local class     = require "xgame.class"
local UIView    = require "xgame.ui.UIView"
local window    = require "xgame.window"
local swf       = require "xgame.swf.swf"

local NO_CHILDREN = {}

local SWFNode = class("SWFNode", UIView)

function SWFNode:ctor(rootswf)
    self._rootswf = false
    self.width, self.height = window.getDesignSize()
    self.touchable = false
    self.touchChildren = true

    if rootswf then
        self.rootswf = rootswf
    end
end

function SWFNode.Get:children()
    if self.rootswf then
        return self.rootswf.children
    else
        return NO_CHILDREN
    end
end

function SWFNode.Get:cobj()
    local cobj = swf.SWFNode.create()
    rawset(self, "cobj", cobj)
    return cobj
end

function SWFNode:validateDisplay()
    if self.rootswf then
        for _, child in ipairs(self.rootswf.children) do
            if child.validateDisplay then
                child:validateDisplay()
            end
        end
    end
end

function SWFNode.Get:rootswf()
    return self._rootswf
end

function SWFNode.Set:rootswf(value)
    if self.rootswf then
        self.rootswf:_setStage(false)
    end

    self._rootswf = value
    self._rootswf._rootNode = self
    self.cobj.rootswf = value.cobj
    if self.stage then
        self.rootswf:_setStage(self.stage)
    end
end

function SWFNode:swfToWorldSpace(x, y)
    return self.cobj:swfToWorldSpace(x, y)
end

function SWFNode:worldToSWFSpace(x, y)
    return self.cobj:worldToSWFSpace(x, y)
end

function SWFNode:hit(points)
    if self.rootswf then
        local hit, capturePoints = self.rootswf:hit(points)
        if hit then
            return hit, capturePoints
        end
    end

    if self.touchable then
        return UIView.hit(self, points)
    end
end

function SWFNode:_setStage(value)
    if self.rootswf then
        self.rootswf:_setStage(value)
    end
    UIView._setStage(self, value)
end

return SWFNode
