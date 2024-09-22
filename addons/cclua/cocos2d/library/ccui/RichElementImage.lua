---AUTO GENERATED, DO NOT MODIFY!
---@meta ccui.RichElementImage

---Rich element for displaying images.
---@class ccui.RichElementImage : ccui.RichElement
local RichElementImage = {}

---Create a RichElementImage with various arguments.
---
---@param tag integer # A integer tag value.
---@param color any # A color in Color3B.
---@param opacity integer # A opacity in GLubyte.
---@param filePath string # A image file name.
---@param url string # uniform resource locator
---@param texType ccui.Widget.TextureResType # texture type, may be a valid file path, or a sprite frame name
---@return ccui.RichElementImage # A RichElementImage instance.
---@overload fun(tag: integer, color: any, opacity: integer, filePath: string): ccui.RichElementImage
---@overload fun(tag: integer, color: any, opacity: integer, filePath: string, url: string): ccui.RichElementImage
function RichElementImage.create(tag, color, opacity, filePath, url, texType) end

---Initialize a RichElementImage with various arguments.
---
---@param tag integer # A integer tag value.
---@param color any # A color in Color3B.
---@param opacity integer # A opacity in GLubyte.
---@param filePath string # A image file name.
---@param url string # uniform resource locator
---@param texType ccui.Widget.TextureResType # texture type, may be a valid file path, or a sprite frame name
---@return boolean # True if initialize success, false otherwise.
---@overload fun(self: ccui.RichElementImage, tag: integer, color: any, opacity: integer, filePath: string): boolean
---@overload fun(self: ccui.RichElementImage, tag: integer, color: any, opacity: integer, filePath: string, url: string): boolean
function RichElementImage:init(tag, color, opacity, filePath, url, texType) end

---Default constructor.
---\js ctor
---\lua new
---@return ccui.RichElementImage
function RichElementImage.new() end

---@param height integer
function RichElementImage:setHeight(height) end

---@param url string
function RichElementImage:setUrl(url) end

---@param width integer
function RichElementImage:setWidth(width) end

return RichElementImage