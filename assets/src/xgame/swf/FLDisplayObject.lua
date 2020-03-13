local class             = require "xgame.class"
local Event             = require "xgame.event.Event"
local Align             = require "xgame.ui.Align"
local UIObject          = require "xgame.ui.UIObject"
local ProgramState      = require "ccb.ProgramState"

local FLDisplayObject = class("FLDisplayObject", UIObject)

function FLDisplayObject:ctor(cobj)
    self._stage = false
    self._rootNode = false
    self.name = cobj.name or ""
    self.horizontalAlign = Align.NONE
    self.horizontalOffset = 0
    self.verticalAlign = Align.NONE
    self.verticalOffset = 0
    self.cobjType = "swf"
    self.cobj = cobj
end

function FLDisplayObject.Get:initialized()
    return true
end

function FLDisplayObject:validateDisplay()
end

function FLDisplayObject.Get:rootNode()
    if not self._rootNode then
        self._rootNode = self.parent.rootNode
    end
    return self._rootNode
end

function FLDisplayObject:removeSelf()
    if self.parent then
        self.parent:removeChild(self)
    end
end

function FLDisplayObject:setScale(sx, sy)
    self.cobj:setScale(sx, sy)
end

function FLDisplayObject:getScale()
    return self.cobj:getScale()
end

function FLDisplayObject:setPosition(x, y)
    self.cobj:setPosition(x, y)
end

function FLDisplayObject:getPosition()
    return self.cobj:getPosition()
end

function FLDisplayObject:setShader(shaderType, shader)
    if shader and shader.classname == 'ccb.Program' then
        shader = ProgramState.new(shader)
    end
    self.cobj:setShader(shaderType, shader)
end

function FLDisplayObject:getShader(shaderType)
    return self.cobj:getShader(shaderType)
end

function FLDisplayObject:localToGlobal(x, y)
    x, y = self.cobj:localToGlobal(x, y)
    local rootNode = self.rootNode
    if rootNode then
        x, y = rootNode.cobj:swfToWorldSpace(x, y)
    end
    return x, y
end

function FLDisplayObject:globalToLocal(x, y)
    local rootNode = self.rootNode
    if rootNode then
        x, y = rootNode.cobj:worldToSWFSpace(x, y)
    end
    return self.cobj:globalToLocal(x, y)
end

function FLDisplayObject:scheduleOnce(callback, delay, key)
    return self.cobj.proxyNode:scheduleOnce(callback, delay, key)
end

function FLDisplayObject:scheduleUpdate()
    self.cobj.proxyNode:scheduleUpdate()
end

function FLDisplayObject:unscheduleUpdate()
    self.cobj.proxyNode:unscheduleUpdate()
end

-- schedule(callback, key)
-- schedule(callback, interval, key)
-- schedule(callback, interval, repeat, delay, key)
function FLDisplayObject:schedule(callback, ...)
    self.cobj.proxyNode:schedule(callback, ...)
end

function FLDisplayObject:unschedule(key)
    self.cobj.proxyNode:unschedule(key)
end

function FLDisplayObject:unscheduleAllCallbacks()
    self.cobj.proxyNode:unscheduleAllCallbacks()
end

function FLDisplayObject:getBounds(target, ...)
    return self.cobj:getBounds(target.cobj, ...)
end

function FLDisplayObject:runAction(action)
    self.cobj:runAction(action)
end

function FLDisplayObject:stopAction(action)
    self.cobj:stopAction(action)
end

function FLDisplayObject:stopActionByTag(tag)
    self.cobj:stopActionByTag(tag)
end

function FLDisplayObject:stopAllActionsByTag(tag)
    self.cobj:stopAllActionsByTag(tag)
end

function FLDisplayObject:stopAllActions()
    self.cobj:stopAllActions()
end

function FLDisplayObject:stopActionsByFlags(flags)
    self.cobj:stopActionsByFlags(flags)
end

function FLDisplayObject.Get:scaleX() return self.cobj.scaleX end
function FLDisplayObject.Set:scaleX(value)
    self.cobj.scaleX = value
end

function FLDisplayObject.Get:scaleY() return self.cobj.scaleY end
function FLDisplayObject.Set:scaleY(value)
    self.cobj.scaleY = value
end

function FLDisplayObject.Get:x() return self.cobj.x end
function FLDisplayObject.Set:x(value)
    self.cobj.x = value
end

function FLDisplayObject.Get:y() return self.cobj.y end
function FLDisplayObject.Set:y(value)
    self.cobj.y = value
end

function FLDisplayObject.Get:rotation() return self.cobj.rotation end
function FLDisplayObject.Set:rotation(value)
    self.cobj.rotation = value
end

function FLDisplayObject.Get:alpha() return self.cobj.alpha end
function FLDisplayObject.Set:alpha(value)
    self.cobj.alpha = value
end

function FLDisplayObject.Get:visible() return self.cobj.visible end
function FLDisplayObject.Set:visible(value)
    self.cobj.visible = value
end

function FLDisplayObject.Get:parent() return self._parent end

function FLDisplayObject.Get:width() return self.cobj.width end

function FLDisplayObject.Get:height() return self.cobj.height end

function FLDisplayObject.Get:stage() return self._stage end
function FLDisplayObject:_setStage(value)
    -- remove form stage
    if not value and self._stage then
        local stage = self._stage
        if stage.focus == self then
            stage.focus = false
        end
        self:dispatch(Event.REMOVED)
        stage:dispatch(Event.REMOVED, self)
    end

    self._stage = value

    -- add to stage
    if value then
        self:dispatch(Event.ADDED)
        value:dispatch(Event.ADDED, self)
    end
end

return FLDisplayObject