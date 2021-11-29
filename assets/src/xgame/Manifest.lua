local class         = require "xgame.class"
local filesystem    = require "xgame.filesystem"
local runtime       = require "xgame.runtime"
local timer         = require "cclua.timer"
local cjson         = require "cjson.safe"
local xxtea         = require "xxtea"

local Manifest = class("Manifest")

function Manifest:ctor(path)
    self._tag = timer.createTag()
    self._flushing = false
    self._path = path
    self._key = runtime.getEnv('cclua.metadata.key')
    if filesystem.exist(path) then
        self:setContent(filesystem.read(path))
    else
        self.data = {assets = {}, version = '0.0.0'}
    end
end

function Manifest:setContent(str)
    self.data = cjson.decode(str) or cjson.decode(xxtea.decrypt(str, self._key))
    assert(self.data and self.data.assets, "bad manifest format")
end

function Manifest.Get:path()
    return self._path
end

function Manifest.Get:version()
    return self.data.version
end

function Manifest.Get:assets()
    return self.data.assets
end

function Manifest.Get:manifestURL()
    return self.data.manfiest_url
end

function Manifest.Get:packageURL()
    return self.data.package_url
end

function Manifest:update(path, info)
    self.data.assets[path] = info
    timer.killDelay(self._tag)
    timer.delayWithTag(1, self._tag, function ()
        self:flush()
    end)
end

function Manifest:flush()
    filesystem.write(self._path, xxtea.encrypt(cjson.encode(self.data), self._key))
end

return Manifest