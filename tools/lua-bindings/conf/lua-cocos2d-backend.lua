local autoconf = require "autoconf"
local M = autoconf.typemod 'cocos2d_backend'
local typeconf = M.typeconf
local typedef = M.typedef

M.PATH = '../../frameworks/libxgame/src/lua-bindings'
M.INCLUDES = [[
#include "lua-bindings/lua_cocos2d_backend.h"
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "cocos2d.h"
#include "xgame/xlua.h"
]]

M.MAKE_LUACLS = function (cppname)
    cppname = string.gsub(cppname, "^cocos2d::backend::", "ccb.")
    cppname = string.gsub(cppname, "::", ".")
    return cppname
end

M.EXCLUDE_TYPE = require "conf.exclude-type"
M.EXCLUDE_TYPE 'cocos2d::backend::RenderPassDescriptor'

typedef {
    CPPCLS = 'cocos2d::backend::UniformLocation',
    CONV = 'manual_olua_$$_cocos2d_backend_UniformLocation',
}

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
    .CALLBACK {NAME = 'captureScreen', TAG_SCOPE = 'once', TAG_MODE = 'OLUA_TAG_NEW'}

local Device = typeconf 'cocos2d::backend::Device'
Device.INJECT({
    'newProgram',
    'newRenderPipeline',
    'newTexture',
    'newBuffer',
    'newCommandBuffer'
}, {
    AFTER = [[
        ret->autorelease();
    ]]
})

typeconf 'cocos2d::backend::DeviceInfo'
typeconf 'cocos2d::backend::ShaderCache'
typeconf 'cocos2d::backend::ShaderModule'
typeconf 'cocos2d::backend::ProgramCache'

local ProgramState = typeconf 'cocos2d::backend::ProgramState'
ProgramState.CHUNK = [[
static inline void olua_check_value(lua_State *L, int idx, cocos2d::Vec2 *value)
{
    auto_olua_check_cocos2d_Vec2(L, idx, value);
}

static inline void olua_check_value(lua_State *L, int idx, cocos2d::Vec3 *value)
{
    auto_olua_check_cocos2d_Vec3(L, idx, value);
}

static inline void olua_check_value(lua_State *L, int idx, cocos2d::Vec4 *value)
{
    auto_olua_check_cocos2d_Vec4(L, idx, value);
}

static inline void olua_check_value(lua_State *L, int idx, cocos2d::Mat4 *value)
{
    manual_olua_check_cocos2d_Mat4(L, idx, value);
}

static inline void olua_check_value(lua_State *L, int idx, int *value)
{
    *value = (int)olua_checkinteger(L, idx);
}

static inline void olua_check_value(lua_State *L, int idx, float *value)
{
    *value = (float)olua_checknumber(L, idx);
}

template <typename T> int _cocos2d_backend_ProgramState_setUniform(lua_State *L)
{
    cocos2d::backend::UniformLocation location;
    T value;
    auto self = olua_toobj<cocos2d::backend::ProgramState>(L, 1);
    if (olua_isstring(L, 2)) {
        location = self->getUniformLocation(olua_checkstring(L, 2));
    } else {
        manual_olua_check_cocos2d_backend_UniformLocation(L, 2, &location);
    }
    olua_check_value(L, 3, &value);
    self->setUniform(location, &value, sizeof(T));
    return 0;
}
]]
ProgramState.EXCLUDE 'setCallbackUniform'
ProgramState.EXCLUDE 'getCallbackUniforms'
ProgramState.EXCLUDE 'getVertexUniformBuffer'
ProgramState.EXCLUDE 'getFragmentUniformBuffer'
ProgramState.FUNC('getVertexLayout', [[
{
    auto self = olua_toobj<cocos2d::backend::ProgramState>(L, 1);
    olua_push_cppobj<cocos2d::backend::VertexLayout>(L, self->getVertexLayout().get());
    olua_addref(L, 1, "vertexLayout", -1, OLUA_MODE_SINGLE);
    return 1;
}]])
ProgramState.FUNC('setUniformVec2', [[
{
    _cocos2d_backend_ProgramState_setUniform<cocos2d::Vec2>(L);
    return 0;
}]])
ProgramState.FUNC('setUniformVec3', [[
{
    _cocos2d_backend_ProgramState_setUniform<cocos2d::Vec3>(L);
    return 0;
}]])
ProgramState.FUNC('setUniformVec4', [[
{
    _cocos2d_backend_ProgramState_setUniform<cocos2d::Vec4>(L);
    return 0;
}]])
ProgramState.FUNC('setUniformMat4', [[
{
    _cocos2d_backend_ProgramState_setUniform<cocos2d::Mat4>(L);
    return 0;
}]])
ProgramState.FUNC('setUniformInt', [[
{
    _cocos2d_backend_ProgramState_setUniform<int>(L);
    return 0;
}]])
ProgramState.FUNC('setUniformFloat', [[
{
    _cocos2d_backend_ProgramState_setUniform<float>(L);
    return 0;
}]])

typeconf 'cocos2d::backend::Program'

typeconf 'cocos2d::backend::TextureBackend'
    .CALLBACK {
        NAME = 'getBytes',
        TAG_MODE = 'OLUA_TAG_NEW',
        TAG_SCOPE = 'once',
    }

typeconf 'cocos2d::backend::Texture2DBackend'
typeconf 'cocos2d::backend::TextureCubemapBackend'

return M