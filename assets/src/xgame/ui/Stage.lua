--
-- $id: Stage.lua O $
--

local class         = require "xgame.class"
local util          = require "xgame.util"
local Event         = require "xgame.Event"
local KeyboardEvent = require "xgame.KeyboardEvent"
local UILayer       = require "xgame.display.UILayer"
local window        = require "kernel.window"

local trace = util.trace("[Stage]")
local ipairs, pairs = ipairs, pairs
local next = next

local Stage = class("Stage", UILayer)

function Stage:ctor()
    self.name = "stage"
    self._stage = self
    self._focus = false
    self._track_points = {}
    self:update_bounds()
    self:init_input()
end

function Stage:update_bounds()
    local left, right, top, bottom = window.get_visible_bounds()
    self.x = left
    self.y = bottom
    self.width = right - left
    self.height = top - bottom
end

function Stage:get_bounds()
    return 0, self.width, self.height, 0
end

function Stage:init_input()
    local function to_tables(rawpoints)
        local points = {}
        for _, touch in ipairs(rawpoints) do
            local id = touch:getId()
            local p = touch:getLocation()
            local x, y = window.convert_to_camera_space(p.x, p.y)
            points[id] = {x = x, y = y, id = id}
        end
        return points
    end

    local function on_touches_began(points, event)
        return self:touch_down(to_tables(points))
    end

    local function on_touches_moved(points, event)
        return self:touch_move(to_tables(points))
    end

    local function on_touches_ended(points, event)
        return self:touch_up(to_tables(points))
    end

    local function on_touches_cancelled(points, event)
        return self:touch_cancel(to_tables(points))
    end

    local eventDispatcher = self.cobj:getEventDispatcher()

    local listener = cc.EventListenerTouchAllAtOnce:create()
    listener:registerScriptHandler(on_touches_began, cc.Handler.EVENT_TOUCHES_BEGAN)
    listener:registerScriptHandler(on_touches_moved, cc.Handler.EVENT_TOUCHES_MOVED)
    listener:registerScriptHandler(on_touches_ended, cc.Handler.EVENT_TOUCHES_ENDED)
    listener:registerScriptHandler(on_touches_cancelled, cc.Handler.EVENT_TOUCHES_CANCELLED)
    eventDispatcher:addEventListenerWithSceneGraphPriority(listener, self.cobj)

    local function on_key_pressed(keycode)
        self:dispatch_event(KeyboardEvent.KEY_DOWN, keycode)
    end

    local function on_key_released(keycode)
        self:dispatch_event(KeyboardEvent.KEY_UP, keycode)
    end

    local listener = cc.EventListenerKeyboard:create()
    listener:registerScriptHandler(on_key_pressed, cc.Handler.EVENT_KEYBOARD_PRESSED)
    listener:registerScriptHandler(on_key_released, cc.Handler.EVENT_KEYBOARD_RELEASED)
    eventDispatcher:addEventListenerWithSceneGraphPriority(listener, self.cobj)
end

function Stage:finish_touch()
    for id, target in pairs(self._track_points) do
        if target.cobj then
            local capture_points = {[id] = {x = 0, y = 0, id = id}}
            xpcall(target.touch_cancel, __TRACEBACK__, target, capture_points)
        end
    end
    self._track_points = {}
end

function Stage:touch_down(points)
    while true and next(points) do
        local target, capture_points = self:hit(points)
        if target and target.cobj then
            for id, _ in pairs(capture_points) do
                self._track_points[id] = target
            end
            self.focus = target
            xpcall(target.touch_down, __TRACEBACK__, target, capture_points)
        else
            break
        end
    end
    return true
end

function Stage:touch_move(points)
    while true and next(points) do
        local capture_points = {}
        local target
        for id, touch in pairs(points) do
            local obj = self._track_points[id]
            if obj and obj.cobj and (not target or target == obj) then
                local x, y = obj:global_to_local(touch.x, touch.y)
                target = obj
                capture_points[id] = {x = x, y = y, id = id}
                points[id] = nil
            end
            if not obj or not obj.cobj then
                points[id] = nil
            end
        end

        if target and target.cobj then
            xpcall(target.touch_move, __TRACEBACK__, target, capture_points)
        end

        if not next(points) then
            break
        end
    end
    return true
end

function Stage:touch_up(points)
    while true and next(points) do
        local capture_points = {}
        local target
        for id, touch in pairs(points) do
            local obj = self._track_points[id]
            if obj and obj.cobj and (not target or target == obj) then
                local x, y = obj:global_to_local(touch.x, touch.y)
                target = obj
                capture_points[id] = {x = x, y = y, id = id}
                points[id] = nil
                self._track_points[id] = nil
            end

            if not obj or not obj.cobj then
                points[id] = nil
            end
        end

        if target and target.cobj then
            xpcall(target.touch_up, __TRACEBACK__, target, capture_points)
        end

        if not next(points) then
            break
        end
    end

    return true
end

function Stage:touch_cancel(points)
    while true and next(points) do
        local capture_points = {}
        local target
        for id, touch in pairs(points) do
            local obj = self._track_points[id]
            if obj and obj.cobj and (not target or target == obj) then
                local x, y = obj:global_to_local(touch.x, touch.y)
                target = obj
                capture_points[id] = {x = x, y = y, id = id}
                points[id] = nil
                self._track_points[id] = nil
            end

            if not obj then
                points[id] = nil
            end
        end

        if target and target.cobj then
            xpcall(target.touch_cancel, __TRACEBACK__, target, capture_points)
        end

        if not next(points) then
            break
        end
    end

    return true
end

--
-- Setter Getter
--
function Stage.Get:focus() return self._focus end
function Stage.Set:focus(value)
    if self._focus ~= value then
        if self._focus then
            self._focus:dispatch_event(Event.FOCUS_OUT)
        end

        self._focus = value

        if value then
            value:dispatch_event(Event.FOCUS_IN)
        end
    end
end

return Stage
