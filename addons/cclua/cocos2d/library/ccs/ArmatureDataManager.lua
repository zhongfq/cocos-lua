---AUTO GENERATED, DO NOT MODIFY!
---@meta ccs.ArmatureDataManager

---format and manage armature configuration and armature animation
---@class ccs.ArmatureDataManager : cc.Ref
---@field animationDatas any 
---@field armatureDatas any 
---@field autoLoadSpriteFile boolean Judge whether or not need auto load sprite file
---@field instance ccs.ArmatureDataManager 
---@field textureDatas any 
local ArmatureDataManager = {}

---add animation data
---@param id string # the id of the animation data
---\return AnimationData
---@param animationData ccs.AnimationData
---@param configFilePath string
---@overload fun(self: ccs.ArmatureDataManager, id: string, animationData: ccs.AnimationData)
function ArmatureDataManager:addAnimationData(id, animationData, configFilePath) end

---Add armature data
---@param id string # The id of the armature data
---@param armatureData ccs.ArmatureData # ArmatureData
---@param configFilePath string
---@overload fun(self: ccs.ArmatureDataManager, id: string, armatureData: ccs.ArmatureData)
function ArmatureDataManager:addArmatureData(id, armatureData, configFilePath) end

---Add ArmatureFileInfo, it is managed by ArmatureDataManager.
---@param configFilePath string
---@overload fun(self: ccs.ArmatureDataManager, imagePath: string, plistPath: string, configFilePath: string)
function ArmatureDataManager:addArmatureFileInfo(configFilePath) end

---Add sprite frame to CCSpriteFrameCache, it will save display name and it's relative image name
---@param plistPath string
---@param imagePath string
---@param configFilePath string
---@overload fun(self: ccs.ArmatureDataManager, plistPath: string, imagePath: string)
function ArmatureDataManager:addSpriteFrameFromFile(plistPath, imagePath, configFilePath) end

---add texture data
---@param id string # the id of the texture data
---\return TextureData
---@param textureData ccs.TextureData
---@param configFilePath string
---@overload fun(self: ccs.ArmatureDataManager, id: string, textureData: ccs.TextureData)
function ArmatureDataManager:addTextureData(id, textureData, configFilePath) end

function ArmatureDataManager.destroyInstance() end

---get animation data from _animationDatas(Dictionary)
---@param id string # the id of the animation data you want to get
---@return ccs.AnimationData # AnimationData
function ArmatureDataManager:getAnimationData(id) end

---@return any
function ArmatureDataManager:getAnimationDatas() end

---get armature data
---@param id string # the id of the armature data you want to get
---@return ccs.ArmatureData # ArmatureData
function ArmatureDataManager:getArmatureData(id) end

---@return any
function ArmatureDataManager:getArmatureDatas() end

---@return ccs.ArmatureDataManager
function ArmatureDataManager.getInstance() end

---get texture data
---@param id string # the id of the texture data you want to get
---@return ccs.TextureData # TextureData
function ArmatureDataManager:getTextureData(id) end

---@return any
function ArmatureDataManager:getTextureDatas() end

---Init ArmatureDataManager
---@return boolean
function ArmatureDataManager:init() end

---Judge whether or not need auto load sprite file
---@return boolean
function ArmatureDataManager:isAutoLoadSpriteFile() end

---remove animation data
---@param id string # the id of the animation data
function ArmatureDataManager:removeAnimationData(id) end

---remove armature data
---@param id string # the id of the armature data you want to get
function ArmatureDataManager:removeArmatureData(id) end

---@param configFilePath string
function ArmatureDataManager:removeArmatureFileInfo(configFilePath) end

---remove texture data
---@param id string # the id of the texture data you want to get
function ArmatureDataManager:removeTextureData(id) end

return ArmatureDataManager