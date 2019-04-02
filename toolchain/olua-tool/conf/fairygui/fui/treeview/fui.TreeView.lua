local cls = class()
cls.CPPCLS = "fairygui::TreeView"
cls.LUACLS = "fui.TreeView"
cls.SUPERCLS = "fui.UIEventDispatcher"
cls.funcs [[
    static TreeView* create(GList* list)
    GList* getList()
    TreeNode* getRootNode()
    TreeNode* getSelectedNode()
    void addSelection(TreeNode* node, bool scrollItToView = false)
    void removeSelection(TreeNode* node)
    void clearSelection()
    int getNodeIndex(TreeNode* node)
    void updateNode(TreeNode* node)
    void expandAll(TreeNode* folderNode)
    void collapseAll(TreeNode* folderNode)
]]

cls.func('getSelection', [[
{
    lua_settop(L, 2);

    fairygui::GList *self = (fairygui::GList *)olua_toobj(L, 1, "fui.GList");
    std::vector<int> selections;
    self->getSelection(selections);
    int idx = 1;
    lua_createtable(L, (int)selections.size(), 0);
    for (auto v : selections) {
        lua_pushinteger(L, v);
        lua_rawseti(L, -2, idx++);
    }

    return 1;
}]])

cls.props [[
    list
    rootNode
    selectedNode
    selection
]]

cls.vars [[
    std::function<GComponent*(TreeNode* node)> treeNodeCreateCell;
    std::function<void(TreeNode* node)> treeNodeRender;
    std::function<void(TreeNode* node, bool expand)> treeNodeWillExpand;
]]

-- ref
-- static TreeView* create(GList* list)
-- GList* getList()
cls.inject('create', {AFTER = 'olua_singleref(L, -1, "list", 1);'})
cls.inject('getList', {AFTER = 'olua_singleref(L, 1, "list", -1);'})

local REFNAME = 'nodes'
-- TreeNode* getRootNode()
-- TreeNode* getSelectedNode()
cls.inject('getRootNode',       mapref_return_value(REFNAME))
cls.inject('getSelectedNode',   mapref_return_value(REFNAME))
-- void addSelection(TreeNode* node, bool scrollItToView = false)
cls.inject('addSelection',      mapref_arg_value(REFNAME))
-- void removeSelection(TreeNode* node)
cls.inject('removeSelection',   mapunref_arg_value(REFNAME))
-- void clearSelection()
cls.inject('clearSelection',    mapunref_all(REFNAME))


return cls