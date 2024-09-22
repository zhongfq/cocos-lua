---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.ParticleBatchNode

---\class ParticleBatchNode
---ParticleBatchNode is like a batch node: if it contains children, it will draw them in 1 single OpenGL call
---(often known as "batch draw").
---
---A ParticleBatchNode can reference one and only one texture (one image file, one texture atlas).
---Only the ParticleSystems that are contained in that texture can be added to the SpriteBatchNode.
---All ParticleSystems added to a SpriteBatchNode are drawn in one OpenGL ES draw call.
---If the ParticleSystems are not added to a ParticleBatchNode then an OpenGL ES draw call will be needed for each one, which is less efficient.
---
---
---Limitations:
---- At the moment only ParticleSystemQuad is supported
---- All systems need to be drawn with the same parameters, blend function, aliasing, texture
---
---Most efficient usage
---- Initialize the ParticleBatchNode with the texture and enough capacity for all the particle systems
---- Initialize all particle systems and add them as child to the batch node
---\since v1.1
---@class cc.ParticleBatchNode : cc.Node
---@field blendFunc cc.BlendFunc \js NA \lua NA
---@field texture cc.Texture2D 
---@field textureAtlas cc.TextureAtlas Gets the texture atlas used for drawing the quads. <br><br>\return The texture atlas used for drawing the quads.
local ParticleBatchNode = {}

---@param cls string
---@return any
function ParticleBatchNode:as(cls) end

---Create the particle system with the name of a file on disk (for a list of supported formats look at the Texture2D class), a capacity of particles.
---
---@param fileImage string # A given file name.
---@param capacity integer # A capacity of particles.
---@return cc.ParticleBatchNode # An autoreleased ParticleBatchNode object.
---@overload fun(fileImage: string): cc.ParticleBatchNode
function ParticleBatchNode.create(fileImage, capacity) end

---Create the particle system with Texture2D, a capacity of particles, which particle system to use.
---
---@param tex cc.Texture2D # A given texture.
---@param capacity integer # A capacity of particles.
---@return cc.ParticleBatchNode # An autoreleased ParticleBatchNode object.
---\js NA
---@overload fun(tex: cc.Texture2D): cc.ParticleBatchNode
function ParticleBatchNode.createWithTexture(tex, capacity) end

---Disables a particle by inserting a 0'd quad into the texture atlas.
---
---@param particleIndex integer # The index of the particle.
function ParticleBatchNode:disableParticle(particleIndex) end

---\js NA
---\lua NA
---@return cc.BlendFunc
function ParticleBatchNode:getBlendFunc() end

---@return cc.Texture2D
function ParticleBatchNode:getTexture() end

---Gets the texture atlas used for drawing the quads.
---
---@return cc.TextureAtlas # The texture atlas used for drawing the quads.
function ParticleBatchNode:getTextureAtlas() end

---initializes the particle system with the name of a file on disk (for a list of supported formats look at the Texture2D class), a capacity of particles
---@param fileImage string
---@param capacity integer
---@return boolean
function ParticleBatchNode:initWithFile(fileImage, capacity) end

---initializes the particle system with Texture2D, a capacity of particles
---@param tex cc.Texture2D
---@param capacity integer
---@return boolean
function ParticleBatchNode:initWithTexture(tex, capacity) end

---Inserts a child into the ParticleBatchNode.
---
---@param system cc.ParticleSystem # A given particle system.
---@param index integer # The insert index.
function ParticleBatchNode:insertChild(system, index) end

---\js ctor
---@return cc.ParticleBatchNode
function ParticleBatchNode.new() end

---Remove a child of the ParticleBatchNode.
---
---@param index integer # The index of the child.
---@param doCleanup boolean # True if all actions and callbacks on this node should be removed, false otherwise.
function ParticleBatchNode:removeChildAtIndex(index, doCleanup) end

---\code
---When this function bound into js or lua,the parameter will be changed
---In js: var setBlendFunc(var src, var dst)
---\endcode
---\lua NA
---@param blendFunc cc.BlendFunc
function ParticleBatchNode:setBlendFunc(blendFunc) end

---@param texture cc.Texture2D
function ParticleBatchNode:setTexture(texture) end

---Sets the texture atlas used for drawing the quads.
---
---@param atlas cc.TextureAtlas # The texture atlas used for drawing the quads.
function ParticleBatchNode:setTextureAtlas(atlas) end

return ParticleBatchNode