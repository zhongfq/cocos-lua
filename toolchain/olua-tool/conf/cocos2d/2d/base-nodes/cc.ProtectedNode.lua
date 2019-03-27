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

--
-- ref
--
local REMOVE_BY_TAG = {
    BEFORE = [[
        cocos2d::Node *child = self->getProtectedChildByTag((int)arg1);
        if (olua_getobj(L, child)) {
            olua_mapunref(L, 1, "protectedChildren", -1);
            lua_pop(L, 1);
        }
    ]]
}
-- void addProtectedChild(Node * child)
-- void addProtectedChild(Node * child, int localZOrder)
-- void addProtectedChild(Node* child, int localZOrder, int tag)
-- Node *getProtectedChildByTag(int tag) const
-- void removeProtectedChildByTag(int tag, bool cleanup = true)
-- void removeProtectedChild(Node* child, bool cleanup = true)
-- void removeAllProtectedChildren()
-- void removeAllProtectedChildrenWithCleanup(bool cleanup)
cls.inject('addProtectedChild',                     mapref_arg_value('protectedChildren'))
cls.inject('getProtectedChildByTag',                mapref_return_value('protectedChildren'))
cls.inject('removeProtectedChildByTag',             REMOVE_BY_TAG)
cls.inject('removeProtectedChild',                  mapunref_arg_value('protectedChildren'))
cls.inject('removeAllProtectedChildren',            mapunref_all('protectedChildren'))
cls.inject('removeAllProtectedChildrenWithCleanup', mapunref_all('protectedChildren'))

return cls