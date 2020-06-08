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
cls.enums [[
    STATIC
    DYNAMIC
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::backend::BufferType'
cls.enums [[
    VERTEX
    INDEX
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::backend::ShaderStage'
cls.enums [[
    VERTEX
    FRAGMENT
    VERTEX_AND_FRAGMENT
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::backend::VertexFormat'
cls.enums [[
    FLOAT4
    FLOAT3
    FLOAT2
    FLOAT
    INT4
    INT3
    INT2
    INT
    USHORT4
    USHORT2
    UBYTE4
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::backend::PixelFormat'
cls.enums [[
    AUTO
    BGRA8888
    RGBA8888
    RGB888
    RGB565
    A8
    I8
    AI88
    RGBA4444
    RGB5A1
    PVRTC4
    PVRTC4A
    PVRTC2
    PVRTC2A
    ETC
    S3TC_DXT1
    S3TC_DXT3
    S3TC_DXT5
    ATC_RGB
    ATC_EXPLICIT_ALPHA
    ATC_INTERPOLATED_ALPHA
    MTL_B5G6R5
    MTL_BGR5A1
    MTL_ABGR4
    D24S8
    DEFAULT
    NONE
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::backend::TextureUsage'
cls.enums [[
    READ
    WRITE
    RENDER_TARGET
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::backend::IndexFormat'
cls.enums [[
    U_SHORT
    U_INT
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::backend::VertexStepMode'
cls.enums [[
    VERTEX
    INSTANCE
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::backend::PrimitiveType'
cls.enums [[
    POINT
    LINE
    LINE_STRIP
    TRIANGLE
    TRIANGLE_STRIP
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::backend::TextureType'
cls.enums [[
    TEXTURE_2D
    TEXTURE_CUBE
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::backend::SamplerAddressMode'
cls.enums [[
    REPEAT
    MIRROR_REPEAT
    CLAMP_TO_EDGE
    DONT_CARE
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::backend::SamplerFilter'
cls.enums [[
    NEAREST
    NEAREST_MIPMAP_NEAREST
    NEAREST_MIPMAP_LINEAR
    LINEAR
    LINEAR_MIPMAP_LINEAR
    LINEAR_MIPMAP_NEAREST
    DONT_CARE
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::backend::StencilOperation'
cls.enums [[
    KEEP
    ZERO
    REPLACE
    INVERT
    INCREMENT_WRAP
    DECREMENT_WRAP
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::backend::CompareFunction'
cls.enums [[
    NEVER
    LESS
    LESS_EQUAL
    GREATER
    GREATER_EQUAL
    EQUAL
    NOT_EQUAL
    ALWAYS
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::backend::BlendOperation'
cls.enums [[
    ADD
    SUBTRACT
    RESERVE_SUBTRACT
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::backend::BlendFactor'
cls.enums [[
    ZERO
    ONE
    SRC_COLOR
    ONE_MINUS_SRC_COLOR
    SRC_ALPHA
    ONE_MINUS_SRC_ALPHA
    DST_COLOR
    ONE_MINUS_DST_COLOR
    DST_ALPHA
    ONE_MINUS_DST_ALPHA
    CONSTANT_ALPHA
    SRC_ALPHA_SATURATE
    ONE_MINUS_CONSTANT_ALPHA
    BLEND_CLOLOR
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::backend::ColorWriteMask'
cls.enums [[
    NONE
    RED
    GREEN
    BLUE
    ALPHA
    ALL
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::backend::CullMode'
cls.enums [[
    NONE
    BACK
    FRONT
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::backend::Winding'
cls.enums [[
    CLOCK_WISE
    COUNTER_CLOCK_WISE
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::backend::TextureCubeFace'
cls.enums [[
    POSITIVE_X
    NEGATIVE_X
    POSITIVE_Y
    NEGATIVE_Y
    POSITIVE_Z
    NEGATIVE_Z
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::backend::ProgramType'
cls.enums [[
    POSITION_COLOR_LENGTH_TEXTURE
    POSITION_COLOR_TEXTURE_AS_POINTSIZE
    POSITION_COLOR
    POSITION
    POSITION_UCOLOR
    POSITION_TEXTURE
    POSITION_TEXTURE_COLOR
    POSITION_TEXTURE_COLOR_ALPHA_TEST
    LABEL_NORMAL
    LABLE_OUTLINE
    LABLE_DISTANCEFIELD_GLOW
    LABEL_DISTANCE_NORMAL
    LAYER_RADIA_GRADIENT
    ETC1
    ETC1_GRAY
    GRAY_SCALE
    CAMERA_CLEAR
    TERRAIN_3D
    LINE_COLOR_3D
    SKYBOX_3D
    SKINPOSITION_TEXTURE_3D
    SKINPOSITION_NORMAL_TEXTURE_3D
    POSITION_NORMAL_TEXTURE_3D
    POSITION_NORMAL_3D
    POSITION_TEXTURE_3D
    POSITION_3D
    POSITION_BUMPEDNORMAL_TEXTURE_3D
    SKINPOSITION_BUMPEDNORMAL_TEXTURE_3D
    PARTICLE_TEXTURE_3D
    PARTICLE_COLOR_3D
    CUSTOM_PROGRAM
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::backend::Uniform'
cls.enums [[
    MVP_MATRIX
    TEXTURE
    TEXTURE1
    TEXTURE2
    TEXTURE3
    TEXT_COLOR
    EFFECT_TYPE
    EFFECT_COLOR
    UNIFORM_MAX
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::backend::Attribute'
cls.enums [[
    POSITION
    COLOR
    TEXCOORD
    TEXCOORD1
    TEXCOORD2
    TEXCOORD3
    ATTRIBUTE_MAX
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::backend::FeatureType'
cls.enums [[
    ETC1
    S3TC
    AMD_COMPRESSED_ATC
    PVRTC
    IMG_FORMAT_BGRA8888
    DISCARD_FRAMEBUFFER
    PACKED_DEPTH_STENCIL
    VAO
    MAPBUFFER
    DEPTH24
    ASTC
]]
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
cls.inject('newProgram', {
    AFTER = [[
        ret->autorelease();
    ]],
})
cls.inject('newRenderPipeline', {
    AFTER = [[
        ret->autorelease();
    ]],
})
cls.inject('newTexture', {
    AFTER = [[
        ret->autorelease();
    ]],
})
cls.inject('newBuffer', {
    AFTER = [[
        ret->autorelease();
    ]],
})
cls.inject('newCommandBuffer', {
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
