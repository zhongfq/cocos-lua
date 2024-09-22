---AUTO GENERATED, DO NOT MODIFY!
---@meta ccui.Scale9Sprite

---A 9-slice sprite for cocos2d-x.
---
---9-slice scaling allows you to specify how scaling is applied
---to specific areas of a sprite. With 9-slice scaling (3x3 grid),
---you can ensure that the sprite does not become distorted when
---scaled.
---Note: When you set _scale9Enabled to false,
---then you could call `scale9Sprite->getSprite()` to return the inner Sprite pointer.
---Then you could call any methods of Sprite class with the return pointers.
---@class ccui.Scale9Sprite : cc.Sprite
---@field capInsets cc.Rect Returns the Cap Insets
---@field insetBottom number Query the bottom sprite's cap inset. <br><br>\return The bottom sprite's cap inset.
---@field insetLeft number Query the left sprite's cap inset. <br><br>\return The left sprite's cap inset.
---@field insetRight number Query the right sprite's cap inset. <br><br>\return The right sprite's cap inset.
---@field insetTop number Query the top sprite's cap inset. <br><br>\return The top sprite's cap inset.
---@field originalSize cc.Size Query the sprite's original size. <br><br>\return Sprite size.
---@field preferredSize cc.Size Query the Scale9Sprite's preferred size. <br><br>\return Scale9Sprite's preferred size.
---@field renderingType ccui.Scale9Sprite.RenderingType Return the slice sprite rendering type.
---@field scale9Enabled boolean Query whether the Scale9Sprite is enable 9-slice or not. <br><br>\return True if 9-slice is enabled, false otherwise. \js NA
---@field sprite cc.Sprite Get the original no 9-sliced sprite <br><br>\return A sprite instance.
---@field state ccui.Scale9Sprite.State Query the current bright state. \return @see `State` \since v3.7
local Scale9Sprite = {}

---copies self to copy
---@param copy ccui.Scale9Sprite
function Scale9Sprite:copyTo(copy) end

---Create an empty Scale9Sprite.
---
---@return ccui.Scale9Sprite # A Scale9Sprite instance.
---
---Creates a 9-slice sprite with a texture file, a delimitation zone and
---with the specified cap insets.
---
---\see initWithFile(const char *file, const Rect& rect, const Rect& capInsets)
---\param file A texture file name.
---\param rect A delimitation zone.
---\param capInsets A specified cap insets.
---\return A Scale9Sprite instance.
---@overload fun(file: string, rect: cc.Rect, capInsets: cc.Rect): ccui.Scale9Sprite
---
---Creates a 9-slice sprite with a texture file. The whole texture will be
---broken down into a 3×3 grid of equal blocks.
---
---\see initWithFile(const Rect& capInsets, const char *file)
---\param capInsets A specified cap insets.
---\param file A texture file name.
---\return A Scale9Sprite instance.
---@overload fun(capInsets: cc.Rect, file: string): ccui.Scale9Sprite
---
---Creates a 9-slice sprite with a texture file and a delimitation zone. The
---texture will be broken down into a 3×3 grid of equal blocks.
---
---\see initWithFile(const char *file, const Rect& rect)
---\param file A texture file name.
---\param rect A delimitation zone.
---\return A Scale9Sprite instance.
---@overload fun(file: string, rect: cc.Rect): ccui.Scale9Sprite
---
---Creates a 9-slice sprite with a texture file. The whole texture will be
---broken down into a 3×3 grid of equal blocks.
---
---\see initWithFile(const char *file)
---\param file A texture file name.
---\return A Scale9Sprite instance.
---@overload fun(file: string): ccui.Scale9Sprite
function Scale9Sprite.create() end

---Creates a 9-slice sprite with an sprite frame.
---Once the sprite is created, you can then call its "setContentSize:" method
---to resize the sprite will all it's 9-slice goodness interact.
---It respects the anchorPoint too.
---
---\see initWithSpriteFrame(SpriteFrame *spriteFrame)
---@param spriteFrame cc.SpriteFrame # A sprite frame pointer.
---@return ccui.Scale9Sprite # A Scale9Sprite instance.
---
---Creates a 9-slice sprite with an sprite frame and the centre of its zone.
---Once the sprite is created, you can then call its "setContentSize:" method
---to resize the sprite will all it's 9-slice goodness interact.
---It respects the anchorPoint too.
---
---\see initWithSpriteFrame(SpriteFrame *spriteFrame, const Rect& capInsets)
---\param spriteFrame A sprite frame pointer.
---\param capInsets  A delimitation zone.
---\return A Scale9Sprite instance.
---@overload fun(spriteFrame: cc.SpriteFrame, capInsets: cc.Rect): ccui.Scale9Sprite
function Scale9Sprite.createWithSpriteFrame(spriteFrame) end

