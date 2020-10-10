-- AUTO BUILD, DON'T MODIFY!

dofile "autobuild/fairygui-types.lua"

local olua = require "olua"
local typeconv = olua.typeconv
local typecls = olua.typecls
local cls = nil
local M = {}

M.NAME = "fairygui"
M.PATH = "../../frameworks/libxgame/src/lua-bindings"
M.INCLUDES = [[
    #include "lua-bindings/lua_conv.h"
    #include "lua-bindings/lua_conv_manual.h"
    #include "xgame/xlua.h"
    #include "FairyGUI.h"
    #include "GLoader3D.h"
    #include "tween/EaseManager.h"
    #include "tween/GPath.h"
    #include "display/FUISprite.h"
    #include "utils/html/HtmlElement.h"
    #include "utils/html/HtmlObject.h"
    #include "utils/html/HtmlParser.h"
]]
M.CHUNK = [[
    bool manual_olua_is_fairygui_EventTag(lua_State *L, int idx)
    {
        return olua_isinteger(L, idx) || olua_isa<void>(L, idx);
    }

    void manual_olua_check_fairygui_EventTag(lua_State *L, int idx, fairygui::EventTag *value)
    {
        if (!value) {
            luaL_error(L, "value is NULL");
        }
        if (olua_isinteger(L, idx)) {
            *value = (int)olua_tointeger(L, idx);
        } else {
            *value = olua_checkobj<void>(L, idx);
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
        CPPCLS = 'fairygui::HtmlParseOptions',
        DEF = [[
            static bool defaultLinkUnderline;
            static cocos2d::Color3B defaultLinkColor;
            bool linkUnderline;
            cocos2d::Color3B linkColor;
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
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
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
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::UIEventDispatcher'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = [[
    static std::string makeListenerTag(lua_State *L, lua_Integer type, int tagidx)
    {
        char buf[64];
        intptr_t tag = 0;
        if (tagidx > 0) {
            if (olua_isinteger(L, tagidx)) {
                tag = (intptr_t)olua_tointeger(L, tagidx);
            } else {
                tag = (intptr_t)olua_checkobj<void>(L, tagidx);
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
cls.func(nil, 'UIEventDispatcher()')
cls.func(nil, 'bool hasEventListener(int eventType)', 'bool hasEventListener(int eventType, const fairygui::EventTag &tag)')
cls.func(nil, 'bool dispatchEvent(int eventType, @optional void *data, @optional const cocos2d::Value &dataValue)')
cls.func(nil, 'bool bubbleEvent(int eventType, @optional void *data, @optional const cocos2d::Value &dataValue)')
cls.func(nil, 'bool isDispatchingEvent(int eventType)')
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
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'EventContext()')
cls.func(nil, 'int getType()')
cls.func(nil, 'cocos2d::Ref *getSender()')
cls.func(nil, 'fairygui::InputEvent *getInput()')
cls.func(nil, 'void stopPropagation()')
cls.func(nil, 'void preventDefault()')
cls.func(nil, 'bool isDefaultPrevented()')
cls.func(nil, 'void captureTouch()')
cls.func(nil, 'void uncaptureTouch()')
cls.func(nil, 'const cocos2d::Value &getDataValue()')
cls.func(nil, 'void *getData()')
cls.prop('type', nil, nil)
cls.prop('sender', nil, nil)
cls.prop('input', nil, nil)
cls.prop('defaultPrevented', nil, nil)
cls.prop('dataValue', nil, nil)
cls.prop('data', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::IHitTest'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'bool hitTest(fairygui::GComponent *obj, const cocos2d::Vec2 &localPoint)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::PixelHitTest'
cls.SUPERCLS = 'fairygui::IHitTest'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'PixelHitTest(fairygui::PixelHitTestData *data, int offsetX, int offsetY)')
cls.var('offsetX', 'int offsetX')
cls.var('offsetY', 'int offsetY')
cls.var('scaleX', 'float scaleX')
cls.var('scaleY', 'float scaleY')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::PixelHitTestData'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'PixelHitTestData()')
cls.var('pixelWidth', 'int pixelWidth')
cls.var('scale', 'float scale')
cls.var('pixels', 'unsigned char *pixels')
cls.var('pixelsLength', 'size_t pixelsLength')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::InputProcessor'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'fairygui::InputEvent *getRecentInput()')
cls.func(nil, 'static bool isTouchOnUI()')
cls.func(nil, 'InputProcessor(fairygui::GComponent *owner)')
cls.func(nil, 'cocos2d::Vec2 getTouchPosition(int touchId)')
cls.func(nil, 'void addTouchMonitor(int touchId, fairygui::GObject *target)')
cls.func(nil, 'void removeTouchMonitor(fairygui::GObject *target)')
cls.func(nil, 'void cancelClick(int touchId)')
cls.func(nil, 'void simulateClick(fairygui::GObject *target, @optional int touchId)')
cls.func(nil, 'void disableDefaultTouchEvent()')
cls.func(nil, 'bool touchDown(cocos2d::Touch *touch, cocos2d::Event *event)')
cls.func(nil, 'void touchMove(cocos2d::Touch *touch, cocos2d::Event *event)')
cls.func(nil, 'void touchUp(cocos2d::Touch *touch, cocos2d::Event *event)')
cls.callback {
    FUNCS =  {
        'void setCaptureCallback(@nullable @local std::function<void (int)> value)'
    },
    TAG_MAKER = 'CaptureCallback',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.prop('recentInput', nil, nil)
cls.prop('touchOnUI', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::InputEvent'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'InputEvent()')
cls.func(nil, 'fairygui::GObject *getTarget()')
cls.func(nil, 'const int getX()')
cls.func(nil, 'const int getY()')
cls.func(nil, 'const cocos2d::Vec2 &getPosition()')
cls.func(nil, 'cocos2d::Touch *getTouch()')
cls.func(nil, 'int getTouchId()')
cls.func(nil, 'int isDoubleClick()')
cls.func(nil, 'cocos2d::EventMouse::MouseButton getButton()')
cls.func(nil, 'cocos2d::EventKeyboard::KeyCode getKeyCode()')
cls.func(nil, 'bool isCtrlDown()')
cls.func(nil, 'bool isAltDown()')
cls.func(nil, 'bool isShiftDown()')
cls.func(nil, 'int getMouseWheelDelta()')
cls.func(nil, 'fairygui::InputProcessor *getProcessor()')
cls.prop('target', nil, nil)
cls.prop('x', nil, nil)
cls.prop('y', nil, nil)
cls.prop('position', nil, nil)
cls.prop('touch', nil, nil)
cls.prop('touchId', nil, nil)
cls.prop('doubleClick', nil, nil)
cls.prop('button', nil, nil)
cls.prop('keyCode', nil, nil)
cls.prop('ctrlDown', nil, nil)
cls.prop('altDown', nil, nil)
cls.prop('shiftDown', nil, nil)
cls.prop('mouseWheelDelta', nil, nil)
cls.prop('processor', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::TextFormat'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.const('OUTLINE', 'fairygui::TextFormat::OUTLINE', 'const int')
cls.const('SHADOW', 'fairygui::TextFormat::SHADOW', 'const int')
cls.const('GLOW', 'fairygui::TextFormat::GLOW', 'const int')
cls.func(nil, 'TextFormat()')
cls.func(nil, 'void setFormat(const fairygui::TextFormat &format)')
cls.func(nil, 'void enableEffect(int effectFlag)')
cls.func(nil, 'void disableEffect(int effectFlag)')
cls.func(nil, 'bool hasEffect(int effectFlag)')
cls.var('face', 'std::string face')
cls.var('fontSize', 'float fontSize')
cls.var('color', 'cocos2d::Color3B color')
cls.var('bold', 'bool bold')
cls.var('italics', 'bool italics')
cls.var('underline', 'bool underline')
cls.var('lineSpacing', 'int lineSpacing')
cls.var('letterSpacing', 'int letterSpacing')
cls.var('align', 'cocos2d::TextHAlignment align')
cls.var('verticalAlign', 'cocos2d::TextVAlignment verticalAlign')
cls.var('effect', 'int effect')
cls.var('outlineColor', 'cocos2d::Color3B outlineColor')
cls.var('outlineSize', 'int outlineSize')
cls.var('shadowColor', 'cocos2d::Color3B shadowColor')
cls.var('shadowOffset', 'cocos2d::Size shadowOffset')
cls.var('shadowBlurRadius', 'int shadowBlurRadius')
cls.var('glowColor', 'cocos2d::Color3B glowColor')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::EaseType'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('Linear', 'fairygui::EaseType::Linear')
cls.enum('SineIn', 'fairygui::EaseType::SineIn')
cls.enum('SineOut', 'fairygui::EaseType::SineOut')
cls.enum('SineInOut', 'fairygui::EaseType::SineInOut')
cls.enum('QuadIn', 'fairygui::EaseType::QuadIn')
cls.enum('QuadOut', 'fairygui::EaseType::QuadOut')
cls.enum('QuadInOut', 'fairygui::EaseType::QuadInOut')
cls.enum('CubicIn', 'fairygui::EaseType::CubicIn')
cls.enum('CubicOut', 'fairygui::EaseType::CubicOut')
cls.enum('CubicInOut', 'fairygui::EaseType::CubicInOut')
cls.enum('QuartIn', 'fairygui::EaseType::QuartIn')
cls.enum('QuartOut', 'fairygui::EaseType::QuartOut')
cls.enum('QuartInOut', 'fairygui::EaseType::QuartInOut')
cls.enum('QuintIn', 'fairygui::EaseType::QuintIn')
cls.enum('QuintOut', 'fairygui::EaseType::QuintOut')
cls.enum('QuintInOut', 'fairygui::EaseType::QuintInOut')
cls.enum('ExpoIn', 'fairygui::EaseType::ExpoIn')
cls.enum('ExpoOut', 'fairygui::EaseType::ExpoOut')
cls.enum('ExpoInOut', 'fairygui::EaseType::ExpoInOut')
cls.enum('CircIn', 'fairygui::EaseType::CircIn')
cls.enum('CircOut', 'fairygui::EaseType::CircOut')
cls.enum('CircInOut', 'fairygui::EaseType::CircInOut')
cls.enum('ElasticIn', 'fairygui::EaseType::ElasticIn')
cls.enum('ElasticOut', 'fairygui::EaseType::ElasticOut')
cls.enum('ElasticInOut', 'fairygui::EaseType::ElasticInOut')
cls.enum('BackIn', 'fairygui::EaseType::BackIn')
cls.enum('BackOut', 'fairygui::EaseType::BackOut')
cls.enum('BackInOut', 'fairygui::EaseType::BackInOut')
cls.enum('BounceIn', 'fairygui::EaseType::BounceIn')
cls.enum('BounceOut', 'fairygui::EaseType::BounceOut')
cls.enum('BounceInOut', 'fairygui::EaseType::BounceInOut')
cls.enum('Custom', 'fairygui::EaseType::Custom')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::EaseManager'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static float evaluate(fairygui::EaseType easeType, float time, float duration, float overshootOrAmplitude, float period)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::TweenPropType'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('None', 'fairygui::TweenPropType::None')
cls.enum('X', 'fairygui::TweenPropType::X')
cls.enum('Y', 'fairygui::TweenPropType::Y')
cls.enum('Position', 'fairygui::TweenPropType::Position')
cls.enum('Width', 'fairygui::TweenPropType::Width')
cls.enum('Height', 'fairygui::TweenPropType::Height')
cls.enum('Size', 'fairygui::TweenPropType::Size')
cls.enum('ScaleX', 'fairygui::TweenPropType::ScaleX')
cls.enum('ScaleY', 'fairygui::TweenPropType::ScaleY')
cls.enum('Scale', 'fairygui::TweenPropType::Scale')
cls.enum('Rotation', 'fairygui::TweenPropType::Rotation')
cls.enum('Alpha', 'fairygui::TweenPropType::Alpha')
cls.enum('Progress', 'fairygui::TweenPropType::Progress')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::GPath'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::GTweener'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'GTweener()')
cls.func(nil, 'fairygui::GTweener *setDelay(float value)')
cls.func(nil, 'float getDelay()')
cls.func(nil, 'fairygui::GTweener *setDuration(float value)')
cls.func(nil, 'float getDuration()')
cls.func(nil, 'fairygui::GTweener *setBreakpoint(float value)')
cls.func(nil, 'fairygui::GTweener *setEase(fairygui::EaseType value)')
cls.func(nil, 'fairygui::GTweener *setEasePeriod(float value)')
cls.func(nil, 'fairygui::GTweener *setEaseOvershootOrAmplitude(float value)')
cls.func(nil, 'fairygui::GTweener *setRepeat(int repeat, @optional bool yoyo)')
cls.func(nil, 'int getRepeat()')
cls.func(nil, 'fairygui::GTweener *setTimeScale(float value)')
cls.func(nil, 'fairygui::GTweener *setSnapping(bool value)')
cls.func(nil, 'fairygui::GTweener *setTargetAny(void *value)')
cls.func(nil, 'fairygui::GTweener *setTarget(cocos2d::Ref *target)', 'fairygui::GTweener *setTarget(cocos2d::Ref *target, fairygui::TweenPropType propType)')
cls.func(nil, 'void *getTarget()')
cls.func(nil, 'fairygui::GTweener *setUserData(const cocos2d::Value &value)')
cls.func(nil, 'fairygui::GTweener *setPath(fairygui::GPath *path)')
cls.func(nil, 'const cocos2d::Value &getUserData()')
cls.func(nil, 'float getNormalizedTime()')
cls.func(nil, 'bool isCompleted()')
cls.func(nil, 'bool allCompleted()')
cls.func(nil, 'fairygui::GTweener *setPaused(bool paused)')
cls.func(nil, 'void seek(float time)')
cls.func(nil, 'void kill(@optional bool complete)')
cls.var('startValue', 'fairygui::TweenValue startValue')
cls.var('endValue', 'fairygui::TweenValue endValue')
cls.var('value', 'fairygui::TweenValue value')
cls.var('deltaValue', 'fairygui::TweenValue deltaValue')
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
cls.prop('delay', nil, nil)
cls.prop('duration', nil, nil)
cls.prop('repeat', nil, nil)
cls.prop('target', nil, nil)
cls.prop('userData', nil, nil)
cls.prop('normalizedTime', nil, nil)
cls.prop('completed', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::GTween'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = [[
    static bool should_del_tweener_ref(lua_State *L, int idx)
    {
        if (olua_isa<fairygui::GTweener>(L, idx)) {
            fairygui::GTweener *obj = olua_toobj<fairygui::GTweener>(L, idx);
            if (obj->getReferenceCount() == 1 || obj->allCompleted()) {
                return true;
            }
        }
        return false;
    }
]]
cls.func(nil, 'static fairygui::GTweener *to(float startValue, float endValue, float duration)', 'static fairygui::GTweener *to(const cocos2d::Vec2 &startValue, const cocos2d::Vec2 &endValue, float duration)', 'static fairygui::GTweener *to(const cocos2d::Vec3 &startValue, const cocos2d::Vec3 &endValue, float duration)', 'static fairygui::GTweener *to(const cocos2d::Vec4 &startValue, const cocos2d::Vec4 &endValue, float duration)', 'static fairygui::GTweener *to(const cocos2d::Color4B &startValue, const cocos2d::Color4B &endValue, float duration)')
cls.func(nil, 'static fairygui::GTweener *toColor(const cocos2d::Color4B &startValue, const cocos2d::Color4B &endValue, float duration)')
cls.func(nil, 'static fairygui::GTweener *toDouble(double startValue, double endValue, float duration)')
cls.func(nil, 'static fairygui::GTweener *delayedCall(float delay)')
cls.func(nil, 'static fairygui::GTweener *shake(const cocos2d::Vec2 &startValue, float amplitude, float duration)')
cls.func(nil, 'static bool isTweening(cocos2d::Ref *target)', 'static bool isTweening(cocos2d::Ref *target, fairygui::TweenPropType propType)')
cls.func(nil, 'static void kill(cocos2d::Ref *target)', 'static void kill(cocos2d::Ref *target, bool complete)', 'static void kill(cocos2d::Ref *target, fairygui::TweenPropType propType, bool complete)')
cls.func(nil, 'static fairygui::GTweener *getTween(cocos2d::Ref *target)', 'static fairygui::GTweener *getTween(cocos2d::Ref *target, fairygui::TweenPropType propType)')
cls.func(nil, 'static void clean()')
cls.insert('to', {
    BEFORE = nil,
    AFTER = [[
        olua_pushclassobj<fairygui::GTween>(L);
        olua_addref(L, -1, "tweeners", -2, OLUA_MODE_MULTIPLE);
        olua_visitrefs(L, -1, "tweeners", should_del_tweener_ref);
        lua_pop(L, 1);
    ]],
    CALLBACK_BEFORE = nil,
    CALLBACK_AFTER = nil,
})
cls.insert('toColor', {
    BEFORE = nil,
    AFTER = [[
        olua_pushclassobj<fairygui::GTween>(L);
        olua_addref(L, -1, "tweeners", -2, OLUA_MODE_MULTIPLE);
        olua_visitrefs(L, -1, "tweeners", should_del_tweener_ref);
        lua_pop(L, 1);
    ]],
    CALLBACK_BEFORE = nil,
    CALLBACK_AFTER = nil,
})
cls.insert('toDouble', {
    BEFORE = nil,
    AFTER = [[
        olua_pushclassobj<fairygui::GTween>(L);
        olua_addref(L, -1, "tweeners", -2, OLUA_MODE_MULTIPLE);
        olua_visitrefs(L, -1, "tweeners", should_del_tweener_ref);
        lua_pop(L, 1);
    ]],
    CALLBACK_BEFORE = nil,
    CALLBACK_AFTER = nil,
})
cls.insert('delayedCall', {
    BEFORE = nil,
    AFTER = [[
        olua_pushclassobj<fairygui::GTween>(L);
        olua_addref(L, -1, "tweeners", -2, OLUA_MODE_MULTIPLE);
        olua_visitrefs(L, -1, "tweeners", should_del_tweener_ref);
        lua_pop(L, 1);
    ]],
    CALLBACK_BEFORE = nil,
    CALLBACK_AFTER = nil,
})
cls.insert('shake', {
    BEFORE = nil,
    AFTER = [[
        olua_pushclassobj<fairygui::GTween>(L);
        olua_addref(L, -1, "tweeners", -2, OLUA_MODE_MULTIPLE);
        olua_visitrefs(L, -1, "tweeners", should_del_tweener_ref);
        lua_pop(L, 1);
    ]],
    CALLBACK_BEFORE = nil,
    CALLBACK_AFTER = nil,
})
cls.insert('kill', {
    BEFORE = nil,
    AFTER = [[
        olua_pushclassobj<fairygui::GTween>(L);
        olua_visitrefs(L, -1, "tweeners", should_del_tweener_ref);
        lua_pop(L, 1);
    ]],
    CALLBACK_BEFORE = nil,
    CALLBACK_AFTER = nil,
})
cls.insert('clean', {
    BEFORE = nil,
    AFTER = [[
        olua_pushclassobj<fairygui::GTween>(L);
        olua_delallrefs(L, -1, "tweeners");
        lua_pop(L, 1);
    ]],
    CALLBACK_BEFORE = nil,
    CALLBACK_AFTER = nil,
})
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::UIPackage'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.const('URL_PREFIX', 'fairygui::UIPackage::URL_PREFIX', 'const std::string')
cls.func(nil, 'UIPackage()')
cls.func(nil, 'static fairygui::UIPackage *getById(const std::string &id)')
cls.func(nil, 'static fairygui::UIPackage *getByName(const std::string &name)')
cls.func(nil, 'static fairygui::UIPackage *addPackage(const std::string &descFilePath)')
cls.func(nil, 'static void removePackage(const std::string &packageIdOrName)')
cls.func(nil, 'static void removeAllPackages()')
cls.func(nil, 'static fairygui::GObject *createObject(const std::string &pkgName, const std::string &resName)')
cls.func(nil, 'static fairygui::GObject *createObjectFromURL(const std::string &url)')
cls.func(nil, 'static std::string getItemURL(const std::string &pkgName, const std::string &resName)')
cls.func(nil, 'static fairygui::PackageItem *getItemByURL(const std::string &url)')
cls.func(nil, 'static std::string normalizeURL(const std::string &url)')
cls.func(nil, 'static void *getItemAsset(const std::string &pkgName, const std::string &resName, @optional fairygui::PackageItemType type)', 'void *getItemAsset(fairygui::PackageItem *item)')
cls.func(nil, 'static void *getItemAssetByURL(const std::string &url, @optional fairygui::PackageItemType type)')
cls.func(nil, 'static cocos2d::Texture2D *getEmptyTexture()')
cls.func(nil, 'const std::string &getId()')
cls.func(nil, 'const std::string &getName()')
cls.func(nil, 'fairygui::PackageItem *getItem(const std::string &itemId)')
cls.func(nil, 'fairygui::PackageItem *getItemByName(const std::string &itemName)')
cls.func(nil, 'static const std::string &getBranch()')
cls.func(nil, 'static void setBranch(const std::string &value)')
cls.func(nil, 'static const std::string &getVar(const std::string &key)')
cls.func(nil, 'static void setVar(const std::string &key, const std::string &value)')
cls.prop('emptyTexture', nil, nil)
cls.prop('id', nil, nil)
cls.prop('name', nil, nil)
cls.prop('branch', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::PackageItem'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'PackageItem()')
cls.func(nil, 'void load()')
cls.func(nil, 'fairygui::PackageItem *getBranch()')
cls.func(nil, 'fairygui::PackageItem *getHighResolution()')
cls.var('owner', 'fairygui::UIPackage *owner')
cls.var('type', 'fairygui::PackageItemType type')
cls.var('objectType', 'fairygui::ObjectType objectType')
cls.var('id', 'std::string id')
cls.var('name', 'std::string name')
cls.var('width', 'int width')
cls.var('height', 'int height')
cls.var('file', 'std::string file')
cls.var('texture', 'cocos2d::Texture2D *texture')
cls.var('scaleByTile', 'bool scaleByTile')
cls.var('tileGridIndice', 'int tileGridIndice')
cls.var('spriteFrame', 'cocos2d::SpriteFrame *spriteFrame')
cls.var('animation', 'cocos2d::Animation *animation')
cls.var('delayPerUnit', 'float delayPerUnit')
cls.var('repeatDelay', 'float repeatDelay')
cls.var('swing', 'bool swing')
cls.var('translated', 'bool translated')
cls.prop('branch', nil, nil)
cls.prop('highResolution', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::PackageItemType'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('IMAGE', 'fairygui::PackageItemType::IMAGE')
cls.enum('MOVIECLIP', 'fairygui::PackageItemType::MOVIECLIP')
cls.enum('SOUND', 'fairygui::PackageItemType::SOUND')
cls.enum('COMPONENT', 'fairygui::PackageItemType::COMPONENT')
cls.enum('ATLAS', 'fairygui::PackageItemType::ATLAS')
cls.enum('FONT', 'fairygui::PackageItemType::FONT')
cls.enum('SWF', 'fairygui::PackageItemType::SWF')
cls.enum('MISC', 'fairygui::PackageItemType::MISC')
cls.enum('UNKNOWN', 'fairygui::PackageItemType::UNKNOWN')
cls.enum('SPINE', 'fairygui::PackageItemType::SPINE')
cls.enum('DRAGONBONES', 'fairygui::PackageItemType::DRAGONBONES')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::ObjectType'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('IMAGE', 'fairygui::ObjectType::IMAGE')
cls.enum('MOVIECLIP', 'fairygui::ObjectType::MOVIECLIP')
cls.enum('SWF', 'fairygui::ObjectType::SWF')
cls.enum('GRAPH', 'fairygui::ObjectType::GRAPH')
cls.enum('LOADER', 'fairygui::ObjectType::LOADER')
cls.enum('GROUP', 'fairygui::ObjectType::GROUP')
cls.enum('TEXT', 'fairygui::ObjectType::TEXT')
cls.enum('RICHTEXT', 'fairygui::ObjectType::RICHTEXT')
cls.enum('INPUTTEXT', 'fairygui::ObjectType::INPUTTEXT')
cls.enum('COMPONENT', 'fairygui::ObjectType::COMPONENT')
cls.enum('LIST', 'fairygui::ObjectType::LIST')
cls.enum('LABEL', 'fairygui::ObjectType::LABEL')
cls.enum('BUTTON', 'fairygui::ObjectType::BUTTON')
cls.enum('COMBOBOX', 'fairygui::ObjectType::COMBOBOX')
cls.enum('PROGRESSBAR', 'fairygui::ObjectType::PROGRESSBAR')
cls.enum('SLIDER', 'fairygui::ObjectType::SLIDER')
cls.enum('SCROLLBAR', 'fairygui::ObjectType::SCROLLBAR')
cls.enum('TREE', 'fairygui::ObjectType::TREE')
cls.enum('LOADER3D', 'fairygui::ObjectType::LOADER3D')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::ButtonMode'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('COMMON', 'fairygui::ButtonMode::COMMON')
cls.enum('CHECK', 'fairygui::ButtonMode::CHECK')
cls.enum('RADIO', 'fairygui::ButtonMode::RADIO')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::ChildrenRenderOrder'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('ASCENT', 'fairygui::ChildrenRenderOrder::ASCENT')
cls.enum('DESCENT', 'fairygui::ChildrenRenderOrder::DESCENT')
cls.enum('ARCH', 'fairygui::ChildrenRenderOrder::ARCH')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::OverflowType'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('VISIBLE', 'fairygui::OverflowType::VISIBLE')
cls.enum('HIDDEN', 'fairygui::OverflowType::HIDDEN')
cls.enum('SCROLL', 'fairygui::OverflowType::SCROLL')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::ScrollType'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('HORIZONTAL', 'fairygui::ScrollType::HORIZONTAL')
cls.enum('VERTICAL', 'fairygui::ScrollType::VERTICAL')
cls.enum('BOTH', 'fairygui::ScrollType::BOTH')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::ScrollBarDisplayType'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('DEFAULT', 'fairygui::ScrollBarDisplayType::DEFAULT')
cls.enum('VISIBLE', 'fairygui::ScrollBarDisplayType::VISIBLE')
cls.enum('AUTO', 'fairygui::ScrollBarDisplayType::AUTO')
cls.enum('HIDDEN', 'fairygui::ScrollBarDisplayType::HIDDEN')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::LoaderFillType'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('NONE', 'fairygui::LoaderFillType::NONE')
cls.enum('SCALE', 'fairygui::LoaderFillType::SCALE')
cls.enum('SCALE_MATCH_HEIGHT', 'fairygui::LoaderFillType::SCALE_MATCH_HEIGHT')
cls.enum('SCALE_MATCH_WIDTH', 'fairygui::LoaderFillType::SCALE_MATCH_WIDTH')
cls.enum('SCALE_FREE', 'fairygui::LoaderFillType::SCALE_FREE')
cls.enum('SCALE_NO_BORDER', 'fairygui::LoaderFillType::SCALE_NO_BORDER')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::ProgressTitleType'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('PERCENT', 'fairygui::ProgressTitleType::PERCENT')
cls.enum('VALUE_MAX', 'fairygui::ProgressTitleType::VALUE_MAX')
cls.enum('VALUE', 'fairygui::ProgressTitleType::VALUE')
cls.enum('MAX', 'fairygui::ProgressTitleType::MAX')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::ListLayoutType'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('SINGLE_COLUMN', 'fairygui::ListLayoutType::SINGLE_COLUMN')
cls.enum('SINGLE_ROW', 'fairygui::ListLayoutType::SINGLE_ROW')
cls.enum('FLOW_HORIZONTAL', 'fairygui::ListLayoutType::FLOW_HORIZONTAL')
cls.enum('FLOW_VERTICAL', 'fairygui::ListLayoutType::FLOW_VERTICAL')
cls.enum('PAGINATION', 'fairygui::ListLayoutType::PAGINATION')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::ListSelectionMode'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('SINGLE', 'fairygui::ListSelectionMode::SINGLE')
cls.enum('MULTIPLE', 'fairygui::ListSelectionMode::MULTIPLE')
cls.enum('MULTIPLE_SINGLECLICK', 'fairygui::ListSelectionMode::MULTIPLE_SINGLECLICK')
cls.enum('NONE', 'fairygui::ListSelectionMode::NONE')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::GroupLayoutType'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('NONE', 'fairygui::GroupLayoutType::NONE')
cls.enum('HORIZONTAL', 'fairygui::GroupLayoutType::HORIZONTAL')
cls.enum('VERTICAL', 'fairygui::GroupLayoutType::VERTICAL')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::PopupDirection'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('AUTO', 'fairygui::PopupDirection::AUTO')
cls.enum('UP', 'fairygui::PopupDirection::UP')
cls.enum('DOWN', 'fairygui::PopupDirection::DOWN')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::AutoSizeType'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('NONE', 'fairygui::AutoSizeType::NONE')
cls.enum('BOTH', 'fairygui::AutoSizeType::BOTH')
cls.enum('HEIGHT', 'fairygui::AutoSizeType::HEIGHT')
cls.enum('SHRINK', 'fairygui::AutoSizeType::SHRINK')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::FlipType'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('NONE', 'fairygui::FlipType::NONE')
cls.enum('HORIZONTAL', 'fairygui::FlipType::HORIZONTAL')
cls.enum('VERTICAL', 'fairygui::FlipType::VERTICAL')
cls.enum('BOTH', 'fairygui::FlipType::BOTH')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::TransitionActionType'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('XY', 'fairygui::TransitionActionType::XY')
cls.enum('Size', 'fairygui::TransitionActionType::Size')
cls.enum('Scale', 'fairygui::TransitionActionType::Scale')
cls.enum('Pivot', 'fairygui::TransitionActionType::Pivot')
cls.enum('Alpha', 'fairygui::TransitionActionType::Alpha')
cls.enum('Rotation', 'fairygui::TransitionActionType::Rotation')
cls.enum('Color', 'fairygui::TransitionActionType::Color')
cls.enum('Animation', 'fairygui::TransitionActionType::Animation')
cls.enum('Visible', 'fairygui::TransitionActionType::Visible')
cls.enum('Sound', 'fairygui::TransitionActionType::Sound')
cls.enum('Transition', 'fairygui::TransitionActionType::Transition')
cls.enum('Shake', 'fairygui::TransitionActionType::Shake')
cls.enum('ColorFilter', 'fairygui::TransitionActionType::ColorFilter')
cls.enum('Skew', 'fairygui::TransitionActionType::Skew')
cls.enum('Text', 'fairygui::TransitionActionType::Text')
cls.enum('Icon', 'fairygui::TransitionActionType::Icon')
cls.enum('Unknown', 'fairygui::TransitionActionType::Unknown')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::FillMethod'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('None', 'fairygui::FillMethod::None')
cls.enum('Horizontal', 'fairygui::FillMethod::Horizontal')
cls.enum('Vertical', 'fairygui::FillMethod::Vertical')
cls.enum('Radial90', 'fairygui::FillMethod::Radial90')
cls.enum('Radial180', 'fairygui::FillMethod::Radial180')
cls.enum('Radial360', 'fairygui::FillMethod::Radial360')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::FillOrigin'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('Top', 'fairygui::FillOrigin::Top')
cls.enum('Bottom', 'fairygui::FillOrigin::Bottom')
cls.enum('Left', 'fairygui::FillOrigin::Left')
cls.enum('Right', 'fairygui::FillOrigin::Right')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::ObjectPropID'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('Text', 'fairygui::ObjectPropID::Text')
cls.enum('Icon', 'fairygui::ObjectPropID::Icon')
cls.enum('Color', 'fairygui::ObjectPropID::Color')
cls.enum('OutlineColor', 'fairygui::ObjectPropID::OutlineColor')
cls.enum('Playing', 'fairygui::ObjectPropID::Playing')
cls.enum('Frame', 'fairygui::ObjectPropID::Frame')
cls.enum('DeltaTime', 'fairygui::ObjectPropID::DeltaTime')
cls.enum('TimeScale', 'fairygui::ObjectPropID::TimeScale')
cls.enum('FontSize', 'fairygui::ObjectPropID::FontSize')
cls.enum('Selected', 'fairygui::ObjectPropID::Selected')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::GController'
cls.SUPERCLS = 'fairygui::UIEventDispatcher'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'GController()')
cls.func(nil, 'fairygui::GComponent *getParent()')
cls.func(nil, 'void setParent(fairygui::GComponent *value)')
cls.func(nil, 'int getSelectedIndex()')
cls.func(nil, 'void setSelectedIndex(int value, @optional bool triggerEvent)')
cls.func(nil, 'const std::string &getSelectedPage()')
cls.func(nil, 'void setSelectedPage(const std::string &value, @optional bool triggerEvent)')
cls.func(nil, 'const std::string &getSelectedPageId()')
cls.func(nil, 'void setSelectedPageId(const std::string &value, @optional bool triggerEvent)')
cls.func(nil, 'int getPrevisousIndex()')
cls.func(nil, 'const std::string &getPreviousPage()')
cls.func(nil, 'const std::string &getPreviousPageId()')
cls.func(nil, 'int getPageCount()')
cls.func(nil, 'bool hasPage(const std::string &aName)')
cls.func(nil, 'int getPageIndexById(const std::string &value)')
cls.func(nil, 'const std::string &getPageNameById(const std::string &value)')
cls.func(nil, 'const std::string &getPageId(int index)')
cls.func(nil, 'void setOppositePageId(const std::string &value)')
cls.func(nil, 'void runActions()')
cls.var('name', 'std::string name')
cls.var('changing', 'bool changing')
cls.var('autoRadioGroupDepth', 'bool autoRadioGroupDepth')
cls.prop('parent', nil, nil)
cls.prop('selectedIndex', nil, nil)
cls.prop('selectedPage', nil, nil)
cls.prop('selectedPageId', nil, nil)
cls.prop('previsousIndex', nil, nil)
cls.prop('previousPage', nil, nil)
cls.prop('previousPageId', nil, nil)
cls.prop('pageCount', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::GObject'
cls.SUPERCLS = 'fairygui::UIEventDispatcher'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static fairygui::GObject *getDraggingObject()')
cls.func(nil, 'GObject()')
cls.func(nil, 'static fairygui::GObject *create()')
cls.func(nil, 'float getX()')
cls.func(nil, 'void setX(float value)')
cls.func(nil, 'float getY()')
cls.func(nil, 'void setY(float value)')
cls.func(nil, 'const cocos2d::Vec2 &getPosition()')
cls.func(nil, 'void setPosition(float xv, float yv)')
cls.func(nil, 'float getXMin()')
cls.func(nil, 'void setXMin(float value)')
cls.func(nil, 'float getYMin()')
cls.func(nil, 'void setYMin(float value)')
cls.func(nil, 'bool isPixelSnapping()')
cls.func(nil, 'void setPixelSnapping(bool value)')
cls.func(nil, 'float getWidth()')
cls.func(nil, 'void setWidth(float value)')
cls.func(nil, 'float getHeight()')
cls.func(nil, 'void setHeight(float value)')
cls.func(nil, 'const cocos2d::Size &getSize()')
cls.func(nil, 'void setSize(float wv, float hv, @optional bool ignorePivot)')
cls.func(nil, 'void center(@optional bool restraint)')
cls.func(nil, 'void makeFullScreen()')
cls.func(nil, 'const cocos2d::Vec2 &getPivot()')
cls.func(nil, 'void setPivot(float xv, float yv, @optional bool asAnchor)')
cls.func(nil, 'bool isPivotAsAnchor()')
cls.func(nil, 'float getScaleX()')
cls.func(nil, 'void setScaleX(float value)')
cls.func(nil, 'float getScaleY()')
cls.func(nil, 'void setScaleY(float value)')
cls.func(nil, 'const cocos2d::Vec2 &getScale()')
cls.func(nil, 'void setScale(float xv, float yv)')
cls.func(nil, 'float getSkewX()')
cls.func(nil, 'void setSkewX(float value)')
cls.func(nil, 'float getSkewY()')
cls.func(nil, 'void setSkewY(float value)')
cls.func(nil, 'float getRotation()')
cls.func(nil, 'void setRotation(float value)')
cls.func(nil, 'float getAlpha()')
cls.func(nil, 'void setAlpha(float value)')
cls.func(nil, 'bool isGrayed()')
cls.func(nil, 'void setGrayed(bool value)')
cls.func(nil, 'bool isVisible()')
cls.func(nil, 'void setVisible(bool value)')
cls.func(nil, 'bool isTouchable()')
cls.func(nil, 'void setTouchable(bool value)')
cls.func(nil, 'int getSortingOrder()')
cls.func(nil, 'void setSortingOrder(int value)')
cls.func(nil, '@addref(group ^) fairygui::GGroup *getGroup()')
cls.func(nil, 'void setGroup(@addref(group ^) fairygui::GGroup *value)')
cls.func(nil, 'const std::string &getText()')
cls.func(nil, 'void setText(const std::string &text)')
cls.func(nil, 'const std::string &getIcon()')
cls.func(nil, 'void setIcon(const std::string &text)')
cls.func(nil, 'const std::string &getTooltips()')
cls.func(nil, 'void setTooltips(const std::string &value)')
cls.func(nil, 'void *getData()')
cls.func(nil, 'void setData(void *value)')
cls.func(nil, 'const cocos2d::Value &getCustomData()')
cls.func(nil, 'void setCustomData(const cocos2d::Value &value)')
cls.func(nil, 'bool isDraggable()')
cls.func(nil, 'void setDraggable(bool value)')
cls.func(nil, 'cocos2d::Rect *getDragBounds()')
cls.func(nil, 'void setDragBounds(const cocos2d::Rect &value)')
cls.func(nil, 'void startDrag(@optional int touchId)')
cls.func(nil, 'void stopDrag()')
cls.func(nil, 'std::string getResourceURL()')
cls.func(nil, 'fairygui::PackageItem *getPackageItem()')
cls.func(nil, 'cocos2d::Vec2 globalToLocal(@pack const cocos2d::Vec2 &pt)', 'cocos2d::Rect globalToLocal(@pack const cocos2d::Rect &rect)')
cls.func(nil, 'cocos2d::Vec2 localToGlobal(@pack const cocos2d::Vec2 &pt)', 'cocos2d::Rect localToGlobal(@pack const cocos2d::Rect &rect)')
cls.func(nil, 'cocos2d::Rect transformRect(@pack const cocos2d::Rect &rect, fairygui::GObject *targetSpace)')
cls.func(nil, 'fairygui::Relations *relations()')
cls.func(nil, 'void addRelation(fairygui::GObject *target, fairygui::RelationType relationType, @optional bool usePercent)')
cls.func(nil, 'void removeRelation(fairygui::GObject *target, fairygui::RelationType relationType)')
cls.func(nil, 'fairygui::GearBase *getGear(int index)')
cls.func(nil, 'bool checkGearController(int index, fairygui::GController *c)')
cls.func(nil, 'uint32_t addDisplayLock()')
cls.func(nil, 'void releaseDisplayLock(uint32_t token)')
cls.func(nil, 'fairygui::GComponent *getParent()')
cls.func(nil, 'fairygui::GObject *findParent()')
cls.func(nil, '@addref(displayObject ^) cocos2d::Node *displayObject()')
cls.func(nil, 'fairygui::GRoot *getRoot()')
cls.func(nil, 'bool onStage()')
cls.func(nil, 'void removeFromParent()')
cls.func(nil, 'cocos2d::Value getProp(fairygui::ObjectPropID propId)')
cls.func(nil, 'void setProp(fairygui::ObjectPropID propId, const cocos2d::Value &value)')
cls.func(nil, 'fairygui::GObject *hitTest(const cocos2d::Vec2 &worldPoint, const cocos2d::Camera *camera)')
cls.func(nil, 'fairygui::GTreeNode *treeNode()')
cls.var('id', 'std::string id')
cls.var('name', 'std::string name')
cls.var('sourceSize', 'cocos2d::Size sourceSize')
cls.var('initSize', 'cocos2d::Size initSize')
cls.var('minSize', 'cocos2d::Size minSize')
cls.var('maxSize', 'cocos2d::Size maxSize')
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
cls.prop('relations', 'Relations* relations()', nil)
cls.prop('displayObject', 'cocos2d::Node* displayObject()', nil)
cls.prop('draggingObject', nil, nil)
cls.prop('x', nil, nil)
cls.prop('y', nil, nil)
cls.prop('position', nil, nil)
cls.prop('xMin', nil, nil)
cls.prop('yMin', nil, nil)
cls.prop('pixelSnapping', nil, nil)
cls.prop('width', nil, nil)
cls.prop('height', nil, nil)
cls.prop('size', nil, nil)
cls.prop('pivot', nil, nil)
cls.prop('pivotAsAnchor', nil, nil)
cls.prop('scaleX', nil, nil)
cls.prop('scaleY', nil, nil)
cls.prop('scale', nil, nil)
cls.prop('skewX', nil, nil)
cls.prop('skewY', nil, nil)
cls.prop('rotation', nil, nil)
cls.prop('alpha', nil, nil)
cls.prop('grayed', nil, nil)
cls.prop('visible', nil, nil)
cls.prop('touchable', nil, nil)
cls.prop('sortingOrder', nil, nil)
cls.prop('group', nil, nil)
cls.prop('text', nil, nil)
cls.prop('icon', nil, nil)
cls.prop('tooltips', nil, nil)
cls.prop('data', nil, nil)
cls.prop('customData', nil, nil)
cls.prop('draggable', nil, nil)
cls.prop('dragBounds', nil, nil)
cls.prop('resourceURL', nil, nil)
cls.prop('packageItem', nil, nil)
cls.prop('parent', nil, nil)
cls.prop('root', nil, nil)
cls.insert('center', {
    BEFORE = [[
        if (!self->getParent() && !fairygui::UIRoot) {
            luaL_error(L, "UIRoot and parent are both nullptr");
        }
    ]],
    AFTER = nil,
    CALLBACK_BEFORE = nil,
    CALLBACK_AFTER = nil,
})
cls.insert('makeFullScreen', {
    BEFORE = [[
        if (!fairygui::UIRoot) {
            luaL_error(L, "UIRoot is nullptr");
        }
    ]],
    AFTER = nil,
    CALLBACK_BEFORE = nil,
    CALLBACK_AFTER = nil,
})
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::GComponent'
cls.SUPERCLS = 'fairygui::GObject'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = [[
    static int _fairygui_GComponent_getController(lua_State *L);
    static int _fairygui_GComponent_getTransition(lua_State *L);
    static int _fairygui_GComponent_getChild(lua_State *L);
]]
cls.func('resolve', [[
    {
        auto self = olua_toobj<fairygui::GComponent>(L, 1);
        const char *name = olua_checkstring(L, 2);
        char type = '.';
        while (true) {
            const char *sep = strpbrk(name, ".~#");
            if (sep == name) {
                type = *sep;
                ++name;
                continue;
            }
            if (!sep) {
                sep = name + strlen(name);
            }
            if (type == '#') {
                lua_pushcfunction(L, _fairygui_GComponent_getController);
            } else if (type == '~') {
                lua_pushcfunction(L, _fairygui_GComponent_getTransition);
            } else {
                lua_pushcfunction(L, _fairygui_GComponent_getChild);
            }
            olua_push_cppobj<fairygui::GComponent>(L, self);
            lua_pushlstring(L, name, sep - name);
            lua_call(L, 2, 1);

            if (type != '.' || *sep == '\0') {
                return 1;
            } else if (olua_isa<fairygui::GComponent>(L, -1)) {
                self = olua_toobj<fairygui::GComponent>(L, -1);
                name = sep;
            } else {
                return 0;
            }
        }
        return 0;
    }
]])
cls.func(nil, 'GComponent()')
cls.func(nil, 'static fairygui::GComponent *create()')
cls.func(nil, 'fairygui::GObject *addChild(@addref(children |) fairygui::GObject *child)')
cls.func(nil, 'fairygui::GObject *addChildAt(@addref(children |) fairygui::GObject *child, int index)')
cls.func(nil, 'void removeChild(@delref(children |) fairygui::GObject *child)')
cls.func(nil, '@delref(children ~) void removeChildAt(int index)')
cls.func(nil, '@delref(children ~) void removeChildren()', '@delref(children ~) void removeChildren(int beginIndex, int endIndex)')
cls.func(nil, '@addref(children |) fairygui::GObject *getChildAt(int index)')
cls.func(nil, '@addref(children |) fairygui::GObject *getChild(const std::string &name)')
cls.func(nil, '@addref(children |) fairygui::GObject *getChildInGroup(const fairygui::GGroup *group, const std::string &name)')
cls.func(nil, '@addref(children |) fairygui::GObject *getChildById(const std::string &id)')
cls.func(nil, '@addref(children |) const cocos2d::Vector<GObject *> &getChildren()')
cls.func(nil, 'int getChildIndex(const fairygui::GObject *child)')
cls.func(nil, 'void setChildIndex(fairygui::GObject *child, int index)')
cls.func(nil, 'int setChildIndexBefore(fairygui::GObject *child, int index)')
cls.func(nil, 'void swapChildren(fairygui::GObject *child1, fairygui::GObject *child2)')
cls.func(nil, 'void swapChildrenAt(int index1, int index2)')
cls.func(nil, 'int numChildren()')
cls.func(nil, 'bool isAncestorOf(const fairygui::GObject *obj)')
cls.func(nil, 'bool isChildInView(fairygui::GObject *child)')
cls.func(nil, 'int getFirstChildInView()')
cls.func(nil, 'void addController(@addref(controllers |) fairygui::GController *c)')
cls.func(nil, '@addref(controllers |) fairygui::GController *getControllerAt(int index)')
cls.func(nil, '@addref(controllers |) fairygui::GController *getController(const std::string &name)')
cls.func(nil, '@addref(controllers |) const cocos2d::Vector<GController *> &getControllers()')
cls.func(nil, 'void removeController(@delref(controllers |) fairygui::GController *c)')
cls.func(nil, 'void applyController(fairygui::GController *c)')
cls.func(nil, 'void applyAllControllers()')
cls.func(nil, '@addref(transitions |) fairygui::Transition *getTransition(const std::string &name)')
cls.func(nil, '@addref(transitions |) fairygui::Transition *getTransitionAt(int index)')
cls.func(nil, '@addref(transitions |) const cocos2d::Vector<Transition *> &getTransitions()')
cls.func(nil, 'bool getOpaque()')
cls.func(nil, 'void setOpaque(bool value)')
cls.func(nil, 'const fairygui::Margin &getMargin()')
cls.func(nil, 'void setMargin(const fairygui::Margin &value)')
cls.func(nil, 'fairygui::ChildrenRenderOrder getChildrenRenderOrder()')
cls.func(nil, 'void setChildrenRenderOrder(fairygui::ChildrenRenderOrder value)')
cls.func(nil, 'int getApexIndex()')
cls.func(nil, 'void setApexIndex(int value)')
cls.func(nil, '@addref(mask ^) cocos2d::Node *getMask()')
cls.func(nil, 'void setMask(@addref(mask ^) cocos2d::Node *value, @optional bool inverted)')
cls.func(nil, 'fairygui::IHitTest *getHitArea()')
cls.func(nil, 'void setHitArea(fairygui::IHitTest *value)')
cls.func(nil, 'fairygui::ScrollPane *getScrollPane()')
cls.func(nil, 'float getViewWidth()')
cls.func(nil, 'void setViewWidth(float value)')
cls.func(nil, 'float getViewHeight()')
cls.func(nil, 'void setViewHeight(float value)')
cls.func(nil, 'void setBoundsChangedFlag()')
cls.func(nil, 'void ensureBoundsCorrect()')
cls.func(nil, 'cocos2d::Vec2 getSnappingPosition(const cocos2d::Vec2 &pt)')
cls.func(nil, 'void childSortingOrderChanged(fairygui::GObject *child, int oldValue, int newValue)')
cls.func(nil, 'void childStateChanged(fairygui::GObject *child)')
cls.func(nil, 'void adjustRadioGroupDepth(fairygui::GObject *obj, fairygui::GController *c)')
cls.prop('numChildren', 'int numChildren()', nil)
cls.prop('children', nil, nil)
cls.prop('firstChildInView', nil, nil)
cls.prop('controllers', nil, nil)
cls.prop('transitions', nil, nil)
cls.prop('opaque', nil, nil)
cls.prop('margin', nil, nil)
cls.prop('childrenRenderOrder', nil, nil)
cls.prop('apexIndex', nil, nil)
cls.prop('mask', nil, nil)
cls.prop('hitArea', nil, nil)
cls.prop('scrollPane', nil, nil)
cls.prop('viewWidth', nil, nil)
cls.prop('viewHeight', nil, nil)
cls.alias('resolve', 'getChildByPath')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::GRoot'
cls.SUPERCLS = 'fairygui::GComponent'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'GRoot()')
cls.func(nil, 'static fairygui::GRoot *create(cocos2d::Scene *scene, @optional int zOrder)')
cls.func(nil, 'static fairygui::GRoot *getInstance()')
cls.func(nil, '@delref(children ~) void showWindow(@addref(children |) fairygui::Window *win)')
cls.func(nil, '@delref(children ~ parent) void hideWindow(fairygui::Window *win)')
cls.func(nil, '@delref(children ~ parent) void hideWindowImmediately(fairygui::Window *win)')
cls.func(nil, 'void bringToFront(fairygui::Window *win)')
cls.func(nil, 'void showModalWait()')
cls.func(nil, 'void closeModalWait()')
cls.func(nil, 'void closeAllExceptModals()')
cls.func(nil, 'void closeAllWindows()')
cls.func(nil, '@addref(children |) fairygui::Window *getTopWindow()')
cls.func(nil, '@addref(children |) fairygui::GObject *getModalWaitingPane()')
cls.func(nil, '@addref(children |) fairygui::GGraph *getModalLayer()')
cls.func(nil, 'bool hasModalWindow()')
cls.func(nil, 'bool isModalWaiting()')
cls.func(nil, '@addref(inputProcessor ^) fairygui::InputProcessor *getInputProcessor()')
cls.func(nil, 'cocos2d::Vec2 getTouchPosition(int touchId)')
cls.func(nil, 'fairygui::GObject *getTouchTarget()')
cls.func(nil, 'cocos2d::Vec2 worldToRoot(const cocos2d::Vec2 &pt)')
cls.func(nil, 'cocos2d::Vec2 rootToWorld(const cocos2d::Vec2 &pt)')
cls.func(nil, '@delref(children ~) void showPopup(@addref(children |) fairygui::GObject *popup)', '@delref(children ~) void showPopup(@addref(children |) fairygui::GObject *popup, fairygui::GObject *target, fairygui::PopupDirection dir)')
cls.func(nil, '@delref(children ~) void togglePopup(@addref(children |) fairygui::GObject *popup)', '@delref(children ~) void togglePopup(@addref(children |) fairygui::GObject *popup, fairygui::GObject *target, fairygui::PopupDirection dir)')
cls.func(nil, '@delref(children ~) void hidePopup()', '@delref(children ~) void hidePopup(fairygui::GObject *popup)')
cls.func(nil, 'bool hasAnyPopup()')
cls.func(nil, 'cocos2d::Vec2 getPoupPosition(fairygui::GObject *popup, fairygui::GObject *target, fairygui::PopupDirection dir)')
cls.func(nil, 'void showTooltips(const std::string &msg)')
cls.func(nil, 'void showTooltipsWin(fairygui::GObject *tooltipWin)')
cls.func(nil, 'void hideTooltips()')
cls.func(nil, 'void playSound(const std::string &url, @optional float volumeScale)')
cls.func(nil, 'bool isSoundEnabled()')
cls.func(nil, 'void setSoundEnabled(bool value)')
cls.func(nil, 'float getSoundVolumeScale()')
cls.func(nil, 'void setSoundVolumeScale(float value)')
cls.func(nil, 'void setNotAsUIRoot()')
cls.var('contentScaleLevel', 'static int contentScaleLevel')
cls.prop('UIRoot', 'static GRoot* getInstance()', nil)
cls.prop('instance', nil, nil)
cls.prop('topWindow', nil, nil)
cls.prop('modalWaitingPane', nil, nil)
cls.prop('modalLayer', nil, nil)
cls.prop('modalWaiting', nil, nil)
cls.prop('inputProcessor', nil, nil)
cls.prop('touchTarget', nil, nil)
cls.prop('soundEnabled', nil, nil)
cls.prop('soundVolumeScale', nil, nil)
cls.insert('create', {
    BEFORE = nil,
    AFTER = [[
        olua_push_cppobj<cocos2d::Node>(L, ret->displayObject());
        olua_addref(L, -1, "fgui.root", -2, OLUA_MODE_SINGLE);
        olua_addref(L, 1, "children", -1, OLUA_MODE_MULTIPLE);
        lua_pop(L, 1);
    ]],
    CALLBACK_BEFORE = nil,
    CALLBACK_AFTER = nil,
})
cls.insert('hideWindow', {
    BEFORE = [[
        int parent = 1;
        if (arg1->getParent()) {
            olua_push_cppobj<fairygui::GComponent>(L, arg1->getParent());
            parent = lua_gettop(L);
        }
    ]],
    AFTER = nil,
    CALLBACK_BEFORE = nil,
    CALLBACK_AFTER = nil,
})
cls.insert('hideWindowImmediately', {
    BEFORE = [[
        int parent = 1;
        if (arg1->getParent()) {
            olua_push_cppobj<fairygui::GComponent>(L, arg1->getParent());
            parent = lua_gettop(L);
        }
    ]],
    AFTER = nil,
    CALLBACK_BEFORE = nil,
    CALLBACK_AFTER = nil,
})
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::GGroup'
cls.SUPERCLS = 'fairygui::GObject'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'GGroup()')
cls.func(nil, 'static fairygui::GGroup *create()')
cls.func(nil, 'fairygui::GroupLayoutType getLayout()')
cls.func(nil, 'void setLayout(fairygui::GroupLayoutType value)')
cls.func(nil, 'int getColumnGap()')
cls.func(nil, 'void setColumnGap(int value)')
cls.func(nil, 'int getLineGap()')
cls.func(nil, 'void setLineGap(int value)')
cls.func(nil, 'bool isExcludeInvisibles()')
cls.func(nil, 'void setExcludeInvisibles(bool value)')
cls.func(nil, 'bool isAutoSizeDisabled()')
cls.func(nil, 'void setAutoSizeDisabled(bool value)')
cls.func(nil, 'int getMainGridIndex()')
cls.func(nil, 'void setMainGridIndex(int value)')
cls.func(nil, 'int getMainGridMinSize()')
cls.func(nil, 'void setMainGridMinSize(int value)')
cls.func(nil, 'void setBoundsChangedFlag(@optional bool positionChangedOnly)')
cls.func(nil, 'void moveChildren(float dx, float dy)')
cls.func(nil, 'void resizeChildren(float dw, float dh)')
cls.prop('layout', nil, nil)
cls.prop('columnGap', nil, nil)
cls.prop('lineGap', nil, nil)
cls.prop('excludeInvisibles', nil, nil)
cls.prop('autoSizeDisabled', nil, nil)
cls.prop('mainGridIndex', nil, nil)
cls.prop('mainGridMinSize', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::GScrollBar'
cls.SUPERCLS = 'fairygui::GComponent'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'GScrollBar()')
cls.func(nil, 'static fairygui::GScrollBar *create()')
cls.func(nil, 'void setScrollPane(fairygui::ScrollPane *target, bool vertical)')
cls.func(nil, 'void setDisplayPerc(float value)')
cls.func(nil, 'void setScrollPerc(float value)')
cls.func(nil, 'float getMinSize()')
cls.prop('minSize', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::GLoader'
cls.SUPERCLS = 'fairygui::GObject'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'GLoader()')
cls.func(nil, 'static fairygui::GLoader *create()')
cls.func(nil, 'const std::string &getURL()')
cls.func(nil, 'void setURL(const std::string &value)')
cls.func(nil, 'cocos2d::TextHAlignment getAlign()')
cls.func(nil, 'void setAlign(cocos2d::TextHAlignment value)')
cls.func(nil, 'cocos2d::TextVAlignment getVerticalAlign()')
cls.func(nil, 'void setVerticalAlign(cocos2d::TextVAlignment value)')
cls.func(nil, 'bool getAutoSize()')
cls.func(nil, 'void setAutoSize(bool value)')
cls.func(nil, 'fairygui::LoaderFillType getFill()')
cls.func(nil, 'void setFill(fairygui::LoaderFillType value)')
cls.func(nil, 'bool isShrinkOnly()')
cls.func(nil, 'void setShrinkOnly(bool value)')
cls.func(nil, 'const cocos2d::Size &getContentSize()')
cls.func(nil, 'cocos2d::Color3B getColor()')
cls.func(nil, 'void setColor(const cocos2d::Color3B &value)')
cls.func(nil, 'bool isPlaying()')
cls.func(nil, 'void setPlaying(bool value)')
cls.func(nil, 'int getFrame()')
cls.func(nil, 'void setFrame(int value)')
cls.func(nil, 'fairygui::FillMethod getFillMethod()')
cls.func(nil, 'void setFillMethod(fairygui::FillMethod value)')
cls.func(nil, 'fairygui::FillOrigin getFillOrigin()')
cls.func(nil, 'void setFillOrigin(fairygui::FillOrigin value)')
cls.func(nil, 'bool isFillClockwise()')
cls.func(nil, 'void setFillClockwise(bool value)')
cls.func(nil, 'float getFillAmount()')
cls.func(nil, 'void setFillAmount(float value)')
cls.func(nil, '@addref(component ^) fairygui::GComponent *getComponent()')
cls.prop('url', nil, nil)
cls.prop('align', nil, nil)
cls.prop('verticalAlign', nil, nil)
cls.prop('autoSize', nil, nil)
cls.prop('fill', nil, nil)
cls.prop('shrinkOnly', nil, nil)
cls.prop('contentSize', nil, nil)
cls.prop('color', nil, nil)
cls.prop('playing', nil, nil)
cls.prop('frame', nil, nil)
cls.prop('fillMethod', nil, nil)
cls.prop('fillOrigin', nil, nil)
cls.prop('fillClockwise', nil, nil)
cls.prop('fillAmount', nil, nil)
cls.prop('component', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::GLoader3D'
cls.SUPERCLS = 'fairygui::GObject'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'GLoader3D()')
cls.func(nil, 'static fairygui::GLoader3D *create()')
cls.func(nil, 'const std::string &getURL()')
cls.func(nil, 'void setURL(const std::string &value)')
cls.func(nil, 'cocos2d::TextHAlignment getAlign()')
cls.func(nil, 'void setAlign(cocos2d::TextHAlignment value)')
cls.func(nil, 'cocos2d::TextVAlignment getVerticalAlign()')
cls.func(nil, 'void setVerticalAlign(cocos2d::TextVAlignment value)')
cls.func(nil, 'bool getAutoSize()')
cls.func(nil, 'void setAutoSize(bool value)')
cls.func(nil, 'fairygui::LoaderFillType getFill()')
cls.func(nil, 'void setFill(fairygui::LoaderFillType value)')
cls.func(nil, 'bool isShrinkOnly()')
cls.func(nil, 'void setShrinkOnly(bool value)')
cls.func(nil, '@addref(content ^) const cocos2d::Node *getContent()')
cls.func(nil, 'void setContent(@addref(content ^) cocos2d::Node *value)')
cls.func(nil, 'cocos2d::Color3B getColor()')
cls.func(nil, 'void setColor(const cocos2d::Color3B &value)')
cls.func(nil, 'bool isPlaying()')
cls.func(nil, 'void setPlaying(bool value)')
cls.func(nil, 'int getFrame()')
cls.func(nil, 'void setFrame(int value)')
cls.func(nil, 'const std::string &getAnimationName()')
cls.func(nil, 'void setAnimationName(const std::string &value)')
cls.func(nil, 'const std::string &getSkinName()')
cls.func(nil, 'void setSkinName(const std::string &value)')
cls.func(nil, 'bool getLoop()')
cls.func(nil, 'void setLoop(bool value)')
cls.prop('url', nil, nil)
cls.prop('align', nil, nil)
cls.prop('verticalAlign', nil, nil)
cls.prop('autoSize', nil, nil)
cls.prop('fill', nil, nil)
cls.prop('shrinkOnly', nil, nil)
cls.prop('content', nil, nil)
cls.prop('color', nil, nil)
cls.prop('playing', nil, nil)
cls.prop('frame', nil, nil)
cls.prop('animationName', nil, nil)
cls.prop('skinName', nil, nil)
cls.prop('loop', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::GTextField'
cls.SUPERCLS = 'fairygui::GObject'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'bool isUBBEnabled()')
cls.func(nil, 'void setUBBEnabled(bool value)')
cls.func(nil, 'fairygui::AutoSizeType getAutoSize()')
cls.func(nil, 'void setAutoSize(fairygui::AutoSizeType value)')
cls.func(nil, 'bool isSingleLine()')
cls.func(nil, 'void setSingleLine(bool value)')
cls.func(nil, 'fairygui::TextFormat *getTextFormat()')
cls.func(nil, 'void applyTextFormat()')
cls.func(nil, 'const cocos2d::Size &getTextSize()')
cls.func(nil, 'cocos2d::Color3B getColor()')
cls.func(nil, 'void setColor(const cocos2d::Color3B &value)')
cls.func(nil, 'float getFontSize()')
cls.func(nil, 'void setFontSize(float value)')
cls.func(nil, 'cocos2d::Color3B getOutlineColor()')
cls.func(nil, 'void setOutlineColor(const cocos2d::Color3B &value)')
cls.func(nil, 'cocos2d::ValueMap *getTemplateVars()')
cls.func(nil, 'void setTemplateVars(cocos2d::ValueMap *value)')
cls.func(nil, 'fairygui::GTextField *setVar(const std::string &name, const cocos2d::Value &value)')
cls.func(nil, 'void flushVars()')
cls.prop('ubbEnabled', nil, nil)
cls.prop('autoSize', nil, nil)
cls.prop('singleLine', nil, nil)
cls.prop('textFormat', nil, nil)
cls.prop('textSize', nil, nil)
cls.prop('color', nil, nil)
cls.prop('fontSize', nil, nil)
cls.prop('outlineColor', nil, nil)
cls.prop('templateVars', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::GBasicTextField'
cls.SUPERCLS = 'fairygui::GTextField'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'GBasicTextField()')
cls.func(nil, 'static fairygui::GBasicTextField *create()')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::GGraph'
cls.SUPERCLS = 'fairygui::GObject'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'GGraph()')
cls.func(nil, 'static fairygui::GGraph *create()')
cls.func(nil, 'void drawRect(float aWidth, float aHeight, int lineSize, const cocos2d::Color4F &lineColor, const cocos2d::Color4F &fillColor)')
cls.func(nil, 'void drawEllipse(float aWidth, float aHeight, int lineSize, const cocos2d::Color4F &lineColor, const cocos2d::Color4F &fillColor)')
cls.func(nil, 'bool isEmpty()')
cls.func(nil, 'cocos2d::Color3B getColor()')
cls.func(nil, 'void setColor(const cocos2d::Color3B &value)')
cls.prop('empty', nil, nil)
cls.prop('color', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::GButton'
cls.SUPERCLS = 'fairygui::GComponent'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.const('UP', 'fairygui::GButton::UP', 'const std::string')
cls.const('DOWN', 'fairygui::GButton::DOWN', 'const std::string')
cls.const('OVER', 'fairygui::GButton::OVER', 'const std::string')
cls.const('SELECTED_OVER', 'fairygui::GButton::SELECTED_OVER', 'const std::string')
cls.const('DISABLED', 'fairygui::GButton::DISABLED', 'const std::string')
cls.const('SELECTED_DISABLED', 'fairygui::GButton::SELECTED_DISABLED', 'const std::string')
cls.func(nil, 'GButton()')
cls.func(nil, 'static fairygui::GButton *create()')
cls.func(nil, 'const std::string &getTitle()')
cls.func(nil, 'void setTitle(const std::string &value)')
cls.func(nil, 'const std::string &getSelectedTitle()')
cls.func(nil, 'void setSelectedTitle(const std::string &value)')
cls.func(nil, 'const std::string &getSelectedIcon()')
cls.func(nil, 'void setSelectedIcon(const std::string &value)')
cls.func(nil, 'cocos2d::Color3B getTitleColor()')
cls.func(nil, 'void setTitleColor(const cocos2d::Color3B &value)')
cls.func(nil, 'int getTitleFontSize()')
cls.func(nil, 'void setTitleFontSize(int value)')
cls.func(nil, 'bool isSelected()')
cls.func(nil, 'void setSelected(bool value)')
cls.func(nil, '@addref(relatedController ^) fairygui::GController *getRelatedController()')
cls.func(nil, 'void setRelatedController(@addref(relatedController ^) fairygui::GController *c)')
cls.func(nil, 'bool isChangeStateOnClick()')
cls.func(nil, 'void setChangeStateOnClick(bool value)')
cls.func(nil, '@addref(textField ^) fairygui::GTextField *getTextField()')
cls.prop('title', nil, nil)
cls.prop('selectedTitle', nil, nil)
cls.prop('selectedIcon', nil, nil)
cls.prop('titleColor', nil, nil)
cls.prop('titleFontSize', nil, nil)
cls.prop('selected', nil, nil)
cls.prop('relatedController', nil, nil)
cls.prop('changeStateOnClick', nil, nil)
cls.prop('textField', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::GImage'
cls.SUPERCLS = 'fairygui::GObject'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'GImage()')
cls.func(nil, 'static fairygui::GImage *create()')
cls.func(nil, 'fairygui::FlipType getFlip()')
cls.func(nil, 'void setFlip(fairygui::FlipType value)')
cls.func(nil, 'cocos2d::Color3B getColor()')
cls.func(nil, 'void setColor(const cocos2d::Color3B &value)')
cls.func(nil, 'fairygui::FillMethod getFillMethod()')
cls.func(nil, 'void setFillMethod(fairygui::FillMethod value)')
cls.func(nil, 'fairygui::FillOrigin getFillOrigin()')
cls.func(nil, 'void setFillOrigin(fairygui::FillOrigin value)')
cls.func(nil, 'bool isFillClockwise()')
cls.func(nil, 'void setFillClockwise(bool value)')
cls.func(nil, 'float getFillAmount()')
cls.func(nil, 'void setFillAmount(float value)')
cls.prop('flip', nil, nil)
cls.prop('color', nil, nil)
cls.prop('fillMethod', nil, nil)
cls.prop('fillOrigin', nil, nil)
cls.prop('fillClockwise', nil, nil)
cls.prop('fillAmount', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::GLabel'
cls.SUPERCLS = 'fairygui::GComponent'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'GLabel()')
cls.func(nil, 'static fairygui::GLabel *create()')
cls.func(nil, 'const std::string &getTitle()')
cls.func(nil, 'void setTitle(const std::string &value)')
cls.func(nil, 'cocos2d::Color3B getTitleColor()')
cls.func(nil, 'void setTitleColor(const cocos2d::Color3B &value)')
cls.func(nil, 'int getTitleFontSize()')
cls.func(nil, 'void setTitleFontSize(int value)')
cls.func(nil, '@addref(textField ^) fairygui::GTextField *getTextField()')
cls.prop('title', nil, nil)
cls.prop('titleColor', nil, nil)
cls.prop('titleFontSize', nil, nil)
cls.prop('textField', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::GList'
cls.SUPERCLS = 'fairygui::GComponent'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'GList()')
cls.func(nil, 'static fairygui::GList *create()')
cls.func(nil, 'const std::string &getDefaultItem()')
cls.func(nil, 'void setDefaultItem(const std::string &value)')
cls.func(nil, 'fairygui::ListLayoutType getLayout()')
cls.func(nil, 'void setLayout(fairygui::ListLayoutType value)')
cls.func(nil, 'int getLineCount()')
cls.func(nil, 'void setLineCount(int value)')
cls.func(nil, 'int getColumnCount()')
cls.func(nil, 'void setColumnCount(int value)')
cls.func(nil, 'int getColumnGap()')
cls.func(nil, 'void setColumnGap(int value)')
cls.func(nil, 'int getLineGap()')
cls.func(nil, 'void setLineGap(int value)')
cls.func(nil, 'cocos2d::TextHAlignment getAlign()')
cls.func(nil, 'void setAlign(cocos2d::TextHAlignment value)')
cls.func(nil, 'cocos2d::TextVAlignment getVerticalAlign()')
cls.func(nil, 'void setVerticalAlign(cocos2d::TextVAlignment value)')
cls.func(nil, 'bool getAutoResizeItem()')
cls.func(nil, 'void setAutoResizeItem(bool value)')
cls.func(nil, 'fairygui::ListSelectionMode getSelectionMode()')
cls.func(nil, 'void setSelectionMode(fairygui::ListSelectionMode value)')
cls.func(nil, 'fairygui::GObject *getFromPool()', 'fairygui::GObject *getFromPool(const std::string &url)')
cls.func(nil, 'void returnToPool(@delref(children |) fairygui::GObject *obj)')
cls.func(nil, '@addref(children |) fairygui::GObject *addItemFromPool()', '@addref(children |) fairygui::GObject *addItemFromPool(const std::string &url)')
cls.func(nil, '@delref(children ~) void removeChildToPoolAt(int index)')
cls.func(nil, 'void removeChildToPool(@delref(children |) fairygui::GObject *child)')
cls.func(nil, '@delref(children ~) void removeChildrenToPool()', '@delref(children ~) void removeChildrenToPool(int beginIndex, int endIndex)')
cls.func(nil, 'int getSelectedIndex()')
cls.func(nil, 'void setSelectedIndex(int value)')
cls.func(nil, 'void getSelection(@out std::vector<int> &result)')
cls.func(nil, 'void addSelection(int index, bool scrollItToView)')
cls.func(nil, 'void removeSelection(int index)')
cls.func(nil, 'void clearSelection()')
cls.func(nil, 'void selectAll()')
cls.func(nil, 'void selectReverse()')
cls.func(nil, 'void handleArrowKey(int dir)')
cls.func(nil, 'void resizeToFit(int itemCount)', 'void resizeToFit(int itemCount, int minSize)')
cls.func(nil, 'void scrollToView(int index, @optional bool ani, @optional bool setFirst)')
cls.func(nil, '@addref(selectionController ^) fairygui::GController *getSelectionController()')
cls.func(nil, 'void setSelectionController(@addref(selectionController ^) fairygui::GController *value)')
cls.func(nil, '@delref(children ~) void setVirtual()')
cls.func(nil, '@delref(children ~) void setVirtualAndLoop()')
cls.func(nil, 'bool isVirtual()')
cls.func(nil, 'void refreshVirtualList()')
cls.func(nil, 'int getNumItems()')
cls.func(nil, '@delref(children ~) void setNumItems(int value)')
cls.func(nil, 'int childIndexToItemIndex(int index)')
cls.func(nil, 'int itemIndexToChildIndex(int index)')
cls.var('itemRenderer', '@nullable std::function<void (int, GObject *)> itemRenderer')
cls.var('itemProvider', '@nullable @local std::function<std::string (int)> itemProvider')
cls.var('scrollItemToViewOnClick', 'bool scrollItemToViewOnClick')
cls.var('foldInvisibleItems', 'bool foldInvisibleItems')
cls.prop('defaultItem', nil, nil)
cls.prop('layout', nil, nil)
cls.prop('lineCount', nil, nil)
cls.prop('columnCount', nil, nil)
cls.prop('columnGap', nil, nil)
cls.prop('lineGap', nil, nil)
cls.prop('align', nil, nil)
cls.prop('verticalAlign', nil, nil)
cls.prop('autoResizeItem', nil, nil)
cls.prop('selectionMode', nil, nil)
cls.prop('selectedIndex', nil, nil)
cls.prop('selectionController', nil, nil)
cls.prop('virtual', nil, nil)
cls.prop('numItems', nil, nil)
cls.insert('itemRenderer', {
    BEFORE = nil,
    AFTER = nil,
    CALLBACK_BEFORE = [[
        if (arg2->getParent()) {
            olua_push_cppobj<fairygui::GComponent>(L, (fairygui::GComponent *)cb_store);
            olua_addref(L, -1, "children", -2, OLUA_MODE_MULTIPLE);
            lua_pop(L, 1);
        }
    ]],
    CALLBACK_AFTER = nil,
})
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::GMovieClip'
cls.SUPERCLS = 'fairygui::GObject'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'GMovieClip()')
cls.func(nil, 'static fairygui::GMovieClip *create()')
cls.func(nil, 'bool isPlaying()')
cls.func(nil, 'void setPlaying(bool value)')
cls.func(nil, 'int getFrame()')
cls.func(nil, 'void setFrame(int value)')
cls.func(nil, 'float getTimeScale()')
cls.func(nil, 'void setTimeScale(float value)')
cls.func(nil, 'void advance(float time)')
cls.func(nil, 'fairygui::FlipType getFlip()')
cls.func(nil, 'void setFlip(fairygui::FlipType value)')
cls.func(nil, 'cocos2d::Color3B getColor()')
cls.func(nil, 'void setColor(const cocos2d::Color3B &value)')
cls.callback {
    FUNCS =  {
        'void setPlaySettings(@optional int start, @optional int end, @optional int times, @optional int endAt, @local @optional std::function<void ()> completeCallback)'
    },
    TAG_MAKER = 'PlaySettings',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.prop('playing', nil, nil)
cls.prop('frame', nil, nil)
cls.prop('timeScale', nil, nil)
cls.prop('flip', nil, nil)
cls.prop('color', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::GProgressBar'
cls.SUPERCLS = 'fairygui::GComponent'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'GProgressBar()')
cls.func(nil, 'static fairygui::GProgressBar *create()')
cls.func(nil, 'fairygui::ProgressTitleType getTitleType()')
cls.func(nil, 'void setTitleType(fairygui::ProgressTitleType value)')
cls.func(nil, 'double getMin()')
cls.func(nil, 'void setMin(double value)')
cls.func(nil, 'double getMax()')
cls.func(nil, 'void setMax(double value)')
cls.func(nil, 'double getValue()')
cls.func(nil, 'void setValue(double value)')
cls.func(nil, 'void tweenValue(double value, float duration)')
cls.func(nil, 'void update(double newValue)')
cls.prop('titleType', nil, nil)
cls.prop('min', nil, nil)
cls.prop('max', nil, nil)
cls.prop('value', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::GComboBox'
cls.SUPERCLS = 'fairygui::GComponent'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'GComboBox()')
cls.func(nil, 'static fairygui::GComboBox *create()')
cls.func(nil, 'const std::string &getTitle()')
cls.func(nil, 'void setTitle(const std::string &value)')
cls.func(nil, 'const cocos2d::Color3B getTitleColor()')
cls.func(nil, 'void setTitleColor(const cocos2d::Color3B &value)')
cls.func(nil, 'int getTitleFontSize()')
cls.func(nil, 'void setTitleFontSize(int value)')
cls.func(nil, 'const std::string &getValue()')
cls.func(nil, 'void setValue(const std::string &value)')
cls.func(nil, 'int getSelectedIndex()')
cls.func(nil, 'void setSelectedIndex(int value)')
cls.func(nil, '@addref(selectionController ^) fairygui::GController *getSelectionController()')
cls.func(nil, 'void setSelectionController(@addref(selectionController ^) fairygui::GController *value)')
cls.func(nil, 'std::vector<std::string> &getItems()')
cls.func(nil, 'std::vector<std::string> &getIcons()')
cls.func(nil, 'std::vector<std::string> &getValues()')
cls.func(nil, '@addref(dropdown ^) fairygui::GObject *getDropdown()')
cls.func(nil, 'void refresh()')
cls.func(nil, '@addref(textField ^) fairygui::GTextField *getTextField()')
cls.var('visibleItemCount', 'int visibleItemCount')
cls.var('popupDirection', 'fairygui::PopupDirection popupDirection')
cls.prop('title', nil, nil)
cls.prop('titleColor', nil, nil)
cls.prop('titleFontSize', nil, nil)
cls.prop('value', nil, nil)
cls.prop('selectedIndex', nil, nil)
cls.prop('selectionController', nil, nil)
cls.prop('items', nil, nil)
cls.prop('icons', nil, nil)
cls.prop('values', nil, nil)
cls.prop('dropdown', nil, nil)
cls.prop('textField', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::GRichTextField'
cls.SUPERCLS = 'fairygui::GTextField'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'GRichTextField()')
cls.func(nil, 'static fairygui::GRichTextField *create()')
cls.func(nil, 'fairygui::HtmlObject *getControl(const std::string &name)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::GSlider'
cls.SUPERCLS = 'fairygui::GComponent'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'GSlider()')
cls.func(nil, 'static fairygui::GSlider *create()')
cls.func(nil, 'fairygui::ProgressTitleType getTitleType()')
cls.func(nil, 'void setTitleType(fairygui::ProgressTitleType value)')
cls.func(nil, 'double getMin()')
cls.func(nil, 'void setMin(double value)')
cls.func(nil, 'double getMax()')
cls.func(nil, 'void setMax(double value)')
cls.func(nil, 'double getValue()')
cls.func(nil, 'void setValue(double value)')
cls.func(nil, 'bool getWholeNumbers()')
cls.func(nil, 'void setWholeNumbers(bool value)')
cls.var('changeOnClick', 'bool changeOnClick')
cls.var('canDrag', 'bool canDrag')
cls.prop('titleType', nil, nil)
cls.prop('min', nil, nil)
cls.prop('max', nil, nil)
cls.prop('value', nil, nil)
cls.prop('wholeNumbers', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::GTextInput'
cls.SUPERCLS = 'fairygui::GTextField'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'GTextInput()')
cls.func(nil, 'static fairygui::GTextInput *create()')
cls.func(nil, 'void setPrompt(const std::string &value)')
cls.func(nil, 'void setPassword(bool value)')
cls.func(nil, 'void setKeyboardType(int value)')
cls.func(nil, 'void setMaxLength(int value)')
cls.func(nil, 'void setRestrict(const std::string &value)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::PopupMenu'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static fairygui::PopupMenu *create(const std::string &resourceURL)', 'static fairygui::PopupMenu *create()')
cls.func(nil, 'PopupMenu()')
cls.func(nil, 'void addSeperator()')
cls.func(nil, 'const std::string &getItemName(int index)')
cls.func(nil, 'void setItemText(const std::string &name, const std::string &caption)')
cls.func(nil, 'void setItemVisible(const std::string &name, bool visible)')
cls.func(nil, 'void setItemGrayed(const std::string &name, bool grayed)')
cls.func(nil, 'void setItemCheckable(const std::string &name, bool checkable)')
cls.func(nil, 'void setItemChecked(const std::string &name, bool check)')
cls.func(nil, 'bool isItemChecked(const std::string &name)')
cls.func(nil, '@delref(children ~ parent) bool removeItem(const std::string &name)')
cls.func(nil, '@delref(children ~ parent) void clearItems()')
cls.func(nil, 'int getItemCount()')
cls.func(nil, '@addref(contentPane ^) fairygui::GComponent *getContentPane()')
cls.func(nil, '@addref(list ^) fairygui::GList *getList()')
cls.func(nil, '@delref(children ~ parent)@addref(children | parent) void show()', '@delref(children ~ parent)@addref(children | parent) void show(fairygui::GObject *target, fairygui::PopupDirection dir)')
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
cls.prop('itemCount', nil, nil)
cls.prop('contentPane', nil, nil)
cls.prop('list', nil, nil)
cls.insert('show', {
    BEFORE = [[
        fairygui::GRoot *root = fairygui::UIRoot;
        if (lua_gettop(L) > 1) {
            fairygui::GObject *target = olua_checkobj<fairygui::GObject>(L, 2);
            root = target->getRoot();
        }
        if (!root) {
            luaL_error(L, "no root to add 'PopupMenu'");
        }
        olua_push_cppobj<fairygui::GRoot>(L, root);
        int parent = lua_gettop(L);
    ]],
    AFTER = nil,
    CALLBACK_BEFORE = nil,
    CALLBACK_AFTER = nil,
})
cls.insert('removeItem', {
    BEFORE = [[
        olua_push_cppobj<fairygui::GList>(L, self->getList());
        int parent = lua_gettop(L);
    ]],
    AFTER = nil,
    CALLBACK_BEFORE = nil,
    CALLBACK_AFTER = nil,
})
cls.insert('clearItems', {
    BEFORE = [[
        olua_push_cppobj<fairygui::GList>(L, self->getList());
        int parent = lua_gettop(L);
    ]],
    AFTER = nil,
    CALLBACK_BEFORE = nil,
    CALLBACK_AFTER = nil,
})
cls.insert('addItem', {
    BEFORE = [[
        olua_push_cppobj<fairygui::GList>(L, self->getList());
        int parent = lua_gettop(L);
    ]],
    AFTER = nil,
    CALLBACK_BEFORE = nil,
    CALLBACK_AFTER = nil,
})
cls.insert('addItemAt', {
    BEFORE = [[
        olua_push_cppobj<fairygui::GList>(L, self->getList());
        int parent = lua_gettop(L);
    ]],
    AFTER = nil,
    CALLBACK_BEFORE = nil,
    CALLBACK_AFTER = nil,
})
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::Relations'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'Relations(fairygui::GObject *owner)')
cls.func(nil, 'void add(fairygui::GObject *target, fairygui::RelationType relationType)', 'void add(fairygui::GObject *target, fairygui::RelationType relationType, bool usePercent)')
cls.func(nil, 'void remove(fairygui::GObject *target, fairygui::RelationType relationType)')
cls.func(nil, 'bool contains(fairygui::GObject *target)')
cls.func(nil, 'void clearFor(fairygui::GObject *target)')
cls.func(nil, 'void clearAll()')
cls.func(nil, 'void copyFrom(const fairygui::Relations &source)')
cls.func(nil, 'void onOwnerSizeChanged(float dWidth, float dHeight, bool applyPivot)')
cls.func(nil, 'bool isEmpty()')
cls.var('handling', 'fairygui::GObject *handling')
cls.prop('empty', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::RelationType'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('Left_Left', 'fairygui::RelationType::Left_Left')
cls.enum('Left_Center', 'fairygui::RelationType::Left_Center')
cls.enum('Left_Right', 'fairygui::RelationType::Left_Right')
cls.enum('Center_Center', 'fairygui::RelationType::Center_Center')
cls.enum('Right_Left', 'fairygui::RelationType::Right_Left')
cls.enum('Right_Center', 'fairygui::RelationType::Right_Center')
cls.enum('Right_Right', 'fairygui::RelationType::Right_Right')
cls.enum('Top_Top', 'fairygui::RelationType::Top_Top')
cls.enum('Top_Middle', 'fairygui::RelationType::Top_Middle')
cls.enum('Top_Bottom', 'fairygui::RelationType::Top_Bottom')
cls.enum('Middle_Middle', 'fairygui::RelationType::Middle_Middle')
cls.enum('Bottom_Top', 'fairygui::RelationType::Bottom_Top')
cls.enum('Bottom_Middle', 'fairygui::RelationType::Bottom_Middle')
cls.enum('Bottom_Bottom', 'fairygui::RelationType::Bottom_Bottom')
cls.enum('Width', 'fairygui::RelationType::Width')
cls.enum('Height', 'fairygui::RelationType::Height')
cls.enum('LeftExt_Left', 'fairygui::RelationType::LeftExt_Left')
cls.enum('LeftExt_Right', 'fairygui::RelationType::LeftExt_Right')
cls.enum('RightExt_Left', 'fairygui::RelationType::RightExt_Left')
cls.enum('RightExt_Right', 'fairygui::RelationType::RightExt_Right')
cls.enum('TopExt_Top', 'fairygui::RelationType::TopExt_Top')
cls.enum('TopExt_Bottom', 'fairygui::RelationType::TopExt_Bottom')
cls.enum('BottomExt_Top', 'fairygui::RelationType::BottomExt_Top')
cls.enum('BottomExt_Bottom', 'fairygui::RelationType::BottomExt_Bottom')
cls.enum('Size', 'fairygui::RelationType::Size')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::RelationItem'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'RelationItem(fairygui::GObject *owner)')
cls.func(nil, '@addref(target ^) fairygui::GObject *getTarget()')
cls.func(nil, 'void setTarget(@addref(target ^) fairygui::GObject *value)')
cls.func(nil, 'void add(fairygui::RelationType relationType, bool usePercent)')
cls.func(nil, 'void internalAdd(fairygui::RelationType relationType, bool usePercent)')
cls.func(nil, 'void remove(fairygui::RelationType relationType)')
cls.func(nil, 'void copyFrom(const fairygui::RelationItem &source)')
cls.func(nil, 'bool isEmpty()')
cls.func(nil, 'void applyOnSelfSizeChanged(float dWidth, float dHeight, bool applyPivot)')
cls.prop('target', nil, nil)
cls.prop('empty', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::ScrollPane'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'ScrollPane(fairygui::GComponent *owner)')
cls.func(nil, '@addref(owner ^) fairygui::GComponent *getOwner()')
cls.func(nil, '@addref(header ^) fairygui::GComponent *getHeader()')
cls.func(nil, '@addref(footer ^) fairygui::GComponent *getFooter()')
cls.func(nil, '@addref(vtScrollBar ^) fairygui::GScrollBar *getVtScrollBar()')
cls.func(nil, '@addref(hzScrollBar ^) fairygui::GScrollBar *getHzScrollBar()')
cls.func(nil, 'bool isBouncebackEffect()')
cls.func(nil, 'void setBouncebackEffect(bool value)')
cls.func(nil, 'bool isTouchEffect()')
cls.func(nil, 'void setTouchEffect(bool value)')
cls.func(nil, 'bool isInertiaDisabled()')
cls.func(nil, 'void setInertiaDisabled(bool value)')
cls.func(nil, 'float getScrollStep()')
cls.func(nil, 'void setScrollStep(float value)')
cls.func(nil, 'bool isSnapToItem()')
cls.func(nil, 'void setSnapToItem(bool value)')
cls.func(nil, 'bool isPageMode()')
cls.func(nil, 'void setPageMode(bool value)')
cls.func(nil, '@addref(pageController ^) fairygui::GController *getPageController()')
cls.func(nil, 'void setPageController(@addref(pageController ^) fairygui::GController *value)')
cls.func(nil, 'bool isMouseWheelEnabled()')
cls.func(nil, 'void setMouseWheelEnabled(bool value)')
cls.func(nil, 'float getDecelerationRate()')
cls.func(nil, 'void setDecelerationRate(float value)')
cls.func(nil, 'float getPosX()')
cls.func(nil, 'void setPosX(float value, @optional bool ani)')
cls.func(nil, 'float getPosY()')
cls.func(nil, 'void setPosY(float value, @optional bool ani)')
cls.func(nil, 'float getPercX()')
cls.func(nil, 'void setPercX(float value, @optional bool ani)')
cls.func(nil, 'float getPercY()')
cls.func(nil, 'void setPercY(float value, @optional bool ani)')
cls.func(nil, 'bool isBottomMost()')
cls.func(nil, 'bool isRightMost()')
cls.func(nil, 'void scrollLeft(@optional float ratio, @optional bool ani)')
cls.func(nil, 'void scrollRight(@optional float ratio, @optional bool ani)')
cls.func(nil, 'void scrollUp(@optional float ratio, @optional bool ani)')
cls.func(nil, 'void scrollDown(@optional float ratio, @optional bool ani)')
cls.func(nil, 'void scrollTop(@optional bool ani)')
cls.func(nil, 'void scrollBottom(@optional bool ani)')
cls.func(nil, 'void scrollToView(fairygui::GObject *obj, @optional bool ani, @optional bool setFirst)', 'void scrollToView(const cocos2d::Rect &rect, @optional bool ani, @optional bool setFirst)')
cls.func(nil, 'bool isChildInView(fairygui::GObject *obj)')
cls.func(nil, 'int getPageX()')
cls.func(nil, 'void setPageX(int value, @optional bool ani)')
cls.func(nil, 'int getPageY()')
cls.func(nil, 'void setPageY(int value, @optional bool ani)')
cls.func(nil, 'float getScrollingPosX()')
cls.func(nil, 'float getScrollingPosY()')
cls.func(nil, 'const cocos2d::Size &getContentSize()')
cls.func(nil, 'const cocos2d::Size &getViewSize()')
cls.func(nil, 'void lockHeader(int size)')
cls.func(nil, 'void lockFooter(int size)')
cls.func(nil, 'void cancelDragging()')
cls.func(nil, 'static fairygui::ScrollPane *getDraggingPane()')
cls.prop('owner', nil, nil)
cls.prop('header', nil, nil)
cls.prop('footer', nil, nil)
cls.prop('vtScrollBar', nil, nil)
cls.prop('hzScrollBar', nil, nil)
cls.prop('bouncebackEffect', nil, nil)
cls.prop('touchEffect', nil, nil)
cls.prop('inertiaDisabled', nil, nil)
cls.prop('scrollStep', nil, nil)
cls.prop('snapToItem', nil, nil)
cls.prop('pageMode', nil, nil)
cls.prop('pageController', nil, nil)
cls.prop('mouseWheelEnabled', nil, nil)
cls.prop('decelerationRate', nil, nil)
cls.prop('posX', nil, nil)
cls.prop('posY', nil, nil)
cls.prop('percX', nil, nil)
cls.prop('percY', nil, nil)
cls.prop('bottomMost', nil, nil)
cls.prop('rightMost', nil, nil)
cls.prop('pageX', nil, nil)
cls.prop('pageY', nil, nil)
cls.prop('scrollingPosX', nil, nil)
cls.prop('scrollingPosY', nil, nil)
cls.prop('contentSize', nil, nil)
cls.prop('viewSize', nil, nil)
cls.prop('draggingPane', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::Transition'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'Transition(fairygui::GComponent *owner)')
cls.func(nil, '@addref(owner ^) fairygui::GComponent *getOwner()')
cls.func(nil, 'bool isPlaying()')
cls.func(nil, 'void changePlayTimes(int value)')
cls.func(nil, 'void stop()', 'void stop(bool setToComplete, bool processCallback)')
cls.func(nil, 'void setAutoPlay(bool autoPlay, int times, float delay)')
cls.func(nil, 'void setPaused(bool paused)')
cls.func(nil, 'void setValue(const std::string &label, const cocos2d::ValueVector &values)')
cls.func(nil, 'void setTarget(const std::string &label, fairygui::GObject *newTarget)')
cls.func(nil, 'void setDuration(const std::string &label, float value)')
cls.func(nil, 'float getLabelTime(const std::string &label)')
cls.func(nil, 'float getTimeScale()')
cls.func(nil, 'void setTimeScale(float value)')
cls.func(nil, 'void updateFromRelations(const std::string &targetId, float dx, float dy)')
cls.func(nil, 'void onOwnerAddedToStage()')
cls.func(nil, 'void onOwnerRemovedFromStage()')
cls.var('name', 'std::string name')
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
cls.prop('owner', nil, nil)
cls.prop('playing', nil, nil)
cls.prop('timeScale', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::UIConfig'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static void registerFont(const std::string &aliasName, const std::string &realName)')
cls.func(nil, 'static const std::string &getRealFontName(const std::string &aliasName, @out bool *isTTF)')
cls.var('defaultFont', 'static std::string defaultFont')
cls.var('buttonSound', 'static std::string buttonSound')
cls.var('buttonSoundVolumeScale', 'static float buttonSoundVolumeScale')
cls.var('defaultScrollStep', 'static int defaultScrollStep')
cls.var('defaultScrollDecelerationRate', 'static float defaultScrollDecelerationRate')
cls.var('defaultScrollTouchEffect', 'static bool defaultScrollTouchEffect')
cls.var('defaultScrollBounceEffect', 'static bool defaultScrollBounceEffect')
cls.var('defaultScrollBarDisplay', 'static fairygui::ScrollBarDisplayType defaultScrollBarDisplay')
cls.var('verticalScrollBar', 'static std::string verticalScrollBar')
cls.var('horizontalScrollBar', 'static std::string horizontalScrollBar')
cls.var('touchDragSensitivity', 'static int touchDragSensitivity')
cls.var('clickDragSensitivity', 'static int clickDragSensitivity')
cls.var('touchScrollSensitivity', 'static int touchScrollSensitivity')
cls.var('defaultComboBoxVisibleItemCount', 'static int defaultComboBoxVisibleItemCount')
cls.var('globalModalWaiting', 'static std::string globalModalWaiting')
cls.var('modalLayerColor', 'static cocos2d::Color4F modalLayerColor')
cls.var('tooltipsWin', 'static std::string tooltipsWin')
cls.var('bringWindowToFrontOnClick', 'static bool bringWindowToFrontOnClick')
cls.var('windowModalWaiting', 'static std::string windowModalWaiting')
cls.var('popupMenu', 'static std::string popupMenu')
cls.var('popupMenu_seperator', 'static std::string popupMenu_seperator')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::IUISource'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'const std::string &getFileName()')
cls.func(nil, 'void setFileName(const std::string &value)')
cls.func(nil, 'bool isLoaded()')
cls.callback {
    FUNCS =  {
        'void load(@nullable @local std::function<void ()> callback)'
    },
    TAG_MAKER = 'load',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.prop('fileName', nil, nil)
cls.prop('loaded', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::UISource'
cls.SUPERCLS = 'fairygui::IUISource'
cls.REG_LUATYPE = true
cls.DEFIF = nil
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
cls.func('create', 'static UISource *create()')
cls.func('loadComplete', 'void loadComplete()')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::Window'
cls.SUPERCLS = 'fairygui::GComponent'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'Window()')
cls.func(nil, 'static fairygui::Window *create()')
cls.func(nil, '@delref(children ~ parent)@addref(children | parent) void show()')
cls.func(nil, '@delref(children ~ parent) void hide()')
cls.func(nil, '@delref(children ~ parent) void hideImmediately()')
cls.func(nil, 'void toggleStatus()')
cls.func(nil, 'void bringToFront()')
cls.func(nil, 'bool isShowing()')
cls.func(nil, 'bool isTop()')
cls.func(nil, 'bool isModal()')
cls.func(nil, 'void setModal(bool value)')
cls.func(nil, 'void showModalWait()', 'void showModalWait(int requestingCmd)')
cls.func(nil, 'bool closeModalWait()', 'bool closeModalWait(int requestingCmd)')
cls.func(nil, 'void initWindow()')
cls.func(nil, 'void addUISource(fairygui::IUISource *uiSource)')
cls.func(nil, 'bool isBringToFrontOnClick()')
cls.func(nil, 'void setBringToFrontOnClick(bool value)')
cls.func(nil, '@addref(contentPane ^) fairygui::GComponent *getContentPane()')
cls.func(nil, 'void setContentPane(@addref(contentPane ^) fairygui::GComponent *value)')
cls.func(nil, '@addref(frame ^) fairygui::GComponent *getFrame()')
cls.func(nil, '@addref(closeButton ^) fairygui::GObject *getCloseButton()')
cls.func(nil, 'void setCloseButton(@addref(closeButton ^) fairygui::GObject *value)')
cls.func(nil, '@addref(dragArea ^) fairygui::GObject *getDragArea()')
cls.func(nil, 'void setDragArea(@addref(dragArea ^) fairygui::GObject *value)')
cls.func(nil, '@addref(contentArea ^) fairygui::GObject *getContentArea()')
cls.func(nil, 'void setContentArea(@addref(contentArea ^) fairygui::GObject *value)')
cls.func(nil, '@addref(modalWaitingPane ^) fairygui::GObject *getModalWaitingPane()')
cls.prop('showing', nil, nil)
cls.prop('top', nil, nil)
cls.prop('modal', nil, nil)
cls.prop('bringToFrontOnClick', nil, nil)
cls.prop('contentPane', nil, nil)
cls.prop('frame', nil, nil)
cls.prop('closeButton', nil, nil)
cls.prop('dragArea', nil, nil)
cls.prop('contentArea', nil, nil)
cls.prop('modalWaitingPane', nil, nil)
cls.insert('show', {
    BEFORE = [[
        fairygui::GComponent *root = fairygui::UIRoot;
        if (!root) {
            luaL_error(L, "no root to add 'Window'");
        }
        olua_push_cppobj<fairygui::GComponent>(L, root);
        int parent = lua_gettop(L);
    ]],
    AFTER = nil,
    CALLBACK_BEFORE = nil,
    CALLBACK_AFTER = nil,
})
cls.insert('hide', {
    BEFORE = [[
        fairygui::GComponent *root = self->getParent() ? self->getParent() : fairygui::UIRoot;
        if (!root) {
            return 0;
        }
        olua_push_cppobj<fairygui::GComponent>(L, root);
        int parent = lua_gettop(L);
    ]],
    AFTER = nil,
    CALLBACK_BEFORE = nil,
    CALLBACK_AFTER = nil,
})
cls.insert('hideImmediately', {
    BEFORE = [[
        fairygui::GComponent *root = self->getParent() ? self->getParent() : fairygui::UIRoot;
        if (!root) {
            return 0;
        }
        olua_push_cppobj<fairygui::GComponent>(L, root);
        int parent = lua_gettop(L);
    ]],
    AFTER = nil,
    CALLBACK_BEFORE = nil,
    CALLBACK_AFTER = nil,
})
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::DragDropManager'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'DragDropManager()')
cls.func(nil, 'static fairygui::DragDropManager *getInstance()')
cls.func(nil, 'fairygui::GLoader *getAgent()')
cls.func(nil, 'bool isDragging()')
cls.func(nil, 'void startDrag(const std::string &icon, @optional const cocos2d::Value &sourceData, @optional int touchPointID)')
cls.func(nil, 'void cancel()')
cls.prop('instance', nil, nil)
cls.prop('agent', nil, nil)
cls.prop('dragging', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::UIObjectFactory'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static fairygui::GObject *newObject(fairygui::PackageItem *pi)', 'static fairygui::GObject *newObject(fairygui::ObjectType type)')
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
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'GearBase(fairygui::GObject *owner)')
cls.func(nil, 'static fairygui::GearBase *create(fairygui::GObject *owner, int index)')
cls.var('disableAllTweenEffect', 'static bool disableAllTweenEffect')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::GTreeNode'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static fairygui::GTreeNode *create(@optional bool isFolder, @optional const std::string &resURL)')
cls.func(nil, 'GTreeNode()')
cls.func(nil, 'fairygui::GTreeNode *getParent()')
cls.func(nil, 'fairygui::GTree *getTree()')
cls.func(nil, '@addref(cell ^) fairygui::GComponent *getCell()')
cls.func(nil, 'const cocos2d::Value &getData()')
cls.func(nil, 'void setData(const cocos2d::Value &value)')
cls.func(nil, 'bool isExpanded()')
cls.func(nil, 'void setExpaned(bool value)')
cls.func(nil, 'bool isFolder()')
cls.func(nil, 'const std::string &getText()')
cls.func(nil, 'void setText(const std::string &value)')
cls.func(nil, 'const std::string &getIcon()')
cls.func(nil, 'void setIcon(const std::string &value)')
cls.func(nil, 'fairygui::GTreeNode *addChild(@addref(children |) fairygui::GTreeNode *child)')
cls.func(nil, 'fairygui::GTreeNode *addChildAt(@addref(children |) fairygui::GTreeNode *child, int index)')
cls.func(nil, 'void removeChild(@delref(children |) fairygui::GTreeNode *child)')
cls.func(nil, '@delref(children ~) void removeChildAt(int index)')
cls.func(nil, '@delref(children ~) void removeChildren()', '@delref(children ~) void removeChildren(int beginIndex, int endIndex)')
cls.func(nil, '@addref(children |) fairygui::GTreeNode *getChildAt(int index)')
cls.func(nil, '@addref(children |) fairygui::GTreeNode *getPrevSibling()')
cls.func(nil, '@addref(children |) fairygui::GTreeNode *getNextSibling()')
cls.func(nil, 'int getChildIndex(const fairygui::GTreeNode *child)')
cls.func(nil, 'void setChildIndex(fairygui::GTreeNode *child, int index)')
cls.func(nil, 'int setChildIndexBefore(fairygui::GTreeNode *child, int index)')
cls.func(nil, 'void swapChildren(fairygui::GTreeNode *child1, fairygui::GTreeNode *child2)')
cls.func(nil, 'void swapChildrenAt(int index1, int index2)')
cls.func(nil, 'int numChildren()')
cls.prop('numChildren', 'int numChildren()', nil)
cls.prop('parent', nil, nil)
cls.prop('tree', nil, nil)
cls.prop('cell', nil, nil)
cls.prop('data', nil, nil)
cls.prop('expanded', nil, nil)
cls.prop('folder', nil, nil)
cls.prop('text', nil, nil)
cls.prop('icon', nil, nil)
cls.prop('prevSibling', nil, nil)
cls.prop('nextSibling', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::GTree'
cls.SUPERCLS = 'fairygui::GList'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'GTree()')
cls.func(nil, 'static fairygui::GTree *create()')
cls.func(nil, 'int getIndent()')
cls.func(nil, 'void setIndent(int value)')
cls.func(nil, 'int getClickToExpand()')
cls.func(nil, 'void setClickToExpand(int value)')
cls.func(nil, '@addref(rootNode ^) fairygui::GTreeNode *getRootNode()')
cls.func(nil, 'fairygui::GTreeNode *getSelectedNode()')
cls.func(nil, 'void getSelectedNodes(@out std::vector<GTreeNode *> &result)')
cls.func(nil, 'void selectNode(fairygui::GTreeNode *node, @optional bool scrollItToView)')
cls.func(nil, 'void unselectNode(fairygui::GTreeNode *node)')
cls.func(nil, 'void expandAll(fairygui::GTreeNode *folderNode)')
cls.func(nil, 'void collapseAll(fairygui::GTreeNode *folderNode)')
cls.var('treeNodeRender', '@nullable std::function<void (GTreeNode *, GComponent *)> treeNodeRender')
cls.var('treeNodeWillExpand', '@nullable std::function<void (GTreeNode *, bool)> treeNodeWillExpand')
cls.prop('indent', nil, nil)
cls.prop('clickToExpand', nil, nil)
cls.prop('rootNode', nil, nil)
cls.prop('selectedNode', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::FUIContainer'
cls.SUPERCLS = 'cocos2d::Node'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'FUIContainer()')
cls.func(nil, 'static fairygui::FUIContainer *create()')
cls.func(nil, 'bool isClippingEnabled()')
cls.func(nil, 'void setClippingEnabled(bool value)')
cls.func(nil, 'const cocos2d::Rect &getClippingRegion()')
cls.func(nil, 'void setClippingRegion(const cocos2d::Rect &clippingRegion)')
cls.func(nil, 'cocos2d::Node *getStencil()')
cls.func(nil, 'void setStencil(cocos2d::Node *stencil)')
cls.func(nil, 'float getAlphaThreshold()')
cls.func(nil, 'void setAlphaThreshold(float alphaThreshold)')
cls.func(nil, 'bool isInverted()')
cls.func(nil, 'void setInverted(bool inverted)')
cls.var('gOwner', 'fairygui::GObject *gOwner')
cls.prop('clippingEnabled', nil, nil)
cls.prop('clippingRegion', nil, nil)
cls.prop('stencil', nil, nil)
cls.prop('alphaThreshold', nil, nil)
cls.prop('inverted', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::FUIInput'
cls.SUPERCLS = 'cocos2d::ui::EditBox'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static fairygui::FUIInput *create()')
cls.func(nil, 'FUIInput()')
cls.func(nil, 'void setText(const std::string &value)')
cls.func(nil, 'fairygui::TextFormat *getTextFormat()')
cls.func(nil, 'void applyTextFormat()')
cls.func(nil, 'bool isSingleLine()')
cls.func(nil, 'void setSingleLine(bool value)')
cls.func(nil, 'bool isPassword()')
cls.func(nil, 'void setPassword(bool value)')
cls.func(nil, 'int keyboardType()')
cls.func(nil, 'void setKeyboardType(int value)')
cls.prop('textFormat', nil, nil)
cls.prop('singleLine', nil, nil)
cls.prop('password', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::FUILabel'
cls.SUPERCLS = 'cocos2d::Label'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'FUILabel()')
cls.func(nil, 'static fairygui::FUILabel *create()')
cls.func(nil, 'const std::string &getText()')
cls.func(nil, 'void setText(const std::string &value)')
cls.func(nil, 'fairygui::TextFormat *getTextFormat()')
cls.func(nil, 'void applyTextFormat()')
cls.func(nil, 'void setUnderlineColor(const cocos2d::Color3B &value)')
cls.func(nil, 'void setGrayed(bool value)')
cls.prop('text', nil, nil)
cls.prop('textFormat', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::FUIRichText'
cls.SUPERCLS = 'cocos2d::Node'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'FUIRichText()')
cls.func(nil, 'static fairygui::FUIRichText *create()')
cls.func(nil, 'const cocos2d::Size &getDimensions()')
cls.func(nil, 'void setDimensions(float width, float height)')
cls.func(nil, 'void setText(const std::string &value)')
cls.func(nil, 'fairygui::TextFormat *getTextFormat()')
cls.func(nil, 'void applyTextFormat()')
cls.func(nil, 'cocos2d::Label::Overflow getOverflow()')
cls.func(nil, 'void setOverflow(cocos2d::Label::Overflow overflow)')
cls.func(nil, 'bool isAnchorTextUnderline()')
cls.func(nil, 'void setAnchorTextUnderline(bool enable)')
cls.func(nil, 'const cocos2d::Color3B &getAnchorFontColor()')
cls.func(nil, 'void setAnchorFontColor(const cocos2d::Color3B &color)')
cls.func(nil, 'fairygui::HtmlParseOptions &parseOptions()')
cls.func(nil, 'const std::vector<HtmlObject *> &getControls()')
cls.func(nil, 'fairygui::HtmlObject *getControl(const std::string &name)')
cls.func(nil, 'const char *hitTestLink(const cocos2d::Vec2 &worldPoint)')
cls.callback {
    FUNCS =  {
        'void setObjectFactory(@local const std::function<HtmlObject *(HtmlElement *)> &value)'
    },
    TAG_MAKER = 'ObjectFactory',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.prop('dimensions', nil, nil)
cls.prop('textFormat', nil, nil)
cls.prop('overflow', nil, nil)
cls.prop('anchorTextUnderline', nil, nil)
cls.prop('anchorFontColor', nil, nil)
cls.prop('controls', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::FUISprite'
cls.SUPERCLS = 'cocos2d::Sprite'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'FUISprite()')
cls.func(nil, 'static fairygui::FUISprite *create()')
cls.func(nil, 'void clearContent()')
cls.func(nil, 'void setScale9Grid(cocos2d::Rect *value)')
cls.func(nil, 'void setGrayed(bool value)')
cls.func(nil, 'fairygui::FillMethod getFillMethod()')
cls.func(nil, 'void setFillMethod(fairygui::FillMethod value)')
cls.func(nil, 'fairygui::FillOrigin getFillOrigin()')
cls.func(nil, 'void setFillOrigin(fairygui::FillOrigin value)')
cls.func(nil, 'bool isFillClockwise()')
cls.func(nil, 'void setFillClockwise(bool value)')
cls.func(nil, 'float getFillAmount()')
cls.func(nil, 'void setFillAmount(float value)')
cls.func(nil, 'bool isScaleByTile()')
cls.func(nil, 'void setScaleByTile(bool value)')
cls.prop('fillMethod', nil, nil)
cls.prop('fillOrigin', nil, nil)
cls.prop('fillClockwise', nil, nil)
cls.prop('fillAmount', nil, nil)
cls.prop('scaleByTile', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::HtmlObject'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'HtmlObject()')
cls.func(nil, 'fairygui::HtmlElement *getElement()')
cls.func(nil, 'fairygui::GObject *getUI()')
cls.func(nil, 'bool isHidden()')
cls.func(nil, 'void create(fairygui::FUIRichText *owner, fairygui::HtmlElement *element)')
cls.func(nil, 'void destroy()')
cls.var('buttonResource', 'static std::string buttonResource')
cls.var('inputResource', 'static std::string inputResource')
cls.var('selectResource', 'static std::string selectResource')
cls.var('usePool', 'static bool usePool')
cls.var('loaderPool', 'static cocos2d::Vector<GObject *> loaderPool')
cls.prop('element', nil, nil)
cls.prop('ui', nil, nil)
cls.prop('hidden', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::HtmlElement::Type'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('TEXT', 'fairygui::HtmlElement::Type::TEXT')
cls.enum('IMAGE', 'fairygui::HtmlElement::Type::IMAGE')
cls.enum('LINK', 'fairygui::HtmlElement::Type::LINK')
cls.enum('INPUT', 'fairygui::HtmlElement::Type::INPUT')
cls.enum('SELECT', 'fairygui::HtmlElement::Type::SELECT')
cls.enum('OBJECT', 'fairygui::HtmlElement::Type::OBJECT')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'fairygui::HtmlElement'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'HtmlElement(fairygui::HtmlElement::Type type)')
cls.func(nil, 'int getInt(const std::string &attrName, @optional int defValue)')
cls.func(nil, 'std::string getString(const std::string &attrName, @optional const std::string &defValue)')
cls.func(nil, 'cocos2d::ValueVector &getArray(const std::string &attrName)')
cls.var('type', 'fairygui::HtmlElement::Type type')
cls.var('text', 'std::string text')
cls.var('format', 'fairygui::TextFormat format')
cls.var('link', 'fairygui::HtmlElement *link')
cls.var('obj', 'fairygui::HtmlObject *obj')
cls.var('space', 'int space')
cls.var('attrs', 'cocos2d::ValueMap attrs')
M.CLASSES[#M.CLASSES + 1] = cls

return M
