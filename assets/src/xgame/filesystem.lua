local filesystem = require "kernel.filesystem"

local M = setmetatable({}, {__index = filesystem})

M.dir = {
    sdcard = assert(filesystem.sdCardDirectory), -- android only
    document = assert(filesystem.documentDirectory),
    assets = assert(filesystem.documentDirectory) .. "/assets",
    cache = assert(filesystem.cacheDirectory),
    tmp = assert(filesystem.tmpDirectory),
    writablePath = assert(filesystem.writablePath),
}

local function encodeURI(s)
    s = string.gsub(s, "([^%w%.%- ])", function(c)
        return string.format("%%%02X", string.byte(c))
    end)
    return string.gsub(s, " ", "+")
end

function M.localCachePath(url)
    if string.find(url, "^http[s]?://static") == 1 then
        return M.dir.cache .. "/http_static/" .. encodeURI(url)
    elseif string.find(url, "^http[s]?://") == 1 then
        return M.dir.cache .. "/http/" .. encodeURI(url)
    else
        return url
    end
end

return M