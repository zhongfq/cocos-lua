-- AUTO BUILD, DON'T MODIFY!

dofile "autobuild/cocos2d-backend-types.lua"

NAME = "cocos2d_backend"
PATH = "../../frameworks/libxgame/src/lua-bindings"
HEADERS = [[
    #include "lua-bindings/lua_conv.h"
    #include "lua-bindings/lua_conv_manual.h"
    #include "cocos2d.h"
    #include "cclua/xlua.h"
]]
CHUNK = nil


typeconf 'cocos2d::backend::BufferUsage'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('STATIC', 'cocos2d::backend::BufferUsage::STATIC')
    .enum('DYNAMIC', 'cocos2d::backend::BufferUsage::DYNAMIC')

typeconf 'cocos2d::backend::BufferType'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('VERTEX', 'cocos2d::backend::BufferType::VERTEX')
    .enum('INDEX', 'cocos2d::backend::BufferType::INDEX')

typeconf 'cocos2d::backend::ShaderStage'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('VERTEX', 'cocos2d::backend::ShaderStage::VERTEX')
    .enum('FRAGMENT', 'cocos2d::backend::ShaderStage::FRAGMENT')
    .enum('VERTEX_AND_FRAGMENT', 'cocos2d::backend::ShaderStage::VERTEX_AND_FRAGMENT')

typeconf 'cocos2d::backend::VertexFormat'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('FLOAT4', 'cocos2d::backend::VertexFormat::FLOAT4')
    .enum('FLOAT3', 'cocos2d::backend::VertexFormat::FLOAT3')
    .enum('FLOAT2', 'cocos2d::backend::VertexFormat::FLOAT2')
    .enum('FLOAT', 'cocos2d::backend::VertexFormat::FLOAT')
    .enum('INT4', 'cocos2d::backend::VertexFormat::INT4')
    .enum('INT3', 'cocos2d::backend::VertexFormat::INT3')
    .enum('INT2', 'cocos2d::backend::VertexFormat::INT2')
    .enum('INT', 'cocos2d::backend::VertexFormat::INT')
    .enum('USHORT4', 'cocos2d::backend::VertexFormat::USHORT4')
    .enum('USHORT2', 'cocos2d::backend::VertexFormat::USHORT2')
    .enum('UBYTE4', 'cocos2d::backend::VertexFormat::UBYTE4')

typeconf 'cocos2d::backend::PixelFormat'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('AUTO', 'cocos2d::backend::PixelFormat::AUTO')
    .enum('BGRA8888', 'cocos2d::backend::PixelFormat::BGRA8888')
    .enum('RGBA8888', 'cocos2d::backend::PixelFormat::RGBA8888')
    .enum('RGB888', 'cocos2d::backend::PixelFormat::RGB888')
    .enum('RGB565', 'cocos2d::backend::PixelFormat::RGB565')
    .enum('A8', 'cocos2d::backend::PixelFormat::A8')
    .enum('I8', 'cocos2d::backend::PixelFormat::I8')
    .enum('AI88', 'cocos2d::backend::PixelFormat::AI88')
    .enum('RGBA4444', 'cocos2d::backend::PixelFormat::RGBA4444')
    .enum('RGB5A1', 'cocos2d::backend::PixelFormat::RGB5A1')
    .enum('PVRTC4', 'cocos2d::backend::PixelFormat::PVRTC4')
    .enum('PVRTC4A', 'cocos2d::backend::PixelFormat::PVRTC4A')
    .enum('PVRTC2', 'cocos2d::backend::PixelFormat::PVRTC2')
    .enum('PVRTC2A', 'cocos2d::backend::PixelFormat::PVRTC2A')
    .enum('ETC', 'cocos2d::backend::PixelFormat::ETC')
    .enum('S3TC_DXT1', 'cocos2d::backend::PixelFormat::S3TC_DXT1')
    .enum('S3TC_DXT3', 'cocos2d::backend::PixelFormat::S3TC_DXT3')
    .enum('S3TC_DXT5', 'cocos2d::backend::PixelFormat::S3TC_DXT5')
    .enum('ATC_RGB', 'cocos2d::backend::PixelFormat::ATC_RGB')
    .enum('ATC_EXPLICIT_ALPHA', 'cocos2d::backend::PixelFormat::ATC_EXPLICIT_ALPHA')
    .enum('ATC_INTERPOLATED_ALPHA', 'cocos2d::backend::PixelFormat::ATC_INTERPOLATED_ALPHA')
    .enum('MTL_B5G6R5', 'cocos2d::backend::PixelFormat::MTL_B5G6R5')
    .enum('MTL_BGR5A1', 'cocos2d::backend::PixelFormat::MTL_BGR5A1')
    .enum('MTL_ABGR4', 'cocos2d::backend::PixelFormat::MTL_ABGR4')
    .enum('D24S8', 'cocos2d::backend::PixelFormat::D24S8')
    .enum('DEFAULT', 'cocos2d::backend::PixelFormat::DEFAULT')
    .enum('NONE', 'cocos2d::backend::PixelFormat::NONE')

