---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.TextureProtocol

---Node objects that uses a Texture2D to render the images.
---The texture can have a blending function.
---If the texture has alpha premultiplied the default blending function is:
---src=BlendFactor::ONE dst= BlendFactor::ONE_MINUS_SRC_ALPHA
---else
---src=BlendFactor::SRC_ALPHA dst= BlendFactor::ONE_MINUS_SRC_ALPHA
---But you can change the blending function at any time.
---@class cc.TextureProtocol : cc.BlendProtocol
---@field texture cc.Texture2D Returns the currently used texture <br><br>\return  The texture that is currently being used. \js NA \lua NA
local TextureProtocol = {}

---Returns the currently used texture
---
---@return cc.Texture2D # The texture that is currently being used.
---\js NA
---\lua NA
function TextureProtocol:getTexture() end

---Sets a new texture. It will be retained.
---
---@param texture cc.Texture2D # A valid Texture2D object, which will be applied to this sprite object.
---\js NA
---\lua NA
function TextureProtocol:setTexture(texture) end

return TextureProtocol