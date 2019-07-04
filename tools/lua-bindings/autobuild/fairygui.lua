require "autobuild.fairygui-types"

local cls
local M = {}
M.NAME = "fairygui"
M.HEADER_PATH = "frameworks/libxgame/src/lua-bindings/lua_fairygui.h"
M.SOURCE_PATH = "frameworks/libxgame/src/lua-bindings/lua_fairygui.cpp"
M.INCLUDES = [[
#include "lua-bindings/lua_fairygui.h"
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "xgame/xlua.h"
#include "FairyGUI.h"
#include "tween/EaseManager.h"
]]
M.CHUNK = [[
bool manual_luacv_is_fairygui_EventTag(lua_State *L, int idx)
{
    return olua_isinteger(L, idx) || olua_isa(L, idx, OLUA_VOIDCLS);
}

void manual_luacv_check_fairygui_EventTag(lua_State *L, int idx, fairygui::EventTag *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    if (olua_isinteger(L, idx)) {
        *value = (int)olua_tointeger(L, idx);
    } else {
        *value = (void *)olua_checkobj(L, idx, OLUA_VOIDCLS);
    }
}]]

M.CONVS = {
    REG_CONV {
        CPPCLS = 'fairygui::Margin',
        DEF = [[
            float left;
            float top;
            float right;
            float bottom;
        ]]
    },
    REG_CONV {
        CPPCLS = 'fairygui::TweenValue',
        DEF = [[
            float x = 0;
            float y = 0;
            float z = 0;
            float w = 0;
            double d = 0;
        ]]
    },
}

M.CLASSES = {}

cls = class(M.CLASSES)
cls.CPPCLS = "fairygui::UIEventType"
cls.enums [[
    Enter
    Exit
    Changed
    Submit
    TouchBegin
    TouchMove
    TouchEnd
    Click
    RollOver
    RollOut
    MouseWheel
    RightClick
    MiddleClick
    PositionChange
    SizeChange
    KeyDown
    KeyUp
    Scroll
    ScrollEnd
    PullDownRelease
    PullUpRelease
    ClickItem
    ClickLink
    ClickMenu
    RightClickItem
    DragStart
    DragMove
    DragEnd
    Drop
    GearStop
]]
cls.funcs [[
]]

cls = class(M.CLASSES)
cls.CPPCLS = "fairygui::UIEventDispatcher"
cls.SUPERCLS = "cocos2d::Ref"
cls.CHUNK = [[
static std::string makeListenerTag(lua_State *L, lua_Integer type, int tagidx)
{
    char buf[64];
    intptr_t tag = 0;
    if (tagidx > 0) {
        if (olua_isinteger(L, tagidx)) {
            tag = (intptr_t)olua_tointeger(L, tagidx);
        } else {
            tag = (intptr_t)olua_checkobj(L, tagidx, OLUA_VOIDCLS);
        }
    }
    if (type < 0) {
        sprintf(buf, "listeners.");
    } else if (tag > 0) {
        sprintf(buf, "listeners.%d.%p", (int)type, (void *)tag);
    } else {
        sprintf(buf, "listeners.%d", (int)type);
    }
    return std::string(buf);
}]]
cls.funcs [[
    bool hasEventListener(int eventType)
    bool hasEventListener(int eventType, const EventTag& tag)
    bool dispatchEvent(int eventType, void* data = nullptr, const cocos2d::Value& dataValue = cocos2d::Value::Null)
    bool bubbleEvent(int eventType, void* data = nullptr, const cocos2d::Value& dataValue = cocos2d::Value::Null)
    bool isDispatchingEvent(int eventType)
]]
cls.callback {
    FUNCS =  {
        'void addEventListener(int eventType, const std::function<void(@stack EventContext* context)>& callback)',
        'void addEventListener(int eventType, const std::function<void(@stack EventContext* context)>& callback, const EventTag& tag)',
    },
    TAG_MAKER = {'makeListenerTag(L, #1, 0)', 'makeListenerTag(L, #1, 4)'},
    TAG_MODE = 'OLUA_CALLBACK_TAG_NEW',
    CALLONCE = false,
    REMOVE = false,
}
cls.callback {
    FUNCS =  {
        'void removeEventListener(int eventType)',
        'void removeEventListener(int eventType, const EventTag& tag)',
    },
    TAG_MAKER = {'makeListenerTag(L, #1, 0)', 'makeListenerTag(L, #1, 3)'},
    TAG_MODE = {'OLUA_CALLBACK_TAG_WILDCARD', 'OLUA_CALLBACK_TAG_ENDWITH'},
    CALLONCE = false,
    REMOVE = true,
}
cls.callback {
    FUNCS =  {
        'void removeEventListeners()',
    },
    TAG_MAKER = 'makeListenerTag(L, -1, 0)',
    TAG_MODE = 'OLUA_CALLBACK_TAG_WILDCARD',
    CALLONCE = false,
    REMOVE = true,
}

cls = class(M.CLASSES)
cls.CPPCLS = "fairygui::EventContext"
cls.funcs [[
    int getType()
    cocos2d::Ref* getSender()
    InputEvent* getInput()
    void stopPropagation()
    void preventDefault()
    bool isDefaultPrevented()
    void captureTouch()
    void uncaptureTouch()
    const cocos2d::Value& getDataValue()
    void* getData()
]]
cls.props [[
    type
    sender
    input
    defaultPrevented
    dataValue
    data
]]

cls = class(M.CLASSES)
cls.CPPCLS = "fairygui::IHitTest"
cls.funcs [[
    bool hitTest(GComponent* obj, const cocos2d::Vec2& localPoint)
]]

cls = class(M.CLASSES)
cls.CPPCLS = "fairygui::InputProcessor"
cls.funcs [[
    InputEvent* getRecentInput()
    static bool isTouchOnUI()
    cocos2d::Vec2 getTouchPosition(int touchId)
    void addTouchMonitor(int touchId, GObject* target)
    void removeTouchMonitor(GObject* target)
    void cancelClick(int touchId)
    void simulateClick(GObject* target, int touchId = -1)
]]
cls.callback {
    FUNCS =  {
        'void setCaptureCallback(@nullable std::function<void(int eventType)> value)',
    },
    TAG_MAKER = 'olua_makecallbacktag("captureCallback")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
    CALLONCE = false,
    REMOVE = false,
}
cls.props [[
    recentInput
    touchOnUI
]]

cls = class(M.CLASSES)
cls.CPPCLS = "fairygui::InputEvent"
cls.funcs [[
    GObject* getTarget()
    const int getX()
    const int getY()
    const cocos2d::Vec2& getPosition()
    cocos2d::Touch* getTouch()
    int getTouchId()
    int isDoubleClick()
    cocos2d::EventMouse::MouseButton getButton()
    cocos2d::EventKeyboard::KeyCode getKeyCode()
    bool isCtrlDown()
    bool isAltDown()
    bool isShiftDown()
    int getMouseWheelDelta()
    InputProcessor* getProcessor()
]]
cls.props [[
    target
    x
    y
    position
    touch
    touchId
    doubleClick
    button
    keyCode
    ctrlDown
    altDown
    shiftDown
    mouseWheelDelta
    processor
]]

cls = class(M.CLASSES)
cls.CPPCLS = "fairygui::TextFormat"
cls.enums [[
    OUTLINE
    SHADOW
    GLOW
]]
cls.funcs [[
    void enableEffect(int effectFlag)
    void disableEffect(int effectFlag)
    bool hasEffect(int effectFlag)
]]
cls.var('face', [[std::string face]])
cls.var('fontSize', [[float fontSize]])
cls.var('color', [[cocos2d::Color3B color]])
cls.var('bold', [[bool bold]])
cls.var('italics', [[bool italics]])
cls.var('underline', [[bool underline]])
cls.var('lineSpacing', [[int lineSpacing]])
cls.var('letterSpacing', [[int letterSpacing]])
cls.var('align', [[cocos2d::TextHAlignment align]])
cls.var('verticalAlign', [[cocos2d::TextVAlignment verticalAlign]])
cls.var('effect', [[int effect]])
cls.var('outlineColor', [[cocos2d::Color3B outlineColor]])
cls.var('outlineSize', [[int outlineSize]])
cls.var('shadowColor', [[cocos2d::Color3B shadowColor]])
cls.var('shadowOffset', [[cocos2d::Size shadowOffset]])
cls.var('shadowBlurRadius', [[int shadowBlurRadius]])
cls.var('glowColor', [[cocos2d::Color3B glowColor]])
cls.func('setFormat', [[{
    lua_settop(L, 2);
    fairygui::TextFormat *self = (fairygui::TextFormat *)olua_toobj(L, 1, "fui.TextFormat");
    fairygui::TextFormat *fmt = (fairygui::TextFormat *)olua_toobj(L, 2, "fui.TextFormat");
    self->setFormat(*fmt);
    return 0;
}]])

