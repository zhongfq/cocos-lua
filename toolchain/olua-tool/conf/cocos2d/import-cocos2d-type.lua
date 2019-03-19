local function make_luacls(cppname)
    cppname = string.gsub(cppname, 'cocos2d::ui::', 'ccui.')
    cppname = string.gsub(cppname, "cocos2d::", "cc.")
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
    TYPENAME = 'cocos2d::Vec2',
    CONV_FUNC = make_auto_conv_func,
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
    INIT_VALUE = false,
    VARS = 4,
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
    TYPENAME = table.concat({
        'cocos2d::Color3B',
        'cocos2d::Color4B',
        'cocos2d::ValueMap',
        'cocos2d::Vector',
    }, "|"),
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
    TYPENAME = table.concat({
        'cocos2d::AffineTransform',
        'cocos2d::BlendFunc',
        'cocos2d::Color4F',
        'cocos2d::experimental::Viewport',
        'cocos2d::Quaternion',
        'cocos2d::T2F_Quad',
        'cocos2d::Tex2F',
        'cocos2d::Texture2D::TexParams',
        'cocos2d::TTFConfig',
        'cocos2d::Uniform *',
        'cocos2d::VertexAttrib *',
        'GLContextAttrs',
    }, '|'),
    CONV_FUNC = make_auto_conv_func,
    INIT_VALUE = false,
}

REG_TYPE {
    TYPENAME = table.concat({
        'cocos2d::Camera::Type',
        'cocos2d::Director::Projection',
        'cocos2d::Event::Type',
        'cocos2d::EventKeyboard::KeyCode',
        'cocos2d::EventListener::Type',
        'cocos2d::EventMouse::MouseButton',
        'cocos2d::EventMouse::MouseEventType',
        'cocos2d::EventTouch::EventCode',
        'cocos2d::GlyphCollection',
        'cocos2d::Image::Format',
        'cocos2d::Label::LabelType',
        'cocos2d::Label::Overflow',
        'cocos2d::LabelEffect',
        'cocos2d::LanguageType',
        'cocos2d::LightFlag',
        'cocos2d::LightType',
        'cocos2d::MATRIX_STACK_TYPE',
        'cocos2d::Application::Platform',
        'cocos2d::SetIntervalReason',
        'cocos2d::TextHAlignment',
        'cocos2d::Texture2D::PixelFormat',
        'cocos2d::TextVAlignment',
        'ResolutionPolicy',
    }, '|'),
    DECL_TYPE = 'lua_Unsigned',
    CONV_FUNC = "olua_$$_uint",
    VALUE_TYPE = true,
}

