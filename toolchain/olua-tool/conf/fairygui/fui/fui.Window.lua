local M = {}

local cls = class(M)
cls.CPPCLS = "fairygui::IUISource"
cls.LUACLS = "fui.IUISource"
cls.SUPERCLS = "cc.Ref"
cls.funcs [[
    const std::string& getFileName()
    void setFileName(const std::string& value)
    bool isLoaded()
]]
cls.callbacks [[
    void load(@nullable std::function<void()> callback)
]]
cls.props [[
    fileName
    loaded
]]

local cls = class(M)
cls.CPPCLS = "fairygui::UISource"
cls.LUACLS = "fui.UISource"
cls.SUPERCLS = "fui.IUISource"
cls.DEFCHUNK = [[
NS_FGUI_BEGIN
class UISource : public IUISource {
public:
    CREATE_FUNC(UISource);

    virtual const std::string& getFileName() { return _name; }
    virtual void setFileName(const std::string& value) { _name = value; }
    virtual bool isLoaded() { return _loaded; }
    virtual void load(std::function<void()> callback) { _complete = callback; }

    void loadComplete()
    {
        _loaded = true;
        if (_complete) {
            _complete();
        }
    }
private:
    UISource() 
        :_loaded(false)
        ,_complete(nullptr)
    {
    }

    bool init()
    {
        return true;
    }

    std::function<void()> _complete;
    std::string _name;
    bool _loaded;
};
NS_FGUI_END
]]
cls.funcs [[
    static UISource *create()
    void loadComplete()
]]

local cls = class(M)
cls.CPPCLS = "fairygui::Window"
cls.LUACLS = "fui.Window"
cls.SUPERCLS = "fui.GComponent"
cls.funcs [[
    static Window *create()
    void show()
    void hide()
    void hideImmediately()
    void toggleStatus()
    void bringToFront()
    bool isShowing()
    bool isTop()
    bool isModal()
    void setModal(bool value)
    void showModalWait()
    void showModalWait(int requestingCmd)
    bool closeModalWait()
    bool closeModalWait(int requestingCmd)
    void initWindow()
    void addUISource(IUISource* uiSource)
    bool isBringToFrontOnClick()
    void setBringToFrontOnClick(bool value)

    @singleref(contentPane) GComponent* getContentPane()
    void setContentPane(@singleref(contentPane) GComponent* value)

    @singleref(frame) GComponent* getFrame()

    @singleref(closeButton) GObject* getCloseButton()
    void setCloseButton(@singleref(closeButton) GObject* value)

    @singleref(dragArea) GObject* getDragArea()
    void setDragArea(@singleref(dragArea) GObject* value)

    @singleref(contentArea) GObject* getContentArea()
    void setContentArea(@singleref(contentArea) GObject* value)

    @singleref(modalWaitingPane) GObject* getModalWaitingPane()
]]
cls.props [[
    showing
    top
    modal
    bringToFrontOnClick
    contentPane
    frame
    closeButton
    dragArea
    contentArea
    modalWaitingPane
]]

-- ref
do
    local REFNAME = 'children'
    -- void show()
    local SHOW_WINDOW = {
        BEFORE = format_snippet [[
            if (UIRoot == nullptr) {
                luaL_error(L, "UIRoot is nullptr");
            }
        ]],
        AFTER = format_snippet [[
            olua_push_cppobj<fairygui::GComponent>(L, UIRoot, "fui.GComponent");
            olua_mapref(L, -1, "${REFNAME", 1);
            lua_pop(L, 1);
        ]]
    }


    -- void hide()
    -- void hideImmediately()
    local HIDE_WINDOW = {
        BEFORE = format_snippet [[
            if (self->getParent()) {
                olua_push_cppobj<fairygui::GComponent>(L, self->getParent(), "fui.GComponent");
                xlua_startcmpunref(L, -1, "children");
            } else {
                lua_pushnil(L);
            }
        ]],
        AFTER = format_snippet [[
            if (!olua_isnil(L, -1)) {
                xlua_endcmpunref(L, -1, "children");
            }
        ]]
    }
    cls.inject('hide',              HIDE_WINDOW)
    cls.inject('hideImmediately',   HIDE_WINDOW)
end

return M