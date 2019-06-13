local class         = require "xgame.class"
local TouchEvent    = require "xgame.event.TouchEvent"

local math = math
local assert = assert
local ipairs, pairs, next = ipairs, pairs, next

local PointTracker = nil

local GestureDetector = class("GestureDetector")

function GestureDetector:ctor(target, delegate, tap_square, max_fling_delay)
    self._trackers = {}
    self._target = target
    self._delegate = delegate
    self._tap_square = tap_square or 20
    self._last_zoom_time = 0
    self._max_fling_delay = max_fling_delay or 0.08

    target:addListener(TouchEvent.TOUCH_DOWN, self._touch_down, self)
    target:addListener(TouchEvent.TOUCH_MOVE, self._touch_move, self)
    target:addListener(TouchEvent.TOUCH_UP, self._touch_up, self)
end

function GestureDetector:_create_tracker(id)
    -- assert(not self._trackers[id])
    local tracker = PointTracker.new()
    self._trackers[id] = tracker
    return tracker
end

function GestureDetector:_touch_down(_, points)
    for id, p in pairs(points) do
        local tracker = self:_create_tracker(id)
        tracker.id = id
        tracker.start_x = p.x
        tracker.start_y = p.y
        tracker.start_time = xGame.time 
        tracker:start(p.x, p.y, xGame.time)
        self._delegate:press(id, p.x, p.y)
    end
end

local function math_sqrt2(x, y)
    return math.sqrt(x * x + y * y)
end

function GestureDetector:_touch_move(_, points)
    for id, p in pairs(points) do
        local tracker = assert(self._trackers[id], id)
        tracker:update(p.x, p.y, xGame.time)
        if tracker.tap_enabled then
            local dx = math.abs(p.x - tracker.start_x)
            local dy = math.abs(p.y - tracker.start_y)
            if dx >= self._tap_square or dy >= self._tap_square then
                tracker.tap_enabled = false
            end
        end
    end

    local id1, trk1 = next(self._trackers)
    local id2, trk2 = next(self._trackers, id1)

    if not id2 then
        id2 = id1
        trk2 = trk1
    end

    local last_x1 = trk1.x - trk1.delta_x
    local last_y1 = trk1.y - trk1.delta_y
    local last_x2 = trk2.x - trk2.delta_x
    local last_y2 = trk2.y - trk2.delta_y
    local last_dis = math_sqrt2(last_x1 - last_x2, last_y1 - last_y2)
    local curr_dis = math_sqrt2(trk1.x - trk2.x, trk1.y - trk2.y)

    if last_dis ~= curr_dis then
        self._last_zoom_time = xGame.time
        self._delegate:zoom((last_x1 + last_x2) / 2, (last_y1 + last_y2) / 2,
            curr_dis - last_dis)
    end

    if not trk1.tap_enabled and not trk2.tap_enabled then
        self._delegate:pan((trk1.delta_x + trk2.delta_x) / 2,
            (trk1.delta_y + trk2.delta_y) / 2)
    end
end

function GestureDetector:_touch_up(_, points)
    local last

    for id, p in pairs(points) do
        local tracker = assert(self._trackers[id], id)
        if tracker.tap_enabled then
            local dx = math.abs(p.x - tracker.start_x)
            local dy = math.abs(p.y - tracker.start_y)
            if dx >= self._tap_square or dy >= self._tap_square then
                tracker.tap_enabled = false
            end
        end


        if not last then
            last = tracker
        else
            self._delegate:release(id, p.x, p.y)
        end

        self._trackers[id] = nil
    end

    if not next(self._trackers) then
        local dt = xGame.time - last.timestamp
        if last.tap_enabled then
            self._delegate:tap(last.id, last.x, last.y)
        elseif dt < self._max_fling_delay 
            and xGame.time - self._last_zoom_time > 0.2 then
            self._delegate:fling(last:calc_vel())
        else
            -- self._delegate:release(last.id, last.x, last.y)
            self._delegate:fling(0, 0)
        end
    end
end

--
-- PointTracker
--
PointTracker = class("PointTracker")

function PointTracker:ctor()
    self.id = -1
    self.start_x = 0
    self.start_y = 0
    self.start_time = 0
    self.tap_enabled = true
    self.x = 0
    self.y = 0
    self.timestamp = 0
    self.delta_x = 0
    self.delta_y = 0
    self.delta_time = 0
    self.sample_size = 4
    self.num_samples = 0
    self.x_samples = {}
    self.y_samples = {}
    self.time_samples = {}
end

function PointTracker:start(x, y, timestamp)
    self.x = x
    self.y = y
    self.timestamp = timestamp
    self.delta_x = 0
    self.delta_y = 0
    self.delta_time = 0
    self.num_samples = 0
end

function PointTracker:update(x, y, timestamp)
    local idx = self.num_samples % self.sample_size + 1

    self.delta_x = x - self.x
    self.delta_y = y - self.y
    self.delta_time = timestamp - self.timestamp

    self.x_samples[idx] = self.delta_x
    self.y_samples[idx] = self.delta_y
    self.time_samples[idx] = self.delta_time
    self.num_samples = self.num_samples + 1

    self.x = x
    self.y = y
    self.timestamp = timestamp
end

function PointTracker:calc_samples(samples)
    local num_samples = math.min(self.num_samples, self.sample_size) 
    local sum = 0
    for _, v in ipairs(samples) do
        sum = sum + v
    end
    return num_samples > 0 and (sum / num_samples) or 0
end

function PointTracker:calc_vel()
    local x = self:calc_samples(self.x_samples)
    local y = self:calc_samples(self.y_samples)
    local time = self:calc_samples(self.time_samples)

    if time > 0 then
        return x / time, y / time
    else
        return 0, 0
    end
end

return GestureDetector