REG_TYPE {
    TYPENAME = table.concat({
        'cocos2d::Acceleration *',
        'cocos2d::Action *',
        'cocos2d::ActionCamera *',
        'cocos2d::ActionEase *',
        'cocos2d::ActionFloat *',
        'cocos2d::ActionInstant *',
        'cocos2d::ActionInterval *',
        'cocos2d::ActionManager *',
        'cocos2d::AmbientLight *',
        'cocos2d::Animate *',
        'cocos2d::Animation *',
        'cocos2d::AnimationFrame *',
        'cocos2d::Application *',
        'cocos2d::AtlasNode *',
        'cocos2d::BaseLight *',
        'cocos2d::BezierBy *',
        'cocos2d::BezierTo *',
        'cocos2d::Blink *',
        'cocos2d::CallFunc *',
        'cocos2d::Camera *',
        'cocos2d::CardinalSplineBy *',
        'cocos2d::CardinalSplineTo *',
        'cocos2d::CatmullRomBy *',
        'cocos2d::CatmullRomTo *',
        'cocos2d::Component *',
        'cocos2d::FileUtils *',
        'cocos2d::DelayTime *',
        'cocos2d::DirectionLight *',
        'cocos2d::Director *',
        'cocos2d::EaseBackIn *',
        'cocos2d::EaseBackInOut *',
        'cocos2d::EaseBackOut *',
        'cocos2d::EaseBezierAction *',
        'cocos2d::EaseBounceIn *',
        'cocos2d::EaseBounceInOut *',
        'cocos2d::EaseBounceOut *',
        'cocos2d::EaseCircleActionIn *',
        'cocos2d::EaseCircleActionInOut *',
        'cocos2d::EaseCircleActionOut *',
        'cocos2d::EaseCubicActionIn *',
        'cocos2d::EaseCubicActionInOut *',
        'cocos2d::EaseCubicActionOut *',
        'cocos2d::EaseElastic *',
        'cocos2d::EaseElasticIn *',
        'cocos2d::EaseElasticInOut *',
        'cocos2d::EaseElasticOut *',
        'cocos2d::EaseExponentialIn *',
        'cocos2d::EaseExponentialInOut *',
        'cocos2d::EaseExponentialOut *',
        'cocos2d::EaseIn *',
        'cocos2d::EaseInOut *',
        'cocos2d::EaseOut *',
        'cocos2d::EaseQuadraticActionIn *',
        'cocos2d::EaseQuadraticActionInOut *',
        'cocos2d::EaseQuadraticActionOut *',
        'cocos2d::EaseQuarticActionIn *',
        'cocos2d::EaseQuarticActionInOut *',
        'cocos2d::EaseQuarticActionOut *',
        'cocos2d::EaseQuinticActionIn *',
        'cocos2d::EaseQuinticActionInOut *',
        'cocos2d::EaseQuinticActionOut *',
        'cocos2d::EaseRateAction *',
        'cocos2d::EaseSineIn *',
        'cocos2d::EaseSineInOut *',
        'cocos2d::EaseSineOut *',
        'cocos2d::Event *',
        'cocos2d::EventAcceleration *',
        'cocos2d::EventCustom *',
        'cocos2d::EventDispatcher *',
        'cocos2d::EventFocus *',
        'cocos2d::EventKeyboard *',
        'cocos2d::EventListener *',
        'cocos2d::EventListenerAcceleration *',
        'cocos2d::EventListenerCustom *',
        'cocos2d::EventListenerFocus *',
        'cocos2d::EventListenerKeyboard *',
        'cocos2d::EventListenerMouse *',
        'cocos2d::EventListenerTouchAllAtOnce *',
        'cocos2d::EventListenerTouchOneByOne *',
        'cocos2d::EventMouse *',
        'cocos2d::EventTouch *',
        'cocos2d::FadeIn *',
        'cocos2d::FadeOut *',
        'cocos2d::FadeTo *',
        'cocos2d::FiniteTimeAction *',
        'cocos2d::FlipX *',
        'cocos2d::FlipY *',
        'cocos2d::Follow *',
        'cocos2d::FontAtlas *',
        'cocos2d::GLProgram *',
        'cocos2d::GLProgramState *',
        'cocos2d::GLView *',
        'cocos2d::GLViewImpl *',
        'cocos2d::Hide *',
        'cocos2d::Image *',
        'cocos2d::JumpBy *',
        'cocos2d::JumpTo *',
        'cocos2d::Label *',
        'cocos2d::LabelAtlas *',
        'cocos2d::Layer *',
        'cocos2d::LayerColor *',
        'cocos2d::LayerGradient *',
        'cocos2d::LayerRadialGradient *',
        'cocos2d::MoveBy *',
        'cocos2d::MoveTo *',
        'cocos2d::Node *',
        'cocos2d::OrbitCamera *',
        'cocos2d::Place *',
        'cocos2d::PointArray *',
        'cocos2d::PointLight *',
        'cocos2d::ProtectedNode *',
        'cocos2d::Ref *',
        'cocos2d::RemoveSelf *',
        'cocos2d::Renderer *',
        'cocos2d::Repeat *',
        'cocos2d::RepeatForever *',
        'cocos2d::ResizeBy *',
        'cocos2d::ResizeTo *',
        'cocos2d::ReverseTime *',
        'cocos2d::RotateBy *',
        'cocos2d::RotateTo *',
        'cocos2d::ScaleBy *',
        'cocos2d::ScaleTo *',
        'cocos2d::Scene *',
        'cocos2d::Scheduler *',
        'cocos2d::Sequence *',
        'cocos2d::Show *',
        'cocos2d::SkewBy *',
        'cocos2d::SkewTo *',
        'cocos2d::Spawn *',
        'cocos2d::Speed *',
        'cocos2d::SpotLight *',
        'cocos2d::Sprite *',
        'cocos2d::SpriteFrame *',
        'cocos2d::TargetedAction *',
        'cocos2d::Texture2D *',
        'cocos2d::TextureAtlas *',
        'cocos2d::TextureCache *',
        'cocos2d::TintBy *',
        'cocos2d::TintTo *',
        'cocos2d::ToggleVisibility *',
        'cocos2d::Touch *',
        'cocos2d::ui::Widget *',
        'cocos2d::UserDefault *',
        'cocos2d::Vec3 *',
        'cocos2d::VRIHeadTracker *',
        'cocos2d::VRIRenderer *',
    }, '|'),
    CONV_FUNC = "olua_$$_cppobj",
    LUACLS = make_luacls,
}

REG_TYPE {
    TYPENAME = 'cocos2d::LuaComponent *',
    CONV_FUNC = "olua_$$_cppobj",
    LUACLS = "cc.Component",
}

