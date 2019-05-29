local runtime = require "kernel.runtime"

assert(not runtime.on)
assert(not runtime.off)

local dispatching = false
local suspended = {}
local listeners = {}

function runtime.on(event, callback)
    assert(event, 'no event')
    assert(type(callback) == 'function', 'no callback')
    if dispatching then
        suspended[#suspended + 1] = {runtime.on, event, callback}
    else
        local map = listeners[event]
        if not map then
            map = {}
            listeners[event] = map
        end
        map[callback] = true
    end
end

function runtime.off(event, callback)
    assert(event, 'no event')
    assert(type(callback) == 'function', 'no callback')
    if dispatching then
        suspended[#suspended + 1] = {runtime.off, event, callback}
    else
        local map = listeners[event]
        if map then
            map[callback] = nil
        end
    end
end

runtime.setDispatcher(function (event, args)
    local map = listeners[event]
    dispatching = true
    if map then
        for callback in pairs(map) do
            callback(args)
        end
    end
    dispatching = false

    for i, v in ipairs(suspended) do
        v[1](table.unpack(v, 2))
        suspended[i] = nil
    end
end)
runtime.setDispatcher = false -- avoid used by others

return runtime