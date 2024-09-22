---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.SpriteFrame

---\class SpriteFrame
---A SpriteFrame has:
---- texture: A Texture2D that will be used by the Sprite
---- rectangle: A rectangle of the texture
---You can modify the frame of a Sprite by doing:
---
---\code
---SpriteFrame* frame = SpriteFrame::createWithTexture(texture, rect);
---sprite->setSpriteFrame(frame);
---\endcode
---@class cc.SpriteFrame : cc.Ref
---@field anchorPoint cc.Vec2 Get anchor point of the frame. <br><br>\return The anchor point of the sprite frame.
---@field centerRect cc.Rect Get center rect of the frame. <br><br>Useful to create 9-slice sprites <br><br>\return The center rect of the sprite frame in points
---@field offset cc.Vec2 Get offset of the frame. <br><br>\return The offset of the sprite frame.
---@field offsetInPixels cc.Vec2 Get offset of the frame. <br><br>\return The offset of the sprite frame, in pixels.
---@field originalSize cc.Size Get original size of the trimmed image. <br><br>\return The original size of the trimmed image.
---@field originalSizeInPixels cc.Size Get original size of the trimmed image. <br><br>\return The original size of the trimmed image, in pixels.
---@field rect cc.Rect Get rect of the frame. <br><br>\return The rect of the sprite frame.
---@field rectInPixels cc.Rect Get rect of the sprite frame. <br><br>\return The rect of the sprite frame, in pixels.
---@field rotated boolean Is the sprite frame rotated or not. <br><br>\return Is rotated if true.
---@field texture cc.Texture2D Get texture of the frame. <br><br>\return The texture of the sprite frame.
local SpriteFrame = {}

---@param cls string
---@return any
function SpriteFrame:as(cls) end

---@return cc.SpriteFrame
function SpriteFrame:clone() end

---Create a SpriteFrame with a texture filename, rect in points.
---It is assumed that the frame was not trimmed.
---
---@param filename string # Texture file name.
---@param rect cc.Rect # A specified rect.
---@return cc.SpriteFrame # An autoreleased SpriteFrame object.
---
---Create a SpriteFrame with a texture filename, rect, rotated, offset and originalSize in pixels.
---The originalSize is the size in pixels of the frame before being trimmed.
---
---\param filename Texture filename
---\param rect A specified rect.
---\param rotated Is rotated if true.
---\param offset A specified offset.
---\param originalSize A specified original size.
---\return An autoreleased SpriteFrame object.
---@overload fun(filename: string, rect: cc.Rect, rotated: boolean, offset: cc.Vec2, originalSize: cc.Size): cc.SpriteFrame
function SpriteFrame.create(filename, rect) end

---Create a SpriteFrame with a texture, rect in points.
---It is assumed that the frame was not trimmed.
---@param pobTexture cc.Texture2D # The texture pointer.
---@param rect cc.Rect # A specified rect.
---@return cc.SpriteFrame # An autoreleased SpriteFrame object.
---
---Create a SpriteFrame with a texture, rect, rotated, offset and originalSize in pixels.
---The originalSize is the size in points of the frame before being trimmed.
---\param pobTexture The texture pointer.
---\param rect A specified rect.
---\param rotated Is rotated if true.
---\param offset A specified offset.
---\param originalSize A specified original size.
---\return An autoreleased SpriteFrame object.
---@overload fun(pobTexture: cc.Texture2D, rect: cc.Rect, rotated: boolean, offset: cc.Vec2, originalSize: cc.Size): cc.SpriteFrame
function SpriteFrame.createWithTexture(pobTexture, rect) end

---Get anchor point of the frame.
---
---@return cc.Vec2 # The anchor point of the sprite frame.
function SpriteFrame:getAnchorPoint() end

---Get center rect of the frame.
---
---Useful to create 9-slice sprites
---
---@return cc.Rect # The center rect of the sprite frame in points
function SpriteFrame:getCenterRect() end

---Get offset of the frame.
---
---@return cc.Vec2 # The offset of the sprite frame.
function SpriteFrame:getOffset() end

---Get offset of the frame.
---
---@return cc.Vec2 # The offset of the sprite frame, in pixels.
function SpriteFrame:getOffsetInPixels() end

---Get original size of the trimmed image.
---
---@return cc.Size # The original size of the trimmed image.
function SpriteFrame:getOriginalSize() end

---Get original size of the trimmed image.
---
---@return cc.Size # The original size of the trimmed image, in pixels.
function SpriteFrame:getOriginalSizeInPixels() end

