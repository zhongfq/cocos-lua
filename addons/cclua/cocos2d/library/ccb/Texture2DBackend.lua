---AUTO GENERATED, DO NOT MODIFY!
---@meta ccb.Texture2DBackend

---A 2D texture.
---@class ccb.Texture2DBackend : ccb.TextureBackend
---@field height integer Get texture height. \return Texture height.
---@field width integer Get texture width. \return Texture width.
local Texture2DBackend = {}

---Get texture height.
---@return integer # Texture height.
function Texture2DBackend:getHeight() end

---Get texture width.
---@return integer # Texture width.
function Texture2DBackend:getWidth() end

---Update a two-dimensional texture image in a compressed format
---@param data olua.uint8 # Specifies a pointer to the compressed image data in memory.
---@param width integer # Specifies the width of the texture image.
---@param height integer # Specifies the height of the texture image.
---@param dataLen integer # Specifies the totoal size of compressed image in bytes.
---@param level integer # Specifies the level-of-detail number. Level 0 is the base image level. Level n is the nth mipmap reduction image.
function Texture2DBackend:updateCompressedData(data, width, height, dataLen, level) end

---Update a two-dimensional texture subimage in a compressed format
---@param xoffset integer # Specifies a texel offset in the x direction within the texture array.
---@param yoffset integer # Specifies a texel offset in the y direction within the texture array.
---@param width integer # Specifies the width of the texture subimage.
---@param height integer # Specifies the height of the texture subimage.
---@param dataLen integer # Specifies the totoal size of compressed subimage in bytes.
---@param level integer # Specifies the level-of-detail number. Level 0 is the base image level. Level n is the nth mipmap reduction image.
---@param data olua.uint8 # Specifies a pointer to the compressed image data in memory.
function Texture2DBackend:updateCompressedSubData(xoffset, yoffset, width, height, dataLen, level, data) end

---Update a two-dimensional texture image
---@param data olua.uint8 # Specifies a pointer to the image data in memory.
---@param width integer # Specifies the width of the texture image.
---@param height integer # Specifies the height of the texture image.
---@param level integer # Specifies the level-of-detail number. Level 0 is the base image level. Level n is the nth mipmap reduction image.
function Texture2DBackend:updateData(data, width, height, level) end

---Update a two-dimensional texture subimage
---@param xoffset integer # Specifies a texel offset in the x direction within the texture array.
---@param yoffset integer # Specifies a texel offset in the y direction within the texture array.
---@param width integer # Specifies the width of the texture subimage.
---@param height integer # Specifies the height of the texture subimage.
---@param level integer # Specifies the level-of-detail number. Level 0 is the base image level. Level n is the nth mipmap reduction image.
---@param data olua.uint8 # Specifies a pointer to the image data in memory.
function Texture2DBackend:updateSubData(xoffset, yoffset, width, height, level, data) end

return Texture2DBackend