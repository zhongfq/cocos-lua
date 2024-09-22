---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.RenderTexture

---RenderTexture is a generic rendering target. To render things into it,
---simply construct a render target, call begin on it, call visit on any cocos
---scenes or objects to render them, and call end. For convenience, render texture
---adds a sprite as it's display child with the results, so you can simply add
---the render texture to your scene and treat it like any other CocosNode.
---There are also functions for saving the render texture to disk in PNG or JPG format.
---\since v0.8.1
---@class cc.RenderTexture : cc.Node
---@field autoDraw boolean When enabled, it will render its children into the texture automatically. Disabled by default for compatibility reasons. Will be enabled in the future. <br><br>\return Return the autoDraw value.
---@field clearColor any Clear color value. Valid only when "autoDraw" is true.  <br><br>\return Color value.
---@field clearFlags cc.ClearFlag Valid when "autoDraw" is true. <br><br>\return Clear flags.
---@field sprite cc.Sprite Gets the Sprite being used.  <br><br>\return A Sprite.
local RenderTexture = {}

---Starts grabbing.
function RenderTexture:begin() end

---@param rt cc.RenderTexture
function RenderTexture.beginVisit(rt) end

---Starts rendering to the texture while clearing the texture first.
---This is more efficient then calling -clear first and then -begin.
---
---@param r number # Red.
---@param g number # Green.
---@param b number # Blue.
---@param a number # Alpha.
---
---Starts rendering to the texture while clearing the texture first.
---This is more efficient then calling -clear first and then -begin.
---
---\param r Red.
---\param g Green.
---\param b Blue.
---\param a Alpha.
---\param depthValue The depth Value.
---@overload fun(self: cc.RenderTexture, r: number, g: number, b: number, a: number, depthValue: number)
---
---Starts rendering to the texture while clearing the texture first.
---This is more efficient then calling -clear first and then -begin. 
---
---\param r Red.
---\param g Green.
---\param b Blue.
---\param a Alpha.
---\param depthValue A specified depth value.
---\param stencilValue A specified stencil value.
---@overload fun(self: cc.RenderTexture, r: number, g: number, b: number, a: number, depthValue: number, stencilValue: integer)
function RenderTexture:beginWithClear(r, g, b, a) end

---Clears the texture with a color. 
---
---@param r number # Red.
---@param g number # Green.
---@param b number # Blue.
---@param a number # Alpha.
function RenderTexture:clear(r, g, b, a) end

---Clears the texture with a specified depth value. 
---
---@param depthValue number # A specified depth value.
function RenderTexture:clearDepth(depthValue) end

---Clears the texture with a specified stencil value.
---
---@param stencilValue integer # A specified stencil value.
function RenderTexture:clearStencil(stencilValue) end

---Initializes a RenderTexture object with width and height in Points and a pixel format( only RGB and RGBA formats are valid ) and depthStencil format. 
---
---@param w integer # The RenderTexture object width.
---@param h integer # The RenderTexture object height.
---@param format ccb.PixelFormat # In Points and a pixel format( only RGB and RGBA formats are valid ).
---@param depthStencilFormat ccb.PixelFormat # The depthStencil format.
---@return cc.RenderTexture
---
---Creates a RenderTexture object with width and height in Points and a pixel format, only RGB and RGBA formats are valid. 
---
---\param w The RenderTexture object width.
---\param h The RenderTexture object height.
---\param format In Points and a pixel format( only RGB and RGBA formats are valid ).
---@overload fun(w: integer, h: integer, format: ccb.PixelFormat): cc.RenderTexture
---
---Creates a RenderTexture object with width and height in Points, pixel format is RGBA8888. 
---
---\param w The RenderTexture object width.
---\param h The RenderTexture object height.
---@overload fun(w: integer, h: integer): cc.RenderTexture
function RenderTexture.create(w, h, format, depthStencilFormat) end

---@param rt cc.RenderTexture
function RenderTexture.endVisit(rt) end

---Ends grabbing.
---\lua endToLua
function RenderTexture:end_() end

---Clear color value. Valid only when "autoDraw" is true. 
---
---@return any # Color value.
function RenderTexture:getClearColor() end

