--
-- $id: Task.lua O $
--

local class             = require "xgame.class"
local Event             = require "xgame.Event"
local EventDispatcher   = require "xgame.EventDispatcher"

local Task = class("Task", EventDispatcher)

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
    self:dispatch_event(Event.COMPLETE)
end

return Task
