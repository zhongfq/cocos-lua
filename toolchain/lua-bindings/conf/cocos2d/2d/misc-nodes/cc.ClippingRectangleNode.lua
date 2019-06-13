local cls = class()
cls.CPPCLS = "cocos2d::ClippingRectangleNode"
cls.LUACLS = "cc.ClippingRectangleNode"
cls.SUPERCLS = "cc.Node"
cls.funcs [[
        static ClippingRectangleNode* create(const Rect& clippingRegion)
        static ClippingRectangleNode* create()
        const Rect& getClippingRegion()
        void setClippingRegion(const Rect& clippingRegion)
        bool isClippingEnabled()
        void setClippingEnabled(bool enabled)
]]

cls.props [[
    clippingRegion
    clippingEnabled
]]

return cls