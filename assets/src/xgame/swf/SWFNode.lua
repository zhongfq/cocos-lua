local class     = require "xgame.class"
local UIView    = require "xgame.ui.UIView"
-- local ui        = require "xgame.ui.ui"
local window    = require "xgame.window"
local swf       = require "xgame.swf.swf"

local SWFNode = class("SWFNode", UIView)

function SWFNode:ctor()
    self._rootSWF = false
    self.width, self.height = window.getDesignSize()
    self.touchable = false
    self.touchChildren = true
end

function SWFNode.Get:children()
    if self.rootSWF then
        return self.rootSWF.children
    else
        return {}
    end
end

function SWFNode.Get:cobj()
    local cobj = swf.SWFNode.create()
    rawset(self, "cobj", cobj)
    return cobj
end

function SWFNode.Get:rootSWF()
    return self._rootSWF
end

function SWFNode.Set:rootSWF(value)
    if self.rootSWF then
        self.rootSWF:_setStage(false)
    end

    self._rootSWF = value
    self._rootSWF._rootNode = self
    self.cobj.rootSWF = value.cobj
    if self.stage then
        self.rootSWF:_setStage(self.stage)
    end
end

function SWFNode:swfToWorldSpace(x, y)
    return self.cobj:swfToWorldSpace(x, y)
end

function SWFNode:worldToSWFSpace(x, y)
    return self.cobj:worldToSWFSpace(x, y)
end

function SWFNode:hit(points)
    if self.rootSWF then
        local hit, capturePoints = self.rootSWF:hit(points)
        if hit then
            return hit, capturePoints
        end
    end

    if self.touchable then
        return UIView.hit(self, points)
    end
end

function SWFNode:_setStage(value)
    if self.rootSWF then
        self.rootSWF:_setStage(value)
    end
    UIView._setStage(self, value)
end

return SWFNode