typeconf 'cocos2d::backend::TextureUsage'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('READ', 'cocos2d::backend::TextureUsage::READ')
    .enum('WRITE', 'cocos2d::backend::TextureUsage::WRITE')
    .enum('RENDER_TARGET', 'cocos2d::backend::TextureUsage::RENDER_TARGET')

typeconf 'cocos2d::backend::IndexFormat'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('U_SHORT', 'cocos2d::backend::IndexFormat::U_SHORT')
    .enum('U_INT', 'cocos2d::backend::IndexFormat::U_INT')

typeconf 'cocos2d::backend::VertexStepMode'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('VERTEX', 'cocos2d::backend::VertexStepMode::VERTEX')
    .enum('INSTANCE', 'cocos2d::backend::VertexStepMode::INSTANCE')

typeconf 'cocos2d::backend::PrimitiveType'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('POINT', 'cocos2d::backend::PrimitiveType::POINT')
    .enum('LINE', 'cocos2d::backend::PrimitiveType::LINE')
    .enum('LINE_STRIP', 'cocos2d::backend::PrimitiveType::LINE_STRIP')
    .enum('TRIANGLE', 'cocos2d::backend::PrimitiveType::TRIANGLE')
    .enum('TRIANGLE_STRIP', 'cocos2d::backend::PrimitiveType::TRIANGLE_STRIP')

typeconf 'cocos2d::backend::TextureType'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('TEXTURE_2D', 'cocos2d::backend::TextureType::TEXTURE_2D')
    .enum('TEXTURE_CUBE', 'cocos2d::backend::TextureType::TEXTURE_CUBE')

typeconf 'cocos2d::backend::SamplerAddressMode'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('REPEAT', 'cocos2d::backend::SamplerAddressMode::REPEAT')
    .enum('MIRROR_REPEAT', 'cocos2d::backend::SamplerAddressMode::MIRROR_REPEAT')
    .enum('CLAMP_TO_EDGE', 'cocos2d::backend::SamplerAddressMode::CLAMP_TO_EDGE')
    .enum('DONT_CARE', 'cocos2d::backend::SamplerAddressMode::DONT_CARE')

typeconf 'cocos2d::backend::SamplerFilter'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('NEAREST', 'cocos2d::backend::SamplerFilter::NEAREST')
    .enum('NEAREST_MIPMAP_NEAREST', 'cocos2d::backend::SamplerFilter::NEAREST_MIPMAP_NEAREST')
    .enum('NEAREST_MIPMAP_LINEAR', 'cocos2d::backend::SamplerFilter::NEAREST_MIPMAP_LINEAR')
    .enum('LINEAR', 'cocos2d::backend::SamplerFilter::LINEAR')
    .enum('LINEAR_MIPMAP_LINEAR', 'cocos2d::backend::SamplerFilter::LINEAR_MIPMAP_LINEAR')
    .enum('LINEAR_MIPMAP_NEAREST', 'cocos2d::backend::SamplerFilter::LINEAR_MIPMAP_NEAREST')
    .enum('DONT_CARE', 'cocos2d::backend::SamplerFilter::DONT_CARE')

typeconf 'cocos2d::backend::StencilOperation'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('KEEP', 'cocos2d::backend::StencilOperation::KEEP')
    .enum('ZERO', 'cocos2d::backend::StencilOperation::ZERO')
    .enum('REPLACE', 'cocos2d::backend::StencilOperation::REPLACE')
    .enum('INVERT', 'cocos2d::backend::StencilOperation::INVERT')
    .enum('INCREMENT_WRAP', 'cocos2d::backend::StencilOperation::INCREMENT_WRAP')
    .enum('DECREMENT_WRAP', 'cocos2d::backend::StencilOperation::DECREMENT_WRAP')

typeconf 'cocos2d::backend::CompareFunction'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('NEVER', 'cocos2d::backend::CompareFunction::NEVER')
    .enum('LESS', 'cocos2d::backend::CompareFunction::LESS')
    .enum('LESS_EQUAL', 'cocos2d::backend::CompareFunction::LESS_EQUAL')
    .enum('GREATER', 'cocos2d::backend::CompareFunction::GREATER')
    .enum('GREATER_EQUAL', 'cocos2d::backend::CompareFunction::GREATER_EQUAL')
    .enum('EQUAL', 'cocos2d::backend::CompareFunction::EQUAL')
    .enum('NOT_EQUAL', 'cocos2d::backend::CompareFunction::NOT_EQUAL')
    .enum('ALWAYS', 'cocos2d::backend::CompareFunction::ALWAYS')

