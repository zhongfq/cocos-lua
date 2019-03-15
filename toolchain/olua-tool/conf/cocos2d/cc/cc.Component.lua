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
cls.prop('enabled')
cls.prop('name')
cls.prop('owner')
cls.var(nil, 'std::function<void(float)> onUpdateCallback = nullptr')
cls.var(nil, 'std::function<void()> onEnterCallback = nullptr')
cls.var(nil, 'std::function<void()> onExitCallback = nullptr')
cls.var(nil, 'std::function<void()> onAddCallback = nullptr')
cls.var(nil, 'std::function<void()> onRemoveCallback = nullptr')
return cls