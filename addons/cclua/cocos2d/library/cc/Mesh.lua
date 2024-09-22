---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.Mesh

---Mesh: contains ref to index buffer, GLProgramState, texture, skin, blend function, aabb and so on
---@class cc.Mesh : cc.Ref
---@field blendFunc cc.BlendFunc 
---@field indexBuffer ccb.Buffer get index buffer <br><br>\lua NA
---@field indexCount integer get index count <br><br>\lua NA
---@field indexFormat any get index format <br><br>\lua NA
---@field material cc.Material Returns the Material being used by the Mesh
---@field meshVertexAttribCount integer get mesh vertex attribute count
---@field name string name getter
---@field primitiveType any get primitive type <br><br>\lua NA
---@field programState ccb.ProgramState get ProgramState <br><br>\lua NA
---@field skin cc.MeshSkin skin getter <br><br>\lua NA
---@field textureFileName string 
---@field vertexBuffer ccb.Buffer get vertex buffer <br><br>\lua NA
---@field vertexSizeInBytes integer get per vertex size in bytes
---@field visible boolean 
local Mesh = {}

---calculate the AABB of the mesh
---\note the AABB is in the local space, not the world space
function Mesh:calculateAABB() end

---create mesh from positions, normals, and so on, single SubMesh
---@param positions number[]
---@param normals number[]
---@param texs number[]
---@param indices integer[]
---@return cc.Mesh
---
---\lua NA
---@overload fun(vertices: number[], perVertexSizeInFloat: integer, indices: integer[], attribs: cc.MeshVertexAttrib[]): cc.Mesh
function Mesh.create(positions, normals, texs, indices) end

---@param renderer cc.Renderer
---@param globalZ number
---@param transform cc.Mat4
---@param flags integer
---@param lightMask integer
---@param color cc.Vec4
---@param forceDepthWrite boolean
function Mesh:draw(renderer, globalZ, transform, flags, lightMask, color, forceDepthWrite) end

---@return cc.BlendFunc
function Mesh:getBlendFunc() end

---get index buffer
---
---\lua NA
---@return ccb.Buffer
function Mesh:getIndexBuffer() end

---get index count
---
---\lua NA
---@return integer
function Mesh:getIndexCount() end

---get index format
---
---\lua NA
---@return any
function Mesh:getIndexFormat() end

---Returns the Material being used by the Mesh
---@return cc.Material
function Mesh:getMaterial() end

---get mesh vertex attribute count
---@return integer
function Mesh:getMeshVertexAttribCount() end

---get MeshVertexAttribute by index
---@param idx integer
---@return cc.MeshVertexAttrib
function Mesh:getMeshVertexAttribute(idx) end

---name getter
---@return string
function Mesh:getName() end

---get primitive type
---
---\lua NA
---@return any
function Mesh:getPrimitiveType() end

---get ProgramState
---
---\lua NA
---@return ccb.ProgramState
function Mesh:getProgramState() end

---skin getter
---
---\lua NA
---@return cc.MeshSkin
function Mesh:getSkin() end

---Get texture (diffuse), which is responsible for the main appearance. It is also means main texture, you can also call getTexture(NTextureData::Usage::Diffuse)
---@return cc.Texture2D # Texture used, return the texture of first mesh if multiple meshes exist
---
---Get texture
---\param usage Usage of returned texture
---\return The texture of this usage, return the texture of first mesh if multiple meshes exist
---@overload fun(self: cc.Mesh, usage: cc.NTextureData.Usage): cc.Texture2D
function Mesh:getTexture() end

---@return string
function Mesh:getTextureFileName() end

---get vertex buffer
---
---\lua NA
---@return ccb.Buffer
function Mesh:getVertexBuffer() end

---get per vertex size in bytes
---@return integer
function Mesh:getVertexSizeInBytes() end

---has vertex attribute?
---
---\lua NA
---@param attrib cc.VertexKey
---@return boolean
function Mesh:hasVertexAttrib(attrib) end

---@return boolean
function Mesh:isVisible() end

---@return cc.Mesh
function Mesh.new() end

---@param blendFunc cc.BlendFunc
function Mesh:setBlendFunc(blendFunc) end

---force set this Sprite3D to 2D render queue
---@param force2D boolean
function Mesh:setForce2DQueue(force2D) end

---Sets a new Material to the Mesh
---@param material cc.Material
function Mesh:setMaterial(material) end

---name setter
---@param name string
function Mesh:setName(name) end

---Sets a new ProgramState for the Mesh
---A new Material will be created for it
---@param programState ccb.ProgramState
function Mesh:setProgramState(programState) end

---skin setter
---@param skin cc.MeshSkin
function Mesh:setSkin(skin) end

---set texture (diffuse), which is responsible for the main appearance. It is also means main texture, you can also call setTexture(texPath, NTextureData::Usage::Diffuse)
---@param texPath string # texture path
---
---set texture (diffuse), which is responsible for the main appearance. It is also means main texture, you can also call setTexture(texPath, NTextureData::Usage::Diffuse)
---\param tex texture to be set
---@overload fun(self: cc.Mesh, tex: cc.Texture2D)
---
---set texture
---\param tex texture to be set
---\param usage Usage of this texture
---\param whether refresh the cache file name
---@overload fun(self: cc.Mesh, tex: cc.Texture2D, usage: cc.NTextureData.Usage, cacheFileName: boolean)
---
---set texture
---\param tex texture to be set
---\param usage Usage of this texture
---\param whether refresh the cache file name
---@overload fun(self: cc.Mesh, tex: cc.Texture2D, usage: cc.NTextureData.Usage)
---
---set texture
---\param texPath texture path
---\param usage Usage of this texture
---@overload fun(self: cc.Mesh, texPath: string, usage: cc.NTextureData.Usage)
function Mesh:setTexture(texPath) end

---visible getter and setter
---@param visible boolean
function Mesh:setVisible(visible) end

return Mesh