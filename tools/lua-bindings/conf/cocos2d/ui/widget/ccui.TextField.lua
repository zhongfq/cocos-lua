local M = {}

local cls = class(M)
cls.CPPCLS = "cocos2d::ui::UICCTextField"
cls.LUACLS = "ccui.UICCTextField"
cls.SUPERCLS = "cc.TextFieldTTF"
cls.funcs [[
    static UICCTextField* create()
    bool onTextFieldAttachWithIME(TextFieldTTF *pSender)
    bool onTextFieldDetachWithIME(TextFieldTTF * pSender)
    void insertText(const char* text, size_t len)
    void openIME()
    void closeIME()
    void setMaxLengthEnabled(bool enable)
    bool isMaxLengthEnabled()
    void setMaxLength(int length)
    int getMaxLength()
    void setPasswordEnabled(bool enable)
    bool isPasswordEnabled()
    void setPasswordStyleText(const std::string& styleText)
    void setPasswordText(const std::string& text)
    void setAttachWithIME(bool attach)
    bool getAttachWithIME()
    void setDetachWithIME(bool detach)
    bool getDetachWithIME()
    void setInsertText(bool insert)
    bool getInsertText()
    void setDeleteBackward(bool deleteBackward)
    bool getDeleteBackward()
]]

cls.props [[
    maxLengthEnabled
    maxLength
    passwordEnabled
    attachWithIME
    detachWithIME
    insertText
    deleteBackward
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::ui::TextField::EventType"
cls.LUACLS = "ccui.TextField.EventType"
cls.enums [[
    ATTACH_WITH_IME
    DETACH_WITH_IME
    INSERT_TEXT
    DELETE_BACKWARD
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::ui::TextField"
cls.LUACLS = "ccui.TextField"
cls.SUPERCLS = "ccui.Widget"
cls.funcs [[
    static TextField* create()
    void setTouchSize(const Size &size)
    Size getTouchSize()
    void setTouchAreaEnabled(bool enable)
    void setPlaceHolder(const std::string& value)
    const std::string& getPlaceHolder()
    const Color4B& getPlaceHolderColor()
    void setPlaceHolderColor(const Color3B& color)
    void setPlaceHolderColor(const Color4B& color)
    const Color4B& getTextColor()
    void setTextColor(const Color4B& textColor)
    void setFontSize(int size)
    int getFontSize()
    void setFontName(const std::string& name)
    const std::string& getFontName()
    void didNotSelectSelf()
    void setString(const std::string& text)
    const std::string& getString()
    void setMaxLengthEnabled(bool enable)
    bool isMaxLengthEnabled()
    void setMaxLength(int length)
    int getMaxLength()
    int getStringLength()
    void setPasswordEnabled(bool enable)
    bool isPasswordEnabled()
    void setPasswordStyleText(const char* styleText)
    const char* getPasswordStyleText()
    bool getAttachWithIME()
    void setAttachWithIME(bool attach)
    bool getDetachWithIME()
    void setDetachWithIME(bool detach)
    bool getInsertText()
    void setInsertText(bool insertText)
    bool getDeleteBackward()
    void setDeleteBackward(bool deleteBackward)
    Size getAutoRenderSize()
    void attachWithIME()
    void setTextAreaSize(const Size &size)
    void setTextHorizontalAlignment(TextHAlignment alignment)
    TextHAlignment getTextHorizontalAlignment()
    void setTextVerticalAlignment(TextVAlignment alignment)
    TextVAlignment getTextVerticalAlignment()
    void setCursorEnabled(bool enabled)
    void setCursorChar(char cursor)
    void setCursorPosition(std::size_t cursorPosition)
    void setCursorFromPoint(const Vec2 &point, const Camera* camera)
]]

cls.callback(
    'void addEventListener(@nullable const std::function<void(Ref*, EventType)>& callback)',
    {
        CALLBACK_MAKER = 'olua_makecallbacktag("TextFieldCallback")',
        CALLBACK_REPLACE = true,
        CALLBACK_MODE = 'OLUA_CALLBACK_TAG_ENDWITH',
    }
)

cls.props [[
    touchSize
    placeHolder
    placeHolderColor
    textColor
    fontSize
    fontName
    string
    maxLengthEnabled
    maxLength
    stringLength
    passwordEnabled
    passwordStyleText
    attachWithIME
    detachWithIME
    insertText
    deleteBackward
    autoRenderSize
    textHorizontalAlignment
    textVerticalAlignment
]]

return M