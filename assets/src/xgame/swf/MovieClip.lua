local class         = require "xgame.class"
local util          = require "xgame.util"
local Align       = require "xgame.ui.Align"
local DisplayObject = require "xgame.swf.DisplayObject"

local table = table
local next = next
local ipairs = ipairs
local string = string
local assert = assert
local setmetatable = setmetatable

local MovieClip = class("MovieClip", DisplayObject)

function MovieClip:ctor(cobj)
    self.metadata = swf.metadata(cobj)
    self.touch_children = true
    self.touchable = false 
    self.children = self:_create_access_proxy()
    self.ns = self:_create_access_proxy({__mode = "v"})  -- 索引有名字的字节点
    self._building = false
    self._real_parent = self
end

function MovieClip.Set:touch_style(value)
    DisplayObject.Set.touch_style(self, value)
    if value then
        self.button_mode = true
    end
end

function MovieClip:_build_children()
    if not self._building then
        self._building = true

        for i = self.num_children, 1, -1 do
            local child = self.children[i]
            if not self.cobj:contains(child.cobj) then
                self:_internal_remove_child(i)
            end
        end

        -- todo: not in order
        for i = 1, self.cobj.num_children do
            local ccobj = self.cobj:get_child_at(i - 1)
            local slot = self.children[i]
            if not slot or slot.cobj ~= ccobj then
                self:_internal_add_child(swf.wrapper(ccobj), i)
            end
        end

        self._building = false
    end
end

function MovieClip:_check_children()
    if not next(self.children) and not self._building then
        self:_build_children()
    end
end

function MovieClip:_create_access_proxy(mt)
    local arr = {}
    setmetatable(arr, {__index = function (_, index)
        self:_check_children()
        setmetatable(arr, mt)
        return arr[index]
    end})
    return arr
end

function MovieClip:_set_stage(value)
    if self._stage ~= value then
        if self.children then
            for _, child in pairs(self.children) do
                child:_set_stage(value)
            end
        end
        DisplayObject._set_stage(self, value)
    end
end

function MovieClip:hook(method, callback)
    return util.hook(self, method, callback)
end

function MovieClip:hit_children(points)
    local children = self.children
    for i = #children, 1, -1 do 
        local child = children[i]
        if child.visible and (child.touchable or child.touch_children) then
            local hit, capture_points = child:hit(points)
            if hit then
                return hit, capture_points 
            end
        end
    end
end

function MovieClip:hit(points)
    -- test children
    if self.touch_children then
        local hit, capture_points = self:hit_children(points)
        if hit then
            return hit, capture_points
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
    local l, r, t, b = swf.visible_bounds()
    local tl, tr, tt, tb = self:get_bounds(self)

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
    local l, r, t, b = swf.visible_bounds()
    local w, h = swf.design_size()
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
        self.parent:add_child(obj)
    end
    return obj
end

function MovieClip:create_movieclip()
    return swf.wrapper(self.cobj:create_movieclip())
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

function MovieClip:play_and_stop_at_end()
    self.cobj:play_and_stop_at_end()
end

function MovieClip:get_child_by_name(name)
    self:_check_children()
    return self.ns[name]
end

function MovieClip:get_child_at(index)
    self:_check_children()
    return self.children[index]
end

function MovieClip:get_child_index(child)
    self:_check_children()
    for index, child2 in ipairs(self.children) do
        if child.cobj == child2.cobj then
            return index
        end
    end

    return 0
end

function MovieClip:_internal_add_child(child, index, silence)
    table.insert(self.children, index, child)

    child._parent = self._real_parent

    if child.name then
        self.ns[child.name] = child
    end

    if self.stage and not silence then
        child:_set_stage(self.stage)
    end
end

