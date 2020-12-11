local class                 = require "xgame.class"
local shader                = require "xgame.shader"
local RenderTexture         = require "cc.RenderTexture"
local EventListenerCustom   = require "cc.EventListenerCustom"
local Director              = require "cc.Director"
local Sprite                = require "cc.Sprite"
local PixelFormat           = require "ccb.PixelFormat"
local ProgramState          = require "ccb.ProgramState"

local director = Director.instance

local GaussFilter = class('GaussFilter')

function GaussFilter:ctor(scale, dynamic, radius)
    self.radius = radius or 1
    self.scale = scale or 0.5
    self.dynamic = dynamic
end

function GaussFilter:apply(source, dest)
    local width = source.width * self.scale // 1
    local height = source.height * self.scale // 1
    local snapshot = self:_createRenderTexture("snapshot", width, height)
    local blurX = self:_createRenderTexture("blurX", width, height)
    local blurY = self:_createRenderTexture("blurY", width, height)
    local spriteX = self:_createBlurSprite(snapshot.sprite.texture, 1, 0, width, height)
    local spriteY = self:_createBlurSprite(blurX.sprite.texture, 0, 1, width, height)

    dest.onUpdate = function ()
        if not self.dynamic then
            dest.onUpdate = nil
        end

        local visible = source.visible
        local x = source.x
        local y = source.y
        local scaleX = source.scaleX
        local scaleY = source.scaleY
        local anchorX = source.anchorX
        local anchorY = source.anchorY
        local filter = source.cobj.filter
        source.visible = true
        source.x = 0
        source.y = 0
        source.anchorX = 0
        source.anchorY = 0
        source.scaleX = self.scale
        source.scaleY = self.scale
        source.cobj.filter = nil
        snapshot:beginVisit()
        source.cobj:visit()
        snapshot:endVisit()
        source.visible = visible
        source.x = x
        source.y = y
        source.scaleX = scaleX
        source.scaleY = scaleY
        source.anchorX = anchorX
        source.anchorY = anchorY
        source.cobj.filter = filter
        
        blurX:beginVisit()
        spriteX:visit()
        blurX:endVisit()

        blurY:beginVisit()
        spriteY:visit()
        blurY:endVisit()
    end

    -- render current frame, EVENT_BEFORE_DRAW triggered after update
    local renderListener
    renderListener = EventListenerCustom.create(Director.EVENT_BEFORE_DRAW, function ()
        director.eventDispatcher:removeEventListener(renderListener)
        dest.onUpdate()
    end)
    director.eventDispatcher:addEventListener(renderListener)

    dest.texture = blurY.sprite.texture
    if blurY.sprite.flippedY then
        dest.flippedY = blurY.sprite.flippedY
    end
    dest.anchorX = 0
    dest.anchorY = 0
    dest.scaleX = 1 / self.scale
    dest.scaleY = 1 / self.scale
end

function GaussFilter:_createSprite(texture)
    local sprite = Sprite.createWithTexture(texture)
    sprite.ignoreAnchorPointForPosition = true
    sprite.flippedY = true
    return sprite
end

function GaussFilter:_createBlurSprite(texture, x, y, width, height)
    local sprite = self:_createSprite(texture)
    sprite.programState = self:_createBlurShader(x, y, width, height)
    return sprite
end

function GaussFilter:_createRenderTexture(name, width, height)
    local node = RenderTexture.create(width, height, PixelFormat.RGB565, PixelFormat.D24S8)
    node.name = name
    node.sprite.ignoreAnchorPointForPosition = true
    node.sprite.anchorX = 0
    node.sprite.anchorY = 0
    return node
end

function GaussFilter:_createBlurShader(x, y, width, height)
    local state = ProgramState.new(shader.gaussFilterGaussFilter)
    state:setUniformVec2('resolution', {x = width, y = height})
    state:setUniformVec2('direction', {x = x, y = y})
    state:setUniformFloat('radius', self.radius)
    return state
end

