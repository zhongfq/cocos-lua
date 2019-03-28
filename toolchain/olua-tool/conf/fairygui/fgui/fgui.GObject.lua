local cls = class()
cls.CPPCLS = "fairygui::GObject"
cls.LUACLS = "fgui.GObject"
cls.SUPERCLS = "fgui.UIEventDispatcher"
cls.funcs [[
    static GObject* getDraggingObject()
    static GObject* create()
    float getX()
    void setX(float value)
    float getY()
    void setY(float value)
    @unpack const cocos2d::Vec2& getPosition()
    void setPosition(float xv, float yv)
    float getXMin()
    void setXMin(float value)
    float getYMin()
    void setYMin(float value)
    bool isPixelSnapping()
    void setPixelSnapping(bool value)
    float getWidth()
    void setWidth(float value)
    float getHeight()
    void setHeight(float value)
    @unpack const cocos2d::Size& getSize()
    void setSize(float wv, float hv, bool ignorePivot = false)
    void center(bool restraint = false)
    void makeFullScreen()
    @unpack const cocos2d::Vec2& getPivot()
    void setPivot(float xv, float yv, bool asAnchor = false)
    bool isPivotAsAnchor()
    float getScaleX()
    void setScaleX(float value)
    float getScaleY()
    void setScaleY(float value)
    @unpack const cocos2d::Vec2& getScale()
    void setScale(float xv, float yv)
    float getSkewX()
    void setSkewX(float value)
    float getSkewY()
    void setSkewY(float value)
    float getRotation()
    void setRotation(float value)
    float getAlpha()
    void setAlpha(float value)
    bool isGrayed()
    void setGrayed(bool value)
    bool isVisible()
    void setVisible(bool value)
    bool isTouchable()
    void setTouchable(bool value)
    int getSortingOrder()
    void setSortingOrder(int value)
    GGroup* getGroup()
    void setGroup(GGroup* value)
    const std::string& getText()
    void setText(const std::string& text)
    const std::string& getIcon()
    void setIcon(const std::string& text)
    const std::string& getTooltips()
    void setTooltips(const std::string& value)
    void* getData()
    void setData(void* value)
    const cocos2d::Value& getCustomData()
    void setCustomData(const cocos2d::Value& value)
    bool isDraggable()
    void setDraggable(bool value)
    void setDragBounds(const cocos2d::Rect& value)
    void startDrag(int touchId = -1)
    void stopDrag()
    std::string getResourceURL()
    PackageItem* getPackageItem()
    cocos2d::Vec2 globalToLocal(const cocos2d::Vec2& pt)
    cocos2d::Rect globalToLocal(const cocos2d::Rect& rect)
    cocos2d::Vec2 localToGlobal(const cocos2d::Vec2& pt)
    cocos2d::Rect localToGlobal(const cocos2d::Rect& rect)
    cocos2d::Rect transformRect(const cocos2d::Rect& rect, GObject* targetSpace)
    Relations* relations()
    void addRelation(GObject* target, RelationType relationType, bool usePercent = false)
    void removeRelation(GObject* target, RelationType relationType)
    GearBase* getGear(int index)
    bool checkGearController(int index, GController* c)
    uint32_t addDisplayLock()
    void releaseDisplayLock(uint32_t token)
    GComponent* getParent()
    GObject* findParent()
    cocos2d::Node* displayObject()
    GRoot* getRoot()
    bool onStage()
    void removeFromParent()
    void constructFromResource()
    GObject* hitTest(const cocos2d::Vec2 & worldPoint, const cocos2d::Camera * camera)
]]
cls.func('getDragBounds', [[
{
    lua_settop(L, 1);
    fairygui::GObject *self = (fairygui::GObject *)olua_toobj(L, 1, "fgui.GObject");
    cocos2d::Rect *rect = self->getDragBounds();
    manual_luacv_push_cocos2d_Rect(L, rect);
    return 1;
}]])

cls.callback(
    'void addClickListener(const std::function<void(@stack EventContext* context)>& callback)',
    'void addClickListener(const std::function<void(@stack EventContext* context)>& callback, const EventTag& tag)',
    {
        CALLBACK_MAKER = {
            'makeListenerTag(L, fairygui::UIEventType::Click, 0)', -- no tag
            'makeListenerTag(L, fairygui::UIEventType::Click, 3)', -- tag stack idx
        },
    }
)
cls.callback(
    'void removeClickListener(const EventTag& tag)',
    {
        CALLBACK_MAKER = 'makeListenerTag(L, fairygui::UIEventType::Click, 2)',
        CALLBACK_MODE = 'OLUA_CALLBACK_TAG_ENDWITH',
        CALLBACK_REMOVE = true,
    }
)

cls.props [[
    x
    y
    xMin
    yMin
    pixelSnapping
    width
    height
    pivotAsAnchor
    scaleX
    scaleY
    skewX
    skewY
    rotation
    alpha
    grayed
    visible
    touchable
    sortingOrder
    group
    text
    icon
    tooltips
    data
    customData
    draggable
    resourceURL
    packageItem
    parent
    root
]]

cls.prop('relations', 'Relations* relations()')
cls.prop('displayObject', 'cocos2d::Node* displayObject()')

return cls