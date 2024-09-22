---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.AtlasNode

---AtlasNode is a subclass of Node that implements the RGBAProtocol and TextureProtocol protocol.
---It knows how to render a TextureAtlas object.
---If you are going to render a TextureAtlas consider subclassing AtlasNode (or a subclass of AtlasNode).
---All features from Node are valid, plus the following features:
---- opacity and RGB colors.
---@class cc.AtlasNode : cc.Node
---@field blendFunc cc.BlendFunc \lua NA
---@field quadsToDraw integer 
---@field texture cc.Texture2D 
---@field textureAtlas cc.TextureAtlas Return the buffer manager of the texture vertex.  <br><br>\return Return A TextureAtlas.
local AtlasNode = {}

---@param cls string
---@return any
function AtlasNode:as(cls) end

---creates a AtlasNode  with an Atlas file the width and height of each item and the quantity of items to render.
---
---@param filename string # The path of Atlas file.
---@param tileWidth integer # The width of the item.
---@param tileHeight integer # The height of the item.
---@param itemsToRender integer # The quantity of items to render.
---@return cc.AtlasNode
function AtlasNode.create(filename, tileWidth, tileHeight, itemsToRender) end

---\lua NA
---@return cc.BlendFunc
function AtlasNode:getBlendFunc() end

---@return integer
function AtlasNode:getQuadsToDraw() end

---@return cc.Texture2D
function AtlasNode:getTexture() end

---Return the buffer manager of the texture vertex. 
---
---@return cc.TextureAtlas # Return A TextureAtlas.
function AtlasNode:getTextureAtlas() end

---Initializes an AtlasNode  with a texture the width and height of each item measured in points and the quantity of items to render
---@param texture cc.Texture2D
---@param tileWidth integer
---@param tileHeight integer
---@param itemsToRender integer
---@return boolean
function AtlasNode:initWithTexture(texture, tileWidth, tileHeight, itemsToRender) end

---Initializes an AtlasNode  with an Atlas file the width and height of each item and the quantity of items to render
---@param tile string
---@param tileWidth integer
---@param tileHeight integer
---@param itemsToRender integer
---@return boolean
function AtlasNode:initWithTileFile(tile, tileWidth, tileHeight, itemsToRender) end

---@return cc.AtlasNode
function AtlasNode.new() end

---\code
---When this function bound into js or lua,the parameter will be changed
---In js: var setBlendFunc(var src, var dst)
---\endcode
---\lua NA
---@param blendFunc cc.BlendFunc
function AtlasNode:setBlendFunc(blendFunc) end

---@param quadsToDraw integer
function AtlasNode:setQuadsToDraw(quadsToDraw) end

---@param texture cc.Texture2D
function AtlasNode:setTexture(texture) end

---Set an buffer manager of the texture vertex.
---@param textureAtlas cc.TextureAtlas
function AtlasNode:setTextureAtlas(textureAtlas) end

---updates the Atlas (indexed vertex array).
---Shall be overridden in subclasses.
function AtlasNode:updateAtlasValues() end

return AtlasNode