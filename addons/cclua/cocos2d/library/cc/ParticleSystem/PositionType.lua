---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.ParticleSystem.PositionType

---@type cc.ParticleSystem.PositionType
local VALUE

---
---@enum cc.ParticleSystem.PositionType
local PositionType = {
    FREE = 0,
    ---Living particles are attached to the world but will follow the emitter repositioning.
    ---Use case: Attach an emitter to an sprite, and you want that the emitter follows the sprite.
    GROUPED = 2,
    ---Living particles are attached to the world and are unaffected by emitter repositioning.
    RELATIVE = 1,
}

return PositionType