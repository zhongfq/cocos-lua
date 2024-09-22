---AUTO GENERATED, DO NOT MODIFY!
---@meta fgui.GRoot

---
---@class fgui.GRoot : fgui.GComponent
---@field UIRoot fgui.GRoot 
---@field inputProcessor fgui.InputProcessor 
---@field instance fgui.GRoot 
---@field modalLayer fgui.GGraph 
---@field modalWaiting boolean 
---@field modalWaitingPane fgui.GObject 
---@field soundEnabled boolean 
---@field soundVolumeScale number 
---@field topWindow fgui.Window 
---@field touchTarget fgui.GObject 
---@field contentScaleLevel integer
local GRoot = {}

---@param win fgui.Window
function GRoot:bringToFront(win) end

function GRoot:closeAllExceptModals() end

function GRoot:closeAllWindows() end

function GRoot:closeModalWait() end

---@param scene cc.Scene
---@param zOrder integer
---@return fgui.GRoot
---@overload fun(scene: cc.Scene): fgui.GRoot
function GRoot.create(scene, zOrder) end

---@return fgui.InputProcessor
function GRoot:getInputProcessor() end

---@return fgui.GRoot
function GRoot.getInstance() end

---@return fgui.GGraph
function GRoot:getModalLayer() end

---@return fgui.GObject
function GRoot:getModalWaitingPane() end

---@param popup fgui.GObject
---@param target fgui.GObject
---@param dir fgui.PopupDirection
---@return cc.Vec2
function GRoot:getPoupPosition(popup, target, dir) end

---@return number
function GRoot:getSoundVolumeScale() end

---@return fgui.Window
function GRoot:getTopWindow() end

---@param touchId integer
---@return cc.Vec2
function GRoot:getTouchPosition(touchId) end

---@return fgui.GObject
function GRoot:getTouchTarget() end

---@return boolean
function GRoot:hasAnyPopup() end

---@return boolean
function GRoot:hasModalWindow() end

---@overload fun(self: fgui.GRoot, popup: fgui.GObject)
function GRoot:hidePopup() end

function GRoot:hideTooltips() end

---@param win fgui.Window
function GRoot:hideWindow(win) end

---@param win fgui.Window
function GRoot:hideWindowImmediately(win) end

---@return boolean
function GRoot:isModalWaiting() end

---@return boolean
function GRoot:isSoundEnabled() end

---@return fgui.GRoot
function GRoot.new() end

---@param url string
---@param volumeScale number
---@overload fun(self: fgui.GRoot, url: string)
function GRoot:playSound(url, volumeScale) end

---@param pt cc.Vec2
---@return cc.Vec2
---@overload fun(self: fgui.GRoot, x: number, y: number): number, number
function GRoot:rootToWorld(pt) end

function GRoot:setNotAsUIRoot() end

---@param value boolean
function GRoot:setSoundEnabled(value) end

---@param value number
function GRoot:setSoundVolumeScale(value) end

function GRoot:showModalWait() end

---@param popup fgui.GObject
---@overload fun(self: fgui.GRoot, popup: fgui.GObject, target: fgui.GObject, dir: fgui.PopupDirection)
function GRoot:showPopup(popup) end

---@param msg string
function GRoot:showTooltips(msg) end

---@param tooltipWin fgui.GObject
function GRoot:showTooltipsWin(tooltipWin) end

---@param win fgui.Window
function GRoot:showWindow(win) end

---@param popup fgui.GObject
---@overload fun(self: fgui.GRoot, popup: fgui.GObject, target: fgui.GObject, dir: fgui.PopupDirection)
function GRoot:togglePopup(popup) end

---@param pt cc.Vec2
---@return cc.Vec2
---@overload fun(self: fgui.GRoot, x: number, y: number): number, number
function GRoot:worldToRoot(pt) end

return GRoot