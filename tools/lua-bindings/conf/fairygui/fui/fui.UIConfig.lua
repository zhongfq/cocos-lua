local cls = class()
cls.CPPCLS = "fairygui::UIConfig"
cls.LUACLS = "fui.UIConfig"
cls.funcs [[
    static void registerFont(const std::string& aliasName, const std::string& realName)
]]
cls.func('getRealFontName', [[
{
    lua_settop(L, 1);
    bool isTTF = false;
    std::string aliasName = olua_checkstring(L, 1);
    std::string fontName = fairygui::UIConfig::getRealFontName(aliasName, &isTTF);
    lua_pushstring(L, fontName.c_str());
    lua_pushboolean(L, isTTF);
    return 2;
}]])

cls.vars [[
    static std::string defaultFont;
    static std::string buttonSound;
    static float buttonSoundVolumeScale;
    static int defaultScrollStep;
    static float defaultScrollDecelerationRate;
    static bool defaultScrollTouchEffect;
    static bool defaultScrollBounceEffect;
    static ScrollBarDisplayType defaultScrollBarDisplay;
    static std::string verticalScrollBar;
    static std::string horizontalScrollBar;
    static int touchDragSensitivity;
    static int clickDragSensitivity;
    static int touchScrollSensitivity;
    static int defaultComboBoxVisibleItemCount;
    static std::string globalModalWaiting;
    static cocos2d::Color4F modalLayerColor;
    static std::string tooltipsWin;
    static bool bringWindowToFrontOnClick;
    static std::string windowModalWaiting;
    static std::string popupMenu;
    static std::string popupMenu_seperator;
]]

return cls