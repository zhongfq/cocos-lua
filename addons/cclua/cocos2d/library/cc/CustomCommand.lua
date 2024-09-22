---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.CustomCommand

---Custom command is used to draw all things except triangle commands. You can use
---this command to draw things, just provide vertex/index data and set corret flags.
---@class cc.CustomCommand : cc.RenderCommand
---@field afterCallback fun() 
---@field beforeCallback fun() 
---@field drawType cc.CustomCommand.DrawType 
---@field indexCapacity integer Get index buffer capacity.
---@field indexDrawCount integer 
---@field indexDrawOffset integer 
---@field indexFormat any 
---@field lineWidth number 
---@field primitiveType any 
---@field vertexBuffer ccb.Buffer 
---@field vertexCapacity integer Get vertex buffer capacity.
---@field vertexDrawCount integer 
---@field vertexDrawStart integer 
---@field func fun()
local CustomCommand = {}

---@return any
function CustomCommand:__gc() end

---Create an index buffer of the custom command. The buffer size is (indexSize * capacity).
---Index size is determined by format. If the buffer already exists, then it will delete the
---old buffer and create a new one.
---@param format any # index fomrat, if format is U_SHORT, then the index data type should be
---unsigned short, otherwise should be unsigned int.
---@param capacity integer # how many indices of the buffer
---@param usage any # the usage of the vertex buffer. Use Static of the index data are not updated
---every frame, otherwise use DYNAMIC.
function CustomCommand:createIndexBuffer(format, capacity, usage) end

---Create a vertex buffer of the custom command. The buffer size is (vertexSize * capacity).
---If the buffer already exists, then it will delete the old buffer and create a new one.
---@param vertexSize integer # the size of every vertex data.
---@param capacity integer # how many vertices of the buffer
---@param usage any # the usage of the vertex buffer. Use Static of the vertex data are not updated
---every frame, otherwise use DYNAMIC.
function CustomCommand:createVertexBuffer(vertexSize, capacity, usage) end

---@return fun()
function CustomCommand:getAfterCallback() end

---@return fun()
function CustomCommand:getBeforeCallback() end

---@return cc.CustomCommand.DrawType
function CustomCommand:getDrawType() end

---@return ccb.Buffer
function CustomCommand:getIndexBuffer() end

---Get index buffer capacity.
---@return integer
function CustomCommand:getIndexCapacity() end

---@return integer
function CustomCommand:getIndexDrawCount() end

---@return integer
function CustomCommand:getIndexDrawOffset() end

---@return any
function CustomCommand:getIndexFormat() end

---@return number
function CustomCommand:getLineWidth() end

---@return any
function CustomCommand:getPrimitiveType() end

---@return ccb.Buffer
function CustomCommand:getVertexBuffer() end

---Get vertex buffer capacity.
---@return integer
function CustomCommand:getVertexCapacity() end

---@return integer
function CustomCommand:getVertexDrawCount() end

---@return integer
function CustomCommand:getVertexDrawStart() end

---TODO: should remove it.
---Init function.
---@param globalZOrder number # GlobalZOrder of the render command.
---@param modelViewTransform cc.Mat4 # When in 3D mode, depth sorting needs modelViewTransform.
---@param flags integer # Use to identify that the render command is 3D mode or not.
---
---Init function. The render command will be in 2D mode.
---\param globalZOrder GlobalZOrder of the render command.
---@overload fun(self: cc.CustomCommand, globalZOrder: number)
---
---Init function. The render command will be in 2D mode.
---\param globalZOrder GlobalZOrder of the render command.
---\param blendFunc blend function of the render command.
---@overload fun(self: cc.CustomCommand, globalZOrder: number, blendFunc: cc.BlendFunc)
function CustomCommand:init(globalZOrder, modelViewTransform, flags) end

---Constructor.
---@return cc.CustomCommand
function CustomCommand.new() end

---set a callback which will be invoke after rendering
---@param after fun()
function CustomCommand:setAfterCallback(after) end

---set a callback which will be invoke before rendering
---@param before fun()
function CustomCommand:setBeforeCallback(before) end

---@param drawType cc.CustomCommand.DrawType
function CustomCommand:setDrawType(drawType) end

---Set the index buffer. The existing index buffer will be replaced if exist.
---@param indexBuffer ccb.Buffer
---@param indexFormat any
function CustomCommand:setIndexBuffer(indexBuffer, indexFormat) end

---Set the drawing information if the drawing type is ELEMENT.
---\start specifices the starting index of index buffer
---\count specifices the number of indices to be rendered
---@param start integer
---@param count integer
function CustomCommand:setIndexDrawInfo(start, count) end

---@param lineWidth number
function CustomCommand:setLineWidth(lineWidth) end

---@param primitiveType any
function CustomCommand:setPrimitiveType(primitiveType) end

---Set the vertex buffer. The existing vertex buffer will be replaced if exist.
---@param vertexBuffer ccb.Buffer
function CustomCommand:setVertexBuffer(vertexBuffer) end

---Set the drawing information if the drawing type is ARRAY.
---\start specifices the starting index of vertex buffer
---\count specifices the number of vertices to be rendered
---@param start integer
---@param count integer
function CustomCommand:setVertexDrawInfo(start, count) end

---Update index buffer contents.
---@param data any # Specifies a pointer to the new data that will be copied into the data store.
---@param length integer # Specifies the size in bytes of the data store region being replaced.
---
---Update some or call contents of index buffer
---\param data Specifies a pointer to the new data that will be copied into the data store.
---\param offset specifies the offset into the buffer object's data store where data replacement will begin, measured in bytes.
---\param length Specifies the size in bytes of the data store region being replaced.
---@overload fun(self: cc.CustomCommand, data: any, offset: integer, length: integer)
function CustomCommand:updateIndexBuffer(data, length) end

---Update vertex buffer contents.
---@param data any # Specifies a pointer to the new data that will be copied into the data store.
---@param length integer # Specifies the length in bytes of the data store region being replaced.
---
---Update some or all contents of vertex buffer.
---\param data Specifies a pointer to the new data that will be copied into the data store.
---\param offset Specifies the offset into the buffer object's data store where data replacement will begin, measured in bytes.
---\param length Specifies the size in bytes of the data store region being replaced.
---@overload fun(self: cc.CustomCommand, data: any, offset: integer, length: integer)
function CustomCommand:updateVertexBuffer(data, length) end

return CustomCommand