---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.OrbitCamera

---\class OrbitCamera
---
---OrbitCamera action.
---Orbits the camera around the center of the screen using spherical coordinates.
---\ingroup Actions
---@class cc.OrbitCamera : cc.ActionCamera
local OrbitCamera = {}

---Creates a OrbitCamera action with radius, delta-radius,  z, deltaZ, x, deltaX. 
---
---@param t number # Duration in seconds.
---@param radius number # The start radius.
---@param deltaRadius number # The delta radius.
---@param angleZ number # The start angle in Z.
---@param deltaAngleZ number # The delta angle in Z.
---@param angleX number # The start angle in X.
---@param deltaAngleX number # The delta angle in X.
---@return cc.OrbitCamera # An OrbitCamera.
function OrbitCamera.create(t, radius, deltaRadius, angleZ, deltaAngleZ, angleX, deltaAngleX) end

---Positions the camera according to spherical coordinates. 
---
---@param r olua.float # The spherical radius.
---@param zenith olua.float # The spherical zenith.
---@param azimuth olua.float # The spherical azimuth.
function OrbitCamera:sphericalRadius(r, zenith, azimuth) end

return OrbitCamera