---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.AudioEngine

---\class AudioEngine
---
---Offers a interface to play audio.
---
---\note Make sure to call AudioEngine::end() when the audio engine is not needed anymore to release resources.
---\js NA
---@class cc.AudioEngine 
---@field defaultProfile cc.AudioProfile Gets the default profile of audio instances. <br><br>\return The default profile of audio instances.
---@field enabled boolean Check whether AudioEngine is enabled.
---@field maxAudioInstance integer Gets the maximum number of simultaneous audio instance of AudioEngine.
---@field playingAudioCount integer Gets playing audio count.
---@field INVALID_AUDIO_ID integer
---@field TIME_UNKNOWN number
local AudioEngine = {}

---@return any
function AudioEngine:__gc() end

---Release objects relating to AudioEngine.
---
---\warning It must be called before the application exit.
---\lua endToLua
function AudioEngine.end_() end

---Gets the current playback position of an audio instance.
---
---@param audioID integer # An audioID returned by the play2d function.
---@return number # The current playback position of an audio instance.
function AudioEngine.getCurrentTime(audioID) end

---Gets the default profile of audio instances.
---
---@return cc.AudioProfile # The default profile of audio instances.
function AudioEngine.getDefaultProfile() end

---Gets the duration of an audio instance.
---
---@param audioID integer # An audioID returned by the play2d function.
---@return number # The duration of an audio instance.
function AudioEngine.getDuration(audioID) end

---Gets the maximum number of simultaneous audio instance of AudioEngine.
---@return integer
function AudioEngine.getMaxAudioInstance() end

---Gets playing audio count.
---@return integer
function AudioEngine.getPlayingAudioCount() end

---Gets the audio profile by id of audio instance.
---
---@param audioID integer # An audioID returned by the play2d function.
---@return cc.AudioProfile # The audio profile.
---
---Gets an audio profile by name.
---
---\param profileName A name of audio profile.
---\return The audio profile.
---@overload fun(profileName: string): cc.AudioProfile
function AudioEngine.getProfile(audioID) end

---Returns the state of an audio instance.
---
---@param audioID integer # An audioID returned by the play2d function.
---@return cc.AudioEngine.AudioState # The status of an audio instance.
function AudioEngine.getState(audioID) end

---Gets the volume value of an audio instance.
---
---@param audioID integer # An audioID returned by the play2d function.
---@return number # Volume value (range from 0.0 to 1.0).
function AudioEngine.getVolume(audioID) end

---Check whether AudioEngine is enabled.
---@return boolean
function AudioEngine.isEnabled() end

---Checks whether an audio instance is loop.
---
---@param audioID integer # An audioID returned by the play2d function.
---@return boolean # Whether or not an audio instance is loop.
function AudioEngine.isLoop(audioID) end

---@return boolean
function AudioEngine.lazyInit() end

---Pause an audio instance.
---
---@param audioID integer # An audioID returned by the play2d function.
function AudioEngine.pause(audioID) end

---Pause all playing audio instances.
function AudioEngine.pauseAll() end

---Play 2d sound.
---
---@param filePath string # The path of an audio file.
---@param loop boolean # Whether audio instance loop or not.
---@param volume number # Volume value (range from 0.0 to 1.0).
---@param position number # The offset in seconds from the start.
---@param profile cc.AudioProfile # A profile for audio instance. When profile is not specified, default profile will be used.
---@return integer # An audio ID. It allows you to dynamically change the behavior of an audio instance on the fly.
---
---\see `AudioProfile`
---@overload fun(filePath: string): integer
---@overload fun(filePath: string, loop: boolean): integer
---@overload fun(filePath: string, loop: boolean, volume: number): integer
---@overload fun(filePath: string, loop: boolean, volume: number, position: number): integer
function AudioEngine.play2d(filePath, loop, volume, position, profile) end

---Preload audio file.
---@param filePath string # The file path of an audio.
---
---Preload audio file.
---\param filePath The file path of an audio.
---\param callback A callback which will be called after loading is finished.
---@overload fun(filePath: string, callback: fun(arg1: boolean))
function AudioEngine.preload(filePath) end

---Resume an audio instance.
---
---@param audioID integer # An audioID returned by the play2d function.
function AudioEngine.resume(audioID) end

---Resume all suspended audio instances.
function AudioEngine.resumeAll() end

---Sets the current playback position of an audio instance.
---
---@param audioID integer # An audioID returned by the play2d function.
---@param sec number # The offset in seconds from the start to seek to.
---@return boolean # 
function AudioEngine.setCurrentTime(audioID, sec) end

---Whether to enable playing audios
---\note If it's disabled, current playing audios will be stopped and the later 'preload', 'play2d' methods will take no effects.
---@param isEnabled boolean
function AudioEngine.setEnabled(isEnabled) end

---Register a callback to be invoked when an audio instance has completed playing.
---
---@param audioID integer # An audioID returned by the play2d function.
---@param callback fun(arg1: integer, arg2: string) # 
function AudioEngine.setFinishCallback(audioID, callback) end

---Sets whether an audio instance loop or not.
---
---@param audioID integer # An audioID returned by the play2d function.
---@param loop boolean # Whether audio instance loop or not.
function AudioEngine.setLoop(audioID, loop) end

---Sets the maximum number of simultaneous audio instance for AudioEngine.
---
---@param maxInstances integer # The maximum number of simultaneous audio instance.
---@return boolean
function AudioEngine.setMaxAudioInstance(maxInstances) end

---Sets volume for an audio instance.
---
---@param audioID integer # An audioID returned by the play2d function.
---@param volume number # Volume value (range from 0.0 to 1.0).
function AudioEngine.setVolume(audioID, volume) end

---Stop an audio instance.
---
---@param audioID integer # An audioID returned by the play2d function.
function AudioEngine.stop(audioID) end

---Stop all audio instances.
function AudioEngine.stopAll() end

---Uncache the audio data from internal buffer.
---AudioEngine cache audio data on ios,mac, and win32 platform.
---
---\warning This can lead to stop related audio first.
---@param filePath string # Audio file path.
function AudioEngine.uncache(filePath) end

---Uncache all audio data from internal buffer.
---
---\warning All audio will be stopped first.
function AudioEngine.uncacheAll() end

return AudioEngine