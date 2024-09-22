---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.FontAtlas

---
---@class cc.FontAtlas : cc.Ref
---@field fontName string 
---@field lineHeight number 
---@field CMD_PURGE_FONTATLAS string
---@field CMD_RESET_FONTATLAS string
---@field CacheTextureHeight integer
---@field CacheTextureWidth integer
local FontAtlas = {}

---@param texture cc.Texture2D
---@param slot integer
function FontAtlas:addTexture(texture, slot) end

---@return string
function FontAtlas:getFontName() end

---@return number
function FontAtlas:getLineHeight() end

---@param slot integer
---@return cc.Texture2D
function FontAtlas:getTexture(slot) end

---listen the event that renderer was recreated on Android/WP8
---It only has effect on Android and WP8.
---@param event cc.EventCustom
function FontAtlas:listenRendererRecreated(event) end

---Removes textures atlas.
---It will purge the textures atlas and if multiple texture exist in the FontAtlas.
function FontAtlas:purgeTexturesAtlas() end

---sets font texture parameters:
---- GL_TEXTURE_MIN_FILTER = GL_NEAREST
---- GL_TEXTURE_MAG_FILTER = GL_NEAREST
function FontAtlas:setAliasTexParameters() end

---sets font texture parameters:
---- GL_TEXTURE_MIN_FILTER = GL_LINEAR
---- GL_TEXTURE_MAG_FILTER = GL_LINEAR
function FontAtlas:setAntiAliasTexParameters() end

---@param newHeight number
function FontAtlas:setLineHeight(newHeight) end

return FontAtlas