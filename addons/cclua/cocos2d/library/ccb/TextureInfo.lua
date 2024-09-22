---AUTO GENERATED, DO NOT MODIFY!
---@meta ccb.TextureInfo

---Store texture information.
---@class ccb.TextureInfo 
---@field slot integer[]
---@field textures ccb.TextureBackend[]
local TextureInfo = {}

---@return any
function TextureInfo:__gc() end

---@param _slots integer[]
---@param _textures ccb.TextureBackend[]
---@return ccb.TextureInfo
---@overload fun(): ccb.TextureInfo
function TextureInfo.new(_slots, _textures) end

function TextureInfo:releaseTextures() end

function TextureInfo:retainTextures() end

return TextureInfo