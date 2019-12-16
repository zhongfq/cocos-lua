local autoconf = require "autoconf"
local M = autoconf.typemod 'conv'
local typeconv = M.typeconv

M.PATH = "../../frameworks/libxgame/src/lua-bindings"

M.HEADER_INCLUDES = [[
#include "xgame/xlua.h"
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "network/WebSocket.h"
]]

M.INCLUDES = [[
#include "lua-bindings/lua_conv.h"
]]

M.MAKE_LUACLS = function () return '' end

typeconv 'cocos2d::Vec2'
    .ATTR('*', {OPTIONAL = false})
    
typeconv 'cocos2d::Vec3'
typeconv 'cocos2d::Vec4'
typeconv 'cocos2d::Size'
typeconv 'cocos2d::Texture2D::TexParams'

typeconv 'cocos2d::experimental::Viewport'
    .VAR('left', 'float _left')
    .VAR('bottom', 'float _bottom')
    .VAR('width', 'float _width')
    .VAR('height', 'float _height')

typeconv 'cocos2d::Quaternion'
typeconv 'cocos2d::AffineTransform'
typeconv 'GLContextAttrs'
typeconv 'cocos2d::Tex2F'
typeconv 'cocos2d::T2F_Quad'
typeconv 'cocos2d::TTFConfig'
    .ATTR('*', {OPTIONAL = true})

typeconv 'cocos2d::BlendFunc'
typeconv 'cocos2d::ui::Margin'
typeconv 'cocos2d::ResourceData'
typeconv 'cocos2d::Quad3'
typeconv 'cocos2d::Controller::KeyStatus'
typeconv 'cocos2d::network::WebSocket::Data'

return M