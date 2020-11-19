//
// AUTO BUILD, DON'T MODIFY!
//
#include "lua_cocos2d_backend.h"
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "cocos2d.h"
#include "xgame/xlua.h"

static int luaopen_cocos2d_backend_BufferUsage(lua_State *L)
{
    oluacls_class(L, "ccb.BufferUsage", nullptr);
    oluacls_const_integer(L, "DYNAMIC", (lua_Integer)cocos2d::backend::BufferUsage::DYNAMIC);
    oluacls_const_integer(L, "STATIC", (lua_Integer)cocos2d::backend::BufferUsage::STATIC);

    olua_registerluatype<cocos2d::backend::BufferUsage>(L, "ccb.BufferUsage");

    return 1;
}

static int luaopen_cocos2d_backend_BufferType(lua_State *L)
{
    oluacls_class(L, "ccb.BufferType", nullptr);
    oluacls_const_integer(L, "INDEX", (lua_Integer)cocos2d::backend::BufferType::INDEX);
    oluacls_const_integer(L, "VERTEX", (lua_Integer)cocos2d::backend::BufferType::VERTEX);

    olua_registerluatype<cocos2d::backend::BufferType>(L, "ccb.BufferType");

    return 1;
}

static int luaopen_cocos2d_backend_ShaderStage(lua_State *L)
{
    oluacls_class(L, "ccb.ShaderStage", nullptr);
    oluacls_const_integer(L, "FRAGMENT", (lua_Integer)cocos2d::backend::ShaderStage::FRAGMENT);
    oluacls_const_integer(L, "VERTEX", (lua_Integer)cocos2d::backend::ShaderStage::VERTEX);
    oluacls_const_integer(L, "VERTEX_AND_FRAGMENT", (lua_Integer)cocos2d::backend::ShaderStage::VERTEX_AND_FRAGMENT);

    olua_registerluatype<cocos2d::backend::ShaderStage>(L, "ccb.ShaderStage");

    return 1;
}

static int luaopen_cocos2d_backend_VertexFormat(lua_State *L)
{
    oluacls_class(L, "ccb.VertexFormat", nullptr);
    oluacls_const_integer(L, "FLOAT", (lua_Integer)cocos2d::backend::VertexFormat::FLOAT);
    oluacls_const_integer(L, "FLOAT2", (lua_Integer)cocos2d::backend::VertexFormat::FLOAT2);
    oluacls_const_integer(L, "FLOAT3", (lua_Integer)cocos2d::backend::VertexFormat::FLOAT3);
    oluacls_const_integer(L, "FLOAT4", (lua_Integer)cocos2d::backend::VertexFormat::FLOAT4);
    oluacls_const_integer(L, "INT", (lua_Integer)cocos2d::backend::VertexFormat::INT);
    oluacls_const_integer(L, "INT2", (lua_Integer)cocos2d::backend::VertexFormat::INT2);
    oluacls_const_integer(L, "INT3", (lua_Integer)cocos2d::backend::VertexFormat::INT3);
    oluacls_const_integer(L, "INT4", (lua_Integer)cocos2d::backend::VertexFormat::INT4);
    oluacls_const_integer(L, "UBYTE4", (lua_Integer)cocos2d::backend::VertexFormat::UBYTE4);
    oluacls_const_integer(L, "USHORT2", (lua_Integer)cocos2d::backend::VertexFormat::USHORT2);
    oluacls_const_integer(L, "USHORT4", (lua_Integer)cocos2d::backend::VertexFormat::USHORT4);

    olua_registerluatype<cocos2d::backend::VertexFormat>(L, "ccb.VertexFormat");

    return 1;
}

static int luaopen_cocos2d_backend_PixelFormat(lua_State *L)
{
    oluacls_class(L, "ccb.PixelFormat", nullptr);
    oluacls_const_integer(L, "A8", (lua_Integer)cocos2d::backend::PixelFormat::A8);
    oluacls_const_integer(L, "AI88", (lua_Integer)cocos2d::backend::PixelFormat::AI88);
    oluacls_const_integer(L, "ATC_EXPLICIT_ALPHA", (lua_Integer)cocos2d::backend::PixelFormat::ATC_EXPLICIT_ALPHA);
    oluacls_const_integer(L, "ATC_INTERPOLATED_ALPHA", (lua_Integer)cocos2d::backend::PixelFormat::ATC_INTERPOLATED_ALPHA);
    oluacls_const_integer(L, "ATC_RGB", (lua_Integer)cocos2d::backend::PixelFormat::ATC_RGB);
    oluacls_const_integer(L, "AUTO", (lua_Integer)cocos2d::backend::PixelFormat::AUTO);
    oluacls_const_integer(L, "BGRA8888", (lua_Integer)cocos2d::backend::PixelFormat::BGRA8888);
    oluacls_const_integer(L, "D24S8", (lua_Integer)cocos2d::backend::PixelFormat::D24S8);
    oluacls_const_integer(L, "DEFAULT", (lua_Integer)cocos2d::backend::PixelFormat::DEFAULT);
    oluacls_const_integer(L, "ETC", (lua_Integer)cocos2d::backend::PixelFormat::ETC);
    oluacls_const_integer(L, "I8", (lua_Integer)cocos2d::backend::PixelFormat::I8);
    oluacls_const_integer(L, "MTL_ABGR4", (lua_Integer)cocos2d::backend::PixelFormat::MTL_ABGR4);
    oluacls_const_integer(L, "MTL_B5G6R5", (lua_Integer)cocos2d::backend::PixelFormat::MTL_B5G6R5);
    oluacls_const_integer(L, "MTL_BGR5A1", (lua_Integer)cocos2d::backend::PixelFormat::MTL_BGR5A1);
    oluacls_const_integer(L, "NONE", (lua_Integer)cocos2d::backend::PixelFormat::NONE);
    oluacls_const_integer(L, "PVRTC2", (lua_Integer)cocos2d::backend::PixelFormat::PVRTC2);
    oluacls_const_integer(L, "PVRTC2A", (lua_Integer)cocos2d::backend::PixelFormat::PVRTC2A);
    oluacls_const_integer(L, "PVRTC4", (lua_Integer)cocos2d::backend::PixelFormat::PVRTC4);
    oluacls_const_integer(L, "PVRTC4A", (lua_Integer)cocos2d::backend::PixelFormat::PVRTC4A);
    oluacls_const_integer(L, "RGB565", (lua_Integer)cocos2d::backend::PixelFormat::RGB565);
    oluacls_const_integer(L, "RGB5A1", (lua_Integer)cocos2d::backend::PixelFormat::RGB5A1);
    oluacls_const_integer(L, "RGB888", (lua_Integer)cocos2d::backend::PixelFormat::RGB888);
    oluacls_const_integer(L, "RGBA4444", (lua_Integer)cocos2d::backend::PixelFormat::RGBA4444);
    oluacls_const_integer(L, "RGBA8888", (lua_Integer)cocos2d::backend::PixelFormat::RGBA8888);
    oluacls_const_integer(L, "S3TC_DXT1", (lua_Integer)cocos2d::backend::PixelFormat::S3TC_DXT1);
    oluacls_const_integer(L, "S3TC_DXT3", (lua_Integer)cocos2d::backend::PixelFormat::S3TC_DXT3);
    oluacls_const_integer(L, "S3TC_DXT5", (lua_Integer)cocos2d::backend::PixelFormat::S3TC_DXT5);

    olua_registerluatype<cocos2d::backend::PixelFormat>(L, "ccb.PixelFormat");

    return 1;
}

static int luaopen_cocos2d_backend_TextureUsage(lua_State *L)
{
    oluacls_class(L, "ccb.TextureUsage", nullptr);
    oluacls_const_integer(L, "READ", (lua_Integer)cocos2d::backend::TextureUsage::READ);
    oluacls_const_integer(L, "RENDER_TARGET", (lua_Integer)cocos2d::backend::TextureUsage::RENDER_TARGET);
    oluacls_const_integer(L, "WRITE", (lua_Integer)cocos2d::backend::TextureUsage::WRITE);

    olua_registerluatype<cocos2d::backend::TextureUsage>(L, "ccb.TextureUsage");

    return 1;
}

static int luaopen_cocos2d_backend_IndexFormat(lua_State *L)
{
    oluacls_class(L, "ccb.IndexFormat", nullptr);
    oluacls_const_integer(L, "U_INT", (lua_Integer)cocos2d::backend::IndexFormat::U_INT);
    oluacls_const_integer(L, "U_SHORT", (lua_Integer)cocos2d::backend::IndexFormat::U_SHORT);

    olua_registerluatype<cocos2d::backend::IndexFormat>(L, "ccb.IndexFormat");

    return 1;
}

static int luaopen_cocos2d_backend_VertexStepMode(lua_State *L)
{
    oluacls_class(L, "ccb.VertexStepMode", nullptr);
    oluacls_const_integer(L, "INSTANCE", (lua_Integer)cocos2d::backend::VertexStepMode::INSTANCE);
    oluacls_const_integer(L, "VERTEX", (lua_Integer)cocos2d::backend::VertexStepMode::VERTEX);

    olua_registerluatype<cocos2d::backend::VertexStepMode>(L, "ccb.VertexStepMode");

    return 1;
}

static int luaopen_cocos2d_backend_PrimitiveType(lua_State *L)
{
    oluacls_class(L, "ccb.PrimitiveType", nullptr);
    oluacls_const_integer(L, "LINE", (lua_Integer)cocos2d::backend::PrimitiveType::LINE);
    oluacls_const_integer(L, "LINE_STRIP", (lua_Integer)cocos2d::backend::PrimitiveType::LINE_STRIP);
    oluacls_const_integer(L, "POINT", (lua_Integer)cocos2d::backend::PrimitiveType::POINT);
    oluacls_const_integer(L, "TRIANGLE", (lua_Integer)cocos2d::backend::PrimitiveType::TRIANGLE);
    oluacls_const_integer(L, "TRIANGLE_STRIP", (lua_Integer)cocos2d::backend::PrimitiveType::TRIANGLE_STRIP);

    olua_registerluatype<cocos2d::backend::PrimitiveType>(L, "ccb.PrimitiveType");

    return 1;
}

static int luaopen_cocos2d_backend_TextureType(lua_State *L)
{
    oluacls_class(L, "ccb.TextureType", nullptr);
    oluacls_const_integer(L, "TEXTURE_2D", (lua_Integer)cocos2d::backend::TextureType::TEXTURE_2D);
    oluacls_const_integer(L, "TEXTURE_CUBE", (lua_Integer)cocos2d::backend::TextureType::TEXTURE_CUBE);

    olua_registerluatype<cocos2d::backend::TextureType>(L, "ccb.TextureType");

    return 1;
}

static int luaopen_cocos2d_backend_SamplerAddressMode(lua_State *L)
{
    oluacls_class(L, "ccb.SamplerAddressMode", nullptr);
    oluacls_const_integer(L, "CLAMP_TO_EDGE", (lua_Integer)cocos2d::backend::SamplerAddressMode::CLAMP_TO_EDGE);
    oluacls_const_integer(L, "DONT_CARE", (lua_Integer)cocos2d::backend::SamplerAddressMode::DONT_CARE);
    oluacls_const_integer(L, "MIRROR_REPEAT", (lua_Integer)cocos2d::backend::SamplerAddressMode::MIRROR_REPEAT);
    oluacls_const_integer(L, "REPEAT", (lua_Integer)cocos2d::backend::SamplerAddressMode::REPEAT);

    olua_registerluatype<cocos2d::backend::SamplerAddressMode>(L, "ccb.SamplerAddressMode");

    return 1;
}

static int luaopen_cocos2d_backend_SamplerFilter(lua_State *L)
{
    oluacls_class(L, "ccb.SamplerFilter", nullptr);
    oluacls_const_integer(L, "DONT_CARE", (lua_Integer)cocos2d::backend::SamplerFilter::DONT_CARE);
    oluacls_const_integer(L, "LINEAR", (lua_Integer)cocos2d::backend::SamplerFilter::LINEAR);
    oluacls_const_integer(L, "LINEAR_MIPMAP_LINEAR", (lua_Integer)cocos2d::backend::SamplerFilter::LINEAR_MIPMAP_LINEAR);
    oluacls_const_integer(L, "LINEAR_MIPMAP_NEAREST", (lua_Integer)cocos2d::backend::SamplerFilter::LINEAR_MIPMAP_NEAREST);
    oluacls_const_integer(L, "NEAREST", (lua_Integer)cocos2d::backend::SamplerFilter::NEAREST);
    oluacls_const_integer(L, "NEAREST_MIPMAP_LINEAR", (lua_Integer)cocos2d::backend::SamplerFilter::NEAREST_MIPMAP_LINEAR);
    oluacls_const_integer(L, "NEAREST_MIPMAP_NEAREST", (lua_Integer)cocos2d::backend::SamplerFilter::NEAREST_MIPMAP_NEAREST);

    olua_registerluatype<cocos2d::backend::SamplerFilter>(L, "ccb.SamplerFilter");

    return 1;
}

static int luaopen_cocos2d_backend_StencilOperation(lua_State *L)
{
    oluacls_class(L, "ccb.StencilOperation", nullptr);
    oluacls_const_integer(L, "DECREMENT_WRAP", (lua_Integer)cocos2d::backend::StencilOperation::DECREMENT_WRAP);
    oluacls_const_integer(L, "INCREMENT_WRAP", (lua_Integer)cocos2d::backend::StencilOperation::INCREMENT_WRAP);
    oluacls_const_integer(L, "INVERT", (lua_Integer)cocos2d::backend::StencilOperation::INVERT);
    oluacls_const_integer(L, "KEEP", (lua_Integer)cocos2d::backend::StencilOperation::KEEP);
    oluacls_const_integer(L, "REPLACE", (lua_Integer)cocos2d::backend::StencilOperation::REPLACE);
    oluacls_const_integer(L, "ZERO", (lua_Integer)cocos2d::backend::StencilOperation::ZERO);

    olua_registerluatype<cocos2d::backend::StencilOperation>(L, "ccb.StencilOperation");

    return 1;
}

