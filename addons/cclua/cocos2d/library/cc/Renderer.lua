---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.Renderer

---\addtogroup 3d
---\{
---@class cc.Renderer 
---@field clearColor any Get color clear value. \return Color clear value.
---@field clearDepth number Get depth clear value. \return Depth clear value.
---@field clearFlag cc.ClearFlag Get the clear flag. \return The clear flag.
---@field clearStencil integer Get the index when the stencil buffer is cleared.  \return The index used when the stencil buffer is cleared.
---@field colorAttachment cc.Texture2D Get color attachment. \return Color attachment.
---@field cullMode any Get cull mode. \return The cull mode.
---@field depthAttachment cc.Texture2D Get depth attachment. \return Depth attachment.
---@field depthCompareFunction ccb.CompareFunction Get depth compare function. \return Depth compare function.
---@field depthTest boolean Get whether depth test state is enabled or disabled. \return true if depth test is enabled, otherwise false.
---@field depthWrite boolean Get whether writing to depth buffer is enabled or not. \return true if enable writing into the depth buffer, false otherwise.
---@field drawnBatches integer 
---@field drawnVertices integer 
---@field renderTargetFlag cc.RenderTargetFlag Get the render target flag. \return The render target flag.
---@field scissorTest boolean 
---@field stencilAttachment cc.Texture2D Get stencil attachment. \return Stencil attachment.
---@field stencilDepthPassOperation ccb.StencilOperation Get the stencil action when both the stencil test and the depth test pass, or when the stencil test passes and either there is no depth buffer or depth testing is not enabled.
---@field stencilFailureOperation ccb.StencilOperation Get the action to take when the stencil test fails.
---@field stencilPassDepthFailureOperation ccb.StencilOperation Get the stencil action when the stencil test passes, but the depth test fails.
---@field stencilReadMask integer Get the stencil readMask. \return Stencil read mask. \see `setStencilCompareFunction(backend::CompareFunction func, unsigned int ref, unsigned int readMask)`
---@field stencilReferenceValue integer Get stencil reference value set by `setStencilCompareFunction`.  \return Stencil reference value. \see `setStencilCompareFunction(backend::CompareFunction func, unsigned int ref, unsigned int readMask)`
---@field stencilTest boolean Get whether stencil test is enabled or not. \return true if stencil test is enabled, false otherwise.
---@field stencilWriteMask integer Get the stencil write mask. \return Stencil write mask. \see `setStencilWriteMask(unsigned int mask)`
---@field winding any Get winding mode. \return The winding mode.
---@field BATCH_TRIAGCOMMAND_RESERVED_SIZE integer
---@field INDEX_VBO_SIZE integer
---@field MATERIAL_ID_DO_NOT_BATCH integer
---@field VBO_SIZE integer
local Renderer = {}

---@return any
function Renderer:__gc() end

---Adds a `RenderComamnd` into the renderer
---@param command cc.RenderCommand
---
---Adds a `RenderComamnd` into the renderer specifying a particular render queue ID
---@overload fun(self: cc.Renderer, command: cc.RenderCommand, renderQueueID: integer)
function Renderer:addCommand(command) end

---@param number integer
function Renderer:addDrawnBatches(number) end

---@param number integer
function Renderer:addDrawnVertices(number) end

---returns whether or not a rectangle is visible or not
---@param transform cc.Mat4
---@param size cc.Size
---@return boolean
function Renderer:checkVisibility(transform, size) end

---Cleans all `RenderCommand`s in the queue
function Renderer:clean() end

---Set clear values for each attachment.
---\flags Flags to indicate which attachment clear value to be modified.
---\color The clear color value.
---\depth The clear depth value.
---\stencil The clear stencil value.
---@param flags cc.ClearFlag
---@param color any
---@param depth number
---@param stencil integer
---@param globalOrder number
function Renderer:clear(flags, color, depth, stencil, globalOrder) end

function Renderer:clearDrawStats() end

---Creates a render queue and returns its Id
---@return integer
function Renderer:createRenderQueue() end

---draw command now
---@param command cc.RenderCommand
function Renderer:drawCommand(command) end

---Get color clear value.
---@return any # Color clear value.
function Renderer:getClearColor() end

---Get depth clear value.
---@return number # Depth clear value.
function Renderer:getClearDepth() end

---Get the clear flag.
---@return cc.ClearFlag # The clear flag.
function Renderer:getClearFlag() end

---Get the index when the stencil buffer is cleared. 
---@return integer # The index used when the stencil buffer is cleared.
function Renderer:getClearStencil() end

---Get color attachment.
---@return cc.Texture2D # Color attachment.
function Renderer:getColorAttachment() end

---Get cull mode.
---@return any # The cull mode.
function Renderer:getCullMode() end

---Get depth attachment.
---@return cc.Texture2D # Depth attachment.
function Renderer:getDepthAttachment() end

---Get depth compare function.
---@return ccb.CompareFunction # Depth compare function.
function Renderer:getDepthCompareFunction() end

---Get whether depth test state is enabled or disabled.
---@return boolean # true if depth test is enabled, otherwise false.
function Renderer:getDepthTest() end

---Get whether writing to depth buffer is enabled or not.
---@return boolean # true if enable writing into the depth buffer, false otherwise.
function Renderer:getDepthWrite() end

---@return integer
function Renderer:getDrawnBatches() end

---@return integer
function Renderer:getDrawnVertices() end

---Get the render target flag.
---@return cc.RenderTargetFlag # The render target flag.
function Renderer:getRenderTargetFlag() end

---@return cc.ScissorRect
function Renderer:getScissorRect() end

---@return boolean
function Renderer:getScissorTest() end

---Get stencil attachment.
---@return cc.Texture2D # Stencil attachment.
function Renderer:getStencilAttachment() end

---Get the stencil test function.
---@return ccb.CompareFunction
function Renderer:getStencilCompareFunction() end

---Get the stencil action when both the stencil test and the depth test pass, or when the stencil test passes and either there is no depth buffer or depth testing is not enabled.
---@return ccb.StencilOperation
function Renderer:getStencilDepthPassOperation() end

---Get the action to take when the stencil test fails.
---@return ccb.StencilOperation
function Renderer:getStencilFailureOperation() end

---Get the stencil action when the stencil test passes, but the depth test fails.
---@return ccb.StencilOperation
function Renderer:getStencilPassDepthFailureOperation() end

---Get the stencil readMask.
---@return integer # Stencil read mask.
---\see `setStencilCompareFunction(backend::CompareFunction func, unsigned int ref, unsigned int readMask)`
function Renderer:getStencilReadMask() end

---Get stencil reference value set by `setStencilCompareFunction`. 
---@return integer # Stencil reference value.
---\see `setStencilCompareFunction(backend::CompareFunction func, unsigned int ref, unsigned int readMask)`
function Renderer:getStencilReferenceValue() end

---Get whether stencil test is enabled or not.
---@return boolean # true if stencil test is enabled, false otherwise.
function Renderer:getStencilTest() end

---Get the stencil write mask.
---@return integer # Stencil write mask.
---\see `setStencilWriteMask(unsigned int mask)`
function Renderer:getStencilWriteMask() end

---Get viewport.
---@return cc.Viewport
function Renderer:getViewport() end

---Get winding mode.
---@return any # The winding mode.
function Renderer:getWinding() end

function Renderer:init() end

---Constructor.
---@return cc.Renderer
function Renderer.new() end

---Pops a group from the render queue
function Renderer:popGroup() end

---Pushes a group into the render queue
---@param renderQueueID integer
function Renderer:pushGroup(renderQueueID) end

---Renders into the GLView all the queued `RenderCommand` objects
function Renderer:render() end

---Fixed-function state
---@param mode any # Controls if primitives are culled when front facing, back facing, or not culled at all.
function Renderer:setCullMode(mode) end

---Set depth compare function.
---@param func ccb.CompareFunction # Specifies the value used for depth buffer comparisons.
function Renderer:setDepthCompareFunction(func) end

---Enable/disable depth test. 
---@param value boolean # true means enable depth test, otherwise false.
function Renderer:setDepthTest(value) end

---Enable/disable to update depth buffer. 
---@param value boolean # true means enable writing into the depth buffer, otherwise false.
function Renderer:setDepthWrite(value) end

---Set render targets. If not set, will use default render targets. It will effect all commands.
---\flags Flags to indicate which attachment to be replaced.
---\colorAttachment The value to replace color attachment, only one color attachment supported now.
---\depthAttachment The value to repalce depth attachment.
---\stencilAttachment The value to replace stencil attachment. Depth attachment and stencil attachment
---can be the same value.
---@param flags cc.RenderTargetFlag
---@param colorAttachment cc.Texture2D
---@param depthAttachment cc.Texture2D
---@param stencilAttachment cc.Texture2D
function Renderer:setRenderTarget(flags, colorAttachment, depthAttachment, stencilAttachment) end

---Fixed-function state
---@param x number # , y Specifies the lower left corner of the scissor box
---\param wdith Specifies the width of the scissor box
---@param height number # Specifies the height of the scissor box
---@param y number
---@param width number
function Renderer:setScissorRect(x, y, width, height) end

---Enable/disable scissor test. 
---@param enabled boolean # true if enable scissor test, false otherwise.
function Renderer:setScissorTest(enabled) end

---Set front and back function and reference value for stencil testing.
---@param func ccb.CompareFunction # Specifies the stencil test function.
---@param ref integer # Specifies the reference value for the stencil test. 
---\readMask Specifies a mask that is ANDed with both the reference value and the stored stencil value when the test is done.
---@param readMask integer
function Renderer:setStencilCompareFunction(func, ref, readMask) end

---Set front and back stencil test actions.
---@param stencilFailureOp ccb.StencilOperation # Specifies the action to take when the stencil test fails. 
---@param depthFailureOp ccb.StencilOperation # Specifies the stencil action when the stencil test passes, but the depth test fails. 
---@param stencilDepthPassOp ccb.StencilOperation # Specifies the stencil action when both the stencil test and the depth test pass, or when the stencil test passes and either there is no depth buffer or depth testing is not enabled.
function Renderer:setStencilOperation(stencilFailureOp, depthFailureOp, stencilDepthPassOp) end

---Enable/disable stencil test. 
---@param value boolean # true means enable stencil test, otherwise false.
function Renderer:setStencilTest(value) end

---Control the front and back writing of individual bits in the stencil planes.
---@param mask integer # Specifies a bit mask to enable and disable writing of individual bits in the stencil planes.
function Renderer:setStencilWriteMask(mask) end

---Fixed-function state
---@param x integer # The x coordinate of the upper-left corner of the viewport.
---@param y integer # The y coordinate of the upper-left corner of the viewport.
---@param w integer # The width of the viewport, in pixels.
---@param h integer # The height of the viewport, in pixels.
function Renderer:setViewPort(x, y, w, h) end

---Fixed-function state
---@param winding any # The winding order of front-facing primitives.
function Renderer:setWinding(winding) end

return Renderer