---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.BillBoard

---Inherit from Sprite, achieve BillBoard.
---@class cc.BillBoard : cc.Sprite
---@field mode cc.BillBoard.Mode Get the billboard rotation mode.
local BillBoard = {}

---Creates an empty BillBoard without texture. You can call setTexture method subsequently.
---
---@return cc.BillBoard # An autoreleased BillBoard object.
---@param mode cc.BillBoard.Mode
---@overload fun(): cc.BillBoard
---
---Creates a BillBoard with an image filename.
---
---After creation, the rect of BillBoard will be the size of the image,
---and the offset will be (0,0).
---
---\param   filename A path to image file, e.g., "scene1/monster.png"
---\return  An autoreleased BillBoard object.
---@overload fun(filename: string, mode: cc.BillBoard.Mode): cc.BillBoard
---
---Creates a BillBoard with an image filename.
---
---After creation, the rect of BillBoard will be the size of the image,
---and the offset will be (0,0).
---
---\param   filename A path to image file, e.g., "scene1/monster.png"
---\return  An autoreleased BillBoard object.
---@overload fun(filename: string): cc.BillBoard
---
---Creates a BillBoard with an image filename and a rect.
---
---\param   filename A path to image file, e.g., "scene1/monster.png"
---\param   rect     A subrect of the image file
---\return  An autoreleased BillBoard object
---@overload fun(filename: string, rect: cc.Rect, mode: cc.BillBoard.Mode): cc.BillBoard
---
---Creates a BillBoard with an image filename and a rect.
---
---\param   filename A path to image file, e.g., "scene1/monster.png"
---\param   rect     A subrect of the image file
---\return  An autoreleased BillBoard object
---@overload fun(filename: string, rect: cc.Rect): cc.BillBoard
function BillBoard.create(mode) end

---Creates a BillBoard with a Texture2D object.
---
---After creation, the rect will be the size of the texture, and the offset will be (0,0).
---
---@param texture cc.Texture2D # A pointer to a Texture2D object.
---@return cc.BillBoard # An autoreleased BillBoard object
---@param mode cc.BillBoard.Mode
---@overload fun(texture: cc.Texture2D): cc.BillBoard
function BillBoard.createWithTexture(texture, mode) end

---Get the billboard rotation mode.
---@return cc.BillBoard.Mode
function BillBoard:getMode() end

---@return cc.BillBoard
function BillBoard.new() end

---Set the billboard rotation mode.
---@param mode cc.BillBoard.Mode
function BillBoard:setMode(mode) end

return BillBoard