---Value for clearDepth. Valid only when "autoDraw" is true. 
---
---@return number # Value for clearDepth.
function RenderTexture:getClearDepth() end

---Valid when "autoDraw" is true.
---
---@return cc.ClearFlag # Clear flags.
function RenderTexture:getClearFlags() end

---Value for clear Stencil. Valid only when "autoDraw" is true.
---
---@return integer # Value for clear Stencil.
function RenderTexture:getClearStencil() end

---Gets the Sprite being used. 
---
---@return cc.Sprite # A Sprite.
function RenderTexture:getSprite() end

---Initializes a RenderTexture object with width and height in Points and a pixel format, only RGB and RGBA formats are valid.
---
---@param w integer # The RenderTexture object width.
---@param h integer # The RenderTexture object height.
---@param format ccb.PixelFormat # In Points and a pixel format( only RGB and RGBA formats are valid ).
---@return boolean # If succeed, it will return true.
---
---Initializes a RenderTexture object with width and height in Points and a pixel format( only RGB and RGBA formats are valid ) and depthStencil format. 
---
---\param w The RenderTexture object width.
---\param h The RenderTexture object height.
---\param format In Points and a pixel format( only RGB and RGBA formats are valid ).
---\param depthStencilFormat The depthStencil format.
---\return If succeed, it will return true.
---@overload fun(self: cc.RenderTexture, w: integer, h: integer, format: ccb.PixelFormat, depthStencilFormat: ccb.PixelFormat): boolean
function RenderTexture:initWithWidthAndHeight(w, h, format) end

---When enabled, it will render its children into the texture automatically. Disabled by default for compatibility reasons.
---Will be enabled in the future.
---
---@return boolean # Return the autoDraw value.
function RenderTexture:isAutoDraw() end

---Listen "come to background" message, and save render texture.
---It only has effect on Android.
---
---@param event cc.EventCustom # Event Custom.
function RenderTexture:listenToBackground(event) end

---Listen "come to foreground" message and restore the frame buffer object.
---It only has effect on Android.
---
---@param event cc.EventCustom # Event Custom.
function RenderTexture:listenToForeground(event) end

---FIXME: should be protected.
---but due to a bug in PowerVR + Android,
---the constructor is public again.
---\js ctor
---@return cc.RenderTexture
function RenderTexture.new() end

---@param imageCallback fun(arg1: cc.Image)
---@param flipImage boolean
---@overload fun(self: cc.RenderTexture, imageCallback: fun(arg1: cc.Image))
function RenderTexture:newImage(imageCallback, flipImage) end

---Saves the texture into a file using JPEG format. The file will be saved in the Documents folder.
---Returns true if the operation is successful.
---
---@param filename string # The file name.
---@param isRGBA boolean # The file is RGBA or not.
---@param callback fun(arg1: cc.RenderTexture, arg2: string) # When the file is save finished,it will callback this function.
---@return boolean # Returns true if the operation is successful.
---@overload fun(self: cc.RenderTexture, filename: string): boolean
---@overload fun(self: cc.RenderTexture, filename: string, isRGBA: boolean): boolean
---
---saves the texture into a file. The format could be JPG or PNG. The file will be saved in the Documents folder.
---Returns true if the operation is successful.
---Notes: since v3.x, saveToFile will generate a custom command, which will be called in the following render->render().
---So if this function is called in a event handler, the actual save file will be called in the next frame. If we switch to a different scene, the game will crash.
---To solve this, add Director::getInstance()->getRenderer()->render(); after this function.
---
---\param filename The file name.
---\param format The image format.
---\param isRGBA The file is RGBA or not.
---\param callback When the file is save finished,it will callback this function.
---\return Returns true if the operation is successful.
---@overload fun(self: cc.RenderTexture, filename: string, format: cc.Image.Format, isRGBA: boolean, callback: fun(arg1: cc.RenderTexture, arg2: string)): boolean
---
---saves the texture into a file. The format could be JPG or PNG. The file will be saved in the Documents folder.
---Returns true if the operation is successful.
---Notes: since v3.x, saveToFile will generate a custom command, which will be called in the following render->render().
---So if this function is called in a event handler, the actual save file will be called in the next frame. If we switch to a different scene, the game will crash.
---To solve this, add Director::getInstance()->getRenderer()->render(); after this function.
---
---\param filename The file name.
---\param format The image format.
---\param isRGBA The file is RGBA or not.
---\param callback When the file is save finished,it will callback this function.
---\return Returns true if the operation is successful.
---@overload fun(self: cc.RenderTexture, filename: string, format: cc.Image.Format): boolean
---
---saves the texture into a file. The format could be JPG or PNG. The file will be saved in the Documents folder.
---Returns true if the operation is successful.
---Notes: since v3.x, saveToFile will generate a custom command, which will be called in the following render->render().
---So if this function is called in a event handler, the actual save file will be called in the next frame. If we switch to a different scene, the game will crash.
---To solve this, add Director::getInstance()->getRenderer()->render(); after this function.
---
---\param filename The file name.
---\param format The image format.
---\param isRGBA The file is RGBA or not.
---\param callback When the file is save finished,it will callback this function.
---\return Returns true if the operation is successful.
---@overload fun(self: cc.RenderTexture, filename: string, format: cc.Image.Format, isRGBA: boolean): boolean
function RenderTexture:saveToFile(filename, isRGBA, callback) end

