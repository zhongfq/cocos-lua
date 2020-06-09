local olua = require "olua"
local typedef = olua.typedef

typedef {
    CPPCLS = 'android_LogPriority',
    DECLTYPE = 'lua_Unsigned',
    CONV = 'olua_$$_uint',
}

typedef {
    CPPCLS = 'cocos2d::CullFaceSide',
    DECLTYPE = 'lua_Unsigned',
    CONV = 'olua_$$_uint',
}

typedef {
    CPPCLS = 'cocos2d::CullMode',
    DECLTYPE = 'lua_Unsigned',
    CONV = 'olua_$$_uint',
}

typedef {
    CPPCLS = 'cocos2d::CustomCommand::BufferUsage',
    DECLTYPE = 'lua_Unsigned',
    CONV = 'olua_$$_uint',
}

typedef {
    CPPCLS = 'cocos2d::CustomCommand::IndexFormat',
    DECLTYPE = 'lua_Unsigned',
    CONV = 'olua_$$_uint',
}

typedef {
    CPPCLS = 'cocos2d::CustomCommand::PrimitiveType',
    DECLTYPE = 'lua_Unsigned',
    CONV = 'olua_$$_uint',
}

typedef {
    CPPCLS = 'cocos2d::DepthFunction',
    DECLTYPE = 'lua_Unsigned',
    CONV = 'olua_$$_uint',
}

typedef {
    CPPCLS = 'cocos2d::FrontFace',
    DECLTYPE = 'lua_Unsigned',
    CONV = 'olua_$$_uint',
}

typedef {
    CPPCLS = 'cocos2d::MeshCommand::BufferUsage',
    DECLTYPE = 'lua_Unsigned',
    CONV = 'olua_$$_uint',
}

typedef {
    CPPCLS = 'cocos2d::MeshCommand::IndexFormat',
    DECLTYPE = 'lua_Unsigned',
    CONV = 'olua_$$_uint',
}

typedef {
    CPPCLS = 'cocos2d::PixelFormat',
    DECLTYPE = 'lua_Unsigned',
    CONV = 'olua_$$_uint',
}

typedef {
    CPPCLS = 'cocos2d::Point',
    DECLTYPE = 'cocos2d::Point',
    CONV = 'auto_olua_$$_cocos2d_Vec2',
}

typedef {
    CPPCLS = 'cocos2d::ResizableBufferAdapter<cocos2d::Data>::BufferType',
    DECLTYPE = 'cocos2d::ResizableBufferAdapter<cocos2d::Data>::BufferType',
    CONV = 'manual_olua_$$_cocos2d_Data',
}

typedef {
    CPPCLS = 'cocos2d::Texture2D::TexParams',
    DECLTYPE = 'cocos2d::Texture2D::TexParams',
    CONV = 'auto_olua_$$_cocos2d_backend_SamplerDescriptor',
}

typedef {
    CPPCLS = 'cocos2d::TextureUsage',
    DECLTYPE = 'lua_Unsigned',
    CONV = 'olua_$$_uint',
}

typedef {
    CPPCLS = 'cocos2d::Vect',
    DECLTYPE = 'cocos2d::Vect',
    CONV = 'auto_olua_$$_cocos2d_Vec2',
}

typedef {
    CPPCLS = 'cocos2d::VolatileTexture::ccCachedImageType',
    DECLTYPE = 'lua_Unsigned',
    CONV = 'olua_$$_uint',
}

typedef {
    CPPCLS = 'cocos2d::Winding',
    DECLTYPE = 'lua_Unsigned',
    CONV = 'olua_$$_uint',
}

typedef {
    CPPCLS = 'cocos2d::ui::SliderEventType',
    DECLTYPE = 'lua_Unsigned',
    CONV = 'olua_$$_uint',
}

typedef {
    CPPCLS = 'jobjectRefType',
    DECLTYPE = 'lua_Unsigned',
    CONV = 'olua_$$_uint',
}

typedef {
    CPPCLS = 'khronos_boolean_enum_t',
    DECLTYPE = 'lua_Unsigned',
    CONV = 'olua_$$_uint',
}

typedef {
    CPPCLS = 'log_id_t',
    DECLTYPE = 'lua_Unsigned',
    CONV = 'olua_$$_uint',
}