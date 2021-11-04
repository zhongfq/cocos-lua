local class         = require "xgame.class"
local filesystem    = require "xgame.filesystem"
local downloader    = require "xgame.downloader"
local Event         = require "xgame.Event"
local Dispatcher    = require "xgame.Dispatcher"

local LoadTask = class("LoadTask", Dispatcher)

function LoadTask:ctor(uri)
    self.uri = uri
    if filesystem.isRemoteURI(uri) then
        self.path = filesystem.localPath(uri)
    else
        self.path = filesystem.dir.assets .. '/' .. uri
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