local class             = require "xgame.class"
local DisplayObject     = require "xgame.swf.DisplayObject"

local TextField = class("TextField", DisplayObject)

function TextField:ctor(cobj)
end

function TextField.Get:plain_text()
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

function TextField.Get:font_size() return self.cobj.font_size end
function TextField.Set:font_size(value)
    self.cobj.font_size = value
end

function TextField.Get:font_name() return self.cobj.font_name end
function TextField.Set:font_name() 
    self.cobj.font_name = value 
end

function TextField.Get:display_as_password() 
    return self.cobj.display_as_password
end
function TextField.Set:display_as_password(value) 
    self.cobj.display_as_password = value
end

function TextField.Get:multiline() return self.cobj.multiline end
function TextField.Set:multiline(value) 
    self.cobj.multiline = value 
end

function TextField.Get:word_wrap() return self.cobj.word_wrap end
function TextField.Set:word_wrap(value) 
    self.cobj.word_wrap = value 
end

function TextField.Get:auto_size() return self.cobj.auto_size end
function TextField.Set:auto_size(value) 
    self.cobj.auto_size = value 
end

return TextField
