---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.PhysicsContact

---Contact information. 
---
---It will created automatically when two shape contact with each other. And it will destroyed automatically when two shape separated.
---@class cc.PhysicsContact : cc.EventCustom
---@field data any Get data.  \lua NA
---@field eventCode cc.PhysicsContact.EventCode Get the event code
---@field shapeA cc.PhysicsShape Get contact shape A.
---@field shapeB cc.PhysicsShape Get contact shape B.
local PhysicsContact = {}

---Get data. 
---\lua NA
---@return any
function PhysicsContact:getData() end

---Get the event code
---@return cc.PhysicsContact.EventCode
function PhysicsContact:getEventCode() end

---Get contact shape A.
---@return cc.PhysicsShape
function PhysicsContact:getShapeA() end

---Get contact shape B.
---@return cc.PhysicsShape
function PhysicsContact:getShapeB() end

---Set data to contact. 
---
---You must manage the memory yourself, Generally you can set data at contact begin, and destroy it at contact separate.
---
---\lua NA
---@param data any
function PhysicsContact:setData(data) end

return PhysicsContact