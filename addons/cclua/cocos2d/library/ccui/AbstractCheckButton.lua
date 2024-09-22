---AUTO GENERATED, DO NOT MODIFY!
---@meta ccui.AbstractCheckButton

---AbstractCheckButton is a specific type of two-states button that can be either checked or unchecked.
---@class ccui.AbstractCheckButton : ccui.Widget
---@field backDisabledFile cc.ResourceData 
---@field backNormalFile cc.ResourceData 
---@field backPressedFile cc.ResourceData 
---@field crossDisabledFile cc.ResourceData 
---@field crossNormalFile cc.ResourceData 
---@field rendererBackground cc.Sprite Return the sprite instance of background \return the sprite instance of background.
---@field rendererBackgroundDisabled cc.Sprite Return the sprite instance of background when disabled \return the sprite instance of background when disabled
---@field rendererBackgroundSelected cc.Sprite Return the sprite instance of background when selected \return the sprite instance of background when selected
---@field rendererFrontCross cc.Sprite Return the sprite instance of front cross \return the sprite instance of front cross
---@field rendererFrontCrossDisabled cc.Sprite Return the sprite instance of front cross when disabled \return the sprite instance of front cross when disabled
---@field selected boolean Query whether CheckBox is selected or not. \return true means "selected", false otherwise.
---@field zoomScale number Return a zoom scale \return A zoom scale of Checkbox. \since v3.3
local AbstractCheckButton = {}

---@return cc.ResourceData
function AbstractCheckButton:getBackDisabledFile() end

---@return cc.ResourceData
function AbstractCheckButton:getBackNormalFile() end

---@return cc.ResourceData
function AbstractCheckButton:getBackPressedFile() end

---@return cc.ResourceData
function AbstractCheckButton:getCrossDisabledFile() end

---@return cc.ResourceData
function AbstractCheckButton:getCrossNormalFile() end

---Return the sprite instance of background
---@return cc.Sprite # the sprite instance of background.
function AbstractCheckButton:getRendererBackground() end

---Return the sprite instance of background when disabled
---@return cc.Sprite # the sprite instance of background when disabled
function AbstractCheckButton:getRendererBackgroundDisabled() end

---Return the sprite instance of background when selected
---@return cc.Sprite # the sprite instance of background when selected
function AbstractCheckButton:getRendererBackgroundSelected() end

---Return the sprite instance of front cross
---@return cc.Sprite # the sprite instance of front cross
function AbstractCheckButton:getRendererFrontCross() end

---Return the sprite instance of front cross when disabled
---@return cc.Sprite # the sprite instance of front cross when disabled
function AbstractCheckButton:getRendererFrontCrossDisabled() end

---Return a zoom scale
---@return number # A zoom scale of Checkbox.
---\since v3.3
function AbstractCheckButton:getZoomScale() end

---@return boolean
---@overload fun(self: ccui.AbstractCheckButton, backGround: string, backGroundSelected: string, cross: string, backGroundDisabled: string, frontCrossDisabled: string, texType: ccui.Widget.TextureResType): boolean
---@overload fun(self: ccui.AbstractCheckButton, backGround: string, backGroundSelected: string, cross: string, backGroundDisabled: string, frontCrossDisabled: string): boolean
function AbstractCheckButton:init() end

---Query whether CheckBox is selected or not.
---@return boolean # true means "selected", false otherwise.
function AbstractCheckButton:isSelected() end

---Load background texture for check button.
---
---@param backGround string # The background image name.
---@param type ccui.Widget.TextureResType # @see `Widget::TextureResType`
---@overload fun(self: ccui.AbstractCheckButton, backGround: string)
function AbstractCheckButton:loadTextureBackGround(backGround, type) end

---Load background disabled state texture for checkbox.
---
---@param backGroundDisabled string # The background disabled state texture name.
---
---@param texType ccui.Widget.TextureResType # @see `Widget::TextureResType`
---@overload fun(self: ccui.AbstractCheckButton, backGroundDisabled: string)
function AbstractCheckButton:loadTextureBackGroundDisabled(backGroundDisabled, texType) end

---Load background selected state texture for check button.
---
---@param backGroundSelected string # The background selected state image name.
---@param texType ccui.Widget.TextureResType # @see `Widget::TextureResType`
---@overload fun(self: ccui.AbstractCheckButton, backGroundSelected: string)
function AbstractCheckButton:loadTextureBackGroundSelected(backGroundSelected, texType) end

---Load cross texture for check button.
---
---@param crossTextureName string # The cross texture name.
---@param texType ccui.Widget.TextureResType # @see `Widget::TextureResType`
---@overload fun(self: ccui.AbstractCheckButton, crossTextureName: string)
function AbstractCheckButton:loadTextureFrontCross(crossTextureName, texType) end

---Load frontcross disabled texture for checkbox.
---
---@param frontCrossDisabled string # The front cross disabled state texture name.
---@param texType ccui.Widget.TextureResType # @see `Widget::TextureResType`
---@overload fun(self: ccui.AbstractCheckButton, frontCrossDisabled: string)
function AbstractCheckButton:loadTextureFrontCrossDisabled(frontCrossDisabled, texType) end

---Load all textures for initializing a check button.
---
---@param background string # The background image name.
---@param backgroundSelected string # The background selected image name.
---@param cross string # The cross image name.
---@param backgroundDisabled string # The background disabled state texture.
---@param frontCrossDisabled string # The front cross disabled state image name.
---@param texType ccui.Widget.TextureResType # @see `Widget::TextureResType`
---@overload fun(self: ccui.AbstractCheckButton, background: string, backgroundSelected: string, cross: string, backgroundDisabled: string, frontCrossDisabled: string)
function AbstractCheckButton:loadTextures(background, backgroundSelected, cross, backgroundDisabled, frontCrossDisabled, texType) end

---Change CheckBox state.
---Set to true will cause the CheckBox's state to "selected", false otherwise.
---@param selected boolean # Set to true will change CheckBox to selected state, false otherwise.
function AbstractCheckButton:setSelected(selected) end

---When user pressed the CheckBox, the button will zoom to a scale.
---The final scale of the CheckBox  equals (CheckBox original scale + _zoomScale)
---\since v3.3
---@param scale number
function AbstractCheckButton:setZoomScale(scale) end

return AbstractCheckButton