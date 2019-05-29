local util          = require "xgame.util"
local downloader    = require "xgame.downloader"
local http          = require "xgame.http"
local filesystem    = require "xgame.filesystem"
local Manifest      = require "xgame.loader.Manifest"
local runtime       = require "xgame.runtime"
local timer         = require "xgame.timer"
local cjson         = require "kernel.cjson.safe"

local _traceback = __TRACEBACK__

local MANIFEST_REMOTE_PATH = filesystem.dir.assets .. '/remote.manifest'
local MANIFEST_BUILTIN_PATH = "builtin.manifest"
local MAX_ATTEMPT_TIMES = 3
local ATTEMPT_INTERVAL = 0.3

local url
local callback
local attemptTimes = 0

function __TRACEBACK__(...)
    _traceback(...)
    __TRACEBACK__ = _traceback
    print(string.rep("*", 80))
    print('* update error, clear all and restart!!!!')
    print(string.rep("*", 80))
    runtime:clearStorage()
    runtime:restart()
end

-- funcs
local checkVersion

local function deferTry()
    if attemptTimes < MAX_ATTEMPT_TIMES then
        timer.delay(ATTEMPT_INTERVAL, function ()
            checkVersion()
        end)
    else
        callback('error', function ()
            checkVersion()
        end)
    end
end

local function toPath(name)
    return string.format('%s/%s.manifest', filesystem.dir.assets, name)
end

local function toIntVersion(version)
    local v1, v2, v3 = string.match(version, "(%d+)%.(%d+)%.(%d+)")
    if v1 then
        return v1 * 1000000 + v2 * 1000 + v3
    else
        return 0
    end
end

local function readManifestVersion(path)
    local version = "0.0.0"
    if filesystem.exist(path) then
        local manifest = cjson.decode(filesystem.read(path))
        if manifest and manifest.version then
            version= manifest.version
        end
    end
    return version
end

local function checkAndDownloadManifest(name, info)
    local path = toPath(name)
    local version = readManifestVersion(path)
    if version ~= info.version then
        local status, data = http({url = info.url})
        if status ~= 200 then
            deferTry()
            return
        else
            filesystem.write(path, data)
        end
    else
        print(string.format("manifest '%s' is up-to-date", name))
    end
end

function checkVersion()
    local version = readManifestVersion(MANIFEST_REMOTE_PATH)
    local url = string.format('%s?os=%s&runtime=%s&version=%s&channel=%s',
        url, runtime.os, runtime.version, version, runtime.channel)
    http.block(function ()
        local status, data = http({url = url, responseType = 'JSON'})
        if status ~= 200 then
            deferTry()
            return
        end

        local maxVersion = 0

        for name, info in pairs(data) do
            maxVersion = math.max(maxVersion, toIntVersion(info.version))
            checkAndDownloadManifest(name, info)
        end

        print(util.dump(data))
    end)
end

local function start(_url, _callback)
    attemptTimes = 0
    url = assert(_url, 'no version url')
    callback = assert(_callback, 'no callback function')
    checkVersion()
end

return {start = start}