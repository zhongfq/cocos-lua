local cjson = require "cjson"
local runtime = require "kernel.runtime"

function main()
    print("hello bootstrap!")
    print(cjson.encode({name="zhong"}))
    print("version", runtime.version)
    print("classname", runtime.classname)
    print("super", runtime.super.classname)

    for k,v in pairs(runtime[".super"]) do
        print(".super", k,v)
    end
end

local r = setmetatable({}, {__gc = function ()
    print("lua meta gc")
end})
