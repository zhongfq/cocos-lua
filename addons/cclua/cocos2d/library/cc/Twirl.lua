---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.Twirl

---Twirl action.
---\details This action is used for take effect on the target node as twirl.
---You can control the effect by these parameters:
---duration, grid size, center position, twirls count, amplitude.
---@class cc.Twirl : cc.Grid3DAction
---@field amplitude number Get the amplitude of the effect. \return Return the amplitude of the effect.
---@field position cc.Vec2 Get the center position of twirl action. \return The center position of twirl action.
local Twirl = {}

---Create the action with center position, number of twirls, amplitude, a grid size and duration.
---@param duration number # Specify the duration of the Twirl action. It's a value in seconds.
---@param gridSize cc.Size # Specify the size of the grid.
---@param position cc.Vec2 # Specify the center position of the twirl action.
---@param twirls integer # Specify the twirls count of the Twirl action.
---@param amplitude number # Specify the amplitude of the Twirl action.
---@return cc.Twirl # If the creation success, return a pointer of Twirl action; otherwise, return nil.
function Twirl.create(duration, gridSize, position, twirls, amplitude) end

---Get the amplitude of the effect.
---@return number # Return the amplitude of the effect.
function Twirl:getAmplitude() end

---Get the center position of twirl action.
---@return cc.Vec2 # The center position of twirl action.
function Twirl:getPosition() end

---Set the amplitude to the effect.
---@param amplitude number # The value of amplitude will be set.
function Twirl:setAmplitude(amplitude) end

---Set the center position of twirl action.
---@param position cc.Vec2 # The center position of twirl action will be set.
function Twirl:setPosition(position) end

return Twirl