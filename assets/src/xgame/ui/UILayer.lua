local class             = require "xgame.class"
local Array             = require "xgame.Array"
local UIView            = require "xgame.ui.UIView"
local AbsoluteLayout    = require "xgame.ui.AbsoluteLayout"
local MaskLayout        = require "ccui.MaskLayout"
local Node              = require "cc.Node"

local assert = assert
local ipairs = ipairs

local UnknownNode
local dummyNode = Node.create()

local UILayer = class("UILayer", UIView)

function UILayer:ctor()
    self.musicOption = {} -- path|keep
    self.renderOption = {}
    self._rawChildren = {}
    self._children = false
    self._realParent = self
    self.touchChildren = true

    if self.cobj.setClippingEnabled then
        self.cobj.cascadeOpacityEnabled = true
        self.cobj.cascadeColorEnabled = false
        self.cobj.touchEnabled = false
        self.cobj.clippingEnabled = false
    end
end

function UILayer.Get:cobj()
    local cobj = MaskLayout.create()
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

function UILayer:_setChildrenActive(target, active)
    if target.children then
        for _, child in ipairs(target.children) do
            if child.didActive or child.didInactive then
                if active then
                    child:didActive()
                else
                    child.didInactive()
                end
            else
                self:_setChildrenActive(child, active)
            end
        end
    end
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

function UILayer:_buildChildren()
    if not self._children then
        self.cobj:sortAllChildren()
        self._children = Array.new()
        for i, rawChild in ipairs(self.cobj.children) do
            rawChild:setLocalZOrder(i)

            local child = self._rawChildren[rawChild]
            if not child then
                child = UnknownNode.new()
                child.cobj = rawChild
                self._rawChildren[rawChild] = child
            end
            self._children:add(child)
        end
    end
end

function UILayer:addChild(child)
    return self:addChildAt(child, self.numChildren + 1)
end

function UILayer:_internalAddChild(child, index, silence)
    self._rawChildren[child.cobj] = child
    self.cobj:addChild(child.cobj, index)
    self.children:addAt(child, index)
    child._parent = self._realParent
    if self.stage and not silence then
        child:_setStage(self.stage)
    end
end

function UILayer:addChildAt(child, index)
    self:_buildChildren()
    if child.parent then
        local oldIndex = child.parent:getChildIndex(child)
        assert(oldIndex > 0)
        child.parent:_internalRemoveChild(oldIndex, true)
        self:_internalAddChild(child, index, true)
    else
        self:_internalAddChild(child, index)
    end

    self:_notifyUpdate(child)

    return child
end

function UILayer:getChildAt(index)
    if self._children then
        return self._children:at(index)
    end
end

function UILayer:getChildIndex(child)
    for index, child2 in ipairs(self.children) do
        if child.cobj == child2.cobj then
            return index
        end
    end
    return 0
end

function UILayer:_internalRemoveChild(index, silence)
    local child = self.children:removeAt(index)
    self._rawChildren[child.cobj] = nil
    self.cobj:removeChild(child.cobj)
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

function UILayer:reorderChild(child, order)
    self.cobj:reorderChild(child.cobj, order)
    self._children = false
end

function UILayer.Get:numChildren()
    return #self.children
end

function UILayer.Get:children()
    self:_buildChildren()
    return self._children
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

UnknownNode = class("UnknownNode", UIView)

function UnknownNode:ctor()
    self.touchChildren = false
    self.touchable = false
end

function UnknownNode.Get:cobj()
    rawset(self, 'cobj', dummyNode)
    return dummyNode
end

return UILayer
