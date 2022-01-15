-- AUTO BUILD, DON'T MODIFY!

dofile "autobuild/conv-types.lua"

name = "conv"
path = "../../frameworks/libxgame/src/lua-bindings"
headers = [[
    #include "cclua/xlua.h"
    #include "cocos2d.h"
    #include "ui/CocosGUI.h"
    #include "network/WebSocket.h"
    #include "navmesh/CCNavMesh.h"
]]
chunk = nil

typeconv 'cocos2d::Vec2'
    .var('x', 'float x')
    .var('y', 'float y')

typeconv 'cocos2d::Vec3'
    .var('x', 'float x')
    .var('y', 'float y')
    .var('z', 'float z')

typeconv 'cocos2d::Vec4'
    .var('x', 'float x')
    .var('y', 'float y')
    .var('z', 'float z')
    .var('w', 'float w')

typeconv 'cocos2d::Size'
    .var('width', 'float width')
    .var('height', 'float height')

typeconv 'cocos2d::Viewport'
    .var('x', '@optional int x')
    .var('y', '@optional int y')
    .var('w', '@optional unsigned int w')
    .var('h', '@optional unsigned int h')

typeconv 'cocos2d::ScissorRect'
    .var('x', '@optional float x')
    .var('y', '@optional float y')
    .var('width', '@optional float width')
    .var('height', '@optional float height')

typeconv 'cocos2d::Quaternion'
    .var('x', 'float x')
    .var('y', 'float y')
    .var('z', 'float z')
    .var('w', 'float w')

typeconv 'cocos2d::AffineTransform'
    .var('a', 'float a')
    .var('b', 'float b')
    .var('c', 'float c')
    .var('d', 'float d')
    .var('tx', 'float tx')
    .var('ty', 'float ty')

typeconv 'GLContextAttrs'
    .var('redBits', 'int redBits')
    .var('greenBits', 'int greenBits')
    .var('blueBits', 'int blueBits')
    .var('alphaBits', 'int alphaBits')
    .var('depthBits', 'int depthBits')
    .var('stencilBits', 'int stencilBits')
    .var('multisamplingCount', 'int multisamplingCount')

typeconv 'cocos2d::Tex2F'
    .var('u', '@optional float u')
    .var('v', '@optional float v')

typeconv 'cocos2d::T2F_Quad'
    .var('bl', 'cocos2d::Tex2F bl')
    .var('br', 'cocos2d::Tex2F br')
    .var('tl', 'cocos2d::Tex2F tl')
    .var('tr', 'cocos2d::Tex2F tr')

typeconv 'cocos2d::ccBezierConfig'
    .var('endPosition', 'cocos2d::Vec2 endPosition')
    .var('controlPoint_1', 'cocos2d::Vec2 controlPoint_1')
    .var('controlPoint_2', 'cocos2d::Vec2 controlPoint_2')

typeconv 'cocos2d::TTFConfig'
    .var('fontFilePath', '@optional std::string fontFilePath')
    .var('fontSize', '@optional float fontSize')
    .var('glyphs', '@optional cocos2d::GlyphCollection glyphs')
    .var('customGlyphs', '@optional const char *customGlyphs')
    .var('distanceFieldEnabled', '@optional bool distanceFieldEnabled')
    .var('outlineSize', '@optional int outlineSize')
    .var('italics', '@optional bool italics')
    .var('bold', '@optional bool bold')
    .var('underline', '@optional bool underline')
    .var('strikethrough', '@optional bool strikethrough')

typeconv 'cocos2d::BlendFunc'
    .var('src', 'cocos2d::backend::BlendFactor src')
    .var('dst', 'cocos2d::backend::BlendFactor dst')

typeconv 'cocos2d::ui::Margin'
    .var('left', 'float left')
    .var('top', 'float top')
    .var('right', 'float right')
    .var('bottom', 'float bottom')

typeconv 'cocos2d::ResourceData'
    .var('type', 'int type')
    .var('file', 'std::string file')
    .var('plist', 'std::string plist')

typeconv 'cocos2d::Quad3'
    .var('bl', 'cocos2d::Vec3 bl')
    .var('br', 'cocos2d::Vec3 br')
    .var('tl', 'cocos2d::Vec3 tl')
    .var('tr', 'cocos2d::Vec3 tr')

typeconv 'cocos2d::Texture2D::PixelFormatInfo'
    .var('bpp', 'int bpp')
    .var('compressed', 'bool compressed')
    .var('alpha', 'bool alpha')

typeconv 'cocos2d::Controller::KeyStatus'
    .var('isPressed', 'bool isPressed')
    .var('value', 'float value')
    .var('isAnalog', 'bool isAnalog')

