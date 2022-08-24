local A             = require "cclua.ui.action"
local TouchEvent    = require "cclua.TouchEvent"

local TouchStyle = {}

function TouchStyle.scale(target, offset)
    assert(target, 'no target')
    assert(offset)
    local scaleX = target.scaleX
    local scaleY = target.scaleY
    target:addListener(TouchEvent.TOUCH_DOWN, function ()
        target.scaleX = scaleX + offset
        target.scaleY = scaleY + offset
    end)
    target:addListener(TouchEvent.TOUCH_UP, function ()
        target.scaleX = scaleX
        target.scaleY = scaleY
    end)
end

function TouchStyle.elastic(target, offset)
    assert(target, 'no target')
    assert(offset)
    local scaleX = target.scaleX
    local scaleY = target.scaleY
    target:addListener(TouchEvent.TOUCH_DOWN, function ()
        target:runAction(A.EaseElasticOut(
            A.ScaleTo(0.5, scaleX + offset, scaleY + offset)
        ))
    end)
    target:addListener(TouchEvent.TOUCH_UP, function ()
        target:runAction(A.EaseElasticOut(
            A.ScaleTo(0.5, scaleX, scaleY)
        ))
    end)
end

return TouchStyle
