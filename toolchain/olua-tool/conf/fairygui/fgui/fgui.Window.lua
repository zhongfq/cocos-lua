local M = {}

local cls = class(M)
cls.CPPCLS = "fairygui::IUISource"
cls.LUACLS = "fgui.IUISource"
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
cls.LUACLS = "fgui.UISource"
cls.SUPERCLS = "fgui.IUISource"
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
cls.LUACLS = "fgui.Window"
cls.SUPERCLS = "fgui.GComponent"
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
    GComponent* getContentPane()
    void setContentPane(GComponent* value)
    GComponent* getFrame()
    GObject* getCloseButton()
    void setCloseButton(GObject* value)
    GObject* getDragArea()
    void setDragArea(GObject* value)
    GObject* getContentArea()
    void setContentArea(GObject* value)
    GObject* getModalWaitingPane()
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

return M