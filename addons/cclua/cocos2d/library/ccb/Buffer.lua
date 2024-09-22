---AUTO GENERATED, DO NOT MODIFY!
---@meta ccb.Buffer

---Used to store vertex and index data data.
---@class ccb.Buffer : cc.Ref
---@field size integer Get buffer size in bytes. \return The buffer size in bytes.
local Buffer = {}

---Get buffer size in bytes.
---@return integer # The buffer size in bytes.
function Buffer:getSize() end

---Update buffer data
---@param data any # Specifies a pointer to data that will be copied into the data store for initialization.
---@param size integer # Specifies the size in bytes of the data store region being replaced.
---\see `updateSubData(void* data, unsigned int offset, unsigned int size)`
function Buffer:updateData(data, size) end

---Update buffer sub-region data
---@param data any # Specifies a pointer to the new data that will be copied into the data store.
---@param offset integer # Specifies the offset into the buffer object's data store where data replacement will begin, measured in bytes.
---@param size integer # Specifies the size in bytes of the data store region being replaced.
---\see `updateData(void* data, unsigned int size)`
function Buffer:updateSubData(data, offset, size) end

---By default, static buffer data will automatically stored when it comes to foreground.
---This function is used to indicate whether external data needs to be used to update the buffer instead of using the default stored data.
---@param needDefaultStoredData boolean # Specifies whether to use the default stored data.
function Buffer:usingDefaultStoredData(needDefaultStoredData) end

return Buffer