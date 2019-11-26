-- AUTO BUILD, DON'T MODIFY!

require "autobuild.conv-types"

local olua = require "olua"
local typeconv = olua.typeconv
local typecls = olua.typecls
local cls = nil
local M = {}

M.NAME = "conv"
M.PATH = "../../frameworks/libxgame/src/lua-bindings"
M.HEADER_INCLUDES = [[
#include "xgame/xlua.h"
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "network/WebSocket.h"
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
    },
    typeconv {
        CPPCLS = 'cocos2d::Point',
        DEF = [[
            float x;
            float y;
        ]],
    },
    typeconv {
        CPPCLS = 'cocos2d::Vec3',
        DEF = [[
            float x;
            float y;
            float z;
        ]],
    },
    typeconv {
        CPPCLS = 'cocos2d::Vec4',
        DEF = [[
            float x;
            float y;
            float z;
            float w;
        ]],
    },
    typeconv {
        CPPCLS = 'cocos2d::Size',
        DEF = [[
            float width;
            float height;
        ]],
    },
    typeconv {
        CPPCLS = 'cocos2d::Texture2D::TexParams',
        DEF = [[
            GLuint minFilter;
            GLuint magFilter;
            GLuint wrapS;
            GLuint wrapT;
        ]],
    },
    typeconv {
        CPPCLS = 'cocos2d::experimental::Viewport',
        DEF = [[
            float _left;
            float _bottom;
            float _width;
            float _height;
        ]],
    },
    typeconv {
        CPPCLS = 'cocos2d::Quaternion',
        DEF = [[
            float x;
            float y;
            float z;
            float w;
        ]],
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
    },
    typeconv {
        CPPCLS = 'cocos2d::Tex2F',
        DEF = [[
            GLfloat u;
            GLfloat v;
        ]],
    },
    typeconv {
        CPPCLS = 'cocos2d::T2F_Quad',
        DEF = [[
            cocos2d::Tex2F bl;
            cocos2d::Tex2F br;
            cocos2d::Tex2F tl;
            cocos2d::Tex2F tr;
        ]],
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
    },
    typeconv {
        CPPCLS = 'cocos2d::BlendFunc',
        DEF = [[
            GLenum src;
            GLenum dst;
        ]],
    },
    typeconv {
        CPPCLS = 'cocos2d::ui::Margin',
        DEF = [[
            float left;
            float top;
            float right;
            float bottom;
        ]],
    },
    typeconv {
        CPPCLS = 'cocos2d::ResourceData',
        DEF = [[
            int         type;
            std::string file;
            std::string plist;
        ]],
    },
    typeconv {
        CPPCLS = 'cocos2d::Quad3',
        DEF = [[
            cocos2d::Vec3 bl;
            cocos2d::Vec3 br;
            cocos2d::Vec3 tl;
            cocos2d::Vec3 tr;
        ]],
    },
    typeconv {
        CPPCLS = 'cocos2d::Controller::KeyStatus',
        DEF = [[
            bool isPressed;
            float value;
            bool isAnalog;
        ]],
    },
    typeconv {
        CPPCLS = 'cocos2d::network::WebSocket::Data',
        DEF = [[
            char* bytes;
            ssize_t len;
            ssize_t issued;
            bool isBinary;
            void* ext;
        ]],
    },
}

M.CLASSES = {}

return M
