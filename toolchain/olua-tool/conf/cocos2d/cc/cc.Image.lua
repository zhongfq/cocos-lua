local arr = {}

local cls = class()
cls.CPPCLS = "cocos2d::Image::Format"
cls.LUACLS = "cc.Image.Format"
cls.enum('JPG', 'cocos2d::Image::Format::JPG')
cls.enum('PNG', 'cocos2d::Image::Format::PNG')
cls.enum('TIFF', 'cocos2d::Image::Format::TIFF')
cls.enum('WEBP', 'cocos2d::Image::Format::WEBP')
cls.enum('PVR', 'cocos2d::Image::Format::PVR')
cls.enum('ETC', 'cocos2d::Image::Format::ETC')
cls.enum('S3TC', 'cocos2d::Image::Format::S3TC')
cls.enum('ATITC', 'cocos2d::Image::Format::ATITC')
cls.enum('TGA', 'cocos2d::Image::Format::TGA')
cls.enum('RAW_DATA', 'cocos2d::Image::Format::RAW_DATA')
cls.enum('UNKNOWN', 'cocos2d::Image::Format::UNKNOWN')
arr[#arr + 1] = cls

local cls = class()
cls.CPPCLS = "cocos2d::Image"
cls.LUACLS = "cc.Image"
cls.SUPERCLS = "cc.Ref"
cls.prop('data', 'const unsigned char *getData()')
cls.prop('dataLen', 'ssize_t getDataLen()')
cls.prop('fileType', 'Format getFileType()')
cls.prop('renderFormat', 'Texture2D::PixelFormat getRenderFormat()')
cls.prop('width', 'int getWidth()')
cls.prop('height', 'int getHeight()')
cls.prop('filePath', 'std::string getFilePath()')
cls.prop('bitPerPixel', 'int getBitPerPixel()')
cls.prop('compressed', 'bool isCompressed()')
cls.func(nil, 'static void setPNGPremultipliedAlphaEnabled(bool enabled)')
cls.func(nil, 'static void setPVRImagesHavePremultipliedAlpha(bool haveAlphaPremultiplied)')
cls.func(nil, 'bool initWithImageFile(const std::string& path)')
cls.func(nil, 'bool initWithImageData(const unsigned char * data, ssize_t dataLen)')
cls.func(nil, 'bool initWithRawData(const unsigned char * data, ssize_t dataLen, int width, int height, int bitsPerComponent, bool preMulti = false)')
cls.func(nil, 'bool saveToFile(const std::string &filename, bool isToRGB = true)')
cls.func(nil, 'bool hasPremultipliedAlpha()')
cls.func(nil, 'bool hasAlpha()')
arr[#arr + 1] = cls

return arr