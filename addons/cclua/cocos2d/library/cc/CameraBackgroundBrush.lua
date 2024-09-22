---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.CameraBackgroundBrush

---Defines a brush to clear the background of camera.
---There are 4 types of brush. None brush do nothing, Depth brush clear background with given depth, Color brush clear background with given color and depth, Skybox brush clear the background with a skybox. Camera uses depth brush by default.
---@class cc.CameraBackgroundBrush : cc.Ref
---@field brushType cc.CameraBackgroundBrush.BrushType get brush type \return BrushType
---@field valid boolean 
local CameraBackgroundBrush = {}

---Creates a color brush
---@param color any # Color of brush
---@param depth number # Depth used to clear depth buffer
---@return cc.CameraBackgroundColorBrush # Created brush
function CameraBackgroundBrush.createColorBrush(color, depth) end

---Creates a depth brush, which clears depth buffer with a given depth.
---@param depth number # Depth used to clear depth buffer
---@return cc.CameraBackgroundDepthBrush # Created brush
---@overload fun(): cc.CameraBackgroundDepthBrush
function CameraBackgroundBrush.createDepthBrush(depth) end

---Creates a none brush, it does nothing when clear the background
---@return cc.CameraBackgroundBrush # Created brush.
function CameraBackgroundBrush.createNoneBrush() end

---Creates a Skybox brush with 6 textures.
---@param positive_x string # texture for the right side of the texture cube face.
---@param negative_x string # texture for the up side of the texture cube face.
---@param positive_y string # texture for the top side of the texture cube face
---@param negative_y string # texture for the bottom side of the texture cube face
---@param positive_z string # texture for the forward side of the texture cube face.
---@param negative_z string # texture for the rear side of the texture cube face.
---@return cc.CameraBackgroundSkyBoxBrush # A new brush inited with given parameters.
function CameraBackgroundBrush.createSkyboxBrush(positive_x, negative_x, positive_y, negative_y, positive_z, negative_z) end

---draw the background
---@param arg1 cc.Camera
function CameraBackgroundBrush:drawBackground(arg1) end

---get brush type
---@return cc.CameraBackgroundBrush.BrushType # BrushType
function CameraBackgroundBrush:getBrushType() end

---@return boolean
function CameraBackgroundBrush:init() end

---@return boolean
function CameraBackgroundBrush:isValid() end

---@return cc.CameraBackgroundBrush
function CameraBackgroundBrush.new() end

return CameraBackgroundBrush