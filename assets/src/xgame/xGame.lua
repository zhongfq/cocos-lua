local class         = require "xgame.class"
local util          = require "xgame.util"
local timer         = require "xgame.timer"
local runtime       = require "xgame.runtime"
local MediatorMap   = require "xgame.MediatorMap"
local updater       = require "xgame.updater"
local Stage         = require "xgame.ui.Stage"
local SceneStack    = require "xgame.private.SceneStack"
local Event         = require "xgame.event.Event"
local Dispatcher    = require "xgame.event.Dispatcher"
local fileloader    = require "xgame.loader.fileloader"
local LoadQueue     = require "xgame.loader.LoadQueue"
local window        = require "kernel.window"
local Director      = require "cc.Director"

local director = Director.instance
local trace = util.trace("[xGame]")

xGame = class("xGame", Dispatcher)

function xGame:ctor()
    self.stage = Stage.new()
    self._mediatorMap = MediatorMap.new(self.stage)
    self._sceneStack = SceneStack.new(self.stage)
    self:_initTimer()
    self:_initRuntimeEvents()

    director.runningScene:addChild(self.stage.cobj)
    fileloader.addModule(updater.LOCAL_MANIFEST_PATH, updater.REMOTE_MANIFEST_PATH)
end

function xGame:capture(node)
    trace("lua mem: %fM", collectgarbage("count") / 1024)
end

function xGame:gc()
    collectgarbage("collect")
end

function xGame:memstat()
end

-- scene api
function xGame:_loadAssets(func, cls, ...)
    local queue = LoadQueue.new(cls.assets(...))
    if queue.totalCount > 0 then
        local args = {...}
        queue:addListener(Event.IOERROR, function ()
            self:dispatch(Event.LOADER_ERROR, queue)
        end)
        queue:addListener(Event.PROGRESS, function ()
            self:dispatch(Event.LOADER_UPDATE, queue)
        end)
        queue:addListener(Event.COMPLETE, function ()
            self:dispatch(Event.LOADER_COMPLETE, queue)
            func(self._sceneStack, cls, table.unpack(args))
        end)
        self:dispatch(Event.LOADER_START)
        queue:start()
    else
        func(self._sceneStack, cls, ...)
    end
end

function xGame:showWindow(cls, ...)
    self:_loadAssets(self._sceneStack.showWindow, cls, ...)
    self._sceneStack:showWindow(cls)
end

function xGame:startScene(cls, ...)
    self:_loadAssets(self._sceneStack.startScene, cls, ...)
end

function xGame:replaceScene(cls, ...)
    self:_loadAssets(self._sceneStack.replaceScene, cls, ...)
end

function xGame:popScene()
    self._sceneStack:popScene()
    self:delay(0.001, function ()
    end)
end

function xGame:popAll()
    self._sceneStack:popAll()
    self:delay(0.001, function ()
    end)
end

function xGame:topScene()
    return self._sceneStack:topScene()
end

--
-- timer api
--
function xGame:_initTimer()
    local inst = timer.new()
    self._timer = inst
    timer.schedule(0, function (dt)
        inst:update(dt)
    end)
end

function xGame:delay(time, func, ...)
    self._timer:delay(time, func, ...)
end

function xGame:delayWithTag(time, tag, func, ...)
    self._timer:delayWithTag(time, tag, func, ...)
end

function xGame:killDelay(tag)
    self._timer:killDelay(tag)
end

function xGame:schedule(interval, func, contextView)
    if contextView then
        local id
        assert(func)
        id = self._timer:schedule(interval, function ()
            if contextView.stage then
                func()
            else
                self:unschedule(id)
            end
        end)
        return id
    else
        return self._timer:schedule(interval, func)
    end
end

function xGame:unschedule(id)
    return self._timer:unschedule(id)
end

--
-- runtime event
--
function xGame:_initRuntimeEvents()
    local function listen(event)
        runtime.on(event, function (...)
            self:dispatch(event, ...)
        end)
    end
    listen('runtimeUpdate')
    listen('runtimeResize')
    listen('runtimePause')
    listen('runtimeResume')
end

--
-- runtime api
--
function xGame.Get:time()
    return runtime.time
end

function xGame.Get:os()
    return runtime.os
end

function xGame.Get:channel()
    return runtime.channel
end

function xGame.Get:version()
    return runtime.version
end

function xGame.Get:versionBuild()
    return runtime.versionBuild
end

function xGame:support(api)
    return runtime.support(api)
end

function xGame:openURL(url, ...)
    runtime.openURL(url, ...)
end

function xGame:canOpenURL(url)
    return runtime.canOpenURL(url)
end

--
-- window api
--
function xGame:getDesignSize()
    return window.getDesignSize()
end

function xGame:getVisibleBounds()
    return window.getVisibleBounds()
end

function xGame:getFrameSize()
    return window.getFrameSize()
end

xGame = xGame.new()