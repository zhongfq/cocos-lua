local class             = require "xgame.class"
local window            = require "xgame.window"
local Array             = require "xgame.Array"
local UIView            = require "xgame.ui.UIView"
local AbsoluteLayout    = require "xgame.ui.AbsoluteLayout"
local MaskLayout        = require "cclua.MaskLayout"

local ipairs = ipairs

local InnerContainer

local UILayer = class("UILayer", UIView)

function UILayer:ctor()
    self.musicOption = {} -- path|keep
    self.renderOption = {
        snapshot = false,
        snapshotScale = window.getFitScale()
    }
    self.children = Array.new()
    self.touchChildren = true
    self._innerContainer = InnerContainer.new()
    self._innerContainer.anchorX = 0
    self._innerContainer.anchorY = 0
    self.cobj:addChild(self._innerContainer.cobj)
end

function UILayer.Get:cobj()
    local cobj = MaskLayout.create()
    cobj.cascadeOpacityEnabled = true
    cobj.cascadeColorEnabled = false
    cobj.touchEnabled = false
    rawset(self, "cobj", cobj)
    return cobj
end

function UILayer:reszieToChildren(resizeWidth, resizeHeight)
    self._layout:doLayout()
    local left = math.maxinteger
    local right = math.mininteger
    local top = math.mininteger
    local bottom = math.maxinteger
    for _, child in ipairs(self.children) do
        if not child.visible then
            goto continue
        end

        local cl, cr, ct, cb = child:getBounds(self)
        left = math.min(left, cl)
        right = math.max(right, cr)
        top = math.max(top, ct)
        bottom = math.min(bottom, cb)

        ::continue::
    end

    if resizeWidth ~= false then
        self.width = right - left
    end

    if resizeHeight ~= false then
        self.height = top - bottom
    end
    self:_validateNow()
end

function UILayer:hit(points)
    -- test children
    if self.touchChildren then
        local children = self.children
        for i = #self.children, 1, -1 do
            local child = children[i]
            if child.visible and (child.touchable or child.touchChildren) then
                local hit, capturePoints = child:hit(points)
                if hit then
                    return hit, capturePoints
                end
            end
        end
    end

    -- test self
    if self.touchable then
        return UIView.hit(self, points)
    end
end

function UILayer:_notifyUpdate(child)
    self.layout:notify("UPDATE", child)
end

function UILayer:addChild(child)
    return self:addChildAt(child, self.numChildren + 1)
end

function UILayer:_internalAddChild(child, index, silence)
    self._innerContainer.cobj:addChild(child.cobj, index)
    self.children:addAt(child, index)
    child._parent = self
    if self.stage and not silence then
        child:_setStage(self.stage)
    end
    for i = index + 1, #self.children do
        local c = self.children[i]
        c.cobj.localZOrder = i
    end
end

function UILayer:addChildAt(child, index)
    if child.parent then
        child:removeSelf()
        index = math.min(index, self.numChildren + 1)
        self:_internalAddChild(child, index, true)
    else
        self:_internalAddChild(child, index)
    end

    self:_notifyUpdate(child)

    return child
end

function UILayer:getChildAt(index)
    if self.children then
        return self.children:at(index)
    end
end

function UILayer:getChildIndex(child)
    return self.children:indexOf(child)
end

function UILayer:_internalRemoveChild(index, silence)
    local child = self.children:removeAt(index)
    self._innerContainer.cobj:removeChild(child.cobj)
    child._parent = false
    if child.stage and not silence then
        child:_setStage(false)
    end
    return child
end

function UILayer:removeChild(child)
    local index = self.children:indexOf(child)
    return self:removeChildAt(index)
end

function UILayer:removeChildAt(index)
    local child = self:_internalRemoveChild(index)
    self:_notifyUpdate(child)
    return child
end

function UILayer:removeChildren(from, to)
    local numChildren = self.numChildren
    from = from or 1
    to = math.min(numChildren, to or numChildren)
    for i = to, from, -1 do
        self:removeChildAt(i)
    end
end

function UILayer.Get:numChildren()
    return #self.children
end

function UILayer.Get:layout()
    if not self._layout then
        self._layout = AbsoluteLayout.new()
        self._layout.target = self
    end
    return self._layout
end

function UILayer.Set:layout(value)
    self._layout = value
    self._layout.target = self
    self._layout:doLayout()
end

function UILayer.Get:clippingEnabled() return self.cobj.clippingEnabled end
function UILayer.Set:clippingEnabled(value)
    self.cobj.clippingEnabled = value
end

function UILayer:_setStage(value)
    if self._stage ~= value then
        for _, child in ipairs(self.children) do
            child:_setStage(value)
        end
        UIView._setStage(self, value)
    end
end

InnerContainer = class('InnerContainer', UIView)

function InnerContainer.Get:cobj()
    local cobj = MaskLayout.create()
    cobj.cascadeOpacityEnabled = true
    cobj.cascadeColorEnabled = false
    cobj.touchEnabled = false
    rawset(self, "cobj", cobj)
    return cobj
end

return UILayer