---Creates a 9-slice sprite with an sprite frame name.
---Once the sprite is created, you can then call its "setContentSize:" method
---to resize the sprite will all it's 9-slice goodness interact.
---It respects the anchorPoint too.
---
---\see initWithSpriteFrameName(const char *spriteFrameName)
---@param spriteFrameName string # A sprite frame name.
---@return ccui.Scale9Sprite # A Scale9Sprite instance.
---
---Creates a 9-slice sprite with an sprite frame name and the centre of its zone.
---Once the sprite is created, you can then call its "setContentSize:" method
---to resize the sprite will all it's 9-slice goodness interact.
---It respects the anchorPoint too.
---
---\see initWithSpriteFrameName(const char *spriteFrameName, const Rect& capInsets)
---\param spriteFrameName A sprite frame name.
---\param capInsets A delimitation zone.
---\return A Scale9Sprite instance.
---@overload fun(spriteFrameName: string, capInsets: cc.Rect): ccui.Scale9Sprite
function Scale9Sprite.createWithSpriteFrameName(spriteFrameName) end

---Returns the Cap Insets
---@return cc.Rect
function Scale9Sprite:getCapInsets() end

---Query the bottom sprite's cap inset.
---
---@return number # The bottom sprite's cap inset.
function Scale9Sprite:getInsetBottom() end

---Query the left sprite's cap inset.
---
---@return number # The left sprite's cap inset.
function Scale9Sprite:getInsetLeft() end

---Query the right sprite's cap inset.
---
---@return number # The right sprite's cap inset.
function Scale9Sprite:getInsetRight() end

---Query the top sprite's cap inset.
---
---@return number # The top sprite's cap inset.
function Scale9Sprite:getInsetTop() end

---Query the sprite's original size.
---
---@return cc.Size # Sprite size.
function Scale9Sprite:getOriginalSize() end

---Query the Scale9Sprite's preferred size.
---
---@return cc.Size # Scale9Sprite's preferred size.
function Scale9Sprite:getPreferredSize() end

---Return the slice sprite rendering type.
---@return ccui.Scale9Sprite.RenderingType
function Scale9Sprite:getRenderingType() end

---Get the original no 9-sliced sprite
---
---@return cc.Sprite # A sprite instance.
function Scale9Sprite:getSprite() end

---Query the current bright state.
---@return ccui.Scale9Sprite.State # @see `State`
---\since v3.7
function Scale9Sprite:getState() end

---@return boolean
---
---Initializes a 9-slice sprite with an sprite instance.
---Once the sprite is created, you can then call its "setContentSize:" method
---to resize the sprite will all it's 9-slice goodness interact.
---It respects the anchorPoint too.
---
---\param sprite The sprite instance.
---\param rect A delimitation zone.
---\param rotated Whether the sprite is rotated or not.
---\param capInsets The values to use for the cap insets.
---\return True if initializes success, false otherwise.
---@overload fun(self: ccui.Scale9Sprite, sprite: cc.Sprite, rect: cc.Rect, rotated: boolean, capInsets: cc.Rect): boolean
---
---Initializes a 9-slice sprite with an sprite instance.
---Once the sprite is created, you can then call its "setContentSize:" method
---to resize the sprite will all it's 9-slice goodness interact.
---It respects the anchorPoint too.
---
---\param sprite The sprite instance.
---\param rect A delimitation zone.
---\param capInsets The values to use for the cap insets.
---\return True if initializes success, false otherwise.
---@overload fun(self: ccui.Scale9Sprite, sprite: cc.Sprite, rect: cc.Rect, capInsets: cc.Rect): boolean
---
---Initializes a 9-slice sprite with an sprite instance.
---Once the sprite is created, you can then call its "setContentSize:" method
---to resize the sprite will all it's 9-slice goodness interact.
---It respects the anchorPoint too.
---
---\param sprite The sprite instance.
---\param rect A delimitation zone.
---\param rotated Whether the sprite is rotated or not.
---\param offset The offset when slice the sprite.
---\param originalSize The original size of sprite.
---\param capInsets The values to use for the cap insets.
---\return True if initializes success, false otherwise.
---@overload fun(self: ccui.Scale9Sprite, sprite: cc.Sprite, rect: cc.Rect, rotated: boolean, offset: cc.Vec2, originalSize: cc.Size, capInsets: cc.Rect): boolean
function Scale9Sprite:init() end

