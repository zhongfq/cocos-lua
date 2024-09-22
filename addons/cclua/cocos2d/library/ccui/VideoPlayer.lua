---AUTO GENERATED, DO NOT MODIFY!
---@meta ccui.VideoPlayer

---\class VideoPlayer
---Displays a video file.
---
---\note VideoPlayer displays a video file base on system widget.
---It's mean VideoPlayer displays a video file above all graphical elements of cocos2d-x.
---\js NA
---@class ccui.VideoPlayer : ccui.Widget
---@field fileName string Get the local video file name. <br><br>\return The video file name.
---@field fullScreenEnabled boolean Indicates whether the video player is in full-screen mode. <br><br>\return True if the video player is in full-screen mode, false otherwise.
---@field keepAspectRatioEnabled boolean Indicates whether the video player keep aspect ratio when displaying the video.
---@field looping boolean Checks whether the VideoPlayer is set with looping mode. <br><br>\return true if the videoplayer is set to loop, false otherwise.
---@field playing boolean Checks whether the VideoPlayer is playing. <br><br>\return True if currently playing, false otherwise.
---@field url string Get the URL of remoting video source. <br><br>\return A remoting URL address.
---@field userInputEnabled boolean Checks whether the VideoPlayer is set to listen user input to resume and pause the video <br><br>\return true if the videoplayer user input is set, false otherwise.
local VideoPlayer = {}

---Register a callback to be invoked when the video state is updated.
---
---@param callback ccui.VideoPlayer.ccVideoPlayerCallback # The callback that will be run.
function VideoPlayer:addEventListener(callback) end

---Static create method for instancing a VideoPlayer.
---@return ccui.VideoPlayer
function VideoPlayer.create() end

---Get the local video file name.
---
---@return string # The video file name.
function VideoPlayer:getFileName() end

---Get the URL of remoting video source.
---
---@return string # A remoting URL address.
function VideoPlayer:getURL() end

---Indicates whether the video player is in full-screen mode.
---
---@return boolean # True if the video player is in full-screen mode, false otherwise.
function VideoPlayer:isFullScreenEnabled() end

---Indicates whether the video player keep aspect ratio when displaying the video.
---@return boolean
function VideoPlayer:isKeepAspectRatioEnabled() end

---Checks whether the VideoPlayer is set with looping mode.
---
---@return boolean # true if the videoplayer is set to loop, false otherwise.
function VideoPlayer:isLooping() end

---Checks whether the VideoPlayer is playing.
---
---@return boolean # True if currently playing, false otherwise.
function VideoPlayer:isPlaying() end

---Checks whether the VideoPlayer is set to listen user input to resume and pause the video
---
---@return boolean # true if the videoplayer user input is set, false otherwise.
function VideoPlayer:isUserInputEnabled() end

---@return ccui.VideoPlayer
function VideoPlayer.new() end

---A function which will be called when video is playing.
---
---@param event integer # @see VideoPlayer::EventType.
function VideoPlayer:onPlayEvent(event) end

---Starts playback.
function VideoPlayer:play() end

---Seeks to specified time position.
---
---@param sec number # The offset in seconds from the start to seek to.
function VideoPlayer:seekTo(sec) end

---Sets a file path as a video source for VideoPlayer.
---@param videoPath string
function VideoPlayer:setFileName(videoPath) end

---Causes the video player to enter or exit full-screen mode.
---
---@param fullscreen boolean # Specify true to enter full-screen mode or false to exit full-screen mode.
function VideoPlayer:setFullScreenEnabled(fullscreen) end

---Causes the video player to keep aspect ratio or no when displaying the video.
---
---@param enable boolean # Specify true to keep aspect ratio or false to scale the video until 
---both dimensions fit the visible bounds of the view exactly.
function VideoPlayer:setKeepAspectRatioEnabled(enable) end

---Set if playback is done in loop mode
---
---@param looping boolean # the video will or not automatically restart at the end
function VideoPlayer:setLooping(looping) end

---Set the style of the player
---
---@param style ccui.VideoPlayer.StyleType # The corresponding style
function VideoPlayer:setStyle(style) end

---Sets a URL as a video source for VideoPlayer.
---@param _videoURL string
function VideoPlayer:setURL(_videoURL) end

---Set if the player will enable user input for basic pause and resume of video
---
---@param enableInput boolean # If true, input will be handled for basic functionality (pause/resume)
function VideoPlayer:setUserInputEnabled(enableInput) end

---Stops playback.
function VideoPlayer:stop() end

return VideoPlayer