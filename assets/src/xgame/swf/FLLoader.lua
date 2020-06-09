local shader            = require "xgame.shader"
local FLMovieClip       = require "xgame.swf.FLMovieClip"
local filesystem        = require "xgame.filesystem"
local assetloader       = require "xgame.assetloader"
local Event             = require "xgame.event.Event"
local LoadQueue         = require "xgame.loader.LoadQueue"
local swf               = require "xgame.swf.swf"
local GLProgramState    = require "cc.GLProgramState"

local textureCache = require("cc.Director").instance.textureCache

local FLLoader = swf.class("FLLoader", FLMovieClip)

function FLLoader:ctor()
    self._image = swf.Image.new()
    self._alphaMask = false
    self._alphaShader = false
    self._preferred = assert(self.ns['__preferred__'], 'no preferred')
    self._preferredWidth = self._preferred.width
    self._preferredHeight = self._preferred.height
    self.cobj:addChild(self._image)
end

function FLLoader.Get:alphaMask()
    return self._alphaMask
end

function FLLoader.Set:alphaMask(value)
    if self._alphaMask ~= value then
        self._alphaShader = false
        self._alphaMask = value
    end
end

function FLLoader:load(url)
    local assets = {[url] = true}
    if self._alphaMask then
        assets[self._alphaMask] = true
    end
    local queue = LoadQueue.new(assets)
    self:unload()
    queue:addListener(Event.COMPLETE, function ()
        local path = filesystem.localCachePath(url)
        self._image:load(path)
        -- reset scale
        self._image.scaleX = 1
        self._image.scaleY = 1
        self._image.scaleX = self._preferredWidth / self._image.width
        self._image.scaleY = self._preferredHeight / self._image.height
        self._preferred.visible = false

        if self._alphaMask and not self._alphaShader then
            local maskPath = filesystem.localCachePath(self._alphaMask)
            local alphaTexture = textureCache:addImage(maskPath)
            assetloader.load(self, {[maskPath] = true})
            self._alphaShader = GLProgramState.new(shader.swfBitmapAlpha)
            self._alphaShader:setTexture(
                self._alphaShader:getUniformLocation('u_alpha_texture'),
                1,
                alphaTexture.backendTexture
            )
            self._image:setShader('BITMAP', self._alphaShader)
        end
    end)
    queue:start()
end

function FLLoader:unload()
    self._preferred.visible = true
    self._image:unload()
end

return FLLoader
