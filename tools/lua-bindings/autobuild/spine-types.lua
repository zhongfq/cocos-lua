-- AUTO BUILD, DON'T MODIFY!

local olua = require "olua"
local typedef = olua.typedef

olua.nowarning(typedef)

typedef {
    CONV = 'manual_olua_$$_spine_String',
    CPPCLS = 'spine::String',
}

typedef {
    CONV = 'manual_olua_$$_spine_EventData',
    CPPCLS = 'spine::EventData',
}

typedef {
    CONV = 'manual_olua_$$_spine_Color',
    CPPCLS = 'spine::Color',
}

typedef {
    CONV = 'manual_olua_$$_spine_Vector',
    CPPCLS = 'spine::Vector',
    PUSH_VALUETYPE = [[
        int ${ARG_NAME}_size = (int)${ARG_NAME}.size();
        lua_createtable(L, ${ARG_NAME}_size, 0);
        for (int i = 0; i < ${ARG_NAME}_size; i++) {
            ${SUBTYPE_PUSH_FUNC}(L, ${SUBTYPE_CAST}((${TYPE_CAST})${ARG_NAME})[i]);
            lua_rawseti(L, -2, i + 1);
        }
    ]],
}

typedef {
    CPPCLS = 'spine::AttachmentType',
    DECLTYPE = 'lua_Unsigned',
    CONV = 'olua_$$_uint',
    LUACLS = 'sp.AttachmentType',
}

typedef {
    CPPCLS = 'spine::BlendMode',
    DECLTYPE = 'lua_Unsigned',
    CONV = 'olua_$$_uint',
    LUACLS = 'sp.BlendMode',
}

typedef {
    CPPCLS = 'spine::EventType',
    DECLTYPE = 'lua_Unsigned',
    CONV = 'olua_$$_uint',
    LUACLS = 'sp.EventType',
}

typedef {
    CPPCLS = 'spine::MixBlend',
    DECLTYPE = 'lua_Unsigned',
    CONV = 'olua_$$_uint',
    LUACLS = 'sp.MixBlend',
}

typedef {
    CPPCLS = 'spine::PositionMode',
    DECLTYPE = 'lua_Unsigned',
    CONV = 'olua_$$_uint',
    LUACLS = 'sp.PositionMode',
}

typedef {
    CPPCLS = 'spine::RotateMode',
    DECLTYPE = 'lua_Unsigned',
    CONV = 'olua_$$_uint',
    LUACLS = 'sp.RotateMode',
}

typedef {
    CPPCLS = 'spine::SpacingMode',
    DECLTYPE = 'lua_Unsigned',
    CONV = 'olua_$$_uint',
    LUACLS = 'sp.SpacingMode',
}

typedef {
    CPPCLS = 'spine::TransformMode',
    DECLTYPE = 'lua_Unsigned',
    CONV = 'olua_$$_uint',
    LUACLS = 'sp.TransformMode',
}

typedef {
    CPPCLS = 'spine::Animation *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'sp.Animation',
}

typedef {
    CPPCLS = 'spine::AnimationState *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'sp.AnimationState',
}

typedef {
    CPPCLS = 'spine::AnimationStateData *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'sp.AnimationStateData',
}

typedef {
    CPPCLS = 'spine::Atlas *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'sp.Atlas',
}

typedef {
    CPPCLS = 'spine::Attachment *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'sp.Attachment',
}

typedef {
    CPPCLS = 'spine::AttachmentTimeline *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'sp.AttachmentTimeline',
}

typedef {
    CPPCLS = 'spine::Bone *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'sp.Bone',
}

typedef {
    CPPCLS = 'spine::BoneData *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'sp.BoneData',
}

typedef {
    CPPCLS = 'spine::BoundingBoxAttachment *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'sp.BoundingBoxAttachment',
}

typedef {
    CPPCLS = 'spine::ClippingAttachment *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'sp.ClippingAttachment',
}

typedef {
    CPPCLS = 'spine::ColorTimeline *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'sp.ColorTimeline',
}

typedef {
    CPPCLS = 'spine::ConstraintData *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'sp.ConstraintData',
}

typedef {
    CPPCLS = 'spine::CurveTimeline *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'sp.CurveTimeline',
}

typedef {
    CPPCLS = 'spine::DeformTimeline *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'sp.DeformTimeline',
}

typedef {
    CPPCLS = 'spine::DrawOrderTimeline *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'sp.DrawOrderTimeline',
}