cls = class(M.CLASSES)
cls.CPPCLS = "fairygui::EaseType"
cls.enums [[
    Linear
    SineIn
    SineOut
    SineInOut
    QuadIn
    QuadOut
    QuadInOut
    CubicIn
    CubicOut
    CubicInOut
    QuartIn
    QuartOut
    QuartInOut
    QuintIn
    QuintOut
    QuintInOut
    ExpoIn
    ExpoOut
    ExpoInOut
    CircIn
    CircOut
    CircInOut
    ElasticIn
    ElasticOut
    ElasticInOut
    BackIn
    BackOut
    BackInOut
    BounceIn
    BounceOut
    BounceInOut
    Custom
]]

cls = class(M.CLASSES)
cls.CPPCLS = "fairygui::EaseManager"
cls.funcs [[
    static float evaluate(EaseType easeType, float time, float duration, float overshootOrAmplitude, float period)
]]

cls = class(M.CLASSES)
cls.CPPCLS = "fairygui::TweenPropType"
cls.enums [[
    None
    X
    Y
    Position
    Width
    Height
    Size
    ScaleX
    ScaleY
    Scale
    Rotation
    Alpha
    Progress
]]

cls = class(M.CLASSES)
cls.CPPCLS = "fairygui::GTweener"
cls.SUPERCLS = "cocos2d::Ref"
cls.funcs [[
    GTweener* setDelay(float value)
    float getDelay()
    GTweener* setDuration(float value)
    float getDuration()
    GTweener* setBreakpoint(float value)
    GTweener* setEase(EaseType value)
    GTweener* setEasePeriod(float value)
    GTweener* setEaseOvershootOrAmplitude(float value)
    GTweener* setRepeat(int repeat, bool yoyo = false)
    int getRepeat()
    GTweener* setTimeScale(float value)
    GTweener* setSnapping(bool value)
    GTweener* setTargetAny(void* value)
    GTweener* setTarget(cocos2d::Ref* target)
    GTweener* setTarget(cocos2d::Ref* target, TweenPropType propType)
    void* getTarget()
    GTweener* setUserData(const cocos2d::Value& value)
    const cocos2d::Value& getUserData()
    float getNormalizedTime()
    bool isCompleted()
    bool allCompleted()
    GTweener* setPaused(bool paused)
    void seek(float time)
    void kill(bool complete = false)
]]
cls.var('startValue', [[TweenValue startValue]])
cls.var('endValue', [[TweenValue endValue]])
cls.var('value', [[TweenValue value]])
cls.var('deltaValue', [[TweenValue deltaValue]])
cls.callback {
    FUNCS =  {
        'GTweener* onUpdate(std::function<void(GTweener* tweener)> callback)',
    },
    TAG_MAKER = 'olua_makecallbacktag("onUpdate")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
    CALLONCE = false,
    REMOVE = false,
}
cls.callback {
    FUNCS =  {
        'GTweener* onStart(std::function<void(GTweener* tweener)> callback)',
    },
    TAG_MAKER = 'olua_makecallbacktag("onStart")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
    CALLONCE = false,
    REMOVE = false,
}
cls.callback {
    FUNCS =  {
        'GTweener* onComplete(std::function<void()> callback)',
    },
    TAG_MAKER = 'olua_makecallbacktag("onComplete")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
    CALLONCE = false,
    REMOVE = false,
}
cls.callback {
    FUNCS =  {
        'GTweener* onComplete1(std::function<void(GTweener* tweener)> callback)',
    },
    TAG_MAKER = 'olua_makecallbacktag("onComplete1")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
    CALLONCE = false,
    REMOVE = false,
}
cls.props [[
    delay
    duration
    repeat
    target
    userData
    normalizedTime
    completed
]]

cls = class(M.CLASSES)
cls.CPPCLS = "fairygui::GTween"
cls.CHUNK = [[
static int should_unref_tween(lua_State *L)
{
    if (olua_isa(L, -2, "fui.GTweener")) {
        fairygui::GTweener *obj = (fairygui::GTweener *)olua_toobj(L, -2, "fui.GTweener");
        if (obj->getReferenceCount() == 1 || obj->allCompleted()) {
            return 1;
        }
    }
    return 0;
}]]
cls.funcs [[
    static GTweener* to(float startValue, float endValue, float duration)
    static GTweener* to(const cocos2d::Vec2& startValue, const cocos2d::Vec2& endValue, float duration)
    static GTweener* to(const cocos2d::Vec3& startValue, const cocos2d::Vec3& endValue, float duration)
    static GTweener* to(const cocos2d::Vec4& startValue, const cocos2d::Vec4& endValue, float duration)
    static GTweener* to(const cocos2d::Color4B& startValue, const cocos2d::Color4B& endValue, float duration)
    static GTweener* toDouble(double startValue, double endValue, float duration)
    static GTweener* delayedCall(float delay)
    static GTweener* shake(const cocos2d::Vec2& startValue, float amplitude, float duration)
    static bool isTweening(cocos2d::Ref* target)
    static bool isTweening(cocos2d::Ref* target, TweenPropType propType)
    static void kill(cocos2d::Ref* target)
    static void kill(cocos2d::Ref* target, bool complete)
    static void kill(cocos2d::Ref* target, TweenPropType propType, bool complete)
    static GTweener* getTween(cocos2d::Ref* target)
    static GTweener* getTween(cocos2d::Ref* target, TweenPropType propType)
    static void clean()
]]
cls.inject('to', {
    AFTER = [[
        olua_getstore(L, "fui.GTween");
        olua_mapwalkunref(L, -1, "tweeners", should_unref_tween);
        olua_mapref(L, -1, "tweeners", -2);
        lua_pop(L, 1);
    ]],
})
cls.inject('toDouble', {
    AFTER = [[
        olua_getstore(L, "fui.GTween");
        olua_mapwalkunref(L, -1, "tweeners", should_unref_tween);
        olua_mapref(L, -1, "tweeners", -2);
        lua_pop(L, 1);
    ]],
})
cls.inject('delayedCall', {
    AFTER = [[
        olua_getstore(L, "fui.GTween");
        olua_mapwalkunref(L, -1, "tweeners", should_unref_tween);
        olua_mapref(L, -1, "tweeners", -2);
        lua_pop(L, 1);
    ]],
})
cls.inject('shake', {
    AFTER = [[
        olua_getstore(L, "fui.GTween");
        olua_mapwalkunref(L, -1, "tweeners", should_unref_tween);
        olua_mapref(L, -1, "tweeners", -2);
        lua_pop(L, 1);
    ]],
})
cls.inject('kill', {
    AFTER = [[
        olua_getstore(L, "fui.GTween");
        olua_mapwalkunref(L, -1, "tweeners", should_unref_tween);
        lua_pop(L, 1);
    ]],
})
cls.inject('clean', {
    AFTER = [[
        olua_unrefall(L, 1, "tweeners");
    ]],
})

cls = class(M.CLASSES)
cls.CPPCLS = "fairygui::UIPackage"
cls.SUPERCLS = "cocos2d::Ref"
cls.funcs [[
    static UIPackage* getById(const std::string& id)
    static UIPackage* getByName(const std::string& name)
    static UIPackage* addPackage(const std::string& descFilePath)
    static void removePackage(const std::string& packageIdOrName)
    static void removeAllPackages()
    static GObject* createObject(const std::string& pkgName, const std::string& resName)
    static GObject* createObjectFromURL(const std::string& url)
    static std::string getItemURL(const std::string& pkgName, const std::string& resName)
    static PackageItem* getItemByURL(const std::string& url)
    static std::string normalizeURL(const std::string& url)
    static void* getItemAsset(const std::string& pkgName, const std::string& resName, PackageItemType type = PackageItemType::UNKNOWN)
    static void* getItemAssetByURL(const std::string& url, PackageItemType type = PackageItemType::UNKNOWN)
    static cocos2d::Texture2D* getEmptyTexture()
    const std::string& getId()
    const std::string& getName()
    PackageItem* getItem(const std::string& itemId)
    PackageItem* getItemByName(const std::string& itemName)
    void* getItemAsset(PackageItem* item)
]]
cls.props [[
    emptyTexture
    id
    name
]]

cls = class(M.CLASSES)
cls.CPPCLS = "fairygui::PackageItem"
cls.SUPERCLS = "cocos2d::Ref"
cls.funcs [[
    void load()
]]
cls.var('owner', [[UIPackage* owner]])
cls.var('type', [[PackageItemType type]])
cls.var('objectType', [[ObjectType objectType]])
cls.var('id', [[std::string id]])
cls.var('name', [[std::string name]])
cls.var('width', [[int width]])
cls.var('height', [[int height]])
cls.var('file', [[std::string file]])
cls.var('texture', [[cocos2d::Texture2D* texture]])
cls.var('scaleByTile', [[bool scaleByTile]])
cls.var('tileGridIndice', [[int tileGridIndice]])
cls.var('spriteFrame', [[cocos2d::SpriteFrame* spriteFrame]])
cls.var('animation', [[cocos2d::Animation* animation]])
cls.var('delayPerUnit', [[float delayPerUnit]])
cls.var('repeatDelay', [[float repeatDelay]])
cls.var('swing', [[bool swing]])
cls.var('translated', [[bool translated]])

