local function make_luacls(cppname)
    cppname = string.gsub(cppname, '^cocos2d::experimental::ui::', 'ccui.')
    cppname = string.gsub(cppname, '^cocos2d::experimental::', 'cc.')
    cppname = string.gsub(cppname, '^cocos2d::ui::', 'ccui.')
    cppname = string.gsub(cppname, "^cocos2d::", "cc.")
    cppname = string.gsub(cppname, "^CocosDenshion::", "cc.")
    cppname = string.gsub(cppname, "^spine::", "sp.")
    cppname = string.gsub(cppname, "^dragonBones::CC", "db.")
    cppname = string.gsub(cppname, "^dragonBones::", "db.")
    cppname = string.gsub(cppname, "::", ".")
    cppname = string.gsub(cppname, "[ *]*$", '')
    return cppname
end

local function make_auto_conv_func(cppname)
    cppname = string.gsub(cppname, '::', '_')
    cppname = string.gsub(cppname, '[ *]*$', '')
    return 'auto_luacv_$$_' .. cppname
end

local function make_manual_conv_func(cppname)
    cppname = string.gsub(cppname, '::', '_')
    cppname = string.gsub(cppname, '[ *]*$', '')
    return 'manual_luacv_$$_' .. cppname
end

REG_TYPE {
    TYPENAME = 'cocos2d::Data', 
    CONV_FUNC = make_manual_conv_func,
    INIT_VALUE = false,
}

REG_TYPE {
    TYPENAME = [[
        cocos2d::Vec2
        cocos2d::Point
    ]],
    CONV_FUNC = 'auto_luacv_$$_cocos2d_Vec2',
    INIT_VALUE = false,
    VARS = 2,
}

REG_TYPE {
    TYPENAME = 'cocos2d::Vec3',
    CONV_FUNC = make_auto_conv_func,
    INIT_VALUE = false,
    VARS = 3,
}

REG_TYPE {
    TYPENAME = 'cocos2d::Vec4',
    CONV_FUNC = make_auto_conv_func,
    INIT_VALUE = false,
    VARS = 4,
}

REG_TYPE {
    TYPENAME = 'cocos2d::Size',
    CONV_FUNC = make_auto_conv_func,
    INIT_VALUE = false,
    VARS = 2,
}

REG_TYPE {
    TYPENAME = 'cocos2d::Rect',
    CONV_FUNC = make_manual_conv_func,
    VARS = 4,
    INIT_VALUE = false,
}

REG_TYPE {
    TYPENAME = 'cocos2d::ccBezierConfig',
    CONV_FUNC =  make_manual_conv_func,
    INIT_VALUE = false,
    VARS = 3,
}

REG_TYPE {
    TYPENAME = 'cocos2d::Mat4',
    CONV_FUNC = make_manual_conv_func,
    INIT_VALUE = false,
    VALUE_TYPE = true,
}

REG_TYPE {
    TYPENAME = 'cocos2d::Vector',
    IS_ARRAY = true,
    CONV_FUNC = make_manual_conv_func,
    INIT_VALUE = false,
}

REG_TYPE {
    TYPENAME = [[
        cocos2d::Color3B
        cocos2d::Color4B
        cocos2d::Color4F
        cocos2d::Value
        cocos2d::ValueMap
        cocos2d::ValueVector
    ]],
    CONV_FUNC = make_manual_conv_func,
    INIT_VALUE = false,
}

REG_TYPE {
    TYPENAME = 'cocos2d::EventListener::ListenerID',
    INIT_VALUE = false,
    DECL_TYPE = 'std::string',
    CONV_FUNC = 'olua_$$_std_string',
}

REG_TYPE {
    TYPENAME = [[
        cocos2d::AffineTransform
        cocos2d::BlendFunc
        cocos2d::experimental::Viewport
        cocos2d::Quaternion
        cocos2d::ResourceData
        cocos2d::T2F_Quad
        cocos2d::Tex2F
        cocos2d::Texture2D::TexParams
        cocos2d::TTFConfig
        cocos2d::ui::Margin
        cocos2d::Uniform *
        cocos2d::VertexAttrib *
        GLContextAttrs
        cocos2d::Quad3
    ]],
    CONV_FUNC = make_auto_conv_func,
    INIT_VALUE = false,
}

REG_TYPE {
    TYPENAME = [[
        
        cocos2d::Touch::DispatchMode
        
        spAttachmentType
        spEventType
    ]],
    DECL_TYPE = 'lua_Unsigned',
    CONV_FUNC = "olua_$$_uint",
    VALUE_TYPE = true,
    LUACLS = make_luacls,
}

REG_TYPE {
    TYPENAME = [[
        
        
        spine::SkeletonAnimation *
        spine::SkeletonRenderer *
        dragonBones::CCFactory *
    ]],
    CONV_FUNC = "olua_$$_cppobj",
    LUACLS = make_luacls,
}

REG_TYPE {
    TYPENAME = [[
        spAnimation *
        spAnimationState *
        spAnimationStateData *
        spAtlas *
        spAttachment *
        spBone *
        spEvent *
        spEventData *
        spSkeleton *
        spSkeletonData *
        spSlot *
        spTrackEntry *
        spVertexEffect *
    ]],
    CONV_FUNC = "olua_$$_obj",
    LUACLS = function (name)
        name = string.gsub(name, 'sp', 'sp.')
        name = string.gsub(name, '[ *]+', '')
        return name
    end,
}
