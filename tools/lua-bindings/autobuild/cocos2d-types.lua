local olua = require "olua"
local typedef = olua.typedef

olua.nowarning(typedef)

typedef {
    CONV_FUNC = 'manual_olua_$$_cocos2d_Data',
    CPPCLS = 'cocos2d::Data',
}

typedef {
    CONV_FUNC = 'auto_olua_$$_cocos2d_Vec2',
    CPPCLS = 'cocos2d::Vec2',
    VARS = 2,
}

typedef {
    CONV_FUNC = 'auto_olua_$$_cocos2d_Vec2',
    CPPCLS = 'cocos2d::Point',
    VARS = 2,
}

typedef {
    CONV_FUNC = 'auto_olua_$$_cocos2d_Vec3',
    CPPCLS = 'cocos2d::Vec3',
    VARS = 3,
}

typedef {
    CONV_FUNC = 'auto_olua_$$_cocos2d_Vec4',
    CPPCLS = 'cocos2d::Vec4',
    VARS = 4,
}

typedef {
    CONV_FUNC = 'auto_olua_$$_cocos2d_Size',
    CPPCLS = 'cocos2d::Size',
    VARS = 2,
}

typedef {
    CONV_FUNC = 'manual_olua_$$_cocos2d_Rect',
    CPPCLS = 'cocos2d::Rect',
    VARS = 4,
}

typedef {
    CONV_FUNC = 'manual_olua_$$_cocos2d_ccBezierConfig',
    CPPCLS = 'cocos2d::ccBezierConfig',
    VARS = 3,
}

typedef {
    CONV_FUNC = 'manual_olua_$$_cocos2d_Mat4',
    CPPCLS = 'cocos2d::Mat4',
}

typedef {
    CONV_FUNC = 'manual_olua_$$_cocos2d_Vector',
    CPPCLS = 'cocos2d::Vector',
}

typedef {
    CONV_FUNC = 'olua_$$_std_string',
    CPPCLS = 'cocos2d::EventListener::ListenerID',
    DECLTYPE = 'std::string',
}

typedef {
    CONV_FUNC = 'auto_olua_$$_cocos2d_AffineTransform',
    CPPCLS = 'cocos2d::AffineTransform',
}

typedef {
    CONV_FUNC = 'auto_olua_$$_cocos2d_BlendFunc',
    CPPCLS = 'cocos2d::BlendFunc',
}

typedef {
    CONV_FUNC = 'auto_olua_$$_cocos2d_experimental_Viewport',
    CPPCLS = 'cocos2d::experimental::Viewport',
}

typedef {
    CONV_FUNC = 'auto_olua_$$_cocos2d_Quaternion',
    CPPCLS = 'cocos2d::Quaternion',
}

typedef {
    CONV_FUNC = 'auto_olua_$$_cocos2d_ResourceData',
    CPPCLS = 'cocos2d::ResourceData',
}

typedef {
    CONV_FUNC = 'auto_olua_$$_cocos2d_T2F_Quad',
    CPPCLS = 'cocos2d::T2F_Quad',
}

typedef {
    CONV_FUNC = 'auto_olua_$$_cocos2d_Tex2F',
    CPPCLS = 'cocos2d::Tex2F',
}

typedef {
    CONV_FUNC = 'auto_olua_$$_cocos2d_Texture2D_TexParams',
    CPPCLS = 'cocos2d::Texture2D::TexParams',
}

typedef {
    CONV_FUNC = 'auto_olua_$$_cocos2d_TTFConfig',
    CPPCLS = 'cocos2d::TTFConfig',
}

typedef {
    CONV_FUNC = 'auto_olua_$$_cocos2d_Uniform',
    CPPCLS = 'cocos2d::Uniform *',
}

typedef {
    CONV_FUNC = 'auto_olua_$$_cocos2d_VertexAttrib',
    CPPCLS = 'cocos2d::VertexAttrib *',
}

typedef {
    CONV_FUNC = 'auto_olua_$$_GLContextAttrs',
    CPPCLS = 'GLContextAttrs',
}

typedef {
    CONV_FUNC = 'auto_olua_$$_cocos2d_Quad3',
    CPPCLS = 'cocos2d::Quad3',
}

typedef {
    CONV_FUNC = 'manual_olua_$$_cocos2d_Color3B',
    CPPCLS = 'cocos2d::Color3B',
}

typedef {
    CONV_FUNC = 'manual_olua_$$_cocos2d_Color4B',
    CPPCLS = 'cocos2d::Color4B',
}

typedef {
    CONV_FUNC = 'manual_olua_$$_cocos2d_Color4F',
    CPPCLS = 'cocos2d::Color4F',
}