cls = class(M.CLASSES)
cls.CPPCLS = "fairygui::PackageItemType"
cls.enums [[
    IMAGE
    MOVIECLIP
    SOUND
    COMPONENT
    ATLAS
    FONT
    SWF
    MISC
    UNKNOWN
]]

cls = class(M.CLASSES)
cls.CPPCLS = "fairygui::ObjectType"
cls.enums [[
    IMAGE
    MOVIECLIP
    SWF
    GRAPH
    LOADER
    GROUP
    TEXT
    RICHTEXT
    INPUTTEXT
    COMPONENT
    LIST
    LABEL
    BUTTON
    COMBOBOX
    PROGRESSBAR
    SLIDER
    SCROLLBAR
]]

cls = class(M.CLASSES)
cls.CPPCLS = "fairygui::ButtonMode"
cls.enums [[
    COMMON
    CHECK
    RADIO
]]

cls = class(M.CLASSES)
cls.CPPCLS = "fairygui::ChildrenRenderOrder"
cls.enums [[
    ASCENT
    DESCENT
    ARCH
]]

cls = class(M.CLASSES)
cls.CPPCLS = "fairygui::OverflowType"
cls.enums [[
    VISIBLE
    HIDDEN
    SCROLL
]]

cls = class(M.CLASSES)
cls.CPPCLS = "fairygui::ScrollType"
cls.enums [[
    HORIZONTAL
    VERTICAL
    BOTH
]]

cls = class(M.CLASSES)
cls.CPPCLS = "fairygui::ScrollBarDisplayType"
cls.enums [[
    DEFAULT
    VISIBLE
    AUTO
    HIDDEN
]]

cls = class(M.CLASSES)
cls.CPPCLS = "fairygui::LoaderFillType"
cls.enums [[
    NONE
    SCALE
    SCALE_MATCH_HEIGHT
    SCALE_MATCH_WIDTH
    SCALE_FREE
    SCALE_NO_BORDER
]]

cls = class(M.CLASSES)
cls.CPPCLS = "fairygui::ProgressTitleType"
cls.enums [[
    PERCENT
    VALUE_MAX
    VALUE
    MAX
]]

cls = class(M.CLASSES)
cls.CPPCLS = "fairygui::ListLayoutType"
cls.enums [[
    SINGLE_COLUMN
    SINGLE_ROW
    FLOW_HORIZONTAL
    FLOW_VERTICAL
    PAGINATION
]]

cls = class(M.CLASSES)
cls.CPPCLS = "fairygui::ListSelectionMode"
cls.enums [[
    SINGLE
    MULTIPLE
    MULTIPLE_SINGLECLICK
    NONE
]]

cls = class(M.CLASSES)
cls.CPPCLS = "fairygui::GroupLayoutType"
cls.enums [[
    NONE
    HORIZONTAL
    VERTICAL
]]

cls = class(M.CLASSES)
cls.CPPCLS = "fairygui::PopupDirection"
cls.enums [[
    AUTO
    UP
    DOWN
]]

cls = class(M.CLASSES)
cls.CPPCLS = "fairygui::AutoSizeType"
cls.enums [[
    NONE
    BOTH
    HEIGHT
    SHRINK
]]

cls = class(M.CLASSES)
cls.CPPCLS = "fairygui::FlipType"
cls.enums [[
    NONE
    HORIZONTAL
    VERTICAL
    BOTH
]]

cls = class(M.CLASSES)
cls.CPPCLS = "fairygui::TransitionActionType"
cls.enums [[
    XY
    Size
    Scale
    Pivot
    Alpha
    Rotation
    Color
    Animation
    Visible
    Sound
    Transition
    Shake
    ColorFilter
    Skew
    Text
    Icon
    Unknown
]]

cls = class(M.CLASSES)
cls.CPPCLS = "fairygui::FillMethod"
cls.enums [[
    None
    Horizontal
    Vertical
    Radial90
    Radial180
    Radial360
]]

cls = class(M.CLASSES)
cls.CPPCLS = "fairygui::FillOrigin"
cls.enums [[
    Top
    Bottom
    Left
    Right
]]

cls = class(M.CLASSES)
cls.CPPCLS = "fairygui::GController"
cls.SUPERCLS = "fairygui::UIEventDispatcher"
cls.funcs [[
    GComponent* getParent()
    void setParent(GComponent* value)
    int getSelectedIndex()
    void setSelectedIndex(int value)
    const std::string& getSelectedPage()
    void setSelectedPage(const std::string& value)
    const std::string& getSelectedPageId()
    void setSelectedPageId(const std::string& value)
    int getPrevisousIndex()
    const std::string& getPreviousPage()
    const std::string& getPreviousPageId()
    int getPageCount()
    bool hasPage(const std::string& aName)
    int getPageIndexById(const std::string& value)
    const std::string& getPageNameById(const std::string& value)
    const std::string& getPageId(int index)
    void setOppositePageId(const std::string& value)
    void runActions()
]]
cls.var('name', [[std::string name]])
cls.var('changing', [[bool changing]])
cls.var('autoRadioGroupDepth', [[bool autoRadioGroupDepth]])
cls.props [[
    parent
    selectedIndex
    selectedPage
    selectedPageId
    previsousIndex
    previousPage
    previousPageId
    pageCount
]]

