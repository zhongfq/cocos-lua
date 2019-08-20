local olua = require "olua.olua-io"

function olua.genHeader(module)
    local HEADER = string.upper(module.NAME)
    olua.nowarning(HEADER)
    olua.write(module.HEADER_PATH, olua.format([[
        //
        // AUTO BUILD, DON'T MODIFY!
        //
        #ifndef __AUTO_GEN_LUA_${HEADER}_H__
        #define __AUTO_GEN_LUA_${HEADER}_H__

        #include "xgame/xlua.h"

        LUALIB_API int luaopen_${module.NAME}(lua_State *L);

        #endif
    ]]) .. '\n')
end