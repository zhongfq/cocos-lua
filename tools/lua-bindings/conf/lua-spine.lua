module 'spine'

output_dir "../../frameworks/cclua/src/lua-bindings"

api_dir"../../addons/cclua/spine"

headers [[
#include "lua-bindings/lua_cocos2d_types.h"
#include "lua-bindings/lua_conv_manual.h"
#include "cocos2d.h"
#include "spine/spine-cocos2dx.h"
]]

luaopen [[cclua::runtime::registerFeature("spine", true);]]

exclude_type 'spine::HasRendererObject'
exclude_type 'spine::RTTI'
exclude_type 'spine::Interpolation'
exclude_type 'spine::Vector *'
exclude_type 'spine::AnimationStateListenerObject'

local function typeenum(classname)
    local cls = typeconf(classname)
    local cppname = string.match(classname, '[^:]+$')
    cls.luaname(function (value)
        return value:gsub('^' .. cppname .. '_', '')
    end)
    return cls
end

typedef 'spine::String'
    .conv 'olua_$$_string'
typedef 'spine::Color'
typedef 'spine::Vector'
    .conv 'olua_$$_array'

typeenum 'spine::EventType'
typeenum 'spine::AttachmentType'
typeenum 'spine::BlendMode'
typeenum 'spine::PositionMode'
typeenum 'spine::SpacingMode'
typeenum 'spine::RotateMode'
typeenum 'spine::MixBlend'
typeenum 'spine::MixDirection'
typeenum 'spine::Physics'
typeenum 'spine::Inherit'

typeconf 'spine::SpineObject'

typeconf 'spine::Event'
    .exclude 'Event'

typeconf 'spine::EventData'
typeconf 'spine::Updatable'
typeconf 'spine::AnimationStateListener'

typeconf 'spine::AnimationState'
    .func 'setListener' .tag_usepool 'false'

typeconf 'spine::AnimationStateData'
typeconf 'spine::Animation'
typeconf 'spine::Sequence'
typeconf 'spine::SequenceMode'
typeconf 'spine::TextureRegion'
typeconf 'spine::ConstraintData'
typeconf 'spine::IkConstraintData'
typeconf 'spine::BoneData'
typeconf 'spine::SlotData'
typeconf 'spine::IkConstraint'
typeconf 'spine::TransformConstraint'
typeconf 'spine::TransformConstraintData'
typeconf 'spine::PathConstraintData'
typeconf 'spine::SkeletonBounds'
typeonly 'spine::SkeletonClipping'
typeonly 'spine::PhysicsConstraint'
typeonly 'spine::PhysicsConstraintData'

typeconf 'spine::Timeline'
    .exclude 'apply'
    .exclude 'setFrame'
    .exclude 'getVertices'
    .exclude 'getDrawOrders'
    .exclude 'getEvents'

typeconf 'spine::CurveTimeline'
typeconf 'spine::CurveTimeline1'
typeconf 'spine::CurveTimeline2'
typeconf 'spine::AttachmentTimeline'
typeconf 'spine::RGBATimeline'
typeconf 'spine::RGBTimeline'
typeconf 'spine::AlphaTimeline'
typeconf 'spine::RGBA2Timeline'
typeconf 'spine::RGB2Timeline'
typeconf 'spine::DeformTimeline'
typeconf 'spine::DrawOrderTimeline'
typeconf 'spine::EventTimeline'
typeconf 'spine::ScaleXTimeline'
typeconf 'spine::ScaleYTimeline'
typeconf 'spine::ShearXTimeline'
typeconf 'spine::ShearYTimeline'
typeconf 'spine::TranslateXTimeline'
typeconf 'spine::TranslateYTimeline'
typeconf 'spine::IkConstraintTimeline'
typeconf 'spine::PathConstraintMixTimeline'
typeconf 'spine::PathConstraintPositionTimeline'
typeconf 'spine::PathConstraintSpacingTimeline'
typeconf 'spine::TranslateTimeline'
typeconf 'spine::ShearTimeline'
typeconf 'spine::TransformConstraintTimeline'
typeconf 'spine::ScaleTimeline'
typeconf 'spine::RotateTimeline'

typeonly 'spine::Polygon'

typeconf 'spine::Skin'
    .exclude 'getAttachments'
    .exclude 'findNamesForSlot'
    .exclude 'findAttachmentsForSlot'

typeonly 'spine::Atlas'

typeconf 'spine::Bone'
    .exclude 'localToWorld'
    .exclude 'worldToLocal'

typeconf 'spine::Slot'
typeconf 'spine::Attachment'
typeconf 'spine::VertexAttachment'
typeconf 'spine::ClippingAttachment'
typeconf 'spine::BoundingBoxAttachment'
typeconf 'spine::MeshAttachment'
typeconf 'spine::PathAttachment'
typeconf 'spine::PathConstraint'
typeconf 'spine::PointAttachment'
typeconf 'spine::RegionAttachment'

typeconf 'spine::TrackEntry'
    .func 'setListener' .tag_usepool 'false'

typeconf 'spine::SkeletonData'
    .exclude 'new'
    .extend 'spine::SkeletonDataExtend'

typeconf 'spine::Skeleton'
    .exclude 'getBounds'

typeconf 'spine::SkeletonRenderer'
    .func 'createWithData' .arg1 '@addref(skeletonData ^)'

typeconf 'spine::StartListener'
typeconf 'spine::InterruptListener'
typeconf 'spine::EndListener'
typeconf 'spine::DisposeListener'
typeconf 'spine::CompleteListener'
typeconf 'spine::EventListener'
typeconf 'spine::UpdateWorldTransformsListener'

typeconf 'spine::SkeletonAnimation'
    .func 'createWithData' .arg1 '@addref(skeletonData ^)'
    .func 'getState' .ret '@addref(state ^)'
    .func 'setAnimation' .ret '@addref(trackEntries |)'
    .func 'addAnimation' .ret '@addref(trackEntries |)'
    .func 'setEmptyAnimation' .ret '@addref(trackEntries |)'
    .func 'addEmptyAnimation' .ret '@addref(trackEntries |)'
    .func 'getCurrent' .ret '@addref(trackEntries |)'
    .func 'setStartListener' .tag_usepool 'false'
    .func 'setInterruptListener' .tag_usepool 'false'
    .func 'setEndListener' .tag_usepool 'false'
    .func 'setDisposeListener' .tag_usepool 'false'
    .func 'setCompleteListener' .tag_usepool 'false'
    .func 'setEventListener' .tag_usepool 'false'
    .func 'setTrackStartListener' .tag_usepool 'false'
    .func 'setTrackInterruptListener' .tag_usepool 'false'
    .func 'setTrackEndListener' .tag_usepool 'false'
    .func 'setTrackDisposeListener' .tag_usepool 'false'
    .func 'setTrackCompleteListener' .tag_usepool 'false'
    .func 'setTrackEventListener' .tag_usepool 'false'