typedef {
    CONV_FUNC = 'manual_olua_$$_cocos2d_Value',
    CPPCLS = 'cocos2d::Value',
}

typedef {
    CONV_FUNC = 'manual_olua_$$_cocos2d_ValueMap',
    CPPCLS = 'cocos2d::ValueMap',
}

typedef {
    CONV_FUNC = 'manual_olua_$$_cocos2d_ValueVector',
    CPPCLS = 'cocos2d::ValueVector',
}

typedef {
    CONV_FUNC = 'auto_olua_$$_cocos2d_Controller_KeyStatus',
    CPPCLS = 'cocos2d::Controller::KeyStatus',
}

typedef {
    CONV_FUNC = 'auto_olua_$$_cocos2d_network_WebSocket_Data',
    CPPCLS = 'cocos2d::network::WebSocket::Data',
}

typedef {
    CPPCLS = 'ResolutionPolicy',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'cc.ResolutionPolicy',
}

typedef {
    CPPCLS = 'cocos2d::ApplicationProtocol::Platform',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'cc.ApplicationProtocol.Platform',
}

typedef {
    CPPCLS = 'cocos2d::Camera::Type',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'cc.Camera.Type',
}

typedef {
    CPPCLS = 'cocos2d::CameraBackgroundBrush::BrushType',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'cc.CameraBackgroundBrush.BrushType',
}

typedef {
    CPPCLS = 'cocos2d::CameraFlag',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'cc.CameraFlag',
}

typedef {
    CPPCLS = 'cocos2d::Controller::Key',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'cc.Controller.Key',
}

typedef {
    CPPCLS = 'cocos2d::Director::Projection',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'cc.Director.Projection',
}

typedef {
    CPPCLS = 'cocos2d::Event::Type',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'cc.Event.Type',
}

typedef {
    CPPCLS = 'cocos2d::EventController::ControllerEventType',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'cc.EventController.ControllerEventType',
}

typedef {
    CPPCLS = 'cocos2d::EventKeyboard::KeyCode',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'cc.EventKeyboard.KeyCode',
}

typedef {
    CPPCLS = 'cocos2d::EventListener::Type',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'cc.EventListener.Type',
}

typedef {
    CPPCLS = 'cocos2d::EventMouse::MouseButton',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'cc.EventMouse.MouseButton',
}

typedef {
    CPPCLS = 'cocos2d::EventMouse::MouseEventType',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'cc.EventMouse.MouseEventType',
}

typedef {
    CPPCLS = 'cocos2d::EventTouch::EventCode',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'cc.EventTouch.EventCode',
}

typedef {
    CPPCLS = 'cocos2d::GlyphCollection',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'cc.GlyphCollection',
}

typedef {
    CPPCLS = 'cocos2d::Image::Format',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'cc.Image.Format',
}

typedef {
    CPPCLS = 'cocos2d::Label::LabelType',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'cc.Label.LabelType',
}

typedef {
    CPPCLS = 'cocos2d::Label::Overflow',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'cc.Label.Overflow',
}

typedef {
    CPPCLS = 'cocos2d::LabelEffect',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'cc.LabelEffect',
}

typedef {
    CPPCLS = 'cocos2d::LanguageType',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'cc.LanguageType',
}

typedef {
    CPPCLS = 'cocos2d::LightFlag',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'cc.LightFlag',
}

typedef {
    CPPCLS = 'cocos2d::LightType',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'cc.LightType',
}

typedef {
    CPPCLS = 'cocos2d::MATRIX_STACK_TYPE',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'cc.MATRIX_STACK_TYPE',
}

typedef {
    CPPCLS = 'cocos2d::ParticleSystem::Mode',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'cc.ParticleSystem.Mode',
}

typedef {
    CPPCLS = 'cocos2d::ParticleSystem::PositionType',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'cc.ParticleSystem.PositionType',
}

typedef {
    CPPCLS = 'cocos2d::ProgressTimer::Type',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'cc.ProgressTimer.Type',
}

typedef {
    CPPCLS = 'cocos2d::TextHAlignment',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'cc.TextHAlignment',
}

typedef {
    CPPCLS = 'cocos2d::TextVAlignment',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'cc.TextVAlignment',
}

typedef {
    CPPCLS = 'cocos2d::Texture2D::PixelFormat',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'cc.Texture2D.PixelFormat',
}

typedef {
    CPPCLS = 'cocos2d::Touch::DispatchMode',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'cc.Touch.DispatchMode',
}

typedef {
    CPPCLS = 'cocos2d::TransitionScene::Orientation',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'cc.TransitionScene.Orientation',
}

typedef {
    CPPCLS = 'cocos2d::experimental::AudioEngine::AudioState',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'cc.AudioEngine.AudioState',
}

