require "aux.tolua-aux"
require "aux.tolua-cls"
require "aux.tolua-arg-type"
require "aux.tolua-gen-header"
require "aux.tolua-gen-source"
require "aux.tolua-gen-class"
require "aux.tolua-gen-class-func"

PROJECT_ROOT = '../../'

function gen_module(module)
    gen_header(module)
    gen_source(module)
end

gen_module(require("conf.lua-xgame"))
gen_module(require("conf.lua-cocos2d"))