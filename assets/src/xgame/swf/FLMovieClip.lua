local class             = require "xgame.class"
local util              = require "xgame.util"
local Array             = require "xgame.Array"
local window            = require "xgame.window"
local runtime           = require "xgame.runtime"
local Align             = require "xgame.ui.Align"
local swf               = require "xgame.swf.swf"
local FLDisplayObject   = require "xgame.swf.FLDisplayObject"

local T = swf.ObjectType

local table = table
local ipairs = ipairs
local assert = assert
local setmetatable = setmetatable

local FLMovieClip = class("FLMovieClip", FLDisplayObject)

function FLMovieClip:ctor(cobj)
    self.metadata = swf.metadata(cobj)

    if self:hasLabel('iPhone') and self:hasLabel('iPad') then
        if runtime.isPad() then
            self.cobj:gotoAndStop('iPad')
        else
            self.cobj:gotoAndStop('iPhone')
        end
    end

    self.touchChildren = true
    self.touchable = false
    self._children = Array.new()
    self.ns = self:_createAccessProxy({__mode = "v"})  -- 索引有名字的字节点
    self._building = false
    self._rawChildren = setmetatable({}, {__mode = 'k'})
    self._realParent = self
end

function FLMovieClip:_buildChildren()
    if not self._building then
        self._building = true

        for i = self.numChildren, 1, -1 do
            local child = self._children[i]
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

function FLMovieClip:_checkChildren()
    if #self._children == 0 and not self._building then
        self:_buildChildren()
    end
end

function FLMovieClip:_createAccessProxy(mt)
    local arr = {}
    setmetatable(arr, {__index = function (_, index)
        self:_checkChildren()
        setmetatable(arr, mt)
        return arr[index]
    end})
    return arr
end

function FLMovieClip:_setStage(value)
    if self._stage ~= value then
        if #self._children > 0 then
            for _, child in ipairs(self._children) do
                child:_setStage(value)
            end
        end
        FLDisplayObject._setStage(self, value)
    end
end

function FLMovieClip:hook(method, callback)
    return util.hook(self, method, callback)
end

function FLMovieClip:hitChildren(points)
    local children = self._children
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

function FLMovieClip:hit(points)
    -- test children
    if self.touchChildren then
        local hit, capturePoints = self:hitChildren(points)
        if hit then
            return hit, capturePoints
        end
    end

    -- test self
    if self.touchable then
        return FLDisplayObject.hit(self, points)
    else
        return nil, nil
    end
end

function FLMovieClip:relative(horizontal, vertical)
    local l, r, t, b = window.getVisibleBounds()
    l, t = self.rootNode.rootswf:globalToLocal(l, t)
    r, b = self.rootNode.rootswf:globalToLocal(r, b)
    local w, h = self.movieWidth, self.movieHeight
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

function FLMovieClip:resolve(name)
    local found = self
    if found then
        for k in string.gmatch(name, "[^.]+") do
            if found then
                found = found.ns[k]
            end
        end
        if found then
            return found
        end
    end
end

-- 只能复制swf导出时的对象
function FLMovieClip:clone(name)
    local obj = swf.wrapper(self.cobj:clone(name))
    if self.parent then
        self.parent:addChild(obj)
    end
    return obj
end

function FLMovieClip:createMovieclip()
    return swf.wrapper(self.cobj:createMovieclip())
end

function FLMovieClip:stop()
    self.cobj:stop()
end

function FLMovieClip:play()
    self.cobj:play()
end

function FLMovieClip:pause()
    self.cobj:pause()
end

function FLMovieClip:resume()
    self.cobj:resume()
end

function FLMovieClip:playOnce()
    self.cobj:playOnce()
end

function FLMovieClip:getChildByName(name)
    self:_checkChildren()
    return self.ns[name]
end

function FLMovieClip:getChildAt(index)
    return self.children[index]
end

function FLMovieClip:getChildIndex(child)
    for index, child2 in ipairs(self.children) do
        if child.cobj == child2.cobj then
            return index
        end
    end

    return 0
end

function FLMovieClip:_internalAddChild(child, index, silence)
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

