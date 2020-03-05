local _traceback = __TRACEBACK__

function __TRACEBACK__(...)
    __TRACEBACK__ = _traceback
    _traceback(...)
    if not DEBUG then
        local runtime = require "kernel.runtime"
        print(string.rep("*", 80))
        print('* update error, clear all and restart!!!!')
        print(string.rep("*", 80))
        runtime:clearStorage()
        runtime:restart()
    end
end

require "init"

local updater   = require "xgame.updater"
local runtime   = require "xgame.runtime"
local conf      = require "conf"

function main()
    local inst = updater.new(conf.VERSION_URL)

    inst.onError = function (callback)
        print("## onError")
    end

    inst.onUpdate = function (event, current, total)
        print("## onUpdate", event, current, total)
    end

    inst.onAppUpdate = function ()
        if runtime.os == 'ios' then
            runtime.openURL("itms-apps://itunes.apple.com/app/${apple id}")
        elseif runtime.os == 'android' then
            runtime.openURL('market://details?id=' .. runtime.packageName)
            --[[
                local status, data = http {
                    url = 'http://www.codetypes.com/app/version',
                    responseType = 'JSON',
                }
                if status ~= 200 then
                    return
                end
                local task = LoadTask.new(data.url)
                function task:loadSuccess()
                    local path = filesystem.localCachePath(task.url)
                    local apk = filesystem.dir.cache .. '/app.apk'
                    filesystem.copy(path, apk)
                    runtime.installAPK(apk)
                end
                task:start()
            ]]
        else
            error('no support update app')
        end
    end

    inst.onComplete = function (shouldRestart)
        __TRACEBACK__ = _traceback
        if shouldRestart then
            runtime.launch("main.lua")
        else
            local function start()
                require "main"
                main()
            end
            if not xpcall(start, __TRACEBACK__) then
                if not DEBUG then
                    runtime.clearStorage()
                    runtime.restart()
                end
            end
        end
    end

    inst.filter = function (path)
        -- return true
        return string.find(path, '.lua', 1, true)
            or string.find(path, '.data', 1, true)
    end

    inst.onComplete(false)
end

