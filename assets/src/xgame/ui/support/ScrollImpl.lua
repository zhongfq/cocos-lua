--
-- $id: ScrollImpl.lua O $
--

local class             = require "xgame.class"
local UIAlign           = require "xgame.display.UIAlign"
local TouchEvent        = require "xgame.display.TouchEvent"
local LayoutManager     = require "xgame.display.support.LayoutManager"
local GestureDetector   = require "xgame.display.support.GestureDetector"

local assert = assert
local math = math
local PI_2 = math.pi / 2

local ScrollImpl = class("ScrollImpl")

function ScrollImpl:ctor(target, container)
    self._target = target
    self._container = container
    self._detector = GestureDetector.new(target, self)
    self._focuses = setmetatable({}, {__mode = "v"})
    self._horizontal_enabled = true
    self._horizontal_align = UIAlign.LEFT
    self._vertical_enabled = true
    self._vertical_align = UIAlign.BOTTOM
    self._touch_count = 0
    self._scrolling = false
    self.rebound_enabled = true -- 回弹
    self.max_vel = 4500
    self.min_vel = 400
    self.elapse_time = 1
    self.validate_threshold = function (which, rawvalue, newvalue)
        return newvalue
    end

    self.scale_enabled = false
    self.max_scale = 2
    self.min_scale = 1
    self.scale_point = {x = 0, y = 0}
end

function ScrollImpl:zoom(x, y, delta_dis)
    if not self.scale_enabled then
        self:_abort_all_focuses()
        return
    end

    local len = math.sqrt(self._target.width * self._target.width,
        self._target.height * self._target.height)
    local scale_x = self._container.scale_x
    local scale = scale_x + 3 * delta_dis * math.max(scale_x, 1) / len
    local scale = math.min(self.max_scale, 
        math.max(self:calc_min_scale(), scale))
    self:scale_to(scale, x, y)
    self._target:dispatch_event(TouchEvent.ZOOMING, scale)
end

function ScrollImpl:calc_min_scale()
    return math.max(self.min_scale, 
        self._target.width / self._container.width,
        self._target.height / self._container.height)
end

function ScrollImpl:scale_to(scale, x, y)
    local lx, ly = self._container:global_to_local(
        self._target:local_to_global(x, y))
    self._container.scale_x = scale
    self._container.scale_y = scale
    self.scale_point.x = x
    self.scale_point.y = y

    local nx, ny = self._target:global_to_local(
        self._container:local_to_global(lx, ly))
    self._container.x = self._container.x + x - nx
    self._container.y = self._container.y + y - ny
    self:pan(0, 0)
end

function ScrollImpl:press(id, x, y)
    self._container:unschedule_update()
    self:_try_focus(id, x, y)

    self:_check_scroll_end()

    self._touch_count = self._touch_count + 1
    if self._touch_count == 1 then
        self._target:dispatch_event(TouchEvent.SCROLL_BEGIN)
    end
end

function ScrollImpl:_check_scroll_end()
    if self._touch_count <= 0 and self._scrolling then
        self._target:dispatch_event(TouchEvent.SCROLL_END)
        self._scrolling = false
        self._touch_count = 0
    end
end

function ScrollImpl:release(id, x, y)
    self:_abort_focus(id)
    self._touch_count = self._touch_count - 1
    self:_check_scroll_end()
end

function ScrollImpl:_try_focus(id, x, y)
    local x, y = self._target:local_to_global(x, y)
    local hit, capture_points = self._container:hit({
        [id] = {x = x, y = y, id = id}})
    if hit then 
        self._focuses[id] = hit
        self._focuses[id]:touch_down(capture_points)
    end
end

function ScrollImpl:_abort_focus(id)
    local focus = self._focuses[id]
    if focus then
        if focus.cobj then
            focus:touch_cancel(focus.touches)
        end
        self._focuses[id] = nil
    end
end

function ScrollImpl:_abort_all_focuses()
    for id, focus in pairs(self._focuses) do
        self:_abort_focus(id)
    end
end

function ScrollImpl:tap(id, x, y)
    -- assert(self._focuses[id]) ?
    local focus = self._focuses[id]
    if focus and focus.cobj then
        focus:touch_up(focus.touches)
        self._focuses[id] = nil
        self._touch_count = self._touch_count - 1
        self:_check_scroll_end()
    end
end

function ScrollImpl:pan(delta_x, delta_y)
    self:_abort_all_focuses()

    local target = self._target
    local left, right, top, bottom = target:get_scroll_bounds()
    local x, y = self._container:get_position()
    local width, height = right - left, top - bottom

    if self._horizontal_enabled then
        -- 如果左边界或右边界在可视范围，拖动距离应缩减
        if left > 0 or right < target.width then
            delta_x = delta_x * 0.3
        end

        -- 不需要回弹
        if not self.rebound_enabled then
            if left + delta_x > 0 then
                delta_x = 0 - left
            elseif right + delta_x < target.width then
                delta_x = target.width - right
            end
        end

        x = x + delta_x
    end

    if self._vertical_enabled then
        -- 如果上边界或下边界在可视范围，拖动距离应缩减
        if bottom > 0 or top < target.height then
            delta_y = delta_y * 0.3
        end

        -- 不需要回弹
        if not self.rebound_enabled then
            if bottom + delta_y > 0 then
                delta_y = 0 - bottom
            elseif top + delta_y < target.height then
                delta_y = target.height - top
            end
        end

        y = y + delta_y
    end

    self._container:set_position(x, y)

    self._scrolling = true
    self._target:dispatch_event(TouchEvent.SCROLLING)
end

