local cls = class()
cls.CPPCLS = "cocos2d::ui::PageViewIndicator"
cls.LUACLS = "ccui.PageViewIndicator"
cls.SUPERCLS = "cc.ProtectedNode"
cls.funcs [[
    static PageViewIndicator* create()
    void setDirection(ScrollView::Direction direction)
    void reset(ssize_t numberOfTotalPages)
    void indicate(ssize_t index)
    void clear()
    void setSpaceBetweenIndexNodes(float spaceBetweenIndexNodes)
    float getSpaceBetweenIndexNodes()
    void setSelectedIndexColor(const Color3B& color)
    const Color3B& getSelectedIndexColor()
    void setIndexNodesColor(const Color3B& indexNodesColor)
    const Color3B& getIndexNodesColor()
    void setIndexNodesScale(float indexNodesScale)
    float getIndexNodesScale()
    void setSelectedIndexOpacity(GLubyte opacity)
    GLubyte getSelectedIndexOpacity()
    void setIndexNodesOpacity(GLubyte opacity)
    GLubyte getIndexNodesOpacity()
    void setIndexNodesTexture(const std::string& texName,Widget::TextureResType texType = Widget::TextureResType::LOCAL)
]]

cls.props [[
    spaceBetweenIndexNodes
    selectedIndexColor
    indexNodesColor
    indexNodesScale
    selectedIndexOpacity
    indexNodesOpacity
]]

return cls