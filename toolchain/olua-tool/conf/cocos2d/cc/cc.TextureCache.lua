local cls = class()
cls.CPPCLS = "cocos2d::TextureCache"
cls.LUACLS = "cc.TextureCache"
cls.SUPERCLS = "cc.Ref"
cls.DEFCHUNK = [[
static const std::string makeTextureCacheCallbackTag(const std::string &key)
{
    return "addImageAsync." + key;
}]]
cls.prop('description', 'std::string getDescription()')
cls.prop('cachedTextureInfo', 'std::string getCachedTextureInfo()')
cls.func(nil, 'Texture2D* addImage(const std::string &filepath)', 'Texture2D* addImage(Image *image, const std::string &key)')
cls.callback(nil, {
        CALLBACK_MAKER = {'makeTextureCacheCallbackTag(#1)', 'makeTextureCacheCallbackTag(#-1)'},
        CALLBACK_CALLONCE = true,
        CALLBACK_MODE = 'OLUA_CALLBACK_TAG_EQUAL',
    }, 
    'void addImageAsync(const std::string &filepath, const std::function<void(Texture2D*)>& callback)',
    'void addImageAsync(const std::string &path, const std::function<void(Texture2D*)>& callback, const std::string& callbackKey)'
)
cls.callback(nil, {
        CALLBACK_MAKER = 'makeTextureCacheCallbackTag(#1)',
        CALLBACK_MODE = 'OLUA_CALLBACK_TAG_ENDWITH',
        CALLBACK_REMOVE = true,
    },
    'void unbindImageAsync(const std::string &filename)'
)
cls.callback(nil, {
        CALLBACK_MAKER = 'makeTextureCacheCallbackTag()',
        CALLBACK_MODE = 'OLUA_CALLBACK_TAG_WILDCARD',
        CALLBACK_REMOVE = true,
    },
    'void unbindAllImageAsync()'
)
cls.func(nil, 'Texture2D* getTextureForKey(const std::string& key)')
cls.func(nil, 'bool reloadTexture(const std::string& fileName)')
cls.func(nil, 'void removeAllTextures()')
cls.func(nil, 'void removeUnusedTextures()')
cls.func(nil, 'void removeTexture(Texture2D* texture)')
cls.func(nil, 'void removeTextureForKey(const std::string &key)')
cls.func(nil, 'std::string getTextureFilePath(Texture2D* texture)')
cls.func(nil, 'void renameTextureWithKey(const std::string& srcName, const std::string& dstName)')
return cls