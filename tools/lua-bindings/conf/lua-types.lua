module "types"

path "../../frameworks/libxgame/src/lua-bindings"

headers [[
#include "cclua/olua-2dx.h"
]]

include "olua/lua-types.lua"