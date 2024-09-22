---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.AccelDeccelAmplitude

---AccelDeccelAmplitude action.
---\js NA
---@class cc.AccelDeccelAmplitude : cc.ActionInterval
---@field rate number Get the value of amplitude rate. \return the value of amplitude rate.
local AccelDeccelAmplitude = {}

---Create the action with an inner action that has the amplitude property, and a duration time.
---@param action cc.Action # A pointer of the inner action.
---@param duration number # Specify the duration of the AccelDeccelAmplitude action.
---@return cc.AccelDeccelAmplitude # Return a pointer of AccelDeccelAmplitude action. When the creation failed, return nil.
function AccelDeccelAmplitude.create(action, duration) end

---Get the value of amplitude rate.
---@return number # the value of amplitude rate.
function AccelDeccelAmplitude:getRate() end

---Set the value of amplitude rate.
---@param rate number # Specify the value of amplitude rate.
function AccelDeccelAmplitude:setRate(rate) end

return AccelDeccelAmplitude