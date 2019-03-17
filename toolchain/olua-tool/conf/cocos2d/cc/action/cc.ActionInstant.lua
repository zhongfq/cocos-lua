local M = {}

local cls = class(M)
cls.CPPCLS = "cocos2d::ActionInstant"
cls.LUACLS = "cc.ActionInstant"
cls.SUPERCLS = "cc.FiniteTimeAction"

local cls = class(M)
cls.CPPCLS = "cocos2d::Show"
cls.LUACLS = "cc.Show"
cls.SUPERCLS = "cc.ActionInstant"
cls.funcs([[
    static Show * create()
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::Hide"
cls.LUACLS = "cc.Hide"
cls.SUPERCLS = "cc.ActionInstant"
cls.funcs([[
    static Hide * create()
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::ToggleVisibility"
cls.LUACLS = "cc.ToggleVisibility"
cls.SUPERCLS = "cc.ActionInstant"
cls.funcs([[
    static ToggleVisibility * create()
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::RemoveSelf"
cls.LUACLS = "cc.RemoveSelf"
cls.SUPERCLS = "cc.ActionInstant"
cls.funcs([[
    static RemoveSelf * create(bool isNeedCleanUp = true)
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::FlipX"
cls.LUACLS = "cc.FlipX"
cls.SUPERCLS = "cc.ActionInstant"
cls.funcs([[
    static FlipX * create(bool x)
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::FlipY"
cls.LUACLS = "cc.FlipY"
cls.SUPERCLS = "cc.ActionInstant"
cls.funcs([[
    static FlipY * create(bool y)
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::Place"
cls.LUACLS = "cc.Place"
cls.SUPERCLS = "cc.ActionInstant"
cls.funcs([[
    static Place * create(const Vec2& pos)
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::CallFunc"
cls.LUACLS = "cc.CallFunc"
cls.SUPERCLS = "cc.ActionInstant"
cls.funcs([[
    Ref* getTargetCallback()
    void setTargetCallback(Ref* sel)
]])
cls.func('create', [[
{
    lua_settop(L, 1);
    
    cocos2d::CallFunc *self = new cocos2d::CallFunc();
    self->autorelease();
    olua_push_cppobj<cocos2d::CallFunc>(L, self, "cc.CallFunc");

    void *callback_store_obj = (void *)self;
    std::string tag = olua_makecallbacktag("callFunc");
    std::string func = olua_setcallback(L, callback_store_obj, tag.c_str(), 1, OLUA_CALLBACK_TAG_NEW);
    std::function<void()> callback = [callback_store_obj, func, tag]() {
        lua_State *L = xlua_cocosthread();
        int top = lua_gettop(L);

        olua_callback(L, callback_store_obj, func.c_str(), 0);

        lua_settop(L, top);
    };
    
    self->initWithFunction(callback);

    return olua_push_cppobj<cocos2d::CallFunc>(L, self, "cc.CallFunc");
}]])

return M