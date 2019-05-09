local class         = require "xgame.class"
local filesystem    = require "xgame.filesystem"
local timer         = require "kernel.timer"
local cjson         = require "kernel.cjson.safe"

local Manifest = class("Manifest")

function Manifest:ctor(path)
    self._tag = '__manifest_update_' .. os.time() .. '__'
    self._path = path
    self._data = assert(cjson.decode(filesystem.read(path)), path)
    assert(self._data.assets, "bad manifest format")
end

function Manifest.Get:version()
    return self._data.version
end

function Manifest.Get:assets()
    return self._data.assets
end

function Manifest.Get:manifestURL()
    return self._data.manfiest_url
end

function Manifest.Get:packageURL()
    return self._data.package_url
end

function Manifest:update(path, info)
    self._data.assets[path] = info
    timer.killDelay(self._tag)
    timer.delayWithTag(1, self._tag, function ()
        self:flush()
    end)
end

function Manifest:flush()
    filesystem.write(self._path, cjson.encode(self._data))
end

return Manifest