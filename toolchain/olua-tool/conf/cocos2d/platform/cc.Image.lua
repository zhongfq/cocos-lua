local arr = {}

local cls = class()
cls.CPPCLS = "cocos2d::Image::Format"
cls.LUACLS = "cc.Image.Format"
cls.enum('JPG')
cls.enum('PNG')
cls.enum('TIFF')
cls.enum('WEBP')
cls.enum('PVR')
cls.enum('ETC')
cls.enum('S3TC')
cls.enum('ATITC')
cls.enum('TGA')
cls.enum('RAW_DATA')
cls.enum('UNKNOWN')
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