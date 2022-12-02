module 'spine'

path "../../frameworks/libxgame/src/lua-bindings"

headers [[
#include "lua-bindings/lua_cocos2d_types.h"
#include "lua-bindings/lua_conv_manual.h"
#include "cocos2d.h"
#include "spine/spine-cocos2dx.h"
]]

luaopen [[cclua::runtime::registerFeature("spine", true);]]

excludetype 'spine::HasRendererObject'
excludetype 'spine::RTTI'
excludetype 'spine::Interpolation'
excludetype 'spine::Vector *'
excludetype 'spine::AnimationStateListenerObject'

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
    .conv 'olua_$$_vector'

typeenum 'spine::EventType'
typeenum 'spine::AttachmentType'
typeenum 'spine::TransformMode'
typeenum 'spine::BlendMode'
typeenum 'spine::PositionMode'
typeenum 'spine::SpacingMode'
typeenum 'spine::RotateMode'
typeenum 'spine::MixBlend'
typeenum 'spine::MixDirection'

typeconf 'spine::SpineObject'

typeconf 'spine::Event'
    .exclude 'Event'

typeconf 'spine::EventData'
typeconf 'spine::Updatable'
typeconf 'spine::AnimationStateListener'

typeconf 'spine::AnimationState'
    .callback 'setListener' .localvar 'false'

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
    .callback 'setListener' .localvar 'false'

typeconf 'spine::SkeletonData'
    .exclude 'new'
    .extend 'spine::SkeletonDataExtend'
    .alias '__gc' .to 'dispose'
    .alias 'create' .to 'new'

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
    .callback 'setStartListener' .localvar 'false'
    .callback 'setInterruptListener' .localvar 'false'
    .callback 'setEndListener' .localvar 'false'
    .callback 'setDisposeListener' .localvar 'false'
    .callback 'setCompleteListener' .localvar 'false'
    .callback 'setEventListener' .localvar 'false'
    .callback 'setTrackStartListener' .localvar 'false'
    .callback 'setTrackInterruptListener' .localvar 'false'
    .callback 'setTrackEndListener' .localvar 'false'
    .callback 'setTrackDisposeListener' .localvar 'false'
    .callback 'setTrackCompleteListener' .localvar 'false'
    .callback 'setTrackEventListener' .localvar 'false'
