require "olua.tools"

autoconf 'conf/clang-args.lua'

autoconf 'conf/lua-conv.lua'
autoconf 'conf/lua-cocos2d.lua'
autoconf 'conf/lua-cocos2d-physics.lua'
autoconf 'conf/lua-cocos2d-ui.lua'
autoconf 'conf/lua-fairygui.lua'
autoconf 'conf/lua-dragonbones.lua'
autoconf 'conf/lua-spine.lua'
autoconf 'conf/lua-xgame.lua'
autoconf 'conf/plugin-alipay.lua'
autoconf 'conf/plugin-apple.lua'
autoconf 'conf/plugin-bugly.lua'
autoconf 'conf/plugin-huawei.lua'
autoconf 'conf/plugin-jiguang.lua'
autoconf 'conf/plugin-oppo.lua'
autoconf 'conf/plugin-talkingdata.lua'
autoconf 'conf/plugin-vivo.lua'
autoconf 'conf/plugin-wechat.lua'

dofile 'autobuild/make.lua'