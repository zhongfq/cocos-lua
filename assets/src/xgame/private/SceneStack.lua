local class         = require "xgame.class"
local util          = require "xgame.util"
local runtime       = require "xgame.runtime"
local Array         = require "xgame.Array"
local assetloader   = require "xgame.assetloader"
local Event         = require "xgame.event.Event"
local UILayer       = require "xgame.ui.UILayer"
local PixelFormat   = require "ccb.PixelFormat"

local trace = util.trace("[SceneStack]")

local SceneStack = class("SceneStack")

function SceneStack:ctor(context)
    self._context = context
    self._sceneStack = Array.new()
    self._sceneLayer = UILayer.new()
    self._sceneLayer.percentWidth = 100
    self._sceneLayer.percentHeight = 100
    context.stage:addChild(self._sceneLayer)
end

function SceneStack:show(cls, ...)
    local scene = assert(self:topScene(), cls.classname)
    local view = cls.new(...)
    scene:addChild(view)
end

function SceneStack:startScene(cls, ...)
    local entry = self:_getSceneEntry(-1)
    if entry then
        entry.sceneWrapper.visible = false
        entry.sceneWrapper.cobj:onExit()
    end
    self:_doStartScene(cls, ...)
end

function SceneStack:replaceScene(cls, ...)
    self:_doPopScene(true)
    self:_doStartScene(cls, ...)
end

function SceneStack:popScene()
    self:_doPopScene(false)
    runtime.once(Event.RUNTIME_UPDATE, function ()
        runtime.gc()
    end)
    -- update music
end

function SceneStack:popAll()
    while #self._sceneStack > 1 do
        self:_doPopScene(true)
    end
    self:popScene()
end

function SceneStack:topScene()
    return self:_getScene(-1)
end

function SceneStack:_doStartScene(cls, ...)
    local snapshot = self:_doCaptureScene(self:_getSceneEntry(-1))
    local entry = self._sceneStack:pushBack({
        scene = false,
        sceneWrapper = false,
        snapshot = false,
    })
    trace("create scene: %s", cls.classname)
    local scene = cls.new(...)
    entry.scene = scene
    entry.sceneWrapper = self:_createSceneWrapper(scene)
    -- update bg music
    self._sceneLayer:addChild(entry.sceneWrapper)

    if scene.renderOption.snapshot and snapshot then
        entry.sceneWrapper.cobj:addProtectedChild(snapshot)
    end
    assetloader.loadSceneAssets(scene)
end

function SceneStack:_doPopScene(onlypop)
    local numScenes = #self._sceneStack
    local entry = self._sceneStack[numScenes]

    if entry then
        trace("destory scene: %s", entry.scene.classname)
        self._sceneStack[numScenes] = nil
        self._sceneLayer:removeChild(entry.sceneWrapper)
    end

    if not onlypop and numScenes > 1 then
        entry = self._sceneStack[numScenes - 1]
        entry.scene.visible = true
        entry.snapshot = false
        assetloader.loadSceneAssets(entry.scene)
        entry.sceneWrapper.visible = true
        entry.sceneWrapper.cobj:onEnter()
    end
end

function SceneStack:_doCaptureScene(entry)
    if not entry then
        return
    end
    if not entry.snapshot then
        entry.snapshot = runtime.capture(entry.sceneWrapper.cobj, PixelFormat.RGB565)
    end
    return entry.snapshot
end

function SceneStack:_createSceneWrapper(scene)
    local wrapper = UILayer.new()
    wrapper.percentWidth = 100
    wrapper.percentHeight = 100
    wrapper:addChild(scene)
    return wrapper
end

function SceneStack:_getSceneEntry(index)
    if index < 0 then
        index = #self._sceneStack + index + 1
    end

    if index <= #self._sceneStack then
        return self._sceneStack[index]
    end
end

function SceneStack:_getScene(index)
    local entry = self:_getSceneEntry(index)
    if entry then
        return entry.scene
    end
end

return SceneStack