local class         = require "xgame.class"
local filesystem    = require "xgame.filesystem"
local downloader    = require "xgame.downloader"
local Event         = require "xgame.event.Event"
local Dispatcher    = require "xgame.Dispatcher"

local LoadTask = class("LoadTask", Dispatcher)

function LoadTask:ctor(url)
    self.url = url
    if string.find(url, '^https?://') then
        self.path = filesystem.localCachePath(url)
    else
        self.path = filesystem.dir.assets .. '/' .. url
    end
end

function LoadTask:start()
    if not self.running then
        self.running = true
        downloader.load(self)
    end
end

function LoadTask:loadSuccess()
    self.running = false
    self:dispatch(Event.COMPLETE)
end

function LoadTask:loadError()
    self.running = false
    self:dispatch(Event.IOERROR)
end

return LoadTask