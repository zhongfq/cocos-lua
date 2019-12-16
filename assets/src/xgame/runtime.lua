local util      = require "xgame.util"
local runtime   = require "kernel.runtime"
local window    = require "kernel.window"

assert(not runtime.on)
assert(not runtime.off)

local xpcall = xpcall
local ANONYMOUS = {}
local dispatching = 0
local suspended = {}
local listeners = {}

runtime.Permission = require "kernel.Permission"
runtime.PermissionStatus = require "kernel.PermissionStatus"

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


function runtime.isPad()
    local vw, vh = window.getFrameSize()
    return vw / vh < (960 / 640)
end

function runtime.isMobile()
    return runtime.os == 'ios' or runtime.os == 'android'
end

runtime.setDispatcher(function (event, args)
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
end)
runtime.setDispatcher = false -- avoid used by others

if runtime.os == 'android' then
    local luaj = require "xgame.luaj"
    local AppContext = luaj.new("kernel/AppContext")
    function runtime.alert(title, message, ok, no, callback)
        AppContext.alert(title, message, ok, no, function (status)
            callback(status == 'true')
        end)
    end

    function runtime.installAPK(path)
        AppContext.installAPK(path)
    end

    local function toAndroidPermission(permission)
        if permission == runtime.Permission.AUDIO then
            return 'android.permission.RECORD_AUDIO'
        elseif permission == runtime.Permission.CAMERA then
            return 'android.permission.CAMERA'
        elseif permission == runtime.Permission.PHOTO then
            return 'android.permission.CAMERA'
        else
            assert(string.find(permission, 'android.permission'))
            return permission
        end
    end

    local function toPermissionStatus(status)
        if status == 'NOT_DETERMINED' then
            return runtime.PermissionStatus.NOT_DETERMINED
        elseif status == 'RESTRICTED' then
            return runtime.PermissionStatus.RESTRICTED
        elseif status == 'DENIED' then
            return runtime.PermissionStatus.DENIED
        else
            return runtime.PermissionStatus.AUTHORIZED
        end
    end

    function runtime.getPermissionStatus(permission)
        permission = toAndroidPermission(permission)
        return toPermissionStatus(AppContext.getPermissionStatus(permission))
    end

    function runtime.requestPermission(permission, callback)
        permission = toAndroidPermission(permission)
        AppContext.requestPermission(permission, function (status)
            callback(toPermissionStatus(status))
        end)
    end
end

return runtime