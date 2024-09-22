---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.SpriteBatchNode

---SpriteBatchNode is like a batch node: if it contains children, it will draw them in 1 single OpenGL call
---(often known as "batch draw").
---
---A SpriteBatchNode can reference one and only one texture (one image file, one texture atlas).
---Only the Sprites that are contained in that texture can be added to the SpriteBatchNode.
---All Sprites added to a SpriteBatchNode are drawn in one OpenGL ES draw call.
---If the Sprites are not added to a SpriteBatchNode then an OpenGL ES draw call will be needed for each one, which is less efficient.
---
---
---Limitations:
---- The only object that is accepted as child (or grandchild, grand-grandchild, etc...) is Sprite or any subclass of Sprite. eg: particles, labels and layer can't be added to a SpriteBatchNode.
---- Either all its children are Aliased or Antialiased. It can't be a mix. This is because "alias" is a property of the texture, and all the sprites share the same texture.
---
---\since v0.7.1
---@class cc.SpriteBatchNode : cc.Node
---@field blendFunc cc.BlendFunc \lua NA
---@field descendants cc.Sprite[] Returns an array with the descendants (children, gran children, etc.). This is specific to BatchNode. In order to use the children, use getChildren() instead. <br><br>\return An array with the descendants (children, gran children, etc.).
---@field texture cc.Texture2D 
---@field textureAtlas cc.TextureAtlas Returns the TextureAtlas object.  <br><br>\return The TextureAtlas object.
local SpriteBatchNode = {}

---@param child cc.Sprite
---@param z integer
---@param aTag integer
---@return cc.SpriteBatchNode
function SpriteBatchNode:addSpriteWithoutQuad(child, z, aTag) end

---Append the child. 
---
---@param sprite cc.Sprite # A Sprite.
function SpriteBatchNode:appendChild(sprite) end

---@param cls string
---@return any
function SpriteBatchNode:as(cls) end

---Get the nearest index from the sprite in z.
---
---@param sprite cc.Sprite # The parent sprite.
---@param z integer # Z order for drawing priority.
---@return integer # Index.
function SpriteBatchNode:atlasIndexForChild(sprite, z) end

---Creates a SpriteBatchNode with a file image (.png, .jpeg, .pvr, etc) and capacity of children.
---The capacity will be increased in 33% in runtime if it runs out of space.
---The file will be loaded using the TextureMgr.
---
---@param fileImage string # A file image (.png, .jpeg, .pvr, etc).
---@param capacity integer # The capacity of children.
---@return cc.SpriteBatchNode # Return an autorelease object.
---@overload fun(fileImage: string): cc.SpriteBatchNode
function SpriteBatchNode.create(fileImage, capacity) end

---Creates a SpriteBatchNode with a texture2d and capacity of children.
---The capacity will be increased in 33% in runtime if it runs out of space.
---
---@param tex cc.Texture2D # A texture2d.
---@param capacity integer # The capacity of children.
---@return cc.SpriteBatchNode # Return an autorelease object.
---@overload fun(tex: cc.Texture2D): cc.SpriteBatchNode
function SpriteBatchNode.createWithTexture(tex, capacity) end

---\lua NA
---@return cc.BlendFunc
function SpriteBatchNode:getBlendFunc() end

---Returns an array with the descendants (children, gran children, etc.).
---This is specific to BatchNode. In order to use the children, use getChildren() instead.
---
---@return cc.Sprite[] # An array with the descendants (children, gran children, etc.).
function SpriteBatchNode:getDescendants() end

---@return cc.Texture2D
function SpriteBatchNode:getTexture() end

---Returns the TextureAtlas object. 
---
---@return cc.TextureAtlas # The TextureAtlas object.
function SpriteBatchNode:getTextureAtlas() end

---Get the Max image block index,in all child.
---
---@param sprite cc.Sprite # The parent sprite.
---@return integer # Index.
function SpriteBatchNode:highestAtlasIndexInChild(sprite) end

---Increase the Atlas Capacity.
function SpriteBatchNode:increaseAtlasCapacity() end

---initializes a SpriteBatchNode with a file image (.png, .jpeg, .pvr, etc) and a capacity of children.
---The capacity will be increased in 33% in runtime if it runs out of space.
---The file will be loaded using the TextureMgr.
---\js init
---\lua init
---@param fileImage string
---@param capacity integer
---@return boolean
---@overload fun(self: cc.SpriteBatchNode, fileImage: string): boolean
function SpriteBatchNode:initWithFile(fileImage, capacity) end

---initializes a SpriteBatchNode with a texture2d and capacity of children.
---The capacity will be increased in 33% in runtime if it runs out of space.
---@param tex cc.Texture2D
---@param capacity integer
---@return boolean
---@overload fun(self: cc.SpriteBatchNode, tex: cc.Texture2D): boolean
function SpriteBatchNode:initWithTexture(tex, capacity) end

---Inserts a quad at a certain index into the texture atlas. The Sprite won't be added into the children array.
---This method should be called only when you are dealing with very big AtlasSprite and when most of the Sprite won't be updated.
---For example: a tile map (TMXMap) or a label with lots of characters (LabelBMFont).
---@param sprite cc.Sprite
---@param index integer
function SpriteBatchNode:insertQuadFromSprite(sprite, index) end

---Get the Min image block index,in all child. 
---
---@param sprite cc.Sprite # The parent sprite.
---@return integer # Index.
function SpriteBatchNode:lowestAtlasIndexInChild(sprite) end

---\js ctor
---@return cc.SpriteBatchNode
function SpriteBatchNode.new() end

---Rebuild index with a sprite all child. 
---
---@param parent cc.Sprite # The parent sprite.
---@param index integer # The child index.
---@return integer # Index.
function SpriteBatchNode:rebuildIndexInOrder(parent, index) end

---Removes a child given a certain index. It will also cleanup the running actions depending on the cleanup parameter.
---
---@param index integer # A certain index.
---@param doCleanup boolean # Whether or not to cleanup the running actions.
---\warning Removing a child from a SpriteBatchNode is very slow.
function SpriteBatchNode:removeChildAtIndex(index, doCleanup) end

---Remove a sprite from Atlas. 
---
---@param sprite cc.Sprite # A Sprite.
function SpriteBatchNode:removeSpriteFromAtlas(sprite) end

---@param reorder boolean
function SpriteBatchNode:reorderBatch(reorder) end

---reserves capacity for the batch node.
---If the current capacity is bigger, nothing happens.
---otherwise, a new capacity is allocated
---@param newCapacity integer
function SpriteBatchNode:reserveCapacity(newCapacity) end

---\code
---When this function bound into js or lua,the parameter will be changed.
---In js: var setBlendFunc(var src, var dst).
---\endcode
---\lua NA
---@param blendFunc cc.BlendFunc
function SpriteBatchNode:setBlendFunc(blendFunc) end

---@param texture cc.Texture2D
function SpriteBatchNode:setTexture(texture) end

---Sets the TextureAtlas object. 
---
---@param textureAtlas cc.TextureAtlas # The TextureAtlas object.
function SpriteBatchNode:setTextureAtlas(textureAtlas) end

return SpriteBatchNode