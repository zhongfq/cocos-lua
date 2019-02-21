local cjson = require "cjson"

function main()
    print("hello bootstrap!")
    print(cjson.encode({name="zhong"}))
end

local r = setmetatable({}, {__gc = function ()
    print("lua meta gc")
end})
