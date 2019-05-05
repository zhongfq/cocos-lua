local M = {}

local cls = class(M)
cls.CPPCLS = "cocos2d::ui::EditBoxDelegate::EditBoxEndAction"
cls.LUACLS = "ccui.EditBoxDelegate.EditBoxEndAction"
cls.enums [[
    UNKNOWN
    TAB_TO_NEXT
    TAB_TO_PREVIOUS
    RETURN
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::ui::EditBoxDelegate"
cls.LUACLS = "ccui.EditBoxDelegate"
cls.SUPERCLS = "cc.Ref"
cls.funcs [[
    void editBoxEditingDidBegin(EditBox* editBox)
    void editBoxTextChanged(EditBox* editBox, const std::string& text)
    void editBoxReturn(EditBox* editBox)
    void editBoxEditingDidEndWithAction(EditBox* editBox, EditBoxEndAction action)
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::ui::LuaEditBoxDelegate"
cls.LUACLS = "ccui.LuaEditBoxDelegate"
cls.SUPERCLS = "ccui.EditBoxDelegate"
cls.CHUNK = [[
NS_CC_BEGIN
namespace ui {
    class LuaEditBoxDelegate : public cocos2d::Ref, public EditBoxDelegate {
    public:
        CREATE_FUNC(LuaEditBoxDelegate);
        virtual void editBoxEditingDidBegin(EditBox* editBox)
        {
            if (onEditingDidBegin) {
                onEditingDidBegin(editBox);
            }
        }
        
        virtual void editBoxTextChanged(EditBox* editBox, const std::string& text)
        {
            if (onTextChanged) {
                onTextChanged(editBox, text);
            }
        }
        
        virtual void editBoxReturn(EditBox* editBox)
        {
            if (onReturn) {
                onReturn(editBox);
            }
        }
        
        virtual void editBoxEditingDidEndWithAction(EditBox* editBox, EditBoxDelegate::EditBoxEndAction action)
        {
            if (onEditingDidEndWithAction) {
                onEditingDidEndWithAction(editBox, action);
            }
        }
        
        std::function<void(EditBox *)> onEditingDidBegin;
        std::function<void(EditBox *, const std::string &)> onTextChanged;
        std::function<void(EditBox *)> onReturn;
        std::function<void(EditBox *, EditBoxDelegate::EditBoxEndAction)> onEditingDidEndWithAction;
    private:
        LuaEditBoxDelegate()
        :onEditingDidBegin(nullptr)
        ,onTextChanged(nullptr)
        ,onReturn(nullptr)
        ,onEditingDidEndWithAction(nullptr)
        {
            
        }
        bool init() { return true; }
    };
}
NS_CC_END
]]
cls.funcs [[
    LuaEditBoxDelegate *create()
]]
cls.vars [[
    @nullable std::function<void(EditBox *)> onEditingDidBegin;
    @nullable std::function<void(EditBox *, const std::string &)> onTextChanged;
    @nullable std::function<void(EditBox *)> onReturn;
    @nullable std::function<void(EditBox *, EditBoxDelegate::EditBoxEndAction)> onEditingDidEndWithAction;
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::ui::EditBox::KeyboardReturnType"
cls.LUACLS = "ccui.EditBox.KeyboardReturnType"
cls.enums [[
    DEFAULT
    DONE
    SEND
    SEARCH
    GO
    NEXT
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::ui::EditBox::InputMode"
cls.LUACLS = "ccui.EditBox.InputMode"
cls.enums [[
    ANY
    EMAIL_ADDRESS
    NUMERIC
    PHONE_NUMBER
    URL
    DECIMAL
    SINGLE_LINE
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::ui::EditBox::InputFlag"
cls.LUACLS = "ccui.EditBox.InputFlag"
cls.enums [[
    PASSWORD
    SENSITIVE
    INITIAL_CAPS_WORD
    INITIAL_CAPS_SENTENCE
    INITIAL_CAPS_ALL_CHARACTERS
    LOWERCASE_ALL_CHARACTERS
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::ui::EditBox"
cls.LUACLS = "ccui.EditBox"
cls.SUPERCLS = "ccui.Widget"
cls.funcs [[
    static EditBox* create(const Size& size, Scale9Sprite* normalSprite, Scale9Sprite* pressedSprite = nullptr, Scale9Sprite* disabledSprite = nullptr)
    static EditBox* create(const Size& size, const std::string& normalImage, Widget::TextureResType texType)
    static EditBox* create(const Size& size, const std::string& normalImage, const std::string& pressedImage = "", const std::string& disabledImage = "", Widget::TextureResType texType = Widget::TextureResType::LOCAL)
    void loadTextures(const std::string& normal, const std::string& pressed, const std::string& disabled = "", Widget::TextureResType texType = Widget::TextureResType::LOCAL)
    void loadTextureNormal(const std::string& normal, Widget::TextureResType texType = Widget::TextureResType::LOCAL)
    void loadTexturePressed(const std::string& pressed, Widget::TextureResType texType = Widget::TextureResType::LOCAL)
    void loadTextureDisabled(const std::string& disabled, Widget::TextureResType texType = Widget::TextureResType::LOCAL)
    void setCapInsets(const Rect &capInsets)
    void setCapInsetsNormalRenderer(const Rect &capInsets)
    const Rect& getCapInsetsNormalRenderer()
    void setCapInsetsPressedRenderer(const Rect &capInsets)
    const Rect& getCapInsetsPressedRenderer()
    void setCapInsetsDisabledRenderer(const Rect &capInsets)
    const Rect& getCapInsetsDisabledRenderer()

    void setDelegate(@ref(single delegate) EditBoxDelegate* delegate)
    @ref(single delegate) EditBoxDelegate* getDelegate()

    void setText(const char* pText)
    const char* getText()
    void setFont(const char* pFontName, int fontSize)
    void setFontName(const char* pFontName)
    const char* getFontName()
    void setFontSize(int fontSize)
    int getFontSize()
    void setFontColor(const Color3B& color)
    void setFontColor(const Color4B& color)
    const Color4B& getFontColor()
    void setPlaceholderFont(const char* pFontName, int fontSize)
    void setPlaceholderFontName(const char* pFontName)
    const char* getPlaceholderFontName()
    void setPlaceholderFontSize(int fontSize)
    int getPlaceholderFontSize()
    void setPlaceholderFontColor(const Color3B& color)
    void setPlaceholderFontColor(const Color4B& color)
    const Color4B& getPlaceholderFontColor()
    void setPlaceHolder(const char* pText)
    const char* getPlaceHolder()
    void setInputMode(InputMode inputMode)
    InputMode getInputMode()
    void setMaxLength(int maxLength)
    int getMaxLength()
    void setInputFlag(InputFlag inputFlag)
    InputFlag getInputFlag()
    void setReturnType(KeyboardReturnType returnType)
    KeyboardReturnType getReturnType()
    void setTextHorizontalAlignment(TextHAlignment alignment)
    TextHAlignment getTextHorizontalAlignment()
    void openKeyboard()
]]

cls.props [[
    capInsetsNormalRenderer
    capInsetsPressedRenderer
    capInsetsDisabledRenderer
    delegate
    text
    fontName
    fontSize
    fontColor
    placeholderFontName
    placeholderFontSize
    placeholderFontColor
    placeHolder
    inputMode
    maxLength
    inputFlag
    returnType
    textHorizontalAlignment
]]

return M