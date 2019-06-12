local class = require "xgame.class"
local util  = require "xgame.util"
local Event = require "xgame.event.Event"
local Task  = require "xgame.Task"
local Array = require "xgame.Array"

local trace = util.trace("[TaskFlow]")

local TaskFlow = class("TaskFlow", Task)

function TaskFlow:ctor(name)
    self.root = self
    self._tasks = Array.new()
    self._lastRunningTask = false
    self._runningTask = false
    self._currentTask = false
end

function TaskFlow.Get:runningTask()
    return self._runningTask
end

function TaskFlow:pushBack(task)
    self._tasks:pushBack(task)
end

function TaskFlow:pushFront(task)
    self._tasks:pushFront(task)
end

function TaskFlow:findTask(name)
    for _, task in ipairs(self._tasks) do
        if task.name == name then
            return task
        end
    end
end

function TaskFlow:start()
    self:_setupNextTask()
end

function TaskFlow:stop()
    local task = self._currentTask
    if task then
        task:removeListener(Event.COMPLETE, self._taskDone, self)
        task:stop()
        self._currentTask = false
    end
end

function TaskFlow:_setupNextTask()
    if #self._tasks == 0 then
        self:complete()
        return
    end

    local task = self._tasks:shift()
    trace("=> %s start:  %s", self.root.name or "", task.name)
    self._currentTask = task
    self._lastRunningTask = self.root._runningTask
    self.root._runningTask = task
    task.root = self.root
    task:addListener(Event.COMPLETE, self._taskDone, self)
    task:prepare()
    task:start()
end

function TaskFlow:_taskDone(task)
    task:removeListener(Event.COMPLETE, self._taskDone, self)
    self.root._runningTask = self._lastRunningTask
    self:_setupNextTask()
end

return TaskFlow
