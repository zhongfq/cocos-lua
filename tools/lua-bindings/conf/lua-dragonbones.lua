module 'dragonbones'

output_dir "../../frameworks/cclua/src/lua-bindings"

headers [[
#include "lua-bindings/lua_cocos2d_types.h"
#include "lua-bindings/lua_conv_manual.h"
#include "cocos2d.h"
#include "CCDragonBonesHeaders.h"
]]

luaopen [[cclua::runtime::registerFeature("dragonbones", true);]]

luacls(function (cppname)
    cppname = string.gsub(cppname, "^dragonBones::CC", "db.")
    cppname = string.gsub(cppname, "^dragonBones::", "db.")
    cppname = string.gsub(cppname, "::", ".")
    return cppname
end)

exclude_type 'dragonBones::Matrix'
exclude_type 'dragonBones::Transform'
exclude_type 'dragonBones::ColorTransform'
exclude_type 'dragonBones::MeshDisplayData'

typeconf 'dragonBones::Rectangle'

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

typeconf 'dragonBones::DragonBones'
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
    .exclude '_updateVisible'
    .exclude '_updateBlendMode'
    .exclude '_updateColor'
    .exclude '_setDisplayIndex'
    .exclude '_setZorder'
    .exclude '_setDisplayList'
    .exclude 'getRawDisplayDatas'
    .exclude 'setRawDisplayDatas'

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
    .exclude 'displays'
    .exclude 'getDisplays'
    .exclude 'getSlotDisplays'

typeconf 'dragonBones::BoneData'
typeconf 'dragonBones::SlotData'
typeconf 'dragonBones::AnimationState'

typeconf 'dragonBones::AnimationData'
    .exclude 'boneCachedFrameIndices'
    .exclude 'boneTimelines'
    .exclude 'constraintTimelines'
    .exclude 'getBoneTimelines'
    .exclude 'getConstraintTimelines'
    .exclude 'getBoneCachedFrameIndices'
    .exclude 'getSlotCachedFrameIndices'
    .exclude 'getSlotTimelines'
    .exclude 'slotCachedFrameIndices'
    .exclude 'slotTimelines'

typeconf 'dragonBones::AnimationConfig'
typeconf 'dragonBones::DragonBonesData'
    .exclude 'getFrameIndices'

typeconf 'dragonBones::BaseFactory'
    .exclude 'getAllTextureAtlasData'
    .exclude 'getTextureAtlasData'

typeconf 'dragonBones::Armature'
    .exclude '_addBone'
    .exclude '_addConstraint'
    .exclude '_addSlot'
    .exclude '_bufferAction'

typeconf 'dragonBones::Animation'
typeconf 'dragonBones::CCFactory'

typeconf 'dragonBones::IEventDispatcher'
typeconf 'dragonBones::IArmatureProxy'
typeconf 'dragonBones::CCArmatureDisplay'
    .func 'addDBEventListener'
        .tag_maker '(#1)'
        .tag_mode 'new'
    .func 'removeDBEventListener'
        .arg2 '@nullable'
        .tag_maker '(#1)'
        .tag_mode 'equal'