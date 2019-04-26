#include "lua_wechat.h"

#if CC_TARGET_PLATFORM != CC_PLATFORM_IOS
int luaopen_wechat(lua_State *L)
{
    xlua_createnonsupport(L, lua_tostring(L, 1));
    return 1;
}
#endif
