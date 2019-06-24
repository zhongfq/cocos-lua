local M = {}

local cls = class(M)
cls.CPPCLS = "cocos2d::ui::LoadingBar::Direction"
cls.LUACLS = "ccui.LoadingBar.Direction"
cls.enums [[
    LEFT
    RIGHT
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::ui::LoadingBar"
cls.LUACLS = "ccui.LoadingBar"
cls.SUPERCLS = "ccui.Widget"
cls.funcs [[
    static LoadingBar* create()
    static LoadingBar* create(const std::string& textureName, float percentage = 0)
    void setDirection(Direction direction)
    Direction getDirection()
    void loadTexture(const std::string& texture, Widget::TextureResType texType = Widget::TextureResType::LOCAL)
    void setPercent(float percent)
    float getPercent()
    void setScale9Enabled(bool enabled)
    bool isScale9Enabled()
    void setCapInsets(const Rect &capInsets)
    const Rect& getCapInsets()
    ResourceData getRenderFile()
]]

cls.props [[
    direction
    percent
    scale9Enabled
    capInsets
    renderFile
]]

return M