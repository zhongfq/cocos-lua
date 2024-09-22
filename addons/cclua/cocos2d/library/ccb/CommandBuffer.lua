---AUTO GENERATED, DO NOT MODIFY!
---@meta ccb.CommandBuffer

---Store encoded commands for the GPU to execute.
---A command buffer stores encoded commands until the buffer is committed for execution by the GPU
---@class ccb.CommandBuffer : cc.Ref
local CommandBuffer = {}

---\name Setters & Getters
---
---Indicate the begining of a frame
function CommandBuffer:beginFrame() end

---Get a screen snapshot
---@param callback fun(arg1: string, arg2: integer, arg3: integer) # A callback to deal with screen snapshot image.
function CommandBuffer:captureScreen(callback) end

---Draw primitives without an index list.
---@param primitiveType ccb.PrimitiveType # The type of primitives that elements are assembled into.
---@param start integer # For each instance, the first index to draw
---@param count integer # For each instance, the number of indexes to draw
---\see `drawElements(PrimitiveType primitiveType, IndexFormat indexType, unsigned int count, unsigned int offset)`
function CommandBuffer:drawArrays(primitiveType, start, count) end

---Draw primitives with an index list.
---@param primitiveType ccb.PrimitiveType # The type of primitives that elements are assembled into.
---@param indexType ccb.IndexFormat # The type if indexes, either 16 bit integer or 32 bit integer.
---@param count integer # The number of indexes to read from the index buffer for each instance.
---@param offset integer # Byte offset within indexBuffer to start reading indexes from.
---\see `setIndexBuffer(Buffer* buffer)`
---\see `drawArrays(PrimitiveType primitiveType, unsigned int start,  unsigned int count)`
function CommandBuffer:drawElements(primitiveType, indexType, count, offset) end

---Present a drawable and commit a command buffer so it can be executed as soon as possible.
function CommandBuffer:endFrame() end

---Do some resources release.
function CommandBuffer:endRenderPass() end

---Fixed-function state
---@param mode ccb.CullMode # Controls if primitives are culled when front facing, back facing, or not culled at all.
function CommandBuffer:setCullMode(mode) end

---Set depthStencil status
---@param depthStencilState ccb.DepthStencilState # Specifies the depth and stencil status
function CommandBuffer:setDepthStencilState(depthStencilState) end

---Set indexes when drawing primitives with index list
---\ buffer A buffer object that the device will read indexes from.
---\ see `drawElements(PrimitiveType primitiveType, IndexFormat indexType, unsigned int count, unsigned int offset)`
---@param buffer ccb.Buffer
function CommandBuffer:setIndexBuffer(buffer) end

---Fixed-function state
---@param lineWidth number # Specifies the width of rasterized lines.
function CommandBuffer:setLineWidth(lineWidth) end

---Set unifroms and textures
---@param programState ccb.ProgramState # A programState object that hold the uniform and texture data.
function CommandBuffer:setProgramState(programState) end

---Sets the current render pipeline state object.
---@param renderPipeline ccb.RenderPipeline # An object that contains the graphics functions and configuration state used in a render pass.
function CommandBuffer:setRenderPipeline(renderPipeline) end

---Fixed-function state
---@param x number # , y Specifies the lower left corner of the scissor box
---\param wdith Specifies the width of the scissor box
---@param height number # Specifies the height of the scissor box
---@param isEnabled boolean
---@param y number
---@param width number
function CommandBuffer:setScissorRect(isEnabled, x, y, width, height) end

---Update both front and back stencil reference value.
---@param value integer # Specifies stencil reference value.
---
---Update stencil reference value.
---\param frontRef Specifies front stencil reference value.
---\param backRef Specifies back stencil reference value.
---@overload fun(self: ccb.CommandBuffer, frontRef: integer, backRef: integer)
function CommandBuffer:setStencilReferenceValue(value) end

---Set a global buffer for all vertex shaders at the given bind point index 0.
---@param buffer ccb.Buffer # The vertex buffer to be setted in the buffer argument table.
function CommandBuffer:setVertexBuffer(buffer) end

---Fixed-function state
---@param x integer # The x coordinate of the upper-left corner of the viewport.
---@param y integer # The y coordinate of the upper-left corner of the viewport.
---@param w integer # The width of the viewport, in pixels.
---@param h integer # The height of the viewport, in pixels.
function CommandBuffer:setViewport(x, y, w, h) end

---Fixed-function state
---@param winding ccb.Winding # The winding order of front-facing primitives.
function CommandBuffer:setWinding(winding) end

return CommandBuffer