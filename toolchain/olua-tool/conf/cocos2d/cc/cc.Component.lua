local cls = class()
cls.CPPCLS = "cocos2d::LuaComponent"
cls.RAWCPPCLS = "cocos2d::Component"
cls.LUACLS = "cc.Component"
cls.SUPERCLS = "cc.Ref"
cls.funcs([[
    static LuaComponent* create()
    bool isEnabled()
    void setEnabled(bool enabled)
    const std::string& getName()
    void setName(const std::string& name)
    @ref(single owner) Node* getOwner()
    void setOwner(@ref(single owner) Node *owner)
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
cls.vars [[
    @nullable std::function<void(float)> onUpdateCallback;
    @nullable std::function<void()> onEnterCallback;
    @nullable std::function<void()> onExitCallback;
    @nullable std::function<void()> onAddCallback;
    @nullable std::function<void()> onRemoveCallback;
]]
return cls