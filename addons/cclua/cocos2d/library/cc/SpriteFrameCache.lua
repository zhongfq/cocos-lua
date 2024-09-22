---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.SpriteFrameCache

---\class SpriteFrameCache
---Singleton that handles the loading of the sprite frames.
---The SpriteFrameCache loads SpriteFrames from a .plist file.
---A SpriteFrame contains information about how to use a sprite
---located in a sprite sheet.
---
---The .plist file contains the following elements:
---- `frames`:
---Dictionary of sprites. Key is the sprite's name, value a dict containing the sprite frame data.
---A sprite frame consists of the following values:
---- `spriteOffset`:     difference vector between the original sprite's center and the center of the trimmed sprite
---- `spriteSize`:       size of the trimmed sprite
---- `spriteSourceSize`: size of the original sprite
---- `textureRect`:      the position of the sprite in the sprite sheet
---- `textureRotated`:   true if the sprite is rotated clockwise
---- `anchor`:           anchor point in normalized coordinates (optional)
---Optional values when using polygon outlines
---- `triangles`:        3 indices per triangle, pointing to vertices and verticesUV coordinates
---- `vertices`:         vertices in sprite coordinates, each vertex consists of a pair of x and y coordinates
---- `verticesUV`:       vertices in the sprite sheet, each vertex consists of a pair of x and y coordinates
---
---- `metadata`:
---Dictionary containing additional information about the sprite sheet:
---- `format`:          plist file format, currently 3
---- `size`:            size of the texture (optional)
---- `textureFileName`: name of the texture's image file
---
---Use one of the following tools to create the .plist file and sprite sheet:
---- [TexturePacker](https://www.codeandweb.com/texturepacker/cocos2d)
---- [Zwoptex](https://zwopple.com/zwoptex/)
---
---\since v0.9
---\js cc.spriteFrameCache
---@class cc.SpriteFrameCache : cc.Ref
---@field instance cc.SpriteFrameCache Returns the shared instance of the Sprite Frame cache. <br><br>\return The instance of the Sprite Frame Cache. \js NA
local SpriteFrameCache = {}

---Adds an sprite frame with a given name.
---If the name already exists, then the contents of the old name will be replaced with the new one.
---
---@param frame cc.SpriteFrame # A certain sprite frame.
---@param frameName string # The name of the sprite frame.
function SpriteFrameCache:addSpriteFrame(frame, frameName) end

---Adds multiple Sprite Frames from a plist file.
---A texture will be loaded automatically. The texture name will composed by replacing the .plist suffix with .png.
---If you want to use another texture, you should use the addSpriteFramesWithFile(const std::string& plist, const std::string& textureFileName) method.
---\js addSpriteFrames
---\lua addSpriteFrames
---
---@param plist string # Plist file name.
---
---Adds multiple Sprite Frames from a plist file. The texture will be associated with the created sprite frames.
---\since v0.99.5
---\js addSpriteFrames
---\lua addSpriteFrames
---
---\param plist Plist file name.
---\param textureFileName Texture file name.
---@overload fun(self: cc.SpriteFrameCache, plist: string, textureFileName: string)
---
---Adds multiple Sprite Frames from a plist file. The texture will be associated with the created sprite frames. 
---\js addSpriteFrames
---\lua addSpriteFrames
---
---\param plist Plist file name.
---\param texture Texture pointer.
---@overload fun(self: cc.SpriteFrameCache, plist: string, texture: cc.Texture2D)
function SpriteFrameCache:addSpriteFramesWithFile(plist) end

---Adds multiple Sprite Frames from a plist file content. The texture will be associated with the created sprite frames. 
---\js NA
---\lua addSpriteFrames
---
---@param plist_content string # Plist file content string.
---@param texture cc.Texture2D # Texture pointer.
function SpriteFrameCache:addSpriteFramesWithFileContent(plist_content, texture) end

---Destroys the cache. It releases all the Sprite Frames and the retained instance.
---\js NA
function SpriteFrameCache.destroyInstance() end

---Returns the shared instance of the Sprite Frame cache.
---
---@return cc.SpriteFrameCache # The instance of the Sprite Frame Cache.
---\js NA
function SpriteFrameCache.getInstance() end

---Returns an Sprite Frame that was previously added.
---If the name is not found it will return nil.
---You should retain the returned copy if you are going to use it.
---\js getSpriteFrame
---\lua getSpriteFrame
---
---@param name string # A certain sprite frame name.
---@return cc.SpriteFrame # The sprite frame.
function SpriteFrameCache:getSpriteFrameByName(name) end

---Initialize method.
---
---@return boolean # if success return true.
function SpriteFrameCache:init() end

---Check if multiple Sprite Frames from a plist file have been loaded.
---\js NA
---\lua NA
---
---@param plist string # Plist file name.
---@return boolean # True if the file is loaded.
function SpriteFrameCache:isSpriteFramesWithFileLoaded(plist) end

---@param plist string
---@return boolean
function SpriteFrameCache:reloadTexture(plist) end

---Deletes an sprite frame from the sprite frame cache. 
---
---@param name string # The name of the sprite frame that needs to removed.
function SpriteFrameCache:removeSpriteFrameByName(name) end

---Purges the dictionary of loaded sprite frames.
---Call this method if you receive the "Memory Warning".
---In the short term: it will free some resources preventing your app from being killed.
---In the medium term: it will allocate more resources.
---In the long term: it will be the same.
function SpriteFrameCache:removeSpriteFrames() end

---Removes multiple Sprite Frames from a plist file.
---Sprite Frames stored in this file will be removed.
---It is convenient to call this method when a specific texture needs to be removed.
---\since v0.99.5
---
---@param plist string # The name of the plist that needs to removed.
function SpriteFrameCache:removeSpriteFramesFromFile(plist) end

---Removes multiple Sprite Frames from a plist file content.
---Sprite Frames stored in this file will be removed.
---It is convenient to call this method when a specific texture needs to be removed.
---
---@param plist_content string # The string of the plist content that needs to removed.
---\js NA
function SpriteFrameCache:removeSpriteFramesFromFileContent(plist_content) end

---Removes all Sprite Frames associated with the specified textures.
---It is convenient to call this method when a specific texture needs to be removed.
---\since v0.995.
---
---@param texture cc.Texture2D # The texture that needs to removed.
function SpriteFrameCache:removeSpriteFramesFromTexture(texture) end

---Removes unused sprite frames.
---Sprite Frames that have a retain count of 1 will be deleted.
---It is convenient to call this method after when starting a new Scene.
---\js NA
function SpriteFrameCache:removeUnusedSpriteFrames() end

return SpriteFrameCache