---Initializes a 9-slice sprite with a texture file, a delimitation zone and
---with the specified cap insets.
---Once the sprite is created, you can then call its "setContentSize:" method
---to resize the sprite will all it's 9-slice goodness interact.
---It respects the anchorPoint too.
---
---@param file string # The name of the texture file.
---@param rect cc.Rect # The rectangle that describes the sub-part of the texture that
---is the whole image. If the shape is the whole texture, set this to the
---texture's full rect.
---@param capInsets cc.Rect # The values to use for the cap insets.
---@return boolean # True if initialize success, false otherwise.
---
---Initializes a 9-slice sprite with a texture file and with the specified cap
---insets.
---Once the sprite is created, you can then call its "setContentSize:" method
---to resize the sprite will all it's 9-slice goodness interact.
---It respects the anchorPoint too.
---
---\param file The name of the texture file.
---\param capInsets The values to use for the cap insets.
---\return True if initializes success, false otherwise.
---@overload fun(self: ccui.Scale9Sprite, capInsets: cc.Rect, file: string): boolean
---
---Initializes a 9-slice sprite with a texture file and a delimitation zone. The
---texture will be broken down into a 3×3 grid of equal blocks.
---Once the sprite is created, you can then call its "setContentSize:" method
---to resize the sprite will all it's 9-slice goodness interact.
---It respects the anchorPoint too.
---
---\param file The name of the texture file.
---\param rect The rectangle that describes the sub-part of the texture that
---is the whole image. If the shape is the whole texture, set this to the
---texture's full rect.
---\return True if initializes success, false otherwise.
---@overload fun(self: ccui.Scale9Sprite, file: string, rect: cc.Rect): boolean
---
---Initializes a 9-slice sprite with a texture file. The whole texture will be
---broken down into a 3×3 grid of equal blocks.
---Once the sprite is created, you can then call its "setContentSize:" method
---to resize the sprite will all it's 9-slice goodness interact.
---It respects the anchorPoint too.
---
---\param file The name of the texture file.
---\return True if initializes success, false otherwise.
---@overload fun(self: ccui.Scale9Sprite, file: string): boolean
function Scale9Sprite:initWithFile(file, rect, capInsets) end

---Initializes a 9-slice sprite with an sprite frame and with the specified
---cap insets.
---Once the sprite is created, you can then call its "setContentSize:" method
---to resize the sprite will all it's 9-slice goodness interact.
---It respects the anchorPoint too.
---
---@param spriteFrame cc.SpriteFrame # The sprite frame object.
---@param capInsets cc.Rect # The values to use for the cap insets.
---@return boolean # True if initializes success, false otherwise.
---
---Initializes a sprite with an SpriteFrame. The texture and rect in SpriteFrame will be applied on this sprite.
---
---\param   spriteFrame  A SpriteFrame object. It should includes a valid texture and a rect.
---\return  True if the sprite is initialized properly, false otherwise.
---@overload fun(self: ccui.Scale9Sprite, spriteFrame: cc.SpriteFrame): boolean
function Scale9Sprite:initWithSpriteFrame(spriteFrame, capInsets) end

---Initializes a 9-slice sprite with an sprite frame name and with the specified
---cap insets.
---Once the sprite is created, you can then call its "setContentSize:" method
---to resize the sprite will all it's 9-slice goodness interact.
---It respects the anchorPoint too.
---
---@param spriteFrameName string # The sprite frame name.
---@param capInsets cc.Rect # The values to use for the cap insets.
---@return boolean # True if initializes success, false otherwise.
---
---Initializes a 9-slice sprite with an sprite frame name.
---Once the sprite is created, you can then call its "setContentSize:" method
---to resize the sprite will all it's 9-slice goodness interact.
---It respects the anchorPoint too.
---
---\param spriteFrameName The sprite frame name.
---\return True if initializes success, false otherwise.
---@overload fun(self: ccui.Scale9Sprite, spriteFrameName: string): boolean
function Scale9Sprite:initWithSpriteFrameName(spriteFrameName, capInsets) end

