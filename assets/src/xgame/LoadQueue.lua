local class         = require "xgame.class"
local Event         = require "xgame.event.Event"
local downloader    = require "xgame.downloader"
local Dispatcher    = require "xgame.Dispatcher"
local LoadTask      = require "xgame.LoadTask"

local LoadQueue = class("LoadQueue", Dispatcher)

function LoadQueue:ctor(assets)
    self._loadTasks = {}
    self.totalCount = 0
    self.currentCount = 0

    for path in pairs(assets) do
        assert(type(path) == "string", "not a path")
        local task = LoadTask.new(path)
        if downloader.shouldDownload(task) then
            task:addListener(Event.COMPLETE, self._complete, self)
            task:addListener(Event.IOERROR, self._ioerror, self)
            self._loadTasks[task.url] = task
            self.totalCount = self.totalCount + 1
        end
    end
end

function LoadQueue:start()
    if not next(self._loadTasks) then
        self:dispatch(Event.COMPLETE)
    else
        for _, task in pairs(self._loadTasks) do
            task:start()
        end
    end
end

function LoadQueue:_ioerror(task)
    self:dispatch(Event.IOERROR, task)
end

function LoadQueue:retry()
    for _, task in pairs(self._loadTasks) do
        if not task.running then
            task:start()
        end
    end
end

function LoadQueue:_complete(task)
    task:removeListener(Event.COMPLETE, self._complete, self)
    task:removeListener(Event.IOERROR, self._ioerror, self)
    self._loadTasks[task.url] = nil
    self.currentCount = self.currentCount + 1
    self:dispatch(Event.PROGRESS)
    if not next(self._loadTasks) then
        self:dispatch(Event.COMPLETE)
    end
end

return LoadQueue