typeconf 'cocos2d::backend::BlendOperation'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('ADD', 'cocos2d::backend::BlendOperation::ADD')
    .enum('SUBTRACT', 'cocos2d::backend::BlendOperation::SUBTRACT')
    .enum('RESERVE_SUBTRACT', 'cocos2d::backend::BlendOperation::RESERVE_SUBTRACT')

typeconf 'cocos2d::backend::BlendFactor'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('ZERO', 'cocos2d::backend::BlendFactor::ZERO')
    .enum('ONE', 'cocos2d::backend::BlendFactor::ONE')
    .enum('SRC_COLOR', 'cocos2d::backend::BlendFactor::SRC_COLOR')
    .enum('ONE_MINUS_SRC_COLOR', 'cocos2d::backend::BlendFactor::ONE_MINUS_SRC_COLOR')
    .enum('SRC_ALPHA', 'cocos2d::backend::BlendFactor::SRC_ALPHA')
    .enum('ONE_MINUS_SRC_ALPHA', 'cocos2d::backend::BlendFactor::ONE_MINUS_SRC_ALPHA')
    .enum('DST_COLOR', 'cocos2d::backend::BlendFactor::DST_COLOR')
    .enum('ONE_MINUS_DST_COLOR', 'cocos2d::backend::BlendFactor::ONE_MINUS_DST_COLOR')
    .enum('DST_ALPHA', 'cocos2d::backend::BlendFactor::DST_ALPHA')
    .enum('ONE_MINUS_DST_ALPHA', 'cocos2d::backend::BlendFactor::ONE_MINUS_DST_ALPHA')
    .enum('CONSTANT_ALPHA', 'cocos2d::backend::BlendFactor::CONSTANT_ALPHA')
    .enum('SRC_ALPHA_SATURATE', 'cocos2d::backend::BlendFactor::SRC_ALPHA_SATURATE')
    .enum('ONE_MINUS_CONSTANT_ALPHA', 'cocos2d::backend::BlendFactor::ONE_MINUS_CONSTANT_ALPHA')
    .enum('BLEND_CLOLOR', 'cocos2d::backend::BlendFactor::BLEND_CLOLOR')

typeconf 'cocos2d::backend::ColorWriteMask'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('NONE', 'cocos2d::backend::ColorWriteMask::NONE')
    .enum('RED', 'cocos2d::backend::ColorWriteMask::RED')
    .enum('GREEN', 'cocos2d::backend::ColorWriteMask::GREEN')
    .enum('BLUE', 'cocos2d::backend::ColorWriteMask::BLUE')
    .enum('ALPHA', 'cocos2d::backend::ColorWriteMask::ALPHA')
    .enum('ALL', 'cocos2d::backend::ColorWriteMask::ALL')

typeconf 'cocos2d::backend::CullMode'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('NONE', 'cocos2d::backend::CullMode::NONE')
    .enum('BACK', 'cocos2d::backend::CullMode::BACK')
    .enum('FRONT', 'cocos2d::backend::CullMode::FRONT')

typeconf 'cocos2d::backend::Winding'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('CLOCK_WISE', 'cocos2d::backend::Winding::CLOCK_WISE')
    .enum('COUNTER_CLOCK_WISE', 'cocos2d::backend::Winding::COUNTER_CLOCK_WISE')

typeconf 'cocos2d::backend::TextureCubeFace'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('POSITIVE_X', 'cocos2d::backend::TextureCubeFace::POSITIVE_X')
    .enum('NEGATIVE_X', 'cocos2d::backend::TextureCubeFace::NEGATIVE_X')
    .enum('POSITIVE_Y', 'cocos2d::backend::TextureCubeFace::POSITIVE_Y')
    .enum('NEGATIVE_Y', 'cocos2d::backend::TextureCubeFace::NEGATIVE_Y')
    .enum('POSITIVE_Z', 'cocos2d::backend::TextureCubeFace::POSITIVE_Z')
    .enum('NEGATIVE_Z', 'cocos2d::backend::TextureCubeFace::NEGATIVE_Z')

