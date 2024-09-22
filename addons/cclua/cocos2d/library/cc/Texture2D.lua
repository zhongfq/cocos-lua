---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.Texture2D

---Texture2D class. This class allows to easily create OpenGL 2D textures from images, text or raw data.
---The created Texture2D object will always have power-of-two dimensions.
---Depending on how you create the Texture2D object, the actual image area of the texture might be smaller than the texture dimensions i.e. "contentSize" != (pixelsWide, pixelsHigh) and (maxS, maxT) != (1.0, 1.0).
---Be aware that the content of the generated textures will be upside-down!
---@class cc.Texture2D : cc.Ref
---@field alphaTexture cc.Texture2D 
---@field alphaTextureName boolean 
---@field backendTexture ccb.TextureBackend 
---@field contentSize cc.Size Get the texture content size.
---@field contentSizeInPixels cc.Size Get content size.
---@field defaultAlphaPixelFormat ccb.PixelFormat Returns the alpha pixel format. \since v0.8
---@field maxS number Gets max S.
---@field maxT number Gets max T.
---@field path string 
---@field pixelFormat ccb.PixelFormat Gets the pixel format of the texture.
---@field pixelFormatInfoMap { [ccb.PixelFormat]: cc.Texture2D.PixelFormatInfo } Get pixel info map, the key-value pairs is PixelFormat and PixelFormatInfo.
---@field pixelsHigh integer Gets the height of the texture in pixels.
---@field pixelsWide integer Gets the width of the texture in pixels.
---@field renderTarget boolean 
---@field stringForFormat string Returns the pixel format. \since v2.0
local Texture2D = {}

---Drawing extensions to make it easy to draw basic quads using a Texture2D object.
---These functions require GL_TEXTURE_2D and both GL_VERTEX_ARRAY and GL_TEXTURE_COORD_ARRAY client states to be enabled.
---
---Draws a texture at a given point.
---@param point cc.Vec2
---@param globalZOrder number
function Texture2D:drawAtPoint(point, globalZOrder) end

---Draws a texture inside a rect.
---@param rect cc.Rect
---@param globalZOrder number
function Texture2D:drawInRect(rect, globalZOrder) end

---Generates mipmap images for the texture.
---It only works if the texture size is POT (power of 2).
---\since v0.99.0
function Texture2D:generateMipmap() end

---@return cc.Texture2D
function Texture2D:getAlphaTexture() end

---@return boolean
function Texture2D:getAlphaTextureName() end

---@return ccb.TextureBackend
function Texture2D:getBackendTexture() end

---Returns the bits-per-pixel of the in-memory OpenGL texture
---\since v1.0
---@return integer
---
---Helper functions that returns bits per pixels for a given format.
---\since v2.0
---@overload fun(self: cc.Texture2D, format: ccb.PixelFormat): integer
function Texture2D:getBitsPerPixelForFormat() end

---Get the texture content size.
---@return cc.Size
function Texture2D:getContentSize() end

---Get content size.
---@return cc.Size
function Texture2D:getContentSizeInPixels() end

---Returns the alpha pixel format.
---\since v0.8
---@return ccb.PixelFormat
function Texture2D.getDefaultAlphaPixelFormat() end

---Gets max S.
---@return number
function Texture2D:getMaxS() end

---Gets max T.
---@return number
function Texture2D:getMaxT() end

---@return string
function Texture2D:getPath() end

---Gets the pixel format of the texture.
---@return ccb.PixelFormat
function Texture2D:getPixelFormat() end

---Get pixel info map, the key-value pairs is PixelFormat and PixelFormatInfo.
---@return { [ccb.PixelFormat]: cc.Texture2D.PixelFormatInfo }
function Texture2D.getPixelFormatInfoMap() end

---Gets the height of the texture in pixels.
---@return integer
function Texture2D:getPixelsHigh() end

---Gets the width of the texture in pixels.
---@return integer
function Texture2D:getPixelsWide() end

