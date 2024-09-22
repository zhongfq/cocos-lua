---AUTO GENERATED, DO NOT MODIFY!
---@meta ccb.Device

---New or create resources from Device.
---@class ccb.Device : cc.Ref
---@field deviceInfo ccb.DeviceInfo Get a DeviceInfo object. \return A DeviceInfo object.
---@field instance ccb.Device Returns a shared instance of the device.
local Device = {}

---Create an auto released DepthStencilState object.
---@param descriptor ccb.DepthStencilDescriptor # Specifies depth and stencil description.
---@return ccb.DepthStencilState # An auto release DepthStencilState object.
function Device:createDepthStencilState(descriptor) end

---Get a DeviceInfo object.
---@return ccb.DeviceInfo # A DeviceInfo object.
function Device:getDeviceInfo() end

---Returns a shared instance of the device.
---@return ccb.Device
function Device.getInstance() end

---New a Buffer object, not auto released.
---@param size integer # Specifies the size in bytes of the buffer object's new data store.
---@param type ccb.BufferType # Specifies the target buffer object. The symbolic constant must be BufferType::VERTEX or BufferType::INDEX.
---@param usage ccb.BufferUsage # Specifies the expected usage pattern of the data store. The symbolic constant must be BufferUsage::STATIC, BufferUsage::DYNAMIC.
---@return ccb.Buffer # A Buffer object.
function Device:newBuffer(size, type, usage) end

---New a CommandBuffer object, not auto released.
---@return ccb.CommandBuffer # A CommandBuffer object.
function Device:newCommandBuffer() end

---Create an auto released Program.
---@param vertexShader string # Specifes this is a vertex shader source.
---@param fragmentShader string # Specifes this is a fragment shader source.
---@return ccb.Program # A Program instance.
function Device:newProgram(vertexShader, fragmentShader) end

---New a RenderPipeline object, not auto released.
---\param descriptor Specifies render pipeline description.
---@return ccb.RenderPipeline # A RenderPipeline object.
function Device:newRenderPipeline() end

---New a TextureBackend object, not auto released.
---@param descriptor ccb.TextureDescriptor # Specifies texture description.
---@return ccb.TextureBackend # A TextureBackend object.
function Device:newTexture(descriptor) end

---This property controls whether or not the drawables'
---metal textures may only be used for framebuffer attachments (YES) or
---whether they may also be used for texture sampling and pixel
---read/write operations (NO).
---@param frameBufferOnly boolean # A value of YES allows CAMetalLayer to allocate the MTLTexture objects in ways that are optimized for display purposes that makes them unsuitable for sampling. The recommended value for most applications is YES.
---\note This interface is specificaly designed for metal.
function Device:setFrameBufferOnly(frameBufferOnly) end

return Device