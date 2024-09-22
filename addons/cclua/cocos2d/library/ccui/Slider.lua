---AUTO GENERATED, DO NOT MODIFY!
---@meta ccui.Slider

---UI Slider widget.
---@class ccui.Slider : ccui.Widget
---@field backFile cc.ResourceData 
---@field ballDisabledFile cc.ResourceData 
---@field ballNormalFile cc.ResourceData 
---@field ballPressedFile cc.ResourceData 
---@field capInsetsBarRenderer cc.Rect Gets capinsets for bar slider, if slider is using scale9 renderer. \return capInsets Capinsets for bar slider.
---@field capInsetsProgressBarRenderer cc.Rect Gets capinsets for progress bar slider, if slider is using scale9 renderer. \return Capinsets for progress bar slider. \js NA
---@field maxPercent integer Query the maximum percent of Slider. The default value is 100. \since v3.7 \return The maximum percent of the Slider.
---@field percent integer Gets the progress direction of slider. <br><br>\return percent Percent value from 1 to 100.
---@field progressBarFile cc.ResourceData 
---@field scale9Enabled boolean Gets If slider is using scale9 renderer. \return True that using scale9 renderer, false otherwise.
---@field slidBallDisabledRenderer cc.Sprite 
---@field slidBallNormalRenderer cc.Sprite 
---@field slidBallPressedRenderer cc.Sprite 
---@field slidBallRenderer cc.Node 
---@field zoomScale number Return a zoom scale \since v3.3
local Slider = {}

---Add call back function called when slider's percent has changed to slider.
---
---@param callback ccui.Slider.ccSliderCallback # An given call back function called when slider's percent has changed to slider.
function Slider:addEventListener(callback) end

---Create a slider widget.
---
---@return ccui.Slider # An autoreleased Slider object.
---
---Create a slider widget with bar texture, ball texture and texture resource type.
---
---\param barTextureName Bar texture file name.
---\param normalBallTextureName Ball texture file name.
---\param resType Texture resource type.
---\return An autoreleased Slider object.
---@overload fun(barTextureName: string, normalBallTextureName: string, resType: ccui.Widget.TextureResType): ccui.Slider
---
---Create a slider widget with bar texture, ball texture and texture resource type.
---
---\param barTextureName Bar texture file name.
---\param normalBallTextureName Ball texture file name.
---\param resType Texture resource type.
---\return An autoreleased Slider object.
---@overload fun(barTextureName: string, normalBallTextureName: string): ccui.Slider
function Slider.create() end

---@return cc.Ref
function Slider.createInstance() end

---@return cc.ResourceData
function Slider:getBackFile() end

---@return cc.ResourceData
function Slider:getBallDisabledFile() end

---@return cc.ResourceData
function Slider:getBallNormalFile() end

---@return cc.ResourceData
function Slider:getBallPressedFile() end

---Gets capinsets for bar slider, if slider is using scale9 renderer.
---@return cc.Rect # capInsets Capinsets for bar slider.
function Slider:getCapInsetsBarRenderer() end

---Gets capinsets for progress bar slider, if slider is using scale9 renderer.
---@return cc.Rect # Capinsets for progress bar slider.
---\js NA
function Slider:getCapInsetsProgressBarRenderer() end

---Query the maximum percent of Slider. The default value is 100.
---\since v3.7
---@return integer # The maximum percent of the Slider.
function Slider:getMaxPercent() end

---Gets the progress direction of slider.
---
---@return integer # percent Percent value from 1 to 100.
function Slider:getPercent() end

---@return cc.ResourceData
function Slider:getProgressBarFile() end

---@return cc.Sprite
function Slider:getSlidBallDisabledRenderer() end

---@return cc.Sprite
function Slider:getSlidBallNormalRenderer() end

---@return cc.Sprite
function Slider:getSlidBallPressedRenderer() end

---@return cc.Node
function Slider:getSlidBallRenderer() end

---Return a zoom scale
---\since v3.3
---@return number
function Slider:getZoomScale() end

---Gets If slider is using scale9 renderer.
---@return boolean # True that using scale9 renderer, false otherwise.
function Slider:isScale9Enabled() end

---Load texture for slider bar.
---
---@param fileName string # File name of texture.
---@param resType ccui.Widget.TextureResType # @see TextureResType .
---@overload fun(self: ccui.Slider, fileName: string)
function Slider:loadBarTexture(fileName, resType) end

---Load dark state texture for slider progress bar.
---
---@param fileName string # File path of texture.
---@param resType ccui.Widget.TextureResType # @see TextureResType .
---@overload fun(self: ccui.Slider, fileName: string)
function Slider:loadProgressBarTexture(fileName, resType) end

---Load disabled state texture for slider ball.
---
---@param disabled string # Disabled state texture.
---@param resType ccui.Widget.TextureResType # @see TextureResType .
---@overload fun(self: ccui.Slider, disabled: string)
function Slider:loadSlidBallTextureDisabled(disabled, resType) end

---Load normal state texture for slider ball.
---
---@param normal string # Normal state texture.
---@param resType ccui.Widget.TextureResType # @see TextureResType .
---@overload fun(self: ccui.Slider, normal: string)
function Slider:loadSlidBallTextureNormal(normal, resType) end

---Load pressed state texture for slider ball.
---
---@param pressed string # Pressed state texture.
---@param resType ccui.Widget.TextureResType # @see TextureResType .
---@overload fun(self: ccui.Slider, pressed: string)
function Slider:loadSlidBallTexturePressed(pressed, resType) end

---Load textures for slider ball.
---
---@param normal string # Normal state texture.
---@param pressed string # Pressed state texture.
---@param disabled string # Disabled state texture.
---@param texType ccui.Widget.TextureResType # @see TextureResType .
---@overload fun(self: ccui.Slider, normal: string)
---@overload fun(self: ccui.Slider, normal: string, pressed: string)
---@overload fun(self: ccui.Slider, normal: string, pressed: string, disabled: string)
function Slider:loadSlidBallTextures(normal, pressed, disabled, texType) end

---Default constructor.
---\js ctor
---\lua new
---@return ccui.Slider
function Slider.new() end

---Sets capinsets for progress bar slider, if slider is using scale9 renderer.
---@param capInsets cc.Rect # Capinsets for progress bar slider.
---\js NA
function Slider:setCapInsetProgressBarRenderer(capInsets) end

---Sets capinsets for slider, if slider is using scale9 renderer.
---@param capInsets cc.Rect # Capinsets for slider.
function Slider:setCapInsets(capInsets) end

---Sets capinsets for bar slider, if slider is using scale9 renderer.
---@param capInsets cc.Rect # Capinsets for bar slider.
function Slider:setCapInsetsBarRenderer(capInsets) end

---Set a large value could give more control to the precision.
---\since v3.7
---@param percent integer # The max percent of Slider.
function Slider:setMaxPercent(percent) end

---Changes the progress direction of slider.
---@param percent integer # Percent value from 1 to 100.
function Slider:setPercent(percent) end

---Sets if slider is using scale9 renderer.
---@param able boolean # True that using scale9 renderer, false otherwise.
function Slider:setScale9Enabled(able) end

---When user pressed the button, the button will zoom to a scale.
---The final scale of the button  equals (button original scale + _zoomScale)
---\since v3.3
---@param scale number
function Slider:setZoomScale(scale) end

---Updates the visual elements of the slider.
function Slider:updateVisualSlider() end

return Slider