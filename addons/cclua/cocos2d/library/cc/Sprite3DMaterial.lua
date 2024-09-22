---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.Sprite3DMaterial

---Sprite3DMaterial: Material for Sprite3D.
---@class cc.Sprite3DMaterial : cc.Material
---@field materialType cc.Sprite3DMaterial.MaterialType Get material type \return Material type
local Sprite3DMaterial = {}

---Create built in material from material type
---@param type cc.Sprite3DMaterial.MaterialType # Material type
---@param skinned boolean # Has skin?
---@return cc.Sprite3DMaterial # Created material
---
---Create all build in materials
---@overload fun()
function Sprite3DMaterial.createBuiltInMaterial(type, skinned) end

---Create material with file name, it creates material from cache if it is previously loaded
---@param path string # Path of material file
---@return cc.Sprite3DMaterial # Created material
function Sprite3DMaterial.createWithFilename(path) end

---@param programState ccb.ProgramState
---@return cc.Sprite3DMaterial
function Sprite3DMaterial.createWithProgramState(programState) end

---Get material type
---@return cc.Sprite3DMaterial.MaterialType # Material type
function Sprite3DMaterial:getMaterialType() end

---Release all built in materials
function Sprite3DMaterial.releaseBuiltInMaterial() end

---Release all cached materials
function Sprite3DMaterial.releaseCachedMaterial() end

---@param tex cc.Texture2D
---@param usage cc.NTextureData.Usage
function Sprite3DMaterial:setTexture(tex, usage) end

return Sprite3DMaterial