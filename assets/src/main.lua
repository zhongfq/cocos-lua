local window        = require "kernel.window"
local Director      = require "cc.Director"

require "xgame.xGame"

window.setDesignSize(1334, 750, 1)

local function runTest(path)
    local TestClass = require(path)
    if TestClass.available or TestClass.available == nil then
        Director.instance:pushScene(TestClass.new())
    else
        print("test not support:", path)
    end
end

function main()
    -- runTest('test.WebViewTest')
    -- runTest('test.AudioEngineTest')
    -- runTest("test.WeChatTest")
    -- runTest("test.GridActionTest")
    -- runTest("test.SpineTest")
    runTest("test.DragonBonesTest")
end