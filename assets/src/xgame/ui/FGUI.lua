local class     = require "xgame.class"
local assets    = require "xgame.assets"
local window    = require "xgame.window"
local UILayer   = require "xgame.ui.UILayer"
local FGUINode  = require "xgame.ui.FGUINode"
local UIPackage = require "fgui.UIPackage"

local FGUI = class('FGUI', UILayer)

function FGUI:ctor()
    self.fguiNode = self:addChild(FGUINode.new())
end

function FGUI:loadAssets(path)
    self.fguiAsset = assets.load(path)
end

function FGUI:createUI(pkg, name)
    self.fgui = UIPackage.createObject(pkg, name)
    self.fgui.width, self.fgui.height = window.getVisibleSize()
    self.fguiNode.root:addChild(self.fgui)
end

-- extend UIEventDispatcher
local UIEventDispatcher = require "fgui.UIEventDispatcher"
local UIEventType = require "fgui.UIEventType"

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