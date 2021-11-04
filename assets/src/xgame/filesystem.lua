local http          = require "xgame.http"
local runtime       = require "cclua.runtime"
local filesystem    = require "cclua.filesystem"

assert(not filesystem.dir)
assert(not filesystem.localPath)

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
    return string.gsub(s, '[?/*:<>|\\]+', '_')
end

function filesystem.localPath(uri)
    if filesystem.isRemoteURI(uri) then
        return cacheDirectory .. "/http/" .. encodeURI(uri)
    else
        return uri
    end
end

function filesystem.isRemoteURI(uri)
    return string.find(uri, "^https?://") or string.find(uri, "^uri://")
end

function filesystem.nomedia(dir)
    if runtime.os == 'android' then
        filesystem.write(dir .. '/.nomedia', '')
    end
end

return filesystem