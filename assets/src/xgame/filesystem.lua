local http          = require "xgame.http"
local runtime       = require "kernel.runtime"
local filesystem    = require "kernel.filesystem"

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

if runtime.os == "android" then
    local appdir = string.format("%s/Android/data/%s",
        filesystem.sdCardDirectory, runtime.packageName)
    filesystem.dir.externalCache = appdir .. '/cache'
    filesystem.dir.externalTmp = appdir .. '/cache'
    filesystem.dir.externalDocument = appdir .. '/files/Documents'
    filesystem.createDirectory(filesystem.dir.externalCache)
    filesystem.createDirectory(filesystem.dir.externalDocument)
end

local cacheDirectory = filesystem.dir.cache

local function encodeURI(s)
    s = http.decodeURI(s)
    return string.gsub(s, '[?/*:<>|\\]', '+')
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