---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.TextureCache

---Singleton that handles the loading of textures.
---Once the texture is loaded, the next time it will return.
---A reference of the previously loaded texture reducing GPU & CPU memory.
---@class cc.TextureCache : cc.Ref
---@field cachedTextureInfo string Output to CCLOG the current contents of this TextureCache. This will attempt to calculate the size of each texture, and the total texture memory in use. <br><br>\since v1.0
---@field description string \js NA \lua NA
---@field etC1AlphaFileSuffix string 
local TextureCache = {}

---Returns a Texture2D object given an filename.
---If the filename was not previously loaded, it will create a new Texture2D.
---Object and it will return it. It will use the filename as a key.
---Otherwise it will return a reference of a previously loaded image.
---Supported image extensions: .png, .bmp, .jpeg, .pvr.
---@param filepath string # The file path.
---@return cc.Texture2D
---
---Returns a Texture2D object given an Image.
---If the image was not previously loaded, it will create a new Texture2D object and it will return it.
---Otherwise it will return a reference of a previously loaded image.
---\param key The "key" parameter will be used as the "key" for the cache.
---If "key" is nil, then a new texture will be created each time.
---@overload fun(self: cc.TextureCache, image: cc.Image, key: string): cc.Texture2D
function TextureCache:addImage(filepath) end

---Returns a Texture2D object given a file image.
---If the file image was not previously loaded, it will create a new Texture2D object and it will return it.
---Otherwise it will load a texture in a new thread, and when the image is loaded, the callback will be called with the Texture2D as a parameter.
---The callback will be called from the main thread, so it is safe to create any cocos2d object from the callback.
---Supported image extensions: .png, .jpg
---@param filepath string # The file path.
---@param callback fun(arg1: cc.Texture2D) # A callback function would be invoked after the image is loaded.
---\since v0.8
---@overload fun(self: cc.TextureCache, path: string, callback: fun(arg1: cc.Texture2D), callbackKey: string)
function TextureCache:addImageAsync(filepath, callback) end

---Output to CCLOG the current contents of this TextureCache.
---This will attempt to calculate the size of each texture, and the total texture memory in use.
---
---\since v1.0
---@return string
function TextureCache:getCachedTextureInfo() end

---\js NA
---\lua NA
---@return string
function TextureCache:getDescription() end

---@return string
function TextureCache.getETC1AlphaFileSuffix() end

---Get the file path of the texture
---
---@param texture cc.Texture2D # A Texture2D object pointer.
---
---@return string # The full path of the file.
function TextureCache:getTextureFilePath(texture) end

---Returns an already created texture. Returns nil if the texture doesn't exist.
---@param key string # It's the related/absolute path of the file image.
---\since v0.99.5
---@return cc.Texture2D
function TextureCache:getTextureForKey(key) end

---\js ctor
---@return cc.TextureCache
function TextureCache.new() end

---Reload texture from the image file.
---If the file image hasn't loaded before, load it.
---Otherwise the texture will be reloaded from the file image.
---@param fileName string # It's the related/absolute path of the file image.
---@return boolean # True if the reloading is succeed, otherwise return false.
function TextureCache:reloadTexture(fileName) end

---Purges the dictionary of loaded textures.
---Call this method if you receive the "Memory Warning".
---In the short term: it will free some resources preventing your app from being killed.
---In the medium term: it will allocate more resources.
---In the long term: it will be the same.
function TextureCache:removeAllTextures() end

---Deletes a texture from the cache given a texture.
---@param texture cc.Texture2D
function TextureCache:removeTexture(texture) end

---Deletes a texture from the cache given a its key name.
---@param key string # It's the related/absolute path of the file image.
---\since v0.99.4
function TextureCache:removeTextureForKey(key) end

---Removes unused textures.
---Textures that have a retain count of 1 will be deleted.
---It is convenient to call this method after when starting a new Scene.
---\since v0.8
function TextureCache:removeUnusedTextures() end

---Reload texture from a new file.
---This function is mainly for editor, won't suggest use it in game for performance reason.
---
---@param srcName string # Original texture file name.
---@param dstName string # New texture file name.
---
---\since v3.10
function TextureCache:renameTextureWithKey(srcName, dstName) end

---@param suffix string
function TextureCache.setETC1AlphaFileSuffix(suffix) end

---Unbind all bound image asynchronous load callbacks.
---\since v3.1
function TextureCache:unbindAllImageAsync() end

---Unbind a specified bound image asynchronous callback.
---In the case an object who was bound to an image asynchronous callback was destroyed before the callback is invoked,
---the object always need to unbind this callback manually.
---@param filename string # It's the related/absolute path of the file image.
---\since v3.1
function TextureCache:unbindImageAsync(filename) end

---Called by director, please do not called outside.
function TextureCache:waitForQuit() end

return TextureCache