local class         = require "xgame.class"
local timer         = require "xgame.timer"
local runtime       = require "xgame.runtime"
local MediatorMap   = require "xgame.MediatorMap"
local Stage         = require "xgame.ui.Stage"
local UIImage       = require "xgame.ui.UIImage"
local SceneStack    = require "xgame.private.SceneStack"
local window        = require "kernel.window"
local Director      = require "cc.Director"
local RenderTexture = require "cc.RenderTexture"
local PixelFormat   = require "cc.Texture2D.PixelFormat"

local director = Director.instance

xGame = class("xGame", require("xgame.event.EventDispatcher"))

function xGame:ctor()
    self.time = 0
    self.stage = Stage.new()
    self._mediatorMap = MediatorMap.new(self.stage)
    self._sceneStack = SceneStack.new(self.stage)
    self:_initTimer()
    self:_initRuntimeEvents()

    director.runningScene:addChild(self.stage.cobj)
end

function xGame:snapshot(node)
    local DEPTH24_STENCIL8_OES = 0x88f0
    local width, height = node.width, node.height
    local vpw, vph = xGame:designSize()
    local renderTexture = RenderTexture.create(width, height,
        PixelFormat.RGB565, DEPTH24_STENCIL8_OES)
    local visible = node.cobj:isVisible()
    renderTexture:setKeepMatrix(true)
    renderTexture:setVirtualViewport({
        -- begin
        x = 0,
        y = 0,
    }, { -- full rect
        x = 0,
        y = 0,
        width = width,
        height = height,
    }, {
        -- full viewport
        x = 0,
        y = 0,
        width = vpw,
        height = vph,
    })
    renderTexture:beginVisit()
    node.cobj:setVisible(true)
    node.cobj:visit()
    node.cobj:setVisible(visible)
    renderTexture:endVisit()

    director.renderer:render()

    local image = UIImage.new()
    image.cobj = renderTexture:getSprite()
    image.cobj:getTexture():setAntiAliasTexParameters()
    renderTexture:removeAllChildren()
    image.cobj:setIgnoreAnchorPointForPosition(true)
    image.cobj.anchorX = 0.5
    image.cobj.anchorY = 0.5
    return image
end

-- scene api
function xGame:startScene(cls, ...)
    return self._sceneStack:startScene(cls, ...)
end

function xGame:replaceScene(cls, ...)
    return self._sceneStack:replaceScene(cls, ...)
end

function xGame:popScene()
    self._sceneStack:popScene()
end

function xGame:popAll()
    self._sceneStack:popAll()
end

function xGame:showView(cls, ...)
    self._sceneStack:showView(cls)
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
        self.time = self.time + dt
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
function xGame:designSize()
    return window.getDesignSize()
end

function xGame:visibleBounds()
    return window.getVisibleBounds()
end

function xGame:frameSize()
    local size = Director:getOpenGLView():getFrameSize()
    return size.width, size.height
end

xGame = xGame.new()