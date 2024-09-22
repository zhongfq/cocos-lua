---AUTO GENERATED, DO NOT MODIFY!
---@meta cclua.runtime

---
---@class cclua.runtime 
---@field actionManager cc.ActionManager 
---@field appBuild string 
---@field appName string 
---@field appVersion string 
---@field args string[] 
---@field audioSessionCatalog string 
---@field channel string 
---@field cocosVersion integer 
---@field debug boolean 
---@field deviceInfo string 
---@field displayStats boolean 
---@field eventDispatcher cc.EventDispatcher 
---@field fileUtils cc.FileUtils 
---@field frameRate integer 
---@field language string 
---@field logPath string 
---@field manifestVersion string 
---@field maxFrameRate integer 
---@field networkStatus string 
---@field os string 
---@field packageName string 
---@field paste string 
---@field programCache ccb.ProgramCache 
---@field restarting boolean 
---@field runningScene cc.Scene 
---@field sampleCount integer 
---@field scheduler cc.Scheduler 
---@field spriteFrameCache cc.SpriteFrameCache 
---@field textureCache cc.TextureCache 
---@field time number 
---@field version string 
local runtime = {}

---@return any
function runtime:__gc() end

---@param title string
---@param message string
---@param ok string
---@param no string
---@param callback fun(arg1: boolean)
function runtime.alert(title, message, ok, no, callback) end

---@param uri string
---@return boolean
function runtime.canOpenURL(uri) end

---@param node cc.Node
---@param width number
---@param height number
---@param scale number
---@param format ccb.PixelFormat
---@param depthStencilFormat ccb.PixelFormat
---@return cc.Sprite
---@overload fun(node: cc.Node, width: number, height: number): cc.Sprite
---@overload fun(node: cc.Node, width: number, height: number, scale: number): cc.Sprite
---@overload fun(node: cc.Node, width: number, height: number, scale: number, format: ccb.PixelFormat): cc.Sprite
function runtime.capture(node, width, height, scale, format, depthStencilFormat) end

function runtime.clearStorage() end

function runtime.disableReport() end

function runtime.exit() end

function runtime.gc() end

---@return cc.ActionManager
function runtime.getActionManager() end

---@return string
function runtime.getAppBuild() end

---@return string
function runtime.getAppName() end

---@return string
function runtime.getAppVersion() end

---@return string[]
function runtime.getArgs() end

---@return string
function runtime.getAudioSessionCatalog() end

---@return string
function runtime.getChannel() end

---@return integer
function runtime.getCocosVersion() end

---@return string
function runtime.getDeviceInfo() end

---@param key string
---@return string
function runtime.getEnv(key) end

---@return cc.EventDispatcher
function runtime.getEventDispatcher() end

---@return cc.FileUtils
function runtime.getFileUtils() end

---@return integer
function runtime.getFrameRate() end

---@return string
function runtime.getLanguage() end

---@return string
function runtime.getLogPath() end

---@return string
function runtime.getManifestVersion() end

---@return integer
function runtime.getMaxFrameRate() end

---@return string
function runtime.getNetworkStatus() end

---@return string
function runtime.getOS() end

---@return string
function runtime.getPackageName() end

---@return string
function runtime.getPaste() end

---@param permission string
---@return string
function runtime.getPermission(permission) end

---@return ccb.ProgramCache
function runtime.getProgramCache() end

---@return cc.Scene
function runtime.getRunningScene() end

---@return integer
function runtime.getSampleCount() end

---@return cc.Scheduler
function runtime.getScheduler() end

---@return cc.SpriteFrameCache
function runtime.getSpriteFrameCache() end

---@return cc.TextureCache
function runtime.getTextureCache() end

---@return number
function runtime.getTime() end

---@return string
function runtime.getVersion() end

---@param api string
---@return boolean
function runtime.hasFeature(api) end

---@param path string
function runtime.installAPK(path) end

---@return boolean
function runtime.isDebug() end

---@return boolean
function runtime.isDisplayStats() end

---@return boolean
function runtime.isRestarting() end

---@param scriptPath string
---@return boolean
function runtime.launch(scriptPath) end

---@param name string
---@return any
---@overload fun(name: string, feature: string): any
function runtime.load(name) end

---@param uri string
---@param callback fun(arg1: boolean)
---@overload fun(uri: string)
function runtime.openURL(uri, callback) end

function runtime.popScene() end

function runtime.popToRootScene() end

function runtime.printFeatures() end

function runtime.purgeCachedData() end

---@param scene cc.Scene
function runtime.pushScene(scene) end

---@param scene cc.Scene
function runtime.replaceScene(scene) end

---@param permission string
---@param callback fun(arg1: string)
function runtime.requestPermission(permission, callback) end

---@return boolean
function runtime.restart() end

---@param catalog string
function runtime.setAudioSessionCatalog(catalog) end

---@param dispatcher cclua.Callback
function runtime.setDispatcher(dispatcher) end

---@param displayStats boolean
function runtime.setDisplayStats(displayStats) end

---@param key string
---@param value string
---@param save boolean
---@overload fun(key: string, value: string)
function runtime.setEnv(key, value, save) end

---@param frameRate integer
function runtime.setFrameRate(frameRate) end

---@param path string
function runtime.setLogPath(path) end

---@param version string
function runtime.setManifestVersion(version) end

---@param text string
function runtime.setPaste(text) end

---@param samples integer
function runtime.setSampleCount(samples) end

function runtime.showLog() end

function runtime.testCrash() end

return runtime