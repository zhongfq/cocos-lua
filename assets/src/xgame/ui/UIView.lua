--
-- $id: UIView.lua O $
--

local class         = require "xgame.class"
local Event         = require "xgame.Event"
local UIAlign       = require "xgame.display.UIAlign"
local UITouchable   = require "xgame.display.UITouchable"

local pairs = pairs

local UIView = class("UIView", UITouchable)

function UIView:ctor()
    self._initialized       = false
    self.touchable          = false 
    self.touch_children     = false 
    self.horizontal_align   = UIAlign.NONE
    self.horizontal_center  = 0
    self.left               = 0
    self.right              = 0
    self.vertical_align     = UIAlign.NONE
    self.vertical_center    = 0
    self.top                = 0
    self.bottom             = 0
    self.cobj:setIgnoreAnchorPointForPosition(true)
    self.cobj:setAnchorPoint(0.5, 0.5)
end

function UIView.Get:initialized()
    return self._initialized
end

function UIView:validate_display()
end

function UIView:_validate_now()
    if self._stage and self._parent then
        self._parent:_notify_update(self)
    end
end

function UIView:bounds_test(x, y)
    local left, bottom, right, top = 0, 0, self.width, self.height
    return not (x < left or x > right or y > top or y < bottom)
end

function UIView:get_bounds(target)
    return self.cobj:getBounds(target.cobj, 0, self.width, self.height, 0)
end

function UIView:remove_self()
    local parent = self.parent
    if parent and self.cobj then
        parent:remove_child(self)
    end
end

function UIView:run_action(action)
    self.cobj:runAction(action)
end

function UIView:stop_action(action)
    self.cobj:stopAction(action)
end

function UIView:stop_action_by_tag(tag)
    self.cobj:stopActionByTag(tag)
end

function UIView:stop_all_actions_by_tag(tag)
    self.cobj:stopAllActionsByTag(tag)
end

function UIView:stop_all_actions()
    self.cobj:stopAllActions()
end

function UIView:stop_actions_by_flags(flags)
    self.cobj:stopActionsByFlags(flags)
end

function UIView:schedule_update(callback)
    self.cobj:scheduleUpdateWithPriorityLua(callback, 0)
end

function UIView:unschedule_update()
    self.cobj:unscheduleUpdate()
end

function UIView:global_to_local(x, y)
    return self.cobj:convertToNodeSpace(x, y)
end

function UIView:local_to_global(x, y)
    return self.cobj:convertToWorldSpace(x, y)
end

function UIView:set_position(x, y)
    self.cobj:setPosition(x, y)
end

function UIView:set_scale(x, y)
    self.cobj:setScale(x, y)
end

function UIView:get_position()
    return self.cobj:getPosition()
end

function UIView.Get:x() return self.cobj:getPositionX() end
function UIView.Set:x(value) 
    self.cobj:setPositionX(value) 
end

function UIView.Get:y() return self.cobj:getPositionY() end
function UIView.Set:y(value) 
    self.cobj:setPositionY(value) 
end

function UIView.Get:scale_x() return self.cobj:getScaleX() end
function UIView.Set:scale_x(value) 
    self.cobj:setScaleX(value) 
end

function UIView.Get:scale_y() return self.cobj:getScaleY() end
function UIView.Set:scale_y(value) 
    self.cobj:setScaleY(value) 
end

function UIView.Get:anchor_x() return self.cobj:getAnchorX() end
function UIView.Set:anchor_x(value) 
    self.cobj:setAnchorX(value) 
end

function UIView.Get:anchor_y() return self.cobj:getAnchorY() end
function UIView.Set:anchor_y(value) 
    self.cobj:setAnchorY(value) 
end

function UIView.Get:visible() return self.cobj:isVisible() end
function UIView.Set:visible(value) 
    self.cobj:setVisible(value) 
end

function UIView.Get:rotation() return self.cobj:getRotation() end
function UIView.Set:rotation(value) 
    self.cobj:setRotation(value) 
end

local function colortoint(c)
    return c.r << 16 | c.g << 8 | c.b
end

function UIView.Get:color() return colortoint(self.cobj:getColor()) end
function UIView.Set:color(value) 
    local R = value >> 16 & 0xFF
    local G = value >> 8 & 0xFF
    local B = value & 0xFF
    self.cobj:setColor({r = R, g = G, b = B}) 
end

function UIView.Get:alpha() return self.cobj:getOpacity() / 255 end
function UIView.Set:alpha(value) 
    self.cobj:setOpacity(value * 255) 
end

function UIView.Get:width() return self.cobj:getWidth() end
function UIView.Set:width(value) 
    self.cobj:setWidth(value) 
end

function UIView.Get:height() return self.cobj:getHeight() end
function UIView.Set:height(value) 
    self.cobj:setHeight(value) 
end

function UIView.Get:parent() return self._parent end

function UIView.Get:stage() return self._stage end
function UIView:_set_stage(value)
    --remove form stage
    if not value and self._stage then
        local stage = self._stage
        if stage.focus == self then
            stage.focus = false
        end
        self:dispatch_event(Event.REMOVED_FORM_STAGE)
        stage:dispatch_event(Event.REMOVED_FORM_STAGE, self)
    end

    self._stage = value

    --add to stage
    if value then
        self:dispatch_event(Event.ADDED_TO_STAGE)
        value:dispatch_event(Event.ADDED_TO_STAGE, self)
    end
end

return UIView
