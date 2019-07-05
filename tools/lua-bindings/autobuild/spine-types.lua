REG_TYPE {
    CONV_FUNC = 'manual_luacv_$$_spine_String',
    INIT_VALUE = false,
    TYPENAME = 'spine::String',
}

REG_TYPE {
    CONV_FUNC = 'manual_luacv_$$_spine_EventData',
    INIT_VALUE = false,
    TYPENAME = 'spine::EventData',
}

REG_TYPE {
    TYPENAME = 'spine::AttachmentType',
    DECL_TYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    VALUE_TYPE = true,
    LUACLS = 'sp.AttachmentType',
}

REG_TYPE {
    TYPENAME = 'spine::EventType',
    DECL_TYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    VALUE_TYPE = true,
    LUACLS = 'sp.EventType',
}

REG_TYPE {
    TYPENAME = 'spine::Animation *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.Animation',
}

REG_TYPE {
    TYPENAME = 'spine::AnimationState *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.AnimationState',
}

REG_TYPE {
    TYPENAME = 'spine::AnimationStateData *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.AnimationStateData',
}

REG_TYPE {
    TYPENAME = 'spine::Atlas *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.Atlas',
}

REG_TYPE {
    TYPENAME = 'spine::Attachment *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.Attachment',
}

REG_TYPE {
    TYPENAME = 'spine::AttachmentTimeline *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.AttachmentTimeline',
}

REG_TYPE {
    TYPENAME = 'spine::Bone *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.Bone',
}

REG_TYPE {
    TYPENAME = 'spine::BoneData *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.BoneData',
}

REG_TYPE {
    TYPENAME = 'spine::ColorTimeline *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.ColorTimeline',
}

REG_TYPE {
    TYPENAME = 'spine::CurveTimeline *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.CurveTimeline',
}

REG_TYPE {
    TYPENAME = 'spine::DeformTimeline *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.DeformTimeline',
}

REG_TYPE {
    TYPENAME = 'spine::DrawOrderTimeline *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.DrawOrderTimeline',
}

REG_TYPE {
    TYPENAME = 'spine::Event *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.Event',
}

REG_TYPE {
    TYPENAME = 'spine::EventData *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.EventData',
}

REG_TYPE {
    TYPENAME = 'spine::EventTimeline *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.EventTimeline',
}

REG_TYPE {
    TYPENAME = 'spine::IkConstraintData *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.IkConstraintData',
}

REG_TYPE {
    TYPENAME = 'spine::IkConstraintTimeline *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.IkConstraintTimeline',
}

REG_TYPE {
    TYPENAME = 'spine::PathConstraintData *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.PathConstraintData',
}

REG_TYPE {
    TYPENAME = 'spine::PathConstraintMixTimeline *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.PathConstraintMixTimeline',
}

REG_TYPE {
    TYPENAME = 'spine::PathConstraintPositionTimeline *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.PathConstraintPositionTimeline',
}

REG_TYPE {
    TYPENAME = 'spine::PathConstraintSpacingTimeline *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.PathConstraintSpacingTimeline',
}

REG_TYPE {
    TYPENAME = 'spine::ScaleTimeline *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.ScaleTimeline',
}

REG_TYPE {
    TYPENAME = 'spine::ShearTimeline *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.ShearTimeline',
}

REG_TYPE {
    TYPENAME = 'spine::Skeleton *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.Skeleton',
}

REG_TYPE {
    TYPENAME = 'spine::SkeletonAnimation *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.SkeletonAnimation',
}

REG_TYPE {
    TYPENAME = 'spine::SkeletonBounds *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.SkeletonBounds',
}

REG_TYPE {
    TYPENAME = 'spine::SkeletonClipping *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.SkeletonClipping',
}

REG_TYPE {
    TYPENAME = 'spine::SkeletonData *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.SkeletonData',
}

REG_TYPE {
    TYPENAME = 'spine::SkeletonRenderer *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.SkeletonRenderer',
}

REG_TYPE {
    TYPENAME = 'spine::Skin *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.Skin',
}

REG_TYPE {
    TYPENAME = 'spine::Slot *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.Slot',
}

REG_TYPE {
    TYPENAME = 'spine::SlotData *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.SlotData',
}

REG_TYPE {
    TYPENAME = 'spine::SpineObject *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.SpineObject',
}

REG_TYPE {
    TYPENAME = 'spine::Timeline *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.Timeline',
}

REG_TYPE {
    TYPENAME = 'spine::TrackEntry *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.TrackEntry',
}

REG_TYPE {
    TYPENAME = 'spine::TransformConstraintData *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.TransformConstraintData',
}

REG_TYPE {
    TYPENAME = 'spine::TransformConstraintTimeline *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.TransformConstraintTimeline',
}

REG_TYPE {
    TYPENAME = 'spine::TranslateTimeline *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.TranslateTimeline',
}

REG_TYPE {
    TYPENAME = 'spine::TwoColorTimeline *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.TwoColorTimeline',
}

REG_TYPE {
    TYPENAME = 'spine::Updatable *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.Updatable',
}

REG_TYPE {
    TYPENAME = 'spine::VertexEffect *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'sp.VertexEffect',
}

