local cls = class(M)
cls.CPPCLS = "fairygui::UIEventDispatcher"
cls.LUACLS = "fui.UIEventDispatcher"
cls.SUPERCLS = "cc.Ref"
cls.DEFCHUNK = [[
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
    if (type >= 0) {
        if (tag > 0) {
            sprintf(buf, "listeners.%d.%ld", (int)type, tag);
        } else {
            sprintf(buf, "listeners.%d", (int)type);
        }
    } else {
        sprintf(buf, "listeners.");
    }
    return std::string(buf);
}
]]
cls.funcs [[
    bool hasEventListener(int eventType)
    bool hasEventListener(int eventType, const EventTag& tag)
    bool dispatchEvent(int eventType, void* data = nullptr, const cocos2d::Value& dataValue = cocos2d::Value::Null)
    bool bubbleEvent(int eventType, void* data = nullptr, const cocos2d::Value& dataValue = cocos2d::Value::Null)
    bool isDispatchingEvent(int eventType)
]]

cls.callback(
    'void addEventListener(int eventType, const std::function<void(@stack EventContext* context)>& callback)',
    'void addEventListener(int eventType, const std::function<void(@stack EventContext* context)>& callback, const EventTag& tag)',
    {
        CALLBACK_MAKER = {'makeListenerTag(L, #1, 0)', 'makeListenerTag(L, #1, 4)'},
    }
)

cls.callback(
    'void removeEventListener(int eventType)',
    'void removeEventListener(int eventType, const EventTag& tag)',
    {
        CALLBACK_MAKER = {'makeListenerTag(L, #1, 0)', 'makeListenerTag(L, #1, 3)'},
        CALLBACK_REMOVE = true,
        CALLBACK_MODE = {'OLUA_CALLBACK_TAG_WILDCARD', 'OLUA_CALLBACK_TAG_ENDWITH'},
    }
)

cls.callback(
    'void removeEventListeners()',
    {
        CALLBACK_MAKER = 'makeListenerTag(L, -1, 0)',
        CALLBACK_REMOVE = true,
        CALLBACK_MODE = 'OLUA_CALLBACK_TAG_WILDCARD',
    }
)

return cls