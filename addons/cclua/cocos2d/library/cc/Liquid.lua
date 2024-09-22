---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.Liquid

---Liquid action.
---\details This action is used for take effect on the target node as liquid.
---You can create the action by these parameters:
---duration, grid size, waves count, amplitude of the liquid effect.
---@class cc.Liquid : cc.Grid3DAction
---@field amplitude number Get the amplitude of the effect. \return Return the amplitude of the effect.
local Liquid = {}

---Create the action with amplitude, grid size, waves count and duration.
---@param duration number # Specify the duration of the Liquid action. It's a value in seconds.
---@param gridSize cc.Size # Specify the size of the grid.
---@param waves integer # Specify the waves count of the Liquid action.
---@param amplitude number # Specify the amplitude of the Liquid action.
---@return cc.Liquid # If the creation success, return a pointer of Liquid action; otherwise, return nil.
function Liquid.create(duration, gridSize, waves, amplitude) end

---Get the amplitude of the effect.
---@return number # Return the amplitude of the effect.
function Liquid:getAmplitude() end

---Set the amplitude to the effect.
---@param amplitude number # The value of amplitude will be set.
function Liquid:setAmplitude(amplitude) end

return Liquid