---Returns the pixel format.
---\since v2.0
---@return string
function Texture2D:getStringForFormat() end

---Whether or not the texture has mip maps.
---@return boolean
function Texture2D:hasMipmaps() end

---Whether or not the texture has their Alpha premultiplied.
---@return boolean
function Texture2D:hasPremultipliedAlpha() end

---@param texture ccb.TextureBackend
---@param preMultipliedAlpha boolean
---@return boolean
---@overload fun(self: cc.Texture2D, texture: ccb.TextureBackend): boolean
function Texture2D:initWithBackendTexture(texture, preMultipliedAlpha) end

---Initializes with a texture2d with data.
---
---@param data any # Specifies a pointer to the image data in memory.
---@param dataLen integer # The image data length.
---@param pixelFormat ccb.PixelFormat # The image pixelFormat.
---@param pixelsWide integer # The image width.
---@param pixelsHigh integer # The image height.
---@param contentSize cc.Size # The image content size.
---@param preMultipliedAlpha boolean # The texture has premultiplied alpha
---\js NA
---\lua NA
---@return boolean
---@overload fun(self: cc.Texture2D, data: any, dataLen: integer, pixelFormat: ccb.PixelFormat, pixelsWide: integer, pixelsHigh: integer, contentSize: cc.Size): boolean
---
---Initializes with a texture2d with data.
---
---\param data Specifies a pointer to the image data in memory.
---\param dataLen The image data length.
---\param pixelFormat The image pixelFormat.
---\param renderFormat The format converted to.
---\param pixelsWide The image width.
---\param pixelsHigh The image height.
---\param contentSize The image content size.
---\param preMultipliedAlpha The texture has premultiplied alpha
---\js NA
---\lua NA
---@overload fun(self: cc.Texture2D, data: any, dataLen: integer, pixelFormat: ccb.PixelFormat, renderFormat: ccb.PixelFormat, pixelsWide: integer, pixelsHigh: integer, contentSize: cc.Size, preMultipliedAlpha: boolean): boolean
---
---Initializes with a texture2d with data.
---
---\param data Specifies a pointer to the image data in memory.
---\param dataLen The image data length.
---\param pixelFormat The image pixelFormat.
---\param renderFormat The format converted to.
---\param pixelsWide The image width.
---\param pixelsHigh The image height.
---\param contentSize The image content size.
---\param preMultipliedAlpha The texture has premultiplied alpha
---\js NA
---\lua NA
---@overload fun(self: cc.Texture2D, data: any, dataLen: integer, pixelFormat: ccb.PixelFormat, renderFormat: ccb.PixelFormat, pixelsWide: integer, pixelsHigh: integer, contentSize: cc.Size): boolean
function Texture2D:initWithData(data, dataLen, pixelFormat, pixelsWide, pixelsHigh, contentSize, preMultipliedAlpha) end

---Extensions to make it easy to create a Texture2D object from an image file.
---
---
---Initializes a texture from a UIImage object.
---We will use the format you specified with setDefaultAlphaPixelFormat to convert the image for texture.
---NOTE: It will not convert the pvr image file.
---@param image cc.Image # An UIImage object.
---@return boolean
---
---Initializes a texture from a UIImage object.
---We will use the format you passed to the function to convert the image format to the texture format.
---If you pass PixelFormat::Automatic, we will auto detect the image render type and use that type for texture to render.
---\param image An UIImage object.
---\param format Texture pixel formats.
---@overload fun(self: cc.Texture2D, image: cc.Image, format: ccb.PixelFormat): boolean
function Texture2D:initWithImage(image) end

