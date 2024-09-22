---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.RenderCommand

---Base class of the `RenderCommand` hierarchy.
---
---The `Renderer` knows how to render `RenderCommands` objects.
---@class cc.RenderCommand 
---@field depth number Get the depth by current model view matrix.
---@field globalOrder number Get global Z order.
---@field mv cc.Mat4 
---@field pipelineDescriptor cc.PipelineDescriptor Can use the result to change the descriptor content.
---@field skipBatching boolean Get skip batching status, if a rendering is skip batching, it will be forced to be rendering separately.
---@field transparent boolean Returns whether is transparent.
---@field type cc.RenderCommand.Type Returns the Command type.
local RenderCommand = {}

---Get the depth by current model view matrix.
---@return number
function RenderCommand:getDepth() end

---Get global Z order.
---@return number
function RenderCommand:getGlobalOrder() end

---@return cc.Mat4
function RenderCommand:getMV() end

---Can use the result to change the descriptor content.
---@return cc.PipelineDescriptor
function RenderCommand:getPipelineDescriptor() end

---Returns the Command type.
---@return cc.RenderCommand.Type
function RenderCommand:getType() end

---Init function, will be called by all the render commands.
---@param globalZOrder number # The global order of command, used for rendercommand sorting.
---@param modelViewTransform cc.Mat4 # Modelview matrix when submitting the render command.
---@param flags integer # Flag used to indicate whether the command should be draw at 3D mode or not.
function RenderCommand:init(globalZOrder, modelViewTransform, flags) end

---Whether the command should be rendered at 3D mode.
---@return boolean
function RenderCommand:is3D() end

---Get skip batching status, if a rendering is skip batching, it will be forced to be rendering separately.
---@return boolean
function RenderCommand:isSkipBatching() end

---Returns whether is transparent.
---@return boolean
function RenderCommand:isTransparent() end

---Set the command rendered in 3D mode or not.
---@param value boolean
function RenderCommand:set3D(value) end

---Set skip batching.
---@param value boolean
function RenderCommand:setSkipBatching(value) end

---Set transparent flag.
---@param isTransparent boolean
function RenderCommand:setTransparent(isTransparent) end

return RenderCommand