--
-- $id: TaskFlow.lua O $
--

local class             = require "xgame.class"
local util              = require "xgame.util"
local Event             = require "xgame.Event"
local Task              = require "xgame.Task"
local Array             = require "xgame.Array"
local EventDispatcher   = require "xgame.EventDispatcher"

local trace = util.trace("[TaskFlow]")

local TaskFlow = class("TaskFlow", Task)

function TaskFlow:ctor(name)
    self.root = self
    self._tasks = Array.new()
    self._last_running_task = false
    self._running_task = false
    self._current_task = false
end

function TaskFlow.Get:running_task()
    return self._running_task
end

function TaskFlow:push_back(task)
    self._tasks:push_back(task)
end

function TaskFlow:push_front(task)
    self._tasks:push_front(task)
end

function TaskFlow:find_task(name)
    for _, task in ipairs(self._tasks) do
        if task.name == name then
            return task
        end
    end
end

function TaskFlow:start()
    self:_setup_next_task()
end

function TaskFlow:stop()
    local task = self._current_task
    if task then
        task:remove_event_listener(Event.COMPLETE, self._task_done, self)
        task:stop()
        self._current_task = false
    end
end

function TaskFlow:_setup_next_task()
    if #self._tasks == 0 then
        self:complete()
        return
    end

    local task = self._tasks:shift()
    trace("=> %s start:  %s", self.root.name or "", task.name)
    self._current_task = task
    self._last_running_task = self.root._running_task
    self.root._running_task = task
    task.root = self.root
    task:add_event_listener(Event.COMPLETE, self._task_done, self)
    task:prepare()
    task:start()
end

function TaskFlow:_task_done(task)
    task:remove_event_listener(Event.COMPLETE, self._task_done, self)
    self.root._running_task = self._last_running_task
    self:_setup_next_task()
end

return TaskFlow
