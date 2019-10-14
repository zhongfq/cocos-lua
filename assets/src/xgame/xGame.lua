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
local window        = require "xgame.window"
local Director      = require "cc.Director"

local director = Director.instance
local trace = util.trace("[xGame]")

xGame = class("xGame", Dispatcher)

function xGame:ctor()
    self.stage = Stage.new()
    self._mediatorMap = MediatorMap.new(self.stage)
    self._sceneStack = SceneStack.new(self.stage)
    self._services = {}
    self._timer = false
    self:_initTimer()
    self:_initRuntimeEvents()

    director.runningScene:addChild(self.stage.cobj)
    fileloader.addModule(updater.LOCAL_MANIFEST_PATH, updater.REMOTE_MANIFEST_PATH)
end

function xGame:capture(node)
end

function xGame:gc()
    runtime.gc()
end

-- services
function xGame:newService(name, cls)
    assert(not self[name], 'name conflict: ' .. name)
    local serviceClass = require(cls)
    local svr = serviceClass.new(name)
    self[name] = svr
    self._services[name] = svr
    serviceClass['fullClassName'] = cls
    trace('create service: %s(%s)', name, cls)
end

function xGame:restart(cls, ...)
    self._timer:clear()
    self:popAll()

    local defs = {}
    for name, svr in pairs(self._services) do
        assert(self[name] == svr, name)
        svr:dispose()
        assert(svr.dispose == true, name)
        defs[name] = svr.class['fullClassName']
        self._services[name] = nil
        self[name] = nil
    end

    for name, serviceClass in pairs(defs) do
        self:newService(name, serviceClass)
    end

    trace('restart xGame: %s', cls.classname)

    self:startScene(cls, ...)
    self:later(function ()
        self:gc()
    end)
end

-- scene api
function xGame:_loadAssets(func, cls, ...)
    if type(cls) == 'string' then
        cls = require(cls)
    end
    local queue = LoadQueue.new(cls:assets(...))
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
end

function xGame:startScene(cls, ...)
    self:_loadAssets(self._sceneStack.startScene, cls, ...)
end

function xGame:replaceScene(cls, ...)
    self:_loadAssets(self._sceneStack.replaceScene, cls, ...)
end

function xGame:popScene()
    self._sceneStack:popScene()
end

function xGame:popAll()
    self._sceneStack:popAll()
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

function xGame:later(func)
    runtime.once('runtimeUpdate', func)
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
    listen('openURL')
    listen('memoryWarning')
    listen('networkChange')
    listen('runtimeGC')
    listen('runtimeUpdate')
    listen('runtimeResize')
    listen('runtimePause')
    listen('runtimeResume')
end

xGame = xGame.new()