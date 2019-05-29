local updater = require "xgame.updater"

function main()
    local url = 'http://127.0.0.1/cocoslua/version'
    updater.start(url, function (event, ...)
        print("event", ...)
    end)
end

