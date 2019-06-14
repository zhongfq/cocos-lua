local class             = require "xgame.class"
local Event             = require "xgame.event.Event"
local assetloader       = require "xgame.assetloader"
local LoadTask          = require "xgame.loader.LoadTask"
local UIView            = require "xgame.ui.UIView"
local ImageView         = require "ccui.ImageView"
local TextureResType    = require "ccui.Widget.TextureResType"

local spriteFrameCache = require("cc.SpriteFrameCache").instance

local UIImage = class("UIImage", UIView)

function UIImage:ctor()
    self._cap_inset = false
    self.url = false
    self.contentMode = "normal"
    self.preferredWidth = 0
    self.preferredHeight = 0
end

function UIImage.Get:cobj()
    local cobj = ImageView.create()
    rawset(self, "cobj", cobj)
    return cobj
end

function UIImage:unload()
    self.url = false
    assetloader.unload(self)
end

function UIImage:load_texture(path)
    if self.url == path or not self.cobj then
        return
    end

    self.url = path

    if string.find(path, "/") then
        assetloader.load(self, {[path] = true})
        self.cobj:loadTexture(path, TextureResType.localType)
    else
        assert(spriteFrameCache:getSpriteFrame(path), path)
        self.cobj:loadTexture(path, TextureResType.plistType)
        if self.scale9Enabled and self._cap_inset then
            self:set_cap_inset(table.unpack(self._cap_inset))
        end
    end

    self:_validate_now()
end

function UIImage:_do_load(url, callback)
    self._event_proxy:clear()

    local E = function (target, priority)
        return self._event_proxy:E(target, priority)
    end

    local loader = LoadTask.new(url)
    E(loader):add_event_listener(Event.COMPLETE, function ()
        self._event_proxy:clear()
        if self.url ~= loader.local_path then
            callback(loader.local_path)
        end
    end)
    E(loader):add_event_listener(Event.IOERROR, function ()
        self._event_proxy:clear()
    end)
    loader:start()
end

function UIImage:load(filepath)
    self:_do_load(filepath, function (path)
        if self.cobj then
            self:load_texture(path)
        end
    end)
end

function UIImage:load_async(filepath)
    self:_do_load(filepath, function (path)
        assetloader.load_async(self, {[path] = true}, function ()
            if self.cobj then
                self:load_texture(path)
            end
        end)
    end)
end

function UIImage:validateDisplay()
    if self.contentMode == "scale_fit" then
        if self.preferredWidth > 0 and self.preferredHeight > 0 then
            self.scale_x = 1
            self.scale_y = 1
            local width, height = self.width, self.height
            if width > 0 and height > 0 then
                self.scale_x = self.preferredWidth / width
                self.scale_y = self.preferredHeight / height
            end
        end
    end
end

function UIImage.Get:shader()
    return self.cobj:getGLProgram()
end

function UIImage.Set:shader(value)
    self.cobj:setGLProgram(assert(value))
end

function UIImage:set_cap_inset(left, right, top, bottom)
    local renderer = self.cobj:getVirtualRenderer()
    renderer:setInsetLeft(left)
    renderer:setInsetRight(right)
    renderer:setInsetTop(top)
    renderer:setInsetBottom(bottom)

    self._cap_inset = {left, right, top, bottom}
end

function UIImage.Get:contentMode() return self._contentMode end
function UIImage.Set:contentMode(value)
    self._contentMode = value
    self:validateDisplay()
end

function UIImage.Get:scale9Enabled() return self.cobj.scale9Enabled end
function UIImage.Set:scale9Enabled(value)
    self.cobj.scale9Enabled = value
end

return UIImage
