local cls = class(M)
cls.CPPCLS = "fairygui::UIEventDispatcher"
cls.LUACLS = "fgui.UIEventDispatcher"
cls.SUPERCLS = "cc.Ref"
cls.DEFCHUNK = [[
static std::string makeUIEventDispatcherTag(lua_State *L, int typeidx, int tagidx)
{
    char buf[64];
    if (typeidx > 0) {
        int type = (int)olua_checkinteger(L, typeidx);
        if (tagidx > 0) {
            intptr_t p = 0;
            if (olua_isinteger(L, tagidx)) {
                p = (uintptr_t)olua_tointeger(L, tagidx);
            } else {
                p = (uintptr_t)olua_checkobj(L, tagidx, OLUA_VOIDCLS);
            }
            sprintf(buf, "listeners.%d.%ld", type, p);
        } else {
            sprintf(buf, "listeners.%d", type);
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
        CALLBACK_MAKER = {'makeUIEventDispatcherTag(L, 2, 0)', 'makeUIEventDispatcherTag(L, 2, 4)'},
    }
)

cls.callback(
    'void removeEventListener(int eventType)',
    'void removeEventListener(int eventType, const EventTag& tag)',
    {
        CALLBACK_MAKER = {'makeUIEventDispatcherTag(L, 2, 0)', 'makeUIEventDispatcherTag(L, 2, 3)'},
        CALLBACK_REMOVE = true,
        CALLBACK_MODE = {'OLUA_CALLBACK_TAG_WILDCARD', 'OLUA_CALLBACK_TAG_ENDWITH'},
    }
)

cls.callback(
    'void removeEventListeners()',
    {
        CALLBACK_MAKER = 'makeUIEventDispatcherTag(L, 0, 0)',
        CALLBACK_REMOVE = true,
        CALLBACK_MODE = 'OLUA_CALLBACK_TAG_WILDCARD',
    }
)

return cls