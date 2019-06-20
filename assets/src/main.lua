require "init"
require "xgame.xGame"

function main()
    -- runTest('test.WebViewTest')
    -- runTest('test.AudioEngineTest')
    -- runTest("test.WeChatTest")
    -- runTest("test.GridActionTest")
    -- runTest("test.SpineTest")
    -- runTest("test.DragonBonesTest")
    xGame:startScene(require("test.DragonBonesTest"))
end