---AUTO GENERATED, DO NOT MODIFY!
---@meta ccui.Layout

---A container for holding a few child widgets. 
---
---The child widgets could be rearranged according to the layout type and it also enables clipping, set background image and color.
---
---There are mainly four types of layout:
---- Absolute layout: This the default layout type, child elements are arranged by their absolute position.
---- Horizontal layout: child elements are arranged horizontally.
---- Vertical layout: child elements are arranged vertically.
---- Relative layout: child elements are arranged relative to certain rules.
---@class ccui.Layout : ccui.Widget
---@field backGroundColor any Query the layout's background color. \return Background color in Color3B.
---@field backGroundColorOpacity integer Get the layout's background color opacity. \return Background color opacity value.
---@field backGroundColorType ccui.Layout.BackGroundColorType Query the layout's background color type. \return The layout's background color type.
---@field backGroundColorVector cc.Vec2 Get the layout's background color vector. \return Background color vector.
---@field backGroundEndColor any Get the gradient background end color. \return Gradient background end color value.
---@field backGroundImageCapInsets cc.Rect Query background image's capInsets size. \return The background image capInsets.
---@field backGroundImageColor any Get color of layout's background image. \return Layout's background image color.
---@field backGroundImageOpacity integer Get the opacity of layout's background image. \return The opacity of layout's background image.
---@field backGroundImageScale9Enabled boolean Query background image scale9 enable status. \return Whether background image is scale9 enabled or not.
---@field backGroundImageTextureSize cc.Size Gets background image texture size. <br><br>\return background image texture size.
---@field backGroundStartColor any Get the gradient background start color. \return  Gradient background start color value.
---@field clippingEnabled boolean Gets if layout is clipping enabled. <br><br>\return if layout is clipping enabled.
---@field clippingType ccui.Layout.ClippingType \see `setClippingType(ClippingType)`
---@field layoutType ccui.Layout.Type Query layout type. \return Get the layout type.
---@field loopFocus boolean \return If focus loop is enabled, then it will return true, otherwise it returns false. The default value is false.
---@field passFocusToChild boolean \return To query whether the layout will pass the focus to its children or not. The default value is true
---@field renderFile cc.ResourceData 
---@field onPassFocusToChild fun(arg1: ccui.Widget.FocusDirection, arg2: ccui.Widget): integer
local Layout = {}

---@param cls string
---@return any
function Layout:as(cls) end

---Create a empty layout.
---@return ccui.Layout
function Layout.create() end

---@return cc.Ref
function Layout.createInstance() end

---force refresh widget layout
function Layout:forceDoLayout() end

---Query the layout's background color.
---@return any # Background color in Color3B.
function Layout:getBackGroundColor() end

---Get the layout's background color opacity.
---@return integer # Background color opacity value.
function Layout:getBackGroundColorOpacity() end

---Query the layout's background color type.
---@return ccui.Layout.BackGroundColorType # The layout's background color type.
function Layout:getBackGroundColorType() end

---Get the layout's background color vector.
---@return cc.Vec2 # Background color vector.
function Layout:getBackGroundColorVector() end

---Get the gradient background end color.
---@return any # Gradient background end color value.
function Layout:getBackGroundEndColor() end

---Query background image's capInsets size.
---@return cc.Rect # The background image capInsets.
function Layout:getBackGroundImageCapInsets() end

---Get color of layout's background image.
---@return any # Layout's background image color.
function Layout:getBackGroundImageColor() end

---Get the opacity of layout's background image.
---@return integer # The opacity of layout's background image.
function Layout:getBackGroundImageOpacity() end

---Gets background image texture size.
---
---@return cc.Size # background image texture size.
function Layout:getBackGroundImageTextureSize() end

---Get the gradient background start color.
---@return any # Gradient background start color value.
function Layout:getBackGroundStartColor() end

---\see `setClippingType(ClippingType)`
---@return ccui.Layout.ClippingType
function Layout:getClippingType() end

---Query layout type.
---@return ccui.Layout.Type # Get the layout type.
function Layout:getLayoutType() end

---@return cc.ResourceData
function Layout:getRenderFile() end

---Query background image scale9 enable status.
---@return boolean # Whether background image is scale9 enabled or not.
function Layout:isBackGroundImageScale9Enabled() end

---Gets if layout is clipping enabled.
---
---@return boolean # if layout is clipping enabled.
function Layout:isClippingEnabled() end

---@return boolean # If focus loop is enabled, then it will return true, otherwise it returns false. The default value is false.
function Layout:isLoopFocus() end

---@return boolean # To query whether the layout will pass the focus to its children or not. The default value is true
function Layout:isPassFocusToChild() end

---Default constructor
---\js ctor
---\lua new
---@return ccui.Layout
function Layout.new() end

---Remove the background image of layout.
function Layout:removeBackGroundImage() end

---request to refresh widget layout
function Layout:requestDoLayout() end

---Set background color for layout
---The color only applies to layout when it's color type is BackGroundColorType::SOLIDE
---
---@param color any # Color in Color3B.
---
---Set start and end background color for layout.
---This setting only take effect when the layout's  color type is BackGroundColorType::GRADIENT
---
---\param startColor Color value in Color3B.
---\param endColor Color value in Color3B.
---@overload fun(self: ccui.Layout, startColor: any, endColor: any)
function Layout:setBackGroundColor(color) end

---Sets background color opacity of layout.
---
---@param opacity integer # The opacity in `GLubyte`.
function Layout:setBackGroundColorOpacity(opacity) end

---Sets Color Type for layout's background
---
---@param type ccui.Layout.BackGroundColorType # @see `BackGroundColorType`
function Layout:setBackGroundColorType(type) end

---Sets background color vector for layout.
---This setting only take effect when layout's color type is BackGroundColorType::GRADIENT
---
---@param vector cc.Vec2 # The color vector in `Vec2`.
function Layout:setBackGroundColorVector(vector) end

---Sets a background image for layout.
---
---@param fileName string # image file path.
---@param texType ccui.Widget.TextureResType # @see TextureResType.
---@overload fun(self: ccui.Layout, fileName: string)
function Layout:setBackGroundImage(fileName, texType) end

---Sets a background image capinsets for layout, it only affects the scale9 enabled background image
---
---@param capInsets cc.Rect # The capInsets in Rect.
function Layout:setBackGroundImageCapInsets(capInsets) end

---Set layout's background image color.
---@param color any # Background color value in `Color3B`.
function Layout:setBackGroundImageColor(color) end

---Set opacity of background image.
---@param opacity integer # Background image opacity in GLubyte.
function Layout:setBackGroundImageOpacity(opacity) end

---Enable background image scale9 rendering.
---
---@param enabled boolean # True means enable scale9 rendering for background image, false otherwise.
function Layout:setBackGroundImageScale9Enabled(enabled) end

---Toggle layout clipping.
---
---If you do need clipping, you pass true to this function.
---
---@param enabled boolean # Pass true to enable clipping, false otherwise.
function Layout:setClippingEnabled(enabled) end

---Change the clipping type of layout.
---On default, the clipping type is `ClippingType::STENCIL`.
---\see `ClippingType`
---@param type ccui.Layout.ClippingType # The clipping type of layout.
function Layout:setClippingType(type) end

---Change the layout type.
---@param type ccui.Layout.Type # Layout type.
function Layout:setLayoutType(type) end

---If a layout is loop focused which means that the focus movement will be inside the layout
---@param loop boolean # pass true to let the focus movement loop inside the layout
function Layout:setLoopFocus(loop) end

---@param pass boolean # To specify whether the layout pass its focus to its child
function Layout:setPassFocusToChild(pass) end

return Layout