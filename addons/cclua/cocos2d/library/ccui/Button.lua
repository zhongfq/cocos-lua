---AUTO GENERATED, DO NOT MODIFY!
---@meta ccui.Button

---Represents a push-button widget.
---Push-buttons can be pressed, or clicked, by the user to perform an action.
---@class ccui.Button : ccui.Widget
---@field capInsetsDisabledRenderer cc.Rect Return the capInsets of disabled state scale9sprite. \return The disabled scale9 renderer capInsets.
---@field capInsetsNormalRenderer cc.Rect Return the capInsets of normal state scale9sprite. \return The normal scale9 renderer capInsets.
---@field capInsetsPressedRenderer cc.Rect Return the capInsets of pressed state scale9sprite. \return The pressed scale9 renderer capInsets.
---@field disabledFile cc.ResourceData 
---@field normalFile cc.ResourceData 
---@field normalTextureSize cc.Size 
---@field pressedFile cc.ResourceData 
---@field rendererClicked ccui.Scale9Sprite Return the nine-patch sprite of clicked state \return the nine-patch sprite of clicked state \since v3.9
---@field rendererDisabled ccui.Scale9Sprite Return the nine-patch sprite of disabled state \return the nine-patch sprite of disabled state \since v3.9
---@field rendererNormal ccui.Scale9Sprite Return the nine-patch sprite of normal state \return the nine-patch sprite of normal state \since v3.9
---@field scale9Enabled boolean Query whether button is using scale9 renderer or not. \return whether button use scale9 renderer or not.
---@field titleColor any Query the button title color. \return Color3B of button title.
---@field titleFontName string Query the font name of button's title \return font name in std::string
---@field titleFontSize number Query the font size of button title \return font size in float.
---@field titleLabel cc.Label returns the current Label being used
---@field titleRenderer cc.Label Return the inner title renderer of Button. \return The button title. \since v3.3
---@field titleText string Query the button title content. \return Get the button's title content.
---@field zoomScale number Return a zoom scale \return the zoom scale in float \since v3.3
local Button = {}

---Create a empty Button.
---@return ccui.Button # A empty Button instance.
---
---Create a button with custom textures.
---\param normalImage normal state texture name.
---\param selectedImage  selected state texture name.
---\param disableImage disabled state texture name.
---\param texType    @see `TextureResType`
---\return a Button instance.
---@overload fun(normalImage: string, selectedImage: string, disableImage: string, texType: ccui.Widget.TextureResType): ccui.Button
---
---Create a button with custom textures.
---\param normalImage normal state texture name.
---\param selectedImage  selected state texture name.
---\param disableImage disabled state texture name.
---\param texType    @see `TextureResType`
---\return a Button instance.
---@overload fun(normalImage: string): ccui.Button
---
---Create a button with custom textures.
---\param normalImage normal state texture name.
---\param selectedImage  selected state texture name.
---\param disableImage disabled state texture name.
---\param texType    @see `TextureResType`
---\return a Button instance.
---@overload fun(normalImage: string, selectedImage: string): ccui.Button
---
---Create a button with custom textures.
---\param normalImage normal state texture name.
---\param selectedImage  selected state texture name.
---\param disableImage disabled state texture name.
---\param texType    @see `TextureResType`
---\return a Button instance.
---@overload fun(normalImage: string, selectedImage: string, disableImage: string): ccui.Button
function Button.create() end

---@return cc.Ref
function Button.createInstance() end

---Return the capInsets of disabled state scale9sprite.
---@return cc.Rect # The disabled scale9 renderer capInsets.
function Button:getCapInsetsDisabledRenderer() end

---Return the capInsets of normal state scale9sprite.
---@return cc.Rect # The normal scale9 renderer capInsets.
function Button:getCapInsetsNormalRenderer() end

---Return the capInsets of pressed state scale9sprite.
---@return cc.Rect # The pressed scale9 renderer capInsets.
function Button:getCapInsetsPressedRenderer() end

---@return cc.ResourceData
function Button:getDisabledFile() end

---@return cc.ResourceData
function Button:getNormalFile() end

---@return cc.Size
function Button:getNormalTextureSize() end

---@return cc.ResourceData
function Button:getPressedFile() end

---Return the nine-patch sprite of clicked state
---@return ccui.Scale9Sprite # the nine-patch sprite of clicked state
---\since v3.9
function Button:getRendererClicked() end

---Return the nine-patch sprite of disabled state
---@return ccui.Scale9Sprite # the nine-patch sprite of disabled state
---\since v3.9
function Button:getRendererDisabled() end

---Return the nine-patch sprite of normal state
---@return ccui.Scale9Sprite # the nine-patch sprite of normal state
---\since v3.9
function Button:getRendererNormal() end

---Query the button title color.
---@return any # Color3B of button title.
function Button:getTitleColor() end

