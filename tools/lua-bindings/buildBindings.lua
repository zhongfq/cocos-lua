require "olua.olua-aux"
require "olua.olua-cls"
require "olua.olua-arg-type"
require "olua.olua-gen-header"
require "olua.olua-gen-source"
require "olua.olua-gen-class"
require "olua.olua-gen-class-func"
require "olua.olua-gen-callback"
require "olua.olua-gen-conv"

require 'autobuild.cocos2d-types'
require 'autobuild.cocos2d-ui-types'

PROJECT_ROOT = '../../'

function gen_module(module)
    gen_header(module)
    gen_source(module)
end

gen_conv(require("conf.lua-conv"))
gen_module(require("autobuild.cocos2d"))
gen_module(require("autobuild.cocos2d-ui"))
gen_module(require("autobuild.fairygui"))
gen_module(require("autobuild.dragonbones"))
gen_module(require("autobuild.spine"))
gen_module(require("autobuild.xgame"))