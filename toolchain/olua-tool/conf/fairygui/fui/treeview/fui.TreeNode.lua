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

return cls