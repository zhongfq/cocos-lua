local class     = require "xgame.class"
local Event     = require "xgame.event.Event"
local Align     = require "xgame.ui.Align"
local UIObject  = require "xgame.ui.UIObject"

local DisplayObject = class("DisplayObject", UIObject)

function DisplayObject:ctor(cobj)
    self._stage = false
    self._rootNode = false
    self.name = cobj.name or ""
    self.layoutParams = {
        horizontalAlign = Align.NONE,
        horizontalCenter = 0,
        verticalAlign = Align.NONE,
        verticalCenter = 0,
        left = 0,
        right = 0,
        top = 0,
        bottom = 0,
    }
    self.cobjType = "swf"
    self.cobj = cobj
end

function DisplayObject.Get:initialized()
    return true
end

function DisplayObject:validateDisplay()
end

function DisplayObject.Get:rootNode()
    if not self._rootNode then
        self._rootNode = self.parent.rootNode
    end
    return self._rootNode
end

function DisplayObject:removeSelf()
    if self.parent then
        self.parent:removeChild(self)
    end
end

function DisplayObject:setScale(sx, sy)
    self.cobj:setScale(sx, sy)
end

function DisplayObject:getScale()
    return self.cobj:getScale()
end

function DisplayObject:setPosition(x, y)
    self.cobj:setPosition(x, y)
end

function DisplayObject:getPosition()
    return self.cobj:getPosition()
end

function DisplayObject:setShader(shaderType, shader)
    self.cobj:setShader(shaderType, shader)
end

function DisplayObject:getShader(shaderType)
    return self.cobj:getShader(shaderType)
end

function DisplayObject:localToGlobal(x, y)
    x, y = self.cobj:localToGlobal(x, y)
    local rootNode = self.rootNode
    if rootNode then
        x, y = rootNode.cobj:swfToWorldSpace(x, y)
    end
    return x, y
end

function DisplayObject:globalToLocal(x, y)
    local rootNode = self.rootNode
    if rootNode then
        x, y = rootNode.cobj:worldToSWFSpace(x, y)
    end
    return self.cobj:globalToLocal(x, y)
end

function DisplayObject:runAction(action)
    self.cobj:runAction(action)
end

function DisplayObject:stopAction(action)
    self.cobj:stopAction(action)
end

function DisplayObject:stopActionByTag(tag)
    self.cobj:stopActionByTag(tag)
end

function DisplayObject:stopAllActionsByTag(tag)
    self.cobj:stopAllActionsByTag(tag)
end

function DisplayObject:stopAllActions()
    self.cobj:stopAllActions()
end

function DisplayObject:stopActionsByFlags(flags)
    self.cobj:stopActionsByFlags(flags)
end

function DisplayObject.Get:scaleX() return self.cobj.scaleX end
function DisplayObject.Set:scaleX(value)
    self.cobj.scaleX = value
end

function DisplayObject.Get:scaleY() return self.cobj.scaleY end
function DisplayObject.Set:scaleY(value)
    self.cobj.scaleY = value
end

function DisplayObject.Get:x() return self.cobj.x end
function DisplayObject.Set:x(value)
    self.cobj.x = value
end

function DisplayObject.Get:y() return self.cobj.y end
function DisplayObject.Set:y(value)
    self.cobj.y = value
end

function DisplayObject.Get:rotation() return self.cobj.rotation end
function DisplayObject.Set:rotation(value)
    self.cobj.rotation = value
end

function DisplayObject.Get:alpha() return self.cobj.alpha end
function DisplayObject.Set:alpha(value)
    self.cobj.alpha = value
end

function DisplayObject.Get:visible() return self.cobj.visible end
function DisplayObject.Set:visible(value)
    self.cobj.visible = value
end

function DisplayObject.Get:parent() return self._parent end

function DisplayObject.Get:width() return self.cobj.width end

function DisplayObject.Get:height() return self.cobj.height end

function DisplayObject.Get:stage() return self._stage end
function DisplayObject:_setStage(value)
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

return DisplayObject