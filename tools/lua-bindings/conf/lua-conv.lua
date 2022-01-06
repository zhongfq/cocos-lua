module 'conv'

path "../../frameworks/libxgame/src/lua-bindings"

headers [[
#include "cclua/xlua.h"
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "network/WebSocket.h"
#include "navmesh/CCNavMesh.h"
]]

typeconv 'cocos2d::Vec2'
    .attr('*', {optional = false})

typeconv 'cocos2d::Vec3'
typeconv 'cocos2d::Vec4'
typeconv 'cocos2d::Size'
typeconv 'cocos2d::Viewport'
typeconv 'cocos2d::ScissorRect'
typeconv 'cocos2d::Quaternion'
typeconv 'cocos2d::AffineTransform'
typeconv 'GLContextAttrs'
typeconv 'cocos2d::Tex2F'
typeconv 'cocos2d::T2F_Quad'
typeconv 'cocos2d::ccBezierConfig'

typeconv 'cocos2d::TTFConfig'
    .attr('*', {optional = true})

typeconv 'cocos2d::BlendFunc'
typeconv 'cocos2d::ui::Margin'
typeconv 'cocos2d::ResourceData'
typeconv 'cocos2d::Quad3'
typeconv 'cocos2d::Texture2D::PixelFormatInfo'
typeconv 'cocos2d::Controller::KeyStatus'
typeconv 'cocos2d::NavMeshAgentParam'
typeconv 'cocos2d::OffMeshLinkData'
typeconv 'cocos2d::backend::BlendDescriptor'
typeconv 'cocos2d::backend::SamplerDescriptor'

typeconv 'cocos2d::backend::TextureInfo'
    .exclude 'location'

typeconv 'cocos2d::backend::AttributeBindInfo'
typeconv 'cocos2d::backend::UniformInfo'
typeconv 'cocos2d::backend::TextureDescriptor'
typeconv 'cocos2d::backend::StencilDescriptor'
typeconv 'cocos2d::backend::DepthStencilDescriptor'
typeconv 'cocos2d::backend::VertexLayout::Attribute'
