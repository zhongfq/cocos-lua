local class         = require "xgame.class"
local downloader    = require "xgame.downloader"
local LoadTask      = require "xgame.LoadTask"
local http          = require "xgame.http"
local filesystem    = require "xgame.filesystem"
local Manifest      = require "xgame.Manifest"
local runtime       = require "xgame.runtime"
local timer         = require "xgame.timer"
local Event         = require "xgame.event.Event"
local cjson         = require "cjson.safe"

local MAX_ATTEMPT_TIMES = 3
local ATTEMPT_INTERVAL = 0.3

local builtinManifest = downloader.builtinManifest
local localManifest = downloader.localManifest
local remoteManifest = downloader.remoteManifest

local M = class('updater')

function M:ctor(url)
    self.filter = function () return true end
    self._shouldRestart = false
    self._url = url
    self._attemptTimes = 0
    self._manifests = {}
end

function M:_deferTry()
    if self._attemptTimes < MAX_ATTEMPT_TIMES then
        self._attemptTimes = self._attemptTimes + 1
        timer.delay(ATTEMPT_INTERVAL, function ()
            self:_checkVersion()
        end)
    else
        self:_didError('version')
    end
end

function M:_removeFileIfExist(path)
    if filesystem.exist(path) then
        self._shouldRestart = true
        filesystem.remove(path)
    end
end

function M:_resolveAssetPath(path)
    return filesystem.dir.assets .. '/' .. path
end

function M:_loadManifest(name)
    local path = string.format('%s/%s.manifest', filesystem.dir.assets, name)
    local m = self._manifests[path]
    if not m then
        m = Manifest.new(path)
        self._manifests[path] = m
    end
    return m
end

function M:_cmpVersion(v1, v2)
    local function toIntVersion(v)
        local v1, v2, v3 = string.match(v, "(%d+)%.(%d+)%.(%d+)")
        if v1 then
            return v1 * 1000000 + v2 * 1000 + v3
        else
            return 0
        end
    end
    return toIntVersion(v1) - toIntVersion(v2)
end

function M:_maxVersion(v1, v2)
    return self:_cmpVersion(v1, v2) < 0 and v2 or v1
end

function M:_checkAndDownloadManifest(name, info)
    local m = self:_loadManifest(name)
    if m.version ~= info.version then
        local status, data = http({url = info.url})
        if status ~= 200 then
            return false
        else
            filesystem.write(m.path, data)
            m.data = cjson.decode(data)
        end
    else
        print(string.format("manifest '%s' is up-to-date", name))
    end
    return true
end

function M:_mergeManifests(versionData)
    local data = {assets = {}, version = "0.0.0"}
    for _, info in pairs(versionData.assets) do
        data.version = self:_maxVersion(data.version, info.version)
        local m = self:_loadManifest(info.name)
        if data.version == info.version then
            data.package_url = assert(m.data.package_url, 'no package url')
        end
        for path, asset in pairs(m.assets) do
            data.assets[path] = asset
        end
    end

    remoteManifest.data = data
    remoteManifest:flush()
end

function M:_downloadAssets(localManifest, assets)
    local total = 0
    local current = 0
    for path, asset in pairs(assets) do
        total = total + 1

        local task = LoadTask.new(path)
        task:addListener(Event.COMPLETE, function ()
            assets[path] = nil
            current = current + 1
            self:_didUpdate('donwloadAssets', current, total)
            if not next(assets) then
                localManifest:flush()
                runtime.manifestVersion = remoteManifest.version
                self:_didComplete(self._shouldRestart)
            end
        end)
        task:addListener(Event.IOERROR, function ()
            self:_didError('asset', asset)
        end)
        downloader.load(task)
    end
    self:_didUpdate('donwloadAssets', current, total)
end

