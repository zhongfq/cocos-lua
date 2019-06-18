local class         = require "xgame.class"
local util          = require "xgame.util"
local Align         = require "xgame.ui.Align"
local DisplayObject = require "xgame.swf.DisplayObject"
local swf           = require "xgame.swf.swf"
local T             = require "swf.type"
local window        = require "kernel.window"

local table = table
local next = next
local ipairs = ipairs
local assert = assert
local setmetatable = setmetatable

local MovieClip = class("MovieClip", DisplayObject)

function MovieClip:ctor(cobj)
    self.metadata = swf.metadata(cobj)
    self.touchChildren = true
    self.touchable = false
    self.children = self:_createAccessProxy()
    self.ns = self:_createAccessProxy({__mode = "v"})  -- 索引有名字的字节点
    self._building = false
    self._rawChildren = setmetatable({}, {__mode = 'k'})
    self._realParent = self
end

function MovieClip:_buildChildren()
    if not self._building then
        self._building = true

        for i = self.numChildren, 1, -1 do
            local child = self.children[i]
            if not self.cobj:contains(child.cobj) then
                self:_internalRemoveChild(i)
            end
        end

        for i = 1, self.cobj.numChildren do
            local rawChild = self.cobj:getChildAt(i - 1)
            if not self._rawChildren[rawChild] then
                self:_internalAddChild(swf.wrapper(rawChild), i)
            end
        end

        self._building = false
    end
end

function MovieClip:_checkChildren()
    if not next(self.children) and not self._building then
        self:_buildChildren()
    end
end

function MovieClip:_createAccessProxy(mt)
    local arr = {}
    setmetatable(arr, {__index = function (_, index)
        self:_checkChildren()
        setmetatable(arr, mt)
        return arr[index]
    end})
    return arr
end

function MovieClip:_setStage(value)
    if self._stage ~= value then
        if self.children then
            for _, child in pairs(self.children) do
                child:_setStage(value)
            end
        end
        DisplayObject._setStage(self, value)
    end
end

function MovieClip:hook(method, callback)
    return util.hook(self, method, callback)
end

function MovieClip:hitChildren(points)
    local children = self.children
    for i = #children, 1, -1 do
        local child = children[i]
        if child.visible and (child.touchable or child.touchChildren) then
            local hit, capturePoints = child:hit(points)
            if hit then
                return hit, capturePoints
            end
        end
    end
end

function MovieClip:hit(points)
    -- test children
    if self.touchChildren then
        local hit, capturePoints = self:hitChildren(points)
        if hit then
            return hit, capturePoints
        end
    end

    -- test self
    if self.touchable then
        return DisplayObject.hit(self, points)
    else
        return nil, nil
    end
end

function MovieClip:align(horizontal, vertical)
    local l, r, t, b = window.getVisibleBounds()
    local tl, tr, tt, tb = self:getBounds(self)

    if horizontal == Align.LEFT then
        self.x = l - tl
    elseif horizontal == Align.CENTER then
        self.x = (l + r) / 2 - (tl + tr) / 2
    elseif horizontal == Align.RIGHT then
        self.x = r - tr
    end
    
    if vertical == Align.TOP then
        self.y = t - tt
    elseif vertical == Align.CENTER then
        self.y = (t + b) / 2 - (tt + tb) / 2
    elseif vertical == Align.BOTTOM then
        self.y = b - tb
    end
end

function MovieClip:relative(horizontal, vertical)
    local l, r, t, b = window.getVisibleBounds()
    local w, h = window.getDesignSize()
    if horizontal == Align.LEFT then
        self.x = self.x + l
    elseif horizontal == Align.CENTER then
        self.x = self.x + (r - l - w) / 2
    elseif horizontal == Align.RIGHT then
        self.x = self.x + r - w
    else
        assert(horizontal == Align.NONE, horizontal)
    end
    
    if vertical == Align.TOP then
        self.y = self.y + t
    elseif vertical == Align.CENTER then
        self.y = self.y - (b - t - h)
    elseif vertical == Align.BOTTOM then
        self.y = self.y + b - h
    else
        assert(vertical == Align.NONE, vertical)
    end
end

-- 只能复制swf导出时的对象
function MovieClip:clone(name)
    local obj = swf.wrapper(self.cobj:clone(name))
    if self.parent then
        self.parent:addChild(obj)
    end
    return obj
end

function MovieClip:createMovieclip()
    return swf.wrapper(self.cobj:createMovieclip())
end

function MovieClip:stop()
    self.cobj:stop()
end

function MovieClip:play()
    self.cobj:play()
end

function MovieClip:pause()
    self.cobj:pause()
end

function MovieClip:resume()
    self.cobj:resume()
end

function MovieClip:playOnce()
    self.cobj:playOnce()
end

function MovieClip:getChildByName(name)
    self:_checkChildren()
    return self.ns[name]
end

function MovieClip:getChildAt(index)
    self:_checkChildren()
    return self.children[index]
end

