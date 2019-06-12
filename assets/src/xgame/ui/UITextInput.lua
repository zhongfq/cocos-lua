--
-- $id: UITextInput.lua O $
--

local class         = require "xgame.class"
local Event         = require "xgame.event.Event"
local TouchEvent    = require "xgame.display.TouchEvent"
local UIView        = require "xgame.display.UIView"

local UITextInput = class("UITextInput", UIView)

function UITextInput:ctor()
    self._color = 0x000000
    self._placeholder_color = 0x000000
    self._font_name = false
    self._font_size = false
    self._label:setReturnType(1)
    self:set_input_mode(0)
    self:set_input_flag(5)
    self.touchable = true

    self._is_open = false

    self:add_event_listener(Event.REMOVED_FORM_STAGE, function ()
        self._label:unregisterScriptEditBoxHandler()
    end)

    self:add_event_listener(Event.FOCUS_OUT, function ()
        if self._is_open then
            self._is_open = false
            self._label:closeKeyboard()
        end
        self._label:setPosition(0, 0)
        self._label:unregisterScriptEditBoxHandler()
    end)

    self:add_event_listener(TouchEvent.CLICK, function ()
        self._label:registerScriptEditBoxHandler(function (event)
            if event == "return" then
                self._label:setPosition(0, 0)
                self._is_open = false
                if self.stage and self.stage.focus == self then
                    self.stage.focus = false
                end
                self._label:unregisterScriptEditBoxHandler()
                self:dispatch_event(Event.COMPLETE)
            elseif event == "changed" then
                self:dispatch_event(Event.CHANGE)
            end
        end)
        

        local vbl, vbr, vbt, vbb = xGame:visible_bounds()
        local dw, dh = xGame:design_size()
        local offset = (dh - math.abs(vbb - vbt)) / 2
        local x, y = self:local_to_global(0, 0)
        if xGame.os == "mac" then
            y = y - xGame.stage.y - offset
        else
            y = y - xGame.stage.y + offset
        end
        x, y = self:global_to_local(x, y)
        self._label:setPosition(x, y)

        local A = require "xgame.display.action"
        self._label:runAction(A.call_func(function ()
            if self.cobj then
                self._label:openKeyboard()
                self._is_open = true
            end
        end))
    end)
end

function UITextInput.Get:cobj()
    local cobj = ccui.Layout:create()
    cobj:setTouchEnabled(false)
    rawset(self, "cobj", cobj)

    local label = ccui.EditBox:create()
    label:setTouchEnabled(false)
    label:setIgnoreAnchorPointForPosition(true)
    cobj:addChild(label, 0)
    self._label = label

    return cobj
end

function UITextInput:set_input_mode(value)
    self._label:setInputMode(value)
end

function UITextInput:set_input_flag(value)
    self._label:setInputFlag(value)
end

local function cti(c)
    return c.r << 16 | c.g << 8 | c.b
end

local function itc(color)
    local R = color >> 16 & 0xFF
    local G = color >> 8 & 0xFF
    local B = color & 0xFF
    return {r = R, g = G, b = B, a = 255}
end

function UITextInput.Set:width(value)
    UIView.Set.width(self, value)
    if value ~= 0 then
        self._label:setWidth(value)
    end
end

function UITextInput.Set:height(value)
    UIView.Set.height(self, value)
    if value ~= 0 then
        self._label:setHeight(value)
    end
end

function UITextInput.Get:max_length() return self._label:getMaxLength() end
function UITextInput.Set:max_length(value)
    self._label:setMaxLength(value)
end

function UITextInput.Get:text() return self._label:getText() end
function UITextInput.Set:text(value)
    self._label:setText(value or "")
end

function UITextInput.Get:color() return self._color end
function UITextInput.Set:color(value) 
    self._color = value
    self._label:setFontColor(itc(value)) 
end

function UITextInput.Get:font_size() return self._font_size end
function UITextInput.Set:font_size(value)
    self._font_size = value
    self._label:setFontSize(value)
    self._label:setPlaceholderFontSize(value)
end

function UITextInput.Get:font_name() return self._font_name end
function UITextInput.Set:font_name(value)
    self._label:setFontName(value)
    self._label:setPlaceholderFontName(value)
end

function UITextInput.Get:placeholder() return self._label:getPlaceHolder() end
function UITextInput.Set:placeholder(value)
    self._label:setPlaceHolder(value or "")
end

function UITextInput.Get:placeholder_color() return self._placeholder_color end
function UITextInput.Set:placeholder_color(value) 
    self._placeholder_color = value
    self._label:setPlaceholderFontColor(itc(value)) 
end

return UITextInput
