---AUTO GENERATED, DO NOT MODIFY!
---@meta ccui.LoadingBar

---Visual indicator of progress in some operation.
---Displays a bar to the user representing how far the operation has progressed.
---@class ccui.LoadingBar : ccui.Widget
---@field capInsets cc.Rect Query LoadingBar's capInsets. \return CapInsets of LoadingBar.
---@field direction ccui.LoadingBar.Direction Get the progress direction of LoadingBar. <br><br>\see Direction  `LEFT` means progress left to right, `RIGHT` otherwise. \return LoadingBar progress direction.
---@field percent number Get the progress value of LoadingBar. <br><br>\return Progress value from 1 to 100.
---@field renderFile cc.ResourceData 
---@field scale9Enabled boolean Query whether LoadingBar is using scale9 renderer or not. \return Whether LoadingBar uses scale9 renderer or not.
local LoadingBar = {}

---Create an empty LoadingBar.
---@return ccui.LoadingBar # A LoadingBar instance.
---
---Create a LoadingBar with a texture name and a predefined progress value.
---
---\param textureName LoadingBar background texture name.
---\param percentage A percentage in float.
---\return A LoadingBar instance.
---@overload fun(textureName: string, percentage: number): ccui.LoadingBar
---
---Create a LoadingBar with a texture name and a predefined progress value.
---
---\param textureName LoadingBar background texture name.
---\param percentage A percentage in float.
---\return A LoadingBar instance.
---@overload fun(textureName: string): ccui.LoadingBar
---
---Create a LoadingBar with a texture name along with its texture type and a predefined progress value.
---
---\param textureName LoadingBar background texture name.
---\param texType LoadingBar background texture type.
---\param percentage A percentage in float, default value is 0.
---\return A LoadingBar instance.
---@overload fun(textureName: string, texType: ccui.Widget.TextureResType, percentage: number): ccui.LoadingBar
---
---Create a LoadingBar with a texture name along with its texture type and a predefined progress value.
---
---\param textureName LoadingBar background texture name.
---\param texType LoadingBar background texture type.
---\param percentage A percentage in float, default value is 0.
---\return A LoadingBar instance.
---@overload fun(textureName: string, texType: ccui.Widget.TextureResType): ccui.LoadingBar
function LoadingBar.create() end

---@return cc.Ref
function LoadingBar.createInstance() end

---Query LoadingBar's capInsets.
---@return cc.Rect # CapInsets of LoadingBar.
function LoadingBar:getCapInsets() end

---Get the progress direction of LoadingBar.
---
---\see Direction  `LEFT` means progress left to right, `RIGHT` otherwise.
---@return ccui.LoadingBar.Direction # LoadingBar progress direction.
function LoadingBar:getDirection() end

---Get the progress value of LoadingBar.
---
---@return number # Progress value from 1 to 100.
function LoadingBar:getPercent() end

---@return cc.ResourceData
function LoadingBar:getRenderFile() end

---Query whether LoadingBar is using scale9 renderer or not.
---@return boolean # Whether LoadingBar uses scale9 renderer or not.
function LoadingBar:isScale9Enabled() end

---Load texture for LoadingBar.
---
---@param texture string # File name of texture.
---@param texType ccui.Widget.TextureResType # Texture resource type,@see TextureResType.
---@overload fun(self: ccui.LoadingBar, texture: string)
function LoadingBar:loadTexture(texture, texType) end

---Default constructor.
---\js ctor
---\lua new
---@return ccui.LoadingBar
function LoadingBar.new() end

---Set capInsets for LoadingBar.
---This setting only take effect when enable scale9 renderer.
---@param capInsets cc.Rect # CapInset in `Rect`.
function LoadingBar:setCapInsets(capInsets) end

---Change the progress direction of LoadingBar.
---
---\see Direction  `LEFT` means progress left to right, `RIGHT` otherwise.
---@param direction ccui.LoadingBar.Direction # Direction
function LoadingBar:setDirection(direction) end

---Changes the progress value of LoadingBar.
---
---@param percent number # Percent value from 1 to 100.
function LoadingBar:setPercent(percent) end

---Enable scale9 renderer.
---
---@param enabled boolean # Set to true will use scale9 renderer, false otherwise.
function LoadingBar:setScale9Enabled(enabled) end

return LoadingBar