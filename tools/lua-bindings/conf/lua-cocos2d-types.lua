module 'cocos2d_types'

path "../../frameworks/libxgame/src/lua-bindings"

headers [[
#include "cclua/cclua.h"
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "network/WebSocket.h"
#include "lua-bindings/lua_conv_manual.h"
]]

luacls(function (cppname)
    return cppname:gsub("^cocos2d::types::", "cc.")
            :gsub("^cocos2d::", "cc.")
            :gsub("::", ".")
            :gsub("GLContextAttrs", "cc.GLContextAttrs")
end)

typedef 'cocos2d::Data'
typedef 'cocos2d::Vector'
    .conv 'olua_$$_array'
typedef 'cocos2d::Color3B'
typedef 'cocos2d::Color4B'
typedef 'cocos2d::Color4F'
typedef 'cocos2d::Value'
typedef 'cocos2d::ValueMap'
typedef 'cocos2d::ValueMapIntKey'
typedef 'cocos2d::ValueVector'
typedef 'cocos2d::Map'
    .conv 'olua_$$_map'
typedef 'cocos2d::network::WebSocket::Data'

typeconf 'cocos2d::Vec2'
    .packable 'true'
    .var '*' .optional 'false'
typeconf 'cocos2d::Vec3'
    .packable 'true'
typeconf 'cocos2d::Vec4'
    .packable 'true'
typeconf 'cocos2d::Size'
    .packable 'true'
typeconf 'cocos2d::Rect'
    .extend 'cocos2d::RectExtend'
    .packable 'true'
    .packvars '4'
typeconf 'cocos2d::Bounds'
    .packable 'true'
typeconf 'cocos2d::Mat4'
    .extend 'cocos2d::Mat4Extend'
    .exclude 'm'

typeconf 'cocos2d::Texture2D::TexParams'

typeconf 'cocos2d::experimental::Viewport'
typeconf 'cocos2d::Quaternion'
typeconf 'cocos2d::AffineTransform'
typeconf 'GLContextAttrs'
typeconf 'cocos2d::Tex2F'
typeconf 'cocos2d::T2F_Quad'
typeconf 'cocos2d::ccBezierConfig'
    .packable 'true'
typeconf 'cocos2d::TTFConfig'
    .var '*' .optional 'true'

typeconf 'cocos2d::BlendFunc'
typeconf 'cocos2d::ui::Margin'
typeconf 'cocos2d::ResourceData'
typeconf 'cocos2d::Quad3'
typeconf 'cocos2d::Controller::KeyStatus'

typeconf 'cocos2d::types::VectorString'
typeconf 'cocos2d::types::VectorInt'
typeconf 'cocos2d::types::ValueMap'
typeconf 'cocos2d::types::TMXTileFlags'

