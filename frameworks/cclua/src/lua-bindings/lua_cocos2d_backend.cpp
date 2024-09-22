//
// AUTO GENERATED, DO NOT MODIFY!
//
#include "lua_cocos2d_backend.h"
#include "lua-bindings/lua_cocos2d_types.h"
#include "lua-bindings/lua_conv_manual.h"
#include "cocos2d.h"

static int _olua_module_cocos2d_backend(lua_State *L);

static int _olua_fun_cocos2d_backend_UniformLocation___eq(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::UniformLocation *self = nullptr;
    cocos2d::backend::UniformLocation *arg1;       /** other */

    olua_to_object(L, 1, &self, "ccb.UniformLocation");
    olua_check_object(L, 2, &arg1, "ccb.UniformLocation");

    // @operator(operator==) bool operator==(const cocos2d::backend::UniformLocation &other)
    bool ret = (*self) == (*arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_UniformLocation___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::backend::UniformLocation *)olua_toobj(L, 1, "ccb.UniformLocation");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_UniformLocation_new(lua_State *L)
{
    olua_startinvoke(L);

    // cocos2d::backend::UniformLocation()
    cocos2d::backend::UniformLocation *ret = new cocos2d::backend::UniformLocation();
    int num_ret = olua_push_object(L, ret, "ccb.UniformLocation");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_UniformLocation_reset(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::UniformLocation *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.UniformLocation");

    // void reset()
    self->reset();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_UniformLocation_shaderStage$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::UniformLocation *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.UniformLocation");

    // cocos2d::backend::ShaderStage shaderStage
    cocos2d::backend::ShaderStage ret = self->shaderStage;
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_UniformLocation_shaderStage$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::UniformLocation *self = nullptr;
    cocos2d::backend::ShaderStage arg1 = (cocos2d::backend::ShaderStage)0;       /** shaderStage */

    olua_to_object(L, 1, &self, "ccb.UniformLocation");
    olua_check_enum(L, 2, &arg1);

    // cocos2d::backend::ShaderStage shaderStage
    self->shaderStage = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_UniformLocation_shaderStage(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // cocos2d::backend::ShaderStage shaderStage
        return _olua_fun_cocos2d_backend_UniformLocation_shaderStage$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccb.UniformLocation")) && (olua_is_enum(L, 2))) {
            // cocos2d::backend::ShaderStage shaderStage
            return _olua_fun_cocos2d_backend_UniformLocation_shaderStage$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::backend::UniformLocation::shaderStage' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_ccb_UniformLocation(lua_State *L)
{
    oluacls_class<cocos2d::backend::UniformLocation>(L, "ccb.UniformLocation");
    oluacls_func(L, "__eq", _olua_fun_cocos2d_backend_UniformLocation___eq);
    oluacls_func(L, "__gc", _olua_fun_cocos2d_backend_UniformLocation___gc);
    oluacls_func(L, "new", _olua_fun_cocos2d_backend_UniformLocation_new);
    oluacls_func(L, "reset", _olua_fun_cocos2d_backend_UniformLocation_reset);
    oluacls_prop(L, "shaderStage", _olua_fun_cocos2d_backend_UniformLocation_shaderStage, _olua_fun_cocos2d_backend_UniformLocation_shaderStage);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccb_UniformLocation(lua_State *L)
{
    olua_require(L, "cocos2d_backend",  _olua_module_cocos2d_backend);
    if (!olua_getclass(L, "ccb.UniformLocation")) {
        luaL_error(L, "class not found: cocos2d::backend::UniformLocation");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_ccb_BufferUsage(lua_State *L)
{
    oluacls_class<cocos2d::backend::BufferUsage>(L, "ccb.BufferUsage");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "DYNAMIC", (lua_Integer)cocos2d::backend::BufferUsage::DYNAMIC);
    oluacls_enum(L, "STATIC", (lua_Integer)cocos2d::backend::BufferUsage::STATIC);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccb_BufferUsage(lua_State *L)
{
    olua_require(L, "cocos2d_backend",  _olua_module_cocos2d_backend);
    if (!olua_getclass(L, "ccb.BufferUsage")) {
        luaL_error(L, "class not found: cocos2d::backend::BufferUsage");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_ccb_BufferType(lua_State *L)
{
    oluacls_class<cocos2d::backend::BufferType>(L, "ccb.BufferType");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "INDEX", (lua_Integer)cocos2d::backend::BufferType::INDEX);
    oluacls_enum(L, "VERTEX", (lua_Integer)cocos2d::backend::BufferType::VERTEX);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccb_BufferType(lua_State *L)
{
    olua_require(L, "cocos2d_backend",  _olua_module_cocos2d_backend);
    if (!olua_getclass(L, "ccb.BufferType")) {
        luaL_error(L, "class not found: cocos2d::backend::BufferType");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_ccb_ShaderStage(lua_State *L)
{
    oluacls_class<cocos2d::backend::ShaderStage>(L, "ccb.ShaderStage");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "FRAGMENT", (lua_Integer)cocos2d::backend::ShaderStage::FRAGMENT);
    oluacls_enum(L, "VERTEX", (lua_Integer)cocos2d::backend::ShaderStage::VERTEX);
    oluacls_enum(L, "VERTEX_AND_FRAGMENT", (lua_Integer)cocos2d::backend::ShaderStage::VERTEX_AND_FRAGMENT);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccb_ShaderStage(lua_State *L)
{
    olua_require(L, "cocos2d_backend",  _olua_module_cocos2d_backend);
    if (!olua_getclass(L, "ccb.ShaderStage")) {
        luaL_error(L, "class not found: cocos2d::backend::ShaderStage");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_ccb_VertexFormat(lua_State *L)
{
    oluacls_class<cocos2d::backend::VertexFormat>(L, "ccb.VertexFormat");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "FLOAT", (lua_Integer)cocos2d::backend::VertexFormat::FLOAT);
    oluacls_enum(L, "FLOAT2", (lua_Integer)cocos2d::backend::VertexFormat::FLOAT2);
    oluacls_enum(L, "FLOAT3", (lua_Integer)cocos2d::backend::VertexFormat::FLOAT3);
    oluacls_enum(L, "FLOAT4", (lua_Integer)cocos2d::backend::VertexFormat::FLOAT4);
    oluacls_enum(L, "INT", (lua_Integer)cocos2d::backend::VertexFormat::INT);
    oluacls_enum(L, "INT2", (lua_Integer)cocos2d::backend::VertexFormat::INT2);
    oluacls_enum(L, "INT3", (lua_Integer)cocos2d::backend::VertexFormat::INT3);
    oluacls_enum(L, "INT4", (lua_Integer)cocos2d::backend::VertexFormat::INT4);
    oluacls_enum(L, "UBYTE4", (lua_Integer)cocos2d::backend::VertexFormat::UBYTE4);
    oluacls_enum(L, "USHORT2", (lua_Integer)cocos2d::backend::VertexFormat::USHORT2);
    oluacls_enum(L, "USHORT4", (lua_Integer)cocos2d::backend::VertexFormat::USHORT4);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccb_VertexFormat(lua_State *L)
{
    olua_require(L, "cocos2d_backend",  _olua_module_cocos2d_backend);
    if (!olua_getclass(L, "ccb.VertexFormat")) {
        luaL_error(L, "class not found: cocos2d::backend::VertexFormat");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_ccb_PixelFormat(lua_State *L)
{
    oluacls_class<cocos2d::backend::PixelFormat>(L, "ccb.PixelFormat");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "A8", (lua_Integer)cocos2d::backend::PixelFormat::A8);
    oluacls_enum(L, "AI88", (lua_Integer)cocos2d::backend::PixelFormat::AI88);
    oluacls_enum(L, "ATC_EXPLICIT_ALPHA", (lua_Integer)cocos2d::backend::PixelFormat::ATC_EXPLICIT_ALPHA);
    oluacls_enum(L, "ATC_INTERPOLATED_ALPHA", (lua_Integer)cocos2d::backend::PixelFormat::ATC_INTERPOLATED_ALPHA);
    oluacls_enum(L, "ATC_RGB", (lua_Integer)cocos2d::backend::PixelFormat::ATC_RGB);
    oluacls_enum(L, "AUTO", (lua_Integer)cocos2d::backend::PixelFormat::AUTO);
    oluacls_enum(L, "BGRA8888", (lua_Integer)cocos2d::backend::PixelFormat::BGRA8888);
    oluacls_enum(L, "D24S8", (lua_Integer)cocos2d::backend::PixelFormat::D24S8);
    oluacls_enum(L, "DEFAULT", (lua_Integer)cocos2d::backend::PixelFormat::DEFAULT);
    oluacls_enum(L, "ETC", (lua_Integer)cocos2d::backend::PixelFormat::ETC);
    oluacls_enum(L, "I8", (lua_Integer)cocos2d::backend::PixelFormat::I8);
    oluacls_enum(L, "MTL_ABGR4", (lua_Integer)cocos2d::backend::PixelFormat::MTL_ABGR4);
    oluacls_enum(L, "MTL_B5G6R5", (lua_Integer)cocos2d::backend::PixelFormat::MTL_B5G6R5);
    oluacls_enum(L, "MTL_BGR5A1", (lua_Integer)cocos2d::backend::PixelFormat::MTL_BGR5A1);
    oluacls_enum(L, "NONE", (lua_Integer)cocos2d::backend::PixelFormat::NONE);
    oluacls_enum(L, "PVRTC2", (lua_Integer)cocos2d::backend::PixelFormat::PVRTC2);
    oluacls_enum(L, "PVRTC2A", (lua_Integer)cocos2d::backend::PixelFormat::PVRTC2A);
    oluacls_enum(L, "PVRTC4", (lua_Integer)cocos2d::backend::PixelFormat::PVRTC4);
    oluacls_enum(L, "PVRTC4A", (lua_Integer)cocos2d::backend::PixelFormat::PVRTC4A);
    oluacls_enum(L, "RGB565", (lua_Integer)cocos2d::backend::PixelFormat::RGB565);
    oluacls_enum(L, "RGB5A1", (lua_Integer)cocos2d::backend::PixelFormat::RGB5A1);
    oluacls_enum(L, "RGB888", (lua_Integer)cocos2d::backend::PixelFormat::RGB888);
    oluacls_enum(L, "RGBA4444", (lua_Integer)cocos2d::backend::PixelFormat::RGBA4444);
    oluacls_enum(L, "RGBA8888", (lua_Integer)cocos2d::backend::PixelFormat::RGBA8888);
    oluacls_enum(L, "S3TC_DXT1", (lua_Integer)cocos2d::backend::PixelFormat::S3TC_DXT1);
    oluacls_enum(L, "S3TC_DXT3", (lua_Integer)cocos2d::backend::PixelFormat::S3TC_DXT3);
    oluacls_enum(L, "S3TC_DXT5", (lua_Integer)cocos2d::backend::PixelFormat::S3TC_DXT5);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccb_PixelFormat(lua_State *L)
{
    olua_require(L, "cocos2d_backend",  _olua_module_cocos2d_backend);
    if (!olua_getclass(L, "ccb.PixelFormat")) {
        luaL_error(L, "class not found: cocos2d::backend::PixelFormat");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_ccb_TextureUsage(lua_State *L)
{
    oluacls_class<cocos2d::backend::TextureUsage>(L, "ccb.TextureUsage");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "READ", (lua_Integer)cocos2d::backend::TextureUsage::READ);
    oluacls_enum(L, "RENDER_TARGET", (lua_Integer)cocos2d::backend::TextureUsage::RENDER_TARGET);
    oluacls_enum(L, "WRITE", (lua_Integer)cocos2d::backend::TextureUsage::WRITE);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccb_TextureUsage(lua_State *L)
{
    olua_require(L, "cocos2d_backend",  _olua_module_cocos2d_backend);
    if (!olua_getclass(L, "ccb.TextureUsage")) {
        luaL_error(L, "class not found: cocos2d::backend::TextureUsage");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_ccb_IndexFormat(lua_State *L)
{
    oluacls_class<cocos2d::backend::IndexFormat>(L, "ccb.IndexFormat");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "U_INT", (lua_Integer)cocos2d::backend::IndexFormat::U_INT);
    oluacls_enum(L, "U_SHORT", (lua_Integer)cocos2d::backend::IndexFormat::U_SHORT);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccb_IndexFormat(lua_State *L)
{
    olua_require(L, "cocos2d_backend",  _olua_module_cocos2d_backend);
    if (!olua_getclass(L, "ccb.IndexFormat")) {
        luaL_error(L, "class not found: cocos2d::backend::IndexFormat");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_ccb_VertexStepMode(lua_State *L)
{
    oluacls_class<cocos2d::backend::VertexStepMode>(L, "ccb.VertexStepMode");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "INSTANCE", (lua_Integer)cocos2d::backend::VertexStepMode::INSTANCE);
    oluacls_enum(L, "VERTEX", (lua_Integer)cocos2d::backend::VertexStepMode::VERTEX);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccb_VertexStepMode(lua_State *L)
{
    olua_require(L, "cocos2d_backend",  _olua_module_cocos2d_backend);
    if (!olua_getclass(L, "ccb.VertexStepMode")) {
        luaL_error(L, "class not found: cocos2d::backend::VertexStepMode");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_ccb_PrimitiveType(lua_State *L)
{
    oluacls_class<cocos2d::backend::PrimitiveType>(L, "ccb.PrimitiveType");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "LINE", (lua_Integer)cocos2d::backend::PrimitiveType::LINE);
    oluacls_enum(L, "LINE_STRIP", (lua_Integer)cocos2d::backend::PrimitiveType::LINE_STRIP);
    oluacls_enum(L, "POINT", (lua_Integer)cocos2d::backend::PrimitiveType::POINT);
    oluacls_enum(L, "TRIANGLE", (lua_Integer)cocos2d::backend::PrimitiveType::TRIANGLE);
    oluacls_enum(L, "TRIANGLE_STRIP", (lua_Integer)cocos2d::backend::PrimitiveType::TRIANGLE_STRIP);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccb_PrimitiveType(lua_State *L)
{
    olua_require(L, "cocos2d_backend",  _olua_module_cocos2d_backend);
    if (!olua_getclass(L, "ccb.PrimitiveType")) {
        luaL_error(L, "class not found: cocos2d::backend::PrimitiveType");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_ccb_TextureType(lua_State *L)
{
    oluacls_class<cocos2d::backend::TextureType>(L, "ccb.TextureType");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "TEXTURE_2D", (lua_Integer)cocos2d::backend::TextureType::TEXTURE_2D);
    oluacls_enum(L, "TEXTURE_CUBE", (lua_Integer)cocos2d::backend::TextureType::TEXTURE_CUBE);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccb_TextureType(lua_State *L)
{
    olua_require(L, "cocos2d_backend",  _olua_module_cocos2d_backend);
    if (!olua_getclass(L, "ccb.TextureType")) {
        luaL_error(L, "class not found: cocos2d::backend::TextureType");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_ccb_SamplerAddressMode(lua_State *L)
{
    oluacls_class<cocos2d::backend::SamplerAddressMode>(L, "ccb.SamplerAddressMode");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "CLAMP_TO_EDGE", (lua_Integer)cocos2d::backend::SamplerAddressMode::CLAMP_TO_EDGE);
    oluacls_enum(L, "DONT_CARE", (lua_Integer)cocos2d::backend::SamplerAddressMode::DONT_CARE);
    oluacls_enum(L, "MIRROR_REPEAT", (lua_Integer)cocos2d::backend::SamplerAddressMode::MIRROR_REPEAT);
    oluacls_enum(L, "REPEAT", (lua_Integer)cocos2d::backend::SamplerAddressMode::REPEAT);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccb_SamplerAddressMode(lua_State *L)
{
    olua_require(L, "cocos2d_backend",  _olua_module_cocos2d_backend);
    if (!olua_getclass(L, "ccb.SamplerAddressMode")) {
        luaL_error(L, "class not found: cocos2d::backend::SamplerAddressMode");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_ccb_SamplerFilter(lua_State *L)
{
    oluacls_class<cocos2d::backend::SamplerFilter>(L, "ccb.SamplerFilter");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "DONT_CARE", (lua_Integer)cocos2d::backend::SamplerFilter::DONT_CARE);
    oluacls_enum(L, "LINEAR", (lua_Integer)cocos2d::backend::SamplerFilter::LINEAR);
    oluacls_enum(L, "LINEAR_MIPMAP_LINEAR", (lua_Integer)cocos2d::backend::SamplerFilter::LINEAR_MIPMAP_LINEAR);
    oluacls_enum(L, "LINEAR_MIPMAP_NEAREST", (lua_Integer)cocos2d::backend::SamplerFilter::LINEAR_MIPMAP_NEAREST);
    oluacls_enum(L, "NEAREST", (lua_Integer)cocos2d::backend::SamplerFilter::NEAREST);
    oluacls_enum(L, "NEAREST_MIPMAP_LINEAR", (lua_Integer)cocos2d::backend::SamplerFilter::NEAREST_MIPMAP_LINEAR);
    oluacls_enum(L, "NEAREST_MIPMAP_NEAREST", (lua_Integer)cocos2d::backend::SamplerFilter::NEAREST_MIPMAP_NEAREST);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccb_SamplerFilter(lua_State *L)
{
    olua_require(L, "cocos2d_backend",  _olua_module_cocos2d_backend);
    if (!olua_getclass(L, "ccb.SamplerFilter")) {
        luaL_error(L, "class not found: cocos2d::backend::SamplerFilter");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_ccb_StencilOperation(lua_State *L)
{
    oluacls_class<cocos2d::backend::StencilOperation>(L, "ccb.StencilOperation");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "DECREMENT_WRAP", (lua_Integer)cocos2d::backend::StencilOperation::DECREMENT_WRAP);
    oluacls_enum(L, "INCREMENT_WRAP", (lua_Integer)cocos2d::backend::StencilOperation::INCREMENT_WRAP);
    oluacls_enum(L, "INVERT", (lua_Integer)cocos2d::backend::StencilOperation::INVERT);
    oluacls_enum(L, "KEEP", (lua_Integer)cocos2d::backend::StencilOperation::KEEP);
    oluacls_enum(L, "REPLACE", (lua_Integer)cocos2d::backend::StencilOperation::REPLACE);
    oluacls_enum(L, "ZERO", (lua_Integer)cocos2d::backend::StencilOperation::ZERO);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccb_StencilOperation(lua_State *L)
{
    olua_require(L, "cocos2d_backend",  _olua_module_cocos2d_backend);
    if (!olua_getclass(L, "ccb.StencilOperation")) {
        luaL_error(L, "class not found: cocos2d::backend::StencilOperation");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_ccb_CompareFunction(lua_State *L)
{
    oluacls_class<cocos2d::backend::CompareFunction>(L, "ccb.CompareFunction");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "ALWAYS", (lua_Integer)cocos2d::backend::CompareFunction::ALWAYS);
    oluacls_enum(L, "EQUAL", (lua_Integer)cocos2d::backend::CompareFunction::EQUAL);
    oluacls_enum(L, "GREATER", (lua_Integer)cocos2d::backend::CompareFunction::GREATER);
    oluacls_enum(L, "GREATER_EQUAL", (lua_Integer)cocos2d::backend::CompareFunction::GREATER_EQUAL);
    oluacls_enum(L, "LESS", (lua_Integer)cocos2d::backend::CompareFunction::LESS);
    oluacls_enum(L, "LESS_EQUAL", (lua_Integer)cocos2d::backend::CompareFunction::LESS_EQUAL);
    oluacls_enum(L, "NEVER", (lua_Integer)cocos2d::backend::CompareFunction::NEVER);
    oluacls_enum(L, "NOT_EQUAL", (lua_Integer)cocos2d::backend::CompareFunction::NOT_EQUAL);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccb_CompareFunction(lua_State *L)
{
    olua_require(L, "cocos2d_backend",  _olua_module_cocos2d_backend);
    if (!olua_getclass(L, "ccb.CompareFunction")) {
        luaL_error(L, "class not found: cocos2d::backend::CompareFunction");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_ccb_BlendOperation(lua_State *L)
{
    oluacls_class<cocos2d::backend::BlendOperation>(L, "ccb.BlendOperation");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "ADD", (lua_Integer)cocos2d::backend::BlendOperation::ADD);
    oluacls_enum(L, "RESERVE_SUBTRACT", (lua_Integer)cocos2d::backend::BlendOperation::RESERVE_SUBTRACT);
    oluacls_enum(L, "SUBTRACT", (lua_Integer)cocos2d::backend::BlendOperation::SUBTRACT);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccb_BlendOperation(lua_State *L)
{
    olua_require(L, "cocos2d_backend",  _olua_module_cocos2d_backend);
    if (!olua_getclass(L, "ccb.BlendOperation")) {
        luaL_error(L, "class not found: cocos2d::backend::BlendOperation");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_ccb_BlendFactor(lua_State *L)
{
    oluacls_class<cocos2d::backend::BlendFactor>(L, "ccb.BlendFactor");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "BLEND_CLOLOR", (lua_Integer)cocos2d::backend::BlendFactor::BLEND_CLOLOR);
    oluacls_enum(L, "CONSTANT_ALPHA", (lua_Integer)cocos2d::backend::BlendFactor::CONSTANT_ALPHA);
    oluacls_enum(L, "DST_ALPHA", (lua_Integer)cocos2d::backend::BlendFactor::DST_ALPHA);
    oluacls_enum(L, "DST_COLOR", (lua_Integer)cocos2d::backend::BlendFactor::DST_COLOR);
    oluacls_enum(L, "ONE", (lua_Integer)cocos2d::backend::BlendFactor::ONE);
    oluacls_enum(L, "ONE_MINUS_CONSTANT_ALPHA", (lua_Integer)cocos2d::backend::BlendFactor::ONE_MINUS_CONSTANT_ALPHA);
    oluacls_enum(L, "ONE_MINUS_DST_ALPHA", (lua_Integer)cocos2d::backend::BlendFactor::ONE_MINUS_DST_ALPHA);
    oluacls_enum(L, "ONE_MINUS_DST_COLOR", (lua_Integer)cocos2d::backend::BlendFactor::ONE_MINUS_DST_COLOR);
    oluacls_enum(L, "ONE_MINUS_SRC_ALPHA", (lua_Integer)cocos2d::backend::BlendFactor::ONE_MINUS_SRC_ALPHA);
    oluacls_enum(L, "ONE_MINUS_SRC_COLOR", (lua_Integer)cocos2d::backend::BlendFactor::ONE_MINUS_SRC_COLOR);
    oluacls_enum(L, "SRC_ALPHA", (lua_Integer)cocos2d::backend::BlendFactor::SRC_ALPHA);
    oluacls_enum(L, "SRC_ALPHA_SATURATE", (lua_Integer)cocos2d::backend::BlendFactor::SRC_ALPHA_SATURATE);
    oluacls_enum(L, "SRC_COLOR", (lua_Integer)cocos2d::backend::BlendFactor::SRC_COLOR);
    oluacls_enum(L, "ZERO", (lua_Integer)cocos2d::backend::BlendFactor::ZERO);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccb_BlendFactor(lua_State *L)
{
    olua_require(L, "cocos2d_backend",  _olua_module_cocos2d_backend);
    if (!olua_getclass(L, "ccb.BlendFactor")) {
        luaL_error(L, "class not found: cocos2d::backend::BlendFactor");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_ccb_ColorWriteMask(lua_State *L)
{
    oluacls_class<cocos2d::backend::ColorWriteMask>(L, "ccb.ColorWriteMask");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "ALL", (lua_Integer)cocos2d::backend::ColorWriteMask::ALL);
    oluacls_enum(L, "ALPHA", (lua_Integer)cocos2d::backend::ColorWriteMask::ALPHA);
    oluacls_enum(L, "BLUE", (lua_Integer)cocos2d::backend::ColorWriteMask::BLUE);
    oluacls_enum(L, "GREEN", (lua_Integer)cocos2d::backend::ColorWriteMask::GREEN);
    oluacls_enum(L, "NONE", (lua_Integer)cocos2d::backend::ColorWriteMask::NONE);
    oluacls_enum(L, "RED", (lua_Integer)cocos2d::backend::ColorWriteMask::RED);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccb_ColorWriteMask(lua_State *L)
{
    olua_require(L, "cocos2d_backend",  _olua_module_cocos2d_backend);
    if (!olua_getclass(L, "ccb.ColorWriteMask")) {
        luaL_error(L, "class not found: cocos2d::backend::ColorWriteMask");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_ccb_CullMode(lua_State *L)
{
    oluacls_class<cocos2d::backend::CullMode>(L, "ccb.CullMode");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "BACK", (lua_Integer)cocos2d::backend::CullMode::BACK);
    oluacls_enum(L, "FRONT", (lua_Integer)cocos2d::backend::CullMode::FRONT);
    oluacls_enum(L, "NONE", (lua_Integer)cocos2d::backend::CullMode::NONE);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccb_CullMode(lua_State *L)
{
    olua_require(L, "cocos2d_backend",  _olua_module_cocos2d_backend);
    if (!olua_getclass(L, "ccb.CullMode")) {
        luaL_error(L, "class not found: cocos2d::backend::CullMode");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_ccb_Winding(lua_State *L)
{
    oluacls_class<cocos2d::backend::Winding>(L, "ccb.Winding");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "CLOCK_WISE", (lua_Integer)cocos2d::backend::Winding::CLOCK_WISE);
    oluacls_enum(L, "COUNTER_CLOCK_WISE", (lua_Integer)cocos2d::backend::Winding::COUNTER_CLOCK_WISE);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccb_Winding(lua_State *L)
{
    olua_require(L, "cocos2d_backend",  _olua_module_cocos2d_backend);
    if (!olua_getclass(L, "ccb.Winding")) {
        luaL_error(L, "class not found: cocos2d::backend::Winding");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_ccb_TextureCubeFace(lua_State *L)
{
    oluacls_class<cocos2d::backend::TextureCubeFace>(L, "ccb.TextureCubeFace");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "NEGATIVE_X", (lua_Integer)cocos2d::backend::TextureCubeFace::NEGATIVE_X);
    oluacls_enum(L, "NEGATIVE_Y", (lua_Integer)cocos2d::backend::TextureCubeFace::NEGATIVE_Y);
    oluacls_enum(L, "NEGATIVE_Z", (lua_Integer)cocos2d::backend::TextureCubeFace::NEGATIVE_Z);
    oluacls_enum(L, "POSITIVE_X", (lua_Integer)cocos2d::backend::TextureCubeFace::POSITIVE_X);
    oluacls_enum(L, "POSITIVE_Y", (lua_Integer)cocos2d::backend::TextureCubeFace::POSITIVE_Y);
    oluacls_enum(L, "POSITIVE_Z", (lua_Integer)cocos2d::backend::TextureCubeFace::POSITIVE_Z);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccb_TextureCubeFace(lua_State *L)
{
    olua_require(L, "cocos2d_backend",  _olua_module_cocos2d_backend);
    if (!olua_getclass(L, "ccb.TextureCubeFace")) {
        luaL_error(L, "class not found: cocos2d::backend::TextureCubeFace");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_ccb_ProgramType(lua_State *L)
{
    oluacls_class<cocos2d::backend::ProgramType>(L, "ccb.ProgramType");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "CAMERA_CLEAR", (lua_Integer)cocos2d::backend::ProgramType::CAMERA_CLEAR);
    oluacls_enum(L, "CUSTOM_PROGRAM", (lua_Integer)cocos2d::backend::ProgramType::CUSTOM_PROGRAM);
    oluacls_enum(L, "ETC1", (lua_Integer)cocos2d::backend::ProgramType::ETC1);
    oluacls_enum(L, "ETC1_GRAY", (lua_Integer)cocos2d::backend::ProgramType::ETC1_GRAY);
    oluacls_enum(L, "GRAY_SCALE", (lua_Integer)cocos2d::backend::ProgramType::GRAY_SCALE);
    oluacls_enum(L, "LABEL_DISTANCE_NORMAL", (lua_Integer)cocos2d::backend::ProgramType::LABEL_DISTANCE_NORMAL);
    oluacls_enum(L, "LABEL_NORMAL", (lua_Integer)cocos2d::backend::ProgramType::LABEL_NORMAL);
    oluacls_enum(L, "LABLE_DISTANCEFIELD_GLOW", (lua_Integer)cocos2d::backend::ProgramType::LABLE_DISTANCEFIELD_GLOW);
    oluacls_enum(L, "LABLE_OUTLINE", (lua_Integer)cocos2d::backend::ProgramType::LABLE_OUTLINE);
    oluacls_enum(L, "LAYER_RADIA_GRADIENT", (lua_Integer)cocos2d::backend::ProgramType::LAYER_RADIA_GRADIENT);
    oluacls_enum(L, "LINE_COLOR_3D", (lua_Integer)cocos2d::backend::ProgramType::LINE_COLOR_3D);
    oluacls_enum(L, "PARTICLE_COLOR_3D", (lua_Integer)cocos2d::backend::ProgramType::PARTICLE_COLOR_3D);
    oluacls_enum(L, "PARTICLE_TEXTURE_3D", (lua_Integer)cocos2d::backend::ProgramType::PARTICLE_TEXTURE_3D);
    oluacls_enum(L, "POSITION", (lua_Integer)cocos2d::backend::ProgramType::POSITION);
    oluacls_enum(L, "POSITION_3D", (lua_Integer)cocos2d::backend::ProgramType::POSITION_3D);
    oluacls_enum(L, "POSITION_BUMPEDNORMAL_TEXTURE_3D", (lua_Integer)cocos2d::backend::ProgramType::POSITION_BUMPEDNORMAL_TEXTURE_3D);
    oluacls_enum(L, "POSITION_COLOR", (lua_Integer)cocos2d::backend::ProgramType::POSITION_COLOR);
    oluacls_enum(L, "POSITION_COLOR_LENGTH_TEXTURE", (lua_Integer)cocos2d::backend::ProgramType::POSITION_COLOR_LENGTH_TEXTURE);
    oluacls_enum(L, "POSITION_COLOR_TEXTURE_AS_POINTSIZE", (lua_Integer)cocos2d::backend::ProgramType::POSITION_COLOR_TEXTURE_AS_POINTSIZE);
    oluacls_enum(L, "POSITION_NORMAL_3D", (lua_Integer)cocos2d::backend::ProgramType::POSITION_NORMAL_3D);
    oluacls_enum(L, "POSITION_NORMAL_TEXTURE_3D", (lua_Integer)cocos2d::backend::ProgramType::POSITION_NORMAL_TEXTURE_3D);
    oluacls_enum(L, "POSITION_TEXTURE", (lua_Integer)cocos2d::backend::ProgramType::POSITION_TEXTURE);
    oluacls_enum(L, "POSITION_TEXTURE_3D", (lua_Integer)cocos2d::backend::ProgramType::POSITION_TEXTURE_3D);
    oluacls_enum(L, "POSITION_TEXTURE_COLOR", (lua_Integer)cocos2d::backend::ProgramType::POSITION_TEXTURE_COLOR);
    oluacls_enum(L, "POSITION_TEXTURE_COLOR_ALPHA_TEST", (lua_Integer)cocos2d::backend::ProgramType::POSITION_TEXTURE_COLOR_ALPHA_TEST);
    oluacls_enum(L, "POSITION_UCOLOR", (lua_Integer)cocos2d::backend::ProgramType::POSITION_UCOLOR);
    oluacls_enum(L, "SKINPOSITION_BUMPEDNORMAL_TEXTURE_3D", (lua_Integer)cocos2d::backend::ProgramType::SKINPOSITION_BUMPEDNORMAL_TEXTURE_3D);
    oluacls_enum(L, "SKINPOSITION_NORMAL_TEXTURE_3D", (lua_Integer)cocos2d::backend::ProgramType::SKINPOSITION_NORMAL_TEXTURE_3D);
    oluacls_enum(L, "SKINPOSITION_TEXTURE_3D", (lua_Integer)cocos2d::backend::ProgramType::SKINPOSITION_TEXTURE_3D);
    oluacls_enum(L, "SKYBOX_3D", (lua_Integer)cocos2d::backend::ProgramType::SKYBOX_3D);
    oluacls_enum(L, "TERRAIN_3D", (lua_Integer)cocos2d::backend::ProgramType::TERRAIN_3D);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccb_ProgramType(lua_State *L)
{
    olua_require(L, "cocos2d_backend",  _olua_module_cocos2d_backend);
    if (!olua_getclass(L, "ccb.ProgramType")) {
        luaL_error(L, "class not found: cocos2d::backend::ProgramType");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_ccb_Uniform(lua_State *L)
{
    oluacls_class<cocos2d::backend::Uniform>(L, "ccb.Uniform");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "EFFECT_COLOR", (lua_Integer)cocos2d::backend::Uniform::EFFECT_COLOR);
    oluacls_enum(L, "EFFECT_TYPE", (lua_Integer)cocos2d::backend::Uniform::EFFECT_TYPE);
    oluacls_enum(L, "MVP_MATRIX", (lua_Integer)cocos2d::backend::Uniform::MVP_MATRIX);
    oluacls_enum(L, "TEXTURE", (lua_Integer)cocos2d::backend::Uniform::TEXTURE);
    oluacls_enum(L, "TEXTURE1", (lua_Integer)cocos2d::backend::Uniform::TEXTURE1);
    oluacls_enum(L, "TEXTURE2", (lua_Integer)cocos2d::backend::Uniform::TEXTURE2);
    oluacls_enum(L, "TEXTURE3", (lua_Integer)cocos2d::backend::Uniform::TEXTURE3);
    oluacls_enum(L, "TEXT_COLOR", (lua_Integer)cocos2d::backend::Uniform::TEXT_COLOR);
    oluacls_enum(L, "UNIFORM_MAX", (lua_Integer)cocos2d::backend::Uniform::UNIFORM_MAX);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccb_Uniform(lua_State *L)
{
    olua_require(L, "cocos2d_backend",  _olua_module_cocos2d_backend);
    if (!olua_getclass(L, "ccb.Uniform")) {
        luaL_error(L, "class not found: cocos2d::backend::Uniform");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_ccb_Attribute(lua_State *L)
{
    oluacls_class<cocos2d::backend::Attribute>(L, "ccb.Attribute");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "ATTRIBUTE_MAX", (lua_Integer)cocos2d::backend::Attribute::ATTRIBUTE_MAX);
    oluacls_enum(L, "COLOR", (lua_Integer)cocos2d::backend::Attribute::COLOR);
    oluacls_enum(L, "POSITION", (lua_Integer)cocos2d::backend::Attribute::POSITION);
    oluacls_enum(L, "TEXCOORD", (lua_Integer)cocos2d::backend::Attribute::TEXCOORD);
    oluacls_enum(L, "TEXCOORD1", (lua_Integer)cocos2d::backend::Attribute::TEXCOORD1);
    oluacls_enum(L, "TEXCOORD2", (lua_Integer)cocos2d::backend::Attribute::TEXCOORD2);
    oluacls_enum(L, "TEXCOORD3", (lua_Integer)cocos2d::backend::Attribute::TEXCOORD3);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccb_Attribute(lua_State *L)
{
    olua_require(L, "cocos2d_backend",  _olua_module_cocos2d_backend);
    if (!olua_getclass(L, "ccb.Attribute")) {
        luaL_error(L, "class not found: cocos2d::backend::Attribute");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_ccb_FeatureType(lua_State *L)
{
    oluacls_class<cocos2d::backend::FeatureType>(L, "ccb.FeatureType");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "AMD_COMPRESSED_ATC", (lua_Integer)cocos2d::backend::FeatureType::AMD_COMPRESSED_ATC);
    oluacls_enum(L, "ASTC", (lua_Integer)cocos2d::backend::FeatureType::ASTC);
    oluacls_enum(L, "DEPTH24", (lua_Integer)cocos2d::backend::FeatureType::DEPTH24);
    oluacls_enum(L, "DISCARD_FRAMEBUFFER", (lua_Integer)cocos2d::backend::FeatureType::DISCARD_FRAMEBUFFER);
    oluacls_enum(L, "ETC1", (lua_Integer)cocos2d::backend::FeatureType::ETC1);
    oluacls_enum(L, "IMG_FORMAT_BGRA8888", (lua_Integer)cocos2d::backend::FeatureType::IMG_FORMAT_BGRA8888);
    oluacls_enum(L, "MAPBUFFER", (lua_Integer)cocos2d::backend::FeatureType::MAPBUFFER);
    oluacls_enum(L, "PACKED_DEPTH_STENCIL", (lua_Integer)cocos2d::backend::FeatureType::PACKED_DEPTH_STENCIL);
    oluacls_enum(L, "PVRTC", (lua_Integer)cocos2d::backend::FeatureType::PVRTC);
    oluacls_enum(L, "S3TC", (lua_Integer)cocos2d::backend::FeatureType::S3TC);
    oluacls_enum(L, "VAO", (lua_Integer)cocos2d::backend::FeatureType::VAO);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccb_FeatureType(lua_State *L)
{
    olua_require(L, "cocos2d_backend",  _olua_module_cocos2d_backend);
    if (!olua_getclass(L, "ccb.FeatureType")) {
        luaL_error(L, "class not found: cocos2d::backend::FeatureType");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_backend_Buffer_getSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::Buffer *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.Buffer");

    // std::size_t getSize()
    std::size_t ret = self->getSize();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_Buffer_updateData(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::Buffer *self = nullptr;
    void *arg1 = nullptr;       /** data */
    std::size_t arg2 = 0;       /** size */

    olua_to_object(L, 1, &self, "ccb.Buffer");
    olua_check_object(L, 2, &arg1, "void *");
    olua_check_integer(L, 3, &arg2);

    // void updateData(void *data, std::size_t size)
    self->updateData(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_Buffer_updateSubData(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::Buffer *self = nullptr;
    void *arg1 = nullptr;       /** data */
    std::size_t arg2 = 0;       /** offset */
    std::size_t arg3 = 0;       /** size */

    olua_to_object(L, 1, &self, "ccb.Buffer");
    olua_check_object(L, 2, &arg1, "void *");
    olua_check_integer(L, 3, &arg2);
    olua_check_integer(L, 4, &arg3);

    // void updateSubData(void *data, std::size_t offset, std::size_t size)
    self->updateSubData(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_Buffer_usingDefaultStoredData(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::Buffer *self = nullptr;
    bool arg1 = false;       /** needDefaultStoredData */

    olua_to_object(L, 1, &self, "ccb.Buffer");
    olua_check_bool(L, 2, &arg1);

    // void usingDefaultStoredData(bool needDefaultStoredData)
    self->usingDefaultStoredData(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_cls_ccb_Buffer(lua_State *L)
{
    oluacls_class<cocos2d::backend::Buffer, cocos2d::Ref>(L, "ccb.Buffer");
    oluacls_func(L, "getSize", _olua_fun_cocos2d_backend_Buffer_getSize);
    oluacls_func(L, "updateData", _olua_fun_cocos2d_backend_Buffer_updateData);
    oluacls_func(L, "updateSubData", _olua_fun_cocos2d_backend_Buffer_updateSubData);
    oluacls_func(L, "usingDefaultStoredData", _olua_fun_cocos2d_backend_Buffer_usingDefaultStoredData);
    oluacls_prop(L, "size", _olua_fun_cocos2d_backend_Buffer_getSize, nullptr);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccb_Buffer(lua_State *L)
{
    olua_require(L, "cocos2d_backend",  _olua_module_cocos2d_backend);
    if (!olua_getclass(L, "ccb.Buffer")) {
        luaL_error(L, "class not found: cocos2d::backend::Buffer");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_ccb_RenderPipeline(lua_State *L)
{
    oluacls_class<cocos2d::backend::RenderPipeline, cocos2d::Ref>(L, "ccb.RenderPipeline");

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccb_RenderPipeline(lua_State *L)
{
    olua_require(L, "cocos2d_backend",  _olua_module_cocos2d_backend);
    if (!olua_getclass(L, "ccb.RenderPipeline")) {
        luaL_error(L, "class not found: cocos2d::backend::RenderPipeline");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_ccb_DepthStencilState(lua_State *L)
{
    oluacls_class<cocos2d::backend::DepthStencilState, cocos2d::Ref>(L, "ccb.DepthStencilState");

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccb_DepthStencilState(lua_State *L)
{
    olua_require(L, "cocos2d_backend",  _olua_module_cocos2d_backend);
    if (!olua_getclass(L, "ccb.DepthStencilState")) {
        luaL_error(L, "class not found: cocos2d::backend::DepthStencilState");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_backend_VertexLayout___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::backend::VertexLayout *)olua_toobj(L, 1, "ccb.VertexLayout");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_VertexLayout_getAttributes(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::VertexLayout *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.VertexLayout");

    // const std::unordered_map<std::string, cocos2d::backend::VertexLayout::Attribute> &getAttributes()
    const std::unordered_map<std::string, cocos2d::backend::VertexLayout::Attribute> &ret = self->getAttributes();
    int num_ret = olua_push_map<std::string, cocos2d::backend::VertexLayout::Attribute>(L, ret, [L](std::string &arg1, cocos2d::backend::VertexLayout::Attribute &arg2) {
        olua_push_string(L, arg1);
        olua_copy_object(L, arg2, "ccb.VertexLayout.Attribute");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_VertexLayout_getStride(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::VertexLayout *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.VertexLayout");

    // std::size_t getStride()
    std::size_t ret = self->getStride();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_VertexLayout_getVertexStepMode(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::VertexLayout *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.VertexLayout");

    // cocos2d::backend::VertexStepMode getVertexStepMode()
    cocos2d::backend::VertexStepMode ret = self->getVertexStepMode();
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_VertexLayout_isValid(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::VertexLayout *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.VertexLayout");

    // bool isValid()
    bool ret = self->isValid();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_VertexLayout_new(lua_State *L)
{
    olua_startinvoke(L);

    // cocos2d::backend::VertexLayout()
    cocos2d::backend::VertexLayout *ret = new cocos2d::backend::VertexLayout();
    int num_ret = olua_push_object(L, ret, "ccb.VertexLayout");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_VertexLayout_setAttribute(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::VertexLayout *self = nullptr;
    std::string arg1;       /** name */
    std::size_t arg2 = 0;       /** index */
    cocos2d::backend::VertexFormat arg3 = (cocos2d::backend::VertexFormat)0;       /** format */
    std::size_t arg4 = 0;       /** offset */
    bool arg5 = false;       /** needToBeNormallized */

    olua_to_object(L, 1, &self, "ccb.VertexLayout");
    olua_check_string(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);
    olua_check_enum(L, 4, &arg3);
    olua_check_integer(L, 5, &arg4);
    olua_check_bool(L, 6, &arg5);

    // void setAttribute(const std::string &name, std::size_t index, cocos2d::backend::VertexFormat format, std::size_t offset, bool needToBeNormallized)
    self->setAttribute(arg1, arg2, arg3, arg4, arg5);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_VertexLayout_setLayout(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::VertexLayout *self = nullptr;
    std::size_t arg1 = 0;       /** stride */

    olua_to_object(L, 1, &self, "ccb.VertexLayout");
    olua_check_integer(L, 2, &arg1);

    // void setLayout(std::size_t stride)
    self->setLayout(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_cls_ccb_VertexLayout(lua_State *L)
{
    oluacls_class<cocos2d::backend::VertexLayout>(L, "ccb.VertexLayout");
    oluacls_func(L, "__gc", _olua_fun_cocos2d_backend_VertexLayout___gc);
    oluacls_func(L, "getAttributes", _olua_fun_cocos2d_backend_VertexLayout_getAttributes);
    oluacls_func(L, "getStride", _olua_fun_cocos2d_backend_VertexLayout_getStride);
    oluacls_func(L, "getVertexStepMode", _olua_fun_cocos2d_backend_VertexLayout_getVertexStepMode);
    oluacls_func(L, "isValid", _olua_fun_cocos2d_backend_VertexLayout_isValid);
    oluacls_func(L, "new", _olua_fun_cocos2d_backend_VertexLayout_new);
    oluacls_func(L, "setAttribute", _olua_fun_cocos2d_backend_VertexLayout_setAttribute);
    oluacls_func(L, "setLayout", _olua_fun_cocos2d_backend_VertexLayout_setLayout);
    oluacls_prop(L, "attributes", _olua_fun_cocos2d_backend_VertexLayout_getAttributes, nullptr);
    oluacls_prop(L, "stride", _olua_fun_cocos2d_backend_VertexLayout_getStride, nullptr);
    oluacls_prop(L, "valid", _olua_fun_cocos2d_backend_VertexLayout_isValid, nullptr);
    oluacls_prop(L, "vertexStepMode", _olua_fun_cocos2d_backend_VertexLayout_getVertexStepMode, nullptr);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccb_VertexLayout(lua_State *L)
{
    olua_require(L, "cocos2d_backend",  _olua_module_cocos2d_backend);
    if (!olua_getclass(L, "ccb.VertexLayout")) {
        luaL_error(L, "class not found: cocos2d::backend::VertexLayout");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_backend_CommandBuffer_beginFrame(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::CommandBuffer *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.CommandBuffer");

    // void beginFrame()
    self->beginFrame();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_CommandBuffer_captureScreen(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::CommandBuffer *self = nullptr;
    std::function<void (const unsigned char *, int, int)> arg1;       /** callback */

    olua_to_object(L, 1, &self, "ccb.CommandBuffer");
    olua_check_callback(L, 2, &arg1, "std.function");

    void *cb_store = (void *)self;
    std::string cb_tag = "captureScreen";
    std::string cb_name = olua_setcallback(L, cb_store, 2, cb_tag.c_str(), OLUA_TAG_NEW);
    olua_Context cb_ctx = olua_context(L);
    // lua_State *ML = olua_mainthread(L);
    arg1 = [cb_store, cb_name, cb_ctx /*, ML */](const unsigned char *cb_arg1, int cb_arg2, int cb_arg3) {
        lua_State *L = olua_mainthread(NULL);
        olua_checkhostthread();

        if (olua_contextequal(L, cb_ctx)) {
            int top = lua_gettop(L);
            olua_push_string(L, cb_arg1);
            olua_push_integer(L, cb_arg2);
            olua_push_integer(L, cb_arg3);

            olua_callback(L, cb_store, cb_name.c_str(), 3);

            olua_removecallback(L, cb_store, cb_name.c_str(), OLUA_TAG_WHOLE);

            lua_settop(L, top);
        }
    };

    // void captureScreen(std::function<void (const unsigned char *, int, int)> callback)
    self->captureScreen(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_CommandBuffer_drawArrays(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::CommandBuffer *self = nullptr;
    cocos2d::backend::PrimitiveType arg1 = (cocos2d::backend::PrimitiveType)0;       /** primitiveType */
    std::size_t arg2 = 0;       /** start */
    std::size_t arg3 = 0;       /** count */

    olua_to_object(L, 1, &self, "ccb.CommandBuffer");
    olua_check_enum(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);
    olua_check_integer(L, 4, &arg3);

    // void drawArrays(cocos2d::backend::PrimitiveType primitiveType, std::size_t start, std::size_t count)
    self->drawArrays(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_CommandBuffer_drawElements(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::CommandBuffer *self = nullptr;
    cocos2d::backend::PrimitiveType arg1 = (cocos2d::backend::PrimitiveType)0;       /** primitiveType */
    cocos2d::backend::IndexFormat arg2 = (cocos2d::backend::IndexFormat)0;       /** indexType */
    std::size_t arg3 = 0;       /** count */
    std::size_t arg4 = 0;       /** offset */

    olua_to_object(L, 1, &self, "ccb.CommandBuffer");
    olua_check_enum(L, 2, &arg1);
    olua_check_enum(L, 3, &arg2);
    olua_check_integer(L, 4, &arg3);
    olua_check_integer(L, 5, &arg4);

    // void drawElements(cocos2d::backend::PrimitiveType primitiveType, cocos2d::backend::IndexFormat indexType, std::size_t count, std::size_t offset)
    self->drawElements(arg1, arg2, arg3, arg4);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_CommandBuffer_endFrame(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::CommandBuffer *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.CommandBuffer");

    // void endFrame()
    self->endFrame();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_CommandBuffer_endRenderPass(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::CommandBuffer *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.CommandBuffer");

    // void endRenderPass()
    self->endRenderPass();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_CommandBuffer_setCullMode(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::CommandBuffer *self = nullptr;
    cocos2d::backend::CullMode arg1 = (cocos2d::backend::CullMode)0;       /** mode */

    olua_to_object(L, 1, &self, "ccb.CommandBuffer");
    olua_check_enum(L, 2, &arg1);

    // void setCullMode(cocos2d::backend::CullMode mode)
    self->setCullMode(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_CommandBuffer_setDepthStencilState(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::CommandBuffer *self = nullptr;
    cocos2d::backend::DepthStencilState *arg1 = nullptr;       /** depthStencilState */

    olua_to_object(L, 1, &self, "ccb.CommandBuffer");
    olua_check_object(L, 2, &arg1, "ccb.DepthStencilState");

    // void setDepthStencilState(cocos2d::backend::DepthStencilState *depthStencilState)
    self->setDepthStencilState(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_CommandBuffer_setIndexBuffer(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::CommandBuffer *self = nullptr;
    cocos2d::backend::Buffer *arg1 = nullptr;       /** buffer */

    olua_to_object(L, 1, &self, "ccb.CommandBuffer");
    olua_check_object(L, 2, &arg1, "ccb.Buffer");

    // void setIndexBuffer(cocos2d::backend::Buffer *buffer)
    self->setIndexBuffer(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_CommandBuffer_setLineWidth(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::CommandBuffer *self = nullptr;
    float arg1 = 0;       /** lineWidth */

    olua_to_object(L, 1, &self, "ccb.CommandBuffer");
    olua_check_number(L, 2, &arg1);

    // void setLineWidth(float lineWidth)
    self->setLineWidth(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_CommandBuffer_setProgramState(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::CommandBuffer *self = nullptr;
    cocos2d::backend::ProgramState *arg1 = nullptr;       /** programState */

    olua_to_object(L, 1, &self, "ccb.CommandBuffer");
    olua_check_object(L, 2, &arg1, "ccb.ProgramState");

    // void setProgramState(cocos2d::backend::ProgramState *programState)
    self->setProgramState(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_CommandBuffer_setRenderPipeline(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::CommandBuffer *self = nullptr;
    cocos2d::backend::RenderPipeline *arg1 = nullptr;       /** renderPipeline */

    olua_to_object(L, 1, &self, "ccb.CommandBuffer");
    olua_check_object(L, 2, &arg1, "ccb.RenderPipeline");

    // void setRenderPipeline(cocos2d::backend::RenderPipeline *renderPipeline)
    self->setRenderPipeline(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_CommandBuffer_setScissorRect(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::CommandBuffer *self = nullptr;
    bool arg1 = false;       /** isEnabled */
    float arg2 = 0;       /** x */
    float arg3 = 0;       /** y */
    float arg4 = 0;       /** width */
    float arg5 = 0;       /** height */

    olua_to_object(L, 1, &self, "ccb.CommandBuffer");
    olua_check_bool(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);
    olua_check_number(L, 5, &arg4);
    olua_check_number(L, 6, &arg5);

    // void setScissorRect(bool isEnabled, float x, float y, float width, float height)
    self->setScissorRect(arg1, arg2, arg3, arg4, arg5);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_CommandBuffer_setStencilReferenceValue$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::CommandBuffer *self = nullptr;
    unsigned int arg1 = 0;       /** value */

    olua_to_object(L, 1, &self, "ccb.CommandBuffer");
    olua_check_integer(L, 2, &arg1);

    // void setStencilReferenceValue(unsigned int value)
    self->setStencilReferenceValue(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_CommandBuffer_setStencilReferenceValue$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::CommandBuffer *self = nullptr;
    unsigned int arg1 = 0;       /** frontRef */
    unsigned int arg2 = 0;       /** backRef */

    olua_to_object(L, 1, &self, "ccb.CommandBuffer");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // void setStencilReferenceValue(unsigned int frontRef, unsigned int backRef)
    self->setStencilReferenceValue(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_CommandBuffer_setStencilReferenceValue(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccb.CommandBuffer")) && (olua_is_integer(L, 2))) {
            // void setStencilReferenceValue(unsigned int value)
            return _olua_fun_cocos2d_backend_CommandBuffer_setStencilReferenceValue$1(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "ccb.CommandBuffer")) && (olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // void setStencilReferenceValue(unsigned int frontRef, unsigned int backRef)
            return _olua_fun_cocos2d_backend_CommandBuffer_setStencilReferenceValue$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::backend::CommandBuffer::setStencilReferenceValue' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_backend_CommandBuffer_setVertexBuffer(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::CommandBuffer *self = nullptr;
    cocos2d::backend::Buffer *arg1 = nullptr;       /** buffer */

    olua_to_object(L, 1, &self, "ccb.CommandBuffer");
    olua_check_object(L, 2, &arg1, "ccb.Buffer");

    // void setVertexBuffer(cocos2d::backend::Buffer *buffer)
    self->setVertexBuffer(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_CommandBuffer_setViewport(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::CommandBuffer *self = nullptr;
    int arg1 = 0;       /** x */
    int arg2 = 0;       /** y */
    unsigned int arg3 = 0;       /** w */
    unsigned int arg4 = 0;       /** h */

    olua_to_object(L, 1, &self, "ccb.CommandBuffer");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);
    olua_check_integer(L, 4, &arg3);
    olua_check_integer(L, 5, &arg4);

    // void setViewport(int x, int y, unsigned int w, unsigned int h)
    self->setViewport(arg1, arg2, arg3, arg4);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_CommandBuffer_setWinding(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::CommandBuffer *self = nullptr;
    cocos2d::backend::Winding arg1 = (cocos2d::backend::Winding)0;       /** winding */

    olua_to_object(L, 1, &self, "ccb.CommandBuffer");
    olua_check_enum(L, 2, &arg1);

    // void setWinding(cocos2d::backend::Winding winding)
    self->setWinding(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_cls_ccb_CommandBuffer(lua_State *L)
{
    oluacls_class<cocos2d::backend::CommandBuffer, cocos2d::Ref>(L, "ccb.CommandBuffer");
    oluacls_func(L, "beginFrame", _olua_fun_cocos2d_backend_CommandBuffer_beginFrame);
    oluacls_func(L, "captureScreen", _olua_fun_cocos2d_backend_CommandBuffer_captureScreen);
    oluacls_func(L, "drawArrays", _olua_fun_cocos2d_backend_CommandBuffer_drawArrays);
    oluacls_func(L, "drawElements", _olua_fun_cocos2d_backend_CommandBuffer_drawElements);
    oluacls_func(L, "endFrame", _olua_fun_cocos2d_backend_CommandBuffer_endFrame);
    oluacls_func(L, "endRenderPass", _olua_fun_cocos2d_backend_CommandBuffer_endRenderPass);
    oluacls_func(L, "setCullMode", _olua_fun_cocos2d_backend_CommandBuffer_setCullMode);
    oluacls_func(L, "setDepthStencilState", _olua_fun_cocos2d_backend_CommandBuffer_setDepthStencilState);
    oluacls_func(L, "setIndexBuffer", _olua_fun_cocos2d_backend_CommandBuffer_setIndexBuffer);
    oluacls_func(L, "setLineWidth", _olua_fun_cocos2d_backend_CommandBuffer_setLineWidth);
    oluacls_func(L, "setProgramState", _olua_fun_cocos2d_backend_CommandBuffer_setProgramState);
    oluacls_func(L, "setRenderPipeline", _olua_fun_cocos2d_backend_CommandBuffer_setRenderPipeline);
    oluacls_func(L, "setScissorRect", _olua_fun_cocos2d_backend_CommandBuffer_setScissorRect);
    oluacls_func(L, "setStencilReferenceValue", _olua_fun_cocos2d_backend_CommandBuffer_setStencilReferenceValue);
    oluacls_func(L, "setVertexBuffer", _olua_fun_cocos2d_backend_CommandBuffer_setVertexBuffer);
    oluacls_func(L, "setViewport", _olua_fun_cocos2d_backend_CommandBuffer_setViewport);
    oluacls_func(L, "setWinding", _olua_fun_cocos2d_backend_CommandBuffer_setWinding);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccb_CommandBuffer(lua_State *L)
{
    olua_require(L, "cocos2d_backend",  _olua_module_cocos2d_backend);
    if (!olua_getclass(L, "ccb.CommandBuffer")) {
        luaL_error(L, "class not found: cocos2d::backend::CommandBuffer");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_backend_Device_createDepthStencilState(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::Device *self = nullptr;
    cocos2d::backend::DepthStencilDescriptor *arg1;       /** descriptor */

    olua_to_object(L, 1, &self, "ccb.Device");
    olua_check_object(L, 2, &arg1, "ccb.DepthStencilDescriptor");

    // cocos2d::backend::DepthStencilState *createDepthStencilState(const cocos2d::backend::DepthStencilDescriptor &descriptor)
    cocos2d::backend::DepthStencilState *ret = self->createDepthStencilState(*arg1);
    int num_ret = olua_push_object(L, ret, "ccb.DepthStencilState");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_Device_getDeviceInfo(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::Device *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.Device");

    // cocos2d::backend::DeviceInfo *getDeviceInfo()
    cocos2d::backend::DeviceInfo *ret = self->getDeviceInfo();
    int num_ret = olua_push_object(L, ret, "ccb.DeviceInfo");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_Device_getInstance(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::backend::Device *getInstance()
    cocos2d::backend::Device *ret = cocos2d::backend::Device::getInstance();
    int num_ret = olua_push_object(L, ret, "ccb.Device");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_Device_newBuffer(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::Device *self = nullptr;
    size_t arg1 = 0;       /** size */
    cocos2d::backend::BufferType arg2 = (cocos2d::backend::BufferType)0;       /** type */
    cocos2d::backend::BufferUsage arg3 = (cocos2d::backend::BufferUsage)0;       /** usage */

    olua_to_object(L, 1, &self, "ccb.Device");
    olua_check_integer(L, 2, &arg1);
    olua_check_enum(L, 3, &arg2);
    olua_check_enum(L, 4, &arg3);

    // @postnew cocos2d::backend::Buffer *newBuffer(size_t size, cocos2d::backend::BufferType type, cocos2d::backend::BufferUsage usage)
    cocos2d::backend::Buffer *ret = self->newBuffer(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "ccb.Buffer");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_Device_newCommandBuffer(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::Device *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.Device");

    // @postnew cocos2d::backend::CommandBuffer *newCommandBuffer()
    cocos2d::backend::CommandBuffer *ret = self->newCommandBuffer();
    int num_ret = olua_push_object(L, ret, "ccb.CommandBuffer");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_Device_newProgram(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::Device *self = nullptr;
    std::string arg1;       /** vertexShader */
    std::string arg2;       /** fragmentShader */

    olua_to_object(L, 1, &self, "ccb.Device");
    olua_check_string(L, 2, &arg1);
    olua_check_string(L, 3, &arg2);

    // @postnew cocos2d::backend::Program *newProgram(const std::string &vertexShader, const std::string &fragmentShader)
    cocos2d::backend::Program *ret = self->newProgram(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "ccb.Program");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_Device_newRenderPipeline(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::Device *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.Device");

    // @postnew cocos2d::backend::RenderPipeline *newRenderPipeline()
    cocos2d::backend::RenderPipeline *ret = self->newRenderPipeline();
    int num_ret = olua_push_object(L, ret, "ccb.RenderPipeline");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_Device_newTexture(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::Device *self = nullptr;
    cocos2d::backend::TextureDescriptor *arg1;       /** descriptor */

    olua_to_object(L, 1, &self, "ccb.Device");
    olua_check_object(L, 2, &arg1, "ccb.TextureDescriptor");

    // @postnew cocos2d::backend::TextureBackend *newTexture(const cocos2d::backend::TextureDescriptor &descriptor)
    cocos2d::backend::TextureBackend *ret = self->newTexture(*arg1);
    int num_ret = olua_push_object(L, ret, "ccb.TextureBackend");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_Device_setFrameBufferOnly(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::Device *self = nullptr;
    bool arg1 = false;       /** frameBufferOnly */

    olua_to_object(L, 1, &self, "ccb.Device");
    olua_check_bool(L, 2, &arg1);

    // void setFrameBufferOnly(bool frameBufferOnly)
    self->setFrameBufferOnly(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_cls_ccb_Device(lua_State *L)
{
    oluacls_class<cocos2d::backend::Device, cocos2d::Ref>(L, "ccb.Device");
    oluacls_func(L, "createDepthStencilState", _olua_fun_cocos2d_backend_Device_createDepthStencilState);
    oluacls_func(L, "getDeviceInfo", _olua_fun_cocos2d_backend_Device_getDeviceInfo);
    oluacls_func(L, "getInstance", _olua_fun_cocos2d_backend_Device_getInstance);
    oluacls_func(L, "newBuffer", _olua_fun_cocos2d_backend_Device_newBuffer);
    oluacls_func(L, "newCommandBuffer", _olua_fun_cocos2d_backend_Device_newCommandBuffer);
    oluacls_func(L, "newProgram", _olua_fun_cocos2d_backend_Device_newProgram);
    oluacls_func(L, "newRenderPipeline", _olua_fun_cocos2d_backend_Device_newRenderPipeline);
    oluacls_func(L, "newTexture", _olua_fun_cocos2d_backend_Device_newTexture);
    oluacls_func(L, "setFrameBufferOnly", _olua_fun_cocos2d_backend_Device_setFrameBufferOnly);
    oluacls_prop(L, "deviceInfo", _olua_fun_cocos2d_backend_Device_getDeviceInfo, nullptr);
    oluacls_prop(L, "instance", _olua_fun_cocos2d_backend_Device_getInstance, nullptr);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccb_Device(lua_State *L)
{
    olua_require(L, "cocos2d_backend",  _olua_module_cocos2d_backend);
    if (!olua_getclass(L, "ccb.Device")) {
        luaL_error(L, "class not found: cocos2d::backend::Device");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_backend_DeviceInfo___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::backend::DeviceInfo *)olua_toobj(L, 1, "ccb.DeviceInfo");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_DeviceInfo_checkForFeatureSupported(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::DeviceInfo *self = nullptr;
    cocos2d::backend::FeatureType arg1 = (cocos2d::backend::FeatureType)0;       /** feature */

    olua_to_object(L, 1, &self, "ccb.DeviceInfo");
    olua_check_enum(L, 2, &arg1);

    // bool checkForFeatureSupported(cocos2d::backend::FeatureType feature)
    bool ret = self->checkForFeatureSupported(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_DeviceInfo_getExtension(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::DeviceInfo *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.DeviceInfo");

    // const char *getExtension()
    const char *ret = self->getExtension();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_DeviceInfo_getMaxAttributes(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::DeviceInfo *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.DeviceInfo");

    // int getMaxAttributes()
    int ret = self->getMaxAttributes();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_DeviceInfo_getMaxSamplesAllowed(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::DeviceInfo *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.DeviceInfo");

    // int getMaxSamplesAllowed()
    int ret = self->getMaxSamplesAllowed();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_DeviceInfo_getMaxTextureSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::DeviceInfo *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.DeviceInfo");

    // int getMaxTextureSize()
    int ret = self->getMaxTextureSize();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_DeviceInfo_getMaxTextureUnits(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::DeviceInfo *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.DeviceInfo");

    // int getMaxTextureUnits()
    int ret = self->getMaxTextureUnits();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_DeviceInfo_getRenderer(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::DeviceInfo *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.DeviceInfo");

    // const char *getRenderer()
    const char *ret = self->getRenderer();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_DeviceInfo_getVendor(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::DeviceInfo *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.DeviceInfo");

    // const char *getVendor()
    const char *ret = self->getVendor();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_DeviceInfo_getVersion(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::DeviceInfo *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.DeviceInfo");

    // const char *getVersion()
    const char *ret = self->getVersion();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_DeviceInfo_init(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::DeviceInfo *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.DeviceInfo");

    // bool init()
    bool ret = self->init();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_cls_ccb_DeviceInfo(lua_State *L)
{
    oluacls_class<cocos2d::backend::DeviceInfo>(L, "ccb.DeviceInfo");
    oluacls_func(L, "__gc", _olua_fun_cocos2d_backend_DeviceInfo___gc);
    oluacls_func(L, "checkForFeatureSupported", _olua_fun_cocos2d_backend_DeviceInfo_checkForFeatureSupported);
    oluacls_func(L, "getExtension", _olua_fun_cocos2d_backend_DeviceInfo_getExtension);
    oluacls_func(L, "getMaxAttributes", _olua_fun_cocos2d_backend_DeviceInfo_getMaxAttributes);
    oluacls_func(L, "getMaxSamplesAllowed", _olua_fun_cocos2d_backend_DeviceInfo_getMaxSamplesAllowed);
    oluacls_func(L, "getMaxTextureSize", _olua_fun_cocos2d_backend_DeviceInfo_getMaxTextureSize);
    oluacls_func(L, "getMaxTextureUnits", _olua_fun_cocos2d_backend_DeviceInfo_getMaxTextureUnits);
    oluacls_func(L, "getRenderer", _olua_fun_cocos2d_backend_DeviceInfo_getRenderer);
    oluacls_func(L, "getVendor", _olua_fun_cocos2d_backend_DeviceInfo_getVendor);
    oluacls_func(L, "getVersion", _olua_fun_cocos2d_backend_DeviceInfo_getVersion);
    oluacls_func(L, "init", _olua_fun_cocos2d_backend_DeviceInfo_init);
    oluacls_prop(L, "extension", _olua_fun_cocos2d_backend_DeviceInfo_getExtension, nullptr);
    oluacls_prop(L, "maxAttributes", _olua_fun_cocos2d_backend_DeviceInfo_getMaxAttributes, nullptr);
    oluacls_prop(L, "maxSamplesAllowed", _olua_fun_cocos2d_backend_DeviceInfo_getMaxSamplesAllowed, nullptr);
    oluacls_prop(L, "maxTextureSize", _olua_fun_cocos2d_backend_DeviceInfo_getMaxTextureSize, nullptr);
    oluacls_prop(L, "maxTextureUnits", _olua_fun_cocos2d_backend_DeviceInfo_getMaxTextureUnits, nullptr);
    oluacls_prop(L, "renderer", _olua_fun_cocos2d_backend_DeviceInfo_getRenderer, nullptr);
    oluacls_prop(L, "vendor", _olua_fun_cocos2d_backend_DeviceInfo_getVendor, nullptr);
    oluacls_prop(L, "version", _olua_fun_cocos2d_backend_DeviceInfo_getVersion, nullptr);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccb_DeviceInfo(lua_State *L)
{
    olua_require(L, "cocos2d_backend",  _olua_module_cocos2d_backend);
    if (!olua_getclass(L, "ccb.DeviceInfo")) {
        luaL_error(L, "class not found: cocos2d::backend::DeviceInfo");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_backend_ShaderCache_destroyInstance(lua_State *L)
{
    olua_startinvoke(L);

    // static void destroyInstance()
    cocos2d::backend::ShaderCache::destroyInstance();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_ShaderCache_getInstance(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::backend::ShaderCache *getInstance()
    cocos2d::backend::ShaderCache *ret = cocos2d::backend::ShaderCache::getInstance();
    int num_ret = olua_push_object(L, ret, "ccb.ShaderCache");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_ShaderCache_newFragmentShaderModule(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** shaderSource */

    olua_check_string(L, 1, &arg1);

    // static cocos2d::backend::ShaderModule *newFragmentShaderModule(const std::string &shaderSource)
    cocos2d::backend::ShaderModule *ret = cocos2d::backend::ShaderCache::newFragmentShaderModule(arg1);
    int num_ret = olua_push_object(L, ret, "ccb.ShaderModule");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_ShaderCache_newVertexShaderModule(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** shaderSource */

    olua_check_string(L, 1, &arg1);

    // static cocos2d::backend::ShaderModule *newVertexShaderModule(const std::string &shaderSource)
    cocos2d::backend::ShaderModule *ret = cocos2d::backend::ShaderCache::newVertexShaderModule(arg1);
    int num_ret = olua_push_object(L, ret, "ccb.ShaderModule");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_ShaderCache_removeUnusedShader(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::ShaderCache *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.ShaderCache");

    // void removeUnusedShader()
    self->removeUnusedShader();

    olua_endinvoke(L);

    return 0;
}

static int _olua_cls_ccb_ShaderCache(lua_State *L)
{
    oluacls_class<cocos2d::backend::ShaderCache, cocos2d::Ref>(L, "ccb.ShaderCache");
    oluacls_func(L, "destroyInstance", _olua_fun_cocos2d_backend_ShaderCache_destroyInstance);
    oluacls_func(L, "getInstance", _olua_fun_cocos2d_backend_ShaderCache_getInstance);
    oluacls_func(L, "newFragmentShaderModule", _olua_fun_cocos2d_backend_ShaderCache_newFragmentShaderModule);
    oluacls_func(L, "newVertexShaderModule", _olua_fun_cocos2d_backend_ShaderCache_newVertexShaderModule);
    oluacls_func(L, "removeUnusedShader", _olua_fun_cocos2d_backend_ShaderCache_removeUnusedShader);
    oluacls_prop(L, "instance", _olua_fun_cocos2d_backend_ShaderCache_getInstance, nullptr);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccb_ShaderCache(lua_State *L)
{
    olua_require(L, "cocos2d_backend",  _olua_module_cocos2d_backend);
    if (!olua_getclass(L, "ccb.ShaderCache")) {
        luaL_error(L, "class not found: cocos2d::backend::ShaderCache");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_backend_ShaderModule_getHashValue(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::ShaderModule *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.ShaderModule");

    // std::size_t getHashValue()
    std::size_t ret = self->getHashValue();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_ShaderModule_getShaderStage(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::ShaderModule *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.ShaderModule");

    // cocos2d::backend::ShaderStage getShaderStage()
    cocos2d::backend::ShaderStage ret = self->getShaderStage();
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_cls_ccb_ShaderModule(lua_State *L)
{
    oluacls_class<cocos2d::backend::ShaderModule, cocos2d::Ref>(L, "ccb.ShaderModule");
    oluacls_func(L, "getHashValue", _olua_fun_cocos2d_backend_ShaderModule_getHashValue);
    oluacls_func(L, "getShaderStage", _olua_fun_cocos2d_backend_ShaderModule_getShaderStage);
    oluacls_prop(L, "hashValue", _olua_fun_cocos2d_backend_ShaderModule_getHashValue, nullptr);
    oluacls_prop(L, "shaderStage", _olua_fun_cocos2d_backend_ShaderModule_getShaderStage, nullptr);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccb_ShaderModule(lua_State *L)
{
    olua_require(L, "cocos2d_backend",  _olua_module_cocos2d_backend);
    if (!olua_getclass(L, "ccb.ShaderModule")) {
        luaL_error(L, "class not found: cocos2d::backend::ShaderModule");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_backend_ProgramCache_addCustomProgram(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::ProgramCache *self = nullptr;
    std::string arg1;       /** key */
    cocos2d::backend::Program *arg2 = nullptr;       /** program */

    olua_to_object(L, 1, &self, "ccb.ProgramCache");
    olua_check_string(L, 2, &arg1);
    olua_check_object(L, 3, &arg2, "ccb.Program");

    // void addCustomProgram(const std::string &key, cocos2d::backend::Program *program)
    self->addCustomProgram(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_ProgramCache_destroyInstance(lua_State *L)
{
    olua_startinvoke(L);

    // static void destroyInstance()
    cocos2d::backend::ProgramCache::destroyInstance();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_ProgramCache_getBuiltinProgram(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::ProgramCache *self = nullptr;
    cocos2d::backend::ProgramType arg1 = (cocos2d::backend::ProgramType)0;       /** type */

    olua_to_object(L, 1, &self, "ccb.ProgramCache");
    olua_check_enum(L, 2, &arg1);

    // cocos2d::backend::Program *getBuiltinProgram(cocos2d::backend::ProgramType type)
    cocos2d::backend::Program *ret = self->getBuiltinProgram(arg1);
    int num_ret = olua_push_object(L, ret, "ccb.Program");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_ProgramCache_getCustomProgram(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::ProgramCache *self = nullptr;
    std::string arg1;       /** key */

    olua_to_object(L, 1, &self, "ccb.ProgramCache");
    olua_check_string(L, 2, &arg1);

    // cocos2d::backend::Program *getCustomProgram(const std::string &key)
    cocos2d::backend::Program *ret = self->getCustomProgram(arg1);
    int num_ret = olua_push_object(L, ret, "ccb.Program");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_ProgramCache_getInstance(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::backend::ProgramCache *getInstance()
    cocos2d::backend::ProgramCache *ret = cocos2d::backend::ProgramCache::getInstance();
    int num_ret = olua_push_object(L, ret, "ccb.ProgramCache");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_ProgramCache_removeAllPrograms(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::ProgramCache *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.ProgramCache");

    // void removeAllPrograms()
    self->removeAllPrograms();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_ProgramCache_removeProgram(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::ProgramCache *self = nullptr;
    cocos2d::backend::Program *arg1 = nullptr;       /** program */

    olua_to_object(L, 1, &self, "ccb.ProgramCache");
    olua_check_object(L, 2, &arg1, "ccb.Program");

    // void removeProgram(cocos2d::backend::Program *program)
    self->removeProgram(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_ProgramCache_removeUnusedProgram(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::ProgramCache *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.ProgramCache");

    // void removeUnusedProgram()
    self->removeUnusedProgram();

    olua_endinvoke(L);

    return 0;
}

static int _olua_cls_ccb_ProgramCache(lua_State *L)
{
    oluacls_class<cocos2d::backend::ProgramCache, cocos2d::Ref>(L, "ccb.ProgramCache");
    oluacls_func(L, "addCustomProgram", _olua_fun_cocos2d_backend_ProgramCache_addCustomProgram);
    oluacls_func(L, "destroyInstance", _olua_fun_cocos2d_backend_ProgramCache_destroyInstance);
    oluacls_func(L, "getBuiltinProgram", _olua_fun_cocos2d_backend_ProgramCache_getBuiltinProgram);
    oluacls_func(L, "getCustomProgram", _olua_fun_cocos2d_backend_ProgramCache_getCustomProgram);
    oluacls_func(L, "getInstance", _olua_fun_cocos2d_backend_ProgramCache_getInstance);
    oluacls_func(L, "removeAllPrograms", _olua_fun_cocos2d_backend_ProgramCache_removeAllPrograms);
    oluacls_func(L, "removeProgram", _olua_fun_cocos2d_backend_ProgramCache_removeProgram);
    oluacls_func(L, "removeUnusedProgram", _olua_fun_cocos2d_backend_ProgramCache_removeUnusedProgram);
    oluacls_prop(L, "instance", _olua_fun_cocos2d_backend_ProgramCache_getInstance, nullptr);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccb_ProgramCache(lua_State *L)
{
    olua_require(L, "cocos2d_backend",  _olua_module_cocos2d_backend);
    if (!olua_getclass(L, "ccb.ProgramCache")) {
        luaL_error(L, "class not found: cocos2d::backend::ProgramCache");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_backend_ProgramState_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::ProgramState *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.ProgramState");

    // cocos2d::backend::ProgramState *clone()
    cocos2d::backend::ProgramState *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "ccb.ProgramState");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_ProgramState_getAttributeLocation$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::ProgramState *self = nullptr;
    std::string arg1;       /** name */

    olua_to_object(L, 1, &self, "ccb.ProgramState");
    olua_check_string(L, 2, &arg1);

    // int getAttributeLocation(const std::string &name)
    int ret = self->getAttributeLocation(arg1);
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_ProgramState_getAttributeLocation$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::ProgramState *self = nullptr;
    cocos2d::backend::Attribute arg1 = (cocos2d::backend::Attribute)0;       /** name */

    olua_to_object(L, 1, &self, "ccb.ProgramState");
    olua_check_enum(L, 2, &arg1);

    // int getAttributeLocation(cocos2d::backend::Attribute name)
    int ret = self->getAttributeLocation(arg1);
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_ProgramState_getAttributeLocation(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        if ((olua_is_object(L, 1, "ccb.ProgramState")) && (olua_is_string(L, 2))) {
            // int getAttributeLocation(const std::string &name)
            return _olua_fun_cocos2d_backend_ProgramState_getAttributeLocation$1(L);
        }

        // if ((olua_is_object(L, 1, "ccb.ProgramState")) && (olua_is_enum(L, 2))) {
            // int getAttributeLocation(cocos2d::backend::Attribute name)
            return _olua_fun_cocos2d_backend_ProgramState_getAttributeLocation$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::backend::ProgramState::getAttributeLocation' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_backend_ProgramState_getFragmentTextureInfos(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::ProgramState *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.ProgramState");

    // const std::unordered_map<int, cocos2d::backend::TextureInfo> &getFragmentTextureInfos()
    const std::unordered_map<int, cocos2d::backend::TextureInfo> &ret = self->getFragmentTextureInfos();
    int num_ret = olua_push_map<int, cocos2d::backend::TextureInfo>(L, ret, [L](int &arg1, cocos2d::backend::TextureInfo &arg2) {
        olua_push_integer(L, arg1);
        olua_copy_object(L, arg2, "ccb.TextureInfo");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_ProgramState_getProgram(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::ProgramState *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.ProgramState");

    // cocos2d::backend::Program *getProgram()
    cocos2d::backend::Program *ret = self->getProgram();
    int num_ret = olua_push_object(L, ret, "ccb.Program");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_ProgramState_getUniformLocation$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::ProgramState *self = nullptr;
    std::string arg1;       /** uniform */

    olua_to_object(L, 1, &self, "ccb.ProgramState");
    olua_check_string(L, 2, &arg1);

    // cocos2d::backend::UniformLocation getUniformLocation(const std::string &uniform)
    cocos2d::backend::UniformLocation ret = self->getUniformLocation(arg1);
    int num_ret = olua_copy_object(L, ret, "ccb.UniformLocation");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_ProgramState_getUniformLocation$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::ProgramState *self = nullptr;
    cocos2d::backend::Uniform arg1 = (cocos2d::backend::Uniform)0;       /** name */

    olua_to_object(L, 1, &self, "ccb.ProgramState");
    olua_check_enum(L, 2, &arg1);

    // cocos2d::backend::UniformLocation getUniformLocation(cocos2d::backend::Uniform name)
    cocos2d::backend::UniformLocation ret = self->getUniformLocation(arg1);
    int num_ret = olua_copy_object(L, ret, "ccb.UniformLocation");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_ProgramState_getUniformLocation(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        if ((olua_is_object(L, 1, "ccb.ProgramState")) && (olua_is_string(L, 2))) {
            // cocos2d::backend::UniformLocation getUniformLocation(const std::string &uniform)
            return _olua_fun_cocos2d_backend_ProgramState_getUniformLocation$1(L);
        }

        // if ((olua_is_object(L, 1, "ccb.ProgramState")) && (olua_is_enum(L, 2))) {
            // cocos2d::backend::UniformLocation getUniformLocation(cocos2d::backend::Uniform name)
            return _olua_fun_cocos2d_backend_ProgramState_getUniformLocation$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::backend::ProgramState::getUniformLocation' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_backend_ProgramState_getVertexLayout(lua_State *L)
{
    olua_startinvoke(L);

    auto self = olua_toobj<cocos2d::backend::ProgramState>(L, 1);
    olua_pushobj<cocos2d::backend::VertexLayout>(L, self->getVertexLayout().get());
    olua_addref(L, 1, "vertexLayout", -1, OLUA_REF_ALONE);

    olua_endinvoke(L);

    return 1;
}

static int _olua_fun_cocos2d_backend_ProgramState_getVertexTextureInfos(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::ProgramState *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.ProgramState");

    // const std::unordered_map<int, cocos2d::backend::TextureInfo> &getVertexTextureInfos()
    const std::unordered_map<int, cocos2d::backend::TextureInfo> &ret = self->getVertexTextureInfos();
    int num_ret = olua_push_map<int, cocos2d::backend::TextureInfo>(L, ret, [L](int &arg1, cocos2d::backend::TextureInfo &arg2) {
        olua_push_integer(L, arg1);
        olua_copy_object(L, arg2, "ccb.TextureInfo");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_ProgramState_new(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::Program *arg1 = nullptr;       /** program */

    olua_check_object(L, 1, &arg1, "ccb.Program");

    // cocos2d::backend::ProgramState(cocos2d::backend::Program *program)
    cocos2d::backend::ProgramState *ret = new cocos2d::backend::ProgramState(arg1);
    int num_ret = olua_push_object(L, ret, "ccb.ProgramState");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_ProgramState_setParameterAutoBinding(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::ProgramState *self = nullptr;
    std::string arg1;       /** uniformName */
    std::string arg2;       /** autoBinding */

    olua_to_object(L, 1, &self, "ccb.ProgramState");
    olua_check_string(L, 2, &arg1);
    olua_check_string(L, 3, &arg2);

    // void setParameterAutoBinding(const std::string &uniformName, const std::string &autoBinding)
    self->setParameterAutoBinding(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_ProgramState_setTexture(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::ProgramState *self = nullptr;
    cocos2d::backend::UniformLocation *arg1;       /** uniformLocation */
    uint32_t arg2 = 0;       /** slot */
    cocos2d::backend::TextureBackend *arg3 = nullptr;       /** texture */

    olua_to_object(L, 1, &self, "ccb.ProgramState");
    olua_check_object(L, 2, &arg1, "ccb.UniformLocation");
    olua_check_integer(L, 3, &arg2);
    olua_check_object(L, 4, &arg3, "ccb.TextureBackend");

    // void setTexture(const cocos2d::backend::UniformLocation &uniformLocation, uint32_t slot, cocos2d::backend::TextureBackend *texture)
    self->setTexture(*arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_ProgramState_setTextureArray(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::ProgramState *self = nullptr;
    cocos2d::backend::UniformLocation *arg1;       /** uniformLocation */
    std::vector<uint32_t> arg2;       /** slots */
    std::vector<cocos2d::backend::TextureBackend *> arg3;       /** textures */

    olua_to_object(L, 1, &self, "ccb.ProgramState");
    olua_check_object(L, 2, &arg1, "ccb.UniformLocation");
    olua_check_array<uint32_t>(L, 3, arg2, [L](uint32_t *arg1) {
        olua_check_integer(L, -1, arg1);
    });
    olua_check_array<cocos2d::backend::TextureBackend *>(L, 4, arg3, [L](cocos2d::backend::TextureBackend **arg1) {
        olua_check_object(L, -1, arg1, "ccb.TextureBackend");
    });

    // void setTextureArray(const cocos2d::backend::UniformLocation &uniformLocation, const std::vector<uint32_t> &slots, const std::vector<cocos2d::backend::TextureBackend *> textures)
    self->setTextureArray(*arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_ProgramState_setUniform(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::ProgramState *self = nullptr;
    cocos2d::backend::UniformLocation *arg1;       /** uniformLocation */
    void *arg2 = nullptr;       /** data */
    std::size_t arg3 = 0;       /** size */

    olua_to_object(L, 1, &self, "ccb.ProgramState");
    olua_check_object(L, 2, &arg1, "ccb.UniformLocation");
    olua_check_object(L, 3, &arg2, "void *");
    olua_check_integer(L, 4, &arg3);

    // void setUniform(const cocos2d::backend::UniformLocation &uniformLocation, const void *data, std::size_t size)
    self->setUniform(*arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_cls_ccb_ProgramState(lua_State *L)
{
    oluacls_class<cocos2d::backend::ProgramState, cocos2d::Ref>(L, "ccb.ProgramState");
    oluacls_func(L, "clone", _olua_fun_cocos2d_backend_ProgramState_clone);
    oluacls_func(L, "getAttributeLocation", _olua_fun_cocos2d_backend_ProgramState_getAttributeLocation);
    oluacls_func(L, "getFragmentTextureInfos", _olua_fun_cocos2d_backend_ProgramState_getFragmentTextureInfos);
    oluacls_func(L, "getProgram", _olua_fun_cocos2d_backend_ProgramState_getProgram);
    oluacls_func(L, "getUniformLocation", _olua_fun_cocos2d_backend_ProgramState_getUniformLocation);
    oluacls_func(L, "getVertexLayout", _olua_fun_cocos2d_backend_ProgramState_getVertexLayout);
    oluacls_func(L, "getVertexTextureInfos", _olua_fun_cocos2d_backend_ProgramState_getVertexTextureInfos);
    oluacls_func(L, "new", _olua_fun_cocos2d_backend_ProgramState_new);
    oluacls_func(L, "setParameterAutoBinding", _olua_fun_cocos2d_backend_ProgramState_setParameterAutoBinding);
    oluacls_func(L, "setTexture", _olua_fun_cocos2d_backend_ProgramState_setTexture);
    oluacls_func(L, "setTextureArray", _olua_fun_cocos2d_backend_ProgramState_setTextureArray);
    oluacls_func(L, "setUniform", _olua_fun_cocos2d_backend_ProgramState_setUniform);
    oluacls_prop(L, "fragmentTextureInfos", _olua_fun_cocos2d_backend_ProgramState_getFragmentTextureInfos, nullptr);
    oluacls_prop(L, "program", _olua_fun_cocos2d_backend_ProgramState_getProgram, nullptr);
    oluacls_prop(L, "vertexTextureInfos", _olua_fun_cocos2d_backend_ProgramState_getVertexTextureInfos, nullptr);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccb_ProgramState(lua_State *L)
{
    olua_require(L, "cocos2d_backend",  _olua_module_cocos2d_backend);
    if (!olua_getclass(L, "ccb.ProgramState")) {
        luaL_error(L, "class not found: cocos2d::backend::ProgramState");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_backend_Program_getActiveAttributes(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::Program *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.Program");

    // const std::unordered_map<std::string, cocos2d::backend::AttributeBindInfo> getActiveAttributes()
    const std::unordered_map<std::string, cocos2d::backend::AttributeBindInfo> ret = self->getActiveAttributes();
    int num_ret = olua_push_map<std::string, cocos2d::backend::AttributeBindInfo>(L, ret, [L](std::string &arg1, cocos2d::backend::AttributeBindInfo &arg2) {
        olua_push_string(L, arg1);
        olua_copy_object(L, arg2, "ccb.AttributeBindInfo");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_Program_getActiveUniformInfo(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::Program *self = nullptr;
    cocos2d::backend::ShaderStage arg1 = (cocos2d::backend::ShaderStage)0;       /** stage */
    int arg2 = 0;       /** location */

    olua_to_object(L, 1, &self, "ccb.Program");
    olua_check_enum(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // const cocos2d::backend::UniformInfo &getActiveUniformInfo(cocos2d::backend::ShaderStage stage, int location)
    const cocos2d::backend::UniformInfo &ret = self->getActiveUniformInfo(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "ccb.UniformInfo");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_Program_getAllActiveUniformInfo(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::Program *self = nullptr;
    cocos2d::backend::ShaderStage arg1 = (cocos2d::backend::ShaderStage)0;       /** stage */

    olua_to_object(L, 1, &self, "ccb.Program");
    olua_check_enum(L, 2, &arg1);

    // const std::unordered_map<std::string, cocos2d::backend::UniformInfo> &getAllActiveUniformInfo(cocos2d::backend::ShaderStage stage)
    const std::unordered_map<std::string, cocos2d::backend::UniformInfo> &ret = self->getAllActiveUniformInfo(arg1);
    int num_ret = olua_push_map<std::string, cocos2d::backend::UniformInfo>(L, ret, [L](std::string &arg1, cocos2d::backend::UniformInfo &arg2) {
        olua_push_string(L, arg1);
        olua_copy_object(L, arg2, "ccb.UniformInfo");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_Program_getAttributeLocation$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::Program *self = nullptr;
    std::string arg1;       /** name */

    olua_to_object(L, 1, &self, "ccb.Program");
    olua_check_string(L, 2, &arg1);

    // int getAttributeLocation(const std::string &name)
    int ret = self->getAttributeLocation(arg1);
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_Program_getAttributeLocation$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::Program *self = nullptr;
    cocos2d::backend::Attribute arg1 = (cocos2d::backend::Attribute)0;       /** name */

    olua_to_object(L, 1, &self, "ccb.Program");
    olua_check_enum(L, 2, &arg1);

    // int getAttributeLocation(cocos2d::backend::Attribute name)
    int ret = self->getAttributeLocation(arg1);
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_Program_getAttributeLocation(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        if ((olua_is_object(L, 1, "ccb.Program")) && (olua_is_string(L, 2))) {
            // int getAttributeLocation(const std::string &name)
            return _olua_fun_cocos2d_backend_Program_getAttributeLocation$1(L);
        }

        // if ((olua_is_object(L, 1, "ccb.Program")) && (olua_is_enum(L, 2))) {
            // int getAttributeLocation(cocos2d::backend::Attribute name)
            return _olua_fun_cocos2d_backend_Program_getAttributeLocation$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::backend::Program::getAttributeLocation' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_backend_Program_getBuiltinProgram(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::ProgramType arg1 = (cocos2d::backend::ProgramType)0;       /** type */

    olua_check_enum(L, 1, &arg1);

    // static cocos2d::backend::Program *getBuiltinProgram(cocos2d::backend::ProgramType type)
    cocos2d::backend::Program *ret = cocos2d::backend::Program::getBuiltinProgram(arg1);
    int num_ret = olua_push_object(L, ret, "ccb.Program");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_Program_getFragmentShader(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::Program *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.Program");

    // const std::string &getFragmentShader()
    const std::string &ret = self->getFragmentShader();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_Program_getMaxFragmentLocation(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::Program *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.Program");

    // int getMaxFragmentLocation()
    int ret = self->getMaxFragmentLocation();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_Program_getMaxVertexLocation(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::Program *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.Program");

    // int getMaxVertexLocation()
    int ret = self->getMaxVertexLocation();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_Program_getProgramType(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::Program *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.Program");

    // cocos2d::backend::ProgramType getProgramType()
    cocos2d::backend::ProgramType ret = self->getProgramType();
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_Program_getUniformBufferSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::Program *self = nullptr;
    cocos2d::backend::ShaderStage arg1 = (cocos2d::backend::ShaderStage)0;       /** stage */

    olua_to_object(L, 1, &self, "ccb.Program");
    olua_check_enum(L, 2, &arg1);

    // std::size_t getUniformBufferSize(cocos2d::backend::ShaderStage stage)
    std::size_t ret = self->getUniformBufferSize(arg1);
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_Program_getUniformLocation$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::Program *self = nullptr;
    std::string arg1;       /** uniform */

    olua_to_object(L, 1, &self, "ccb.Program");
    olua_check_string(L, 2, &arg1);

    // cocos2d::backend::UniformLocation getUniformLocation(const std::string &uniform)
    cocos2d::backend::UniformLocation ret = self->getUniformLocation(arg1);
    int num_ret = olua_copy_object(L, ret, "ccb.UniformLocation");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_Program_getUniformLocation$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::Program *self = nullptr;
    cocos2d::backend::Uniform arg1 = (cocos2d::backend::Uniform)0;       /** name */

    olua_to_object(L, 1, &self, "ccb.Program");
    olua_check_enum(L, 2, &arg1);

    // cocos2d::backend::UniformLocation getUniformLocation(cocos2d::backend::Uniform name)
    cocos2d::backend::UniformLocation ret = self->getUniformLocation(arg1);
    int num_ret = olua_copy_object(L, ret, "ccb.UniformLocation");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_Program_getUniformLocation(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        if ((olua_is_object(L, 1, "ccb.Program")) && (olua_is_string(L, 2))) {
            // cocos2d::backend::UniformLocation getUniformLocation(const std::string &uniform)
            return _olua_fun_cocos2d_backend_Program_getUniformLocation$1(L);
        }

        // if ((olua_is_object(L, 1, "ccb.Program")) && (olua_is_enum(L, 2))) {
            // cocos2d::backend::UniformLocation getUniformLocation(cocos2d::backend::Uniform name)
            return _olua_fun_cocos2d_backend_Program_getUniformLocation$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::backend::Program::getUniformLocation' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_backend_Program_getVertexShader(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::Program *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.Program");

    // const std::string &getVertexShader()
    const std::string &ret = self->getVertexShader();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_cls_ccb_Program(lua_State *L)
{
    oluacls_class<cocos2d::backend::Program, cocos2d::Ref>(L, "ccb.Program");
    oluacls_func(L, "getActiveAttributes", _olua_fun_cocos2d_backend_Program_getActiveAttributes);
    oluacls_func(L, "getActiveUniformInfo", _olua_fun_cocos2d_backend_Program_getActiveUniformInfo);
    oluacls_func(L, "getAllActiveUniformInfo", _olua_fun_cocos2d_backend_Program_getAllActiveUniformInfo);
    oluacls_func(L, "getAttributeLocation", _olua_fun_cocos2d_backend_Program_getAttributeLocation);
    oluacls_func(L, "getBuiltinProgram", _olua_fun_cocos2d_backend_Program_getBuiltinProgram);
    oluacls_func(L, "getFragmentShader", _olua_fun_cocos2d_backend_Program_getFragmentShader);
    oluacls_func(L, "getMaxFragmentLocation", _olua_fun_cocos2d_backend_Program_getMaxFragmentLocation);
    oluacls_func(L, "getMaxVertexLocation", _olua_fun_cocos2d_backend_Program_getMaxVertexLocation);
    oluacls_func(L, "getProgramType", _olua_fun_cocos2d_backend_Program_getProgramType);
    oluacls_func(L, "getUniformBufferSize", _olua_fun_cocos2d_backend_Program_getUniformBufferSize);
    oluacls_func(L, "getUniformLocation", _olua_fun_cocos2d_backend_Program_getUniformLocation);
    oluacls_func(L, "getVertexShader", _olua_fun_cocos2d_backend_Program_getVertexShader);
    oluacls_prop(L, "activeAttributes", _olua_fun_cocos2d_backend_Program_getActiveAttributes, nullptr);
    oluacls_prop(L, "fragmentShader", _olua_fun_cocos2d_backend_Program_getFragmentShader, nullptr);
    oluacls_prop(L, "maxFragmentLocation", _olua_fun_cocos2d_backend_Program_getMaxFragmentLocation, nullptr);
    oluacls_prop(L, "maxVertexLocation", _olua_fun_cocos2d_backend_Program_getMaxVertexLocation, nullptr);
    oluacls_prop(L, "programType", _olua_fun_cocos2d_backend_Program_getProgramType, nullptr);
    oluacls_prop(L, "vertexShader", _olua_fun_cocos2d_backend_Program_getVertexShader, nullptr);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccb_Program(lua_State *L)
{
    olua_require(L, "cocos2d_backend",  _olua_module_cocos2d_backend);
    if (!olua_getclass(L, "ccb.Program")) {
        luaL_error(L, "class not found: cocos2d::backend::Program");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_backend_TextureBackend_generateMipmaps(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::TextureBackend *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.TextureBackend");

    // void generateMipmaps()
    self->generateMipmaps();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_TextureBackend_getBytes(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::TextureBackend *self = nullptr;
    std::size_t arg1 = 0;       /** x */
    std::size_t arg2 = 0;       /** y */
    std::size_t arg3 = 0;       /** width */
    std::size_t arg4 = 0;       /** height */
    bool arg5 = false;       /** flipImage */
    std::function<void (const unsigned char *, std::size_t, std::size_t)> arg6;       /** callback */

    olua_to_object(L, 1, &self, "ccb.TextureBackend");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);
    olua_check_integer(L, 4, &arg3);
    olua_check_integer(L, 5, &arg4);
    olua_check_bool(L, 6, &arg5);
    olua_check_callback(L, 7, &arg6, "std.function");

    void *cb_store = (void *)self;
    std::string cb_tag = "Bytes";
    std::string cb_name = olua_setcallback(L, cb_store, 7, cb_tag.c_str(), OLUA_TAG_NEW);
    olua_Context cb_ctx = olua_context(L);
    // lua_State *ML = olua_mainthread(L);
    arg6 = [cb_store, cb_name, cb_ctx /*, ML */](const unsigned char *cb_arg1, std::size_t cb_arg2, std::size_t cb_arg3) {
        lua_State *L = olua_mainthread(NULL);
        olua_checkhostthread();

        if (olua_contextequal(L, cb_ctx)) {
            int top = lua_gettop(L);
            olua_push_string(L, cb_arg1);
            olua_push_integer(L, cb_arg2);
            olua_push_integer(L, cb_arg3);

            olua_callback(L, cb_store, cb_name.c_str(), 3);

            olua_removecallback(L, cb_store, cb_name.c_str(), OLUA_TAG_WHOLE);

            lua_settop(L, top);
        }
    };

    // void getBytes(std::size_t x, std::size_t y, std::size_t width, std::size_t height, bool flipImage, std::function<void (const unsigned char *, std::size_t, std::size_t)> callback)
    self->getBytes(arg1, arg2, arg3, arg4, arg5, arg6);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_TextureBackend_getTextureFormat(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::TextureBackend *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.TextureBackend");

    // cocos2d::backend::PixelFormat getTextureFormat()
    cocos2d::backend::PixelFormat ret = self->getTextureFormat();
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_TextureBackend_getTextureType(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::TextureBackend *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.TextureBackend");

    // cocos2d::backend::TextureType getTextureType()
    cocos2d::backend::TextureType ret = self->getTextureType();
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_TextureBackend_getTextureUsage(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::TextureBackend *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.TextureBackend");

    // cocos2d::backend::TextureUsage getTextureUsage()
    cocos2d::backend::TextureUsage ret = self->getTextureUsage();
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_TextureBackend_hasMipmaps(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::TextureBackend *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.TextureBackend");

    // bool hasMipmaps()
    bool ret = self->hasMipmaps();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_TextureBackend_updateSamplerDescriptor(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::TextureBackend *self = nullptr;
    cocos2d::backend::SamplerDescriptor *arg1;       /** sampler */

    olua_to_object(L, 1, &self, "ccb.TextureBackend");
    olua_check_object(L, 2, &arg1, "ccb.SamplerDescriptor");

    // void updateSamplerDescriptor(const cocos2d::backend::SamplerDescriptor &sampler)
    self->updateSamplerDescriptor(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_TextureBackend_updateTextureDescriptor(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::TextureBackend *self = nullptr;
    cocos2d::backend::TextureDescriptor *arg1;       /** descriptor */

    olua_to_object(L, 1, &self, "ccb.TextureBackend");
    olua_check_object(L, 2, &arg1, "ccb.TextureDescriptor");

    // void updateTextureDescriptor(const cocos2d::backend::TextureDescriptor &descriptor)
    self->updateTextureDescriptor(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_cls_ccb_TextureBackend(lua_State *L)
{
    oluacls_class<cocos2d::backend::TextureBackend, cocos2d::Ref>(L, "ccb.TextureBackend");
    oluacls_func(L, "generateMipmaps", _olua_fun_cocos2d_backend_TextureBackend_generateMipmaps);
    oluacls_func(L, "getBytes", _olua_fun_cocos2d_backend_TextureBackend_getBytes);
    oluacls_func(L, "getTextureFormat", _olua_fun_cocos2d_backend_TextureBackend_getTextureFormat);
    oluacls_func(L, "getTextureType", _olua_fun_cocos2d_backend_TextureBackend_getTextureType);
    oluacls_func(L, "getTextureUsage", _olua_fun_cocos2d_backend_TextureBackend_getTextureUsage);
    oluacls_func(L, "hasMipmaps", _olua_fun_cocos2d_backend_TextureBackend_hasMipmaps);
    oluacls_func(L, "updateSamplerDescriptor", _olua_fun_cocos2d_backend_TextureBackend_updateSamplerDescriptor);
    oluacls_func(L, "updateTextureDescriptor", _olua_fun_cocos2d_backend_TextureBackend_updateTextureDescriptor);
    oluacls_prop(L, "textureFormat", _olua_fun_cocos2d_backend_TextureBackend_getTextureFormat, nullptr);
    oluacls_prop(L, "textureType", _olua_fun_cocos2d_backend_TextureBackend_getTextureType, nullptr);
    oluacls_prop(L, "textureUsage", _olua_fun_cocos2d_backend_TextureBackend_getTextureUsage, nullptr);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccb_TextureBackend(lua_State *L)
{
    olua_require(L, "cocos2d_backend",  _olua_module_cocos2d_backend);
    if (!olua_getclass(L, "ccb.TextureBackend")) {
        luaL_error(L, "class not found: cocos2d::backend::TextureBackend");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_backend_Texture2DBackend_getHeight(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::Texture2DBackend *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.Texture2DBackend");

    // std::size_t getHeight()
    std::size_t ret = self->getHeight();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_Texture2DBackend_getWidth(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::Texture2DBackend *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.Texture2DBackend");

    // std::size_t getWidth()
    std::size_t ret = self->getWidth();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_Texture2DBackend_updateCompressedData(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::Texture2DBackend *self = nullptr;
    uint8_t *arg1 = nullptr;       /** data */
    std::size_t arg2 = 0;       /** width */
    std::size_t arg3 = 0;       /** height */
    std::size_t arg4 = 0;       /** dataLen */
    std::size_t arg5 = 0;       /** level */

    olua_to_object(L, 1, &self, "ccb.Texture2DBackend");
    olua_check_pointer(L, 2, &arg1, "olua.uint8");
    olua_check_integer(L, 3, &arg2);
    olua_check_integer(L, 4, &arg3);
    olua_check_integer(L, 5, &arg4);
    olua_check_integer(L, 6, &arg5);

    // void updateCompressedData(uint8_t *data, std::size_t width, std::size_t height, std::size_t dataLen, std::size_t level)
    self->updateCompressedData(arg1, arg2, arg3, arg4, arg5);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_Texture2DBackend_updateCompressedSubData(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::Texture2DBackend *self = nullptr;
    std::size_t arg1 = 0;       /** xoffset */
    std::size_t arg2 = 0;       /** yoffset */
    std::size_t arg3 = 0;       /** width */
    std::size_t arg4 = 0;       /** height */
    std::size_t arg5 = 0;       /** dataLen */
    std::size_t arg6 = 0;       /** level */
    uint8_t *arg7 = nullptr;       /** data */

    olua_to_object(L, 1, &self, "ccb.Texture2DBackend");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);
    olua_check_integer(L, 4, &arg3);
    olua_check_integer(L, 5, &arg4);
    olua_check_integer(L, 6, &arg5);
    olua_check_integer(L, 7, &arg6);
    olua_check_pointer(L, 8, &arg7, "olua.uint8");

    // void updateCompressedSubData(std::size_t xoffset, std::size_t yoffset, std::size_t width, std::size_t height, std::size_t dataLen, std::size_t level, uint8_t *data)
    self->updateCompressedSubData(arg1, arg2, arg3, arg4, arg5, arg6, arg7);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_Texture2DBackend_updateData(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::Texture2DBackend *self = nullptr;
    uint8_t *arg1 = nullptr;       /** data */
    std::size_t arg2 = 0;       /** width */
    std::size_t arg3 = 0;       /** height */
    std::size_t arg4 = 0;       /** level */

    olua_to_object(L, 1, &self, "ccb.Texture2DBackend");
    olua_check_pointer(L, 2, &arg1, "olua.uint8");
    olua_check_integer(L, 3, &arg2);
    olua_check_integer(L, 4, &arg3);
    olua_check_integer(L, 5, &arg4);

    // void updateData(uint8_t *data, std::size_t width, std::size_t height, std::size_t level)
    self->updateData(arg1, arg2, arg3, arg4);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_Texture2DBackend_updateSubData(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::Texture2DBackend *self = nullptr;
    std::size_t arg1 = 0;       /** xoffset */
    std::size_t arg2 = 0;       /** yoffset */
    std::size_t arg3 = 0;       /** width */
    std::size_t arg4 = 0;       /** height */
    std::size_t arg5 = 0;       /** level */
    uint8_t *arg6 = nullptr;       /** data */

    olua_to_object(L, 1, &self, "ccb.Texture2DBackend");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);
    olua_check_integer(L, 4, &arg3);
    olua_check_integer(L, 5, &arg4);
    olua_check_integer(L, 6, &arg5);
    olua_check_pointer(L, 7, &arg6, "olua.uint8");

    // void updateSubData(std::size_t xoffset, std::size_t yoffset, std::size_t width, std::size_t height, std::size_t level, uint8_t *data)
    self->updateSubData(arg1, arg2, arg3, arg4, arg5, arg6);

    olua_endinvoke(L);

    return 0;
}

static int _olua_cls_ccb_Texture2DBackend(lua_State *L)
{
    oluacls_class<cocos2d::backend::Texture2DBackend, cocos2d::backend::TextureBackend>(L, "ccb.Texture2DBackend");
    oluacls_func(L, "getHeight", _olua_fun_cocos2d_backend_Texture2DBackend_getHeight);
    oluacls_func(L, "getWidth", _olua_fun_cocos2d_backend_Texture2DBackend_getWidth);
    oluacls_func(L, "updateCompressedData", _olua_fun_cocos2d_backend_Texture2DBackend_updateCompressedData);
    oluacls_func(L, "updateCompressedSubData", _olua_fun_cocos2d_backend_Texture2DBackend_updateCompressedSubData);
    oluacls_func(L, "updateData", _olua_fun_cocos2d_backend_Texture2DBackend_updateData);
    oluacls_func(L, "updateSubData", _olua_fun_cocos2d_backend_Texture2DBackend_updateSubData);
    oluacls_prop(L, "height", _olua_fun_cocos2d_backend_Texture2DBackend_getHeight, nullptr);
    oluacls_prop(L, "width", _olua_fun_cocos2d_backend_Texture2DBackend_getWidth, nullptr);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccb_Texture2DBackend(lua_State *L)
{
    olua_require(L, "cocos2d_backend",  _olua_module_cocos2d_backend);
    if (!olua_getclass(L, "ccb.Texture2DBackend")) {
        luaL_error(L, "class not found: cocos2d::backend::Texture2DBackend");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_backend_TextureCubemapBackend_updateFaceData(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::TextureCubemapBackend *self = nullptr;
    cocos2d::backend::TextureCubeFace arg1 = (cocos2d::backend::TextureCubeFace)0;       /** side */
    void *arg2 = nullptr;       /** data */

    olua_to_object(L, 1, &self, "ccb.TextureCubemapBackend");
    olua_check_enum(L, 2, &arg1);
    olua_check_object(L, 3, &arg2, "void *");

    // void updateFaceData(cocos2d::backend::TextureCubeFace side, void *data)
    self->updateFaceData(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_cls_ccb_TextureCubemapBackend(lua_State *L)
{
    oluacls_class<cocos2d::backend::TextureCubemapBackend, cocos2d::backend::TextureBackend>(L, "ccb.TextureCubemapBackend");
    oluacls_func(L, "updateFaceData", _olua_fun_cocos2d_backend_TextureCubemapBackend_updateFaceData);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccb_TextureCubemapBackend(lua_State *L)
{
    olua_require(L, "cocos2d_backend",  _olua_module_cocos2d_backend);
    if (!olua_getclass(L, "ccb.TextureCubemapBackend")) {
        luaL_error(L, "class not found: cocos2d::backend::TextureCubemapBackend");
    }
    return 1;
}
OLUA_END_DECLS

int _olua_module_cocos2d_backend(lua_State *L)
{
    olua_require(L, "ccb.UniformLocation", _olua_cls_ccb_UniformLocation);
    olua_require(L, "ccb.BufferUsage", _olua_cls_ccb_BufferUsage);
    olua_require(L, "ccb.BufferType", _olua_cls_ccb_BufferType);
    olua_require(L, "ccb.ShaderStage", _olua_cls_ccb_ShaderStage);
    olua_require(L, "ccb.VertexFormat", _olua_cls_ccb_VertexFormat);
    olua_require(L, "ccb.PixelFormat", _olua_cls_ccb_PixelFormat);
    olua_require(L, "ccb.TextureUsage", _olua_cls_ccb_TextureUsage);
    olua_require(L, "ccb.IndexFormat", _olua_cls_ccb_IndexFormat);
    olua_require(L, "ccb.VertexStepMode", _olua_cls_ccb_VertexStepMode);
    olua_require(L, "ccb.PrimitiveType", _olua_cls_ccb_PrimitiveType);
    olua_require(L, "ccb.TextureType", _olua_cls_ccb_TextureType);
    olua_require(L, "ccb.SamplerAddressMode", _olua_cls_ccb_SamplerAddressMode);
    olua_require(L, "ccb.SamplerFilter", _olua_cls_ccb_SamplerFilter);
    olua_require(L, "ccb.StencilOperation", _olua_cls_ccb_StencilOperation);
    olua_require(L, "ccb.CompareFunction", _olua_cls_ccb_CompareFunction);
    olua_require(L, "ccb.BlendOperation", _olua_cls_ccb_BlendOperation);
    olua_require(L, "ccb.BlendFactor", _olua_cls_ccb_BlendFactor);
    olua_require(L, "ccb.ColorWriteMask", _olua_cls_ccb_ColorWriteMask);
    olua_require(L, "ccb.CullMode", _olua_cls_ccb_CullMode);
    olua_require(L, "ccb.Winding", _olua_cls_ccb_Winding);
    olua_require(L, "ccb.TextureCubeFace", _olua_cls_ccb_TextureCubeFace);
    olua_require(L, "ccb.ProgramType", _olua_cls_ccb_ProgramType);
    olua_require(L, "ccb.Uniform", _olua_cls_ccb_Uniform);
    olua_require(L, "ccb.Attribute", _olua_cls_ccb_Attribute);
    olua_require(L, "ccb.FeatureType", _olua_cls_ccb_FeatureType);
    olua_require(L, "ccb.Buffer", _olua_cls_ccb_Buffer);
    olua_require(L, "ccb.RenderPipeline", _olua_cls_ccb_RenderPipeline);
    olua_require(L, "ccb.DepthStencilState", _olua_cls_ccb_DepthStencilState);
    olua_require(L, "ccb.VertexLayout", _olua_cls_ccb_VertexLayout);
    olua_require(L, "ccb.CommandBuffer", _olua_cls_ccb_CommandBuffer);
    olua_require(L, "ccb.Device", _olua_cls_ccb_Device);
    olua_require(L, "ccb.DeviceInfo", _olua_cls_ccb_DeviceInfo);
    olua_require(L, "ccb.ShaderCache", _olua_cls_ccb_ShaderCache);
    olua_require(L, "ccb.ShaderModule", _olua_cls_ccb_ShaderModule);
    olua_require(L, "ccb.ProgramCache", _olua_cls_ccb_ProgramCache);
    olua_require(L, "ccb.ProgramState", _olua_cls_ccb_ProgramState);
    olua_require(L, "ccb.Program", _olua_cls_ccb_Program);
    olua_require(L, "ccb.TextureBackend", _olua_cls_ccb_TextureBackend);
    olua_require(L, "ccb.Texture2DBackend", _olua_cls_ccb_Texture2DBackend);
    olua_require(L, "ccb.TextureCubemapBackend", _olua_cls_ccb_TextureCubemapBackend);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_backend(lua_State *L)
{
    olua_require(L, "cocos2d_backend",  _olua_module_cocos2d_backend);

    return 0;
}
OLUA_END_DECLS