function ScrollImpl:fling(vel_x, vel_y)
    self._touch_count = self._touch_count - 1
    self:_abort_all_focuses()

    local target = self._target
    local left, right, top, bottom = target:get_scroll_bounds()
    local MAX, MIN = self.max_vel, self.min_vel

    -- time, factor, duration
    local tx, fx, dx = 0, 1, self.elapse_time
    local ty, fy, dy = 0, 1, self.elapse_time

    vel_x = math.abs(vel_x) < 100 and 0 or vel_x
    vel_y = math.abs(vel_y) < 100 and 0 or vel_y

    if self._horizontal_enabled and vel_x ~= 0 then
        local factor = (left > 0 or right < target.width) and 0.5 or 1
        local dir = vel_x < 0 and -1 or 1
        vel_x = math.min(MAX, math.max(MIN, math.abs(vel_x))) * dir * factor
        dx = dx * factor
    else
        vel_x = 0
    end

    if self._vertical_enabled and vel_y ~= 0 then
        local factor = (bottom > 0 or top < target.height) and 0.5 or 1
        local dir = vel_y < 0 and -1 or 1
        vel_y = math.min(MAX, math.max(MIN, math.abs(vel_y))) * dir * factor
        dy = dy * factor
    else
        vel_y = 0
    end

    local function equal(x1, x2)
        local diff = x1 - x2
        return diff < 0.1 and diff > -0.1
    end

    self._container:schedule_update(function (delta)
        local x, y = self._container:get_position()
        local last_x, last_y = x, y

        tx = tx + delta * fx
        ty = ty + delta * fy

        -- 衰减函数，参考ease族函数
        local vx = vel_x * (1 - math.sin(math.min(1, tx / dx) * PI_2))
        local vy = vel_y * (1 - math.sin(math.min(1, ty / dy) * PI_2))

        -- 逼近目标
        x = x + vx * delta
        y = y + vy * delta

        local tox = self:_validate_x(x, self._horizontal_enabled)
        local toy = self:_validate_y(y, self._vertical_enabled)

        -- 如果有效目标与计算目标不一致，表明有一边已经在可视范围内
        -- 这种情况，加速衰减
        fx = equal(tox, x) and fx or 5
        fy = equal(toy, y) and fy or 5

        -- 回弹
        x = math.abs(vx) < 20 and (x + (tox - x) * delta * 10) or x
        y = math.abs(vy) < 20 and (y + (toy - y) * delta * 10) or y

        self._container:set_position(x, y)

        if not self.rebound_enabled then
            self:validate()
        end

        if equal(x, last_x) and equal(y, last_y) then
            self._container:unschedule_update()
            self:_check_scroll_end()
        else
            self._target:dispatch_event(TouchEvent.SCROLLING)
        end
    end)
end

function ScrollImpl:validate()
    local target = self._target
    local left, right, top, bottom = target:get_scroll_bounds()
    local x, y = self._container:get_position()

    if left > 0 or right < target.width then
        x = self:_validate_x(x, true)
    end

    if bottom > 0 or top < target.height then
        y = self:_validate_y(y, true)
    end

    self._container:set_position(x, y)

    LayoutManager:remove_update(self)
end

function ScrollImpl:_validate_x(value, force)
    if not force then
        return value
    end

    local target = self._target
    local left, right, top, bottom = target:get_scroll_bounds()
    local x, y = self._container:get_position()
    local width = right - left

    if self._horizontal_align == UIAlign.LEFT then
        if left > 0 or width < target.width then
            value = self.validate_threshold("L", value, x + (0 - left))
        elseif right < target.width then
            value = self.validate_threshold("R", value, 
                x + (target.width - right))
        end
    else
        if right < target.width or width < target.width then
            value = self.validate_threshold("R", value,
                x + (target.width - right))
        elseif left > 0 then
            value = self.validate_threshold("L", value, x + (0 - left))
        end
    end

    return value
end

function ScrollImpl:_validate_y(value, force)
    if not force then
        return value
    end

    local target = self._target
    local left, right, top, bottom = target:get_scroll_bounds()
    local x, y = self._container:get_position()
    local height = top - bottom

    if self._vertical_align == UIAlign.BOTTOM then
        if bottom > 0 or height < target.height then
            value = self.validate_threshold("B", value, y + (0 - bottom))
        elseif top < target.height then
            value = self.validate_threshold("T", value, 
                y + (target.height - top))
        end
    else
        if top < target.height or height < target.height then
            value = self.validate_threshold("T", value,
                y + (target.height - top))
        elseif bottom > 0 then
            value = self.validate_threshold("B", value, y + (0 - bottom))
        end
    end

    return value
end

function ScrollImpl:update()
    if self._target and self._target.cobj then
        self:validate()
    end
end

function ScrollImpl:validate_later()
    LayoutManager:add_update(self)
end

function ScrollImpl.Get:horizontal_enabled()
    return self._horizontal_enabled
end
function ScrollImpl.Set:horizontal_enabled(value)
    self._horizontal_enabled = value
    self:validate_later()
end

function ScrollImpl.Get:vertical_enabled()
    return self._vertical_enabled
end
function ScrollImpl.Set:vertical_enabled(value)
    self._vertical_enabled = value
    self:validate_later()
end

function ScrollImpl.Get:horizontal_align()
    return self._horizontal_align
end
function ScrollImpl.Set:horizontal_align(value)
    self._horizontal_align = value
    self:validate_later()
end

function ScrollImpl.Get:vertical_align()
    return self._vertical_align
end
function ScrollImpl.Set:vertical_align(value)
    self._vertical_align = value
    self:validate_later()
end

return ScrollImpl