typedef {
    CPPCLS = 'cocos2d::network::WebSocket::ErrorCode',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'cc.network.WebSocket.ErrorCode',
}

typedef {
    CPPCLS = 'cocos2d::network::WebSocket::State',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'cc.network.WebSocket.State',
}

typedef {
    CPPCLS = 'CocosDenshion::SimpleAudioEngine *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.SimpleAudioEngine',
}

typedef {
    CPPCLS = 'cocos2d::AccelAmplitude *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.AccelAmplitude',
}

typedef {
    CPPCLS = 'cocos2d::AccelDeccelAmplitude *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.AccelDeccelAmplitude',
}

typedef {
    CPPCLS = 'cocos2d::Acceleration *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.Acceleration',
}

typedef {
    CPPCLS = 'cocos2d::Action *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.Action',
}

typedef {
    CPPCLS = 'cocos2d::ActionCamera *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.ActionCamera',
}

typedef {
    CPPCLS = 'cocos2d::ActionEase *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.ActionEase',
}

typedef {
    CPPCLS = 'cocos2d::ActionFloat *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.ActionFloat',
}

typedef {
    CPPCLS = 'cocos2d::ActionInstant *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.ActionInstant',
}

typedef {
    CPPCLS = 'cocos2d::ActionInterval *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.ActionInterval',
}

typedef {
    CPPCLS = 'cocos2d::ActionManager *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.ActionManager',
}

typedef {
    CPPCLS = 'cocos2d::AmbientLight *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.AmbientLight',
}

typedef {
    CPPCLS = 'cocos2d::Animate *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.Animate',
}

typedef {
    CPPCLS = 'cocos2d::Animation *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.Animation',
}

typedef {
    CPPCLS = 'cocos2d::AnimationCache *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.AnimationCache',
}

typedef {
    CPPCLS = 'cocos2d::AnimationFrame *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.AnimationFrame',
}

typedef {
    CPPCLS = 'cocos2d::Application *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.Application',
}

typedef {
    CPPCLS = 'cocos2d::ApplicationProtocol *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.ApplicationProtocol',
}

typedef {
    CPPCLS = 'cocos2d::AtlasNode *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.AtlasNode',
}

typedef {
    CPPCLS = 'cocos2d::BaseLight *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.BaseLight',
}

typedef {
    CPPCLS = 'cocos2d::BezierBy *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.BezierBy',
}

typedef {
    CPPCLS = 'cocos2d::BezierTo *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.BezierTo',
}

typedef {
    CPPCLS = 'cocos2d::Blink *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.Blink',
}

typedef {
    CPPCLS = 'cocos2d::CallFunc *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.CallFunc',
}

typedef {
    CPPCLS = 'cocos2d::Camera *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.Camera',
}

typedef {
    CPPCLS = 'cocos2d::CameraBackgroundBrush *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.CameraBackgroundBrush',
}

typedef {
    CPPCLS = 'cocos2d::CameraBackgroundColorBrush *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.CameraBackgroundColorBrush',
}

typedef {
    CPPCLS = 'cocos2d::CameraBackgroundDepthBrush *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.CameraBackgroundDepthBrush',
}

typedef {
    CPPCLS = 'cocos2d::CameraBackgroundSkyBoxBrush *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.CameraBackgroundSkyBoxBrush',
}

typedef {
    CPPCLS = 'cocos2d::CardinalSplineBy *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.CardinalSplineBy',
}

typedef {
    CPPCLS = 'cocos2d::CardinalSplineTo *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.CardinalSplineTo',
}

typedef {
    CPPCLS = 'cocos2d::CatmullRomBy *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.CatmullRomBy',
}

typedef {
    CPPCLS = 'cocos2d::CatmullRomTo *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.CatmullRomTo',
}

typedef {
    CPPCLS = 'cocos2d::ClippingRectangleNode *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.ClippingRectangleNode',
}

typedef {
    CPPCLS = 'cocos2d::Component *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.Component',
}

typedef {
    CPPCLS = 'cocos2d::Controller *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.Controller',
}

typedef {
    CPPCLS = 'cocos2d::DeccelAmplitude *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.DeccelAmplitude',
}

typedef {
    CPPCLS = 'cocos2d::DelayTime *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.DelayTime',
}

typedef {
    CPPCLS = 'cocos2d::Device *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.Device',
}

typedef {
    CPPCLS = 'cocos2d::DirectionLight *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.DirectionLight',
}

typedef {
    CPPCLS = 'cocos2d::Director *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.Director',
}

typedef {
    CPPCLS = 'cocos2d::DrawNode *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.DrawNode',
}

