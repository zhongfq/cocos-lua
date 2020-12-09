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

function GaussBlur:ctor(node, scale, dynamic, blurRadius)
    self.width = node.width
    self.height = node.height
    self.rtBlurRadius = blurRadius or 1
    self.rtScale = scale or 0.5
    self.rtDynamic = dynamic
    self.rtWidth = node.width * self.rtScale // 1
    self.rtHeight = node.height * self.rtScale // 1
    self.rtNode = self:createRenderTexture(self.rtWidth, self.rtHeight)
    self.rtBlurX = self:createRenderTexture(self.rtWidth, self.rtHeight)
    self.rtBlurY = self:createRenderTexture(self.rtWidth, self.rtHeight)
    self.rtSpriteX = self:createBlurSprite(self.rtBlurX.sprite.texture, 1, 0, self.rtWidth, self.rtHeight)
    self.rtSpriteY = self:createBlurSprite(self.rtBlurY.sprite.texture, 0, 1, self.rtWidth, self.rtHeight)
    
    self.content = self:createSprite(self.rtNode.sprite.texture)
    self.content.anchorX = 0
    self.content.anchorY = 0
    self.content.scaleX = 1 / self.rtScale
    self.content.scaleY = 1 / self.rtScale
    self.cobj:addChild(self.content)

    self.renderListener = EventListenerCustom.create(Director.EVENT_BEFORE_DRAW, function ()
        if not self.rtDynamic then
            director.eventDispatcher:removeEventListener(self.renderListener)
        end

        local visible = node.visible
        local x = node.x
        local y = node.y
        local scaleX = node.scaleX
        local scaleY = node.scaleY
        local anchorX = node.anchorX
        local anchorY = node.anchorY
        node.visible = true
        node.x = 0
        node.y = 0
        node.anchorX = 0
        node.anchorY = 0
        node.scaleX = self.rtScale
        node.scaleY = self.rtScale
        self.rtBlurX:beginVisit()
        if node.classtype == 'native' then
            node:visit()
        else
            node.cobj:visit()
        end
        self.rtBlurX:endVisit()
        node.visible = visible
        node.x = x
        node.y = y
        node.scaleX = scaleX
        node.scaleY = scaleY
        node.anchorX = anchorX
        node.anchorY = anchorY
        
        self.rtBlurY:beginVisit()
        self.rtSpriteX:visit()
        self.rtBlurY:endVisit()

        self.rtNode:beginVisit()
        self.rtSpriteY:visit()
        self.rtNode:endVisit()
    end)

    if self.rtDynamic then
        self.cobj.onExitCallback = function ()
            director.eventDispatcher:removeEventListener(self.renderListener)
        end
        self.cobj.onEnterCallback = function ()
            director.eventDispatcher:addEventListenerWithFixedPriority(self.renderListener, 1)
        end
    else
        director.eventDispatcher:addEventListenerWithFixedPriority(self.renderListener, 1)
    end
end

function GaussBlur:createSprite(texture)
    local sprite = Sprite.createWithTexture(texture)
    sprite.ignoreAnchorPointForPosition = true
    sprite.flippedY = true
    return sprite
end

function GaussBlur:createBlurSprite(texture, x, y, width, height)
    local sprite = self:createSprite(texture)
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
    state:setUniformFloat('radius', self.rtBlurRadius)
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