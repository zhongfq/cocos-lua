---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.ParticleSystemQuad

---\class ParticleSystemQuad
---ParticleSystemQuad is a subclass of ParticleSystem.
---
---It includes all the features of ParticleSystem.
---
---Special features and Limitations:    
---- Particle size can be any float number.
---- The system can be scaled.
---- The particles can be rotated.
---- It supports subrects.
---- It supports batched rendering since 1.1.
---\since v0.8
---\js NA
---@class cc.ParticleSystemQuad : cc.ParticleSystem
local ParticleSystemQuad = {}

---Creates a Particle Emitter.
---
---@return cc.ParticleSystemQuad # An autoreleased ParticleSystemQuad object.
---
---Creates an initializes a ParticleSystemQuad from a plist file.
---This plist files can be created manually or with Particle Designer.
---
---\param filename Particle plist file name.
---\return An autoreleased ParticleSystemQuad object.
---@overload fun(filename: string): cc.ParticleSystemQuad
---
---Creates a Particle Emitter with a dictionary.
---
---\param dictionary Particle dictionary.
---\return An autoreleased ParticleSystemQuad object.
---@overload fun(dictionary: cc.types.ValueMap): cc.ParticleSystemQuad
function ParticleSystemQuad.create() end

---Creates a Particle Emitter with a number of particles.
---
---@param numberOfParticles integer # A given number of particles.
---@return cc.ParticleSystemQuad # An autoreleased ParticleSystemQuad object.
function ParticleSystemQuad.createWithTotalParticles(numberOfParticles) end

---Listen the event that renderer was recreated on Android/WP8.
---\js NA
---\lua NA
---
---@param event cc.EventCustom # the event that renderer was recreated on Android/WP8.
function ParticleSystemQuad:listenRendererRecreated(event) end

---\js ctor
---@return cc.ParticleSystemQuad
function ParticleSystemQuad.new() end

---Sets a new SpriteFrame as particle.
---WARNING: this method is experimental. Use setTextureWithRect instead.
---
---@param spriteFrame cc.SpriteFrame # A given sprite frame as particle texture.
---\since v0.99.4
function ParticleSystemQuad:setDisplayFrame(spriteFrame) end

---Sets a new texture with a rect. The rect is in Points.
---\since v0.99.4
---\js NA
---\lua NA
---
---@param texture cc.Texture2D # A given texture.
---8 @param rect A given rect, in points.
---@param rect cc.Rect
function ParticleSystemQuad:setTextureWithRect(texture, rect) end

return ParticleSystemQuad