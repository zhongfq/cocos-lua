local class             = require "xgame.class"
local loader            = require "xgame.loader"
local window            = require "xgame.window"
local filesystem        = require "xgame.filesystem"
local UILayer           = require "xgame.ui.UILayer"
local FGUINode          = require "xgame.ui.FGUINode"
local UIPackage         = require "fgui.UIPackage"
local GButton           = require "fgui.GButton"
local GLoader           = require "fgui.GLoader"
local UIEventDispatcher = require "fgui.UIEventDispatcher"
local UIEventType       = require "fgui.UIEventType"

local FGUI = class('FGUI', UILayer)

function FGUI:ctor()
    self.fguiNode = self:addChild(FGUINode.new())
end

function FGUI:loadAssets(path)
    self.assetRef = loader.load(path)
end

function FGUI:createUI(pkg, name)
    self.fgui = UIPackage.createObject(pkg, name)
    self.fgui.width, self.fgui.height = window.getVisibleSize()
    self.width = self.fgui.width
    self.height = self.fgui.height
    self.fguiNode.root:addChild(self.fgui)
end

-- extend fairygui

function GButton:playSound()
    self:dispatchEvent(UIEventType.Click)
end

function GLoader:load(url)
    self._loadingURL = url
    self.assetRef = loader.load(url, function (success)
        if self._loadingURL == url and success then
            self.url = filesystem.localCachePath(url)
        end
    end)
end

function UIEventDispatcher:onClick(callback)
    return self:addEventListener(UIEventType.Click, callback)
end

function UIEventDispatcher:onChanged(callback)
    return self:addEventListener(UIEventType.Changed, callback)
end

function UIEventDispatcher:onClickItem(callback)
    return self:addEventListener(UIEventType.ClickItem, callback)
end

function UIEventDispatcher:onSubmit(callback)
    return self:addEventListener(UIEventType.Submit, callback)
end

function UIEventDispatcher:onTouchDown(callback)
    return self:addEventListener(UIEventType.TouchBegin, callback)
end

function UIEventDispatcher:onTouchMove(callback)
    return self:addEventListener(UIEventType.TouchMove, callback)
end

function UIEventDispatcher:onTouchUp(callback)
    return self:addEventListener(UIEventType.TouchEnd, callback)
end

return FGUI