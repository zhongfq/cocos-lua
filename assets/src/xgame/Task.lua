local class = require "xgame.class"
local Event = require "xgame.Event"

local Task = class("Task", require("xgame.EventDispatcher"))

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