---Initializes a texture from a string with dimensions, alignment, font name and font size. 
---
---@param text string # A null terminated string.
---@param fontName string # The font name.
---@param fontSize number # The font size.
---@param dimensions cc.Size # The font dimension.
---@param hAlignment cc.TextHAlignment # The font horizontal text alignment type.
---@param vAlignment cc.TextVAlignment # The font vertical text alignment type.
---@param enableWrap boolean # Whether enable text wrap or not.
---@param overflow integer # Whether shrink font size when content larger than the dimensions.
---@return boolean
---@overload fun(self: cc.Texture2D, text: string, fontName: string, fontSize: number): boolean
---@overload fun(self: cc.Texture2D, text: string, fontName: string, fontSize: number, dimensions: cc.Size): boolean
---@overload fun(self: cc.Texture2D, text: string, fontName: string, fontSize: number, dimensions: cc.Size, hAlignment: cc.TextHAlignment): boolean
---@overload fun(self: cc.Texture2D, text: string, fontName: string, fontSize: number, dimensions: cc.Size, hAlignment: cc.TextHAlignment, vAlignment: cc.TextVAlignment): boolean
---@overload fun(self: cc.Texture2D, text: string, fontName: string, fontSize: number, dimensions: cc.Size, hAlignment: cc.TextHAlignment, vAlignment: cc.TextVAlignment, enableWrap: boolean): boolean
function Texture2D:initWithString(text, fontName, fontSize, dimensions, hAlignment, vAlignment, enableWrap, overflow) end

---@return boolean
function Texture2D:isRenderTarget() end

---\js ctor
---@return cc.Texture2D
function Texture2D.new() end

---Sets alias texture parameters:
---- GL_TEXTURE_MIN_FILTER = GL_NEAREST
---- GL_TEXTURE_MAG_FILTER = GL_NEAREST
---\warning Calling this method could allocate additional texture memory.
---\since v0.8
function Texture2D:setAliasTexParameters() end

---@param alphaTexture cc.Texture2D
function Texture2D:setAlphaTexture(alphaTexture) end

---Sets antialias texture parameters:
---- GL_TEXTURE_MIN_FILTER = GL_LINEAR
---- GL_TEXTURE_MAG_FILTER = GL_LINEAR
---
---\warning Calling this method could allocate additional texture memory.
---
---\since v0.8
function Texture2D:setAntiAliasTexParameters() end

---sets the default pixel format for UIImagescontains alpha channel.
---
---@param format ccb.PixelFormat # 
---If the UIImage contains alpha channel, then the options are:
---- generate 32-bit textures: backend::PixelFormat::RGBA8888 (default one)
---- generate 24-bit textures: backend::PixelFormat::RGB888
---- generate 16-bit textures: backend::PixelFormat::RGBA4444
---- generate 16-bit textures: backend::PixelFormat::RGB5A1
---- generate 16-bit textures: backend::PixelFormat::RGB565
---- generate 8-bit textures: backend::PixelFormat::A8 (only use it if you use just 1 color)
---How does it work ?
---- If the image is an RGBA (with Alpha) then the default pixel format will be used (it can be a 8-bit, 16-bit or 32-bit texture)
---- If the image is an RGB (without Alpha) then: If the default pixel format is RGBA8888 then a RGBA8888 (32-bit) will be used. Otherwise a RGB565 (16-bit texture) will be used.
---This parameter is not valid for PVR / PVR.CCZ images.
---\since v0.8
function Texture2D.setDefaultAlphaPixelFormat(format) end

---Sets max S.
---@param maxS number
function Texture2D:setMaxS(maxS) end

---Sets max T.
---@param maxT number
function Texture2D:setMaxT(maxT) end

---@param renderTarget boolean
function Texture2D:setRenderTarget(renderTarget) end

---@param params ccb.SamplerDescriptor
function Texture2D:setTexParameters(params) end

---Update with texture data.
---
---@param data any # Specifies a pointer to the image data in memory.
---@param offsetX integer # Specifies a texel offset in the x direction within the texture array.
---@param offsetY integer # Specifies a texel offset in the y direction within the texture array.
---@param width integer # Specifies the width of the texture subimage.
---@param height integer # Specifies the height of the texture subimage.
---@return boolean
function Texture2D:updateWithData(data, offsetX, offsetY, width, height) end

return Texture2D