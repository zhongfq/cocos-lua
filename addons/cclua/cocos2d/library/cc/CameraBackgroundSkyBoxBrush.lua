---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.CameraBackgroundSkyBoxBrush

---Skybox brush clear buffer with a skybox
---@class cc.CameraBackgroundSkyBoxBrush : cc.CameraBackgroundBrush
---@field actived boolean 
local CameraBackgroundSkyBoxBrush = {}

---Creates a Skybox brush with 6 textures.
---@param positive_x string # texture for the right side of the texture cube face.
---@param negative_x string # texture for the up side of the texture cube face.
---@param positive_y string # texture for the top side of the texture cube face
---@param negative_y string # texture for the bottom side of the texture cube face
---@param positive_z string # texture for the forward side of the texture cube face.
---@param negative_z string # texture for the rear side of the texture cube face.
---@return cc.CameraBackgroundSkyBoxBrush # A new brush inited with given parameters.
---
---Creates a Skybox brush with 6 textures.
---@overload fun(): cc.CameraBackgroundSkyBoxBrush
function CameraBackgroundSkyBoxBrush.create(positive_x, negative_x, positive_y, negative_y, positive_z, negative_z) end

---@return boolean
function CameraBackgroundSkyBoxBrush:isActived() end

---@return cc.CameraBackgroundSkyBoxBrush
function CameraBackgroundSkyBoxBrush.new() end

---@param actived boolean
function CameraBackgroundSkyBoxBrush:setActived(actived) end

---Set skybox texture 
---@param texture cc.TextureCube # Skybox texture
function CameraBackgroundSkyBoxBrush:setTexture(texture) end

---@param valid boolean
function CameraBackgroundSkyBoxBrush:setTextureValid(valid) end

return CameraBackgroundSkyBoxBrush