---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.DeccelAmplitude

---DeccelAmplitude action.
---\js NA
---@class cc.DeccelAmplitude : cc.ActionInterval
---@field rate number Get the value of amplitude rate. \return The value of amplitude rate.
local DeccelAmplitude = {}

---Creates the action with an inner action that has the amplitude property, and a duration time.
---@param action cc.Action # A pointer of the inner action.
---@param duration number # Specify the duration of the DeccelAmplitude action.
---@return cc.DeccelAmplitude # Return a pointer of DeccelAmplitude. When the creation failed, return nil.
function DeccelAmplitude.create(action, duration) end

---Get the value of amplitude rate.
---@return number # The value of amplitude rate.
function DeccelAmplitude:getRate() end

---Set the value of amplitude rate.
---@param rate number # Specify the value.
function DeccelAmplitude:setRate(rate) end

return DeccelAmplitude