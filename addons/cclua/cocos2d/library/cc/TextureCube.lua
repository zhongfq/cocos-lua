---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.TextureCube

---\addtogroup _3d
---\{
---@class cc.TextureCube : cc.Ref
---@field backendTexture ccb.TextureBackend 
local TextureCube = {}

---create cube texture from 6 textures.
---@param positive_x string # texture for the right side of the texture cube face.
---@param negative_x string # texture for the up side of the texture cube face.
---@param positive_y string # texture for the top side of the texture cube face
---@param negative_y string # texture for the bottom side of the texture cube face
---@param positive_z string # texture for the forward side of the texture cube face.
---@param negative_z string # texture for the rear side of the texture cube face.
---@return cc.TextureCube # A new texture cube inited with given parameters.
function TextureCube.create(positive_x, negative_x, positive_y, negative_y, positive_z, negative_z) end

---@return ccb.TextureBackend
function TextureCube:getBackendTexture() end

---Constructor.
---@return cc.TextureCube
function TextureCube.new() end

---reload texture cube after GLESContext reconstructed.
---@return boolean
function TextureCube:reloadTexture() end

---Sets the min filter, mag filter, wrap s and wrap t texture parameters.
---If the texture size is NPOT (non power of 2), then in can only use GL_CLAMP_TO_EDGE in GL_TEXTURE_WRAP_{S,T}.
---@param arg1 ccb.SamplerDescriptor
function TextureCube:setTexParameters(arg1) end

return TextureCube