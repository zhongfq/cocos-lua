---AUTO GENERATED, DO NOT MODIFY!
---@meta fgui.TextFormat

---
---@class fgui.TextFormat 
---@field face string
---@field fontSize number
---@field color any
---@field bold boolean
---@field italics boolean
---@field underline boolean
---@field lineSpacing integer
---@field letterSpacing integer
---@field align cc.TextHAlignment
---@field verticalAlign cc.TextVAlignment
---@field effect integer
---@field outlineColor any
---@field outlineSize integer
---@field shadowColor any
---@field shadowOffset cc.Size
---@field shadowBlurRadius integer
---@field glowColor any
---@field GLOW integer
---@field OUTLINE integer
---@field SHADOW integer
local TextFormat = {}

---@return any
function TextFormat:__gc() end

---@param effectFlag integer
function TextFormat:disableEffect(effectFlag) end

---@param effectFlag integer
function TextFormat:enableEffect(effectFlag) end

---@param effectFlag integer
---@return boolean
function TextFormat:hasEffect(effectFlag) end

---@return fgui.TextFormat
function TextFormat.new() end

---@param format fgui.TextFormat
function TextFormat:setFormat(format) end

return TextFormat