---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.Lens3D

---Lens3D action.
---\details This action is used for take effect on the target node as lens.
---You can create the action by these parameters:
---duration, grid size, center position of lens, radius of lens.
---Also you can change the lens effect value & whether effect is concave by the setter methods.
---@class cc.Lens3D : cc.Grid3DAction
---@field lensEffect number Get the value of lens effect. Default value is 0.7. \return The value of lens effect.
---@field position cc.Vec2 Get the center position of lens effect. \return The center position of lens effect.
local Lens3D = {}

---Create the action with center position, radius, a grid size and duration.
---@param duration number # Specify the duration of the Lens3D action. It's a value in seconds.
---@param gridSize cc.Size # Specify the size of the grid.
---@param position cc.Vec2 # Specify the center position of the lens.
---@param radius number # Specify the radius of the lens.
---@return cc.Lens3D # If the creation success, return a pointer of Lens3D action; otherwise, return nil.
function Lens3D.create(duration, gridSize, position, radius) end

---Get the value of lens effect. Default value is 0.7.
---@return number # The value of lens effect.
function Lens3D:getLensEffect() end

---Get the center position of lens effect.
---@return cc.Vec2 # The center position of lens effect.
function Lens3D:getPosition() end

---Set whether lens is concave.
---@param concave boolean # Whether lens is concave.
function Lens3D:setConcave(concave) end

---Set the value of lens effect.
---@param lensEffect number # The value of lens effect will be set.
function Lens3D:setLensEffect(lensEffect) end

---Set the center position of lens effect.
---@param position cc.Vec2 # The center position will be set.
function Lens3D:setPosition(position) end

return Lens3D