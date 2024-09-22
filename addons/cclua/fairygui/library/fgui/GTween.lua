---AUTO GENERATED, DO NOT MODIFY!
---@meta fgui.GTween

---
---@class fgui.GTween 
local GTween = {}

---@return any
function GTween:__gc() end

function GTween.clean() end

---@param delay number
---@return fgui.GTweener
function GTween.delayedCall(delay) end

---@param target cc.Ref
---@return fgui.GTweener
---@overload fun(target: cc.Ref, propType: fgui.TweenPropType): fgui.GTweener
function GTween.getTween(target) end

---@param target cc.Ref
---@return boolean
---@overload fun(target: cc.Ref, propType: fgui.TweenPropType): boolean
function GTween.isTweening(target) end

---@param target cc.Ref
---@overload fun(target: cc.Ref, complete: boolean)
---@overload fun(target: cc.Ref, propType: fgui.TweenPropType, complete: boolean)
function GTween.kill(target) end

---@param startValue cc.Vec2
---@param amplitude number
---@param duration number
---@return fgui.GTweener
function GTween.shake(startValue, amplitude, duration) end

---@param startValue number
---@param endValue number
---@param duration number
---@return fgui.GTweener
---@overload fun(startValue: cc.Vec2, endValue: cc.Vec2, duration: number): fgui.GTweener
---@overload fun(startValue: cc.Vec3, endValue: cc.Vec3, duration: number): fgui.GTweener
---@overload fun(startValue: cc.Vec4, endValue: cc.Vec4, duration: number): fgui.GTweener
---@overload fun(startValue: any, endValue: any, duration: number): fgui.GTweener
function GTween.to(startValue, endValue, duration) end

---@param startValue any
---@param endValue any
---@param duration number
---@return fgui.GTweener
function GTween.toColor(startValue, endValue, duration) end

---@param startValue number
---@param endValue number
---@param duration number
---@return fgui.GTweener
function GTween.toDouble(startValue, endValue, duration) end

return GTween