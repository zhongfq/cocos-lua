-- AUTO BUILD, DON'T MODIFY!

require "autobuild.fairygui-types"

local olua = require "olua"
local typeconv = olua.typeconv
local typecls = olua.typecls
local cls = nil
local M = {}

M.NAME = "fairygui"
M.PATH = "../../frameworks/libxgame/src/lua-bindings"
M.INCLUDES = [[
#include "lua-bindings/lua_fairygui.h"
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "xgame/xlua.h"
#include "FairyGUI.h"
#include "tween/EaseManager.h"
#include "tween/GPath.h"
#include "display/FUISprite.h"
]]
M.CHUNK = [[
bool manual_olua_is_fairygui_EventTag(lua_State *L, int idx)
{
    return olua_isinteger(L, idx) || olua_isa(L, idx, OLUA_VOIDCLS);
}

void manual_olua_check_fairygui_EventTag(lua_State *L, int idx, fairygui::EventTag *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    if (olua_isinteger(L, idx)) {
        *value = (int)olua_tointeger(L, idx);
    } else {
        *value = (void *)olua_checkobj(L, idx, OLUA_VOIDCLS);
    }
}
]]

M.CONVS = {
    typeconv {
        CPPCLS = 'fairygui::Margin',
        DEF = [[
            float left;
            float top;
            float right;
            float bottom;
        ]],
    },
    typeconv {
        CPPCLS = 'fairygui::TweenValue',
        DEF = [[
            @optional float x;
            @optional float y;
            @optional float z;
            @optional float w;
            @optional double d;
        ]],
    },
}

M.CLASSES = {}

cls = typecls 'fairygui::UIEventType'
cls.const('Enter', 'fairygui::UIEventType::Enter', 'const int')
cls.const('Exit', 'fairygui::UIEventType::Exit', 'const int')
cls.const('Changed', 'fairygui::UIEventType::Changed', 'const int')
cls.const('Submit', 'fairygui::UIEventType::Submit', 'const int')
cls.const('TouchBegin', 'fairygui::UIEventType::TouchBegin', 'const int')
cls.const('TouchMove', 'fairygui::UIEventType::TouchMove', 'const int')
cls.const('TouchEnd', 'fairygui::UIEventType::TouchEnd', 'const int')
cls.const('Click', 'fairygui::UIEventType::Click', 'const int')
cls.const('RollOver', 'fairygui::UIEventType::RollOver', 'const int')
cls.const('RollOut', 'fairygui::UIEventType::RollOut', 'const int')
cls.const('MouseWheel', 'fairygui::UIEventType::MouseWheel', 'const int')
cls.const('RightClick', 'fairygui::UIEventType::RightClick', 'const int')
cls.const('MiddleClick', 'fairygui::UIEventType::MiddleClick', 'const int')
cls.const('PositionChange', 'fairygui::UIEventType::PositionChange', 'const int')
cls.const('SizeChange', 'fairygui::UIEventType::SizeChange', 'const int')
cls.const('KeyDown', 'fairygui::UIEventType::KeyDown', 'const int')
cls.const('KeyUp', 'fairygui::UIEventType::KeyUp', 'const int')
cls.const('Scroll', 'fairygui::UIEventType::Scroll', 'const int')
cls.const('ScrollEnd', 'fairygui::UIEventType::ScrollEnd', 'const int')
cls.const('PullDownRelease', 'fairygui::UIEventType::PullDownRelease', 'const int')
cls.const('PullUpRelease', 'fairygui::UIEventType::PullUpRelease', 'const int')
cls.const('ClickItem', 'fairygui::UIEventType::ClickItem', 'const int')
cls.const('ClickLink', 'fairygui::UIEventType::ClickLink', 'const int')
cls.const('ClickMenu', 'fairygui::UIEventType::ClickMenu', 'const int')
cls.const('RightClickItem', 'fairygui::UIEventType::RightClickItem', 'const int')
cls.const('DragStart', 'fairygui::UIEventType::DragStart', 'const int')
cls.const('DragMove', 'fairygui::UIEventType::DragMove', 'const int')
cls.const('DragEnd', 'fairygui::UIEventType::DragEnd', 'const int')
cls.const('Drop', 'fairygui::UIEventType::Drop', 'const int')
cls.const('GearStop', 'fairygui::UIEventType::GearStop', 'const int')
cls.funcs [[
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::UIEventDispatcher'
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
        sprintf(buf, "listeners.%d.", (int)type);
    }
    return std::string(buf);
}
]]
cls.funcs [[
    UIEventDispatcher()
    bool hasEventListener(int eventType)
    bool hasEventListener(int eventType, const fairygui::EventTag &tag)
    bool dispatchEvent(int eventType, @optional void *data, @optional const cocos2d::Value &dataValue)
    bool bubbleEvent(int eventType, @optional void *data, @optional const cocos2d::Value &dataValue)
    bool isDispatchingEvent(int eventType)
]]
cls.callback {
    FUNCS =  {
        'void addEventListener(int eventType, @local const std::function<void (EventContext *)> &callback)',
        'void addEventListener(int eventType, @local const std::function<void (EventContext *)> &callback, const fairygui::EventTag &tag)'
    },
    TAG_MAKER = {'makeListenerTag(L, #1, 0)', 'makeListenerTag(L, #1, 4)'},
    TAG_MODE = 'OLUA_TAG_NEW',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        'void removeEventListener(int eventType)',
        'void removeEventListener(int eventType, const fairygui::EventTag &tag)'
    },
    TAG_MAKER = {'makeListenerTag(L, #1, 0)', 'makeListenerTag(L, #1, 3)'},
    TAG_MODE = {'OLUA_TAG_SUBSTARTWITH', 'OLUA_TAG_SUBEQUAL'},
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        'void removeEventListeners()'
    },
    TAG_MAKER = 'makeListenerTag(L, -1, 0)',
    TAG_MODE = 'OLUA_TAG_SUBSTARTWITH',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::EventContext'
