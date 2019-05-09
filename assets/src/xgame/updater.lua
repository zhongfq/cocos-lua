local downloader    = require "xgame.downloader"
local http          = require "xgame.http"
local Manifest      = require "xgame.loader.Manifest"
local runtime       = require "kernel.runtime"

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

local conf

local function start(config)
    conf = config
    assert(conf.update)
    assert(conf.ioerror)
    assert(conf.complete)
    assert(conf.url, "no version url")
end

return {start = start}