local cls = class()
cls.CPPCLS = "cocos2d::Node"
cls.LUACLS = "cc.Node"
cls.SUPERCLS = "cc.Ref"
cls.func(nil, 'static cocos2d::Node *create()')
cls.func(nil, 'void addChild(cocos2d::Node * child)', 'void addChild(cocos2d::Node * child, int localZOrder)', 'void addChild(cocos2d::Node* child, int localZOrder, int tag)', 'void addChild(cocos2d::Node* child, int localZOrder, const std::string &name)')
cls.func(nil, 'cocos2d::Node *getChildByTag(int tag) const')
cls.func(nil, 'void removeFromParent()')
cls.func(nil, 'void removeFromParentAndCleanup(bool cleanup)')
cls.func(nil, 'void removeChild(cocos2d::Node* child, bool cleanup = true)')
cls.func(nil, 'void removeChildByTag(int tag, bool cleanup = true)')
cls.func(nil, 'void removeChildByName(const std::string &name, bool cleanup = true)')
cls.func(nil, 'void removeAllChildren()')
cls.func(nil, 'void removeAllChildrenWithCleanup(bool cleanup)')
cls.func(nil, 'void reorderChild(cocos2d::Node * child, int localZOrder)')
cls.func(nil, 'void sortAllChildren()')
return cls