---Saves the texture into a file using JPEG format. The file will be saved in the Documents folder.
---Returns true if the operation is successful.
---
---@param filename string # The file name.
---@param isRGBA boolean # The file is RGBA or not.
---@param callback fun(arg1: cc.RenderTexture, arg2: string) # When the file is save finished,it will callback this function.
---@return boolean # Returns true if the operation is successful.
---@overload fun(self: cc.RenderTexture, filename: string): boolean
---@overload fun(self: cc.RenderTexture, filename: string, isRGBA: boolean): boolean
---
---saves the texture into a file in non-PMA. The format could be JPG or PNG. The file will be saved in the Documents folder.
---Returns true if the operation is successful.
---Notes: since v3.x, saveToFile will generate a custom command, which will be called in the following render->render().
---So if this function is called in a event handler, the actual save file will be called in the next frame. If we switch to a different scene, the game will crash.
---To solve this, add Director::getInstance()->getRenderer()->render(); after this function.
---
---\param filename The file name.
---\param format The image format.
---\param isRGBA The file is RGBA or not.
---\param callback When the file is save finished,it will callback this function.
---\return Returns true if the operation is successful.
---@overload fun(self: cc.RenderTexture, fileName: string, format: cc.Image.Format, isRGBA: boolean, callback: fun(arg1: cc.RenderTexture, arg2: string)): boolean
function RenderTexture:saveToFileAsNonPMA(filename, isRGBA, callback) end

---Set a valve to control whether or not render its children into the texture automatically. 
---
---@param isAutoDraw boolean # Whether or not render its children into the texture automatically.
function RenderTexture:setAutoDraw(isAutoDraw) end

---Set color value. 
---
---@param clearColor any # Color value.
function RenderTexture:setClearColor(clearColor) end

---Set Value for clearDepth.
---
---@param clearDepth number # Value for clearDepth.
function RenderTexture:setClearDepth(clearDepth) end

---Set flags.
---
---@param clearFlags cc.ClearFlag # set clear flags.
function RenderTexture:setClearFlags(clearFlags) end

---Set Value for clear Stencil.
---
---@param clearStencil integer # Value for clear Stencil.
function RenderTexture:setClearStencil(clearStencil) end

---Flag: Use stack matrix computed from scene hierarchy or generate new modelView and projection matrix.
---
---@param keepMatrix boolean # Whether or not use stack matrix computed from scene hierarchy or generate new modelView and projection matrix.
---\js NA
function RenderTexture:setKeepMatrix(keepMatrix) end

---Sets the Sprite being used. 
---
---@param sprite cc.Sprite # A Sprite.
function RenderTexture:setSprite(sprite) end

---Used for grab part of screen to a texture. 
---@param rtBegin cc.Vec2 # The position of renderTexture on the fullRect.
---@param fullRect cc.Rect # The total size of screen.
---@param fullViewport cc.Rect # The total viewportSize.
function RenderTexture:setVirtualViewport(rtBegin, fullRect, fullViewport) end

return RenderTexture