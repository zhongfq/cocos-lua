local function make_luacls(cppname)
    cppname = string.gsub(cppname, "cocos2d::", "cc.")
    cppname = string.gsub(cppname, "[ *]*$", '')
    return cppname
end

REG_TYPE {
    TYPENAME = 'cocos2d::Data', 
    CONV_FUNC = "xluacv_$$_ccdata",
}

REG_TYPE {
    TYPENAME = 'cocos2d::UserDefault *',
    CONV_FUNC = "olua_$$_cppobj",
    LUACLS = make_luacls,
}

REG_TYPE {
    TYPENAME = 'cocos2d::Vec2',
    CONV_FUNC = 'auto_luacv_$$_cocos2d_Vec2',
    INIT_VALUE = false,
    VARS = 2,
}

REG_TYPE {
    TYPENAME = 'cocos2d::Vec3',
    CONV_FUNC = 'auto_luacv_$$_cocos2d_Vec3',
    INIT_VALUE = false,
    VARS = 3,
}

REG_TYPE {
    TYPENAME = 'cocos2d::Vec4',
    CONV_FUNC = 'auto_luacv_$$_cocos2d_Vec4',
    INIT_VALUE = false,
    VARS = 4,
}

REG_TYPE {
    TYPENAME = 'cocos2d::Size',
    CONV_FUNC = 'auto_luacv_$$_cocos2d_Size',
    INIT_VALUE = false,
    VARS = 2,
}

REG_TYPE {
    TYPENAME = 'cocos2d::Mat4',
    CONV_FUNC = "xluacv_$$_ccmat4",
    INIT_VALUE = false,
}

REG_TYPE {
    TYPENAME = 'cocos2d::Vector',
    CONV_FUNC = "xluacv_$$_ccvector",
    INIT_VALUE = false,
}

REG_TYPE {
    TYPENAME = 'cocos2d::Texture2D::TexParams',
    CONV_FUNC = 'auto_luacv_$$_cocos2d_Texture2D_TexParams',
    INIT_VALUE = false,
}

REG_TYPE {
    TYPENAME = 'cocos2d::experimental::Viewport',
    CONV_FUNC = 'auto_luacv_$$_cocos2d_experimental_Viewport',
    INIT_VALUE = false,
}

REG_TYPE {
    TYPENAME = 'cocos2d::Uniform *',
    CONV_FUNC = 'auto_luacv_$$_cocos2d_Uniform',
}

REG_TYPE {
    TYPENAME = 'cocos2d::VertexAttrib *',
    CONV_FUNC = 'auto_luacv_$$_cocos2d_VertexAttrib',
}

REG_TYPE {
    TYPENAME = 'cocos2d::EventListener::ListenerID',
    INIT_VALUE = false,
    DECL_TYPE = 'std::string',
    CONV_FUNC = 'olua_$$_std_string',
}

REG_TYPE {
    TYPENAME = table.concat({
        'cocos2d::Director::Projection',
        'cocos2d::Texture2D::PixelFormat',
        'cocos2d::Image::Format',
        'cocos2d::Camera::Type',
        'cocos2d::EventListener::Type',
        'cocos2d::Event::Type',
    }, '|'),
    DECL_TYPE = 'lua_Unsigned',
    CONV_FUNC = "olua_$$_uint",
}

REG_TYPE {
    TYPENAME = table.concat({
        'cocos2d::Ref *',
        'cocos2d::Director *',
        'cocos2d::Scheduler *',
        'cocos2d::ActionManager *',
        'cocos2d::GLView *',
        'cocos2d::GLProgram *',
        'cocos2d::TextureCache *',
        'cocos2d::Texture2D *',
        'cocos2d::Image *',
        'cocos2d::Node *',
        'cocos2d::Camera *',
        'cocos2d::Sprite *',
        'cocos2d::Scene *',
        'cocos2d::Action *',
        'cocos2d::EventListener *',
        'cocos2d::EventListenerTouchAllAtOnce *',
        'cocos2d::Event *',
        'cocos2d::Touch *',
    }, '|'),
    CONV_FUNC = "olua_$$_cppobj",
    LUACLS = make_luacls,
}