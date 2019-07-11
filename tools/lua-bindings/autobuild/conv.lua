require "autobuild.conv-types"

local cls
local M = {}
M.NAME = "conv"
M.HEADER_PATH = "../../frameworks/libxgame/src/lua-bindings/lua_conv.h"
M.SOURCE_PATH = "../../frameworks/libxgame/src/lua-bindings/lua_conv.cpp"
M.HEADER_INCLUDES = [[
#include "xgame/xlua.h"
#include "cocos2d.h"
#include "ui/CocosGUI.h"
]]
M.INCLUDES = [[
#include "lua-bindings/lua_conv.h"
]]

M.CONVS = {
    typeconv {
        CPPCLS = 'cocos2d::Vec2',
        DEF = [[
            float x;
            float y;
        ]],
        FUNC = nil,
    },
    typeconv {
        CPPCLS = 'cocos2d::Vec3',
        DEF = [[
            float x;
            float y;
            float z;
        ]],
        FUNC = nil,
    },
    typeconv {
        CPPCLS = 'cocos2d::Vec4',
        DEF = [[
            float x;
            float y;
            float z;
            float w;
        ]],
        FUNC = nil,
    },
    typeconv {
        CPPCLS = 'cocos2d::Size',
        DEF = [[
            float width;
            float height;
        ]],
        FUNC = nil,
    },
    typeconv {
        CPPCLS = 'cocos2d::Texture2D::TexParams',
        DEF = [[
            GLuint minFilter;
            GLuint magFilter;
            GLuint wrapS;
            GLuint wrapT;
        ]],
        FUNC = nil,
    },
    typeconv {
        CPPCLS = 'cocos2d::Uniform',
        DEF = [[
            GLint location;
            GLint size;
            GLenum type;
            std::string name;
        ]],
        FUNC = nil,
    },
    typeconv {
        CPPCLS = 'cocos2d::VertexAttrib',
        DEF = [[
            GLuint index;
            GLint size;
            GLenum type;
            std::string name;
        ]],
        FUNC = nil,
    },
    typeconv {
        CPPCLS = 'cocos2d::experimental::Viewport',
        DEF = [[
            float _left;
            float _bottom;
            float _width;
            float _height;
        ]],
        FUNC = nil,
    },
    typeconv {
        CPPCLS = 'cocos2d::Quaternion',
        DEF = [[
            float x;
            float y;
            float z;
            float w;
        ]],
        FUNC = nil,
    },
    typeconv {
        CPPCLS = 'cocos2d::AffineTransform',
        DEF = [[
            float a;
            float b;
            float c;
            float d;
            float tx;
            float ty;
        ]],
        FUNC = nil,
    },
    typeconv {
        CPPCLS = 'GLContextAttrs',
        DEF = [[
            int redBits;
            int greenBits;
            int blueBits;
            int alphaBits;
            int depthBits;
            int stencilBits;
            int multisamplingCount;
        ]],
        FUNC = nil,
    },
    typeconv {
        CPPCLS = 'cocos2d::Tex2F',
        DEF = [[
            GLfloat u;
            GLfloat v;
        ]],
        FUNC = nil,
    },
    typeconv {
        CPPCLS = 'cocos2d::T2F_Quad',
        DEF = [[
            cocos2d::Tex2F bl;
            cocos2d::Tex2F br;
            cocos2d::Tex2F tl;
            cocos2d::Tex2F tr;
        ]],
        FUNC = "push|check|is",
    },
    typeconv {
        CPPCLS = 'cocos2d::TTFConfig',
        DEF = [[
            std::string fontFilePath;
            float fontSize = 12;
            cocos2d::GlyphCollection glyphs = 0;
            const char *customGlyphs = nullptr;
            bool distanceFieldEnabled = false;
            int outlineSize = 0;
            bool italics = false;
            bool bold = false;
            bool underline = false;
            bool strikethrough = false;
        ]],
        FUNC = "push|check|is",
    },
    typeconv {
        CPPCLS = 'cocos2d::BlendFunc',
        DEF = [[
            GLenum src;
            GLenum dst;
        ]],
        FUNC = nil,
    },
    typeconv {
        CPPCLS = 'cocos2d::ui::Margin',
        DEF = [[
            float left;
            float top;
            float right;
            float bottom;
        ]],
        FUNC = nil,
    },
    typeconv {
        CPPCLS = 'cocos2d::ResourceData',
        DEF = [[
            int         type;
            std::string file;
            std::string plist;
        ]],
        FUNC = nil,
    },
    typeconv {
        CPPCLS = 'cocos2d::Quad3',
        DEF = [[
            cocos2d::Vec3 bl;
            cocos2d::Vec3 br;
            cocos2d::Vec3 tl;
            cocos2d::Vec3 tr;
        ]],
        FUNC = "push|check|is",
    },
    typeconv {
        CPPCLS = 'cocos2d::Controller::KeyStatus',
        DEF = [[
            bool isPressed;
            float value;
            bool isAnalog;
        ]],
        FUNC = nil,
    },
}

M.CLASSES = {}

return M
