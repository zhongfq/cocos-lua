require "olua"

require 'autobuild.cocos2d-types'
require 'autobuild.cocos2d-ui-types'

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