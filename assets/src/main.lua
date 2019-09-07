if DEBUG then
    require "xgame.debug"
end

require "init"
require "xgame.xGame"

function main()
    -- add console, touch left-bottom corner
    local Console = require('system.console.Console')
    xGame.stage:addChild(Console.new())

    -- runTest('test.WebViewTest')
    -- runTest('test.AudioEngineTest')
    -- runTest("test.WeChatTest")
    -- runTest("test.GridActionTest")
    -- runTest("test.SpineTest")
    -- runTest("test.DragonBonesTest")
    xGame:startScene(require("test.DragonBonesTest"))
end