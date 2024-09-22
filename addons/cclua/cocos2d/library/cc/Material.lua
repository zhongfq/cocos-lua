---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.Material

---Material
---@class cc.Material : cc.Ref
---@field name string returns the material name
---@field renderState cc.RenderState 
---@field technique cc.Technique Returns the Technique used by the Material
---@field techniqueCount integer Returns the number of Techniques in the Material.
---@field techniques any Returns the list of Techniques
local Material = {}

---Adds a Technique into the Material
---@param technique cc.Technique
function Material:addTechnique(technique) end

---returns a clone (deep-copy) of the material
---@return cc.Material
function Material:clone() end

---Creates a Material using the data from the Properties object defined at the specified URL,
---where the URL is of the format "<file-path>.<extension>#<namespace-id>/<namespace-id>/.../<namespace-id>"
---(and "#<namespace-id>/<namespace-id>/.../<namespace-id>" is optional).
---
---\param url The URL pointing to the Properties object defining the material.
---
---@return cc.Material # A new Material or NULL if there was an error.
---@param path string
function Material.createWithFilename(path) end

---Creates a Material with a GLProgramState.
---It will only contain one Technique and one Pass.
---Added in order to support legacy code.
---@param programState ccb.ProgramState
---@return cc.Material
function Material.createWithProgramState(programState) end

---Creates a material from the specified properties object.
---
---@param materialProperties cc.Properties # The properties object defining the
---material (must have namespace equal to 'material').
---@return cc.Material # A new Material.
function Material.createWithProperties(materialProperties) end

---@param meshCommand cc.MeshCommand
---@param globalZOrder number
---@param vertexBuffer ccb.Buffer
---@param indexBuffer ccb.Buffer
---@param primitive any
---@param indexFormat any
---@param indexCount integer
---@param modelView cc.Mat4
function Material:draw(meshCommand, globalZOrder, vertexBuffer, indexBuffer, primitive, indexFormat, indexCount, modelView) end

---returns the material name
---@return string
function Material:getName() end

---@return cc.RenderState
function Material:getRenderState() end

---Returns the Technique used by the Material
---@return cc.Technique
function Material:getTechnique() end

---Returns a Technique by index. 
---returns `nullptr` if the index is invalid.
---@param index integer
---@return cc.Technique
function Material:getTechniqueByIndex(index) end

---Returns a Technique by its name.
---returns `nullptr` if the Technique can't be found.
---@param name string
---@return cc.Technique
function Material:getTechniqueByName(name) end

---Returns the number of Techniques in the Material.
---@return integer
function Material:getTechniqueCount() end

---Returns the list of Techniques
---@return any
function Material:getTechniques() end

---sets the material name
---@param name string
function Material:setName(name) end

---Sets the current technique
---@param techniqueName string
function Material:setTechnique(techniqueName) end

return Material