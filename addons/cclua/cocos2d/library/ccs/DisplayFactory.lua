---AUTO GENERATED, DO NOT MODIFY!
---@meta ccs.DisplayFactory

---\js NA
---\lua NA
---@class ccs.DisplayFactory 
local DisplayFactory = {}

---@return any
function DisplayFactory:__gc() end

---@param bone ccs.Bone
---@param decoDisplay ccs.DecorativeDisplay
---@param displayData ccs.DisplayData
function DisplayFactory.addArmatureDisplay(bone, decoDisplay, displayData) end

---@param bone ccs.Bone
---@param decoDisplay ccs.DecorativeDisplay
---@param displayData ccs.DisplayData
function DisplayFactory.addDisplay(bone, decoDisplay, displayData) end

---@param bone ccs.Bone
---@param decoDisplay ccs.DecorativeDisplay
---@param displayData ccs.DisplayData
function DisplayFactory.addParticleDisplay(bone, decoDisplay, displayData) end

---@param bone ccs.Bone
---@param decoDisplay ccs.DecorativeDisplay
---@param displayData ccs.DisplayData
function DisplayFactory.addSpriteDisplay(bone, decoDisplay, displayData) end

---@param bone ccs.Bone
---@param decoDisplay ccs.DecorativeDisplay
function DisplayFactory.createArmatureDisplay(bone, decoDisplay) end

---@param bone ccs.Bone
---@param decoDisplay ccs.DecorativeDisplay
function DisplayFactory.createDisplay(bone, decoDisplay) end

---@param bone ccs.Bone
---@param decoDisplay ccs.DecorativeDisplay
function DisplayFactory.createParticleDisplay(bone, decoDisplay) end

---@param bone ccs.Bone
---@param decoDisplay ccs.DecorativeDisplay
function DisplayFactory.createSpriteDisplay(bone, decoDisplay) end

---@param bone ccs.Bone
---@param decoDisplay ccs.DecorativeDisplay
---@param displayName string
---@param skin ccs.Skin
function DisplayFactory.initSpriteDisplay(bone, decoDisplay, displayName, skin) end

---@param bone ccs.Bone
---@param display cc.Node
---@param dt number
function DisplayFactory.updateArmatureDisplay(bone, display, dt) end

---@param bone ccs.Bone
---@param dt number
---@param dirty boolean
function DisplayFactory.updateDisplay(bone, dt, dirty) end

---@param bone ccs.Bone
---@param display cc.Node
---@param dt number
function DisplayFactory.updateParticleDisplay(bone, display, dt) end

return DisplayFactory