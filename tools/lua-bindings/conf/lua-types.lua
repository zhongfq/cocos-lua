module "types"

output_dir "../../frameworks/cclua/src/lua-bindings"

api_dir"../../addons/cclua/olua"

headers [[
#include "cclua/olua-2dx.h"
]]

import "olua/lua-types.lua"