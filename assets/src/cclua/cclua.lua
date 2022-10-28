local timer         = require "cclua.timer"
local runtime       = require "cclua.runtime"
local Array         = require "cclua.Array"
local MediatorMap   = require "cclua.MediatorMap"
local Event         = require "cclua.Event"
local LoadQueue     = require "cclua.LoadQueue"
local SceneStack    = require "cclua.ui.SceneStack"
local Stage         = require "cclua.ui.Stage"

cclua = {}
cclua.stage = Stage.new()
cclua.idleTime = math.maxinteger
cclua._timer = nil
cclua._pauseTime = nil
cclua._mediatorMap = MediatorMap.new(cclua.stage)
cclua._sceneStack = SceneStack.new(cclua.stage)
cclua._services = {}
cclua._serviceClasses = Array.new()

-- init fairygui uiroot
if runtime.hasFeature("fairygui") then
    local FGUINode = require "cclua.ui.FGUINode"
    local keepUIRootNotNull = FGUINode.new()
    runtime.runningScene:addChild(keepUIRootNotNull.cobj)
end

-- add stage to the root scene
runtime.runningScene:addChild(cclua.stage.cobj)

function cclua.gc()
    runtime.gc()
end

-- services
function cclua.newService(name, cls)
    assert(not cclua[name], 'name conflict: ' .. name)
    local serviceClass = require(cls)
    local svr = serviceClass.new(name)
    cclua[name] = svr
    cclua._services[name] = svr
    cclua._serviceClasses:pushBack({class = cls, name = name})
    printf('[cclua] create service: %s(%s)', name, cls)
end

function cclua.restart(cls, ...)
    cclua.popAll()

    for name, svr in pairs(cclua._services) do
        assert(cclua[name] == svr, name)
        svr:dispose()
        assert(svr.dispose == true, name)
        cclua._services[name] = nil
        cclua[name] = nil
    end

    local serviceClasses = cclua._serviceClasses:slice()
    cclua._serviceClasses.length = 0
    for _, v in ipairs(serviceClasses) do
        cclua.newService(v.name, v.class)
    end

    printf('[cclua] restart: %s', cls)

    cclua.startScene(cls, ...)
    cclua.later(function ()
        cclua.gc()
    end)
end

function cclua.loadAssets(assets, callback)
    local queue = LoadQueue.new(assets)
    if queue.totalCount > 0 then
        queue:addListener(Event.IOERROR, function ()
            runtime.dispatch(Event.IOERROR, queue)
        end)
        queue:addListener(Event.PROGRESS, function ()
            runtime.dispatch(Event.LOADER_UPDATE, queue)
        end)
        queue:addListener(Event.COMPLETE, function ()
            runtime.dispatch(Event.LOADER_COMPLETE, queue)
            callback()
        end)
        runtime.dispatch(Event.LOADER_START, queue)
        queue:start()
    else
        callback()
    end
end

function cclua.playMusic(path, volume)
    cclua._sceneStack:playMusic(path, volume)
end

-- scene api
local function loadSceneAssets(func, cls, ...)
    if type(cls) == 'string' then
        cls = require(cls)
    end
    assert(type(cls) == 'table', 'not a class')
    local args = {...}
    cclua.loadAssets(cls:assets(...), function ()
        func(cclua._sceneStack, cls, table.unpack(args))
    end)
end

function cclua.show(cls, ...)
    loadSceneAssets(cclua._sceneStack.show, cls, ...)
end

function cclua.startScene(cls, ...)
    loadSceneAssets(cclua._sceneStack.startScene, cls, ...)
end

function cclua.replaceScene(cls, ...)
    loadSceneAssets(cclua._sceneStack.replaceScene, cls, ...)
end

function cclua.findScene(cls)
    return cclua._sceneStack:findScene(cls)
end

function cclua.popScene()
    cclua._sceneStack:popScene()
end

function cclua.popAll()
    cclua._sceneStack:popAll()
end

function cclua.topScene()
    return cclua._sceneStack:topScene()
end

-- timer api
cclua._timer = timer.new()
timer.schedule(0, function (...)
    cclua._timer:update(...)
end)

function cclua.later(func)
    runtime.once('runtimeUpdate', func)
end

function cclua.delay(time, func, ...)
    cclua._timer:delay(time, func, ...)
end

function cclua.delayWithTag(time, tag, func, ...)
    cclua._timer:delayWithTag(time, tag, func, ...)
end

function cclua.killDelay(tag)
    cclua._timer:killDelay(tag)
end

function cclua.schedule(interval, func, contextView)
    if contextView then
        local id
        assert(func)
        id = cclua._timer:schedule(interval, function (...)
            if contextView.stage then
                func(...)
            else
                cclua.unschedule(id)
            end
        end)
        return id
    else
        return cclua._timer:schedule(interval, func)
    end
end

function cclua.unschedule(id)
    return cclua._timer:unschedule(id)
end

--
-- runtime event
--
runtime.on(Event.RUNTIME_PAUSE, function ()
    cclua._pauseTime = os.time()
end)

runtime.on(Event.RUNTIME_RESUME, function ()
    local pauseTime = cclua._pauseTime
    if pauseTime and os.time() - pauseTime > cclua.idleTime then
        cclua.popAll()
        runtime.restart()
    else
        cclua._pauseTime = nil
    end
end)

function cclua.on(event, callback, caller)
    return runtime.on(event, callback, caller)
end

function cclua.once(event, callback, caller)
    return runtime.once(event, callback, caller)
end

function cclua.off(event, callback)
    return runtime.off(event, callback)
end

return cclua