---AUTO GENERATED, DO NOT MODIFY!
---@meta ccb.TextureBackend

---A base texture
---@class ccb.TextureBackend : cc.Ref
---@field textureFormat ccb.PixelFormat Get texture format. \return Texture format.
---@field textureType ccb.TextureType Get texture type. Symbolic constant value can be either TEXTURE_2D or TEXTURE_CUBE. \return Texture type.
---@field textureUsage ccb.TextureUsage Get texture usage. Symbolic constant can be READ, WRITE or RENDER_TARGET. \return Texture usage.
local TextureBackend = {}

---Generate mipmaps.
function TextureBackend:generateMipmaps() end

---Read a block of pixels from the drawable texture
---@param x integer # ,y Specify the window coordinates of the first pixel that is read from the drawable texture. This location is the lower left corner of a rectangular block of pixels.
---@param width integer # ,height Specify the dimensions of the pixel rectangle. width and height of one correspond to a single pixel.
---@param flipImage boolean # Specifies if needs to flip the image.
---@param callback fun(arg1: string, arg2: integer, arg3: integer) # Specifies a call back function to deal with the image.
---@param y integer
---@param height integer
function TextureBackend:getBytes(x, y, width, height, flipImage, callback) end

---Get texture format.
---@return ccb.PixelFormat # Texture format.
function TextureBackend:getTextureFormat() end

---Get texture type. Symbolic constant value can be either TEXTURE_2D or TEXTURE_CUBE.
---@return ccb.TextureType # Texture type.
function TextureBackend:getTextureType() end

---Get texture usage. Symbolic constant can be READ, WRITE or RENDER_TARGET.
---@return ccb.TextureUsage # Texture usage.
function TextureBackend:getTextureUsage() end

---Check if mipmap had generated before.
---@return boolean # true if the mipmap has always generated before, otherwise false.
function TextureBackend:hasMipmaps() end

---Update sampler
---@param sampler ccb.SamplerDescriptor # Specifies the sampler descriptor.
function TextureBackend:updateSamplerDescriptor(sampler) end

---Update texture description.
---@param descriptor ccb.TextureDescriptor # Specifies texture and sampler descriptor.
function TextureBackend:updateTextureDescriptor(descriptor) end

return TextureBackend