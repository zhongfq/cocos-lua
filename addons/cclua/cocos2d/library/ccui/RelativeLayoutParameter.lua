---AUTO GENERATED, DO NOT MODIFY!
---@meta ccui.RelativeLayoutParameter

---Relative layout parameter.
---It is mainly used by  `RelativeLayoutManager`.
---@class ccui.RelativeLayoutParameter : ccui.LayoutParameter
---@field align ccui.RelativeLayoutParameter.RelativeAlign Get RelativeAlign parameter for LayoutParameter. <br><br>\see RelativeAlign \return  A RelativeAlign variable.
---@field relativeName string Get a name of LayoutParameter in Relative Layout. <br><br>\return name Relative name in string.
---@field relativeToWidgetName string Get the relative widget name. \return name A relative widget name in string.
local RelativeLayoutParameter = {}

---Create a RelativeLayoutParameter instance.
---@return ccui.RelativeLayoutParameter # A initialized LayoutParameter which is marked as "autorelease".
function RelativeLayoutParameter.create() end

---Get RelativeAlign parameter for LayoutParameter.
---
---\see RelativeAlign
---@return ccui.RelativeLayoutParameter.RelativeAlign # A RelativeAlign variable.
function RelativeLayoutParameter:getAlign() end

---Get a name of LayoutParameter in Relative Layout.
---
---@return string # name Relative name in string.
function RelativeLayoutParameter:getRelativeName() end

---Get the relative widget name.
---@return string # name A relative widget name in string.
function RelativeLayoutParameter:getRelativeToWidgetName() end

---Default constructor
---
---\lua new
---@return ccui.RelativeLayoutParameter
function RelativeLayoutParameter.new() end

---Sets RelativeAlign parameter for LayoutParameter.
---
---\see RelativeAlign
---@param align ccui.RelativeLayoutParameter.RelativeAlign # Relative align in  `RelativeAlign`.
function RelativeLayoutParameter:setAlign(align) end

---Set a name for LayoutParameter in Relative Layout.
---
---@param name string # A string name.
function RelativeLayoutParameter:setRelativeName(name) end

---Set widget name your widget want to relative to.
---
---@param name string # Relative widget name.
function RelativeLayoutParameter:setRelativeToWidgetName(name) end

return RelativeLayoutParameter