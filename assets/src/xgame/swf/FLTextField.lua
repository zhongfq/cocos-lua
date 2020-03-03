local class             = require "xgame.class"
local FLDisplayObject   = require "xgame.swf.FLDisplayObject"

local FLTextField = class("FLTextField", FLDisplayObject)

function FLTextField:ctor(cobj)
end

function FLTextField.Get:plainText()
    local value = self.cobj.text or ""
    value = string.gsub(value, "<[^>]*>", "")
    return value
end

function FLTextField.Get:text() return self.cobj.text or "" end
function FLTextField.Set:text(value)
    self.cobj.text = value
end

function FLTextField.Get:color() return self.cobj.color end
function FLTextField.Set:color(value)
    self.cobj.color = value
end

function FLTextField.Get:fontSize() return self.cobj.fontSize end
function FLTextField.Set:fontSize(value)
    self.cobj.fontSize = value
end

function FLTextField.Get:fontName() return self.cobj.fontName end
function FLTextField.Set:fontName(value)
    self.cobj.fontName = value
end

function FLTextField.Get:displayAsPassword()
    return self.cobj.displayAsPassword
end
function FLTextField.Set:displayAsPassword(value)
    self.cobj.displayAsPassword = value
end

function FLTextField.Get:multiline() return self.cobj.multiline end
function FLTextField.Set:multiline(value)
    self.cobj.multiline = value
end

function FLTextField.Get:wordWrap() return self.cobj.wordWrap end
function FLTextField.Set:wordWrap(value)
    self.cobj.wordWrap = value
end

function FLTextField.Get:autoSize() return self.cobj.autoSize end
function FLTextField.Set:autoSize(value)
    self.cobj.autoSize = value
end

return FLTextField
