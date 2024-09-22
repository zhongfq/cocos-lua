---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.AccelAmplitude

---AccelAmplitude action.
---\js NA
---@class cc.AccelAmplitude : cc.ActionInterval
---@field rate number Get the value of amplitude rate. \return The value of amplitude rate.
local AccelAmplitude = {}

---Create the action with an inner action that has the amplitude property, and a duration time.
---@param action cc.Action # A pointer of the inner action.
---@param duration number # Specify the duration of the AccelAmplitude action.
---@return cc.AccelAmplitude # Return a pointer of AccelAmplitude action. When the creation failed, return nil.
function AccelAmplitude.create(action, duration) end

---Get the value of amplitude rate.
---@return number # The value of amplitude rate.
function AccelAmplitude:getRate() end

---Set the value of amplitude rate.
---@param rate number # Specify the value of amplitude rate.
function AccelAmplitude:setRate(rate) end

return AccelAmplitude