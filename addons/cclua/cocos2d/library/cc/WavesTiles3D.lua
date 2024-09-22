---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.WavesTiles3D

---WavesTiles3D action.
---\details This action wave the target node with many tiles.
---@class cc.WavesTiles3D : cc.TiledGrid3DAction
---@field amplitude number Get the amplitude of the effect. \return Return the amplitude of the effect.
local WavesTiles3D = {}

---Create the action with a number of waves, the waves amplitude, the grid size and the duration.
---@param duration number # Specify the duration of the WavesTiles3D action. It's a value in seconds.
---@param gridSize cc.Size # Specify the size of the grid.
---@param waves integer # Specify the waves count of the WavesTiles3D action.
---@param amplitude number # Specify the amplitude of the WavesTiles3D action.
---@return cc.WavesTiles3D # If the creation success, return a pointer of WavesTiles3D action; otherwise, return nil.
function WavesTiles3D.create(duration, gridSize, waves, amplitude) end

---Get the amplitude of the effect.
---@return number # Return the amplitude of the effect.
function WavesTiles3D:getAmplitude() end

---Set the amplitude to the effect.
---@param amplitude number # The value of amplitude will be set.
function WavesTiles3D:setAmplitude(amplitude) end

return WavesTiles3D