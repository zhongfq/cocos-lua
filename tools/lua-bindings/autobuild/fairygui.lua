-- AUTO BUILD, DON'T MODIFY!

dofile "autobuild/fairygui-types.lua"

name = "fairygui"
path = "../../frameworks/libxgame/src/lua-bindings"
headers = [[
    #include "lua-bindings/lua_conv.h"
    #include "lua-bindings/lua_conv_manual.h"
    #include "FairyGUI.h"
    #include "GLoader3D.h"
    #include "tween/EaseManager.h"
    #include "tween/GPath.h"
    #include "display/FUISprite.h"
    #include "utils/html/HtmlElement.h"
    #include "utils/html/HtmlObject.h"
    #include "utils/html/HtmlParser.h"
]]
chunk = [[
    bool olua_is_fairygui_EventTag(lua_State *L, int idx)
    {
        return olua_isinteger(L, idx) || olua_isa<void>(L, idx);
    }

    void olua_check_fairygui_EventTag(lua_State *L, int idx, fairygui::EventTag *value)
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
luaopen = [[cclua::runtime::registerFeature("fairygui", true);]]

typeconv 'fairygui::Margin'
    .var('left', 'float left')
    .var('top', 'float top')
    .var('right', 'float right')
    .var('bottom', 'float bottom')

typeconv 'fairygui::HtmlParseOptions'
    .var('defaultLinkUnderline', 'static bool defaultLinkUnderline')
    .var('defaultLinkColor', 'static cocos2d::Color3B defaultLinkColor')
    .var('linkUnderline', 'bool linkUnderline')
    .var('linkColor', 'cocos2d::Color3B linkColor')

typeconv 'fairygui::TweenValue'
    .var('x', '@optional float x')
    .var('y', '@optional float y')
    .var('z', '@optional float z')
    .var('w', '@optional float w')
    .var('d', '@optional double d')


typeconf 'fairygui::UIEventType'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror('r')
    .const('Enter', 'fairygui::UIEventType::Enter', 'const int')
    .const('Exit', 'fairygui::UIEventType::Exit', 'const int')
    .const('Changed', 'fairygui::UIEventType::Changed', 'const int')
    .const('Submit', 'fairygui::UIEventType::Submit', 'const int')
    .const('TouchBegin', 'fairygui::UIEventType::TouchBegin', 'const int')
    .const('TouchMove', 'fairygui::UIEventType::TouchMove', 'const int')
    .const('TouchEnd', 'fairygui::UIEventType::TouchEnd', 'const int')
    .const('Click', 'fairygui::UIEventType::Click', 'const int')
    .const('RollOver', 'fairygui::UIEventType::RollOver', 'const int')
    .const('RollOut', 'fairygui::UIEventType::RollOut', 'const int')
    .const('MouseWheel', 'fairygui::UIEventType::MouseWheel', 'const int')
    .const('RightClick', 'fairygui::UIEventType::RightClick', 'const int')
    .const('MiddleClick', 'fairygui::UIEventType::MiddleClick', 'const int')
    .const('PositionChange', 'fairygui::UIEventType::PositionChange', 'const int')
    .const('SizeChange', 'fairygui::UIEventType::SizeChange', 'const int')
    .const('KeyDown', 'fairygui::UIEventType::KeyDown', 'const int')
    .const('KeyUp', 'fairygui::UIEventType::KeyUp', 'const int')
    .const('Scroll', 'fairygui::UIEventType::Scroll', 'const int')
    .const('ScrollEnd', 'fairygui::UIEventType::ScrollEnd', 'const int')
    .const('PullDownRelease', 'fairygui::UIEventType::PullDownRelease', 'const int')
    .const('PullUpRelease', 'fairygui::UIEventType::PullUpRelease', 'const int')
    .const('ClickItem', 'fairygui::UIEventType::ClickItem', 'const int')
    .const('ClickLink', 'fairygui::UIEventType::ClickLink', 'const int')
    .const('ClickMenu', 'fairygui::UIEventType::ClickMenu', 'const int')
    .const('RightClickItem', 'fairygui::UIEventType::RightClickItem', 'const int')
    .const('DragStart', 'fairygui::UIEventType::DragStart', 'const int')
    .const('DragMove', 'fairygui::UIEventType::DragMove', 'const int')
    .const('DragEnd', 'fairygui::UIEventType::DragEnd', 'const int')
    .const('Drop', 'fairygui::UIEventType::Drop', 'const int')
    .const('GearStop', 'fairygui::UIEventType::GearStop', 'const int')

typeconf 'fairygui::EventCallback'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror(nil)

typeconf 'fairygui::UIEventDispatcher'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk([[
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
                snprintf(buf, sizeof(buf), "listeners.");
            } else if (tag > 0) {
                snprintf(buf, sizeof(buf), "listeners.%d.%p", (int)type, (void *)tag);
            } else {
                snprintf(buf, sizeof(buf), "listeners.%d.", (int)type);
            }
            return std::string(buf);
        }
    ]])
    .luaopen(nil)
    .indexerror(nil)
    .func(nil, 'UIEventDispatcher()')
    .func(nil, 'bool hasEventListener(int eventType)', 'bool hasEventListener(int eventType, const fairygui::EventTag &tag)')
    .func(nil, 'bool dispatchEvent(int eventType, @optional void *data, @optional const cocos2d::Value &dataValue)')
    .func(nil, 'bool bubbleEvent(int eventType, @optional void *data, @optional const cocos2d::Value &dataValue)')
    .func(nil, 'bool isDispatchingEvent(int eventType)')
    .callback {
        funcs =  {
            'void addEventListener(int eventType, @localvar const fairygui::EventCallback &callback)',
            'void addEventListener(int eventType, @localvar const fairygui::EventCallback &callback, const fairygui::EventTag &tag)'
        },
        tag_maker = {'makeListenerTag(L, #1, 0)', 'makeListenerTag(L, #1, 4)'},
        tag_mode = 'new',
        tag_store = 0,
        tag_scope = 'object',
    }
    .callback {
        funcs =  {
            'void removeEventListener(int eventType)',
            'void removeEventListener(int eventType, const fairygui::EventTag &tag)'
        },
        tag_maker = {'makeListenerTag(L, #1, 0)', 'makeListenerTag(L, #1, 3)'},
        tag_mode = {'substartwith', 'subequal'},
        tag_store = 0,
        tag_scope = 'object',
    }
    .callback {
        funcs =  {
            'void removeEventListeners()'
        },
        tag_maker = 'makeListenerTag(L, -1, 0)',
        tag_mode = 'substartwith',
        tag_store = 0,
        tag_scope = 'object',
    }

typeconf 'fairygui::EventContext'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror(nil)
    .func(nil, 'EventContext()')
    .func(nil, 'int getType()')
    .func(nil, 'cocos2d::Ref *getSender()')
    .func(nil, 'fairygui::InputEvent *getInput()')
    .func(nil, 'void stopPropagation()')
    .func(nil, 'void preventDefault()')
    .func(nil, 'bool isDefaultPrevented()')
    .func(nil, 'void captureTouch()')
    .func(nil, 'void uncaptureTouch()')
    .func(nil, 'const cocos2d::Value &getDataValue()')
    .func(nil, 'void *getData()')
    .prop('type', nil, nil)
    .prop('sender', nil, nil)
    .prop('input', nil, nil)
    .prop('defaultPrevented', nil, nil)
    .prop('dataValue', nil, nil)
    .prop('data', nil, nil)

typeconf 'fairygui::IHitTest'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror(nil)
    .func(nil, 'bool hitTest(fairygui::GComponent *obj, const cocos2d::Vec2 &localPoint)')

typeconf 'fairygui::PixelHitTest'
    .supercls('fairygui::IHitTest')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror(nil)
    .func(nil, 'PixelHitTest(fairygui::PixelHitTestData *data, int offsetX, int offsetY)')
    .var('offsetX', 'int offsetX')
    .var('offsetY', 'int offsetY')
    .var('scaleX', 'float scaleX')
    .var('scaleY', 'float scaleY')

typeconf 'fairygui::PixelHitTestData'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror(nil)
    .func(nil, 'PixelHitTestData()')
    .var('pixelWidth', 'int pixelWidth')
    .var('scale', 'float scale')
    .var('pixels', 'unsigned char *pixels')
    .var('pixelsLength', 'size_t pixelsLength')

typeconf 'fairygui::InputProcessor::CaptureEventCallback'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror(nil)

typeconf 'fairygui::InputProcessor'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror(nil)
    .func(nil, 'fairygui::InputEvent *getRecentInput()')
    .func(nil, 'static bool isTouchOnUI()')
    .func(nil, 'InputProcessor(fairygui::GComponent *owner)')
    .func(nil, 'cocos2d::Vec2 getTouchPosition(int touchId)')
    .func(nil, 'void addTouchMonitor(int touchId, fairygui::GObject *target)')
    .func(nil, 'void removeTouchMonitor(fairygui::GObject *target)')
    .func(nil, 'void cancelClick(int touchId)')
    .func(nil, 'void simulateClick(fairygui::GObject *target, @optional int touchId)')
    .func(nil, 'void disableDefaultTouchEvent()')
    .func(nil, 'bool touchDown(cocos2d::Touch *touch, cocos2d::Event *event)')
    .func(nil, 'void touchMove(cocos2d::Touch *touch, cocos2d::Event *event)')
    .func(nil, 'void touchUp(cocos2d::Touch *touch, cocos2d::Event *event)')
    .callback {
        funcs =  {
            'void setCaptureCallback(@localvar @nullable fairygui::InputProcessor::CaptureEventCallback value)'
        },
        tag_maker = 'CaptureCallback',
        tag_mode = 'replace',
        tag_store = 0,
        tag_scope = 'object',
    }
    .prop('recentInput', nil, nil)
    .prop('touchOnUI', nil, nil)

typeconf 'fairygui::InputEvent'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror(nil)
    .func(nil, 'InputEvent()')
    .func(nil, 'fairygui::GObject *getTarget()')
    .func(nil, 'const int getX()')
    .func(nil, 'const int getY()')
    .func(nil, 'const cocos2d::Vec2 &getPosition()')
    .func(nil, 'cocos2d::Touch *getTouch()')
    .func(nil, 'int getTouchId()')
    .func(nil, 'int isDoubleClick()')
    .func(nil, 'cocos2d::EventMouse::MouseButton getButton()')
    .func(nil, 'cocos2d::EventKeyboard::KeyCode getKeyCode()')
    .func(nil, 'bool isCtrlDown()')
    .func(nil, 'bool isAltDown()')
    .func(nil, 'bool isShiftDown()')
    .func(nil, 'int getMouseWheelDelta()')
    .func(nil, 'fairygui::InputProcessor *getProcessor()')
    .prop('target', nil, nil)
    .prop('x', nil, nil)
    .prop('y', nil, nil)
    .prop('position', nil, nil)
    .prop('touch', nil, nil)
    .prop('touchId', nil, nil)
    .prop('doubleClick', nil, nil)
    .prop('button', nil, nil)
    .prop('keyCode', nil, nil)
    .prop('ctrlDown', nil, nil)
    .prop('altDown', nil, nil)
    .prop('shiftDown', nil, nil)
    .prop('mouseWheelDelta', nil, nil)
    .prop('processor', nil, nil)

typeconf 'fairygui::TextFormat'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror(nil)
    .const('OUTLINE', 'fairygui::TextFormat::OUTLINE', 'const int')
    .const('SHADOW', 'fairygui::TextFormat::SHADOW', 'const int')
    .const('GLOW', 'fairygui::TextFormat::GLOW', 'const int')
    .func(nil, 'TextFormat()')
    .func(nil, 'void setFormat(const fairygui::TextFormat &format)')
    .func(nil, 'void enableEffect(int effectFlag)')
    .func(nil, 'void disableEffect(int effectFlag)')
    .func(nil, 'bool hasEffect(int effectFlag)')
    .var('face', 'std::string face')
    .var('fontSize', 'float fontSize')
    .var('color', 'cocos2d::Color3B color')
    .var('bold', 'bool bold')
    .var('italics', 'bool italics')
    .var('underline', 'bool underline')
    .var('lineSpacing', 'int lineSpacing')
    .var('letterSpacing', 'int letterSpacing')
    .var('align', 'cocos2d::TextHAlignment align')
    .var('verticalAlign', 'cocos2d::TextVAlignment verticalAlign')
    .var('effect', 'int effect')
    .var('outlineColor', 'cocos2d::Color3B outlineColor')
    .var('outlineSize', 'int outlineSize')
    .var('shadowColor', 'cocos2d::Color3B shadowColor')
    .var('shadowOffset', 'cocos2d::Size shadowOffset')
    .var('shadowBlurRadius', 'int shadowBlurRadius')
    .var('glowColor', 'cocos2d::Color3B glowColor')

typeconf 'fairygui::EaseType'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror('rw')
    .enum('Linear', 'fairygui::EaseType::Linear')
    .enum('SineIn', 'fairygui::EaseType::SineIn')
    .enum('SineOut', 'fairygui::EaseType::SineOut')
    .enum('SineInOut', 'fairygui::EaseType::SineInOut')
    .enum('QuadIn', 'fairygui::EaseType::QuadIn')
    .enum('QuadOut', 'fairygui::EaseType::QuadOut')
    .enum('QuadInOut', 'fairygui::EaseType::QuadInOut')
    .enum('CubicIn', 'fairygui::EaseType::CubicIn')
    .enum('CubicOut', 'fairygui::EaseType::CubicOut')
    .enum('CubicInOut', 'fairygui::EaseType::CubicInOut')
    .enum('QuartIn', 'fairygui::EaseType::QuartIn')
    .enum('QuartOut', 'fairygui::EaseType::QuartOut')
    .enum('QuartInOut', 'fairygui::EaseType::QuartInOut')
    .enum('QuintIn', 'fairygui::EaseType::QuintIn')
    .enum('QuintOut', 'fairygui::EaseType::QuintOut')
    .enum('QuintInOut', 'fairygui::EaseType::QuintInOut')
    .enum('ExpoIn', 'fairygui::EaseType::ExpoIn')
    .enum('ExpoOut', 'fairygui::EaseType::ExpoOut')
    .enum('ExpoInOut', 'fairygui::EaseType::ExpoInOut')
    .enum('CircIn', 'fairygui::EaseType::CircIn')
    .enum('CircOut', 'fairygui::EaseType::CircOut')
    .enum('CircInOut', 'fairygui::EaseType::CircInOut')
    .enum('ElasticIn', 'fairygui::EaseType::ElasticIn')
    .enum('ElasticOut', 'fairygui::EaseType::ElasticOut')
    .enum('ElasticInOut', 'fairygui::EaseType::ElasticInOut')
    .enum('BackIn', 'fairygui::EaseType::BackIn')
    .enum('BackOut', 'fairygui::EaseType::BackOut')
    .enum('BackInOut', 'fairygui::EaseType::BackInOut')
    .enum('BounceIn', 'fairygui::EaseType::BounceIn')
    .enum('BounceOut', 'fairygui::EaseType::BounceOut')
    .enum('BounceInOut', 'fairygui::EaseType::BounceInOut')
    .enum('Custom', 'fairygui::EaseType::Custom')

typeconf 'fairygui::EaseManager'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror(nil)
    .func(nil, 'static float evaluate(fairygui::EaseType easeType, float time, float duration, float overshootOrAmplitude, float period)')

