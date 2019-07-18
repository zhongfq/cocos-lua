local olua = require "olua"
local typedef = olua.typedef

olua.nowarning(typedef)

typedef {
    CONV_FUNC = 'manual_olua_$$_spine_String',
    CPPCLS = 'spine::String',
}

typedef {
    CONV_FUNC = 'manual_olua_$$_spine_EventData',
    CPPCLS = 'spine::EventData',
}

typedef {
    CONV_FUNC = 'manual_olua_$$_spine_Color',
    CPPCLS = 'spine::Color',
}

typedef {
    CONV_FUNC = 'manual_olua_$$_spine_Vector',
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
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'sp.AttachmentType',
}

typedef {
    CPPCLS = 'spine::BlendMode',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'sp.BlendMode',
}

typedef {
    CPPCLS = 'spine::EventType',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'sp.EventType',
}

typedef {
    CPPCLS = 'spine::MixBlend',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'sp.MixBlend',
}

typedef {
    CPPCLS = 'spine::PositionMode',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'sp.PositionMode',
}

typedef {
    CPPCLS = 'spine::RotateMode',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'sp.RotateMode',
}

typedef {
    CPPCLS = 'spine::SpacingMode',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'sp.SpacingMode',
}

typedef {
    CPPCLS = 'spine::TransformMode',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'sp.TransformMode',
}

typedef {
    CPPCLS = 'spine::Animation *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.Animation',
}

typedef {
    CPPCLS = 'spine::AnimationState *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.AnimationState',
}

typedef {
    CPPCLS = 'spine::AnimationStateData *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.AnimationStateData',
}

typedef {
    CPPCLS = 'spine::Atlas *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.Atlas',
}

typedef {
    CPPCLS = 'spine::Attachment *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.Attachment',
}

typedef {
    CPPCLS = 'spine::AttachmentTimeline *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.AttachmentTimeline',
}

typedef {
    CPPCLS = 'spine::Bone *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.Bone',
}

typedef {
    CPPCLS = 'spine::BoneData *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.BoneData',
}

typedef {
    CPPCLS = 'spine::BoundingBoxAttachment *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.BoundingBoxAttachment',
}

typedef {
    CPPCLS = 'spine::ClippingAttachment *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.ClippingAttachment',
}

typedef {
    CPPCLS = 'spine::ColorTimeline *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.ColorTimeline',
}

typedef {
    CPPCLS = 'spine::ConstraintData *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.ConstraintData',
}

typedef {
    CPPCLS = 'spine::CurveTimeline *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.CurveTimeline',
}

typedef {
    CPPCLS = 'spine::DeformTimeline *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.DeformTimeline',
}

typedef {
    CPPCLS = 'spine::DrawOrderTimeline *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.DrawOrderTimeline',
}

typedef {
    CPPCLS = 'spine::Event *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.Event',
}

typedef {
    CPPCLS = 'spine::EventData *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.EventData',
}

typedef {
    CPPCLS = 'spine::EventTimeline *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.EventTimeline',
}

typedef {
    CPPCLS = 'spine::IkConstraint *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.IkConstraint',
}

typedef {
    CPPCLS = 'spine::IkConstraintData *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.IkConstraintData',
}

typedef {
    CPPCLS = 'spine::IkConstraintTimeline *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.IkConstraintTimeline',
}

typedef {
    CPPCLS = 'spine::JitterVertexEffect *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.JitterVertexEffect',
}

typedef {
    CPPCLS = 'spine::MeshAttachment *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.MeshAttachment',
}

typedef {
    CPPCLS = 'spine::PathAttachment *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.PathAttachment',
}

typedef {
    CPPCLS = 'spine::PathConstraint *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.PathConstraint',
}

typedef {
    CPPCLS = 'spine::PathConstraintData *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.PathConstraintData',
}

typedef {
    CPPCLS = 'spine::PathConstraintMixTimeline *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.PathConstraintMixTimeline',
}

typedef {
    CPPCLS = 'spine::PathConstraintPositionTimeline *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.PathConstraintPositionTimeline',
}

typedef {
    CPPCLS = 'spine::PathConstraintSpacingTimeline *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.PathConstraintSpacingTimeline',
}

typedef {
    CPPCLS = 'spine::PointAttachment *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.PointAttachment',
}

typedef {
    CPPCLS = 'spine::Polygon *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.Polygon',
}

typedef {
    CPPCLS = 'spine::RegionAttachment *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.RegionAttachment',
}

typedef {
    CPPCLS = 'spine::RotateTimeline *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.RotateTimeline',
}

typedef {
    CPPCLS = 'spine::ScaleTimeline *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.ScaleTimeline',
}

typedef {
    CPPCLS = 'spine::ShearTimeline *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.ShearTimeline',
}

typedef {
    CPPCLS = 'spine::Skeleton *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.Skeleton',
}

typedef {
    CPPCLS = 'spine::SkeletonAnimation *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.SkeletonAnimation',
}

typedef {
    CPPCLS = 'spine::SkeletonBounds *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.SkeletonBounds',
}

typedef {
    CPPCLS = 'spine::SkeletonClipping *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.SkeletonClipping',
}

typedef {
    CPPCLS = 'spine::SkeletonData *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.SkeletonData',
}

typedef {
    CPPCLS = 'spine::SkeletonRenderer *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.SkeletonRenderer',
}

typedef {
    CPPCLS = 'spine::Skin *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.Skin',
}

typedef {
    CPPCLS = 'spine::Slot *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.Slot',
}

typedef {
    CPPCLS = 'spine::SlotData *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.SlotData',
}

typedef {
    CPPCLS = 'spine::SpineObject *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.SpineObject',
}

typedef {
    CPPCLS = 'spine::SwirlVertexEffect *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.SwirlVertexEffect',
}

typedef {
    CPPCLS = 'spine::Timeline *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.Timeline',
}

typedef {
    CPPCLS = 'spine::TrackEntry *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.TrackEntry',
}

typedef {
    CPPCLS = 'spine::TransformConstraint *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.TransformConstraint',
}

typedef {
    CPPCLS = 'spine::TransformConstraintData *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.TransformConstraintData',
}

typedef {
    CPPCLS = 'spine::TransformConstraintTimeline *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.TransformConstraintTimeline',
}

typedef {
    CPPCLS = 'spine::TranslateTimeline *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.TranslateTimeline',
}

typedef {
    CPPCLS = 'spine::TwoColorTimeline *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.TwoColorTimeline',
}

typedef {
    CPPCLS = 'spine::Updatable *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.Updatable',
}

typedef {
    CPPCLS = 'spine::VertexAttachment *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.VertexAttachment',
}

typedef {
    CPPCLS = 'spine::VertexEffect *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.VertexEffect',
}

