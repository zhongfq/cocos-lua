local window        = require "kernel.window"
local util          = require "util"
local Director      = require "cc.Director"

window.setDesignSize(1334, 750, 1)

function main()
    -- runTest('test.WebViewTest')
    runTest("test.RefChainTest")
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
    util.printdump(debug.getuservalue(obj) or {})
end