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
cls.func('addImageAsync', [[
{
    lua_settop(L, 3);

    cocos2d::TextureCache *self = nullptr;
    std::string filePath;

    xluacv_to_ccobj(L, 1, (void **)&self, "cc.TextureCache");
    tolua_check_std_string(L, 2, &filePath);

    std::string tag = makeTextureCacheCallbackTag(filePath);
    std::string func = tolua_setcallback(L, 1, tag.c_str(), 3);
    self->addImageAsync(filePath, [self, func] (cocos2d::Texture2D *texture) {
        lua_State *L = xlua_cocosthread();
        int top = lua_gettop(L);
        xluacv_push_ccobj(L, texture, "cc.Texture2D");
        tolua_callback(L, self, func.c_str(), 1);
        if (tolua_getobj(L, self)) {
            tolua_removecallback(L, -1, func.c_str(), TOLUA_REMOVE_CALLBACK_EQUAL);
        }
        lua_settop(L, top);
    });

    return 0;
}]])
cls.func('unbindImageAsync', [[
{
    lua_settop(L, 2);
    
    cocos2d::TextureCache *self = nullptr;
    std::string filePath;
    
    xluacv_to_ccobj(L, 1, (void **)&self, "cc.TextureCache");
    tolua_check_std_string(L, 2, &filePath);
    
    std::string tag = makeTextureCacheCallbackTag(filePath);
    self->unbindImageAsync(filePath);
    tolua_removecallback(L, 1, tag.c_str(), TOLUA_REMOVE_CALLBACK_ENDWITH);
    
    return 0;
}]])
cls.func('unbindAllImageAsync', [[
{
    lua_settop(L, 1);
    
    cocos2d::TextureCache *self = nullptr;
    
    xluacv_to_ccobj(L, 1, (void **)&self, "cc.TextureCache");
    std::string tag = makeTextureCacheCallbackTag("");
    
    self->unbindAllImageAsync();
    tolua_removecallback(L, 1, tag.c_str(), TOLUA_REMOVE_CALLBACK_WILDCARD);
    
    return 0;
}]])
cls.func(nil, 'Texture2D* getTextureForKey(const std::string& key)')
cls.func(nil, 'bool reloadTexture(const std::string& fileName)')
cls.func(nil, 'void removeAllTextures()')
cls.func(nil, 'void removeUnusedTextures()')
cls.func(nil, 'void removeTexture(Texture2D* texture)')
cls.func(nil, 'void removeTextureForKey(const std::string &key)')
cls.func(nil, 'std::string getTextureFilePath(Texture2D* texture)')
cls.func(nil, 'void renameTextureWithKey(const std::string& srcName, const std::string& dstName)')
return cls