function MovieClip:add_child(child)
    self:_check_children()
    return self:add_child_at(child, #self.children + 1)
end

function MovieClip:add_child_at(child, index)
    self:_check_children()

    if child.parent then
        local old_index = child.parent:get_child_index(child)
        assert(old_index > 0)
        child.parent:_internal_remove_child(old_index, true)

        self.cobj:add_child_at(child.cobj, index - 1)

        index = self.cobj:get_child_index(child.cobj) + 1
        self:_internal_add_child(child, index, true)
    else
        self.cobj:add_child_at(child.cobj, index - 1)

        index = self.cobj:get_child_index(child.cobj) + 1
        self:_internal_add_child(child, index)
    end

    return child
end

function MovieClip:_internal_remove_child(index, silence)
    assert(index == 0 or index > 0)

    if index == 0 then
        return
    end
    
    local child = table.remove(self.children, index)

    child._parent = false

    if child.name then
        self.ns[child.name] = nil
    end

    if child.stage and not silence then
        child:_set_stage(false)
    end

    return child
end

function MovieClip:remove_child(child)
    self:_check_children()

    local index = self:get_child_index(child)
    if index > 0 then
        return self:remove_child_at(index)
    end
end

function MovieClip:remove_child_at(index)
    self:_check_children()
    self.cobj:remove_child_at(index - 1)
    return self:_internal_remove_child(index)
end

function MovieClip:remove_children(start_index, end_index)
    self:_check_children()

    local num_children = self.num_children

    start_index = start_index or 1
    end_index = math.min(num_children, end_index or num_children)

    self.cobj:remove_children(start_index - 1, end_index)

    for index = end_index, start_index, -1 do
        self:_internal_remove_child(index)
    end
end

function MovieClip:swap_children(child1, child2)
    self.cobj:swap_children(child1.cobj, child2.cobj)
end

function MovieClip:swap_children_at(index1, index2)
    self.cobj:swap_children_at(index1 - 1, index2 - 1)
end

function MovieClip:goto_and_play(frame)
    if type(frame) == 'number' then
        frame = frame // 1
        if frame < 0 then
            frame = self.total_frames + frame + 1
        end
    end
    self.cobj:goto_and_play(frame)
    self:_build_children()
end

function MovieClip:goto_and_stop(frame)
    if type(frame) == 'number' then
        frame = frame // 1
        if frame < 0 then
            frame = self.total_frames + frame + 1
        end
    end
    self.cobj:goto_and_stop(frame)
    self:_build_children()
end

function MovieClip:frame_at(frame)
    return self.frame_labels[frame] == self.current_frame
end

function MovieClip:next_frame()
    self.cobj:next_frame()
    self:_build_children()
end

function MovieClip:prev_frame()
    self.cobj:prev_frame()
    self:_build_children()
end

function MovieClip.Get:top_mc()
    self:_check_children()
    for i = #self.children, 1, -1 do
        local child = self.children[i]
        if child.cobj.type == swf.type.MOVIECLIP then
            return child
        end
    end
end

function MovieClip:get_position()
    return self.cobj.x, self.cobj.y
end

function MovieClip:set_child_touchable(touchable, touch_children)
    for _, child in pairs(self.children) do
        child.touchable = touchable and true or false
        child.touch_children = touch_children and true or false
    end
end

function MovieClip.Get:mask()
    self:_check_children()
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

function MovieClip.Get:movie_width()
    return self.cobj.movie_width
end

function MovieClip.Get:movie_height()
    return self.cobj.movie_height
end

function MovieClip.Get:raw_frame_rate()
    return self.cobj.raw_frame_rate
end

function MovieClip.Get:frame_rate()
    return self.cobj.frame_rate
end

function MovieClip.Set:frame_rate(value)
    self.cobj.frame_rate = value
end

function MovieClip.Get:num_children()
    self:_check_children()
    return #self.children 
end

function MovieClip.Get:current_frame()
    return self.cobj.current_frame
end

function MovieClip.Get:total_frames()
    return self.cobj.total_frames
end

function MovieClip.Get:frame_labels()
    if not self._frame_labels then
        self._frame_labels = self.cobj.frame_labels
    end
    return self._frame_labels
end

function MovieClip.Get:current_label()
    return self.cobj.current_label
end

function MovieClip.Get:button_mode()
    return self._button_mode
end

function MovieClip.Set:button_mode(value)
    self._button_mode = value
    self.touch_children = not value
    self.touchable = value
end

return MovieClip
