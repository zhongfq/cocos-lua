-- AUTO BUILD, DON'T MODIFY!

dofile "autobuild/conv-types.lua"

local olua = require "olua"
local typeconv = olua.typeconv
local typecls = olua.typecls
local cls = nil
local M = {}

M.NAME = "conv"
M.PATH = "../../frameworks/libxgame/src/lua-bindings"
M.INCLUDES = [[
    #include "xgame/xlua.h"
    #include "cocos2d.h"
    #include "ui/CocosGUI.h"
    #include "network/WebSocket.h"
    #include "navmesh/CCNavMesh.h"
]]
M.CHUNK = nil

M.CONVS = {
    typeconv {
        CPPCLS = 'cocos2d::Vec2',
        DEF = [[
            float x;
            float y;
        ]],
    },
    typeconv {
        CPPCLS = 'cocos2d::Vec3',
        DEF = [[
            float x;
            float y;
            float z;
        ]],
    },
    typeconv {
        CPPCLS = 'cocos2d::Vec4',
        DEF = [[
            float x;
            float y;
            float z;
            float w;
        ]],
    },
    typeconv {
        CPPCLS = 'cocos2d::Size',
        DEF = [[
            float width;
            float height;
        ]],
    },
    typeconv {
        CPPCLS = 'cocos2d::Viewport',
        DEF = [[
            @optional int x;
            @optional int y;
            @optional unsigned int w;
            @optional unsigned int h;
        ]],
    },
    typeconv {
        CPPCLS = 'cocos2d::ScissorRect',
        DEF = [[
            @optional float x;
            @optional float y;
            @optional float width;
            @optional float height;
        ]],
    },
    typeconv {
        CPPCLS = 'cocos2d::Quaternion',
        DEF = [[
            float x;
            float y;
            float z;
            float w;
        ]],
    },
    typeconv {
        CPPCLS = 'cocos2d::AffineTransform',
        DEF = [[
            float a;
            float b;
            float c;
            float d;
            float tx;
            float ty;
        ]],
    },
    typeconv {
        CPPCLS = 'GLContextAttrs',
        DEF = [[
            int redBits;
            int greenBits;
            int blueBits;
            int alphaBits;
            int depthBits;
            int stencilBits;
            int multisamplingCount;
        ]],
    },
    typeconv {
        CPPCLS = 'cocos2d::Tex2F',
        DEF = [[
            @optional float u;
            @optional float v;
        ]],
    },
    typeconv {
        CPPCLS = 'cocos2d::T2F_Quad',
        DEF = [[
            cocos2d::Tex2F bl;
            cocos2d::Tex2F br;
            cocos2d::Tex2F tl;
            cocos2d::Tex2F tr;
        ]],
    },
    typeconv {
        CPPCLS = 'cocos2d::ccBezierConfig',
        DEF = [[
            cocos2d::Vec2 endPosition;
            cocos2d::Vec2 controlPoint_1;
            cocos2d::Vec2 controlPoint_2;
        ]],
    },
    typeconv {
        CPPCLS = 'cocos2d::TTFConfig',
        DEF = [[
            @optional std::string fontFilePath;
            @optional float fontSize;
            @optional cocos2d::GlyphCollection glyphs;
            @optional const char *customGlyphs;
            @optional bool distanceFieldEnabled;
            @optional int outlineSize;
            @optional bool italics;
            @optional bool bold;
            @optional bool underline;
            @optional bool strikethrough;
        ]],
    },
    typeconv {
        CPPCLS = 'cocos2d::BlendFunc',
        DEF = [[
            cocos2d::backend::BlendFactor src;
            cocos2d::backend::BlendFactor dst;
        ]],
    },
    typeconv {
        CPPCLS = 'cocos2d::ui::Margin',
        DEF = [[
            float left;
            float top;
            float right;
            float bottom;
        ]],
    },
    typeconv {
        CPPCLS = 'cocos2d::ResourceData',
        DEF = [[
            int type;
            std::string file;
            std::string plist;
        ]],
    },
    typeconv {
        CPPCLS = 'cocos2d::Quad3',
        DEF = [[
            cocos2d::Vec3 bl;
            cocos2d::Vec3 br;
            cocos2d::Vec3 tl;
            cocos2d::Vec3 tr;
        ]],
    },
    typeconv {
        CPPCLS = 'cocos2d::Texture2D::PixelFormatInfo',
        DEF = [[
            int bpp;
            bool compressed;
            bool alpha;
        ]],
    },
    typeconv {
        CPPCLS = 'cocos2d::Controller::KeyStatus',
        DEF = [[
            bool isPressed;
            float value;
            bool isAnalog;
        ]],
    },
    typeconv {
        CPPCLS = 'cocos2d::network::WebSocket::Data',
        DEF = [[
            char *bytes;
            ssize_t len;
            ssize_t issued;
            bool isBinary;
            void *ext;
        ]],
    },
    typeconv {
        CPPCLS = 'cocos2d::NavMeshAgentParam',
        DEF = [[
            float radius;
            float height;
            float maxAcceleration;
            float maxSpeed;
            float collisionQueryRange;
            float pathOptimizationRange;
            float separationWeight;
            unsigned char updateFlags;
            unsigned char obstacleAvoidanceType;
            unsigned char queryFilterType;
        ]],
    },
    typeconv {
        CPPCLS = 'cocos2d::OffMeshLinkData',
        DEF = [[
            cocos2d::Vec3 startPosition;
            cocos2d::Vec3 endPosition;
        ]],
    },
    typeconv {
        CPPCLS = 'cocos2d::backend::BlendDescriptor',
        DEF = [[
            @optional cocos2d::backend::ColorWriteMask writeMask;
            @optional bool blendEnabled;
            @optional cocos2d::backend::BlendOperation rgbBlendOperation;
            @optional cocos2d::backend::BlendOperation alphaBlendOperation;
            @optional cocos2d::backend::BlendFactor sourceRGBBlendFactor;
            @optional cocos2d::backend::BlendFactor destinationRGBBlendFactor;
            @optional cocos2d::backend::BlendFactor sourceAlphaBlendFactor;
            @optional cocos2d::backend::BlendFactor destinationAlphaBlendFactor;
        ]],
    },
    typeconv {
        CPPCLS = 'cocos2d::backend::SamplerDescriptor',
        DEF = [[
            @optional cocos2d::backend::SamplerFilter magFilter;
            @optional cocos2d::backend::SamplerFilter minFilter;
            @optional cocos2d::backend::SamplerAddressMode sAddressMode;
            @optional cocos2d::backend::SamplerAddressMode tAddressMode;
        ]],
    },
    typeconv {
        CPPCLS = 'cocos2d::backend::TextureInfo',
        DEF = [[
            std::vector<uint32_t> slot;
            std::vector<backend::TextureBackend *> textures;
        ]],
    },
    typeconv {
        CPPCLS = 'cocos2d::backend::AttributeBindInfo',
        DEF = [[
            std::string attributeName;
            @optional int location;
            @optional int size;
            @optional int type;
        ]],
    },
    typeconv {
        CPPCLS = 'cocos2d::backend::UniformInfo',
        DEF = [[
            @optional int count;
            @optional int location;
            @optional unsigned int type;
            @optional bool isArray;
            @optional unsigned int size;
            @optional unsigned int bufferOffset;
            @optional bool isMatrix;
            @optional bool needConvert;
        ]],
    },
    typeconv {
        CPPCLS = 'cocos2d::backend::TextureDescriptor',
        DEF = [[
            @optional cocos2d::backend::TextureType textureType;
            @optional cocos2d::backend::PixelFormat textureFormat;
            @optional cocos2d::backend::TextureUsage textureUsage;
            @optional uint32_t width;
            @optional uint32_t height;
            @optional uint32_t depth;
            cocos2d::backend::SamplerDescriptor samplerDescriptor;
            @optional int sampleCount;
        ]],
    },
    typeconv {
        CPPCLS = 'cocos2d::backend::StencilDescriptor',
        DEF = [[
            @optional cocos2d::backend::StencilOperation stencilFailureOperation;
            @optional cocos2d::backend::StencilOperation depthFailureOperation;
            @optional cocos2d::backend::StencilOperation depthStencilPassOperation;
            @optional cocos2d::backend::CompareFunction stencilCompareFunction;
            @optional unsigned int readMask;
            @optional unsigned int writeMask;
        ]],
    },
    typeconv {
        CPPCLS = 'cocos2d::backend::DepthStencilDescriptor',
        DEF = [[
            @optional cocos2d::backend::CompareFunction depthCompareFunction;
            @optional bool depthWriteEnabled;
            @optional bool depthTestEnabled;
            @optional bool stencilTestEnabled;
            cocos2d::backend::StencilDescriptor backFaceStencil;
            cocos2d::backend::StencilDescriptor frontFaceStencil;
        ]],
    },
    typeconv {
        CPPCLS = 'cocos2d::backend::VertexLayout::Attribute',
        DEF = [[
            std::string name;
            @optional cocos2d::backend::VertexFormat format;
            @optional std::size_t offset;
            @optional std::size_t index;
            @optional bool needToBeNormallized;
        ]],
    },
}

M.CLASSES = {}

return M
