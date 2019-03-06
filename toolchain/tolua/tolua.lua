require "aux.tolua-aux"
require "aux.tolua-cls"
require "aux.tolua-arg-type"
require "aux.tolua-gen-header"
require "aux.tolua-gen-source"
require "aux.tolua-gen-class"
require "aux.tolua-gen-class-func"
require "aux.tolua-gen-conv"

PROJECT_ROOT = '../../'

function gen_module(module)
    gen_header(module)
    gen_source(module)
end

gen_conv(require("conf.lua-conv"))
gen_module(require("conf.cocos2d.lua-cocos2d"))
gen_module(require("conf.xgame.lua-xgame"))