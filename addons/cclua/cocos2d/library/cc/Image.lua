---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.Image

---
---@class cc.Image : cc.Ref
---@field bitPerPixel integer 
---@field compressed boolean 
---@field data string 
---@field dataLen integer 
---@field filePath string 
---@field fileType cc.Image.Format 
---@field height integer 
---@field numberOfMipmaps integer 
---@field pixelFormat ccb.PixelFormat 
---@field pngPremultipliedAlphaEnabled boolean 
---@field width integer 
local Image = {}

---@return integer
function Image:getBitPerPixel() end

---@return string
function Image:getData() end

---@return integer
function Image:getDataLen() end

---@return string
function Image:getFilePath() end

---@return cc.Image.Format
function Image:getFileType() end

---@return integer
function Image:getHeight() end

---@return integer
function Image:getNumberOfMipmaps() end

---@return boolean
function Image.getPNGPremultipliedAlphaEnabled() end

---@return ccb.PixelFormat
function Image:getPixelFormat() end

---@return integer
function Image:getWidth() end

---@return boolean
function Image:hasAlpha() end

---@return boolean
function Image:hasPremultipliedAlpha() end

---Load image from stream buffer.
---@param data string # stream buffer which holds the image data.
---@param dataLen integer # data length expressed in (number of) bytes.
---@return boolean # true if loaded correctly.
---\js NA
---\lua NA
function Image:initWithImageData(data, dataLen) end

---Load the image from the specified path.
---@param path string # the absolute file path.
---@return boolean # true if loaded correctly.
function Image:initWithImageFile(path) end

---@param data string
---@param dataLen integer
---@param width integer
---@param height integer
---@param bitsPerComponent integer
---@param preMulti boolean
---@return boolean
---@overload fun(self: cc.Image, data: string, dataLen: integer, width: integer, height: integer, bitsPerComponent: integer): boolean
function Image:initWithRawData(data, dataLen, width, height, bitsPerComponent, preMulti) end

---@return boolean
function Image:isCompressed() end

---\js ctor
---@return cc.Image
function Image.new() end

function Image:premultiplyAlpha() end

function Image:reversePremultipliedAlpha() end

---Save Image data to the specified file, with specified format.
---\param    filePath        the file's absolute path, including file suffix.
---@param isToRGB boolean # whether the image is saved as RGB format.
---@param filename string
---@return boolean
---@overload fun(self: cc.Image, filename: string): boolean
function Image:saveToFile(filename, isToRGB) end

---Enables or disables premultiplied alpha for PNG files.
---
---@param enabled boolean # (default: true)
function Image.setPNGPremultipliedAlphaEnabled(enabled) end

---treats (or not) PVR files as if they have alpha premultiplied.
---Since it is impossible to know at runtime if the PVR images have the alpha channel premultiplied, it is
---possible load them as if they have (or not) the alpha channel premultiplied.
---
---By default it is disabled.
---@param haveAlphaPremultiplied boolean
function Image.setPVRImagesHavePremultipliedAlpha(haveAlphaPremultiplied) end

return Image