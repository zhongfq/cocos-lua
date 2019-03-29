local cls = class()
cls.CPPCLS = "fairygui::PackageItem"
cls.LUACLS = "fgui.PackageItem"
cls.SUPERCLS = "cc.Ref"
-- cls.vars [[
--     UIPackage* owner;

--     PackageItemType type;
--     ObjectType objectType;
--     std::string id;
--     std::string name;
--     int width;
--     int height;
--     std::string file;
--     ByteBuffer* rawData;

--     //atlas
--     cocos2d::Texture2D* texture;

--     //image
--     cocos2d::Rect* scale9Grid;
--     bool scaleByTile;
--     int tileGridIndice;
--     cocos2d::SpriteFrame* spriteFrame;
--     PixelHitTestData* pixelHitTestData;

--     //movieclip
--     cocos2d::Animation* animation;
--     float delayPerUnit;
--     float repeatDelay;
--     bool swing;

--     //component
--     std::function<GComponent*()> extensionCreator;
--     bool translated;

--     //font
--     BitmapFont* bitmapFont;
-- ]]

return cls