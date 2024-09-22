---AUTO GENERATED, DO NOT MODIFY!
---@meta spine.SlotData

---
---@class spine.SlotData : spine.SpineObject
---@field attachmentName any May be empty.
---@field blendMode spine.BlendMode 
---@field boneData spine.BoneData 
---@field color any 
---@field darkColor any 
---@field index integer 
---@field name any 
---@field visible boolean 
local SlotData = {}

---May be empty.
---@return any
function SlotData:getAttachmentName() end

---@return spine.BlendMode
function SlotData:getBlendMode() end

---@return spine.BoneData
function SlotData:getBoneData() end

---@return any
function SlotData:getColor() end

---@return any
function SlotData:getDarkColor() end

---@return integer
function SlotData:getIndex() end

---@return any
function SlotData:getName() end

---@return boolean
function SlotData:hasDarkColor() end

---@return boolean
function SlotData:isVisible() end

---@param index integer
---@param name any
---@param boneData spine.BoneData
---@return spine.SlotData
function SlotData.new(index, name, boneData) end

---@param inValue any
function SlotData:setAttachmentName(inValue) end

---@param inValue spine.BlendMode
function SlotData:setBlendMode(inValue) end

---@param inValue boolean
function SlotData:setHasDarkColor(inValue) end

---@param inValue boolean
function SlotData:setVisible(inValue) end

return SlotData