---Query the font name of button's title
---@return string # font name in std::string
function Button:getTitleFontName() end

---Query the font size of button title
---@return number # font size in float.
function Button:getTitleFontSize() end

---returns the current Label being used
---@return cc.Label
function Button:getTitleLabel() end

---Return the inner title renderer of Button.
---@return cc.Label # The button title.
---\since v3.3
function Button:getTitleRenderer() end

---Query the button title content.
---@return string # Get the button's title content.
function Button:getTitleText() end

---Return a zoom scale
---@return number # the zoom scale in float
---\since v3.3
function Button:getZoomScale() end

---@return boolean
---@overload fun(self: ccui.Button, normalImage: string, selectedImage: string, disableImage: string, texType: ccui.Widget.TextureResType): boolean
---@overload fun(self: ccui.Button, normalImage: string): boolean
---@overload fun(self: ccui.Button, normalImage: string, selectedImage: string): boolean
---@overload fun(self: ccui.Button, normalImage: string, selectedImage: string, disableImage: string): boolean
function Button:init() end

---Query whether button is using scale9 renderer or not.
---@return boolean # whether button use scale9 renderer or not.
function Button:isScale9Enabled() end

---Load disabled state texture for button.
---
---@param disabled string # dark state texture.
---@param texType ccui.Widget.TextureResType # @see `TextureResType`
---@overload fun(self: ccui.Button, disabled: string)
function Button:loadTextureDisabled(disabled, texType) end

---Load normal state texture for button.
---
---@param normal string # normal state texture.
---@param texType ccui.Widget.TextureResType # @see `TextureResType`
---@overload fun(self: ccui.Button, normal: string)
function Button:loadTextureNormal(normal, texType) end

---Load selected state texture for button.
---
---@param selected string # selected state texture.
---@param texType ccui.Widget.TextureResType # @see `TextureResType`
---@overload fun(self: ccui.Button, selected: string)
function Button:loadTexturePressed(selected, texType) end

---Load textures for button.
---
---@param normal string # normal state texture name.
---@param selected string # selected state texture name.
---@param disabled string # disabled state texture name.
---@param texType ccui.Widget.TextureResType # @see `TextureResType`
---@overload fun(self: ccui.Button, normal: string, selected: string)
---@overload fun(self: ccui.Button, normal: string, selected: string, disabled: string)
function Button:loadTextures(normal, selected, disabled, texType) end

---Default constructor.
---@return ccui.Button
function Button.new() end

function Button:resetDisabledRender() end

function Button:resetNormalRender() end

function Button:resetPressedRender() end

---Sets capInsets for button.
---The capInset affects  all button scale9 renderer only if `setScale9Enabled(true)` is called
---
---@param capInsets cc.Rect # capInset in Rect.
function Button:setCapInsets(capInsets) end

---Sets capInsets for button, only the disabled state scale9 renderer will be affected.
---
---@param capInsets cc.Rect # capInsets in Rect.
function Button:setCapInsetsDisabledRenderer(capInsets) end

---Sets capInsets for button, only the normal state scale9 renderer will be affected.
---
---@param capInsets cc.Rect # capInsets in Rect.
function Button:setCapInsetsNormalRenderer(capInsets) end

---Sets capInsets for button, only the pressed state scale9 renderer will be affected.
---
---@param capInsets cc.Rect # capInsets in Rect
function Button:setCapInsetsPressedRenderer(capInsets) end

---Enable zooming action when button is pressed.
---
---@param enabled boolean # Set to true will enable zoom effect, false otherwise.
function Button:setPressedActionEnabled(enabled) end

---Enable scale9 renderer.
---
---@param enable boolean # Set to true will use scale9 renderer, false otherwise.
function Button:setScale9Enabled(enable) end

---Sets the title's text horizontal alignment.
---
---@param hAlignment cc.TextHAlignment # see TextHAlignment
---
---Sets the title's text vertical alignment.
---
---\param hAlignment see TextHAlignment.
---\param vAlignment see TextVAlignment.
---@overload fun(self: ccui.Button, hAlignment: cc.TextHAlignment, vAlignment: cc.TextVAlignment)
function Button:setTitleAlignment(hAlignment) end

---Change the color of button's title.
---@param color any # The title color in Color3B.
function Button:setTitleColor(color) end

---Change the font name of button's title
---@param fontName string # a font name string.
function Button:setTitleFontName(fontName) end

---Change the font size of button's title
---@param size number # Title font size in float.
function Button:setTitleFontSize(size) end

---replaces the current Label node with a new one
---@param label cc.Label
function Button:setTitleLabel(label) end

---Change the content of button's title.
---@param text string # The title in std::string.
function Button:setTitleText(text) end

---When user pressed the button, the button will zoom to a scale.
---The final scale of the button  equals (button original scale + _zoomScale)
---\since v3.3
---@param scale number
function Button:setZoomScale(scale) end

return Button