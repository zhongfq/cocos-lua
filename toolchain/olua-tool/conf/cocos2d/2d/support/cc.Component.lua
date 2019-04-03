local M = {}

local cls = class(M)
cls.CPPCLS = "cocos2d::Component"
cls.LUACLS = "cc.Component"
cls.SUPERCLS = "cc.Ref"
cls.funcs([[
    static Component* create()
    bool isEnabled()
    void setEnabled(bool enabled)
    const std::string& getName()
    void setName(const std::string& name)
    @ref(singleref owner) Node* getOwner()
    void setOwner(@ref(singleref owner) Node *owner)
    void update(float delta)
    bool serialize(void* r)
    void onEnter()
    void onExit()
    void onAdd()
    void onRemove()
]])
cls.props [[
    enabled
    name
    owner
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::LuaComponent"
cls.LUACLS = "cc.LuaComponent"
cls.SUPERCLS = "cc.Component"
cls.funcs [[
    static LuaComponent* create()
]]
cls.vars [[
    @nullable std::function<void(float)> onUpdateCallback;
    @nullable std::function<void()> onEnterCallback;
    @nullable std::function<void()> onExitCallback;
    @nullable std::function<void()> onAddCallback;
    @nullable std::function<void()> onRemoveCallback;
]]

return M