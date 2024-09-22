---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.BlendProtocol

---Specify the blending function according glBlendFunc
---Please refer to glBlendFunc in OpenGL ES Manual
---http://www.khronos.org/opengles/sdk/docs/man/xhtml/glBlendFunc.xml for more details.
---@class cc.BlendProtocol 
---@field blendFunc cc.BlendFunc Returns the blending function that is currently being used. <br><br>\return A BlendFunc structure with source and destination factor which specified pixel arithmetic. \js NA \lua NA
local BlendProtocol = {}

---@return any
function BlendProtocol:__gc() end

---Returns the blending function that is currently being used.
---
---@return cc.BlendFunc # A BlendFunc structure with source and destination factor which specified pixel arithmetic.
---\js NA
---\lua NA
function BlendProtocol:getBlendFunc() end

---Sets the source blending function.
---
---@param blendFunc cc.BlendFunc # A structure with source and destination factor to specify pixel arithmetic, 
---e.g. {BlendFactor::ONE, BlendFactor::ONE}, {BlendFactor::SRC_ALPHA, BlendFactor::ONE_MINUS_SRC_ALPHA}.
---\js NA
---\lua NA
function BlendProtocol:setBlendFunc(blendFunc) end

return BlendProtocol