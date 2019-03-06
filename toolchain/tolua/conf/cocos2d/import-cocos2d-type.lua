local function make_luacls(cppname)
    cppname = string.gsub(cppname, "cocos2d::", "cc.")
    cppname = string.gsub(cppname, "[ *]*$", '')
    return cppname
end

REG_TYPE {
    TYPENAME = 'cocos2d::Data', 
    CONV_FUNC = "xluacv_$ACTION_ccdata",
}

REG_TYPE {
    TYPENAME = 'cocos2d::UserDefault *',
    CONV_FUNC = "tolua_$ACTION_obj",
    LUACLS = make_luacls,
}

REG_TYPE {
    TYPENAME = 'cocos2d::Vec2',
    CONV_FUNC = "luacv_$ACTION_cocos2d_Vec2",
    INIT_VALUE = false,
    VARS = 2,
}

REG_TYPE {
    TYPENAME = 'cocos2d::Size',
    CONV_FUNC = "xluacv_$ACTION_ccsize",
    INIT_VALUE = false,
    VARS = 2,
}

REG_TYPE {
    TYPENAME = 'cocos2d::Mat4',
    CONV_FUNC = "xluacv_$ACTION_ccmat4",
    INIT_VALUE = false,
}

REG_TYPE {
    TYPENAME = 'cocos2d::Vector',
    CONV_FUNC = "xluacv_$ACTION_ccvector",
    INIT_VALUE = false,
}

REG_TYPE {
    TYPENAME = 'cocos2d::Texture2D::TexParams',
    CONV_FUNC = "xluacv_$ACTION_cctexparams",
    INIT_VALUE = false,
}

REG_TYPE {
    TYPENAME = 'cocos2d::experimental::Viewport',
    CONV_FUNC = "luacv_$ACTION_cocos2d_experimental_Viewport",
    INIT_VALUE = false,
}

REG_TYPE {
    TYPENAME = 'cocos2d::Uniform *',
    CONV_FUNC = "xluacv_$ACTION_uniform"
}

REG_TYPE {
    TYPENAME = 'cocos2d::VertexAttrib *',
    CONV_FUNC = "xluacv_$ACTION_vertexattrib"
}

REG_TYPE {
    TYPENAME = table.concat({
        'cocos2d::Director::Projection',
        'cocos2d::Texture2D::PixelFormat',
        'cocos2d::Image::Format',
        'cocos2d::Camera::Type',
    }, '|'),
    DECL_TYPE = 'lua_Unsigned',
    CONV_FUNC = "tolua_$ACTION_uint",
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
    }, '|'),
    CONV_FUNC = "xluacv_$ACTION_ccobj",
    LUACLS = make_luacls,
}