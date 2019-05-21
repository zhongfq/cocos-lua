require "core.olua-aux"
require "core.olua-cls"
require "core.olua-arg-type"
require "core.olua-gen-header"
require "core.olua-gen-source"
require "core.olua-gen-class"
require "core.olua-gen-class-func"
require "core.olua-gen-callback"
require "core.olua-gen-conv"

require "conf.lua-ref"

PROJECT_ROOT = '../../'

function gen_module(module)
    gen_header(module)
    gen_source(module)
end

gen_conv(require("conf.lua-conv"))
gen_module(require("conf.cocos2d.lua-cocos2d"))
gen_module(require("conf.cocos2d.lua-cocos2d-ui"))
gen_module(require("conf.cocos2d.lua-spine"))
gen_module(require("conf.cocos2d.lua-dragonbones"))
gen_module(require("conf.fairygui.lua-fairygui"))
gen_module(require("conf.xgame.lua-xgame"))