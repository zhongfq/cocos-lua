-- AUTO BUILD, DON'T MODIFY!

require "autobuild.cocos2d-backend-types"

local olua = require "olua"
local typeconv = olua.typeconv
local typecls = olua.typecls
local cls = nil
local M = {}

M.NAME = "cocos2d_backend"
M.PATH = "../../frameworks/libxgame/src/lua-bindings"
M.INCLUDES = [[
#include "lua-bindings/lua_cocos2d_backend.h"
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "cocos2d.h"
#include "xgame/xlua.h"
]]

M.CONVS = {
}

M.CLASSES = {}

cls = typecls 'cocos2d::backend::BufferUsage'
cls.enum('STATIC', 'cocos2d::backend::BufferUsage::STATIC')
cls.enum('DYNAMIC', 'cocos2d::backend::BufferUsage::DYNAMIC')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::backend::BufferType'
cls.enum('VERTEX', 'cocos2d::backend::BufferType::VERTEX')
cls.enum('INDEX', 'cocos2d::backend::BufferType::INDEX')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::backend::ShaderStage'
cls.enum('VERTEX', 'cocos2d::backend::ShaderStage::VERTEX')
cls.enum('FRAGMENT', 'cocos2d::backend::ShaderStage::FRAGMENT')
cls.enum('VERTEX_AND_FRAGMENT', 'cocos2d::backend::ShaderStage::VERTEX_AND_FRAGMENT')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::backend::VertexFormat'
cls.enum('FLOAT4', 'cocos2d::backend::VertexFormat::FLOAT4')
cls.enum('FLOAT3', 'cocos2d::backend::VertexFormat::FLOAT3')
cls.enum('FLOAT2', 'cocos2d::backend::VertexFormat::FLOAT2')
cls.enum('FLOAT', 'cocos2d::backend::VertexFormat::FLOAT')
cls.enum('INT4', 'cocos2d::backend::VertexFormat::INT4')
cls.enum('INT3', 'cocos2d::backend::VertexFormat::INT3')
cls.enum('INT2', 'cocos2d::backend::VertexFormat::INT2')
cls.enum('INT', 'cocos2d::backend::VertexFormat::INT')
cls.enum('USHORT4', 'cocos2d::backend::VertexFormat::USHORT4')
cls.enum('USHORT2', 'cocos2d::backend::VertexFormat::USHORT2')
cls.enum('UBYTE4', 'cocos2d::backend::VertexFormat::UBYTE4')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::backend::PixelFormat'
cls.enum('AUTO', 'cocos2d::backend::PixelFormat::AUTO')
cls.enum('BGRA8888', 'cocos2d::backend::PixelFormat::BGRA8888')
cls.enum('RGBA8888', 'cocos2d::backend::PixelFormat::RGBA8888')
cls.enum('RGB888', 'cocos2d::backend::PixelFormat::RGB888')
cls.enum('RGB565', 'cocos2d::backend::PixelFormat::RGB565')
cls.enum('A8', 'cocos2d::backend::PixelFormat::A8')
cls.enum('I8', 'cocos2d::backend::PixelFormat::I8')
cls.enum('AI88', 'cocos2d::backend::PixelFormat::AI88')
cls.enum('RGBA4444', 'cocos2d::backend::PixelFormat::RGBA4444')
cls.enum('RGB5A1', 'cocos2d::backend::PixelFormat::RGB5A1')
cls.enum('PVRTC4', 'cocos2d::backend::PixelFormat::PVRTC4')
cls.enum('PVRTC4A', 'cocos2d::backend::PixelFormat::PVRTC4A')
cls.enum('PVRTC2', 'cocos2d::backend::PixelFormat::PVRTC2')
cls.enum('PVRTC2A', 'cocos2d::backend::PixelFormat::PVRTC2A')
cls.enum('ETC', 'cocos2d::backend::PixelFormat::ETC')
cls.enum('S3TC_DXT1', 'cocos2d::backend::PixelFormat::S3TC_DXT1')
cls.enum('S3TC_DXT3', 'cocos2d::backend::PixelFormat::S3TC_DXT3')
cls.enum('S3TC_DXT5', 'cocos2d::backend::PixelFormat::S3TC_DXT5')
cls.enum('ATC_RGB', 'cocos2d::backend::PixelFormat::ATC_RGB')
cls.enum('ATC_EXPLICIT_ALPHA', 'cocos2d::backend::PixelFormat::ATC_EXPLICIT_ALPHA')
cls.enum('ATC_INTERPOLATED_ALPHA', 'cocos2d::backend::PixelFormat::ATC_INTERPOLATED_ALPHA')
cls.enum('MTL_B5G6R5', 'cocos2d::backend::PixelFormat::MTL_B5G6R5')
cls.enum('MTL_BGR5A1', 'cocos2d::backend::PixelFormat::MTL_BGR5A1')
cls.enum('MTL_ABGR4', 'cocos2d::backend::PixelFormat::MTL_ABGR4')
cls.enum('D24S8', 'cocos2d::backend::PixelFormat::D24S8')
cls.enum('DEFAULT', 'cocos2d::backend::PixelFormat::DEFAULT')
cls.enum('NONE', 'cocos2d::backend::PixelFormat::NONE')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::backend::TextureUsage'
cls.enum('READ', 'cocos2d::backend::TextureUsage::READ')
cls.enum('WRITE', 'cocos2d::backend::TextureUsage::WRITE')
cls.enum('RENDER_TARGET', 'cocos2d::backend::TextureUsage::RENDER_TARGET')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::backend::IndexFormat'
cls.enum('U_SHORT', 'cocos2d::backend::IndexFormat::U_SHORT')
cls.enum('U_INT', 'cocos2d::backend::IndexFormat::U_INT')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::backend::VertexStepMode'
cls.enum('VERTEX', 'cocos2d::backend::VertexStepMode::VERTEX')
cls.enum('INSTANCE', 'cocos2d::backend::VertexStepMode::INSTANCE')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::backend::PrimitiveType'
cls.enum('POINT', 'cocos2d::backend::PrimitiveType::POINT')
cls.enum('LINE', 'cocos2d::backend::PrimitiveType::LINE')
cls.enum('LINE_STRIP', 'cocos2d::backend::PrimitiveType::LINE_STRIP')
cls.enum('TRIANGLE', 'cocos2d::backend::PrimitiveType::TRIANGLE')
cls.enum('TRIANGLE_STRIP', 'cocos2d::backend::PrimitiveType::TRIANGLE_STRIP')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::backend::TextureType'
cls.enum('TEXTURE_2D', 'cocos2d::backend::TextureType::TEXTURE_2D')
cls.enum('TEXTURE_CUBE', 'cocos2d::backend::TextureType::TEXTURE_CUBE')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::backend::SamplerAddressMode'
cls.enum('REPEAT', 'cocos2d::backend::SamplerAddressMode::REPEAT')
cls.enum('MIRROR_REPEAT', 'cocos2d::backend::SamplerAddressMode::MIRROR_REPEAT')
cls.enum('CLAMP_TO_EDGE', 'cocos2d::backend::SamplerAddressMode::CLAMP_TO_EDGE')
cls.enum('DONT_CARE', 'cocos2d::backend::SamplerAddressMode::DONT_CARE')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::backend::SamplerFilter'
cls.enum('NEAREST', 'cocos2d::backend::SamplerFilter::NEAREST')
cls.enum('NEAREST_MIPMAP_NEAREST', 'cocos2d::backend::SamplerFilter::NEAREST_MIPMAP_NEAREST')
cls.enum('NEAREST_MIPMAP_LINEAR', 'cocos2d::backend::SamplerFilter::NEAREST_MIPMAP_LINEAR')
cls.enum('LINEAR', 'cocos2d::backend::SamplerFilter::LINEAR')
cls.enum('LINEAR_MIPMAP_LINEAR', 'cocos2d::backend::SamplerFilter::LINEAR_MIPMAP_LINEAR')
cls.enum('LINEAR_MIPMAP_NEAREST', 'cocos2d::backend::SamplerFilter::LINEAR_MIPMAP_NEAREST')
cls.enum('DONT_CARE', 'cocos2d::backend::SamplerFilter::DONT_CARE')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::backend::StencilOperation'
cls.enum('KEEP', 'cocos2d::backend::StencilOperation::KEEP')
cls.enum('ZERO', 'cocos2d::backend::StencilOperation::ZERO')
cls.enum('REPLACE', 'cocos2d::backend::StencilOperation::REPLACE')
cls.enum('INVERT', 'cocos2d::backend::StencilOperation::INVERT')
cls.enum('INCREMENT_WRAP', 'cocos2d::backend::StencilOperation::INCREMENT_WRAP')
cls.enum('DECREMENT_WRAP', 'cocos2d::backend::StencilOperation::DECREMENT_WRAP')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::backend::CompareFunction'
cls.enum('NEVER', 'cocos2d::backend::CompareFunction::NEVER')
cls.enum('LESS', 'cocos2d::backend::CompareFunction::LESS')
cls.enum('LESS_EQUAL', 'cocos2d::backend::CompareFunction::LESS_EQUAL')
cls.enum('GREATER', 'cocos2d::backend::CompareFunction::GREATER')
cls.enum('GREATER_EQUAL', 'cocos2d::backend::CompareFunction::GREATER_EQUAL')
cls.enum('EQUAL', 'cocos2d::backend::CompareFunction::EQUAL')
cls.enum('NOT_EQUAL', 'cocos2d::backend::CompareFunction::NOT_EQUAL')
cls.enum('ALWAYS', 'cocos2d::backend::CompareFunction::ALWAYS')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::backend::BlendOperation'
cls.enum('ADD', 'cocos2d::backend::BlendOperation::ADD')
cls.enum('SUBTRACT', 'cocos2d::backend::BlendOperation::SUBTRACT')
cls.enum('RESERVE_SUBTRACT', 'cocos2d::backend::BlendOperation::RESERVE_SUBTRACT')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::backend::BlendFactor'
cls.enum('ZERO', 'cocos2d::backend::BlendFactor::ZERO')
cls.enum('ONE', 'cocos2d::backend::BlendFactor::ONE')
cls.enum('SRC_COLOR', 'cocos2d::backend::BlendFactor::SRC_COLOR')
cls.enum('ONE_MINUS_SRC_COLOR', 'cocos2d::backend::BlendFactor::ONE_MINUS_SRC_COLOR')
cls.enum('SRC_ALPHA', 'cocos2d::backend::BlendFactor::SRC_ALPHA')
cls.enum('ONE_MINUS_SRC_ALPHA', 'cocos2d::backend::BlendFactor::ONE_MINUS_SRC_ALPHA')
cls.enum('DST_COLOR', 'cocos2d::backend::BlendFactor::DST_COLOR')
cls.enum('ONE_MINUS_DST_COLOR', 'cocos2d::backend::BlendFactor::ONE_MINUS_DST_COLOR')
cls.enum('DST_ALPHA', 'cocos2d::backend::BlendFactor::DST_ALPHA')
cls.enum('ONE_MINUS_DST_ALPHA', 'cocos2d::backend::BlendFactor::ONE_MINUS_DST_ALPHA')
cls.enum('CONSTANT_ALPHA', 'cocos2d::backend::BlendFactor::CONSTANT_ALPHA')
cls.enum('SRC_ALPHA_SATURATE', 'cocos2d::backend::BlendFactor::SRC_ALPHA_SATURATE')
cls.enum('ONE_MINUS_CONSTANT_ALPHA', 'cocos2d::backend::BlendFactor::ONE_MINUS_CONSTANT_ALPHA')
cls.enum('BLEND_CLOLOR', 'cocos2d::backend::BlendFactor::BLEND_CLOLOR')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::backend::ColorWriteMask'
cls.enum('NONE', 'cocos2d::backend::ColorWriteMask::NONE')
cls.enum('RED', 'cocos2d::backend::ColorWriteMask::RED')
cls.enum('GREEN', 'cocos2d::backend::ColorWriteMask::GREEN')
cls.enum('BLUE', 'cocos2d::backend::ColorWriteMask::BLUE')
cls.enum('ALPHA', 'cocos2d::backend::ColorWriteMask::ALPHA')
cls.enum('ALL', 'cocos2d::backend::ColorWriteMask::ALL')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::backend::CullMode'
cls.enum('NONE', 'cocos2d::backend::CullMode::NONE')
cls.enum('BACK', 'cocos2d::backend::CullMode::BACK')
cls.enum('FRONT', 'cocos2d::backend::CullMode::FRONT')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::backend::Winding'
cls.enum('CLOCK_WISE', 'cocos2d::backend::Winding::CLOCK_WISE')
cls.enum('COUNTER_CLOCK_WISE', 'cocos2d::backend::Winding::COUNTER_CLOCK_WISE')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::backend::TextureCubeFace'
cls.enum('POSITIVE_X', 'cocos2d::backend::TextureCubeFace::POSITIVE_X')
cls.enum('NEGATIVE_X', 'cocos2d::backend::TextureCubeFace::NEGATIVE_X')
cls.enum('POSITIVE_Y', 'cocos2d::backend::TextureCubeFace::POSITIVE_Y')
cls.enum('NEGATIVE_Y', 'cocos2d::backend::TextureCubeFace::NEGATIVE_Y')
cls.enum('POSITIVE_Z', 'cocos2d::backend::TextureCubeFace::POSITIVE_Z')
cls.enum('NEGATIVE_Z', 'cocos2d::backend::TextureCubeFace::NEGATIVE_Z')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::backend::ProgramType'
cls.enum('POSITION_COLOR_LENGTH_TEXTURE', 'cocos2d::backend::ProgramType::POSITION_COLOR_LENGTH_TEXTURE')
cls.enum('POSITION_COLOR_TEXTURE_AS_POINTSIZE', 'cocos2d::backend::ProgramType::POSITION_COLOR_TEXTURE_AS_POINTSIZE')
cls.enum('POSITION_COLOR', 'cocos2d::backend::ProgramType::POSITION_COLOR')
cls.enum('POSITION', 'cocos2d::backend::ProgramType::POSITION')
cls.enum('POSITION_UCOLOR', 'cocos2d::backend::ProgramType::POSITION_UCOLOR')
cls.enum('POSITION_TEXTURE', 'cocos2d::backend::ProgramType::POSITION_TEXTURE')
cls.enum('POSITION_TEXTURE_COLOR', 'cocos2d::backend::ProgramType::POSITION_TEXTURE_COLOR')
cls.enum('POSITION_TEXTURE_COLOR_ALPHA_TEST', 'cocos2d::backend::ProgramType::POSITION_TEXTURE_COLOR_ALPHA_TEST')
cls.enum('LABEL_NORMAL', 'cocos2d::backend::ProgramType::LABEL_NORMAL')
cls.enum('LABLE_OUTLINE', 'cocos2d::backend::ProgramType::LABLE_OUTLINE')
cls.enum('LABLE_DISTANCEFIELD_GLOW', 'cocos2d::backend::ProgramType::LABLE_DISTANCEFIELD_GLOW')
cls.enum('LABEL_DISTANCE_NORMAL', 'cocos2d::backend::ProgramType::LABEL_DISTANCE_NORMAL')
cls.enum('LAYER_RADIA_GRADIENT', 'cocos2d::backend::ProgramType::LAYER_RADIA_GRADIENT')
cls.enum('ETC1', 'cocos2d::backend::ProgramType::ETC1')
cls.enum('ETC1_GRAY', 'cocos2d::backend::ProgramType::ETC1_GRAY')
cls.enum('GRAY_SCALE', 'cocos2d::backend::ProgramType::GRAY_SCALE')
cls.enum('CAMERA_CLEAR', 'cocos2d::backend::ProgramType::CAMERA_CLEAR')
cls.enum('TERRAIN_3D', 'cocos2d::backend::ProgramType::TERRAIN_3D')
cls.enum('LINE_COLOR_3D', 'cocos2d::backend::ProgramType::LINE_COLOR_3D')
cls.enum('SKYBOX_3D', 'cocos2d::backend::ProgramType::SKYBOX_3D')
cls.enum('SKINPOSITION_TEXTURE_3D', 'cocos2d::backend::ProgramType::SKINPOSITION_TEXTURE_3D')
cls.enum('SKINPOSITION_NORMAL_TEXTURE_3D', 'cocos2d::backend::ProgramType::SKINPOSITION_NORMAL_TEXTURE_3D')
cls.enum('POSITION_NORMAL_TEXTURE_3D', 'cocos2d::backend::ProgramType::POSITION_NORMAL_TEXTURE_3D')
cls.enum('POSITION_NORMAL_3D', 'cocos2d::backend::ProgramType::POSITION_NORMAL_3D')
cls.enum('POSITION_TEXTURE_3D', 'cocos2d::backend::ProgramType::POSITION_TEXTURE_3D')
cls.enum('POSITION_3D', 'cocos2d::backend::ProgramType::POSITION_3D')
cls.enum('POSITION_BUMPEDNORMAL_TEXTURE_3D', 'cocos2d::backend::ProgramType::POSITION_BUMPEDNORMAL_TEXTURE_3D')
cls.enum('SKINPOSITION_BUMPEDNORMAL_TEXTURE_3D', 'cocos2d::backend::ProgramType::SKINPOSITION_BUMPEDNORMAL_TEXTURE_3D')
cls.enum('PARTICLE_TEXTURE_3D', 'cocos2d::backend::ProgramType::PARTICLE_TEXTURE_3D')
cls.enum('PARTICLE_COLOR_3D', 'cocos2d::backend::ProgramType::PARTICLE_COLOR_3D')
cls.enum('CUSTOM_PROGRAM', 'cocos2d::backend::ProgramType::CUSTOM_PROGRAM')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::backend::Uniform'
cls.enum('MVP_MATRIX', 'cocos2d::backend::Uniform::MVP_MATRIX')
cls.enum('TEXTURE', 'cocos2d::backend::Uniform::TEXTURE')
cls.enum('TEXTURE1', 'cocos2d::backend::Uniform::TEXTURE1')
cls.enum('TEXTURE2', 'cocos2d::backend::Uniform::TEXTURE2')
cls.enum('TEXTURE3', 'cocos2d::backend::Uniform::TEXTURE3')
cls.enum('TEXT_COLOR', 'cocos2d::backend::Uniform::TEXT_COLOR')
cls.enum('EFFECT_TYPE', 'cocos2d::backend::Uniform::EFFECT_TYPE')
cls.enum('EFFECT_COLOR', 'cocos2d::backend::Uniform::EFFECT_COLOR')
cls.enum('UNIFORM_MAX', 'cocos2d::backend::Uniform::UNIFORM_MAX')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::backend::Attribute'
cls.enum('POSITION', 'cocos2d::backend::Attribute::POSITION')
cls.enum('COLOR', 'cocos2d::backend::Attribute::COLOR')
cls.enum('TEXCOORD', 'cocos2d::backend::Attribute::TEXCOORD')
cls.enum('TEXCOORD1', 'cocos2d::backend::Attribute::TEXCOORD1')
cls.enum('TEXCOORD2', 'cocos2d::backend::Attribute::TEXCOORD2')
cls.enum('TEXCOORD3', 'cocos2d::backend::Attribute::TEXCOORD3')
cls.enum('ATTRIBUTE_MAX', 'cocos2d::backend::Attribute::ATTRIBUTE_MAX')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::backend::FeatureType'
cls.enum('ETC1', 'cocos2d::backend::FeatureType::ETC1')
cls.enum('S3TC', 'cocos2d::backend::FeatureType::S3TC')
cls.enum('AMD_COMPRESSED_ATC', 'cocos2d::backend::FeatureType::AMD_COMPRESSED_ATC')
cls.enum('PVRTC', 'cocos2d::backend::FeatureType::PVRTC')
cls.enum('IMG_FORMAT_BGRA8888', 'cocos2d::backend::FeatureType::IMG_FORMAT_BGRA8888')
cls.enum('DISCARD_FRAMEBUFFER', 'cocos2d::backend::FeatureType::DISCARD_FRAMEBUFFER')
cls.enum('PACKED_DEPTH_STENCIL', 'cocos2d::backend::FeatureType::PACKED_DEPTH_STENCIL')
cls.enum('VAO', 'cocos2d::backend::FeatureType::VAO')
cls.enum('MAPBUFFER', 'cocos2d::backend::FeatureType::MAPBUFFER')
cls.enum('DEPTH24', 'cocos2d::backend::FeatureType::DEPTH24')
cls.enum('ASTC', 'cocos2d::backend::FeatureType::ASTC')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::backend::Buffer'
cls.SUPERCLS = "cocos2d::Ref"
cls.funcs [[
    void updateData(void *data, std::size_t size)
    void updateSubData(void *data, std::size_t offset, std::size_t size)
    void usingDefaultStoredData(bool needDefaultStoredData)
    std::size_t getSize()
]]
cls.props [[
    size
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::backend::RenderPipeline'
cls.SUPERCLS = "cocos2d::Ref"
cls.funcs [[
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::backend::DepthStencilState'
cls.SUPERCLS = "cocos2d::Ref"
cls.funcs [[
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::backend::VertexLayout'
cls.funcs [[
    VertexLayout()
    void setAttribute(const std::string &name, std::size_t index, cocos2d::backend::VertexFormat format, std::size_t offset, bool needToBeNormallized)
    void setLayout(std::size_t stride)
    std::size_t getStride()
    cocos2d::backend::VertexStepMode getVertexStepMode()
    const std::unordered_map<std::string, Attribute> &getAttributes()
    bool isValid()
]]
cls.props [[
    stride
    vertexStepMode
    attributes
    valid
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::backend::CommandBuffer'
cls.SUPERCLS = "cocos2d::Ref"
cls.funcs [[
    void beginFrame()
    void setRenderPipeline(cocos2d::backend::RenderPipeline *renderPipeline)
    void setViewport(int x, int y, unsigned int w, unsigned int h)
    void setCullMode(cocos2d::backend::CullMode mode)
    void setWinding(cocos2d::backend::Winding winding)
    void setVertexBuffer(cocos2d::backend::Buffer *buffer)
    void setProgramState(cocos2d::backend::ProgramState *programState)
    void setIndexBuffer(cocos2d::backend::Buffer *buffer)
    void drawArrays(cocos2d::backend::PrimitiveType primitiveType, std::size_t start, std::size_t count)
    void drawElements(cocos2d::backend::PrimitiveType primitiveType, cocos2d::backend::IndexFormat indexType, std::size_t count, std::size_t offset)
    void endRenderPass()
    void endFrame()
    void setLineWidth(float lineWidth)
    void setScissorRect(bool isEnabled, float x, float y, float width, float height)
    void setDepthStencilState(cocos2d::backend::DepthStencilState *depthStencilState)
    void setStencilReferenceValue(unsigned int value)
    void setStencilReferenceValue(unsigned int frontRef, unsigned int backRef)
]]
cls.callback {
    FUNCS =  {
        'void captureScreen(@local std::function<void (const unsigned char *, int, int)> callback)'
    },
    TAG_MAKER = 'captureScreen',
    TAG_MODE = 'OLUA_TAG_NEW',
    TAG_STORE = nil,
    TAG_SCOPE = 'once',
}
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::backend::Device'
cls.SUPERCLS = "cocos2d::Ref"
cls.funcs [[
    static cocos2d::backend::Device *getInstance()
    cocos2d::backend::CommandBuffer *newCommandBuffer()
    cocos2d::backend::Buffer *newBuffer(size_t size, cocos2d::backend::BufferType type, cocos2d::backend::BufferUsage usage)
    cocos2d::backend::TextureBackend *newTexture(const cocos2d::backend::TextureDescriptor &descriptor)
    cocos2d::backend::DepthStencilState *createDepthStencilState(const cocos2d::backend::DepthStencilDescriptor &descriptor)
    cocos2d::backend::RenderPipeline *newRenderPipeline()
    void setFrameBufferOnly(bool frameBufferOnly)
    cocos2d::backend::Program *newProgram(const std::string &vertexShader, const std::string &fragmentShader)
    cocos2d::backend::DeviceInfo *getDeviceInfo()
]]
cls.insert('newProgram', {
    AFTER = [[
        ret->autorelease();
    ]],
})
cls.insert('newRenderPipeline', {
    AFTER = [[
        ret->autorelease();
    ]],
})
cls.insert('newTexture', {
    AFTER = [[
        ret->autorelease();
    ]],
})
cls.insert('newBuffer', {
    AFTER = [[
        ret->autorelease();
    ]],
})
cls.insert('newCommandBuffer', {
    AFTER = [[
        ret->autorelease();
    ]],
})
cls.props [[
    instance
    deviceInfo
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::backend::DeviceInfo'
cls.funcs [[
    bool init()
    const char *getVendor()
    const char *getRenderer()
    const char *getVersion()
    const char *getExtension()
    bool checkForFeatureSupported(cocos2d::backend::FeatureType feature)
    int getMaxTextureSize()
    int getMaxAttributes()
    int getMaxTextureUnits()
    int getMaxSamplesAllowed()
]]
cls.props [[
    vendor
    renderer
    version
    extension
    maxTextureSize
    maxAttributes
    maxTextureUnits
    maxSamplesAllowed
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::backend::ShaderCache'
cls.SUPERCLS = "cocos2d::Ref"
cls.funcs [[
    static cocos2d::backend::ShaderCache *getInstance()
    static void destroyInstance()
    static cocos2d::backend::ShaderModule *newVertexShaderModule(const std::string &shaderSource)
    static cocos2d::backend::ShaderModule *newFragmentShaderModule(const std::string &shaderSource)
    void removeUnusedShader()
]]
cls.props [[
    instance
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::backend::ShaderModule'
cls.SUPERCLS = "cocos2d::Ref"
cls.funcs [[
    cocos2d::backend::ShaderStage getShaderStage()
    std::size_t getHashValue()
]]
cls.props [[
    shaderStage
    hashValue
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::backend::ProgramCache'
cls.SUPERCLS = "cocos2d::Ref"
cls.funcs [[
    static cocos2d::backend::ProgramCache *getInstance()
    static void destroyInstance()
    cocos2d::backend::Program *getBuiltinProgram(cocos2d::backend::ProgramType type)
    void removeProgram(cocos2d::backend::Program *program)
    void removeUnusedProgram()
    void removeAllPrograms()
    void addCustomProgram(const std::string &key, cocos2d::backend::Program *program)
    cocos2d::backend::Program *getCustomProgram(const std::string &key)
]]
cls.props [[
    instance
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::backend::ProgramState'
cls.SUPERCLS = "cocos2d::Ref"
cls.CHUNK = [[
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
cls.funcs [[
    ProgramState(cocos2d::backend::Program *program)
    cocos2d::backend::ProgramState *clone()
    cocos2d::backend::Program *getProgram()
    void setUniform(const cocos2d::backend::UniformLocation &uniformLocation, const void *data, std::size_t size)
    cocos2d::backend::UniformLocation getUniformLocation(const std::string &uniform)
    cocos2d::backend::UniformLocation getUniformLocation(cocos2d::backend::Uniform name)
    int getAttributeLocation(const std::string &name)
    int getAttributeLocation(cocos2d::backend::Attribute name)
    void setTexture(const cocos2d::backend::UniformLocation &uniformLocation, uint32_t slot, cocos2d::backend::TextureBackend *texture)
    void setTextureArray(const cocos2d::backend::UniformLocation &uniformLocation, const std::vector<uint32_t> &slots, const std::vector<backend::TextureBackend *> textures)
    const std::unordered_map<int, TextureInfo> &getVertexTextureInfos()
    const std::unordered_map<int, TextureInfo> &getFragmentTextureInfos()
    void setParameterAutoBinding(const std::string &uniformName, const std::string &autoBinding)
]]
cls.func('getVertexLayout', [[{
    auto self = olua_toobj<cocos2d::backend::ProgramState>(L, 1);
    olua_push_cppobj<cocos2d::backend::VertexLayout>(L, self->getVertexLayout().get());
    olua_addref(L, 1, "vertexLayout", -1, OLUA_MODE_SINGLE);
    return 1;
}]])
cls.func('setUniformVec2', [[{
    _cocos2d_backend_ProgramState_setUniform<cocos2d::Vec2>(L);
    return 0;
}]])
cls.func('setUniformVec3', [[{
    _cocos2d_backend_ProgramState_setUniform<cocos2d::Vec3>(L);
    return 0;
}]])
cls.func('setUniformVec4', [[{
    _cocos2d_backend_ProgramState_setUniform<cocos2d::Vec4>(L);
    return 0;
}]])
cls.func('setUniformMat4', [[{
    _cocos2d_backend_ProgramState_setUniform<cocos2d::Mat4>(L);
    return 0;
}]])
cls.func('setUniformInt', [[{
    _cocos2d_backend_ProgramState_setUniform<int>(L);
    return 0;
}]])
cls.func('setUniformFloat', [[{
    _cocos2d_backend_ProgramState_setUniform<float>(L);
    return 0;
}]])
cls.props [[
    program
    vertexTextureInfos
    fragmentTextureInfos
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::backend::Program'
cls.SUPERCLS = "cocos2d::Ref"
cls.funcs [[
    static cocos2d::backend::Program *getBuiltinProgram(cocos2d::backend::ProgramType type)
    cocos2d::backend::UniformLocation getUniformLocation(const std::string &uniform)
    cocos2d::backend::UniformLocation getUniformLocation(cocos2d::backend::Uniform name)
    int getAttributeLocation(const std::string &name)
    int getAttributeLocation(cocos2d::backend::Attribute name)
    int getMaxVertexLocation()
    int getMaxFragmentLocation()
    const std::unordered_map<std::string, AttributeBindInfo> getActiveAttributes()
    const std::string &getVertexShader()
    const std::string &getFragmentShader()
    cocos2d::backend::ProgramType getProgramType()
    std::size_t getUniformBufferSize(cocos2d::backend::ShaderStage stage)
    const cocos2d::backend::UniformInfo &getActiveUniformInfo(cocos2d::backend::ShaderStage stage, int location)
    const std::unordered_map<std::string, UniformInfo> &getAllActiveUniformInfo(cocos2d::backend::ShaderStage stage)
]]
cls.props [[
    maxVertexLocation
    maxFragmentLocation
    activeAttributes
    vertexShader
    fragmentShader
    programType
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::backend::TextureBackend'
cls.SUPERCLS = "cocos2d::Ref"
cls.funcs [[
    void updateSamplerDescriptor(const cocos2d::backend::SamplerDescriptor &sampler)
    void generateMipmaps()
    void updateTextureDescriptor(const cocos2d::backend::TextureDescriptor &descriptor)
    cocos2d::backend::PixelFormat getTextureFormat()
    cocos2d::backend::TextureUsage getTextureUsage()
    cocos2d::backend::TextureType getTextureType()
    bool hasMipmaps()
]]
cls.callback {
    FUNCS =  {
        'void getBytes(std::size_t x, std::size_t y, std::size_t width, std::size_t height, bool flipImage, @local std::function<void (const unsigned char *, std::size_t, std::size_t)> callback)'
    },
    TAG_MAKER = 'Bytes',
    TAG_MODE = 'OLUA_TAG_NEW',
    TAG_STORE = nil,
    TAG_SCOPE = 'once',
}
cls.props [[
    textureFormat
    textureUsage
    textureType
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::backend::Texture2DBackend'
cls.SUPERCLS = "cocos2d::backend::TextureBackend"
cls.funcs [[
    void updateData(uint8_t *data, std::size_t width, std::size_t height, std::size_t level)
    void updateCompressedData(uint8_t *data, std::size_t width, std::size_t height, std::size_t dataLen, std::size_t level)
    void updateSubData(std::size_t xoffset, std::size_t yoffset, std::size_t width, std::size_t height, std::size_t level, uint8_t *data)
    void updateCompressedSubData(std::size_t xoffset, std::size_t yoffset, std::size_t width, std::size_t height, std::size_t dataLen, std::size_t level, uint8_t *data)
    std::size_t getWidth()
    std::size_t getHeight()
]]
cls.props [[
    width
    height
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::backend::TextureCubemapBackend'
cls.SUPERCLS = "cocos2d::backend::TextureBackend"
cls.funcs [[
    void updateFaceData(cocos2d::backend::TextureCubeFace side, void *data)
]]
M.CLASSES[#M.CLASSES + 1] = cls

return M
