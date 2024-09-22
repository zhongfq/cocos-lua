---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.EaseRateAction

---\class EaseRateAction
---Base class for Easing actions with rate parameters
---\details Ease the inner action with specified rate.
---\ingroup Actions
---@class cc.EaseRateAction : cc.ActionEase
---@field rate number Get the rate value of the ease rate action. \return Return the rate value of the ease rate action.
local EaseRateAction = {}

---@param action cc.ActionInterval
---@param rate number
---@return cc.EaseRateAction
function EaseRateAction.create(action, rate) end

---Get the rate value of the ease rate action.
---@return number # Return the rate value of the ease rate action.
function EaseRateAction:getRate() end

---Set the rate value for the ease rate action.
---@param rate number # The value will be set.
function EaseRateAction:setRate(rate) end

return EaseRateAction