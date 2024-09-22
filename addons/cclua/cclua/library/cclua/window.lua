---AUTO GENERATED, DO NOT MODIFY!
---@meta cclua.window

---
---@class cclua.window 
---@field designSize cc.Size 
---@field frameSize cc.Size 
---@field visibleBounds cc.Bounds 
---@field visibleSize cc.Size 
local window = {}

---@return any
function window:__gc() end

---@param position cc.Vec2
---@return cc.Vec2
---@overload fun(x: number, y: number): number, number
function window.convertToCameraSpace(position) end

---@return number, number
function window.getDesignSize() end

---@return number, number
function window.getFrameSize() end

---@return number, number, number, number
function window.getVisibleBounds() end

---@return number, number
function window.getVisibleSize() end

---@param size cc.Size
---@param resolutionPolicy cc.ResolutionPolicy
---@overload fun(width: number, height: number, resolutionPolicy: cc.ResolutionPolicy)
function window.setDesignSize(size, resolutionPolicy) end

---@param size cc.Size
---@overload fun(width: number, height: number)
function window.setFrameSize(size) end

return window