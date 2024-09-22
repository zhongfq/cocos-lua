---AUTO GENERATED, DO NOT MODIFY!
---@meta ccs.ComAudio

---
---@class ccs.ComAudio : cc.Component
---@field backgroundMusicPlaying boolean 
---@field backgroundMusicVolume number 
---@field effectsVolume number 
---@field file string 
---@field loop boolean 
---@field COMPONENT_NAME string
local ComAudio = {}

---@param cls string
---@return any
function ComAudio:as(cls) end

---@return ccs.ComAudio
function ComAudio.create() end

---@return cc.Ref
function ComAudio.createInstance() end

---\lua endToLua
function ComAudio:end_() end

---@return number
function ComAudio:getBackgroundMusicVolume() end

---@return number
function ComAudio:getEffectsVolume() end

---@return string
function ComAudio:getFile() end

---@return boolean
function ComAudio:isBackgroundMusicPlaying() end

---@return boolean
function ComAudio:isLoop() end

---\js ctor
---@return ccs.ComAudio
function ComAudio.new() end

function ComAudio:pauseAllEffects() end

function ComAudio:pauseBackgroundMusic() end

---@param nSoundId integer
function ComAudio:pauseEffect(nSoundId) end

---@param pszFilePath string
---@param bLoop boolean
---@overload fun(self: ccs.ComAudio, pszFilePath: string)
---@overload fun(self: ccs.ComAudio)
function ComAudio:playBackgroundMusic(pszFilePath, bLoop) end

---@param pszFilePath string
---@param bLoop boolean
---@return integer
---@overload fun(self: ccs.ComAudio, pszFilePath: string): integer
---@overload fun(self: ccs.ComAudio): integer
function ComAudio:playEffect(pszFilePath, bLoop) end

---@param pszFilePath string
function ComAudio:preloadBackgroundMusic(pszFilePath) end

---@param pszFilePath string
function ComAudio:preloadEffect(pszFilePath) end

function ComAudio:resumeAllEffects() end

function ComAudio:resumeBackgroundMusic() end

---@param nSoundId integer
function ComAudio:resumeEffect(nSoundId) end

function ComAudio:rewindBackgroundMusic() end

---@param volume number
function ComAudio:setBackgroundMusicVolume(volume) end

---@param volume number
function ComAudio:setEffectsVolume(volume) end

---@param pszFilePath string
function ComAudio:setFile(pszFilePath) end

---@param bLoop boolean
function ComAudio:setLoop(bLoop) end

---\{
---\name implement Playable Protocol
function ComAudio:start() end

function ComAudio:stop() end

function ComAudio:stopAllEffects() end

---@param bReleaseData boolean
---@overload fun(self: ccs.ComAudio)
function ComAudio:stopBackgroundMusic(bReleaseData) end

---@param nSoundId integer
function ComAudio:stopEffect(nSoundId) end

---@param pszFilePath string
function ComAudio:unloadEffect(pszFilePath) end

---@return boolean
function ComAudio:willPlayBackgroundMusic() end

return ComAudio