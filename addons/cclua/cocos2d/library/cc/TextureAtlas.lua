---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.TextureAtlas

---\addtogroup _2d
---\{
---@class cc.TextureAtlas : cc.Ref
---@field capacity integer Gets the quantity of quads that can be stored with the current texture atlas size.
---@field description string Get quads total amount. \js NA \lua NA
---@field dirty boolean Whether or not the array buffer of the VBO needs to be updated.
---@field indices olua.ushort 
---@field texture cc.Texture2D Gets the texture of the texture atlas.
---@field totalQuads integer Gets the quantity of quads that are going to be drawn.
local TextureAtlas = {}

---Creates a TextureAtlas with an filename and with an initial capacity for Quads.
---The TextureAtlas capacity can be increased in runtime.
---@param file string # The file path.
---@param capacity integer # Capacity for Quads.
---@return cc.TextureAtlas
function TextureAtlas.create(file, capacity) end

---Creates a TextureAtlas with a previously initialized Texture2D object, and
---with an initial capacity for n Quads.
---The TextureAtlas capacity can be increased in runtime.
---@param texture cc.Texture2D # A texture2D object pointer.
---@param capacity integer # Capacity for Quads.
---@return cc.TextureAtlas
function TextureAtlas.createWithTexture(texture, capacity) end

---Ensures that after a realloc quads are still empty.
---Used internally by ParticleBatchNode.
---\since 1.1
---@param index integer
---@param amount integer
function TextureAtlas:fillWithEmptyQuadsFromIndex(index, amount) end

---Gets the quantity of quads that can be stored with the current texture atlas size.
---@return integer
function TextureAtlas:getCapacity() end

---Get quads total amount.
---\js NA
---\lua NA
---@return string
function TextureAtlas:getDescription() end

---@return olua.ushort
function TextureAtlas:getIndices() end

---Gets the texture of the texture atlas.
---@return cc.Texture2D
function TextureAtlas:getTexture() end

---Gets the quantity of quads that are going to be drawn.
---@return integer
function TextureAtlas:getTotalQuads() end

---Used internally by ParticleBatchNode.
---don't use this unless you know what you're doing.
---\since 1.1
---@param amount integer
function TextureAtlas:increaseTotalQuadsWith(amount) end

---Initializes a TextureAtlas with a filename and with a certain capacity for Quads.
---The TextureAtlas capacity can be increased in runtime.
---
---\attention Do not reinitialize the TextureAtlas because it will leak memory (issue #706).
---@param file string # The file path.
---@param capacity integer # Capacity for Quads.
---@return boolean
function TextureAtlas:initWithFile(file, capacity) end

---Initializes a TextureAtlas with a previously initialized Texture2D object, and
---with an initial capacity for Quads. 
---The TextureAtlas capacity can be increased in runtime.
---\attention: Do not reinitialize the TextureAtlas because it will leak memory (issue #706).
---@param texture cc.Texture2D # A texture2D object pointer.
---@param capacity integer # Capacity for Quads.
---@return boolean
function TextureAtlas:initWithTexture(texture, capacity) end

---Removes the quad that is located at a certain index and inserts it at a new index.
---This operation is faster than removing and inserting in a quad in 2 different steps.
---\since v0.7.2
---@param fromIndex integer
---@param newIndex integer
function TextureAtlas:insertQuadFromIndex(fromIndex, newIndex) end

---Whether or not the array buffer of the VBO needs to be updated.
---@return boolean
function TextureAtlas:isDirty() end

---Moves an amount of quads from oldIndex at newIndex.
---\since v1.1
---@param oldIndex integer
---@param amount integer
---@param newIndex integer
---
---Moves quads from index till totalQuads to the newIndex.
---Used internally by ParticleBatchNode.
---This method doesn't enlarge the array if newIndex + quads to be moved > capacity.
---\since 1.1
---@overload fun(self: cc.TextureAtlas, index: integer, newIndex: integer)
function TextureAtlas:moveQuadsFromIndex(oldIndex, amount, newIndex) end

---\js ctor
---@return cc.TextureAtlas
function TextureAtlas.new() end

---Removes all Quads.
---The TextureAtlas capacity remains untouched. No memory is freed.
---The total number of quads to be drawn will be 0.
---\since v0.7.2
function TextureAtlas:removeAllQuads() end

---Removes a quad at a given index number.
---The capacity remains the same, but the total number of quads to be drawn is reduced in 1.
---\since v0.7.2
---@param index integer
function TextureAtlas:removeQuadAtIndex(index) end

---Removes a amount of quads starting from index.
---\since 1.1
---@param index integer
---@param amount integer
function TextureAtlas:removeQuadsAtIndex(index, amount) end

---Resize the capacity of the TextureAtlas.
---The new capacity can be lower or higher than the current one.
---It returns true if the resize was successful.
---If it fails to resize the capacity it will return false with a new capacity of 0.
---
---@param capacity integer # Capacity for Quads.
---@return boolean
function TextureAtlas:resizeCapacity(capacity) end

---Specify if the array buffer of the VBO needs to be updated.
---@param bDirty boolean
function TextureAtlas:setDirty(bDirty) end

---Sets the texture for the texture atlas.
---@param texture cc.Texture2D
function TextureAtlas:setTexture(texture) end

return TextureAtlas