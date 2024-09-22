---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.LabelProtocol

---Common interface for Labels
---@class cc.LabelProtocol 
---@field string string Returns the string that is currently being used in this label  <br><br>\return The string that is currently being used in this label \js NA \lua NA
local LabelProtocol = {}

---@return any
function LabelProtocol:__gc() end

---Returns the string that is currently being used in this label 
---
---@return string # The string that is currently being used in this label
---\js NA
---\lua NA
function LabelProtocol:getString() end

---Sets a new label using a string
---
---@param label string # The name of the new label.
---\js NA
---\lua NA
function LabelProtocol:setString(label) end

return LabelProtocol