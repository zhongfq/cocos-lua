---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.Scheduler

---Scheduler is responsible for triggering the scheduled callbacks.
---You should not use system timer for your game logic. Instead, use this class.
---
---There are 2 different types of callbacks (selectors):
---
---- update selector: the 'update' selector will be called every frame. You can customize the priority.
---- custom selector: A custom selector will be called every frame, or with a custom interval of time
---
---The 'custom selectors' should be avoided when possible. It is faster, and consumes less memory to use the 'update selector'.
---@class cc.Scheduler : cc.Ref
---@field timeScale number Gets the time scale of schedule callbacks. \see Scheduler::setTimeScale()
---@field PRIORITY_NON_SYSTEM_MIN integer
---@field PRIORITY_SYSTEM integer
local Scheduler = {}

---Gets the time scale of schedule callbacks.
---\see Scheduler::setTimeScale()
---@return number
function Scheduler:getTimeScale() end

---Checks whether a callback associated with 'key' and 'target' is scheduled.
---@param key string # The key to identify the callback function, because there is not way to identify a std::function<>.
---@param target any # The target of the callback.
---@return boolean # True if the specified callback is invoked, false if not.
---\since v3.0.0
function Scheduler:isScheduled(key, target) end

---Returns whether or not the target is paused.
---@param target any # The target to be checked.
---@return boolean # True if the target is paused, false if not.
---\since v1.0.0
---\lua NA
function Scheduler:isTargetPaused(target) end

---Constructor
---
---\js ctor
---@return cc.Scheduler
function Scheduler.new() end

---Pause all selectors from all targets.
---You should NEVER call this method, unless you know what you are doing.
---\since v2.0.0
---@return any[]
function Scheduler:pauseAllTargets() end

---Pause all selectors from all targets with a minimum priority.
---You should only call this with PRIORITY_NON_SYSTEM_MIN or higher.
---@param minPriority integer # The minimum priority of selector to be paused. Which means, all selectors which
---priority is higher than minPriority will be paused.
---\since v2.0.0
---@return any[]
function Scheduler:pauseAllTargetsWithMinPriority(minPriority) end

---Pauses the target.
---All scheduled selectors/update for a given target won't be 'ticked' until the target is resumed.
---If the target is not present, nothing happens.
---@param target any # The target to be paused.
---\since v0.99.3
function Scheduler:pauseTarget(target) end

---Remove all pending functions queued to be performed with Scheduler::performFunctionInCocosThread
---Functions unscheduled in this manner will not be executed
---This function is thread safe
---\since v3.14
---\js NA
function Scheduler:removeAllFunctionsToBePerformedInCocosThread() end

---Resumes the target.
---The 'target' will be unpaused, so all schedule selectors/update will be 'ticked' again.
---If the target is not present, nothing happens.
---@param target any # The target to be resumed.
---\since v0.99.3
function Scheduler:resumeTarget(target) end

---Resume selectors on a set of targets.
---This can be useful for undoing a call to pauseAllSelectors.
---@param targetsToResume any[] # The set of targets to be resumed.
---\since v2.0.0
function Scheduler:resumeTargets(targetsToResume) end

---The scheduled method will be called every 'interval' seconds.
---If paused is true, then it won't be called until it is resumed.
---If 'interval' is 0, it will be called every frame, but if so, it's recommended to use 'scheduleUpdate' instead.
---If the 'callback' is already scheduled, then only the interval parameter will be updated without re-scheduling it again.
---repeat let the action be repeated repeat + 1 times, use CC_REPEAT_FOREVER to let the action run continuously
---delay is the amount of time the action will wait before it'll start.
---@param callback cc.ccSchedulerFunc # The callback function.
---@param target any # The target of the callback function.
---@param interval number # The interval to schedule the callback. If the value is 0, then the callback will be scheduled every frame.
---\param repeat repeat+1 times to schedule the callback.
---@param delay number # Schedule call back after `delay` seconds. If the value is not 0, the first schedule will happen after `delay` seconds.
---But it will only affect first schedule. After first schedule, the delay time is determined by `interval`.
---@param paused boolean # Whether or not to pause the schedule.
---@param key string # The key to identify the callback function, because there is not way to identify a std::function<>.
---\since v3.0
---@param repeat_ integer
---
---The scheduled method will be called every 'interval' seconds for ever.
---\param callback The callback function.
---\param target The target of the callback function.
---\param interval The interval to schedule the callback. If the value is 0, then the callback will be scheduled every frame.
---\param paused Whether or not to pause the schedule.
---\param key The key to identify the callback function, because there is not way to identify a std::function<>.
---\since v3.0
---@overload fun(self: cc.Scheduler, callback: cc.ccSchedulerFunc, target: any, interval: number, paused: boolean, key: string)
function Scheduler:schedule(callback, target, interval, repeat_, delay, paused, key) end

---@return any
function Scheduler:scheduleUpdate() end

---Modifies the time of all scheduled callbacks.
---You can use this property to create a 'slow motion' or 'fast forward' effect.
---Default is 1.0. To create a 'slow motion' effect, use values below 1.0.
---To create a 'fast forward' effect, use values higher than 1.0.
---\since v0.8
---\warning It will affect EVERY scheduled selector / action.
---@param timeScale number
function Scheduler:setTimeScale(timeScale) end

---Unschedules a callback for a key and a given target.
---If you want to unschedule the 'callbackPerFrame', use unscheduleUpdate.
---@param key string # The key to identify the callback function, because there is not way to identify a std::function<>.
---@param target any # The target to be unscheduled.
---\since v3.0
function Scheduler:unschedule(key, target) end

---Unschedules all selectors from all targets.
---You should NEVER call this method, unless you know what you are doing.
---\since v0.99.3
function Scheduler:unscheduleAll() end

---Unschedules all selectors for a given target.
---This also includes the "update" selector.
---@param target any # The target to be unscheduled.
---\since v0.99.3
---\lua NA
function Scheduler:unscheduleAllForTarget(target) end

---Unschedules all selectors from all targets with a minimum priority.
---You should only call this with `PRIORITY_NON_SYSTEM_MIN` or higher.
---@param minPriority integer # The minimum priority of selector to be unscheduled. Which means, all selectors which
---priority is higher than minPriority will be unscheduled.
---\since v2.0.0
function Scheduler:unscheduleAllWithMinPriority(minPriority) end

---Unschedules the update selector for a given target
---@param target any # The target to be unscheduled.
---\since v0.99.3
function Scheduler:unscheduleUpdate(target) end

---'update' the scheduler.
---You should NEVER call this method, unless you know what you are doing.
---\lua NA
---@param dt number
function Scheduler:update(dt) end

return Scheduler