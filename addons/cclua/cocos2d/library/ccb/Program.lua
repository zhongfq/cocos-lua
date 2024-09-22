---AUTO GENERATED, DO NOT MODIFY!
---@meta ccb.Program

---A program.
---@class ccb.Program : cc.Ref
---@field activeAttributes { [string]: ccb.AttributeBindInfo } Get active vertex attributes. \return Active vertex attributes. key is active attribute name, Value is corresponding attribute info.
---@field fragmentShader string Get fragment shader. \ Fragment shader.
---@field maxFragmentLocation integer Get maximum fragment location. \return Maximum fragment location.
---@field maxVertexLocation integer Get maximum vertex location. \return Maximum vertex locaiton.
---@field programType ccb.ProgramType Get engine built-in program type. \return The built-in program type.
---@field vertexShader string Get vertex shader. \return Vertex shader.
local Program = {}

---Get active vertex attributes.
---@return { [string]: ccb.AttributeBindInfo } # Active vertex attributes. key is active attribute name, Value is corresponding attribute info.
function Program:getActiveAttributes() end

---Get a uniformInfo in given location from the specific shader stage.
---@param stage ccb.ShaderStage # Specifies the shader stage. The symbolic constant can be either VERTEX or FRAGMENT.
---@param location integer # Specifies the uniform locaion.
---@return ccb.UniformInfo # The uniformInfo.
function Program:getActiveUniformInfo(stage, location) end

---Get all uniformInfos.
---@return { [string]: ccb.UniformInfo } # The uniformInfos.
---@param stage ccb.ShaderStage
function Program:getAllActiveUniformInfo(stage) end

---Get attribute location by attribute name.
---@param name string # Specifies the attribute name.
---@return integer # The attribute location.
---
---Get attribute location by engine built-in attribute enum name.
---\param name Specifies the engine built-in attribute enum name.
---\return The attribute location.
---@overload fun(self: ccb.Program, name: ccb.Attribute): integer
function Program:getAttributeLocation(name) end

---Get engine built-in program.
---@param type ccb.ProgramType # Specifies the built-in program type.
---@return ccb.Program
function Program.getBuiltinProgram(type) end

---Get fragment shader.
---\ Fragment shader.
---@return string
function Program:getFragmentShader() end

---Get maximum fragment location.
---@return integer # Maximum fragment location.
function Program:getMaxFragmentLocation() end

---Get maximum vertex location.
---@return integer # Maximum vertex locaiton.
function Program:getMaxVertexLocation() end

---Get engine built-in program type.
---@return ccb.ProgramType # The built-in program type.
function Program:getProgramType() end

---Get uniform buffer size in bytes that can hold all the uniforms.
---@param stage ccb.ShaderStage # Specifies the shader stage. The symbolic constant can be either VERTEX or FRAGMENT.
---@return integer # The uniform buffer size in bytes.
function Program:getUniformBufferSize(stage) end

---Get uniform location by name.
---@param uniform string # Specifies the uniform name.
---@return ccb.UniformLocation # The uniform location.
---
---Get uniform location by engine built-in uniform enum name.
---\param name Specifies the engine built-in uniform enum name.
---\return The uniform location.
---@overload fun(self: ccb.Program, name: ccb.Uniform): ccb.UniformLocation
function Program:getUniformLocation(uniform) end

---Get vertex shader.
---@return string # Vertex shader.
function Program:getVertexShader() end

return Program