typeconv 'cocos2d::NavMeshAgentParam'
    .var('radius', 'float radius')
    .var('height', 'float height')
    .var('maxAcceleration', 'float maxAcceleration')
    .var('maxSpeed', 'float maxSpeed')
    .var('collisionQueryRange', 'float collisionQueryRange')
    .var('pathOptimizationRange', 'float pathOptimizationRange')
    .var('separationWeight', 'float separationWeight')
    .var('updateFlags', 'unsigned char updateFlags')
    .var('obstacleAvoidanceType', 'unsigned char obstacleAvoidanceType')
    .var('queryFilterType', 'unsigned char queryFilterType')

typeconv 'cocos2d::OffMeshLinkData'
    .var('startPosition', 'cocos2d::Vec3 startPosition')
    .var('endPosition', 'cocos2d::Vec3 endPosition')

typeconv 'cocos2d::backend::BlendDescriptor'
    .var('writeMask', '@optional cocos2d::backend::ColorWriteMask writeMask')
    .var('blendEnabled', '@optional bool blendEnabled')
    .var('rgbBlendOperation', '@optional cocos2d::backend::BlendOperation rgbBlendOperation')
    .var('alphaBlendOperation', '@optional cocos2d::backend::BlendOperation alphaBlendOperation')
    .var('sourceRGBBlendFactor', '@optional cocos2d::backend::BlendFactor sourceRGBBlendFactor')
    .var('destinationRGBBlendFactor', '@optional cocos2d::backend::BlendFactor destinationRGBBlendFactor')
    .var('sourceAlphaBlendFactor', '@optional cocos2d::backend::BlendFactor sourceAlphaBlendFactor')
    .var('destinationAlphaBlendFactor', '@optional cocos2d::backend::BlendFactor destinationAlphaBlendFactor')

typeconv 'cocos2d::backend::SamplerDescriptor'
    .var('magFilter', '@optional cocos2d::backend::SamplerFilter magFilter')
    .var('minFilter', '@optional cocos2d::backend::SamplerFilter minFilter')
    .var('sAddressMode', '@optional cocos2d::backend::SamplerAddressMode sAddressMode')
    .var('tAddressMode', '@optional cocos2d::backend::SamplerAddressMode tAddressMode')

typeconv 'cocos2d::backend::TextureInfo'
    .var('slot', 'std::vector<uint32_t> slot')
    .var('textures', 'std::vector<backend::TextureBackend *> textures')

typeconv 'cocos2d::backend::AttributeBindInfo'
    .var('attributeName', 'std::string attributeName')
    .var('location', '@optional int location')
    .var('size', '@optional int size')
    .var('type', '@optional int type')

typeconv 'cocos2d::backend::UniformInfo'
    .var('count', '@optional int count')
    .var('location', '@optional int location')
    .var('type', '@optional unsigned int type')
    .var('isArray', '@optional bool isArray')
    .var('size', '@optional unsigned int size')
    .var('bufferOffset', '@optional unsigned int bufferOffset')
    .var('isMatrix', '@optional bool isMatrix')
    .var('needConvert', '@optional bool needConvert')

typeconv 'cocos2d::backend::TextureDescriptor'
    .var('textureType', '@optional cocos2d::backend::TextureType textureType')
    .var('textureFormat', '@optional cocos2d::backend::PixelFormat textureFormat')
    .var('textureUsage', '@optional cocos2d::backend::TextureUsage textureUsage')
    .var('width', '@optional uint32_t width')
    .var('height', '@optional uint32_t height')
    .var('depth', '@optional uint32_t depth')
    .var('samplerDescriptor', 'cocos2d::backend::SamplerDescriptor samplerDescriptor')
    .var('sampleCount', '@optional int sampleCount')

typeconv 'cocos2d::backend::StencilDescriptor'
    .var('stencilFailureOperation', '@optional cocos2d::backend::StencilOperation stencilFailureOperation')
    .var('depthFailureOperation', '@optional cocos2d::backend::StencilOperation depthFailureOperation')
    .var('depthStencilPassOperation', '@optional cocos2d::backend::StencilOperation depthStencilPassOperation')
    .var('stencilCompareFunction', '@optional cocos2d::backend::CompareFunction stencilCompareFunction')
    .var('readMask', '@optional unsigned int readMask')
    .var('writeMask', '@optional unsigned int writeMask')

typeconv 'cocos2d::backend::DepthStencilDescriptor'
    .var('depthCompareFunction', '@optional cocos2d::backend::CompareFunction depthCompareFunction')
    .var('depthWriteEnabled', '@optional bool depthWriteEnabled')
    .var('depthTestEnabled', '@optional bool depthTestEnabled')
    .var('stencilTestEnabled', '@optional bool stencilTestEnabled')
    .var('backFaceStencil', 'cocos2d::backend::StencilDescriptor backFaceStencil')
    .var('frontFaceStencil', 'cocos2d::backend::StencilDescriptor frontFaceStencil')

typeconv 'cocos2d::backend::VertexLayout::Attribute'
    .var('name', 'std::string name')
    .var('format', '@optional cocos2d::backend::VertexFormat format')
    .var('offset', '@optional std::size_t offset')
    .var('index', '@optional std::size_t index')
    .var('needToBeNormallized', '@optional bool needToBeNormallized')