cls = class(M.CLASSES)
cls.CPPCLS = "fairygui::GObject"
cls.SUPERCLS = "fairygui::UIEventDispatcher"
cls.funcs [[
    static GObject* getDraggingObject()
    static fairygui::GObject *create()
    float getX()
    void setX(float value)
    float getY()
    void setY(float value)
    const cocos2d::Vec2& getPosition()
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
    const cocos2d::Size& getSize()
    void setSize(float wv, float hv, bool ignorePivot = false)
    void center(bool restraint = false)
    void makeFullScreen()
    const cocos2d::Vec2& getPivot()
    void setPivot(float xv, float yv, bool asAnchor = false)
    bool isPivotAsAnchor()
    float getScaleX()
    void setScaleX(float value)
    float getScaleY()
    void setScaleY(float value)
    const cocos2d::Vec2& getScale()
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
    @ref(single group) GGroup* getGroup()
    void setGroup(@ref(single group) GGroup* value)
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
    cocos2d::Vec2 globalToLocal(@pack const cocos2d::Vec2& pt)
    cocos2d::Rect globalToLocal(@pack const cocos2d::Rect& rect)
    cocos2d::Vec2 localToGlobal(@pack const cocos2d::Vec2& pt)
    cocos2d::Rect localToGlobal(@pack const cocos2d::Rect& rect)
    cocos2d::Rect transformRect(@pack const cocos2d::Rect& rect, GObject* targetSpace)
    Relations* relations()
    void addRelation(GObject* target, RelationType relationType, bool usePercent = false)
    void removeRelation(GObject* target, RelationType relationType)
    GearBase* getGear(int index)
    bool checkGearController(int index, GController* c)
    uint32_t addDisplayLock()
    void releaseDisplayLock(uint32_t token)
    GComponent* getParent()
    GObject* findParent()
    @ref(single displayObject) cocos2d::Node* displayObject()
    GRoot* getRoot()
    bool onStage()
    void removeFromParent()
    GObject* hitTest(const cocos2d::Vec2 & worldPoint, const cocos2d::Camera * camera)
]]
cls.var('id', [[std::string id]])
cls.var('name', [[std::string name]])
cls.var('sourceSize', [[cocos2d::Size sourceSize]])
cls.var('initSize', [[cocos2d::Size initSize]])
cls.var('minSize', [[cocos2d::Size minSize]])
cls.var('maxSize', [[cocos2d::Size maxSize]])
cls.func('getDragBounds', [[{
    lua_settop(L, 1);
    fairygui::GObject *self = (fairygui::GObject *)olua_toobj(L, 1, "fui.GObject");
    cocos2d::Rect *rect = self->getDragBounds();
    manual_luacv_push_cocos2d_Rect(L, rect);
    return 1;
}]])
cls.prop('relations', 'Relations* relations()')
cls.prop('displayObject', 'cocos2d::Node* displayObject()')
cls.callback {
    FUNCS =  {
        'void addClickListener(const std::function<void(@stack EventContext* context)>& callback)',
        'void addClickListener(const std::function<void(@stack EventContext* context)>& callback, const EventTag& tag)',
    },
    TAG_MAKER = {'makeListenerTag(L, fairygui::UIEventType::Click, 0)', 'makeListenerTag(L, fairygui::UIEventType::Click, 3)'},
    TAG_MODE = 'OLUA_CALLBACK_TAG_NEW',
    CALLONCE = false,
    REMOVE = false,
}
cls.callback {
    FUNCS =  {
        'void removeClickListener(const EventTag& tag)',
    },
    TAG_MAKER = 'makeListenerTag(L, fairygui::UIEventType::Click, 2)',
    TAG_MODE = 'OLUA_CALLBACK_TAG_ENDWITH',
    CALLONCE = false,
    REMOVE = true,
}
cls.inject('center', {
    BEFORE = [[
        if (!self->getParent() && !fairygui::UIRoot) {
            luaL_error(L, "UIRoot and parent are both nullptr");
        }
    ]],
})
cls.inject('makeFullScreen', {
    BEFORE = [[
        if (!fairygui::UIRoot) {
            luaL_error(L, "UIRoot is nullptr");
        }
    ]],
})
cls.props [[
    draggingObject
    x
    y
    position
    xMin
    yMin
    pixelSnapping
    width
    height
    size
    pivot
    pivotAsAnchor
    scaleX
    scaleY
    scale
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

cls = class(M.CLASSES)
cls.CPPCLS = "fairygui::GComponent"
cls.SUPERCLS = "fairygui::GObject"
cls.funcs [[
    static fairygui::GComponent *create()
    GObject* addChild(@ref(map children) GObject* child)
    GObject* addChildAt(@ref(map children) GObject* child, int index)
    void removeChild(@unref(map children) GObject * child)
    @unref(cmp children) void removeChildAt(int index)
    @unref(cmp children) void removeChildren()
    @unref(cmp children) void removeChildren(int beginIndex, int endIndex)
    @ref(map children) GObject * getChildAt(int index)
    @ref(map children) GObject * getChild(const std::string& name)
    @ref(map children) GObject * getChildInGroup(const GGroup * group, const std::string& name)
    @ref(map children) GObject * getChildById(const std::string& id)
    @ref(map children) const cocos2d::Vector<GObject*>& getChildren()
    int getChildIndex(const GObject* child)
    void setChildIndex(GObject* child, int index)
    int setChildIndexBefore(GObject* child, int index)
    void swapChildren(GObject* child1, GObject* child2)
    void swapChildrenAt(int index1, int index2)
    int numChildren()
    bool isAncestorOf(const GObject* obj)
    bool isChildInView(GObject* child)
    int getFirstChildInView()
    void addController(@ref(map controllers) GController* c)
    @ref(map controllers) GController* getControllerAt(int index)
    @ref(map controllers) GController* getController(const std::string& name)
    @ref(map controllers) const cocos2d::Vector<GController*>& getControllers()
    void removeController(@unref(map controllers) GController* c)
    void applyController(GController* c)
    void applyAllControllers()
    @ref(map transitions) Transition* getTransition(const std::string& name)
    @ref(map transitions) Transition* getTransitionAt(int index)
    @ref(map transitions) const cocos2d::Vector<Transition*>& getTransitions()
    bool getOpaque()
    void setOpaque(bool value)
    const Margin& getMargin()
    void setMargin(const Margin& value)
    ChildrenRenderOrder getChildrenRenderOrder()
    void setChildrenRenderOrder(ChildrenRenderOrder value)
    int getApexIndex()
    void setApexIndex(int value)
    @ref(single mask) cocos2d::Node* getMask()
    void setMask(@ref(single mask) cocos2d::Node* value, bool inverted = false)
    IHitTest* getHitArea()
    void setHitArea(IHitTest* value)
    ScrollPane* getScrollPane()
    float getViewWidth()
    void setViewWidth(float value)
    float getViewHeight()
    void setViewHeight(float value)
    void setBoundsChangedFlag()
    void ensureBoundsCorrect()
    cocos2d::Vec2 getSnappingPosition(const cocos2d::Vec2& pt)
    void childSortingOrderChanged(GObject* child, int oldValue, int newValue)
    void childStateChanged(GObject * child)
    void adjustRadioGroupDepth(GObject* obj, GController* c)
]]
cls.prop('numChildren', 'int numChildren()')
cls.inject('addChildAt', {
    BEFORE = [[
        if (!(arg2 >= 0 && arg2 <= self->numChildren())) {
            luaL_error(L, "index out of range");
        }
    ]],
})
cls.inject('removeChildren', {
    BEFORE = [[
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
    ]],
})
cls.inject({'getChildAt', 'removeChildAt'}, {
    BEFORE = [[
        if (!(arg1 >= 0 && arg1 < self->numChildren())) {
            luaL_error(L, "index out of range");
        }
    ]],
})
cls.inject('getTransitionAt', {
    BEFORE = [[
        if (!(arg1 >= 0 && arg1 < self->getTransitions().size())) {
            luaL_error(L, "index out of range");
        }
    ]],
})
cls.inject('getControllerAt', {
    BEFORE = [[
        if (!(arg1 >= 0 && arg1 < self->getControllers().size())) {
            luaL_error(L, "index out of range");
        }
    ]],
})
cls.props [[
    children
    firstChildInView
    controllers
    transitions
    opaque
    margin
    childrenRenderOrder
    apexIndex
    mask
    hitArea
    scrollPane
    viewWidth
    viewHeight
]]

cls = class(M.CLASSES)
cls.CPPCLS = "fairygui::GRoot"
cls.SUPERCLS = "fairygui::GComponent"
cls.funcs [[
    static GRoot* create(cocos2d::Scene* scene, int zOrder = 1000)
    static GRoot* getInstance()
    @unref(cmp children) void showWindow(@ref(map children) Window* win)
    @unref(cmp children parent) void hideWindow(Window* win)
    @unref(cmp children parent) void hideWindowImmediately(Window* win)
    void bringToFront(Window* win)
    void showModalWait()
    void closeModalWait()
    void closeAllExceptModals()
    void closeAllWindows()
    @ref(map children) Window* getTopWindow()
    @ref(map children) GObject* getModalWaitingPane()
    @ref(map children) GGraph* getModalLayer()
    bool hasModalWindow()
    bool isModalWaiting()
    InputProcessor* getInputProcessor()
    cocos2d::Vec2 getTouchPosition(int touchId)
    GObject* getTouchTarget()
    @unref(cmp children) void showPopup(@ref(map children) GObject* popup)
    @unref(cmp children) void showPopup(@ref(map children) GObject* popup, GObject* target, PopupDirection dir)
    @unref(cmp children) void togglePopup(@ref(map children) GObject* popup)
    @unref(cmp children) void togglePopup(@ref(map children) GObject* popup, GObject* target, PopupDirection dir)
    @unref(cmp children) void hidePopup()
    @unref(cmp children) void hidePopup(GObject* popup)
    bool hasAnyPopup()
    cocos2d::Vec2 getPoupPosition(GObject* popup, GObject* target, PopupDirection dir)
    void showTooltips(const std::string& msg)
    void showTooltipsWin(GObject* tooltipWin)
    void hideTooltips()
    void playSound(const std::string& url, float volumeScale = 1)
    bool isSoundEnabled()
    void setSoundEnabled(bool value)
    float getSoundVolumeScale()
    void setSoundVolumeScale(float value)
]]
cls.prop('UIRoot', 'static GRoot* getInstance()')
cls.inject('create', {
    AFTER = [[
        olua_push_cppobj<cocos2d::Node>(L, ret->displayObject(), "cc.Node");
        olua_singleref(L, -1, "fui.root", -2);
        olua_mapref(L, 1, "children", -1);
        lua_pop(L, 1);
    ]],
})
cls.inject({'hideWindow', 'hideWindowImmediately'}, {
    BEFORE = [[
        int parent = 1;
        if (arg1->getParent()) {
            olua_push_cppobj<fairygui::GComponent>(L, arg1->getParent(), "fui.GComponent");
            parent = lua_gettop(L);
        }
    ]],
})
cls.props [[
    instance
    topWindow
    modalWaitingPane
    modalLayer
    modalWaiting
    inputProcessor
    touchTarget
    soundEnabled
    soundVolumeScale
]]

cls = class(M.CLASSES)
cls.CPPCLS = "fairygui::GGroup"
cls.SUPERCLS = "fairygui::GObject"
cls.funcs [[
    static fairygui::GGroup *create()
    GroupLayoutType getLayout()
    void setLayout(GroupLayoutType value)
    int getColumnGap()
    void setColumnGap(int value)
    int getLineGap()
    void setLineGap(int value)
    void setBoundsChangedFlag(bool childSizeChanged = false)
    void moveChildren(float dx, float dy)
    void resizeChildren(float dw, float dh)
]]
cls.props [[
    layout
    columnGap
    lineGap
]]

cls = class(M.CLASSES)
cls.CPPCLS = "fairygui::GScrollBar"
cls.SUPERCLS = "fairygui::GComponent"
cls.funcs [[
    static fairygui::GScrollBar *create()
    void setScrollPane(ScrollPane* target, bool vertical)
    void setDisplayPerc(float value)
    void setScrollPerc(float value)
    float getMinSize()
]]
cls.props [[
    minSize
]]

cls = class(M.CLASSES)
cls.CPPCLS = "fairygui::GLoader"
cls.SUPERCLS = "fairygui::GObject"
cls.funcs [[
    static fairygui::GLoader *create()
    const std::string& getURL()
    void setURL(const std::string& value)
    cocos2d::TextHAlignment getAlign()
    void setAlign(cocos2d::TextHAlignment value)
    cocos2d::TextVAlignment getVerticalAlign()
    void setVerticalAlign(cocos2d::TextVAlignment value)
    bool getAutoSize()
    void setAutoSize(bool value)
    LoaderFillType getFill()
    void setFill(LoaderFillType value)
    bool isShrinkOnly()
    void setShrinkOnly(bool value)
    const cocos2d::Size& getContentSize()
    cocos2d::Color3B getColor()
    void setColor(const cocos2d::Color3B& value)
    bool isPlaying()
    void setPlaying(bool value)
    int getFrame()
    void setFrame(int value)
    float getTimeScale()
    void setTimeScale(float value)
    void advance(float time)
    FillMethod getFillMethod()
    void setFillMethod(FillMethod value)
    FillOrigin getFillOrigin()
    void setFillOrigin(FillOrigin value)
    bool isFillClockwise()
    void setFillClockwise(bool value)
    float getFillAmount()
    void setFillAmount(float value)
    @ref(single component) GComponent* getComponent()
]]
cls.props [[
    url
    align
    verticalAlign
    autoSize
    fill
    shrinkOnly
    contentSize
    color
    playing
    frame
    timeScale
    fillMethod
    fillOrigin
    fillClockwise
    fillAmount
    component
]]

cls = class(M.CLASSES)
cls.CPPCLS = "fairygui::GTextField"
cls.SUPERCLS = "fairygui::GObject"
cls.funcs [[
    bool isUBBEnabled()
    void setUBBEnabled(bool value)
    AutoSizeType getAutoSize()
    void setAutoSize(AutoSizeType value)
    bool isSingleLine()
    void setSingleLine(bool value)
    TextFormat* getTextFormat()
    void applyTextFormat()
    const cocos2d::Size& getTextSize()
    cocos2d::Color3B getColor()
    void setColor(const cocos2d::Color3B& value)
    float getFontSize()
    void setFontSize(float value)
    cocos2d::Color3B getOutlineColor()
    void setOutlineColor(const cocos2d::Color3B& value)
    GTextField* setVar(const std::string& name, const cocos2d::Value& value)
    void flushVars()
]]
cls.func('getTemplateVars', [[{
    lua_settop(L, 1);
    fairygui::GTextField *self = (fairygui::GTextField *)olua_toobj(L, 1, "fui.GTextField");
    manual_luacv_push_cocos2d_ValueMap(L, self->getTemplateVars());
    return 1;
}]])
cls.func('setTemplateVars', [[{
    lua_settop(L, 2);
    cocos2d::ValueMap arg;
    fairygui::GTextField *self = (fairygui::GTextField *)olua_toobj(L, 1, "fui.GTextField");
    manual_luacv_check_cocos2d_ValueMap(L, 2, &arg);
    self->setTemplateVars(&arg);
    return 1;
}]])
cls.prop('templateVars')
cls.props [[
    ubbEnabled
    autoSize
    singleLine
    textFormat
    textSize
    color
    fontSize
    outlineColor
]]

cls = class(M.CLASSES)
cls.CPPCLS = "fairygui::GGraph"
cls.SUPERCLS = "fairygui::GObject"
cls.funcs [[
    static fairygui::GGraph *create()
    void drawRect(float aWidth, float aHeight, int lineSize, const cocos2d::Color4F& lineColor, const cocos2d::Color4F& fillColor)
    void drawEllipse(float aWidth, float aHeight, int lineSize, const cocos2d::Color4F& lineColor, const cocos2d::Color4F& fillColor)
    bool isEmpty()
    cocos2d::Color3B getColor()
    void setColor(const cocos2d::Color3B& value)
]]
cls.props [[
    empty
    color
]]

cls = class(M.CLASSES)
cls.CPPCLS = "fairygui::GButton"
cls.SUPERCLS = "fairygui::GComponent"
cls.funcs [[
    static fairygui::GButton *create()
    const std::string& getTitle()
    void setTitle(const std::string& value)
    const std::string& getSelectedTitle()
    void setSelectedTitle(const std::string& value)
    const std::string& getSelectedIcon()
    void setSelectedIcon(const std::string& value)
    cocos2d::Color3B getTitleColor()
    void setTitleColor(const cocos2d::Color3B& value)
    int getTitleFontSize()
    void setTitleFontSize(int value)
    bool isSelected()
    void setSelected(bool value)
    @ref(single relatedController) GController* getRelatedController()
    void setRelatedController(@ref(single relatedController) GController* c)
    bool isChangeStateOnClick()
    void setChangeStateOnClick(bool value)
    @ref(single textField) GTextField* getTextField()
]]
cls.props [[
    title
    selectedTitle
    selectedIcon
    titleColor
    titleFontSize
    selected
    relatedController
    changeStateOnClick
    textField
]]

cls = class(M.CLASSES)
cls.CPPCLS = "fairygui::GImage"
cls.SUPERCLS = "fairygui::GObject"
cls.funcs [[
    static fairygui::GImage *create()
    FlipType getFlip()
    void setFlip(FlipType value)
    cocos2d::Color3B getColor()
    void setColor(const cocos2d::Color3B& value)
    FillMethod getFillMethod()
    void setFillMethod(FillMethod value)
    FillOrigin getFillOrigin()
    void setFillOrigin(FillOrigin value)
    bool isFillClockwise()
    void setFillClockwise(bool value)
    float getFillAmount()
    void setFillAmount(float value)
]]
cls.props [[
    flip
    color
    fillMethod
    fillOrigin
    fillClockwise
    fillAmount
]]

cls = class(M.CLASSES)
cls.CPPCLS = "fairygui::GLabel"
cls.SUPERCLS = "fairygui::GComponent"
cls.funcs [[
    static fairygui::GLabel *create()
    const std::string& getTitle()
    void setTitle(const std::string& value)
    cocos2d::Color3B getTitleColor()
    void setTitleColor(const cocos2d::Color3B& value)
    int getTitleFontSize()
    void setTitleFontSize(int value)
    @ref(single textField) GTextField* getTextField()
]]
cls.props [[
    title
    titleColor
    titleFontSize
    textField
]]

cls = class(M.CLASSES)
cls.CPPCLS = "fairygui::GList"
cls.SUPERCLS = "fairygui::GComponent"
cls.funcs [[
    static fairygui::GList *create()
    const std::string& getDefaultItem()
    void setDefaultItem(const std::string& value)
    ListLayoutType getLayout()
    void setLayout(ListLayoutType value)
    int getLineCount()
    void setLineCount(int value)
    int getColumnCount()
    void setColumnCount(int value)
    int getColumnGap()
    void setColumnGap(int value)
    int getLineGap()
    void setLineGap(int value)
    cocos2d::TextHAlignment getAlign()
    void setAlign(cocos2d::TextHAlignment value)
    cocos2d::TextVAlignment getVerticalAlign()
    void setVerticalAlign(cocos2d::TextVAlignment value)
    bool getAutoResizeItem()
    void setAutoResizeItem(bool value)
    ListSelectionMode getSelectionMode()
    void setSelectionMode(ListSelectionMode value)
    GObject* getFromPool()
    GObject* getFromPool(const std::string& url)
    void returnToPool(@unref(map children) GObject *obj)
    @ref(map children) GObject* addItemFromPool()
    @ref(map children) GObject* addItemFromPool(const std::string& url)
    @unref(cmp children) void removeChildToPoolAt(int index)
    void removeChildToPool(@unref(map children) GObject *child)
    @unref(cmp children) void removeChildrenToPool()
    @unref(cmp children) void removeChildrenToPool(int beginIndex, int endIndex)
    int getSelectedIndex()
    void setSelectedIndex(int value)
    void getSelection(std::vector<int>& result)
    void addSelection(int index, bool scrollItToView)
    void removeSelection(int index)
    void clearSelection()
    void selectAll()
    void selectReverse()
    void handleArrowKey(int dir)
    void resizeToFit(int itemCount)
    void resizeToFit(int itemCount, int minSize)
    void scrollToView(int index, bool ani = false, bool setFirst = false)
    @ref(single selectionController) GController* getSelectionController()
    void setSelectionController(@ref(single selectionController) GController* value)
    @unref(cmp children) void setVirtual()
    @unref(cmp children) void setVirtualAndLoop()
    bool isVirtual()
    void refreshVirtualList()
    int getNumItems()
    @unref(cmp children) void setNumItems(int value)
    int childIndexToItemIndex(int index)
    int itemIndexToChildIndex(int index)
]]
cls.var('scrollItemToViewOnClick', [[bool scrollItemToViewOnClick]])
cls.var('foldInvisibleItems', [[bool foldInvisibleItems]])
cls.var('itemRenderer', [[std::function<void(int, GObject*)> itemRenderer]])
cls.var('itemProvider', [[std::function<std::string(int)> itemProvider]])
cls.inject('removeChildToPoolAt', {
    BEFORE = [[
        if (!(arg1 >= 0 && arg1 < self->numChildren())) {
            luaL_error(L, "index out of range");
        }
    ]],
})
cls.inject('removeChildrenToPool', {
    BEFORE = [[
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
    ]],
})
cls.inject('itemRenderer', {
    CALLBACK_BEFORE = [[
        if (arg2->getParent()) {
            olua_push_cppobj<fairygui::GComponent>(L, arg2->getParent(), "fui.GComponent");
            olua_mapref(L, -1, "children", -2);
            lua_pop(L, 1);
        }
    ]],
})
cls.props [[
    defaultItem
    layout
    lineCount
    columnCount
    columnGap
    lineGap
    align
    verticalAlign
    autoResizeItem
    selectionMode
    selectedIndex
    selectionController
    virtual
    numItems
]]

cls = class(M.CLASSES)
cls.CPPCLS = "fairygui::GMovieClip"
cls.SUPERCLS = "fairygui::GObject"
cls.funcs [[
    static fairygui::GMovieClip *create()
    bool isPlaying()
    void setPlaying(bool value)
    int getFrame()
    void setFrame(int value)
    float getTimeScale()
    void setTimeScale(float value)
    void advance(float time)
    FlipType getFlip()
    void setFlip(FlipType value)
    cocos2d::Color3B getColor()
    void setColor(const cocos2d::Color3B& value)
]]
cls.callback {
    FUNCS =  {
        'void setPlaySettings(int start = 0, int end = -1, int times = 0, int endAt = -1, std::function<void()> completeCallback = nullptr)',
    },
    TAG_MAKER = 'olua_makecallbacktag("playSettings")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
    CALLONCE = false,
    REMOVE = false,
}
cls.props [[
    playing
    frame
    timeScale
    flip
    color
]]

cls = class(M.CLASSES)
cls.CPPCLS = "fairygui::GProgressBar"
cls.SUPERCLS = "fairygui::GComponent"
cls.funcs [[
    static fairygui::GProgressBar *create()
    ProgressTitleType getTitleType()
    void setTitleType(ProgressTitleType value)
    double getMax()
    void setMax(double value)
    double getValue()
    void setValue(double value)
    void tweenValue(double value, float duration)
]]
cls.props [[
    titleType
    max
    value
]]

cls = class(M.CLASSES)
cls.CPPCLS = "fairygui::GComboBox"
cls.SUPERCLS = "fairygui::GComponent"
cls.funcs [[
    static fairygui::GComboBox *create()
    const std::string& getTitle()
    void setTitle(const std::string& value)
    const cocos2d::Color3B getTitleColor()
    void setTitleColor(const cocos2d::Color3B& value)
    int getTitleFontSize()
    void setTitleFontSize(int value)
    const std::string& getValue()
    void setValue(const std::string& value)
    int getSelectedIndex()
    void setSelectedIndex(int value)
    @ref(single selectionController) GController* getSelectionController()
    void setSelectionController(@ref(single selectionController) GController* value)
    std::vector<std::string>& getItems()
    std::vector<std::string>& getIcons()
    std::vector<std::string>& getValues()
    @ref(single dropdown) GObject* getDropdown()
    void refresh()
    @ref(single textField) GTextField* getTextField()
]]
cls.var('visibleItemCount', [[int visibleItemCount]])
cls.var('popupDirection', [[PopupDirection popupDirection]])
cls.props [[
    title
    titleColor
    titleFontSize
    value
    selectedIndex
    selectionController
    items
    icons
    values
    dropdown
    textField
]]

cls = class(M.CLASSES)
cls.CPPCLS = "fairygui::GRichTextField"
cls.SUPERCLS = "fairygui::GTextField"
cls.funcs [[
    static fairygui::GRichTextField *create()
]]

cls = class(M.CLASSES)
cls.CPPCLS = "fairygui::GSlider"
cls.SUPERCLS = "fairygui::GComponent"
cls.funcs [[
    static fairygui::GSlider *create()
    ProgressTitleType getTitleType()
    void setTitleType(ProgressTitleType value)
    double getMax()
    void setMax(double value)
    double getValue()
    void setValue(double value)
]]
cls.var('changeOnClick', [[bool changeOnClick]])
cls.var('canDrag', [[bool canDrag]])
cls.props [[
    titleType
    max
    value
]]

cls = class(M.CLASSES)
cls.CPPCLS = "fairygui::GTextInput"
cls.SUPERCLS = "fairygui::GTextField"
cls.funcs [[
    static fairygui::GTextInput *create()
    void setPrompt(const std::string& value)
    void setPassword(bool value)
    void setKeyboardType(int value)
    void setMaxLength(int value)
    void setRestrict(const std::string& value)
]]

cls = class(M.CLASSES)
cls.CPPCLS = "fairygui::PopupMenu"
cls.SUPERCLS = "cocos2d::Ref"
cls.CHUNK = [[
static int _fairygui_PopupMenu_addItemAt(lua_State *L);
]]
cls.funcs [[
    static PopupMenu* create(const std::string& resourceURL)
    static PopupMenu* create()
    void addSeperator()
    const std::string& getItemName(int index)
    void setItemText(const std::string& name, const std::string& caption)
    void setItemVisible(const std::string& name, bool visible)
    void setItemGrayed(const std::string& name, bool grayed)
    void setItemCheckable(const std::string& name, bool checkable)
    void setItemChecked(const std::string& name, bool check)
    bool isItemChecked(const std::string& name)
    @unref(cmp children parent) bool removeItem(const std::string& name)
    @unref(cmp children parent) void clearItems()
    int getItemCount()
    @ref(single contentPane) GComponent* getContentPane()
    @ref(single list) GList* getList()
    @unref(cmp children parent)@ref(map children parent) void show()
    @unref(cmp children parent)@ref(map children parent) void show(GObject* target, PopupDirection dir)
]]
cls.func('addItemAt', [[{
    lua_settop(L, 4);

    fairygui::PopupMenu *self = (fairygui::PopupMenu *)olua_toobj(L, 1, "fui.PopupMenu");
    std::string caption = olua_checkstring(L, 2);
    int index = (int)olua_checkinteger(L, 3);
    fairygui::GButton *ret = (fairygui::GButton *)self->addItemAt(caption, index, nullptr);

    void *callback_store_obj = (void *)ret;
    std::string tag = makeListenerTag(L, fairygui::UIEventType::ClickMenu, 0);
    std::string func = olua_setcallback(L, callback_store_obj, tag.c_str(), 4, OLUA_CALLBACK_TAG_NEW);
    std::function<void(fairygui::EventContext *)> callback = [callback_store_obj, func, tag](fairygui::EventContext *event) {
        lua_State *L = olua_mainthread();
        int top = lua_gettop(L);
        size_t last = olua_push_objpool(L);
        olua_enable_objpool(L);
        olua_push_cppobj<fairygui::EventContext>(L, event, "fui.EventContext");
        olua_disable_objpool(L);
        olua_callback(L, callback_store_obj, func.c_str(), 1);
        
        //pop stack value
        olua_pop_objpool(L, last);
        
        lua_settop(L, top);
    };
    
    ret->addEventListener(fairygui::UIEventType::ClickMenu, callback);
    
    olua_push_cppobj<fairygui::GButton>(L, ret, "fui.GButton");
    olua_push_cppobj<fairygui::GComponent>(L, ret->getParent(), "fui.GComponent");
    olua_mapref(L, -1, "children", -2);
    lua_pop(L, 1);

    return 1;
}]])
cls.func('addItem', [[{
    lua_settop(L, 3);

    fairygui::PopupMenu *self = (fairygui::PopupMenu *)olua_toobj(L, 1, "fui.PopupMenu");
    lua_pushinteger(L, self->getList()->numChildren());
    lua_insert(L, -2);
    return _fairygui_PopupMenu_addItemAt(L);
}]])
cls.inject('show', {
    BEFORE = [[
        fairygui::GRoot *root = fairygui::UIRoot;
        if (lua_gettop(L) > 1) {
            fairygui::GObject *target = (fairygui::GObject *)olua_checkobj(L, 2, "fui.GObject");
            root = target->getRoot();
        }
        if (!root) {
            luaL_error(L, "no root to add 'PopupMenu'");
        }
        olua_push_cppobj<fairygui::GRoot>(L, root, "fui.GRoot");
        int parent = lua_gettop(L);
    ]],
})
cls.inject({'removeItem', 'clearItems'}, {
    BEFORE = [[
        olua_push_cppobj<fairygui::GList>(L, self->getList(), "fui.GList");
        int parent = lua_gettop(L);
    ]],
})
cls.props [[
    itemCount
    contentPane
    list
]]

cls = class(M.CLASSES)
cls.CPPCLS = "fairygui::Relations"
cls.funcs [[
    void add(GObject* target, RelationType relationType)
    void add(GObject* target, RelationType relationType, bool usePercent)
    void remove(GObject* target, RelationType relationType)
    bool contains(GObject* target)
    void clearFor(GObject* target)
    void clearAll()
    void onOwnerSizeChanged(float dWidth, float dHeight, bool applyPivot)
    bool isEmpty()
]]
cls.var('handling', [[GObject* handling]])
cls.func('copyFrom', [[{
    lua_settop(L, 2);
    
    fairygui::Relations *self = (fairygui::Relations *)olua_toobj(L, 1, "fui.Relations");
    fairygui::Relations *source = (fairygui::Relations *)olua_checkobj(L, 2, "fui.Relations");
    // void copyFrom(const Relations& source)
    self->copyFrom(*source);
    
    return 0;
}]])
cls.props [[
    empty
]]

cls = class(M.CLASSES)
cls.CPPCLS = "fairygui::RelationType"
cls.enums [[
    Left_Left
    Left_Center
    Left_Right
    Center_Center
    Right_Left
    Right_Center
    Right_Right
    Top_Top
    Top_Middle
    Top_Bottom
    Middle_Middle
    Bottom_Top
    Bottom_Middle
    Bottom_Bottom
    Width
    Height
    LeftExt_Left
    LeftExt_Right
    RightExt_Left
    RightExt_Right
    TopExt_Top
    TopExt_Bottom
    BottomExt_Top
    BottomExt_Bottom
    Size
]]

cls = class(M.CLASSES)
cls.CPPCLS = "fairygui::RelationItem"
cls.funcs [[
    @ref(single target) GObject* getTarget()
    void setTarget(@ref(single target) GObject* value)
    void add(RelationType relationType, bool usePercent)
    void internalAdd(RelationType relationType, bool usePercent)
    void remove(RelationType relationType)
    bool isEmpty()
    void applyOnSelfSizeChanged(float dWidth, float dHeight, bool applyPivot)
]]
cls.func('copyFrom', [[{
    lua_settop(L, 2);
    
    fairygui::RelationItem *self = (fairygui::RelationItem *)olua_toobj(L, 1, "fui.RelationItem");
    fairygui::RelationItem *source = (fairygui::RelationItem *)olua_checkobj(L, 2, "fui.RelationItem");
    // void copyFrom(const RelationItem& source)
    self->copyFrom(*source);
    
    return 0;
}]])
cls.props [[
    target
    empty
]]

cls = class(M.CLASSES)
cls.CPPCLS = "fairygui::ScrollPane"
cls.SUPERCLS = "cocos2d::Ref"
cls.funcs [[
    @ref(single owner) GComponent* getOwner()
    @ref(single header) GComponent* getHeader()
    @ref(single footer) GComponent* getFooter()
    @ref(single vtScrollBar) GScrollBar* getVtScrollBar()
    @ref(single hzScrollBar) GScrollBar* getHzScrollBar()
    bool isBouncebackEffect()
    void setBouncebackEffect(bool value)
    bool isTouchEffect()
    void setTouchEffect(bool value)
    bool isInertiaDisabled()
    void setInertiaDisabled(bool value)
    float getScrollStep()
    void setScrollStep(float value)
    bool isSnapToItem()
    void setSnapToItem(bool value)
    bool isPageMode()
    void setPageMode(bool value)
    @ref(single pageController) GController* getPageController()
    void setPageController(@ref(single pageController) GController* value)
    bool isMouseWheelEnabled()
    void setMouseWheelEnabled(bool value)
    float getDecelerationRate()
    void setDecelerationRate(float value)
    float getPosX()
    void setPosX(float value, bool ani = false)
    float getPosY()
    void setPosY(float value, bool ani = false)
    float getPercX()
    void setPercX(float value, bool ani = false)
    float getPercY()
    void setPercY(float value, bool ani = false)
    bool isBottomMost()
    bool isRightMost()
    void scrollLeft(float ratio = 1, bool ani = false)
    void scrollRight(float ratio = 1, bool ani = false)
    void scrollUp(float ratio = 1, bool ani = false)
    void scrollDown(float ratio = 1, bool ani = false)
    void scrollTop(bool ani = false)
    void scrollBottom(bool ani = false)
    void scrollToView(GObject* obj, bool ani = false, bool setFirst = false)
    void scrollToView(const cocos2d::Rect& rect, bool ani = false, bool setFirst = false)
    bool isChildInView(GObject* obj)
    int getPageX()
    void setPageX(int value, bool ani = false)
    int getPageY()
    void setPageY(int value, bool ani = false)
    float getScrollingPosX()
    float getScrollingPosY()
    const cocos2d::Size& getContentSize()
    const cocos2d::Size& getViewSize()
    void lockHeader(int size)
    void lockFooter(int size)
    void cancelDragging()
    static ScrollPane* getDraggingPane()
]]
cls.props [[
    owner
    header
    footer
    vtScrollBar
    hzScrollBar
    bouncebackEffect
    touchEffect
    inertiaDisabled
    scrollStep
    snapToItem
    pageMode
    pageController
    mouseWheelEnabled
    decelerationRate
    posX
    posY
    percX
    percY
    bottomMost
    rightMost
    pageX
    pageY
    scrollingPosX
    scrollingPosY
    contentSize
    viewSize
    draggingPane
]]

cls = class(M.CLASSES)
cls.CPPCLS = "fairygui::Transition"
cls.SUPERCLS = "cocos2d::Ref"
cls.funcs [[
    @ref(single owner) GComponent* getOwner()
    bool isPlaying()
    void changePlayTimes(int value)
    void stop()
    void stop(bool setToComplete, bool processCallback)
    void setAutoPlay(bool autoPlay, int times, float delay)
    void setPaused(bool paused)
    void setValue(const std::string& label, const cocos2d::ValueVector& values)
    void setTarget(const std::string& label, GObject* newTarget)
    void setDuration(const std::string& label, float value)
    float getLabelTime(const std::string& label)
    float getTimeScale()
    void setTimeScale(float value)
    void updateFromRelations(const std::string& targetId, float dx, float dy)
    void onOwnerAddedToStage()
    void onOwnerRemovedFromStage()
]]
cls.var('name', [[std::string name]])
cls.callback {
    FUNCS =  {
        'void play(std::function<void()> callback = nullptr)',
        'void play(int times, float delay, std::function<void()> callback = nullptr)',
        'void play(int times, float delay, float startTime, float endTime, std::function<void()> callback = nullptr)',
    },
    TAG_MAKER = 'olua_makecallbacktag("play")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
    CALLONCE = false,
    REMOVE = false,
}
cls.callback {
    FUNCS =  {
        'void playReverse(std::function<void()> callback = nullptr)',
        'void playReverse(int times, float delay, std::function<void()> callback = nullptr)',
    },
    TAG_MAKER = 'olua_makecallbacktag("playReverse")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
    CALLONCE = false,
    REMOVE = false,
}
cls.callback {
    FUNCS =  {
        'void setHook(const std::string& label, @nullable std::function<void()> callback)',
    },
    TAG_MAKER = 'olua_makecallbacktag("hook." + #1)',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
    CALLONCE = false,
    REMOVE = false,
}
cls.callback {
    FUNCS =  {
        'void clearHooks()',
    },
    TAG_MAKER = 'olua_makecallbacktag("hook.")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_WILDCARD',
    CALLONCE = false,
    REMOVE = true,
}
cls.props [[
    owner
    playing
    timeScale
]]

cls = class(M.CLASSES)
cls.CPPCLS = "fairygui::UIConfig"
cls.funcs [[
    static void registerFont(const std::string& aliasName, const std::string& realName)
]]
cls.func('getRealFontName', [[{
    lua_settop(L, 1);
    bool isTTF = false;
    std::string aliasName = olua_checkstring(L, 1);
    std::string fontName = fairygui::UIConfig::getRealFontName(aliasName, &isTTF);
    lua_pushstring(L, fontName.c_str());
    lua_pushboolean(L, isTTF);
    return 2;
}]])
cls.var('defaultFont', [[static std::string defaultFont]])
cls.var('buttonSound', [[static std::string buttonSound]])
cls.var('buttonSoundVolumeScale', [[static float buttonSoundVolumeScale]])
cls.var('defaultScrollStep', [[static int defaultScrollStep]])
cls.var('defaultScrollDecelerationRate', [[static float defaultScrollDecelerationRate]])
cls.var('defaultScrollTouchEffect', [[static bool defaultScrollTouchEffect]])
cls.var('defaultScrollBounceEffect', [[static bool defaultScrollBounceEffect]])
cls.var('defaultScrollBarDisplay', [[static ScrollBarDisplayType defaultScrollBarDisplay]])
cls.var('verticalScrollBar', [[static std::string verticalScrollBar]])
cls.var('horizontalScrollBar', [[static std::string horizontalScrollBar]])
cls.var('touchDragSensitivity', [[static int touchDragSensitivity]])
cls.var('clickDragSensitivity', [[static int clickDragSensitivity]])
cls.var('touchScrollSensitivity', [[static int touchScrollSensitivity]])
cls.var('defaultComboBoxVisibleItemCount', [[static int defaultComboBoxVisibleItemCount]])
cls.var('globalModalWaiting', [[static std::string globalModalWaiting]])
cls.var('modalLayerColor', [[static cocos2d::Color4F modalLayerColor]])
cls.var('tooltipsWin', [[static std::string tooltipsWin]])
cls.var('bringWindowToFrontOnClick', [[static bool bringWindowToFrontOnClick]])
cls.var('windowModalWaiting', [[static std::string windowModalWaiting]])
cls.var('popupMenu', [[static std::string popupMenu]])
cls.var('popupMenu_seperator', [[static std::string popupMenu_seperator]])

cls = class(M.CLASSES)
cls.CPPCLS = "fairygui::IUISource"
cls.SUPERCLS = "cocos2d::Ref"
cls.funcs [[
    const std::string& getFileName()
    void setFileName(const std::string& value)
    bool isLoaded()
]]
cls.callback {
    FUNCS =  {
        'void load(@nullable std::function<void()> callback)',
    },
    TAG_MAKER = 'olua_makecallbacktag("load")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
    CALLONCE = false,
    REMOVE = false,
}
cls.props [[
    fileName
    loaded
]]

cls = class(M.CLASSES)
cls.CPPCLS = "fairygui::UISource"
cls.SUPERCLS = "fairygui::IUISource"
cls.CHUNK = [[
NS_FGUI_BEGIN
class UISource : public IUISource {
public:
    CREATE_FUNC(UISource);

    virtual const std::string& getFileName() { return _name; }
    virtual void setFileName(const std::string& value) { _name = value; }
    virtual bool isLoaded() { return _loaded; }
    virtual void load(std::function<void()> callback) { _complete = callback; }

    void loadComplete()
    {
        _loaded = true;
        if (_complete) {
            _complete();
        }
    }
private:
    UISource()
        :_loaded(false)
        ,_complete(nullptr)
    {
    }

    bool init()
    {
        return true;
    }

    std::function<void()> _complete;
    std::string _name;
    bool _loaded;
};
NS_FGUI_END
]]
cls.funcs [[
]]
cls.func('create', [[static UISource *create()]])
cls.func('loadComplete', [[void loadComplete()]])

cls = class(M.CLASSES)
cls.CPPCLS = "fairygui::Window"
cls.SUPERCLS = "fairygui::GComponent"
cls.funcs [[
    static fairygui::Window *create()
    @unref(cmp children parent)@ref(map children parent) void show()
    @unref(cmp children parent) void hide()
    @unref(cmp children parent) void hideImmediately()
    void toggleStatus()
    void bringToFront()
    bool isShowing()
    bool isTop()
    bool isModal()
    void setModal(bool value)
    void showModalWait()
    void showModalWait(int requestingCmd)
    bool closeModalWait()
    bool closeModalWait(int requestingCmd)
    void initWindow()
    void addUISource(IUISource* uiSource)
    bool isBringToFrontOnClick()
    void setBringToFrontOnClick(bool value)
    @ref(single contentPane) GComponent* getContentPane()
    void setContentPane(@ref(single contentPane) GComponent* value)
    @ref(single frame) GComponent* getFrame()
    @ref(single closeButton) GObject* getCloseButton()
    void setCloseButton(@ref(single closeButton) GObject* value)
    @ref(single dragArea) GObject* getDragArea()
    void setDragArea(@ref(single dragArea) GObject* value)
    @ref(single contentArea) GObject* getContentArea()
    void setContentArea(@ref(single contentArea) GObject* value)
    @ref(single modalWaitingPane) GObject* getModalWaitingPane()
]]
cls.inject('show', {
    BEFORE = [[
        fairygui::GComponent *root = fairygui::UIRoot;
        if (!root) {
            luaL_error(L, "no root to add 'Window'");
        }
        olua_push_cppobj<fairygui::GComponent>(L, root, "fui.GComponent");
        int parent = lua_gettop(L);
    ]],
})
cls.inject({'hide', 'hideImmediately'}, {
    BEFORE = [[
        fairygui::GComponent *root = self->getParent() ? self->getParent() : fairygui::UIRoot;
        if (!root) {
            return 0;
        }
        olua_push_cppobj<fairygui::GComponent>(L, root, "fui.GComponent");
        int parent = lua_gettop(L);
    ]],
})
cls.props [[
    showing
    top
    modal
    bringToFrontOnClick
    contentPane
    frame
    closeButton
    dragArea
    contentArea
    modalWaitingPane
]]

cls = class(M.CLASSES)
cls.CPPCLS = "fairygui::DragDropManager"
cls.funcs [[
    static DragDropManager* getInstance()
    GLoader* getAgent()
    bool isDragging()
    void startDrag(const std::string& icon, const cocos2d::Value& sourceData = cocos2d::Value::Null, int touchPointID = -1)
    void cancel()
]]
cls.props [[
    instance
    agent
    dragging
]]

cls = class(M.CLASSES)
cls.CPPCLS = "fairygui::UIObjectFactory"
cls.funcs [[
    static GObject* newObject(PackageItem* pi)
    static GObject* newObject(ObjectType type)
]]
cls.callback {
    FUNCS =  {
        'static void setPackageItemExtension(const std::string& url, std::function<GComponent*()> creator)',
    },
    TAG_MAKER = 'olua_makecallbacktag("packageItemExtension")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
    CALLONCE = false,
    REMOVE = false,
}
cls.callback {
    FUNCS =  {
        'static void setLoaderExtension(std::function<GLoader*()> creator)',
    },
    TAG_MAKER = 'olua_makecallbacktag("loaderExtension")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
    CALLONCE = false,
    REMOVE = false,
}

cls = class(M.CLASSES)
cls.CPPCLS = "fairygui::GearBase"
cls.funcs [[
]]

cls = class(M.CLASSES)
cls.CPPCLS = "fairygui::TreeNode"
cls.SUPERCLS = "cocos2d::Ref"
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
cls.prop('numChildren', 'int numChildren()')
cls.inject('addChildAt', {
    BEFORE = [[
        if (!(arg2 >= 0 && arg2 <= self->numChildren())) {
            luaL_error(L, "index out of range");
        }
    ]],
})
cls.inject({'getChildAt', 'removeChildAt'}, {
    BEFORE = [[
        if (!(arg1 >= 0 && arg1 < self->numChildren())) {
            luaL_error(L, "index out of range");
        }
    ]],
})
cls.inject('removeChildren', {
    BEFORE = [[
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
    ]],
})
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

cls = class(M.CLASSES)
cls.CPPCLS = "fairygui::TreeView"
cls.SUPERCLS = "fairygui::UIEventDispatcher"
cls.funcs [[
    static TreeView* create(@ref(single list) GList* list)
    @ref(single list) GList* getList()
    @ref(single rootNode) TreeNode* getRootNode()
    TreeNode* getSelectedNode()
    void addSelection(TreeNode* node, bool scrollItToView = false)
    void removeSelection(TreeNode* node)
    void clearSelection()
    int getNodeIndex(TreeNode* node)
    void updateNode(TreeNode* node)
    void expandAll(TreeNode* folderNode)
    void collapseAll(TreeNode* folderNode)
]]
cls.func('getSelection', [[{
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
cls.var('treeNodeCreateCell', [[std::function<GComponent*(TreeNode* node)> treeNodeCreateCell]])
cls.var('treeNodeRender', [[std::function<void(TreeNode* node)> treeNodeRender]])
cls.var('treeNodeWillExpand', [[std::function<void(TreeNode* node, bool expand)> treeNodeWillExpand]])
cls.inject('create', {
    AFTER = [[
        olua_push_cppobj<fairygui::TreeNode>(L, ret->getRootNode(), "fui.TreeNode");
        olua_singleref(L, -2, "rootNode", -1);
        lua_pop(L, 1);
    ]],
})
cls.inject('treeNodeCreateCell', {
    CALLBACK_AFTER = [[
        olua_push_cppobj<fairygui::TreeNode>(L, arg1, "fui.TreeNode");
        olua_singleref(L, -1, "cell", -2);
        lua_pop(L, 1);
    ]],
})
cls.props [[
    list
    rootNode
    selectedNode
]]

return M
