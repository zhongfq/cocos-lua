-- AUTO BUILD, DON'T MODIFY!

local olua = require "olua"
local typedef = olua.typedef

olua.nowarning(typedef)

typedef {
    CONV = 'auto_olua_$$_dragonBones_Rectangle',
    CPPCLS = 'dragonBones::Rectangle',
}

typedef {
    CPPCLS = 'dragonBones::ActionType',
    DECLTYPE = 'lua_Unsigned',
    CONV = 'olua_$$_uint',
    LUACLS = 'db.ActionType',
}

typedef {
    CPPCLS = 'dragonBones::AnimationFadeOutMode',
    DECLTYPE = 'lua_Unsigned',
    CONV = 'olua_$$_uint',
    LUACLS = 'db.AnimationFadeOutMode',
}

typedef {
    CPPCLS = 'dragonBones::ArmatureType',
    DECLTYPE = 'lua_Unsigned',
    CONV = 'olua_$$_uint',
    LUACLS = 'db.ArmatureType',
}

typedef {
    CPPCLS = 'dragonBones::BinaryOffset',
    DECLTYPE = 'lua_Unsigned',
    CONV = 'olua_$$_uint',
    LUACLS = 'db.BinaryOffset',
}

typedef {
    CPPCLS = 'dragonBones::BlendMode',
    DECLTYPE = 'lua_Unsigned',
    CONV = 'olua_$$_uint',
    LUACLS = 'db.BlendMode',
}

typedef {
    CPPCLS = 'dragonBones::BoundingBoxType',
    DECLTYPE = 'lua_Unsigned',
    CONV = 'olua_$$_uint',
    LUACLS = 'db.BoundingBoxType',
}

typedef {
    CPPCLS = 'dragonBones::DisplayType',
    DECLTYPE = 'lua_Unsigned',
    CONV = 'olua_$$_uint',
    LUACLS = 'db.DisplayType',
}

typedef {
    CPPCLS = 'dragonBones::OffsetMode',
    DECLTYPE = 'lua_Unsigned',
    CONV = 'olua_$$_uint',
    LUACLS = 'db.OffsetMode',
}

typedef {
    CPPCLS = 'dragonBones::TextureFormat',
    DECLTYPE = 'lua_Unsigned',
    CONV = 'olua_$$_uint',
    LUACLS = 'db.TextureFormat',
}

typedef {
    CPPCLS = 'dragonBones::TimelineType',
    DECLTYPE = 'lua_Unsigned',
    CONV = 'olua_$$_uint',
    LUACLS = 'db.TimelineType',
}

typedef {
    CPPCLS = 'dragonBones::TweenType',
    DECLTYPE = 'lua_Unsigned',
    CONV = 'olua_$$_uint',
    LUACLS = 'db.TweenType',
}

typedef {
    CPPCLS = 'dragonBones::ActionData *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'db.ActionData',
}

typedef {
    CPPCLS = 'dragonBones::Animation *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'db.Animation',
}

typedef {
    CPPCLS = 'dragonBones::AnimationConfig *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'db.AnimationConfig',
}

typedef {
    CPPCLS = 'dragonBones::AnimationData *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'db.AnimationData',
}

typedef {
    CPPCLS = 'dragonBones::AnimationState *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'db.AnimationState',
}

typedef {
    CPPCLS = 'dragonBones::Armature *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'db.Armature',
}

typedef {
    CPPCLS = 'dragonBones::ArmatureData *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'db.ArmatureData',
}

typedef {
    CPPCLS = 'dragonBones::BaseFactory *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'db.BaseFactory',
}

typedef {
    CPPCLS = 'dragonBones::BaseObject *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'db.BaseObject',
}

typedef {
    CPPCLS = 'dragonBones::Bone *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'db.Bone',
}

typedef {
    CPPCLS = 'dragonBones::BoneData *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'db.BoneData',
}

typedef {
    CPPCLS = 'dragonBones::BoundingBoxData *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'db.BoundingBoxData',
}

typedef {
    CPPCLS = 'dragonBones::BoundingBoxDisplayData *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'db.BoundingBoxDisplayData',
}

typedef {
    CPPCLS = 'dragonBones::CCArmatureDisplay *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'db.ArmatureDisplay',
}

typedef {
    CPPCLS = 'dragonBones::CCFactory *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'db.Factory',
}

typedef {
    CPPCLS = 'dragonBones::CanvasData *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'db.CanvasData',
}

typedef {
    CPPCLS = 'dragonBones::ConstraintData *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'db.ConstraintData',
}

typedef {
    CPPCLS = 'dragonBones::DisplayData *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'db.DisplayData',
}

typedef {
    CPPCLS = 'dragonBones::DragonBonesData *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'db.DragonBonesData',
}

typedef {
    CPPCLS = 'dragonBones::EventObject *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'db.EventObject',
}

typedef {
    CPPCLS = 'dragonBones::IAnimatable *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'db.IAnimatable',
}

typedef {
    CPPCLS = 'dragonBones::IKConstraintData *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'db.IKConstraintData',
}

typedef {
    CPPCLS = 'dragonBones::Point *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'db.Point',
}

typedef {
    CPPCLS = 'dragonBones::SkinData *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'db.SkinData',
}

typedef {
    CPPCLS = 'dragonBones::Slot *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'db.Slot',
}

typedef {
    CPPCLS = 'dragonBones::SlotData *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'db.SlotData',
}

typedef {
    CPPCLS = 'dragonBones::TextureAtlasData *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'db.TextureAtlasData',
}

typedef {
    CPPCLS = 'dragonBones::TextureData *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'db.TextureData',
}

typedef {
    CPPCLS = 'dragonBones::TimelineData *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'db.TimelineData',
}

typedef {
    CPPCLS = 'dragonBones::TransformObject *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'db.TransformObject',
}

typedef {
    CPPCLS = 'dragonBones::UserData *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'db.UserData',
}

typedef {
    CPPCLS = 'dragonBones::WorldClock *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'db.WorldClock',
}

