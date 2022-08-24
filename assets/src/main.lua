require "cclua.init"
require "init"

function main()
    -- add console, touch left-bottom corner
    local Console = require('system.console.Console')
    cclua.stage:addChild(Console.new())

    cclua.startScene('test.SpineTest')
end