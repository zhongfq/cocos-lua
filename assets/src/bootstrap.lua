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

    inst.onComplete = function (shouldRestart)
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

    inst:start()
end