shader.load('gaussFilterGaussFilter',
[[
    attribute vec4 a_position;
    attribute vec2 a_texCoord;
    attribute vec4 a_color;

    uniform mat4 u_MVPMatrix;

    #ifdef GL_ES
    varying lowp vec4 v_fragmentColor;
    varying mediump vec2 v_texCoord;
    #else
    varying vec4 v_fragmentColor;
    varying vec2 v_texCoord;
    #endif

    void main()
    {
        gl_Position = u_MVPMatrix * a_position;
        v_fragmentColor = a_color;
        v_texCoord = a_texCoord;
    }
]],
[[
    #ifdef GL_ES
    precision mediump float;
    #endif

    varying vec4 v_fragmentColor;
    varying vec2 v_texCoord;
    
    uniform sampler2D u_texture;

    uniform vec2 resolution;
    uniform vec2 direction;
    uniform float radius;


    void main()
    {
        vec4 sum = vec4(0.0);
        float psx = radius / resolution.x;
        float psy = radius / resolution.y;

        sum += texture2D(u_texture, vec2(v_texCoord.x - 7.0 * psx * direction.x, v_texCoord.y - 8.0 * psy * direction.y)) * 0.003799;
        sum += texture2D(u_texture, vec2(v_texCoord.x - 7.0 * psx * direction.x, v_texCoord.y - 7.0 * psy * direction.y)) * 0.008741;
        sum += texture2D(u_texture, vec2(v_texCoord.x - 6.0 * psx * direction.x, v_texCoord.y - 6.0 * psy * direction.y)) * 0.017997;
        sum += texture2D(u_texture, vec2(v_texCoord.x - 5.0 * psx * direction.x, v_texCoord.y - 5.0 * psy * direction.y)) * 0.033159;
        sum += texture2D(u_texture, vec2(v_texCoord.x - 4.0 * psx * direction.x, v_texCoord.y - 4.0 * psy * direction.y)) * 0.054670;
        sum += texture2D(u_texture, vec2(v_texCoord.x - 3.0 * psx * direction.x, v_texCoord.y - 3.0 * psy * direction.y)) * 0.080657;
        sum += texture2D(u_texture, vec2(v_texCoord.x - 2.0 * psx * direction.x, v_texCoord.y - 2.0 * psy * direction.y)) * 0.106483;
        sum += texture2D(u_texture, vec2(v_texCoord.x - 1.0 * psx * direction.x, v_texCoord.y - 1.0 * psy * direction.y)) * 0.125794;
        sum += texture2D(u_texture, vec2(v_texCoord.x, v_texCoord.y)) * 0.137401;
        sum += texture2D(u_texture, vec2(v_texCoord.x + 1.0 * psx * direction.x, v_texCoord.y + 1.0 * psy * direction.y)) * 0.125794;
        sum += texture2D(u_texture, vec2(v_texCoord.x + 2.0 * psx * direction.x, v_texCoord.y + 2.0 * psy * direction.y)) * 0.106483;
        sum += texture2D(u_texture, vec2(v_texCoord.x + 3.0 * psx * direction.x, v_texCoord.y + 3.0 * psy * direction.y)) * 0.080657;
        sum += texture2D(u_texture, vec2(v_texCoord.x + 4.0 * psy * direction.x, v_texCoord.y + 4.0 * psy * direction.y)) * 0.054670;
        sum += texture2D(u_texture, vec2(v_texCoord.x + 5.0 * psx * direction.x, v_texCoord.y + 5.0 * psy * direction.y)) * 0.033159;
        sum += texture2D(u_texture, vec2(v_texCoord.x + 6.0 * psx * direction.x, v_texCoord.y + 6.0 * psy * direction.y)) * 0.017997;
        sum += texture2D(u_texture, vec2(v_texCoord.x + 7.0 * psx * direction.x, v_texCoord.y + 7.0 * psy * direction.y)) * 0.008741;
        sum += texture2D(u_texture, vec2(v_texCoord.x - 8.0 * psx * direction.x, v_texCoord.y - 8.0 * psy * direction.y)) * 0.003799;

        gl_FragColor = v_fragmentColor*sum;
    }
]])

return GaussFilter