function MovieClip:getChildIndex(child)
    self:_checkChildren()
    for index, child2 in ipairs(self.children) do
        if child.cobj == child2.cobj then
            return index
        end
    end

    return 0
end

function MovieClip:_internalAddChild(child, index, silence)
    table.insert(self.children, index, child)
    self._rawChildren[child.cobj] = child
    child._parent = self._realParent

    if child.name then
        self.ns[child.name] = child
    end

    if self.stage and not silence then
        child:_setStage(self.stage)
    end
    
end

function MovieClip:addChild(child)
    self:_checkChildren()
    return self:addChildAt(child, #self.children + 1)
end

function MovieClip:addChildAt(child, index)
    self:_checkChildren()

    if child.parent then
        local old_index = child.parent:getChildIndex(child)
        assert(old_index > 0)
        child.parent:_internalRemoveChild(old_index, true)

        self.cobj:addChildAt(child.cobj, index - 1)

        index = self.cobj:getChildIndex(child.cobj) + 1
        self:_internalAddChild(child, index, true)
    else
        self.cobj:addChildAt(child.cobj, index - 1)

        index = self.cobj:getChildIndex(child.cobj) + 1
        self:_internalAddChild(child, index)
    end

    return child
end

function MovieClip:_internalRemoveChild(index, silence)
    assert(index == 0 or index > 0)

    if index == 0 then
        return
    end
    
    local child = table.remove(self.children, index)

    self._rawChildren[child.cobj] = nil
    child._parent = false

    if child.name then
        self.ns[child.name] = nil
    end

    if child.stage and not silence then
        child:_setStage(false)
    end

    return child
end

function MovieClip:removeChild(child)
    self:_checkChildren()

    local index = self:getChildIndex(child)
    if index > 0 then
        return self:removeChildAt(index)
    end
end

function MovieClip:removeChildAt(index)
    self:_checkChildren()
    self.cobj:removeChildAt(index - 1)
    return self:_internalRemoveChild(index)
end

function MovieClip:removeChildren(from, to)
    self:_checkChildren()

    local numChildren = self.numChildren

    from = from or 1
    to = math.min(numChildren, to or numChildren)

    self.cobj:removeChildren(from - 1, to)

    for index = to, from, -1 do
        self:_internalRemoveChild(index)
    end
end

function MovieClip:swapChildren(child1, child2)
    self.cobj:swapChildren(child1.cobj, child2.cobj)
end

function MovieClip:swapChildrenAt(index1, index2)
    self.cobj:swapChildrenAt(index1 - 1, index2 - 1)
end

function MovieClip:gotoAndPlay(frame)
    if type(frame) == 'number' then
        frame = frame // 1
        if frame < 0 then
            frame = self.totalFrames + frame + 1
        end
    end
    self.cobj:gotoAndPlay(frame)
    self:_buildChildren()
end

function MovieClip:gotoAndStop(frame)
    if type(frame) == 'number' then
        frame = frame // 1
        if frame < 0 then
            frame = self.totalFrames + frame + 1
        end
    end
    self.cobj:gotoAndStop(frame)
    self:_buildChildren()
end

function MovieClip:frameAt(frame)
    return self.frameLabels[frame] == self.currentFrame
end

function MovieClip:nextFrame()
    self.cobj:nextFrame()
    self:_buildChildren()
end

function MovieClip:prevFrame()
    self.cobj:prevFrame()
    self:_buildChildren()
end

function MovieClip.Get:top_mc()
    self:_checkChildren()
    for i = #self.children, 1, -1 do
        local child = self.children[i]
        if child.cobj.type == T.MOVIECLIP then
            return child
        end
    end
end

function MovieClip:setChildTouchable(touchable, touchChildren)
    for _, child in pairs(self.children) do
        child.touchable = touchable and true or false
        child.touchChildren = touchChildren and true or false
    end
end

function MovieClip.Get:mask()
    self:_checkChildren()
    local mask = self.cobj.mask
    for _, child in ipairs(self.children) do
        if child.cobj == mask then
            return child
        end
    end
    return MovieClip.new(mask)
end

function MovieClip.Set:mask(value)
    self.cobj.mask = value.cobj
end

function MovieClip.Get:movieWidth()
    return self.cobj.movieWidth
end

function MovieClip.Get:movieHeight()
    return self.cobj.movieHeight
end

function MovieClip.Get:rawFrameRate()
    return self.cobj.rawFrameRate
end

function MovieClip.Get:frameRate()
    return self.cobj.frameRate
end

function MovieClip.Set:frameRate(value)
    self.cobj.frameRate = value
end

function MovieClip.Get:numChildren()
    self:_checkChildren()
    return #self.children
end

function MovieClip.Get:currentFrame()
    return self.cobj.currentFrame
end

function MovieClip.Get:totalFrames()
    return self.cobj.totalFrames
end

function MovieClip.Get:frameLabels()
    if not self._frameLabels then
        self._frameLabels = self.cobj.frameLabels
    end
    return self._frameLabels
end

function MovieClip.Get:currentLabel()
    return self.cobj.currentLabel
end

return MovieClip