typeconf 'fairygui::TweenPropType'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror('rw')
    .enum('None', 'fairygui::TweenPropType::None')
    .enum('X', 'fairygui::TweenPropType::X')
    .enum('Y', 'fairygui::TweenPropType::Y')
    .enum('Position', 'fairygui::TweenPropType::Position')
    .enum('Width', 'fairygui::TweenPropType::Width')
    .enum('Height', 'fairygui::TweenPropType::Height')
    .enum('Size', 'fairygui::TweenPropType::Size')
    .enum('ScaleX', 'fairygui::TweenPropType::ScaleX')
    .enum('ScaleY', 'fairygui::TweenPropType::ScaleY')
    .enum('Scale', 'fairygui::TweenPropType::Scale')
    .enum('Rotation', 'fairygui::TweenPropType::Rotation')
    .enum('Alpha', 'fairygui::TweenPropType::Alpha')
    .enum('Progress', 'fairygui::TweenPropType::Progress')

typeconf 'fairygui::GPath'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror(nil)

typeconf 'fairygui::GTweener::GTweenCallback'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror(nil)

typeconf 'fairygui::GTweener::GTweenCallback0'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror(nil)

typeconf 'fairygui::GTweener'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror(nil)
    .func(nil, 'GTweener()')
    .func(nil, 'fairygui::GTweener *setDelay(float value)')
    .func(nil, 'float getDelay()')
    .func(nil, 'fairygui::GTweener *setDuration(float value)')
    .func(nil, 'float getDuration()')
    .func(nil, 'fairygui::GTweener *setBreakpoint(float value)')
    .func(nil, 'fairygui::GTweener *setEase(fairygui::EaseType value)')
    .func(nil, 'fairygui::GTweener *setEasePeriod(float value)')
    .func(nil, 'fairygui::GTweener *setEaseOvershootOrAmplitude(float value)')
    .func(nil, 'fairygui::GTweener *setRepeat(int repeat, @optional bool yoyo)')
    .func(nil, 'int getRepeat()')
    .func(nil, 'fairygui::GTweener *setTimeScale(float value)')
    .func(nil, 'fairygui::GTweener *setSnapping(bool value)')
    .func(nil, 'fairygui::GTweener *setTargetAny(void *value)')
    .func(nil, 'fairygui::GTweener *setTarget(cocos2d::Ref *target)', 'fairygui::GTweener *setTarget(cocos2d::Ref *target, fairygui::TweenPropType propType)')
    .func(nil, 'void *getTarget()')
    .func(nil, 'fairygui::GTweener *setUserData(const cocos2d::Value &value)')
    .func(nil, 'fairygui::GTweener *setPath(fairygui::GPath *path)')
    .func(nil, 'const cocos2d::Value &getUserData()')
    .func(nil, 'float getNormalizedTime()')
    .func(nil, 'bool isCompleted()')
    .func(nil, 'bool allCompleted()')
    .func(nil, 'fairygui::GTweener *setPaused(bool paused)')
    .func(nil, 'void seek(float time)')
    .func(nil, 'void kill(@optional bool complete)')
    .var('startValue', 'fairygui::TweenValue startValue')
    .var('endValue', 'fairygui::TweenValue endValue')
    .var('value', 'fairygui::TweenValue value')
    .var('deltaValue', 'fairygui::TweenValue deltaValue')
    .callback {
        funcs =  {
            'fairygui::GTweener *onUpdate(fairygui::GTweener::GTweenCallback callback)'
        },
        tag_maker = 'onUpdate',
        tag_mode = 'replace',
        tag_store = 0,
        tag_scope = 'object',
    }
    .callback {
        funcs =  {
            'fairygui::GTweener *onStart(fairygui::GTweener::GTweenCallback callback)'
        },
        tag_maker = 'onStart',
        tag_mode = 'replace',
        tag_store = 0,
        tag_scope = 'object',
    }
    .callback {
        funcs =  {
            'fairygui::GTweener *onComplete(fairygui::GTweener::GTweenCallback0 callback)'
        },
        tag_maker = 'onComplete',
        tag_mode = 'replace',
        tag_store = 0,
        tag_scope = 'object',
    }
    .callback {
        funcs =  {
            'fairygui::GTweener *onComplete1(fairygui::GTweener::GTweenCallback callback)'
        },
        tag_maker = 'onComplete1',
        tag_mode = 'replace',
        tag_store = 0,
        tag_scope = 'object',
    }
    .prop('delay', nil, nil)
    .prop('duration', nil, nil)
    .prop('repeat', nil, nil)
    .prop('target', nil, nil)
    .prop('userData', nil, nil)
    .prop('normalizedTime', nil, nil)
    .prop('completed', nil, nil)

typeconf 'fairygui::GTween'
    .supercls(nil)
    .reg_luatype(true)
    .chunk([[
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
    ]])
    .luaopen(nil)
    .indexerror(nil)
    .func(nil, 'static fairygui::GTweener *to(float startValue, float endValue, float duration)', 'static fairygui::GTweener *to(const cocos2d::Vec2 &startValue, const cocos2d::Vec2 &endValue, float duration)', 'static fairygui::GTweener *to(const cocos2d::Vec3 &startValue, const cocos2d::Vec3 &endValue, float duration)', 'static fairygui::GTweener *to(const cocos2d::Vec4 &startValue, const cocos2d::Vec4 &endValue, float duration)', 'static fairygui::GTweener *to(const cocos2d::Color4B &startValue, const cocos2d::Color4B &endValue, float duration)')
    .func(nil, 'static fairygui::GTweener *toColor(const cocos2d::Color4B &startValue, const cocos2d::Color4B &endValue, float duration)')
    .func(nil, 'static fairygui::GTweener *toDouble(double startValue, double endValue, float duration)')
    .func(nil, 'static fairygui::GTweener *delayedCall(float delay)')
    .func(nil, 'static fairygui::GTweener *shake(const cocos2d::Vec2 &startValue, float amplitude, float duration)')
    .func(nil, 'static bool isTweening(cocos2d::Ref *target)', 'static bool isTweening(cocos2d::Ref *target, fairygui::TweenPropType propType)')
    .func(nil, 'static void kill(cocos2d::Ref *target)', 'static void kill(cocos2d::Ref *target, bool complete)', 'static void kill(cocos2d::Ref *target, fairygui::TweenPropType propType, bool complete)')
    .func(nil, 'static fairygui::GTweener *getTween(cocos2d::Ref *target)', 'static fairygui::GTweener *getTween(cocos2d::Ref *target, fairygui::TweenPropType propType)')
    .func(nil, 'static void clean()')
    .insert('to', {
        before = nil,
        after = [[
            olua_pushclassobj<fairygui::GTween>(L);
            olua_addref(L, -1, "tweeners", -2, OLUA_FLAG_MULTIPLE);
            olua_visitrefs(L, -1, "tweeners", should_del_tweener_ref);
            lua_pop(L, 1);
        ]],
        cbefore = nil,
        cafter = nil,
    })
    .insert('toColor', {
        before = nil,
        after = [[
            olua_pushclassobj<fairygui::GTween>(L);
            olua_addref(L, -1, "tweeners", -2, OLUA_FLAG_MULTIPLE);
            olua_visitrefs(L, -1, "tweeners", should_del_tweener_ref);
            lua_pop(L, 1);
        ]],
        cbefore = nil,
        cafter = nil,
    })
    .insert('toDouble', {
        before = nil,
        after = [[
            olua_pushclassobj<fairygui::GTween>(L);
            olua_addref(L, -1, "tweeners", -2, OLUA_FLAG_MULTIPLE);
            olua_visitrefs(L, -1, "tweeners", should_del_tweener_ref);
            lua_pop(L, 1);
        ]],
        cbefore = nil,
        cafter = nil,
    })
    .insert('delayedCall', {
        before = nil,
        after = [[
            olua_pushclassobj<fairygui::GTween>(L);
            olua_addref(L, -1, "tweeners", -2, OLUA_FLAG_MULTIPLE);
            olua_visitrefs(L, -1, "tweeners", should_del_tweener_ref);
            lua_pop(L, 1);
        ]],
        cbefore = nil,
        cafter = nil,
    })
    .insert('shake', {
        before = nil,
        after = [[
            olua_pushclassobj<fairygui::GTween>(L);
            olua_addref(L, -1, "tweeners", -2, OLUA_FLAG_MULTIPLE);
            olua_visitrefs(L, -1, "tweeners", should_del_tweener_ref);
            lua_pop(L, 1);
        ]],
        cbefore = nil,
        cafter = nil,
    })
    .insert('kill', {
        before = nil,
        after = [[
            olua_pushclassobj<fairygui::GTween>(L);
            olua_visitrefs(L, -1, "tweeners", should_del_tweener_ref);
            lua_pop(L, 1);
        ]],
        cbefore = nil,
        cafter = nil,
    })
    .insert('clean', {
        before = nil,
        after = [[
            olua_pushclassobj<fairygui::GTween>(L);
            olua_delallrefs(L, -1, "tweeners");
            lua_pop(L, 1);
        ]],
        cbefore = nil,
        cafter = nil,
    })

typeconf 'fairygui::UIPackage'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror(nil)
    .const('URL_PREFIX', 'fairygui::UIPackage::URL_PREFIX', 'const std::string')
    .func(nil, 'UIPackage()')
    .func(nil, 'static fairygui::UIPackage *getById(const std::string &id)')
    .func(nil, 'static fairygui::UIPackage *getByName(const std::string &name)')
    .func(nil, 'static fairygui::UIPackage *addPackage(const std::string &descFilePath)')
    .func(nil, 'static void removePackage(const std::string &packageIdOrName)')
    .func(nil, 'static void removeAllPackages()')
    .func(nil, 'static fairygui::GObject *createObject(const std::string &pkgName, const std::string &resName)')
    .func(nil, 'static fairygui::GObject *createObjectFromURL(const std::string &url)')
    .func(nil, 'static std::string getItemURL(const std::string &pkgName, const std::string &resName)')
    .func(nil, 'static fairygui::PackageItem *getItemByURL(const std::string &url)')
    .func(nil, 'static std::string normalizeURL(const std::string &url)')
    .func(nil, 'static void *getItemAsset(const std::string &pkgName, const std::string &resName, @optional fairygui::PackageItemType type)', 'void *getItemAsset(fairygui::PackageItem *item)')
    .func(nil, 'static void *getItemAssetByURL(const std::string &url, @optional fairygui::PackageItemType type)')
    .func(nil, 'static cocos2d::Texture2D *getEmptyTexture()')
    .func(nil, 'const std::string &getId()')
    .func(nil, 'const std::string &getName()')
    .func(nil, 'fairygui::PackageItem *getItem(const std::string &itemId)')
    .func(nil, 'fairygui::PackageItem *getItemByName(const std::string &itemName)')
    .func(nil, 'static const std::string &getBranch()')
    .func(nil, 'static void setBranch(const std::string &value)')
    .func(nil, 'static const std::string &getVar(const std::string &key)')
    .func(nil, 'static void setVar(const std::string &key, const std::string &value)')
    .prop('emptyTexture', nil, nil)
    .prop('id', nil, nil)
    .prop('name', nil, nil)
    .prop('branch', nil, nil)

typeconf 'fairygui::PackageItem'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror(nil)
    .func(nil, 'PackageItem()')
    .func(nil, 'void load()')
    .func(nil, 'fairygui::PackageItem *getBranch()')
    .func(nil, 'fairygui::PackageItem *getHighResolution()')
    .var('owner', 'fairygui::UIPackage *owner')
    .var('type', 'fairygui::PackageItemType type')
    .var('objectType', 'fairygui::ObjectType objectType')
    .var('id', 'std::string id')
    .var('name', 'std::string name')
    .var('width', 'int width')
    .var('height', 'int height')
    .var('file', 'std::string file')
    .var('texture', 'cocos2d::Texture2D *texture')
    .var('scaleByTile', 'bool scaleByTile')
    .var('tileGridIndice', 'int tileGridIndice')
    .var('spriteFrame', 'cocos2d::SpriteFrame *spriteFrame')
    .var('animation', 'cocos2d::Animation *animation')
    .var('delayPerUnit', 'float delayPerUnit')
    .var('repeatDelay', 'float repeatDelay')
    .var('swing', 'bool swing')
    .var('translated', 'bool translated')
    .prop('branch', nil, nil)
    .prop('highResolution', nil, nil)

typeconf 'fairygui::PackageItemType'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror('rw')
    .enum('IMAGE', 'fairygui::PackageItemType::IMAGE')
    .enum('MOVIECLIP', 'fairygui::PackageItemType::MOVIECLIP')
    .enum('SOUND', 'fairygui::PackageItemType::SOUND')
    .enum('COMPONENT', 'fairygui::PackageItemType::COMPONENT')
    .enum('ATLAS', 'fairygui::PackageItemType::ATLAS')
    .enum('FONT', 'fairygui::PackageItemType::FONT')
    .enum('SWF', 'fairygui::PackageItemType::SWF')
    .enum('MISC', 'fairygui::PackageItemType::MISC')
    .enum('UNKNOWN', 'fairygui::PackageItemType::UNKNOWN')
    .enum('SPINE', 'fairygui::PackageItemType::SPINE')
    .enum('DRAGONBONES', 'fairygui::PackageItemType::DRAGONBONES')

typeconf 'fairygui::ObjectType'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror('rw')
    .enum('IMAGE', 'fairygui::ObjectType::IMAGE')
    .enum('MOVIECLIP', 'fairygui::ObjectType::MOVIECLIP')
    .enum('SWF', 'fairygui::ObjectType::SWF')
    .enum('GRAPH', 'fairygui::ObjectType::GRAPH')
    .enum('LOADER', 'fairygui::ObjectType::LOADER')
    .enum('GROUP', 'fairygui::ObjectType::GROUP')
    .enum('TEXT', 'fairygui::ObjectType::TEXT')
    .enum('RICHTEXT', 'fairygui::ObjectType::RICHTEXT')
    .enum('INPUTTEXT', 'fairygui::ObjectType::INPUTTEXT')
    .enum('COMPONENT', 'fairygui::ObjectType::COMPONENT')
    .enum('LIST', 'fairygui::ObjectType::LIST')
    .enum('LABEL', 'fairygui::ObjectType::LABEL')
    .enum('BUTTON', 'fairygui::ObjectType::BUTTON')
    .enum('COMBOBOX', 'fairygui::ObjectType::COMBOBOX')
    .enum('PROGRESSBAR', 'fairygui::ObjectType::PROGRESSBAR')
    .enum('SLIDER', 'fairygui::ObjectType::SLIDER')
    .enum('SCROLLBAR', 'fairygui::ObjectType::SCROLLBAR')
    .enum('TREE', 'fairygui::ObjectType::TREE')
    .enum('LOADER3D', 'fairygui::ObjectType::LOADER3D')

typeconf 'fairygui::ButtonMode'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror('rw')
    .enum('COMMON', 'fairygui::ButtonMode::COMMON')
    .enum('CHECK', 'fairygui::ButtonMode::CHECK')
    .enum('RADIO', 'fairygui::ButtonMode::RADIO')

typeconf 'fairygui::ChildrenRenderOrder'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror('rw')
    .enum('ASCENT', 'fairygui::ChildrenRenderOrder::ASCENT')
    .enum('DESCENT', 'fairygui::ChildrenRenderOrder::DESCENT')
    .enum('ARCH', 'fairygui::ChildrenRenderOrder::ARCH')

