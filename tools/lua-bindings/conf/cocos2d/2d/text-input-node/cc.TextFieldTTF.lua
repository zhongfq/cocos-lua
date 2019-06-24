local cls = class()
cls.CPPCLS = "cocos2d::TextFieldTTF"
cls.LUACLS = "cc.TextFieldTTF"
cls.SUPERCLS = "cc.Label"
cls.funcs [[
    static TextFieldTTF * textFieldWithPlaceHolder(const std::string& placeholder, const Size& dimensions, TextHAlignment alignment, const std::string& fontName, float fontSize)
    static TextFieldTTF * textFieldWithPlaceHolder(const std::string& placeholder, const std::string& fontName, float fontSize)
    bool attachWithIME()
    bool detachWithIME()
    std::size_t getCharCount()
    const Color4B& getColorSpaceHolder()
    void setColorSpaceHolder(const Color3B& color)
    void setColorSpaceHolder(const Color4B& color)
    void appendString(const std::string& text)
    void setPlaceHolder(const std::string& text)
    const std::string& getPlaceHolder()
    void setSecureTextEntry(bool value)
    void setPasswordTextStyle(const std::string& text)
    const std::string& getPasswordTextStyle()
    bool isSecureTextEntry()
    void setCursorEnabled(bool enabled)
    void setCursorChar(char cursor)
    void setCursorPosition(std::size_t cursorPosition)
    void setCursorFromPoint(const Vec2 &point, const Camera* camera)
]]

cls.props [[
    charCount
    colorSpaceHolder
    placeHolder
    passwordTextStyle
    secureTextEntry
]]

return cls