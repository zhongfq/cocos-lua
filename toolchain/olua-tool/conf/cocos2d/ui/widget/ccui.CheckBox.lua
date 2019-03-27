local M = {}

local cls = class(M)
cls.CPPCLS = "cocos2d::ui::CheckBox::EventType"
cls.LUACLS = "ccui.CheckBox.EventType"
cls.enums [[
    SELECTED
    UNSELECTED
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::ui::CheckBox"
cls.LUACLS = "ccui.CheckBox"
cls.SUPERCLS = "ccui.AbstractCheckButton"
cls.funcs [[
    static CheckBox* create()
    static CheckBox* create(const std::string& backGround, const std::string& backGroundSelected, const std::string& cross, const std::string& backGroundDisabled, const std::string& frontCrossDisabled, Widget::TextureResType texType = Widget::TextureResType::LOCAL)
    static CheckBox* create(const std::string& backGround, const std::string& cross, Widget::TextureResType texType = Widget::TextureResType::LOCAL)
]]

cls.callback(
    'void addEventListener(@nullable const std::function<void(Ref*,CheckBox::EventType)>& callback)',
    {
        CALLBACK_MAKER = 'olua_makecallbacktag("CheckBoxCallback")',
        CALLBACK_REPLACE = true,
        CALLBACK_MODE = 'OLUA_CALLBACK_TAG_ENDWITH',
    }
)

return M