local class         = require "xgame.class"
local filesystem    = require "xgame.filesystem"
local timer         = require "kernel.timer"
local cjson         = require "cjson.safe"

local Manifest = class("Manifest")

function Manifest:ctor(path)
    self._tag = timer.createTag()
    self._flushing = false
    self._path = path
    if filesystem.exist(path) then
        self.data = assert(cjson.decode(filesystem.read(path)), path)
        assert(self.data.assets, "bad manifest format")
    else
        self.data = {assets = {}, version = '0.0.0'}
    end
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
    filesystem.write(self._path, cjson.encode(self.data))
end

return Manifest