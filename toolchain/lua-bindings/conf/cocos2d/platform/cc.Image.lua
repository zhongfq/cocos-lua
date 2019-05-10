local M = {}

local cls = class(M)
cls.CPPCLS = "cocos2d::Image::Format"
cls.LUACLS = "cc.Image.Format"
cls.enums [[
    JPG
    PNG
    TIFF
    WEBP
    PVR
    ETC
    S3TC
    ATITC
    TGA
    RAW_DATA
    UNKNOWN
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::Image"
cls.LUACLS = "cc.Image"
cls.SUPERCLS = "cc.Ref"
cls.CHUNK = [[
NS_CC_BEGIN
class LuaImage : public cocos2d::Image {
public:
    static bool getPNGPremultipliedAlphaEnabled() { return PNG_PREMULTIPLIED_ALPHA_ENABLED; };
};
NS_CC_END
]]
cls.funcs [[
    static void setPNGPremultipliedAlphaEnabled(bool enabled)
    static void setPVRImagesHavePremultipliedAlpha(bool haveAlphaPremultiplied)
    bool initWithImageFile(const std::string& path)
    bool initWithImageData(const unsigned char * data, ssize_t dataLen)
    bool initWithRawData(const unsigned char * data, ssize_t dataLen, int width, int height, int bitsPerComponent, bool preMulti = false)
    bool saveToFile(const std::string &filename, bool isToRGB = true)
    bool hasPremultipliedAlpha()
    bool hasAlpha()
    const unsigned char *getData()
    ssize_t getDataLen()
    Format getFileType()
    Texture2D::PixelFormat getRenderFormat()
    int getWidth()
    int getHeight()
    std::string getFilePath()
    int getBitPerPixel()
    bool isCompressed()
]]
cls.func('getPNGPremultipliedAlphaEnabled', [[
{
    lua_settop(L, 0);
    lua_pushboolean(L, cocos2d::LuaImage::getPNGPremultipliedAlphaEnabled());
    return 1;
}]])
cls.props [[
    data
    dataLen
    fileType
    renderFormat
    width
    height
    filePath
    bitPerPixel
    compressed
    pngPremultipliedAlphaEnabled
]]
return M