function FLMovieClip:addChild(child)
    return self:addChildAt(child, #self.children + 1)
end

function FLMovieClip:addChildAt(child, index)
    if child.parent then
        local old_index = child.parent:getChildIndex(child)
        assert(old_index > 0)
        child.parent:_internalRemoveChild(old_index, true)

        index = math.min(index, #self.children + 1)
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

function FLMovieClip:_internalRemoveChild(index, silence)
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

function FLMovieClip:removeChild(child)
    local index = self:getChildIndex(child)
    if index > 0 then
        return self:removeChildAt(index)
    end
end

function FLMovieClip:removeChildAt(index)
    self.cobj:removeChildAt(index - 1)
    return self:_internalRemoveChild(index)
end

function FLMovieClip:removeChildren(from, to)
    local numChildren = self.numChildren

    from = from or 1
    to = math.min(numChildren, to or numChildren)

    self.cobj:removeChildren(from - 1, to)

    for index = to, from, -1 do
        self:_internalRemoveChild(index)
    end
end

function FLMovieClip:swapChildren(child1, child2)
    self.cobj:swapChildren(child1.cobj, child2.cobj)
end

function FLMovieClip:swapChildrenAt(index1, index2)
    self.cobj:swapChildrenAt(index1 - 1, index2 - 1)
end

function FLMovieClip:gotoAndPlay(frame)
    if type(frame) == 'number' then
        frame = frame // 1
        if frame < 0 then
            frame = self.totalFrames + frame + 1
        end
    end
    self.cobj:gotoAndPlay(frame)
    self:_buildChildren()
end

function FLMovieClip:gotoAndStop(frame)
    if type(frame) == 'number' then
        frame = frame // 1
        if frame < 0 then
            frame = self.totalFrames + frame + 1
        end
    end
    self.cobj:gotoAndStop(frame)
    self:_buildChildren()
end

function FLMovieClip:labelAt(frame)
    return self.frameLabels[frame] == self.currentFrame
end

function FLMovieClip:hasLabel(label)
    return self.frameLabels[label] ~= nil
end

function FLMovieClip:nextFrame()
    self.cobj:nextFrame()
    self:_buildChildren()
end

function FLMovieClip:prevFrame()
    self.cobj:prevFrame()
    self:_buildChildren()
end

function FLMovieClip.Get:topMC()
    for i = #self.children, 1, -1 do
        local child = self.children[i]
        if child.cobj.type == T.MOVIE_CLIP then
            return child
        end
    end
end

function FLMovieClip:setChildTouchable(touchable, touchChildren)
    for _, child in ipairs(self.children) do
        child.touchable = touchable and true or false
        child.touchChildren = touchChildren and true or false
    end
end

function FLMovieClip.Get:mask()
    local mask = self.cobj.mask
    for _, child in ipairs(self.children) do
        if child.cobj == mask then
            return child
        end
    end
    return FLMovieClip.new(mask)
end

function FLMovieClip.Set:mask(value)
    self.cobj.mask = value.cobj
end

function FLMovieClip.Get:movieWidth()
    return self.cobj.movieWidth
end

function FLMovieClip.Get:movieHeight()
    return self.cobj.movieHeight
end

function FLMovieClip.Get:rawFrameRate()
    return self.cobj.rawFrameRate
end

function FLMovieClip.Get:frameRate()
    return self.cobj.frameRate
end

function FLMovieClip.Set:frameRate(value)
    self.cobj.frameRate = value
end

function FLMovieClip.Get:numChildren()
    return #self.children
end

function FLMovieClip.Get:children()
    self:_checkChildren()
    return self._children
end

function FLMovieClip.Get:currentFrame()
    return self.cobj.currentFrame
end

function FLMovieClip.Get:totalFrames()
    return self.cobj.totalFrames
end

function FLMovieClip.Get:frameLabels()
    if not self._frameLabels then
        self._frameLabels = self.cobj.frameLabels
    end
    return self._frameLabels
end

function FLMovieClip.Get:currentLabel()
    return self.cobj.currentLabel
end

return FLMovieClip