typedef {
    CPPCLS = 'cocos2d::EaseBackIn *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.EaseBackIn',
}

typedef {
    CPPCLS = 'cocos2d::EaseBackInOut *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.EaseBackInOut',
}

typedef {
    CPPCLS = 'cocos2d::EaseBackOut *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.EaseBackOut',
}

typedef {
    CPPCLS = 'cocos2d::EaseBezierAction *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.EaseBezierAction',
}

typedef {
    CPPCLS = 'cocos2d::EaseBounceIn *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.EaseBounceIn',
}

typedef {
    CPPCLS = 'cocos2d::EaseBounceInOut *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.EaseBounceInOut',
}

typedef {
    CPPCLS = 'cocos2d::EaseBounceOut *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.EaseBounceOut',
}

typedef {
    CPPCLS = 'cocos2d::EaseCircleActionIn *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.EaseCircleActionIn',
}

typedef {
    CPPCLS = 'cocos2d::EaseCircleActionInOut *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.EaseCircleActionInOut',
}

typedef {
    CPPCLS = 'cocos2d::EaseCircleActionOut *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.EaseCircleActionOut',
}

typedef {
    CPPCLS = 'cocos2d::EaseCubicActionIn *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.EaseCubicActionIn',
}

typedef {
    CPPCLS = 'cocos2d::EaseCubicActionInOut *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.EaseCubicActionInOut',
}

typedef {
    CPPCLS = 'cocos2d::EaseCubicActionOut *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.EaseCubicActionOut',
}

typedef {
    CPPCLS = 'cocos2d::EaseElastic *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.EaseElastic',
}

typedef {
    CPPCLS = 'cocos2d::EaseElasticIn *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.EaseElasticIn',
}

typedef {
    CPPCLS = 'cocos2d::EaseElasticInOut *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.EaseElasticInOut',
}

typedef {
    CPPCLS = 'cocos2d::EaseElasticOut *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.EaseElasticOut',
}

typedef {
    CPPCLS = 'cocos2d::EaseExponentialIn *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.EaseExponentialIn',
}

typedef {
    CPPCLS = 'cocos2d::EaseExponentialInOut *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.EaseExponentialInOut',
}

typedef {
    CPPCLS = 'cocos2d::EaseExponentialOut *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.EaseExponentialOut',
}

typedef {
    CPPCLS = 'cocos2d::EaseIn *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.EaseIn',
}

typedef {
    CPPCLS = 'cocos2d::EaseInOut *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.EaseInOut',
}

typedef {
    CPPCLS = 'cocos2d::EaseOut *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.EaseOut',
}

typedef {
    CPPCLS = 'cocos2d::EaseQuadraticActionIn *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.EaseQuadraticActionIn',
}

typedef {
    CPPCLS = 'cocos2d::EaseQuadraticActionInOut *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.EaseQuadraticActionInOut',
}

typedef {
    CPPCLS = 'cocos2d::EaseQuadraticActionOut *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.EaseQuadraticActionOut',
}

typedef {
    CPPCLS = 'cocos2d::EaseQuarticActionIn *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.EaseQuarticActionIn',
}

typedef {
    CPPCLS = 'cocos2d::EaseQuarticActionInOut *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.EaseQuarticActionInOut',
}

typedef {
    CPPCLS = 'cocos2d::EaseQuarticActionOut *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.EaseQuarticActionOut',
}

typedef {
    CPPCLS = 'cocos2d::EaseQuinticActionIn *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.EaseQuinticActionIn',
}

typedef {
    CPPCLS = 'cocos2d::EaseQuinticActionInOut *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.EaseQuinticActionInOut',
}

typedef {
    CPPCLS = 'cocos2d::EaseQuinticActionOut *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.EaseQuinticActionOut',
}

typedef {
    CPPCLS = 'cocos2d::EaseRateAction *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.EaseRateAction',
}

typedef {
    CPPCLS = 'cocos2d::EaseSineIn *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.EaseSineIn',
}

typedef {
    CPPCLS = 'cocos2d::EaseSineInOut *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.EaseSineInOut',
}

typedef {
    CPPCLS = 'cocos2d::EaseSineOut *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.EaseSineOut',
}

typedef {
    CPPCLS = 'cocos2d::Event *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.Event',
}

typedef {
    CPPCLS = 'cocos2d::EventAcceleration *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.EventAcceleration',
}

typedef {
    CPPCLS = 'cocos2d::EventController *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.EventController',
}

typedef {
    CPPCLS = 'cocos2d::EventCustom *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.EventCustom',
}

typedef {
    CPPCLS = 'cocos2d::EventDispatcher *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.EventDispatcher',
}

typedef {
    CPPCLS = 'cocos2d::EventFocus *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.EventFocus',
}

