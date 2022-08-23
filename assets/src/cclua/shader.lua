local Device        = require "ccb.Device"

local mt = {}
local M = setmetatable({}, mt)
local programs = {}

mt.__index = function(t, name)
    return assert(programs[name], 'no program: ' .. name)
end

function M.load(name, vert, frag)
    assert(not programs[name])
    programs[name] = Device.instance:newProgram(vert, frag)
end

do
    local vert =
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
    ]]

    M.load("default", vert,
    [[
        #ifdef GL_ES
        precision lowp float;
        #endif

        varying vec4 v_fragmentColor;
        varying vec2 v_texCoord;

        uniform sampler2D u_texture;

        void main()
        {
            gl_FragColor = v_fragmentColor * texture2D(u_texture, v_texCoord);
        }
    ]])

    M.load("gray", vert,
    [[
        #ifdef GL_ES
        precision mediump float;
        #endif
        varying vec2 v_texCoord;
        varying vec4 v_fragmentColor;

        uniform sampler2D u_texture;

        void main(void)
        {
            float alpha = texture2D(u_texture, v_texCoord).a * v_fragmentColor.a;
            float grey = dot(texture2D(u_texture, v_texCoord).rgb, vec3(0.299,0.587,0.114));
            gl_FragColor = vec4(grey * alpha, grey * alpha, grey * alpha, alpha);
        }
    ]])

    M.load("black", vert,
    [[
        #ifdef GL_ES
        precision mediump float;
        #endif
        varying vec2 v_texCoord;
        varying vec4 v_fragmentColor;

        uniform sampler2D u_texture;

        void main(void)
        {
            float alpha = texture2D(u_texture, v_texCoord).a;
            gl_FragColor = vec4(0.0, 0.0, 0.0, alpha);
        }
    ]])

    M.load("white", vert, [[
        #ifdef GL_ES
        precision mediump float;
        #endif
        varying vec2 v_texCoord;
        varying vec4 v_fragmentColor;

        uniform sampler2D u_texture;

        void main(void)
        {
            float alpha = texture2D(u_texture, v_texCoord).a;
            gl_FragColor = vec4(alpha, alpha, alpha, alpha);
        }
    ]])

    M.load("blur", vert,
    [[
        #ifdef GL_ES
        precision mediump float;
        #endif

        varying vec4 v_fragmentColor;
        varying vec2 v_texCoord;

        uniform vec2 resolution;
        uniform float blurRadius;
        uniform float sampleNum;

        uniform sampler2D u_texture;

        vec3 blur(vec2);

        void main(void)
        {
            vec3 col = blur(v_texCoord);
            gl_FragColor = vec4(col, 1.0) * v_fragmentColor;
        }

        vec3 blur(vec2 p)
        {
            if (blurRadius > 0.0 && sampleNum > 1.0)
            {
                vec3 col = vec3(0);
                vec2 unit = 1.0 / resolution.xy;
                float r = blurRadius;
                float sampleStep = r / sampleNum;
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
end

return M