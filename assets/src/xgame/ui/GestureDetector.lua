local class         = require "xgame.class"
local runtime       = require "xgame.runtime"
local TouchEvent    = require "xgame.event.TouchEvent"

local math = math
local assert = assert
local ipairs, pairs, next = ipairs, pairs, next

local TouchTracker = nil

local GestureDetector = class("GestureDetector")

function GestureDetector:ctor(target, delegate, tapSquare, maxFlingDelay)
    self._trackers = {}
    self._target = target
    self._delegate = delegate
    self._tapSquare = tapSquare or 20
    self._lastZoomTime = 0
    self._valid = true
    self._maxFlingDelay = maxFlingDelay or 0.08

    target:addListener(TouchEvent.TOUCH_DOWN, self._touchDown, self)
    target:addListener(TouchEvent.TOUCH_MOVE, self._touchMove, self)
    target:addListener(TouchEvent.TOUCH_UP, self._touchUp, self)
end

function GestureDetector:_createTracker(id)
    -- assert(not self._trackers[id])
    local tracker = TouchTracker.new()
    self._trackers[id] = tracker
    return tracker
end

function GestureDetector:invalidate()
    self._valid = false
end

function GestureDetector:getTracker(id)
    return assert(self._trackers[id], id)
end

function GestureDetector:_touchDown(_, points)
    self._valid = true
    for id, p in pairs(points) do
        local tracker = self:_createTracker(id)
        tracker.id = id
        tracker.startX = p.x
        tracker.startY = p.y
        tracker.startTime = runtime.time
        tracker:start(p.x, p.y, runtime.time)
        self._delegate:press(id, p.x, p.y)
    end
end

local function mathSqrt2(x, y)
    return math.sqrt(x * x + y * y)
end

function GestureDetector:_touchMove(_, points)
    for id, p in pairs(points) do
        local tracker = assert(self._trackers[id], id)
        tracker:update(p.x, p.y, runtime.time)
        if tracker.tapEnabled then
            local dx = math.abs(p.x - tracker.startX)
            local dy = math.abs(p.y - tracker.startY)
            if dx >= self._tapSquare or dy >= self._tapSquare then
                tracker.tapEnabled = false
            end
        end
    end

    local id1, trk1 = next(self._trackers)
    local id2, trk2 = next(self._trackers, id1)

    if not id2 then
        id2 = id1
        trk2 = trk1
    end

    local lastX1 = trk1.x - trk1.deltaX
    local lastY1 = trk1.y - trk1.deltaY
    local lastX2 = trk2.x - trk2.deltaX
    local lastY2 = trk2.y - trk2.deltaY
    local lastDis = mathSqrt2(lastX1 - lastX2, lastY1 - lastY2)
    local currDis = mathSqrt2(trk1.x - trk2.x, trk1.y - trk2.y)

    if lastDis ~= currDis then
        self._lastZoomTime = runtime.time
        self._delegate:zoom(
            (lastX1 + lastX2) / 2,
            (lastY1 + lastY2) / 2,
            currDis - lastDis
        )
    end

    if not trk1.tapEnabled and not trk2.tapEnabled then
        self._delegate:pan(
            (trk1.deltaX + trk2.deltaX) / 2,
            (trk1.deltaY + trk2.deltaY) / 2
        )
    end
end

function GestureDetector:_touchUp(_, points)
    local last

    for id, p in pairs(points) do
        local tracker = assert(self._trackers[id], id)
        if tracker.tapEnabled then
            local dx = math.abs(p.x - tracker.startX)
            local dy = math.abs(p.y - tracker.startY)
            if dx >= self._tapSquare or dy >= self._tapSquare then
                tracker.tapEnabled = false
            end
        end


        if not last then
            last = tracker
        else
            self._delegate:release(id, p.x, p.y)
        end

        self._trackers[id] = nil
    end

    if not self._valid then
        return
    end

    if not next(self._trackers) then
        local dt = runtime.time - last.timestamp
        if last.tapEnabled then
            self._delegate:tap(last.id, last.x, last.y)
        elseif dt < self._maxFlingDelay
            and runtime.time - self._lastZoomTime > 0.2 then
            self._delegate:fling(last:calcVel())
        else
            -- self._delegate:release(last.id, last.x, last.y)
            self._delegate:fling(0, 0)
        end
    end
end

--
-- TouchTracker
--
TouchTracker = class("TouchTracker")

function TouchTracker:ctor()
    self.id = -1
    self.startX = 0
    self.startY = 0
    self.startTime = 0
    self.tapEnabled = true
    self.x = 0
    self.y = 0
    self.timestamp = 0
    self.deltaX = 0
    self.deltaY = 0
    self.deltaTime = 0
    self.sampleSize = 4
    self.numSamples = 0
    self.xSamples = {}
    self.ySamples = {}
    self.timeSamples = {}
end

function TouchTracker:start(x, y, timestamp)
    self.x = x
    self.y = y
    self.timestamp = timestamp
    self.deltaX = 0
    self.deltaY = 0
    self.deltaTime = 0
    self.numSamples = 0
end

function TouchTracker:update(x, y, timestamp)
    local idx = self.numSamples % self.sampleSize + 1

    self.deltaX = x - self.x
    self.deltaY = y - self.y
    self.deltaTime = timestamp - self.timestamp

    self.xSamples[idx] = self.deltaX
    self.ySamples[idx] = self.deltaY
    self.timeSamples[idx] = self.deltaTime
    self.numSamples = self.numSamples + 1

    self.x = x
    self.y = y
    self.timestamp = timestamp
end

function TouchTracker:calcSamples(samples)
    local numSamples = math.min(self.numSamples, self.sampleSize)
    local sum = 0
    for _, v in ipairs(samples) do
        sum = sum + v
    end
    return numSamples > 0 and (sum / numSamples) or 0
end

function TouchTracker:calcVel()
    local x = self:calcSamples(self.xSamples)
    local y = self:calcSamples(self.ySamples)
    local time = self:calcSamples(self.timeSamples)

    if time > 0 then
        return x / time, y / time
    else
        return 0, 0
    end
end

return GestureDetector
