---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.Sprite

---\addtogroup ui
---\{
---@class cc.Sprite : cc.Node
---@field atlasIndex integer Returns the index used on the TextureAtlas.
---@field batchNode cc.SpriteBatchNode Returns the batch node object if this sprite is rendered by SpriteBatchNode. <br><br>\return The SpriteBatchNode object if this sprite is rendered by SpriteBatchNode, nullptr if the sprite isn't used batch node.
---@field blendFunc cc.BlendFunc \js  NA \lua NA
---@field centerRect cc.Rect Returns the Cap Insets rect <br><br>\return Scale9Sprite's cap inset.
---@field centerRectNormalized cc.Rect getCenterRectNormalized <br><br>Returns the CenterRect in normalized coordinates
---@field dirty boolean Whether or not the Sprite needs to be updated in the Atlas. <br><br>\return True if the sprite needs to be updated in the Atlas, false otherwise.
---@field flippedX boolean Returns the flag which indicates whether the sprite is flipped horizontally or not. <br><br>It only flips the texture of the sprite, and not the texture of the sprite's children. Also, flipping the texture doesn't alter the anchorPoint. If you want to flip the anchorPoint too, and/or to flip the children too use: sprite->setScaleX(sprite->getScaleX() * -1); <br><br>\return true if the sprite is flipped horizontally, false otherwise.
---@field flippedY boolean Return the flag which indicates whether the sprite is flipped vertically or not. <br><br>It only flips the texture of the sprite, and not the texture of the sprite's children. Also, flipping the texture doesn't alter the anchorPoint. If you want to flip the anchorPoint too, and/or to flip the children too use: sprite->setScaleY(sprite->getScaleY() * -1); <br><br>\return true if the sprite is flipped vertically, false otherwise.
---@field offsetPosition cc.Vec2 Gets the offset position of the sprite. Calculated automatically by editors like Zwoptex.
---@field resourceName string 
---@field resourceType integer \}
---@field spriteFrame cc.SpriteFrame Returns the current displayed frame.
---@field stretchEnabled boolean returns whether or not contentSize stretches the sprite's texture
---@field texture cc.Texture2D Returns the Texture2D object used by the sprite.
---@field textureAtlas cc.TextureAtlas Gets the weak reference of the TextureAtlas when the sprite is rendered using via SpriteBatchNode.
---@field textureRect cc.Rect Returns the rect of the Sprite in points.
---@field textureRectRotated boolean Returns whether or not the texture rectangle is rotated.
---@field INDEX_NOT_INITIALIZED integer
local Sprite = {}

---@param cls string
---@return any
function Sprite:as(cls) end

---Creates an empty sprite without texture. You can call setTexture method subsequently.
---
---\memberof Sprite
---@return cc.Sprite # An autoreleased sprite object.
---
---Creates a sprite with an image filename.
---
---After creation, the rect of sprite will be the size of the image,
---and the offset will be (0,0).
---
---\param   filename A path to image file, e.g., "scene1/monster.png".
---\return  An autoreleased sprite object.
---@overload fun(filename: string): cc.Sprite
---
---Creates a sprite with an image filename and a rect.
---
---\param   filename A path to image file, e.g., "scene1/monster.png".
---\param   rect     A subrect of the image file.
---\return  An autoreleased sprite object.
---@overload fun(filename: string, rect: cc.Rect): cc.Sprite
function Sprite.create() end

---Creates a sprite with an sprite frame.
---
---@param spriteFrame cc.SpriteFrame # A sprite frame which involves a texture and a rect.
---@return cc.Sprite # An autoreleased sprite object.
function Sprite.createWithSpriteFrame(spriteFrame) end

---Creates a sprite with an sprite frame name.
---
---A SpriteFrame will be fetched from the SpriteFrameCache by spriteFrameName param.
---If the SpriteFrame doesn't exist it will raise an exception.
---
---@param spriteFrameName string # The name of sprite frame.
---@return cc.Sprite # An autoreleased sprite object.
function Sprite.createWithSpriteFrameName(spriteFrameName) end

