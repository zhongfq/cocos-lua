require "init"
require "xgame.xGame"

function main()
    -- add console, touch left-bottom corner
    local Console = require('system.console.Console')
    xGame.stage:addChild(Console.new())

    xGame:startScene('test.SpineTest')
end