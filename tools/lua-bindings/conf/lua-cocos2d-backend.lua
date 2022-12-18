module 'cocos2d_backend'

path '../../frameworks/cclua/src/lua-bindings'

headers [[
#include "lua-bindings/lua_cocos2d_types.h"
#include "lua-bindings/lua_conv_manual.h"
#include "cocos2d.h"
]]

luacls(function (cppname)
    cppname = string.gsub(cppname, "^cocos2d::backend::", "ccb.")
    cppname = string.gsub(cppname, "::", ".")
    return cppname
end)

excludetype 'cocos2d::backend::RenderPassDescriptor'

typeconf 'cocos2d::backend::UniformLocation'
typeconf 'cocos2d::backend::BufferUsage'
typeconf 'cocos2d::backend::BufferType'
typeconf 'cocos2d::backend::ShaderStage'
typeconf 'cocos2d::backend::VertexFormat'
typeconf 'cocos2d::backend::PixelFormat'
typeconf 'cocos2d::backend::TextureUsage'
typeconf 'cocos2d::backend::IndexFormat'
typeconf 'cocos2d::backend::VertexStepMode'
typeconf 'cocos2d::backend::PrimitiveType'
typeconf 'cocos2d::backend::TextureType'
typeconf 'cocos2d::backend::SamplerAddressMode'
typeconf 'cocos2d::backend::SamplerFilter'
typeconf 'cocos2d::backend::StencilOperation'
typeconf 'cocos2d::backend::CompareFunction'
typeconf 'cocos2d::backend::BlendOperation'
typeconf 'cocos2d::backend::BlendFactor'
typeconf 'cocos2d::backend::ColorWriteMask'
typeconf 'cocos2d::backend::CullMode'
typeconf 'cocos2d::backend::Winding'
typeconf 'cocos2d::backend::TextureCubeFace'
typeconf 'cocos2d::backend::ProgramType'
typeconf 'cocos2d::backend::Uniform'
typeconf 'cocos2d::backend::Attribute'
typeconf 'cocos2d::backend::FeatureType'
typeconf 'cocos2d::backend::Buffer'
typeconf 'cocos2d::backend::RenderPipeline'
typeconf 'cocos2d::backend::DepthStencilState'
typeconf 'cocos2d::backend::VertexLayout'

typeconf 'cocos2d::backend::CommandBuffer'
    .callback 'captureScreen'
        .tag_scope 'once'
        .tag_mode 'new'

typeconf 'cocos2d::backend::Device'
    .func 'newProgram' .ret '@postnew'
    .func 'newRenderPipeline' .ret '@postnew'
    .func 'newTexture' .ret '@postnew'
    .func 'newBuffer' .ret '@postnew'
    .func 'newCommandBuffer' .ret '@postnew'

typeconf 'cocos2d::backend::DeviceInfo'
typeconf 'cocos2d::backend::ShaderCache'
typeconf 'cocos2d::backend::ShaderModule'
typeconf 'cocos2d::backend::ProgramCache'

typeconf 'cocos2d::backend::ProgramState'
    .exclude 'setCallbackUniform'
    .exclude 'getCallbackUniforms'
    .exclude 'getVertexUniformBuffer'
    .exclude 'getFragmentUniformBuffer'
    .func 'getVertexLayout'
        .snippet [[
        {
            auto self = olua_toobj<cocos2d::backend::ProgramState>(L, 1);
            olua_pushobj<cocos2d::backend::VertexLayout>(L, self->getVertexLayout().get());
            olua_addref(L, 1, "vertexLayout", -1, OLUA_FLAG_SINGLE);
            return 1;
        }]]

typeconf 'cocos2d::backend::Program'

typeconf 'cocos2d::backend::TextureBackend'
    .callback 'getBytes'
        .tag_mode 'new'
        .tag_scope 'once'

typeconf 'cocos2d::backend::Texture2DBackend'
typeconf 'cocos2d::backend::TextureCubemapBackend'
