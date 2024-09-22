---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.Waves

---Waves action.
---\details This action is used for take effect on the target node as waves.
---You can control the effect by these parameters:
---duration, grid size, waves count, amplitude,
---whether waves on horizontal and whether waves on vertical.
---@class cc.Waves : cc.Grid3DAction
---@field amplitude number Get the amplitude of the effect. \return Return the amplitude of the effect.
local Waves = {}

---Create the action with amplitude, horizontal sin, vertical sin, grid size, waves count and duration.
---@param duration number # Specify the duration of the Waves action. It's a value in seconds.
---@param gridSize cc.Size # Specify the size of the grid.
---@param waves integer # Specify the waves count of the Waves action.
---@param amplitude number # Specify the amplitude of the Waves action.
---@param horizontal boolean # Specify whether waves on horizontal.
---@param vertical boolean # Specify whether waves on vertical.
---@return cc.Waves # If the creation success, return a pointer of Waves action; otherwise, return nil.
function Waves.create(duration, gridSize, waves, amplitude, horizontal, vertical) end

---Get the amplitude of the effect.
---@return number # Return the amplitude of the effect.
function Waves:getAmplitude() end

---Set the amplitude to the effect.
---@param amplitude number # The value of amplitude will be set.
function Waves:setAmplitude(amplitude) end

return Waves