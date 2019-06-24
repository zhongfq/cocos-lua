local cls = class()
cls.CPPCLS = "fairygui::TreeNode"
cls.LUACLS = "fui.TreeNode"
cls.SUPERCLS = "cc.Ref"
cls.funcs [[
    static TreeNode* create(bool isFolder = false)
    TreeNode* getParent()
    TreeView* getRoot()
    
    @ref(single cell) GComponent* getCell()
    
    const cocos2d::Value& getData()
    void setData(const cocos2d::Value& value)
    bool isExpanded()
    void setExpaned(bool value)
    bool isFolder()
    const std::string& getText()

    TreeNode* addChild(@ref(map children) TreeNode* child)
    TreeNode* addChildAt(@ref(map children) TreeNode* child, int index)
    void removeChild(@unref(map children) TreeNode * child)
    @unref(cmp children) void removeChildAt(int index)
    @unref(cmp children) void removeChildren()
    @unref(cmp children) void removeChildren(int beginIndex, int endIndex)
    @ref(map children) TreeNode* getChildAt(int index)
    @ref(map children) TreeNode* getPrevSibling()
    @ref(map children) TreeNode* getNextSibling()

    int getChildIndex(const TreeNode* child)
    void setChildIndex(TreeNode* child, int index)
    int setChildIndexBefore(TreeNode* child, int index)
    void swapChildren(TreeNode* child1, TreeNode* child2)
    void swapChildrenAt(int index1, int index2)
    int numChildren()
]]

cls.props [[
    parent
    root
    cell
    data
    expanded
    folder
    text
    prevSibling
    nextSibling
]]
cls.prop('numChildren', 'int numChildren()')


cls.inject('addChildAt', {
    BEFORE = format_snippet [[
        if (!(arg2 >= 0 && arg2 <= self->numChildren())) {
            luaL_error(L, "index out of range");
        }
    ]]
})
cls.inject({'getChildAt', 'removeChildAt'}, {
    BEFORE = format_snippet [[
        if (!(arg1 >= 0 && arg1 < self->numChildren())) {
            luaL_error(L, "index out of range");
        }
    ]]
})
cls.inject('removeChildren', {
    BEFORE = format_snippet [[
        if (lua_gettop(L) == 3) {
            int arg1 = (int)olua_checkinteger(L, 2);
            int arg2 = (int)olua_checkinteger(L, 3);
            if (!(arg1 >= 0 && arg1 < self->numChildren())) {
                luaL_error(L, "beginIndex index out of range");
            }
            if (!(arg2 == -1 || (arg2 >= 0 && arg2 < self->numChildren()))) {
                luaL_error(L, "endIndex index out of range");
            }
        }
    ]]
})

return cls