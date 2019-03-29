local cls = class()
cls.CPPCLS = "fairygui::GTextField"
cls.LUACLS = "fgui.GTextField"
cls.SUPERCLS = "fgui.GObject"
cls.funcs [[
    bool isUBBEnabled()
    void setUBBEnabled(bool value)
    AutoSizeType getAutoSize()
    void setAutoSize(AutoSizeType value)
    bool isSingleLine()
    void setSingleLine(bool value)
    TextFormat* getTextFormat()
    void applyTextFormat()
    const cocos2d::Size& getTextSize()
    cocos2d::Color3B getColor()
    void setColor(const cocos2d::Color3B& value)
    float getFontSize()
    void setFontSize(float value)
    cocos2d::Color3B getOutlineColor()
    void setOutlineColor(const cocos2d::Color3B& value)
    GTextField* setVar(const std::string& name, const cocos2d::Value& value)
    void flushVars()
]]
cls.func('getTemplateVars', [[
{
    lua_settop(L, 1);
    fairygui::GTextField *self = (fairygui::GTextField *)olua_toobj(L, 1, "fgui.GTextField");
    manual_luacv_push_cocos2d_ValueMap(L, self->getTemplateVars());
    return 1;
}]])
cls.func('setTemplateVars', [[
{
    lua_settop(L, 2);
    cocos2d::ValueMap arg;
    fairygui::GTextField *self = (fairygui::GTextField *)olua_toobj(L, 1, "fgui.GTextField");
    manual_luacv_check_cocos2d_ValueMap(L, 2, &arg);
    self->setTemplateVars(&arg);
    return 1;
}]])
cls.props [[
    ubbEnabled
    autoSize
    singleLine
    textFormat
    textSize
    color
    fontSize
    outlineColor
    templateVars
]]
return cls