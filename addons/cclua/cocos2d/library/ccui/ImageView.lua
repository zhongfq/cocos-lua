---AUTO GENERATED, DO NOT MODIFY!
---@meta ccui.ImageView

---A widget to display images.
---@class ccui.ImageView : ccui.Widget
---@field blendFunc cc.BlendFunc Returns the blending function that is currently being used. <br><br>\return A BlendFunc structure with source and destination factor which specified pixel arithmetic. \js NA \lua NA
---@field capInsets cc.Rect Get ImageView's capInsets size. \return Query capInsets size in Rect \see `setCapInsets(const Rect&)`
---@field renderFile cc.ResourceData 
---@field scale9Enabled boolean Query whether button is using scale9 renderer or not. \return whether button use scale9 renderer or not.
local ImageView = {}

---@param cls string
---@return any
function ImageView:as(cls) end

---Create a empty ImageView.
---@return ccui.ImageView
---
---Create a  imageview  with a image name.
---
---\param imageFileName   file name of texture.
---\param texType    @see `Widget::TextureResType`
---\return A ImageView instance.
---@overload fun(imageFileName: string, texType: ccui.Widget.TextureResType): ccui.ImageView
---
---Create a  imageview  with a image name.
---
---\param imageFileName   file name of texture.
---\param texType    @see `Widget::TextureResType`
---\return A ImageView instance.
---@overload fun(imageFileName: string): ccui.ImageView
function ImageView.create() end

---@return cc.Ref
function ImageView.createInstance() end

---Returns the blending function that is currently being used.
---
---@return cc.BlendFunc # A BlendFunc structure with source and destination factor which specified pixel arithmetic.
---\js NA
---\lua NA
function ImageView:getBlendFunc() end

---Get ImageView's capInsets size.
---@return cc.Rect # Query capInsets size in Rect
---\see `setCapInsets(const Rect&)`
function ImageView:getCapInsets() end

---@return cc.ResourceData
function ImageView:getRenderFile() end

---@return boolean
---@overload fun(self: ccui.ImageView, imageFileName: string, texType: ccui.Widget.TextureResType): boolean
---@overload fun(self: ccui.ImageView, imageFileName: string): boolean
function ImageView:init() end

---Query whether button is using scale9 renderer or not.
---@return boolean # whether button use scale9 renderer or not.
function ImageView:isScale9Enabled() end

---Load texture for imageview.
---
---@param fileName string # file name of texture.
---@param texType ccui.Widget.TextureResType # @see `Widget::TextureResType`
---@overload fun(self: ccui.ImageView, fileName: string)
function ImageView:loadTexture(fileName, texType) end

---Default constructor
---\js ctor
---\lua new
---@return ccui.ImageView
function ImageView.new() end

---Sets the source blending function.
---
---@param blendFunc cc.BlendFunc # A structure with source and destination factor to specify pixel arithmetic. e.g. {BlendFactor::ONE, BlendFactor::ONE}, {BlendFactor::SRC_ALPHA, BlendFactor::ONE_MINUS_SRC_ALPHA}.
---\js NA
---\lua NA
function ImageView:setBlendFunc(blendFunc) end

---Sets capInsets for imageview.
---The capInsets affects the ImageView's renderer only if `setScale9Enabled(true)` is called.
---
---@param capInsets cc.Rect # capinsets for imageview
function ImageView:setCapInsets(capInsets) end

---Enable scale9 renderer.
---
---@param enabled boolean # Set to true will use scale9 renderer, false otherwise.
function ImageView:setScale9Enabled(enabled) end

---Updates the texture rect of the ImageView in points.
---It will call setTextureRect:rotated:untrimmedSize with rotated = NO, and utrimmedSize = rect.size.
---@param rect cc.Rect
function ImageView:setTextureRect(rect) end

return ImageView