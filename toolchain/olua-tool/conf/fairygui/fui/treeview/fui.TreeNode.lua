local cls = class()
cls.CPPCLS = "fairygui::TreeNode"
cls.LUACLS = "fui.TreeNode"
cls.SUPERCLS = "cc.Ref"
cls.funcs [[
    static TreeNode* create(bool isFolder = false)
    TreeNode* getParent()
    TreeView* getRoot()
    GComponent* getCell()
    const cocos2d::Value& getData()
    void setData(const cocos2d::Value& value)
    bool isExpanded()
    void setExpaned(bool value)
    bool isFolder()
    const std::string& getText()
    TreeNode* addChild(TreeNode* child)
    TreeNode* addChildAt(TreeNode* child, int index)
    void removeChild(TreeNode * child)
    void removeChildAt(int index)
    void removeChildren()
    void removeChildren(int beginIndex, int endIndex)
    TreeNode* getChildAt(int index)
    TreeNode* getPrevSibling()
    TreeNode* getNextSibling()
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

-- ref
do
    local REFNAME = 'children'
    local CHECK_RANGE = {
        BEFORE = format_snippet [[
            if (!(arg1 >= 0 && arg1 < self->numChildren())) {
                luaL_error(L, "index out of range");
            }
        ]]
    }
    local CHECK_ADD_RANGE = {
        BEFORE = format_snippet [[
            if (!(arg2 >= 0 && arg2 <= self->numChildren())) {
                luaL_error(L, "index out of range");
            }
        ]]
    }
    local UNREF_BY_INDEX = {
        BEFORE = format_snippet [[
            fairygui::TreeNode *child = self->getChildAt((int)arg1);
            if (olua_getobj(L, child)) {
                olua_mapunref(L, 1, "${REFNAME}", -1);
                lua_pop(L, 1);
            }
        ]]
    }
    local CHECK_REMOVE_CHILDREN_RANGE = {
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
    }
    -- GObject* addChild(GObject* child)
    cls.inject('addChild',      mapref_arg_value(REFNAME))

    -- GObject* addChildAt(GObject* child, int index)
    cls.inject('addChildAt',    mapref_combo(CHECK_ADD_RANGE, mapref_arg_value(REFNAME)))

    -- void removeChild(GObject * child);
    cls.inject('removeChild',   mapunref_arg_value(REFNAME))

    -- void removeChildAt(int index);
    cls.inject('removeChildAt', mapref_combo(CHECK_RANGE, UNREF_BY_INDEX))

    -- void removeChildren() { removeChildren(0, -1); }
    -- void removeChildren(int beginIndex, int endIndex);
    cls.inject('removeChildren', mapref_combo(CHECK_REMOVE_CHILDREN_RANGE, mapunef_by_compare(REFNAME)))

    -- GObject *getChildAt(int index) const;
    cls.inject('getChildAt',    mapref_combo(CHECK_RANGE, mapref_return_value(REFNAME)))

    -- TreeNode* getPrevSibling()
    -- TreeNode* getNextSibling()
    cls.inject('getPrevSibling', mapref_return_value(REFNAME))
    cls.inject('getNextSibling', mapref_return_value(REFNAME))
end

return cls