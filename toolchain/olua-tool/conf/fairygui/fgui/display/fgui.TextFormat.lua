local cls = class()
cls.CPPCLS = "fairygui::TextFormat"
cls.LUACLS = "fgui.TextFormat"
cls.enums [[
    OUTLINE
    SHADOW
    GLOW
]]
cls.funcs [[
    void enableEffect(int effectFlag)
    void disableEffect(int effectFlag)
    bool hasEffect(int effectFlag)
]]
cls.func('setFormat', [[
{
    lua_settop(L, 2);
    fairygui::TextFormat *self = (fairygui::TextFormat *)olua_toobj(L, 1, "fgui.TextFormat");
    fairygui::TextFormat *fmt = (fairygui::TextFormat *)olua_toobj(L, 2, "fgui.TextFormat");
    self->setFormat(*fmt);
    return 0;
}]])
cls.vars [[
    std::string face;
    float fontSize;
    cocos2d::Color3B color;
    bool bold;
    bool italics;
    bool underline;
    int lineSpacing;
    int letterSpacing;
    cocos2d::TextHAlignment align;
    cocos2d::TextVAlignment verticalAlign;

    int effect;
    cocos2d::Color3B outlineColor;
    int outlineSize;
    cocos2d::Color3B shadowColor;
    cocos2d::Size shadowOffset;
    int shadowBlurRadius;
    cocos2d::Color3B glowColor;
]]

return cls