typedef {
    CPPCLS = 'cocos2d::EventKeyboard *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.EventKeyboard',
}

typedef {
    CPPCLS = 'cocos2d::EventListener *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.EventListener',
}

typedef {
    CPPCLS = 'cocos2d::EventListenerAcceleration *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.EventListenerAcceleration',
}

typedef {
    CPPCLS = 'cocos2d::EventListenerController *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.EventListenerController',
}

typedef {
    CPPCLS = 'cocos2d::EventListenerCustom *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.EventListenerCustom',
}

typedef {
    CPPCLS = 'cocos2d::EventListenerFocus *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.EventListenerFocus',
}

typedef {
    CPPCLS = 'cocos2d::EventListenerKeyboard *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.EventListenerKeyboard',
}

typedef {
    CPPCLS = 'cocos2d::EventListenerMouse *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.EventListenerMouse',
}

typedef {
    CPPCLS = 'cocos2d::EventListenerTouchAllAtOnce *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.EventListenerTouchAllAtOnce',
}

typedef {
    CPPCLS = 'cocos2d::EventListenerTouchOneByOne *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.EventListenerTouchOneByOne',
}

typedef {
    CPPCLS = 'cocos2d::EventMouse *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.EventMouse',
}

typedef {
    CPPCLS = 'cocos2d::EventTouch *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.EventTouch',
}

typedef {
    CPPCLS = 'cocos2d::FadeIn *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.FadeIn',
}

typedef {
    CPPCLS = 'cocos2d::FadeOut *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.FadeOut',
}

typedef {
    CPPCLS = 'cocos2d::FadeOutBLTiles *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.FadeOutBLTiles',
}

typedef {
    CPPCLS = 'cocos2d::FadeOutDownTiles *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.FadeOutDownTiles',
}

typedef {
    CPPCLS = 'cocos2d::FadeOutTRTiles *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.FadeOutTRTiles',
}

typedef {
    CPPCLS = 'cocos2d::FadeOutUpTiles *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.FadeOutUpTiles',
}

typedef {
    CPPCLS = 'cocos2d::FadeTo *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.FadeTo',
}

typedef {
    CPPCLS = 'cocos2d::FileUtils *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.FileUtils',
}

typedef {
    CPPCLS = 'cocos2d::FiniteTimeAction *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.FiniteTimeAction',
}

typedef {
    CPPCLS = 'cocos2d::FlipX *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.FlipX',
}

typedef {
    CPPCLS = 'cocos2d::FlipX3D *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.FlipX3D',
}

typedef {
    CPPCLS = 'cocos2d::FlipY *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.FlipY',
}

typedef {
    CPPCLS = 'cocos2d::FlipY3D *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.FlipY3D',
}

typedef {
    CPPCLS = 'cocos2d::Follow *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.Follow',
}

typedef {
    CPPCLS = 'cocos2d::FontAtlas *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.FontAtlas',
}

typedef {
    CPPCLS = 'cocos2d::GLProgram *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.GLProgram',
}

typedef {
    CPPCLS = 'cocos2d::GLProgramCache *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.GLProgramCache',
}

typedef {
    CPPCLS = 'cocos2d::GLProgramState *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.GLProgramState',
}

typedef {
    CPPCLS = 'cocos2d::GLView *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.GLView',
}

typedef {
    CPPCLS = 'cocos2d::GLViewImpl *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.GLViewImpl',
}

typedef {
    CPPCLS = 'cocos2d::Grid3D *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.Grid3D',
}

typedef {
    CPPCLS = 'cocos2d::Grid3DAction *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.Grid3DAction',
}

typedef {
    CPPCLS = 'cocos2d::GridAction *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.GridAction',
}

typedef {
    CPPCLS = 'cocos2d::GridBase *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.GridBase',
}

typedef {
    CPPCLS = 'cocos2d::Hide *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.Hide',
}

typedef {
    CPPCLS = 'cocos2d::Image *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.Image',
}

typedef {
    CPPCLS = 'cocos2d::JumpBy *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.JumpBy',
}

typedef {
    CPPCLS = 'cocos2d::JumpTiles3D *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.JumpTiles3D',
}

typedef {
    CPPCLS = 'cocos2d::JumpTo *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.JumpTo',
}

typedef {
    CPPCLS = 'cocos2d::Label *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.Label',
}

typedef {
    CPPCLS = 'cocos2d::LabelAtlas *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.LabelAtlas',
}

typedef {
    CPPCLS = 'cocos2d::Layer *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.Layer',
}

typedef {
    CPPCLS = 'cocos2d::LayerColor *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.LayerColor',
}

