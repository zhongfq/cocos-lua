local class         = require "xgame.class"
local Event         = require "xgame.event.Event"
local assetloader   = require "xgame.assetloader"
local LoadTask      = require "xgame.loader.LoadTask"
local DisplayObject = require "xgame.swf.DisplayObject"
local swf           = require "xgame.swf.swf"

local Image = class("Image", DisplayObject)

local _new = Image.new

function Image.new(cobj)
    return _new(cobj or swf.Image.new())
end

function Image:ctor(cobj)
    self._preferredWidth = 0
    self._preferredHeight = 0
end

function Image:_doLoad(url, callback)
    local loader = LoadTask.new(url)
    loader:addListener(Event.COMPLETE, function ()
        callback(loader.path)
    end)
    loader:start()
end

function Image:loadTexture(cocosTexture)
    self.cobj:loadTexture(cocosTexture)
end

function Image:load(filePath)
    self:_doLoad(filePath, function (path)
        assetloader.load(self, {[path] = true})
        self.cobj:load(path)
        self.preferredWidth = self._preferredWidth
        self.preferredHeight = self._preferredHeight
    end)
end

function Image:loadAsync(filePath)
    self:_doLoad(filePath, function (path)
        assetloader.load(self, {[path] = true})
        self.cobj:loadAsync(path, function (success)
            self.preferredWidth = self._preferredWidth
            self.preferredHeight = self._preferredHeight
        end)
    end)
end

function Image.Get:filePath()
    return self.cobj.filePath
end

function Image.Get:preferredWidth() return self._preferredWidth end
function Image.Set:preferredWidth(value)
    self._preferredWidth = value
    if value > 0 and self.width > 0 then
        self.scaleX = 1 -- reset width
        self.scaleX = value / self.width
    end
end

function Image.Get:preferredHeight() return self._preferredHeight end
function Image.Set:preferredHeight(value)
    self._preferredHeight = value
    if value > 0 and self.height > 0 then
        self.scaleY = 1 -- reset height
        self.scaleY = value / self.height
    end
end

return Image