typeconf 'fairygui::OverflowType'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror('rw')
    .enum('VISIBLE', 'fairygui::OverflowType::VISIBLE')
    .enum('HIDDEN', 'fairygui::OverflowType::HIDDEN')
    .enum('SCROLL', 'fairygui::OverflowType::SCROLL')

typeconf 'fairygui::ScrollType'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror('rw')
    .enum('HORIZONTAL', 'fairygui::ScrollType::HORIZONTAL')
    .enum('VERTICAL', 'fairygui::ScrollType::VERTICAL')
    .enum('BOTH', 'fairygui::ScrollType::BOTH')

typeconf 'fairygui::ScrollBarDisplayType'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror('rw')
    .enum('DEFAULT', 'fairygui::ScrollBarDisplayType::DEFAULT')
    .enum('VISIBLE', 'fairygui::ScrollBarDisplayType::VISIBLE')
    .enum('AUTO', 'fairygui::ScrollBarDisplayType::AUTO')
    .enum('HIDDEN', 'fairygui::ScrollBarDisplayType::HIDDEN')

typeconf 'fairygui::LoaderFillType'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror('rw')
    .enum('NONE', 'fairygui::LoaderFillType::NONE')
    .enum('SCALE', 'fairygui::LoaderFillType::SCALE')
    .enum('SCALE_MATCH_HEIGHT', 'fairygui::LoaderFillType::SCALE_MATCH_HEIGHT')
    .enum('SCALE_MATCH_WIDTH', 'fairygui::LoaderFillType::SCALE_MATCH_WIDTH')
    .enum('SCALE_FREE', 'fairygui::LoaderFillType::SCALE_FREE')
    .enum('SCALE_NO_BORDER', 'fairygui::LoaderFillType::SCALE_NO_BORDER')

typeconf 'fairygui::ProgressTitleType'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror('rw')
    .enum('PERCENT', 'fairygui::ProgressTitleType::PERCENT')
    .enum('VALUE_MAX', 'fairygui::ProgressTitleType::VALUE_MAX')
    .enum('VALUE', 'fairygui::ProgressTitleType::VALUE')
    .enum('MAX', 'fairygui::ProgressTitleType::MAX')

typeconf 'fairygui::ListLayoutType'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror('rw')
    .enum('SINGLE_COLUMN', 'fairygui::ListLayoutType::SINGLE_COLUMN')
    .enum('SINGLE_ROW', 'fairygui::ListLayoutType::SINGLE_ROW')
    .enum('FLOW_HORIZONTAL', 'fairygui::ListLayoutType::FLOW_HORIZONTAL')
    .enum('FLOW_VERTICAL', 'fairygui::ListLayoutType::FLOW_VERTICAL')
    .enum('PAGINATION', 'fairygui::ListLayoutType::PAGINATION')

typeconf 'fairygui::ListSelectionMode'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror('rw')
    .enum('SINGLE', 'fairygui::ListSelectionMode::SINGLE')
    .enum('MULTIPLE', 'fairygui::ListSelectionMode::MULTIPLE')
    .enum('MULTIPLE_SINGLECLICK', 'fairygui::ListSelectionMode::MULTIPLE_SINGLECLICK')
    .enum('NONE', 'fairygui::ListSelectionMode::NONE')

typeconf 'fairygui::GroupLayoutType'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror('rw')
    .enum('NONE', 'fairygui::GroupLayoutType::NONE')
    .enum('HORIZONTAL', 'fairygui::GroupLayoutType::HORIZONTAL')
    .enum('VERTICAL', 'fairygui::GroupLayoutType::VERTICAL')

typeconf 'fairygui::PopupDirection'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror('rw')
    .enum('AUTO', 'fairygui::PopupDirection::AUTO')
    .enum('UP', 'fairygui::PopupDirection::UP')
    .enum('DOWN', 'fairygui::PopupDirection::DOWN')

typeconf 'fairygui::AutoSizeType'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror('rw')
    .enum('NONE', 'fairygui::AutoSizeType::NONE')
    .enum('BOTH', 'fairygui::AutoSizeType::BOTH')
    .enum('HEIGHT', 'fairygui::AutoSizeType::HEIGHT')
    .enum('SHRINK', 'fairygui::AutoSizeType::SHRINK')

typeconf 'fairygui::FlipType'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror('rw')
    .enum('NONE', 'fairygui::FlipType::NONE')
    .enum('HORIZONTAL', 'fairygui::FlipType::HORIZONTAL')
    .enum('VERTICAL', 'fairygui::FlipType::VERTICAL')
    .enum('BOTH', 'fairygui::FlipType::BOTH')

typeconf 'fairygui::TransitionActionType'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror('rw')
    .enum('XY', 'fairygui::TransitionActionType::XY')
    .enum('Size', 'fairygui::TransitionActionType::Size')
    .enum('Scale', 'fairygui::TransitionActionType::Scale')
    .enum('Pivot', 'fairygui::TransitionActionType::Pivot')
    .enum('Alpha', 'fairygui::TransitionActionType::Alpha')
    .enum('Rotation', 'fairygui::TransitionActionType::Rotation')
    .enum('Color', 'fairygui::TransitionActionType::Color')
    .enum('Animation', 'fairygui::TransitionActionType::Animation')
    .enum('Visible', 'fairygui::TransitionActionType::Visible')
    .enum('Sound', 'fairygui::TransitionActionType::Sound')
    .enum('Transition', 'fairygui::TransitionActionType::Transition')
    .enum('Shake', 'fairygui::TransitionActionType::Shake')
    .enum('ColorFilter', 'fairygui::TransitionActionType::ColorFilter')
    .enum('Skew', 'fairygui::TransitionActionType::Skew')
    .enum('Text', 'fairygui::TransitionActionType::Text')
    .enum('Icon', 'fairygui::TransitionActionType::Icon')
    .enum('Unknown', 'fairygui::TransitionActionType::Unknown')

typeconf 'fairygui::FillMethod'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror('rw')
    .enum('None', 'fairygui::FillMethod::None')
    .enum('Horizontal', 'fairygui::FillMethod::Horizontal')
    .enum('Vertical', 'fairygui::FillMethod::Vertical')
    .enum('Radial90', 'fairygui::FillMethod::Radial90')
    .enum('Radial180', 'fairygui::FillMethod::Radial180')
    .enum('Radial360', 'fairygui::FillMethod::Radial360')

typeconf 'fairygui::FillOrigin'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror('rw')
    .enum('Top', 'fairygui::FillOrigin::Top')
    .enum('Bottom', 'fairygui::FillOrigin::Bottom')
    .enum('Left', 'fairygui::FillOrigin::Left')
    .enum('Right', 'fairygui::FillOrigin::Right')

typeconf 'fairygui::ObjectPropID'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror('rw')
    .enum('Text', 'fairygui::ObjectPropID::Text')
    .enum('Icon', 'fairygui::ObjectPropID::Icon')
    .enum('Color', 'fairygui::ObjectPropID::Color')
    .enum('OutlineColor', 'fairygui::ObjectPropID::OutlineColor')
    .enum('Playing', 'fairygui::ObjectPropID::Playing')
    .enum('Frame', 'fairygui::ObjectPropID::Frame')
    .enum('DeltaTime', 'fairygui::ObjectPropID::DeltaTime')
    .enum('TimeScale', 'fairygui::ObjectPropID::TimeScale')
    .enum('FontSize', 'fairygui::ObjectPropID::FontSize')
    .enum('Selected', 'fairygui::ObjectPropID::Selected')

typeconf 'fairygui::GController'
    .supercls('fairygui::UIEventDispatcher')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror(nil)
    .func(nil, 'GController()')
    .func(nil, 'fairygui::GComponent *getParent()')
    .func(nil, 'void setParent(fairygui::GComponent *value)')
    .func(nil, 'int getSelectedIndex()')
    .func(nil, 'void setSelectedIndex(int value, @optional bool triggerEvent)')
    .func(nil, 'const std::string &getSelectedPage()')
    .func(nil, 'void setSelectedPage(const std::string &value, @optional bool triggerEvent)')
    .func(nil, 'const std::string &getSelectedPageId()')
    .func(nil, 'void setSelectedPageId(const std::string &value, @optional bool triggerEvent)')
    .func(nil, 'int getPrevisousIndex()')
    .func(nil, 'const std::string &getPreviousPage()')
    .func(nil, 'const std::string &getPreviousPageId()')
    .func(nil, 'int getPageCount()')
    .func(nil, 'bool hasPage(const std::string &aName)')
    .func(nil, 'int getPageIndexById(const std::string &value)')
    .func(nil, 'const std::string &getPageNameById(const std::string &value)')
    .func(nil, 'const std::string &getPageId(int index)')
    .func(nil, 'void setOppositePageId(const std::string &value)')
    .func(nil, 'void runActions()')
    .var('name', 'std::string name')
    .var('changing', 'bool changing')
    .var('autoRadioGroupDepth', 'bool autoRadioGroupDepth')
    .prop('parent', nil, nil)
    .prop('selectedIndex', nil, nil)
    .prop('selectedPage', nil, nil)
    .prop('selectedPageId', nil, nil)
    .prop('previsousIndex', nil, nil)
    .prop('previousPage', nil, nil)
    .prop('previousPageId', nil, nil)
    .prop('pageCount', nil, nil)

typeconf 'fairygui::GObject'
    .supercls('fairygui::UIEventDispatcher')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror(nil)
    .func(nil, 'static fairygui::GObject *getDraggingObject()')
    .func(nil, 'GObject()')
    .func(nil, 'static fairygui::GObject *create()')
    .func(nil, 'float getX()')
    .func(nil, 'void setX(float value)')
    .func(nil, 'float getY()')
    .func(nil, 'void setY(float value)')
    .func(nil, 'const cocos2d::Vec2 &getPosition()')
    .func(nil, 'void setPosition(float xv, float yv)')
    .func(nil, 'float getXMin()')
    .func(nil, 'void setXMin(float value)')
    .func(nil, 'float getYMin()')
    .func(nil, 'void setYMin(float value)')
    .func(nil, 'bool isPixelSnapping()')
    .func(nil, 'void setPixelSnapping(bool value)')
    .func(nil, 'float getWidth()')
    .func(nil, 'void setWidth(float value)')
    .func(nil, 'float getHeight()')
    .func(nil, 'void setHeight(float value)')
    .func(nil, 'const cocos2d::Size &getSize()')
    .func(nil, 'void setSize(float wv, float hv, @optional bool ignorePivot)')
    .func(nil, 'void center(@optional bool restraint)')
    .func(nil, 'void makeFullScreen()')
    .func(nil, 'const cocos2d::Vec2 &getPivot()')
    .func(nil, 'void setPivot(float xv, float yv, @optional bool asAnchor)')
    .func(nil, 'bool isPivotAsAnchor()')
    .func(nil, 'float getScaleX()')
    .func(nil, 'void setScaleX(float value)')
    .func(nil, 'float getScaleY()')
    .func(nil, 'void setScaleY(float value)')
    .func(nil, 'const cocos2d::Vec2 &getScale()')
    .func(nil, 'void setScale(float xv, float yv)')
    .func(nil, 'float getSkewX()')
    .func(nil, 'void setSkewX(float value)')
    .func(nil, 'float getSkewY()')
    .func(nil, 'void setSkewY(float value)')
    .func(nil, 'float getRotation()')
    .func(nil, 'void setRotation(float value)')
    .func(nil, 'float getAlpha()')
    .func(nil, 'void setAlpha(float value)')
    .func(nil, 'bool isGrayed()')
    .func(nil, 'void setGrayed(bool value)')
    .func(nil, 'bool isVisible()')
    .func(nil, 'void setVisible(bool value)')
    .func(nil, 'bool isTouchable()')
    .func(nil, 'void setTouchable(bool value)')
    .func(nil, 'int getSortingOrder()')
    .func(nil, 'void setSortingOrder(int value)')
    .func(nil, '@addref(group ^) fairygui::GGroup *getGroup()')
    .func(nil, 'void setGroup(@addref(group ^) fairygui::GGroup *value)')
    .func(nil, 'const std::string &getText()')
    .func(nil, 'void setText(const std::string &text)')
    .func(nil, 'const std::string &getIcon()')
    .func(nil, 'void setIcon(const std::string &text)')
    .func(nil, 'const std::string &getTooltips()')
    .func(nil, 'void setTooltips(const std::string &value)')
    .func(nil, 'void *getData()')
    .func(nil, 'void setData(void *value)')
    .func(nil, 'const cocos2d::Value &getCustomData()')
    .func(nil, 'void setCustomData(const cocos2d::Value &value)')
    .func(nil, 'bool isDraggable()')
    .func(nil, 'void setDraggable(bool value)')
    .func(nil, 'void setDragBounds(const cocos2d::Rect &value)')
    .func(nil, 'void startDrag(@optional int touchId)')
    .func(nil, 'void stopDrag()')
    .func(nil, 'std::string getResourceURL()')
    .func(nil, 'fairygui::PackageItem *getPackageItem()')
    .func(nil, 'cocos2d::Vec2 globalToLocal(@pack const cocos2d::Vec2 &pt)', 'cocos2d::Rect globalToLocal(@pack const cocos2d::Rect &rect)')
    .func(nil, 'cocos2d::Vec2 localToGlobal(@pack const cocos2d::Vec2 &pt)', 'cocos2d::Rect localToGlobal(@pack const cocos2d::Rect &rect)')
    .func(nil, 'cocos2d::Rect transformRect(@pack const cocos2d::Rect &rect, fairygui::GObject *targetSpace)')
    .func(nil, 'fairygui::Relations *relations()')
    .func(nil, 'void addRelation(fairygui::GObject *target, fairygui::RelationType relationType, @optional bool usePercent)')
    .func(nil, 'void removeRelation(fairygui::GObject *target, fairygui::RelationType relationType)')
    .func(nil, 'fairygui::GearBase *getGear(int index)')
    .func(nil, 'bool checkGearController(int index, fairygui::GController *c)')
    .func(nil, 'uint32_t addDisplayLock()')
    .func(nil, 'void releaseDisplayLock(uint32_t token)')
    .func(nil, 'fairygui::GComponent *getParent()')
    .func(nil, 'fairygui::GObject *findParent()')
    .func(nil, '@addref(displayObject ^) cocos2d::Node *displayObject()')
    .func(nil, 'fairygui::GRoot *getRoot()')
    .func(nil, 'bool onStage()')
    .func(nil, 'void removeFromParent()')
    .func(nil, 'cocos2d::Value getProp(fairygui::ObjectPropID propId)')
    .func(nil, 'void setProp(fairygui::ObjectPropID propId, const cocos2d::Value &value)')
    .func(nil, 'fairygui::GObject *hitTest(const cocos2d::Vec2 &worldPoint, const cocos2d::Camera *camera)')
    .func(nil, 'fairygui::GTreeNode *treeNode()')
    .var('id', 'std::string id')
    .var('name', 'std::string name')
    .var('sourceSize', 'cocos2d::Size sourceSize')
    .var('initSize', 'cocos2d::Size initSize')
    .var('minSize', 'cocos2d::Size minSize')
    .var('maxSize', 'cocos2d::Size maxSize')
    .callback {
        funcs =  {
            'void addClickListener(@localvar const fairygui::EventCallback &callback)',
            'void addClickListener(@localvar const fairygui::EventCallback &callback, const fairygui::EventTag &tag)'
        },
        tag_maker = {'makeListenerTag(L, fairygui::UIEventType::Click, 0)', 'makeListenerTag(L, fairygui::UIEventType::Click, 3)'},
        tag_mode = 'new',
        tag_store = 0,
        tag_scope = 'object',
    }
    .callback {
        funcs =  {
            'void removeClickListener(const fairygui::EventTag &tag)'
        },
        tag_maker = 'makeListenerTag(L, fairygui::UIEventType::Click, 2)',
        tag_mode = 'subequal',
        tag_store = 0,
        tag_scope = 'object',
    }
    .prop('relations', 'Relations* relations()', nil)
    .prop('displayObject', 'cocos2d::Node* displayObject()', nil)
    .prop('draggingObject', nil, nil)
    .prop('x', nil, nil)
    .prop('y', nil, nil)
    .prop('xMin', nil, nil)
    .prop('yMin', nil, nil)
    .prop('pixelSnapping', nil, nil)
    .prop('width', nil, nil)
    .prop('height', nil, nil)
    .prop('pivotAsAnchor', nil, nil)
    .prop('scaleX', nil, nil)
    .prop('scaleY', nil, nil)
    .prop('skewX', nil, nil)
    .prop('skewY', nil, nil)
    .prop('rotation', nil, nil)
    .prop('alpha', nil, nil)
    .prop('grayed', nil, nil)
    .prop('visible', nil, nil)
    .prop('touchable', nil, nil)
    .prop('sortingOrder', nil, nil)
    .prop('group', nil, nil)
    .prop('text', nil, nil)
    .prop('icon', nil, nil)
    .prop('tooltips', nil, nil)
    .prop('data', nil, nil)
    .prop('customData', nil, nil)
    .prop('draggable', nil, nil)
    .prop('resourceURL', nil, nil)
    .prop('packageItem', nil, nil)
    .prop('parent', nil, nil)
    .prop('root', nil, nil)
    .insert('center', {
        before = [[
            if (!self->getParent() && !fairygui::UIRoot) {
                luaL_error(L, "UIRoot and parent are both nullptr");
            }
        ]],
        after = nil,
        cbefore = nil,
        cafter = nil,
    })
    .insert('makeFullScreen', {
        before = [[
            if (!fairygui::UIRoot) {
                luaL_error(L, "UIRoot is nullptr");
            }
        ]],
        after = nil,
        cbefore = nil,
        cafter = nil,
    })

