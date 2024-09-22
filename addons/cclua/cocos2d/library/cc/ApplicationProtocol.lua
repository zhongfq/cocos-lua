---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.ApplicationProtocol

---\addtogroup platform
---\{
---@class cc.ApplicationProtocol 
---@field currentLanguage cc.LanguageType Get current language config. \return Current language config. \js NA \lua NA
---@field currentLanguageCode string Get current language iso 639-1 code. \return Current language iso 639-1 code. \js NA \lua NA
---@field targetPlatform cc.ApplicationProtocol.Platform Get target platform. \js NA \lua NA
---@field version string Get application version. \js NA \lua NA
local ApplicationProtocol = {}

---@return any
function ApplicationProtocol:__gc() end

---This function will be called when the application enters background.
---\js NA
---\lua NA
function ApplicationProtocol:applicationDidEnterBackground() end

---Implement Director and Scene init code here.
---@return boolean # true    Initialize success, app continue.
---\return false   Initialize failed, app terminate.
---\js NA
---\lua NA
function ApplicationProtocol:applicationDidFinishLaunching() end

---This function will be called when the application enters foreground.
---\js NA
---\lua NA
function ApplicationProtocol:applicationWillEnterForeground() end

---Get current language config.
---@return cc.LanguageType # Current language config.
---\js NA
---\lua NA
function ApplicationProtocol:getCurrentLanguage() end

---Get current language iso 639-1 code.
---@return string # Current language iso 639-1 code.
---\js NA
---\lua NA
function ApplicationProtocol:getCurrentLanguageCode() end

---Get target platform.
---\js NA
---\lua NA
---@return cc.ApplicationProtocol.Platform
function ApplicationProtocol:getTargetPlatform() end

---Get application version.
---\js NA
---\lua NA
---@return string
function ApplicationProtocol:getVersion() end

---Subclass override the function to set OpenGL context attribution instead of use default value.
---And now can only set six attributions:redBits,greenBits,blueBits,alphaBits,depthBits,stencilBits.
---Default value are(5,6,5,0,16,0), usually use as follows:
---void AppDelegate::initGLContextAttrs(){
---GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};
---GLView::setGLContextAttrs(glContextAttrs);
---}
function ApplicationProtocol:initGLContextAttrs() end

---Open url in default browser.
---\param String with url to open.
---@return boolean # True if the resource located by the URL was successfully opened; otherwise false.
---\js NA
---\lua NA
---@param url string
function ApplicationProtocol:openURL(url) end

---Callback by Director for limit FPS.
---@param interval number # The time, expressed in seconds, between current frame and next.
---\js NA
---\lua NA
function ApplicationProtocol:setAnimationInterval(interval) end

return ApplicationProtocol