---Get rect of the frame.
---
---@return cc.Rect # The rect of the sprite frame.
function SpriteFrame:getRect() end

---Get rect of the sprite frame.
---
---@return cc.Rect # The rect of the sprite frame, in pixels.
function SpriteFrame:getRectInPixels() end

---Get texture of the frame.
---
---@return cc.Texture2D # The texture of the sprite frame.
function SpriteFrame:getTexture() end

---Check if anchor point is defined for the frame.
---
---@return boolean # true if anchor point is available.
function SpriteFrame:hasAnchorPoint() end

---hasCenterRect
---@return boolean # Whether or not it has a centerRect
function SpriteFrame:hasCenterRect() end

---Check if sprite frame is a polygon sprite
---
---@return boolean # true if polygonInfo is available
function SpriteFrame:hasPolygonInfo() end

---Initializes a SpriteFrame with a texture, rect in points.
---It is assumed that the frame was not trimmed.
---@param pobTexture cc.Texture2D
---@param rect cc.Rect
---@return boolean
---
---Initializes a SpriteFrame with a texture, rect, rotated, offset and originalSize in pixels.
---The originalSize is the size in points of the frame before being trimmed.
---@overload fun(self: cc.SpriteFrame, pobTexture: cc.Texture2D, rect: cc.Rect, rotated: boolean, offset: cc.Vec2, originalSize: cc.Size): boolean
function SpriteFrame:initWithTexture(pobTexture, rect) end

---Initializes a SpriteFrame with a texture filename, rect in points;
---It is assumed that the frame was not trimmed.
---@param filename string
---@param rect cc.Rect
---@return boolean
---
---Initializes a SpriteFrame with a texture, rect, rotated, offset and originalSize in pixels.
---The originalSize is the size in pixels of the frame before being trimmed.
---
---\since v1.1
---@overload fun(self: cc.SpriteFrame, filename: string, rect: cc.Rect, rotated: boolean, offset: cc.Vec2, originalSize: cc.Size): boolean
function SpriteFrame:initWithTextureFilename(filename, rect) end

---Is the sprite frame rotated or not.
---
---@return boolean # Is rotated if true.
function SpriteFrame:isRotated() end

---\lua NA
---@return cc.SpriteFrame
function SpriteFrame.new() end

---Set anchor point of the frame.
---
---@param anchorPoint cc.Vec2 # The anchor point of the sprite frame.
function SpriteFrame:setAnchorPoint(anchorPoint) end

---setCenterRect
---
---Useful to implement "9 sliced" sprites.
---The sprite will be sliced into a 3 x 3 grid. The four corners of this grid are applied without
---performing any scaling. The upper- and lower-middle parts are scaled horizontally, and the left- and right-middle parts are scaled vertically.
---The center is scaled in both directions.
---Important: The scaling is based the Sprite's trimmed size.
---
---Limitations: Does not work when the sprite is part of `SpriteBatchNode`.
---@param centerRect cc.Rect # the Rect in points
function SpriteFrame:setCenterRectInPixels(centerRect) end

---Set offset of the frame.
---
---@param offsets cc.Vec2 # The offset of the sprite frame.
function SpriteFrame:setOffset(offsets) end

---Set offset of the frame.
---
---@param offsetInPixels cc.Vec2 # The offset of the sprite frame, in pixels.
function SpriteFrame:setOffsetInPixels(offsetInPixels) end

---Set original size of the trimmed image.
---
---@param sizeInPixels cc.Size # The original size of the trimmed image.
function SpriteFrame:setOriginalSize(sizeInPixels) end

---Set original size of the trimmed image.
---
---@param sizeInPixels cc.Size # The original size of the trimmed image, in pixels.
function SpriteFrame:setOriginalSizeInPixels(sizeInPixels) end

---Set rect of the frame.
---
---@param rect cc.Rect # The rect of the sprite.
function SpriteFrame:setRect(rect) end

---Set rect of the sprite frame.
---
---@param rectInPixels cc.Rect # The rect of the sprite frame, in pixels.
function SpriteFrame:setRectInPixels(rectInPixels) end

---Set rotated of the sprite frame.
---
---@param rotated boolean # Rotated the sprite frame if true.
function SpriteFrame:setRotated(rotated) end

---Set texture of the frame, the texture is retained.
---
---@param pobTexture cc.Texture2D # The texture of the sprite frame.
function SpriteFrame:setTexture(pobTexture) end

return SpriteFrame