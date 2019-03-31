require 'conf.cocos2d.import-cocos2d-type'
require "conf.fairygui.import-fairygui-type"

local M = {}

M.NAME = "CONV"
M.HEADER_PATH = "template/frameworks/libxgame/src/xgame/lua-bindings/lua_conv.h"
M.SOURCE_PATH = "template/frameworks/libxgame/src/xgame/lua-bindings/lua_conv.cpp"

M.HEADER_INCLUDES = [[
#include "xgame/xlua.h"
#include "lua.hpp"

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "FairyGUI.h"
]]

M.INCLUDES = [[
#include "xgame/lua-bindings/lua_conv.h"
#include "xgame/xlua.h"
#include "olua/olua.hpp"
]]

M.CONVS = {
    REG_CONV {
        CPPCLS = 'cocos2d::Vec2',
        DEF = [[
            float x;
            float y;
        ]],
    },
    REG_CONV {
        CPPCLS = 'cocos2d::Vec3',
        DEF = [[
            float x;
            float y;
            float z;
        ]],
    },
    REG_CONV {
        CPPCLS = 'cocos2d::Vec4',
        DEF = [[
            float x;
            float y;
            float z;
            float w;
        ]],
    },
    REG_CONV {
        CPPCLS = 'cocos2d::Size',
        DEF = [[
            float width;
            float height;
        ]],
    },
    -- REG_CONV {
    --     CPPCLS = 'cocos2d::Color3B',
    --     DEF = [[
    --         GLubyte r;
    --         GLubyte g;
    --         GLubyte b;
    --     ]],
    -- },
    -- REG_CONV {
    --     CPPCLS = 'cocos2d::Color4B',
    --     DEF = [[
    --         GLubyte r;
    --         GLubyte g;
    --         GLubyte b;
    --         GLubyte a;
    --     ]],
    -- },
    -- REG_CONV {
    --     CPPCLS = 'cocos2d::Color4F',
    --     DEF = [[
    --         GLfloat r;
    --         GLfloat g;
    --         GLfloat b;
    --         GLfloat a;
    --     ]],
    -- },
    REG_CONV {
        CPPCLS = 'cocos2d::Texture2D::TexParams',
        DEF = [[
            GLuint minFilter;
            GLuint magFilter;
            GLuint wrapS;
            GLuint wrapT;
        ]],
    },
    REG_CONV {
        CPPCLS = 'cocos2d::Uniform',
        DEF = [[
            GLint location;
            GLint size;
            GLenum type;
            std::string name;
        ]],
    },
    REG_CONV {
        CPPCLS = 'cocos2d::VertexAttrib',
        DEF = [[
            GLuint index;
            GLint size;
            GLenum type;
            std::string name;
        ]]
    },
    REG_CONV {
        CPPCLS = 'cocos2d::experimental::Viewport',
        DEF = [[
            float _left = left;
            float _bottom = bottom;
            float _width = width;
            float _height = height;
        ]],
    },
    REG_CONV {
        CPPCLS = 'cocos2d::Quaternion',
        DEF = [[
            float x;
            float y;
            float z;
            float w;
        ]],
    },
    REG_CONV {
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
    REG_CONV {
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
    REG_CONV {
        CPPCLS = 'cocos2d::Tex2F',
        DEF = [[
            GLfloat u;
            GLfloat v;
        ]],
    },
    REG_CONV {
        CPPCLS = 'cocos2d::T2F_Quad',
        DEF = [[
            cocos2d::Tex2F bl;
            cocos2d::Tex2F br;
            cocos2d::Tex2F tl;
            cocos2d::Tex2F tr;
        ]],
        FUNC = 'push|check|is',
    },
    REG_CONV {
        CPPCLS = 'cocos2d::TTFConfig',
        DEF = [[
            std::string fontFilePath;
            float fontSize;
            cocos2d::GlyphCollection glyphs;
            const char *customGlyphs;
            bool distanceFieldEnabled;
            int outlineSize;
            bool italics;
            bool bold;
            bool underline;
            bool strikethrough;
        ]],
        FUNC = 'push|check|is'
    },
    REG_CONV {
        CPPCLS = 'cocos2d::BlendFunc',
        DEF = [[
            GLenum src;
            GLenum dst;
        ]]
    },
    REG_CONV {
        CPPCLS = 'cocos2d::ui::Margin',
        DEF = [[
            float left;
            float top;
            float right;
            float bottom;
        ]]
    },
    REG_CONV {
        CPPCLS = 'cocos2d::ResourceData',
        DEF = [[
            int         type;
            std::string file;
            std::string plist;
        ]]
    },
    REG_CONV {
        CPPCLS = 'fairygui::Margin',
        DEF = [[
            float left;
            float top;
            float right;
            float bottom;
        ]]
    },
    REG_CONV {
        CPPCLS = 'cocos2d::Quad3',
        DEF = [[
            cocos2d::Vec3 bl;
            cocos2d::Vec3 br;
            cocos2d::Vec3 tl;
            cocos2d::Vec3 tr;
        ]],
        FUNC = 'push|check|is',
    },
}

return M