---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.Size

---\addtogroup base
---\{
---@class cc.Size 
---@field width number
---@field height number
---@field ZERO cc.Size
---@operator add(cc.Size):cc.Size
---@operator div(number):cc.Size
---@operator mul(number):cc.Size
---@operator sub(cc.Size):cc.Size
local Size = {}

---\js NA
---\lua NA
---@param right cc.Size
---@return cc.Size
function Size:__add(right) end

---\js NA
---\lua NA
---@param a number
---@return cc.Size
function Size:__div(a) end

---@return any
function Size:__gc() end

---\js NA
---\lua NA
---@param a number
---@return cc.Size
function Size:__mul(a) end

---\js NA
---\lua NA
---@param right cc.Size
---@return cc.Size
function Size:__sub(right) end

---Check if two size is the same.
---\js NA
---@param target cc.Size
---@return boolean
function Size:equals(target) end

---\{
---Constructor.
---\param width Width of the size.
---\param height Height of the size.
---\param other Copy constructor.
---\param point Conversion from a point.
---@return cc.Size
---@overload fun(width: number, height: number): cc.Size
---@overload fun(point: cc.Vec2): cc.Size
function Size.new() end

---Set the width and height of Size.
---\js NA
---\lua NA
---@param width number
---@param height number
function Size:setSize(width, height) end

return Size