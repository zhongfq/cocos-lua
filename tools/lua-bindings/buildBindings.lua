local olua = require "olua.tools.olua"
local export = olua.export

require 'autobuild.alias-types'
require 'autobuild.conv-types'
require 'autobuild.cocos2d-types'
require 'autobuild.cocos2d-action-types'
require 'autobuild.cocos2d-backend-types'
require 'autobuild.cocos2d-physics-types'
require 'autobuild.cocos2d-ui-types'

export 'autobuild/conv.lua'
export 'autobuild/cocos2d.lua'
export 'autobuild/cocos2d-action.lua'
export 'autobuild/cocos2d-3d.lua'
export 'autobuild/cocos2d-backend.lua'
export 'autobuild/cocos2d-physics.lua'
export 'autobuild/cocos2d-ui.lua'
export 'autobuild/fairygui.lua'
export 'autobuild/dragonbones.lua'
export 'autobuild/spine.lua'
export 'autobuild/xgame.lua'

-- require "autobuild.make"

-- local checkref = olua.checkref
-- checkref {
--     REF = {'cocos2d::Node *', 'cocos2d::Action *'}
-- }