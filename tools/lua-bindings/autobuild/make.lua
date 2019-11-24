local olua = require "olua"
local export = olua.export
local typedef = olua.typedef

dofile "autobuild/alias-types.lua"
dofile "autobuild/conv-types.lua"
dofile "autobuild/cocos2d-types.lua"
dofile "autobuild/cocos2d-physics-types.lua"
dofile "autobuild/cocos2d-ui-types.lua"
dofile "autobuild/fairygui-types.lua"
dofile "autobuild/dragonbones-types.lua"
dofile "autobuild/spine-types.lua"
dofile "autobuild/xgame-types.lua"

export "autobuild/conv.lua"
export "autobuild/cocos2d.lua"
export "autobuild/cocos2d-physics.lua"
export "autobuild/cocos2d-ui.lua"
export "autobuild/fairygui.lua"
export "autobuild/dragonbones.lua"
export "autobuild/spine.lua"
export "autobuild/xgame.lua"