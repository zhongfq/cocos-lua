--
-- $id: LayoutManager.lua O $
--

local class = require "xgame.class"
local Event = require "xgame.event.Event"

local LayoutManager = class("LayoutManager")

local assert = assert
local next = next
local table = table

function LayoutManager:ctor()
    self._running = false
    self:_reset()
end

function LayoutManager:_reset()
    local units = self._execution_units
    self._execution_units = setmetatable({}, {__mode = "k"})
    return units
end

function LayoutManager:_update(try_times)
    if try_times > 0 and next(self._execution_units) then
        local units = self:_reset()
        for target, _ in pairs(units) do
            target:update()
        end
        self:_update(try_times - 1)
    end
end

function LayoutManager:add_update(target)
    assert(target.update, "no update function")
    if not self._running then
        self._running = true
        xGame:add_event_listener(Event.AFTER_UPDATE, function ()
            self:_update(3)
        end)
    end
    if not self._execution_units[target] then
        self._execution_units[target] = true
    end
end

function LayoutManager:remove_update(target)
    if self._execution_units[target] then
        self._execution_units[target] = nil
    end
end

return LayoutManager.new()
