local class         = require "xgame.class"
local Event         = require "xgame.event.Event"
local Dispatcher    = require "xgame.event.Dispatcher"

local Task = class("Task", Dispatcher)

function Task:ctor(name)
    self.name = name or "<unknow task>"
    self.root = false
end

function Task:prepare()
end

function Task:start()
end

function Task:stop()
end

function Task:complete()
    self:dispatch(Event.COMPLETE)
end

return Task
