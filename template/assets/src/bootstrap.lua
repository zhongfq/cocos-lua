local window        = require "kernel.window"
local util          = require "util"

window.setDesignSize(1334, 750, 1)

function main()
    runTest('test.WebViewTest')
end

function runTest(path)
    require(path)
end

function printUserValue(obj, ...)
    print("uservalue", obj, ...)
    util.printdump(debug.getuservalue(obj) or {})
end