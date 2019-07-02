require "olua.olua-aux"
require "olua.olua-cls"
require "olua.olua-arg-type"
require "olua.olua-gen-header"
require "olua.olua-gen-source"
require "olua.olua-gen-class"
require "olua.olua-gen-class-func"
require "olua.olua-gen-callback"
require "olua.olua-gen-conv"

require "conf.lua-ref"

require "olua.olua-cls"
require "conf.cocos2d.import-cocos2d-type"


PROJECT_ROOT = '../../'

function gen_module(module)
    gen_header(module)
    gen_source(module)
end

gen_module(require("autoconf.cocos2d"))

-- gen_conv(require("conf.lua-conv"))
-- gen_module(require("conf.cocos2d.lua-cocos2d"))
-- gen_module(require("conf.cocos2d.lua-cocos2d-ui"))
-- gen_module(require("conf.cocos2d.lua-spine"))
-- gen_module(require("conf.cocos2d.lua-dragonbones"))
-- gen_module(require("conf.fairygui.lua-fairygui"))
-- gen_module(require("conf.xgame.lua-xgame"))