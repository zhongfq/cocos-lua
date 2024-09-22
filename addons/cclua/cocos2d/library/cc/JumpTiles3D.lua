---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.JumpTiles3D

---JumpTiles3D action.
---\details Move the tiles of a target node across the Z axis.
---@class cc.JumpTiles3D : cc.TiledGrid3DAction
---@field amplitude number Get the amplitude of the effect. \return Return the amplitude of the effect.
local JumpTiles3D = {}

---Create the action with the number of jumps, the sin amplitude, the grid size and the duration.
---@param duration number # Specify the duration of the JumpTiles3D action. It's a value in seconds.
---@param gridSize cc.Size # Specify the size of the grid.
---@param numberOfJumps integer # Specify the jump tiles count.
---@param amplitude number # Specify the amplitude of the JumpTiles3D action.
---@return cc.JumpTiles3D # If the creation success, return a pointer of JumpTiles3D action; otherwise, return nil.
function JumpTiles3D.create(duration, gridSize, numberOfJumps, amplitude) end

---Get the amplitude of the effect.
---@return number # Return the amplitude of the effect.
function JumpTiles3D:getAmplitude() end

---Set the amplitude to the effect.
---@param amplitude number # The value of amplitude will be set.
function JumpTiles3D:setAmplitude(amplitude) end

return JumpTiles3D