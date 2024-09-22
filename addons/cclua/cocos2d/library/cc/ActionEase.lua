---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.ActionEase

---\class ActionEase
---Base class for Easing actions.
---\details Ease actions are created from other interval actions.
---The ease action will change the timeline of the inner action.
---\ingroup Actions
---@class cc.ActionEase : cc.ActionInterval
---@field innerAction cc.ActionInterval Get the pointer of the inner action. \return The pointer of the inner action.
local ActionEase = {}

---Get the pointer of the inner action.
---@return cc.ActionInterval # The pointer of the inner action.
function ActionEase:getInnerAction() end

return ActionEase