typeconf 'cocos2d::backend::ProgramType'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('POSITION_COLOR_LENGTH_TEXTURE', 'cocos2d::backend::ProgramType::POSITION_COLOR_LENGTH_TEXTURE')
    .enum('POSITION_COLOR_TEXTURE_AS_POINTSIZE', 'cocos2d::backend::ProgramType::POSITION_COLOR_TEXTURE_AS_POINTSIZE')
    .enum('POSITION_COLOR', 'cocos2d::backend::ProgramType::POSITION_COLOR')
    .enum('POSITION', 'cocos2d::backend::ProgramType::POSITION')
    .enum('POSITION_UCOLOR', 'cocos2d::backend::ProgramType::POSITION_UCOLOR')
    .enum('POSITION_TEXTURE', 'cocos2d::backend::ProgramType::POSITION_TEXTURE')
    .enum('POSITION_TEXTURE_COLOR', 'cocos2d::backend::ProgramType::POSITION_TEXTURE_COLOR')
    .enum('POSITION_TEXTURE_COLOR_ALPHA_TEST', 'cocos2d::backend::ProgramType::POSITION_TEXTURE_COLOR_ALPHA_TEST')
    .enum('LABEL_NORMAL', 'cocos2d::backend::ProgramType::LABEL_NORMAL')
    .enum('LABLE_OUTLINE', 'cocos2d::backend::ProgramType::LABLE_OUTLINE')
    .enum('LABLE_DISTANCEFIELD_GLOW', 'cocos2d::backend::ProgramType::LABLE_DISTANCEFIELD_GLOW')
    .enum('LABEL_DISTANCE_NORMAL', 'cocos2d::backend::ProgramType::LABEL_DISTANCE_NORMAL')
    .enum('LAYER_RADIA_GRADIENT', 'cocos2d::backend::ProgramType::LAYER_RADIA_GRADIENT')
    .enum('ETC1', 'cocos2d::backend::ProgramType::ETC1')
    .enum('ETC1_GRAY', 'cocos2d::backend::ProgramType::ETC1_GRAY')
    .enum('GRAY_SCALE', 'cocos2d::backend::ProgramType::GRAY_SCALE')
    .enum('CAMERA_CLEAR', 'cocos2d::backend::ProgramType::CAMERA_CLEAR')
    .enum('TERRAIN_3D', 'cocos2d::backend::ProgramType::TERRAIN_3D')
    .enum('LINE_COLOR_3D', 'cocos2d::backend::ProgramType::LINE_COLOR_3D')
    .enum('SKYBOX_3D', 'cocos2d::backend::ProgramType::SKYBOX_3D')
    .enum('SKINPOSITION_TEXTURE_3D', 'cocos2d::backend::ProgramType::SKINPOSITION_TEXTURE_3D')
    .enum('SKINPOSITION_NORMAL_TEXTURE_3D', 'cocos2d::backend::ProgramType::SKINPOSITION_NORMAL_TEXTURE_3D')
    .enum('POSITION_NORMAL_TEXTURE_3D', 'cocos2d::backend::ProgramType::POSITION_NORMAL_TEXTURE_3D')
    .enum('POSITION_NORMAL_3D', 'cocos2d::backend::ProgramType::POSITION_NORMAL_3D')
    .enum('POSITION_TEXTURE_3D', 'cocos2d::backend::ProgramType::POSITION_TEXTURE_3D')
    .enum('POSITION_3D', 'cocos2d::backend::ProgramType::POSITION_3D')
    .enum('POSITION_BUMPEDNORMAL_TEXTURE_3D', 'cocos2d::backend::ProgramType::POSITION_BUMPEDNORMAL_TEXTURE_3D')
    .enum('SKINPOSITION_BUMPEDNORMAL_TEXTURE_3D', 'cocos2d::backend::ProgramType::SKINPOSITION_BUMPEDNORMAL_TEXTURE_3D')
    .enum('PARTICLE_TEXTURE_3D', 'cocos2d::backend::ProgramType::PARTICLE_TEXTURE_3D')
    .enum('PARTICLE_COLOR_3D', 'cocos2d::backend::ProgramType::PARTICLE_COLOR_3D')
    .enum('CUSTOM_PROGRAM', 'cocos2d::backend::ProgramType::CUSTOM_PROGRAM')

typeconf 'cocos2d::backend::Uniform'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('MVP_MATRIX', 'cocos2d::backend::Uniform::MVP_MATRIX')
    .enum('TEXTURE', 'cocos2d::backend::Uniform::TEXTURE')
    .enum('TEXTURE1', 'cocos2d::backend::Uniform::TEXTURE1')
    .enum('TEXTURE2', 'cocos2d::backend::Uniform::TEXTURE2')
    .enum('TEXTURE3', 'cocos2d::backend::Uniform::TEXTURE3')
    .enum('TEXT_COLOR', 'cocos2d::backend::Uniform::TEXT_COLOR')
    .enum('EFFECT_TYPE', 'cocos2d::backend::Uniform::EFFECT_TYPE')
    .enum('EFFECT_COLOR', 'cocos2d::backend::Uniform::EFFECT_COLOR')
    .enum('UNIFORM_MAX', 'cocos2d::backend::Uniform::UNIFORM_MAX')

