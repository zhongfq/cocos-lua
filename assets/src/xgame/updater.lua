local downloader    = require "xgame.downloader"
local http          = require "xgame.http"
local filesystem    = require "xgame.filesystem"
local Manifest      = require "xgame.loader.Manifest"
local runtime       = require "kernel.runtime"
local timer         = require "kernel.timer"
local cjson         = require "kernel.cjson.safe"

local _traceback = __TRACEBACK__

local MANIFEST_REMOTE_PATH = filesystem.dir.assets .. '/remote.manifest'
local MANIFEST_BUILTIN_PATH = "builtin.manifest"
local MAX_ATTEMPT_TIMES = 3
local ATTEMPT_INTERVAL = 0.3

local conf
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
        conf.onError(function ()
            checkVersion()
        end)
    end
end

function checkVersion()
    local version = "0.0.0"
    if filesystem.exist(MANIFEST_REMOTE_PATH) then
        local manifest = cjson.decode(filesystem.read(MANIFEST_REMOTE_PATH))
        if manifest and manifest.version then
            version= manifest.version
        end
    end

    local url = string.format('%s?os=%s&runtime=%s&version=%s&channel=%s',
        conf.url, runtime.os, version, runtime.channel)
    http.block(function ()
        local status, data = http({url = url, responseType = 'JSON'})
        if status ~= 200 then
            deferTry()
            return
        end
    end)
end

local function start(ci)
    conf = ci
    attemptTimes = 0
    assert(conf.url, 'no version url')
    assert(conf.onComplete, "no 'onComplete' callback")
    assert(conf.onError, "no 'onError' callback")
    assert(conf.onUpdate, "no 'onUpdate' callback")
    checkVersion()
end

return {start = start}