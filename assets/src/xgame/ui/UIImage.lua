local class             = require "xgame.class"
local loader            = require "xgame.loader"
local filesystem        = require "xgame.filesystem"
local Event             = require "xgame.event.Event"
local LoadTask          = require "xgame.LoadTask"
local UIView            = require "xgame.ui.UIView"
local ImageView         = require "ccui.ImageView"
local TextureResType    = require "ccui.Widget.TextureResType"

local spriteFrameCache = require("cc.SpriteFrameCache").instance

local UIImage = class("UIImage", UIView)

function UIImage:ctor()
    self._capInset = false
    self._url = false
    self.filePath = false
    self.preferredWidth = 0
    self.preferredHeight = 0
end

function UIImage.Get:cobj()
    local cobj = ImageView.create()
    rawset(self, "cobj", cobj)
    return cobj
end

function UIImage:unload()
    self.filePath = false
end

function UIImage:loadTexture(path)
    self.filePath = path

    if filesystem.exist(path) then
        self.cobj:loadTexture(path, TextureResType.LOCAL)
    else
        assert(spriteFrameCache:getSpriteFrameByName(path), path)
        self.cobj:loadTexture(path, TextureResType.PLIST)
        if self.scale9Enabled and self._capInset then
            self:setCapInset(table.unpack(self._capInset))
        end
    end

    self:_validateNow()
end

function UIImage:_doLoad(url, callback)
    if url and #url > 0 then
        self._url = url
        self.assetRef = loader.load(url, function (success)
            if self._url == url and success then
                callback()
            end
        end)
    end
end

function UIImage:load(url)
    self:_doLoad(function ()
        self:loadTexture(filesystem.localCachePath(url))
        self:validateDisplay()
    end)
end

function UIImage:loadAsync(url)
    self:_doLoad(function ()
        self:loadTexture(filesystem.localCachePath(url))
        self:validateDisplay()
    end)
end

function UIImage:validateDisplay()
    if self.preferredWidth > 0 and self.preferredHeight > 0 then
        self.scaleX = 1
        self.scaleY = 1
        local width, height = self.width, self.height
        if width > 0 and height > 0 then
            self.scaleX = self.preferredWidth / width
            self.scaleY = self.preferredHeight / height
        end
    end
end

function UIImage.Get:shader()
    return self.cobj:getGLProgram()
end

function UIImage.Set:shader(value)
    self.cobj:setGLProgram(assert(value))
end

function UIImage:setCapInset(left, right, top, bottom)
    local renderer = self.cobj:getVirtualRenderer()
    renderer:setInsetLeft(left)
    renderer:setInsetRight(right)
    renderer:setInsetTop(top)
    renderer:setInsetBottom(bottom)

    self._capInset = {left, right, top, bottom}
end

function UIImage.Get:scale9Enabled() return self.cobj.scale9Enabled end
function UIImage.Set:scale9Enabled(value)
    self.cobj.scale9Enabled = value
end

return UIImage
