---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.AffineTransform

---\{
---Affine transform
---a   b    0
---c   d    0
---tx  ty   1
---
---Identity
---1   0    0
---0   1    0
---0   0    1
---@class cc.AffineTransform 
---@field a number
---@field b number
---@field c number
---@field d number
---@field tx number
---@field ty number
---@field IDENTITY cc.AffineTransform
local AffineTransform = {}

---@return any
function AffineTransform:__gc() end

return AffineTransform