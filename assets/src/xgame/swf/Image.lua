--
-- $id: Image.lua O $
--

local class             = require "xgame.class"
local util              = require "xgame.util"
local Event             = require "xgame.Event"
local filesystem        = require "xgame.filesystem"
local assetcache        = require "xgame.assetcache"
local HandlerProxy      = require "xgame.HandlerProxy"
local LoadTask          = require "xgame.loader.LoadTask"
local DisplayObject     = require "xgame.swf.DisplayObject"

local trace = util.trace("[Image]")

local Image = class("Image", DisplayObject)

local _new = Image.new

function Image.new(cobj)
    return _new(cobj or swf.image.new())
end

function Image:ctor(cobj)
    self._filepath = false
    self._preferred_width = 0
    self._preferred_height = 0
    self._event_proxy = HandlerProxy.new()
    self:add_event_listener(Event.REMOVED_FORM_STAGE, function ()
        self._event_proxy:clear()
    end)
end

function Image:_do_load(url, callback)
    self._event_proxy:clear()

    local E = function (target, priority)
        return self._event_proxy:E(target, priority)
    end

    local loader = LoadTask.new(url)
    E(loader):add_event_listener(Event.COMPLETE, function ()
        self._event_proxy:clear()
        callback(loader.local_path)
    end)
    E(loader):add_event_listener(Event.IOERROR, function ()
        self._event_proxy:clear()
    end)
    loader:start()
end

function Image:load_texture(cocos_texture)
    self.cobj:load_texture(cocos_texture)
end

function Image:load(filepath)
    self:_do_load(filepath, function (path)
        assetcache.load(self, {[path] = true})
        self.cobj:load(path)
        self.preferred_width = self._preferred_width
        self.preferred_height = self._preferred_height
    end)
end

function Image:load_async(filepath)
    self:_do_load(filepath, function (path)
        assetcache.load(self, {[path] = true})
        self.cobj:load_async(path, function (success)
            self.preferred_width = self._preferred_width
            self.preferred_height = self._preferred_height
        end)
    end)
end

function Image:is_loaded()
    return self.cobj:is_loaded()
end

function Image.Get:filepath()
    return self.cobj.filepath
end

function Image.Get:preferred_width() return self._preferred_width end
function Image.Set:preferred_width(value)
    self._preferred_width = value
    if value > 0 and self.width > 0 then
        self.scale_x = 1
        self.scale_x = value / self.width
    end
end

function Image.Get:preferred_height() return self._preferred_height end
function Image.Set:preferred_height(value)
    self._preferred_height = value
    if value > 0 and self.height > 0 then
        self.scale_y = 1
        self.scale_y = value / self.height
    end
end

return Image
