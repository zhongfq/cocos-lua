local class         = require "cclua.class"
local filesystem    = require "cclua.filesystem"
local downloader    = require "cclua.downloader"
local Event         = require "cclua.Event"
local Dispatcher    = require "cclua.Dispatcher"

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