typeconf 'fairygui::GComponent'
    .supercls('fairygui::GObject')
    .reg_luatype(true)
    .chunk([[
        static int _fairygui_GComponent_getController(lua_State *L);
        static int _fairygui_GComponent_getTransition(lua_State *L);
        static int _fairygui_GComponent_getChild(lua_State *L);
    ]])
    .luaopen(nil)
    .indexerror(nil)
    .func('__index', [[
        {
            if(olua_isuserdata(L, 1)) {
                if (olua_isstring(L, 2)) {
                    auto self = olua_toobj<fairygui::GComponent>(L, 1);
                    fairygui::GObject *child = self->getChild(olua_tostring(L, 2));
                    if (child) {
                        olua_pushobj<fairygui::GObject>(L, child);
                        olua_addref(L, 1, "children", -1, OLUA_FLAG_MULTIPLE);
                        return 1;
                    }
                }
                lua_settop(L, 2);
                olua_getvariable(L, 1);
                return 1;
            } else {
                return 0;
            }
        }
    ]])
    .func('resolve', [[
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
    .func(nil, 'GComponent()')
    .func(nil, 'static fairygui::GComponent *create()')
    .func(nil, 'fairygui::GObject *addChild(@addref(children |) fairygui::GObject *child)')
    .func(nil, 'fairygui::GObject *addChildAt(@addref(children |) fairygui::GObject *child, int index)')
    .func(nil, 'void removeChild(@delref(children |) fairygui::GObject *child)')
    .func(nil, '@delref(children ~) void removeChildAt(int index)')
    .func(nil, '@delref(children ~) void removeChildren()', '@delref(children ~) void removeChildren(int beginIndex, int endIndex)')
    .func(nil, '@addref(children |) fairygui::GObject *getChildAt(int index)')
    .func(nil, '@addref(children |) fairygui::GObject *getChild(const std::string &name)')
    .func(nil, '@addref(children |) fairygui::GObject *getChildInGroup(const fairygui::GGroup *group, const std::string &name)')
    .func(nil, '@addref(children |) fairygui::GObject *getChildById(const std::string &id)')
    .func(nil, '@addref(children |) const cocos2d::Vector<GObject *> &getChildren()')
    .func(nil, 'int getChildIndex(const fairygui::GObject *child)')
    .func(nil, 'void setChildIndex(fairygui::GObject *child, int index)')
    .func(nil, 'int setChildIndexBefore(fairygui::GObject *child, int index)')
    .func(nil, 'void swapChildren(fairygui::GObject *child1, fairygui::GObject *child2)')
    .func(nil, 'void swapChildrenAt(int index1, int index2)')
    .func(nil, 'int numChildren()')
    .func(nil, 'bool isAncestorOf(const fairygui::GObject *obj)')
    .func(nil, 'bool isChildInView(fairygui::GObject *child)')
    .func(nil, 'int getFirstChildInView()')
    .func(nil, 'void addController(@addref(controllers |) fairygui::GController *c)')
    .func(nil, '@addref(controllers |) fairygui::GController *getControllerAt(int index)')
    .func(nil, '@addref(controllers |) fairygui::GController *getController(const std::string &name)')
    .func(nil, '@addref(controllers |) const cocos2d::Vector<GController *> &getControllers()')
    .func(nil, 'void removeController(@delref(controllers |) fairygui::GController *c)')
    .func(nil, 'void applyController(fairygui::GController *c)')
    .func(nil, 'void applyAllControllers()')
    .func(nil, '@addref(transitions |) fairygui::Transition *getTransition(const std::string &name)')
    .func(nil, '@addref(transitions |) fairygui::Transition *getTransitionAt(int index)')
    .func(nil, '@addref(transitions |) const cocos2d::Vector<Transition *> &getTransitions()')
    .func(nil, 'bool getOpaque()')
    .func(nil, 'void setOpaque(bool value)')
    .func(nil, 'const fairygui::Margin &getMargin()')
    .func(nil, 'void setMargin(const fairygui::Margin &value)')
    .func(nil, 'fairygui::ChildrenRenderOrder getChildrenRenderOrder()')
    .func(nil, 'void setChildrenRenderOrder(fairygui::ChildrenRenderOrder value)')
    .func(nil, 'int getApexIndex()')
    .func(nil, 'void setApexIndex(int value)')
    .func(nil, '@addref(mask ^) cocos2d::Node *getMask()')
    .func(nil, 'void setMask(@addref(mask ^) cocos2d::Node *value, @optional bool inverted)')
    .func(nil, 'fairygui::IHitTest *getHitArea()')
    .func(nil, 'void setHitArea(fairygui::IHitTest *value)')
    .func(nil, 'fairygui::ScrollPane *getScrollPane()')
    .func(nil, 'float getViewWidth()')
    .func(nil, 'void setViewWidth(float value)')
    .func(nil, 'float getViewHeight()')
    .func(nil, 'void setViewHeight(float value)')
    .func(nil, 'void setBoundsChangedFlag()')
    .func(nil, 'void ensureBoundsCorrect()')
    .func(nil, 'cocos2d::Vec2 getSnappingPosition(const cocos2d::Vec2 &pt)')
    .func(nil, 'void childSortingOrderChanged(fairygui::GObject *child, int oldValue, int newValue)')
    .func(nil, 'void childStateChanged(fairygui::GObject *child)')
    .func(nil, 'void adjustRadioGroupDepth(fairygui::GObject *obj, fairygui::GController *c)')
    .prop('numChildren', 'int numChildren()', nil)
    .prop('children', nil, nil)
    .prop('firstChildInView', nil, nil)
    .prop('controllers', nil, nil)
    .prop('transitions', nil, nil)
    .prop('opaque', nil, nil)
    .prop('margin', nil, nil)
    .prop('childrenRenderOrder', nil, nil)
    .prop('apexIndex', nil, nil)
    .prop('mask', nil, nil)
    .prop('hitArea', nil, nil)
    .prop('scrollPane', nil, nil)
    .prop('viewWidth', nil, nil)
    .prop('viewHeight', nil, nil)
    .alias('resolve', 'getChildByPath')

typeconf 'fairygui::GRoot'
    .supercls('fairygui::GComponent')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror(nil)
    .func(nil, 'GRoot()')
    .func(nil, 'static fairygui::GRoot *create(cocos2d::Scene *scene, @optional int zOrder)')
    .func(nil, 'static fairygui::GRoot *getInstance()')
    .func(nil, '@delref(children ~) void showWindow(@addref(children |) fairygui::Window *win)')
    .func(nil, '@delref(children ~ parent) void hideWindow(fairygui::Window *win)')
    .func(nil, '@delref(children ~ parent) void hideWindowImmediately(fairygui::Window *win)')
    .func(nil, 'void bringToFront(fairygui::Window *win)')
    .func(nil, 'void showModalWait()')
    .func(nil, 'void closeModalWait()')
    .func(nil, 'void closeAllExceptModals()')
    .func(nil, 'void closeAllWindows()')
    .func(nil, '@addref(children |) fairygui::Window *getTopWindow()')
    .func(nil, '@addref(children |) fairygui::GObject *getModalWaitingPane()')
    .func(nil, '@addref(children |) fairygui::GGraph *getModalLayer()')
    .func(nil, 'bool hasModalWindow()')
    .func(nil, 'bool isModalWaiting()')
    .func(nil, '@addref(inputProcessor ^) fairygui::InputProcessor *getInputProcessor()')
    .func(nil, 'cocos2d::Vec2 getTouchPosition(int touchId)')
    .func(nil, 'fairygui::GObject *getTouchTarget()')
    .func(nil, 'cocos2d::Vec2 worldToRoot(@pack const cocos2d::Vec2 &pt)')
    .func(nil, 'cocos2d::Vec2 rootToWorld(@pack const cocos2d::Vec2 &pt)')
    .func(nil, '@delref(children ~) void showPopup(@addref(children |) fairygui::GObject *popup)', '@delref(children ~) void showPopup(@addref(children |) fairygui::GObject *popup, fairygui::GObject *target, fairygui::PopupDirection dir)')
    .func(nil, '@delref(children ~) void togglePopup(@addref(children |) fairygui::GObject *popup)', '@delref(children ~) void togglePopup(@addref(children |) fairygui::GObject *popup, fairygui::GObject *target, fairygui::PopupDirection dir)')
    .func(nil, '@delref(children ~) void hidePopup()', '@delref(children ~) void hidePopup(fairygui::GObject *popup)')
    .func(nil, 'bool hasAnyPopup()')
    .func(nil, 'cocos2d::Vec2 getPoupPosition(fairygui::GObject *popup, fairygui::GObject *target, fairygui::PopupDirection dir)')
    .func(nil, 'void showTooltips(const std::string &msg)')
    .func(nil, 'void showTooltipsWin(fairygui::GObject *tooltipWin)')
    .func(nil, 'void hideTooltips()')
    .func(nil, 'void playSound(const std::string &url, @optional float volumeScale)')
    .func(nil, 'bool isSoundEnabled()')
    .func(nil, 'void setSoundEnabled(bool value)')
    .func(nil, 'float getSoundVolumeScale()')
    .func(nil, 'void setSoundVolumeScale(float value)')
    .func(nil, 'void setNotAsUIRoot()')
    .var('contentScaleLevel', 'static int contentScaleLevel')
    .prop('UIRoot', 'static GRoot* getInstance()', nil)
    .prop('instance', nil, nil)
    .prop('topWindow', nil, nil)
    .prop('modalWaitingPane', nil, nil)
    .prop('modalLayer', nil, nil)
    .prop('modalWaiting', nil, nil)
    .prop('inputProcessor', nil, nil)
    .prop('touchTarget', nil, nil)
    .prop('soundEnabled', nil, nil)
    .prop('soundVolumeScale', nil, nil)
    .insert('create', {
        before = nil,
        after = [[
            olua_push_cppobj<cocos2d::Node>(L, ret->displayObject());
            olua_addref(L, -1, "fgui.root", -2, OLUA_FLAG_SINGLE);
            olua_addref(L, 1, "children", -1, OLUA_FLAG_MULTIPLE);
            lua_pop(L, 1);
        ]],
        cbefore = nil,
        cafter = nil,
    })
    .insert('hideWindow', {
        before = [[
            int parent = 1;
            if (arg1->getParent()) {
                olua_push_cppobj<fairygui::GComponent>(L, arg1->getParent());
                parent = lua_gettop(L);
            }
        ]],
        after = nil,
        cbefore = nil,
        cafter = nil,
    })
    .insert('hideWindowImmediately', {
        before = [[
            int parent = 1;
            if (arg1->getParent()) {
                olua_push_cppobj<fairygui::GComponent>(L, arg1->getParent());
                parent = lua_gettop(L);
            }
        ]],
        after = nil,
        cbefore = nil,
        cafter = nil,
    })

typeconf 'fairygui::GGroup'
    .supercls('fairygui::GObject')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror(nil)
    .func(nil, 'GGroup()')
    .func(nil, 'static fairygui::GGroup *create()')
    .func(nil, 'fairygui::GroupLayoutType getLayout()')
    .func(nil, 'void setLayout(fairygui::GroupLayoutType value)')
    .func(nil, 'int getColumnGap()')
    .func(nil, 'void setColumnGap(int value)')
    .func(nil, 'int getLineGap()')
    .func(nil, 'void setLineGap(int value)')
    .func(nil, 'bool isExcludeInvisibles()')
    .func(nil, 'void setExcludeInvisibles(bool value)')
    .func(nil, 'bool isAutoSizeDisabled()')
    .func(nil, 'void setAutoSizeDisabled(bool value)')
    .func(nil, 'int getMainGridIndex()')
    .func(nil, 'void setMainGridIndex(int value)')
    .func(nil, 'int getMainGridMinSize()')
    .func(nil, 'void setMainGridMinSize(int value)')
    .func(nil, 'void setBoundsChangedFlag(@optional bool positionChangedOnly)')
    .func(nil, 'void moveChildren(float dx, float dy)')
    .func(nil, 'void resizeChildren(float dw, float dh)')
    .prop('layout', nil, nil)
    .prop('columnGap', nil, nil)
    .prop('lineGap', nil, nil)
    .prop('excludeInvisibles', nil, nil)
    .prop('autoSizeDisabled', nil, nil)
    .prop('mainGridIndex', nil, nil)
    .prop('mainGridMinSize', nil, nil)

typeconf 'fairygui::GScrollBar'
    .supercls('fairygui::GComponent')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror(nil)
    .func(nil, 'GScrollBar()')
    .func(nil, 'static fairygui::GScrollBar *create()')
    .func(nil, 'void setScrollPane(fairygui::ScrollPane *target, bool vertical)')
    .func(nil, 'void setDisplayPerc(float value)')
    .func(nil, 'void setScrollPerc(float value)')
    .func(nil, 'float getMinSize()')
    .prop('minSize', nil, nil)

typeconf 'fairygui::GLoader'
    .supercls('fairygui::GObject')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror(nil)
    .func(nil, 'GLoader()')
    .func(nil, 'static fairygui::GLoader *create()')
    .func(nil, 'const std::string &getURL()')
    .func(nil, 'void setURL(const std::string &value)')
    .func(nil, 'cocos2d::TextHAlignment getAlign()')
    .func(nil, 'void setAlign(cocos2d::TextHAlignment value)')
    .func(nil, 'cocos2d::TextVAlignment getVerticalAlign()')
    .func(nil, 'void setVerticalAlign(cocos2d::TextVAlignment value)')
    .func(nil, 'bool getAutoSize()')
    .func(nil, 'void setAutoSize(bool value)')
    .func(nil, 'fairygui::LoaderFillType getFill()')
    .func(nil, 'void setFill(fairygui::LoaderFillType value)')
    .func(nil, 'bool isShrinkOnly()')
    .func(nil, 'void setShrinkOnly(bool value)')
    .func(nil, 'const cocos2d::Size &getContentSize()')
    .func(nil, 'cocos2d::Color3B getColor()')
    .func(nil, 'void setColor(const cocos2d::Color3B &value)')
    .func(nil, 'bool isPlaying()')
    .func(nil, 'void setPlaying(bool value)')
    .func(nil, 'int getFrame()')
    .func(nil, 'void setFrame(int value)')
    .func(nil, 'fairygui::FillMethod getFillMethod()')
    .func(nil, 'void setFillMethod(fairygui::FillMethod value)')
    .func(nil, 'fairygui::FillOrigin getFillOrigin()')
    .func(nil, 'void setFillOrigin(fairygui::FillOrigin value)')
    .func(nil, 'bool isFillClockwise()')
    .func(nil, 'void setFillClockwise(bool value)')
    .func(nil, 'float getFillAmount()')
    .func(nil, 'void setFillAmount(float value)')
    .func(nil, '@addref(component ^) fairygui::GComponent *getComponent()')
    .prop('url', nil, nil)
    .prop('align', nil, nil)
    .prop('verticalAlign', nil, nil)
    .prop('autoSize', nil, nil)
    .prop('fill', nil, nil)
    .prop('shrinkOnly', nil, nil)
    .prop('contentSize', nil, nil)
    .prop('color', nil, nil)
    .prop('playing', nil, nil)
    .prop('frame', nil, nil)
    .prop('fillMethod', nil, nil)
    .prop('fillOrigin', nil, nil)
    .prop('fillClockwise', nil, nil)
    .prop('fillAmount', nil, nil)
    .prop('component', nil, nil)

typeconf 'fairygui::GLoader3D'
    .supercls('fairygui::GObject')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror(nil)
    .func(nil, 'GLoader3D()')
    .func(nil, 'static fairygui::GLoader3D *create()')
    .func(nil, 'const std::string &getURL()')
    .func(nil, 'void setURL(const std::string &value)')
    .func(nil, 'cocos2d::TextHAlignment getAlign()')
    .func(nil, 'void setAlign(cocos2d::TextHAlignment value)')
    .func(nil, 'cocos2d::TextVAlignment getVerticalAlign()')
    .func(nil, 'void setVerticalAlign(cocos2d::TextVAlignment value)')
    .func(nil, 'bool getAutoSize()')
    .func(nil, 'void setAutoSize(bool value)')
    .func(nil, 'fairygui::LoaderFillType getFill()')
    .func(nil, 'void setFill(fairygui::LoaderFillType value)')
    .func(nil, 'bool isShrinkOnly()')
    .func(nil, 'void setShrinkOnly(bool value)')
    .func(nil, '@addref(content ^) const cocos2d::Node *getContent()')
    .func(nil, 'void setContent(@addref(content ^) cocos2d::Node *value)')
    .func(nil, 'cocos2d::Color3B getColor()')
    .func(nil, 'void setColor(const cocos2d::Color3B &value)')
    .func(nil, 'bool isPlaying()')
    .func(nil, 'void setPlaying(bool value)')
    .func(nil, 'int getFrame()')
    .func(nil, 'void setFrame(int value)')
    .func(nil, 'const std::string &getAnimationName()')
    .func(nil, 'void setAnimationName(const std::string &value)')
    .func(nil, 'const std::string &getSkinName()')
    .func(nil, 'void setSkinName(const std::string &value)')
    .func(nil, 'bool getLoop()')
    .func(nil, 'void setLoop(bool value)')
    .prop('url', nil, nil)
    .prop('align', nil, nil)
    .prop('verticalAlign', nil, nil)
    .prop('autoSize', nil, nil)
    .prop('fill', nil, nil)
    .prop('shrinkOnly', nil, nil)
    .prop('content', nil, nil)
    .prop('color', nil, nil)
    .prop('playing', nil, nil)
    .prop('frame', nil, nil)
    .prop('animationName', nil, nil)
    .prop('skinName', nil, nil)
    .prop('loop', nil, nil)

typeconf 'fairygui::GTextField'
    .supercls('fairygui::GObject')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror(nil)
    .func(nil, 'bool isUBBEnabled()')
    .func(nil, 'void setUBBEnabled(bool value)')
    .func(nil, 'fairygui::AutoSizeType getAutoSize()')
    .func(nil, 'void setAutoSize(fairygui::AutoSizeType value)')
    .func(nil, 'bool isSingleLine()')
    .func(nil, 'void setSingleLine(bool value)')
    .func(nil, 'fairygui::TextFormat *getTextFormat()')
    .func(nil, 'void applyTextFormat()')
    .func(nil, 'const cocos2d::Size &getTextSize()')
    .func(nil, 'cocos2d::Color3B getColor()')
    .func(nil, 'void setColor(const cocos2d::Color3B &value)')
    .func(nil, 'float getFontSize()')
    .func(nil, 'void setFontSize(float value)')
    .func(nil, 'cocos2d::Color3B getOutlineColor()')
    .func(nil, 'void setOutlineColor(const cocos2d::Color3B &value)')
    .func(nil, 'cocos2d::ValueMap *getTemplateVars()')
    .func(nil, 'void setTemplateVars(cocos2d::ValueMap *value)')
    .func(nil, 'fairygui::GTextField *setVar(const std::string &name, const cocos2d::Value &value)')
    .func(nil, 'void flushVars()')
    .prop('ubbEnabled', nil, nil)
    .prop('autoSize', nil, nil)
    .prop('singleLine', nil, nil)
    .prop('textFormat', nil, nil)
    .prop('textSize', nil, nil)
    .prop('color', nil, nil)
    .prop('fontSize', nil, nil)
    .prop('outlineColor', nil, nil)
    .prop('templateVars', nil, nil)

typeconf 'fairygui::GBasicTextField'
    .supercls('fairygui::GTextField')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror(nil)
    .func(nil, 'GBasicTextField()')
    .func(nil, 'static fairygui::GBasicTextField *create()')

typeconf 'fairygui::GGraph'
    .supercls('fairygui::GObject')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror(nil)
    .func('drawPolygon', [[
        {
            fairygui::GGraph *self = nullptr;
            lua_Integer lineSize = 0;
            cocos2d::Color4F lineColor;
            cocos2d::Color4F fillColor;
            std::vector<cocos2d::Vec2> points;

            self = olua_toobj<fairygui::GGraph>(L, 1);
            olua_check_int(L, 2, &lineSize);
            olua_check_cocos2d_Color4F(L, 3, &lineColor);
            olua_check_cocos2d_Color4F(L, 4, &fillColor);
            olua_check_array<cocos2d::Vec2>(L, 5, &points, [L](cocos2d::Vec2 *value) {
                olua_check_cocos2d_Vec2(L, -1, value);
            });

            self->drawPolygon((int)lineSize, lineColor, fillColor, points.size() ? &points[0] : nullptr, (int)points.size());

            return 0;
        }
    ]])
    .func('drawRegularPolygon', [[
        {
            int num_args = lua_gettop(L) - 1;
            fairygui::GGraph *self = nullptr;
            lua_Integer lineSize = 0;
            cocos2d::Color4F lineColor;
            cocos2d::Color4F fillColor;
            lua_Integer sides = 0;
            lua_Number startAngle = 0;
            std::vector<float> distances;

            self = olua_toobj<fairygui::GGraph>(L, 1);
            olua_check_int(L, 2, &lineSize);
            olua_check_cocos2d_Color4F(L, 3, &lineColor);
            olua_check_cocos2d_Color4F(L, 4, &fillColor);
            olua_check_int(L, 5, &sides);

            if (num_args == 4) {
                self->drawRegularPolygon((int)lineSize, lineColor, fillColor, (int)sides);
            } else if (num_args == 5) {
                olua_check_number(L, 6, &startAngle);
                self->drawRegularPolygon((int)lineSize, lineColor, fillColor, (int)sides, (float)startAngle);
            } else {
                olua_check_number(L, 6, &startAngle);
                olua_check_array<float>(L, 7, &distances, [L](float *value) {
                    *value = (float)olua_checknumber(L, -1);
                });
                self->drawRegularPolygon((int)lineSize, lineColor, fillColor, (int)sides, (float)startAngle, distances.size() ? &distances[0] : nullptr, (int)distances.size());
            }

            return 0;
        }
    ]])
    .func(nil, 'GGraph()')
    .func(nil, 'static fairygui::GGraph *create()')
    .func(nil, 'void drawRect(float aWidth, float aHeight, int lineSize, const cocos2d::Color4F &lineColor, const cocos2d::Color4F &fillColor)')
    .func(nil, 'void drawEllipse(float aWidth, float aHeight, int lineSize, const cocos2d::Color4F &lineColor, const cocos2d::Color4F &fillColor)')
    .func(nil, 'bool isEmpty()')
    .func(nil, 'cocos2d::Color3B getColor()')
    .func(nil, 'void setColor(const cocos2d::Color3B &value)')
    .prop('empty', nil, nil)
    .prop('color', nil, nil)

typeconf 'fairygui::GButton'
    .supercls('fairygui::GComponent')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror(nil)
    .const('UP', 'fairygui::GButton::UP', 'const std::string')
    .const('DOWN', 'fairygui::GButton::DOWN', 'const std::string')
    .const('OVER', 'fairygui::GButton::OVER', 'const std::string')
    .const('SELECTED_OVER', 'fairygui::GButton::SELECTED_OVER', 'const std::string')
    .const('DISABLED', 'fairygui::GButton::DISABLED', 'const std::string')
    .const('SELECTED_DISABLED', 'fairygui::GButton::SELECTED_DISABLED', 'const std::string')
    .func(nil, 'GButton()')
    .func(nil, 'static fairygui::GButton *create()')
    .func(nil, 'const std::string &getTitle()')
    .func(nil, 'void setTitle(const std::string &value)')
    .func(nil, 'const std::string &getSelectedTitle()')
    .func(nil, 'void setSelectedTitle(const std::string &value)')
    .func(nil, 'const std::string &getSelectedIcon()')
    .func(nil, 'void setSelectedIcon(const std::string &value)')
    .func(nil, 'cocos2d::Color3B getTitleColor()')
    .func(nil, 'void setTitleColor(const cocos2d::Color3B &value)')
    .func(nil, 'int getTitleFontSize()')
    .func(nil, 'void setTitleFontSize(int value)')
    .func(nil, 'bool isSelected()')
    .func(nil, 'void setSelected(bool value)')
    .func(nil, '@addref(relatedController ^) fairygui::GController *getRelatedController()')
    .func(nil, 'void setRelatedController(@addref(relatedController ^) fairygui::GController *c)')
    .func(nil, 'bool isChangeStateOnClick()')
    .func(nil, 'void setChangeStateOnClick(bool value)')
    .func(nil, '@addref(textField ^) fairygui::GTextField *getTextField()')
    .prop('title', nil, nil)
    .prop('selectedTitle', nil, nil)
    .prop('selectedIcon', nil, nil)
    .prop('titleColor', nil, nil)
    .prop('titleFontSize', nil, nil)
    .prop('selected', nil, nil)
    .prop('relatedController', nil, nil)
    .prop('changeStateOnClick', nil, nil)
    .prop('textField', nil, nil)

typeconf 'fairygui::GImage'
    .supercls('fairygui::GObject')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror(nil)
    .func(nil, 'GImage()')
    .func(nil, 'static fairygui::GImage *create()')
    .func(nil, 'fairygui::FlipType getFlip()')
    .func(nil, 'void setFlip(fairygui::FlipType value)')
    .func(nil, 'cocos2d::Color3B getColor()')
    .func(nil, 'void setColor(const cocos2d::Color3B &value)')
    .func(nil, 'fairygui::FillMethod getFillMethod()')
    .func(nil, 'void setFillMethod(fairygui::FillMethod value)')
    .func(nil, 'fairygui::FillOrigin getFillOrigin()')
    .func(nil, 'void setFillOrigin(fairygui::FillOrigin value)')
    .func(nil, 'bool isFillClockwise()')
    .func(nil, 'void setFillClockwise(bool value)')
    .func(nil, 'float getFillAmount()')
    .func(nil, 'void setFillAmount(float value)')
    .prop('flip', nil, nil)
    .prop('color', nil, nil)
    .prop('fillMethod', nil, nil)
    .prop('fillOrigin', nil, nil)
    .prop('fillClockwise', nil, nil)
    .prop('fillAmount', nil, nil)

typeconf 'fairygui::GLabel'
    .supercls('fairygui::GComponent')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror(nil)
    .func(nil, 'GLabel()')
    .func(nil, 'static fairygui::GLabel *create()')
    .func(nil, 'const std::string &getTitle()')
    .func(nil, 'void setTitle(const std::string &value)')
    .func(nil, 'cocos2d::Color3B getTitleColor()')
    .func(nil, 'void setTitleColor(const cocos2d::Color3B &value)')
    .func(nil, 'int getTitleFontSize()')
    .func(nil, 'void setTitleFontSize(int value)')
    .func(nil, '@addref(textField ^) fairygui::GTextField *getTextField()')
    .prop('title', nil, nil)
    .prop('titleColor', nil, nil)
    .prop('titleFontSize', nil, nil)
    .prop('textField', nil, nil)

typeconf 'fairygui::GList::ListItemRenderer'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror(nil)

typeconf 'fairygui::GList::ListItemProvider'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror(nil)

typeconf 'fairygui::GList'
    .supercls('fairygui::GComponent')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror(nil)
    .func(nil, 'GList()')
    .func(nil, 'static fairygui::GList *create()')
    .func(nil, 'const std::string &getDefaultItem()')
    .func(nil, 'void setDefaultItem(const std::string &value)')
    .func(nil, 'fairygui::ListLayoutType getLayout()')
    .func(nil, 'void setLayout(fairygui::ListLayoutType value)')
    .func(nil, 'int getLineCount()')
    .func(nil, 'void setLineCount(int value)')
    .func(nil, 'int getColumnCount()')
    .func(nil, 'void setColumnCount(int value)')
    .func(nil, 'int getColumnGap()')
    .func(nil, 'void setColumnGap(int value)')
    .func(nil, 'int getLineGap()')
    .func(nil, 'void setLineGap(int value)')
    .func(nil, 'cocos2d::TextHAlignment getAlign()')
    .func(nil, 'void setAlign(cocos2d::TextHAlignment value)')
    .func(nil, 'cocos2d::TextVAlignment getVerticalAlign()')
    .func(nil, 'void setVerticalAlign(cocos2d::TextVAlignment value)')
    .func(nil, 'bool getAutoResizeItem()')
    .func(nil, 'void setAutoResizeItem(bool value)')
    .func(nil, 'fairygui::ListSelectionMode getSelectionMode()')
    .func(nil, 'void setSelectionMode(fairygui::ListSelectionMode value)')
    .func(nil, 'fairygui::GObject *getFromPool()', 'fairygui::GObject *getFromPool(const std::string &url)')
    .func(nil, 'void returnToPool(@delref(children |) fairygui::GObject *obj)')
    .func(nil, '@addref(children |) fairygui::GObject *addItemFromPool()', '@addref(children |) fairygui::GObject *addItemFromPool(const std::string &url)')
    .func(nil, '@delref(children ~) void removeChildToPoolAt(int index)')
    .func(nil, 'void removeChildToPool(@delref(children |) fairygui::GObject *child)')
    .func(nil, '@delref(children ~) void removeChildrenToPool()', '@delref(children ~) void removeChildrenToPool(int beginIndex, int endIndex)')
    .func(nil, 'int getSelectedIndex()')
    .func(nil, 'void setSelectedIndex(int value)')
    .func(nil, 'void getSelection(@ret std::vector<int> &result)')
    .func(nil, 'void addSelection(int index, bool scrollItToView)')
    .func(nil, 'void removeSelection(int index)')
    .func(nil, 'void clearSelection()')
    .func(nil, 'void selectAll()')
    .func(nil, 'void selectReverse()')
    .func(nil, 'void handleArrowKey(int dir)')
    .func(nil, 'void resizeToFit(int itemCount)', 'void resizeToFit(int itemCount, int minSize)')
    .func(nil, 'void scrollToView(int index, @optional bool ani, @optional bool setFirst)')
    .func(nil, '@addref(selectionController ^) fairygui::GController *getSelectionController()')
    .func(nil, 'void setSelectionController(@addref(selectionController ^) fairygui::GController *value)')
    .func(nil, '@delref(children ~) void setVirtual()')
    .func(nil, '@delref(children ~) void setVirtualAndLoop()')
    .func(nil, 'bool isVirtual()')
    .func(nil, 'void refreshVirtualList()')
    .func(nil, 'int getNumItems()')
    .func(nil, '@delref(children ~) void setNumItems(int value)')
    .func(nil, 'int childIndexToItemIndex(int index)')
    .func(nil, 'int itemIndexToChildIndex(int index)')
    .var('itemRenderer', '@nullable fairygui::GList::ListItemRenderer itemRenderer')
    .var('itemProvider', '@nullable @localvar fairygui::GList::ListItemProvider itemProvider')
    .var('scrollItemToViewOnClick', 'bool scrollItemToViewOnClick')
    .var('foldInvisibleItems', 'bool foldInvisibleItems')
    .prop('defaultItem', nil, nil)
    .prop('layout', nil, nil)
    .prop('lineCount', nil, nil)
    .prop('columnCount', nil, nil)
    .prop('columnGap', nil, nil)
    .prop('lineGap', nil, nil)
    .prop('align', nil, nil)
    .prop('verticalAlign', nil, nil)
    .prop('autoResizeItem', nil, nil)
    .prop('selectionMode', nil, nil)
    .prop('selectedIndex', nil, nil)
    .prop('selectionController', nil, nil)
    .prop('virtual', nil, nil)
    .prop('numItems', nil, nil)
    .insert('itemRenderer', {
        before = nil,
        after = nil,
        cbefore = [[
            olua_push_cppobj<fairygui::GComponent>(L, (fairygui::GComponent *)cb_store);
            olua_addref(L, -1, "children", top + 2, OLUA_FLAG_MULTIPLE);
            lua_pop(L, 1);
        ]],
        cafter = nil,
    })

typeconf 'fairygui::GMovieClip'
    .supercls('fairygui::GObject')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror(nil)
    .func(nil, 'GMovieClip()')
    .func(nil, 'static fairygui::GMovieClip *create()')
    .func(nil, 'bool isPlaying()')
    .func(nil, 'void setPlaying(bool value)')
    .func(nil, 'int getFrame()')
    .func(nil, 'void setFrame(int value)')
    .func(nil, 'float getTimeScale()')
    .func(nil, 'void setTimeScale(float value)')
    .func(nil, 'void advance(float time)')
    .func(nil, 'fairygui::FlipType getFlip()')
    .func(nil, 'void setFlip(fairygui::FlipType value)')
    .func(nil, 'cocos2d::Color3B getColor()')
    .func(nil, 'void setColor(const cocos2d::Color3B &value)')
    .callback {
        funcs =  {
            'void setPlaySettings(@optional int start, @optional int end, @optional int times, @optional int endAt, @localvar @optional std::function<void ()> completeCallback)'
        },
        tag_maker = 'PlaySettings',
        tag_mode = 'replace',
        tag_store = 0,
        tag_scope = 'object',
    }
    .prop('playing', nil, nil)
    .prop('frame', nil, nil)
    .prop('timeScale', nil, nil)
    .prop('flip', nil, nil)
    .prop('color', nil, nil)

typeconf 'fairygui::GProgressBar'
    .supercls('fairygui::GComponent')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror(nil)
    .func(nil, 'GProgressBar()')
    .func(nil, 'static fairygui::GProgressBar *create()')
    .func(nil, 'fairygui::ProgressTitleType getTitleType()')
    .func(nil, 'void setTitleType(fairygui::ProgressTitleType value)')
    .func(nil, 'double getMin()')
    .func(nil, 'void setMin(double value)')
    .func(nil, 'double getMax()')
    .func(nil, 'void setMax(double value)')
    .func(nil, 'double getValue()')
    .func(nil, 'void setValue(double value)')
    .func(nil, 'void tweenValue(double value, float duration)')
    .func(nil, 'void update(double newValue)')
    .prop('titleType', nil, nil)
    .prop('min', nil, nil)
    .prop('max', nil, nil)
    .prop('value', nil, nil)

typeconf 'fairygui::GComboBox'
    .supercls('fairygui::GComponent')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror(nil)
    .func(nil, 'GComboBox()')
    .func(nil, 'static fairygui::GComboBox *create()')
    .func(nil, 'const std::string &getTitle()')
    .func(nil, 'void setTitle(const std::string &value)')
    .func(nil, 'const cocos2d::Color3B getTitleColor()')
    .func(nil, 'void setTitleColor(const cocos2d::Color3B &value)')
    .func(nil, 'int getTitleFontSize()')
    .func(nil, 'void setTitleFontSize(int value)')
    .func(nil, 'const std::string &getValue()')
    .func(nil, 'void setValue(const std::string &value)')
    .func(nil, 'int getSelectedIndex()')
    .func(nil, 'void setSelectedIndex(int value)')
    .func(nil, '@addref(selectionController ^) fairygui::GController *getSelectionController()')
    .func(nil, 'void setSelectionController(@addref(selectionController ^) fairygui::GController *value)')
    .func(nil, 'std::vector<std::string> &getItems()')
    .func(nil, 'std::vector<std::string> &getIcons()')
    .func(nil, 'std::vector<std::string> &getValues()')
    .func(nil, '@addref(dropdown ^) fairygui::GObject *getDropdown()')
    .func(nil, 'void refresh()')
    .func(nil, '@addref(textField ^) fairygui::GTextField *getTextField()')
    .var('visibleItemCount', 'int visibleItemCount')
    .var('popupDirection', 'fairygui::PopupDirection popupDirection')
    .prop('title', nil, nil)
    .prop('titleColor', nil, nil)
    .prop('titleFontSize', nil, nil)
    .prop('value', nil, nil)
    .prop('selectedIndex', nil, nil)
    .prop('selectionController', nil, nil)
    .prop('items', nil, nil)
    .prop('icons', nil, nil)
    .prop('values', nil, nil)
    .prop('dropdown', nil, nil)
    .prop('textField', nil, nil)

typeconf 'fairygui::GRichTextField'
    .supercls('fairygui::GTextField')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror(nil)
    .func(nil, 'GRichTextField()')
    .func(nil, 'static fairygui::GRichTextField *create()')
    .func(nil, 'fairygui::HtmlObject *getControl(const std::string &name)')

typeconf 'fairygui::GSlider'
    .supercls('fairygui::GComponent')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror(nil)
    .func(nil, 'GSlider()')
    .func(nil, 'static fairygui::GSlider *create()')
    .func(nil, 'fairygui::ProgressTitleType getTitleType()')
    .func(nil, 'void setTitleType(fairygui::ProgressTitleType value)')
    .func(nil, 'double getMin()')
    .func(nil, 'void setMin(double value)')
    .func(nil, 'double getMax()')
    .func(nil, 'void setMax(double value)')
    .func(nil, 'double getValue()')
    .func(nil, 'void setValue(double value)')
    .func(nil, 'bool getWholeNumbers()')
    .func(nil, 'void setWholeNumbers(bool value)')
    .var('changeOnClick', 'bool changeOnClick')
    .var('canDrag', 'bool canDrag')
    .prop('titleType', nil, nil)
    .prop('min', nil, nil)
    .prop('max', nil, nil)
    .prop('value', nil, nil)
    .prop('wholeNumbers', nil, nil)

typeconf 'fairygui::GTextInput'
    .supercls('fairygui::GTextField')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror(nil)
    .func(nil, 'GTextInput()')
    .func(nil, 'static fairygui::GTextInput *create()')
    .func(nil, 'void setPrompt(const std::string &value)')
    .func(nil, 'void setPassword(bool value)')
    .func(nil, 'void setKeyboardType(int value)')
    .func(nil, 'void setMaxLength(int value)')
    .func(nil, 'void setRestrict(const std::string &value)')

typeconf 'fairygui::PopupMenu'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror(nil)
    .func(nil, 'static fairygui::PopupMenu *create(const std::string &resourceURL)', 'static fairygui::PopupMenu *create()')
    .func(nil, 'PopupMenu()')
    .func(nil, 'void addSeperator()')
    .func(nil, 'const std::string &getItemName(int index)')
    .func(nil, 'void setItemText(const std::string &name, const std::string &caption)')
    .func(nil, 'void setItemVisible(const std::string &name, bool visible)')
    .func(nil, 'void setItemGrayed(const std::string &name, bool grayed)')
    .func(nil, 'void setItemCheckable(const std::string &name, bool checkable)')
    .func(nil, 'void setItemChecked(const std::string &name, bool check)')
    .func(nil, 'bool isItemChecked(const std::string &name)')
    .func(nil, '@delref(children ~ parent) bool removeItem(const std::string &name)')
    .func(nil, '@delref(children ~ parent) void clearItems()')
    .func(nil, 'int getItemCount()')
    .func(nil, '@addref(contentPane ^) fairygui::GComponent *getContentPane()')
    .func(nil, '@addref(list ^) fairygui::GList *getList()')
    .func(nil, '@delref(children ~ parent)@addref(children | parent) void show()', '@delref(children ~ parent)@addref(children | parent) void show(fairygui::GObject *target, fairygui::PopupDirection dir)')
    .callback {
        funcs =  {
            '@addref(children | parent) fairygui::GButton *addItem(const std::string &caption, @localvar fairygui::EventCallback callback)'
        },
        tag_maker = 'makeListenerTag(L, fairygui::UIEventType::ClickMenu, 0)',
        tag_mode = 'replace',
        tag_store = -1,
        tag_scope = 'object',
    }
    .callback {
        funcs =  {
            '@addref(children | parent) fairygui::GButton *addItemAt(const std::string &caption, int index, @localvar fairygui::EventCallback callback)'
        },
        tag_maker = 'makeListenerTag(L, fairygui::UIEventType::ClickMenu, 0)',
        tag_mode = 'replace',
        tag_store = -1,
        tag_scope = 'object',
    }
    .prop('itemCount', nil, nil)
    .prop('contentPane', nil, nil)
    .prop('list', nil, nil)
    .insert('show', {
        before = [[
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
        after = nil,
        cbefore = nil,
        cafter = nil,
    })
    .insert('removeItem', {
        before = [[
            olua_push_cppobj<fairygui::GList>(L, self->getList());
            int parent = lua_gettop(L);
        ]],
        after = nil,
        cbefore = nil,
        cafter = nil,
    })
    .insert('clearItems', {
        before = [[
            olua_push_cppobj<fairygui::GList>(L, self->getList());
            int parent = lua_gettop(L);
        ]],
        after = nil,
        cbefore = nil,
        cafter = nil,
    })
    .insert('addItem', {
        before = [[
            olua_push_cppobj<fairygui::GList>(L, self->getList());
            int parent = lua_gettop(L);
        ]],
        after = nil,
        cbefore = nil,
        cafter = nil,
    })
    .insert('addItemAt', {
        before = [[
            olua_push_cppobj<fairygui::GList>(L, self->getList());
            int parent = lua_gettop(L);
        ]],
        after = nil,
        cbefore = nil,
        cafter = nil,
    })

typeconf 'fairygui::Relations'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror(nil)
    .func(nil, 'Relations(fairygui::GObject *owner)')
    .func(nil, 'void add(fairygui::GObject *target, fairygui::RelationType relationType)', 'void add(fairygui::GObject *target, fairygui::RelationType relationType, bool usePercent)')
    .func(nil, 'void remove(fairygui::GObject *target, fairygui::RelationType relationType)')
    .func(nil, 'bool contains(fairygui::GObject *target)')
    .func(nil, 'void clearFor(fairygui::GObject *target)')
    .func(nil, 'void clearAll()')
    .func(nil, 'void copyFrom(const fairygui::Relations &source)')
    .func(nil, 'void onOwnerSizeChanged(float dWidth, float dHeight, bool applyPivot)')
    .func(nil, 'bool isEmpty()')
    .var('handling', 'fairygui::GObject *handling')
    .prop('empty', nil, nil)

typeconf 'fairygui::RelationType'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror('rw')
    .enum('Left_Left', 'fairygui::RelationType::Left_Left')
    .enum('Left_Center', 'fairygui::RelationType::Left_Center')
    .enum('Left_Right', 'fairygui::RelationType::Left_Right')
    .enum('Center_Center', 'fairygui::RelationType::Center_Center')
    .enum('Right_Left', 'fairygui::RelationType::Right_Left')
    .enum('Right_Center', 'fairygui::RelationType::Right_Center')
    .enum('Right_Right', 'fairygui::RelationType::Right_Right')
    .enum('Top_Top', 'fairygui::RelationType::Top_Top')
    .enum('Top_Middle', 'fairygui::RelationType::Top_Middle')
    .enum('Top_Bottom', 'fairygui::RelationType::Top_Bottom')
    .enum('Middle_Middle', 'fairygui::RelationType::Middle_Middle')
    .enum('Bottom_Top', 'fairygui::RelationType::Bottom_Top')
    .enum('Bottom_Middle', 'fairygui::RelationType::Bottom_Middle')
    .enum('Bottom_Bottom', 'fairygui::RelationType::Bottom_Bottom')
    .enum('Width', 'fairygui::RelationType::Width')
    .enum('Height', 'fairygui::RelationType::Height')
    .enum('LeftExt_Left', 'fairygui::RelationType::LeftExt_Left')
    .enum('LeftExt_Right', 'fairygui::RelationType::LeftExt_Right')
    .enum('RightExt_Left', 'fairygui::RelationType::RightExt_Left')
    .enum('RightExt_Right', 'fairygui::RelationType::RightExt_Right')
    .enum('TopExt_Top', 'fairygui::RelationType::TopExt_Top')
    .enum('TopExt_Bottom', 'fairygui::RelationType::TopExt_Bottom')
    .enum('BottomExt_Top', 'fairygui::RelationType::BottomExt_Top')
    .enum('BottomExt_Bottom', 'fairygui::RelationType::BottomExt_Bottom')
    .enum('Size', 'fairygui::RelationType::Size')

typeconf 'fairygui::RelationItem'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror(nil)
    .func(nil, 'RelationItem(fairygui::GObject *owner)')
    .func(nil, '@addref(target ^) fairygui::GObject *getTarget()')
    .func(nil, 'void setTarget(@addref(target ^) fairygui::GObject *value)')
    .func(nil, 'void add(fairygui::RelationType relationType, bool usePercent)')
    .func(nil, 'void internalAdd(fairygui::RelationType relationType, bool usePercent)')
    .func(nil, 'void remove(fairygui::RelationType relationType)')
    .func(nil, 'void copyFrom(const fairygui::RelationItem &source)')
    .func(nil, 'bool isEmpty()')
    .func(nil, 'void applyOnSelfSizeChanged(float dWidth, float dHeight, bool applyPivot)')
    .prop('target', nil, nil)
    .prop('empty', nil, nil)

typeconf 'fairygui::ScrollPane'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror(nil)
    .func(nil, 'ScrollPane(fairygui::GComponent *owner)')
    .func(nil, '@addref(owner ^) fairygui::GComponent *getOwner()')
    .func(nil, '@addref(header ^) fairygui::GComponent *getHeader()')
    .func(nil, '@addref(footer ^) fairygui::GComponent *getFooter()')
    .func(nil, '@addref(vtScrollBar ^) fairygui::GScrollBar *getVtScrollBar()')
    .func(nil, '@addref(hzScrollBar ^) fairygui::GScrollBar *getHzScrollBar()')
    .func(nil, 'bool isBouncebackEffect()')
    .func(nil, 'void setBouncebackEffect(bool value)')
    .func(nil, 'bool isTouchEffect()')
    .func(nil, 'void setTouchEffect(bool value)')
    .func(nil, 'bool isInertiaDisabled()')
    .func(nil, 'void setInertiaDisabled(bool value)')
    .func(nil, 'float getScrollStep()')
    .func(nil, 'void setScrollStep(float value)')
    .func(nil, 'bool isSnapToItem()')
    .func(nil, 'void setSnapToItem(bool value)')
    .func(nil, 'bool isPageMode()')
    .func(nil, 'void setPageMode(bool value)')
    .func(nil, '@addref(pageController ^) fairygui::GController *getPageController()')
    .func(nil, 'void setPageController(@addref(pageController ^) fairygui::GController *value)')
    .func(nil, 'bool isMouseWheelEnabled()')
    .func(nil, 'void setMouseWheelEnabled(bool value)')
    .func(nil, 'float getDecelerationRate()')
    .func(nil, 'void setDecelerationRate(float value)')
    .func(nil, 'float getPosX()')
    .func(nil, 'void setPosX(float value, @optional bool ani)')
    .func(nil, 'float getPosY()')
    .func(nil, 'void setPosY(float value, @optional bool ani)')
    .func(nil, 'float getPercX()')
    .func(nil, 'void setPercX(float value, @optional bool ani)')
    .func(nil, 'float getPercY()')
    .func(nil, 'void setPercY(float value, @optional bool ani)')
    .func(nil, 'bool isBottomMost()')
    .func(nil, 'bool isRightMost()')
    .func(nil, 'void scrollLeft(@optional float ratio, @optional bool ani)')
    .func(nil, 'void scrollRight(@optional float ratio, @optional bool ani)')
    .func(nil, 'void scrollUp(@optional float ratio, @optional bool ani)')
    .func(nil, 'void scrollDown(@optional float ratio, @optional bool ani)')
    .func(nil, 'void scrollTop(@optional bool ani)')
    .func(nil, 'void scrollBottom(@optional bool ani)')
    .func(nil, 'void scrollToView(fairygui::GObject *obj, @optional bool ani, @optional bool setFirst)', 'void scrollToView(const cocos2d::Rect &rect, @optional bool ani, @optional bool setFirst)')
    .func(nil, 'bool isChildInView(fairygui::GObject *obj)')
    .func(nil, 'int getPageX()')
    .func(nil, 'void setPageX(int value, @optional bool ani)')
    .func(nil, 'int getPageY()')
    .func(nil, 'void setPageY(int value, @optional bool ani)')
    .func(nil, 'float getScrollingPosX()')
    .func(nil, 'float getScrollingPosY()')
    .func(nil, 'const cocos2d::Size &getContentSize()')
    .func(nil, 'const cocos2d::Size &getViewSize()')
    .func(nil, 'void lockHeader(int size)')
    .func(nil, 'void lockFooter(int size)')
    .func(nil, 'void cancelDragging()')
    .func(nil, 'static fairygui::ScrollPane *getDraggingPane()')
    .prop('owner', nil, nil)
    .prop('header', nil, nil)
    .prop('footer', nil, nil)
    .prop('vtScrollBar', nil, nil)
    .prop('hzScrollBar', nil, nil)
    .prop('bouncebackEffect', nil, nil)
    .prop('touchEffect', nil, nil)
    .prop('inertiaDisabled', nil, nil)
    .prop('scrollStep', nil, nil)
    .prop('snapToItem', nil, nil)
    .prop('pageMode', nil, nil)
    .prop('pageController', nil, nil)
    .prop('mouseWheelEnabled', nil, nil)
    .prop('decelerationRate', nil, nil)
    .prop('posX', nil, nil)
    .prop('posY', nil, nil)
    .prop('percX', nil, nil)
    .prop('percY', nil, nil)
    .prop('bottomMost', nil, nil)
    .prop('rightMost', nil, nil)
    .prop('pageX', nil, nil)
    .prop('pageY', nil, nil)
    .prop('scrollingPosX', nil, nil)
    .prop('scrollingPosY', nil, nil)
    .prop('contentSize', nil, nil)
    .prop('viewSize', nil, nil)
    .prop('draggingPane', nil, nil)

typeconf 'fairygui::Transition::PlayCompleteCallback'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror(nil)

typeconf 'fairygui::Transition::TransitionHook'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror(nil)

typeconf 'fairygui::Transition'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror(nil)
    .func(nil, 'Transition(fairygui::GComponent *owner)')
    .func(nil, '@addref(owner ^) fairygui::GComponent *getOwner()')
    .func(nil, 'bool isPlaying()')
    .func(nil, 'void changePlayTimes(int value)')
    .func(nil, 'void stop()', 'void stop(bool setToComplete, bool processCallback)')
    .func(nil, 'void setAutoPlay(bool autoPlay, int times, float delay)')
    .func(nil, 'void setPaused(bool paused)')
    .func(nil, 'void setValue(const std::string &label, const cocos2d::ValueVector &values)')
    .func(nil, 'void setTarget(const std::string &label, fairygui::GObject *newTarget)')
    .func(nil, 'void setDuration(const std::string &label, float value)')
    .func(nil, 'float getLabelTime(const std::string &label)')
    .func(nil, 'float getTimeScale()')
    .func(nil, 'void setTimeScale(float value)')
    .func(nil, 'void updateFromRelations(const std::string &targetId, float dx, float dy)')
    .func(nil, 'void onOwnerAddedToStage()')
    .func(nil, 'void onOwnerRemovedFromStage()')
    .var('name', 'std::string name')
    .callback {
        funcs =  {
            'void play(@localvar @optional fairygui::Transition::PlayCompleteCallback callback)',
            'void play(int times, float delay, @localvar @optional fairygui::Transition::PlayCompleteCallback callback)',
            'void play(int times, float delay, float startTime, float endTime, @localvar @optional fairygui::Transition::PlayCompleteCallback callback)'
        },
        tag_maker = 'play',
        tag_mode = 'replace',
        tag_store = 0,
        tag_scope = 'object',
    }
    .callback {
        funcs =  {
            'void playReverse(@localvar @optional fairygui::Transition::PlayCompleteCallback callback)',
            'void playReverse(int times, float delay, @localvar @optional fairygui::Transition::PlayCompleteCallback callback)'
        },
        tag_maker = 'playReverse',
        tag_mode = 'replace',
        tag_store = 0,
        tag_scope = 'object',
    }
    .callback {
        funcs =  {
            'void setHook(const std::string &label, @localvar @nullable fairygui::Transition::TransitionHook callback)'
        },
        tag_maker = '("hook." + #1)',
        tag_mode = 'replace',
        tag_store = 0,
        tag_scope = 'object',
    }
    .callback {
        funcs =  {
            'void clearHooks()'
        },
        tag_maker = '("hook.")',
        tag_mode = 'substartwith',
        tag_store = 0,
        tag_scope = 'object',
    }
    .prop('owner', nil, nil)
    .prop('playing', nil, nil)
    .prop('timeScale', nil, nil)

typeconf 'fairygui::UIConfig'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror(nil)
    .func(nil, 'static void registerFont(const std::string &aliasName, const std::string &realName)')
    .func(nil, 'static const std::string &getRealFontName(const std::string &aliasName, @ret bool *isTTF)')
    .var('defaultFont', 'static std::string defaultFont')
    .var('buttonSound', 'static std::string buttonSound')
    .var('buttonSoundVolumeScale', 'static float buttonSoundVolumeScale')
    .var('defaultScrollStep', 'static int defaultScrollStep')
    .var('defaultScrollDecelerationRate', 'static float defaultScrollDecelerationRate')
    .var('defaultScrollTouchEffect', 'static bool defaultScrollTouchEffect')
    .var('defaultScrollBounceEffect', 'static bool defaultScrollBounceEffect')
    .var('defaultScrollBarDisplay', 'static fairygui::ScrollBarDisplayType defaultScrollBarDisplay')
    .var('verticalScrollBar', 'static std::string verticalScrollBar')
    .var('horizontalScrollBar', 'static std::string horizontalScrollBar')
    .var('touchDragSensitivity', 'static int touchDragSensitivity')
    .var('clickDragSensitivity', 'static int clickDragSensitivity')
    .var('touchScrollSensitivity', 'static int touchScrollSensitivity')
    .var('defaultComboBoxVisibleItemCount', 'static int defaultComboBoxVisibleItemCount')
    .var('globalModalWaiting', 'static std::string globalModalWaiting')
    .var('modalLayerColor', 'static cocos2d::Color4F modalLayerColor')
    .var('tooltipsWin', 'static std::string tooltipsWin')
    .var('bringWindowToFrontOnClick', 'static bool bringWindowToFrontOnClick')
    .var('windowModalWaiting', 'static std::string windowModalWaiting')
    .var('popupMenu', 'static std::string popupMenu')
    .var('popupMenu_seperator', 'static std::string popupMenu_seperator')

typeconf 'fairygui::IUISource'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror(nil)
    .func(nil, 'const std::string &getFileName()')
    .func(nil, 'void setFileName(const std::string &value)')
    .func(nil, 'bool isLoaded()')
    .callback {
        funcs =  {
            'void load(@localvar @nullable std::function<void ()> callback)'
        },
        tag_maker = 'load',
        tag_mode = 'replace',
        tag_store = 0,
        tag_scope = 'object',
    }
    .prop('fileName', nil, nil)
    .prop('loaded', nil, nil)

typeconf 'fairygui::UISource'
    .supercls('fairygui::IUISource')
    .reg_luatype(true)
    .chunk([[
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
    ]])
    .luaopen(nil)
    .indexerror(nil)
    .func('create', 'static UISource *create()')
    .func('loadComplete', 'void loadComplete()')

typeconf 'fairygui::Window'
    .supercls('fairygui::GComponent')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror(nil)
    .func(nil, 'Window()')
    .func(nil, 'static fairygui::Window *create()')
    .func(nil, '@delref(children ~ parent)@addref(children | parent) void show()')
    .func(nil, '@delref(children ~ parent) void hide()')
    .func(nil, '@delref(children ~ parent) void hideImmediately()')
    .func(nil, 'void toggleStatus()')
    .func(nil, 'void bringToFront()')
    .func(nil, 'bool isShowing()')
    .func(nil, 'bool isTop()')
    .func(nil, 'bool isModal()')
    .func(nil, 'void setModal(bool value)')
    .func(nil, 'void showModalWait()', 'void showModalWait(int requestingCmd)')
    .func(nil, 'bool closeModalWait()', 'bool closeModalWait(int requestingCmd)')
    .func(nil, 'void initWindow()')
    .func(nil, 'void addUISource(fairygui::IUISource *uiSource)')
    .func(nil, 'bool isBringToFrontOnClick()')
    .func(nil, 'void setBringToFrontOnClick(bool value)')
    .func(nil, '@addref(contentPane ^) fairygui::GComponent *getContentPane()')
    .func(nil, 'void setContentPane(@addref(contentPane ^) fairygui::GComponent *value)')
    .func(nil, '@addref(frame ^) fairygui::GComponent *getFrame()')
    .func(nil, '@addref(closeButton ^) fairygui::GObject *getCloseButton()')
    .func(nil, 'void setCloseButton(@addref(closeButton ^) fairygui::GObject *value)')
    .func(nil, '@addref(dragArea ^) fairygui::GObject *getDragArea()')
    .func(nil, 'void setDragArea(@addref(dragArea ^) fairygui::GObject *value)')
    .func(nil, '@addref(contentArea ^) fairygui::GObject *getContentArea()')
    .func(nil, 'void setContentArea(@addref(contentArea ^) fairygui::GObject *value)')
    .func(nil, '@addref(modalWaitingPane ^) fairygui::GObject *getModalWaitingPane()')
    .prop('showing', nil, nil)
    .prop('top', nil, nil)
    .prop('modal', nil, nil)
    .prop('bringToFrontOnClick', nil, nil)
    .prop('contentPane', nil, nil)
    .prop('frame', nil, nil)
    .prop('closeButton', nil, nil)
    .prop('dragArea', nil, nil)
    .prop('contentArea', nil, nil)
    .prop('modalWaitingPane', nil, nil)
    .insert('show', {
        before = [[
            fairygui::GComponent *root = fairygui::UIRoot;
            if (!root) {
                luaL_error(L, "no root to add 'Window'");
            }
            olua_push_cppobj<fairygui::GComponent>(L, root);
            int parent = lua_gettop(L);
        ]],
        after = nil,
        cbefore = nil,
        cafter = nil,
    })
    .insert('hide', {
        before = [[
            fairygui::GComponent *root = self->getParent() ? self->getParent() : fairygui::UIRoot;
            if (!root) {
                return 0;
            }
            olua_push_cppobj<fairygui::GComponent>(L, root);
            int parent = lua_gettop(L);
        ]],
        after = nil,
        cbefore = nil,
        cafter = nil,
    })
    .insert('hideImmediately', {
        before = [[
            fairygui::GComponent *root = self->getParent() ? self->getParent() : fairygui::UIRoot;
            if (!root) {
                return 0;
            }
            olua_push_cppobj<fairygui::GComponent>(L, root);
            int parent = lua_gettop(L);
        ]],
        after = nil,
        cbefore = nil,
        cafter = nil,
    })

typeconf 'fairygui::DragDropManager'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror(nil)
    .func(nil, 'DragDropManager()')
    .func(nil, 'static fairygui::DragDropManager *getInstance()')
    .func(nil, 'fairygui::GLoader *getAgent()')
    .func(nil, 'bool isDragging()')
    .func(nil, 'void startDrag(const std::string &icon, @optional const cocos2d::Value &sourceData, @optional int touchPointID)')
    .func(nil, 'void cancel()')
    .prop('instance', nil, nil)
    .prop('agent', nil, nil)
    .prop('dragging', nil, nil)

typeconf 'fairygui::UIObjectFactory::GLoaderCreator'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror(nil)

typeconf 'fairygui::UIObjectFactory::GComponentCreator'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror(nil)

typeconf 'fairygui::UIObjectFactory'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror(nil)
    .func(nil, 'static fairygui::GObject *newObject(fairygui::PackageItem *pi)', 'static fairygui::GObject *newObject(fairygui::ObjectType type)')
    .callback {
        funcs =  {
            'static void setPackageItemExtension(const std::string &url, @localvar fairygui::UIObjectFactory::GComponentCreator creator)'
        },
        tag_maker = 'PackageItemExtension',
        tag_mode = 'replace',
        tag_store = 0,
        tag_scope = 'object',
    }
    .callback {
        funcs =  {
            'static void setLoaderExtension(@localvar fairygui::UIObjectFactory::GLoaderCreator creator)'
        },
        tag_maker = 'LoaderExtension',
        tag_mode = 'replace',
        tag_store = 0,
        tag_scope = 'object',
    }

typeconf 'fairygui::GearBase'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror(nil)
    .func(nil, 'GearBase(fairygui::GObject *owner)')
    .func(nil, 'static fairygui::GearBase *create(fairygui::GObject *owner, int index)')
    .var('disableAllTweenEffect', 'static bool disableAllTweenEffect')

typeconf 'fairygui::GTreeNode'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror(nil)
    .func(nil, 'static fairygui::GTreeNode *create(@optional bool isFolder, @optional const std::string &resURL)')
    .func(nil, 'GTreeNode()')
    .func(nil, 'fairygui::GTreeNode *getParent()')
    .func(nil, 'fairygui::GTree *getTree()')
    .func(nil, '@addref(cell ^) fairygui::GComponent *getCell()')
    .func(nil, 'const cocos2d::Value &getData()')
    .func(nil, 'void setData(const cocos2d::Value &value)')
    .func(nil, 'bool isExpanded()')
    .func(nil, 'void setExpaned(bool value)')
    .func(nil, 'bool isFolder()')
    .func(nil, 'const std::string &getText()')
    .func(nil, 'void setText(const std::string &value)')
    .func(nil, 'const std::string &getIcon()')
    .func(nil, 'void setIcon(const std::string &value)')
    .func(nil, 'fairygui::GTreeNode *addChild(@addref(children |) fairygui::GTreeNode *child)')
    .func(nil, 'fairygui::GTreeNode *addChildAt(@addref(children |) fairygui::GTreeNode *child, int index)')
    .func(nil, 'void removeChild(@delref(children |) fairygui::GTreeNode *child)')
    .func(nil, '@delref(children ~) void removeChildAt(int index)')
    .func(nil, '@delref(children ~) void removeChildren()', '@delref(children ~) void removeChildren(int beginIndex, int endIndex)')
    .func(nil, '@addref(children |) fairygui::GTreeNode *getChildAt(int index)')
    .func(nil, '@addref(children |) fairygui::GTreeNode *getPrevSibling()')
    .func(nil, '@addref(children |) fairygui::GTreeNode *getNextSibling()')
    .func(nil, 'int getChildIndex(const fairygui::GTreeNode *child)')
    .func(nil, 'void setChildIndex(fairygui::GTreeNode *child, int index)')
    .func(nil, 'int setChildIndexBefore(fairygui::GTreeNode *child, int index)')
    .func(nil, 'void swapChildren(fairygui::GTreeNode *child1, fairygui::GTreeNode *child2)')
    .func(nil, 'void swapChildrenAt(int index1, int index2)')
    .func(nil, 'int numChildren()')
    .prop('numChildren', 'int numChildren()', nil)
    .prop('parent', nil, nil)
    .prop('tree', nil, nil)
    .prop('cell', nil, nil)
    .prop('data', nil, nil)
    .prop('expanded', nil, nil)
    .prop('folder', nil, nil)
    .prop('text', nil, nil)
    .prop('icon', nil, nil)
    .prop('prevSibling', nil, nil)
    .prop('nextSibling', nil, nil)

typeconf 'fairygui::GTree::TreeNodeRenderFunction'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror(nil)

typeconf 'fairygui::GTree::TreeNodeWillExpandFunction'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror(nil)

typeconf 'fairygui::GTree'
    .supercls('fairygui::GList')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror(nil)
    .func(nil, 'GTree()')
    .func(nil, 'static fairygui::GTree *create()')
    .func(nil, 'int getIndent()')
    .func(nil, 'void setIndent(int value)')
    .func(nil, 'int getClickToExpand()')
    .func(nil, 'void setClickToExpand(int value)')
    .func(nil, '@addref(rootNode ^) fairygui::GTreeNode *getRootNode()')
    .func(nil, '@addref(nodes |) fairygui::GTreeNode *getSelectedNode()')
    .func(nil, 'void getSelectedNodes(@addref(nodes |)@ret std::vector<GTreeNode *> &result)')
    .func(nil, 'void selectNode(fairygui::GTreeNode *node, @optional bool scrollItToView)')
    .func(nil, 'void unselectNode(fairygui::GTreeNode *node)')
    .func(nil, 'void expandAll(fairygui::GTreeNode *folderNode)')
    .func(nil, 'void collapseAll(fairygui::GTreeNode *folderNode)')
    .var('treeNodeRender', '@nullable fairygui::GTree::TreeNodeRenderFunction treeNodeRender')
    .var('treeNodeWillExpand', '@nullable fairygui::GTree::TreeNodeWillExpandFunction treeNodeWillExpand')
    .prop('indent', nil, nil)
    .prop('clickToExpand', nil, nil)
    .prop('rootNode', nil, nil)
    .prop('selectedNode', nil, nil)
    .insert('treeNodeRender', {
        before = nil,
        after = nil,
        cbefore = [[
            olua_push_cppobj<fairygui::GComponent>(L, (fairygui::GComponent *)cb_store);
            olua_addref(L, -1, "nodes", top + 1, OLUA_FLAG_MULTIPLE);
            olua_addref(L, -1, "children",top + 2, OLUA_FLAG_MULTIPLE);
            lua_pop(L, 1);
        ]],
        cafter = nil,
    })
    .insert('treeNodeWillExpand', {
        before = nil,
        after = nil,
        cbefore = [[
            olua_push_cppobj<fairygui::GComponent>(L, (fairygui::GComponent *)cb_store);
            olua_addref(L, -1, "nodes", top + 1, OLUA_FLAG_MULTIPLE);
            lua_pop(L, 1);
        ]],
        cafter = nil,
    })

typeconf 'fairygui::FUIContainer'
    .supercls('cocos2d::Node')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror(nil)
    .func(nil, 'FUIContainer()')
    .func(nil, 'static fairygui::FUIContainer *create()')
    .func(nil, 'bool isClippingEnabled()')
    .func(nil, 'void setClippingEnabled(bool value)')
    .func(nil, 'const cocos2d::Rect &getClippingRegion()')
    .func(nil, 'void setClippingRegion(const cocos2d::Rect &clippingRegion)')
    .func(nil, 'cocos2d::Node *getStencil()')
    .func(nil, 'void setStencil(cocos2d::Node *stencil)')
    .func(nil, 'float getAlphaThreshold()')
    .func(nil, 'void setAlphaThreshold(float alphaThreshold)')
    .func(nil, 'bool isInverted()')
    .func(nil, 'void setInverted(bool inverted)')
    .var('gOwner', 'fairygui::GObject *gOwner')
    .prop('clippingEnabled', nil, nil)
    .prop('clippingRegion', nil, nil)
    .prop('stencil', nil, nil)
    .prop('alphaThreshold', nil, nil)
    .prop('inverted', nil, nil)

typeconf 'fairygui::FUIInput'
    .supercls('cocos2d::ui::EditBox')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror(nil)
    .func(nil, 'static fairygui::FUIInput *create()')
    .func(nil, 'FUIInput()')
    .func(nil, 'void setText(const std::string &value)')
    .func(nil, 'fairygui::TextFormat *getTextFormat()')
    .func(nil, 'void applyTextFormat()')
    .func(nil, 'bool isSingleLine()')
    .func(nil, 'void setSingleLine(bool value)')
    .func(nil, 'bool isPassword()')
    .func(nil, 'void setPassword(bool value)')
    .func(nil, 'int keyboardType()')
    .func(nil, 'void setKeyboardType(int value)')
    .prop('textFormat', nil, nil)
    .prop('singleLine', nil, nil)
    .prop('password', nil, nil)

typeconf 'fairygui::FUILabel'
    .supercls('cocos2d::Label')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror(nil)
    .func(nil, 'FUILabel()')
    .func(nil, 'static fairygui::FUILabel *create()')
    .func(nil, 'const std::string &getText()')
    .func(nil, 'void setText(const std::string &value)')
    .func(nil, 'fairygui::TextFormat *getTextFormat()')
    .func(nil, 'void applyTextFormat()')
    .func(nil, 'void setUnderlineColor(const cocos2d::Color3B &value)')
    .func(nil, 'bool setBMFontFilePath(const std::string &bmfontFilePath, const cocos2d::Vec2 &imageOffset, @optional float fontSize)', '@using bool setBMFontFilePath(const std::string &bmfontFilePath, @optional float fontSize)', '@using bool setBMFontFilePath(const std::string &bmfontFilePath, const cocos2d::Rect &imageRect, bool imageRotated, @optional float fontSize)', '@using bool setBMFontFilePath(const std::string &bmfontFilePath, const std::string &subTextureKey, @optional float fontSize)')
    .func(nil, 'void setGrayed(bool value)')
    .prop('text', nil, nil)
    .prop('textFormat', nil, nil)

typeconf 'fairygui::FUIRichText'
    .supercls('cocos2d::Node')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror(nil)
    .func(nil, 'FUIRichText()')
    .func(nil, 'static fairygui::FUIRichText *create()')
    .func(nil, 'const cocos2d::Size &getDimensions()')
    .func(nil, 'void setDimensions(float width, float height)')
    .func(nil, 'void setText(const std::string &value)')
    .func(nil, 'fairygui::TextFormat *getTextFormat()')
    .func(nil, 'void applyTextFormat()')
    .func(nil, 'cocos2d::Label::Overflow getOverflow()')
    .func(nil, 'void setOverflow(cocos2d::Label::Overflow overflow)')
    .func(nil, 'bool isAnchorTextUnderline()')
    .func(nil, 'void setAnchorTextUnderline(bool enable)')
    .func(nil, 'const cocos2d::Color3B &getAnchorFontColor()')
    .func(nil, 'void setAnchorFontColor(const cocos2d::Color3B &color)')
    .func(nil, 'fairygui::HtmlParseOptions &parseOptions()')
    .func(nil, 'const std::vector<HtmlObject *> &getControls()')
    .func(nil, 'fairygui::HtmlObject *getControl(const std::string &name)')
    .func(nil, 'const char *hitTestLink(const cocos2d::Vec2 &worldPoint)')
    .callback {
        funcs =  {
            'void setObjectFactory(@localvar const std::function<HtmlObject *(HtmlElement *)> &value)'
        },
        tag_maker = 'ObjectFactory',
        tag_mode = 'replace',
        tag_store = 0,
        tag_scope = 'object',
    }
    .prop('textFormat', nil, nil)
    .prop('overflow', nil, nil)
    .prop('anchorTextUnderline', nil, nil)
    .prop('anchorFontColor', nil, nil)
    .prop('controls', nil, nil)

typeconf 'fairygui::FUISprite'
    .supercls('cocos2d::Sprite')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror(nil)
    .func(nil, 'FUISprite()')
    .func(nil, 'static fairygui::FUISprite *create()')
    .func(nil, 'void clearContent()')
    .func(nil, 'void setGrayed(bool value)')
    .func(nil, 'fairygui::FillMethod getFillMethod()')
    .func(nil, 'void setFillMethod(fairygui::FillMethod value)')
    .func(nil, 'fairygui::FillOrigin getFillOrigin()')
    .func(nil, 'void setFillOrigin(fairygui::FillOrigin value)')
    .func(nil, 'bool isFillClockwise()')
    .func(nil, 'void setFillClockwise(bool value)')
    .func(nil, 'float getFillAmount()')
    .func(nil, 'void setFillAmount(float value)')
    .func(nil, 'bool isScaleByTile()')
    .func(nil, 'void setScaleByTile(bool value)')
    .prop('fillMethod', nil, nil)
    .prop('fillOrigin', nil, nil)
    .prop('fillClockwise', nil, nil)
    .prop('fillAmount', nil, nil)
    .prop('scaleByTile', nil, nil)

typeconf 'fairygui::HtmlObject'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror(nil)
    .func(nil, 'HtmlObject()')
    .func(nil, 'fairygui::HtmlElement *getElement()')
    .func(nil, 'fairygui::GObject *getUI()')
    .func(nil, 'bool isHidden()')
    .func(nil, 'void create(fairygui::FUIRichText *owner, fairygui::HtmlElement *element)')
    .func(nil, 'void destroy()')
    .var('buttonResource', 'static std::string buttonResource')
    .var('inputResource', 'static std::string inputResource')
    .var('selectResource', 'static std::string selectResource')
    .var('usePool', 'static bool usePool')
    .var('loaderPool', 'static cocos2d::Vector<GObject *> loaderPool')
    .prop('element', nil, nil)
    .prop('ui', nil, nil)
    .prop('hidden', nil, nil)

typeconf 'fairygui::HtmlElement::Type'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror('rw')
    .enum('TEXT', 'fairygui::HtmlElement::Type::TEXT')
    .enum('IMAGE', 'fairygui::HtmlElement::Type::IMAGE')
    .enum('LINK', 'fairygui::HtmlElement::Type::LINK')
    .enum('INPUT', 'fairygui::HtmlElement::Type::INPUT')
    .enum('SELECT', 'fairygui::HtmlElement::Type::SELECT')
    .enum('OBJECT', 'fairygui::HtmlElement::Type::OBJECT')

typeconf 'fairygui::HtmlElement'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror(nil)
    .func(nil, 'HtmlElement(fairygui::HtmlElement::Type type)')
    .func(nil, 'int getInt(const std::string &attrName, @optional int defValue)')
    .func(nil, 'std::string getString(const std::string &attrName, @optional const std::string &defValue)')
    .func(nil, 'cocos2d::ValueVector &getArray(const std::string &attrName)')
    .var('type', 'fairygui::HtmlElement::Type type')
    .var('text', 'std::string text')
    .var('format', 'fairygui::TextFormat format')
    .var('link', 'fairygui::HtmlElement *link')
    .var('obj', 'fairygui::HtmlObject *obj')
    .var('space', 'int space')
    .var('attrs', 'cocos2d::ValueMap attrs')