static int luaopen_cocos2d_backend_CompareFunction(lua_State *L)
{
    oluacls_class(L, "ccb.CompareFunction", nullptr);
    oluacls_const_integer(L, "ALWAYS", (lua_Integer)cocos2d::backend::CompareFunction::ALWAYS);
    oluacls_const_integer(L, "EQUAL", (lua_Integer)cocos2d::backend::CompareFunction::EQUAL);
    oluacls_const_integer(L, "GREATER", (lua_Integer)cocos2d::backend::CompareFunction::GREATER);
    oluacls_const_integer(L, "GREATER_EQUAL", (lua_Integer)cocos2d::backend::CompareFunction::GREATER_EQUAL);
    oluacls_const_integer(L, "LESS", (lua_Integer)cocos2d::backend::CompareFunction::LESS);
    oluacls_const_integer(L, "LESS_EQUAL", (lua_Integer)cocos2d::backend::CompareFunction::LESS_EQUAL);
    oluacls_const_integer(L, "NEVER", (lua_Integer)cocos2d::backend::CompareFunction::NEVER);
    oluacls_const_integer(L, "NOT_EQUAL", (lua_Integer)cocos2d::backend::CompareFunction::NOT_EQUAL);

    olua_registerluatype<cocos2d::backend::CompareFunction>(L, "ccb.CompareFunction");

    return 1;
}

static int luaopen_cocos2d_backend_BlendOperation(lua_State *L)
{
    oluacls_class(L, "ccb.BlendOperation", nullptr);
    oluacls_const_integer(L, "ADD", (lua_Integer)cocos2d::backend::BlendOperation::ADD);
    oluacls_const_integer(L, "RESERVE_SUBTRACT", (lua_Integer)cocos2d::backend::BlendOperation::RESERVE_SUBTRACT);
    oluacls_const_integer(L, "SUBTRACT", (lua_Integer)cocos2d::backend::BlendOperation::SUBTRACT);

    olua_registerluatype<cocos2d::backend::BlendOperation>(L, "ccb.BlendOperation");

    return 1;
}

static int luaopen_cocos2d_backend_BlendFactor(lua_State *L)
{
    oluacls_class(L, "ccb.BlendFactor", nullptr);
    oluacls_const_integer(L, "BLEND_CLOLOR", (lua_Integer)cocos2d::backend::BlendFactor::BLEND_CLOLOR);
    oluacls_const_integer(L, "CONSTANT_ALPHA", (lua_Integer)cocos2d::backend::BlendFactor::CONSTANT_ALPHA);
    oluacls_const_integer(L, "DST_ALPHA", (lua_Integer)cocos2d::backend::BlendFactor::DST_ALPHA);
    oluacls_const_integer(L, "DST_COLOR", (lua_Integer)cocos2d::backend::BlendFactor::DST_COLOR);
    oluacls_const_integer(L, "ONE", (lua_Integer)cocos2d::backend::BlendFactor::ONE);
    oluacls_const_integer(L, "ONE_MINUS_CONSTANT_ALPHA", (lua_Integer)cocos2d::backend::BlendFactor::ONE_MINUS_CONSTANT_ALPHA);
    oluacls_const_integer(L, "ONE_MINUS_DST_ALPHA", (lua_Integer)cocos2d::backend::BlendFactor::ONE_MINUS_DST_ALPHA);
    oluacls_const_integer(L, "ONE_MINUS_DST_COLOR", (lua_Integer)cocos2d::backend::BlendFactor::ONE_MINUS_DST_COLOR);
    oluacls_const_integer(L, "ONE_MINUS_SRC_ALPHA", (lua_Integer)cocos2d::backend::BlendFactor::ONE_MINUS_SRC_ALPHA);
    oluacls_const_integer(L, "ONE_MINUS_SRC_COLOR", (lua_Integer)cocos2d::backend::BlendFactor::ONE_MINUS_SRC_COLOR);
    oluacls_const_integer(L, "SRC_ALPHA", (lua_Integer)cocos2d::backend::BlendFactor::SRC_ALPHA);
    oluacls_const_integer(L, "SRC_ALPHA_SATURATE", (lua_Integer)cocos2d::backend::BlendFactor::SRC_ALPHA_SATURATE);
    oluacls_const_integer(L, "SRC_COLOR", (lua_Integer)cocos2d::backend::BlendFactor::SRC_COLOR);
    oluacls_const_integer(L, "ZERO", (lua_Integer)cocos2d::backend::BlendFactor::ZERO);

    olua_registerluatype<cocos2d::backend::BlendFactor>(L, "ccb.BlendFactor");

    return 1;
}

static int luaopen_cocos2d_backend_ColorWriteMask(lua_State *L)
{
    oluacls_class(L, "ccb.ColorWriteMask", nullptr);
    oluacls_const_integer(L, "ALL", (lua_Integer)cocos2d::backend::ColorWriteMask::ALL);
    oluacls_const_integer(L, "ALPHA", (lua_Integer)cocos2d::backend::ColorWriteMask::ALPHA);
    oluacls_const_integer(L, "BLUE", (lua_Integer)cocos2d::backend::ColorWriteMask::BLUE);
    oluacls_const_integer(L, "GREEN", (lua_Integer)cocos2d::backend::ColorWriteMask::GREEN);
    oluacls_const_integer(L, "NONE", (lua_Integer)cocos2d::backend::ColorWriteMask::NONE);
    oluacls_const_integer(L, "RED", (lua_Integer)cocos2d::backend::ColorWriteMask::RED);

    olua_registerluatype<cocos2d::backend::ColorWriteMask>(L, "ccb.ColorWriteMask");

    return 1;
}

static int luaopen_cocos2d_backend_CullMode(lua_State *L)
{
    oluacls_class(L, "ccb.CullMode", nullptr);
    oluacls_const_integer(L, "BACK", (lua_Integer)cocos2d::backend::CullMode::BACK);
    oluacls_const_integer(L, "FRONT", (lua_Integer)cocos2d::backend::CullMode::FRONT);
    oluacls_const_integer(L, "NONE", (lua_Integer)cocos2d::backend::CullMode::NONE);

    olua_registerluatype<cocos2d::backend::CullMode>(L, "ccb.CullMode");

    return 1;
}

static int luaopen_cocos2d_backend_Winding(lua_State *L)
{
    oluacls_class(L, "ccb.Winding", nullptr);
    oluacls_const_integer(L, "CLOCK_WISE", (lua_Integer)cocos2d::backend::Winding::CLOCK_WISE);
    oluacls_const_integer(L, "COUNTER_CLOCK_WISE", (lua_Integer)cocos2d::backend::Winding::COUNTER_CLOCK_WISE);

    olua_registerluatype<cocos2d::backend::Winding>(L, "ccb.Winding");

    return 1;
}

static int luaopen_cocos2d_backend_TextureCubeFace(lua_State *L)
{
    oluacls_class(L, "ccb.TextureCubeFace", nullptr);
    oluacls_const_integer(L, "NEGATIVE_X", (lua_Integer)cocos2d::backend::TextureCubeFace::NEGATIVE_X);
    oluacls_const_integer(L, "NEGATIVE_Y", (lua_Integer)cocos2d::backend::TextureCubeFace::NEGATIVE_Y);
    oluacls_const_integer(L, "NEGATIVE_Z", (lua_Integer)cocos2d::backend::TextureCubeFace::NEGATIVE_Z);
    oluacls_const_integer(L, "POSITIVE_X", (lua_Integer)cocos2d::backend::TextureCubeFace::POSITIVE_X);
    oluacls_const_integer(L, "POSITIVE_Y", (lua_Integer)cocos2d::backend::TextureCubeFace::POSITIVE_Y);
    oluacls_const_integer(L, "POSITIVE_Z", (lua_Integer)cocos2d::backend::TextureCubeFace::POSITIVE_Z);

    olua_registerluatype<cocos2d::backend::TextureCubeFace>(L, "ccb.TextureCubeFace");

    return 1;
}

static int luaopen_cocos2d_backend_ProgramType(lua_State *L)
{
    oluacls_class(L, "ccb.ProgramType", nullptr);
    oluacls_const_integer(L, "CAMERA_CLEAR", (lua_Integer)cocos2d::backend::ProgramType::CAMERA_CLEAR);
    oluacls_const_integer(L, "CUSTOM_PROGRAM", (lua_Integer)cocos2d::backend::ProgramType::CUSTOM_PROGRAM);
    oluacls_const_integer(L, "ETC1", (lua_Integer)cocos2d::backend::ProgramType::ETC1);
    oluacls_const_integer(L, "ETC1_GRAY", (lua_Integer)cocos2d::backend::ProgramType::ETC1_GRAY);
    oluacls_const_integer(L, "GRAY_SCALE", (lua_Integer)cocos2d::backend::ProgramType::GRAY_SCALE);
    oluacls_const_integer(L, "LABEL_DISTANCE_NORMAL", (lua_Integer)cocos2d::backend::ProgramType::LABEL_DISTANCE_NORMAL);
    oluacls_const_integer(L, "LABEL_NORMAL", (lua_Integer)cocos2d::backend::ProgramType::LABEL_NORMAL);
    oluacls_const_integer(L, "LABLE_DISTANCEFIELD_GLOW", (lua_Integer)cocos2d::backend::ProgramType::LABLE_DISTANCEFIELD_GLOW);
    oluacls_const_integer(L, "LABLE_OUTLINE", (lua_Integer)cocos2d::backend::ProgramType::LABLE_OUTLINE);
    oluacls_const_integer(L, "LAYER_RADIA_GRADIENT", (lua_Integer)cocos2d::backend::ProgramType::LAYER_RADIA_GRADIENT);
    oluacls_const_integer(L, "LINE_COLOR_3D", (lua_Integer)cocos2d::backend::ProgramType::LINE_COLOR_3D);
    oluacls_const_integer(L, "PARTICLE_COLOR_3D", (lua_Integer)cocos2d::backend::ProgramType::PARTICLE_COLOR_3D);
    oluacls_const_integer(L, "PARTICLE_TEXTURE_3D", (lua_Integer)cocos2d::backend::ProgramType::PARTICLE_TEXTURE_3D);
    oluacls_const_integer(L, "POSITION", (lua_Integer)cocos2d::backend::ProgramType::POSITION);
    oluacls_const_integer(L, "POSITION_3D", (lua_Integer)cocos2d::backend::ProgramType::POSITION_3D);
    oluacls_const_integer(L, "POSITION_BUMPEDNORMAL_TEXTURE_3D", (lua_Integer)cocos2d::backend::ProgramType::POSITION_BUMPEDNORMAL_TEXTURE_3D);
    oluacls_const_integer(L, "POSITION_COLOR", (lua_Integer)cocos2d::backend::ProgramType::POSITION_COLOR);
    oluacls_const_integer(L, "POSITION_COLOR_LENGTH_TEXTURE", (lua_Integer)cocos2d::backend::ProgramType::POSITION_COLOR_LENGTH_TEXTURE);
    oluacls_const_integer(L, "POSITION_COLOR_TEXTURE_AS_POINTSIZE", (lua_Integer)cocos2d::backend::ProgramType::POSITION_COLOR_TEXTURE_AS_POINTSIZE);
    oluacls_const_integer(L, "POSITION_NORMAL_3D", (lua_Integer)cocos2d::backend::ProgramType::POSITION_NORMAL_3D);
    oluacls_const_integer(L, "POSITION_NORMAL_TEXTURE_3D", (lua_Integer)cocos2d::backend::ProgramType::POSITION_NORMAL_TEXTURE_3D);
    oluacls_const_integer(L, "POSITION_TEXTURE", (lua_Integer)cocos2d::backend::ProgramType::POSITION_TEXTURE);
    oluacls_const_integer(L, "POSITION_TEXTURE_3D", (lua_Integer)cocos2d::backend::ProgramType::POSITION_TEXTURE_3D);
    oluacls_const_integer(L, "POSITION_TEXTURE_COLOR", (lua_Integer)cocos2d::backend::ProgramType::POSITION_TEXTURE_COLOR);
    oluacls_const_integer(L, "POSITION_TEXTURE_COLOR_ALPHA_TEST", (lua_Integer)cocos2d::backend::ProgramType::POSITION_TEXTURE_COLOR_ALPHA_TEST);
    oluacls_const_integer(L, "POSITION_UCOLOR", (lua_Integer)cocos2d::backend::ProgramType::POSITION_UCOLOR);
    oluacls_const_integer(L, "SKINPOSITION_BUMPEDNORMAL_TEXTURE_3D", (lua_Integer)cocos2d::backend::ProgramType::SKINPOSITION_BUMPEDNORMAL_TEXTURE_3D);
    oluacls_const_integer(L, "SKINPOSITION_NORMAL_TEXTURE_3D", (lua_Integer)cocos2d::backend::ProgramType::SKINPOSITION_NORMAL_TEXTURE_3D);
    oluacls_const_integer(L, "SKINPOSITION_TEXTURE_3D", (lua_Integer)cocos2d::backend::ProgramType::SKINPOSITION_TEXTURE_3D);
    oluacls_const_integer(L, "SKYBOX_3D", (lua_Integer)cocos2d::backend::ProgramType::SKYBOX_3D);
    oluacls_const_integer(L, "TERRAIN_3D", (lua_Integer)cocos2d::backend::ProgramType::TERRAIN_3D);

    olua_registerluatype<cocos2d::backend::ProgramType>(L, "ccb.ProgramType");

    return 1;
}

