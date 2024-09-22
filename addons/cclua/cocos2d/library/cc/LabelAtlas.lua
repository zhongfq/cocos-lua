---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.LabelAtlas

---\addtogroup base
---\{
---@class cc.LabelAtlas : cc.AtlasNode
---@field string string 
local LabelAtlas = {}

---@param cls string
---@return any
function LabelAtlas:as(cls) end

---Creates an empty LabelAtlas.
---User need to call initWithString(...) later to make this object work properly.
---@return cc.LabelAtlas
---
---Creates the LabelAtlas with a string, a char map file(the atlas), the width and height of each element and the starting char of the atlas.
---@overload fun(string: string, charMapFile: string, itemWidth: integer, itemHeight: integer, startCharMap: integer): cc.LabelAtlas
---
---Creates the LabelAtlas with a string and a configuration file.
---\since v2.0
---@overload fun(string: string, fntFile: string): cc.LabelAtlas
function LabelAtlas.create() end

---@return string
function LabelAtlas:getString() end

---Initializes the LabelAtlas with a string, a char map file(the atlas), the width and height of each element and the starting char of the atlas.
---@param string string
---@param charMapFile string
---@param itemWidth integer
---@param itemHeight integer
---@param startCharMap integer
---@return boolean
---
---Initializes the LabelAtlas with a string and a configuration file.
---\since v2.0
---@overload fun(self: cc.LabelAtlas, string: string, fntFile: string): boolean
---
---Initializes the LabelAtlas with a string, a texture, the width and height in points of each element and the starting char of the atlas
---@overload fun(self: cc.LabelAtlas, string: string, texture: cc.Texture2D, itemWidth: integer, itemHeight: integer, startCharMap: integer): boolean
function LabelAtlas:initWithString(string, charMapFile, itemWidth, itemHeight, startCharMap) end

---@return cc.LabelAtlas
function LabelAtlas.new() end

---@param label string
function LabelAtlas:setString(label) end

return LabelAtlas