function M:_verifyAssets()
    self:_didUpdate('verifyAssets')
    
    if not filesystem.exist(localManifest.path) then
        filesystem.copy(builtinManifest.path, localManifest.path)
    end

    -- compare builtin.manifest and local.manifest
    -- remove file when the date of builtin asset is newer
    local shouldSave = false
    for path, builtinAsset in pairs(builtinManifest.assets) do
        local localAsset = localManifest.assets[path]
        if not localAsset or builtinAsset.date > localAsset.date then
            self:_removeFileIfExist(self:_resolveAssetPath(path))
            shouldSave = true
            localManifest.assets[path] = builtinAsset
            print('use builtin file asset: ' .. path)
        end
    end
    if shouldSave then
        localManifest:flush()
    end

    -- compare local.manifest and remote.manifest, should updated when:
    -- 1. date not equal and asset.builtin = true
    -- 2. date not equal and pass filter test
    -- 3. date equal but file lose
    local assets = {}
    for path, remoteAsset in pairs(remoteManifest.assets) do
        local builtinAsset = builtinManifest.assets[path]
        local localAsset = localManifest.assets[path]
        local shouldUpdated = false
        if not localAsset or localAsset.date < remoteAsset.date then
            self:_removeFileIfExist(self:_resolveAssetPath(path))
            if builtinAsset or remoteAsset.builtin then
                print('will update builtin file: ' .. path)
                shouldUpdated = true
            elseif self.filter(path) then
                print('will update file: ' .. path)
                shouldUpdated = true
            -- else donwload on-demand
            end
        elseif localAsset.date == remoteAsset.date then
            if (not builtinAsset or builtinAsset.date < localAsset.date)
                and not filesystem.exist(self:_resolveAssetPath(path)) then
                print('will update missed file:' .. path)
                shouldUpdated = true
            end
        else
            -- if localAsset.date > remoteAsset.date, should rollback?
            if filesystem.exist(self:_resolveAssetPath(path)) then
                print(string.format('local asset is newer: %s', path))
                runtime.clearStorage()
                runtime.restart()
                return
            end
        end

        if shouldUpdated then
            assets[path] = remoteAsset
        end
    end

    if next(assets) then
        self._shouldRestart = true
        self:_downloadAssets(localManifest, assets)
    else
        print("all assets is up-to-date")
        runtime.manifestVersion = remoteManifest.version
        self:_didComplete(self._shouldRestart)
    end
end

function M:_checkVersion()
    self:_didUpdate('checkUpdate')
    http.block(function ()
        local version = remoteManifest.version
        local url = string.format('%s?os=%s&runtime=%s&version=%s&channel=%s',
            self._url, runtime.os, runtime.appVersion, version, runtime.channel)
        local status, data = http({url = url, responseType = 'JSON'})
        if status ~= 200 or not data then
            self:_deferTry()
            return
        end

        if self:_cmpVersion(runtime.version, data.runtime) < 0 then
            print(string.format("runtime require '%s', got '%s'", data.runtime, runtime.version))
            self:_didAppUpdate()
            return
        end

        local newVersion = "0.0.0"

        self:_didUpdate('updateManifest')
        for _, info in pairs(data.assets) do
            newVersion = self:_maxVersion(newVersion, info.version)
            if not self:_checkAndDownloadManifest(info.name, info) then
                self:_deferTry()
                return
            end
        end

        self:_mergeManifests(data)

        -- rollback?
        if newVersion < version then
            print(string.format("rollback from '%s' to '%s'", newVersion, version))
            runtime.clearStorage()
            runtime.restart()
        else
            self:_verifyAssets()
        end
    end)
end

function M:_didComplete(...)
    self.onComplete(...)
end

function M:_didError(...)
    self.onError(...)
end

function M:_didUpdate(...)
    self.onUpdate(...)
end

function M:_didAppUpdate()
    self.onAppUpdate()
end

function M:start()
    assert(self.onError, 'no error handler')
    assert(self.onComplete, 'no complete handler')
    assert(self.onUpdate, 'no update handler')
    assert(self.onAppUpdate, 'no app update handler')
    self._attemptTimes = 0
    self:_checkVersion()
end

return M