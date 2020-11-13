local Animate = require "cc.Animate"
local ActionFloat = require "cc.ActionFloat"
local MoveTo = require "cc.MoveTo"
local MoveBy = require "cc.MoveBy"
local MoveFrom = require "cc.MoveFrom"
local CallFunc = require "cc.CallFunc"
local Sequence = require "cc.Sequence"
local DelayTime = require "cc.DelayTime"
local ScaleTo = require "cc.ScaleTo"
local ScaleBy = require "cc.ScaleFrom"
local ScaleFrom = require "cc.ScaleFrom"
local Speed = require "cc.Speed"
local Repeat = require "cc.Repeat"
local RepeatForever = require "cc.RepeatForever"
local FadeTo = require "cc.FadeTo"
local FadeFrom = require "cc.FadeFrom"
local FadeIn = require "cc.FadeIn"
local FadeOut = require "cc.FadeOut"
local RotateTo = require "cc.RotateTo"
local RotateFrom = require "cc.RotateFrom"
local RotateBy = require "cc.RotateBy"
local Hide = require "cc.Hide"
local Show = require "cc.Show"
local Spawn = require "cc.Spawn"
local CatmullRomTo = require "cc.CatmullRomTo"
local CatmullRomBy = require "cc.CatmullRomBy"
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
local PointArray = require "cc.PointArray"

local M = {}

function M.Animate(...)
    return Animate.create(...)
end

function M.ActionFloat(...)
    return ActionFloat.create(...)
end

function M.MoveTo(...)
    return MoveTo.create(...)
end

function M.MoveBy(...)
    return MoveBy.create(...)
end

function M.MoveFrom(...)
    return MoveFrom.create(...)
end

function M.CallFunc(func)
    return CallFunc.create(func)
end

function M.Sequence(...)
    return Sequence.create(...)
end

function M.DelayTime(delay)
    return DelayTime.create(delay)
end

function M.DelayCall(time, func)
    return M.Sequence(M.DelayTime(time), M.CallFunc(func))
end

function M.ScaleTo(...)
    return ScaleTo.create(...)
end

function M.ScaleBy(...)
    return ScaleBy.create(...)
end

function M.ScaleFrom(...)
    return ScaleFrom.create(...)
end

function M.Speed(...)
    return Speed.create(...)
end

function M.Repeat(...)
    return Repeat.create(...)
end

function M.RepeatForever(...)
    return RepeatForever.create(...)
end

function M.FadeTo(duration, alpha)
    return FadeTo.create(duration, alpha * 255 // 1)
end

function M.FadeFrom(duration, alpha)
    return FadeFrom.create(duration, alpha * 255 // 1)
end

function M.FadeIn(...)
    return FadeIn.create(...)
end

function M.FadeOut(...)
    return FadeOut.create(...)
end

function M.RemoveSelf(view)
    assert(view)
    return M.CallFunc(function()
        if view.removeSelf then
            view:removeSelf()
        else
            view:removeFromParent()
        end
    end)
end

function M.RotateBy(...)
    return RotateBy.create(...)
end

function M.Hide()
    return Hide.create()
end

function M.Show()
    return Show.create()
end

function M.Spawn(...)
    return Spawn.create(...)
end

function M.RotateTo(...)
    return RotateTo.create(...)
end

function M.RotateFrom(...)
    return RotateFrom.create(...)
end

function M.CatmullRomTo(t, points)
    local arr = PointArray.create(#points)
    for _, v in ipairs(points) do
        arr:addControlPoint(v)
    end
    return CatmullRomTo.create(t, arr)
end

function M.CatmullRomBy(t, points)
    local arr = PointArray.create(#points)
    for _, v in ipairs(points) do
        arr:addControlPoint(v)
    end
    return CatmullRomBy.create(t, arr)
end

function M.EaseRate(...)
    return EaseRateAction.create(...)
end

function M.EaseIn(...)
    return EaseIn.create(...)
end

function M.EaseOut(...)
    return EaseOut.create(...)
end

function M.EaseInOut(...)
    return EaseInOut.create(...)
end

function M.EaseExponentialIn(...)
    return EaseExponentialIn.create(...)
end

function M.EaseExponentialOut(...)
    return EaseExponentialOut.create(...)
end

function M.EaseExponentialInOut(...)
    return EaseExponentialInOut.create(...)
end

function M.EaseSineIn(...)
    return EaseSineIn.create(...)
end

function M.EaseSineOut(...)
    return EaseSineOut.create(...)
end

function M.EaseSineInOut(...)
    return EaseSineInOut.create(...)
end

function M.EaseElasticIn(...)
    return EaseElasticIn.create(...)
end

function M.EaseElasticOut(...)
    return EaseElasticOut.create(...)
end

function M.EaseElasticInOut(...)
    return EaseElasticInOut.create(...)
end

function M.EaseBounceIn(...)
    return EaseBounceIn.create(...)
end

function M.EaseBounceOut(...)
    return EaseBounceOut.create(...)
end

function M.EaseBounceInOut(...)
    return EaseBounceInOut.create(...)
end

function M.EaseBackIn(...)
    return EaseBackIn.create(...)
end

function M.EaseBackOut(...)
    return EaseBackOut.create(...)
end

function M.EaseBackInOut(...)
    return EaseBackInOut.create(...)
end

function M.EaseQuadraticIn(...)
    return EaseQuadraticActionIn.create(...)
end

function M.EaseQuadraticOut(...)
    return EaseQuadraticActionOut.create(...)
end

function M.EaseQuadraticInOut(...)
    return EaseQuadraticActionInOut.create(...)
end

function M.EaseQuarticIn(...)
    return EaseQuarticActionIn.create(...)
end

function M.EaseQuarticOut(...)
    return EaseQuarticActionOut.create(...)
end

function M.EaseQuarticInOut(...)
    return EaseQuarticActionInOut.create(...)
end

function M.EaseQuinticIn(...)
    return EaseQuinticActionIn.create(...)
end

function M.EaseQuinticOut(...)
    return EaseQuinticActionOut.create(...)
end

function M.EaseQuinticInOut(...)
    return EaseQuinticActionInOut.create(...)
end

return M
