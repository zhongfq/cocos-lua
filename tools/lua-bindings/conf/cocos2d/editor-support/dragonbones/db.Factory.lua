local M = {}

local cls = class(M)
cls.CPPCLS = "dragonBones::CCFactory"
cls.LUACLS = "db.Factory"
cls.SUPERCLS = "db.BaseFactory"
cls.funcs [[
    static CCFactory* getFactory()
    DragonBonesData* loadDragonBonesData(const std::string& filePath, const std::string& name = "", float scale = 1.0f)
    TextureAtlasData* loadTextureAtlasData(const std::string& filePath, const std::string& name = "", float scale = 1.0f)
    CCArmatureDisplay* buildArmatureDisplay(const std::string& armatureName, const std::string& dragonBonesName = "", const std::string& skinName = "", const std::string& textureAtlasName = "")
    cocos2d::Sprite* getTextureDisplay(const std::string& textureName, const std::string& dragonBonesName = "")
    CCArmatureDisplay* getSoundEventManager()
]]

return M