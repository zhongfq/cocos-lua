//
// AUTO BUILD, DON'T MODIFY!
//
#include "lua-bindings/lua_fairygui.h"
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "xgame/xlua.h"
#include "FairyGUI.h"
#include "tween/EaseManager.h"
#include "tween/GPath.h"
#include "display/FUISprite.h"

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

int auto_olua_push_fairygui_Margin(lua_State *L, const fairygui::Margin *value)
{
    if (value) {
        lua_createtable(L, 0, 4);

        olua_push_number(L, (lua_Number)value->left);
        olua_setfield(L, -2, "left");

        olua_push_number(L, (lua_Number)value->top);
        olua_setfield(L, -2, "top");

        olua_push_number(L, (lua_Number)value->right);
        olua_setfield(L, -2, "right");

        olua_push_number(L, (lua_Number)value->bottom);
        olua_setfield(L, -2, "bottom");
    } else {
        lua_pushnil(L);
    }

    return 1;
}

void auto_olua_check_fairygui_Margin(lua_State *L, int idx, fairygui::Margin *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);
    luaL_checktype(L, idx, LUA_TTABLE);

    lua_Number arg1 = 0;       /** left */
    lua_Number arg2 = 0;       /** top */
    lua_Number arg3 = 0;       /** right */
    lua_Number arg4 = 0;       /** bottom */

    olua_getfield(L, idx, "left");
    olua_check_number(L, -1, &arg1);
    value->left = (float)arg1;
    lua_pop(L, 1);

    olua_getfield(L, idx, "top");
    olua_check_number(L, -1, &arg2);
    value->top = (float)arg2;
    lua_pop(L, 1);

    olua_getfield(L, idx, "right");
    olua_check_number(L, -1, &arg3);
    value->right = (float)arg3;
    lua_pop(L, 1);

    olua_getfield(L, idx, "bottom");
    olua_check_number(L, -1, &arg4);
    value->bottom = (float)arg4;
    lua_pop(L, 1);
}

bool auto_olua_is_fairygui_Margin(lua_State *L, int idx)
{
    return olua_istable(L, idx) && olua_hasfield(L, idx, "bottom") && olua_hasfield(L, idx, "right") && olua_hasfield(L, idx, "top") && olua_hasfield(L, idx, "left");
}

void auto_olua_pack_fairygui_Margin(lua_State *L, int idx, fairygui::Margin *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);

    lua_Number arg1 = 0;       /** left */
    lua_Number arg2 = 0;       /** top */
    lua_Number arg3 = 0;       /** right */
    lua_Number arg4 = 0;       /** bottom */

    olua_check_number(L, idx + 0, &arg1);
    value->left = (float)arg1;

    olua_check_number(L, idx + 1, &arg2);
    value->top = (float)arg2;

    olua_check_number(L, idx + 2, &arg3);
    value->right = (float)arg3;

    olua_check_number(L, idx + 3, &arg4);
    value->bottom = (float)arg4;
}

int auto_olua_unpack_fairygui_Margin(lua_State *L, const fairygui::Margin *value)
{
    if (value) {
        olua_push_number(L, (lua_Number)value->left);
        olua_push_number(L, (lua_Number)value->top);
        olua_push_number(L, (lua_Number)value->right);
        olua_push_number(L, (lua_Number)value->bottom);
    } else {
        for (int i = 0; i < 4; i++) {
            lua_pushnil(L);
        }
    }

    return 4;
}

bool auto_olua_ispack_fairygui_Margin(lua_State *L, int idx)
{
    return olua_is_number(L, idx + 0) && olua_is_number(L, idx + 1) && olua_is_number(L, idx + 2) && olua_is_number(L, idx + 3);
}

int auto_olua_push_fairygui_TweenValue(lua_State *L, const fairygui::TweenValue *value)
{
    if (value) {
        lua_createtable(L, 0, 5);

        olua_push_number(L, (lua_Number)value->x);
        olua_setfield(L, -2, "x");

        olua_push_number(L, (lua_Number)value->y);
        olua_setfield(L, -2, "y");

        olua_push_number(L, (lua_Number)value->z);
        olua_setfield(L, -2, "z");

        olua_push_number(L, (lua_Number)value->w);
        olua_setfield(L, -2, "w");

        olua_push_number(L, (lua_Number)value->d);
        olua_setfield(L, -2, "d");
    } else {
        lua_pushnil(L);
    }

    return 1;
}

void auto_olua_check_fairygui_TweenValue(lua_State *L, int idx, fairygui::TweenValue *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);
    luaL_checktype(L, idx, LUA_TTABLE);

    lua_Number arg1 = 0;       /** x */
    lua_Number arg2 = 0;       /** y */
    lua_Number arg3 = 0;       /** z */
    lua_Number arg4 = 0;       /** w */
    lua_Number arg5 = 0;       /** d */

    olua_getfield(L, idx, "x");
    if (!olua_isnoneornil(L, -1)) {
        olua_check_number(L, -1, &arg1);
        value->x = (float)arg1;
    }
    lua_pop(L, 1);

    olua_getfield(L, idx, "y");
    if (!olua_isnoneornil(L, -1)) {
        olua_check_number(L, -1, &arg2);
        value->y = (float)arg2;
    }
    lua_pop(L, 1);

    olua_getfield(L, idx, "z");
    if (!olua_isnoneornil(L, -1)) {
        olua_check_number(L, -1, &arg3);
        value->z = (float)arg3;
    }
    lua_pop(L, 1);

    olua_getfield(L, idx, "w");
    if (!olua_isnoneornil(L, -1)) {
        olua_check_number(L, -1, &arg4);
        value->w = (float)arg4;
    }
    lua_pop(L, 1);

    olua_getfield(L, idx, "d");
    if (!olua_isnoneornil(L, -1)) {
        olua_check_number(L, -1, &arg5);
        value->d = (double)arg5;
    }
    lua_pop(L, 1);
}

bool auto_olua_is_fairygui_TweenValue(lua_State *L, int idx)
{
    return olua_istable(L, idx);
}

void auto_olua_pack_fairygui_TweenValue(lua_State *L, int idx, fairygui::TweenValue *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);

    lua_Number arg1 = 0;       /** x */
    lua_Number arg2 = 0;       /** y */
    lua_Number arg3 = 0;       /** z */
    lua_Number arg4 = 0;       /** w */
    lua_Number arg5 = 0;       /** d */

    olua_check_number(L, idx + 0, &arg1);
    value->x = (float)arg1;

    olua_check_number(L, idx + 1, &arg2);
    value->y = (float)arg2;

    olua_check_number(L, idx + 2, &arg3);
    value->z = (float)arg3;

    olua_check_number(L, idx + 3, &arg4);
    value->w = (float)arg4;

    olua_check_number(L, idx + 4, &arg5);
    value->d = (double)arg5;
}

int auto_olua_unpack_fairygui_TweenValue(lua_State *L, const fairygui::TweenValue *value)
{
    if (value) {
        olua_push_number(L, (lua_Number)value->x);
        olua_push_number(L, (lua_Number)value->y);
        olua_push_number(L, (lua_Number)value->z);
        olua_push_number(L, (lua_Number)value->w);
        olua_push_number(L, (lua_Number)value->d);
    } else {
        for (int i = 0; i < 5; i++) {
            lua_pushnil(L);
        }
    }

    return 5;
}

bool auto_olua_ispack_fairygui_TweenValue(lua_State *L, int idx)
{
    return olua_is_number(L, idx + 0) && olua_is_number(L, idx + 1) && olua_is_number(L, idx + 2) && olua_is_number(L, idx + 3) && olua_is_number(L, idx + 4);
}

static int _fairygui_UIEventType___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (fairygui::UIEventType *)olua_toobj(L, 1, "fgui.UIEventType");
    olua_push_cppobj(L, self, "fgui.UIEventType");

    olua_endinvoke(L);

    return 1;
}

static int luaopen_fairygui_UIEventType(lua_State *L)
{
    oluacls_class(L, "fgui.UIEventType", nullptr);
    oluacls_func(L, "__move", _fairygui_UIEventType___move);
    oluacls_const_integer(L, "Changed", (lua_Integer)fairygui::UIEventType::Changed);
    oluacls_const_integer(L, "Click", (lua_Integer)fairygui::UIEventType::Click);
    oluacls_const_integer(L, "ClickItem", (lua_Integer)fairygui::UIEventType::ClickItem);
    oluacls_const_integer(L, "ClickLink", (lua_Integer)fairygui::UIEventType::ClickLink);
    oluacls_const_integer(L, "ClickMenu", (lua_Integer)fairygui::UIEventType::ClickMenu);
    oluacls_const_integer(L, "DragEnd", (lua_Integer)fairygui::UIEventType::DragEnd);
    oluacls_const_integer(L, "DragMove", (lua_Integer)fairygui::UIEventType::DragMove);
    oluacls_const_integer(L, "DragStart", (lua_Integer)fairygui::UIEventType::DragStart);
    oluacls_const_integer(L, "Drop", (lua_Integer)fairygui::UIEventType::Drop);
    oluacls_const_integer(L, "Enter", (lua_Integer)fairygui::UIEventType::Enter);
    oluacls_const_integer(L, "Exit", (lua_Integer)fairygui::UIEventType::Exit);
    oluacls_const_integer(L, "GearStop", (lua_Integer)fairygui::UIEventType::GearStop);
    oluacls_const_integer(L, "KeyDown", (lua_Integer)fairygui::UIEventType::KeyDown);
    oluacls_const_integer(L, "KeyUp", (lua_Integer)fairygui::UIEventType::KeyUp);
    oluacls_const_integer(L, "MiddleClick", (lua_Integer)fairygui::UIEventType::MiddleClick);
    oluacls_const_integer(L, "MouseWheel", (lua_Integer)fairygui::UIEventType::MouseWheel);
    oluacls_const_integer(L, "PositionChange", (lua_Integer)fairygui::UIEventType::PositionChange);
    oluacls_const_integer(L, "PullDownRelease", (lua_Integer)fairygui::UIEventType::PullDownRelease);
    oluacls_const_integer(L, "PullUpRelease", (lua_Integer)fairygui::UIEventType::PullUpRelease);
    oluacls_const_integer(L, "RightClick", (lua_Integer)fairygui::UIEventType::RightClick);
    oluacls_const_integer(L, "RightClickItem", (lua_Integer)fairygui::UIEventType::RightClickItem);
    oluacls_const_integer(L, "RollOut", (lua_Integer)fairygui::UIEventType::RollOut);
    oluacls_const_integer(L, "RollOver", (lua_Integer)fairygui::UIEventType::RollOver);
    oluacls_const_integer(L, "Scroll", (lua_Integer)fairygui::UIEventType::Scroll);
    oluacls_const_integer(L, "ScrollEnd", (lua_Integer)fairygui::UIEventType::ScrollEnd);
    oluacls_const_integer(L, "SizeChange", (lua_Integer)fairygui::UIEventType::SizeChange);
    oluacls_const_integer(L, "Submit", (lua_Integer)fairygui::UIEventType::Submit);
    oluacls_const_integer(L, "TouchBegin", (lua_Integer)fairygui::UIEventType::TouchBegin);
    oluacls_const_integer(L, "TouchEnd", (lua_Integer)fairygui::UIEventType::TouchEnd);
    oluacls_const_integer(L, "TouchMove", (lua_Integer)fairygui::UIEventType::TouchMove);

    olua_registerluatype<fairygui::UIEventType>(L, "fgui.UIEventType");

    return 1;
}

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

static int _fairygui_UIEventDispatcher___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (fairygui::UIEventDispatcher *)olua_toobj(L, 1, "fgui.UIEventDispatcher");
    olua_push_cppobj(L, self, "fgui.UIEventDispatcher");

    olua_endinvoke(L);

    return 1;
}

static int _fairygui_UIEventDispatcher_addEventListener1(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::UIEventDispatcher *self = nullptr;
    lua_Integer arg1 = 0;       /** eventType */
    std::function<void(fairygui::EventContext *)> arg2;       /** callback */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.UIEventDispatcher");
    olua_check_int(L, 2, &arg1);

    void *self_obj = (void *)self;
    std::string tag = makeListenerTag(L, arg1, 0);
    std::string func = olua_setcallback(L, self_obj, tag.c_str(), 3, OLUA_TAG_NEW);
    lua_Unsigned ctx = olua_context(L);
    arg2 = [self_obj, func, ctx](fairygui::EventContext *arg1) {
        lua_State *L = olua_mainthread(NULL);

        if (L != NULL && (olua_context(L) == ctx)) {
            int top = lua_gettop(L);
            size_t last = olua_push_objpool(L);
            olua_enable_objpool(L);
            olua_push_cppobj(L, arg1, "fgui.EventContext");
            olua_disable_objpool(L);

            olua_callback(L, self_obj, func.c_str(), 1);

            //pop stack value
            olua_pop_objpool(L, last);
            lua_settop(L, top);
        }
    };

    // void addEventListener(int eventType, @local const std::function<void (EventContext *)> &callback)
    self->addEventListener((int)arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_UIEventDispatcher_addEventListener2(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::UIEventDispatcher *self = nullptr;
    lua_Integer arg1 = 0;       /** eventType */
    std::function<void(fairygui::EventContext *)> arg2;       /** callback */
    fairygui::EventTag arg3;       /** tag */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.UIEventDispatcher");
    olua_check_int(L, 2, &arg1);
    manual_olua_check_fairygui_EventTag(L, 4, &arg3);

    void *self_obj = (void *)self;
    std::string tag = makeListenerTag(L, arg1, 4);
    std::string func = olua_setcallback(L, self_obj, tag.c_str(), 3, OLUA_TAG_NEW);
    lua_Unsigned ctx = olua_context(L);
    arg2 = [self_obj, func, ctx](fairygui::EventContext *arg1) {
        lua_State *L = olua_mainthread(NULL);

        if (L != NULL && (olua_context(L) == ctx)) {
            int top = lua_gettop(L);
            size_t last = olua_push_objpool(L);
            olua_enable_objpool(L);
            olua_push_cppobj(L, arg1, "fgui.EventContext");
            olua_disable_objpool(L);

            olua_callback(L, self_obj, func.c_str(), 1);

            //pop stack value
            olua_pop_objpool(L, last);
            lua_settop(L, top);
        }
    };

    // void addEventListener(int eventType, @local const std::function<void (EventContext *)> &callback, const fairygui::EventTag &tag)
    self->addEventListener((int)arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_UIEventDispatcher_addEventListener(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 2) {
        // if ((olua_is_int(L, 2)) && (olua_is_std_function(L, 3))) {
            // void addEventListener(int eventType, @local const std::function<void (EventContext *)> &callback)
            return _fairygui_UIEventDispatcher_addEventListener1(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_int(L, 2)) && (olua_is_std_function(L, 3)) && (manual_olua_is_fairygui_EventTag(L, 4))) {
            // void addEventListener(int eventType, @local const std::function<void (EventContext *)> &callback, const fairygui::EventTag &tag)
            return _fairygui_UIEventDispatcher_addEventListener2(L);
        // }
    }

    luaL_error(L, "method 'fairygui::UIEventDispatcher::addEventListener' not support '%d' arguments", num_args);

    return 0;
}

static int _fairygui_UIEventDispatcher_bubbleEvent1(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::UIEventDispatcher *self = nullptr;
    lua_Integer arg1 = 0;       /** eventType */
    void *arg2 = nullptr;       /** data */
    cocos2d::Value arg3;       /** dataValue */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.UIEventDispatcher");
    olua_check_int(L, 2, &arg1);
    olua_check_obj(L, 3, (void **)&arg2, "void *");
    manual_olua_check_cocos2d_Value(L, 4, &arg3);

    // bool bubbleEvent(int eventType, @optional void *data, @optional const cocos2d::Value &dataValue)
    bool ret = (bool)self->bubbleEvent((int)arg1, arg2, arg3);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_UIEventDispatcher_bubbleEvent2(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::UIEventDispatcher *self = nullptr;
    lua_Integer arg1 = 0;       /** eventType */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.UIEventDispatcher");
    olua_check_int(L, 2, &arg1);

    // bool bubbleEvent(int eventType, @optional void *data, @optional const cocos2d::Value &dataValue)
    bool ret = (bool)self->bubbleEvent((int)arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_UIEventDispatcher_bubbleEvent3(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::UIEventDispatcher *self = nullptr;
    lua_Integer arg1 = 0;       /** eventType */
    void *arg2 = nullptr;       /** data */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.UIEventDispatcher");
    olua_check_int(L, 2, &arg1);
    olua_check_obj(L, 3, (void **)&arg2, "void *");

    // bool bubbleEvent(int eventType, @optional void *data, @optional const cocos2d::Value &dataValue)
    bool ret = (bool)self->bubbleEvent((int)arg1, arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_UIEventDispatcher_bubbleEvent(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_int(L, 2))) {
            // bool bubbleEvent(int eventType, @optional void *data, @optional const cocos2d::Value &dataValue)
            return _fairygui_UIEventDispatcher_bubbleEvent2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_int(L, 2)) && (olua_is_obj(L, 3, "void *"))) {
            // bool bubbleEvent(int eventType, @optional void *data, @optional const cocos2d::Value &dataValue)
            return _fairygui_UIEventDispatcher_bubbleEvent3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_int(L, 2)) && (olua_is_obj(L, 3, "void *")) && (manual_olua_is_cocos2d_Value(L, 4))) {
            // bool bubbleEvent(int eventType, @optional void *data, @optional const cocos2d::Value &dataValue)
            return _fairygui_UIEventDispatcher_bubbleEvent1(L);
        // }
    }

    luaL_error(L, "method 'fairygui::UIEventDispatcher::bubbleEvent' not support '%d' arguments", num_args);

    return 0;
}

static int _fairygui_UIEventDispatcher_dispatchEvent1(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::UIEventDispatcher *self = nullptr;
    lua_Integer arg1 = 0;       /** eventType */
    void *arg2 = nullptr;       /** data */
    cocos2d::Value arg3;       /** dataValue */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.UIEventDispatcher");
    olua_check_int(L, 2, &arg1);
    olua_check_obj(L, 3, (void **)&arg2, "void *");
    manual_olua_check_cocos2d_Value(L, 4, &arg3);

    // bool dispatchEvent(int eventType, @optional void *data, @optional const cocos2d::Value &dataValue)
    bool ret = (bool)self->dispatchEvent((int)arg1, arg2, arg3);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_UIEventDispatcher_dispatchEvent2(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::UIEventDispatcher *self = nullptr;
    lua_Integer arg1 = 0;       /** eventType */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.UIEventDispatcher");
    olua_check_int(L, 2, &arg1);

    // bool dispatchEvent(int eventType, @optional void *data, @optional const cocos2d::Value &dataValue)
    bool ret = (bool)self->dispatchEvent((int)arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_UIEventDispatcher_dispatchEvent3(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::UIEventDispatcher *self = nullptr;
    lua_Integer arg1 = 0;       /** eventType */
    void *arg2 = nullptr;       /** data */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.UIEventDispatcher");
    olua_check_int(L, 2, &arg1);
    olua_check_obj(L, 3, (void **)&arg2, "void *");

    // bool dispatchEvent(int eventType, @optional void *data, @optional const cocos2d::Value &dataValue)
    bool ret = (bool)self->dispatchEvent((int)arg1, arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_UIEventDispatcher_dispatchEvent(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_int(L, 2))) {
            // bool dispatchEvent(int eventType, @optional void *data, @optional const cocos2d::Value &dataValue)
            return _fairygui_UIEventDispatcher_dispatchEvent2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_int(L, 2)) && (olua_is_obj(L, 3, "void *"))) {
            // bool dispatchEvent(int eventType, @optional void *data, @optional const cocos2d::Value &dataValue)
            return _fairygui_UIEventDispatcher_dispatchEvent3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_int(L, 2)) && (olua_is_obj(L, 3, "void *")) && (manual_olua_is_cocos2d_Value(L, 4))) {
            // bool dispatchEvent(int eventType, @optional void *data, @optional const cocos2d::Value &dataValue)
            return _fairygui_UIEventDispatcher_dispatchEvent1(L);
        // }
    }

    luaL_error(L, "method 'fairygui::UIEventDispatcher::dispatchEvent' not support '%d' arguments", num_args);

    return 0;
}

static int _fairygui_UIEventDispatcher_hasEventListener1(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::UIEventDispatcher *self = nullptr;
    lua_Integer arg1 = 0;       /** eventType */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.UIEventDispatcher");
    olua_check_int(L, 2, &arg1);

    // bool hasEventListener(int eventType)
    bool ret = (bool)self->hasEventListener((int)arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_UIEventDispatcher_hasEventListener2(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::UIEventDispatcher *self = nullptr;
    lua_Integer arg1 = 0;       /** eventType */
    fairygui::EventTag arg2;       /** tag */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.UIEventDispatcher");
    olua_check_int(L, 2, &arg1);
    manual_olua_check_fairygui_EventTag(L, 3, &arg2);

    // bool hasEventListener(int eventType, const fairygui::EventTag &tag)
    bool ret = (bool)self->hasEventListener((int)arg1, arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_UIEventDispatcher_hasEventListener(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_int(L, 2))) {
            // bool hasEventListener(int eventType)
            return _fairygui_UIEventDispatcher_hasEventListener1(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_int(L, 2)) && (manual_olua_is_fairygui_EventTag(L, 3))) {
            // bool hasEventListener(int eventType, const fairygui::EventTag &tag)
            return _fairygui_UIEventDispatcher_hasEventListener2(L);
        // }
    }

    luaL_error(L, "method 'fairygui::UIEventDispatcher::hasEventListener' not support '%d' arguments", num_args);

    return 0;
}

static int _fairygui_UIEventDispatcher_isDispatchingEvent(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::UIEventDispatcher *self = nullptr;
    lua_Integer arg1 = 0;       /** eventType */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.UIEventDispatcher");
    olua_check_int(L, 2, &arg1);

    // bool isDispatchingEvent(int eventType)
    bool ret = (bool)self->isDispatchingEvent((int)arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_UIEventDispatcher_new(lua_State *L)
{
    olua_startinvoke(L);

    // UIEventDispatcher()
    fairygui::UIEventDispatcher *ret = (fairygui::UIEventDispatcher *)new fairygui::UIEventDispatcher();
    int num_ret = olua_push_cppobj(L, ret, "fgui.UIEventDispatcher");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_UIEventDispatcher_removeEventListener1(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::UIEventDispatcher *self = nullptr;
    lua_Integer arg1 = 0;       /** eventType */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.UIEventDispatcher");
    olua_check_int(L, 2, &arg1);

    std::string tag = makeListenerTag(L, arg1, 0);
    void *self_obj = (void *)self;
    olua_removecallback(L, self_obj, tag.c_str(), OLUA_TAG_SUBSTARTWITH);

    // void removeEventListener(int eventType)
    self->removeEventListener((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_UIEventDispatcher_removeEventListener2(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::UIEventDispatcher *self = nullptr;
    lua_Integer arg1 = 0;       /** eventType */
    fairygui::EventTag arg2;       /** tag */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.UIEventDispatcher");
    olua_check_int(L, 2, &arg1);
    manual_olua_check_fairygui_EventTag(L, 3, &arg2);

    std::string tag = makeListenerTag(L, arg1, 3);
    void *self_obj = (void *)self;
    olua_removecallback(L, self_obj, tag.c_str(), OLUA_TAG_SUBEQUAL);

    // void removeEventListener(int eventType, const fairygui::EventTag &tag)
    self->removeEventListener((int)arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_UIEventDispatcher_removeEventListener(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_int(L, 2))) {
            // void removeEventListener(int eventType)
            return _fairygui_UIEventDispatcher_removeEventListener1(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_int(L, 2)) && (manual_olua_is_fairygui_EventTag(L, 3))) {
            // void removeEventListener(int eventType, const fairygui::EventTag &tag)
            return _fairygui_UIEventDispatcher_removeEventListener2(L);
        // }
    }

    luaL_error(L, "method 'fairygui::UIEventDispatcher::removeEventListener' not support '%d' arguments", num_args);

    return 0;
}

static int _fairygui_UIEventDispatcher_removeEventListeners(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::UIEventDispatcher *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.UIEventDispatcher");

    std::string tag = makeListenerTag(L, -1, 0);
    void *self_obj = (void *)self;
    olua_removecallback(L, self_obj, tag.c_str(), OLUA_TAG_SUBSTARTWITH);

    // void removeEventListeners()
    self->removeEventListeners();

    olua_endinvoke(L);

    return 0;
}

static int luaopen_fairygui_UIEventDispatcher(lua_State *L)
{
    oluacls_class(L, "fgui.UIEventDispatcher", "cc.Ref");
    oluacls_func(L, "__move", _fairygui_UIEventDispatcher___move);
    oluacls_func(L, "addEventListener", _fairygui_UIEventDispatcher_addEventListener);
    oluacls_func(L, "bubbleEvent", _fairygui_UIEventDispatcher_bubbleEvent);
    oluacls_func(L, "dispatchEvent", _fairygui_UIEventDispatcher_dispatchEvent);
    oluacls_func(L, "hasEventListener", _fairygui_UIEventDispatcher_hasEventListener);
    oluacls_func(L, "isDispatchingEvent", _fairygui_UIEventDispatcher_isDispatchingEvent);
    oluacls_func(L, "new", _fairygui_UIEventDispatcher_new);
    oluacls_func(L, "removeEventListener", _fairygui_UIEventDispatcher_removeEventListener);
    oluacls_func(L, "removeEventListeners", _fairygui_UIEventDispatcher_removeEventListeners);

    olua_registerluatype<fairygui::UIEventDispatcher>(L, "fgui.UIEventDispatcher");

    return 1;
}

static int _fairygui_EventContext___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (fairygui::EventContext *)olua_toobj(L, 1, "fgui.EventContext");
    lua_pushstring(L, ".ownership");
    olua_getvariable(L, 1);
    if (lua_toboolean(L, -1)) {
        olua_setrawobj(L, 1, nullptr);
        delete self;
    }

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_EventContext___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (fairygui::EventContext *)olua_toobj(L, 1, "fgui.EventContext");
    olua_push_cppobj(L, self, "fgui.EventContext");

    olua_endinvoke(L);

    return 1;
}

static int _fairygui_EventContext_captureTouch(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::EventContext *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.EventContext");

    // void captureTouch()
    self->captureTouch();

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_EventContext_getData(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::EventContext *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.EventContext");

    // void *getData()
    void *ret = (void *)self->getData();
    int num_ret = olua_push_obj(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_EventContext_getDataValue(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::EventContext *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.EventContext");

    // const cocos2d::Value &getDataValue()
    const cocos2d::Value &ret = (const cocos2d::Value &)self->getDataValue();
    int num_ret = manual_olua_push_cocos2d_Value(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_EventContext_getInput(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::EventContext *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.EventContext");

    // fairygui::InputEvent *getInput()
    fairygui::InputEvent *ret = (fairygui::InputEvent *)self->getInput();
    int num_ret = olua_push_cppobj(L, ret, "fgui.InputEvent");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_EventContext_getSender(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::EventContext *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.EventContext");

    // cocos2d::Ref *getSender()
    cocos2d::Ref *ret = (cocos2d::Ref *)self->getSender();
    int num_ret = olua_push_cppobj(L, ret, "cc.Ref");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_EventContext_getType(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::EventContext *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.EventContext");

    // int getType()
    int ret = (int)self->getType();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_EventContext_isDefaultPrevented(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::EventContext *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.EventContext");

    // bool isDefaultPrevented()
    bool ret = (bool)self->isDefaultPrevented();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_EventContext_new(lua_State *L)
{
    olua_startinvoke(L);

    // EventContext()
    fairygui::EventContext *ret = (fairygui::EventContext *)new fairygui::EventContext();
    int num_ret = olua_push_cppobj(L, ret, "fgui.EventContext");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_EventContext_preventDefault(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::EventContext *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.EventContext");

    // void preventDefault()
    self->preventDefault();

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_EventContext_stopPropagation(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::EventContext *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.EventContext");

    // void stopPropagation()
    self->stopPropagation();

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_EventContext_uncaptureTouch(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::EventContext *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.EventContext");

    // void uncaptureTouch()
    self->uncaptureTouch();

    olua_endinvoke(L);

    return 0;
}

static int luaopen_fairygui_EventContext(lua_State *L)
{
    oluacls_class(L, "fgui.EventContext", nullptr);
    oluacls_func(L, "__gc", _fairygui_EventContext___gc);
    oluacls_func(L, "__move", _fairygui_EventContext___move);
    oluacls_func(L, "captureTouch", _fairygui_EventContext_captureTouch);
    oluacls_func(L, "getData", _fairygui_EventContext_getData);
    oluacls_func(L, "getDataValue", _fairygui_EventContext_getDataValue);
    oluacls_func(L, "getInput", _fairygui_EventContext_getInput);
    oluacls_func(L, "getSender", _fairygui_EventContext_getSender);
    oluacls_func(L, "getType", _fairygui_EventContext_getType);
    oluacls_func(L, "isDefaultPrevented", _fairygui_EventContext_isDefaultPrevented);
    oluacls_func(L, "new", _fairygui_EventContext_new);
    oluacls_func(L, "preventDefault", _fairygui_EventContext_preventDefault);
    oluacls_func(L, "stopPropagation", _fairygui_EventContext_stopPropagation);
    oluacls_func(L, "uncaptureTouch", _fairygui_EventContext_uncaptureTouch);
    oluacls_prop(L, "data", _fairygui_EventContext_getData, nullptr);
    oluacls_prop(L, "dataValue", _fairygui_EventContext_getDataValue, nullptr);
    oluacls_prop(L, "defaultPrevented", _fairygui_EventContext_isDefaultPrevented, nullptr);
    oluacls_prop(L, "input", _fairygui_EventContext_getInput, nullptr);
    oluacls_prop(L, "sender", _fairygui_EventContext_getSender, nullptr);
    oluacls_prop(L, "type", _fairygui_EventContext_getType, nullptr);

    olua_registerluatype<fairygui::EventContext>(L, "fgui.EventContext");

    return 1;
}

static int _fairygui_IHitTest___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (fairygui::IHitTest *)olua_toobj(L, 1, "fgui.IHitTest");
    olua_push_cppobj(L, self, "fgui.IHitTest");

    olua_endinvoke(L);

    return 1;
}

static int _fairygui_IHitTest_hitTest(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::IHitTest *self = nullptr;
    fairygui::GComponent *arg1 = nullptr;       /** obj */
    cocos2d::Vec2 arg2;       /** localPoint */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.IHitTest");
    olua_check_cppobj(L, 2, (void **)&arg1, "fgui.GComponent");
    auto_olua_check_cocos2d_Vec2(L, 3, &arg2);

    // bool hitTest(fairygui::GComponent *obj, const cocos2d::Vec2 &localPoint)
    bool ret = (bool)self->hitTest(arg1, arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_fairygui_IHitTest(lua_State *L)
{
    oluacls_class(L, "fgui.IHitTest", nullptr);
    oluacls_func(L, "__move", _fairygui_IHitTest___move);
    oluacls_func(L, "hitTest", _fairygui_IHitTest_hitTest);

    olua_registerluatype<fairygui::IHitTest>(L, "fgui.IHitTest");

    return 1;
}

static int _fairygui_PixelHitTest___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (fairygui::PixelHitTest *)olua_toobj(L, 1, "fgui.PixelHitTest");
    lua_pushstring(L, ".ownership");
    olua_getvariable(L, 1);
    if (lua_toboolean(L, -1)) {
        olua_setrawobj(L, 1, nullptr);
        delete self;
    }

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_PixelHitTest___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (fairygui::PixelHitTest *)olua_toobj(L, 1, "fgui.PixelHitTest");
    olua_push_cppobj(L, self, "fgui.PixelHitTest");

    olua_endinvoke(L);

    return 1;
}

static int _fairygui_PixelHitTest_new(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::PixelHitTestData *arg1 = nullptr;       /** data */
    lua_Integer arg2 = 0;       /** offsetX */
    lua_Integer arg3 = 0;       /** offsetY */

    olua_check_cppobj(L, 1, (void **)&arg1, "fgui.PixelHitTestData");
    olua_check_int(L, 2, &arg2);
    olua_check_int(L, 3, &arg3);

    // PixelHitTest(fairygui::PixelHitTestData *data, int offsetX, int offsetY)
    fairygui::PixelHitTest *ret = (fairygui::PixelHitTest *)new fairygui::PixelHitTest(arg1, (int)arg2, (int)arg3);
    int num_ret = olua_push_cppobj(L, ret, "fgui.PixelHitTest");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_PixelHitTest_get_offsetX(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::PixelHitTest *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.PixelHitTest");

    // int offsetX
    int ret = (int)self->offsetX;
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_PixelHitTest_set_offsetX(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::PixelHitTest *self = nullptr;
    lua_Integer arg1 = 0;       /** offsetX */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.PixelHitTest");
    olua_check_int(L, 2, &arg1);

    // int offsetX
    self->offsetX = (int)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_PixelHitTest_get_offsetY(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::PixelHitTest *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.PixelHitTest");

    // int offsetY
    int ret = (int)self->offsetY;
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_PixelHitTest_set_offsetY(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::PixelHitTest *self = nullptr;
    lua_Integer arg1 = 0;       /** offsetY */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.PixelHitTest");
    olua_check_int(L, 2, &arg1);

    // int offsetY
    self->offsetY = (int)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_PixelHitTest_get_scaleX(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::PixelHitTest *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.PixelHitTest");

    // float scaleX
    float ret = (float)self->scaleX;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_PixelHitTest_set_scaleX(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::PixelHitTest *self = nullptr;
    lua_Number arg1 = 0;       /** scaleX */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.PixelHitTest");
    olua_check_number(L, 2, &arg1);

    // float scaleX
    self->scaleX = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_PixelHitTest_get_scaleY(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::PixelHitTest *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.PixelHitTest");

    // float scaleY
    float ret = (float)self->scaleY;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_PixelHitTest_set_scaleY(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::PixelHitTest *self = nullptr;
    lua_Number arg1 = 0;       /** scaleY */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.PixelHitTest");
    olua_check_number(L, 2, &arg1);

    // float scaleY
    self->scaleY = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int luaopen_fairygui_PixelHitTest(lua_State *L)
{
    oluacls_class(L, "fgui.PixelHitTest", "fgui.IHitTest");
    oluacls_func(L, "__gc", _fairygui_PixelHitTest___gc);
    oluacls_func(L, "__move", _fairygui_PixelHitTest___move);
    oluacls_func(L, "new", _fairygui_PixelHitTest_new);
    oluacls_prop(L, "offsetX", _fairygui_PixelHitTest_get_offsetX, _fairygui_PixelHitTest_set_offsetX);
    oluacls_prop(L, "offsetY", _fairygui_PixelHitTest_get_offsetY, _fairygui_PixelHitTest_set_offsetY);
    oluacls_prop(L, "scaleX", _fairygui_PixelHitTest_get_scaleX, _fairygui_PixelHitTest_set_scaleX);
    oluacls_prop(L, "scaleY", _fairygui_PixelHitTest_get_scaleY, _fairygui_PixelHitTest_set_scaleY);

    olua_registerluatype<fairygui::PixelHitTest>(L, "fgui.PixelHitTest");

    return 1;
}

static int _fairygui_PixelHitTestData___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (fairygui::PixelHitTestData *)olua_toobj(L, 1, "fgui.PixelHitTestData");
    lua_pushstring(L, ".ownership");
    olua_getvariable(L, 1);
    if (lua_toboolean(L, -1)) {
        olua_setrawobj(L, 1, nullptr);
        delete self;
    }

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_PixelHitTestData___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (fairygui::PixelHitTestData *)olua_toobj(L, 1, "fgui.PixelHitTestData");
    olua_push_cppobj(L, self, "fgui.PixelHitTestData");

    olua_endinvoke(L);

    return 1;
}

static int _fairygui_PixelHitTestData_new(lua_State *L)
{
    olua_startinvoke(L);

    // PixelHitTestData()
    fairygui::PixelHitTestData *ret = (fairygui::PixelHitTestData *)new fairygui::PixelHitTestData();
    int num_ret = olua_push_cppobj(L, ret, "fgui.PixelHitTestData");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_PixelHitTestData_get_pixelWidth(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::PixelHitTestData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.PixelHitTestData");

    // int pixelWidth
    int ret = (int)self->pixelWidth;
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_PixelHitTestData_set_pixelWidth(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::PixelHitTestData *self = nullptr;
    lua_Integer arg1 = 0;       /** pixelWidth */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.PixelHitTestData");
    olua_check_int(L, 2, &arg1);

    // int pixelWidth
    self->pixelWidth = (int)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_PixelHitTestData_get_pixels(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::PixelHitTestData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.PixelHitTestData");

    // unsigned char *pixels
    unsigned char *ret = (unsigned char *)self->pixels;
    int num_ret = olua_push_string(L, (const char *)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_PixelHitTestData_set_pixels(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::PixelHitTestData *self = nullptr;
    const char *arg1 = nullptr;       /** pixels */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.PixelHitTestData");
    olua_check_string(L, 2, &arg1);

    // unsigned char *pixels
    self->pixels = (unsigned char *)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_PixelHitTestData_get_pixelsLength(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::PixelHitTestData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.PixelHitTestData");

    // size_t pixelsLength
    size_t ret = (size_t)self->pixelsLength;
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_PixelHitTestData_set_pixelsLength(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::PixelHitTestData *self = nullptr;
    lua_Unsigned arg1 = 0;       /** pixelsLength */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.PixelHitTestData");
    olua_check_uint(L, 2, &arg1);

    // size_t pixelsLength
    self->pixelsLength = (size_t)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_PixelHitTestData_get_scale(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::PixelHitTestData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.PixelHitTestData");

    // float scale
    float ret = (float)self->scale;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_PixelHitTestData_set_scale(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::PixelHitTestData *self = nullptr;
    lua_Number arg1 = 0;       /** scale */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.PixelHitTestData");
    olua_check_number(L, 2, &arg1);

    // float scale
    self->scale = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int luaopen_fairygui_PixelHitTestData(lua_State *L)
{
    oluacls_class(L, "fgui.PixelHitTestData", nullptr);
    oluacls_func(L, "__gc", _fairygui_PixelHitTestData___gc);
    oluacls_func(L, "__move", _fairygui_PixelHitTestData___move);
    oluacls_func(L, "new", _fairygui_PixelHitTestData_new);
    oluacls_prop(L, "pixelWidth", _fairygui_PixelHitTestData_get_pixelWidth, _fairygui_PixelHitTestData_set_pixelWidth);
    oluacls_prop(L, "pixels", _fairygui_PixelHitTestData_get_pixels, _fairygui_PixelHitTestData_set_pixels);
    oluacls_prop(L, "pixelsLength", _fairygui_PixelHitTestData_get_pixelsLength, _fairygui_PixelHitTestData_set_pixelsLength);
    oluacls_prop(L, "scale", _fairygui_PixelHitTestData_get_scale, _fairygui_PixelHitTestData_set_scale);

    olua_registerluatype<fairygui::PixelHitTestData>(L, "fgui.PixelHitTestData");

    return 1;
}

static int _fairygui_InputProcessor___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (fairygui::InputProcessor *)olua_toobj(L, 1, "fgui.InputProcessor");
    lua_pushstring(L, ".ownership");
    olua_getvariable(L, 1);
    if (lua_toboolean(L, -1)) {
        olua_setrawobj(L, 1, nullptr);
        delete self;
    }

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_InputProcessor___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (fairygui::InputProcessor *)olua_toobj(L, 1, "fgui.InputProcessor");
    olua_push_cppobj(L, self, "fgui.InputProcessor");

    olua_endinvoke(L);

    return 1;
}

static int _fairygui_InputProcessor_addTouchMonitor(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::InputProcessor *self = nullptr;
    lua_Integer arg1 = 0;       /** touchId */
    fairygui::GObject *arg2 = nullptr;       /** target */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.InputProcessor");
    olua_check_int(L, 2, &arg1);
    olua_check_cppobj(L, 3, (void **)&arg2, "fgui.GObject");

    // void addTouchMonitor(int touchId, fairygui::GObject *target)
    self->addTouchMonitor((int)arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_InputProcessor_cancelClick(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::InputProcessor *self = nullptr;
    lua_Integer arg1 = 0;       /** touchId */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.InputProcessor");
    olua_check_int(L, 2, &arg1);

    // void cancelClick(int touchId)
    self->cancelClick((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_InputProcessor_disableDefaultTouchEvent(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::InputProcessor *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.InputProcessor");

    // void disableDefaultTouchEvent()
    self->disableDefaultTouchEvent();

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_InputProcessor_getRecentInput(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::InputProcessor *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.InputProcessor");

    // fairygui::InputEvent *getRecentInput()
    fairygui::InputEvent *ret = (fairygui::InputEvent *)self->getRecentInput();
    int num_ret = olua_push_cppobj(L, ret, "fgui.InputEvent");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_InputProcessor_getTouchPosition(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::InputProcessor *self = nullptr;
    lua_Integer arg1 = 0;       /** touchId */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.InputProcessor");
    olua_check_int(L, 2, &arg1);

    // cocos2d::Vec2 getTouchPosition(int touchId)
    cocos2d::Vec2 ret = (cocos2d::Vec2)self->getTouchPosition((int)arg1);
    int num_ret = auto_olua_push_cocos2d_Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_InputProcessor_isTouchOnUI(lua_State *L)
{
    olua_startinvoke(L);

    // static bool isTouchOnUI()
    bool ret = (bool)fairygui::InputProcessor::isTouchOnUI();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_InputProcessor_new(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComponent *arg1 = nullptr;       /** owner */

    olua_check_cppobj(L, 1, (void **)&arg1, "fgui.GComponent");

    // InputProcessor(fairygui::GComponent *owner)
    fairygui::InputProcessor *ret = (fairygui::InputProcessor *)new fairygui::InputProcessor(arg1);
    int num_ret = olua_push_cppobj(L, ret, "fgui.InputProcessor");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_InputProcessor_removeTouchMonitor(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::InputProcessor *self = nullptr;
    fairygui::GObject *arg1 = nullptr;       /** target */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.InputProcessor");
    olua_check_cppobj(L, 2, (void **)&arg1, "fgui.GObject");

    // void removeTouchMonitor(fairygui::GObject *target)
    self->removeTouchMonitor(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_InputProcessor_setCaptureCallback(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::InputProcessor *self = nullptr;
    std::function<void(int)> arg1;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.InputProcessor");

    if (olua_is_std_function(L, 2)) {
        void *self_obj = (void *)self;
        std::string tag = "CaptureCallback";
        std::string func = olua_setcallback(L, self_obj, tag.c_str(), 2, OLUA_TAG_REPLACE);
        lua_Unsigned ctx = olua_context(L);
        arg1 = [self_obj, func, ctx](int arg1) {
            lua_State *L = olua_mainthread(NULL);

            if (L != NULL && (olua_context(L) == ctx)) {
                int top = lua_gettop(L);
                olua_push_int(L, (lua_Integer)arg1);

                olua_callback(L, self_obj, func.c_str(), 1);

                lua_settop(L, top);
            }
        };
    } else {
        void *self_obj = (void *)self;
        std::string tag = "CaptureCallback";
        olua_removecallback(L, self_obj, tag.c_str(), OLUA_TAG_SUBEQUAL);
        arg1 = nullptr;
    }

    // void setCaptureCallback(@nullable @local std::function<void (int)> value)
    self->setCaptureCallback(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_InputProcessor_simulateClick1(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::InputProcessor *self = nullptr;
    fairygui::GObject *arg1 = nullptr;       /** target */
    lua_Integer arg2 = 0;       /** touchId */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.InputProcessor");
    olua_check_cppobj(L, 2, (void **)&arg1, "fgui.GObject");
    olua_check_int(L, 3, &arg2);

    // void simulateClick(fairygui::GObject *target, @optional int touchId)
    self->simulateClick(arg1, (int)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_InputProcessor_simulateClick2(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::InputProcessor *self = nullptr;
    fairygui::GObject *arg1 = nullptr;       /** target */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.InputProcessor");
    olua_check_cppobj(L, 2, (void **)&arg1, "fgui.GObject");

    // void simulateClick(fairygui::GObject *target, @optional int touchId)
    self->simulateClick(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_InputProcessor_simulateClick(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_cppobj(L, 2, "fgui.GObject"))) {
            // void simulateClick(fairygui::GObject *target, @optional int touchId)
            return _fairygui_InputProcessor_simulateClick2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_cppobj(L, 2, "fgui.GObject")) && (olua_is_int(L, 3))) {
            // void simulateClick(fairygui::GObject *target, @optional int touchId)
            return _fairygui_InputProcessor_simulateClick1(L);
        // }
    }

    luaL_error(L, "method 'fairygui::InputProcessor::simulateClick' not support '%d' arguments", num_args);

    return 0;
}

static int _fairygui_InputProcessor_touchDown(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::InputProcessor *self = nullptr;
    cocos2d::Touch *arg1 = nullptr;       /** touch */
    cocos2d::Event *arg2 = nullptr;       /** event */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.InputProcessor");
    olua_check_cppobj(L, 2, (void **)&arg1, "cc.Touch");
    olua_check_cppobj(L, 3, (void **)&arg2, "cc.Event");

    // bool touchDown(cocos2d::Touch *touch, cocos2d::Event *event)
    bool ret = (bool)self->touchDown(arg1, arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_InputProcessor_touchMove(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::InputProcessor *self = nullptr;
    cocos2d::Touch *arg1 = nullptr;       /** touch */
    cocos2d::Event *arg2 = nullptr;       /** event */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.InputProcessor");
    olua_check_cppobj(L, 2, (void **)&arg1, "cc.Touch");
    olua_check_cppobj(L, 3, (void **)&arg2, "cc.Event");

    // void touchMove(cocos2d::Touch *touch, cocos2d::Event *event)
    self->touchMove(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_InputProcessor_touchUp(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::InputProcessor *self = nullptr;
    cocos2d::Touch *arg1 = nullptr;       /** touch */
    cocos2d::Event *arg2 = nullptr;       /** event */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.InputProcessor");
    olua_check_cppobj(L, 2, (void **)&arg1, "cc.Touch");
    olua_check_cppobj(L, 3, (void **)&arg2, "cc.Event");

    // void touchUp(cocos2d::Touch *touch, cocos2d::Event *event)
    self->touchUp(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_fairygui_InputProcessor(lua_State *L)
{
    oluacls_class(L, "fgui.InputProcessor", nullptr);
    oluacls_func(L, "__gc", _fairygui_InputProcessor___gc);
    oluacls_func(L, "__move", _fairygui_InputProcessor___move);
    oluacls_func(L, "addTouchMonitor", _fairygui_InputProcessor_addTouchMonitor);
    oluacls_func(L, "cancelClick", _fairygui_InputProcessor_cancelClick);
    oluacls_func(L, "disableDefaultTouchEvent", _fairygui_InputProcessor_disableDefaultTouchEvent);
    oluacls_func(L, "getRecentInput", _fairygui_InputProcessor_getRecentInput);
    oluacls_func(L, "getTouchPosition", _fairygui_InputProcessor_getTouchPosition);
    oluacls_func(L, "isTouchOnUI", _fairygui_InputProcessor_isTouchOnUI);
    oluacls_func(L, "new", _fairygui_InputProcessor_new);
    oluacls_func(L, "removeTouchMonitor", _fairygui_InputProcessor_removeTouchMonitor);
    oluacls_func(L, "setCaptureCallback", _fairygui_InputProcessor_setCaptureCallback);
    oluacls_func(L, "simulateClick", _fairygui_InputProcessor_simulateClick);
    oluacls_func(L, "touchDown", _fairygui_InputProcessor_touchDown);
    oluacls_func(L, "touchMove", _fairygui_InputProcessor_touchMove);
    oluacls_func(L, "touchUp", _fairygui_InputProcessor_touchUp);
    oluacls_prop(L, "recentInput", _fairygui_InputProcessor_getRecentInput, nullptr);
    oluacls_prop(L, "touchOnUI", _fairygui_InputProcessor_isTouchOnUI, nullptr);

    olua_registerluatype<fairygui::InputProcessor>(L, "fgui.InputProcessor");

    return 1;
}

static int _fairygui_InputEvent___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (fairygui::InputEvent *)olua_toobj(L, 1, "fgui.InputEvent");
    lua_pushstring(L, ".ownership");
    olua_getvariable(L, 1);
    if (lua_toboolean(L, -1)) {
        olua_setrawobj(L, 1, nullptr);
        delete self;
    }

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_InputEvent___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (fairygui::InputEvent *)olua_toobj(L, 1, "fgui.InputEvent");
    olua_push_cppobj(L, self, "fgui.InputEvent");

    olua_endinvoke(L);

    return 1;
}

static int _fairygui_InputEvent_getButton(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::InputEvent *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.InputEvent");

    // cocos2d::EventMouse::MouseButton getButton()
    cocos2d::EventMouse::MouseButton ret = (cocos2d::EventMouse::MouseButton)self->getButton();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_InputEvent_getKeyCode(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::InputEvent *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.InputEvent");

    // cocos2d::EventKeyboard::KeyCode getKeyCode()
    cocos2d::EventKeyboard::KeyCode ret = (cocos2d::EventKeyboard::KeyCode)self->getKeyCode();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_InputEvent_getMouseWheelDelta(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::InputEvent *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.InputEvent");

    // int getMouseWheelDelta()
    int ret = (int)self->getMouseWheelDelta();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_InputEvent_getPosition(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::InputEvent *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.InputEvent");

    // const cocos2d::Vec2 &getPosition()
    const cocos2d::Vec2 &ret = (const cocos2d::Vec2 &)self->getPosition();
    int num_ret = auto_olua_push_cocos2d_Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_InputEvent_getProcessor(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::InputEvent *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.InputEvent");

    // fairygui::InputProcessor *getProcessor()
    fairygui::InputProcessor *ret = (fairygui::InputProcessor *)self->getProcessor();
    int num_ret = olua_push_cppobj(L, ret, "fgui.InputProcessor");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_InputEvent_getTarget(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::InputEvent *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.InputEvent");

    // fairygui::GObject *getTarget()
    fairygui::GObject *ret = (fairygui::GObject *)self->getTarget();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GObject");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_InputEvent_getTouch(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::InputEvent *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.InputEvent");

    // cocos2d::Touch *getTouch()
    cocos2d::Touch *ret = (cocos2d::Touch *)self->getTouch();
    int num_ret = olua_push_cppobj(L, ret, "cc.Touch");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_InputEvent_getTouchId(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::InputEvent *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.InputEvent");

    // int getTouchId()
    int ret = (int)self->getTouchId();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_InputEvent_getX(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::InputEvent *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.InputEvent");

    // const int getX()
    const int ret = (const int)self->getX();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_InputEvent_getY(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::InputEvent *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.InputEvent");

    // const int getY()
    const int ret = (const int)self->getY();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_InputEvent_isAltDown(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::InputEvent *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.InputEvent");

    // bool isAltDown()
    bool ret = (bool)self->isAltDown();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_InputEvent_isCtrlDown(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::InputEvent *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.InputEvent");

    // bool isCtrlDown()
    bool ret = (bool)self->isCtrlDown();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_InputEvent_isDoubleClick(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::InputEvent *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.InputEvent");

    // int isDoubleClick()
    int ret = (int)self->isDoubleClick();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_InputEvent_isShiftDown(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::InputEvent *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.InputEvent");

    // bool isShiftDown()
    bool ret = (bool)self->isShiftDown();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_InputEvent_new(lua_State *L)
{
    olua_startinvoke(L);

    // InputEvent()
    fairygui::InputEvent *ret = (fairygui::InputEvent *)new fairygui::InputEvent();
    int num_ret = olua_push_cppobj(L, ret, "fgui.InputEvent");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_fairygui_InputEvent(lua_State *L)
{
    oluacls_class(L, "fgui.InputEvent", nullptr);
    oluacls_func(L, "__gc", _fairygui_InputEvent___gc);
    oluacls_func(L, "__move", _fairygui_InputEvent___move);
    oluacls_func(L, "getButton", _fairygui_InputEvent_getButton);
    oluacls_func(L, "getKeyCode", _fairygui_InputEvent_getKeyCode);
    oluacls_func(L, "getMouseWheelDelta", _fairygui_InputEvent_getMouseWheelDelta);
    oluacls_func(L, "getPosition", _fairygui_InputEvent_getPosition);
    oluacls_func(L, "getProcessor", _fairygui_InputEvent_getProcessor);
    oluacls_func(L, "getTarget", _fairygui_InputEvent_getTarget);
    oluacls_func(L, "getTouch", _fairygui_InputEvent_getTouch);
    oluacls_func(L, "getTouchId", _fairygui_InputEvent_getTouchId);
    oluacls_func(L, "getX", _fairygui_InputEvent_getX);
    oluacls_func(L, "getY", _fairygui_InputEvent_getY);
    oluacls_func(L, "isAltDown", _fairygui_InputEvent_isAltDown);
    oluacls_func(L, "isCtrlDown", _fairygui_InputEvent_isCtrlDown);
    oluacls_func(L, "isDoubleClick", _fairygui_InputEvent_isDoubleClick);
    oluacls_func(L, "isShiftDown", _fairygui_InputEvent_isShiftDown);
    oluacls_func(L, "new", _fairygui_InputEvent_new);
    oluacls_prop(L, "altDown", _fairygui_InputEvent_isAltDown, nullptr);
    oluacls_prop(L, "button", _fairygui_InputEvent_getButton, nullptr);
    oluacls_prop(L, "ctrlDown", _fairygui_InputEvent_isCtrlDown, nullptr);
    oluacls_prop(L, "doubleClick", _fairygui_InputEvent_isDoubleClick, nullptr);
    oluacls_prop(L, "keyCode", _fairygui_InputEvent_getKeyCode, nullptr);
    oluacls_prop(L, "mouseWheelDelta", _fairygui_InputEvent_getMouseWheelDelta, nullptr);
    oluacls_prop(L, "position", _fairygui_InputEvent_getPosition, nullptr);
    oluacls_prop(L, "processor", _fairygui_InputEvent_getProcessor, nullptr);
    oluacls_prop(L, "shiftDown", _fairygui_InputEvent_isShiftDown, nullptr);
    oluacls_prop(L, "target", _fairygui_InputEvent_getTarget, nullptr);
    oluacls_prop(L, "touch", _fairygui_InputEvent_getTouch, nullptr);
    oluacls_prop(L, "touchId", _fairygui_InputEvent_getTouchId, nullptr);
    oluacls_prop(L, "x", _fairygui_InputEvent_getX, nullptr);
    oluacls_prop(L, "y", _fairygui_InputEvent_getY, nullptr);

    olua_registerluatype<fairygui::InputEvent>(L, "fgui.InputEvent");

    return 1;
}

static int _fairygui_TextFormat___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (fairygui::TextFormat *)olua_toobj(L, 1, "fgui.TextFormat");
    lua_pushstring(L, ".ownership");
    olua_getvariable(L, 1);
    if (lua_toboolean(L, -1)) {
        olua_setrawobj(L, 1, nullptr);
        delete self;
    }

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_TextFormat___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (fairygui::TextFormat *)olua_toobj(L, 1, "fgui.TextFormat");
    olua_push_cppobj(L, self, "fgui.TextFormat");

    olua_endinvoke(L);

    return 1;
}

static int _fairygui_TextFormat_disableEffect(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::TextFormat *self = nullptr;
    lua_Integer arg1 = 0;       /** effectFlag */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.TextFormat");
    olua_check_int(L, 2, &arg1);

    // void disableEffect(int effectFlag)
    self->disableEffect((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_TextFormat_enableEffect(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::TextFormat *self = nullptr;
    lua_Integer arg1 = 0;       /** effectFlag */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.TextFormat");
    olua_check_int(L, 2, &arg1);

    // void enableEffect(int effectFlag)
    self->enableEffect((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_TextFormat_hasEffect(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::TextFormat *self = nullptr;
    lua_Integer arg1 = 0;       /** effectFlag */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.TextFormat");
    olua_check_int(L, 2, &arg1);

    // bool hasEffect(int effectFlag)
    bool ret = (bool)self->hasEffect((int)arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_TextFormat_new(lua_State *L)
{
    olua_startinvoke(L);

    // TextFormat()
    fairygui::TextFormat *ret = (fairygui::TextFormat *)new fairygui::TextFormat();
    int num_ret = olua_push_cppobj(L, ret, "fgui.TextFormat");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_TextFormat_setFormat(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::TextFormat *self = olua_toobj<fairygui::TextFormat>(L, 1);
    fairygui::TextFormat *fmt = olua_checkobj<fairygui::TextFormat>(L, 2);
    self->setFormat(*fmt);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_TextFormat_get_align(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::TextFormat *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.TextFormat");

    // cocos2d::TextHAlignment align
    cocos2d::TextHAlignment ret = (cocos2d::TextHAlignment)self->align;
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_TextFormat_set_align(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::TextFormat *self = nullptr;
    lua_Unsigned arg1 = 0;       /** align */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.TextFormat");
    olua_check_uint(L, 2, &arg1);

    // cocos2d::TextHAlignment align
    self->align = (cocos2d::TextHAlignment)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_TextFormat_get_bold(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::TextFormat *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.TextFormat");

    // bool bold
    bool ret = (bool)self->bold;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_TextFormat_set_bold(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::TextFormat *self = nullptr;
    bool arg1 = false;       /** bold */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.TextFormat");
    olua_check_bool(L, 2, &arg1);

    // bool bold
    self->bold = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_TextFormat_get_color(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::TextFormat *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.TextFormat");

    // cocos2d::Color3B color
    cocos2d::Color3B ret = (cocos2d::Color3B)self->color;
    int num_ret = manual_olua_push_cocos2d_Color3B(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_TextFormat_set_color(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::TextFormat *self = nullptr;
    cocos2d::Color3B arg1;       /** color */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.TextFormat");
    manual_olua_check_cocos2d_Color3B(L, 2, &arg1);

    // cocos2d::Color3B color
    self->color = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_TextFormat_get_effect(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::TextFormat *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.TextFormat");

    // int effect
    int ret = (int)self->effect;
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_TextFormat_set_effect(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::TextFormat *self = nullptr;
    lua_Integer arg1 = 0;       /** effect */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.TextFormat");
    olua_check_int(L, 2, &arg1);

    // int effect
    self->effect = (int)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_TextFormat_get_face(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::TextFormat *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.TextFormat");

    // std::string face
    std::string ret = (std::string)self->face;
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_TextFormat_set_face(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::TextFormat *self = nullptr;
    std::string arg1;       /** face */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.TextFormat");
    olua_check_std_string(L, 2, &arg1);

    // std::string face
    self->face = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_TextFormat_get_fontSize(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::TextFormat *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.TextFormat");

    // float fontSize
    float ret = (float)self->fontSize;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_TextFormat_set_fontSize(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::TextFormat *self = nullptr;
    lua_Number arg1 = 0;       /** fontSize */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.TextFormat");
    olua_check_number(L, 2, &arg1);

    // float fontSize
    self->fontSize = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_TextFormat_get_glowColor(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::TextFormat *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.TextFormat");

    // cocos2d::Color3B glowColor
    cocos2d::Color3B ret = (cocos2d::Color3B)self->glowColor;
    int num_ret = manual_olua_push_cocos2d_Color3B(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_TextFormat_set_glowColor(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::TextFormat *self = nullptr;
    cocos2d::Color3B arg1;       /** glowColor */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.TextFormat");
    manual_olua_check_cocos2d_Color3B(L, 2, &arg1);

    // cocos2d::Color3B glowColor
    self->glowColor = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_TextFormat_get_italics(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::TextFormat *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.TextFormat");

    // bool italics
    bool ret = (bool)self->italics;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_TextFormat_set_italics(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::TextFormat *self = nullptr;
    bool arg1 = false;       /** italics */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.TextFormat");
    olua_check_bool(L, 2, &arg1);

    // bool italics
    self->italics = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_TextFormat_get_letterSpacing(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::TextFormat *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.TextFormat");

    // int letterSpacing
    int ret = (int)self->letterSpacing;
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_TextFormat_set_letterSpacing(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::TextFormat *self = nullptr;
    lua_Integer arg1 = 0;       /** letterSpacing */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.TextFormat");
    olua_check_int(L, 2, &arg1);

    // int letterSpacing
    self->letterSpacing = (int)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_TextFormat_get_lineSpacing(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::TextFormat *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.TextFormat");

    // int lineSpacing
    int ret = (int)self->lineSpacing;
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_TextFormat_set_lineSpacing(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::TextFormat *self = nullptr;
    lua_Integer arg1 = 0;       /** lineSpacing */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.TextFormat");
    olua_check_int(L, 2, &arg1);

    // int lineSpacing
    self->lineSpacing = (int)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_TextFormat_get_outlineColor(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::TextFormat *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.TextFormat");

    // cocos2d::Color3B outlineColor
    cocos2d::Color3B ret = (cocos2d::Color3B)self->outlineColor;
    int num_ret = manual_olua_push_cocos2d_Color3B(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_TextFormat_set_outlineColor(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::TextFormat *self = nullptr;
    cocos2d::Color3B arg1;       /** outlineColor */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.TextFormat");
    manual_olua_check_cocos2d_Color3B(L, 2, &arg1);

    // cocos2d::Color3B outlineColor
    self->outlineColor = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_TextFormat_get_outlineSize(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::TextFormat *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.TextFormat");

    // int outlineSize
    int ret = (int)self->outlineSize;
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_TextFormat_set_outlineSize(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::TextFormat *self = nullptr;
    lua_Integer arg1 = 0;       /** outlineSize */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.TextFormat");
    olua_check_int(L, 2, &arg1);

    // int outlineSize
    self->outlineSize = (int)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_TextFormat_get_shadowBlurRadius(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::TextFormat *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.TextFormat");

    // int shadowBlurRadius
    int ret = (int)self->shadowBlurRadius;
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_TextFormat_set_shadowBlurRadius(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::TextFormat *self = nullptr;
    lua_Integer arg1 = 0;       /** shadowBlurRadius */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.TextFormat");
    olua_check_int(L, 2, &arg1);

    // int shadowBlurRadius
    self->shadowBlurRadius = (int)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_TextFormat_get_shadowColor(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::TextFormat *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.TextFormat");

    // cocos2d::Color3B shadowColor
    cocos2d::Color3B ret = (cocos2d::Color3B)self->shadowColor;
    int num_ret = manual_olua_push_cocos2d_Color3B(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_TextFormat_set_shadowColor(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::TextFormat *self = nullptr;
    cocos2d::Color3B arg1;       /** shadowColor */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.TextFormat");
    manual_olua_check_cocos2d_Color3B(L, 2, &arg1);

    // cocos2d::Color3B shadowColor
    self->shadowColor = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_TextFormat_get_shadowOffset(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::TextFormat *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.TextFormat");

    // cocos2d::Size shadowOffset
    cocos2d::Size ret = (cocos2d::Size)self->shadowOffset;
    int num_ret = auto_olua_push_cocos2d_Size(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_TextFormat_set_shadowOffset(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::TextFormat *self = nullptr;
    cocos2d::Size arg1;       /** shadowOffset */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.TextFormat");
    auto_olua_check_cocos2d_Size(L, 2, &arg1);

    // cocos2d::Size shadowOffset
    self->shadowOffset = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_TextFormat_get_underline(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::TextFormat *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.TextFormat");

    // bool underline
    bool ret = (bool)self->underline;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_TextFormat_set_underline(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::TextFormat *self = nullptr;
    bool arg1 = false;       /** underline */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.TextFormat");
    olua_check_bool(L, 2, &arg1);

    // bool underline
    self->underline = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_TextFormat_get_verticalAlign(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::TextFormat *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.TextFormat");

    // cocos2d::TextVAlignment verticalAlign
    cocos2d::TextVAlignment ret = (cocos2d::TextVAlignment)self->verticalAlign;
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_TextFormat_set_verticalAlign(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::TextFormat *self = nullptr;
    lua_Unsigned arg1 = 0;       /** verticalAlign */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.TextFormat");
    olua_check_uint(L, 2, &arg1);

    // cocos2d::TextVAlignment verticalAlign
    self->verticalAlign = (cocos2d::TextVAlignment)arg1;

    olua_endinvoke(L);

    return 0;
}

static int luaopen_fairygui_TextFormat(lua_State *L)
{
    oluacls_class(L, "fgui.TextFormat", nullptr);
    oluacls_func(L, "__gc", _fairygui_TextFormat___gc);
    oluacls_func(L, "__move", _fairygui_TextFormat___move);
    oluacls_func(L, "disableEffect", _fairygui_TextFormat_disableEffect);
    oluacls_func(L, "enableEffect", _fairygui_TextFormat_enableEffect);
    oluacls_func(L, "hasEffect", _fairygui_TextFormat_hasEffect);
    oluacls_func(L, "new", _fairygui_TextFormat_new);
    oluacls_func(L, "setFormat", _fairygui_TextFormat_setFormat);
    oluacls_prop(L, "align", _fairygui_TextFormat_get_align, _fairygui_TextFormat_set_align);
    oluacls_prop(L, "bold", _fairygui_TextFormat_get_bold, _fairygui_TextFormat_set_bold);
    oluacls_prop(L, "color", _fairygui_TextFormat_get_color, _fairygui_TextFormat_set_color);
    oluacls_prop(L, "effect", _fairygui_TextFormat_get_effect, _fairygui_TextFormat_set_effect);
    oluacls_prop(L, "face", _fairygui_TextFormat_get_face, _fairygui_TextFormat_set_face);
    oluacls_prop(L, "fontSize", _fairygui_TextFormat_get_fontSize, _fairygui_TextFormat_set_fontSize);
    oluacls_prop(L, "glowColor", _fairygui_TextFormat_get_glowColor, _fairygui_TextFormat_set_glowColor);
    oluacls_prop(L, "italics", _fairygui_TextFormat_get_italics, _fairygui_TextFormat_set_italics);
    oluacls_prop(L, "letterSpacing", _fairygui_TextFormat_get_letterSpacing, _fairygui_TextFormat_set_letterSpacing);
    oluacls_prop(L, "lineSpacing", _fairygui_TextFormat_get_lineSpacing, _fairygui_TextFormat_set_lineSpacing);
    oluacls_prop(L, "outlineColor", _fairygui_TextFormat_get_outlineColor, _fairygui_TextFormat_set_outlineColor);
    oluacls_prop(L, "outlineSize", _fairygui_TextFormat_get_outlineSize, _fairygui_TextFormat_set_outlineSize);
    oluacls_prop(L, "shadowBlurRadius", _fairygui_TextFormat_get_shadowBlurRadius, _fairygui_TextFormat_set_shadowBlurRadius);
    oluacls_prop(L, "shadowColor", _fairygui_TextFormat_get_shadowColor, _fairygui_TextFormat_set_shadowColor);
    oluacls_prop(L, "shadowOffset", _fairygui_TextFormat_get_shadowOffset, _fairygui_TextFormat_set_shadowOffset);
    oluacls_prop(L, "underline", _fairygui_TextFormat_get_underline, _fairygui_TextFormat_set_underline);
    oluacls_prop(L, "verticalAlign", _fairygui_TextFormat_get_verticalAlign, _fairygui_TextFormat_set_verticalAlign);
    oluacls_const_integer(L, "GLOW", (lua_Integer)fairygui::TextFormat::GLOW);
    oluacls_const_integer(L, "OUTLINE", (lua_Integer)fairygui::TextFormat::OUTLINE);
    oluacls_const_integer(L, "SHADOW", (lua_Integer)fairygui::TextFormat::SHADOW);

    olua_registerluatype<fairygui::TextFormat>(L, "fgui.TextFormat");

    return 1;
}

static int luaopen_fairygui_EaseType(lua_State *L)
{
    oluacls_class(L, "fgui.EaseType", nullptr);
    oluacls_const_integer(L, "BackIn", (lua_Integer)fairygui::EaseType::BackIn);
    oluacls_const_integer(L, "BackInOut", (lua_Integer)fairygui::EaseType::BackInOut);
    oluacls_const_integer(L, "BackOut", (lua_Integer)fairygui::EaseType::BackOut);
    oluacls_const_integer(L, "BounceIn", (lua_Integer)fairygui::EaseType::BounceIn);
    oluacls_const_integer(L, "BounceInOut", (lua_Integer)fairygui::EaseType::BounceInOut);
    oluacls_const_integer(L, "BounceOut", (lua_Integer)fairygui::EaseType::BounceOut);
    oluacls_const_integer(L, "CircIn", (lua_Integer)fairygui::EaseType::CircIn);
    oluacls_const_integer(L, "CircInOut", (lua_Integer)fairygui::EaseType::CircInOut);
    oluacls_const_integer(L, "CircOut", (lua_Integer)fairygui::EaseType::CircOut);
    oluacls_const_integer(L, "CubicIn", (lua_Integer)fairygui::EaseType::CubicIn);
    oluacls_const_integer(L, "CubicInOut", (lua_Integer)fairygui::EaseType::CubicInOut);
    oluacls_const_integer(L, "CubicOut", (lua_Integer)fairygui::EaseType::CubicOut);
    oluacls_const_integer(L, "Custom", (lua_Integer)fairygui::EaseType::Custom);
    oluacls_const_integer(L, "ElasticIn", (lua_Integer)fairygui::EaseType::ElasticIn);
    oluacls_const_integer(L, "ElasticInOut", (lua_Integer)fairygui::EaseType::ElasticInOut);
    oluacls_const_integer(L, "ElasticOut", (lua_Integer)fairygui::EaseType::ElasticOut);
    oluacls_const_integer(L, "ExpoIn", (lua_Integer)fairygui::EaseType::ExpoIn);
    oluacls_const_integer(L, "ExpoInOut", (lua_Integer)fairygui::EaseType::ExpoInOut);
    oluacls_const_integer(L, "ExpoOut", (lua_Integer)fairygui::EaseType::ExpoOut);
    oluacls_const_integer(L, "Linear", (lua_Integer)fairygui::EaseType::Linear);
    oluacls_const_integer(L, "QuadIn", (lua_Integer)fairygui::EaseType::QuadIn);
    oluacls_const_integer(L, "QuadInOut", (lua_Integer)fairygui::EaseType::QuadInOut);
    oluacls_const_integer(L, "QuadOut", (lua_Integer)fairygui::EaseType::QuadOut);
    oluacls_const_integer(L, "QuartIn", (lua_Integer)fairygui::EaseType::QuartIn);
    oluacls_const_integer(L, "QuartInOut", (lua_Integer)fairygui::EaseType::QuartInOut);
    oluacls_const_integer(L, "QuartOut", (lua_Integer)fairygui::EaseType::QuartOut);
    oluacls_const_integer(L, "QuintIn", (lua_Integer)fairygui::EaseType::QuintIn);
    oluacls_const_integer(L, "QuintInOut", (lua_Integer)fairygui::EaseType::QuintInOut);
    oluacls_const_integer(L, "QuintOut", (lua_Integer)fairygui::EaseType::QuintOut);
    oluacls_const_integer(L, "SineIn", (lua_Integer)fairygui::EaseType::SineIn);
    oluacls_const_integer(L, "SineInOut", (lua_Integer)fairygui::EaseType::SineInOut);
    oluacls_const_integer(L, "SineOut", (lua_Integer)fairygui::EaseType::SineOut);

    olua_registerluatype<fairygui::EaseType>(L, "fgui.EaseType");

    return 1;
}

static int _fairygui_EaseManager___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (fairygui::EaseManager *)olua_toobj(L, 1, "fgui.EaseManager");
    olua_push_cppobj(L, self, "fgui.EaseManager");

    olua_endinvoke(L);

    return 1;
}

static int _fairygui_EaseManager_evaluate(lua_State *L)
{
    olua_startinvoke(L);

    lua_Unsigned arg1 = 0;       /** easeType */
    lua_Number arg2 = 0;       /** time */
    lua_Number arg3 = 0;       /** duration */
    lua_Number arg4 = 0;       /** overshootOrAmplitude */
    lua_Number arg5 = 0;       /** period */

    olua_check_uint(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);
    olua_check_number(L, 4, &arg4);
    olua_check_number(L, 5, &arg5);

    // static float evaluate(fairygui::EaseType easeType, float time, float duration, float overshootOrAmplitude, float period)
    float ret = (float)fairygui::EaseManager::evaluate((fairygui::EaseType)arg1, (float)arg2, (float)arg3, (float)arg4, (float)arg5);
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_fairygui_EaseManager(lua_State *L)
{
    oluacls_class(L, "fgui.EaseManager", nullptr);
    oluacls_func(L, "__move", _fairygui_EaseManager___move);
    oluacls_func(L, "evaluate", _fairygui_EaseManager_evaluate);

    olua_registerluatype<fairygui::EaseManager>(L, "fgui.EaseManager");

    return 1;
}

static int luaopen_fairygui_TweenPropType(lua_State *L)
{
    oluacls_class(L, "fgui.TweenPropType", nullptr);
    oluacls_const_integer(L, "Alpha", (lua_Integer)fairygui::TweenPropType::Alpha);
    oluacls_const_integer(L, "Height", (lua_Integer)fairygui::TweenPropType::Height);
    oluacls_const_integer(L, "None", (lua_Integer)fairygui::TweenPropType::None);
    oluacls_const_integer(L, "Position", (lua_Integer)fairygui::TweenPropType::Position);
    oluacls_const_integer(L, "Progress", (lua_Integer)fairygui::TweenPropType::Progress);
    oluacls_const_integer(L, "Rotation", (lua_Integer)fairygui::TweenPropType::Rotation);
    oluacls_const_integer(L, "Scale", (lua_Integer)fairygui::TweenPropType::Scale);
    oluacls_const_integer(L, "ScaleX", (lua_Integer)fairygui::TweenPropType::ScaleX);
    oluacls_const_integer(L, "ScaleY", (lua_Integer)fairygui::TweenPropType::ScaleY);
    oluacls_const_integer(L, "Size", (lua_Integer)fairygui::TweenPropType::Size);
    oluacls_const_integer(L, "Width", (lua_Integer)fairygui::TweenPropType::Width);
    oluacls_const_integer(L, "X", (lua_Integer)fairygui::TweenPropType::X);
    oluacls_const_integer(L, "Y", (lua_Integer)fairygui::TweenPropType::Y);

    olua_registerluatype<fairygui::TweenPropType>(L, "fgui.TweenPropType");

    return 1;
}

static int _fairygui_GPath___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (fairygui::GPath *)olua_toobj(L, 1, "fgui.GPath");
    olua_push_cppobj(L, self, "fgui.GPath");

    olua_endinvoke(L);

    return 1;
}

static int luaopen_fairygui_GPath(lua_State *L)
{
    oluacls_class(L, "fgui.GPath", nullptr);
    oluacls_func(L, "__move", _fairygui_GPath___move);

    olua_registerluatype<fairygui::GPath>(L, "fgui.GPath");

    return 1;
}

static int _fairygui_GTweener___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (fairygui::GTweener *)olua_toobj(L, 1, "fgui.GTweener");
    olua_push_cppobj(L, self, "fgui.GTweener");

    olua_endinvoke(L);

    return 1;
}

static int _fairygui_GTweener_allCompleted(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTweener *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTweener");

    // bool allCompleted()
    bool ret = (bool)self->allCompleted();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTweener_getDelay(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTweener *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTweener");

    // float getDelay()
    float ret = (float)self->getDelay();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTweener_getDuration(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTweener *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTweener");

    // float getDuration()
    float ret = (float)self->getDuration();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTweener_getNormalizedTime(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTweener *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTweener");

    // float getNormalizedTime()
    float ret = (float)self->getNormalizedTime();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTweener_getRepeat(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTweener *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTweener");

    // int getRepeat()
    int ret = (int)self->getRepeat();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTweener_getTarget(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTweener *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTweener");

    // void *getTarget()
    void *ret = (void *)self->getTarget();
    int num_ret = olua_push_obj(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTweener_getUserData(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTweener *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTweener");

    // const cocos2d::Value &getUserData()
    const cocos2d::Value &ret = (const cocos2d::Value &)self->getUserData();
    int num_ret = manual_olua_push_cocos2d_Value(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTweener_isCompleted(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTweener *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTweener");

    // bool isCompleted()
    bool ret = (bool)self->isCompleted();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTweener_kill1(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTweener *self = nullptr;
    bool arg1 = false;       /** complete */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTweener");
    olua_check_bool(L, 2, &arg1);

    // void kill(@optional bool complete)
    self->kill(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GTweener_kill2(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTweener *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTweener");

    // void kill(@optional bool complete)
    self->kill();

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GTweener_kill(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // void kill(@optional bool complete)
        return _fairygui_GTweener_kill2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_bool(L, 2))) {
            // void kill(@optional bool complete)
            return _fairygui_GTweener_kill1(L);
        // }
    }

    luaL_error(L, "method 'fairygui::GTweener::kill' not support '%d' arguments", num_args);

    return 0;
}

static int _fairygui_GTweener_new(lua_State *L)
{
    olua_startinvoke(L);

    // GTweener()
    fairygui::GTweener *ret = (fairygui::GTweener *)new fairygui::GTweener();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GTweener");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTweener_onComplete(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTweener *self = nullptr;
    std::function<void()> arg1;       /** callback */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTweener");

    void *self_obj = (void *)self;
    std::string tag = "onComplete";
    std::string func = olua_setcallback(L, self_obj, tag.c_str(), 2, OLUA_TAG_REPLACE);
    lua_Unsigned ctx = olua_context(L);
    arg1 = [self_obj, func, ctx]() {
        lua_State *L = olua_mainthread(NULL);

        if (L != NULL && (olua_context(L) == ctx)) {
            int top = lua_gettop(L);

            olua_callback(L, self_obj, func.c_str(), 0);

            lua_settop(L, top);
        }
    };

    // fairygui::GTweener *onComplete(std::function<void ()> callback)
    fairygui::GTweener *ret = (fairygui::GTweener *)self->onComplete(arg1);
    int num_ret = olua_push_cppobj(L, ret, "fgui.GTweener");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTweener_onComplete1(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTweener *self = nullptr;
    std::function<void(fairygui::GTweener *)> arg1;       /** callback */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTweener");

    void *self_obj = (void *)self;
    std::string tag = "onComplete1";
    std::string func = olua_setcallback(L, self_obj, tag.c_str(), 2, OLUA_TAG_REPLACE);
    lua_Unsigned ctx = olua_context(L);
    arg1 = [self_obj, func, ctx](fairygui::GTweener *arg1) {
        lua_State *L = olua_mainthread(NULL);

        if (L != NULL && (olua_context(L) == ctx)) {
            int top = lua_gettop(L);
            olua_push_cppobj(L, arg1, "fgui.GTweener");

            olua_callback(L, self_obj, func.c_str(), 1);

            lua_settop(L, top);
        }
    };

    // fairygui::GTweener *onComplete1(std::function<void (GTweener *)> callback)
    fairygui::GTweener *ret = (fairygui::GTweener *)self->onComplete1(arg1);
    int num_ret = olua_push_cppobj(L, ret, "fgui.GTweener");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTweener_onStart(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTweener *self = nullptr;
    std::function<void(fairygui::GTweener *)> arg1;       /** callback */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTweener");

    void *self_obj = (void *)self;
    std::string tag = "onStart";
    std::string func = olua_setcallback(L, self_obj, tag.c_str(), 2, OLUA_TAG_REPLACE);
    lua_Unsigned ctx = olua_context(L);
    arg1 = [self_obj, func, ctx](fairygui::GTweener *arg1) {
        lua_State *L = olua_mainthread(NULL);

        if (L != NULL && (olua_context(L) == ctx)) {
            int top = lua_gettop(L);
            olua_push_cppobj(L, arg1, "fgui.GTweener");

            olua_callback(L, self_obj, func.c_str(), 1);

            lua_settop(L, top);
        }
    };

    // fairygui::GTweener *onStart(std::function<void (GTweener *)> callback)
    fairygui::GTweener *ret = (fairygui::GTweener *)self->onStart(arg1);
    int num_ret = olua_push_cppobj(L, ret, "fgui.GTweener");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTweener_onUpdate(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTweener *self = nullptr;
    std::function<void(fairygui::GTweener *)> arg1;       /** callback */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTweener");

    void *self_obj = (void *)self;
    std::string tag = "onUpdate";
    std::string func = olua_setcallback(L, self_obj, tag.c_str(), 2, OLUA_TAG_REPLACE);
    lua_Unsigned ctx = olua_context(L);
    arg1 = [self_obj, func, ctx](fairygui::GTweener *arg1) {
        lua_State *L = olua_mainthread(NULL);

        if (L != NULL && (olua_context(L) == ctx)) {
            int top = lua_gettop(L);
            olua_push_cppobj(L, arg1, "fgui.GTweener");

            olua_callback(L, self_obj, func.c_str(), 1);

            lua_settop(L, top);
        }
    };

    // fairygui::GTweener *onUpdate(std::function<void (GTweener *)> callback)
    fairygui::GTweener *ret = (fairygui::GTweener *)self->onUpdate(arg1);
    int num_ret = olua_push_cppobj(L, ret, "fgui.GTweener");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTweener_seek(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTweener *self = nullptr;
    lua_Number arg1 = 0;       /** time */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTweener");
    olua_check_number(L, 2, &arg1);

    // void seek(float time)
    self->seek((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GTweener_setBreakpoint(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTweener *self = nullptr;
    lua_Number arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTweener");
    olua_check_number(L, 2, &arg1);

    // fairygui::GTweener *setBreakpoint(float value)
    fairygui::GTweener *ret = (fairygui::GTweener *)self->setBreakpoint((float)arg1);
    int num_ret = olua_push_cppobj(L, ret, "fgui.GTweener");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTweener_setDelay(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTweener *self = nullptr;
    lua_Number arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTweener");
    olua_check_number(L, 2, &arg1);

    // fairygui::GTweener *setDelay(float value)
    fairygui::GTweener *ret = (fairygui::GTweener *)self->setDelay((float)arg1);
    int num_ret = olua_push_cppobj(L, ret, "fgui.GTweener");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTweener_setDuration(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTweener *self = nullptr;
    lua_Number arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTweener");
    olua_check_number(L, 2, &arg1);

    // fairygui::GTweener *setDuration(float value)
    fairygui::GTweener *ret = (fairygui::GTweener *)self->setDuration((float)arg1);
    int num_ret = olua_push_cppobj(L, ret, "fgui.GTweener");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTweener_setEase(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTweener *self = nullptr;
    lua_Unsigned arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTweener");
    olua_check_uint(L, 2, &arg1);

    // fairygui::GTweener *setEase(fairygui::EaseType value)
    fairygui::GTweener *ret = (fairygui::GTweener *)self->setEase((fairygui::EaseType)arg1);
    int num_ret = olua_push_cppobj(L, ret, "fgui.GTweener");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTweener_setEaseOvershootOrAmplitude(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTweener *self = nullptr;
    lua_Number arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTweener");
    olua_check_number(L, 2, &arg1);

    // fairygui::GTweener *setEaseOvershootOrAmplitude(float value)
    fairygui::GTweener *ret = (fairygui::GTweener *)self->setEaseOvershootOrAmplitude((float)arg1);
    int num_ret = olua_push_cppobj(L, ret, "fgui.GTweener");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTweener_setEasePeriod(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTweener *self = nullptr;
    lua_Number arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTweener");
    olua_check_number(L, 2, &arg1);

    // fairygui::GTweener *setEasePeriod(float value)
    fairygui::GTweener *ret = (fairygui::GTweener *)self->setEasePeriod((float)arg1);
    int num_ret = olua_push_cppobj(L, ret, "fgui.GTweener");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTweener_setPath(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTweener *self = nullptr;
    fairygui::GPath *arg1 = nullptr;       /** path */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTweener");
    olua_check_cppobj(L, 2, (void **)&arg1, "fgui.GPath");

    // fairygui::GTweener *setPath(fairygui::GPath *path)
    fairygui::GTweener *ret = (fairygui::GTweener *)self->setPath(arg1);
    int num_ret = olua_push_cppobj(L, ret, "fgui.GTweener");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTweener_setPaused(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTweener *self = nullptr;
    bool arg1 = false;       /** paused */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTweener");
    olua_check_bool(L, 2, &arg1);

    // fairygui::GTweener *setPaused(bool paused)
    fairygui::GTweener *ret = (fairygui::GTweener *)self->setPaused(arg1);
    int num_ret = olua_push_cppobj(L, ret, "fgui.GTweener");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTweener_setRepeat1(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTweener *self = nullptr;
    lua_Integer arg1 = 0;       /** repeat */
    bool arg2 = false;       /** yoyo */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTweener");
    olua_check_int(L, 2, &arg1);
    olua_check_bool(L, 3, &arg2);

    // fairygui::GTweener *setRepeat(int repeat, @optional bool yoyo)
    fairygui::GTweener *ret = (fairygui::GTweener *)self->setRepeat((int)arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "fgui.GTweener");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTweener_setRepeat2(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTweener *self = nullptr;
    lua_Integer arg1 = 0;       /** repeat */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTweener");
    olua_check_int(L, 2, &arg1);

    // fairygui::GTweener *setRepeat(int repeat, @optional bool yoyo)
    fairygui::GTweener *ret = (fairygui::GTweener *)self->setRepeat((int)arg1);
    int num_ret = olua_push_cppobj(L, ret, "fgui.GTweener");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTweener_setRepeat(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_int(L, 2))) {
            // fairygui::GTweener *setRepeat(int repeat, @optional bool yoyo)
            return _fairygui_GTweener_setRepeat2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_int(L, 2)) && (olua_is_bool(L, 3))) {
            // fairygui::GTweener *setRepeat(int repeat, @optional bool yoyo)
            return _fairygui_GTweener_setRepeat1(L);
        // }
    }

    luaL_error(L, "method 'fairygui::GTweener::setRepeat' not support '%d' arguments", num_args);

    return 0;
}

static int _fairygui_GTweener_setSnapping(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTweener *self = nullptr;
    bool arg1 = false;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTweener");
    olua_check_bool(L, 2, &arg1);

    // fairygui::GTweener *setSnapping(bool value)
    fairygui::GTweener *ret = (fairygui::GTweener *)self->setSnapping(arg1);
    int num_ret = olua_push_cppobj(L, ret, "fgui.GTweener");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTweener_setTarget1(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTweener *self = nullptr;
    cocos2d::Ref *arg1 = nullptr;       /** target */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTweener");
    olua_check_cppobj(L, 2, (void **)&arg1, "cc.Ref");

    // fairygui::GTweener *setTarget(cocos2d::Ref *target)
    fairygui::GTweener *ret = (fairygui::GTweener *)self->setTarget(arg1);
    int num_ret = olua_push_cppobj(L, ret, "fgui.GTweener");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTweener_setTarget2(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTweener *self = nullptr;
    cocos2d::Ref *arg1 = nullptr;       /** target */
    lua_Unsigned arg2 = 0;       /** propType */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTweener");
    olua_check_cppobj(L, 2, (void **)&arg1, "cc.Ref");
    olua_check_uint(L, 3, &arg2);

    // fairygui::GTweener *setTarget(cocos2d::Ref *target, fairygui::TweenPropType propType)
    fairygui::GTweener *ret = (fairygui::GTweener *)self->setTarget(arg1, (fairygui::TweenPropType)arg2);
    int num_ret = olua_push_cppobj(L, ret, "fgui.GTweener");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTweener_setTarget(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_cppobj(L, 2, "cc.Ref"))) {
            // fairygui::GTweener *setTarget(cocos2d::Ref *target)
            return _fairygui_GTweener_setTarget1(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_cppobj(L, 2, "cc.Ref")) && (olua_is_uint(L, 3))) {
            // fairygui::GTweener *setTarget(cocos2d::Ref *target, fairygui::TweenPropType propType)
            return _fairygui_GTweener_setTarget2(L);
        // }
    }

    luaL_error(L, "method 'fairygui::GTweener::setTarget' not support '%d' arguments", num_args);

    return 0;
}

static int _fairygui_GTweener_setTargetAny(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTweener *self = nullptr;
    void *arg1 = nullptr;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTweener");
    olua_check_obj(L, 2, (void **)&arg1, "void *");

    // fairygui::GTweener *setTargetAny(void *value)
    fairygui::GTweener *ret = (fairygui::GTweener *)self->setTargetAny(arg1);
    int num_ret = olua_push_cppobj(L, ret, "fgui.GTweener");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTweener_setTimeScale(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTweener *self = nullptr;
    lua_Number arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTweener");
    olua_check_number(L, 2, &arg1);

    // fairygui::GTweener *setTimeScale(float value)
    fairygui::GTweener *ret = (fairygui::GTweener *)self->setTimeScale((float)arg1);
    int num_ret = olua_push_cppobj(L, ret, "fgui.GTweener");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTweener_setUserData(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTweener *self = nullptr;
    cocos2d::Value arg1;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTweener");
    manual_olua_check_cocos2d_Value(L, 2, &arg1);

    // fairygui::GTweener *setUserData(const cocos2d::Value &value)
    fairygui::GTweener *ret = (fairygui::GTweener *)self->setUserData(arg1);
    int num_ret = olua_push_cppobj(L, ret, "fgui.GTweener");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTweener_get_deltaValue(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTweener *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTweener");

    // fairygui::TweenValue deltaValue
    fairygui::TweenValue ret = (fairygui::TweenValue)self->deltaValue;
    int num_ret = auto_olua_push_fairygui_TweenValue(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTweener_set_deltaValue(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTweener *self = nullptr;
    fairygui::TweenValue arg1;       /** deltaValue */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTweener");
    auto_olua_check_fairygui_TweenValue(L, 2, &arg1);

    // fairygui::TweenValue deltaValue
    self->deltaValue = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GTweener_get_endValue(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTweener *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTweener");

    // fairygui::TweenValue endValue
    fairygui::TweenValue ret = (fairygui::TweenValue)self->endValue;
    int num_ret = auto_olua_push_fairygui_TweenValue(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTweener_set_endValue(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTweener *self = nullptr;
    fairygui::TweenValue arg1;       /** endValue */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTweener");
    auto_olua_check_fairygui_TweenValue(L, 2, &arg1);

    // fairygui::TweenValue endValue
    self->endValue = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GTweener_get_startValue(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTweener *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTweener");

    // fairygui::TweenValue startValue
    fairygui::TweenValue ret = (fairygui::TweenValue)self->startValue;
    int num_ret = auto_olua_push_fairygui_TweenValue(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTweener_set_startValue(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTweener *self = nullptr;
    fairygui::TweenValue arg1;       /** startValue */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTweener");
    auto_olua_check_fairygui_TweenValue(L, 2, &arg1);

    // fairygui::TweenValue startValue
    self->startValue = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GTweener_get_value(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTweener *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTweener");

    // fairygui::TweenValue value
    fairygui::TweenValue ret = (fairygui::TweenValue)self->value;
    int num_ret = auto_olua_push_fairygui_TweenValue(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTweener_set_value(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTweener *self = nullptr;
    fairygui::TweenValue arg1;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTweener");
    auto_olua_check_fairygui_TweenValue(L, 2, &arg1);

    // fairygui::TweenValue value
    self->value = arg1;

    olua_endinvoke(L);

    return 0;
}

static int luaopen_fairygui_GTweener(lua_State *L)
{
    oluacls_class(L, "fgui.GTweener", "cc.Ref");
    oluacls_func(L, "__move", _fairygui_GTweener___move);
    oluacls_func(L, "allCompleted", _fairygui_GTweener_allCompleted);
    oluacls_func(L, "getDelay", _fairygui_GTweener_getDelay);
    oluacls_func(L, "getDuration", _fairygui_GTweener_getDuration);
    oluacls_func(L, "getNormalizedTime", _fairygui_GTweener_getNormalizedTime);
    oluacls_func(L, "getRepeat", _fairygui_GTweener_getRepeat);
    oluacls_func(L, "getTarget", _fairygui_GTweener_getTarget);
    oluacls_func(L, "getUserData", _fairygui_GTweener_getUserData);
    oluacls_func(L, "isCompleted", _fairygui_GTweener_isCompleted);
    oluacls_func(L, "kill", _fairygui_GTweener_kill);
    oluacls_func(L, "new", _fairygui_GTweener_new);
    oluacls_func(L, "onComplete", _fairygui_GTweener_onComplete);
    oluacls_func(L, "onComplete1", _fairygui_GTweener_onComplete1);
    oluacls_func(L, "onStart", _fairygui_GTweener_onStart);
    oluacls_func(L, "onUpdate", _fairygui_GTweener_onUpdate);
    oluacls_func(L, "seek", _fairygui_GTweener_seek);
    oluacls_func(L, "setBreakpoint", _fairygui_GTweener_setBreakpoint);
    oluacls_func(L, "setDelay", _fairygui_GTweener_setDelay);
    oluacls_func(L, "setDuration", _fairygui_GTweener_setDuration);
    oluacls_func(L, "setEase", _fairygui_GTweener_setEase);
    oluacls_func(L, "setEaseOvershootOrAmplitude", _fairygui_GTweener_setEaseOvershootOrAmplitude);
    oluacls_func(L, "setEasePeriod", _fairygui_GTweener_setEasePeriod);
    oluacls_func(L, "setPath", _fairygui_GTweener_setPath);
    oluacls_func(L, "setPaused", _fairygui_GTweener_setPaused);
    oluacls_func(L, "setRepeat", _fairygui_GTweener_setRepeat);
    oluacls_func(L, "setSnapping", _fairygui_GTweener_setSnapping);
    oluacls_func(L, "setTarget", _fairygui_GTweener_setTarget);
    oluacls_func(L, "setTargetAny", _fairygui_GTweener_setTargetAny);
    oluacls_func(L, "setTimeScale", _fairygui_GTweener_setTimeScale);
    oluacls_func(L, "setUserData", _fairygui_GTweener_setUserData);
    oluacls_prop(L, "completed", _fairygui_GTweener_isCompleted, nullptr);
    oluacls_prop(L, "delay", _fairygui_GTweener_getDelay, _fairygui_GTweener_setDelay);
    oluacls_prop(L, "duration", _fairygui_GTweener_getDuration, _fairygui_GTweener_setDuration);
    oluacls_prop(L, "normalizedTime", _fairygui_GTweener_getNormalizedTime, nullptr);
    oluacls_prop(L, "repeat", _fairygui_GTweener_getRepeat, _fairygui_GTweener_setRepeat);
    oluacls_prop(L, "target", _fairygui_GTweener_getTarget, _fairygui_GTweener_setTarget);
    oluacls_prop(L, "userData", _fairygui_GTweener_getUserData, _fairygui_GTweener_setUserData);
    oluacls_prop(L, "deltaValue", _fairygui_GTweener_get_deltaValue, _fairygui_GTweener_set_deltaValue);
    oluacls_prop(L, "endValue", _fairygui_GTweener_get_endValue, _fairygui_GTweener_set_endValue);
    oluacls_prop(L, "startValue", _fairygui_GTweener_get_startValue, _fairygui_GTweener_set_startValue);
    oluacls_prop(L, "value", _fairygui_GTweener_get_value, _fairygui_GTweener_set_value);

    olua_registerluatype<fairygui::GTweener>(L, "fgui.GTweener");

    return 1;
}

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

static int _fairygui_GTween___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (fairygui::GTween *)olua_toobj(L, 1, "fgui.GTween");
    olua_push_cppobj(L, self, "fgui.GTween");

    olua_endinvoke(L);

    return 1;
}

static int _fairygui_GTween_clean(lua_State *L)
{
    olua_startinvoke(L);

    // static void clean()
    fairygui::GTween::clean();

    // inject code after call
    olua_pushclassobj<fairygui::GTween>(L);
    olua_delallrefs(L, -1, "tweeners");
    lua_pop(L, 1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GTween_delayedCall(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** delay */

    olua_check_number(L, 1, &arg1);

    // static fairygui::GTweener *delayedCall(float delay)
    fairygui::GTweener *ret = (fairygui::GTweener *)fairygui::GTween::delayedCall((float)arg1);
    int num_ret = olua_push_cppobj(L, ret, "fgui.GTweener");

    // inject code after call
    olua_pushclassobj<fairygui::GTween>(L);
    olua_addref(L, -1, "tweeners", -2, OLUA_MODE_MULTIPLE);
    olua_visitrefs(L, -1, "tweeners", should_del_tweener_ref);
    lua_pop(L, 1);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTween_getTween1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Ref *arg1 = nullptr;       /** target */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.Ref");

    // static fairygui::GTweener *getTween(cocos2d::Ref *target)
    fairygui::GTweener *ret = (fairygui::GTweener *)fairygui::GTween::getTween(arg1);
    int num_ret = olua_push_cppobj(L, ret, "fgui.GTweener");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTween_getTween2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Ref *arg1 = nullptr;       /** target */
    lua_Unsigned arg2 = 0;       /** propType */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.Ref");
    olua_check_uint(L, 2, &arg2);

    // static fairygui::GTweener *getTween(cocos2d::Ref *target, fairygui::TweenPropType propType)
    fairygui::GTweener *ret = (fairygui::GTweener *)fairygui::GTween::getTween(arg1, (fairygui::TweenPropType)arg2);
    int num_ret = olua_push_cppobj(L, ret, "fgui.GTweener");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTween_getTween(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_cppobj(L, 1, "cc.Ref"))) {
            // static fairygui::GTweener *getTween(cocos2d::Ref *target)
            return _fairygui_GTween_getTween1(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_cppobj(L, 1, "cc.Ref")) && (olua_is_uint(L, 2))) {
            // static fairygui::GTweener *getTween(cocos2d::Ref *target, fairygui::TweenPropType propType)
            return _fairygui_GTween_getTween2(L);
        // }
    }

    luaL_error(L, "method 'fairygui::GTween::getTween' not support '%d' arguments", num_args);

    return 0;
}

static int _fairygui_GTween_isTweening1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Ref *arg1 = nullptr;       /** target */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.Ref");

    // static bool isTweening(cocos2d::Ref *target)
    bool ret = (bool)fairygui::GTween::isTweening(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTween_isTweening2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Ref *arg1 = nullptr;       /** target */
    lua_Unsigned arg2 = 0;       /** propType */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.Ref");
    olua_check_uint(L, 2, &arg2);

    // static bool isTweening(cocos2d::Ref *target, fairygui::TweenPropType propType)
    bool ret = (bool)fairygui::GTween::isTweening(arg1, (fairygui::TweenPropType)arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTween_isTweening(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_cppobj(L, 1, "cc.Ref"))) {
            // static bool isTweening(cocos2d::Ref *target)
            return _fairygui_GTween_isTweening1(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_cppobj(L, 1, "cc.Ref")) && (olua_is_uint(L, 2))) {
            // static bool isTweening(cocos2d::Ref *target, fairygui::TweenPropType propType)
            return _fairygui_GTween_isTweening2(L);
        // }
    }

    luaL_error(L, "method 'fairygui::GTween::isTweening' not support '%d' arguments", num_args);

    return 0;
}

static int _fairygui_GTween_kill1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Ref *arg1 = nullptr;       /** target */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.Ref");

    // static void kill(cocos2d::Ref *target)
    fairygui::GTween::kill(arg1);

    // inject code after call
    olua_pushclassobj<fairygui::GTween>(L);
    olua_visitrefs(L, -1, "tweeners", should_del_tweener_ref);
    lua_pop(L, 1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GTween_kill2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Ref *arg1 = nullptr;       /** target */
    bool arg2 = false;       /** complete */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.Ref");
    olua_check_bool(L, 2, &arg2);

    // static void kill(cocos2d::Ref *target, bool complete)
    fairygui::GTween::kill(arg1, arg2);

    // inject code after call
    olua_pushclassobj<fairygui::GTween>(L);
    olua_visitrefs(L, -1, "tweeners", should_del_tweener_ref);
    lua_pop(L, 1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GTween_kill3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Ref *arg1 = nullptr;       /** target */
    lua_Unsigned arg2 = 0;       /** propType */
    bool arg3 = false;       /** complete */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.Ref");
    olua_check_uint(L, 2, &arg2);
    olua_check_bool(L, 3, &arg3);

    // static void kill(cocos2d::Ref *target, fairygui::TweenPropType propType, bool complete)
    fairygui::GTween::kill(arg1, (fairygui::TweenPropType)arg2, arg3);

    // inject code after call
    olua_pushclassobj<fairygui::GTween>(L);
    olua_visitrefs(L, -1, "tweeners", should_del_tweener_ref);
    lua_pop(L, 1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GTween_kill(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_cppobj(L, 1, "cc.Ref"))) {
            // static void kill(cocos2d::Ref *target)
            return _fairygui_GTween_kill1(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_cppobj(L, 1, "cc.Ref")) && (olua_is_bool(L, 2))) {
            // static void kill(cocos2d::Ref *target, bool complete)
            return _fairygui_GTween_kill2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_cppobj(L, 1, "cc.Ref")) && (olua_is_uint(L, 2)) && (olua_is_bool(L, 3))) {
            // static void kill(cocos2d::Ref *target, fairygui::TweenPropType propType, bool complete)
            return _fairygui_GTween_kill3(L);
        // }
    }

    luaL_error(L, "method 'fairygui::GTween::kill' not support '%d' arguments", num_args);

    return 0;
}

static int _fairygui_GTween_shake(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 arg1;       /** startValue */
    lua_Number arg2 = 0;       /** amplitude */
    lua_Number arg3 = 0;       /** duration */

    auto_olua_check_cocos2d_Vec2(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);

    // static fairygui::GTweener *shake(const cocos2d::Vec2 &startValue, float amplitude, float duration)
    fairygui::GTweener *ret = (fairygui::GTweener *)fairygui::GTween::shake(arg1, (float)arg2, (float)arg3);
    int num_ret = olua_push_cppobj(L, ret, "fgui.GTweener");

    // inject code after call
    olua_pushclassobj<fairygui::GTween>(L);
    olua_addref(L, -1, "tweeners", -2, OLUA_MODE_MULTIPLE);
    olua_visitrefs(L, -1, "tweeners", should_del_tweener_ref);
    lua_pop(L, 1);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTween_to1(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** startValue */
    lua_Number arg2 = 0;       /** endValue */
    lua_Number arg3 = 0;       /** duration */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);

    // static fairygui::GTweener *to(float startValue, float endValue, float duration)
    fairygui::GTweener *ret = (fairygui::GTweener *)fairygui::GTween::to((float)arg1, (float)arg2, (float)arg3);
    int num_ret = olua_push_cppobj(L, ret, "fgui.GTweener");

    // inject code after call
    olua_pushclassobj<fairygui::GTween>(L);
    olua_addref(L, -1, "tweeners", -2, OLUA_MODE_MULTIPLE);
    olua_visitrefs(L, -1, "tweeners", should_del_tweener_ref);
    lua_pop(L, 1);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTween_to2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 arg1;       /** startValue */
    cocos2d::Vec2 arg2;       /** endValue */
    lua_Number arg3 = 0;       /** duration */

    auto_olua_check_cocos2d_Vec2(L, 1, &arg1);
    auto_olua_check_cocos2d_Vec2(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);

    // static fairygui::GTweener *to(const cocos2d::Vec2 &startValue, const cocos2d::Vec2 &endValue, float duration)
    fairygui::GTweener *ret = (fairygui::GTweener *)fairygui::GTween::to(arg1, arg2, (float)arg3);
    int num_ret = olua_push_cppobj(L, ret, "fgui.GTweener");

    // inject code after call
    olua_pushclassobj<fairygui::GTween>(L);
    olua_addref(L, -1, "tweeners", -2, OLUA_MODE_MULTIPLE);
    olua_visitrefs(L, -1, "tweeners", should_del_tweener_ref);
    lua_pop(L, 1);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTween_to3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec3 arg1;       /** startValue */
    cocos2d::Vec3 arg2;       /** endValue */
    lua_Number arg3 = 0;       /** duration */

    auto_olua_check_cocos2d_Vec3(L, 1, &arg1);
    auto_olua_check_cocos2d_Vec3(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);

    // static fairygui::GTweener *to(const cocos2d::Vec3 &startValue, const cocos2d::Vec3 &endValue, float duration)
    fairygui::GTweener *ret = (fairygui::GTweener *)fairygui::GTween::to(arg1, arg2, (float)arg3);
    int num_ret = olua_push_cppobj(L, ret, "fgui.GTweener");

    // inject code after call
    olua_pushclassobj<fairygui::GTween>(L);
    olua_addref(L, -1, "tweeners", -2, OLUA_MODE_MULTIPLE);
    olua_visitrefs(L, -1, "tweeners", should_del_tweener_ref);
    lua_pop(L, 1);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTween_to4(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec4 arg1;       /** startValue */
    cocos2d::Vec4 arg2;       /** endValue */
    lua_Number arg3 = 0;       /** duration */

    auto_olua_check_cocos2d_Vec4(L, 1, &arg1);
    auto_olua_check_cocos2d_Vec4(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);

    // static fairygui::GTweener *to(const cocos2d::Vec4 &startValue, const cocos2d::Vec4 &endValue, float duration)
    fairygui::GTweener *ret = (fairygui::GTweener *)fairygui::GTween::to(arg1, arg2, (float)arg3);
    int num_ret = olua_push_cppobj(L, ret, "fgui.GTweener");

    // inject code after call
    olua_pushclassobj<fairygui::GTween>(L);
    olua_addref(L, -1, "tweeners", -2, OLUA_MODE_MULTIPLE);
    olua_visitrefs(L, -1, "tweeners", should_del_tweener_ref);
    lua_pop(L, 1);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTween_to5(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Color4B arg1;       /** startValue */
    cocos2d::Color4B arg2;       /** endValue */
    lua_Number arg3 = 0;       /** duration */

    manual_olua_check_cocos2d_Color4B(L, 1, &arg1);
    manual_olua_check_cocos2d_Color4B(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);

    // static fairygui::GTweener *to(const cocos2d::Color4B &startValue, const cocos2d::Color4B &endValue, float duration)
    fairygui::GTweener *ret = (fairygui::GTweener *)fairygui::GTween::to(arg1, arg2, (float)arg3);
    int num_ret = olua_push_cppobj(L, ret, "fgui.GTweener");

    // inject code after call
    olua_pushclassobj<fairygui::GTween>(L);
    olua_addref(L, -1, "tweeners", -2, OLUA_MODE_MULTIPLE);
    olua_visitrefs(L, -1, "tweeners", should_del_tweener_ref);
    lua_pop(L, 1);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTween_to(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 3) {
        if ((auto_olua_is_cocos2d_Vec4(L, 1)) && (auto_olua_is_cocos2d_Vec4(L, 2)) && (olua_is_number(L, 3))) {
            // static fairygui::GTweener *to(const cocos2d::Vec4 &startValue, const cocos2d::Vec4 &endValue, float duration)
            return _fairygui_GTween_to4(L);
        }

        if ((auto_olua_is_cocos2d_Vec3(L, 1)) && (auto_olua_is_cocos2d_Vec3(L, 2)) && (olua_is_number(L, 3))) {
            // static fairygui::GTweener *to(const cocos2d::Vec3 &startValue, const cocos2d::Vec3 &endValue, float duration)
            return _fairygui_GTween_to3(L);
        }

        if ((auto_olua_is_cocos2d_Vec2(L, 1)) && (auto_olua_is_cocos2d_Vec2(L, 2)) && (olua_is_number(L, 3))) {
            // static fairygui::GTweener *to(const cocos2d::Vec2 &startValue, const cocos2d::Vec2 &endValue, float duration)
            return _fairygui_GTween_to2(L);
        }

        if ((olua_is_number(L, 1)) && (olua_is_number(L, 2)) && (olua_is_number(L, 3))) {
            // static fairygui::GTweener *to(float startValue, float endValue, float duration)
            return _fairygui_GTween_to1(L);
        }

        // if ((manual_olua_is_cocos2d_Color4B(L, 1)) && (manual_olua_is_cocos2d_Color4B(L, 2)) && (olua_is_number(L, 3))) {
            // static fairygui::GTweener *to(const cocos2d::Color4B &startValue, const cocos2d::Color4B &endValue, float duration)
            return _fairygui_GTween_to5(L);
        // }
    }

    luaL_error(L, "method 'fairygui::GTween::to' not support '%d' arguments", num_args);

    return 0;
}

static int _fairygui_GTween_toDouble(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** startValue */
    lua_Number arg2 = 0;       /** endValue */
    lua_Number arg3 = 0;       /** duration */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);

    // static fairygui::GTweener *toDouble(double startValue, double endValue, float duration)
    fairygui::GTweener *ret = (fairygui::GTweener *)fairygui::GTween::toDouble((double)arg1, (double)arg2, (float)arg3);
    int num_ret = olua_push_cppobj(L, ret, "fgui.GTweener");

    // inject code after call
    olua_pushclassobj<fairygui::GTween>(L);
    olua_addref(L, -1, "tweeners", -2, OLUA_MODE_MULTIPLE);
    olua_visitrefs(L, -1, "tweeners", should_del_tweener_ref);
    lua_pop(L, 1);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_fairygui_GTween(lua_State *L)
{
    oluacls_class(L, "fgui.GTween", nullptr);
    oluacls_func(L, "__move", _fairygui_GTween___move);
    oluacls_func(L, "clean", _fairygui_GTween_clean);
    oluacls_func(L, "delayedCall", _fairygui_GTween_delayedCall);
    oluacls_func(L, "getTween", _fairygui_GTween_getTween);
    oluacls_func(L, "isTweening", _fairygui_GTween_isTweening);
    oluacls_func(L, "kill", _fairygui_GTween_kill);
    oluacls_func(L, "shake", _fairygui_GTween_shake);
    oluacls_func(L, "to", _fairygui_GTween_to);
    oluacls_func(L, "toDouble", _fairygui_GTween_toDouble);

    olua_registerluatype<fairygui::GTween>(L, "fgui.GTween");

    return 1;
}

static int _fairygui_UIPackage___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (fairygui::UIPackage *)olua_toobj(L, 1, "fgui.UIPackage");
    olua_push_cppobj(L, self, "fgui.UIPackage");

    olua_endinvoke(L);

    return 1;
}

static int _fairygui_UIPackage_addPackage(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** descFilePath */

    olua_check_std_string(L, 1, &arg1);

    // static fairygui::UIPackage *addPackage(const std::string &descFilePath)
    fairygui::UIPackage *ret = (fairygui::UIPackage *)fairygui::UIPackage::addPackage(arg1);
    int num_ret = olua_push_cppobj(L, ret, "fgui.UIPackage");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_UIPackage_createObject(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** pkgName */
    std::string arg2;       /** resName */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);

    // static fairygui::GObject *createObject(const std::string &pkgName, const std::string &resName)
    fairygui::GObject *ret = (fairygui::GObject *)fairygui::UIPackage::createObject(arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "fgui.GObject");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_UIPackage_createObjectFromURL(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** url */

    olua_check_std_string(L, 1, &arg1);

    // static fairygui::GObject *createObjectFromURL(const std::string &url)
    fairygui::GObject *ret = (fairygui::GObject *)fairygui::UIPackage::createObjectFromURL(arg1);
    int num_ret = olua_push_cppobj(L, ret, "fgui.GObject");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_UIPackage_getBranch(lua_State *L)
{
    olua_startinvoke(L);

    // static const std::string &getBranch()
    const std::string &ret = (const std::string &)fairygui::UIPackage::getBranch();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_UIPackage_getById(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** id */

    olua_check_std_string(L, 1, &arg1);

    // static fairygui::UIPackage *getById(const std::string &id)
    fairygui::UIPackage *ret = (fairygui::UIPackage *)fairygui::UIPackage::getById(arg1);
    int num_ret = olua_push_cppobj(L, ret, "fgui.UIPackage");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_UIPackage_getByName(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** name */

    olua_check_std_string(L, 1, &arg1);

    // static fairygui::UIPackage *getByName(const std::string &name)
    fairygui::UIPackage *ret = (fairygui::UIPackage *)fairygui::UIPackage::getByName(arg1);
    int num_ret = olua_push_cppobj(L, ret, "fgui.UIPackage");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_UIPackage_getEmptyTexture(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::Texture2D *getEmptyTexture()
    cocos2d::Texture2D *ret = (cocos2d::Texture2D *)fairygui::UIPackage::getEmptyTexture();
    int num_ret = olua_push_cppobj(L, ret, "cc.Texture2D");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_UIPackage_getId(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::UIPackage *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.UIPackage");

    // const std::string &getId()
    const std::string &ret = (const std::string &)self->getId();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_UIPackage_getItem(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::UIPackage *self = nullptr;
    std::string arg1;       /** itemId */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.UIPackage");
    olua_check_std_string(L, 2, &arg1);

    // fairygui::PackageItem *getItem(const std::string &itemId)
    fairygui::PackageItem *ret = (fairygui::PackageItem *)self->getItem(arg1);
    int num_ret = olua_push_cppobj(L, ret, "fgui.PackageItem");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_UIPackage_getItemAsset1(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** pkgName */
    std::string arg2;       /** resName */
    lua_Unsigned arg3 = 0;       /** type */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);
    olua_check_uint(L, 3, &arg3);

    // static void *getItemAsset(const std::string &pkgName, const std::string &resName, @optional fairygui::PackageItemType type)
    void *ret = (void *)fairygui::UIPackage::getItemAsset(arg1, arg2, (fairygui::PackageItemType)arg3);
    int num_ret = olua_push_obj(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_UIPackage_getItemAsset2(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::UIPackage *self = nullptr;
    fairygui::PackageItem *arg1 = nullptr;       /** item */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.UIPackage");
    olua_check_cppobj(L, 2, (void **)&arg1, "fgui.PackageItem");

    // void *getItemAsset(fairygui::PackageItem *item)
    void *ret = (void *)self->getItemAsset(arg1);
    int num_ret = olua_push_obj(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_UIPackage_getItemAsset3(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** pkgName */
    std::string arg2;       /** resName */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);

    // static void *getItemAsset(const std::string &pkgName, const std::string &resName, @optional fairygui::PackageItemType type)
    void *ret = (void *)fairygui::UIPackage::getItemAsset(arg1, arg2);
    int num_ret = olua_push_obj(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_UIPackage_getItemAsset(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_cppobj(L, 2, "fgui.PackageItem"))) {
            // void *getItemAsset(fairygui::PackageItem *item)
            return _fairygui_UIPackage_getItemAsset2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 1)) && (olua_is_std_string(L, 2))) {
            // static void *getItemAsset(const std::string &pkgName, const std::string &resName, @optional fairygui::PackageItemType type)
            return _fairygui_UIPackage_getItemAsset3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_std_string(L, 1)) && (olua_is_std_string(L, 2)) && (olua_is_uint(L, 3))) {
            // static void *getItemAsset(const std::string &pkgName, const std::string &resName, @optional fairygui::PackageItemType type)
            return _fairygui_UIPackage_getItemAsset1(L);
        // }
    }

    luaL_error(L, "method 'fairygui::UIPackage::getItemAsset' not support '%d' arguments", num_args);

    return 0;
}

static int _fairygui_UIPackage_getItemAssetByURL1(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** url */
    lua_Unsigned arg2 = 0;       /** type */

    olua_check_std_string(L, 1, &arg1);
    olua_check_uint(L, 2, &arg2);

    // static void *getItemAssetByURL(const std::string &url, @optional fairygui::PackageItemType type)
    void *ret = (void *)fairygui::UIPackage::getItemAssetByURL(arg1, (fairygui::PackageItemType)arg2);
    int num_ret = olua_push_obj(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_UIPackage_getItemAssetByURL2(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** url */

    olua_check_std_string(L, 1, &arg1);

    // static void *getItemAssetByURL(const std::string &url, @optional fairygui::PackageItemType type)
    void *ret = (void *)fairygui::UIPackage::getItemAssetByURL(arg1);
    int num_ret = olua_push_obj(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_UIPackage_getItemAssetByURL(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 1))) {
            // static void *getItemAssetByURL(const std::string &url, @optional fairygui::PackageItemType type)
            return _fairygui_UIPackage_getItemAssetByURL2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 1)) && (olua_is_uint(L, 2))) {
            // static void *getItemAssetByURL(const std::string &url, @optional fairygui::PackageItemType type)
            return _fairygui_UIPackage_getItemAssetByURL1(L);
        // }
    }

    luaL_error(L, "method 'fairygui::UIPackage::getItemAssetByURL' not support '%d' arguments", num_args);

    return 0;
}

static int _fairygui_UIPackage_getItemByName(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::UIPackage *self = nullptr;
    std::string arg1;       /** itemName */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.UIPackage");
    olua_check_std_string(L, 2, &arg1);

    // fairygui::PackageItem *getItemByName(const std::string &itemName)
    fairygui::PackageItem *ret = (fairygui::PackageItem *)self->getItemByName(arg1);
    int num_ret = olua_push_cppobj(L, ret, "fgui.PackageItem");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_UIPackage_getItemByURL(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** url */

    olua_check_std_string(L, 1, &arg1);

    // static fairygui::PackageItem *getItemByURL(const std::string &url)
    fairygui::PackageItem *ret = (fairygui::PackageItem *)fairygui::UIPackage::getItemByURL(arg1);
    int num_ret = olua_push_cppobj(L, ret, "fgui.PackageItem");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_UIPackage_getItemURL(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** pkgName */
    std::string arg2;       /** resName */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);

    // static std::string getItemURL(const std::string &pkgName, const std::string &resName)
    std::string ret = (std::string)fairygui::UIPackage::getItemURL(arg1, arg2);
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_UIPackage_getName(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::UIPackage *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.UIPackage");

    // const std::string &getName()
    const std::string &ret = (const std::string &)self->getName();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_UIPackage_getVar(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** key */

    olua_check_std_string(L, 1, &arg1);

    // static const std::string &getVar(const std::string &key)
    const std::string &ret = (const std::string &)fairygui::UIPackage::getVar(arg1);
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_UIPackage_new(lua_State *L)
{
    olua_startinvoke(L);

    // UIPackage()
    fairygui::UIPackage *ret = (fairygui::UIPackage *)new fairygui::UIPackage();
    int num_ret = olua_push_cppobj(L, ret, "fgui.UIPackage");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_UIPackage_normalizeURL(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** url */

    olua_check_std_string(L, 1, &arg1);

    // static std::string normalizeURL(const std::string &url)
    std::string ret = (std::string)fairygui::UIPackage::normalizeURL(arg1);
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_UIPackage_removeAllPackages(lua_State *L)
{
    olua_startinvoke(L);

    // static void removeAllPackages()
    fairygui::UIPackage::removeAllPackages();

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_UIPackage_removePackage(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** packageIdOrName */

    olua_check_std_string(L, 1, &arg1);

    // static void removePackage(const std::string &packageIdOrName)
    fairygui::UIPackage::removePackage(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_UIPackage_setBranch(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** value */

    olua_check_std_string(L, 1, &arg1);

    // static void setBranch(const std::string &value)
    fairygui::UIPackage::setBranch(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_UIPackage_setVar(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** key */
    std::string arg2;       /** value */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);

    // static void setVar(const std::string &key, const std::string &value)
    fairygui::UIPackage::setVar(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_fairygui_UIPackage(lua_State *L)
{
    oluacls_class(L, "fgui.UIPackage", "cc.Ref");
    oluacls_func(L, "__move", _fairygui_UIPackage___move);
    oluacls_func(L, "addPackage", _fairygui_UIPackage_addPackage);
    oluacls_func(L, "createObject", _fairygui_UIPackage_createObject);
    oluacls_func(L, "createObjectFromURL", _fairygui_UIPackage_createObjectFromURL);
    oluacls_func(L, "getBranch", _fairygui_UIPackage_getBranch);
    oluacls_func(L, "getById", _fairygui_UIPackage_getById);
    oluacls_func(L, "getByName", _fairygui_UIPackage_getByName);
    oluacls_func(L, "getEmptyTexture", _fairygui_UIPackage_getEmptyTexture);
    oluacls_func(L, "getId", _fairygui_UIPackage_getId);
    oluacls_func(L, "getItem", _fairygui_UIPackage_getItem);
    oluacls_func(L, "getItemAsset", _fairygui_UIPackage_getItemAsset);
    oluacls_func(L, "getItemAssetByURL", _fairygui_UIPackage_getItemAssetByURL);
    oluacls_func(L, "getItemByName", _fairygui_UIPackage_getItemByName);
    oluacls_func(L, "getItemByURL", _fairygui_UIPackage_getItemByURL);
    oluacls_func(L, "getItemURL", _fairygui_UIPackage_getItemURL);
    oluacls_func(L, "getName", _fairygui_UIPackage_getName);
    oluacls_func(L, "getVar", _fairygui_UIPackage_getVar);
    oluacls_func(L, "new", _fairygui_UIPackage_new);
    oluacls_func(L, "normalizeURL", _fairygui_UIPackage_normalizeURL);
    oluacls_func(L, "removeAllPackages", _fairygui_UIPackage_removeAllPackages);
    oluacls_func(L, "removePackage", _fairygui_UIPackage_removePackage);
    oluacls_func(L, "setBranch", _fairygui_UIPackage_setBranch);
    oluacls_func(L, "setVar", _fairygui_UIPackage_setVar);
    oluacls_prop(L, "branch", _fairygui_UIPackage_getBranch, _fairygui_UIPackage_setBranch);
    oluacls_prop(L, "emptyTexture", _fairygui_UIPackage_getEmptyTexture, nullptr);
    oluacls_prop(L, "id", _fairygui_UIPackage_getId, nullptr);
    oluacls_prop(L, "name", _fairygui_UIPackage_getName, nullptr);
    oluacls_const_string(L, "URL_PREFIX", (const char *)fairygui::UIPackage::URL_PREFIX.c_str());

    olua_registerluatype<fairygui::UIPackage>(L, "fgui.UIPackage");

    return 1;
}

static int _fairygui_PackageItem___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (fairygui::PackageItem *)olua_toobj(L, 1, "fgui.PackageItem");
    olua_push_cppobj(L, self, "fgui.PackageItem");

    olua_endinvoke(L);

    return 1;
}

static int _fairygui_PackageItem_getBranch(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::PackageItem *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.PackageItem");

    // fairygui::PackageItem *getBranch()
    fairygui::PackageItem *ret = (fairygui::PackageItem *)self->getBranch();
    int num_ret = olua_push_cppobj(L, ret, "fgui.PackageItem");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_PackageItem_getHighResolution(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::PackageItem *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.PackageItem");

    // fairygui::PackageItem *getHighResolution()
    fairygui::PackageItem *ret = (fairygui::PackageItem *)self->getHighResolution();
    int num_ret = olua_push_cppobj(L, ret, "fgui.PackageItem");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_PackageItem_load(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::PackageItem *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.PackageItem");

    // void load()
    self->load();

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_PackageItem_new(lua_State *L)
{
    olua_startinvoke(L);

    // PackageItem()
    fairygui::PackageItem *ret = (fairygui::PackageItem *)new fairygui::PackageItem();
    int num_ret = olua_push_cppobj(L, ret, "fgui.PackageItem");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_PackageItem_get_animation(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::PackageItem *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.PackageItem");

    // cocos2d::Animation *animation
    cocos2d::Animation *ret = (cocos2d::Animation *)self->animation;
    int num_ret = olua_push_cppobj(L, ret, "cc.Animation");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_PackageItem_set_animation(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::PackageItem *self = nullptr;
    cocos2d::Animation *arg1 = nullptr;       /** animation */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.PackageItem");
    olua_check_cppobj(L, 2, (void **)&arg1, "cc.Animation");

    // cocos2d::Animation *animation
    self->animation = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_PackageItem_get_delayPerUnit(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::PackageItem *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.PackageItem");

    // float delayPerUnit
    float ret = (float)self->delayPerUnit;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_PackageItem_set_delayPerUnit(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::PackageItem *self = nullptr;
    lua_Number arg1 = 0;       /** delayPerUnit */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.PackageItem");
    olua_check_number(L, 2, &arg1);

    // float delayPerUnit
    self->delayPerUnit = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_PackageItem_get_file(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::PackageItem *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.PackageItem");

    // std::string file
    std::string ret = (std::string)self->file;
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_PackageItem_set_file(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::PackageItem *self = nullptr;
    std::string arg1;       /** file */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.PackageItem");
    olua_check_std_string(L, 2, &arg1);

    // std::string file
    self->file = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_PackageItem_get_height(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::PackageItem *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.PackageItem");

    // int height
    int ret = (int)self->height;
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_PackageItem_set_height(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::PackageItem *self = nullptr;
    lua_Integer arg1 = 0;       /** height */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.PackageItem");
    olua_check_int(L, 2, &arg1);

    // int height
    self->height = (int)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_PackageItem_get_id(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::PackageItem *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.PackageItem");

    // std::string id
    std::string ret = (std::string)self->id;
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_PackageItem_set_id(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::PackageItem *self = nullptr;
    std::string arg1;       /** id */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.PackageItem");
    olua_check_std_string(L, 2, &arg1);

    // std::string id
    self->id = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_PackageItem_get_name(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::PackageItem *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.PackageItem");

    // std::string name
    std::string ret = (std::string)self->name;
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_PackageItem_set_name(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::PackageItem *self = nullptr;
    std::string arg1;       /** name */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.PackageItem");
    olua_check_std_string(L, 2, &arg1);

    // std::string name
    self->name = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_PackageItem_get_objectType(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::PackageItem *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.PackageItem");

    // fairygui::ObjectType objectType
    fairygui::ObjectType ret = (fairygui::ObjectType)self->objectType;
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_PackageItem_set_objectType(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::PackageItem *self = nullptr;
    lua_Unsigned arg1 = 0;       /** objectType */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.PackageItem");
    olua_check_uint(L, 2, &arg1);

    // fairygui::ObjectType objectType
    self->objectType = (fairygui::ObjectType)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_PackageItem_get_owner(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::PackageItem *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.PackageItem");

    // fairygui::UIPackage *owner
    fairygui::UIPackage *ret = (fairygui::UIPackage *)self->owner;
    int num_ret = olua_push_cppobj(L, ret, "fgui.UIPackage");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_PackageItem_set_owner(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::PackageItem *self = nullptr;
    fairygui::UIPackage *arg1 = nullptr;       /** owner */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.PackageItem");
    olua_check_cppobj(L, 2, (void **)&arg1, "fgui.UIPackage");

    // fairygui::UIPackage *owner
    self->owner = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_PackageItem_get_repeatDelay(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::PackageItem *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.PackageItem");

    // float repeatDelay
    float ret = (float)self->repeatDelay;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_PackageItem_set_repeatDelay(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::PackageItem *self = nullptr;
    lua_Number arg1 = 0;       /** repeatDelay */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.PackageItem");
    olua_check_number(L, 2, &arg1);

    // float repeatDelay
    self->repeatDelay = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_PackageItem_get_scaleByTile(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::PackageItem *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.PackageItem");

    // bool scaleByTile
    bool ret = (bool)self->scaleByTile;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_PackageItem_set_scaleByTile(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::PackageItem *self = nullptr;
    bool arg1 = false;       /** scaleByTile */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.PackageItem");
    olua_check_bool(L, 2, &arg1);

    // bool scaleByTile
    self->scaleByTile = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_PackageItem_get_spriteFrame(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::PackageItem *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.PackageItem");

    // cocos2d::SpriteFrame *spriteFrame
    cocos2d::SpriteFrame *ret = (cocos2d::SpriteFrame *)self->spriteFrame;
    int num_ret = olua_push_cppobj(L, ret, "cc.SpriteFrame");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_PackageItem_set_spriteFrame(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::PackageItem *self = nullptr;
    cocos2d::SpriteFrame *arg1 = nullptr;       /** spriteFrame */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.PackageItem");
    olua_check_cppobj(L, 2, (void **)&arg1, "cc.SpriteFrame");

    // cocos2d::SpriteFrame *spriteFrame
    self->spriteFrame = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_PackageItem_get_swing(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::PackageItem *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.PackageItem");

    // bool swing
    bool ret = (bool)self->swing;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_PackageItem_set_swing(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::PackageItem *self = nullptr;
    bool arg1 = false;       /** swing */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.PackageItem");
    olua_check_bool(L, 2, &arg1);

    // bool swing
    self->swing = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_PackageItem_get_texture(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::PackageItem *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.PackageItem");

    // cocos2d::Texture2D *texture
    cocos2d::Texture2D *ret = (cocos2d::Texture2D *)self->texture;
    int num_ret = olua_push_cppobj(L, ret, "cc.Texture2D");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_PackageItem_set_texture(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::PackageItem *self = nullptr;
    cocos2d::Texture2D *arg1 = nullptr;       /** texture */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.PackageItem");
    olua_check_cppobj(L, 2, (void **)&arg1, "cc.Texture2D");

    // cocos2d::Texture2D *texture
    self->texture = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_PackageItem_get_tileGridIndice(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::PackageItem *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.PackageItem");

    // int tileGridIndice
    int ret = (int)self->tileGridIndice;
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_PackageItem_set_tileGridIndice(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::PackageItem *self = nullptr;
    lua_Integer arg1 = 0;       /** tileGridIndice */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.PackageItem");
    olua_check_int(L, 2, &arg1);

    // int tileGridIndice
    self->tileGridIndice = (int)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_PackageItem_get_translated(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::PackageItem *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.PackageItem");

    // bool translated
    bool ret = (bool)self->translated;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_PackageItem_set_translated(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::PackageItem *self = nullptr;
    bool arg1 = false;       /** translated */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.PackageItem");
    olua_check_bool(L, 2, &arg1);

    // bool translated
    self->translated = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_PackageItem_get_type(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::PackageItem *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.PackageItem");

    // fairygui::PackageItemType type
    fairygui::PackageItemType ret = (fairygui::PackageItemType)self->type;
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_PackageItem_set_type(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::PackageItem *self = nullptr;
    lua_Unsigned arg1 = 0;       /** type */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.PackageItem");
    olua_check_uint(L, 2, &arg1);

    // fairygui::PackageItemType type
    self->type = (fairygui::PackageItemType)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_PackageItem_get_width(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::PackageItem *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.PackageItem");

    // int width
    int ret = (int)self->width;
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_PackageItem_set_width(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::PackageItem *self = nullptr;
    lua_Integer arg1 = 0;       /** width */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.PackageItem");
    olua_check_int(L, 2, &arg1);

    // int width
    self->width = (int)arg1;

    olua_endinvoke(L);

    return 0;
}

static int luaopen_fairygui_PackageItem(lua_State *L)
{
    oluacls_class(L, "fgui.PackageItem", "cc.Ref");
    oluacls_func(L, "__move", _fairygui_PackageItem___move);
    oluacls_func(L, "getBranch", _fairygui_PackageItem_getBranch);
    oluacls_func(L, "getHighResolution", _fairygui_PackageItem_getHighResolution);
    oluacls_func(L, "load", _fairygui_PackageItem_load);
    oluacls_func(L, "new", _fairygui_PackageItem_new);
    oluacls_prop(L, "branch", _fairygui_PackageItem_getBranch, nullptr);
    oluacls_prop(L, "highResolution", _fairygui_PackageItem_getHighResolution, nullptr);
    oluacls_prop(L, "animation", _fairygui_PackageItem_get_animation, _fairygui_PackageItem_set_animation);
    oluacls_prop(L, "delayPerUnit", _fairygui_PackageItem_get_delayPerUnit, _fairygui_PackageItem_set_delayPerUnit);
    oluacls_prop(L, "file", _fairygui_PackageItem_get_file, _fairygui_PackageItem_set_file);
    oluacls_prop(L, "height", _fairygui_PackageItem_get_height, _fairygui_PackageItem_set_height);
    oluacls_prop(L, "id", _fairygui_PackageItem_get_id, _fairygui_PackageItem_set_id);
    oluacls_prop(L, "name", _fairygui_PackageItem_get_name, _fairygui_PackageItem_set_name);
    oluacls_prop(L, "objectType", _fairygui_PackageItem_get_objectType, _fairygui_PackageItem_set_objectType);
    oluacls_prop(L, "owner", _fairygui_PackageItem_get_owner, _fairygui_PackageItem_set_owner);
    oluacls_prop(L, "repeatDelay", _fairygui_PackageItem_get_repeatDelay, _fairygui_PackageItem_set_repeatDelay);
    oluacls_prop(L, "scaleByTile", _fairygui_PackageItem_get_scaleByTile, _fairygui_PackageItem_set_scaleByTile);
    oluacls_prop(L, "spriteFrame", _fairygui_PackageItem_get_spriteFrame, _fairygui_PackageItem_set_spriteFrame);
    oluacls_prop(L, "swing", _fairygui_PackageItem_get_swing, _fairygui_PackageItem_set_swing);
    oluacls_prop(L, "texture", _fairygui_PackageItem_get_texture, _fairygui_PackageItem_set_texture);
    oluacls_prop(L, "tileGridIndice", _fairygui_PackageItem_get_tileGridIndice, _fairygui_PackageItem_set_tileGridIndice);
    oluacls_prop(L, "translated", _fairygui_PackageItem_get_translated, _fairygui_PackageItem_set_translated);
    oluacls_prop(L, "type", _fairygui_PackageItem_get_type, _fairygui_PackageItem_set_type);
    oluacls_prop(L, "width", _fairygui_PackageItem_get_width, _fairygui_PackageItem_set_width);

    olua_registerluatype<fairygui::PackageItem>(L, "fgui.PackageItem");

    return 1;
}

static int luaopen_fairygui_PackageItemType(lua_State *L)
{
    oluacls_class(L, "fgui.PackageItemType", nullptr);
    oluacls_const_integer(L, "ATLAS", (lua_Integer)fairygui::PackageItemType::ATLAS);
    oluacls_const_integer(L, "COMPONENT", (lua_Integer)fairygui::PackageItemType::COMPONENT);
    oluacls_const_integer(L, "FONT", (lua_Integer)fairygui::PackageItemType::FONT);
    oluacls_const_integer(L, "IMAGE", (lua_Integer)fairygui::PackageItemType::IMAGE);
    oluacls_const_integer(L, "MISC", (lua_Integer)fairygui::PackageItemType::MISC);
    oluacls_const_integer(L, "MOVIECLIP", (lua_Integer)fairygui::PackageItemType::MOVIECLIP);
    oluacls_const_integer(L, "SOUND", (lua_Integer)fairygui::PackageItemType::SOUND);
    oluacls_const_integer(L, "SWF", (lua_Integer)fairygui::PackageItemType::SWF);
    oluacls_const_integer(L, "UNKNOWN", (lua_Integer)fairygui::PackageItemType::UNKNOWN);

    olua_registerluatype<fairygui::PackageItemType>(L, "fgui.PackageItemType");

    return 1;
}

static int luaopen_fairygui_ObjectType(lua_State *L)
{
    oluacls_class(L, "fgui.ObjectType", nullptr);
    oluacls_const_integer(L, "BUTTON", (lua_Integer)fairygui::ObjectType::BUTTON);
    oluacls_const_integer(L, "COMBOBOX", (lua_Integer)fairygui::ObjectType::COMBOBOX);
    oluacls_const_integer(L, "COMPONENT", (lua_Integer)fairygui::ObjectType::COMPONENT);
    oluacls_const_integer(L, "GRAPH", (lua_Integer)fairygui::ObjectType::GRAPH);
    oluacls_const_integer(L, "GROUP", (lua_Integer)fairygui::ObjectType::GROUP);
    oluacls_const_integer(L, "IMAGE", (lua_Integer)fairygui::ObjectType::IMAGE);
    oluacls_const_integer(L, "INPUTTEXT", (lua_Integer)fairygui::ObjectType::INPUTTEXT);
    oluacls_const_integer(L, "LABEL", (lua_Integer)fairygui::ObjectType::LABEL);
    oluacls_const_integer(L, "LIST", (lua_Integer)fairygui::ObjectType::LIST);
    oluacls_const_integer(L, "LOADER", (lua_Integer)fairygui::ObjectType::LOADER);
    oluacls_const_integer(L, "MOVIECLIP", (lua_Integer)fairygui::ObjectType::MOVIECLIP);
    oluacls_const_integer(L, "PROGRESSBAR", (lua_Integer)fairygui::ObjectType::PROGRESSBAR);
    oluacls_const_integer(L, "RICHTEXT", (lua_Integer)fairygui::ObjectType::RICHTEXT);
    oluacls_const_integer(L, "SCROLLBAR", (lua_Integer)fairygui::ObjectType::SCROLLBAR);
    oluacls_const_integer(L, "SLIDER", (lua_Integer)fairygui::ObjectType::SLIDER);
    oluacls_const_integer(L, "SWF", (lua_Integer)fairygui::ObjectType::SWF);
    oluacls_const_integer(L, "TEXT", (lua_Integer)fairygui::ObjectType::TEXT);
    oluacls_const_integer(L, "TREE", (lua_Integer)fairygui::ObjectType::TREE);

    olua_registerluatype<fairygui::ObjectType>(L, "fgui.ObjectType");

    return 1;
}

static int luaopen_fairygui_ButtonMode(lua_State *L)
{
    oluacls_class(L, "fgui.ButtonMode", nullptr);
    oluacls_const_integer(L, "CHECK", (lua_Integer)fairygui::ButtonMode::CHECK);
    oluacls_const_integer(L, "COMMON", (lua_Integer)fairygui::ButtonMode::COMMON);
    oluacls_const_integer(L, "RADIO", (lua_Integer)fairygui::ButtonMode::RADIO);

    olua_registerluatype<fairygui::ButtonMode>(L, "fgui.ButtonMode");

    return 1;
}

static int luaopen_fairygui_ChildrenRenderOrder(lua_State *L)
{
    oluacls_class(L, "fgui.ChildrenRenderOrder", nullptr);
    oluacls_const_integer(L, "ARCH", (lua_Integer)fairygui::ChildrenRenderOrder::ARCH);
    oluacls_const_integer(L, "ASCENT", (lua_Integer)fairygui::ChildrenRenderOrder::ASCENT);
    oluacls_const_integer(L, "DESCENT", (lua_Integer)fairygui::ChildrenRenderOrder::DESCENT);

    olua_registerluatype<fairygui::ChildrenRenderOrder>(L, "fgui.ChildrenRenderOrder");

    return 1;
}

static int luaopen_fairygui_OverflowType(lua_State *L)
{
    oluacls_class(L, "fgui.OverflowType", nullptr);
    oluacls_const_integer(L, "HIDDEN", (lua_Integer)fairygui::OverflowType::HIDDEN);
    oluacls_const_integer(L, "SCROLL", (lua_Integer)fairygui::OverflowType::SCROLL);
    oluacls_const_integer(L, "VISIBLE", (lua_Integer)fairygui::OverflowType::VISIBLE);

    olua_registerluatype<fairygui::OverflowType>(L, "fgui.OverflowType");

    return 1;
}

static int luaopen_fairygui_ScrollType(lua_State *L)
{
    oluacls_class(L, "fgui.ScrollType", nullptr);
    oluacls_const_integer(L, "BOTH", (lua_Integer)fairygui::ScrollType::BOTH);
    oluacls_const_integer(L, "HORIZONTAL", (lua_Integer)fairygui::ScrollType::HORIZONTAL);
    oluacls_const_integer(L, "VERTICAL", (lua_Integer)fairygui::ScrollType::VERTICAL);

    olua_registerluatype<fairygui::ScrollType>(L, "fgui.ScrollType");

    return 1;
}

static int luaopen_fairygui_ScrollBarDisplayType(lua_State *L)
{
    oluacls_class(L, "fgui.ScrollBarDisplayType", nullptr);
    oluacls_const_integer(L, "AUTO", (lua_Integer)fairygui::ScrollBarDisplayType::AUTO);
    oluacls_const_integer(L, "DEFAULT", (lua_Integer)fairygui::ScrollBarDisplayType::DEFAULT);
    oluacls_const_integer(L, "HIDDEN", (lua_Integer)fairygui::ScrollBarDisplayType::HIDDEN);
    oluacls_const_integer(L, "VISIBLE", (lua_Integer)fairygui::ScrollBarDisplayType::VISIBLE);

    olua_registerluatype<fairygui::ScrollBarDisplayType>(L, "fgui.ScrollBarDisplayType");

    return 1;
}

static int luaopen_fairygui_LoaderFillType(lua_State *L)
{
    oluacls_class(L, "fgui.LoaderFillType", nullptr);
    oluacls_const_integer(L, "NONE", (lua_Integer)fairygui::LoaderFillType::NONE);
    oluacls_const_integer(L, "SCALE", (lua_Integer)fairygui::LoaderFillType::SCALE);
    oluacls_const_integer(L, "SCALE_FREE", (lua_Integer)fairygui::LoaderFillType::SCALE_FREE);
    oluacls_const_integer(L, "SCALE_MATCH_HEIGHT", (lua_Integer)fairygui::LoaderFillType::SCALE_MATCH_HEIGHT);
    oluacls_const_integer(L, "SCALE_MATCH_WIDTH", (lua_Integer)fairygui::LoaderFillType::SCALE_MATCH_WIDTH);
    oluacls_const_integer(L, "SCALE_NO_BORDER", (lua_Integer)fairygui::LoaderFillType::SCALE_NO_BORDER);

    olua_registerluatype<fairygui::LoaderFillType>(L, "fgui.LoaderFillType");

    return 1;
}

static int luaopen_fairygui_ProgressTitleType(lua_State *L)
{
    oluacls_class(L, "fgui.ProgressTitleType", nullptr);
    oluacls_const_integer(L, "MAX", (lua_Integer)fairygui::ProgressTitleType::MAX);
    oluacls_const_integer(L, "PERCENT", (lua_Integer)fairygui::ProgressTitleType::PERCENT);
    oluacls_const_integer(L, "VALUE", (lua_Integer)fairygui::ProgressTitleType::VALUE);
    oluacls_const_integer(L, "VALUE_MAX", (lua_Integer)fairygui::ProgressTitleType::VALUE_MAX);

    olua_registerluatype<fairygui::ProgressTitleType>(L, "fgui.ProgressTitleType");

    return 1;
}

static int luaopen_fairygui_ListLayoutType(lua_State *L)
{
    oluacls_class(L, "fgui.ListLayoutType", nullptr);
    oluacls_const_integer(L, "FLOW_HORIZONTAL", (lua_Integer)fairygui::ListLayoutType::FLOW_HORIZONTAL);
    oluacls_const_integer(L, "FLOW_VERTICAL", (lua_Integer)fairygui::ListLayoutType::FLOW_VERTICAL);
    oluacls_const_integer(L, "PAGINATION", (lua_Integer)fairygui::ListLayoutType::PAGINATION);
    oluacls_const_integer(L, "SINGLE_COLUMN", (lua_Integer)fairygui::ListLayoutType::SINGLE_COLUMN);
    oluacls_const_integer(L, "SINGLE_ROW", (lua_Integer)fairygui::ListLayoutType::SINGLE_ROW);

    olua_registerluatype<fairygui::ListLayoutType>(L, "fgui.ListLayoutType");

    return 1;
}

static int luaopen_fairygui_ListSelectionMode(lua_State *L)
{
    oluacls_class(L, "fgui.ListSelectionMode", nullptr);
    oluacls_const_integer(L, "MULTIPLE", (lua_Integer)fairygui::ListSelectionMode::MULTIPLE);
    oluacls_const_integer(L, "MULTIPLE_SINGLECLICK", (lua_Integer)fairygui::ListSelectionMode::MULTIPLE_SINGLECLICK);
    oluacls_const_integer(L, "NONE", (lua_Integer)fairygui::ListSelectionMode::NONE);
    oluacls_const_integer(L, "SINGLE", (lua_Integer)fairygui::ListSelectionMode::SINGLE);

    olua_registerluatype<fairygui::ListSelectionMode>(L, "fgui.ListSelectionMode");

    return 1;
}

static int luaopen_fairygui_GroupLayoutType(lua_State *L)
{
    oluacls_class(L, "fgui.GroupLayoutType", nullptr);
    oluacls_const_integer(L, "HORIZONTAL", (lua_Integer)fairygui::GroupLayoutType::HORIZONTAL);
    oluacls_const_integer(L, "NONE", (lua_Integer)fairygui::GroupLayoutType::NONE);
    oluacls_const_integer(L, "VERTICAL", (lua_Integer)fairygui::GroupLayoutType::VERTICAL);

    olua_registerluatype<fairygui::GroupLayoutType>(L, "fgui.GroupLayoutType");

    return 1;
}

static int luaopen_fairygui_PopupDirection(lua_State *L)
{
    oluacls_class(L, "fgui.PopupDirection", nullptr);
    oluacls_const_integer(L, "AUTO", (lua_Integer)fairygui::PopupDirection::AUTO);
    oluacls_const_integer(L, "DOWN", (lua_Integer)fairygui::PopupDirection::DOWN);
    oluacls_const_integer(L, "UP", (lua_Integer)fairygui::PopupDirection::UP);

    olua_registerluatype<fairygui::PopupDirection>(L, "fgui.PopupDirection");

    return 1;
}

static int luaopen_fairygui_AutoSizeType(lua_State *L)
{
    oluacls_class(L, "fgui.AutoSizeType", nullptr);
    oluacls_const_integer(L, "BOTH", (lua_Integer)fairygui::AutoSizeType::BOTH);
    oluacls_const_integer(L, "HEIGHT", (lua_Integer)fairygui::AutoSizeType::HEIGHT);
    oluacls_const_integer(L, "NONE", (lua_Integer)fairygui::AutoSizeType::NONE);
    oluacls_const_integer(L, "SHRINK", (lua_Integer)fairygui::AutoSizeType::SHRINK);

    olua_registerluatype<fairygui::AutoSizeType>(L, "fgui.AutoSizeType");

    return 1;
}

static int luaopen_fairygui_FlipType(lua_State *L)
{
    oluacls_class(L, "fgui.FlipType", nullptr);
    oluacls_const_integer(L, "BOTH", (lua_Integer)fairygui::FlipType::BOTH);
    oluacls_const_integer(L, "HORIZONTAL", (lua_Integer)fairygui::FlipType::HORIZONTAL);
    oluacls_const_integer(L, "NONE", (lua_Integer)fairygui::FlipType::NONE);
    oluacls_const_integer(L, "VERTICAL", (lua_Integer)fairygui::FlipType::VERTICAL);

    olua_registerluatype<fairygui::FlipType>(L, "fgui.FlipType");

    return 1;
}

static int luaopen_fairygui_TransitionActionType(lua_State *L)
{
    oluacls_class(L, "fgui.TransitionActionType", nullptr);
    oluacls_const_integer(L, "Alpha", (lua_Integer)fairygui::TransitionActionType::Alpha);
    oluacls_const_integer(L, "Animation", (lua_Integer)fairygui::TransitionActionType::Animation);
    oluacls_const_integer(L, "Color", (lua_Integer)fairygui::TransitionActionType::Color);
    oluacls_const_integer(L, "ColorFilter", (lua_Integer)fairygui::TransitionActionType::ColorFilter);
    oluacls_const_integer(L, "Icon", (lua_Integer)fairygui::TransitionActionType::Icon);
    oluacls_const_integer(L, "Pivot", (lua_Integer)fairygui::TransitionActionType::Pivot);
    oluacls_const_integer(L, "Rotation", (lua_Integer)fairygui::TransitionActionType::Rotation);
    oluacls_const_integer(L, "Scale", (lua_Integer)fairygui::TransitionActionType::Scale);
    oluacls_const_integer(L, "Shake", (lua_Integer)fairygui::TransitionActionType::Shake);
    oluacls_const_integer(L, "Size", (lua_Integer)fairygui::TransitionActionType::Size);
    oluacls_const_integer(L, "Skew", (lua_Integer)fairygui::TransitionActionType::Skew);
    oluacls_const_integer(L, "Sound", (lua_Integer)fairygui::TransitionActionType::Sound);
    oluacls_const_integer(L, "Text", (lua_Integer)fairygui::TransitionActionType::Text);
    oluacls_const_integer(L, "Transition", (lua_Integer)fairygui::TransitionActionType::Transition);
    oluacls_const_integer(L, "Unknown", (lua_Integer)fairygui::TransitionActionType::Unknown);
    oluacls_const_integer(L, "Visible", (lua_Integer)fairygui::TransitionActionType::Visible);
    oluacls_const_integer(L, "XY", (lua_Integer)fairygui::TransitionActionType::XY);

    olua_registerluatype<fairygui::TransitionActionType>(L, "fgui.TransitionActionType");

    return 1;
}

static int luaopen_fairygui_FillMethod(lua_State *L)
{
    oluacls_class(L, "fgui.FillMethod", nullptr);
    oluacls_const_integer(L, "Horizontal", (lua_Integer)fairygui::FillMethod::Horizontal);
    oluacls_const_integer(L, "None", (lua_Integer)fairygui::FillMethod::None);
    oluacls_const_integer(L, "Radial180", (lua_Integer)fairygui::FillMethod::Radial180);
    oluacls_const_integer(L, "Radial360", (lua_Integer)fairygui::FillMethod::Radial360);
    oluacls_const_integer(L, "Radial90", (lua_Integer)fairygui::FillMethod::Radial90);
    oluacls_const_integer(L, "Vertical", (lua_Integer)fairygui::FillMethod::Vertical);

    olua_registerluatype<fairygui::FillMethod>(L, "fgui.FillMethod");

    return 1;
}

static int luaopen_fairygui_FillOrigin(lua_State *L)
{
    oluacls_class(L, "fgui.FillOrigin", nullptr);
    oluacls_const_integer(L, "Bottom", (lua_Integer)fairygui::FillOrigin::Bottom);
    oluacls_const_integer(L, "Left", (lua_Integer)fairygui::FillOrigin::Left);
    oluacls_const_integer(L, "Right", (lua_Integer)fairygui::FillOrigin::Right);
    oluacls_const_integer(L, "Top", (lua_Integer)fairygui::FillOrigin::Top);

    olua_registerluatype<fairygui::FillOrigin>(L, "fgui.FillOrigin");

    return 1;
}

static int luaopen_fairygui_ObjectPropID(lua_State *L)
{
    oluacls_class(L, "fgui.ObjectPropID", nullptr);
    oluacls_const_integer(L, "Color", (lua_Integer)fairygui::ObjectPropID::Color);
    oluacls_const_integer(L, "DeltaTime", (lua_Integer)fairygui::ObjectPropID::DeltaTime);
    oluacls_const_integer(L, "FontSize", (lua_Integer)fairygui::ObjectPropID::FontSize);
    oluacls_const_integer(L, "Frame", (lua_Integer)fairygui::ObjectPropID::Frame);
    oluacls_const_integer(L, "Icon", (lua_Integer)fairygui::ObjectPropID::Icon);
    oluacls_const_integer(L, "OutlineColor", (lua_Integer)fairygui::ObjectPropID::OutlineColor);
    oluacls_const_integer(L, "Playing", (lua_Integer)fairygui::ObjectPropID::Playing);
    oluacls_const_integer(L, "Selected", (lua_Integer)fairygui::ObjectPropID::Selected);
    oluacls_const_integer(L, "Text", (lua_Integer)fairygui::ObjectPropID::Text);
    oluacls_const_integer(L, "TimeScale", (lua_Integer)fairygui::ObjectPropID::TimeScale);

    olua_registerluatype<fairygui::ObjectPropID>(L, "fgui.ObjectPropID");

    return 1;
}

static int _fairygui_GController___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (fairygui::GController *)olua_toobj(L, 1, "fgui.GController");
    olua_push_cppobj(L, self, "fgui.GController");

    olua_endinvoke(L);

    return 1;
}

static int _fairygui_GController_getPageCount(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GController *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GController");

    // int getPageCount()
    int ret = (int)self->getPageCount();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GController_getPageId(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GController *self = nullptr;
    lua_Integer arg1 = 0;       /** index */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GController");
    olua_check_int(L, 2, &arg1);

    // const std::string &getPageId(int index)
    const std::string &ret = (const std::string &)self->getPageId((int)arg1);
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GController_getPageIndexById(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GController *self = nullptr;
    std::string arg1;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GController");
    olua_check_std_string(L, 2, &arg1);

    // int getPageIndexById(const std::string &value)
    int ret = (int)self->getPageIndexById(arg1);
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GController_getPageNameById(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GController *self = nullptr;
    std::string arg1;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GController");
    olua_check_std_string(L, 2, &arg1);

    // const std::string &getPageNameById(const std::string &value)
    const std::string &ret = (const std::string &)self->getPageNameById(arg1);
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GController_getParent(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GController *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GController");

    // fairygui::GComponent *getParent()
    fairygui::GComponent *ret = (fairygui::GComponent *)self->getParent();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GComponent");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GController_getPreviousPage(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GController *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GController");

    // const std::string &getPreviousPage()
    const std::string &ret = (const std::string &)self->getPreviousPage();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GController_getPreviousPageId(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GController *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GController");

    // const std::string &getPreviousPageId()
    const std::string &ret = (const std::string &)self->getPreviousPageId();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GController_getPrevisousIndex(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GController *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GController");

    // int getPrevisousIndex()
    int ret = (int)self->getPrevisousIndex();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GController_getSelectedIndex(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GController *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GController");

    // int getSelectedIndex()
    int ret = (int)self->getSelectedIndex();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GController_getSelectedPage(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GController *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GController");

    // const std::string &getSelectedPage()
    const std::string &ret = (const std::string &)self->getSelectedPage();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GController_getSelectedPageId(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GController *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GController");

    // const std::string &getSelectedPageId()
    const std::string &ret = (const std::string &)self->getSelectedPageId();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GController_hasPage(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GController *self = nullptr;
    std::string arg1;       /** aName */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GController");
    olua_check_std_string(L, 2, &arg1);

    // bool hasPage(const std::string &aName)
    bool ret = (bool)self->hasPage(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GController_new(lua_State *L)
{
    olua_startinvoke(L);

    // GController()
    fairygui::GController *ret = (fairygui::GController *)new fairygui::GController();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GController");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GController_runActions(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GController *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GController");

    // void runActions()
    self->runActions();

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GController_setOppositePageId(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GController *self = nullptr;
    std::string arg1;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GController");
    olua_check_std_string(L, 2, &arg1);

    // void setOppositePageId(const std::string &value)
    self->setOppositePageId(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GController_setParent(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GController *self = nullptr;
    fairygui::GComponent *arg1 = nullptr;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GController");
    olua_check_cppobj(L, 2, (void **)&arg1, "fgui.GComponent");

    // void setParent(fairygui::GComponent *value)
    self->setParent(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GController_setSelectedIndex1(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GController *self = nullptr;
    lua_Integer arg1 = 0;       /** value */
    bool arg2 = false;       /** triggerEvent */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GController");
    olua_check_int(L, 2, &arg1);
    olua_check_bool(L, 3, &arg2);

    // void setSelectedIndex(int value, @optional bool triggerEvent)
    self->setSelectedIndex((int)arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GController_setSelectedIndex2(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GController *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GController");
    olua_check_int(L, 2, &arg1);

    // void setSelectedIndex(int value, @optional bool triggerEvent)
    self->setSelectedIndex((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GController_setSelectedIndex(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_int(L, 2))) {
            // void setSelectedIndex(int value, @optional bool triggerEvent)
            return _fairygui_GController_setSelectedIndex2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_int(L, 2)) && (olua_is_bool(L, 3))) {
            // void setSelectedIndex(int value, @optional bool triggerEvent)
            return _fairygui_GController_setSelectedIndex1(L);
        // }
    }

    luaL_error(L, "method 'fairygui::GController::setSelectedIndex' not support '%d' arguments", num_args);

    return 0;
}

static int _fairygui_GController_setSelectedPage1(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GController *self = nullptr;
    std::string arg1;       /** value */
    bool arg2 = false;       /** triggerEvent */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GController");
    olua_check_std_string(L, 2, &arg1);
    olua_check_bool(L, 3, &arg2);

    // void setSelectedPage(const std::string &value, @optional bool triggerEvent)
    self->setSelectedPage(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GController_setSelectedPage2(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GController *self = nullptr;
    std::string arg1;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GController");
    olua_check_std_string(L, 2, &arg1);

    // void setSelectedPage(const std::string &value, @optional bool triggerEvent)
    self->setSelectedPage(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GController_setSelectedPage(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 2))) {
            // void setSelectedPage(const std::string &value, @optional bool triggerEvent)
            return _fairygui_GController_setSelectedPage2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_bool(L, 3))) {
            // void setSelectedPage(const std::string &value, @optional bool triggerEvent)
            return _fairygui_GController_setSelectedPage1(L);
        // }
    }

    luaL_error(L, "method 'fairygui::GController::setSelectedPage' not support '%d' arguments", num_args);

    return 0;
}

static int _fairygui_GController_setSelectedPageId1(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GController *self = nullptr;
    std::string arg1;       /** value */
    bool arg2 = false;       /** triggerEvent */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GController");
    olua_check_std_string(L, 2, &arg1);
    olua_check_bool(L, 3, &arg2);

    // void setSelectedPageId(const std::string &value, @optional bool triggerEvent)
    self->setSelectedPageId(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GController_setSelectedPageId2(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GController *self = nullptr;
    std::string arg1;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GController");
    olua_check_std_string(L, 2, &arg1);

    // void setSelectedPageId(const std::string &value, @optional bool triggerEvent)
    self->setSelectedPageId(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GController_setSelectedPageId(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 2))) {
            // void setSelectedPageId(const std::string &value, @optional bool triggerEvent)
            return _fairygui_GController_setSelectedPageId2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_bool(L, 3))) {
            // void setSelectedPageId(const std::string &value, @optional bool triggerEvent)
            return _fairygui_GController_setSelectedPageId1(L);
        // }
    }

    luaL_error(L, "method 'fairygui::GController::setSelectedPageId' not support '%d' arguments", num_args);

    return 0;
}

static int _fairygui_GController_get_autoRadioGroupDepth(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GController *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GController");

    // bool autoRadioGroupDepth
    bool ret = (bool)self->autoRadioGroupDepth;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GController_set_autoRadioGroupDepth(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GController *self = nullptr;
    bool arg1 = false;       /** autoRadioGroupDepth */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GController");
    olua_check_bool(L, 2, &arg1);

    // bool autoRadioGroupDepth
    self->autoRadioGroupDepth = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GController_get_changing(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GController *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GController");

    // bool changing
    bool ret = (bool)self->changing;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GController_set_changing(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GController *self = nullptr;
    bool arg1 = false;       /** changing */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GController");
    olua_check_bool(L, 2, &arg1);

    // bool changing
    self->changing = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GController_get_name(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GController *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GController");

    // std::string name
    std::string ret = (std::string)self->name;
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GController_set_name(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GController *self = nullptr;
    std::string arg1;       /** name */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GController");
    olua_check_std_string(L, 2, &arg1);

    // std::string name
    self->name = arg1;

    olua_endinvoke(L);

    return 0;
}

static int luaopen_fairygui_GController(lua_State *L)
{
    oluacls_class(L, "fgui.GController", "fgui.UIEventDispatcher");
    oluacls_func(L, "__move", _fairygui_GController___move);
    oluacls_func(L, "getPageCount", _fairygui_GController_getPageCount);
    oluacls_func(L, "getPageId", _fairygui_GController_getPageId);
    oluacls_func(L, "getPageIndexById", _fairygui_GController_getPageIndexById);
    oluacls_func(L, "getPageNameById", _fairygui_GController_getPageNameById);
    oluacls_func(L, "getParent", _fairygui_GController_getParent);
    oluacls_func(L, "getPreviousPage", _fairygui_GController_getPreviousPage);
    oluacls_func(L, "getPreviousPageId", _fairygui_GController_getPreviousPageId);
    oluacls_func(L, "getPrevisousIndex", _fairygui_GController_getPrevisousIndex);
    oluacls_func(L, "getSelectedIndex", _fairygui_GController_getSelectedIndex);
    oluacls_func(L, "getSelectedPage", _fairygui_GController_getSelectedPage);
    oluacls_func(L, "getSelectedPageId", _fairygui_GController_getSelectedPageId);
    oluacls_func(L, "hasPage", _fairygui_GController_hasPage);
    oluacls_func(L, "new", _fairygui_GController_new);
    oluacls_func(L, "runActions", _fairygui_GController_runActions);
    oluacls_func(L, "setOppositePageId", _fairygui_GController_setOppositePageId);
    oluacls_func(L, "setParent", _fairygui_GController_setParent);
    oluacls_func(L, "setSelectedIndex", _fairygui_GController_setSelectedIndex);
    oluacls_func(L, "setSelectedPage", _fairygui_GController_setSelectedPage);
    oluacls_func(L, "setSelectedPageId", _fairygui_GController_setSelectedPageId);
    oluacls_prop(L, "pageCount", _fairygui_GController_getPageCount, nullptr);
    oluacls_prop(L, "parent", _fairygui_GController_getParent, _fairygui_GController_setParent);
    oluacls_prop(L, "previousPage", _fairygui_GController_getPreviousPage, nullptr);
    oluacls_prop(L, "previousPageId", _fairygui_GController_getPreviousPageId, nullptr);
    oluacls_prop(L, "previsousIndex", _fairygui_GController_getPrevisousIndex, nullptr);
    oluacls_prop(L, "selectedIndex", _fairygui_GController_getSelectedIndex, _fairygui_GController_setSelectedIndex);
    oluacls_prop(L, "selectedPage", _fairygui_GController_getSelectedPage, _fairygui_GController_setSelectedPage);
    oluacls_prop(L, "selectedPageId", _fairygui_GController_getSelectedPageId, _fairygui_GController_setSelectedPageId);
    oluacls_prop(L, "autoRadioGroupDepth", _fairygui_GController_get_autoRadioGroupDepth, _fairygui_GController_set_autoRadioGroupDepth);
    oluacls_prop(L, "changing", _fairygui_GController_get_changing, _fairygui_GController_set_changing);
    oluacls_prop(L, "name", _fairygui_GController_get_name, _fairygui_GController_set_name);

    olua_registerluatype<fairygui::GController>(L, "fgui.GController");

    return 1;
}

static int _fairygui_GObject___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (fairygui::GObject *)olua_toobj(L, 1, "fgui.GObject");
    olua_push_cppobj(L, self, "fgui.GObject");

    olua_endinvoke(L);

    return 1;
}

static int _fairygui_GObject_addClickListener1(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;
    std::function<void(fairygui::EventContext *)> arg1;       /** callback */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");

    void *self_obj = (void *)self;
    std::string tag = makeListenerTag(L, fairygui::UIEventType::Click, 0);
    std::string func = olua_setcallback(L, self_obj, tag.c_str(), 2, OLUA_TAG_NEW);
    lua_Unsigned ctx = olua_context(L);
    arg1 = [self_obj, func, ctx](fairygui::EventContext *arg1) {
        lua_State *L = olua_mainthread(NULL);

        if (L != NULL && (olua_context(L) == ctx)) {
            int top = lua_gettop(L);
            size_t last = olua_push_objpool(L);
            olua_enable_objpool(L);
            olua_push_cppobj(L, arg1, "fgui.EventContext");
            olua_disable_objpool(L);

            olua_callback(L, self_obj, func.c_str(), 1);

            //pop stack value
            olua_pop_objpool(L, last);
            lua_settop(L, top);
        }
    };

    // void addClickListener(@local const std::function<void (EventContext *)> &callback)
    self->addClickListener(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GObject_addClickListener2(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;
    std::function<void(fairygui::EventContext *)> arg1;       /** callback */
    fairygui::EventTag arg2;       /** tag */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");
    manual_olua_check_fairygui_EventTag(L, 3, &arg2);

    void *self_obj = (void *)self;
    std::string tag = makeListenerTag(L, fairygui::UIEventType::Click, 3);
    std::string func = olua_setcallback(L, self_obj, tag.c_str(), 2, OLUA_TAG_NEW);
    lua_Unsigned ctx = olua_context(L);
    arg1 = [self_obj, func, ctx](fairygui::EventContext *arg1) {
        lua_State *L = olua_mainthread(NULL);

        if (L != NULL && (olua_context(L) == ctx)) {
            int top = lua_gettop(L);
            size_t last = olua_push_objpool(L);
            olua_enable_objpool(L);
            olua_push_cppobj(L, arg1, "fgui.EventContext");
            olua_disable_objpool(L);

            olua_callback(L, self_obj, func.c_str(), 1);

            //pop stack value
            olua_pop_objpool(L, last);
            lua_settop(L, top);
        }
    };

    // void addClickListener(@local const std::function<void (EventContext *)> &callback, const fairygui::EventTag &tag)
    self->addClickListener(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GObject_addClickListener(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_std_function(L, 2))) {
            // void addClickListener(@local const std::function<void (EventContext *)> &callback)
            return _fairygui_GObject_addClickListener1(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_function(L, 2)) && (manual_olua_is_fairygui_EventTag(L, 3))) {
            // void addClickListener(@local const std::function<void (EventContext *)> &callback, const fairygui::EventTag &tag)
            return _fairygui_GObject_addClickListener2(L);
        // }
    }

    luaL_error(L, "method 'fairygui::GObject::addClickListener' not support '%d' arguments", num_args);

    return 0;
}

static int _fairygui_GObject_addDisplayLock(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");

    // uint32_t addDisplayLock()
    uint32_t ret = (uint32_t)self->addDisplayLock();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GObject_addRelation1(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;
    fairygui::GObject *arg1 = nullptr;       /** target */
    lua_Unsigned arg2 = 0;       /** relationType */
    bool arg3 = false;       /** usePercent */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");
    olua_check_cppobj(L, 2, (void **)&arg1, "fgui.GObject");
    olua_check_uint(L, 3, &arg2);
    olua_check_bool(L, 4, &arg3);

    // void addRelation(fairygui::GObject *target, fairygui::RelationType relationType, @optional bool usePercent)
    self->addRelation(arg1, (fairygui::RelationType)arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GObject_addRelation2(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;
    fairygui::GObject *arg1 = nullptr;       /** target */
    lua_Unsigned arg2 = 0;       /** relationType */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");
    olua_check_cppobj(L, 2, (void **)&arg1, "fgui.GObject");
    olua_check_uint(L, 3, &arg2);

    // void addRelation(fairygui::GObject *target, fairygui::RelationType relationType, @optional bool usePercent)
    self->addRelation(arg1, (fairygui::RelationType)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GObject_addRelation(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 2) {
        // if ((olua_is_cppobj(L, 2, "fgui.GObject")) && (olua_is_uint(L, 3))) {
            // void addRelation(fairygui::GObject *target, fairygui::RelationType relationType, @optional bool usePercent)
            return _fairygui_GObject_addRelation2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_cppobj(L, 2, "fgui.GObject")) && (olua_is_uint(L, 3)) && (olua_is_bool(L, 4))) {
            // void addRelation(fairygui::GObject *target, fairygui::RelationType relationType, @optional bool usePercent)
            return _fairygui_GObject_addRelation1(L);
        // }
    }

    luaL_error(L, "method 'fairygui::GObject::addRelation' not support '%d' arguments", num_args);

    return 0;
}

static int _fairygui_GObject_center1(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;
    bool arg1 = false;       /** restraint */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");
    olua_check_bool(L, 2, &arg1);

    // inject code before call
    if (!self->getParent() && !fairygui::UIRoot) {
        luaL_error(L, "UIRoot and parent are both nullptr");
    }

    // void center(@optional bool restraint)
    self->center(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GObject_center2(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");

    // inject code before call
    if (!self->getParent() && !fairygui::UIRoot) {
        luaL_error(L, "UIRoot and parent are both nullptr");
    }

    // void center(@optional bool restraint)
    self->center();

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GObject_center(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // void center(@optional bool restraint)
        return _fairygui_GObject_center2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_bool(L, 2))) {
            // void center(@optional bool restraint)
            return _fairygui_GObject_center1(L);
        // }
    }

    luaL_error(L, "method 'fairygui::GObject::center' not support '%d' arguments", num_args);

    return 0;
}

static int _fairygui_GObject_checkGearController(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;
    lua_Integer arg1 = 0;       /** index */
    fairygui::GController *arg2 = nullptr;       /** c */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");
    olua_check_int(L, 2, &arg1);
    olua_check_cppobj(L, 3, (void **)&arg2, "fgui.GController");

    // bool checkGearController(int index, fairygui::GController *c)
    bool ret = (bool)self->checkGearController((int)arg1, arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GObject_create(lua_State *L)
{
    olua_startinvoke(L);

    // static fairygui::GObject *create()
    fairygui::GObject *ret = (fairygui::GObject *)fairygui::GObject::create();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GObject");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GObject_displayObject(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");

    // @addref(displayObject ^) cocos2d::Node *displayObject()
    cocos2d::Node *ret = (cocos2d::Node *)self->displayObject();
    int num_ret = olua_push_cppobj(L, ret, "cc.Node");

    // inject code after call
    olua_addref(L, 1, "displayObject", -1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GObject_findParent(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");

    // fairygui::GObject *findParent()
    fairygui::GObject *ret = (fairygui::GObject *)self->findParent();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GObject");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GObject_getAlpha(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");

    // float getAlpha()
    float ret = (float)self->getAlpha();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GObject_getCustomData(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");

    // const cocos2d::Value &getCustomData()
    const cocos2d::Value &ret = (const cocos2d::Value &)self->getCustomData();
    int num_ret = manual_olua_push_cocos2d_Value(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GObject_getData(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");

    // void *getData()
    void *ret = (void *)self->getData();
    int num_ret = olua_push_obj(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GObject_getDragBounds(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = olua_toobj<fairygui::GObject>(L, 1);
    cocos2d::Rect *rect = self->getDragBounds();
    manual_olua_push_cocos2d_Rect(L, rect);

    olua_endinvoke(L);

    return 1;
}

static int _fairygui_GObject_getDraggingObject(lua_State *L)
{
    olua_startinvoke(L);

    // static fairygui::GObject *getDraggingObject()
    fairygui::GObject *ret = (fairygui::GObject *)fairygui::GObject::getDraggingObject();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GObject");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GObject_getGear(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;
    lua_Integer arg1 = 0;       /** index */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");
    olua_check_int(L, 2, &arg1);

    // fairygui::GearBase *getGear(int index)
    fairygui::GearBase *ret = (fairygui::GearBase *)self->getGear((int)arg1);
    int num_ret = olua_push_cppobj(L, ret, "fgui.GearBase");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GObject_getGroup(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");

    // @addref(group ^) fairygui::GGroup *getGroup()
    fairygui::GGroup *ret = (fairygui::GGroup *)self->getGroup();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GGroup");

    // inject code after call
    olua_addref(L, 1, "group", -1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GObject_getHeight(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");

    // float getHeight()
    float ret = (float)self->getHeight();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GObject_getIcon(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");

    // const std::string &getIcon()
    const std::string &ret = (const std::string &)self->getIcon();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GObject_getPackageItem(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");

    // fairygui::PackageItem *getPackageItem()
    fairygui::PackageItem *ret = (fairygui::PackageItem *)self->getPackageItem();
    int num_ret = olua_push_cppobj(L, ret, "fgui.PackageItem");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GObject_getParent(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");

    // fairygui::GComponent *getParent()
    fairygui::GComponent *ret = (fairygui::GComponent *)self->getParent();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GComponent");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GObject_getPivot(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");

    // const cocos2d::Vec2 &getPivot()
    const cocos2d::Vec2 &ret = (const cocos2d::Vec2 &)self->getPivot();
    int num_ret = auto_olua_push_cocos2d_Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GObject_getPosition(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");

    // const cocos2d::Vec2 &getPosition()
    const cocos2d::Vec2 &ret = (const cocos2d::Vec2 &)self->getPosition();
    int num_ret = auto_olua_push_cocos2d_Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GObject_getProp(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;
    lua_Unsigned arg1 = 0;       /** propId */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");
    olua_check_uint(L, 2, &arg1);

    // cocos2d::Value getProp(fairygui::ObjectPropID propId)
    cocos2d::Value ret = (cocos2d::Value)self->getProp((fairygui::ObjectPropID)arg1);
    int num_ret = manual_olua_push_cocos2d_Value(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GObject_getResourceURL(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");

    // std::string getResourceURL()
    std::string ret = (std::string)self->getResourceURL();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GObject_getRoot(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");

    // fairygui::GRoot *getRoot()
    fairygui::GRoot *ret = (fairygui::GRoot *)self->getRoot();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GRoot");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GObject_getRotation(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");

    // float getRotation()
    float ret = (float)self->getRotation();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GObject_getScale(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");

    // const cocos2d::Vec2 &getScale()
    const cocos2d::Vec2 &ret = (const cocos2d::Vec2 &)self->getScale();
    int num_ret = auto_olua_push_cocos2d_Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GObject_getScaleX(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");

    // float getScaleX()
    float ret = (float)self->getScaleX();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GObject_getScaleY(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");

    // float getScaleY()
    float ret = (float)self->getScaleY();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GObject_getSize(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");

    // const cocos2d::Size &getSize()
    const cocos2d::Size &ret = (const cocos2d::Size &)self->getSize();
    int num_ret = auto_olua_push_cocos2d_Size(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GObject_getSkewX(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");

    // float getSkewX()
    float ret = (float)self->getSkewX();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GObject_getSkewY(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");

    // float getSkewY()
    float ret = (float)self->getSkewY();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GObject_getSortingOrder(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");

    // int getSortingOrder()
    int ret = (int)self->getSortingOrder();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GObject_getText(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");

    // const std::string &getText()
    const std::string &ret = (const std::string &)self->getText();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GObject_getTooltips(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");

    // const std::string &getTooltips()
    const std::string &ret = (const std::string &)self->getTooltips();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GObject_getWidth(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");

    // float getWidth()
    float ret = (float)self->getWidth();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GObject_getX(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");

    // float getX()
    float ret = (float)self->getX();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GObject_getXMin(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");

    // float getXMin()
    float ret = (float)self->getXMin();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GObject_getY(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");

    // float getY()
    float ret = (float)self->getY();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GObject_getYMin(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");

    // float getYMin()
    float ret = (float)self->getYMin();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GObject_globalToLocal1(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;
    cocos2d::Vec2 arg1;       /** pt */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);

    // cocos2d::Vec2 globalToLocal(const cocos2d::Vec2 &pt)
    cocos2d::Vec2 ret = (cocos2d::Vec2)self->globalToLocal(arg1);
    int num_ret = auto_olua_push_cocos2d_Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GObject_globalToLocal2(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;
    cocos2d::Vec2 arg1;       /** pt */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");
    auto_olua_pack_cocos2d_Vec2(L, 2, &arg1);

    // cocos2d::Vec2 globalToLocal(@pack const cocos2d::Vec2 &pt)
    cocos2d::Vec2 ret = (cocos2d::Vec2)self->globalToLocal(arg1);
    int num_ret = auto_olua_unpack_cocos2d_Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GObject_globalToLocal3(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;
    cocos2d::Rect arg1;       /** rect */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");
    manual_olua_check_cocos2d_Rect(L, 2, &arg1);

    // cocos2d::Rect globalToLocal(const cocos2d::Rect &rect)
    cocos2d::Rect ret = (cocos2d::Rect)self->globalToLocal(arg1);
    int num_ret = manual_olua_push_cocos2d_Rect(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GObject_globalToLocal4(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;
    cocos2d::Rect arg1;       /** rect */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");
    manual_olua_pack_cocos2d_Rect(L, 2, &arg1);

    // cocos2d::Rect globalToLocal(@pack const cocos2d::Rect &rect)
    cocos2d::Rect ret = (cocos2d::Rect)self->globalToLocal(arg1);
    int num_ret = manual_olua_unpack_cocos2d_Rect(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GObject_globalToLocal(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        if ((manual_olua_is_cocos2d_Rect(L, 2))) {
            // cocos2d::Rect globalToLocal(const cocos2d::Rect &rect)
            return _fairygui_GObject_globalToLocal3(L);
        }

        // if ((auto_olua_is_cocos2d_Vec2(L, 2))) {
            // cocos2d::Vec2 globalToLocal(const cocos2d::Vec2 &pt)
            return _fairygui_GObject_globalToLocal1(L);
        // }
    }

    if (num_args == 2) {
        // if ((auto_olua_ispack_cocos2d_Vec2(L, 2))) {
            // cocos2d::Vec2 globalToLocal(@pack const cocos2d::Vec2 &pt)
            return _fairygui_GObject_globalToLocal2(L);
        // }
    }

    if (num_args == 4) {
        // if ((manual_olua_ispack_cocos2d_Rect(L, 2))) {
            // cocos2d::Rect globalToLocal(@pack const cocos2d::Rect &rect)
            return _fairygui_GObject_globalToLocal4(L);
        // }
    }

    luaL_error(L, "method 'fairygui::GObject::globalToLocal' not support '%d' arguments", num_args);

    return 0;
}

static int _fairygui_GObject_hitTest(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;
    cocos2d::Vec2 arg1;       /** worldPoint */
    cocos2d::Camera *arg2 = nullptr;       /** camera */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);
    olua_check_cppobj(L, 3, (void **)&arg2, "cc.Camera");

    // fairygui::GObject *hitTest(const cocos2d::Vec2 &worldPoint, const cocos2d::Camera *camera)
    fairygui::GObject *ret = (fairygui::GObject *)self->hitTest(arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "fgui.GObject");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GObject_isDraggable(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");

    // bool isDraggable()
    bool ret = (bool)self->isDraggable();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GObject_isGrayed(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");

    // bool isGrayed()
    bool ret = (bool)self->isGrayed();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GObject_isPivotAsAnchor(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");

    // bool isPivotAsAnchor()
    bool ret = (bool)self->isPivotAsAnchor();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GObject_isPixelSnapping(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");

    // bool isPixelSnapping()
    bool ret = (bool)self->isPixelSnapping();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GObject_isTouchable(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");

    // bool isTouchable()
    bool ret = (bool)self->isTouchable();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GObject_isVisible(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");

    // bool isVisible()
    bool ret = (bool)self->isVisible();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GObject_localToGlobal1(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;
    cocos2d::Vec2 arg1;       /** pt */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);

    // cocos2d::Vec2 localToGlobal(const cocos2d::Vec2 &pt)
    cocos2d::Vec2 ret = (cocos2d::Vec2)self->localToGlobal(arg1);
    int num_ret = auto_olua_push_cocos2d_Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GObject_localToGlobal2(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;
    cocos2d::Vec2 arg1;       /** pt */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");
    auto_olua_pack_cocos2d_Vec2(L, 2, &arg1);

    // cocos2d::Vec2 localToGlobal(@pack const cocos2d::Vec2 &pt)
    cocos2d::Vec2 ret = (cocos2d::Vec2)self->localToGlobal(arg1);
    int num_ret = auto_olua_unpack_cocos2d_Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GObject_localToGlobal3(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;
    cocos2d::Rect arg1;       /** rect */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");
    manual_olua_check_cocos2d_Rect(L, 2, &arg1);

    // cocos2d::Rect localToGlobal(const cocos2d::Rect &rect)
    cocos2d::Rect ret = (cocos2d::Rect)self->localToGlobal(arg1);
    int num_ret = manual_olua_push_cocos2d_Rect(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GObject_localToGlobal4(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;
    cocos2d::Rect arg1;       /** rect */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");
    manual_olua_pack_cocos2d_Rect(L, 2, &arg1);

    // cocos2d::Rect localToGlobal(@pack const cocos2d::Rect &rect)
    cocos2d::Rect ret = (cocos2d::Rect)self->localToGlobal(arg1);
    int num_ret = manual_olua_unpack_cocos2d_Rect(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GObject_localToGlobal(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        if ((manual_olua_is_cocos2d_Rect(L, 2))) {
            // cocos2d::Rect localToGlobal(const cocos2d::Rect &rect)
            return _fairygui_GObject_localToGlobal3(L);
        }

        // if ((auto_olua_is_cocos2d_Vec2(L, 2))) {
            // cocos2d::Vec2 localToGlobal(const cocos2d::Vec2 &pt)
            return _fairygui_GObject_localToGlobal1(L);
        // }
    }

    if (num_args == 2) {
        // if ((auto_olua_ispack_cocos2d_Vec2(L, 2))) {
            // cocos2d::Vec2 localToGlobal(@pack const cocos2d::Vec2 &pt)
            return _fairygui_GObject_localToGlobal2(L);
        // }
    }

    if (num_args == 4) {
        // if ((manual_olua_ispack_cocos2d_Rect(L, 2))) {
            // cocos2d::Rect localToGlobal(@pack const cocos2d::Rect &rect)
            return _fairygui_GObject_localToGlobal4(L);
        // }
    }

    luaL_error(L, "method 'fairygui::GObject::localToGlobal' not support '%d' arguments", num_args);

    return 0;
}

static int _fairygui_GObject_makeFullScreen(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");

    // inject code before call
    if (!fairygui::UIRoot) {
        luaL_error(L, "UIRoot is nullptr");
    }

    // void makeFullScreen()
    self->makeFullScreen();

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GObject_new(lua_State *L)
{
    olua_startinvoke(L);

    // GObject()
    fairygui::GObject *ret = (fairygui::GObject *)new fairygui::GObject();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GObject");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GObject_onStage(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");

    // bool onStage()
    bool ret = (bool)self->onStage();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GObject_relations(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");

    // fairygui::Relations *relations()
    fairygui::Relations *ret = (fairygui::Relations *)self->relations();
    int num_ret = olua_push_cppobj(L, ret, "fgui.Relations");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GObject_releaseDisplayLock(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;
    lua_Unsigned arg1 = 0;       /** token */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");
    olua_check_uint(L, 2, &arg1);

    // void releaseDisplayLock(uint32_t token)
    self->releaseDisplayLock((uint32_t)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GObject_removeClickListener(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;
    fairygui::EventTag arg1;       /** tag */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");
    manual_olua_check_fairygui_EventTag(L, 2, &arg1);

    std::string tag = makeListenerTag(L, fairygui::UIEventType::Click, 2);
    void *self_obj = (void *)self;
    olua_removecallback(L, self_obj, tag.c_str(), OLUA_TAG_SUBEQUAL);

    // void removeClickListener(const fairygui::EventTag &tag)
    self->removeClickListener(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GObject_removeFromParent(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");

    // void removeFromParent()
    self->removeFromParent();

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GObject_removeRelation(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;
    fairygui::GObject *arg1 = nullptr;       /** target */
    lua_Unsigned arg2 = 0;       /** relationType */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");
    olua_check_cppobj(L, 2, (void **)&arg1, "fgui.GObject");
    olua_check_uint(L, 3, &arg2);

    // void removeRelation(fairygui::GObject *target, fairygui::RelationType relationType)
    self->removeRelation(arg1, (fairygui::RelationType)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GObject_setAlpha(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;
    lua_Number arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");
    olua_check_number(L, 2, &arg1);

    // void setAlpha(float value)
    self->setAlpha((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GObject_setCustomData(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;
    cocos2d::Value arg1;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");
    manual_olua_check_cocos2d_Value(L, 2, &arg1);

    // void setCustomData(const cocos2d::Value &value)
    self->setCustomData(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GObject_setData(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;
    void *arg1 = nullptr;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");
    olua_check_obj(L, 2, (void **)&arg1, "void *");

    // void setData(void *value)
    self->setData(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GObject_setDragBounds(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;
    cocos2d::Rect arg1;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");
    manual_olua_check_cocos2d_Rect(L, 2, &arg1);

    // void setDragBounds(const cocos2d::Rect &value)
    self->setDragBounds(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GObject_setDraggable(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;
    bool arg1 = false;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");
    olua_check_bool(L, 2, &arg1);

    // void setDraggable(bool value)
    self->setDraggable(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GObject_setGrayed(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;
    bool arg1 = false;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");
    olua_check_bool(L, 2, &arg1);

    // void setGrayed(bool value)
    self->setGrayed(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GObject_setGroup(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;
    fairygui::GGroup *arg1 = nullptr;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");
    olua_check_cppobj(L, 2, (void **)&arg1, "fgui.GGroup");

    // void setGroup(@addref(group ^) fairygui::GGroup *value)
    self->setGroup(arg1);

    // inject code after call
    olua_addref(L, 1, "group", 2, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GObject_setHeight(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;
    lua_Number arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");
    olua_check_number(L, 2, &arg1);

    // void setHeight(float value)
    self->setHeight((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GObject_setIcon(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;
    std::string arg1;       /** text */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");
    olua_check_std_string(L, 2, &arg1);

    // void setIcon(const std::string &text)
    self->setIcon(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GObject_setPivot1(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;
    lua_Number arg1 = 0;       /** xv */
    lua_Number arg2 = 0;       /** yv */
    bool arg3 = false;       /** asAnchor */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_bool(L, 4, &arg3);

    // void setPivot(float xv, float yv, @optional bool asAnchor)
    self->setPivot((float)arg1, (float)arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GObject_setPivot2(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;
    lua_Number arg1 = 0;       /** xv */
    lua_Number arg2 = 0;       /** yv */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);

    // void setPivot(float xv, float yv, @optional bool asAnchor)
    self->setPivot((float)arg1, (float)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GObject_setPivot(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 2) {
        // if ((olua_is_number(L, 2)) && (olua_is_number(L, 3))) {
            // void setPivot(float xv, float yv, @optional bool asAnchor)
            return _fairygui_GObject_setPivot2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_number(L, 2)) && (olua_is_number(L, 3)) && (olua_is_bool(L, 4))) {
            // void setPivot(float xv, float yv, @optional bool asAnchor)
            return _fairygui_GObject_setPivot1(L);
        // }
    }

    luaL_error(L, "method 'fairygui::GObject::setPivot' not support '%d' arguments", num_args);

    return 0;
}

static int _fairygui_GObject_setPixelSnapping(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;
    bool arg1 = false;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");
    olua_check_bool(L, 2, &arg1);

    // void setPixelSnapping(bool value)
    self->setPixelSnapping(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GObject_setPosition(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;
    lua_Number arg1 = 0;       /** xv */
    lua_Number arg2 = 0;       /** yv */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);

    // void setPosition(float xv, float yv)
    self->setPosition((float)arg1, (float)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GObject_setProp(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;
    lua_Unsigned arg1 = 0;       /** propId */
    cocos2d::Value arg2;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");
    olua_check_uint(L, 2, &arg1);
    manual_olua_check_cocos2d_Value(L, 3, &arg2);

    // void setProp(fairygui::ObjectPropID propId, const cocos2d::Value &value)
    self->setProp((fairygui::ObjectPropID)arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GObject_setRotation(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;
    lua_Number arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");
    olua_check_number(L, 2, &arg1);

    // void setRotation(float value)
    self->setRotation((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GObject_setScale(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;
    lua_Number arg1 = 0;       /** xv */
    lua_Number arg2 = 0;       /** yv */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);

    // void setScale(float xv, float yv)
    self->setScale((float)arg1, (float)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GObject_setScaleX(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;
    lua_Number arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");
    olua_check_number(L, 2, &arg1);

    // void setScaleX(float value)
    self->setScaleX((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GObject_setScaleY(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;
    lua_Number arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");
    olua_check_number(L, 2, &arg1);

    // void setScaleY(float value)
    self->setScaleY((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GObject_setSize1(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;
    lua_Number arg1 = 0;       /** wv */
    lua_Number arg2 = 0;       /** hv */
    bool arg3 = false;       /** ignorePivot */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_bool(L, 4, &arg3);

    // void setSize(float wv, float hv, @optional bool ignorePivot)
    self->setSize((float)arg1, (float)arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GObject_setSize2(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;
    lua_Number arg1 = 0;       /** wv */
    lua_Number arg2 = 0;       /** hv */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);

    // void setSize(float wv, float hv, @optional bool ignorePivot)
    self->setSize((float)arg1, (float)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GObject_setSize(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 2) {
        // if ((olua_is_number(L, 2)) && (olua_is_number(L, 3))) {
            // void setSize(float wv, float hv, @optional bool ignorePivot)
            return _fairygui_GObject_setSize2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_number(L, 2)) && (olua_is_number(L, 3)) && (olua_is_bool(L, 4))) {
            // void setSize(float wv, float hv, @optional bool ignorePivot)
            return _fairygui_GObject_setSize1(L);
        // }
    }

    luaL_error(L, "method 'fairygui::GObject::setSize' not support '%d' arguments", num_args);

    return 0;
}

static int _fairygui_GObject_setSkewX(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;
    lua_Number arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");
    olua_check_number(L, 2, &arg1);

    // void setSkewX(float value)
    self->setSkewX((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GObject_setSkewY(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;
    lua_Number arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");
    olua_check_number(L, 2, &arg1);

    // void setSkewY(float value)
    self->setSkewY((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GObject_setSortingOrder(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");
    olua_check_int(L, 2, &arg1);

    // void setSortingOrder(int value)
    self->setSortingOrder((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GObject_setText(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;
    std::string arg1;       /** text */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");
    olua_check_std_string(L, 2, &arg1);

    // void setText(const std::string &text)
    self->setText(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GObject_setTooltips(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;
    std::string arg1;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");
    olua_check_std_string(L, 2, &arg1);

    // void setTooltips(const std::string &value)
    self->setTooltips(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GObject_setTouchable(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;
    bool arg1 = false;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");
    olua_check_bool(L, 2, &arg1);

    // void setTouchable(bool value)
    self->setTouchable(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GObject_setVisible(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;
    bool arg1 = false;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");
    olua_check_bool(L, 2, &arg1);

    // void setVisible(bool value)
    self->setVisible(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GObject_setWidth(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;
    lua_Number arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");
    olua_check_number(L, 2, &arg1);

    // void setWidth(float value)
    self->setWidth((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GObject_setX(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;
    lua_Number arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");
    olua_check_number(L, 2, &arg1);

    // void setX(float value)
    self->setX((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GObject_setXMin(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;
    lua_Number arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");
    olua_check_number(L, 2, &arg1);

    // void setXMin(float value)
    self->setXMin((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GObject_setY(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;
    lua_Number arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");
    olua_check_number(L, 2, &arg1);

    // void setY(float value)
    self->setY((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GObject_setYMin(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;
    lua_Number arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");
    olua_check_number(L, 2, &arg1);

    // void setYMin(float value)
    self->setYMin((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GObject_startDrag1(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;
    lua_Integer arg1 = 0;       /** touchId */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");
    olua_check_int(L, 2, &arg1);

    // void startDrag(@optional int touchId)
    self->startDrag((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GObject_startDrag2(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");

    // void startDrag(@optional int touchId)
    self->startDrag();

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GObject_startDrag(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // void startDrag(@optional int touchId)
        return _fairygui_GObject_startDrag2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_int(L, 2))) {
            // void startDrag(@optional int touchId)
            return _fairygui_GObject_startDrag1(L);
        // }
    }

    luaL_error(L, "method 'fairygui::GObject::startDrag' not support '%d' arguments", num_args);

    return 0;
}

static int _fairygui_GObject_stopDrag(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");

    // void stopDrag()
    self->stopDrag();

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GObject_transformRect1(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;
    cocos2d::Rect arg1;       /** rect */
    fairygui::GObject *arg2 = nullptr;       /** targetSpace */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");
    manual_olua_check_cocos2d_Rect(L, 2, &arg1);
    olua_check_cppobj(L, 3, (void **)&arg2, "fgui.GObject");

    // cocos2d::Rect transformRect(const cocos2d::Rect &rect, fairygui::GObject *targetSpace)
    cocos2d::Rect ret = (cocos2d::Rect)self->transformRect(arg1, arg2);
    int num_ret = manual_olua_push_cocos2d_Rect(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GObject_transformRect2(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;
    cocos2d::Rect arg1;       /** rect */
    fairygui::GObject *arg2 = nullptr;       /** targetSpace */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");
    manual_olua_pack_cocos2d_Rect(L, 2, &arg1);
    olua_check_cppobj(L, 6, (void **)&arg2, "fgui.GObject");

    // cocos2d::Rect transformRect(@pack const cocos2d::Rect &rect, fairygui::GObject *targetSpace)
    cocos2d::Rect ret = (cocos2d::Rect)self->transformRect(arg1, arg2);
    int num_ret = manual_olua_unpack_cocos2d_Rect(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GObject_transformRect(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 2) {
        // if ((manual_olua_is_cocos2d_Rect(L, 2)) && (olua_is_cppobj(L, 3, "fgui.GObject"))) {
            // cocos2d::Rect transformRect(const cocos2d::Rect &rect, fairygui::GObject *targetSpace)
            return _fairygui_GObject_transformRect1(L);
        // }
    }

    if (num_args == 5) {
        // if ((manual_olua_ispack_cocos2d_Rect(L, 2)) && (olua_is_cppobj(L, 3, "fgui.GObject"))) {
            // cocos2d::Rect transformRect(@pack const cocos2d::Rect &rect, fairygui::GObject *targetSpace)
            return _fairygui_GObject_transformRect2(L);
        // }
    }

    luaL_error(L, "method 'fairygui::GObject::transformRect' not support '%d' arguments", num_args);

    return 0;
}

static int _fairygui_GObject_treeNode(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");

    // fairygui::GTreeNode *treeNode()
    fairygui::GTreeNode *ret = (fairygui::GTreeNode *)self->treeNode();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GTreeNode");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GObject_get_id(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");

    // std::string id
    std::string ret = (std::string)self->id;
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GObject_set_id(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;
    std::string arg1;       /** id */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");
    olua_check_std_string(L, 2, &arg1);

    // std::string id
    self->id = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GObject_get_initSize(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");

    // cocos2d::Size initSize
    cocos2d::Size ret = (cocos2d::Size)self->initSize;
    int num_ret = auto_olua_push_cocos2d_Size(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GObject_set_initSize(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;
    cocos2d::Size arg1;       /** initSize */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");
    auto_olua_check_cocos2d_Size(L, 2, &arg1);

    // cocos2d::Size initSize
    self->initSize = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GObject_get_maxSize(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");

    // cocos2d::Size maxSize
    cocos2d::Size ret = (cocos2d::Size)self->maxSize;
    int num_ret = auto_olua_push_cocos2d_Size(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GObject_set_maxSize(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;
    cocos2d::Size arg1;       /** maxSize */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");
    auto_olua_check_cocos2d_Size(L, 2, &arg1);

    // cocos2d::Size maxSize
    self->maxSize = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GObject_get_minSize(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");

    // cocos2d::Size minSize
    cocos2d::Size ret = (cocos2d::Size)self->minSize;
    int num_ret = auto_olua_push_cocos2d_Size(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GObject_set_minSize(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;
    cocos2d::Size arg1;       /** minSize */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");
    auto_olua_check_cocos2d_Size(L, 2, &arg1);

    // cocos2d::Size minSize
    self->minSize = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GObject_get_name(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");

    // std::string name
    std::string ret = (std::string)self->name;
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GObject_set_name(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;
    std::string arg1;       /** name */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");
    olua_check_std_string(L, 2, &arg1);

    // std::string name
    self->name = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GObject_get_sourceSize(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");

    // cocos2d::Size sourceSize
    cocos2d::Size ret = (cocos2d::Size)self->sourceSize;
    int num_ret = auto_olua_push_cocos2d_Size(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GObject_set_sourceSize(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *self = nullptr;
    cocos2d::Size arg1;       /** sourceSize */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GObject");
    auto_olua_check_cocos2d_Size(L, 2, &arg1);

    // cocos2d::Size sourceSize
    self->sourceSize = arg1;

    olua_endinvoke(L);

    return 0;
}

static int luaopen_fairygui_GObject(lua_State *L)
{
    oluacls_class(L, "fgui.GObject", "fgui.UIEventDispatcher");
    oluacls_func(L, "__move", _fairygui_GObject___move);
    oluacls_func(L, "addClickListener", _fairygui_GObject_addClickListener);
    oluacls_func(L, "addDisplayLock", _fairygui_GObject_addDisplayLock);
    oluacls_func(L, "addRelation", _fairygui_GObject_addRelation);
    oluacls_func(L, "center", _fairygui_GObject_center);
    oluacls_func(L, "checkGearController", _fairygui_GObject_checkGearController);
    oluacls_func(L, "create", _fairygui_GObject_create);
    oluacls_func(L, "displayObject", _fairygui_GObject_displayObject);
    oluacls_func(L, "findParent", _fairygui_GObject_findParent);
    oluacls_func(L, "getAlpha", _fairygui_GObject_getAlpha);
    oluacls_func(L, "getCustomData", _fairygui_GObject_getCustomData);
    oluacls_func(L, "getData", _fairygui_GObject_getData);
    oluacls_func(L, "getDragBounds", _fairygui_GObject_getDragBounds);
    oluacls_func(L, "getDraggingObject", _fairygui_GObject_getDraggingObject);
    oluacls_func(L, "getGear", _fairygui_GObject_getGear);
    oluacls_func(L, "getGroup", _fairygui_GObject_getGroup);
    oluacls_func(L, "getHeight", _fairygui_GObject_getHeight);
    oluacls_func(L, "getIcon", _fairygui_GObject_getIcon);
    oluacls_func(L, "getPackageItem", _fairygui_GObject_getPackageItem);
    oluacls_func(L, "getParent", _fairygui_GObject_getParent);
    oluacls_func(L, "getPivot", _fairygui_GObject_getPivot);
    oluacls_func(L, "getPosition", _fairygui_GObject_getPosition);
    oluacls_func(L, "getProp", _fairygui_GObject_getProp);
    oluacls_func(L, "getResourceURL", _fairygui_GObject_getResourceURL);
    oluacls_func(L, "getRoot", _fairygui_GObject_getRoot);
    oluacls_func(L, "getRotation", _fairygui_GObject_getRotation);
    oluacls_func(L, "getScale", _fairygui_GObject_getScale);
    oluacls_func(L, "getScaleX", _fairygui_GObject_getScaleX);
    oluacls_func(L, "getScaleY", _fairygui_GObject_getScaleY);
    oluacls_func(L, "getSize", _fairygui_GObject_getSize);
    oluacls_func(L, "getSkewX", _fairygui_GObject_getSkewX);
    oluacls_func(L, "getSkewY", _fairygui_GObject_getSkewY);
    oluacls_func(L, "getSortingOrder", _fairygui_GObject_getSortingOrder);
    oluacls_func(L, "getText", _fairygui_GObject_getText);
    oluacls_func(L, "getTooltips", _fairygui_GObject_getTooltips);
    oluacls_func(L, "getWidth", _fairygui_GObject_getWidth);
    oluacls_func(L, "getX", _fairygui_GObject_getX);
    oluacls_func(L, "getXMin", _fairygui_GObject_getXMin);
    oluacls_func(L, "getY", _fairygui_GObject_getY);
    oluacls_func(L, "getYMin", _fairygui_GObject_getYMin);
    oluacls_func(L, "globalToLocal", _fairygui_GObject_globalToLocal);
    oluacls_func(L, "hitTest", _fairygui_GObject_hitTest);
    oluacls_func(L, "isDraggable", _fairygui_GObject_isDraggable);
    oluacls_func(L, "isGrayed", _fairygui_GObject_isGrayed);
    oluacls_func(L, "isPivotAsAnchor", _fairygui_GObject_isPivotAsAnchor);
    oluacls_func(L, "isPixelSnapping", _fairygui_GObject_isPixelSnapping);
    oluacls_func(L, "isTouchable", _fairygui_GObject_isTouchable);
    oluacls_func(L, "isVisible", _fairygui_GObject_isVisible);
    oluacls_func(L, "localToGlobal", _fairygui_GObject_localToGlobal);
    oluacls_func(L, "makeFullScreen", _fairygui_GObject_makeFullScreen);
    oluacls_func(L, "new", _fairygui_GObject_new);
    oluacls_func(L, "onStage", _fairygui_GObject_onStage);
    oluacls_func(L, "relations", _fairygui_GObject_relations);
    oluacls_func(L, "releaseDisplayLock", _fairygui_GObject_releaseDisplayLock);
    oluacls_func(L, "removeClickListener", _fairygui_GObject_removeClickListener);
    oluacls_func(L, "removeFromParent", _fairygui_GObject_removeFromParent);
    oluacls_func(L, "removeRelation", _fairygui_GObject_removeRelation);
    oluacls_func(L, "setAlpha", _fairygui_GObject_setAlpha);
    oluacls_func(L, "setCustomData", _fairygui_GObject_setCustomData);
    oluacls_func(L, "setData", _fairygui_GObject_setData);
    oluacls_func(L, "setDragBounds", _fairygui_GObject_setDragBounds);
    oluacls_func(L, "setDraggable", _fairygui_GObject_setDraggable);
    oluacls_func(L, "setGrayed", _fairygui_GObject_setGrayed);
    oluacls_func(L, "setGroup", _fairygui_GObject_setGroup);
    oluacls_func(L, "setHeight", _fairygui_GObject_setHeight);
    oluacls_func(L, "setIcon", _fairygui_GObject_setIcon);
    oluacls_func(L, "setPivot", _fairygui_GObject_setPivot);
    oluacls_func(L, "setPixelSnapping", _fairygui_GObject_setPixelSnapping);
    oluacls_func(L, "setPosition", _fairygui_GObject_setPosition);
    oluacls_func(L, "setProp", _fairygui_GObject_setProp);
    oluacls_func(L, "setRotation", _fairygui_GObject_setRotation);
    oluacls_func(L, "setScale", _fairygui_GObject_setScale);
    oluacls_func(L, "setScaleX", _fairygui_GObject_setScaleX);
    oluacls_func(L, "setScaleY", _fairygui_GObject_setScaleY);
    oluacls_func(L, "setSize", _fairygui_GObject_setSize);
    oluacls_func(L, "setSkewX", _fairygui_GObject_setSkewX);
    oluacls_func(L, "setSkewY", _fairygui_GObject_setSkewY);
    oluacls_func(L, "setSortingOrder", _fairygui_GObject_setSortingOrder);
    oluacls_func(L, "setText", _fairygui_GObject_setText);
    oluacls_func(L, "setTooltips", _fairygui_GObject_setTooltips);
    oluacls_func(L, "setTouchable", _fairygui_GObject_setTouchable);
    oluacls_func(L, "setVisible", _fairygui_GObject_setVisible);
    oluacls_func(L, "setWidth", _fairygui_GObject_setWidth);
    oluacls_func(L, "setX", _fairygui_GObject_setX);
    oluacls_func(L, "setXMin", _fairygui_GObject_setXMin);
    oluacls_func(L, "setY", _fairygui_GObject_setY);
    oluacls_func(L, "setYMin", _fairygui_GObject_setYMin);
    oluacls_func(L, "startDrag", _fairygui_GObject_startDrag);
    oluacls_func(L, "stopDrag", _fairygui_GObject_stopDrag);
    oluacls_func(L, "transformRect", _fairygui_GObject_transformRect);
    oluacls_func(L, "treeNode", _fairygui_GObject_treeNode);
    oluacls_prop(L, "alpha", _fairygui_GObject_getAlpha, _fairygui_GObject_setAlpha);
    oluacls_prop(L, "customData", _fairygui_GObject_getCustomData, _fairygui_GObject_setCustomData);
    oluacls_prop(L, "data", _fairygui_GObject_getData, _fairygui_GObject_setData);
    oluacls_prop(L, "displayObject", _fairygui_GObject_displayObject, nullptr);
    oluacls_prop(L, "draggable", _fairygui_GObject_isDraggable, _fairygui_GObject_setDraggable);
    oluacls_prop(L, "draggingObject", _fairygui_GObject_getDraggingObject, nullptr);
    oluacls_prop(L, "grayed", _fairygui_GObject_isGrayed, _fairygui_GObject_setGrayed);
    oluacls_prop(L, "group", _fairygui_GObject_getGroup, _fairygui_GObject_setGroup);
    oluacls_prop(L, "height", _fairygui_GObject_getHeight, _fairygui_GObject_setHeight);
    oluacls_prop(L, "icon", _fairygui_GObject_getIcon, _fairygui_GObject_setIcon);
    oluacls_prop(L, "packageItem", _fairygui_GObject_getPackageItem, nullptr);
    oluacls_prop(L, "parent", _fairygui_GObject_getParent, nullptr);
    oluacls_prop(L, "pivot", _fairygui_GObject_getPivot, _fairygui_GObject_setPivot);
    oluacls_prop(L, "pivotAsAnchor", _fairygui_GObject_isPivotAsAnchor, nullptr);
    oluacls_prop(L, "pixelSnapping", _fairygui_GObject_isPixelSnapping, _fairygui_GObject_setPixelSnapping);
    oluacls_prop(L, "position", _fairygui_GObject_getPosition, _fairygui_GObject_setPosition);
    oluacls_prop(L, "relations", _fairygui_GObject_relations, nullptr);
    oluacls_prop(L, "resourceURL", _fairygui_GObject_getResourceURL, nullptr);
    oluacls_prop(L, "root", _fairygui_GObject_getRoot, nullptr);
    oluacls_prop(L, "rotation", _fairygui_GObject_getRotation, _fairygui_GObject_setRotation);
    oluacls_prop(L, "scale", _fairygui_GObject_getScale, _fairygui_GObject_setScale);
    oluacls_prop(L, "scaleX", _fairygui_GObject_getScaleX, _fairygui_GObject_setScaleX);
    oluacls_prop(L, "scaleY", _fairygui_GObject_getScaleY, _fairygui_GObject_setScaleY);
    oluacls_prop(L, "size", _fairygui_GObject_getSize, _fairygui_GObject_setSize);
    oluacls_prop(L, "skewX", _fairygui_GObject_getSkewX, _fairygui_GObject_setSkewX);
    oluacls_prop(L, "skewY", _fairygui_GObject_getSkewY, _fairygui_GObject_setSkewY);
    oluacls_prop(L, "sortingOrder", _fairygui_GObject_getSortingOrder, _fairygui_GObject_setSortingOrder);
    oluacls_prop(L, "text", _fairygui_GObject_getText, _fairygui_GObject_setText);
    oluacls_prop(L, "tooltips", _fairygui_GObject_getTooltips, _fairygui_GObject_setTooltips);
    oluacls_prop(L, "touchable", _fairygui_GObject_isTouchable, _fairygui_GObject_setTouchable);
    oluacls_prop(L, "visible", _fairygui_GObject_isVisible, _fairygui_GObject_setVisible);
    oluacls_prop(L, "width", _fairygui_GObject_getWidth, _fairygui_GObject_setWidth);
    oluacls_prop(L, "x", _fairygui_GObject_getX, _fairygui_GObject_setX);
    oluacls_prop(L, "xMin", _fairygui_GObject_getXMin, _fairygui_GObject_setXMin);
    oluacls_prop(L, "y", _fairygui_GObject_getY, _fairygui_GObject_setY);
    oluacls_prop(L, "yMin", _fairygui_GObject_getYMin, _fairygui_GObject_setYMin);
    oluacls_prop(L, "id", _fairygui_GObject_get_id, _fairygui_GObject_set_id);
    oluacls_prop(L, "initSize", _fairygui_GObject_get_initSize, _fairygui_GObject_set_initSize);
    oluacls_prop(L, "maxSize", _fairygui_GObject_get_maxSize, _fairygui_GObject_set_maxSize);
    oluacls_prop(L, "minSize", _fairygui_GObject_get_minSize, _fairygui_GObject_set_minSize);
    oluacls_prop(L, "name", _fairygui_GObject_get_name, _fairygui_GObject_set_name);
    oluacls_prop(L, "sourceSize", _fairygui_GObject_get_sourceSize, _fairygui_GObject_set_sourceSize);

    olua_registerluatype<fairygui::GObject>(L, "fgui.GObject");

    return 1;
}

static int _fairygui_GComponent___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (fairygui::GComponent *)olua_toobj(L, 1, "fgui.GComponent");
    olua_push_cppobj(L, self, "fgui.GComponent");

    olua_endinvoke(L);

    return 1;
}

static int _fairygui_GComponent_addChild(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComponent *self = nullptr;
    fairygui::GObject *arg1 = nullptr;       /** child */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GComponent");
    olua_check_cppobj(L, 2, (void **)&arg1, "fgui.GObject");

    // fairygui::GObject *addChild(@addref(children |) fairygui::GObject *child)
    fairygui::GObject *ret = (fairygui::GObject *)self->addChild(arg1);
    int num_ret = olua_push_cppobj(L, ret, "fgui.GObject");

    // inject code after call
    olua_addref(L, 1, "children", 2, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GComponent_addChildAt(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComponent *self = nullptr;
    fairygui::GObject *arg1 = nullptr;       /** child */
    lua_Integer arg2 = 0;       /** index */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GComponent");
    olua_check_cppobj(L, 2, (void **)&arg1, "fgui.GObject");
    olua_check_int(L, 3, &arg2);

    // fairygui::GObject *addChildAt(@addref(children |) fairygui::GObject *child, int index)
    fairygui::GObject *ret = (fairygui::GObject *)self->addChildAt(arg1, (int)arg2);
    int num_ret = olua_push_cppobj(L, ret, "fgui.GObject");

    // inject code after call
    olua_addref(L, 1, "children", 2, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GComponent_addController(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComponent *self = nullptr;
    fairygui::GController *arg1 = nullptr;       /** c */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GComponent");
    olua_check_cppobj(L, 2, (void **)&arg1, "fgui.GController");

    // void addController(@addref(controllers |) fairygui::GController *c)
    self->addController(arg1);

    // inject code after call
    olua_addref(L, 1, "controllers", 2, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GComponent_adjustRadioGroupDepth(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComponent *self = nullptr;
    fairygui::GObject *arg1 = nullptr;       /** obj */
    fairygui::GController *arg2 = nullptr;       /** c */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GComponent");
    olua_check_cppobj(L, 2, (void **)&arg1, "fgui.GObject");
    olua_check_cppobj(L, 3, (void **)&arg2, "fgui.GController");

    // void adjustRadioGroupDepth(fairygui::GObject *obj, fairygui::GController *c)
    self->adjustRadioGroupDepth(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GComponent_applyAllControllers(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComponent *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GComponent");

    // void applyAllControllers()
    self->applyAllControllers();

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GComponent_applyController(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComponent *self = nullptr;
    fairygui::GController *arg1 = nullptr;       /** c */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GComponent");
    olua_check_cppobj(L, 2, (void **)&arg1, "fgui.GController");

    // void applyController(fairygui::GController *c)
    self->applyController(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GComponent_childSortingOrderChanged(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComponent *self = nullptr;
    fairygui::GObject *arg1 = nullptr;       /** child */
    lua_Integer arg2 = 0;       /** oldValue */
    lua_Integer arg3 = 0;       /** newValue */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GComponent");
    olua_check_cppobj(L, 2, (void **)&arg1, "fgui.GObject");
    olua_check_int(L, 3, &arg2);
    olua_check_int(L, 4, &arg3);

    // void childSortingOrderChanged(fairygui::GObject *child, int oldValue, int newValue)
    self->childSortingOrderChanged(arg1, (int)arg2, (int)arg3);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GComponent_childStateChanged(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComponent *self = nullptr;
    fairygui::GObject *arg1 = nullptr;       /** child */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GComponent");
    olua_check_cppobj(L, 2, (void **)&arg1, "fgui.GObject");

    // void childStateChanged(fairygui::GObject *child)
    self->childStateChanged(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GComponent_create(lua_State *L)
{
    olua_startinvoke(L);

    // static fairygui::GComponent *create()
    fairygui::GComponent *ret = (fairygui::GComponent *)fairygui::GComponent::create();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GComponent");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GComponent_ensureBoundsCorrect(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComponent *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GComponent");

    // void ensureBoundsCorrect()
    self->ensureBoundsCorrect();

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GComponent_getApexIndex(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComponent *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GComponent");

    // int getApexIndex()
    int ret = (int)self->getApexIndex();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GComponent_getChild(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComponent *self = nullptr;
    std::string arg1;       /** name */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GComponent");
    olua_check_std_string(L, 2, &arg1);

    // @addref(children |) fairygui::GObject *getChild(const std::string &name)
    fairygui::GObject *ret = (fairygui::GObject *)self->getChild(arg1);
    int num_ret = olua_push_cppobj(L, ret, "fgui.GObject");

    // inject code after call
    olua_addref(L, 1, "children", -1, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GComponent_getChildAt(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComponent *self = nullptr;
    lua_Integer arg1 = 0;       /** index */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GComponent");
    olua_check_int(L, 2, &arg1);

    // @addref(children |) fairygui::GObject *getChildAt(int index)
    fairygui::GObject *ret = (fairygui::GObject *)self->getChildAt((int)arg1);
    int num_ret = olua_push_cppobj(L, ret, "fgui.GObject");

    // inject code after call
    olua_addref(L, 1, "children", -1, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GComponent_getChildById(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComponent *self = nullptr;
    std::string arg1;       /** id */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GComponent");
    olua_check_std_string(L, 2, &arg1);

    // @addref(children |) fairygui::GObject *getChildById(const std::string &id)
    fairygui::GObject *ret = (fairygui::GObject *)self->getChildById(arg1);
    int num_ret = olua_push_cppobj(L, ret, "fgui.GObject");

    // inject code after call
    olua_addref(L, 1, "children", -1, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GComponent_getChildByPath(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComponent *self = nullptr;
    std::string arg1;       /** path */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GComponent");
    olua_check_std_string(L, 2, &arg1);

    // fairygui::GObject *getChildByPath(const std::string &path)
    fairygui::GObject *ret = (fairygui::GObject *)self->getChildByPath(arg1);
    int num_ret = olua_push_cppobj(L, ret, "fgui.GObject");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GComponent_getChildInGroup(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComponent *self = nullptr;
    fairygui::GGroup *arg1 = nullptr;       /** group */
    std::string arg2;       /** name */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GComponent");
    olua_check_cppobj(L, 2, (void **)&arg1, "fgui.GGroup");
    olua_check_std_string(L, 3, &arg2);

    // @addref(children |) fairygui::GObject *getChildInGroup(const fairygui::GGroup *group, const std::string &name)
    fairygui::GObject *ret = (fairygui::GObject *)self->getChildInGroup(arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "fgui.GObject");

    // inject code after call
    olua_addref(L, 1, "children", -1, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GComponent_getChildIndex(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComponent *self = nullptr;
    fairygui::GObject *arg1 = nullptr;       /** child */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GComponent");
    olua_check_cppobj(L, 2, (void **)&arg1, "fgui.GObject");

    // int getChildIndex(const fairygui::GObject *child)
    int ret = (int)self->getChildIndex(arg1);
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GComponent_getChildren(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComponent *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GComponent");

    // @addref(children |) const cocos2d::Vector<GObject *> &getChildren()
    const cocos2d::Vector<fairygui::GObject *> &ret = (const cocos2d::Vector<fairygui::GObject *> &)self->getChildren();
    int num_ret = manual_olua_push_cocos2d_Vector(L, ret, "fgui.GObject");

    // inject code after call
    olua_addref(L, 1, "children", -1, OLUA_MODE_MULTIPLE | OLUA_FLAG_ARRAY);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GComponent_getChildrenRenderOrder(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComponent *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GComponent");

    // fairygui::ChildrenRenderOrder getChildrenRenderOrder()
    fairygui::ChildrenRenderOrder ret = (fairygui::ChildrenRenderOrder)self->getChildrenRenderOrder();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GComponent_getController(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComponent *self = nullptr;
    std::string arg1;       /** name */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GComponent");
    olua_check_std_string(L, 2, &arg1);

    // @addref(controllers |) fairygui::GController *getController(const std::string &name)
    fairygui::GController *ret = (fairygui::GController *)self->getController(arg1);
    int num_ret = olua_push_cppobj(L, ret, "fgui.GController");

    // inject code after call
    olua_addref(L, 1, "controllers", -1, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GComponent_getControllerAt(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComponent *self = nullptr;
    lua_Integer arg1 = 0;       /** index */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GComponent");
    olua_check_int(L, 2, &arg1);

    // @addref(controllers |) fairygui::GController *getControllerAt(int index)
    fairygui::GController *ret = (fairygui::GController *)self->getControllerAt((int)arg1);
    int num_ret = olua_push_cppobj(L, ret, "fgui.GController");

    // inject code after call
    olua_addref(L, 1, "controllers", -1, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GComponent_getControllers(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComponent *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GComponent");

    // @addref(controllers |) const cocos2d::Vector<GController *> &getControllers()
    const cocos2d::Vector<fairygui::GController *> &ret = (const cocos2d::Vector<fairygui::GController *> &)self->getControllers();
    int num_ret = manual_olua_push_cocos2d_Vector(L, ret, "fgui.GController");

    // inject code after call
    olua_addref(L, 1, "controllers", -1, OLUA_MODE_MULTIPLE | OLUA_FLAG_ARRAY);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GComponent_getFirstChildInView(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComponent *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GComponent");

    // int getFirstChildInView()
    int ret = (int)self->getFirstChildInView();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GComponent_getHitArea(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComponent *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GComponent");

    // fairygui::IHitTest *getHitArea()
    fairygui::IHitTest *ret = (fairygui::IHitTest *)self->getHitArea();
    int num_ret = olua_push_cppobj(L, ret, "fgui.IHitTest");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GComponent_getMargin(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComponent *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GComponent");

    // const fairygui::Margin &getMargin()
    const fairygui::Margin &ret = (const fairygui::Margin &)self->getMargin();
    int num_ret = auto_olua_push_fairygui_Margin(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GComponent_getMask(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComponent *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GComponent");

    // @addref(mask ^) cocos2d::Node *getMask()
    cocos2d::Node *ret = (cocos2d::Node *)self->getMask();
    int num_ret = olua_push_cppobj(L, ret, "cc.Node");

    // inject code after call
    olua_addref(L, 1, "mask", -1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GComponent_getOpaque(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComponent *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GComponent");

    // bool getOpaque()
    bool ret = (bool)self->getOpaque();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GComponent_getScrollPane(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComponent *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GComponent");

    // fairygui::ScrollPane *getScrollPane()
    fairygui::ScrollPane *ret = (fairygui::ScrollPane *)self->getScrollPane();
    int num_ret = olua_push_cppobj(L, ret, "fgui.ScrollPane");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GComponent_getSnappingPosition(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComponent *self = nullptr;
    cocos2d::Vec2 arg1;       /** pt */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GComponent");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);

    // cocos2d::Vec2 getSnappingPosition(const cocos2d::Vec2 &pt)
    cocos2d::Vec2 ret = (cocos2d::Vec2)self->getSnappingPosition(arg1);
    int num_ret = auto_olua_push_cocos2d_Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GComponent_getTransition(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComponent *self = nullptr;
    std::string arg1;       /** name */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GComponent");
    olua_check_std_string(L, 2, &arg1);

    // @addref(transitions |) fairygui::Transition *getTransition(const std::string &name)
    fairygui::Transition *ret = (fairygui::Transition *)self->getTransition(arg1);
    int num_ret = olua_push_cppobj(L, ret, "fgui.Transition");

    // inject code after call
    olua_addref(L, 1, "transitions", -1, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GComponent_getTransitionAt(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComponent *self = nullptr;
    lua_Integer arg1 = 0;       /** index */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GComponent");
    olua_check_int(L, 2, &arg1);

    // @addref(transitions |) fairygui::Transition *getTransitionAt(int index)
    fairygui::Transition *ret = (fairygui::Transition *)self->getTransitionAt((int)arg1);
    int num_ret = olua_push_cppobj(L, ret, "fgui.Transition");

    // inject code after call
    olua_addref(L, 1, "transitions", -1, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GComponent_getTransitions(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComponent *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GComponent");

    // @addref(transitions |) const cocos2d::Vector<Transition *> &getTransitions()
    const cocos2d::Vector<fairygui::Transition *> &ret = (const cocos2d::Vector<fairygui::Transition *> &)self->getTransitions();
    int num_ret = manual_olua_push_cocos2d_Vector(L, ret, "fgui.Transition");

    // inject code after call
    olua_addref(L, 1, "transitions", -1, OLUA_MODE_MULTIPLE | OLUA_FLAG_ARRAY);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GComponent_getViewHeight(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComponent *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GComponent");

    // float getViewHeight()
    float ret = (float)self->getViewHeight();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GComponent_getViewWidth(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComponent *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GComponent");

    // float getViewWidth()
    float ret = (float)self->getViewWidth();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GComponent_isAncestorOf(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComponent *self = nullptr;
    fairygui::GObject *arg1 = nullptr;       /** obj */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GComponent");
    olua_check_cppobj(L, 2, (void **)&arg1, "fgui.GObject");

    // bool isAncestorOf(const fairygui::GObject *obj)
    bool ret = (bool)self->isAncestorOf(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GComponent_isChildInView(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComponent *self = nullptr;
    fairygui::GObject *arg1 = nullptr;       /** child */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GComponent");
    olua_check_cppobj(L, 2, (void **)&arg1, "fgui.GObject");

    // bool isChildInView(fairygui::GObject *child)
    bool ret = (bool)self->isChildInView(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GComponent_new(lua_State *L)
{
    olua_startinvoke(L);

    // GComponent()
    fairygui::GComponent *ret = (fairygui::GComponent *)new fairygui::GComponent();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GComponent");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GComponent_numChildren(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComponent *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GComponent");

    // int numChildren()
    int ret = (int)self->numChildren();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GComponent_removeChild(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComponent *self = nullptr;
    fairygui::GObject *arg1 = nullptr;       /** child */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GComponent");
    olua_check_cppobj(L, 2, (void **)&arg1, "fgui.GObject");

    // void removeChild(@delref(children |) fairygui::GObject *child)
    self->removeChild(arg1);

    // inject code after call
    olua_delref(L, 1, "children", 2, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GComponent_removeChildAt(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComponent *self = nullptr;
    lua_Integer arg1 = 0;       /** index */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GComponent");
    olua_check_int(L, 2, &arg1);

    // inject code before call
    olua_startcmpdelref(L, 1, "children");

    // @delref(children ~) void removeChildAt(int index)
    self->removeChildAt((int)arg1);

    // inject code after call
    olua_endcmpdelref(L, 1, "children");

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GComponent_removeChildren1(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComponent *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GComponent");

    // inject code before call
    olua_startcmpdelref(L, 1, "children");

    // @delref(children ~) void removeChildren()
    self->removeChildren();

    // inject code after call
    olua_endcmpdelref(L, 1, "children");

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GComponent_removeChildren2(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComponent *self = nullptr;
    lua_Integer arg1 = 0;       /** beginIndex */
    lua_Integer arg2 = 0;       /** endIndex */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GComponent");
    olua_check_int(L, 2, &arg1);
    olua_check_int(L, 3, &arg2);

    // inject code before call
    olua_startcmpdelref(L, 1, "children");

    // @delref(children ~) void removeChildren(int beginIndex, int endIndex)
    self->removeChildren((int)arg1, (int)arg2);

    // inject code after call
    olua_endcmpdelref(L, 1, "children");

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GComponent_removeChildren(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // @delref(children ~) void removeChildren()
        return _fairygui_GComponent_removeChildren1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_int(L, 2)) && (olua_is_int(L, 3))) {
            // @delref(children ~) void removeChildren(int beginIndex, int endIndex)
            return _fairygui_GComponent_removeChildren2(L);
        // }
    }

    luaL_error(L, "method 'fairygui::GComponent::removeChildren' not support '%d' arguments", num_args);

    return 0;
}

static int _fairygui_GComponent_removeController(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComponent *self = nullptr;
    fairygui::GController *arg1 = nullptr;       /** c */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GComponent");
    olua_check_cppobj(L, 2, (void **)&arg1, "fgui.GController");

    // void removeController(@delref(controllers |) fairygui::GController *c)
    self->removeController(arg1);

    // inject code after call
    olua_delref(L, 1, "controllers", 2, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GComponent_resolve(lua_State *L)
{
    olua_startinvoke(L);

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

            if (olua_isa<fairygui::GComponent>(L, -1)) {
                self = olua_toobj<fairygui::GComponent>(L, -1);
            } else {
                olua_endinvoke(L);

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

            olua_endinvoke(L);

            return 1;
        }
    }

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GComponent_setApexIndex(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComponent *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GComponent");
    olua_check_int(L, 2, &arg1);

    // void setApexIndex(int value)
    self->setApexIndex((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GComponent_setBoundsChangedFlag(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComponent *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GComponent");

    // void setBoundsChangedFlag()
    self->setBoundsChangedFlag();

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GComponent_setChildIndex(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComponent *self = nullptr;
    fairygui::GObject *arg1 = nullptr;       /** child */
    lua_Integer arg2 = 0;       /** index */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GComponent");
    olua_check_cppobj(L, 2, (void **)&arg1, "fgui.GObject");
    olua_check_int(L, 3, &arg2);

    // void setChildIndex(fairygui::GObject *child, int index)
    self->setChildIndex(arg1, (int)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GComponent_setChildIndexBefore(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComponent *self = nullptr;
    fairygui::GObject *arg1 = nullptr;       /** child */
    lua_Integer arg2 = 0;       /** index */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GComponent");
    olua_check_cppobj(L, 2, (void **)&arg1, "fgui.GObject");
    olua_check_int(L, 3, &arg2);

    // int setChildIndexBefore(fairygui::GObject *child, int index)
    int ret = (int)self->setChildIndexBefore(arg1, (int)arg2);
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GComponent_setChildrenRenderOrder(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComponent *self = nullptr;
    lua_Unsigned arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GComponent");
    olua_check_uint(L, 2, &arg1);

    // void setChildrenRenderOrder(fairygui::ChildrenRenderOrder value)
    self->setChildrenRenderOrder((fairygui::ChildrenRenderOrder)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GComponent_setHitArea(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComponent *self = nullptr;
    fairygui::IHitTest *arg1 = nullptr;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GComponent");
    olua_check_cppobj(L, 2, (void **)&arg1, "fgui.IHitTest");

    // void setHitArea(fairygui::IHitTest *value)
    self->setHitArea(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GComponent_setMargin(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComponent *self = nullptr;
    fairygui::Margin arg1;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GComponent");
    auto_olua_check_fairygui_Margin(L, 2, &arg1);

    // void setMargin(const fairygui::Margin &value)
    self->setMargin(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GComponent_setMask1(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComponent *self = nullptr;
    cocos2d::Node *arg1 = nullptr;       /** value */
    bool arg2 = false;       /** inverted */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GComponent");
    olua_check_cppobj(L, 2, (void **)&arg1, "cc.Node");
    olua_check_bool(L, 3, &arg2);

    // void setMask(@addref(mask ^) cocos2d::Node *value, @optional bool inverted)
    self->setMask(arg1, arg2);

    // inject code after call
    olua_addref(L, 1, "mask", 2, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GComponent_setMask2(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComponent *self = nullptr;
    cocos2d::Node *arg1 = nullptr;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GComponent");
    olua_check_cppobj(L, 2, (void **)&arg1, "cc.Node");

    // void setMask(@addref(mask ^) cocos2d::Node *value, @optional bool inverted)
    self->setMask(arg1);

    // inject code after call
    olua_addref(L, 1, "mask", 2, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GComponent_setMask(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_cppobj(L, 2, "cc.Node"))) {
            // void setMask(@addref(mask ^) cocos2d::Node *value, @optional bool inverted)
            return _fairygui_GComponent_setMask2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_cppobj(L, 2, "cc.Node")) && (olua_is_bool(L, 3))) {
            // void setMask(@addref(mask ^) cocos2d::Node *value, @optional bool inverted)
            return _fairygui_GComponent_setMask1(L);
        // }
    }

    luaL_error(L, "method 'fairygui::GComponent::setMask' not support '%d' arguments", num_args);

    return 0;
}

static int _fairygui_GComponent_setOpaque(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComponent *self = nullptr;
    bool arg1 = false;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GComponent");
    olua_check_bool(L, 2, &arg1);

    // void setOpaque(bool value)
    self->setOpaque(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GComponent_setViewHeight(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComponent *self = nullptr;
    lua_Number arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GComponent");
    olua_check_number(L, 2, &arg1);

    // void setViewHeight(float value)
    self->setViewHeight((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GComponent_setViewWidth(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComponent *self = nullptr;
    lua_Number arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GComponent");
    olua_check_number(L, 2, &arg1);

    // void setViewWidth(float value)
    self->setViewWidth((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GComponent_swapChildren(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComponent *self = nullptr;
    fairygui::GObject *arg1 = nullptr;       /** child1 */
    fairygui::GObject *arg2 = nullptr;       /** child2 */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GComponent");
    olua_check_cppobj(L, 2, (void **)&arg1, "fgui.GObject");
    olua_check_cppobj(L, 3, (void **)&arg2, "fgui.GObject");

    // void swapChildren(fairygui::GObject *child1, fairygui::GObject *child2)
    self->swapChildren(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GComponent_swapChildrenAt(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComponent *self = nullptr;
    lua_Integer arg1 = 0;       /** index1 */
    lua_Integer arg2 = 0;       /** index2 */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GComponent");
    olua_check_int(L, 2, &arg1);
    olua_check_int(L, 3, &arg2);

    // void swapChildrenAt(int index1, int index2)
    self->swapChildrenAt((int)arg1, (int)arg2);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_fairygui_GComponent(lua_State *L)
{
    oluacls_class(L, "fgui.GComponent", "fgui.GObject");
    oluacls_func(L, "__move", _fairygui_GComponent___move);
    oluacls_func(L, "addChild", _fairygui_GComponent_addChild);
    oluacls_func(L, "addChildAt", _fairygui_GComponent_addChildAt);
    oluacls_func(L, "addController", _fairygui_GComponent_addController);
    oluacls_func(L, "adjustRadioGroupDepth", _fairygui_GComponent_adjustRadioGroupDepth);
    oluacls_func(L, "applyAllControllers", _fairygui_GComponent_applyAllControllers);
    oluacls_func(L, "applyController", _fairygui_GComponent_applyController);
    oluacls_func(L, "childSortingOrderChanged", _fairygui_GComponent_childSortingOrderChanged);
    oluacls_func(L, "childStateChanged", _fairygui_GComponent_childStateChanged);
    oluacls_func(L, "create", _fairygui_GComponent_create);
    oluacls_func(L, "ensureBoundsCorrect", _fairygui_GComponent_ensureBoundsCorrect);
    oluacls_func(L, "getApexIndex", _fairygui_GComponent_getApexIndex);
    oluacls_func(L, "getChild", _fairygui_GComponent_getChild);
    oluacls_func(L, "getChildAt", _fairygui_GComponent_getChildAt);
    oluacls_func(L, "getChildById", _fairygui_GComponent_getChildById);
    oluacls_func(L, "getChildByPath", _fairygui_GComponent_getChildByPath);
    oluacls_func(L, "getChildInGroup", _fairygui_GComponent_getChildInGroup);
    oluacls_func(L, "getChildIndex", _fairygui_GComponent_getChildIndex);
    oluacls_func(L, "getChildren", _fairygui_GComponent_getChildren);
    oluacls_func(L, "getChildrenRenderOrder", _fairygui_GComponent_getChildrenRenderOrder);
    oluacls_func(L, "getController", _fairygui_GComponent_getController);
    oluacls_func(L, "getControllerAt", _fairygui_GComponent_getControllerAt);
    oluacls_func(L, "getControllers", _fairygui_GComponent_getControllers);
    oluacls_func(L, "getFirstChildInView", _fairygui_GComponent_getFirstChildInView);
    oluacls_func(L, "getHitArea", _fairygui_GComponent_getHitArea);
    oluacls_func(L, "getMargin", _fairygui_GComponent_getMargin);
    oluacls_func(L, "getMask", _fairygui_GComponent_getMask);
    oluacls_func(L, "getOpaque", _fairygui_GComponent_getOpaque);
    oluacls_func(L, "getScrollPane", _fairygui_GComponent_getScrollPane);
    oluacls_func(L, "getSnappingPosition", _fairygui_GComponent_getSnappingPosition);
    oluacls_func(L, "getTransition", _fairygui_GComponent_getTransition);
    oluacls_func(L, "getTransitionAt", _fairygui_GComponent_getTransitionAt);
    oluacls_func(L, "getTransitions", _fairygui_GComponent_getTransitions);
    oluacls_func(L, "getViewHeight", _fairygui_GComponent_getViewHeight);
    oluacls_func(L, "getViewWidth", _fairygui_GComponent_getViewWidth);
    oluacls_func(L, "isAncestorOf", _fairygui_GComponent_isAncestorOf);
    oluacls_func(L, "isChildInView", _fairygui_GComponent_isChildInView);
    oluacls_func(L, "new", _fairygui_GComponent_new);
    oluacls_func(L, "numChildren", _fairygui_GComponent_numChildren);
    oluacls_func(L, "removeChild", _fairygui_GComponent_removeChild);
    oluacls_func(L, "removeChildAt", _fairygui_GComponent_removeChildAt);
    oluacls_func(L, "removeChildren", _fairygui_GComponent_removeChildren);
    oluacls_func(L, "removeController", _fairygui_GComponent_removeController);
    oluacls_func(L, "resolve", _fairygui_GComponent_resolve);
    oluacls_func(L, "setApexIndex", _fairygui_GComponent_setApexIndex);
    oluacls_func(L, "setBoundsChangedFlag", _fairygui_GComponent_setBoundsChangedFlag);
    oluacls_func(L, "setChildIndex", _fairygui_GComponent_setChildIndex);
    oluacls_func(L, "setChildIndexBefore", _fairygui_GComponent_setChildIndexBefore);
    oluacls_func(L, "setChildrenRenderOrder", _fairygui_GComponent_setChildrenRenderOrder);
    oluacls_func(L, "setHitArea", _fairygui_GComponent_setHitArea);
    oluacls_func(L, "setMargin", _fairygui_GComponent_setMargin);
    oluacls_func(L, "setMask", _fairygui_GComponent_setMask);
    oluacls_func(L, "setOpaque", _fairygui_GComponent_setOpaque);
    oluacls_func(L, "setViewHeight", _fairygui_GComponent_setViewHeight);
    oluacls_func(L, "setViewWidth", _fairygui_GComponent_setViewWidth);
    oluacls_func(L, "swapChildren", _fairygui_GComponent_swapChildren);
    oluacls_func(L, "swapChildrenAt", _fairygui_GComponent_swapChildrenAt);
    oluacls_prop(L, "apexIndex", _fairygui_GComponent_getApexIndex, _fairygui_GComponent_setApexIndex);
    oluacls_prop(L, "children", _fairygui_GComponent_getChildren, nullptr);
    oluacls_prop(L, "childrenRenderOrder", _fairygui_GComponent_getChildrenRenderOrder, _fairygui_GComponent_setChildrenRenderOrder);
    oluacls_prop(L, "controllers", _fairygui_GComponent_getControllers, nullptr);
    oluacls_prop(L, "firstChildInView", _fairygui_GComponent_getFirstChildInView, nullptr);
    oluacls_prop(L, "hitArea", _fairygui_GComponent_getHitArea, _fairygui_GComponent_setHitArea);
    oluacls_prop(L, "margin", _fairygui_GComponent_getMargin, _fairygui_GComponent_setMargin);
    oluacls_prop(L, "mask", _fairygui_GComponent_getMask, _fairygui_GComponent_setMask);
    oluacls_prop(L, "numChildren", _fairygui_GComponent_numChildren, nullptr);
    oluacls_prop(L, "opaque", _fairygui_GComponent_getOpaque, _fairygui_GComponent_setOpaque);
    oluacls_prop(L, "scrollPane", _fairygui_GComponent_getScrollPane, nullptr);
    oluacls_prop(L, "transitions", _fairygui_GComponent_getTransitions, nullptr);
    oluacls_prop(L, "viewHeight", _fairygui_GComponent_getViewHeight, _fairygui_GComponent_setViewHeight);
    oluacls_prop(L, "viewWidth", _fairygui_GComponent_getViewWidth, _fairygui_GComponent_setViewWidth);

    olua_registerluatype<fairygui::GComponent>(L, "fgui.GComponent");

    return 1;
}

static int _fairygui_GRoot___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (fairygui::GRoot *)olua_toobj(L, 1, "fgui.GRoot");
    olua_push_cppobj(L, self, "fgui.GRoot");

    olua_endinvoke(L);

    return 1;
}

static int _fairygui_GRoot_bringToFront(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GRoot *self = nullptr;
    fairygui::Window *arg1 = nullptr;       /** win */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GRoot");
    olua_check_cppobj(L, 2, (void **)&arg1, "fgui.Window");

    // void bringToFront(fairygui::Window *win)
    self->bringToFront(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GRoot_closeAllExceptModals(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GRoot *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GRoot");

    // void closeAllExceptModals()
    self->closeAllExceptModals();

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GRoot_closeAllWindows(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GRoot *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GRoot");

    // void closeAllWindows()
    self->closeAllWindows();

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GRoot_closeModalWait(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GRoot *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GRoot");

    // void closeModalWait()
    self->closeModalWait();

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GRoot_create1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Scene *arg1 = nullptr;       /** scene */
    lua_Integer arg2 = 0;       /** zOrder */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.Scene");
    olua_check_int(L, 2, &arg2);

    // static fairygui::GRoot *create(cocos2d::Scene *scene, @optional int zOrder)
    fairygui::GRoot *ret = (fairygui::GRoot *)fairygui::GRoot::create(arg1, (int)arg2);
    int num_ret = olua_push_cppobj(L, ret, "fgui.GRoot");

    // inject code after call
    olua_push_cppobj<cocos2d::Node>(L, ret->displayObject());
    olua_addref(L, -1, "fgui.root", -2, OLUA_MODE_SINGLE);
    olua_addref(L, 1, "children", -1, OLUA_MODE_MULTIPLE);
    lua_pop(L, 1);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GRoot_create2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Scene *arg1 = nullptr;       /** scene */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.Scene");

    // static fairygui::GRoot *create(cocos2d::Scene *scene, @optional int zOrder)
    fairygui::GRoot *ret = (fairygui::GRoot *)fairygui::GRoot::create(arg1);
    int num_ret = olua_push_cppobj(L, ret, "fgui.GRoot");

    // inject code after call
    olua_push_cppobj<cocos2d::Node>(L, ret->displayObject());
    olua_addref(L, -1, "fgui.root", -2, OLUA_MODE_SINGLE);
    olua_addref(L, 1, "children", -1, OLUA_MODE_MULTIPLE);
    lua_pop(L, 1);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GRoot_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_cppobj(L, 1, "cc.Scene"))) {
            // static fairygui::GRoot *create(cocos2d::Scene *scene, @optional int zOrder)
            return _fairygui_GRoot_create2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_cppobj(L, 1, "cc.Scene")) && (olua_is_int(L, 2))) {
            // static fairygui::GRoot *create(cocos2d::Scene *scene, @optional int zOrder)
            return _fairygui_GRoot_create1(L);
        // }
    }

    luaL_error(L, "method 'fairygui::GRoot::create' not support '%d' arguments", num_args);

    return 0;
}

static int _fairygui_GRoot_getInputProcessor(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GRoot *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GRoot");

    // @addref(inputProcessor ^) fairygui::InputProcessor *getInputProcessor()
    fairygui::InputProcessor *ret = (fairygui::InputProcessor *)self->getInputProcessor();
    int num_ret = olua_push_cppobj(L, ret, "fgui.InputProcessor");

    // inject code after call
    olua_addref(L, 1, "inputProcessor", -1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GRoot_getInstance(lua_State *L)
{
    olua_startinvoke(L);

    // static fairygui::GRoot *getInstance()
    fairygui::GRoot *ret = (fairygui::GRoot *)fairygui::GRoot::getInstance();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GRoot");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GRoot_getModalLayer(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GRoot *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GRoot");

    // @addref(children |) fairygui::GGraph *getModalLayer()
    fairygui::GGraph *ret = (fairygui::GGraph *)self->getModalLayer();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GGraph");

    // inject code after call
    olua_addref(L, 1, "children", -1, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GRoot_getModalWaitingPane(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GRoot *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GRoot");

    // @addref(children |) fairygui::GObject *getModalWaitingPane()
    fairygui::GObject *ret = (fairygui::GObject *)self->getModalWaitingPane();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GObject");

    // inject code after call
    olua_addref(L, 1, "children", -1, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GRoot_getPoupPosition(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GRoot *self = nullptr;
    fairygui::GObject *arg1 = nullptr;       /** popup */
    fairygui::GObject *arg2 = nullptr;       /** target */
    lua_Unsigned arg3 = 0;       /** dir */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GRoot");
    olua_check_cppobj(L, 2, (void **)&arg1, "fgui.GObject");
    olua_check_cppobj(L, 3, (void **)&arg2, "fgui.GObject");
    olua_check_uint(L, 4, &arg3);

    // cocos2d::Vec2 getPoupPosition(fairygui::GObject *popup, fairygui::GObject *target, fairygui::PopupDirection dir)
    cocos2d::Vec2 ret = (cocos2d::Vec2)self->getPoupPosition(arg1, arg2, (fairygui::PopupDirection)arg3);
    int num_ret = auto_olua_push_cocos2d_Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GRoot_getSoundVolumeScale(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GRoot *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GRoot");

    // float getSoundVolumeScale()
    float ret = (float)self->getSoundVolumeScale();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GRoot_getTopWindow(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GRoot *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GRoot");

    // @addref(children |) fairygui::Window *getTopWindow()
    fairygui::Window *ret = (fairygui::Window *)self->getTopWindow();
    int num_ret = olua_push_cppobj(L, ret, "fgui.Window");

    // inject code after call
    olua_addref(L, 1, "children", -1, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GRoot_getTouchPosition(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GRoot *self = nullptr;
    lua_Integer arg1 = 0;       /** touchId */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GRoot");
    olua_check_int(L, 2, &arg1);

    // cocos2d::Vec2 getTouchPosition(int touchId)
    cocos2d::Vec2 ret = (cocos2d::Vec2)self->getTouchPosition((int)arg1);
    int num_ret = auto_olua_push_cocos2d_Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GRoot_getTouchTarget(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GRoot *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GRoot");

    // fairygui::GObject *getTouchTarget()
    fairygui::GObject *ret = (fairygui::GObject *)self->getTouchTarget();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GObject");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GRoot_hasAnyPopup(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GRoot *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GRoot");

    // bool hasAnyPopup()
    bool ret = (bool)self->hasAnyPopup();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GRoot_hasModalWindow(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GRoot *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GRoot");

    // bool hasModalWindow()
    bool ret = (bool)self->hasModalWindow();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GRoot_hidePopup1(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GRoot *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GRoot");

    // inject code before call
    olua_startcmpdelref(L, 1, "children");

    // @delref(children ~) void hidePopup()
    self->hidePopup();

    // inject code after call
    olua_endcmpdelref(L, 1, "children");

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GRoot_hidePopup2(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GRoot *self = nullptr;
    fairygui::GObject *arg1 = nullptr;       /** popup */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GRoot");
    olua_check_cppobj(L, 2, (void **)&arg1, "fgui.GObject");

    // inject code before call
    olua_startcmpdelref(L, 1, "children");

    // @delref(children ~) void hidePopup(fairygui::GObject *popup)
    self->hidePopup(arg1);

    // inject code after call
    olua_endcmpdelref(L, 1, "children");

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GRoot_hidePopup(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // @delref(children ~) void hidePopup()
        return _fairygui_GRoot_hidePopup1(L);
    }

    if (num_args == 1) {
        // if ((olua_is_cppobj(L, 2, "fgui.GObject"))) {
            // @delref(children ~) void hidePopup(fairygui::GObject *popup)
            return _fairygui_GRoot_hidePopup2(L);
        // }
    }

    luaL_error(L, "method 'fairygui::GRoot::hidePopup' not support '%d' arguments", num_args);

    return 0;
}

static int _fairygui_GRoot_hideTooltips(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GRoot *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GRoot");

    // void hideTooltips()
    self->hideTooltips();

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GRoot_hideWindow(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GRoot *self = nullptr;
    fairygui::Window *arg1 = nullptr;       /** win */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GRoot");
    olua_check_cppobj(L, 2, (void **)&arg1, "fgui.Window");

    // inject code before call
    int parent = 1;
    if (arg1->getParent()) {
        olua_push_cppobj<fairygui::GComponent>(L, arg1->getParent());
        parent = lua_gettop(L);
    }
    olua_startcmpdelref(L, parent, "children");

    // @delref(children ~ parent) void hideWindow(fairygui::Window *win)
    self->hideWindow(arg1);

    // inject code after call
    olua_endcmpdelref(L, parent, "children");

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GRoot_hideWindowImmediately(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GRoot *self = nullptr;
    fairygui::Window *arg1 = nullptr;       /** win */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GRoot");
    olua_check_cppobj(L, 2, (void **)&arg1, "fgui.Window");

    // inject code before call
    int parent = 1;
    if (arg1->getParent()) {
        olua_push_cppobj<fairygui::GComponent>(L, arg1->getParent());
        parent = lua_gettop(L);
    }
    olua_startcmpdelref(L, parent, "children");

    // @delref(children ~ parent) void hideWindowImmediately(fairygui::Window *win)
    self->hideWindowImmediately(arg1);

    // inject code after call
    olua_endcmpdelref(L, parent, "children");

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GRoot_isModalWaiting(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GRoot *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GRoot");

    // bool isModalWaiting()
    bool ret = (bool)self->isModalWaiting();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GRoot_isSoundEnabled(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GRoot *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GRoot");

    // bool isSoundEnabled()
    bool ret = (bool)self->isSoundEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GRoot_new(lua_State *L)
{
    olua_startinvoke(L);

    // GRoot()
    fairygui::GRoot *ret = (fairygui::GRoot *)new fairygui::GRoot();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GRoot");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GRoot_playSound1(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GRoot *self = nullptr;
    std::string arg1;       /** url */
    lua_Number arg2 = 0;       /** volumeScale */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GRoot");
    olua_check_std_string(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);

    // void playSound(const std::string &url, @optional float volumeScale)
    self->playSound(arg1, (float)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GRoot_playSound2(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GRoot *self = nullptr;
    std::string arg1;       /** url */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GRoot");
    olua_check_std_string(L, 2, &arg1);

    // void playSound(const std::string &url, @optional float volumeScale)
    self->playSound(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GRoot_playSound(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 2))) {
            // void playSound(const std::string &url, @optional float volumeScale)
            return _fairygui_GRoot_playSound2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_number(L, 3))) {
            // void playSound(const std::string &url, @optional float volumeScale)
            return _fairygui_GRoot_playSound1(L);
        // }
    }

    luaL_error(L, "method 'fairygui::GRoot::playSound' not support '%d' arguments", num_args);

    return 0;
}

static int _fairygui_GRoot_rootToWorld(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GRoot *self = nullptr;
    cocos2d::Vec2 arg1;       /** pt */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GRoot");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);

    // cocos2d::Vec2 rootToWorld(const cocos2d::Vec2 &pt)
    cocos2d::Vec2 ret = (cocos2d::Vec2)self->rootToWorld(arg1);
    int num_ret = auto_olua_push_cocos2d_Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GRoot_setNotAsUIRoot(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GRoot *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GRoot");

    // void setNotAsUIRoot()
    self->setNotAsUIRoot();

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GRoot_setSoundEnabled(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GRoot *self = nullptr;
    bool arg1 = false;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GRoot");
    olua_check_bool(L, 2, &arg1);

    // void setSoundEnabled(bool value)
    self->setSoundEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GRoot_setSoundVolumeScale(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GRoot *self = nullptr;
    lua_Number arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GRoot");
    olua_check_number(L, 2, &arg1);

    // void setSoundVolumeScale(float value)
    self->setSoundVolumeScale((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GRoot_showModalWait(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GRoot *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GRoot");

    // void showModalWait()
    self->showModalWait();

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GRoot_showPopup1(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GRoot *self = nullptr;
    fairygui::GObject *arg1 = nullptr;       /** popup */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GRoot");
    olua_check_cppobj(L, 2, (void **)&arg1, "fgui.GObject");

    // inject code before call
    olua_startcmpdelref(L, 1, "children");

    // @delref(children ~) void showPopup(@addref(children |) fairygui::GObject *popup)
    self->showPopup(arg1);

    // inject code after call
    olua_addref(L, 1, "children", 2, OLUA_MODE_MULTIPLE);
    olua_endcmpdelref(L, 1, "children");

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GRoot_showPopup2(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GRoot *self = nullptr;
    fairygui::GObject *arg1 = nullptr;       /** popup */
    fairygui::GObject *arg2 = nullptr;       /** target */
    lua_Unsigned arg3 = 0;       /** dir */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GRoot");
    olua_check_cppobj(L, 2, (void **)&arg1, "fgui.GObject");
    olua_check_cppobj(L, 3, (void **)&arg2, "fgui.GObject");
    olua_check_uint(L, 4, &arg3);

    // inject code before call
    olua_startcmpdelref(L, 1, "children");

    // @delref(children ~) void showPopup(@addref(children |) fairygui::GObject *popup, fairygui::GObject *target, fairygui::PopupDirection dir)
    self->showPopup(arg1, arg2, (fairygui::PopupDirection)arg3);

    // inject code after call
    olua_addref(L, 1, "children", 2, OLUA_MODE_MULTIPLE);
    olua_endcmpdelref(L, 1, "children");

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GRoot_showPopup(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_cppobj(L, 2, "fgui.GObject"))) {
            // @delref(children ~) void showPopup(@addref(children |) fairygui::GObject *popup)
            return _fairygui_GRoot_showPopup1(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_cppobj(L, 2, "fgui.GObject")) && (olua_is_cppobj(L, 3, "fgui.GObject")) && (olua_is_uint(L, 4))) {
            // @delref(children ~) void showPopup(@addref(children |) fairygui::GObject *popup, fairygui::GObject *target, fairygui::PopupDirection dir)
            return _fairygui_GRoot_showPopup2(L);
        // }
    }

    luaL_error(L, "method 'fairygui::GRoot::showPopup' not support '%d' arguments", num_args);

    return 0;
}

static int _fairygui_GRoot_showTooltips(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GRoot *self = nullptr;
    std::string arg1;       /** msg */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GRoot");
    olua_check_std_string(L, 2, &arg1);

    // void showTooltips(const std::string &msg)
    self->showTooltips(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GRoot_showTooltipsWin(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GRoot *self = nullptr;
    fairygui::GObject *arg1 = nullptr;       /** tooltipWin */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GRoot");
    olua_check_cppobj(L, 2, (void **)&arg1, "fgui.GObject");

    // void showTooltipsWin(fairygui::GObject *tooltipWin)
    self->showTooltipsWin(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GRoot_showWindow(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GRoot *self = nullptr;
    fairygui::Window *arg1 = nullptr;       /** win */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GRoot");
    olua_check_cppobj(L, 2, (void **)&arg1, "fgui.Window");

    // inject code before call
    olua_startcmpdelref(L, 1, "children");

    // @delref(children ~) void showWindow(@addref(children |) fairygui::Window *win)
    self->showWindow(arg1);

    // inject code after call
    olua_addref(L, 1, "children", 2, OLUA_MODE_MULTIPLE);
    olua_endcmpdelref(L, 1, "children");

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GRoot_togglePopup1(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GRoot *self = nullptr;
    fairygui::GObject *arg1 = nullptr;       /** popup */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GRoot");
    olua_check_cppobj(L, 2, (void **)&arg1, "fgui.GObject");

    // inject code before call
    olua_startcmpdelref(L, 1, "children");

    // @delref(children ~) void togglePopup(@addref(children |) fairygui::GObject *popup)
    self->togglePopup(arg1);

    // inject code after call
    olua_addref(L, 1, "children", 2, OLUA_MODE_MULTIPLE);
    olua_endcmpdelref(L, 1, "children");

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GRoot_togglePopup2(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GRoot *self = nullptr;
    fairygui::GObject *arg1 = nullptr;       /** popup */
    fairygui::GObject *arg2 = nullptr;       /** target */
    lua_Unsigned arg3 = 0;       /** dir */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GRoot");
    olua_check_cppobj(L, 2, (void **)&arg1, "fgui.GObject");
    olua_check_cppobj(L, 3, (void **)&arg2, "fgui.GObject");
    olua_check_uint(L, 4, &arg3);

    // inject code before call
    olua_startcmpdelref(L, 1, "children");

    // @delref(children ~) void togglePopup(@addref(children |) fairygui::GObject *popup, fairygui::GObject *target, fairygui::PopupDirection dir)
    self->togglePopup(arg1, arg2, (fairygui::PopupDirection)arg3);

    // inject code after call
    olua_addref(L, 1, "children", 2, OLUA_MODE_MULTIPLE);
    olua_endcmpdelref(L, 1, "children");

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GRoot_togglePopup(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_cppobj(L, 2, "fgui.GObject"))) {
            // @delref(children ~) void togglePopup(@addref(children |) fairygui::GObject *popup)
            return _fairygui_GRoot_togglePopup1(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_cppobj(L, 2, "fgui.GObject")) && (olua_is_cppobj(L, 3, "fgui.GObject")) && (olua_is_uint(L, 4))) {
            // @delref(children ~) void togglePopup(@addref(children |) fairygui::GObject *popup, fairygui::GObject *target, fairygui::PopupDirection dir)
            return _fairygui_GRoot_togglePopup2(L);
        // }
    }

    luaL_error(L, "method 'fairygui::GRoot::togglePopup' not support '%d' arguments", num_args);

    return 0;
}

static int _fairygui_GRoot_worldToRoot(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GRoot *self = nullptr;
    cocos2d::Vec2 arg1;       /** pt */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GRoot");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);

    // cocos2d::Vec2 worldToRoot(const cocos2d::Vec2 &pt)
    cocos2d::Vec2 ret = (cocos2d::Vec2)self->worldToRoot(arg1);
    int num_ret = auto_olua_push_cocos2d_Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GRoot_get_contentScaleLevel(lua_State *L)
{
    olua_startinvoke(L);

    // static int contentScaleLevel
    int ret = (int)fairygui::GRoot::contentScaleLevel;
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GRoot_set_contentScaleLevel(lua_State *L)
{
    olua_startinvoke(L);

    lua_Integer arg1 = 0;       /** contentScaleLevel */

    olua_check_int(L, 1, &arg1);

    // static int contentScaleLevel
    fairygui::GRoot::contentScaleLevel = (int)arg1;

    olua_endinvoke(L);

    return 0;
}

static int luaopen_fairygui_GRoot(lua_State *L)
{
    oluacls_class(L, "fgui.GRoot", "fgui.GComponent");
    oluacls_func(L, "__move", _fairygui_GRoot___move);
    oluacls_func(L, "bringToFront", _fairygui_GRoot_bringToFront);
    oluacls_func(L, "closeAllExceptModals", _fairygui_GRoot_closeAllExceptModals);
    oluacls_func(L, "closeAllWindows", _fairygui_GRoot_closeAllWindows);
    oluacls_func(L, "closeModalWait", _fairygui_GRoot_closeModalWait);
    oluacls_func(L, "create", _fairygui_GRoot_create);
    oluacls_func(L, "getInputProcessor", _fairygui_GRoot_getInputProcessor);
    oluacls_func(L, "getInstance", _fairygui_GRoot_getInstance);
    oluacls_func(L, "getModalLayer", _fairygui_GRoot_getModalLayer);
    oluacls_func(L, "getModalWaitingPane", _fairygui_GRoot_getModalWaitingPane);
    oluacls_func(L, "getPoupPosition", _fairygui_GRoot_getPoupPosition);
    oluacls_func(L, "getSoundVolumeScale", _fairygui_GRoot_getSoundVolumeScale);
    oluacls_func(L, "getTopWindow", _fairygui_GRoot_getTopWindow);
    oluacls_func(L, "getTouchPosition", _fairygui_GRoot_getTouchPosition);
    oluacls_func(L, "getTouchTarget", _fairygui_GRoot_getTouchTarget);
    oluacls_func(L, "hasAnyPopup", _fairygui_GRoot_hasAnyPopup);
    oluacls_func(L, "hasModalWindow", _fairygui_GRoot_hasModalWindow);
    oluacls_func(L, "hidePopup", _fairygui_GRoot_hidePopup);
    oluacls_func(L, "hideTooltips", _fairygui_GRoot_hideTooltips);
    oluacls_func(L, "hideWindow", _fairygui_GRoot_hideWindow);
    oluacls_func(L, "hideWindowImmediately", _fairygui_GRoot_hideWindowImmediately);
    oluacls_func(L, "isModalWaiting", _fairygui_GRoot_isModalWaiting);
    oluacls_func(L, "isSoundEnabled", _fairygui_GRoot_isSoundEnabled);
    oluacls_func(L, "new", _fairygui_GRoot_new);
    oluacls_func(L, "playSound", _fairygui_GRoot_playSound);
    oluacls_func(L, "rootToWorld", _fairygui_GRoot_rootToWorld);
    oluacls_func(L, "setNotAsUIRoot", _fairygui_GRoot_setNotAsUIRoot);
    oluacls_func(L, "setSoundEnabled", _fairygui_GRoot_setSoundEnabled);
    oluacls_func(L, "setSoundVolumeScale", _fairygui_GRoot_setSoundVolumeScale);
    oluacls_func(L, "showModalWait", _fairygui_GRoot_showModalWait);
    oluacls_func(L, "showPopup", _fairygui_GRoot_showPopup);
    oluacls_func(L, "showTooltips", _fairygui_GRoot_showTooltips);
    oluacls_func(L, "showTooltipsWin", _fairygui_GRoot_showTooltipsWin);
    oluacls_func(L, "showWindow", _fairygui_GRoot_showWindow);
    oluacls_func(L, "togglePopup", _fairygui_GRoot_togglePopup);
    oluacls_func(L, "worldToRoot", _fairygui_GRoot_worldToRoot);
    oluacls_prop(L, "UIRoot", _fairygui_GRoot_getInstance, nullptr);
    oluacls_prop(L, "inputProcessor", _fairygui_GRoot_getInputProcessor, nullptr);
    oluacls_prop(L, "instance", _fairygui_GRoot_getInstance, nullptr);
    oluacls_prop(L, "modalLayer", _fairygui_GRoot_getModalLayer, nullptr);
    oluacls_prop(L, "modalWaiting", _fairygui_GRoot_isModalWaiting, nullptr);
    oluacls_prop(L, "modalWaitingPane", _fairygui_GRoot_getModalWaitingPane, nullptr);
    oluacls_prop(L, "soundEnabled", _fairygui_GRoot_isSoundEnabled, _fairygui_GRoot_setSoundEnabled);
    oluacls_prop(L, "soundVolumeScale", _fairygui_GRoot_getSoundVolumeScale, _fairygui_GRoot_setSoundVolumeScale);
    oluacls_prop(L, "topWindow", _fairygui_GRoot_getTopWindow, nullptr);
    oluacls_prop(L, "touchTarget", _fairygui_GRoot_getTouchTarget, nullptr);
    oluacls_prop(L, "contentScaleLevel", _fairygui_GRoot_get_contentScaleLevel, _fairygui_GRoot_set_contentScaleLevel);

    olua_registerluatype<fairygui::GRoot>(L, "fgui.GRoot");

    return 1;
}

static int _fairygui_GGroup___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (fairygui::GGroup *)olua_toobj(L, 1, "fgui.GGroup");
    olua_push_cppobj(L, self, "fgui.GGroup");

    olua_endinvoke(L);

    return 1;
}

static int _fairygui_GGroup_create(lua_State *L)
{
    olua_startinvoke(L);

    // static fairygui::GGroup *create()
    fairygui::GGroup *ret = (fairygui::GGroup *)fairygui::GGroup::create();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GGroup");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GGroup_getColumnGap(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GGroup *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GGroup");

    // int getColumnGap()
    int ret = (int)self->getColumnGap();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GGroup_getLayout(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GGroup *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GGroup");

    // fairygui::GroupLayoutType getLayout()
    fairygui::GroupLayoutType ret = (fairygui::GroupLayoutType)self->getLayout();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GGroup_getLineGap(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GGroup *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GGroup");

    // int getLineGap()
    int ret = (int)self->getLineGap();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GGroup_getMainGridIndex(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GGroup *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GGroup");

    // int getMainGridIndex()
    int ret = (int)self->getMainGridIndex();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GGroup_getMainGridMinSize(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GGroup *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GGroup");

    // int getMainGridMinSize()
    int ret = (int)self->getMainGridMinSize();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GGroup_isAutoSizeDisabled(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GGroup *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GGroup");

    // bool isAutoSizeDisabled()
    bool ret = (bool)self->isAutoSizeDisabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GGroup_isExcludeInvisibles(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GGroup *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GGroup");

    // bool isExcludeInvisibles()
    bool ret = (bool)self->isExcludeInvisibles();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GGroup_moveChildren(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GGroup *self = nullptr;
    lua_Number arg1 = 0;       /** dx */
    lua_Number arg2 = 0;       /** dy */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GGroup");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);

    // void moveChildren(float dx, float dy)
    self->moveChildren((float)arg1, (float)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GGroup_new(lua_State *L)
{
    olua_startinvoke(L);

    // GGroup()
    fairygui::GGroup *ret = (fairygui::GGroup *)new fairygui::GGroup();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GGroup");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GGroup_resizeChildren(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GGroup *self = nullptr;
    lua_Number arg1 = 0;       /** dw */
    lua_Number arg2 = 0;       /** dh */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GGroup");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);

    // void resizeChildren(float dw, float dh)
    self->resizeChildren((float)arg1, (float)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GGroup_setAutoSizeDisabled(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GGroup *self = nullptr;
    bool arg1 = false;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GGroup");
    olua_check_bool(L, 2, &arg1);

    // void setAutoSizeDisabled(bool value)
    self->setAutoSizeDisabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GGroup_setBoundsChangedFlag1(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GGroup *self = nullptr;
    bool arg1 = false;       /** positionChangedOnly */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GGroup");
    olua_check_bool(L, 2, &arg1);

    // void setBoundsChangedFlag(@optional bool positionChangedOnly)
    self->setBoundsChangedFlag(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GGroup_setBoundsChangedFlag2(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GGroup *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GGroup");

    // void setBoundsChangedFlag(@optional bool positionChangedOnly)
    self->setBoundsChangedFlag();

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GGroup_setBoundsChangedFlag(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // void setBoundsChangedFlag(@optional bool positionChangedOnly)
        return _fairygui_GGroup_setBoundsChangedFlag2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_bool(L, 2))) {
            // void setBoundsChangedFlag(@optional bool positionChangedOnly)
            return _fairygui_GGroup_setBoundsChangedFlag1(L);
        // }
    }

    luaL_error(L, "method 'fairygui::GGroup::setBoundsChangedFlag' not support '%d' arguments", num_args);

    return 0;
}

static int _fairygui_GGroup_setColumnGap(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GGroup *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GGroup");
    olua_check_int(L, 2, &arg1);

    // void setColumnGap(int value)
    self->setColumnGap((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GGroup_setExcludeInvisibles(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GGroup *self = nullptr;
    bool arg1 = false;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GGroup");
    olua_check_bool(L, 2, &arg1);

    // void setExcludeInvisibles(bool value)
    self->setExcludeInvisibles(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GGroup_setLayout(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GGroup *self = nullptr;
    lua_Unsigned arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GGroup");
    olua_check_uint(L, 2, &arg1);

    // void setLayout(fairygui::GroupLayoutType value)
    self->setLayout((fairygui::GroupLayoutType)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GGroup_setLineGap(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GGroup *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GGroup");
    olua_check_int(L, 2, &arg1);

    // void setLineGap(int value)
    self->setLineGap((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GGroup_setMainGridIndex(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GGroup *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GGroup");
    olua_check_int(L, 2, &arg1);

    // void setMainGridIndex(int value)
    self->setMainGridIndex((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GGroup_setMainGridMinSize(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GGroup *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GGroup");
    olua_check_int(L, 2, &arg1);

    // void setMainGridMinSize(int value)
    self->setMainGridMinSize((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_fairygui_GGroup(lua_State *L)
{
    oluacls_class(L, "fgui.GGroup", "fgui.GObject");
    oluacls_func(L, "__move", _fairygui_GGroup___move);
    oluacls_func(L, "create", _fairygui_GGroup_create);
    oluacls_func(L, "getColumnGap", _fairygui_GGroup_getColumnGap);
    oluacls_func(L, "getLayout", _fairygui_GGroup_getLayout);
    oluacls_func(L, "getLineGap", _fairygui_GGroup_getLineGap);
    oluacls_func(L, "getMainGridIndex", _fairygui_GGroup_getMainGridIndex);
    oluacls_func(L, "getMainGridMinSize", _fairygui_GGroup_getMainGridMinSize);
    oluacls_func(L, "isAutoSizeDisabled", _fairygui_GGroup_isAutoSizeDisabled);
    oluacls_func(L, "isExcludeInvisibles", _fairygui_GGroup_isExcludeInvisibles);
    oluacls_func(L, "moveChildren", _fairygui_GGroup_moveChildren);
    oluacls_func(L, "new", _fairygui_GGroup_new);
    oluacls_func(L, "resizeChildren", _fairygui_GGroup_resizeChildren);
    oluacls_func(L, "setAutoSizeDisabled", _fairygui_GGroup_setAutoSizeDisabled);
    oluacls_func(L, "setBoundsChangedFlag", _fairygui_GGroup_setBoundsChangedFlag);
    oluacls_func(L, "setColumnGap", _fairygui_GGroup_setColumnGap);
    oluacls_func(L, "setExcludeInvisibles", _fairygui_GGroup_setExcludeInvisibles);
    oluacls_func(L, "setLayout", _fairygui_GGroup_setLayout);
    oluacls_func(L, "setLineGap", _fairygui_GGroup_setLineGap);
    oluacls_func(L, "setMainGridIndex", _fairygui_GGroup_setMainGridIndex);
    oluacls_func(L, "setMainGridMinSize", _fairygui_GGroup_setMainGridMinSize);
    oluacls_prop(L, "autoSizeDisabled", _fairygui_GGroup_isAutoSizeDisabled, _fairygui_GGroup_setAutoSizeDisabled);
    oluacls_prop(L, "columnGap", _fairygui_GGroup_getColumnGap, _fairygui_GGroup_setColumnGap);
    oluacls_prop(L, "excludeInvisibles", _fairygui_GGroup_isExcludeInvisibles, _fairygui_GGroup_setExcludeInvisibles);
    oluacls_prop(L, "layout", _fairygui_GGroup_getLayout, _fairygui_GGroup_setLayout);
    oluacls_prop(L, "lineGap", _fairygui_GGroup_getLineGap, _fairygui_GGroup_setLineGap);
    oluacls_prop(L, "mainGridIndex", _fairygui_GGroup_getMainGridIndex, _fairygui_GGroup_setMainGridIndex);
    oluacls_prop(L, "mainGridMinSize", _fairygui_GGroup_getMainGridMinSize, _fairygui_GGroup_setMainGridMinSize);

    olua_registerluatype<fairygui::GGroup>(L, "fgui.GGroup");

    return 1;
}

static int _fairygui_GScrollBar___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (fairygui::GScrollBar *)olua_toobj(L, 1, "fgui.GScrollBar");
    olua_push_cppobj(L, self, "fgui.GScrollBar");

    olua_endinvoke(L);

    return 1;
}

static int _fairygui_GScrollBar_create(lua_State *L)
{
    olua_startinvoke(L);

    // static fairygui::GScrollBar *create()
    fairygui::GScrollBar *ret = (fairygui::GScrollBar *)fairygui::GScrollBar::create();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GScrollBar");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GScrollBar_getMinSize(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GScrollBar *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GScrollBar");

    // float getMinSize()
    float ret = (float)self->getMinSize();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GScrollBar_new(lua_State *L)
{
    olua_startinvoke(L);

    // GScrollBar()
    fairygui::GScrollBar *ret = (fairygui::GScrollBar *)new fairygui::GScrollBar();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GScrollBar");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GScrollBar_setDisplayPerc(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GScrollBar *self = nullptr;
    lua_Number arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GScrollBar");
    olua_check_number(L, 2, &arg1);

    // void setDisplayPerc(float value)
    self->setDisplayPerc((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GScrollBar_setScrollPane(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GScrollBar *self = nullptr;
    fairygui::ScrollPane *arg1 = nullptr;       /** target */
    bool arg2 = false;       /** vertical */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GScrollBar");
    olua_check_cppobj(L, 2, (void **)&arg1, "fgui.ScrollPane");
    olua_check_bool(L, 3, &arg2);

    // void setScrollPane(fairygui::ScrollPane *target, bool vertical)
    self->setScrollPane(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GScrollBar_setScrollPerc(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GScrollBar *self = nullptr;
    lua_Number arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GScrollBar");
    olua_check_number(L, 2, &arg1);

    // void setScrollPerc(float value)
    self->setScrollPerc((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_fairygui_GScrollBar(lua_State *L)
{
    oluacls_class(L, "fgui.GScrollBar", "fgui.GComponent");
    oluacls_func(L, "__move", _fairygui_GScrollBar___move);
    oluacls_func(L, "create", _fairygui_GScrollBar_create);
    oluacls_func(L, "getMinSize", _fairygui_GScrollBar_getMinSize);
    oluacls_func(L, "new", _fairygui_GScrollBar_new);
    oluacls_func(L, "setDisplayPerc", _fairygui_GScrollBar_setDisplayPerc);
    oluacls_func(L, "setScrollPane", _fairygui_GScrollBar_setScrollPane);
    oluacls_func(L, "setScrollPerc", _fairygui_GScrollBar_setScrollPerc);
    oluacls_prop(L, "minSize", _fairygui_GScrollBar_getMinSize, nullptr);

    olua_registerluatype<fairygui::GScrollBar>(L, "fgui.GScrollBar");

    return 1;
}

static int _fairygui_GLoader___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (fairygui::GLoader *)olua_toobj(L, 1, "fgui.GLoader");
    olua_push_cppobj(L, self, "fgui.GLoader");

    olua_endinvoke(L);

    return 1;
}

static int _fairygui_GLoader_create(lua_State *L)
{
    olua_startinvoke(L);

    // static fairygui::GLoader *create()
    fairygui::GLoader *ret = (fairygui::GLoader *)fairygui::GLoader::create();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GLoader");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GLoader_getAlign(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GLoader *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GLoader");

    // cocos2d::TextHAlignment getAlign()
    cocos2d::TextHAlignment ret = (cocos2d::TextHAlignment)self->getAlign();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GLoader_getAutoSize(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GLoader *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GLoader");

    // bool getAutoSize()
    bool ret = (bool)self->getAutoSize();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GLoader_getColor(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GLoader *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GLoader");

    // cocos2d::Color3B getColor()
    cocos2d::Color3B ret = (cocos2d::Color3B)self->getColor();
    int num_ret = manual_olua_push_cocos2d_Color3B(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GLoader_getComponent(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GLoader *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GLoader");

    // @addref(component ^) fairygui::GComponent *getComponent()
    fairygui::GComponent *ret = (fairygui::GComponent *)self->getComponent();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GComponent");

    // inject code after call
    olua_addref(L, 1, "component", -1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GLoader_getContentSize(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GLoader *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GLoader");

    // const cocos2d::Size &getContentSize()
    const cocos2d::Size &ret = (const cocos2d::Size &)self->getContentSize();
    int num_ret = auto_olua_push_cocos2d_Size(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GLoader_getFill(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GLoader *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GLoader");

    // fairygui::LoaderFillType getFill()
    fairygui::LoaderFillType ret = (fairygui::LoaderFillType)self->getFill();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GLoader_getFillAmount(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GLoader *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GLoader");

    // float getFillAmount()
    float ret = (float)self->getFillAmount();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GLoader_getFillMethod(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GLoader *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GLoader");

    // fairygui::FillMethod getFillMethod()
    fairygui::FillMethod ret = (fairygui::FillMethod)self->getFillMethod();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GLoader_getFillOrigin(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GLoader *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GLoader");

    // fairygui::FillOrigin getFillOrigin()
    fairygui::FillOrigin ret = (fairygui::FillOrigin)self->getFillOrigin();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GLoader_getFrame(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GLoader *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GLoader");

    // int getFrame()
    int ret = (int)self->getFrame();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GLoader_getURL(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GLoader *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GLoader");

    // const std::string &getURL()
    const std::string &ret = (const std::string &)self->getURL();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GLoader_getVerticalAlign(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GLoader *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GLoader");

    // cocos2d::TextVAlignment getVerticalAlign()
    cocos2d::TextVAlignment ret = (cocos2d::TextVAlignment)self->getVerticalAlign();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GLoader_isFillClockwise(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GLoader *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GLoader");

    // bool isFillClockwise()
    bool ret = (bool)self->isFillClockwise();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GLoader_isPlaying(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GLoader *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GLoader");

    // bool isPlaying()
    bool ret = (bool)self->isPlaying();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GLoader_isShrinkOnly(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GLoader *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GLoader");

    // bool isShrinkOnly()
    bool ret = (bool)self->isShrinkOnly();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GLoader_new(lua_State *L)
{
    olua_startinvoke(L);

    // GLoader()
    fairygui::GLoader *ret = (fairygui::GLoader *)new fairygui::GLoader();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GLoader");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GLoader_setAlign(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GLoader *self = nullptr;
    lua_Unsigned arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GLoader");
    olua_check_uint(L, 2, &arg1);

    // void setAlign(cocos2d::TextHAlignment value)
    self->setAlign((cocos2d::TextHAlignment)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GLoader_setAutoSize(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GLoader *self = nullptr;
    bool arg1 = false;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GLoader");
    olua_check_bool(L, 2, &arg1);

    // void setAutoSize(bool value)
    self->setAutoSize(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GLoader_setColor(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GLoader *self = nullptr;
    cocos2d::Color3B arg1;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GLoader");
    manual_olua_check_cocos2d_Color3B(L, 2, &arg1);

    // void setColor(const cocos2d::Color3B &value)
    self->setColor(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GLoader_setFill(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GLoader *self = nullptr;
    lua_Unsigned arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GLoader");
    olua_check_uint(L, 2, &arg1);

    // void setFill(fairygui::LoaderFillType value)
    self->setFill((fairygui::LoaderFillType)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GLoader_setFillAmount(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GLoader *self = nullptr;
    lua_Number arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GLoader");
    olua_check_number(L, 2, &arg1);

    // void setFillAmount(float value)
    self->setFillAmount((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GLoader_setFillClockwise(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GLoader *self = nullptr;
    bool arg1 = false;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GLoader");
    olua_check_bool(L, 2, &arg1);

    // void setFillClockwise(bool value)
    self->setFillClockwise(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GLoader_setFillMethod(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GLoader *self = nullptr;
    lua_Unsigned arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GLoader");
    olua_check_uint(L, 2, &arg1);

    // void setFillMethod(fairygui::FillMethod value)
    self->setFillMethod((fairygui::FillMethod)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GLoader_setFillOrigin(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GLoader *self = nullptr;
    lua_Unsigned arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GLoader");
    olua_check_uint(L, 2, &arg1);

    // void setFillOrigin(fairygui::FillOrigin value)
    self->setFillOrigin((fairygui::FillOrigin)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GLoader_setFrame(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GLoader *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GLoader");
    olua_check_int(L, 2, &arg1);

    // void setFrame(int value)
    self->setFrame((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GLoader_setPlaying(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GLoader *self = nullptr;
    bool arg1 = false;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GLoader");
    olua_check_bool(L, 2, &arg1);

    // void setPlaying(bool value)
    self->setPlaying(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GLoader_setShrinkOnly(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GLoader *self = nullptr;
    bool arg1 = false;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GLoader");
    olua_check_bool(L, 2, &arg1);

    // void setShrinkOnly(bool value)
    self->setShrinkOnly(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GLoader_setURL(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GLoader *self = nullptr;
    std::string arg1;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GLoader");
    olua_check_std_string(L, 2, &arg1);

    // void setURL(const std::string &value)
    self->setURL(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GLoader_setVerticalAlign(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GLoader *self = nullptr;
    lua_Unsigned arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GLoader");
    olua_check_uint(L, 2, &arg1);

    // void setVerticalAlign(cocos2d::TextVAlignment value)
    self->setVerticalAlign((cocos2d::TextVAlignment)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_fairygui_GLoader(lua_State *L)
{
    oluacls_class(L, "fgui.GLoader", "fgui.GObject");
    oluacls_func(L, "__move", _fairygui_GLoader___move);
    oluacls_func(L, "create", _fairygui_GLoader_create);
    oluacls_func(L, "getAlign", _fairygui_GLoader_getAlign);
    oluacls_func(L, "getAutoSize", _fairygui_GLoader_getAutoSize);
    oluacls_func(L, "getColor", _fairygui_GLoader_getColor);
    oluacls_func(L, "getComponent", _fairygui_GLoader_getComponent);
    oluacls_func(L, "getContentSize", _fairygui_GLoader_getContentSize);
    oluacls_func(L, "getFill", _fairygui_GLoader_getFill);
    oluacls_func(L, "getFillAmount", _fairygui_GLoader_getFillAmount);
    oluacls_func(L, "getFillMethod", _fairygui_GLoader_getFillMethod);
    oluacls_func(L, "getFillOrigin", _fairygui_GLoader_getFillOrigin);
    oluacls_func(L, "getFrame", _fairygui_GLoader_getFrame);
    oluacls_func(L, "getURL", _fairygui_GLoader_getURL);
    oluacls_func(L, "getVerticalAlign", _fairygui_GLoader_getVerticalAlign);
    oluacls_func(L, "isFillClockwise", _fairygui_GLoader_isFillClockwise);
    oluacls_func(L, "isPlaying", _fairygui_GLoader_isPlaying);
    oluacls_func(L, "isShrinkOnly", _fairygui_GLoader_isShrinkOnly);
    oluacls_func(L, "new", _fairygui_GLoader_new);
    oluacls_func(L, "setAlign", _fairygui_GLoader_setAlign);
    oluacls_func(L, "setAutoSize", _fairygui_GLoader_setAutoSize);
    oluacls_func(L, "setColor", _fairygui_GLoader_setColor);
    oluacls_func(L, "setFill", _fairygui_GLoader_setFill);
    oluacls_func(L, "setFillAmount", _fairygui_GLoader_setFillAmount);
    oluacls_func(L, "setFillClockwise", _fairygui_GLoader_setFillClockwise);
    oluacls_func(L, "setFillMethod", _fairygui_GLoader_setFillMethod);
    oluacls_func(L, "setFillOrigin", _fairygui_GLoader_setFillOrigin);
    oluacls_func(L, "setFrame", _fairygui_GLoader_setFrame);
    oluacls_func(L, "setPlaying", _fairygui_GLoader_setPlaying);
    oluacls_func(L, "setShrinkOnly", _fairygui_GLoader_setShrinkOnly);
    oluacls_func(L, "setURL", _fairygui_GLoader_setURL);
    oluacls_func(L, "setVerticalAlign", _fairygui_GLoader_setVerticalAlign);
    oluacls_prop(L, "align", _fairygui_GLoader_getAlign, _fairygui_GLoader_setAlign);
    oluacls_prop(L, "autoSize", _fairygui_GLoader_getAutoSize, _fairygui_GLoader_setAutoSize);
    oluacls_prop(L, "color", _fairygui_GLoader_getColor, _fairygui_GLoader_setColor);
    oluacls_prop(L, "component", _fairygui_GLoader_getComponent, nullptr);
    oluacls_prop(L, "contentSize", _fairygui_GLoader_getContentSize, nullptr);
    oluacls_prop(L, "fill", _fairygui_GLoader_getFill, _fairygui_GLoader_setFill);
    oluacls_prop(L, "fillAmount", _fairygui_GLoader_getFillAmount, _fairygui_GLoader_setFillAmount);
    oluacls_prop(L, "fillClockwise", _fairygui_GLoader_isFillClockwise, _fairygui_GLoader_setFillClockwise);
    oluacls_prop(L, "fillMethod", _fairygui_GLoader_getFillMethod, _fairygui_GLoader_setFillMethod);
    oluacls_prop(L, "fillOrigin", _fairygui_GLoader_getFillOrigin, _fairygui_GLoader_setFillOrigin);
    oluacls_prop(L, "frame", _fairygui_GLoader_getFrame, _fairygui_GLoader_setFrame);
    oluacls_prop(L, "playing", _fairygui_GLoader_isPlaying, _fairygui_GLoader_setPlaying);
    oluacls_prop(L, "shrinkOnly", _fairygui_GLoader_isShrinkOnly, _fairygui_GLoader_setShrinkOnly);
    oluacls_prop(L, "url", _fairygui_GLoader_getURL, _fairygui_GLoader_setURL);
    oluacls_prop(L, "verticalAlign", _fairygui_GLoader_getVerticalAlign, _fairygui_GLoader_setVerticalAlign);

    olua_registerluatype<fairygui::GLoader>(L, "fgui.GLoader");

    return 1;
}

static int _fairygui_GTextField___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (fairygui::GTextField *)olua_toobj(L, 1, "fgui.GTextField");
    olua_push_cppobj(L, self, "fgui.GTextField");

    olua_endinvoke(L);

    return 1;
}

static int _fairygui_GTextField_applyTextFormat(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTextField *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTextField");

    // void applyTextFormat()
    self->applyTextFormat();

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GTextField_flushVars(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTextField *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTextField");

    // void flushVars()
    self->flushVars();

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GTextField_getAutoSize(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTextField *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTextField");

    // fairygui::AutoSizeType getAutoSize()
    fairygui::AutoSizeType ret = (fairygui::AutoSizeType)self->getAutoSize();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTextField_getColor(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTextField *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTextField");

    // cocos2d::Color3B getColor()
    cocos2d::Color3B ret = (cocos2d::Color3B)self->getColor();
    int num_ret = manual_olua_push_cocos2d_Color3B(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTextField_getFontSize(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTextField *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTextField");

    // float getFontSize()
    float ret = (float)self->getFontSize();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTextField_getOutlineColor(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTextField *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTextField");

    // cocos2d::Color3B getOutlineColor()
    cocos2d::Color3B ret = (cocos2d::Color3B)self->getOutlineColor();
    int num_ret = manual_olua_push_cocos2d_Color3B(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTextField_getTemplateVars(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTextField *self = olua_toobj<fairygui::GTextField>(L, 1);
    manual_olua_push_cocos2d_ValueMap(L, self->getTemplateVars());

    olua_endinvoke(L);

    return 1;
}

static int _fairygui_GTextField_getTextFormat(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTextField *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTextField");

    // fairygui::TextFormat *getTextFormat()
    fairygui::TextFormat *ret = (fairygui::TextFormat *)self->getTextFormat();
    int num_ret = olua_push_cppobj(L, ret, "fgui.TextFormat");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTextField_getTextSize(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTextField *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTextField");

    // const cocos2d::Size &getTextSize()
    const cocos2d::Size &ret = (const cocos2d::Size &)self->getTextSize();
    int num_ret = auto_olua_push_cocos2d_Size(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTextField_isSingleLine(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTextField *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTextField");

    // bool isSingleLine()
    bool ret = (bool)self->isSingleLine();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTextField_isUBBEnabled(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTextField *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTextField");

    // bool isUBBEnabled()
    bool ret = (bool)self->isUBBEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTextField_setAutoSize(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTextField *self = nullptr;
    lua_Unsigned arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTextField");
    olua_check_uint(L, 2, &arg1);

    // void setAutoSize(fairygui::AutoSizeType value)
    self->setAutoSize((fairygui::AutoSizeType)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GTextField_setColor(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTextField *self = nullptr;
    cocos2d::Color3B arg1;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTextField");
    manual_olua_check_cocos2d_Color3B(L, 2, &arg1);

    // void setColor(const cocos2d::Color3B &value)
    self->setColor(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GTextField_setFontSize(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTextField *self = nullptr;
    lua_Number arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTextField");
    olua_check_number(L, 2, &arg1);

    // void setFontSize(float value)
    self->setFontSize((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GTextField_setOutlineColor(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTextField *self = nullptr;
    cocos2d::Color3B arg1;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTextField");
    manual_olua_check_cocos2d_Color3B(L, 2, &arg1);

    // void setOutlineColor(const cocos2d::Color3B &value)
    self->setOutlineColor(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GTextField_setSingleLine(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTextField *self = nullptr;
    bool arg1 = false;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTextField");
    olua_check_bool(L, 2, &arg1);

    // void setSingleLine(bool value)
    self->setSingleLine(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GTextField_setTemplateVars(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ValueMap arg;
    fairygui::GTextField *self = olua_toobj<fairygui::GTextField>(L, 1);
    manual_olua_check_cocos2d_ValueMap(L, 2, &arg);
    self->setTemplateVars(&arg);

    olua_endinvoke(L);

    return 1;
}

static int _fairygui_GTextField_setUBBEnabled(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTextField *self = nullptr;
    bool arg1 = false;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTextField");
    olua_check_bool(L, 2, &arg1);

    // void setUBBEnabled(bool value)
    self->setUBBEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GTextField_setVar(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTextField *self = nullptr;
    std::string arg1;       /** name */
    cocos2d::Value arg2;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTextField");
    olua_check_std_string(L, 2, &arg1);
    manual_olua_check_cocos2d_Value(L, 3, &arg2);

    // fairygui::GTextField *setVar(const std::string &name, const cocos2d::Value &value)
    fairygui::GTextField *ret = (fairygui::GTextField *)self->setVar(arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "fgui.GTextField");

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_fairygui_GTextField(lua_State *L)
{
    oluacls_class(L, "fgui.GTextField", "fgui.GObject");
    oluacls_func(L, "__move", _fairygui_GTextField___move);
    oluacls_func(L, "applyTextFormat", _fairygui_GTextField_applyTextFormat);
    oluacls_func(L, "flushVars", _fairygui_GTextField_flushVars);
    oluacls_func(L, "getAutoSize", _fairygui_GTextField_getAutoSize);
    oluacls_func(L, "getColor", _fairygui_GTextField_getColor);
    oluacls_func(L, "getFontSize", _fairygui_GTextField_getFontSize);
    oluacls_func(L, "getOutlineColor", _fairygui_GTextField_getOutlineColor);
    oluacls_func(L, "getTemplateVars", _fairygui_GTextField_getTemplateVars);
    oluacls_func(L, "getTextFormat", _fairygui_GTextField_getTextFormat);
    oluacls_func(L, "getTextSize", _fairygui_GTextField_getTextSize);
    oluacls_func(L, "isSingleLine", _fairygui_GTextField_isSingleLine);
    oluacls_func(L, "isUBBEnabled", _fairygui_GTextField_isUBBEnabled);
    oluacls_func(L, "setAutoSize", _fairygui_GTextField_setAutoSize);
    oluacls_func(L, "setColor", _fairygui_GTextField_setColor);
    oluacls_func(L, "setFontSize", _fairygui_GTextField_setFontSize);
    oluacls_func(L, "setOutlineColor", _fairygui_GTextField_setOutlineColor);
    oluacls_func(L, "setSingleLine", _fairygui_GTextField_setSingleLine);
    oluacls_func(L, "setTemplateVars", _fairygui_GTextField_setTemplateVars);
    oluacls_func(L, "setUBBEnabled", _fairygui_GTextField_setUBBEnabled);
    oluacls_func(L, "setVar", _fairygui_GTextField_setVar);
    oluacls_prop(L, "autoSize", _fairygui_GTextField_getAutoSize, _fairygui_GTextField_setAutoSize);
    oluacls_prop(L, "color", _fairygui_GTextField_getColor, _fairygui_GTextField_setColor);
    oluacls_prop(L, "fontSize", _fairygui_GTextField_getFontSize, _fairygui_GTextField_setFontSize);
    oluacls_prop(L, "outlineColor", _fairygui_GTextField_getOutlineColor, _fairygui_GTextField_setOutlineColor);
    oluacls_prop(L, "singleLine", _fairygui_GTextField_isSingleLine, _fairygui_GTextField_setSingleLine);
    oluacls_prop(L, "templateVars", _fairygui_GTextField_getTemplateVars, _fairygui_GTextField_setTemplateVars);
    oluacls_prop(L, "textFormat", _fairygui_GTextField_getTextFormat, nullptr);
    oluacls_prop(L, "textSize", _fairygui_GTextField_getTextSize, nullptr);
    oluacls_prop(L, "ubbEnabled", _fairygui_GTextField_isUBBEnabled, _fairygui_GTextField_setUBBEnabled);

    olua_registerluatype<fairygui::GTextField>(L, "fgui.GTextField");

    return 1;
}

static int _fairygui_GBasicTextField___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (fairygui::GBasicTextField *)olua_toobj(L, 1, "fgui.GBasicTextField");
    olua_push_cppobj(L, self, "fgui.GBasicTextField");

    olua_endinvoke(L);

    return 1;
}

static int _fairygui_GBasicTextField_create(lua_State *L)
{
    olua_startinvoke(L);

    // static fairygui::GBasicTextField *create()
    fairygui::GBasicTextField *ret = (fairygui::GBasicTextField *)fairygui::GBasicTextField::create();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GBasicTextField");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GBasicTextField_new(lua_State *L)
{
    olua_startinvoke(L);

    // GBasicTextField()
    fairygui::GBasicTextField *ret = (fairygui::GBasicTextField *)new fairygui::GBasicTextField();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GBasicTextField");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_fairygui_GBasicTextField(lua_State *L)
{
    oluacls_class(L, "fgui.GBasicTextField", "fgui.GTextField");
    oluacls_func(L, "__move", _fairygui_GBasicTextField___move);
    oluacls_func(L, "create", _fairygui_GBasicTextField_create);
    oluacls_func(L, "new", _fairygui_GBasicTextField_new);

    olua_registerluatype<fairygui::GBasicTextField>(L, "fgui.GBasicTextField");

    return 1;
}

static int _fairygui_GGraph___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (fairygui::GGraph *)olua_toobj(L, 1, "fgui.GGraph");
    olua_push_cppobj(L, self, "fgui.GGraph");

    olua_endinvoke(L);

    return 1;
}

static int _fairygui_GGraph_create(lua_State *L)
{
    olua_startinvoke(L);

    // static fairygui::GGraph *create()
    fairygui::GGraph *ret = (fairygui::GGraph *)fairygui::GGraph::create();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GGraph");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GGraph_drawEllipse(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GGraph *self = nullptr;
    lua_Number arg1 = 0;       /** aWidth */
    lua_Number arg2 = 0;       /** aHeight */
    lua_Integer arg3 = 0;       /** lineSize */
    cocos2d::Color4F arg4;       /** lineColor */
    cocos2d::Color4F arg5;       /** fillColor */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GGraph");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_int(L, 4, &arg3);
    manual_olua_check_cocos2d_Color4F(L, 5, &arg4);
    manual_olua_check_cocos2d_Color4F(L, 6, &arg5);

    // void drawEllipse(float aWidth, float aHeight, int lineSize, const cocos2d::Color4F &lineColor, const cocos2d::Color4F &fillColor)
    self->drawEllipse((float)arg1, (float)arg2, (int)arg3, arg4, arg5);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GGraph_drawRect(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GGraph *self = nullptr;
    lua_Number arg1 = 0;       /** aWidth */
    lua_Number arg2 = 0;       /** aHeight */
    lua_Integer arg3 = 0;       /** lineSize */
    cocos2d::Color4F arg4;       /** lineColor */
    cocos2d::Color4F arg5;       /** fillColor */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GGraph");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_int(L, 4, &arg3);
    manual_olua_check_cocos2d_Color4F(L, 5, &arg4);
    manual_olua_check_cocos2d_Color4F(L, 6, &arg5);

    // void drawRect(float aWidth, float aHeight, int lineSize, const cocos2d::Color4F &lineColor, const cocos2d::Color4F &fillColor)
    self->drawRect((float)arg1, (float)arg2, (int)arg3, arg4, arg5);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GGraph_getColor(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GGraph *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GGraph");

    // cocos2d::Color3B getColor()
    cocos2d::Color3B ret = (cocos2d::Color3B)self->getColor();
    int num_ret = manual_olua_push_cocos2d_Color3B(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GGraph_isEmpty(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GGraph *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GGraph");

    // bool isEmpty()
    bool ret = (bool)self->isEmpty();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GGraph_new(lua_State *L)
{
    olua_startinvoke(L);

    // GGraph()
    fairygui::GGraph *ret = (fairygui::GGraph *)new fairygui::GGraph();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GGraph");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GGraph_setColor(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GGraph *self = nullptr;
    cocos2d::Color3B arg1;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GGraph");
    manual_olua_check_cocos2d_Color3B(L, 2, &arg1);

    // void setColor(const cocos2d::Color3B &value)
    self->setColor(arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_fairygui_GGraph(lua_State *L)
{
    oluacls_class(L, "fgui.GGraph", "fgui.GObject");
    oluacls_func(L, "__move", _fairygui_GGraph___move);
    oluacls_func(L, "create", _fairygui_GGraph_create);
    oluacls_func(L, "drawEllipse", _fairygui_GGraph_drawEllipse);
    oluacls_func(L, "drawRect", _fairygui_GGraph_drawRect);
    oluacls_func(L, "getColor", _fairygui_GGraph_getColor);
    oluacls_func(L, "isEmpty", _fairygui_GGraph_isEmpty);
    oluacls_func(L, "new", _fairygui_GGraph_new);
    oluacls_func(L, "setColor", _fairygui_GGraph_setColor);
    oluacls_prop(L, "color", _fairygui_GGraph_getColor, _fairygui_GGraph_setColor);
    oluacls_prop(L, "empty", _fairygui_GGraph_isEmpty, nullptr);

    olua_registerluatype<fairygui::GGraph>(L, "fgui.GGraph");

    return 1;
}

static int _fairygui_GButton___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (fairygui::GButton *)olua_toobj(L, 1, "fgui.GButton");
    olua_push_cppobj(L, self, "fgui.GButton");

    olua_endinvoke(L);

    return 1;
}

static int _fairygui_GButton_create(lua_State *L)
{
    olua_startinvoke(L);

    // static fairygui::GButton *create()
    fairygui::GButton *ret = (fairygui::GButton *)fairygui::GButton::create();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GButton");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GButton_getRelatedController(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GButton *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GButton");

    // @addref(relatedController ^) fairygui::GController *getRelatedController()
    fairygui::GController *ret = (fairygui::GController *)self->getRelatedController();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GController");

    // inject code after call
    olua_addref(L, 1, "relatedController", -1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GButton_getSelectedIcon(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GButton *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GButton");

    // const std::string &getSelectedIcon()
    const std::string &ret = (const std::string &)self->getSelectedIcon();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GButton_getSelectedTitle(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GButton *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GButton");

    // const std::string &getSelectedTitle()
    const std::string &ret = (const std::string &)self->getSelectedTitle();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GButton_getTextField(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GButton *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GButton");

    // @addref(textField ^) fairygui::GTextField *getTextField()
    fairygui::GTextField *ret = (fairygui::GTextField *)self->getTextField();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GTextField");

    // inject code after call
    olua_addref(L, 1, "textField", -1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GButton_getTitle(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GButton *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GButton");

    // const std::string &getTitle()
    const std::string &ret = (const std::string &)self->getTitle();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GButton_getTitleColor(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GButton *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GButton");

    // cocos2d::Color3B getTitleColor()
    cocos2d::Color3B ret = (cocos2d::Color3B)self->getTitleColor();
    int num_ret = manual_olua_push_cocos2d_Color3B(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GButton_getTitleFontSize(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GButton *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GButton");

    // int getTitleFontSize()
    int ret = (int)self->getTitleFontSize();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GButton_isChangeStateOnClick(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GButton *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GButton");

    // bool isChangeStateOnClick()
    bool ret = (bool)self->isChangeStateOnClick();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GButton_isSelected(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GButton *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GButton");

    // bool isSelected()
    bool ret = (bool)self->isSelected();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GButton_new(lua_State *L)
{
    olua_startinvoke(L);

    // GButton()
    fairygui::GButton *ret = (fairygui::GButton *)new fairygui::GButton();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GButton");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GButton_setChangeStateOnClick(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GButton *self = nullptr;
    bool arg1 = false;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GButton");
    olua_check_bool(L, 2, &arg1);

    // void setChangeStateOnClick(bool value)
    self->setChangeStateOnClick(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GButton_setRelatedController(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GButton *self = nullptr;
    fairygui::GController *arg1 = nullptr;       /** c */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GButton");
    olua_check_cppobj(L, 2, (void **)&arg1, "fgui.GController");

    // void setRelatedController(@addref(relatedController ^) fairygui::GController *c)
    self->setRelatedController(arg1);

    // inject code after call
    olua_addref(L, 1, "relatedController", 2, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GButton_setSelected(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GButton *self = nullptr;
    bool arg1 = false;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GButton");
    olua_check_bool(L, 2, &arg1);

    // void setSelected(bool value)
    self->setSelected(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GButton_setSelectedIcon(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GButton *self = nullptr;
    std::string arg1;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GButton");
    olua_check_std_string(L, 2, &arg1);

    // void setSelectedIcon(const std::string &value)
    self->setSelectedIcon(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GButton_setSelectedTitle(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GButton *self = nullptr;
    std::string arg1;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GButton");
    olua_check_std_string(L, 2, &arg1);

    // void setSelectedTitle(const std::string &value)
    self->setSelectedTitle(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GButton_setTitle(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GButton *self = nullptr;
    std::string arg1;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GButton");
    olua_check_std_string(L, 2, &arg1);

    // void setTitle(const std::string &value)
    self->setTitle(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GButton_setTitleColor(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GButton *self = nullptr;
    cocos2d::Color3B arg1;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GButton");
    manual_olua_check_cocos2d_Color3B(L, 2, &arg1);

    // void setTitleColor(const cocos2d::Color3B &value)
    self->setTitleColor(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GButton_setTitleFontSize(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GButton *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GButton");
    olua_check_int(L, 2, &arg1);

    // void setTitleFontSize(int value)
    self->setTitleFontSize((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_fairygui_GButton(lua_State *L)
{
    oluacls_class(L, "fgui.GButton", "fgui.GComponent");
    oluacls_func(L, "__move", _fairygui_GButton___move);
    oluacls_func(L, "create", _fairygui_GButton_create);
    oluacls_func(L, "getRelatedController", _fairygui_GButton_getRelatedController);
    oluacls_func(L, "getSelectedIcon", _fairygui_GButton_getSelectedIcon);
    oluacls_func(L, "getSelectedTitle", _fairygui_GButton_getSelectedTitle);
    oluacls_func(L, "getTextField", _fairygui_GButton_getTextField);
    oluacls_func(L, "getTitle", _fairygui_GButton_getTitle);
    oluacls_func(L, "getTitleColor", _fairygui_GButton_getTitleColor);
    oluacls_func(L, "getTitleFontSize", _fairygui_GButton_getTitleFontSize);
    oluacls_func(L, "isChangeStateOnClick", _fairygui_GButton_isChangeStateOnClick);
    oluacls_func(L, "isSelected", _fairygui_GButton_isSelected);
    oluacls_func(L, "new", _fairygui_GButton_new);
    oluacls_func(L, "setChangeStateOnClick", _fairygui_GButton_setChangeStateOnClick);
    oluacls_func(L, "setRelatedController", _fairygui_GButton_setRelatedController);
    oluacls_func(L, "setSelected", _fairygui_GButton_setSelected);
    oluacls_func(L, "setSelectedIcon", _fairygui_GButton_setSelectedIcon);
    oluacls_func(L, "setSelectedTitle", _fairygui_GButton_setSelectedTitle);
    oluacls_func(L, "setTitle", _fairygui_GButton_setTitle);
    oluacls_func(L, "setTitleColor", _fairygui_GButton_setTitleColor);
    oluacls_func(L, "setTitleFontSize", _fairygui_GButton_setTitleFontSize);
    oluacls_prop(L, "changeStateOnClick", _fairygui_GButton_isChangeStateOnClick, _fairygui_GButton_setChangeStateOnClick);
    oluacls_prop(L, "relatedController", _fairygui_GButton_getRelatedController, _fairygui_GButton_setRelatedController);
    oluacls_prop(L, "selected", _fairygui_GButton_isSelected, _fairygui_GButton_setSelected);
    oluacls_prop(L, "selectedIcon", _fairygui_GButton_getSelectedIcon, _fairygui_GButton_setSelectedIcon);
    oluacls_prop(L, "selectedTitle", _fairygui_GButton_getSelectedTitle, _fairygui_GButton_setSelectedTitle);
    oluacls_prop(L, "textField", _fairygui_GButton_getTextField, nullptr);
    oluacls_prop(L, "title", _fairygui_GButton_getTitle, _fairygui_GButton_setTitle);
    oluacls_prop(L, "titleColor", _fairygui_GButton_getTitleColor, _fairygui_GButton_setTitleColor);
    oluacls_prop(L, "titleFontSize", _fairygui_GButton_getTitleFontSize, _fairygui_GButton_setTitleFontSize);
    oluacls_const_string(L, "DISABLED", (const char *)fairygui::GButton::DISABLED.c_str());
    oluacls_const_string(L, "DOWN", (const char *)fairygui::GButton::DOWN.c_str());
    oluacls_const_string(L, "OVER", (const char *)fairygui::GButton::OVER.c_str());
    oluacls_const_string(L, "SELECTED_DISABLED", (const char *)fairygui::GButton::SELECTED_DISABLED.c_str());
    oluacls_const_string(L, "SELECTED_OVER", (const char *)fairygui::GButton::SELECTED_OVER.c_str());
    oluacls_const_string(L, "UP", (const char *)fairygui::GButton::UP.c_str());

    olua_registerluatype<fairygui::GButton>(L, "fgui.GButton");

    return 1;
}

static int _fairygui_GImage___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (fairygui::GImage *)olua_toobj(L, 1, "fgui.GImage");
    olua_push_cppobj(L, self, "fgui.GImage");

    olua_endinvoke(L);

    return 1;
}

static int _fairygui_GImage_create(lua_State *L)
{
    olua_startinvoke(L);

    // static fairygui::GImage *create()
    fairygui::GImage *ret = (fairygui::GImage *)fairygui::GImage::create();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GImage");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GImage_getColor(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GImage *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GImage");

    // cocos2d::Color3B getColor()
    cocos2d::Color3B ret = (cocos2d::Color3B)self->getColor();
    int num_ret = manual_olua_push_cocos2d_Color3B(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GImage_getFillAmount(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GImage *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GImage");

    // float getFillAmount()
    float ret = (float)self->getFillAmount();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GImage_getFillMethod(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GImage *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GImage");

    // fairygui::FillMethod getFillMethod()
    fairygui::FillMethod ret = (fairygui::FillMethod)self->getFillMethod();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GImage_getFillOrigin(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GImage *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GImage");

    // fairygui::FillOrigin getFillOrigin()
    fairygui::FillOrigin ret = (fairygui::FillOrigin)self->getFillOrigin();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GImage_getFlip(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GImage *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GImage");

    // fairygui::FlipType getFlip()
    fairygui::FlipType ret = (fairygui::FlipType)self->getFlip();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GImage_isFillClockwise(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GImage *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GImage");

    // bool isFillClockwise()
    bool ret = (bool)self->isFillClockwise();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GImage_new(lua_State *L)
{
    olua_startinvoke(L);

    // GImage()
    fairygui::GImage *ret = (fairygui::GImage *)new fairygui::GImage();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GImage");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GImage_setColor(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GImage *self = nullptr;
    cocos2d::Color3B arg1;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GImage");
    manual_olua_check_cocos2d_Color3B(L, 2, &arg1);

    // void setColor(const cocos2d::Color3B &value)
    self->setColor(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GImage_setFillAmount(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GImage *self = nullptr;
    lua_Number arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GImage");
    olua_check_number(L, 2, &arg1);

    // void setFillAmount(float value)
    self->setFillAmount((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GImage_setFillClockwise(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GImage *self = nullptr;
    bool arg1 = false;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GImage");
    olua_check_bool(L, 2, &arg1);

    // void setFillClockwise(bool value)
    self->setFillClockwise(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GImage_setFillMethod(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GImage *self = nullptr;
    lua_Unsigned arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GImage");
    olua_check_uint(L, 2, &arg1);

    // void setFillMethod(fairygui::FillMethod value)
    self->setFillMethod((fairygui::FillMethod)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GImage_setFillOrigin(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GImage *self = nullptr;
    lua_Unsigned arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GImage");
    olua_check_uint(L, 2, &arg1);

    // void setFillOrigin(fairygui::FillOrigin value)
    self->setFillOrigin((fairygui::FillOrigin)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GImage_setFlip(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GImage *self = nullptr;
    lua_Unsigned arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GImage");
    olua_check_uint(L, 2, &arg1);

    // void setFlip(fairygui::FlipType value)
    self->setFlip((fairygui::FlipType)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_fairygui_GImage(lua_State *L)
{
    oluacls_class(L, "fgui.GImage", "fgui.GObject");
    oluacls_func(L, "__move", _fairygui_GImage___move);
    oluacls_func(L, "create", _fairygui_GImage_create);
    oluacls_func(L, "getColor", _fairygui_GImage_getColor);
    oluacls_func(L, "getFillAmount", _fairygui_GImage_getFillAmount);
    oluacls_func(L, "getFillMethod", _fairygui_GImage_getFillMethod);
    oluacls_func(L, "getFillOrigin", _fairygui_GImage_getFillOrigin);
    oluacls_func(L, "getFlip", _fairygui_GImage_getFlip);
    oluacls_func(L, "isFillClockwise", _fairygui_GImage_isFillClockwise);
    oluacls_func(L, "new", _fairygui_GImage_new);
    oluacls_func(L, "setColor", _fairygui_GImage_setColor);
    oluacls_func(L, "setFillAmount", _fairygui_GImage_setFillAmount);
    oluacls_func(L, "setFillClockwise", _fairygui_GImage_setFillClockwise);
    oluacls_func(L, "setFillMethod", _fairygui_GImage_setFillMethod);
    oluacls_func(L, "setFillOrigin", _fairygui_GImage_setFillOrigin);
    oluacls_func(L, "setFlip", _fairygui_GImage_setFlip);
    oluacls_prop(L, "color", _fairygui_GImage_getColor, _fairygui_GImage_setColor);
    oluacls_prop(L, "fillAmount", _fairygui_GImage_getFillAmount, _fairygui_GImage_setFillAmount);
    oluacls_prop(L, "fillClockwise", _fairygui_GImage_isFillClockwise, _fairygui_GImage_setFillClockwise);
    oluacls_prop(L, "fillMethod", _fairygui_GImage_getFillMethod, _fairygui_GImage_setFillMethod);
    oluacls_prop(L, "fillOrigin", _fairygui_GImage_getFillOrigin, _fairygui_GImage_setFillOrigin);
    oluacls_prop(L, "flip", _fairygui_GImage_getFlip, _fairygui_GImage_setFlip);

    olua_registerluatype<fairygui::GImage>(L, "fgui.GImage");

    return 1;
}

static int _fairygui_GLabel___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (fairygui::GLabel *)olua_toobj(L, 1, "fgui.GLabel");
    olua_push_cppobj(L, self, "fgui.GLabel");

    olua_endinvoke(L);

    return 1;
}

static int _fairygui_GLabel_create(lua_State *L)
{
    olua_startinvoke(L);

    // static fairygui::GLabel *create()
    fairygui::GLabel *ret = (fairygui::GLabel *)fairygui::GLabel::create();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GLabel");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GLabel_getTextField(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GLabel *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GLabel");

    // @addref(textField ^) fairygui::GTextField *getTextField()
    fairygui::GTextField *ret = (fairygui::GTextField *)self->getTextField();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GTextField");

    // inject code after call
    olua_addref(L, 1, "textField", -1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GLabel_getTitle(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GLabel *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GLabel");

    // const std::string &getTitle()
    const std::string &ret = (const std::string &)self->getTitle();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GLabel_getTitleColor(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GLabel *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GLabel");

    // cocos2d::Color3B getTitleColor()
    cocos2d::Color3B ret = (cocos2d::Color3B)self->getTitleColor();
    int num_ret = manual_olua_push_cocos2d_Color3B(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GLabel_getTitleFontSize(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GLabel *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GLabel");

    // int getTitleFontSize()
    int ret = (int)self->getTitleFontSize();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GLabel_new(lua_State *L)
{
    olua_startinvoke(L);

    // GLabel()
    fairygui::GLabel *ret = (fairygui::GLabel *)new fairygui::GLabel();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GLabel");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GLabel_setTitle(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GLabel *self = nullptr;
    std::string arg1;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GLabel");
    olua_check_std_string(L, 2, &arg1);

    // void setTitle(const std::string &value)
    self->setTitle(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GLabel_setTitleColor(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GLabel *self = nullptr;
    cocos2d::Color3B arg1;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GLabel");
    manual_olua_check_cocos2d_Color3B(L, 2, &arg1);

    // void setTitleColor(const cocos2d::Color3B &value)
    self->setTitleColor(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GLabel_setTitleFontSize(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GLabel *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GLabel");
    olua_check_int(L, 2, &arg1);

    // void setTitleFontSize(int value)
    self->setTitleFontSize((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_fairygui_GLabel(lua_State *L)
{
    oluacls_class(L, "fgui.GLabel", "fgui.GComponent");
    oluacls_func(L, "__move", _fairygui_GLabel___move);
    oluacls_func(L, "create", _fairygui_GLabel_create);
    oluacls_func(L, "getTextField", _fairygui_GLabel_getTextField);
    oluacls_func(L, "getTitle", _fairygui_GLabel_getTitle);
    oluacls_func(L, "getTitleColor", _fairygui_GLabel_getTitleColor);
    oluacls_func(L, "getTitleFontSize", _fairygui_GLabel_getTitleFontSize);
    oluacls_func(L, "new", _fairygui_GLabel_new);
    oluacls_func(L, "setTitle", _fairygui_GLabel_setTitle);
    oluacls_func(L, "setTitleColor", _fairygui_GLabel_setTitleColor);
    oluacls_func(L, "setTitleFontSize", _fairygui_GLabel_setTitleFontSize);
    oluacls_prop(L, "textField", _fairygui_GLabel_getTextField, nullptr);
    oluacls_prop(L, "title", _fairygui_GLabel_getTitle, _fairygui_GLabel_setTitle);
    oluacls_prop(L, "titleColor", _fairygui_GLabel_getTitleColor, _fairygui_GLabel_setTitleColor);
    oluacls_prop(L, "titleFontSize", _fairygui_GLabel_getTitleFontSize, _fairygui_GLabel_setTitleFontSize);

    olua_registerluatype<fairygui::GLabel>(L, "fgui.GLabel");

    return 1;
}

static int _fairygui_GList___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (fairygui::GList *)olua_toobj(L, 1, "fgui.GList");
    olua_push_cppobj(L, self, "fgui.GList");

    olua_endinvoke(L);

    return 1;
}

static int _fairygui_GList_addItemFromPool1(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GList *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GList");

    // @addref(children |) fairygui::GObject *addItemFromPool()
    fairygui::GObject *ret = (fairygui::GObject *)self->addItemFromPool();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GObject");

    // inject code after call
    olua_addref(L, 1, "children", -1, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GList_addItemFromPool2(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GList *self = nullptr;
    std::string arg1;       /** url */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GList");
    olua_check_std_string(L, 2, &arg1);

    // @addref(children |) fairygui::GObject *addItemFromPool(const std::string &url)
    fairygui::GObject *ret = (fairygui::GObject *)self->addItemFromPool(arg1);
    int num_ret = olua_push_cppobj(L, ret, "fgui.GObject");

    // inject code after call
    olua_addref(L, 1, "children", -1, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GList_addItemFromPool(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // @addref(children |) fairygui::GObject *addItemFromPool()
        return _fairygui_GList_addItemFromPool1(L);
    }

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 2))) {
            // @addref(children |) fairygui::GObject *addItemFromPool(const std::string &url)
            return _fairygui_GList_addItemFromPool2(L);
        // }
    }

    luaL_error(L, "method 'fairygui::GList::addItemFromPool' not support '%d' arguments", num_args);

    return 0;
}

static int _fairygui_GList_addSelection(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GList *self = nullptr;
    lua_Integer arg1 = 0;       /** index */
    bool arg2 = false;       /** scrollItToView */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GList");
    olua_check_int(L, 2, &arg1);
    olua_check_bool(L, 3, &arg2);

    // void addSelection(int index, bool scrollItToView)
    self->addSelection((int)arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GList_childIndexToItemIndex(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GList *self = nullptr;
    lua_Integer arg1 = 0;       /** index */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GList");
    olua_check_int(L, 2, &arg1);

    // int childIndexToItemIndex(int index)
    int ret = (int)self->childIndexToItemIndex((int)arg1);
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GList_clearSelection(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GList *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GList");

    // void clearSelection()
    self->clearSelection();

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GList_create(lua_State *L)
{
    olua_startinvoke(L);

    // static fairygui::GList *create()
    fairygui::GList *ret = (fairygui::GList *)fairygui::GList::create();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GList");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GList_getAlign(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GList *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GList");

    // cocos2d::TextHAlignment getAlign()
    cocos2d::TextHAlignment ret = (cocos2d::TextHAlignment)self->getAlign();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GList_getAutoResizeItem(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GList *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GList");

    // bool getAutoResizeItem()
    bool ret = (bool)self->getAutoResizeItem();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GList_getColumnCount(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GList *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GList");

    // int getColumnCount()
    int ret = (int)self->getColumnCount();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GList_getColumnGap(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GList *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GList");

    // int getColumnGap()
    int ret = (int)self->getColumnGap();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GList_getDefaultItem(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GList *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GList");

    // const std::string &getDefaultItem()
    const std::string &ret = (const std::string &)self->getDefaultItem();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GList_getFromPool1(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GList *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GList");

    // fairygui::GObject *getFromPool()
    fairygui::GObject *ret = (fairygui::GObject *)self->getFromPool();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GObject");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GList_getFromPool2(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GList *self = nullptr;
    std::string arg1;       /** url */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GList");
    olua_check_std_string(L, 2, &arg1);

    // fairygui::GObject *getFromPool(const std::string &url)
    fairygui::GObject *ret = (fairygui::GObject *)self->getFromPool(arg1);
    int num_ret = olua_push_cppobj(L, ret, "fgui.GObject");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GList_getFromPool(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // fairygui::GObject *getFromPool()
        return _fairygui_GList_getFromPool1(L);
    }

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 2))) {
            // fairygui::GObject *getFromPool(const std::string &url)
            return _fairygui_GList_getFromPool2(L);
        // }
    }

    luaL_error(L, "method 'fairygui::GList::getFromPool' not support '%d' arguments", num_args);

    return 0;
}

static int _fairygui_GList_getLayout(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GList *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GList");

    // fairygui::ListLayoutType getLayout()
    fairygui::ListLayoutType ret = (fairygui::ListLayoutType)self->getLayout();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GList_getLineCount(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GList *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GList");

    // int getLineCount()
    int ret = (int)self->getLineCount();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GList_getLineGap(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GList *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GList");

    // int getLineGap()
    int ret = (int)self->getLineGap();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GList_getNumItems(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GList *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GList");

    // int getNumItems()
    int ret = (int)self->getNumItems();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GList_getSelectedIndex(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GList *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GList");

    // int getSelectedIndex()
    int ret = (int)self->getSelectedIndex();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GList_getSelection(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GList *self = nullptr;
    std::vector<int> arg1;       /** result */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GList");
    // no need to check 'arg1' with mark '@out'

    // void getSelection(@out std::vector<int> &result)
    self->getSelection(arg1);

    int arg1_size = (int)arg1.size();
    lua_createtable(L, arg1_size, 0);
    for (int i = 0; i < arg1_size; i++) {
        olua_push_int(L, (lua_Integer)((std::vector<int>)arg1)[i]);
        lua_rawseti(L, -2, i + 1);
    }

    olua_endinvoke(L);

    return 0 + 1;
}

static int _fairygui_GList_getSelectionController(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GList *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GList");

    // @addref(selectionController ^) fairygui::GController *getSelectionController()
    fairygui::GController *ret = (fairygui::GController *)self->getSelectionController();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GController");

    // inject code after call
    olua_addref(L, 1, "selectionController", -1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GList_getSelectionMode(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GList *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GList");

    // fairygui::ListSelectionMode getSelectionMode()
    fairygui::ListSelectionMode ret = (fairygui::ListSelectionMode)self->getSelectionMode();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GList_getVerticalAlign(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GList *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GList");

    // cocos2d::TextVAlignment getVerticalAlign()
    cocos2d::TextVAlignment ret = (cocos2d::TextVAlignment)self->getVerticalAlign();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GList_handleArrowKey(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GList *self = nullptr;
    lua_Integer arg1 = 0;       /** dir */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GList");
    olua_check_int(L, 2, &arg1);

    // void handleArrowKey(int dir)
    self->handleArrowKey((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GList_isVirtual(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GList *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GList");

    // bool isVirtual()
    bool ret = (bool)self->isVirtual();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GList_itemIndexToChildIndex(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GList *self = nullptr;
    lua_Integer arg1 = 0;       /** index */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GList");
    olua_check_int(L, 2, &arg1);

    // int itemIndexToChildIndex(int index)
    int ret = (int)self->itemIndexToChildIndex((int)arg1);
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GList_new(lua_State *L)
{
    olua_startinvoke(L);

    // GList()
    fairygui::GList *ret = (fairygui::GList *)new fairygui::GList();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GList");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GList_refreshVirtualList(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GList *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GList");

    // void refreshVirtualList()
    self->refreshVirtualList();

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GList_removeChildToPool(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GList *self = nullptr;
    fairygui::GObject *arg1 = nullptr;       /** child */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GList");
    olua_check_cppobj(L, 2, (void **)&arg1, "fgui.GObject");

    // void removeChildToPool(@delref(children |) fairygui::GObject *child)
    self->removeChildToPool(arg1);

    // inject code after call
    olua_delref(L, 1, "children", 2, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GList_removeChildToPoolAt(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GList *self = nullptr;
    lua_Integer arg1 = 0;       /** index */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GList");
    olua_check_int(L, 2, &arg1);

    // inject code before call
    olua_startcmpdelref(L, 1, "children");

    // @delref(children ~) void removeChildToPoolAt(int index)
    self->removeChildToPoolAt((int)arg1);

    // inject code after call
    olua_endcmpdelref(L, 1, "children");

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GList_removeChildrenToPool1(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GList *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GList");

    // inject code before call
    olua_startcmpdelref(L, 1, "children");

    // @delref(children ~) void removeChildrenToPool()
    self->removeChildrenToPool();

    // inject code after call
    olua_endcmpdelref(L, 1, "children");

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GList_removeChildrenToPool2(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GList *self = nullptr;
    lua_Integer arg1 = 0;       /** beginIndex */
    lua_Integer arg2 = 0;       /** endIndex */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GList");
    olua_check_int(L, 2, &arg1);
    olua_check_int(L, 3, &arg2);

    // inject code before call
    olua_startcmpdelref(L, 1, "children");

    // @delref(children ~) void removeChildrenToPool(int beginIndex, int endIndex)
    self->removeChildrenToPool((int)arg1, (int)arg2);

    // inject code after call
    olua_endcmpdelref(L, 1, "children");

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GList_removeChildrenToPool(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // @delref(children ~) void removeChildrenToPool()
        return _fairygui_GList_removeChildrenToPool1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_int(L, 2)) && (olua_is_int(L, 3))) {
            // @delref(children ~) void removeChildrenToPool(int beginIndex, int endIndex)
            return _fairygui_GList_removeChildrenToPool2(L);
        // }
    }

    luaL_error(L, "method 'fairygui::GList::removeChildrenToPool' not support '%d' arguments", num_args);

    return 0;
}

static int _fairygui_GList_removeSelection(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GList *self = nullptr;
    lua_Integer arg1 = 0;       /** index */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GList");
    olua_check_int(L, 2, &arg1);

    // void removeSelection(int index)
    self->removeSelection((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GList_resizeToFit1(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GList *self = nullptr;
    lua_Integer arg1 = 0;       /** itemCount */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GList");
    olua_check_int(L, 2, &arg1);

    // void resizeToFit(int itemCount)
    self->resizeToFit((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GList_resizeToFit2(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GList *self = nullptr;
    lua_Integer arg1 = 0;       /** itemCount */
    lua_Integer arg2 = 0;       /** minSize */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GList");
    olua_check_int(L, 2, &arg1);
    olua_check_int(L, 3, &arg2);

    // void resizeToFit(int itemCount, int minSize)
    self->resizeToFit((int)arg1, (int)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GList_resizeToFit(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_int(L, 2))) {
            // void resizeToFit(int itemCount)
            return _fairygui_GList_resizeToFit1(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_int(L, 2)) && (olua_is_int(L, 3))) {
            // void resizeToFit(int itemCount, int minSize)
            return _fairygui_GList_resizeToFit2(L);
        // }
    }

    luaL_error(L, "method 'fairygui::GList::resizeToFit' not support '%d' arguments", num_args);

    return 0;
}

static int _fairygui_GList_returnToPool(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GList *self = nullptr;
    fairygui::GObject *arg1 = nullptr;       /** obj */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GList");
    olua_check_cppobj(L, 2, (void **)&arg1, "fgui.GObject");

    // void returnToPool(@delref(children |) fairygui::GObject *obj)
    self->returnToPool(arg1);

    // inject code after call
    olua_delref(L, 1, "children", 2, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GList_scrollToView1(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GList *self = nullptr;
    lua_Integer arg1 = 0;       /** index */
    bool arg2 = false;       /** ani */
    bool arg3 = false;       /** setFirst */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GList");
    olua_check_int(L, 2, &arg1);
    olua_check_bool(L, 3, &arg2);
    olua_check_bool(L, 4, &arg3);

    // void scrollToView(int index, @optional bool ani, @optional bool setFirst)
    self->scrollToView((int)arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GList_scrollToView2(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GList *self = nullptr;
    lua_Integer arg1 = 0;       /** index */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GList");
    olua_check_int(L, 2, &arg1);

    // void scrollToView(int index, @optional bool ani, @optional bool setFirst)
    self->scrollToView((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GList_scrollToView3(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GList *self = nullptr;
    lua_Integer arg1 = 0;       /** index */
    bool arg2 = false;       /** ani */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GList");
    olua_check_int(L, 2, &arg1);
    olua_check_bool(L, 3, &arg2);

    // void scrollToView(int index, @optional bool ani, @optional bool setFirst)
    self->scrollToView((int)arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GList_scrollToView(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_int(L, 2))) {
            // void scrollToView(int index, @optional bool ani, @optional bool setFirst)
            return _fairygui_GList_scrollToView2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_int(L, 2)) && (olua_is_bool(L, 3))) {
            // void scrollToView(int index, @optional bool ani, @optional bool setFirst)
            return _fairygui_GList_scrollToView3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_int(L, 2)) && (olua_is_bool(L, 3)) && (olua_is_bool(L, 4))) {
            // void scrollToView(int index, @optional bool ani, @optional bool setFirst)
            return _fairygui_GList_scrollToView1(L);
        // }
    }

    luaL_error(L, "method 'fairygui::GList::scrollToView' not support '%d' arguments", num_args);

    return 0;
}

static int _fairygui_GList_selectAll(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GList *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GList");

    // void selectAll()
    self->selectAll();

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GList_selectReverse(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GList *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GList");

    // void selectReverse()
    self->selectReverse();

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GList_setAlign(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GList *self = nullptr;
    lua_Unsigned arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GList");
    olua_check_uint(L, 2, &arg1);

    // void setAlign(cocos2d::TextHAlignment value)
    self->setAlign((cocos2d::TextHAlignment)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GList_setAutoResizeItem(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GList *self = nullptr;
    bool arg1 = false;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GList");
    olua_check_bool(L, 2, &arg1);

    // void setAutoResizeItem(bool value)
    self->setAutoResizeItem(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GList_setColumnCount(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GList *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GList");
    olua_check_int(L, 2, &arg1);

    // void setColumnCount(int value)
    self->setColumnCount((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GList_setColumnGap(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GList *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GList");
    olua_check_int(L, 2, &arg1);

    // void setColumnGap(int value)
    self->setColumnGap((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GList_setDefaultItem(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GList *self = nullptr;
    std::string arg1;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GList");
    olua_check_std_string(L, 2, &arg1);

    // void setDefaultItem(const std::string &value)
    self->setDefaultItem(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GList_setLayout(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GList *self = nullptr;
    lua_Unsigned arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GList");
    olua_check_uint(L, 2, &arg1);

    // void setLayout(fairygui::ListLayoutType value)
    self->setLayout((fairygui::ListLayoutType)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GList_setLineCount(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GList *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GList");
    olua_check_int(L, 2, &arg1);

    // void setLineCount(int value)
    self->setLineCount((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GList_setLineGap(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GList *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GList");
    olua_check_int(L, 2, &arg1);

    // void setLineGap(int value)
    self->setLineGap((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GList_setNumItems(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GList *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GList");
    olua_check_int(L, 2, &arg1);

    // inject code before call
    olua_startcmpdelref(L, 1, "children");

    // @delref(children ~) void setNumItems(int value)
    self->setNumItems((int)arg1);

    // inject code after call
    olua_endcmpdelref(L, 1, "children");

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GList_setSelectedIndex(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GList *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GList");
    olua_check_int(L, 2, &arg1);

    // void setSelectedIndex(int value)
    self->setSelectedIndex((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GList_setSelectionController(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GList *self = nullptr;
    fairygui::GController *arg1 = nullptr;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GList");
    olua_check_cppobj(L, 2, (void **)&arg1, "fgui.GController");

    // void setSelectionController(@addref(selectionController ^) fairygui::GController *value)
    self->setSelectionController(arg1);

    // inject code after call
    olua_addref(L, 1, "selectionController", 2, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GList_setSelectionMode(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GList *self = nullptr;
    lua_Unsigned arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GList");
    olua_check_uint(L, 2, &arg1);

    // void setSelectionMode(fairygui::ListSelectionMode value)
    self->setSelectionMode((fairygui::ListSelectionMode)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GList_setVerticalAlign(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GList *self = nullptr;
    lua_Unsigned arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GList");
    olua_check_uint(L, 2, &arg1);

    // void setVerticalAlign(cocos2d::TextVAlignment value)
    self->setVerticalAlign((cocos2d::TextVAlignment)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GList_setVirtual(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GList *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GList");

    // inject code before call
    olua_startcmpdelref(L, 1, "children");

    // @delref(children ~) void setVirtual()
    self->setVirtual();

    // inject code after call
    olua_endcmpdelref(L, 1, "children");

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GList_setVirtualAndLoop(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GList *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GList");

    // inject code before call
    olua_startcmpdelref(L, 1, "children");

    // @delref(children ~) void setVirtualAndLoop()
    self->setVirtualAndLoop();

    // inject code after call
    olua_endcmpdelref(L, 1, "children");

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GList_get_foldInvisibleItems(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GList *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GList");

    // bool foldInvisibleItems
    bool ret = (bool)self->foldInvisibleItems;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GList_set_foldInvisibleItems(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GList *self = nullptr;
    bool arg1 = false;       /** foldInvisibleItems */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GList");
    olua_check_bool(L, 2, &arg1);

    // bool foldInvisibleItems
    self->foldInvisibleItems = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GList_get_itemProvider(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GList *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GList");

    void *self_obj = (void *)self;
    std::string tag = "itemProvider";
    olua_getcallback(L, self_obj, tag.c_str(), OLUA_TAG_SUBEQUAL);

    // @nullable @local std::function<std::string (int)> itemProvider
    std::function<std::string(int)> ret = (std::function<std::string(int)>)self->itemProvider;
    int num_ret = olua_push_std_function(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GList_set_itemProvider(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GList *self = nullptr;
    std::function<std::string(int)> arg1;       /** itemProvider */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GList");

    if (olua_is_std_function(L, 2)) {
        void *self_obj = (void *)self;
        std::string tag = "itemProvider";
        std::string func = olua_setcallback(L, self_obj, tag.c_str(), 2, OLUA_TAG_REPLACE);
        lua_Unsigned ctx = olua_context(L);
        arg1 = [self_obj, func, ctx](int arg1) {
            lua_State *L = olua_mainthread(NULL);
            std::string ret;       
            if (L != NULL && (olua_context(L) == ctx)) {
                int top = lua_gettop(L);
                olua_push_int(L, (lua_Integer)arg1);

                olua_callback(L, self_obj, func.c_str(), 1);

                if (olua_is_std_string(L, -1)) {
                    olua_check_std_string(L, -1, &ret);
                }

                lua_settop(L, top);
            }
            return ret;
        };
    } else {
        void *self_obj = (void *)self;
        std::string tag = "itemProvider";
        olua_removecallback(L, self_obj, tag.c_str(), OLUA_TAG_SUBEQUAL);
        arg1 = nullptr;
    }

    // @nullable @local std::function<std::string (int)> itemProvider
    self->itemProvider = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GList_get_itemRenderer(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GList *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GList");

    void *self_obj = (void *)self;
    std::string tag = "itemRenderer";
    olua_getcallback(L, self_obj, tag.c_str(), OLUA_TAG_SUBEQUAL);

    // @nullable std::function<void (int, GObject *)> itemRenderer
    std::function<void(int, fairygui::GObject *)> ret = (std::function<void(int, fairygui::GObject *)>)self->itemRenderer;
    int num_ret = olua_push_std_function(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GList_set_itemRenderer(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GList *self = nullptr;
    std::function<void(int, fairygui::GObject *)> arg1;       /** itemRenderer */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GList");

    if (olua_is_std_function(L, 2)) {
        void *self_obj = (void *)self;
        std::string tag = "itemRenderer";
        std::string func = olua_setcallback(L, self_obj, tag.c_str(), 2, OLUA_TAG_REPLACE);
        lua_Unsigned ctx = olua_context(L);
        arg1 = [self_obj, func, ctx](int arg1, fairygui::GObject *arg2) {
            lua_State *L = olua_mainthread(NULL);

            if (L != NULL && (olua_context(L) == ctx)) {
                int top = lua_gettop(L);
                olua_push_int(L, (lua_Integer)arg1);
                olua_push_cppobj(L, arg2, "fgui.GObject");

                // inject code before call
                if (arg2->getParent()) {
                    olua_push_cppobj<fairygui::GComponent>(L, (fairygui::GComponent *)self_obj);
                    olua_addref(L, -1, "children", -2, OLUA_MODE_MULTIPLE);
                    lua_pop(L, 1);
                }

                olua_callback(L, self_obj, func.c_str(), 2);

                lua_settop(L, top);
            }
        };
    } else {
        void *self_obj = (void *)self;
        std::string tag = "itemRenderer";
        olua_removecallback(L, self_obj, tag.c_str(), OLUA_TAG_SUBEQUAL);
        arg1 = nullptr;
    }

    // @nullable std::function<void (int, GObject *)> itemRenderer
    self->itemRenderer = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GList_get_scrollItemToViewOnClick(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GList *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GList");

    // bool scrollItemToViewOnClick
    bool ret = (bool)self->scrollItemToViewOnClick;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GList_set_scrollItemToViewOnClick(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GList *self = nullptr;
    bool arg1 = false;       /** scrollItemToViewOnClick */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GList");
    olua_check_bool(L, 2, &arg1);

    // bool scrollItemToViewOnClick
    self->scrollItemToViewOnClick = arg1;

    olua_endinvoke(L);

    return 0;
}

static int luaopen_fairygui_GList(lua_State *L)
{
    oluacls_class(L, "fgui.GList", "fgui.GComponent");
    oluacls_func(L, "__move", _fairygui_GList___move);
    oluacls_func(L, "addItemFromPool", _fairygui_GList_addItemFromPool);
    oluacls_func(L, "addSelection", _fairygui_GList_addSelection);
    oluacls_func(L, "childIndexToItemIndex", _fairygui_GList_childIndexToItemIndex);
    oluacls_func(L, "clearSelection", _fairygui_GList_clearSelection);
    oluacls_func(L, "create", _fairygui_GList_create);
    oluacls_func(L, "getAlign", _fairygui_GList_getAlign);
    oluacls_func(L, "getAutoResizeItem", _fairygui_GList_getAutoResizeItem);
    oluacls_func(L, "getColumnCount", _fairygui_GList_getColumnCount);
    oluacls_func(L, "getColumnGap", _fairygui_GList_getColumnGap);
    oluacls_func(L, "getDefaultItem", _fairygui_GList_getDefaultItem);
    oluacls_func(L, "getFromPool", _fairygui_GList_getFromPool);
    oluacls_func(L, "getLayout", _fairygui_GList_getLayout);
    oluacls_func(L, "getLineCount", _fairygui_GList_getLineCount);
    oluacls_func(L, "getLineGap", _fairygui_GList_getLineGap);
    oluacls_func(L, "getNumItems", _fairygui_GList_getNumItems);
    oluacls_func(L, "getSelectedIndex", _fairygui_GList_getSelectedIndex);
    oluacls_func(L, "getSelection", _fairygui_GList_getSelection);
    oluacls_func(L, "getSelectionController", _fairygui_GList_getSelectionController);
    oluacls_func(L, "getSelectionMode", _fairygui_GList_getSelectionMode);
    oluacls_func(L, "getVerticalAlign", _fairygui_GList_getVerticalAlign);
    oluacls_func(L, "handleArrowKey", _fairygui_GList_handleArrowKey);
    oluacls_func(L, "isVirtual", _fairygui_GList_isVirtual);
    oluacls_func(L, "itemIndexToChildIndex", _fairygui_GList_itemIndexToChildIndex);
    oluacls_func(L, "new", _fairygui_GList_new);
    oluacls_func(L, "refreshVirtualList", _fairygui_GList_refreshVirtualList);
    oluacls_func(L, "removeChildToPool", _fairygui_GList_removeChildToPool);
    oluacls_func(L, "removeChildToPoolAt", _fairygui_GList_removeChildToPoolAt);
    oluacls_func(L, "removeChildrenToPool", _fairygui_GList_removeChildrenToPool);
    oluacls_func(L, "removeSelection", _fairygui_GList_removeSelection);
    oluacls_func(L, "resizeToFit", _fairygui_GList_resizeToFit);
    oluacls_func(L, "returnToPool", _fairygui_GList_returnToPool);
    oluacls_func(L, "scrollToView", _fairygui_GList_scrollToView);
    oluacls_func(L, "selectAll", _fairygui_GList_selectAll);
    oluacls_func(L, "selectReverse", _fairygui_GList_selectReverse);
    oluacls_func(L, "setAlign", _fairygui_GList_setAlign);
    oluacls_func(L, "setAutoResizeItem", _fairygui_GList_setAutoResizeItem);
    oluacls_func(L, "setColumnCount", _fairygui_GList_setColumnCount);
    oluacls_func(L, "setColumnGap", _fairygui_GList_setColumnGap);
    oluacls_func(L, "setDefaultItem", _fairygui_GList_setDefaultItem);
    oluacls_func(L, "setLayout", _fairygui_GList_setLayout);
    oluacls_func(L, "setLineCount", _fairygui_GList_setLineCount);
    oluacls_func(L, "setLineGap", _fairygui_GList_setLineGap);
    oluacls_func(L, "setNumItems", _fairygui_GList_setNumItems);
    oluacls_func(L, "setSelectedIndex", _fairygui_GList_setSelectedIndex);
    oluacls_func(L, "setSelectionController", _fairygui_GList_setSelectionController);
    oluacls_func(L, "setSelectionMode", _fairygui_GList_setSelectionMode);
    oluacls_func(L, "setVerticalAlign", _fairygui_GList_setVerticalAlign);
    oluacls_func(L, "setVirtual", _fairygui_GList_setVirtual);
    oluacls_func(L, "setVirtualAndLoop", _fairygui_GList_setVirtualAndLoop);
    oluacls_prop(L, "align", _fairygui_GList_getAlign, _fairygui_GList_setAlign);
    oluacls_prop(L, "autoResizeItem", _fairygui_GList_getAutoResizeItem, _fairygui_GList_setAutoResizeItem);
    oluacls_prop(L, "columnCount", _fairygui_GList_getColumnCount, _fairygui_GList_setColumnCount);
    oluacls_prop(L, "columnGap", _fairygui_GList_getColumnGap, _fairygui_GList_setColumnGap);
    oluacls_prop(L, "defaultItem", _fairygui_GList_getDefaultItem, _fairygui_GList_setDefaultItem);
    oluacls_prop(L, "layout", _fairygui_GList_getLayout, _fairygui_GList_setLayout);
    oluacls_prop(L, "lineCount", _fairygui_GList_getLineCount, _fairygui_GList_setLineCount);
    oluacls_prop(L, "lineGap", _fairygui_GList_getLineGap, _fairygui_GList_setLineGap);
    oluacls_prop(L, "numItems", _fairygui_GList_getNumItems, _fairygui_GList_setNumItems);
    oluacls_prop(L, "selectedIndex", _fairygui_GList_getSelectedIndex, _fairygui_GList_setSelectedIndex);
    oluacls_prop(L, "selectionController", _fairygui_GList_getSelectionController, _fairygui_GList_setSelectionController);
    oluacls_prop(L, "selectionMode", _fairygui_GList_getSelectionMode, _fairygui_GList_setSelectionMode);
    oluacls_prop(L, "verticalAlign", _fairygui_GList_getVerticalAlign, _fairygui_GList_setVerticalAlign);
    oluacls_prop(L, "virtual", _fairygui_GList_isVirtual, _fairygui_GList_setVirtual);
    oluacls_prop(L, "foldInvisibleItems", _fairygui_GList_get_foldInvisibleItems, _fairygui_GList_set_foldInvisibleItems);
    oluacls_prop(L, "itemProvider", _fairygui_GList_get_itemProvider, _fairygui_GList_set_itemProvider);
    oluacls_prop(L, "itemRenderer", _fairygui_GList_get_itemRenderer, _fairygui_GList_set_itemRenderer);
    oluacls_prop(L, "scrollItemToViewOnClick", _fairygui_GList_get_scrollItemToViewOnClick, _fairygui_GList_set_scrollItemToViewOnClick);

    olua_registerluatype<fairygui::GList>(L, "fgui.GList");

    return 1;
}

static int _fairygui_GMovieClip___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (fairygui::GMovieClip *)olua_toobj(L, 1, "fgui.GMovieClip");
    olua_push_cppobj(L, self, "fgui.GMovieClip");

    olua_endinvoke(L);

    return 1;
}

static int _fairygui_GMovieClip_advance(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GMovieClip *self = nullptr;
    lua_Number arg1 = 0;       /** time */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GMovieClip");
    olua_check_number(L, 2, &arg1);

    // void advance(float time)
    self->advance((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GMovieClip_create(lua_State *L)
{
    olua_startinvoke(L);

    // static fairygui::GMovieClip *create()
    fairygui::GMovieClip *ret = (fairygui::GMovieClip *)fairygui::GMovieClip::create();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GMovieClip");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GMovieClip_getColor(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GMovieClip *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GMovieClip");

    // cocos2d::Color3B getColor()
    cocos2d::Color3B ret = (cocos2d::Color3B)self->getColor();
    int num_ret = manual_olua_push_cocos2d_Color3B(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GMovieClip_getFlip(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GMovieClip *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GMovieClip");

    // fairygui::FlipType getFlip()
    fairygui::FlipType ret = (fairygui::FlipType)self->getFlip();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GMovieClip_getFrame(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GMovieClip *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GMovieClip");

    // int getFrame()
    int ret = (int)self->getFrame();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GMovieClip_getTimeScale(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GMovieClip *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GMovieClip");

    // float getTimeScale()
    float ret = (float)self->getTimeScale();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GMovieClip_isPlaying(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GMovieClip *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GMovieClip");

    // bool isPlaying()
    bool ret = (bool)self->isPlaying();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GMovieClip_new(lua_State *L)
{
    olua_startinvoke(L);

    // GMovieClip()
    fairygui::GMovieClip *ret = (fairygui::GMovieClip *)new fairygui::GMovieClip();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GMovieClip");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GMovieClip_setColor(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GMovieClip *self = nullptr;
    cocos2d::Color3B arg1;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GMovieClip");
    manual_olua_check_cocos2d_Color3B(L, 2, &arg1);

    // void setColor(const cocos2d::Color3B &value)
    self->setColor(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GMovieClip_setFlip(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GMovieClip *self = nullptr;
    lua_Unsigned arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GMovieClip");
    olua_check_uint(L, 2, &arg1);

    // void setFlip(fairygui::FlipType value)
    self->setFlip((fairygui::FlipType)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GMovieClip_setFrame(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GMovieClip *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GMovieClip");
    olua_check_int(L, 2, &arg1);

    // void setFrame(int value)
    self->setFrame((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GMovieClip_setPlaySettings1(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GMovieClip *self = nullptr;
    lua_Integer arg1 = 0;       /** start */
    lua_Integer arg2 = 0;       /** end */
    lua_Integer arg3 = 0;       /** times */
    lua_Integer arg4 = 0;       /** endAt */
    std::function<void()> arg5;       /** completeCallback */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GMovieClip");
    olua_check_int(L, 2, &arg1);
    olua_check_int(L, 3, &arg2);
    olua_check_int(L, 4, &arg3);
    olua_check_int(L, 5, &arg4);

    if (olua_is_std_function(L, 6)) {
        void *self_obj = (void *)self;
        std::string tag = "PlaySettings";
        std::string func = olua_setcallback(L, self_obj, tag.c_str(), 6, OLUA_TAG_REPLACE);
        lua_Unsigned ctx = olua_context(L);
        arg5 = [self_obj, func, ctx]() {
            lua_State *L = olua_mainthread(NULL);

            if (L != NULL && (olua_context(L) == ctx)) {
                int top = lua_gettop(L);

                olua_callback(L, self_obj, func.c_str(), 0);

                lua_settop(L, top);
            }
        };
    } else {
        void *self_obj = (void *)self;
        std::string tag = "PlaySettings";
        olua_removecallback(L, self_obj, tag.c_str(), OLUA_TAG_SUBEQUAL);
        arg5 = nullptr;
    }

    // void setPlaySettings(@optional int start, @optional int end, @optional int times, @optional int endAt, @local @optional std::function<void ()> completeCallback)
    self->setPlaySettings((int)arg1, (int)arg2, (int)arg3, (int)arg4, arg5);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GMovieClip_setPlaySettings2(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GMovieClip *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GMovieClip");

    // void setPlaySettings(@optional int start, @optional int end, @optional int times, @optional int endAt, @local @optional std::function<void ()> completeCallback)
    self->setPlaySettings();

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GMovieClip_setPlaySettings3(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GMovieClip *self = nullptr;
    lua_Integer arg1 = 0;       /** start */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GMovieClip");
    olua_check_int(L, 2, &arg1);

    // void setPlaySettings(@optional int start, @optional int end, @optional int times, @optional int endAt, @local @optional std::function<void ()> completeCallback)
    self->setPlaySettings((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GMovieClip_setPlaySettings4(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GMovieClip *self = nullptr;
    lua_Integer arg1 = 0;       /** start */
    lua_Integer arg2 = 0;       /** end */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GMovieClip");
    olua_check_int(L, 2, &arg1);
    olua_check_int(L, 3, &arg2);

    // void setPlaySettings(@optional int start, @optional int end, @optional int times, @optional int endAt, @local @optional std::function<void ()> completeCallback)
    self->setPlaySettings((int)arg1, (int)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GMovieClip_setPlaySettings5(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GMovieClip *self = nullptr;
    lua_Integer arg1 = 0;       /** start */
    lua_Integer arg2 = 0;       /** end */
    lua_Integer arg3 = 0;       /** times */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GMovieClip");
    olua_check_int(L, 2, &arg1);
    olua_check_int(L, 3, &arg2);
    olua_check_int(L, 4, &arg3);

    // void setPlaySettings(@optional int start, @optional int end, @optional int times, @optional int endAt, @local @optional std::function<void ()> completeCallback)
    self->setPlaySettings((int)arg1, (int)arg2, (int)arg3);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GMovieClip_setPlaySettings6(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GMovieClip *self = nullptr;
    lua_Integer arg1 = 0;       /** start */
    lua_Integer arg2 = 0;       /** end */
    lua_Integer arg3 = 0;       /** times */
    lua_Integer arg4 = 0;       /** endAt */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GMovieClip");
    olua_check_int(L, 2, &arg1);
    olua_check_int(L, 3, &arg2);
    olua_check_int(L, 4, &arg3);
    olua_check_int(L, 5, &arg4);

    // void setPlaySettings(@optional int start, @optional int end, @optional int times, @optional int endAt, @local @optional std::function<void ()> completeCallback)
    self->setPlaySettings((int)arg1, (int)arg2, (int)arg3, (int)arg4);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GMovieClip_setPlaySettings(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // void setPlaySettings(@optional int start, @optional int end, @optional int times, @optional int endAt, @local @optional std::function<void ()> completeCallback)
        return _fairygui_GMovieClip_setPlaySettings2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_int(L, 2))) {
            // void setPlaySettings(@optional int start, @optional int end, @optional int times, @optional int endAt, @local @optional std::function<void ()> completeCallback)
            return _fairygui_GMovieClip_setPlaySettings3(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_int(L, 2)) && (olua_is_int(L, 3))) {
            // void setPlaySettings(@optional int start, @optional int end, @optional int times, @optional int endAt, @local @optional std::function<void ()> completeCallback)
            return _fairygui_GMovieClip_setPlaySettings4(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_int(L, 2)) && (olua_is_int(L, 3)) && (olua_is_int(L, 4))) {
            // void setPlaySettings(@optional int start, @optional int end, @optional int times, @optional int endAt, @local @optional std::function<void ()> completeCallback)
            return _fairygui_GMovieClip_setPlaySettings5(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_int(L, 2)) && (olua_is_int(L, 3)) && (olua_is_int(L, 4)) && (olua_is_int(L, 5))) {
            // void setPlaySettings(@optional int start, @optional int end, @optional int times, @optional int endAt, @local @optional std::function<void ()> completeCallback)
            return _fairygui_GMovieClip_setPlaySettings6(L);
        // }
    }

    if (num_args == 5) {
        // if ((olua_is_int(L, 2)) && (olua_is_int(L, 3)) && (olua_is_int(L, 4)) && (olua_is_int(L, 5)) && (olua_is_std_function(L, 6))) {
            // void setPlaySettings(@optional int start, @optional int end, @optional int times, @optional int endAt, @local @optional std::function<void ()> completeCallback)
            return _fairygui_GMovieClip_setPlaySettings1(L);
        // }
    }

    luaL_error(L, "method 'fairygui::GMovieClip::setPlaySettings' not support '%d' arguments", num_args);

    return 0;
}

static int _fairygui_GMovieClip_setPlaying(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GMovieClip *self = nullptr;
    bool arg1 = false;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GMovieClip");
    olua_check_bool(L, 2, &arg1);

    // void setPlaying(bool value)
    self->setPlaying(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GMovieClip_setTimeScale(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GMovieClip *self = nullptr;
    lua_Number arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GMovieClip");
    olua_check_number(L, 2, &arg1);

    // void setTimeScale(float value)
    self->setTimeScale((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_fairygui_GMovieClip(lua_State *L)
{
    oluacls_class(L, "fgui.GMovieClip", "fgui.GObject");
    oluacls_func(L, "__move", _fairygui_GMovieClip___move);
    oluacls_func(L, "advance", _fairygui_GMovieClip_advance);
    oluacls_func(L, "create", _fairygui_GMovieClip_create);
    oluacls_func(L, "getColor", _fairygui_GMovieClip_getColor);
    oluacls_func(L, "getFlip", _fairygui_GMovieClip_getFlip);
    oluacls_func(L, "getFrame", _fairygui_GMovieClip_getFrame);
    oluacls_func(L, "getTimeScale", _fairygui_GMovieClip_getTimeScale);
    oluacls_func(L, "isPlaying", _fairygui_GMovieClip_isPlaying);
    oluacls_func(L, "new", _fairygui_GMovieClip_new);
    oluacls_func(L, "setColor", _fairygui_GMovieClip_setColor);
    oluacls_func(L, "setFlip", _fairygui_GMovieClip_setFlip);
    oluacls_func(L, "setFrame", _fairygui_GMovieClip_setFrame);
    oluacls_func(L, "setPlaySettings", _fairygui_GMovieClip_setPlaySettings);
    oluacls_func(L, "setPlaying", _fairygui_GMovieClip_setPlaying);
    oluacls_func(L, "setTimeScale", _fairygui_GMovieClip_setTimeScale);
    oluacls_prop(L, "color", _fairygui_GMovieClip_getColor, _fairygui_GMovieClip_setColor);
    oluacls_prop(L, "flip", _fairygui_GMovieClip_getFlip, _fairygui_GMovieClip_setFlip);
    oluacls_prop(L, "frame", _fairygui_GMovieClip_getFrame, _fairygui_GMovieClip_setFrame);
    oluacls_prop(L, "playing", _fairygui_GMovieClip_isPlaying, _fairygui_GMovieClip_setPlaying);
    oluacls_prop(L, "timeScale", _fairygui_GMovieClip_getTimeScale, _fairygui_GMovieClip_setTimeScale);

    olua_registerluatype<fairygui::GMovieClip>(L, "fgui.GMovieClip");

    return 1;
}

static int _fairygui_GProgressBar___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (fairygui::GProgressBar *)olua_toobj(L, 1, "fgui.GProgressBar");
    olua_push_cppobj(L, self, "fgui.GProgressBar");

    olua_endinvoke(L);

    return 1;
}

static int _fairygui_GProgressBar_create(lua_State *L)
{
    olua_startinvoke(L);

    // static fairygui::GProgressBar *create()
    fairygui::GProgressBar *ret = (fairygui::GProgressBar *)fairygui::GProgressBar::create();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GProgressBar");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GProgressBar_getMax(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GProgressBar *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GProgressBar");

    // double getMax()
    double ret = (double)self->getMax();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GProgressBar_getMin(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GProgressBar *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GProgressBar");

    // double getMin()
    double ret = (double)self->getMin();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GProgressBar_getTitleType(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GProgressBar *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GProgressBar");

    // fairygui::ProgressTitleType getTitleType()
    fairygui::ProgressTitleType ret = (fairygui::ProgressTitleType)self->getTitleType();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GProgressBar_getValue(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GProgressBar *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GProgressBar");

    // double getValue()
    double ret = (double)self->getValue();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GProgressBar_new(lua_State *L)
{
    olua_startinvoke(L);

    // GProgressBar()
    fairygui::GProgressBar *ret = (fairygui::GProgressBar *)new fairygui::GProgressBar();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GProgressBar");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GProgressBar_setMax(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GProgressBar *self = nullptr;
    lua_Number arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GProgressBar");
    olua_check_number(L, 2, &arg1);

    // void setMax(double value)
    self->setMax((double)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GProgressBar_setMin(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GProgressBar *self = nullptr;
    lua_Number arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GProgressBar");
    olua_check_number(L, 2, &arg1);

    // void setMin(double value)
    self->setMin((double)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GProgressBar_setTitleType(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GProgressBar *self = nullptr;
    lua_Unsigned arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GProgressBar");
    olua_check_uint(L, 2, &arg1);

    // void setTitleType(fairygui::ProgressTitleType value)
    self->setTitleType((fairygui::ProgressTitleType)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GProgressBar_setValue(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GProgressBar *self = nullptr;
    lua_Number arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GProgressBar");
    olua_check_number(L, 2, &arg1);

    // void setValue(double value)
    self->setValue((double)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GProgressBar_tweenValue(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GProgressBar *self = nullptr;
    lua_Number arg1 = 0;       /** value */
    lua_Number arg2 = 0;       /** duration */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GProgressBar");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);

    // void tweenValue(double value, float duration)
    self->tweenValue((double)arg1, (float)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GProgressBar_update(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GProgressBar *self = nullptr;
    lua_Number arg1 = 0;       /** newValue */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GProgressBar");
    olua_check_number(L, 2, &arg1);

    // void update(double newValue)
    self->update((double)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_fairygui_GProgressBar(lua_State *L)
{
    oluacls_class(L, "fgui.GProgressBar", "fgui.GComponent");
    oluacls_func(L, "__move", _fairygui_GProgressBar___move);
    oluacls_func(L, "create", _fairygui_GProgressBar_create);
    oluacls_func(L, "getMax", _fairygui_GProgressBar_getMax);
    oluacls_func(L, "getMin", _fairygui_GProgressBar_getMin);
    oluacls_func(L, "getTitleType", _fairygui_GProgressBar_getTitleType);
    oluacls_func(L, "getValue", _fairygui_GProgressBar_getValue);
    oluacls_func(L, "new", _fairygui_GProgressBar_new);
    oluacls_func(L, "setMax", _fairygui_GProgressBar_setMax);
    oluacls_func(L, "setMin", _fairygui_GProgressBar_setMin);
    oluacls_func(L, "setTitleType", _fairygui_GProgressBar_setTitleType);
    oluacls_func(L, "setValue", _fairygui_GProgressBar_setValue);
    oluacls_func(L, "tweenValue", _fairygui_GProgressBar_tweenValue);
    oluacls_func(L, "update", _fairygui_GProgressBar_update);
    oluacls_prop(L, "max", _fairygui_GProgressBar_getMax, _fairygui_GProgressBar_setMax);
    oluacls_prop(L, "min", _fairygui_GProgressBar_getMin, _fairygui_GProgressBar_setMin);
    oluacls_prop(L, "titleType", _fairygui_GProgressBar_getTitleType, _fairygui_GProgressBar_setTitleType);
    oluacls_prop(L, "value", _fairygui_GProgressBar_getValue, _fairygui_GProgressBar_setValue);

    olua_registerluatype<fairygui::GProgressBar>(L, "fgui.GProgressBar");

    return 1;
}

static int _fairygui_GComboBox___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (fairygui::GComboBox *)olua_toobj(L, 1, "fgui.GComboBox");
    olua_push_cppobj(L, self, "fgui.GComboBox");

    olua_endinvoke(L);

    return 1;
}

static int _fairygui_GComboBox_create(lua_State *L)
{
    olua_startinvoke(L);

    // static fairygui::GComboBox *create()
    fairygui::GComboBox *ret = (fairygui::GComboBox *)fairygui::GComboBox::create();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GComboBox");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GComboBox_getDropdown(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComboBox *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GComboBox");

    // @addref(dropdown ^) fairygui::GObject *getDropdown()
    fairygui::GObject *ret = (fairygui::GObject *)self->getDropdown();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GObject");

    // inject code after call
    olua_addref(L, 1, "dropdown", -1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GComboBox_getIcons(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComboBox *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GComboBox");

    // std::vector<std::string> &getIcons()
    std::vector<std::string> &ret = (std::vector<std::string> &)self->getIcons();
    int num_ret = 1;
    int ret_size = (int)ret.size();
    lua_createtable(L, ret_size, 0);
    for (int i = 0; i < ret_size; i++) {
        olua_push_std_string(L, ((std::vector<std::string> &)ret)[i]);
        lua_rawseti(L, -2, i + 1);
    }

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GComboBox_getItems(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComboBox *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GComboBox");

    // std::vector<std::string> &getItems()
    std::vector<std::string> &ret = (std::vector<std::string> &)self->getItems();
    int num_ret = 1;
    int ret_size = (int)ret.size();
    lua_createtable(L, ret_size, 0);
    for (int i = 0; i < ret_size; i++) {
        olua_push_std_string(L, ((std::vector<std::string> &)ret)[i]);
        lua_rawseti(L, -2, i + 1);
    }

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GComboBox_getSelectedIndex(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComboBox *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GComboBox");

    // int getSelectedIndex()
    int ret = (int)self->getSelectedIndex();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GComboBox_getSelectionController(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComboBox *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GComboBox");

    // @addref(selectionController ^) fairygui::GController *getSelectionController()
    fairygui::GController *ret = (fairygui::GController *)self->getSelectionController();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GController");

    // inject code after call
    olua_addref(L, 1, "selectionController", -1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GComboBox_getTextField(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComboBox *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GComboBox");

    // @addref(textField ^) fairygui::GTextField *getTextField()
    fairygui::GTextField *ret = (fairygui::GTextField *)self->getTextField();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GTextField");

    // inject code after call
    olua_addref(L, 1, "textField", -1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GComboBox_getTitle(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComboBox *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GComboBox");

    // const std::string &getTitle()
    const std::string &ret = (const std::string &)self->getTitle();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GComboBox_getTitleColor(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComboBox *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GComboBox");

    // const cocos2d::Color3B getTitleColor()
    const cocos2d::Color3B ret = (const cocos2d::Color3B)self->getTitleColor();
    int num_ret = manual_olua_push_cocos2d_Color3B(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GComboBox_getTitleFontSize(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComboBox *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GComboBox");

    // int getTitleFontSize()
    int ret = (int)self->getTitleFontSize();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GComboBox_getValue(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComboBox *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GComboBox");

    // const std::string &getValue()
    const std::string &ret = (const std::string &)self->getValue();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GComboBox_getValues(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComboBox *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GComboBox");

    // std::vector<std::string> &getValues()
    std::vector<std::string> &ret = (std::vector<std::string> &)self->getValues();
    int num_ret = 1;
    int ret_size = (int)ret.size();
    lua_createtable(L, ret_size, 0);
    for (int i = 0; i < ret_size; i++) {
        olua_push_std_string(L, ((std::vector<std::string> &)ret)[i]);
        lua_rawseti(L, -2, i + 1);
    }

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GComboBox_new(lua_State *L)
{
    olua_startinvoke(L);

    // GComboBox()
    fairygui::GComboBox *ret = (fairygui::GComboBox *)new fairygui::GComboBox();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GComboBox");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GComboBox_refresh(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComboBox *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GComboBox");

    // void refresh()
    self->refresh();

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GComboBox_setSelectedIndex(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComboBox *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GComboBox");
    olua_check_int(L, 2, &arg1);

    // void setSelectedIndex(int value)
    self->setSelectedIndex((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GComboBox_setSelectionController(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComboBox *self = nullptr;
    fairygui::GController *arg1 = nullptr;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GComboBox");
    olua_check_cppobj(L, 2, (void **)&arg1, "fgui.GController");

    // void setSelectionController(@addref(selectionController ^) fairygui::GController *value)
    self->setSelectionController(arg1);

    // inject code after call
    olua_addref(L, 1, "selectionController", 2, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GComboBox_setTitle(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComboBox *self = nullptr;
    std::string arg1;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GComboBox");
    olua_check_std_string(L, 2, &arg1);

    // void setTitle(const std::string &value)
    self->setTitle(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GComboBox_setTitleColor(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComboBox *self = nullptr;
    cocos2d::Color3B arg1;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GComboBox");
    manual_olua_check_cocos2d_Color3B(L, 2, &arg1);

    // void setTitleColor(const cocos2d::Color3B &value)
    self->setTitleColor(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GComboBox_setTitleFontSize(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComboBox *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GComboBox");
    olua_check_int(L, 2, &arg1);

    // void setTitleFontSize(int value)
    self->setTitleFontSize((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GComboBox_setValue(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComboBox *self = nullptr;
    std::string arg1;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GComboBox");
    olua_check_std_string(L, 2, &arg1);

    // void setValue(const std::string &value)
    self->setValue(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GComboBox_get_popupDirection(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComboBox *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GComboBox");

    // fairygui::PopupDirection popupDirection
    fairygui::PopupDirection ret = (fairygui::PopupDirection)self->popupDirection;
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GComboBox_set_popupDirection(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComboBox *self = nullptr;
    lua_Unsigned arg1 = 0;       /** popupDirection */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GComboBox");
    olua_check_uint(L, 2, &arg1);

    // fairygui::PopupDirection popupDirection
    self->popupDirection = (fairygui::PopupDirection)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GComboBox_get_visibleItemCount(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComboBox *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GComboBox");

    // int visibleItemCount
    int ret = (int)self->visibleItemCount;
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GComboBox_set_visibleItemCount(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComboBox *self = nullptr;
    lua_Integer arg1 = 0;       /** visibleItemCount */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GComboBox");
    olua_check_int(L, 2, &arg1);

    // int visibleItemCount
    self->visibleItemCount = (int)arg1;

    olua_endinvoke(L);

    return 0;
}

static int luaopen_fairygui_GComboBox(lua_State *L)
{
    oluacls_class(L, "fgui.GComboBox", "fgui.GComponent");
    oluacls_func(L, "__move", _fairygui_GComboBox___move);
    oluacls_func(L, "create", _fairygui_GComboBox_create);
    oluacls_func(L, "getDropdown", _fairygui_GComboBox_getDropdown);
    oluacls_func(L, "getIcons", _fairygui_GComboBox_getIcons);
    oluacls_func(L, "getItems", _fairygui_GComboBox_getItems);
    oluacls_func(L, "getSelectedIndex", _fairygui_GComboBox_getSelectedIndex);
    oluacls_func(L, "getSelectionController", _fairygui_GComboBox_getSelectionController);
    oluacls_func(L, "getTextField", _fairygui_GComboBox_getTextField);
    oluacls_func(L, "getTitle", _fairygui_GComboBox_getTitle);
    oluacls_func(L, "getTitleColor", _fairygui_GComboBox_getTitleColor);
    oluacls_func(L, "getTitleFontSize", _fairygui_GComboBox_getTitleFontSize);
    oluacls_func(L, "getValue", _fairygui_GComboBox_getValue);
    oluacls_func(L, "getValues", _fairygui_GComboBox_getValues);
    oluacls_func(L, "new", _fairygui_GComboBox_new);
    oluacls_func(L, "refresh", _fairygui_GComboBox_refresh);
    oluacls_func(L, "setSelectedIndex", _fairygui_GComboBox_setSelectedIndex);
    oluacls_func(L, "setSelectionController", _fairygui_GComboBox_setSelectionController);
    oluacls_func(L, "setTitle", _fairygui_GComboBox_setTitle);
    oluacls_func(L, "setTitleColor", _fairygui_GComboBox_setTitleColor);
    oluacls_func(L, "setTitleFontSize", _fairygui_GComboBox_setTitleFontSize);
    oluacls_func(L, "setValue", _fairygui_GComboBox_setValue);
    oluacls_prop(L, "dropdown", _fairygui_GComboBox_getDropdown, nullptr);
    oluacls_prop(L, "icons", _fairygui_GComboBox_getIcons, nullptr);
    oluacls_prop(L, "items", _fairygui_GComboBox_getItems, nullptr);
    oluacls_prop(L, "selectedIndex", _fairygui_GComboBox_getSelectedIndex, _fairygui_GComboBox_setSelectedIndex);
    oluacls_prop(L, "selectionController", _fairygui_GComboBox_getSelectionController, _fairygui_GComboBox_setSelectionController);
    oluacls_prop(L, "textField", _fairygui_GComboBox_getTextField, nullptr);
    oluacls_prop(L, "title", _fairygui_GComboBox_getTitle, _fairygui_GComboBox_setTitle);
    oluacls_prop(L, "titleColor", _fairygui_GComboBox_getTitleColor, _fairygui_GComboBox_setTitleColor);
    oluacls_prop(L, "titleFontSize", _fairygui_GComboBox_getTitleFontSize, _fairygui_GComboBox_setTitleFontSize);
    oluacls_prop(L, "value", _fairygui_GComboBox_getValue, _fairygui_GComboBox_setValue);
    oluacls_prop(L, "values", _fairygui_GComboBox_getValues, nullptr);
    oluacls_prop(L, "popupDirection", _fairygui_GComboBox_get_popupDirection, _fairygui_GComboBox_set_popupDirection);
    oluacls_prop(L, "visibleItemCount", _fairygui_GComboBox_get_visibleItemCount, _fairygui_GComboBox_set_visibleItemCount);

    olua_registerluatype<fairygui::GComboBox>(L, "fgui.GComboBox");

    return 1;
}

static int _fairygui_GRichTextField___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (fairygui::GRichTextField *)olua_toobj(L, 1, "fgui.GRichTextField");
    olua_push_cppobj(L, self, "fgui.GRichTextField");

    olua_endinvoke(L);

    return 1;
}

static int _fairygui_GRichTextField_create(lua_State *L)
{
    olua_startinvoke(L);

    // static fairygui::GRichTextField *create()
    fairygui::GRichTextField *ret = (fairygui::GRichTextField *)fairygui::GRichTextField::create();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GRichTextField");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GRichTextField_new(lua_State *L)
{
    olua_startinvoke(L);

    // GRichTextField()
    fairygui::GRichTextField *ret = (fairygui::GRichTextField *)new fairygui::GRichTextField();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GRichTextField");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_fairygui_GRichTextField(lua_State *L)
{
    oluacls_class(L, "fgui.GRichTextField", "fgui.GTextField");
    oluacls_func(L, "__move", _fairygui_GRichTextField___move);
    oluacls_func(L, "create", _fairygui_GRichTextField_create);
    oluacls_func(L, "new", _fairygui_GRichTextField_new);

    olua_registerluatype<fairygui::GRichTextField>(L, "fgui.GRichTextField");

    return 1;
}

static int _fairygui_GSlider___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (fairygui::GSlider *)olua_toobj(L, 1, "fgui.GSlider");
    olua_push_cppobj(L, self, "fgui.GSlider");

    olua_endinvoke(L);

    return 1;
}

static int _fairygui_GSlider_create(lua_State *L)
{
    olua_startinvoke(L);

    // static fairygui::GSlider *create()
    fairygui::GSlider *ret = (fairygui::GSlider *)fairygui::GSlider::create();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GSlider");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GSlider_getMax(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GSlider *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GSlider");

    // double getMax()
    double ret = (double)self->getMax();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GSlider_getMin(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GSlider *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GSlider");

    // double getMin()
    double ret = (double)self->getMin();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GSlider_getTitleType(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GSlider *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GSlider");

    // fairygui::ProgressTitleType getTitleType()
    fairygui::ProgressTitleType ret = (fairygui::ProgressTitleType)self->getTitleType();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GSlider_getValue(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GSlider *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GSlider");

    // double getValue()
    double ret = (double)self->getValue();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GSlider_getWholeNumbers(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GSlider *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GSlider");

    // bool getWholeNumbers()
    bool ret = (bool)self->getWholeNumbers();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GSlider_new(lua_State *L)
{
    olua_startinvoke(L);

    // GSlider()
    fairygui::GSlider *ret = (fairygui::GSlider *)new fairygui::GSlider();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GSlider");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GSlider_setMax(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GSlider *self = nullptr;
    lua_Number arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GSlider");
    olua_check_number(L, 2, &arg1);

    // void setMax(double value)
    self->setMax((double)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GSlider_setMin(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GSlider *self = nullptr;
    lua_Number arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GSlider");
    olua_check_number(L, 2, &arg1);

    // void setMin(double value)
    self->setMin((double)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GSlider_setTitleType(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GSlider *self = nullptr;
    lua_Unsigned arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GSlider");
    olua_check_uint(L, 2, &arg1);

    // void setTitleType(fairygui::ProgressTitleType value)
    self->setTitleType((fairygui::ProgressTitleType)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GSlider_setValue(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GSlider *self = nullptr;
    lua_Number arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GSlider");
    olua_check_number(L, 2, &arg1);

    // void setValue(double value)
    self->setValue((double)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GSlider_setWholeNumbers(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GSlider *self = nullptr;
    bool arg1 = false;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GSlider");
    olua_check_bool(L, 2, &arg1);

    // void setWholeNumbers(bool value)
    self->setWholeNumbers(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GSlider_get_canDrag(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GSlider *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GSlider");

    // bool canDrag
    bool ret = (bool)self->canDrag;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GSlider_set_canDrag(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GSlider *self = nullptr;
    bool arg1 = false;       /** canDrag */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GSlider");
    olua_check_bool(L, 2, &arg1);

    // bool canDrag
    self->canDrag = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GSlider_get_changeOnClick(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GSlider *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GSlider");

    // bool changeOnClick
    bool ret = (bool)self->changeOnClick;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GSlider_set_changeOnClick(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GSlider *self = nullptr;
    bool arg1 = false;       /** changeOnClick */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GSlider");
    olua_check_bool(L, 2, &arg1);

    // bool changeOnClick
    self->changeOnClick = arg1;

    olua_endinvoke(L);

    return 0;
}

static int luaopen_fairygui_GSlider(lua_State *L)
{
    oluacls_class(L, "fgui.GSlider", "fgui.GComponent");
    oluacls_func(L, "__move", _fairygui_GSlider___move);
    oluacls_func(L, "create", _fairygui_GSlider_create);
    oluacls_func(L, "getMax", _fairygui_GSlider_getMax);
    oluacls_func(L, "getMin", _fairygui_GSlider_getMin);
    oluacls_func(L, "getTitleType", _fairygui_GSlider_getTitleType);
    oluacls_func(L, "getValue", _fairygui_GSlider_getValue);
    oluacls_func(L, "getWholeNumbers", _fairygui_GSlider_getWholeNumbers);
    oluacls_func(L, "new", _fairygui_GSlider_new);
    oluacls_func(L, "setMax", _fairygui_GSlider_setMax);
    oluacls_func(L, "setMin", _fairygui_GSlider_setMin);
    oluacls_func(L, "setTitleType", _fairygui_GSlider_setTitleType);
    oluacls_func(L, "setValue", _fairygui_GSlider_setValue);
    oluacls_func(L, "setWholeNumbers", _fairygui_GSlider_setWholeNumbers);
    oluacls_prop(L, "max", _fairygui_GSlider_getMax, _fairygui_GSlider_setMax);
    oluacls_prop(L, "min", _fairygui_GSlider_getMin, _fairygui_GSlider_setMin);
    oluacls_prop(L, "titleType", _fairygui_GSlider_getTitleType, _fairygui_GSlider_setTitleType);
    oluacls_prop(L, "value", _fairygui_GSlider_getValue, _fairygui_GSlider_setValue);
    oluacls_prop(L, "wholeNumbers", _fairygui_GSlider_getWholeNumbers, _fairygui_GSlider_setWholeNumbers);
    oluacls_prop(L, "canDrag", _fairygui_GSlider_get_canDrag, _fairygui_GSlider_set_canDrag);
    oluacls_prop(L, "changeOnClick", _fairygui_GSlider_get_changeOnClick, _fairygui_GSlider_set_changeOnClick);

    olua_registerluatype<fairygui::GSlider>(L, "fgui.GSlider");

    return 1;
}

static int _fairygui_GTextInput___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (fairygui::GTextInput *)olua_toobj(L, 1, "fgui.GTextInput");
    olua_push_cppobj(L, self, "fgui.GTextInput");

    olua_endinvoke(L);

    return 1;
}

static int _fairygui_GTextInput_create(lua_State *L)
{
    olua_startinvoke(L);

    // static fairygui::GTextInput *create()
    fairygui::GTextInput *ret = (fairygui::GTextInput *)fairygui::GTextInput::create();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GTextInput");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTextInput_new(lua_State *L)
{
    olua_startinvoke(L);

    // GTextInput()
    fairygui::GTextInput *ret = (fairygui::GTextInput *)new fairygui::GTextInput();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GTextInput");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTextInput_setKeyboardType(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTextInput *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTextInput");
    olua_check_int(L, 2, &arg1);

    // void setKeyboardType(int value)
    self->setKeyboardType((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GTextInput_setMaxLength(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTextInput *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTextInput");
    olua_check_int(L, 2, &arg1);

    // void setMaxLength(int value)
    self->setMaxLength((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GTextInput_setPassword(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTextInput *self = nullptr;
    bool arg1 = false;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTextInput");
    olua_check_bool(L, 2, &arg1);

    // void setPassword(bool value)
    self->setPassword(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GTextInput_setPrompt(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTextInput *self = nullptr;
    std::string arg1;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTextInput");
    olua_check_std_string(L, 2, &arg1);

    // void setPrompt(const std::string &value)
    self->setPrompt(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GTextInput_setRestrict(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTextInput *self = nullptr;
    std::string arg1;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTextInput");
    olua_check_std_string(L, 2, &arg1);

    // void setRestrict(const std::string &value)
    self->setRestrict(arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_fairygui_GTextInput(lua_State *L)
{
    oluacls_class(L, "fgui.GTextInput", "fgui.GTextField");
    oluacls_func(L, "__move", _fairygui_GTextInput___move);
    oluacls_func(L, "create", _fairygui_GTextInput_create);
    oluacls_func(L, "new", _fairygui_GTextInput_new);
    oluacls_func(L, "setKeyboardType", _fairygui_GTextInput_setKeyboardType);
    oluacls_func(L, "setMaxLength", _fairygui_GTextInput_setMaxLength);
    oluacls_func(L, "setPassword", _fairygui_GTextInput_setPassword);
    oluacls_func(L, "setPrompt", _fairygui_GTextInput_setPrompt);
    oluacls_func(L, "setRestrict", _fairygui_GTextInput_setRestrict);

    olua_registerluatype<fairygui::GTextInput>(L, "fgui.GTextInput");

    return 1;
}

static int _fairygui_PopupMenu___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (fairygui::PopupMenu *)olua_toobj(L, 1, "fgui.PopupMenu");
    olua_push_cppobj(L, self, "fgui.PopupMenu");

    olua_endinvoke(L);

    return 1;
}

static int _fairygui_PopupMenu_addItem(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::PopupMenu *self = nullptr;
    std::string arg1;       /** caption */
    std::function<void(fairygui::EventContext *)> arg2;       /** callback */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.PopupMenu");
    olua_check_std_string(L, 2, &arg1);

    // inject code before call
    olua_push_cppobj<fairygui::GList>(L, self->getList());
    int parent = lua_gettop(L);

    void *self_obj = (void *)olua_newobjstub(L, "fgui.GButton");
    std::string tag = makeListenerTag(L, fairygui::UIEventType::ClickMenu, 0);
    std::string func = olua_setcallback(L, self_obj, tag.c_str(), 3, OLUA_TAG_REPLACE);
    lua_Unsigned ctx = olua_context(L);
    arg2 = [self_obj, func, ctx](fairygui::EventContext *arg1) {
        lua_State *L = olua_mainthread(NULL);

        if (L != NULL && (olua_context(L) == ctx)) {
            int top = lua_gettop(L);
            size_t last = olua_push_objpool(L);
            olua_enable_objpool(L);
            olua_push_cppobj(L, arg1, "fgui.EventContext");
            olua_disable_objpool(L);

            olua_callback(L, self_obj, func.c_str(), 1);

            //pop stack value
            olua_pop_objpool(L, last);
            lua_settop(L, top);
        }
    };

    // @addref(children | parent) fairygui::GButton *addItem(const std::string &caption, @local std::function<void (EventContext *)> callback)
    fairygui::GButton *ret = (fairygui::GButton *)self->addItem(arg1, arg2);
    const char *cls = olua_getluatype(L, ret, "fgui.GButton");
    if (olua_pushobjstub(L, ret, self_obj, cls) == OLUA_OBJ_EXIST) {
        olua_removecallback(L, self_obj, tag.c_str(), OLUA_TAG_SUBEQUAL);
        lua_pushstring(L, func.c_str());
        lua_pushvalue(L, 3);
        olua_setvariable(L, -3);
    } else {
        olua_postpush(L, ret, OLUA_OBJ_NEW);
    };

    // inject code after call
    olua_addref(L, parent, "children", -1, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return 1;
}

static int _fairygui_PopupMenu_addItemAt(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::PopupMenu *self = nullptr;
    std::string arg1;       /** caption */
    lua_Integer arg2 = 0;       /** index */
    std::function<void(fairygui::EventContext *)> arg3;       /** callback */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.PopupMenu");
    olua_check_std_string(L, 2, &arg1);
    olua_check_int(L, 3, &arg2);

    // inject code before call
    olua_push_cppobj<fairygui::GList>(L, self->getList());
    int parent = lua_gettop(L);

    void *self_obj = (void *)olua_newobjstub(L, "fgui.GButton");
    std::string tag = makeListenerTag(L, fairygui::UIEventType::ClickMenu, 0);
    std::string func = olua_setcallback(L, self_obj, tag.c_str(), 4, OLUA_TAG_REPLACE);
    lua_Unsigned ctx = olua_context(L);
    arg3 = [self_obj, func, ctx](fairygui::EventContext *arg1) {
        lua_State *L = olua_mainthread(NULL);

        if (L != NULL && (olua_context(L) == ctx)) {
            int top = lua_gettop(L);
            size_t last = olua_push_objpool(L);
            olua_enable_objpool(L);
            olua_push_cppobj(L, arg1, "fgui.EventContext");
            olua_disable_objpool(L);

            olua_callback(L, self_obj, func.c_str(), 1);

            //pop stack value
            olua_pop_objpool(L, last);
            lua_settop(L, top);
        }
    };

    // @addref(children | parent) fairygui::GButton *addItemAt(const std::string &caption, int index, @local std::function<void (EventContext *)> callback)
    fairygui::GButton *ret = (fairygui::GButton *)self->addItemAt(arg1, (int)arg2, arg3);
    const char *cls = olua_getluatype(L, ret, "fgui.GButton");
    if (olua_pushobjstub(L, ret, self_obj, cls) == OLUA_OBJ_EXIST) {
        olua_removecallback(L, self_obj, tag.c_str(), OLUA_TAG_SUBEQUAL);
        lua_pushstring(L, func.c_str());
        lua_pushvalue(L, 4);
        olua_setvariable(L, -3);
    } else {
        olua_postpush(L, ret, OLUA_OBJ_NEW);
    };

    // inject code after call
    olua_addref(L, parent, "children", -1, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return 1;
}

static int _fairygui_PopupMenu_addSeperator(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::PopupMenu *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.PopupMenu");

    // void addSeperator()
    self->addSeperator();

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_PopupMenu_clearItems(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::PopupMenu *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.PopupMenu");

    // inject code before call
    olua_push_cppobj<fairygui::GList>(L, self->getList());
    int parent = lua_gettop(L);
    olua_startcmpdelref(L, parent, "children");

    // @delref(children ~ parent) void clearItems()
    self->clearItems();

    // inject code after call
    olua_endcmpdelref(L, parent, "children");

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_PopupMenu_create1(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** resourceURL */

    olua_check_std_string(L, 1, &arg1);

    // static fairygui::PopupMenu *create(const std::string &resourceURL)
    fairygui::PopupMenu *ret = (fairygui::PopupMenu *)fairygui::PopupMenu::create(arg1);
    int num_ret = olua_push_cppobj(L, ret, "fgui.PopupMenu");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_PopupMenu_create2(lua_State *L)
{
    olua_startinvoke(L);

    // static fairygui::PopupMenu *create()
    fairygui::PopupMenu *ret = (fairygui::PopupMenu *)fairygui::PopupMenu::create();
    int num_ret = olua_push_cppobj(L, ret, "fgui.PopupMenu");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_PopupMenu_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // static fairygui::PopupMenu *create()
        return _fairygui_PopupMenu_create2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 1))) {
            // static fairygui::PopupMenu *create(const std::string &resourceURL)
            return _fairygui_PopupMenu_create1(L);
        // }
    }

    luaL_error(L, "method 'fairygui::PopupMenu::create' not support '%d' arguments", num_args);

    return 0;
}

static int _fairygui_PopupMenu_getContentPane(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::PopupMenu *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.PopupMenu");

    // @addref(contentPane ^) fairygui::GComponent *getContentPane()
    fairygui::GComponent *ret = (fairygui::GComponent *)self->getContentPane();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GComponent");

    // inject code after call
    olua_addref(L, 1, "contentPane", -1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_PopupMenu_getItemCount(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::PopupMenu *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.PopupMenu");

    // int getItemCount()
    int ret = (int)self->getItemCount();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_PopupMenu_getItemName(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::PopupMenu *self = nullptr;
    lua_Integer arg1 = 0;       /** index */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.PopupMenu");
    olua_check_int(L, 2, &arg1);

    // const std::string &getItemName(int index)
    const std::string &ret = (const std::string &)self->getItemName((int)arg1);
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_PopupMenu_getList(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::PopupMenu *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.PopupMenu");

    // @addref(list ^) fairygui::GList *getList()
    fairygui::GList *ret = (fairygui::GList *)self->getList();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GList");

    // inject code after call
    olua_addref(L, 1, "list", -1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_PopupMenu_isItemChecked(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::PopupMenu *self = nullptr;
    std::string arg1;       /** name */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.PopupMenu");
    olua_check_std_string(L, 2, &arg1);

    // bool isItemChecked(const std::string &name)
    bool ret = (bool)self->isItemChecked(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_PopupMenu_new(lua_State *L)
{
    olua_startinvoke(L);

    // PopupMenu()
    fairygui::PopupMenu *ret = (fairygui::PopupMenu *)new fairygui::PopupMenu();
    int num_ret = olua_push_cppobj(L, ret, "fgui.PopupMenu");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_PopupMenu_removeItem(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::PopupMenu *self = nullptr;
    std::string arg1;       /** name */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.PopupMenu");
    olua_check_std_string(L, 2, &arg1);

    // inject code before call
    olua_push_cppobj<fairygui::GList>(L, self->getList());
    int parent = lua_gettop(L);
    olua_startcmpdelref(L, parent, "children");

    // @delref(children ~ parent) bool removeItem(const std::string &name)
    bool ret = (bool)self->removeItem(arg1);
    int num_ret = olua_push_bool(L, ret);

    // inject code after call
    olua_endcmpdelref(L, parent, "children");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_PopupMenu_setItemCheckable(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::PopupMenu *self = nullptr;
    std::string arg1;       /** name */
    bool arg2 = false;       /** checkable */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.PopupMenu");
    olua_check_std_string(L, 2, &arg1);
    olua_check_bool(L, 3, &arg2);

    // void setItemCheckable(const std::string &name, bool checkable)
    self->setItemCheckable(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_PopupMenu_setItemChecked(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::PopupMenu *self = nullptr;
    std::string arg1;       /** name */
    bool arg2 = false;       /** check */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.PopupMenu");
    olua_check_std_string(L, 2, &arg1);
    olua_check_bool(L, 3, &arg2);

    // void setItemChecked(const std::string &name, bool check)
    self->setItemChecked(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_PopupMenu_setItemGrayed(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::PopupMenu *self = nullptr;
    std::string arg1;       /** name */
    bool arg2 = false;       /** grayed */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.PopupMenu");
    olua_check_std_string(L, 2, &arg1);
    olua_check_bool(L, 3, &arg2);

    // void setItemGrayed(const std::string &name, bool grayed)
    self->setItemGrayed(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_PopupMenu_setItemText(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::PopupMenu *self = nullptr;
    std::string arg1;       /** name */
    std::string arg2;       /** caption */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.PopupMenu");
    olua_check_std_string(L, 2, &arg1);
    olua_check_std_string(L, 3, &arg2);

    // void setItemText(const std::string &name, const std::string &caption)
    self->setItemText(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_PopupMenu_setItemVisible(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::PopupMenu *self = nullptr;
    std::string arg1;       /** name */
    bool arg2 = false;       /** visible */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.PopupMenu");
    olua_check_std_string(L, 2, &arg1);
    olua_check_bool(L, 3, &arg2);

    // void setItemVisible(const std::string &name, bool visible)
    self->setItemVisible(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_PopupMenu_show1(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::PopupMenu *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.PopupMenu");

    // inject code before call
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
    olua_startcmpdelref(L, parent, "children");

    // @delref(children ~ parent)@addref(children | parent) void show()
    self->show();

    // inject code after call
    olua_addref(L, parent, "children", 1, OLUA_MODE_MULTIPLE);
    olua_endcmpdelref(L, parent, "children");

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_PopupMenu_show2(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::PopupMenu *self = nullptr;
    fairygui::GObject *arg1 = nullptr;       /** target */
    lua_Unsigned arg2 = 0;       /** dir */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.PopupMenu");
    olua_check_cppobj(L, 2, (void **)&arg1, "fgui.GObject");
    olua_check_uint(L, 3, &arg2);

    // inject code before call
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
    olua_startcmpdelref(L, parent, "children");

    // @delref(children ~ parent)@addref(children | parent) void show(fairygui::GObject *target, fairygui::PopupDirection dir)
    self->show(arg1, (fairygui::PopupDirection)arg2);

    // inject code after call
    olua_addref(L, parent, "children", 1, OLUA_MODE_MULTIPLE);
    olua_endcmpdelref(L, parent, "children");

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_PopupMenu_show(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // @delref(children ~ parent)@addref(children | parent) void show()
        return _fairygui_PopupMenu_show1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_cppobj(L, 2, "fgui.GObject")) && (olua_is_uint(L, 3))) {
            // @delref(children ~ parent)@addref(children | parent) void show(fairygui::GObject *target, fairygui::PopupDirection dir)
            return _fairygui_PopupMenu_show2(L);
        // }
    }

    luaL_error(L, "method 'fairygui::PopupMenu::show' not support '%d' arguments", num_args);

    return 0;
}

static int luaopen_fairygui_PopupMenu(lua_State *L)
{
    oluacls_class(L, "fgui.PopupMenu", "cc.Ref");
    oluacls_func(L, "__move", _fairygui_PopupMenu___move);
    oluacls_func(L, "addItem", _fairygui_PopupMenu_addItem);
    oluacls_func(L, "addItemAt", _fairygui_PopupMenu_addItemAt);
    oluacls_func(L, "addSeperator", _fairygui_PopupMenu_addSeperator);
    oluacls_func(L, "clearItems", _fairygui_PopupMenu_clearItems);
    oluacls_func(L, "create", _fairygui_PopupMenu_create);
    oluacls_func(L, "getContentPane", _fairygui_PopupMenu_getContentPane);
    oluacls_func(L, "getItemCount", _fairygui_PopupMenu_getItemCount);
    oluacls_func(L, "getItemName", _fairygui_PopupMenu_getItemName);
    oluacls_func(L, "getList", _fairygui_PopupMenu_getList);
    oluacls_func(L, "isItemChecked", _fairygui_PopupMenu_isItemChecked);
    oluacls_func(L, "new", _fairygui_PopupMenu_new);
    oluacls_func(L, "removeItem", _fairygui_PopupMenu_removeItem);
    oluacls_func(L, "setItemCheckable", _fairygui_PopupMenu_setItemCheckable);
    oluacls_func(L, "setItemChecked", _fairygui_PopupMenu_setItemChecked);
    oluacls_func(L, "setItemGrayed", _fairygui_PopupMenu_setItemGrayed);
    oluacls_func(L, "setItemText", _fairygui_PopupMenu_setItemText);
    oluacls_func(L, "setItemVisible", _fairygui_PopupMenu_setItemVisible);
    oluacls_func(L, "show", _fairygui_PopupMenu_show);
    oluacls_prop(L, "contentPane", _fairygui_PopupMenu_getContentPane, nullptr);
    oluacls_prop(L, "itemCount", _fairygui_PopupMenu_getItemCount, nullptr);
    oluacls_prop(L, "list", _fairygui_PopupMenu_getList, nullptr);

    olua_registerluatype<fairygui::PopupMenu>(L, "fgui.PopupMenu");

    return 1;
}

static int _fairygui_Relations___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (fairygui::Relations *)olua_toobj(L, 1, "fgui.Relations");
    lua_pushstring(L, ".ownership");
    olua_getvariable(L, 1);
    if (lua_toboolean(L, -1)) {
        olua_setrawobj(L, 1, nullptr);
        delete self;
    }

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_Relations___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (fairygui::Relations *)olua_toobj(L, 1, "fgui.Relations");
    olua_push_cppobj(L, self, "fgui.Relations");

    olua_endinvoke(L);

    return 1;
}

static int _fairygui_Relations_add1(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::Relations *self = nullptr;
    fairygui::GObject *arg1 = nullptr;       /** target */
    lua_Unsigned arg2 = 0;       /** relationType */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.Relations");
    olua_check_cppobj(L, 2, (void **)&arg1, "fgui.GObject");
    olua_check_uint(L, 3, &arg2);

    // void add(fairygui::GObject *target, fairygui::RelationType relationType)
    self->add(arg1, (fairygui::RelationType)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_Relations_add2(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::Relations *self = nullptr;
    fairygui::GObject *arg1 = nullptr;       /** target */
    lua_Unsigned arg2 = 0;       /** relationType */
    bool arg3 = false;       /** usePercent */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.Relations");
    olua_check_cppobj(L, 2, (void **)&arg1, "fgui.GObject");
    olua_check_uint(L, 3, &arg2);
    olua_check_bool(L, 4, &arg3);

    // void add(fairygui::GObject *target, fairygui::RelationType relationType, bool usePercent)
    self->add(arg1, (fairygui::RelationType)arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_Relations_add(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 2) {
        // if ((olua_is_cppobj(L, 2, "fgui.GObject")) && (olua_is_uint(L, 3))) {
            // void add(fairygui::GObject *target, fairygui::RelationType relationType)
            return _fairygui_Relations_add1(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_cppobj(L, 2, "fgui.GObject")) && (olua_is_uint(L, 3)) && (olua_is_bool(L, 4))) {
            // void add(fairygui::GObject *target, fairygui::RelationType relationType, bool usePercent)
            return _fairygui_Relations_add2(L);
        // }
    }

    luaL_error(L, "method 'fairygui::Relations::add' not support '%d' arguments", num_args);

    return 0;
}

static int _fairygui_Relations_clearAll(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::Relations *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.Relations");

    // void clearAll()
    self->clearAll();

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_Relations_clearFor(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::Relations *self = nullptr;
    fairygui::GObject *arg1 = nullptr;       /** target */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.Relations");
    olua_check_cppobj(L, 2, (void **)&arg1, "fgui.GObject");

    // void clearFor(fairygui::GObject *target)
    self->clearFor(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_Relations_contains(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::Relations *self = nullptr;
    fairygui::GObject *arg1 = nullptr;       /** target */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.Relations");
    olua_check_cppobj(L, 2, (void **)&arg1, "fgui.GObject");

    // bool contains(fairygui::GObject *target)
    bool ret = (bool)self->contains(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_Relations_copyFrom(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::Relations *self = olua_toobj<fairygui::Relations>(L, 1);
    fairygui::Relations *source = olua_checkobj<fairygui::Relations>(L, 2);
    // void copyFrom(const Relations& source)
    self->copyFrom(*source);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_Relations_isEmpty(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::Relations *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.Relations");

    // bool isEmpty()
    bool ret = (bool)self->isEmpty();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_Relations_new(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *arg1 = nullptr;       /** owner */

    olua_check_cppobj(L, 1, (void **)&arg1, "fgui.GObject");

    // Relations(fairygui::GObject *owner)
    fairygui::Relations *ret = (fairygui::Relations *)new fairygui::Relations(arg1);
    int num_ret = olua_push_cppobj(L, ret, "fgui.Relations");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_Relations_onOwnerSizeChanged(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::Relations *self = nullptr;
    lua_Number arg1 = 0;       /** dWidth */
    lua_Number arg2 = 0;       /** dHeight */
    bool arg3 = false;       /** applyPivot */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.Relations");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_bool(L, 4, &arg3);

    // void onOwnerSizeChanged(float dWidth, float dHeight, bool applyPivot)
    self->onOwnerSizeChanged((float)arg1, (float)arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_Relations_remove(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::Relations *self = nullptr;
    fairygui::GObject *arg1 = nullptr;       /** target */
    lua_Unsigned arg2 = 0;       /** relationType */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.Relations");
    olua_check_cppobj(L, 2, (void **)&arg1, "fgui.GObject");
    olua_check_uint(L, 3, &arg2);

    // void remove(fairygui::GObject *target, fairygui::RelationType relationType)
    self->remove(arg1, (fairygui::RelationType)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_Relations_get_handling(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::Relations *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.Relations");

    // fairygui::GObject *handling
    fairygui::GObject *ret = (fairygui::GObject *)self->handling;
    int num_ret = olua_push_cppobj(L, ret, "fgui.GObject");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_Relations_set_handling(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::Relations *self = nullptr;
    fairygui::GObject *arg1 = nullptr;       /** handling */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.Relations");
    olua_check_cppobj(L, 2, (void **)&arg1, "fgui.GObject");

    // fairygui::GObject *handling
    self->handling = arg1;

    olua_endinvoke(L);

    return 0;
}

static int luaopen_fairygui_Relations(lua_State *L)
{
    oluacls_class(L, "fgui.Relations", nullptr);
    oluacls_func(L, "__gc", _fairygui_Relations___gc);
    oluacls_func(L, "__move", _fairygui_Relations___move);
    oluacls_func(L, "add", _fairygui_Relations_add);
    oluacls_func(L, "clearAll", _fairygui_Relations_clearAll);
    oluacls_func(L, "clearFor", _fairygui_Relations_clearFor);
    oluacls_func(L, "contains", _fairygui_Relations_contains);
    oluacls_func(L, "copyFrom", _fairygui_Relations_copyFrom);
    oluacls_func(L, "isEmpty", _fairygui_Relations_isEmpty);
    oluacls_func(L, "new", _fairygui_Relations_new);
    oluacls_func(L, "onOwnerSizeChanged", _fairygui_Relations_onOwnerSizeChanged);
    oluacls_func(L, "remove", _fairygui_Relations_remove);
    oluacls_prop(L, "empty", _fairygui_Relations_isEmpty, nullptr);
    oluacls_prop(L, "handling", _fairygui_Relations_get_handling, _fairygui_Relations_set_handling);

    olua_registerluatype<fairygui::Relations>(L, "fgui.Relations");

    return 1;
}

static int luaopen_fairygui_RelationType(lua_State *L)
{
    oluacls_class(L, "fgui.RelationType", nullptr);
    oluacls_const_integer(L, "BottomExt_Bottom", (lua_Integer)fairygui::RelationType::BottomExt_Bottom);
    oluacls_const_integer(L, "BottomExt_Top", (lua_Integer)fairygui::RelationType::BottomExt_Top);
    oluacls_const_integer(L, "Bottom_Bottom", (lua_Integer)fairygui::RelationType::Bottom_Bottom);
    oluacls_const_integer(L, "Bottom_Middle", (lua_Integer)fairygui::RelationType::Bottom_Middle);
    oluacls_const_integer(L, "Bottom_Top", (lua_Integer)fairygui::RelationType::Bottom_Top);
    oluacls_const_integer(L, "Center_Center", (lua_Integer)fairygui::RelationType::Center_Center);
    oluacls_const_integer(L, "Height", (lua_Integer)fairygui::RelationType::Height);
    oluacls_const_integer(L, "LeftExt_Left", (lua_Integer)fairygui::RelationType::LeftExt_Left);
    oluacls_const_integer(L, "LeftExt_Right", (lua_Integer)fairygui::RelationType::LeftExt_Right);
    oluacls_const_integer(L, "Left_Center", (lua_Integer)fairygui::RelationType::Left_Center);
    oluacls_const_integer(L, "Left_Left", (lua_Integer)fairygui::RelationType::Left_Left);
    oluacls_const_integer(L, "Left_Right", (lua_Integer)fairygui::RelationType::Left_Right);
    oluacls_const_integer(L, "Middle_Middle", (lua_Integer)fairygui::RelationType::Middle_Middle);
    oluacls_const_integer(L, "RightExt_Left", (lua_Integer)fairygui::RelationType::RightExt_Left);
    oluacls_const_integer(L, "RightExt_Right", (lua_Integer)fairygui::RelationType::RightExt_Right);
    oluacls_const_integer(L, "Right_Center", (lua_Integer)fairygui::RelationType::Right_Center);
    oluacls_const_integer(L, "Right_Left", (lua_Integer)fairygui::RelationType::Right_Left);
    oluacls_const_integer(L, "Right_Right", (lua_Integer)fairygui::RelationType::Right_Right);
    oluacls_const_integer(L, "Size", (lua_Integer)fairygui::RelationType::Size);
    oluacls_const_integer(L, "TopExt_Bottom", (lua_Integer)fairygui::RelationType::TopExt_Bottom);
    oluacls_const_integer(L, "TopExt_Top", (lua_Integer)fairygui::RelationType::TopExt_Top);
    oluacls_const_integer(L, "Top_Bottom", (lua_Integer)fairygui::RelationType::Top_Bottom);
    oluacls_const_integer(L, "Top_Middle", (lua_Integer)fairygui::RelationType::Top_Middle);
    oluacls_const_integer(L, "Top_Top", (lua_Integer)fairygui::RelationType::Top_Top);
    oluacls_const_integer(L, "Width", (lua_Integer)fairygui::RelationType::Width);

    olua_registerluatype<fairygui::RelationType>(L, "fgui.RelationType");

    return 1;
}

static int _fairygui_RelationItem___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (fairygui::RelationItem *)olua_toobj(L, 1, "fgui.RelationItem");
    lua_pushstring(L, ".ownership");
    olua_getvariable(L, 1);
    if (lua_toboolean(L, -1)) {
        olua_setrawobj(L, 1, nullptr);
        delete self;
    }

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_RelationItem___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (fairygui::RelationItem *)olua_toobj(L, 1, "fgui.RelationItem");
    olua_push_cppobj(L, self, "fgui.RelationItem");

    olua_endinvoke(L);

    return 1;
}

static int _fairygui_RelationItem_add(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::RelationItem *self = nullptr;
    lua_Unsigned arg1 = 0;       /** relationType */
    bool arg2 = false;       /** usePercent */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.RelationItem");
    olua_check_uint(L, 2, &arg1);
    olua_check_bool(L, 3, &arg2);

    // void add(fairygui::RelationType relationType, bool usePercent)
    self->add((fairygui::RelationType)arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_RelationItem_applyOnSelfSizeChanged(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::RelationItem *self = nullptr;
    lua_Number arg1 = 0;       /** dWidth */
    lua_Number arg2 = 0;       /** dHeight */
    bool arg3 = false;       /** applyPivot */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.RelationItem");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_bool(L, 4, &arg3);

    // void applyOnSelfSizeChanged(float dWidth, float dHeight, bool applyPivot)
    self->applyOnSelfSizeChanged((float)arg1, (float)arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_RelationItem_copyFrom(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::RelationItem *self = olua_toobj<fairygui::RelationItem>(L, 1);
    fairygui::RelationItem *source = olua_checkobj<fairygui::RelationItem>(L, 2);
    // void copyFrom(const RelationItem& source)
    self->copyFrom(*source);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_RelationItem_getTarget(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::RelationItem *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.RelationItem");

    // @addref(target ^) fairygui::GObject *getTarget()
    fairygui::GObject *ret = (fairygui::GObject *)self->getTarget();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GObject");

    // inject code after call
    olua_addref(L, 1, "target", -1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_RelationItem_internalAdd(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::RelationItem *self = nullptr;
    lua_Unsigned arg1 = 0;       /** relationType */
    bool arg2 = false;       /** usePercent */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.RelationItem");
    olua_check_uint(L, 2, &arg1);
    olua_check_bool(L, 3, &arg2);

    // void internalAdd(fairygui::RelationType relationType, bool usePercent)
    self->internalAdd((fairygui::RelationType)arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_RelationItem_isEmpty(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::RelationItem *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.RelationItem");

    // bool isEmpty()
    bool ret = (bool)self->isEmpty();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_RelationItem_new(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *arg1 = nullptr;       /** owner */

    olua_check_cppobj(L, 1, (void **)&arg1, "fgui.GObject");

    // RelationItem(fairygui::GObject *owner)
    fairygui::RelationItem *ret = (fairygui::RelationItem *)new fairygui::RelationItem(arg1);
    int num_ret = olua_push_cppobj(L, ret, "fgui.RelationItem");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_RelationItem_remove(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::RelationItem *self = nullptr;
    lua_Unsigned arg1 = 0;       /** relationType */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.RelationItem");
    olua_check_uint(L, 2, &arg1);

    // void remove(fairygui::RelationType relationType)
    self->remove((fairygui::RelationType)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_RelationItem_setTarget(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::RelationItem *self = nullptr;
    fairygui::GObject *arg1 = nullptr;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.RelationItem");
    olua_check_cppobj(L, 2, (void **)&arg1, "fgui.GObject");

    // void setTarget(@addref(target ^) fairygui::GObject *value)
    self->setTarget(arg1);

    // inject code after call
    olua_addref(L, 1, "target", 2, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_fairygui_RelationItem(lua_State *L)
{
    oluacls_class(L, "fgui.RelationItem", nullptr);
    oluacls_func(L, "__gc", _fairygui_RelationItem___gc);
    oluacls_func(L, "__move", _fairygui_RelationItem___move);
    oluacls_func(L, "add", _fairygui_RelationItem_add);
    oluacls_func(L, "applyOnSelfSizeChanged", _fairygui_RelationItem_applyOnSelfSizeChanged);
    oluacls_func(L, "copyFrom", _fairygui_RelationItem_copyFrom);
    oluacls_func(L, "getTarget", _fairygui_RelationItem_getTarget);
    oluacls_func(L, "internalAdd", _fairygui_RelationItem_internalAdd);
    oluacls_func(L, "isEmpty", _fairygui_RelationItem_isEmpty);
    oluacls_func(L, "new", _fairygui_RelationItem_new);
    oluacls_func(L, "remove", _fairygui_RelationItem_remove);
    oluacls_func(L, "setTarget", _fairygui_RelationItem_setTarget);
    oluacls_prop(L, "empty", _fairygui_RelationItem_isEmpty, nullptr);
    oluacls_prop(L, "target", _fairygui_RelationItem_getTarget, _fairygui_RelationItem_setTarget);

    olua_registerluatype<fairygui::RelationItem>(L, "fgui.RelationItem");

    return 1;
}

static int _fairygui_ScrollPane___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (fairygui::ScrollPane *)olua_toobj(L, 1, "fgui.ScrollPane");
    olua_push_cppobj(L, self, "fgui.ScrollPane");

    olua_endinvoke(L);

    return 1;
}

static int _fairygui_ScrollPane_cancelDragging(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::ScrollPane *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.ScrollPane");

    // void cancelDragging()
    self->cancelDragging();

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_ScrollPane_getContentSize(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::ScrollPane *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.ScrollPane");

    // const cocos2d::Size &getContentSize()
    const cocos2d::Size &ret = (const cocos2d::Size &)self->getContentSize();
    int num_ret = auto_olua_push_cocos2d_Size(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_ScrollPane_getDecelerationRate(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::ScrollPane *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.ScrollPane");

    // float getDecelerationRate()
    float ret = (float)self->getDecelerationRate();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_ScrollPane_getDraggingPane(lua_State *L)
{
    olua_startinvoke(L);

    // static fairygui::ScrollPane *getDraggingPane()
    fairygui::ScrollPane *ret = (fairygui::ScrollPane *)fairygui::ScrollPane::getDraggingPane();
    int num_ret = olua_push_cppobj(L, ret, "fgui.ScrollPane");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_ScrollPane_getFooter(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::ScrollPane *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.ScrollPane");

    // @addref(footer ^) fairygui::GComponent *getFooter()
    fairygui::GComponent *ret = (fairygui::GComponent *)self->getFooter();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GComponent");

    // inject code after call
    olua_addref(L, 1, "footer", -1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_ScrollPane_getHeader(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::ScrollPane *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.ScrollPane");

    // @addref(header ^) fairygui::GComponent *getHeader()
    fairygui::GComponent *ret = (fairygui::GComponent *)self->getHeader();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GComponent");

    // inject code after call
    olua_addref(L, 1, "header", -1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_ScrollPane_getHzScrollBar(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::ScrollPane *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.ScrollPane");

    // @addref(hzScrollBar ^) fairygui::GScrollBar *getHzScrollBar()
    fairygui::GScrollBar *ret = (fairygui::GScrollBar *)self->getHzScrollBar();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GScrollBar");

    // inject code after call
    olua_addref(L, 1, "hzScrollBar", -1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_ScrollPane_getOwner(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::ScrollPane *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.ScrollPane");

    // @addref(owner ^) fairygui::GComponent *getOwner()
    fairygui::GComponent *ret = (fairygui::GComponent *)self->getOwner();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GComponent");

    // inject code after call
    olua_addref(L, 1, "owner", -1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_ScrollPane_getPageController(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::ScrollPane *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.ScrollPane");

    // @addref(pageController ^) fairygui::GController *getPageController()
    fairygui::GController *ret = (fairygui::GController *)self->getPageController();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GController");

    // inject code after call
    olua_addref(L, 1, "pageController", -1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_ScrollPane_getPageX(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::ScrollPane *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.ScrollPane");

    // int getPageX()
    int ret = (int)self->getPageX();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_ScrollPane_getPageY(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::ScrollPane *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.ScrollPane");

    // int getPageY()
    int ret = (int)self->getPageY();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_ScrollPane_getPercX(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::ScrollPane *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.ScrollPane");

    // float getPercX()
    float ret = (float)self->getPercX();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_ScrollPane_getPercY(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::ScrollPane *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.ScrollPane");

    // float getPercY()
    float ret = (float)self->getPercY();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_ScrollPane_getPosX(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::ScrollPane *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.ScrollPane");

    // float getPosX()
    float ret = (float)self->getPosX();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_ScrollPane_getPosY(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::ScrollPane *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.ScrollPane");

    // float getPosY()
    float ret = (float)self->getPosY();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_ScrollPane_getScrollStep(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::ScrollPane *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.ScrollPane");

    // float getScrollStep()
    float ret = (float)self->getScrollStep();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_ScrollPane_getScrollingPosX(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::ScrollPane *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.ScrollPane");

    // float getScrollingPosX()
    float ret = (float)self->getScrollingPosX();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_ScrollPane_getScrollingPosY(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::ScrollPane *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.ScrollPane");

    // float getScrollingPosY()
    float ret = (float)self->getScrollingPosY();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_ScrollPane_getViewSize(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::ScrollPane *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.ScrollPane");

    // const cocos2d::Size &getViewSize()
    const cocos2d::Size &ret = (const cocos2d::Size &)self->getViewSize();
    int num_ret = auto_olua_push_cocos2d_Size(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_ScrollPane_getVtScrollBar(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::ScrollPane *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.ScrollPane");

    // @addref(vtScrollBar ^) fairygui::GScrollBar *getVtScrollBar()
    fairygui::GScrollBar *ret = (fairygui::GScrollBar *)self->getVtScrollBar();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GScrollBar");

    // inject code after call
    olua_addref(L, 1, "vtScrollBar", -1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_ScrollPane_isBottomMost(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::ScrollPane *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.ScrollPane");

    // bool isBottomMost()
    bool ret = (bool)self->isBottomMost();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_ScrollPane_isBouncebackEffect(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::ScrollPane *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.ScrollPane");

    // bool isBouncebackEffect()
    bool ret = (bool)self->isBouncebackEffect();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_ScrollPane_isChildInView(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::ScrollPane *self = nullptr;
    fairygui::GObject *arg1 = nullptr;       /** obj */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.ScrollPane");
    olua_check_cppobj(L, 2, (void **)&arg1, "fgui.GObject");

    // bool isChildInView(fairygui::GObject *obj)
    bool ret = (bool)self->isChildInView(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_ScrollPane_isInertiaDisabled(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::ScrollPane *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.ScrollPane");

    // bool isInertiaDisabled()
    bool ret = (bool)self->isInertiaDisabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_ScrollPane_isMouseWheelEnabled(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::ScrollPane *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.ScrollPane");

    // bool isMouseWheelEnabled()
    bool ret = (bool)self->isMouseWheelEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_ScrollPane_isPageMode(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::ScrollPane *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.ScrollPane");

    // bool isPageMode()
    bool ret = (bool)self->isPageMode();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_ScrollPane_isRightMost(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::ScrollPane *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.ScrollPane");

    // bool isRightMost()
    bool ret = (bool)self->isRightMost();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_ScrollPane_isSnapToItem(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::ScrollPane *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.ScrollPane");

    // bool isSnapToItem()
    bool ret = (bool)self->isSnapToItem();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_ScrollPane_isTouchEffect(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::ScrollPane *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.ScrollPane");

    // bool isTouchEffect()
    bool ret = (bool)self->isTouchEffect();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_ScrollPane_lockFooter(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::ScrollPane *self = nullptr;
    lua_Integer arg1 = 0;       /** size */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.ScrollPane");
    olua_check_int(L, 2, &arg1);

    // void lockFooter(int size)
    self->lockFooter((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_ScrollPane_lockHeader(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::ScrollPane *self = nullptr;
    lua_Integer arg1 = 0;       /** size */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.ScrollPane");
    olua_check_int(L, 2, &arg1);

    // void lockHeader(int size)
    self->lockHeader((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_ScrollPane_new(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComponent *arg1 = nullptr;       /** owner */

    olua_check_cppobj(L, 1, (void **)&arg1, "fgui.GComponent");

    // ScrollPane(fairygui::GComponent *owner)
    fairygui::ScrollPane *ret = (fairygui::ScrollPane *)new fairygui::ScrollPane(arg1);
    int num_ret = olua_push_cppobj(L, ret, "fgui.ScrollPane");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_ScrollPane_scrollBottom1(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::ScrollPane *self = nullptr;
    bool arg1 = false;       /** ani */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.ScrollPane");
    olua_check_bool(L, 2, &arg1);

    // void scrollBottom(@optional bool ani)
    self->scrollBottom(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_ScrollPane_scrollBottom2(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::ScrollPane *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.ScrollPane");

    // void scrollBottom(@optional bool ani)
    self->scrollBottom();

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_ScrollPane_scrollBottom(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // void scrollBottom(@optional bool ani)
        return _fairygui_ScrollPane_scrollBottom2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_bool(L, 2))) {
            // void scrollBottom(@optional bool ani)
            return _fairygui_ScrollPane_scrollBottom1(L);
        // }
    }

    luaL_error(L, "method 'fairygui::ScrollPane::scrollBottom' not support '%d' arguments", num_args);

    return 0;
}

static int _fairygui_ScrollPane_scrollDown1(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::ScrollPane *self = nullptr;
    lua_Number arg1 = 0;       /** ratio */
    bool arg2 = false;       /** ani */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.ScrollPane");
    olua_check_number(L, 2, &arg1);
    olua_check_bool(L, 3, &arg2);

    // void scrollDown(@optional float ratio, @optional bool ani)
    self->scrollDown((float)arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_ScrollPane_scrollDown2(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::ScrollPane *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.ScrollPane");

    // void scrollDown(@optional float ratio, @optional bool ani)
    self->scrollDown();

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_ScrollPane_scrollDown3(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::ScrollPane *self = nullptr;
    lua_Number arg1 = 0;       /** ratio */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.ScrollPane");
    olua_check_number(L, 2, &arg1);

    // void scrollDown(@optional float ratio, @optional bool ani)
    self->scrollDown((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_ScrollPane_scrollDown(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // void scrollDown(@optional float ratio, @optional bool ani)
        return _fairygui_ScrollPane_scrollDown2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_number(L, 2))) {
            // void scrollDown(@optional float ratio, @optional bool ani)
            return _fairygui_ScrollPane_scrollDown3(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_number(L, 2)) && (olua_is_bool(L, 3))) {
            // void scrollDown(@optional float ratio, @optional bool ani)
            return _fairygui_ScrollPane_scrollDown1(L);
        // }
    }

    luaL_error(L, "method 'fairygui::ScrollPane::scrollDown' not support '%d' arguments", num_args);

    return 0;
}

static int _fairygui_ScrollPane_scrollLeft1(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::ScrollPane *self = nullptr;
    lua_Number arg1 = 0;       /** ratio */
    bool arg2 = false;       /** ani */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.ScrollPane");
    olua_check_number(L, 2, &arg1);
    olua_check_bool(L, 3, &arg2);

    // void scrollLeft(@optional float ratio, @optional bool ani)
    self->scrollLeft((float)arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_ScrollPane_scrollLeft2(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::ScrollPane *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.ScrollPane");

    // void scrollLeft(@optional float ratio, @optional bool ani)
    self->scrollLeft();

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_ScrollPane_scrollLeft3(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::ScrollPane *self = nullptr;
    lua_Number arg1 = 0;       /** ratio */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.ScrollPane");
    olua_check_number(L, 2, &arg1);

    // void scrollLeft(@optional float ratio, @optional bool ani)
    self->scrollLeft((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_ScrollPane_scrollLeft(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // void scrollLeft(@optional float ratio, @optional bool ani)
        return _fairygui_ScrollPane_scrollLeft2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_number(L, 2))) {
            // void scrollLeft(@optional float ratio, @optional bool ani)
            return _fairygui_ScrollPane_scrollLeft3(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_number(L, 2)) && (olua_is_bool(L, 3))) {
            // void scrollLeft(@optional float ratio, @optional bool ani)
            return _fairygui_ScrollPane_scrollLeft1(L);
        // }
    }

    luaL_error(L, "method 'fairygui::ScrollPane::scrollLeft' not support '%d' arguments", num_args);

    return 0;
}

static int _fairygui_ScrollPane_scrollRight1(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::ScrollPane *self = nullptr;
    lua_Number arg1 = 0;       /** ratio */
    bool arg2 = false;       /** ani */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.ScrollPane");
    olua_check_number(L, 2, &arg1);
    olua_check_bool(L, 3, &arg2);

    // void scrollRight(@optional float ratio, @optional bool ani)
    self->scrollRight((float)arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_ScrollPane_scrollRight2(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::ScrollPane *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.ScrollPane");

    // void scrollRight(@optional float ratio, @optional bool ani)
    self->scrollRight();

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_ScrollPane_scrollRight3(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::ScrollPane *self = nullptr;
    lua_Number arg1 = 0;       /** ratio */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.ScrollPane");
    olua_check_number(L, 2, &arg1);

    // void scrollRight(@optional float ratio, @optional bool ani)
    self->scrollRight((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_ScrollPane_scrollRight(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // void scrollRight(@optional float ratio, @optional bool ani)
        return _fairygui_ScrollPane_scrollRight2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_number(L, 2))) {
            // void scrollRight(@optional float ratio, @optional bool ani)
            return _fairygui_ScrollPane_scrollRight3(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_number(L, 2)) && (olua_is_bool(L, 3))) {
            // void scrollRight(@optional float ratio, @optional bool ani)
            return _fairygui_ScrollPane_scrollRight1(L);
        // }
    }

    luaL_error(L, "method 'fairygui::ScrollPane::scrollRight' not support '%d' arguments", num_args);

    return 0;
}

static int _fairygui_ScrollPane_scrollToView1(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::ScrollPane *self = nullptr;
    fairygui::GObject *arg1 = nullptr;       /** obj */
    bool arg2 = false;       /** ani */
    bool arg3 = false;       /** setFirst */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.ScrollPane");
    olua_check_cppobj(L, 2, (void **)&arg1, "fgui.GObject");
    olua_check_bool(L, 3, &arg2);
    olua_check_bool(L, 4, &arg3);

    // void scrollToView(fairygui::GObject *obj, @optional bool ani, @optional bool setFirst)
    self->scrollToView(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_ScrollPane_scrollToView2(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::ScrollPane *self = nullptr;
    cocos2d::Rect arg1;       /** rect */
    bool arg2 = false;       /** ani */
    bool arg3 = false;       /** setFirst */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.ScrollPane");
    manual_olua_check_cocos2d_Rect(L, 2, &arg1);
    olua_check_bool(L, 3, &arg2);
    olua_check_bool(L, 4, &arg3);

    // void scrollToView(const cocos2d::Rect &rect, @optional bool ani, @optional bool setFirst)
    self->scrollToView(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_ScrollPane_scrollToView3(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::ScrollPane *self = nullptr;
    fairygui::GObject *arg1 = nullptr;       /** obj */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.ScrollPane");
    olua_check_cppobj(L, 2, (void **)&arg1, "fgui.GObject");

    // void scrollToView(fairygui::GObject *obj, @optional bool ani, @optional bool setFirst)
    self->scrollToView(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_ScrollPane_scrollToView4(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::ScrollPane *self = nullptr;
    fairygui::GObject *arg1 = nullptr;       /** obj */
    bool arg2 = false;       /** ani */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.ScrollPane");
    olua_check_cppobj(L, 2, (void **)&arg1, "fgui.GObject");
    olua_check_bool(L, 3, &arg2);

    // void scrollToView(fairygui::GObject *obj, @optional bool ani, @optional bool setFirst)
    self->scrollToView(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_ScrollPane_scrollToView5(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::ScrollPane *self = nullptr;
    cocos2d::Rect arg1;       /** rect */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.ScrollPane");
    manual_olua_check_cocos2d_Rect(L, 2, &arg1);

    // void scrollToView(const cocos2d::Rect &rect, @optional bool ani, @optional bool setFirst)
    self->scrollToView(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_ScrollPane_scrollToView6(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::ScrollPane *self = nullptr;
    cocos2d::Rect arg1;       /** rect */
    bool arg2 = false;       /** ani */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.ScrollPane");
    manual_olua_check_cocos2d_Rect(L, 2, &arg1);
    olua_check_bool(L, 3, &arg2);

    // void scrollToView(const cocos2d::Rect &rect, @optional bool ani, @optional bool setFirst)
    self->scrollToView(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_ScrollPane_scrollToView(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        if ((manual_olua_is_cocos2d_Rect(L, 2))) {
            // void scrollToView(const cocos2d::Rect &rect, @optional bool ani, @optional bool setFirst)
            return _fairygui_ScrollPane_scrollToView5(L);
        }

        // if ((olua_is_cppobj(L, 2, "fgui.GObject"))) {
            // void scrollToView(fairygui::GObject *obj, @optional bool ani, @optional bool setFirst)
            return _fairygui_ScrollPane_scrollToView3(L);
        // }
    }

    if (num_args == 2) {
        if ((manual_olua_is_cocos2d_Rect(L, 2)) && (olua_is_bool(L, 3))) {
            // void scrollToView(const cocos2d::Rect &rect, @optional bool ani, @optional bool setFirst)
            return _fairygui_ScrollPane_scrollToView6(L);
        }

        // if ((olua_is_cppobj(L, 2, "fgui.GObject")) && (olua_is_bool(L, 3))) {
            // void scrollToView(fairygui::GObject *obj, @optional bool ani, @optional bool setFirst)
            return _fairygui_ScrollPane_scrollToView4(L);
        // }
    }

    if (num_args == 3) {
        if ((manual_olua_is_cocos2d_Rect(L, 2)) && (olua_is_bool(L, 3)) && (olua_is_bool(L, 4))) {
            // void scrollToView(const cocos2d::Rect &rect, @optional bool ani, @optional bool setFirst)
            return _fairygui_ScrollPane_scrollToView2(L);
        }

        // if ((olua_is_cppobj(L, 2, "fgui.GObject")) && (olua_is_bool(L, 3)) && (olua_is_bool(L, 4))) {
            // void scrollToView(fairygui::GObject *obj, @optional bool ani, @optional bool setFirst)
            return _fairygui_ScrollPane_scrollToView1(L);
        // }
    }

    luaL_error(L, "method 'fairygui::ScrollPane::scrollToView' not support '%d' arguments", num_args);

    return 0;
}

static int _fairygui_ScrollPane_scrollTop1(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::ScrollPane *self = nullptr;
    bool arg1 = false;       /** ani */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.ScrollPane");
    olua_check_bool(L, 2, &arg1);

    // void scrollTop(@optional bool ani)
    self->scrollTop(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_ScrollPane_scrollTop2(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::ScrollPane *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.ScrollPane");

    // void scrollTop(@optional bool ani)
    self->scrollTop();

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_ScrollPane_scrollTop(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // void scrollTop(@optional bool ani)
        return _fairygui_ScrollPane_scrollTop2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_bool(L, 2))) {
            // void scrollTop(@optional bool ani)
            return _fairygui_ScrollPane_scrollTop1(L);
        // }
    }

    luaL_error(L, "method 'fairygui::ScrollPane::scrollTop' not support '%d' arguments", num_args);

    return 0;
}

static int _fairygui_ScrollPane_scrollUp1(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::ScrollPane *self = nullptr;
    lua_Number arg1 = 0;       /** ratio */
    bool arg2 = false;       /** ani */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.ScrollPane");
    olua_check_number(L, 2, &arg1);
    olua_check_bool(L, 3, &arg2);

    // void scrollUp(@optional float ratio, @optional bool ani)
    self->scrollUp((float)arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_ScrollPane_scrollUp2(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::ScrollPane *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.ScrollPane");

    // void scrollUp(@optional float ratio, @optional bool ani)
    self->scrollUp();

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_ScrollPane_scrollUp3(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::ScrollPane *self = nullptr;
    lua_Number arg1 = 0;       /** ratio */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.ScrollPane");
    olua_check_number(L, 2, &arg1);

    // void scrollUp(@optional float ratio, @optional bool ani)
    self->scrollUp((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_ScrollPane_scrollUp(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // void scrollUp(@optional float ratio, @optional bool ani)
        return _fairygui_ScrollPane_scrollUp2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_number(L, 2))) {
            // void scrollUp(@optional float ratio, @optional bool ani)
            return _fairygui_ScrollPane_scrollUp3(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_number(L, 2)) && (olua_is_bool(L, 3))) {
            // void scrollUp(@optional float ratio, @optional bool ani)
            return _fairygui_ScrollPane_scrollUp1(L);
        // }
    }

    luaL_error(L, "method 'fairygui::ScrollPane::scrollUp' not support '%d' arguments", num_args);

    return 0;
}

static int _fairygui_ScrollPane_setBouncebackEffect(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::ScrollPane *self = nullptr;
    bool arg1 = false;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.ScrollPane");
    olua_check_bool(L, 2, &arg1);

    // void setBouncebackEffect(bool value)
    self->setBouncebackEffect(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_ScrollPane_setDecelerationRate(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::ScrollPane *self = nullptr;
    lua_Number arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.ScrollPane");
    olua_check_number(L, 2, &arg1);

    // void setDecelerationRate(float value)
    self->setDecelerationRate((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_ScrollPane_setInertiaDisabled(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::ScrollPane *self = nullptr;
    bool arg1 = false;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.ScrollPane");
    olua_check_bool(L, 2, &arg1);

    // void setInertiaDisabled(bool value)
    self->setInertiaDisabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_ScrollPane_setMouseWheelEnabled(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::ScrollPane *self = nullptr;
    bool arg1 = false;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.ScrollPane");
    olua_check_bool(L, 2, &arg1);

    // void setMouseWheelEnabled(bool value)
    self->setMouseWheelEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_ScrollPane_setPageController(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::ScrollPane *self = nullptr;
    fairygui::GController *arg1 = nullptr;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.ScrollPane");
    olua_check_cppobj(L, 2, (void **)&arg1, "fgui.GController");

    // void setPageController(@addref(pageController ^) fairygui::GController *value)
    self->setPageController(arg1);

    // inject code after call
    olua_addref(L, 1, "pageController", 2, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_ScrollPane_setPageMode(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::ScrollPane *self = nullptr;
    bool arg1 = false;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.ScrollPane");
    olua_check_bool(L, 2, &arg1);

    // void setPageMode(bool value)
    self->setPageMode(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_ScrollPane_setPageX1(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::ScrollPane *self = nullptr;
    lua_Integer arg1 = 0;       /** value */
    bool arg2 = false;       /** ani */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.ScrollPane");
    olua_check_int(L, 2, &arg1);
    olua_check_bool(L, 3, &arg2);

    // void setPageX(int value, @optional bool ani)
    self->setPageX((int)arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_ScrollPane_setPageX2(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::ScrollPane *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.ScrollPane");
    olua_check_int(L, 2, &arg1);

    // void setPageX(int value, @optional bool ani)
    self->setPageX((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_ScrollPane_setPageX(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_int(L, 2))) {
            // void setPageX(int value, @optional bool ani)
            return _fairygui_ScrollPane_setPageX2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_int(L, 2)) && (olua_is_bool(L, 3))) {
            // void setPageX(int value, @optional bool ani)
            return _fairygui_ScrollPane_setPageX1(L);
        // }
    }

    luaL_error(L, "method 'fairygui::ScrollPane::setPageX' not support '%d' arguments", num_args);

    return 0;
}

static int _fairygui_ScrollPane_setPageY1(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::ScrollPane *self = nullptr;
    lua_Integer arg1 = 0;       /** value */
    bool arg2 = false;       /** ani */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.ScrollPane");
    olua_check_int(L, 2, &arg1);
    olua_check_bool(L, 3, &arg2);

    // void setPageY(int value, @optional bool ani)
    self->setPageY((int)arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_ScrollPane_setPageY2(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::ScrollPane *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.ScrollPane");
    olua_check_int(L, 2, &arg1);

    // void setPageY(int value, @optional bool ani)
    self->setPageY((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_ScrollPane_setPageY(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_int(L, 2))) {
            // void setPageY(int value, @optional bool ani)
            return _fairygui_ScrollPane_setPageY2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_int(L, 2)) && (olua_is_bool(L, 3))) {
            // void setPageY(int value, @optional bool ani)
            return _fairygui_ScrollPane_setPageY1(L);
        // }
    }

    luaL_error(L, "method 'fairygui::ScrollPane::setPageY' not support '%d' arguments", num_args);

    return 0;
}

static int _fairygui_ScrollPane_setPercX1(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::ScrollPane *self = nullptr;
    lua_Number arg1 = 0;       /** value */
    bool arg2 = false;       /** ani */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.ScrollPane");
    olua_check_number(L, 2, &arg1);
    olua_check_bool(L, 3, &arg2);

    // void setPercX(float value, @optional bool ani)
    self->setPercX((float)arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_ScrollPane_setPercX2(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::ScrollPane *self = nullptr;
    lua_Number arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.ScrollPane");
    olua_check_number(L, 2, &arg1);

    // void setPercX(float value, @optional bool ani)
    self->setPercX((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_ScrollPane_setPercX(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_number(L, 2))) {
            // void setPercX(float value, @optional bool ani)
            return _fairygui_ScrollPane_setPercX2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_number(L, 2)) && (olua_is_bool(L, 3))) {
            // void setPercX(float value, @optional bool ani)
            return _fairygui_ScrollPane_setPercX1(L);
        // }
    }

    luaL_error(L, "method 'fairygui::ScrollPane::setPercX' not support '%d' arguments", num_args);

    return 0;
}

static int _fairygui_ScrollPane_setPercY1(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::ScrollPane *self = nullptr;
    lua_Number arg1 = 0;       /** value */
    bool arg2 = false;       /** ani */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.ScrollPane");
    olua_check_number(L, 2, &arg1);
    olua_check_bool(L, 3, &arg2);

    // void setPercY(float value, @optional bool ani)
    self->setPercY((float)arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_ScrollPane_setPercY2(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::ScrollPane *self = nullptr;
    lua_Number arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.ScrollPane");
    olua_check_number(L, 2, &arg1);

    // void setPercY(float value, @optional bool ani)
    self->setPercY((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_ScrollPane_setPercY(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_number(L, 2))) {
            // void setPercY(float value, @optional bool ani)
            return _fairygui_ScrollPane_setPercY2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_number(L, 2)) && (olua_is_bool(L, 3))) {
            // void setPercY(float value, @optional bool ani)
            return _fairygui_ScrollPane_setPercY1(L);
        // }
    }

    luaL_error(L, "method 'fairygui::ScrollPane::setPercY' not support '%d' arguments", num_args);

    return 0;
}

static int _fairygui_ScrollPane_setPosX1(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::ScrollPane *self = nullptr;
    lua_Number arg1 = 0;       /** value */
    bool arg2 = false;       /** ani */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.ScrollPane");
    olua_check_number(L, 2, &arg1);
    olua_check_bool(L, 3, &arg2);

    // void setPosX(float value, @optional bool ani)
    self->setPosX((float)arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_ScrollPane_setPosX2(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::ScrollPane *self = nullptr;
    lua_Number arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.ScrollPane");
    olua_check_number(L, 2, &arg1);

    // void setPosX(float value, @optional bool ani)
    self->setPosX((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_ScrollPane_setPosX(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_number(L, 2))) {
            // void setPosX(float value, @optional bool ani)
            return _fairygui_ScrollPane_setPosX2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_number(L, 2)) && (olua_is_bool(L, 3))) {
            // void setPosX(float value, @optional bool ani)
            return _fairygui_ScrollPane_setPosX1(L);
        // }
    }

    luaL_error(L, "method 'fairygui::ScrollPane::setPosX' not support '%d' arguments", num_args);

    return 0;
}

static int _fairygui_ScrollPane_setPosY1(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::ScrollPane *self = nullptr;
    lua_Number arg1 = 0;       /** value */
    bool arg2 = false;       /** ani */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.ScrollPane");
    olua_check_number(L, 2, &arg1);
    olua_check_bool(L, 3, &arg2);

    // void setPosY(float value, @optional bool ani)
    self->setPosY((float)arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_ScrollPane_setPosY2(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::ScrollPane *self = nullptr;
    lua_Number arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.ScrollPane");
    olua_check_number(L, 2, &arg1);

    // void setPosY(float value, @optional bool ani)
    self->setPosY((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_ScrollPane_setPosY(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_number(L, 2))) {
            // void setPosY(float value, @optional bool ani)
            return _fairygui_ScrollPane_setPosY2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_number(L, 2)) && (olua_is_bool(L, 3))) {
            // void setPosY(float value, @optional bool ani)
            return _fairygui_ScrollPane_setPosY1(L);
        // }
    }

    luaL_error(L, "method 'fairygui::ScrollPane::setPosY' not support '%d' arguments", num_args);

    return 0;
}

static int _fairygui_ScrollPane_setScrollStep(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::ScrollPane *self = nullptr;
    lua_Number arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.ScrollPane");
    olua_check_number(L, 2, &arg1);

    // void setScrollStep(float value)
    self->setScrollStep((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_ScrollPane_setSnapToItem(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::ScrollPane *self = nullptr;
    bool arg1 = false;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.ScrollPane");
    olua_check_bool(L, 2, &arg1);

    // void setSnapToItem(bool value)
    self->setSnapToItem(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_ScrollPane_setTouchEffect(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::ScrollPane *self = nullptr;
    bool arg1 = false;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.ScrollPane");
    olua_check_bool(L, 2, &arg1);

    // void setTouchEffect(bool value)
    self->setTouchEffect(arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_fairygui_ScrollPane(lua_State *L)
{
    oluacls_class(L, "fgui.ScrollPane", "cc.Ref");
    oluacls_func(L, "__move", _fairygui_ScrollPane___move);
    oluacls_func(L, "cancelDragging", _fairygui_ScrollPane_cancelDragging);
    oluacls_func(L, "getContentSize", _fairygui_ScrollPane_getContentSize);
    oluacls_func(L, "getDecelerationRate", _fairygui_ScrollPane_getDecelerationRate);
    oluacls_func(L, "getDraggingPane", _fairygui_ScrollPane_getDraggingPane);
    oluacls_func(L, "getFooter", _fairygui_ScrollPane_getFooter);
    oluacls_func(L, "getHeader", _fairygui_ScrollPane_getHeader);
    oluacls_func(L, "getHzScrollBar", _fairygui_ScrollPane_getHzScrollBar);
    oluacls_func(L, "getOwner", _fairygui_ScrollPane_getOwner);
    oluacls_func(L, "getPageController", _fairygui_ScrollPane_getPageController);
    oluacls_func(L, "getPageX", _fairygui_ScrollPane_getPageX);
    oluacls_func(L, "getPageY", _fairygui_ScrollPane_getPageY);
    oluacls_func(L, "getPercX", _fairygui_ScrollPane_getPercX);
    oluacls_func(L, "getPercY", _fairygui_ScrollPane_getPercY);
    oluacls_func(L, "getPosX", _fairygui_ScrollPane_getPosX);
    oluacls_func(L, "getPosY", _fairygui_ScrollPane_getPosY);
    oluacls_func(L, "getScrollStep", _fairygui_ScrollPane_getScrollStep);
    oluacls_func(L, "getScrollingPosX", _fairygui_ScrollPane_getScrollingPosX);
    oluacls_func(L, "getScrollingPosY", _fairygui_ScrollPane_getScrollingPosY);
    oluacls_func(L, "getViewSize", _fairygui_ScrollPane_getViewSize);
    oluacls_func(L, "getVtScrollBar", _fairygui_ScrollPane_getVtScrollBar);
    oluacls_func(L, "isBottomMost", _fairygui_ScrollPane_isBottomMost);
    oluacls_func(L, "isBouncebackEffect", _fairygui_ScrollPane_isBouncebackEffect);
    oluacls_func(L, "isChildInView", _fairygui_ScrollPane_isChildInView);
    oluacls_func(L, "isInertiaDisabled", _fairygui_ScrollPane_isInertiaDisabled);
    oluacls_func(L, "isMouseWheelEnabled", _fairygui_ScrollPane_isMouseWheelEnabled);
    oluacls_func(L, "isPageMode", _fairygui_ScrollPane_isPageMode);
    oluacls_func(L, "isRightMost", _fairygui_ScrollPane_isRightMost);
    oluacls_func(L, "isSnapToItem", _fairygui_ScrollPane_isSnapToItem);
    oluacls_func(L, "isTouchEffect", _fairygui_ScrollPane_isTouchEffect);
    oluacls_func(L, "lockFooter", _fairygui_ScrollPane_lockFooter);
    oluacls_func(L, "lockHeader", _fairygui_ScrollPane_lockHeader);
    oluacls_func(L, "new", _fairygui_ScrollPane_new);
    oluacls_func(L, "scrollBottom", _fairygui_ScrollPane_scrollBottom);
    oluacls_func(L, "scrollDown", _fairygui_ScrollPane_scrollDown);
    oluacls_func(L, "scrollLeft", _fairygui_ScrollPane_scrollLeft);
    oluacls_func(L, "scrollRight", _fairygui_ScrollPane_scrollRight);
    oluacls_func(L, "scrollToView", _fairygui_ScrollPane_scrollToView);
    oluacls_func(L, "scrollTop", _fairygui_ScrollPane_scrollTop);
    oluacls_func(L, "scrollUp", _fairygui_ScrollPane_scrollUp);
    oluacls_func(L, "setBouncebackEffect", _fairygui_ScrollPane_setBouncebackEffect);
    oluacls_func(L, "setDecelerationRate", _fairygui_ScrollPane_setDecelerationRate);
    oluacls_func(L, "setInertiaDisabled", _fairygui_ScrollPane_setInertiaDisabled);
    oluacls_func(L, "setMouseWheelEnabled", _fairygui_ScrollPane_setMouseWheelEnabled);
    oluacls_func(L, "setPageController", _fairygui_ScrollPane_setPageController);
    oluacls_func(L, "setPageMode", _fairygui_ScrollPane_setPageMode);
    oluacls_func(L, "setPageX", _fairygui_ScrollPane_setPageX);
    oluacls_func(L, "setPageY", _fairygui_ScrollPane_setPageY);
    oluacls_func(L, "setPercX", _fairygui_ScrollPane_setPercX);
    oluacls_func(L, "setPercY", _fairygui_ScrollPane_setPercY);
    oluacls_func(L, "setPosX", _fairygui_ScrollPane_setPosX);
    oluacls_func(L, "setPosY", _fairygui_ScrollPane_setPosY);
    oluacls_func(L, "setScrollStep", _fairygui_ScrollPane_setScrollStep);
    oluacls_func(L, "setSnapToItem", _fairygui_ScrollPane_setSnapToItem);
    oluacls_func(L, "setTouchEffect", _fairygui_ScrollPane_setTouchEffect);
    oluacls_prop(L, "bottomMost", _fairygui_ScrollPane_isBottomMost, nullptr);
    oluacls_prop(L, "bouncebackEffect", _fairygui_ScrollPane_isBouncebackEffect, _fairygui_ScrollPane_setBouncebackEffect);
    oluacls_prop(L, "contentSize", _fairygui_ScrollPane_getContentSize, nullptr);
    oluacls_prop(L, "decelerationRate", _fairygui_ScrollPane_getDecelerationRate, _fairygui_ScrollPane_setDecelerationRate);
    oluacls_prop(L, "draggingPane", _fairygui_ScrollPane_getDraggingPane, nullptr);
    oluacls_prop(L, "footer", _fairygui_ScrollPane_getFooter, nullptr);
    oluacls_prop(L, "header", _fairygui_ScrollPane_getHeader, nullptr);
    oluacls_prop(L, "hzScrollBar", _fairygui_ScrollPane_getHzScrollBar, nullptr);
    oluacls_prop(L, "inertiaDisabled", _fairygui_ScrollPane_isInertiaDisabled, _fairygui_ScrollPane_setInertiaDisabled);
    oluacls_prop(L, "mouseWheelEnabled", _fairygui_ScrollPane_isMouseWheelEnabled, _fairygui_ScrollPane_setMouseWheelEnabled);
    oluacls_prop(L, "owner", _fairygui_ScrollPane_getOwner, nullptr);
    oluacls_prop(L, "pageController", _fairygui_ScrollPane_getPageController, _fairygui_ScrollPane_setPageController);
    oluacls_prop(L, "pageMode", _fairygui_ScrollPane_isPageMode, _fairygui_ScrollPane_setPageMode);
    oluacls_prop(L, "pageX", _fairygui_ScrollPane_getPageX, _fairygui_ScrollPane_setPageX);
    oluacls_prop(L, "pageY", _fairygui_ScrollPane_getPageY, _fairygui_ScrollPane_setPageY);
    oluacls_prop(L, "percX", _fairygui_ScrollPane_getPercX, _fairygui_ScrollPane_setPercX);
    oluacls_prop(L, "percY", _fairygui_ScrollPane_getPercY, _fairygui_ScrollPane_setPercY);
    oluacls_prop(L, "posX", _fairygui_ScrollPane_getPosX, _fairygui_ScrollPane_setPosX);
    oluacls_prop(L, "posY", _fairygui_ScrollPane_getPosY, _fairygui_ScrollPane_setPosY);
    oluacls_prop(L, "rightMost", _fairygui_ScrollPane_isRightMost, nullptr);
    oluacls_prop(L, "scrollStep", _fairygui_ScrollPane_getScrollStep, _fairygui_ScrollPane_setScrollStep);
    oluacls_prop(L, "scrollingPosX", _fairygui_ScrollPane_getScrollingPosX, nullptr);
    oluacls_prop(L, "scrollingPosY", _fairygui_ScrollPane_getScrollingPosY, nullptr);
    oluacls_prop(L, "snapToItem", _fairygui_ScrollPane_isSnapToItem, _fairygui_ScrollPane_setSnapToItem);
    oluacls_prop(L, "touchEffect", _fairygui_ScrollPane_isTouchEffect, _fairygui_ScrollPane_setTouchEffect);
    oluacls_prop(L, "viewSize", _fairygui_ScrollPane_getViewSize, nullptr);
    oluacls_prop(L, "vtScrollBar", _fairygui_ScrollPane_getVtScrollBar, nullptr);

    olua_registerluatype<fairygui::ScrollPane>(L, "fgui.ScrollPane");

    return 1;
}

static int _fairygui_Transition___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (fairygui::Transition *)olua_toobj(L, 1, "fgui.Transition");
    olua_push_cppobj(L, self, "fgui.Transition");

    olua_endinvoke(L);

    return 1;
}

static int _fairygui_Transition_changePlayTimes(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::Transition *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.Transition");
    olua_check_int(L, 2, &arg1);

    // void changePlayTimes(int value)
    self->changePlayTimes((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_Transition_clearHooks(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::Transition *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.Transition");

    std::string tag = ("hook.");
    void *self_obj = (void *)self;
    olua_removecallback(L, self_obj, tag.c_str(), OLUA_TAG_SUBSTARTWITH);

    // void clearHooks()
    self->clearHooks();

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_Transition_getLabelTime(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::Transition *self = nullptr;
    std::string arg1;       /** label */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.Transition");
    olua_check_std_string(L, 2, &arg1);

    // float getLabelTime(const std::string &label)
    float ret = (float)self->getLabelTime(arg1);
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_Transition_getOwner(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::Transition *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.Transition");

    // @addref(owner ^) fairygui::GComponent *getOwner()
    fairygui::GComponent *ret = (fairygui::GComponent *)self->getOwner();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GComponent");

    // inject code after call
    olua_addref(L, 1, "owner", -1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_Transition_getTimeScale(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::Transition *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.Transition");

    // float getTimeScale()
    float ret = (float)self->getTimeScale();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_Transition_isPlaying(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::Transition *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.Transition");

    // bool isPlaying()
    bool ret = (bool)self->isPlaying();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_Transition_new(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GComponent *arg1 = nullptr;       /** owner */

    olua_check_cppobj(L, 1, (void **)&arg1, "fgui.GComponent");

    // Transition(fairygui::GComponent *owner)
    fairygui::Transition *ret = (fairygui::Transition *)new fairygui::Transition(arg1);
    int num_ret = olua_push_cppobj(L, ret, "fgui.Transition");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_Transition_onOwnerAddedToStage(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::Transition *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.Transition");

    // void onOwnerAddedToStage()
    self->onOwnerAddedToStage();

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_Transition_onOwnerRemovedFromStage(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::Transition *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.Transition");

    // void onOwnerRemovedFromStage()
    self->onOwnerRemovedFromStage();

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_Transition_play1(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::Transition *self = nullptr;
    std::function<void()> arg1;       /** callback */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.Transition");

    if (olua_is_std_function(L, 2)) {
        void *self_obj = (void *)self;
        std::string tag = "play";
        std::string func = olua_setcallback(L, self_obj, tag.c_str(), 2, OLUA_TAG_REPLACE);
        lua_Unsigned ctx = olua_context(L);
        arg1 = [self_obj, func, ctx]() {
            lua_State *L = olua_mainthread(NULL);

            if (L != NULL && (olua_context(L) == ctx)) {
                int top = lua_gettop(L);

                olua_callback(L, self_obj, func.c_str(), 0);

                lua_settop(L, top);
            }
        };
    } else {
        void *self_obj = (void *)self;
        std::string tag = "play";
        olua_removecallback(L, self_obj, tag.c_str(), OLUA_TAG_SUBEQUAL);
        arg1 = nullptr;
    }

    // void play(@local @optional std::function<void ()> callback)
    self->play(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_Transition_play2(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::Transition *self = nullptr;
    lua_Integer arg1 = 0;       /** times */
    lua_Number arg2 = 0;       /** delay */
    std::function<void()> arg3;       /** callback */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.Transition");
    olua_check_int(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);

    if (olua_is_std_function(L, 4)) {
        void *self_obj = (void *)self;
        std::string tag = "play";
        std::string func = olua_setcallback(L, self_obj, tag.c_str(), 4, OLUA_TAG_REPLACE);
        lua_Unsigned ctx = olua_context(L);
        arg3 = [self_obj, func, ctx]() {
            lua_State *L = olua_mainthread(NULL);

            if (L != NULL && (olua_context(L) == ctx)) {
                int top = lua_gettop(L);

                olua_callback(L, self_obj, func.c_str(), 0);

                lua_settop(L, top);
            }
        };
    } else {
        void *self_obj = (void *)self;
        std::string tag = "play";
        olua_removecallback(L, self_obj, tag.c_str(), OLUA_TAG_SUBEQUAL);
        arg3 = nullptr;
    }

    // void play(int times, float delay, @local @optional std::function<void ()> callback)
    self->play((int)arg1, (float)arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_Transition_play3(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::Transition *self = nullptr;
    lua_Integer arg1 = 0;       /** times */
    lua_Number arg2 = 0;       /** delay */
    lua_Number arg3 = 0;       /** startTime */
    lua_Number arg4 = 0;       /** endTime */
    std::function<void()> arg5;       /** callback */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.Transition");
    olua_check_int(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);
    olua_check_number(L, 5, &arg4);

    if (olua_is_std_function(L, 6)) {
        void *self_obj = (void *)self;
        std::string tag = "play";
        std::string func = olua_setcallback(L, self_obj, tag.c_str(), 6, OLUA_TAG_REPLACE);
        lua_Unsigned ctx = olua_context(L);
        arg5 = [self_obj, func, ctx]() {
            lua_State *L = olua_mainthread(NULL);

            if (L != NULL && (olua_context(L) == ctx)) {
                int top = lua_gettop(L);

                olua_callback(L, self_obj, func.c_str(), 0);

                lua_settop(L, top);
            }
        };
    } else {
        void *self_obj = (void *)self;
        std::string tag = "play";
        olua_removecallback(L, self_obj, tag.c_str(), OLUA_TAG_SUBEQUAL);
        arg5 = nullptr;
    }

    // void play(int times, float delay, float startTime, float endTime, @local @optional std::function<void ()> callback)
    self->play((int)arg1, (float)arg2, (float)arg3, (float)arg4, arg5);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_Transition_play4(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::Transition *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.Transition");

    // void play(@local @optional std::function<void ()> callback)
    self->play();

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_Transition_play5(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::Transition *self = nullptr;
    lua_Integer arg1 = 0;       /** times */
    lua_Number arg2 = 0;       /** delay */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.Transition");
    olua_check_int(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);

    // void play(int times, float delay, @local @optional std::function<void ()> callback)
    self->play((int)arg1, (float)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_Transition_play6(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::Transition *self = nullptr;
    lua_Integer arg1 = 0;       /** times */
    lua_Number arg2 = 0;       /** delay */
    lua_Number arg3 = 0;       /** startTime */
    lua_Number arg4 = 0;       /** endTime */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.Transition");
    olua_check_int(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);
    olua_check_number(L, 5, &arg4);

    // void play(int times, float delay, float startTime, float endTime, @local @optional std::function<void ()> callback)
    self->play((int)arg1, (float)arg2, (float)arg3, (float)arg4);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_Transition_play(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // void play(@local @optional std::function<void ()> callback)
        return _fairygui_Transition_play4(L);
    }

    if (num_args == 1) {
        // if ((olua_is_std_function(L, 2))) {
            // void play(@local @optional std::function<void ()> callback)
            return _fairygui_Transition_play1(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_int(L, 2)) && (olua_is_number(L, 3))) {
            // void play(int times, float delay, @local @optional std::function<void ()> callback)
            return _fairygui_Transition_play5(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_int(L, 2)) && (olua_is_number(L, 3)) && (olua_is_std_function(L, 4))) {
            // void play(int times, float delay, @local @optional std::function<void ()> callback)
            return _fairygui_Transition_play2(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_int(L, 2)) && (olua_is_number(L, 3)) && (olua_is_number(L, 4)) && (olua_is_number(L, 5))) {
            // void play(int times, float delay, float startTime, float endTime, @local @optional std::function<void ()> callback)
            return _fairygui_Transition_play6(L);
        // }
    }

    if (num_args == 5) {
        // if ((olua_is_int(L, 2)) && (olua_is_number(L, 3)) && (olua_is_number(L, 4)) && (olua_is_number(L, 5)) && (olua_is_std_function(L, 6))) {
            // void play(int times, float delay, float startTime, float endTime, @local @optional std::function<void ()> callback)
            return _fairygui_Transition_play3(L);
        // }
    }

    luaL_error(L, "method 'fairygui::Transition::play' not support '%d' arguments", num_args);

    return 0;
}

static int _fairygui_Transition_playReverse1(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::Transition *self = nullptr;
    std::function<void()> arg1;       /** callback */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.Transition");

    if (olua_is_std_function(L, 2)) {
        void *self_obj = (void *)self;
        std::string tag = "playReverse";
        std::string func = olua_setcallback(L, self_obj, tag.c_str(), 2, OLUA_TAG_REPLACE);
        lua_Unsigned ctx = olua_context(L);
        arg1 = [self_obj, func, ctx]() {
            lua_State *L = olua_mainthread(NULL);

            if (L != NULL && (olua_context(L) == ctx)) {
                int top = lua_gettop(L);

                olua_callback(L, self_obj, func.c_str(), 0);

                lua_settop(L, top);
            }
        };
    } else {
        void *self_obj = (void *)self;
        std::string tag = "playReverse";
        olua_removecallback(L, self_obj, tag.c_str(), OLUA_TAG_SUBEQUAL);
        arg1 = nullptr;
    }

    // void playReverse(@local @optional std::function<void ()> callback)
    self->playReverse(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_Transition_playReverse2(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::Transition *self = nullptr;
    lua_Integer arg1 = 0;       /** times */
    lua_Number arg2 = 0;       /** delay */
    std::function<void()> arg3;       /** callback */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.Transition");
    olua_check_int(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);

    if (olua_is_std_function(L, 4)) {
        void *self_obj = (void *)self;
        std::string tag = "playReverse";
        std::string func = olua_setcallback(L, self_obj, tag.c_str(), 4, OLUA_TAG_REPLACE);
        lua_Unsigned ctx = olua_context(L);
        arg3 = [self_obj, func, ctx]() {
            lua_State *L = olua_mainthread(NULL);

            if (L != NULL && (olua_context(L) == ctx)) {
                int top = lua_gettop(L);

                olua_callback(L, self_obj, func.c_str(), 0);

                lua_settop(L, top);
            }
        };
    } else {
        void *self_obj = (void *)self;
        std::string tag = "playReverse";
        olua_removecallback(L, self_obj, tag.c_str(), OLUA_TAG_SUBEQUAL);
        arg3 = nullptr;
    }

    // void playReverse(int times, float delay, @local @optional std::function<void ()> callback)
    self->playReverse((int)arg1, (float)arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_Transition_playReverse3(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::Transition *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.Transition");

    // void playReverse(@local @optional std::function<void ()> callback)
    self->playReverse();

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_Transition_playReverse4(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::Transition *self = nullptr;
    lua_Integer arg1 = 0;       /** times */
    lua_Number arg2 = 0;       /** delay */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.Transition");
    olua_check_int(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);

    // void playReverse(int times, float delay, @local @optional std::function<void ()> callback)
    self->playReverse((int)arg1, (float)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_Transition_playReverse(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // void playReverse(@local @optional std::function<void ()> callback)
        return _fairygui_Transition_playReverse3(L);
    }

    if (num_args == 1) {
        // if ((olua_is_std_function(L, 2))) {
            // void playReverse(@local @optional std::function<void ()> callback)
            return _fairygui_Transition_playReverse1(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_int(L, 2)) && (olua_is_number(L, 3))) {
            // void playReverse(int times, float delay, @local @optional std::function<void ()> callback)
            return _fairygui_Transition_playReverse4(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_int(L, 2)) && (olua_is_number(L, 3)) && (olua_is_std_function(L, 4))) {
            // void playReverse(int times, float delay, @local @optional std::function<void ()> callback)
            return _fairygui_Transition_playReverse2(L);
        // }
    }

    luaL_error(L, "method 'fairygui::Transition::playReverse' not support '%d' arguments", num_args);

    return 0;
}

static int _fairygui_Transition_setAutoPlay(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::Transition *self = nullptr;
    bool arg1 = false;       /** autoPlay */
    lua_Integer arg2 = 0;       /** times */
    lua_Number arg3 = 0;       /** delay */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.Transition");
    olua_check_bool(L, 2, &arg1);
    olua_check_int(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);

    // void setAutoPlay(bool autoPlay, int times, float delay)
    self->setAutoPlay(arg1, (int)arg2, (float)arg3);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_Transition_setDuration(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::Transition *self = nullptr;
    std::string arg1;       /** label */
    lua_Number arg2 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.Transition");
    olua_check_std_string(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);

    // void setDuration(const std::string &label, float value)
    self->setDuration(arg1, (float)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_Transition_setHook(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::Transition *self = nullptr;
    std::string arg1;       /** label */
    std::function<void()> arg2;       /** callback */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.Transition");
    olua_check_std_string(L, 2, &arg1);

    if (olua_is_std_function(L, 3)) {
        void *self_obj = (void *)self;
        std::string tag = ("hook." + arg1);
        std::string func = olua_setcallback(L, self_obj, tag.c_str(), 3, OLUA_TAG_REPLACE);
        lua_Unsigned ctx = olua_context(L);
        arg2 = [self_obj, func, ctx]() {
            lua_State *L = olua_mainthread(NULL);

            if (L != NULL && (olua_context(L) == ctx)) {
                int top = lua_gettop(L);

                olua_callback(L, self_obj, func.c_str(), 0);

                lua_settop(L, top);
            }
        };
    } else {
        void *self_obj = (void *)self;
        std::string tag = ("hook." + arg1);
        olua_removecallback(L, self_obj, tag.c_str(), OLUA_TAG_SUBEQUAL);
        arg2 = nullptr;
    }

    // void setHook(const std::string &label, @nullable @local std::function<void ()> callback)
    self->setHook(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_Transition_setPaused(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::Transition *self = nullptr;
    bool arg1 = false;       /** paused */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.Transition");
    olua_check_bool(L, 2, &arg1);

    // void setPaused(bool paused)
    self->setPaused(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_Transition_setTarget(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::Transition *self = nullptr;
    std::string arg1;       /** label */
    fairygui::GObject *arg2 = nullptr;       /** newTarget */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.Transition");
    olua_check_std_string(L, 2, &arg1);
    olua_check_cppobj(L, 3, (void **)&arg2, "fgui.GObject");

    // void setTarget(const std::string &label, fairygui::GObject *newTarget)
    self->setTarget(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_Transition_setTimeScale(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::Transition *self = nullptr;
    lua_Number arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.Transition");
    olua_check_number(L, 2, &arg1);

    // void setTimeScale(float value)
    self->setTimeScale((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_Transition_setValue(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::Transition *self = nullptr;
    std::string arg1;       /** label */
    cocos2d::ValueVector arg2;       /** values */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.Transition");
    olua_check_std_string(L, 2, &arg1);
    manual_olua_check_cocos2d_ValueVector(L, 3, &arg2);

    // void setValue(const std::string &label, const cocos2d::ValueVector &values)
    self->setValue(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_Transition_stop1(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::Transition *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.Transition");

    // void stop()
    self->stop();

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_Transition_stop2(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::Transition *self = nullptr;
    bool arg1 = false;       /** setToComplete */
    bool arg2 = false;       /** processCallback */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.Transition");
    olua_check_bool(L, 2, &arg1);
    olua_check_bool(L, 3, &arg2);

    // void stop(bool setToComplete, bool processCallback)
    self->stop(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_Transition_stop(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // void stop()
        return _fairygui_Transition_stop1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_bool(L, 2)) && (olua_is_bool(L, 3))) {
            // void stop(bool setToComplete, bool processCallback)
            return _fairygui_Transition_stop2(L);
        // }
    }

    luaL_error(L, "method 'fairygui::Transition::stop' not support '%d' arguments", num_args);

    return 0;
}

static int _fairygui_Transition_updateFromRelations(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::Transition *self = nullptr;
    std::string arg1;       /** targetId */
    lua_Number arg2 = 0;       /** dx */
    lua_Number arg3 = 0;       /** dy */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.Transition");
    olua_check_std_string(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);

    // void updateFromRelations(const std::string &targetId, float dx, float dy)
    self->updateFromRelations(arg1, (float)arg2, (float)arg3);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_Transition_get_name(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::Transition *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.Transition");

    // std::string name
    std::string ret = (std::string)self->name;
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_Transition_set_name(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::Transition *self = nullptr;
    std::string arg1;       /** name */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.Transition");
    olua_check_std_string(L, 2, &arg1);

    // std::string name
    self->name = arg1;

    olua_endinvoke(L);

    return 0;
}

static int luaopen_fairygui_Transition(lua_State *L)
{
    oluacls_class(L, "fgui.Transition", "cc.Ref");
    oluacls_func(L, "__move", _fairygui_Transition___move);
    oluacls_func(L, "changePlayTimes", _fairygui_Transition_changePlayTimes);
    oluacls_func(L, "clearHooks", _fairygui_Transition_clearHooks);
    oluacls_func(L, "getLabelTime", _fairygui_Transition_getLabelTime);
    oluacls_func(L, "getOwner", _fairygui_Transition_getOwner);
    oluacls_func(L, "getTimeScale", _fairygui_Transition_getTimeScale);
    oluacls_func(L, "isPlaying", _fairygui_Transition_isPlaying);
    oluacls_func(L, "new", _fairygui_Transition_new);
    oluacls_func(L, "onOwnerAddedToStage", _fairygui_Transition_onOwnerAddedToStage);
    oluacls_func(L, "onOwnerRemovedFromStage", _fairygui_Transition_onOwnerRemovedFromStage);
    oluacls_func(L, "play", _fairygui_Transition_play);
    oluacls_func(L, "playReverse", _fairygui_Transition_playReverse);
    oluacls_func(L, "setAutoPlay", _fairygui_Transition_setAutoPlay);
    oluacls_func(L, "setDuration", _fairygui_Transition_setDuration);
    oluacls_func(L, "setHook", _fairygui_Transition_setHook);
    oluacls_func(L, "setPaused", _fairygui_Transition_setPaused);
    oluacls_func(L, "setTarget", _fairygui_Transition_setTarget);
    oluacls_func(L, "setTimeScale", _fairygui_Transition_setTimeScale);
    oluacls_func(L, "setValue", _fairygui_Transition_setValue);
    oluacls_func(L, "stop", _fairygui_Transition_stop);
    oluacls_func(L, "updateFromRelations", _fairygui_Transition_updateFromRelations);
    oluacls_prop(L, "owner", _fairygui_Transition_getOwner, nullptr);
    oluacls_prop(L, "playing", _fairygui_Transition_isPlaying, nullptr);
    oluacls_prop(L, "timeScale", _fairygui_Transition_getTimeScale, _fairygui_Transition_setTimeScale);
    oluacls_prop(L, "name", _fairygui_Transition_get_name, _fairygui_Transition_set_name);

    olua_registerluatype<fairygui::Transition>(L, "fgui.Transition");

    return 1;
}

static int _fairygui_UIConfig___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (fairygui::UIConfig *)olua_toobj(L, 1, "fgui.UIConfig");
    olua_push_cppobj(L, self, "fgui.UIConfig");

    olua_endinvoke(L);

    return 1;
}

static int _fairygui_UIConfig_getRealFontName(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** aliasName */
    bool arg2 = false;       /** isTTF */

    olua_check_std_string(L, 1, &arg1);
    // no need to check 'arg2' with mark '@out'

    // static const std::string &getRealFontName(const std::string &aliasName, @out bool *isTTF)
    const std::string &ret = (const std::string &)fairygui::UIConfig::getRealFontName(arg1, &arg2);
    int num_ret = olua_push_std_string(L, ret);
    olua_push_bool(L, arg2);

    olua_endinvoke(L);

    return num_ret + 1;
}

static int _fairygui_UIConfig_registerFont(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** aliasName */
    std::string arg2;       /** realName */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);

    // static void registerFont(const std::string &aliasName, const std::string &realName)
    fairygui::UIConfig::registerFont(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_UIConfig_get_bringWindowToFrontOnClick(lua_State *L)
{
    olua_startinvoke(L);

    // static bool bringWindowToFrontOnClick
    bool ret = (bool)fairygui::UIConfig::bringWindowToFrontOnClick;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_UIConfig_set_bringWindowToFrontOnClick(lua_State *L)
{
    olua_startinvoke(L);

    bool arg1 = false;       /** bringWindowToFrontOnClick */

    olua_check_bool(L, 1, &arg1);

    // static bool bringWindowToFrontOnClick
    fairygui::UIConfig::bringWindowToFrontOnClick = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_UIConfig_get_buttonSound(lua_State *L)
{
    olua_startinvoke(L);

    // static std::string buttonSound
    std::string ret = (std::string)fairygui::UIConfig::buttonSound;
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_UIConfig_set_buttonSound(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** buttonSound */

    olua_check_std_string(L, 1, &arg1);

    // static std::string buttonSound
    fairygui::UIConfig::buttonSound = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_UIConfig_get_buttonSoundVolumeScale(lua_State *L)
{
    olua_startinvoke(L);

    // static float buttonSoundVolumeScale
    float ret = (float)fairygui::UIConfig::buttonSoundVolumeScale;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_UIConfig_set_buttonSoundVolumeScale(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** buttonSoundVolumeScale */

    olua_check_number(L, 1, &arg1);

    // static float buttonSoundVolumeScale
    fairygui::UIConfig::buttonSoundVolumeScale = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_UIConfig_get_clickDragSensitivity(lua_State *L)
{
    olua_startinvoke(L);

    // static int clickDragSensitivity
    int ret = (int)fairygui::UIConfig::clickDragSensitivity;
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_UIConfig_set_clickDragSensitivity(lua_State *L)
{
    olua_startinvoke(L);

    lua_Integer arg1 = 0;       /** clickDragSensitivity */

    olua_check_int(L, 1, &arg1);

    // static int clickDragSensitivity
    fairygui::UIConfig::clickDragSensitivity = (int)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_UIConfig_get_defaultComboBoxVisibleItemCount(lua_State *L)
{
    olua_startinvoke(L);

    // static int defaultComboBoxVisibleItemCount
    int ret = (int)fairygui::UIConfig::defaultComboBoxVisibleItemCount;
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_UIConfig_set_defaultComboBoxVisibleItemCount(lua_State *L)
{
    olua_startinvoke(L);

    lua_Integer arg1 = 0;       /** defaultComboBoxVisibleItemCount */

    olua_check_int(L, 1, &arg1);

    // static int defaultComboBoxVisibleItemCount
    fairygui::UIConfig::defaultComboBoxVisibleItemCount = (int)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_UIConfig_get_defaultFont(lua_State *L)
{
    olua_startinvoke(L);

    // static std::string defaultFont
    std::string ret = (std::string)fairygui::UIConfig::defaultFont;
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_UIConfig_set_defaultFont(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** defaultFont */

    olua_check_std_string(L, 1, &arg1);

    // static std::string defaultFont
    fairygui::UIConfig::defaultFont = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_UIConfig_get_defaultScrollBarDisplay(lua_State *L)
{
    olua_startinvoke(L);

    // static fairygui::ScrollBarDisplayType defaultScrollBarDisplay
    fairygui::ScrollBarDisplayType ret = (fairygui::ScrollBarDisplayType)fairygui::UIConfig::defaultScrollBarDisplay;
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_UIConfig_set_defaultScrollBarDisplay(lua_State *L)
{
    olua_startinvoke(L);

    lua_Unsigned arg1 = 0;       /** defaultScrollBarDisplay */

    olua_check_uint(L, 1, &arg1);

    // static fairygui::ScrollBarDisplayType defaultScrollBarDisplay
    fairygui::UIConfig::defaultScrollBarDisplay = (fairygui::ScrollBarDisplayType)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_UIConfig_get_defaultScrollBounceEffect(lua_State *L)
{
    olua_startinvoke(L);

    // static bool defaultScrollBounceEffect
    bool ret = (bool)fairygui::UIConfig::defaultScrollBounceEffect;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_UIConfig_set_defaultScrollBounceEffect(lua_State *L)
{
    olua_startinvoke(L);

    bool arg1 = false;       /** defaultScrollBounceEffect */

    olua_check_bool(L, 1, &arg1);

    // static bool defaultScrollBounceEffect
    fairygui::UIConfig::defaultScrollBounceEffect = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_UIConfig_get_defaultScrollDecelerationRate(lua_State *L)
{
    olua_startinvoke(L);

    // static float defaultScrollDecelerationRate
    float ret = (float)fairygui::UIConfig::defaultScrollDecelerationRate;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_UIConfig_set_defaultScrollDecelerationRate(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** defaultScrollDecelerationRate */

    olua_check_number(L, 1, &arg1);

    // static float defaultScrollDecelerationRate
    fairygui::UIConfig::defaultScrollDecelerationRate = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_UIConfig_get_defaultScrollStep(lua_State *L)
{
    olua_startinvoke(L);

    // static int defaultScrollStep
    int ret = (int)fairygui::UIConfig::defaultScrollStep;
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_UIConfig_set_defaultScrollStep(lua_State *L)
{
    olua_startinvoke(L);

    lua_Integer arg1 = 0;       /** defaultScrollStep */

    olua_check_int(L, 1, &arg1);

    // static int defaultScrollStep
    fairygui::UIConfig::defaultScrollStep = (int)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_UIConfig_get_defaultScrollTouchEffect(lua_State *L)
{
    olua_startinvoke(L);

    // static bool defaultScrollTouchEffect
    bool ret = (bool)fairygui::UIConfig::defaultScrollTouchEffect;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_UIConfig_set_defaultScrollTouchEffect(lua_State *L)
{
    olua_startinvoke(L);

    bool arg1 = false;       /** defaultScrollTouchEffect */

    olua_check_bool(L, 1, &arg1);

    // static bool defaultScrollTouchEffect
    fairygui::UIConfig::defaultScrollTouchEffect = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_UIConfig_get_globalModalWaiting(lua_State *L)
{
    olua_startinvoke(L);

    // static std::string globalModalWaiting
    std::string ret = (std::string)fairygui::UIConfig::globalModalWaiting;
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_UIConfig_set_globalModalWaiting(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** globalModalWaiting */

    olua_check_std_string(L, 1, &arg1);

    // static std::string globalModalWaiting
    fairygui::UIConfig::globalModalWaiting = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_UIConfig_get_horizontalScrollBar(lua_State *L)
{
    olua_startinvoke(L);

    // static std::string horizontalScrollBar
    std::string ret = (std::string)fairygui::UIConfig::horizontalScrollBar;
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_UIConfig_set_horizontalScrollBar(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** horizontalScrollBar */

    olua_check_std_string(L, 1, &arg1);

    // static std::string horizontalScrollBar
    fairygui::UIConfig::horizontalScrollBar = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_UIConfig_get_modalLayerColor(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::Color4F modalLayerColor
    cocos2d::Color4F ret = (cocos2d::Color4F)fairygui::UIConfig::modalLayerColor;
    int num_ret = manual_olua_push_cocos2d_Color4F(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_UIConfig_set_modalLayerColor(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Color4F arg1;       /** modalLayerColor */

    manual_olua_check_cocos2d_Color4F(L, 1, &arg1);

    // static cocos2d::Color4F modalLayerColor
    fairygui::UIConfig::modalLayerColor = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_UIConfig_get_popupMenu(lua_State *L)
{
    olua_startinvoke(L);

    // static std::string popupMenu
    std::string ret = (std::string)fairygui::UIConfig::popupMenu;
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_UIConfig_set_popupMenu(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** popupMenu */

    olua_check_std_string(L, 1, &arg1);

    // static std::string popupMenu
    fairygui::UIConfig::popupMenu = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_UIConfig_get_popupMenu_seperator(lua_State *L)
{
    olua_startinvoke(L);

    // static std::string popupMenu_seperator
    std::string ret = (std::string)fairygui::UIConfig::popupMenu_seperator;
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_UIConfig_set_popupMenu_seperator(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** popupMenu_seperator */

    olua_check_std_string(L, 1, &arg1);

    // static std::string popupMenu_seperator
    fairygui::UIConfig::popupMenu_seperator = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_UIConfig_get_tooltipsWin(lua_State *L)
{
    olua_startinvoke(L);

    // static std::string tooltipsWin
    std::string ret = (std::string)fairygui::UIConfig::tooltipsWin;
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_UIConfig_set_tooltipsWin(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** tooltipsWin */

    olua_check_std_string(L, 1, &arg1);

    // static std::string tooltipsWin
    fairygui::UIConfig::tooltipsWin = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_UIConfig_get_touchDragSensitivity(lua_State *L)
{
    olua_startinvoke(L);

    // static int touchDragSensitivity
    int ret = (int)fairygui::UIConfig::touchDragSensitivity;
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_UIConfig_set_touchDragSensitivity(lua_State *L)
{
    olua_startinvoke(L);

    lua_Integer arg1 = 0;       /** touchDragSensitivity */

    olua_check_int(L, 1, &arg1);

    // static int touchDragSensitivity
    fairygui::UIConfig::touchDragSensitivity = (int)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_UIConfig_get_touchScrollSensitivity(lua_State *L)
{
    olua_startinvoke(L);

    // static int touchScrollSensitivity
    int ret = (int)fairygui::UIConfig::touchScrollSensitivity;
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_UIConfig_set_touchScrollSensitivity(lua_State *L)
{
    olua_startinvoke(L);

    lua_Integer arg1 = 0;       /** touchScrollSensitivity */

    olua_check_int(L, 1, &arg1);

    // static int touchScrollSensitivity
    fairygui::UIConfig::touchScrollSensitivity = (int)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_UIConfig_get_verticalScrollBar(lua_State *L)
{
    olua_startinvoke(L);

    // static std::string verticalScrollBar
    std::string ret = (std::string)fairygui::UIConfig::verticalScrollBar;
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_UIConfig_set_verticalScrollBar(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** verticalScrollBar */

    olua_check_std_string(L, 1, &arg1);

    // static std::string verticalScrollBar
    fairygui::UIConfig::verticalScrollBar = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_UIConfig_get_windowModalWaiting(lua_State *L)
{
    olua_startinvoke(L);

    // static std::string windowModalWaiting
    std::string ret = (std::string)fairygui::UIConfig::windowModalWaiting;
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_UIConfig_set_windowModalWaiting(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** windowModalWaiting */

    olua_check_std_string(L, 1, &arg1);

    // static std::string windowModalWaiting
    fairygui::UIConfig::windowModalWaiting = arg1;

    olua_endinvoke(L);

    return 0;
}

static int luaopen_fairygui_UIConfig(lua_State *L)
{
    oluacls_class(L, "fgui.UIConfig", nullptr);
    oluacls_func(L, "__move", _fairygui_UIConfig___move);
    oluacls_func(L, "getRealFontName", _fairygui_UIConfig_getRealFontName);
    oluacls_func(L, "registerFont", _fairygui_UIConfig_registerFont);
    oluacls_prop(L, "bringWindowToFrontOnClick", _fairygui_UIConfig_get_bringWindowToFrontOnClick, _fairygui_UIConfig_set_bringWindowToFrontOnClick);
    oluacls_prop(L, "buttonSound", _fairygui_UIConfig_get_buttonSound, _fairygui_UIConfig_set_buttonSound);
    oluacls_prop(L, "buttonSoundVolumeScale", _fairygui_UIConfig_get_buttonSoundVolumeScale, _fairygui_UIConfig_set_buttonSoundVolumeScale);
    oluacls_prop(L, "clickDragSensitivity", _fairygui_UIConfig_get_clickDragSensitivity, _fairygui_UIConfig_set_clickDragSensitivity);
    oluacls_prop(L, "defaultComboBoxVisibleItemCount", _fairygui_UIConfig_get_defaultComboBoxVisibleItemCount, _fairygui_UIConfig_set_defaultComboBoxVisibleItemCount);
    oluacls_prop(L, "defaultFont", _fairygui_UIConfig_get_defaultFont, _fairygui_UIConfig_set_defaultFont);
    oluacls_prop(L, "defaultScrollBarDisplay", _fairygui_UIConfig_get_defaultScrollBarDisplay, _fairygui_UIConfig_set_defaultScrollBarDisplay);
    oluacls_prop(L, "defaultScrollBounceEffect", _fairygui_UIConfig_get_defaultScrollBounceEffect, _fairygui_UIConfig_set_defaultScrollBounceEffect);
    oluacls_prop(L, "defaultScrollDecelerationRate", _fairygui_UIConfig_get_defaultScrollDecelerationRate, _fairygui_UIConfig_set_defaultScrollDecelerationRate);
    oluacls_prop(L, "defaultScrollStep", _fairygui_UIConfig_get_defaultScrollStep, _fairygui_UIConfig_set_defaultScrollStep);
    oluacls_prop(L, "defaultScrollTouchEffect", _fairygui_UIConfig_get_defaultScrollTouchEffect, _fairygui_UIConfig_set_defaultScrollTouchEffect);
    oluacls_prop(L, "globalModalWaiting", _fairygui_UIConfig_get_globalModalWaiting, _fairygui_UIConfig_set_globalModalWaiting);
    oluacls_prop(L, "horizontalScrollBar", _fairygui_UIConfig_get_horizontalScrollBar, _fairygui_UIConfig_set_horizontalScrollBar);
    oluacls_prop(L, "modalLayerColor", _fairygui_UIConfig_get_modalLayerColor, _fairygui_UIConfig_set_modalLayerColor);
    oluacls_prop(L, "popupMenu", _fairygui_UIConfig_get_popupMenu, _fairygui_UIConfig_set_popupMenu);
    oluacls_prop(L, "popupMenu_seperator", _fairygui_UIConfig_get_popupMenu_seperator, _fairygui_UIConfig_set_popupMenu_seperator);
    oluacls_prop(L, "tooltipsWin", _fairygui_UIConfig_get_tooltipsWin, _fairygui_UIConfig_set_tooltipsWin);
    oluacls_prop(L, "touchDragSensitivity", _fairygui_UIConfig_get_touchDragSensitivity, _fairygui_UIConfig_set_touchDragSensitivity);
    oluacls_prop(L, "touchScrollSensitivity", _fairygui_UIConfig_get_touchScrollSensitivity, _fairygui_UIConfig_set_touchScrollSensitivity);
    oluacls_prop(L, "verticalScrollBar", _fairygui_UIConfig_get_verticalScrollBar, _fairygui_UIConfig_set_verticalScrollBar);
    oluacls_prop(L, "windowModalWaiting", _fairygui_UIConfig_get_windowModalWaiting, _fairygui_UIConfig_set_windowModalWaiting);

    olua_registerluatype<fairygui::UIConfig>(L, "fgui.UIConfig");

    return 1;
}

static int _fairygui_IUISource___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (fairygui::IUISource *)olua_toobj(L, 1, "fgui.IUISource");
    olua_push_cppobj(L, self, "fgui.IUISource");

    olua_endinvoke(L);

    return 1;
}

static int _fairygui_IUISource_getFileName(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::IUISource *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.IUISource");

    // const std::string &getFileName()
    const std::string &ret = (const std::string &)self->getFileName();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_IUISource_isLoaded(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::IUISource *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.IUISource");

    // bool isLoaded()
    bool ret = (bool)self->isLoaded();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_IUISource_load(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::IUISource *self = nullptr;
    std::function<void()> arg1;       /** callback */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.IUISource");

    if (olua_is_std_function(L, 2)) {
        void *self_obj = (void *)self;
        std::string tag = "load";
        std::string func = olua_setcallback(L, self_obj, tag.c_str(), 2, OLUA_TAG_REPLACE);
        lua_Unsigned ctx = olua_context(L);
        arg1 = [self_obj, func, ctx]() {
            lua_State *L = olua_mainthread(NULL);

            if (L != NULL && (olua_context(L) == ctx)) {
                int top = lua_gettop(L);

                olua_callback(L, self_obj, func.c_str(), 0);

                lua_settop(L, top);
            }
        };
    } else {
        void *self_obj = (void *)self;
        std::string tag = "load";
        olua_removecallback(L, self_obj, tag.c_str(), OLUA_TAG_SUBEQUAL);
        arg1 = nullptr;
    }

    // void load(@nullable @local std::function<void ()> callback)
    self->load(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_IUISource_setFileName(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::IUISource *self = nullptr;
    std::string arg1;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.IUISource");
    olua_check_std_string(L, 2, &arg1);

    // void setFileName(const std::string &value)
    self->setFileName(arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_fairygui_IUISource(lua_State *L)
{
    oluacls_class(L, "fgui.IUISource", "cc.Ref");
    oluacls_func(L, "__move", _fairygui_IUISource___move);
    oluacls_func(L, "getFileName", _fairygui_IUISource_getFileName);
    oluacls_func(L, "isLoaded", _fairygui_IUISource_isLoaded);
    oluacls_func(L, "load", _fairygui_IUISource_load);
    oluacls_func(L, "setFileName", _fairygui_IUISource_setFileName);
    oluacls_prop(L, "fileName", _fairygui_IUISource_getFileName, _fairygui_IUISource_setFileName);
    oluacls_prop(L, "loaded", _fairygui_IUISource_isLoaded, nullptr);

    olua_registerluatype<fairygui::IUISource>(L, "fgui.IUISource");

    return 1;
}

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

static int _fairygui_UISource___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (fairygui::UISource *)olua_toobj(L, 1, "fgui.UISource");
    olua_push_cppobj(L, self, "fgui.UISource");

    olua_endinvoke(L);

    return 1;
}

static int _fairygui_UISource_create(lua_State *L)
{
    olua_startinvoke(L);

    // static UISource *create()
    fairygui::UISource *ret = (fairygui::UISource *)fairygui::UISource::create();
    int num_ret = olua_push_cppobj(L, ret, "fgui.UISource");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_UISource_loadComplete(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::UISource *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.UISource");

    // void loadComplete()
    self->loadComplete();

    olua_endinvoke(L);

    return 0;
}

static int luaopen_fairygui_UISource(lua_State *L)
{
    oluacls_class(L, "fgui.UISource", "fgui.IUISource");
    oluacls_func(L, "__move", _fairygui_UISource___move);
    oluacls_func(L, "create", _fairygui_UISource_create);
    oluacls_func(L, "loadComplete", _fairygui_UISource_loadComplete);

    olua_registerluatype<fairygui::UISource>(L, "fgui.UISource");

    return 1;
}

static int _fairygui_Window___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (fairygui::Window *)olua_toobj(L, 1, "fgui.Window");
    olua_push_cppobj(L, self, "fgui.Window");

    olua_endinvoke(L);

    return 1;
}

static int _fairygui_Window_addUISource(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::Window *self = nullptr;
    fairygui::IUISource *arg1 = nullptr;       /** uiSource */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.Window");
    olua_check_cppobj(L, 2, (void **)&arg1, "fgui.IUISource");

    // void addUISource(fairygui::IUISource *uiSource)
    self->addUISource(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_Window_bringToFront(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::Window *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.Window");

    // void bringToFront()
    self->bringToFront();

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_Window_closeModalWait1(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::Window *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.Window");

    // bool closeModalWait()
    bool ret = (bool)self->closeModalWait();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_Window_closeModalWait2(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::Window *self = nullptr;
    lua_Integer arg1 = 0;       /** requestingCmd */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.Window");
    olua_check_int(L, 2, &arg1);

    // bool closeModalWait(int requestingCmd)
    bool ret = (bool)self->closeModalWait((int)arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_Window_closeModalWait(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // bool closeModalWait()
        return _fairygui_Window_closeModalWait1(L);
    }

    if (num_args == 1) {
        // if ((olua_is_int(L, 2))) {
            // bool closeModalWait(int requestingCmd)
            return _fairygui_Window_closeModalWait2(L);
        // }
    }

    luaL_error(L, "method 'fairygui::Window::closeModalWait' not support '%d' arguments", num_args);

    return 0;
}

static int _fairygui_Window_create(lua_State *L)
{
    olua_startinvoke(L);

    // static fairygui::Window *create()
    fairygui::Window *ret = (fairygui::Window *)fairygui::Window::create();
    int num_ret = olua_push_cppobj(L, ret, "fgui.Window");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_Window_getCloseButton(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::Window *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.Window");

    // @addref(closeButton ^) fairygui::GObject *getCloseButton()
    fairygui::GObject *ret = (fairygui::GObject *)self->getCloseButton();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GObject");

    // inject code after call
    olua_addref(L, 1, "closeButton", -1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_Window_getContentArea(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::Window *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.Window");

    // @addref(contentArea ^) fairygui::GObject *getContentArea()
    fairygui::GObject *ret = (fairygui::GObject *)self->getContentArea();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GObject");

    // inject code after call
    olua_addref(L, 1, "contentArea", -1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_Window_getContentPane(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::Window *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.Window");

    // @addref(contentPane ^) fairygui::GComponent *getContentPane()
    fairygui::GComponent *ret = (fairygui::GComponent *)self->getContentPane();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GComponent");

    // inject code after call
    olua_addref(L, 1, "contentPane", -1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_Window_getDragArea(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::Window *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.Window");

    // @addref(dragArea ^) fairygui::GObject *getDragArea()
    fairygui::GObject *ret = (fairygui::GObject *)self->getDragArea();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GObject");

    // inject code after call
    olua_addref(L, 1, "dragArea", -1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_Window_getFrame(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::Window *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.Window");

    // @addref(frame ^) fairygui::GComponent *getFrame()
    fairygui::GComponent *ret = (fairygui::GComponent *)self->getFrame();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GComponent");

    // inject code after call
    olua_addref(L, 1, "frame", -1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_Window_getModalWaitingPane(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::Window *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.Window");

    // @addref(modalWaitingPane ^) fairygui::GObject *getModalWaitingPane()
    fairygui::GObject *ret = (fairygui::GObject *)self->getModalWaitingPane();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GObject");

    // inject code after call
    olua_addref(L, 1, "modalWaitingPane", -1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_Window_hide(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::Window *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.Window");

    // inject code before call
    fairygui::GComponent *root = self->getParent() ? self->getParent() : fairygui::UIRoot;
    if (!root) {
        return 0;
    }
    olua_push_cppobj<fairygui::GComponent>(L, root);
    int parent = lua_gettop(L);
    olua_startcmpdelref(L, parent, "children");

    // @delref(children ~ parent) void hide()
    self->hide();

    // inject code after call
    olua_endcmpdelref(L, parent, "children");

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_Window_hideImmediately(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::Window *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.Window");

    // inject code before call
    fairygui::GComponent *root = self->getParent() ? self->getParent() : fairygui::UIRoot;
    if (!root) {
        return 0;
    }
    olua_push_cppobj<fairygui::GComponent>(L, root);
    int parent = lua_gettop(L);
    olua_startcmpdelref(L, parent, "children");

    // @delref(children ~ parent) void hideImmediately()
    self->hideImmediately();

    // inject code after call
    olua_endcmpdelref(L, parent, "children");

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_Window_initWindow(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::Window *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.Window");

    // void initWindow()
    self->initWindow();

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_Window_isBringToFrontOnClick(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::Window *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.Window");

    // bool isBringToFrontOnClick()
    bool ret = (bool)self->isBringToFrontOnClick();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_Window_isModal(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::Window *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.Window");

    // bool isModal()
    bool ret = (bool)self->isModal();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_Window_isShowing(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::Window *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.Window");

    // bool isShowing()
    bool ret = (bool)self->isShowing();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_Window_isTop(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::Window *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.Window");

    // bool isTop()
    bool ret = (bool)self->isTop();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_Window_new(lua_State *L)
{
    olua_startinvoke(L);

    // Window()
    fairygui::Window *ret = (fairygui::Window *)new fairygui::Window();
    int num_ret = olua_push_cppobj(L, ret, "fgui.Window");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_Window_setBringToFrontOnClick(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::Window *self = nullptr;
    bool arg1 = false;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.Window");
    olua_check_bool(L, 2, &arg1);

    // void setBringToFrontOnClick(bool value)
    self->setBringToFrontOnClick(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_Window_setCloseButton(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::Window *self = nullptr;
    fairygui::GObject *arg1 = nullptr;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.Window");
    olua_check_cppobj(L, 2, (void **)&arg1, "fgui.GObject");

    // void setCloseButton(@addref(closeButton ^) fairygui::GObject *value)
    self->setCloseButton(arg1);

    // inject code after call
    olua_addref(L, 1, "closeButton", 2, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_Window_setContentArea(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::Window *self = nullptr;
    fairygui::GObject *arg1 = nullptr;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.Window");
    olua_check_cppobj(L, 2, (void **)&arg1, "fgui.GObject");

    // void setContentArea(@addref(contentArea ^) fairygui::GObject *value)
    self->setContentArea(arg1);

    // inject code after call
    olua_addref(L, 1, "contentArea", 2, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_Window_setContentPane(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::Window *self = nullptr;
    fairygui::GComponent *arg1 = nullptr;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.Window");
    olua_check_cppobj(L, 2, (void **)&arg1, "fgui.GComponent");

    // void setContentPane(@addref(contentPane ^) fairygui::GComponent *value)
    self->setContentPane(arg1);

    // inject code after call
    olua_addref(L, 1, "contentPane", 2, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_Window_setDragArea(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::Window *self = nullptr;
    fairygui::GObject *arg1 = nullptr;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.Window");
    olua_check_cppobj(L, 2, (void **)&arg1, "fgui.GObject");

    // void setDragArea(@addref(dragArea ^) fairygui::GObject *value)
    self->setDragArea(arg1);

    // inject code after call
    olua_addref(L, 1, "dragArea", 2, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_Window_setModal(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::Window *self = nullptr;
    bool arg1 = false;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.Window");
    olua_check_bool(L, 2, &arg1);

    // void setModal(bool value)
    self->setModal(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_Window_show(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::Window *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.Window");

    // inject code before call
    fairygui::GComponent *root = fairygui::UIRoot;
    if (!root) {
        luaL_error(L, "no root to add 'Window'");
    }
    olua_push_cppobj<fairygui::GComponent>(L, root);
    int parent = lua_gettop(L);
    olua_startcmpdelref(L, parent, "children");

    // @delref(children ~ parent)@addref(children | parent) void show()
    self->show();

    // inject code after call
    olua_addref(L, parent, "children", 1, OLUA_MODE_MULTIPLE);
    olua_endcmpdelref(L, parent, "children");

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_Window_showModalWait1(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::Window *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.Window");

    // void showModalWait()
    self->showModalWait();

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_Window_showModalWait2(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::Window *self = nullptr;
    lua_Integer arg1 = 0;       /** requestingCmd */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.Window");
    olua_check_int(L, 2, &arg1);

    // void showModalWait(int requestingCmd)
    self->showModalWait((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_Window_showModalWait(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // void showModalWait()
        return _fairygui_Window_showModalWait1(L);
    }

    if (num_args == 1) {
        // if ((olua_is_int(L, 2))) {
            // void showModalWait(int requestingCmd)
            return _fairygui_Window_showModalWait2(L);
        // }
    }

    luaL_error(L, "method 'fairygui::Window::showModalWait' not support '%d' arguments", num_args);

    return 0;
}

static int _fairygui_Window_toggleStatus(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::Window *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.Window");

    // void toggleStatus()
    self->toggleStatus();

    olua_endinvoke(L);

    return 0;
}

static int luaopen_fairygui_Window(lua_State *L)
{
    oluacls_class(L, "fgui.Window", "fgui.GComponent");
    oluacls_func(L, "__move", _fairygui_Window___move);
    oluacls_func(L, "addUISource", _fairygui_Window_addUISource);
    oluacls_func(L, "bringToFront", _fairygui_Window_bringToFront);
    oluacls_func(L, "closeModalWait", _fairygui_Window_closeModalWait);
    oluacls_func(L, "create", _fairygui_Window_create);
    oluacls_func(L, "getCloseButton", _fairygui_Window_getCloseButton);
    oluacls_func(L, "getContentArea", _fairygui_Window_getContentArea);
    oluacls_func(L, "getContentPane", _fairygui_Window_getContentPane);
    oluacls_func(L, "getDragArea", _fairygui_Window_getDragArea);
    oluacls_func(L, "getFrame", _fairygui_Window_getFrame);
    oluacls_func(L, "getModalWaitingPane", _fairygui_Window_getModalWaitingPane);
    oluacls_func(L, "hide", _fairygui_Window_hide);
    oluacls_func(L, "hideImmediately", _fairygui_Window_hideImmediately);
    oluacls_func(L, "initWindow", _fairygui_Window_initWindow);
    oluacls_func(L, "isBringToFrontOnClick", _fairygui_Window_isBringToFrontOnClick);
    oluacls_func(L, "isModal", _fairygui_Window_isModal);
    oluacls_func(L, "isShowing", _fairygui_Window_isShowing);
    oluacls_func(L, "isTop", _fairygui_Window_isTop);
    oluacls_func(L, "new", _fairygui_Window_new);
    oluacls_func(L, "setBringToFrontOnClick", _fairygui_Window_setBringToFrontOnClick);
    oluacls_func(L, "setCloseButton", _fairygui_Window_setCloseButton);
    oluacls_func(L, "setContentArea", _fairygui_Window_setContentArea);
    oluacls_func(L, "setContentPane", _fairygui_Window_setContentPane);
    oluacls_func(L, "setDragArea", _fairygui_Window_setDragArea);
    oluacls_func(L, "setModal", _fairygui_Window_setModal);
    oluacls_func(L, "show", _fairygui_Window_show);
    oluacls_func(L, "showModalWait", _fairygui_Window_showModalWait);
    oluacls_func(L, "toggleStatus", _fairygui_Window_toggleStatus);
    oluacls_prop(L, "bringToFrontOnClick", _fairygui_Window_isBringToFrontOnClick, _fairygui_Window_setBringToFrontOnClick);
    oluacls_prop(L, "closeButton", _fairygui_Window_getCloseButton, _fairygui_Window_setCloseButton);
    oluacls_prop(L, "contentArea", _fairygui_Window_getContentArea, _fairygui_Window_setContentArea);
    oluacls_prop(L, "contentPane", _fairygui_Window_getContentPane, _fairygui_Window_setContentPane);
    oluacls_prop(L, "dragArea", _fairygui_Window_getDragArea, _fairygui_Window_setDragArea);
    oluacls_prop(L, "frame", _fairygui_Window_getFrame, nullptr);
    oluacls_prop(L, "modal", _fairygui_Window_isModal, _fairygui_Window_setModal);
    oluacls_prop(L, "modalWaitingPane", _fairygui_Window_getModalWaitingPane, nullptr);
    oluacls_prop(L, "showing", _fairygui_Window_isShowing, nullptr);
    oluacls_prop(L, "top", _fairygui_Window_isTop, nullptr);

    olua_registerluatype<fairygui::Window>(L, "fgui.Window");

    return 1;
}

static int _fairygui_DragDropManager___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (fairygui::DragDropManager *)olua_toobj(L, 1, "fgui.DragDropManager");
    lua_pushstring(L, ".ownership");
    olua_getvariable(L, 1);
    if (lua_toboolean(L, -1)) {
        olua_setrawobj(L, 1, nullptr);
        delete self;
    }

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_DragDropManager___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (fairygui::DragDropManager *)olua_toobj(L, 1, "fgui.DragDropManager");
    olua_push_cppobj(L, self, "fgui.DragDropManager");

    olua_endinvoke(L);

    return 1;
}

static int _fairygui_DragDropManager_cancel(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::DragDropManager *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.DragDropManager");

    // void cancel()
    self->cancel();

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_DragDropManager_getAgent(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::DragDropManager *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.DragDropManager");

    // fairygui::GLoader *getAgent()
    fairygui::GLoader *ret = (fairygui::GLoader *)self->getAgent();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GLoader");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_DragDropManager_getInstance(lua_State *L)
{
    olua_startinvoke(L);

    // static fairygui::DragDropManager *getInstance()
    fairygui::DragDropManager *ret = (fairygui::DragDropManager *)fairygui::DragDropManager::getInstance();
    int num_ret = olua_push_cppobj(L, ret, "fgui.DragDropManager");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_DragDropManager_isDragging(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::DragDropManager *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.DragDropManager");

    // bool isDragging()
    bool ret = (bool)self->isDragging();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_DragDropManager_new(lua_State *L)
{
    olua_startinvoke(L);

    // DragDropManager()
    fairygui::DragDropManager *ret = (fairygui::DragDropManager *)new fairygui::DragDropManager();
    int num_ret = olua_push_cppobj(L, ret, "fgui.DragDropManager");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_DragDropManager_startDrag1(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::DragDropManager *self = nullptr;
    std::string arg1;       /** icon */
    cocos2d::Value arg2;       /** sourceData */
    lua_Integer arg3 = 0;       /** touchPointID */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.DragDropManager");
    olua_check_std_string(L, 2, &arg1);
    manual_olua_check_cocos2d_Value(L, 3, &arg2);
    olua_check_int(L, 4, &arg3);

    // void startDrag(const std::string &icon, @optional const cocos2d::Value &sourceData, @optional int touchPointID)
    self->startDrag(arg1, arg2, (int)arg3);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_DragDropManager_startDrag2(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::DragDropManager *self = nullptr;
    std::string arg1;       /** icon */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.DragDropManager");
    olua_check_std_string(L, 2, &arg1);

    // void startDrag(const std::string &icon, @optional const cocos2d::Value &sourceData, @optional int touchPointID)
    self->startDrag(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_DragDropManager_startDrag3(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::DragDropManager *self = nullptr;
    std::string arg1;       /** icon */
    cocos2d::Value arg2;       /** sourceData */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.DragDropManager");
    olua_check_std_string(L, 2, &arg1);
    manual_olua_check_cocos2d_Value(L, 3, &arg2);

    // void startDrag(const std::string &icon, @optional const cocos2d::Value &sourceData, @optional int touchPointID)
    self->startDrag(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_DragDropManager_startDrag(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 2))) {
            // void startDrag(const std::string &icon, @optional const cocos2d::Value &sourceData, @optional int touchPointID)
            return _fairygui_DragDropManager_startDrag2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 2)) && (manual_olua_is_cocos2d_Value(L, 3))) {
            // void startDrag(const std::string &icon, @optional const cocos2d::Value &sourceData, @optional int touchPointID)
            return _fairygui_DragDropManager_startDrag3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_std_string(L, 2)) && (manual_olua_is_cocos2d_Value(L, 3)) && (olua_is_int(L, 4))) {
            // void startDrag(const std::string &icon, @optional const cocos2d::Value &sourceData, @optional int touchPointID)
            return _fairygui_DragDropManager_startDrag1(L);
        // }
    }

    luaL_error(L, "method 'fairygui::DragDropManager::startDrag' not support '%d' arguments", num_args);

    return 0;
}

static int luaopen_fairygui_DragDropManager(lua_State *L)
{
    oluacls_class(L, "fgui.DragDropManager", nullptr);
    oluacls_func(L, "__gc", _fairygui_DragDropManager___gc);
    oluacls_func(L, "__move", _fairygui_DragDropManager___move);
    oluacls_func(L, "cancel", _fairygui_DragDropManager_cancel);
    oluacls_func(L, "getAgent", _fairygui_DragDropManager_getAgent);
    oluacls_func(L, "getInstance", _fairygui_DragDropManager_getInstance);
    oluacls_func(L, "isDragging", _fairygui_DragDropManager_isDragging);
    oluacls_func(L, "new", _fairygui_DragDropManager_new);
    oluacls_func(L, "startDrag", _fairygui_DragDropManager_startDrag);
    oluacls_prop(L, "agent", _fairygui_DragDropManager_getAgent, nullptr);
    oluacls_prop(L, "dragging", _fairygui_DragDropManager_isDragging, nullptr);
    oluacls_prop(L, "instance", _fairygui_DragDropManager_getInstance, nullptr);

    olua_registerluatype<fairygui::DragDropManager>(L, "fgui.DragDropManager");

    return 1;
}

static int _fairygui_UIObjectFactory___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (fairygui::UIObjectFactory *)olua_toobj(L, 1, "fgui.UIObjectFactory");
    olua_push_cppobj(L, self, "fgui.UIObjectFactory");

    olua_endinvoke(L);

    return 1;
}

static int _fairygui_UIObjectFactory_newObject1(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::PackageItem *arg1 = nullptr;       /** pi */

    olua_check_cppobj(L, 1, (void **)&arg1, "fgui.PackageItem");

    // static fairygui::GObject *newObject(fairygui::PackageItem *pi)
    fairygui::GObject *ret = (fairygui::GObject *)fairygui::UIObjectFactory::newObject(arg1);
    int num_ret = olua_push_cppobj(L, ret, "fgui.GObject");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_UIObjectFactory_newObject2(lua_State *L)
{
    olua_startinvoke(L);

    lua_Unsigned arg1 = 0;       /** type */

    olua_check_uint(L, 1, &arg1);

    // static fairygui::GObject *newObject(fairygui::ObjectType type)
    fairygui::GObject *ret = (fairygui::GObject *)fairygui::UIObjectFactory::newObject((fairygui::ObjectType)arg1);
    int num_ret = olua_push_cppobj(L, ret, "fgui.GObject");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_UIObjectFactory_newObject(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        if ((olua_is_cppobj(L, 1, "fgui.PackageItem"))) {
            // static fairygui::GObject *newObject(fairygui::PackageItem *pi)
            return _fairygui_UIObjectFactory_newObject1(L);
        }

        // if ((olua_is_uint(L, 1))) {
            // static fairygui::GObject *newObject(fairygui::ObjectType type)
            return _fairygui_UIObjectFactory_newObject2(L);
        // }
    }

    luaL_error(L, "method 'fairygui::UIObjectFactory::newObject' not support '%d' arguments", num_args);

    return 0;
}

static int _fairygui_UIObjectFactory_setLoaderExtension(lua_State *L)
{
    olua_startinvoke(L);

    std::function<fairygui::GLoader *()> arg1;       /** creator */

    void *self_obj = (void *)olua_pushclassobj(L, "fgui.UIObjectFactory");
    std::string tag = "LoaderExtension";
    std::string func = olua_setcallback(L, self_obj, tag.c_str(), 1, OLUA_TAG_REPLACE);
    lua_Unsigned ctx = olua_context(L);
    arg1 = [self_obj, func, ctx]() {
        lua_State *L = olua_mainthread(NULL);
        fairygui::GLoader *ret = nullptr;       
        if (L != NULL && (olua_context(L) == ctx)) {
            int top = lua_gettop(L);

            olua_callback(L, self_obj, func.c_str(), 0);

            if (olua_is_cppobj(L, -1, "fgui.GLoader")) {
                olua_check_cppobj(L, -1, (void **)&ret, "fgui.GLoader");
            }

            lua_settop(L, top);
        }
        return ret;
    };

    // static void setLoaderExtension(@local std::function<GLoader *()> creator)
    fairygui::UIObjectFactory::setLoaderExtension(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_UIObjectFactory_setPackageItemExtension(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** url */
    std::function<fairygui::GComponent *()> arg2;       /** creator */

    olua_check_std_string(L, 1, &arg1);

    void *self_obj = (void *)olua_pushclassobj(L, "fgui.UIObjectFactory");
    std::string tag = "PackageItemExtension";
    std::string func = olua_setcallback(L, self_obj, tag.c_str(), 2, OLUA_TAG_REPLACE);
    lua_Unsigned ctx = olua_context(L);
    arg2 = [self_obj, func, ctx]() {
        lua_State *L = olua_mainthread(NULL);
        fairygui::GComponent *ret = nullptr;       
        if (L != NULL && (olua_context(L) == ctx)) {
            int top = lua_gettop(L);

            olua_callback(L, self_obj, func.c_str(), 0);

            if (olua_is_cppobj(L, -1, "fgui.GComponent")) {
                olua_check_cppobj(L, -1, (void **)&ret, "fgui.GComponent");
            }

            lua_settop(L, top);
        }
        return ret;
    };

    // static void setPackageItemExtension(const std::string &url, @local std::function<GComponent *()> creator)
    fairygui::UIObjectFactory::setPackageItemExtension(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_fairygui_UIObjectFactory(lua_State *L)
{
    oluacls_class(L, "fgui.UIObjectFactory", nullptr);
    oluacls_func(L, "__move", _fairygui_UIObjectFactory___move);
    oluacls_func(L, "newObject", _fairygui_UIObjectFactory_newObject);
    oluacls_func(L, "setLoaderExtension", _fairygui_UIObjectFactory_setLoaderExtension);
    oluacls_func(L, "setPackageItemExtension", _fairygui_UIObjectFactory_setPackageItemExtension);

    olua_registerluatype<fairygui::UIObjectFactory>(L, "fgui.UIObjectFactory");

    return 1;
}

static int _fairygui_GearBase___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (fairygui::GearBase *)olua_toobj(L, 1, "fgui.GearBase");
    lua_pushstring(L, ".ownership");
    olua_getvariable(L, 1);
    if (lua_toboolean(L, -1)) {
        olua_setrawobj(L, 1, nullptr);
        delete self;
    }

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GearBase___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (fairygui::GearBase *)olua_toobj(L, 1, "fgui.GearBase");
    olua_push_cppobj(L, self, "fgui.GearBase");

    olua_endinvoke(L);

    return 1;
}

static int _fairygui_GearBase_create(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *arg1 = nullptr;       /** owner */
    lua_Integer arg2 = 0;       /** index */

    olua_check_cppobj(L, 1, (void **)&arg1, "fgui.GObject");
    olua_check_int(L, 2, &arg2);

    // static fairygui::GearBase *create(fairygui::GObject *owner, int index)
    fairygui::GearBase *ret = (fairygui::GearBase *)fairygui::GearBase::create(arg1, (int)arg2);
    int num_ret = olua_push_cppobj(L, ret, "fgui.GearBase");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GearBase_new(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GObject *arg1 = nullptr;       /** owner */

    olua_check_cppobj(L, 1, (void **)&arg1, "fgui.GObject");

    // GearBase(fairygui::GObject *owner)
    fairygui::GearBase *ret = (fairygui::GearBase *)new fairygui::GearBase(arg1);
    int num_ret = olua_push_cppobj(L, ret, "fgui.GearBase");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GearBase_get_disableAllTweenEffect(lua_State *L)
{
    olua_startinvoke(L);

    // static bool disableAllTweenEffect
    bool ret = (bool)fairygui::GearBase::disableAllTweenEffect;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GearBase_set_disableAllTweenEffect(lua_State *L)
{
    olua_startinvoke(L);

    bool arg1 = false;       /** disableAllTweenEffect */

    olua_check_bool(L, 1, &arg1);

    // static bool disableAllTweenEffect
    fairygui::GearBase::disableAllTweenEffect = arg1;

    olua_endinvoke(L);

    return 0;
}

static int luaopen_fairygui_GearBase(lua_State *L)
{
    oluacls_class(L, "fgui.GearBase", nullptr);
    oluacls_func(L, "__gc", _fairygui_GearBase___gc);
    oluacls_func(L, "__move", _fairygui_GearBase___move);
    oluacls_func(L, "create", _fairygui_GearBase_create);
    oluacls_func(L, "new", _fairygui_GearBase_new);
    oluacls_prop(L, "disableAllTweenEffect", _fairygui_GearBase_get_disableAllTweenEffect, _fairygui_GearBase_set_disableAllTweenEffect);

    olua_registerluatype<fairygui::GearBase>(L, "fgui.GearBase");

    return 1;
}

static int _fairygui_GTreeNode___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (fairygui::GTreeNode *)olua_toobj(L, 1, "fgui.GTreeNode");
    olua_push_cppobj(L, self, "fgui.GTreeNode");

    olua_endinvoke(L);

    return 1;
}

static int _fairygui_GTreeNode_addChild(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTreeNode *self = nullptr;
    fairygui::GTreeNode *arg1 = nullptr;       /** child */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTreeNode");
    olua_check_cppobj(L, 2, (void **)&arg1, "fgui.GTreeNode");

    // fairygui::GTreeNode *addChild(@addref(children |) fairygui::GTreeNode *child)
    fairygui::GTreeNode *ret = (fairygui::GTreeNode *)self->addChild(arg1);
    int num_ret = olua_push_cppobj(L, ret, "fgui.GTreeNode");

    // inject code after call
    olua_addref(L, 1, "children", 2, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTreeNode_addChildAt(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTreeNode *self = nullptr;
    fairygui::GTreeNode *arg1 = nullptr;       /** child */
    lua_Integer arg2 = 0;       /** index */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTreeNode");
    olua_check_cppobj(L, 2, (void **)&arg1, "fgui.GTreeNode");
    olua_check_int(L, 3, &arg2);

    // fairygui::GTreeNode *addChildAt(@addref(children |) fairygui::GTreeNode *child, int index)
    fairygui::GTreeNode *ret = (fairygui::GTreeNode *)self->addChildAt(arg1, (int)arg2);
    int num_ret = olua_push_cppobj(L, ret, "fgui.GTreeNode");

    // inject code after call
    olua_addref(L, 1, "children", 2, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTreeNode_create1(lua_State *L)
{
    olua_startinvoke(L);

    bool arg1 = false;       /** isFolder */
    std::string arg2;       /** resURL */

    olua_check_bool(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);

    // static fairygui::GTreeNode *create(@optional bool isFolder, @optional const std::string &resURL)
    fairygui::GTreeNode *ret = (fairygui::GTreeNode *)fairygui::GTreeNode::create(arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "fgui.GTreeNode");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTreeNode_create2(lua_State *L)
{
    olua_startinvoke(L);

    // static fairygui::GTreeNode *create(@optional bool isFolder, @optional const std::string &resURL)
    fairygui::GTreeNode *ret = (fairygui::GTreeNode *)fairygui::GTreeNode::create();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GTreeNode");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTreeNode_create3(lua_State *L)
{
    olua_startinvoke(L);

    bool arg1 = false;       /** isFolder */

    olua_check_bool(L, 1, &arg1);

    // static fairygui::GTreeNode *create(@optional bool isFolder, @optional const std::string &resURL)
    fairygui::GTreeNode *ret = (fairygui::GTreeNode *)fairygui::GTreeNode::create(arg1);
    int num_ret = olua_push_cppobj(L, ret, "fgui.GTreeNode");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTreeNode_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // static fairygui::GTreeNode *create(@optional bool isFolder, @optional const std::string &resURL)
        return _fairygui_GTreeNode_create2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_bool(L, 1))) {
            // static fairygui::GTreeNode *create(@optional bool isFolder, @optional const std::string &resURL)
            return _fairygui_GTreeNode_create3(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_bool(L, 1)) && (olua_is_std_string(L, 2))) {
            // static fairygui::GTreeNode *create(@optional bool isFolder, @optional const std::string &resURL)
            return _fairygui_GTreeNode_create1(L);
        // }
    }

    luaL_error(L, "method 'fairygui::GTreeNode::create' not support '%d' arguments", num_args);

    return 0;
}

static int _fairygui_GTreeNode_getCell(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTreeNode *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTreeNode");

    // @addref(cell ^) fairygui::GComponent *getCell()
    fairygui::GComponent *ret = (fairygui::GComponent *)self->getCell();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GComponent");

    // inject code after call
    olua_addref(L, 1, "cell", -1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTreeNode_getChildAt(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTreeNode *self = nullptr;
    lua_Integer arg1 = 0;       /** index */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTreeNode");
    olua_check_int(L, 2, &arg1);

    // @addref(children |) fairygui::GTreeNode *getChildAt(int index)
    fairygui::GTreeNode *ret = (fairygui::GTreeNode *)self->getChildAt((int)arg1);
    int num_ret = olua_push_cppobj(L, ret, "fgui.GTreeNode");

    // inject code after call
    olua_addref(L, 1, "children", -1, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTreeNode_getChildIndex(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTreeNode *self = nullptr;
    fairygui::GTreeNode *arg1 = nullptr;       /** child */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTreeNode");
    olua_check_cppobj(L, 2, (void **)&arg1, "fgui.GTreeNode");

    // int getChildIndex(const fairygui::GTreeNode *child)
    int ret = (int)self->getChildIndex(arg1);
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTreeNode_getData(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTreeNode *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTreeNode");

    // const cocos2d::Value &getData()
    const cocos2d::Value &ret = (const cocos2d::Value &)self->getData();
    int num_ret = manual_olua_push_cocos2d_Value(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTreeNode_getIcon(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTreeNode *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTreeNode");

    // const std::string &getIcon()
    const std::string &ret = (const std::string &)self->getIcon();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTreeNode_getNextSibling(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTreeNode *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTreeNode");

    // @addref(children |) fairygui::GTreeNode *getNextSibling()
    fairygui::GTreeNode *ret = (fairygui::GTreeNode *)self->getNextSibling();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GTreeNode");

    // inject code after call
    olua_addref(L, 1, "children", -1, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTreeNode_getParent(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTreeNode *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTreeNode");

    // fairygui::GTreeNode *getParent()
    fairygui::GTreeNode *ret = (fairygui::GTreeNode *)self->getParent();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GTreeNode");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTreeNode_getPrevSibling(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTreeNode *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTreeNode");

    // @addref(children |) fairygui::GTreeNode *getPrevSibling()
    fairygui::GTreeNode *ret = (fairygui::GTreeNode *)self->getPrevSibling();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GTreeNode");

    // inject code after call
    olua_addref(L, 1, "children", -1, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTreeNode_getText(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTreeNode *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTreeNode");

    // const std::string &getText()
    const std::string &ret = (const std::string &)self->getText();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTreeNode_getTree(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTreeNode *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTreeNode");

    // fairygui::GTree *getTree()
    fairygui::GTree *ret = (fairygui::GTree *)self->getTree();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GTree");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTreeNode_isExpanded(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTreeNode *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTreeNode");

    // bool isExpanded()
    bool ret = (bool)self->isExpanded();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTreeNode_isFolder(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTreeNode *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTreeNode");

    // bool isFolder()
    bool ret = (bool)self->isFolder();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTreeNode_new(lua_State *L)
{
    olua_startinvoke(L);

    // GTreeNode()
    fairygui::GTreeNode *ret = (fairygui::GTreeNode *)new fairygui::GTreeNode();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GTreeNode");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTreeNode_numChildren(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTreeNode *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTreeNode");

    // int numChildren()
    int ret = (int)self->numChildren();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTreeNode_removeChild(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTreeNode *self = nullptr;
    fairygui::GTreeNode *arg1 = nullptr;       /** child */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTreeNode");
    olua_check_cppobj(L, 2, (void **)&arg1, "fgui.GTreeNode");

    // void removeChild(@delref(children |) fairygui::GTreeNode *child)
    self->removeChild(arg1);

    // inject code after call
    olua_delref(L, 1, "children", 2, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GTreeNode_removeChildAt(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTreeNode *self = nullptr;
    lua_Integer arg1 = 0;       /** index */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTreeNode");
    olua_check_int(L, 2, &arg1);

    // inject code before call
    olua_startcmpdelref(L, 1, "children");

    // @delref(children ~) void removeChildAt(int index)
    self->removeChildAt((int)arg1);

    // inject code after call
    olua_endcmpdelref(L, 1, "children");

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GTreeNode_removeChildren1(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTreeNode *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTreeNode");

    // inject code before call
    olua_startcmpdelref(L, 1, "children");

    // @delref(children ~) void removeChildren()
    self->removeChildren();

    // inject code after call
    olua_endcmpdelref(L, 1, "children");

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GTreeNode_removeChildren2(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTreeNode *self = nullptr;
    lua_Integer arg1 = 0;       /** beginIndex */
    lua_Integer arg2 = 0;       /** endIndex */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTreeNode");
    olua_check_int(L, 2, &arg1);
    olua_check_int(L, 3, &arg2);

    // inject code before call
    olua_startcmpdelref(L, 1, "children");

    // @delref(children ~) void removeChildren(int beginIndex, int endIndex)
    self->removeChildren((int)arg1, (int)arg2);

    // inject code after call
    olua_endcmpdelref(L, 1, "children");

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GTreeNode_removeChildren(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // @delref(children ~) void removeChildren()
        return _fairygui_GTreeNode_removeChildren1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_int(L, 2)) && (olua_is_int(L, 3))) {
            // @delref(children ~) void removeChildren(int beginIndex, int endIndex)
            return _fairygui_GTreeNode_removeChildren2(L);
        // }
    }

    luaL_error(L, "method 'fairygui::GTreeNode::removeChildren' not support '%d' arguments", num_args);

    return 0;
}

static int _fairygui_GTreeNode_setChildIndex(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTreeNode *self = nullptr;
    fairygui::GTreeNode *arg1 = nullptr;       /** child */
    lua_Integer arg2 = 0;       /** index */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTreeNode");
    olua_check_cppobj(L, 2, (void **)&arg1, "fgui.GTreeNode");
    olua_check_int(L, 3, &arg2);

    // void setChildIndex(fairygui::GTreeNode *child, int index)
    self->setChildIndex(arg1, (int)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GTreeNode_setChildIndexBefore(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTreeNode *self = nullptr;
    fairygui::GTreeNode *arg1 = nullptr;       /** child */
    lua_Integer arg2 = 0;       /** index */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTreeNode");
    olua_check_cppobj(L, 2, (void **)&arg1, "fgui.GTreeNode");
    olua_check_int(L, 3, &arg2);

    // int setChildIndexBefore(fairygui::GTreeNode *child, int index)
    int ret = (int)self->setChildIndexBefore(arg1, (int)arg2);
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTreeNode_setData(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTreeNode *self = nullptr;
    cocos2d::Value arg1;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTreeNode");
    manual_olua_check_cocos2d_Value(L, 2, &arg1);

    // void setData(const cocos2d::Value &value)
    self->setData(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GTreeNode_setExpaned(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTreeNode *self = nullptr;
    bool arg1 = false;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTreeNode");
    olua_check_bool(L, 2, &arg1);

    // void setExpaned(bool value)
    self->setExpaned(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GTreeNode_setIcon(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTreeNode *self = nullptr;
    std::string arg1;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTreeNode");
    olua_check_std_string(L, 2, &arg1);

    // void setIcon(const std::string &value)
    self->setIcon(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GTreeNode_setText(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTreeNode *self = nullptr;
    std::string arg1;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTreeNode");
    olua_check_std_string(L, 2, &arg1);

    // void setText(const std::string &value)
    self->setText(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GTreeNode_swapChildren(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTreeNode *self = nullptr;
    fairygui::GTreeNode *arg1 = nullptr;       /** child1 */
    fairygui::GTreeNode *arg2 = nullptr;       /** child2 */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTreeNode");
    olua_check_cppobj(L, 2, (void **)&arg1, "fgui.GTreeNode");
    olua_check_cppobj(L, 3, (void **)&arg2, "fgui.GTreeNode");

    // void swapChildren(fairygui::GTreeNode *child1, fairygui::GTreeNode *child2)
    self->swapChildren(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GTreeNode_swapChildrenAt(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTreeNode *self = nullptr;
    lua_Integer arg1 = 0;       /** index1 */
    lua_Integer arg2 = 0;       /** index2 */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTreeNode");
    olua_check_int(L, 2, &arg1);
    olua_check_int(L, 3, &arg2);

    // void swapChildrenAt(int index1, int index2)
    self->swapChildrenAt((int)arg1, (int)arg2);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_fairygui_GTreeNode(lua_State *L)
{
    oluacls_class(L, "fgui.GTreeNode", "cc.Ref");
    oluacls_func(L, "__move", _fairygui_GTreeNode___move);
    oluacls_func(L, "addChild", _fairygui_GTreeNode_addChild);
    oluacls_func(L, "addChildAt", _fairygui_GTreeNode_addChildAt);
    oluacls_func(L, "create", _fairygui_GTreeNode_create);
    oluacls_func(L, "getCell", _fairygui_GTreeNode_getCell);
    oluacls_func(L, "getChildAt", _fairygui_GTreeNode_getChildAt);
    oluacls_func(L, "getChildIndex", _fairygui_GTreeNode_getChildIndex);
    oluacls_func(L, "getData", _fairygui_GTreeNode_getData);
    oluacls_func(L, "getIcon", _fairygui_GTreeNode_getIcon);
    oluacls_func(L, "getNextSibling", _fairygui_GTreeNode_getNextSibling);
    oluacls_func(L, "getParent", _fairygui_GTreeNode_getParent);
    oluacls_func(L, "getPrevSibling", _fairygui_GTreeNode_getPrevSibling);
    oluacls_func(L, "getText", _fairygui_GTreeNode_getText);
    oluacls_func(L, "getTree", _fairygui_GTreeNode_getTree);
    oluacls_func(L, "isExpanded", _fairygui_GTreeNode_isExpanded);
    oluacls_func(L, "isFolder", _fairygui_GTreeNode_isFolder);
    oluacls_func(L, "new", _fairygui_GTreeNode_new);
    oluacls_func(L, "numChildren", _fairygui_GTreeNode_numChildren);
    oluacls_func(L, "removeChild", _fairygui_GTreeNode_removeChild);
    oluacls_func(L, "removeChildAt", _fairygui_GTreeNode_removeChildAt);
    oluacls_func(L, "removeChildren", _fairygui_GTreeNode_removeChildren);
    oluacls_func(L, "setChildIndex", _fairygui_GTreeNode_setChildIndex);
    oluacls_func(L, "setChildIndexBefore", _fairygui_GTreeNode_setChildIndexBefore);
    oluacls_func(L, "setData", _fairygui_GTreeNode_setData);
    oluacls_func(L, "setExpaned", _fairygui_GTreeNode_setExpaned);
    oluacls_func(L, "setIcon", _fairygui_GTreeNode_setIcon);
    oluacls_func(L, "setText", _fairygui_GTreeNode_setText);
    oluacls_func(L, "swapChildren", _fairygui_GTreeNode_swapChildren);
    oluacls_func(L, "swapChildrenAt", _fairygui_GTreeNode_swapChildrenAt);
    oluacls_prop(L, "cell", _fairygui_GTreeNode_getCell, nullptr);
    oluacls_prop(L, "data", _fairygui_GTreeNode_getData, _fairygui_GTreeNode_setData);
    oluacls_prop(L, "expanded", _fairygui_GTreeNode_isExpanded, nullptr);
    oluacls_prop(L, "folder", _fairygui_GTreeNode_isFolder, nullptr);
    oluacls_prop(L, "icon", _fairygui_GTreeNode_getIcon, _fairygui_GTreeNode_setIcon);
    oluacls_prop(L, "nextSibling", _fairygui_GTreeNode_getNextSibling, nullptr);
    oluacls_prop(L, "numChildren", _fairygui_GTreeNode_numChildren, nullptr);
    oluacls_prop(L, "parent", _fairygui_GTreeNode_getParent, nullptr);
    oluacls_prop(L, "prevSibling", _fairygui_GTreeNode_getPrevSibling, nullptr);
    oluacls_prop(L, "text", _fairygui_GTreeNode_getText, _fairygui_GTreeNode_setText);
    oluacls_prop(L, "tree", _fairygui_GTreeNode_getTree, nullptr);

    olua_registerluatype<fairygui::GTreeNode>(L, "fgui.GTreeNode");

    return 1;
}

static int _fairygui_GTree___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (fairygui::GTree *)olua_toobj(L, 1, "fgui.GTree");
    olua_push_cppobj(L, self, "fgui.GTree");

    olua_endinvoke(L);

    return 1;
}

static int _fairygui_GTree_collapseAll(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTree *self = nullptr;
    fairygui::GTreeNode *arg1 = nullptr;       /** folderNode */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTree");
    olua_check_cppobj(L, 2, (void **)&arg1, "fgui.GTreeNode");

    // void collapseAll(fairygui::GTreeNode *folderNode)
    self->collapseAll(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GTree_create(lua_State *L)
{
    olua_startinvoke(L);

    // static fairygui::GTree *create()
    fairygui::GTree *ret = (fairygui::GTree *)fairygui::GTree::create();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GTree");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTree_expandAll(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTree *self = nullptr;
    fairygui::GTreeNode *arg1 = nullptr;       /** folderNode */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTree");
    olua_check_cppobj(L, 2, (void **)&arg1, "fgui.GTreeNode");

    // void expandAll(fairygui::GTreeNode *folderNode)
    self->expandAll(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GTree_getClickToExpand(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTree *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTree");

    // int getClickToExpand()
    int ret = (int)self->getClickToExpand();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTree_getIndent(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTree *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTree");

    // int getIndent()
    int ret = (int)self->getIndent();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTree_getRootNode(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTree *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTree");

    // @addref(rootNode ^) fairygui::GTreeNode *getRootNode()
    fairygui::GTreeNode *ret = (fairygui::GTreeNode *)self->getRootNode();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GTreeNode");

    // inject code after call
    olua_addref(L, 1, "rootNode", -1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTree_getSelectedNode(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTree *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTree");

    // fairygui::GTreeNode *getSelectedNode()
    fairygui::GTreeNode *ret = (fairygui::GTreeNode *)self->getSelectedNode();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GTreeNode");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTree_getSelectedNodes(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTree *self = nullptr;
    std::vector<fairygui::GTreeNode *> arg1;       /** result */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTree");
    // no need to check 'arg1' with mark '@out'

    // void getSelectedNodes(@out std::vector<GTreeNode *> &result)
    self->getSelectedNodes(arg1);

    olua_push_std_vector(L, arg1, "fgui.GTreeNode");

    olua_endinvoke(L);

    return 0 + 1;
}

static int _fairygui_GTree_new(lua_State *L)
{
    olua_startinvoke(L);

    // GTree()
    fairygui::GTree *ret = (fairygui::GTree *)new fairygui::GTree();
    int num_ret = olua_push_cppobj(L, ret, "fgui.GTree");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTree_selectNode1(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTree *self = nullptr;
    fairygui::GTreeNode *arg1 = nullptr;       /** node */
    bool arg2 = false;       /** scrollItToView */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTree");
    olua_check_cppobj(L, 2, (void **)&arg1, "fgui.GTreeNode");
    olua_check_bool(L, 3, &arg2);

    // void selectNode(fairygui::GTreeNode *node, @optional bool scrollItToView)
    self->selectNode(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GTree_selectNode2(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTree *self = nullptr;
    fairygui::GTreeNode *arg1 = nullptr;       /** node */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTree");
    olua_check_cppobj(L, 2, (void **)&arg1, "fgui.GTreeNode");

    // void selectNode(fairygui::GTreeNode *node, @optional bool scrollItToView)
    self->selectNode(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GTree_selectNode(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_cppobj(L, 2, "fgui.GTreeNode"))) {
            // void selectNode(fairygui::GTreeNode *node, @optional bool scrollItToView)
            return _fairygui_GTree_selectNode2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_cppobj(L, 2, "fgui.GTreeNode")) && (olua_is_bool(L, 3))) {
            // void selectNode(fairygui::GTreeNode *node, @optional bool scrollItToView)
            return _fairygui_GTree_selectNode1(L);
        // }
    }

    luaL_error(L, "method 'fairygui::GTree::selectNode' not support '%d' arguments", num_args);

    return 0;
}

static int _fairygui_GTree_setClickToExpand(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTree *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTree");
    olua_check_int(L, 2, &arg1);

    // void setClickToExpand(int value)
    self->setClickToExpand((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GTree_setIndent(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTree *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTree");
    olua_check_int(L, 2, &arg1);

    // void setIndent(int value)
    self->setIndent((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GTree_unselectNode(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTree *self = nullptr;
    fairygui::GTreeNode *arg1 = nullptr;       /** node */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTree");
    olua_check_cppobj(L, 2, (void **)&arg1, "fgui.GTreeNode");

    // void unselectNode(fairygui::GTreeNode *node)
    self->unselectNode(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GTree_get_treeNodeRender(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTree *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTree");

    void *self_obj = (void *)self;
    std::string tag = "treeNodeRender";
    olua_getcallback(L, self_obj, tag.c_str(), OLUA_TAG_SUBEQUAL);

    // @nullable std::function<void (GTreeNode *, GComponent *)> treeNodeRender
    std::function<void(fairygui::GTreeNode *, fairygui::GComponent *)> ret = (std::function<void(fairygui::GTreeNode *, fairygui::GComponent *)>)self->treeNodeRender;
    int num_ret = olua_push_std_function(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTree_set_treeNodeRender(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTree *self = nullptr;
    std::function<void(fairygui::GTreeNode *, fairygui::GComponent *)> arg1;       /** treeNodeRender */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTree");

    if (olua_is_std_function(L, 2)) {
        void *self_obj = (void *)self;
        std::string tag = "treeNodeRender";
        std::string func = olua_setcallback(L, self_obj, tag.c_str(), 2, OLUA_TAG_REPLACE);
        lua_Unsigned ctx = olua_context(L);
        arg1 = [self_obj, func, ctx](fairygui::GTreeNode *arg1, fairygui::GComponent *arg2) {
            lua_State *L = olua_mainthread(NULL);

            if (L != NULL && (olua_context(L) == ctx)) {
                int top = lua_gettop(L);
                olua_push_cppobj(L, arg1, "fgui.GTreeNode");
                olua_push_cppobj(L, arg2, "fgui.GComponent");

                olua_callback(L, self_obj, func.c_str(), 2);

                lua_settop(L, top);
            }
        };
    } else {
        void *self_obj = (void *)self;
        std::string tag = "treeNodeRender";
        olua_removecallback(L, self_obj, tag.c_str(), OLUA_TAG_SUBEQUAL);
        arg1 = nullptr;
    }

    // @nullable std::function<void (GTreeNode *, GComponent *)> treeNodeRender
    self->treeNodeRender = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_GTree_get_treeNodeWillExpand(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTree *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTree");

    void *self_obj = (void *)self;
    std::string tag = "treeNodeWillExpand";
    olua_getcallback(L, self_obj, tag.c_str(), OLUA_TAG_SUBEQUAL);

    // @nullable std::function<void (GTreeNode *, bool)> treeNodeWillExpand
    std::function<void(fairygui::GTreeNode *, bool)> ret = (std::function<void(fairygui::GTreeNode *, bool)>)self->treeNodeWillExpand;
    int num_ret = olua_push_std_function(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_GTree_set_treeNodeWillExpand(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::GTree *self = nullptr;
    std::function<void(fairygui::GTreeNode *, bool)> arg1;       /** treeNodeWillExpand */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.GTree");

    if (olua_is_std_function(L, 2)) {
        void *self_obj = (void *)self;
        std::string tag = "treeNodeWillExpand";
        std::string func = olua_setcallback(L, self_obj, tag.c_str(), 2, OLUA_TAG_REPLACE);
        lua_Unsigned ctx = olua_context(L);
        arg1 = [self_obj, func, ctx](fairygui::GTreeNode *arg1, bool arg2) {
            lua_State *L = olua_mainthread(NULL);

            if (L != NULL && (olua_context(L) == ctx)) {
                int top = lua_gettop(L);
                olua_push_cppobj(L, arg1, "fgui.GTreeNode");
                olua_push_bool(L, arg2);

                olua_callback(L, self_obj, func.c_str(), 2);

                lua_settop(L, top);
            }
        };
    } else {
        void *self_obj = (void *)self;
        std::string tag = "treeNodeWillExpand";
        olua_removecallback(L, self_obj, tag.c_str(), OLUA_TAG_SUBEQUAL);
        arg1 = nullptr;
    }

    // @nullable std::function<void (GTreeNode *, bool)> treeNodeWillExpand
    self->treeNodeWillExpand = arg1;

    olua_endinvoke(L);

    return 0;
}

static int luaopen_fairygui_GTree(lua_State *L)
{
    oluacls_class(L, "fgui.GTree", "fgui.GList");
    oluacls_func(L, "__move", _fairygui_GTree___move);
    oluacls_func(L, "collapseAll", _fairygui_GTree_collapseAll);
    oluacls_func(L, "create", _fairygui_GTree_create);
    oluacls_func(L, "expandAll", _fairygui_GTree_expandAll);
    oluacls_func(L, "getClickToExpand", _fairygui_GTree_getClickToExpand);
    oluacls_func(L, "getIndent", _fairygui_GTree_getIndent);
    oluacls_func(L, "getRootNode", _fairygui_GTree_getRootNode);
    oluacls_func(L, "getSelectedNode", _fairygui_GTree_getSelectedNode);
    oluacls_func(L, "getSelectedNodes", _fairygui_GTree_getSelectedNodes);
    oluacls_func(L, "new", _fairygui_GTree_new);
    oluacls_func(L, "selectNode", _fairygui_GTree_selectNode);
    oluacls_func(L, "setClickToExpand", _fairygui_GTree_setClickToExpand);
    oluacls_func(L, "setIndent", _fairygui_GTree_setIndent);
    oluacls_func(L, "unselectNode", _fairygui_GTree_unselectNode);
    oluacls_prop(L, "clickToExpand", _fairygui_GTree_getClickToExpand, _fairygui_GTree_setClickToExpand);
    oluacls_prop(L, "indent", _fairygui_GTree_getIndent, _fairygui_GTree_setIndent);
    oluacls_prop(L, "rootNode", _fairygui_GTree_getRootNode, nullptr);
    oluacls_prop(L, "selectedNode", _fairygui_GTree_getSelectedNode, nullptr);
    oluacls_prop(L, "treeNodeRender", _fairygui_GTree_get_treeNodeRender, _fairygui_GTree_set_treeNodeRender);
    oluacls_prop(L, "treeNodeWillExpand", _fairygui_GTree_get_treeNodeWillExpand, _fairygui_GTree_set_treeNodeWillExpand);

    olua_registerluatype<fairygui::GTree>(L, "fgui.GTree");

    return 1;
}

static int _fairygui_FUIContainer___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (fairygui::FUIContainer *)olua_toobj(L, 1, "fgui.FUIContainer");
    olua_push_cppobj(L, self, "fgui.FUIContainer");

    olua_endinvoke(L);

    return 1;
}

static int _fairygui_FUIContainer_create(lua_State *L)
{
    olua_startinvoke(L);

    // static fairygui::FUIContainer *create()
    fairygui::FUIContainer *ret = (fairygui::FUIContainer *)fairygui::FUIContainer::create();
    int num_ret = olua_push_cppobj(L, ret, "fgui.FUIContainer");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_FUIContainer_getAlphaThreshold(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::FUIContainer *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.FUIContainer");

    // float getAlphaThreshold()
    float ret = (float)self->getAlphaThreshold();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_FUIContainer_getClippingRegion(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::FUIContainer *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.FUIContainer");

    // const cocos2d::Rect &getClippingRegion()
    const cocos2d::Rect &ret = (const cocos2d::Rect &)self->getClippingRegion();
    int num_ret = manual_olua_push_cocos2d_Rect(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_FUIContainer_getStencil(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::FUIContainer *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.FUIContainer");

    // cocos2d::Node *getStencil()
    cocos2d::Node *ret = (cocos2d::Node *)self->getStencil();
    int num_ret = olua_push_cppobj(L, ret, "cc.Node");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_FUIContainer_isClippingEnabled(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::FUIContainer *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.FUIContainer");

    // bool isClippingEnabled()
    bool ret = (bool)self->isClippingEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_FUIContainer_isInverted(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::FUIContainer *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.FUIContainer");

    // bool isInverted()
    bool ret = (bool)self->isInverted();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_FUIContainer_new(lua_State *L)
{
    olua_startinvoke(L);

    // FUIContainer()
    fairygui::FUIContainer *ret = (fairygui::FUIContainer *)new fairygui::FUIContainer();
    int num_ret = olua_push_cppobj(L, ret, "fgui.FUIContainer");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_FUIContainer_setAlphaThreshold(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::FUIContainer *self = nullptr;
    lua_Number arg1 = 0;       /** alphaThreshold */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.FUIContainer");
    olua_check_number(L, 2, &arg1);

    // void setAlphaThreshold(float alphaThreshold)
    self->setAlphaThreshold((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_FUIContainer_setClippingEnabled(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::FUIContainer *self = nullptr;
    bool arg1 = false;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.FUIContainer");
    olua_check_bool(L, 2, &arg1);

    // void setClippingEnabled(bool value)
    self->setClippingEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_FUIContainer_setClippingRegion(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::FUIContainer *self = nullptr;
    cocos2d::Rect arg1;       /** clippingRegion */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.FUIContainer");
    manual_olua_check_cocos2d_Rect(L, 2, &arg1);

    // void setClippingRegion(const cocos2d::Rect &clippingRegion)
    self->setClippingRegion(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_FUIContainer_setInverted(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::FUIContainer *self = nullptr;
    bool arg1 = false;       /** inverted */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.FUIContainer");
    olua_check_bool(L, 2, &arg1);

    // void setInverted(bool inverted)
    self->setInverted(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_FUIContainer_setStencil(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::FUIContainer *self = nullptr;
    cocos2d::Node *arg1 = nullptr;       /** stencil */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.FUIContainer");
    olua_check_cppobj(L, 2, (void **)&arg1, "cc.Node");

    // void setStencil(cocos2d::Node *stencil)
    self->setStencil(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_FUIContainer_get_gOwner(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::FUIContainer *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.FUIContainer");

    // fairygui::GObject *gOwner
    fairygui::GObject *ret = (fairygui::GObject *)self->gOwner;
    int num_ret = olua_push_cppobj(L, ret, "fgui.GObject");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_FUIContainer_set_gOwner(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::FUIContainer *self = nullptr;
    fairygui::GObject *arg1 = nullptr;       /** gOwner */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.FUIContainer");
    olua_check_cppobj(L, 2, (void **)&arg1, "fgui.GObject");

    // fairygui::GObject *gOwner
    self->gOwner = arg1;

    olua_endinvoke(L);

    return 0;
}

static int luaopen_fairygui_FUIContainer(lua_State *L)
{
    oluacls_class(L, "fgui.FUIContainer", "cc.Node");
    oluacls_func(L, "__move", _fairygui_FUIContainer___move);
    oluacls_func(L, "create", _fairygui_FUIContainer_create);
    oluacls_func(L, "getAlphaThreshold", _fairygui_FUIContainer_getAlphaThreshold);
    oluacls_func(L, "getClippingRegion", _fairygui_FUIContainer_getClippingRegion);
    oluacls_func(L, "getStencil", _fairygui_FUIContainer_getStencil);
    oluacls_func(L, "isClippingEnabled", _fairygui_FUIContainer_isClippingEnabled);
    oluacls_func(L, "isInverted", _fairygui_FUIContainer_isInverted);
    oluacls_func(L, "new", _fairygui_FUIContainer_new);
    oluacls_func(L, "setAlphaThreshold", _fairygui_FUIContainer_setAlphaThreshold);
    oluacls_func(L, "setClippingEnabled", _fairygui_FUIContainer_setClippingEnabled);
    oluacls_func(L, "setClippingRegion", _fairygui_FUIContainer_setClippingRegion);
    oluacls_func(L, "setInverted", _fairygui_FUIContainer_setInverted);
    oluacls_func(L, "setStencil", _fairygui_FUIContainer_setStencil);
    oluacls_prop(L, "alphaThreshold", _fairygui_FUIContainer_getAlphaThreshold, _fairygui_FUIContainer_setAlphaThreshold);
    oluacls_prop(L, "clippingEnabled", _fairygui_FUIContainer_isClippingEnabled, _fairygui_FUIContainer_setClippingEnabled);
    oluacls_prop(L, "clippingRegion", _fairygui_FUIContainer_getClippingRegion, _fairygui_FUIContainer_setClippingRegion);
    oluacls_prop(L, "inverted", _fairygui_FUIContainer_isInverted, _fairygui_FUIContainer_setInverted);
    oluacls_prop(L, "stencil", _fairygui_FUIContainer_getStencil, _fairygui_FUIContainer_setStencil);
    oluacls_prop(L, "gOwner", _fairygui_FUIContainer_get_gOwner, _fairygui_FUIContainer_set_gOwner);

    olua_registerluatype<fairygui::FUIContainer>(L, "fgui.FUIContainer");

    return 1;
}

static int _fairygui_FUIInput___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (fairygui::FUIInput *)olua_toobj(L, 1, "fgui.FUIInput");
    olua_push_cppobj(L, self, "fgui.FUIInput");

    olua_endinvoke(L);

    return 1;
}

static int _fairygui_FUIInput_applyTextFormat(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::FUIInput *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.FUIInput");

    // void applyTextFormat()
    self->applyTextFormat();

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_FUIInput_create(lua_State *L)
{
    olua_startinvoke(L);

    // static fairygui::FUIInput *create()
    fairygui::FUIInput *ret = (fairygui::FUIInput *)fairygui::FUIInput::create();
    int num_ret = olua_push_cppobj(L, ret, "fgui.FUIInput");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_FUIInput_getTextFormat(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::FUIInput *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.FUIInput");

    // fairygui::TextFormat *getTextFormat()
    fairygui::TextFormat *ret = (fairygui::TextFormat *)self->getTextFormat();
    int num_ret = olua_push_cppobj(L, ret, "fgui.TextFormat");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_FUIInput_isPassword(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::FUIInput *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.FUIInput");

    // bool isPassword()
    bool ret = (bool)self->isPassword();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_FUIInput_isSingleLine(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::FUIInput *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.FUIInput");

    // bool isSingleLine()
    bool ret = (bool)self->isSingleLine();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_FUIInput_keyboardType(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::FUIInput *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.FUIInput");

    // int keyboardType()
    int ret = (int)self->keyboardType();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_FUIInput_new(lua_State *L)
{
    olua_startinvoke(L);

    // FUIInput()
    fairygui::FUIInput *ret = (fairygui::FUIInput *)new fairygui::FUIInput();
    int num_ret = olua_push_cppobj(L, ret, "fgui.FUIInput");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_FUIInput_setKeyboardType(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::FUIInput *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.FUIInput");
    olua_check_int(L, 2, &arg1);

    // void setKeyboardType(int value)
    self->setKeyboardType((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_FUIInput_setPassword(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::FUIInput *self = nullptr;
    bool arg1 = false;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.FUIInput");
    olua_check_bool(L, 2, &arg1);

    // void setPassword(bool value)
    self->setPassword(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_FUIInput_setSingleLine(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::FUIInput *self = nullptr;
    bool arg1 = false;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.FUIInput");
    olua_check_bool(L, 2, &arg1);

    // void setSingleLine(bool value)
    self->setSingleLine(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_FUIInput_setText(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::FUIInput *self = nullptr;
    std::string arg1;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.FUIInput");
    olua_check_std_string(L, 2, &arg1);

    // void setText(const std::string &value)
    self->setText(arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_fairygui_FUIInput(lua_State *L)
{
    oluacls_class(L, "fgui.FUIInput", "ccui.EditBox");
    oluacls_func(L, "__move", _fairygui_FUIInput___move);
    oluacls_func(L, "applyTextFormat", _fairygui_FUIInput_applyTextFormat);
    oluacls_func(L, "create", _fairygui_FUIInput_create);
    oluacls_func(L, "getTextFormat", _fairygui_FUIInput_getTextFormat);
    oluacls_func(L, "isPassword", _fairygui_FUIInput_isPassword);
    oluacls_func(L, "isSingleLine", _fairygui_FUIInput_isSingleLine);
    oluacls_func(L, "keyboardType", _fairygui_FUIInput_keyboardType);
    oluacls_func(L, "new", _fairygui_FUIInput_new);
    oluacls_func(L, "setKeyboardType", _fairygui_FUIInput_setKeyboardType);
    oluacls_func(L, "setPassword", _fairygui_FUIInput_setPassword);
    oluacls_func(L, "setSingleLine", _fairygui_FUIInput_setSingleLine);
    oluacls_func(L, "setText", _fairygui_FUIInput_setText);
    oluacls_prop(L, "password", _fairygui_FUIInput_isPassword, _fairygui_FUIInput_setPassword);
    oluacls_prop(L, "singleLine", _fairygui_FUIInput_isSingleLine, _fairygui_FUIInput_setSingleLine);
    oluacls_prop(L, "textFormat", _fairygui_FUIInput_getTextFormat, nullptr);

    olua_registerluatype<fairygui::FUIInput>(L, "fgui.FUIInput");

    return 1;
}

static int _fairygui_FUILabel___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (fairygui::FUILabel *)olua_toobj(L, 1, "fgui.FUILabel");
    olua_push_cppobj(L, self, "fgui.FUILabel");

    olua_endinvoke(L);

    return 1;
}

static int _fairygui_FUILabel_applyTextFormat(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::FUILabel *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.FUILabel");

    // void applyTextFormat()
    self->applyTextFormat();

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_FUILabel_create(lua_State *L)
{
    olua_startinvoke(L);

    // static fairygui::FUILabel *create()
    fairygui::FUILabel *ret = (fairygui::FUILabel *)fairygui::FUILabel::create();
    int num_ret = olua_push_cppobj(L, ret, "fgui.FUILabel");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_FUILabel_getText(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::FUILabel *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.FUILabel");

    // const std::string &getText()
    const std::string &ret = (const std::string &)self->getText();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_FUILabel_getTextFormat(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::FUILabel *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.FUILabel");

    // fairygui::TextFormat *getTextFormat()
    fairygui::TextFormat *ret = (fairygui::TextFormat *)self->getTextFormat();
    int num_ret = olua_push_cppobj(L, ret, "fgui.TextFormat");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_FUILabel_new(lua_State *L)
{
    olua_startinvoke(L);

    // FUILabel()
    fairygui::FUILabel *ret = (fairygui::FUILabel *)new fairygui::FUILabel();
    int num_ret = olua_push_cppobj(L, ret, "fgui.FUILabel");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_FUILabel_setGrayed(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::FUILabel *self = nullptr;
    bool arg1 = false;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.FUILabel");
    olua_check_bool(L, 2, &arg1);

    // void setGrayed(bool value)
    self->setGrayed(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_FUILabel_setText(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::FUILabel *self = nullptr;
    std::string arg1;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.FUILabel");
    olua_check_std_string(L, 2, &arg1);

    // void setText(const std::string &value)
    self->setText(arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_fairygui_FUILabel(lua_State *L)
{
    oluacls_class(L, "fgui.FUILabel", "cc.Label");
    oluacls_func(L, "__move", _fairygui_FUILabel___move);
    oluacls_func(L, "applyTextFormat", _fairygui_FUILabel_applyTextFormat);
    oluacls_func(L, "create", _fairygui_FUILabel_create);
    oluacls_func(L, "getText", _fairygui_FUILabel_getText);
    oluacls_func(L, "getTextFormat", _fairygui_FUILabel_getTextFormat);
    oluacls_func(L, "new", _fairygui_FUILabel_new);
    oluacls_func(L, "setGrayed", _fairygui_FUILabel_setGrayed);
    oluacls_func(L, "setText", _fairygui_FUILabel_setText);
    oluacls_prop(L, "text", _fairygui_FUILabel_getText, _fairygui_FUILabel_setText);
    oluacls_prop(L, "textFormat", _fairygui_FUILabel_getTextFormat, nullptr);

    olua_registerluatype<fairygui::FUILabel>(L, "fgui.FUILabel");

    return 1;
}

static int _fairygui_FUIRichText___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (fairygui::FUIRichText *)olua_toobj(L, 1, "fgui.FUIRichText");
    olua_push_cppobj(L, self, "fgui.FUIRichText");

    olua_endinvoke(L);

    return 1;
}

static int _fairygui_FUIRichText_applyTextFormat(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::FUIRichText *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.FUIRichText");

    // void applyTextFormat()
    self->applyTextFormat();

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_FUIRichText_create(lua_State *L)
{
    olua_startinvoke(L);

    // static fairygui::FUIRichText *create()
    fairygui::FUIRichText *ret = (fairygui::FUIRichText *)fairygui::FUIRichText::create();
    int num_ret = olua_push_cppobj(L, ret, "fgui.FUIRichText");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_FUIRichText_getAnchorFontColor(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::FUIRichText *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.FUIRichText");

    // const cocos2d::Color3B &getAnchorFontColor()
    const cocos2d::Color3B &ret = (const cocos2d::Color3B &)self->getAnchorFontColor();
    int num_ret = manual_olua_push_cocos2d_Color3B(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_FUIRichText_getDimensions(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::FUIRichText *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.FUIRichText");

    // const cocos2d::Size &getDimensions()
    const cocos2d::Size &ret = (const cocos2d::Size &)self->getDimensions();
    int num_ret = auto_olua_push_cocos2d_Size(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_FUIRichText_getOverflow(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::FUIRichText *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.FUIRichText");

    // cocos2d::Label::Overflow getOverflow()
    cocos2d::Label::Overflow ret = (cocos2d::Label::Overflow)self->getOverflow();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_FUIRichText_getTextFormat(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::FUIRichText *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.FUIRichText");

    // fairygui::TextFormat *getTextFormat()
    fairygui::TextFormat *ret = (fairygui::TextFormat *)self->getTextFormat();
    int num_ret = olua_push_cppobj(L, ret, "fgui.TextFormat");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_FUIRichText_hitTestLink(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::FUIRichText *self = nullptr;
    cocos2d::Vec2 arg1;       /** worldPoint */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.FUIRichText");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);

    // const char *hitTestLink(const cocos2d::Vec2 &worldPoint)
    const char *ret = (const char *)self->hitTestLink(arg1);
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_FUIRichText_isAnchorTextUnderline(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::FUIRichText *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.FUIRichText");

    // bool isAnchorTextUnderline()
    bool ret = (bool)self->isAnchorTextUnderline();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_FUIRichText_new(lua_State *L)
{
    olua_startinvoke(L);

    // FUIRichText()
    fairygui::FUIRichText *ret = (fairygui::FUIRichText *)new fairygui::FUIRichText();
    int num_ret = olua_push_cppobj(L, ret, "fgui.FUIRichText");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_FUIRichText_setAnchorFontColor(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::FUIRichText *self = nullptr;
    cocos2d::Color3B arg1;       /** color */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.FUIRichText");
    manual_olua_check_cocos2d_Color3B(L, 2, &arg1);

    // void setAnchorFontColor(const cocos2d::Color3B &color)
    self->setAnchorFontColor(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_FUIRichText_setAnchorTextUnderline(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::FUIRichText *self = nullptr;
    bool arg1 = false;       /** enable */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.FUIRichText");
    olua_check_bool(L, 2, &arg1);

    // void setAnchorTextUnderline(bool enable)
    self->setAnchorTextUnderline(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_FUIRichText_setDimensions(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::FUIRichText *self = nullptr;
    lua_Number arg1 = 0;       /** width */
    lua_Number arg2 = 0;       /** height */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.FUIRichText");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);

    // void setDimensions(float width, float height)
    self->setDimensions((float)arg1, (float)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_FUIRichText_setOverflow(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::FUIRichText *self = nullptr;
    lua_Unsigned arg1 = 0;       /** overflow */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.FUIRichText");
    olua_check_uint(L, 2, &arg1);

    // void setOverflow(cocos2d::Label::Overflow overflow)
    self->setOverflow((cocos2d::Label::Overflow)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_FUIRichText_setText(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::FUIRichText *self = nullptr;
    std::string arg1;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.FUIRichText");
    olua_check_std_string(L, 2, &arg1);

    // void setText(const std::string &value)
    self->setText(arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_fairygui_FUIRichText(lua_State *L)
{
    oluacls_class(L, "fgui.FUIRichText", "cc.Node");
    oluacls_func(L, "__move", _fairygui_FUIRichText___move);
    oluacls_func(L, "applyTextFormat", _fairygui_FUIRichText_applyTextFormat);
    oluacls_func(L, "create", _fairygui_FUIRichText_create);
    oluacls_func(L, "getAnchorFontColor", _fairygui_FUIRichText_getAnchorFontColor);
    oluacls_func(L, "getDimensions", _fairygui_FUIRichText_getDimensions);
    oluacls_func(L, "getOverflow", _fairygui_FUIRichText_getOverflow);
    oluacls_func(L, "getTextFormat", _fairygui_FUIRichText_getTextFormat);
    oluacls_func(L, "hitTestLink", _fairygui_FUIRichText_hitTestLink);
    oluacls_func(L, "isAnchorTextUnderline", _fairygui_FUIRichText_isAnchorTextUnderline);
    oluacls_func(L, "new", _fairygui_FUIRichText_new);
    oluacls_func(L, "setAnchorFontColor", _fairygui_FUIRichText_setAnchorFontColor);
    oluacls_func(L, "setAnchorTextUnderline", _fairygui_FUIRichText_setAnchorTextUnderline);
    oluacls_func(L, "setDimensions", _fairygui_FUIRichText_setDimensions);
    oluacls_func(L, "setOverflow", _fairygui_FUIRichText_setOverflow);
    oluacls_func(L, "setText", _fairygui_FUIRichText_setText);
    oluacls_prop(L, "anchorFontColor", _fairygui_FUIRichText_getAnchorFontColor, _fairygui_FUIRichText_setAnchorFontColor);
    oluacls_prop(L, "anchorTextUnderline", _fairygui_FUIRichText_isAnchorTextUnderline, _fairygui_FUIRichText_setAnchorTextUnderline);
    oluacls_prop(L, "dimensions", _fairygui_FUIRichText_getDimensions, _fairygui_FUIRichText_setDimensions);
    oluacls_prop(L, "overflow", _fairygui_FUIRichText_getOverflow, _fairygui_FUIRichText_setOverflow);
    oluacls_prop(L, "textFormat", _fairygui_FUIRichText_getTextFormat, nullptr);

    olua_registerluatype<fairygui::FUIRichText>(L, "fgui.FUIRichText");

    return 1;
}

static int _fairygui_FUISprite___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (fairygui::FUISprite *)olua_toobj(L, 1, "fgui.FUISprite");
    olua_push_cppobj(L, self, "fgui.FUISprite");

    olua_endinvoke(L);

    return 1;
}

static int _fairygui_FUISprite_clearContent(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::FUISprite *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.FUISprite");

    // void clearContent()
    self->clearContent();

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_FUISprite_create(lua_State *L)
{
    olua_startinvoke(L);

    // static fairygui::FUISprite *create()
    fairygui::FUISprite *ret = (fairygui::FUISprite *)fairygui::FUISprite::create();
    int num_ret = olua_push_cppobj(L, ret, "fgui.FUISprite");

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_FUISprite_getFillAmount(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::FUISprite *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.FUISprite");

    // float getFillAmount()
    float ret = (float)self->getFillAmount();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_FUISprite_getFillMethod(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::FUISprite *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.FUISprite");

    // fairygui::FillMethod getFillMethod()
    fairygui::FillMethod ret = (fairygui::FillMethod)self->getFillMethod();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_FUISprite_getFillOrigin(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::FUISprite *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.FUISprite");

    // fairygui::FillOrigin getFillOrigin()
    fairygui::FillOrigin ret = (fairygui::FillOrigin)self->getFillOrigin();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_FUISprite_isFillClockwise(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::FUISprite *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.FUISprite");

    // bool isFillClockwise()
    bool ret = (bool)self->isFillClockwise();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_FUISprite_isScaleByTile(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::FUISprite *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "fgui.FUISprite");

    // bool isScaleByTile()
    bool ret = (bool)self->isScaleByTile();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_FUISprite_new(lua_State *L)
{
    olua_startinvoke(L);

    // FUISprite()
    fairygui::FUISprite *ret = (fairygui::FUISprite *)new fairygui::FUISprite();
    int num_ret = olua_push_cppobj(L, ret, "fgui.FUISprite");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _fairygui_FUISprite_setFillAmount(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::FUISprite *self = nullptr;
    lua_Number arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.FUISprite");
    olua_check_number(L, 2, &arg1);

    // void setFillAmount(float value)
    self->setFillAmount((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_FUISprite_setFillClockwise(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::FUISprite *self = nullptr;
    bool arg1 = false;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.FUISprite");
    olua_check_bool(L, 2, &arg1);

    // void setFillClockwise(bool value)
    self->setFillClockwise(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_FUISprite_setFillMethod(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::FUISprite *self = nullptr;
    lua_Unsigned arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.FUISprite");
    olua_check_uint(L, 2, &arg1);

    // void setFillMethod(fairygui::FillMethod value)
    self->setFillMethod((fairygui::FillMethod)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_FUISprite_setFillOrigin(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::FUISprite *self = nullptr;
    lua_Unsigned arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.FUISprite");
    olua_check_uint(L, 2, &arg1);

    // void setFillOrigin(fairygui::FillOrigin value)
    self->setFillOrigin((fairygui::FillOrigin)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_FUISprite_setGrayed(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::FUISprite *self = nullptr;
    bool arg1 = false;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.FUISprite");
    olua_check_bool(L, 2, &arg1);

    // void setGrayed(bool value)
    self->setGrayed(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _fairygui_FUISprite_setScaleByTile(lua_State *L)
{
    olua_startinvoke(L);

    fairygui::FUISprite *self = nullptr;
    bool arg1 = false;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "fgui.FUISprite");
    olua_check_bool(L, 2, &arg1);

    // void setScaleByTile(bool value)
    self->setScaleByTile(arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_fairygui_FUISprite(lua_State *L)
{
    oluacls_class(L, "fgui.FUISprite", "cc.Sprite");
    oluacls_func(L, "__move", _fairygui_FUISprite___move);
    oluacls_func(L, "clearContent", _fairygui_FUISprite_clearContent);
    oluacls_func(L, "create", _fairygui_FUISprite_create);
    oluacls_func(L, "getFillAmount", _fairygui_FUISprite_getFillAmount);
    oluacls_func(L, "getFillMethod", _fairygui_FUISprite_getFillMethod);
    oluacls_func(L, "getFillOrigin", _fairygui_FUISprite_getFillOrigin);
    oluacls_func(L, "isFillClockwise", _fairygui_FUISprite_isFillClockwise);
    oluacls_func(L, "isScaleByTile", _fairygui_FUISprite_isScaleByTile);
    oluacls_func(L, "new", _fairygui_FUISprite_new);
    oluacls_func(L, "setFillAmount", _fairygui_FUISprite_setFillAmount);
    oluacls_func(L, "setFillClockwise", _fairygui_FUISprite_setFillClockwise);
    oluacls_func(L, "setFillMethod", _fairygui_FUISprite_setFillMethod);
    oluacls_func(L, "setFillOrigin", _fairygui_FUISprite_setFillOrigin);
    oluacls_func(L, "setGrayed", _fairygui_FUISprite_setGrayed);
    oluacls_func(L, "setScaleByTile", _fairygui_FUISprite_setScaleByTile);
    oluacls_prop(L, "fillAmount", _fairygui_FUISprite_getFillAmount, _fairygui_FUISprite_setFillAmount);
    oluacls_prop(L, "fillClockwise", _fairygui_FUISprite_isFillClockwise, _fairygui_FUISprite_setFillClockwise);
    oluacls_prop(L, "fillMethod", _fairygui_FUISprite_getFillMethod, _fairygui_FUISprite_setFillMethod);
    oluacls_prop(L, "fillOrigin", _fairygui_FUISprite_getFillOrigin, _fairygui_FUISprite_setFillOrigin);
    oluacls_prop(L, "scaleByTile", _fairygui_FUISprite_isScaleByTile, _fairygui_FUISprite_setScaleByTile);

    olua_registerluatype<fairygui::FUISprite>(L, "fgui.FUISprite");

    return 1;
}

int luaopen_fairygui(lua_State *L)
{
    olua_require(L, "fgui.UIEventType", luaopen_fairygui_UIEventType);
    olua_require(L, "fgui.UIEventDispatcher", luaopen_fairygui_UIEventDispatcher);
    olua_require(L, "fgui.EventContext", luaopen_fairygui_EventContext);
    olua_require(L, "fgui.IHitTest", luaopen_fairygui_IHitTest);
    olua_require(L, "fgui.PixelHitTest", luaopen_fairygui_PixelHitTest);
    olua_require(L, "fgui.PixelHitTestData", luaopen_fairygui_PixelHitTestData);
    olua_require(L, "fgui.InputProcessor", luaopen_fairygui_InputProcessor);
    olua_require(L, "fgui.InputEvent", luaopen_fairygui_InputEvent);
    olua_require(L, "fgui.TextFormat", luaopen_fairygui_TextFormat);
    olua_require(L, "fgui.EaseType", luaopen_fairygui_EaseType);
    olua_require(L, "fgui.EaseManager", luaopen_fairygui_EaseManager);
    olua_require(L, "fgui.TweenPropType", luaopen_fairygui_TweenPropType);
    olua_require(L, "fgui.GPath", luaopen_fairygui_GPath);
    olua_require(L, "fgui.GTweener", luaopen_fairygui_GTweener);
    olua_require(L, "fgui.GTween", luaopen_fairygui_GTween);
    olua_require(L, "fgui.UIPackage", luaopen_fairygui_UIPackage);
    olua_require(L, "fgui.PackageItem", luaopen_fairygui_PackageItem);
    olua_require(L, "fgui.PackageItemType", luaopen_fairygui_PackageItemType);
    olua_require(L, "fgui.ObjectType", luaopen_fairygui_ObjectType);
    olua_require(L, "fgui.ButtonMode", luaopen_fairygui_ButtonMode);
    olua_require(L, "fgui.ChildrenRenderOrder", luaopen_fairygui_ChildrenRenderOrder);
    olua_require(L, "fgui.OverflowType", luaopen_fairygui_OverflowType);
    olua_require(L, "fgui.ScrollType", luaopen_fairygui_ScrollType);
    olua_require(L, "fgui.ScrollBarDisplayType", luaopen_fairygui_ScrollBarDisplayType);
    olua_require(L, "fgui.LoaderFillType", luaopen_fairygui_LoaderFillType);
    olua_require(L, "fgui.ProgressTitleType", luaopen_fairygui_ProgressTitleType);
    olua_require(L, "fgui.ListLayoutType", luaopen_fairygui_ListLayoutType);
    olua_require(L, "fgui.ListSelectionMode", luaopen_fairygui_ListSelectionMode);
    olua_require(L, "fgui.GroupLayoutType", luaopen_fairygui_GroupLayoutType);
    olua_require(L, "fgui.PopupDirection", luaopen_fairygui_PopupDirection);
    olua_require(L, "fgui.AutoSizeType", luaopen_fairygui_AutoSizeType);
    olua_require(L, "fgui.FlipType", luaopen_fairygui_FlipType);
    olua_require(L, "fgui.TransitionActionType", luaopen_fairygui_TransitionActionType);
    olua_require(L, "fgui.FillMethod", luaopen_fairygui_FillMethod);
    olua_require(L, "fgui.FillOrigin", luaopen_fairygui_FillOrigin);
    olua_require(L, "fgui.ObjectPropID", luaopen_fairygui_ObjectPropID);
    olua_require(L, "fgui.GController", luaopen_fairygui_GController);
    olua_require(L, "fgui.GObject", luaopen_fairygui_GObject);
    olua_require(L, "fgui.GComponent", luaopen_fairygui_GComponent);
    olua_require(L, "fgui.GRoot", luaopen_fairygui_GRoot);
    olua_require(L, "fgui.GGroup", luaopen_fairygui_GGroup);
    olua_require(L, "fgui.GScrollBar", luaopen_fairygui_GScrollBar);
    olua_require(L, "fgui.GLoader", luaopen_fairygui_GLoader);
    olua_require(L, "fgui.GTextField", luaopen_fairygui_GTextField);
    olua_require(L, "fgui.GBasicTextField", luaopen_fairygui_GBasicTextField);
    olua_require(L, "fgui.GGraph", luaopen_fairygui_GGraph);
    olua_require(L, "fgui.GButton", luaopen_fairygui_GButton);
    olua_require(L, "fgui.GImage", luaopen_fairygui_GImage);
    olua_require(L, "fgui.GLabel", luaopen_fairygui_GLabel);
    olua_require(L, "fgui.GList", luaopen_fairygui_GList);
    olua_require(L, "fgui.GMovieClip", luaopen_fairygui_GMovieClip);
    olua_require(L, "fgui.GProgressBar", luaopen_fairygui_GProgressBar);
    olua_require(L, "fgui.GComboBox", luaopen_fairygui_GComboBox);
    olua_require(L, "fgui.GRichTextField", luaopen_fairygui_GRichTextField);
    olua_require(L, "fgui.GSlider", luaopen_fairygui_GSlider);
    olua_require(L, "fgui.GTextInput", luaopen_fairygui_GTextInput);
    olua_require(L, "fgui.PopupMenu", luaopen_fairygui_PopupMenu);
    olua_require(L, "fgui.Relations", luaopen_fairygui_Relations);
    olua_require(L, "fgui.RelationType", luaopen_fairygui_RelationType);
    olua_require(L, "fgui.RelationItem", luaopen_fairygui_RelationItem);
    olua_require(L, "fgui.ScrollPane", luaopen_fairygui_ScrollPane);
    olua_require(L, "fgui.Transition", luaopen_fairygui_Transition);
    olua_require(L, "fgui.UIConfig", luaopen_fairygui_UIConfig);
    olua_require(L, "fgui.IUISource", luaopen_fairygui_IUISource);
    olua_require(L, "fgui.UISource", luaopen_fairygui_UISource);
    olua_require(L, "fgui.Window", luaopen_fairygui_Window);
    olua_require(L, "fgui.DragDropManager", luaopen_fairygui_DragDropManager);
    olua_require(L, "fgui.UIObjectFactory", luaopen_fairygui_UIObjectFactory);
    olua_require(L, "fgui.GearBase", luaopen_fairygui_GearBase);
    olua_require(L, "fgui.GTreeNode", luaopen_fairygui_GTreeNode);
    olua_require(L, "fgui.GTree", luaopen_fairygui_GTree);
    olua_require(L, "fgui.FUIContainer", luaopen_fairygui_FUIContainer);
    olua_require(L, "fgui.FUIInput", luaopen_fairygui_FUIInput);
    olua_require(L, "fgui.FUILabel", luaopen_fairygui_FUILabel);
    olua_require(L, "fgui.FUIRichText", luaopen_fairygui_FUIRichText);
    olua_require(L, "fgui.FUISprite", luaopen_fairygui_FUISprite);
    return 0;
}
