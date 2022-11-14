#include "lua_manual.h"
#include "lua_conv_manual.h"
#include "lua_conv.h"

static int _cocos2d_Value_get_Null(lua_State *L)
{
    olua_pushobj<cocos2d::Value>(L, &cocos2d::Value::Null);
    return 1;
}

int luaopen_cocos2d_Value(lua_State *L)
{
    oluacls_class(L, "cc.Value", NULL);
    oluacls_prop(L, "Null", _cocos2d_Value_get_Null, NULL);
    olua_registerluatype<cocos2d::Value>(L, "cc.Value");
    return 1;
}

int luaopen_manual(lua_State *L)
{
    olua_require(L, "cc.Value", luaopen_cocos2d_Value);
    return 0;
}