---Creates a sprite with a Texture2D object.
---
---After creation, the rect will be the size of the texture, and the offset will be (0,0).
---
---@param texture cc.Texture2D # A pointer to a Texture2D object.
---@return cc.Sprite # An autoreleased sprite object.
---
---Creates a sprite with a texture and a rect.
---
---After creation, the offset will be (0,0).
---
---\param   texture     A pointer to an existing Texture2D object.
---You can use a Texture2D object for many sprites.
---\param   rect        Only the contents inside the rect of this texture will be applied for this sprite.
---\param   rotated     Whether or not the rect is rotated.
---\return  An autoreleased sprite object.
---@overload fun(texture: cc.Texture2D, rect: cc.Rect, rotated: boolean): cc.Sprite
---
---Creates a sprite with a texture and a rect.
---
---After creation, the offset will be (0,0).
---
---\param   texture     A pointer to an existing Texture2D object.
---You can use a Texture2D object for many sprites.
---\param   rect        Only the contents inside the rect of this texture will be applied for this sprite.
---\param   rotated     Whether or not the rect is rotated.
---\return  An autoreleased sprite object.
---@overload fun(texture: cc.Texture2D, rect: cc.Rect): cc.Sprite
function Sprite.createWithTexture(texture) end

---Returns the index used on the TextureAtlas.
---@return integer
function Sprite:getAtlasIndex() end

---Returns the batch node object if this sprite is rendered by SpriteBatchNode.
---
---@return cc.SpriteBatchNode # The SpriteBatchNode object if this sprite is rendered by SpriteBatchNode,
---nullptr if the sprite isn't used batch node.
function Sprite:getBatchNode() end

---\js  NA
---\lua NA
---@return cc.BlendFunc
function Sprite:getBlendFunc() end

---Returns the Cap Insets rect
---
---@return cc.Rect # Scale9Sprite's cap inset.
function Sprite:getCenterRect() end

---getCenterRectNormalized
---
---Returns the CenterRect in normalized coordinates
---@return cc.Rect
function Sprite:getCenterRectNormalized() end

---Gets the offset position of the sprite. Calculated automatically by editors like Zwoptex.
---@return cc.Vec2
function Sprite:getOffsetPosition() end

---@return string
function Sprite:getResourceName() end

---\}
---@return integer
function Sprite:getResourceType() end

---Returns the current displayed frame.
---@return cc.SpriteFrame
function Sprite:getSpriteFrame() end

---Returns the Texture2D object used by the sprite.
---@return cc.Texture2D
function Sprite:getTexture() end

---Gets the weak reference of the TextureAtlas when the sprite is rendered using via SpriteBatchNode.
---@return cc.TextureAtlas
function Sprite:getTextureAtlas() end

---Returns the rect of the Sprite in points.
---@return cc.Rect
function Sprite:getTextureRect() end

---Initializes a sprite with an image filename.
---
---This method will find filename from local file system, load its content to Texture2D,
---then use Texture2D to create a sprite.
---After initialization, the rect used will be the size of the image. The offset will be (0,0).
---
---@param filename string # The path to an image file in local file system.
---@return boolean # True if the sprite is initialized properly, false otherwise.
---\lua     init
---
---Initializes a sprite with an image filename, and a rect.
---
---This method will find filename from local file system, load its content to Texture2D,
---then use Texture2D to create a sprite.
---After initialization, the offset will be (0,0).
---
---\param   filename The path to an image file in local file system.
---\param   rect        The rectangle assigned the content area from texture.
---\return  True if the sprite is initialized properly, false otherwise.
---\lua     init
---@overload fun(self: cc.Sprite, filename: string, rect: cc.Rect): boolean
function Sprite:initWithFile(filename) end

---Initializes a sprite with an SpriteFrame. The texture and rect in SpriteFrame will be applied on this sprite.
---
---@param spriteFrame cc.SpriteFrame # A SpriteFrame object. It should includes a valid texture and a rect.
---@return boolean # True if the sprite is initialized properly, false otherwise.
function Sprite:initWithSpriteFrame(spriteFrame) end