typedef {
    CPPCLS = 'cocos2d::LayerGradient *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.LayerGradient',
}

typedef {
    CPPCLS = 'cocos2d::LayerRadialGradient *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.LayerRadialGradient',
}

typedef {
    CPPCLS = 'cocos2d::Lens3D *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.Lens3D',
}

typedef {
    CPPCLS = 'cocos2d::Liquid *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.Liquid',
}

typedef {
    CPPCLS = 'cocos2d::LuaComponent *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.LuaComponent',
}

typedef {
    CPPCLS = 'cocos2d::LuaWebSocketDelegate *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.LuaWebSocketDelegate',
}

typedef {
    CPPCLS = 'cocos2d::MoveBy *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.MoveBy',
}

typedef {
    CPPCLS = 'cocos2d::MoveTo *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.MoveTo',
}

typedef {
    CPPCLS = 'cocos2d::Node *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.Node',
}

typedef {
    CPPCLS = 'cocos2d::NodeGrid *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.NodeGrid',
}

typedef {
    CPPCLS = 'cocos2d::OrbitCamera *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.OrbitCamera',
}

typedef {
    CPPCLS = 'cocos2d::PageTurn3D *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.PageTurn3D',
}

typedef {
    CPPCLS = 'cocos2d::ParticleBatchNode *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.ParticleBatchNode',
}

typedef {
    CPPCLS = 'cocos2d::ParticleExplosion *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.ParticleExplosion',
}

typedef {
    CPPCLS = 'cocos2d::ParticleFire *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.ParticleFire',
}

typedef {
    CPPCLS = 'cocos2d::ParticleFireworks *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.ParticleFireworks',
}

typedef {
    CPPCLS = 'cocos2d::ParticleFlower *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.ParticleFlower',
}

typedef {
    CPPCLS = 'cocos2d::ParticleGalaxy *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.ParticleGalaxy',
}

typedef {
    CPPCLS = 'cocos2d::ParticleMeteor *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.ParticleMeteor',
}

typedef {
    CPPCLS = 'cocos2d::ParticleRain *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.ParticleRain',
}

typedef {
    CPPCLS = 'cocos2d::ParticleSmoke *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.ParticleSmoke',
}

typedef {
    CPPCLS = 'cocos2d::ParticleSnow *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.ParticleSnow',
}

typedef {
    CPPCLS = 'cocos2d::ParticleSpiral *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.ParticleSpiral',
}

typedef {
    CPPCLS = 'cocos2d::ParticleSun *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.ParticleSun',
}

typedef {
    CPPCLS = 'cocos2d::ParticleSystem *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.ParticleSystem',
}

typedef {
    CPPCLS = 'cocos2d::ParticleSystemQuad *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.ParticleSystemQuad',
}

typedef {
    CPPCLS = 'cocos2d::Place *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.Place',
}

typedef {
    CPPCLS = 'cocos2d::PointArray *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.PointArray',
}

typedef {
    CPPCLS = 'cocos2d::PointLight *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.PointLight',
}

typedef {
    CPPCLS = 'cocos2d::ProgressFromTo *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.ProgressFromTo',
}

typedef {
    CPPCLS = 'cocos2d::ProgressTimer *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.ProgressTimer',
}

typedef {
    CPPCLS = 'cocos2d::ProgressTo *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.ProgressTo',
}

typedef {
    CPPCLS = 'cocos2d::ProtectedNode *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.ProtectedNode',
}

typedef {
    CPPCLS = 'cocos2d::Ref *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.Ref',
}

typedef {
    CPPCLS = 'cocos2d::RemoveSelf *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.RemoveSelf',
}

typedef {
    CPPCLS = 'cocos2d::RenderTexture *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.RenderTexture',
}

typedef {
    CPPCLS = 'cocos2d::Renderer *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.Renderer',
}

typedef {
    CPPCLS = 'cocos2d::Repeat *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.Repeat',
}

typedef {
    CPPCLS = 'cocos2d::RepeatForever *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.RepeatForever',
}

typedef {
    CPPCLS = 'cocos2d::ResizeBy *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.ResizeBy',
}

typedef {
    CPPCLS = 'cocos2d::ResizeTo *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.ResizeTo',
}

typedef {
    CPPCLS = 'cocos2d::ReuseGrid *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.ReuseGrid',
}

typedef {
    CPPCLS = 'cocos2d::ReverseTime *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.ReverseTime',
}

typedef {
    CPPCLS = 'cocos2d::Ripple3D *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.Ripple3D',
}

typedef {
    CPPCLS = 'cocos2d::RotateBy *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.RotateBy',
}

typedef {
    CPPCLS = 'cocos2d::RotateTo *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.RotateTo',
}

