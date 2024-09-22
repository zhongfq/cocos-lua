---AUTO GENERATED, DO NOT MODIFY!
---@meta ccui.EditBox

---Class for edit box.
---
---You can use this widget to gather small amounts of text from the user.
---@class ccui.EditBox : ccui.Widget
---@field capInsetsDisabledRenderer cc.Rect Return the capInsets of disabled state scale9sprite. \return The disabled scale9 renderer capInsets.
---@field capInsetsNormalRenderer cc.Rect Return the capInsets of normal state scale9sprite. \return The normal scale9 renderer capInsets.
---@field capInsetsPressedRenderer cc.Rect Return the capInsets of pressed state scale9sprite. \return The pressed scale9 renderer capInsets.
---@field delegate ccui.EditBoxDelegate \js NA \lua NA
---@field fontColor any Get the font color of the widget's text.
---@field fontName string Get the font name. \return The font name.
---@field fontSize integer Get the font size. \return The font size.
---@field inputFlag ccui.EditBox.InputFlag Get the input flags that are to be applied to the edit box. \return One of the EditBox::InputFlag constants.
---@field inputMode ccui.EditBox.InputMode Get the input mode of the edit box. \return One of the EditBox::InputMode constants.
---@field maxLength integer Gets the maximum input length of the edit box. <br><br>\return Maximum input length.
---@field placeHolder string Get a text in the edit box that acts as a placeholder when an edit box is empty.
---@field placeholderFontColor any Get the font color of the placeholder text when the edit box is empty.
---@field placeholderFontName string Get the placeholder's font name. only system font is allowed. \return The font name.
---@field placeholderFontSize integer Get the placeholder's font size. \return The font size.
---@field returnType ccui.EditBox.KeyboardReturnType Get the return type that are to be applied to the edit box. \return One of the EditBox::KeyboardReturnType constants.
---@field text string Get the text entered in the edit box. \return The text entered in the edit box.
---@field textHorizontalAlignment cc.TextHAlignment Get the text horizontal alignment.
local EditBox = {}

---@param cls string
---@return any
function EditBox:as(cls) end

---Default destructor.
---\js NA
---\lua NA
---@return boolean
function EditBox:attachWithIME() end

---create a edit box with size.
---@return ccui.EditBox # An autorelease pointer of EditBox, you don't need to release it only if you retain it again.
---@param size cc.Size
---@param normalSprite ccui.Scale9Sprite
---@param pressedSprite ccui.Scale9Sprite
---@param disabledSprite ccui.Scale9Sprite
---@overload fun(size: cc.Size, normalSprite: ccui.Scale9Sprite): ccui.EditBox
---@overload fun(size: cc.Size, normalSprite: ccui.Scale9Sprite, pressedSprite: ccui.Scale9Sprite): ccui.EditBox
---@overload fun(size: cc.Size, normalImage: string, texType: ccui.Widget.TextureResType): ccui.EditBox
---@overload fun(size: cc.Size, normalImage: string, pressedImage: string, disabledImage: string, texType: ccui.Widget.TextureResType): ccui.EditBox
---@overload fun(size: cc.Size, normalImage: string): ccui.EditBox
---@overload fun(size: cc.Size, normalImage: string, pressedImage: string): ccui.EditBox
---@overload fun(size: cc.Size, normalImage: string, pressedImage: string, disabledImage: string): ccui.EditBox
function EditBox.create(size, normalSprite, pressedSprite, disabledSprite) end

---Determine whether the IME is detached or not.
---\js NA
---\lua NA
---@return boolean
function EditBox:detachWithIME() end

---Return the capInsets of disabled state scale9sprite.
---@return cc.Rect # The disabled scale9 renderer capInsets.
function EditBox:getCapInsetsDisabledRenderer() end

---Return the capInsets of normal state scale9sprite.
---@return cc.Rect # The normal scale9 renderer capInsets.
function EditBox:getCapInsetsNormalRenderer() end

---Return the capInsets of pressed state scale9sprite.
---@return cc.Rect # The pressed scale9 renderer capInsets.
function EditBox:getCapInsetsPressedRenderer() end

---\js NA
---\lua NA
---@return ccui.EditBoxDelegate
function EditBox:getDelegate() end

---Get the font color of the widget's text.
---@return any
function EditBox:getFontColor() end

