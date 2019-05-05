local cls = class()
cls.CPPCLS = "fairygui::GTween"
cls.LUACLS = "fui.GTween"
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
}
]]
cls.funcs [[
    static GTweener* to(float startValue, float endValue, float duration)
    static GTweener* to(const cocos2d::Vec4& startValue, const cocos2d::Vec4& endValue, float duration)
    static GTweener* to(const cocos2d::Vec3& startValue, const cocos2d::Vec3& endValue, float duration)
    static GTweener* to(const cocos2d::Vec2& startValue, const cocos2d::Vec2& endValue, float duration)
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

-- ref
local REFNAME = 'tweeners'
local UNREF_TWEEN = {
    AFTER = format_snippet [[
        olua_getstore(L, "fui.GTween");
        olua_mapwalkunref(L, -1, "${REFNAME}", should_unref_tween);
        lua_pop(L, 1);
    ]]
}
local REF_TEWEENER = {
    AFTER = format_snippet [[
        olua_getstore(L, "fui.GTween");
        olua_mapwalkunref(L, -1, "${REFNAME}", should_unref_tween);
        olua_mapref(L, -1, "${REFNAME}", -2);
        lua_pop(L, 1);
    ]]
}
cls.inject('to', REF_TEWEENER)
cls.inject('toDouble', REF_TEWEENER)
cls.inject('delayedCall', REF_TEWEENER)
cls.inject('shake', REF_TEWEENER)
cls.inject('kill', UNREF_TWEEN)
cls.inject('clean', mapunref_all(REFNAME))

return cls