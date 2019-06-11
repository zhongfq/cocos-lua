local updater = require "xgame.updater"

function main()
    local inst = updater.new('http://127.0.0.1/cocoslua/version')

    inst.onError = function (callback)
        print("## onError")
    end

    inst.onUpdate = function (event, current, total)
        print("## onUpdate", event, current, total)
    end

    inst.onComplete = function (shouldRestart)
        print('## onComplete', shouldRestart)
    end

    inst:start()
end

