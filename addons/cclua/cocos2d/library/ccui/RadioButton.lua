---AUTO GENERATED, DO NOT MODIFY!
---@meta ccui.RadioButton

---RadioButton is a specific type of two-states button that is similar to CheckBox.
---Additionally, it can be used together with RadioButtonGroup to interact with other radio buttons.
---@class ccui.RadioButton : ccui.AbstractCheckButton
local RadioButton = {}

---Add a callback function which would be called when radio button is selected or unselected.
---@param callback ccui.RadioButton.ccRadioButtonCallback # A std::function with type @see `ccRadioButtonCallback`
function RadioButton:addEventListener(callback) end

---Create and return a empty RadioButton instance pointer.
---@return ccui.RadioButton
---
---Create a radio button with various images.
---
---\param backGround    backGround texture.
---\param backGroundSelected    backGround selected state texture.
---\param cross    cross texture.
---\param backGroundDisabled    backGround disabled state texture.
---\param frontCrossDisabled    cross dark state texture.
---\param texType    @see `Widget::TextureResType`
---
---\return A RadioButton instance pointer.
---@overload fun(backGround: string, backGroundSelected: string, cross: string, backGroundDisabled: string, frontCrossDisabled: string, texType: ccui.Widget.TextureResType): ccui.RadioButton
---
---Create a radio button with various images.
---
---\param backGround    backGround texture.
---\param backGroundSelected    backGround selected state texture.
---\param cross    cross texture.
---\param backGroundDisabled    backGround disabled state texture.
---\param frontCrossDisabled    cross dark state texture.
---\param texType    @see `Widget::TextureResType`
---
---\return A RadioButton instance pointer.
---@overload fun(backGround: string, backGroundSelected: string, cross: string, backGroundDisabled: string, frontCrossDisabled: string): ccui.RadioButton
---
---Another factory method to create a RadioButton instance.
---This method uses less resource to create a RadioButton.
---\param backGround The background image name in `std::string`.
---\param cross The cross image name in `std::string`.
---\param texType  The texture's resource type in `Widget::TextureResType`.
---\return A RadioButton instance pointer
---@overload fun(backGround: string, cross: string, texType: ccui.Widget.TextureResType): ccui.RadioButton
---
---Another factory method to create a RadioButton instance.
---This method uses less resource to create a RadioButton.
---\param backGround The background image name in `std::string`.
---\param cross The cross image name in `std::string`.
---\param texType  The texture's resource type in `Widget::TextureResType`.
---\return A RadioButton instance pointer
---@overload fun(backGround: string, cross: string): ccui.RadioButton
function RadioButton.create() end

---@return cc.Ref
function RadioButton.createInstance() end

---Default constructor.
---
---\lua new
---@return ccui.RadioButton
function RadioButton.new() end

return RadioButton