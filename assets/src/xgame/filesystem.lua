local filesystem = require "kernel.filesystem"

assert(not filesystem.dir)
assert(not filesystem.localCachePath)

filesystem.dir = {
    sdcard = assert(filesystem.sdCardDirectory), -- android only
    document = assert(filesystem.documentDirectory),
    assets = assert(filesystem.documentDirectory) .. "/assets",
    cache = assert(filesystem.cacheDirectory),
    tmp = assert(filesystem.tmpDirectory),
    writablePath = assert(filesystem.writablePath),
}

local cacheDirectory = filesystem.dir.cache

local function encodeURI(s)
    s = string.gsub(s, "([^%w%.%-])", function(c)
        return string.format("%%%02X", string.byte(c))
    end)
    return string.gsub(s, " ", "+")
end

function filesystem.localCachePath(url)
    if string.find(url, "^https?://static") then
        return cacheDirectory .. "/http_static/" .. encodeURI(url)
    elseif string.find(url, "^https?://") then
        return cacheDirectory .. "/http/" .. encodeURI(url)
    else
        return url
    end
end

return filesystem