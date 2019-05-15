local Animate = require "cc.Animate"
local MoveTo = require "cc.MoveTo"
local MoveBy = require "cc.MoveBy"
local CallFunc = require "cc.CallFunc"
local Sequence = require "cc.Sequence"
local DelayTime = require "cc.DelayTime"
local ScaleTo = require "cc.ScaleTo"
local Speed = require "cc.Speed"
local Repeat = require "cc.Repeat"
local RepeatForever = require "cc.RepeatForever"
local FadeTo = require "cc.FadeTo"
local FadeIn = require "cc.FadeIn"
local FadeOut = require "cc.FadeOut"
local RotateBy = require "cc.RotateBy"
local Hide = require "cc.Hide"
local Show = require "cc.Show"
local Spawn = require "cc.Spawn"
local RotateTo = require "cc.RotateTo"
local EaseRateAction = require "cc.EaseRateAction"
local EaseIn = require "cc.EaseIn"
local EaseOut = require "cc.EaseOut"
local EaseInOut = require "cc.EaseInOut"
local EaseExponentialIn = require "cc.EaseExponentialIn"
local EaseExponentialOut = require "cc.EaseExponentialOut"
local EaseExponentialInOut = require "cc.EaseExponentialInOut"
local EaseSineIn = require "cc.EaseSineIn"
local EaseSineOut = require "cc.EaseSineOut"
local EaseSineInOut = require "cc.EaseSineInOut"
local EaseElasticIn = require "cc.EaseElasticIn"
local EaseElasticOut = require "cc.EaseElasticOut"
local EaseElasticInOut = require "cc.EaseElasticInOut"
local EaseBounceIn = require "cc.EaseBounceIn"
local EaseBounceOut = require "cc.EaseBounceOut"
local EaseBounceInOut = require "cc.EaseBounceInOut"
local EaseBackIn = require "cc.EaseBackIn"
local EaseBackOut = require "cc.EaseBackOut"
local EaseBackInOut = require "cc.EaseBackInOut"
local EaseQuadraticActionIn = require "cc.EaseQuadraticActionIn"
local EaseQuadraticActionOut = require "cc.EaseQuadraticActionOut"
local EaseQuadraticActionInOut = require "cc.EaseQuadraticActionInOut"
local EaseQuarticActionIn = require "cc.EaseQuarticActionIn"
local EaseQuarticActionOut = require "cc.EaseQuarticActionOut"
local EaseQuarticActionInOut = require "cc.EaseQuarticActionInOut"
local EaseQuinticActionIn = require "cc.EaseQuinticActionIn"
local EaseQuinticActionOut = require "cc.EaseQuinticActionOut"
local EaseQuinticActionInOut = require "cc.EaseQuinticActionInOut"

local M = {}

function M.animate(...)
    return Animate.create(...)
end

function M.moveTo(duration, x, y)
    return MoveTo.create(duration, x, y)
end

function M.moveBy(duration, x, y)
    return MoveBy.create(duration, x, y)
end

function M.callFunc(func)
    return CallFunc.create(func)
end

function M.sequence(...)
    return Sequence.create(...)
end

function M.delayTime(delay)
    return DelayTime.create(delay)
end

function M.delayCall(time, func)
    return M.sequence(M.delayTime(time), M.callFunc(func))
end

function M.scaleTo(...)
    return ScaleTo.create(...)
end

function M.speed(...)
    return Speed.create(...)
end

function M.repeatTimes(...)
    return Repeat.create(...)
end

function M.repeatForever(...)
    return RepeatForever.create(...)
end

function M.fadeTo(duration, alpha)
    return FadeTo.create(duration, alpha * 255)
end

function M.fadeIn(...)
    return FadeIn.create(...)
end

function M.fadeOut(...)
    return FadeOut.create(...)
end

function M.removeSelf(view)
    assert(view)
    return M.callFunc(function()
        view:removeSelf()
    end)
end

function M.rotateBy(...)
    return RotateBy.create(...)
end

function M.hide()
    return Hide.create()
end

function M.show()
    return Show.create()
end

function M.spawn(...)
    return Spawn.create(...)
end

function M.rotateTo(...)
    return RotateTo.create(...)
end

function M.easeRate(...)
    return EaseRateAction.create(...)
end

function M.easeIn(...)
    return EaseIn.create(...)
end

function M.easeOut(...)
    return EaseOut.create(...)
end

function M.easeInOut(...)
    return EaseInOut.create(...)
end

function M.easeExponentialIn(...)
    return EaseExponentialIn.create(...)
end

function M.easeExponentialOut(...)
    return EaseExponentialOut.create(...)
end

function M.easeExponentialInOut(...)
    return EaseExponentialInOut.create(...)
end

function M.easeSineIn(...)
    return EaseSineIn.create(...)
end

function M.easeSineOut(...)
    return EaseSineOut.create(...)
end

function M.easeSineInOut(...)
    return EaseSineInOut.create(...)
end

function M.easeElasticIn(...)
    return EaseElasticIn.create(...)
end

function M.easeElasticOut(...)
    return EaseElasticOut.create(...)
end

function M.easeElasticInOut(...)
    return EaseElasticInOut.create(...)
end

function M.easeBounceIn(...)
    return EaseBounceIn.create(...)
end

function M.easeBounceOut(...)
    return EaseBounceOut.create(...)
end

function M.easeBounceInOut(...)
    return EaseBounceInOut.create(...)
end

function M.easeBackIn(...)
    return EaseBackIn.create(...)
end

function M.easeBackOut(...)
    return EaseBackOut.create(...)
end

function M.easeBackInOut(...)
    return EaseBackInOut.create(...)
end

function M.easeQuadraticIn(...)
    return EaseQuadraticActionIn.create(...)
end

function M.easeQuadraticOut(...)
    return EaseQuadraticActionOut.create(...)
end

function M.easeQuadraticInOut(...)
    return EaseQuadraticActionInOut.create(...)
end

function M.easeQuarticIn(...)
    return EaseQuarticActionIn.create(...)
end

function M.easeQuarticOut(...)
    return EaseQuarticActionOut.create(...)
end

function M.easeQuarticInOut(...)
    return EaseQuarticActionInOut.create(...)
end

function M.easeQuinticIn(...)
    return EaseQuinticActionIn.create(...)
end

function M.easeQuinticOut(...)
    return EaseQuinticActionOut.create(...)
end

function M.easeQuinticInOut(...)
    return EaseQuinticActionInOut.create(...)
end

return M
