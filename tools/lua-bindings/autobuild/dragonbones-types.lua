local olua = require "olua"
local typedef = olua.typedef

olua.nowarning(typedef)

typedef {
    CPPCLS = 'dragonBones::ActionType',
    DECL_TYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'db.ActionType',
}

typedef {
    CPPCLS = 'dragonBones::AnimationFadeOutMode',
    DECL_TYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'db.AnimationFadeOutMode',
}

typedef {
    CPPCLS = 'dragonBones::ArmatureType',
    DECL_TYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'db.ArmatureType',
}

typedef {
    CPPCLS = 'dragonBones::DisplayType',
    DECL_TYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'db.DisplayType',
}

typedef {
    CPPCLS = 'dragonBones::OffsetMode',
    DECL_TYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'db.OffsetMode',
}

typedef {
    CPPCLS = 'dragonBones::ActionData *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'db.ActionData',
}

typedef {
    CPPCLS = 'dragonBones::Animation *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'db.Animation',
}

typedef {
    CPPCLS = 'dragonBones::AnimationConfig *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'db.AnimationConfig',
}

typedef {
    CPPCLS = 'dragonBones::AnimationData *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'db.AnimationData',
}

typedef {
    CPPCLS = 'dragonBones::AnimationState *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'db.AnimationState',
}

typedef {
    CPPCLS = 'dragonBones::Armature *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'db.Armature',
}

typedef {
    CPPCLS = 'dragonBones::ArmatureData *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'db.ArmatureData',
}

typedef {
    CPPCLS = 'dragonBones::BaseFactory *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'db.BaseFactory',
}

typedef {
    CPPCLS = 'dragonBones::BaseObject *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'db.BaseObject',
}

typedef {
    CPPCLS = 'dragonBones::Bone *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'db.Bone',
}

typedef {
    CPPCLS = 'dragonBones::BoneData *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'db.BoneData',
}

typedef {
    CPPCLS = 'dragonBones::CCArmatureDisplay *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'db.ArmatureDisplay',
}

typedef {
    CPPCLS = 'dragonBones::CCFactory *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'db.Factory',
}

typedef {
    CPPCLS = 'dragonBones::DisplayData *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'db.DisplayData',
}

typedef {
    CPPCLS = 'dragonBones::DragonBonesData *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'db.DragonBonesData',
}

typedef {
    CPPCLS = 'dragonBones::EventObject *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'db.EventObject',
}

typedef {
    CPPCLS = 'dragonBones::Point *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'db.Point',
}

typedef {
    CPPCLS = 'dragonBones::SkinData *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'db.SkinData',
}

typedef {
    CPPCLS = 'dragonBones::Slot *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'db.Slot',
}

typedef {
    CPPCLS = 'dragonBones::SlotData *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'db.SlotData',
}

typedef {
    CPPCLS = 'dragonBones::TextureAtlasData *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'db.TextureAtlasData',
}

typedef {
    CPPCLS = 'dragonBones::TextureData *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'db.TextureData',
}

typedef {
    CPPCLS = 'dragonBones::TransformObject *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'db.TransformObject',
}

