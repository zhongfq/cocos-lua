local class     = require "xgame.class"
local Event     = require "xgame.event.Event"
local Align     = require "xgame.ui.Align"
local UIObject  = require "xgame.ui.UIObject"

local UIView = class("UIView", UIObject)

function UIView:ctor()
    self._initialized = false
    self.touchable = false
    self.touchChildren = false
    self.horizontalAlign = Align.NONE
    self.horizontalOffset = 0
    self.verticalAlign = Align.NONE
    self.verticalOffset = 0
    self.ctype = "cocos"
    self.cobj.ignoreAnchorPointForPosition = true
    self.cobj.anchorX = 0.5
    self.cobj.anchorY = 0.5
end

function UIView.Get:initialized()
    return self._initialized
end

function UIView.Get:cobj()
    error(string.format("'%s' must implement", self.classname))
end

function UIView:validateDisplay()
end

function UIView:_validateNow()
    if self._stage and self._parent then
        self._parent:_notifyUpdate(self)
    end
end

function UIView:boundsTest(x, y)
    local left, bottom, right, top = 0, 0, self.width, self.height
    return not (x < left or x > right or y > top or y < bottom)
end

function UIView:getBounds(target)
    if target == self then
        return 0, self.width, self.height, 0
    else
        return self.cobj:getBounds(target.cobj, 0, self.width, self.height, 0)
    end
end

function UIView:removeSelf()
    local parent = self.parent
    if parent then
        parent:removeChild(self)
    end
end

function UIView:runAction(action)
    self.cobj:runAction(action)
end

function UIView:stopAction(action)
    self.cobj:stopAction(action)
end

function UIView:stopActionByTag(tag)
    self.cobj:stopActionByTag(tag)
end

function UIView:stopAllActionsByTag(tag)
    self.cobj:stopAllActionsByTag(tag)
end

function UIView:stopAllActions()
    self.cobj:stopAllActions()
end

function UIView:stopActionsByFlags(flags)
    self.cobj:stopActionsByFlags(flags)
end

function UIView:globalToLocal(x, y)
    return self.cobj:convertToNodeSpace(x, y)
end

function UIView:localToGlobal(x, y)
    return self.cobj:convertToWorldSpace(x, y)
end

function UIView:scheduleOnce(callback, delay, key)
    return self.cobj:scheduleOnce(callback, delay, key)
end

function UIView:scheduleUpdate()
    self.cobj:scheduleUpdate()
end

function UIView:unscheduleUpdate()
    self.cobj:unscheduleUpdate()
end

-- schedule(callback, key)
-- schedule(callback, interval, key)
-- schedule(callback, interval, repeat, delay, key)
function UIView:schedule(callback, ...)
    self.cobj:schedule(callback, ...)
end

function UIView:unschedule(key)
    self.cobj:unschedule(key)
end

function UIView:unscheduleAllCallbacks()
    self.cobj:unscheduleAllCallbacks()
end

function UIView.Get:x() return self.cobj.x end
function UIView.Set:x(value)
    self.cobj.x = value
end

function UIView.Get:y() return self.cobj.y end
function UIView.Set:y(value)
    self.cobj.y = value
end

function UIView.Get:scaleX() return self.cobj.scaleX end
function UIView.Set:scaleX(value)
    self.cobj.scaleX = value
end

function UIView.Get:scaleY() return self.cobj.scaleY end
function UIView.Set:scaleY(value)
    self.cobj.scaleY = value
end

function UIView.Get:anchorX() return self.cobj.anchorX end
function UIView.Set:anchorX(value)
    self.cobj.anchorX = value
end

function UIView.Get:anchorY() return self.cobj.anchorY end
function UIView.Set:anchorY(value)
    self.cobj.anchorY = value
end

function UIView.Get:visible() return self.cobj.visible end
function UIView.Set:visible(value)
    self.cobj.visible = value
end

function UIView.Get:rotation() return self.cobj.rotation end
function UIView.Set:rotation(value)
    self.cobj.rotation = value
end

function UIView.Get:color() return self.cobj.color end
function UIView.Set:color(value)
    self.cobj.color = value
end

function UIView.Get:alpha() return self.cobj.alpha end
function UIView.Set:alpha(value)
    self.cobj.alpha = value
end

function UIView.Get:width() return self.cobj.width end
function UIView.Set:width(value)
    self.cobj.width = value
end

function UIView.Get:height() return self.cobj.height end
function UIView.Set:height(value)
    self.cobj.height = value
end

function UIView.Get:parent() return self._parent end

function UIView.Get:stage() return self._stage end
function UIView:_setStage(value)
    --remove form stage
    if not value and self._stage then
        local stage = self._stage
        if stage.focus == self then
            stage.focus = false
        end
        self:dispatch(Event.REMOVED)
        stage:dispatch(Event.REMOVED, self)
    end

    self._stage = value

    --add to stage
    if value then
        self:dispatch(Event.ADDED)
        value:dispatch(Event.ADDED, self)
    end
end

return UIView