static int luaopen_cocos2d_backend_Uniform(lua_State *L)
{
    oluacls_class(L, "ccb.Uniform", nullptr);
    oluacls_const_integer(L, "EFFECT_COLOR", (lua_Integer)cocos2d::backend::Uniform::EFFECT_COLOR);
    oluacls_const_integer(L, "EFFECT_TYPE", (lua_Integer)cocos2d::backend::Uniform::EFFECT_TYPE);
    oluacls_const_integer(L, "MVP_MATRIX", (lua_Integer)cocos2d::backend::Uniform::MVP_MATRIX);
    oluacls_const_integer(L, "TEXTURE", (lua_Integer)cocos2d::backend::Uniform::TEXTURE);
    oluacls_const_integer(L, "TEXTURE1", (lua_Integer)cocos2d::backend::Uniform::TEXTURE1);
    oluacls_const_integer(L, "TEXTURE2", (lua_Integer)cocos2d::backend::Uniform::TEXTURE2);
    oluacls_const_integer(L, "TEXTURE3", (lua_Integer)cocos2d::backend::Uniform::TEXTURE3);
    oluacls_const_integer(L, "TEXT_COLOR", (lua_Integer)cocos2d::backend::Uniform::TEXT_COLOR);
    oluacls_const_integer(L, "UNIFORM_MAX", (lua_Integer)cocos2d::backend::Uniform::UNIFORM_MAX);

    olua_registerluatype<cocos2d::backend::Uniform>(L, "ccb.Uniform");

    return 1;
}

static int luaopen_cocos2d_backend_Attribute(lua_State *L)
{
    oluacls_class(L, "ccb.Attribute", nullptr);
    oluacls_const_integer(L, "ATTRIBUTE_MAX", (lua_Integer)cocos2d::backend::Attribute::ATTRIBUTE_MAX);
    oluacls_const_integer(L, "COLOR", (lua_Integer)cocos2d::backend::Attribute::COLOR);
    oluacls_const_integer(L, "POSITION", (lua_Integer)cocos2d::backend::Attribute::POSITION);
    oluacls_const_integer(L, "TEXCOORD", (lua_Integer)cocos2d::backend::Attribute::TEXCOORD);
    oluacls_const_integer(L, "TEXCOORD1", (lua_Integer)cocos2d::backend::Attribute::TEXCOORD1);
    oluacls_const_integer(L, "TEXCOORD2", (lua_Integer)cocos2d::backend::Attribute::TEXCOORD2);
    oluacls_const_integer(L, "TEXCOORD3", (lua_Integer)cocos2d::backend::Attribute::TEXCOORD3);

    olua_registerluatype<cocos2d::backend::Attribute>(L, "ccb.Attribute");

    return 1;
}

static int luaopen_cocos2d_backend_FeatureType(lua_State *L)
{
    oluacls_class(L, "ccb.FeatureType", nullptr);
    oluacls_const_integer(L, "AMD_COMPRESSED_ATC", (lua_Integer)cocos2d::backend::FeatureType::AMD_COMPRESSED_ATC);
    oluacls_const_integer(L, "ASTC", (lua_Integer)cocos2d::backend::FeatureType::ASTC);
    oluacls_const_integer(L, "DEPTH24", (lua_Integer)cocos2d::backend::FeatureType::DEPTH24);
    oluacls_const_integer(L, "DISCARD_FRAMEBUFFER", (lua_Integer)cocos2d::backend::FeatureType::DISCARD_FRAMEBUFFER);
    oluacls_const_integer(L, "ETC1", (lua_Integer)cocos2d::backend::FeatureType::ETC1);
    oluacls_const_integer(L, "IMG_FORMAT_BGRA8888", (lua_Integer)cocos2d::backend::FeatureType::IMG_FORMAT_BGRA8888);
    oluacls_const_integer(L, "MAPBUFFER", (lua_Integer)cocos2d::backend::FeatureType::MAPBUFFER);
    oluacls_const_integer(L, "PACKED_DEPTH_STENCIL", (lua_Integer)cocos2d::backend::FeatureType::PACKED_DEPTH_STENCIL);
    oluacls_const_integer(L, "PVRTC", (lua_Integer)cocos2d::backend::FeatureType::PVRTC);
    oluacls_const_integer(L, "S3TC", (lua_Integer)cocos2d::backend::FeatureType::S3TC);
    oluacls_const_integer(L, "VAO", (lua_Integer)cocos2d::backend::FeatureType::VAO);

    olua_registerluatype<cocos2d::backend::FeatureType>(L, "ccb.FeatureType");

    return 1;
}

