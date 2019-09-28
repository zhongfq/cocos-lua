local class     = require "xgame.class"
local window    = require "xgame.window"
local UIView    = require "xgame.ui.UIView"
local Scene     = require "kernel.SceneNoCamera"
local GRoot     = require "fgui.GRoot"

local FGUINode = class('FGUINode', UIView)

function FGUINode:ctor()
    self.multiTouch = true
    self.touchable = true
    self.root = GRoot.create(self.cobj)
    self.root.inputProcessor:disableDefaultTouchEvent()
    self.root:setSize(self.cobj.width, self.cobj.height)
end

function FGUINode.Get:cobj()
    local width, height = window.getVisibleSize()
    local cobj = Scene.createWithSize({width = width, height = height})
    rawset(self, 'cobj', cobj)
    return cobj
end

function FGUINode:hitTest()
    local root = self.root
    return root.visible and root.touchable
end

function FGUINode:touchDown(points)
    local inputProcessor = self.root.inputProcessor
    for _, point in pairs(points) do
        if point.touch then
            inputProcessor:touchDown(point.touch, point.event)
        end
    end
end

function FGUINode:touchMove(points)
    local inputProcessor = self.root.inputProcessor
    for _, point in pairs(points) do
        if point.touch then
            inputProcessor:touchMove(point.touch, point.event)
        end
    end
end

function FGUINode:touchUp(points)
    local inputProcessor = self.root.inputProcessor
    for _, point in pairs(points) do
        if point.touch then
            inputProcessor:touchUp(point.touch, point.event)
        end
    end
end

return FGUINode