cls.funcs [[
    EventContext()
    int getType()
    cocos2d::Ref *getSender()
    fairygui::InputEvent *getInput()
    void stopPropagation()
    void preventDefault()
    bool isDefaultPrevented()
    void captureTouch()
    void uncaptureTouch()
    const cocos2d::Value &getDataValue()
    void *getData()
]]
cls.props [[
    type
    sender
    input
    defaultPrevented
    dataValue
    data
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::IHitTest'
cls.funcs [[
    bool hitTest(fairygui::GComponent *obj, const cocos2d::Vec2 &localPoint)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::PixelHitTest'
cls.SUPERCLS = "fairygui::IHitTest"
cls.funcs [[
    PixelHitTest(fairygui::PixelHitTestData *data, int offsetX, int offsetY)
]]
cls.var('offsetX', [[int offsetX]])
cls.var('offsetY', [[int offsetY]])
cls.var('scaleX', [[float scaleX]])
cls.var('scaleY', [[float scaleY]])
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::PixelHitTestData'
cls.funcs [[
    PixelHitTestData()
]]
cls.var('pixelWidth', [[int pixelWidth]])
cls.var('scale', [[float scale]])
cls.var('pixels', [[unsigned char *pixels]])
cls.var('pixelsLength', [[size_t pixelsLength]])
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::InputProcessor'
cls.funcs [[
    fairygui::InputEvent *getRecentInput()
    static bool isTouchOnUI()
    InputProcessor(fairygui::GComponent *owner)
    cocos2d::Vec2 getTouchPosition(int touchId)
    void addTouchMonitor(int touchId, fairygui::GObject *target)
    void removeTouchMonitor(fairygui::GObject *target)
    void cancelClick(int touchId)
    void simulateClick(fairygui::GObject *target, @optional int touchId)
    void disableDefaultTouchEvent()
    bool touchDown(cocos2d::Touch *touch, cocos2d::Event *event)
    void touchMove(cocos2d::Touch *touch, cocos2d::Event *event)
    void touchUp(cocos2d::Touch *touch, cocos2d::Event *event)
]]
cls.callback {
    FUNCS =  {
        'void setCaptureCallback(@nullable @local std::function<void (int)> value)'
    },
    TAG_MAKER = 'CaptureCallback',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.props [[
    recentInput
    touchOnUI
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::InputEvent'
cls.funcs [[
    InputEvent()
    fairygui::GObject *getTarget()
    const int getX()
    const int getY()
    const cocos2d::Vec2 &getPosition()
    cocos2d::Touch *getTouch()
    int getTouchId()
    int isDoubleClick()
    cocos2d::EventMouse::MouseButton getButton()
    cocos2d::EventKeyboard::KeyCode getKeyCode()
    bool isCtrlDown()
    bool isAltDown()
    bool isShiftDown()
    int getMouseWheelDelta()
    fairygui::InputProcessor *getProcessor()
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
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::TextFormat'
cls.const('OUTLINE', 'fairygui::TextFormat::OUTLINE', 'const int')
cls.const('SHADOW', 'fairygui::TextFormat::SHADOW', 'const int')
cls.const('GLOW', 'fairygui::TextFormat::GLOW', 'const int')
cls.funcs [[
    TextFormat()
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
    fairygui::TextFormat *self = (fairygui::TextFormat *)olua_toobj(L, 1, "fgui.TextFormat");
    fairygui::TextFormat *fmt = (fairygui::TextFormat *)olua_checkobj(L, 2, "fgui.TextFormat");
    self->setFormat(*fmt);
    return 0;
}]])
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::EaseType'
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
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::EaseManager'
cls.funcs [[
    static float evaluate(fairygui::EaseType easeType, float time, float duration, float overshootOrAmplitude, float period)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::TweenPropType'
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
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::GPath'
cls.funcs [[
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::GTweener'
cls.SUPERCLS = "cocos2d::Ref"
cls.funcs [[
    GTweener()
    fairygui::GTweener *setDelay(float value)
    float getDelay()
    fairygui::GTweener *setDuration(float value)
    float getDuration()
    fairygui::GTweener *setBreakpoint(float value)
    fairygui::GTweener *setEase(fairygui::EaseType value)
    fairygui::GTweener *setEasePeriod(float value)
    fairygui::GTweener *setEaseOvershootOrAmplitude(float value)
    fairygui::GTweener *setRepeat(int repeat, @optional bool yoyo)
    int getRepeat()
    fairygui::GTweener *setTimeScale(float value)
    fairygui::GTweener *setSnapping(bool value)
    fairygui::GTweener *setTargetAny(void *value)
    fairygui::GTweener *setTarget(cocos2d::Ref *target)
    fairygui::GTweener *setTarget(cocos2d::Ref *target, fairygui::TweenPropType propType)
    void *getTarget()
    fairygui::GTweener *setUserData(const cocos2d::Value &value)
    fairygui::GTweener *setPath(fairygui::GPath *path)
    const cocos2d::Value &getUserData()
    float getNormalizedTime()
    bool isCompleted()
    bool allCompleted()
    fairygui::GTweener *setPaused(bool paused)
    void seek(float time)
    void kill(@optional bool complete)
]]
cls.var('startValue', [[fairygui::TweenValue startValue]])
cls.var('endValue', [[fairygui::TweenValue endValue]])
cls.var('value', [[fairygui::TweenValue value]])
cls.var('deltaValue', [[fairygui::TweenValue deltaValue]])
cls.callback {
    FUNCS =  {
        'fairygui::GTweener *onUpdate(std::function<void (GTweener *)> callback)'
    },
    TAG_MAKER = 'onUpdate',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        'fairygui::GTweener *onStart(std::function<void (GTweener *)> callback)'
    },
    TAG_MAKER = 'onStart',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        'fairygui::GTweener *onComplete(std::function<void ()> callback)'
    },
    TAG_MAKER = 'onComplete',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        'fairygui::GTweener *onComplete1(std::function<void (GTweener *)> callback)'
    },
    TAG_MAKER = 'onComplete1',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
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
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::GTween'
cls.CHUNK = [[
static bool should_del_tweener_ref(lua_State *L, int idx)
{
    if (olua_isa(L, idx, "fgui.GTweener")) {
        fairygui::GTweener *obj = (fairygui::GTweener *)olua_toobj(L, idx, "fgui.GTweener");
        if (obj->getReferenceCount() == 1 || obj->allCompleted()) {
            return true;
        }
    }
    return false;
}
]]
cls.funcs [[
    static fairygui::GTweener *to(float startValue, float endValue, float duration)
    static fairygui::GTweener *to(const cocos2d::Vec2 &startValue, const cocos2d::Vec2 &endValue, float duration)
    static fairygui::GTweener *to(const cocos2d::Vec3 &startValue, const cocos2d::Vec3 &endValue, float duration)
    static fairygui::GTweener *to(const cocos2d::Vec4 &startValue, const cocos2d::Vec4 &endValue, float duration)
    static fairygui::GTweener *to(const cocos2d::Color4B &startValue, const cocos2d::Color4B &endValue, float duration)
    static fairygui::GTweener *toDouble(double startValue, double endValue, float duration)
    static fairygui::GTweener *delayedCall(float delay)
    static fairygui::GTweener *shake(const cocos2d::Vec2 &startValue, float amplitude, float duration)
    static bool isTweening(cocos2d::Ref *target)
    static bool isTweening(cocos2d::Ref *target, fairygui::TweenPropType propType)
    static void kill(cocos2d::Ref *target)
    static void kill(cocos2d::Ref *target, bool complete)
    static void kill(cocos2d::Ref *target, fairygui::TweenPropType propType, bool complete)
    static fairygui::GTweener *getTween(cocos2d::Ref *target)
    static fairygui::GTweener *getTween(cocos2d::Ref *target, fairygui::TweenPropType propType)
    static void clean()
]]
cls.inject('to', {
    AFTER = [[
        olua_pushclassobj(L, "fgui.GTween");
        olua_addref(L, -1, "tweeners", -2, OLUA_MODE_MULTIPLE);
        olua_visitrefs(L, -1, "tweeners", should_del_tweener_ref);
        lua_pop(L, 1);
    ]],
})
cls.inject('toDouble', {
    AFTER = [[
        olua_pushclassobj(L, "fgui.GTween");
        olua_addref(L, -1, "tweeners", -2, OLUA_MODE_MULTIPLE);
        olua_visitrefs(L, -1, "tweeners", should_del_tweener_ref);
        lua_pop(L, 1);
    ]],
})
cls.inject('delayedCall', {
    AFTER = [[
        olua_pushclassobj(L, "fgui.GTween");
        olua_addref(L, -1, "tweeners", -2, OLUA_MODE_MULTIPLE);
        olua_visitrefs(L, -1, "tweeners", should_del_tweener_ref);
        lua_pop(L, 1);
    ]],
})
cls.inject('shake', {
    AFTER = [[
        olua_pushclassobj(L, "fgui.GTween");
        olua_addref(L, -1, "tweeners", -2, OLUA_MODE_MULTIPLE);
        olua_visitrefs(L, -1, "tweeners", should_del_tweener_ref);
        lua_pop(L, 1);
    ]],
})
cls.inject('kill', {
    AFTER = [[
        olua_pushclassobj(L, "fgui.GTween");
        olua_visitrefs(L, -1, "tweeners", should_del_tweener_ref);
        lua_pop(L, 1);
    ]],
})
cls.inject('clean', {
    AFTER = [[
        olua_pushclassobj(L, "fgui.GTween");
        olua_delallrefs(L, 1, "tweeners");
    ]],
})
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::UIPackage'
cls.SUPERCLS = "cocos2d::Ref"
cls.const('URL_PREFIX', 'fairygui::UIPackage::URL_PREFIX', 'const std::string')
cls.funcs [[
    UIPackage()
    static fairygui::UIPackage *getById(const std::string &id)
    static fairygui::UIPackage *getByName(const std::string &name)
    static fairygui::UIPackage *addPackage(const std::string &descFilePath)
    static void removePackage(const std::string &packageIdOrName)
    static void removeAllPackages()
    static fairygui::GObject *createObject(const std::string &pkgName, const std::string &resName)
    static fairygui::GObject *createObjectFromURL(const std::string &url)
    static std::string getItemURL(const std::string &pkgName, const std::string &resName)
    static fairygui::PackageItem *getItemByURL(const std::string &url)
    static std::string normalizeURL(const std::string &url)
    static void *getItemAsset(const std::string &pkgName, const std::string &resName, @optional fairygui::PackageItemType type)
    static void *getItemAssetByURL(const std::string &url, @optional fairygui::PackageItemType type)
    static cocos2d::Texture2D *getEmptyTexture()
    const std::string &getId()
    const std::string &getName()
    fairygui::PackageItem *getItem(const std::string &itemId)
    fairygui::PackageItem *getItemByName(const std::string &itemName)
    void *getItemAsset(fairygui::PackageItem *item)
    static const std::string &getBranch()
    static void setBranch(const std::string &value)
    static const std::string &getVar(const std::string &key)
    static void setVar(const std::string &key, const std::string &value)
]]
cls.props [[
    emptyTexture
    id
    name
    branch
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::PackageItem'
cls.SUPERCLS = "cocos2d::Ref"
cls.funcs [[
    PackageItem()
    void load()
    fairygui::PackageItem *getBranch()
    fairygui::PackageItem *getHighResolution()
]]
cls.var('owner', [[fairygui::UIPackage *owner]])
cls.var('type', [[fairygui::PackageItemType type]])
cls.var('objectType', [[fairygui::ObjectType objectType]])
cls.var('id', [[std::string id]])
cls.var('name', [[std::string name]])
cls.var('width', [[int width]])
cls.var('height', [[int height]])
cls.var('file', [[std::string file]])
cls.var('texture', [[cocos2d::Texture2D *texture]])
cls.var('scaleByTile', [[bool scaleByTile]])
cls.var('tileGridIndice', [[int tileGridIndice]])
cls.var('spriteFrame', [[cocos2d::SpriteFrame *spriteFrame]])
cls.var('animation', [[cocos2d::Animation *animation]])
cls.var('delayPerUnit', [[float delayPerUnit]])
cls.var('repeatDelay', [[float repeatDelay]])
cls.var('swing', [[bool swing]])
cls.var('translated', [[bool translated]])
cls.props [[
    branch
    highResolution
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::PackageItemType'
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
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::ObjectType'
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
    TREE
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::ButtonMode'
cls.enums [[
    COMMON
    CHECK
    RADIO
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::ChildrenRenderOrder'
cls.enums [[
    ASCENT
    DESCENT
    ARCH
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::OverflowType'
cls.enums [[
    VISIBLE
    HIDDEN
    SCROLL
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::ScrollType'
cls.enums [[
    HORIZONTAL
    VERTICAL
    BOTH
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::ScrollBarDisplayType'
cls.enums [[
    DEFAULT
    VISIBLE
    AUTO
    HIDDEN
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::LoaderFillType'
cls.enums [[
    NONE
    SCALE
    SCALE_MATCH_HEIGHT
    SCALE_MATCH_WIDTH
    SCALE_FREE
    SCALE_NO_BORDER
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::ProgressTitleType'
cls.enums [[
    PERCENT
    VALUE_MAX
    VALUE
    MAX
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::ListLayoutType'
cls.enums [[
    SINGLE_COLUMN
    SINGLE_ROW
    FLOW_HORIZONTAL
    FLOW_VERTICAL
    PAGINATION
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::ListSelectionMode'
cls.enums [[
    SINGLE
    MULTIPLE
    MULTIPLE_SINGLECLICK
    NONE
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::GroupLayoutType'
cls.enums [[
    NONE
    HORIZONTAL
    VERTICAL
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::PopupDirection'
cls.enums [[
    AUTO
    UP
    DOWN
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::AutoSizeType'
cls.enums [[
    NONE
    BOTH
    HEIGHT
    SHRINK
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::FlipType'
cls.enums [[
    NONE
    HORIZONTAL
    VERTICAL
    BOTH
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::TransitionActionType'
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
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::FillMethod'
cls.enums [[
    None
    Horizontal
    Vertical
    Radial90
    Radial180
    Radial360
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::FillOrigin'
cls.enums [[
    Top
    Bottom
    Left
    Right
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::ObjectPropID'
cls.enums [[
    Text
    Icon
    Color
    OutlineColor
    Playing
    Frame
    DeltaTime
    TimeScale
    FontSize
    Selected
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::GController'
cls.SUPERCLS = "fairygui::UIEventDispatcher"
cls.funcs [[
    GController()
    fairygui::GComponent *getParent()
    void setParent(fairygui::GComponent *value)
    int getSelectedIndex()
    void setSelectedIndex(int value, @optional bool triggerEvent)
    const std::string &getSelectedPage()
    void setSelectedPage(const std::string &value, @optional bool triggerEvent)
    const std::string &getSelectedPageId()
    void setSelectedPageId(const std::string &value, @optional bool triggerEvent)
    int getPrevisousIndex()
    const std::string &getPreviousPage()
    const std::string &getPreviousPageId()
    int getPageCount()
    bool hasPage(const std::string &aName)
    int getPageIndexById(const std::string &value)
    const std::string &getPageNameById(const std::string &value)
    const std::string &getPageId(int index)
    void setOppositePageId(const std::string &value)
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
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::GObject'
cls.SUPERCLS = "fairygui::UIEventDispatcher"
cls.funcs [[
    static fairygui::GObject *getDraggingObject()
    GObject()
    static fairygui::GObject *create()
    float getX()
    void setX(float value)
    float getY()
    void setY(float value)
    const cocos2d::Vec2 &getPosition()
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
    const cocos2d::Size &getSize()
    void setSize(float wv, float hv, @optional bool ignorePivot)
    void center(@optional bool restraint)
    void makeFullScreen()
    const cocos2d::Vec2 &getPivot()
    void setPivot(float xv, float yv, @optional bool asAnchor)
    bool isPivotAsAnchor()
    float getScaleX()
    void setScaleX(float value)
    float getScaleY()
    void setScaleY(float value)
    const cocos2d::Vec2 &getScale()
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
    @addref(group ^) fairygui::GGroup *getGroup()
    void setGroup(@addref(group ^) fairygui::GGroup *value)
    const std::string &getText()
    void setText(const std::string &text)
    const std::string &getIcon()
    void setIcon(const std::string &text)
    const std::string &getTooltips()
    void setTooltips(const std::string &value)
    void *getData()
    void setData(void *value)
    const cocos2d::Value &getCustomData()
    void setCustomData(const cocos2d::Value &value)
    bool isDraggable()
    void setDraggable(bool value)
    void setDragBounds(const cocos2d::Rect &value)
    void startDrag(@optional int touchId)
    void stopDrag()
    std::string getResourceURL()
    fairygui::PackageItem *getPackageItem()
    cocos2d::Vec2 globalToLocal(@pack const cocos2d::Vec2 &pt)
    cocos2d::Rect globalToLocal(@pack const cocos2d::Rect &rect)
    cocos2d::Vec2 localToGlobal(@pack const cocos2d::Vec2 &pt)
    cocos2d::Rect localToGlobal(@pack const cocos2d::Rect &rect)
    cocos2d::Rect transformRect(@pack const cocos2d::Rect &rect, fairygui::GObject *targetSpace)
    fairygui::Relations *relations()
    void addRelation(fairygui::GObject *target, fairygui::RelationType relationType, @optional bool usePercent)
    void removeRelation(fairygui::GObject *target, fairygui::RelationType relationType)
    fairygui::GearBase *getGear(int index)
    bool checkGearController(int index, fairygui::GController *c)
    uint32_t addDisplayLock()
    void releaseDisplayLock(uint32_t token)
    fairygui::GComponent *getParent()
    fairygui::GObject *findParent()
    @addref(displayObject ^) cocos2d::Node *displayObject()
    fairygui::GRoot *getRoot()
    bool onStage()
    void removeFromParent()
    cocos2d::Value getProp(fairygui::ObjectPropID propId)
    void setProp(fairygui::ObjectPropID propId, const cocos2d::Value &value)
    fairygui::GObject *hitTest(const cocos2d::Vec2 &worldPoint, const cocos2d::Camera *camera)
    fairygui::GTreeNode *treeNode()
]]
cls.var('id', [[std::string id]])
cls.var('name', [[std::string name]])
cls.var('sourceSize', [[cocos2d::Size sourceSize]])
cls.var('initSize', [[cocos2d::Size initSize]])
cls.var('minSize', [[cocos2d::Size minSize]])
cls.var('maxSize', [[cocos2d::Size maxSize]])
cls.func('getDragBounds', [[{
    fairygui::GObject *self = (fairygui::GObject *)olua_toobj(L, 1, "fgui.GObject");
    cocos2d::Rect *rect = self->getDragBounds();
    manual_olua_push_cocos2d_Rect(L, rect);
    return 1;
}]])
cls.prop('relations', 'Relations* relations()')
cls.prop('displayObject', 'cocos2d::Node* displayObject()')
cls.callback {
    FUNCS =  {
        'void addClickListener(@local const std::function<void (EventContext *)> &callback)',
        'void addClickListener(@local const std::function<void (EventContext *)> &callback, const fairygui::EventTag &tag)'
    },
    TAG_MAKER = {'makeListenerTag(L, fairygui::UIEventType::Click, 0)', 'makeListenerTag(L, fairygui::UIEventType::Click, 3)'},
    TAG_MODE = 'OLUA_TAG_NEW',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        'void removeClickListener(const fairygui::EventTag &tag)'
    },
    TAG_MAKER = 'makeListenerTag(L, fairygui::UIEventType::Click, 2)',
    TAG_MODE = 'OLUA_TAG_SUBEQUAL',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
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
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::GComponent'
cls.SUPERCLS = "fairygui::GObject"
cls.funcs [[
    GComponent()
    static fairygui::GComponent *create()
    fairygui::GObject *addChild(@addref(children |) fairygui::GObject *child)
    fairygui::GObject *addChildAt(@addref(children |) fairygui::GObject *child, int index)
    void removeChild(@delref(children |) fairygui::GObject *child)
    @delref(children ~) void removeChildAt(int index)
    @delref(children ~) void removeChildren()
    @delref(children ~) void removeChildren(int beginIndex, int endIndex)
    @addref(children |) fairygui::GObject *getChildAt(int index)
    @addref(children |) fairygui::GObject *getChild(const std::string &name)
    fairygui::GObject *getChildByPath(const std::string &path)
    @addref(children |) fairygui::GObject *getChildInGroup(const fairygui::GGroup *group, const std::string &name)
    @addref(children |) fairygui::GObject *getChildById(const std::string &id)
    @addref(children |) const cocos2d::Vector<GObject *> &getChildren()
    int getChildIndex(const fairygui::GObject *child)
    void setChildIndex(fairygui::GObject *child, int index)
    int setChildIndexBefore(fairygui::GObject *child, int index)
    void swapChildren(fairygui::GObject *child1, fairygui::GObject *child2)
    void swapChildrenAt(int index1, int index2)
    int numChildren()
    bool isAncestorOf(const fairygui::GObject *obj)
    bool isChildInView(fairygui::GObject *child)
    int getFirstChildInView()
    void addController(@addref(controllers |) fairygui::GController *c)
    @addref(controllers |) fairygui::GController *getControllerAt(int index)
    @addref(controllers |) fairygui::GController *getController(const std::string &name)
    @addref(controllers |) const cocos2d::Vector<GController *> &getControllers()
    void removeController(@delref(controllers |) fairygui::GController *c)
    void applyController(fairygui::GController *c)
    void applyAllControllers()
    @addref(transitions |) fairygui::Transition *getTransition(const std::string &name)
    @addref(transitions |) fairygui::Transition *getTransitionAt(int index)
    @addref(transitions |) const cocos2d::Vector<Transition *> &getTransitions()
    bool getOpaque()
    void setOpaque(bool value)
    const fairygui::Margin &getMargin()
    void setMargin(const fairygui::Margin &value)
    fairygui::ChildrenRenderOrder getChildrenRenderOrder()
    void setChildrenRenderOrder(fairygui::ChildrenRenderOrder value)
    int getApexIndex()
    void setApexIndex(int value)
    @addref(mask ^) cocos2d::Node *getMask()
    void setMask(@addref(mask ^) cocos2d::Node *value, @optional bool inverted)
    fairygui::IHitTest *getHitArea()
    void setHitArea(fairygui::IHitTest *value)
    fairygui::ScrollPane *getScrollPane()
    float getViewWidth()
    void setViewWidth(float value)
    float getViewHeight()
    void setViewHeight(float value)
    void setBoundsChangedFlag()
    void ensureBoundsCorrect()
    cocos2d::Vec2 getSnappingPosition(const cocos2d::Vec2 &pt)
    void childSortingOrderChanged(fairygui::GObject *child, int oldValue, int newValue)
    void childStateChanged(fairygui::GObject *child)
    void adjustRadioGroupDepth(fairygui::GObject *obj, fairygui::GController *c)
]]
cls.func('resolve', [[{
    auto self = olua_toobj<fairygui::GComponent>(L, 1);
    const char *name = olua_checkstring(L, 2);
    char type = '.';
    while (true) {
        const char *pos = strchr(name, '.');
        if (!pos) {
            pos = strchr(name, '#');
            type = pos ? '#' : type;
        }
        if (!pos) {
            pos = strchr(name, '~');
            type = pos ? '~' : type;
        }
        if (pos == name) {
            pos = nullptr;
            ++name;
        }
        if (pos) {
            lua_pushcfunction(L, _fairygui_GComponent_getChild);
            olua_push_cppobj<fairygui::GComponent>(L, self);
            lua_pushlstring(L, name, pos - name);
            lua_call(L, 2, 1);

            if (olua_isa(L, -1, "fgui.GComponent")) {
                self = olua_toobj<fairygui::GComponent>(L, -1);
            } else {
                return 0;
            }
            name = pos + 1;
        } else {
            if (type == '#') {
                lua_pushcfunction(L, _fairygui_GComponent_getController);
            } else if (type == '~') {
                lua_pushcfunction(L, _fairygui_GComponent_getTransition);
            } else {
                lua_pushcfunction(L, _fairygui_GComponent_getChild);
            }

            olua_push_cppobj<fairygui::GComponent>(L, self);
            lua_pushstring(L, name);
            lua_call(L, 2, 1);
            return 1;
        }
    }
    return 0;
}]])
cls.prop('numChildren', 'int numChildren()')
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
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::GRoot'
cls.SUPERCLS = "fairygui::GComponent"
cls.funcs [[
    GRoot()
    static fairygui::GRoot *create(cocos2d::Scene *scene, @optional int zOrder)
    static fairygui::GRoot *getInstance()
    @delref(children ~) void showWindow(@addref(children |) fairygui::Window *win)
    @delref(children ~ parent) void hideWindow(fairygui::Window *win)
    @delref(children ~ parent) void hideWindowImmediately(fairygui::Window *win)
    void bringToFront(fairygui::Window *win)
    void showModalWait()
    void closeModalWait()
    void closeAllExceptModals()
    void closeAllWindows()
    @addref(children |) fairygui::Window *getTopWindow()
    @addref(children |) fairygui::GObject *getModalWaitingPane()
    @addref(children |) fairygui::GGraph *getModalLayer()
    bool hasModalWindow()
    bool isModalWaiting()
    @addref(inputProcessor ^) fairygui::InputProcessor *getInputProcessor()
    cocos2d::Vec2 getTouchPosition(int touchId)
    fairygui::GObject *getTouchTarget()
    cocos2d::Vec2 worldToRoot(const cocos2d::Vec2 &pt)
    cocos2d::Vec2 rootToWorld(const cocos2d::Vec2 &pt)
    @delref(children ~) void showPopup(@addref(children |) fairygui::GObject *popup)
    @delref(children ~) void showPopup(@addref(children |) fairygui::GObject *popup, fairygui::GObject *target, fairygui::PopupDirection dir)
    @delref(children ~) void togglePopup(@addref(children |) fairygui::GObject *popup)
    @delref(children ~) void togglePopup(@addref(children |) fairygui::GObject *popup, fairygui::GObject *target, fairygui::PopupDirection dir)
    @delref(children ~) void hidePopup()
    @delref(children ~) void hidePopup(fairygui::GObject *popup)
    bool hasAnyPopup()
    cocos2d::Vec2 getPoupPosition(fairygui::GObject *popup, fairygui::GObject *target, fairygui::PopupDirection dir)
    void showTooltips(const std::string &msg)
    void showTooltipsWin(fairygui::GObject *tooltipWin)
    void hideTooltips()
    void playSound(const std::string &url, @optional float volumeScale)
    bool isSoundEnabled()
    void setSoundEnabled(bool value)
    float getSoundVolumeScale()
    void setSoundVolumeScale(float value)
    void setNotAsUIRoot()
]]
cls.var('contentScaleLevel', [[static int contentScaleLevel]])
cls.prop('UIRoot', 'static GRoot* getInstance()')
cls.inject('create', {
    AFTER = [[
        olua_push_cppobj<cocos2d::Node>(L, ret->displayObject(), "cc.Node");
        olua_addref(L, -1, "fgui.root", -2, OLUA_MODE_SINGLE);
        olua_addref(L, 1, "children", -1, OLUA_MODE_MULTIPLE);
        lua_pop(L, 1);
    ]],
})
cls.inject('hideWindow', {
    BEFORE = [[
        int parent = 1;
        if (arg1->getParent()) {
            olua_push_cppobj<fairygui::GComponent>(L, arg1->getParent(), "fgui.GComponent");
            parent = lua_gettop(L);
        }
    ]],
})
cls.inject('hideWindowImmediately', {
    BEFORE = [[
        int parent = 1;
        if (arg1->getParent()) {
            olua_push_cppobj<fairygui::GComponent>(L, arg1->getParent(), "fgui.GComponent");
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
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::GGroup'
cls.SUPERCLS = "fairygui::GObject"
cls.funcs [[
    GGroup()
    static fairygui::GGroup *create()
    fairygui::GroupLayoutType getLayout()
    void setLayout(fairygui::GroupLayoutType value)
    int getColumnGap()
    void setColumnGap(int value)
    int getLineGap()
    void setLineGap(int value)
    bool isExcludeInvisibles()
    void setExcludeInvisibles(bool value)
    bool isAutoSizeDisabled()
    void setAutoSizeDisabled(bool value)
    int getMainGridIndex()
    void setMainGridIndex(int value)
    int getMainGridMinSize()
    void setMainGridMinSize(int value)
    void setBoundsChangedFlag(@optional bool positionChangedOnly)
    void moveChildren(float dx, float dy)
    void resizeChildren(float dw, float dh)
]]
cls.props [[
    layout
    columnGap
    lineGap
    excludeInvisibles
    autoSizeDisabled
    mainGridIndex
    mainGridMinSize
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::GScrollBar'
cls.SUPERCLS = "fairygui::GComponent"
cls.funcs [[
    GScrollBar()
    static fairygui::GScrollBar *create()
    void setScrollPane(fairygui::ScrollPane *target, bool vertical)
    void setDisplayPerc(float value)
    void setScrollPerc(float value)
    float getMinSize()
]]
cls.props [[
    minSize
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::GLoader'
cls.SUPERCLS = "fairygui::GObject"
cls.funcs [[
    GLoader()
    static fairygui::GLoader *create()
    const std::string &getURL()
    void setURL(const std::string &value)
    cocos2d::TextHAlignment getAlign()
    void setAlign(cocos2d::TextHAlignment value)
    cocos2d::TextVAlignment getVerticalAlign()
    void setVerticalAlign(cocos2d::TextVAlignment value)
    bool getAutoSize()
    void setAutoSize(bool value)
    fairygui::LoaderFillType getFill()
    void setFill(fairygui::LoaderFillType value)
    bool isShrinkOnly()
    void setShrinkOnly(bool value)
    const cocos2d::Size &getContentSize()
    cocos2d::Color3B getColor()
    void setColor(const cocos2d::Color3B &value)
    bool isPlaying()
    void setPlaying(bool value)
    int getFrame()
    void setFrame(int value)
    fairygui::FillMethod getFillMethod()
    void setFillMethod(fairygui::FillMethod value)
    fairygui::FillOrigin getFillOrigin()
    void setFillOrigin(fairygui::FillOrigin value)
    bool isFillClockwise()
    void setFillClockwise(bool value)
    float getFillAmount()
    void setFillAmount(float value)
    @addref(component ^) fairygui::GComponent *getComponent()
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
    fillMethod
    fillOrigin
    fillClockwise
    fillAmount
    component
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::GTextField'
cls.SUPERCLS = "fairygui::GObject"
cls.funcs [[
    bool isUBBEnabled()
    void setUBBEnabled(bool value)
    fairygui::AutoSizeType getAutoSize()
    void setAutoSize(fairygui::AutoSizeType value)
    bool isSingleLine()
    void setSingleLine(bool value)
    fairygui::TextFormat *getTextFormat()
    void applyTextFormat()
    const cocos2d::Size &getTextSize()
    cocos2d::Color3B getColor()
    void setColor(const cocos2d::Color3B &value)
    float getFontSize()
    void setFontSize(float value)
    cocos2d::Color3B getOutlineColor()
    void setOutlineColor(const cocos2d::Color3B &value)
    fairygui::GTextField *setVar(const std::string &name, const cocos2d::Value &value)
    void flushVars()
]]
cls.func('getTemplateVars', [[{
    fairygui::GTextField *self = (fairygui::GTextField *)olua_toobj(L, 1, "fgui.GTextField");
    manual_olua_push_cocos2d_ValueMap(L, self->getTemplateVars());
    return 1;
}]])
cls.func('setTemplateVars', [[{
    cocos2d::ValueMap arg;
    fairygui::GTextField *self = (fairygui::GTextField *)olua_toobj(L, 1, "fgui.GTextField");
    manual_olua_check_cocos2d_ValueMap(L, 2, &arg);
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
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::GBasicTextField'
cls.SUPERCLS = "fairygui::GTextField"
cls.funcs [[
    GBasicTextField()
    static fairygui::GBasicTextField *create()
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::GGraph'
cls.SUPERCLS = "fairygui::GObject"
cls.funcs [[
    GGraph()
    static fairygui::GGraph *create()
    void drawRect(float aWidth, float aHeight, int lineSize, const cocos2d::Color4F &lineColor, const cocos2d::Color4F &fillColor)
    void drawEllipse(float aWidth, float aHeight, int lineSize, const cocos2d::Color4F &lineColor, const cocos2d::Color4F &fillColor)
    bool isEmpty()
    cocos2d::Color3B getColor()
    void setColor(const cocos2d::Color3B &value)
]]
cls.props [[
    empty
    color
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::GButton'
cls.SUPERCLS = "fairygui::GComponent"
cls.const('UP', 'fairygui::GButton::UP', 'const std::string')
cls.const('DOWN', 'fairygui::GButton::DOWN', 'const std::string')
cls.const('OVER', 'fairygui::GButton::OVER', 'const std::string')
cls.const('SELECTED_OVER', 'fairygui::GButton::SELECTED_OVER', 'const std::string')
cls.const('DISABLED', 'fairygui::GButton::DISABLED', 'const std::string')
cls.const('SELECTED_DISABLED', 'fairygui::GButton::SELECTED_DISABLED', 'const std::string')
cls.funcs [[
    GButton()
    static fairygui::GButton *create()
    const std::string &getTitle()
    void setTitle(const std::string &value)
    const std::string &getSelectedTitle()
    void setSelectedTitle(const std::string &value)
    const std::string &getSelectedIcon()
    void setSelectedIcon(const std::string &value)
    cocos2d::Color3B getTitleColor()
    void setTitleColor(const cocos2d::Color3B &value)
    int getTitleFontSize()
    void setTitleFontSize(int value)
    bool isSelected()
    void setSelected(bool value)
    @addref(relatedController ^) fairygui::GController *getRelatedController()
    void setRelatedController(@addref(relatedController ^) fairygui::GController *c)
    bool isChangeStateOnClick()
    void setChangeStateOnClick(bool value)
    @addref(textField ^) fairygui::GTextField *getTextField()
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
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::GImage'
cls.SUPERCLS = "fairygui::GObject"
cls.funcs [[
    GImage()
    static fairygui::GImage *create()
    fairygui::FlipType getFlip()
    void setFlip(fairygui::FlipType value)
    cocos2d::Color3B getColor()
    void setColor(const cocos2d::Color3B &value)
    fairygui::FillMethod getFillMethod()
    void setFillMethod(fairygui::FillMethod value)
    fairygui::FillOrigin getFillOrigin()
    void setFillOrigin(fairygui::FillOrigin value)
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
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::GLabel'
cls.SUPERCLS = "fairygui::GComponent"
cls.funcs [[
    GLabel()
    static fairygui::GLabel *create()
    const std::string &getTitle()
    void setTitle(const std::string &value)
    cocos2d::Color3B getTitleColor()
    void setTitleColor(const cocos2d::Color3B &value)
    int getTitleFontSize()
    void setTitleFontSize(int value)
    @addref(textField ^) fairygui::GTextField *getTextField()
]]
cls.props [[
    title
    titleColor
    titleFontSize
    textField
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::GList'
cls.SUPERCLS = "fairygui::GComponent"
cls.funcs [[
    GList()
    static fairygui::GList *create()
    const std::string &getDefaultItem()
    void setDefaultItem(const std::string &value)
    fairygui::ListLayoutType getLayout()
    void setLayout(fairygui::ListLayoutType value)
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
    fairygui::ListSelectionMode getSelectionMode()
    void setSelectionMode(fairygui::ListSelectionMode value)
    fairygui::GObject *getFromPool()
    fairygui::GObject *getFromPool(const std::string &url)
    void returnToPool(@delref(children |) fairygui::GObject *obj)
    @addref(children |) fairygui::GObject *addItemFromPool()
    @addref(children |) fairygui::GObject *addItemFromPool(const std::string &url)
    @delref(children ~) void removeChildToPoolAt(int index)
    void removeChildToPool(@delref(children |) fairygui::GObject *child)
    @delref(children ~) void removeChildrenToPool()
    @delref(children ~) void removeChildrenToPool(int beginIndex, int endIndex)
    int getSelectedIndex()
    void setSelectedIndex(int value)
    void getSelection(@out std::vector<int> &result)
    void addSelection(int index, bool scrollItToView)
    void removeSelection(int index)
    void clearSelection()
    void selectAll()
    void selectReverse()
    void handleArrowKey(int dir)
    void resizeToFit(int itemCount)
    void resizeToFit(int itemCount, int minSize)
    void scrollToView(int index, @optional bool ani, @optional bool setFirst)
    @addref(selectionController ^) fairygui::GController *getSelectionController()
    void setSelectionController(@addref(selectionController ^) fairygui::GController *value)
    @delref(children ~) void setVirtual()
    @delref(children ~) void setVirtualAndLoop()
    bool isVirtual()
    void refreshVirtualList()
    int getNumItems()
    @delref(children ~) void setNumItems(int value)
    int childIndexToItemIndex(int index)
    int itemIndexToChildIndex(int index)
]]
cls.var('scrollItemToViewOnClick', [[bool scrollItemToViewOnClick]])
cls.var('foldInvisibleItems', [[bool foldInvisibleItems]])
cls.var('itemRenderer', [[std::function<void(int, GObject*)> itemRenderer]])
cls.var('itemProvider', [[std::function<std::string(int)> itemProvider]])
cls.inject('itemRenderer', {
    CALLBACK_BEFORE = [[
        if (arg2->getParent()) {
            olua_push_cppobj<fairygui::GComponent>(L, (fairygui::GComponent *)callback_store_obj);
            olua_addref(L, -1, "children", -2, OLUA_MODE_MULTIPLE);
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
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::GMovieClip'
cls.SUPERCLS = "fairygui::GObject"
cls.funcs [[
    GMovieClip()
    static fairygui::GMovieClip *create()
    bool isPlaying()
    void setPlaying(bool value)
    int getFrame()
    void setFrame(int value)
    float getTimeScale()
    void setTimeScale(float value)
    void advance(float time)
    fairygui::FlipType getFlip()
    void setFlip(fairygui::FlipType value)
    cocos2d::Color3B getColor()
    void setColor(const cocos2d::Color3B &value)
]]
cls.callback {
    FUNCS =  {
        'void setPlaySettings(@optional int start, @optional int end, @optional int times, @optional int endAt, @local @optional std::function<void ()> completeCallback)'
    },
    TAG_MAKER = 'PlaySettings',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.props [[
    playing
    frame
    timeScale
    flip
    color
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::GProgressBar'
cls.SUPERCLS = "fairygui::GComponent"
cls.funcs [[
    GProgressBar()
    static fairygui::GProgressBar *create()
    fairygui::ProgressTitleType getTitleType()
    void setTitleType(fairygui::ProgressTitleType value)
    double getMin()
    void setMin(double value)
    double getMax()
    void setMax(double value)
    double getValue()
    void setValue(double value)
    void tweenValue(double value, float duration)
    void update(double newValue)
]]
cls.props [[
    titleType
    min
    max
    value
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::GComboBox'
cls.SUPERCLS = "fairygui::GComponent"
cls.funcs [[
    GComboBox()
    static fairygui::GComboBox *create()
    const std::string &getTitle()
    void setTitle(const std::string &value)
    const cocos2d::Color3B getTitleColor()
    void setTitleColor(const cocos2d::Color3B &value)
    int getTitleFontSize()
    void setTitleFontSize(int value)
    const std::string &getValue()
    void setValue(const std::string &value)
    int getSelectedIndex()
    void setSelectedIndex(int value)
    @addref(selectionController ^) fairygui::GController *getSelectionController()
    void setSelectionController(@addref(selectionController ^) fairygui::GController *value)
    std::vector<std::string> &getItems()
    std::vector<std::string> &getIcons()
    std::vector<std::string> &getValues()
    @addref(dropdown ^) fairygui::GObject *getDropdown()
    void refresh()
    @addref(textField ^) fairygui::GTextField *getTextField()
]]
cls.var('visibleItemCount', [[int visibleItemCount]])
cls.var('popupDirection', [[fairygui::PopupDirection popupDirection]])
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
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::GRichTextField'
cls.SUPERCLS = "fairygui::GTextField"
cls.funcs [[
    GRichTextField()
    static fairygui::GRichTextField *create()
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::GSlider'
cls.SUPERCLS = "fairygui::GComponent"
cls.funcs [[
    GSlider()
    static fairygui::GSlider *create()
    fairygui::ProgressTitleType getTitleType()
    void setTitleType(fairygui::ProgressTitleType value)
    double getMin()
    void setMin(double value)
    double getMax()
    void setMax(double value)
    double getValue()
    void setValue(double value)
    bool getWholeNumbers()
    void setWholeNumbers(bool value)
]]
cls.var('changeOnClick', [[bool changeOnClick]])
cls.var('canDrag', [[bool canDrag]])
cls.props [[
    titleType
    min
    max
    value
    wholeNumbers
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::GTextInput'
cls.SUPERCLS = "fairygui::GTextField"
cls.funcs [[
    GTextInput()
    static fairygui::GTextInput *create()
    void setPrompt(const std::string &value)
    void setPassword(bool value)
    void setKeyboardType(int value)
    void setMaxLength(int value)
    void setRestrict(const std::string &value)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::PopupMenu'
cls.SUPERCLS = "cocos2d::Ref"
cls.funcs [[
    static fairygui::PopupMenu *create(const std::string &resourceURL)
    static fairygui::PopupMenu *create()
    PopupMenu()
    void addSeperator()
    const std::string &getItemName(int index)
    void setItemText(const std::string &name, const std::string &caption)
    void setItemVisible(const std::string &name, bool visible)
    void setItemGrayed(const std::string &name, bool grayed)
    void setItemCheckable(const std::string &name, bool checkable)
    void setItemChecked(const std::string &name, bool check)
    bool isItemChecked(const std::string &name)
    @delref(children ~ parent) bool removeItem(const std::string &name)
    @delref(children ~ parent) void clearItems()
    int getItemCount()
    @addref(contentPane ^) fairygui::GComponent *getContentPane()
    @addref(list ^) fairygui::GList *getList()
    @delref(children ~ parent)@addref(children | parent) void show()
    @delref(children ~ parent)@addref(children | parent) void show(fairygui::GObject *target, fairygui::PopupDirection dir)
]]
cls.callback {
    FUNCS =  {
        '@addref(children | parent) fairygui::GButton *addItem(const std::string &caption, @local std::function<void (EventContext *)> callback)'
    },
    TAG_MAKER = 'makeListenerTag(L, fairygui::UIEventType::ClickMenu, 0)',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = "return",
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        '@addref(children | parent) fairygui::GButton *addItemAt(const std::string &caption, int index, @local std::function<void (EventContext *)> callback)'
    },
    TAG_MAKER = 'makeListenerTag(L, fairygui::UIEventType::ClickMenu, 0)',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = "return",
    TAG_SCOPE = 'object',
}
cls.inject('show', {
    BEFORE = [[
        fairygui::GRoot *root = fairygui::UIRoot;
        if (lua_gettop(L) > 1) {
            fairygui::GObject *target = (fairygui::GObject *)olua_checkobj(L, 2, "fgui.GObject");
            root = target->getRoot();
        }
        if (!root) {
            luaL_error(L, "no root to add 'PopupMenu'");
        }
        olua_push_cppobj<fairygui::GRoot>(L, root);
        int parent = lua_gettop(L);
    ]],
})
cls.inject('removeItem', {
    BEFORE = [[
        olua_push_cppobj<fairygui::GList>(L, self->getList());
        int parent = lua_gettop(L);
    ]],
})
cls.inject('clearItems', {
    BEFORE = [[
        olua_push_cppobj<fairygui::GList>(L, self->getList());
        int parent = lua_gettop(L);
    ]],
})
cls.inject('addItem', {
    BEFORE = [[
        olua_push_cppobj<fairygui::GList>(L, self->getList());
        int parent = lua_gettop(L);
    ]],
})
cls.inject('addItemAt', {
    BEFORE = [[
        olua_push_cppobj<fairygui::GList>(L, self->getList());
        int parent = lua_gettop(L);
    ]],
})
cls.props [[
    itemCount
    contentPane
    list
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::Relations'
cls.funcs [[
    Relations(fairygui::GObject *owner)
    void add(fairygui::GObject *target, fairygui::RelationType relationType)
    void add(fairygui::GObject *target, fairygui::RelationType relationType, bool usePercent)
    void remove(fairygui::GObject *target, fairygui::RelationType relationType)
    bool contains(fairygui::GObject *target)
    void clearFor(fairygui::GObject *target)
    void clearAll()
    void onOwnerSizeChanged(float dWidth, float dHeight, bool applyPivot)
    bool isEmpty()
]]
cls.var('handling', [[fairygui::GObject *handling]])
cls.func('copyFrom', [[{
    fairygui::Relations *self = (fairygui::Relations *)olua_toobj(L, 1, "fgui.Relations");
    fairygui::Relations *source = (fairygui::Relations *)olua_checkobj(L, 2, "fgui.Relations");
    // void copyFrom(const Relations& source)
    self->copyFrom(*source);

    return 0;
}]])
cls.props [[
    empty
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::RelationType'
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
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::RelationItem'
cls.funcs [[
    RelationItem(fairygui::GObject *owner)
    @addref(target ^) fairygui::GObject *getTarget()
    void setTarget(@addref(target ^) fairygui::GObject *value)
    void add(fairygui::RelationType relationType, bool usePercent)
    void internalAdd(fairygui::RelationType relationType, bool usePercent)
    void remove(fairygui::RelationType relationType)
    bool isEmpty()
    void applyOnSelfSizeChanged(float dWidth, float dHeight, bool applyPivot)
]]
cls.func('copyFrom', [[{
    fairygui::RelationItem *self = (fairygui::RelationItem *)olua_toobj(L, 1, "fgui.RelationItem");
    fairygui::RelationItem *source = (fairygui::RelationItem *)olua_checkobj(L, 2, "fgui.RelationItem");
    // void copyFrom(const RelationItem& source)
    self->copyFrom(*source);

    return 0;
}]])
cls.props [[
    target
    empty
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::ScrollPane'
cls.SUPERCLS = "cocos2d::Ref"
cls.funcs [[
    ScrollPane(fairygui::GComponent *owner)
    @addref(owner ^) fairygui::GComponent *getOwner()
    @addref(header ^) fairygui::GComponent *getHeader()
    @addref(footer ^) fairygui::GComponent *getFooter()
    @addref(vtScrollBar ^) fairygui::GScrollBar *getVtScrollBar()
    @addref(hzScrollBar ^) fairygui::GScrollBar *getHzScrollBar()
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
    @addref(pageController ^) fairygui::GController *getPageController()
    void setPageController(@addref(pageController ^) fairygui::GController *value)
    bool isMouseWheelEnabled()
    void setMouseWheelEnabled(bool value)
    float getDecelerationRate()
    void setDecelerationRate(float value)
    float getPosX()
    void setPosX(float value, @optional bool ani)
    float getPosY()
    void setPosY(float value, @optional bool ani)
    float getPercX()
    void setPercX(float value, @optional bool ani)
    float getPercY()
    void setPercY(float value, @optional bool ani)
    bool isBottomMost()
    bool isRightMost()
    void scrollLeft(@optional float ratio, @optional bool ani)
    void scrollRight(@optional float ratio, @optional bool ani)
    void scrollUp(@optional float ratio, @optional bool ani)
    void scrollDown(@optional float ratio, @optional bool ani)
    void scrollTop(@optional bool ani)
    void scrollBottom(@optional bool ani)
    void scrollToView(fairygui::GObject *obj, @optional bool ani, @optional bool setFirst)
    void scrollToView(const cocos2d::Rect &rect, @optional bool ani, @optional bool setFirst)
    bool isChildInView(fairygui::GObject *obj)
    int getPageX()
    void setPageX(int value, @optional bool ani)
    int getPageY()
    void setPageY(int value, @optional bool ani)
    float getScrollingPosX()
    float getScrollingPosY()
    const cocos2d::Size &getContentSize()
    const cocos2d::Size &getViewSize()
    void lockHeader(int size)
    void lockFooter(int size)
    void cancelDragging()
    static fairygui::ScrollPane *getDraggingPane()
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
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::Transition'
cls.SUPERCLS = "cocos2d::Ref"
cls.funcs [[
    Transition(fairygui::GComponent *owner)
    @addref(owner ^) fairygui::GComponent *getOwner()
    bool isPlaying()
    void changePlayTimes(int value)
    void stop()
    void stop(bool setToComplete, bool processCallback)
    void setAutoPlay(bool autoPlay, int times, float delay)
    void setPaused(bool paused)
    void setValue(const std::string &label, const cocos2d::ValueVector &values)
    void setTarget(const std::string &label, fairygui::GObject *newTarget)
    void setDuration(const std::string &label, float value)
    float getLabelTime(const std::string &label)
    float getTimeScale()
    void setTimeScale(float value)
    void updateFromRelations(const std::string &targetId, float dx, float dy)
    void onOwnerAddedToStage()
    void onOwnerRemovedFromStage()
]]
cls.var('name', [[std::string name]])
cls.callback {
    FUNCS =  {
        'void play(@local @optional std::function<void ()> callback)',
        'void play(int times, float delay, @local @optional std::function<void ()> callback)',
        'void play(int times, float delay, float startTime, float endTime, @local @optional std::function<void ()> callback)'
    },
    TAG_MAKER = 'play',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        'void playReverse(@local @optional std::function<void ()> callback)',
        'void playReverse(int times, float delay, @local @optional std::function<void ()> callback)'
    },
    TAG_MAKER = 'playReverse',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        'void setHook(const std::string &label, @nullable @local std::function<void ()> callback)'
    },
    TAG_MAKER = '("hook." + #1)',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        'void clearHooks()'
    },
    TAG_MAKER = '("hook.")',
    TAG_MODE = 'OLUA_TAG_SUBSTARTWITH',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.props [[
    owner
    playing
    timeScale
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::UIConfig'
cls.funcs [[
    static void registerFont(const std::string &aliasName, const std::string &realName)
    static const std::string &getRealFontName(const std::string &aliasName, @out bool *isTTF)
]]
cls.var('defaultFont', [[static std::string defaultFont]])
cls.var('buttonSound', [[static std::string buttonSound]])
cls.var('buttonSoundVolumeScale', [[static float buttonSoundVolumeScale]])
cls.var('defaultScrollStep', [[static int defaultScrollStep]])
cls.var('defaultScrollDecelerationRate', [[static float defaultScrollDecelerationRate]])
cls.var('defaultScrollTouchEffect', [[static bool defaultScrollTouchEffect]])
cls.var('defaultScrollBounceEffect', [[static bool defaultScrollBounceEffect]])
cls.var('defaultScrollBarDisplay', [[static fairygui::ScrollBarDisplayType defaultScrollBarDisplay]])
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
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::IUISource'
cls.SUPERCLS = "cocos2d::Ref"
cls.funcs [[
    const std::string &getFileName()
    void setFileName(const std::string &value)
    bool isLoaded()
]]
cls.callback {
    FUNCS =  {
        'void load(@nullable @local std::function<void ()> callback)'
    },
    TAG_MAKER = 'load',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.props [[
    fileName
    loaded
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::UISource'
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

    bool _loaded;
    std::function<void()> _complete;
    std::string _name;
};
NS_FGUI_END
]]
cls.funcs [[
]]
cls.func('create', [[static UISource *create()]])
cls.func('loadComplete', [[void loadComplete()]])
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::Window'
cls.SUPERCLS = "fairygui::GComponent"
cls.funcs [[
    Window()
    static fairygui::Window *create()
    @delref(children ~ parent)@addref(children | parent) void show()
    @delref(children ~ parent) void hide()
    @delref(children ~ parent) void hideImmediately()
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
    void addUISource(fairygui::IUISource *uiSource)
    bool isBringToFrontOnClick()
    void setBringToFrontOnClick(bool value)
    @addref(contentPane ^) fairygui::GComponent *getContentPane()
    void setContentPane(@addref(contentPane ^) fairygui::GComponent *value)
    @addref(frame ^) fairygui::GComponent *getFrame()
    @addref(closeButton ^) fairygui::GObject *getCloseButton()
    void setCloseButton(@addref(closeButton ^) fairygui::GObject *value)
    @addref(dragArea ^) fairygui::GObject *getDragArea()
    void setDragArea(@addref(dragArea ^) fairygui::GObject *value)
    @addref(contentArea ^) fairygui::GObject *getContentArea()
    void setContentArea(@addref(contentArea ^) fairygui::GObject *value)
    @addref(modalWaitingPane ^) fairygui::GObject *getModalWaitingPane()
]]
cls.inject('show', {
    BEFORE = [[
        fairygui::GComponent *root = fairygui::UIRoot;
        if (!root) {
            luaL_error(L, "no root to add 'Window'");
        }
        olua_push_cppobj<fairygui::GComponent>(L, root);
        int parent = lua_gettop(L);
    ]],
})
cls.inject('hide', {
    BEFORE = [[
        fairygui::GComponent *root = self->getParent() ? self->getParent() : fairygui::UIRoot;
        if (!root) {
            return 0;
        }
        olua_push_cppobj<fairygui::GComponent>(L, root);
        int parent = lua_gettop(L);
    ]],
})
cls.inject('hideImmediately', {
    BEFORE = [[
        fairygui::GComponent *root = self->getParent() ? self->getParent() : fairygui::UIRoot;
        if (!root) {
            return 0;
        }
        olua_push_cppobj<fairygui::GComponent>(L, root);
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
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::DragDropManager'
cls.funcs [[
    DragDropManager()
    static fairygui::DragDropManager *getInstance()
    fairygui::GLoader *getAgent()
    bool isDragging()
    void startDrag(const std::string &icon, @optional const cocos2d::Value &sourceData, @optional int touchPointID)
    void cancel()
]]
cls.props [[
    instance
    agent
    dragging
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::UIObjectFactory'
cls.funcs [[
    static fairygui::GObject *newObject(fairygui::PackageItem *pi)
    static fairygui::GObject *newObject(fairygui::ObjectType type)
]]
cls.callback {
    FUNCS =  {
        'static void setPackageItemExtension(const std::string &url, @local std::function<GComponent *()> creator)'
    },
    TAG_MAKER = 'PackageItemExtension',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        'static void setLoaderExtension(@local std::function<GLoader *()> creator)'
    },
    TAG_MAKER = 'LoaderExtension',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::GearBase'
cls.funcs [[
    GearBase(fairygui::GObject *owner)
    static fairygui::GearBase *create(fairygui::GObject *owner, int index)
]]
cls.var('disableAllTweenEffect', [[static bool disableAllTweenEffect]])
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::GTreeNode'
cls.SUPERCLS = "cocos2d::Ref"
cls.funcs [[
    static fairygui::GTreeNode *create(@optional bool isFolder, @optional const std::string &resURL)
    GTreeNode()
    fairygui::GTreeNode *getParent()
    fairygui::GTree *getTree()
    @addref(cell ^) fairygui::GComponent *getCell()
    const cocos2d::Value &getData()
    void setData(const cocos2d::Value &value)
    bool isExpanded()
    void setExpaned(bool value)
    bool isFolder()
    const std::string &getText()
    void setText(const std::string &value)
    const std::string &getIcon()
    void setIcon(const std::string &value)
    fairygui::GTreeNode *addChild(@addref(children |) fairygui::GTreeNode *child)
    fairygui::GTreeNode *addChildAt(@addref(children |) fairygui::GTreeNode *child, int index)
    void removeChild(@delref(children |) fairygui::GTreeNode *child)
    @delref(children ~) void removeChildAt(int index)
    @delref(children ~) void removeChildren()
    @delref(children ~) void removeChildren(int beginIndex, int endIndex)
    @addref(children |) fairygui::GTreeNode *getChildAt(int index)
    @addref(children |) fairygui::GTreeNode *getPrevSibling()
    @addref(children |) fairygui::GTreeNode *getNextSibling()
    int getChildIndex(const fairygui::GTreeNode *child)
    void setChildIndex(fairygui::GTreeNode *child, int index)
    int setChildIndexBefore(fairygui::GTreeNode *child, int index)
    void swapChildren(fairygui::GTreeNode *child1, fairygui::GTreeNode *child2)
    void swapChildrenAt(int index1, int index2)
    int numChildren()
]]
cls.prop('numChildren', 'int numChildren()')
cls.props [[
    parent
    tree
    cell
    data
    expanded
    folder
    text
    icon
    prevSibling
    nextSibling
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::GTree'
cls.SUPERCLS = "fairygui::GList"
cls.funcs [[
    GTree()
    static fairygui::GTree *create()
    int getIndent()
    void setIndent(int value)
    int getClickToExpand()
    void setClickToExpand(int value)
    @addref(rootNode ^) fairygui::GTreeNode *getRootNode()
    fairygui::GTreeNode *getSelectedNode()
    void getSelectedNodes(@out std::vector<GTreeNode *> &result)
    void selectNode(fairygui::GTreeNode *node, @optional bool scrollItToView)
    void unselectNode(fairygui::GTreeNode *node)
    void expandAll(fairygui::GTreeNode *folderNode)
    void collapseAll(fairygui::GTreeNode *folderNode)
]]
cls.var('treeNodeRender', [[@nullable std::function<void (GTreeNode *, GComponent *)> treeNodeRender]])
cls.var('treeNodeWillExpand', [[@nullable std::function<void (GTreeNode *, bool)> treeNodeWillExpand]])
cls.props [[
    indent
    clickToExpand
    rootNode
    selectedNode
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::FUIContainer'
cls.SUPERCLS = "cocos2d::Node"
cls.funcs [[
    FUIContainer()
    static fairygui::FUIContainer *create()
    bool isClippingEnabled()
    void setClippingEnabled(bool value)
    const cocos2d::Rect &getClippingRegion()
    void setClippingRegion(const cocos2d::Rect &clippingRegion)
    cocos2d::Node *getStencil()
    void setStencil(cocos2d::Node *stencil)
    float getAlphaThreshold()
    void setAlphaThreshold(float alphaThreshold)
    bool isInverted()
    void setInverted(bool inverted)
]]
cls.var('gOwner', [[fairygui::GObject *gOwner]])
cls.props [[
    clippingEnabled
    clippingRegion
    stencil
    alphaThreshold
    inverted
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::FUIInput'
cls.SUPERCLS = "cocos2d::ui::EditBox"
cls.funcs [[
    static fairygui::FUIInput *create()
    FUIInput()
    void setText(const std::string &value)
    fairygui::TextFormat *getTextFormat()
    void applyTextFormat()
    bool isSingleLine()
    void setSingleLine(bool value)
    bool isPassword()
    void setPassword(bool value)
    int keyboardType()
    void setKeyboardType(int value)
]]
cls.props [[
    textFormat
    singleLine
    password
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::FUILabel'
cls.SUPERCLS = "cocos2d::Label"
cls.funcs [[
    FUILabel()
    static fairygui::FUILabel *create()
    const std::string &getText()
    void setText(const std::string &value)
    fairygui::TextFormat *getTextFormat()
    void applyTextFormat()
    void setGrayed(bool value)
]]
cls.props [[
    text
    textFormat
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::FUIRichText'
cls.SUPERCLS = "cocos2d::Node"
cls.funcs [[
    FUIRichText()
    static fairygui::FUIRichText *create()
    const cocos2d::Size &getDimensions()
    void setDimensions(float width, float height)
    void setText(const std::string &value)
    fairygui::TextFormat *getTextFormat()
    void applyTextFormat()
    cocos2d::Label::Overflow getOverflow()
    void setOverflow(cocos2d::Label::Overflow overflow)
    bool isAnchorTextUnderline()
    void setAnchorTextUnderline(bool enable)
    const cocos2d::Color3B &getAnchorFontColor()
    void setAnchorFontColor(const cocos2d::Color3B &color)
    const char *hitTestLink(const cocos2d::Vec2 &worldPoint)
]]
cls.props [[
    dimensions
    textFormat
    overflow
    anchorTextUnderline
    anchorFontColor
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::FUISprite'
cls.SUPERCLS = "cocos2d::Sprite"
cls.funcs [[
    FUISprite()
    static fairygui::FUISprite *create()
    void clearContent()
    void setGrayed(bool value)
    fairygui::FillMethod getFillMethod()
    void setFillMethod(fairygui::FillMethod value)
    fairygui::FillOrigin getFillOrigin()
    void setFillOrigin(fairygui::FillOrigin value)
    bool isFillClockwise()
    void setFillClockwise(bool value)
    float getFillAmount()
    void setFillAmount(float value)
    bool isScaleByTile()
    void setScaleByTile(bool value)
]]
cls.props [[
    fillMethod
    fillOrigin
    fillClockwise
    fillAmount
    scaleByTile
]]
M.CLASSES[#M.CLASSES + 1] = cls

return M
