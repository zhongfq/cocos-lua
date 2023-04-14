module "types"

path "../../frameworks/cclua/src/lua-bindings"

headers [[
#include "cclua/olua-2dx.h"
]]

import "olua/lua-types.lua"