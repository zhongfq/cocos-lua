-- AUTO BUILD, DON'T MODIFY!

dofile "autobuild/conv-types.lua"

name = "conv"
path = "../../frameworks/libxgame/src/lua-bindings"
headers = [[
    #include "cclua/xlua.h"
    #include "cocos2d.h"
    #include "ui/CocosGUI.h"
    #include "network/WebSocket.h"
]]
chunk = nil
luaopen = nil

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

typeconv 'cocos2d::Texture2D::TexParams'
    .var('minFilter', 'GLuint minFilter')
    .var('magFilter', 'GLuint magFilter')
    .var('wrapS', 'GLuint wrapS')
    .var('wrapT', 'GLuint wrapT')

typeconv 'cocos2d::experimental::Viewport'
    .var('left', 'float left')
    .var('bottom', 'float bottom')
    .var('width', 'float width')
    .var('height', 'float height')

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

typeconv 'cocos2d::ccBezierConfig'
    .var('endPosition', 'cocos2d::Vec2 endPosition')
    .var('controlPoint_1', 'cocos2d::Vec2 controlPoint_1')
    .var('controlPoint_2', 'cocos2d::Vec2 controlPoint_2')

typeconv 'GLContextAttrs'
    .var('redBits', 'int redBits')
    .var('greenBits', 'int greenBits')
    .var('blueBits', 'int blueBits')
    .var('alphaBits', 'int alphaBits')
    .var('depthBits', 'int depthBits')
    .var('stencilBits', 'int stencilBits')
    .var('multisamplingCount', 'int multisamplingCount')

typeconv 'cocos2d::Tex2F'
    .var('u', 'GLfloat u')
    .var('v', 'GLfloat v')

typeconv 'cocos2d::T2F_Quad'
    .var('bl', 'cocos2d::Tex2F bl')
    .var('br', 'cocos2d::Tex2F br')
    .var('tl', 'cocos2d::Tex2F tl')
    .var('tr', 'cocos2d::Tex2F tr')

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
    .var('src', 'GLenum src')
    .var('dst', 'GLenum dst')

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

typeconv 'cocos2d::Controller::KeyStatus'
    .var('isPressed', 'bool isPressed')
    .var('value', 'float value')
    .var('isAnalog', 'bool isAnalog')