---Get the font name.
---@return string # The font name.
function EditBox:getFontName() end

---Get the font size.
---@return integer # The font size.
function EditBox:getFontSize() end

---Get the input flags that are to be applied to the edit box.
---@return ccui.EditBox.InputFlag # One of the EditBox::InputFlag constants.
function EditBox:getInputFlag() end

---Get the input mode of the edit box.
---@return ccui.EditBox.InputMode # One of the EditBox::InputMode constants.
function EditBox:getInputMode() end

---Gets the maximum input length of the edit box.
---
---@return integer # Maximum input length.
function EditBox:getMaxLength() end

---Get a text in the edit box that acts as a placeholder when an
---edit box is empty.
---@return string
function EditBox:getPlaceHolder() end

---Get the font color of the placeholder text when the edit box is empty.
---@return any
function EditBox:getPlaceholderFontColor() end

---Get the placeholder's font name. only system font is allowed.
---@return string # The font name.
function EditBox:getPlaceholderFontName() end

---Get the placeholder's font size.
---@return integer # The font size.
function EditBox:getPlaceholderFontSize() end

---Get the return type that are to be applied to the edit box.
---@return ccui.EditBox.KeyboardReturnType # One of the EditBox::KeyboardReturnType constants.
function EditBox:getReturnType() end

---Get the text entered in the edit box.
---@return string # The text entered in the edit box.
function EditBox:getText() end

---Get the text horizontal alignment.
---@return cc.TextHAlignment
function EditBox:getTextHorizontalAlignment() end

---Init edit box with specified size. This method should be invoked right after constructor.
---@param size cc.Size # The size of edit box.
---@param normal9SpriteBg string # background image of edit box.
---@param texType ccui.Widget.TextureResType # the resource type, the default value is TextureResType::LOCAL
---@return boolean # Whether initialization is successfully or not.
---@overload fun(self: ccui.EditBox, size: cc.Size, normal9SpriteBg: string): boolean
---
---Init edit box with specified size. This method should be invoked right after constructor.
---\param size The size of edit box.
---\param normal9SpriteBg  background image of edit box.
---\return Whether initialization is successfully or not.
---@overload fun(self: ccui.EditBox, size: cc.Size, normal9SpriteBg: ccui.Scale9Sprite): boolean
---
---Init edit box with specified size. This method should be invoked right after constructor.
---\param size The size of edit box.
---\param normalSprite  normal state image of edit box.
---\param pressedSprite  pressed state image of edit box.
---\param disabledSprite  disabled state image of edit box.
---\return Whether initialization is successfully or not.
---@overload fun(self: ccui.EditBox, size: cc.Size, normalSprite: ccui.Scale9Sprite, pressedSprite: ccui.Scale9Sprite, disabledSprite: ccui.Scale9Sprite): boolean
function EditBox:initWithSizeAndBackgroundSprite(size, normal9SpriteBg, texType) end

---Init edit box with specified size. This method should be invoked right after constructor.
---@param size cc.Size # The size of edit box.
---@param normalImage string # normal state texture name.
---@param pressedImage string # pressed state texture name.
---@param disabledImage string # disabled state texture name.
---@return boolean # Whether initialization is successfully or not.
---@param texType ccui.Widget.TextureResType
---@overload fun(self: ccui.EditBox, size: cc.Size, normalImage: string): boolean
---@overload fun(self: ccui.EditBox, size: cc.Size, normalImage: string, pressedImage: string): boolean
---@overload fun(self: ccui.EditBox, size: cc.Size, normalImage: string, pressedImage: string, disabledImage: string): boolean
function EditBox:initWithSizeAndTexture(size, normalImage, pressedImage, disabledImage, texType) end

---Load disabled state texture for edit box.
---
---@param disabled string # dark state texture.
---@param texType ccui.Widget.TextureResType # @see `TextureResType`
---@overload fun(self: ccui.EditBox, disabled: string)
function EditBox:loadTextureDisabled(disabled, texType) end

---Load normal state texture for edit box.
---
---@param normal string # normal state texture.
---@param texType ccui.Widget.TextureResType # @see `TextureResType`
---@overload fun(self: ccui.EditBox, normal: string)
function EditBox:loadTextureNormal(normal, texType) end