typedef {
    CPPCLS = 'cocos2d::ScaleBy *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.ScaleBy',
}

typedef {
    CPPCLS = 'cocos2d::ScaleTo *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.ScaleTo',
}

typedef {
    CPPCLS = 'cocos2d::Scene *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.Scene',
}

typedef {
    CPPCLS = 'cocos2d::Scheduler *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.Scheduler',
}

typedef {
    CPPCLS = 'cocos2d::Sequence *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.Sequence',
}

typedef {
    CPPCLS = 'cocos2d::Shaky3D *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.Shaky3D',
}

typedef {
    CPPCLS = 'cocos2d::ShakyTiles3D *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.ShakyTiles3D',
}

typedef {
    CPPCLS = 'cocos2d::ShatteredTiles3D *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.ShatteredTiles3D',
}

typedef {
    CPPCLS = 'cocos2d::Show *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.Show',
}

typedef {
    CPPCLS = 'cocos2d::ShuffleTiles *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.ShuffleTiles',
}

typedef {
    CPPCLS = 'cocos2d::SkewBy *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.SkewBy',
}

typedef {
    CPPCLS = 'cocos2d::SkewTo *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.SkewTo',
}

typedef {
    CPPCLS = 'cocos2d::Spawn *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.Spawn',
}

typedef {
    CPPCLS = 'cocos2d::Speed *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.Speed',
}

typedef {
    CPPCLS = 'cocos2d::SplitCols *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.SplitCols',
}

typedef {
    CPPCLS = 'cocos2d::SplitRows *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.SplitRows',
}

typedef {
    CPPCLS = 'cocos2d::SpotLight *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.SpotLight',
}

typedef {
    CPPCLS = 'cocos2d::Sprite *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.Sprite',
}

typedef {
    CPPCLS = 'cocos2d::SpriteBatchNode *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.SpriteBatchNode',
}

typedef {
    CPPCLS = 'cocos2d::SpriteFrame *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.SpriteFrame',
}

typedef {
    CPPCLS = 'cocos2d::SpriteFrameCache *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.SpriteFrameCache',
}

typedef {
    CPPCLS = 'cocos2d::StopGrid *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.StopGrid',
}

typedef {
    CPPCLS = 'cocos2d::TargetedAction *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.TargetedAction',
}

typedef {
    CPPCLS = 'cocos2d::TextFieldDelegate *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.TextFieldDelegate',
}

typedef {
    CPPCLS = 'cocos2d::TextFieldTTF *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.TextFieldTTF',
}

typedef {
    CPPCLS = 'cocos2d::Texture2D *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.Texture2D',
}

typedef {
    CPPCLS = 'cocos2d::TextureAtlas *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.TextureAtlas',
}

typedef {
    CPPCLS = 'cocos2d::TextureCache *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.TextureCache',
}

typedef {
    CPPCLS = 'cocos2d::TextureCube *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.TextureCube',
}

typedef {
    CPPCLS = 'cocos2d::TiledGrid3D *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.TiledGrid3D',
}

typedef {
    CPPCLS = 'cocos2d::TiledGrid3DAction *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.TiledGrid3DAction',
}

typedef {
    CPPCLS = 'cocos2d::TintBy *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.TintBy',
}

typedef {
    CPPCLS = 'cocos2d::TintTo *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.TintTo',
}

typedef {
    CPPCLS = 'cocos2d::ToggleVisibility *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.ToggleVisibility',
}

typedef {
    CPPCLS = 'cocos2d::Touch *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.Touch',
}

typedef {
    CPPCLS = 'cocos2d::TransitionCrossFade *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.TransitionCrossFade',
}

typedef {
    CPPCLS = 'cocos2d::TransitionFade *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.TransitionFade',
}

typedef {
    CPPCLS = 'cocos2d::TransitionFadeBL *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.TransitionFadeBL',
}

typedef {
    CPPCLS = 'cocos2d::TransitionFadeDown *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.TransitionFadeDown',
}

typedef {
    CPPCLS = 'cocos2d::TransitionFadeTR *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.TransitionFadeTR',
}

typedef {
    CPPCLS = 'cocos2d::TransitionFadeUp *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.TransitionFadeUp',
}

typedef {
    CPPCLS = 'cocos2d::TransitionFlipAngular *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.TransitionFlipAngular',
}

typedef {
    CPPCLS = 'cocos2d::TransitionFlipX *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.TransitionFlipX',
}

typedef {
    CPPCLS = 'cocos2d::TransitionFlipY *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.TransitionFlipY',
}

typedef {
    CPPCLS = 'cocos2d::TransitionJumpZoom *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.TransitionJumpZoom',
}

typedef {
    CPPCLS = 'cocos2d::TransitionMoveInB *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.TransitionMoveInB',
}

