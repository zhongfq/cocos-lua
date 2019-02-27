local cjson = require "cjson"
local runtime = require "kernel.runtime"
local preferences = require "kernel.preferences"

function main()
    print("hello bootstrap!")
    print(cjson.encode({name="zhong"}))
    print("version", runtime.version)
    print("classname", runtime.classname)

    for k,v in pairs(runtime.class) do
        print("class table:", k,v)
    end
    for k,v in pairs(runtime.class['.get']) do
        print("class get:", k,v, v())
    end

    print("###", runtime.isRestarting())

    print("preferences", preferences.getString("conf.version.runtime"))
end

local r = setmetatable({}, {__gc = function ()
    print("lua meta gc")
end})
