require "bindings-generator.src.olua"

local autoconf = require "autoconf"

autoconf.init 'conf/clang-args.lua'

autoconf 'conf/lua-conv.lua'
autoconf 'conf/lua-cocos2d.lua'
autoconf 'conf/lua-cocos2d-physics.lua'
autoconf 'conf/lua-cocos2d-ui.lua'
autoconf 'conf/lua-fairygui.lua'
autoconf 'conf/lua-dragonbones.lua'
autoconf 'conf/lua-spine.lua'
autoconf 'conf/lua-xgame.lua'