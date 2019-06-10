local class         = require "xgame.class"
local util          = require "xgame.util"
local downloader    = require "xgame.downloader"
local http          = require "xgame.http"
local filesystem    = require "xgame.filesystem"
local Manifest      = require "xgame.loader.Manifest"
local runtime       = require "xgame.runtime"
local timer         = require "xgame.timer"
local cjson         = require "kernel.cjson.safe"

local _traceback = __TRACEBACK__

function __TRACEBACK__(...)
    _traceback(...)
    __TRACEBACK__ = _traceback
    print(string.rep("*", 80))
    print('* update error, clear all and restart!!!!')
    print(string.rep("*", 80))
    runtime:clearStorage()
    runtime:restart()
end

local REMOTE_MANIFEST_PATH = filesystem.dir.assets .. '/remote.manifest'
local LOCAL_MANIFEST_PATH = filesystem.dir.assets .. '/local.manifest'
local BUILTIN_MANIFEST_PATH = "builtin.manifest"
local MAX_ATTEMPT_TIMES = 3
local ATTEMPT_INTERVAL = 0.3

local M = class('updater')

function M:ctor(url)
    self.filter = function () return true end
    self._url = url
    self._attemptTimes = 0
    self:_removeFileIfExist(self:_resolveAssetPath(BUILTIN_MANIFEST_PATH))
end

function M:_deferTry()
    if self._attemptTimes < MAX_ATTEMPT_TIMES then
        self._attemptTimes = self._attemptTimes + 1
        timer.delay(ATTEMPT_INTERVAL, function ()
            self:_checkVersion()
        end)
    else
        self.onError('version')
    end
end

function M:_removeFileIfExist(path)
    if filesystem.exist(path) then
        filesystem.remove(path)
    end
end

function M:_resolveAssetPath(path)
    return filesystem.dir.assets .. '/' .. path
end

function M:_resolveManifestPath(name)
    return string.format('%s/%s.manifest', filesystem.dir.assets, name)
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

function M:_readManifestVersion(path)
    local version = "0.0.0"
    if filesystem.exist(path) then
        local manifest = cjson.decode(filesystem.read(path))
        if manifest and manifest.version then
            version= manifest.version
        end
    end
    return version
end

function M:_checkAndDownloadManifest(name, info)
    local path = self:_resolveManifestPath(name)
    local version = self:_readManifestVersion(path)
    if version ~= info.version then
        local status, data = http({url = info.url})
        if status ~= 200 then
            self:_deferTry()
            return
        else
            filesystem.write(path, data)
        end
    else
        print(string.format("manifest '%s' is up-to-date", name))
    end
end

function M:_mergeManifests(data)
    local newVersion = '0.0.0'
    local remote = {assets = {}, package_url = "", manifest_url = ""}
    for name, info in pairs(data) do
        newVersion = self:_maxVersion(newVersion, info.version)
        local m = Manifest.new(self:_resolveManifestPath(name))
        for path, asset in pairs(m.assets) do
            asset.url = m.packageURL .. '/' .. path
            remote.assets[path] = asset
        end
    end
    remote.version = newVersion
    filesystem.write(REMOTE_MANIFEST_PATH, cjson.encode(remote))
end

function M:_startDownloadAssets(localManifest, assets)
    for path, asset in pairs(assets) do
        local function callback(success)
            if success then
                assets[path] = nil
                localManifest:update(path, asset)
            else
                self.onError('asset', asset)
            end
        end
        downloader.load({
            url = asset.url,
            md5 = asset.md5,
            asset = asset,
            path = self:_resolveAssetPath(path),
            callback = callback,
        })
    end
end

function M:_validateAndDownloadAssets()
    if not filesystem.exist(LOCAL_MANIFEST_PATH) then
        filesystem.copy(BUILTIN_MANIFEST_PATH, LOCAL_MANIFEST_PATH)
    end

    local builtinManifest = Manifest.new(BUILTIN_MANIFEST_PATH)
    local localManifest = Manifest.new(LOCAL_MANIFEST_PATH)
    local remoteManifest = Manifest.new(REMOTE_MANIFEST_PATH)

    -- compare builtin.manifest and local.manifest
    -- remove file when the date of builtin asset is newer
    for path, builtinAsset in pairs(builtinManifest.assets) do
        local localAsset = localManifest.assets[path]
        if not localAsset or builtinAsset.date > localAsset.date then
            self:_removeFileIfExist(self:_resolveAssetPath(path))
            localManifest:update(path, builtinAsset)
            print('use builtin file asset: ' .. path)
        end
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
        self:_startDownloadAssets(localManifest, assets)
    else
        print("all assets is up-to-date")
        self.onComplete(false)
    end
end

function M:_checkVersion()
    local version = self:_readManifestVersion(REMOTE_MANIFEST_PATH)
    local url = string.format('%s?os=%s&runtime=%s&version=%s&channel=%s',
        self._url, runtime.os, runtime.version, version, runtime.channel)
    http.block(function ()
        local status, data = http({url = url, responseType = 'JSON'})
        if status ~= 200 then
            self:_deferTry()
            return
        end

        local newVersion = "0.0.0"

        for name, info in pairs(data) do
            newVersion = self:_maxVersion(newVersion, info.version)
            self:_checkAndDownloadManifest(name, info)
        end

        self:_mergeManifests(data)

        -- rollback?
        if newVersion < version then
            runtime.clearStorage()
            runtime.restart()
        else
            self:_validateAndDownloadAssets()
        end
    end)
end

function M:start()
    assert(self.onError, 'no error handler')
    assert(self.onComplete, 'no complete handler')
    assert(self.onMessage, 'no message handler')
    assert(self.onUpdate, 'no update handler')
    self:_checkVersion()
end

return M