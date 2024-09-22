---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.ActionCamera

---Base class for Camera actions.
---\ingroup Actions
---@class cc.ActionCamera : cc.ActionInterval
---@field center cc.Vec3 
---@field eye cc.Vec3 
---@field up cc.Vec3 
local ActionCamera = {}

---@return cc.Vec3
function ActionCamera:getCenter() end

---@return cc.Vec3
function ActionCamera:getEye() end

---@return cc.Vec3
function ActionCamera:getUp() end

---@param center cc.Vec3
function ActionCamera:setCenter(center) end

---@param eye cc.Vec3
---@overload fun(self: cc.ActionCamera, x: number, y: number, z: number)
function ActionCamera:setEye(eye) end

---@param up cc.Vec3
function ActionCamera:setUp(up) end

return ActionCamera