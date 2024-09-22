---AUTO GENERATED, DO NOT MODIFY!
---@meta ccui.CheckBox

---Checkbox is a specific type of two-states button that can be either checked or unchecked.
---@class ccui.CheckBox : ccui.AbstractCheckButton
local CheckBox = {}

---Add a callback function which would be called when checkbox is selected or unselected.
---@param callback ccui.CheckBox.ccCheckBoxCallback # A std::function with type @see `ccCheckBoxCallback`
function CheckBox:addEventListener(callback) end

---Create and return a empty CheckBox instance pointer.
---@return ccui.CheckBox
---
---Create an checkbox with various images.
---
---\param backGround    backGround texture.
---\param backGroundSelected    backGround selected state texture.
---\param cross    cross texture.
---\param backGroundDisabled    backGround disabled state texture.
---\param frontCrossDisabled    cross dark state texture.
---\param texType    @see `Widget::TextureResType`
---
---\return A CheckBox instance pointer.
---@overload fun(backGround: string, backGroundSelected: string, cross: string, backGroundDisabled: string, frontCrossDisabled: string, texType: ccui.Widget.TextureResType): ccui.CheckBox
---
---Create an checkbox with various images.
---
---\param backGround    backGround texture.
---\param backGroundSelected    backGround selected state texture.
---\param cross    cross texture.
---\param backGroundDisabled    backGround disabled state texture.
---\param frontCrossDisabled    cross dark state texture.
---\param texType    @see `Widget::TextureResType`
---
---\return A CheckBox instance pointer.
---@overload fun(backGround: string, backGroundSelected: string, cross: string, backGroundDisabled: string, frontCrossDisabled: string): ccui.CheckBox
---
---Another factory method to create a CheckBox instance.
---This method uses less resource to create a CheckBox.
---\param backGround The background image name in `std::string`.
---\param cross The cross image name in `std::string`.
---\param texType  The texture's resource type in `Widget::TextureResType`.
---\return A CheckBox instance pointer
---@overload fun(backGround: string, cross: string, texType: ccui.Widget.TextureResType): ccui.CheckBox
---
---Another factory method to create a CheckBox instance.
---This method uses less resource to create a CheckBox.
---\param backGround The background image name in `std::string`.
---\param cross The cross image name in `std::string`.
---\param texType  The texture's resource type in `Widget::TextureResType`.
---\return A CheckBox instance pointer
---@overload fun(backGround: string, cross: string): ccui.CheckBox
function CheckBox.create() end

---@return cc.Ref
function CheckBox.createInstance() end

---Default constructor.
---
---\lua new
---@return ccui.CheckBox
function CheckBox.new() end

return CheckBox