module 'conv'

path "../../frameworks/libxgame/src/lua-bindings"

headers [[
#include "cclua/cclua.h"
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "network/WebSocket.h"
]]

typeconv 'cocos2d::Vec2'
    .var '*' .optional 'false'
    
typeconv 'cocos2d::Vec3'
typeconv 'cocos2d::Vec4'
typeconv 'cocos2d::Size'
typeconv 'cocos2d::Texture2D::TexParams'

typeconv 'cocos2d::experimental::Viewport'
typeconv 'cocos2d::Quaternion'
typeconv 'cocos2d::AffineTransform'
typeconv 'cocos2d::ccBezierConfig'
typeconv 'GLContextAttrs'
typeconv 'cocos2d::Tex2F'
typeconv 'cocos2d::T2F_Quad'
typeconv 'cocos2d::TTFConfig'
    .var '*' .optional 'true'

typeconv 'cocos2d::BlendFunc'
typeconv 'cocos2d::ui::Margin'
typeconv 'cocos2d::ResourceData'
typeconv 'cocos2d::Quad3'
typeconv 'cocos2d::Controller::KeyStatus'