---Initializes a sprite with an sprite frame name.
---
---A SpriteFrame will be fetched from the SpriteFrameCache by name.
---If the SpriteFrame doesn't exist it will raise an exception.
---
---@param spriteFrameName string # A key string that can fetched a valid SpriteFrame from SpriteFrameCache.
---@return boolean # True if the sprite is initialized properly, false otherwise.
function Sprite:initWithSpriteFrameName(spriteFrameName) end

---Initializes a sprite with a texture.
---
---After initialization, the rect used will be the size of the texture, and the offset will be (0,0).
---
---@param texture cc.Texture2D # A pointer to an existing Texture2D object.
---You can use a Texture2D object for many sprites.
---@return boolean # True if the sprite is initialized properly, false otherwise.
---
---Initializes a sprite with a texture and a rect.
---
---After initialization, the offset will be (0,0).
---
---\param   texture    A pointer to an existing Texture2D object.
---You can use a Texture2D object for many sprites.
---\param   rect        Only the contents inside rect of this texture will be applied for this sprite.
---\return  True if the sprite is initialized properly, false otherwise.
---@overload fun(self: cc.Sprite, texture: cc.Texture2D, rect: cc.Rect): boolean
---
---Initializes a sprite with a texture and a rect in points, optionally rotated.
---
---After initialization, the offset will be (0,0).
---\note    This is the designated initializer.
---
---\param   texture    A Texture2D object whose texture will be applied to this sprite.
---\param   rect        A rectangle assigned the contents of texture.
---\param   rotated     Whether or not the texture rectangle is rotated.
---\return  True if the sprite is initialized properly, false otherwise.
---@overload fun(self: cc.Sprite, texture: cc.Texture2D, rect: cc.Rect, rotated: boolean): boolean
function Sprite:initWithTexture(texture) end

---Whether or not the Sprite needs to be updated in the Atlas.
---
---@return boolean # True if the sprite needs to be updated in the Atlas, false otherwise.
function Sprite:isDirty() end

---Returns the flag which indicates whether the sprite is flipped horizontally or not.
---
---It only flips the texture of the sprite, and not the texture of the sprite's children.
---Also, flipping the texture doesn't alter the anchorPoint.
---If you want to flip the anchorPoint too, and/or to flip the children too use:
---sprite->setScaleX(sprite->getScaleX() * -1);
---
---@return boolean # true if the sprite is flipped horizontally, false otherwise.
function Sprite:isFlippedX() end

---Return the flag which indicates whether the sprite is flipped vertically or not.
---
---It only flips the texture of the sprite, and not the texture of the sprite's children.
---Also, flipping the texture doesn't alter the anchorPoint.
---If you want to flip the anchorPoint too, and/or to flip the children too use:
---sprite->setScaleY(sprite->getScaleY() * -1);
---
---@return boolean # true if the sprite is flipped vertically, false otherwise.
function Sprite:isFlippedY() end

---Returns whether or not a SpriteFrame is being displayed.
---@param frame cc.SpriteFrame
---@return boolean
function Sprite:isFrameDisplayed(frame) end

---returns whether or not contentSize stretches the sprite's texture
---@return boolean
function Sprite:isStretchEnabled() end

---Returns whether or not the texture rectangle is rotated.
---@return boolean
function Sprite:isTextureRectRotated() end

---\js ctor
---@return cc.Sprite
function Sprite.new() end

---Sets the index used on the TextureAtlas.
---
---\warning Don't modify this value unless you know what you are doing.
---@param atlasIndex integer
function Sprite:setAtlasIndex(atlasIndex) end

---Sets the batch node to sprite.
---\warning This method is not recommended for game developers. Sample code for using batch node
---\code
---SpriteBatchNode *batch = SpriteBatchNode::create("Images/grossini_dance_atlas.png", 15);
---Sprite *sprite = Sprite::createWithTexture(batch->getTexture(), Rect(0, 0, 57, 57));
---batch->addChild(sprite);
---layer->addChild(batch);
---\endcode
---@param spriteBatchNode cc.SpriteBatchNode
function Sprite:setBatchNode(spriteBatchNode) end