typeconf 'cocos2d::backend::Attribute'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('POSITION', 'cocos2d::backend::Attribute::POSITION')
    .enum('COLOR', 'cocos2d::backend::Attribute::COLOR')
    .enum('TEXCOORD', 'cocos2d::backend::Attribute::TEXCOORD')
    .enum('TEXCOORD1', 'cocos2d::backend::Attribute::TEXCOORD1')
    .enum('TEXCOORD2', 'cocos2d::backend::Attribute::TEXCOORD2')
    .enum('TEXCOORD3', 'cocos2d::backend::Attribute::TEXCOORD3')
    .enum('ATTRIBUTE_MAX', 'cocos2d::backend::Attribute::ATTRIBUTE_MAX')

typeconf 'cocos2d::backend::FeatureType'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('ETC1', 'cocos2d::backend::FeatureType::ETC1')
    .enum('S3TC', 'cocos2d::backend::FeatureType::S3TC')
    .enum('AMD_COMPRESSED_ATC', 'cocos2d::backend::FeatureType::AMD_COMPRESSED_ATC')
    .enum('PVRTC', 'cocos2d::backend::FeatureType::PVRTC')
    .enum('IMG_FORMAT_BGRA8888', 'cocos2d::backend::FeatureType::IMG_FORMAT_BGRA8888')
    .enum('DISCARD_FRAMEBUFFER', 'cocos2d::backend::FeatureType::DISCARD_FRAMEBUFFER')
    .enum('PACKED_DEPTH_STENCIL', 'cocos2d::backend::FeatureType::PACKED_DEPTH_STENCIL')
    .enum('VAO', 'cocos2d::backend::FeatureType::VAO')
    .enum('MAPBUFFER', 'cocos2d::backend::FeatureType::MAPBUFFER')
    .enum('DEPTH24', 'cocos2d::backend::FeatureType::DEPTH24')
    .enum('ASTC', 'cocos2d::backend::FeatureType::ASTC')

typeconf 'cocos2d::backend::Buffer'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'void updateData(void *data, std::size_t size)')
    .func(nil, 'void updateSubData(void *data, std::size_t offset, std::size_t size)')
    .func(nil, 'void usingDefaultStoredData(bool needDefaultStoredData)')
    .func(nil, 'std::size_t getSize()')
    .prop('size', nil, nil)

typeconf 'cocos2d::backend::RenderPipeline'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)

typeconf 'cocos2d::backend::DepthStencilState'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)

typeconf 'cocos2d::backend::VertexLayout'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'VertexLayout()')
    .func(nil, 'void setAttribute(const std::string &name, std::size_t index, cocos2d::backend::VertexFormat format, std::size_t offset, bool needToBeNormallized)')
    .func(nil, 'void setLayout(std::size_t stride)')
    .func(nil, 'std::size_t getStride()')
    .func(nil, 'cocos2d::backend::VertexStepMode getVertexStepMode()')
    .func(nil, 'const std::unordered_map<std::string, Attribute> &getAttributes()')
    .func(nil, 'bool isValid()')
    .prop('stride', nil, nil)
    .prop('vertexStepMode', nil, nil)
    .prop('attributes', nil, nil)
    .prop('valid', nil, nil)

typeconf 'cocos2d::backend::CommandBuffer'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'void beginFrame()')
    .func(nil, 'void setRenderPipeline(cocos2d::backend::RenderPipeline *renderPipeline)')
    .func(nil, 'void setViewport(int x, int y, unsigned int w, unsigned int h)')
    .func(nil, 'void setCullMode(cocos2d::backend::CullMode mode)')
    .func(nil, 'void setWinding(cocos2d::backend::Winding winding)')
    .func(nil, 'void setVertexBuffer(cocos2d::backend::Buffer *buffer)')
    .func(nil, 'void setProgramState(cocos2d::backend::ProgramState *programState)')
    .func(nil, 'void setIndexBuffer(cocos2d::backend::Buffer *buffer)')
    .func(nil, 'void drawArrays(cocos2d::backend::PrimitiveType primitiveType, std::size_t start, std::size_t count)')
    .func(nil, 'void drawElements(cocos2d::backend::PrimitiveType primitiveType, cocos2d::backend::IndexFormat indexType, std::size_t count, std::size_t offset)')
    .func(nil, 'void endRenderPass()')
    .func(nil, 'void endFrame()')
    .func(nil, 'void setLineWidth(float lineWidth)')
    .func(nil, 'void setScissorRect(bool isEnabled, float x, float y, float width, float height)')
    .func(nil, 'void setDepthStencilState(cocos2d::backend::DepthStencilState *depthStencilState)')
    .func(nil, 'void setStencilReferenceValue(unsigned int value)', 'void setStencilReferenceValue(unsigned int frontRef, unsigned int backRef)')
    .callback {
        FUNCS =  {
            'void captureScreen(@local std::function<void (const unsigned char *, int, int)> callback)'
        },
        TAG_MAKER = 'captureScreen',
        TAG_MODE = 'OLUA_TAG_NEW',
        TAG_STORE = nil,
        TAG_SCOPE = 'once',
    }

