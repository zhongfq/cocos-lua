local M = {}

local cls = class(M)
cls.CPPCLS = "cocos2d::Texture2D::PixelFormat"
cls.LUACLS = "cc.Texture2D.PixelFormat"
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
    DEFAULT
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::Texture2D"
cls.LUACLS = "cc.Texture2D"
cls.SUPERCLS = "cc.Ref"
cls.prop('defaultAlphaPixelFormat', 'static Texture2D::PixelFormat getDefaultAlphaPixelFormat()', 'static void setDefaultAlphaPixelFormat(Texture2D::PixelFormat format)')
cls.prop('description', 'std::string getDescription()')
cls.prop('pixelFormat', 'Texture2D::PixelFormat getPixelFormat()')
cls.prop('pixelsWide', 'int getPixelsWide()')
cls.prop('pixelsHigh', 'int getPixelsHigh()')
cls.prop('name', 'GLuint getName()')
cls.prop('maxS', 'GLfloat getMaxS()', 'void setMaxS(GLfloat maxS)')
cls.prop('maxT', 'GLfloat getMaxT()', 'void setMaxT(GLfloat maxT)')
cls.prop('glProgram', 'GLProgram* getGLProgram()', 'void setGLProgram(GLProgram* program)')
cls.prop('path', 'std::string getPath()')
cls.prop('alphaTexture', 'Texture2D* getAlphaTexture()', 'void setAlphaTexture(Texture2D* alphaTexture)')
cls.prop('alphaTextureName', 'GLuint getAlphaTextureName()')
cls.func(nil, 'void releaseGLTexture()')
cls.func(nil, 'bool initWithImage(Image * image)', 'bool initWithImage(Image * image, PixelFormat format)')
cls.func(nil, 'void setTexParameters(const TexParams& texParams)')
cls.func(nil, 'void setAntiAliasTexParameters()')
cls.func(nil, 'void setAliasTexParameters()')
cls.func(nil, 'void generateMipmap()')
cls.func(nil, 'unsigned int getBitsPerPixelForFormat()', 'unsigned int getBitsPerPixelForFormat(Texture2D::PixelFormat format)')
cls.func(nil, 'const char* getStringForFormat()')
cls.func(nil, '@unpack const Size& getContentSizeInPixels()')
cls.func(nil, 'bool hasPremultipliedAlpha()')
cls.func(nil, 'bool hasMipmaps()')
cls.func(nil, '@unpack Size getContentSize()')

return M