typedef {
    CPPCLS = 'cocos2d::TransitionMoveInL *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.TransitionMoveInL',
}

typedef {
    CPPCLS = 'cocos2d::TransitionMoveInR *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.TransitionMoveInR',
}

typedef {
    CPPCLS = 'cocos2d::TransitionMoveInT *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.TransitionMoveInT',
}

typedef {
    CPPCLS = 'cocos2d::TransitionPageTurn *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.TransitionPageTurn',
}

typedef {
    CPPCLS = 'cocos2d::TransitionProgress *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.TransitionProgress',
}

typedef {
    CPPCLS = 'cocos2d::TransitionProgressHorizontal *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.TransitionProgressHorizontal',
}

typedef {
    CPPCLS = 'cocos2d::TransitionProgressInOut *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.TransitionProgressInOut',
}

typedef {
    CPPCLS = 'cocos2d::TransitionProgressOutIn *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.TransitionProgressOutIn',
}

typedef {
    CPPCLS = 'cocos2d::TransitionProgressRadialCCW *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.TransitionProgressRadialCCW',
}

typedef {
    CPPCLS = 'cocos2d::TransitionProgressRadialCW *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.TransitionProgressRadialCW',
}

typedef {
    CPPCLS = 'cocos2d::TransitionProgressVertical *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.TransitionProgressVertical',
}

typedef {
    CPPCLS = 'cocos2d::TransitionRotoZoom *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.TransitionRotoZoom',
}

typedef {
    CPPCLS = 'cocos2d::TransitionScene *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.TransitionScene',
}

typedef {
    CPPCLS = 'cocos2d::TransitionSceneOriented *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.TransitionSceneOriented',
}

typedef {
    CPPCLS = 'cocos2d::TransitionShrinkGrow *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.TransitionShrinkGrow',
}

typedef {
    CPPCLS = 'cocos2d::TransitionSlideInB *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.TransitionSlideInB',
}

typedef {
    CPPCLS = 'cocos2d::TransitionSlideInL *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.TransitionSlideInL',
}

typedef {
    CPPCLS = 'cocos2d::TransitionSlideInR *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.TransitionSlideInR',
}

typedef {
    CPPCLS = 'cocos2d::TransitionSlideInT *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.TransitionSlideInT',
}

typedef {
    CPPCLS = 'cocos2d::TransitionSplitCols *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.TransitionSplitCols',
}

typedef {
    CPPCLS = 'cocos2d::TransitionSplitRows *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.TransitionSplitRows',
}

typedef {
    CPPCLS = 'cocos2d::TransitionTurnOffTiles *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.TransitionTurnOffTiles',
}

typedef {
    CPPCLS = 'cocos2d::TransitionZoomFlipAngular *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.TransitionZoomFlipAngular',
}

typedef {
    CPPCLS = 'cocos2d::TransitionZoomFlipX *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.TransitionZoomFlipX',
}

typedef {
    CPPCLS = 'cocos2d::TransitionZoomFlipY *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.TransitionZoomFlipY',
}

typedef {
    CPPCLS = 'cocos2d::TurnOffTiles *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.TurnOffTiles',
}

typedef {
    CPPCLS = 'cocos2d::Twirl *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.Twirl',
}

typedef {
    CPPCLS = 'cocos2d::UserDefault *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.UserDefault',
}

typedef {
    CPPCLS = 'cocos2d::VRGenericHeadTracker *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.VRGenericHeadTracker',
}

typedef {
    CPPCLS = 'cocos2d::VRGenericRenderer *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.VRGenericRenderer',
}

typedef {
    CPPCLS = 'cocos2d::VRIHeadTracker *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.VRIHeadTracker',
}

typedef {
    CPPCLS = 'cocos2d::VRIRenderer *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.VRIRenderer',
}

typedef {
    CPPCLS = 'cocos2d::Waves *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.Waves',
}

typedef {
    CPPCLS = 'cocos2d::Waves3D *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.Waves3D',
}

typedef {
    CPPCLS = 'cocos2d::WavesTiles3D *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.WavesTiles3D',
}

typedef {
    CPPCLS = 'cocos2d::experimental::AudioEngine *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.AudioEngine',
}

typedef {
    CPPCLS = 'cocos2d::experimental::AudioProfile *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.AudioProfile',
}

typedef {
    CPPCLS = 'cocos2d::network::WebSocket *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.network.WebSocket',
}

typedef {
    CPPCLS = 'cocos2d::network::WebSocket::Delegate *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.network.WebSocket.Delegate',
}

typedef {
    CPPCLS = 'cocos2d::tweenfunc *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.tweenfunc',
}

