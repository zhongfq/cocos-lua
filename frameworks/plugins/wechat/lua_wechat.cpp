#include "lua_wechat.h"

#if CC_TARGET_PLATFORM != CC_PLATFORM_IOS
int luaopen_wechat(lua_State *L)
{
    return 0;
}
#endif
