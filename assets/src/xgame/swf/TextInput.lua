local class         = require "xgame.class"
local Event         = require "xgame.event.Event"
local TouchEvent    = require "xgame.event.TouchEvent"
local UIView        = require "xgame.ui.UIView"
local MovieClip     = require "xgame.swf.MovieClip"
local swf           = require "xgame.swf.swf"
local EditBox       = require "ccui.EditBox"

local CocosInput

local TextInput = swf.class("TextInput", MovieClip)

function TextInput:ctor()
    self._restrict = false
    self._cocosobj = false
    self.label = self.ns['label']
    self.mode = 'NONE'
    self.touchable = true
    self.touchChildren = false
    
    self:addListener(Event.REMOVED, self._onRemoved, self)
    self:addListener(Event.FOCUS_OUT, self._focusOut, self)
    self:addListener(TouchEvent.CLICK, self._focusIn, self)
end

function TextInput:_onRemoved()
    if self._cocosobj then
        self._cocosobj.cobj:unregisterScriptEditBoxHandler()
        self._cocosobj:remove_self()
        self._cocosobj = false
    end
end

function TextInput.Get:mode()
    return self._mode
end

function TextInput.Set:mode(value)
    self._mode = value
    if value == 'PASSWORD' then
        self.label.displayAsPassword = true
        self._input_mode = 1
        self._input_flag = 0
    elseif value == 'ACCOUNT' then
        self.label.displayAsPassword = false
        self._input_mode = 1
        self._input_flag = 5
    else
        self.label.displayAsPassword = false
        self._input_mode = 0
        self._input_flag = 5
    end
end

function TextInput:_create_cocosobj()
    local cocosobj = self._cocosobj
    if not cocosobj then
        cocosobj = CocosInput.new()
        cocosobj.width = self.label.width
        cocosobj.height = self.label.height
        cocosobj:setFontSize(self.label.fontSize)
        cocosobj:addListener(Event.COMPLETE, function ()
            if self.stage and self.stage.focus == self then
                self.stage.focus = false
            else
                self:_focusOut()
            end
            self:dispatch(Event.COMPLETE)
        end)
        cocosobj:addListener(Event.CHANGE, function ()
            self.label.text = self._cocosobj.text
            self:dispatch(Event.CHANGE)
        end)
        self.rootnode.cobj:addChild(cocosobj.cobj, 0xFF)
        self._cocosobj = cocosobj
    end
end

function TextInput:_focusOut()
    if self._cocosobj then
        self._cocosobj.visible = false
        self._cocosobj:closeKeyboard()
        self.label.text = self._cocosobj.text
    end
    self.label.visible = true
end

function TextInput:_focusIn()
    if (self._cocosobj and self._cocosobj.open) or
        not self.rootnode.cobj then
        return
    end

    self.label.visible = false

    self:_create_cocosobj()

    local cocosobj = self._cocosobj
    local x, y = self.label:localToGlobal(
        0,
        self.label.fontSize + (self.label.height - self.label.fontSize) / 2)
    x, y = self.rootnode:globalToLocal(x, y)

    local vbl, vbr, vbt, vbb = swf.visible_bounds()
    local dw, dh = swf.design_size()
    local offset = vbt - (dh - math.abs(vbb - vbt)) / 2
    if xGame.os == "mac" then
        y = y - offset
    else
        y = y + offset
    end

    x, y = self.rootnode:globalToLocal(x, y)
    cocosobj.x = x
    cocosobj.y = y
    cocosobj.restrict = self.restrict
    cocosobj.text = self.label.plain_text
    cocosobj.color = self.label.color
    cocosobj.placeholder = self.placeholder
    cocosobj:setInputMode(self._input_mode)
    cocosobj:setInputFlag(self._input_flag)
    cocosobj:openKeyboard()
end

function TextInput.Get:restrict() return self._restrict end
function TextInput.Set:restrict(value)
    self._restrict = value
end

function TextInput.Get:text()
    if self._cocosobj and self._cocosobj.visible then
        self.label.text = self._cocosobj.text
    end

    return self.label.plainText or ""
end
function TextInput.Set:text(value)
    value = value or ""
    if self._cocosobj then
        self._cocosobj.text = value
    end
    self.label.text = value
end

function TextInput.Get:placeholder()
    return self._placeholder
end
function TextInput.Set:placeholder(value)
    value = value or ""
    if self._cocosobj then
        self._cocosobj.placeholder = value
    end
    self._placeholder = value
end

function TextInput.Get:multiline()
    return self.label.multiline
end

function TextInput.Set:multiline(value)
    self.label.multiline = value
    if self._cocosobj then
        if not value then
            self._cocosobj:setInputMode(6)
        end
    end
end

-- CocosInput
CocosInput = class("CocosInput", UIView)

function CocosInput:ctor()
    self.open = false
    self.touchable = false
    self.restrict = false
end

function CocosInput.Get:cobj()
    local cobj = EditBox.create()
    cobj:setTouchEnabled(false)
    cobj:setInputFlag(1)
    rawset(self, "cobj", cobj)
    return cobj
end

function CocosInput:openKeyboard()
    self.cobj:registerScriptEditBoxHandler(function (event)
        if event == "return" then
            self.open = false
            self:dispatch(Event.COMPLETE)
        elseif event == "changed" then
            if self.restrict then
                local restrict = "[^" .. self.restrict .. "]"
                self.text = string.gsub(self.text, restrict, "")
            end
            self:dispatch(Event.CHANGE)

            -- when use keyborad, if set text, label will be visible again
            for _, child in ipairs(self.cobj:getChildren()) do
                child:setVisible(false)
            end
        end
    end)
    self.cobj:openKeyboard()
    self.open = true
end

function CocosInput:closeKeyboard()
    if self.open then
        self.cobj:closeKeyboard()
        self.open = false
    end
    self.cobj:unregisterScriptEditBoxHandler()
end

function CocosInput:setFontName(value)
    self.cobj:setFontName(value)
end

function CocosInput:setFontSize(value)
    self.cobj:setFontSize(value)
    self.cobj:setPlaceholderFontSize(value)
end

function CocosInput:setInputMode(value)
    self.cobj:setInputMode(value)
end

function CocosInput:setInputFlag(value)
    self.cobj:setInputFlag(value)
end

function CocosInput.Set:width(value)
    self._width = value
    if value ~= 0 then
        self.cobj:setWidth(value)
    end
end
function CocosInput.Get:width()
    return self._width
end

function CocosInput.Set:height(value)
    self._height = value
    if value ~= 0 then
        self.cobj:setHeight(value)
    end
end
function CocosInput.Get:height()
    return self._height
end

function CocosInput.Get:color()
    return self.cobj:getFontColor()
end
function CocosInput.Set:color(value)
    self.cobj:setFontColor(value)
end

function CocosInput.Get:placeholder()
	return self.cobj:getPlaceHolder()
end
function CocosInput.Set:placeholder(value)
	self.cobj:setPlaceHolder(value)
end

function CocosInput.Get:text()
	return self.cobj:getText()
end
function CocosInput.Set:text(value)
	self.cobj:setText(value or "")
end

return TextInput
