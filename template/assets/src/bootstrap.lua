local cjson = require "cjson"
local runtime = require "kernel.runtime"

function main()
    print("hello bootstrap!")
    print(cjson.encode({name="zhong"}))
    print("version", runtime.version)
end

local r = setmetatable({}, {__gc = function ()
    print("lua meta gc")
end})
