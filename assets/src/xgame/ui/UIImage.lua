--
-- $id: UIImage.lua O $
--

local class         = require "xgame.class"
local util          = require "xgame.util"
local Event         = require "xgame.Event"
local assetcache    = require "xgame.assetcache"
local HandlerProxy  = require "xgame.HandlerProxy"
local LoadTask      = require "xgame.loader.LoadTask"
local UIView        = require "xgame.display.UIView"

local SpriteFrameCache = cc.SpriteFrameCache:getInstance()
local trace = util.trace("[UIImage]")

local UIImage = class("UIImage", UIView)

function UIImage:ctor()
    self._cap_inset = false
    self.file_path = false
    self.content_mode = "normal"
    self.preferred_width = 0
    self.preferred_height = 0

    self._event_proxy = HandlerProxy.new()
    self:add_event_listener(Event.REMOVED_FORM_STAGE, function ()
        self._event_proxy:clear()
    end)
end

function UIImage.Get:cobj()
    local cobj = ccui.ImageView:create()
    rawset(self, "cobj", cobj)
    return cobj
end

function UIImage:unload()
    self.file_path = false
    assetcache.unload(self)
end

function UIImage:load_texture(path)
    if self.file_path == path or not self.cobj then
        return
    end

    self.file_path = path

    if string.find(path, "/") then
        assetcache.load(self, {[path] = true})
        self.cobj:loadTexture(path, ccui.TextureResType.localType)
    else
        assert(SpriteFrameCache:getSpriteFrame(path), path)
        self.cobj:loadTexture(path, ccui.TextureResType.plistType)
        if self.scale9_enabled and self._cap_inset then
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
        if self.file_path ~= loader.local_path then
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
        assetcache.load_async(self, {[path] = true}, function ()
            if self.cobj then
                self:load_texture(path)
            end
        end)
    end)
end

function UIImage:validate_display()
    if self.content_mode == "scale_fit" then
        if self.preferred_width > 0 and self.preferred_height > 0 then
            self.scale_x = 1
            self.scale_y = 1
            local width, height = self.width, self.height
            if width > 0 and height > 0 then
                self.scale_x = self.preferred_width / width
                self.scale_y = self.preferred_height / height
            end
        end
    end
end

function UIImage:set_gray(value) 
    self.cobj:setGray(value) 
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

function UIImage.Get:content_mode() return self._content_mode end
function UIImage.Set:content_mode(value)
    self._content_mode = value
    self:validate_display()
end

function UIImage.Get:scale9_enabled() return self.cobj:isScale9Enabled() end
function UIImage.Set:scale9_enabled(value)
    self.cobj:setScale9Enabled(value)
end

function UIImage.Get:mask() return self.cobj:getMask() end
function UIImage.Set:mask(value) self.cobj:setMask(value) end

return UIImage
