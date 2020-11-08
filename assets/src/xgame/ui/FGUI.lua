local class             = require "xgame.class"
local loader            = require "xgame.loader"
local window            = require "xgame.window"
local Event             = require "xgame.event.Event"
local LoadTask          = require "xgame.LoadTask"
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
    self._assetObject = loader.load(path)
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
    local loader = LoadTask.new(url)
    self._loadingURL = url
    loader:addListener(Event.COMPLETE, function ()
        if url == self._loadingURL then
            self.url = loader.path
        end
    end)
    loader:start()
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