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
cls.CHUNK = [[
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

    @unref(cmp children parent)@ref(map children parent) void show()
    @unref(cmp children parent) void hide()
    @unref(cmp children parent) void hideImmediately()

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

    @ref(single contentPane) GComponent* getContentPane()
    void setContentPane(@ref(single contentPane) GComponent* value)

    @ref(single frame) GComponent* getFrame()

    @ref(single closeButton) GObject* getCloseButton()
    void setCloseButton(@ref(single closeButton) GObject* value)

    @ref(single dragArea) GObject* getDragArea()
    void setDragArea(@ref(single dragArea) GObject* value)

    @ref(single contentArea) GObject* getContentArea()
    void setContentArea(@ref(single contentArea) GObject* value)

    @ref(single modalWaitingPane) GObject* getModalWaitingPane()
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

local REFNAME = 'children'
cls.inject('show', {
    BEFORE = format_snippet [[
        fairygui::GComponent *root = fairygui::UIRoot;
        if (!root) {
            luaL_error(L, "no root to add 'Window'");
        }
        olua_push_cppobj<fairygui::GComponent>(L, root, "fui.GComponent");
        int parent = lua_gettop(L);
    ]]
})

cls.inject({'hide', 'hideImmediately'}, {
    BEFORE = format_snippet [[
        fairygui::GComponent *root = self->getParent() ? self->getParent() : fairygui::UIRoot;
        if (!root) {
            return 0;
        }
        olua_push_cppobj<fairygui::GComponent>(L, root, "fui.GComponent");
        int parent = lua_gettop(L);
    ]]
})

return M