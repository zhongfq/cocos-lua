local cls = class()
cls.CPPCLS = "cocos2d::ProtectedNode"
cls.LUACLS = "cc.ProtectedNode"
cls.SUPERCLS = "cc.Node"
cls.funcs([[
    static ProtectedNode * create(void)
    void addProtectedChild(Node * child)
    void addProtectedChild(Node * child, int localZOrder)
    void addProtectedChild(Node* child, int localZOrder, int tag)
    Node * getProtectedChildByTag(int tag)
    void removeProtectedChild(Node* child, bool cleanup = true)
    void removeProtectedChildByTag(int tag, bool cleanup = true)
    void removeAllProtectedChildren()
    void removeAllProtectedChildrenWithCleanup(bool cleanup)
    void reorderProtectedChild(Node * child, int localZOrder)
    void sortAllProtectedChildren()
]])

return cls