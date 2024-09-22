---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.EaseBezierAction

---\class EaseBezierAction
---Ease Bezier
---\ingroup Actions
---@class cc.EaseBezierAction : cc.ActionEase
local EaseBezierAction = {}

---Create the action with the inner action.
---@param action cc.ActionInterval # The pointer of the inner action.
---@return cc.EaseBezierAction # A pointer of EaseBezierAction action. If creation failed, return nil.
function EaseBezierAction.create(action) end

---Set the bezier parameters.
---@param p0 number
---@param p1 number
---@param p2 number
---@param p3 number
function EaseBezierAction:setBezierParamer(p0, p1, p2, p3) end

return EaseBezierAction