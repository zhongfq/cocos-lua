local M = {}

M.NAME = "CONV"
M.HEADER_PATH = "template/frameworks/libxgame/src/xgame/lua-bindings/lua_conv.h"
M.SOURCE_PATH = "template/frameworks/libxgame/src/xgame/lua-bindings/lua_conv.cpp"

M.INCLUDES = [[
#include "xgame/lua-bindings/lua_conv.h"
#include "xgame/xlua.h"
#include "olua/olua.hpp"
]]

M.CONVS = {
    REG_CONV {
        CPPCLS = 'cocos2d::Vec2',
        DEF = [[
            {
                float x;
                float y;
            }
        ]],
    },
    REG_CONV {
        CPPCLS = 'cocos2d::Vec3',
        DEF = [[
            {
                float x;
                float y;
                float z;
            }
        ]],
    },
    REG_CONV {
        CPPCLS = 'cocos2d::Vec4',
        DEF = [[
            {
                float x;
                float y;
                float z;
                float w;
            }
        ]],
    },
    REG_CONV {
        CPPCLS = 'cocos2d::Size',
        DEF = [[
            {
                float width;
                float height;
            }
        ]],
    },
    REG_CONV {
        CPPCLS = 'cocos2d::Color3B',
        DEF = [[
            GLubyte r;
            GLubyte g;
            GLubyte b;
        ]],
    },
    REG_CONV {
        CPPCLS = 'cocos2d::Color4B',
        DEF = [[
            GLubyte r;
            GLubyte g;
            GLubyte b;
            GLubyte a;
        ]],
    },
    REG_CONV {
        CPPCLS = 'cocos2d::Color4F',
        DEF = [[
            GLfloat r;
            GLfloat g;
            GLfloat b;
            GLfloat a;
        ]],
    },
    REG_CONV {
        CPPCLS = 'cocos2d::Texture2D::TexParams',
        DEF = [[
            {
                GLuint minFilter;
                GLuint magFilter;
                GLuint wrapS;
                GLuint wrapT;
            }
        ]],
    },
    REG_CONV {
        CPPCLS = 'cocos2d::Uniform',
        DEF = [[
            {
                GLint location;
                GLint size;
                GLenum type;
                std::string name;
            }
        ]],
    },
    REG_CONV {
        CPPCLS = 'cocos2d::VertexAttrib',
        DEF = [[
            {
                GLuint index;
                GLint size;
                GLenum type;
                std::string name;
            }
        ]]
    },
    REG_CONV {
        CPPCLS = 'cocos2d::experimental::Viewport',
        DEF = [[
            {
                float _left = left;
                float _bottom = bottom;
                float _width = width;
                float _height = height;
            }
        ]],
    },
    REG_CONV {
        CPPCLS = 'GLContextAttrs',
        DEF = [[
            {
                int redBits;
                int greenBits;
                int blueBits;
                int alphaBits;
                int depthBits;
                int stencilBits;
                int multisamplingCount;
            }
        ]],
    },
}

M.DECLCHUNK = [[
int auto_luacv_push_cocos2d_Rect(lua_State *L, const cocos2d::Rect *value)
{
    if (value) {
        lua_createtable(L, 0, 4);
        olua_rawsetfieldnumber(L, -1, "x", value->origin.x);
        olua_rawsetfieldnumber(L, -1, "y", value->origin.y);
        olua_rawsetfieldnumber(L, -1, "width", value->size.width);
        olua_rawsetfieldnumber(L, -1, "height", value->size.height);
    } else {
        lua_pushnil(L);
    }
    
    return 1;
}

void auto_luacv_check_cocos2d_Rect(lua_State *L, int idx, cocos2d::Rect *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    luaL_checktype(L, idx, LUA_TTABLE);
    value->origin.x = (float)olua_checkfieldnumber(L, idx, "x");
    value->origin.y = (float)olua_checkfieldnumber(L, idx, "y");
    value->size.width = (float)olua_checkfieldnumber(L, idx, "width");
    value->size.height = (float)olua_checkfieldnumber(L, idx, "height");
}

void auto_luacv_pack_cocos2d_Rect(lua_State *L, int idx, cocos2d::Rect *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    value->origin.x = (int)luaL_checkinteger(L, idx + 0);
    value->origin.y = (int)luaL_checkinteger(L, idx + 1);
    value->size.width = (int)luaL_checkinteger(L, idx + 2);
    value->size.height = (int)luaL_checkinteger(L, idx + 3);
}

int auto_luacv_unpack_cocos2d_Rect(lua_State *L, const cocos2d::Rect *value)
{
    if (value) {
        lua_pushnumber(L, value->origin.x);
        lua_pushnumber(L, value->origin.y);
        lua_pushnumber(L, value->size.width);
        lua_pushnumber(L, value->size.height);
    } else {
        for (int i = 0; i < 4; i++) {
            lua_pushnil(L);
        }
    }
    return 4;
}

bool auto_luacv_is_cocos2d_Rect(lua_State *L, int idx)
{
    return lua_istable(L, idx);
}]]

return M