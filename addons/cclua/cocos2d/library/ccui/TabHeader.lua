---AUTO GENERATED, DO NOT MODIFY!
---@meta ccui.TabHeader

---the header button in TabControl
---@class ccui.TabHeader : ccui.AbstractCheckButton
---@field indexInTabControl integer get the index this header in the TabControl \return -1 means not in any TabControl
---@field titleColor any get the TabHeader text color. \return Color4B of TabHeader text.
---@field titleFontName string get the font name of TabHeader text \return font name in std::string
---@field titleFontSize number get the font size of TabHeader text \return TabHeader text's font size in float.
---@field titleRenderer cc.Label Return the inner Label renderer of TabHeader. \return The TabHeader Label.
---@field titleText string get the TabHeader text \return he TabHeader text
local TabHeader = {}

---Create and return a empty TabHeader instance pointer.
---@return ccui.TabHeader
---
---factory method to create a TabHeader instance.
---This method uses less resource to create a TabHeader.
---\param titleStr The text on the TabHeader
---\param backGround The background image name in `std::string`.
---\param cross The cross image name in `std::string`.
---\param texType  The texture's resource type in `Widget::TextureResType`.
---\return A TabHeader instance pointer
---@overload fun(titleStr: string, backGround: string, cross: string, texType: ccui.Widget.TextureResType): ccui.TabHeader
---
---factory method to create a TabHeader instance.
---This method uses less resource to create a TabHeader.
---\param titleStr The text on the TabHeader
---\param backGround The background image name in `std::string`.
---\param cross The cross image name in `std::string`.
---\param texType  The texture's resource type in `Widget::TextureResType`.
---\return A TabHeader instance pointer
---@overload fun(titleStr: string, backGround: string, cross: string): ccui.TabHeader
---
---Create a TabHeader with various images.
---\param titleStr The text on the TabHeader
---\param backGround    backGround texture.
---\param backGroundSelected    backGround selected state texture.
---\param cross    cross texture.
---\param backGroundDisabled    backGround disabled state texture.
---\param frontCrossDisabled    cross dark state texture.
---\param texType    @see `Widget::TextureResType`
---
---\return A TabHeader instance pointer.
---@overload fun(titleStr: string, backGround: string, backGroundSelected: string, cross: string, backGroundDisabled: string, frontCrossDisabled: string, texType: ccui.Widget.TextureResType): ccui.TabHeader
---
---Create a TabHeader with various images.
---\param titleStr The text on the TabHeader
---\param backGround    backGround texture.
---\param backGroundSelected    backGround selected state texture.
---\param cross    cross texture.
---\param backGroundDisabled    backGround disabled state texture.
---\param frontCrossDisabled    cross dark state texture.
---\param texType    @see `Widget::TextureResType`
---
---\return A TabHeader instance pointer.
---@overload fun(titleStr: string, backGround: string, backGroundSelected: string, cross: string, backGroundDisabled: string, frontCrossDisabled: string): ccui.TabHeader
function TabHeader.create() end

---get the index this header in the TabControl
---@return integer # -1 means not in any TabControl
function TabHeader:getIndexInTabControl() end

---get the TabHeader text color.
---@return any # Color4B of TabHeader text.
function TabHeader:getTitleColor() end

---get the font name of TabHeader text
---@return string # font name in std::string
function TabHeader:getTitleFontName() end

---get the font size of TabHeader text
---@return number # TabHeader text's font size in float.
function TabHeader:getTitleFontSize() end

---Return the inner Label renderer of TabHeader.
---@return cc.Label # The TabHeader Label.
function TabHeader:getTitleRenderer() end

---get the TabHeader text
---@return string # he TabHeader text
function TabHeader:getTitleText() end

---Change the color of he TabHeader text
---@param color any # The he TabHeader text's color in Color4B.
function TabHeader:setTitleColor(color) end

---Change the font name of TabHeader text
---@param fontName string # a font name string.
function TabHeader:setTitleFontName(fontName) end

---Change the font size of TabHeader text
---@param size number # TabHeader text's font size in float.
function TabHeader:setTitleFontSize(size) end

---Change the content of Header's text.
---@param text string # The Header's text.
function TabHeader:setTitleText(text) end

return TabHeader