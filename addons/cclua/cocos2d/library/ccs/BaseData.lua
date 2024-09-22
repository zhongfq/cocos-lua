---AUTO GENERATED, DO NOT MODIFY!
---@meta ccs.BaseData

---The base node include a lot of attributes.
---\js NA
---\lua NA
---@class ccs.BaseData : cc.Ref
---@field color any 
---@field x number
---@field y number
---@field zOrder integer
---@field skewX number
---@field skewY number
---@field scaleX number
---@field scaleY number
---@field tweenRotate number
---@field isUseColorInfo boolean
---@field a integer
---@field r integer
---@field g integer
---@field b integer
local BaseData = {}

---@param node ccs.BaseData
function BaseData:copy(node) end

---@return ccs.BaseData
function BaseData.create() end

---@return any
function BaseData:getColor() end

---\js ctor
---@return ccs.BaseData
function BaseData.new() end

---@param color any
function BaseData:setColor(color) end

---@param from ccs.BaseData
---@param to ccs.BaseData
---@param limit boolean
function BaseData:subtract(from, to, limit) end

return BaseData