---Query whether the Scale9Sprite is enable 9-slice or not.
---
---@return boolean # True if 9-slice is enabled, false otherwise.
---\js NA
function Scale9Sprite:isScale9Enabled() end

---Default constructor.
---\js ctor
---\lua new
---@return ccui.Scale9Sprite
function Scale9Sprite.new() end

function Scale9Sprite:resetRender() end

---Creates and returns a new sprite object with the specified cap insets.
---You use this method to add cap insets to a sprite or to change the existing
---cap insets of a sprite. In both cases, you get back a new image and the
---original sprite remains untouched.
---
---@param capInsets cc.Rect # The values to use for the cap insets.
---@return ccui.Scale9Sprite # A Scale9Sprite instance.
function Scale9Sprite:resizableSpriteWithCapInsets(capInsets) end

---Set the Cap Insets in Points using the untrimmed size as reference
---@param insets cc.Rect
function Scale9Sprite:setCapInsets(insets) end

---Change the bottom sprite's cap inset.
---
---@param bottomInset number # The values to use for the cap inset.
function Scale9Sprite:setInsetBottom(bottomInset) end

---Change the left sprite's cap inset.
---
---@param leftInset number # The values to use for the cap inset.
function Scale9Sprite:setInsetLeft(leftInset) end

---Change the right sprite's cap inset.
---
---@param rightInset number # The values to use for the cap inset.
function Scale9Sprite:setInsetRight(rightInset) end

---Change the top sprite's cap inset.
---
---@param topInset number # The values to use for the cap inset.
function Scale9Sprite:setInsetTop(topInset) end

---Change the preferred size of Scale9Sprite.
---
---@param size cc.Size # A delimitation zone.
function Scale9Sprite:setPreferredSize(size) end

---Set the slice sprite rendering type.
---When setting to SIMPLE, only 4 vertexes is used to rendering.
---otherwise 16 vertexes will be used to rendering.
---\see RenderingType
---@param type ccui.Scale9Sprite.RenderingType
function Scale9Sprite:setRenderingType(type) end

---Toggle 9-slice feature.
---If Scale9Sprite is 9-slice disabled, the Scale9Sprite will rendered as a normal sprite.
---\warning: Don't use setScale9Enabled(false), use setRenderingType(RenderingType::SIMPLE) instead.
---The setScale9Enabled(false) is kept only for back back compatibility.
---@param enabled boolean # True to enable 9-slice, false otherwise.
---\js NA
function Scale9Sprite:setScale9Enabled(enabled) end

---Change inner sprite's sprite frame.
---
---@param spriteFrame cc.SpriteFrame # A sprite frame pointer.
---@param capInsets cc.Rect # The values to use for the cap insets.
---
---\{
---Sets a new SpriteFrame to the Sprite.
---@overload fun(self: ccui.Scale9Sprite, spriteFrameName: string)
---@overload fun(self: ccui.Scale9Sprite, newFrame: cc.SpriteFrame)
function Scale9Sprite:setSpriteFrame(spriteFrame, capInsets) end

---Change the state of 9-slice sprite.
---\see `State`
---@param state ccui.Scale9Sprite.State # A enum value in State.
---\since v3.4
function Scale9Sprite:setState(state) end

---Update Scale9Sprite with a specified sprite.
---
---@param sprite cc.Sprite # A sprite pointer.
---@param rect cc.Rect # A delimitation zone.
---@param rotated boolean # Whether the sprite is rotated or not.
---@param capInsets cc.Rect # The Values to use for the cap insets.
---@return boolean # True if update success, false otherwise.
---\js NA
---
---Update Scale9Sprite with a specified sprite.
---
---\param sprite A sprite pointer.
---\param rect A delimitation zone.
---\param rotated Whether the sprite is rotated or not.
---\param offset The offset when slice the sprite.
---\param originalSize The original size of the sprite.
---\param capInsets The Values to use for the cap insets.
---\return True if update success, false otherwise.
---\js NA
---@overload fun(self: ccui.Scale9Sprite, sprite: cc.Sprite, rect: cc.Rect, rotated: boolean, offset: cc.Vec2, originalSize: cc.Size, capInsets: cc.Rect): boolean
function Scale9Sprite:updateWithSprite(sprite, rect, rotated, capInsets) end

return Scale9Sprite