typeconf 'cocos2d::backend::Device'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::backend::Device *getInstance()')
    .func(nil, 'cocos2d::backend::CommandBuffer *newCommandBuffer()')
    .func(nil, 'cocos2d::backend::Buffer *newBuffer(size_t size, cocos2d::backend::BufferType type, cocos2d::backend::BufferUsage usage)')
    .func(nil, 'cocos2d::backend::TextureBackend *newTexture(const cocos2d::backend::TextureDescriptor &descriptor)')
    .func(nil, 'cocos2d::backend::DepthStencilState *createDepthStencilState(const cocos2d::backend::DepthStencilDescriptor &descriptor)')
    .func(nil, 'cocos2d::backend::RenderPipeline *newRenderPipeline()')
    .func(nil, 'void setFrameBufferOnly(bool frameBufferOnly)')
    .func(nil, 'cocos2d::backend::Program *newProgram(const std::string &vertexShader, const std::string &fragmentShader)')
    .func(nil, 'cocos2d::backend::DeviceInfo *getDeviceInfo()')
    .prop('instance', nil, nil)
    .prop('deviceInfo', nil, nil)
    .insert('newProgram', {
        BEFORE = nil,
        AFTER = 'ret->autorelease();',
        CALLBACK_BEFORE = nil,
        CALLBACK_AFTER = nil,
    })
    .insert('newRenderPipeline', {
        BEFORE = nil,
        AFTER = 'ret->autorelease();',
        CALLBACK_BEFORE = nil,
        CALLBACK_AFTER = nil,
    })
    .insert('newTexture', {
        BEFORE = nil,
        AFTER = 'ret->autorelease();',
        CALLBACK_BEFORE = nil,
        CALLBACK_AFTER = nil,
    })
    .insert('newBuffer', {
        BEFORE = nil,
        AFTER = 'ret->autorelease();',
        CALLBACK_BEFORE = nil,
        CALLBACK_AFTER = nil,
    })
    .insert('newCommandBuffer', {
        BEFORE = nil,
        AFTER = 'ret->autorelease();',
        CALLBACK_BEFORE = nil,
        CALLBACK_AFTER = nil,
    })

typeconf 'cocos2d::backend::DeviceInfo'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'bool init()')
    .func(nil, 'const char *getVendor()')
    .func(nil, 'const char *getRenderer()')
    .func(nil, 'const char *getVersion()')
    .func(nil, 'const char *getExtension()')
    .func(nil, 'bool checkForFeatureSupported(cocos2d::backend::FeatureType feature)')
    .func(nil, 'int getMaxTextureSize()')
    .func(nil, 'int getMaxAttributes()')
    .func(nil, 'int getMaxTextureUnits()')
    .func(nil, 'int getMaxSamplesAllowed()')
    .prop('vendor', nil, nil)
    .prop('renderer', nil, nil)
    .prop('version', nil, nil)
    .prop('extension', nil, nil)
    .prop('maxTextureSize', nil, nil)
    .prop('maxAttributes', nil, nil)
    .prop('maxTextureUnits', nil, nil)
    .prop('maxSamplesAllowed', nil, nil)

typeconf 'cocos2d::backend::ShaderCache'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::backend::ShaderCache *getInstance()')
    .func(nil, 'static void destroyInstance()')
    .func(nil, 'static cocos2d::backend::ShaderModule *newVertexShaderModule(const std::string &shaderSource)')
    .func(nil, 'static cocos2d::backend::ShaderModule *newFragmentShaderModule(const std::string &shaderSource)')
    .func(nil, 'void removeUnusedShader()')
    .prop('instance', nil, nil)

typeconf 'cocos2d::backend::ShaderModule'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'cocos2d::backend::ShaderStage getShaderStage()')
    .func(nil, 'std::size_t getHashValue()')
    .prop('shaderStage', nil, nil)
    .prop('hashValue', nil, nil)

