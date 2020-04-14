local autoconf = require "autoconf"
local M = autoconf.typemod 'dragonbones'
local typeconf = M.typeconf
local typeconv = M.typeconv

M.PATH = "../../frameworks/libxgame/src/lua-bindings"
M.INCLUDES = [[
#include "lua-bindings/lua_dragonbones.h"
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "xgame/xlua.h"
#include "cocos2d.h"
#include "CCDragonBonesHeaders.h"
]]
M.CHUNK = [[]]

typeconv 'dragonBones::Rectangle'

M.MAKE_LUACLS = function (cppname)
    cppname = string.gsub(cppname, "^dragonBones::CC", "db.")
    cppname = string.gsub(cppname, "^dragonBones::", "db.")
    cppname = string.gsub(cppname, "::", ".")
    return cppname
end

M.EXCLUDE_TYPE = require "conf.exclude-type"
M.EXCLUDE_TYPE 'dragonBones::Matrix *'
M.EXCLUDE_TYPE 'dragonBones::Matrix'
M.EXCLUDE_TYPE 'dragonBones::WorldClock'
M.EXCLUDE_TYPE 'dragonBones::Transform *'
M.EXCLUDE_TYPE 'dragonBones::Transform'
M.EXCLUDE_TYPE 'dragonBones::Point'
M.EXCLUDE_TYPE 'dragonBones::ColorTransform'
M.EXCLUDE_TYPE 'dragonBones::ColorTransform *'
M.EXCLUDE_TYPE 'dragonBones::Rectangle *'
M.EXCLUDE_TYPE 'dragonBones::MeshDisplayData *'
M.EXCLUDE_TYPE 'dragonBones::CanvasData *'
M.EXCLUDE_TYPE 'dragonBones::IArmatureProxy *'
M.EXCLUDE_TYPE 'dragonBones::IEventDispatcher *'
M.EXCLUDE_TYPE 'std::vector *'

M.EXCLUDE_PASS = function (cppcls, fn, decl)
    return string.find(fn, '^_') or string.find(decl, 'std::map')
end

typeconf 'dragonBones::BinaryOffset'
typeconf 'dragonBones::ArmatureType'
typeconf 'dragonBones::OffsetMode'
typeconf 'dragonBones::DisplayType'
typeconf 'dragonBones::BoundingBoxType'
typeconf 'dragonBones::ActionType'
typeconf 'dragonBones::BlendMode'
typeconf 'dragonBones::TweenType'
typeconf 'dragonBones::TimelineType'
typeconf 'dragonBones::AnimationFadeOutMode'
typeconf 'dragonBones::TextureFormat'

typeconf 'dragonBones::BaseObject'
typeconf 'dragonBones::EventObject'
typeconf 'dragonBones::TransformObject'
typeconf 'dragonBones::Point'
typeconf 'dragonBones::ConstraintData'
typeconf 'dragonBones::IKConstraintData'
typeconf 'dragonBones::TimelineData'

typeconf 'dragonBones::IAnimatable'
typeconf 'dragonBones::WorldClock'

typeconf 'dragonBones::Slot'
    .EXCLUDE 'getDisplayList'
    .EXCLUDE 'setDisplayList'

typeconf 'dragonBones::Bone'
typeconf 'dragonBones::DisplayData'
typeconf 'dragonBones::ActionData'
typeconf 'dragonBones::UserData'
typeconf 'dragonBones::BoundingBoxData'
typeconf 'dragonBones::BoundingBoxDisplayData'
typeconf 'dragonBones::CanvasData'

typeconf 'dragonBones::TextureAtlasData'
    .EXCLUDE 'copyFrom'

typeconf 'dragonBones::TextureData'
    .EXCLUDE 'copyFrom'

typeconf 'dragonBones::ArmatureData'
typeconf 'dragonBones::SkinData'
typeconf 'dragonBones::BoneData'
typeconf 'dragonBones::SlotData'
typeconf 'dragonBones::AnimationState'
typeconf 'dragonBones::AnimationData'
typeconf 'dragonBones::AnimationConfig'
typeconf 'dragonBones::DragonBonesData'

typeconf 'dragonBones::BaseFactory'

local Armature = typeconf 'dragonBones::Armature'
Armature.SUPERCLS = 'dragonBones::BaseObject'

typeconf 'dragonBones::Animation'
typeconf 'dragonBones::CCFactory'

typeconf 'dragonBones::CCArmatureDisplay'
    .CALLBACK {
        NAME = 'addDBEventListener',
        TAG_MAKER = '(#1)',
        TAG_MODE = 'OLUA_TAG_NEW',
    }
    .CALLBACK {
        NAME = 'removeDBEventListener',
        TAG_MAKER = '(#1)',
        TAG_MODE = 'OLUA_TAG_SUBEQUAL',
        NULLABLE = true,
    }

return M