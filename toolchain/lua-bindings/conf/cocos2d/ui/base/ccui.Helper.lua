local cls = class()
cls.CPPCLS = "cocos2d::ui::Helper"
cls.LUACLS = "ccui.Helper"
cls.REG_LUATYPE = false
cls.funcs [[
    static Widget* seekWidgetByTag(Widget* root, int tag)
    static Widget* seekWidgetByName(Widget* root, const std::string& name)
    static Widget* seekActionWidgetByActionTag(Widget* root, int tag)
    static void doLayout(Node *rootNode)
    static void changeLayoutSystemActiveState(bool active)
    static Rect restrictCapInsetRect(const Rect& capInsets, const Size& textureSize)
    static Rect convertBoundingBoxToScreen(Node* node)
]]
return cls