typedef {
    CPPCLS = 'spine::Event *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'sp.Event',
}

typedef {
    CPPCLS = 'spine::EventData *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'sp.EventData',
}

typedef {
    CPPCLS = 'spine::EventTimeline *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'sp.EventTimeline',
}

typedef {
    CPPCLS = 'spine::IkConstraint *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'sp.IkConstraint',
}

typedef {
    CPPCLS = 'spine::IkConstraintData *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'sp.IkConstraintData',
}

typedef {
    CPPCLS = 'spine::IkConstraintTimeline *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'sp.IkConstraintTimeline',
}

typedef {
    CPPCLS = 'spine::JitterVertexEffect *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'sp.JitterVertexEffect',
}

typedef {
    CPPCLS = 'spine::MeshAttachment *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'sp.MeshAttachment',
}

typedef {
    CPPCLS = 'spine::PathAttachment *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'sp.PathAttachment',
}

typedef {
    CPPCLS = 'spine::PathConstraint *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'sp.PathConstraint',
}

typedef {
    CPPCLS = 'spine::PathConstraintData *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'sp.PathConstraintData',
}

typedef {
    CPPCLS = 'spine::PathConstraintMixTimeline *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'sp.PathConstraintMixTimeline',
}

typedef {
    CPPCLS = 'spine::PathConstraintPositionTimeline *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'sp.PathConstraintPositionTimeline',
}

typedef {
    CPPCLS = 'spine::PathConstraintSpacingTimeline *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'sp.PathConstraintSpacingTimeline',
}

typedef {
    CPPCLS = 'spine::PointAttachment *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'sp.PointAttachment',
}

typedef {
    CPPCLS = 'spine::Polygon *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'sp.Polygon',
}

typedef {
    CPPCLS = 'spine::RegionAttachment *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'sp.RegionAttachment',
}

typedef {
    CPPCLS = 'spine::RotateTimeline *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'sp.RotateTimeline',
}

typedef {
    CPPCLS = 'spine::ScaleTimeline *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'sp.ScaleTimeline',
}

typedef {
    CPPCLS = 'spine::ShearTimeline *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'sp.ShearTimeline',
}

typedef {
    CPPCLS = 'spine::Skeleton *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'sp.Skeleton',
}

typedef {
    CPPCLS = 'spine::SkeletonAnimation *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'sp.SkeletonAnimation',
}

typedef {
    CPPCLS = 'spine::SkeletonBounds *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'sp.SkeletonBounds',
}

typedef {
    CPPCLS = 'spine::SkeletonClipping *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'sp.SkeletonClipping',
}

typedef {
    CPPCLS = 'spine::SkeletonData *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'sp.SkeletonData',
}

typedef {
    CPPCLS = 'spine::SkeletonRenderer *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'sp.SkeletonRenderer',
}

typedef {
    CPPCLS = 'spine::Skin *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'sp.Skin',
}

typedef {
    CPPCLS = 'spine::Slot *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'sp.Slot',
}

typedef {
    CPPCLS = 'spine::SlotData *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'sp.SlotData',
}

typedef {
    CPPCLS = 'spine::SpineObject *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'sp.SpineObject',
}

typedef {
    CPPCLS = 'spine::SwirlVertexEffect *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'sp.SwirlVertexEffect',
}

typedef {
    CPPCLS = 'spine::Timeline *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'sp.Timeline',
}

typedef {
    CPPCLS = 'spine::TrackEntry *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'sp.TrackEntry',
}

typedef {
    CPPCLS = 'spine::TransformConstraint *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'sp.TransformConstraint',
}

typedef {
    CPPCLS = 'spine::TransformConstraintData *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'sp.TransformConstraintData',
}

typedef {
    CPPCLS = 'spine::TransformConstraintTimeline *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'sp.TransformConstraintTimeline',
}

typedef {
    CPPCLS = 'spine::TranslateTimeline *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'sp.TranslateTimeline',
}

typedef {
    CPPCLS = 'spine::TwoColorTimeline *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'sp.TwoColorTimeline',
}

typedef {
    CPPCLS = 'spine::Updatable *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'sp.Updatable',
}

typedef {
    CPPCLS = 'spine::VertexAttachment *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'sp.VertexAttachment',
}

typedef {
    CPPCLS = 'spine::VertexEffect *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'sp.VertexEffect',
}

