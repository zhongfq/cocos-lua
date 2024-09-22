---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.EventListenerTouchOneByOne

---\class EventListenerTouchOneByOne
---Single touch event listener.
---\js cc._EventListenerTouchOneByOne
---@class cc.EventListenerTouchOneByOne : cc.EventListener
---@field swallowTouches boolean Is swall touches or not. <br><br>\return True if needs to swall touches.
---@field onTouchBegan cc.EventListenerTouchOneByOne.ccTouchBeganCallback
---@field onTouchMoved cc.EventListenerTouchOneByOne.ccTouchCallback
---@field onTouchEnded cc.EventListenerTouchOneByOne.ccTouchCallback
---@field onTouchCancelled cc.EventListenerTouchOneByOne.ccTouchCallback
---@field LISTENER_ID string
local EventListenerTouchOneByOne = {}

---Create a one by one touch event listener.
---@return cc.EventListenerTouchOneByOne
function EventListenerTouchOneByOne.create() end

---Is swall touches or not.
---
---@return boolean # True if needs to swall touches.
function EventListenerTouchOneByOne:isSwallowTouches() end

---@return cc.EventListenerTouchOneByOne
function EventListenerTouchOneByOne.new() end

---Whether or not to swall touches.
---
---@param needSwallow boolean # True if needs to swall touches.
function EventListenerTouchOneByOne:setSwallowTouches(needSwallow) end

return EventListenerTouchOneByOne