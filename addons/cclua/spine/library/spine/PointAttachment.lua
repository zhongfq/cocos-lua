---AUTO GENERATED, DO NOT MODIFY!
---@meta spine.PointAttachment

---An attachment which is a single point and a rotation. This can be used to spawn projectiles, particles, etc. A bone can be
---used in similar ways, but a PointAttachment is slightly less expensive to compute and can be hidden, shown, and placed in a
---skin.
---
---See http://esotericsoftware.com/spine-point-attachments for Point Attachments in the Spine User Guide.
---@class spine.PointAttachment : spine.Attachment
---@field color any 
---@field rotation number 
---@field x number 
---@field y number 
local PointAttachment = {}

---@param bone spine.Bone
---@param ox olua.float
---@param oy olua.float
function PointAttachment:computeWorldPosition(bone, ox, oy) end

---@param bone spine.Bone
---@return number
function PointAttachment:computeWorldRotation(bone) end

---@return any
function PointAttachment:getColor() end

---@return number
function PointAttachment:getRotation() end

---@return number
function PointAttachment:getX() end

---@return number
function PointAttachment:getY() end

---@param name any
---@return spine.PointAttachment
function PointAttachment.new(name) end

---@param inValue number
function PointAttachment:setRotation(inValue) end

---@param inValue number
function PointAttachment:setX(inValue) end

---@param inValue number
function PointAttachment:setY(inValue) end

return PointAttachment