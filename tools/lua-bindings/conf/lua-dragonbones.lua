module 'dragonbones'

path = "../../frameworks/libxgame/src/lua-bindings"

headers = [[
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "cclua/xlua.h"
#include "cocos2d.h"
#include "CCDragonBonesHeaders.h"
]]

make_luacls = function (cppname)
    cppname = string.gsub(cppname, "^dragonBones::CC", "db.")
    cppname = string.gsub(cppname, "^dragonBones::", "db.")
    cppname = string.gsub(cppname, "::", ".")
    return cppname
end

include "conf/exclude-type.lua"

exclude 'dragonBones::Matrix *'
exclude 'dragonBones::Matrix'
exclude 'dragonBones::WorldClock'
exclude 'dragonBones::Transform *'
exclude 'dragonBones::Transform'
exclude 'dragonBones::Point'
exclude 'dragonBones::ColorTransform'
exclude 'dragonBones::ColorTransform *'
exclude 'dragonBones::Rectangle *'
exclude 'dragonBones::MeshDisplayData *'
exclude 'dragonBones::CanvasData *'
exclude 'dragonBones::IArmatureProxy *'
exclude 'dragonBones::IEventDispatcher *'
exclude 'std::vector *'

typeconv 'dragonBones::Rectangle'

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
    .exclude 'getDisplayList'
    .exclude 'setDisplayList'

typeconf 'dragonBones::Bone'
typeconf 'dragonBones::DisplayData'
typeconf 'dragonBones::ActionData'
typeconf 'dragonBones::UserData'
typeconf 'dragonBones::BoundingBoxData'
typeconf 'dragonBones::BoundingBoxDisplayData'
typeconf 'dragonBones::CanvasData'

typeconf 'dragonBones::TextureAtlasData'
    .exclude 'copyFrom'

typeconf 'dragonBones::TextureData'
    .exclude 'copyFrom'

typeconf 'dragonBones::ArmatureData'

typeconf 'dragonBones::SkinData'
    .exclude 'getSlotDisplays'
    .exclude 'displays'

typeconf 'dragonBones::BoneData'
typeconf 'dragonBones::SlotData'
typeconf 'dragonBones::AnimationState'

typeconf 'dragonBones::AnimationData'
    .exclude 'boneTimelines'
    .exclude 'slotTimelines'
    .exclude 'constraintTimelines'
    .exclude 'boneCachedFrameIndices'
    .exclude 'slotCachedFrameIndices'

typeconf 'dragonBones::AnimationConfig'
typeconf 'dragonBones::DragonBonesData'

typeconf 'dragonBones::BaseFactory'
    .exclude 'getAllTextureAtlasData'

typeconf 'dragonBones::Armature'
    .supercls 'dragonBones::BaseObject'

typeconf 'dragonBones::Animation'
typeconf 'dragonBones::CCFactory'

typeconf 'dragonBones::CCArmatureDisplay'
    .callback {
        name = 'addDBEventListener',
        tag_maker = '(#1)',
        tag_mode = 'OLUA_TAG_NEW',
    }
    .callback {
        name = 'removeDBEventListener',
        tag_maker = '(#1)',
        tag_mode = 'OLUA_TAG_SUBEQUAL',
        nullable = true,
    }