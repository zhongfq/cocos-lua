local cls = class()
cls.CPPCLS = "cocos2d::ProtectedNode"
cls.LUACLS = "cc.ProtectedNode"
cls.SUPERCLS = "cc.Node"
cls.funcs([[
    static ProtectedNode * create(void)

    void addProtectedChild(@ref(map protectedChildren) Node * child)
    void addProtectedChild(@ref(map protectedChildren) Node * child, int localZOrder)
    void addProtectedChild(@ref(map protectedChildren) Node* child, int localZOrder, int tag)
    @ref(map protectedChildren) Node * getProtectedChildByTag(int tag)
    void removeProtectedChild(@unref(map protectedChildren) Node* child, bool cleanup = true)
    @unref(cmp protectedChildren) void removeProtectedChildByTag(int tag, bool cleanup = true)
    @unref(all protectedChildren) void removeAllProtectedChildren()
    @unref(all protectedChildren) void removeAllProtectedChildrenWithCleanup(bool cleanup)

    void reorderProtectedChild(Node * child, int localZOrder)
    void sortAllProtectedChildren()
]])

return cls