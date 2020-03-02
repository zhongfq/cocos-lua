local class             = require "xgame.class"
local filesystem        = require "xgame.filesystem"
local Event             = require "xgame.event.Event"
local assetloader       = require "xgame.assetloader"
local LoadTask          = require "xgame.loader.LoadTask"
local swf               = require "xgame.swf.swf"
local FLDisplayObject   = require "xgame.swf.FLDisplayObject"

local FLImage = class("FLImage", FLDisplayObject)

local _new = FLImage.new

function FLImage.new(cobj)
    return _new(cobj or swf.Image.new())
end

function FLImage:ctor(cobj)
    self._preferredWidth = 0
    self._preferredHeight = 0
end

function FLImage:_doLoad(url, callback)
    local loader = LoadTask.new(url)
    loader:addListener(Event.COMPLETE, function ()
        callback(filesystem.localCachePath(url))
    end)
    loader:start()
end

function FLImage:loadTexture(cocosTexture)
    self.cobj:loadTexture(cocosTexture)
end

function FLImage:load(filePath)
    self:_doLoad(filePath, function (path)
        assetloader.load(self, {[path] = true})
        self.cobj:load(path)
        self.preferredWidth = self._preferredWidth
        self.preferredHeight = self._preferredHeight
    end)
end

function FLImage:loadAsync(filePath)
    self:_doLoad(filePath, function (path)
        assetloader.load(self, {[path] = true})
        self.cobj:loadAsync(path, function (success)
            self.preferredWidth = self._preferredWidth
            self.preferredHeight = self._preferredHeight
        end)
    end)
end

function FLImage.Get:filePath()
    return self.cobj.filePath
end

function FLImage.Get:preferredWidth() return self._preferredWidth end
function FLImage.Set:preferredWidth(value)
    self._preferredWidth = value
    if value > 0 and self.width > 0 then
        self.scaleX = 1 -- reset width
        self.scaleX = value / self.width
    end
end

function FLImage.Get:preferredHeight() return self._preferredHeight end
function FLImage.Set:preferredHeight(value)
    self._preferredHeight = value
    if value > 0 and self.height > 0 then
        self.scaleY = 1 -- reset height
        self.scaleY = value / self.height
    end
end

return FLImage
