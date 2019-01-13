//
// $id: packet.h zhongfq $
//

#ifndef __PACKET_H__
#define __PACKET_H__

#ifdef __cplusplus
extern "C" {
#endif
    
#include "lua.h"
#include "lauxlib.h"

LUALIB_API int luaopen_packet(lua_State *L);

#ifdef __cplusplus
}
#endif

#endif
