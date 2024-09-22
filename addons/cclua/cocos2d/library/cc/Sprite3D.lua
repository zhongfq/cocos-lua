---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.Sprite3D

---Sprite3D: A sprite can be loaded from 3D model files, .obj, .c3t, .c3b, then can be drawn as sprite
---@class cc.Sprite3D : cc.Node
---@field blendFunc cc.BlendFunc 
---@field forceDepthWrite boolean 
---@field lightMask integer 
---@field mesh cc.Mesh get mesh
---@field meshCount integer get mesh count
---@field meshes any Get meshes used in sprite 3d
---@field skeleton cc.Skeleton3D 
local Sprite3D = {}

---@param mesh cc.Mesh
function Sprite3D:addMesh(mesh) end

---@param param any
function Sprite3D:afterAsyncLoad(param) end

---@param cls string
---@return any
function Sprite3D:as(cls) end

---Creates an empty sprite3D without 3D model and texture.
---
---@return cc.Sprite3D # An autoreleased sprite3D object.
---
---creates a Sprite3D
---@overload fun(modelPath: string): cc.Sprite3D
---@overload fun(modelPath: string, texturePath: string): cc.Sprite3D
function Sprite3D.create() end

---create 3d sprite asynchronously
---If the 3d model was previously loaded, it will create a new 3d sprite and the callback will be called at once.
---Otherwise it will load the model file in a new thread, and when the 3d sprite is loaded, the callback will be called with the created Sprite3D and a user-defined parameter.
---The callback will be called from the main thread, so it is safe to create any cocos2d object from the callback.
---@param modelPath string # model to be loaded
---@param callback fun(arg1: cc.Sprite3D, arg2: any) # callback after loading
---@param callbackparam any # user defined parameter for the callback
---@overload fun(modelPath: string, texturePath: string, callback: fun(arg1: cc.Sprite3D, arg2: any), callbackparam: any)
function Sprite3D.createAsync(modelPath, callback, callbackparam) end

---generate default material
---@param useLight boolean
---@overload fun(self: cc.Sprite3D)
function Sprite3D:genMaterial(useLight) end

---get AttachNode by bone name, return nullptr if not exist
---@param boneName string
---@return cc.AttachNode
function Sprite3D:getAttachNode(boneName) end

---@return cc.BlendFunc
function Sprite3D:getBlendFunc() end

---@return integer
function Sprite3D:getLightMask() end

---Adds a new material to a particular mesh of the sprite.
---meshIndex is the mesh that will be applied to.
---if meshIndex == -1, then it will be applied to all the meshes that belong to the sprite.
---@param meshIndex integer
---@return cc.Material
function Sprite3D:getMaterial(meshIndex) end

---get mesh
---@return cc.Mesh
function Sprite3D:getMesh() end

---get mesh array by name, returns all meshes with the given name
---
---\lua NA
---@param name string
---@return cc.Mesh[]
function Sprite3D:getMeshArrayByName(name) end

---get Mesh by index
---@param index integer
---@return cc.Mesh
function Sprite3D:getMeshByIndex(index) end

---get Mesh by Name, it returns the first one if there are more than one mesh with the same name
---@param name string
---@return cc.Mesh
function Sprite3D:getMeshByName(name) end

---get mesh count
---@return integer
function Sprite3D:getMeshCount() end

---Get meshes used in sprite 3d
---@return any
function Sprite3D:getMeshes() end

---@return cc.Skeleton3D
function Sprite3D:getSkeleton() end

---@param path string
---@return boolean
function Sprite3D:initWithFile(path) end

---@return boolean
function Sprite3D:isForceDepthWrite() end

---load sprite3d from cache, return true if succeed, false otherwise
---@param path string
---@return boolean
function Sprite3D:loadFromCache(path) end

---@return cc.Sprite3D
function Sprite3D.new() end

function Sprite3D:onAABBDirty() end

---remove all attach nodes
function Sprite3D:removeAllAttachNode() end

---remove attach node
---@param boneName string
function Sprite3D:removeAttachNode(boneName) end

---@param blendFunc cc.BlendFunc
function Sprite3D:setBlendFunc(blendFunc) end

---@param side any
function Sprite3D:setCullFace(side) end

---@param enable boolean
function Sprite3D:setCullFaceEnabled(enable) end

---force set this Sprite3D to 2D render queue
---@param force2D boolean
function Sprite3D:setForce2DQueue(force2D) end

---Force to write to depth buffer, this is useful if you want to achieve effects like fading.
---@param value boolean
function Sprite3D:setForceDepthWrite(value) end

---light mask getter & setter, light works only when _lightmask & light's flag is true, default value of _lightmask is 0xffff
---@param mask integer
function Sprite3D:setLightMask(mask) end

---Adds a new material to the sprite.
---The Material will be applied to all the meshes that belong to the sprite.
---Internally it will call `setMaterial(material,-1)`
---@param material cc.Material
---
---Adds a new material to a particular mesh of the sprite.
---meshIndex is the mesh that will be applied to.
---if meshIndex == -1, then it will be applied to all the meshes that belong to the sprite.
---@overload fun(self: cc.Sprite3D, material: cc.Material, meshIndex: integer)
function Sprite3D:setMaterial(material) end

---set diffuse texture, set the first if multiple textures exist
---@param texFile string
---@overload fun(self: cc.Sprite3D, texture: cc.Texture2D)
function Sprite3D:setTexture(texFile) end

return Sprite3D