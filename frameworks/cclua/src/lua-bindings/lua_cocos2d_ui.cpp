//
// AUTO GENERATED, DO NOT MODIFY!
//
#include "lua_cocos2d_ui.h"
#include "lua-bindings/lua_cocos2d_types.h"
#include "lua-bindings/lua_conv_manual.h"
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "ui/UIScrollViewBar.h"
#include "ui/UILayoutManager.h"

static int _olua_module_cocos2d_ui(lua_State *L);

static int _olua_cls_ccui_Widget_FocusDirection(lua_State *L)
{
    oluacls_class<cocos2d::ui::Widget::FocusDirection>(L, "ccui.Widget.FocusDirection");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "DOWN", (lua_Integer)cocos2d::ui::Widget::FocusDirection::DOWN);
    oluacls_enum(L, "LEFT", (lua_Integer)cocos2d::ui::Widget::FocusDirection::LEFT);
    oluacls_enum(L, "RIGHT", (lua_Integer)cocos2d::ui::Widget::FocusDirection::RIGHT);
    oluacls_enum(L, "UP", (lua_Integer)cocos2d::ui::Widget::FocusDirection::UP);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_Widget_FocusDirection(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.Widget.FocusDirection")) {
        luaL_error(L, "class not found: cocos2d::ui::Widget::FocusDirection");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_ccui_Widget_PositionType(lua_State *L)
{
    oluacls_class<cocos2d::ui::Widget::PositionType>(L, "ccui.Widget.PositionType");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "ABSOLUTE", (lua_Integer)cocos2d::ui::Widget::PositionType::ABSOLUTE);
    oluacls_enum(L, "PERCENT", (lua_Integer)cocos2d::ui::Widget::PositionType::PERCENT);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_Widget_PositionType(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.Widget.PositionType")) {
        luaL_error(L, "class not found: cocos2d::ui::Widget::PositionType");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_ccui_Widget_SizeType(lua_State *L)
{
    oluacls_class<cocos2d::ui::Widget::SizeType>(L, "ccui.Widget.SizeType");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "ABSOLUTE", (lua_Integer)cocos2d::ui::Widget::SizeType::ABSOLUTE);
    oluacls_enum(L, "PERCENT", (lua_Integer)cocos2d::ui::Widget::SizeType::PERCENT);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_Widget_SizeType(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.Widget.SizeType")) {
        luaL_error(L, "class not found: cocos2d::ui::Widget::SizeType");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_ccui_Widget_TouchEventType(lua_State *L)
{
    oluacls_class<cocos2d::ui::Widget::TouchEventType>(L, "ccui.Widget.TouchEventType");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "BEGAN", (lua_Integer)cocos2d::ui::Widget::TouchEventType::BEGAN);
    oluacls_enum(L, "CANCELED", (lua_Integer)cocos2d::ui::Widget::TouchEventType::CANCELED);
    oluacls_enum(L, "ENDED", (lua_Integer)cocos2d::ui::Widget::TouchEventType::ENDED);
    oluacls_enum(L, "MOVED", (lua_Integer)cocos2d::ui::Widget::TouchEventType::MOVED);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_Widget_TouchEventType(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.Widget.TouchEventType")) {
        luaL_error(L, "class not found: cocos2d::ui::Widget::TouchEventType");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_ccui_Widget_TextureResType(lua_State *L)
{
    oluacls_class<cocos2d::ui::Widget::TextureResType>(L, "ccui.Widget.TextureResType");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "LOCAL", (lua_Integer)cocos2d::ui::Widget::TextureResType::LOCAL);
    oluacls_enum(L, "PLIST", (lua_Integer)cocos2d::ui::Widget::TextureResType::PLIST);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_Widget_TextureResType(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.Widget.TextureResType")) {
        luaL_error(L, "class not found: cocos2d::ui::Widget::TextureResType");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_ccui_Widget_BrightStyle(lua_State *L)
{
    oluacls_class<cocos2d::ui::Widget::BrightStyle>(L, "ccui.Widget.BrightStyle");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "HIGHLIGHT", (lua_Integer)cocos2d::ui::Widget::BrightStyle::HIGHLIGHT);
    oluacls_enum(L, "NONE", (lua_Integer)cocos2d::ui::Widget::BrightStyle::NONE);
    oluacls_enum(L, "NORMAL", (lua_Integer)cocos2d::ui::Widget::BrightStyle::NORMAL);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_Widget_BrightStyle(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.Widget.BrightStyle")) {
        luaL_error(L, "class not found: cocos2d::ui::Widget::BrightStyle");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_ui_Widget_ccWidgetTouchCallback___call(lua_State *L)
{
    olua_startinvoke(L);

    luaL_checktype(L, -1, LUA_TFUNCTION);
    olua_push_callback(L, (cocos2d::ui::Widget::ccWidgetTouchCallback *)nullptr, "ccui.Widget.ccWidgetTouchCallback");

    olua_endinvoke(L);

    return 1;
}

static int _olua_cls_ccui_Widget_ccWidgetTouchCallback(lua_State *L)
{
    oluacls_class<cocos2d::ui::Widget::ccWidgetTouchCallback>(L, "ccui.Widget.ccWidgetTouchCallback");
    oluacls_func(L, "__call", _olua_fun_cocos2d_ui_Widget_ccWidgetTouchCallback___call);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_Widget_ccWidgetTouchCallback(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.Widget.ccWidgetTouchCallback")) {
        luaL_error(L, "class not found: cocos2d::ui::Widget::ccWidgetTouchCallback");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_ui_Widget_ccWidgetClickCallback___call(lua_State *L)
{
    olua_startinvoke(L);

    luaL_checktype(L, -1, LUA_TFUNCTION);
    olua_push_callback(L, (cocos2d::ui::Widget::ccWidgetClickCallback *)nullptr, "ccui.Widget.ccWidgetClickCallback");

    olua_endinvoke(L);

    return 1;
}

static int _olua_cls_ccui_Widget_ccWidgetClickCallback(lua_State *L)
{
    oluacls_class<cocos2d::ui::Widget::ccWidgetClickCallback>(L, "ccui.Widget.ccWidgetClickCallback");
    oluacls_func(L, "__call", _olua_fun_cocos2d_ui_Widget_ccWidgetClickCallback___call);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_Widget_ccWidgetClickCallback(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.Widget.ccWidgetClickCallback")) {
        luaL_error(L, "class not found: cocos2d::ui::Widget::ccWidgetClickCallback");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_ui_Widget_ccWidgetEventCallback___call(lua_State *L)
{
    olua_startinvoke(L);

    luaL_checktype(L, -1, LUA_TFUNCTION);
    olua_push_callback(L, (cocos2d::ui::Widget::ccWidgetEventCallback *)nullptr, "ccui.Widget.ccWidgetEventCallback");

    olua_endinvoke(L);

    return 1;
}

static int _olua_cls_ccui_Widget_ccWidgetEventCallback(lua_State *L)
{
    oluacls_class<cocos2d::ui::Widget::ccWidgetEventCallback>(L, "ccui.Widget.ccWidgetEventCallback");
    oluacls_func(L, "__call", _olua_fun_cocos2d_ui_Widget_ccWidgetEventCallback___call);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_Widget_ccWidgetEventCallback(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.Widget.ccWidgetEventCallback")) {
        luaL_error(L, "class not found: cocos2d::ui::Widget::ccWidgetEventCallback");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_ui_LayoutManager_doLayout(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutManager *self = nullptr;
    cocos2d::ui::LayoutProtocol *arg1 = nullptr;       /** layout */

    olua_to_object(L, 1, &self, "ccui.LayoutManager");
    olua_check_object(L, 2, &arg1, "ccui.LayoutProtocol");

    // void doLayout(cocos2d::ui::LayoutProtocol *layout)
    self->doLayout(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_cls_ccui_LayoutManager(lua_State *L)
{
    oluacls_class<cocos2d::ui::LayoutManager, cocos2d::Ref>(L, "ccui.LayoutManager");
    oluacls_func(L, "doLayout", _olua_fun_cocos2d_ui_LayoutManager_doLayout);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_LayoutManager(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.LayoutManager")) {
        luaL_error(L, "class not found: cocos2d::ui::LayoutManager");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_ui_LayoutParameterProtocol___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::ui::LayoutParameterProtocol *)olua_toobj(L, 1, "ccui.LayoutParameterProtocol");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_LayoutParameterProtocol_getLayoutParameter(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutParameterProtocol *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.LayoutParameterProtocol");

    // cocos2d::ui::LayoutParameter *getLayoutParameter()
    cocos2d::ui::LayoutParameter *ret = self->getLayoutParameter();
    int num_ret = olua_push_object(L, ret, "ccui.LayoutParameter");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_cls_ccui_LayoutParameterProtocol(lua_State *L)
{
    oluacls_class<cocos2d::ui::LayoutParameterProtocol>(L, "ccui.LayoutParameterProtocol");
    oluacls_func(L, "__gc", _olua_fun_cocos2d_ui_LayoutParameterProtocol___gc);
    oluacls_func(L, "getLayoutParameter", _olua_fun_cocos2d_ui_LayoutParameterProtocol_getLayoutParameter);
    oluacls_prop(L, "layoutParameter", _olua_fun_cocos2d_ui_LayoutParameterProtocol_getLayoutParameter, nullptr);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_LayoutParameterProtocol(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.LayoutParameterProtocol")) {
        luaL_error(L, "class not found: cocos2d::ui::LayoutParameterProtocol");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_ui_LayoutProtocol___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::ui::LayoutProtocol *)olua_toobj(L, 1, "ccui.LayoutProtocol");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_LayoutProtocol_createLayoutManager(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutProtocol *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.LayoutProtocol");

    // cocos2d::ui::LayoutManager *createLayoutManager()
    cocos2d::ui::LayoutManager *ret = self->createLayoutManager();
    int num_ret = olua_push_object(L, ret, "ccui.LayoutManager");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_LayoutProtocol_doLayout(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutProtocol *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.LayoutProtocol");

    // void doLayout()
    self->doLayout();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_LayoutProtocol_getLayoutContentSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutProtocol *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.LayoutProtocol");

    // cocos2d::Size getLayoutContentSize()
    cocos2d::Size ret = self->getLayoutContentSize();
    int num_ret = olua_copy_object(L, ret, "cc.Size");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_LayoutProtocol_getLayoutElements(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutProtocol *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.LayoutProtocol");

    // const cocos2d::Vector<cocos2d::Node *> &getLayoutElements()
    const cocos2d::Vector<cocos2d::Node *> &ret = self->getLayoutElements();
    int num_ret = olua_push_array<cocos2d::Node *>(L, ret, [L](cocos2d::Node *arg1) {
        olua_push_object(L, arg1, "cc.Node");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_cls_ccui_LayoutProtocol(lua_State *L)
{
    oluacls_class<cocos2d::ui::LayoutProtocol>(L, "ccui.LayoutProtocol");
    oluacls_func(L, "__gc", _olua_fun_cocos2d_ui_LayoutProtocol___gc);
    oluacls_func(L, "createLayoutManager", _olua_fun_cocos2d_ui_LayoutProtocol_createLayoutManager);
    oluacls_func(L, "doLayout", _olua_fun_cocos2d_ui_LayoutProtocol_doLayout);
    oluacls_func(L, "getLayoutContentSize", _olua_fun_cocos2d_ui_LayoutProtocol_getLayoutContentSize);
    oluacls_func(L, "getLayoutElements", _olua_fun_cocos2d_ui_LayoutProtocol_getLayoutElements);
    oluacls_prop(L, "layoutContentSize", _olua_fun_cocos2d_ui_LayoutProtocol_getLayoutContentSize, nullptr);
    oluacls_prop(L, "layoutElements", _olua_fun_cocos2d_ui_LayoutProtocol_getLayoutElements, nullptr);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_LayoutProtocol(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.LayoutProtocol")) {
        luaL_error(L, "class not found: cocos2d::ui::LayoutProtocol");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_ui_Widget_addCCSEventListener(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    cocos2d::ui::Widget::ccWidgetEventCallback arg1;       /** callback */

    olua_to_object(L, 1, &self, "ccui.Widget");
    if (!olua_isnoneornil(L, 2)) {
        olua_check_callback(L, 2, &arg1, "ccui.Widget.ccWidgetEventCallback");
    }

    void *cb_store = (void *)self;
    std::string cb_tag = "addCCSEventListener";
    std::string cb_name;
    if (olua_isfunction(L, 2)) {
        cb_name = olua_setcallback(L, cb_store, 2, cb_tag.c_str(), OLUA_TAG_REPLACE);
        olua_Context cb_ctx = olua_context(L);
        // lua_State *ML = olua_mainthread(L);
        arg1 = [cb_store, cb_name, cb_ctx /*, ML */](cocos2d::Ref *cb_arg1, int cb_arg2) {
            lua_State *L = olua_mainthread(NULL);
            olua_checkhostthread();

            if (olua_contextequal(L, cb_ctx)) {
                int top = lua_gettop(L);
                olua_push_object(L, cb_arg1, "cc.Ref");
                olua_push_integer(L, cb_arg2);

                olua_callback(L, cb_store, cb_name.c_str(), 2);

                lua_settop(L, top);
            }
        };
    } else {
        olua_removecallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_EQUAL);
        arg1 = nullptr;
    }

    // void addCCSEventListener(@nullable const cocos2d::ui::Widget::ccWidgetEventCallback &callback)
    self->addCCSEventListener(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Widget_addClickEventListener(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    cocos2d::ui::Widget::ccWidgetClickCallback arg1;       /** callback */

    olua_to_object(L, 1, &self, "ccui.Widget");
    if (!olua_isnoneornil(L, 2)) {
        olua_check_callback(L, 2, &arg1, "ccui.Widget.ccWidgetClickCallback");
    }

    void *cb_store = (void *)self;
    std::string cb_tag = "addClickEventListener";
    std::string cb_name;
    if (olua_isfunction(L, 2)) {
        cb_name = olua_setcallback(L, cb_store, 2, cb_tag.c_str(), OLUA_TAG_REPLACE);
        olua_Context cb_ctx = olua_context(L);
        // lua_State *ML = olua_mainthread(L);
        arg1 = [cb_store, cb_name, cb_ctx /*, ML */](cocos2d::Ref *cb_arg1) {
            lua_State *L = olua_mainthread(NULL);
            olua_checkhostthread();

            if (olua_contextequal(L, cb_ctx)) {
                int top = lua_gettop(L);
                olua_push_object(L, cb_arg1, "cc.Ref");

                olua_callback(L, cb_store, cb_name.c_str(), 1);

                lua_settop(L, top);
            }
        };
    } else {
        olua_removecallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_EQUAL);
        arg1 = nullptr;
    }

    // void addClickEventListener(@nullable const cocos2d::ui::Widget::ccWidgetClickCallback &callback)
    self->addClickEventListener(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Widget_addTouchEventListener(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    cocos2d::ui::Widget::ccWidgetTouchCallback arg1;       /** callback */

    olua_to_object(L, 1, &self, "ccui.Widget");
    if (!olua_isnoneornil(L, 2)) {
        olua_check_callback(L, 2, &arg1, "ccui.Widget.ccWidgetTouchCallback");
    }

    void *cb_store = (void *)self;
    std::string cb_tag = "addTouchEventListener";
    std::string cb_name;
    if (olua_isfunction(L, 2)) {
        cb_name = olua_setcallback(L, cb_store, 2, cb_tag.c_str(), OLUA_TAG_REPLACE);
        olua_Context cb_ctx = olua_context(L);
        // lua_State *ML = olua_mainthread(L);
        arg1 = [cb_store, cb_name, cb_ctx /*, ML */](cocos2d::Ref *cb_arg1, cocos2d::ui::Widget::TouchEventType cb_arg2) {
            lua_State *L = olua_mainthread(NULL);
            olua_checkhostthread();

            if (olua_contextequal(L, cb_ctx)) {
                int top = lua_gettop(L);
                olua_push_object(L, cb_arg1, "cc.Ref");
                olua_push_enum(L, cb_arg2);

                olua_callback(L, cb_store, cb_name.c_str(), 2);

                lua_settop(L, top);
            }
        };
    } else {
        olua_removecallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_EQUAL);
        arg1 = nullptr;
    }

    // void addTouchEventListener(@nullable const cocos2d::ui::Widget::ccWidgetTouchCallback &callback)
    self->addTouchEventListener(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Widget_as(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    const char *arg1 = nullptr;       /** cls */

    olua_to_object(L, 1, &self, "ccui.Widget");
    olua_check_string(L, 2, &arg1);

    do {
        if (olua_isa(L, 1, arg1)) {
            lua_pushvalue(L, 1);
            break;
        }
        if (olua_strequal(arg1, "ccui.LayoutParameterProtocol")) {
            olua_pushobj_as<cocos2d::ui::LayoutParameterProtocol>(L, 1, self, "as.ccui.LayoutParameterProtocol");
            break;
        }

        luaL_error(L, "'cocos2d::ui::Widget' can't cast to '%s'", arg1);
    } while (0);

    olua_endinvoke(L);

    return 1;
}

static int _olua_fun_cocos2d_ui_Widget_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Widget");

    // cocos2d::ui::Widget *clone()
    cocos2d::ui::Widget *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "ccui.Widget");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Widget_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::ui::Widget *create()
    cocos2d::ui::Widget *ret = cocos2d::ui::Widget::create();
    int num_ret = olua_push_object(L, ret, "ccui.Widget");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Widget_dispatchFocusEvent(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    cocos2d::ui::Widget *arg1 = nullptr;       /** widgetLoseFocus */
    cocos2d::ui::Widget *arg2 = nullptr;       /** widgetGetFocus */

    olua_to_object(L, 1, &self, "ccui.Widget");
    if (!olua_isnoneornil(L, 2)) {
        olua_check_object(L, 2, &arg1, "ccui.Widget");
    }
    if (!olua_isnoneornil(L, 3)) {
        olua_check_object(L, 3, &arg2, "ccui.Widget");
    }

    // void dispatchFocusEvent(@nullable cocos2d::ui::Widget *widgetLoseFocus, @nullable cocos2d::ui::Widget *widgetGetFocus)
    self->dispatchFocusEvent(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Widget_enableDpadNavigation(lua_State *L)
{
    olua_startinvoke(L);

    bool arg1 = false;       /** enable */

    olua_check_bool(L, 1, &arg1);

    // static void enableDpadNavigation(bool enable)
    cocos2d::ui::Widget::enableDpadNavigation(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Widget_findNextFocusedWidget(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    cocos2d::ui::Widget::FocusDirection arg1 = (cocos2d::ui::Widget::FocusDirection)0;       /** direction */
    cocos2d::ui::Widget *arg2 = nullptr;       /** current */

    olua_to_object(L, 1, &self, "ccui.Widget");
    olua_check_enum(L, 2, &arg1);
    if (!olua_isnoneornil(L, 3)) {
        olua_check_object(L, 3, &arg2, "ccui.Widget");
    }

    // cocos2d::ui::Widget *findNextFocusedWidget(cocos2d::ui::Widget::FocusDirection direction, @nullable cocos2d::ui::Widget *current)
    cocos2d::ui::Widget *ret = self->findNextFocusedWidget(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "ccui.Widget");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Widget_getActionTag(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Widget");

    // int getActionTag()
    int ret = self->getActionTag();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Widget_getBottomBoundary(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Widget");

    // float getBottomBoundary()
    float ret = self->getBottomBoundary();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Widget_getCallbackName(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Widget");

    // const std::string &getCallbackName()
    const std::string &ret = self->getCallbackName();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Widget_getCallbackType(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Widget");

    // const std::string &getCallbackType()
    const std::string &ret = self->getCallbackType();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Widget_getCurrentFocusedWidget(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::ui::Widget *getCurrentFocusedWidget()
    cocos2d::ui::Widget *ret = cocos2d::ui::Widget::getCurrentFocusedWidget();
    int num_ret = olua_push_object(L, ret, "ccui.Widget");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Widget_getCustomSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Widget");

    // const cocos2d::Size &getCustomSize()
    const cocos2d::Size &ret = self->getCustomSize();
    int num_ret = olua_push_object(L, ret, "cc.Size");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Widget_getLayoutParameter(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Widget");

    // cocos2d::ui::LayoutParameter *getLayoutParameter()
    cocos2d::ui::LayoutParameter *ret = self->getLayoutParameter();
    int num_ret = olua_push_object(L, ret, "ccui.LayoutParameter");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Widget_getLayoutSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Widget");

    // const cocos2d::Size &getLayoutSize()
    const cocos2d::Size &ret = self->getLayoutSize();
    int num_ret = olua_push_object(L, ret, "cc.Size");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Widget_getLeftBoundary(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Widget");

    // float getLeftBoundary()
    float ret = self->getLeftBoundary();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Widget_getPositionPercent(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Widget");

    // const cocos2d::Vec2 &getPositionPercent()
    const cocos2d::Vec2 &ret = self->getPositionPercent();
    int num_ret = olua_push_object(L, ret, "cc.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Widget_getPositionType(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Widget");

    // cocos2d::ui::Widget::PositionType getPositionType()
    cocos2d::ui::Widget::PositionType ret = self->getPositionType();
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Widget_getRightBoundary(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Widget");

    // float getRightBoundary()
    float ret = self->getRightBoundary();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Widget_getSizePercent(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Widget");

    // const cocos2d::Vec2 &getSizePercent()
    const cocos2d::Vec2 &ret = self->getSizePercent();
    int num_ret = olua_push_object(L, ret, "cc.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Widget_getSizeType(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Widget");

    // cocos2d::ui::Widget::SizeType getSizeType()
    cocos2d::ui::Widget::SizeType ret = self->getSizeType();
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Widget_getTopBoundary(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Widget");

    // float getTopBoundary()
    float ret = self->getTopBoundary();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Widget_getTouchBeganPosition(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Widget");

    // const cocos2d::Vec2 &getTouchBeganPosition()
    const cocos2d::Vec2 &ret = self->getTouchBeganPosition();
    int num_ret = olua_push_object(L, ret, "cc.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Widget_getTouchEndPosition(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Widget");

    // const cocos2d::Vec2 &getTouchEndPosition()
    const cocos2d::Vec2 &ret = self->getTouchEndPosition();
    int num_ret = olua_push_object(L, ret, "cc.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Widget_getTouchMovePosition(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Widget");

    // const cocos2d::Vec2 &getTouchMovePosition()
    const cocos2d::Vec2 &ret = self->getTouchMovePosition();
    int num_ret = olua_push_object(L, ret, "cc.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Widget_getVirtualRenderer(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Widget");

    // @addref(protectedChildren |) cocos2d::Node *getVirtualRenderer()
    cocos2d::Node *ret = self->getVirtualRenderer();
    int num_ret = olua_push_object(L, ret, "cc.Node");

    // insert code after call
    olua_addref(L, 1, "protectedChildren", -1, OLUA_REF_MULTI);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Widget_getVirtualRendererSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Widget");

    // cocos2d::Size getVirtualRendererSize()
    cocos2d::Size ret = self->getVirtualRendererSize();
    int num_ret = olua_copy_object(L, ret, "cc.Size");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Widget_getWorldPosition(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Widget");

    // cocos2d::Vec2 getWorldPosition()
    cocos2d::Vec2 ret = self->getWorldPosition();
    int num_ret = olua_copy_object(L, ret, "cc.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Widget_hitTest(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    cocos2d::Vec2 *arg1;       /** pt */
    cocos2d::Camera *arg2 = nullptr;       /** camera */
    cocos2d::Vec3 *arg3 = nullptr;       /** p */

    olua_to_object(L, 1, &self, "ccui.Widget");
    olua_check_object(L, 2, &arg1, "cc.Vec2");
    olua_check_object(L, 3, &arg2, "cc.Camera");
    olua_check_object(L, 4, &arg3, "cc.Vec3");

    // bool hitTest(const cocos2d::Vec2 &pt, const cocos2d::Camera *camera, cocos2d::Vec3 *p)
    bool ret = self->hitTest(*arg1, arg2, arg3);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Widget_ignoreContentAdaptWithSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    bool arg1 = false;       /** ignore */

    olua_to_object(L, 1, &self, "ccui.Widget");
    olua_check_bool(L, 2, &arg1);

    // void ignoreContentAdaptWithSize(bool ignore)
    self->ignoreContentAdaptWithSize(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Widget_interceptTouchEvent(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    cocos2d::ui::Widget::TouchEventType arg1 = (cocos2d::ui::Widget::TouchEventType)0;       /** event */
    cocos2d::ui::Widget *arg2 = nullptr;       /** sender */
    cocos2d::Touch *arg3 = nullptr;       /** touch */

    olua_to_object(L, 1, &self, "ccui.Widget");
    olua_check_enum(L, 2, &arg1);
    olua_check_object(L, 3, &arg2, "ccui.Widget");
    olua_check_object(L, 4, &arg3, "cc.Touch");

    // void interceptTouchEvent(cocos2d::ui::Widget::TouchEventType event, cocos2d::ui::Widget *sender, cocos2d::Touch *touch)
    self->interceptTouchEvent(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Widget_isBright(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Widget");

    // bool isBright()
    bool ret = self->isBright();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Widget_isClippingParentContainsPoint(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    cocos2d::Vec2 *arg1;       /** pt */

    olua_to_object(L, 1, &self, "ccui.Widget");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // bool isClippingParentContainsPoint(const cocos2d::Vec2 &pt)
    bool ret = self->isClippingParentContainsPoint(*arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Widget_isEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Widget");

    // bool isEnabled()
    bool ret = self->isEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Widget_isFlippedX(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Widget");

    // bool isFlippedX()
    bool ret = self->isFlippedX();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Widget_isFlippedY(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Widget");

    // bool isFlippedY()
    bool ret = self->isFlippedY();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Widget_isFocusEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Widget");

    // bool isFocusEnabled()
    bool ret = self->isFocusEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Widget_isFocused(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Widget");

    // bool isFocused()
    bool ret = self->isFocused();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Widget_isHighlighted(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Widget");

    // bool isHighlighted()
    bool ret = self->isHighlighted();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Widget_isIgnoreContentAdaptWithSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Widget");

    // bool isIgnoreContentAdaptWithSize()
    bool ret = self->isIgnoreContentAdaptWithSize();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Widget_isLayoutComponentEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Widget");

    // bool isLayoutComponentEnabled()
    bool ret = self->isLayoutComponentEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Widget_isPropagateTouchEvents(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Widget");

    // bool isPropagateTouchEvents()
    bool ret = self->isPropagateTouchEvents();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Widget_isSwallowTouches(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Widget");

    // bool isSwallowTouches()
    bool ret = self->isSwallowTouches();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Widget_isTouchEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Widget");

    // bool isTouchEnabled()
    bool ret = self->isTouchEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Widget_isUnifySizeEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Widget");

    // bool isUnifySizeEnabled()
    bool ret = self->isUnifySizeEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Widget_new(lua_State *L)
{
    olua_startinvoke(L);

    // cocos2d::ui::Widget()
    cocos2d::ui::Widget *ret = new cocos2d::ui::Widget();
    int num_ret = olua_push_object(L, ret, "ccui.Widget");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Widget_onFocusChange(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    cocos2d::ui::Widget *arg1 = nullptr;       /** widgetLostFocus */
    cocos2d::ui::Widget *arg2 = nullptr;       /** widgetGetFocus */

    olua_to_object(L, 1, &self, "ccui.Widget");
    if (!olua_isnoneornil(L, 2)) {
        olua_check_object(L, 2, &arg1, "ccui.Widget");
    }
    if (!olua_isnoneornil(L, 3)) {
        olua_check_object(L, 3, &arg2, "ccui.Widget");
    }

    // void onFocusChange(@nullable cocos2d::ui::Widget *widgetLostFocus, @nullable cocos2d::ui::Widget *widgetGetFocus)
    self->onFocusChange(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Widget_onFocusChanged$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Widget");

    void *cb_store = (void *)self;
    std::string cb_tag = "onFocusChanged";
    olua_getcallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_EQUAL);

    // std::function<void (cocos2d::ui::Widget *, cocos2d::ui::Widget *)> onFocusChanged
    std::function<void (cocos2d::ui::Widget *, cocos2d::ui::Widget *)> ret = self->onFocusChanged;
    int num_ret = olua_push_callback(L, &ret, "std.function");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Widget_onFocusChanged$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    std::function<void (cocos2d::ui::Widget *, cocos2d::ui::Widget *)> arg1;       /** onFocusChanged */

    olua_to_object(L, 1, &self, "ccui.Widget");
    if (!olua_isnoneornil(L, 2)) {
        olua_check_callback(L, 2, &arg1, "std.function");
    }

    void *cb_store = (void *)self;
    std::string cb_tag = "onFocusChanged";
    std::string cb_name;
    if (olua_isfunction(L, 2)) {
        cb_name = olua_setcallback(L, cb_store, 2, cb_tag.c_str(), OLUA_TAG_REPLACE);
        olua_Context cb_ctx = olua_context(L);
        // lua_State *ML = olua_mainthread(L);
        arg1 = [cb_store, cb_name, cb_ctx /*, ML */](cocos2d::ui::Widget *cb_arg1, cocos2d::ui::Widget *cb_arg2) {
            lua_State *L = olua_mainthread(NULL);
            olua_checkhostthread();

            if (olua_contextequal(L, cb_ctx)) {
                int top = lua_gettop(L);
                size_t last = olua_push_objpool(L);
                olua_enable_objpool(L);
                olua_push_object(L, cb_arg1, "ccui.Widget");
                olua_push_object(L, cb_arg2, "ccui.Widget");
                olua_disable_objpool(L);

                olua_callback(L, cb_store, cb_name.c_str(), 2);

                //pop stack value
                olua_pop_objpool(L, last);
                lua_settop(L, top);
            }
        };
    } else {
        olua_removecallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_EQUAL);
        arg1 = nullptr;
    }

    // std::function<void (cocos2d::ui::Widget *, cocos2d::ui::Widget *)> onFocusChanged
    self->onFocusChanged = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Widget_onFocusChanged(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // std::function<void (cocos2d::ui::Widget *, cocos2d::ui::Widget *)> onFocusChanged
        return _olua_fun_cocos2d_ui_Widget_onFocusChanged$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccui.Widget")) && (olua_is_callback(L, 2, "std.function") || olua_isnil(L, 2))) {
            // std::function<void (cocos2d::ui::Widget *, cocos2d::ui::Widget *)> onFocusChanged
            return _olua_fun_cocos2d_ui_Widget_onFocusChanged$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::Widget::onFocusChanged' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_Widget_onNextFocusedWidget$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Widget");

    void *cb_store = (void *)self;
    std::string cb_tag = "onNextFocusedWidget";
    olua_getcallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_EQUAL);

    // std::function<cocos2d::ui::Widget *(cocos2d::ui::Widget::FocusDirection)> onNextFocusedWidget
    std::function<cocos2d::ui::Widget *(cocos2d::ui::Widget::FocusDirection)> ret = self->onNextFocusedWidget;
    int num_ret = olua_push_callback(L, &ret, "std.function");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Widget_onNextFocusedWidget$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    std::function<cocos2d::ui::Widget *(cocos2d::ui::Widget::FocusDirection)> arg1;       /** onNextFocusedWidget */

    olua_to_object(L, 1, &self, "ccui.Widget");
    if (!olua_isnoneornil(L, 2)) {
        olua_check_callback(L, 2, &arg1, "std.function");
    }

    void *cb_store = (void *)self;
    std::string cb_tag = "onNextFocusedWidget";
    std::string cb_name;
    if (olua_isfunction(L, 2)) {
        cb_name = olua_setcallback(L, cb_store, 2, cb_tag.c_str(), OLUA_TAG_REPLACE);
        olua_Context cb_ctx = olua_context(L);
        // lua_State *ML = olua_mainthread(L);
        arg1 = [cb_store, cb_name, cb_ctx /*, ML */](cocos2d::ui::Widget::FocusDirection cb_arg1) {
            lua_State *L = olua_mainthread(NULL);
            olua_checkhostthread();
            cocos2d::ui::Widget *ret = nullptr;       /** ret */
            if (olua_contextequal(L, cb_ctx)) {
                int top = lua_gettop(L);
                olua_push_enum(L, cb_arg1);

                olua_callback(L, cb_store, cb_name.c_str(), 1);

                if (olua_is_object(L, -1, "ccui.Widget")) {
                    olua_check_object(L, -1, &ret, "ccui.Widget");
                }

                lua_settop(L, top);
            }
            return ret;
        };
    } else {
        olua_removecallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_EQUAL);
        arg1 = nullptr;
    }

    // std::function<cocos2d::ui::Widget *(cocos2d::ui::Widget::FocusDirection)> onNextFocusedWidget
    self->onNextFocusedWidget = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Widget_onNextFocusedWidget(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // std::function<cocos2d::ui::Widget *(cocos2d::ui::Widget::FocusDirection)> onNextFocusedWidget
        return _olua_fun_cocos2d_ui_Widget_onNextFocusedWidget$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccui.Widget")) && (olua_is_callback(L, 2, "std.function") || olua_isnil(L, 2))) {
            // std::function<cocos2d::ui::Widget *(cocos2d::ui::Widget::FocusDirection)> onNextFocusedWidget
            return _olua_fun_cocos2d_ui_Widget_onNextFocusedWidget$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::Widget::onNextFocusedWidget' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_Widget_onTouchBegan(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    cocos2d::Touch *arg1 = nullptr;       /** touch */
    cocos2d::Event *arg2 = nullptr;       /** unusedEvent */

    olua_to_object(L, 1, &self, "ccui.Widget");
    olua_check_object(L, 2, &arg1, "cc.Touch");
    olua_check_object(L, 3, &arg2, "cc.Event");

    // bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unusedEvent)
    bool ret = self->onTouchBegan(arg1, arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Widget_onTouchCancelled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    cocos2d::Touch *arg1 = nullptr;       /** touch */
    cocos2d::Event *arg2 = nullptr;       /** unusedEvent */

    olua_to_object(L, 1, &self, "ccui.Widget");
    olua_check_object(L, 2, &arg1, "cc.Touch");
    olua_check_object(L, 3, &arg2, "cc.Event");

    // void onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event *unusedEvent)
    self->onTouchCancelled(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Widget_onTouchEnded(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    cocos2d::Touch *arg1 = nullptr;       /** touch */
    cocos2d::Event *arg2 = nullptr;       /** unusedEvent */

    olua_to_object(L, 1, &self, "ccui.Widget");
    olua_check_object(L, 2, &arg1, "cc.Touch");
    olua_check_object(L, 3, &arg2, "cc.Event");

    // void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unusedEvent)
    self->onTouchEnded(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Widget_onTouchMoved(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    cocos2d::Touch *arg1 = nullptr;       /** touch */
    cocos2d::Event *arg2 = nullptr;       /** unusedEvent */

    olua_to_object(L, 1, &self, "ccui.Widget");
    olua_check_object(L, 2, &arg1, "cc.Touch");
    olua_check_object(L, 3, &arg2, "cc.Event");

    // void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unusedEvent)
    self->onTouchMoved(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Widget_propagateTouchEvent(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    cocos2d::ui::Widget::TouchEventType arg1 = (cocos2d::ui::Widget::TouchEventType)0;       /** event */
    cocos2d::ui::Widget *arg2 = nullptr;       /** sender */
    cocos2d::Touch *arg3 = nullptr;       /** touch */

    olua_to_object(L, 1, &self, "ccui.Widget");
    olua_check_enum(L, 2, &arg1);
    olua_check_object(L, 3, &arg2, "ccui.Widget");
    olua_check_object(L, 4, &arg3, "cc.Touch");

    // void propagateTouchEvent(cocos2d::ui::Widget::TouchEventType event, cocos2d::ui::Widget *sender, cocos2d::Touch *touch)
    self->propagateTouchEvent(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Widget_requestFocus(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Widget");

    // void requestFocus()
    self->requestFocus();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Widget_setActionTag(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    int arg1 = 0;       /** tag */

    olua_to_object(L, 1, &self, "ccui.Widget");
    olua_check_integer(L, 2, &arg1);

    // void setActionTag(int tag)
    self->setActionTag(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Widget_setBright(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    bool arg1 = false;       /** bright */

    olua_to_object(L, 1, &self, "ccui.Widget");
    olua_check_bool(L, 2, &arg1);

    // void setBright(bool bright)
    self->setBright(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Widget_setBrightStyle(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    cocos2d::ui::Widget::BrightStyle arg1 = (cocos2d::ui::Widget::BrightStyle)0;       /** style */

    olua_to_object(L, 1, &self, "ccui.Widget");
    olua_check_enum(L, 2, &arg1);

    // void setBrightStyle(cocos2d::ui::Widget::BrightStyle style)
    self->setBrightStyle(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Widget_setCallbackName(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    std::string arg1;       /** callbackName */

    olua_to_object(L, 1, &self, "ccui.Widget");
    olua_check_string(L, 2, &arg1);

    // void setCallbackName(const std::string &callbackName)
    self->setCallbackName(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Widget_setCallbackType(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    std::string arg1;       /** callbackType */

    olua_to_object(L, 1, &self, "ccui.Widget");
    olua_check_string(L, 2, &arg1);

    // void setCallbackType(const std::string &callbackType)
    self->setCallbackType(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Widget_setEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    bool arg1 = false;       /** enabled */

    olua_to_object(L, 1, &self, "ccui.Widget");
    olua_check_bool(L, 2, &arg1);

    // void setEnabled(bool enabled)
    self->setEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Widget_setFlippedX(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    bool arg1 = false;       /** flippedX */

    olua_to_object(L, 1, &self, "ccui.Widget");
    olua_check_bool(L, 2, &arg1);

    // void setFlippedX(bool flippedX)
    self->setFlippedX(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Widget_setFlippedY(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    bool arg1 = false;       /** flippedY */

    olua_to_object(L, 1, &self, "ccui.Widget");
    olua_check_bool(L, 2, &arg1);

    // void setFlippedY(bool flippedY)
    self->setFlippedY(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Widget_setFocusEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    bool arg1 = false;       /** enable */

    olua_to_object(L, 1, &self, "ccui.Widget");
    olua_check_bool(L, 2, &arg1);

    // void setFocusEnabled(bool enable)
    self->setFocusEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Widget_setFocused(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    bool arg1 = false;       /** focus */

    olua_to_object(L, 1, &self, "ccui.Widget");
    olua_check_bool(L, 2, &arg1);

    // void setFocused(bool focus)
    self->setFocused(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Widget_setHighlighted(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    bool arg1 = false;       /** highlight */

    olua_to_object(L, 1, &self, "ccui.Widget");
    olua_check_bool(L, 2, &arg1);

    // void setHighlighted(bool highlight)
    self->setHighlighted(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Widget_setLayoutComponentEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    bool arg1 = false;       /** enable */

    olua_to_object(L, 1, &self, "ccui.Widget");
    olua_check_bool(L, 2, &arg1);

    // void setLayoutComponentEnabled(bool enable)
    self->setLayoutComponentEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Widget_setLayoutParameter(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    cocos2d::ui::LayoutParameter *arg1 = nullptr;       /** parameter */

    olua_to_object(L, 1, &self, "ccui.Widget");
    olua_check_object(L, 2, &arg1, "ccui.LayoutParameter");

    // void setLayoutParameter(cocos2d::ui::LayoutParameter *parameter)
    self->setLayoutParameter(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Widget_setPositionPercent(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    cocos2d::Vec2 *arg1;       /** percent */

    olua_to_object(L, 1, &self, "ccui.Widget");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // void setPositionPercent(const cocos2d::Vec2 &percent)
    self->setPositionPercent(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Widget_setPositionType(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    cocos2d::ui::Widget::PositionType arg1 = (cocos2d::ui::Widget::PositionType)0;       /** type */

    olua_to_object(L, 1, &self, "ccui.Widget");
    olua_check_enum(L, 2, &arg1);

    // void setPositionType(cocos2d::ui::Widget::PositionType type)
    self->setPositionType(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Widget_setPropagateTouchEvents(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    bool arg1 = false;       /** isPropagate */

    olua_to_object(L, 1, &self, "ccui.Widget");
    olua_check_bool(L, 2, &arg1);

    // void setPropagateTouchEvents(bool isPropagate)
    self->setPropagateTouchEvents(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Widget_setSizePercent(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    cocos2d::Vec2 *arg1;       /** percent */

    olua_to_object(L, 1, &self, "ccui.Widget");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // void setSizePercent(const cocos2d::Vec2 &percent)
    self->setSizePercent(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Widget_setSizeType(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    cocos2d::ui::Widget::SizeType arg1 = (cocos2d::ui::Widget::SizeType)0;       /** type */

    olua_to_object(L, 1, &self, "ccui.Widget");
    olua_check_enum(L, 2, &arg1);

    // void setSizeType(cocos2d::ui::Widget::SizeType type)
    self->setSizeType(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Widget_setSwallowTouches(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    bool arg1 = false;       /** swallow */

    olua_to_object(L, 1, &self, "ccui.Widget");
    olua_check_bool(L, 2, &arg1);

    // void setSwallowTouches(bool swallow)
    self->setSwallowTouches(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Widget_setTouchEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    bool arg1 = false;       /** enabled */

    olua_to_object(L, 1, &self, "ccui.Widget");
    olua_check_bool(L, 2, &arg1);

    // void setTouchEnabled(bool enabled)
    self->setTouchEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Widget_setUnifySizeEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    bool arg1 = false;       /** enable */

    olua_to_object(L, 1, &self, "ccui.Widget");
    olua_check_bool(L, 2, &arg1);

    // void setUnifySizeEnabled(bool enable)
    self->setUnifySizeEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Widget_updateSizeAndPosition$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Widget");

    // void updateSizeAndPosition()
    self->updateSizeAndPosition();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Widget_updateSizeAndPosition$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    cocos2d::Size *arg1;       /** parentSize */

    olua_to_object(L, 1, &self, "ccui.Widget");
    olua_check_object(L, 2, &arg1, "cc.Size");

    // void updateSizeAndPosition(const cocos2d::Size &parentSize)
    self->updateSizeAndPosition(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Widget_updateSizeAndPosition(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // void updateSizeAndPosition()
        return _olua_fun_cocos2d_ui_Widget_updateSizeAndPosition$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccui.Widget")) && (olua_is_object(L, 2, "cc.Size"))) {
            // void updateSizeAndPosition(const cocos2d::Size &parentSize)
            return _olua_fun_cocos2d_ui_Widget_updateSizeAndPosition$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::Widget::updateSizeAndPosition' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_ccui_Widget(lua_State *L)
{
    oluacls_class<cocos2d::ui::Widget, cocos2d::ProtectedNode>(L, "ccui.Widget");
    oluacls_func(L, "addCCSEventListener", _olua_fun_cocos2d_ui_Widget_addCCSEventListener);
    oluacls_func(L, "addClickEventListener", _olua_fun_cocos2d_ui_Widget_addClickEventListener);
    oluacls_func(L, "addTouchEventListener", _olua_fun_cocos2d_ui_Widget_addTouchEventListener);
    oluacls_func(L, "as", _olua_fun_cocos2d_ui_Widget_as);
    oluacls_func(L, "clone", _olua_fun_cocos2d_ui_Widget_clone);
    oluacls_func(L, "create", _olua_fun_cocos2d_ui_Widget_create);
    oluacls_func(L, "dispatchFocusEvent", _olua_fun_cocos2d_ui_Widget_dispatchFocusEvent);
    oluacls_func(L, "enableDpadNavigation", _olua_fun_cocos2d_ui_Widget_enableDpadNavigation);
    oluacls_func(L, "findNextFocusedWidget", _olua_fun_cocos2d_ui_Widget_findNextFocusedWidget);
    oluacls_func(L, "getActionTag", _olua_fun_cocos2d_ui_Widget_getActionTag);
    oluacls_func(L, "getBottomBoundary", _olua_fun_cocos2d_ui_Widget_getBottomBoundary);
    oluacls_func(L, "getCallbackName", _olua_fun_cocos2d_ui_Widget_getCallbackName);
    oluacls_func(L, "getCallbackType", _olua_fun_cocos2d_ui_Widget_getCallbackType);
    oluacls_func(L, "getCurrentFocusedWidget", _olua_fun_cocos2d_ui_Widget_getCurrentFocusedWidget);
    oluacls_func(L, "getCustomSize", _olua_fun_cocos2d_ui_Widget_getCustomSize);
    oluacls_func(L, "getLayoutParameter", _olua_fun_cocos2d_ui_Widget_getLayoutParameter);
    oluacls_func(L, "getLayoutSize", _olua_fun_cocos2d_ui_Widget_getLayoutSize);
    oluacls_func(L, "getLeftBoundary", _olua_fun_cocos2d_ui_Widget_getLeftBoundary);
    oluacls_func(L, "getPositionPercent", _olua_fun_cocos2d_ui_Widget_getPositionPercent);
    oluacls_func(L, "getPositionType", _olua_fun_cocos2d_ui_Widget_getPositionType);
    oluacls_func(L, "getRightBoundary", _olua_fun_cocos2d_ui_Widget_getRightBoundary);
    oluacls_func(L, "getSizePercent", _olua_fun_cocos2d_ui_Widget_getSizePercent);
    oluacls_func(L, "getSizeType", _olua_fun_cocos2d_ui_Widget_getSizeType);
    oluacls_func(L, "getTopBoundary", _olua_fun_cocos2d_ui_Widget_getTopBoundary);
    oluacls_func(L, "getTouchBeganPosition", _olua_fun_cocos2d_ui_Widget_getTouchBeganPosition);
    oluacls_func(L, "getTouchEndPosition", _olua_fun_cocos2d_ui_Widget_getTouchEndPosition);
    oluacls_func(L, "getTouchMovePosition", _olua_fun_cocos2d_ui_Widget_getTouchMovePosition);
    oluacls_func(L, "getVirtualRenderer", _olua_fun_cocos2d_ui_Widget_getVirtualRenderer);
    oluacls_func(L, "getVirtualRendererSize", _olua_fun_cocos2d_ui_Widget_getVirtualRendererSize);
    oluacls_func(L, "getWorldPosition", _olua_fun_cocos2d_ui_Widget_getWorldPosition);
    oluacls_func(L, "hitTest", _olua_fun_cocos2d_ui_Widget_hitTest);
    oluacls_func(L, "ignoreContentAdaptWithSize", _olua_fun_cocos2d_ui_Widget_ignoreContentAdaptWithSize);
    oluacls_func(L, "interceptTouchEvent", _olua_fun_cocos2d_ui_Widget_interceptTouchEvent);
    oluacls_func(L, "isBright", _olua_fun_cocos2d_ui_Widget_isBright);
    oluacls_func(L, "isClippingParentContainsPoint", _olua_fun_cocos2d_ui_Widget_isClippingParentContainsPoint);
    oluacls_func(L, "isEnabled", _olua_fun_cocos2d_ui_Widget_isEnabled);
    oluacls_func(L, "isFlippedX", _olua_fun_cocos2d_ui_Widget_isFlippedX);
    oluacls_func(L, "isFlippedY", _olua_fun_cocos2d_ui_Widget_isFlippedY);
    oluacls_func(L, "isFocusEnabled", _olua_fun_cocos2d_ui_Widget_isFocusEnabled);
    oluacls_func(L, "isFocused", _olua_fun_cocos2d_ui_Widget_isFocused);
    oluacls_func(L, "isHighlighted", _olua_fun_cocos2d_ui_Widget_isHighlighted);
    oluacls_func(L, "isIgnoreContentAdaptWithSize", _olua_fun_cocos2d_ui_Widget_isIgnoreContentAdaptWithSize);
    oluacls_func(L, "isLayoutComponentEnabled", _olua_fun_cocos2d_ui_Widget_isLayoutComponentEnabled);
    oluacls_func(L, "isPropagateTouchEvents", _olua_fun_cocos2d_ui_Widget_isPropagateTouchEvents);
    oluacls_func(L, "isSwallowTouches", _olua_fun_cocos2d_ui_Widget_isSwallowTouches);
    oluacls_func(L, "isTouchEnabled", _olua_fun_cocos2d_ui_Widget_isTouchEnabled);
    oluacls_func(L, "isUnifySizeEnabled", _olua_fun_cocos2d_ui_Widget_isUnifySizeEnabled);
    oluacls_func(L, "new", _olua_fun_cocos2d_ui_Widget_new);
    oluacls_func(L, "onFocusChange", _olua_fun_cocos2d_ui_Widget_onFocusChange);
    oluacls_func(L, "onTouchBegan", _olua_fun_cocos2d_ui_Widget_onTouchBegan);
    oluacls_func(L, "onTouchCancelled", _olua_fun_cocos2d_ui_Widget_onTouchCancelled);
    oluacls_func(L, "onTouchEnded", _olua_fun_cocos2d_ui_Widget_onTouchEnded);
    oluacls_func(L, "onTouchMoved", _olua_fun_cocos2d_ui_Widget_onTouchMoved);
    oluacls_func(L, "propagateTouchEvent", _olua_fun_cocos2d_ui_Widget_propagateTouchEvent);
    oluacls_func(L, "requestFocus", _olua_fun_cocos2d_ui_Widget_requestFocus);
    oluacls_func(L, "setActionTag", _olua_fun_cocos2d_ui_Widget_setActionTag);
    oluacls_func(L, "setBright", _olua_fun_cocos2d_ui_Widget_setBright);
    oluacls_func(L, "setBrightStyle", _olua_fun_cocos2d_ui_Widget_setBrightStyle);
    oluacls_func(L, "setCallbackName", _olua_fun_cocos2d_ui_Widget_setCallbackName);
    oluacls_func(L, "setCallbackType", _olua_fun_cocos2d_ui_Widget_setCallbackType);
    oluacls_func(L, "setEnabled", _olua_fun_cocos2d_ui_Widget_setEnabled);
    oluacls_func(L, "setFlippedX", _olua_fun_cocos2d_ui_Widget_setFlippedX);
    oluacls_func(L, "setFlippedY", _olua_fun_cocos2d_ui_Widget_setFlippedY);
    oluacls_func(L, "setFocusEnabled", _olua_fun_cocos2d_ui_Widget_setFocusEnabled);
    oluacls_func(L, "setFocused", _olua_fun_cocos2d_ui_Widget_setFocused);
    oluacls_func(L, "setHighlighted", _olua_fun_cocos2d_ui_Widget_setHighlighted);
    oluacls_func(L, "setLayoutComponentEnabled", _olua_fun_cocos2d_ui_Widget_setLayoutComponentEnabled);
    oluacls_func(L, "setLayoutParameter", _olua_fun_cocos2d_ui_Widget_setLayoutParameter);
    oluacls_func(L, "setPositionPercent", _olua_fun_cocos2d_ui_Widget_setPositionPercent);
    oluacls_func(L, "setPositionType", _olua_fun_cocos2d_ui_Widget_setPositionType);
    oluacls_func(L, "setPropagateTouchEvents", _olua_fun_cocos2d_ui_Widget_setPropagateTouchEvents);
    oluacls_func(L, "setSizePercent", _olua_fun_cocos2d_ui_Widget_setSizePercent);
    oluacls_func(L, "setSizeType", _olua_fun_cocos2d_ui_Widget_setSizeType);
    oluacls_func(L, "setSwallowTouches", _olua_fun_cocos2d_ui_Widget_setSwallowTouches);
    oluacls_func(L, "setTouchEnabled", _olua_fun_cocos2d_ui_Widget_setTouchEnabled);
    oluacls_func(L, "setUnifySizeEnabled", _olua_fun_cocos2d_ui_Widget_setUnifySizeEnabled);
    oluacls_func(L, "updateSizeAndPosition", _olua_fun_cocos2d_ui_Widget_updateSizeAndPosition);
    oluacls_prop(L, "actionTag", _olua_fun_cocos2d_ui_Widget_getActionTag, _olua_fun_cocos2d_ui_Widget_setActionTag);
    oluacls_prop(L, "bottomBoundary", _olua_fun_cocos2d_ui_Widget_getBottomBoundary, nullptr);
    oluacls_prop(L, "bright", _olua_fun_cocos2d_ui_Widget_isBright, _olua_fun_cocos2d_ui_Widget_setBright);
    oluacls_prop(L, "callbackName", _olua_fun_cocos2d_ui_Widget_getCallbackName, _olua_fun_cocos2d_ui_Widget_setCallbackName);
    oluacls_prop(L, "callbackType", _olua_fun_cocos2d_ui_Widget_getCallbackType, _olua_fun_cocos2d_ui_Widget_setCallbackType);
    oluacls_prop(L, "currentFocusedWidget", _olua_fun_cocos2d_ui_Widget_getCurrentFocusedWidget, nullptr);
    oluacls_prop(L, "customSize", _olua_fun_cocos2d_ui_Widget_getCustomSize, nullptr);
    oluacls_prop(L, "enabled", _olua_fun_cocos2d_ui_Widget_isEnabled, _olua_fun_cocos2d_ui_Widget_setEnabled);
    oluacls_prop(L, "flippedX", _olua_fun_cocos2d_ui_Widget_isFlippedX, _olua_fun_cocos2d_ui_Widget_setFlippedX);
    oluacls_prop(L, "flippedY", _olua_fun_cocos2d_ui_Widget_isFlippedY, _olua_fun_cocos2d_ui_Widget_setFlippedY);
    oluacls_prop(L, "focusEnabled", _olua_fun_cocos2d_ui_Widget_isFocusEnabled, _olua_fun_cocos2d_ui_Widget_setFocusEnabled);
    oluacls_prop(L, "focused", _olua_fun_cocos2d_ui_Widget_isFocused, _olua_fun_cocos2d_ui_Widget_setFocused);
    oluacls_prop(L, "highlighted", _olua_fun_cocos2d_ui_Widget_isHighlighted, _olua_fun_cocos2d_ui_Widget_setHighlighted);
    oluacls_prop(L, "layoutComponentEnabled", _olua_fun_cocos2d_ui_Widget_isLayoutComponentEnabled, _olua_fun_cocos2d_ui_Widget_setLayoutComponentEnabled);
    oluacls_prop(L, "layoutParameter", _olua_fun_cocos2d_ui_Widget_getLayoutParameter, _olua_fun_cocos2d_ui_Widget_setLayoutParameter);
    oluacls_prop(L, "layoutSize", _olua_fun_cocos2d_ui_Widget_getLayoutSize, nullptr);
    oluacls_prop(L, "leftBoundary", _olua_fun_cocos2d_ui_Widget_getLeftBoundary, nullptr);
    oluacls_prop(L, "positionPercent", _olua_fun_cocos2d_ui_Widget_getPositionPercent, _olua_fun_cocos2d_ui_Widget_setPositionPercent);
    oluacls_prop(L, "positionType", _olua_fun_cocos2d_ui_Widget_getPositionType, _olua_fun_cocos2d_ui_Widget_setPositionType);
    oluacls_prop(L, "propagateTouchEvents", _olua_fun_cocos2d_ui_Widget_isPropagateTouchEvents, _olua_fun_cocos2d_ui_Widget_setPropagateTouchEvents);
    oluacls_prop(L, "rightBoundary", _olua_fun_cocos2d_ui_Widget_getRightBoundary, nullptr);
    oluacls_prop(L, "sizePercent", _olua_fun_cocos2d_ui_Widget_getSizePercent, _olua_fun_cocos2d_ui_Widget_setSizePercent);
    oluacls_prop(L, "sizeType", _olua_fun_cocos2d_ui_Widget_getSizeType, _olua_fun_cocos2d_ui_Widget_setSizeType);
    oluacls_prop(L, "swallowTouches", _olua_fun_cocos2d_ui_Widget_isSwallowTouches, _olua_fun_cocos2d_ui_Widget_setSwallowTouches);
    oluacls_prop(L, "topBoundary", _olua_fun_cocos2d_ui_Widget_getTopBoundary, nullptr);
    oluacls_prop(L, "touchBeganPosition", _olua_fun_cocos2d_ui_Widget_getTouchBeganPosition, nullptr);
    oluacls_prop(L, "touchEnabled", _olua_fun_cocos2d_ui_Widget_isTouchEnabled, _olua_fun_cocos2d_ui_Widget_setTouchEnabled);
    oluacls_prop(L, "touchEndPosition", _olua_fun_cocos2d_ui_Widget_getTouchEndPosition, nullptr);
    oluacls_prop(L, "touchMovePosition", _olua_fun_cocos2d_ui_Widget_getTouchMovePosition, nullptr);
    oluacls_prop(L, "unifySizeEnabled", _olua_fun_cocos2d_ui_Widget_isUnifySizeEnabled, _olua_fun_cocos2d_ui_Widget_setUnifySizeEnabled);
    oluacls_prop(L, "virtualRenderer", _olua_fun_cocos2d_ui_Widget_getVirtualRenderer, nullptr);
    oluacls_prop(L, "virtualRendererSize", _olua_fun_cocos2d_ui_Widget_getVirtualRendererSize, nullptr);
    oluacls_prop(L, "worldPosition", _olua_fun_cocos2d_ui_Widget_getWorldPosition, nullptr);
    oluacls_prop(L, "onFocusChanged", _olua_fun_cocos2d_ui_Widget_onFocusChanged, _olua_fun_cocos2d_ui_Widget_onFocusChanged);
    oluacls_prop(L, "onNextFocusedWidget", _olua_fun_cocos2d_ui_Widget_onNextFocusedWidget, _olua_fun_cocos2d_ui_Widget_onNextFocusedWidget);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_Widget(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.Widget")) {
        luaL_error(L, "class not found: cocos2d::ui::Widget");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_ui_Helper___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::ui::Helper *)olua_toobj(L, 1, "ccui.Helper");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Helper_changeLayoutSystemActiveState(lua_State *L)
{
    olua_startinvoke(L);

    bool arg1 = false;       /** active */

    olua_check_bool(L, 1, &arg1);

    // static void changeLayoutSystemActiveState(bool active)
    cocos2d::ui::Helper::changeLayoutSystemActiveState(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Helper_convertBoundingBoxToScreen(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Node *arg1 = nullptr;       /** node */

    olua_check_object(L, 1, &arg1, "cc.Node");

    // static cocos2d::Rect convertBoundingBoxToScreen(cocos2d::Node *node)
    cocos2d::Rect ret = cocos2d::ui::Helper::convertBoundingBoxToScreen(arg1);
    int num_ret = olua_copy_object(L, ret, "cc.Rect");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Helper_doLayout(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Node *arg1 = nullptr;       /** rootNode */

    olua_check_object(L, 1, &arg1, "cc.Node");

    // static void doLayout(cocos2d::Node *rootNode)
    cocos2d::ui::Helper::doLayout(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Helper_getSubStringOfUTF8String(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** str */
    std::string::size_type arg2 = 0;       /** start */
    std::string::size_type arg3 = 0;       /** length */

    olua_check_string(L, 1, &arg1);
    olua_check_integer(L, 2, &arg2);
    olua_check_integer(L, 3, &arg3);

    // static std::string getSubStringOfUTF8String(const std::string &str, std::string::size_type start, std::string::size_type length)
    std::string ret = cocos2d::ui::Helper::getSubStringOfUTF8String(arg1, arg2, arg3);
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Helper_restrictCapInsetRect(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Rect *arg1;       /** capInsets */
    cocos2d::Size *arg2;       /** textureSize */

    olua_check_object(L, 1, &arg1, "cc.Rect");
    olua_check_object(L, 2, &arg2, "cc.Size");

    // static cocos2d::Rect restrictCapInsetRect(const cocos2d::Rect &capInsets, const cocos2d::Size &textureSize)
    cocos2d::Rect ret = cocos2d::ui::Helper::restrictCapInsetRect(*arg1, *arg2);
    int num_ret = olua_copy_object(L, ret, "cc.Rect");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Helper_seekActionWidgetByActionTag(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *arg1 = nullptr;       /** root */
    int arg2 = 0;       /** tag */

    olua_check_object(L, 1, &arg1, "ccui.Widget");
    olua_check_integer(L, 2, &arg2);

    // static cocos2d::ui::Widget *seekActionWidgetByActionTag(cocos2d::ui::Widget *root, int tag)
    cocos2d::ui::Widget *ret = cocos2d::ui::Helper::seekActionWidgetByActionTag(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "ccui.Widget");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Helper_seekWidgetByName(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *arg1 = nullptr;       /** root */
    std::string arg2;       /** name */

    olua_check_object(L, 1, &arg1, "ccui.Widget");
    olua_check_string(L, 2, &arg2);

    // static cocos2d::ui::Widget *seekWidgetByName(cocos2d::ui::Widget *root, const std::string &name)
    cocos2d::ui::Widget *ret = cocos2d::ui::Helper::seekWidgetByName(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "ccui.Widget");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Helper_seekWidgetByTag(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *arg1 = nullptr;       /** root */
    int arg2 = 0;       /** tag */

    olua_check_object(L, 1, &arg1, "ccui.Widget");
    olua_check_integer(L, 2, &arg2);

    // static cocos2d::ui::Widget *seekWidgetByTag(cocos2d::ui::Widget *root, int tag)
    cocos2d::ui::Widget *ret = cocos2d::ui::Helper::seekWidgetByTag(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "ccui.Widget");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_cls_ccui_Helper(lua_State *L)
{
    oluacls_class<cocos2d::ui::Helper>(L, "ccui.Helper");
    oluacls_func(L, "__gc", _olua_fun_cocos2d_ui_Helper___gc);
    oluacls_func(L, "changeLayoutSystemActiveState", _olua_fun_cocos2d_ui_Helper_changeLayoutSystemActiveState);
    oluacls_func(L, "convertBoundingBoxToScreen", _olua_fun_cocos2d_ui_Helper_convertBoundingBoxToScreen);
    oluacls_func(L, "doLayout", _olua_fun_cocos2d_ui_Helper_doLayout);
    oluacls_func(L, "getSubStringOfUTF8String", _olua_fun_cocos2d_ui_Helper_getSubStringOfUTF8String);
    oluacls_func(L, "restrictCapInsetRect", _olua_fun_cocos2d_ui_Helper_restrictCapInsetRect);
    oluacls_func(L, "seekActionWidgetByActionTag", _olua_fun_cocos2d_ui_Helper_seekActionWidgetByActionTag);
    oluacls_func(L, "seekWidgetByName", _olua_fun_cocos2d_ui_Helper_seekWidgetByName);
    oluacls_func(L, "seekWidgetByTag", _olua_fun_cocos2d_ui_Helper_seekWidgetByTag);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_Helper(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.Helper")) {
        luaL_error(L, "class not found: cocos2d::ui::Helper");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_ccui_Scale9Sprite_State(lua_State *L)
{
    oluacls_class<cocos2d::ui::Scale9Sprite::State>(L, "ccui.Scale9Sprite.State");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "GRAY", (lua_Integer)cocos2d::ui::Scale9Sprite::State::GRAY);
    oluacls_enum(L, "NORMAL", (lua_Integer)cocos2d::ui::Scale9Sprite::State::NORMAL);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_Scale9Sprite_State(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.Scale9Sprite.State")) {
        luaL_error(L, "class not found: cocos2d::ui::Scale9Sprite::State");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_ccui_Scale9Sprite_RenderingType(lua_State *L)
{
    oluacls_class<cocos2d::ui::Scale9Sprite::RenderingType>(L, "ccui.Scale9Sprite.RenderingType");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "SIMPLE", (lua_Integer)cocos2d::ui::Scale9Sprite::RenderingType::SIMPLE);
    oluacls_enum(L, "SLICE", (lua_Integer)cocos2d::ui::Scale9Sprite::RenderingType::SLICE);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_Scale9Sprite_RenderingType(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.Scale9Sprite.RenderingType")) {
        luaL_error(L, "class not found: cocos2d::ui::Scale9Sprite::RenderingType");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_ui_Scale9Sprite_copyTo(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Scale9Sprite *self = nullptr;
    cocos2d::ui::Scale9Sprite *arg1 = nullptr;       /** copy */

    olua_to_object(L, 1, &self, "ccui.Scale9Sprite");
    olua_check_object(L, 2, &arg1, "ccui.Scale9Sprite");

    // void copyTo(cocos2d::ui::Scale9Sprite *copy)
    self->copyTo(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Scale9Sprite_create$1(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::ui::Scale9Sprite *create()
    cocos2d::ui::Scale9Sprite *ret = cocos2d::ui::Scale9Sprite::create();
    int num_ret = olua_push_object(L, ret, "ccui.Scale9Sprite");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Scale9Sprite_create$2(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** file */
    cocos2d::Rect *arg2;       /** rect */
    cocos2d::Rect *arg3;       /** capInsets */

    olua_check_string(L, 1, &arg1);
    olua_check_object(L, 2, &arg2, "cc.Rect");
    olua_check_object(L, 3, &arg3, "cc.Rect");

    // static cocos2d::ui::Scale9Sprite *create(const std::string &file, const cocos2d::Rect &rect, const cocos2d::Rect &capInsets)
    cocos2d::ui::Scale9Sprite *ret = cocos2d::ui::Scale9Sprite::create(arg1, *arg2, *arg3);
    int num_ret = olua_push_object(L, ret, "ccui.Scale9Sprite");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Scale9Sprite_create$3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Rect *arg1;       /** capInsets */
    std::string arg2;       /** file */

    olua_check_object(L, 1, &arg1, "cc.Rect");
    olua_check_string(L, 2, &arg2);

    // static cocos2d::ui::Scale9Sprite *create(const cocos2d::Rect &capInsets, const std::string &file)
    cocos2d::ui::Scale9Sprite *ret = cocos2d::ui::Scale9Sprite::create(*arg1, arg2);
    int num_ret = olua_push_object(L, ret, "ccui.Scale9Sprite");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Scale9Sprite_create$4(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** file */
    cocos2d::Rect *arg2;       /** rect */

    olua_check_string(L, 1, &arg1);
    olua_check_object(L, 2, &arg2, "cc.Rect");

    // static cocos2d::ui::Scale9Sprite *create(const std::string &file, const cocos2d::Rect &rect)
    cocos2d::ui::Scale9Sprite *ret = cocos2d::ui::Scale9Sprite::create(arg1, *arg2);
    int num_ret = olua_push_object(L, ret, "ccui.Scale9Sprite");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Scale9Sprite_create$5(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** file */

    olua_check_string(L, 1, &arg1);

    // static cocos2d::ui::Scale9Sprite *create(const std::string &file)
    cocos2d::ui::Scale9Sprite *ret = cocos2d::ui::Scale9Sprite::create(arg1);
    int num_ret = olua_push_object(L, ret, "ccui.Scale9Sprite");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Scale9Sprite_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // static cocos2d::ui::Scale9Sprite *create()
        return _olua_fun_cocos2d_ui_Scale9Sprite_create$1(L);
    }

    if (num_args == 1) {
        // if ((olua_is_string(L, 1))) {
            // static cocos2d::ui::Scale9Sprite *create(const std::string &file)
            return _olua_fun_cocos2d_ui_Scale9Sprite_create$5(L);
        // }
    }

    if (num_args == 2) {
        if ((olua_is_object(L, 1, "cc.Rect")) && (olua_is_string(L, 2))) {
            // static cocos2d::ui::Scale9Sprite *create(const cocos2d::Rect &capInsets, const std::string &file)
            return _olua_fun_cocos2d_ui_Scale9Sprite_create$3(L);
        }

        // if ((olua_is_string(L, 1)) && (olua_is_object(L, 2, "cc.Rect"))) {
            // static cocos2d::ui::Scale9Sprite *create(const std::string &file, const cocos2d::Rect &rect)
            return _olua_fun_cocos2d_ui_Scale9Sprite_create$4(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_string(L, 1)) && (olua_is_object(L, 2, "cc.Rect")) && (olua_is_object(L, 3, "cc.Rect"))) {
            // static cocos2d::ui::Scale9Sprite *create(const std::string &file, const cocos2d::Rect &rect, const cocos2d::Rect &capInsets)
            return _olua_fun_cocos2d_ui_Scale9Sprite_create$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::Scale9Sprite::create' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_Scale9Sprite_createWithSpriteFrame$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::SpriteFrame *arg1 = nullptr;       /** spriteFrame */

    olua_check_object(L, 1, &arg1, "cc.SpriteFrame");

    // static cocos2d::ui::Scale9Sprite *createWithSpriteFrame(cocos2d::SpriteFrame *spriteFrame)
    cocos2d::ui::Scale9Sprite *ret = cocos2d::ui::Scale9Sprite::createWithSpriteFrame(arg1);
    int num_ret = olua_push_object(L, ret, "ccui.Scale9Sprite");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Scale9Sprite_createWithSpriteFrame$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::SpriteFrame *arg1 = nullptr;       /** spriteFrame */
    cocos2d::Rect *arg2;       /** capInsets */

    olua_check_object(L, 1, &arg1, "cc.SpriteFrame");
    olua_check_object(L, 2, &arg2, "cc.Rect");

    // static cocos2d::ui::Scale9Sprite *createWithSpriteFrame(cocos2d::SpriteFrame *spriteFrame, const cocos2d::Rect &capInsets)
    cocos2d::ui::Scale9Sprite *ret = cocos2d::ui::Scale9Sprite::createWithSpriteFrame(arg1, *arg2);
    int num_ret = olua_push_object(L, ret, "ccui.Scale9Sprite");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Scale9Sprite_createWithSpriteFrame(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_object(L, 1, "cc.SpriteFrame"))) {
            // static cocos2d::ui::Scale9Sprite *createWithSpriteFrame(cocos2d::SpriteFrame *spriteFrame)
            return _olua_fun_cocos2d_ui_Scale9Sprite_createWithSpriteFrame$1(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.SpriteFrame")) && (olua_is_object(L, 2, "cc.Rect"))) {
            // static cocos2d::ui::Scale9Sprite *createWithSpriteFrame(cocos2d::SpriteFrame *spriteFrame, const cocos2d::Rect &capInsets)
            return _olua_fun_cocos2d_ui_Scale9Sprite_createWithSpriteFrame$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::Scale9Sprite::createWithSpriteFrame' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_Scale9Sprite_createWithSpriteFrameName$1(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** spriteFrameName */

    olua_check_string(L, 1, &arg1);

    // static cocos2d::ui::Scale9Sprite *createWithSpriteFrameName(const std::string &spriteFrameName)
    cocos2d::ui::Scale9Sprite *ret = cocos2d::ui::Scale9Sprite::createWithSpriteFrameName(arg1);
    int num_ret = olua_push_object(L, ret, "ccui.Scale9Sprite");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Scale9Sprite_createWithSpriteFrameName$2(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** spriteFrameName */
    cocos2d::Rect *arg2;       /** capInsets */

    olua_check_string(L, 1, &arg1);
    olua_check_object(L, 2, &arg2, "cc.Rect");

    // static cocos2d::ui::Scale9Sprite *createWithSpriteFrameName(const std::string &spriteFrameName, const cocos2d::Rect &capInsets)
    cocos2d::ui::Scale9Sprite *ret = cocos2d::ui::Scale9Sprite::createWithSpriteFrameName(arg1, *arg2);
    int num_ret = olua_push_object(L, ret, "ccui.Scale9Sprite");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Scale9Sprite_createWithSpriteFrameName(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_string(L, 1))) {
            // static cocos2d::ui::Scale9Sprite *createWithSpriteFrameName(const std::string &spriteFrameName)
            return _olua_fun_cocos2d_ui_Scale9Sprite_createWithSpriteFrameName$1(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_string(L, 1)) && (olua_is_object(L, 2, "cc.Rect"))) {
            // static cocos2d::ui::Scale9Sprite *createWithSpriteFrameName(const std::string &spriteFrameName, const cocos2d::Rect &capInsets)
            return _olua_fun_cocos2d_ui_Scale9Sprite_createWithSpriteFrameName$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::Scale9Sprite::createWithSpriteFrameName' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_Scale9Sprite_getCapInsets(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Scale9Sprite *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Scale9Sprite");

    // cocos2d::Rect getCapInsets()
    cocos2d::Rect ret = self->getCapInsets();
    int num_ret = olua_copy_object(L, ret, "cc.Rect");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Scale9Sprite_getInsetBottom(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Scale9Sprite *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Scale9Sprite");

    // float getInsetBottom()
    float ret = self->getInsetBottom();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Scale9Sprite_getInsetLeft(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Scale9Sprite *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Scale9Sprite");

    // float getInsetLeft()
    float ret = self->getInsetLeft();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Scale9Sprite_getInsetRight(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Scale9Sprite *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Scale9Sprite");

    // float getInsetRight()
    float ret = self->getInsetRight();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Scale9Sprite_getInsetTop(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Scale9Sprite *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Scale9Sprite");

    // float getInsetTop()
    float ret = self->getInsetTop();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Scale9Sprite_getOriginalSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Scale9Sprite *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Scale9Sprite");

    // cocos2d::Size getOriginalSize()
    cocos2d::Size ret = self->getOriginalSize();
    int num_ret = olua_copy_object(L, ret, "cc.Size");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Scale9Sprite_getPreferredSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Scale9Sprite *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Scale9Sprite");

    // cocos2d::Size getPreferredSize()
    cocos2d::Size ret = self->getPreferredSize();
    int num_ret = olua_copy_object(L, ret, "cc.Size");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Scale9Sprite_getRenderingType(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Scale9Sprite *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Scale9Sprite");

    // cocos2d::ui::Scale9Sprite::RenderingType getRenderingType()
    cocos2d::ui::Scale9Sprite::RenderingType ret = self->getRenderingType();
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Scale9Sprite_getSprite(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Scale9Sprite *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Scale9Sprite");

    // cocos2d::Sprite *getSprite()
    cocos2d::Sprite *ret = self->getSprite();
    int num_ret = olua_push_object(L, ret, "cc.Sprite");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Scale9Sprite_getState(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Scale9Sprite *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Scale9Sprite");

    // cocos2d::ui::Scale9Sprite::State getState()
    cocos2d::ui::Scale9Sprite::State ret = self->getState();
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Scale9Sprite_init$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Scale9Sprite *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Scale9Sprite");

    // @using bool init()
    bool ret = self->init();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Scale9Sprite_init$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Scale9Sprite *self = nullptr;
    cocos2d::Sprite *arg1 = nullptr;       /** sprite */
    cocos2d::Rect *arg2;       /** rect */
    bool arg3 = false;       /** rotated */
    cocos2d::Rect *arg4;       /** capInsets */

    olua_to_object(L, 1, &self, "ccui.Scale9Sprite");
    olua_check_object(L, 2, &arg1, "cc.Sprite");
    olua_check_object(L, 3, &arg2, "cc.Rect");
    olua_check_bool(L, 4, &arg3);
    olua_check_object(L, 5, &arg4, "cc.Rect");

    // bool init(cocos2d::Sprite *sprite, const cocos2d::Rect &rect, bool rotated, const cocos2d::Rect &capInsets)
    bool ret = self->init(arg1, *arg2, arg3, *arg4);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Scale9Sprite_init$3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Scale9Sprite *self = nullptr;
    cocos2d::Sprite *arg1 = nullptr;       /** sprite */
    cocos2d::Rect *arg2;       /** rect */
    cocos2d::Rect *arg3;       /** capInsets */

    olua_to_object(L, 1, &self, "ccui.Scale9Sprite");
    olua_check_object(L, 2, &arg1, "cc.Sprite");
    olua_check_object(L, 3, &arg2, "cc.Rect");
    olua_check_object(L, 4, &arg3, "cc.Rect");

    // bool init(cocos2d::Sprite *sprite, const cocos2d::Rect &rect, const cocos2d::Rect &capInsets)
    bool ret = self->init(arg1, *arg2, *arg3);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Scale9Sprite_init$4(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Scale9Sprite *self = nullptr;
    cocos2d::Sprite *arg1 = nullptr;       /** sprite */
    cocos2d::Rect *arg2;       /** rect */
    bool arg3 = false;       /** rotated */
    cocos2d::Vec2 *arg4;       /** offset */
    cocos2d::Size *arg5;       /** originalSize */
    cocos2d::Rect *arg6;       /** capInsets */

    olua_to_object(L, 1, &self, "ccui.Scale9Sprite");
    olua_check_object(L, 2, &arg1, "cc.Sprite");
    olua_check_object(L, 3, &arg2, "cc.Rect");
    olua_check_bool(L, 4, &arg3);
    olua_check_object(L, 5, &arg4, "cc.Vec2");
    olua_check_object(L, 6, &arg5, "cc.Size");
    olua_check_object(L, 7, &arg6, "cc.Rect");

    // bool init(cocos2d::Sprite *sprite, const cocos2d::Rect &rect, bool rotated, const cocos2d::Vec2 &offset, const cocos2d::Size &originalSize, const cocos2d::Rect &capInsets)
    bool ret = self->init(arg1, *arg2, arg3, *arg4, *arg5, *arg6);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Scale9Sprite_init(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // @using bool init()
        return _olua_fun_cocos2d_ui_Scale9Sprite_init$1(L);
    }

    if (num_args == 4) {
        // if ((olua_is_object(L, 1, "ccui.Scale9Sprite")) && (olua_is_object(L, 2, "cc.Sprite")) && (olua_is_object(L, 3, "cc.Rect")) && (olua_is_object(L, 4, "cc.Rect"))) {
            // bool init(cocos2d::Sprite *sprite, const cocos2d::Rect &rect, const cocos2d::Rect &capInsets)
            return _olua_fun_cocos2d_ui_Scale9Sprite_init$3(L);
        // }
    }

    if (num_args == 5) {
        // if ((olua_is_object(L, 1, "ccui.Scale9Sprite")) && (olua_is_object(L, 2, "cc.Sprite")) && (olua_is_object(L, 3, "cc.Rect")) && (olua_is_bool(L, 4)) && (olua_is_object(L, 5, "cc.Rect"))) {
            // bool init(cocos2d::Sprite *sprite, const cocos2d::Rect &rect, bool rotated, const cocos2d::Rect &capInsets)
            return _olua_fun_cocos2d_ui_Scale9Sprite_init$2(L);
        // }
    }

    if (num_args == 7) {
        // if ((olua_is_object(L, 1, "ccui.Scale9Sprite")) && (olua_is_object(L, 2, "cc.Sprite")) && (olua_is_object(L, 3, "cc.Rect")) && (olua_is_bool(L, 4)) && (olua_is_object(L, 5, "cc.Vec2")) && (olua_is_object(L, 6, "cc.Size")) && (olua_is_object(L, 7, "cc.Rect"))) {
            // bool init(cocos2d::Sprite *sprite, const cocos2d::Rect &rect, bool rotated, const cocos2d::Vec2 &offset, const cocos2d::Size &originalSize, const cocos2d::Rect &capInsets)
            return _olua_fun_cocos2d_ui_Scale9Sprite_init$4(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::Scale9Sprite::init' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_Scale9Sprite_initWithFile$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Scale9Sprite *self = nullptr;
    std::string arg1;       /** file */
    cocos2d::Rect *arg2;       /** rect */
    cocos2d::Rect *arg3;       /** capInsets */

    olua_to_object(L, 1, &self, "ccui.Scale9Sprite");
    olua_check_string(L, 2, &arg1);
    olua_check_object(L, 3, &arg2, "cc.Rect");
    olua_check_object(L, 4, &arg3, "cc.Rect");

    // bool initWithFile(const std::string &file, const cocos2d::Rect &rect, const cocos2d::Rect &capInsets)
    bool ret = self->initWithFile(arg1, *arg2, *arg3);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Scale9Sprite_initWithFile$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Scale9Sprite *self = nullptr;
    cocos2d::Rect *arg1;       /** capInsets */
    std::string arg2;       /** file */

    olua_to_object(L, 1, &self, "ccui.Scale9Sprite");
    olua_check_object(L, 2, &arg1, "cc.Rect");
    olua_check_string(L, 3, &arg2);

    // bool initWithFile(const cocos2d::Rect &capInsets, const std::string &file)
    bool ret = self->initWithFile(*arg1, arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Scale9Sprite_initWithFile$3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Scale9Sprite *self = nullptr;
    std::string arg1;       /** file */
    cocos2d::Rect *arg2;       /** rect */

    olua_to_object(L, 1, &self, "ccui.Scale9Sprite");
    olua_check_string(L, 2, &arg1);
    olua_check_object(L, 3, &arg2, "cc.Rect");

    // @using bool initWithFile(const std::string &file, const cocos2d::Rect &rect)
    bool ret = self->initWithFile(arg1, *arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Scale9Sprite_initWithFile$4(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Scale9Sprite *self = nullptr;
    std::string arg1;       /** file */

    olua_to_object(L, 1, &self, "ccui.Scale9Sprite");
    olua_check_string(L, 2, &arg1);

    // @using bool initWithFile(const std::string &file)
    bool ret = self->initWithFile(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Scale9Sprite_initWithFile(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccui.Scale9Sprite")) && (olua_is_string(L, 2))) {
            // @using bool initWithFile(const std::string &file)
            return _olua_fun_cocos2d_ui_Scale9Sprite_initWithFile$4(L);
        // }
    }

    if (num_args == 3) {
        if ((olua_is_object(L, 1, "ccui.Scale9Sprite")) && (olua_is_object(L, 2, "cc.Rect")) && (olua_is_string(L, 3))) {
            // bool initWithFile(const cocos2d::Rect &capInsets, const std::string &file)
            return _olua_fun_cocos2d_ui_Scale9Sprite_initWithFile$2(L);
        }

        // if ((olua_is_object(L, 1, "ccui.Scale9Sprite")) && (olua_is_string(L, 2)) && (olua_is_object(L, 3, "cc.Rect"))) {
            // @using bool initWithFile(const std::string &file, const cocos2d::Rect &rect)
            return _olua_fun_cocos2d_ui_Scale9Sprite_initWithFile$3(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_object(L, 1, "ccui.Scale9Sprite")) && (olua_is_string(L, 2)) && (olua_is_object(L, 3, "cc.Rect")) && (olua_is_object(L, 4, "cc.Rect"))) {
            // bool initWithFile(const std::string &file, const cocos2d::Rect &rect, const cocos2d::Rect &capInsets)
            return _olua_fun_cocos2d_ui_Scale9Sprite_initWithFile$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::Scale9Sprite::initWithFile' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_Scale9Sprite_initWithSpriteFrame$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Scale9Sprite *self = nullptr;
    cocos2d::SpriteFrame *arg1 = nullptr;       /** spriteFrame */
    cocos2d::Rect *arg2;       /** capInsets */

    olua_to_object(L, 1, &self, "ccui.Scale9Sprite");
    olua_check_object(L, 2, &arg1, "cc.SpriteFrame");
    olua_check_object(L, 3, &arg2, "cc.Rect");

    // bool initWithSpriteFrame(cocos2d::SpriteFrame *spriteFrame, const cocos2d::Rect &capInsets)
    bool ret = self->initWithSpriteFrame(arg1, *arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Scale9Sprite_initWithSpriteFrame$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Scale9Sprite *self = nullptr;
    cocos2d::SpriteFrame *arg1 = nullptr;       /** spriteFrame */

    olua_to_object(L, 1, &self, "ccui.Scale9Sprite");
    olua_check_object(L, 2, &arg1, "cc.SpriteFrame");

    // @using bool initWithSpriteFrame(cocos2d::SpriteFrame *spriteFrame)
    bool ret = self->initWithSpriteFrame(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Scale9Sprite_initWithSpriteFrame(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccui.Scale9Sprite")) && (olua_is_object(L, 2, "cc.SpriteFrame"))) {
            // @using bool initWithSpriteFrame(cocos2d::SpriteFrame *spriteFrame)
            return _olua_fun_cocos2d_ui_Scale9Sprite_initWithSpriteFrame$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "ccui.Scale9Sprite")) && (olua_is_object(L, 2, "cc.SpriteFrame")) && (olua_is_object(L, 3, "cc.Rect"))) {
            // bool initWithSpriteFrame(cocos2d::SpriteFrame *spriteFrame, const cocos2d::Rect &capInsets)
            return _olua_fun_cocos2d_ui_Scale9Sprite_initWithSpriteFrame$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::Scale9Sprite::initWithSpriteFrame' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_Scale9Sprite_initWithSpriteFrameName$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Scale9Sprite *self = nullptr;
    std::string arg1;       /** spriteFrameName */
    cocos2d::Rect *arg2;       /** capInsets */

    olua_to_object(L, 1, &self, "ccui.Scale9Sprite");
    olua_check_string(L, 2, &arg1);
    olua_check_object(L, 3, &arg2, "cc.Rect");

    // bool initWithSpriteFrameName(const std::string &spriteFrameName, const cocos2d::Rect &capInsets)
    bool ret = self->initWithSpriteFrameName(arg1, *arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Scale9Sprite_initWithSpriteFrameName$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Scale9Sprite *self = nullptr;
    std::string arg1;       /** spriteFrameName */

    olua_to_object(L, 1, &self, "ccui.Scale9Sprite");
    olua_check_string(L, 2, &arg1);

    // @using bool initWithSpriteFrameName(const std::string &spriteFrameName)
    bool ret = self->initWithSpriteFrameName(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Scale9Sprite_initWithSpriteFrameName(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccui.Scale9Sprite")) && (olua_is_string(L, 2))) {
            // @using bool initWithSpriteFrameName(const std::string &spriteFrameName)
            return _olua_fun_cocos2d_ui_Scale9Sprite_initWithSpriteFrameName$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "ccui.Scale9Sprite")) && (olua_is_string(L, 2)) && (olua_is_object(L, 3, "cc.Rect"))) {
            // bool initWithSpriteFrameName(const std::string &spriteFrameName, const cocos2d::Rect &capInsets)
            return _olua_fun_cocos2d_ui_Scale9Sprite_initWithSpriteFrameName$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::Scale9Sprite::initWithSpriteFrameName' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_Scale9Sprite_isScale9Enabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Scale9Sprite *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Scale9Sprite");

    // bool isScale9Enabled()
    bool ret = self->isScale9Enabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Scale9Sprite_new(lua_State *L)
{
    olua_startinvoke(L);

    // cocos2d::ui::Scale9Sprite()
    cocos2d::ui::Scale9Sprite *ret = new cocos2d::ui::Scale9Sprite();
    int num_ret = olua_push_object(L, ret, "ccui.Scale9Sprite");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Scale9Sprite_resetRender(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Scale9Sprite *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Scale9Sprite");

    // void resetRender()
    self->resetRender();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Scale9Sprite_resizableSpriteWithCapInsets(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Scale9Sprite *self = nullptr;
    cocos2d::Rect *arg1;       /** capInsets */

    olua_to_object(L, 1, &self, "ccui.Scale9Sprite");
    olua_check_object(L, 2, &arg1, "cc.Rect");

    // cocos2d::ui::Scale9Sprite *resizableSpriteWithCapInsets(const cocos2d::Rect &capInsets)
    cocos2d::ui::Scale9Sprite *ret = self->resizableSpriteWithCapInsets(*arg1);
    int num_ret = olua_push_object(L, ret, "ccui.Scale9Sprite");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Scale9Sprite_setCapInsets(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Scale9Sprite *self = nullptr;
    cocos2d::Rect *arg1;       /** insets */

    olua_to_object(L, 1, &self, "ccui.Scale9Sprite");
    olua_check_object(L, 2, &arg1, "cc.Rect");

    // void setCapInsets(const cocos2d::Rect &insets)
    self->setCapInsets(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Scale9Sprite_setInsetBottom(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Scale9Sprite *self = nullptr;
    float arg1 = 0;       /** bottomInset */

    olua_to_object(L, 1, &self, "ccui.Scale9Sprite");
    olua_check_number(L, 2, &arg1);

    // void setInsetBottom(float bottomInset)
    self->setInsetBottom(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Scale9Sprite_setInsetLeft(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Scale9Sprite *self = nullptr;
    float arg1 = 0;       /** leftInset */

    olua_to_object(L, 1, &self, "ccui.Scale9Sprite");
    olua_check_number(L, 2, &arg1);

    // void setInsetLeft(float leftInset)
    self->setInsetLeft(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Scale9Sprite_setInsetRight(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Scale9Sprite *self = nullptr;
    float arg1 = 0;       /** rightInset */

    olua_to_object(L, 1, &self, "ccui.Scale9Sprite");
    olua_check_number(L, 2, &arg1);

    // void setInsetRight(float rightInset)
    self->setInsetRight(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Scale9Sprite_setInsetTop(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Scale9Sprite *self = nullptr;
    float arg1 = 0;       /** topInset */

    olua_to_object(L, 1, &self, "ccui.Scale9Sprite");
    olua_check_number(L, 2, &arg1);

    // void setInsetTop(float topInset)
    self->setInsetTop(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Scale9Sprite_setPreferredSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Scale9Sprite *self = nullptr;
    cocos2d::Size *arg1;       /** size */

    olua_to_object(L, 1, &self, "ccui.Scale9Sprite");
    olua_check_object(L, 2, &arg1, "cc.Size");

    // void setPreferredSize(const cocos2d::Size &size)
    self->setPreferredSize(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Scale9Sprite_setRenderingType(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Scale9Sprite *self = nullptr;
    cocos2d::ui::Scale9Sprite::RenderingType arg1 = (cocos2d::ui::Scale9Sprite::RenderingType)0;       /** type */

    olua_to_object(L, 1, &self, "ccui.Scale9Sprite");
    olua_check_enum(L, 2, &arg1);

    // void setRenderingType(cocos2d::ui::Scale9Sprite::RenderingType type)
    self->setRenderingType(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Scale9Sprite_setScale9Enabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Scale9Sprite *self = nullptr;
    bool arg1 = false;       /** enabled */

    olua_to_object(L, 1, &self, "ccui.Scale9Sprite");
    olua_check_bool(L, 2, &arg1);

    // void setScale9Enabled(bool enabled)
    self->setScale9Enabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Scale9Sprite_setSpriteFrame$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Scale9Sprite *self = nullptr;
    cocos2d::SpriteFrame *arg1 = nullptr;       /** spriteFrame */
    cocos2d::Rect *arg2;       /** capInsets */

    olua_to_object(L, 1, &self, "ccui.Scale9Sprite");
    olua_check_object(L, 2, &arg1, "cc.SpriteFrame");
    olua_check_object(L, 3, &arg2, "cc.Rect");

    // void setSpriteFrame(cocos2d::SpriteFrame *spriteFrame, const cocos2d::Rect &capInsets)
    self->setSpriteFrame(arg1, *arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Scale9Sprite_setSpriteFrame$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Scale9Sprite *self = nullptr;
    std::string arg1;       /** spriteFrameName */

    olua_to_object(L, 1, &self, "ccui.Scale9Sprite");
    olua_check_string(L, 2, &arg1);

    // @using void setSpriteFrame(const std::string &spriteFrameName)
    self->setSpriteFrame(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Scale9Sprite_setSpriteFrame$3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Scale9Sprite *self = nullptr;
    cocos2d::SpriteFrame *arg1 = nullptr;       /** newFrame */

    olua_to_object(L, 1, &self, "ccui.Scale9Sprite");
    olua_check_object(L, 2, &arg1, "cc.SpriteFrame");

    // @using void setSpriteFrame(cocos2d::SpriteFrame *newFrame)
    self->setSpriteFrame(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Scale9Sprite_setSpriteFrame(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        if ((olua_is_object(L, 1, "ccui.Scale9Sprite")) && (olua_is_string(L, 2))) {
            // @using void setSpriteFrame(const std::string &spriteFrameName)
            return _olua_fun_cocos2d_ui_Scale9Sprite_setSpriteFrame$2(L);
        }

        // if ((olua_is_object(L, 1, "ccui.Scale9Sprite")) && (olua_is_object(L, 2, "cc.SpriteFrame"))) {
            // @using void setSpriteFrame(cocos2d::SpriteFrame *newFrame)
            return _olua_fun_cocos2d_ui_Scale9Sprite_setSpriteFrame$3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "ccui.Scale9Sprite")) && (olua_is_object(L, 2, "cc.SpriteFrame")) && (olua_is_object(L, 3, "cc.Rect"))) {
            // void setSpriteFrame(cocos2d::SpriteFrame *spriteFrame, const cocos2d::Rect &capInsets)
            return _olua_fun_cocos2d_ui_Scale9Sprite_setSpriteFrame$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::Scale9Sprite::setSpriteFrame' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_Scale9Sprite_setState(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Scale9Sprite *self = nullptr;
    cocos2d::ui::Scale9Sprite::State arg1 = (cocos2d::ui::Scale9Sprite::State)0;       /** state */

    olua_to_object(L, 1, &self, "ccui.Scale9Sprite");
    olua_check_enum(L, 2, &arg1);

    // void setState(cocos2d::ui::Scale9Sprite::State state)
    self->setState(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Scale9Sprite_updateWithSprite$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Scale9Sprite *self = nullptr;
    cocos2d::Sprite *arg1 = nullptr;       /** sprite */
    cocos2d::Rect *arg2;       /** rect */
    bool arg3 = false;       /** rotated */
    cocos2d::Rect *arg4;       /** capInsets */

    olua_to_object(L, 1, &self, "ccui.Scale9Sprite");
    olua_check_object(L, 2, &arg1, "cc.Sprite");
    olua_check_object(L, 3, &arg2, "cc.Rect");
    olua_check_bool(L, 4, &arg3);
    olua_check_object(L, 5, &arg4, "cc.Rect");

    // bool updateWithSprite(cocos2d::Sprite *sprite, const cocos2d::Rect &rect, bool rotated, const cocos2d::Rect &capInsets)
    bool ret = self->updateWithSprite(arg1, *arg2, arg3, *arg4);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Scale9Sprite_updateWithSprite$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Scale9Sprite *self = nullptr;
    cocos2d::Sprite *arg1 = nullptr;       /** sprite */
    cocos2d::Rect *arg2;       /** rect */
    bool arg3 = false;       /** rotated */
    cocos2d::Vec2 *arg4;       /** offset */
    cocos2d::Size *arg5;       /** originalSize */
    cocos2d::Rect *arg6;       /** capInsets */

    olua_to_object(L, 1, &self, "ccui.Scale9Sprite");
    olua_check_object(L, 2, &arg1, "cc.Sprite");
    olua_check_object(L, 3, &arg2, "cc.Rect");
    olua_check_bool(L, 4, &arg3);
    olua_check_object(L, 5, &arg4, "cc.Vec2");
    olua_check_object(L, 6, &arg5, "cc.Size");
    olua_check_object(L, 7, &arg6, "cc.Rect");

    // bool updateWithSprite(cocos2d::Sprite *sprite, const cocos2d::Rect &rect, bool rotated, const cocos2d::Vec2 &offset, const cocos2d::Size &originalSize, const cocos2d::Rect &capInsets)
    bool ret = self->updateWithSprite(arg1, *arg2, arg3, *arg4, *arg5, *arg6);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Scale9Sprite_updateWithSprite(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 5) {
        // if ((olua_is_object(L, 1, "ccui.Scale9Sprite")) && (olua_is_object(L, 2, "cc.Sprite")) && (olua_is_object(L, 3, "cc.Rect")) && (olua_is_bool(L, 4)) && (olua_is_object(L, 5, "cc.Rect"))) {
            // bool updateWithSprite(cocos2d::Sprite *sprite, const cocos2d::Rect &rect, bool rotated, const cocos2d::Rect &capInsets)
            return _olua_fun_cocos2d_ui_Scale9Sprite_updateWithSprite$1(L);
        // }
    }

    if (num_args == 7) {
        // if ((olua_is_object(L, 1, "ccui.Scale9Sprite")) && (olua_is_object(L, 2, "cc.Sprite")) && (olua_is_object(L, 3, "cc.Rect")) && (olua_is_bool(L, 4)) && (olua_is_object(L, 5, "cc.Vec2")) && (olua_is_object(L, 6, "cc.Size")) && (olua_is_object(L, 7, "cc.Rect"))) {
            // bool updateWithSprite(cocos2d::Sprite *sprite, const cocos2d::Rect &rect, bool rotated, const cocos2d::Vec2 &offset, const cocos2d::Size &originalSize, const cocos2d::Rect &capInsets)
            return _olua_fun_cocos2d_ui_Scale9Sprite_updateWithSprite$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::Scale9Sprite::updateWithSprite' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_ccui_Scale9Sprite(lua_State *L)
{
    oluacls_class<cocos2d::ui::Scale9Sprite, cocos2d::Sprite>(L, "ccui.Scale9Sprite");
    oluacls_func(L, "copyTo", _olua_fun_cocos2d_ui_Scale9Sprite_copyTo);
    oluacls_func(L, "create", _olua_fun_cocos2d_ui_Scale9Sprite_create);
    oluacls_func(L, "createWithSpriteFrame", _olua_fun_cocos2d_ui_Scale9Sprite_createWithSpriteFrame);
    oluacls_func(L, "createWithSpriteFrameName", _olua_fun_cocos2d_ui_Scale9Sprite_createWithSpriteFrameName);
    oluacls_func(L, "getCapInsets", _olua_fun_cocos2d_ui_Scale9Sprite_getCapInsets);
    oluacls_func(L, "getInsetBottom", _olua_fun_cocos2d_ui_Scale9Sprite_getInsetBottom);
    oluacls_func(L, "getInsetLeft", _olua_fun_cocos2d_ui_Scale9Sprite_getInsetLeft);
    oluacls_func(L, "getInsetRight", _olua_fun_cocos2d_ui_Scale9Sprite_getInsetRight);
    oluacls_func(L, "getInsetTop", _olua_fun_cocos2d_ui_Scale9Sprite_getInsetTop);
    oluacls_func(L, "getOriginalSize", _olua_fun_cocos2d_ui_Scale9Sprite_getOriginalSize);
    oluacls_func(L, "getPreferredSize", _olua_fun_cocos2d_ui_Scale9Sprite_getPreferredSize);
    oluacls_func(L, "getRenderingType", _olua_fun_cocos2d_ui_Scale9Sprite_getRenderingType);
    oluacls_func(L, "getSprite", _olua_fun_cocos2d_ui_Scale9Sprite_getSprite);
    oluacls_func(L, "getState", _olua_fun_cocos2d_ui_Scale9Sprite_getState);
    oluacls_func(L, "init", _olua_fun_cocos2d_ui_Scale9Sprite_init);
    oluacls_func(L, "initWithFile", _olua_fun_cocos2d_ui_Scale9Sprite_initWithFile);
    oluacls_func(L, "initWithSpriteFrame", _olua_fun_cocos2d_ui_Scale9Sprite_initWithSpriteFrame);
    oluacls_func(L, "initWithSpriteFrameName", _olua_fun_cocos2d_ui_Scale9Sprite_initWithSpriteFrameName);
    oluacls_func(L, "isScale9Enabled", _olua_fun_cocos2d_ui_Scale9Sprite_isScale9Enabled);
    oluacls_func(L, "new", _olua_fun_cocos2d_ui_Scale9Sprite_new);
    oluacls_func(L, "resetRender", _olua_fun_cocos2d_ui_Scale9Sprite_resetRender);
    oluacls_func(L, "resizableSpriteWithCapInsets", _olua_fun_cocos2d_ui_Scale9Sprite_resizableSpriteWithCapInsets);
    oluacls_func(L, "setCapInsets", _olua_fun_cocos2d_ui_Scale9Sprite_setCapInsets);
    oluacls_func(L, "setInsetBottom", _olua_fun_cocos2d_ui_Scale9Sprite_setInsetBottom);
    oluacls_func(L, "setInsetLeft", _olua_fun_cocos2d_ui_Scale9Sprite_setInsetLeft);
    oluacls_func(L, "setInsetRight", _olua_fun_cocos2d_ui_Scale9Sprite_setInsetRight);
    oluacls_func(L, "setInsetTop", _olua_fun_cocos2d_ui_Scale9Sprite_setInsetTop);
    oluacls_func(L, "setPreferredSize", _olua_fun_cocos2d_ui_Scale9Sprite_setPreferredSize);
    oluacls_func(L, "setRenderingType", _olua_fun_cocos2d_ui_Scale9Sprite_setRenderingType);
    oluacls_func(L, "setScale9Enabled", _olua_fun_cocos2d_ui_Scale9Sprite_setScale9Enabled);
    oluacls_func(L, "setSpriteFrame", _olua_fun_cocos2d_ui_Scale9Sprite_setSpriteFrame);
    oluacls_func(L, "setState", _olua_fun_cocos2d_ui_Scale9Sprite_setState);
    oluacls_func(L, "updateWithSprite", _olua_fun_cocos2d_ui_Scale9Sprite_updateWithSprite);
    oluacls_prop(L, "capInsets", _olua_fun_cocos2d_ui_Scale9Sprite_getCapInsets, _olua_fun_cocos2d_ui_Scale9Sprite_setCapInsets);
    oluacls_prop(L, "insetBottom", _olua_fun_cocos2d_ui_Scale9Sprite_getInsetBottom, _olua_fun_cocos2d_ui_Scale9Sprite_setInsetBottom);
    oluacls_prop(L, "insetLeft", _olua_fun_cocos2d_ui_Scale9Sprite_getInsetLeft, _olua_fun_cocos2d_ui_Scale9Sprite_setInsetLeft);
    oluacls_prop(L, "insetRight", _olua_fun_cocos2d_ui_Scale9Sprite_getInsetRight, _olua_fun_cocos2d_ui_Scale9Sprite_setInsetRight);
    oluacls_prop(L, "insetTop", _olua_fun_cocos2d_ui_Scale9Sprite_getInsetTop, _olua_fun_cocos2d_ui_Scale9Sprite_setInsetTop);
    oluacls_prop(L, "originalSize", _olua_fun_cocos2d_ui_Scale9Sprite_getOriginalSize, nullptr);
    oluacls_prop(L, "preferredSize", _olua_fun_cocos2d_ui_Scale9Sprite_getPreferredSize, _olua_fun_cocos2d_ui_Scale9Sprite_setPreferredSize);
    oluacls_prop(L, "renderingType", _olua_fun_cocos2d_ui_Scale9Sprite_getRenderingType, _olua_fun_cocos2d_ui_Scale9Sprite_setRenderingType);
    oluacls_prop(L, "scale9Enabled", _olua_fun_cocos2d_ui_Scale9Sprite_isScale9Enabled, _olua_fun_cocos2d_ui_Scale9Sprite_setScale9Enabled);
    oluacls_prop(L, "sprite", _olua_fun_cocos2d_ui_Scale9Sprite_getSprite, nullptr);
    oluacls_prop(L, "state", _olua_fun_cocos2d_ui_Scale9Sprite_getState, _olua_fun_cocos2d_ui_Scale9Sprite_setState);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_Scale9Sprite(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.Scale9Sprite")) {
        luaL_error(L, "class not found: cocos2d::ui::Scale9Sprite");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_ccui_LayoutComponent_HorizontalEdge(lua_State *L)
{
    oluacls_class<cocos2d::ui::LayoutComponent::HorizontalEdge>(L, "ccui.LayoutComponent.HorizontalEdge");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "Center", (lua_Integer)cocos2d::ui::LayoutComponent::HorizontalEdge::Center);
    oluacls_enum(L, "Left", (lua_Integer)cocos2d::ui::LayoutComponent::HorizontalEdge::Left);
    oluacls_enum(L, "None", (lua_Integer)cocos2d::ui::LayoutComponent::HorizontalEdge::None);
    oluacls_enum(L, "Right", (lua_Integer)cocos2d::ui::LayoutComponent::HorizontalEdge::Right);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_LayoutComponent_HorizontalEdge(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.LayoutComponent.HorizontalEdge")) {
        luaL_error(L, "class not found: cocos2d::ui::LayoutComponent::HorizontalEdge");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_ccui_LayoutComponent_VerticalEdge(lua_State *L)
{
    oluacls_class<cocos2d::ui::LayoutComponent::VerticalEdge>(L, "ccui.LayoutComponent.VerticalEdge");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "Bottom", (lua_Integer)cocos2d::ui::LayoutComponent::VerticalEdge::Bottom);
    oluacls_enum(L, "Center", (lua_Integer)cocos2d::ui::LayoutComponent::VerticalEdge::Center);
    oluacls_enum(L, "None", (lua_Integer)cocos2d::ui::LayoutComponent::VerticalEdge::None);
    oluacls_enum(L, "Top", (lua_Integer)cocos2d::ui::LayoutComponent::VerticalEdge::Top);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_LayoutComponent_VerticalEdge(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.LayoutComponent.VerticalEdge")) {
        luaL_error(L, "class not found: cocos2d::ui::LayoutComponent::VerticalEdge");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_ui_LayoutComponent_bindLayoutComponent(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Node *arg1 = nullptr;       /** node */

    olua_check_object(L, 1, &arg1, "cc.Node");

    // static cocos2d::ui::LayoutComponent *bindLayoutComponent(cocos2d::Node *node)
    cocos2d::ui::LayoutComponent *ret = cocos2d::ui::LayoutComponent::bindLayoutComponent(arg1);
    int num_ret = olua_push_object(L, ret, "ccui.LayoutComponent");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_LayoutComponent_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::ui::LayoutComponent *create()
    cocos2d::ui::LayoutComponent *ret = cocos2d::ui::LayoutComponent::create();
    int num_ret = olua_push_object(L, ret, "ccui.LayoutComponent");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_LayoutComponent_getAnchorPosition(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.LayoutComponent");

    // const cocos2d::Point &getAnchorPosition()
    const cocos2d::Point &ret = self->getAnchorPosition();
    int num_ret = olua_push_object(L, ret, "cc.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_LayoutComponent_getBottomMargin(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.LayoutComponent");

    // float getBottomMargin()
    float ret = self->getBottomMargin();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_LayoutComponent_getHorizontalEdge(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.LayoutComponent");

    // cocos2d::ui::LayoutComponent::HorizontalEdge getHorizontalEdge()
    cocos2d::ui::LayoutComponent::HorizontalEdge ret = self->getHorizontalEdge();
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_LayoutComponent_getLeftMargin(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.LayoutComponent");

    // float getLeftMargin()
    float ret = self->getLeftMargin();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_LayoutComponent_getPercentContentSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.LayoutComponent");

    // cocos2d::Vec2 getPercentContentSize()
    cocos2d::Vec2 ret = self->getPercentContentSize();
    int num_ret = olua_copy_object(L, ret, "cc.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_LayoutComponent_getPercentHeight(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.LayoutComponent");

    // float getPercentHeight()
    float ret = self->getPercentHeight();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_LayoutComponent_getPercentWidth(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.LayoutComponent");

    // float getPercentWidth()
    float ret = self->getPercentWidth();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_LayoutComponent_getPosition(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.LayoutComponent");

    // const cocos2d::Point &getPosition()
    const cocos2d::Point &ret = self->getPosition();
    int num_ret = olua_push_object(L, ret, "cc.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_LayoutComponent_getPositionPercentX(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.LayoutComponent");

    // float getPositionPercentX()
    float ret = self->getPositionPercentX();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_LayoutComponent_getPositionPercentY(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.LayoutComponent");

    // float getPositionPercentY()
    float ret = self->getPositionPercentY();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_LayoutComponent_getRightMargin(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.LayoutComponent");

    // float getRightMargin()
    float ret = self->getRightMargin();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_LayoutComponent_getSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.LayoutComponent");

    // const cocos2d::Size &getSize()
    const cocos2d::Size &ret = self->getSize();
    int num_ret = olua_push_object(L, ret, "cc.Size");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_LayoutComponent_getSizeHeight(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.LayoutComponent");

    // float getSizeHeight()
    float ret = self->getSizeHeight();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_LayoutComponent_getSizeWidth(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.LayoutComponent");

    // float getSizeWidth()
    float ret = self->getSizeWidth();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_LayoutComponent_getTopMargin(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.LayoutComponent");

    // float getTopMargin()
    float ret = self->getTopMargin();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_LayoutComponent_getUsingPercentContentSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.LayoutComponent");

    // bool getUsingPercentContentSize()
    bool ret = self->getUsingPercentContentSize();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_LayoutComponent_getVerticalEdge(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.LayoutComponent");

    // cocos2d::ui::LayoutComponent::VerticalEdge getVerticalEdge()
    cocos2d::ui::LayoutComponent::VerticalEdge ret = self->getVerticalEdge();
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_LayoutComponent_isPercentHeightEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.LayoutComponent");

    // bool isPercentHeightEnabled()
    bool ret = self->isPercentHeightEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_LayoutComponent_isPercentWidthEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.LayoutComponent");

    // bool isPercentWidthEnabled()
    bool ret = self->isPercentWidthEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_LayoutComponent_isPositionPercentXEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.LayoutComponent");

    // bool isPositionPercentXEnabled()
    bool ret = self->isPositionPercentXEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_LayoutComponent_isPositionPercentYEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.LayoutComponent");

    // bool isPositionPercentYEnabled()
    bool ret = self->isPositionPercentYEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_LayoutComponent_isStretchHeightEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.LayoutComponent");

    // bool isStretchHeightEnabled()
    bool ret = self->isStretchHeightEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_LayoutComponent_isStretchWidthEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.LayoutComponent");

    // bool isStretchWidthEnabled()
    bool ret = self->isStretchWidthEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_LayoutComponent_new(lua_State *L)
{
    olua_startinvoke(L);

    // cocos2d::ui::LayoutComponent()
    cocos2d::ui::LayoutComponent *ret = new cocos2d::ui::LayoutComponent();
    int num_ret = olua_push_object(L, ret, "ccui.LayoutComponent");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_LayoutComponent_refreshLayout(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.LayoutComponent");

    // void refreshLayout()
    self->refreshLayout();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_LayoutComponent_setActiveEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;
    bool arg1 = false;       /** enable */

    olua_to_object(L, 1, &self, "ccui.LayoutComponent");
    olua_check_bool(L, 2, &arg1);

    // void setActiveEnabled(bool enable)
    self->setActiveEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_LayoutComponent_setAnchorPosition(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;
    cocos2d::Point *arg1;       /** point */

    olua_to_object(L, 1, &self, "ccui.LayoutComponent");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // void setAnchorPosition(const cocos2d::Point &point)
    self->setAnchorPosition(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_LayoutComponent_setBottomMargin(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;
    float arg1 = 0;       /** margin */

    olua_to_object(L, 1, &self, "ccui.LayoutComponent");
    olua_check_number(L, 2, &arg1);

    // void setBottomMargin(float margin)
    self->setBottomMargin(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_LayoutComponent_setHorizontalEdge(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;
    cocos2d::ui::LayoutComponent::HorizontalEdge arg1 = (cocos2d::ui::LayoutComponent::HorizontalEdge)0;       /** hEage */

    olua_to_object(L, 1, &self, "ccui.LayoutComponent");
    olua_check_enum(L, 2, &arg1);

    // void setHorizontalEdge(cocos2d::ui::LayoutComponent::HorizontalEdge hEage)
    self->setHorizontalEdge(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_LayoutComponent_setLeftMargin(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;
    float arg1 = 0;       /** margin */

    olua_to_object(L, 1, &self, "ccui.LayoutComponent");
    olua_check_number(L, 2, &arg1);

    // void setLeftMargin(float margin)
    self->setLeftMargin(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_LayoutComponent_setPercentContentSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;
    cocos2d::Vec2 *arg1;       /** percent */

    olua_to_object(L, 1, &self, "ccui.LayoutComponent");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // void setPercentContentSize(const cocos2d::Vec2 &percent)
    self->setPercentContentSize(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_LayoutComponent_setPercentHeight(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;
    float arg1 = 0;       /** percentHeight */

    olua_to_object(L, 1, &self, "ccui.LayoutComponent");
    olua_check_number(L, 2, &arg1);

    // void setPercentHeight(float percentHeight)
    self->setPercentHeight(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_LayoutComponent_setPercentHeightEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;
    bool arg1 = false;       /** isUsed */

    olua_to_object(L, 1, &self, "ccui.LayoutComponent");
    olua_check_bool(L, 2, &arg1);

    // void setPercentHeightEnabled(bool isUsed)
    self->setPercentHeightEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_LayoutComponent_setPercentOnlyEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;
    bool arg1 = false;       /** enable */

    olua_to_object(L, 1, &self, "ccui.LayoutComponent");
    olua_check_bool(L, 2, &arg1);

    // void setPercentOnlyEnabled(bool enable)
    self->setPercentOnlyEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_LayoutComponent_setPercentWidth(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;
    float arg1 = 0;       /** percentWidth */

    olua_to_object(L, 1, &self, "ccui.LayoutComponent");
    olua_check_number(L, 2, &arg1);

    // void setPercentWidth(float percentWidth)
    self->setPercentWidth(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_LayoutComponent_setPercentWidthEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;
    bool arg1 = false;       /** isUsed */

    olua_to_object(L, 1, &self, "ccui.LayoutComponent");
    olua_check_bool(L, 2, &arg1);

    // void setPercentWidthEnabled(bool isUsed)
    self->setPercentWidthEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_LayoutComponent_setPosition(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;
    cocos2d::Point *arg1;       /** position */

    olua_to_object(L, 1, &self, "ccui.LayoutComponent");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // void setPosition(const cocos2d::Point &position)
    self->setPosition(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_LayoutComponent_setPositionPercentX(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;
    float arg1 = 0;       /** percentMargin */

    olua_to_object(L, 1, &self, "ccui.LayoutComponent");
    olua_check_number(L, 2, &arg1);

    // void setPositionPercentX(float percentMargin)
    self->setPositionPercentX(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_LayoutComponent_setPositionPercentXEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;
    bool arg1 = false;       /** isUsed */

    olua_to_object(L, 1, &self, "ccui.LayoutComponent");
    olua_check_bool(L, 2, &arg1);

    // void setPositionPercentXEnabled(bool isUsed)
    self->setPositionPercentXEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_LayoutComponent_setPositionPercentY(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;
    float arg1 = 0;       /** percentMargin */

    olua_to_object(L, 1, &self, "ccui.LayoutComponent");
    olua_check_number(L, 2, &arg1);

    // void setPositionPercentY(float percentMargin)
    self->setPositionPercentY(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_LayoutComponent_setPositionPercentYEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;
    bool arg1 = false;       /** isUsed */

    olua_to_object(L, 1, &self, "ccui.LayoutComponent");
    olua_check_bool(L, 2, &arg1);

    // void setPositionPercentYEnabled(bool isUsed)
    self->setPositionPercentYEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_LayoutComponent_setRightMargin(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;
    float arg1 = 0;       /** margin */

    olua_to_object(L, 1, &self, "ccui.LayoutComponent");
    olua_check_number(L, 2, &arg1);

    // void setRightMargin(float margin)
    self->setRightMargin(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_LayoutComponent_setSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;
    cocos2d::Size *arg1;       /** size */

    olua_to_object(L, 1, &self, "ccui.LayoutComponent");
    olua_check_object(L, 2, &arg1, "cc.Size");

    // void setSize(const cocos2d::Size &size)
    self->setSize(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_LayoutComponent_setSizeHeight(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;
    float arg1 = 0;       /** height */

    olua_to_object(L, 1, &self, "ccui.LayoutComponent");
    olua_check_number(L, 2, &arg1);

    // void setSizeHeight(float height)
    self->setSizeHeight(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_LayoutComponent_setSizeWidth(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;
    float arg1 = 0;       /** width */

    olua_to_object(L, 1, &self, "ccui.LayoutComponent");
    olua_check_number(L, 2, &arg1);

    // void setSizeWidth(float width)
    self->setSizeWidth(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_LayoutComponent_setStretchHeightEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;
    bool arg1 = false;       /** isUsed */

    olua_to_object(L, 1, &self, "ccui.LayoutComponent");
    olua_check_bool(L, 2, &arg1);

    // void setStretchHeightEnabled(bool isUsed)
    self->setStretchHeightEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_LayoutComponent_setStretchWidthEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;
    bool arg1 = false;       /** isUsed */

    olua_to_object(L, 1, &self, "ccui.LayoutComponent");
    olua_check_bool(L, 2, &arg1);

    // void setStretchWidthEnabled(bool isUsed)
    self->setStretchWidthEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_LayoutComponent_setTopMargin(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;
    float arg1 = 0;       /** margin */

    olua_to_object(L, 1, &self, "ccui.LayoutComponent");
    olua_check_number(L, 2, &arg1);

    // void setTopMargin(float margin)
    self->setTopMargin(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_LayoutComponent_setUsingPercentContentSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;
    bool arg1 = false;       /** isUsed */

    olua_to_object(L, 1, &self, "ccui.LayoutComponent");
    olua_check_bool(L, 2, &arg1);

    // void setUsingPercentContentSize(bool isUsed)
    self->setUsingPercentContentSize(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_LayoutComponent_setVerticalEdge(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;
    cocos2d::ui::LayoutComponent::VerticalEdge arg1 = (cocos2d::ui::LayoutComponent::VerticalEdge)0;       /** vEage */

    olua_to_object(L, 1, &self, "ccui.LayoutComponent");
    olua_check_enum(L, 2, &arg1);

    // void setVerticalEdge(cocos2d::ui::LayoutComponent::VerticalEdge vEage)
    self->setVerticalEdge(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_cls_ccui_LayoutComponent(lua_State *L)
{
    oluacls_class<cocos2d::ui::LayoutComponent, cocos2d::Component>(L, "ccui.LayoutComponent");
    oluacls_func(L, "bindLayoutComponent", _olua_fun_cocos2d_ui_LayoutComponent_bindLayoutComponent);
    oluacls_func(L, "create", _olua_fun_cocos2d_ui_LayoutComponent_create);
    oluacls_func(L, "getAnchorPosition", _olua_fun_cocos2d_ui_LayoutComponent_getAnchorPosition);
    oluacls_func(L, "getBottomMargin", _olua_fun_cocos2d_ui_LayoutComponent_getBottomMargin);
    oluacls_func(L, "getHorizontalEdge", _olua_fun_cocos2d_ui_LayoutComponent_getHorizontalEdge);
    oluacls_func(L, "getLeftMargin", _olua_fun_cocos2d_ui_LayoutComponent_getLeftMargin);
    oluacls_func(L, "getPercentContentSize", _olua_fun_cocos2d_ui_LayoutComponent_getPercentContentSize);
    oluacls_func(L, "getPercentHeight", _olua_fun_cocos2d_ui_LayoutComponent_getPercentHeight);
    oluacls_func(L, "getPercentWidth", _olua_fun_cocos2d_ui_LayoutComponent_getPercentWidth);
    oluacls_func(L, "getPosition", _olua_fun_cocos2d_ui_LayoutComponent_getPosition);
    oluacls_func(L, "getPositionPercentX", _olua_fun_cocos2d_ui_LayoutComponent_getPositionPercentX);
    oluacls_func(L, "getPositionPercentY", _olua_fun_cocos2d_ui_LayoutComponent_getPositionPercentY);
    oluacls_func(L, "getRightMargin", _olua_fun_cocos2d_ui_LayoutComponent_getRightMargin);
    oluacls_func(L, "getSize", _olua_fun_cocos2d_ui_LayoutComponent_getSize);
    oluacls_func(L, "getSizeHeight", _olua_fun_cocos2d_ui_LayoutComponent_getSizeHeight);
    oluacls_func(L, "getSizeWidth", _olua_fun_cocos2d_ui_LayoutComponent_getSizeWidth);
    oluacls_func(L, "getTopMargin", _olua_fun_cocos2d_ui_LayoutComponent_getTopMargin);
    oluacls_func(L, "getUsingPercentContentSize", _olua_fun_cocos2d_ui_LayoutComponent_getUsingPercentContentSize);
    oluacls_func(L, "getVerticalEdge", _olua_fun_cocos2d_ui_LayoutComponent_getVerticalEdge);
    oluacls_func(L, "isPercentHeightEnabled", _olua_fun_cocos2d_ui_LayoutComponent_isPercentHeightEnabled);
    oluacls_func(L, "isPercentWidthEnabled", _olua_fun_cocos2d_ui_LayoutComponent_isPercentWidthEnabled);
    oluacls_func(L, "isPositionPercentXEnabled", _olua_fun_cocos2d_ui_LayoutComponent_isPositionPercentXEnabled);
    oluacls_func(L, "isPositionPercentYEnabled", _olua_fun_cocos2d_ui_LayoutComponent_isPositionPercentYEnabled);
    oluacls_func(L, "isStretchHeightEnabled", _olua_fun_cocos2d_ui_LayoutComponent_isStretchHeightEnabled);
    oluacls_func(L, "isStretchWidthEnabled", _olua_fun_cocos2d_ui_LayoutComponent_isStretchWidthEnabled);
    oluacls_func(L, "new", _olua_fun_cocos2d_ui_LayoutComponent_new);
    oluacls_func(L, "refreshLayout", _olua_fun_cocos2d_ui_LayoutComponent_refreshLayout);
    oluacls_func(L, "setActiveEnabled", _olua_fun_cocos2d_ui_LayoutComponent_setActiveEnabled);
    oluacls_func(L, "setAnchorPosition", _olua_fun_cocos2d_ui_LayoutComponent_setAnchorPosition);
    oluacls_func(L, "setBottomMargin", _olua_fun_cocos2d_ui_LayoutComponent_setBottomMargin);
    oluacls_func(L, "setHorizontalEdge", _olua_fun_cocos2d_ui_LayoutComponent_setHorizontalEdge);
    oluacls_func(L, "setLeftMargin", _olua_fun_cocos2d_ui_LayoutComponent_setLeftMargin);
    oluacls_func(L, "setPercentContentSize", _olua_fun_cocos2d_ui_LayoutComponent_setPercentContentSize);
    oluacls_func(L, "setPercentHeight", _olua_fun_cocos2d_ui_LayoutComponent_setPercentHeight);
    oluacls_func(L, "setPercentHeightEnabled", _olua_fun_cocos2d_ui_LayoutComponent_setPercentHeightEnabled);
    oluacls_func(L, "setPercentOnlyEnabled", _olua_fun_cocos2d_ui_LayoutComponent_setPercentOnlyEnabled);
    oluacls_func(L, "setPercentWidth", _olua_fun_cocos2d_ui_LayoutComponent_setPercentWidth);
    oluacls_func(L, "setPercentWidthEnabled", _olua_fun_cocos2d_ui_LayoutComponent_setPercentWidthEnabled);
    oluacls_func(L, "setPosition", _olua_fun_cocos2d_ui_LayoutComponent_setPosition);
    oluacls_func(L, "setPositionPercentX", _olua_fun_cocos2d_ui_LayoutComponent_setPositionPercentX);
    oluacls_func(L, "setPositionPercentXEnabled", _olua_fun_cocos2d_ui_LayoutComponent_setPositionPercentXEnabled);
    oluacls_func(L, "setPositionPercentY", _olua_fun_cocos2d_ui_LayoutComponent_setPositionPercentY);
    oluacls_func(L, "setPositionPercentYEnabled", _olua_fun_cocos2d_ui_LayoutComponent_setPositionPercentYEnabled);
    oluacls_func(L, "setRightMargin", _olua_fun_cocos2d_ui_LayoutComponent_setRightMargin);
    oluacls_func(L, "setSize", _olua_fun_cocos2d_ui_LayoutComponent_setSize);
    oluacls_func(L, "setSizeHeight", _olua_fun_cocos2d_ui_LayoutComponent_setSizeHeight);
    oluacls_func(L, "setSizeWidth", _olua_fun_cocos2d_ui_LayoutComponent_setSizeWidth);
    oluacls_func(L, "setStretchHeightEnabled", _olua_fun_cocos2d_ui_LayoutComponent_setStretchHeightEnabled);
    oluacls_func(L, "setStretchWidthEnabled", _olua_fun_cocos2d_ui_LayoutComponent_setStretchWidthEnabled);
    oluacls_func(L, "setTopMargin", _olua_fun_cocos2d_ui_LayoutComponent_setTopMargin);
    oluacls_func(L, "setUsingPercentContentSize", _olua_fun_cocos2d_ui_LayoutComponent_setUsingPercentContentSize);
    oluacls_func(L, "setVerticalEdge", _olua_fun_cocos2d_ui_LayoutComponent_setVerticalEdge);
    oluacls_prop(L, "anchorPosition", _olua_fun_cocos2d_ui_LayoutComponent_getAnchorPosition, _olua_fun_cocos2d_ui_LayoutComponent_setAnchorPosition);
    oluacls_prop(L, "bottomMargin", _olua_fun_cocos2d_ui_LayoutComponent_getBottomMargin, _olua_fun_cocos2d_ui_LayoutComponent_setBottomMargin);
    oluacls_prop(L, "horizontalEdge", _olua_fun_cocos2d_ui_LayoutComponent_getHorizontalEdge, _olua_fun_cocos2d_ui_LayoutComponent_setHorizontalEdge);
    oluacls_prop(L, "leftMargin", _olua_fun_cocos2d_ui_LayoutComponent_getLeftMargin, _olua_fun_cocos2d_ui_LayoutComponent_setLeftMargin);
    oluacls_prop(L, "percentContentSize", _olua_fun_cocos2d_ui_LayoutComponent_getPercentContentSize, _olua_fun_cocos2d_ui_LayoutComponent_setPercentContentSize);
    oluacls_prop(L, "percentHeight", _olua_fun_cocos2d_ui_LayoutComponent_getPercentHeight, _olua_fun_cocos2d_ui_LayoutComponent_setPercentHeight);
    oluacls_prop(L, "percentHeightEnabled", _olua_fun_cocos2d_ui_LayoutComponent_isPercentHeightEnabled, _olua_fun_cocos2d_ui_LayoutComponent_setPercentHeightEnabled);
    oluacls_prop(L, "percentWidth", _olua_fun_cocos2d_ui_LayoutComponent_getPercentWidth, _olua_fun_cocos2d_ui_LayoutComponent_setPercentWidth);
    oluacls_prop(L, "percentWidthEnabled", _olua_fun_cocos2d_ui_LayoutComponent_isPercentWidthEnabled, _olua_fun_cocos2d_ui_LayoutComponent_setPercentWidthEnabled);
    oluacls_prop(L, "position", _olua_fun_cocos2d_ui_LayoutComponent_getPosition, _olua_fun_cocos2d_ui_LayoutComponent_setPosition);
    oluacls_prop(L, "positionPercentX", _olua_fun_cocos2d_ui_LayoutComponent_getPositionPercentX, _olua_fun_cocos2d_ui_LayoutComponent_setPositionPercentX);
    oluacls_prop(L, "positionPercentXEnabled", _olua_fun_cocos2d_ui_LayoutComponent_isPositionPercentXEnabled, _olua_fun_cocos2d_ui_LayoutComponent_setPositionPercentXEnabled);
    oluacls_prop(L, "positionPercentY", _olua_fun_cocos2d_ui_LayoutComponent_getPositionPercentY, _olua_fun_cocos2d_ui_LayoutComponent_setPositionPercentY);
    oluacls_prop(L, "positionPercentYEnabled", _olua_fun_cocos2d_ui_LayoutComponent_isPositionPercentYEnabled, _olua_fun_cocos2d_ui_LayoutComponent_setPositionPercentYEnabled);
    oluacls_prop(L, "rightMargin", _olua_fun_cocos2d_ui_LayoutComponent_getRightMargin, _olua_fun_cocos2d_ui_LayoutComponent_setRightMargin);
    oluacls_prop(L, "size", _olua_fun_cocos2d_ui_LayoutComponent_getSize, _olua_fun_cocos2d_ui_LayoutComponent_setSize);
    oluacls_prop(L, "sizeHeight", _olua_fun_cocos2d_ui_LayoutComponent_getSizeHeight, _olua_fun_cocos2d_ui_LayoutComponent_setSizeHeight);
    oluacls_prop(L, "sizeWidth", _olua_fun_cocos2d_ui_LayoutComponent_getSizeWidth, _olua_fun_cocos2d_ui_LayoutComponent_setSizeWidth);
    oluacls_prop(L, "stretchHeightEnabled", _olua_fun_cocos2d_ui_LayoutComponent_isStretchHeightEnabled, _olua_fun_cocos2d_ui_LayoutComponent_setStretchHeightEnabled);
    oluacls_prop(L, "stretchWidthEnabled", _olua_fun_cocos2d_ui_LayoutComponent_isStretchWidthEnabled, _olua_fun_cocos2d_ui_LayoutComponent_setStretchWidthEnabled);
    oluacls_prop(L, "topMargin", _olua_fun_cocos2d_ui_LayoutComponent_getTopMargin, _olua_fun_cocos2d_ui_LayoutComponent_setTopMargin);
    oluacls_prop(L, "usingPercentContentSize", _olua_fun_cocos2d_ui_LayoutComponent_getUsingPercentContentSize, _olua_fun_cocos2d_ui_LayoutComponent_setUsingPercentContentSize);
    oluacls_prop(L, "verticalEdge", _olua_fun_cocos2d_ui_LayoutComponent_getVerticalEdge, _olua_fun_cocos2d_ui_LayoutComponent_setVerticalEdge);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_LayoutComponent(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.LayoutComponent")) {
        luaL_error(L, "class not found: cocos2d::ui::LayoutComponent");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_ccui_LayoutParameter_Type(lua_State *L)
{
    oluacls_class<cocos2d::ui::LayoutParameter::Type>(L, "ccui.LayoutParameter.Type");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "LINEAR", (lua_Integer)cocos2d::ui::LayoutParameter::Type::LINEAR);
    oluacls_enum(L, "NONE", (lua_Integer)cocos2d::ui::LayoutParameter::Type::NONE);
    oluacls_enum(L, "RELATIVE", (lua_Integer)cocos2d::ui::LayoutParameter::Type::RELATIVE);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_LayoutParameter_Type(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.LayoutParameter.Type")) {
        luaL_error(L, "class not found: cocos2d::ui::LayoutParameter::Type");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_ui_LayoutParameter_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutParameter *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.LayoutParameter");

    // cocos2d::ui::LayoutParameter *clone()
    cocos2d::ui::LayoutParameter *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "ccui.LayoutParameter");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_LayoutParameter_copyProperties(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutParameter *self = nullptr;
    cocos2d::ui::LayoutParameter *arg1 = nullptr;       /** model */

    olua_to_object(L, 1, &self, "ccui.LayoutParameter");
    olua_check_object(L, 2, &arg1, "ccui.LayoutParameter");

    // void copyProperties(cocos2d::ui::LayoutParameter *model)
    self->copyProperties(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_LayoutParameter_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::ui::LayoutParameter *create()
    cocos2d::ui::LayoutParameter *ret = cocos2d::ui::LayoutParameter::create();
    int num_ret = olua_push_object(L, ret, "ccui.LayoutParameter");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_LayoutParameter_createCloneInstance(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutParameter *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.LayoutParameter");

    // cocos2d::ui::LayoutParameter *createCloneInstance()
    cocos2d::ui::LayoutParameter *ret = self->createCloneInstance();
    int num_ret = olua_push_object(L, ret, "ccui.LayoutParameter");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_LayoutParameter_getLayoutType(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutParameter *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.LayoutParameter");

    // cocos2d::ui::LayoutParameter::Type getLayoutType()
    cocos2d::ui::LayoutParameter::Type ret = self->getLayoutType();
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_LayoutParameter_getMargin(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutParameter *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.LayoutParameter");

    // const cocos2d::ui::Margin &getMargin()
    const cocos2d::ui::Margin &ret = self->getMargin();
    int num_ret = olua_push_object(L, ret, "cc.ui.Margin");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_LayoutParameter_new(lua_State *L)
{
    olua_startinvoke(L);

    // cocos2d::ui::LayoutParameter()
    cocos2d::ui::LayoutParameter *ret = new cocos2d::ui::LayoutParameter();
    int num_ret = olua_push_object(L, ret, "ccui.LayoutParameter");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_LayoutParameter_setMargin(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutParameter *self = nullptr;
    cocos2d::ui::Margin *arg1;       /** margin */

    olua_to_object(L, 1, &self, "ccui.LayoutParameter");
    olua_check_object(L, 2, &arg1, "cc.ui.Margin");

    // void setMargin(const cocos2d::ui::Margin &margin)
    self->setMargin(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_cls_ccui_LayoutParameter(lua_State *L)
{
    oluacls_class<cocos2d::ui::LayoutParameter, cocos2d::Ref>(L, "ccui.LayoutParameter");
    oluacls_func(L, "clone", _olua_fun_cocos2d_ui_LayoutParameter_clone);
    oluacls_func(L, "copyProperties", _olua_fun_cocos2d_ui_LayoutParameter_copyProperties);
    oluacls_func(L, "create", _olua_fun_cocos2d_ui_LayoutParameter_create);
    oluacls_func(L, "createCloneInstance", _olua_fun_cocos2d_ui_LayoutParameter_createCloneInstance);
    oluacls_func(L, "getLayoutType", _olua_fun_cocos2d_ui_LayoutParameter_getLayoutType);
    oluacls_func(L, "getMargin", _olua_fun_cocos2d_ui_LayoutParameter_getMargin);
    oluacls_func(L, "new", _olua_fun_cocos2d_ui_LayoutParameter_new);
    oluacls_func(L, "setMargin", _olua_fun_cocos2d_ui_LayoutParameter_setMargin);
    oluacls_prop(L, "layoutType", _olua_fun_cocos2d_ui_LayoutParameter_getLayoutType, nullptr);
    oluacls_prop(L, "margin", _olua_fun_cocos2d_ui_LayoutParameter_getMargin, _olua_fun_cocos2d_ui_LayoutParameter_setMargin);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_LayoutParameter(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.LayoutParameter")) {
        luaL_error(L, "class not found: cocos2d::ui::LayoutParameter");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_ccui_LinearLayoutParameter_LinearGravity(lua_State *L)
{
    oluacls_class<cocos2d::ui::LinearLayoutParameter::LinearGravity>(L, "ccui.LinearLayoutParameter.LinearGravity");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "BOTTOM", (lua_Integer)cocos2d::ui::LinearLayoutParameter::LinearGravity::BOTTOM);
    oluacls_enum(L, "CENTER_HORIZONTAL", (lua_Integer)cocos2d::ui::LinearLayoutParameter::LinearGravity::CENTER_HORIZONTAL);
    oluacls_enum(L, "CENTER_VERTICAL", (lua_Integer)cocos2d::ui::LinearLayoutParameter::LinearGravity::CENTER_VERTICAL);
    oluacls_enum(L, "LEFT", (lua_Integer)cocos2d::ui::LinearLayoutParameter::LinearGravity::LEFT);
    oluacls_enum(L, "NONE", (lua_Integer)cocos2d::ui::LinearLayoutParameter::LinearGravity::NONE);
    oluacls_enum(L, "RIGHT", (lua_Integer)cocos2d::ui::LinearLayoutParameter::LinearGravity::RIGHT);
    oluacls_enum(L, "TOP", (lua_Integer)cocos2d::ui::LinearLayoutParameter::LinearGravity::TOP);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_LinearLayoutParameter_LinearGravity(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.LinearLayoutParameter.LinearGravity")) {
        luaL_error(L, "class not found: cocos2d::ui::LinearLayoutParameter::LinearGravity");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_ui_LinearLayoutParameter_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::ui::LinearLayoutParameter *create()
    cocos2d::ui::LinearLayoutParameter *ret = cocos2d::ui::LinearLayoutParameter::create();
    int num_ret = olua_push_object(L, ret, "ccui.LinearLayoutParameter");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_LinearLayoutParameter_getGravity(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LinearLayoutParameter *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.LinearLayoutParameter");

    // cocos2d::ui::LinearLayoutParameter::LinearGravity getGravity()
    cocos2d::ui::LinearLayoutParameter::LinearGravity ret = self->getGravity();
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_LinearLayoutParameter_new(lua_State *L)
{
    olua_startinvoke(L);

    // cocos2d::ui::LinearLayoutParameter()
    cocos2d::ui::LinearLayoutParameter *ret = new cocos2d::ui::LinearLayoutParameter();
    int num_ret = olua_push_object(L, ret, "ccui.LinearLayoutParameter");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_LinearLayoutParameter_setGravity(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LinearLayoutParameter *self = nullptr;
    cocos2d::ui::LinearLayoutParameter::LinearGravity arg1 = (cocos2d::ui::LinearLayoutParameter::LinearGravity)0;       /** gravity */

    olua_to_object(L, 1, &self, "ccui.LinearLayoutParameter");
    olua_check_enum(L, 2, &arg1);

    // void setGravity(cocos2d::ui::LinearLayoutParameter::LinearGravity gravity)
    self->setGravity(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_cls_ccui_LinearLayoutParameter(lua_State *L)
{
    oluacls_class<cocos2d::ui::LinearLayoutParameter, cocos2d::ui::LayoutParameter>(L, "ccui.LinearLayoutParameter");
    oluacls_func(L, "create", _olua_fun_cocos2d_ui_LinearLayoutParameter_create);
    oluacls_func(L, "getGravity", _olua_fun_cocos2d_ui_LinearLayoutParameter_getGravity);
    oluacls_func(L, "new", _olua_fun_cocos2d_ui_LinearLayoutParameter_new);
    oluacls_func(L, "setGravity", _olua_fun_cocos2d_ui_LinearLayoutParameter_setGravity);
    oluacls_prop(L, "gravity", _olua_fun_cocos2d_ui_LinearLayoutParameter_getGravity, _olua_fun_cocos2d_ui_LinearLayoutParameter_setGravity);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_LinearLayoutParameter(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.LinearLayoutParameter")) {
        luaL_error(L, "class not found: cocos2d::ui::LinearLayoutParameter");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_ccui_RelativeLayoutParameter_RelativeAlign(lua_State *L)
{
    oluacls_class<cocos2d::ui::RelativeLayoutParameter::RelativeAlign>(L, "ccui.RelativeLayoutParameter.RelativeAlign");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "CENTER_IN_PARENT", (lua_Integer)cocos2d::ui::RelativeLayoutParameter::RelativeAlign::CENTER_IN_PARENT);
    oluacls_enum(L, "LOCATION_ABOVE_CENTER", (lua_Integer)cocos2d::ui::RelativeLayoutParameter::RelativeAlign::LOCATION_ABOVE_CENTER);
    oluacls_enum(L, "LOCATION_ABOVE_LEFTALIGN", (lua_Integer)cocos2d::ui::RelativeLayoutParameter::RelativeAlign::LOCATION_ABOVE_LEFTALIGN);
    oluacls_enum(L, "LOCATION_ABOVE_RIGHTALIGN", (lua_Integer)cocos2d::ui::RelativeLayoutParameter::RelativeAlign::LOCATION_ABOVE_RIGHTALIGN);
    oluacls_enum(L, "LOCATION_BELOW_CENTER", (lua_Integer)cocos2d::ui::RelativeLayoutParameter::RelativeAlign::LOCATION_BELOW_CENTER);
    oluacls_enum(L, "LOCATION_BELOW_LEFTALIGN", (lua_Integer)cocos2d::ui::RelativeLayoutParameter::RelativeAlign::LOCATION_BELOW_LEFTALIGN);
    oluacls_enum(L, "LOCATION_BELOW_RIGHTALIGN", (lua_Integer)cocos2d::ui::RelativeLayoutParameter::RelativeAlign::LOCATION_BELOW_RIGHTALIGN);
    oluacls_enum(L, "LOCATION_LEFT_OF_BOTTOMALIGN", (lua_Integer)cocos2d::ui::RelativeLayoutParameter::RelativeAlign::LOCATION_LEFT_OF_BOTTOMALIGN);
    oluacls_enum(L, "LOCATION_LEFT_OF_CENTER", (lua_Integer)cocos2d::ui::RelativeLayoutParameter::RelativeAlign::LOCATION_LEFT_OF_CENTER);
    oluacls_enum(L, "LOCATION_LEFT_OF_TOPALIGN", (lua_Integer)cocos2d::ui::RelativeLayoutParameter::RelativeAlign::LOCATION_LEFT_OF_TOPALIGN);
    oluacls_enum(L, "LOCATION_RIGHT_OF_BOTTOMALIGN", (lua_Integer)cocos2d::ui::RelativeLayoutParameter::RelativeAlign::LOCATION_RIGHT_OF_BOTTOMALIGN);
    oluacls_enum(L, "LOCATION_RIGHT_OF_CENTER", (lua_Integer)cocos2d::ui::RelativeLayoutParameter::RelativeAlign::LOCATION_RIGHT_OF_CENTER);
    oluacls_enum(L, "LOCATION_RIGHT_OF_TOPALIGN", (lua_Integer)cocos2d::ui::RelativeLayoutParameter::RelativeAlign::LOCATION_RIGHT_OF_TOPALIGN);
    oluacls_enum(L, "NONE", (lua_Integer)cocos2d::ui::RelativeLayoutParameter::RelativeAlign::NONE);
    oluacls_enum(L, "PARENT_BOTTOM_CENTER_HORIZONTAL", (lua_Integer)cocos2d::ui::RelativeLayoutParameter::RelativeAlign::PARENT_BOTTOM_CENTER_HORIZONTAL);
    oluacls_enum(L, "PARENT_LEFT_BOTTOM", (lua_Integer)cocos2d::ui::RelativeLayoutParameter::RelativeAlign::PARENT_LEFT_BOTTOM);
    oluacls_enum(L, "PARENT_LEFT_CENTER_VERTICAL", (lua_Integer)cocos2d::ui::RelativeLayoutParameter::RelativeAlign::PARENT_LEFT_CENTER_VERTICAL);
    oluacls_enum(L, "PARENT_RIGHT_BOTTOM", (lua_Integer)cocos2d::ui::RelativeLayoutParameter::RelativeAlign::PARENT_RIGHT_BOTTOM);
    oluacls_enum(L, "PARENT_RIGHT_CENTER_VERTICAL", (lua_Integer)cocos2d::ui::RelativeLayoutParameter::RelativeAlign::PARENT_RIGHT_CENTER_VERTICAL);
    oluacls_enum(L, "PARENT_TOP_CENTER_HORIZONTAL", (lua_Integer)cocos2d::ui::RelativeLayoutParameter::RelativeAlign::PARENT_TOP_CENTER_HORIZONTAL);
    oluacls_enum(L, "PARENT_TOP_LEFT", (lua_Integer)cocos2d::ui::RelativeLayoutParameter::RelativeAlign::PARENT_TOP_LEFT);
    oluacls_enum(L, "PARENT_TOP_RIGHT", (lua_Integer)cocos2d::ui::RelativeLayoutParameter::RelativeAlign::PARENT_TOP_RIGHT);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_RelativeLayoutParameter_RelativeAlign(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.RelativeLayoutParameter.RelativeAlign")) {
        luaL_error(L, "class not found: cocos2d::ui::RelativeLayoutParameter::RelativeAlign");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_ui_RelativeLayoutParameter_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::ui::RelativeLayoutParameter *create()
    cocos2d::ui::RelativeLayoutParameter *ret = cocos2d::ui::RelativeLayoutParameter::create();
    int num_ret = olua_push_object(L, ret, "ccui.RelativeLayoutParameter");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_RelativeLayoutParameter_getAlign(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RelativeLayoutParameter *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.RelativeLayoutParameter");

    // cocos2d::ui::RelativeLayoutParameter::RelativeAlign getAlign()
    cocos2d::ui::RelativeLayoutParameter::RelativeAlign ret = self->getAlign();
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_RelativeLayoutParameter_getRelativeName(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RelativeLayoutParameter *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.RelativeLayoutParameter");

    // const std::string &getRelativeName()
    const std::string &ret = self->getRelativeName();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_RelativeLayoutParameter_getRelativeToWidgetName(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RelativeLayoutParameter *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.RelativeLayoutParameter");

    // const std::string &getRelativeToWidgetName()
    const std::string &ret = self->getRelativeToWidgetName();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_RelativeLayoutParameter_new(lua_State *L)
{
    olua_startinvoke(L);

    // cocos2d::ui::RelativeLayoutParameter()
    cocos2d::ui::RelativeLayoutParameter *ret = new cocos2d::ui::RelativeLayoutParameter();
    int num_ret = olua_push_object(L, ret, "ccui.RelativeLayoutParameter");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_RelativeLayoutParameter_setAlign(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RelativeLayoutParameter *self = nullptr;
    cocos2d::ui::RelativeLayoutParameter::RelativeAlign arg1 = (cocos2d::ui::RelativeLayoutParameter::RelativeAlign)0;       /** align */

    olua_to_object(L, 1, &self, "ccui.RelativeLayoutParameter");
    olua_check_enum(L, 2, &arg1);

    // void setAlign(cocos2d::ui::RelativeLayoutParameter::RelativeAlign align)
    self->setAlign(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_RelativeLayoutParameter_setRelativeName(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RelativeLayoutParameter *self = nullptr;
    std::string arg1;       /** name */

    olua_to_object(L, 1, &self, "ccui.RelativeLayoutParameter");
    olua_check_string(L, 2, &arg1);

    // void setRelativeName(const std::string &name)
    self->setRelativeName(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_RelativeLayoutParameter_setRelativeToWidgetName(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RelativeLayoutParameter *self = nullptr;
    std::string arg1;       /** name */

    olua_to_object(L, 1, &self, "ccui.RelativeLayoutParameter");
    olua_check_string(L, 2, &arg1);

    // void setRelativeToWidgetName(const std::string &name)
    self->setRelativeToWidgetName(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_cls_ccui_RelativeLayoutParameter(lua_State *L)
{
    oluacls_class<cocos2d::ui::RelativeLayoutParameter, cocos2d::ui::LayoutParameter>(L, "ccui.RelativeLayoutParameter");
    oluacls_func(L, "create", _olua_fun_cocos2d_ui_RelativeLayoutParameter_create);
    oluacls_func(L, "getAlign", _olua_fun_cocos2d_ui_RelativeLayoutParameter_getAlign);
    oluacls_func(L, "getRelativeName", _olua_fun_cocos2d_ui_RelativeLayoutParameter_getRelativeName);
    oluacls_func(L, "getRelativeToWidgetName", _olua_fun_cocos2d_ui_RelativeLayoutParameter_getRelativeToWidgetName);
    oluacls_func(L, "new", _olua_fun_cocos2d_ui_RelativeLayoutParameter_new);
    oluacls_func(L, "setAlign", _olua_fun_cocos2d_ui_RelativeLayoutParameter_setAlign);
    oluacls_func(L, "setRelativeName", _olua_fun_cocos2d_ui_RelativeLayoutParameter_setRelativeName);
    oluacls_func(L, "setRelativeToWidgetName", _olua_fun_cocos2d_ui_RelativeLayoutParameter_setRelativeToWidgetName);
    oluacls_prop(L, "align", _olua_fun_cocos2d_ui_RelativeLayoutParameter_getAlign, _olua_fun_cocos2d_ui_RelativeLayoutParameter_setAlign);
    oluacls_prop(L, "relativeName", _olua_fun_cocos2d_ui_RelativeLayoutParameter_getRelativeName, _olua_fun_cocos2d_ui_RelativeLayoutParameter_setRelativeName);
    oluacls_prop(L, "relativeToWidgetName", _olua_fun_cocos2d_ui_RelativeLayoutParameter_getRelativeToWidgetName, _olua_fun_cocos2d_ui_RelativeLayoutParameter_setRelativeToWidgetName);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_RelativeLayoutParameter(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.RelativeLayoutParameter")) {
        luaL_error(L, "class not found: cocos2d::ui::RelativeLayoutParameter");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_ccui_Layout_Type(lua_State *L)
{
    oluacls_class<cocos2d::ui::Layout::Type>(L, "ccui.Layout.Type");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "ABSOLUTE", (lua_Integer)cocos2d::ui::Layout::Type::ABSOLUTE);
    oluacls_enum(L, "HORIZONTAL", (lua_Integer)cocos2d::ui::Layout::Type::HORIZONTAL);
    oluacls_enum(L, "RELATIVE", (lua_Integer)cocos2d::ui::Layout::Type::RELATIVE);
    oluacls_enum(L, "VERTICAL", (lua_Integer)cocos2d::ui::Layout::Type::VERTICAL);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_Layout_Type(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.Layout.Type")) {
        luaL_error(L, "class not found: cocos2d::ui::Layout::Type");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_ccui_Layout_ClippingType(lua_State *L)
{
    oluacls_class<cocos2d::ui::Layout::ClippingType>(L, "ccui.Layout.ClippingType");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "SCISSOR", (lua_Integer)cocos2d::ui::Layout::ClippingType::SCISSOR);
    oluacls_enum(L, "STENCIL", (lua_Integer)cocos2d::ui::Layout::ClippingType::STENCIL);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_Layout_ClippingType(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.Layout.ClippingType")) {
        luaL_error(L, "class not found: cocos2d::ui::Layout::ClippingType");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_ccui_Layout_BackGroundColorType(lua_State *L)
{
    oluacls_class<cocos2d::ui::Layout::BackGroundColorType>(L, "ccui.Layout.BackGroundColorType");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "GRADIENT", (lua_Integer)cocos2d::ui::Layout::BackGroundColorType::GRADIENT);
    oluacls_enum(L, "NONE", (lua_Integer)cocos2d::ui::Layout::BackGroundColorType::NONE);
    oluacls_enum(L, "SOLID", (lua_Integer)cocos2d::ui::Layout::BackGroundColorType::SOLID);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_Layout_BackGroundColorType(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.Layout.BackGroundColorType")) {
        luaL_error(L, "class not found: cocos2d::ui::Layout::BackGroundColorType");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_ui_Layout_as(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Layout *self = nullptr;
    const char *arg1 = nullptr;       /** cls */

    olua_to_object(L, 1, &self, "ccui.Layout");
    olua_check_string(L, 2, &arg1);

    do {
        if (olua_isa(L, 1, arg1)) {
            lua_pushvalue(L, 1);
            break;
        }
        if (olua_strequal(arg1, "ccui.LayoutParameterProtocol")) {
            olua_pushobj_as<cocos2d::ui::LayoutParameterProtocol>(L, 1, self, "as.ccui.LayoutParameterProtocol");
            break;
        }
        if (olua_strequal(arg1, "ccui.LayoutProtocol")) {
            olua_pushobj_as<cocos2d::ui::LayoutProtocol>(L, 1, self, "as.ccui.LayoutProtocol");
            break;
        }

        luaL_error(L, "'cocos2d::ui::Layout' can't cast to '%s'", arg1);
    } while (0);

    olua_endinvoke(L);

    return 1;
}

static int _olua_fun_cocos2d_ui_Layout_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::ui::Layout *create()
    cocos2d::ui::Layout *ret = cocos2d::ui::Layout::create();
    int num_ret = olua_push_object(L, ret, "ccui.Layout");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Layout_createInstance(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::Ref *createInstance()
    cocos2d::Ref *ret = cocos2d::ui::Layout::createInstance();
    int num_ret = olua_push_object(L, ret, "cc.Ref");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Layout_forceDoLayout(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Layout *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Layout");

    // void forceDoLayout()
    self->forceDoLayout();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Layout_getBackGroundColor(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Layout *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Layout");

    // const cocos2d::Color3B &getBackGroundColor()
    const cocos2d::Color3B &ret = self->getBackGroundColor();
    int num_ret = olua_push_cocos2d_Color3B(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Layout_getBackGroundColorOpacity(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Layout *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Layout");

    // uint8_t getBackGroundColorOpacity()
    uint8_t ret = self->getBackGroundColorOpacity();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Layout_getBackGroundColorType(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Layout *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Layout");

    // cocos2d::ui::Layout::BackGroundColorType getBackGroundColorType()
    cocos2d::ui::Layout::BackGroundColorType ret = self->getBackGroundColorType();
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Layout_getBackGroundColorVector(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Layout *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Layout");

    // const cocos2d::Vec2 &getBackGroundColorVector()
    const cocos2d::Vec2 &ret = self->getBackGroundColorVector();
    int num_ret = olua_push_object(L, ret, "cc.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Layout_getBackGroundEndColor(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Layout *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Layout");

    // const cocos2d::Color3B &getBackGroundEndColor()
    const cocos2d::Color3B &ret = self->getBackGroundEndColor();
    int num_ret = olua_push_cocos2d_Color3B(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Layout_getBackGroundImageCapInsets(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Layout *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Layout");

    // const cocos2d::Rect &getBackGroundImageCapInsets()
    const cocos2d::Rect &ret = self->getBackGroundImageCapInsets();
    int num_ret = olua_push_object(L, ret, "cc.Rect");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Layout_getBackGroundImageColor(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Layout *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Layout");

    // const cocos2d::Color3B &getBackGroundImageColor()
    const cocos2d::Color3B &ret = self->getBackGroundImageColor();
    int num_ret = olua_push_cocos2d_Color3B(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Layout_getBackGroundImageOpacity(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Layout *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Layout");

    // uint8_t getBackGroundImageOpacity()
    uint8_t ret = self->getBackGroundImageOpacity();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Layout_getBackGroundImageTextureSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Layout *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Layout");

    // const cocos2d::Size &getBackGroundImageTextureSize()
    const cocos2d::Size &ret = self->getBackGroundImageTextureSize();
    int num_ret = olua_push_object(L, ret, "cc.Size");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Layout_getBackGroundStartColor(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Layout *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Layout");

    // const cocos2d::Color3B &getBackGroundStartColor()
    const cocos2d::Color3B &ret = self->getBackGroundStartColor();
    int num_ret = olua_push_cocos2d_Color3B(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Layout_getClippingType(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Layout *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Layout");

    // cocos2d::ui::Layout::ClippingType getClippingType()
    cocos2d::ui::Layout::ClippingType ret = self->getClippingType();
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Layout_getLayoutType(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Layout *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Layout");

    // cocos2d::ui::Layout::Type getLayoutType()
    cocos2d::ui::Layout::Type ret = self->getLayoutType();
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Layout_getRenderFile(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Layout *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Layout");

    // cocos2d::ResourceData getRenderFile()
    cocos2d::ResourceData ret = self->getRenderFile();
    int num_ret = olua_copy_object(L, ret, "cc.ResourceData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Layout_isBackGroundImageScale9Enabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Layout *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Layout");

    // bool isBackGroundImageScale9Enabled()
    bool ret = self->isBackGroundImageScale9Enabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Layout_isClippingEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Layout *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Layout");

    // bool isClippingEnabled()
    bool ret = self->isClippingEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Layout_isLoopFocus(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Layout *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Layout");

    // bool isLoopFocus()
    bool ret = self->isLoopFocus();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Layout_isPassFocusToChild(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Layout *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Layout");

    // bool isPassFocusToChild()
    bool ret = self->isPassFocusToChild();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Layout_new(lua_State *L)
{
    olua_startinvoke(L);

    // cocos2d::ui::Layout()
    cocos2d::ui::Layout *ret = new cocos2d::ui::Layout();
    int num_ret = olua_push_object(L, ret, "ccui.Layout");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Layout_onPassFocusToChild$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Layout *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Layout");

    void *cb_store = (void *)self;
    std::string cb_tag = "onPassFocusToChild";
    olua_getcallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_EQUAL);

    // std::function<int (cocos2d::ui::Widget::FocusDirection, cocos2d::ui::Widget *)> onPassFocusToChild
    std::function<int (cocos2d::ui::Widget::FocusDirection, cocos2d::ui::Widget *)> ret = self->onPassFocusToChild;
    int num_ret = olua_push_callback(L, &ret, "std.function");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Layout_onPassFocusToChild$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Layout *self = nullptr;
    std::function<int (cocos2d::ui::Widget::FocusDirection, cocos2d::ui::Widget *)> arg1;       /** onPassFocusToChild */

    olua_to_object(L, 1, &self, "ccui.Layout");
    if (!olua_isnoneornil(L, 2)) {
        olua_check_callback(L, 2, &arg1, "std.function");
    }

    void *cb_store = (void *)self;
    std::string cb_tag = "onPassFocusToChild";
    std::string cb_name;
    if (olua_isfunction(L, 2)) {
        cb_name = olua_setcallback(L, cb_store, 2, cb_tag.c_str(), OLUA_TAG_REPLACE);
        olua_Context cb_ctx = olua_context(L);
        // lua_State *ML = olua_mainthread(L);
        arg1 = [cb_store, cb_name, cb_ctx /*, ML */](cocos2d::ui::Widget::FocusDirection cb_arg1, cocos2d::ui::Widget *cb_arg2) {
            lua_State *L = olua_mainthread(NULL);
            olua_checkhostthread();
            int ret = 0;       /** ret */
            if (olua_contextequal(L, cb_ctx)) {
                int top = lua_gettop(L);
                size_t last = olua_push_objpool(L);
                olua_enable_objpool(L);
                olua_push_enum(L, cb_arg1);
                olua_push_object(L, cb_arg2, "ccui.Widget");
                olua_disable_objpool(L);

                olua_callback(L, cb_store, cb_name.c_str(), 2);

                if (olua_is_integer(L, -1)) {
                    olua_check_integer(L, -1, &ret);
                }

                //pop stack value
                olua_pop_objpool(L, last);
                lua_settop(L, top);
            }
            return ret;
        };
    } else {
        olua_removecallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_EQUAL);
        arg1 = nullptr;
    }

    // std::function<int (cocos2d::ui::Widget::FocusDirection, cocos2d::ui::Widget *)> onPassFocusToChild
    self->onPassFocusToChild = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Layout_onPassFocusToChild(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // std::function<int (cocos2d::ui::Widget::FocusDirection, cocos2d::ui::Widget *)> onPassFocusToChild
        return _olua_fun_cocos2d_ui_Layout_onPassFocusToChild$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccui.Layout")) && (olua_is_callback(L, 2, "std.function") || olua_isnil(L, 2))) {
            // std::function<int (cocos2d::ui::Widget::FocusDirection, cocos2d::ui::Widget *)> onPassFocusToChild
            return _olua_fun_cocos2d_ui_Layout_onPassFocusToChild$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::Layout::onPassFocusToChild' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_Layout_removeBackGroundImage(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Layout *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Layout");

    // void removeBackGroundImage()
    self->removeBackGroundImage();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Layout_requestDoLayout(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Layout *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Layout");

    // void requestDoLayout()
    self->requestDoLayout();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Layout_setBackGroundColor$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Layout *self = nullptr;
    cocos2d::Color3B arg1;       /** color */

    olua_to_object(L, 1, &self, "ccui.Layout");
    olua_check_cocos2d_Color3B(L, 2, &arg1);

    // void setBackGroundColor(const cocos2d::Color3B &color)
    self->setBackGroundColor(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Layout_setBackGroundColor$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Layout *self = nullptr;
    cocos2d::Color3B arg1;       /** startColor */
    cocos2d::Color3B arg2;       /** endColor */

    olua_to_object(L, 1, &self, "ccui.Layout");
    olua_check_cocos2d_Color3B(L, 2, &arg1);
    olua_check_cocos2d_Color3B(L, 3, &arg2);

    // void setBackGroundColor(const cocos2d::Color3B &startColor, const cocos2d::Color3B &endColor)
    self->setBackGroundColor(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Layout_setBackGroundColor(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccui.Layout")) && (olua_is_cocos2d_Color3B(L, 2))) {
            // void setBackGroundColor(const cocos2d::Color3B &color)
            return _olua_fun_cocos2d_ui_Layout_setBackGroundColor$1(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "ccui.Layout")) && (olua_is_cocos2d_Color3B(L, 2)) && (olua_is_cocos2d_Color3B(L, 3))) {
            // void setBackGroundColor(const cocos2d::Color3B &startColor, const cocos2d::Color3B &endColor)
            return _olua_fun_cocos2d_ui_Layout_setBackGroundColor$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::Layout::setBackGroundColor' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_Layout_setBackGroundColorOpacity(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Layout *self = nullptr;
    uint8_t arg1 = 0;       /** opacity */

    olua_to_object(L, 1, &self, "ccui.Layout");
    olua_check_integer(L, 2, &arg1);

    // void setBackGroundColorOpacity(uint8_t opacity)
    self->setBackGroundColorOpacity(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Layout_setBackGroundColorType(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Layout *self = nullptr;
    cocos2d::ui::Layout::BackGroundColorType arg1 = (cocos2d::ui::Layout::BackGroundColorType)0;       /** type */

    olua_to_object(L, 1, &self, "ccui.Layout");
    olua_check_enum(L, 2, &arg1);

    // void setBackGroundColorType(cocos2d::ui::Layout::BackGroundColorType type)
    self->setBackGroundColorType(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Layout_setBackGroundColorVector(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Layout *self = nullptr;
    cocos2d::Vec2 *arg1;       /** vector */

    olua_to_object(L, 1, &self, "ccui.Layout");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // void setBackGroundColorVector(const cocos2d::Vec2 &vector)
    self->setBackGroundColorVector(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Layout_setBackGroundImage$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Layout *self = nullptr;
    std::string arg1;       /** fileName */
    cocos2d::ui::Widget::TextureResType arg2 = (cocos2d::ui::Widget::TextureResType)0;       /** texType */

    olua_to_object(L, 1, &self, "ccui.Layout");
    olua_check_string(L, 2, &arg1);
    olua_check_enum(L, 3, &arg2);

    // void setBackGroundImage(const std::string &fileName, @optional cocos2d::ui::Widget::TextureResType texType)
    self->setBackGroundImage(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Layout_setBackGroundImage$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Layout *self = nullptr;
    std::string arg1;       /** fileName */

    olua_to_object(L, 1, &self, "ccui.Layout");
    olua_check_string(L, 2, &arg1);

    // void setBackGroundImage(const std::string &fileName)
    self->setBackGroundImage(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Layout_setBackGroundImage(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccui.Layout")) && (olua_is_string(L, 2))) {
            // void setBackGroundImage(const std::string &fileName)
            return _olua_fun_cocos2d_ui_Layout_setBackGroundImage$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "ccui.Layout")) && (olua_is_string(L, 2)) && (olua_is_enum(L, 3))) {
            // void setBackGroundImage(const std::string &fileName, @optional cocos2d::ui::Widget::TextureResType texType)
            return _olua_fun_cocos2d_ui_Layout_setBackGroundImage$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::Layout::setBackGroundImage' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_Layout_setBackGroundImageCapInsets(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Layout *self = nullptr;
    cocos2d::Rect *arg1;       /** capInsets */

    olua_to_object(L, 1, &self, "ccui.Layout");
    olua_check_object(L, 2, &arg1, "cc.Rect");

    // void setBackGroundImageCapInsets(const cocos2d::Rect &capInsets)
    self->setBackGroundImageCapInsets(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Layout_setBackGroundImageColor(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Layout *self = nullptr;
    cocos2d::Color3B arg1;       /** color */

    olua_to_object(L, 1, &self, "ccui.Layout");
    olua_check_cocos2d_Color3B(L, 2, &arg1);

    // void setBackGroundImageColor(const cocos2d::Color3B &color)
    self->setBackGroundImageColor(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Layout_setBackGroundImageOpacity(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Layout *self = nullptr;
    uint8_t arg1 = 0;       /** opacity */

    olua_to_object(L, 1, &self, "ccui.Layout");
    olua_check_integer(L, 2, &arg1);

    // void setBackGroundImageOpacity(uint8_t opacity)
    self->setBackGroundImageOpacity(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Layout_setBackGroundImageScale9Enabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Layout *self = nullptr;
    bool arg1 = false;       /** enabled */

    olua_to_object(L, 1, &self, "ccui.Layout");
    olua_check_bool(L, 2, &arg1);

    // void setBackGroundImageScale9Enabled(bool enabled)
    self->setBackGroundImageScale9Enabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Layout_setClippingEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Layout *self = nullptr;
    bool arg1 = false;       /** enabled */

    olua_to_object(L, 1, &self, "ccui.Layout");
    olua_check_bool(L, 2, &arg1);

    // void setClippingEnabled(bool enabled)
    self->setClippingEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Layout_setClippingType(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Layout *self = nullptr;
    cocos2d::ui::Layout::ClippingType arg1 = (cocos2d::ui::Layout::ClippingType)0;       /** type */

    olua_to_object(L, 1, &self, "ccui.Layout");
    olua_check_enum(L, 2, &arg1);

    // void setClippingType(cocos2d::ui::Layout::ClippingType type)
    self->setClippingType(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Layout_setLayoutType(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Layout *self = nullptr;
    cocos2d::ui::Layout::Type arg1 = (cocos2d::ui::Layout::Type)0;       /** type */

    olua_to_object(L, 1, &self, "ccui.Layout");
    olua_check_enum(L, 2, &arg1);

    // void setLayoutType(cocos2d::ui::Layout::Type type)
    self->setLayoutType(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Layout_setLoopFocus(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Layout *self = nullptr;
    bool arg1 = false;       /** loop */

    olua_to_object(L, 1, &self, "ccui.Layout");
    olua_check_bool(L, 2, &arg1);

    // void setLoopFocus(bool loop)
    self->setLoopFocus(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Layout_setPassFocusToChild(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Layout *self = nullptr;
    bool arg1 = false;       /** pass */

    olua_to_object(L, 1, &self, "ccui.Layout");
    olua_check_bool(L, 2, &arg1);

    // void setPassFocusToChild(bool pass)
    self->setPassFocusToChild(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_cls_ccui_Layout(lua_State *L)
{
    oluacls_class<cocos2d::ui::Layout, cocos2d::ui::Widget>(L, "ccui.Layout");
    oluacls_func(L, "as", _olua_fun_cocos2d_ui_Layout_as);
    oluacls_func(L, "create", _olua_fun_cocos2d_ui_Layout_create);
    oluacls_func(L, "createInstance", _olua_fun_cocos2d_ui_Layout_createInstance);
    oluacls_func(L, "forceDoLayout", _olua_fun_cocos2d_ui_Layout_forceDoLayout);
    oluacls_func(L, "getBackGroundColor", _olua_fun_cocos2d_ui_Layout_getBackGroundColor);
    oluacls_func(L, "getBackGroundColorOpacity", _olua_fun_cocos2d_ui_Layout_getBackGroundColorOpacity);
    oluacls_func(L, "getBackGroundColorType", _olua_fun_cocos2d_ui_Layout_getBackGroundColorType);
    oluacls_func(L, "getBackGroundColorVector", _olua_fun_cocos2d_ui_Layout_getBackGroundColorVector);
    oluacls_func(L, "getBackGroundEndColor", _olua_fun_cocos2d_ui_Layout_getBackGroundEndColor);
    oluacls_func(L, "getBackGroundImageCapInsets", _olua_fun_cocos2d_ui_Layout_getBackGroundImageCapInsets);
    oluacls_func(L, "getBackGroundImageColor", _olua_fun_cocos2d_ui_Layout_getBackGroundImageColor);
    oluacls_func(L, "getBackGroundImageOpacity", _olua_fun_cocos2d_ui_Layout_getBackGroundImageOpacity);
    oluacls_func(L, "getBackGroundImageTextureSize", _olua_fun_cocos2d_ui_Layout_getBackGroundImageTextureSize);
    oluacls_func(L, "getBackGroundStartColor", _olua_fun_cocos2d_ui_Layout_getBackGroundStartColor);
    oluacls_func(L, "getClippingType", _olua_fun_cocos2d_ui_Layout_getClippingType);
    oluacls_func(L, "getLayoutType", _olua_fun_cocos2d_ui_Layout_getLayoutType);
    oluacls_func(L, "getRenderFile", _olua_fun_cocos2d_ui_Layout_getRenderFile);
    oluacls_func(L, "isBackGroundImageScale9Enabled", _olua_fun_cocos2d_ui_Layout_isBackGroundImageScale9Enabled);
    oluacls_func(L, "isClippingEnabled", _olua_fun_cocos2d_ui_Layout_isClippingEnabled);
    oluacls_func(L, "isLoopFocus", _olua_fun_cocos2d_ui_Layout_isLoopFocus);
    oluacls_func(L, "isPassFocusToChild", _olua_fun_cocos2d_ui_Layout_isPassFocusToChild);
    oluacls_func(L, "new", _olua_fun_cocos2d_ui_Layout_new);
    oluacls_func(L, "removeBackGroundImage", _olua_fun_cocos2d_ui_Layout_removeBackGroundImage);
    oluacls_func(L, "requestDoLayout", _olua_fun_cocos2d_ui_Layout_requestDoLayout);
    oluacls_func(L, "setBackGroundColor", _olua_fun_cocos2d_ui_Layout_setBackGroundColor);
    oluacls_func(L, "setBackGroundColorOpacity", _olua_fun_cocos2d_ui_Layout_setBackGroundColorOpacity);
    oluacls_func(L, "setBackGroundColorType", _olua_fun_cocos2d_ui_Layout_setBackGroundColorType);
    oluacls_func(L, "setBackGroundColorVector", _olua_fun_cocos2d_ui_Layout_setBackGroundColorVector);
    oluacls_func(L, "setBackGroundImage", _olua_fun_cocos2d_ui_Layout_setBackGroundImage);
    oluacls_func(L, "setBackGroundImageCapInsets", _olua_fun_cocos2d_ui_Layout_setBackGroundImageCapInsets);
    oluacls_func(L, "setBackGroundImageColor", _olua_fun_cocos2d_ui_Layout_setBackGroundImageColor);
    oluacls_func(L, "setBackGroundImageOpacity", _olua_fun_cocos2d_ui_Layout_setBackGroundImageOpacity);
    oluacls_func(L, "setBackGroundImageScale9Enabled", _olua_fun_cocos2d_ui_Layout_setBackGroundImageScale9Enabled);
    oluacls_func(L, "setClippingEnabled", _olua_fun_cocos2d_ui_Layout_setClippingEnabled);
    oluacls_func(L, "setClippingType", _olua_fun_cocos2d_ui_Layout_setClippingType);
    oluacls_func(L, "setLayoutType", _olua_fun_cocos2d_ui_Layout_setLayoutType);
    oluacls_func(L, "setLoopFocus", _olua_fun_cocos2d_ui_Layout_setLoopFocus);
    oluacls_func(L, "setPassFocusToChild", _olua_fun_cocos2d_ui_Layout_setPassFocusToChild);
    oluacls_prop(L, "backGroundColor", _olua_fun_cocos2d_ui_Layout_getBackGroundColor, nullptr);
    oluacls_prop(L, "backGroundColorOpacity", _olua_fun_cocos2d_ui_Layout_getBackGroundColorOpacity, _olua_fun_cocos2d_ui_Layout_setBackGroundColorOpacity);
    oluacls_prop(L, "backGroundColorType", _olua_fun_cocos2d_ui_Layout_getBackGroundColorType, _olua_fun_cocos2d_ui_Layout_setBackGroundColorType);
    oluacls_prop(L, "backGroundColorVector", _olua_fun_cocos2d_ui_Layout_getBackGroundColorVector, _olua_fun_cocos2d_ui_Layout_setBackGroundColorVector);
    oluacls_prop(L, "backGroundEndColor", _olua_fun_cocos2d_ui_Layout_getBackGroundEndColor, nullptr);
    oluacls_prop(L, "backGroundImageCapInsets", _olua_fun_cocos2d_ui_Layout_getBackGroundImageCapInsets, _olua_fun_cocos2d_ui_Layout_setBackGroundImageCapInsets);
    oluacls_prop(L, "backGroundImageColor", _olua_fun_cocos2d_ui_Layout_getBackGroundImageColor, _olua_fun_cocos2d_ui_Layout_setBackGroundImageColor);
    oluacls_prop(L, "backGroundImageOpacity", _olua_fun_cocos2d_ui_Layout_getBackGroundImageOpacity, _olua_fun_cocos2d_ui_Layout_setBackGroundImageOpacity);
    oluacls_prop(L, "backGroundImageScale9Enabled", _olua_fun_cocos2d_ui_Layout_isBackGroundImageScale9Enabled, _olua_fun_cocos2d_ui_Layout_setBackGroundImageScale9Enabled);
    oluacls_prop(L, "backGroundImageTextureSize", _olua_fun_cocos2d_ui_Layout_getBackGroundImageTextureSize, nullptr);
    oluacls_prop(L, "backGroundStartColor", _olua_fun_cocos2d_ui_Layout_getBackGroundStartColor, nullptr);
    oluacls_prop(L, "clippingEnabled", _olua_fun_cocos2d_ui_Layout_isClippingEnabled, _olua_fun_cocos2d_ui_Layout_setClippingEnabled);
    oluacls_prop(L, "clippingType", _olua_fun_cocos2d_ui_Layout_getClippingType, _olua_fun_cocos2d_ui_Layout_setClippingType);
    oluacls_prop(L, "layoutType", _olua_fun_cocos2d_ui_Layout_getLayoutType, _olua_fun_cocos2d_ui_Layout_setLayoutType);
    oluacls_prop(L, "loopFocus", _olua_fun_cocos2d_ui_Layout_isLoopFocus, _olua_fun_cocos2d_ui_Layout_setLoopFocus);
    oluacls_prop(L, "passFocusToChild", _olua_fun_cocos2d_ui_Layout_isPassFocusToChild, _olua_fun_cocos2d_ui_Layout_setPassFocusToChild);
    oluacls_prop(L, "renderFile", _olua_fun_cocos2d_ui_Layout_getRenderFile, nullptr);
    oluacls_prop(L, "onPassFocusToChild", _olua_fun_cocos2d_ui_Layout_onPassFocusToChild, _olua_fun_cocos2d_ui_Layout_onPassFocusToChild);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_Layout(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.Layout")) {
        luaL_error(L, "class not found: cocos2d::ui::Layout");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_ui_HBox_create$1(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::ui::HBox *create()
    cocos2d::ui::HBox *ret = cocos2d::ui::HBox::create();
    int num_ret = olua_push_object(L, ret, "ccui.HBox");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_HBox_create$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size *arg1;       /** size */

    olua_check_object(L, 1, &arg1, "cc.Size");

    // static cocos2d::ui::HBox *create(const cocos2d::Size &size)
    cocos2d::ui::HBox *ret = cocos2d::ui::HBox::create(*arg1);
    int num_ret = olua_push_object(L, ret, "ccui.HBox");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_HBox_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // static cocos2d::ui::HBox *create()
        return _olua_fun_cocos2d_ui_HBox_create$1(L);
    }

    if (num_args == 1) {
        // if ((olua_is_object(L, 1, "cc.Size"))) {
            // static cocos2d::ui::HBox *create(const cocos2d::Size &size)
            return _olua_fun_cocos2d_ui_HBox_create$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::HBox::create' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_HBox_initWithSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::HBox *self = nullptr;
    cocos2d::Size *arg1;       /** size */

    olua_to_object(L, 1, &self, "ccui.HBox");
    olua_check_object(L, 2, &arg1, "cc.Size");

    // bool initWithSize(const cocos2d::Size &size)
    bool ret = self->initWithSize(*arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_HBox_new(lua_State *L)
{
    olua_startinvoke(L);

    // cocos2d::ui::HBox()
    cocos2d::ui::HBox *ret = new cocos2d::ui::HBox();
    int num_ret = olua_push_object(L, ret, "ccui.HBox");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_cls_ccui_HBox(lua_State *L)
{
    oluacls_class<cocos2d::ui::HBox, cocos2d::ui::Layout>(L, "ccui.HBox");
    oluacls_func(L, "create", _olua_fun_cocos2d_ui_HBox_create);
    oluacls_func(L, "initWithSize", _olua_fun_cocos2d_ui_HBox_initWithSize);
    oluacls_func(L, "new", _olua_fun_cocos2d_ui_HBox_new);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_HBox(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.HBox")) {
        luaL_error(L, "class not found: cocos2d::ui::HBox");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_ui_VBox_create$1(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::ui::VBox *create()
    cocos2d::ui::VBox *ret = cocos2d::ui::VBox::create();
    int num_ret = olua_push_object(L, ret, "ccui.VBox");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_VBox_create$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size *arg1;       /** size */

    olua_check_object(L, 1, &arg1, "cc.Size");

    // static cocos2d::ui::VBox *create(const cocos2d::Size &size)
    cocos2d::ui::VBox *ret = cocos2d::ui::VBox::create(*arg1);
    int num_ret = olua_push_object(L, ret, "ccui.VBox");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_VBox_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // static cocos2d::ui::VBox *create()
        return _olua_fun_cocos2d_ui_VBox_create$1(L);
    }

    if (num_args == 1) {
        // if ((olua_is_object(L, 1, "cc.Size"))) {
            // static cocos2d::ui::VBox *create(const cocos2d::Size &size)
            return _olua_fun_cocos2d_ui_VBox_create$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::VBox::create' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_VBox_initWithSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::VBox *self = nullptr;
    cocos2d::Size *arg1;       /** size */

    olua_to_object(L, 1, &self, "ccui.VBox");
    olua_check_object(L, 2, &arg1, "cc.Size");

    // bool initWithSize(const cocos2d::Size &size)
    bool ret = self->initWithSize(*arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_VBox_new(lua_State *L)
{
    olua_startinvoke(L);

    // cocos2d::ui::VBox()
    cocos2d::ui::VBox *ret = new cocos2d::ui::VBox();
    int num_ret = olua_push_object(L, ret, "ccui.VBox");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_cls_ccui_VBox(lua_State *L)
{
    oluacls_class<cocos2d::ui::VBox, cocos2d::ui::Layout>(L, "ccui.VBox");
    oluacls_func(L, "create", _olua_fun_cocos2d_ui_VBox_create);
    oluacls_func(L, "initWithSize", _olua_fun_cocos2d_ui_VBox_initWithSize);
    oluacls_func(L, "new", _olua_fun_cocos2d_ui_VBox_new);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_VBox(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.VBox")) {
        luaL_error(L, "class not found: cocos2d::ui::VBox");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_ui_RelativeBox_create$1(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::ui::RelativeBox *create()
    cocos2d::ui::RelativeBox *ret = cocos2d::ui::RelativeBox::create();
    int num_ret = olua_push_object(L, ret, "ccui.RelativeBox");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_RelativeBox_create$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size *arg1;       /** size */

    olua_check_object(L, 1, &arg1, "cc.Size");

    // static cocos2d::ui::RelativeBox *create(const cocos2d::Size &size)
    cocos2d::ui::RelativeBox *ret = cocos2d::ui::RelativeBox::create(*arg1);
    int num_ret = olua_push_object(L, ret, "ccui.RelativeBox");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_RelativeBox_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // static cocos2d::ui::RelativeBox *create()
        return _olua_fun_cocos2d_ui_RelativeBox_create$1(L);
    }

    if (num_args == 1) {
        // if ((olua_is_object(L, 1, "cc.Size"))) {
            // static cocos2d::ui::RelativeBox *create(const cocos2d::Size &size)
            return _olua_fun_cocos2d_ui_RelativeBox_create$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::RelativeBox::create' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_RelativeBox_initWithSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RelativeBox *self = nullptr;
    cocos2d::Size *arg1;       /** size */

    olua_to_object(L, 1, &self, "ccui.RelativeBox");
    olua_check_object(L, 2, &arg1, "cc.Size");

    // bool initWithSize(const cocos2d::Size &size)
    bool ret = self->initWithSize(*arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_RelativeBox_new(lua_State *L)
{
    olua_startinvoke(L);

    // cocos2d::ui::RelativeBox()
    cocos2d::ui::RelativeBox *ret = new cocos2d::ui::RelativeBox();
    int num_ret = olua_push_object(L, ret, "ccui.RelativeBox");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_cls_ccui_RelativeBox(lua_State *L)
{
    oluacls_class<cocos2d::ui::RelativeBox, cocos2d::ui::Layout>(L, "ccui.RelativeBox");
    oluacls_func(L, "create", _olua_fun_cocos2d_ui_RelativeBox_create);
    oluacls_func(L, "initWithSize", _olua_fun_cocos2d_ui_RelativeBox_initWithSize);
    oluacls_func(L, "new", _olua_fun_cocos2d_ui_RelativeBox_new);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_RelativeBox(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.RelativeBox")) {
        luaL_error(L, "class not found: cocos2d::ui::RelativeBox");
    }
    return 1;
}
OLUA_END_DECLS

#if defined(CCLUA_OS_IOS) || defined(CCLUA_OS_ANDROID)
static int _olua_fun_cocos2d_ui_WebView_ccWebViewCallback___call(lua_State *L)
{
    olua_startinvoke(L);

    luaL_checktype(L, -1, LUA_TFUNCTION);
    olua_push_callback(L, (cocos2d::ui::WebView::ccWebViewCallback *)nullptr, "ccui.WebView.ccWebViewCallback");

    olua_endinvoke(L);

    return 1;
}

static int _olua_cls_ccui_WebView_ccWebViewCallback(lua_State *L)
{
    oluacls_class<cocos2d::ui::WebView::ccWebViewCallback>(L, "ccui.WebView.ccWebViewCallback");
    oluacls_func(L, "__call", _olua_fun_cocos2d_ui_WebView_ccWebViewCallback___call);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_WebView_ccWebViewCallback(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.WebView.ccWebViewCallback")) {
        luaL_error(L, "class not found: cocos2d::ui::WebView::ccWebViewCallback");
    }
    return 1;
}
OLUA_END_DECLS
#endif

#if defined(CCLUA_OS_IOS) || defined(CCLUA_OS_ANDROID)
static int _olua_fun_cocos2d_ui_WebView_canGoBack(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::WebView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.WebView");

    // bool canGoBack()
    bool ret = self->canGoBack();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_WebView_canGoForward(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::WebView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.WebView");

    // bool canGoForward()
    bool ret = self->canGoForward();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_WebView_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::ui::WebView *create()
    cocos2d::ui::WebView *ret = cocos2d::ui::WebView::create();
    int num_ret = olua_push_object(L, ret, "ccui.WebView");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_WebView_evaluateJS(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::WebView *self = nullptr;
    std::string arg1;       /** js */

    olua_to_object(L, 1, &self, "ccui.WebView");
    olua_check_string(L, 2, &arg1);

    // void evaluateJS(const std::string &js)
    self->evaluateJS(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_WebView_getOnDidFailLoading(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::WebView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.WebView");

    void *cb_store = (void *)self;
    std::string cb_tag = "OnDidFailLoading";
    olua_getcallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_EQUAL);

    // cocos2d::ui::WebView::ccWebViewCallback getOnDidFailLoading()
    cocos2d::ui::WebView::ccWebViewCallback ret = self->getOnDidFailLoading();
    int num_ret = olua_push_callback(L, &ret, "ccui.WebView.ccWebViewCallback");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_WebView_getOnDidFinishLoading(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::WebView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.WebView");

    void *cb_store = (void *)self;
    std::string cb_tag = "OnDidFinishLoading";
    olua_getcallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_EQUAL);

    // cocos2d::ui::WebView::ccWebViewCallback getOnDidFinishLoading()
    cocos2d::ui::WebView::ccWebViewCallback ret = self->getOnDidFinishLoading();
    int num_ret = olua_push_callback(L, &ret, "ccui.WebView.ccWebViewCallback");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_WebView_getOnJSCallback(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::WebView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.WebView");

    void *cb_store = (void *)self;
    std::string cb_tag = "OnJSCallback";
    olua_getcallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_EQUAL);

    // cocos2d::ui::WebView::ccWebViewCallback getOnJSCallback()
    cocos2d::ui::WebView::ccWebViewCallback ret = self->getOnJSCallback();
    int num_ret = olua_push_callback(L, &ret, "ccui.WebView.ccWebViewCallback");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_WebView_getOnShouldStartLoading(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::WebView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.WebView");

    void *cb_store = (void *)self;
    std::string cb_tag = "OnShouldStartLoading";
    olua_getcallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_EQUAL);

    // std::function<bool (cocos2d::ui::WebView *, const std::string &)> getOnShouldStartLoading()
    std::function<bool (cocos2d::ui::WebView *, const std::string &)> ret = self->getOnShouldStartLoading();
    int num_ret = olua_push_callback(L, &ret, "std.function");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_WebView_getOpacityWebView(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::WebView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.WebView");

    // float getOpacityWebView()
    float ret = self->getOpacityWebView();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_WebView_goBack(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::WebView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.WebView");

    // void goBack()
    self->goBack();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_WebView_goForward(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::WebView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.WebView");

    // void goForward()
    self->goForward();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_WebView_loadData(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::WebView *self = nullptr;
    cocos2d::Data arg1;       /** data */
    std::string arg2;       /** MIMEType */
    std::string arg3;       /** encoding */
    std::string arg4;       /** baseURL */

    olua_to_object(L, 1, &self, "ccui.WebView");
    olua_check_cocos2d_Data(L, 2, &arg1);
    olua_check_string(L, 3, &arg2);
    olua_check_string(L, 4, &arg3);
    olua_check_string(L, 5, &arg4);

    // void loadData(const cocos2d::Data &data, const std::string &MIMEType, const std::string &encoding, const std::string &baseURL)
    self->loadData(arg1, arg2, arg3, arg4);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_WebView_loadFile(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::WebView *self = nullptr;
    std::string arg1;       /** fileName */

    olua_to_object(L, 1, &self, "ccui.WebView");
    olua_check_string(L, 2, &arg1);

    // void loadFile(const std::string &fileName)
    self->loadFile(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_WebView_loadHTMLString$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::WebView *self = nullptr;
    std::string arg1;       /** string */
    std::string arg2;       /** baseURL */

    olua_to_object(L, 1, &self, "ccui.WebView");
    olua_check_string(L, 2, &arg1);
    olua_check_string(L, 3, &arg2);

    // void loadHTMLString(const std::string &string, @optional const std::string &baseURL)
    self->loadHTMLString(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_WebView_loadHTMLString$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::WebView *self = nullptr;
    std::string arg1;       /** string */

    olua_to_object(L, 1, &self, "ccui.WebView");
    olua_check_string(L, 2, &arg1);

    // void loadHTMLString(const std::string &string)
    self->loadHTMLString(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_WebView_loadHTMLString(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccui.WebView")) && (olua_is_string(L, 2))) {
            // void loadHTMLString(const std::string &string)
            return _olua_fun_cocos2d_ui_WebView_loadHTMLString$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "ccui.WebView")) && (olua_is_string(L, 2)) && (olua_is_string(L, 3))) {
            // void loadHTMLString(const std::string &string, @optional const std::string &baseURL)
            return _olua_fun_cocos2d_ui_WebView_loadHTMLString$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::WebView::loadHTMLString' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_WebView_loadURL$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::WebView *self = nullptr;
    std::string arg1;       /** url */

    olua_to_object(L, 1, &self, "ccui.WebView");
    olua_check_string(L, 2, &arg1);

    // void loadURL(const std::string &url)
    self->loadURL(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_WebView_loadURL$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::WebView *self = nullptr;
    std::string arg1;       /** url */
    bool arg2 = false;       /** cleanCachedData */

    olua_to_object(L, 1, &self, "ccui.WebView");
    olua_check_string(L, 2, &arg1);
    olua_check_bool(L, 3, &arg2);

    // void loadURL(const std::string &url, bool cleanCachedData)
    self->loadURL(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_WebView_loadURL(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccui.WebView")) && (olua_is_string(L, 2))) {
            // void loadURL(const std::string &url)
            return _olua_fun_cocos2d_ui_WebView_loadURL$1(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "ccui.WebView")) && (olua_is_string(L, 2)) && (olua_is_bool(L, 3))) {
            // void loadURL(const std::string &url, bool cleanCachedData)
            return _olua_fun_cocos2d_ui_WebView_loadURL$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::WebView::loadURL' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_WebView_new(lua_State *L)
{
    olua_startinvoke(L);

    // cocos2d::ui::WebView()
    cocos2d::ui::WebView *ret = new cocos2d::ui::WebView();
    int num_ret = olua_push_object(L, ret, "ccui.WebView");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_WebView_reload(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::WebView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.WebView");

    // void reload()
    self->reload();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_WebView_setBackgroundTransparent(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::WebView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.WebView");

    // void setBackgroundTransparent()
    self->setBackgroundTransparent();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_WebView_setBounces(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::WebView *self = nullptr;
    bool arg1 = false;       /** bounce */

    olua_to_object(L, 1, &self, "ccui.WebView");
    olua_check_bool(L, 2, &arg1);

    // void setBounces(bool bounce)
    self->setBounces(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_WebView_setJavascriptInterfaceScheme(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::WebView *self = nullptr;
    std::string arg1;       /** scheme */

    olua_to_object(L, 1, &self, "ccui.WebView");
    olua_check_string(L, 2, &arg1);

    // void setJavascriptInterfaceScheme(const std::string &scheme)
    self->setJavascriptInterfaceScheme(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_WebView_setOnDidFailLoading(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::WebView *self = nullptr;
    cocos2d::ui::WebView::ccWebViewCallback arg1;       /** callback */

    olua_to_object(L, 1, &self, "ccui.WebView");
    if (!olua_isnoneornil(L, 2)) {
        olua_check_callback(L, 2, &arg1, "ccui.WebView.ccWebViewCallback");
    }

    void *cb_store = (void *)self;
    std::string cb_tag = "OnDidFailLoading";
    std::string cb_name;
    if (olua_isfunction(L, 2)) {
        cb_name = olua_setcallback(L, cb_store, 2, cb_tag.c_str(), OLUA_TAG_REPLACE);
        olua_Context cb_ctx = olua_context(L);
        // lua_State *ML = olua_mainthread(L);
        arg1 = [cb_store, cb_name, cb_ctx /*, ML */](cocos2d::ui::WebView *cb_arg1, const std::string &cb_arg2) {
            lua_State *L = olua_mainthread(NULL);
            olua_checkhostthread();

            if (olua_contextequal(L, cb_ctx)) {
                int top = lua_gettop(L);
                olua_push_object(L, cb_arg1, "ccui.WebView");
                olua_push_string(L, cb_arg2);

                olua_callback(L, cb_store, cb_name.c_str(), 2);

                lua_settop(L, top);
            }
        };
    } else {
        olua_removecallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_EQUAL);
        arg1 = nullptr;
    }

    // void setOnDidFailLoading(@nullable const cocos2d::ui::WebView::ccWebViewCallback &callback)
    self->setOnDidFailLoading(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_WebView_setOnDidFinishLoading(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::WebView *self = nullptr;
    cocos2d::ui::WebView::ccWebViewCallback arg1;       /** callback */

    olua_to_object(L, 1, &self, "ccui.WebView");
    if (!olua_isnoneornil(L, 2)) {
        olua_check_callback(L, 2, &arg1, "ccui.WebView.ccWebViewCallback");
    }

    void *cb_store = (void *)self;
    std::string cb_tag = "OnDidFinishLoading";
    std::string cb_name;
    if (olua_isfunction(L, 2)) {
        cb_name = olua_setcallback(L, cb_store, 2, cb_tag.c_str(), OLUA_TAG_REPLACE);
        olua_Context cb_ctx = olua_context(L);
        // lua_State *ML = olua_mainthread(L);
        arg1 = [cb_store, cb_name, cb_ctx /*, ML */](cocos2d::ui::WebView *cb_arg1, const std::string &cb_arg2) {
            lua_State *L = olua_mainthread(NULL);
            olua_checkhostthread();

            if (olua_contextequal(L, cb_ctx)) {
                int top = lua_gettop(L);
                olua_push_object(L, cb_arg1, "ccui.WebView");
                olua_push_string(L, cb_arg2);

                olua_callback(L, cb_store, cb_name.c_str(), 2);

                lua_settop(L, top);
            }
        };
    } else {
        olua_removecallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_EQUAL);
        arg1 = nullptr;
    }

    // void setOnDidFinishLoading(@nullable const cocos2d::ui::WebView::ccWebViewCallback &callback)
    self->setOnDidFinishLoading(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_WebView_setOnJSCallback(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::WebView *self = nullptr;
    cocos2d::ui::WebView::ccWebViewCallback arg1;       /** callback */

    olua_to_object(L, 1, &self, "ccui.WebView");
    if (!olua_isnoneornil(L, 2)) {
        olua_check_callback(L, 2, &arg1, "ccui.WebView.ccWebViewCallback");
    }

    void *cb_store = (void *)self;
    std::string cb_tag = "OnJSCallback";
    std::string cb_name;
    if (olua_isfunction(L, 2)) {
        cb_name = olua_setcallback(L, cb_store, 2, cb_tag.c_str(), OLUA_TAG_REPLACE);
        olua_Context cb_ctx = olua_context(L);
        // lua_State *ML = olua_mainthread(L);
        arg1 = [cb_store, cb_name, cb_ctx /*, ML */](cocos2d::ui::WebView *cb_arg1, const std::string &cb_arg2) {
            lua_State *L = olua_mainthread(NULL);
            olua_checkhostthread();

            if (olua_contextequal(L, cb_ctx)) {
                int top = lua_gettop(L);
                olua_push_object(L, cb_arg1, "ccui.WebView");
                olua_push_string(L, cb_arg2);

                olua_callback(L, cb_store, cb_name.c_str(), 2);

                lua_settop(L, top);
            }
        };
    } else {
        olua_removecallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_EQUAL);
        arg1 = nullptr;
    }

    // void setOnJSCallback(@nullable const cocos2d::ui::WebView::ccWebViewCallback &callback)
    self->setOnJSCallback(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_WebView_setOnShouldStartLoading(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::WebView *self = nullptr;
    std::function<bool (cocos2d::ui::WebView *, const std::string &)> arg1;       /** callback */

    olua_to_object(L, 1, &self, "ccui.WebView");
    if (!olua_isnoneornil(L, 2)) {
        olua_check_callback(L, 2, &arg1, "std.function");
    }

    void *cb_store = (void *)self;
    std::string cb_tag = "OnShouldStartLoading";
    std::string cb_name;
    if (olua_isfunction(L, 2)) {
        cb_name = olua_setcallback(L, cb_store, 2, cb_tag.c_str(), OLUA_TAG_REPLACE);
        olua_Context cb_ctx = olua_context(L);
        // lua_State *ML = olua_mainthread(L);
        arg1 = [cb_store, cb_name, cb_ctx /*, ML */](cocos2d::ui::WebView *cb_arg1, const std::string &cb_arg2) {
            lua_State *L = olua_mainthread(NULL);
            olua_checkhostthread();
            bool ret = false;       /** ret */
            if (olua_contextequal(L, cb_ctx)) {
                int top = lua_gettop(L);
                olua_push_object(L, cb_arg1, "ccui.WebView");
                olua_push_string(L, cb_arg2);

                olua_callback(L, cb_store, cb_name.c_str(), 2);

                if (olua_is_bool(L, -1)) {
                    olua_check_bool(L, -1, &ret);
                }

                lua_settop(L, top);
            }
            return ret;
        };
    } else {
        olua_removecallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_EQUAL);
        arg1 = nullptr;
    }

    // void setOnShouldStartLoading(@nullable const std::function<bool (cocos2d::ui::WebView *, const std::string &)> &callback)
    self->setOnShouldStartLoading(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_WebView_setOpacityWebView(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::WebView *self = nullptr;
    float arg1 = 0;       /** opacity */

    olua_to_object(L, 1, &self, "ccui.WebView");
    olua_check_number(L, 2, &arg1);

    // void setOpacityWebView(float opacity)
    self->setOpacityWebView(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_WebView_setScalesPageToFit(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::WebView *self = nullptr;
    bool arg1 = false;       /** scalesPageToFit */

    olua_to_object(L, 1, &self, "ccui.WebView");
    olua_check_bool(L, 2, &arg1);

    // void setScalesPageToFit(const bool scalesPageToFit)
    self->setScalesPageToFit(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_WebView_stopLoading(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::WebView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.WebView");

    // void stopLoading()
    self->stopLoading();

    olua_endinvoke(L);

    return 0;
}

static int _olua_cls_ccui_WebView(lua_State *L)
{
    oluacls_class<cocos2d::ui::WebView, cocos2d::ui::Widget>(L, "ccui.WebView");
    oluacls_func(L, "canGoBack", _olua_fun_cocos2d_ui_WebView_canGoBack);
    oluacls_func(L, "canGoForward", _olua_fun_cocos2d_ui_WebView_canGoForward);
    oluacls_func(L, "create", _olua_fun_cocos2d_ui_WebView_create);
    oluacls_func(L, "evaluateJS", _olua_fun_cocos2d_ui_WebView_evaluateJS);
    oluacls_func(L, "getOnDidFailLoading", _olua_fun_cocos2d_ui_WebView_getOnDidFailLoading);
    oluacls_func(L, "getOnDidFinishLoading", _olua_fun_cocos2d_ui_WebView_getOnDidFinishLoading);
    oluacls_func(L, "getOnJSCallback", _olua_fun_cocos2d_ui_WebView_getOnJSCallback);
    oluacls_func(L, "getOnShouldStartLoading", _olua_fun_cocos2d_ui_WebView_getOnShouldStartLoading);
    oluacls_func(L, "getOpacityWebView", _olua_fun_cocos2d_ui_WebView_getOpacityWebView);
    oluacls_func(L, "goBack", _olua_fun_cocos2d_ui_WebView_goBack);
    oluacls_func(L, "goForward", _olua_fun_cocos2d_ui_WebView_goForward);
    oluacls_func(L, "loadData", _olua_fun_cocos2d_ui_WebView_loadData);
    oluacls_func(L, "loadFile", _olua_fun_cocos2d_ui_WebView_loadFile);
    oluacls_func(L, "loadHTMLString", _olua_fun_cocos2d_ui_WebView_loadHTMLString);
    oluacls_func(L, "loadURL", _olua_fun_cocos2d_ui_WebView_loadURL);
    oluacls_func(L, "new", _olua_fun_cocos2d_ui_WebView_new);
    oluacls_func(L, "reload", _olua_fun_cocos2d_ui_WebView_reload);
    oluacls_func(L, "setBackgroundTransparent", _olua_fun_cocos2d_ui_WebView_setBackgroundTransparent);
    oluacls_func(L, "setBounces", _olua_fun_cocos2d_ui_WebView_setBounces);
    oluacls_func(L, "setJavascriptInterfaceScheme", _olua_fun_cocos2d_ui_WebView_setJavascriptInterfaceScheme);
    oluacls_func(L, "setOnDidFailLoading", _olua_fun_cocos2d_ui_WebView_setOnDidFailLoading);
    oluacls_func(L, "setOnDidFinishLoading", _olua_fun_cocos2d_ui_WebView_setOnDidFinishLoading);
    oluacls_func(L, "setOnJSCallback", _olua_fun_cocos2d_ui_WebView_setOnJSCallback);
    oluacls_func(L, "setOnShouldStartLoading", _olua_fun_cocos2d_ui_WebView_setOnShouldStartLoading);
    oluacls_func(L, "setOpacityWebView", _olua_fun_cocos2d_ui_WebView_setOpacityWebView);
    oluacls_func(L, "setScalesPageToFit", _olua_fun_cocos2d_ui_WebView_setScalesPageToFit);
    oluacls_func(L, "stopLoading", _olua_fun_cocos2d_ui_WebView_stopLoading);
    oluacls_prop(L, "onDidFailLoading", _olua_fun_cocos2d_ui_WebView_getOnDidFailLoading, _olua_fun_cocos2d_ui_WebView_setOnDidFailLoading);
    oluacls_prop(L, "onDidFinishLoading", _olua_fun_cocos2d_ui_WebView_getOnDidFinishLoading, _olua_fun_cocos2d_ui_WebView_setOnDidFinishLoading);
    oluacls_prop(L, "onJSCallback", _olua_fun_cocos2d_ui_WebView_getOnJSCallback, _olua_fun_cocos2d_ui_WebView_setOnJSCallback);
    oluacls_prop(L, "onShouldStartLoading", _olua_fun_cocos2d_ui_WebView_getOnShouldStartLoading, _olua_fun_cocos2d_ui_WebView_setOnShouldStartLoading);
    oluacls_prop(L, "opacityWebView", _olua_fun_cocos2d_ui_WebView_getOpacityWebView, _olua_fun_cocos2d_ui_WebView_setOpacityWebView);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_WebView(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.WebView")) {
        luaL_error(L, "class not found: cocos2d::ui::WebView");
    }
    return 1;
}
OLUA_END_DECLS
#endif

#if defined(CCLUA_OS_IOS) || defined(CCLUA_OS_ANDROID)
static int _olua_cls_ccui_VideoPlayer_EventType(lua_State *L)
{
    oluacls_class<cocos2d::ui::VideoPlayer::EventType>(L, "ccui.VideoPlayer.EventType");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "COMPLETED", (lua_Integer)cocos2d::ui::VideoPlayer::EventType::COMPLETED);
    oluacls_enum(L, "ERROR", (lua_Integer)cocos2d::ui::VideoPlayer::EventType::ERROR);
    oluacls_enum(L, "PAUSED", (lua_Integer)cocos2d::ui::VideoPlayer::EventType::PAUSED);
    oluacls_enum(L, "PLAYING", (lua_Integer)cocos2d::ui::VideoPlayer::EventType::PLAYING);
    oluacls_enum(L, "STOPPED", (lua_Integer)cocos2d::ui::VideoPlayer::EventType::STOPPED);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_VideoPlayer_EventType(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.VideoPlayer.EventType")) {
        luaL_error(L, "class not found: cocos2d::ui::VideoPlayer::EventType");
    }
    return 1;
}
OLUA_END_DECLS
#endif

#if defined(CCLUA_OS_IOS) || defined(CCLUA_OS_ANDROID)
static int _olua_fun_cocos2d_ui_VideoPlayer_ccVideoPlayerCallback___call(lua_State *L)
{
    olua_startinvoke(L);

    luaL_checktype(L, -1, LUA_TFUNCTION);
    olua_push_callback(L, (cocos2d::ui::VideoPlayer::ccVideoPlayerCallback *)nullptr, "ccui.VideoPlayer.ccVideoPlayerCallback");

    olua_endinvoke(L);

    return 1;
}

static int _olua_cls_ccui_VideoPlayer_ccVideoPlayerCallback(lua_State *L)
{
    oluacls_class<cocos2d::ui::VideoPlayer::ccVideoPlayerCallback>(L, "ccui.VideoPlayer.ccVideoPlayerCallback");
    oluacls_func(L, "__call", _olua_fun_cocos2d_ui_VideoPlayer_ccVideoPlayerCallback___call);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_VideoPlayer_ccVideoPlayerCallback(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.VideoPlayer.ccVideoPlayerCallback")) {
        luaL_error(L, "class not found: cocos2d::ui::VideoPlayer::ccVideoPlayerCallback");
    }
    return 1;
}
OLUA_END_DECLS
#endif

#if defined(CCLUA_OS_IOS) || defined(CCLUA_OS_ANDROID)
static int _olua_cls_ccui_VideoPlayer_StyleType(lua_State *L)
{
    oluacls_class<cocos2d::ui::VideoPlayer::StyleType>(L, "ccui.VideoPlayer.StyleType");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "DEFAULT", (lua_Integer)cocos2d::ui::VideoPlayer::StyleType::DEFAULT);
    oluacls_enum(L, "NONE", (lua_Integer)cocos2d::ui::VideoPlayer::StyleType::NONE);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_VideoPlayer_StyleType(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.VideoPlayer.StyleType")) {
        luaL_error(L, "class not found: cocos2d::ui::VideoPlayer::StyleType");
    }
    return 1;
}
OLUA_END_DECLS
#endif

#if defined(CCLUA_OS_IOS) || defined(CCLUA_OS_ANDROID)
static int _olua_fun_cocos2d_ui_VideoPlayer_addEventListener(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::VideoPlayer *self = nullptr;
    cocos2d::ui::VideoPlayer::ccVideoPlayerCallback arg1;       /** callback */

    olua_to_object(L, 1, &self, "ccui.VideoPlayer");
    olua_check_callback(L, 2, &arg1, "ccui.VideoPlayer.ccVideoPlayerCallback");

    void *cb_store = (void *)self;
    std::string cb_tag = "videoPlayerCallback";
    std::string cb_name = olua_setcallback(L, cb_store, 2, cb_tag.c_str(), OLUA_TAG_REPLACE);
    olua_Context cb_ctx = olua_context(L);
    // lua_State *ML = olua_mainthread(L);
    arg1 = [cb_store, cb_name, cb_ctx /*, ML */](cocos2d::Ref *cb_arg1, cocos2d::ui::VideoPlayer::EventType cb_arg2) {
        lua_State *L = olua_mainthread(NULL);
        olua_checkhostthread();

        if (olua_contextequal(L, cb_ctx)) {
            int top = lua_gettop(L);
            olua_push_object(L, cb_arg1, "cc.Ref");
            olua_push_enum(L, cb_arg2);

            olua_callback(L, cb_store, cb_name.c_str(), 2);

            lua_settop(L, top);
        }
    };

    // void addEventListener(const cocos2d::ui::VideoPlayer::ccVideoPlayerCallback &callback)
    self->addEventListener(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_VideoPlayer_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::ui::VideoPlayer *create()
    cocos2d::ui::VideoPlayer *ret = cocos2d::ui::VideoPlayer::create();
    int num_ret = olua_push_object(L, ret, "ccui.VideoPlayer");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_VideoPlayer_getFileName(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::VideoPlayer *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.VideoPlayer");

    // const std::string &getFileName()
    const std::string &ret = self->getFileName();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_VideoPlayer_getURL(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::VideoPlayer *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.VideoPlayer");

    // const std::string &getURL()
    const std::string &ret = self->getURL();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_VideoPlayer_isFullScreenEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::VideoPlayer *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.VideoPlayer");

    // bool isFullScreenEnabled()
    bool ret = self->isFullScreenEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_VideoPlayer_isKeepAspectRatioEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::VideoPlayer *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.VideoPlayer");

    // bool isKeepAspectRatioEnabled()
    bool ret = self->isKeepAspectRatioEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_VideoPlayer_isLooping(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::VideoPlayer *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.VideoPlayer");

    // bool isLooping()
    bool ret = self->isLooping();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_VideoPlayer_isPlaying(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::VideoPlayer *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.VideoPlayer");

    // bool isPlaying()
    bool ret = self->isPlaying();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_VideoPlayer_isUserInputEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::VideoPlayer *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.VideoPlayer");

    // bool isUserInputEnabled()
    bool ret = self->isUserInputEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_VideoPlayer_new(lua_State *L)
{
    olua_startinvoke(L);

    // cocos2d::ui::VideoPlayer()
    cocos2d::ui::VideoPlayer *ret = new cocos2d::ui::VideoPlayer();
    int num_ret = olua_push_object(L, ret, "ccui.VideoPlayer");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_VideoPlayer_onPlayEvent(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::VideoPlayer *self = nullptr;
    int arg1 = 0;       /** event */

    olua_to_object(L, 1, &self, "ccui.VideoPlayer");
    olua_check_integer(L, 2, &arg1);

    // void onPlayEvent(int event)
    self->onPlayEvent(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_VideoPlayer_play(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::VideoPlayer *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.VideoPlayer");

    // void play()
    self->play();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_VideoPlayer_seekTo(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::VideoPlayer *self = nullptr;
    float arg1 = 0;       /** sec */

    olua_to_object(L, 1, &self, "ccui.VideoPlayer");
    olua_check_number(L, 2, &arg1);

    // void seekTo(float sec)
    self->seekTo(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_VideoPlayer_setFileName(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::VideoPlayer *self = nullptr;
    std::string arg1;       /** videoPath */

    olua_to_object(L, 1, &self, "ccui.VideoPlayer");
    olua_check_string(L, 2, &arg1);

    // void setFileName(const std::string &videoPath)
    self->setFileName(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_VideoPlayer_setFullScreenEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::VideoPlayer *self = nullptr;
    bool arg1 = false;       /** fullscreen */

    olua_to_object(L, 1, &self, "ccui.VideoPlayer");
    olua_check_bool(L, 2, &arg1);

    // void setFullScreenEnabled(bool fullscreen)
    self->setFullScreenEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_VideoPlayer_setKeepAspectRatioEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::VideoPlayer *self = nullptr;
    bool arg1 = false;       /** enable */

    olua_to_object(L, 1, &self, "ccui.VideoPlayer");
    olua_check_bool(L, 2, &arg1);

    // void setKeepAspectRatioEnabled(bool enable)
    self->setKeepAspectRatioEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_VideoPlayer_setLooping(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::VideoPlayer *self = nullptr;
    bool arg1 = false;       /** looping */

    olua_to_object(L, 1, &self, "ccui.VideoPlayer");
    olua_check_bool(L, 2, &arg1);

    // void setLooping(bool looping)
    self->setLooping(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_VideoPlayer_setStyle(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::VideoPlayer *self = nullptr;
    cocos2d::ui::VideoPlayer::StyleType arg1 = (cocos2d::ui::VideoPlayer::StyleType)0;       /** style */

    olua_to_object(L, 1, &self, "ccui.VideoPlayer");
    olua_check_enum(L, 2, &arg1);

    // void setStyle(cocos2d::ui::VideoPlayer::StyleType style)
    self->setStyle(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_VideoPlayer_setURL(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::VideoPlayer *self = nullptr;
    std::string arg1;       /** _videoURL */

    olua_to_object(L, 1, &self, "ccui.VideoPlayer");
    olua_check_string(L, 2, &arg1);

    // void setURL(const std::string &_videoURL)
    self->setURL(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_VideoPlayer_setUserInputEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::VideoPlayer *self = nullptr;
    bool arg1 = false;       /** enableInput */

    olua_to_object(L, 1, &self, "ccui.VideoPlayer");
    olua_check_bool(L, 2, &arg1);

    // void setUserInputEnabled(bool enableInput)
    self->setUserInputEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_VideoPlayer_stop(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::VideoPlayer *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.VideoPlayer");

    // void stop()
    self->stop();

    olua_endinvoke(L);

    return 0;
}

static int _olua_cls_ccui_VideoPlayer(lua_State *L)
{
    oluacls_class<cocos2d::ui::VideoPlayer, cocos2d::ui::Widget>(L, "ccui.VideoPlayer");
    oluacls_func(L, "addEventListener", _olua_fun_cocos2d_ui_VideoPlayer_addEventListener);
    oluacls_func(L, "create", _olua_fun_cocos2d_ui_VideoPlayer_create);
    oluacls_func(L, "getFileName", _olua_fun_cocos2d_ui_VideoPlayer_getFileName);
    oluacls_func(L, "getURL", _olua_fun_cocos2d_ui_VideoPlayer_getURL);
    oluacls_func(L, "isFullScreenEnabled", _olua_fun_cocos2d_ui_VideoPlayer_isFullScreenEnabled);
    oluacls_func(L, "isKeepAspectRatioEnabled", _olua_fun_cocos2d_ui_VideoPlayer_isKeepAspectRatioEnabled);
    oluacls_func(L, "isLooping", _olua_fun_cocos2d_ui_VideoPlayer_isLooping);
    oluacls_func(L, "isPlaying", _olua_fun_cocos2d_ui_VideoPlayer_isPlaying);
    oluacls_func(L, "isUserInputEnabled", _olua_fun_cocos2d_ui_VideoPlayer_isUserInputEnabled);
    oluacls_func(L, "new", _olua_fun_cocos2d_ui_VideoPlayer_new);
    oluacls_func(L, "onPlayEvent", _olua_fun_cocos2d_ui_VideoPlayer_onPlayEvent);
    oluacls_func(L, "play", _olua_fun_cocos2d_ui_VideoPlayer_play);
    oluacls_func(L, "seekTo", _olua_fun_cocos2d_ui_VideoPlayer_seekTo);
    oluacls_func(L, "setFileName", _olua_fun_cocos2d_ui_VideoPlayer_setFileName);
    oluacls_func(L, "setFullScreenEnabled", _olua_fun_cocos2d_ui_VideoPlayer_setFullScreenEnabled);
    oluacls_func(L, "setKeepAspectRatioEnabled", _olua_fun_cocos2d_ui_VideoPlayer_setKeepAspectRatioEnabled);
    oluacls_func(L, "setLooping", _olua_fun_cocos2d_ui_VideoPlayer_setLooping);
    oluacls_func(L, "setStyle", _olua_fun_cocos2d_ui_VideoPlayer_setStyle);
    oluacls_func(L, "setURL", _olua_fun_cocos2d_ui_VideoPlayer_setURL);
    oluacls_func(L, "setUserInputEnabled", _olua_fun_cocos2d_ui_VideoPlayer_setUserInputEnabled);
    oluacls_func(L, "stop", _olua_fun_cocos2d_ui_VideoPlayer_stop);
    oluacls_prop(L, "fileName", _olua_fun_cocos2d_ui_VideoPlayer_getFileName, _olua_fun_cocos2d_ui_VideoPlayer_setFileName);
    oluacls_prop(L, "fullScreenEnabled", _olua_fun_cocos2d_ui_VideoPlayer_isFullScreenEnabled, _olua_fun_cocos2d_ui_VideoPlayer_setFullScreenEnabled);
    oluacls_prop(L, "keepAspectRatioEnabled", _olua_fun_cocos2d_ui_VideoPlayer_isKeepAspectRatioEnabled, _olua_fun_cocos2d_ui_VideoPlayer_setKeepAspectRatioEnabled);
    oluacls_prop(L, "looping", _olua_fun_cocos2d_ui_VideoPlayer_isLooping, _olua_fun_cocos2d_ui_VideoPlayer_setLooping);
    oluacls_prop(L, "playing", _olua_fun_cocos2d_ui_VideoPlayer_isPlaying, nullptr);
    oluacls_prop(L, "url", _olua_fun_cocos2d_ui_VideoPlayer_getURL, _olua_fun_cocos2d_ui_VideoPlayer_setURL);
    oluacls_prop(L, "userInputEnabled", _olua_fun_cocos2d_ui_VideoPlayer_isUserInputEnabled, _olua_fun_cocos2d_ui_VideoPlayer_setUserInputEnabled);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_VideoPlayer(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.VideoPlayer")) {
        luaL_error(L, "class not found: cocos2d::ui::VideoPlayer");
    }
    return 1;
}
OLUA_END_DECLS
#endif

static int _olua_fun_cocos2d_ui_AbstractCheckButton_getBackDisabledFile(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::AbstractCheckButton *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.AbstractCheckButton");

    // cocos2d::ResourceData getBackDisabledFile()
    cocos2d::ResourceData ret = self->getBackDisabledFile();
    int num_ret = olua_copy_object(L, ret, "cc.ResourceData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_AbstractCheckButton_getBackNormalFile(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::AbstractCheckButton *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.AbstractCheckButton");

    // cocos2d::ResourceData getBackNormalFile()
    cocos2d::ResourceData ret = self->getBackNormalFile();
    int num_ret = olua_copy_object(L, ret, "cc.ResourceData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_AbstractCheckButton_getBackPressedFile(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::AbstractCheckButton *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.AbstractCheckButton");

    // cocos2d::ResourceData getBackPressedFile()
    cocos2d::ResourceData ret = self->getBackPressedFile();
    int num_ret = olua_copy_object(L, ret, "cc.ResourceData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_AbstractCheckButton_getCrossDisabledFile(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::AbstractCheckButton *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.AbstractCheckButton");

    // cocos2d::ResourceData getCrossDisabledFile()
    cocos2d::ResourceData ret = self->getCrossDisabledFile();
    int num_ret = olua_copy_object(L, ret, "cc.ResourceData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_AbstractCheckButton_getCrossNormalFile(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::AbstractCheckButton *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.AbstractCheckButton");

    // cocos2d::ResourceData getCrossNormalFile()
    cocos2d::ResourceData ret = self->getCrossNormalFile();
    int num_ret = olua_copy_object(L, ret, "cc.ResourceData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_AbstractCheckButton_getRendererBackground(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::AbstractCheckButton *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.AbstractCheckButton");

    // @addref(protectedChildren |) cocos2d::Sprite *getRendererBackground()
    cocos2d::Sprite *ret = self->getRendererBackground();
    int num_ret = olua_push_object(L, ret, "cc.Sprite");

    // insert code after call
    olua_addref(L, 1, "protectedChildren", -1, OLUA_REF_MULTI);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_AbstractCheckButton_getRendererBackgroundDisabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::AbstractCheckButton *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.AbstractCheckButton");

    // @addref(protectedChildren |) cocos2d::Sprite *getRendererBackgroundDisabled()
    cocos2d::Sprite *ret = self->getRendererBackgroundDisabled();
    int num_ret = olua_push_object(L, ret, "cc.Sprite");

    // insert code after call
    olua_addref(L, 1, "protectedChildren", -1, OLUA_REF_MULTI);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_AbstractCheckButton_getRendererBackgroundSelected(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::AbstractCheckButton *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.AbstractCheckButton");

    // @addref(protectedChildren |) cocos2d::Sprite *getRendererBackgroundSelected()
    cocos2d::Sprite *ret = self->getRendererBackgroundSelected();
    int num_ret = olua_push_object(L, ret, "cc.Sprite");

    // insert code after call
    olua_addref(L, 1, "protectedChildren", -1, OLUA_REF_MULTI);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_AbstractCheckButton_getRendererFrontCross(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::AbstractCheckButton *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.AbstractCheckButton");

    // @addref(protectedChildren |) cocos2d::Sprite *getRendererFrontCross()
    cocos2d::Sprite *ret = self->getRendererFrontCross();
    int num_ret = olua_push_object(L, ret, "cc.Sprite");

    // insert code after call
    olua_addref(L, 1, "protectedChildren", -1, OLUA_REF_MULTI);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_AbstractCheckButton_getRendererFrontCrossDisabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::AbstractCheckButton *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.AbstractCheckButton");

    // @addref(protectedChildren |) cocos2d::Sprite *getRendererFrontCrossDisabled()
    cocos2d::Sprite *ret = self->getRendererFrontCrossDisabled();
    int num_ret = olua_push_object(L, ret, "cc.Sprite");

    // insert code after call
    olua_addref(L, 1, "protectedChildren", -1, OLUA_REF_MULTI);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_AbstractCheckButton_getZoomScale(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::AbstractCheckButton *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.AbstractCheckButton");

    // float getZoomScale()
    float ret = self->getZoomScale();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_AbstractCheckButton_init$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::AbstractCheckButton *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.AbstractCheckButton");

    // @using bool init()
    bool ret = self->init();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_AbstractCheckButton_init$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::AbstractCheckButton *self = nullptr;
    std::string arg1;       /** backGround */
    std::string arg2;       /** backGroundSelected */
    std::string arg3;       /** cross */
    std::string arg4;       /** backGroundDisabled */
    std::string arg5;       /** frontCrossDisabled */
    cocos2d::ui::Widget::TextureResType arg6 = (cocos2d::ui::Widget::TextureResType)0;       /** texType */

    olua_to_object(L, 1, &self, "ccui.AbstractCheckButton");
    olua_check_string(L, 2, &arg1);
    olua_check_string(L, 3, &arg2);
    olua_check_string(L, 4, &arg3);
    olua_check_string(L, 5, &arg4);
    olua_check_string(L, 6, &arg5);
    olua_check_enum(L, 7, &arg6);

    // bool init(const std::string &backGround, const std::string &backGroundSelected, const std::string &cross, const std::string &backGroundDisabled, const std::string &frontCrossDisabled, @optional cocos2d::ui::Widget::TextureResType texType)
    bool ret = self->init(arg1, arg2, arg3, arg4, arg5, arg6);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_AbstractCheckButton_init$3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::AbstractCheckButton *self = nullptr;
    std::string arg1;       /** backGround */
    std::string arg2;       /** backGroundSelected */
    std::string arg3;       /** cross */
    std::string arg4;       /** backGroundDisabled */
    std::string arg5;       /** frontCrossDisabled */

    olua_to_object(L, 1, &self, "ccui.AbstractCheckButton");
    olua_check_string(L, 2, &arg1);
    olua_check_string(L, 3, &arg2);
    olua_check_string(L, 4, &arg3);
    olua_check_string(L, 5, &arg4);
    olua_check_string(L, 6, &arg5);

    // bool init(const std::string &backGround, const std::string &backGroundSelected, const std::string &cross, const std::string &backGroundDisabled, const std::string &frontCrossDisabled)
    bool ret = self->init(arg1, arg2, arg3, arg4, arg5);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_AbstractCheckButton_init(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // @using bool init()
        return _olua_fun_cocos2d_ui_AbstractCheckButton_init$1(L);
    }

    if (num_args == 6) {
        // if ((olua_is_object(L, 1, "ccui.AbstractCheckButton")) && (olua_is_string(L, 2)) && (olua_is_string(L, 3)) && (olua_is_string(L, 4)) && (olua_is_string(L, 5)) && (olua_is_string(L, 6))) {
            // bool init(const std::string &backGround, const std::string &backGroundSelected, const std::string &cross, const std::string &backGroundDisabled, const std::string &frontCrossDisabled)
            return _olua_fun_cocos2d_ui_AbstractCheckButton_init$3(L);
        // }
    }

    if (num_args == 7) {
        // if ((olua_is_object(L, 1, "ccui.AbstractCheckButton")) && (olua_is_string(L, 2)) && (olua_is_string(L, 3)) && (olua_is_string(L, 4)) && (olua_is_string(L, 5)) && (olua_is_string(L, 6)) && (olua_is_enum(L, 7))) {
            // bool init(const std::string &backGround, const std::string &backGroundSelected, const std::string &cross, const std::string &backGroundDisabled, const std::string &frontCrossDisabled, @optional cocos2d::ui::Widget::TextureResType texType)
            return _olua_fun_cocos2d_ui_AbstractCheckButton_init$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::AbstractCheckButton::init' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_AbstractCheckButton_isSelected(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::AbstractCheckButton *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.AbstractCheckButton");

    // bool isSelected()
    bool ret = self->isSelected();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_AbstractCheckButton_loadTextureBackGround$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::AbstractCheckButton *self = nullptr;
    std::string arg1;       /** backGround */
    cocos2d::ui::Widget::TextureResType arg2 = (cocos2d::ui::Widget::TextureResType)0;       /** type */

    olua_to_object(L, 1, &self, "ccui.AbstractCheckButton");
    olua_check_string(L, 2, &arg1);
    olua_check_enum(L, 3, &arg2);

    // void loadTextureBackGround(const std::string &backGround, @optional cocos2d::ui::Widget::TextureResType type)
    self->loadTextureBackGround(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_AbstractCheckButton_loadTextureBackGround$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::AbstractCheckButton *self = nullptr;
    std::string arg1;       /** backGround */

    olua_to_object(L, 1, &self, "ccui.AbstractCheckButton");
    olua_check_string(L, 2, &arg1);

    // void loadTextureBackGround(const std::string &backGround)
    self->loadTextureBackGround(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_AbstractCheckButton_loadTextureBackGround(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccui.AbstractCheckButton")) && (olua_is_string(L, 2))) {
            // void loadTextureBackGround(const std::string &backGround)
            return _olua_fun_cocos2d_ui_AbstractCheckButton_loadTextureBackGround$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "ccui.AbstractCheckButton")) && (olua_is_string(L, 2)) && (olua_is_enum(L, 3))) {
            // void loadTextureBackGround(const std::string &backGround, @optional cocos2d::ui::Widget::TextureResType type)
            return _olua_fun_cocos2d_ui_AbstractCheckButton_loadTextureBackGround$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::AbstractCheckButton::loadTextureBackGround' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_AbstractCheckButton_loadTextureBackGroundDisabled$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::AbstractCheckButton *self = nullptr;
    std::string arg1;       /** backGroundDisabled */
    cocos2d::ui::Widget::TextureResType arg2 = (cocos2d::ui::Widget::TextureResType)0;       /** texType */

    olua_to_object(L, 1, &self, "ccui.AbstractCheckButton");
    olua_check_string(L, 2, &arg1);
    olua_check_enum(L, 3, &arg2);

    // void loadTextureBackGroundDisabled(const std::string &backGroundDisabled, @optional cocos2d::ui::Widget::TextureResType texType)
    self->loadTextureBackGroundDisabled(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_AbstractCheckButton_loadTextureBackGroundDisabled$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::AbstractCheckButton *self = nullptr;
    std::string arg1;       /** backGroundDisabled */

    olua_to_object(L, 1, &self, "ccui.AbstractCheckButton");
    olua_check_string(L, 2, &arg1);

    // void loadTextureBackGroundDisabled(const std::string &backGroundDisabled)
    self->loadTextureBackGroundDisabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_AbstractCheckButton_loadTextureBackGroundDisabled(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccui.AbstractCheckButton")) && (olua_is_string(L, 2))) {
            // void loadTextureBackGroundDisabled(const std::string &backGroundDisabled)
            return _olua_fun_cocos2d_ui_AbstractCheckButton_loadTextureBackGroundDisabled$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "ccui.AbstractCheckButton")) && (olua_is_string(L, 2)) && (olua_is_enum(L, 3))) {
            // void loadTextureBackGroundDisabled(const std::string &backGroundDisabled, @optional cocos2d::ui::Widget::TextureResType texType)
            return _olua_fun_cocos2d_ui_AbstractCheckButton_loadTextureBackGroundDisabled$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::AbstractCheckButton::loadTextureBackGroundDisabled' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_AbstractCheckButton_loadTextureBackGroundSelected$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::AbstractCheckButton *self = nullptr;
    std::string arg1;       /** backGroundSelected */
    cocos2d::ui::Widget::TextureResType arg2 = (cocos2d::ui::Widget::TextureResType)0;       /** texType */

    olua_to_object(L, 1, &self, "ccui.AbstractCheckButton");
    olua_check_string(L, 2, &arg1);
    olua_check_enum(L, 3, &arg2);

    // void loadTextureBackGroundSelected(const std::string &backGroundSelected, @optional cocos2d::ui::Widget::TextureResType texType)
    self->loadTextureBackGroundSelected(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_AbstractCheckButton_loadTextureBackGroundSelected$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::AbstractCheckButton *self = nullptr;
    std::string arg1;       /** backGroundSelected */

    olua_to_object(L, 1, &self, "ccui.AbstractCheckButton");
    olua_check_string(L, 2, &arg1);

    // void loadTextureBackGroundSelected(const std::string &backGroundSelected)
    self->loadTextureBackGroundSelected(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_AbstractCheckButton_loadTextureBackGroundSelected(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccui.AbstractCheckButton")) && (olua_is_string(L, 2))) {
            // void loadTextureBackGroundSelected(const std::string &backGroundSelected)
            return _olua_fun_cocos2d_ui_AbstractCheckButton_loadTextureBackGroundSelected$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "ccui.AbstractCheckButton")) && (olua_is_string(L, 2)) && (olua_is_enum(L, 3))) {
            // void loadTextureBackGroundSelected(const std::string &backGroundSelected, @optional cocos2d::ui::Widget::TextureResType texType)
            return _olua_fun_cocos2d_ui_AbstractCheckButton_loadTextureBackGroundSelected$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::AbstractCheckButton::loadTextureBackGroundSelected' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_AbstractCheckButton_loadTextureFrontCross$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::AbstractCheckButton *self = nullptr;
    std::string arg1;       /** crossTextureName */
    cocos2d::ui::Widget::TextureResType arg2 = (cocos2d::ui::Widget::TextureResType)0;       /** texType */

    olua_to_object(L, 1, &self, "ccui.AbstractCheckButton");
    olua_check_string(L, 2, &arg1);
    olua_check_enum(L, 3, &arg2);

    // void loadTextureFrontCross(const std::string &crossTextureName, @optional cocos2d::ui::Widget::TextureResType texType)
    self->loadTextureFrontCross(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_AbstractCheckButton_loadTextureFrontCross$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::AbstractCheckButton *self = nullptr;
    std::string arg1;       /** crossTextureName */

    olua_to_object(L, 1, &self, "ccui.AbstractCheckButton");
    olua_check_string(L, 2, &arg1);

    // void loadTextureFrontCross(const std::string &crossTextureName)
    self->loadTextureFrontCross(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_AbstractCheckButton_loadTextureFrontCross(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccui.AbstractCheckButton")) && (olua_is_string(L, 2))) {
            // void loadTextureFrontCross(const std::string &crossTextureName)
            return _olua_fun_cocos2d_ui_AbstractCheckButton_loadTextureFrontCross$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "ccui.AbstractCheckButton")) && (olua_is_string(L, 2)) && (olua_is_enum(L, 3))) {
            // void loadTextureFrontCross(const std::string &crossTextureName, @optional cocos2d::ui::Widget::TextureResType texType)
            return _olua_fun_cocos2d_ui_AbstractCheckButton_loadTextureFrontCross$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::AbstractCheckButton::loadTextureFrontCross' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_AbstractCheckButton_loadTextureFrontCrossDisabled$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::AbstractCheckButton *self = nullptr;
    std::string arg1;       /** frontCrossDisabled */
    cocos2d::ui::Widget::TextureResType arg2 = (cocos2d::ui::Widget::TextureResType)0;       /** texType */

    olua_to_object(L, 1, &self, "ccui.AbstractCheckButton");
    olua_check_string(L, 2, &arg1);
    olua_check_enum(L, 3, &arg2);

    // void loadTextureFrontCrossDisabled(const std::string &frontCrossDisabled, @optional cocos2d::ui::Widget::TextureResType texType)
    self->loadTextureFrontCrossDisabled(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_AbstractCheckButton_loadTextureFrontCrossDisabled$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::AbstractCheckButton *self = nullptr;
    std::string arg1;       /** frontCrossDisabled */

    olua_to_object(L, 1, &self, "ccui.AbstractCheckButton");
    olua_check_string(L, 2, &arg1);

    // void loadTextureFrontCrossDisabled(const std::string &frontCrossDisabled)
    self->loadTextureFrontCrossDisabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_AbstractCheckButton_loadTextureFrontCrossDisabled(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccui.AbstractCheckButton")) && (olua_is_string(L, 2))) {
            // void loadTextureFrontCrossDisabled(const std::string &frontCrossDisabled)
            return _olua_fun_cocos2d_ui_AbstractCheckButton_loadTextureFrontCrossDisabled$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "ccui.AbstractCheckButton")) && (olua_is_string(L, 2)) && (olua_is_enum(L, 3))) {
            // void loadTextureFrontCrossDisabled(const std::string &frontCrossDisabled, @optional cocos2d::ui::Widget::TextureResType texType)
            return _olua_fun_cocos2d_ui_AbstractCheckButton_loadTextureFrontCrossDisabled$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::AbstractCheckButton::loadTextureFrontCrossDisabled' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_AbstractCheckButton_loadTextures$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::AbstractCheckButton *self = nullptr;
    std::string arg1;       /** background */
    std::string arg2;       /** backgroundSelected */
    std::string arg3;       /** cross */
    std::string arg4;       /** backgroundDisabled */
    std::string arg5;       /** frontCrossDisabled */
    cocos2d::ui::Widget::TextureResType arg6 = (cocos2d::ui::Widget::TextureResType)0;       /** texType */

    olua_to_object(L, 1, &self, "ccui.AbstractCheckButton");
    olua_check_string(L, 2, &arg1);
    olua_check_string(L, 3, &arg2);
    olua_check_string(L, 4, &arg3);
    olua_check_string(L, 5, &arg4);
    olua_check_string(L, 6, &arg5);
    olua_check_enum(L, 7, &arg6);

    // void loadTextures(const std::string &background, const std::string &backgroundSelected, const std::string &cross, const std::string &backgroundDisabled, const std::string &frontCrossDisabled, @optional cocos2d::ui::Widget::TextureResType texType)
    self->loadTextures(arg1, arg2, arg3, arg4, arg5, arg6);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_AbstractCheckButton_loadTextures$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::AbstractCheckButton *self = nullptr;
    std::string arg1;       /** background */
    std::string arg2;       /** backgroundSelected */
    std::string arg3;       /** cross */
    std::string arg4;       /** backgroundDisabled */
    std::string arg5;       /** frontCrossDisabled */

    olua_to_object(L, 1, &self, "ccui.AbstractCheckButton");
    olua_check_string(L, 2, &arg1);
    olua_check_string(L, 3, &arg2);
    olua_check_string(L, 4, &arg3);
    olua_check_string(L, 5, &arg4);
    olua_check_string(L, 6, &arg5);

    // void loadTextures(const std::string &background, const std::string &backgroundSelected, const std::string &cross, const std::string &backgroundDisabled, const std::string &frontCrossDisabled)
    self->loadTextures(arg1, arg2, arg3, arg4, arg5);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_AbstractCheckButton_loadTextures(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 6) {
        // if ((olua_is_object(L, 1, "ccui.AbstractCheckButton")) && (olua_is_string(L, 2)) && (olua_is_string(L, 3)) && (olua_is_string(L, 4)) && (olua_is_string(L, 5)) && (olua_is_string(L, 6))) {
            // void loadTextures(const std::string &background, const std::string &backgroundSelected, const std::string &cross, const std::string &backgroundDisabled, const std::string &frontCrossDisabled)
            return _olua_fun_cocos2d_ui_AbstractCheckButton_loadTextures$2(L);
        // }
    }

    if (num_args == 7) {
        // if ((olua_is_object(L, 1, "ccui.AbstractCheckButton")) && (olua_is_string(L, 2)) && (olua_is_string(L, 3)) && (olua_is_string(L, 4)) && (olua_is_string(L, 5)) && (olua_is_string(L, 6)) && (olua_is_enum(L, 7))) {
            // void loadTextures(const std::string &background, const std::string &backgroundSelected, const std::string &cross, const std::string &backgroundDisabled, const std::string &frontCrossDisabled, @optional cocos2d::ui::Widget::TextureResType texType)
            return _olua_fun_cocos2d_ui_AbstractCheckButton_loadTextures$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::AbstractCheckButton::loadTextures' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_AbstractCheckButton_setSelected(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::AbstractCheckButton *self = nullptr;
    bool arg1 = false;       /** selected */

    olua_to_object(L, 1, &self, "ccui.AbstractCheckButton");
    olua_check_bool(L, 2, &arg1);

    // void setSelected(bool selected)
    self->setSelected(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_AbstractCheckButton_setZoomScale(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::AbstractCheckButton *self = nullptr;
    float arg1 = 0;       /** scale */

    olua_to_object(L, 1, &self, "ccui.AbstractCheckButton");
    olua_check_number(L, 2, &arg1);

    // void setZoomScale(float scale)
    self->setZoomScale(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_cls_ccui_AbstractCheckButton(lua_State *L)
{
    oluacls_class<cocos2d::ui::AbstractCheckButton, cocos2d::ui::Widget>(L, "ccui.AbstractCheckButton");
    oluacls_func(L, "getBackDisabledFile", _olua_fun_cocos2d_ui_AbstractCheckButton_getBackDisabledFile);
    oluacls_func(L, "getBackNormalFile", _olua_fun_cocos2d_ui_AbstractCheckButton_getBackNormalFile);
    oluacls_func(L, "getBackPressedFile", _olua_fun_cocos2d_ui_AbstractCheckButton_getBackPressedFile);
    oluacls_func(L, "getCrossDisabledFile", _olua_fun_cocos2d_ui_AbstractCheckButton_getCrossDisabledFile);
    oluacls_func(L, "getCrossNormalFile", _olua_fun_cocos2d_ui_AbstractCheckButton_getCrossNormalFile);
    oluacls_func(L, "getRendererBackground", _olua_fun_cocos2d_ui_AbstractCheckButton_getRendererBackground);
    oluacls_func(L, "getRendererBackgroundDisabled", _olua_fun_cocos2d_ui_AbstractCheckButton_getRendererBackgroundDisabled);
    oluacls_func(L, "getRendererBackgroundSelected", _olua_fun_cocos2d_ui_AbstractCheckButton_getRendererBackgroundSelected);
    oluacls_func(L, "getRendererFrontCross", _olua_fun_cocos2d_ui_AbstractCheckButton_getRendererFrontCross);
    oluacls_func(L, "getRendererFrontCrossDisabled", _olua_fun_cocos2d_ui_AbstractCheckButton_getRendererFrontCrossDisabled);
    oluacls_func(L, "getZoomScale", _olua_fun_cocos2d_ui_AbstractCheckButton_getZoomScale);
    oluacls_func(L, "init", _olua_fun_cocos2d_ui_AbstractCheckButton_init);
    oluacls_func(L, "isSelected", _olua_fun_cocos2d_ui_AbstractCheckButton_isSelected);
    oluacls_func(L, "loadTextureBackGround", _olua_fun_cocos2d_ui_AbstractCheckButton_loadTextureBackGround);
    oluacls_func(L, "loadTextureBackGroundDisabled", _olua_fun_cocos2d_ui_AbstractCheckButton_loadTextureBackGroundDisabled);
    oluacls_func(L, "loadTextureBackGroundSelected", _olua_fun_cocos2d_ui_AbstractCheckButton_loadTextureBackGroundSelected);
    oluacls_func(L, "loadTextureFrontCross", _olua_fun_cocos2d_ui_AbstractCheckButton_loadTextureFrontCross);
    oluacls_func(L, "loadTextureFrontCrossDisabled", _olua_fun_cocos2d_ui_AbstractCheckButton_loadTextureFrontCrossDisabled);
    oluacls_func(L, "loadTextures", _olua_fun_cocos2d_ui_AbstractCheckButton_loadTextures);
    oluacls_func(L, "setSelected", _olua_fun_cocos2d_ui_AbstractCheckButton_setSelected);
    oluacls_func(L, "setZoomScale", _olua_fun_cocos2d_ui_AbstractCheckButton_setZoomScale);
    oluacls_prop(L, "backDisabledFile", _olua_fun_cocos2d_ui_AbstractCheckButton_getBackDisabledFile, nullptr);
    oluacls_prop(L, "backNormalFile", _olua_fun_cocos2d_ui_AbstractCheckButton_getBackNormalFile, nullptr);
    oluacls_prop(L, "backPressedFile", _olua_fun_cocos2d_ui_AbstractCheckButton_getBackPressedFile, nullptr);
    oluacls_prop(L, "crossDisabledFile", _olua_fun_cocos2d_ui_AbstractCheckButton_getCrossDisabledFile, nullptr);
    oluacls_prop(L, "crossNormalFile", _olua_fun_cocos2d_ui_AbstractCheckButton_getCrossNormalFile, nullptr);
    oluacls_prop(L, "rendererBackground", _olua_fun_cocos2d_ui_AbstractCheckButton_getRendererBackground, nullptr);
    oluacls_prop(L, "rendererBackgroundDisabled", _olua_fun_cocos2d_ui_AbstractCheckButton_getRendererBackgroundDisabled, nullptr);
    oluacls_prop(L, "rendererBackgroundSelected", _olua_fun_cocos2d_ui_AbstractCheckButton_getRendererBackgroundSelected, nullptr);
    oluacls_prop(L, "rendererFrontCross", _olua_fun_cocos2d_ui_AbstractCheckButton_getRendererFrontCross, nullptr);
    oluacls_prop(L, "rendererFrontCrossDisabled", _olua_fun_cocos2d_ui_AbstractCheckButton_getRendererFrontCrossDisabled, nullptr);
    oluacls_prop(L, "selected", _olua_fun_cocos2d_ui_AbstractCheckButton_isSelected, _olua_fun_cocos2d_ui_AbstractCheckButton_setSelected);
    oluacls_prop(L, "zoomScale", _olua_fun_cocos2d_ui_AbstractCheckButton_getZoomScale, _olua_fun_cocos2d_ui_AbstractCheckButton_setZoomScale);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_AbstractCheckButton(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.AbstractCheckButton")) {
        luaL_error(L, "class not found: cocos2d::ui::AbstractCheckButton");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_ccui_TabHeader_EventType(lua_State *L)
{
    oluacls_class<cocos2d::ui::TabHeader::EventType>(L, "ccui.TabHeader.EventType");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "SELECTED", (lua_Integer)cocos2d::ui::TabHeader::EventType::SELECTED);
    oluacls_enum(L, "UNSELECTED", (lua_Integer)cocos2d::ui::TabHeader::EventType::UNSELECTED);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_TabHeader_EventType(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.TabHeader.EventType")) {
        luaL_error(L, "class not found: cocos2d::ui::TabHeader::EventType");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_ui_TabHeader_create$1(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::ui::TabHeader *create()
    cocos2d::ui::TabHeader *ret = cocos2d::ui::TabHeader::create();
    int num_ret = olua_push_object(L, ret, "ccui.TabHeader");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_TabHeader_create$2(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** titleStr */
    std::string arg2;       /** backGround */
    std::string arg3;       /** cross */
    cocos2d::ui::Widget::TextureResType arg4 = (cocos2d::ui::Widget::TextureResType)0;       /** texType */

    olua_check_string(L, 1, &arg1);
    olua_check_string(L, 2, &arg2);
    olua_check_string(L, 3, &arg3);
    olua_check_enum(L, 4, &arg4);

    // static cocos2d::ui::TabHeader *create(const std::string &titleStr, const std::string &backGround, const std::string &cross, @optional cocos2d::ui::Widget::TextureResType texType)
    cocos2d::ui::TabHeader *ret = cocos2d::ui::TabHeader::create(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_object(L, ret, "ccui.TabHeader");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_TabHeader_create$3(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** titleStr */
    std::string arg2;       /** backGround */
    std::string arg3;       /** cross */

    olua_check_string(L, 1, &arg1);
    olua_check_string(L, 2, &arg2);
    olua_check_string(L, 3, &arg3);

    // static cocos2d::ui::TabHeader *create(const std::string &titleStr, const std::string &backGround, const std::string &cross)
    cocos2d::ui::TabHeader *ret = cocos2d::ui::TabHeader::create(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "ccui.TabHeader");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_TabHeader_create$4(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** titleStr */
    std::string arg2;       /** backGround */
    std::string arg3;       /** backGroundSelected */
    std::string arg4;       /** cross */
    std::string arg5;       /** backGroundDisabled */
    std::string arg6;       /** frontCrossDisabled */
    cocos2d::ui::Widget::TextureResType arg7 = (cocos2d::ui::Widget::TextureResType)0;       /** texType */

    olua_check_string(L, 1, &arg1);
    olua_check_string(L, 2, &arg2);
    olua_check_string(L, 3, &arg3);
    olua_check_string(L, 4, &arg4);
    olua_check_string(L, 5, &arg5);
    olua_check_string(L, 6, &arg6);
    olua_check_enum(L, 7, &arg7);

    // static cocos2d::ui::TabHeader *create(const std::string &titleStr, const std::string &backGround, const std::string &backGroundSelected, const std::string &cross, const std::string &backGroundDisabled, const std::string &frontCrossDisabled, @optional cocos2d::ui::Widget::TextureResType texType)
    cocos2d::ui::TabHeader *ret = cocos2d::ui::TabHeader::create(arg1, arg2, arg3, arg4, arg5, arg6, arg7);
    int num_ret = olua_push_object(L, ret, "ccui.TabHeader");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_TabHeader_create$5(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** titleStr */
    std::string arg2;       /** backGround */
    std::string arg3;       /** backGroundSelected */
    std::string arg4;       /** cross */
    std::string arg5;       /** backGroundDisabled */
    std::string arg6;       /** frontCrossDisabled */

    olua_check_string(L, 1, &arg1);
    olua_check_string(L, 2, &arg2);
    olua_check_string(L, 3, &arg3);
    olua_check_string(L, 4, &arg4);
    olua_check_string(L, 5, &arg5);
    olua_check_string(L, 6, &arg6);

    // static cocos2d::ui::TabHeader *create(const std::string &titleStr, const std::string &backGround, const std::string &backGroundSelected, const std::string &cross, const std::string &backGroundDisabled, const std::string &frontCrossDisabled)
    cocos2d::ui::TabHeader *ret = cocos2d::ui::TabHeader::create(arg1, arg2, arg3, arg4, arg5, arg6);
    int num_ret = olua_push_object(L, ret, "ccui.TabHeader");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_TabHeader_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // static cocos2d::ui::TabHeader *create()
        return _olua_fun_cocos2d_ui_TabHeader_create$1(L);
    }

    if (num_args == 3) {
        // if ((olua_is_string(L, 1)) && (olua_is_string(L, 2)) && (olua_is_string(L, 3))) {
            // static cocos2d::ui::TabHeader *create(const std::string &titleStr, const std::string &backGround, const std::string &cross)
            return _olua_fun_cocos2d_ui_TabHeader_create$3(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_string(L, 1)) && (olua_is_string(L, 2)) && (olua_is_string(L, 3)) && (olua_is_enum(L, 4))) {
            // static cocos2d::ui::TabHeader *create(const std::string &titleStr, const std::string &backGround, const std::string &cross, @optional cocos2d::ui::Widget::TextureResType texType)
            return _olua_fun_cocos2d_ui_TabHeader_create$2(L);
        // }
    }

    if (num_args == 6) {
        // if ((olua_is_string(L, 1)) && (olua_is_string(L, 2)) && (olua_is_string(L, 3)) && (olua_is_string(L, 4)) && (olua_is_string(L, 5)) && (olua_is_string(L, 6))) {
            // static cocos2d::ui::TabHeader *create(const std::string &titleStr, const std::string &backGround, const std::string &backGroundSelected, const std::string &cross, const std::string &backGroundDisabled, const std::string &frontCrossDisabled)
            return _olua_fun_cocos2d_ui_TabHeader_create$5(L);
        // }
    }

    if (num_args == 7) {
        // if ((olua_is_string(L, 1)) && (olua_is_string(L, 2)) && (olua_is_string(L, 3)) && (olua_is_string(L, 4)) && (olua_is_string(L, 5)) && (olua_is_string(L, 6)) && (olua_is_enum(L, 7))) {
            // static cocos2d::ui::TabHeader *create(const std::string &titleStr, const std::string &backGround, const std::string &backGroundSelected, const std::string &cross, const std::string &backGroundDisabled, const std::string &frontCrossDisabled, @optional cocos2d::ui::Widget::TextureResType texType)
            return _olua_fun_cocos2d_ui_TabHeader_create$4(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::TabHeader::create' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_TabHeader_getIndexInTabControl(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TabHeader *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.TabHeader");

    // int getIndexInTabControl()
    int ret = self->getIndexInTabControl();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_TabHeader_getTitleColor(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TabHeader *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.TabHeader");

    // const cocos2d::Color4B &getTitleColor()
    const cocos2d::Color4B &ret = self->getTitleColor();
    int num_ret = olua_push_cocos2d_Color4B(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_TabHeader_getTitleFontName(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TabHeader *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.TabHeader");

    // std::string getTitleFontName()
    std::string ret = self->getTitleFontName();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_TabHeader_getTitleFontSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TabHeader *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.TabHeader");

    // float getTitleFontSize()
    float ret = self->getTitleFontSize();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_TabHeader_getTitleRenderer(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TabHeader *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.TabHeader");

    // @addref(protectedChildren |) cocos2d::Label *getTitleRenderer()
    cocos2d::Label *ret = self->getTitleRenderer();
    int num_ret = olua_push_object(L, ret, "cc.Label");

    // insert code after call
    olua_addref(L, 1, "protectedChildren", -1, OLUA_REF_MULTI);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_TabHeader_getTitleText(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TabHeader *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.TabHeader");

    // std::string getTitleText()
    std::string ret = self->getTitleText();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_TabHeader_setTitleColor(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TabHeader *self = nullptr;
    cocos2d::Color4B arg1;       /** color */

    olua_to_object(L, 1, &self, "ccui.TabHeader");
    olua_check_cocos2d_Color4B(L, 2, &arg1);

    // void setTitleColor(const cocos2d::Color4B &color)
    self->setTitleColor(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_TabHeader_setTitleFontName(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TabHeader *self = nullptr;
    std::string arg1;       /** fontName */

    olua_to_object(L, 1, &self, "ccui.TabHeader");
    olua_check_string(L, 2, &arg1);

    // void setTitleFontName(const std::string &fontName)
    self->setTitleFontName(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_TabHeader_setTitleFontSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TabHeader *self = nullptr;
    float arg1 = 0;       /** size */

    olua_to_object(L, 1, &self, "ccui.TabHeader");
    olua_check_number(L, 2, &arg1);

    // void setTitleFontSize(float size)
    self->setTitleFontSize(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_TabHeader_setTitleText(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TabHeader *self = nullptr;
    std::string arg1;       /** text */

    olua_to_object(L, 1, &self, "ccui.TabHeader");
    olua_check_string(L, 2, &arg1);

    // void setTitleText(const std::string &text)
    self->setTitleText(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_cls_ccui_TabHeader(lua_State *L)
{
    oluacls_class<cocos2d::ui::TabHeader, cocos2d::ui::AbstractCheckButton>(L, "ccui.TabHeader");
    oluacls_func(L, "create", _olua_fun_cocos2d_ui_TabHeader_create);
    oluacls_func(L, "getIndexInTabControl", _olua_fun_cocos2d_ui_TabHeader_getIndexInTabControl);
    oluacls_func(L, "getTitleColor", _olua_fun_cocos2d_ui_TabHeader_getTitleColor);
    oluacls_func(L, "getTitleFontName", _olua_fun_cocos2d_ui_TabHeader_getTitleFontName);
    oluacls_func(L, "getTitleFontSize", _olua_fun_cocos2d_ui_TabHeader_getTitleFontSize);
    oluacls_func(L, "getTitleRenderer", _olua_fun_cocos2d_ui_TabHeader_getTitleRenderer);
    oluacls_func(L, "getTitleText", _olua_fun_cocos2d_ui_TabHeader_getTitleText);
    oluacls_func(L, "setTitleColor", _olua_fun_cocos2d_ui_TabHeader_setTitleColor);
    oluacls_func(L, "setTitleFontName", _olua_fun_cocos2d_ui_TabHeader_setTitleFontName);
    oluacls_func(L, "setTitleFontSize", _olua_fun_cocos2d_ui_TabHeader_setTitleFontSize);
    oluacls_func(L, "setTitleText", _olua_fun_cocos2d_ui_TabHeader_setTitleText);
    oluacls_prop(L, "indexInTabControl", _olua_fun_cocos2d_ui_TabHeader_getIndexInTabControl, nullptr);
    oluacls_prop(L, "titleColor", _olua_fun_cocos2d_ui_TabHeader_getTitleColor, _olua_fun_cocos2d_ui_TabHeader_setTitleColor);
    oluacls_prop(L, "titleFontName", _olua_fun_cocos2d_ui_TabHeader_getTitleFontName, _olua_fun_cocos2d_ui_TabHeader_setTitleFontName);
    oluacls_prop(L, "titleFontSize", _olua_fun_cocos2d_ui_TabHeader_getTitleFontSize, _olua_fun_cocos2d_ui_TabHeader_setTitleFontSize);
    oluacls_prop(L, "titleRenderer", _olua_fun_cocos2d_ui_TabHeader_getTitleRenderer, nullptr);
    oluacls_prop(L, "titleText", _olua_fun_cocos2d_ui_TabHeader_getTitleText, _olua_fun_cocos2d_ui_TabHeader_setTitleText);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_TabHeader(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.TabHeader")) {
        luaL_error(L, "class not found: cocos2d::ui::TabHeader");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_ccui_TabControl_Dock(lua_State *L)
{
    oluacls_class<cocos2d::ui::TabControl::Dock>(L, "ccui.TabControl.Dock");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "BOTTOM", (lua_Integer)cocos2d::ui::TabControl::Dock::BOTTOM);
    oluacls_enum(L, "LEFT", (lua_Integer)cocos2d::ui::TabControl::Dock::LEFT);
    oluacls_enum(L, "RIGHT", (lua_Integer)cocos2d::ui::TabControl::Dock::RIGHT);
    oluacls_enum(L, "TOP", (lua_Integer)cocos2d::ui::TabControl::Dock::TOP);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_TabControl_Dock(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.TabControl.Dock")) {
        luaL_error(L, "class not found: cocos2d::ui::TabControl::Dock");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_ccui_TabControl_EventType(lua_State *L)
{
    oluacls_class<cocos2d::ui::TabControl::EventType>(L, "ccui.TabControl.EventType");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "SELECT_CHANGED", (lua_Integer)cocos2d::ui::TabControl::EventType::SELECT_CHANGED);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_TabControl_EventType(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.TabControl.EventType")) {
        luaL_error(L, "class not found: cocos2d::ui::TabControl::EventType");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_ui_TabControl_ccTabControlCallback___call(lua_State *L)
{
    olua_startinvoke(L);

    luaL_checktype(L, -1, LUA_TFUNCTION);
    olua_push_callback(L, (cocos2d::ui::TabControl::ccTabControlCallback *)nullptr, "ccui.TabControl.ccTabControlCallback");

    olua_endinvoke(L);

    return 1;
}

static int _olua_cls_ccui_TabControl_ccTabControlCallback(lua_State *L)
{
    oluacls_class<cocos2d::ui::TabControl::ccTabControlCallback>(L, "ccui.TabControl.ccTabControlCallback");
    oluacls_func(L, "__call", _olua_fun_cocos2d_ui_TabControl_ccTabControlCallback___call);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_TabControl_ccTabControlCallback(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.TabControl.ccTabControlCallback")) {
        luaL_error(L, "class not found: cocos2d::ui::TabControl::ccTabControlCallback");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_ui_TabControl_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::ui::TabControl *create()
    cocos2d::ui::TabControl *ret = cocos2d::ui::TabControl::create();
    int num_ret = olua_push_object(L, ret, "ccui.TabControl");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_TabControl_getHeaderDockPlace(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TabControl *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.TabControl");

    // cocos2d::ui::TabControl::Dock getHeaderDockPlace()
    cocos2d::ui::TabControl::Dock ret = self->getHeaderDockPlace();
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_TabControl_getHeaderHeight(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TabControl *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.TabControl");

    // int getHeaderHeight()
    int ret = self->getHeaderHeight();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_TabControl_getHeaderSelectedZoom(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TabControl *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.TabControl");

    // float getHeaderSelectedZoom()
    float ret = self->getHeaderSelectedZoom();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_TabControl_getHeaderWidth(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TabControl *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.TabControl");

    // float getHeaderWidth()
    float ret = self->getHeaderWidth();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_TabControl_getSelectedTabIndex(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TabControl *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.TabControl");

    // int getSelectedTabIndex()
    int ret = self->getSelectedTabIndex();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_TabControl_getTabContainer(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TabControl *self = nullptr;
    int arg1 = 0;       /** index */

    olua_to_object(L, 1, &self, "ccui.TabControl");
    olua_check_integer(L, 2, &arg1);

    // @addref(protectedChildren |) cocos2d::ui::Layout *getTabContainer(int index)
    cocos2d::ui::Layout *ret = self->getTabContainer(arg1);
    int num_ret = olua_push_object(L, ret, "ccui.Layout");

    // insert code after call
    olua_addref(L, 1, "protectedChildren", -1, OLUA_REF_MULTI);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_TabControl_getTabCount(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TabControl *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.TabControl");

    // size_t getTabCount()
    size_t ret = self->getTabCount();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_TabControl_getTabHeader(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TabControl *self = nullptr;
    int arg1 = 0;       /** index */

    olua_to_object(L, 1, &self, "ccui.TabControl");
    olua_check_integer(L, 2, &arg1);

    // @addref(protectedChildren |) cocos2d::ui::TabHeader *getTabHeader(int index)
    cocos2d::ui::TabHeader *ret = self->getTabHeader(arg1);
    int num_ret = olua_push_object(L, ret, "ccui.TabHeader");

    // insert code after call
    olua_addref(L, 1, "protectedChildren", -1, OLUA_REF_MULTI);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_TabControl_ignoreHeadersTextureSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TabControl *self = nullptr;
    bool arg1 = false;       /** ignore */

    olua_to_object(L, 1, &self, "ccui.TabControl");
    olua_check_bool(L, 2, &arg1);

    // void ignoreHeadersTextureSize(bool ignore)
    self->ignoreHeadersTextureSize(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_TabControl_indexOfTabHeader(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TabControl *self = nullptr;
    cocos2d::ui::TabHeader *arg1 = nullptr;       /** tabCell */

    olua_to_object(L, 1, &self, "ccui.TabControl");
    olua_check_object(L, 2, &arg1, "ccui.TabHeader");

    // int indexOfTabHeader(const cocos2d::ui::TabHeader *tabCell)
    int ret = self->indexOfTabHeader(arg1);
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_TabControl_insertTab(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TabControl *self = nullptr;
    int arg1 = 0;       /** index */
    cocos2d::ui::TabHeader *arg2 = nullptr;       /** header */
    cocos2d::ui::Layout *arg3 = nullptr;       /** container */

    olua_to_object(L, 1, &self, "ccui.TabControl");
    olua_check_integer(L, 2, &arg1);
    olua_check_object(L, 3, &arg2, "ccui.TabHeader");
    olua_check_object(L, 4, &arg3, "ccui.Layout");

    // void insertTab(int index, @addref(protectedChildren |) cocos2d::ui::TabHeader *header, @addref(protectedChildren |) cocos2d::ui::Layout *container)
    self->insertTab(arg1, arg2, arg3);

    // insert code after call
    olua_addref(L, 1, "protectedChildren", 3, OLUA_REF_MULTI);
    olua_addref(L, 1, "protectedChildren", 4, OLUA_REF_MULTI);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_TabControl_isIgnoreHeadersTextureSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TabControl *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.TabControl");

    // bool isIgnoreHeadersTextureSize()
    bool ret = self->isIgnoreHeadersTextureSize();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_TabControl_removeTab(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TabControl *self = nullptr;
    int arg1 = 0;       /** index */

    olua_to_object(L, 1, &self, "ccui.TabControl");
    olua_check_integer(L, 2, &arg1);

    // insert code before call
    olua_startcmpref(L, 1, "protectedChildren");

    // @delref(protectedChildren ~) void removeTab(int index)
    self->removeTab(arg1);

    // insert code after call
    olua_endcmpref(L, 1, "protectedChildren");

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_TabControl_setHeaderDockPlace(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TabControl *self = nullptr;
    cocos2d::ui::TabControl::Dock arg1 = (cocos2d::ui::TabControl::Dock)0;       /** dockPlace */

    olua_to_object(L, 1, &self, "ccui.TabControl");
    olua_check_enum(L, 2, &arg1);

    // void setHeaderDockPlace(cocos2d::ui::TabControl::Dock dockPlace)
    self->setHeaderDockPlace(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_TabControl_setHeaderHeight(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TabControl *self = nullptr;
    float arg1 = 0;       /** headerHeight */

    olua_to_object(L, 1, &self, "ccui.TabControl");
    olua_check_number(L, 2, &arg1);

    // void setHeaderHeight(float headerHeight)
    self->setHeaderHeight(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_TabControl_setHeaderSelectedZoom(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TabControl *self = nullptr;
    float arg1 = 0;       /** zoom */

    olua_to_object(L, 1, &self, "ccui.TabControl");
    olua_check_number(L, 2, &arg1);

    // void setHeaderSelectedZoom(float zoom)
    self->setHeaderSelectedZoom(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_TabControl_setHeaderWidth(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TabControl *self = nullptr;
    float arg1 = 0;       /** headerWidth */

    olua_to_object(L, 1, &self, "ccui.TabControl");
    olua_check_number(L, 2, &arg1);

    // void setHeaderWidth(float headerWidth)
    self->setHeaderWidth(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_TabControl_setSelectTab$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TabControl *self = nullptr;
    int arg1 = 0;       /** index */

    olua_to_object(L, 1, &self, "ccui.TabControl");
    olua_check_integer(L, 2, &arg1);

    // void setSelectTab(int index)
    self->setSelectTab(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_TabControl_setSelectTab$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TabControl *self = nullptr;
    cocos2d::ui::TabHeader *arg1 = nullptr;       /** tabHeader */

    olua_to_object(L, 1, &self, "ccui.TabControl");
    olua_check_object(L, 2, &arg1, "ccui.TabHeader");

    // void setSelectTab(cocos2d::ui::TabHeader *tabHeader)
    self->setSelectTab(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_TabControl_setSelectTab(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        if ((olua_is_object(L, 1, "ccui.TabControl")) && (olua_is_integer(L, 2))) {
            // void setSelectTab(int index)
            return _olua_fun_cocos2d_ui_TabControl_setSelectTab$1(L);
        }

        // if ((olua_is_object(L, 1, "ccui.TabControl")) && (olua_is_object(L, 2, "ccui.TabHeader"))) {
            // void setSelectTab(cocos2d::ui::TabHeader *tabHeader)
            return _olua_fun_cocos2d_ui_TabControl_setSelectTab$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::TabControl::setSelectTab' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_TabControl_setTabChangedEventListener(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TabControl *self = nullptr;
    cocos2d::ui::TabControl::ccTabControlCallback arg1;       /** callback */

    olua_to_object(L, 1, &self, "ccui.TabControl");
    if (!olua_isnoneornil(L, 2)) {
        olua_check_callback(L, 2, &arg1, "ccui.TabControl.ccTabControlCallback");
    }

    void *cb_store = (void *)self;
    std::string cb_tag = "tabChangedEventListener";
    std::string cb_name;
    if (olua_isfunction(L, 2)) {
        cb_name = olua_setcallback(L, cb_store, 2, cb_tag.c_str(), OLUA_TAG_REPLACE);
        olua_Context cb_ctx = olua_context(L);
        // lua_State *ML = olua_mainthread(L);
        arg1 = [cb_store, cb_name, cb_ctx /*, ML */](int cb_arg1, cocos2d::ui::TabControl::EventType cb_arg2) {
            lua_State *L = olua_mainthread(NULL);
            olua_checkhostthread();

            if (olua_contextequal(L, cb_ctx)) {
                int top = lua_gettop(L);
                olua_push_integer(L, cb_arg1);
                olua_push_enum(L, cb_arg2);

                olua_callback(L, cb_store, cb_name.c_str(), 2);

                lua_settop(L, top);
            }
        };
    } else {
        olua_removecallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_EQUAL);
        arg1 = nullptr;
    }

    // void setTabChangedEventListener(@nullable const cocos2d::ui::TabControl::ccTabControlCallback &callback)
    self->setTabChangedEventListener(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_cls_ccui_TabControl(lua_State *L)
{
    oluacls_class<cocos2d::ui::TabControl, cocos2d::ui::Widget>(L, "ccui.TabControl");
    oluacls_func(L, "create", _olua_fun_cocos2d_ui_TabControl_create);
    oluacls_func(L, "getHeaderDockPlace", _olua_fun_cocos2d_ui_TabControl_getHeaderDockPlace);
    oluacls_func(L, "getHeaderHeight", _olua_fun_cocos2d_ui_TabControl_getHeaderHeight);
    oluacls_func(L, "getHeaderSelectedZoom", _olua_fun_cocos2d_ui_TabControl_getHeaderSelectedZoom);
    oluacls_func(L, "getHeaderWidth", _olua_fun_cocos2d_ui_TabControl_getHeaderWidth);
    oluacls_func(L, "getSelectedTabIndex", _olua_fun_cocos2d_ui_TabControl_getSelectedTabIndex);
    oluacls_func(L, "getTabContainer", _olua_fun_cocos2d_ui_TabControl_getTabContainer);
    oluacls_func(L, "getTabCount", _olua_fun_cocos2d_ui_TabControl_getTabCount);
    oluacls_func(L, "getTabHeader", _olua_fun_cocos2d_ui_TabControl_getTabHeader);
    oluacls_func(L, "ignoreHeadersTextureSize", _olua_fun_cocos2d_ui_TabControl_ignoreHeadersTextureSize);
    oluacls_func(L, "indexOfTabHeader", _olua_fun_cocos2d_ui_TabControl_indexOfTabHeader);
    oluacls_func(L, "insertTab", _olua_fun_cocos2d_ui_TabControl_insertTab);
    oluacls_func(L, "isIgnoreHeadersTextureSize", _olua_fun_cocos2d_ui_TabControl_isIgnoreHeadersTextureSize);
    oluacls_func(L, "removeTab", _olua_fun_cocos2d_ui_TabControl_removeTab);
    oluacls_func(L, "setHeaderDockPlace", _olua_fun_cocos2d_ui_TabControl_setHeaderDockPlace);
    oluacls_func(L, "setHeaderHeight", _olua_fun_cocos2d_ui_TabControl_setHeaderHeight);
    oluacls_func(L, "setHeaderSelectedZoom", _olua_fun_cocos2d_ui_TabControl_setHeaderSelectedZoom);
    oluacls_func(L, "setHeaderWidth", _olua_fun_cocos2d_ui_TabControl_setHeaderWidth);
    oluacls_func(L, "setSelectTab", _olua_fun_cocos2d_ui_TabControl_setSelectTab);
    oluacls_func(L, "setTabChangedEventListener", _olua_fun_cocos2d_ui_TabControl_setTabChangedEventListener);
    oluacls_prop(L, "headerDockPlace", _olua_fun_cocos2d_ui_TabControl_getHeaderDockPlace, _olua_fun_cocos2d_ui_TabControl_setHeaderDockPlace);
    oluacls_prop(L, "headerHeight", _olua_fun_cocos2d_ui_TabControl_getHeaderHeight, _olua_fun_cocos2d_ui_TabControl_setHeaderHeight);
    oluacls_prop(L, "headerSelectedZoom", _olua_fun_cocos2d_ui_TabControl_getHeaderSelectedZoom, _olua_fun_cocos2d_ui_TabControl_setHeaderSelectedZoom);
    oluacls_prop(L, "headerWidth", _olua_fun_cocos2d_ui_TabControl_getHeaderWidth, _olua_fun_cocos2d_ui_TabControl_setHeaderWidth);
    oluacls_prop(L, "selectedTabIndex", _olua_fun_cocos2d_ui_TabControl_getSelectedTabIndex, nullptr);
    oluacls_prop(L, "tabCount", _olua_fun_cocos2d_ui_TabControl_getTabCount, nullptr);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_TabControl(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.TabControl")) {
        luaL_error(L, "class not found: cocos2d::ui::TabControl");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_ccui_ScrollView_Direction(lua_State *L)
{
    oluacls_class<cocos2d::ui::ScrollView::Direction>(L, "ccui.ScrollView.Direction");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "BOTH", (lua_Integer)cocos2d::ui::ScrollView::Direction::BOTH);
    oluacls_enum(L, "HORIZONTAL", (lua_Integer)cocos2d::ui::ScrollView::Direction::HORIZONTAL);
    oluacls_enum(L, "NONE", (lua_Integer)cocos2d::ui::ScrollView::Direction::NONE);
    oluacls_enum(L, "VERTICAL", (lua_Integer)cocos2d::ui::ScrollView::Direction::VERTICAL);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_ScrollView_Direction(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.ScrollView.Direction")) {
        luaL_error(L, "class not found: cocos2d::ui::ScrollView::Direction");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_ccui_ScrollView_EventType(lua_State *L)
{
    oluacls_class<cocos2d::ui::ScrollView::EventType>(L, "ccui.ScrollView.EventType");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "AUTOSCROLL_ENDED", (lua_Integer)cocos2d::ui::ScrollView::EventType::AUTOSCROLL_ENDED);
    oluacls_enum(L, "BOUNCE_BOTTOM", (lua_Integer)cocos2d::ui::ScrollView::EventType::BOUNCE_BOTTOM);
    oluacls_enum(L, "BOUNCE_LEFT", (lua_Integer)cocos2d::ui::ScrollView::EventType::BOUNCE_LEFT);
    oluacls_enum(L, "BOUNCE_RIGHT", (lua_Integer)cocos2d::ui::ScrollView::EventType::BOUNCE_RIGHT);
    oluacls_enum(L, "BOUNCE_TOP", (lua_Integer)cocos2d::ui::ScrollView::EventType::BOUNCE_TOP);
    oluacls_enum(L, "CONTAINER_MOVED", (lua_Integer)cocos2d::ui::ScrollView::EventType::CONTAINER_MOVED);
    oluacls_enum(L, "SCROLLING", (lua_Integer)cocos2d::ui::ScrollView::EventType::SCROLLING);
    oluacls_enum(L, "SCROLLING_BEGAN", (lua_Integer)cocos2d::ui::ScrollView::EventType::SCROLLING_BEGAN);
    oluacls_enum(L, "SCROLLING_ENDED", (lua_Integer)cocos2d::ui::ScrollView::EventType::SCROLLING_ENDED);
    oluacls_enum(L, "SCROLL_TO_BOTTOM", (lua_Integer)cocos2d::ui::ScrollView::EventType::SCROLL_TO_BOTTOM);
    oluacls_enum(L, "SCROLL_TO_LEFT", (lua_Integer)cocos2d::ui::ScrollView::EventType::SCROLL_TO_LEFT);
    oluacls_enum(L, "SCROLL_TO_RIGHT", (lua_Integer)cocos2d::ui::ScrollView::EventType::SCROLL_TO_RIGHT);
    oluacls_enum(L, "SCROLL_TO_TOP", (lua_Integer)cocos2d::ui::ScrollView::EventType::SCROLL_TO_TOP);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_ScrollView_EventType(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.ScrollView.EventType")) {
        luaL_error(L, "class not found: cocos2d::ui::ScrollView::EventType");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_ui_ScrollView_ccScrollViewCallback___call(lua_State *L)
{
    olua_startinvoke(L);

    luaL_checktype(L, -1, LUA_TFUNCTION);
    olua_push_callback(L, (cocos2d::ui::ScrollView::ccScrollViewCallback *)nullptr, "ccui.ScrollView.ccScrollViewCallback");

    olua_endinvoke(L);

    return 1;
}

static int _olua_cls_ccui_ScrollView_ccScrollViewCallback(lua_State *L)
{
    oluacls_class<cocos2d::ui::ScrollView::ccScrollViewCallback>(L, "ccui.ScrollView.ccScrollViewCallback");
    oluacls_func(L, "__call", _olua_fun_cocos2d_ui_ScrollView_ccScrollViewCallback___call);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_ScrollView_ccScrollViewCallback(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.ScrollView.ccScrollViewCallback")) {
        luaL_error(L, "class not found: cocos2d::ui::ScrollView::ccScrollViewCallback");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_ui_ScrollView_addEventListener(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;
    cocos2d::ui::ScrollView::ccScrollViewCallback arg1;       /** callback */

    olua_to_object(L, 1, &self, "ccui.ScrollView");
    olua_check_callback(L, 2, &arg1, "ccui.ScrollView.ccScrollViewCallback");

    void *cb_store = (void *)self;
    std::string cb_tag = "scrollViewCallback";
    std::string cb_name = olua_setcallback(L, cb_store, 2, cb_tag.c_str(), OLUA_TAG_REPLACE);
    olua_Context cb_ctx = olua_context(L);
    // lua_State *ML = olua_mainthread(L);
    arg1 = [cb_store, cb_name, cb_ctx /*, ML */](cocos2d::Ref *cb_arg1, cocos2d::ui::ScrollView::EventType cb_arg2) {
        lua_State *L = olua_mainthread(NULL);
        olua_checkhostthread();

        if (olua_contextequal(L, cb_ctx)) {
            int top = lua_gettop(L);
            olua_push_object(L, cb_arg1, "cc.Ref");
            olua_push_enum(L, cb_arg2);

            olua_callback(L, cb_store, cb_name.c_str(), 2);

            lua_settop(L, top);
        }
    };

    // void addEventListener(const cocos2d::ui::ScrollView::ccScrollViewCallback &callback)
    self->addEventListener(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_ScrollView_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::ui::ScrollView *create()
    cocos2d::ui::ScrollView *ret = cocos2d::ui::ScrollView::create();
    int num_ret = olua_push_object(L, ret, "ccui.ScrollView");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_ScrollView_createInstance(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::Ref *createInstance()
    cocos2d::Ref *ret = cocos2d::ui::ScrollView::createInstance();
    int num_ret = olua_push_object(L, ret, "cc.Ref");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_ScrollView_getDirection(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.ScrollView");

    // cocos2d::ui::ScrollView::Direction getDirection()
    cocos2d::ui::ScrollView::Direction ret = self->getDirection();
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_ScrollView_getInnerContainer(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.ScrollView");

    // @addref(protectedChildren |) cocos2d::ui::Layout *getInnerContainer()
    cocos2d::ui::Layout *ret = self->getInnerContainer();
    int num_ret = olua_push_object(L, ret, "ccui.Layout");

    // insert code after call
    olua_addref(L, 1, "protectedChildren", -1, OLUA_REF_MULTI);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_ScrollView_getInnerContainerPosition(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.ScrollView");

    // const cocos2d::Vec2 &getInnerContainerPosition()
    const cocos2d::Vec2 &ret = self->getInnerContainerPosition();
    int num_ret = olua_push_object(L, ret, "cc.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_ScrollView_getInnerContainerSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.ScrollView");

    // const cocos2d::Size &getInnerContainerSize()
    const cocos2d::Size &ret = self->getInnerContainerSize();
    int num_ret = olua_push_object(L, ret, "cc.Size");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_ScrollView_getScrollBarAutoHideTime(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.ScrollView");

    // float getScrollBarAutoHideTime()
    float ret = self->getScrollBarAutoHideTime();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_ScrollView_getScrollBarColor(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.ScrollView");

    // const cocos2d::Color3B &getScrollBarColor()
    const cocos2d::Color3B &ret = self->getScrollBarColor();
    int num_ret = olua_push_cocos2d_Color3B(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_ScrollView_getScrollBarOpacity(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.ScrollView");

    // uint8_t getScrollBarOpacity()
    uint8_t ret = self->getScrollBarOpacity();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_ScrollView_getScrollBarPositionFromCornerForHorizontal(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.ScrollView");

    // cocos2d::Vec2 getScrollBarPositionFromCornerForHorizontal()
    cocos2d::Vec2 ret = self->getScrollBarPositionFromCornerForHorizontal();
    int num_ret = olua_copy_object(L, ret, "cc.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_ScrollView_getScrollBarPositionFromCornerForVertical(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.ScrollView");

    // cocos2d::Vec2 getScrollBarPositionFromCornerForVertical()
    cocos2d::Vec2 ret = self->getScrollBarPositionFromCornerForVertical();
    int num_ret = olua_copy_object(L, ret, "cc.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_ScrollView_getScrollBarWidth(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.ScrollView");

    // float getScrollBarWidth()
    float ret = self->getScrollBarWidth();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_ScrollView_getScrolledPercentBothDirection(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.ScrollView");

    // cocos2d::Vec2 getScrolledPercentBothDirection()
    cocos2d::Vec2 ret = self->getScrolledPercentBothDirection();
    int num_ret = olua_copy_object(L, ret, "cc.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_ScrollView_getScrolledPercentHorizontal(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.ScrollView");

    // float getScrolledPercentHorizontal()
    float ret = self->getScrolledPercentHorizontal();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_ScrollView_getScrolledPercentVertical(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.ScrollView");

    // float getScrolledPercentVertical()
    float ret = self->getScrolledPercentVertical();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_ScrollView_getTouchTotalTimeThreshold(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.ScrollView");

    // float getTouchTotalTimeThreshold()
    float ret = self->getTouchTotalTimeThreshold();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_ScrollView_isAutoScrolling(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.ScrollView");

    // bool isAutoScrolling()
    bool ret = self->isAutoScrolling();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_ScrollView_isBounceEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.ScrollView");

    // bool isBounceEnabled()
    bool ret = self->isBounceEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_ScrollView_isInertiaScrollEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.ScrollView");

    // bool isInertiaScrollEnabled()
    bool ret = self->isInertiaScrollEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_ScrollView_isScrollBarAutoHideEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.ScrollView");

    // bool isScrollBarAutoHideEnabled()
    bool ret = self->isScrollBarAutoHideEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_ScrollView_isScrollBarEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.ScrollView");

    // bool isScrollBarEnabled()
    bool ret = self->isScrollBarEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_ScrollView_isScrolling(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.ScrollView");

    // bool isScrolling()
    bool ret = self->isScrolling();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_ScrollView_jumpToBottom(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.ScrollView");

    // void jumpToBottom()
    self->jumpToBottom();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_ScrollView_jumpToBottomLeft(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.ScrollView");

    // void jumpToBottomLeft()
    self->jumpToBottomLeft();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_ScrollView_jumpToBottomRight(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.ScrollView");

    // void jumpToBottomRight()
    self->jumpToBottomRight();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_ScrollView_jumpToLeft(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.ScrollView");

    // void jumpToLeft()
    self->jumpToLeft();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_ScrollView_jumpToPercentBothDirection(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;
    cocos2d::Vec2 *arg1;       /** percent */

    olua_to_object(L, 1, &self, "ccui.ScrollView");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // void jumpToPercentBothDirection(const cocos2d::Vec2 &percent)
    self->jumpToPercentBothDirection(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_ScrollView_jumpToPercentHorizontal(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;
    float arg1 = 0;       /** percent */

    olua_to_object(L, 1, &self, "ccui.ScrollView");
    olua_check_number(L, 2, &arg1);

    // void jumpToPercentHorizontal(float percent)
    self->jumpToPercentHorizontal(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_ScrollView_jumpToPercentVertical(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;
    float arg1 = 0;       /** percent */

    olua_to_object(L, 1, &self, "ccui.ScrollView");
    olua_check_number(L, 2, &arg1);

    // void jumpToPercentVertical(float percent)
    self->jumpToPercentVertical(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_ScrollView_jumpToRight(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.ScrollView");

    // void jumpToRight()
    self->jumpToRight();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_ScrollView_jumpToTop(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.ScrollView");

    // void jumpToTop()
    self->jumpToTop();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_ScrollView_jumpToTopLeft(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.ScrollView");

    // void jumpToTopLeft()
    self->jumpToTopLeft();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_ScrollView_jumpToTopRight(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.ScrollView");

    // void jumpToTopRight()
    self->jumpToTopRight();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_ScrollView_new(lua_State *L)
{
    olua_startinvoke(L);

    // cocos2d::ui::ScrollView()
    cocos2d::ui::ScrollView *ret = new cocos2d::ui::ScrollView();
    int num_ret = olua_push_object(L, ret, "ccui.ScrollView");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_ScrollView_scrollToBottom(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;
    float arg1 = 0;       /** timeInSec */
    bool arg2 = false;       /** attenuated */

    olua_to_object(L, 1, &self, "ccui.ScrollView");
    olua_check_number(L, 2, &arg1);
    olua_check_bool(L, 3, &arg2);

    // void scrollToBottom(float timeInSec, bool attenuated)
    self->scrollToBottom(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_ScrollView_scrollToBottomLeft(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;
    float arg1 = 0;       /** timeInSec */
    bool arg2 = false;       /** attenuated */

    olua_to_object(L, 1, &self, "ccui.ScrollView");
    olua_check_number(L, 2, &arg1);
    olua_check_bool(L, 3, &arg2);

    // void scrollToBottomLeft(float timeInSec, bool attenuated)
    self->scrollToBottomLeft(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_ScrollView_scrollToBottomRight(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;
    float arg1 = 0;       /** timeInSec */
    bool arg2 = false;       /** attenuated */

    olua_to_object(L, 1, &self, "ccui.ScrollView");
    olua_check_number(L, 2, &arg1);
    olua_check_bool(L, 3, &arg2);

    // void scrollToBottomRight(float timeInSec, bool attenuated)
    self->scrollToBottomRight(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_ScrollView_scrollToLeft(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;
    float arg1 = 0;       /** timeInSec */
    bool arg2 = false;       /** attenuated */

    olua_to_object(L, 1, &self, "ccui.ScrollView");
    olua_check_number(L, 2, &arg1);
    olua_check_bool(L, 3, &arg2);

    // void scrollToLeft(float timeInSec, bool attenuated)
    self->scrollToLeft(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_ScrollView_scrollToPercentBothDirection(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;
    cocos2d::Vec2 *arg1;       /** percent */
    float arg2 = 0;       /** timeInSec */
    bool arg3 = false;       /** attenuated */

    olua_to_object(L, 1, &self, "ccui.ScrollView");
    olua_check_object(L, 2, &arg1, "cc.Vec2");
    olua_check_number(L, 3, &arg2);
    olua_check_bool(L, 4, &arg3);

    // void scrollToPercentBothDirection(const cocos2d::Vec2 &percent, float timeInSec, bool attenuated)
    self->scrollToPercentBothDirection(*arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_ScrollView_scrollToPercentHorizontal(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;
    float arg1 = 0;       /** percent */
    float arg2 = 0;       /** timeInSec */
    bool arg3 = false;       /** attenuated */

    olua_to_object(L, 1, &self, "ccui.ScrollView");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_bool(L, 4, &arg3);

    // void scrollToPercentHorizontal(float percent, float timeInSec, bool attenuated)
    self->scrollToPercentHorizontal(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_ScrollView_scrollToPercentVertical(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;
    float arg1 = 0;       /** percent */
    float arg2 = 0;       /** timeInSec */
    bool arg3 = false;       /** attenuated */

    olua_to_object(L, 1, &self, "ccui.ScrollView");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_bool(L, 4, &arg3);

    // void scrollToPercentVertical(float percent, float timeInSec, bool attenuated)
    self->scrollToPercentVertical(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_ScrollView_scrollToRight(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;
    float arg1 = 0;       /** timeInSec */
    bool arg2 = false;       /** attenuated */

    olua_to_object(L, 1, &self, "ccui.ScrollView");
    olua_check_number(L, 2, &arg1);
    olua_check_bool(L, 3, &arg2);

    // void scrollToRight(float timeInSec, bool attenuated)
    self->scrollToRight(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_ScrollView_scrollToTop(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;
    float arg1 = 0;       /** timeInSec */
    bool arg2 = false;       /** attenuated */

    olua_to_object(L, 1, &self, "ccui.ScrollView");
    olua_check_number(L, 2, &arg1);
    olua_check_bool(L, 3, &arg2);

    // void scrollToTop(float timeInSec, bool attenuated)
    self->scrollToTop(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_ScrollView_scrollToTopLeft(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;
    float arg1 = 0;       /** timeInSec */
    bool arg2 = false;       /** attenuated */

    olua_to_object(L, 1, &self, "ccui.ScrollView");
    olua_check_number(L, 2, &arg1);
    olua_check_bool(L, 3, &arg2);

    // void scrollToTopLeft(float timeInSec, bool attenuated)
    self->scrollToTopLeft(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_ScrollView_scrollToTopRight(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;
    float arg1 = 0;       /** timeInSec */
    bool arg2 = false;       /** attenuated */

    olua_to_object(L, 1, &self, "ccui.ScrollView");
    olua_check_number(L, 2, &arg1);
    olua_check_bool(L, 3, &arg2);

    // void scrollToTopRight(float timeInSec, bool attenuated)
    self->scrollToTopRight(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_ScrollView_setBounceEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;
    bool arg1 = false;       /** enabled */

    olua_to_object(L, 1, &self, "ccui.ScrollView");
    olua_check_bool(L, 2, &arg1);

    // void setBounceEnabled(bool enabled)
    self->setBounceEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_ScrollView_setDirection(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;
    cocos2d::ui::ScrollView::Direction arg1 = (cocos2d::ui::ScrollView::Direction)0;       /** dir */

    olua_to_object(L, 1, &self, "ccui.ScrollView");
    olua_check_enum(L, 2, &arg1);

    // void setDirection(cocos2d::ui::ScrollView::Direction dir)
    self->setDirection(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_ScrollView_setInertiaScrollEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;
    bool arg1 = false;       /** enabled */

    olua_to_object(L, 1, &self, "ccui.ScrollView");
    olua_check_bool(L, 2, &arg1);

    // void setInertiaScrollEnabled(bool enabled)
    self->setInertiaScrollEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_ScrollView_setInnerContainerPosition(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;
    cocos2d::Vec2 *arg1;       /** pos */

    olua_to_object(L, 1, &self, "ccui.ScrollView");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // void setInnerContainerPosition(const cocos2d::Vec2 &pos)
    self->setInnerContainerPosition(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_ScrollView_setInnerContainerSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;
    cocos2d::Size *arg1;       /** size */

    olua_to_object(L, 1, &self, "ccui.ScrollView");
    olua_check_object(L, 2, &arg1, "cc.Size");

    // void setInnerContainerSize(const cocos2d::Size &size)
    self->setInnerContainerSize(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_ScrollView_setScrollBarAutoHideEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;
    bool arg1 = false;       /** autoHideEnabled */

    olua_to_object(L, 1, &self, "ccui.ScrollView");
    olua_check_bool(L, 2, &arg1);

    // void setScrollBarAutoHideEnabled(bool autoHideEnabled)
    self->setScrollBarAutoHideEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_ScrollView_setScrollBarAutoHideTime(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;
    float arg1 = 0;       /** autoHideTime */

    olua_to_object(L, 1, &self, "ccui.ScrollView");
    olua_check_number(L, 2, &arg1);

    // void setScrollBarAutoHideTime(float autoHideTime)
    self->setScrollBarAutoHideTime(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_ScrollView_setScrollBarColor(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;
    cocos2d::Color3B arg1;       /** color */

    olua_to_object(L, 1, &self, "ccui.ScrollView");
    olua_check_cocos2d_Color3B(L, 2, &arg1);

    // void setScrollBarColor(const cocos2d::Color3B &color)
    self->setScrollBarColor(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_ScrollView_setScrollBarEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;
    bool arg1 = false;       /** enabled */

    olua_to_object(L, 1, &self, "ccui.ScrollView");
    olua_check_bool(L, 2, &arg1);

    // void setScrollBarEnabled(bool enabled)
    self->setScrollBarEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_ScrollView_setScrollBarOpacity(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;
    uint8_t arg1 = 0;       /** opacity */

    olua_to_object(L, 1, &self, "ccui.ScrollView");
    olua_check_integer(L, 2, &arg1);

    // void setScrollBarOpacity(uint8_t opacity)
    self->setScrollBarOpacity(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_ScrollView_setScrollBarPositionFromCorner(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;
    cocos2d::Vec2 *arg1;       /** positionFromCorner */

    olua_to_object(L, 1, &self, "ccui.ScrollView");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // void setScrollBarPositionFromCorner(const cocos2d::Vec2 &positionFromCorner)
    self->setScrollBarPositionFromCorner(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_ScrollView_setScrollBarPositionFromCornerForHorizontal(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;
    cocos2d::Vec2 *arg1;       /** positionFromCorner */

    olua_to_object(L, 1, &self, "ccui.ScrollView");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // void setScrollBarPositionFromCornerForHorizontal(const cocos2d::Vec2 &positionFromCorner)
    self->setScrollBarPositionFromCornerForHorizontal(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_ScrollView_setScrollBarPositionFromCornerForVertical(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;
    cocos2d::Vec2 *arg1;       /** positionFromCorner */

    olua_to_object(L, 1, &self, "ccui.ScrollView");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // void setScrollBarPositionFromCornerForVertical(const cocos2d::Vec2 &positionFromCorner)
    self->setScrollBarPositionFromCornerForVertical(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_ScrollView_setScrollBarWidth(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;
    float arg1 = 0;       /** width */

    olua_to_object(L, 1, &self, "ccui.ScrollView");
    olua_check_number(L, 2, &arg1);

    // void setScrollBarWidth(float width)
    self->setScrollBarWidth(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_ScrollView_setTouchTotalTimeThreshold(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;
    float arg1 = 0;       /** touchTotalTimeThreshold */

    olua_to_object(L, 1, &self, "ccui.ScrollView");
    olua_check_number(L, 2, &arg1);

    // void setTouchTotalTimeThreshold(float touchTotalTimeThreshold)
    self->setTouchTotalTimeThreshold(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_ScrollView_stopAutoScroll(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.ScrollView");

    // void stopAutoScroll()
    self->stopAutoScroll();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_ScrollView_stopOverallScroll(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.ScrollView");

    // void stopOverallScroll()
    self->stopOverallScroll();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_ScrollView_stopScroll(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.ScrollView");

    // void stopScroll()
    self->stopScroll();

    olua_endinvoke(L);

    return 0;
}

static int _olua_cls_ccui_ScrollView(lua_State *L)
{
    oluacls_class<cocos2d::ui::ScrollView, cocos2d::ui::Layout>(L, "ccui.ScrollView");
    oluacls_func(L, "addEventListener", _olua_fun_cocos2d_ui_ScrollView_addEventListener);
    oluacls_func(L, "create", _olua_fun_cocos2d_ui_ScrollView_create);
    oluacls_func(L, "createInstance", _olua_fun_cocos2d_ui_ScrollView_createInstance);
    oluacls_func(L, "getDirection", _olua_fun_cocos2d_ui_ScrollView_getDirection);
    oluacls_func(L, "getInnerContainer", _olua_fun_cocos2d_ui_ScrollView_getInnerContainer);
    oluacls_func(L, "getInnerContainerPosition", _olua_fun_cocos2d_ui_ScrollView_getInnerContainerPosition);
    oluacls_func(L, "getInnerContainerSize", _olua_fun_cocos2d_ui_ScrollView_getInnerContainerSize);
    oluacls_func(L, "getScrollBarAutoHideTime", _olua_fun_cocos2d_ui_ScrollView_getScrollBarAutoHideTime);
    oluacls_func(L, "getScrollBarColor", _olua_fun_cocos2d_ui_ScrollView_getScrollBarColor);
    oluacls_func(L, "getScrollBarOpacity", _olua_fun_cocos2d_ui_ScrollView_getScrollBarOpacity);
    oluacls_func(L, "getScrollBarPositionFromCornerForHorizontal", _olua_fun_cocos2d_ui_ScrollView_getScrollBarPositionFromCornerForHorizontal);
    oluacls_func(L, "getScrollBarPositionFromCornerForVertical", _olua_fun_cocos2d_ui_ScrollView_getScrollBarPositionFromCornerForVertical);
    oluacls_func(L, "getScrollBarWidth", _olua_fun_cocos2d_ui_ScrollView_getScrollBarWidth);
    oluacls_func(L, "getScrolledPercentBothDirection", _olua_fun_cocos2d_ui_ScrollView_getScrolledPercentBothDirection);
    oluacls_func(L, "getScrolledPercentHorizontal", _olua_fun_cocos2d_ui_ScrollView_getScrolledPercentHorizontal);
    oluacls_func(L, "getScrolledPercentVertical", _olua_fun_cocos2d_ui_ScrollView_getScrolledPercentVertical);
    oluacls_func(L, "getTouchTotalTimeThreshold", _olua_fun_cocos2d_ui_ScrollView_getTouchTotalTimeThreshold);
    oluacls_func(L, "isAutoScrolling", _olua_fun_cocos2d_ui_ScrollView_isAutoScrolling);
    oluacls_func(L, "isBounceEnabled", _olua_fun_cocos2d_ui_ScrollView_isBounceEnabled);
    oluacls_func(L, "isInertiaScrollEnabled", _olua_fun_cocos2d_ui_ScrollView_isInertiaScrollEnabled);
    oluacls_func(L, "isScrollBarAutoHideEnabled", _olua_fun_cocos2d_ui_ScrollView_isScrollBarAutoHideEnabled);
    oluacls_func(L, "isScrollBarEnabled", _olua_fun_cocos2d_ui_ScrollView_isScrollBarEnabled);
    oluacls_func(L, "isScrolling", _olua_fun_cocos2d_ui_ScrollView_isScrolling);
    oluacls_func(L, "jumpToBottom", _olua_fun_cocos2d_ui_ScrollView_jumpToBottom);
    oluacls_func(L, "jumpToBottomLeft", _olua_fun_cocos2d_ui_ScrollView_jumpToBottomLeft);
    oluacls_func(L, "jumpToBottomRight", _olua_fun_cocos2d_ui_ScrollView_jumpToBottomRight);
    oluacls_func(L, "jumpToLeft", _olua_fun_cocos2d_ui_ScrollView_jumpToLeft);
    oluacls_func(L, "jumpToPercentBothDirection", _olua_fun_cocos2d_ui_ScrollView_jumpToPercentBothDirection);
    oluacls_func(L, "jumpToPercentHorizontal", _olua_fun_cocos2d_ui_ScrollView_jumpToPercentHorizontal);
    oluacls_func(L, "jumpToPercentVertical", _olua_fun_cocos2d_ui_ScrollView_jumpToPercentVertical);
    oluacls_func(L, "jumpToRight", _olua_fun_cocos2d_ui_ScrollView_jumpToRight);
    oluacls_func(L, "jumpToTop", _olua_fun_cocos2d_ui_ScrollView_jumpToTop);
    oluacls_func(L, "jumpToTopLeft", _olua_fun_cocos2d_ui_ScrollView_jumpToTopLeft);
    oluacls_func(L, "jumpToTopRight", _olua_fun_cocos2d_ui_ScrollView_jumpToTopRight);
    oluacls_func(L, "new", _olua_fun_cocos2d_ui_ScrollView_new);
    oluacls_func(L, "scrollToBottom", _olua_fun_cocos2d_ui_ScrollView_scrollToBottom);
    oluacls_func(L, "scrollToBottomLeft", _olua_fun_cocos2d_ui_ScrollView_scrollToBottomLeft);
    oluacls_func(L, "scrollToBottomRight", _olua_fun_cocos2d_ui_ScrollView_scrollToBottomRight);
    oluacls_func(L, "scrollToLeft", _olua_fun_cocos2d_ui_ScrollView_scrollToLeft);
    oluacls_func(L, "scrollToPercentBothDirection", _olua_fun_cocos2d_ui_ScrollView_scrollToPercentBothDirection);
    oluacls_func(L, "scrollToPercentHorizontal", _olua_fun_cocos2d_ui_ScrollView_scrollToPercentHorizontal);
    oluacls_func(L, "scrollToPercentVertical", _olua_fun_cocos2d_ui_ScrollView_scrollToPercentVertical);
    oluacls_func(L, "scrollToRight", _olua_fun_cocos2d_ui_ScrollView_scrollToRight);
    oluacls_func(L, "scrollToTop", _olua_fun_cocos2d_ui_ScrollView_scrollToTop);
    oluacls_func(L, "scrollToTopLeft", _olua_fun_cocos2d_ui_ScrollView_scrollToTopLeft);
    oluacls_func(L, "scrollToTopRight", _olua_fun_cocos2d_ui_ScrollView_scrollToTopRight);
    oluacls_func(L, "setBounceEnabled", _olua_fun_cocos2d_ui_ScrollView_setBounceEnabled);
    oluacls_func(L, "setDirection", _olua_fun_cocos2d_ui_ScrollView_setDirection);
    oluacls_func(L, "setInertiaScrollEnabled", _olua_fun_cocos2d_ui_ScrollView_setInertiaScrollEnabled);
    oluacls_func(L, "setInnerContainerPosition", _olua_fun_cocos2d_ui_ScrollView_setInnerContainerPosition);
    oluacls_func(L, "setInnerContainerSize", _olua_fun_cocos2d_ui_ScrollView_setInnerContainerSize);
    oluacls_func(L, "setScrollBarAutoHideEnabled", _olua_fun_cocos2d_ui_ScrollView_setScrollBarAutoHideEnabled);
    oluacls_func(L, "setScrollBarAutoHideTime", _olua_fun_cocos2d_ui_ScrollView_setScrollBarAutoHideTime);
    oluacls_func(L, "setScrollBarColor", _olua_fun_cocos2d_ui_ScrollView_setScrollBarColor);
    oluacls_func(L, "setScrollBarEnabled", _olua_fun_cocos2d_ui_ScrollView_setScrollBarEnabled);
    oluacls_func(L, "setScrollBarOpacity", _olua_fun_cocos2d_ui_ScrollView_setScrollBarOpacity);
    oluacls_func(L, "setScrollBarPositionFromCorner", _olua_fun_cocos2d_ui_ScrollView_setScrollBarPositionFromCorner);
    oluacls_func(L, "setScrollBarPositionFromCornerForHorizontal", _olua_fun_cocos2d_ui_ScrollView_setScrollBarPositionFromCornerForHorizontal);
    oluacls_func(L, "setScrollBarPositionFromCornerForVertical", _olua_fun_cocos2d_ui_ScrollView_setScrollBarPositionFromCornerForVertical);
    oluacls_func(L, "setScrollBarWidth", _olua_fun_cocos2d_ui_ScrollView_setScrollBarWidth);
    oluacls_func(L, "setTouchTotalTimeThreshold", _olua_fun_cocos2d_ui_ScrollView_setTouchTotalTimeThreshold);
    oluacls_func(L, "stopAutoScroll", _olua_fun_cocos2d_ui_ScrollView_stopAutoScroll);
    oluacls_func(L, "stopOverallScroll", _olua_fun_cocos2d_ui_ScrollView_stopOverallScroll);
    oluacls_func(L, "stopScroll", _olua_fun_cocos2d_ui_ScrollView_stopScroll);
    oluacls_prop(L, "autoScrolling", _olua_fun_cocos2d_ui_ScrollView_isAutoScrolling, nullptr);
    oluacls_prop(L, "bounceEnabled", _olua_fun_cocos2d_ui_ScrollView_isBounceEnabled, _olua_fun_cocos2d_ui_ScrollView_setBounceEnabled);
    oluacls_prop(L, "direction", _olua_fun_cocos2d_ui_ScrollView_getDirection, _olua_fun_cocos2d_ui_ScrollView_setDirection);
    oluacls_prop(L, "inertiaScrollEnabled", _olua_fun_cocos2d_ui_ScrollView_isInertiaScrollEnabled, _olua_fun_cocos2d_ui_ScrollView_setInertiaScrollEnabled);
    oluacls_prop(L, "innerContainer", _olua_fun_cocos2d_ui_ScrollView_getInnerContainer, nullptr);
    oluacls_prop(L, "innerContainerPosition", _olua_fun_cocos2d_ui_ScrollView_getInnerContainerPosition, _olua_fun_cocos2d_ui_ScrollView_setInnerContainerPosition);
    oluacls_prop(L, "innerContainerSize", _olua_fun_cocos2d_ui_ScrollView_getInnerContainerSize, _olua_fun_cocos2d_ui_ScrollView_setInnerContainerSize);
    oluacls_prop(L, "scrollBarAutoHideEnabled", _olua_fun_cocos2d_ui_ScrollView_isScrollBarAutoHideEnabled, _olua_fun_cocos2d_ui_ScrollView_setScrollBarAutoHideEnabled);
    oluacls_prop(L, "scrollBarAutoHideTime", _olua_fun_cocos2d_ui_ScrollView_getScrollBarAutoHideTime, _olua_fun_cocos2d_ui_ScrollView_setScrollBarAutoHideTime);
    oluacls_prop(L, "scrollBarColor", _olua_fun_cocos2d_ui_ScrollView_getScrollBarColor, _olua_fun_cocos2d_ui_ScrollView_setScrollBarColor);
    oluacls_prop(L, "scrollBarEnabled", _olua_fun_cocos2d_ui_ScrollView_isScrollBarEnabled, _olua_fun_cocos2d_ui_ScrollView_setScrollBarEnabled);
    oluacls_prop(L, "scrollBarOpacity", _olua_fun_cocos2d_ui_ScrollView_getScrollBarOpacity, _olua_fun_cocos2d_ui_ScrollView_setScrollBarOpacity);
    oluacls_prop(L, "scrollBarPositionFromCornerForHorizontal", _olua_fun_cocos2d_ui_ScrollView_getScrollBarPositionFromCornerForHorizontal, _olua_fun_cocos2d_ui_ScrollView_setScrollBarPositionFromCornerForHorizontal);
    oluacls_prop(L, "scrollBarPositionFromCornerForVertical", _olua_fun_cocos2d_ui_ScrollView_getScrollBarPositionFromCornerForVertical, _olua_fun_cocos2d_ui_ScrollView_setScrollBarPositionFromCornerForVertical);
    oluacls_prop(L, "scrollBarWidth", _olua_fun_cocos2d_ui_ScrollView_getScrollBarWidth, _olua_fun_cocos2d_ui_ScrollView_setScrollBarWidth);
    oluacls_prop(L, "scrolledPercentBothDirection", _olua_fun_cocos2d_ui_ScrollView_getScrolledPercentBothDirection, nullptr);
    oluacls_prop(L, "scrolledPercentHorizontal", _olua_fun_cocos2d_ui_ScrollView_getScrolledPercentHorizontal, nullptr);
    oluacls_prop(L, "scrolledPercentVertical", _olua_fun_cocos2d_ui_ScrollView_getScrolledPercentVertical, nullptr);
    oluacls_prop(L, "scrolling", _olua_fun_cocos2d_ui_ScrollView_isScrolling, nullptr);
    oluacls_prop(L, "touchTotalTimeThreshold", _olua_fun_cocos2d_ui_ScrollView_getTouchTotalTimeThreshold, _olua_fun_cocos2d_ui_ScrollView_setTouchTotalTimeThreshold);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_ScrollView(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.ScrollView")) {
        luaL_error(L, "class not found: cocos2d::ui::ScrollView");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_ccui_ListView_Gravity(lua_State *L)
{
    oluacls_class<cocos2d::ui::ListView::Gravity>(L, "ccui.ListView.Gravity");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "BOTTOM", (lua_Integer)cocos2d::ui::ListView::Gravity::BOTTOM);
    oluacls_enum(L, "CENTER_HORIZONTAL", (lua_Integer)cocos2d::ui::ListView::Gravity::CENTER_HORIZONTAL);
    oluacls_enum(L, "CENTER_VERTICAL", (lua_Integer)cocos2d::ui::ListView::Gravity::CENTER_VERTICAL);
    oluacls_enum(L, "LEFT", (lua_Integer)cocos2d::ui::ListView::Gravity::LEFT);
    oluacls_enum(L, "RIGHT", (lua_Integer)cocos2d::ui::ListView::Gravity::RIGHT);
    oluacls_enum(L, "TOP", (lua_Integer)cocos2d::ui::ListView::Gravity::TOP);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_ListView_Gravity(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.ListView.Gravity")) {
        luaL_error(L, "class not found: cocos2d::ui::ListView::Gravity");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_ccui_ListView_EventType(lua_State *L)
{
    oluacls_class<cocos2d::ui::ListView::EventType>(L, "ccui.ListView.EventType");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "ON_SELECTED_ITEM_END", (lua_Integer)cocos2d::ui::ListView::EventType::ON_SELECTED_ITEM_END);
    oluacls_enum(L, "ON_SELECTED_ITEM_START", (lua_Integer)cocos2d::ui::ListView::EventType::ON_SELECTED_ITEM_START);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_ListView_EventType(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.ListView.EventType")) {
        luaL_error(L, "class not found: cocos2d::ui::ListView::EventType");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_ccui_ListView_MagneticType(lua_State *L)
{
    oluacls_class<cocos2d::ui::ListView::MagneticType>(L, "ccui.ListView.MagneticType");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "BOTH_END", (lua_Integer)cocos2d::ui::ListView::MagneticType::BOTH_END);
    oluacls_enum(L, "BOTTOM", (lua_Integer)cocos2d::ui::ListView::MagneticType::BOTTOM);
    oluacls_enum(L, "CENTER", (lua_Integer)cocos2d::ui::ListView::MagneticType::CENTER);
    oluacls_enum(L, "LEFT", (lua_Integer)cocos2d::ui::ListView::MagneticType::LEFT);
    oluacls_enum(L, "NONE", (lua_Integer)cocos2d::ui::ListView::MagneticType::NONE);
    oluacls_enum(L, "RIGHT", (lua_Integer)cocos2d::ui::ListView::MagneticType::RIGHT);
    oluacls_enum(L, "TOP", (lua_Integer)cocos2d::ui::ListView::MagneticType::TOP);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_ListView_MagneticType(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.ListView.MagneticType")) {
        luaL_error(L, "class not found: cocos2d::ui::ListView::MagneticType");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_ui_ListView_ccListViewCallback___call(lua_State *L)
{
    olua_startinvoke(L);

    luaL_checktype(L, -1, LUA_TFUNCTION);
    olua_push_callback(L, (cocos2d::ui::ListView::ccListViewCallback *)nullptr, "ccui.ListView.ccListViewCallback");

    olua_endinvoke(L);

    return 1;
}

static int _olua_cls_ccui_ListView_ccListViewCallback(lua_State *L)
{
    oluacls_class<cocos2d::ui::ListView::ccListViewCallback>(L, "ccui.ListView.ccListViewCallback");
    oluacls_func(L, "__call", _olua_fun_cocos2d_ui_ListView_ccListViewCallback___call);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_ListView_ccListViewCallback(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.ListView.ccListViewCallback")) {
        luaL_error(L, "class not found: cocos2d::ui::ListView::ccListViewCallback");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_ui_ListView_addEventListener$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;
    cocos2d::ui::ListView::ccListViewCallback arg1;       /** callback */

    olua_to_object(L, 1, &self, "ccui.ListView");
    olua_check_callback(L, 2, &arg1, "ccui.ListView.ccListViewCallback");

    void *cb_store = (void *)self;
    std::string cb_tag = "ListViewCallback";
    std::string cb_name = olua_setcallback(L, cb_store, 2, cb_tag.c_str(), OLUA_TAG_REPLACE);
    olua_Context cb_ctx = olua_context(L);
    // lua_State *ML = olua_mainthread(L);
    arg1 = [cb_store, cb_name, cb_ctx /*, ML */](cocos2d::Ref *cb_arg1, cocos2d::ui::ListView::EventType cb_arg2) {
        lua_State *L = olua_mainthread(NULL);
        olua_checkhostthread();

        if (olua_contextequal(L, cb_ctx)) {
            int top = lua_gettop(L);
            olua_push_object(L, cb_arg1, "cc.Ref");
            olua_push_enum(L, cb_arg2);

            olua_callback(L, cb_store, cb_name.c_str(), 2);

            lua_settop(L, top);
        }
    };

    // void addEventListener(const cocos2d::ui::ListView::ccListViewCallback &callback)
    self->addEventListener(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_ListView_addEventListener$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;
    cocos2d::ui::ScrollView::ccScrollViewCallback arg1;       /** callback */

    olua_to_object(L, 1, &self, "ccui.ListView");
    olua_check_callback(L, 2, &arg1, "ccui.ScrollView.ccScrollViewCallback");

    void *cb_store = (void *)self;
    std::string cb_tag = "scrollViewCallback" + std::string(".using");
    std::string cb_name = olua_setcallback(L, cb_store, 2, cb_tag.c_str(), OLUA_TAG_REPLACE);
    olua_Context cb_ctx = olua_context(L);
    // lua_State *ML = olua_mainthread(L);
    arg1 = [cb_store, cb_name, cb_ctx /*, ML */](cocos2d::Ref *cb_arg1, cocos2d::ui::ScrollView::EventType cb_arg2) {
        lua_State *L = olua_mainthread(NULL);
        olua_checkhostthread();

        if (olua_contextequal(L, cb_ctx)) {
            int top = lua_gettop(L);
            olua_push_object(L, cb_arg1, "cc.Ref");
            olua_push_enum(L, cb_arg2);

            olua_callback(L, cb_store, cb_name.c_str(), 2);

            lua_settop(L, top);
        }
    };

    // @using void addEventListener(const cocos2d::ui::ScrollView::ccScrollViewCallback &callback)
    self->addEventListener(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_ListView_addEventListener(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        if ((olua_is_object(L, 1, "ccui.ListView")) && (olua_is_callback(L, 2, "ccui.ListView.ccListViewCallback"))) {
            // void addEventListener(const cocos2d::ui::ListView::ccListViewCallback &callback)
            return _olua_fun_cocos2d_ui_ListView_addEventListener$1(L);
        }

        // if ((olua_is_object(L, 1, "ccui.ListView")) && (olua_is_callback(L, 2, "ccui.ScrollView.ccScrollViewCallback"))) {
            // @using void addEventListener(const cocos2d::ui::ScrollView::ccScrollViewCallback &callback)
            return _olua_fun_cocos2d_ui_ListView_addEventListener$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::ListView::addEventListener' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_ListView_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::ui::ListView *create()
    cocos2d::ui::ListView *ret = cocos2d::ui::ListView::create();
    int num_ret = olua_push_object(L, ret, "ccui.ListView");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_ListView_createInstance(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::Ref *createInstance()
    cocos2d::Ref *ret = cocos2d::ui::ListView::createInstance();
    int num_ret = olua_push_object(L, ret, "cc.Ref");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_ListView_doLayout(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.ListView");

    // void doLayout()
    self->doLayout();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_ListView_getBottomPadding(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.ListView");

    // float getBottomPadding()
    float ret = self->getBottomPadding();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_ListView_getBottommostItemInCurrentView(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.ListView");

    // cocos2d::ui::Widget *getBottommostItemInCurrentView()
    cocos2d::ui::Widget *ret = self->getBottommostItemInCurrentView();
    int num_ret = olua_push_object(L, ret, "ccui.Widget");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_ListView_getCenterItemInCurrentView(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.ListView");

    // cocos2d::ui::Widget *getCenterItemInCurrentView()
    cocos2d::ui::Widget *ret = self->getCenterItemInCurrentView();
    int num_ret = olua_push_object(L, ret, "ccui.Widget");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_ListView_getClosestItemToPosition(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;
    cocos2d::Vec2 *arg1;       /** targetPosition */
    cocos2d::Vec2 *arg2;       /** itemAnchorPoint */

    olua_to_object(L, 1, &self, "ccui.ListView");
    olua_check_object(L, 2, &arg1, "cc.Vec2");
    olua_check_object(L, 3, &arg2, "cc.Vec2");

    // cocos2d::ui::Widget *getClosestItemToPosition(const cocos2d::Vec2 &targetPosition, const cocos2d::Vec2 &itemAnchorPoint)
    cocos2d::ui::Widget *ret = self->getClosestItemToPosition(*arg1, *arg2);
    int num_ret = olua_push_object(L, ret, "ccui.Widget");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_ListView_getClosestItemToPositionInCurrentView(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;
    cocos2d::Vec2 *arg1;       /** positionRatioInView */
    cocos2d::Vec2 *arg2;       /** itemAnchorPoint */

    olua_to_object(L, 1, &self, "ccui.ListView");
    olua_check_object(L, 2, &arg1, "cc.Vec2");
    olua_check_object(L, 3, &arg2, "cc.Vec2");

    // cocos2d::ui::Widget *getClosestItemToPositionInCurrentView(const cocos2d::Vec2 &positionRatioInView, const cocos2d::Vec2 &itemAnchorPoint)
    cocos2d::ui::Widget *ret = self->getClosestItemToPositionInCurrentView(*arg1, *arg2);
    int num_ret = olua_push_object(L, ret, "ccui.Widget");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_ListView_getCurSelectedIndex(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.ListView");

    // ssize_t getCurSelectedIndex()
    ssize_t ret = self->getCurSelectedIndex();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_ListView_getIndex(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;
    cocos2d::ui::Widget *arg1 = nullptr;       /** item */

    olua_to_object(L, 1, &self, "ccui.ListView");
    olua_check_object(L, 2, &arg1, "ccui.Widget");

    // ssize_t getIndex(cocos2d::ui::Widget *item)
    ssize_t ret = self->getIndex(arg1);
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_ListView_getItem(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;
    ssize_t arg1 = 0;       /** index */

    olua_to_object(L, 1, &self, "ccui.ListView");
    olua_check_integer(L, 2, &arg1);

    // @addref(children |) cocos2d::ui::Widget *getItem(ssize_t index)
    cocos2d::ui::Widget *ret = self->getItem(arg1);
    int num_ret = olua_push_object(L, ret, "ccui.Widget");

    // insert code after call
    olua_addref(L, 1, "children", -1, OLUA_REF_MULTI);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_ListView_getItems(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.ListView");

    // @addref(children |) cocos2d::Vector<cocos2d::ui::Widget *> &getItems()
    cocos2d::Vector<cocos2d::ui::Widget *> &ret = self->getItems();
    int num_ret = olua_push_array<cocos2d::ui::Widget *>(L, ret, [L](cocos2d::ui::Widget *arg1) {
        olua_push_object(L, arg1, "ccui.Widget");
    });

    // insert code after call
    olua_addref(L, 1, "children", -1, OLUA_REF_MULTI | OLUA_REF_TABLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_ListView_getItemsMargin(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.ListView");

    // float getItemsMargin()
    float ret = self->getItemsMargin();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_ListView_getLeftPadding(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.ListView");

    // float getLeftPadding()
    float ret = self->getLeftPadding();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_ListView_getLeftmostItemInCurrentView(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.ListView");

    // cocos2d::ui::Widget *getLeftmostItemInCurrentView()
    cocos2d::ui::Widget *ret = self->getLeftmostItemInCurrentView();
    int num_ret = olua_push_object(L, ret, "ccui.Widget");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_ListView_getMagneticAllowedOutOfBoundary(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.ListView");

    // bool getMagneticAllowedOutOfBoundary()
    bool ret = self->getMagneticAllowedOutOfBoundary();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_ListView_getMagneticType(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.ListView");

    // cocos2d::ui::ListView::MagneticType getMagneticType()
    cocos2d::ui::ListView::MagneticType ret = self->getMagneticType();
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_ListView_getRightPadding(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.ListView");

    // float getRightPadding()
    float ret = self->getRightPadding();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_ListView_getRightmostItemInCurrentView(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.ListView");

    // cocos2d::ui::Widget *getRightmostItemInCurrentView()
    cocos2d::ui::Widget *ret = self->getRightmostItemInCurrentView();
    int num_ret = olua_push_object(L, ret, "ccui.Widget");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_ListView_getScrollDuration(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.ListView");

    // float getScrollDuration()
    float ret = self->getScrollDuration();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_ListView_getTopPadding(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.ListView");

    // float getTopPadding()
    float ret = self->getTopPadding();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_ListView_getTopmostItemInCurrentView(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.ListView");

    // cocos2d::ui::Widget *getTopmostItemInCurrentView()
    cocos2d::ui::Widget *ret = self->getTopmostItemInCurrentView();
    int num_ret = olua_push_object(L, ret, "ccui.Widget");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_ListView_insertCustomItem(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;
    cocos2d::ui::Widget *arg1 = nullptr;       /** item */
    ssize_t arg2 = 0;       /** index */

    olua_to_object(L, 1, &self, "ccui.ListView");
    olua_check_object(L, 2, &arg1, "ccui.Widget");
    olua_check_integer(L, 3, &arg2);

    // void insertCustomItem(@addref(children |) cocos2d::ui::Widget *item, ssize_t index)
    self->insertCustomItem(arg1, arg2);

    // insert code after call
    olua_addref(L, 1, "children", 2, OLUA_REF_MULTI);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_ListView_insertDefaultItem(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;
    ssize_t arg1 = 0;       /** index */

    olua_to_object(L, 1, &self, "ccui.ListView");
    olua_check_integer(L, 2, &arg1);

    // void insertDefaultItem(ssize_t index)
    self->insertDefaultItem(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_ListView_jumpToItem(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;
    ssize_t arg1 = 0;       /** itemIndex */
    cocos2d::Vec2 *arg2;       /** positionRatioInView */
    cocos2d::Vec2 *arg3;       /** itemAnchorPoint */

    olua_to_object(L, 1, &self, "ccui.ListView");
    olua_check_integer(L, 2, &arg1);
    olua_check_object(L, 3, &arg2, "cc.Vec2");
    olua_check_object(L, 4, &arg3, "cc.Vec2");

    // void jumpToItem(ssize_t itemIndex, const cocos2d::Vec2 &positionRatioInView, const cocos2d::Vec2 &itemAnchorPoint)
    self->jumpToItem(arg1, *arg2, *arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_ListView_new(lua_State *L)
{
    olua_startinvoke(L);

    // cocos2d::ui::ListView()
    cocos2d::ui::ListView *ret = new cocos2d::ui::ListView();
    int num_ret = olua_push_object(L, ret, "ccui.ListView");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_ListView_pushBackCustomItem(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;
    cocos2d::ui::Widget *arg1 = nullptr;       /** item */

    olua_to_object(L, 1, &self, "ccui.ListView");
    olua_check_object(L, 2, &arg1, "ccui.Widget");

    // void pushBackCustomItem(@addref(children |) cocos2d::ui::Widget *item)
    self->pushBackCustomItem(arg1);

    // insert code after call
    olua_addref(L, 1, "children", 2, OLUA_REF_MULTI);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_ListView_pushBackDefaultItem(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.ListView");

    // void pushBackDefaultItem()
    self->pushBackDefaultItem();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_ListView_removeAllItems(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.ListView");

    // insert code before call
    olua_startcmpref(L, 1, "children");

    // @delref(children ~) void removeAllItems()
    self->removeAllItems();

    // insert code after call
    olua_endcmpref(L, 1, "children");

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_ListView_removeItem(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;
    ssize_t arg1 = 0;       /** index */

    olua_to_object(L, 1, &self, "ccui.ListView");
    olua_check_integer(L, 2, &arg1);

    // insert code before call
    olua_startcmpref(L, 1, "children");

    // @delref(children ~) void removeItem(ssize_t index)
    self->removeItem(arg1);

    // insert code after call
    olua_endcmpref(L, 1, "children");

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_ListView_removeLastItem(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.ListView");

    // insert code before call
    olua_startcmpref(L, 1, "children");

    // @delref(children ~) void removeLastItem()
    self->removeLastItem();

    // insert code after call
    olua_endcmpref(L, 1, "children");

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_ListView_scrollToItem$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;
    ssize_t arg1 = 0;       /** itemIndex */
    cocos2d::Vec2 *arg2;       /** positionRatioInView */
    cocos2d::Vec2 *arg3;       /** itemAnchorPoint */

    olua_to_object(L, 1, &self, "ccui.ListView");
    olua_check_integer(L, 2, &arg1);
    olua_check_object(L, 3, &arg2, "cc.Vec2");
    olua_check_object(L, 4, &arg3, "cc.Vec2");

    // void scrollToItem(ssize_t itemIndex, const cocos2d::Vec2 &positionRatioInView, const cocos2d::Vec2 &itemAnchorPoint)
    self->scrollToItem(arg1, *arg2, *arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_ListView_scrollToItem$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;
    ssize_t arg1 = 0;       /** itemIndex */
    cocos2d::Vec2 *arg2;       /** positionRatioInView */
    cocos2d::Vec2 *arg3;       /** itemAnchorPoint */
    float arg4 = 0;       /** timeInSec */

    olua_to_object(L, 1, &self, "ccui.ListView");
    olua_check_integer(L, 2, &arg1);
    olua_check_object(L, 3, &arg2, "cc.Vec2");
    olua_check_object(L, 4, &arg3, "cc.Vec2");
    olua_check_number(L, 5, &arg4);

    // void scrollToItem(ssize_t itemIndex, const cocos2d::Vec2 &positionRatioInView, const cocos2d::Vec2 &itemAnchorPoint, float timeInSec)
    self->scrollToItem(arg1, *arg2, *arg3, arg4);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_ListView_scrollToItem(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 4) {
        // if ((olua_is_object(L, 1, "ccui.ListView")) && (olua_is_integer(L, 2)) && (olua_is_object(L, 3, "cc.Vec2")) && (olua_is_object(L, 4, "cc.Vec2"))) {
            // void scrollToItem(ssize_t itemIndex, const cocos2d::Vec2 &positionRatioInView, const cocos2d::Vec2 &itemAnchorPoint)
            return _olua_fun_cocos2d_ui_ListView_scrollToItem$1(L);
        // }
    }

    if (num_args == 5) {
        // if ((olua_is_object(L, 1, "ccui.ListView")) && (olua_is_integer(L, 2)) && (olua_is_object(L, 3, "cc.Vec2")) && (olua_is_object(L, 4, "cc.Vec2")) && (olua_is_number(L, 5))) {
            // void scrollToItem(ssize_t itemIndex, const cocos2d::Vec2 &positionRatioInView, const cocos2d::Vec2 &itemAnchorPoint, float timeInSec)
            return _olua_fun_cocos2d_ui_ListView_scrollToItem$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::ListView::scrollToItem' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_ListView_setBottomPadding(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;
    float arg1 = 0;       /** b */

    olua_to_object(L, 1, &self, "ccui.ListView");
    olua_check_number(L, 2, &arg1);

    // void setBottomPadding(float b)
    self->setBottomPadding(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_ListView_setCurSelectedIndex(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;
    int arg1 = 0;       /** itemIndex */

    olua_to_object(L, 1, &self, "ccui.ListView");
    olua_check_integer(L, 2, &arg1);

    // void setCurSelectedIndex(int itemIndex)
    self->setCurSelectedIndex(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_ListView_setGravity(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;
    cocos2d::ui::ListView::Gravity arg1 = (cocos2d::ui::ListView::Gravity)0;       /** gravity */

    olua_to_object(L, 1, &self, "ccui.ListView");
    olua_check_enum(L, 2, &arg1);

    // void setGravity(cocos2d::ui::ListView::Gravity gravity)
    self->setGravity(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_ListView_setItemModel(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;
    cocos2d::ui::Widget *arg1 = nullptr;       /** model */

    olua_to_object(L, 1, &self, "ccui.ListView");
    olua_check_object(L, 2, &arg1, "ccui.Widget");

    // void setItemModel(cocos2d::ui::Widget *model)
    self->setItemModel(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_ListView_setItemsMargin(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;
    float arg1 = 0;       /** margin */

    olua_to_object(L, 1, &self, "ccui.ListView");
    olua_check_number(L, 2, &arg1);

    // void setItemsMargin(float margin)
    self->setItemsMargin(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_ListView_setLeftPadding(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;
    float arg1 = 0;       /** l */

    olua_to_object(L, 1, &self, "ccui.ListView");
    olua_check_number(L, 2, &arg1);

    // void setLeftPadding(float l)
    self->setLeftPadding(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_ListView_setMagneticAllowedOutOfBoundary(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;
    bool arg1 = false;       /** magneticAllowedOutOfBoundary */

    olua_to_object(L, 1, &self, "ccui.ListView");
    olua_check_bool(L, 2, &arg1);

    // void setMagneticAllowedOutOfBoundary(bool magneticAllowedOutOfBoundary)
    self->setMagneticAllowedOutOfBoundary(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_ListView_setMagneticType(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;
    cocos2d::ui::ListView::MagneticType arg1 = (cocos2d::ui::ListView::MagneticType)0;       /** magneticType */

    olua_to_object(L, 1, &self, "ccui.ListView");
    olua_check_enum(L, 2, &arg1);

    // void setMagneticType(cocos2d::ui::ListView::MagneticType magneticType)
    self->setMagneticType(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_ListView_setPadding(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;
    float arg1 = 0;       /** l */
    float arg2 = 0;       /** t */
    float arg3 = 0;       /** r */
    float arg4 = 0;       /** b */

    olua_to_object(L, 1, &self, "ccui.ListView");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);
    olua_check_number(L, 5, &arg4);

    // void setPadding(float l, float t, float r, float b)
    self->setPadding(arg1, arg2, arg3, arg4);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_ListView_setRightPadding(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;
    float arg1 = 0;       /** r */

    olua_to_object(L, 1, &self, "ccui.ListView");
    olua_check_number(L, 2, &arg1);

    // void setRightPadding(float r)
    self->setRightPadding(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_ListView_setScrollDuration(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;
    float arg1 = 0;       /** time */

    olua_to_object(L, 1, &self, "ccui.ListView");
    olua_check_number(L, 2, &arg1);

    // void setScrollDuration(float time)
    self->setScrollDuration(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_ListView_setTopPadding(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;
    float arg1 = 0;       /** t */

    olua_to_object(L, 1, &self, "ccui.ListView");
    olua_check_number(L, 2, &arg1);

    // void setTopPadding(float t)
    self->setTopPadding(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_cls_ccui_ListView(lua_State *L)
{
    oluacls_class<cocos2d::ui::ListView, cocos2d::ui::ScrollView>(L, "ccui.ListView");
    oluacls_func(L, "addEventListener", _olua_fun_cocos2d_ui_ListView_addEventListener);
    oluacls_func(L, "create", _olua_fun_cocos2d_ui_ListView_create);
    oluacls_func(L, "createInstance", _olua_fun_cocos2d_ui_ListView_createInstance);
    oluacls_func(L, "doLayout", _olua_fun_cocos2d_ui_ListView_doLayout);
    oluacls_func(L, "getBottomPadding", _olua_fun_cocos2d_ui_ListView_getBottomPadding);
    oluacls_func(L, "getBottommostItemInCurrentView", _olua_fun_cocos2d_ui_ListView_getBottommostItemInCurrentView);
    oluacls_func(L, "getCenterItemInCurrentView", _olua_fun_cocos2d_ui_ListView_getCenterItemInCurrentView);
    oluacls_func(L, "getClosestItemToPosition", _olua_fun_cocos2d_ui_ListView_getClosestItemToPosition);
    oluacls_func(L, "getClosestItemToPositionInCurrentView", _olua_fun_cocos2d_ui_ListView_getClosestItemToPositionInCurrentView);
    oluacls_func(L, "getCurSelectedIndex", _olua_fun_cocos2d_ui_ListView_getCurSelectedIndex);
    oluacls_func(L, "getIndex", _olua_fun_cocos2d_ui_ListView_getIndex);
    oluacls_func(L, "getItem", _olua_fun_cocos2d_ui_ListView_getItem);
    oluacls_func(L, "getItems", _olua_fun_cocos2d_ui_ListView_getItems);
    oluacls_func(L, "getItemsMargin", _olua_fun_cocos2d_ui_ListView_getItemsMargin);
    oluacls_func(L, "getLeftPadding", _olua_fun_cocos2d_ui_ListView_getLeftPadding);
    oluacls_func(L, "getLeftmostItemInCurrentView", _olua_fun_cocos2d_ui_ListView_getLeftmostItemInCurrentView);
    oluacls_func(L, "getMagneticAllowedOutOfBoundary", _olua_fun_cocos2d_ui_ListView_getMagneticAllowedOutOfBoundary);
    oluacls_func(L, "getMagneticType", _olua_fun_cocos2d_ui_ListView_getMagneticType);
    oluacls_func(L, "getRightPadding", _olua_fun_cocos2d_ui_ListView_getRightPadding);
    oluacls_func(L, "getRightmostItemInCurrentView", _olua_fun_cocos2d_ui_ListView_getRightmostItemInCurrentView);
    oluacls_func(L, "getScrollDuration", _olua_fun_cocos2d_ui_ListView_getScrollDuration);
    oluacls_func(L, "getTopPadding", _olua_fun_cocos2d_ui_ListView_getTopPadding);
    oluacls_func(L, "getTopmostItemInCurrentView", _olua_fun_cocos2d_ui_ListView_getTopmostItemInCurrentView);
    oluacls_func(L, "insertCustomItem", _olua_fun_cocos2d_ui_ListView_insertCustomItem);
    oluacls_func(L, "insertDefaultItem", _olua_fun_cocos2d_ui_ListView_insertDefaultItem);
    oluacls_func(L, "jumpToItem", _olua_fun_cocos2d_ui_ListView_jumpToItem);
    oluacls_func(L, "new", _olua_fun_cocos2d_ui_ListView_new);
    oluacls_func(L, "pushBackCustomItem", _olua_fun_cocos2d_ui_ListView_pushBackCustomItem);
    oluacls_func(L, "pushBackDefaultItem", _olua_fun_cocos2d_ui_ListView_pushBackDefaultItem);
    oluacls_func(L, "removeAllItems", _olua_fun_cocos2d_ui_ListView_removeAllItems);
    oluacls_func(L, "removeItem", _olua_fun_cocos2d_ui_ListView_removeItem);
    oluacls_func(L, "removeLastItem", _olua_fun_cocos2d_ui_ListView_removeLastItem);
    oluacls_func(L, "scrollToItem", _olua_fun_cocos2d_ui_ListView_scrollToItem);
    oluacls_func(L, "setBottomPadding", _olua_fun_cocos2d_ui_ListView_setBottomPadding);
    oluacls_func(L, "setCurSelectedIndex", _olua_fun_cocos2d_ui_ListView_setCurSelectedIndex);
    oluacls_func(L, "setGravity", _olua_fun_cocos2d_ui_ListView_setGravity);
    oluacls_func(L, "setItemModel", _olua_fun_cocos2d_ui_ListView_setItemModel);
    oluacls_func(L, "setItemsMargin", _olua_fun_cocos2d_ui_ListView_setItemsMargin);
    oluacls_func(L, "setLeftPadding", _olua_fun_cocos2d_ui_ListView_setLeftPadding);
    oluacls_func(L, "setMagneticAllowedOutOfBoundary", _olua_fun_cocos2d_ui_ListView_setMagneticAllowedOutOfBoundary);
    oluacls_func(L, "setMagneticType", _olua_fun_cocos2d_ui_ListView_setMagneticType);
    oluacls_func(L, "setPadding", _olua_fun_cocos2d_ui_ListView_setPadding);
    oluacls_func(L, "setRightPadding", _olua_fun_cocos2d_ui_ListView_setRightPadding);
    oluacls_func(L, "setScrollDuration", _olua_fun_cocos2d_ui_ListView_setScrollDuration);
    oluacls_func(L, "setTopPadding", _olua_fun_cocos2d_ui_ListView_setTopPadding);
    oluacls_prop(L, "bottomPadding", _olua_fun_cocos2d_ui_ListView_getBottomPadding, _olua_fun_cocos2d_ui_ListView_setBottomPadding);
    oluacls_prop(L, "bottommostItemInCurrentView", _olua_fun_cocos2d_ui_ListView_getBottommostItemInCurrentView, nullptr);
    oluacls_prop(L, "centerItemInCurrentView", _olua_fun_cocos2d_ui_ListView_getCenterItemInCurrentView, nullptr);
    oluacls_prop(L, "curSelectedIndex", _olua_fun_cocos2d_ui_ListView_getCurSelectedIndex, _olua_fun_cocos2d_ui_ListView_setCurSelectedIndex);
    oluacls_prop(L, "items", _olua_fun_cocos2d_ui_ListView_getItems, nullptr);
    oluacls_prop(L, "itemsMargin", _olua_fun_cocos2d_ui_ListView_getItemsMargin, _olua_fun_cocos2d_ui_ListView_setItemsMargin);
    oluacls_prop(L, "leftPadding", _olua_fun_cocos2d_ui_ListView_getLeftPadding, _olua_fun_cocos2d_ui_ListView_setLeftPadding);
    oluacls_prop(L, "leftmostItemInCurrentView", _olua_fun_cocos2d_ui_ListView_getLeftmostItemInCurrentView, nullptr);
    oluacls_prop(L, "magneticAllowedOutOfBoundary", _olua_fun_cocos2d_ui_ListView_getMagneticAllowedOutOfBoundary, _olua_fun_cocos2d_ui_ListView_setMagneticAllowedOutOfBoundary);
    oluacls_prop(L, "magneticType", _olua_fun_cocos2d_ui_ListView_getMagneticType, _olua_fun_cocos2d_ui_ListView_setMagneticType);
    oluacls_prop(L, "rightPadding", _olua_fun_cocos2d_ui_ListView_getRightPadding, _olua_fun_cocos2d_ui_ListView_setRightPadding);
    oluacls_prop(L, "rightmostItemInCurrentView", _olua_fun_cocos2d_ui_ListView_getRightmostItemInCurrentView, nullptr);
    oluacls_prop(L, "scrollDuration", _olua_fun_cocos2d_ui_ListView_getScrollDuration, _olua_fun_cocos2d_ui_ListView_setScrollDuration);
    oluacls_prop(L, "topPadding", _olua_fun_cocos2d_ui_ListView_getTopPadding, _olua_fun_cocos2d_ui_ListView_setTopPadding);
    oluacls_prop(L, "topmostItemInCurrentView", _olua_fun_cocos2d_ui_ListView_getTopmostItemInCurrentView, nullptr);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_ListView(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.ListView")) {
        luaL_error(L, "class not found: cocos2d::ui::ListView");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_ccui_LoadingBar_Direction(lua_State *L)
{
    oluacls_class<cocos2d::ui::LoadingBar::Direction>(L, "ccui.LoadingBar.Direction");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "LEFT", (lua_Integer)cocos2d::ui::LoadingBar::Direction::LEFT);
    oluacls_enum(L, "RIGHT", (lua_Integer)cocos2d::ui::LoadingBar::Direction::RIGHT);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_LoadingBar_Direction(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.LoadingBar.Direction")) {
        luaL_error(L, "class not found: cocos2d::ui::LoadingBar::Direction");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_ui_LoadingBar_create$1(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::ui::LoadingBar *create()
    cocos2d::ui::LoadingBar *ret = cocos2d::ui::LoadingBar::create();
    int num_ret = olua_push_object(L, ret, "ccui.LoadingBar");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_LoadingBar_create$2(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** textureName */
    float arg2 = 0;       /** percentage */

    olua_check_string(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);

    // static cocos2d::ui::LoadingBar *create(const std::string &textureName, @optional float percentage)
    cocos2d::ui::LoadingBar *ret = cocos2d::ui::LoadingBar::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "ccui.LoadingBar");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_LoadingBar_create$3(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** textureName */

    olua_check_string(L, 1, &arg1);

    // static cocos2d::ui::LoadingBar *create(const std::string &textureName)
    cocos2d::ui::LoadingBar *ret = cocos2d::ui::LoadingBar::create(arg1);
    int num_ret = olua_push_object(L, ret, "ccui.LoadingBar");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_LoadingBar_create$4(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** textureName */
    cocos2d::ui::Widget::TextureResType arg2 = (cocos2d::ui::Widget::TextureResType)0;       /** texType */
    float arg3 = 0;       /** percentage */

    olua_check_string(L, 1, &arg1);
    olua_check_enum(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);

    // static cocos2d::ui::LoadingBar *create(const std::string &textureName, cocos2d::ui::Widget::TextureResType texType, @optional float percentage)
    cocos2d::ui::LoadingBar *ret = cocos2d::ui::LoadingBar::create(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "ccui.LoadingBar");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_LoadingBar_create$5(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** textureName */
    cocos2d::ui::Widget::TextureResType arg2 = (cocos2d::ui::Widget::TextureResType)0;       /** texType */

    olua_check_string(L, 1, &arg1);
    olua_check_enum(L, 2, &arg2);

    // static cocos2d::ui::LoadingBar *create(const std::string &textureName, cocos2d::ui::Widget::TextureResType texType)
    cocos2d::ui::LoadingBar *ret = cocos2d::ui::LoadingBar::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "ccui.LoadingBar");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_LoadingBar_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // static cocos2d::ui::LoadingBar *create()
        return _olua_fun_cocos2d_ui_LoadingBar_create$1(L);
    }

    if (num_args == 1) {
        // if ((olua_is_string(L, 1))) {
            // static cocos2d::ui::LoadingBar *create(const std::string &textureName)
            return _olua_fun_cocos2d_ui_LoadingBar_create$3(L);
        // }
    }

    if (num_args == 2) {
        if ((olua_is_string(L, 1)) && (olua_is_number(L, 2))) {
            // static cocos2d::ui::LoadingBar *create(const std::string &textureName, @optional float percentage)
            return _olua_fun_cocos2d_ui_LoadingBar_create$2(L);
        }

        // if ((olua_is_string(L, 1)) && (olua_is_enum(L, 2))) {
            // static cocos2d::ui::LoadingBar *create(const std::string &textureName, cocos2d::ui::Widget::TextureResType texType)
            return _olua_fun_cocos2d_ui_LoadingBar_create$5(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_string(L, 1)) && (olua_is_enum(L, 2)) && (olua_is_number(L, 3))) {
            // static cocos2d::ui::LoadingBar *create(const std::string &textureName, cocos2d::ui::Widget::TextureResType texType, @optional float percentage)
            return _olua_fun_cocos2d_ui_LoadingBar_create$4(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::LoadingBar::create' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_LoadingBar_createInstance(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::Ref *createInstance()
    cocos2d::Ref *ret = cocos2d::ui::LoadingBar::createInstance();
    int num_ret = olua_push_object(L, ret, "cc.Ref");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_LoadingBar_getCapInsets(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LoadingBar *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.LoadingBar");

    // const cocos2d::Rect &getCapInsets()
    const cocos2d::Rect &ret = self->getCapInsets();
    int num_ret = olua_push_object(L, ret, "cc.Rect");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_LoadingBar_getDirection(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LoadingBar *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.LoadingBar");

    // cocos2d::ui::LoadingBar::Direction getDirection()
    cocos2d::ui::LoadingBar::Direction ret = self->getDirection();
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_LoadingBar_getPercent(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LoadingBar *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.LoadingBar");

    // float getPercent()
    float ret = self->getPercent();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_LoadingBar_getRenderFile(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LoadingBar *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.LoadingBar");

    // cocos2d::ResourceData getRenderFile()
    cocos2d::ResourceData ret = self->getRenderFile();
    int num_ret = olua_copy_object(L, ret, "cc.ResourceData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_LoadingBar_isScale9Enabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LoadingBar *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.LoadingBar");

    // bool isScale9Enabled()
    bool ret = self->isScale9Enabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_LoadingBar_loadTexture$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LoadingBar *self = nullptr;
    std::string arg1;       /** texture */
    cocos2d::ui::Widget::TextureResType arg2 = (cocos2d::ui::Widget::TextureResType)0;       /** texType */

    olua_to_object(L, 1, &self, "ccui.LoadingBar");
    olua_check_string(L, 2, &arg1);
    olua_check_enum(L, 3, &arg2);

    // void loadTexture(const std::string &texture, @optional cocos2d::ui::Widget::TextureResType texType)
    self->loadTexture(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_LoadingBar_loadTexture$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LoadingBar *self = nullptr;
    std::string arg1;       /** texture */

    olua_to_object(L, 1, &self, "ccui.LoadingBar");
    olua_check_string(L, 2, &arg1);

    // void loadTexture(const std::string &texture)
    self->loadTexture(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_LoadingBar_loadTexture(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccui.LoadingBar")) && (olua_is_string(L, 2))) {
            // void loadTexture(const std::string &texture)
            return _olua_fun_cocos2d_ui_LoadingBar_loadTexture$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "ccui.LoadingBar")) && (olua_is_string(L, 2)) && (olua_is_enum(L, 3))) {
            // void loadTexture(const std::string &texture, @optional cocos2d::ui::Widget::TextureResType texType)
            return _olua_fun_cocos2d_ui_LoadingBar_loadTexture$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::LoadingBar::loadTexture' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_LoadingBar_new(lua_State *L)
{
    olua_startinvoke(L);

    // cocos2d::ui::LoadingBar()
    cocos2d::ui::LoadingBar *ret = new cocos2d::ui::LoadingBar();
    int num_ret = olua_push_object(L, ret, "ccui.LoadingBar");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_LoadingBar_setCapInsets(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LoadingBar *self = nullptr;
    cocos2d::Rect *arg1;       /** capInsets */

    olua_to_object(L, 1, &self, "ccui.LoadingBar");
    olua_check_object(L, 2, &arg1, "cc.Rect");

    // void setCapInsets(const cocos2d::Rect &capInsets)
    self->setCapInsets(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_LoadingBar_setDirection(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LoadingBar *self = nullptr;
    cocos2d::ui::LoadingBar::Direction arg1 = (cocos2d::ui::LoadingBar::Direction)0;       /** direction */

    olua_to_object(L, 1, &self, "ccui.LoadingBar");
    olua_check_enum(L, 2, &arg1);

    // void setDirection(cocos2d::ui::LoadingBar::Direction direction)
    self->setDirection(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_LoadingBar_setPercent(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LoadingBar *self = nullptr;
    float arg1 = 0;       /** percent */

    olua_to_object(L, 1, &self, "ccui.LoadingBar");
    olua_check_number(L, 2, &arg1);

    // void setPercent(float percent)
    self->setPercent(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_LoadingBar_setScale9Enabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LoadingBar *self = nullptr;
    bool arg1 = false;       /** enabled */

    olua_to_object(L, 1, &self, "ccui.LoadingBar");
    olua_check_bool(L, 2, &arg1);

    // void setScale9Enabled(bool enabled)
    self->setScale9Enabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_cls_ccui_LoadingBar(lua_State *L)
{
    oluacls_class<cocos2d::ui::LoadingBar, cocos2d::ui::Widget>(L, "ccui.LoadingBar");
    oluacls_func(L, "create", _olua_fun_cocos2d_ui_LoadingBar_create);
    oluacls_func(L, "createInstance", _olua_fun_cocos2d_ui_LoadingBar_createInstance);
    oluacls_func(L, "getCapInsets", _olua_fun_cocos2d_ui_LoadingBar_getCapInsets);
    oluacls_func(L, "getDirection", _olua_fun_cocos2d_ui_LoadingBar_getDirection);
    oluacls_func(L, "getPercent", _olua_fun_cocos2d_ui_LoadingBar_getPercent);
    oluacls_func(L, "getRenderFile", _olua_fun_cocos2d_ui_LoadingBar_getRenderFile);
    oluacls_func(L, "isScale9Enabled", _olua_fun_cocos2d_ui_LoadingBar_isScale9Enabled);
    oluacls_func(L, "loadTexture", _olua_fun_cocos2d_ui_LoadingBar_loadTexture);
    oluacls_func(L, "new", _olua_fun_cocos2d_ui_LoadingBar_new);
    oluacls_func(L, "setCapInsets", _olua_fun_cocos2d_ui_LoadingBar_setCapInsets);
    oluacls_func(L, "setDirection", _olua_fun_cocos2d_ui_LoadingBar_setDirection);
    oluacls_func(L, "setPercent", _olua_fun_cocos2d_ui_LoadingBar_setPercent);
    oluacls_func(L, "setScale9Enabled", _olua_fun_cocos2d_ui_LoadingBar_setScale9Enabled);
    oluacls_prop(L, "capInsets", _olua_fun_cocos2d_ui_LoadingBar_getCapInsets, _olua_fun_cocos2d_ui_LoadingBar_setCapInsets);
    oluacls_prop(L, "direction", _olua_fun_cocos2d_ui_LoadingBar_getDirection, _olua_fun_cocos2d_ui_LoadingBar_setDirection);
    oluacls_prop(L, "percent", _olua_fun_cocos2d_ui_LoadingBar_getPercent, _olua_fun_cocos2d_ui_LoadingBar_setPercent);
    oluacls_prop(L, "renderFile", _olua_fun_cocos2d_ui_LoadingBar_getRenderFile, nullptr);
    oluacls_prop(L, "scale9Enabled", _olua_fun_cocos2d_ui_LoadingBar_isScale9Enabled, _olua_fun_cocos2d_ui_LoadingBar_setScale9Enabled);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_LoadingBar(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.LoadingBar")) {
        luaL_error(L, "class not found: cocos2d::ui::LoadingBar");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_ccui_PageView_EventType(lua_State *L)
{
    oluacls_class<cocos2d::ui::PageView::EventType>(L, "ccui.PageView.EventType");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "TURNING", (lua_Integer)cocos2d::ui::PageView::EventType::TURNING);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_PageView_EventType(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.PageView.EventType")) {
        luaL_error(L, "class not found: cocos2d::ui::PageView::EventType");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_ccui_PageView_TouchDirection(lua_State *L)
{
    oluacls_class<cocos2d::ui::PageView::TouchDirection>(L, "ccui.PageView.TouchDirection");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "DOWN", (lua_Integer)cocos2d::ui::PageView::TouchDirection::DOWN);
    oluacls_enum(L, "LEFT", (lua_Integer)cocos2d::ui::PageView::TouchDirection::LEFT);
    oluacls_enum(L, "RIGHT", (lua_Integer)cocos2d::ui::PageView::TouchDirection::RIGHT);
    oluacls_enum(L, "UP", (lua_Integer)cocos2d::ui::PageView::TouchDirection::UP);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_PageView_TouchDirection(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.PageView.TouchDirection")) {
        luaL_error(L, "class not found: cocos2d::ui::PageView::TouchDirection");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_ui_PageView_ccPageViewCallback___call(lua_State *L)
{
    olua_startinvoke(L);

    luaL_checktype(L, -1, LUA_TFUNCTION);
    olua_push_callback(L, (cocos2d::ui::PageView::ccPageViewCallback *)nullptr, "ccui.PageView.ccPageViewCallback");

    olua_endinvoke(L);

    return 1;
}

static int _olua_cls_ccui_PageView_ccPageViewCallback(lua_State *L)
{
    oluacls_class<cocos2d::ui::PageView::ccPageViewCallback>(L, "ccui.PageView.ccPageViewCallback");
    oluacls_func(L, "__call", _olua_fun_cocos2d_ui_PageView_ccPageViewCallback___call);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_PageView_ccPageViewCallback(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.PageView.ccPageViewCallback")) {
        luaL_error(L, "class not found: cocos2d::ui::PageView::ccPageViewCallback");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_ui_PageView_addEventListener$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::PageView *self = nullptr;
    cocos2d::ui::PageView::ccPageViewCallback arg1;       /** callback */

    olua_to_object(L, 1, &self, "ccui.PageView");
    olua_check_callback(L, 2, &arg1, "ccui.PageView.ccPageViewCallback");

    void *cb_store = (void *)self;
    std::string cb_tag = "PageViewCallback";
    std::string cb_name = olua_setcallback(L, cb_store, 2, cb_tag.c_str(), OLUA_TAG_REPLACE);
    olua_Context cb_ctx = olua_context(L);
    // lua_State *ML = olua_mainthread(L);
    arg1 = [cb_store, cb_name, cb_ctx /*, ML */](cocos2d::Ref *cb_arg1, cocos2d::ui::PageView::EventType cb_arg2) {
        lua_State *L = olua_mainthread(NULL);
        olua_checkhostthread();

        if (olua_contextequal(L, cb_ctx)) {
            int top = lua_gettop(L);
            olua_push_object(L, cb_arg1, "cc.Ref");
            olua_push_enum(L, cb_arg2);

            olua_callback(L, cb_store, cb_name.c_str(), 2);

            lua_settop(L, top);
        }
    };

    // void addEventListener(const cocos2d::ui::PageView::ccPageViewCallback &callback)
    self->addEventListener(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_PageView_addEventListener$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::PageView *self = nullptr;
    cocos2d::ui::ScrollView::ccScrollViewCallback arg1;       /** callback */

    olua_to_object(L, 1, &self, "ccui.PageView");
    olua_check_callback(L, 2, &arg1, "ccui.ScrollView.ccScrollViewCallback");

    void *cb_store = (void *)self;
    std::string cb_tag = "scrollViewCallback" + std::string(".using");
    std::string cb_name = olua_setcallback(L, cb_store, 2, cb_tag.c_str(), OLUA_TAG_REPLACE);
    olua_Context cb_ctx = olua_context(L);
    // lua_State *ML = olua_mainthread(L);
    arg1 = [cb_store, cb_name, cb_ctx /*, ML */](cocos2d::Ref *cb_arg1, cocos2d::ui::ScrollView::EventType cb_arg2) {
        lua_State *L = olua_mainthread(NULL);
        olua_checkhostthread();

        if (olua_contextequal(L, cb_ctx)) {
            int top = lua_gettop(L);
            olua_push_object(L, cb_arg1, "cc.Ref");
            olua_push_enum(L, cb_arg2);

            olua_callback(L, cb_store, cb_name.c_str(), 2);

            lua_settop(L, top);
        }
    };

    // @using void addEventListener(const cocos2d::ui::ScrollView::ccScrollViewCallback &callback)
    self->addEventListener(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_PageView_addEventListener(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        if ((olua_is_object(L, 1, "ccui.PageView")) && (olua_is_callback(L, 2, "ccui.PageView.ccPageViewCallback"))) {
            // void addEventListener(const cocos2d::ui::PageView::ccPageViewCallback &callback)
            return _olua_fun_cocos2d_ui_PageView_addEventListener$1(L);
        }

        // if ((olua_is_object(L, 1, "ccui.PageView")) && (olua_is_callback(L, 2, "ccui.ScrollView.ccScrollViewCallback"))) {
            // @using void addEventListener(const cocos2d::ui::ScrollView::ccScrollViewCallback &callback)
            return _olua_fun_cocos2d_ui_PageView_addEventListener$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::PageView::addEventListener' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_PageView_addPage(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::PageView *self = nullptr;
    cocos2d::ui::Widget *arg1 = nullptr;       /** page */

    olua_to_object(L, 1, &self, "ccui.PageView");
    olua_check_object(L, 2, &arg1, "ccui.Widget");

    // void addPage(@addref(children |) cocos2d::ui::Widget *page)
    self->addPage(arg1);

    // insert code after call
    olua_addref(L, 1, "children", 2, OLUA_REF_MULTI);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_PageView_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::ui::PageView *create()
    cocos2d::ui::PageView *ret = cocos2d::ui::PageView::create();
    int num_ret = olua_push_object(L, ret, "ccui.PageView");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_PageView_createInstance(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::Ref *createInstance()
    cocos2d::Ref *ret = cocos2d::ui::PageView::createInstance();
    int num_ret = olua_push_object(L, ret, "cc.Ref");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_PageView_getCurrentPageIndex(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::PageView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.PageView");

    // ssize_t getCurrentPageIndex()
    ssize_t ret = self->getCurrentPageIndex();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_PageView_getIndicatorEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::PageView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.PageView");

    // bool getIndicatorEnabled()
    bool ret = self->getIndicatorEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_PageView_getIndicatorIndexNodesColor(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::PageView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.PageView");

    // const cocos2d::Color3B &getIndicatorIndexNodesColor()
    const cocos2d::Color3B &ret = self->getIndicatorIndexNodesColor();
    int num_ret = olua_push_cocos2d_Color3B(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_PageView_getIndicatorIndexNodesOpacity(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::PageView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.PageView");

    // uint8_t getIndicatorIndexNodesOpacity()
    uint8_t ret = self->getIndicatorIndexNodesOpacity();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_PageView_getIndicatorIndexNodesScale(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::PageView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.PageView");

    // float getIndicatorIndexNodesScale()
    float ret = self->getIndicatorIndexNodesScale();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_PageView_getIndicatorPosition(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::PageView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.PageView");

    // const cocos2d::Vec2 &getIndicatorPosition()
    const cocos2d::Vec2 &ret = self->getIndicatorPosition();
    int num_ret = olua_push_object(L, ret, "cc.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_PageView_getIndicatorPositionAsAnchorPoint(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::PageView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.PageView");

    // const cocos2d::Vec2 &getIndicatorPositionAsAnchorPoint()
    const cocos2d::Vec2 &ret = self->getIndicatorPositionAsAnchorPoint();
    int num_ret = olua_push_object(L, ret, "cc.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_PageView_getIndicatorSelectedIndexColor(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::PageView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.PageView");

    // const cocos2d::Color3B &getIndicatorSelectedIndexColor()
    const cocos2d::Color3B &ret = self->getIndicatorSelectedIndexColor();
    int num_ret = olua_push_cocos2d_Color3B(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_PageView_getIndicatorSelectedIndexOpacity(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::PageView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.PageView");

    // uint8_t getIndicatorSelectedIndexOpacity()
    uint8_t ret = self->getIndicatorSelectedIndexOpacity();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_PageView_getIndicatorSpaceBetweenIndexNodes(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::PageView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.PageView");

    // float getIndicatorSpaceBetweenIndexNodes()
    float ret = self->getIndicatorSpaceBetweenIndexNodes();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_PageView_insertPage(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::PageView *self = nullptr;
    cocos2d::ui::Widget *arg1 = nullptr;       /** page */
    int arg2 = 0;       /** idx */

    olua_to_object(L, 1, &self, "ccui.PageView");
    olua_check_object(L, 2, &arg1, "ccui.Widget");
    olua_check_integer(L, 3, &arg2);

    // void insertPage(@addref(children |) cocos2d::ui::Widget *page, int idx)
    self->insertPage(arg1, arg2);

    // insert code after call
    olua_addref(L, 1, "children", 2, OLUA_REF_MULTI);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_PageView_new(lua_State *L)
{
    olua_startinvoke(L);

    // cocos2d::ui::PageView()
    cocos2d::ui::PageView *ret = new cocos2d::ui::PageView();
    int num_ret = olua_push_object(L, ret, "ccui.PageView");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_PageView_removeAllPages(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::PageView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.PageView");

    // @delref(children *) void removeAllPages()
    self->removeAllPages();

    // insert code after call
    olua_delallrefs(L, 1, "children");

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_PageView_removePage(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::PageView *self = nullptr;
    cocos2d::ui::Widget *arg1 = nullptr;       /** page */

    olua_to_object(L, 1, &self, "ccui.PageView");
    olua_check_object(L, 2, &arg1, "ccui.Widget");

    // void removePage(@delref(children |) cocos2d::ui::Widget *page)
    self->removePage(arg1);

    // insert code after call
    olua_delref(L, 1, "children", 2, OLUA_REF_MULTI);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_PageView_removePageAtIndex(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::PageView *self = nullptr;
    ssize_t arg1 = 0;       /** index */

    olua_to_object(L, 1, &self, "ccui.PageView");
    olua_check_integer(L, 2, &arg1);

    // insert code before call
    olua_startcmpref(L, 1, "children");

    // @delref(children ~) void removePageAtIndex(ssize_t index)
    self->removePageAtIndex(arg1);

    // insert code after call
    olua_endcmpref(L, 1, "children");

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_PageView_scrollToItem$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::PageView *self = nullptr;
    ssize_t arg1 = 0;       /** itemIndex */

    olua_to_object(L, 1, &self, "ccui.PageView");
    olua_check_integer(L, 2, &arg1);

    // void scrollToItem(ssize_t itemIndex)
    self->scrollToItem(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_PageView_scrollToItem$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::PageView *self = nullptr;
    ssize_t arg1 = 0;       /** idx */
    float arg2 = 0;       /** time */

    olua_to_object(L, 1, &self, "ccui.PageView");
    olua_check_integer(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);

    // void scrollToItem(ssize_t idx, float time)
    self->scrollToItem(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_PageView_scrollToItem(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccui.PageView")) && (olua_is_integer(L, 2))) {
            // void scrollToItem(ssize_t itemIndex)
            return _olua_fun_cocos2d_ui_PageView_scrollToItem$1(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "ccui.PageView")) && (olua_is_integer(L, 2)) && (olua_is_number(L, 3))) {
            // void scrollToItem(ssize_t idx, float time)
            return _olua_fun_cocos2d_ui_PageView_scrollToItem$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::PageView::scrollToItem' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_PageView_scrollToPage$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::PageView *self = nullptr;
    ssize_t arg1 = 0;       /** idx */

    olua_to_object(L, 1, &self, "ccui.PageView");
    olua_check_integer(L, 2, &arg1);

    // void scrollToPage(ssize_t idx)
    self->scrollToPage(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_PageView_scrollToPage$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::PageView *self = nullptr;
    ssize_t arg1 = 0;       /** idx */
    float arg2 = 0;       /** time */

    olua_to_object(L, 1, &self, "ccui.PageView");
    olua_check_integer(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);

    // void scrollToPage(ssize_t idx, float time)
    self->scrollToPage(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_PageView_scrollToPage(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccui.PageView")) && (olua_is_integer(L, 2))) {
            // void scrollToPage(ssize_t idx)
            return _olua_fun_cocos2d_ui_PageView_scrollToPage$1(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "ccui.PageView")) && (olua_is_integer(L, 2)) && (olua_is_number(L, 3))) {
            // void scrollToPage(ssize_t idx, float time)
            return _olua_fun_cocos2d_ui_PageView_scrollToPage$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::PageView::scrollToPage' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_PageView_setAutoScrollStopEpsilon(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::PageView *self = nullptr;
    float arg1 = 0;       /** epsilon */

    olua_to_object(L, 1, &self, "ccui.PageView");
    olua_check_number(L, 2, &arg1);

    // void setAutoScrollStopEpsilon(float epsilon)
    self->setAutoScrollStopEpsilon(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_PageView_setCurrentPageIndex(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::PageView *self = nullptr;
    ssize_t arg1 = 0;       /** index */

    olua_to_object(L, 1, &self, "ccui.PageView");
    olua_check_integer(L, 2, &arg1);

    // void setCurrentPageIndex(ssize_t index)
    self->setCurrentPageIndex(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_PageView_setIndicatorEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::PageView *self = nullptr;
    bool arg1 = false;       /** enabled */

    olua_to_object(L, 1, &self, "ccui.PageView");
    olua_check_bool(L, 2, &arg1);

    // void setIndicatorEnabled(bool enabled)
    self->setIndicatorEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_PageView_setIndicatorIndexNodesColor(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::PageView *self = nullptr;
    cocos2d::Color3B arg1;       /** color */

    olua_to_object(L, 1, &self, "ccui.PageView");
    olua_check_cocos2d_Color3B(L, 2, &arg1);

    // void setIndicatorIndexNodesColor(const cocos2d::Color3B &color)
    self->setIndicatorIndexNodesColor(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_PageView_setIndicatorIndexNodesOpacity(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::PageView *self = nullptr;
    uint8_t arg1 = 0;       /** opacity */

    olua_to_object(L, 1, &self, "ccui.PageView");
    olua_check_integer(L, 2, &arg1);

    // void setIndicatorIndexNodesOpacity(uint8_t opacity)
    self->setIndicatorIndexNodesOpacity(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_PageView_setIndicatorIndexNodesScale(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::PageView *self = nullptr;
    float arg1 = 0;       /** indexNodesScale */

    olua_to_object(L, 1, &self, "ccui.PageView");
    olua_check_number(L, 2, &arg1);

    // void setIndicatorIndexNodesScale(float indexNodesScale)
    self->setIndicatorIndexNodesScale(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_PageView_setIndicatorIndexNodesTexture$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::PageView *self = nullptr;
    std::string arg1;       /** texName */
    cocos2d::ui::Widget::TextureResType arg2 = (cocos2d::ui::Widget::TextureResType)0;       /** texType */

    olua_to_object(L, 1, &self, "ccui.PageView");
    olua_check_string(L, 2, &arg1);
    olua_check_enum(L, 3, &arg2);

    // void setIndicatorIndexNodesTexture(const std::string &texName, @optional cocos2d::ui::Widget::TextureResType texType)
    self->setIndicatorIndexNodesTexture(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_PageView_setIndicatorIndexNodesTexture$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::PageView *self = nullptr;
    std::string arg1;       /** texName */

    olua_to_object(L, 1, &self, "ccui.PageView");
    olua_check_string(L, 2, &arg1);

    // void setIndicatorIndexNodesTexture(const std::string &texName)
    self->setIndicatorIndexNodesTexture(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_PageView_setIndicatorIndexNodesTexture(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccui.PageView")) && (olua_is_string(L, 2))) {
            // void setIndicatorIndexNodesTexture(const std::string &texName)
            return _olua_fun_cocos2d_ui_PageView_setIndicatorIndexNodesTexture$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "ccui.PageView")) && (olua_is_string(L, 2)) && (olua_is_enum(L, 3))) {
            // void setIndicatorIndexNodesTexture(const std::string &texName, @optional cocos2d::ui::Widget::TextureResType texType)
            return _olua_fun_cocos2d_ui_PageView_setIndicatorIndexNodesTexture$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::PageView::setIndicatorIndexNodesTexture' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_PageView_setIndicatorPosition(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::PageView *self = nullptr;
    cocos2d::Vec2 *arg1;       /** position */

    olua_to_object(L, 1, &self, "ccui.PageView");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // void setIndicatorPosition(const cocos2d::Vec2 &position)
    self->setIndicatorPosition(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_PageView_setIndicatorPositionAsAnchorPoint(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::PageView *self = nullptr;
    cocos2d::Vec2 *arg1;       /** positionAsAnchorPoint */

    olua_to_object(L, 1, &self, "ccui.PageView");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // void setIndicatorPositionAsAnchorPoint(const cocos2d::Vec2 &positionAsAnchorPoint)
    self->setIndicatorPositionAsAnchorPoint(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_PageView_setIndicatorSelectedIndexColor(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::PageView *self = nullptr;
    cocos2d::Color3B arg1;       /** color */

    olua_to_object(L, 1, &self, "ccui.PageView");
    olua_check_cocos2d_Color3B(L, 2, &arg1);

    // void setIndicatorSelectedIndexColor(const cocos2d::Color3B &color)
    self->setIndicatorSelectedIndexColor(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_PageView_setIndicatorSelectedIndexOpacity(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::PageView *self = nullptr;
    uint8_t arg1 = 0;       /** opacity */

    olua_to_object(L, 1, &self, "ccui.PageView");
    olua_check_integer(L, 2, &arg1);

    // void setIndicatorSelectedIndexOpacity(uint8_t opacity)
    self->setIndicatorSelectedIndexOpacity(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_PageView_setIndicatorSpaceBetweenIndexNodes(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::PageView *self = nullptr;
    float arg1 = 0;       /** spaceBetweenIndexNodes */

    olua_to_object(L, 1, &self, "ccui.PageView");
    olua_check_number(L, 2, &arg1);

    // void setIndicatorSpaceBetweenIndexNodes(float spaceBetweenIndexNodes)
    self->setIndicatorSpaceBetweenIndexNodes(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_cls_ccui_PageView(lua_State *L)
{
    oluacls_class<cocos2d::ui::PageView, cocos2d::ui::ListView>(L, "ccui.PageView");
    oluacls_func(L, "addEventListener", _olua_fun_cocos2d_ui_PageView_addEventListener);
    oluacls_func(L, "addPage", _olua_fun_cocos2d_ui_PageView_addPage);
    oluacls_func(L, "create", _olua_fun_cocos2d_ui_PageView_create);
    oluacls_func(L, "createInstance", _olua_fun_cocos2d_ui_PageView_createInstance);
    oluacls_func(L, "getCurrentPageIndex", _olua_fun_cocos2d_ui_PageView_getCurrentPageIndex);
    oluacls_func(L, "getIndicatorEnabled", _olua_fun_cocos2d_ui_PageView_getIndicatorEnabled);
    oluacls_func(L, "getIndicatorIndexNodesColor", _olua_fun_cocos2d_ui_PageView_getIndicatorIndexNodesColor);
    oluacls_func(L, "getIndicatorIndexNodesOpacity", _olua_fun_cocos2d_ui_PageView_getIndicatorIndexNodesOpacity);
    oluacls_func(L, "getIndicatorIndexNodesScale", _olua_fun_cocos2d_ui_PageView_getIndicatorIndexNodesScale);
    oluacls_func(L, "getIndicatorPosition", _olua_fun_cocos2d_ui_PageView_getIndicatorPosition);
    oluacls_func(L, "getIndicatorPositionAsAnchorPoint", _olua_fun_cocos2d_ui_PageView_getIndicatorPositionAsAnchorPoint);
    oluacls_func(L, "getIndicatorSelectedIndexColor", _olua_fun_cocos2d_ui_PageView_getIndicatorSelectedIndexColor);
    oluacls_func(L, "getIndicatorSelectedIndexOpacity", _olua_fun_cocos2d_ui_PageView_getIndicatorSelectedIndexOpacity);
    oluacls_func(L, "getIndicatorSpaceBetweenIndexNodes", _olua_fun_cocos2d_ui_PageView_getIndicatorSpaceBetweenIndexNodes);
    oluacls_func(L, "insertPage", _olua_fun_cocos2d_ui_PageView_insertPage);
    oluacls_func(L, "new", _olua_fun_cocos2d_ui_PageView_new);
    oluacls_func(L, "removeAllPages", _olua_fun_cocos2d_ui_PageView_removeAllPages);
    oluacls_func(L, "removePage", _olua_fun_cocos2d_ui_PageView_removePage);
    oluacls_func(L, "removePageAtIndex", _olua_fun_cocos2d_ui_PageView_removePageAtIndex);
    oluacls_func(L, "scrollToItem", _olua_fun_cocos2d_ui_PageView_scrollToItem);
    oluacls_func(L, "scrollToPage", _olua_fun_cocos2d_ui_PageView_scrollToPage);
    oluacls_func(L, "setAutoScrollStopEpsilon", _olua_fun_cocos2d_ui_PageView_setAutoScrollStopEpsilon);
    oluacls_func(L, "setCurrentPageIndex", _olua_fun_cocos2d_ui_PageView_setCurrentPageIndex);
    oluacls_func(L, "setIndicatorEnabled", _olua_fun_cocos2d_ui_PageView_setIndicatorEnabled);
    oluacls_func(L, "setIndicatorIndexNodesColor", _olua_fun_cocos2d_ui_PageView_setIndicatorIndexNodesColor);
    oluacls_func(L, "setIndicatorIndexNodesOpacity", _olua_fun_cocos2d_ui_PageView_setIndicatorIndexNodesOpacity);
    oluacls_func(L, "setIndicatorIndexNodesScale", _olua_fun_cocos2d_ui_PageView_setIndicatorIndexNodesScale);
    oluacls_func(L, "setIndicatorIndexNodesTexture", _olua_fun_cocos2d_ui_PageView_setIndicatorIndexNodesTexture);
    oluacls_func(L, "setIndicatorPosition", _olua_fun_cocos2d_ui_PageView_setIndicatorPosition);
    oluacls_func(L, "setIndicatorPositionAsAnchorPoint", _olua_fun_cocos2d_ui_PageView_setIndicatorPositionAsAnchorPoint);
    oluacls_func(L, "setIndicatorSelectedIndexColor", _olua_fun_cocos2d_ui_PageView_setIndicatorSelectedIndexColor);
    oluacls_func(L, "setIndicatorSelectedIndexOpacity", _olua_fun_cocos2d_ui_PageView_setIndicatorSelectedIndexOpacity);
    oluacls_func(L, "setIndicatorSpaceBetweenIndexNodes", _olua_fun_cocos2d_ui_PageView_setIndicatorSpaceBetweenIndexNodes);
    oluacls_prop(L, "currentPageIndex", _olua_fun_cocos2d_ui_PageView_getCurrentPageIndex, _olua_fun_cocos2d_ui_PageView_setCurrentPageIndex);
    oluacls_prop(L, "indicatorEnabled", _olua_fun_cocos2d_ui_PageView_getIndicatorEnabled, _olua_fun_cocos2d_ui_PageView_setIndicatorEnabled);
    oluacls_prop(L, "indicatorIndexNodesColor", _olua_fun_cocos2d_ui_PageView_getIndicatorIndexNodesColor, _olua_fun_cocos2d_ui_PageView_setIndicatorIndexNodesColor);
    oluacls_prop(L, "indicatorIndexNodesOpacity", _olua_fun_cocos2d_ui_PageView_getIndicatorIndexNodesOpacity, _olua_fun_cocos2d_ui_PageView_setIndicatorIndexNodesOpacity);
    oluacls_prop(L, "indicatorIndexNodesScale", _olua_fun_cocos2d_ui_PageView_getIndicatorIndexNodesScale, _olua_fun_cocos2d_ui_PageView_setIndicatorIndexNodesScale);
    oluacls_prop(L, "indicatorPosition", _olua_fun_cocos2d_ui_PageView_getIndicatorPosition, _olua_fun_cocos2d_ui_PageView_setIndicatorPosition);
    oluacls_prop(L, "indicatorPositionAsAnchorPoint", _olua_fun_cocos2d_ui_PageView_getIndicatorPositionAsAnchorPoint, _olua_fun_cocos2d_ui_PageView_setIndicatorPositionAsAnchorPoint);
    oluacls_prop(L, "indicatorSelectedIndexColor", _olua_fun_cocos2d_ui_PageView_getIndicatorSelectedIndexColor, _olua_fun_cocos2d_ui_PageView_setIndicatorSelectedIndexColor);
    oluacls_prop(L, "indicatorSelectedIndexOpacity", _olua_fun_cocos2d_ui_PageView_getIndicatorSelectedIndexOpacity, _olua_fun_cocos2d_ui_PageView_setIndicatorSelectedIndexOpacity);
    oluacls_prop(L, "indicatorSpaceBetweenIndexNodes", _olua_fun_cocos2d_ui_PageView_getIndicatorSpaceBetweenIndexNodes, _olua_fun_cocos2d_ui_PageView_setIndicatorSpaceBetweenIndexNodes);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_PageView(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.PageView")) {
        luaL_error(L, "class not found: cocos2d::ui::PageView");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_ccui_RichElement_Type(lua_State *L)
{
    oluacls_class<cocos2d::ui::RichElement::Type>(L, "ccui.RichElement.Type");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "CUSTOM", (lua_Integer)cocos2d::ui::RichElement::Type::CUSTOM);
    oluacls_enum(L, "IMAGE", (lua_Integer)cocos2d::ui::RichElement::Type::IMAGE);
    oluacls_enum(L, "NEWLINE", (lua_Integer)cocos2d::ui::RichElement::Type::NEWLINE);
    oluacls_enum(L, "TEXT", (lua_Integer)cocos2d::ui::RichElement::Type::TEXT);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_RichElement_Type(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.RichElement.Type")) {
        luaL_error(L, "class not found: cocos2d::ui::RichElement::Type");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_ui_RichElement_equalType(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichElement *self = nullptr;
    cocos2d::ui::RichElement::Type arg1 = (cocos2d::ui::RichElement::Type)0;       /** type */

    olua_to_object(L, 1, &self, "ccui.RichElement");
    olua_check_enum(L, 2, &arg1);

    // bool equalType(cocos2d::ui::RichElement::Type type)
    bool ret = self->equalType(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_RichElement_init(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichElement *self = nullptr;
    int arg1 = 0;       /** tag */
    cocos2d::Color3B arg2;       /** color */
    uint8_t arg3 = 0;       /** opacity */

    olua_to_object(L, 1, &self, "ccui.RichElement");
    olua_check_integer(L, 2, &arg1);
    olua_check_cocos2d_Color3B(L, 3, &arg2);
    olua_check_integer(L, 4, &arg3);

    // bool init(int tag, const cocos2d::Color3B &color, uint8_t opacity)
    bool ret = self->init(arg1, arg2, arg3);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_RichElement_new(lua_State *L)
{
    olua_startinvoke(L);

    // cocos2d::ui::RichElement()
    cocos2d::ui::RichElement *ret = new cocos2d::ui::RichElement();
    int num_ret = olua_push_object(L, ret, "ccui.RichElement");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_RichElement_setColor(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichElement *self = nullptr;
    cocos2d::Color3B arg1;       /** color */

    olua_to_object(L, 1, &self, "ccui.RichElement");
    olua_check_cocos2d_Color3B(L, 2, &arg1);

    // void setColor(const cocos2d::Color3B &color)
    self->setColor(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_cls_ccui_RichElement(lua_State *L)
{
    oluacls_class<cocos2d::ui::RichElement, cocos2d::Ref>(L, "ccui.RichElement");
    oluacls_func(L, "equalType", _olua_fun_cocos2d_ui_RichElement_equalType);
    oluacls_func(L, "init", _olua_fun_cocos2d_ui_RichElement_init);
    oluacls_func(L, "new", _olua_fun_cocos2d_ui_RichElement_new);
    oluacls_func(L, "setColor", _olua_fun_cocos2d_ui_RichElement_setColor);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_RichElement(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.RichElement")) {
        luaL_error(L, "class not found: cocos2d::ui::RichElement");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_ui_RichElementText_create$1(lua_State *L)
{
    olua_startinvoke(L);

    int arg1 = 0;       /** tag */
    cocos2d::Color3B arg2;       /** color */
    uint8_t arg3 = 0;       /** opacity */
    std::string arg4;       /** text */
    std::string arg5;       /** fontName */
    float arg6 = 0;       /** fontSize */
    uint32_t arg7 = 0;       /** flags */
    std::string arg8;       /** url */
    cocos2d::Color3B arg9;       /** outlineColor */
    int arg10 = 0;       /** outlineSize */
    cocos2d::Color3B arg11;       /** shadowColor */
    cocos2d::Size *arg12;       /** shadowOffset */
    int arg13 = 0;       /** shadowBlurRadius */
    cocos2d::Color3B arg14;       /** glowColor */

    olua_check_integer(L, 1, &arg1);
    olua_check_cocos2d_Color3B(L, 2, &arg2);
    olua_check_integer(L, 3, &arg3);
    olua_check_string(L, 4, &arg4);
    olua_check_string(L, 5, &arg5);
    olua_check_number(L, 6, &arg6);
    olua_check_integer(L, 7, &arg7);
    olua_check_string(L, 8, &arg8);
    olua_check_cocos2d_Color3B(L, 9, &arg9);
    olua_check_integer(L, 10, &arg10);
    olua_check_cocos2d_Color3B(L, 11, &arg11);
    olua_check_object(L, 12, &arg12, "cc.Size");
    olua_check_integer(L, 13, &arg13);
    olua_check_cocos2d_Color3B(L, 14, &arg14);

    // static cocos2d::ui::RichElementText *create(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &text, const std::string &fontName, float fontSize, @optional uint32_t flags, @optional const std::string &url, @optional const cocos2d::Color3B &outlineColor, @optional int outlineSize, @optional const cocos2d::Color3B &shadowColor, @optional const cocos2d::Size &shadowOffset, @optional int shadowBlurRadius, @optional const cocos2d::Color3B &glowColor)
    cocos2d::ui::RichElementText *ret = cocos2d::ui::RichElementText::create(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, *arg12, arg13, arg14);
    int num_ret = olua_push_object(L, ret, "ccui.RichElementText");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_RichElementText_create$2(lua_State *L)
{
    olua_startinvoke(L);

    int arg1 = 0;       /** tag */
    cocos2d::Color3B arg2;       /** color */
    uint8_t arg3 = 0;       /** opacity */
    std::string arg4;       /** text */
    std::string arg5;       /** fontName */
    float arg6 = 0;       /** fontSize */

    olua_check_integer(L, 1, &arg1);
    olua_check_cocos2d_Color3B(L, 2, &arg2);
    olua_check_integer(L, 3, &arg3);
    olua_check_string(L, 4, &arg4);
    olua_check_string(L, 5, &arg5);
    olua_check_number(L, 6, &arg6);

    // static cocos2d::ui::RichElementText *create(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &text, const std::string &fontName, float fontSize)
    cocos2d::ui::RichElementText *ret = cocos2d::ui::RichElementText::create(arg1, arg2, arg3, arg4, arg5, arg6);
    int num_ret = olua_push_object(L, ret, "ccui.RichElementText");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_RichElementText_create$3(lua_State *L)
{
    olua_startinvoke(L);

    int arg1 = 0;       /** tag */
    cocos2d::Color3B arg2;       /** color */
    uint8_t arg3 = 0;       /** opacity */
    std::string arg4;       /** text */
    std::string arg5;       /** fontName */
    float arg6 = 0;       /** fontSize */
    uint32_t arg7 = 0;       /** flags */

    olua_check_integer(L, 1, &arg1);
    olua_check_cocos2d_Color3B(L, 2, &arg2);
    olua_check_integer(L, 3, &arg3);
    olua_check_string(L, 4, &arg4);
    olua_check_string(L, 5, &arg5);
    olua_check_number(L, 6, &arg6);
    olua_check_integer(L, 7, &arg7);

    // static cocos2d::ui::RichElementText *create(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &text, const std::string &fontName, float fontSize, @optional uint32_t flags)
    cocos2d::ui::RichElementText *ret = cocos2d::ui::RichElementText::create(arg1, arg2, arg3, arg4, arg5, arg6, arg7);
    int num_ret = olua_push_object(L, ret, "ccui.RichElementText");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_RichElementText_create$4(lua_State *L)
{
    olua_startinvoke(L);

    int arg1 = 0;       /** tag */
    cocos2d::Color3B arg2;       /** color */
    uint8_t arg3 = 0;       /** opacity */
    std::string arg4;       /** text */
    std::string arg5;       /** fontName */
    float arg6 = 0;       /** fontSize */
    uint32_t arg7 = 0;       /** flags */
    std::string arg8;       /** url */

    olua_check_integer(L, 1, &arg1);
    olua_check_cocos2d_Color3B(L, 2, &arg2);
    olua_check_integer(L, 3, &arg3);
    olua_check_string(L, 4, &arg4);
    olua_check_string(L, 5, &arg5);
    olua_check_number(L, 6, &arg6);
    olua_check_integer(L, 7, &arg7);
    olua_check_string(L, 8, &arg8);

    // static cocos2d::ui::RichElementText *create(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &text, const std::string &fontName, float fontSize, @optional uint32_t flags, @optional const std::string &url)
    cocos2d::ui::RichElementText *ret = cocos2d::ui::RichElementText::create(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
    int num_ret = olua_push_object(L, ret, "ccui.RichElementText");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_RichElementText_create$5(lua_State *L)
{
    olua_startinvoke(L);

    int arg1 = 0;       /** tag */
    cocos2d::Color3B arg2;       /** color */
    uint8_t arg3 = 0;       /** opacity */
    std::string arg4;       /** text */
    std::string arg5;       /** fontName */
    float arg6 = 0;       /** fontSize */
    uint32_t arg7 = 0;       /** flags */
    std::string arg8;       /** url */
    cocos2d::Color3B arg9;       /** outlineColor */

    olua_check_integer(L, 1, &arg1);
    olua_check_cocos2d_Color3B(L, 2, &arg2);
    olua_check_integer(L, 3, &arg3);
    olua_check_string(L, 4, &arg4);
    olua_check_string(L, 5, &arg5);
    olua_check_number(L, 6, &arg6);
    olua_check_integer(L, 7, &arg7);
    olua_check_string(L, 8, &arg8);
    olua_check_cocos2d_Color3B(L, 9, &arg9);

    // static cocos2d::ui::RichElementText *create(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &text, const std::string &fontName, float fontSize, @optional uint32_t flags, @optional const std::string &url, @optional const cocos2d::Color3B &outlineColor)
    cocos2d::ui::RichElementText *ret = cocos2d::ui::RichElementText::create(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
    int num_ret = olua_push_object(L, ret, "ccui.RichElementText");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_RichElementText_create$6(lua_State *L)
{
    olua_startinvoke(L);

    int arg1 = 0;       /** tag */
    cocos2d::Color3B arg2;       /** color */
    uint8_t arg3 = 0;       /** opacity */
    std::string arg4;       /** text */
    std::string arg5;       /** fontName */
    float arg6 = 0;       /** fontSize */
    uint32_t arg7 = 0;       /** flags */
    std::string arg8;       /** url */
    cocos2d::Color3B arg9;       /** outlineColor */
    int arg10 = 0;       /** outlineSize */

    olua_check_integer(L, 1, &arg1);
    olua_check_cocos2d_Color3B(L, 2, &arg2);
    olua_check_integer(L, 3, &arg3);
    olua_check_string(L, 4, &arg4);
    olua_check_string(L, 5, &arg5);
    olua_check_number(L, 6, &arg6);
    olua_check_integer(L, 7, &arg7);
    olua_check_string(L, 8, &arg8);
    olua_check_cocos2d_Color3B(L, 9, &arg9);
    olua_check_integer(L, 10, &arg10);

    // static cocos2d::ui::RichElementText *create(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &text, const std::string &fontName, float fontSize, @optional uint32_t flags, @optional const std::string &url, @optional const cocos2d::Color3B &outlineColor, @optional int outlineSize)
    cocos2d::ui::RichElementText *ret = cocos2d::ui::RichElementText::create(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10);
    int num_ret = olua_push_object(L, ret, "ccui.RichElementText");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_RichElementText_create$7(lua_State *L)
{
    olua_startinvoke(L);

    int arg1 = 0;       /** tag */
    cocos2d::Color3B arg2;       /** color */
    uint8_t arg3 = 0;       /** opacity */
    std::string arg4;       /** text */
    std::string arg5;       /** fontName */
    float arg6 = 0;       /** fontSize */
    uint32_t arg7 = 0;       /** flags */
    std::string arg8;       /** url */
    cocos2d::Color3B arg9;       /** outlineColor */
    int arg10 = 0;       /** outlineSize */
    cocos2d::Color3B arg11;       /** shadowColor */

    olua_check_integer(L, 1, &arg1);
    olua_check_cocos2d_Color3B(L, 2, &arg2);
    olua_check_integer(L, 3, &arg3);
    olua_check_string(L, 4, &arg4);
    olua_check_string(L, 5, &arg5);
    olua_check_number(L, 6, &arg6);
    olua_check_integer(L, 7, &arg7);
    olua_check_string(L, 8, &arg8);
    olua_check_cocos2d_Color3B(L, 9, &arg9);
    olua_check_integer(L, 10, &arg10);
    olua_check_cocos2d_Color3B(L, 11, &arg11);

    // static cocos2d::ui::RichElementText *create(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &text, const std::string &fontName, float fontSize, @optional uint32_t flags, @optional const std::string &url, @optional const cocos2d::Color3B &outlineColor, @optional int outlineSize, @optional const cocos2d::Color3B &shadowColor)
    cocos2d::ui::RichElementText *ret = cocos2d::ui::RichElementText::create(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11);
    int num_ret = olua_push_object(L, ret, "ccui.RichElementText");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_RichElementText_create$8(lua_State *L)
{
    olua_startinvoke(L);

    int arg1 = 0;       /** tag */
    cocos2d::Color3B arg2;       /** color */
    uint8_t arg3 = 0;       /** opacity */
    std::string arg4;       /** text */
    std::string arg5;       /** fontName */
    float arg6 = 0;       /** fontSize */
    uint32_t arg7 = 0;       /** flags */
    std::string arg8;       /** url */
    cocos2d::Color3B arg9;       /** outlineColor */
    int arg10 = 0;       /** outlineSize */
    cocos2d::Color3B arg11;       /** shadowColor */
    cocos2d::Size *arg12;       /** shadowOffset */

    olua_check_integer(L, 1, &arg1);
    olua_check_cocos2d_Color3B(L, 2, &arg2);
    olua_check_integer(L, 3, &arg3);
    olua_check_string(L, 4, &arg4);
    olua_check_string(L, 5, &arg5);
    olua_check_number(L, 6, &arg6);
    olua_check_integer(L, 7, &arg7);
    olua_check_string(L, 8, &arg8);
    olua_check_cocos2d_Color3B(L, 9, &arg9);
    olua_check_integer(L, 10, &arg10);
    olua_check_cocos2d_Color3B(L, 11, &arg11);
    olua_check_object(L, 12, &arg12, "cc.Size");

    // static cocos2d::ui::RichElementText *create(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &text, const std::string &fontName, float fontSize, @optional uint32_t flags, @optional const std::string &url, @optional const cocos2d::Color3B &outlineColor, @optional int outlineSize, @optional const cocos2d::Color3B &shadowColor, @optional const cocos2d::Size &shadowOffset)
    cocos2d::ui::RichElementText *ret = cocos2d::ui::RichElementText::create(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, *arg12);
    int num_ret = olua_push_object(L, ret, "ccui.RichElementText");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_RichElementText_create$9(lua_State *L)
{
    olua_startinvoke(L);

    int arg1 = 0;       /** tag */
    cocos2d::Color3B arg2;       /** color */
    uint8_t arg3 = 0;       /** opacity */
    std::string arg4;       /** text */
    std::string arg5;       /** fontName */
    float arg6 = 0;       /** fontSize */
    uint32_t arg7 = 0;       /** flags */
    std::string arg8;       /** url */
    cocos2d::Color3B arg9;       /** outlineColor */
    int arg10 = 0;       /** outlineSize */
    cocos2d::Color3B arg11;       /** shadowColor */
    cocos2d::Size *arg12;       /** shadowOffset */
    int arg13 = 0;       /** shadowBlurRadius */

    olua_check_integer(L, 1, &arg1);
    olua_check_cocos2d_Color3B(L, 2, &arg2);
    olua_check_integer(L, 3, &arg3);
    olua_check_string(L, 4, &arg4);
    olua_check_string(L, 5, &arg5);
    olua_check_number(L, 6, &arg6);
    olua_check_integer(L, 7, &arg7);
    olua_check_string(L, 8, &arg8);
    olua_check_cocos2d_Color3B(L, 9, &arg9);
    olua_check_integer(L, 10, &arg10);
    olua_check_cocos2d_Color3B(L, 11, &arg11);
    olua_check_object(L, 12, &arg12, "cc.Size");
    olua_check_integer(L, 13, &arg13);

    // static cocos2d::ui::RichElementText *create(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &text, const std::string &fontName, float fontSize, @optional uint32_t flags, @optional const std::string &url, @optional const cocos2d::Color3B &outlineColor, @optional int outlineSize, @optional const cocos2d::Color3B &shadowColor, @optional const cocos2d::Size &shadowOffset, @optional int shadowBlurRadius)
    cocos2d::ui::RichElementText *ret = cocos2d::ui::RichElementText::create(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, *arg12, arg13);
    int num_ret = olua_push_object(L, ret, "ccui.RichElementText");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_RichElementText_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 6) {
        // if ((olua_is_integer(L, 1)) && (olua_is_cocos2d_Color3B(L, 2)) && (olua_is_integer(L, 3)) && (olua_is_string(L, 4)) && (olua_is_string(L, 5)) && (olua_is_number(L, 6))) {
            // static cocos2d::ui::RichElementText *create(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &text, const std::string &fontName, float fontSize)
            return _olua_fun_cocos2d_ui_RichElementText_create$2(L);
        // }
    }

    if (num_args == 7) {
        // if ((olua_is_integer(L, 1)) && (olua_is_cocos2d_Color3B(L, 2)) && (olua_is_integer(L, 3)) && (olua_is_string(L, 4)) && (olua_is_string(L, 5)) && (olua_is_number(L, 6)) && (olua_is_integer(L, 7))) {
            // static cocos2d::ui::RichElementText *create(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &text, const std::string &fontName, float fontSize, @optional uint32_t flags)
            return _olua_fun_cocos2d_ui_RichElementText_create$3(L);
        // }
    }

    if (num_args == 8) {
        // if ((olua_is_integer(L, 1)) && (olua_is_cocos2d_Color3B(L, 2)) && (olua_is_integer(L, 3)) && (olua_is_string(L, 4)) && (olua_is_string(L, 5)) && (olua_is_number(L, 6)) && (olua_is_integer(L, 7)) && (olua_is_string(L, 8))) {
            // static cocos2d::ui::RichElementText *create(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &text, const std::string &fontName, float fontSize, @optional uint32_t flags, @optional const std::string &url)
            return _olua_fun_cocos2d_ui_RichElementText_create$4(L);
        // }
    }

    if (num_args == 9) {
        // if ((olua_is_integer(L, 1)) && (olua_is_cocos2d_Color3B(L, 2)) && (olua_is_integer(L, 3)) && (olua_is_string(L, 4)) && (olua_is_string(L, 5)) && (olua_is_number(L, 6)) && (olua_is_integer(L, 7)) && (olua_is_string(L, 8)) && (olua_is_cocos2d_Color3B(L, 9))) {
            // static cocos2d::ui::RichElementText *create(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &text, const std::string &fontName, float fontSize, @optional uint32_t flags, @optional const std::string &url, @optional const cocos2d::Color3B &outlineColor)
            return _olua_fun_cocos2d_ui_RichElementText_create$5(L);
        // }
    }

    if (num_args == 10) {
        // if ((olua_is_integer(L, 1)) && (olua_is_cocos2d_Color3B(L, 2)) && (olua_is_integer(L, 3)) && (olua_is_string(L, 4)) && (olua_is_string(L, 5)) && (olua_is_number(L, 6)) && (olua_is_integer(L, 7)) && (olua_is_string(L, 8)) && (olua_is_cocos2d_Color3B(L, 9)) && (olua_is_integer(L, 10))) {
            // static cocos2d::ui::RichElementText *create(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &text, const std::string &fontName, float fontSize, @optional uint32_t flags, @optional const std::string &url, @optional const cocos2d::Color3B &outlineColor, @optional int outlineSize)
            return _olua_fun_cocos2d_ui_RichElementText_create$6(L);
        // }
    }

    if (num_args == 11) {
        // if ((olua_is_integer(L, 1)) && (olua_is_cocos2d_Color3B(L, 2)) && (olua_is_integer(L, 3)) && (olua_is_string(L, 4)) && (olua_is_string(L, 5)) && (olua_is_number(L, 6)) && (olua_is_integer(L, 7)) && (olua_is_string(L, 8)) && (olua_is_cocos2d_Color3B(L, 9)) && (olua_is_integer(L, 10)) && (olua_is_cocos2d_Color3B(L, 11))) {
            // static cocos2d::ui::RichElementText *create(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &text, const std::string &fontName, float fontSize, @optional uint32_t flags, @optional const std::string &url, @optional const cocos2d::Color3B &outlineColor, @optional int outlineSize, @optional const cocos2d::Color3B &shadowColor)
            return _olua_fun_cocos2d_ui_RichElementText_create$7(L);
        // }
    }

    if (num_args == 12) {
        // if ((olua_is_integer(L, 1)) && (olua_is_cocos2d_Color3B(L, 2)) && (olua_is_integer(L, 3)) && (olua_is_string(L, 4)) && (olua_is_string(L, 5)) && (olua_is_number(L, 6)) && (olua_is_integer(L, 7)) && (olua_is_string(L, 8)) && (olua_is_cocos2d_Color3B(L, 9)) && (olua_is_integer(L, 10)) && (olua_is_cocos2d_Color3B(L, 11)) && (olua_is_object(L, 12, "cc.Size"))) {
            // static cocos2d::ui::RichElementText *create(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &text, const std::string &fontName, float fontSize, @optional uint32_t flags, @optional const std::string &url, @optional const cocos2d::Color3B &outlineColor, @optional int outlineSize, @optional const cocos2d::Color3B &shadowColor, @optional const cocos2d::Size &shadowOffset)
            return _olua_fun_cocos2d_ui_RichElementText_create$8(L);
        // }
    }

    if (num_args == 13) {
        // if ((olua_is_integer(L, 1)) && (olua_is_cocos2d_Color3B(L, 2)) && (olua_is_integer(L, 3)) && (olua_is_string(L, 4)) && (olua_is_string(L, 5)) && (olua_is_number(L, 6)) && (olua_is_integer(L, 7)) && (olua_is_string(L, 8)) && (olua_is_cocos2d_Color3B(L, 9)) && (olua_is_integer(L, 10)) && (olua_is_cocos2d_Color3B(L, 11)) && (olua_is_object(L, 12, "cc.Size")) && (olua_is_integer(L, 13))) {
            // static cocos2d::ui::RichElementText *create(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &text, const std::string &fontName, float fontSize, @optional uint32_t flags, @optional const std::string &url, @optional const cocos2d::Color3B &outlineColor, @optional int outlineSize, @optional const cocos2d::Color3B &shadowColor, @optional const cocos2d::Size &shadowOffset, @optional int shadowBlurRadius)
            return _olua_fun_cocos2d_ui_RichElementText_create$9(L);
        // }
    }

    if (num_args == 14) {
        // if ((olua_is_integer(L, 1)) && (olua_is_cocos2d_Color3B(L, 2)) && (olua_is_integer(L, 3)) && (olua_is_string(L, 4)) && (olua_is_string(L, 5)) && (olua_is_number(L, 6)) && (olua_is_integer(L, 7)) && (olua_is_string(L, 8)) && (olua_is_cocos2d_Color3B(L, 9)) && (olua_is_integer(L, 10)) && (olua_is_cocos2d_Color3B(L, 11)) && (olua_is_object(L, 12, "cc.Size")) && (olua_is_integer(L, 13)) && (olua_is_cocos2d_Color3B(L, 14))) {
            // static cocos2d::ui::RichElementText *create(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &text, const std::string &fontName, float fontSize, @optional uint32_t flags, @optional const std::string &url, @optional const cocos2d::Color3B &outlineColor, @optional int outlineSize, @optional const cocos2d::Color3B &shadowColor, @optional const cocos2d::Size &shadowOffset, @optional int shadowBlurRadius, @optional const cocos2d::Color3B &glowColor)
            return _olua_fun_cocos2d_ui_RichElementText_create$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::RichElementText::create' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_RichElementText_init$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichElementText *self = nullptr;
    int arg1 = 0;       /** tag */
    cocos2d::Color3B arg2;       /** color */
    uint8_t arg3 = 0;       /** opacity */
    std::string arg4;       /** text */
    std::string arg5;       /** fontName */
    float arg6 = 0;       /** fontSize */
    uint32_t arg7 = 0;       /** flags */
    std::string arg8;       /** url */
    cocos2d::Color3B arg9;       /** outlineColor */
    int arg10 = 0;       /** outlineSize */
    cocos2d::Color3B arg11;       /** shadowColor */
    cocos2d::Size *arg12;       /** shadowOffset */
    int arg13 = 0;       /** shadowBlurRadius */
    cocos2d::Color3B arg14;       /** glowColor */

    olua_to_object(L, 1, &self, "ccui.RichElementText");
    olua_check_integer(L, 2, &arg1);
    olua_check_cocos2d_Color3B(L, 3, &arg2);
    olua_check_integer(L, 4, &arg3);
    olua_check_string(L, 5, &arg4);
    olua_check_string(L, 6, &arg5);
    olua_check_number(L, 7, &arg6);
    olua_check_integer(L, 8, &arg7);
    olua_check_string(L, 9, &arg8);
    olua_check_cocos2d_Color3B(L, 10, &arg9);
    olua_check_integer(L, 11, &arg10);
    olua_check_cocos2d_Color3B(L, 12, &arg11);
    olua_check_object(L, 13, &arg12, "cc.Size");
    olua_check_integer(L, 14, &arg13);
    olua_check_cocos2d_Color3B(L, 15, &arg14);

    // bool init(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &text, const std::string &fontName, float fontSize, uint32_t flags, const std::string &url, @optional const cocos2d::Color3B &outlineColor, @optional int outlineSize, @optional const cocos2d::Color3B &shadowColor, @optional const cocos2d::Size &shadowOffset, @optional int shadowBlurRadius, @optional const cocos2d::Color3B &glowColor)
    bool ret = self->init(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, *arg12, arg13, arg14);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_RichElementText_init$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichElementText *self = nullptr;
    int arg1 = 0;       /** tag */
    cocos2d::Color3B arg2;       /** color */
    uint8_t arg3 = 0;       /** opacity */
    std::string arg4;       /** text */
    std::string arg5;       /** fontName */
    float arg6 = 0;       /** fontSize */
    uint32_t arg7 = 0;       /** flags */
    std::string arg8;       /** url */

    olua_to_object(L, 1, &self, "ccui.RichElementText");
    olua_check_integer(L, 2, &arg1);
    olua_check_cocos2d_Color3B(L, 3, &arg2);
    olua_check_integer(L, 4, &arg3);
    olua_check_string(L, 5, &arg4);
    olua_check_string(L, 6, &arg5);
    olua_check_number(L, 7, &arg6);
    olua_check_integer(L, 8, &arg7);
    olua_check_string(L, 9, &arg8);

    // bool init(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &text, const std::string &fontName, float fontSize, uint32_t flags, const std::string &url)
    bool ret = self->init(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_RichElementText_init$3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichElementText *self = nullptr;
    int arg1 = 0;       /** tag */
    cocos2d::Color3B arg2;       /** color */
    uint8_t arg3 = 0;       /** opacity */
    std::string arg4;       /** text */
    std::string arg5;       /** fontName */
    float arg6 = 0;       /** fontSize */
    uint32_t arg7 = 0;       /** flags */
    std::string arg8;       /** url */
    cocos2d::Color3B arg9;       /** outlineColor */

    olua_to_object(L, 1, &self, "ccui.RichElementText");
    olua_check_integer(L, 2, &arg1);
    olua_check_cocos2d_Color3B(L, 3, &arg2);
    olua_check_integer(L, 4, &arg3);
    olua_check_string(L, 5, &arg4);
    olua_check_string(L, 6, &arg5);
    olua_check_number(L, 7, &arg6);
    olua_check_integer(L, 8, &arg7);
    olua_check_string(L, 9, &arg8);
    olua_check_cocos2d_Color3B(L, 10, &arg9);

    // bool init(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &text, const std::string &fontName, float fontSize, uint32_t flags, const std::string &url, @optional const cocos2d::Color3B &outlineColor)
    bool ret = self->init(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_RichElementText_init$4(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichElementText *self = nullptr;
    int arg1 = 0;       /** tag */
    cocos2d::Color3B arg2;       /** color */
    uint8_t arg3 = 0;       /** opacity */
    std::string arg4;       /** text */
    std::string arg5;       /** fontName */
    float arg6 = 0;       /** fontSize */
    uint32_t arg7 = 0;       /** flags */
    std::string arg8;       /** url */
    cocos2d::Color3B arg9;       /** outlineColor */
    int arg10 = 0;       /** outlineSize */

    olua_to_object(L, 1, &self, "ccui.RichElementText");
    olua_check_integer(L, 2, &arg1);
    olua_check_cocos2d_Color3B(L, 3, &arg2);
    olua_check_integer(L, 4, &arg3);
    olua_check_string(L, 5, &arg4);
    olua_check_string(L, 6, &arg5);
    olua_check_number(L, 7, &arg6);
    olua_check_integer(L, 8, &arg7);
    olua_check_string(L, 9, &arg8);
    olua_check_cocos2d_Color3B(L, 10, &arg9);
    olua_check_integer(L, 11, &arg10);

    // bool init(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &text, const std::string &fontName, float fontSize, uint32_t flags, const std::string &url, @optional const cocos2d::Color3B &outlineColor, @optional int outlineSize)
    bool ret = self->init(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_RichElementText_init$5(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichElementText *self = nullptr;
    int arg1 = 0;       /** tag */
    cocos2d::Color3B arg2;       /** color */
    uint8_t arg3 = 0;       /** opacity */
    std::string arg4;       /** text */
    std::string arg5;       /** fontName */
    float arg6 = 0;       /** fontSize */
    uint32_t arg7 = 0;       /** flags */
    std::string arg8;       /** url */
    cocos2d::Color3B arg9;       /** outlineColor */
    int arg10 = 0;       /** outlineSize */
    cocos2d::Color3B arg11;       /** shadowColor */

    olua_to_object(L, 1, &self, "ccui.RichElementText");
    olua_check_integer(L, 2, &arg1);
    olua_check_cocos2d_Color3B(L, 3, &arg2);
    olua_check_integer(L, 4, &arg3);
    olua_check_string(L, 5, &arg4);
    olua_check_string(L, 6, &arg5);
    olua_check_number(L, 7, &arg6);
    olua_check_integer(L, 8, &arg7);
    olua_check_string(L, 9, &arg8);
    olua_check_cocos2d_Color3B(L, 10, &arg9);
    olua_check_integer(L, 11, &arg10);
    olua_check_cocos2d_Color3B(L, 12, &arg11);

    // bool init(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &text, const std::string &fontName, float fontSize, uint32_t flags, const std::string &url, @optional const cocos2d::Color3B &outlineColor, @optional int outlineSize, @optional const cocos2d::Color3B &shadowColor)
    bool ret = self->init(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_RichElementText_init$6(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichElementText *self = nullptr;
    int arg1 = 0;       /** tag */
    cocos2d::Color3B arg2;       /** color */
    uint8_t arg3 = 0;       /** opacity */
    std::string arg4;       /** text */
    std::string arg5;       /** fontName */
    float arg6 = 0;       /** fontSize */
    uint32_t arg7 = 0;       /** flags */
    std::string arg8;       /** url */
    cocos2d::Color3B arg9;       /** outlineColor */
    int arg10 = 0;       /** outlineSize */
    cocos2d::Color3B arg11;       /** shadowColor */
    cocos2d::Size *arg12;       /** shadowOffset */

    olua_to_object(L, 1, &self, "ccui.RichElementText");
    olua_check_integer(L, 2, &arg1);
    olua_check_cocos2d_Color3B(L, 3, &arg2);
    olua_check_integer(L, 4, &arg3);
    olua_check_string(L, 5, &arg4);
    olua_check_string(L, 6, &arg5);
    olua_check_number(L, 7, &arg6);
    olua_check_integer(L, 8, &arg7);
    olua_check_string(L, 9, &arg8);
    olua_check_cocos2d_Color3B(L, 10, &arg9);
    olua_check_integer(L, 11, &arg10);
    olua_check_cocos2d_Color3B(L, 12, &arg11);
    olua_check_object(L, 13, &arg12, "cc.Size");

    // bool init(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &text, const std::string &fontName, float fontSize, uint32_t flags, const std::string &url, @optional const cocos2d::Color3B &outlineColor, @optional int outlineSize, @optional const cocos2d::Color3B &shadowColor, @optional const cocos2d::Size &shadowOffset)
    bool ret = self->init(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, *arg12);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_RichElementText_init$7(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichElementText *self = nullptr;
    int arg1 = 0;       /** tag */
    cocos2d::Color3B arg2;       /** color */
    uint8_t arg3 = 0;       /** opacity */
    std::string arg4;       /** text */
    std::string arg5;       /** fontName */
    float arg6 = 0;       /** fontSize */
    uint32_t arg7 = 0;       /** flags */
    std::string arg8;       /** url */
    cocos2d::Color3B arg9;       /** outlineColor */
    int arg10 = 0;       /** outlineSize */
    cocos2d::Color3B arg11;       /** shadowColor */
    cocos2d::Size *arg12;       /** shadowOffset */
    int arg13 = 0;       /** shadowBlurRadius */

    olua_to_object(L, 1, &self, "ccui.RichElementText");
    olua_check_integer(L, 2, &arg1);
    olua_check_cocos2d_Color3B(L, 3, &arg2);
    olua_check_integer(L, 4, &arg3);
    olua_check_string(L, 5, &arg4);
    olua_check_string(L, 6, &arg5);
    olua_check_number(L, 7, &arg6);
    olua_check_integer(L, 8, &arg7);
    olua_check_string(L, 9, &arg8);
    olua_check_cocos2d_Color3B(L, 10, &arg9);
    olua_check_integer(L, 11, &arg10);
    olua_check_cocos2d_Color3B(L, 12, &arg11);
    olua_check_object(L, 13, &arg12, "cc.Size");
    olua_check_integer(L, 14, &arg13);

    // bool init(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &text, const std::string &fontName, float fontSize, uint32_t flags, const std::string &url, @optional const cocos2d::Color3B &outlineColor, @optional int outlineSize, @optional const cocos2d::Color3B &shadowColor, @optional const cocos2d::Size &shadowOffset, @optional int shadowBlurRadius)
    bool ret = self->init(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, *arg12, arg13);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_RichElementText_init(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 9) {
        // if ((olua_is_object(L, 1, "ccui.RichElementText")) && (olua_is_integer(L, 2)) && (olua_is_cocos2d_Color3B(L, 3)) && (olua_is_integer(L, 4)) && (olua_is_string(L, 5)) && (olua_is_string(L, 6)) && (olua_is_number(L, 7)) && (olua_is_integer(L, 8)) && (olua_is_string(L, 9))) {
            // bool init(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &text, const std::string &fontName, float fontSize, uint32_t flags, const std::string &url)
            return _olua_fun_cocos2d_ui_RichElementText_init$2(L);
        // }
    }

    if (num_args == 10) {
        // if ((olua_is_object(L, 1, "ccui.RichElementText")) && (olua_is_integer(L, 2)) && (olua_is_cocos2d_Color3B(L, 3)) && (olua_is_integer(L, 4)) && (olua_is_string(L, 5)) && (olua_is_string(L, 6)) && (olua_is_number(L, 7)) && (olua_is_integer(L, 8)) && (olua_is_string(L, 9)) && (olua_is_cocos2d_Color3B(L, 10))) {
            // bool init(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &text, const std::string &fontName, float fontSize, uint32_t flags, const std::string &url, @optional const cocos2d::Color3B &outlineColor)
            return _olua_fun_cocos2d_ui_RichElementText_init$3(L);
        // }
    }

    if (num_args == 11) {
        // if ((olua_is_object(L, 1, "ccui.RichElementText")) && (olua_is_integer(L, 2)) && (olua_is_cocos2d_Color3B(L, 3)) && (olua_is_integer(L, 4)) && (olua_is_string(L, 5)) && (olua_is_string(L, 6)) && (olua_is_number(L, 7)) && (olua_is_integer(L, 8)) && (olua_is_string(L, 9)) && (olua_is_cocos2d_Color3B(L, 10)) && (olua_is_integer(L, 11))) {
            // bool init(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &text, const std::string &fontName, float fontSize, uint32_t flags, const std::string &url, @optional const cocos2d::Color3B &outlineColor, @optional int outlineSize)
            return _olua_fun_cocos2d_ui_RichElementText_init$4(L);
        // }
    }

    if (num_args == 12) {
        // if ((olua_is_object(L, 1, "ccui.RichElementText")) && (olua_is_integer(L, 2)) && (olua_is_cocos2d_Color3B(L, 3)) && (olua_is_integer(L, 4)) && (olua_is_string(L, 5)) && (olua_is_string(L, 6)) && (olua_is_number(L, 7)) && (olua_is_integer(L, 8)) && (olua_is_string(L, 9)) && (olua_is_cocos2d_Color3B(L, 10)) && (olua_is_integer(L, 11)) && (olua_is_cocos2d_Color3B(L, 12))) {
            // bool init(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &text, const std::string &fontName, float fontSize, uint32_t flags, const std::string &url, @optional const cocos2d::Color3B &outlineColor, @optional int outlineSize, @optional const cocos2d::Color3B &shadowColor)
            return _olua_fun_cocos2d_ui_RichElementText_init$5(L);
        // }
    }

    if (num_args == 13) {
        // if ((olua_is_object(L, 1, "ccui.RichElementText")) && (olua_is_integer(L, 2)) && (olua_is_cocos2d_Color3B(L, 3)) && (olua_is_integer(L, 4)) && (olua_is_string(L, 5)) && (olua_is_string(L, 6)) && (olua_is_number(L, 7)) && (olua_is_integer(L, 8)) && (olua_is_string(L, 9)) && (olua_is_cocos2d_Color3B(L, 10)) && (olua_is_integer(L, 11)) && (olua_is_cocos2d_Color3B(L, 12)) && (olua_is_object(L, 13, "cc.Size"))) {
            // bool init(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &text, const std::string &fontName, float fontSize, uint32_t flags, const std::string &url, @optional const cocos2d::Color3B &outlineColor, @optional int outlineSize, @optional const cocos2d::Color3B &shadowColor, @optional const cocos2d::Size &shadowOffset)
            return _olua_fun_cocos2d_ui_RichElementText_init$6(L);
        // }
    }

    if (num_args == 14) {
        // if ((olua_is_object(L, 1, "ccui.RichElementText")) && (olua_is_integer(L, 2)) && (olua_is_cocos2d_Color3B(L, 3)) && (olua_is_integer(L, 4)) && (olua_is_string(L, 5)) && (olua_is_string(L, 6)) && (olua_is_number(L, 7)) && (olua_is_integer(L, 8)) && (olua_is_string(L, 9)) && (olua_is_cocos2d_Color3B(L, 10)) && (olua_is_integer(L, 11)) && (olua_is_cocos2d_Color3B(L, 12)) && (olua_is_object(L, 13, "cc.Size")) && (olua_is_integer(L, 14))) {
            // bool init(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &text, const std::string &fontName, float fontSize, uint32_t flags, const std::string &url, @optional const cocos2d::Color3B &outlineColor, @optional int outlineSize, @optional const cocos2d::Color3B &shadowColor, @optional const cocos2d::Size &shadowOffset, @optional int shadowBlurRadius)
            return _olua_fun_cocos2d_ui_RichElementText_init$7(L);
        // }
    }

    if (num_args == 15) {
        // if ((olua_is_object(L, 1, "ccui.RichElementText")) && (olua_is_integer(L, 2)) && (olua_is_cocos2d_Color3B(L, 3)) && (olua_is_integer(L, 4)) && (olua_is_string(L, 5)) && (olua_is_string(L, 6)) && (olua_is_number(L, 7)) && (olua_is_integer(L, 8)) && (olua_is_string(L, 9)) && (olua_is_cocos2d_Color3B(L, 10)) && (olua_is_integer(L, 11)) && (olua_is_cocos2d_Color3B(L, 12)) && (olua_is_object(L, 13, "cc.Size")) && (olua_is_integer(L, 14)) && (olua_is_cocos2d_Color3B(L, 15))) {
            // bool init(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &text, const std::string &fontName, float fontSize, uint32_t flags, const std::string &url, @optional const cocos2d::Color3B &outlineColor, @optional int outlineSize, @optional const cocos2d::Color3B &shadowColor, @optional const cocos2d::Size &shadowOffset, @optional int shadowBlurRadius, @optional const cocos2d::Color3B &glowColor)
            return _olua_fun_cocos2d_ui_RichElementText_init$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::RichElementText::init' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_RichElementText_new(lua_State *L)
{
    olua_startinvoke(L);

    // cocos2d::ui::RichElementText()
    cocos2d::ui::RichElementText *ret = new cocos2d::ui::RichElementText();
    int num_ret = olua_push_object(L, ret, "ccui.RichElementText");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_cls_ccui_RichElementText(lua_State *L)
{
    oluacls_class<cocos2d::ui::RichElementText, cocos2d::ui::RichElement>(L, "ccui.RichElementText");
    oluacls_func(L, "create", _olua_fun_cocos2d_ui_RichElementText_create);
    oluacls_func(L, "init", _olua_fun_cocos2d_ui_RichElementText_init);
    oluacls_func(L, "new", _olua_fun_cocos2d_ui_RichElementText_new);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_RichElementText(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.RichElementText")) {
        luaL_error(L, "class not found: cocos2d::ui::RichElementText");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_ui_RichElementImage_create$1(lua_State *L)
{
    olua_startinvoke(L);

    int arg1 = 0;       /** tag */
    cocos2d::Color3B arg2;       /** color */
    uint8_t arg3 = 0;       /** opacity */
    std::string arg4;       /** filePath */
    std::string arg5;       /** url */
    cocos2d::ui::Widget::TextureResType arg6 = (cocos2d::ui::Widget::TextureResType)0;       /** texType */

    olua_check_integer(L, 1, &arg1);
    olua_check_cocos2d_Color3B(L, 2, &arg2);
    olua_check_integer(L, 3, &arg3);
    olua_check_string(L, 4, &arg4);
    olua_check_string(L, 5, &arg5);
    olua_check_enum(L, 6, &arg6);

    // static cocos2d::ui::RichElementImage *create(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &filePath, @optional const std::string &url, @optional cocos2d::ui::Widget::TextureResType texType)
    cocos2d::ui::RichElementImage *ret = cocos2d::ui::RichElementImage::create(arg1, arg2, arg3, arg4, arg5, arg6);
    int num_ret = olua_push_object(L, ret, "ccui.RichElementImage");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_RichElementImage_create$2(lua_State *L)
{
    olua_startinvoke(L);

    int arg1 = 0;       /** tag */
    cocos2d::Color3B arg2;       /** color */
    uint8_t arg3 = 0;       /** opacity */
    std::string arg4;       /** filePath */

    olua_check_integer(L, 1, &arg1);
    olua_check_cocos2d_Color3B(L, 2, &arg2);
    olua_check_integer(L, 3, &arg3);
    olua_check_string(L, 4, &arg4);

    // static cocos2d::ui::RichElementImage *create(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &filePath)
    cocos2d::ui::RichElementImage *ret = cocos2d::ui::RichElementImage::create(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_object(L, ret, "ccui.RichElementImage");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_RichElementImage_create$3(lua_State *L)
{
    olua_startinvoke(L);

    int arg1 = 0;       /** tag */
    cocos2d::Color3B arg2;       /** color */
    uint8_t arg3 = 0;       /** opacity */
    std::string arg4;       /** filePath */
    std::string arg5;       /** url */

    olua_check_integer(L, 1, &arg1);
    olua_check_cocos2d_Color3B(L, 2, &arg2);
    olua_check_integer(L, 3, &arg3);
    olua_check_string(L, 4, &arg4);
    olua_check_string(L, 5, &arg5);

    // static cocos2d::ui::RichElementImage *create(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &filePath, @optional const std::string &url)
    cocos2d::ui::RichElementImage *ret = cocos2d::ui::RichElementImage::create(arg1, arg2, arg3, arg4, arg5);
    int num_ret = olua_push_object(L, ret, "ccui.RichElementImage");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_RichElementImage_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 4) {
        // if ((olua_is_integer(L, 1)) && (olua_is_cocos2d_Color3B(L, 2)) && (olua_is_integer(L, 3)) && (olua_is_string(L, 4))) {
            // static cocos2d::ui::RichElementImage *create(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &filePath)
            return _olua_fun_cocos2d_ui_RichElementImage_create$2(L);
        // }
    }

    if (num_args == 5) {
        // if ((olua_is_integer(L, 1)) && (olua_is_cocos2d_Color3B(L, 2)) && (olua_is_integer(L, 3)) && (olua_is_string(L, 4)) && (olua_is_string(L, 5))) {
            // static cocos2d::ui::RichElementImage *create(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &filePath, @optional const std::string &url)
            return _olua_fun_cocos2d_ui_RichElementImage_create$3(L);
        // }
    }

    if (num_args == 6) {
        // if ((olua_is_integer(L, 1)) && (olua_is_cocos2d_Color3B(L, 2)) && (olua_is_integer(L, 3)) && (olua_is_string(L, 4)) && (olua_is_string(L, 5)) && (olua_is_enum(L, 6))) {
            // static cocos2d::ui::RichElementImage *create(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &filePath, @optional const std::string &url, @optional cocos2d::ui::Widget::TextureResType texType)
            return _olua_fun_cocos2d_ui_RichElementImage_create$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::RichElementImage::create' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_RichElementImage_init$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichElementImage *self = nullptr;
    int arg1 = 0;       /** tag */
    cocos2d::Color3B arg2;       /** color */
    uint8_t arg3 = 0;       /** opacity */
    std::string arg4;       /** filePath */
    std::string arg5;       /** url */
    cocos2d::ui::Widget::TextureResType arg6 = (cocos2d::ui::Widget::TextureResType)0;       /** texType */

    olua_to_object(L, 1, &self, "ccui.RichElementImage");
    olua_check_integer(L, 2, &arg1);
    olua_check_cocos2d_Color3B(L, 3, &arg2);
    olua_check_integer(L, 4, &arg3);
    olua_check_string(L, 5, &arg4);
    olua_check_string(L, 6, &arg5);
    olua_check_enum(L, 7, &arg6);

    // bool init(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &filePath, @optional const std::string &url, @optional cocos2d::ui::Widget::TextureResType texType)
    bool ret = self->init(arg1, arg2, arg3, arg4, arg5, arg6);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_RichElementImage_init$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichElementImage *self = nullptr;
    int arg1 = 0;       /** tag */
    cocos2d::Color3B arg2;       /** color */
    uint8_t arg3 = 0;       /** opacity */
    std::string arg4;       /** filePath */

    olua_to_object(L, 1, &self, "ccui.RichElementImage");
    olua_check_integer(L, 2, &arg1);
    olua_check_cocos2d_Color3B(L, 3, &arg2);
    olua_check_integer(L, 4, &arg3);
    olua_check_string(L, 5, &arg4);

    // bool init(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &filePath)
    bool ret = self->init(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_RichElementImage_init$3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichElementImage *self = nullptr;
    int arg1 = 0;       /** tag */
    cocos2d::Color3B arg2;       /** color */
    uint8_t arg3 = 0;       /** opacity */
    std::string arg4;       /** filePath */
    std::string arg5;       /** url */

    olua_to_object(L, 1, &self, "ccui.RichElementImage");
    olua_check_integer(L, 2, &arg1);
    olua_check_cocos2d_Color3B(L, 3, &arg2);
    olua_check_integer(L, 4, &arg3);
    olua_check_string(L, 5, &arg4);
    olua_check_string(L, 6, &arg5);

    // bool init(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &filePath, @optional const std::string &url)
    bool ret = self->init(arg1, arg2, arg3, arg4, arg5);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_RichElementImage_init(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 5) {
        // if ((olua_is_object(L, 1, "ccui.RichElementImage")) && (olua_is_integer(L, 2)) && (olua_is_cocos2d_Color3B(L, 3)) && (olua_is_integer(L, 4)) && (olua_is_string(L, 5))) {
            // bool init(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &filePath)
            return _olua_fun_cocos2d_ui_RichElementImage_init$2(L);
        // }
    }

    if (num_args == 6) {
        // if ((olua_is_object(L, 1, "ccui.RichElementImage")) && (olua_is_integer(L, 2)) && (olua_is_cocos2d_Color3B(L, 3)) && (olua_is_integer(L, 4)) && (olua_is_string(L, 5)) && (olua_is_string(L, 6))) {
            // bool init(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &filePath, @optional const std::string &url)
            return _olua_fun_cocos2d_ui_RichElementImage_init$3(L);
        // }
    }

    if (num_args == 7) {
        // if ((olua_is_object(L, 1, "ccui.RichElementImage")) && (olua_is_integer(L, 2)) && (olua_is_cocos2d_Color3B(L, 3)) && (olua_is_integer(L, 4)) && (olua_is_string(L, 5)) && (olua_is_string(L, 6)) && (olua_is_enum(L, 7))) {
            // bool init(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &filePath, @optional const std::string &url, @optional cocos2d::ui::Widget::TextureResType texType)
            return _olua_fun_cocos2d_ui_RichElementImage_init$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::RichElementImage::init' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_RichElementImage_new(lua_State *L)
{
    olua_startinvoke(L);

    // cocos2d::ui::RichElementImage()
    cocos2d::ui::RichElementImage *ret = new cocos2d::ui::RichElementImage();
    int num_ret = olua_push_object(L, ret, "ccui.RichElementImage");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_RichElementImage_setHeight(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichElementImage *self = nullptr;
    int arg1 = 0;       /** height */

    olua_to_object(L, 1, &self, "ccui.RichElementImage");
    olua_check_integer(L, 2, &arg1);

    // void setHeight(int height)
    self->setHeight(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_RichElementImage_setUrl(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichElementImage *self = nullptr;
    std::string arg1;       /** url */

    olua_to_object(L, 1, &self, "ccui.RichElementImage");
    olua_check_string(L, 2, &arg1);

    // void setUrl(const std::string &url)
    self->setUrl(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_RichElementImage_setWidth(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichElementImage *self = nullptr;
    int arg1 = 0;       /** width */

    olua_to_object(L, 1, &self, "ccui.RichElementImage");
    olua_check_integer(L, 2, &arg1);

    // void setWidth(int width)
    self->setWidth(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_cls_ccui_RichElementImage(lua_State *L)
{
    oluacls_class<cocos2d::ui::RichElementImage, cocos2d::ui::RichElement>(L, "ccui.RichElementImage");
    oluacls_func(L, "create", _olua_fun_cocos2d_ui_RichElementImage_create);
    oluacls_func(L, "init", _olua_fun_cocos2d_ui_RichElementImage_init);
    oluacls_func(L, "new", _olua_fun_cocos2d_ui_RichElementImage_new);
    oluacls_func(L, "setHeight", _olua_fun_cocos2d_ui_RichElementImage_setHeight);
    oluacls_func(L, "setUrl", _olua_fun_cocos2d_ui_RichElementImage_setUrl);
    oluacls_func(L, "setWidth", _olua_fun_cocos2d_ui_RichElementImage_setWidth);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_RichElementImage(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.RichElementImage")) {
        luaL_error(L, "class not found: cocos2d::ui::RichElementImage");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_ui_RichElementCustomNode_create(lua_State *L)
{
    olua_startinvoke(L);

    int arg1 = 0;       /** tag */
    cocos2d::Color3B arg2;       /** color */
    uint8_t arg3 = 0;       /** opacity */
    cocos2d::Node *arg4 = nullptr;       /** customNode */

    olua_check_integer(L, 1, &arg1);
    olua_check_cocos2d_Color3B(L, 2, &arg2);
    olua_check_integer(L, 3, &arg3);
    olua_check_object(L, 4, &arg4, "cc.Node");

    // static cocos2d::ui::RichElementCustomNode *create(int tag, const cocos2d::Color3B &color, uint8_t opacity, cocos2d::Node *customNode)
    cocos2d::ui::RichElementCustomNode *ret = cocos2d::ui::RichElementCustomNode::create(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_object(L, ret, "ccui.RichElementCustomNode");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_RichElementCustomNode_init(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichElementCustomNode *self = nullptr;
    int arg1 = 0;       /** tag */
    cocos2d::Color3B arg2;       /** color */
    uint8_t arg3 = 0;       /** opacity */
    cocos2d::Node *arg4 = nullptr;       /** customNode */

    olua_to_object(L, 1, &self, "ccui.RichElementCustomNode");
    olua_check_integer(L, 2, &arg1);
    olua_check_cocos2d_Color3B(L, 3, &arg2);
    olua_check_integer(L, 4, &arg3);
    olua_check_object(L, 5, &arg4, "cc.Node");

    // bool init(int tag, const cocos2d::Color3B &color, uint8_t opacity, cocos2d::Node *customNode)
    bool ret = self->init(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_RichElementCustomNode_new(lua_State *L)
{
    olua_startinvoke(L);

    // cocos2d::ui::RichElementCustomNode()
    cocos2d::ui::RichElementCustomNode *ret = new cocos2d::ui::RichElementCustomNode();
    int num_ret = olua_push_object(L, ret, "ccui.RichElementCustomNode");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_cls_ccui_RichElementCustomNode(lua_State *L)
{
    oluacls_class<cocos2d::ui::RichElementCustomNode, cocos2d::ui::RichElement>(L, "ccui.RichElementCustomNode");
    oluacls_func(L, "create", _olua_fun_cocos2d_ui_RichElementCustomNode_create);
    oluacls_func(L, "init", _olua_fun_cocos2d_ui_RichElementCustomNode_init);
    oluacls_func(L, "new", _olua_fun_cocos2d_ui_RichElementCustomNode_new);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_RichElementCustomNode(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.RichElementCustomNode")) {
        luaL_error(L, "class not found: cocos2d::ui::RichElementCustomNode");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_ui_RichElementNewLine_create(lua_State *L)
{
    olua_startinvoke(L);

    int arg1 = 0;       /** tag */
    cocos2d::Color3B arg2;       /** color */
    uint8_t arg3 = 0;       /** opacity */

    olua_check_integer(L, 1, &arg1);
    olua_check_cocos2d_Color3B(L, 2, &arg2);
    olua_check_integer(L, 3, &arg3);

    // static cocos2d::ui::RichElementNewLine *create(int tag, const cocos2d::Color3B &color, uint8_t opacity)
    cocos2d::ui::RichElementNewLine *ret = cocos2d::ui::RichElementNewLine::create(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "ccui.RichElementNewLine");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_RichElementNewLine_new(lua_State *L)
{
    olua_startinvoke(L);

    // cocos2d::ui::RichElementNewLine()
    cocos2d::ui::RichElementNewLine *ret = new cocos2d::ui::RichElementNewLine();
    int num_ret = olua_push_object(L, ret, "ccui.RichElementNewLine");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_cls_ccui_RichElementNewLine(lua_State *L)
{
    oluacls_class<cocos2d::ui::RichElementNewLine, cocos2d::ui::RichElement>(L, "ccui.RichElementNewLine");
    oluacls_func(L, "create", _olua_fun_cocos2d_ui_RichElementNewLine_create);
    oluacls_func(L, "new", _olua_fun_cocos2d_ui_RichElementNewLine_new);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_RichElementNewLine(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.RichElementNewLine")) {
        luaL_error(L, "class not found: cocos2d::ui::RichElementNewLine");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_ccui_RichText_WrapMode(lua_State *L)
{
    oluacls_class<cocos2d::ui::RichText::WrapMode>(L, "ccui.RichText.WrapMode");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "WRAP_PER_CHAR", (lua_Integer)cocos2d::ui::RichText::WrapMode::WRAP_PER_CHAR);
    oluacls_enum(L, "WRAP_PER_WORD", (lua_Integer)cocos2d::ui::RichText::WrapMode::WRAP_PER_WORD);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_RichText_WrapMode(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.RichText.WrapMode")) {
        luaL_error(L, "class not found: cocos2d::ui::RichText::WrapMode");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_ccui_RichText_HorizontalAlignment(lua_State *L)
{
    oluacls_class<cocos2d::ui::RichText::HorizontalAlignment>(L, "ccui.RichText.HorizontalAlignment");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "CENTER", (lua_Integer)cocos2d::ui::RichText::HorizontalAlignment::CENTER);
    oluacls_enum(L, "LEFT", (lua_Integer)cocos2d::ui::RichText::HorizontalAlignment::LEFT);
    oluacls_enum(L, "RIGHT", (lua_Integer)cocos2d::ui::RichText::HorizontalAlignment::RIGHT);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_RichText_HorizontalAlignment(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.RichText.HorizontalAlignment")) {
        luaL_error(L, "class not found: cocos2d::ui::RichText::HorizontalAlignment");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_ui_RichText_OpenUrlHandler___call(lua_State *L)
{
    olua_startinvoke(L);

    luaL_checktype(L, -1, LUA_TFUNCTION);
    olua_push_callback(L, (cocos2d::ui::RichText::OpenUrlHandler *)nullptr, "ccui.RichText.OpenUrlHandler");

    olua_endinvoke(L);

    return 1;
}

static int _olua_cls_ccui_RichText_OpenUrlHandler(lua_State *L)
{
    oluacls_class<cocos2d::ui::RichText::OpenUrlHandler>(L, "ccui.RichText.OpenUrlHandler");
    oluacls_func(L, "__call", _olua_fun_cocos2d_ui_RichText_OpenUrlHandler___call);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_RichText_OpenUrlHandler(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.RichText.OpenUrlHandler")) {
        luaL_error(L, "class not found: cocos2d::ui::RichText::OpenUrlHandler");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_ui_RichText_color3BWithString(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;
    std::string arg1;       /** color */

    olua_to_object(L, 1, &self, "ccui.RichText");
    olua_check_string(L, 2, &arg1);

    // cocos2d::Color3B color3BWithString(const std::string &color)
    cocos2d::Color3B ret = self->color3BWithString(arg1);
    int num_ret = olua_push_cocos2d_Color3B(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_RichText_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::ui::RichText *create()
    cocos2d::ui::RichText *ret = cocos2d::ui::RichText::create();
    int num_ret = olua_push_object(L, ret, "ccui.RichText");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_RichText_createWithXML$1(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** xml */
    cocos2d::ValueMap arg2;       /** defaults */
    cocos2d::ui::RichText::OpenUrlHandler arg3;       /** handleOpenUrl */

    olua_check_string(L, 1, &arg1);
    olua_check_cocos2d_ValueMap(L, 2, &arg2);
    olua_check_callback(L, 3, &arg3, "ccui.RichText.OpenUrlHandler");

    void *cb_store = (void *)olua_newobjstub(L, "ccui.RichText");
    std::string cb_tag = "OpenUrlHandler";
    std::string cb_name;
    if (olua_isfunction(L, 3)) {
        cb_name = olua_setcallback(L, cb_store, 3, cb_tag.c_str(), OLUA_TAG_REPLACE);
        olua_Context cb_ctx = olua_context(L);
        // lua_State *ML = olua_mainthread(L);
        arg3 = [cb_store, cb_name, cb_ctx /*, ML */](const std::string &cb_arg1) {
            lua_State *L = olua_mainthread(NULL);
            olua_checkhostthread();

            if (olua_contextequal(L, cb_ctx)) {
                int top = lua_gettop(L);
                olua_push_string(L, cb_arg1);

                olua_callback(L, cb_store, cb_name.c_str(), 1);

                lua_settop(L, top);
            }
        };
    } else {
        olua_removecallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_EQUAL);
        arg3 = nullptr;
    }

    // static cocos2d::ui::RichText *createWithXML(const std::string &xml, @optional const cocos2d::ValueMap &defaults, @optional const cocos2d::ui::RichText::OpenUrlHandler &handleOpenUrl)
    cocos2d::ui::RichText *ret = cocos2d::ui::RichText::createWithXML(arg1, arg2, arg3);
    if (olua_pushobjstub(L, ret, cb_store, "ccui.RichText") == OLUA_OBJ_EXIST) {
        olua_removecallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_EQUAL);
        lua_pushstring(L, cb_name.c_str());
        lua_pushvalue(L, 3);
        olua_setvariable(L, -3);
    } else {
        olua_postpush(L, ret, OLUA_OBJ_NEW);
    };

    olua_endinvoke(L);

    return 1;
}

static int _olua_fun_cocos2d_ui_RichText_createWithXML$2(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** xml */

    olua_check_string(L, 1, &arg1);

    // static cocos2d::ui::RichText *createWithXML(const std::string &xml)
    cocos2d::ui::RichText *ret = cocos2d::ui::RichText::createWithXML(arg1);
    int num_ret = olua_push_object(L, ret, "ccui.RichText");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_RichText_createWithXML$3(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** xml */
    cocos2d::ValueMap arg2;       /** defaults */

    olua_check_string(L, 1, &arg1);
    olua_check_cocos2d_ValueMap(L, 2, &arg2);

    // static cocos2d::ui::RichText *createWithXML(const std::string &xml, @optional const cocos2d::ValueMap &defaults)
    cocos2d::ui::RichText *ret = cocos2d::ui::RichText::createWithXML(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "ccui.RichText");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_RichText_createWithXML(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_string(L, 1))) {
            // static cocos2d::ui::RichText *createWithXML(const std::string &xml)
            return _olua_fun_cocos2d_ui_RichText_createWithXML$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_string(L, 1)) && (olua_is_cocos2d_ValueMap(L, 2))) {
            // static cocos2d::ui::RichText *createWithXML(const std::string &xml, @optional const cocos2d::ValueMap &defaults)
            return _olua_fun_cocos2d_ui_RichText_createWithXML$3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_string(L, 1)) && (olua_is_cocos2d_ValueMap(L, 2)) && (olua_is_callback(L, 3, "ccui.RichText.OpenUrlHandler"))) {
            // static cocos2d::ui::RichText *createWithXML(const std::string &xml, @optional const cocos2d::ValueMap &defaults, @optional const cocos2d::ui::RichText::OpenUrlHandler &handleOpenUrl)
            return _olua_fun_cocos2d_ui_RichText_createWithXML$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::RichText::createWithXML' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_RichText_formatText(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.RichText");

    // void formatText()
    self->formatText();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_RichText_getAnchorFontColor(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.RichText");

    // std::string getAnchorFontColor()
    std::string ret = self->getAnchorFontColor();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_RichText_getAnchorFontColor3B(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.RichText");

    // cocos2d::Color3B getAnchorFontColor3B()
    cocos2d::Color3B ret = self->getAnchorFontColor3B();
    int num_ret = olua_push_cocos2d_Color3B(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_RichText_getAnchorTextGlowColor3B(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.RichText");

    // cocos2d::Color3B getAnchorTextGlowColor3B()
    cocos2d::Color3B ret = self->getAnchorTextGlowColor3B();
    int num_ret = olua_push_cocos2d_Color3B(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_RichText_getAnchorTextOutlineColor3B(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.RichText");

    // cocos2d::Color3B getAnchorTextOutlineColor3B()
    cocos2d::Color3B ret = self->getAnchorTextOutlineColor3B();
    int num_ret = olua_push_cocos2d_Color3B(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_RichText_getAnchorTextOutlineSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.RichText");

    // int getAnchorTextOutlineSize()
    int ret = self->getAnchorTextOutlineSize();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_RichText_getAnchorTextShadowBlurRadius(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.RichText");

    // int getAnchorTextShadowBlurRadius()
    int ret = self->getAnchorTextShadowBlurRadius();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_RichText_getAnchorTextShadowColor3B(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.RichText");

    // cocos2d::Color3B getAnchorTextShadowColor3B()
    cocos2d::Color3B ret = self->getAnchorTextShadowColor3B();
    int num_ret = olua_push_cocos2d_Color3B(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_RichText_getAnchorTextShadowOffset(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.RichText");

    // cocos2d::Size getAnchorTextShadowOffset()
    cocos2d::Size ret = self->getAnchorTextShadowOffset();
    int num_ret = olua_copy_object(L, ret, "cc.Size");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_RichText_getDefaults(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.RichText");

    // cocos2d::ValueMap getDefaults()
    cocos2d::ValueMap ret = self->getDefaults();
    int num_ret = olua_push_cocos2d_ValueMap(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_RichText_getFontColor(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.RichText");

    // std::string getFontColor()
    std::string ret = self->getFontColor();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_RichText_getFontColor3B(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.RichText");

    // cocos2d::Color3B getFontColor3B()
    cocos2d::Color3B ret = self->getFontColor3B();
    int num_ret = olua_push_cocos2d_Color3B(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_RichText_getFontFace(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.RichText");

    // std::string getFontFace()
    std::string ret = self->getFontFace();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_RichText_getFontSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.RichText");

    // float getFontSize()
    float ret = self->getFontSize();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_RichText_getHorizontalAlignment(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.RichText");

    // cocos2d::ui::RichText::HorizontalAlignment getHorizontalAlignment()
    cocos2d::ui::RichText::HorizontalAlignment ret = self->getHorizontalAlignment();
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_RichText_getWrapMode(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.RichText");

    // cocos2d::ui::RichText::WrapMode getWrapMode()
    cocos2d::ui::RichText::WrapMode ret = self->getWrapMode();
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_RichText_insertElement(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;
    cocos2d::ui::RichElement *arg1 = nullptr;       /** element */
    int arg2 = 0;       /** index */

    olua_to_object(L, 1, &self, "ccui.RichText");
    olua_check_object(L, 2, &arg1, "ccui.RichElement");
    olua_check_integer(L, 3, &arg2);

    // void insertElement(cocos2d::ui::RichElement *element, int index)
    self->insertElement(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_RichText_isAnchorTextBoldEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.RichText");

    // bool isAnchorTextBoldEnabled()
    bool ret = self->isAnchorTextBoldEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_RichText_isAnchorTextDelEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.RichText");

    // bool isAnchorTextDelEnabled()
    bool ret = self->isAnchorTextDelEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_RichText_isAnchorTextGlowEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.RichText");

    // bool isAnchorTextGlowEnabled()
    bool ret = self->isAnchorTextGlowEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_RichText_isAnchorTextItalicEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.RichText");

    // bool isAnchorTextItalicEnabled()
    bool ret = self->isAnchorTextItalicEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_RichText_isAnchorTextOutlineEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.RichText");

    // bool isAnchorTextOutlineEnabled()
    bool ret = self->isAnchorTextOutlineEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_RichText_isAnchorTextShadowEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.RichText");

    // bool isAnchorTextShadowEnabled()
    bool ret = self->isAnchorTextShadowEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_RichText_isAnchorTextUnderlineEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.RichText");

    // bool isAnchorTextUnderlineEnabled()
    bool ret = self->isAnchorTextUnderlineEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_RichText_new(lua_State *L)
{
    olua_startinvoke(L);

    // cocos2d::ui::RichText()
    cocos2d::ui::RichText *ret = new cocos2d::ui::RichText();
    int num_ret = olua_push_object(L, ret, "ccui.RichText");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_RichText_openUrl(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;
    std::string arg1;       /** url */

    olua_to_object(L, 1, &self, "ccui.RichText");
    olua_check_string(L, 2, &arg1);

    // void openUrl(const std::string &url)
    self->openUrl(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_RichText_pushBackElement(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;
    cocos2d::ui::RichElement *arg1 = nullptr;       /** element */

    olua_to_object(L, 1, &self, "ccui.RichText");
    olua_check_object(L, 2, &arg1, "ccui.RichElement");

    // void pushBackElement(cocos2d::ui::RichElement *element)
    self->pushBackElement(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_RichText_removeElement$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;
    int arg1 = 0;       /** index */

    olua_to_object(L, 1, &self, "ccui.RichText");
    olua_check_integer(L, 2, &arg1);

    // void removeElement(int index)
    self->removeElement(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_RichText_removeElement$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;
    cocos2d::ui::RichElement *arg1 = nullptr;       /** element */

    olua_to_object(L, 1, &self, "ccui.RichText");
    olua_check_object(L, 2, &arg1, "ccui.RichElement");

    // void removeElement(cocos2d::ui::RichElement *element)
    self->removeElement(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_RichText_removeElement(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        if ((olua_is_object(L, 1, "ccui.RichText")) && (olua_is_integer(L, 2))) {
            // void removeElement(int index)
            return _olua_fun_cocos2d_ui_RichText_removeElement$1(L);
        }

        // if ((olua_is_object(L, 1, "ccui.RichText")) && (olua_is_object(L, 2, "ccui.RichElement"))) {
            // void removeElement(cocos2d::ui::RichElement *element)
            return _olua_fun_cocos2d_ui_RichText_removeElement$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::RichText::removeElement' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_RichText_removeTagDescription(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** tag */

    olua_check_string(L, 1, &arg1);

    // static void removeTagDescription(const std::string &tag)
    cocos2d::ui::RichText::removeTagDescription(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_RichText_setAnchorFontColor(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;
    std::string arg1;       /** color */

    olua_to_object(L, 1, &self, "ccui.RichText");
    olua_check_string(L, 2, &arg1);

    // void setAnchorFontColor(const std::string &color)
    self->setAnchorFontColor(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_RichText_setAnchorTextBold(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;
    bool arg1 = false;       /** enable */

    olua_to_object(L, 1, &self, "ccui.RichText");
    olua_check_bool(L, 2, &arg1);

    // void setAnchorTextBold(bool enable)
    self->setAnchorTextBold(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_RichText_setAnchorTextDel(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;
    bool arg1 = false;       /** enable */

    olua_to_object(L, 1, &self, "ccui.RichText");
    olua_check_bool(L, 2, &arg1);

    // void setAnchorTextDel(bool enable)
    self->setAnchorTextDel(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_RichText_setAnchorTextGlow$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;
    bool arg1 = false;       /** enable */
    cocos2d::Color3B arg2;       /** glowColor */

    olua_to_object(L, 1, &self, "ccui.RichText");
    olua_check_bool(L, 2, &arg1);
    olua_check_cocos2d_Color3B(L, 3, &arg2);

    // void setAnchorTextGlow(bool enable, @optional const cocos2d::Color3B &glowColor)
    self->setAnchorTextGlow(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_RichText_setAnchorTextGlow$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;
    bool arg1 = false;       /** enable */

    olua_to_object(L, 1, &self, "ccui.RichText");
    olua_check_bool(L, 2, &arg1);

    // void setAnchorTextGlow(bool enable)
    self->setAnchorTextGlow(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_RichText_setAnchorTextGlow(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccui.RichText")) && (olua_is_bool(L, 2))) {
            // void setAnchorTextGlow(bool enable)
            return _olua_fun_cocos2d_ui_RichText_setAnchorTextGlow$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "ccui.RichText")) && (olua_is_bool(L, 2)) && (olua_is_cocos2d_Color3B(L, 3))) {
            // void setAnchorTextGlow(bool enable, @optional const cocos2d::Color3B &glowColor)
            return _olua_fun_cocos2d_ui_RichText_setAnchorTextGlow$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::RichText::setAnchorTextGlow' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_RichText_setAnchorTextItalic(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;
    bool arg1 = false;       /** enable */

    olua_to_object(L, 1, &self, "ccui.RichText");
    olua_check_bool(L, 2, &arg1);

    // void setAnchorTextItalic(bool enable)
    self->setAnchorTextItalic(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_RichText_setAnchorTextOutline$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;
    bool arg1 = false;       /** enable */
    cocos2d::Color3B arg2;       /** outlineColor */
    int arg3 = 0;       /** outlineSize */

    olua_to_object(L, 1, &self, "ccui.RichText");
    olua_check_bool(L, 2, &arg1);
    olua_check_cocos2d_Color3B(L, 3, &arg2);
    olua_check_integer(L, 4, &arg3);

    // void setAnchorTextOutline(bool enable, @optional const cocos2d::Color3B &outlineColor, @optional int outlineSize)
    self->setAnchorTextOutline(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_RichText_setAnchorTextOutline$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;
    bool arg1 = false;       /** enable */

    olua_to_object(L, 1, &self, "ccui.RichText");
    olua_check_bool(L, 2, &arg1);

    // void setAnchorTextOutline(bool enable)
    self->setAnchorTextOutline(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_RichText_setAnchorTextOutline$3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;
    bool arg1 = false;       /** enable */
    cocos2d::Color3B arg2;       /** outlineColor */

    olua_to_object(L, 1, &self, "ccui.RichText");
    olua_check_bool(L, 2, &arg1);
    olua_check_cocos2d_Color3B(L, 3, &arg2);

    // void setAnchorTextOutline(bool enable, @optional const cocos2d::Color3B &outlineColor)
    self->setAnchorTextOutline(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_RichText_setAnchorTextOutline(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccui.RichText")) && (olua_is_bool(L, 2))) {
            // void setAnchorTextOutline(bool enable)
            return _olua_fun_cocos2d_ui_RichText_setAnchorTextOutline$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "ccui.RichText")) && (olua_is_bool(L, 2)) && (olua_is_cocos2d_Color3B(L, 3))) {
            // void setAnchorTextOutline(bool enable, @optional const cocos2d::Color3B &outlineColor)
            return _olua_fun_cocos2d_ui_RichText_setAnchorTextOutline$3(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_object(L, 1, "ccui.RichText")) && (olua_is_bool(L, 2)) && (olua_is_cocos2d_Color3B(L, 3)) && (olua_is_integer(L, 4))) {
            // void setAnchorTextOutline(bool enable, @optional const cocos2d::Color3B &outlineColor, @optional int outlineSize)
            return _olua_fun_cocos2d_ui_RichText_setAnchorTextOutline$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::RichText::setAnchorTextOutline' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_RichText_setAnchorTextShadow$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;
    bool arg1 = false;       /** enable */
    cocos2d::Color3B arg2;       /** shadowColor */
    cocos2d::Size *arg3;       /** offset */
    int arg4 = 0;       /** blurRadius */

    olua_to_object(L, 1, &self, "ccui.RichText");
    olua_check_bool(L, 2, &arg1);
    olua_check_cocos2d_Color3B(L, 3, &arg2);
    olua_check_object(L, 4, &arg3, "cc.Size");
    olua_check_integer(L, 5, &arg4);

    // void setAnchorTextShadow(bool enable, @optional const cocos2d::Color3B &shadowColor, @optional const cocos2d::Size &offset, @optional int blurRadius)
    self->setAnchorTextShadow(arg1, arg2, *arg3, arg4);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_RichText_setAnchorTextShadow$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;
    bool arg1 = false;       /** enable */

    olua_to_object(L, 1, &self, "ccui.RichText");
    olua_check_bool(L, 2, &arg1);

    // void setAnchorTextShadow(bool enable)
    self->setAnchorTextShadow(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_RichText_setAnchorTextShadow$3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;
    bool arg1 = false;       /** enable */
    cocos2d::Color3B arg2;       /** shadowColor */

    olua_to_object(L, 1, &self, "ccui.RichText");
    olua_check_bool(L, 2, &arg1);
    olua_check_cocos2d_Color3B(L, 3, &arg2);

    // void setAnchorTextShadow(bool enable, @optional const cocos2d::Color3B &shadowColor)
    self->setAnchorTextShadow(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_RichText_setAnchorTextShadow$4(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;
    bool arg1 = false;       /** enable */
    cocos2d::Color3B arg2;       /** shadowColor */
    cocos2d::Size *arg3;       /** offset */

    olua_to_object(L, 1, &self, "ccui.RichText");
    olua_check_bool(L, 2, &arg1);
    olua_check_cocos2d_Color3B(L, 3, &arg2);
    olua_check_object(L, 4, &arg3, "cc.Size");

    // void setAnchorTextShadow(bool enable, @optional const cocos2d::Color3B &shadowColor, @optional const cocos2d::Size &offset)
    self->setAnchorTextShadow(arg1, arg2, *arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_RichText_setAnchorTextShadow(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccui.RichText")) && (olua_is_bool(L, 2))) {
            // void setAnchorTextShadow(bool enable)
            return _olua_fun_cocos2d_ui_RichText_setAnchorTextShadow$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "ccui.RichText")) && (olua_is_bool(L, 2)) && (olua_is_cocos2d_Color3B(L, 3))) {
            // void setAnchorTextShadow(bool enable, @optional const cocos2d::Color3B &shadowColor)
            return _olua_fun_cocos2d_ui_RichText_setAnchorTextShadow$3(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_object(L, 1, "ccui.RichText")) && (olua_is_bool(L, 2)) && (olua_is_cocos2d_Color3B(L, 3)) && (olua_is_object(L, 4, "cc.Size"))) {
            // void setAnchorTextShadow(bool enable, @optional const cocos2d::Color3B &shadowColor, @optional const cocos2d::Size &offset)
            return _olua_fun_cocos2d_ui_RichText_setAnchorTextShadow$4(L);
        // }
    }

    if (num_args == 5) {
        // if ((olua_is_object(L, 1, "ccui.RichText")) && (olua_is_bool(L, 2)) && (olua_is_cocos2d_Color3B(L, 3)) && (olua_is_object(L, 4, "cc.Size")) && (olua_is_integer(L, 5))) {
            // void setAnchorTextShadow(bool enable, @optional const cocos2d::Color3B &shadowColor, @optional const cocos2d::Size &offset, @optional int blurRadius)
            return _olua_fun_cocos2d_ui_RichText_setAnchorTextShadow$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::RichText::setAnchorTextShadow' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_RichText_setAnchorTextUnderline(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;
    bool arg1 = false;       /** enable */

    olua_to_object(L, 1, &self, "ccui.RichText");
    olua_check_bool(L, 2, &arg1);

    // void setAnchorTextUnderline(bool enable)
    self->setAnchorTextUnderline(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_RichText_setDefaults(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;
    cocos2d::ValueMap arg1;       /** defaults */

    olua_to_object(L, 1, &self, "ccui.RichText");
    olua_check_cocos2d_ValueMap(L, 2, &arg1);

    // void setDefaults(const cocos2d::ValueMap &defaults)
    self->setDefaults(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_RichText_setFontColor(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;
    std::string arg1;       /** color */

    olua_to_object(L, 1, &self, "ccui.RichText");
    olua_check_string(L, 2, &arg1);

    // void setFontColor(const std::string &color)
    self->setFontColor(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_RichText_setFontFace(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;
    std::string arg1;       /** face */

    olua_to_object(L, 1, &self, "ccui.RichText");
    olua_check_string(L, 2, &arg1);

    // void setFontFace(const std::string &face)
    self->setFontFace(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_RichText_setFontSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;
    float arg1 = 0;       /** size */

    olua_to_object(L, 1, &self, "ccui.RichText");
    olua_check_number(L, 2, &arg1);

    // void setFontSize(float size)
    self->setFontSize(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_RichText_setHorizontalAlignment(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;
    cocos2d::ui::RichText::HorizontalAlignment arg1 = (cocos2d::ui::RichText::HorizontalAlignment)0;       /** a */

    olua_to_object(L, 1, &self, "ccui.RichText");
    olua_check_enum(L, 2, &arg1);

    // void setHorizontalAlignment(cocos2d::ui::RichText::HorizontalAlignment a)
    self->setHorizontalAlignment(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_RichText_setOpenUrlHandler(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;
    cocos2d::ui::RichText::OpenUrlHandler arg1;       /** handleOpenUrl */

    olua_to_object(L, 1, &self, "ccui.RichText");
    olua_check_callback(L, 2, &arg1, "ccui.RichText.OpenUrlHandler");

    void *cb_store = (void *)self;
    std::string cb_tag = "OpenUrlHandler";
    std::string cb_name = olua_setcallback(L, cb_store, 2, cb_tag.c_str(), OLUA_TAG_REPLACE);
    olua_Context cb_ctx = olua_context(L);
    // lua_State *ML = olua_mainthread(L);
    arg1 = [cb_store, cb_name, cb_ctx /*, ML */](const std::string &cb_arg1) {
        lua_State *L = olua_mainthread(NULL);
        olua_checkhostthread();

        if (olua_contextequal(L, cb_ctx)) {
            int top = lua_gettop(L);
            olua_push_string(L, cb_arg1);

            olua_callback(L, cb_store, cb_name.c_str(), 1);

            lua_settop(L, top);
        }
    };

    // void setOpenUrlHandler(const cocos2d::ui::RichText::OpenUrlHandler &handleOpenUrl)
    self->setOpenUrlHandler(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_RichText_setVerticalSpace(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;
    float arg1 = 0;       /** space */

    olua_to_object(L, 1, &self, "ccui.RichText");
    olua_check_number(L, 2, &arg1);

    // void setVerticalSpace(float space)
    self->setVerticalSpace(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_RichText_setWrapMode(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;
    cocos2d::ui::RichText::WrapMode arg1 = (cocos2d::ui::RichText::WrapMode)0;       /** wrapMode */

    olua_to_object(L, 1, &self, "ccui.RichText");
    olua_check_enum(L, 2, &arg1);

    // void setWrapMode(cocos2d::ui::RichText::WrapMode wrapMode)
    self->setWrapMode(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_RichText_stringWithColor3B(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;
    cocos2d::Color3B arg1;       /** color3b */

    olua_to_object(L, 1, &self, "ccui.RichText");
    olua_check_cocos2d_Color3B(L, 2, &arg1);

    // std::string stringWithColor3B(const cocos2d::Color3B &color3b)
    std::string ret = self->stringWithColor3B(arg1);
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_RichText_stringWithColor4B(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;
    cocos2d::Color4B arg1;       /** color4b */

    olua_to_object(L, 1, &self, "ccui.RichText");
    olua_check_cocos2d_Color4B(L, 2, &arg1);

    // std::string stringWithColor4B(const cocos2d::Color4B &color4b)
    std::string ret = self->stringWithColor4B(arg1);
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_cls_ccui_RichText(lua_State *L)
{
    oluacls_class<cocos2d::ui::RichText, cocos2d::ui::Widget>(L, "ccui.RichText");
    oluacls_func(L, "color3BWithString", _olua_fun_cocos2d_ui_RichText_color3BWithString);
    oluacls_func(L, "create", _olua_fun_cocos2d_ui_RichText_create);
    oluacls_func(L, "createWithXML", _olua_fun_cocos2d_ui_RichText_createWithXML);
    oluacls_func(L, "formatText", _olua_fun_cocos2d_ui_RichText_formatText);
    oluacls_func(L, "getAnchorFontColor", _olua_fun_cocos2d_ui_RichText_getAnchorFontColor);
    oluacls_func(L, "getAnchorFontColor3B", _olua_fun_cocos2d_ui_RichText_getAnchorFontColor3B);
    oluacls_func(L, "getAnchorTextGlowColor3B", _olua_fun_cocos2d_ui_RichText_getAnchorTextGlowColor3B);
    oluacls_func(L, "getAnchorTextOutlineColor3B", _olua_fun_cocos2d_ui_RichText_getAnchorTextOutlineColor3B);
    oluacls_func(L, "getAnchorTextOutlineSize", _olua_fun_cocos2d_ui_RichText_getAnchorTextOutlineSize);
    oluacls_func(L, "getAnchorTextShadowBlurRadius", _olua_fun_cocos2d_ui_RichText_getAnchorTextShadowBlurRadius);
    oluacls_func(L, "getAnchorTextShadowColor3B", _olua_fun_cocos2d_ui_RichText_getAnchorTextShadowColor3B);
    oluacls_func(L, "getAnchorTextShadowOffset", _olua_fun_cocos2d_ui_RichText_getAnchorTextShadowOffset);
    oluacls_func(L, "getDefaults", _olua_fun_cocos2d_ui_RichText_getDefaults);
    oluacls_func(L, "getFontColor", _olua_fun_cocos2d_ui_RichText_getFontColor);
    oluacls_func(L, "getFontColor3B", _olua_fun_cocos2d_ui_RichText_getFontColor3B);
    oluacls_func(L, "getFontFace", _olua_fun_cocos2d_ui_RichText_getFontFace);
    oluacls_func(L, "getFontSize", _olua_fun_cocos2d_ui_RichText_getFontSize);
    oluacls_func(L, "getHorizontalAlignment", _olua_fun_cocos2d_ui_RichText_getHorizontalAlignment);
    oluacls_func(L, "getWrapMode", _olua_fun_cocos2d_ui_RichText_getWrapMode);
    oluacls_func(L, "insertElement", _olua_fun_cocos2d_ui_RichText_insertElement);
    oluacls_func(L, "isAnchorTextBoldEnabled", _olua_fun_cocos2d_ui_RichText_isAnchorTextBoldEnabled);
    oluacls_func(L, "isAnchorTextDelEnabled", _olua_fun_cocos2d_ui_RichText_isAnchorTextDelEnabled);
    oluacls_func(L, "isAnchorTextGlowEnabled", _olua_fun_cocos2d_ui_RichText_isAnchorTextGlowEnabled);
    oluacls_func(L, "isAnchorTextItalicEnabled", _olua_fun_cocos2d_ui_RichText_isAnchorTextItalicEnabled);
    oluacls_func(L, "isAnchorTextOutlineEnabled", _olua_fun_cocos2d_ui_RichText_isAnchorTextOutlineEnabled);
    oluacls_func(L, "isAnchorTextShadowEnabled", _olua_fun_cocos2d_ui_RichText_isAnchorTextShadowEnabled);
    oluacls_func(L, "isAnchorTextUnderlineEnabled", _olua_fun_cocos2d_ui_RichText_isAnchorTextUnderlineEnabled);
    oluacls_func(L, "new", _olua_fun_cocos2d_ui_RichText_new);
    oluacls_func(L, "openUrl", _olua_fun_cocos2d_ui_RichText_openUrl);
    oluacls_func(L, "pushBackElement", _olua_fun_cocos2d_ui_RichText_pushBackElement);
    oluacls_func(L, "removeElement", _olua_fun_cocos2d_ui_RichText_removeElement);
    oluacls_func(L, "removeTagDescription", _olua_fun_cocos2d_ui_RichText_removeTagDescription);
    oluacls_func(L, "setAnchorFontColor", _olua_fun_cocos2d_ui_RichText_setAnchorFontColor);
    oluacls_func(L, "setAnchorTextBold", _olua_fun_cocos2d_ui_RichText_setAnchorTextBold);
    oluacls_func(L, "setAnchorTextDel", _olua_fun_cocos2d_ui_RichText_setAnchorTextDel);
    oluacls_func(L, "setAnchorTextGlow", _olua_fun_cocos2d_ui_RichText_setAnchorTextGlow);
    oluacls_func(L, "setAnchorTextItalic", _olua_fun_cocos2d_ui_RichText_setAnchorTextItalic);
    oluacls_func(L, "setAnchorTextOutline", _olua_fun_cocos2d_ui_RichText_setAnchorTextOutline);
    oluacls_func(L, "setAnchorTextShadow", _olua_fun_cocos2d_ui_RichText_setAnchorTextShadow);
    oluacls_func(L, "setAnchorTextUnderline", _olua_fun_cocos2d_ui_RichText_setAnchorTextUnderline);
    oluacls_func(L, "setDefaults", _olua_fun_cocos2d_ui_RichText_setDefaults);
    oluacls_func(L, "setFontColor", _olua_fun_cocos2d_ui_RichText_setFontColor);
    oluacls_func(L, "setFontFace", _olua_fun_cocos2d_ui_RichText_setFontFace);
    oluacls_func(L, "setFontSize", _olua_fun_cocos2d_ui_RichText_setFontSize);
    oluacls_func(L, "setHorizontalAlignment", _olua_fun_cocos2d_ui_RichText_setHorizontalAlignment);
    oluacls_func(L, "setOpenUrlHandler", _olua_fun_cocos2d_ui_RichText_setOpenUrlHandler);
    oluacls_func(L, "setVerticalSpace", _olua_fun_cocos2d_ui_RichText_setVerticalSpace);
    oluacls_func(L, "setWrapMode", _olua_fun_cocos2d_ui_RichText_setWrapMode);
    oluacls_func(L, "stringWithColor3B", _olua_fun_cocos2d_ui_RichText_stringWithColor3B);
    oluacls_func(L, "stringWithColor4B", _olua_fun_cocos2d_ui_RichText_stringWithColor4B);
    oluacls_prop(L, "anchorFontColor", _olua_fun_cocos2d_ui_RichText_getAnchorFontColor, _olua_fun_cocos2d_ui_RichText_setAnchorFontColor);
    oluacls_prop(L, "anchorFontColor3B", _olua_fun_cocos2d_ui_RichText_getAnchorFontColor3B, nullptr);
    oluacls_prop(L, "anchorTextBoldEnabled", _olua_fun_cocos2d_ui_RichText_isAnchorTextBoldEnabled, nullptr);
    oluacls_prop(L, "anchorTextDelEnabled", _olua_fun_cocos2d_ui_RichText_isAnchorTextDelEnabled, nullptr);
    oluacls_prop(L, "anchorTextGlowColor3B", _olua_fun_cocos2d_ui_RichText_getAnchorTextGlowColor3B, nullptr);
    oluacls_prop(L, "anchorTextGlowEnabled", _olua_fun_cocos2d_ui_RichText_isAnchorTextGlowEnabled, nullptr);
    oluacls_prop(L, "anchorTextItalicEnabled", _olua_fun_cocos2d_ui_RichText_isAnchorTextItalicEnabled, nullptr);
    oluacls_prop(L, "anchorTextOutlineColor3B", _olua_fun_cocos2d_ui_RichText_getAnchorTextOutlineColor3B, nullptr);
    oluacls_prop(L, "anchorTextOutlineEnabled", _olua_fun_cocos2d_ui_RichText_isAnchorTextOutlineEnabled, nullptr);
    oluacls_prop(L, "anchorTextOutlineSize", _olua_fun_cocos2d_ui_RichText_getAnchorTextOutlineSize, nullptr);
    oluacls_prop(L, "anchorTextShadowBlurRadius", _olua_fun_cocos2d_ui_RichText_getAnchorTextShadowBlurRadius, nullptr);
    oluacls_prop(L, "anchorTextShadowColor3B", _olua_fun_cocos2d_ui_RichText_getAnchorTextShadowColor3B, nullptr);
    oluacls_prop(L, "anchorTextShadowEnabled", _olua_fun_cocos2d_ui_RichText_isAnchorTextShadowEnabled, nullptr);
    oluacls_prop(L, "anchorTextShadowOffset", _olua_fun_cocos2d_ui_RichText_getAnchorTextShadowOffset, nullptr);
    oluacls_prop(L, "anchorTextUnderlineEnabled", _olua_fun_cocos2d_ui_RichText_isAnchorTextUnderlineEnabled, nullptr);
    oluacls_prop(L, "defaults", _olua_fun_cocos2d_ui_RichText_getDefaults, _olua_fun_cocos2d_ui_RichText_setDefaults);
    oluacls_prop(L, "fontColor", _olua_fun_cocos2d_ui_RichText_getFontColor, _olua_fun_cocos2d_ui_RichText_setFontColor);
    oluacls_prop(L, "fontColor3B", _olua_fun_cocos2d_ui_RichText_getFontColor3B, nullptr);
    oluacls_prop(L, "fontFace", _olua_fun_cocos2d_ui_RichText_getFontFace, _olua_fun_cocos2d_ui_RichText_setFontFace);
    oluacls_prop(L, "fontSize", _olua_fun_cocos2d_ui_RichText_getFontSize, _olua_fun_cocos2d_ui_RichText_setFontSize);
    oluacls_prop(L, "horizontalAlignment", _olua_fun_cocos2d_ui_RichText_getHorizontalAlignment, _olua_fun_cocos2d_ui_RichText_setHorizontalAlignment);
    oluacls_prop(L, "wrapMode", _olua_fun_cocos2d_ui_RichText_getWrapMode, _olua_fun_cocos2d_ui_RichText_setWrapMode);
    oluacls_const(L, "KEY_ANCHOR_FONT_COLOR_STRING", cocos2d::ui::RichText::KEY_ANCHOR_FONT_COLOR_STRING);
    oluacls_const(L, "KEY_ANCHOR_TEXT_BOLD", cocos2d::ui::RichText::KEY_ANCHOR_TEXT_BOLD);
    oluacls_const(L, "KEY_ANCHOR_TEXT_GLOW_COLOR", cocos2d::ui::RichText::KEY_ANCHOR_TEXT_GLOW_COLOR);
    oluacls_const(L, "KEY_ANCHOR_TEXT_ITALIC", cocos2d::ui::RichText::KEY_ANCHOR_TEXT_ITALIC);
    oluacls_const(L, "KEY_ANCHOR_TEXT_LINE", cocos2d::ui::RichText::KEY_ANCHOR_TEXT_LINE);
    oluacls_const(L, "KEY_ANCHOR_TEXT_OUTLINE_COLOR", cocos2d::ui::RichText::KEY_ANCHOR_TEXT_OUTLINE_COLOR);
    oluacls_const(L, "KEY_ANCHOR_TEXT_OUTLINE_SIZE", cocos2d::ui::RichText::KEY_ANCHOR_TEXT_OUTLINE_SIZE);
    oluacls_const(L, "KEY_ANCHOR_TEXT_SHADOW_BLUR_RADIUS", cocos2d::ui::RichText::KEY_ANCHOR_TEXT_SHADOW_BLUR_RADIUS);
    oluacls_const(L, "KEY_ANCHOR_TEXT_SHADOW_COLOR", cocos2d::ui::RichText::KEY_ANCHOR_TEXT_SHADOW_COLOR);
    oluacls_const(L, "KEY_ANCHOR_TEXT_SHADOW_OFFSET_HEIGHT", cocos2d::ui::RichText::KEY_ANCHOR_TEXT_SHADOW_OFFSET_HEIGHT);
    oluacls_const(L, "KEY_ANCHOR_TEXT_SHADOW_OFFSET_WIDTH", cocos2d::ui::RichText::KEY_ANCHOR_TEXT_SHADOW_OFFSET_WIDTH);
    oluacls_const(L, "KEY_ANCHOR_TEXT_STYLE", cocos2d::ui::RichText::KEY_ANCHOR_TEXT_STYLE);
    oluacls_const(L, "KEY_FONT_BIG", cocos2d::ui::RichText::KEY_FONT_BIG);
    oluacls_const(L, "KEY_FONT_COLOR_STRING", cocos2d::ui::RichText::KEY_FONT_COLOR_STRING);
    oluacls_const(L, "KEY_FONT_FACE", cocos2d::ui::RichText::KEY_FONT_FACE);
    oluacls_const(L, "KEY_FONT_SIZE", cocos2d::ui::RichText::KEY_FONT_SIZE);
    oluacls_const(L, "KEY_FONT_SMALL", cocos2d::ui::RichText::KEY_FONT_SMALL);
    oluacls_const(L, "KEY_HORIZONTAL_ALIGNMENT", cocos2d::ui::RichText::KEY_HORIZONTAL_ALIGNMENT);
    oluacls_const(L, "KEY_TEXT_BOLD", cocos2d::ui::RichText::KEY_TEXT_BOLD);
    oluacls_const(L, "KEY_TEXT_GLOW_COLOR", cocos2d::ui::RichText::KEY_TEXT_GLOW_COLOR);
    oluacls_const(L, "KEY_TEXT_ITALIC", cocos2d::ui::RichText::KEY_TEXT_ITALIC);
    oluacls_const(L, "KEY_TEXT_LINE", cocos2d::ui::RichText::KEY_TEXT_LINE);
    oluacls_const(L, "KEY_TEXT_OUTLINE_COLOR", cocos2d::ui::RichText::KEY_TEXT_OUTLINE_COLOR);
    oluacls_const(L, "KEY_TEXT_OUTLINE_SIZE", cocos2d::ui::RichText::KEY_TEXT_OUTLINE_SIZE);
    oluacls_const(L, "KEY_TEXT_SHADOW_BLUR_RADIUS", cocos2d::ui::RichText::KEY_TEXT_SHADOW_BLUR_RADIUS);
    oluacls_const(L, "KEY_TEXT_SHADOW_COLOR", cocos2d::ui::RichText::KEY_TEXT_SHADOW_COLOR);
    oluacls_const(L, "KEY_TEXT_SHADOW_OFFSET_HEIGHT", cocos2d::ui::RichText::KEY_TEXT_SHADOW_OFFSET_HEIGHT);
    oluacls_const(L, "KEY_TEXT_SHADOW_OFFSET_WIDTH", cocos2d::ui::RichText::KEY_TEXT_SHADOW_OFFSET_WIDTH);
    oluacls_const(L, "KEY_TEXT_STYLE", cocos2d::ui::RichText::KEY_TEXT_STYLE);
    oluacls_const(L, "KEY_URL", cocos2d::ui::RichText::KEY_URL);
    oluacls_const(L, "KEY_VERTICAL_SPACE", cocos2d::ui::RichText::KEY_VERTICAL_SPACE);
    oluacls_const(L, "KEY_WRAP_MODE", cocos2d::ui::RichText::KEY_WRAP_MODE);
    oluacls_const(L, "VALUE_TEXT_LINE_DEL", cocos2d::ui::RichText::VALUE_TEXT_LINE_DEL);
    oluacls_const(L, "VALUE_TEXT_LINE_NONE", cocos2d::ui::RichText::VALUE_TEXT_LINE_NONE);
    oluacls_const(L, "VALUE_TEXT_LINE_UNDER", cocos2d::ui::RichText::VALUE_TEXT_LINE_UNDER);
    oluacls_const(L, "VALUE_TEXT_STYLE_GLOW", cocos2d::ui::RichText::VALUE_TEXT_STYLE_GLOW);
    oluacls_const(L, "VALUE_TEXT_STYLE_NONE", cocos2d::ui::RichText::VALUE_TEXT_STYLE_NONE);
    oluacls_const(L, "VALUE_TEXT_STYLE_OUTLINE", cocos2d::ui::RichText::VALUE_TEXT_STYLE_OUTLINE);
    oluacls_const(L, "VALUE_TEXT_STYLE_SHADOW", cocos2d::ui::RichText::VALUE_TEXT_STYLE_SHADOW);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_RichText(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.RichText")) {
        luaL_error(L, "class not found: cocos2d::ui::RichText");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_ui_ScrollViewBar_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *arg1 = nullptr;       /** parent */
    cocos2d::ui::ScrollView::Direction arg2 = (cocos2d::ui::ScrollView::Direction)0;       /** direction */

    olua_check_object(L, 1, &arg1, "ccui.ScrollView");
    olua_check_enum(L, 2, &arg2);

    // static cocos2d::ui::ScrollViewBar *create(cocos2d::ui::ScrollView *parent, cocos2d::ui::ScrollView::Direction direction)
    cocos2d::ui::ScrollViewBar *ret = cocos2d::ui::ScrollViewBar::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "ccui.ScrollViewBar");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_ScrollViewBar_getAutoHideTime(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollViewBar *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.ScrollViewBar");

    // float getAutoHideTime()
    float ret = self->getAutoHideTime();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_ScrollViewBar_getPositionFromCorner(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollViewBar *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.ScrollViewBar");

    // cocos2d::Vec2 getPositionFromCorner()
    cocos2d::Vec2 ret = self->getPositionFromCorner();
    int num_ret = olua_copy_object(L, ret, "cc.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_ScrollViewBar_getWidth(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollViewBar *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.ScrollViewBar");

    // float getWidth()
    float ret = self->getWidth();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_ScrollViewBar_isAutoHideEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollViewBar *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.ScrollViewBar");

    // bool isAutoHideEnabled()
    bool ret = self->isAutoHideEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_ScrollViewBar_new(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *arg1 = nullptr;       /** parent */
    cocos2d::ui::ScrollView::Direction arg2 = (cocos2d::ui::ScrollView::Direction)0;       /** direction */

    olua_check_object(L, 1, &arg1, "ccui.ScrollView");
    olua_check_enum(L, 2, &arg2);

    // cocos2d::ui::ScrollViewBar(cocos2d::ui::ScrollView *parent, cocos2d::ui::ScrollView::Direction direction)
    cocos2d::ui::ScrollViewBar *ret = new cocos2d::ui::ScrollViewBar(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "ccui.ScrollViewBar");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_ScrollViewBar_onScrolled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollViewBar *self = nullptr;
    cocos2d::Vec2 *arg1;       /** outOfBoundary */

    olua_to_object(L, 1, &self, "ccui.ScrollViewBar");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // void onScrolled(const cocos2d::Vec2 &outOfBoundary)
    self->onScrolled(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_ScrollViewBar_onTouchBegan(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollViewBar *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.ScrollViewBar");

    // void onTouchBegan()
    self->onTouchBegan();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_ScrollViewBar_onTouchEnded(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollViewBar *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.ScrollViewBar");

    // void onTouchEnded()
    self->onTouchEnded();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_ScrollViewBar_setAutoHideEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollViewBar *self = nullptr;
    bool arg1 = false;       /** autoHideEnabled */

    olua_to_object(L, 1, &self, "ccui.ScrollViewBar");
    olua_check_bool(L, 2, &arg1);

    // void setAutoHideEnabled(bool autoHideEnabled)
    self->setAutoHideEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_ScrollViewBar_setAutoHideTime(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollViewBar *self = nullptr;
    float arg1 = 0;       /** autoHideTime */

    olua_to_object(L, 1, &self, "ccui.ScrollViewBar");
    olua_check_number(L, 2, &arg1);

    // void setAutoHideTime(float autoHideTime)
    self->setAutoHideTime(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_ScrollViewBar_setPositionFromCorner(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollViewBar *self = nullptr;
    cocos2d::Vec2 *arg1;       /** positionFromCorner */

    olua_to_object(L, 1, &self, "ccui.ScrollViewBar");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // void setPositionFromCorner(const cocos2d::Vec2 &positionFromCorner)
    self->setPositionFromCorner(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_ScrollViewBar_setWidth(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollViewBar *self = nullptr;
    float arg1 = 0;       /** width */

    olua_to_object(L, 1, &self, "ccui.ScrollViewBar");
    olua_check_number(L, 2, &arg1);

    // void setWidth(float width)
    self->setWidth(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_cls_ccui_ScrollViewBar(lua_State *L)
{
    oluacls_class<cocos2d::ui::ScrollViewBar, cocos2d::ProtectedNode>(L, "ccui.ScrollViewBar");
    oluacls_func(L, "create", _olua_fun_cocos2d_ui_ScrollViewBar_create);
    oluacls_func(L, "getAutoHideTime", _olua_fun_cocos2d_ui_ScrollViewBar_getAutoHideTime);
    oluacls_func(L, "getPositionFromCorner", _olua_fun_cocos2d_ui_ScrollViewBar_getPositionFromCorner);
    oluacls_func(L, "getWidth", _olua_fun_cocos2d_ui_ScrollViewBar_getWidth);
    oluacls_func(L, "isAutoHideEnabled", _olua_fun_cocos2d_ui_ScrollViewBar_isAutoHideEnabled);
    oluacls_func(L, "new", _olua_fun_cocos2d_ui_ScrollViewBar_new);
    oluacls_func(L, "onScrolled", _olua_fun_cocos2d_ui_ScrollViewBar_onScrolled);
    oluacls_func(L, "onTouchBegan", _olua_fun_cocos2d_ui_ScrollViewBar_onTouchBegan);
    oluacls_func(L, "onTouchEnded", _olua_fun_cocos2d_ui_ScrollViewBar_onTouchEnded);
    oluacls_func(L, "setAutoHideEnabled", _olua_fun_cocos2d_ui_ScrollViewBar_setAutoHideEnabled);
    oluacls_func(L, "setAutoHideTime", _olua_fun_cocos2d_ui_ScrollViewBar_setAutoHideTime);
    oluacls_func(L, "setPositionFromCorner", _olua_fun_cocos2d_ui_ScrollViewBar_setPositionFromCorner);
    oluacls_func(L, "setWidth", _olua_fun_cocos2d_ui_ScrollViewBar_setWidth);
    oluacls_prop(L, "autoHideEnabled", _olua_fun_cocos2d_ui_ScrollViewBar_isAutoHideEnabled, _olua_fun_cocos2d_ui_ScrollViewBar_setAutoHideEnabled);
    oluacls_prop(L, "autoHideTime", _olua_fun_cocos2d_ui_ScrollViewBar_getAutoHideTime, _olua_fun_cocos2d_ui_ScrollViewBar_setAutoHideTime);
    oluacls_prop(L, "positionFromCorner", _olua_fun_cocos2d_ui_ScrollViewBar_getPositionFromCorner, _olua_fun_cocos2d_ui_ScrollViewBar_setPositionFromCorner);
    oluacls_prop(L, "width", _olua_fun_cocos2d_ui_ScrollViewBar_getWidth, _olua_fun_cocos2d_ui_ScrollViewBar_setWidth);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_ScrollViewBar(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.ScrollViewBar")) {
        luaL_error(L, "class not found: cocos2d::ui::ScrollViewBar");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_ccui_Slider_EventType(lua_State *L)
{
    oluacls_class<cocos2d::ui::Slider::EventType>(L, "ccui.Slider.EventType");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "ON_PERCENTAGE_CHANGED", (lua_Integer)cocos2d::ui::Slider::EventType::ON_PERCENTAGE_CHANGED);
    oluacls_enum(L, "ON_SLIDEBALL_CANCEL", (lua_Integer)cocos2d::ui::Slider::EventType::ON_SLIDEBALL_CANCEL);
    oluacls_enum(L, "ON_SLIDEBALL_DOWN", (lua_Integer)cocos2d::ui::Slider::EventType::ON_SLIDEBALL_DOWN);
    oluacls_enum(L, "ON_SLIDEBALL_UP", (lua_Integer)cocos2d::ui::Slider::EventType::ON_SLIDEBALL_UP);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_Slider_EventType(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.Slider.EventType")) {
        luaL_error(L, "class not found: cocos2d::ui::Slider::EventType");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_ui_Slider_ccSliderCallback___call(lua_State *L)
{
    olua_startinvoke(L);

    luaL_checktype(L, -1, LUA_TFUNCTION);
    olua_push_callback(L, (cocos2d::ui::Slider::ccSliderCallback *)nullptr, "ccui.Slider.ccSliderCallback");

    olua_endinvoke(L);

    return 1;
}

static int _olua_cls_ccui_Slider_ccSliderCallback(lua_State *L)
{
    oluacls_class<cocos2d::ui::Slider::ccSliderCallback>(L, "ccui.Slider.ccSliderCallback");
    oluacls_func(L, "__call", _olua_fun_cocos2d_ui_Slider_ccSliderCallback___call);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_Slider_ccSliderCallback(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.Slider.ccSliderCallback")) {
        luaL_error(L, "class not found: cocos2d::ui::Slider::ccSliderCallback");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_ui_Slider_addEventListener(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Slider *self = nullptr;
    cocos2d::ui::Slider::ccSliderCallback arg1;       /** callback */

    olua_to_object(L, 1, &self, "ccui.Slider");
    olua_check_callback(L, 2, &arg1, "ccui.Slider.ccSliderCallback");

    void *cb_store = (void *)self;
    std::string cb_tag = "sliderCallback";
    std::string cb_name = olua_setcallback(L, cb_store, 2, cb_tag.c_str(), OLUA_TAG_REPLACE);
    olua_Context cb_ctx = olua_context(L);
    // lua_State *ML = olua_mainthread(L);
    arg1 = [cb_store, cb_name, cb_ctx /*, ML */](cocos2d::Ref *cb_arg1, cocos2d::ui::Slider::EventType cb_arg2) {
        lua_State *L = olua_mainthread(NULL);
        olua_checkhostthread();

        if (olua_contextequal(L, cb_ctx)) {
            int top = lua_gettop(L);
            olua_push_object(L, cb_arg1, "cc.Ref");
            olua_push_enum(L, cb_arg2);

            olua_callback(L, cb_store, cb_name.c_str(), 2);

            lua_settop(L, top);
        }
    };

    // void addEventListener(const cocos2d::ui::Slider::ccSliderCallback &callback)
    self->addEventListener(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Slider_create$1(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::ui::Slider *create()
    cocos2d::ui::Slider *ret = cocos2d::ui::Slider::create();
    int num_ret = olua_push_object(L, ret, "ccui.Slider");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Slider_create$2(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** barTextureName */
    std::string arg2;       /** normalBallTextureName */
    cocos2d::ui::Widget::TextureResType arg3 = (cocos2d::ui::Widget::TextureResType)0;       /** resType */

    olua_check_string(L, 1, &arg1);
    olua_check_string(L, 2, &arg2);
    olua_check_enum(L, 3, &arg3);

    // static cocos2d::ui::Slider *create(const std::string &barTextureName, const std::string &normalBallTextureName, @optional cocos2d::ui::Widget::TextureResType resType)
    cocos2d::ui::Slider *ret = cocos2d::ui::Slider::create(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "ccui.Slider");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Slider_create$3(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** barTextureName */
    std::string arg2;       /** normalBallTextureName */

    olua_check_string(L, 1, &arg1);
    olua_check_string(L, 2, &arg2);

    // static cocos2d::ui::Slider *create(const std::string &barTextureName, const std::string &normalBallTextureName)
    cocos2d::ui::Slider *ret = cocos2d::ui::Slider::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "ccui.Slider");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Slider_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // static cocos2d::ui::Slider *create()
        return _olua_fun_cocos2d_ui_Slider_create$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_string(L, 1)) && (olua_is_string(L, 2))) {
            // static cocos2d::ui::Slider *create(const std::string &barTextureName, const std::string &normalBallTextureName)
            return _olua_fun_cocos2d_ui_Slider_create$3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_string(L, 1)) && (olua_is_string(L, 2)) && (olua_is_enum(L, 3))) {
            // static cocos2d::ui::Slider *create(const std::string &barTextureName, const std::string &normalBallTextureName, @optional cocos2d::ui::Widget::TextureResType resType)
            return _olua_fun_cocos2d_ui_Slider_create$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::Slider::create' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_Slider_createInstance(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::Ref *createInstance()
    cocos2d::Ref *ret = cocos2d::ui::Slider::createInstance();
    int num_ret = olua_push_object(L, ret, "cc.Ref");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Slider_getBackFile(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Slider *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Slider");

    // cocos2d::ResourceData getBackFile()
    cocos2d::ResourceData ret = self->getBackFile();
    int num_ret = olua_copy_object(L, ret, "cc.ResourceData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Slider_getBallDisabledFile(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Slider *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Slider");

    // cocos2d::ResourceData getBallDisabledFile()
    cocos2d::ResourceData ret = self->getBallDisabledFile();
    int num_ret = olua_copy_object(L, ret, "cc.ResourceData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Slider_getBallNormalFile(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Slider *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Slider");

    // cocos2d::ResourceData getBallNormalFile()
    cocos2d::ResourceData ret = self->getBallNormalFile();
    int num_ret = olua_copy_object(L, ret, "cc.ResourceData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Slider_getBallPressedFile(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Slider *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Slider");

    // cocos2d::ResourceData getBallPressedFile()
    cocos2d::ResourceData ret = self->getBallPressedFile();
    int num_ret = olua_copy_object(L, ret, "cc.ResourceData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Slider_getCapInsetsBarRenderer(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Slider *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Slider");

    // const cocos2d::Rect &getCapInsetsBarRenderer()
    const cocos2d::Rect &ret = self->getCapInsetsBarRenderer();
    int num_ret = olua_push_object(L, ret, "cc.Rect");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Slider_getCapInsetsProgressBarRenderer(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Slider *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Slider");

    // const cocos2d::Rect &getCapInsetsProgressBarRenderer()
    const cocos2d::Rect &ret = self->getCapInsetsProgressBarRenderer();
    int num_ret = olua_push_object(L, ret, "cc.Rect");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Slider_getMaxPercent(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Slider *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Slider");

    // int getMaxPercent()
    int ret = self->getMaxPercent();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Slider_getPercent(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Slider *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Slider");

    // int getPercent()
    int ret = self->getPercent();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Slider_getProgressBarFile(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Slider *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Slider");

    // cocos2d::ResourceData getProgressBarFile()
    cocos2d::ResourceData ret = self->getProgressBarFile();
    int num_ret = olua_copy_object(L, ret, "cc.ResourceData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Slider_getSlidBallDisabledRenderer(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Slider *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Slider");

    // @addref(protectedChildren |) cocos2d::Sprite *getSlidBallDisabledRenderer()
    cocos2d::Sprite *ret = self->getSlidBallDisabledRenderer();
    int num_ret = olua_push_object(L, ret, "cc.Sprite");

    // insert code after call
    olua_addref(L, 1, "protectedChildren", -1, OLUA_REF_MULTI);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Slider_getSlidBallNormalRenderer(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Slider *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Slider");

    // @addref(protectedChildren |) cocos2d::Sprite *getSlidBallNormalRenderer()
    cocos2d::Sprite *ret = self->getSlidBallNormalRenderer();
    int num_ret = olua_push_object(L, ret, "cc.Sprite");

    // insert code after call
    olua_addref(L, 1, "protectedChildren", -1, OLUA_REF_MULTI);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Slider_getSlidBallPressedRenderer(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Slider *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Slider");

    // @addref(protectedChildren |) cocos2d::Sprite *getSlidBallPressedRenderer()
    cocos2d::Sprite *ret = self->getSlidBallPressedRenderer();
    int num_ret = olua_push_object(L, ret, "cc.Sprite");

    // insert code after call
    olua_addref(L, 1, "protectedChildren", -1, OLUA_REF_MULTI);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Slider_getSlidBallRenderer(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Slider *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Slider");

    // @addref(protectedChildren |) cocos2d::Node *getSlidBallRenderer()
    cocos2d::Node *ret = self->getSlidBallRenderer();
    int num_ret = olua_push_object(L, ret, "cc.Node");

    // insert code after call
    olua_addref(L, 1, "protectedChildren", -1, OLUA_REF_MULTI);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Slider_getZoomScale(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Slider *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Slider");

    // float getZoomScale()
    float ret = self->getZoomScale();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Slider_isScale9Enabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Slider *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Slider");

    // bool isScale9Enabled()
    bool ret = self->isScale9Enabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Slider_loadBarTexture$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Slider *self = nullptr;
    std::string arg1;       /** fileName */
    cocos2d::ui::Widget::TextureResType arg2 = (cocos2d::ui::Widget::TextureResType)0;       /** resType */

    olua_to_object(L, 1, &self, "ccui.Slider");
    olua_check_string(L, 2, &arg1);
    olua_check_enum(L, 3, &arg2);

    // void loadBarTexture(const std::string &fileName, @optional cocos2d::ui::Widget::TextureResType resType)
    self->loadBarTexture(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Slider_loadBarTexture$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Slider *self = nullptr;
    std::string arg1;       /** fileName */

    olua_to_object(L, 1, &self, "ccui.Slider");
    olua_check_string(L, 2, &arg1);

    // void loadBarTexture(const std::string &fileName)
    self->loadBarTexture(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Slider_loadBarTexture(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccui.Slider")) && (olua_is_string(L, 2))) {
            // void loadBarTexture(const std::string &fileName)
            return _olua_fun_cocos2d_ui_Slider_loadBarTexture$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "ccui.Slider")) && (olua_is_string(L, 2)) && (olua_is_enum(L, 3))) {
            // void loadBarTexture(const std::string &fileName, @optional cocos2d::ui::Widget::TextureResType resType)
            return _olua_fun_cocos2d_ui_Slider_loadBarTexture$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::Slider::loadBarTexture' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_Slider_loadProgressBarTexture$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Slider *self = nullptr;
    std::string arg1;       /** fileName */
    cocos2d::ui::Widget::TextureResType arg2 = (cocos2d::ui::Widget::TextureResType)0;       /** resType */

    olua_to_object(L, 1, &self, "ccui.Slider");
    olua_check_string(L, 2, &arg1);
    olua_check_enum(L, 3, &arg2);

    // void loadProgressBarTexture(const std::string &fileName, @optional cocos2d::ui::Widget::TextureResType resType)
    self->loadProgressBarTexture(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Slider_loadProgressBarTexture$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Slider *self = nullptr;
    std::string arg1;       /** fileName */

    olua_to_object(L, 1, &self, "ccui.Slider");
    olua_check_string(L, 2, &arg1);

    // void loadProgressBarTexture(const std::string &fileName)
    self->loadProgressBarTexture(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Slider_loadProgressBarTexture(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccui.Slider")) && (olua_is_string(L, 2))) {
            // void loadProgressBarTexture(const std::string &fileName)
            return _olua_fun_cocos2d_ui_Slider_loadProgressBarTexture$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "ccui.Slider")) && (olua_is_string(L, 2)) && (olua_is_enum(L, 3))) {
            // void loadProgressBarTexture(const std::string &fileName, @optional cocos2d::ui::Widget::TextureResType resType)
            return _olua_fun_cocos2d_ui_Slider_loadProgressBarTexture$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::Slider::loadProgressBarTexture' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_Slider_loadSlidBallTextureDisabled$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Slider *self = nullptr;
    std::string arg1;       /** disabled */
    cocos2d::ui::Widget::TextureResType arg2 = (cocos2d::ui::Widget::TextureResType)0;       /** resType */

    olua_to_object(L, 1, &self, "ccui.Slider");
    olua_check_string(L, 2, &arg1);
    olua_check_enum(L, 3, &arg2);

    // void loadSlidBallTextureDisabled(const std::string &disabled, @optional cocos2d::ui::Widget::TextureResType resType)
    self->loadSlidBallTextureDisabled(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Slider_loadSlidBallTextureDisabled$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Slider *self = nullptr;
    std::string arg1;       /** disabled */

    olua_to_object(L, 1, &self, "ccui.Slider");
    olua_check_string(L, 2, &arg1);

    // void loadSlidBallTextureDisabled(const std::string &disabled)
    self->loadSlidBallTextureDisabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Slider_loadSlidBallTextureDisabled(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccui.Slider")) && (olua_is_string(L, 2))) {
            // void loadSlidBallTextureDisabled(const std::string &disabled)
            return _olua_fun_cocos2d_ui_Slider_loadSlidBallTextureDisabled$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "ccui.Slider")) && (olua_is_string(L, 2)) && (olua_is_enum(L, 3))) {
            // void loadSlidBallTextureDisabled(const std::string &disabled, @optional cocos2d::ui::Widget::TextureResType resType)
            return _olua_fun_cocos2d_ui_Slider_loadSlidBallTextureDisabled$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::Slider::loadSlidBallTextureDisabled' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_Slider_loadSlidBallTextureNormal$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Slider *self = nullptr;
    std::string arg1;       /** normal */
    cocos2d::ui::Widget::TextureResType arg2 = (cocos2d::ui::Widget::TextureResType)0;       /** resType */

    olua_to_object(L, 1, &self, "ccui.Slider");
    olua_check_string(L, 2, &arg1);
    olua_check_enum(L, 3, &arg2);

    // void loadSlidBallTextureNormal(const std::string &normal, @optional cocos2d::ui::Widget::TextureResType resType)
    self->loadSlidBallTextureNormal(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Slider_loadSlidBallTextureNormal$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Slider *self = nullptr;
    std::string arg1;       /** normal */

    olua_to_object(L, 1, &self, "ccui.Slider");
    olua_check_string(L, 2, &arg1);

    // void loadSlidBallTextureNormal(const std::string &normal)
    self->loadSlidBallTextureNormal(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Slider_loadSlidBallTextureNormal(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccui.Slider")) && (olua_is_string(L, 2))) {
            // void loadSlidBallTextureNormal(const std::string &normal)
            return _olua_fun_cocos2d_ui_Slider_loadSlidBallTextureNormal$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "ccui.Slider")) && (olua_is_string(L, 2)) && (olua_is_enum(L, 3))) {
            // void loadSlidBallTextureNormal(const std::string &normal, @optional cocos2d::ui::Widget::TextureResType resType)
            return _olua_fun_cocos2d_ui_Slider_loadSlidBallTextureNormal$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::Slider::loadSlidBallTextureNormal' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_Slider_loadSlidBallTexturePressed$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Slider *self = nullptr;
    std::string arg1;       /** pressed */
    cocos2d::ui::Widget::TextureResType arg2 = (cocos2d::ui::Widget::TextureResType)0;       /** resType */

    olua_to_object(L, 1, &self, "ccui.Slider");
    olua_check_string(L, 2, &arg1);
    olua_check_enum(L, 3, &arg2);

    // void loadSlidBallTexturePressed(const std::string &pressed, @optional cocos2d::ui::Widget::TextureResType resType)
    self->loadSlidBallTexturePressed(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Slider_loadSlidBallTexturePressed$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Slider *self = nullptr;
    std::string arg1;       /** pressed */

    olua_to_object(L, 1, &self, "ccui.Slider");
    olua_check_string(L, 2, &arg1);

    // void loadSlidBallTexturePressed(const std::string &pressed)
    self->loadSlidBallTexturePressed(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Slider_loadSlidBallTexturePressed(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccui.Slider")) && (olua_is_string(L, 2))) {
            // void loadSlidBallTexturePressed(const std::string &pressed)
            return _olua_fun_cocos2d_ui_Slider_loadSlidBallTexturePressed$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "ccui.Slider")) && (olua_is_string(L, 2)) && (olua_is_enum(L, 3))) {
            // void loadSlidBallTexturePressed(const std::string &pressed, @optional cocos2d::ui::Widget::TextureResType resType)
            return _olua_fun_cocos2d_ui_Slider_loadSlidBallTexturePressed$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::Slider::loadSlidBallTexturePressed' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_Slider_loadSlidBallTextures$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Slider *self = nullptr;
    std::string arg1;       /** normal */
    std::string arg2;       /** pressed */
    std::string arg3;       /** disabled */
    cocos2d::ui::Widget::TextureResType arg4 = (cocos2d::ui::Widget::TextureResType)0;       /** texType */

    olua_to_object(L, 1, &self, "ccui.Slider");
    olua_check_string(L, 2, &arg1);
    olua_check_string(L, 3, &arg2);
    olua_check_string(L, 4, &arg3);
    olua_check_enum(L, 5, &arg4);

    // void loadSlidBallTextures(const std::string &normal, @optional const std::string &pressed, @optional const std::string &disabled, @optional cocos2d::ui::Widget::TextureResType texType)
    self->loadSlidBallTextures(arg1, arg2, arg3, arg4);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Slider_loadSlidBallTextures$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Slider *self = nullptr;
    std::string arg1;       /** normal */

    olua_to_object(L, 1, &self, "ccui.Slider");
    olua_check_string(L, 2, &arg1);

    // void loadSlidBallTextures(const std::string &normal)
    self->loadSlidBallTextures(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Slider_loadSlidBallTextures$3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Slider *self = nullptr;
    std::string arg1;       /** normal */
    std::string arg2;       /** pressed */

    olua_to_object(L, 1, &self, "ccui.Slider");
    olua_check_string(L, 2, &arg1);
    olua_check_string(L, 3, &arg2);

    // void loadSlidBallTextures(const std::string &normal, @optional const std::string &pressed)
    self->loadSlidBallTextures(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Slider_loadSlidBallTextures$4(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Slider *self = nullptr;
    std::string arg1;       /** normal */
    std::string arg2;       /** pressed */
    std::string arg3;       /** disabled */

    olua_to_object(L, 1, &self, "ccui.Slider");
    olua_check_string(L, 2, &arg1);
    olua_check_string(L, 3, &arg2);
    olua_check_string(L, 4, &arg3);

    // void loadSlidBallTextures(const std::string &normal, @optional const std::string &pressed, @optional const std::string &disabled)
    self->loadSlidBallTextures(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Slider_loadSlidBallTextures(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccui.Slider")) && (olua_is_string(L, 2))) {
            // void loadSlidBallTextures(const std::string &normal)
            return _olua_fun_cocos2d_ui_Slider_loadSlidBallTextures$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "ccui.Slider")) && (olua_is_string(L, 2)) && (olua_is_string(L, 3))) {
            // void loadSlidBallTextures(const std::string &normal, @optional const std::string &pressed)
            return _olua_fun_cocos2d_ui_Slider_loadSlidBallTextures$3(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_object(L, 1, "ccui.Slider")) && (olua_is_string(L, 2)) && (olua_is_string(L, 3)) && (olua_is_string(L, 4))) {
            // void loadSlidBallTextures(const std::string &normal, @optional const std::string &pressed, @optional const std::string &disabled)
            return _olua_fun_cocos2d_ui_Slider_loadSlidBallTextures$4(L);
        // }
    }

    if (num_args == 5) {
        // if ((olua_is_object(L, 1, "ccui.Slider")) && (olua_is_string(L, 2)) && (olua_is_string(L, 3)) && (olua_is_string(L, 4)) && (olua_is_enum(L, 5))) {
            // void loadSlidBallTextures(const std::string &normal, @optional const std::string &pressed, @optional const std::string &disabled, @optional cocos2d::ui::Widget::TextureResType texType)
            return _olua_fun_cocos2d_ui_Slider_loadSlidBallTextures$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::Slider::loadSlidBallTextures' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_Slider_new(lua_State *L)
{
    olua_startinvoke(L);

    // cocos2d::ui::Slider()
    cocos2d::ui::Slider *ret = new cocos2d::ui::Slider();
    int num_ret = olua_push_object(L, ret, "ccui.Slider");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Slider_setCapInsetProgressBarRenderer(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Slider *self = nullptr;
    cocos2d::Rect *arg1;       /** capInsets */

    olua_to_object(L, 1, &self, "ccui.Slider");
    olua_check_object(L, 2, &arg1, "cc.Rect");

    // void setCapInsetProgressBarRenderer(const cocos2d::Rect &capInsets)
    self->setCapInsetProgressBarRenderer(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Slider_setCapInsets(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Slider *self = nullptr;
    cocos2d::Rect *arg1;       /** capInsets */

    olua_to_object(L, 1, &self, "ccui.Slider");
    olua_check_object(L, 2, &arg1, "cc.Rect");

    // void setCapInsets(const cocos2d::Rect &capInsets)
    self->setCapInsets(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Slider_setCapInsetsBarRenderer(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Slider *self = nullptr;
    cocos2d::Rect *arg1;       /** capInsets */

    olua_to_object(L, 1, &self, "ccui.Slider");
    olua_check_object(L, 2, &arg1, "cc.Rect");

    // void setCapInsetsBarRenderer(const cocos2d::Rect &capInsets)
    self->setCapInsetsBarRenderer(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Slider_setMaxPercent(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Slider *self = nullptr;
    int arg1 = 0;       /** percent */

    olua_to_object(L, 1, &self, "ccui.Slider");
    olua_check_integer(L, 2, &arg1);

    // void setMaxPercent(int percent)
    self->setMaxPercent(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Slider_setPercent(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Slider *self = nullptr;
    int arg1 = 0;       /** percent */

    olua_to_object(L, 1, &self, "ccui.Slider");
    olua_check_integer(L, 2, &arg1);

    // void setPercent(int percent)
    self->setPercent(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Slider_setScale9Enabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Slider *self = nullptr;
    bool arg1 = false;       /** able */

    olua_to_object(L, 1, &self, "ccui.Slider");
    olua_check_bool(L, 2, &arg1);

    // void setScale9Enabled(bool able)
    self->setScale9Enabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Slider_setZoomScale(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Slider *self = nullptr;
    float arg1 = 0;       /** scale */

    olua_to_object(L, 1, &self, "ccui.Slider");
    olua_check_number(L, 2, &arg1);

    // void setZoomScale(float scale)
    self->setZoomScale(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Slider_updateVisualSlider(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Slider *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Slider");

    // void updateVisualSlider()
    self->updateVisualSlider();

    olua_endinvoke(L);

    return 0;
}

static int _olua_cls_ccui_Slider(lua_State *L)
{
    oluacls_class<cocos2d::ui::Slider, cocos2d::ui::Widget>(L, "ccui.Slider");
    oluacls_func(L, "addEventListener", _olua_fun_cocos2d_ui_Slider_addEventListener);
    oluacls_func(L, "create", _olua_fun_cocos2d_ui_Slider_create);
    oluacls_func(L, "createInstance", _olua_fun_cocos2d_ui_Slider_createInstance);
    oluacls_func(L, "getBackFile", _olua_fun_cocos2d_ui_Slider_getBackFile);
    oluacls_func(L, "getBallDisabledFile", _olua_fun_cocos2d_ui_Slider_getBallDisabledFile);
    oluacls_func(L, "getBallNormalFile", _olua_fun_cocos2d_ui_Slider_getBallNormalFile);
    oluacls_func(L, "getBallPressedFile", _olua_fun_cocos2d_ui_Slider_getBallPressedFile);
    oluacls_func(L, "getCapInsetsBarRenderer", _olua_fun_cocos2d_ui_Slider_getCapInsetsBarRenderer);
    oluacls_func(L, "getCapInsetsProgressBarRenderer", _olua_fun_cocos2d_ui_Slider_getCapInsetsProgressBarRenderer);
    oluacls_func(L, "getMaxPercent", _olua_fun_cocos2d_ui_Slider_getMaxPercent);
    oluacls_func(L, "getPercent", _olua_fun_cocos2d_ui_Slider_getPercent);
    oluacls_func(L, "getProgressBarFile", _olua_fun_cocos2d_ui_Slider_getProgressBarFile);
    oluacls_func(L, "getSlidBallDisabledRenderer", _olua_fun_cocos2d_ui_Slider_getSlidBallDisabledRenderer);
    oluacls_func(L, "getSlidBallNormalRenderer", _olua_fun_cocos2d_ui_Slider_getSlidBallNormalRenderer);
    oluacls_func(L, "getSlidBallPressedRenderer", _olua_fun_cocos2d_ui_Slider_getSlidBallPressedRenderer);
    oluacls_func(L, "getSlidBallRenderer", _olua_fun_cocos2d_ui_Slider_getSlidBallRenderer);
    oluacls_func(L, "getZoomScale", _olua_fun_cocos2d_ui_Slider_getZoomScale);
    oluacls_func(L, "isScale9Enabled", _olua_fun_cocos2d_ui_Slider_isScale9Enabled);
    oluacls_func(L, "loadBarTexture", _olua_fun_cocos2d_ui_Slider_loadBarTexture);
    oluacls_func(L, "loadProgressBarTexture", _olua_fun_cocos2d_ui_Slider_loadProgressBarTexture);
    oluacls_func(L, "loadSlidBallTextureDisabled", _olua_fun_cocos2d_ui_Slider_loadSlidBallTextureDisabled);
    oluacls_func(L, "loadSlidBallTextureNormal", _olua_fun_cocos2d_ui_Slider_loadSlidBallTextureNormal);
    oluacls_func(L, "loadSlidBallTexturePressed", _olua_fun_cocos2d_ui_Slider_loadSlidBallTexturePressed);
    oluacls_func(L, "loadSlidBallTextures", _olua_fun_cocos2d_ui_Slider_loadSlidBallTextures);
    oluacls_func(L, "new", _olua_fun_cocos2d_ui_Slider_new);
    oluacls_func(L, "setCapInsetProgressBarRenderer", _olua_fun_cocos2d_ui_Slider_setCapInsetProgressBarRenderer);
    oluacls_func(L, "setCapInsets", _olua_fun_cocos2d_ui_Slider_setCapInsets);
    oluacls_func(L, "setCapInsetsBarRenderer", _olua_fun_cocos2d_ui_Slider_setCapInsetsBarRenderer);
    oluacls_func(L, "setMaxPercent", _olua_fun_cocos2d_ui_Slider_setMaxPercent);
    oluacls_func(L, "setPercent", _olua_fun_cocos2d_ui_Slider_setPercent);
    oluacls_func(L, "setScale9Enabled", _olua_fun_cocos2d_ui_Slider_setScale9Enabled);
    oluacls_func(L, "setZoomScale", _olua_fun_cocos2d_ui_Slider_setZoomScale);
    oluacls_func(L, "updateVisualSlider", _olua_fun_cocos2d_ui_Slider_updateVisualSlider);
    oluacls_prop(L, "backFile", _olua_fun_cocos2d_ui_Slider_getBackFile, nullptr);
    oluacls_prop(L, "ballDisabledFile", _olua_fun_cocos2d_ui_Slider_getBallDisabledFile, nullptr);
    oluacls_prop(L, "ballNormalFile", _olua_fun_cocos2d_ui_Slider_getBallNormalFile, nullptr);
    oluacls_prop(L, "ballPressedFile", _olua_fun_cocos2d_ui_Slider_getBallPressedFile, nullptr);
    oluacls_prop(L, "capInsetsBarRenderer", _olua_fun_cocos2d_ui_Slider_getCapInsetsBarRenderer, _olua_fun_cocos2d_ui_Slider_setCapInsetsBarRenderer);
    oluacls_prop(L, "capInsetsProgressBarRenderer", _olua_fun_cocos2d_ui_Slider_getCapInsetsProgressBarRenderer, nullptr);
    oluacls_prop(L, "maxPercent", _olua_fun_cocos2d_ui_Slider_getMaxPercent, _olua_fun_cocos2d_ui_Slider_setMaxPercent);
    oluacls_prop(L, "percent", _olua_fun_cocos2d_ui_Slider_getPercent, _olua_fun_cocos2d_ui_Slider_setPercent);
    oluacls_prop(L, "progressBarFile", _olua_fun_cocos2d_ui_Slider_getProgressBarFile, nullptr);
    oluacls_prop(L, "scale9Enabled", _olua_fun_cocos2d_ui_Slider_isScale9Enabled, _olua_fun_cocos2d_ui_Slider_setScale9Enabled);
    oluacls_prop(L, "slidBallDisabledRenderer", _olua_fun_cocos2d_ui_Slider_getSlidBallDisabledRenderer, nullptr);
    oluacls_prop(L, "slidBallNormalRenderer", _olua_fun_cocos2d_ui_Slider_getSlidBallNormalRenderer, nullptr);
    oluacls_prop(L, "slidBallPressedRenderer", _olua_fun_cocos2d_ui_Slider_getSlidBallPressedRenderer, nullptr);
    oluacls_prop(L, "slidBallRenderer", _olua_fun_cocos2d_ui_Slider_getSlidBallRenderer, nullptr);
    oluacls_prop(L, "zoomScale", _olua_fun_cocos2d_ui_Slider_getZoomScale, _olua_fun_cocos2d_ui_Slider_setZoomScale);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_Slider(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.Slider")) {
        luaL_error(L, "class not found: cocos2d::ui::Slider");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_ccui_Text_Type(lua_State *L)
{
    oluacls_class<cocos2d::ui::Text::Type>(L, "ccui.Text.Type");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "SYSTEM", (lua_Integer)cocos2d::ui::Text::Type::SYSTEM);
    oluacls_enum(L, "TTF", (lua_Integer)cocos2d::ui::Text::Type::TTF);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_Text_Type(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.Text.Type")) {
        luaL_error(L, "class not found: cocos2d::ui::Text::Type");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_ui_Text_as(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;
    const char *arg1 = nullptr;       /** cls */

    olua_to_object(L, 1, &self, "ccui.Text");
    olua_check_string(L, 2, &arg1);

    do {
        if (olua_isa(L, 1, arg1)) {
            lua_pushvalue(L, 1);
            break;
        }
        if (olua_strequal(arg1, "cc.BlendProtocol")) {
            olua_pushobj_as<cocos2d::BlendProtocol>(L, 1, self, "as.cc.BlendProtocol");
            break;
        }
        if (olua_strequal(arg1, "ccui.LayoutParameterProtocol")) {
            olua_pushobj_as<cocos2d::ui::LayoutParameterProtocol>(L, 1, self, "as.ccui.LayoutParameterProtocol");
            break;
        }

        luaL_error(L, "'cocos2d::ui::Text' can't cast to '%s'", arg1);
    } while (0);

    olua_endinvoke(L);

    return 1;
}

static int _olua_fun_cocos2d_ui_Text_create$1(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::ui::Text *create()
    cocos2d::ui::Text *ret = cocos2d::ui::Text::create();
    int num_ret = olua_push_object(L, ret, "ccui.Text");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Text_create$2(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** textContent */
    std::string arg2;       /** fontName */
    float arg3 = 0;       /** fontSize */

    olua_check_string(L, 1, &arg1);
    olua_check_string(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);

    // static cocos2d::ui::Text *create(const std::string &textContent, const std::string &fontName, float fontSize)
    cocos2d::ui::Text *ret = cocos2d::ui::Text::create(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "ccui.Text");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Text_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // static cocos2d::ui::Text *create()
        return _olua_fun_cocos2d_ui_Text_create$1(L);
    }

    if (num_args == 3) {
        // if ((olua_is_string(L, 1)) && (olua_is_string(L, 2)) && (olua_is_number(L, 3))) {
            // static cocos2d::ui::Text *create(const std::string &textContent, const std::string &fontName, float fontSize)
            return _olua_fun_cocos2d_ui_Text_create$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::Text::create' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_Text_createInstance(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::Ref *createInstance()
    cocos2d::Ref *ret = cocos2d::ui::Text::createInstance();
    int num_ret = olua_push_object(L, ret, "cc.Ref");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Text_disableEffect$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Text");

    // void disableEffect()
    self->disableEffect();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Text_disableEffect$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;
    cocos2d::LabelEffect arg1 = (cocos2d::LabelEffect)0;       /** effect */

    olua_to_object(L, 1, &self, "ccui.Text");
    olua_check_enum(L, 2, &arg1);

    // void disableEffect(cocos2d::LabelEffect effect)
    self->disableEffect(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Text_disableEffect(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // void disableEffect()
        return _olua_fun_cocos2d_ui_Text_disableEffect$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccui.Text")) && (olua_is_enum(L, 2))) {
            // void disableEffect(cocos2d::LabelEffect effect)
            return _olua_fun_cocos2d_ui_Text_disableEffect$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::Text::disableEffect' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_Text_enableGlow(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;
    cocos2d::Color4B arg1;       /** glowColor */

    olua_to_object(L, 1, &self, "ccui.Text");
    olua_check_cocos2d_Color4B(L, 2, &arg1);

    // void enableGlow(const cocos2d::Color4B &glowColor)
    self->enableGlow(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Text_enableOutline$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;
    cocos2d::Color4B arg1;       /** outlineColor */
    int arg2 = 0;       /** outlineSize */

    olua_to_object(L, 1, &self, "ccui.Text");
    olua_check_cocos2d_Color4B(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // void enableOutline(const cocos2d::Color4B &outlineColor, @optional int outlineSize)
    self->enableOutline(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Text_enableOutline$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;
    cocos2d::Color4B arg1;       /** outlineColor */

    olua_to_object(L, 1, &self, "ccui.Text");
    olua_check_cocos2d_Color4B(L, 2, &arg1);

    // void enableOutline(const cocos2d::Color4B &outlineColor)
    self->enableOutline(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Text_enableOutline(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccui.Text")) && (olua_is_cocos2d_Color4B(L, 2))) {
            // void enableOutline(const cocos2d::Color4B &outlineColor)
            return _olua_fun_cocos2d_ui_Text_enableOutline$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "ccui.Text")) && (olua_is_cocos2d_Color4B(L, 2)) && (olua_is_integer(L, 3))) {
            // void enableOutline(const cocos2d::Color4B &outlineColor, @optional int outlineSize)
            return _olua_fun_cocos2d_ui_Text_enableOutline$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::Text::enableOutline' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_Text_enableShadow$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;
    cocos2d::Color4B arg1;       /** shadowColor */
    cocos2d::Size *arg2;       /** offset */
    int arg3 = 0;       /** blurRadius */

    olua_to_object(L, 1, &self, "ccui.Text");
    olua_check_cocos2d_Color4B(L, 2, &arg1);
    olua_check_object(L, 3, &arg2, "cc.Size");
    olua_check_integer(L, 4, &arg3);

    // void enableShadow(@optional const cocos2d::Color4B &shadowColor, @optional const cocos2d::Size &offset, @optional int blurRadius)
    self->enableShadow(arg1, *arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Text_enableShadow$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Text");

    // void enableShadow()
    self->enableShadow();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Text_enableShadow$3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;
    cocos2d::Color4B arg1;       /** shadowColor */

    olua_to_object(L, 1, &self, "ccui.Text");
    olua_check_cocos2d_Color4B(L, 2, &arg1);

    // void enableShadow(@optional const cocos2d::Color4B &shadowColor)
    self->enableShadow(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Text_enableShadow$4(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;
    cocos2d::Color4B arg1;       /** shadowColor */
    cocos2d::Size *arg2;       /** offset */

    olua_to_object(L, 1, &self, "ccui.Text");
    olua_check_cocos2d_Color4B(L, 2, &arg1);
    olua_check_object(L, 3, &arg2, "cc.Size");

    // void enableShadow(@optional const cocos2d::Color4B &shadowColor, @optional const cocos2d::Size &offset)
    self->enableShadow(arg1, *arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Text_enableShadow(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // void enableShadow()
        return _olua_fun_cocos2d_ui_Text_enableShadow$2(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccui.Text")) && (olua_is_cocos2d_Color4B(L, 2))) {
            // void enableShadow(@optional const cocos2d::Color4B &shadowColor)
            return _olua_fun_cocos2d_ui_Text_enableShadow$3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "ccui.Text")) && (olua_is_cocos2d_Color4B(L, 2)) && (olua_is_object(L, 3, "cc.Size"))) {
            // void enableShadow(@optional const cocos2d::Color4B &shadowColor, @optional const cocos2d::Size &offset)
            return _olua_fun_cocos2d_ui_Text_enableShadow$4(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_object(L, 1, "ccui.Text")) && (olua_is_cocos2d_Color4B(L, 2)) && (olua_is_object(L, 3, "cc.Size")) && (olua_is_integer(L, 4))) {
            // void enableShadow(@optional const cocos2d::Color4B &shadowColor, @optional const cocos2d::Size &offset, @optional int blurRadius)
            return _olua_fun_cocos2d_ui_Text_enableShadow$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::Text::enableShadow' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_Text_getAutoRenderSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Text");

    // cocos2d::Size getAutoRenderSize()
    cocos2d::Size ret = self->getAutoRenderSize();
    int num_ret = olua_copy_object(L, ret, "cc.Size");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Text_getBlendFunc(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Text");

    // const cocos2d::BlendFunc &getBlendFunc()
    const cocos2d::BlendFunc &ret = self->getBlendFunc();
    int num_ret = olua_push_object(L, ret, "cc.BlendFunc");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Text_getEffectColor(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Text");

    // cocos2d::Color4B getEffectColor()
    cocos2d::Color4B ret = self->getEffectColor();
    int num_ret = olua_push_cocos2d_Color4B(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Text_getFontName(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Text");

    // const std::string &getFontName()
    const std::string &ret = self->getFontName();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Text_getFontSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Text");

    // float getFontSize()
    float ret = self->getFontSize();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Text_getLabelEffectType(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Text");

    // cocos2d::LabelEffect getLabelEffectType()
    cocos2d::LabelEffect ret = self->getLabelEffectType();
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Text_getLetter(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;
    int arg1 = 0;       /** lettetIndex */

    olua_to_object(L, 1, &self, "ccui.Text");
    olua_check_integer(L, 2, &arg1);

    // cocos2d::Sprite *getLetter(int lettetIndex)
    cocos2d::Sprite *ret = self->getLetter(arg1);
    int num_ret = olua_push_object(L, ret, "cc.Sprite");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Text_getOutlineSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Text");

    // int getOutlineSize()
    int ret = self->getOutlineSize();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Text_getShadowBlurRadius(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Text");

    // float getShadowBlurRadius()
    float ret = self->getShadowBlurRadius();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Text_getShadowColor(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Text");

    // cocos2d::Color4B getShadowColor()
    cocos2d::Color4B ret = self->getShadowColor();
    int num_ret = olua_push_cocos2d_Color4B(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Text_getShadowOffset(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Text");

    // cocos2d::Size getShadowOffset()
    cocos2d::Size ret = self->getShadowOffset();
    int num_ret = olua_copy_object(L, ret, "cc.Size");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Text_getString(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Text");

    // const std::string &getString()
    const std::string &ret = self->getString();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Text_getStringLength(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Text");

    // ssize_t getStringLength()
    ssize_t ret = self->getStringLength();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Text_getTextAreaSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Text");

    // const cocos2d::Size &getTextAreaSize()
    const cocos2d::Size &ret = self->getTextAreaSize();
    int num_ret = olua_push_object(L, ret, "cc.Size");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Text_getTextColor(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Text");

    // const cocos2d::Color4B &getTextColor()
    const cocos2d::Color4B &ret = self->getTextColor();
    int num_ret = olua_push_cocos2d_Color4B(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Text_getTextHorizontalAlignment(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Text");

    // cocos2d::TextHAlignment getTextHorizontalAlignment()
    cocos2d::TextHAlignment ret = self->getTextHorizontalAlignment();
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Text_getTextVerticalAlignment(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Text");

    // cocos2d::TextVAlignment getTextVerticalAlignment()
    cocos2d::TextVAlignment ret = self->getTextVerticalAlignment();
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Text_getType(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Text");

    // cocos2d::ui::Text::Type getType()
    cocos2d::ui::Text::Type ret = self->getType();
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Text_init$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Text");

    // @using bool init()
    bool ret = self->init();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Text_init$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;
    std::string arg1;       /** textContent */
    std::string arg2;       /** fontName */
    float arg3 = 0;       /** fontSize */

    olua_to_object(L, 1, &self, "ccui.Text");
    olua_check_string(L, 2, &arg1);
    olua_check_string(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);

    // bool init(const std::string &textContent, const std::string &fontName, float fontSize)
    bool ret = self->init(arg1, arg2, arg3);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Text_init(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // @using bool init()
        return _olua_fun_cocos2d_ui_Text_init$1(L);
    }

    if (num_args == 4) {
        // if ((olua_is_object(L, 1, "ccui.Text")) && (olua_is_string(L, 2)) && (olua_is_string(L, 3)) && (olua_is_number(L, 4))) {
            // bool init(const std::string &textContent, const std::string &fontName, float fontSize)
            return _olua_fun_cocos2d_ui_Text_init$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::Text::init' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_Text_isShadowEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Text");

    // bool isShadowEnabled()
    bool ret = self->isShadowEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Text_isTouchScaleChangeEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Text");

    // bool isTouchScaleChangeEnabled()
    bool ret = self->isTouchScaleChangeEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Text_new(lua_State *L)
{
    olua_startinvoke(L);

    // cocos2d::ui::Text()
    cocos2d::ui::Text *ret = new cocos2d::ui::Text();
    int num_ret = olua_push_object(L, ret, "ccui.Text");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Text_setBlendFunc(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;
    cocos2d::BlendFunc *arg1;       /** blendFunc */

    olua_to_object(L, 1, &self, "ccui.Text");
    olua_check_object(L, 2, &arg1, "cc.BlendFunc");

    // void setBlendFunc(const cocos2d::BlendFunc &blendFunc)
    self->setBlendFunc(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Text_setFontName(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;
    std::string arg1;       /** name */

    olua_to_object(L, 1, &self, "ccui.Text");
    olua_check_string(L, 2, &arg1);

    // void setFontName(const std::string &name)
    self->setFontName(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Text_setFontSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;
    float arg1 = 0;       /** size */

    olua_to_object(L, 1, &self, "ccui.Text");
    olua_check_number(L, 2, &arg1);

    // void setFontSize(float size)
    self->setFontSize(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Text_setString(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;
    std::string arg1;       /** text */

    olua_to_object(L, 1, &self, "ccui.Text");
    olua_check_string(L, 2, &arg1);

    // void setString(const std::string &text)
    self->setString(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Text_setTextAreaSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;
    cocos2d::Size *arg1;       /** size */

    olua_to_object(L, 1, &self, "ccui.Text");
    olua_check_object(L, 2, &arg1, "cc.Size");

    // void setTextAreaSize(const cocos2d::Size &size)
    self->setTextAreaSize(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Text_setTextColor(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;
    cocos2d::Color4B arg1;       /** color */

    olua_to_object(L, 1, &self, "ccui.Text");
    olua_check_cocos2d_Color4B(L, 2, &arg1);

    // void setTextColor(const cocos2d::Color4B color)
    self->setTextColor(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Text_setTextHorizontalAlignment(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;
    cocos2d::TextHAlignment arg1 = (cocos2d::TextHAlignment)0;       /** alignment */

    olua_to_object(L, 1, &self, "ccui.Text");
    olua_check_enum(L, 2, &arg1);

    // void setTextHorizontalAlignment(cocos2d::TextHAlignment alignment)
    self->setTextHorizontalAlignment(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Text_setTextVerticalAlignment(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;
    cocos2d::TextVAlignment arg1 = (cocos2d::TextVAlignment)0;       /** alignment */

    olua_to_object(L, 1, &self, "ccui.Text");
    olua_check_enum(L, 2, &arg1);

    // void setTextVerticalAlignment(cocos2d::TextVAlignment alignment)
    self->setTextVerticalAlignment(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Text_setTouchScaleChangeEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;
    bool arg1 = false;       /** enabled */

    olua_to_object(L, 1, &self, "ccui.Text");
    olua_check_bool(L, 2, &arg1);

    // void setTouchScaleChangeEnabled(bool enabled)
    self->setTouchScaleChangeEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_cls_ccui_Text(lua_State *L)
{
    oluacls_class<cocos2d::ui::Text, cocos2d::ui::Widget>(L, "ccui.Text");
    oluacls_func(L, "as", _olua_fun_cocos2d_ui_Text_as);
    oluacls_func(L, "create", _olua_fun_cocos2d_ui_Text_create);
    oluacls_func(L, "createInstance", _olua_fun_cocos2d_ui_Text_createInstance);
    oluacls_func(L, "disableEffect", _olua_fun_cocos2d_ui_Text_disableEffect);
    oluacls_func(L, "enableGlow", _olua_fun_cocos2d_ui_Text_enableGlow);
    oluacls_func(L, "enableOutline", _olua_fun_cocos2d_ui_Text_enableOutline);
    oluacls_func(L, "enableShadow", _olua_fun_cocos2d_ui_Text_enableShadow);
    oluacls_func(L, "getAutoRenderSize", _olua_fun_cocos2d_ui_Text_getAutoRenderSize);
    oluacls_func(L, "getBlendFunc", _olua_fun_cocos2d_ui_Text_getBlendFunc);
    oluacls_func(L, "getEffectColor", _olua_fun_cocos2d_ui_Text_getEffectColor);
    oluacls_func(L, "getFontName", _olua_fun_cocos2d_ui_Text_getFontName);
    oluacls_func(L, "getFontSize", _olua_fun_cocos2d_ui_Text_getFontSize);
    oluacls_func(L, "getLabelEffectType", _olua_fun_cocos2d_ui_Text_getLabelEffectType);
    oluacls_func(L, "getLetter", _olua_fun_cocos2d_ui_Text_getLetter);
    oluacls_func(L, "getOutlineSize", _olua_fun_cocos2d_ui_Text_getOutlineSize);
    oluacls_func(L, "getShadowBlurRadius", _olua_fun_cocos2d_ui_Text_getShadowBlurRadius);
    oluacls_func(L, "getShadowColor", _olua_fun_cocos2d_ui_Text_getShadowColor);
    oluacls_func(L, "getShadowOffset", _olua_fun_cocos2d_ui_Text_getShadowOffset);
    oluacls_func(L, "getString", _olua_fun_cocos2d_ui_Text_getString);
    oluacls_func(L, "getStringLength", _olua_fun_cocos2d_ui_Text_getStringLength);
    oluacls_func(L, "getTextAreaSize", _olua_fun_cocos2d_ui_Text_getTextAreaSize);
    oluacls_func(L, "getTextColor", _olua_fun_cocos2d_ui_Text_getTextColor);
    oluacls_func(L, "getTextHorizontalAlignment", _olua_fun_cocos2d_ui_Text_getTextHorizontalAlignment);
    oluacls_func(L, "getTextVerticalAlignment", _olua_fun_cocos2d_ui_Text_getTextVerticalAlignment);
    oluacls_func(L, "getType", _olua_fun_cocos2d_ui_Text_getType);
    oluacls_func(L, "init", _olua_fun_cocos2d_ui_Text_init);
    oluacls_func(L, "isShadowEnabled", _olua_fun_cocos2d_ui_Text_isShadowEnabled);
    oluacls_func(L, "isTouchScaleChangeEnabled", _olua_fun_cocos2d_ui_Text_isTouchScaleChangeEnabled);
    oluacls_func(L, "new", _olua_fun_cocos2d_ui_Text_new);
    oluacls_func(L, "setBlendFunc", _olua_fun_cocos2d_ui_Text_setBlendFunc);
    oluacls_func(L, "setFontName", _olua_fun_cocos2d_ui_Text_setFontName);
    oluacls_func(L, "setFontSize", _olua_fun_cocos2d_ui_Text_setFontSize);
    oluacls_func(L, "setString", _olua_fun_cocos2d_ui_Text_setString);
    oluacls_func(L, "setTextAreaSize", _olua_fun_cocos2d_ui_Text_setTextAreaSize);
    oluacls_func(L, "setTextColor", _olua_fun_cocos2d_ui_Text_setTextColor);
    oluacls_func(L, "setTextHorizontalAlignment", _olua_fun_cocos2d_ui_Text_setTextHorizontalAlignment);
    oluacls_func(L, "setTextVerticalAlignment", _olua_fun_cocos2d_ui_Text_setTextVerticalAlignment);
    oluacls_func(L, "setTouchScaleChangeEnabled", _olua_fun_cocos2d_ui_Text_setTouchScaleChangeEnabled);
    oluacls_prop(L, "autoRenderSize", _olua_fun_cocos2d_ui_Text_getAutoRenderSize, nullptr);
    oluacls_prop(L, "blendFunc", _olua_fun_cocos2d_ui_Text_getBlendFunc, _olua_fun_cocos2d_ui_Text_setBlendFunc);
    oluacls_prop(L, "effectColor", _olua_fun_cocos2d_ui_Text_getEffectColor, nullptr);
    oluacls_prop(L, "fontName", _olua_fun_cocos2d_ui_Text_getFontName, _olua_fun_cocos2d_ui_Text_setFontName);
    oluacls_prop(L, "fontSize", _olua_fun_cocos2d_ui_Text_getFontSize, _olua_fun_cocos2d_ui_Text_setFontSize);
    oluacls_prop(L, "labelEffectType", _olua_fun_cocos2d_ui_Text_getLabelEffectType, nullptr);
    oluacls_prop(L, "outlineSize", _olua_fun_cocos2d_ui_Text_getOutlineSize, nullptr);
    oluacls_prop(L, "shadowBlurRadius", _olua_fun_cocos2d_ui_Text_getShadowBlurRadius, nullptr);
    oluacls_prop(L, "shadowColor", _olua_fun_cocos2d_ui_Text_getShadowColor, nullptr);
    oluacls_prop(L, "shadowEnabled", _olua_fun_cocos2d_ui_Text_isShadowEnabled, nullptr);
    oluacls_prop(L, "shadowOffset", _olua_fun_cocos2d_ui_Text_getShadowOffset, nullptr);
    oluacls_prop(L, "string", _olua_fun_cocos2d_ui_Text_getString, _olua_fun_cocos2d_ui_Text_setString);
    oluacls_prop(L, "stringLength", _olua_fun_cocos2d_ui_Text_getStringLength, nullptr);
    oluacls_prop(L, "textAreaSize", _olua_fun_cocos2d_ui_Text_getTextAreaSize, _olua_fun_cocos2d_ui_Text_setTextAreaSize);
    oluacls_prop(L, "textColor", _olua_fun_cocos2d_ui_Text_getTextColor, _olua_fun_cocos2d_ui_Text_setTextColor);
    oluacls_prop(L, "textHorizontalAlignment", _olua_fun_cocos2d_ui_Text_getTextHorizontalAlignment, _olua_fun_cocos2d_ui_Text_setTextHorizontalAlignment);
    oluacls_prop(L, "textVerticalAlignment", _olua_fun_cocos2d_ui_Text_getTextVerticalAlignment, _olua_fun_cocos2d_ui_Text_setTextVerticalAlignment);
    oluacls_prop(L, "touchScaleChangeEnabled", _olua_fun_cocos2d_ui_Text_isTouchScaleChangeEnabled, _olua_fun_cocos2d_ui_Text_setTouchScaleChangeEnabled);
    oluacls_prop(L, "type", _olua_fun_cocos2d_ui_Text_getType, nullptr);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_Text(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.Text")) {
        luaL_error(L, "class not found: cocos2d::ui::Text");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_ui_TextAtlas_adaptRenderers(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextAtlas *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.TextAtlas");

    // void adaptRenderers()
    self->adaptRenderers();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_TextAtlas_create$1(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::ui::TextAtlas *create()
    cocos2d::ui::TextAtlas *ret = cocos2d::ui::TextAtlas::create();
    int num_ret = olua_push_object(L, ret, "ccui.TextAtlas");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_TextAtlas_create$2(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** stringValue */
    std::string arg2;       /** charMapFile */
    int arg3 = 0;       /** itemWidth */
    int arg4 = 0;       /** itemHeight */
    std::string arg5;       /** startCharMap */

    olua_check_string(L, 1, &arg1);
    olua_check_string(L, 2, &arg2);
    olua_check_integer(L, 3, &arg3);
    olua_check_integer(L, 4, &arg4);
    olua_check_string(L, 5, &arg5);

    // static cocos2d::ui::TextAtlas *create(const std::string &stringValue, const std::string &charMapFile, int itemWidth, int itemHeight, const std::string &startCharMap)
    cocos2d::ui::TextAtlas *ret = cocos2d::ui::TextAtlas::create(arg1, arg2, arg3, arg4, arg5);
    int num_ret = olua_push_object(L, ret, "ccui.TextAtlas");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_TextAtlas_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // static cocos2d::ui::TextAtlas *create()
        return _olua_fun_cocos2d_ui_TextAtlas_create$1(L);
    }

    if (num_args == 5) {
        // if ((olua_is_string(L, 1)) && (olua_is_string(L, 2)) && (olua_is_integer(L, 3)) && (olua_is_integer(L, 4)) && (olua_is_string(L, 5))) {
            // static cocos2d::ui::TextAtlas *create(const std::string &stringValue, const std::string &charMapFile, int itemWidth, int itemHeight, const std::string &startCharMap)
            return _olua_fun_cocos2d_ui_TextAtlas_create$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::TextAtlas::create' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_TextAtlas_createInstance(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::Ref *createInstance()
    cocos2d::Ref *ret = cocos2d::ui::TextAtlas::createInstance();
    int num_ret = olua_push_object(L, ret, "cc.Ref");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_TextAtlas_getRenderFile(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextAtlas *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.TextAtlas");

    // cocos2d::ResourceData getRenderFile()
    cocos2d::ResourceData ret = self->getRenderFile();
    int num_ret = olua_copy_object(L, ret, "cc.ResourceData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_TextAtlas_getString(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextAtlas *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.TextAtlas");

    // const std::string &getString()
    const std::string &ret = self->getString();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_TextAtlas_getStringLength(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextAtlas *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.TextAtlas");

    // ssize_t getStringLength()
    ssize_t ret = self->getStringLength();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_TextAtlas_new(lua_State *L)
{
    olua_startinvoke(L);

    // cocos2d::ui::TextAtlas()
    cocos2d::ui::TextAtlas *ret = new cocos2d::ui::TextAtlas();
    int num_ret = olua_push_object(L, ret, "ccui.TextAtlas");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_TextAtlas_setProperty(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextAtlas *self = nullptr;
    std::string arg1;       /** stringValue */
    std::string arg2;       /** charMapFile */
    int arg3 = 0;       /** itemWidth */
    int arg4 = 0;       /** itemHeight */
    std::string arg5;       /** startCharMap */

    olua_to_object(L, 1, &self, "ccui.TextAtlas");
    olua_check_string(L, 2, &arg1);
    olua_check_string(L, 3, &arg2);
    olua_check_integer(L, 4, &arg3);
    olua_check_integer(L, 5, &arg4);
    olua_check_string(L, 6, &arg5);

    // void setProperty(const std::string &stringValue, const std::string &charMapFile, int itemWidth, int itemHeight, const std::string &startCharMap)
    self->setProperty(arg1, arg2, arg3, arg4, arg5);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_TextAtlas_setString(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextAtlas *self = nullptr;
    std::string arg1;       /** value */

    olua_to_object(L, 1, &self, "ccui.TextAtlas");
    olua_check_string(L, 2, &arg1);

    // void setString(const std::string &value)
    self->setString(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_cls_ccui_TextAtlas(lua_State *L)
{
    oluacls_class<cocos2d::ui::TextAtlas, cocos2d::ui::Widget>(L, "ccui.TextAtlas");
    oluacls_func(L, "adaptRenderers", _olua_fun_cocos2d_ui_TextAtlas_adaptRenderers);
    oluacls_func(L, "create", _olua_fun_cocos2d_ui_TextAtlas_create);
    oluacls_func(L, "createInstance", _olua_fun_cocos2d_ui_TextAtlas_createInstance);
    oluacls_func(L, "getRenderFile", _olua_fun_cocos2d_ui_TextAtlas_getRenderFile);
    oluacls_func(L, "getString", _olua_fun_cocos2d_ui_TextAtlas_getString);
    oluacls_func(L, "getStringLength", _olua_fun_cocos2d_ui_TextAtlas_getStringLength);
    oluacls_func(L, "new", _olua_fun_cocos2d_ui_TextAtlas_new);
    oluacls_func(L, "setProperty", _olua_fun_cocos2d_ui_TextAtlas_setProperty);
    oluacls_func(L, "setString", _olua_fun_cocos2d_ui_TextAtlas_setString);
    oluacls_prop(L, "renderFile", _olua_fun_cocos2d_ui_TextAtlas_getRenderFile, nullptr);
    oluacls_prop(L, "string", _olua_fun_cocos2d_ui_TextAtlas_getString, _olua_fun_cocos2d_ui_TextAtlas_setString);
    oluacls_prop(L, "stringLength", _olua_fun_cocos2d_ui_TextAtlas_getStringLength, nullptr);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_TextAtlas(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.TextAtlas")) {
        luaL_error(L, "class not found: cocos2d::ui::TextAtlas");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_ui_TextBMFont_create$1(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::ui::TextBMFont *create()
    cocos2d::ui::TextBMFont *ret = cocos2d::ui::TextBMFont::create();
    int num_ret = olua_push_object(L, ret, "ccui.TextBMFont");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_TextBMFont_create$2(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** text */
    std::string arg2;       /** filename */

    olua_check_string(L, 1, &arg1);
    olua_check_string(L, 2, &arg2);

    // static cocos2d::ui::TextBMFont *create(const std::string &text, const std::string &filename)
    cocos2d::ui::TextBMFont *ret = cocos2d::ui::TextBMFont::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "ccui.TextBMFont");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_TextBMFont_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // static cocos2d::ui::TextBMFont *create()
        return _olua_fun_cocos2d_ui_TextBMFont_create$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_string(L, 1)) && (olua_is_string(L, 2))) {
            // static cocos2d::ui::TextBMFont *create(const std::string &text, const std::string &filename)
            return _olua_fun_cocos2d_ui_TextBMFont_create$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::TextBMFont::create' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_TextBMFont_createInstance(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::Ref *createInstance()
    cocos2d::Ref *ret = cocos2d::ui::TextBMFont::createInstance();
    int num_ret = olua_push_object(L, ret, "cc.Ref");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_TextBMFont_getRenderFile(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextBMFont *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.TextBMFont");

    // cocos2d::ResourceData getRenderFile()
    cocos2d::ResourceData ret = self->getRenderFile();
    int num_ret = olua_copy_object(L, ret, "cc.ResourceData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_TextBMFont_getString(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextBMFont *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.TextBMFont");

    // const std::string &getString()
    const std::string &ret = self->getString();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_TextBMFont_getStringLength(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextBMFont *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.TextBMFont");

    // ssize_t getStringLength()
    ssize_t ret = self->getStringLength();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_TextBMFont_new(lua_State *L)
{
    olua_startinvoke(L);

    // cocos2d::ui::TextBMFont()
    cocos2d::ui::TextBMFont *ret = new cocos2d::ui::TextBMFont();
    int num_ret = olua_push_object(L, ret, "ccui.TextBMFont");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_TextBMFont_resetRender(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextBMFont *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.TextBMFont");

    // void resetRender()
    self->resetRender();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_TextBMFont_setFntFile(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextBMFont *self = nullptr;
    std::string arg1;       /** fileName */

    olua_to_object(L, 1, &self, "ccui.TextBMFont");
    olua_check_string(L, 2, &arg1);

    // void setFntFile(const std::string &fileName)
    self->setFntFile(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_TextBMFont_setString(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextBMFont *self = nullptr;
    std::string arg1;       /** value */

    olua_to_object(L, 1, &self, "ccui.TextBMFont");
    olua_check_string(L, 2, &arg1);

    // void setString(const std::string &value)
    self->setString(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_cls_ccui_TextBMFont(lua_State *L)
{
    oluacls_class<cocos2d::ui::TextBMFont, cocos2d::ui::Widget>(L, "ccui.TextBMFont");
    oluacls_func(L, "create", _olua_fun_cocos2d_ui_TextBMFont_create);
    oluacls_func(L, "createInstance", _olua_fun_cocos2d_ui_TextBMFont_createInstance);
    oluacls_func(L, "getRenderFile", _olua_fun_cocos2d_ui_TextBMFont_getRenderFile);
    oluacls_func(L, "getString", _olua_fun_cocos2d_ui_TextBMFont_getString);
    oluacls_func(L, "getStringLength", _olua_fun_cocos2d_ui_TextBMFont_getStringLength);
    oluacls_func(L, "new", _olua_fun_cocos2d_ui_TextBMFont_new);
    oluacls_func(L, "resetRender", _olua_fun_cocos2d_ui_TextBMFont_resetRender);
    oluacls_func(L, "setFntFile", _olua_fun_cocos2d_ui_TextBMFont_setFntFile);
    oluacls_func(L, "setString", _olua_fun_cocos2d_ui_TextBMFont_setString);
    oluacls_prop(L, "renderFile", _olua_fun_cocos2d_ui_TextBMFont_getRenderFile, nullptr);
    oluacls_prop(L, "string", _olua_fun_cocos2d_ui_TextBMFont_getString, _olua_fun_cocos2d_ui_TextBMFont_setString);
    oluacls_prop(L, "stringLength", _olua_fun_cocos2d_ui_TextBMFont_getStringLength, nullptr);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_TextBMFont(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.TextBMFont")) {
        luaL_error(L, "class not found: cocos2d::ui::TextBMFont");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_ui_UICCTextField_as(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::UICCTextField *self = nullptr;
    const char *arg1 = nullptr;       /** cls */

    olua_to_object(L, 1, &self, "ccui.UICCTextField");
    olua_check_string(L, 2, &arg1);

    do {
        if (olua_isa(L, 1, arg1)) {
            lua_pushvalue(L, 1);
            break;
        }
        if (olua_strequal(arg1, "cc.BlendProtocol")) {
            olua_pushobj_as<cocos2d::BlendProtocol>(L, 1, self, "as.cc.BlendProtocol");
            break;
        }
        if (olua_strequal(arg1, "cc.IMEDelegate")) {
            olua_pushobj_as<cocos2d::IMEDelegate>(L, 1, self, "as.cc.IMEDelegate");
            break;
        }
        if (olua_strequal(arg1, "cc.LabelProtocol")) {
            olua_pushobj_as<cocos2d::LabelProtocol>(L, 1, self, "as.cc.LabelProtocol");
            break;
        }
        if (olua_strequal(arg1, "cc.TextFieldDelegate")) {
            olua_pushobj_as<cocos2d::TextFieldDelegate>(L, 1, self, "as.cc.TextFieldDelegate");
            break;
        }

        luaL_error(L, "'cocos2d::ui::UICCTextField' can't cast to '%s'", arg1);
    } while (0);

    olua_endinvoke(L);

    return 1;
}

static int _olua_fun_cocos2d_ui_UICCTextField_closeIME(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::UICCTextField *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.UICCTextField");

    // void closeIME()
    self->closeIME();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_UICCTextField_create$1(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::ui::UICCTextField *create()
    cocos2d::ui::UICCTextField *ret = cocos2d::ui::UICCTextField::create();
    int num_ret = olua_push_object(L, ret, "ccui.UICCTextField");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_UICCTextField_create$2(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** placeholder */
    std::string arg2;       /** fontName */
    float arg3 = 0;       /** fontSize */

    olua_check_string(L, 1, &arg1);
    olua_check_string(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);

    // static cocos2d::ui::UICCTextField *create(const std::string &placeholder, const std::string &fontName, float fontSize)
    cocos2d::ui::UICCTextField *ret = cocos2d::ui::UICCTextField::create(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "ccui.UICCTextField");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_UICCTextField_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // static cocos2d::ui::UICCTextField *create()
        return _olua_fun_cocos2d_ui_UICCTextField_create$1(L);
    }

    if (num_args == 3) {
        // if ((olua_is_string(L, 1)) && (olua_is_string(L, 2)) && (olua_is_number(L, 3))) {
            // static cocos2d::ui::UICCTextField *create(const std::string &placeholder, const std::string &fontName, float fontSize)
            return _olua_fun_cocos2d_ui_UICCTextField_create$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::UICCTextField::create' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_UICCTextField_getAttachWithIME(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::UICCTextField *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.UICCTextField");

    // bool getAttachWithIME()
    bool ret = self->getAttachWithIME();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_UICCTextField_getDeleteBackward(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::UICCTextField *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.UICCTextField");

    // bool getDeleteBackward()
    bool ret = self->getDeleteBackward();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_UICCTextField_getDetachWithIME(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::UICCTextField *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.UICCTextField");

    // bool getDetachWithIME()
    bool ret = self->getDetachWithIME();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_UICCTextField_getInsertText(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::UICCTextField *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.UICCTextField");

    // bool getInsertText()
    bool ret = self->getInsertText();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_UICCTextField_getMaxLength(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::UICCTextField *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.UICCTextField");

    // int getMaxLength()
    int ret = self->getMaxLength();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_UICCTextField_insertText(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::UICCTextField *self = nullptr;
    const char *arg1 = nullptr;       /** text */
    size_t arg2 = 0;       /** len */

    olua_to_object(L, 1, &self, "ccui.UICCTextField");
    olua_check_string(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // void insertText(const char *text, size_t len)
    self->insertText(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_UICCTextField_isMaxLengthEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::UICCTextField *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.UICCTextField");

    // bool isMaxLengthEnabled()
    bool ret = self->isMaxLengthEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_UICCTextField_isPasswordEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::UICCTextField *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.UICCTextField");

    // bool isPasswordEnabled()
    bool ret = self->isPasswordEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_UICCTextField_new(lua_State *L)
{
    olua_startinvoke(L);

    // cocos2d::ui::UICCTextField()
    cocos2d::ui::UICCTextField *ret = new cocos2d::ui::UICCTextField();
    int num_ret = olua_push_object(L, ret, "ccui.UICCTextField");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_UICCTextField_onTextFieldAttachWithIME(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::UICCTextField *self = nullptr;
    cocos2d::TextFieldTTF *arg1 = nullptr;       /** pSender */

    olua_to_object(L, 1, &self, "ccui.UICCTextField");
    olua_check_object(L, 2, &arg1, "cc.TextFieldTTF");

    // bool onTextFieldAttachWithIME(cocos2d::TextFieldTTF *pSender)
    bool ret = self->onTextFieldAttachWithIME(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_UICCTextField_onTextFieldDeleteBackward(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::UICCTextField *self = nullptr;
    cocos2d::TextFieldTTF *arg1 = nullptr;       /** pSender */
    const char *arg2 = nullptr;       /** delText */
    size_t arg3 = 0;       /** nLen */

    olua_to_object(L, 1, &self, "ccui.UICCTextField");
    olua_check_object(L, 2, &arg1, "cc.TextFieldTTF");
    olua_check_string(L, 3, &arg2);
    olua_check_integer(L, 4, &arg3);

    // bool onTextFieldDeleteBackward(cocos2d::TextFieldTTF *pSender, const char *delText, size_t nLen)
    bool ret = self->onTextFieldDeleteBackward(arg1, arg2, arg3);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_UICCTextField_onTextFieldDetachWithIME(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::UICCTextField *self = nullptr;
    cocos2d::TextFieldTTF *arg1 = nullptr;       /** pSender */

    olua_to_object(L, 1, &self, "ccui.UICCTextField");
    olua_check_object(L, 2, &arg1, "cc.TextFieldTTF");

    // bool onTextFieldDetachWithIME(cocos2d::TextFieldTTF *pSender)
    bool ret = self->onTextFieldDetachWithIME(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_UICCTextField_onTextFieldInsertText(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::UICCTextField *self = nullptr;
    cocos2d::TextFieldTTF *arg1 = nullptr;       /** pSender */
    const char *arg2 = nullptr;       /** text */
    size_t arg3 = 0;       /** nLen */

    olua_to_object(L, 1, &self, "ccui.UICCTextField");
    olua_check_object(L, 2, &arg1, "cc.TextFieldTTF");
    olua_check_string(L, 3, &arg2);
    olua_check_integer(L, 4, &arg3);

    // bool onTextFieldInsertText(cocos2d::TextFieldTTF *pSender, const char *text, size_t nLen)
    bool ret = self->onTextFieldInsertText(arg1, arg2, arg3);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_UICCTextField_onVisit(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::UICCTextField *self = nullptr;
    cocos2d::TextFieldTTF *arg1 = nullptr;       /** sender */
    cocos2d::Renderer *arg2 = nullptr;       /** renderer */
    cocos2d::Mat4 *arg3;       /** transform */
    uint32_t arg4 = 0;       /** flags */

    olua_to_object(L, 1, &self, "ccui.UICCTextField");
    olua_check_object(L, 2, &arg1, "cc.TextFieldTTF");
    olua_check_object(L, 3, &arg2, "cc.Renderer");
    olua_check_object(L, 4, &arg3, "cc.Mat4");
    olua_check_integer(L, 5, &arg4);

    // @copyfrom(cocos2d::TextFieldDelegate) bool onVisit(cocos2d::TextFieldTTF *sender, cocos2d::Renderer *renderer, const cocos2d::Mat4 &transform, uint32_t flags)
    bool ret = self->onVisit(arg1, arg2, *arg3, arg4);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_UICCTextField_openIME(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::UICCTextField *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.UICCTextField");

    // void openIME()
    self->openIME();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_UICCTextField_setAttachWithIME(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::UICCTextField *self = nullptr;
    bool arg1 = false;       /** attach */

    olua_to_object(L, 1, &self, "ccui.UICCTextField");
    olua_check_bool(L, 2, &arg1);

    // void setAttachWithIME(bool attach)
    self->setAttachWithIME(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_UICCTextField_setDeleteBackward(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::UICCTextField *self = nullptr;
    bool arg1 = false;       /** deleteBackward */

    olua_to_object(L, 1, &self, "ccui.UICCTextField");
    olua_check_bool(L, 2, &arg1);

    // void setDeleteBackward(bool deleteBackward)
    self->setDeleteBackward(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_UICCTextField_setDetachWithIME(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::UICCTextField *self = nullptr;
    bool arg1 = false;       /** detach */

    olua_to_object(L, 1, &self, "ccui.UICCTextField");
    olua_check_bool(L, 2, &arg1);

    // void setDetachWithIME(bool detach)
    self->setDetachWithIME(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_UICCTextField_setInsertText(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::UICCTextField *self = nullptr;
    bool arg1 = false;       /** insert */

    olua_to_object(L, 1, &self, "ccui.UICCTextField");
    olua_check_bool(L, 2, &arg1);

    // void setInsertText(bool insert)
    self->setInsertText(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_UICCTextField_setMaxLength(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::UICCTextField *self = nullptr;
    int arg1 = 0;       /** length */

    olua_to_object(L, 1, &self, "ccui.UICCTextField");
    olua_check_integer(L, 2, &arg1);

    // void setMaxLength(int length)
    self->setMaxLength(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_UICCTextField_setMaxLengthEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::UICCTextField *self = nullptr;
    bool arg1 = false;       /** enable */

    olua_to_object(L, 1, &self, "ccui.UICCTextField");
    olua_check_bool(L, 2, &arg1);

    // void setMaxLengthEnabled(bool enable)
    self->setMaxLengthEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_UICCTextField_setPasswordEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::UICCTextField *self = nullptr;
    bool arg1 = false;       /** enable */

    olua_to_object(L, 1, &self, "ccui.UICCTextField");
    olua_check_bool(L, 2, &arg1);

    // void setPasswordEnabled(bool enable)
    self->setPasswordEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_UICCTextField_setPasswordStyleText(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::UICCTextField *self = nullptr;
    std::string arg1;       /** styleText */

    olua_to_object(L, 1, &self, "ccui.UICCTextField");
    olua_check_string(L, 2, &arg1);

    // void setPasswordStyleText(const std::string &styleText)
    self->setPasswordStyleText(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_UICCTextField_setPasswordText(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::UICCTextField *self = nullptr;
    std::string arg1;       /** text */

    olua_to_object(L, 1, &self, "ccui.UICCTextField");
    olua_check_string(L, 2, &arg1);

    // void setPasswordText(const std::string &text)
    self->setPasswordText(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_cls_ccui_UICCTextField(lua_State *L)
{
    oluacls_class<cocos2d::ui::UICCTextField, cocos2d::TextFieldTTF>(L, "ccui.UICCTextField");
    oluacls_func(L, "as", _olua_fun_cocos2d_ui_UICCTextField_as);
    oluacls_func(L, "closeIME", _olua_fun_cocos2d_ui_UICCTextField_closeIME);
    oluacls_func(L, "create", _olua_fun_cocos2d_ui_UICCTextField_create);
    oluacls_func(L, "getAttachWithIME", _olua_fun_cocos2d_ui_UICCTextField_getAttachWithIME);
    oluacls_func(L, "getDeleteBackward", _olua_fun_cocos2d_ui_UICCTextField_getDeleteBackward);
    oluacls_func(L, "getDetachWithIME", _olua_fun_cocos2d_ui_UICCTextField_getDetachWithIME);
    oluacls_func(L, "getInsertText", _olua_fun_cocos2d_ui_UICCTextField_getInsertText);
    oluacls_func(L, "getMaxLength", _olua_fun_cocos2d_ui_UICCTextField_getMaxLength);
    oluacls_func(L, "insertText", _olua_fun_cocos2d_ui_UICCTextField_insertText);
    oluacls_func(L, "isMaxLengthEnabled", _olua_fun_cocos2d_ui_UICCTextField_isMaxLengthEnabled);
    oluacls_func(L, "isPasswordEnabled", _olua_fun_cocos2d_ui_UICCTextField_isPasswordEnabled);
    oluacls_func(L, "new", _olua_fun_cocos2d_ui_UICCTextField_new);
    oluacls_func(L, "onTextFieldAttachWithIME", _olua_fun_cocos2d_ui_UICCTextField_onTextFieldAttachWithIME);
    oluacls_func(L, "onTextFieldDeleteBackward", _olua_fun_cocos2d_ui_UICCTextField_onTextFieldDeleteBackward);
    oluacls_func(L, "onTextFieldDetachWithIME", _olua_fun_cocos2d_ui_UICCTextField_onTextFieldDetachWithIME);
    oluacls_func(L, "onTextFieldInsertText", _olua_fun_cocos2d_ui_UICCTextField_onTextFieldInsertText);
    oluacls_func(L, "onVisit", _olua_fun_cocos2d_ui_UICCTextField_onVisit);
    oluacls_func(L, "openIME", _olua_fun_cocos2d_ui_UICCTextField_openIME);
    oluacls_func(L, "setAttachWithIME", _olua_fun_cocos2d_ui_UICCTextField_setAttachWithIME);
    oluacls_func(L, "setDeleteBackward", _olua_fun_cocos2d_ui_UICCTextField_setDeleteBackward);
    oluacls_func(L, "setDetachWithIME", _olua_fun_cocos2d_ui_UICCTextField_setDetachWithIME);
    oluacls_func(L, "setInsertText", _olua_fun_cocos2d_ui_UICCTextField_setInsertText);
    oluacls_func(L, "setMaxLength", _olua_fun_cocos2d_ui_UICCTextField_setMaxLength);
    oluacls_func(L, "setMaxLengthEnabled", _olua_fun_cocos2d_ui_UICCTextField_setMaxLengthEnabled);
    oluacls_func(L, "setPasswordEnabled", _olua_fun_cocos2d_ui_UICCTextField_setPasswordEnabled);
    oluacls_func(L, "setPasswordStyleText", _olua_fun_cocos2d_ui_UICCTextField_setPasswordStyleText);
    oluacls_func(L, "setPasswordText", _olua_fun_cocos2d_ui_UICCTextField_setPasswordText);
    oluacls_prop(L, "attachWithIME", _olua_fun_cocos2d_ui_UICCTextField_getAttachWithIME, _olua_fun_cocos2d_ui_UICCTextField_setAttachWithIME);
    oluacls_prop(L, "deleteBackward", _olua_fun_cocos2d_ui_UICCTextField_getDeleteBackward, _olua_fun_cocos2d_ui_UICCTextField_setDeleteBackward);
    oluacls_prop(L, "detachWithIME", _olua_fun_cocos2d_ui_UICCTextField_getDetachWithIME, _olua_fun_cocos2d_ui_UICCTextField_setDetachWithIME);
    oluacls_prop(L, "maxLength", _olua_fun_cocos2d_ui_UICCTextField_getMaxLength, _olua_fun_cocos2d_ui_UICCTextField_setMaxLength);
    oluacls_prop(L, "maxLengthEnabled", _olua_fun_cocos2d_ui_UICCTextField_isMaxLengthEnabled, _olua_fun_cocos2d_ui_UICCTextField_setMaxLengthEnabled);
    oluacls_prop(L, "passwordEnabled", _olua_fun_cocos2d_ui_UICCTextField_isPasswordEnabled, _olua_fun_cocos2d_ui_UICCTextField_setPasswordEnabled);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_UICCTextField(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.UICCTextField")) {
        luaL_error(L, "class not found: cocos2d::ui::UICCTextField");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_ccui_TextField_EventType(lua_State *L)
{
    oluacls_class<cocos2d::ui::TextField::EventType>(L, "ccui.TextField.EventType");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "ATTACH_WITH_IME", (lua_Integer)cocos2d::ui::TextField::EventType::ATTACH_WITH_IME);
    oluacls_enum(L, "DELETE_BACKWARD", (lua_Integer)cocos2d::ui::TextField::EventType::DELETE_BACKWARD);
    oluacls_enum(L, "DETACH_WITH_IME", (lua_Integer)cocos2d::ui::TextField::EventType::DETACH_WITH_IME);
    oluacls_enum(L, "INSERT_TEXT", (lua_Integer)cocos2d::ui::TextField::EventType::INSERT_TEXT);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_TextField_EventType(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.TextField.EventType")) {
        luaL_error(L, "class not found: cocos2d::ui::TextField::EventType");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_ui_TextField_ccTextFieldCallback___call(lua_State *L)
{
    olua_startinvoke(L);

    luaL_checktype(L, -1, LUA_TFUNCTION);
    olua_push_callback(L, (cocos2d::ui::TextField::ccTextFieldCallback *)nullptr, "ccui.TextField.ccTextFieldCallback");

    olua_endinvoke(L);

    return 1;
}

static int _olua_cls_ccui_TextField_ccTextFieldCallback(lua_State *L)
{
    oluacls_class<cocos2d::ui::TextField::ccTextFieldCallback>(L, "ccui.TextField.ccTextFieldCallback");
    oluacls_func(L, "__call", _olua_fun_cocos2d_ui_TextField_ccTextFieldCallback___call);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_TextField_ccTextFieldCallback(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.TextField.ccTextFieldCallback")) {
        luaL_error(L, "class not found: cocos2d::ui::TextField::ccTextFieldCallback");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_ui_TextField_addEventListener(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;
    cocos2d::ui::TextField::ccTextFieldCallback arg1;       /** callback */

    olua_to_object(L, 1, &self, "ccui.TextField");
    olua_check_callback(L, 2, &arg1, "ccui.TextField.ccTextFieldCallback");

    void *cb_store = (void *)self;
    std::string cb_tag = "textFieldCallback";
    std::string cb_name = olua_setcallback(L, cb_store, 2, cb_tag.c_str(), OLUA_TAG_REPLACE);
    olua_Context cb_ctx = olua_context(L);
    // lua_State *ML = olua_mainthread(L);
    arg1 = [cb_store, cb_name, cb_ctx /*, ML */](cocos2d::Ref *cb_arg1, cocos2d::ui::TextField::EventType cb_arg2) {
        lua_State *L = olua_mainthread(NULL);
        olua_checkhostthread();

        if (olua_contextequal(L, cb_ctx)) {
            int top = lua_gettop(L);
            olua_push_object(L, cb_arg1, "cc.Ref");
            olua_push_enum(L, cb_arg2);

            olua_callback(L, cb_store, cb_name.c_str(), 2);

            lua_settop(L, top);
        }
    };

    // void addEventListener(const cocos2d::ui::TextField::ccTextFieldCallback &callback)
    self->addEventListener(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_TextField_attachWithIME(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.TextField");

    // void attachWithIME()
    self->attachWithIME();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_TextField_create$1(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::ui::TextField *create()
    cocos2d::ui::TextField *ret = cocos2d::ui::TextField::create();
    int num_ret = olua_push_object(L, ret, "ccui.TextField");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_TextField_create$2(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** placeholder */
    std::string arg2;       /** fontName */
    int arg3 = 0;       /** fontSize */

    olua_check_string(L, 1, &arg1);
    olua_check_string(L, 2, &arg2);
    olua_check_integer(L, 3, &arg3);

    // static cocos2d::ui::TextField *create(const std::string &placeholder, const std::string &fontName, int fontSize)
    cocos2d::ui::TextField *ret = cocos2d::ui::TextField::create(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "ccui.TextField");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_TextField_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // static cocos2d::ui::TextField *create()
        return _olua_fun_cocos2d_ui_TextField_create$1(L);
    }

    if (num_args == 3) {
        // if ((olua_is_string(L, 1)) && (olua_is_string(L, 2)) && (olua_is_integer(L, 3))) {
            // static cocos2d::ui::TextField *create(const std::string &placeholder, const std::string &fontName, int fontSize)
            return _olua_fun_cocos2d_ui_TextField_create$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::TextField::create' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_TextField_createInstance(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::Ref *createInstance()
    cocos2d::Ref *ret = cocos2d::ui::TextField::createInstance();
    int num_ret = olua_push_object(L, ret, "cc.Ref");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_TextField_didNotSelectSelf(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.TextField");

    // void didNotSelectSelf()
    self->didNotSelectSelf();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_TextField_getAttachWithIME(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.TextField");

    // bool getAttachWithIME()
    bool ret = self->getAttachWithIME();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_TextField_getAutoRenderSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.TextField");

    // cocos2d::Size getAutoRenderSize()
    cocos2d::Size ret = self->getAutoRenderSize();
    int num_ret = olua_copy_object(L, ret, "cc.Size");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_TextField_getDeleteBackward(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.TextField");

    // bool getDeleteBackward()
    bool ret = self->getDeleteBackward();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_TextField_getDetachWithIME(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.TextField");

    // bool getDetachWithIME()
    bool ret = self->getDetachWithIME();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_TextField_getFontName(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.TextField");

    // const std::string &getFontName()
    const std::string &ret = self->getFontName();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_TextField_getFontSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.TextField");

    // int getFontSize()
    int ret = self->getFontSize();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_TextField_getInsertText(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.TextField");

    // bool getInsertText()
    bool ret = self->getInsertText();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_TextField_getMaxLength(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.TextField");

    // int getMaxLength()
    int ret = self->getMaxLength();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_TextField_getPasswordStyleText(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.TextField");

    // const char *getPasswordStyleText()
    const char *ret = self->getPasswordStyleText();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_TextField_getPlaceHolder(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.TextField");

    // const std::string &getPlaceHolder()
    const std::string &ret = self->getPlaceHolder();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_TextField_getPlaceHolderColor(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.TextField");

    // const cocos2d::Color4B &getPlaceHolderColor()
    const cocos2d::Color4B &ret = self->getPlaceHolderColor();
    int num_ret = olua_push_cocos2d_Color4B(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_TextField_getString(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.TextField");

    // const std::string &getString()
    const std::string &ret = self->getString();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_TextField_getStringLength(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.TextField");

    // int getStringLength()
    int ret = self->getStringLength();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_TextField_getTextColor(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.TextField");

    // const cocos2d::Color4B &getTextColor()
    const cocos2d::Color4B &ret = self->getTextColor();
    int num_ret = olua_push_cocos2d_Color4B(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_TextField_getTextHorizontalAlignment(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.TextField");

    // cocos2d::TextHAlignment getTextHorizontalAlignment()
    cocos2d::TextHAlignment ret = self->getTextHorizontalAlignment();
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_TextField_getTextVerticalAlignment(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.TextField");

    // cocos2d::TextVAlignment getTextVerticalAlignment()
    cocos2d::TextVAlignment ret = self->getTextVerticalAlignment();
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_TextField_getTouchSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.TextField");

    // cocos2d::Size getTouchSize()
    cocos2d::Size ret = self->getTouchSize();
    int num_ret = olua_copy_object(L, ret, "cc.Size");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_TextField_isMaxLengthEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.TextField");

    // bool isMaxLengthEnabled()
    bool ret = self->isMaxLengthEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_TextField_isPasswordEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.TextField");

    // bool isPasswordEnabled()
    bool ret = self->isPasswordEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_TextField_new(lua_State *L)
{
    olua_startinvoke(L);

    // cocos2d::ui::TextField()
    cocos2d::ui::TextField *ret = new cocos2d::ui::TextField();
    int num_ret = olua_push_object(L, ret, "ccui.TextField");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_TextField_setAttachWithIME(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;
    bool arg1 = false;       /** attach */

    olua_to_object(L, 1, &self, "ccui.TextField");
    olua_check_bool(L, 2, &arg1);

    // void setAttachWithIME(bool attach)
    self->setAttachWithIME(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_TextField_setCursorChar(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;
    char arg1 = 0;       /** cursor */

    olua_to_object(L, 1, &self, "ccui.TextField");
    olua_check_integer(L, 2, &arg1);

    // void setCursorChar(char cursor)
    self->setCursorChar(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_TextField_setCursorEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;
    bool arg1 = false;       /** enabled */

    olua_to_object(L, 1, &self, "ccui.TextField");
    olua_check_bool(L, 2, &arg1);

    // void setCursorEnabled(bool enabled)
    self->setCursorEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_TextField_setCursorFromPoint(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;
    cocos2d::Vec2 *arg1;       /** point */
    cocos2d::Camera *arg2 = nullptr;       /** camera */

    olua_to_object(L, 1, &self, "ccui.TextField");
    olua_check_object(L, 2, &arg1, "cc.Vec2");
    olua_check_object(L, 3, &arg2, "cc.Camera");

    // void setCursorFromPoint(const cocos2d::Vec2 &point, const cocos2d::Camera *camera)
    self->setCursorFromPoint(*arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_TextField_setCursorPosition(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;
    std::size_t arg1 = 0;       /** cursorPosition */

    olua_to_object(L, 1, &self, "ccui.TextField");
    olua_check_integer(L, 2, &arg1);

    // void setCursorPosition(std::size_t cursorPosition)
    self->setCursorPosition(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_TextField_setDeleteBackward(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;
    bool arg1 = false;       /** deleteBackward */

    olua_to_object(L, 1, &self, "ccui.TextField");
    olua_check_bool(L, 2, &arg1);

    // void setDeleteBackward(bool deleteBackward)
    self->setDeleteBackward(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_TextField_setDetachWithIME(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;
    bool arg1 = false;       /** detach */

    olua_to_object(L, 1, &self, "ccui.TextField");
    olua_check_bool(L, 2, &arg1);

    // void setDetachWithIME(bool detach)
    self->setDetachWithIME(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_TextField_setFontName(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;
    std::string arg1;       /** name */

    olua_to_object(L, 1, &self, "ccui.TextField");
    olua_check_string(L, 2, &arg1);

    // void setFontName(const std::string &name)
    self->setFontName(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_TextField_setFontSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;
    int arg1 = 0;       /** size */

    olua_to_object(L, 1, &self, "ccui.TextField");
    olua_check_integer(L, 2, &arg1);

    // void setFontSize(int size)
    self->setFontSize(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_TextField_setInsertText(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;
    bool arg1 = false;       /** insertText */

    olua_to_object(L, 1, &self, "ccui.TextField");
    olua_check_bool(L, 2, &arg1);

    // void setInsertText(bool insertText)
    self->setInsertText(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_TextField_setMaxLength(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;
    int arg1 = 0;       /** length */

    olua_to_object(L, 1, &self, "ccui.TextField");
    olua_check_integer(L, 2, &arg1);

    // void setMaxLength(int length)
    self->setMaxLength(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_TextField_setMaxLengthEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;
    bool arg1 = false;       /** enable */

    olua_to_object(L, 1, &self, "ccui.TextField");
    olua_check_bool(L, 2, &arg1);

    // void setMaxLengthEnabled(bool enable)
    self->setMaxLengthEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_TextField_setPasswordEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;
    bool arg1 = false;       /** enable */

    olua_to_object(L, 1, &self, "ccui.TextField");
    olua_check_bool(L, 2, &arg1);

    // void setPasswordEnabled(bool enable)
    self->setPasswordEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_TextField_setPasswordStyleText(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;
    const char *arg1 = nullptr;       /** styleText */

    olua_to_object(L, 1, &self, "ccui.TextField");
    olua_check_string(L, 2, &arg1);

    // void setPasswordStyleText(const char *styleText)
    self->setPasswordStyleText(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_TextField_setPlaceHolder(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;
    std::string arg1;       /** value */

    olua_to_object(L, 1, &self, "ccui.TextField");
    olua_check_string(L, 2, &arg1);

    // void setPlaceHolder(const std::string &value)
    self->setPlaceHolder(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_TextField_setPlaceHolderColor$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;
    cocos2d::Color3B arg1;       /** color */

    olua_to_object(L, 1, &self, "ccui.TextField");
    olua_check_cocos2d_Color3B(L, 2, &arg1);

    // void setPlaceHolderColor(const cocos2d::Color3B &color)
    self->setPlaceHolderColor(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_TextField_setPlaceHolderColor$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;
    cocos2d::Color4B arg1;       /** color */

    olua_to_object(L, 1, &self, "ccui.TextField");
    olua_check_cocos2d_Color4B(L, 2, &arg1);

    // void setPlaceHolderColor(const cocos2d::Color4B &color)
    self->setPlaceHolderColor(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_TextField_setPlaceHolderColor(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        if ((olua_is_object(L, 1, "ccui.TextField")) && (olua_is_cocos2d_Color3B(L, 2))) {
            // void setPlaceHolderColor(const cocos2d::Color3B &color)
            return _olua_fun_cocos2d_ui_TextField_setPlaceHolderColor$1(L);
        }

        // if ((olua_is_object(L, 1, "ccui.TextField")) && (olua_is_cocos2d_Color4B(L, 2))) {
            // void setPlaceHolderColor(const cocos2d::Color4B &color)
            return _olua_fun_cocos2d_ui_TextField_setPlaceHolderColor$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::TextField::setPlaceHolderColor' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_TextField_setString(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;
    std::string arg1;       /** text */

    olua_to_object(L, 1, &self, "ccui.TextField");
    olua_check_string(L, 2, &arg1);

    // void setString(const std::string &text)
    self->setString(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_TextField_setTextAreaSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;
    cocos2d::Size *arg1;       /** size */

    olua_to_object(L, 1, &self, "ccui.TextField");
    olua_check_object(L, 2, &arg1, "cc.Size");

    // void setTextAreaSize(const cocos2d::Size &size)
    self->setTextAreaSize(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_TextField_setTextColor(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;
    cocos2d::Color4B arg1;       /** textColor */

    olua_to_object(L, 1, &self, "ccui.TextField");
    olua_check_cocos2d_Color4B(L, 2, &arg1);

    // void setTextColor(const cocos2d::Color4B &textColor)
    self->setTextColor(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_TextField_setTextHorizontalAlignment(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;
    cocos2d::TextHAlignment arg1 = (cocos2d::TextHAlignment)0;       /** alignment */

    olua_to_object(L, 1, &self, "ccui.TextField");
    olua_check_enum(L, 2, &arg1);

    // void setTextHorizontalAlignment(cocos2d::TextHAlignment alignment)
    self->setTextHorizontalAlignment(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_TextField_setTextVerticalAlignment(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;
    cocos2d::TextVAlignment arg1 = (cocos2d::TextVAlignment)0;       /** alignment */

    olua_to_object(L, 1, &self, "ccui.TextField");
    olua_check_enum(L, 2, &arg1);

    // void setTextVerticalAlignment(cocos2d::TextVAlignment alignment)
    self->setTextVerticalAlignment(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_TextField_setTouchAreaEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;
    bool arg1 = false;       /** enable */

    olua_to_object(L, 1, &self, "ccui.TextField");
    olua_check_bool(L, 2, &arg1);

    // void setTouchAreaEnabled(bool enable)
    self->setTouchAreaEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_TextField_setTouchSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;
    cocos2d::Size *arg1;       /** size */

    olua_to_object(L, 1, &self, "ccui.TextField");
    olua_check_object(L, 2, &arg1, "cc.Size");

    // void setTouchSize(const cocos2d::Size &size)
    self->setTouchSize(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_cls_ccui_TextField(lua_State *L)
{
    oluacls_class<cocos2d::ui::TextField, cocos2d::ui::Widget>(L, "ccui.TextField");
    oluacls_func(L, "addEventListener", _olua_fun_cocos2d_ui_TextField_addEventListener);
    oluacls_func(L, "attachWithIME", _olua_fun_cocos2d_ui_TextField_attachWithIME);
    oluacls_func(L, "create", _olua_fun_cocos2d_ui_TextField_create);
    oluacls_func(L, "createInstance", _olua_fun_cocos2d_ui_TextField_createInstance);
    oluacls_func(L, "didNotSelectSelf", _olua_fun_cocos2d_ui_TextField_didNotSelectSelf);
    oluacls_func(L, "getAttachWithIME", _olua_fun_cocos2d_ui_TextField_getAttachWithIME);
    oluacls_func(L, "getAutoRenderSize", _olua_fun_cocos2d_ui_TextField_getAutoRenderSize);
    oluacls_func(L, "getDeleteBackward", _olua_fun_cocos2d_ui_TextField_getDeleteBackward);
    oluacls_func(L, "getDetachWithIME", _olua_fun_cocos2d_ui_TextField_getDetachWithIME);
    oluacls_func(L, "getFontName", _olua_fun_cocos2d_ui_TextField_getFontName);
    oluacls_func(L, "getFontSize", _olua_fun_cocos2d_ui_TextField_getFontSize);
    oluacls_func(L, "getInsertText", _olua_fun_cocos2d_ui_TextField_getInsertText);
    oluacls_func(L, "getMaxLength", _olua_fun_cocos2d_ui_TextField_getMaxLength);
    oluacls_func(L, "getPasswordStyleText", _olua_fun_cocos2d_ui_TextField_getPasswordStyleText);
    oluacls_func(L, "getPlaceHolder", _olua_fun_cocos2d_ui_TextField_getPlaceHolder);
    oluacls_func(L, "getPlaceHolderColor", _olua_fun_cocos2d_ui_TextField_getPlaceHolderColor);
    oluacls_func(L, "getString", _olua_fun_cocos2d_ui_TextField_getString);
    oluacls_func(L, "getStringLength", _olua_fun_cocos2d_ui_TextField_getStringLength);
    oluacls_func(L, "getTextColor", _olua_fun_cocos2d_ui_TextField_getTextColor);
    oluacls_func(L, "getTextHorizontalAlignment", _olua_fun_cocos2d_ui_TextField_getTextHorizontalAlignment);
    oluacls_func(L, "getTextVerticalAlignment", _olua_fun_cocos2d_ui_TextField_getTextVerticalAlignment);
    oluacls_func(L, "getTouchSize", _olua_fun_cocos2d_ui_TextField_getTouchSize);
    oluacls_func(L, "isMaxLengthEnabled", _olua_fun_cocos2d_ui_TextField_isMaxLengthEnabled);
    oluacls_func(L, "isPasswordEnabled", _olua_fun_cocos2d_ui_TextField_isPasswordEnabled);
    oluacls_func(L, "new", _olua_fun_cocos2d_ui_TextField_new);
    oluacls_func(L, "setAttachWithIME", _olua_fun_cocos2d_ui_TextField_setAttachWithIME);
    oluacls_func(L, "setCursorChar", _olua_fun_cocos2d_ui_TextField_setCursorChar);
    oluacls_func(L, "setCursorEnabled", _olua_fun_cocos2d_ui_TextField_setCursorEnabled);
    oluacls_func(L, "setCursorFromPoint", _olua_fun_cocos2d_ui_TextField_setCursorFromPoint);
    oluacls_func(L, "setCursorPosition", _olua_fun_cocos2d_ui_TextField_setCursorPosition);
    oluacls_func(L, "setDeleteBackward", _olua_fun_cocos2d_ui_TextField_setDeleteBackward);
    oluacls_func(L, "setDetachWithIME", _olua_fun_cocos2d_ui_TextField_setDetachWithIME);
    oluacls_func(L, "setFontName", _olua_fun_cocos2d_ui_TextField_setFontName);
    oluacls_func(L, "setFontSize", _olua_fun_cocos2d_ui_TextField_setFontSize);
    oluacls_func(L, "setInsertText", _olua_fun_cocos2d_ui_TextField_setInsertText);
    oluacls_func(L, "setMaxLength", _olua_fun_cocos2d_ui_TextField_setMaxLength);
    oluacls_func(L, "setMaxLengthEnabled", _olua_fun_cocos2d_ui_TextField_setMaxLengthEnabled);
    oluacls_func(L, "setPasswordEnabled", _olua_fun_cocos2d_ui_TextField_setPasswordEnabled);
    oluacls_func(L, "setPasswordStyleText", _olua_fun_cocos2d_ui_TextField_setPasswordStyleText);
    oluacls_func(L, "setPlaceHolder", _olua_fun_cocos2d_ui_TextField_setPlaceHolder);
    oluacls_func(L, "setPlaceHolderColor", _olua_fun_cocos2d_ui_TextField_setPlaceHolderColor);
    oluacls_func(L, "setString", _olua_fun_cocos2d_ui_TextField_setString);
    oluacls_func(L, "setTextAreaSize", _olua_fun_cocos2d_ui_TextField_setTextAreaSize);
    oluacls_func(L, "setTextColor", _olua_fun_cocos2d_ui_TextField_setTextColor);
    oluacls_func(L, "setTextHorizontalAlignment", _olua_fun_cocos2d_ui_TextField_setTextHorizontalAlignment);
    oluacls_func(L, "setTextVerticalAlignment", _olua_fun_cocos2d_ui_TextField_setTextVerticalAlignment);
    oluacls_func(L, "setTouchAreaEnabled", _olua_fun_cocos2d_ui_TextField_setTouchAreaEnabled);
    oluacls_func(L, "setTouchSize", _olua_fun_cocos2d_ui_TextField_setTouchSize);
    oluacls_prop(L, "autoRenderSize", _olua_fun_cocos2d_ui_TextField_getAutoRenderSize, nullptr);
    oluacls_prop(L, "deleteBackward", _olua_fun_cocos2d_ui_TextField_getDeleteBackward, _olua_fun_cocos2d_ui_TextField_setDeleteBackward);
    oluacls_prop(L, "detachWithIME", _olua_fun_cocos2d_ui_TextField_getDetachWithIME, _olua_fun_cocos2d_ui_TextField_setDetachWithIME);
    oluacls_prop(L, "fontName", _olua_fun_cocos2d_ui_TextField_getFontName, _olua_fun_cocos2d_ui_TextField_setFontName);
    oluacls_prop(L, "fontSize", _olua_fun_cocos2d_ui_TextField_getFontSize, _olua_fun_cocos2d_ui_TextField_setFontSize);
    oluacls_prop(L, "insertText", _olua_fun_cocos2d_ui_TextField_getInsertText, _olua_fun_cocos2d_ui_TextField_setInsertText);
    oluacls_prop(L, "maxLength", _olua_fun_cocos2d_ui_TextField_getMaxLength, _olua_fun_cocos2d_ui_TextField_setMaxLength);
    oluacls_prop(L, "maxLengthEnabled", _olua_fun_cocos2d_ui_TextField_isMaxLengthEnabled, _olua_fun_cocos2d_ui_TextField_setMaxLengthEnabled);
    oluacls_prop(L, "passwordEnabled", _olua_fun_cocos2d_ui_TextField_isPasswordEnabled, _olua_fun_cocos2d_ui_TextField_setPasswordEnabled);
    oluacls_prop(L, "passwordStyleText", _olua_fun_cocos2d_ui_TextField_getPasswordStyleText, _olua_fun_cocos2d_ui_TextField_setPasswordStyleText);
    oluacls_prop(L, "placeHolder", _olua_fun_cocos2d_ui_TextField_getPlaceHolder, _olua_fun_cocos2d_ui_TextField_setPlaceHolder);
    oluacls_prop(L, "placeHolderColor", _olua_fun_cocos2d_ui_TextField_getPlaceHolderColor, nullptr);
    oluacls_prop(L, "string", _olua_fun_cocos2d_ui_TextField_getString, _olua_fun_cocos2d_ui_TextField_setString);
    oluacls_prop(L, "stringLength", _olua_fun_cocos2d_ui_TextField_getStringLength, nullptr);
    oluacls_prop(L, "textColor", _olua_fun_cocos2d_ui_TextField_getTextColor, _olua_fun_cocos2d_ui_TextField_setTextColor);
    oluacls_prop(L, "textHorizontalAlignment", _olua_fun_cocos2d_ui_TextField_getTextHorizontalAlignment, _olua_fun_cocos2d_ui_TextField_setTextHorizontalAlignment);
    oluacls_prop(L, "textVerticalAlignment", _olua_fun_cocos2d_ui_TextField_getTextVerticalAlignment, _olua_fun_cocos2d_ui_TextField_setTextVerticalAlignment);
    oluacls_prop(L, "touchSize", _olua_fun_cocos2d_ui_TextField_getTouchSize, _olua_fun_cocos2d_ui_TextField_setTouchSize);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_TextField(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.TextField")) {
        luaL_error(L, "class not found: cocos2d::ui::TextField");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_ui_Button_create$1(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::ui::Button *create()
    cocos2d::ui::Button *ret = cocos2d::ui::Button::create();
    int num_ret = olua_push_object(L, ret, "ccui.Button");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Button_create$2(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** normalImage */
    std::string arg2;       /** selectedImage */
    std::string arg3;       /** disableImage */
    cocos2d::ui::Widget::TextureResType arg4 = (cocos2d::ui::Widget::TextureResType)0;       /** texType */

    olua_check_string(L, 1, &arg1);
    olua_check_string(L, 2, &arg2);
    olua_check_string(L, 3, &arg3);
    olua_check_enum(L, 4, &arg4);

    // static cocos2d::ui::Button *create(const std::string &normalImage, @optional const std::string &selectedImage, @optional const std::string &disableImage, @optional cocos2d::ui::Widget::TextureResType texType)
    cocos2d::ui::Button *ret = cocos2d::ui::Button::create(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_object(L, ret, "ccui.Button");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Button_create$3(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** normalImage */

    olua_check_string(L, 1, &arg1);

    // static cocos2d::ui::Button *create(const std::string &normalImage)
    cocos2d::ui::Button *ret = cocos2d::ui::Button::create(arg1);
    int num_ret = olua_push_object(L, ret, "ccui.Button");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Button_create$4(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** normalImage */
    std::string arg2;       /** selectedImage */

    olua_check_string(L, 1, &arg1);
    olua_check_string(L, 2, &arg2);

    // static cocos2d::ui::Button *create(const std::string &normalImage, @optional const std::string &selectedImage)
    cocos2d::ui::Button *ret = cocos2d::ui::Button::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "ccui.Button");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Button_create$5(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** normalImage */
    std::string arg2;       /** selectedImage */
    std::string arg3;       /** disableImage */

    olua_check_string(L, 1, &arg1);
    olua_check_string(L, 2, &arg2);
    olua_check_string(L, 3, &arg3);

    // static cocos2d::ui::Button *create(const std::string &normalImage, @optional const std::string &selectedImage, @optional const std::string &disableImage)
    cocos2d::ui::Button *ret = cocos2d::ui::Button::create(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "ccui.Button");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Button_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // static cocos2d::ui::Button *create()
        return _olua_fun_cocos2d_ui_Button_create$1(L);
    }

    if (num_args == 1) {
        // if ((olua_is_string(L, 1))) {
            // static cocos2d::ui::Button *create(const std::string &normalImage)
            return _olua_fun_cocos2d_ui_Button_create$3(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_string(L, 1)) && (olua_is_string(L, 2))) {
            // static cocos2d::ui::Button *create(const std::string &normalImage, @optional const std::string &selectedImage)
            return _olua_fun_cocos2d_ui_Button_create$4(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_string(L, 1)) && (olua_is_string(L, 2)) && (olua_is_string(L, 3))) {
            // static cocos2d::ui::Button *create(const std::string &normalImage, @optional const std::string &selectedImage, @optional const std::string &disableImage)
            return _olua_fun_cocos2d_ui_Button_create$5(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_string(L, 1)) && (olua_is_string(L, 2)) && (olua_is_string(L, 3)) && (olua_is_enum(L, 4))) {
            // static cocos2d::ui::Button *create(const std::string &normalImage, @optional const std::string &selectedImage, @optional const std::string &disableImage, @optional cocos2d::ui::Widget::TextureResType texType)
            return _olua_fun_cocos2d_ui_Button_create$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::Button::create' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_Button_createInstance(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::Ref *createInstance()
    cocos2d::Ref *ret = cocos2d::ui::Button::createInstance();
    int num_ret = olua_push_object(L, ret, "cc.Ref");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Button_getCapInsetsDisabledRenderer(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Button");

    // const cocos2d::Rect &getCapInsetsDisabledRenderer()
    const cocos2d::Rect &ret = self->getCapInsetsDisabledRenderer();
    int num_ret = olua_push_object(L, ret, "cc.Rect");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Button_getCapInsetsNormalRenderer(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Button");

    // const cocos2d::Rect &getCapInsetsNormalRenderer()
    const cocos2d::Rect &ret = self->getCapInsetsNormalRenderer();
    int num_ret = olua_push_object(L, ret, "cc.Rect");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Button_getCapInsetsPressedRenderer(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Button");

    // const cocos2d::Rect &getCapInsetsPressedRenderer()
    const cocos2d::Rect &ret = self->getCapInsetsPressedRenderer();
    int num_ret = olua_push_object(L, ret, "cc.Rect");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Button_getDisabledFile(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Button");

    // cocos2d::ResourceData getDisabledFile()
    cocos2d::ResourceData ret = self->getDisabledFile();
    int num_ret = olua_copy_object(L, ret, "cc.ResourceData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Button_getNormalFile(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Button");

    // cocos2d::ResourceData getNormalFile()
    cocos2d::ResourceData ret = self->getNormalFile();
    int num_ret = olua_copy_object(L, ret, "cc.ResourceData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Button_getNormalTextureSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Button");

    // cocos2d::Size getNormalTextureSize()
    cocos2d::Size ret = self->getNormalTextureSize();
    int num_ret = olua_copy_object(L, ret, "cc.Size");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Button_getPressedFile(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Button");

    // cocos2d::ResourceData getPressedFile()
    cocos2d::ResourceData ret = self->getPressedFile();
    int num_ret = olua_copy_object(L, ret, "cc.ResourceData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Button_getRendererClicked(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Button");

    // @addref(protectedChildren |) cocos2d::ui::Scale9Sprite *getRendererClicked()
    cocos2d::ui::Scale9Sprite *ret = self->getRendererClicked();
    int num_ret = olua_push_object(L, ret, "ccui.Scale9Sprite");

    // insert code after call
    olua_addref(L, 1, "protectedChildren", -1, OLUA_REF_MULTI);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Button_getRendererDisabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Button");

    // @addref(protectedChildren |) cocos2d::ui::Scale9Sprite *getRendererDisabled()
    cocos2d::ui::Scale9Sprite *ret = self->getRendererDisabled();
    int num_ret = olua_push_object(L, ret, "ccui.Scale9Sprite");

    // insert code after call
    olua_addref(L, 1, "protectedChildren", -1, OLUA_REF_MULTI);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Button_getRendererNormal(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Button");

    // @addref(protectedChildren |) cocos2d::ui::Scale9Sprite *getRendererNormal()
    cocos2d::ui::Scale9Sprite *ret = self->getRendererNormal();
    int num_ret = olua_push_object(L, ret, "ccui.Scale9Sprite");

    // insert code after call
    olua_addref(L, 1, "protectedChildren", -1, OLUA_REF_MULTI);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Button_getTitleColor(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Button");

    // cocos2d::Color3B getTitleColor()
    cocos2d::Color3B ret = self->getTitleColor();
    int num_ret = olua_push_cocos2d_Color3B(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Button_getTitleFontName(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Button");

    // std::string getTitleFontName()
    std::string ret = self->getTitleFontName();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Button_getTitleFontSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Button");

    // float getTitleFontSize()
    float ret = self->getTitleFontSize();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Button_getTitleLabel(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Button");

    // @addref(protectedChildren |) cocos2d::Label *getTitleLabel()
    cocos2d::Label *ret = self->getTitleLabel();
    int num_ret = olua_push_object(L, ret, "cc.Label");

    // insert code after call
    olua_addref(L, 1, "protectedChildren", -1, OLUA_REF_MULTI);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Button_getTitleRenderer(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Button");

    // @addref(protectedChildren |) cocos2d::Label *getTitleRenderer()
    cocos2d::Label *ret = self->getTitleRenderer();
    int num_ret = olua_push_object(L, ret, "cc.Label");

    // insert code after call
    olua_addref(L, 1, "protectedChildren", -1, OLUA_REF_MULTI);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Button_getTitleText(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Button");

    // std::string getTitleText()
    std::string ret = self->getTitleText();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Button_getZoomScale(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Button");

    // float getZoomScale()
    float ret = self->getZoomScale();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Button_init$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Button");

    // @using bool init()
    bool ret = self->init();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Button_init$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;
    std::string arg1;       /** normalImage */
    std::string arg2;       /** selectedImage */
    std::string arg3;       /** disableImage */
    cocos2d::ui::Widget::TextureResType arg4 = (cocos2d::ui::Widget::TextureResType)0;       /** texType */

    olua_to_object(L, 1, &self, "ccui.Button");
    olua_check_string(L, 2, &arg1);
    olua_check_string(L, 3, &arg2);
    olua_check_string(L, 4, &arg3);
    olua_check_enum(L, 5, &arg4);

    // bool init(const std::string &normalImage, @optional const std::string &selectedImage, @optional const std::string &disableImage, @optional cocos2d::ui::Widget::TextureResType texType)
    bool ret = self->init(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Button_init$3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;
    std::string arg1;       /** normalImage */

    olua_to_object(L, 1, &self, "ccui.Button");
    olua_check_string(L, 2, &arg1);

    // bool init(const std::string &normalImage)
    bool ret = self->init(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Button_init$4(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;
    std::string arg1;       /** normalImage */
    std::string arg2;       /** selectedImage */

    olua_to_object(L, 1, &self, "ccui.Button");
    olua_check_string(L, 2, &arg1);
    olua_check_string(L, 3, &arg2);

    // bool init(const std::string &normalImage, @optional const std::string &selectedImage)
    bool ret = self->init(arg1, arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Button_init$5(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;
    std::string arg1;       /** normalImage */
    std::string arg2;       /** selectedImage */
    std::string arg3;       /** disableImage */

    olua_to_object(L, 1, &self, "ccui.Button");
    olua_check_string(L, 2, &arg1);
    olua_check_string(L, 3, &arg2);
    olua_check_string(L, 4, &arg3);

    // bool init(const std::string &normalImage, @optional const std::string &selectedImage, @optional const std::string &disableImage)
    bool ret = self->init(arg1, arg2, arg3);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Button_init(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // @using bool init()
        return _olua_fun_cocos2d_ui_Button_init$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccui.Button")) && (olua_is_string(L, 2))) {
            // bool init(const std::string &normalImage)
            return _olua_fun_cocos2d_ui_Button_init$3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "ccui.Button")) && (olua_is_string(L, 2)) && (olua_is_string(L, 3))) {
            // bool init(const std::string &normalImage, @optional const std::string &selectedImage)
            return _olua_fun_cocos2d_ui_Button_init$4(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_object(L, 1, "ccui.Button")) && (olua_is_string(L, 2)) && (olua_is_string(L, 3)) && (olua_is_string(L, 4))) {
            // bool init(const std::string &normalImage, @optional const std::string &selectedImage, @optional const std::string &disableImage)
            return _olua_fun_cocos2d_ui_Button_init$5(L);
        // }
    }

    if (num_args == 5) {
        // if ((olua_is_object(L, 1, "ccui.Button")) && (olua_is_string(L, 2)) && (olua_is_string(L, 3)) && (olua_is_string(L, 4)) && (olua_is_enum(L, 5))) {
            // bool init(const std::string &normalImage, @optional const std::string &selectedImage, @optional const std::string &disableImage, @optional cocos2d::ui::Widget::TextureResType texType)
            return _olua_fun_cocos2d_ui_Button_init$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::Button::init' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_Button_isScale9Enabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Button");

    // bool isScale9Enabled()
    bool ret = self->isScale9Enabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Button_loadTextureDisabled$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;
    std::string arg1;       /** disabled */
    cocos2d::ui::Widget::TextureResType arg2 = (cocos2d::ui::Widget::TextureResType)0;       /** texType */

    olua_to_object(L, 1, &self, "ccui.Button");
    olua_check_string(L, 2, &arg1);
    olua_check_enum(L, 3, &arg2);

    // void loadTextureDisabled(const std::string &disabled, @optional cocos2d::ui::Widget::TextureResType texType)
    self->loadTextureDisabled(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Button_loadTextureDisabled$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;
    std::string arg1;       /** disabled */

    olua_to_object(L, 1, &self, "ccui.Button");
    olua_check_string(L, 2, &arg1);

    // void loadTextureDisabled(const std::string &disabled)
    self->loadTextureDisabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Button_loadTextureDisabled(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccui.Button")) && (olua_is_string(L, 2))) {
            // void loadTextureDisabled(const std::string &disabled)
            return _olua_fun_cocos2d_ui_Button_loadTextureDisabled$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "ccui.Button")) && (olua_is_string(L, 2)) && (olua_is_enum(L, 3))) {
            // void loadTextureDisabled(const std::string &disabled, @optional cocos2d::ui::Widget::TextureResType texType)
            return _olua_fun_cocos2d_ui_Button_loadTextureDisabled$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::Button::loadTextureDisabled' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_Button_loadTextureNormal$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;
    std::string arg1;       /** normal */
    cocos2d::ui::Widget::TextureResType arg2 = (cocos2d::ui::Widget::TextureResType)0;       /** texType */

    olua_to_object(L, 1, &self, "ccui.Button");
    olua_check_string(L, 2, &arg1);
    olua_check_enum(L, 3, &arg2);

    // void loadTextureNormal(const std::string &normal, @optional cocos2d::ui::Widget::TextureResType texType)
    self->loadTextureNormal(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Button_loadTextureNormal$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;
    std::string arg1;       /** normal */

    olua_to_object(L, 1, &self, "ccui.Button");
    olua_check_string(L, 2, &arg1);

    // void loadTextureNormal(const std::string &normal)
    self->loadTextureNormal(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Button_loadTextureNormal(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccui.Button")) && (olua_is_string(L, 2))) {
            // void loadTextureNormal(const std::string &normal)
            return _olua_fun_cocos2d_ui_Button_loadTextureNormal$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "ccui.Button")) && (olua_is_string(L, 2)) && (olua_is_enum(L, 3))) {
            // void loadTextureNormal(const std::string &normal, @optional cocos2d::ui::Widget::TextureResType texType)
            return _olua_fun_cocos2d_ui_Button_loadTextureNormal$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::Button::loadTextureNormal' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_Button_loadTexturePressed$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;
    std::string arg1;       /** selected */
    cocos2d::ui::Widget::TextureResType arg2 = (cocos2d::ui::Widget::TextureResType)0;       /** texType */

    olua_to_object(L, 1, &self, "ccui.Button");
    olua_check_string(L, 2, &arg1);
    olua_check_enum(L, 3, &arg2);

    // void loadTexturePressed(const std::string &selected, @optional cocos2d::ui::Widget::TextureResType texType)
    self->loadTexturePressed(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Button_loadTexturePressed$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;
    std::string arg1;       /** selected */

    olua_to_object(L, 1, &self, "ccui.Button");
    olua_check_string(L, 2, &arg1);

    // void loadTexturePressed(const std::string &selected)
    self->loadTexturePressed(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Button_loadTexturePressed(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccui.Button")) && (olua_is_string(L, 2))) {
            // void loadTexturePressed(const std::string &selected)
            return _olua_fun_cocos2d_ui_Button_loadTexturePressed$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "ccui.Button")) && (olua_is_string(L, 2)) && (olua_is_enum(L, 3))) {
            // void loadTexturePressed(const std::string &selected, @optional cocos2d::ui::Widget::TextureResType texType)
            return _olua_fun_cocos2d_ui_Button_loadTexturePressed$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::Button::loadTexturePressed' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_Button_loadTextures$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;
    std::string arg1;       /** normal */
    std::string arg2;       /** selected */
    std::string arg3;       /** disabled */
    cocos2d::ui::Widget::TextureResType arg4 = (cocos2d::ui::Widget::TextureResType)0;       /** texType */

    olua_to_object(L, 1, &self, "ccui.Button");
    olua_check_string(L, 2, &arg1);
    olua_check_string(L, 3, &arg2);
    olua_check_string(L, 4, &arg3);
    olua_check_enum(L, 5, &arg4);

    // void loadTextures(const std::string &normal, const std::string &selected, @optional const std::string &disabled, @optional cocos2d::ui::Widget::TextureResType texType)
    self->loadTextures(arg1, arg2, arg3, arg4);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Button_loadTextures$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;
    std::string arg1;       /** normal */
    std::string arg2;       /** selected */

    olua_to_object(L, 1, &self, "ccui.Button");
    olua_check_string(L, 2, &arg1);
    olua_check_string(L, 3, &arg2);

    // void loadTextures(const std::string &normal, const std::string &selected)
    self->loadTextures(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Button_loadTextures$3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;
    std::string arg1;       /** normal */
    std::string arg2;       /** selected */
    std::string arg3;       /** disabled */

    olua_to_object(L, 1, &self, "ccui.Button");
    olua_check_string(L, 2, &arg1);
    olua_check_string(L, 3, &arg2);
    olua_check_string(L, 4, &arg3);

    // void loadTextures(const std::string &normal, const std::string &selected, @optional const std::string &disabled)
    self->loadTextures(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Button_loadTextures(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "ccui.Button")) && (olua_is_string(L, 2)) && (olua_is_string(L, 3))) {
            // void loadTextures(const std::string &normal, const std::string &selected)
            return _olua_fun_cocos2d_ui_Button_loadTextures$2(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_object(L, 1, "ccui.Button")) && (olua_is_string(L, 2)) && (olua_is_string(L, 3)) && (olua_is_string(L, 4))) {
            // void loadTextures(const std::string &normal, const std::string &selected, @optional const std::string &disabled)
            return _olua_fun_cocos2d_ui_Button_loadTextures$3(L);
        // }
    }

    if (num_args == 5) {
        // if ((olua_is_object(L, 1, "ccui.Button")) && (olua_is_string(L, 2)) && (olua_is_string(L, 3)) && (olua_is_string(L, 4)) && (olua_is_enum(L, 5))) {
            // void loadTextures(const std::string &normal, const std::string &selected, @optional const std::string &disabled, @optional cocos2d::ui::Widget::TextureResType texType)
            return _olua_fun_cocos2d_ui_Button_loadTextures$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::Button::loadTextures' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_Button_new(lua_State *L)
{
    olua_startinvoke(L);

    // cocos2d::ui::Button()
    cocos2d::ui::Button *ret = new cocos2d::ui::Button();
    int num_ret = olua_push_object(L, ret, "ccui.Button");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Button_resetDisabledRender(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Button");

    // void resetDisabledRender()
    self->resetDisabledRender();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Button_resetNormalRender(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Button");

    // void resetNormalRender()
    self->resetNormalRender();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Button_resetPressedRender(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.Button");

    // void resetPressedRender()
    self->resetPressedRender();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Button_setCapInsets(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;
    cocos2d::Rect *arg1;       /** capInsets */

    olua_to_object(L, 1, &self, "ccui.Button");
    olua_check_object(L, 2, &arg1, "cc.Rect");

    // void setCapInsets(const cocos2d::Rect &capInsets)
    self->setCapInsets(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Button_setCapInsetsDisabledRenderer(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;
    cocos2d::Rect *arg1;       /** capInsets */

    olua_to_object(L, 1, &self, "ccui.Button");
    olua_check_object(L, 2, &arg1, "cc.Rect");

    // void setCapInsetsDisabledRenderer(const cocos2d::Rect &capInsets)
    self->setCapInsetsDisabledRenderer(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Button_setCapInsetsNormalRenderer(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;
    cocos2d::Rect *arg1;       /** capInsets */

    olua_to_object(L, 1, &self, "ccui.Button");
    olua_check_object(L, 2, &arg1, "cc.Rect");

    // void setCapInsetsNormalRenderer(const cocos2d::Rect &capInsets)
    self->setCapInsetsNormalRenderer(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Button_setCapInsetsPressedRenderer(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;
    cocos2d::Rect *arg1;       /** capInsets */

    olua_to_object(L, 1, &self, "ccui.Button");
    olua_check_object(L, 2, &arg1, "cc.Rect");

    // void setCapInsetsPressedRenderer(const cocos2d::Rect &capInsets)
    self->setCapInsetsPressedRenderer(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Button_setPressedActionEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;
    bool arg1 = false;       /** enabled */

    olua_to_object(L, 1, &self, "ccui.Button");
    olua_check_bool(L, 2, &arg1);

    // void setPressedActionEnabled(bool enabled)
    self->setPressedActionEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Button_setScale9Enabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;
    bool arg1 = false;       /** enable */

    olua_to_object(L, 1, &self, "ccui.Button");
    olua_check_bool(L, 2, &arg1);

    // void setScale9Enabled(bool enable)
    self->setScale9Enabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Button_setTitleAlignment$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;
    cocos2d::TextHAlignment arg1 = (cocos2d::TextHAlignment)0;       /** hAlignment */

    olua_to_object(L, 1, &self, "ccui.Button");
    olua_check_enum(L, 2, &arg1);

    // void setTitleAlignment(cocos2d::TextHAlignment hAlignment)
    self->setTitleAlignment(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Button_setTitleAlignment$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;
    cocos2d::TextHAlignment arg1 = (cocos2d::TextHAlignment)0;       /** hAlignment */
    cocos2d::TextVAlignment arg2 = (cocos2d::TextVAlignment)0;       /** vAlignment */

    olua_to_object(L, 1, &self, "ccui.Button");
    olua_check_enum(L, 2, &arg1);
    olua_check_enum(L, 3, &arg2);

    // void setTitleAlignment(cocos2d::TextHAlignment hAlignment, cocos2d::TextVAlignment vAlignment)
    self->setTitleAlignment(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Button_setTitleAlignment(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccui.Button")) && (olua_is_enum(L, 2))) {
            // void setTitleAlignment(cocos2d::TextHAlignment hAlignment)
            return _olua_fun_cocos2d_ui_Button_setTitleAlignment$1(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "ccui.Button")) && (olua_is_enum(L, 2)) && (olua_is_enum(L, 3))) {
            // void setTitleAlignment(cocos2d::TextHAlignment hAlignment, cocos2d::TextVAlignment vAlignment)
            return _olua_fun_cocos2d_ui_Button_setTitleAlignment$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::Button::setTitleAlignment' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_Button_setTitleColor(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;
    cocos2d::Color3B arg1;       /** color */

    olua_to_object(L, 1, &self, "ccui.Button");
    olua_check_cocos2d_Color3B(L, 2, &arg1);

    // void setTitleColor(const cocos2d::Color3B &color)
    self->setTitleColor(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Button_setTitleFontName(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;
    std::string arg1;       /** fontName */

    olua_to_object(L, 1, &self, "ccui.Button");
    olua_check_string(L, 2, &arg1);

    // void setTitleFontName(const std::string &fontName)
    self->setTitleFontName(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Button_setTitleFontSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;
    float arg1 = 0;       /** size */

    olua_to_object(L, 1, &self, "ccui.Button");
    olua_check_number(L, 2, &arg1);

    // void setTitleFontSize(float size)
    self->setTitleFontSize(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Button_setTitleLabel(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;
    cocos2d::Label *arg1 = nullptr;       /** label */

    olua_to_object(L, 1, &self, "ccui.Button");
    olua_check_object(L, 2, &arg1, "cc.Label");

    // void setTitleLabel(@addref(protectedChildren |) cocos2d::Label *label)
    self->setTitleLabel(arg1);

    // insert code after call
    olua_addref(L, 1, "protectedChildren", 2, OLUA_REF_MULTI);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Button_setTitleText(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;
    std::string arg1;       /** text */

    olua_to_object(L, 1, &self, "ccui.Button");
    olua_check_string(L, 2, &arg1);

    // void setTitleText(const std::string &text)
    self->setTitleText(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Button_setZoomScale(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;
    float arg1 = 0;       /** scale */

    olua_to_object(L, 1, &self, "ccui.Button");
    olua_check_number(L, 2, &arg1);

    // void setZoomScale(float scale)
    self->setZoomScale(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_cls_ccui_Button(lua_State *L)
{
    oluacls_class<cocos2d::ui::Button, cocos2d::ui::Widget>(L, "ccui.Button");
    oluacls_func(L, "create", _olua_fun_cocos2d_ui_Button_create);
    oluacls_func(L, "createInstance", _olua_fun_cocos2d_ui_Button_createInstance);
    oluacls_func(L, "getCapInsetsDisabledRenderer", _olua_fun_cocos2d_ui_Button_getCapInsetsDisabledRenderer);
    oluacls_func(L, "getCapInsetsNormalRenderer", _olua_fun_cocos2d_ui_Button_getCapInsetsNormalRenderer);
    oluacls_func(L, "getCapInsetsPressedRenderer", _olua_fun_cocos2d_ui_Button_getCapInsetsPressedRenderer);
    oluacls_func(L, "getDisabledFile", _olua_fun_cocos2d_ui_Button_getDisabledFile);
    oluacls_func(L, "getNormalFile", _olua_fun_cocos2d_ui_Button_getNormalFile);
    oluacls_func(L, "getNormalTextureSize", _olua_fun_cocos2d_ui_Button_getNormalTextureSize);
    oluacls_func(L, "getPressedFile", _olua_fun_cocos2d_ui_Button_getPressedFile);
    oluacls_func(L, "getRendererClicked", _olua_fun_cocos2d_ui_Button_getRendererClicked);
    oluacls_func(L, "getRendererDisabled", _olua_fun_cocos2d_ui_Button_getRendererDisabled);
    oluacls_func(L, "getRendererNormal", _olua_fun_cocos2d_ui_Button_getRendererNormal);
    oluacls_func(L, "getTitleColor", _olua_fun_cocos2d_ui_Button_getTitleColor);
    oluacls_func(L, "getTitleFontName", _olua_fun_cocos2d_ui_Button_getTitleFontName);
    oluacls_func(L, "getTitleFontSize", _olua_fun_cocos2d_ui_Button_getTitleFontSize);
    oluacls_func(L, "getTitleLabel", _olua_fun_cocos2d_ui_Button_getTitleLabel);
    oluacls_func(L, "getTitleRenderer", _olua_fun_cocos2d_ui_Button_getTitleRenderer);
    oluacls_func(L, "getTitleText", _olua_fun_cocos2d_ui_Button_getTitleText);
    oluacls_func(L, "getZoomScale", _olua_fun_cocos2d_ui_Button_getZoomScale);
    oluacls_func(L, "init", _olua_fun_cocos2d_ui_Button_init);
    oluacls_func(L, "isScale9Enabled", _olua_fun_cocos2d_ui_Button_isScale9Enabled);
    oluacls_func(L, "loadTextureDisabled", _olua_fun_cocos2d_ui_Button_loadTextureDisabled);
    oluacls_func(L, "loadTextureNormal", _olua_fun_cocos2d_ui_Button_loadTextureNormal);
    oluacls_func(L, "loadTexturePressed", _olua_fun_cocos2d_ui_Button_loadTexturePressed);
    oluacls_func(L, "loadTextures", _olua_fun_cocos2d_ui_Button_loadTextures);
    oluacls_func(L, "new", _olua_fun_cocos2d_ui_Button_new);
    oluacls_func(L, "resetDisabledRender", _olua_fun_cocos2d_ui_Button_resetDisabledRender);
    oluacls_func(L, "resetNormalRender", _olua_fun_cocos2d_ui_Button_resetNormalRender);
    oluacls_func(L, "resetPressedRender", _olua_fun_cocos2d_ui_Button_resetPressedRender);
    oluacls_func(L, "setCapInsets", _olua_fun_cocos2d_ui_Button_setCapInsets);
    oluacls_func(L, "setCapInsetsDisabledRenderer", _olua_fun_cocos2d_ui_Button_setCapInsetsDisabledRenderer);
    oluacls_func(L, "setCapInsetsNormalRenderer", _olua_fun_cocos2d_ui_Button_setCapInsetsNormalRenderer);
    oluacls_func(L, "setCapInsetsPressedRenderer", _olua_fun_cocos2d_ui_Button_setCapInsetsPressedRenderer);
    oluacls_func(L, "setPressedActionEnabled", _olua_fun_cocos2d_ui_Button_setPressedActionEnabled);
    oluacls_func(L, "setScale9Enabled", _olua_fun_cocos2d_ui_Button_setScale9Enabled);
    oluacls_func(L, "setTitleAlignment", _olua_fun_cocos2d_ui_Button_setTitleAlignment);
    oluacls_func(L, "setTitleColor", _olua_fun_cocos2d_ui_Button_setTitleColor);
    oluacls_func(L, "setTitleFontName", _olua_fun_cocos2d_ui_Button_setTitleFontName);
    oluacls_func(L, "setTitleFontSize", _olua_fun_cocos2d_ui_Button_setTitleFontSize);
    oluacls_func(L, "setTitleLabel", _olua_fun_cocos2d_ui_Button_setTitleLabel);
    oluacls_func(L, "setTitleText", _olua_fun_cocos2d_ui_Button_setTitleText);
    oluacls_func(L, "setZoomScale", _olua_fun_cocos2d_ui_Button_setZoomScale);
    oluacls_prop(L, "capInsetsDisabledRenderer", _olua_fun_cocos2d_ui_Button_getCapInsetsDisabledRenderer, _olua_fun_cocos2d_ui_Button_setCapInsetsDisabledRenderer);
    oluacls_prop(L, "capInsetsNormalRenderer", _olua_fun_cocos2d_ui_Button_getCapInsetsNormalRenderer, _olua_fun_cocos2d_ui_Button_setCapInsetsNormalRenderer);
    oluacls_prop(L, "capInsetsPressedRenderer", _olua_fun_cocos2d_ui_Button_getCapInsetsPressedRenderer, _olua_fun_cocos2d_ui_Button_setCapInsetsPressedRenderer);
    oluacls_prop(L, "disabledFile", _olua_fun_cocos2d_ui_Button_getDisabledFile, nullptr);
    oluacls_prop(L, "normalFile", _olua_fun_cocos2d_ui_Button_getNormalFile, nullptr);
    oluacls_prop(L, "normalTextureSize", _olua_fun_cocos2d_ui_Button_getNormalTextureSize, nullptr);
    oluacls_prop(L, "pressedFile", _olua_fun_cocos2d_ui_Button_getPressedFile, nullptr);
    oluacls_prop(L, "rendererClicked", _olua_fun_cocos2d_ui_Button_getRendererClicked, nullptr);
    oluacls_prop(L, "rendererDisabled", _olua_fun_cocos2d_ui_Button_getRendererDisabled, nullptr);
    oluacls_prop(L, "rendererNormal", _olua_fun_cocos2d_ui_Button_getRendererNormal, nullptr);
    oluacls_prop(L, "scale9Enabled", _olua_fun_cocos2d_ui_Button_isScale9Enabled, _olua_fun_cocos2d_ui_Button_setScale9Enabled);
    oluacls_prop(L, "titleColor", _olua_fun_cocos2d_ui_Button_getTitleColor, _olua_fun_cocos2d_ui_Button_setTitleColor);
    oluacls_prop(L, "titleFontName", _olua_fun_cocos2d_ui_Button_getTitleFontName, _olua_fun_cocos2d_ui_Button_setTitleFontName);
    oluacls_prop(L, "titleFontSize", _olua_fun_cocos2d_ui_Button_getTitleFontSize, _olua_fun_cocos2d_ui_Button_setTitleFontSize);
    oluacls_prop(L, "titleLabel", _olua_fun_cocos2d_ui_Button_getTitleLabel, _olua_fun_cocos2d_ui_Button_setTitleLabel);
    oluacls_prop(L, "titleRenderer", _olua_fun_cocos2d_ui_Button_getTitleRenderer, nullptr);
    oluacls_prop(L, "titleText", _olua_fun_cocos2d_ui_Button_getTitleText, _olua_fun_cocos2d_ui_Button_setTitleText);
    oluacls_prop(L, "zoomScale", _olua_fun_cocos2d_ui_Button_getZoomScale, _olua_fun_cocos2d_ui_Button_setZoomScale);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_Button(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.Button")) {
        luaL_error(L, "class not found: cocos2d::ui::Button");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_ccui_CheckBox_EventType(lua_State *L)
{
    oluacls_class<cocos2d::ui::CheckBox::EventType>(L, "ccui.CheckBox.EventType");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "SELECTED", (lua_Integer)cocos2d::ui::CheckBox::EventType::SELECTED);
    oluacls_enum(L, "UNSELECTED", (lua_Integer)cocos2d::ui::CheckBox::EventType::UNSELECTED);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_CheckBox_EventType(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.CheckBox.EventType")) {
        luaL_error(L, "class not found: cocos2d::ui::CheckBox::EventType");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_ui_CheckBox_ccCheckBoxCallback___call(lua_State *L)
{
    olua_startinvoke(L);

    luaL_checktype(L, -1, LUA_TFUNCTION);
    olua_push_callback(L, (cocos2d::ui::CheckBox::ccCheckBoxCallback *)nullptr, "ccui.CheckBox.ccCheckBoxCallback");

    olua_endinvoke(L);

    return 1;
}

static int _olua_cls_ccui_CheckBox_ccCheckBoxCallback(lua_State *L)
{
    oluacls_class<cocos2d::ui::CheckBox::ccCheckBoxCallback>(L, "ccui.CheckBox.ccCheckBoxCallback");
    oluacls_func(L, "__call", _olua_fun_cocos2d_ui_CheckBox_ccCheckBoxCallback___call);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_CheckBox_ccCheckBoxCallback(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.CheckBox.ccCheckBoxCallback")) {
        luaL_error(L, "class not found: cocos2d::ui::CheckBox::ccCheckBoxCallback");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_ui_CheckBox_addEventListener(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::CheckBox *self = nullptr;
    cocos2d::ui::CheckBox::ccCheckBoxCallback arg1;       /** callback */

    olua_to_object(L, 1, &self, "ccui.CheckBox");
    olua_check_callback(L, 2, &arg1, "ccui.CheckBox.ccCheckBoxCallback");

    void *cb_store = (void *)self;
    std::string cb_tag = "checkBoxCallback";
    std::string cb_name = olua_setcallback(L, cb_store, 2, cb_tag.c_str(), OLUA_TAG_REPLACE);
    olua_Context cb_ctx = olua_context(L);
    // lua_State *ML = olua_mainthread(L);
    arg1 = [cb_store, cb_name, cb_ctx /*, ML */](cocos2d::Ref *cb_arg1, cocos2d::ui::CheckBox::EventType cb_arg2) {
        lua_State *L = olua_mainthread(NULL);
        olua_checkhostthread();

        if (olua_contextequal(L, cb_ctx)) {
            int top = lua_gettop(L);
            olua_push_object(L, cb_arg1, "cc.Ref");
            olua_push_enum(L, cb_arg2);

            olua_callback(L, cb_store, cb_name.c_str(), 2);

            lua_settop(L, top);
        }
    };

    // void addEventListener(const cocos2d::ui::CheckBox::ccCheckBoxCallback &callback)
    self->addEventListener(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_CheckBox_create$1(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::ui::CheckBox *create()
    cocos2d::ui::CheckBox *ret = cocos2d::ui::CheckBox::create();
    int num_ret = olua_push_object(L, ret, "ccui.CheckBox");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_CheckBox_create$2(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** backGround */
    std::string arg2;       /** backGroundSelected */
    std::string arg3;       /** cross */
    std::string arg4;       /** backGroundDisabled */
    std::string arg5;       /** frontCrossDisabled */
    cocos2d::ui::Widget::TextureResType arg6 = (cocos2d::ui::Widget::TextureResType)0;       /** texType */

    olua_check_string(L, 1, &arg1);
    olua_check_string(L, 2, &arg2);
    olua_check_string(L, 3, &arg3);
    olua_check_string(L, 4, &arg4);
    olua_check_string(L, 5, &arg5);
    olua_check_enum(L, 6, &arg6);

    // static cocos2d::ui::CheckBox *create(const std::string &backGround, const std::string &backGroundSelected, const std::string &cross, const std::string &backGroundDisabled, const std::string &frontCrossDisabled, @optional cocos2d::ui::Widget::TextureResType texType)
    cocos2d::ui::CheckBox *ret = cocos2d::ui::CheckBox::create(arg1, arg2, arg3, arg4, arg5, arg6);
    int num_ret = olua_push_object(L, ret, "ccui.CheckBox");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_CheckBox_create$3(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** backGround */
    std::string arg2;       /** backGroundSelected */
    std::string arg3;       /** cross */
    std::string arg4;       /** backGroundDisabled */
    std::string arg5;       /** frontCrossDisabled */

    olua_check_string(L, 1, &arg1);
    olua_check_string(L, 2, &arg2);
    olua_check_string(L, 3, &arg3);
    olua_check_string(L, 4, &arg4);
    olua_check_string(L, 5, &arg5);

    // static cocos2d::ui::CheckBox *create(const std::string &backGround, const std::string &backGroundSelected, const std::string &cross, const std::string &backGroundDisabled, const std::string &frontCrossDisabled)
    cocos2d::ui::CheckBox *ret = cocos2d::ui::CheckBox::create(arg1, arg2, arg3, arg4, arg5);
    int num_ret = olua_push_object(L, ret, "ccui.CheckBox");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_CheckBox_create$4(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** backGround */
    std::string arg2;       /** cross */
    cocos2d::ui::Widget::TextureResType arg3 = (cocos2d::ui::Widget::TextureResType)0;       /** texType */

    olua_check_string(L, 1, &arg1);
    olua_check_string(L, 2, &arg2);
    olua_check_enum(L, 3, &arg3);

    // static cocos2d::ui::CheckBox *create(const std::string &backGround, const std::string &cross, @optional cocos2d::ui::Widget::TextureResType texType)
    cocos2d::ui::CheckBox *ret = cocos2d::ui::CheckBox::create(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "ccui.CheckBox");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_CheckBox_create$5(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** backGround */
    std::string arg2;       /** cross */

    olua_check_string(L, 1, &arg1);
    olua_check_string(L, 2, &arg2);

    // static cocos2d::ui::CheckBox *create(const std::string &backGround, const std::string &cross)
    cocos2d::ui::CheckBox *ret = cocos2d::ui::CheckBox::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "ccui.CheckBox");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_CheckBox_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // static cocos2d::ui::CheckBox *create()
        return _olua_fun_cocos2d_ui_CheckBox_create$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_string(L, 1)) && (olua_is_string(L, 2))) {
            // static cocos2d::ui::CheckBox *create(const std::string &backGround, const std::string &cross)
            return _olua_fun_cocos2d_ui_CheckBox_create$5(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_string(L, 1)) && (olua_is_string(L, 2)) && (olua_is_enum(L, 3))) {
            // static cocos2d::ui::CheckBox *create(const std::string &backGround, const std::string &cross, @optional cocos2d::ui::Widget::TextureResType texType)
            return _olua_fun_cocos2d_ui_CheckBox_create$4(L);
        // }
    }

    if (num_args == 5) {
        // if ((olua_is_string(L, 1)) && (olua_is_string(L, 2)) && (olua_is_string(L, 3)) && (olua_is_string(L, 4)) && (olua_is_string(L, 5))) {
            // static cocos2d::ui::CheckBox *create(const std::string &backGround, const std::string &backGroundSelected, const std::string &cross, const std::string &backGroundDisabled, const std::string &frontCrossDisabled)
            return _olua_fun_cocos2d_ui_CheckBox_create$3(L);
        // }
    }

    if (num_args == 6) {
        // if ((olua_is_string(L, 1)) && (olua_is_string(L, 2)) && (olua_is_string(L, 3)) && (olua_is_string(L, 4)) && (olua_is_string(L, 5)) && (olua_is_enum(L, 6))) {
            // static cocos2d::ui::CheckBox *create(const std::string &backGround, const std::string &backGroundSelected, const std::string &cross, const std::string &backGroundDisabled, const std::string &frontCrossDisabled, @optional cocos2d::ui::Widget::TextureResType texType)
            return _olua_fun_cocos2d_ui_CheckBox_create$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::CheckBox::create' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_CheckBox_createInstance(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::Ref *createInstance()
    cocos2d::Ref *ret = cocos2d::ui::CheckBox::createInstance();
    int num_ret = olua_push_object(L, ret, "cc.Ref");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_CheckBox_new(lua_State *L)
{
    olua_startinvoke(L);

    // cocos2d::ui::CheckBox()
    cocos2d::ui::CheckBox *ret = new cocos2d::ui::CheckBox();
    int num_ret = olua_push_object(L, ret, "ccui.CheckBox");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_cls_ccui_CheckBox(lua_State *L)
{
    oluacls_class<cocos2d::ui::CheckBox, cocos2d::ui::AbstractCheckButton>(L, "ccui.CheckBox");
    oluacls_func(L, "addEventListener", _olua_fun_cocos2d_ui_CheckBox_addEventListener);
    oluacls_func(L, "create", _olua_fun_cocos2d_ui_CheckBox_create);
    oluacls_func(L, "createInstance", _olua_fun_cocos2d_ui_CheckBox_createInstance);
    oluacls_func(L, "new", _olua_fun_cocos2d_ui_CheckBox_new);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_CheckBox(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.CheckBox")) {
        luaL_error(L, "class not found: cocos2d::ui::CheckBox");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_ccui_RadioButton_EventType(lua_State *L)
{
    oluacls_class<cocos2d::ui::RadioButton::EventType>(L, "ccui.RadioButton.EventType");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "SELECTED", (lua_Integer)cocos2d::ui::RadioButton::EventType::SELECTED);
    oluacls_enum(L, "UNSELECTED", (lua_Integer)cocos2d::ui::RadioButton::EventType::UNSELECTED);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_RadioButton_EventType(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.RadioButton.EventType")) {
        luaL_error(L, "class not found: cocos2d::ui::RadioButton::EventType");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_ui_RadioButton_ccRadioButtonCallback___call(lua_State *L)
{
    olua_startinvoke(L);

    luaL_checktype(L, -1, LUA_TFUNCTION);
    olua_push_callback(L, (cocos2d::ui::RadioButton::ccRadioButtonCallback *)nullptr, "ccui.RadioButton.ccRadioButtonCallback");

    olua_endinvoke(L);

    return 1;
}

static int _olua_cls_ccui_RadioButton_ccRadioButtonCallback(lua_State *L)
{
    oluacls_class<cocos2d::ui::RadioButton::ccRadioButtonCallback>(L, "ccui.RadioButton.ccRadioButtonCallback");
    oluacls_func(L, "__call", _olua_fun_cocos2d_ui_RadioButton_ccRadioButtonCallback___call);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_RadioButton_ccRadioButtonCallback(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.RadioButton.ccRadioButtonCallback")) {
        luaL_error(L, "class not found: cocos2d::ui::RadioButton::ccRadioButtonCallback");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_ui_RadioButton_addEventListener(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RadioButton *self = nullptr;
    cocos2d::ui::RadioButton::ccRadioButtonCallback arg1;       /** callback */

    olua_to_object(L, 1, &self, "ccui.RadioButton");
    olua_check_callback(L, 2, &arg1, "ccui.RadioButton.ccRadioButtonCallback");

    void *cb_store = (void *)self;
    std::string cb_tag = "radioButtonCallback";
    std::string cb_name = olua_setcallback(L, cb_store, 2, cb_tag.c_str(), OLUA_TAG_REPLACE);
    olua_Context cb_ctx = olua_context(L);
    // lua_State *ML = olua_mainthread(L);
    arg1 = [cb_store, cb_name, cb_ctx /*, ML */](cocos2d::ui::RadioButton *cb_arg1, cocos2d::ui::RadioButton::EventType cb_arg2) {
        lua_State *L = olua_mainthread(NULL);
        olua_checkhostthread();

        if (olua_contextequal(L, cb_ctx)) {
            int top = lua_gettop(L);
            olua_push_object(L, cb_arg1, "ccui.RadioButton");
            olua_push_enum(L, cb_arg2);

            olua_callback(L, cb_store, cb_name.c_str(), 2);

            lua_settop(L, top);
        }
    };

    // void addEventListener(const cocos2d::ui::RadioButton::ccRadioButtonCallback &callback)
    self->addEventListener(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_RadioButton_create$1(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::ui::RadioButton *create()
    cocos2d::ui::RadioButton *ret = cocos2d::ui::RadioButton::create();
    int num_ret = olua_push_object(L, ret, "ccui.RadioButton");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_RadioButton_create$2(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** backGround */
    std::string arg2;       /** backGroundSelected */
    std::string arg3;       /** cross */
    std::string arg4;       /** backGroundDisabled */
    std::string arg5;       /** frontCrossDisabled */
    cocos2d::ui::Widget::TextureResType arg6 = (cocos2d::ui::Widget::TextureResType)0;       /** texType */

    olua_check_string(L, 1, &arg1);
    olua_check_string(L, 2, &arg2);
    olua_check_string(L, 3, &arg3);
    olua_check_string(L, 4, &arg4);
    olua_check_string(L, 5, &arg5);
    olua_check_enum(L, 6, &arg6);

    // static cocos2d::ui::RadioButton *create(const std::string &backGround, const std::string &backGroundSelected, const std::string &cross, const std::string &backGroundDisabled, const std::string &frontCrossDisabled, @optional cocos2d::ui::Widget::TextureResType texType)
    cocos2d::ui::RadioButton *ret = cocos2d::ui::RadioButton::create(arg1, arg2, arg3, arg4, arg5, arg6);
    int num_ret = olua_push_object(L, ret, "ccui.RadioButton");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_RadioButton_create$3(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** backGround */
    std::string arg2;       /** backGroundSelected */
    std::string arg3;       /** cross */
    std::string arg4;       /** backGroundDisabled */
    std::string arg5;       /** frontCrossDisabled */

    olua_check_string(L, 1, &arg1);
    olua_check_string(L, 2, &arg2);
    olua_check_string(L, 3, &arg3);
    olua_check_string(L, 4, &arg4);
    olua_check_string(L, 5, &arg5);

    // static cocos2d::ui::RadioButton *create(const std::string &backGround, const std::string &backGroundSelected, const std::string &cross, const std::string &backGroundDisabled, const std::string &frontCrossDisabled)
    cocos2d::ui::RadioButton *ret = cocos2d::ui::RadioButton::create(arg1, arg2, arg3, arg4, arg5);
    int num_ret = olua_push_object(L, ret, "ccui.RadioButton");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_RadioButton_create$4(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** backGround */
    std::string arg2;       /** cross */
    cocos2d::ui::Widget::TextureResType arg3 = (cocos2d::ui::Widget::TextureResType)0;       /** texType */

    olua_check_string(L, 1, &arg1);
    olua_check_string(L, 2, &arg2);
    olua_check_enum(L, 3, &arg3);

    // static cocos2d::ui::RadioButton *create(const std::string &backGround, const std::string &cross, @optional cocos2d::ui::Widget::TextureResType texType)
    cocos2d::ui::RadioButton *ret = cocos2d::ui::RadioButton::create(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "ccui.RadioButton");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_RadioButton_create$5(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** backGround */
    std::string arg2;       /** cross */

    olua_check_string(L, 1, &arg1);
    olua_check_string(L, 2, &arg2);

    // static cocos2d::ui::RadioButton *create(const std::string &backGround, const std::string &cross)
    cocos2d::ui::RadioButton *ret = cocos2d::ui::RadioButton::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "ccui.RadioButton");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_RadioButton_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // static cocos2d::ui::RadioButton *create()
        return _olua_fun_cocos2d_ui_RadioButton_create$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_string(L, 1)) && (olua_is_string(L, 2))) {
            // static cocos2d::ui::RadioButton *create(const std::string &backGround, const std::string &cross)
            return _olua_fun_cocos2d_ui_RadioButton_create$5(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_string(L, 1)) && (olua_is_string(L, 2)) && (olua_is_enum(L, 3))) {
            // static cocos2d::ui::RadioButton *create(const std::string &backGround, const std::string &cross, @optional cocos2d::ui::Widget::TextureResType texType)
            return _olua_fun_cocos2d_ui_RadioButton_create$4(L);
        // }
    }

    if (num_args == 5) {
        // if ((olua_is_string(L, 1)) && (olua_is_string(L, 2)) && (olua_is_string(L, 3)) && (olua_is_string(L, 4)) && (olua_is_string(L, 5))) {
            // static cocos2d::ui::RadioButton *create(const std::string &backGround, const std::string &backGroundSelected, const std::string &cross, const std::string &backGroundDisabled, const std::string &frontCrossDisabled)
            return _olua_fun_cocos2d_ui_RadioButton_create$3(L);
        // }
    }

    if (num_args == 6) {
        // if ((olua_is_string(L, 1)) && (olua_is_string(L, 2)) && (olua_is_string(L, 3)) && (olua_is_string(L, 4)) && (olua_is_string(L, 5)) && (olua_is_enum(L, 6))) {
            // static cocos2d::ui::RadioButton *create(const std::string &backGround, const std::string &backGroundSelected, const std::string &cross, const std::string &backGroundDisabled, const std::string &frontCrossDisabled, @optional cocos2d::ui::Widget::TextureResType texType)
            return _olua_fun_cocos2d_ui_RadioButton_create$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::RadioButton::create' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_RadioButton_createInstance(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::Ref *createInstance()
    cocos2d::Ref *ret = cocos2d::ui::RadioButton::createInstance();
    int num_ret = olua_push_object(L, ret, "cc.Ref");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_RadioButton_new(lua_State *L)
{
    olua_startinvoke(L);

    // cocos2d::ui::RadioButton()
    cocos2d::ui::RadioButton *ret = new cocos2d::ui::RadioButton();
    int num_ret = olua_push_object(L, ret, "ccui.RadioButton");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_cls_ccui_RadioButton(lua_State *L)
{
    oluacls_class<cocos2d::ui::RadioButton, cocos2d::ui::AbstractCheckButton>(L, "ccui.RadioButton");
    oluacls_func(L, "addEventListener", _olua_fun_cocos2d_ui_RadioButton_addEventListener);
    oluacls_func(L, "create", _olua_fun_cocos2d_ui_RadioButton_create);
    oluacls_func(L, "createInstance", _olua_fun_cocos2d_ui_RadioButton_createInstance);
    oluacls_func(L, "new", _olua_fun_cocos2d_ui_RadioButton_new);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_RadioButton(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.RadioButton")) {
        luaL_error(L, "class not found: cocos2d::ui::RadioButton");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_ccui_RadioButtonGroup_EventType(lua_State *L)
{
    oluacls_class<cocos2d::ui::RadioButtonGroup::EventType>(L, "ccui.RadioButtonGroup.EventType");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "SELECT_CHANGED", (lua_Integer)cocos2d::ui::RadioButtonGroup::EventType::SELECT_CHANGED);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_RadioButtonGroup_EventType(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.RadioButtonGroup.EventType")) {
        luaL_error(L, "class not found: cocos2d::ui::RadioButtonGroup::EventType");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_ui_RadioButtonGroup_ccRadioButtonGroupCallback___call(lua_State *L)
{
    olua_startinvoke(L);

    luaL_checktype(L, -1, LUA_TFUNCTION);
    olua_push_callback(L, (cocos2d::ui::RadioButtonGroup::ccRadioButtonGroupCallback *)nullptr, "ccui.RadioButtonGroup.ccRadioButtonGroupCallback");

    olua_endinvoke(L);

    return 1;
}

static int _olua_cls_ccui_RadioButtonGroup_ccRadioButtonGroupCallback(lua_State *L)
{
    oluacls_class<cocos2d::ui::RadioButtonGroup::ccRadioButtonGroupCallback>(L, "ccui.RadioButtonGroup.ccRadioButtonGroupCallback");
    oluacls_func(L, "__call", _olua_fun_cocos2d_ui_RadioButtonGroup_ccRadioButtonGroupCallback___call);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_RadioButtonGroup_ccRadioButtonGroupCallback(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.RadioButtonGroup.ccRadioButtonGroupCallback")) {
        luaL_error(L, "class not found: cocos2d::ui::RadioButtonGroup::ccRadioButtonGroupCallback");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_ui_RadioButtonGroup_addEventListener(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RadioButtonGroup *self = nullptr;
    cocos2d::ui::RadioButtonGroup::ccRadioButtonGroupCallback arg1;       /** callback */

    olua_to_object(L, 1, &self, "ccui.RadioButtonGroup");
    olua_check_callback(L, 2, &arg1, "ccui.RadioButtonGroup.ccRadioButtonGroupCallback");

    void *cb_store = (void *)self;
    std::string cb_tag = "radioButtonCallback";
    std::string cb_name = olua_setcallback(L, cb_store, 2, cb_tag.c_str(), OLUA_TAG_REPLACE);
    olua_Context cb_ctx = olua_context(L);
    // lua_State *ML = olua_mainthread(L);
    arg1 = [cb_store, cb_name, cb_ctx /*, ML */](cocos2d::ui::RadioButton *cb_arg1, int cb_arg2, cocos2d::ui::RadioButtonGroup::EventType cb_arg3) {
        lua_State *L = olua_mainthread(NULL);
        olua_checkhostthread();

        if (olua_contextequal(L, cb_ctx)) {
            int top = lua_gettop(L);
            olua_push_object(L, cb_arg1, "ccui.RadioButton");
            olua_push_integer(L, cb_arg2);
            olua_push_enum(L, cb_arg3);

            olua_callback(L, cb_store, cb_name.c_str(), 3);

            lua_settop(L, top);
        }
    };

    // void addEventListener(const cocos2d::ui::RadioButtonGroup::ccRadioButtonGroupCallback &callback)
    self->addEventListener(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_RadioButtonGroup_addRadioButton(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RadioButtonGroup *self = nullptr;
    cocos2d::ui::RadioButton *arg1 = nullptr;       /** radioButton */

    olua_to_object(L, 1, &self, "ccui.RadioButtonGroup");
    olua_check_object(L, 2, &arg1, "ccui.RadioButton");

    // void addRadioButton(cocos2d::ui::RadioButton *radioButton)
    self->addRadioButton(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_RadioButtonGroup_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::ui::RadioButtonGroup *create()
    cocos2d::ui::RadioButtonGroup *ret = cocos2d::ui::RadioButtonGroup::create();
    int num_ret = olua_push_object(L, ret, "ccui.RadioButtonGroup");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_RadioButtonGroup_getNumberOfRadioButtons(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RadioButtonGroup *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.RadioButtonGroup");

    // ssize_t getNumberOfRadioButtons()
    ssize_t ret = self->getNumberOfRadioButtons();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_RadioButtonGroup_getRadioButtonByIndex(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RadioButtonGroup *self = nullptr;
    int arg1 = 0;       /** index */

    olua_to_object(L, 1, &self, "ccui.RadioButtonGroup");
    olua_check_integer(L, 2, &arg1);

    // cocos2d::ui::RadioButton *getRadioButtonByIndex(int index)
    cocos2d::ui::RadioButton *ret = self->getRadioButtonByIndex(arg1);
    int num_ret = olua_push_object(L, ret, "ccui.RadioButton");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_RadioButtonGroup_getSelectedButtonIndex(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RadioButtonGroup *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.RadioButtonGroup");

    // int getSelectedButtonIndex()
    int ret = self->getSelectedButtonIndex();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_RadioButtonGroup_isAllowedNoSelection(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RadioButtonGroup *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.RadioButtonGroup");

    // bool isAllowedNoSelection()
    bool ret = self->isAllowedNoSelection();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_RadioButtonGroup_new(lua_State *L)
{
    olua_startinvoke(L);

    // cocos2d::ui::RadioButtonGroup()
    cocos2d::ui::RadioButtonGroup *ret = new cocos2d::ui::RadioButtonGroup();
    int num_ret = olua_push_object(L, ret, "ccui.RadioButtonGroup");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_RadioButtonGroup_removeAllRadioButtons(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RadioButtonGroup *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.RadioButtonGroup");

    // void removeAllRadioButtons()
    self->removeAllRadioButtons();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_RadioButtonGroup_removeRadioButton(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RadioButtonGroup *self = nullptr;
    cocos2d::ui::RadioButton *arg1 = nullptr;       /** radioButton */

    olua_to_object(L, 1, &self, "ccui.RadioButtonGroup");
    olua_check_object(L, 2, &arg1, "ccui.RadioButton");

    // void removeRadioButton(cocos2d::ui::RadioButton *radioButton)
    self->removeRadioButton(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_RadioButtonGroup_setAllowedNoSelection(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RadioButtonGroup *self = nullptr;
    bool arg1 = false;       /** allowedNoSelection */

    olua_to_object(L, 1, &self, "ccui.RadioButtonGroup");
    olua_check_bool(L, 2, &arg1);

    // void setAllowedNoSelection(bool allowedNoSelection)
    self->setAllowedNoSelection(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_RadioButtonGroup_setSelectedButton$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RadioButtonGroup *self = nullptr;
    int arg1 = 0;       /** index */

    olua_to_object(L, 1, &self, "ccui.RadioButtonGroup");
    olua_check_integer(L, 2, &arg1);

    // void setSelectedButton(int index)
    self->setSelectedButton(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_RadioButtonGroup_setSelectedButton$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RadioButtonGroup *self = nullptr;
    cocos2d::ui::RadioButton *arg1 = nullptr;       /** radioButton */

    olua_to_object(L, 1, &self, "ccui.RadioButtonGroup");
    olua_check_object(L, 2, &arg1, "ccui.RadioButton");

    // void setSelectedButton(cocos2d::ui::RadioButton *radioButton)
    self->setSelectedButton(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_RadioButtonGroup_setSelectedButton(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        if ((olua_is_object(L, 1, "ccui.RadioButtonGroup")) && (olua_is_integer(L, 2))) {
            // void setSelectedButton(int index)
            return _olua_fun_cocos2d_ui_RadioButtonGroup_setSelectedButton$1(L);
        }

        // if ((olua_is_object(L, 1, "ccui.RadioButtonGroup")) && (olua_is_object(L, 2, "ccui.RadioButton"))) {
            // void setSelectedButton(cocos2d::ui::RadioButton *radioButton)
            return _olua_fun_cocos2d_ui_RadioButtonGroup_setSelectedButton$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::RadioButtonGroup::setSelectedButton' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_RadioButtonGroup_setSelectedButtonWithoutEvent$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RadioButtonGroup *self = nullptr;
    int arg1 = 0;       /** index */

    olua_to_object(L, 1, &self, "ccui.RadioButtonGroup");
    olua_check_integer(L, 2, &arg1);

    // void setSelectedButtonWithoutEvent(int index)
    self->setSelectedButtonWithoutEvent(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_RadioButtonGroup_setSelectedButtonWithoutEvent$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RadioButtonGroup *self = nullptr;
    cocos2d::ui::RadioButton *arg1 = nullptr;       /** radioButton */

    olua_to_object(L, 1, &self, "ccui.RadioButtonGroup");
    olua_check_object(L, 2, &arg1, "ccui.RadioButton");

    // void setSelectedButtonWithoutEvent(cocos2d::ui::RadioButton *radioButton)
    self->setSelectedButtonWithoutEvent(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_RadioButtonGroup_setSelectedButtonWithoutEvent(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        if ((olua_is_object(L, 1, "ccui.RadioButtonGroup")) && (olua_is_integer(L, 2))) {
            // void setSelectedButtonWithoutEvent(int index)
            return _olua_fun_cocos2d_ui_RadioButtonGroup_setSelectedButtonWithoutEvent$1(L);
        }

        // if ((olua_is_object(L, 1, "ccui.RadioButtonGroup")) && (olua_is_object(L, 2, "ccui.RadioButton"))) {
            // void setSelectedButtonWithoutEvent(cocos2d::ui::RadioButton *radioButton)
            return _olua_fun_cocos2d_ui_RadioButtonGroup_setSelectedButtonWithoutEvent$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::RadioButtonGroup::setSelectedButtonWithoutEvent' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_ccui_RadioButtonGroup(lua_State *L)
{
    oluacls_class<cocos2d::ui::RadioButtonGroup, cocos2d::ui::Widget>(L, "ccui.RadioButtonGroup");
    oluacls_func(L, "addEventListener", _olua_fun_cocos2d_ui_RadioButtonGroup_addEventListener);
    oluacls_func(L, "addRadioButton", _olua_fun_cocos2d_ui_RadioButtonGroup_addRadioButton);
    oluacls_func(L, "create", _olua_fun_cocos2d_ui_RadioButtonGroup_create);
    oluacls_func(L, "getNumberOfRadioButtons", _olua_fun_cocos2d_ui_RadioButtonGroup_getNumberOfRadioButtons);
    oluacls_func(L, "getRadioButtonByIndex", _olua_fun_cocos2d_ui_RadioButtonGroup_getRadioButtonByIndex);
    oluacls_func(L, "getSelectedButtonIndex", _olua_fun_cocos2d_ui_RadioButtonGroup_getSelectedButtonIndex);
    oluacls_func(L, "isAllowedNoSelection", _olua_fun_cocos2d_ui_RadioButtonGroup_isAllowedNoSelection);
    oluacls_func(L, "new", _olua_fun_cocos2d_ui_RadioButtonGroup_new);
    oluacls_func(L, "removeAllRadioButtons", _olua_fun_cocos2d_ui_RadioButtonGroup_removeAllRadioButtons);
    oluacls_func(L, "removeRadioButton", _olua_fun_cocos2d_ui_RadioButtonGroup_removeRadioButton);
    oluacls_func(L, "setAllowedNoSelection", _olua_fun_cocos2d_ui_RadioButtonGroup_setAllowedNoSelection);
    oluacls_func(L, "setSelectedButton", _olua_fun_cocos2d_ui_RadioButtonGroup_setSelectedButton);
    oluacls_func(L, "setSelectedButtonWithoutEvent", _olua_fun_cocos2d_ui_RadioButtonGroup_setSelectedButtonWithoutEvent);
    oluacls_prop(L, "allowedNoSelection", _olua_fun_cocos2d_ui_RadioButtonGroup_isAllowedNoSelection, _olua_fun_cocos2d_ui_RadioButtonGroup_setAllowedNoSelection);
    oluacls_prop(L, "numberOfRadioButtons", _olua_fun_cocos2d_ui_RadioButtonGroup_getNumberOfRadioButtons, nullptr);
    oluacls_prop(L, "selectedButtonIndex", _olua_fun_cocos2d_ui_RadioButtonGroup_getSelectedButtonIndex, nullptr);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_RadioButtonGroup(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.RadioButtonGroup")) {
        luaL_error(L, "class not found: cocos2d::ui::RadioButtonGroup");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_ui_ImageView_as(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ImageView *self = nullptr;
    const char *arg1 = nullptr;       /** cls */

    olua_to_object(L, 1, &self, "ccui.ImageView");
    olua_check_string(L, 2, &arg1);

    do {
        if (olua_isa(L, 1, arg1)) {
            lua_pushvalue(L, 1);
            break;
        }
        if (olua_strequal(arg1, "cc.BlendProtocol")) {
            olua_pushobj_as<cocos2d::BlendProtocol>(L, 1, self, "as.cc.BlendProtocol");
            break;
        }
        if (olua_strequal(arg1, "ccui.LayoutParameterProtocol")) {
            olua_pushobj_as<cocos2d::ui::LayoutParameterProtocol>(L, 1, self, "as.ccui.LayoutParameterProtocol");
            break;
        }

        luaL_error(L, "'cocos2d::ui::ImageView' can't cast to '%s'", arg1);
    } while (0);

    olua_endinvoke(L);

    return 1;
}

static int _olua_fun_cocos2d_ui_ImageView_create$1(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::ui::ImageView *create()
    cocos2d::ui::ImageView *ret = cocos2d::ui::ImageView::create();
    int num_ret = olua_push_object(L, ret, "ccui.ImageView");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_ImageView_create$2(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** imageFileName */
    cocos2d::ui::Widget::TextureResType arg2 = (cocos2d::ui::Widget::TextureResType)0;       /** texType */

    olua_check_string(L, 1, &arg1);
    olua_check_enum(L, 2, &arg2);

    // static cocos2d::ui::ImageView *create(const std::string &imageFileName, @optional cocos2d::ui::Widget::TextureResType texType)
    cocos2d::ui::ImageView *ret = cocos2d::ui::ImageView::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "ccui.ImageView");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_ImageView_create$3(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** imageFileName */

    olua_check_string(L, 1, &arg1);

    // static cocos2d::ui::ImageView *create(const std::string &imageFileName)
    cocos2d::ui::ImageView *ret = cocos2d::ui::ImageView::create(arg1);
    int num_ret = olua_push_object(L, ret, "ccui.ImageView");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_ImageView_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // static cocos2d::ui::ImageView *create()
        return _olua_fun_cocos2d_ui_ImageView_create$1(L);
    }

    if (num_args == 1) {
        // if ((olua_is_string(L, 1))) {
            // static cocos2d::ui::ImageView *create(const std::string &imageFileName)
            return _olua_fun_cocos2d_ui_ImageView_create$3(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_string(L, 1)) && (olua_is_enum(L, 2))) {
            // static cocos2d::ui::ImageView *create(const std::string &imageFileName, @optional cocos2d::ui::Widget::TextureResType texType)
            return _olua_fun_cocos2d_ui_ImageView_create$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::ImageView::create' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_ImageView_createInstance(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::Ref *createInstance()
    cocos2d::Ref *ret = cocos2d::ui::ImageView::createInstance();
    int num_ret = olua_push_object(L, ret, "cc.Ref");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_ImageView_getBlendFunc(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ImageView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.ImageView");

    // const cocos2d::BlendFunc &getBlendFunc()
    const cocos2d::BlendFunc &ret = self->getBlendFunc();
    int num_ret = olua_push_object(L, ret, "cc.BlendFunc");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_ImageView_getCapInsets(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ImageView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.ImageView");

    // const cocos2d::Rect &getCapInsets()
    const cocos2d::Rect &ret = self->getCapInsets();
    int num_ret = olua_push_object(L, ret, "cc.Rect");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_ImageView_getRenderFile(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ImageView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.ImageView");

    // cocos2d::ResourceData getRenderFile()
    cocos2d::ResourceData ret = self->getRenderFile();
    int num_ret = olua_copy_object(L, ret, "cc.ResourceData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_ImageView_init$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ImageView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.ImageView");

    // @using bool init()
    bool ret = self->init();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_ImageView_init$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ImageView *self = nullptr;
    std::string arg1;       /** imageFileName */
    cocos2d::ui::Widget::TextureResType arg2 = (cocos2d::ui::Widget::TextureResType)0;       /** texType */

    olua_to_object(L, 1, &self, "ccui.ImageView");
    olua_check_string(L, 2, &arg1);
    olua_check_enum(L, 3, &arg2);

    // bool init(const std::string &imageFileName, @optional cocos2d::ui::Widget::TextureResType texType)
    bool ret = self->init(arg1, arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_ImageView_init$3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ImageView *self = nullptr;
    std::string arg1;       /** imageFileName */

    olua_to_object(L, 1, &self, "ccui.ImageView");
    olua_check_string(L, 2, &arg1);

    // bool init(const std::string &imageFileName)
    bool ret = self->init(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_ImageView_init(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // @using bool init()
        return _olua_fun_cocos2d_ui_ImageView_init$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccui.ImageView")) && (olua_is_string(L, 2))) {
            // bool init(const std::string &imageFileName)
            return _olua_fun_cocos2d_ui_ImageView_init$3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "ccui.ImageView")) && (olua_is_string(L, 2)) && (olua_is_enum(L, 3))) {
            // bool init(const std::string &imageFileName, @optional cocos2d::ui::Widget::TextureResType texType)
            return _olua_fun_cocos2d_ui_ImageView_init$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::ImageView::init' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_ImageView_isScale9Enabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ImageView *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.ImageView");

    // bool isScale9Enabled()
    bool ret = self->isScale9Enabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_ImageView_loadTexture$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ImageView *self = nullptr;
    std::string arg1;       /** fileName */
    cocos2d::ui::Widget::TextureResType arg2 = (cocos2d::ui::Widget::TextureResType)0;       /** texType */

    olua_to_object(L, 1, &self, "ccui.ImageView");
    olua_check_string(L, 2, &arg1);
    olua_check_enum(L, 3, &arg2);

    // void loadTexture(const std::string &fileName, @optional cocos2d::ui::Widget::TextureResType texType)
    self->loadTexture(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_ImageView_loadTexture$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ImageView *self = nullptr;
    std::string arg1;       /** fileName */

    olua_to_object(L, 1, &self, "ccui.ImageView");
    olua_check_string(L, 2, &arg1);

    // void loadTexture(const std::string &fileName)
    self->loadTexture(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_ImageView_loadTexture(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccui.ImageView")) && (olua_is_string(L, 2))) {
            // void loadTexture(const std::string &fileName)
            return _olua_fun_cocos2d_ui_ImageView_loadTexture$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "ccui.ImageView")) && (olua_is_string(L, 2)) && (olua_is_enum(L, 3))) {
            // void loadTexture(const std::string &fileName, @optional cocos2d::ui::Widget::TextureResType texType)
            return _olua_fun_cocos2d_ui_ImageView_loadTexture$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::ImageView::loadTexture' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_ImageView_new(lua_State *L)
{
    olua_startinvoke(L);

    // cocos2d::ui::ImageView()
    cocos2d::ui::ImageView *ret = new cocos2d::ui::ImageView();
    int num_ret = olua_push_object(L, ret, "ccui.ImageView");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_ImageView_setBlendFunc(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ImageView *self = nullptr;
    cocos2d::BlendFunc *arg1;       /** blendFunc */

    olua_to_object(L, 1, &self, "ccui.ImageView");
    olua_check_object(L, 2, &arg1, "cc.BlendFunc");

    // void setBlendFunc(const cocos2d::BlendFunc &blendFunc)
    self->setBlendFunc(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_ImageView_setCapInsets(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ImageView *self = nullptr;
    cocos2d::Rect *arg1;       /** capInsets */

    olua_to_object(L, 1, &self, "ccui.ImageView");
    olua_check_object(L, 2, &arg1, "cc.Rect");

    // void setCapInsets(const cocos2d::Rect &capInsets)
    self->setCapInsets(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_ImageView_setScale9Enabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ImageView *self = nullptr;
    bool arg1 = false;       /** enabled */

    olua_to_object(L, 1, &self, "ccui.ImageView");
    olua_check_bool(L, 2, &arg1);

    // void setScale9Enabled(bool enabled)
    self->setScale9Enabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_ImageView_setTextureRect(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ImageView *self = nullptr;
    cocos2d::Rect *arg1;       /** rect */

    olua_to_object(L, 1, &self, "ccui.ImageView");
    olua_check_object(L, 2, &arg1, "cc.Rect");

    // void setTextureRect(const cocos2d::Rect &rect)
    self->setTextureRect(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_cls_ccui_ImageView(lua_State *L)
{
    oluacls_class<cocos2d::ui::ImageView, cocos2d::ui::Widget>(L, "ccui.ImageView");
    oluacls_func(L, "as", _olua_fun_cocos2d_ui_ImageView_as);
    oluacls_func(L, "create", _olua_fun_cocos2d_ui_ImageView_create);
    oluacls_func(L, "createInstance", _olua_fun_cocos2d_ui_ImageView_createInstance);
    oluacls_func(L, "getBlendFunc", _olua_fun_cocos2d_ui_ImageView_getBlendFunc);
    oluacls_func(L, "getCapInsets", _olua_fun_cocos2d_ui_ImageView_getCapInsets);
    oluacls_func(L, "getRenderFile", _olua_fun_cocos2d_ui_ImageView_getRenderFile);
    oluacls_func(L, "init", _olua_fun_cocos2d_ui_ImageView_init);
    oluacls_func(L, "isScale9Enabled", _olua_fun_cocos2d_ui_ImageView_isScale9Enabled);
    oluacls_func(L, "loadTexture", _olua_fun_cocos2d_ui_ImageView_loadTexture);
    oluacls_func(L, "new", _olua_fun_cocos2d_ui_ImageView_new);
    oluacls_func(L, "setBlendFunc", _olua_fun_cocos2d_ui_ImageView_setBlendFunc);
    oluacls_func(L, "setCapInsets", _olua_fun_cocos2d_ui_ImageView_setCapInsets);
    oluacls_func(L, "setScale9Enabled", _olua_fun_cocos2d_ui_ImageView_setScale9Enabled);
    oluacls_func(L, "setTextureRect", _olua_fun_cocos2d_ui_ImageView_setTextureRect);
    oluacls_prop(L, "blendFunc", _olua_fun_cocos2d_ui_ImageView_getBlendFunc, _olua_fun_cocos2d_ui_ImageView_setBlendFunc);
    oluacls_prop(L, "capInsets", _olua_fun_cocos2d_ui_ImageView_getCapInsets, _olua_fun_cocos2d_ui_ImageView_setCapInsets);
    oluacls_prop(L, "renderFile", _olua_fun_cocos2d_ui_ImageView_getRenderFile, nullptr);
    oluacls_prop(L, "scale9Enabled", _olua_fun_cocos2d_ui_ImageView_isScale9Enabled, _olua_fun_cocos2d_ui_ImageView_setScale9Enabled);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_ImageView(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.ImageView")) {
        luaL_error(L, "class not found: cocos2d::ui::ImageView");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_ccui_EditBoxDelegate_EditBoxEndAction(lua_State *L)
{
    oluacls_class<cocos2d::ui::EditBoxDelegate::EditBoxEndAction>(L, "ccui.EditBoxDelegate.EditBoxEndAction");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "RETURN", (lua_Integer)cocos2d::ui::EditBoxDelegate::EditBoxEndAction::RETURN);
    oluacls_enum(L, "TAB_TO_NEXT", (lua_Integer)cocos2d::ui::EditBoxDelegate::EditBoxEndAction::TAB_TO_NEXT);
    oluacls_enum(L, "TAB_TO_PREVIOUS", (lua_Integer)cocos2d::ui::EditBoxDelegate::EditBoxEndAction::TAB_TO_PREVIOUS);
    oluacls_enum(L, "UNKNOWN", (lua_Integer)cocos2d::ui::EditBoxDelegate::EditBoxEndAction::UNKNOWN);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_EditBoxDelegate_EditBoxEndAction(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.EditBoxDelegate.EditBoxEndAction")) {
        luaL_error(L, "class not found: cocos2d::ui::EditBoxDelegate::EditBoxEndAction");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_ui_EditBoxDelegate___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::ui::EditBoxDelegate *)olua_toobj(L, 1, "ccui.EditBoxDelegate");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_EditBoxDelegate_editBoxEditingDidBegin(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBoxDelegate *self = nullptr;
    cocos2d::ui::EditBox *arg1 = nullptr;       /** arg1 */

    olua_to_object(L, 1, &self, "ccui.EditBoxDelegate");
    olua_check_object(L, 2, &arg1, "ccui.EditBox");

    // void editBoxEditingDidBegin(cocos2d::ui::EditBox *arg1)
    self->editBoxEditingDidBegin(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_EditBoxDelegate_editBoxEditingDidEndWithAction(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBoxDelegate *self = nullptr;
    cocos2d::ui::EditBox *arg1 = nullptr;       /** arg1 */
    cocos2d::ui::EditBoxDelegate::EditBoxEndAction arg2 = (cocos2d::ui::EditBoxDelegate::EditBoxEndAction)0;       /** arg2 */

    olua_to_object(L, 1, &self, "ccui.EditBoxDelegate");
    olua_check_object(L, 2, &arg1, "ccui.EditBox");
    olua_check_enum(L, 3, &arg2);

    // void editBoxEditingDidEndWithAction(cocos2d::ui::EditBox *arg1, cocos2d::ui::EditBoxDelegate::EditBoxEndAction arg2)
    self->editBoxEditingDidEndWithAction(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_EditBoxDelegate_editBoxReturn(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBoxDelegate *self = nullptr;
    cocos2d::ui::EditBox *arg1 = nullptr;       /** editBox */

    olua_to_object(L, 1, &self, "ccui.EditBoxDelegate");
    olua_check_object(L, 2, &arg1, "ccui.EditBox");

    // void editBoxReturn(cocos2d::ui::EditBox *editBox)
    self->editBoxReturn(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_EditBoxDelegate_editBoxTextChanged(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBoxDelegate *self = nullptr;
    cocos2d::ui::EditBox *arg1 = nullptr;       /** arg1 */
    std::string arg2;       /** arg2 */

    olua_to_object(L, 1, &self, "ccui.EditBoxDelegate");
    olua_check_object(L, 2, &arg1, "ccui.EditBox");
    olua_check_string(L, 3, &arg2);

    // void editBoxTextChanged(cocos2d::ui::EditBox *arg1, const std::string &arg2)
    self->editBoxTextChanged(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_cls_ccui_EditBoxDelegate(lua_State *L)
{
    oluacls_class<cocos2d::ui::EditBoxDelegate>(L, "ccui.EditBoxDelegate");
    oluacls_func(L, "__gc", _olua_fun_cocos2d_ui_EditBoxDelegate___gc);
    oluacls_func(L, "editBoxEditingDidBegin", _olua_fun_cocos2d_ui_EditBoxDelegate_editBoxEditingDidBegin);
    oluacls_func(L, "editBoxEditingDidEndWithAction", _olua_fun_cocos2d_ui_EditBoxDelegate_editBoxEditingDidEndWithAction);
    oluacls_func(L, "editBoxReturn", _olua_fun_cocos2d_ui_EditBoxDelegate_editBoxReturn);
    oluacls_func(L, "editBoxTextChanged", _olua_fun_cocos2d_ui_EditBoxDelegate_editBoxTextChanged);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_EditBoxDelegate(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.EditBoxDelegate")) {
        luaL_error(L, "class not found: cocos2d::ui::EditBoxDelegate");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_ui_LuaEditBoxDelegate_new(lua_State *L)
{
    olua_startinvoke(L);

    // cocos2d::ui::LuaEditBoxDelegate()
    cocos2d::ui::LuaEditBoxDelegate *ret = new cocos2d::ui::LuaEditBoxDelegate();
    int num_ret = olua_push_object(L, ret, "ccui.LuaEditBoxDelegate");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_LuaEditBoxDelegate_onEditingDidBegin$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LuaEditBoxDelegate *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.LuaEditBoxDelegate");

    void *cb_store = (void *)self;
    std::string cb_tag = "onEditingDidBegin";
    olua_getcallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_EQUAL);

    // std::function<void (cocos2d::ui::EditBox *)> onEditingDidBegin
    std::function<void (cocos2d::ui::EditBox *)> ret = self->onEditingDidBegin;
    int num_ret = olua_push_callback(L, &ret, "std.function");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_LuaEditBoxDelegate_onEditingDidBegin$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LuaEditBoxDelegate *self = nullptr;
    std::function<void (cocos2d::ui::EditBox *)> arg1;       /** onEditingDidBegin */

    olua_to_object(L, 1, &self, "ccui.LuaEditBoxDelegate");
    if (!olua_isnoneornil(L, 2)) {
        olua_check_callback(L, 2, &arg1, "std.function");
    }

    void *cb_store = (void *)self;
    std::string cb_tag = "onEditingDidBegin";
    std::string cb_name;
    if (olua_isfunction(L, 2)) {
        cb_name = olua_setcallback(L, cb_store, 2, cb_tag.c_str(), OLUA_TAG_REPLACE);
        olua_Context cb_ctx = olua_context(L);
        // lua_State *ML = olua_mainthread(L);
        arg1 = [cb_store, cb_name, cb_ctx /*, ML */](cocos2d::ui::EditBox *cb_arg1) {
            lua_State *L = olua_mainthread(NULL);
            olua_checkhostthread();

            if (olua_contextequal(L, cb_ctx)) {
                int top = lua_gettop(L);
                size_t last = olua_push_objpool(L);
                olua_enable_objpool(L);
                olua_push_object(L, cb_arg1, "ccui.EditBox");
                olua_disable_objpool(L);

                olua_callback(L, cb_store, cb_name.c_str(), 1);

                //pop stack value
                olua_pop_objpool(L, last);
                lua_settop(L, top);
            }
        };
    } else {
        olua_removecallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_EQUAL);
        arg1 = nullptr;
    }

    // std::function<void (cocos2d::ui::EditBox *)> onEditingDidBegin
    self->onEditingDidBegin = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_LuaEditBoxDelegate_onEditingDidBegin(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // std::function<void (cocos2d::ui::EditBox *)> onEditingDidBegin
        return _olua_fun_cocos2d_ui_LuaEditBoxDelegate_onEditingDidBegin$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccui.LuaEditBoxDelegate")) && (olua_is_callback(L, 2, "std.function") || olua_isnil(L, 2))) {
            // std::function<void (cocos2d::ui::EditBox *)> onEditingDidBegin
            return _olua_fun_cocos2d_ui_LuaEditBoxDelegate_onEditingDidBegin$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::LuaEditBoxDelegate::onEditingDidBegin' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_LuaEditBoxDelegate_onEditingDidEndWithAction$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LuaEditBoxDelegate *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.LuaEditBoxDelegate");

    void *cb_store = (void *)self;
    std::string cb_tag = "onEditingDidEndWithAction";
    olua_getcallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_EQUAL);

    // std::function<void (cocos2d::ui::EditBox *, cocos2d::ui::EditBoxDelegate::EditBoxEndAction)> onEditingDidEndWithAction
    std::function<void (cocos2d::ui::EditBox *, cocos2d::ui::EditBoxDelegate::EditBoxEndAction)> ret = self->onEditingDidEndWithAction;
    int num_ret = olua_push_callback(L, &ret, "std.function");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_LuaEditBoxDelegate_onEditingDidEndWithAction$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LuaEditBoxDelegate *self = nullptr;
    std::function<void (cocos2d::ui::EditBox *, cocos2d::ui::EditBoxDelegate::EditBoxEndAction)> arg1;       /** onEditingDidEndWithAction */

    olua_to_object(L, 1, &self, "ccui.LuaEditBoxDelegate");
    if (!olua_isnoneornil(L, 2)) {
        olua_check_callback(L, 2, &arg1, "std.function");
    }

    void *cb_store = (void *)self;
    std::string cb_tag = "onEditingDidEndWithAction";
    std::string cb_name;
    if (olua_isfunction(L, 2)) {
        cb_name = olua_setcallback(L, cb_store, 2, cb_tag.c_str(), OLUA_TAG_REPLACE);
        olua_Context cb_ctx = olua_context(L);
        // lua_State *ML = olua_mainthread(L);
        arg1 = [cb_store, cb_name, cb_ctx /*, ML */](cocos2d::ui::EditBox *cb_arg1, cocos2d::ui::EditBoxDelegate::EditBoxEndAction cb_arg2) {
            lua_State *L = olua_mainthread(NULL);
            olua_checkhostthread();

            if (olua_contextequal(L, cb_ctx)) {
                int top = lua_gettop(L);
                size_t last = olua_push_objpool(L);
                olua_enable_objpool(L);
                olua_push_object(L, cb_arg1, "ccui.EditBox");
                olua_push_enum(L, cb_arg2);
                olua_disable_objpool(L);

                olua_callback(L, cb_store, cb_name.c_str(), 2);

                //pop stack value
                olua_pop_objpool(L, last);
                lua_settop(L, top);
            }
        };
    } else {
        olua_removecallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_EQUAL);
        arg1 = nullptr;
    }

    // std::function<void (cocos2d::ui::EditBox *, cocos2d::ui::EditBoxDelegate::EditBoxEndAction)> onEditingDidEndWithAction
    self->onEditingDidEndWithAction = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_LuaEditBoxDelegate_onEditingDidEndWithAction(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // std::function<void (cocos2d::ui::EditBox *, cocos2d::ui::EditBoxDelegate::EditBoxEndAction)> onEditingDidEndWithAction
        return _olua_fun_cocos2d_ui_LuaEditBoxDelegate_onEditingDidEndWithAction$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccui.LuaEditBoxDelegate")) && (olua_is_callback(L, 2, "std.function") || olua_isnil(L, 2))) {
            // std::function<void (cocos2d::ui::EditBox *, cocos2d::ui::EditBoxDelegate::EditBoxEndAction)> onEditingDidEndWithAction
            return _olua_fun_cocos2d_ui_LuaEditBoxDelegate_onEditingDidEndWithAction$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::LuaEditBoxDelegate::onEditingDidEndWithAction' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_LuaEditBoxDelegate_onReturn$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LuaEditBoxDelegate *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.LuaEditBoxDelegate");

    void *cb_store = (void *)self;
    std::string cb_tag = "onReturn";
    olua_getcallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_EQUAL);

    // std::function<void (cocos2d::ui::EditBox *)> onReturn
    std::function<void (cocos2d::ui::EditBox *)> ret = self->onReturn;
    int num_ret = olua_push_callback(L, &ret, "std.function");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_LuaEditBoxDelegate_onReturn$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LuaEditBoxDelegate *self = nullptr;
    std::function<void (cocos2d::ui::EditBox *)> arg1;       /** onReturn */

    olua_to_object(L, 1, &self, "ccui.LuaEditBoxDelegate");
    if (!olua_isnoneornil(L, 2)) {
        olua_check_callback(L, 2, &arg1, "std.function");
    }

    void *cb_store = (void *)self;
    std::string cb_tag = "onReturn";
    std::string cb_name;
    if (olua_isfunction(L, 2)) {
        cb_name = olua_setcallback(L, cb_store, 2, cb_tag.c_str(), OLUA_TAG_REPLACE);
        olua_Context cb_ctx = olua_context(L);
        // lua_State *ML = olua_mainthread(L);
        arg1 = [cb_store, cb_name, cb_ctx /*, ML */](cocos2d::ui::EditBox *cb_arg1) {
            lua_State *L = olua_mainthread(NULL);
            olua_checkhostthread();

            if (olua_contextequal(L, cb_ctx)) {
                int top = lua_gettop(L);
                size_t last = olua_push_objpool(L);
                olua_enable_objpool(L);
                olua_push_object(L, cb_arg1, "ccui.EditBox");
                olua_disable_objpool(L);

                olua_callback(L, cb_store, cb_name.c_str(), 1);

                //pop stack value
                olua_pop_objpool(L, last);
                lua_settop(L, top);
            }
        };
    } else {
        olua_removecallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_EQUAL);
        arg1 = nullptr;
    }

    // std::function<void (cocos2d::ui::EditBox *)> onReturn
    self->onReturn = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_LuaEditBoxDelegate_onReturn(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // std::function<void (cocos2d::ui::EditBox *)> onReturn
        return _olua_fun_cocos2d_ui_LuaEditBoxDelegate_onReturn$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccui.LuaEditBoxDelegate")) && (olua_is_callback(L, 2, "std.function") || olua_isnil(L, 2))) {
            // std::function<void (cocos2d::ui::EditBox *)> onReturn
            return _olua_fun_cocos2d_ui_LuaEditBoxDelegate_onReturn$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::LuaEditBoxDelegate::onReturn' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_LuaEditBoxDelegate_onTextChanged$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LuaEditBoxDelegate *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.LuaEditBoxDelegate");

    void *cb_store = (void *)self;
    std::string cb_tag = "onTextChanged";
    olua_getcallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_EQUAL);

    // std::function<void (cocos2d::ui::EditBox *, const std::string &)> onTextChanged
    std::function<void (cocos2d::ui::EditBox *, const std::string &)> ret = self->onTextChanged;
    int num_ret = olua_push_callback(L, &ret, "std.function");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_LuaEditBoxDelegate_onTextChanged$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LuaEditBoxDelegate *self = nullptr;
    std::function<void (cocos2d::ui::EditBox *, const std::string &)> arg1;       /** onTextChanged */

    olua_to_object(L, 1, &self, "ccui.LuaEditBoxDelegate");
    if (!olua_isnoneornil(L, 2)) {
        olua_check_callback(L, 2, &arg1, "std.function");
    }

    void *cb_store = (void *)self;
    std::string cb_tag = "onTextChanged";
    std::string cb_name;
    if (olua_isfunction(L, 2)) {
        cb_name = olua_setcallback(L, cb_store, 2, cb_tag.c_str(), OLUA_TAG_REPLACE);
        olua_Context cb_ctx = olua_context(L);
        // lua_State *ML = olua_mainthread(L);
        arg1 = [cb_store, cb_name, cb_ctx /*, ML */](cocos2d::ui::EditBox *cb_arg1, const std::string &cb_arg2) {
            lua_State *L = olua_mainthread(NULL);
            olua_checkhostthread();

            if (olua_contextequal(L, cb_ctx)) {
                int top = lua_gettop(L);
                size_t last = olua_push_objpool(L);
                olua_enable_objpool(L);
                olua_push_object(L, cb_arg1, "ccui.EditBox");
                olua_push_string(L, cb_arg2);
                olua_disable_objpool(L);

                olua_callback(L, cb_store, cb_name.c_str(), 2);

                //pop stack value
                olua_pop_objpool(L, last);
                lua_settop(L, top);
            }
        };
    } else {
        olua_removecallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_EQUAL);
        arg1 = nullptr;
    }

    // std::function<void (cocos2d::ui::EditBox *, const std::string &)> onTextChanged
    self->onTextChanged = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_LuaEditBoxDelegate_onTextChanged(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // std::function<void (cocos2d::ui::EditBox *, const std::string &)> onTextChanged
        return _olua_fun_cocos2d_ui_LuaEditBoxDelegate_onTextChanged$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccui.LuaEditBoxDelegate")) && (olua_is_callback(L, 2, "std.function") || olua_isnil(L, 2))) {
            // std::function<void (cocos2d::ui::EditBox *, const std::string &)> onTextChanged
            return _olua_fun_cocos2d_ui_LuaEditBoxDelegate_onTextChanged$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::LuaEditBoxDelegate::onTextChanged' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_ccui_LuaEditBoxDelegate(lua_State *L)
{
    oluacls_class<cocos2d::ui::LuaEditBoxDelegate, cocos2d::ui::EditBoxDelegate>(L, "ccui.LuaEditBoxDelegate");
    oluacls_func(L, "new", _olua_fun_cocos2d_ui_LuaEditBoxDelegate_new);
    oluacls_prop(L, "onEditingDidBegin", _olua_fun_cocos2d_ui_LuaEditBoxDelegate_onEditingDidBegin, _olua_fun_cocos2d_ui_LuaEditBoxDelegate_onEditingDidBegin);
    oluacls_prop(L, "onTextChanged", _olua_fun_cocos2d_ui_LuaEditBoxDelegate_onTextChanged, _olua_fun_cocos2d_ui_LuaEditBoxDelegate_onTextChanged);
    oluacls_prop(L, "onReturn", _olua_fun_cocos2d_ui_LuaEditBoxDelegate_onReturn, _olua_fun_cocos2d_ui_LuaEditBoxDelegate_onReturn);
    oluacls_prop(L, "onEditingDidEndWithAction", _olua_fun_cocos2d_ui_LuaEditBoxDelegate_onEditingDidEndWithAction, _olua_fun_cocos2d_ui_LuaEditBoxDelegate_onEditingDidEndWithAction);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_LuaEditBoxDelegate(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.LuaEditBoxDelegate")) {
        luaL_error(L, "class not found: cocos2d::ui::LuaEditBoxDelegate");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_ccui_EditBox_KeyboardReturnType(lua_State *L)
{
    oluacls_class<cocos2d::ui::EditBox::KeyboardReturnType>(L, "ccui.EditBox.KeyboardReturnType");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "DEFAULT", (lua_Integer)cocos2d::ui::EditBox::KeyboardReturnType::DEFAULT);
    oluacls_enum(L, "DONE", (lua_Integer)cocos2d::ui::EditBox::KeyboardReturnType::DONE);
    oluacls_enum(L, "GO", (lua_Integer)cocos2d::ui::EditBox::KeyboardReturnType::GO);
    oluacls_enum(L, "NEXT", (lua_Integer)cocos2d::ui::EditBox::KeyboardReturnType::NEXT);
    oluacls_enum(L, "SEARCH", (lua_Integer)cocos2d::ui::EditBox::KeyboardReturnType::SEARCH);
    oluacls_enum(L, "SEND", (lua_Integer)cocos2d::ui::EditBox::KeyboardReturnType::SEND);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_EditBox_KeyboardReturnType(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.EditBox.KeyboardReturnType")) {
        luaL_error(L, "class not found: cocos2d::ui::EditBox::KeyboardReturnType");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_ccui_EditBox_InputMode(lua_State *L)
{
    oluacls_class<cocos2d::ui::EditBox::InputMode>(L, "ccui.EditBox.InputMode");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "ANY", (lua_Integer)cocos2d::ui::EditBox::InputMode::ANY);
    oluacls_enum(L, "DECIMAL", (lua_Integer)cocos2d::ui::EditBox::InputMode::DECIMAL);
    oluacls_enum(L, "EMAIL_ADDRESS", (lua_Integer)cocos2d::ui::EditBox::InputMode::EMAIL_ADDRESS);
    oluacls_enum(L, "NUMERIC", (lua_Integer)cocos2d::ui::EditBox::InputMode::NUMERIC);
    oluacls_enum(L, "PHONE_NUMBER", (lua_Integer)cocos2d::ui::EditBox::InputMode::PHONE_NUMBER);
    oluacls_enum(L, "SINGLE_LINE", (lua_Integer)cocos2d::ui::EditBox::InputMode::SINGLE_LINE);
    oluacls_enum(L, "URL", (lua_Integer)cocos2d::ui::EditBox::InputMode::URL);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_EditBox_InputMode(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.EditBox.InputMode")) {
        luaL_error(L, "class not found: cocos2d::ui::EditBox::InputMode");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_ccui_EditBox_InputFlag(lua_State *L)
{
    oluacls_class<cocos2d::ui::EditBox::InputFlag>(L, "ccui.EditBox.InputFlag");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "INITIAL_CAPS_ALL_CHARACTERS", (lua_Integer)cocos2d::ui::EditBox::InputFlag::INITIAL_CAPS_ALL_CHARACTERS);
    oluacls_enum(L, "INITIAL_CAPS_SENTENCE", (lua_Integer)cocos2d::ui::EditBox::InputFlag::INITIAL_CAPS_SENTENCE);
    oluacls_enum(L, "INITIAL_CAPS_WORD", (lua_Integer)cocos2d::ui::EditBox::InputFlag::INITIAL_CAPS_WORD);
    oluacls_enum(L, "LOWERCASE_ALL_CHARACTERS", (lua_Integer)cocos2d::ui::EditBox::InputFlag::LOWERCASE_ALL_CHARACTERS);
    oluacls_enum(L, "PASSWORD", (lua_Integer)cocos2d::ui::EditBox::InputFlag::PASSWORD);
    oluacls_enum(L, "SENSITIVE", (lua_Integer)cocos2d::ui::EditBox::InputFlag::SENSITIVE);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_EditBox_InputFlag(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.EditBox.InputFlag")) {
        luaL_error(L, "class not found: cocos2d::ui::EditBox::InputFlag");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_ui_EditBox_as(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    const char *arg1 = nullptr;       /** cls */

    olua_to_object(L, 1, &self, "ccui.EditBox");
    olua_check_string(L, 2, &arg1);

    do {
        if (olua_isa(L, 1, arg1)) {
            lua_pushvalue(L, 1);
            break;
        }
        if (olua_strequal(arg1, "cc.IMEDelegate")) {
            olua_pushobj_as<cocos2d::IMEDelegate>(L, 1, self, "as.cc.IMEDelegate");
            break;
        }
        if (olua_strequal(arg1, "ccui.LayoutParameterProtocol")) {
            olua_pushobj_as<cocos2d::ui::LayoutParameterProtocol>(L, 1, self, "as.ccui.LayoutParameterProtocol");
            break;
        }

        luaL_error(L, "'cocos2d::ui::EditBox' can't cast to '%s'", arg1);
    } while (0);

    olua_endinvoke(L);

    return 1;
}

static int _olua_fun_cocos2d_ui_EditBox_attachWithIME(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.EditBox");

    // @copyfrom(cocos2d::IMEDelegate) bool attachWithIME()
    bool ret = self->attachWithIME();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_EditBox_create$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size *arg1;       /** size */
    cocos2d::ui::Scale9Sprite *arg2 = nullptr;       /** normalSprite */
    cocos2d::ui::Scale9Sprite *arg3 = nullptr;       /** pressedSprite */
    cocos2d::ui::Scale9Sprite *arg4 = nullptr;       /** disabledSprite */

    olua_check_object(L, 1, &arg1, "cc.Size");
    olua_check_object(L, 2, &arg2, "ccui.Scale9Sprite");
    olua_check_object(L, 3, &arg3, "ccui.Scale9Sprite");
    olua_check_object(L, 4, &arg4, "ccui.Scale9Sprite");

    // static cocos2d::ui::EditBox *create(const cocos2d::Size &size, cocos2d::ui::Scale9Sprite *normalSprite, @optional cocos2d::ui::Scale9Sprite *pressedSprite, @optional cocos2d::ui::Scale9Sprite *disabledSprite)
    cocos2d::ui::EditBox *ret = cocos2d::ui::EditBox::create(*arg1, arg2, arg3, arg4);
    int num_ret = olua_push_object(L, ret, "ccui.EditBox");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_EditBox_create$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size *arg1;       /** size */
    cocos2d::ui::Scale9Sprite *arg2 = nullptr;       /** normalSprite */

    olua_check_object(L, 1, &arg1, "cc.Size");
    olua_check_object(L, 2, &arg2, "ccui.Scale9Sprite");

    // static cocos2d::ui::EditBox *create(const cocos2d::Size &size, cocos2d::ui::Scale9Sprite *normalSprite)
    cocos2d::ui::EditBox *ret = cocos2d::ui::EditBox::create(*arg1, arg2);
    int num_ret = olua_push_object(L, ret, "ccui.EditBox");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_EditBox_create$3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size *arg1;       /** size */
    cocos2d::ui::Scale9Sprite *arg2 = nullptr;       /** normalSprite */
    cocos2d::ui::Scale9Sprite *arg3 = nullptr;       /** pressedSprite */

    olua_check_object(L, 1, &arg1, "cc.Size");
    olua_check_object(L, 2, &arg2, "ccui.Scale9Sprite");
    olua_check_object(L, 3, &arg3, "ccui.Scale9Sprite");

    // static cocos2d::ui::EditBox *create(const cocos2d::Size &size, cocos2d::ui::Scale9Sprite *normalSprite, @optional cocos2d::ui::Scale9Sprite *pressedSprite)
    cocos2d::ui::EditBox *ret = cocos2d::ui::EditBox::create(*arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "ccui.EditBox");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_EditBox_create$4(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size *arg1;       /** size */
    std::string arg2;       /** normalImage */
    cocos2d::ui::Widget::TextureResType arg3 = (cocos2d::ui::Widget::TextureResType)0;       /** texType */

    olua_check_object(L, 1, &arg1, "cc.Size");
    olua_check_string(L, 2, &arg2);
    olua_check_enum(L, 3, &arg3);

    // static cocos2d::ui::EditBox *create(const cocos2d::Size &size, const std::string &normalImage, cocos2d::ui::Widget::TextureResType texType)
    cocos2d::ui::EditBox *ret = cocos2d::ui::EditBox::create(*arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "ccui.EditBox");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_EditBox_create$5(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size *arg1;       /** size */
    std::string arg2;       /** normalImage */
    std::string arg3;       /** pressedImage */
    std::string arg4;       /** disabledImage */
    cocos2d::ui::Widget::TextureResType arg5 = (cocos2d::ui::Widget::TextureResType)0;       /** texType */

    olua_check_object(L, 1, &arg1, "cc.Size");
    olua_check_string(L, 2, &arg2);
    olua_check_string(L, 3, &arg3);
    olua_check_string(L, 4, &arg4);
    olua_check_enum(L, 5, &arg5);

    // static cocos2d::ui::EditBox *create(const cocos2d::Size &size, const std::string &normalImage, @optional const std::string &pressedImage, @optional const std::string &disabledImage, @optional cocos2d::ui::Widget::TextureResType texType)
    cocos2d::ui::EditBox *ret = cocos2d::ui::EditBox::create(*arg1, arg2, arg3, arg4, arg5);
    int num_ret = olua_push_object(L, ret, "ccui.EditBox");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_EditBox_create$6(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size *arg1;       /** size */
    std::string arg2;       /** normalImage */

    olua_check_object(L, 1, &arg1, "cc.Size");
    olua_check_string(L, 2, &arg2);

    // static cocos2d::ui::EditBox *create(const cocos2d::Size &size, const std::string &normalImage)
    cocos2d::ui::EditBox *ret = cocos2d::ui::EditBox::create(*arg1, arg2);
    int num_ret = olua_push_object(L, ret, "ccui.EditBox");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_EditBox_create$7(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size *arg1;       /** size */
    std::string arg2;       /** normalImage */
    std::string arg3;       /** pressedImage */

    olua_check_object(L, 1, &arg1, "cc.Size");
    olua_check_string(L, 2, &arg2);
    olua_check_string(L, 3, &arg3);

    // static cocos2d::ui::EditBox *create(const cocos2d::Size &size, const std::string &normalImage, @optional const std::string &pressedImage)
    cocos2d::ui::EditBox *ret = cocos2d::ui::EditBox::create(*arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "ccui.EditBox");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_EditBox_create$8(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size *arg1;       /** size */
    std::string arg2;       /** normalImage */
    std::string arg3;       /** pressedImage */
    std::string arg4;       /** disabledImage */

    olua_check_object(L, 1, &arg1, "cc.Size");
    olua_check_string(L, 2, &arg2);
    olua_check_string(L, 3, &arg3);
    olua_check_string(L, 4, &arg4);

    // static cocos2d::ui::EditBox *create(const cocos2d::Size &size, const std::string &normalImage, @optional const std::string &pressedImage, @optional const std::string &disabledImage)
    cocos2d::ui::EditBox *ret = cocos2d::ui::EditBox::create(*arg1, arg2, arg3, arg4);
    int num_ret = olua_push_object(L, ret, "ccui.EditBox");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_EditBox_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        if ((olua_is_object(L, 1, "cc.Size")) && (olua_is_object(L, 2, "ccui.Scale9Sprite"))) {
            // static cocos2d::ui::EditBox *create(const cocos2d::Size &size, cocos2d::ui::Scale9Sprite *normalSprite)
            return _olua_fun_cocos2d_ui_EditBox_create$2(L);
        }

        // if ((olua_is_object(L, 1, "cc.Size")) && (olua_is_string(L, 2))) {
            // static cocos2d::ui::EditBox *create(const cocos2d::Size &size, const std::string &normalImage)
            return _olua_fun_cocos2d_ui_EditBox_create$6(L);
        // }
    }

    if (num_args == 3) {
        if ((olua_is_object(L, 1, "cc.Size")) && (olua_is_object(L, 2, "ccui.Scale9Sprite")) && (olua_is_object(L, 3, "ccui.Scale9Sprite"))) {
            // static cocos2d::ui::EditBox *create(const cocos2d::Size &size, cocos2d::ui::Scale9Sprite *normalSprite, @optional cocos2d::ui::Scale9Sprite *pressedSprite)
            return _olua_fun_cocos2d_ui_EditBox_create$3(L);
        }

        if ((olua_is_object(L, 1, "cc.Size")) && (olua_is_string(L, 2)) && (olua_is_enum(L, 3))) {
            // static cocos2d::ui::EditBox *create(const cocos2d::Size &size, const std::string &normalImage, cocos2d::ui::Widget::TextureResType texType)
            return _olua_fun_cocos2d_ui_EditBox_create$4(L);
        }

        // if ((olua_is_object(L, 1, "cc.Size")) && (olua_is_string(L, 2)) && (olua_is_string(L, 3))) {
            // static cocos2d::ui::EditBox *create(const cocos2d::Size &size, const std::string &normalImage, @optional const std::string &pressedImage)
            return _olua_fun_cocos2d_ui_EditBox_create$7(L);
        // }
    }

    if (num_args == 4) {
        if ((olua_is_object(L, 1, "cc.Size")) && (olua_is_object(L, 2, "ccui.Scale9Sprite")) && (olua_is_object(L, 3, "ccui.Scale9Sprite")) && (olua_is_object(L, 4, "ccui.Scale9Sprite"))) {
            // static cocos2d::ui::EditBox *create(const cocos2d::Size &size, cocos2d::ui::Scale9Sprite *normalSprite, @optional cocos2d::ui::Scale9Sprite *pressedSprite, @optional cocos2d::ui::Scale9Sprite *disabledSprite)
            return _olua_fun_cocos2d_ui_EditBox_create$1(L);
        }

        // if ((olua_is_object(L, 1, "cc.Size")) && (olua_is_string(L, 2)) && (olua_is_string(L, 3)) && (olua_is_string(L, 4))) {
            // static cocos2d::ui::EditBox *create(const cocos2d::Size &size, const std::string &normalImage, @optional const std::string &pressedImage, @optional const std::string &disabledImage)
            return _olua_fun_cocos2d_ui_EditBox_create$8(L);
        // }
    }

    if (num_args == 5) {
        // if ((olua_is_object(L, 1, "cc.Size")) && (olua_is_string(L, 2)) && (olua_is_string(L, 3)) && (olua_is_string(L, 4)) && (olua_is_enum(L, 5))) {
            // static cocos2d::ui::EditBox *create(const cocos2d::Size &size, const std::string &normalImage, @optional const std::string &pressedImage, @optional const std::string &disabledImage, @optional cocos2d::ui::Widget::TextureResType texType)
            return _olua_fun_cocos2d_ui_EditBox_create$5(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::EditBox::create' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_EditBox_detachWithIME(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.EditBox");

    // @copyfrom(cocos2d::IMEDelegate) bool detachWithIME()
    bool ret = self->detachWithIME();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_EditBox_getCapInsetsDisabledRenderer(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.EditBox");

    // const cocos2d::Rect &getCapInsetsDisabledRenderer()
    const cocos2d::Rect &ret = self->getCapInsetsDisabledRenderer();
    int num_ret = olua_push_object(L, ret, "cc.Rect");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_EditBox_getCapInsetsNormalRenderer(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.EditBox");

    // const cocos2d::Rect &getCapInsetsNormalRenderer()
    const cocos2d::Rect &ret = self->getCapInsetsNormalRenderer();
    int num_ret = olua_push_object(L, ret, "cc.Rect");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_EditBox_getCapInsetsPressedRenderer(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.EditBox");

    // const cocos2d::Rect &getCapInsetsPressedRenderer()
    const cocos2d::Rect &ret = self->getCapInsetsPressedRenderer();
    int num_ret = olua_push_object(L, ret, "cc.Rect");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_EditBox_getDelegate(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.EditBox");

    // @addref(delegate ^) cocos2d::ui::EditBoxDelegate *getDelegate()
    cocos2d::ui::EditBoxDelegate *ret = self->getDelegate();
    int num_ret = olua_push_object(L, ret, "ccui.EditBoxDelegate");

    // insert code after call
    olua_addref(L, 1, "delegate", -1, OLUA_REF_ALONE);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_EditBox_getFontColor(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.EditBox");

    // const cocos2d::Color4B &getFontColor()
    const cocos2d::Color4B &ret = self->getFontColor();
    int num_ret = olua_push_cocos2d_Color4B(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_EditBox_getFontName(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.EditBox");

    // const char *getFontName()
    const char *ret = self->getFontName();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_EditBox_getFontSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.EditBox");

    // int getFontSize()
    int ret = self->getFontSize();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_EditBox_getInputFlag(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.EditBox");

    // cocos2d::ui::EditBox::InputFlag getInputFlag()
    cocos2d::ui::EditBox::InputFlag ret = self->getInputFlag();
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_EditBox_getInputMode(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.EditBox");

    // cocos2d::ui::EditBox::InputMode getInputMode()
    cocos2d::ui::EditBox::InputMode ret = self->getInputMode();
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_EditBox_getMaxLength(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.EditBox");

    // int getMaxLength()
    int ret = self->getMaxLength();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_EditBox_getPlaceHolder(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.EditBox");

    // const char *getPlaceHolder()
    const char *ret = self->getPlaceHolder();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_EditBox_getPlaceholderFontColor(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.EditBox");

    // const cocos2d::Color4B &getPlaceholderFontColor()
    const cocos2d::Color4B &ret = self->getPlaceholderFontColor();
    int num_ret = olua_push_cocos2d_Color4B(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_EditBox_getPlaceholderFontName(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.EditBox");

    // const char *getPlaceholderFontName()
    const char *ret = self->getPlaceholderFontName();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_EditBox_getPlaceholderFontSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.EditBox");

    // int getPlaceholderFontSize()
    int ret = self->getPlaceholderFontSize();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_EditBox_getReturnType(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.EditBox");

    // cocos2d::ui::EditBox::KeyboardReturnType getReturnType()
    cocos2d::ui::EditBox::KeyboardReturnType ret = self->getReturnType();
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_EditBox_getText(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.EditBox");

    // const char *getText()
    const char *ret = self->getText();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_EditBox_getTextHorizontalAlignment(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.EditBox");

    // cocos2d::TextHAlignment getTextHorizontalAlignment()
    cocos2d::TextHAlignment ret = self->getTextHorizontalAlignment();
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_EditBox_initWithSizeAndBackgroundSprite$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    cocos2d::Size *arg1;       /** size */
    std::string arg2;       /** normal9SpriteBg */
    cocos2d::ui::Widget::TextureResType arg3 = (cocos2d::ui::Widget::TextureResType)0;       /** texType */

    olua_to_object(L, 1, &self, "ccui.EditBox");
    olua_check_object(L, 2, &arg1, "cc.Size");
    olua_check_string(L, 3, &arg2);
    olua_check_enum(L, 4, &arg3);

    // bool initWithSizeAndBackgroundSprite(const cocos2d::Size &size, const std::string &normal9SpriteBg, @optional cocos2d::ui::Widget::TextureResType texType)
    bool ret = self->initWithSizeAndBackgroundSprite(*arg1, arg2, arg3);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_EditBox_initWithSizeAndBackgroundSprite$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    cocos2d::Size *arg1;       /** size */
    std::string arg2;       /** normal9SpriteBg */

    olua_to_object(L, 1, &self, "ccui.EditBox");
    olua_check_object(L, 2, &arg1, "cc.Size");
    olua_check_string(L, 3, &arg2);

    // bool initWithSizeAndBackgroundSprite(const cocos2d::Size &size, const std::string &normal9SpriteBg)
    bool ret = self->initWithSizeAndBackgroundSprite(*arg1, arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_EditBox_initWithSizeAndBackgroundSprite$3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    cocos2d::Size *arg1;       /** size */
    cocos2d::ui::Scale9Sprite *arg2 = nullptr;       /** normal9SpriteBg */

    olua_to_object(L, 1, &self, "ccui.EditBox");
    olua_check_object(L, 2, &arg1, "cc.Size");
    olua_check_object(L, 3, &arg2, "ccui.Scale9Sprite");

    // bool initWithSizeAndBackgroundSprite(const cocos2d::Size &size, cocos2d::ui::Scale9Sprite *normal9SpriteBg)
    bool ret = self->initWithSizeAndBackgroundSprite(*arg1, arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_EditBox_initWithSizeAndBackgroundSprite$4(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    cocos2d::Size *arg1;       /** size */
    cocos2d::ui::Scale9Sprite *arg2 = nullptr;       /** normalSprite */
    cocos2d::ui::Scale9Sprite *arg3 = nullptr;       /** pressedSprite */
    cocos2d::ui::Scale9Sprite *arg4 = nullptr;       /** disabledSprite */

    olua_to_object(L, 1, &self, "ccui.EditBox");
    olua_check_object(L, 2, &arg1, "cc.Size");
    olua_check_object(L, 3, &arg2, "ccui.Scale9Sprite");
    olua_check_object(L, 4, &arg3, "ccui.Scale9Sprite");
    olua_check_object(L, 5, &arg4, "ccui.Scale9Sprite");

    // bool initWithSizeAndBackgroundSprite(const cocos2d::Size &size, cocos2d::ui::Scale9Sprite *normalSprite, cocos2d::ui::Scale9Sprite *pressedSprite, cocos2d::ui::Scale9Sprite *disabledSprite)
    bool ret = self->initWithSizeAndBackgroundSprite(*arg1, arg2, arg3, arg4);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_EditBox_initWithSizeAndBackgroundSprite(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 3) {
        if ((olua_is_object(L, 1, "ccui.EditBox")) && (olua_is_object(L, 2, "cc.Size")) && (olua_is_string(L, 3))) {
            // bool initWithSizeAndBackgroundSprite(const cocos2d::Size &size, const std::string &normal9SpriteBg)
            return _olua_fun_cocos2d_ui_EditBox_initWithSizeAndBackgroundSprite$2(L);
        }

        // if ((olua_is_object(L, 1, "ccui.EditBox")) && (olua_is_object(L, 2, "cc.Size")) && (olua_is_object(L, 3, "ccui.Scale9Sprite"))) {
            // bool initWithSizeAndBackgroundSprite(const cocos2d::Size &size, cocos2d::ui::Scale9Sprite *normal9SpriteBg)
            return _olua_fun_cocos2d_ui_EditBox_initWithSizeAndBackgroundSprite$3(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_object(L, 1, "ccui.EditBox")) && (olua_is_object(L, 2, "cc.Size")) && (olua_is_string(L, 3)) && (olua_is_enum(L, 4))) {
            // bool initWithSizeAndBackgroundSprite(const cocos2d::Size &size, const std::string &normal9SpriteBg, @optional cocos2d::ui::Widget::TextureResType texType)
            return _olua_fun_cocos2d_ui_EditBox_initWithSizeAndBackgroundSprite$1(L);
        // }
    }

    if (num_args == 5) {
        // if ((olua_is_object(L, 1, "ccui.EditBox")) && (olua_is_object(L, 2, "cc.Size")) && (olua_is_object(L, 3, "ccui.Scale9Sprite")) && (olua_is_object(L, 4, "ccui.Scale9Sprite")) && (olua_is_object(L, 5, "ccui.Scale9Sprite"))) {
            // bool initWithSizeAndBackgroundSprite(const cocos2d::Size &size, cocos2d::ui::Scale9Sprite *normalSprite, cocos2d::ui::Scale9Sprite *pressedSprite, cocos2d::ui::Scale9Sprite *disabledSprite)
            return _olua_fun_cocos2d_ui_EditBox_initWithSizeAndBackgroundSprite$4(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::EditBox::initWithSizeAndBackgroundSprite' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_EditBox_initWithSizeAndTexture$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    cocos2d::Size *arg1;       /** size */
    std::string arg2;       /** normalImage */
    std::string arg3;       /** pressedImage */
    std::string arg4;       /** disabledImage */
    cocos2d::ui::Widget::TextureResType arg5 = (cocos2d::ui::Widget::TextureResType)0;       /** texType */

    olua_to_object(L, 1, &self, "ccui.EditBox");
    olua_check_object(L, 2, &arg1, "cc.Size");
    olua_check_string(L, 3, &arg2);
    olua_check_string(L, 4, &arg3);
    olua_check_string(L, 5, &arg4);
    olua_check_enum(L, 6, &arg5);

    // bool initWithSizeAndTexture(const cocos2d::Size &size, const std::string &normalImage, @optional const std::string &pressedImage, @optional const std::string &disabledImage, @optional cocos2d::ui::Widget::TextureResType texType)
    bool ret = self->initWithSizeAndTexture(*arg1, arg2, arg3, arg4, arg5);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_EditBox_initWithSizeAndTexture$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    cocos2d::Size *arg1;       /** size */
    std::string arg2;       /** normalImage */

    olua_to_object(L, 1, &self, "ccui.EditBox");
    olua_check_object(L, 2, &arg1, "cc.Size");
    olua_check_string(L, 3, &arg2);

    // bool initWithSizeAndTexture(const cocos2d::Size &size, const std::string &normalImage)
    bool ret = self->initWithSizeAndTexture(*arg1, arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_EditBox_initWithSizeAndTexture$3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    cocos2d::Size *arg1;       /** size */
    std::string arg2;       /** normalImage */
    std::string arg3;       /** pressedImage */

    olua_to_object(L, 1, &self, "ccui.EditBox");
    olua_check_object(L, 2, &arg1, "cc.Size");
    olua_check_string(L, 3, &arg2);
    olua_check_string(L, 4, &arg3);

    // bool initWithSizeAndTexture(const cocos2d::Size &size, const std::string &normalImage, @optional const std::string &pressedImage)
    bool ret = self->initWithSizeAndTexture(*arg1, arg2, arg3);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_EditBox_initWithSizeAndTexture$4(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    cocos2d::Size *arg1;       /** size */
    std::string arg2;       /** normalImage */
    std::string arg3;       /** pressedImage */
    std::string arg4;       /** disabledImage */

    olua_to_object(L, 1, &self, "ccui.EditBox");
    olua_check_object(L, 2, &arg1, "cc.Size");
    olua_check_string(L, 3, &arg2);
    olua_check_string(L, 4, &arg3);
    olua_check_string(L, 5, &arg4);

    // bool initWithSizeAndTexture(const cocos2d::Size &size, const std::string &normalImage, @optional const std::string &pressedImage, @optional const std::string &disabledImage)
    bool ret = self->initWithSizeAndTexture(*arg1, arg2, arg3, arg4);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_EditBox_initWithSizeAndTexture(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "ccui.EditBox")) && (olua_is_object(L, 2, "cc.Size")) && (olua_is_string(L, 3))) {
            // bool initWithSizeAndTexture(const cocos2d::Size &size, const std::string &normalImage)
            return _olua_fun_cocos2d_ui_EditBox_initWithSizeAndTexture$2(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_object(L, 1, "ccui.EditBox")) && (olua_is_object(L, 2, "cc.Size")) && (olua_is_string(L, 3)) && (olua_is_string(L, 4))) {
            // bool initWithSizeAndTexture(const cocos2d::Size &size, const std::string &normalImage, @optional const std::string &pressedImage)
            return _olua_fun_cocos2d_ui_EditBox_initWithSizeAndTexture$3(L);
        // }
    }

    if (num_args == 5) {
        // if ((olua_is_object(L, 1, "ccui.EditBox")) && (olua_is_object(L, 2, "cc.Size")) && (olua_is_string(L, 3)) && (olua_is_string(L, 4)) && (olua_is_string(L, 5))) {
            // bool initWithSizeAndTexture(const cocos2d::Size &size, const std::string &normalImage, @optional const std::string &pressedImage, @optional const std::string &disabledImage)
            return _olua_fun_cocos2d_ui_EditBox_initWithSizeAndTexture$4(L);
        // }
    }

    if (num_args == 6) {
        // if ((olua_is_object(L, 1, "ccui.EditBox")) && (olua_is_object(L, 2, "cc.Size")) && (olua_is_string(L, 3)) && (olua_is_string(L, 4)) && (olua_is_string(L, 5)) && (olua_is_enum(L, 6))) {
            // bool initWithSizeAndTexture(const cocos2d::Size &size, const std::string &normalImage, @optional const std::string &pressedImage, @optional const std::string &disabledImage, @optional cocos2d::ui::Widget::TextureResType texType)
            return _olua_fun_cocos2d_ui_EditBox_initWithSizeAndTexture$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::EditBox::initWithSizeAndTexture' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_EditBox_loadTextureDisabled$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    std::string arg1;       /** disabled */
    cocos2d::ui::Widget::TextureResType arg2 = (cocos2d::ui::Widget::TextureResType)0;       /** texType */

    olua_to_object(L, 1, &self, "ccui.EditBox");
    olua_check_string(L, 2, &arg1);
    olua_check_enum(L, 3, &arg2);

    // void loadTextureDisabled(const std::string &disabled, @optional cocos2d::ui::Widget::TextureResType texType)
    self->loadTextureDisabled(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_EditBox_loadTextureDisabled$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    std::string arg1;       /** disabled */

    olua_to_object(L, 1, &self, "ccui.EditBox");
    olua_check_string(L, 2, &arg1);

    // void loadTextureDisabled(const std::string &disabled)
    self->loadTextureDisabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_EditBox_loadTextureDisabled(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccui.EditBox")) && (olua_is_string(L, 2))) {
            // void loadTextureDisabled(const std::string &disabled)
            return _olua_fun_cocos2d_ui_EditBox_loadTextureDisabled$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "ccui.EditBox")) && (olua_is_string(L, 2)) && (olua_is_enum(L, 3))) {
            // void loadTextureDisabled(const std::string &disabled, @optional cocos2d::ui::Widget::TextureResType texType)
            return _olua_fun_cocos2d_ui_EditBox_loadTextureDisabled$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::EditBox::loadTextureDisabled' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_EditBox_loadTextureNormal$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    std::string arg1;       /** normal */
    cocos2d::ui::Widget::TextureResType arg2 = (cocos2d::ui::Widget::TextureResType)0;       /** texType */

    olua_to_object(L, 1, &self, "ccui.EditBox");
    olua_check_string(L, 2, &arg1);
    olua_check_enum(L, 3, &arg2);

    // void loadTextureNormal(const std::string &normal, @optional cocos2d::ui::Widget::TextureResType texType)
    self->loadTextureNormal(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_EditBox_loadTextureNormal$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    std::string arg1;       /** normal */

    olua_to_object(L, 1, &self, "ccui.EditBox");
    olua_check_string(L, 2, &arg1);

    // void loadTextureNormal(const std::string &normal)
    self->loadTextureNormal(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_EditBox_loadTextureNormal(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccui.EditBox")) && (olua_is_string(L, 2))) {
            // void loadTextureNormal(const std::string &normal)
            return _olua_fun_cocos2d_ui_EditBox_loadTextureNormal$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "ccui.EditBox")) && (olua_is_string(L, 2)) && (olua_is_enum(L, 3))) {
            // void loadTextureNormal(const std::string &normal, @optional cocos2d::ui::Widget::TextureResType texType)
            return _olua_fun_cocos2d_ui_EditBox_loadTextureNormal$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::EditBox::loadTextureNormal' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_EditBox_loadTexturePressed$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    std::string arg1;       /** pressed */
    cocos2d::ui::Widget::TextureResType arg2 = (cocos2d::ui::Widget::TextureResType)0;       /** texType */

    olua_to_object(L, 1, &self, "ccui.EditBox");
    olua_check_string(L, 2, &arg1);
    olua_check_enum(L, 3, &arg2);

    // void loadTexturePressed(const std::string &pressed, @optional cocos2d::ui::Widget::TextureResType texType)
    self->loadTexturePressed(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_EditBox_loadTexturePressed$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    std::string arg1;       /** pressed */

    olua_to_object(L, 1, &self, "ccui.EditBox");
    olua_check_string(L, 2, &arg1);

    // void loadTexturePressed(const std::string &pressed)
    self->loadTexturePressed(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_EditBox_loadTexturePressed(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccui.EditBox")) && (olua_is_string(L, 2))) {
            // void loadTexturePressed(const std::string &pressed)
            return _olua_fun_cocos2d_ui_EditBox_loadTexturePressed$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "ccui.EditBox")) && (olua_is_string(L, 2)) && (olua_is_enum(L, 3))) {
            // void loadTexturePressed(const std::string &pressed, @optional cocos2d::ui::Widget::TextureResType texType)
            return _olua_fun_cocos2d_ui_EditBox_loadTexturePressed$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::EditBox::loadTexturePressed' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_EditBox_loadTextures$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    std::string arg1;       /** normal */
    std::string arg2;       /** pressed */
    std::string arg3;       /** disabled */
    cocos2d::ui::Widget::TextureResType arg4 = (cocos2d::ui::Widget::TextureResType)0;       /** texType */

    olua_to_object(L, 1, &self, "ccui.EditBox");
    olua_check_string(L, 2, &arg1);
    olua_check_string(L, 3, &arg2);
    olua_check_string(L, 4, &arg3);
    olua_check_enum(L, 5, &arg4);

    // void loadTextures(const std::string &normal, const std::string &pressed, @optional const std::string &disabled, @optional cocos2d::ui::Widget::TextureResType texType)
    self->loadTextures(arg1, arg2, arg3, arg4);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_EditBox_loadTextures$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    std::string arg1;       /** normal */
    std::string arg2;       /** pressed */

    olua_to_object(L, 1, &self, "ccui.EditBox");
    olua_check_string(L, 2, &arg1);
    olua_check_string(L, 3, &arg2);

    // void loadTextures(const std::string &normal, const std::string &pressed)
    self->loadTextures(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_EditBox_loadTextures$3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    std::string arg1;       /** normal */
    std::string arg2;       /** pressed */
    std::string arg3;       /** disabled */

    olua_to_object(L, 1, &self, "ccui.EditBox");
    olua_check_string(L, 2, &arg1);
    olua_check_string(L, 3, &arg2);
    olua_check_string(L, 4, &arg3);

    // void loadTextures(const std::string &normal, const std::string &pressed, @optional const std::string &disabled)
    self->loadTextures(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_EditBox_loadTextures(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "ccui.EditBox")) && (olua_is_string(L, 2)) && (olua_is_string(L, 3))) {
            // void loadTextures(const std::string &normal, const std::string &pressed)
            return _olua_fun_cocos2d_ui_EditBox_loadTextures$2(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_object(L, 1, "ccui.EditBox")) && (olua_is_string(L, 2)) && (olua_is_string(L, 3)) && (olua_is_string(L, 4))) {
            // void loadTextures(const std::string &normal, const std::string &pressed, @optional const std::string &disabled)
            return _olua_fun_cocos2d_ui_EditBox_loadTextures$3(L);
        // }
    }

    if (num_args == 5) {
        // if ((olua_is_object(L, 1, "ccui.EditBox")) && (olua_is_string(L, 2)) && (olua_is_string(L, 3)) && (olua_is_string(L, 4)) && (olua_is_enum(L, 5))) {
            // void loadTextures(const std::string &normal, const std::string &pressed, @optional const std::string &disabled, @optional cocos2d::ui::Widget::TextureResType texType)
            return _olua_fun_cocos2d_ui_EditBox_loadTextures$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::EditBox::loadTextures' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_EditBox_new(lua_State *L)
{
    olua_startinvoke(L);

    // cocos2d::ui::EditBox()
    cocos2d::ui::EditBox *ret = new cocos2d::ui::EditBox();
    int num_ret = olua_push_object(L, ret, "ccui.EditBox");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_EditBox_openKeyboard(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;

    olua_to_object(L, 1, &self, "ccui.EditBox");

    // void openKeyboard()
    self->openKeyboard();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_EditBox_setCapInsets(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    cocos2d::Rect *arg1;       /** capInsets */

    olua_to_object(L, 1, &self, "ccui.EditBox");
    olua_check_object(L, 2, &arg1, "cc.Rect");

    // void setCapInsets(const cocos2d::Rect &capInsets)
    self->setCapInsets(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_EditBox_setCapInsetsDisabledRenderer(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    cocos2d::Rect *arg1;       /** capInsets */

    olua_to_object(L, 1, &self, "ccui.EditBox");
    olua_check_object(L, 2, &arg1, "cc.Rect");

    // void setCapInsetsDisabledRenderer(const cocos2d::Rect &capInsets)
    self->setCapInsetsDisabledRenderer(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_EditBox_setCapInsetsNormalRenderer(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    cocos2d::Rect *arg1;       /** capInsets */

    olua_to_object(L, 1, &self, "ccui.EditBox");
    olua_check_object(L, 2, &arg1, "cc.Rect");

    // void setCapInsetsNormalRenderer(const cocos2d::Rect &capInsets)
    self->setCapInsetsNormalRenderer(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_EditBox_setCapInsetsPressedRenderer(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    cocos2d::Rect *arg1;       /** capInsets */

    olua_to_object(L, 1, &self, "ccui.EditBox");
    olua_check_object(L, 2, &arg1, "cc.Rect");

    // void setCapInsetsPressedRenderer(const cocos2d::Rect &capInsets)
    self->setCapInsetsPressedRenderer(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_EditBox_setDelegate(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    cocos2d::ui::EditBoxDelegate *arg1 = nullptr;       /** delegate */

    olua_to_object(L, 1, &self, "ccui.EditBox");
    olua_check_object(L, 2, &arg1, "ccui.EditBoxDelegate");

    // void setDelegate(@addref(delegate ^) cocos2d::ui::EditBoxDelegate *delegate)
    self->setDelegate(arg1);

    // insert code after call
    olua_addref(L, 1, "delegate", 2, OLUA_REF_ALONE);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_EditBox_setFont(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    const char *arg1 = nullptr;       /** pFontName */
    int arg2 = 0;       /** fontSize */

    olua_to_object(L, 1, &self, "ccui.EditBox");
    olua_check_string(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // void setFont(const char *pFontName, int fontSize)
    self->setFont(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_EditBox_setFontColor$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    cocos2d::Color3B arg1;       /** color */

    olua_to_object(L, 1, &self, "ccui.EditBox");
    olua_check_cocos2d_Color3B(L, 2, &arg1);

    // void setFontColor(const cocos2d::Color3B &color)
    self->setFontColor(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_EditBox_setFontColor$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    cocos2d::Color4B arg1;       /** color */

    olua_to_object(L, 1, &self, "ccui.EditBox");
    olua_check_cocos2d_Color4B(L, 2, &arg1);

    // void setFontColor(const cocos2d::Color4B &color)
    self->setFontColor(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_EditBox_setFontColor(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        if ((olua_is_object(L, 1, "ccui.EditBox")) && (olua_is_cocos2d_Color3B(L, 2))) {
            // void setFontColor(const cocos2d::Color3B &color)
            return _olua_fun_cocos2d_ui_EditBox_setFontColor$1(L);
        }

        // if ((olua_is_object(L, 1, "ccui.EditBox")) && (olua_is_cocos2d_Color4B(L, 2))) {
            // void setFontColor(const cocos2d::Color4B &color)
            return _olua_fun_cocos2d_ui_EditBox_setFontColor$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::EditBox::setFontColor' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_EditBox_setFontName(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    const char *arg1 = nullptr;       /** pFontName */

    olua_to_object(L, 1, &self, "ccui.EditBox");
    olua_check_string(L, 2, &arg1);

    // void setFontName(const char *pFontName)
    self->setFontName(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_EditBox_setFontSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    int arg1 = 0;       /** fontSize */

    olua_to_object(L, 1, &self, "ccui.EditBox");
    olua_check_integer(L, 2, &arg1);

    // void setFontSize(int fontSize)
    self->setFontSize(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_EditBox_setInputFlag(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    cocos2d::ui::EditBox::InputFlag arg1 = (cocos2d::ui::EditBox::InputFlag)0;       /** inputFlag */

    olua_to_object(L, 1, &self, "ccui.EditBox");
    olua_check_enum(L, 2, &arg1);

    // void setInputFlag(cocos2d::ui::EditBox::InputFlag inputFlag)
    self->setInputFlag(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_EditBox_setInputMode(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    cocos2d::ui::EditBox::InputMode arg1 = (cocos2d::ui::EditBox::InputMode)0;       /** inputMode */

    olua_to_object(L, 1, &self, "ccui.EditBox");
    olua_check_enum(L, 2, &arg1);

    // void setInputMode(cocos2d::ui::EditBox::InputMode inputMode)
    self->setInputMode(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_EditBox_setMaxLength(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    int arg1 = 0;       /** maxLength */

    olua_to_object(L, 1, &self, "ccui.EditBox");
    olua_check_integer(L, 2, &arg1);

    // void setMaxLength(int maxLength)
    self->setMaxLength(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_EditBox_setPlaceHolder(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    const char *arg1 = nullptr;       /** pText */

    olua_to_object(L, 1, &self, "ccui.EditBox");
    olua_check_string(L, 2, &arg1);

    // void setPlaceHolder(const char *pText)
    self->setPlaceHolder(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_EditBox_setPlaceholderFont(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    const char *arg1 = nullptr;       /** pFontName */
    int arg2 = 0;       /** fontSize */

    olua_to_object(L, 1, &self, "ccui.EditBox");
    olua_check_string(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // void setPlaceholderFont(const char *pFontName, int fontSize)
    self->setPlaceholderFont(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_EditBox_setPlaceholderFontColor$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    cocos2d::Color3B arg1;       /** color */

    olua_to_object(L, 1, &self, "ccui.EditBox");
    olua_check_cocos2d_Color3B(L, 2, &arg1);

    // void setPlaceholderFontColor(const cocos2d::Color3B &color)
    self->setPlaceholderFontColor(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_EditBox_setPlaceholderFontColor$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    cocos2d::Color4B arg1;       /** color */

    olua_to_object(L, 1, &self, "ccui.EditBox");
    olua_check_cocos2d_Color4B(L, 2, &arg1);

    // void setPlaceholderFontColor(const cocos2d::Color4B &color)
    self->setPlaceholderFontColor(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_EditBox_setPlaceholderFontColor(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        if ((olua_is_object(L, 1, "ccui.EditBox")) && (olua_is_cocos2d_Color3B(L, 2))) {
            // void setPlaceholderFontColor(const cocos2d::Color3B &color)
            return _olua_fun_cocos2d_ui_EditBox_setPlaceholderFontColor$1(L);
        }

        // if ((olua_is_object(L, 1, "ccui.EditBox")) && (olua_is_cocos2d_Color4B(L, 2))) {
            // void setPlaceholderFontColor(const cocos2d::Color4B &color)
            return _olua_fun_cocos2d_ui_EditBox_setPlaceholderFontColor$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::EditBox::setPlaceholderFontColor' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_EditBox_setPlaceholderFontName(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    const char *arg1 = nullptr;       /** pFontName */

    olua_to_object(L, 1, &self, "ccui.EditBox");
    olua_check_string(L, 2, &arg1);

    // void setPlaceholderFontName(const char *pFontName)
    self->setPlaceholderFontName(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_EditBox_setPlaceholderFontSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    int arg1 = 0;       /** fontSize */

    olua_to_object(L, 1, &self, "ccui.EditBox");
    olua_check_integer(L, 2, &arg1);

    // void setPlaceholderFontSize(int fontSize)
    self->setPlaceholderFontSize(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_EditBox_setReturnType(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    cocos2d::ui::EditBox::KeyboardReturnType arg1 = (cocos2d::ui::EditBox::KeyboardReturnType)0;       /** returnType */

    olua_to_object(L, 1, &self, "ccui.EditBox");
    olua_check_enum(L, 2, &arg1);

    // void setReturnType(cocos2d::ui::EditBox::KeyboardReturnType returnType)
    self->setReturnType(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_EditBox_setText(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    const char *arg1 = nullptr;       /** pText */

    olua_to_object(L, 1, &self, "ccui.EditBox");
    olua_check_string(L, 2, &arg1);

    // void setText(const char *pText)
    self->setText(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_EditBox_setTextHorizontalAlignment(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    cocos2d::TextHAlignment arg1 = (cocos2d::TextHAlignment)0;       /** alignment */

    olua_to_object(L, 1, &self, "ccui.EditBox");
    olua_check_enum(L, 2, &arg1);

    // void setTextHorizontalAlignment(cocos2d::TextHAlignment alignment)
    self->setTextHorizontalAlignment(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_cls_ccui_EditBox(lua_State *L)
{
    oluacls_class<cocos2d::ui::EditBox, cocos2d::ui::Widget>(L, "ccui.EditBox");
    oluacls_func(L, "as", _olua_fun_cocos2d_ui_EditBox_as);
    oluacls_func(L, "attachWithIME", _olua_fun_cocos2d_ui_EditBox_attachWithIME);
    oluacls_func(L, "create", _olua_fun_cocos2d_ui_EditBox_create);
    oluacls_func(L, "detachWithIME", _olua_fun_cocos2d_ui_EditBox_detachWithIME);
    oluacls_func(L, "getCapInsetsDisabledRenderer", _olua_fun_cocos2d_ui_EditBox_getCapInsetsDisabledRenderer);
    oluacls_func(L, "getCapInsetsNormalRenderer", _olua_fun_cocos2d_ui_EditBox_getCapInsetsNormalRenderer);
    oluacls_func(L, "getCapInsetsPressedRenderer", _olua_fun_cocos2d_ui_EditBox_getCapInsetsPressedRenderer);
    oluacls_func(L, "getDelegate", _olua_fun_cocos2d_ui_EditBox_getDelegate);
    oluacls_func(L, "getFontColor", _olua_fun_cocos2d_ui_EditBox_getFontColor);
    oluacls_func(L, "getFontName", _olua_fun_cocos2d_ui_EditBox_getFontName);
    oluacls_func(L, "getFontSize", _olua_fun_cocos2d_ui_EditBox_getFontSize);
    oluacls_func(L, "getInputFlag", _olua_fun_cocos2d_ui_EditBox_getInputFlag);
    oluacls_func(L, "getInputMode", _olua_fun_cocos2d_ui_EditBox_getInputMode);
    oluacls_func(L, "getMaxLength", _olua_fun_cocos2d_ui_EditBox_getMaxLength);
    oluacls_func(L, "getPlaceHolder", _olua_fun_cocos2d_ui_EditBox_getPlaceHolder);
    oluacls_func(L, "getPlaceholderFontColor", _olua_fun_cocos2d_ui_EditBox_getPlaceholderFontColor);
    oluacls_func(L, "getPlaceholderFontName", _olua_fun_cocos2d_ui_EditBox_getPlaceholderFontName);
    oluacls_func(L, "getPlaceholderFontSize", _olua_fun_cocos2d_ui_EditBox_getPlaceholderFontSize);
    oluacls_func(L, "getReturnType", _olua_fun_cocos2d_ui_EditBox_getReturnType);
    oluacls_func(L, "getText", _olua_fun_cocos2d_ui_EditBox_getText);
    oluacls_func(L, "getTextHorizontalAlignment", _olua_fun_cocos2d_ui_EditBox_getTextHorizontalAlignment);
    oluacls_func(L, "initWithSizeAndBackgroundSprite", _olua_fun_cocos2d_ui_EditBox_initWithSizeAndBackgroundSprite);
    oluacls_func(L, "initWithSizeAndTexture", _olua_fun_cocos2d_ui_EditBox_initWithSizeAndTexture);
    oluacls_func(L, "loadTextureDisabled", _olua_fun_cocos2d_ui_EditBox_loadTextureDisabled);
    oluacls_func(L, "loadTextureNormal", _olua_fun_cocos2d_ui_EditBox_loadTextureNormal);
    oluacls_func(L, "loadTexturePressed", _olua_fun_cocos2d_ui_EditBox_loadTexturePressed);
    oluacls_func(L, "loadTextures", _olua_fun_cocos2d_ui_EditBox_loadTextures);
    oluacls_func(L, "new", _olua_fun_cocos2d_ui_EditBox_new);
    oluacls_func(L, "openKeyboard", _olua_fun_cocos2d_ui_EditBox_openKeyboard);
    oluacls_func(L, "setCapInsets", _olua_fun_cocos2d_ui_EditBox_setCapInsets);
    oluacls_func(L, "setCapInsetsDisabledRenderer", _olua_fun_cocos2d_ui_EditBox_setCapInsetsDisabledRenderer);
    oluacls_func(L, "setCapInsetsNormalRenderer", _olua_fun_cocos2d_ui_EditBox_setCapInsetsNormalRenderer);
    oluacls_func(L, "setCapInsetsPressedRenderer", _olua_fun_cocos2d_ui_EditBox_setCapInsetsPressedRenderer);
    oluacls_func(L, "setDelegate", _olua_fun_cocos2d_ui_EditBox_setDelegate);
    oluacls_func(L, "setFont", _olua_fun_cocos2d_ui_EditBox_setFont);
    oluacls_func(L, "setFontColor", _olua_fun_cocos2d_ui_EditBox_setFontColor);
    oluacls_func(L, "setFontName", _olua_fun_cocos2d_ui_EditBox_setFontName);
    oluacls_func(L, "setFontSize", _olua_fun_cocos2d_ui_EditBox_setFontSize);
    oluacls_func(L, "setInputFlag", _olua_fun_cocos2d_ui_EditBox_setInputFlag);
    oluacls_func(L, "setInputMode", _olua_fun_cocos2d_ui_EditBox_setInputMode);
    oluacls_func(L, "setMaxLength", _olua_fun_cocos2d_ui_EditBox_setMaxLength);
    oluacls_func(L, "setPlaceHolder", _olua_fun_cocos2d_ui_EditBox_setPlaceHolder);
    oluacls_func(L, "setPlaceholderFont", _olua_fun_cocos2d_ui_EditBox_setPlaceholderFont);
    oluacls_func(L, "setPlaceholderFontColor", _olua_fun_cocos2d_ui_EditBox_setPlaceholderFontColor);
    oluacls_func(L, "setPlaceholderFontName", _olua_fun_cocos2d_ui_EditBox_setPlaceholderFontName);
    oluacls_func(L, "setPlaceholderFontSize", _olua_fun_cocos2d_ui_EditBox_setPlaceholderFontSize);
    oluacls_func(L, "setReturnType", _olua_fun_cocos2d_ui_EditBox_setReturnType);
    oluacls_func(L, "setText", _olua_fun_cocos2d_ui_EditBox_setText);
    oluacls_func(L, "setTextHorizontalAlignment", _olua_fun_cocos2d_ui_EditBox_setTextHorizontalAlignment);
    oluacls_prop(L, "capInsetsDisabledRenderer", _olua_fun_cocos2d_ui_EditBox_getCapInsetsDisabledRenderer, _olua_fun_cocos2d_ui_EditBox_setCapInsetsDisabledRenderer);
    oluacls_prop(L, "capInsetsNormalRenderer", _olua_fun_cocos2d_ui_EditBox_getCapInsetsNormalRenderer, _olua_fun_cocos2d_ui_EditBox_setCapInsetsNormalRenderer);
    oluacls_prop(L, "capInsetsPressedRenderer", _olua_fun_cocos2d_ui_EditBox_getCapInsetsPressedRenderer, _olua_fun_cocos2d_ui_EditBox_setCapInsetsPressedRenderer);
    oluacls_prop(L, "delegate", _olua_fun_cocos2d_ui_EditBox_getDelegate, _olua_fun_cocos2d_ui_EditBox_setDelegate);
    oluacls_prop(L, "fontColor", _olua_fun_cocos2d_ui_EditBox_getFontColor, nullptr);
    oluacls_prop(L, "fontName", _olua_fun_cocos2d_ui_EditBox_getFontName, _olua_fun_cocos2d_ui_EditBox_setFontName);
    oluacls_prop(L, "fontSize", _olua_fun_cocos2d_ui_EditBox_getFontSize, _olua_fun_cocos2d_ui_EditBox_setFontSize);
    oluacls_prop(L, "inputFlag", _olua_fun_cocos2d_ui_EditBox_getInputFlag, _olua_fun_cocos2d_ui_EditBox_setInputFlag);
    oluacls_prop(L, "inputMode", _olua_fun_cocos2d_ui_EditBox_getInputMode, _olua_fun_cocos2d_ui_EditBox_setInputMode);
    oluacls_prop(L, "maxLength", _olua_fun_cocos2d_ui_EditBox_getMaxLength, _olua_fun_cocos2d_ui_EditBox_setMaxLength);
    oluacls_prop(L, "placeHolder", _olua_fun_cocos2d_ui_EditBox_getPlaceHolder, _olua_fun_cocos2d_ui_EditBox_setPlaceHolder);
    oluacls_prop(L, "placeholderFontColor", _olua_fun_cocos2d_ui_EditBox_getPlaceholderFontColor, nullptr);
    oluacls_prop(L, "placeholderFontName", _olua_fun_cocos2d_ui_EditBox_getPlaceholderFontName, _olua_fun_cocos2d_ui_EditBox_setPlaceholderFontName);
    oluacls_prop(L, "placeholderFontSize", _olua_fun_cocos2d_ui_EditBox_getPlaceholderFontSize, _olua_fun_cocos2d_ui_EditBox_setPlaceholderFontSize);
    oluacls_prop(L, "returnType", _olua_fun_cocos2d_ui_EditBox_getReturnType, _olua_fun_cocos2d_ui_EditBox_setReturnType);
    oluacls_prop(L, "text", _olua_fun_cocos2d_ui_EditBox_getText, _olua_fun_cocos2d_ui_EditBox_setText);
    oluacls_prop(L, "textHorizontalAlignment", _olua_fun_cocos2d_ui_EditBox_getTextHorizontalAlignment, _olua_fun_cocos2d_ui_EditBox_setTextHorizontalAlignment);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccui_EditBox(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);
    if (!olua_getclass(L, "ccui.EditBox")) {
        luaL_error(L, "class not found: cocos2d::ui::EditBox");
    }
    return 1;
}
OLUA_END_DECLS

int _olua_module_cocos2d_ui(lua_State *L)
{
    olua_require(L, "ccui.Widget.FocusDirection", _olua_cls_ccui_Widget_FocusDirection);
    olua_require(L, "ccui.Widget.PositionType", _olua_cls_ccui_Widget_PositionType);
    olua_require(L, "ccui.Widget.SizeType", _olua_cls_ccui_Widget_SizeType);
    olua_require(L, "ccui.Widget.TouchEventType", _olua_cls_ccui_Widget_TouchEventType);
    olua_require(L, "ccui.Widget.TextureResType", _olua_cls_ccui_Widget_TextureResType);
    olua_require(L, "ccui.Widget.BrightStyle", _olua_cls_ccui_Widget_BrightStyle);
    olua_require(L, "ccui.Widget.ccWidgetTouchCallback", _olua_cls_ccui_Widget_ccWidgetTouchCallback);
    olua_require(L, "ccui.Widget.ccWidgetClickCallback", _olua_cls_ccui_Widget_ccWidgetClickCallback);
    olua_require(L, "ccui.Widget.ccWidgetEventCallback", _olua_cls_ccui_Widget_ccWidgetEventCallback);
    olua_require(L, "ccui.LayoutManager", _olua_cls_ccui_LayoutManager);
    olua_require(L, "ccui.LayoutParameterProtocol", _olua_cls_ccui_LayoutParameterProtocol);
    olua_require(L, "ccui.LayoutProtocol", _olua_cls_ccui_LayoutProtocol);
    olua_require(L, "ccui.Widget", _olua_cls_ccui_Widget);
    olua_require(L, "ccui.Helper", _olua_cls_ccui_Helper);
    olua_require(L, "ccui.Scale9Sprite.State", _olua_cls_ccui_Scale9Sprite_State);
    olua_require(L, "ccui.Scale9Sprite.RenderingType", _olua_cls_ccui_Scale9Sprite_RenderingType);
    olua_require(L, "ccui.Scale9Sprite", _olua_cls_ccui_Scale9Sprite);
    olua_require(L, "ccui.LayoutComponent.HorizontalEdge", _olua_cls_ccui_LayoutComponent_HorizontalEdge);
    olua_require(L, "ccui.LayoutComponent.VerticalEdge", _olua_cls_ccui_LayoutComponent_VerticalEdge);
    olua_require(L, "ccui.LayoutComponent", _olua_cls_ccui_LayoutComponent);
    olua_require(L, "ccui.LayoutParameter.Type", _olua_cls_ccui_LayoutParameter_Type);
    olua_require(L, "ccui.LayoutParameter", _olua_cls_ccui_LayoutParameter);
    olua_require(L, "ccui.LinearLayoutParameter.LinearGravity", _olua_cls_ccui_LinearLayoutParameter_LinearGravity);
    olua_require(L, "ccui.LinearLayoutParameter", _olua_cls_ccui_LinearLayoutParameter);
    olua_require(L, "ccui.RelativeLayoutParameter.RelativeAlign", _olua_cls_ccui_RelativeLayoutParameter_RelativeAlign);
    olua_require(L, "ccui.RelativeLayoutParameter", _olua_cls_ccui_RelativeLayoutParameter);
    olua_require(L, "ccui.Layout.Type", _olua_cls_ccui_Layout_Type);
    olua_require(L, "ccui.Layout.ClippingType", _olua_cls_ccui_Layout_ClippingType);
    olua_require(L, "ccui.Layout.BackGroundColorType", _olua_cls_ccui_Layout_BackGroundColorType);
    olua_require(L, "ccui.Layout", _olua_cls_ccui_Layout);
    olua_require(L, "ccui.HBox", _olua_cls_ccui_HBox);
    olua_require(L, "ccui.VBox", _olua_cls_ccui_VBox);
    olua_require(L, "ccui.RelativeBox", _olua_cls_ccui_RelativeBox);
#if defined(CCLUA_OS_IOS) || defined(CCLUA_OS_ANDROID)
    olua_require(L, "ccui.WebView.ccWebViewCallback", _olua_cls_ccui_WebView_ccWebViewCallback);
    olua_require(L, "ccui.WebView", _olua_cls_ccui_WebView);
    olua_require(L, "ccui.VideoPlayer.EventType", _olua_cls_ccui_VideoPlayer_EventType);
    olua_require(L, "ccui.VideoPlayer.ccVideoPlayerCallback", _olua_cls_ccui_VideoPlayer_ccVideoPlayerCallback);
    olua_require(L, "ccui.VideoPlayer.StyleType", _olua_cls_ccui_VideoPlayer_StyleType);
    olua_require(L, "ccui.VideoPlayer", _olua_cls_ccui_VideoPlayer);
#endif
    olua_require(L, "ccui.AbstractCheckButton", _olua_cls_ccui_AbstractCheckButton);
    olua_require(L, "ccui.TabHeader.EventType", _olua_cls_ccui_TabHeader_EventType);
    olua_require(L, "ccui.TabHeader", _olua_cls_ccui_TabHeader);
    olua_require(L, "ccui.TabControl.Dock", _olua_cls_ccui_TabControl_Dock);
    olua_require(L, "ccui.TabControl.EventType", _olua_cls_ccui_TabControl_EventType);
    olua_require(L, "ccui.TabControl.ccTabControlCallback", _olua_cls_ccui_TabControl_ccTabControlCallback);
    olua_require(L, "ccui.TabControl", _olua_cls_ccui_TabControl);
    olua_require(L, "ccui.ScrollView.Direction", _olua_cls_ccui_ScrollView_Direction);
    olua_require(L, "ccui.ScrollView.EventType", _olua_cls_ccui_ScrollView_EventType);
    olua_require(L, "ccui.ScrollView.ccScrollViewCallback", _olua_cls_ccui_ScrollView_ccScrollViewCallback);
    olua_require(L, "ccui.ScrollView", _olua_cls_ccui_ScrollView);
    olua_require(L, "ccui.ListView.Gravity", _olua_cls_ccui_ListView_Gravity);
    olua_require(L, "ccui.ListView.EventType", _olua_cls_ccui_ListView_EventType);
    olua_require(L, "ccui.ListView.MagneticType", _olua_cls_ccui_ListView_MagneticType);
    olua_require(L, "ccui.ListView.ccListViewCallback", _olua_cls_ccui_ListView_ccListViewCallback);
    olua_require(L, "ccui.ListView", _olua_cls_ccui_ListView);
    olua_require(L, "ccui.LoadingBar.Direction", _olua_cls_ccui_LoadingBar_Direction);
    olua_require(L, "ccui.LoadingBar", _olua_cls_ccui_LoadingBar);
    olua_require(L, "ccui.PageView.EventType", _olua_cls_ccui_PageView_EventType);
    olua_require(L, "ccui.PageView.TouchDirection", _olua_cls_ccui_PageView_TouchDirection);
    olua_require(L, "ccui.PageView.ccPageViewCallback", _olua_cls_ccui_PageView_ccPageViewCallback);
    olua_require(L, "ccui.PageView", _olua_cls_ccui_PageView);
    olua_require(L, "ccui.RichElement.Type", _olua_cls_ccui_RichElement_Type);
    olua_require(L, "ccui.RichElement", _olua_cls_ccui_RichElement);
    olua_require(L, "ccui.RichElementText", _olua_cls_ccui_RichElementText);
    olua_require(L, "ccui.RichElementImage", _olua_cls_ccui_RichElementImage);
    olua_require(L, "ccui.RichElementCustomNode", _olua_cls_ccui_RichElementCustomNode);
    olua_require(L, "ccui.RichElementNewLine", _olua_cls_ccui_RichElementNewLine);
    olua_require(L, "ccui.RichText.WrapMode", _olua_cls_ccui_RichText_WrapMode);
    olua_require(L, "ccui.RichText.HorizontalAlignment", _olua_cls_ccui_RichText_HorizontalAlignment);
    olua_require(L, "ccui.RichText.OpenUrlHandler", _olua_cls_ccui_RichText_OpenUrlHandler);
    olua_require(L, "ccui.RichText", _olua_cls_ccui_RichText);
    olua_require(L, "ccui.ScrollViewBar", _olua_cls_ccui_ScrollViewBar);
    olua_require(L, "ccui.Slider.EventType", _olua_cls_ccui_Slider_EventType);
    olua_require(L, "ccui.Slider.ccSliderCallback", _olua_cls_ccui_Slider_ccSliderCallback);
    olua_require(L, "ccui.Slider", _olua_cls_ccui_Slider);
    olua_require(L, "ccui.Text.Type", _olua_cls_ccui_Text_Type);
    olua_require(L, "ccui.Text", _olua_cls_ccui_Text);
    olua_require(L, "ccui.TextAtlas", _olua_cls_ccui_TextAtlas);
    olua_require(L, "ccui.TextBMFont", _olua_cls_ccui_TextBMFont);
    olua_require(L, "ccui.UICCTextField", _olua_cls_ccui_UICCTextField);
    olua_require(L, "ccui.TextField.EventType", _olua_cls_ccui_TextField_EventType);
    olua_require(L, "ccui.TextField.ccTextFieldCallback", _olua_cls_ccui_TextField_ccTextFieldCallback);
    olua_require(L, "ccui.TextField", _olua_cls_ccui_TextField);
    olua_require(L, "ccui.Button", _olua_cls_ccui_Button);
    olua_require(L, "ccui.CheckBox.EventType", _olua_cls_ccui_CheckBox_EventType);
    olua_require(L, "ccui.CheckBox.ccCheckBoxCallback", _olua_cls_ccui_CheckBox_ccCheckBoxCallback);
    olua_require(L, "ccui.CheckBox", _olua_cls_ccui_CheckBox);
    olua_require(L, "ccui.RadioButton.EventType", _olua_cls_ccui_RadioButton_EventType);
    olua_require(L, "ccui.RadioButton.ccRadioButtonCallback", _olua_cls_ccui_RadioButton_ccRadioButtonCallback);
    olua_require(L, "ccui.RadioButton", _olua_cls_ccui_RadioButton);
    olua_require(L, "ccui.RadioButtonGroup.EventType", _olua_cls_ccui_RadioButtonGroup_EventType);
    olua_require(L, "ccui.RadioButtonGroup.ccRadioButtonGroupCallback", _olua_cls_ccui_RadioButtonGroup_ccRadioButtonGroupCallback);
    olua_require(L, "ccui.RadioButtonGroup", _olua_cls_ccui_RadioButtonGroup);
    olua_require(L, "ccui.ImageView", _olua_cls_ccui_ImageView);
    olua_require(L, "ccui.EditBoxDelegate.EditBoxEndAction", _olua_cls_ccui_EditBoxDelegate_EditBoxEndAction);
    olua_require(L, "ccui.EditBoxDelegate", _olua_cls_ccui_EditBoxDelegate);
    olua_require(L, "ccui.LuaEditBoxDelegate", _olua_cls_ccui_LuaEditBoxDelegate);
    olua_require(L, "ccui.EditBox.KeyboardReturnType", _olua_cls_ccui_EditBox_KeyboardReturnType);
    olua_require(L, "ccui.EditBox.InputMode", _olua_cls_ccui_EditBox_InputMode);
    olua_require(L, "ccui.EditBox.InputFlag", _olua_cls_ccui_EditBox_InputFlag);
    olua_require(L, "ccui.EditBox", _olua_cls_ccui_EditBox);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_ui(lua_State *L)
{
    olua_require(L, "cocos2d_ui",  _olua_module_cocos2d_ui);

    return 0;
}
OLUA_END_DECLS
