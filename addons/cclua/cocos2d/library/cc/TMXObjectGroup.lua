---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.TMXObjectGroup

---TMXObjectGroup represents the TMX object group.
---\since v0.99.0
---@class cc.TMXObjectGroup : cc.Ref
---@field groupName string Get the group name.  <br><br>\return The group name.
---@field objects any Gets the array of the objects.  <br><br>\return The array of the objects.
---@field positionOffset cc.Vec2 Gets the offset position of child objects.  <br><br>\return The offset position of child objects.
---@field properties any Gets the list of properties stored in a dictionary.  <br><br>\return The list of properties stored in a dictionary.
local TMXObjectGroup = {}

---Get the group name. 
---
---@return string # The group name.
function TMXObjectGroup:getGroupName() end

---Return the dictionary for the specific object name.
---It will return the 1st object found on the array for the given name.
---
---@return any # Return the dictionary for the specific object name.
---@param objectName string
function TMXObjectGroup:getObject(objectName) end

---Gets the array of the objects. 
---
---@return any # The array of the objects.
function TMXObjectGroup:getObjects() end

---Gets the offset position of child objects. 
---
---@return cc.Vec2 # The offset position of child objects.
function TMXObjectGroup:getPositionOffset() end

---Gets the list of properties stored in a dictionary. 
---
---@return any # The list of properties stored in a dictionary.
function TMXObjectGroup:getProperties() end

---Return the value for the specific property name. 
---
---@param propertyName string # The specific property name.
---@return any # Return the value for the specific property name.
---\js NA
function TMXObjectGroup:getProperty(propertyName) end

---\js ctor
---@return cc.TMXObjectGroup
function TMXObjectGroup.new() end

---Set the group name. 
---
---@param groupName string # A string,it is used to set the group name.
function TMXObjectGroup:setGroupName(groupName) end

---Sets the array of the objects.
---
---@param objects any # The array of the objects.
function TMXObjectGroup:setObjects(objects) end

---Sets the offset position of child objects. 
---
---@param offset cc.Vec2 # The offset position of child objects.
function TMXObjectGroup:setPositionOffset(offset) end

---Sets the list of properties.
---
---@param properties any # The list of properties.
function TMXObjectGroup:setProperties(properties) end

return TMXObjectGroup