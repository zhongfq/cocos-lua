---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.Ripple3D

---Ripple3D action.
---\details This action is used for take effect on the target node as ripple.
---You can create the action by these parameters:
---duration, grid size, center position of ripple,
---radius of ripple, waves count, amplitude.
---@class cc.Ripple3D : cc.Grid3DAction
---@field amplitude number Get the amplitude of ripple effect. \return The amplitude of ripple effect.
---@field position cc.Vec2 Get the center position of ripple effect. \return The center position of ripple effect.
local Ripple3D = {}

---Create the action with center position, radius, number of waves, amplitude, a grid size and duration.
---@param duration number # Specify the duration of the Ripple3D action. It's a value in seconds.
---@param gridSize cc.Size # Specify the size of the grid.
---@param position cc.Vec2 # Specify the center position of the ripple effect.
---@param radius number # Specify the radius of the ripple effect.
---@param waves integer # Specify the waves count of the ripple effect.
---@param amplitude number # Specify the amplitude of the ripple effect.
---@return cc.Ripple3D # If the creation success, return a pointer of Ripple3D action; otherwise, return nil.
function Ripple3D.create(duration, gridSize, position, radius, waves, amplitude) end

---Get the amplitude of ripple effect.
---@return number # The amplitude of ripple effect.
function Ripple3D:getAmplitude() end

---Get the center position of ripple effect.
---@return cc.Vec2 # The center position of ripple effect.
function Ripple3D:getPosition() end

---Set the amplitude of ripple effect.
---@param fAmplitude number # The amplitude of ripple effect.
function Ripple3D:setAmplitude(fAmplitude) end

---Set the center position of ripple effect.
---@param position cc.Vec2 # The center position of ripple effect will be set.
function Ripple3D:setPosition(position) end

return Ripple3D