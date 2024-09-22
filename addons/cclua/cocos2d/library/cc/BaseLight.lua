---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.BaseLight

---\js NA
---@class cc.BaseLight : cc.Node
---@field enabled boolean 
---@field intensity number intensity getter and setter
---@field lightFlag cc.LightFlag light flag getter and setter
---@field lightType cc.LightType Get the light type,light type MUST be one of LightType::DIRECTIONAL , LightType::POINT, LightType::SPOT, LightType::AMBIENT.
local BaseLight = {}

---intensity getter and setter
---@return number
function BaseLight:getIntensity() end

---light flag getter and setter
---@return cc.LightFlag
function BaseLight:getLightFlag() end

---Get the light type,light type MUST be one of LightType::DIRECTIONAL ,
---LightType::POINT, LightType::SPOT, LightType::AMBIENT.
---@return cc.LightType
function BaseLight:getLightType() end

---@return boolean
function BaseLight:isEnabled() end

---light enabled getter and setter.
---@param enabled boolean
function BaseLight:setEnabled(enabled) end

---@param intensity number
function BaseLight:setIntensity(intensity) end

---@param flag cc.LightFlag
function BaseLight:setLightFlag(flag) end

return BaseLight