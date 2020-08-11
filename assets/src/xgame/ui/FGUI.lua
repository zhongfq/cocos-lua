local class     = require "xgame.class"
local assets    = require "xgame.assets"
local window    = require "xgame.window"
local UILayer   = require "xgame.ui.UILayer"
local FGUINode  = require "xgame.ui.FGUINode"
local UIPackage = require "fgui.UIPackage"

local FGUI = class('FGUI', UILayer)

function FGUI:ctor()
    self.fguiAssets = {}
    self.fguiNode = self:addChild(FGUINode.new())
end

function FGUI:loadAssets(path)
    self.fguiAssets[path] = assets.load(path)
end

function FGUI:createUI(pkg, name)
    self.fgui = UIPackage.createObject(pkg, name)
    self.fgui.width, self.fgui.height = window.getVisibleSize()
    self.fguiNode.root:addChild(self.fgui)
end

-- extend GObject
local GObject = require "fgui.GObject"
local UIEventType = require "fgui.UIEventType"

function GObject:onClick(callback)
    return self:addEventListener(UIEventType.Click, callback)
end

function GObject:onChanged(callback)
    return self:addEventListener(UIEventType.Changed, callback)
end

function GObject:onClickItem(callback)
    return self:addEventListener(UIEventType.ClickItem, callback)
end

function GObject:onSubmit(callback)
    return self:addEventListener(UIEventType.Submit, callback)
end

function GObject:onTouchDown(callback)
    return self:addEventListener(UIEventType.TouchBegin, callback)
end

function GObject:onTouchMove(callback)
    return self:addEventListener(UIEventType.TouchMove, callback)
end

function GObject:onTouchUp(callback)
    return self:addEventListener(UIEventType.TouchEnd, callback)
end

return FGUI