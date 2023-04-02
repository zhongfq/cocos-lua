local util      = require "cclua.util"
local timer     = require "cclua.timer"
local runtime   = require "cclua.runtime"

assert(not runtime.on)
assert(not runtime.once)
assert(not runtime.off)
assert(not runtime.dispatch)
assert(not runtime.useHighFPS)

local xpcall = xpcall
local ANONYMOUS = {}
local dispatching = 0
local suspended = {}
local listeners = {}
local frameRate = nil
local usedBy = nil

function runtime.on(event, callback, caller)
    assert(event, 'no event')
    assert(type(callback) == 'function', 'no callback')
    if dispatching > 0 then
        suspended[#suspended + 1] = {runtime.on, event, callback, caller}
    else
        local map = listeners[event]
        if not map then
            map = {}
            listeners[event] = map
        end
        if map[callback] then
            printf("will overwrite event callback: %s", event)
        end
        map[callback] = caller or ANONYMOUS
    end
end

function runtime.once(event, callback, caller)
    assert(type(callback) == 'function', 'no callback')
    runtime.on(event, function (...)
        runtime.off(event, util.callee())
        callback(...)
    end, caller)
end

function runtime.off(event, callback)
    assert(event, 'no event')
    assert(type(callback) == 'function', 'no callback')
    if dispatching > 0 then
        suspended[#suspended + 1] = {runtime.off, event, callback}
    else
        local map = listeners[event]
        if map then
            map[callback] = nil
        end
    end
end

function runtime.dispatch(event, args)
    local map = listeners[event]
    local __TRACEBACK__ = __TRACEBACK__
    dispatching = dispatching + 1
    if map then
        for callback, caller in pairs(map) do
            if caller == ANONYMOUS then
                xpcall(callback, __TRACEBACK__, args)
            else
                xpcall(callback, __TRACEBACK__, caller, args)
            end
        end
    end
    dispatching = dispatching - 1

    if dispatching == 0 then
        for i, v in ipairs(suspended) do
            v[1](table.unpack(v, 2))
            suspended[i] = nil
        end
    end
end

runtime.setDispatcher(runtime.dispatch)
runtime.setDispatcher = false -- avoid used by others

function runtime.useHighFPS(use, owner, duration)
    local TAG = '__runtime_useHighFPS__'
    if not frameRate then
        frameRate = runtime.frameRate
    end
    timer.killDelay(TAG)
    if use then
        usedBy = owner
        runtime.frameRate = runtime.maxFrameRate
        if duration then
            timer.delayWithTag(duration, TAG, function ()
                runtime.useHighFPS(false, owner)
            end)
        end
    else
        if usedBy == owner then
            usedBy = nil
            runtime.frameRate = frameRate
        end
        
    end
end

return runtime