---\{
---\name Functions inherited from TextureProtocol.
---
---\code
---When this function bound into js or lua,the parameter will be changed.
---In js: var setBlendFunc(var src, var dst).
---In lua: local setBlendFunc(local src, local dst).
---\endcode
---@param blendFunc cc.BlendFunc
function Sprite:setBlendFunc(blendFunc) end

---@param rect cc.Rect
function Sprite:setCenterRect(rect) end

---setCenterRectNormalized
---
---Useful to implement "9 sliced" sprites.
---The default value is (0,0) - (1,1), which means that only one "slice" will be used: From top-left (0,0) to bottom-right (1,1).
---If the value is different than (0,0), (1,1), then the sprite will be sliced into a 3 x 3 grid. The four corners of this grid are applied without
---performing any scaling. The upper- and lower-middle parts are scaled horizontally, and the left- and right-middle parts are scaled vertically.
---The center is scaled in both directions.
---Important: The scaling is based the Sprite's trimmed size.
---
---Limitations: Does not work when the sprite is part of `SpriteBatchNode`.
---@param rect cc.Rect
function Sprite:setCenterRectNormalized(rect) end

---Makes the Sprite to be updated in the Atlas.
---@param dirty boolean
function Sprite:setDirty(dirty) end

---\{
---\name Animation methods
---
---Changes the display frame with animation name and index.
---The animation name will be get from the AnimationCache.
---@param animationName string
---@param frameIndex integer
function Sprite:setDisplayFrameWithAnimationName(animationName, frameIndex) end

---Sets whether the sprite should be flipped horizontally or not.
---
---@param flippedX boolean # true if the sprite should be flipped horizontally, false otherwise.
function Sprite:setFlippedX(flippedX) end

---Sets whether the sprite should be flipped vertically or not.
---
---@param flippedY boolean # true if the sprite should be flipped vertically, false otherwise.
function Sprite:setFlippedY(flippedY) end

---\{
---Sets a new SpriteFrame to the Sprite.
---@param spriteFrameName string
---@overload fun(self: cc.Sprite, newFrame: cc.SpriteFrame)
function Sprite:setSpriteFrame(spriteFrameName) end

---whether or not contentSize stretches the sprite's texture
---@param enabled boolean
function Sprite:setStretchEnabled(enabled) end

---Sets a new texture (from a filename) to the sprite.
---
---\memberof Sprite
---It will call `setTextureRect()` with the texture's content size.
---@param filename string
---
---\overload
---
---The Texture's rect is not changed.
---@overload fun(self: cc.Sprite, texture: cc.Texture2D)
function Sprite:setTexture(filename) end

---Sets the weak reference of the TextureAtlas when the sprite is rendered using via SpriteBatchNode.
---@param textureAtlas cc.TextureAtlas
function Sprite:setTextureAtlas(textureAtlas) end

---Updates the texture rect of the Sprite in points.
---
---It will call setTextureRect(const Rect& rect, bool rotated, const Size& untrimmedSize) with \p rotated = false, and \p utrimmedSize = rect.size.
---@param rect cc.Rect
---
---\overload
---
---It will update the texture coordinates and the vertex rectangle.
---@overload fun(self: cc.Sprite, rect: cc.Rect, rotated: boolean, untrimmedSize: cc.Size)
function Sprite:setTextureRect(rect) end

function Sprite:setVertexLayout() end

---Sets the vertex rect.
---
---It will be called internally by setTextureRect.
---Useful if you want to create 2x images from SD images in Retina Display.
---Do not call it manually. Use setTextureRect instead.
---@param rect cc.Rect
function Sprite:setVertexRect(rect) end

---@param vert string
---@param frag string
function Sprite:updateShaders(vert, frag) end

return Sprite