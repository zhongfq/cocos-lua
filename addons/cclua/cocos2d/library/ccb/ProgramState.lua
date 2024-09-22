---AUTO GENERATED, DO NOT MODIFY!
---@meta ccb.ProgramState

---A program state object can create or reuse a program.
---Each program state object keep its own unifroms and textures data.
---@class ccb.ProgramState : cc.Ref
---@field fragmentTextureInfos { [integer]: ccb.TextureInfo } Get fragment texture informations \return Fragment texture informations. Key is the texture location, Value store the texture informations
---@field program ccb.Program Get the program object.
---@field vertexTextureInfos { [integer]: ccb.TextureInfo } Get vertex texture informations \return Vertex texture informations. Key is the texture location, Value store the texture informations
local ProgramState = {}

---Deep clone ProgramState
---@return ccb.ProgramState
function ProgramState:clone() end

---Get an attribute location by the actual attribute name.
---@param name string # Specifies the attribute name.
---@return integer # Attribute location.
---\see `int getAttributeLocation(const std::string& name) const`
---
---Get an attribute location by the engine built-in attribute name.
---\param name Specifies the built-in attribute name.
---\return Attribute location.
---\see `int getAttributeLocation(const std::string& name) const`
---@overload fun(self: ccb.ProgramState, name: ccb.Attribute): integer
function ProgramState:getAttributeLocation(name) end

---Get fragment texture informations
---@return { [integer]: ccb.TextureInfo } # Fragment texture informations. Key is the texture location, Value store the texture informations
function ProgramState:getFragmentTextureInfos() end

---Get the program object.
---@return ccb.Program
function ProgramState:getProgram() end

---Get uniform location in given uniform name.
---@param uniform string # Specifies the uniform name.
---@return ccb.UniformLocation # Uniform location.
---\see `backend::UniformLocation getUniformLocation(backend::Uniform name) const`
---
---Get uniform location in a more efficient way by the given built-in uniform name.
---\param uniform Specifies the engin built-in uniform name.
---\return Uniform location.
---\see `backend::UniformLocation getUniformLocation(backend::Uniform name) const`
---@overload fun(self: ccb.ProgramState, name: ccb.Uniform): ccb.UniformLocation
function ProgramState:getUniformLocation(uniform) end

---@return any
function ProgramState:getVertexLayout() end

---Get vertex texture informations
---@return { [integer]: ccb.TextureInfo } # Vertex texture informations. Key is the texture location, Value store the texture informations
function ProgramState:getVertexTextureInfos() end

---@param program ccb.Program # Specifies the program.
---@return ccb.ProgramState
function ProgramState.new(program) end

---Sets a uniform auto-binding.
---
---This method parses the passed in autoBinding string and attempts to convert it
---to an enumeration value. If it matches to one of the predefined strings, it will create a
---callback to get the correct value at runtime.
---
---@param uniformName string # The name of the material parameter to store an auto-binding for.
---@param autoBinding string # A string matching one of the built-in AutoBinding enum constants.
function ProgramState:setParameterAutoBinding(uniformName, autoBinding) end

---Set texture.
---@param uniformLocation ccb.UniformLocation # Specifies texture location.
---@param slot integer # Specifies texture slot selector.
---@param texture ccb.TextureBackend # Specifies a pointer to backend texture.
function ProgramState:setTexture(uniformLocation, slot, texture) end

---Set textures in array.
---@param uniformLocation ccb.UniformLocation # Specifies texture location.
---@param slots integer[] # Specifies texture slot selector.
---@param textures ccb.TextureBackend[] # Specifies a vector of backend texture object.
function ProgramState:setTextureArray(uniformLocation, slots, textures) end

---Specify the value of a uniform variable for the current program state object.
---@param uniformLocation ccb.UniformLocation # Specifies the uniform location.
---@param data any # Specifies the new values to be used for the specified uniform variable.
---@param size integer # Specifies the uniform data size.
function ProgramState:setUniform(uniformLocation, data, size) end

return ProgramState