static int _cocos2d_backend_Buffer___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::backend::Buffer *)olua_toobj(L, 1, "ccb.Buffer");
    olua_push_cppobj(L, self, "ccb.Buffer");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_backend_Buffer_getSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::Buffer *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccb.Buffer");

    // std::size_t getSize()
    std::size_t ret = self->getSize();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_backend_Buffer_updateData(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::Buffer *self = nullptr;
    void *arg1 = nullptr;       /** data */
    lua_Unsigned arg2 = 0;       /** size */

    olua_to_cppobj(L, 1, (void **)&self, "ccb.Buffer");
    olua_check_obj(L, 2, (void **)&arg1, "void *");
    olua_check_uint(L, 3, &arg2);

    // void updateData(void *data, std::size_t size)
    self->updateData(arg1, (std::size_t)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_backend_Buffer_updateSubData(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::Buffer *self = nullptr;
    void *arg1 = nullptr;       /** data */
    lua_Unsigned arg2 = 0;       /** offset */
    lua_Unsigned arg3 = 0;       /** size */

    olua_to_cppobj(L, 1, (void **)&self, "ccb.Buffer");
    olua_check_obj(L, 2, (void **)&arg1, "void *");
    olua_check_uint(L, 3, &arg2);
    olua_check_uint(L, 4, &arg3);

    // void updateSubData(void *data, std::size_t offset, std::size_t size)
    self->updateSubData(arg1, (std::size_t)arg2, (std::size_t)arg3);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_backend_Buffer_usingDefaultStoredData(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::Buffer *self = nullptr;
    bool arg1 = false;       /** needDefaultStoredData */

    olua_to_cppobj(L, 1, (void **)&self, "ccb.Buffer");
    olua_check_bool(L, 2, &arg1);

    // void usingDefaultStoredData(bool needDefaultStoredData)
    self->usingDefaultStoredData(arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_backend_Buffer(lua_State *L)
{
    oluacls_class(L, "ccb.Buffer", "cc.Ref");
    oluacls_func(L, "__move", _cocos2d_backend_Buffer___move);
    oluacls_func(L, "getSize", _cocos2d_backend_Buffer_getSize);
    oluacls_func(L, "updateData", _cocos2d_backend_Buffer_updateData);
    oluacls_func(L, "updateSubData", _cocos2d_backend_Buffer_updateSubData);
    oluacls_func(L, "usingDefaultStoredData", _cocos2d_backend_Buffer_usingDefaultStoredData);
    oluacls_prop(L, "size", _cocos2d_backend_Buffer_getSize, nullptr);

    olua_registerluatype<cocos2d::backend::Buffer>(L, "ccb.Buffer");

    return 1;
}

static int _cocos2d_backend_RenderPipeline___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::backend::RenderPipeline *)olua_toobj(L, 1, "ccb.RenderPipeline");
    olua_push_cppobj(L, self, "ccb.RenderPipeline");

    olua_endinvoke(L);

    return 1;
}

static int luaopen_cocos2d_backend_RenderPipeline(lua_State *L)
{
    oluacls_class(L, "ccb.RenderPipeline", "cc.Ref");
    oluacls_func(L, "__move", _cocos2d_backend_RenderPipeline___move);

    olua_registerluatype<cocos2d::backend::RenderPipeline>(L, "ccb.RenderPipeline");

    return 1;
}

static int _cocos2d_backend_DepthStencilState___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::backend::DepthStencilState *)olua_toobj(L, 1, "ccb.DepthStencilState");
    olua_push_cppobj(L, self, "ccb.DepthStencilState");

    olua_endinvoke(L);

    return 1;
}

static int luaopen_cocos2d_backend_DepthStencilState(lua_State *L)
{
    oluacls_class(L, "ccb.DepthStencilState", "cc.Ref");
    oluacls_func(L, "__move", _cocos2d_backend_DepthStencilState___move);

    olua_registerluatype<cocos2d::backend::DepthStencilState>(L, "ccb.DepthStencilState");

    return 1;
}

static int _cocos2d_backend_VertexLayout___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::backend::VertexLayout *)olua_toobj(L, 1, "ccb.VertexLayout");
    lua_pushstring(L, ".ownership");
    olua_getvariable(L, 1);
    if (lua_toboolean(L, -1)) {
        olua_setrawobj(L, 1, nullptr);
        delete self;
    }

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_backend_VertexLayout___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::backend::VertexLayout *)olua_toobj(L, 1, "ccb.VertexLayout");
    olua_push_cppobj(L, self, "ccb.VertexLayout");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_backend_VertexLayout_getAttributes(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::VertexLayout *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccb.VertexLayout");

    // const std::unordered_map<std::string, Attribute> &getAttributes()
    const std::unordered_map<std::string, cocos2d::backend::VertexLayout::Attribute> &ret = self->getAttributes();
    int num_ret = 1;
    lua_createtable(L, 0, (int)ret.size());
    for (auto &entry : ret) {
        olua_push_std_string(L, entry.first);
        auto_olua_push_cocos2d_backend_VertexLayout_Attribute(L, &entry.second);
        lua_rawset(L, -3);
    }

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_backend_VertexLayout_getStride(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::VertexLayout *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccb.VertexLayout");

    // std::size_t getStride()
    std::size_t ret = self->getStride();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_backend_VertexLayout_getVertexStepMode(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::VertexLayout *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccb.VertexLayout");

    // cocos2d::backend::VertexStepMode getVertexStepMode()
    cocos2d::backend::VertexStepMode ret = self->getVertexStepMode();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_backend_VertexLayout_isValid(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::VertexLayout *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccb.VertexLayout");

    // bool isValid()
    bool ret = self->isValid();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_backend_VertexLayout_new(lua_State *L)
{
    olua_startinvoke(L);

    // VertexLayout()
    cocos2d::backend::VertexLayout *ret = new cocos2d::backend::VertexLayout();
    int num_ret = olua_push_cppobj(L, ret, "ccb.VertexLayout");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_backend_VertexLayout_setAttribute(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::VertexLayout *self = nullptr;
    std::string arg1;       /** name */
    lua_Unsigned arg2 = 0;       /** index */
    lua_Unsigned arg3 = 0;       /** format */
    lua_Unsigned arg4 = 0;       /** offset */
    bool arg5 = false;       /** needToBeNormallized */

    olua_to_cppobj(L, 1, (void **)&self, "ccb.VertexLayout");
    olua_check_std_string(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);
    olua_check_uint(L, 4, &arg3);
    olua_check_uint(L, 5, &arg4);
    olua_check_bool(L, 6, &arg5);

    // void setAttribute(const std::string &name, std::size_t index, cocos2d::backend::VertexFormat format, std::size_t offset, bool needToBeNormallized)
    self->setAttribute(arg1, (std::size_t)arg2, (cocos2d::backend::VertexFormat)arg3, (std::size_t)arg4, arg5);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_backend_VertexLayout_setLayout(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::VertexLayout *self = nullptr;
    lua_Unsigned arg1 = 0;       /** stride */

    olua_to_cppobj(L, 1, (void **)&self, "ccb.VertexLayout");
    olua_check_uint(L, 2, &arg1);

    // void setLayout(std::size_t stride)
    self->setLayout((std::size_t)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_backend_VertexLayout(lua_State *L)
{
    oluacls_class(L, "ccb.VertexLayout", nullptr);
    oluacls_func(L, "__gc", _cocos2d_backend_VertexLayout___gc);
    oluacls_func(L, "__move", _cocos2d_backend_VertexLayout___move);
    oluacls_func(L, "getAttributes", _cocos2d_backend_VertexLayout_getAttributes);
    oluacls_func(L, "getStride", _cocos2d_backend_VertexLayout_getStride);
    oluacls_func(L, "getVertexStepMode", _cocos2d_backend_VertexLayout_getVertexStepMode);
    oluacls_func(L, "isValid", _cocos2d_backend_VertexLayout_isValid);
    oluacls_func(L, "new", _cocos2d_backend_VertexLayout_new);
    oluacls_func(L, "setAttribute", _cocos2d_backend_VertexLayout_setAttribute);
    oluacls_func(L, "setLayout", _cocos2d_backend_VertexLayout_setLayout);
    oluacls_prop(L, "attributes", _cocos2d_backend_VertexLayout_getAttributes, nullptr);
    oluacls_prop(L, "stride", _cocos2d_backend_VertexLayout_getStride, nullptr);
    oluacls_prop(L, "valid", _cocos2d_backend_VertexLayout_isValid, nullptr);
    oluacls_prop(L, "vertexStepMode", _cocos2d_backend_VertexLayout_getVertexStepMode, nullptr);

    olua_registerluatype<cocos2d::backend::VertexLayout>(L, "ccb.VertexLayout");

    return 1;
}

static int _cocos2d_backend_CommandBuffer___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::backend::CommandBuffer *)olua_toobj(L, 1, "ccb.CommandBuffer");
    olua_push_cppobj(L, self, "ccb.CommandBuffer");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_backend_CommandBuffer_beginFrame(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::CommandBuffer *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccb.CommandBuffer");

    // void beginFrame()
    self->beginFrame();

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_backend_CommandBuffer_captureScreen(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::CommandBuffer *self = nullptr;
    std::function<void(const unsigned char *, int, int)> arg1;       /** callback */

    olua_to_cppobj(L, 1, (void **)&self, "ccb.CommandBuffer");

    void *cb_store = (void *)self;
    std::string cb_tag = "captureScreen";
    std::string cb_name = olua_setcallback(L, cb_store, cb_tag.c_str(), 2, OLUA_TAG_NEW);
    lua_Integer cb_ctx = olua_context(L);
    arg1 = [cb_store, cb_name, cb_ctx](const unsigned char *arg1, int arg2, int arg3) {
        lua_State *L = olua_mainthread(NULL);

        if (L != NULL && olua_context(L) == cb_ctx) {
            int top = lua_gettop(L);
            olua_push_string(L, (const char *)arg1);
            olua_push_int(L, (lua_Integer)arg2);
            olua_push_int(L, (lua_Integer)arg3);

            olua_callback(L, cb_store, cb_name.c_str(), 3);

            olua_removecallback(L, cb_store, cb_name.c_str(), OLUA_TAG_WHOLE);

            lua_settop(L, top);
        }
    };

    // void captureScreen(@local std::function<void (const unsigned char *, int, int)> callback)
    self->captureScreen(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_backend_CommandBuffer_drawArrays(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::CommandBuffer *self = nullptr;
    lua_Unsigned arg1 = 0;       /** primitiveType */
    lua_Unsigned arg2 = 0;       /** start */
    lua_Unsigned arg3 = 0;       /** count */

    olua_to_cppobj(L, 1, (void **)&self, "ccb.CommandBuffer");
    olua_check_uint(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);
    olua_check_uint(L, 4, &arg3);

    // void drawArrays(cocos2d::backend::PrimitiveType primitiveType, std::size_t start, std::size_t count)
    self->drawArrays((cocos2d::backend::PrimitiveType)arg1, (std::size_t)arg2, (std::size_t)arg3);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_backend_CommandBuffer_drawElements(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::CommandBuffer *self = nullptr;
    lua_Unsigned arg1 = 0;       /** primitiveType */
    lua_Unsigned arg2 = 0;       /** indexType */
    lua_Unsigned arg3 = 0;       /** count */
    lua_Unsigned arg4 = 0;       /** offset */

    olua_to_cppobj(L, 1, (void **)&self, "ccb.CommandBuffer");
    olua_check_uint(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);
    olua_check_uint(L, 4, &arg3);
    olua_check_uint(L, 5, &arg4);

    // void drawElements(cocos2d::backend::PrimitiveType primitiveType, cocos2d::backend::IndexFormat indexType, std::size_t count, std::size_t offset)
    self->drawElements((cocos2d::backend::PrimitiveType)arg1, (cocos2d::backend::IndexFormat)arg2, (std::size_t)arg3, (std::size_t)arg4);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_backend_CommandBuffer_endFrame(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::CommandBuffer *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccb.CommandBuffer");

    // void endFrame()
    self->endFrame();

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_backend_CommandBuffer_endRenderPass(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::CommandBuffer *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccb.CommandBuffer");

    // void endRenderPass()
    self->endRenderPass();

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_backend_CommandBuffer_setCullMode(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::CommandBuffer *self = nullptr;
    lua_Unsigned arg1 = 0;       /** mode */

    olua_to_cppobj(L, 1, (void **)&self, "ccb.CommandBuffer");
    olua_check_uint(L, 2, &arg1);

    // void setCullMode(cocos2d::backend::CullMode mode)
    self->setCullMode((cocos2d::backend::CullMode)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_backend_CommandBuffer_setDepthStencilState(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::CommandBuffer *self = nullptr;
    cocos2d::backend::DepthStencilState *arg1 = nullptr;       /** depthStencilState */

    olua_to_cppobj(L, 1, (void **)&self, "ccb.CommandBuffer");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccb.DepthStencilState");

    // void setDepthStencilState(cocos2d::backend::DepthStencilState *depthStencilState)
    self->setDepthStencilState(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_backend_CommandBuffer_setIndexBuffer(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::CommandBuffer *self = nullptr;
    cocos2d::backend::Buffer *arg1 = nullptr;       /** buffer */

    olua_to_cppobj(L, 1, (void **)&self, "ccb.CommandBuffer");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccb.Buffer");

    // void setIndexBuffer(cocos2d::backend::Buffer *buffer)
    self->setIndexBuffer(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_backend_CommandBuffer_setLineWidth(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::CommandBuffer *self = nullptr;
    lua_Number arg1 = 0;       /** lineWidth */

    olua_to_cppobj(L, 1, (void **)&self, "ccb.CommandBuffer");
    olua_check_number(L, 2, &arg1);

    // void setLineWidth(float lineWidth)
    self->setLineWidth((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_backend_CommandBuffer_setProgramState(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::CommandBuffer *self = nullptr;
    cocos2d::backend::ProgramState *arg1 = nullptr;       /** programState */

    olua_to_cppobj(L, 1, (void **)&self, "ccb.CommandBuffer");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccb.ProgramState");

    // void setProgramState(cocos2d::backend::ProgramState *programState)
    self->setProgramState(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_backend_CommandBuffer_setRenderPipeline(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::CommandBuffer *self = nullptr;
    cocos2d::backend::RenderPipeline *arg1 = nullptr;       /** renderPipeline */

    olua_to_cppobj(L, 1, (void **)&self, "ccb.CommandBuffer");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccb.RenderPipeline");

    // void setRenderPipeline(cocos2d::backend::RenderPipeline *renderPipeline)
    self->setRenderPipeline(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_backend_CommandBuffer_setScissorRect(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::CommandBuffer *self = nullptr;
    bool arg1 = false;       /** isEnabled */
    lua_Number arg2 = 0;       /** x */
    lua_Number arg3 = 0;       /** y */
    lua_Number arg4 = 0;       /** width */
    lua_Number arg5 = 0;       /** height */

    olua_to_cppobj(L, 1, (void **)&self, "ccb.CommandBuffer");
    olua_check_bool(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);
    olua_check_number(L, 5, &arg4);
    olua_check_number(L, 6, &arg5);

    // void setScissorRect(bool isEnabled, float x, float y, float width, float height)
    self->setScissorRect(arg1, (float)arg2, (float)arg3, (float)arg4, (float)arg5);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_backend_CommandBuffer_setStencilReferenceValue1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::CommandBuffer *self = nullptr;
    lua_Unsigned arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "ccb.CommandBuffer");
    olua_check_uint(L, 2, &arg1);

    // void setStencilReferenceValue(unsigned int value)
    self->setStencilReferenceValue((unsigned int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_backend_CommandBuffer_setStencilReferenceValue2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::CommandBuffer *self = nullptr;
    lua_Unsigned arg1 = 0;       /** frontRef */
    lua_Unsigned arg2 = 0;       /** backRef */

    olua_to_cppobj(L, 1, (void **)&self, "ccb.CommandBuffer");
    olua_check_uint(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // void setStencilReferenceValue(unsigned int frontRef, unsigned int backRef)
    self->setStencilReferenceValue((unsigned int)arg1, (unsigned int)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_backend_CommandBuffer_setStencilReferenceValue(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_uint(L, 2))) {
            // void setStencilReferenceValue(unsigned int value)
            return _cocos2d_backend_CommandBuffer_setStencilReferenceValue1(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_uint(L, 2)) && (olua_is_uint(L, 3))) {
            // void setStencilReferenceValue(unsigned int frontRef, unsigned int backRef)
            return _cocos2d_backend_CommandBuffer_setStencilReferenceValue2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::backend::CommandBuffer::setStencilReferenceValue' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_backend_CommandBuffer_setVertexBuffer(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::CommandBuffer *self = nullptr;
    cocos2d::backend::Buffer *arg1 = nullptr;       /** buffer */

    olua_to_cppobj(L, 1, (void **)&self, "ccb.CommandBuffer");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccb.Buffer");

    // void setVertexBuffer(cocos2d::backend::Buffer *buffer)
    self->setVertexBuffer(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_backend_CommandBuffer_setViewport(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::CommandBuffer *self = nullptr;
    lua_Integer arg1 = 0;       /** x */
    lua_Integer arg2 = 0;       /** y */
    lua_Unsigned arg3 = 0;       /** w */
    lua_Unsigned arg4 = 0;       /** h */

    olua_to_cppobj(L, 1, (void **)&self, "ccb.CommandBuffer");
    olua_check_int(L, 2, &arg1);
    olua_check_int(L, 3, &arg2);
    olua_check_uint(L, 4, &arg3);
    olua_check_uint(L, 5, &arg4);

    // void setViewport(int x, int y, unsigned int w, unsigned int h)
    self->setViewport((int)arg1, (int)arg2, (unsigned int)arg3, (unsigned int)arg4);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_backend_CommandBuffer_setWinding(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::CommandBuffer *self = nullptr;
    lua_Unsigned arg1 = 0;       /** winding */

    olua_to_cppobj(L, 1, (void **)&self, "ccb.CommandBuffer");
    olua_check_uint(L, 2, &arg1);

    // void setWinding(cocos2d::backend::Winding winding)
    self->setWinding((cocos2d::backend::Winding)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_backend_CommandBuffer(lua_State *L)
{
    oluacls_class(L, "ccb.CommandBuffer", "cc.Ref");
    oluacls_func(L, "__move", _cocos2d_backend_CommandBuffer___move);
    oluacls_func(L, "beginFrame", _cocos2d_backend_CommandBuffer_beginFrame);
    oluacls_func(L, "captureScreen", _cocos2d_backend_CommandBuffer_captureScreen);
    oluacls_func(L, "drawArrays", _cocos2d_backend_CommandBuffer_drawArrays);
    oluacls_func(L, "drawElements", _cocos2d_backend_CommandBuffer_drawElements);
    oluacls_func(L, "endFrame", _cocos2d_backend_CommandBuffer_endFrame);
    oluacls_func(L, "endRenderPass", _cocos2d_backend_CommandBuffer_endRenderPass);
    oluacls_func(L, "setCullMode", _cocos2d_backend_CommandBuffer_setCullMode);
    oluacls_func(L, "setDepthStencilState", _cocos2d_backend_CommandBuffer_setDepthStencilState);
    oluacls_func(L, "setIndexBuffer", _cocos2d_backend_CommandBuffer_setIndexBuffer);
    oluacls_func(L, "setLineWidth", _cocos2d_backend_CommandBuffer_setLineWidth);
    oluacls_func(L, "setProgramState", _cocos2d_backend_CommandBuffer_setProgramState);
    oluacls_func(L, "setRenderPipeline", _cocos2d_backend_CommandBuffer_setRenderPipeline);
    oluacls_func(L, "setScissorRect", _cocos2d_backend_CommandBuffer_setScissorRect);
    oluacls_func(L, "setStencilReferenceValue", _cocos2d_backend_CommandBuffer_setStencilReferenceValue);
    oluacls_func(L, "setVertexBuffer", _cocos2d_backend_CommandBuffer_setVertexBuffer);
    oluacls_func(L, "setViewport", _cocos2d_backend_CommandBuffer_setViewport);
    oluacls_func(L, "setWinding", _cocos2d_backend_CommandBuffer_setWinding);

    olua_registerluatype<cocos2d::backend::CommandBuffer>(L, "ccb.CommandBuffer");

    return 1;
}

static int _cocos2d_backend_Device___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::backend::Device *)olua_toobj(L, 1, "ccb.Device");
    olua_push_cppobj(L, self, "ccb.Device");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_backend_Device_createDepthStencilState(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::Device *self = nullptr;
    cocos2d::backend::DepthStencilDescriptor arg1;       /** descriptor */

    olua_to_cppobj(L, 1, (void **)&self, "ccb.Device");
    auto_olua_check_cocos2d_backend_DepthStencilDescriptor(L, 2, &arg1);

    // cocos2d::backend::DepthStencilState *createDepthStencilState(const cocos2d::backend::DepthStencilDescriptor &descriptor)
    cocos2d::backend::DepthStencilState *ret = self->createDepthStencilState(arg1);
    int num_ret = olua_push_cppobj(L, ret, "ccb.DepthStencilState");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_backend_Device_getDeviceInfo(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::Device *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccb.Device");

    // cocos2d::backend::DeviceInfo *getDeviceInfo()
    cocos2d::backend::DeviceInfo *ret = self->getDeviceInfo();
    int num_ret = olua_push_cppobj(L, ret, "ccb.DeviceInfo");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_backend_Device_getInstance(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::backend::Device *getInstance()
    cocos2d::backend::Device *ret = cocos2d::backend::Device::getInstance();
    int num_ret = olua_push_cppobj(L, ret, "ccb.Device");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_backend_Device_newBuffer(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::Device *self = nullptr;
    lua_Unsigned arg1 = 0;       /** size */
    lua_Unsigned arg2 = 0;       /** type */
    lua_Unsigned arg3 = 0;       /** usage */

    olua_to_cppobj(L, 1, (void **)&self, "ccb.Device");
    olua_check_uint(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);
    olua_check_uint(L, 4, &arg3);

    // cocos2d::backend::Buffer *newBuffer(size_t size, cocos2d::backend::BufferType type, cocos2d::backend::BufferUsage usage)
    cocos2d::backend::Buffer *ret = self->newBuffer((size_t)arg1, (cocos2d::backend::BufferType)arg2, (cocos2d::backend::BufferUsage)arg3);
    int num_ret = olua_push_cppobj(L, ret, "ccb.Buffer");

    // insert code after call
    ret->autorelease();

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_backend_Device_newCommandBuffer(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::Device *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccb.Device");

    // cocos2d::backend::CommandBuffer *newCommandBuffer()
    cocos2d::backend::CommandBuffer *ret = self->newCommandBuffer();
    int num_ret = olua_push_cppobj(L, ret, "ccb.CommandBuffer");

    // insert code after call
    ret->autorelease();

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_backend_Device_newProgram(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::Device *self = nullptr;
    std::string arg1;       /** vertexShader */
    std::string arg2;       /** fragmentShader */

    olua_to_cppobj(L, 1, (void **)&self, "ccb.Device");
    olua_check_std_string(L, 2, &arg1);
    olua_check_std_string(L, 3, &arg2);

    // cocos2d::backend::Program *newProgram(const std::string &vertexShader, const std::string &fragmentShader)
    cocos2d::backend::Program *ret = self->newProgram(arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "ccb.Program");

    // insert code after call
    ret->autorelease();

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_backend_Device_newRenderPipeline(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::Device *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccb.Device");

    // cocos2d::backend::RenderPipeline *newRenderPipeline()
    cocos2d::backend::RenderPipeline *ret = self->newRenderPipeline();
    int num_ret = olua_push_cppobj(L, ret, "ccb.RenderPipeline");

    // insert code after call
    ret->autorelease();

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_backend_Device_newTexture(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::Device *self = nullptr;
    cocos2d::backend::TextureDescriptor arg1;       /** descriptor */

    olua_to_cppobj(L, 1, (void **)&self, "ccb.Device");
    auto_olua_check_cocos2d_backend_TextureDescriptor(L, 2, &arg1);

    // cocos2d::backend::TextureBackend *newTexture(const cocos2d::backend::TextureDescriptor &descriptor)
    cocos2d::backend::TextureBackend *ret = self->newTexture(arg1);
    int num_ret = olua_push_cppobj(L, ret, "ccb.TextureBackend");

    // insert code after call
    ret->autorelease();

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_backend_Device_setFrameBufferOnly(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::Device *self = nullptr;
    bool arg1 = false;       /** frameBufferOnly */

    olua_to_cppobj(L, 1, (void **)&self, "ccb.Device");
    olua_check_bool(L, 2, &arg1);

    // void setFrameBufferOnly(bool frameBufferOnly)
    self->setFrameBufferOnly(arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_backend_Device(lua_State *L)
{
    oluacls_class(L, "ccb.Device", "cc.Ref");
    oluacls_func(L, "__move", _cocos2d_backend_Device___move);
    oluacls_func(L, "createDepthStencilState", _cocos2d_backend_Device_createDepthStencilState);
    oluacls_func(L, "getDeviceInfo", _cocos2d_backend_Device_getDeviceInfo);
    oluacls_func(L, "getInstance", _cocos2d_backend_Device_getInstance);
    oluacls_func(L, "newBuffer", _cocos2d_backend_Device_newBuffer);
    oluacls_func(L, "newCommandBuffer", _cocos2d_backend_Device_newCommandBuffer);
    oluacls_func(L, "newProgram", _cocos2d_backend_Device_newProgram);
    oluacls_func(L, "newRenderPipeline", _cocos2d_backend_Device_newRenderPipeline);
    oluacls_func(L, "newTexture", _cocos2d_backend_Device_newTexture);
    oluacls_func(L, "setFrameBufferOnly", _cocos2d_backend_Device_setFrameBufferOnly);
    oluacls_prop(L, "deviceInfo", _cocos2d_backend_Device_getDeviceInfo, nullptr);
    oluacls_prop(L, "instance", _cocos2d_backend_Device_getInstance, nullptr);

    olua_registerluatype<cocos2d::backend::Device>(L, "ccb.Device");

    return 1;
}

static int _cocos2d_backend_DeviceInfo___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::backend::DeviceInfo *)olua_toobj(L, 1, "ccb.DeviceInfo");
    olua_push_cppobj(L, self, "ccb.DeviceInfo");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_backend_DeviceInfo_checkForFeatureSupported(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::DeviceInfo *self = nullptr;
    lua_Unsigned arg1 = 0;       /** feature */

    olua_to_cppobj(L, 1, (void **)&self, "ccb.DeviceInfo");
    olua_check_uint(L, 2, &arg1);

    // bool checkForFeatureSupported(cocos2d::backend::FeatureType feature)
    bool ret = self->checkForFeatureSupported((cocos2d::backend::FeatureType)arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_backend_DeviceInfo_getExtension(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::DeviceInfo *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccb.DeviceInfo");

    // const char *getExtension()
    const char *ret = self->getExtension();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_backend_DeviceInfo_getMaxAttributes(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::DeviceInfo *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccb.DeviceInfo");

    // int getMaxAttributes()
    int ret = self->getMaxAttributes();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_backend_DeviceInfo_getMaxSamplesAllowed(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::DeviceInfo *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccb.DeviceInfo");

    // int getMaxSamplesAllowed()
    int ret = self->getMaxSamplesAllowed();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_backend_DeviceInfo_getMaxTextureSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::DeviceInfo *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccb.DeviceInfo");

    // int getMaxTextureSize()
    int ret = self->getMaxTextureSize();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_backend_DeviceInfo_getMaxTextureUnits(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::DeviceInfo *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccb.DeviceInfo");

    // int getMaxTextureUnits()
    int ret = self->getMaxTextureUnits();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_backend_DeviceInfo_getRenderer(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::DeviceInfo *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccb.DeviceInfo");

    // const char *getRenderer()
    const char *ret = self->getRenderer();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_backend_DeviceInfo_getVendor(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::DeviceInfo *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccb.DeviceInfo");

    // const char *getVendor()
    const char *ret = self->getVendor();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_backend_DeviceInfo_getVersion(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::DeviceInfo *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccb.DeviceInfo");

    // const char *getVersion()
    const char *ret = self->getVersion();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_backend_DeviceInfo_init(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::DeviceInfo *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccb.DeviceInfo");

    // bool init()
    bool ret = self->init();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_backend_DeviceInfo(lua_State *L)
{
    oluacls_class(L, "ccb.DeviceInfo", nullptr);
    oluacls_func(L, "__move", _cocos2d_backend_DeviceInfo___move);
    oluacls_func(L, "checkForFeatureSupported", _cocos2d_backend_DeviceInfo_checkForFeatureSupported);
    oluacls_func(L, "getExtension", _cocos2d_backend_DeviceInfo_getExtension);
    oluacls_func(L, "getMaxAttributes", _cocos2d_backend_DeviceInfo_getMaxAttributes);
    oluacls_func(L, "getMaxSamplesAllowed", _cocos2d_backend_DeviceInfo_getMaxSamplesAllowed);
    oluacls_func(L, "getMaxTextureSize", _cocos2d_backend_DeviceInfo_getMaxTextureSize);
    oluacls_func(L, "getMaxTextureUnits", _cocos2d_backend_DeviceInfo_getMaxTextureUnits);
    oluacls_func(L, "getRenderer", _cocos2d_backend_DeviceInfo_getRenderer);
    oluacls_func(L, "getVendor", _cocos2d_backend_DeviceInfo_getVendor);
    oluacls_func(L, "getVersion", _cocos2d_backend_DeviceInfo_getVersion);
    oluacls_func(L, "init", _cocos2d_backend_DeviceInfo_init);
    oluacls_prop(L, "extension", _cocos2d_backend_DeviceInfo_getExtension, nullptr);
    oluacls_prop(L, "maxAttributes", _cocos2d_backend_DeviceInfo_getMaxAttributes, nullptr);
    oluacls_prop(L, "maxSamplesAllowed", _cocos2d_backend_DeviceInfo_getMaxSamplesAllowed, nullptr);
    oluacls_prop(L, "maxTextureSize", _cocos2d_backend_DeviceInfo_getMaxTextureSize, nullptr);
    oluacls_prop(L, "maxTextureUnits", _cocos2d_backend_DeviceInfo_getMaxTextureUnits, nullptr);
    oluacls_prop(L, "renderer", _cocos2d_backend_DeviceInfo_getRenderer, nullptr);
    oluacls_prop(L, "vendor", _cocos2d_backend_DeviceInfo_getVendor, nullptr);
    oluacls_prop(L, "version", _cocos2d_backend_DeviceInfo_getVersion, nullptr);

    olua_registerluatype<cocos2d::backend::DeviceInfo>(L, "ccb.DeviceInfo");

    return 1;
}

static int _cocos2d_backend_ShaderCache___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::backend::ShaderCache *)olua_toobj(L, 1, "ccb.ShaderCache");
    olua_push_cppobj(L, self, "ccb.ShaderCache");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_backend_ShaderCache_destroyInstance(lua_State *L)
{
    olua_startinvoke(L);

    // static void destroyInstance()
    cocos2d::backend::ShaderCache::destroyInstance();

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_backend_ShaderCache_getInstance(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::backend::ShaderCache *getInstance()
    cocos2d::backend::ShaderCache *ret = cocos2d::backend::ShaderCache::getInstance();
    int num_ret = olua_push_cppobj(L, ret, "ccb.ShaderCache");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_backend_ShaderCache_newFragmentShaderModule(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** shaderSource */

    olua_check_std_string(L, 1, &arg1);

    // static cocos2d::backend::ShaderModule *newFragmentShaderModule(const std::string &shaderSource)
    cocos2d::backend::ShaderModule *ret = cocos2d::backend::ShaderCache::newFragmentShaderModule(arg1);
    int num_ret = olua_push_cppobj(L, ret, "ccb.ShaderModule");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_backend_ShaderCache_newVertexShaderModule(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** shaderSource */

    olua_check_std_string(L, 1, &arg1);

    // static cocos2d::backend::ShaderModule *newVertexShaderModule(const std::string &shaderSource)
    cocos2d::backend::ShaderModule *ret = cocos2d::backend::ShaderCache::newVertexShaderModule(arg1);
    int num_ret = olua_push_cppobj(L, ret, "ccb.ShaderModule");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_backend_ShaderCache_removeUnusedShader(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::ShaderCache *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccb.ShaderCache");

    // void removeUnusedShader()
    self->removeUnusedShader();

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_backend_ShaderCache(lua_State *L)
{
    oluacls_class(L, "ccb.ShaderCache", "cc.Ref");
    oluacls_func(L, "__move", _cocos2d_backend_ShaderCache___move);
    oluacls_func(L, "destroyInstance", _cocos2d_backend_ShaderCache_destroyInstance);
    oluacls_func(L, "getInstance", _cocos2d_backend_ShaderCache_getInstance);
    oluacls_func(L, "newFragmentShaderModule", _cocos2d_backend_ShaderCache_newFragmentShaderModule);
    oluacls_func(L, "newVertexShaderModule", _cocos2d_backend_ShaderCache_newVertexShaderModule);
    oluacls_func(L, "removeUnusedShader", _cocos2d_backend_ShaderCache_removeUnusedShader);
    oluacls_prop(L, "instance", _cocos2d_backend_ShaderCache_getInstance, nullptr);

    olua_registerluatype<cocos2d::backend::ShaderCache>(L, "ccb.ShaderCache");

    return 1;
}

static int _cocos2d_backend_ShaderModule___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::backend::ShaderModule *)olua_toobj(L, 1, "ccb.ShaderModule");
    olua_push_cppobj(L, self, "ccb.ShaderModule");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_backend_ShaderModule_getHashValue(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::ShaderModule *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccb.ShaderModule");

    // std::size_t getHashValue()
    std::size_t ret = self->getHashValue();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_backend_ShaderModule_getShaderStage(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::ShaderModule *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccb.ShaderModule");

    // cocos2d::backend::ShaderStage getShaderStage()
    cocos2d::backend::ShaderStage ret = self->getShaderStage();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_backend_ShaderModule(lua_State *L)
{
    oluacls_class(L, "ccb.ShaderModule", "cc.Ref");
    oluacls_func(L, "__move", _cocos2d_backend_ShaderModule___move);
    oluacls_func(L, "getHashValue", _cocos2d_backend_ShaderModule_getHashValue);
    oluacls_func(L, "getShaderStage", _cocos2d_backend_ShaderModule_getShaderStage);
    oluacls_prop(L, "hashValue", _cocos2d_backend_ShaderModule_getHashValue, nullptr);
    oluacls_prop(L, "shaderStage", _cocos2d_backend_ShaderModule_getShaderStage, nullptr);

    olua_registerluatype<cocos2d::backend::ShaderModule>(L, "ccb.ShaderModule");

    return 1;
}

static int _cocos2d_backend_ProgramCache___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::backend::ProgramCache *)olua_toobj(L, 1, "ccb.ProgramCache");
    olua_push_cppobj(L, self, "ccb.ProgramCache");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_backend_ProgramCache_addCustomProgram(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::ProgramCache *self = nullptr;
    std::string arg1;       /** key */
    cocos2d::backend::Program *arg2 = nullptr;       /** program */

    olua_to_cppobj(L, 1, (void **)&self, "ccb.ProgramCache");
    olua_check_std_string(L, 2, &arg1);
    olua_check_cppobj(L, 3, (void **)&arg2, "ccb.Program");

    // void addCustomProgram(const std::string &key, cocos2d::backend::Program *program)
    self->addCustomProgram(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_backend_ProgramCache_destroyInstance(lua_State *L)
{
    olua_startinvoke(L);

    // static void destroyInstance()
    cocos2d::backend::ProgramCache::destroyInstance();

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_backend_ProgramCache_getBuiltinProgram(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::ProgramCache *self = nullptr;
    lua_Unsigned arg1 = 0;       /** type */

    olua_to_cppobj(L, 1, (void **)&self, "ccb.ProgramCache");
    olua_check_uint(L, 2, &arg1);

    // cocos2d::backend::Program *getBuiltinProgram(cocos2d::backend::ProgramType type)
    cocos2d::backend::Program *ret = self->getBuiltinProgram((cocos2d::backend::ProgramType)arg1);
    int num_ret = olua_push_cppobj(L, ret, "ccb.Program");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_backend_ProgramCache_getCustomProgram(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::ProgramCache *self = nullptr;
    std::string arg1;       /** key */

    olua_to_cppobj(L, 1, (void **)&self, "ccb.ProgramCache");
    olua_check_std_string(L, 2, &arg1);

    // cocos2d::backend::Program *getCustomProgram(const std::string &key)
    cocos2d::backend::Program *ret = self->getCustomProgram(arg1);
    int num_ret = olua_push_cppobj(L, ret, "ccb.Program");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_backend_ProgramCache_getInstance(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::backend::ProgramCache *getInstance()
    cocos2d::backend::ProgramCache *ret = cocos2d::backend::ProgramCache::getInstance();
    int num_ret = olua_push_cppobj(L, ret, "ccb.ProgramCache");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_backend_ProgramCache_removeAllPrograms(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::ProgramCache *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccb.ProgramCache");

    // void removeAllPrograms()
    self->removeAllPrograms();

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_backend_ProgramCache_removeProgram(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::ProgramCache *self = nullptr;
    cocos2d::backend::Program *arg1 = nullptr;       /** program */

    olua_to_cppobj(L, 1, (void **)&self, "ccb.ProgramCache");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccb.Program");

    // void removeProgram(cocos2d::backend::Program *program)
    self->removeProgram(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_backend_ProgramCache_removeUnusedProgram(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::ProgramCache *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccb.ProgramCache");

    // void removeUnusedProgram()
    self->removeUnusedProgram();

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_backend_ProgramCache(lua_State *L)
{
    oluacls_class(L, "ccb.ProgramCache", "cc.Ref");
    oluacls_func(L, "__move", _cocos2d_backend_ProgramCache___move);
    oluacls_func(L, "addCustomProgram", _cocos2d_backend_ProgramCache_addCustomProgram);
    oluacls_func(L, "destroyInstance", _cocos2d_backend_ProgramCache_destroyInstance);
    oluacls_func(L, "getBuiltinProgram", _cocos2d_backend_ProgramCache_getBuiltinProgram);
    oluacls_func(L, "getCustomProgram", _cocos2d_backend_ProgramCache_getCustomProgram);
    oluacls_func(L, "getInstance", _cocos2d_backend_ProgramCache_getInstance);
    oluacls_func(L, "removeAllPrograms", _cocos2d_backend_ProgramCache_removeAllPrograms);
    oluacls_func(L, "removeProgram", _cocos2d_backend_ProgramCache_removeProgram);
    oluacls_func(L, "removeUnusedProgram", _cocos2d_backend_ProgramCache_removeUnusedProgram);
    oluacls_prop(L, "instance", _cocos2d_backend_ProgramCache_getInstance, nullptr);

    olua_registerluatype<cocos2d::backend::ProgramCache>(L, "ccb.ProgramCache");

    return 1;
}

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

template <typename T> int _cocos2d_backend_ProgramState_setUniformv(lua_State *L)
{
    cocos2d::backend::UniformLocation location;
    auto self = olua_toobj<cocos2d::backend::ProgramState>(L, 1);
    if (olua_isstring(L, 2)) {
        location = self->getUniformLocation(olua_checkstring(L, 2));
    } else {
        manual_olua_check_cocos2d_backend_UniformLocation(L, 2, &location);
    }
    luaL_checktype(L, 3, LUA_TTABLE);
    int len = (int)lua_rawlen(L, 3);
    T *value = new T[len]();
    for (int i = 0; i < len; i++) {
        lua_rawgeti(L, 3, i + 1);
        T v;
        olua_check_value(L, -1, &v);
        lua_pop(L, 1);
        value[i] = v;
    }
    self->setUniform(location, value, sizeof(T) * len);
    delete []value;
    return 0;
}

static int _cocos2d_backend_ProgramState___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::backend::ProgramState *)olua_toobj(L, 1, "ccb.ProgramState");
    olua_push_cppobj(L, self, "ccb.ProgramState");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_backend_ProgramState_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::ProgramState *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccb.ProgramState");

    // cocos2d::backend::ProgramState *clone()
    cocos2d::backend::ProgramState *ret = self->clone();
    int num_ret = olua_push_cppobj(L, ret, "ccb.ProgramState");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_backend_ProgramState_getAttributeLocation1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::ProgramState *self = nullptr;
    std::string arg1;       /** name */

    olua_to_cppobj(L, 1, (void **)&self, "ccb.ProgramState");
    olua_check_std_string(L, 2, &arg1);

    // int getAttributeLocation(const std::string &name)
    int ret = self->getAttributeLocation(arg1);
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_backend_ProgramState_getAttributeLocation2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::ProgramState *self = nullptr;
    lua_Unsigned arg1 = 0;       /** name */

    olua_to_cppobj(L, 1, (void **)&self, "ccb.ProgramState");
    olua_check_uint(L, 2, &arg1);

    // int getAttributeLocation(cocos2d::backend::Attribute name)
    int ret = self->getAttributeLocation((cocos2d::backend::Attribute)arg1);
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_backend_ProgramState_getAttributeLocation(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        if ((olua_is_std_string(L, 2))) {
            // int getAttributeLocation(const std::string &name)
            return _cocos2d_backend_ProgramState_getAttributeLocation1(L);
        }

        // if ((olua_is_uint(L, 2))) {
            // int getAttributeLocation(cocos2d::backend::Attribute name)
            return _cocos2d_backend_ProgramState_getAttributeLocation2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::backend::ProgramState::getAttributeLocation' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_backend_ProgramState_getFragmentTextureInfos(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::ProgramState *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccb.ProgramState");

    // const std::unordered_map<int, TextureInfo> &getFragmentTextureInfos()
    const std::unordered_map<int, cocos2d::backend::TextureInfo> &ret = self->getFragmentTextureInfos();
    int num_ret = 1;
    lua_createtable(L, 0, (int)ret.size());
    for (auto &entry : ret) {
        olua_push_int(L, (lua_Integer)entry.first);
        auto_olua_push_cocos2d_backend_TextureInfo(L, &entry.second);
        lua_rawset(L, -3);
    }

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_backend_ProgramState_getProgram(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::ProgramState *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccb.ProgramState");

    // cocos2d::backend::Program *getProgram()
    cocos2d::backend::Program *ret = self->getProgram();
    int num_ret = olua_push_cppobj(L, ret, "ccb.Program");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_backend_ProgramState_getUniformLocation1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::ProgramState *self = nullptr;
    std::string arg1;       /** uniform */

    olua_to_cppobj(L, 1, (void **)&self, "ccb.ProgramState");
    olua_check_std_string(L, 2, &arg1);

    // cocos2d::backend::UniformLocation getUniformLocation(const std::string &uniform)
    cocos2d::backend::UniformLocation ret = self->getUniformLocation(arg1);
    int num_ret = manual_olua_push_cocos2d_backend_UniformLocation(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_backend_ProgramState_getUniformLocation2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::ProgramState *self = nullptr;
    lua_Unsigned arg1 = 0;       /** name */

    olua_to_cppobj(L, 1, (void **)&self, "ccb.ProgramState");
    olua_check_uint(L, 2, &arg1);

    // cocos2d::backend::UniformLocation getUniformLocation(cocos2d::backend::Uniform name)
    cocos2d::backend::UniformLocation ret = self->getUniformLocation((cocos2d::backend::Uniform)arg1);
    int num_ret = manual_olua_push_cocos2d_backend_UniformLocation(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_backend_ProgramState_getUniformLocation(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        if ((olua_is_std_string(L, 2))) {
            // cocos2d::backend::UniformLocation getUniformLocation(const std::string &uniform)
            return _cocos2d_backend_ProgramState_getUniformLocation1(L);
        }

        // if ((olua_is_uint(L, 2))) {
            // cocos2d::backend::UniformLocation getUniformLocation(cocos2d::backend::Uniform name)
            return _cocos2d_backend_ProgramState_getUniformLocation2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::backend::ProgramState::getUniformLocation' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_backend_ProgramState_getVertexLayout(lua_State *L)
{
    olua_startinvoke(L);

    auto self = olua_toobj<cocos2d::backend::ProgramState>(L, 1);
    olua_push_cppobj<cocos2d::backend::VertexLayout>(L, self->getVertexLayout().get());
    olua_addref(L, 1, "vertexLayout", -1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_backend_ProgramState_getVertexTextureInfos(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::ProgramState *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccb.ProgramState");

    // const std::unordered_map<int, TextureInfo> &getVertexTextureInfos()
    const std::unordered_map<int, cocos2d::backend::TextureInfo> &ret = self->getVertexTextureInfos();
    int num_ret = 1;
    lua_createtable(L, 0, (int)ret.size());
    for (auto &entry : ret) {
        olua_push_int(L, (lua_Integer)entry.first);
        auto_olua_push_cocos2d_backend_TextureInfo(L, &entry.second);
        lua_rawset(L, -3);
    }

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_backend_ProgramState_new(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::Program *arg1 = nullptr;       /** program */

    olua_check_cppobj(L, 1, (void **)&arg1, "ccb.Program");

    // ProgramState(cocos2d::backend::Program *program)
    cocos2d::backend::ProgramState *ret = new cocos2d::backend::ProgramState(arg1);
    int num_ret = olua_push_cppobj(L, ret, "ccb.ProgramState");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_backend_ProgramState_setParameterAutoBinding(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::ProgramState *self = nullptr;
    std::string arg1;       /** uniformName */
    std::string arg2;       /** autoBinding */

    olua_to_cppobj(L, 1, (void **)&self, "ccb.ProgramState");
    olua_check_std_string(L, 2, &arg1);
    olua_check_std_string(L, 3, &arg2);

    // void setParameterAutoBinding(const std::string &uniformName, const std::string &autoBinding)
    self->setParameterAutoBinding(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_backend_ProgramState_setTexture(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::ProgramState *self = nullptr;
    cocos2d::backend::UniformLocation arg1;       /** uniformLocation */
    lua_Unsigned arg2 = 0;       /** slot */
    cocos2d::backend::TextureBackend *arg3 = nullptr;       /** texture */

    olua_to_cppobj(L, 1, (void **)&self, "ccb.ProgramState");
    manual_olua_check_cocos2d_backend_UniformLocation(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);
    olua_check_cppobj(L, 4, (void **)&arg3, "ccb.TextureBackend");

    // void setTexture(const cocos2d::backend::UniformLocation &uniformLocation, uint32_t slot, cocos2d::backend::TextureBackend *texture)
    self->setTexture(arg1, (uint32_t)arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_backend_ProgramState_setTextureArray(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::ProgramState *self = nullptr;
    cocos2d::backend::UniformLocation arg1;       /** uniformLocation */
    std::vector<uint32_t> arg2;       /** slots */
    std::vector<cocos2d::backend::TextureBackend *> arg3;       /** textures */

    olua_to_cppobj(L, 1, (void **)&self, "ccb.ProgramState");
    manual_olua_check_cocos2d_backend_UniformLocation(L, 2, &arg1);
    luaL_checktype(L, 3, LUA_TTABLE);
    int arg2_total = (int)lua_rawlen(L, 3);
    arg2.reserve((size_t)arg2_total);
    for (int i = 1; i <= arg2_total; i++) {
        lua_Unsigned obj;
        lua_rawgeti(L, 3, i);
        olua_check_uint(L, -1, &obj);
        arg2.push_back((uint32_t)obj);
        lua_pop(L, 1);
    }
    olua_check_std_vector(L, 4, arg3, "ccb.TextureBackend");

    // void setTextureArray(const cocos2d::backend::UniformLocation &uniformLocation, const std::vector<uint32_t> &slots, const std::vector<backend::TextureBackend *> textures)
    self->setTextureArray(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_backend_ProgramState_setUniform(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::ProgramState *self = nullptr;
    cocos2d::backend::UniformLocation arg1;       /** uniformLocation */
    void *arg2 = nullptr;       /** data */
    lua_Unsigned arg3 = 0;       /** size */

    olua_to_cppobj(L, 1, (void **)&self, "ccb.ProgramState");
    manual_olua_check_cocos2d_backend_UniformLocation(L, 2, &arg1);
    olua_check_obj(L, 3, (void **)&arg2, "void *");
    olua_check_uint(L, 4, &arg3);

    // void setUniform(const cocos2d::backend::UniformLocation &uniformLocation, const void *data, std::size_t size)
    self->setUniform(arg1, arg2, (std::size_t)arg3);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_backend_ProgramState_setUniformFloat(lua_State *L)
{
    olua_startinvoke(L);

    _cocos2d_backend_ProgramState_setUniform<float>(L);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_backend_ProgramState_setUniformFloatv(lua_State *L)
{
    olua_startinvoke(L);

    _cocos2d_backend_ProgramState_setUniformv<float>(L);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_backend_ProgramState_setUniformInt(lua_State *L)
{
    olua_startinvoke(L);

    _cocos2d_backend_ProgramState_setUniform<int>(L);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_backend_ProgramState_setUniformIntv(lua_State *L)
{
    olua_startinvoke(L);

    _cocos2d_backend_ProgramState_setUniformv<int>(L);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_backend_ProgramState_setUniformMat4(lua_State *L)
{
    olua_startinvoke(L);

    _cocos2d_backend_ProgramState_setUniform<cocos2d::Mat4>(L);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_backend_ProgramState_setUniformMat4v(lua_State *L)
{
    olua_startinvoke(L);

    _cocos2d_backend_ProgramState_setUniformv<cocos2d::Mat4>(L);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_backend_ProgramState_setUniformVec2(lua_State *L)
{
    olua_startinvoke(L);

    _cocos2d_backend_ProgramState_setUniform<cocos2d::Vec2>(L);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_backend_ProgramState_setUniformVec2v(lua_State *L)
{
    olua_startinvoke(L);

    _cocos2d_backend_ProgramState_setUniformv<cocos2d::Vec2>(L);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_backend_ProgramState_setUniformVec3(lua_State *L)
{
    olua_startinvoke(L);

    _cocos2d_backend_ProgramState_setUniform<cocos2d::Vec3>(L);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_backend_ProgramState_setUniformVec3v(lua_State *L)
{
    olua_startinvoke(L);

    _cocos2d_backend_ProgramState_setUniformv<cocos2d::Vec3>(L);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_backend_ProgramState_setUniformVec4(lua_State *L)
{
    olua_startinvoke(L);

    _cocos2d_backend_ProgramState_setUniform<cocos2d::Vec4>(L);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_backend_ProgramState_setUniformVec4v(lua_State *L)
{
    olua_startinvoke(L);

    _cocos2d_backend_ProgramState_setUniformv<cocos2d::Vec4>(L);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_backend_ProgramState(lua_State *L)
{
    oluacls_class(L, "ccb.ProgramState", "cc.Ref");
    oluacls_func(L, "__move", _cocos2d_backend_ProgramState___move);
    oluacls_func(L, "clone", _cocos2d_backend_ProgramState_clone);
    oluacls_func(L, "getAttributeLocation", _cocos2d_backend_ProgramState_getAttributeLocation);
    oluacls_func(L, "getFragmentTextureInfos", _cocos2d_backend_ProgramState_getFragmentTextureInfos);
    oluacls_func(L, "getProgram", _cocos2d_backend_ProgramState_getProgram);
    oluacls_func(L, "getUniformLocation", _cocos2d_backend_ProgramState_getUniformLocation);
    oluacls_func(L, "getVertexLayout", _cocos2d_backend_ProgramState_getVertexLayout);
    oluacls_func(L, "getVertexTextureInfos", _cocos2d_backend_ProgramState_getVertexTextureInfos);
    oluacls_func(L, "new", _cocos2d_backend_ProgramState_new);
    oluacls_func(L, "setParameterAutoBinding", _cocos2d_backend_ProgramState_setParameterAutoBinding);
    oluacls_func(L, "setTexture", _cocos2d_backend_ProgramState_setTexture);
    oluacls_func(L, "setTextureArray", _cocos2d_backend_ProgramState_setTextureArray);
    oluacls_func(L, "setUniform", _cocos2d_backend_ProgramState_setUniform);
    oluacls_func(L, "setUniformFloat", _cocos2d_backend_ProgramState_setUniformFloat);
    oluacls_func(L, "setUniformFloatv", _cocos2d_backend_ProgramState_setUniformFloatv);
    oluacls_func(L, "setUniformInt", _cocos2d_backend_ProgramState_setUniformInt);
    oluacls_func(L, "setUniformIntv", _cocos2d_backend_ProgramState_setUniformIntv);
    oluacls_func(L, "setUniformMat4", _cocos2d_backend_ProgramState_setUniformMat4);
    oluacls_func(L, "setUniformMat4v", _cocos2d_backend_ProgramState_setUniformMat4v);
    oluacls_func(L, "setUniformVec2", _cocos2d_backend_ProgramState_setUniformVec2);
    oluacls_func(L, "setUniformVec2v", _cocos2d_backend_ProgramState_setUniformVec2v);
    oluacls_func(L, "setUniformVec3", _cocos2d_backend_ProgramState_setUniformVec3);
    oluacls_func(L, "setUniformVec3v", _cocos2d_backend_ProgramState_setUniformVec3v);
    oluacls_func(L, "setUniformVec4", _cocos2d_backend_ProgramState_setUniformVec4);
    oluacls_func(L, "setUniformVec4v", _cocos2d_backend_ProgramState_setUniformVec4v);
    oluacls_prop(L, "fragmentTextureInfos", _cocos2d_backend_ProgramState_getFragmentTextureInfos, nullptr);
    oluacls_prop(L, "program", _cocos2d_backend_ProgramState_getProgram, nullptr);
    oluacls_prop(L, "vertexTextureInfos", _cocos2d_backend_ProgramState_getVertexTextureInfos, nullptr);

    olua_registerluatype<cocos2d::backend::ProgramState>(L, "ccb.ProgramState");

    return 1;
}

static int _cocos2d_backend_Program___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::backend::Program *)olua_toobj(L, 1, "ccb.Program");
    olua_push_cppobj(L, self, "ccb.Program");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_backend_Program_getActiveAttributes(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::Program *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccb.Program");

    // const std::unordered_map<std::string, AttributeBindInfo> getActiveAttributes()
    const std::unordered_map<std::string, cocos2d::backend::AttributeBindInfo> ret = self->getActiveAttributes();
    int num_ret = 1;
    lua_createtable(L, 0, (int)ret.size());
    for (auto &entry : ret) {
        olua_push_std_string(L, entry.first);
        auto_olua_push_cocos2d_backend_AttributeBindInfo(L, &entry.second);
        lua_rawset(L, -3);
    }

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_backend_Program_getActiveUniformInfo(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::Program *self = nullptr;
    lua_Unsigned arg1 = 0;       /** stage */
    lua_Integer arg2 = 0;       /** location */

    olua_to_cppobj(L, 1, (void **)&self, "ccb.Program");
    olua_check_uint(L, 2, &arg1);
    olua_check_int(L, 3, &arg2);

    // const cocos2d::backend::UniformInfo &getActiveUniformInfo(cocos2d::backend::ShaderStage stage, int location)
    const cocos2d::backend::UniformInfo &ret = self->getActiveUniformInfo((cocos2d::backend::ShaderStage)arg1, (int)arg2);
    int num_ret = auto_olua_push_cocos2d_backend_UniformInfo(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_backend_Program_getAllActiveUniformInfo(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::Program *self = nullptr;
    lua_Unsigned arg1 = 0;       /** stage */

    olua_to_cppobj(L, 1, (void **)&self, "ccb.Program");
    olua_check_uint(L, 2, &arg1);

    // const std::unordered_map<std::string, UniformInfo> &getAllActiveUniformInfo(cocos2d::backend::ShaderStage stage)
    const std::unordered_map<std::string, cocos2d::backend::UniformInfo> &ret = self->getAllActiveUniformInfo((cocos2d::backend::ShaderStage)arg1);
    int num_ret = 1;
    lua_createtable(L, 0, (int)ret.size());
    for (auto &entry : ret) {
        olua_push_std_string(L, entry.first);
        auto_olua_push_cocos2d_backend_UniformInfo(L, &entry.second);
        lua_rawset(L, -3);
    }

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_backend_Program_getAttributeLocation1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::Program *self = nullptr;
    std::string arg1;       /** name */

    olua_to_cppobj(L, 1, (void **)&self, "ccb.Program");
    olua_check_std_string(L, 2, &arg1);

    // int getAttributeLocation(const std::string &name)
    int ret = self->getAttributeLocation(arg1);
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_backend_Program_getAttributeLocation2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::Program *self = nullptr;
    lua_Unsigned arg1 = 0;       /** name */

    olua_to_cppobj(L, 1, (void **)&self, "ccb.Program");
    olua_check_uint(L, 2, &arg1);

    // int getAttributeLocation(cocos2d::backend::Attribute name)
    int ret = self->getAttributeLocation((cocos2d::backend::Attribute)arg1);
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_backend_Program_getAttributeLocation(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        if ((olua_is_std_string(L, 2))) {
            // int getAttributeLocation(const std::string &name)
            return _cocos2d_backend_Program_getAttributeLocation1(L);
        }

        // if ((olua_is_uint(L, 2))) {
            // int getAttributeLocation(cocos2d::backend::Attribute name)
            return _cocos2d_backend_Program_getAttributeLocation2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::backend::Program::getAttributeLocation' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_backend_Program_getBuiltinProgram(lua_State *L)
{
    olua_startinvoke(L);

    lua_Unsigned arg1 = 0;       /** type */

    olua_check_uint(L, 1, &arg1);

    // static cocos2d::backend::Program *getBuiltinProgram(cocos2d::backend::ProgramType type)
    cocos2d::backend::Program *ret = cocos2d::backend::Program::getBuiltinProgram((cocos2d::backend::ProgramType)arg1);
    int num_ret = olua_push_cppobj(L, ret, "ccb.Program");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_backend_Program_getFragmentShader(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::Program *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccb.Program");

    // const std::string &getFragmentShader()
    const std::string &ret = self->getFragmentShader();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_backend_Program_getMaxFragmentLocation(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::Program *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccb.Program");

    // int getMaxFragmentLocation()
    int ret = self->getMaxFragmentLocation();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_backend_Program_getMaxVertexLocation(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::Program *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccb.Program");

    // int getMaxVertexLocation()
    int ret = self->getMaxVertexLocation();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_backend_Program_getProgramType(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::Program *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccb.Program");

    // cocos2d::backend::ProgramType getProgramType()
    cocos2d::backend::ProgramType ret = self->getProgramType();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_backend_Program_getUniformBufferSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::Program *self = nullptr;
    lua_Unsigned arg1 = 0;       /** stage */

    olua_to_cppobj(L, 1, (void **)&self, "ccb.Program");
    olua_check_uint(L, 2, &arg1);

    // std::size_t getUniformBufferSize(cocos2d::backend::ShaderStage stage)
    std::size_t ret = self->getUniformBufferSize((cocos2d::backend::ShaderStage)arg1);
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_backend_Program_getUniformLocation1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::Program *self = nullptr;
    std::string arg1;       /** uniform */

    olua_to_cppobj(L, 1, (void **)&self, "ccb.Program");
    olua_check_std_string(L, 2, &arg1);

    // cocos2d::backend::UniformLocation getUniformLocation(const std::string &uniform)
    cocos2d::backend::UniformLocation ret = self->getUniformLocation(arg1);
    int num_ret = manual_olua_push_cocos2d_backend_UniformLocation(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_backend_Program_getUniformLocation2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::Program *self = nullptr;
    lua_Unsigned arg1 = 0;       /** name */

    olua_to_cppobj(L, 1, (void **)&self, "ccb.Program");
    olua_check_uint(L, 2, &arg1);

    // cocos2d::backend::UniformLocation getUniformLocation(cocos2d::backend::Uniform name)
    cocos2d::backend::UniformLocation ret = self->getUniformLocation((cocos2d::backend::Uniform)arg1);
    int num_ret = manual_olua_push_cocos2d_backend_UniformLocation(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_backend_Program_getUniformLocation(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        if ((olua_is_std_string(L, 2))) {
            // cocos2d::backend::UniformLocation getUniformLocation(const std::string &uniform)
            return _cocos2d_backend_Program_getUniformLocation1(L);
        }

        // if ((olua_is_uint(L, 2))) {
            // cocos2d::backend::UniformLocation getUniformLocation(cocos2d::backend::Uniform name)
            return _cocos2d_backend_Program_getUniformLocation2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::backend::Program::getUniformLocation' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_backend_Program_getVertexShader(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::Program *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccb.Program");

    // const std::string &getVertexShader()
    const std::string &ret = self->getVertexShader();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_backend_Program(lua_State *L)
{
    oluacls_class(L, "ccb.Program", "cc.Ref");
    oluacls_func(L, "__move", _cocos2d_backend_Program___move);
    oluacls_func(L, "getActiveAttributes", _cocos2d_backend_Program_getActiveAttributes);
    oluacls_func(L, "getActiveUniformInfo", _cocos2d_backend_Program_getActiveUniformInfo);
    oluacls_func(L, "getAllActiveUniformInfo", _cocos2d_backend_Program_getAllActiveUniformInfo);
    oluacls_func(L, "getAttributeLocation", _cocos2d_backend_Program_getAttributeLocation);
    oluacls_func(L, "getBuiltinProgram", _cocos2d_backend_Program_getBuiltinProgram);
    oluacls_func(L, "getFragmentShader", _cocos2d_backend_Program_getFragmentShader);
    oluacls_func(L, "getMaxFragmentLocation", _cocos2d_backend_Program_getMaxFragmentLocation);
    oluacls_func(L, "getMaxVertexLocation", _cocos2d_backend_Program_getMaxVertexLocation);
    oluacls_func(L, "getProgramType", _cocos2d_backend_Program_getProgramType);
    oluacls_func(L, "getUniformBufferSize", _cocos2d_backend_Program_getUniformBufferSize);
    oluacls_func(L, "getUniformLocation", _cocos2d_backend_Program_getUniformLocation);
    oluacls_func(L, "getVertexShader", _cocos2d_backend_Program_getVertexShader);
    oluacls_prop(L, "activeAttributes", _cocos2d_backend_Program_getActiveAttributes, nullptr);
    oluacls_prop(L, "fragmentShader", _cocos2d_backend_Program_getFragmentShader, nullptr);
    oluacls_prop(L, "maxFragmentLocation", _cocos2d_backend_Program_getMaxFragmentLocation, nullptr);
    oluacls_prop(L, "maxVertexLocation", _cocos2d_backend_Program_getMaxVertexLocation, nullptr);
    oluacls_prop(L, "programType", _cocos2d_backend_Program_getProgramType, nullptr);
    oluacls_prop(L, "vertexShader", _cocos2d_backend_Program_getVertexShader, nullptr);

    olua_registerluatype<cocos2d::backend::Program>(L, "ccb.Program");

    return 1;
}

static int _cocos2d_backend_TextureBackend___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::backend::TextureBackend *)olua_toobj(L, 1, "ccb.TextureBackend");
    olua_push_cppobj(L, self, "ccb.TextureBackend");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_backend_TextureBackend_generateMipmaps(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::TextureBackend *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccb.TextureBackend");

    // void generateMipmaps()
    self->generateMipmaps();

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_backend_TextureBackend_getBytes(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::TextureBackend *self = nullptr;
    lua_Unsigned arg1 = 0;       /** x */
    lua_Unsigned arg2 = 0;       /** y */
    lua_Unsigned arg3 = 0;       /** width */
    lua_Unsigned arg4 = 0;       /** height */
    bool arg5 = false;       /** flipImage */
    std::function<void(const unsigned char *, std::size_t, std::size_t)> arg6;       /** callback */

    olua_to_cppobj(L, 1, (void **)&self, "ccb.TextureBackend");
    olua_check_uint(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);
    olua_check_uint(L, 4, &arg3);
    olua_check_uint(L, 5, &arg4);
    olua_check_bool(L, 6, &arg5);

    void *cb_store = (void *)self;
    std::string cb_tag = "Bytes";
    std::string cb_name = olua_setcallback(L, cb_store, cb_tag.c_str(), 7, OLUA_TAG_NEW);
    lua_Integer cb_ctx = olua_context(L);
    arg6 = [cb_store, cb_name, cb_ctx](const unsigned char *arg1, std::size_t arg2, std::size_t arg3) {
        lua_State *L = olua_mainthread(NULL);

        if (L != NULL && olua_context(L) == cb_ctx) {
            int top = lua_gettop(L);
            olua_push_string(L, (const char *)arg1);
            olua_push_uint(L, (lua_Unsigned)arg2);
            olua_push_uint(L, (lua_Unsigned)arg3);

            olua_callback(L, cb_store, cb_name.c_str(), 3);

            olua_removecallback(L, cb_store, cb_name.c_str(), OLUA_TAG_WHOLE);

            lua_settop(L, top);
        }
    };

    // void getBytes(std::size_t x, std::size_t y, std::size_t width, std::size_t height, bool flipImage, @local std::function<void (const unsigned char *, std::size_t, std::size_t)> callback)
    self->getBytes((std::size_t)arg1, (std::size_t)arg2, (std::size_t)arg3, (std::size_t)arg4, arg5, arg6);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_backend_TextureBackend_getTextureFormat(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::TextureBackend *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccb.TextureBackend");

    // cocos2d::backend::PixelFormat getTextureFormat()
    cocos2d::backend::PixelFormat ret = self->getTextureFormat();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_backend_TextureBackend_getTextureType(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::TextureBackend *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccb.TextureBackend");

    // cocos2d::backend::TextureType getTextureType()
    cocos2d::backend::TextureType ret = self->getTextureType();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_backend_TextureBackend_getTextureUsage(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::TextureBackend *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccb.TextureBackend");

    // cocos2d::backend::TextureUsage getTextureUsage()
    cocos2d::backend::TextureUsage ret = self->getTextureUsage();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_backend_TextureBackend_hasMipmaps(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::TextureBackend *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccb.TextureBackend");

    // bool hasMipmaps()
    bool ret = self->hasMipmaps();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_backend_TextureBackend_updateSamplerDescriptor(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::TextureBackend *self = nullptr;
    cocos2d::backend::SamplerDescriptor arg1;       /** sampler */

    olua_to_cppobj(L, 1, (void **)&self, "ccb.TextureBackend");
    auto_olua_check_cocos2d_backend_SamplerDescriptor(L, 2, &arg1);

    // void updateSamplerDescriptor(const cocos2d::backend::SamplerDescriptor &sampler)
    self->updateSamplerDescriptor(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_backend_TextureBackend_updateTextureDescriptor(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::TextureBackend *self = nullptr;
    cocos2d::backend::TextureDescriptor arg1;       /** descriptor */

    olua_to_cppobj(L, 1, (void **)&self, "ccb.TextureBackend");
    auto_olua_check_cocos2d_backend_TextureDescriptor(L, 2, &arg1);

    // void updateTextureDescriptor(const cocos2d::backend::TextureDescriptor &descriptor)
    self->updateTextureDescriptor(arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_backend_TextureBackend(lua_State *L)
{
    oluacls_class(L, "ccb.TextureBackend", "cc.Ref");
    oluacls_func(L, "__move", _cocos2d_backend_TextureBackend___move);
    oluacls_func(L, "generateMipmaps", _cocos2d_backend_TextureBackend_generateMipmaps);
    oluacls_func(L, "getBytes", _cocos2d_backend_TextureBackend_getBytes);
    oluacls_func(L, "getTextureFormat", _cocos2d_backend_TextureBackend_getTextureFormat);
    oluacls_func(L, "getTextureType", _cocos2d_backend_TextureBackend_getTextureType);
    oluacls_func(L, "getTextureUsage", _cocos2d_backend_TextureBackend_getTextureUsage);
    oluacls_func(L, "hasMipmaps", _cocos2d_backend_TextureBackend_hasMipmaps);
    oluacls_func(L, "updateSamplerDescriptor", _cocos2d_backend_TextureBackend_updateSamplerDescriptor);
    oluacls_func(L, "updateTextureDescriptor", _cocos2d_backend_TextureBackend_updateTextureDescriptor);
    oluacls_prop(L, "textureFormat", _cocos2d_backend_TextureBackend_getTextureFormat, nullptr);
    oluacls_prop(L, "textureType", _cocos2d_backend_TextureBackend_getTextureType, nullptr);
    oluacls_prop(L, "textureUsage", _cocos2d_backend_TextureBackend_getTextureUsage, nullptr);

    olua_registerluatype<cocos2d::backend::TextureBackend>(L, "ccb.TextureBackend");

    return 1;
}

static int _cocos2d_backend_Texture2DBackend___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::backend::Texture2DBackend *)olua_toobj(L, 1, "ccb.Texture2DBackend");
    olua_push_cppobj(L, self, "ccb.Texture2DBackend");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_backend_Texture2DBackend_getHeight(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::Texture2DBackend *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccb.Texture2DBackend");

    // std::size_t getHeight()
    std::size_t ret = self->getHeight();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_backend_Texture2DBackend_getWidth(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::Texture2DBackend *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccb.Texture2DBackend");

    // std::size_t getWidth()
    std::size_t ret = self->getWidth();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_backend_Texture2DBackend_updateCompressedData(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::Texture2DBackend *self = nullptr;
    const char *arg1 = nullptr;       /** data */
    lua_Unsigned arg2 = 0;       /** width */
    lua_Unsigned arg3 = 0;       /** height */
    lua_Unsigned arg4 = 0;       /** dataLen */
    lua_Unsigned arg5 = 0;       /** level */

    olua_to_cppobj(L, 1, (void **)&self, "ccb.Texture2DBackend");
    olua_check_string(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);
    olua_check_uint(L, 4, &arg3);
    olua_check_uint(L, 5, &arg4);
    olua_check_uint(L, 6, &arg5);

    // void updateCompressedData(uint8_t *data, std::size_t width, std::size_t height, std::size_t dataLen, std::size_t level)
    self->updateCompressedData((uint8_t *)arg1, (std::size_t)arg2, (std::size_t)arg3, (std::size_t)arg4, (std::size_t)arg5);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_backend_Texture2DBackend_updateCompressedSubData(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::Texture2DBackend *self = nullptr;
    lua_Unsigned arg1 = 0;       /** xoffset */
    lua_Unsigned arg2 = 0;       /** yoffset */
    lua_Unsigned arg3 = 0;       /** width */
    lua_Unsigned arg4 = 0;       /** height */
    lua_Unsigned arg5 = 0;       /** dataLen */
    lua_Unsigned arg6 = 0;       /** level */
    const char *arg7 = nullptr;       /** data */

    olua_to_cppobj(L, 1, (void **)&self, "ccb.Texture2DBackend");
    olua_check_uint(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);
    olua_check_uint(L, 4, &arg3);
    olua_check_uint(L, 5, &arg4);
    olua_check_uint(L, 6, &arg5);
    olua_check_uint(L, 7, &arg6);
    olua_check_string(L, 8, &arg7);

    // void updateCompressedSubData(std::size_t xoffset, std::size_t yoffset, std::size_t width, std::size_t height, std::size_t dataLen, std::size_t level, uint8_t *data)
    self->updateCompressedSubData((std::size_t)arg1, (std::size_t)arg2, (std::size_t)arg3, (std::size_t)arg4, (std::size_t)arg5, (std::size_t)arg6, (uint8_t *)arg7);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_backend_Texture2DBackend_updateData(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::Texture2DBackend *self = nullptr;
    const char *arg1 = nullptr;       /** data */
    lua_Unsigned arg2 = 0;       /** width */
    lua_Unsigned arg3 = 0;       /** height */
    lua_Unsigned arg4 = 0;       /** level */

    olua_to_cppobj(L, 1, (void **)&self, "ccb.Texture2DBackend");
    olua_check_string(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);
    olua_check_uint(L, 4, &arg3);
    olua_check_uint(L, 5, &arg4);

    // void updateData(uint8_t *data, std::size_t width, std::size_t height, std::size_t level)
    self->updateData((uint8_t *)arg1, (std::size_t)arg2, (std::size_t)arg3, (std::size_t)arg4);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_backend_Texture2DBackend_updateSubData(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::Texture2DBackend *self = nullptr;
    lua_Unsigned arg1 = 0;       /** xoffset */
    lua_Unsigned arg2 = 0;       /** yoffset */
    lua_Unsigned arg3 = 0;       /** width */
    lua_Unsigned arg4 = 0;       /** height */
    lua_Unsigned arg5 = 0;       /** level */
    const char *arg6 = nullptr;       /** data */

    olua_to_cppobj(L, 1, (void **)&self, "ccb.Texture2DBackend");
    olua_check_uint(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);
    olua_check_uint(L, 4, &arg3);
    olua_check_uint(L, 5, &arg4);
    olua_check_uint(L, 6, &arg5);
    olua_check_string(L, 7, &arg6);

    // void updateSubData(std::size_t xoffset, std::size_t yoffset, std::size_t width, std::size_t height, std::size_t level, uint8_t *data)
    self->updateSubData((std::size_t)arg1, (std::size_t)arg2, (std::size_t)arg3, (std::size_t)arg4, (std::size_t)arg5, (uint8_t *)arg6);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_backend_Texture2DBackend(lua_State *L)
{
    oluacls_class(L, "ccb.Texture2DBackend", "ccb.TextureBackend");
    oluacls_func(L, "__move", _cocos2d_backend_Texture2DBackend___move);
    oluacls_func(L, "getHeight", _cocos2d_backend_Texture2DBackend_getHeight);
    oluacls_func(L, "getWidth", _cocos2d_backend_Texture2DBackend_getWidth);
    oluacls_func(L, "updateCompressedData", _cocos2d_backend_Texture2DBackend_updateCompressedData);
    oluacls_func(L, "updateCompressedSubData", _cocos2d_backend_Texture2DBackend_updateCompressedSubData);
    oluacls_func(L, "updateData", _cocos2d_backend_Texture2DBackend_updateData);
    oluacls_func(L, "updateSubData", _cocos2d_backend_Texture2DBackend_updateSubData);
    oluacls_prop(L, "height", _cocos2d_backend_Texture2DBackend_getHeight, nullptr);
    oluacls_prop(L, "width", _cocos2d_backend_Texture2DBackend_getWidth, nullptr);

    olua_registerluatype<cocos2d::backend::Texture2DBackend>(L, "ccb.Texture2DBackend");

    return 1;
}

static int _cocos2d_backend_TextureCubemapBackend___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::backend::TextureCubemapBackend *)olua_toobj(L, 1, "ccb.TextureCubemapBackend");
    olua_push_cppobj(L, self, "ccb.TextureCubemapBackend");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_backend_TextureCubemapBackend_updateFaceData(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::TextureCubemapBackend *self = nullptr;
    lua_Unsigned arg1 = 0;       /** side */
    void *arg2 = nullptr;       /** data */

    olua_to_cppobj(L, 1, (void **)&self, "ccb.TextureCubemapBackend");
    olua_check_uint(L, 2, &arg1);
    olua_check_obj(L, 3, (void **)&arg2, "void *");

    // void updateFaceData(cocos2d::backend::TextureCubeFace side, void *data)
    self->updateFaceData((cocos2d::backend::TextureCubeFace)arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_backend_TextureCubemapBackend(lua_State *L)
{
    oluacls_class(L, "ccb.TextureCubemapBackend", "ccb.TextureBackend");
    oluacls_func(L, "__move", _cocos2d_backend_TextureCubemapBackend___move);
    oluacls_func(L, "updateFaceData", _cocos2d_backend_TextureCubemapBackend_updateFaceData);

    olua_registerluatype<cocos2d::backend::TextureCubemapBackend>(L, "ccb.TextureCubemapBackend");

    return 1;
}

int luaopen_cocos2d_backend(lua_State *L)
{
    olua_require(L, "ccb.BufferUsage", luaopen_cocos2d_backend_BufferUsage);
    olua_require(L, "ccb.BufferType", luaopen_cocos2d_backend_BufferType);
    olua_require(L, "ccb.ShaderStage", luaopen_cocos2d_backend_ShaderStage);
    olua_require(L, "ccb.VertexFormat", luaopen_cocos2d_backend_VertexFormat);
    olua_require(L, "ccb.PixelFormat", luaopen_cocos2d_backend_PixelFormat);
    olua_require(L, "ccb.TextureUsage", luaopen_cocos2d_backend_TextureUsage);
    olua_require(L, "ccb.IndexFormat", luaopen_cocos2d_backend_IndexFormat);
    olua_require(L, "ccb.VertexStepMode", luaopen_cocos2d_backend_VertexStepMode);
    olua_require(L, "ccb.PrimitiveType", luaopen_cocos2d_backend_PrimitiveType);
    olua_require(L, "ccb.TextureType", luaopen_cocos2d_backend_TextureType);
    olua_require(L, "ccb.SamplerAddressMode", luaopen_cocos2d_backend_SamplerAddressMode);
    olua_require(L, "ccb.SamplerFilter", luaopen_cocos2d_backend_SamplerFilter);
    olua_require(L, "ccb.StencilOperation", luaopen_cocos2d_backend_StencilOperation);
    olua_require(L, "ccb.CompareFunction", luaopen_cocos2d_backend_CompareFunction);
    olua_require(L, "ccb.BlendOperation", luaopen_cocos2d_backend_BlendOperation);
    olua_require(L, "ccb.BlendFactor", luaopen_cocos2d_backend_BlendFactor);
    olua_require(L, "ccb.ColorWriteMask", luaopen_cocos2d_backend_ColorWriteMask);
    olua_require(L, "ccb.CullMode", luaopen_cocos2d_backend_CullMode);
    olua_require(L, "ccb.Winding", luaopen_cocos2d_backend_Winding);
    olua_require(L, "ccb.TextureCubeFace", luaopen_cocos2d_backend_TextureCubeFace);
    olua_require(L, "ccb.ProgramType", luaopen_cocos2d_backend_ProgramType);
    olua_require(L, "ccb.Uniform", luaopen_cocos2d_backend_Uniform);
    olua_require(L, "ccb.Attribute", luaopen_cocos2d_backend_Attribute);
    olua_require(L, "ccb.FeatureType", luaopen_cocos2d_backend_FeatureType);
    olua_require(L, "ccb.Buffer", luaopen_cocos2d_backend_Buffer);
    olua_require(L, "ccb.RenderPipeline", luaopen_cocos2d_backend_RenderPipeline);
    olua_require(L, "ccb.DepthStencilState", luaopen_cocos2d_backend_DepthStencilState);
    olua_require(L, "ccb.VertexLayout", luaopen_cocos2d_backend_VertexLayout);
    olua_require(L, "ccb.CommandBuffer", luaopen_cocos2d_backend_CommandBuffer);
    olua_require(L, "ccb.Device", luaopen_cocos2d_backend_Device);
    olua_require(L, "ccb.DeviceInfo", luaopen_cocos2d_backend_DeviceInfo);
    olua_require(L, "ccb.ShaderCache", luaopen_cocos2d_backend_ShaderCache);
    olua_require(L, "ccb.ShaderModule", luaopen_cocos2d_backend_ShaderModule);
    olua_require(L, "ccb.ProgramCache", luaopen_cocos2d_backend_ProgramCache);
    olua_require(L, "ccb.ProgramState", luaopen_cocos2d_backend_ProgramState);
    olua_require(L, "ccb.Program", luaopen_cocos2d_backend_Program);
    olua_require(L, "ccb.TextureBackend", luaopen_cocos2d_backend_TextureBackend);
    olua_require(L, "ccb.Texture2DBackend", luaopen_cocos2d_backend_Texture2DBackend);
    olua_require(L, "ccb.TextureCubemapBackend", luaopen_cocos2d_backend_TextureCubemapBackend);
    return 0;
}
