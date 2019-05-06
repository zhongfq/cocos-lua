local window        = require "kernel.window"
local util          = require "xgame.util"
local Director      = require "cc.Director"

require "xgame.xGame"

window.setDesignSize(1334, 750, 1)

function main()
    -- runTest('test.WebViewTest')
    -- runTest('test.AudioEngineTest')
    runTest("test.WeChatTest")
    -- runTest("test.GridActionTest")
end

function runTest(path)
    local TestClass = require(path)
    if TestClass.available or TestClass.available == nil then
        Director.instance:pushScene(TestClass.new())
    else
        print("test not support:", path)
    end
end

function printUserValue(obj, ...)
    print("uservalue", obj, ...)
    util.dump(debug.getuservalue(obj) or {})
end