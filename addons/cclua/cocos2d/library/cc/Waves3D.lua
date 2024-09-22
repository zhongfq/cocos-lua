---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.Waves3D

---Waves3D action.
---\details This action is used for take effect on the target node as 3D waves.
---You can control the effect by these parameters:
---duration, grid size, waves count, amplitude.
---@class cc.Waves3D : cc.Grid3DAction
---@field amplitude number Get the amplitude of the effect. \return Return the amplitude of the effect.
local Waves3D = {}

---Create an action with duration, grid size, waves and amplitude.
---@param duration number # Specify the duration of the Waves3D action. It's a value in seconds.
---@param gridSize cc.Size # Specify the size of the grid.
---@param waves integer # Specify the waves count of the Waves3D action.
---@param amplitude number # Specify the amplitude of the Waves3D action.
---@return cc.Waves3D # If the creation success, return a pointer of Waves3D action; otherwise, return nil.
function Waves3D.create(duration, gridSize, waves, amplitude) end

---Get the amplitude of the effect.
---@return number # Return the amplitude of the effect.
function Waves3D:getAmplitude() end

---Set the amplitude to the effect.
---@param amplitude number # The value of amplitude will be set.
function Waves3D:setAmplitude(amplitude) end

return Waves3D