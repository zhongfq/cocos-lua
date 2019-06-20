local class         = require "xgame.class"
local DisplayObject = require "xgame.swf.DisplayObject"

local TextField = class("TextField", DisplayObject)

function TextField:ctor(cobj)
end

function TextField.Get:plainText()
    local value = self.cobj.text or ""
    value = string.gsub(value, "<[^>]*>", "")
    return value
end

function TextField.Get:text() return self.cobj.text or "" end
function TextField.Set:text(value)
    self.cobj.text = value
end

function TextField.Get:color() return self.cobj.color end
function TextField.Set:color(value)
    self.cobj.color = value
end

function TextField.Get:fontSize() return self.cobj.fontSize end
function TextField.Set:fontSize(value)
    self.cobj.fontSize = value
end

function TextField.Get:fontName() return self.cobj.fontName end
function TextField.Set:fontName(value)
    self.cobj.fontName = value
end

function TextField.Get:displayAsPassword()
    return self.cobj.displayAsPassword
end
function TextField.Set:displayAsPassword(value)
    self.cobj.displayAsPassword = value
end

function TextField.Get:multiline() return self.cobj.multiline end
function TextField.Set:multiline(value)
    self.cobj.multiline = value
end

function TextField.Get:wordWrap() return self.cobj.wordWrap end
function TextField.Set:wordWrap(value)
    self.cobj.wordWrap = value
end

function TextField.Get:autoSize() return self.cobj.autoSize end
function TextField.Set:autoSize(value)
    self.cobj.autoSize = value
end

return TextField
