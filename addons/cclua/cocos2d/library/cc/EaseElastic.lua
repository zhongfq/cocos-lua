---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.EaseElastic

---\class EaseElastic
---Ease Elastic abstract class
---\since v0.8.2
---\ingroup Actions
---@class cc.EaseElastic : cc.ActionEase
---@field period number Get period of the wave in radians. Default value is 0.3. \return Return the period of the wave in radians.
local EaseElastic = {}

---Get period of the wave in radians. Default value is 0.3.
---@return number # Return the period of the wave in radians.
function EaseElastic:getPeriod() end

---Set period of the wave in radians.
---@param fPeriod number # The value will be set.
function EaseElastic:setPeriod(fPeriod) end

return EaseElastic