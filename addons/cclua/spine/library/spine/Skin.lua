---AUTO GENERATED, DO NOT MODIFY!
---@meta spine.Skin

---Stores attachments by slot index and attachment name.
---See SkeletonData::getDefaultSkin, Skeleton::getSkin, and
---http://esotericsoftware.com/spine-runtime-skins in the Spine Runtimes Guide.
---@class spine.Skin : spine.SpineObject
---@field bones any 
---@field color any 
---@field constraints any 
---@field name any 
local Skin = {}

---Adds all attachments, bones, and constraints from the specified skin to this skin.
---@param other spine.Skin
function Skin:addSkin(other) end

---Adds all attachments, bones, and constraints from the specified skin to this skin. Attachments are deep copied.
---@param other spine.Skin
function Skin:copySkin(other) end

---Returns the attachment for the specified slot index and name, or NULL.
---@param slotIndex integer
---@param name any
---@return spine.Attachment
function Skin:getAttachment(slotIndex, name) end

---@return any
function Skin:getBones() end

---@return any
function Skin:getColor() end

---@return any
function Skin:getConstraints() end

---@return any
function Skin:getName() end

---@param name any
---@return spine.Skin
function Skin.new(name) end

---@param slotIndex integer
---@param name any
function Skin:removeAttachment(slotIndex, name) end

---Adds an attachment to the skin for the specified slot index and name.
---If the name already exists for the slot, the previous value is replaced.
---@param slotIndex integer
---@param name any
---@param attachment spine.Attachment
function Skin:setAttachment(slotIndex, name, attachment) end

return Skin