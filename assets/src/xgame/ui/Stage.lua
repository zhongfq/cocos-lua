local class         = require "xgame.class"
local Event         = require "xgame.event.Event"
local KeyboardEvent = require "xgame.event.KeyboardEvent"
local UILayer       = require "xgame.ui.UILayer"
local window        = require "xgame.window"

local ipairs = ipairs
local pairs = pairs
local xpcall = xpcall
local next = next

local Stage = class("Stage", UILayer)

function Stage:ctor()
    self.name = "stage"
    self._stage = self
    self._focus = false
    self._trackedTouches = {}
    self:_initTouchListener()
    self:_updateBounds()
end

function Stage:_updateBounds()
    local left, right, top, bottom = window.getVisibleBounds()
    self.x = left
    self.y = bottom
    self.width = right - left
    self.height = top - bottom
end

function Stage:getBounds()
    return 0, self.width, self.height, 0
end

function Stage:_initTouchListener()
    local EventListenerTouchAllAtOnce = require "cc.EventListenerTouchAllAtOnce"
    local EventListenerKeyboard = require "cc.EventListenerKeyboard"

    local function convert(rawpoints, event)
        local points = {}
        for _, touch in ipairs(rawpoints) do
            local id = touch.id
            local p = touch.location
            local x, y = window.convertToCameraSpace(p.x, p.y)
            p.x = x
            p.y = y
            p.id = id
            p.touch = touch
            p.event = event
            points[id] = p
        end
        return points
    end

    local function addEventListenerWithSceneGraphPriority(listener)
        local dispatcher = self.cobj.eventDispatcher
        dispatcher:addEventListenerWithSceneGraphPriority(listener, self.cobj)
    end

    -- add touch listener
    local touchListener = EventListenerTouchAllAtOnce.create()
    touchListener.onTouchesBegan = function (touches, event)
        return self:touchDown(convert(touches, event))
    end
    touchListener.onTouchesMoved = function (touches, event)
        return self:touchMove(convert(touches, event))
    end
    touchListener.onTouchesEnded = function (touches, event)
        return self:touchUp(convert(touches, event))
    end
    touchListener.onTouchesCancelled = function (touches, event)
        return self:touchCancel(convert(touches, event))
    end
    addEventListenerWithSceneGraphPriority(touchListener)

    -- add keyboard listener
    local keyboardListener = EventListenerKeyboard.create()
    keyboardListener.onKeyPressed = function (keycode, event)
        self:dispatch(KeyboardEvent.KEY_DOWN, keycode)
    end
    keyboardListener.onKeyReleased = function (keycode, event)
        self:dispatch(KeyboardEvent.KEY_UP, keycode)
    end
    addEventListenerWithSceneGraphPriority(keyboardListener)
end

function Stage:preemptTouch(target, id, x, y)
    x, y = target:globalToLocal(x, y)
    self:touchCancel({[id] = {id = id, x = x, y = y}})
    self._trackedTouches[id] = target
    self.focus = target
    target:touchMove({[id] = {id = id, x = x, y = y}})
end

function Stage:touchDown(points)
    local __TRACEBACK__ = __TRACEBACK__
    while true and next(points) do
        local target, capturePoints = self:hit(points)
        if target then
            for id in pairs(capturePoints) do
                self._trackedTouches[id] = target
            end
            self.focus = target
            xpcall(target.touchDown, __TRACEBACK__, target, capturePoints)
        else
            break
        end
    end
    return true
end

function Stage:touchMove(points)
    local __TRACEBACK__ = __TRACEBACK__
    while true and next(points) do
        local capturePoints = {}
        local target
        for id, p in pairs(points) do
            local obj = self._trackedTouches[id]
            if not obj or not obj.stage then
                points[id] = nil
            elseif not target or target == obj then
                target = obj
                p.x, p.y = obj:globalToLocal(p.x, p.y)
                capturePoints[id] = p
                points[id] = nil
            end
        end

        if target then
            xpcall(target.touchMove, __TRACEBACK__, target, capturePoints)
        end

        if not next(points) then
            break
        end
    end
    return true
end

function Stage:touchUp(points)
    local __TRACEBACK__ = __TRACEBACK__
    while true and next(points) do
        local capturePoints = {}
        local target
        for id, p in pairs(points) do
            local obj = self._trackedTouches[id]
            if not obj or not obj.stage then
                points[id] = nil
            elseif not target or target == obj then
                target = obj
                p.x, p.y = obj:globalToLocal(p.x, p.y)
                capturePoints[id] = p
                points[id] = nil
                self._trackedTouches[id] = nil
            end
        end

        if target then
            xpcall(target.touchUp, __TRACEBACK__, target, capturePoints)
        end

        if not next(points) then
            break
        end
    end
    return true
end

function Stage:touchCancel(points)
    for _, p in pairs(points) do
        p.x = math.maxinteger
        p.y = math.maxinteger
    end
    return self:touchUp(points)
end

function Stage.Get:focus() return self._focus end
function Stage.Set:focus(value)
    if self._focus ~= value then
        if self._focus then
            self._focus:dispatch(Event.FOCUS_OUT)
        end

        self._focus = value

        if value then
            value:dispatch(Event.FOCUS_IN)
        end
    end
end

return Stage
