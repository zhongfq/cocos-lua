local class                 = require "xgame.class"
local shader                = require "xgame.shader"
local UILayer               = require "xgame.ui.UILayer"
local RenderTexture         = require "cc.RenderTexture"
local EventListenerCustom   = require "cc.EventListenerCustom"
local Director              = require "cc.Director"
local Sprite                = require "cc.Sprite"
local PixelFormat           = require "ccb.PixelFormat"
local ProgramState          = require "ccb.ProgramState"

local director = Director.instance

local GaussBlur = class('GaussBlur', UILayer)

function GaussBlur:ctor(node)
    local width = node.width
    local height = node.height
    local visible = node.visible
    local x = node.x
    local y = node.y
    local scaleX = node.scaleX
    local scaleY = node.scaleY
    local renderListener
    local renderTexture = self:createRenderTexture(width, height)

    renderListener = EventListenerCustom.create(Director.EVENT_BEFORE_DRAW, function ()
        director.eventDispatcher:removeEventListener(renderListener, 1)
        director.nextDeltaTimeZero = true

        node.visible = true
        node.x = 0
        node.y = 0
        node.scaleX = 1
        node.scaleY = 1
        renderTexture:beginVisit()
        node.cobj:visit()
        renderTexture:endVisit()
        node.visible = visible
        node.x = x
        node.y = y
        node.scaleX = scaleX
        node.scaleY = scaleY
        
        local snapshot = self:createRenderTexture(width, height)
        local blurX = self:createBlurSprite(renderTexture.sprite.texture, 1, 0, width, height)
        snapshot:beginVisit()
        blurX:visit()
        snapshot:endVisit()

        local blurY = self:createBlurSprite(snapshot.sprite.texture, 0, 1, width, height)
        renderTexture:beginVisit()
        blurY:visit()
        renderTexture:endVisit()
    end)
    self.cobj:addChild(renderTexture)
    director.eventDispatcher:addEventListenerWithFixedPriority(renderListener, 1)
end

function GaussBlur:createBlurSprite(texture, x, y, width, height)
    local sprite = Sprite.createWithTexture(texture)
    sprite.ignoreAnchorPointForPosition = true
    sprite.flippedY = true
    sprite.programState = self:createBlurShader(x, y, width, height)
    return sprite
end

function GaussBlur:createRenderTexture(width, height)
    local node = RenderTexture.create(width, height, PixelFormat.RGB565, PixelFormat.D24S8)
    node.sprite.ignoreAnchorPointForPosition = true
    node.sprite.anchorX = 0
    node.sprite.anchorY = 0
    return node
end

function GaussBlur:createBlurShader(x, y, width, height)
    local state = ProgramState.new(shader.gaussBlur)
    state:setUniformVec2('resolution', {x = width, y = height})
    state:setUniformVec2('direction', {x = x, y = y})
    state:setUniformFloat('radius', 3)
    return state
end

shader.load('gaussBlur',
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
        float pixelsizex = radius/resolution.x;
        float pixelsizey = radius/resolution.y;

        sum += texture2D(u_texture, vec2(v_texCoord.x - 7.0*pixelsizex*direction.x, v_texCoord.y - 8.0*pixelsizey*direction.y)) * 0.003799;
        sum += texture2D(u_texture, vec2(v_texCoord.x - 7.0*pixelsizex*direction.x, v_texCoord.y - 7.0*pixelsizey*direction.y)) * 0.008741;
        sum += texture2D(u_texture, vec2(v_texCoord.x - 6.0*pixelsizex*direction.x, v_texCoord.y - 6.0*pixelsizey*direction.y)) * 0.017997;
        sum += texture2D(u_texture, vec2(v_texCoord.x - 5.0*pixelsizex*direction.x, v_texCoord.y - 5.0*pixelsizey*direction.y)) * 0.033159;
        sum += texture2D(u_texture, vec2(v_texCoord.x - 4.0*pixelsizex*direction.x, v_texCoord.y - 4.0*pixelsizey*direction.y)) * 0.054670;
        sum += texture2D(u_texture, vec2(v_texCoord.x - 3.0*pixelsizex*direction.x, v_texCoord.y - 3.0*pixelsizey*direction.y)) * 0.080657;
        sum += texture2D(u_texture, vec2(v_texCoord.x - 2.0*pixelsizex*direction.x, v_texCoord.y - 2.0*pixelsizey*direction.y)) * 0.106483;
        sum += texture2D(u_texture, vec2(v_texCoord.x - 1.0*pixelsizex*direction.x, v_texCoord.y - 1.0*pixelsizey*direction.y)) * 0.125794;
        sum += texture2D(u_texture, vec2(v_texCoord.x, v_texCoord.y)) * 0.137401;
        sum += texture2D(u_texture, vec2(v_texCoord.x + 1.0*pixelsizex*direction.x, v_texCoord.y + 1.0*pixelsizey*direction.y)) * 0.125794;
        sum += texture2D(u_texture, vec2(v_texCoord.x + 2.0*pixelsizex*direction.x, v_texCoord.y + 2.0*pixelsizey*direction.y)) * 0.106483;
        sum += texture2D(u_texture, vec2(v_texCoord.x + 3.0*pixelsizex*direction.x, v_texCoord.y + 3.0*pixelsizey*direction.y)) * 0.080657;
        sum += texture2D(u_texture, vec2(v_texCoord.x + 4.0*pixelsizey*direction.x, v_texCoord.y + 4.0*pixelsizey*direction.y)) * 0.054670;
        sum += texture2D(u_texture, vec2(v_texCoord.x + 5.0*pixelsizex*direction.x, v_texCoord.y + 5.0*pixelsizey*direction.y)) * 0.033159;
        sum += texture2D(u_texture, vec2(v_texCoord.x + 6.0*pixelsizex*direction.x, v_texCoord.y + 6.0*pixelsizey*direction.y)) * 0.017997;
        sum += texture2D(u_texture, vec2(v_texCoord.x + 7.0*pixelsizex*direction.x, v_texCoord.y + 7.0*pixelsizey*direction.y)) * 0.008741;
        sum += texture2D(u_texture, vec2(v_texCoord.x - 8.0*pixelsizex*direction.x, v_texCoord.y - 8.0*pixelsizey*direction.y)) * 0.003799;

        gl_FragColor = v_fragmentColor*sum;
    }
]])

return GaussBlur