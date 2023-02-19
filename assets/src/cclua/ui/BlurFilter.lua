local class                 = require "cclua.class"
local shader                = require "cclua.shader"
local RenderTexture         = require "cc.RenderTexture"
local EventListenerCustom   = require "cc.EventListenerCustom"
local Director              = require "cc.Director"
local Sprite                = require "cc.Sprite"
local PixelFormat           = require "ccb.PixelFormat"
local ProgramState          = require "ccb.ProgramState"
local float                 = require "olua.float"

local director = Director.instance

local BlurFilter = class('BlurFilter')

function BlurFilter:ctor(scale, dynamic, blurRadius, sampleCount)
    self.scale = scale or 0.5
    self.blurRadius = blurRadius or 5
    self.sampleCount = sampleCount or 3
    self.dynamic = dynamic
end

function BlurFilter:apply(source, dest)
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
        if dest.onUpdate then
            dest.onUpdate()
        end
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

function BlurFilter:_createSprite(texture)
    local sprite = Sprite.createWithTexture(texture)
    sprite.ignoreAnchorPointForPosition = true
    sprite.flippedY = true
    return sprite
end

function BlurFilter:_createBlurSprite(texture, x, y, width, height)
    local sprite = self:_createSprite(texture)
    sprite.programState = self:_createBlurShader(x, y, width, height)
    return sprite
end

function BlurFilter:_createRenderTexture(name, width, height)
    local node = RenderTexture.create(width, height, PixelFormat.RGB565, PixelFormat.D24S8)
    node.name = name
    node.sprite.ignoreAnchorPointForPosition = true
    node.sprite.anchorX = 0
    node.sprite.anchorY = 0
    return node
end

local function setUniform(state, name, ...)
    local args = {...}
    local buf = float.new(#args)
    for i, v in ipairs(args) do
        buf[i] = v
    end
    state:setUniform(state:getUniformLocation(name), buf.rawdata, buf.sizeof * #args)
end


function BlurFilter:_createBlurShader(x, y, width, height)
    local state = ProgramState.new(shader.BlurFilter)
    setUniform(state, 'resolution', width, height)
    setUniform(state, 'sampleCount', self.sampleCount)
    setUniform(state, 'blurRadius', self.blurRadius)
    return state
end

shader.load('BlurFilter',
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

    uniform vec2 resolution;
    uniform float blurRadius;
    uniform float sampleCount;

    uniform sampler2D u_texture;

    vec3 blur(vec2);

    void main(void)
    {
        vec3 col = blur(v_texCoord);
        gl_FragColor = vec4(col, 1.0) * v_fragmentColor;
    }

    vec3 blur(vec2 p)
    {
        if (blurRadius > 0.0 && sampleCount > 1.0)
        {
            vec3 col = vec3(0);
            vec2 unit = 1.0 / resolution.xy;
            float r = blurRadius;
            float sampleStep = r / sampleCount;
            float count = 0.0;
            for(float x = -r; x < r; x += sampleStep)
            {
                for(float y = -r; y < r; y += sampleStep)
                {
                    float weight = (r - abs(x)) * (r - abs(y));
                    col += texture2D(u_texture, p + vec2(x * unit.x, y * unit.y)).rgb * weight;
                    count += weight;
                }
            }
            return col / count;
        }
        return texture2D(u_texture, p).rgb;
    }
]])

return BlurFilter