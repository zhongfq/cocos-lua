---AUTO GENERATED, DO NOT MODIFY!
---@meta ccb.TextureCubemapBackend

---A cubemap texture.
---@class ccb.TextureCubemapBackend : ccb.TextureBackend
local TextureCubemapBackend = {}

---Update texutre cube data in give slice side.
---@param side ccb.TextureCubeFace # Specifies which slice texture of cube to be update.
---@param data any # Specifies a pointer to the image data in memory.
function TextureCubemapBackend:updateFaceData(side, data) end

return TextureCubemapBackend