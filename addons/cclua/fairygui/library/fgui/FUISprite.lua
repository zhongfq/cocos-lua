---AUTO GENERATED, DO NOT MODIFY!
---@meta fgui.FUISprite

---
---@class fgui.FUISprite : cc.Sprite
---@field fillAmount number 
---@field fillClockwise boolean 
---@field fillMethod fgui.FillMethod 
---@field fillOrigin fgui.FillOrigin 
---@field scaleByTile boolean 
local FUISprite = {}

function FUISprite:clearContent() end

---@return fgui.FUISprite
function FUISprite.create() end

---@return number
function FUISprite:getFillAmount() end

---@return fgui.FillMethod
function FUISprite:getFillMethod() end

---@return fgui.FillOrigin
function FUISprite:getFillOrigin() end

---@return boolean
function FUISprite:isFillClockwise() end

---@return boolean
function FUISprite:isScaleByTile() end

---@return fgui.FUISprite
function FUISprite.new() end

---@param value number
function FUISprite:setFillAmount(value) end

---@param value boolean
function FUISprite:setFillClockwise(value) end

---@param value fgui.FillMethod
function FUISprite:setFillMethod(value) end

---@param value fgui.FillOrigin
function FUISprite:setFillOrigin(value) end

---@param value boolean
function FUISprite:setGrayed(value) end

---@param value cc.Rect
function FUISprite:setScale9Grid(value) end

---@param value boolean
function FUISprite:setScaleByTile(value) end

return FUISprite