---Load pressed state texture for edit box.
---
---@param pressed string # pressed state texture.
---@param texType ccui.Widget.TextureResType # @see `TextureResType`
---@overload fun(self: ccui.EditBox, pressed: string)
function EditBox:loadTexturePressed(pressed, texType) end

---Load textures for edit box.
---
---@param normal string # normal state texture name.
---@param pressed string # pressed state texture name.
---@param disabled string # disabled state texture name.
---@param texType ccui.Widget.TextureResType # @see `TextureResType`
---@overload fun(self: ccui.EditBox, normal: string, pressed: string)
---@overload fun(self: ccui.EditBox, normal: string, pressed: string, disabled: string)
function EditBox:loadTextures(normal, pressed, disabled, texType) end

---Constructor.
---\js ctor
---\lua new
---@return ccui.EditBox
function EditBox.new() end

function EditBox:openKeyboard() end

---Sets capInsets for edit box.
---
---@param capInsets cc.Rect # capInset in Rect.
function EditBox:setCapInsets(capInsets) end

---Sets capInsets for edit box, only the disabled state scale9 renderer will be affected.
---
---@param capInsets cc.Rect # capInsets in Rect.
function EditBox:setCapInsetsDisabledRenderer(capInsets) end

---Sets capInsets for edit box, only the normal state scale9 renderer will be affected.
---
---@param capInsets cc.Rect # capInsets in Rect.
function EditBox:setCapInsetsNormalRenderer(capInsets) end

---Sets capInsets for edit box, only the pressed state scale9 renderer will be affected.
---
---@param capInsets cc.Rect # capInsets in Rect
function EditBox:setCapInsetsPressedRenderer(capInsets) end

---Gets/Sets the delegate for edit box.
---\lua NA
---@param delegate ccui.EditBoxDelegate
function EditBox:setDelegate(delegate) end

---Set the font. Only system font is allowed.
---@param pFontName string # The font name.
---@param fontSize integer # The font size.
function EditBox:setFont(pFontName, fontSize) end

---Set the font color of the widget's text.
---@param color any
---@overload fun(self: ccui.EditBox, color: any)
function EditBox:setFontColor(color) end

---Set the font name. Only system font is allowed.
---@param pFontName string # The font name.
function EditBox:setFontName(pFontName) end

---Set the font size.
---@param fontSize integer # The font size.
function EditBox:setFontSize(fontSize) end

---Set the input flags that are to be applied to the edit box.
---@param inputFlag ccui.EditBox.InputFlag # One of the EditBox::InputFlag constants.
function EditBox:setInputFlag(inputFlag) end

---Set the input mode of the edit box.
---@param inputMode ccui.EditBox.InputMode # One of the EditBox::InputMode constants.
function EditBox:setInputMode(inputMode) end

---Sets the maximum input length of the edit box.
---Setting this value enables multiline input mode by default.
---Available on Android, iOS and Windows Phone.
---
---@param maxLength integer # The maximum length.
function EditBox:setMaxLength(maxLength) end

---Set a text in the edit box that acts as a placeholder when an
---edit box is empty.
---@param pText string # The given text.
function EditBox:setPlaceHolder(pText) end

---Set the placeholder's font. Only system font is allowed.
---@param pFontName string # The font name.
---@param fontSize integer # The font size.
function EditBox:setPlaceholderFont(pFontName, fontSize) end

---Set the font color of the placeholder text when the edit box is empty.
---@param color any
---@overload fun(self: ccui.EditBox, color: any)
function EditBox:setPlaceholderFontColor(color) end

---Set the placeholder's font name. only system font is allowed.
---@param pFontName string # The font name.
function EditBox:setPlaceholderFontName(pFontName) end

---Set the placeholder's font size.
---@param fontSize integer # The font size.
function EditBox:setPlaceholderFontSize(fontSize) end

---Set the return type that are to be applied to the edit box.
---@param returnType ccui.EditBox.KeyboardReturnType # One of the EditBox::KeyboardReturnType constants.
function EditBox:setReturnType(returnType) end

---Set the text entered in the edit box.
---@param pText string # The given text.
function EditBox:setText(pText) end

---Set the text horizontal alignment.
---@param alignment cc.TextHAlignment
function EditBox:setTextHorizontalAlignment(alignment) end

return EditBox