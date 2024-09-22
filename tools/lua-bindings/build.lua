package.path = "./?/init.lua;" .. package.path

require "olua"

autoconf 'conf/clang-args.lua'
autoconf 'conf/exclude-type.lua'

autoconf 'conf/lua-types.lua'
autoconf 'conf/lua-cocos2d-types.lua'
autoconf 'conf/lua-cocos2d.lua'
autoconf 'conf/lua-cocos2d-action.lua'
autoconf 'conf/lua-cocos2d-studio.lua'
autoconf 'conf/lua-cocos2d-3d.lua'
autoconf 'conf/lua-cocos2d-backend.lua'
autoconf 'conf/lua-cocos2d-physics.lua'
autoconf 'conf/lua-cocos2d-ui.lua'
autoconf 'conf/lua-box2d.lua'
autoconf 'conf/lua-fairygui.lua'
autoconf 'conf/lua-dragonbones.lua'
autoconf 'conf/lua-spine.lua'
autoconf 'conf/lua-cclua.lua'
autoconf 'conf/plugin-alipay.lua'
autoconf 'conf/plugin-apple.lua'
autoconf 'conf/plugin-bugly.lua'
autoconf 'conf/plugin-huawei.lua'
autoconf 'conf/plugin-janalytics.lua'
autoconf 'conf/plugin-jauth.lua'
autoconf 'conf/plugin-jpush.lua'
autoconf 'conf/plugin-oppo.lua'
autoconf 'conf/plugin-talkingdata.lua'
autoconf 'conf/plugin-vivo.lua'
autoconf 'conf/plugin-wechat.lua'