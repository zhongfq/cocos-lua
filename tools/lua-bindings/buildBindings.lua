require "olua.tools.olua"

local olua = require "olua"
local export = olua.export

require 'autobuild.alias-types'
require 'autobuild.cocos2d-types'
require 'autobuild.cocos2d-physics-types'
require 'autobuild.cocos2d-ui-types'

export 'autobuild/conv.lua'
export 'autobuild/cocos2d.lua'
export 'autobuild/cocos2d-physics.lua'
export 'autobuild/cocos2d-ui.lua'
export 'autobuild/fairygui.lua'
export 'autobuild/dragonbones.lua'
export 'autobuild/spine.lua'
export 'autobuild/xgame.lua'

-- local checkref = olua.checkref
-- checkref {
--     REF = {'cocos2d::Node *', 'cocos2d::Action *'}
-- }