typeconf 'cocos2d::backend::ProgramCache'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::backend::ProgramCache *getInstance()')
    .func(nil, 'static void destroyInstance()')
    .func(nil, 'cocos2d::backend::Program *getBuiltinProgram(cocos2d::backend::ProgramType type)')
    .func(nil, 'void removeProgram(cocos2d::backend::Program *program)')
    .func(nil, 'void removeUnusedProgram()')
    .func(nil, 'void removeAllPrograms()')
    .func(nil, 'void addCustomProgram(const std::string &key, cocos2d::backend::Program *program)')
    .func(nil, 'cocos2d::backend::Program *getCustomProgram(const std::string &key)')
    .prop('instance', nil, nil)

typeconf 'cocos2d::backend::ProgramState'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk([[
        static inline void olua_check_value(lua_State *L, int idx, cocos2d::Vec2 *value)
        {
            olua_check_cocos2d_Vec2(L, idx, value);
        }

        static inline void olua_check_value(lua_State *L, int idx, cocos2d::Vec3 *value)
        {
            olua_check_cocos2d_Vec3(L, idx, value);
        }

        static inline void olua_check_value(lua_State *L, int idx, cocos2d::Vec4 *value)
        {
            olua_check_cocos2d_Vec4(L, idx, value);
        }

        static inline void olua_check_value(lua_State *L, int idx, cocos2d::Mat4 *value)
        {
            olua_check_cocos2d_Mat4(L, idx, value);
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
                olua_check_cocos2d_backend_UniformLocation(L, 2, &location);
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
                olua_check_cocos2d_backend_UniformLocation(L, 2, &location);
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
    ]])
    .require(nil)
    .func('getVertexLayout', [[
        {
            auto self = olua_toobj<cocos2d::backend::ProgramState>(L, 1);
            olua_push_cppobj<cocos2d::backend::VertexLayout>(L, self->getVertexLayout().get());
            olua_addref(L, 1, "vertexLayout", -1, OLUA_MODE_SINGLE);
            return 1;
        }
    ]])
    .func('setUniformVec2', [[
        {
            _cocos2d_backend_ProgramState_setUniform<cocos2d::Vec2>(L);
            return 0;
        }
    ]])
    .func('setUniformVec3', [[
        {
            _cocos2d_backend_ProgramState_setUniform<cocos2d::Vec3>(L);
            return 0;
        }
    ]])
    .func('setUniformVec4', [[
        {
            _cocos2d_backend_ProgramState_setUniform<cocos2d::Vec4>(L);
            return 0;
        }
    ]])
    .func('setUniformMat4', [[
        {
            _cocos2d_backend_ProgramState_setUniform<cocos2d::Mat4>(L);
            return 0;
        }
    ]])
    .func('setUniformInt', [[
        {
            _cocos2d_backend_ProgramState_setUniform<int>(L);
            return 0;
        }
    ]])
    .func('setUniformFloat', [[
        {
            _cocos2d_backend_ProgramState_setUniform<float>(L);
            return 0;
        }
    ]])
    .func('setUniformVec2v', [[
        {
            _cocos2d_backend_ProgramState_setUniformv<cocos2d::Vec2>(L);
            return 0;
        }
    ]])
    .func('setUniformVec3v', [[
        {
            _cocos2d_backend_ProgramState_setUniformv<cocos2d::Vec3>(L);
            return 0;
        }
    ]])
    .func('setUniformVec4v', [[
        {
            _cocos2d_backend_ProgramState_setUniformv<cocos2d::Vec4>(L);
            return 0;
        }
    ]])
    .func('setUniformMat4v', [[
        {
            _cocos2d_backend_ProgramState_setUniformv<cocos2d::Mat4>(L);
            return 0;
        }
    ]])
    .func('setUniformIntv', [[
        {
            _cocos2d_backend_ProgramState_setUniformv<int>(L);
            return 0;
        }
    ]])
    .func('setUniformFloatv', [[
        {
            _cocos2d_backend_ProgramState_setUniformv<float>(L);
            return 0;
        }
    ]])
    .func(nil, 'ProgramState(cocos2d::backend::Program *program)')
    .func(nil, 'cocos2d::backend::ProgramState *clone()')
    .func(nil, 'cocos2d::backend::Program *getProgram()')
    .func(nil, 'void setUniform(const cocos2d::backend::UniformLocation &uniformLocation, const void *data, std::size_t size)')
    .func(nil, 'cocos2d::backend::UniformLocation getUniformLocation(const std::string &uniform)', 'cocos2d::backend::UniformLocation getUniformLocation(cocos2d::backend::Uniform name)')
    .func(nil, 'int getAttributeLocation(const std::string &name)', 'int getAttributeLocation(cocos2d::backend::Attribute name)')
    .func(nil, 'void setTexture(const cocos2d::backend::UniformLocation &uniformLocation, uint32_t slot, cocos2d::backend::TextureBackend *texture)')
    .func(nil, 'void setTextureArray(const cocos2d::backend::UniformLocation &uniformLocation, const std::vector<uint32_t> &slots, const std::vector<backend::TextureBackend *> textures)')
    .func(nil, 'const std::unordered_map<int, TextureInfo> &getVertexTextureInfos()')
    .func(nil, 'const std::unordered_map<int, TextureInfo> &getFragmentTextureInfos()')
    .func(nil, 'void setParameterAutoBinding(const std::string &uniformName, const std::string &autoBinding)')
    .prop('program', nil, nil)
    .prop('vertexTextureInfos', nil, nil)
    .prop('fragmentTextureInfos', nil, nil)

typeconf 'cocos2d::backend::Program'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::backend::Program *getBuiltinProgram(cocos2d::backend::ProgramType type)')
    .func(nil, 'cocos2d::backend::UniformLocation getUniformLocation(const std::string &uniform)', 'cocos2d::backend::UniformLocation getUniformLocation(cocos2d::backend::Uniform name)')
    .func(nil, 'int getAttributeLocation(const std::string &name)', 'int getAttributeLocation(cocos2d::backend::Attribute name)')
    .func(nil, 'int getMaxVertexLocation()')
    .func(nil, 'int getMaxFragmentLocation()')
    .func(nil, 'const std::unordered_map<std::string, AttributeBindInfo> getActiveAttributes()')
    .func(nil, 'const std::string &getVertexShader()')
    .func(nil, 'const std::string &getFragmentShader()')
    .func(nil, 'cocos2d::backend::ProgramType getProgramType()')
    .func(nil, 'std::size_t getUniformBufferSize(cocos2d::backend::ShaderStage stage)')
    .func(nil, 'const cocos2d::backend::UniformInfo &getActiveUniformInfo(cocos2d::backend::ShaderStage stage, int location)')
    .func(nil, 'const std::unordered_map<std::string, UniformInfo> &getAllActiveUniformInfo(cocos2d::backend::ShaderStage stage)')
    .prop('maxVertexLocation', nil, nil)
    .prop('maxFragmentLocation', nil, nil)
    .prop('activeAttributes', nil, nil)
    .prop('vertexShader', nil, nil)
    .prop('fragmentShader', nil, nil)
    .prop('programType', nil, nil)

typeconf 'cocos2d::backend::TextureBackend'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'void updateSamplerDescriptor(const cocos2d::backend::SamplerDescriptor &sampler)')
    .func(nil, 'void generateMipmaps()')
    .func(nil, 'void updateTextureDescriptor(const cocos2d::backend::TextureDescriptor &descriptor)')
    .func(nil, 'cocos2d::backend::PixelFormat getTextureFormat()')
    .func(nil, 'cocos2d::backend::TextureUsage getTextureUsage()')
    .func(nil, 'cocos2d::backend::TextureType getTextureType()')
    .func(nil, 'bool hasMipmaps()')
    .callback {
        FUNCS =  {
            'void getBytes(std::size_t x, std::size_t y, std::size_t width, std::size_t height, bool flipImage, @local std::function<void (const unsigned char *, std::size_t, std::size_t)> callback)'
        },
        TAG_MAKER = 'Bytes',
        TAG_MODE = 'OLUA_TAG_NEW',
        TAG_STORE = nil,
        TAG_SCOPE = 'once',
    }
    .prop('textureFormat', nil, nil)
    .prop('textureUsage', nil, nil)
    .prop('textureType', nil, nil)

typeconf 'cocos2d::backend::Texture2DBackend'
    .supercls('cocos2d::backend::TextureBackend')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'void updateData(uint8_t *data, std::size_t width, std::size_t height, std::size_t level)')
    .func(nil, 'void updateCompressedData(uint8_t *data, std::size_t width, std::size_t height, std::size_t dataLen, std::size_t level)')
    .func(nil, 'void updateSubData(std::size_t xoffset, std::size_t yoffset, std::size_t width, std::size_t height, std::size_t level, uint8_t *data)')
    .func(nil, 'void updateCompressedSubData(std::size_t xoffset, std::size_t yoffset, std::size_t width, std::size_t height, std::size_t dataLen, std::size_t level, uint8_t *data)')
    .func(nil, 'std::size_t getWidth()')
    .func(nil, 'std::size_t getHeight()')
    .prop('width', nil, nil)
    .prop('height', nil, nil)

typeconf 'cocos2d::backend::TextureCubemapBackend'
    .supercls('cocos2d::backend::TextureBackend')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'void updateFaceData(cocos2d::backend::TextureCubeFace side, void *data)')
