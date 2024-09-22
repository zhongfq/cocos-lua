---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.AnimationCache

---Singleton that manages the Animations.
---It saves in a cache the animations. You should use this class if you want to save your animations in a cache.
---
---Before v0.99.5, the recommend way was to save them on the Sprite. Since v0.99.5, you should use this class instead.
---
---\since v0.99.5
---\js cc.animationCache
---@class cc.AnimationCache : cc.Ref
---@field instance cc.AnimationCache Returns the shared instance of the Animation cache  \js NA
local AnimationCache = {}

---Adds a Animation with a name.
---
---@param animation cc.Animation # An animation.
---@param name string # The name of animation.
function AnimationCache:addAnimation(animation, name) end

---Adds an animation from an NSDictionary.
---Make sure that the frames were previously loaded in the SpriteFrameCache.
---@param dictionary any # An NSDictionary.
---@param plist string # The path of the relative file,it use to find the plist path for load SpriteFrames.
---\since v1.1
---\js NA
function AnimationCache:addAnimationsWithDictionary(dictionary, plist) end

---Adds an animation from a plist file.
---Make sure that the frames were previously loaded in the SpriteFrameCache.
---\since v1.1
---\js addAnimations
---\lua addAnimations
---@param plist string # An animation from a plist file.
function AnimationCache:addAnimationsWithFile(plist) end

---Purges the cache. It releases all the Animation objects and the shared instance.
---\js NA
function AnimationCache.destroyInstance() end

---Returns a Animation that was previously added.
---If the name is not found it will return nil.
---You should retain the returned copy if you are going to use it.
---
---@return cc.Animation # A Animation that was previously added. If the name is not found it will return nil.
---@param name string
function AnimationCache:getAnimation(name) end

---Returns the shared instance of the Animation cache 
---\js NA
---@return cc.AnimationCache
function AnimationCache.getInstance() end

---@return boolean
function AnimationCache:init() end

---\js ctor
---@return cc.AnimationCache
function AnimationCache.new() end

---Deletes a Animation from the cache.
---
---@param name string # The name of animation.
function AnimationCache:removeAnimation(name) end

return AnimationCache