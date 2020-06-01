local class         = require "xgame.class"
local audio         = require "xgame.audio"
local TouchEvent    = require "xgame.event.TouchEvent"
local Dispatcher    = require "xgame.event.Dispatcher"

local pairs = pairs

local UIObject = class("UIObject", Dispatcher)

function UIObject:ctor()
    self.touchable = false
    self.touchChildren = false
    self.touchPreemptive = false
    self.preemptiveImpact = 1
    self.touches = {}
    self.multiTouch = false
    self.numTouches = 0
    self.clickedSound = false
    self._buttonMode = false
    self.ctype = "<unknown>"
end

function UIObject.Get:buttonMode()
    return self._buttonMode
end

function UIObject.Set:buttonMode(value)
    self._buttonMode = value
    self.touchChildren = not value
    self.touchable = value
end

function UIObject:getBounds(target)
    error(string.format("'%s' must implement", self.classname))
end

function UIObject:localToGlobal(x, y)
    error(string.format("'%s' must implement", self.classname))
end

function UIObject:globalToLocal(x, y)
    error(string.format("'%s' must implement", self.classname))
end

function UIObject:boundsTest(x, y)
    local left, right, top, bottom = self:getBounds(self)
    return not (x < left or x > right or y < top or y > bottom)
end

function UIObject:hit(points)
    local capturePoints
    local numTouches = self.numTouches
    local accept = self.multiTouch and 5 or 1

    for id, value in pairs(points) do
        local x, y = self:globalToLocal(value.x, value.y)
        if (self.hitTest or self.boundsTest)(self, x, y) then
            points[id] = nil
            if numTouches < accept then
                numTouches = numTouches + 1
                capturePoints = capturePoints or {}
                capturePoints[id] = value
                value.x = x
                value.y = y
            end
        end
    end

    if capturePoints then
        return self, capturePoints
    else
        return nil, nil
    end
end

function UIObject:touchDown(points)
    local numTouches = self.numTouches
    for id, value in pairs(points) do
        self.touches[id] = value
        numTouches = numTouches + 1
    end
    self.numTouches = numTouches
    self:dispatch(TouchEvent.TOUCH_DOWN, points)
end

function UIObject:touchMove(points)
    self:dispatch(TouchEvent.TOUCH_MOVE, points)
end

function UIObject:_internalClick()
end

function UIObject:touchUp(points)
    local numTouches = self.numTouches
    local hasHit

    if numTouches <= 0 then
        return
    end

    for id, value in pairs(points) do
        hasHit = hasHit or self:boundsTest(value.x, value.y)
        numTouches = numTouches - 1
        value.hit = hasHit
        self.touches[id] = nil
    end

    self.numTouches = math.max(numTouches, 0)
    self:dispatch(TouchEvent.TOUCH_UP, points)

    if hasHit and numTouches <= 0 then
        if self.clickedSound then
            audio.play(self.clickedSound)
        end
        self:_internalClick()
        self:dispatch(TouchEvent.CLICK)
    end
end

return UIObject