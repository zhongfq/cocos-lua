local class         = require "xgame.class"
local Dispatcher    = require "xgame.Dispatcher"
local EventAgent    = require "xgame.event.EventAgent"

local Service = class('Service', Dispatcher)

function Service:ctor(name)
    self.name = name
    self._eventAgent = EventAgent.new()
end

function Service:__call(target, priority)
    return self._eventAgent:wrap(target, priority)
end

function Service:dispose()
    self.dispose = true
    self._eventAgent:clear()
end

return Service
