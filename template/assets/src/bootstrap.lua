local cjson = require "cjson"
local runtime = require "kernel.runtime"

function main()
    print("hello bootstrap!")
    print(cjson.encode({name="zhong"}))
    print("version", runtime.version)
    print("classname", runtime.classname)
    print("super", runtime.super.classname)

    for k,v in pairs(runtime.class) do
        print("class table:", k,v)
    end
    for k,v in pairs(runtime['.get']) do
        print("class get:", k,v, v())
    end
end

local r = setmetatable({}, {__gc = function ()
    print("lua meta gc")
end})
