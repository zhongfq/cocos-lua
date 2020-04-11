//
// AUTO BUILD, DON'T MODIFY!
//
#include "lua-bindings/lua_cocos2d_ui.h"
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "lua-bindings/LuaCocosAdapter.h"
#include "xgame/xlua.h"
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "ui/UIScrollViewBar.h"



static int luaopen_cocos2d_ui_Widget_FocusDirection(lua_State *L)
{
    oluacls_class(L, "ccui.Widget.FocusDirection", nullptr);
    oluacls_const_integer(L, "DOWN", (lua_Integer)cocos2d::ui::Widget::FocusDirection::DOWN);
    oluacls_const_integer(L, "LEFT", (lua_Integer)cocos2d::ui::Widget::FocusDirection::LEFT);
    oluacls_const_integer(L, "RIGHT", (lua_Integer)cocos2d::ui::Widget::FocusDirection::RIGHT);
    oluacls_const_integer(L, "UP", (lua_Integer)cocos2d::ui::Widget::FocusDirection::UP);

    olua_registerluatype<cocos2d::ui::Widget::FocusDirection>(L, "ccui.Widget.FocusDirection");

    return 1;
}

static int luaopen_cocos2d_ui_Widget_PositionType(lua_State *L)
{
    oluacls_class(L, "ccui.Widget.PositionType", nullptr);
    oluacls_const_integer(L, "ABSOLUTE", (lua_Integer)cocos2d::ui::Widget::PositionType::ABSOLUTE);
    oluacls_const_integer(L, "PERCENT", (lua_Integer)cocos2d::ui::Widget::PositionType::PERCENT);

    olua_registerluatype<cocos2d::ui::Widget::PositionType>(L, "ccui.Widget.PositionType");

    return 1;
}

static int luaopen_cocos2d_ui_Widget_SizeType(lua_State *L)
{
    oluacls_class(L, "ccui.Widget.SizeType", nullptr);
    oluacls_const_integer(L, "ABSOLUTE", (lua_Integer)cocos2d::ui::Widget::SizeType::ABSOLUTE);
    oluacls_const_integer(L, "PERCENT", (lua_Integer)cocos2d::ui::Widget::SizeType::PERCENT);

    olua_registerluatype<cocos2d::ui::Widget::SizeType>(L, "ccui.Widget.SizeType");

    return 1;
}

static int luaopen_cocos2d_ui_Widget_TouchEventType(lua_State *L)
{
    oluacls_class(L, "ccui.Widget.TouchEventType", nullptr);
    oluacls_const_integer(L, "BEGAN", (lua_Integer)cocos2d::ui::Widget::TouchEventType::BEGAN);
    oluacls_const_integer(L, "CANCELED", (lua_Integer)cocos2d::ui::Widget::TouchEventType::CANCELED);
    oluacls_const_integer(L, "ENDED", (lua_Integer)cocos2d::ui::Widget::TouchEventType::ENDED);
    oluacls_const_integer(L, "MOVED", (lua_Integer)cocos2d::ui::Widget::TouchEventType::MOVED);

    olua_registerluatype<cocos2d::ui::Widget::TouchEventType>(L, "ccui.Widget.TouchEventType");

    return 1;
}

static int luaopen_cocos2d_ui_Widget_TextureResType(lua_State *L)
{
    oluacls_class(L, "ccui.Widget.TextureResType", nullptr);
    oluacls_const_integer(L, "LOCAL", (lua_Integer)cocos2d::ui::Widget::TextureResType::LOCAL);
    oluacls_const_integer(L, "PLIST", (lua_Integer)cocos2d::ui::Widget::TextureResType::PLIST);

    olua_registerluatype<cocos2d::ui::Widget::TextureResType>(L, "ccui.Widget.TextureResType");

    return 1;
}

static int luaopen_cocos2d_ui_Widget_BrightStyle(lua_State *L)
{
    oluacls_class(L, "ccui.Widget.BrightStyle", nullptr);
    oluacls_const_integer(L, "HIGHLIGHT", (lua_Integer)cocos2d::ui::Widget::BrightStyle::HIGHLIGHT);
    oluacls_const_integer(L, "NONE", (lua_Integer)cocos2d::ui::Widget::BrightStyle::NONE);
    oluacls_const_integer(L, "NORMAL", (lua_Integer)cocos2d::ui::Widget::BrightStyle::NORMAL);

    olua_registerluatype<cocos2d::ui::Widget::BrightStyle>(L, "ccui.Widget.BrightStyle");

    return 1;
}

static int _cocos2d_ui_Widget___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::ui::Widget *)olua_toobj(L, 1, "ccui.Widget");
    olua_push_cppobj(L, self, "ccui.Widget");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_ui_Widget_addCCSEventListener(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    std::function<void(cocos2d::Ref *, int)> arg1;       /** callback */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Widget");

    if (olua_is_std_function(L, 2)) {
        void *callback_store_obj = (void *)self;
        std::string tag = "ccsEventListener";
        std::string func = olua_setcallback(L, callback_store_obj, tag.c_str(), 2, OLUA_TAG_REPLACE);
        lua_State *MT = olua_mainthread();
        arg1 = [callback_store_obj, func, MT](cocos2d::Ref *arg1, int arg2) {
            lua_State *L = olua_mainthread();

            if (MT == L) {
                int top = lua_gettop(L);
                olua_push_cppobj(L, arg1, "cc.Ref");
                olua_push_int(L, (lua_Integer)arg2);

                olua_callback(L, callback_store_obj, func.c_str(), 2);

                lua_settop(L, top);
            }
        };
    } else {
        void *callback_store_obj = (void *)self;
        std::string tag = "ccsEventListener";
        olua_removecallback(L, callback_store_obj, tag.c_str(), OLUA_TAG_SUBEQUAL);
        arg1 = nullptr;
    }

    // void addCCSEventListener(@nullable const std::function<void(Ref*, int)>& callback)
    self->addCCSEventListener(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Widget_addClickEventListener(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    std::function<void(cocos2d::Ref *)> arg1;       /** callback */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Widget");

    if (olua_is_std_function(L, 2)) {
        void *callback_store_obj = (void *)self;
        std::string tag = "clickEventListener";
        std::string func = olua_setcallback(L, callback_store_obj, tag.c_str(), 2, OLUA_TAG_REPLACE);
        lua_State *MT = olua_mainthread();
        arg1 = [callback_store_obj, func, MT](cocos2d::Ref *arg1) {
            lua_State *L = olua_mainthread();

            if (MT == L) {
                int top = lua_gettop(L);
                olua_push_cppobj(L, arg1, "cc.Ref");

                olua_callback(L, callback_store_obj, func.c_str(), 1);

                lua_settop(L, top);
            }
        };
    } else {
        void *callback_store_obj = (void *)self;
        std::string tag = "clickEventListener";
        olua_removecallback(L, callback_store_obj, tag.c_str(), OLUA_TAG_SUBEQUAL);
        arg1 = nullptr;
    }

    // void addClickEventListener(@nullable std::function<void(Ref*)>& callback)
    self->addClickEventListener(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Widget_addTouchEventListener(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    std::function<void(cocos2d::Ref *, cocos2d::ui::Widget::TouchEventType)> arg1;       /** callback */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Widget");

    if (olua_is_std_function(L, 2)) {
        void *callback_store_obj = (void *)self;
        std::string tag = "touchEventListener";
        std::string func = olua_setcallback(L, callback_store_obj, tag.c_str(), 2, OLUA_TAG_REPLACE);
        lua_State *MT = olua_mainthread();
        arg1 = [callback_store_obj, func, MT](cocos2d::Ref *arg1, cocos2d::ui::Widget::TouchEventType arg2) {
            lua_State *L = olua_mainthread();

            if (MT == L) {
                int top = lua_gettop(L);
                olua_push_cppobj(L, arg1, "cc.Ref");
                olua_push_uint(L, (lua_Unsigned)arg2);

                olua_callback(L, callback_store_obj, func.c_str(), 2);

                lua_settop(L, top);
            }
        };
    } else {
        void *callback_store_obj = (void *)self;
        std::string tag = "touchEventListener";
        olua_removecallback(L, callback_store_obj, tag.c_str(), OLUA_TAG_SUBEQUAL);
        arg1 = nullptr;
    }

    // void addTouchEventListener(@nullable const std::function<void(Ref*,Widget::TouchEventType)>& callback)
    self->addTouchEventListener(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Widget_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Widget");

    // cocos2d::ui::Widget *clone()
    cocos2d::ui::Widget *ret = (cocos2d::ui::Widget *)self->clone();
    int num_ret = olua_push_cppobj(L, ret, "ccui.Widget");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Widget_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::ui::Widget *create()
    cocos2d::ui::Widget *ret = (cocos2d::ui::Widget *)cocos2d::ui::Widget::create();
    int num_ret = olua_push_cppobj(L, ret, "ccui.Widget");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Widget_dispatchFocusEvent(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    cocos2d::ui::Widget *arg1 = nullptr;       /** widgetLoseFocus */
    cocos2d::ui::Widget *arg2 = nullptr;       /** widgetGetFocus */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Widget");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccui.Widget");
    olua_check_cppobj(L, 3, (void **)&arg2, "ccui.Widget");

    // void dispatchFocusEvent(cocos2d::ui::Widget *widgetLoseFocus, cocos2d::ui::Widget *widgetGetFocus)
    self->dispatchFocusEvent(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Widget_enableDpadNavigation(lua_State *L)
{
    olua_startinvoke(L);

    bool arg1 = false;       /** enable */

    olua_check_bool(L, 1, &arg1);

    // static void enableDpadNavigation(bool enable)
    cocos2d::ui::Widget::enableDpadNavigation(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Widget_findNextFocusedWidget(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    lua_Unsigned arg1 = 0;       /** direction */
    cocos2d::ui::Widget *arg2 = nullptr;       /** current */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Widget");
    olua_check_uint(L, 2, &arg1);
    olua_check_cppobj(L, 3, (void **)&arg2, "ccui.Widget");

    // cocos2d::ui::Widget *findNextFocusedWidget(cocos2d::ui::Widget::FocusDirection direction, cocos2d::ui::Widget *current)
    cocos2d::ui::Widget *ret = (cocos2d::ui::Widget *)self->findNextFocusedWidget((cocos2d::ui::Widget::FocusDirection)arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "ccui.Widget");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Widget_getActionTag(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Widget");

    // int getActionTag()
    int ret = (int)self->getActionTag();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Widget_getBottomBoundary(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Widget");

    // float getBottomBoundary()
    float ret = (float)self->getBottomBoundary();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Widget_getCallbackName(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Widget");

    // const std::string &getCallbackName()
    const std::string &ret = (const std::string &)self->getCallbackName();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Widget_getCallbackType(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Widget");

    // const std::string &getCallbackType()
    const std::string &ret = (const std::string &)self->getCallbackType();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Widget_getCurrentFocusedWidget(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::ui::Widget *getCurrentFocusedWidget()
    cocos2d::ui::Widget *ret = (cocos2d::ui::Widget *)cocos2d::ui::Widget::getCurrentFocusedWidget();
    int num_ret = olua_push_cppobj(L, ret, "ccui.Widget");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Widget_getCustomSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Widget");

    // const cocos2d::Size &getCustomSize()
    const cocos2d::Size &ret = (const cocos2d::Size &)self->getCustomSize();
    int num_ret = auto_olua_push_cocos2d_Size(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Widget_getLayoutParameter(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Widget");

    // cocos2d::ui::LayoutParameter *getLayoutParameter()
    cocos2d::ui::LayoutParameter *ret = (cocos2d::ui::LayoutParameter *)self->getLayoutParameter();
    int num_ret = olua_push_cppobj(L, ret, "ccui.LayoutParameter");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Widget_getLayoutSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Widget");

    // const cocos2d::Size &getLayoutSize()
    const cocos2d::Size &ret = (const cocos2d::Size &)self->getLayoutSize();
    int num_ret = auto_olua_push_cocos2d_Size(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Widget_getLeftBoundary(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Widget");

    // float getLeftBoundary()
    float ret = (float)self->getLeftBoundary();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Widget_getPositionPercent(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Widget");

    // const cocos2d::Vec2 &getPositionPercent()
    const cocos2d::Vec2 &ret = (const cocos2d::Vec2 &)self->getPositionPercent();
    int num_ret = auto_olua_push_cocos2d_Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Widget_getPositionType(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Widget");

    // cocos2d::ui::Widget::PositionType getPositionType()
    cocos2d::ui::Widget::PositionType ret = (cocos2d::ui::Widget::PositionType)self->getPositionType();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Widget_getRightBoundary(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Widget");

    // float getRightBoundary()
    float ret = (float)self->getRightBoundary();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Widget_getSizePercent(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Widget");

    // const cocos2d::Vec2 &getSizePercent()
    const cocos2d::Vec2 &ret = (const cocos2d::Vec2 &)self->getSizePercent();
    int num_ret = auto_olua_push_cocos2d_Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Widget_getSizeType(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Widget");

    // cocos2d::ui::Widget::SizeType getSizeType()
    cocos2d::ui::Widget::SizeType ret = (cocos2d::ui::Widget::SizeType)self->getSizeType();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Widget_getTopBoundary(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Widget");

    // float getTopBoundary()
    float ret = (float)self->getTopBoundary();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Widget_getTouchBeganPosition(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Widget");

    // const cocos2d::Vec2 &getTouchBeganPosition()
    const cocos2d::Vec2 &ret = (const cocos2d::Vec2 &)self->getTouchBeganPosition();
    int num_ret = auto_olua_push_cocos2d_Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Widget_getTouchEndPosition(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Widget");

    // const cocos2d::Vec2 &getTouchEndPosition()
    const cocos2d::Vec2 &ret = (const cocos2d::Vec2 &)self->getTouchEndPosition();
    int num_ret = auto_olua_push_cocos2d_Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Widget_getTouchMovePosition(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Widget");

    // const cocos2d::Vec2 &getTouchMovePosition()
    const cocos2d::Vec2 &ret = (const cocos2d::Vec2 &)self->getTouchMovePosition();
    int num_ret = auto_olua_push_cocos2d_Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Widget_getVirtualRenderer(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Widget");

    // @addref(protectedChildren |) cocos2d::Node *getVirtualRenderer()
    cocos2d::Node *ret = (cocos2d::Node *)self->getVirtualRenderer();
    int num_ret = olua_push_cppobj(L, ret, "cc.Node");

    // inject code after call
    olua_addref(L, 1, "protectedChildren", -1, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Widget_getVirtualRendererSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Widget");

    // cocos2d::Size getVirtualRendererSize()
    cocos2d::Size ret = (cocos2d::Size)self->getVirtualRendererSize();
    int num_ret = auto_olua_push_cocos2d_Size(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Widget_getWorldPosition(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Widget");

    // cocos2d::Vec2 getWorldPosition()
    cocos2d::Vec2 ret = (cocos2d::Vec2)self->getWorldPosition();
    int num_ret = auto_olua_push_cocos2d_Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Widget_ignoreContentAdaptWithSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    bool arg1 = false;       /** ignore */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Widget");
    olua_check_bool(L, 2, &arg1);

    // void ignoreContentAdaptWithSize(bool ignore)
    self->ignoreContentAdaptWithSize(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Widget_interceptTouchEvent(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    lua_Unsigned arg1 = 0;       /** event */
    cocos2d::ui::Widget *arg2 = nullptr;       /** sender */
    cocos2d::Touch *arg3 = nullptr;       /** touch */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Widget");
    olua_check_uint(L, 2, &arg1);
    olua_check_cppobj(L, 3, (void **)&arg2, "ccui.Widget");
    olua_check_cppobj(L, 4, (void **)&arg3, "cc.Touch");

    // void interceptTouchEvent(cocos2d::ui::Widget::TouchEventType event, cocos2d::ui::Widget *sender, cocos2d::Touch *touch)
    self->interceptTouchEvent((cocos2d::ui::Widget::TouchEventType)arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Widget_isBright(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Widget");

    // bool isBright()
    bool ret = (bool)self->isBright();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Widget_isClippingParentContainsPoint(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    cocos2d::Vec2 arg1;       /** pt */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Widget");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);

    // bool isClippingParentContainsPoint(const cocos2d::Vec2 &pt)
    bool ret = (bool)self->isClippingParentContainsPoint(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Widget_isEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Widget");

    // bool isEnabled()
    bool ret = (bool)self->isEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Widget_isFlippedX(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Widget");

    // bool isFlippedX()
    bool ret = (bool)self->isFlippedX();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Widget_isFlippedY(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Widget");

    // bool isFlippedY()
    bool ret = (bool)self->isFlippedY();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Widget_isFocusEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Widget");

    // bool isFocusEnabled()
    bool ret = (bool)self->isFocusEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Widget_isFocused(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Widget");

    // bool isFocused()
    bool ret = (bool)self->isFocused();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Widget_isHighlighted(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Widget");

    // bool isHighlighted()
    bool ret = (bool)self->isHighlighted();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Widget_isIgnoreContentAdaptWithSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Widget");

    // bool isIgnoreContentAdaptWithSize()
    bool ret = (bool)self->isIgnoreContentAdaptWithSize();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Widget_isLayoutComponentEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Widget");

    // bool isLayoutComponentEnabled()
    bool ret = (bool)self->isLayoutComponentEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Widget_isPropagateTouchEvents(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Widget");

    // bool isPropagateTouchEvents()
    bool ret = (bool)self->isPropagateTouchEvents();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Widget_isSwallowTouches(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Widget");

    // bool isSwallowTouches()
    bool ret = (bool)self->isSwallowTouches();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Widget_isTouchEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Widget");

    // bool isTouchEnabled()
    bool ret = (bool)self->isTouchEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Widget_isUnifySizeEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Widget");

    // bool isUnifySizeEnabled()
    bool ret = (bool)self->isUnifySizeEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Widget_new(lua_State *L)
{
    olua_startinvoke(L);

    // Widget()
    cocos2d::ui::Widget *ret = (cocos2d::ui::Widget *)new cocos2d::ui::Widget();
    int num_ret = olua_push_cppobj(L, ret, "ccui.Widget");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Widget_onFocusChange(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    cocos2d::ui::Widget *arg1 = nullptr;       /** widgetLostFocus */
    cocos2d::ui::Widget *arg2 = nullptr;       /** widgetGetFocus */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Widget");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccui.Widget");
    olua_check_cppobj(L, 3, (void **)&arg2, "ccui.Widget");

    // void onFocusChange(cocos2d::ui::Widget *widgetLostFocus, cocos2d::ui::Widget *widgetGetFocus)
    self->onFocusChange(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Widget_onTouchBegan(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    cocos2d::Touch *arg1 = nullptr;       /** touch */
    cocos2d::Event *arg2 = nullptr;       /** unusedEvent */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Widget");
    olua_check_cppobj(L, 2, (void **)&arg1, "cc.Touch");
    olua_check_cppobj(L, 3, (void **)&arg2, "cc.Event");

    // bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unusedEvent)
    bool ret = (bool)self->onTouchBegan(arg1, arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Widget_onTouchCancelled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    cocos2d::Touch *arg1 = nullptr;       /** touch */
    cocos2d::Event *arg2 = nullptr;       /** unusedEvent */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Widget");
    olua_check_cppobj(L, 2, (void **)&arg1, "cc.Touch");
    olua_check_cppobj(L, 3, (void **)&arg2, "cc.Event");

    // void onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event *unusedEvent)
    self->onTouchCancelled(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Widget_onTouchEnded(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    cocos2d::Touch *arg1 = nullptr;       /** touch */
    cocos2d::Event *arg2 = nullptr;       /** unusedEvent */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Widget");
    olua_check_cppobj(L, 2, (void **)&arg1, "cc.Touch");
    olua_check_cppobj(L, 3, (void **)&arg2, "cc.Event");

    // void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unusedEvent)
    self->onTouchEnded(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Widget_onTouchMoved(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    cocos2d::Touch *arg1 = nullptr;       /** touch */
    cocos2d::Event *arg2 = nullptr;       /** unusedEvent */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Widget");
    olua_check_cppobj(L, 2, (void **)&arg1, "cc.Touch");
    olua_check_cppobj(L, 3, (void **)&arg2, "cc.Event");

    // void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unusedEvent)
    self->onTouchMoved(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Widget_propagateTouchEvent(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    lua_Unsigned arg1 = 0;       /** event */
    cocos2d::ui::Widget *arg2 = nullptr;       /** sender */
    cocos2d::Touch *arg3 = nullptr;       /** touch */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Widget");
    olua_check_uint(L, 2, &arg1);
    olua_check_cppobj(L, 3, (void **)&arg2, "ccui.Widget");
    olua_check_cppobj(L, 4, (void **)&arg3, "cc.Touch");

    // void propagateTouchEvent(cocos2d::ui::Widget::TouchEventType event, cocos2d::ui::Widget *sender, cocos2d::Touch *touch)
    self->propagateTouchEvent((cocos2d::ui::Widget::TouchEventType)arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Widget_requestFocus(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Widget");

    // void requestFocus()
    self->requestFocus();

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Widget_setActionTag(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    lua_Integer arg1 = 0;       /** tag */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Widget");
    olua_check_int(L, 2, &arg1);

    // void setActionTag(int tag)
    self->setActionTag((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Widget_setBright(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    bool arg1 = false;       /** bright */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Widget");
    olua_check_bool(L, 2, &arg1);

    // void setBright(bool bright)
    self->setBright(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Widget_setBrightStyle(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    lua_Unsigned arg1 = 0;       /** style */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Widget");
    olua_check_uint(L, 2, &arg1);

    // void setBrightStyle(cocos2d::ui::Widget::BrightStyle style)
    self->setBrightStyle((cocos2d::ui::Widget::BrightStyle)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Widget_setCallbackName(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    std::string arg1;       /** callbackName */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Widget");
    olua_check_std_string(L, 2, &arg1);

    // void setCallbackName(const std::string &callbackName)
    self->setCallbackName(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Widget_setCallbackType(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    std::string arg1;       /** callbackType */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Widget");
    olua_check_std_string(L, 2, &arg1);

    // void setCallbackType(const std::string &callbackType)
    self->setCallbackType(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Widget_setEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    bool arg1 = false;       /** enabled */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Widget");
    olua_check_bool(L, 2, &arg1);

    // void setEnabled(bool enabled)
    self->setEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Widget_setFlippedX(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    bool arg1 = false;       /** flippedX */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Widget");
    olua_check_bool(L, 2, &arg1);

    // void setFlippedX(bool flippedX)
    self->setFlippedX(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Widget_setFlippedY(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    bool arg1 = false;       /** flippedY */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Widget");
    olua_check_bool(L, 2, &arg1);

    // void setFlippedY(bool flippedY)
    self->setFlippedY(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Widget_setFocusEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    bool arg1 = false;       /** enable */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Widget");
    olua_check_bool(L, 2, &arg1);

    // void setFocusEnabled(bool enable)
    self->setFocusEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Widget_setFocused(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    bool arg1 = false;       /** focus */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Widget");
    olua_check_bool(L, 2, &arg1);

    // void setFocused(bool focus)
    self->setFocused(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Widget_setHighlighted(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    bool arg1 = false;       /** highlight */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Widget");
    olua_check_bool(L, 2, &arg1);

    // void setHighlighted(bool highlight)
    self->setHighlighted(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Widget_setLayoutComponentEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    bool arg1 = false;       /** enable */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Widget");
    olua_check_bool(L, 2, &arg1);

    // void setLayoutComponentEnabled(bool enable)
    self->setLayoutComponentEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Widget_setLayoutParameter(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    cocos2d::ui::LayoutParameter *arg1 = nullptr;       /** parameter */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Widget");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccui.LayoutParameter");

    // void setLayoutParameter(cocos2d::ui::LayoutParameter *parameter)
    self->setLayoutParameter(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Widget_setPositionPercent(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    cocos2d::Vec2 arg1;       /** percent */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Widget");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);

    // void setPositionPercent(const cocos2d::Vec2 &percent)
    self->setPositionPercent(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Widget_setPositionType(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    lua_Unsigned arg1 = 0;       /** type */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Widget");
    olua_check_uint(L, 2, &arg1);

    // void setPositionType(cocos2d::ui::Widget::PositionType type)
    self->setPositionType((cocos2d::ui::Widget::PositionType)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Widget_setPropagateTouchEvents(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    bool arg1 = false;       /** isPropagate */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Widget");
    olua_check_bool(L, 2, &arg1);

    // void setPropagateTouchEvents(bool isPropagate)
    self->setPropagateTouchEvents(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Widget_setSizePercent(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    cocos2d::Vec2 arg1;       /** percent */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Widget");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);

    // void setSizePercent(const cocos2d::Vec2 &percent)
    self->setSizePercent(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Widget_setSizeType(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    lua_Unsigned arg1 = 0;       /** type */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Widget");
    olua_check_uint(L, 2, &arg1);

    // void setSizeType(cocos2d::ui::Widget::SizeType type)
    self->setSizeType((cocos2d::ui::Widget::SizeType)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Widget_setSwallowTouches(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    bool arg1 = false;       /** swallow */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Widget");
    olua_check_bool(L, 2, &arg1);

    // void setSwallowTouches(bool swallow)
    self->setSwallowTouches(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Widget_setTouchEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    bool arg1 = false;       /** enabled */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Widget");
    olua_check_bool(L, 2, &arg1);

    // void setTouchEnabled(bool enabled)
    self->setTouchEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Widget_setUnifySizeEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    bool arg1 = false;       /** enable */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Widget");
    olua_check_bool(L, 2, &arg1);

    // void setUnifySizeEnabled(bool enable)
    self->setUnifySizeEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Widget_updateSizeAndPosition1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Widget");

    // void updateSizeAndPosition()
    self->updateSizeAndPosition();

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Widget_updateSizeAndPosition2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    cocos2d::Size arg1;       /** parentSize */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Widget");
    auto_olua_check_cocos2d_Size(L, 2, &arg1);

    // void updateSizeAndPosition(const cocos2d::Size &parentSize)
    self->updateSizeAndPosition(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Widget_updateSizeAndPosition(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // void updateSizeAndPosition()
        return _cocos2d_ui_Widget_updateSizeAndPosition1(L);
    }

    if (num_args == 1) {
        // if ((auto_olua_is_cocos2d_Size(L, 2))) {
            // void updateSizeAndPosition(const cocos2d::Size &parentSize)
            return _cocos2d_ui_Widget_updateSizeAndPosition2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::Widget::updateSizeAndPosition' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ui_Widget_get_onFocusChanged(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Widget");

    void *callback_store_obj = (void *)self;
    std::string tag = "onFocusChanged";
    olua_getcallback(L, callback_store_obj, tag.c_str(), OLUA_TAG_SUBEQUAL);

    // @nullable std::function<void(Widget*,Widget*)> onFocusChanged
    std::function<void(cocos2d::ui::Widget *, cocos2d::ui::Widget *)> ret = (std::function<void(cocos2d::ui::Widget *, cocos2d::ui::Widget *)>)self->onFocusChanged;
    int num_ret = olua_push_std_function(L, (std::function<void(cocos2d::ui::Widget *, cocos2d::ui::Widget *)>)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Widget_set_onFocusChanged(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    std::function<void(cocos2d::ui::Widget *, cocos2d::ui::Widget *)> arg1;       /** onFocusChanged */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Widget");

    if (olua_is_std_function(L, 2)) {
        void *callback_store_obj = (void *)self;
        std::string tag = "onFocusChanged";
        std::string func = olua_setcallback(L, callback_store_obj, tag.c_str(), 2, OLUA_TAG_REPLACE);
        lua_State *MT = olua_mainthread();
        arg1 = [callback_store_obj, func, MT](cocos2d::ui::Widget *arg1, cocos2d::ui::Widget *arg2) {
            lua_State *L = olua_mainthread();

            if (MT == L) {
                int top = lua_gettop(L);
                olua_push_cppobj(L, arg1, "ccui.Widget");
                olua_push_cppobj(L, arg2, "ccui.Widget");

                olua_callback(L, callback_store_obj, func.c_str(), 2);

                lua_settop(L, top);
            }
        };
    } else {
        void *callback_store_obj = (void *)self;
        std::string tag = "onFocusChanged";
        olua_removecallback(L, callback_store_obj, tag.c_str(), OLUA_TAG_SUBEQUAL);
        arg1 = nullptr;
    }

    // @nullable std::function<void(Widget*,Widget*)> onFocusChanged
    self->onFocusChanged = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Widget_get_onNextFocusedWidget(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Widget");

    void *callback_store_obj = (void *)self;
    std::string tag = "onNextFocusedWidget";
    olua_getcallback(L, callback_store_obj, tag.c_str(), OLUA_TAG_SUBEQUAL);

    // @nullable std::function<Widget*(FocusDirection)> onNextFocusedWidget
    std::function<cocos2d::ui::Widget *(cocos2d::ui::Widget::FocusDirection)> ret = (std::function<cocos2d::ui::Widget *(cocos2d::ui::Widget::FocusDirection)>)self->onNextFocusedWidget;
    int num_ret = olua_push_std_function(L, (std::function<cocos2d::ui::Widget *(cocos2d::ui::Widget::FocusDirection)>)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Widget_set_onNextFocusedWidget(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *self = nullptr;
    std::function<cocos2d::ui::Widget *(cocos2d::ui::Widget::FocusDirection)> arg1;       /** onNextFocusedWidget */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Widget");

    if (olua_is_std_function(L, 2)) {
        void *callback_store_obj = (void *)self;
        std::string tag = "onNextFocusedWidget";
        std::string func = olua_setcallback(L, callback_store_obj, tag.c_str(), 2, OLUA_TAG_REPLACE);
        lua_State *MT = olua_mainthread();
        arg1 = [callback_store_obj, func, MT](cocos2d::ui::Widget::FocusDirection arg1) {
            lua_State *L = olua_mainthread();
            cocos2d::ui::Widget *ret = nullptr;       
            if (MT == L) {
                int top = lua_gettop(L);
                olua_push_uint(L, (lua_Unsigned)arg1);

                olua_callback(L, callback_store_obj, func.c_str(), 1);

                if (olua_is_cppobj(L, -1, "ccui.Widget")) {
                    olua_check_cppobj(L, -1, (void **)&ret, "ccui.Widget");
                }

                lua_settop(L, top);
            }
            return ret;
        };
    } else {
        void *callback_store_obj = (void *)self;
        std::string tag = "onNextFocusedWidget";
        olua_removecallback(L, callback_store_obj, tag.c_str(), OLUA_TAG_SUBEQUAL);
        arg1 = nullptr;
    }

    // @nullable std::function<Widget*(FocusDirection)> onNextFocusedWidget
    self->onNextFocusedWidget = arg1;

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_ui_Widget(lua_State *L)
{
    oluacls_class(L, "ccui.Widget", "cc.ProtectedNode");
    oluacls_func(L, "__move", _cocos2d_ui_Widget___move);
    oluacls_func(L, "addCCSEventListener", _cocos2d_ui_Widget_addCCSEventListener);
    oluacls_func(L, "addClickEventListener", _cocos2d_ui_Widget_addClickEventListener);
    oluacls_func(L, "addTouchEventListener", _cocos2d_ui_Widget_addTouchEventListener);
    oluacls_func(L, "clone", _cocos2d_ui_Widget_clone);
    oluacls_func(L, "create", _cocos2d_ui_Widget_create);
    oluacls_func(L, "dispatchFocusEvent", _cocos2d_ui_Widget_dispatchFocusEvent);
    oluacls_func(L, "enableDpadNavigation", _cocos2d_ui_Widget_enableDpadNavigation);
    oluacls_func(L, "findNextFocusedWidget", _cocos2d_ui_Widget_findNextFocusedWidget);
    oluacls_func(L, "getActionTag", _cocos2d_ui_Widget_getActionTag);
    oluacls_func(L, "getBottomBoundary", _cocos2d_ui_Widget_getBottomBoundary);
    oluacls_func(L, "getCallbackName", _cocos2d_ui_Widget_getCallbackName);
    oluacls_func(L, "getCallbackType", _cocos2d_ui_Widget_getCallbackType);
    oluacls_func(L, "getCurrentFocusedWidget", _cocos2d_ui_Widget_getCurrentFocusedWidget);
    oluacls_func(L, "getCustomSize", _cocos2d_ui_Widget_getCustomSize);
    oluacls_func(L, "getLayoutParameter", _cocos2d_ui_Widget_getLayoutParameter);
    oluacls_func(L, "getLayoutSize", _cocos2d_ui_Widget_getLayoutSize);
    oluacls_func(L, "getLeftBoundary", _cocos2d_ui_Widget_getLeftBoundary);
    oluacls_func(L, "getPositionPercent", _cocos2d_ui_Widget_getPositionPercent);
    oluacls_func(L, "getPositionType", _cocos2d_ui_Widget_getPositionType);
    oluacls_func(L, "getRightBoundary", _cocos2d_ui_Widget_getRightBoundary);
    oluacls_func(L, "getSizePercent", _cocos2d_ui_Widget_getSizePercent);
    oluacls_func(L, "getSizeType", _cocos2d_ui_Widget_getSizeType);
    oluacls_func(L, "getTopBoundary", _cocos2d_ui_Widget_getTopBoundary);
    oluacls_func(L, "getTouchBeganPosition", _cocos2d_ui_Widget_getTouchBeganPosition);
    oluacls_func(L, "getTouchEndPosition", _cocos2d_ui_Widget_getTouchEndPosition);
    oluacls_func(L, "getTouchMovePosition", _cocos2d_ui_Widget_getTouchMovePosition);
    oluacls_func(L, "getVirtualRenderer", _cocos2d_ui_Widget_getVirtualRenderer);
    oluacls_func(L, "getVirtualRendererSize", _cocos2d_ui_Widget_getVirtualRendererSize);
    oluacls_func(L, "getWorldPosition", _cocos2d_ui_Widget_getWorldPosition);
    oluacls_func(L, "ignoreContentAdaptWithSize", _cocos2d_ui_Widget_ignoreContentAdaptWithSize);
    oluacls_func(L, "interceptTouchEvent", _cocos2d_ui_Widget_interceptTouchEvent);
    oluacls_func(L, "isBright", _cocos2d_ui_Widget_isBright);
    oluacls_func(L, "isClippingParentContainsPoint", _cocos2d_ui_Widget_isClippingParentContainsPoint);
    oluacls_func(L, "isEnabled", _cocos2d_ui_Widget_isEnabled);
    oluacls_func(L, "isFlippedX", _cocos2d_ui_Widget_isFlippedX);
    oluacls_func(L, "isFlippedY", _cocos2d_ui_Widget_isFlippedY);
    oluacls_func(L, "isFocusEnabled", _cocos2d_ui_Widget_isFocusEnabled);
    oluacls_func(L, "isFocused", _cocos2d_ui_Widget_isFocused);
    oluacls_func(L, "isHighlighted", _cocos2d_ui_Widget_isHighlighted);
    oluacls_func(L, "isIgnoreContentAdaptWithSize", _cocos2d_ui_Widget_isIgnoreContentAdaptWithSize);
    oluacls_func(L, "isLayoutComponentEnabled", _cocos2d_ui_Widget_isLayoutComponentEnabled);
    oluacls_func(L, "isPropagateTouchEvents", _cocos2d_ui_Widget_isPropagateTouchEvents);
    oluacls_func(L, "isSwallowTouches", _cocos2d_ui_Widget_isSwallowTouches);
    oluacls_func(L, "isTouchEnabled", _cocos2d_ui_Widget_isTouchEnabled);
    oluacls_func(L, "isUnifySizeEnabled", _cocos2d_ui_Widget_isUnifySizeEnabled);
    oluacls_func(L, "new", _cocos2d_ui_Widget_new);
    oluacls_func(L, "onFocusChange", _cocos2d_ui_Widget_onFocusChange);
    oluacls_func(L, "onTouchBegan", _cocos2d_ui_Widget_onTouchBegan);
    oluacls_func(L, "onTouchCancelled", _cocos2d_ui_Widget_onTouchCancelled);
    oluacls_func(L, "onTouchEnded", _cocos2d_ui_Widget_onTouchEnded);
    oluacls_func(L, "onTouchMoved", _cocos2d_ui_Widget_onTouchMoved);
    oluacls_func(L, "propagateTouchEvent", _cocos2d_ui_Widget_propagateTouchEvent);
    oluacls_func(L, "requestFocus", _cocos2d_ui_Widget_requestFocus);
    oluacls_func(L, "setActionTag", _cocos2d_ui_Widget_setActionTag);
    oluacls_func(L, "setBright", _cocos2d_ui_Widget_setBright);
    oluacls_func(L, "setBrightStyle", _cocos2d_ui_Widget_setBrightStyle);
    oluacls_func(L, "setCallbackName", _cocos2d_ui_Widget_setCallbackName);
    oluacls_func(L, "setCallbackType", _cocos2d_ui_Widget_setCallbackType);
    oluacls_func(L, "setEnabled", _cocos2d_ui_Widget_setEnabled);
    oluacls_func(L, "setFlippedX", _cocos2d_ui_Widget_setFlippedX);
    oluacls_func(L, "setFlippedY", _cocos2d_ui_Widget_setFlippedY);
    oluacls_func(L, "setFocusEnabled", _cocos2d_ui_Widget_setFocusEnabled);
    oluacls_func(L, "setFocused", _cocos2d_ui_Widget_setFocused);
    oluacls_func(L, "setHighlighted", _cocos2d_ui_Widget_setHighlighted);
    oluacls_func(L, "setLayoutComponentEnabled", _cocos2d_ui_Widget_setLayoutComponentEnabled);
    oluacls_func(L, "setLayoutParameter", _cocos2d_ui_Widget_setLayoutParameter);
    oluacls_func(L, "setPositionPercent", _cocos2d_ui_Widget_setPositionPercent);
    oluacls_func(L, "setPositionType", _cocos2d_ui_Widget_setPositionType);
    oluacls_func(L, "setPropagateTouchEvents", _cocos2d_ui_Widget_setPropagateTouchEvents);
    oluacls_func(L, "setSizePercent", _cocos2d_ui_Widget_setSizePercent);
    oluacls_func(L, "setSizeType", _cocos2d_ui_Widget_setSizeType);
    oluacls_func(L, "setSwallowTouches", _cocos2d_ui_Widget_setSwallowTouches);
    oluacls_func(L, "setTouchEnabled", _cocos2d_ui_Widget_setTouchEnabled);
    oluacls_func(L, "setUnifySizeEnabled", _cocos2d_ui_Widget_setUnifySizeEnabled);
    oluacls_func(L, "updateSizeAndPosition", _cocos2d_ui_Widget_updateSizeAndPosition);
    oluacls_prop(L, "actionTag", _cocos2d_ui_Widget_getActionTag, _cocos2d_ui_Widget_setActionTag);
    oluacls_prop(L, "bottomBoundary", _cocos2d_ui_Widget_getBottomBoundary, nullptr);
    oluacls_prop(L, "bright", _cocos2d_ui_Widget_isBright, _cocos2d_ui_Widget_setBright);
    oluacls_prop(L, "callbackName", _cocos2d_ui_Widget_getCallbackName, _cocos2d_ui_Widget_setCallbackName);
    oluacls_prop(L, "callbackType", _cocos2d_ui_Widget_getCallbackType, _cocos2d_ui_Widget_setCallbackType);
    oluacls_prop(L, "currentFocusedWidget", _cocos2d_ui_Widget_getCurrentFocusedWidget, nullptr);
    oluacls_prop(L, "customSize", _cocos2d_ui_Widget_getCustomSize, nullptr);
    oluacls_prop(L, "enabled", _cocos2d_ui_Widget_isEnabled, _cocos2d_ui_Widget_setEnabled);
    oluacls_prop(L, "flippedX", _cocos2d_ui_Widget_isFlippedX, _cocos2d_ui_Widget_setFlippedX);
    oluacls_prop(L, "flippedY", _cocos2d_ui_Widget_isFlippedY, _cocos2d_ui_Widget_setFlippedY);
    oluacls_prop(L, "focusEnabled", _cocos2d_ui_Widget_isFocusEnabled, _cocos2d_ui_Widget_setFocusEnabled);
    oluacls_prop(L, "focused", _cocos2d_ui_Widget_isFocused, _cocos2d_ui_Widget_setFocused);
    oluacls_prop(L, "highlighted", _cocos2d_ui_Widget_isHighlighted, _cocos2d_ui_Widget_setHighlighted);
    oluacls_prop(L, "ignoreContentAdaptWithSize", _cocos2d_ui_Widget_isIgnoreContentAdaptWithSize, nullptr);
    oluacls_prop(L, "layoutComponentEnabled", _cocos2d_ui_Widget_isLayoutComponentEnabled, _cocos2d_ui_Widget_setLayoutComponentEnabled);
    oluacls_prop(L, "layoutParameter", _cocos2d_ui_Widget_getLayoutParameter, _cocos2d_ui_Widget_setLayoutParameter);
    oluacls_prop(L, "layoutSize", _cocos2d_ui_Widget_getLayoutSize, nullptr);
    oluacls_prop(L, "leftBoundary", _cocos2d_ui_Widget_getLeftBoundary, nullptr);
    oluacls_prop(L, "positionPercent", _cocos2d_ui_Widget_getPositionPercent, _cocos2d_ui_Widget_setPositionPercent);
    oluacls_prop(L, "positionType", _cocos2d_ui_Widget_getPositionType, _cocos2d_ui_Widget_setPositionType);
    oluacls_prop(L, "propagateTouchEvents", _cocos2d_ui_Widget_isPropagateTouchEvents, _cocos2d_ui_Widget_setPropagateTouchEvents);
    oluacls_prop(L, "rightBoundary", _cocos2d_ui_Widget_getRightBoundary, nullptr);
    oluacls_prop(L, "sizePercent", _cocos2d_ui_Widget_getSizePercent, _cocos2d_ui_Widget_setSizePercent);
    oluacls_prop(L, "sizeType", _cocos2d_ui_Widget_getSizeType, _cocos2d_ui_Widget_setSizeType);
    oluacls_prop(L, "swallowTouches", _cocos2d_ui_Widget_isSwallowTouches, _cocos2d_ui_Widget_setSwallowTouches);
    oluacls_prop(L, "topBoundary", _cocos2d_ui_Widget_getTopBoundary, nullptr);
    oluacls_prop(L, "touchBeganPosition", _cocos2d_ui_Widget_getTouchBeganPosition, nullptr);
    oluacls_prop(L, "touchEnabled", _cocos2d_ui_Widget_isTouchEnabled, _cocos2d_ui_Widget_setTouchEnabled);
    oluacls_prop(L, "touchEndPosition", _cocos2d_ui_Widget_getTouchEndPosition, nullptr);
    oluacls_prop(L, "touchMovePosition", _cocos2d_ui_Widget_getTouchMovePosition, nullptr);
    oluacls_prop(L, "unifySizeEnabled", _cocos2d_ui_Widget_isUnifySizeEnabled, _cocos2d_ui_Widget_setUnifySizeEnabled);
    oluacls_prop(L, "virtualRenderer", _cocos2d_ui_Widget_getVirtualRenderer, nullptr);
    oluacls_prop(L, "virtualRendererSize", _cocos2d_ui_Widget_getVirtualRendererSize, nullptr);
    oluacls_prop(L, "worldPosition", _cocos2d_ui_Widget_getWorldPosition, nullptr);
    oluacls_prop(L, "onFocusChanged", _cocos2d_ui_Widget_get_onFocusChanged, _cocos2d_ui_Widget_set_onFocusChanged);
    oluacls_prop(L, "onNextFocusedWidget", _cocos2d_ui_Widget_get_onNextFocusedWidget, _cocos2d_ui_Widget_set_onNextFocusedWidget);

    olua_registerluatype<cocos2d::ui::Widget>(L, "ccui.Widget");

    return 1;
}

static int _cocos2d_ui_Helper___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::ui::Helper *)olua_toobj(L, 1, "ccui.Helper");
    olua_push_cppobj(L, self, "ccui.Helper");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_ui_Helper_changeLayoutSystemActiveState(lua_State *L)
{
    olua_startinvoke(L);

    bool arg1 = false;       /** active */

    olua_check_bool(L, 1, &arg1);

    // static void changeLayoutSystemActiveState(bool active)
    cocos2d::ui::Helper::changeLayoutSystemActiveState(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Helper_convertBoundingBoxToScreen(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Node *arg1 = nullptr;       /** node */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.Node");

    // static cocos2d::Rect convertBoundingBoxToScreen(cocos2d::Node *node)
    cocos2d::Rect ret = (cocos2d::Rect)cocos2d::ui::Helper::convertBoundingBoxToScreen(arg1);
    int num_ret = manual_olua_push_cocos2d_Rect(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Helper_doLayout(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Node *arg1 = nullptr;       /** rootNode */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.Node");

    // static void doLayout(cocos2d::Node *rootNode)
    cocos2d::ui::Helper::doLayout(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Helper_getSubStringOfUTF8String(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** str */
    lua_Unsigned arg2 = 0;       /** start */
    lua_Unsigned arg3 = 0;       /** length */

    olua_check_std_string(L, 1, &arg1);
    olua_check_uint(L, 2, &arg2);
    olua_check_uint(L, 3, &arg3);

    // static std::string getSubStringOfUTF8String(const std::string &str, std::string::size_type start, std::string::size_type length)
    std::string ret = (std::string)cocos2d::ui::Helper::getSubStringOfUTF8String(arg1, (std::string::size_type)arg2, (std::string::size_type)arg3);
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Helper_restrictCapInsetRect(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Rect arg1;       /** capInsets */
    cocos2d::Size arg2;       /** textureSize */

    manual_olua_check_cocos2d_Rect(L, 1, &arg1);
    auto_olua_check_cocos2d_Size(L, 2, &arg2);

    // static cocos2d::Rect restrictCapInsetRect(const cocos2d::Rect &capInsets, const cocos2d::Size &textureSize)
    cocos2d::Rect ret = (cocos2d::Rect)cocos2d::ui::Helper::restrictCapInsetRect(arg1, arg2);
    int num_ret = manual_olua_push_cocos2d_Rect(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Helper_seekActionWidgetByActionTag(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *arg1 = nullptr;       /** root */
    lua_Integer arg2 = 0;       /** tag */

    olua_check_cppobj(L, 1, (void **)&arg1, "ccui.Widget");
    olua_check_int(L, 2, &arg2);

    // static cocos2d::ui::Widget *seekActionWidgetByActionTag(cocos2d::ui::Widget *root, int tag)
    cocos2d::ui::Widget *ret = (cocos2d::ui::Widget *)cocos2d::ui::Helper::seekActionWidgetByActionTag(arg1, (int)arg2);
    int num_ret = olua_push_cppobj(L, ret, "ccui.Widget");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Helper_seekWidgetByName(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *arg1 = nullptr;       /** root */
    std::string arg2;       /** name */

    olua_check_cppobj(L, 1, (void **)&arg1, "ccui.Widget");
    olua_check_std_string(L, 2, &arg2);

    // static cocos2d::ui::Widget *seekWidgetByName(cocos2d::ui::Widget *root, const std::string &name)
    cocos2d::ui::Widget *ret = (cocos2d::ui::Widget *)cocos2d::ui::Helper::seekWidgetByName(arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "ccui.Widget");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Helper_seekWidgetByTag(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Widget *arg1 = nullptr;       /** root */
    lua_Integer arg2 = 0;       /** tag */

    olua_check_cppobj(L, 1, (void **)&arg1, "ccui.Widget");
    olua_check_int(L, 2, &arg2);

    // static cocos2d::ui::Widget *seekWidgetByTag(cocos2d::ui::Widget *root, int tag)
    cocos2d::ui::Widget *ret = (cocos2d::ui::Widget *)cocos2d::ui::Helper::seekWidgetByTag(arg1, (int)arg2);
    int num_ret = olua_push_cppobj(L, ret, "ccui.Widget");

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_ui_Helper(lua_State *L)
{
    oluacls_class(L, "ccui.Helper", nullptr);
    oluacls_func(L, "__move", _cocos2d_ui_Helper___move);
    oluacls_func(L, "changeLayoutSystemActiveState", _cocos2d_ui_Helper_changeLayoutSystemActiveState);
    oluacls_func(L, "convertBoundingBoxToScreen", _cocos2d_ui_Helper_convertBoundingBoxToScreen);
    oluacls_func(L, "doLayout", _cocos2d_ui_Helper_doLayout);
    oluacls_func(L, "getSubStringOfUTF8String", _cocos2d_ui_Helper_getSubStringOfUTF8String);
    oluacls_func(L, "restrictCapInsetRect", _cocos2d_ui_Helper_restrictCapInsetRect);
    oluacls_func(L, "seekActionWidgetByActionTag", _cocos2d_ui_Helper_seekActionWidgetByActionTag);
    oluacls_func(L, "seekWidgetByName", _cocos2d_ui_Helper_seekWidgetByName);
    oluacls_func(L, "seekWidgetByTag", _cocos2d_ui_Helper_seekWidgetByTag);

    olua_registerluatype<cocos2d::ui::Helper>(L, "ccui.Helper");

    return 1;
}

static int luaopen_cocos2d_ui_Scale9Sprite_State(lua_State *L)
{
    oluacls_class(L, "ccui.Scale9Sprite.State", nullptr);
    oluacls_const_integer(L, "GRAY", (lua_Integer)cocos2d::ui::Scale9Sprite::State::GRAY);
    oluacls_const_integer(L, "NORMAL", (lua_Integer)cocos2d::ui::Scale9Sprite::State::NORMAL);

    olua_registerluatype<cocos2d::ui::Scale9Sprite::State>(L, "ccui.Scale9Sprite.State");

    return 1;
}

static int luaopen_cocos2d_ui_Scale9Sprite_RenderingType(lua_State *L)
{
    oluacls_class(L, "ccui.Scale9Sprite.RenderingType", nullptr);
    oluacls_const_integer(L, "SIMPLE", (lua_Integer)cocos2d::ui::Scale9Sprite::RenderingType::SIMPLE);
    oluacls_const_integer(L, "SLICE", (lua_Integer)cocos2d::ui::Scale9Sprite::RenderingType::SLICE);

    olua_registerluatype<cocos2d::ui::Scale9Sprite::RenderingType>(L, "ccui.Scale9Sprite.RenderingType");

    return 1;
}

static int _cocos2d_ui_Scale9Sprite___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::ui::Scale9Sprite *)olua_toobj(L, 1, "ccui.Scale9Sprite");
    olua_push_cppobj(L, self, "ccui.Scale9Sprite");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_ui_Scale9Sprite_copyTo(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Scale9Sprite *self = nullptr;
    cocos2d::ui::Scale9Sprite *arg1 = nullptr;       /** copy */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Scale9Sprite");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccui.Scale9Sprite");

    // void copyTo(cocos2d::ui::Scale9Sprite *copy)
    self->copyTo(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Scale9Sprite_create1(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::ui::Scale9Sprite *create()
    cocos2d::ui::Scale9Sprite *ret = (cocos2d::ui::Scale9Sprite *)cocos2d::ui::Scale9Sprite::create();
    int num_ret = olua_push_cppobj(L, ret, "ccui.Scale9Sprite");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Scale9Sprite_create2(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** file */
    cocos2d::Rect arg2;       /** rect */
    cocos2d::Rect arg3;       /** capInsets */

    olua_check_std_string(L, 1, &arg1);
    manual_olua_check_cocos2d_Rect(L, 2, &arg2);
    manual_olua_check_cocos2d_Rect(L, 3, &arg3);

    // static cocos2d::ui::Scale9Sprite *create(const std::string &file, const cocos2d::Rect &rect, const cocos2d::Rect &capInsets)
    cocos2d::ui::Scale9Sprite *ret = (cocos2d::ui::Scale9Sprite *)cocos2d::ui::Scale9Sprite::create(arg1, arg2, arg3);
    int num_ret = olua_push_cppobj(L, ret, "ccui.Scale9Sprite");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Scale9Sprite_create3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Rect arg1;       /** capInsets */
    std::string arg2;       /** file */

    manual_olua_check_cocos2d_Rect(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);

    // static cocos2d::ui::Scale9Sprite *create(const cocos2d::Rect &capInsets, const std::string &file)
    cocos2d::ui::Scale9Sprite *ret = (cocos2d::ui::Scale9Sprite *)cocos2d::ui::Scale9Sprite::create(arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "ccui.Scale9Sprite");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Scale9Sprite_create4(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** file */
    cocos2d::Rect arg2;       /** rect */

    olua_check_std_string(L, 1, &arg1);
    manual_olua_check_cocos2d_Rect(L, 2, &arg2);

    // static cocos2d::ui::Scale9Sprite *create(const std::string &file, const cocos2d::Rect &rect)
    cocos2d::ui::Scale9Sprite *ret = (cocos2d::ui::Scale9Sprite *)cocos2d::ui::Scale9Sprite::create(arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "ccui.Scale9Sprite");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Scale9Sprite_create5(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** file */

    olua_check_std_string(L, 1, &arg1);

    // static cocos2d::ui::Scale9Sprite *create(const std::string &file)
    cocos2d::ui::Scale9Sprite *ret = (cocos2d::ui::Scale9Sprite *)cocos2d::ui::Scale9Sprite::create(arg1);
    int num_ret = olua_push_cppobj(L, ret, "ccui.Scale9Sprite");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Scale9Sprite_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // static cocos2d::ui::Scale9Sprite *create()
        return _cocos2d_ui_Scale9Sprite_create1(L);
    }

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 1))) {
            // static cocos2d::ui::Scale9Sprite *create(const std::string &file)
            return _cocos2d_ui_Scale9Sprite_create5(L);
        // }
    }

    if (num_args == 2) {
        if ((manual_olua_is_cocos2d_Rect(L, 1)) && (olua_is_std_string(L, 2))) {
            // static cocos2d::ui::Scale9Sprite *create(const cocos2d::Rect &capInsets, const std::string &file)
            return _cocos2d_ui_Scale9Sprite_create3(L);
        }

        // if ((olua_is_std_string(L, 1)) && (manual_olua_is_cocos2d_Rect(L, 2))) {
            // static cocos2d::ui::Scale9Sprite *create(const std::string &file, const cocos2d::Rect &rect)
            return _cocos2d_ui_Scale9Sprite_create4(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_std_string(L, 1)) && (manual_olua_is_cocos2d_Rect(L, 2)) && (manual_olua_is_cocos2d_Rect(L, 3))) {
            // static cocos2d::ui::Scale9Sprite *create(const std::string &file, const cocos2d::Rect &rect, const cocos2d::Rect &capInsets)
            return _cocos2d_ui_Scale9Sprite_create2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::Scale9Sprite::create' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ui_Scale9Sprite_createWithSpriteFrame1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::SpriteFrame *arg1 = nullptr;       /** spriteFrame */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.SpriteFrame");

    // static cocos2d::ui::Scale9Sprite *createWithSpriteFrame(cocos2d::SpriteFrame *spriteFrame)
    cocos2d::ui::Scale9Sprite *ret = (cocos2d::ui::Scale9Sprite *)cocos2d::ui::Scale9Sprite::createWithSpriteFrame(arg1);
    int num_ret = olua_push_cppobj(L, ret, "ccui.Scale9Sprite");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Scale9Sprite_createWithSpriteFrame2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::SpriteFrame *arg1 = nullptr;       /** spriteFrame */
    cocos2d::Rect arg2;       /** capInsets */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.SpriteFrame");
    manual_olua_check_cocos2d_Rect(L, 2, &arg2);

    // static cocos2d::ui::Scale9Sprite *createWithSpriteFrame(cocos2d::SpriteFrame *spriteFrame, const cocos2d::Rect &capInsets)
    cocos2d::ui::Scale9Sprite *ret = (cocos2d::ui::Scale9Sprite *)cocos2d::ui::Scale9Sprite::createWithSpriteFrame(arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "ccui.Scale9Sprite");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Scale9Sprite_createWithSpriteFrame(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_cppobj(L, 1, "cc.SpriteFrame"))) {
            // static cocos2d::ui::Scale9Sprite *createWithSpriteFrame(cocos2d::SpriteFrame *spriteFrame)
            return _cocos2d_ui_Scale9Sprite_createWithSpriteFrame1(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_cppobj(L, 1, "cc.SpriteFrame")) && (manual_olua_is_cocos2d_Rect(L, 2))) {
            // static cocos2d::ui::Scale9Sprite *createWithSpriteFrame(cocos2d::SpriteFrame *spriteFrame, const cocos2d::Rect &capInsets)
            return _cocos2d_ui_Scale9Sprite_createWithSpriteFrame2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::Scale9Sprite::createWithSpriteFrame' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ui_Scale9Sprite_createWithSpriteFrameName1(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** spriteFrameName */

    olua_check_std_string(L, 1, &arg1);

    // static cocos2d::ui::Scale9Sprite *createWithSpriteFrameName(const std::string &spriteFrameName)
    cocos2d::ui::Scale9Sprite *ret = (cocos2d::ui::Scale9Sprite *)cocos2d::ui::Scale9Sprite::createWithSpriteFrameName(arg1);
    int num_ret = olua_push_cppobj(L, ret, "ccui.Scale9Sprite");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Scale9Sprite_createWithSpriteFrameName2(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** spriteFrameName */
    cocos2d::Rect arg2;       /** capInsets */

    olua_check_std_string(L, 1, &arg1);
    manual_olua_check_cocos2d_Rect(L, 2, &arg2);

    // static cocos2d::ui::Scale9Sprite *createWithSpriteFrameName(const std::string &spriteFrameName, const cocos2d::Rect &capInsets)
    cocos2d::ui::Scale9Sprite *ret = (cocos2d::ui::Scale9Sprite *)cocos2d::ui::Scale9Sprite::createWithSpriteFrameName(arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "ccui.Scale9Sprite");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Scale9Sprite_createWithSpriteFrameName(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 1))) {
            // static cocos2d::ui::Scale9Sprite *createWithSpriteFrameName(const std::string &spriteFrameName)
            return _cocos2d_ui_Scale9Sprite_createWithSpriteFrameName1(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 1)) && (manual_olua_is_cocos2d_Rect(L, 2))) {
            // static cocos2d::ui::Scale9Sprite *createWithSpriteFrameName(const std::string &spriteFrameName, const cocos2d::Rect &capInsets)
            return _cocos2d_ui_Scale9Sprite_createWithSpriteFrameName2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::Scale9Sprite::createWithSpriteFrameName' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ui_Scale9Sprite_getCapInsets(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Scale9Sprite *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Scale9Sprite");

    // cocos2d::Rect getCapInsets()
    cocos2d::Rect ret = (cocos2d::Rect)self->getCapInsets();
    int num_ret = manual_olua_push_cocos2d_Rect(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Scale9Sprite_getInsetBottom(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Scale9Sprite *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Scale9Sprite");

    // float getInsetBottom()
    float ret = (float)self->getInsetBottom();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Scale9Sprite_getInsetLeft(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Scale9Sprite *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Scale9Sprite");

    // float getInsetLeft()
    float ret = (float)self->getInsetLeft();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Scale9Sprite_getInsetRight(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Scale9Sprite *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Scale9Sprite");

    // float getInsetRight()
    float ret = (float)self->getInsetRight();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Scale9Sprite_getInsetTop(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Scale9Sprite *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Scale9Sprite");

    // float getInsetTop()
    float ret = (float)self->getInsetTop();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Scale9Sprite_getOriginalSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Scale9Sprite *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Scale9Sprite");

    // cocos2d::Size getOriginalSize()
    cocos2d::Size ret = (cocos2d::Size)self->getOriginalSize();
    int num_ret = auto_olua_push_cocos2d_Size(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Scale9Sprite_getPreferredSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Scale9Sprite *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Scale9Sprite");

    // cocos2d::Size getPreferredSize()
    cocos2d::Size ret = (cocos2d::Size)self->getPreferredSize();
    int num_ret = auto_olua_push_cocos2d_Size(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Scale9Sprite_getRenderingType(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Scale9Sprite *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Scale9Sprite");

    // cocos2d::ui::Scale9Sprite::RenderingType getRenderingType()
    cocos2d::ui::Scale9Sprite::RenderingType ret = (cocos2d::ui::Scale9Sprite::RenderingType)self->getRenderingType();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Scale9Sprite_getSprite(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Scale9Sprite *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Scale9Sprite");

    // cocos2d::Sprite *getSprite()
    cocos2d::Sprite *ret = (cocos2d::Sprite *)self->getSprite();
    int num_ret = olua_push_cppobj(L, ret, "cc.Sprite");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Scale9Sprite_getState(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Scale9Sprite *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Scale9Sprite");

    // cocos2d::ui::Scale9Sprite::State getState()
    cocos2d::ui::Scale9Sprite::State ret = (cocos2d::ui::Scale9Sprite::State)self->getState();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Scale9Sprite_init1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Scale9Sprite *self = nullptr;
    cocos2d::Sprite *arg1 = nullptr;       /** sprite */
    cocos2d::Rect arg2;       /** rect */
    bool arg3 = false;       /** rotated */
    cocos2d::Rect arg4;       /** capInsets */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Scale9Sprite");
    olua_check_cppobj(L, 2, (void **)&arg1, "cc.Sprite");
    manual_olua_check_cocos2d_Rect(L, 3, &arg2);
    olua_check_bool(L, 4, &arg3);
    manual_olua_check_cocos2d_Rect(L, 5, &arg4);

    // bool init(cocos2d::Sprite *sprite, const cocos2d::Rect &rect, bool rotated, const cocos2d::Rect &capInsets)
    bool ret = (bool)self->init(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Scale9Sprite_init2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Scale9Sprite *self = nullptr;
    cocos2d::Sprite *arg1 = nullptr;       /** sprite */
    cocos2d::Rect arg2;       /** rect */
    cocos2d::Rect arg3;       /** capInsets */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Scale9Sprite");
    olua_check_cppobj(L, 2, (void **)&arg1, "cc.Sprite");
    manual_olua_check_cocos2d_Rect(L, 3, &arg2);
    manual_olua_check_cocos2d_Rect(L, 4, &arg3);

    // bool init(cocos2d::Sprite *sprite, const cocos2d::Rect &rect, const cocos2d::Rect &capInsets)
    bool ret = (bool)self->init(arg1, arg2, arg3);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Scale9Sprite_init3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Scale9Sprite *self = nullptr;
    cocos2d::Sprite *arg1 = nullptr;       /** sprite */
    cocos2d::Rect arg2;       /** rect */
    bool arg3 = false;       /** rotated */
    cocos2d::Vec2 arg4;       /** offset */
    cocos2d::Size arg5;       /** originalSize */
    cocos2d::Rect arg6;       /** capInsets */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Scale9Sprite");
    olua_check_cppobj(L, 2, (void **)&arg1, "cc.Sprite");
    manual_olua_check_cocos2d_Rect(L, 3, &arg2);
    olua_check_bool(L, 4, &arg3);
    auto_olua_check_cocos2d_Vec2(L, 5, &arg4);
    auto_olua_check_cocos2d_Size(L, 6, &arg5);
    manual_olua_check_cocos2d_Rect(L, 7, &arg6);

    // bool init(cocos2d::Sprite *sprite, const cocos2d::Rect &rect, bool rotated, const cocos2d::Vec2 &offset, const cocos2d::Size &originalSize, const cocos2d::Rect &capInsets)
    bool ret = (bool)self->init(arg1, arg2, arg3, arg4, arg5, arg6);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Scale9Sprite_init(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 3) {
        // if ((olua_is_cppobj(L, 2, "cc.Sprite")) && (manual_olua_is_cocos2d_Rect(L, 3)) && (manual_olua_is_cocos2d_Rect(L, 4))) {
            // bool init(cocos2d::Sprite *sprite, const cocos2d::Rect &rect, const cocos2d::Rect &capInsets)
            return _cocos2d_ui_Scale9Sprite_init2(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_cppobj(L, 2, "cc.Sprite")) && (manual_olua_is_cocos2d_Rect(L, 3)) && (olua_is_bool(L, 4)) && (manual_olua_is_cocos2d_Rect(L, 5))) {
            // bool init(cocos2d::Sprite *sprite, const cocos2d::Rect &rect, bool rotated, const cocos2d::Rect &capInsets)
            return _cocos2d_ui_Scale9Sprite_init1(L);
        // }
    }

    if (num_args == 6) {
        // if ((olua_is_cppobj(L, 2, "cc.Sprite")) && (manual_olua_is_cocos2d_Rect(L, 3)) && (olua_is_bool(L, 4)) && (auto_olua_is_cocos2d_Vec2(L, 5)) && (auto_olua_is_cocos2d_Size(L, 6)) && (manual_olua_is_cocos2d_Rect(L, 7))) {
            // bool init(cocos2d::Sprite *sprite, const cocos2d::Rect &rect, bool rotated, const cocos2d::Vec2 &offset, const cocos2d::Size &originalSize, const cocos2d::Rect &capInsets)
            return _cocos2d_ui_Scale9Sprite_init3(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::Scale9Sprite::init' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ui_Scale9Sprite_initWithFile1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Scale9Sprite *self = nullptr;
    std::string arg1;       /** file */
    cocos2d::Rect arg2;       /** rect */
    cocos2d::Rect arg3;       /** capInsets */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Scale9Sprite");
    olua_check_std_string(L, 2, &arg1);
    manual_olua_check_cocos2d_Rect(L, 3, &arg2);
    manual_olua_check_cocos2d_Rect(L, 4, &arg3);

    // bool initWithFile(const std::string &file, const cocos2d::Rect &rect, const cocos2d::Rect &capInsets)
    bool ret = (bool)self->initWithFile(arg1, arg2, arg3);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Scale9Sprite_initWithFile2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Scale9Sprite *self = nullptr;
    cocos2d::Rect arg1;       /** capInsets */
    std::string arg2;       /** file */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Scale9Sprite");
    manual_olua_check_cocos2d_Rect(L, 2, &arg1);
    olua_check_std_string(L, 3, &arg2);

    // bool initWithFile(const cocos2d::Rect &capInsets, const std::string &file)
    bool ret = (bool)self->initWithFile(arg1, arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Scale9Sprite_initWithFile(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 2) {
        // if ((manual_olua_is_cocos2d_Rect(L, 2)) && (olua_is_std_string(L, 3))) {
            // bool initWithFile(const cocos2d::Rect &capInsets, const std::string &file)
            return _cocos2d_ui_Scale9Sprite_initWithFile2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_std_string(L, 2)) && (manual_olua_is_cocos2d_Rect(L, 3)) && (manual_olua_is_cocos2d_Rect(L, 4))) {
            // bool initWithFile(const std::string &file, const cocos2d::Rect &rect, const cocos2d::Rect &capInsets)
            return _cocos2d_ui_Scale9Sprite_initWithFile1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::Scale9Sprite::initWithFile' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ui_Scale9Sprite_initWithSpriteFrame(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Scale9Sprite *self = nullptr;
    cocos2d::SpriteFrame *arg1 = nullptr;       /** spriteFrame */
    cocos2d::Rect arg2;       /** capInsets */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Scale9Sprite");
    olua_check_cppobj(L, 2, (void **)&arg1, "cc.SpriteFrame");
    manual_olua_check_cocos2d_Rect(L, 3, &arg2);

    // bool initWithSpriteFrame(cocos2d::SpriteFrame *spriteFrame, const cocos2d::Rect &capInsets)
    bool ret = (bool)self->initWithSpriteFrame(arg1, arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Scale9Sprite_initWithSpriteFrameName(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Scale9Sprite *self = nullptr;
    std::string arg1;       /** spriteFrameName */
    cocos2d::Rect arg2;       /** capInsets */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Scale9Sprite");
    olua_check_std_string(L, 2, &arg1);
    manual_olua_check_cocos2d_Rect(L, 3, &arg2);

    // bool initWithSpriteFrameName(const std::string &spriteFrameName, const cocos2d::Rect &capInsets)
    bool ret = (bool)self->initWithSpriteFrameName(arg1, arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Scale9Sprite_isScale9Enabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Scale9Sprite *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Scale9Sprite");

    // bool isScale9Enabled()
    bool ret = (bool)self->isScale9Enabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Scale9Sprite_new(lua_State *L)
{
    olua_startinvoke(L);

    // Scale9Sprite()
    cocos2d::ui::Scale9Sprite *ret = (cocos2d::ui::Scale9Sprite *)new cocos2d::ui::Scale9Sprite();
    int num_ret = olua_push_cppobj(L, ret, "ccui.Scale9Sprite");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Scale9Sprite_resetRender(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Scale9Sprite *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Scale9Sprite");

    // void resetRender()
    self->resetRender();

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Scale9Sprite_resizableSpriteWithCapInsets(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Scale9Sprite *self = nullptr;
    cocos2d::Rect arg1;       /** capInsets */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Scale9Sprite");
    manual_olua_check_cocos2d_Rect(L, 2, &arg1);

    // cocos2d::ui::Scale9Sprite *resizableSpriteWithCapInsets(const cocos2d::Rect &capInsets)
    cocos2d::ui::Scale9Sprite *ret = (cocos2d::ui::Scale9Sprite *)self->resizableSpriteWithCapInsets(arg1);
    int num_ret = olua_push_cppobj(L, ret, "ccui.Scale9Sprite");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Scale9Sprite_setCapInsets(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Scale9Sprite *self = nullptr;
    cocos2d::Rect arg1;       /** insets */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Scale9Sprite");
    manual_olua_check_cocos2d_Rect(L, 2, &arg1);

    // void setCapInsets(const cocos2d::Rect &insets)
    self->setCapInsets(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Scale9Sprite_setInsetBottom(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Scale9Sprite *self = nullptr;
    lua_Number arg1 = 0;       /** bottomInset */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Scale9Sprite");
    olua_check_number(L, 2, &arg1);

    // void setInsetBottom(float bottomInset)
    self->setInsetBottom((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Scale9Sprite_setInsetLeft(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Scale9Sprite *self = nullptr;
    lua_Number arg1 = 0;       /** leftInset */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Scale9Sprite");
    olua_check_number(L, 2, &arg1);

    // void setInsetLeft(float leftInset)
    self->setInsetLeft((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Scale9Sprite_setInsetRight(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Scale9Sprite *self = nullptr;
    lua_Number arg1 = 0;       /** rightInset */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Scale9Sprite");
    olua_check_number(L, 2, &arg1);

    // void setInsetRight(float rightInset)
    self->setInsetRight((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Scale9Sprite_setInsetTop(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Scale9Sprite *self = nullptr;
    lua_Number arg1 = 0;       /** topInset */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Scale9Sprite");
    olua_check_number(L, 2, &arg1);

    // void setInsetTop(float topInset)
    self->setInsetTop((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Scale9Sprite_setPreferredSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Scale9Sprite *self = nullptr;
    cocos2d::Size arg1;       /** size */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Scale9Sprite");
    auto_olua_check_cocos2d_Size(L, 2, &arg1);

    // void setPreferredSize(const cocos2d::Size &size)
    self->setPreferredSize(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Scale9Sprite_setRenderingType(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Scale9Sprite *self = nullptr;
    lua_Unsigned arg1 = 0;       /** type */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Scale9Sprite");
    olua_check_uint(L, 2, &arg1);

    // void setRenderingType(cocos2d::ui::Scale9Sprite::RenderingType type)
    self->setRenderingType((cocos2d::ui::Scale9Sprite::RenderingType)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Scale9Sprite_setScale9Enabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Scale9Sprite *self = nullptr;
    bool arg1 = false;       /** enabled */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Scale9Sprite");
    olua_check_bool(L, 2, &arg1);

    // void setScale9Enabled(bool enabled)
    self->setScale9Enabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Scale9Sprite_setSpriteFrame(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Scale9Sprite *self = nullptr;
    cocos2d::SpriteFrame *arg1 = nullptr;       /** spriteFrame */
    cocos2d::Rect arg2;       /** capInsets */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Scale9Sprite");
    olua_check_cppobj(L, 2, (void **)&arg1, "cc.SpriteFrame");
    manual_olua_check_cocos2d_Rect(L, 3, &arg2);

    // void setSpriteFrame(cocos2d::SpriteFrame *spriteFrame, const cocos2d::Rect &capInsets)
    self->setSpriteFrame(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Scale9Sprite_setState(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Scale9Sprite *self = nullptr;
    lua_Unsigned arg1 = 0;       /** state */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Scale9Sprite");
    olua_check_uint(L, 2, &arg1);

    // void setState(cocos2d::ui::Scale9Sprite::State state)
    self->setState((cocos2d::ui::Scale9Sprite::State)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Scale9Sprite_updateWithSprite1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Scale9Sprite *self = nullptr;
    cocos2d::Sprite *arg1 = nullptr;       /** sprite */
    cocos2d::Rect arg2;       /** rect */
    bool arg3 = false;       /** rotated */
    cocos2d::Rect arg4;       /** capInsets */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Scale9Sprite");
    olua_check_cppobj(L, 2, (void **)&arg1, "cc.Sprite");
    manual_olua_check_cocos2d_Rect(L, 3, &arg2);
    olua_check_bool(L, 4, &arg3);
    manual_olua_check_cocos2d_Rect(L, 5, &arg4);

    // bool updateWithSprite(cocos2d::Sprite *sprite, const cocos2d::Rect &rect, bool rotated, const cocos2d::Rect &capInsets)
    bool ret = (bool)self->updateWithSprite(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Scale9Sprite_updateWithSprite2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Scale9Sprite *self = nullptr;
    cocos2d::Sprite *arg1 = nullptr;       /** sprite */
    cocos2d::Rect arg2;       /** rect */
    bool arg3 = false;       /** rotated */
    cocos2d::Vec2 arg4;       /** offset */
    cocos2d::Size arg5;       /** originalSize */
    cocos2d::Rect arg6;       /** capInsets */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Scale9Sprite");
    olua_check_cppobj(L, 2, (void **)&arg1, "cc.Sprite");
    manual_olua_check_cocos2d_Rect(L, 3, &arg2);
    olua_check_bool(L, 4, &arg3);
    auto_olua_check_cocos2d_Vec2(L, 5, &arg4);
    auto_olua_check_cocos2d_Size(L, 6, &arg5);
    manual_olua_check_cocos2d_Rect(L, 7, &arg6);

    // bool updateWithSprite(cocos2d::Sprite *sprite, const cocos2d::Rect &rect, bool rotated, const cocos2d::Vec2 &offset, const cocos2d::Size &originalSize, const cocos2d::Rect &capInsets)
    bool ret = (bool)self->updateWithSprite(arg1, arg2, arg3, arg4, arg5, arg6);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Scale9Sprite_updateWithSprite(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 4) {
        // if ((olua_is_cppobj(L, 2, "cc.Sprite")) && (manual_olua_is_cocos2d_Rect(L, 3)) && (olua_is_bool(L, 4)) && (manual_olua_is_cocos2d_Rect(L, 5))) {
            // bool updateWithSprite(cocos2d::Sprite *sprite, const cocos2d::Rect &rect, bool rotated, const cocos2d::Rect &capInsets)
            return _cocos2d_ui_Scale9Sprite_updateWithSprite1(L);
        // }
    }

    if (num_args == 6) {
        // if ((olua_is_cppobj(L, 2, "cc.Sprite")) && (manual_olua_is_cocos2d_Rect(L, 3)) && (olua_is_bool(L, 4)) && (auto_olua_is_cocos2d_Vec2(L, 5)) && (auto_olua_is_cocos2d_Size(L, 6)) && (manual_olua_is_cocos2d_Rect(L, 7))) {
            // bool updateWithSprite(cocos2d::Sprite *sprite, const cocos2d::Rect &rect, bool rotated, const cocos2d::Vec2 &offset, const cocos2d::Size &originalSize, const cocos2d::Rect &capInsets)
            return _cocos2d_ui_Scale9Sprite_updateWithSprite2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::Scale9Sprite::updateWithSprite' not support '%d' arguments", num_args);

    return 0;
}

static int luaopen_cocos2d_ui_Scale9Sprite(lua_State *L)
{
    oluacls_class(L, "ccui.Scale9Sprite", "cc.Sprite");
    oluacls_func(L, "__move", _cocos2d_ui_Scale9Sprite___move);
    oluacls_func(L, "copyTo", _cocos2d_ui_Scale9Sprite_copyTo);
    oluacls_func(L, "create", _cocos2d_ui_Scale9Sprite_create);
    oluacls_func(L, "createWithSpriteFrame", _cocos2d_ui_Scale9Sprite_createWithSpriteFrame);
    oluacls_func(L, "createWithSpriteFrameName", _cocos2d_ui_Scale9Sprite_createWithSpriteFrameName);
    oluacls_func(L, "getCapInsets", _cocos2d_ui_Scale9Sprite_getCapInsets);
    oluacls_func(L, "getInsetBottom", _cocos2d_ui_Scale9Sprite_getInsetBottom);
    oluacls_func(L, "getInsetLeft", _cocos2d_ui_Scale9Sprite_getInsetLeft);
    oluacls_func(L, "getInsetRight", _cocos2d_ui_Scale9Sprite_getInsetRight);
    oluacls_func(L, "getInsetTop", _cocos2d_ui_Scale9Sprite_getInsetTop);
    oluacls_func(L, "getOriginalSize", _cocos2d_ui_Scale9Sprite_getOriginalSize);
    oluacls_func(L, "getPreferredSize", _cocos2d_ui_Scale9Sprite_getPreferredSize);
    oluacls_func(L, "getRenderingType", _cocos2d_ui_Scale9Sprite_getRenderingType);
    oluacls_func(L, "getSprite", _cocos2d_ui_Scale9Sprite_getSprite);
    oluacls_func(L, "getState", _cocos2d_ui_Scale9Sprite_getState);
    oluacls_func(L, "init", _cocos2d_ui_Scale9Sprite_init);
    oluacls_func(L, "initWithFile", _cocos2d_ui_Scale9Sprite_initWithFile);
    oluacls_func(L, "initWithSpriteFrame", _cocos2d_ui_Scale9Sprite_initWithSpriteFrame);
    oluacls_func(L, "initWithSpriteFrameName", _cocos2d_ui_Scale9Sprite_initWithSpriteFrameName);
    oluacls_func(L, "isScale9Enabled", _cocos2d_ui_Scale9Sprite_isScale9Enabled);
    oluacls_func(L, "new", _cocos2d_ui_Scale9Sprite_new);
    oluacls_func(L, "resetRender", _cocos2d_ui_Scale9Sprite_resetRender);
    oluacls_func(L, "resizableSpriteWithCapInsets", _cocos2d_ui_Scale9Sprite_resizableSpriteWithCapInsets);
    oluacls_func(L, "setCapInsets", _cocos2d_ui_Scale9Sprite_setCapInsets);
    oluacls_func(L, "setInsetBottom", _cocos2d_ui_Scale9Sprite_setInsetBottom);
    oluacls_func(L, "setInsetLeft", _cocos2d_ui_Scale9Sprite_setInsetLeft);
    oluacls_func(L, "setInsetRight", _cocos2d_ui_Scale9Sprite_setInsetRight);
    oluacls_func(L, "setInsetTop", _cocos2d_ui_Scale9Sprite_setInsetTop);
    oluacls_func(L, "setPreferredSize", _cocos2d_ui_Scale9Sprite_setPreferredSize);
    oluacls_func(L, "setRenderingType", _cocos2d_ui_Scale9Sprite_setRenderingType);
    oluacls_func(L, "setScale9Enabled", _cocos2d_ui_Scale9Sprite_setScale9Enabled);
    oluacls_func(L, "setSpriteFrame", _cocos2d_ui_Scale9Sprite_setSpriteFrame);
    oluacls_func(L, "setState", _cocos2d_ui_Scale9Sprite_setState);
    oluacls_func(L, "updateWithSprite", _cocos2d_ui_Scale9Sprite_updateWithSprite);
    oluacls_prop(L, "capInsets", _cocos2d_ui_Scale9Sprite_getCapInsets, _cocos2d_ui_Scale9Sprite_setCapInsets);
    oluacls_prop(L, "insetBottom", _cocos2d_ui_Scale9Sprite_getInsetBottom, _cocos2d_ui_Scale9Sprite_setInsetBottom);
    oluacls_prop(L, "insetLeft", _cocos2d_ui_Scale9Sprite_getInsetLeft, _cocos2d_ui_Scale9Sprite_setInsetLeft);
    oluacls_prop(L, "insetRight", _cocos2d_ui_Scale9Sprite_getInsetRight, _cocos2d_ui_Scale9Sprite_setInsetRight);
    oluacls_prop(L, "insetTop", _cocos2d_ui_Scale9Sprite_getInsetTop, _cocos2d_ui_Scale9Sprite_setInsetTop);
    oluacls_prop(L, "originalSize", _cocos2d_ui_Scale9Sprite_getOriginalSize, nullptr);
    oluacls_prop(L, "preferredSize", _cocos2d_ui_Scale9Sprite_getPreferredSize, _cocos2d_ui_Scale9Sprite_setPreferredSize);
    oluacls_prop(L, "renderingType", _cocos2d_ui_Scale9Sprite_getRenderingType, _cocos2d_ui_Scale9Sprite_setRenderingType);
    oluacls_prop(L, "scale9Enabled", _cocos2d_ui_Scale9Sprite_isScale9Enabled, _cocos2d_ui_Scale9Sprite_setScale9Enabled);
    oluacls_prop(L, "sprite", _cocos2d_ui_Scale9Sprite_getSprite, nullptr);
    oluacls_prop(L, "state", _cocos2d_ui_Scale9Sprite_getState, _cocos2d_ui_Scale9Sprite_setState);

    olua_registerluatype<cocos2d::ui::Scale9Sprite>(L, "ccui.Scale9Sprite");

    return 1;
}

static int luaopen_cocos2d_ui_LayoutComponent_HorizontalEdge(lua_State *L)
{
    oluacls_class(L, "ccui.LayoutComponent.HorizontalEdge", nullptr);
    oluacls_const_integer(L, "Center", (lua_Integer)cocos2d::ui::LayoutComponent::HorizontalEdge::Center);
    oluacls_const_integer(L, "Left", (lua_Integer)cocos2d::ui::LayoutComponent::HorizontalEdge::Left);
    oluacls_const_integer(L, "None", (lua_Integer)cocos2d::ui::LayoutComponent::HorizontalEdge::None);
    oluacls_const_integer(L, "Right", (lua_Integer)cocos2d::ui::LayoutComponent::HorizontalEdge::Right);

    olua_registerluatype<cocos2d::ui::LayoutComponent::HorizontalEdge>(L, "ccui.LayoutComponent.HorizontalEdge");

    return 1;
}

static int luaopen_cocos2d_ui_LayoutComponent_VerticalEdge(lua_State *L)
{
    oluacls_class(L, "ccui.LayoutComponent.VerticalEdge", nullptr);
    oluacls_const_integer(L, "Bottom", (lua_Integer)cocos2d::ui::LayoutComponent::VerticalEdge::Bottom);
    oluacls_const_integer(L, "Center", (lua_Integer)cocos2d::ui::LayoutComponent::VerticalEdge::Center);
    oluacls_const_integer(L, "None", (lua_Integer)cocos2d::ui::LayoutComponent::VerticalEdge::None);
    oluacls_const_integer(L, "Top", (lua_Integer)cocos2d::ui::LayoutComponent::VerticalEdge::Top);

    olua_registerluatype<cocos2d::ui::LayoutComponent::VerticalEdge>(L, "ccui.LayoutComponent.VerticalEdge");

    return 1;
}

static int _cocos2d_ui_LayoutComponent___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::ui::LayoutComponent *)olua_toobj(L, 1, "ccui.LayoutComponent");
    olua_push_cppobj(L, self, "ccui.LayoutComponent");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_ui_LayoutComponent_bindLayoutComponent(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Node *arg1 = nullptr;       /** node */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.Node");

    // static cocos2d::ui::LayoutComponent *bindLayoutComponent(cocos2d::Node *node)
    cocos2d::ui::LayoutComponent *ret = (cocos2d::ui::LayoutComponent *)cocos2d::ui::LayoutComponent::bindLayoutComponent(arg1);
    int num_ret = olua_push_cppobj(L, ret, "ccui.LayoutComponent");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_LayoutComponent_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::ui::LayoutComponent *create()
    cocos2d::ui::LayoutComponent *ret = (cocos2d::ui::LayoutComponent *)cocos2d::ui::LayoutComponent::create();
    int num_ret = olua_push_cppobj(L, ret, "ccui.LayoutComponent");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_LayoutComponent_getAnchorPosition(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.LayoutComponent");

    // const cocos2d::Point &getAnchorPosition()
    const cocos2d::Point &ret = (const cocos2d::Point &)self->getAnchorPosition();
    int num_ret = auto_olua_push_cocos2d_Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_LayoutComponent_getBottomMargin(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.LayoutComponent");

    // float getBottomMargin()
    float ret = (float)self->getBottomMargin();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_LayoutComponent_getHorizontalEdge(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.LayoutComponent");

    // cocos2d::ui::LayoutComponent::HorizontalEdge getHorizontalEdge()
    cocos2d::ui::LayoutComponent::HorizontalEdge ret = (cocos2d::ui::LayoutComponent::HorizontalEdge)self->getHorizontalEdge();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_LayoutComponent_getLeftMargin(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.LayoutComponent");

    // float getLeftMargin()
    float ret = (float)self->getLeftMargin();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_LayoutComponent_getPercentContentSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.LayoutComponent");

    // cocos2d::Vec2 getPercentContentSize()
    cocos2d::Vec2 ret = (cocos2d::Vec2)self->getPercentContentSize();
    int num_ret = auto_olua_push_cocos2d_Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_LayoutComponent_getPercentHeight(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.LayoutComponent");

    // float getPercentHeight()
    float ret = (float)self->getPercentHeight();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_LayoutComponent_getPercentWidth(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.LayoutComponent");

    // float getPercentWidth()
    float ret = (float)self->getPercentWidth();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_LayoutComponent_getPosition(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.LayoutComponent");

    // const cocos2d::Point &getPosition()
    const cocos2d::Point &ret = (const cocos2d::Point &)self->getPosition();
    int num_ret = auto_olua_push_cocos2d_Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_LayoutComponent_getPositionPercentX(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.LayoutComponent");

    // float getPositionPercentX()
    float ret = (float)self->getPositionPercentX();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_LayoutComponent_getPositionPercentY(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.LayoutComponent");

    // float getPositionPercentY()
    float ret = (float)self->getPositionPercentY();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_LayoutComponent_getRightMargin(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.LayoutComponent");

    // float getRightMargin()
    float ret = (float)self->getRightMargin();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_LayoutComponent_getSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.LayoutComponent");

    // const cocos2d::Size &getSize()
    const cocos2d::Size &ret = (const cocos2d::Size &)self->getSize();
    int num_ret = auto_olua_push_cocos2d_Size(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_LayoutComponent_getSizeHeight(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.LayoutComponent");

    // float getSizeHeight()
    float ret = (float)self->getSizeHeight();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_LayoutComponent_getSizeWidth(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.LayoutComponent");

    // float getSizeWidth()
    float ret = (float)self->getSizeWidth();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_LayoutComponent_getTopMargin(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.LayoutComponent");

    // float getTopMargin()
    float ret = (float)self->getTopMargin();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_LayoutComponent_getUsingPercentContentSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.LayoutComponent");

    // bool getUsingPercentContentSize()
    bool ret = (bool)self->getUsingPercentContentSize();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_LayoutComponent_getVerticalEdge(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.LayoutComponent");

    // cocos2d::ui::LayoutComponent::VerticalEdge getVerticalEdge()
    cocos2d::ui::LayoutComponent::VerticalEdge ret = (cocos2d::ui::LayoutComponent::VerticalEdge)self->getVerticalEdge();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_LayoutComponent_isPercentHeightEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.LayoutComponent");

    // bool isPercentHeightEnabled()
    bool ret = (bool)self->isPercentHeightEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_LayoutComponent_isPercentWidthEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.LayoutComponent");

    // bool isPercentWidthEnabled()
    bool ret = (bool)self->isPercentWidthEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_LayoutComponent_isPositionPercentXEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.LayoutComponent");

    // bool isPositionPercentXEnabled()
    bool ret = (bool)self->isPositionPercentXEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_LayoutComponent_isPositionPercentYEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.LayoutComponent");

    // bool isPositionPercentYEnabled()
    bool ret = (bool)self->isPositionPercentYEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_LayoutComponent_isStretchHeightEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.LayoutComponent");

    // bool isStretchHeightEnabled()
    bool ret = (bool)self->isStretchHeightEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_LayoutComponent_isStretchWidthEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.LayoutComponent");

    // bool isStretchWidthEnabled()
    bool ret = (bool)self->isStretchWidthEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_LayoutComponent_new(lua_State *L)
{
    olua_startinvoke(L);

    // LayoutComponent()
    cocos2d::ui::LayoutComponent *ret = (cocos2d::ui::LayoutComponent *)new cocos2d::ui::LayoutComponent();
    int num_ret = olua_push_cppobj(L, ret, "ccui.LayoutComponent");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_LayoutComponent_refreshLayout(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.LayoutComponent");

    // void refreshLayout()
    self->refreshLayout();

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_LayoutComponent_setActiveEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;
    bool arg1 = false;       /** enable */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.LayoutComponent");
    olua_check_bool(L, 2, &arg1);

    // void setActiveEnabled(bool enable)
    self->setActiveEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_LayoutComponent_setAnchorPosition(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;
    cocos2d::Point arg1;       /** point */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.LayoutComponent");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);

    // void setAnchorPosition(const cocos2d::Point &point)
    self->setAnchorPosition(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_LayoutComponent_setBottomMargin(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;
    lua_Number arg1 = 0;       /** margin */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.LayoutComponent");
    olua_check_number(L, 2, &arg1);

    // void setBottomMargin(float margin)
    self->setBottomMargin((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_LayoutComponent_setHorizontalEdge(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;
    lua_Unsigned arg1 = 0;       /** hEage */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.LayoutComponent");
    olua_check_uint(L, 2, &arg1);

    // void setHorizontalEdge(cocos2d::ui::LayoutComponent::HorizontalEdge hEage)
    self->setHorizontalEdge((cocos2d::ui::LayoutComponent::HorizontalEdge)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_LayoutComponent_setLeftMargin(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;
    lua_Number arg1 = 0;       /** margin */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.LayoutComponent");
    olua_check_number(L, 2, &arg1);

    // void setLeftMargin(float margin)
    self->setLeftMargin((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_LayoutComponent_setPercentContentSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;
    cocos2d::Vec2 arg1;       /** percent */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.LayoutComponent");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);

    // void setPercentContentSize(const cocos2d::Vec2 &percent)
    self->setPercentContentSize(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_LayoutComponent_setPercentHeight(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;
    lua_Number arg1 = 0;       /** percentHeight */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.LayoutComponent");
    olua_check_number(L, 2, &arg1);

    // void setPercentHeight(float percentHeight)
    self->setPercentHeight((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_LayoutComponent_setPercentHeightEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;
    bool arg1 = false;       /** isUsed */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.LayoutComponent");
    olua_check_bool(L, 2, &arg1);

    // void setPercentHeightEnabled(bool isUsed)
    self->setPercentHeightEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_LayoutComponent_setPercentOnlyEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;
    bool arg1 = false;       /** enable */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.LayoutComponent");
    olua_check_bool(L, 2, &arg1);

    // void setPercentOnlyEnabled(bool enable)
    self->setPercentOnlyEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_LayoutComponent_setPercentWidth(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;
    lua_Number arg1 = 0;       /** percentWidth */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.LayoutComponent");
    olua_check_number(L, 2, &arg1);

    // void setPercentWidth(float percentWidth)
    self->setPercentWidth((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_LayoutComponent_setPercentWidthEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;
    bool arg1 = false;       /** isUsed */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.LayoutComponent");
    olua_check_bool(L, 2, &arg1);

    // void setPercentWidthEnabled(bool isUsed)
    self->setPercentWidthEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_LayoutComponent_setPosition(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;
    cocos2d::Point arg1;       /** position */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.LayoutComponent");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);

    // void setPosition(const cocos2d::Point &position)
    self->setPosition(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_LayoutComponent_setPositionPercentX(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;
    lua_Number arg1 = 0;       /** percentMargin */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.LayoutComponent");
    olua_check_number(L, 2, &arg1);

    // void setPositionPercentX(float percentMargin)
    self->setPositionPercentX((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_LayoutComponent_setPositionPercentXEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;
    bool arg1 = false;       /** isUsed */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.LayoutComponent");
    olua_check_bool(L, 2, &arg1);

    // void setPositionPercentXEnabled(bool isUsed)
    self->setPositionPercentXEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_LayoutComponent_setPositionPercentY(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;
    lua_Number arg1 = 0;       /** percentMargin */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.LayoutComponent");
    olua_check_number(L, 2, &arg1);

    // void setPositionPercentY(float percentMargin)
    self->setPositionPercentY((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_LayoutComponent_setPositionPercentYEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;
    bool arg1 = false;       /** isUsed */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.LayoutComponent");
    olua_check_bool(L, 2, &arg1);

    // void setPositionPercentYEnabled(bool isUsed)
    self->setPositionPercentYEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_LayoutComponent_setRightMargin(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;
    lua_Number arg1 = 0;       /** margin */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.LayoutComponent");
    olua_check_number(L, 2, &arg1);

    // void setRightMargin(float margin)
    self->setRightMargin((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_LayoutComponent_setSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;
    cocos2d::Size arg1;       /** size */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.LayoutComponent");
    auto_olua_check_cocos2d_Size(L, 2, &arg1);

    // void setSize(const cocos2d::Size &size)
    self->setSize(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_LayoutComponent_setSizeHeight(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;
    lua_Number arg1 = 0;       /** height */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.LayoutComponent");
    olua_check_number(L, 2, &arg1);

    // void setSizeHeight(float height)
    self->setSizeHeight((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_LayoutComponent_setSizeWidth(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;
    lua_Number arg1 = 0;       /** width */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.LayoutComponent");
    olua_check_number(L, 2, &arg1);

    // void setSizeWidth(float width)
    self->setSizeWidth((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_LayoutComponent_setStretchHeightEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;
    bool arg1 = false;       /** isUsed */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.LayoutComponent");
    olua_check_bool(L, 2, &arg1);

    // void setStretchHeightEnabled(bool isUsed)
    self->setStretchHeightEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_LayoutComponent_setStretchWidthEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;
    bool arg1 = false;       /** isUsed */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.LayoutComponent");
    olua_check_bool(L, 2, &arg1);

    // void setStretchWidthEnabled(bool isUsed)
    self->setStretchWidthEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_LayoutComponent_setTopMargin(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;
    lua_Number arg1 = 0;       /** margin */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.LayoutComponent");
    olua_check_number(L, 2, &arg1);

    // void setTopMargin(float margin)
    self->setTopMargin((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_LayoutComponent_setUsingPercentContentSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;
    bool arg1 = false;       /** isUsed */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.LayoutComponent");
    olua_check_bool(L, 2, &arg1);

    // void setUsingPercentContentSize(bool isUsed)
    self->setUsingPercentContentSize(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_LayoutComponent_setVerticalEdge(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutComponent *self = nullptr;
    lua_Unsigned arg1 = 0;       /** vEage */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.LayoutComponent");
    olua_check_uint(L, 2, &arg1);

    // void setVerticalEdge(cocos2d::ui::LayoutComponent::VerticalEdge vEage)
    self->setVerticalEdge((cocos2d::ui::LayoutComponent::VerticalEdge)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_ui_LayoutComponent(lua_State *L)
{
    oluacls_class(L, "ccui.LayoutComponent", "cc.Component");
    oluacls_func(L, "__move", _cocos2d_ui_LayoutComponent___move);
    oluacls_func(L, "bindLayoutComponent", _cocos2d_ui_LayoutComponent_bindLayoutComponent);
    oluacls_func(L, "create", _cocos2d_ui_LayoutComponent_create);
    oluacls_func(L, "getAnchorPosition", _cocos2d_ui_LayoutComponent_getAnchorPosition);
    oluacls_func(L, "getBottomMargin", _cocos2d_ui_LayoutComponent_getBottomMargin);
    oluacls_func(L, "getHorizontalEdge", _cocos2d_ui_LayoutComponent_getHorizontalEdge);
    oluacls_func(L, "getLeftMargin", _cocos2d_ui_LayoutComponent_getLeftMargin);
    oluacls_func(L, "getPercentContentSize", _cocos2d_ui_LayoutComponent_getPercentContentSize);
    oluacls_func(L, "getPercentHeight", _cocos2d_ui_LayoutComponent_getPercentHeight);
    oluacls_func(L, "getPercentWidth", _cocos2d_ui_LayoutComponent_getPercentWidth);
    oluacls_func(L, "getPosition", _cocos2d_ui_LayoutComponent_getPosition);
    oluacls_func(L, "getPositionPercentX", _cocos2d_ui_LayoutComponent_getPositionPercentX);
    oluacls_func(L, "getPositionPercentY", _cocos2d_ui_LayoutComponent_getPositionPercentY);
    oluacls_func(L, "getRightMargin", _cocos2d_ui_LayoutComponent_getRightMargin);
    oluacls_func(L, "getSize", _cocos2d_ui_LayoutComponent_getSize);
    oluacls_func(L, "getSizeHeight", _cocos2d_ui_LayoutComponent_getSizeHeight);
    oluacls_func(L, "getSizeWidth", _cocos2d_ui_LayoutComponent_getSizeWidth);
    oluacls_func(L, "getTopMargin", _cocos2d_ui_LayoutComponent_getTopMargin);
    oluacls_func(L, "getUsingPercentContentSize", _cocos2d_ui_LayoutComponent_getUsingPercentContentSize);
    oluacls_func(L, "getVerticalEdge", _cocos2d_ui_LayoutComponent_getVerticalEdge);
    oluacls_func(L, "isPercentHeightEnabled", _cocos2d_ui_LayoutComponent_isPercentHeightEnabled);
    oluacls_func(L, "isPercentWidthEnabled", _cocos2d_ui_LayoutComponent_isPercentWidthEnabled);
    oluacls_func(L, "isPositionPercentXEnabled", _cocos2d_ui_LayoutComponent_isPositionPercentXEnabled);
    oluacls_func(L, "isPositionPercentYEnabled", _cocos2d_ui_LayoutComponent_isPositionPercentYEnabled);
    oluacls_func(L, "isStretchHeightEnabled", _cocos2d_ui_LayoutComponent_isStretchHeightEnabled);
    oluacls_func(L, "isStretchWidthEnabled", _cocos2d_ui_LayoutComponent_isStretchWidthEnabled);
    oluacls_func(L, "new", _cocos2d_ui_LayoutComponent_new);
    oluacls_func(L, "refreshLayout", _cocos2d_ui_LayoutComponent_refreshLayout);
    oluacls_func(L, "setActiveEnabled", _cocos2d_ui_LayoutComponent_setActiveEnabled);
    oluacls_func(L, "setAnchorPosition", _cocos2d_ui_LayoutComponent_setAnchorPosition);
    oluacls_func(L, "setBottomMargin", _cocos2d_ui_LayoutComponent_setBottomMargin);
    oluacls_func(L, "setHorizontalEdge", _cocos2d_ui_LayoutComponent_setHorizontalEdge);
    oluacls_func(L, "setLeftMargin", _cocos2d_ui_LayoutComponent_setLeftMargin);
    oluacls_func(L, "setPercentContentSize", _cocos2d_ui_LayoutComponent_setPercentContentSize);
    oluacls_func(L, "setPercentHeight", _cocos2d_ui_LayoutComponent_setPercentHeight);
    oluacls_func(L, "setPercentHeightEnabled", _cocos2d_ui_LayoutComponent_setPercentHeightEnabled);
    oluacls_func(L, "setPercentOnlyEnabled", _cocos2d_ui_LayoutComponent_setPercentOnlyEnabled);
    oluacls_func(L, "setPercentWidth", _cocos2d_ui_LayoutComponent_setPercentWidth);
    oluacls_func(L, "setPercentWidthEnabled", _cocos2d_ui_LayoutComponent_setPercentWidthEnabled);
    oluacls_func(L, "setPosition", _cocos2d_ui_LayoutComponent_setPosition);
    oluacls_func(L, "setPositionPercentX", _cocos2d_ui_LayoutComponent_setPositionPercentX);
    oluacls_func(L, "setPositionPercentXEnabled", _cocos2d_ui_LayoutComponent_setPositionPercentXEnabled);
    oluacls_func(L, "setPositionPercentY", _cocos2d_ui_LayoutComponent_setPositionPercentY);
    oluacls_func(L, "setPositionPercentYEnabled", _cocos2d_ui_LayoutComponent_setPositionPercentYEnabled);
    oluacls_func(L, "setRightMargin", _cocos2d_ui_LayoutComponent_setRightMargin);
    oluacls_func(L, "setSize", _cocos2d_ui_LayoutComponent_setSize);
    oluacls_func(L, "setSizeHeight", _cocos2d_ui_LayoutComponent_setSizeHeight);
    oluacls_func(L, "setSizeWidth", _cocos2d_ui_LayoutComponent_setSizeWidth);
    oluacls_func(L, "setStretchHeightEnabled", _cocos2d_ui_LayoutComponent_setStretchHeightEnabled);
    oluacls_func(L, "setStretchWidthEnabled", _cocos2d_ui_LayoutComponent_setStretchWidthEnabled);
    oluacls_func(L, "setTopMargin", _cocos2d_ui_LayoutComponent_setTopMargin);
    oluacls_func(L, "setUsingPercentContentSize", _cocos2d_ui_LayoutComponent_setUsingPercentContentSize);
    oluacls_func(L, "setVerticalEdge", _cocos2d_ui_LayoutComponent_setVerticalEdge);
    oluacls_prop(L, "anchorPosition", _cocos2d_ui_LayoutComponent_getAnchorPosition, _cocos2d_ui_LayoutComponent_setAnchorPosition);
    oluacls_prop(L, "bottomMargin", _cocos2d_ui_LayoutComponent_getBottomMargin, _cocos2d_ui_LayoutComponent_setBottomMargin);
    oluacls_prop(L, "horizontalEdge", _cocos2d_ui_LayoutComponent_getHorizontalEdge, _cocos2d_ui_LayoutComponent_setHorizontalEdge);
    oluacls_prop(L, "leftMargin", _cocos2d_ui_LayoutComponent_getLeftMargin, _cocos2d_ui_LayoutComponent_setLeftMargin);
    oluacls_prop(L, "percentContentSize", _cocos2d_ui_LayoutComponent_getPercentContentSize, _cocos2d_ui_LayoutComponent_setPercentContentSize);
    oluacls_prop(L, "percentHeight", _cocos2d_ui_LayoutComponent_getPercentHeight, _cocos2d_ui_LayoutComponent_setPercentHeight);
    oluacls_prop(L, "percentHeightEnabled", _cocos2d_ui_LayoutComponent_isPercentHeightEnabled, _cocos2d_ui_LayoutComponent_setPercentHeightEnabled);
    oluacls_prop(L, "percentWidth", _cocos2d_ui_LayoutComponent_getPercentWidth, _cocos2d_ui_LayoutComponent_setPercentWidth);
    oluacls_prop(L, "percentWidthEnabled", _cocos2d_ui_LayoutComponent_isPercentWidthEnabled, _cocos2d_ui_LayoutComponent_setPercentWidthEnabled);
    oluacls_prop(L, "position", _cocos2d_ui_LayoutComponent_getPosition, _cocos2d_ui_LayoutComponent_setPosition);
    oluacls_prop(L, "positionPercentX", _cocos2d_ui_LayoutComponent_getPositionPercentX, _cocos2d_ui_LayoutComponent_setPositionPercentX);
    oluacls_prop(L, "positionPercentXEnabled", _cocos2d_ui_LayoutComponent_isPositionPercentXEnabled, _cocos2d_ui_LayoutComponent_setPositionPercentXEnabled);
    oluacls_prop(L, "positionPercentY", _cocos2d_ui_LayoutComponent_getPositionPercentY, _cocos2d_ui_LayoutComponent_setPositionPercentY);
    oluacls_prop(L, "positionPercentYEnabled", _cocos2d_ui_LayoutComponent_isPositionPercentYEnabled, _cocos2d_ui_LayoutComponent_setPositionPercentYEnabled);
    oluacls_prop(L, "rightMargin", _cocos2d_ui_LayoutComponent_getRightMargin, _cocos2d_ui_LayoutComponent_setRightMargin);
    oluacls_prop(L, "size", _cocos2d_ui_LayoutComponent_getSize, _cocos2d_ui_LayoutComponent_setSize);
    oluacls_prop(L, "sizeHeight", _cocos2d_ui_LayoutComponent_getSizeHeight, _cocos2d_ui_LayoutComponent_setSizeHeight);
    oluacls_prop(L, "sizeWidth", _cocos2d_ui_LayoutComponent_getSizeWidth, _cocos2d_ui_LayoutComponent_setSizeWidth);
    oluacls_prop(L, "stretchHeightEnabled", _cocos2d_ui_LayoutComponent_isStretchHeightEnabled, _cocos2d_ui_LayoutComponent_setStretchHeightEnabled);
    oluacls_prop(L, "stretchWidthEnabled", _cocos2d_ui_LayoutComponent_isStretchWidthEnabled, _cocos2d_ui_LayoutComponent_setStretchWidthEnabled);
    oluacls_prop(L, "topMargin", _cocos2d_ui_LayoutComponent_getTopMargin, _cocos2d_ui_LayoutComponent_setTopMargin);
    oluacls_prop(L, "usingPercentContentSize", _cocos2d_ui_LayoutComponent_getUsingPercentContentSize, _cocos2d_ui_LayoutComponent_setUsingPercentContentSize);
    oluacls_prop(L, "verticalEdge", _cocos2d_ui_LayoutComponent_getVerticalEdge, _cocos2d_ui_LayoutComponent_setVerticalEdge);

    olua_registerluatype<cocos2d::ui::LayoutComponent>(L, "ccui.LayoutComponent");

    return 1;
}

static int luaopen_cocos2d_ui_LayoutParameter_Type(lua_State *L)
{
    oluacls_class(L, "ccui.LayoutParameter.Type", nullptr);
    oluacls_const_integer(L, "LINEAR", (lua_Integer)cocos2d::ui::LayoutParameter::Type::LINEAR);
    oluacls_const_integer(L, "NONE", (lua_Integer)cocos2d::ui::LayoutParameter::Type::NONE);
    oluacls_const_integer(L, "RELATIVE", (lua_Integer)cocos2d::ui::LayoutParameter::Type::RELATIVE);

    olua_registerluatype<cocos2d::ui::LayoutParameter::Type>(L, "ccui.LayoutParameter.Type");

    return 1;
}

static int _cocos2d_ui_LayoutParameter___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::ui::LayoutParameter *)olua_toobj(L, 1, "ccui.LayoutParameter");
    olua_push_cppobj(L, self, "ccui.LayoutParameter");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_ui_LayoutParameter_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutParameter *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.LayoutParameter");

    // cocos2d::ui::LayoutParameter *clone()
    cocos2d::ui::LayoutParameter *ret = (cocos2d::ui::LayoutParameter *)self->clone();
    int num_ret = olua_push_cppobj(L, ret, "ccui.LayoutParameter");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_LayoutParameter_copyProperties(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutParameter *self = nullptr;
    cocos2d::ui::LayoutParameter *arg1 = nullptr;       /** model */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.LayoutParameter");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccui.LayoutParameter");

    // void copyProperties(cocos2d::ui::LayoutParameter *model)
    self->copyProperties(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_LayoutParameter_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::ui::LayoutParameter *create()
    cocos2d::ui::LayoutParameter *ret = (cocos2d::ui::LayoutParameter *)cocos2d::ui::LayoutParameter::create();
    int num_ret = olua_push_cppobj(L, ret, "ccui.LayoutParameter");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_LayoutParameter_createCloneInstance(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutParameter *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.LayoutParameter");

    // cocos2d::ui::LayoutParameter *createCloneInstance()
    cocos2d::ui::LayoutParameter *ret = (cocos2d::ui::LayoutParameter *)self->createCloneInstance();
    int num_ret = olua_push_cppobj(L, ret, "ccui.LayoutParameter");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_LayoutParameter_getLayoutType(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutParameter *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.LayoutParameter");

    // cocos2d::ui::LayoutParameter::Type getLayoutType()
    cocos2d::ui::LayoutParameter::Type ret = (cocos2d::ui::LayoutParameter::Type)self->getLayoutType();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_LayoutParameter_getMargin(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutParameter *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.LayoutParameter");

    // const cocos2d::ui::Margin &getMargin()
    const cocos2d::ui::Margin &ret = (const cocos2d::ui::Margin &)self->getMargin();
    int num_ret = auto_olua_push_cocos2d_ui_Margin(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_LayoutParameter_new(lua_State *L)
{
    olua_startinvoke(L);

    // LayoutParameter()
    cocos2d::ui::LayoutParameter *ret = (cocos2d::ui::LayoutParameter *)new cocos2d::ui::LayoutParameter();
    int num_ret = olua_push_cppobj(L, ret, "ccui.LayoutParameter");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_LayoutParameter_setMargin(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LayoutParameter *self = nullptr;
    cocos2d::ui::Margin arg1;       /** margin */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.LayoutParameter");
    auto_olua_check_cocos2d_ui_Margin(L, 2, &arg1);

    // void setMargin(const cocos2d::ui::Margin &margin)
    self->setMargin(arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_ui_LayoutParameter(lua_State *L)
{
    oluacls_class(L, "ccui.LayoutParameter", "cc.Ref");
    oluacls_func(L, "__move", _cocos2d_ui_LayoutParameter___move);
    oluacls_func(L, "clone", _cocos2d_ui_LayoutParameter_clone);
    oluacls_func(L, "copyProperties", _cocos2d_ui_LayoutParameter_copyProperties);
    oluacls_func(L, "create", _cocos2d_ui_LayoutParameter_create);
    oluacls_func(L, "createCloneInstance", _cocos2d_ui_LayoutParameter_createCloneInstance);
    oluacls_func(L, "getLayoutType", _cocos2d_ui_LayoutParameter_getLayoutType);
    oluacls_func(L, "getMargin", _cocos2d_ui_LayoutParameter_getMargin);
    oluacls_func(L, "new", _cocos2d_ui_LayoutParameter_new);
    oluacls_func(L, "setMargin", _cocos2d_ui_LayoutParameter_setMargin);
    oluacls_prop(L, "layoutType", _cocos2d_ui_LayoutParameter_getLayoutType, nullptr);
    oluacls_prop(L, "margin", _cocos2d_ui_LayoutParameter_getMargin, _cocos2d_ui_LayoutParameter_setMargin);

    olua_registerluatype<cocos2d::ui::LayoutParameter>(L, "ccui.LayoutParameter");

    return 1;
}

static int luaopen_cocos2d_ui_LinearLayoutParameter_LinearGravity(lua_State *L)
{
    oluacls_class(L, "ccui.LinearLayoutParameter.LinearGravity", nullptr);
    oluacls_const_integer(L, "BOTTOM", (lua_Integer)cocos2d::ui::LinearLayoutParameter::LinearGravity::BOTTOM);
    oluacls_const_integer(L, "CENTER_HORIZONTAL", (lua_Integer)cocos2d::ui::LinearLayoutParameter::LinearGravity::CENTER_HORIZONTAL);
    oluacls_const_integer(L, "CENTER_VERTICAL", (lua_Integer)cocos2d::ui::LinearLayoutParameter::LinearGravity::CENTER_VERTICAL);
    oluacls_const_integer(L, "LEFT", (lua_Integer)cocos2d::ui::LinearLayoutParameter::LinearGravity::LEFT);
    oluacls_const_integer(L, "NONE", (lua_Integer)cocos2d::ui::LinearLayoutParameter::LinearGravity::NONE);
    oluacls_const_integer(L, "RIGHT", (lua_Integer)cocos2d::ui::LinearLayoutParameter::LinearGravity::RIGHT);
    oluacls_const_integer(L, "TOP", (lua_Integer)cocos2d::ui::LinearLayoutParameter::LinearGravity::TOP);

    olua_registerluatype<cocos2d::ui::LinearLayoutParameter::LinearGravity>(L, "ccui.LinearLayoutParameter.LinearGravity");

    return 1;
}

static int _cocos2d_ui_LinearLayoutParameter___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::ui::LinearLayoutParameter *)olua_toobj(L, 1, "ccui.LinearLayoutParameter");
    olua_push_cppobj(L, self, "ccui.LinearLayoutParameter");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_ui_LinearLayoutParameter_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::ui::LinearLayoutParameter *create()
    cocos2d::ui::LinearLayoutParameter *ret = (cocos2d::ui::LinearLayoutParameter *)cocos2d::ui::LinearLayoutParameter::create();
    int num_ret = olua_push_cppobj(L, ret, "ccui.LinearLayoutParameter");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_LinearLayoutParameter_getGravity(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LinearLayoutParameter *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.LinearLayoutParameter");

    // cocos2d::ui::LinearLayoutParameter::LinearGravity getGravity()
    cocos2d::ui::LinearLayoutParameter::LinearGravity ret = (cocos2d::ui::LinearLayoutParameter::LinearGravity)self->getGravity();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_LinearLayoutParameter_new(lua_State *L)
{
    olua_startinvoke(L);

    // LinearLayoutParameter()
    cocos2d::ui::LinearLayoutParameter *ret = (cocos2d::ui::LinearLayoutParameter *)new cocos2d::ui::LinearLayoutParameter();
    int num_ret = olua_push_cppobj(L, ret, "ccui.LinearLayoutParameter");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_LinearLayoutParameter_setGravity(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LinearLayoutParameter *self = nullptr;
    lua_Unsigned arg1 = 0;       /** gravity */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.LinearLayoutParameter");
    olua_check_uint(L, 2, &arg1);

    // void setGravity(cocos2d::ui::LinearLayoutParameter::LinearGravity gravity)
    self->setGravity((cocos2d::ui::LinearLayoutParameter::LinearGravity)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_ui_LinearLayoutParameter(lua_State *L)
{
    oluacls_class(L, "ccui.LinearLayoutParameter", "ccui.LayoutParameter");
    oluacls_func(L, "__move", _cocos2d_ui_LinearLayoutParameter___move);
    oluacls_func(L, "create", _cocos2d_ui_LinearLayoutParameter_create);
    oluacls_func(L, "getGravity", _cocos2d_ui_LinearLayoutParameter_getGravity);
    oluacls_func(L, "new", _cocos2d_ui_LinearLayoutParameter_new);
    oluacls_func(L, "setGravity", _cocos2d_ui_LinearLayoutParameter_setGravity);
    oluacls_prop(L, "gravity", _cocos2d_ui_LinearLayoutParameter_getGravity, _cocos2d_ui_LinearLayoutParameter_setGravity);

    olua_registerluatype<cocos2d::ui::LinearLayoutParameter>(L, "ccui.LinearLayoutParameter");

    return 1;
}

static int luaopen_cocos2d_ui_RelativeLayoutParameter_RelativeAlign(lua_State *L)
{
    oluacls_class(L, "ccui.RelativeLayoutParameter.RelativeAlign", nullptr);
    oluacls_const_integer(L, "CENTER_IN_PARENT", (lua_Integer)cocos2d::ui::RelativeLayoutParameter::RelativeAlign::CENTER_IN_PARENT);
    oluacls_const_integer(L, "LOCATION_ABOVE_CENTER", (lua_Integer)cocos2d::ui::RelativeLayoutParameter::RelativeAlign::LOCATION_ABOVE_CENTER);
    oluacls_const_integer(L, "LOCATION_ABOVE_LEFTALIGN", (lua_Integer)cocos2d::ui::RelativeLayoutParameter::RelativeAlign::LOCATION_ABOVE_LEFTALIGN);
    oluacls_const_integer(L, "LOCATION_ABOVE_RIGHTALIGN", (lua_Integer)cocos2d::ui::RelativeLayoutParameter::RelativeAlign::LOCATION_ABOVE_RIGHTALIGN);
    oluacls_const_integer(L, "LOCATION_BELOW_CENTER", (lua_Integer)cocos2d::ui::RelativeLayoutParameter::RelativeAlign::LOCATION_BELOW_CENTER);
    oluacls_const_integer(L, "LOCATION_BELOW_LEFTALIGN", (lua_Integer)cocos2d::ui::RelativeLayoutParameter::RelativeAlign::LOCATION_BELOW_LEFTALIGN);
    oluacls_const_integer(L, "LOCATION_BELOW_RIGHTALIGN", (lua_Integer)cocos2d::ui::RelativeLayoutParameter::RelativeAlign::LOCATION_BELOW_RIGHTALIGN);
    oluacls_const_integer(L, "LOCATION_LEFT_OF_BOTTOMALIGN", (lua_Integer)cocos2d::ui::RelativeLayoutParameter::RelativeAlign::LOCATION_LEFT_OF_BOTTOMALIGN);
    oluacls_const_integer(L, "LOCATION_LEFT_OF_CENTER", (lua_Integer)cocos2d::ui::RelativeLayoutParameter::RelativeAlign::LOCATION_LEFT_OF_CENTER);
    oluacls_const_integer(L, "LOCATION_LEFT_OF_TOPALIGN", (lua_Integer)cocos2d::ui::RelativeLayoutParameter::RelativeAlign::LOCATION_LEFT_OF_TOPALIGN);
    oluacls_const_integer(L, "LOCATION_RIGHT_OF_BOTTOMALIGN", (lua_Integer)cocos2d::ui::RelativeLayoutParameter::RelativeAlign::LOCATION_RIGHT_OF_BOTTOMALIGN);
    oluacls_const_integer(L, "LOCATION_RIGHT_OF_CENTER", (lua_Integer)cocos2d::ui::RelativeLayoutParameter::RelativeAlign::LOCATION_RIGHT_OF_CENTER);
    oluacls_const_integer(L, "LOCATION_RIGHT_OF_TOPALIGN", (lua_Integer)cocos2d::ui::RelativeLayoutParameter::RelativeAlign::LOCATION_RIGHT_OF_TOPALIGN);
    oluacls_const_integer(L, "NONE", (lua_Integer)cocos2d::ui::RelativeLayoutParameter::RelativeAlign::NONE);
    oluacls_const_integer(L, "PARENT_BOTTOM_CENTER_HORIZONTAL", (lua_Integer)cocos2d::ui::RelativeLayoutParameter::RelativeAlign::PARENT_BOTTOM_CENTER_HORIZONTAL);
    oluacls_const_integer(L, "PARENT_LEFT_BOTTOM", (lua_Integer)cocos2d::ui::RelativeLayoutParameter::RelativeAlign::PARENT_LEFT_BOTTOM);
    oluacls_const_integer(L, "PARENT_LEFT_CENTER_VERTICAL", (lua_Integer)cocos2d::ui::RelativeLayoutParameter::RelativeAlign::PARENT_LEFT_CENTER_VERTICAL);
    oluacls_const_integer(L, "PARENT_RIGHT_BOTTOM", (lua_Integer)cocos2d::ui::RelativeLayoutParameter::RelativeAlign::PARENT_RIGHT_BOTTOM);
    oluacls_const_integer(L, "PARENT_RIGHT_CENTER_VERTICAL", (lua_Integer)cocos2d::ui::RelativeLayoutParameter::RelativeAlign::PARENT_RIGHT_CENTER_VERTICAL);
    oluacls_const_integer(L, "PARENT_TOP_CENTER_HORIZONTAL", (lua_Integer)cocos2d::ui::RelativeLayoutParameter::RelativeAlign::PARENT_TOP_CENTER_HORIZONTAL);
    oluacls_const_integer(L, "PARENT_TOP_LEFT", (lua_Integer)cocos2d::ui::RelativeLayoutParameter::RelativeAlign::PARENT_TOP_LEFT);
    oluacls_const_integer(L, "PARENT_TOP_RIGHT", (lua_Integer)cocos2d::ui::RelativeLayoutParameter::RelativeAlign::PARENT_TOP_RIGHT);

    olua_registerluatype<cocos2d::ui::RelativeLayoutParameter::RelativeAlign>(L, "ccui.RelativeLayoutParameter.RelativeAlign");

    return 1;
}

static int _cocos2d_ui_RelativeLayoutParameter___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::ui::RelativeLayoutParameter *)olua_toobj(L, 1, "ccui.RelativeLayoutParameter");
    olua_push_cppobj(L, self, "ccui.RelativeLayoutParameter");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_ui_RelativeLayoutParameter_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::ui::RelativeLayoutParameter *create()
    cocos2d::ui::RelativeLayoutParameter *ret = (cocos2d::ui::RelativeLayoutParameter *)cocos2d::ui::RelativeLayoutParameter::create();
    int num_ret = olua_push_cppobj(L, ret, "ccui.RelativeLayoutParameter");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_RelativeLayoutParameter_getAlign(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RelativeLayoutParameter *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RelativeLayoutParameter");

    // cocos2d::ui::RelativeLayoutParameter::RelativeAlign getAlign()
    cocos2d::ui::RelativeLayoutParameter::RelativeAlign ret = (cocos2d::ui::RelativeLayoutParameter::RelativeAlign)self->getAlign();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_RelativeLayoutParameter_getRelativeName(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RelativeLayoutParameter *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RelativeLayoutParameter");

    // const std::string &getRelativeName()
    const std::string &ret = (const std::string &)self->getRelativeName();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_RelativeLayoutParameter_getRelativeToWidgetName(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RelativeLayoutParameter *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RelativeLayoutParameter");

    // const std::string &getRelativeToWidgetName()
    const std::string &ret = (const std::string &)self->getRelativeToWidgetName();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_RelativeLayoutParameter_new(lua_State *L)
{
    olua_startinvoke(L);

    // RelativeLayoutParameter()
    cocos2d::ui::RelativeLayoutParameter *ret = (cocos2d::ui::RelativeLayoutParameter *)new cocos2d::ui::RelativeLayoutParameter();
    int num_ret = olua_push_cppobj(L, ret, "ccui.RelativeLayoutParameter");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_RelativeLayoutParameter_setAlign(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RelativeLayoutParameter *self = nullptr;
    lua_Unsigned arg1 = 0;       /** align */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RelativeLayoutParameter");
    olua_check_uint(L, 2, &arg1);

    // void setAlign(cocos2d::ui::RelativeLayoutParameter::RelativeAlign align)
    self->setAlign((cocos2d::ui::RelativeLayoutParameter::RelativeAlign)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_RelativeLayoutParameter_setRelativeName(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RelativeLayoutParameter *self = nullptr;
    std::string arg1;       /** name */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RelativeLayoutParameter");
    olua_check_std_string(L, 2, &arg1);

    // void setRelativeName(const std::string &name)
    self->setRelativeName(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_RelativeLayoutParameter_setRelativeToWidgetName(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RelativeLayoutParameter *self = nullptr;
    std::string arg1;       /** name */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RelativeLayoutParameter");
    olua_check_std_string(L, 2, &arg1);

    // void setRelativeToWidgetName(const std::string &name)
    self->setRelativeToWidgetName(arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_ui_RelativeLayoutParameter(lua_State *L)
{
    oluacls_class(L, "ccui.RelativeLayoutParameter", "ccui.LayoutParameter");
    oluacls_func(L, "__move", _cocos2d_ui_RelativeLayoutParameter___move);
    oluacls_func(L, "create", _cocos2d_ui_RelativeLayoutParameter_create);
    oluacls_func(L, "getAlign", _cocos2d_ui_RelativeLayoutParameter_getAlign);
    oluacls_func(L, "getRelativeName", _cocos2d_ui_RelativeLayoutParameter_getRelativeName);
    oluacls_func(L, "getRelativeToWidgetName", _cocos2d_ui_RelativeLayoutParameter_getRelativeToWidgetName);
    oluacls_func(L, "new", _cocos2d_ui_RelativeLayoutParameter_new);
    oluacls_func(L, "setAlign", _cocos2d_ui_RelativeLayoutParameter_setAlign);
    oluacls_func(L, "setRelativeName", _cocos2d_ui_RelativeLayoutParameter_setRelativeName);
    oluacls_func(L, "setRelativeToWidgetName", _cocos2d_ui_RelativeLayoutParameter_setRelativeToWidgetName);
    oluacls_prop(L, "align", _cocos2d_ui_RelativeLayoutParameter_getAlign, _cocos2d_ui_RelativeLayoutParameter_setAlign);
    oluacls_prop(L, "relativeName", _cocos2d_ui_RelativeLayoutParameter_getRelativeName, _cocos2d_ui_RelativeLayoutParameter_setRelativeName);
    oluacls_prop(L, "relativeToWidgetName", _cocos2d_ui_RelativeLayoutParameter_getRelativeToWidgetName, _cocos2d_ui_RelativeLayoutParameter_setRelativeToWidgetName);

    olua_registerluatype<cocos2d::ui::RelativeLayoutParameter>(L, "ccui.RelativeLayoutParameter");

    return 1;
}

static int luaopen_cocos2d_ui_Layout_Type(lua_State *L)
{
    oluacls_class(L, "ccui.Layout.Type", nullptr);
    oluacls_const_integer(L, "ABSOLUTE", (lua_Integer)cocos2d::ui::Layout::Type::ABSOLUTE);
    oluacls_const_integer(L, "HORIZONTAL", (lua_Integer)cocos2d::ui::Layout::Type::HORIZONTAL);
    oluacls_const_integer(L, "RELATIVE", (lua_Integer)cocos2d::ui::Layout::Type::RELATIVE);
    oluacls_const_integer(L, "VERTICAL", (lua_Integer)cocos2d::ui::Layout::Type::VERTICAL);

    olua_registerluatype<cocos2d::ui::Layout::Type>(L, "ccui.Layout.Type");

    return 1;
}

static int luaopen_cocos2d_ui_Layout_ClippingType(lua_State *L)
{
    oluacls_class(L, "ccui.Layout.ClippingType", nullptr);
    oluacls_const_integer(L, "SCISSOR", (lua_Integer)cocos2d::ui::Layout::ClippingType::SCISSOR);
    oluacls_const_integer(L, "STENCIL", (lua_Integer)cocos2d::ui::Layout::ClippingType::STENCIL);

    olua_registerluatype<cocos2d::ui::Layout::ClippingType>(L, "ccui.Layout.ClippingType");

    return 1;
}

static int luaopen_cocos2d_ui_Layout_BackGroundColorType(lua_State *L)
{
    oluacls_class(L, "ccui.Layout.BackGroundColorType", nullptr);
    oluacls_const_integer(L, "GRADIENT", (lua_Integer)cocos2d::ui::Layout::BackGroundColorType::GRADIENT);
    oluacls_const_integer(L, "NONE", (lua_Integer)cocos2d::ui::Layout::BackGroundColorType::NONE);
    oluacls_const_integer(L, "SOLID", (lua_Integer)cocos2d::ui::Layout::BackGroundColorType::SOLID);

    olua_registerluatype<cocos2d::ui::Layout::BackGroundColorType>(L, "ccui.Layout.BackGroundColorType");

    return 1;
}

static int _cocos2d_ui_Layout___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::ui::Layout *)olua_toobj(L, 1, "ccui.Layout");
    olua_push_cppobj(L, self, "ccui.Layout");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_ui_Layout_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::ui::Layout *create()
    cocos2d::ui::Layout *ret = (cocos2d::ui::Layout *)cocos2d::ui::Layout::create();
    int num_ret = olua_push_cppobj(L, ret, "ccui.Layout");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Layout_createInstance(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::Ref *createInstance()
    cocos2d::Ref *ret = (cocos2d::Ref *)cocos2d::ui::Layout::createInstance();
    int num_ret = olua_push_cppobj(L, ret, "cc.Ref");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Layout_forceDoLayout(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Layout *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Layout");

    // void forceDoLayout()
    self->forceDoLayout();

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Layout_getBackGroundColor(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Layout *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Layout");

    // const cocos2d::Color3B &getBackGroundColor()
    const cocos2d::Color3B &ret = (const cocos2d::Color3B &)self->getBackGroundColor();
    int num_ret = manual_olua_push_cocos2d_Color3B(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Layout_getBackGroundColorOpacity(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Layout *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Layout");

    // uint8_t getBackGroundColorOpacity()
    uint8_t ret = (uint8_t)self->getBackGroundColorOpacity();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Layout_getBackGroundColorType(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Layout *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Layout");

    // cocos2d::ui::Layout::BackGroundColorType getBackGroundColorType()
    cocos2d::ui::Layout::BackGroundColorType ret = (cocos2d::ui::Layout::BackGroundColorType)self->getBackGroundColorType();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Layout_getBackGroundColorVector(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Layout *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Layout");

    // const cocos2d::Vec2 &getBackGroundColorVector()
    const cocos2d::Vec2 &ret = (const cocos2d::Vec2 &)self->getBackGroundColorVector();
    int num_ret = auto_olua_push_cocos2d_Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Layout_getBackGroundEndColor(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Layout *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Layout");

    // const cocos2d::Color3B &getBackGroundEndColor()
    const cocos2d::Color3B &ret = (const cocos2d::Color3B &)self->getBackGroundEndColor();
    int num_ret = manual_olua_push_cocos2d_Color3B(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Layout_getBackGroundImageCapInsets(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Layout *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Layout");

    // const cocos2d::Rect &getBackGroundImageCapInsets()
    const cocos2d::Rect &ret = (const cocos2d::Rect &)self->getBackGroundImageCapInsets();
    int num_ret = manual_olua_push_cocos2d_Rect(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Layout_getBackGroundImageColor(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Layout *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Layout");

    // const cocos2d::Color3B &getBackGroundImageColor()
    const cocos2d::Color3B &ret = (const cocos2d::Color3B &)self->getBackGroundImageColor();
    int num_ret = manual_olua_push_cocos2d_Color3B(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Layout_getBackGroundImageOpacity(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Layout *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Layout");

    // uint8_t getBackGroundImageOpacity()
    uint8_t ret = (uint8_t)self->getBackGroundImageOpacity();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Layout_getBackGroundImageTextureSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Layout *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Layout");

    // const cocos2d::Size &getBackGroundImageTextureSize()
    const cocos2d::Size &ret = (const cocos2d::Size &)self->getBackGroundImageTextureSize();
    int num_ret = auto_olua_push_cocos2d_Size(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Layout_getBackGroundStartColor(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Layout *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Layout");

    // const cocos2d::Color3B &getBackGroundStartColor()
    const cocos2d::Color3B &ret = (const cocos2d::Color3B &)self->getBackGroundStartColor();
    int num_ret = manual_olua_push_cocos2d_Color3B(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Layout_getClippingType(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Layout *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Layout");

    // cocos2d::ui::Layout::ClippingType getClippingType()
    cocos2d::ui::Layout::ClippingType ret = (cocos2d::ui::Layout::ClippingType)self->getClippingType();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Layout_getLayoutType(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Layout *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Layout");

    // cocos2d::ui::Layout::Type getLayoutType()
    cocos2d::ui::Layout::Type ret = (cocos2d::ui::Layout::Type)self->getLayoutType();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Layout_getRenderFile(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Layout *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Layout");

    // cocos2d::ResourceData getRenderFile()
    cocos2d::ResourceData ret = (cocos2d::ResourceData)self->getRenderFile();
    int num_ret = auto_olua_push_cocos2d_ResourceData(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Layout_isBackGroundImageScale9Enabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Layout *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Layout");

    // bool isBackGroundImageScale9Enabled()
    bool ret = (bool)self->isBackGroundImageScale9Enabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Layout_isClippingEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Layout *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Layout");

    // bool isClippingEnabled()
    bool ret = (bool)self->isClippingEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Layout_isLoopFocus(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Layout *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Layout");

    // bool isLoopFocus()
    bool ret = (bool)self->isLoopFocus();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Layout_isPassFocusToChild(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Layout *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Layout");

    // bool isPassFocusToChild()
    bool ret = (bool)self->isPassFocusToChild();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Layout_new(lua_State *L)
{
    olua_startinvoke(L);

    // Layout()
    cocos2d::ui::Layout *ret = (cocos2d::ui::Layout *)new cocos2d::ui::Layout();
    int num_ret = olua_push_cppobj(L, ret, "ccui.Layout");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Layout_removeBackGroundImage(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Layout *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Layout");

    // void removeBackGroundImage()
    self->removeBackGroundImage();

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Layout_requestDoLayout(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Layout *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Layout");

    // void requestDoLayout()
    self->requestDoLayout();

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Layout_setBackGroundColor1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Layout *self = nullptr;
    cocos2d::Color3B arg1;       /** color */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Layout");
    manual_olua_check_cocos2d_Color3B(L, 2, &arg1);

    // void setBackGroundColor(const cocos2d::Color3B &color)
    self->setBackGroundColor(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Layout_setBackGroundColor2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Layout *self = nullptr;
    cocos2d::Color3B arg1;       /** startColor */
    cocos2d::Color3B arg2;       /** endColor */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Layout");
    manual_olua_check_cocos2d_Color3B(L, 2, &arg1);
    manual_olua_check_cocos2d_Color3B(L, 3, &arg2);

    // void setBackGroundColor(const cocos2d::Color3B &startColor, const cocos2d::Color3B &endColor)
    self->setBackGroundColor(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Layout_setBackGroundColor(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((manual_olua_is_cocos2d_Color3B(L, 2))) {
            // void setBackGroundColor(const cocos2d::Color3B &color)
            return _cocos2d_ui_Layout_setBackGroundColor1(L);
        // }
    }

    if (num_args == 2) {
        // if ((manual_olua_is_cocos2d_Color3B(L, 2)) && (manual_olua_is_cocos2d_Color3B(L, 3))) {
            // void setBackGroundColor(const cocos2d::Color3B &startColor, const cocos2d::Color3B &endColor)
            return _cocos2d_ui_Layout_setBackGroundColor2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::Layout::setBackGroundColor' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ui_Layout_setBackGroundColorOpacity(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Layout *self = nullptr;
    lua_Unsigned arg1 = 0;       /** opacity */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Layout");
    olua_check_uint(L, 2, &arg1);

    // void setBackGroundColorOpacity(uint8_t opacity)
    self->setBackGroundColorOpacity((uint8_t)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Layout_setBackGroundColorType(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Layout *self = nullptr;
    lua_Unsigned arg1 = 0;       /** type */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Layout");
    olua_check_uint(L, 2, &arg1);

    // void setBackGroundColorType(cocos2d::ui::Layout::BackGroundColorType type)
    self->setBackGroundColorType((cocos2d::ui::Layout::BackGroundColorType)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Layout_setBackGroundColorVector(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Layout *self = nullptr;
    cocos2d::Vec2 arg1;       /** vector */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Layout");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);

    // void setBackGroundColorVector(const cocos2d::Vec2 &vector)
    self->setBackGroundColorVector(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Layout_setBackGroundImage1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Layout *self = nullptr;
    std::string arg1;       /** fileName */
    lua_Unsigned arg2 = 0;       /** texType */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Layout");
    olua_check_std_string(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // void setBackGroundImage(const std::string &fileName, @optional cocos2d::ui::Widget::TextureResType texType)
    self->setBackGroundImage(arg1, (cocos2d::ui::Widget::TextureResType)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Layout_setBackGroundImage2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Layout *self = nullptr;
    std::string arg1;       /** fileName */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Layout");
    olua_check_std_string(L, 2, &arg1);

    // void setBackGroundImage(const std::string &fileName, @optional cocos2d::ui::Widget::TextureResType texType)
    self->setBackGroundImage(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Layout_setBackGroundImage(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 2))) {
            // void setBackGroundImage(const std::string &fileName, @optional cocos2d::ui::Widget::TextureResType texType)
            return _cocos2d_ui_Layout_setBackGroundImage2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_uint(L, 3))) {
            // void setBackGroundImage(const std::string &fileName, @optional cocos2d::ui::Widget::TextureResType texType)
            return _cocos2d_ui_Layout_setBackGroundImage1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::Layout::setBackGroundImage' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ui_Layout_setBackGroundImageCapInsets(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Layout *self = nullptr;
    cocos2d::Rect arg1;       /** capInsets */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Layout");
    manual_olua_check_cocos2d_Rect(L, 2, &arg1);

    // void setBackGroundImageCapInsets(const cocos2d::Rect &capInsets)
    self->setBackGroundImageCapInsets(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Layout_setBackGroundImageColor(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Layout *self = nullptr;
    cocos2d::Color3B arg1;       /** color */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Layout");
    manual_olua_check_cocos2d_Color3B(L, 2, &arg1);

    // void setBackGroundImageColor(const cocos2d::Color3B &color)
    self->setBackGroundImageColor(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Layout_setBackGroundImageOpacity(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Layout *self = nullptr;
    lua_Unsigned arg1 = 0;       /** opacity */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Layout");
    olua_check_uint(L, 2, &arg1);

    // void setBackGroundImageOpacity(uint8_t opacity)
    self->setBackGroundImageOpacity((uint8_t)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Layout_setBackGroundImageScale9Enabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Layout *self = nullptr;
    bool arg1 = false;       /** enabled */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Layout");
    olua_check_bool(L, 2, &arg1);

    // void setBackGroundImageScale9Enabled(bool enabled)
    self->setBackGroundImageScale9Enabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Layout_setClippingEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Layout *self = nullptr;
    bool arg1 = false;       /** enabled */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Layout");
    olua_check_bool(L, 2, &arg1);

    // void setClippingEnabled(bool enabled)
    self->setClippingEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Layout_setClippingType(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Layout *self = nullptr;
    lua_Unsigned arg1 = 0;       /** type */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Layout");
    olua_check_uint(L, 2, &arg1);

    // void setClippingType(cocos2d::ui::Layout::ClippingType type)
    self->setClippingType((cocos2d::ui::Layout::ClippingType)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Layout_setLayoutType(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Layout *self = nullptr;
    lua_Unsigned arg1 = 0;       /** type */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Layout");
    olua_check_uint(L, 2, &arg1);

    // void setLayoutType(cocos2d::ui::Layout::Type type)
    self->setLayoutType((cocos2d::ui::Layout::Type)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Layout_setLoopFocus(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Layout *self = nullptr;
    bool arg1 = false;       /** loop */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Layout");
    olua_check_bool(L, 2, &arg1);

    // void setLoopFocus(bool loop)
    self->setLoopFocus(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Layout_setPassFocusToChild(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Layout *self = nullptr;
    bool arg1 = false;       /** pass */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Layout");
    olua_check_bool(L, 2, &arg1);

    // void setPassFocusToChild(bool pass)
    self->setPassFocusToChild(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Layout_get_onPassFocusToChild(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Layout *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Layout");

    void *callback_store_obj = (void *)self;
    std::string tag = "onPassFocusToChild";
    olua_getcallback(L, callback_store_obj, tag.c_str(), OLUA_TAG_SUBEQUAL);

    // @nullable std::function<int(Widget::FocusDirection, Widget*)> onPassFocusToChild
    std::function<int(cocos2d::ui::Widget::FocusDirection, cocos2d::ui::Widget *)> ret = (std::function<int(cocos2d::ui::Widget::FocusDirection, cocos2d::ui::Widget *)>)self->onPassFocusToChild;
    int num_ret = olua_push_std_function(L, (std::function<int(cocos2d::ui::Widget::FocusDirection, cocos2d::ui::Widget *)>)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Layout_set_onPassFocusToChild(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Layout *self = nullptr;
    std::function<int(cocos2d::ui::Widget::FocusDirection, cocos2d::ui::Widget *)> arg1;       /** onPassFocusToChild */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Layout");

    if (olua_is_std_function(L, 2)) {
        void *callback_store_obj = (void *)self;
        std::string tag = "onPassFocusToChild";
        std::string func = olua_setcallback(L, callback_store_obj, tag.c_str(), 2, OLUA_TAG_REPLACE);
        lua_State *MT = olua_mainthread();
        arg1 = [callback_store_obj, func, MT](cocos2d::ui::Widget::FocusDirection arg1, cocos2d::ui::Widget *arg2) {
            lua_State *L = olua_mainthread();
            lua_Integer ret = 0;       
            if (MT == L) {
                int top = lua_gettop(L);
                olua_push_uint(L, (lua_Unsigned)arg1);
                olua_push_cppobj(L, arg2, "ccui.Widget");

                olua_callback(L, callback_store_obj, func.c_str(), 2);

                if (olua_is_int(L, -1)) {
                    olua_check_int(L, -1, &ret);
                }

                lua_settop(L, top);
            }
            return (int)ret;
        };
    } else {
        void *callback_store_obj = (void *)self;
        std::string tag = "onPassFocusToChild";
        olua_removecallback(L, callback_store_obj, tag.c_str(), OLUA_TAG_SUBEQUAL);
        arg1 = nullptr;
    }

    // @nullable std::function<int(Widget::FocusDirection, Widget*)> onPassFocusToChild
    self->onPassFocusToChild = arg1;

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_ui_Layout(lua_State *L)
{
    oluacls_class(L, "ccui.Layout", "ccui.Widget");
    oluacls_func(L, "__move", _cocos2d_ui_Layout___move);
    oluacls_func(L, "create", _cocos2d_ui_Layout_create);
    oluacls_func(L, "createInstance", _cocos2d_ui_Layout_createInstance);
    oluacls_func(L, "forceDoLayout", _cocos2d_ui_Layout_forceDoLayout);
    oluacls_func(L, "getBackGroundColor", _cocos2d_ui_Layout_getBackGroundColor);
    oluacls_func(L, "getBackGroundColorOpacity", _cocos2d_ui_Layout_getBackGroundColorOpacity);
    oluacls_func(L, "getBackGroundColorType", _cocos2d_ui_Layout_getBackGroundColorType);
    oluacls_func(L, "getBackGroundColorVector", _cocos2d_ui_Layout_getBackGroundColorVector);
    oluacls_func(L, "getBackGroundEndColor", _cocos2d_ui_Layout_getBackGroundEndColor);
    oluacls_func(L, "getBackGroundImageCapInsets", _cocos2d_ui_Layout_getBackGroundImageCapInsets);
    oluacls_func(L, "getBackGroundImageColor", _cocos2d_ui_Layout_getBackGroundImageColor);
    oluacls_func(L, "getBackGroundImageOpacity", _cocos2d_ui_Layout_getBackGroundImageOpacity);
    oluacls_func(L, "getBackGroundImageTextureSize", _cocos2d_ui_Layout_getBackGroundImageTextureSize);
    oluacls_func(L, "getBackGroundStartColor", _cocos2d_ui_Layout_getBackGroundStartColor);
    oluacls_func(L, "getClippingType", _cocos2d_ui_Layout_getClippingType);
    oluacls_func(L, "getLayoutType", _cocos2d_ui_Layout_getLayoutType);
    oluacls_func(L, "getRenderFile", _cocos2d_ui_Layout_getRenderFile);
    oluacls_func(L, "isBackGroundImageScale9Enabled", _cocos2d_ui_Layout_isBackGroundImageScale9Enabled);
    oluacls_func(L, "isClippingEnabled", _cocos2d_ui_Layout_isClippingEnabled);
    oluacls_func(L, "isLoopFocus", _cocos2d_ui_Layout_isLoopFocus);
    oluacls_func(L, "isPassFocusToChild", _cocos2d_ui_Layout_isPassFocusToChild);
    oluacls_func(L, "new", _cocos2d_ui_Layout_new);
    oluacls_func(L, "removeBackGroundImage", _cocos2d_ui_Layout_removeBackGroundImage);
    oluacls_func(L, "requestDoLayout", _cocos2d_ui_Layout_requestDoLayout);
    oluacls_func(L, "setBackGroundColor", _cocos2d_ui_Layout_setBackGroundColor);
    oluacls_func(L, "setBackGroundColorOpacity", _cocos2d_ui_Layout_setBackGroundColorOpacity);
    oluacls_func(L, "setBackGroundColorType", _cocos2d_ui_Layout_setBackGroundColorType);
    oluacls_func(L, "setBackGroundColorVector", _cocos2d_ui_Layout_setBackGroundColorVector);
    oluacls_func(L, "setBackGroundImage", _cocos2d_ui_Layout_setBackGroundImage);
    oluacls_func(L, "setBackGroundImageCapInsets", _cocos2d_ui_Layout_setBackGroundImageCapInsets);
    oluacls_func(L, "setBackGroundImageColor", _cocos2d_ui_Layout_setBackGroundImageColor);
    oluacls_func(L, "setBackGroundImageOpacity", _cocos2d_ui_Layout_setBackGroundImageOpacity);
    oluacls_func(L, "setBackGroundImageScale9Enabled", _cocos2d_ui_Layout_setBackGroundImageScale9Enabled);
    oluacls_func(L, "setClippingEnabled", _cocos2d_ui_Layout_setClippingEnabled);
    oluacls_func(L, "setClippingType", _cocos2d_ui_Layout_setClippingType);
    oluacls_func(L, "setLayoutType", _cocos2d_ui_Layout_setLayoutType);
    oluacls_func(L, "setLoopFocus", _cocos2d_ui_Layout_setLoopFocus);
    oluacls_func(L, "setPassFocusToChild", _cocos2d_ui_Layout_setPassFocusToChild);
    oluacls_prop(L, "backGroundColor", _cocos2d_ui_Layout_getBackGroundColor, _cocos2d_ui_Layout_setBackGroundColor);
    oluacls_prop(L, "backGroundColorOpacity", _cocos2d_ui_Layout_getBackGroundColorOpacity, _cocos2d_ui_Layout_setBackGroundColorOpacity);
    oluacls_prop(L, "backGroundColorType", _cocos2d_ui_Layout_getBackGroundColorType, _cocos2d_ui_Layout_setBackGroundColorType);
    oluacls_prop(L, "backGroundColorVector", _cocos2d_ui_Layout_getBackGroundColorVector, _cocos2d_ui_Layout_setBackGroundColorVector);
    oluacls_prop(L, "backGroundEndColor", _cocos2d_ui_Layout_getBackGroundEndColor, nullptr);
    oluacls_prop(L, "backGroundImageCapInsets", _cocos2d_ui_Layout_getBackGroundImageCapInsets, _cocos2d_ui_Layout_setBackGroundImageCapInsets);
    oluacls_prop(L, "backGroundImageColor", _cocos2d_ui_Layout_getBackGroundImageColor, _cocos2d_ui_Layout_setBackGroundImageColor);
    oluacls_prop(L, "backGroundImageOpacity", _cocos2d_ui_Layout_getBackGroundImageOpacity, _cocos2d_ui_Layout_setBackGroundImageOpacity);
    oluacls_prop(L, "backGroundImageScale9Enabled", _cocos2d_ui_Layout_isBackGroundImageScale9Enabled, _cocos2d_ui_Layout_setBackGroundImageScale9Enabled);
    oluacls_prop(L, "backGroundImageTextureSize", _cocos2d_ui_Layout_getBackGroundImageTextureSize, nullptr);
    oluacls_prop(L, "backGroundStartColor", _cocos2d_ui_Layout_getBackGroundStartColor, nullptr);
    oluacls_prop(L, "clippingEnabled", _cocos2d_ui_Layout_isClippingEnabled, _cocos2d_ui_Layout_setClippingEnabled);
    oluacls_prop(L, "clippingType", _cocos2d_ui_Layout_getClippingType, _cocos2d_ui_Layout_setClippingType);
    oluacls_prop(L, "layoutType", _cocos2d_ui_Layout_getLayoutType, _cocos2d_ui_Layout_setLayoutType);
    oluacls_prop(L, "loopFocus", _cocos2d_ui_Layout_isLoopFocus, _cocos2d_ui_Layout_setLoopFocus);
    oluacls_prop(L, "passFocusToChild", _cocos2d_ui_Layout_isPassFocusToChild, _cocos2d_ui_Layout_setPassFocusToChild);
    oluacls_prop(L, "renderFile", _cocos2d_ui_Layout_getRenderFile, nullptr);
    oluacls_prop(L, "onPassFocusToChild", _cocos2d_ui_Layout_get_onPassFocusToChild, _cocos2d_ui_Layout_set_onPassFocusToChild);

    olua_registerluatype<cocos2d::ui::Layout>(L, "ccui.Layout");

    return 1;
}

static int _cocos2d_ui_HBox___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::ui::HBox *)olua_toobj(L, 1, "ccui.HBox");
    olua_push_cppobj(L, self, "ccui.HBox");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_ui_HBox_create1(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::ui::HBox *create()
    cocos2d::ui::HBox *ret = (cocos2d::ui::HBox *)cocos2d::ui::HBox::create();
    int num_ret = olua_push_cppobj(L, ret, "ccui.HBox");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_HBox_create2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size arg1;       /** size */

    auto_olua_check_cocos2d_Size(L, 1, &arg1);

    // static cocos2d::ui::HBox *create(const cocos2d::Size &size)
    cocos2d::ui::HBox *ret = (cocos2d::ui::HBox *)cocos2d::ui::HBox::create(arg1);
    int num_ret = olua_push_cppobj(L, ret, "ccui.HBox");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_HBox_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // static cocos2d::ui::HBox *create()
        return _cocos2d_ui_HBox_create1(L);
    }

    if (num_args == 1) {
        // if ((auto_olua_is_cocos2d_Size(L, 1))) {
            // static cocos2d::ui::HBox *create(const cocos2d::Size &size)
            return _cocos2d_ui_HBox_create2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::HBox::create' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ui_HBox_initWithSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::HBox *self = nullptr;
    cocos2d::Size arg1;       /** size */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.HBox");
    auto_olua_check_cocos2d_Size(L, 2, &arg1);

    // bool initWithSize(const cocos2d::Size &size)
    bool ret = (bool)self->initWithSize(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_HBox_new(lua_State *L)
{
    olua_startinvoke(L);

    // HBox()
    cocos2d::ui::HBox *ret = (cocos2d::ui::HBox *)new cocos2d::ui::HBox();
    int num_ret = olua_push_cppobj(L, ret, "ccui.HBox");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_ui_HBox(lua_State *L)
{
    oluacls_class(L, "ccui.HBox", "ccui.Layout");
    oluacls_func(L, "__move", _cocos2d_ui_HBox___move);
    oluacls_func(L, "create", _cocos2d_ui_HBox_create);
    oluacls_func(L, "initWithSize", _cocos2d_ui_HBox_initWithSize);
    oluacls_func(L, "new", _cocos2d_ui_HBox_new);

    olua_registerluatype<cocos2d::ui::HBox>(L, "ccui.HBox");

    return 1;
}

static int _cocos2d_ui_VBox___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::ui::VBox *)olua_toobj(L, 1, "ccui.VBox");
    olua_push_cppobj(L, self, "ccui.VBox");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_ui_VBox_create1(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::ui::VBox *create()
    cocos2d::ui::VBox *ret = (cocos2d::ui::VBox *)cocos2d::ui::VBox::create();
    int num_ret = olua_push_cppobj(L, ret, "ccui.VBox");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_VBox_create2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size arg1;       /** size */

    auto_olua_check_cocos2d_Size(L, 1, &arg1);

    // static cocos2d::ui::VBox *create(const cocos2d::Size &size)
    cocos2d::ui::VBox *ret = (cocos2d::ui::VBox *)cocos2d::ui::VBox::create(arg1);
    int num_ret = olua_push_cppobj(L, ret, "ccui.VBox");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_VBox_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // static cocos2d::ui::VBox *create()
        return _cocos2d_ui_VBox_create1(L);
    }

    if (num_args == 1) {
        // if ((auto_olua_is_cocos2d_Size(L, 1))) {
            // static cocos2d::ui::VBox *create(const cocos2d::Size &size)
            return _cocos2d_ui_VBox_create2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::VBox::create' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ui_VBox_initWithSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::VBox *self = nullptr;
    cocos2d::Size arg1;       /** size */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.VBox");
    auto_olua_check_cocos2d_Size(L, 2, &arg1);

    // bool initWithSize(const cocos2d::Size &size)
    bool ret = (bool)self->initWithSize(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_VBox_new(lua_State *L)
{
    olua_startinvoke(L);

    // VBox()
    cocos2d::ui::VBox *ret = (cocos2d::ui::VBox *)new cocos2d::ui::VBox();
    int num_ret = olua_push_cppobj(L, ret, "ccui.VBox");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_ui_VBox(lua_State *L)
{
    oluacls_class(L, "ccui.VBox", "ccui.Layout");
    oluacls_func(L, "__move", _cocos2d_ui_VBox___move);
    oluacls_func(L, "create", _cocos2d_ui_VBox_create);
    oluacls_func(L, "initWithSize", _cocos2d_ui_VBox_initWithSize);
    oluacls_func(L, "new", _cocos2d_ui_VBox_new);

    olua_registerluatype<cocos2d::ui::VBox>(L, "ccui.VBox");

    return 1;
}

static int _cocos2d_ui_RelativeBox___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::ui::RelativeBox *)olua_toobj(L, 1, "ccui.RelativeBox");
    olua_push_cppobj(L, self, "ccui.RelativeBox");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_ui_RelativeBox_create1(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::ui::RelativeBox *create()
    cocos2d::ui::RelativeBox *ret = (cocos2d::ui::RelativeBox *)cocos2d::ui::RelativeBox::create();
    int num_ret = olua_push_cppobj(L, ret, "ccui.RelativeBox");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_RelativeBox_create2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size arg1;       /** size */

    auto_olua_check_cocos2d_Size(L, 1, &arg1);

    // static cocos2d::ui::RelativeBox *create(const cocos2d::Size &size)
    cocos2d::ui::RelativeBox *ret = (cocos2d::ui::RelativeBox *)cocos2d::ui::RelativeBox::create(arg1);
    int num_ret = olua_push_cppobj(L, ret, "ccui.RelativeBox");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_RelativeBox_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // static cocos2d::ui::RelativeBox *create()
        return _cocos2d_ui_RelativeBox_create1(L);
    }

    if (num_args == 1) {
        // if ((auto_olua_is_cocos2d_Size(L, 1))) {
            // static cocos2d::ui::RelativeBox *create(const cocos2d::Size &size)
            return _cocos2d_ui_RelativeBox_create2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::RelativeBox::create' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ui_RelativeBox_initWithSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RelativeBox *self = nullptr;
    cocos2d::Size arg1;       /** size */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RelativeBox");
    auto_olua_check_cocos2d_Size(L, 2, &arg1);

    // bool initWithSize(const cocos2d::Size &size)
    bool ret = (bool)self->initWithSize(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_RelativeBox_new(lua_State *L)
{
    olua_startinvoke(L);

    // RelativeBox()
    cocos2d::ui::RelativeBox *ret = (cocos2d::ui::RelativeBox *)new cocos2d::ui::RelativeBox();
    int num_ret = olua_push_cppobj(L, ret, "ccui.RelativeBox");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_ui_RelativeBox(lua_State *L)
{
    oluacls_class(L, "ccui.RelativeBox", "ccui.Layout");
    oluacls_func(L, "__move", _cocos2d_ui_RelativeBox___move);
    oluacls_func(L, "create", _cocos2d_ui_RelativeBox_create);
    oluacls_func(L, "initWithSize", _cocos2d_ui_RelativeBox_initWithSize);
    oluacls_func(L, "new", _cocos2d_ui_RelativeBox_new);

    olua_registerluatype<cocos2d::ui::RelativeBox>(L, "ccui.RelativeBox");

    return 1;
}

#ifdef CCLUA_HAVE_WEBVIEW
static int _cocos2d_ui_WebView___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::ui::WebView *)olua_toobj(L, 1, "ccui.WebView");
    olua_push_cppobj(L, self, "ccui.WebView");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_ui_WebView_canGoBack(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::WebView *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.WebView");

    // bool canGoBack()
    bool ret = (bool)self->canGoBack();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_WebView_canGoForward(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::WebView *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.WebView");

    // bool canGoForward()
    bool ret = (bool)self->canGoForward();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_WebView_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::ui::WebView *create()
    cocos2d::ui::WebView *ret = (cocos2d::ui::WebView *)cocos2d::ui::WebView::create();
    int num_ret = olua_push_cppobj(L, ret, "ccui.WebView");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_WebView_evaluateJS(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::WebView *self = nullptr;
    std::string arg1;       /** js */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.WebView");
    olua_check_std_string(L, 2, &arg1);

    // void evaluateJS(const std::string &js)
    self->evaluateJS(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_WebView_getOnDidFailLoading(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::WebView *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.WebView");

    void *callback_store_obj = (void *)self;
    std::string tag = "OnDidFailLoading";
    olua_getcallback(L, callback_store_obj, tag.c_str(), OLUA_TAG_SUBEQUAL);

    // @local std::function<void (WebView *, const std::string &)> getOnDidFailLoading()
    std::function<void(cocos2d::ui::WebView *, const std::string &)> ret = (std::function<void(cocos2d::ui::WebView *, const std::string &)>)self->getOnDidFailLoading();
    int num_ret = olua_push_std_function(L, (std::function<void(cocos2d::ui::WebView *, const std::string &)>)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_WebView_getOnDidFinishLoading(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::WebView *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.WebView");

    void *callback_store_obj = (void *)self;
    std::string tag = "OnDidFinishLoading";
    olua_getcallback(L, callback_store_obj, tag.c_str(), OLUA_TAG_SUBEQUAL);

    // @local std::function<void (WebView *, const std::string &)> getOnDidFinishLoading()
    std::function<void(cocos2d::ui::WebView *, const std::string &)> ret = (std::function<void(cocos2d::ui::WebView *, const std::string &)>)self->getOnDidFinishLoading();
    int num_ret = olua_push_std_function(L, (std::function<void(cocos2d::ui::WebView *, const std::string &)>)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_WebView_getOnJSCallback(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::WebView *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.WebView");

    void *callback_store_obj = (void *)self;
    std::string tag = "OnJSCallback";
    olua_getcallback(L, callback_store_obj, tag.c_str(), OLUA_TAG_SUBEQUAL);

    // @local std::function<void (WebView *, const std::string &)> getOnJSCallback()
    std::function<void(cocos2d::ui::WebView *, const std::string &)> ret = (std::function<void(cocos2d::ui::WebView *, const std::string &)>)self->getOnJSCallback();
    int num_ret = olua_push_std_function(L, (std::function<void(cocos2d::ui::WebView *, const std::string &)>)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_WebView_getOnShouldStartLoading(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::WebView *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.WebView");

    void *callback_store_obj = (void *)self;
    std::string tag = "OnShouldStartLoading";
    olua_getcallback(L, callback_store_obj, tag.c_str(), OLUA_TAG_SUBEQUAL);

    // @local std::function<bool (WebView *, const std::string &)> getOnShouldStartLoading()
    std::function<bool(cocos2d::ui::WebView *, const std::string &)> ret = (std::function<bool(cocos2d::ui::WebView *, const std::string &)>)self->getOnShouldStartLoading();
    int num_ret = olua_push_std_function(L, (std::function<bool(cocos2d::ui::WebView *, const std::string &)>)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_WebView_getOpacityWebView(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::WebView *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.WebView");

    // float getOpacityWebView()
    float ret = (float)self->getOpacityWebView();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_WebView_goBack(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::WebView *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.WebView");

    // void goBack()
    self->goBack();

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_WebView_goForward(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::WebView *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.WebView");

    // void goForward()
    self->goForward();

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_WebView_loadData(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::WebView *self = nullptr;
    cocos2d::Data arg1;       /** data */
    std::string arg2;       /** MIMEType */
    std::string arg3;       /** encoding */
    std::string arg4;       /** baseURL */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.WebView");
    manual_olua_check_cocos2d_Data(L, 2, &arg1);
    olua_check_std_string(L, 3, &arg2);
    olua_check_std_string(L, 4, &arg3);
    olua_check_std_string(L, 5, &arg4);

    // void loadData(const cocos2d::Data &data, const std::string &MIMEType, const std::string &encoding, const std::string &baseURL)
    self->loadData(arg1, arg2, arg3, arg4);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_WebView_loadFile(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::WebView *self = nullptr;
    std::string arg1;       /** fileName */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.WebView");
    olua_check_std_string(L, 2, &arg1);

    // void loadFile(const std::string &fileName)
    self->loadFile(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_WebView_loadHTMLString1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::WebView *self = nullptr;
    std::string arg1;       /** string */
    std::string arg2;       /** baseURL */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.WebView");
    olua_check_std_string(L, 2, &arg1);
    olua_check_std_string(L, 3, &arg2);

    // void loadHTMLString(const std::string &string, @optional const std::string &baseURL)
    self->loadHTMLString(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_WebView_loadHTMLString2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::WebView *self = nullptr;
    std::string arg1;       /** string */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.WebView");
    olua_check_std_string(L, 2, &arg1);

    // void loadHTMLString(const std::string &string, @optional const std::string &baseURL)
    self->loadHTMLString(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_WebView_loadHTMLString(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 2))) {
            // void loadHTMLString(const std::string &string, @optional const std::string &baseURL)
            return _cocos2d_ui_WebView_loadHTMLString2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_std_string(L, 3))) {
            // void loadHTMLString(const std::string &string, @optional const std::string &baseURL)
            return _cocos2d_ui_WebView_loadHTMLString1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::WebView::loadHTMLString' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ui_WebView_loadURL1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::WebView *self = nullptr;
    std::string arg1;       /** url */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.WebView");
    olua_check_std_string(L, 2, &arg1);

    // void loadURL(const std::string &url)
    self->loadURL(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_WebView_loadURL2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::WebView *self = nullptr;
    std::string arg1;       /** url */
    bool arg2 = false;       /** cleanCachedData */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.WebView");
    olua_check_std_string(L, 2, &arg1);
    olua_check_bool(L, 3, &arg2);

    // void loadURL(const std::string &url, bool cleanCachedData)
    self->loadURL(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_WebView_loadURL(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 2))) {
            // void loadURL(const std::string &url)
            return _cocos2d_ui_WebView_loadURL1(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_bool(L, 3))) {
            // void loadURL(const std::string &url, bool cleanCachedData)
            return _cocos2d_ui_WebView_loadURL2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::WebView::loadURL' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ui_WebView_new(lua_State *L)
{
    olua_startinvoke(L);

    // WebView()
    cocos2d::ui::WebView *ret = (cocos2d::ui::WebView *)new cocos2d::ui::WebView();
    int num_ret = olua_push_cppobj(L, ret, "ccui.WebView");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_WebView_reload(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::WebView *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.WebView");

    // void reload()
    self->reload();

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_WebView_setBackgroundTransparent(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::WebView *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.WebView");

    // void setBackgroundTransparent()
    self->setBackgroundTransparent();

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_WebView_setBounces(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::WebView *self = nullptr;
    bool arg1 = false;       /** bounce */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.WebView");
    olua_check_bool(L, 2, &arg1);

    // void setBounces(bool bounce)
    self->setBounces(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_WebView_setJavascriptInterfaceScheme(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::WebView *self = nullptr;
    std::string arg1;       /** scheme */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.WebView");
    olua_check_std_string(L, 2, &arg1);

    // void setJavascriptInterfaceScheme(const std::string &scheme)
    self->setJavascriptInterfaceScheme(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_WebView_setOnDidFailLoading(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::WebView *self = nullptr;
    std::function<void(cocos2d::ui::WebView *, const std::string &)> arg1;       /** callback */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.WebView");

    if (olua_is_std_function(L, 2)) {
        void *callback_store_obj = (void *)self;
        std::string tag = "OnDidFailLoading";
        std::string func = olua_setcallback(L, callback_store_obj, tag.c_str(), 2, OLUA_TAG_REPLACE);
        lua_State *MT = olua_mainthread();
        arg1 = [callback_store_obj, func, MT](cocos2d::ui::WebView *arg1, const std::string &arg2) {
            lua_State *L = olua_mainthread();

            if (MT == L) {
                int top = lua_gettop(L);
                olua_push_cppobj(L, arg1, "ccui.WebView");
                olua_push_std_string(L, arg2);

                olua_callback(L, callback_store_obj, func.c_str(), 2);

                lua_settop(L, top);
            }
        };
    } else {
        void *callback_store_obj = (void *)self;
        std::string tag = "OnDidFailLoading";
        olua_removecallback(L, callback_store_obj, tag.c_str(), OLUA_TAG_SUBEQUAL);
        arg1 = nullptr;
    }

    // void setOnDidFailLoading(@nullable const std::function<void (WebView *, const std::string &)> &callback)
    self->setOnDidFailLoading(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_WebView_setOnDidFinishLoading(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::WebView *self = nullptr;
    std::function<void(cocos2d::ui::WebView *, const std::string &)> arg1;       /** callback */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.WebView");

    if (olua_is_std_function(L, 2)) {
        void *callback_store_obj = (void *)self;
        std::string tag = "OnDidFinishLoading";
        std::string func = olua_setcallback(L, callback_store_obj, tag.c_str(), 2, OLUA_TAG_REPLACE);
        lua_State *MT = olua_mainthread();
        arg1 = [callback_store_obj, func, MT](cocos2d::ui::WebView *arg1, const std::string &arg2) {
            lua_State *L = olua_mainthread();

            if (MT == L) {
                int top = lua_gettop(L);
                olua_push_cppobj(L, arg1, "ccui.WebView");
                olua_push_std_string(L, arg2);

                olua_callback(L, callback_store_obj, func.c_str(), 2);

                lua_settop(L, top);
            }
        };
    } else {
        void *callback_store_obj = (void *)self;
        std::string tag = "OnDidFinishLoading";
        olua_removecallback(L, callback_store_obj, tag.c_str(), OLUA_TAG_SUBEQUAL);
        arg1 = nullptr;
    }

    // void setOnDidFinishLoading(@nullable const std::function<void (WebView *, const std::string &)> &callback)
    self->setOnDidFinishLoading(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_WebView_setOnJSCallback(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::WebView *self = nullptr;
    std::function<void(cocos2d::ui::WebView *, const std::string &)> arg1;       /** callback */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.WebView");

    if (olua_is_std_function(L, 2)) {
        void *callback_store_obj = (void *)self;
        std::string tag = "OnJSCallback";
        std::string func = olua_setcallback(L, callback_store_obj, tag.c_str(), 2, OLUA_TAG_REPLACE);
        lua_State *MT = olua_mainthread();
        arg1 = [callback_store_obj, func, MT](cocos2d::ui::WebView *arg1, const std::string &arg2) {
            lua_State *L = olua_mainthread();

            if (MT == L) {
                int top = lua_gettop(L);
                olua_push_cppobj(L, arg1, "ccui.WebView");
                olua_push_std_string(L, arg2);

                olua_callback(L, callback_store_obj, func.c_str(), 2);

                lua_settop(L, top);
            }
        };
    } else {
        void *callback_store_obj = (void *)self;
        std::string tag = "OnJSCallback";
        olua_removecallback(L, callback_store_obj, tag.c_str(), OLUA_TAG_SUBEQUAL);
        arg1 = nullptr;
    }

    // void setOnJSCallback(@nullable const std::function<void (WebView *, const std::string &)> &callback)
    self->setOnJSCallback(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_WebView_setOnShouldStartLoading(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::WebView *self = nullptr;
    std::function<bool(cocos2d::ui::WebView *, const std::string &)> arg1;       /** callback */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.WebView");

    if (olua_is_std_function(L, 2)) {
        void *callback_store_obj = (void *)self;
        std::string tag = "OnShouldStartLoading";
        std::string func = olua_setcallback(L, callback_store_obj, tag.c_str(), 2, OLUA_TAG_REPLACE);
        lua_State *MT = olua_mainthread();
        arg1 = [callback_store_obj, func, MT](cocos2d::ui::WebView *arg1, const std::string &arg2) {
            lua_State *L = olua_mainthread();
            bool ret = false;       
            if (MT == L) {
                int top = lua_gettop(L);
                olua_push_cppobj(L, arg1, "ccui.WebView");
                olua_push_std_string(L, arg2);

                olua_callback(L, callback_store_obj, func.c_str(), 2);

                if (olua_is_bool(L, -1)) {
                    olua_check_bool(L, -1, &ret);
                }

                lua_settop(L, top);
            }
            return ret;
        };
    } else {
        void *callback_store_obj = (void *)self;
        std::string tag = "OnShouldStartLoading";
        olua_removecallback(L, callback_store_obj, tag.c_str(), OLUA_TAG_SUBEQUAL);
        arg1 = nullptr;
    }

    // void setOnShouldStartLoading(@nullable const std::function<bool (WebView *, const std::string &)> &callback)
    self->setOnShouldStartLoading(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_WebView_setOpacityWebView(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::WebView *self = nullptr;
    lua_Number arg1 = 0;       /** opacity */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.WebView");
    olua_check_number(L, 2, &arg1);

    // void setOpacityWebView(float opacity)
    self->setOpacityWebView((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_WebView_setScalesPageToFit(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::WebView *self = nullptr;
    bool arg1 = false;       /** scalesPageToFit */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.WebView");
    olua_check_bool(L, 2, &arg1);

    // void setScalesPageToFit(const bool scalesPageToFit)
    self->setScalesPageToFit(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_WebView_stopLoading(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::WebView *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.WebView");

    // void stopLoading()
    self->stopLoading();

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_ui_WebView(lua_State *L)
{
    oluacls_class(L, "ccui.WebView", "ccui.Widget");
    oluacls_func(L, "__move", _cocos2d_ui_WebView___move);
    oluacls_func(L, "canGoBack", _cocos2d_ui_WebView_canGoBack);
    oluacls_func(L, "canGoForward", _cocos2d_ui_WebView_canGoForward);
    oluacls_func(L, "create", _cocos2d_ui_WebView_create);
    oluacls_func(L, "evaluateJS", _cocos2d_ui_WebView_evaluateJS);
    oluacls_func(L, "getOnDidFailLoading", _cocos2d_ui_WebView_getOnDidFailLoading);
    oluacls_func(L, "getOnDidFinishLoading", _cocos2d_ui_WebView_getOnDidFinishLoading);
    oluacls_func(L, "getOnJSCallback", _cocos2d_ui_WebView_getOnJSCallback);
    oluacls_func(L, "getOnShouldStartLoading", _cocos2d_ui_WebView_getOnShouldStartLoading);
    oluacls_func(L, "getOpacityWebView", _cocos2d_ui_WebView_getOpacityWebView);
    oluacls_func(L, "goBack", _cocos2d_ui_WebView_goBack);
    oluacls_func(L, "goForward", _cocos2d_ui_WebView_goForward);
    oluacls_func(L, "loadData", _cocos2d_ui_WebView_loadData);
    oluacls_func(L, "loadFile", _cocos2d_ui_WebView_loadFile);
    oluacls_func(L, "loadHTMLString", _cocos2d_ui_WebView_loadHTMLString);
    oluacls_func(L, "loadURL", _cocos2d_ui_WebView_loadURL);
    oluacls_func(L, "new", _cocos2d_ui_WebView_new);
    oluacls_func(L, "reload", _cocos2d_ui_WebView_reload);
    oluacls_func(L, "setBackgroundTransparent", _cocos2d_ui_WebView_setBackgroundTransparent);
    oluacls_func(L, "setBounces", _cocos2d_ui_WebView_setBounces);
    oluacls_func(L, "setJavascriptInterfaceScheme", _cocos2d_ui_WebView_setJavascriptInterfaceScheme);
    oluacls_func(L, "setOnDidFailLoading", _cocos2d_ui_WebView_setOnDidFailLoading);
    oluacls_func(L, "setOnDidFinishLoading", _cocos2d_ui_WebView_setOnDidFinishLoading);
    oluacls_func(L, "setOnJSCallback", _cocos2d_ui_WebView_setOnJSCallback);
    oluacls_func(L, "setOnShouldStartLoading", _cocos2d_ui_WebView_setOnShouldStartLoading);
    oluacls_func(L, "setOpacityWebView", _cocos2d_ui_WebView_setOpacityWebView);
    oluacls_func(L, "setScalesPageToFit", _cocos2d_ui_WebView_setScalesPageToFit);
    oluacls_func(L, "stopLoading", _cocos2d_ui_WebView_stopLoading);
    oluacls_prop(L, "onDidFailLoading", _cocos2d_ui_WebView_getOnDidFailLoading, _cocos2d_ui_WebView_setOnDidFailLoading);
    oluacls_prop(L, "onDidFinishLoading", _cocos2d_ui_WebView_getOnDidFinishLoading, _cocos2d_ui_WebView_setOnDidFinishLoading);
    oluacls_prop(L, "onJSCallback", _cocos2d_ui_WebView_getOnJSCallback, _cocos2d_ui_WebView_setOnJSCallback);
    oluacls_prop(L, "onShouldStartLoading", _cocos2d_ui_WebView_getOnShouldStartLoading, _cocos2d_ui_WebView_setOnShouldStartLoading);
    oluacls_prop(L, "opacityWebView", _cocos2d_ui_WebView_getOpacityWebView, _cocos2d_ui_WebView_setOpacityWebView);

    olua_registerluatype<cocos2d::ui::WebView>(L, "ccui.WebView");

    return 1;
}
#endif

#ifdef CCLUA_HAVE_VIDEOPLAYER
static int luaopen_cocos2d_ui_VideoPlayer_EventType(lua_State *L)
{
    oluacls_class(L, "ccui.VideoPlayer.EventType", nullptr);
    oluacls_const_integer(L, "COMPLETED", (lua_Integer)cocos2d::ui::VideoPlayer::EventType::COMPLETED);
    oluacls_const_integer(L, "ERROR", (lua_Integer)cocos2d::ui::VideoPlayer::EventType::ERROR);
    oluacls_const_integer(L, "PAUSED", (lua_Integer)cocos2d::ui::VideoPlayer::EventType::PAUSED);
    oluacls_const_integer(L, "PLAYING", (lua_Integer)cocos2d::ui::VideoPlayer::EventType::PLAYING);
    oluacls_const_integer(L, "STOPPED", (lua_Integer)cocos2d::ui::VideoPlayer::EventType::STOPPED);

    olua_registerluatype<cocos2d::ui::VideoPlayer::EventType>(L, "ccui.VideoPlayer.EventType");

    return 1;
}
#endif

#ifdef CCLUA_HAVE_VIDEOPLAYER
static int luaopen_cocos2d_ui_VideoPlayer_StyleType(lua_State *L)
{
    oluacls_class(L, "ccui.VideoPlayer.StyleType", nullptr);
    oluacls_const_integer(L, "DEFAULT", (lua_Integer)cocos2d::ui::VideoPlayer::StyleType::DEFAULT);
    oluacls_const_integer(L, "NONE", (lua_Integer)cocos2d::ui::VideoPlayer::StyleType::NONE);

    olua_registerluatype<cocos2d::ui::VideoPlayer::StyleType>(L, "ccui.VideoPlayer.StyleType");

    return 1;
}
#endif

#ifdef CCLUA_HAVE_VIDEOPLAYER
static int _cocos2d_ui_VideoPlayer___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::ui::VideoPlayer *)olua_toobj(L, 1, "ccui.VideoPlayer");
    olua_push_cppobj(L, self, "ccui.VideoPlayer");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_ui_VideoPlayer_addEventListener(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::VideoPlayer *self = nullptr;
    std::function<void(cocos2d::Ref *, cocos2d::ui::VideoPlayer::EventType)> arg1;       /** callback */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.VideoPlayer");

    if (olua_is_std_function(L, 2)) {
        void *callback_store_obj = (void *)self;
        std::string tag = "videoPlayerCallback";
        std::string func = olua_setcallback(L, callback_store_obj, tag.c_str(), 2, OLUA_TAG_REPLACE);
        lua_State *MT = olua_mainthread();
        arg1 = [callback_store_obj, func, MT](cocos2d::Ref *arg1, cocos2d::ui::VideoPlayer::EventType arg2) {
            lua_State *L = olua_mainthread();

            if (MT == L) {
                int top = lua_gettop(L);
                olua_push_cppobj(L, arg1, "cc.Ref");
                olua_push_uint(L, (lua_Unsigned)arg2);

                olua_callback(L, callback_store_obj, func.c_str(), 2);

                lua_settop(L, top);
            }
        };
    } else {
        void *callback_store_obj = (void *)self;
        std::string tag = "videoPlayerCallback";
        olua_removecallback(L, callback_store_obj, tag.c_str(), OLUA_TAG_SUBEQUAL);
        arg1 = nullptr;
    }

    // void addEventListener(@nullable const std::function<void(Ref*,VideoPlayer::EventType)>& callback)
    self->addEventListener(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_VideoPlayer_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::ui::VideoPlayer *create()
    cocos2d::ui::VideoPlayer *ret = (cocos2d::ui::VideoPlayer *)cocos2d::ui::VideoPlayer::create();
    int num_ret = olua_push_cppobj(L, ret, "ccui.VideoPlayer");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_VideoPlayer_getFileName(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::VideoPlayer *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.VideoPlayer");

    // const std::string &getFileName()
    const std::string &ret = (const std::string &)self->getFileName();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_VideoPlayer_getURL(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::VideoPlayer *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.VideoPlayer");

    // const std::string &getURL()
    const std::string &ret = (const std::string &)self->getURL();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_VideoPlayer_isFullScreenEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::VideoPlayer *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.VideoPlayer");

    // bool isFullScreenEnabled()
    bool ret = (bool)self->isFullScreenEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_VideoPlayer_isKeepAspectRatioEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::VideoPlayer *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.VideoPlayer");

    // bool isKeepAspectRatioEnabled()
    bool ret = (bool)self->isKeepAspectRatioEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_VideoPlayer_isLooping(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::VideoPlayer *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.VideoPlayer");

    // bool isLooping()
    bool ret = (bool)self->isLooping();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_VideoPlayer_isPlaying(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::VideoPlayer *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.VideoPlayer");

    // bool isPlaying()
    bool ret = (bool)self->isPlaying();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_VideoPlayer_isUserInputEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::VideoPlayer *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.VideoPlayer");

    // bool isUserInputEnabled()
    bool ret = (bool)self->isUserInputEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_VideoPlayer_new(lua_State *L)
{
    olua_startinvoke(L);

    // VideoPlayer()
    cocos2d::ui::VideoPlayer *ret = (cocos2d::ui::VideoPlayer *)new cocos2d::ui::VideoPlayer();
    int num_ret = olua_push_cppobj(L, ret, "ccui.VideoPlayer");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_VideoPlayer_onPlayEvent(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::VideoPlayer *self = nullptr;
    lua_Integer arg1 = 0;       /** event */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.VideoPlayer");
    olua_check_int(L, 2, &arg1);

    // void onPlayEvent(int event)
    self->onPlayEvent((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_VideoPlayer_play(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::VideoPlayer *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.VideoPlayer");

    // void play()
    self->play();

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_VideoPlayer_seekTo(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::VideoPlayer *self = nullptr;
    lua_Number arg1 = 0;       /** sec */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.VideoPlayer");
    olua_check_number(L, 2, &arg1);

    // void seekTo(float sec)
    self->seekTo((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_VideoPlayer_setFileName(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::VideoPlayer *self = nullptr;
    std::string arg1;       /** videoPath */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.VideoPlayer");
    olua_check_std_string(L, 2, &arg1);

    // void setFileName(const std::string &videoPath)
    self->setFileName(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_VideoPlayer_setFullScreenEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::VideoPlayer *self = nullptr;
    bool arg1 = false;       /** fullscreen */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.VideoPlayer");
    olua_check_bool(L, 2, &arg1);

    // void setFullScreenEnabled(bool fullscreen)
    self->setFullScreenEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_VideoPlayer_setKeepAspectRatioEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::VideoPlayer *self = nullptr;
    bool arg1 = false;       /** enable */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.VideoPlayer");
    olua_check_bool(L, 2, &arg1);

    // void setKeepAspectRatioEnabled(bool enable)
    self->setKeepAspectRatioEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_VideoPlayer_setLooping(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::VideoPlayer *self = nullptr;
    bool arg1 = false;       /** looping */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.VideoPlayer");
    olua_check_bool(L, 2, &arg1);

    // void setLooping(bool looping)
    self->setLooping(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_VideoPlayer_setStyle(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::VideoPlayer *self = nullptr;
    lua_Unsigned arg1 = 0;       /** style */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.VideoPlayer");
    olua_check_uint(L, 2, &arg1);

    // void setStyle(cocos2d::ui::VideoPlayer::StyleType style)
    self->setStyle((cocos2d::ui::VideoPlayer::StyleType)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_VideoPlayer_setURL(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::VideoPlayer *self = nullptr;
    std::string arg1;       /** _videoURL */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.VideoPlayer");
    olua_check_std_string(L, 2, &arg1);

    // void setURL(const std::string &_videoURL)
    self->setURL(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_VideoPlayer_setUserInputEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::VideoPlayer *self = nullptr;
    bool arg1 = false;       /** enableInput */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.VideoPlayer");
    olua_check_bool(L, 2, &arg1);

    // void setUserInputEnabled(bool enableInput)
    self->setUserInputEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_VideoPlayer_stop(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::VideoPlayer *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.VideoPlayer");

    // void stop()
    self->stop();

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_ui_VideoPlayer(lua_State *L)
{
    oluacls_class(L, "ccui.VideoPlayer", "ccui.Widget");
    oluacls_func(L, "__move", _cocos2d_ui_VideoPlayer___move);
    oluacls_func(L, "addEventListener", _cocos2d_ui_VideoPlayer_addEventListener);
    oluacls_func(L, "create", _cocos2d_ui_VideoPlayer_create);
    oluacls_func(L, "getFileName", _cocos2d_ui_VideoPlayer_getFileName);
    oluacls_func(L, "getURL", _cocos2d_ui_VideoPlayer_getURL);
    oluacls_func(L, "isFullScreenEnabled", _cocos2d_ui_VideoPlayer_isFullScreenEnabled);
    oluacls_func(L, "isKeepAspectRatioEnabled", _cocos2d_ui_VideoPlayer_isKeepAspectRatioEnabled);
    oluacls_func(L, "isLooping", _cocos2d_ui_VideoPlayer_isLooping);
    oluacls_func(L, "isPlaying", _cocos2d_ui_VideoPlayer_isPlaying);
    oluacls_func(L, "isUserInputEnabled", _cocos2d_ui_VideoPlayer_isUserInputEnabled);
    oluacls_func(L, "new", _cocos2d_ui_VideoPlayer_new);
    oluacls_func(L, "onPlayEvent", _cocos2d_ui_VideoPlayer_onPlayEvent);
    oluacls_func(L, "play", _cocos2d_ui_VideoPlayer_play);
    oluacls_func(L, "seekTo", _cocos2d_ui_VideoPlayer_seekTo);
    oluacls_func(L, "setFileName", _cocos2d_ui_VideoPlayer_setFileName);
    oluacls_func(L, "setFullScreenEnabled", _cocos2d_ui_VideoPlayer_setFullScreenEnabled);
    oluacls_func(L, "setKeepAspectRatioEnabled", _cocos2d_ui_VideoPlayer_setKeepAspectRatioEnabled);
    oluacls_func(L, "setLooping", _cocos2d_ui_VideoPlayer_setLooping);
    oluacls_func(L, "setStyle", _cocos2d_ui_VideoPlayer_setStyle);
    oluacls_func(L, "setURL", _cocos2d_ui_VideoPlayer_setURL);
    oluacls_func(L, "setUserInputEnabled", _cocos2d_ui_VideoPlayer_setUserInputEnabled);
    oluacls_func(L, "stop", _cocos2d_ui_VideoPlayer_stop);
    oluacls_prop(L, "fileName", _cocos2d_ui_VideoPlayer_getFileName, _cocos2d_ui_VideoPlayer_setFileName);
    oluacls_prop(L, "fullScreenEnabled", _cocos2d_ui_VideoPlayer_isFullScreenEnabled, _cocos2d_ui_VideoPlayer_setFullScreenEnabled);
    oluacls_prop(L, "keepAspectRatioEnabled", _cocos2d_ui_VideoPlayer_isKeepAspectRatioEnabled, _cocos2d_ui_VideoPlayer_setKeepAspectRatioEnabled);
    oluacls_prop(L, "looping", _cocos2d_ui_VideoPlayer_isLooping, _cocos2d_ui_VideoPlayer_setLooping);
    oluacls_prop(L, "playing", _cocos2d_ui_VideoPlayer_isPlaying, nullptr);
    oluacls_prop(L, "url", _cocos2d_ui_VideoPlayer_getURL, _cocos2d_ui_VideoPlayer_setURL);
    oluacls_prop(L, "userInputEnabled", _cocos2d_ui_VideoPlayer_isUserInputEnabled, _cocos2d_ui_VideoPlayer_setUserInputEnabled);

    olua_registerluatype<cocos2d::ui::VideoPlayer>(L, "ccui.VideoPlayer");

    return 1;
}
#endif

static int _cocos2d_ui_AbstractCheckButton___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::ui::AbstractCheckButton *)olua_toobj(L, 1, "ccui.AbstractCheckButton");
    olua_push_cppobj(L, self, "ccui.AbstractCheckButton");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_ui_AbstractCheckButton_getBackDisabledFile(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::AbstractCheckButton *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.AbstractCheckButton");

    // cocos2d::ResourceData getBackDisabledFile()
    cocos2d::ResourceData ret = (cocos2d::ResourceData)self->getBackDisabledFile();
    int num_ret = auto_olua_push_cocos2d_ResourceData(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_AbstractCheckButton_getBackNormalFile(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::AbstractCheckButton *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.AbstractCheckButton");

    // cocos2d::ResourceData getBackNormalFile()
    cocos2d::ResourceData ret = (cocos2d::ResourceData)self->getBackNormalFile();
    int num_ret = auto_olua_push_cocos2d_ResourceData(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_AbstractCheckButton_getBackPressedFile(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::AbstractCheckButton *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.AbstractCheckButton");

    // cocos2d::ResourceData getBackPressedFile()
    cocos2d::ResourceData ret = (cocos2d::ResourceData)self->getBackPressedFile();
    int num_ret = auto_olua_push_cocos2d_ResourceData(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_AbstractCheckButton_getCrossDisabledFile(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::AbstractCheckButton *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.AbstractCheckButton");

    // cocos2d::ResourceData getCrossDisabledFile()
    cocos2d::ResourceData ret = (cocos2d::ResourceData)self->getCrossDisabledFile();
    int num_ret = auto_olua_push_cocos2d_ResourceData(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_AbstractCheckButton_getCrossNormalFile(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::AbstractCheckButton *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.AbstractCheckButton");

    // cocos2d::ResourceData getCrossNormalFile()
    cocos2d::ResourceData ret = (cocos2d::ResourceData)self->getCrossNormalFile();
    int num_ret = auto_olua_push_cocos2d_ResourceData(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_AbstractCheckButton_getRendererBackground(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::AbstractCheckButton *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.AbstractCheckButton");

    // @addref(protectedChildren |) cocos2d::Sprite *getRendererBackground()
    cocos2d::Sprite *ret = (cocos2d::Sprite *)self->getRendererBackground();
    int num_ret = olua_push_cppobj(L, ret, "cc.Sprite");

    // inject code after call
    olua_addref(L, 1, "protectedChildren", -1, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_AbstractCheckButton_getRendererBackgroundDisabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::AbstractCheckButton *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.AbstractCheckButton");

    // @addref(protectedChildren |) cocos2d::Sprite *getRendererBackgroundDisabled()
    cocos2d::Sprite *ret = (cocos2d::Sprite *)self->getRendererBackgroundDisabled();
    int num_ret = olua_push_cppobj(L, ret, "cc.Sprite");

    // inject code after call
    olua_addref(L, 1, "protectedChildren", -1, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_AbstractCheckButton_getRendererBackgroundSelected(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::AbstractCheckButton *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.AbstractCheckButton");

    // @addref(protectedChildren |) cocos2d::Sprite *getRendererBackgroundSelected()
    cocos2d::Sprite *ret = (cocos2d::Sprite *)self->getRendererBackgroundSelected();
    int num_ret = olua_push_cppobj(L, ret, "cc.Sprite");

    // inject code after call
    olua_addref(L, 1, "protectedChildren", -1, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_AbstractCheckButton_getRendererFrontCross(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::AbstractCheckButton *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.AbstractCheckButton");

    // @addref(protectedChildren |) cocos2d::Sprite *getRendererFrontCross()
    cocos2d::Sprite *ret = (cocos2d::Sprite *)self->getRendererFrontCross();
    int num_ret = olua_push_cppobj(L, ret, "cc.Sprite");

    // inject code after call
    olua_addref(L, 1, "protectedChildren", -1, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_AbstractCheckButton_getRendererFrontCrossDisabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::AbstractCheckButton *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.AbstractCheckButton");

    // @addref(protectedChildren |) cocos2d::Sprite *getRendererFrontCrossDisabled()
    cocos2d::Sprite *ret = (cocos2d::Sprite *)self->getRendererFrontCrossDisabled();
    int num_ret = olua_push_cppobj(L, ret, "cc.Sprite");

    // inject code after call
    olua_addref(L, 1, "protectedChildren", -1, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_AbstractCheckButton_getZoomScale(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::AbstractCheckButton *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.AbstractCheckButton");

    // float getZoomScale()
    float ret = (float)self->getZoomScale();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_AbstractCheckButton_init1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::AbstractCheckButton *self = nullptr;
    std::string arg1;       /** backGround */
    std::string arg2;       /** backGroundSelected */
    std::string arg3;       /** cross */
    std::string arg4;       /** backGroundDisabled */
    std::string arg5;       /** frontCrossDisabled */
    lua_Unsigned arg6 = 0;       /** texType */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.AbstractCheckButton");
    olua_check_std_string(L, 2, &arg1);
    olua_check_std_string(L, 3, &arg2);
    olua_check_std_string(L, 4, &arg3);
    olua_check_std_string(L, 5, &arg4);
    olua_check_std_string(L, 6, &arg5);
    olua_check_uint(L, 7, &arg6);

    // bool init(const std::string &backGround, const std::string &backGroundSelected, const std::string &cross, const std::string &backGroundDisabled, const std::string &frontCrossDisabled, @optional cocos2d::ui::Widget::TextureResType texType)
    bool ret = (bool)self->init(arg1, arg2, arg3, arg4, arg5, (cocos2d::ui::Widget::TextureResType)arg6);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_AbstractCheckButton_init2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::AbstractCheckButton *self = nullptr;
    std::string arg1;       /** backGround */
    std::string arg2;       /** backGroundSelected */
    std::string arg3;       /** cross */
    std::string arg4;       /** backGroundDisabled */
    std::string arg5;       /** frontCrossDisabled */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.AbstractCheckButton");
    olua_check_std_string(L, 2, &arg1);
    olua_check_std_string(L, 3, &arg2);
    olua_check_std_string(L, 4, &arg3);
    olua_check_std_string(L, 5, &arg4);
    olua_check_std_string(L, 6, &arg5);

    // bool init(const std::string &backGround, const std::string &backGroundSelected, const std::string &cross, const std::string &backGroundDisabled, const std::string &frontCrossDisabled, @optional cocos2d::ui::Widget::TextureResType texType)
    bool ret = (bool)self->init(arg1, arg2, arg3, arg4, arg5);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_AbstractCheckButton_init(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 5) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_std_string(L, 3)) && (olua_is_std_string(L, 4)) && (olua_is_std_string(L, 5)) && (olua_is_std_string(L, 6))) {
            // bool init(const std::string &backGround, const std::string &backGroundSelected, const std::string &cross, const std::string &backGroundDisabled, const std::string &frontCrossDisabled, @optional cocos2d::ui::Widget::TextureResType texType)
            return _cocos2d_ui_AbstractCheckButton_init2(L);
        // }
    }

    if (num_args == 6) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_std_string(L, 3)) && (olua_is_std_string(L, 4)) && (olua_is_std_string(L, 5)) && (olua_is_std_string(L, 6)) && (olua_is_uint(L, 7))) {
            // bool init(const std::string &backGround, const std::string &backGroundSelected, const std::string &cross, const std::string &backGroundDisabled, const std::string &frontCrossDisabled, @optional cocos2d::ui::Widget::TextureResType texType)
            return _cocos2d_ui_AbstractCheckButton_init1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::AbstractCheckButton::init' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ui_AbstractCheckButton_isSelected(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::AbstractCheckButton *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.AbstractCheckButton");

    // bool isSelected()
    bool ret = (bool)self->isSelected();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_AbstractCheckButton_loadTextureBackGround1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::AbstractCheckButton *self = nullptr;
    std::string arg1;       /** backGround */
    lua_Unsigned arg2 = 0;       /** type */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.AbstractCheckButton");
    olua_check_std_string(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // void loadTextureBackGround(const std::string &backGround, @optional cocos2d::ui::Widget::TextureResType type)
    self->loadTextureBackGround(arg1, (cocos2d::ui::Widget::TextureResType)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_AbstractCheckButton_loadTextureBackGround2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::AbstractCheckButton *self = nullptr;
    std::string arg1;       /** backGround */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.AbstractCheckButton");
    olua_check_std_string(L, 2, &arg1);

    // void loadTextureBackGround(const std::string &backGround, @optional cocos2d::ui::Widget::TextureResType type)
    self->loadTextureBackGround(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_AbstractCheckButton_loadTextureBackGround(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 2))) {
            // void loadTextureBackGround(const std::string &backGround, @optional cocos2d::ui::Widget::TextureResType type)
            return _cocos2d_ui_AbstractCheckButton_loadTextureBackGround2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_uint(L, 3))) {
            // void loadTextureBackGround(const std::string &backGround, @optional cocos2d::ui::Widget::TextureResType type)
            return _cocos2d_ui_AbstractCheckButton_loadTextureBackGround1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::AbstractCheckButton::loadTextureBackGround' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ui_AbstractCheckButton_loadTextureBackGroundDisabled1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::AbstractCheckButton *self = nullptr;
    std::string arg1;       /** backGroundDisabled */
    lua_Unsigned arg2 = 0;       /** texType */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.AbstractCheckButton");
    olua_check_std_string(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // void loadTextureBackGroundDisabled(const std::string &backGroundDisabled, @optional cocos2d::ui::Widget::TextureResType texType)
    self->loadTextureBackGroundDisabled(arg1, (cocos2d::ui::Widget::TextureResType)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_AbstractCheckButton_loadTextureBackGroundDisabled2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::AbstractCheckButton *self = nullptr;
    std::string arg1;       /** backGroundDisabled */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.AbstractCheckButton");
    olua_check_std_string(L, 2, &arg1);

    // void loadTextureBackGroundDisabled(const std::string &backGroundDisabled, @optional cocos2d::ui::Widget::TextureResType texType)
    self->loadTextureBackGroundDisabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_AbstractCheckButton_loadTextureBackGroundDisabled(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 2))) {
            // void loadTextureBackGroundDisabled(const std::string &backGroundDisabled, @optional cocos2d::ui::Widget::TextureResType texType)
            return _cocos2d_ui_AbstractCheckButton_loadTextureBackGroundDisabled2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_uint(L, 3))) {
            // void loadTextureBackGroundDisabled(const std::string &backGroundDisabled, @optional cocos2d::ui::Widget::TextureResType texType)
            return _cocos2d_ui_AbstractCheckButton_loadTextureBackGroundDisabled1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::AbstractCheckButton::loadTextureBackGroundDisabled' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ui_AbstractCheckButton_loadTextureBackGroundSelected1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::AbstractCheckButton *self = nullptr;
    std::string arg1;       /** backGroundSelected */
    lua_Unsigned arg2 = 0;       /** texType */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.AbstractCheckButton");
    olua_check_std_string(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // void loadTextureBackGroundSelected(const std::string &backGroundSelected, @optional cocos2d::ui::Widget::TextureResType texType)
    self->loadTextureBackGroundSelected(arg1, (cocos2d::ui::Widget::TextureResType)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_AbstractCheckButton_loadTextureBackGroundSelected2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::AbstractCheckButton *self = nullptr;
    std::string arg1;       /** backGroundSelected */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.AbstractCheckButton");
    olua_check_std_string(L, 2, &arg1);

    // void loadTextureBackGroundSelected(const std::string &backGroundSelected, @optional cocos2d::ui::Widget::TextureResType texType)
    self->loadTextureBackGroundSelected(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_AbstractCheckButton_loadTextureBackGroundSelected(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 2))) {
            // void loadTextureBackGroundSelected(const std::string &backGroundSelected, @optional cocos2d::ui::Widget::TextureResType texType)
            return _cocos2d_ui_AbstractCheckButton_loadTextureBackGroundSelected2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_uint(L, 3))) {
            // void loadTextureBackGroundSelected(const std::string &backGroundSelected, @optional cocos2d::ui::Widget::TextureResType texType)
            return _cocos2d_ui_AbstractCheckButton_loadTextureBackGroundSelected1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::AbstractCheckButton::loadTextureBackGroundSelected' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ui_AbstractCheckButton_loadTextureFrontCross1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::AbstractCheckButton *self = nullptr;
    std::string arg1;       /** crossTextureName */
    lua_Unsigned arg2 = 0;       /** texType */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.AbstractCheckButton");
    olua_check_std_string(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // void loadTextureFrontCross(const std::string &crossTextureName, @optional cocos2d::ui::Widget::TextureResType texType)
    self->loadTextureFrontCross(arg1, (cocos2d::ui::Widget::TextureResType)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_AbstractCheckButton_loadTextureFrontCross2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::AbstractCheckButton *self = nullptr;
    std::string arg1;       /** crossTextureName */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.AbstractCheckButton");
    olua_check_std_string(L, 2, &arg1);

    // void loadTextureFrontCross(const std::string &crossTextureName, @optional cocos2d::ui::Widget::TextureResType texType)
    self->loadTextureFrontCross(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_AbstractCheckButton_loadTextureFrontCross(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 2))) {
            // void loadTextureFrontCross(const std::string &crossTextureName, @optional cocos2d::ui::Widget::TextureResType texType)
            return _cocos2d_ui_AbstractCheckButton_loadTextureFrontCross2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_uint(L, 3))) {
            // void loadTextureFrontCross(const std::string &crossTextureName, @optional cocos2d::ui::Widget::TextureResType texType)
            return _cocos2d_ui_AbstractCheckButton_loadTextureFrontCross1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::AbstractCheckButton::loadTextureFrontCross' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ui_AbstractCheckButton_loadTextureFrontCrossDisabled1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::AbstractCheckButton *self = nullptr;
    std::string arg1;       /** frontCrossDisabled */
    lua_Unsigned arg2 = 0;       /** texType */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.AbstractCheckButton");
    olua_check_std_string(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // void loadTextureFrontCrossDisabled(const std::string &frontCrossDisabled, @optional cocos2d::ui::Widget::TextureResType texType)
    self->loadTextureFrontCrossDisabled(arg1, (cocos2d::ui::Widget::TextureResType)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_AbstractCheckButton_loadTextureFrontCrossDisabled2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::AbstractCheckButton *self = nullptr;
    std::string arg1;       /** frontCrossDisabled */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.AbstractCheckButton");
    olua_check_std_string(L, 2, &arg1);

    // void loadTextureFrontCrossDisabled(const std::string &frontCrossDisabled, @optional cocos2d::ui::Widget::TextureResType texType)
    self->loadTextureFrontCrossDisabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_AbstractCheckButton_loadTextureFrontCrossDisabled(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 2))) {
            // void loadTextureFrontCrossDisabled(const std::string &frontCrossDisabled, @optional cocos2d::ui::Widget::TextureResType texType)
            return _cocos2d_ui_AbstractCheckButton_loadTextureFrontCrossDisabled2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_uint(L, 3))) {
            // void loadTextureFrontCrossDisabled(const std::string &frontCrossDisabled, @optional cocos2d::ui::Widget::TextureResType texType)
            return _cocos2d_ui_AbstractCheckButton_loadTextureFrontCrossDisabled1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::AbstractCheckButton::loadTextureFrontCrossDisabled' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ui_AbstractCheckButton_loadTextures1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::AbstractCheckButton *self = nullptr;
    std::string arg1;       /** background */
    std::string arg2;       /** backgroundSelected */
    std::string arg3;       /** cross */
    std::string arg4;       /** backgroundDisabled */
    std::string arg5;       /** frontCrossDisabled */
    lua_Unsigned arg6 = 0;       /** texType */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.AbstractCheckButton");
    olua_check_std_string(L, 2, &arg1);
    olua_check_std_string(L, 3, &arg2);
    olua_check_std_string(L, 4, &arg3);
    olua_check_std_string(L, 5, &arg4);
    olua_check_std_string(L, 6, &arg5);
    olua_check_uint(L, 7, &arg6);

    // void loadTextures(const std::string &background, const std::string &backgroundSelected, const std::string &cross, const std::string &backgroundDisabled, const std::string &frontCrossDisabled, @optional cocos2d::ui::Widget::TextureResType texType)
    self->loadTextures(arg1, arg2, arg3, arg4, arg5, (cocos2d::ui::Widget::TextureResType)arg6);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_AbstractCheckButton_loadTextures2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::AbstractCheckButton *self = nullptr;
    std::string arg1;       /** background */
    std::string arg2;       /** backgroundSelected */
    std::string arg3;       /** cross */
    std::string arg4;       /** backgroundDisabled */
    std::string arg5;       /** frontCrossDisabled */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.AbstractCheckButton");
    olua_check_std_string(L, 2, &arg1);
    olua_check_std_string(L, 3, &arg2);
    olua_check_std_string(L, 4, &arg3);
    olua_check_std_string(L, 5, &arg4);
    olua_check_std_string(L, 6, &arg5);

    // void loadTextures(const std::string &background, const std::string &backgroundSelected, const std::string &cross, const std::string &backgroundDisabled, const std::string &frontCrossDisabled, @optional cocos2d::ui::Widget::TextureResType texType)
    self->loadTextures(arg1, arg2, arg3, arg4, arg5);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_AbstractCheckButton_loadTextures(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 5) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_std_string(L, 3)) && (olua_is_std_string(L, 4)) && (olua_is_std_string(L, 5)) && (olua_is_std_string(L, 6))) {
            // void loadTextures(const std::string &background, const std::string &backgroundSelected, const std::string &cross, const std::string &backgroundDisabled, const std::string &frontCrossDisabled, @optional cocos2d::ui::Widget::TextureResType texType)
            return _cocos2d_ui_AbstractCheckButton_loadTextures2(L);
        // }
    }

    if (num_args == 6) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_std_string(L, 3)) && (olua_is_std_string(L, 4)) && (olua_is_std_string(L, 5)) && (olua_is_std_string(L, 6)) && (olua_is_uint(L, 7))) {
            // void loadTextures(const std::string &background, const std::string &backgroundSelected, const std::string &cross, const std::string &backgroundDisabled, const std::string &frontCrossDisabled, @optional cocos2d::ui::Widget::TextureResType texType)
            return _cocos2d_ui_AbstractCheckButton_loadTextures1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::AbstractCheckButton::loadTextures' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ui_AbstractCheckButton_setSelected(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::AbstractCheckButton *self = nullptr;
    bool arg1 = false;       /** selected */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.AbstractCheckButton");
    olua_check_bool(L, 2, &arg1);

    // void setSelected(bool selected)
    self->setSelected(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_AbstractCheckButton_setZoomScale(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::AbstractCheckButton *self = nullptr;
    lua_Number arg1 = 0;       /** scale */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.AbstractCheckButton");
    olua_check_number(L, 2, &arg1);

    // void setZoomScale(float scale)
    self->setZoomScale((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_ui_AbstractCheckButton(lua_State *L)
{
    oluacls_class(L, "ccui.AbstractCheckButton", "ccui.Widget");
    oluacls_func(L, "__move", _cocos2d_ui_AbstractCheckButton___move);
    oluacls_func(L, "getBackDisabledFile", _cocos2d_ui_AbstractCheckButton_getBackDisabledFile);
    oluacls_func(L, "getBackNormalFile", _cocos2d_ui_AbstractCheckButton_getBackNormalFile);
    oluacls_func(L, "getBackPressedFile", _cocos2d_ui_AbstractCheckButton_getBackPressedFile);
    oluacls_func(L, "getCrossDisabledFile", _cocos2d_ui_AbstractCheckButton_getCrossDisabledFile);
    oluacls_func(L, "getCrossNormalFile", _cocos2d_ui_AbstractCheckButton_getCrossNormalFile);
    oluacls_func(L, "getRendererBackground", _cocos2d_ui_AbstractCheckButton_getRendererBackground);
    oluacls_func(L, "getRendererBackgroundDisabled", _cocos2d_ui_AbstractCheckButton_getRendererBackgroundDisabled);
    oluacls_func(L, "getRendererBackgroundSelected", _cocos2d_ui_AbstractCheckButton_getRendererBackgroundSelected);
    oluacls_func(L, "getRendererFrontCross", _cocos2d_ui_AbstractCheckButton_getRendererFrontCross);
    oluacls_func(L, "getRendererFrontCrossDisabled", _cocos2d_ui_AbstractCheckButton_getRendererFrontCrossDisabled);
    oluacls_func(L, "getZoomScale", _cocos2d_ui_AbstractCheckButton_getZoomScale);
    oluacls_func(L, "init", _cocos2d_ui_AbstractCheckButton_init);
    oluacls_func(L, "isSelected", _cocos2d_ui_AbstractCheckButton_isSelected);
    oluacls_func(L, "loadTextureBackGround", _cocos2d_ui_AbstractCheckButton_loadTextureBackGround);
    oluacls_func(L, "loadTextureBackGroundDisabled", _cocos2d_ui_AbstractCheckButton_loadTextureBackGroundDisabled);
    oluacls_func(L, "loadTextureBackGroundSelected", _cocos2d_ui_AbstractCheckButton_loadTextureBackGroundSelected);
    oluacls_func(L, "loadTextureFrontCross", _cocos2d_ui_AbstractCheckButton_loadTextureFrontCross);
    oluacls_func(L, "loadTextureFrontCrossDisabled", _cocos2d_ui_AbstractCheckButton_loadTextureFrontCrossDisabled);
    oluacls_func(L, "loadTextures", _cocos2d_ui_AbstractCheckButton_loadTextures);
    oluacls_func(L, "setSelected", _cocos2d_ui_AbstractCheckButton_setSelected);
    oluacls_func(L, "setZoomScale", _cocos2d_ui_AbstractCheckButton_setZoomScale);
    oluacls_prop(L, "backDisabledFile", _cocos2d_ui_AbstractCheckButton_getBackDisabledFile, nullptr);
    oluacls_prop(L, "backNormalFile", _cocos2d_ui_AbstractCheckButton_getBackNormalFile, nullptr);
    oluacls_prop(L, "backPressedFile", _cocos2d_ui_AbstractCheckButton_getBackPressedFile, nullptr);
    oluacls_prop(L, "crossDisabledFile", _cocos2d_ui_AbstractCheckButton_getCrossDisabledFile, nullptr);
    oluacls_prop(L, "crossNormalFile", _cocos2d_ui_AbstractCheckButton_getCrossNormalFile, nullptr);
    oluacls_prop(L, "rendererBackground", _cocos2d_ui_AbstractCheckButton_getRendererBackground, nullptr);
    oluacls_prop(L, "rendererBackgroundDisabled", _cocos2d_ui_AbstractCheckButton_getRendererBackgroundDisabled, nullptr);
    oluacls_prop(L, "rendererBackgroundSelected", _cocos2d_ui_AbstractCheckButton_getRendererBackgroundSelected, nullptr);
    oluacls_prop(L, "rendererFrontCross", _cocos2d_ui_AbstractCheckButton_getRendererFrontCross, nullptr);
    oluacls_prop(L, "rendererFrontCrossDisabled", _cocos2d_ui_AbstractCheckButton_getRendererFrontCrossDisabled, nullptr);
    oluacls_prop(L, "selected", _cocos2d_ui_AbstractCheckButton_isSelected, _cocos2d_ui_AbstractCheckButton_setSelected);
    oluacls_prop(L, "zoomScale", _cocos2d_ui_AbstractCheckButton_getZoomScale, _cocos2d_ui_AbstractCheckButton_setZoomScale);

    olua_registerluatype<cocos2d::ui::AbstractCheckButton>(L, "ccui.AbstractCheckButton");

    return 1;
}

static int luaopen_cocos2d_ui_TabHeader_EventType(lua_State *L)
{
    oluacls_class(L, "ccui.TabHeader.EventType", nullptr);
    oluacls_const_integer(L, "SELECTED", (lua_Integer)cocos2d::ui::TabHeader::EventType::SELECTED);
    oluacls_const_integer(L, "UNSELECTED", (lua_Integer)cocos2d::ui::TabHeader::EventType::UNSELECTED);

    olua_registerluatype<cocos2d::ui::TabHeader::EventType>(L, "ccui.TabHeader.EventType");

    return 1;
}

static int _cocos2d_ui_TabHeader___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::ui::TabHeader *)olua_toobj(L, 1, "ccui.TabHeader");
    olua_push_cppobj(L, self, "ccui.TabHeader");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_ui_TabHeader_create1(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::ui::TabHeader *create()
    cocos2d::ui::TabHeader *ret = (cocos2d::ui::TabHeader *)cocos2d::ui::TabHeader::create();
    int num_ret = olua_push_cppobj(L, ret, "ccui.TabHeader");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_TabHeader_create2(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** titleStr */
    std::string arg2;       /** backGround */
    std::string arg3;       /** cross */
    lua_Unsigned arg4 = 0;       /** texType */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);
    olua_check_std_string(L, 3, &arg3);
    olua_check_uint(L, 4, &arg4);

    // static cocos2d::ui::TabHeader *create(const std::string &titleStr, const std::string &backGround, const std::string &cross, @optional cocos2d::ui::Widget::TextureResType texType)
    cocos2d::ui::TabHeader *ret = (cocos2d::ui::TabHeader *)cocos2d::ui::TabHeader::create(arg1, arg2, arg3, (cocos2d::ui::Widget::TextureResType)arg4);
    int num_ret = olua_push_cppobj(L, ret, "ccui.TabHeader");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_TabHeader_create3(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** titleStr */
    std::string arg2;       /** backGround */
    std::string arg3;       /** backGroundSelected */
    std::string arg4;       /** cross */
    std::string arg5;       /** backGroundDisabled */
    std::string arg6;       /** frontCrossDisabled */
    lua_Unsigned arg7 = 0;       /** texType */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);
    olua_check_std_string(L, 3, &arg3);
    olua_check_std_string(L, 4, &arg4);
    olua_check_std_string(L, 5, &arg5);
    olua_check_std_string(L, 6, &arg6);
    olua_check_uint(L, 7, &arg7);

    // static cocos2d::ui::TabHeader *create(const std::string &titleStr, const std::string &backGround, const std::string &backGroundSelected, const std::string &cross, const std::string &backGroundDisabled, const std::string &frontCrossDisabled, @optional cocos2d::ui::Widget::TextureResType texType)
    cocos2d::ui::TabHeader *ret = (cocos2d::ui::TabHeader *)cocos2d::ui::TabHeader::create(arg1, arg2, arg3, arg4, arg5, arg6, (cocos2d::ui::Widget::TextureResType)arg7);
    int num_ret = olua_push_cppobj(L, ret, "ccui.TabHeader");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_TabHeader_create4(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** titleStr */
    std::string arg2;       /** backGround */
    std::string arg3;       /** cross */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);
    olua_check_std_string(L, 3, &arg3);

    // static cocos2d::ui::TabHeader *create(const std::string &titleStr, const std::string &backGround, const std::string &cross, @optional cocos2d::ui::Widget::TextureResType texType)
    cocos2d::ui::TabHeader *ret = (cocos2d::ui::TabHeader *)cocos2d::ui::TabHeader::create(arg1, arg2, arg3);
    int num_ret = olua_push_cppobj(L, ret, "ccui.TabHeader");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_TabHeader_create5(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** titleStr */
    std::string arg2;       /** backGround */
    std::string arg3;       /** backGroundSelected */
    std::string arg4;       /** cross */
    std::string arg5;       /** backGroundDisabled */
    std::string arg6;       /** frontCrossDisabled */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);
    olua_check_std_string(L, 3, &arg3);
    olua_check_std_string(L, 4, &arg4);
    olua_check_std_string(L, 5, &arg5);
    olua_check_std_string(L, 6, &arg6);

    // static cocos2d::ui::TabHeader *create(const std::string &titleStr, const std::string &backGround, const std::string &backGroundSelected, const std::string &cross, const std::string &backGroundDisabled, const std::string &frontCrossDisabled, @optional cocos2d::ui::Widget::TextureResType texType)
    cocos2d::ui::TabHeader *ret = (cocos2d::ui::TabHeader *)cocos2d::ui::TabHeader::create(arg1, arg2, arg3, arg4, arg5, arg6);
    int num_ret = olua_push_cppobj(L, ret, "ccui.TabHeader");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_TabHeader_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // static cocos2d::ui::TabHeader *create()
        return _cocos2d_ui_TabHeader_create1(L);
    }

    if (num_args == 3) {
        // if ((olua_is_std_string(L, 1)) && (olua_is_std_string(L, 2)) && (olua_is_std_string(L, 3))) {
            // static cocos2d::ui::TabHeader *create(const std::string &titleStr, const std::string &backGround, const std::string &cross, @optional cocos2d::ui::Widget::TextureResType texType)
            return _cocos2d_ui_TabHeader_create4(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_std_string(L, 1)) && (olua_is_std_string(L, 2)) && (olua_is_std_string(L, 3)) && (olua_is_uint(L, 4))) {
            // static cocos2d::ui::TabHeader *create(const std::string &titleStr, const std::string &backGround, const std::string &cross, @optional cocos2d::ui::Widget::TextureResType texType)
            return _cocos2d_ui_TabHeader_create2(L);
        // }
    }

    if (num_args == 6) {
        // if ((olua_is_std_string(L, 1)) && (olua_is_std_string(L, 2)) && (olua_is_std_string(L, 3)) && (olua_is_std_string(L, 4)) && (olua_is_std_string(L, 5)) && (olua_is_std_string(L, 6))) {
            // static cocos2d::ui::TabHeader *create(const std::string &titleStr, const std::string &backGround, const std::string &backGroundSelected, const std::string &cross, const std::string &backGroundDisabled, const std::string &frontCrossDisabled, @optional cocos2d::ui::Widget::TextureResType texType)
            return _cocos2d_ui_TabHeader_create5(L);
        // }
    }

    if (num_args == 7) {
        // if ((olua_is_std_string(L, 1)) && (olua_is_std_string(L, 2)) && (olua_is_std_string(L, 3)) && (olua_is_std_string(L, 4)) && (olua_is_std_string(L, 5)) && (olua_is_std_string(L, 6)) && (olua_is_uint(L, 7))) {
            // static cocos2d::ui::TabHeader *create(const std::string &titleStr, const std::string &backGround, const std::string &backGroundSelected, const std::string &cross, const std::string &backGroundDisabled, const std::string &frontCrossDisabled, @optional cocos2d::ui::Widget::TextureResType texType)
            return _cocos2d_ui_TabHeader_create3(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::TabHeader::create' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ui_TabHeader_getIndexInTabControl(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TabHeader *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TabHeader");

    // int getIndexInTabControl()
    int ret = (int)self->getIndexInTabControl();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_TabHeader_getTitleColor(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TabHeader *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TabHeader");

    // const cocos2d::Color4B &getTitleColor()
    const cocos2d::Color4B &ret = (const cocos2d::Color4B &)self->getTitleColor();
    int num_ret = manual_olua_push_cocos2d_Color4B(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_TabHeader_getTitleFontName(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TabHeader *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TabHeader");

    // std::string getTitleFontName()
    std::string ret = (std::string)self->getTitleFontName();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_TabHeader_getTitleFontSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TabHeader *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TabHeader");

    // float getTitleFontSize()
    float ret = (float)self->getTitleFontSize();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_TabHeader_getTitleRenderer(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TabHeader *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TabHeader");

    // @addref(protectedChildren |) cocos2d::Label *getTitleRenderer()
    cocos2d::Label *ret = (cocos2d::Label *)self->getTitleRenderer();
    int num_ret = olua_push_cppobj(L, ret, "cc.Label");

    // inject code after call
    olua_addref(L, 1, "protectedChildren", -1, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_TabHeader_getTitleText(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TabHeader *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TabHeader");

    // std::string getTitleText()
    std::string ret = (std::string)self->getTitleText();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_TabHeader_setTitleColor(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TabHeader *self = nullptr;
    cocos2d::Color4B arg1;       /** color */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TabHeader");
    manual_olua_check_cocos2d_Color4B(L, 2, &arg1);

    // void setTitleColor(const cocos2d::Color4B &color)
    self->setTitleColor(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_TabHeader_setTitleFontName(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TabHeader *self = nullptr;
    std::string arg1;       /** fontName */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TabHeader");
    olua_check_std_string(L, 2, &arg1);

    // void setTitleFontName(const std::string &fontName)
    self->setTitleFontName(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_TabHeader_setTitleFontSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TabHeader *self = nullptr;
    lua_Number arg1 = 0;       /** size */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TabHeader");
    olua_check_number(L, 2, &arg1);

    // void setTitleFontSize(float size)
    self->setTitleFontSize((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_TabHeader_setTitleText(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TabHeader *self = nullptr;
    std::string arg1;       /** text */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TabHeader");
    olua_check_std_string(L, 2, &arg1);

    // void setTitleText(const std::string &text)
    self->setTitleText(arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_ui_TabHeader(lua_State *L)
{
    oluacls_class(L, "ccui.TabHeader", "ccui.AbstractCheckButton");
    oluacls_func(L, "__move", _cocos2d_ui_TabHeader___move);
    oluacls_func(L, "create", _cocos2d_ui_TabHeader_create);
    oluacls_func(L, "getIndexInTabControl", _cocos2d_ui_TabHeader_getIndexInTabControl);
    oluacls_func(L, "getTitleColor", _cocos2d_ui_TabHeader_getTitleColor);
    oluacls_func(L, "getTitleFontName", _cocos2d_ui_TabHeader_getTitleFontName);
    oluacls_func(L, "getTitleFontSize", _cocos2d_ui_TabHeader_getTitleFontSize);
    oluacls_func(L, "getTitleRenderer", _cocos2d_ui_TabHeader_getTitleRenderer);
    oluacls_func(L, "getTitleText", _cocos2d_ui_TabHeader_getTitleText);
    oluacls_func(L, "setTitleColor", _cocos2d_ui_TabHeader_setTitleColor);
    oluacls_func(L, "setTitleFontName", _cocos2d_ui_TabHeader_setTitleFontName);
    oluacls_func(L, "setTitleFontSize", _cocos2d_ui_TabHeader_setTitleFontSize);
    oluacls_func(L, "setTitleText", _cocos2d_ui_TabHeader_setTitleText);
    oluacls_prop(L, "indexInTabControl", _cocos2d_ui_TabHeader_getIndexInTabControl, nullptr);
    oluacls_prop(L, "titleColor", _cocos2d_ui_TabHeader_getTitleColor, _cocos2d_ui_TabHeader_setTitleColor);
    oluacls_prop(L, "titleFontName", _cocos2d_ui_TabHeader_getTitleFontName, _cocos2d_ui_TabHeader_setTitleFontName);
    oluacls_prop(L, "titleFontSize", _cocos2d_ui_TabHeader_getTitleFontSize, _cocos2d_ui_TabHeader_setTitleFontSize);
    oluacls_prop(L, "titleRenderer", _cocos2d_ui_TabHeader_getTitleRenderer, nullptr);
    oluacls_prop(L, "titleText", _cocos2d_ui_TabHeader_getTitleText, _cocos2d_ui_TabHeader_setTitleText);

    olua_registerluatype<cocos2d::ui::TabHeader>(L, "ccui.TabHeader");

    return 1;
}

static int luaopen_cocos2d_ui_TabControl_Dock(lua_State *L)
{
    oluacls_class(L, "ccui.TabControl.Dock", nullptr);
    oluacls_const_integer(L, "BOTTOM", (lua_Integer)cocos2d::ui::TabControl::Dock::BOTTOM);
    oluacls_const_integer(L, "LEFT", (lua_Integer)cocos2d::ui::TabControl::Dock::LEFT);
    oluacls_const_integer(L, "RIGHT", (lua_Integer)cocos2d::ui::TabControl::Dock::RIGHT);
    oluacls_const_integer(L, "TOP", (lua_Integer)cocos2d::ui::TabControl::Dock::TOP);

    olua_registerluatype<cocos2d::ui::TabControl::Dock>(L, "ccui.TabControl.Dock");

    return 1;
}

static int luaopen_cocos2d_ui_TabControl_EventType(lua_State *L)
{
    oluacls_class(L, "ccui.TabControl.EventType", nullptr);
    oluacls_const_integer(L, "SELECT_CHANGED", (lua_Integer)cocos2d::ui::TabControl::EventType::SELECT_CHANGED);

    olua_registerluatype<cocos2d::ui::TabControl::EventType>(L, "ccui.TabControl.EventType");

    return 1;
}

static int _cocos2d_ui_TabControl___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::ui::TabControl *)olua_toobj(L, 1, "ccui.TabControl");
    olua_push_cppobj(L, self, "ccui.TabControl");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_ui_TabControl_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::ui::TabControl *create()
    cocos2d::ui::TabControl *ret = (cocos2d::ui::TabControl *)cocos2d::ui::TabControl::create();
    int num_ret = olua_push_cppobj(L, ret, "ccui.TabControl");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_TabControl_getHeaderDockPlace(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TabControl *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TabControl");

    // TabControl::Dock getHeaderDockPlace()
    cocos2d::ui::TabControl::Dock ret = (cocos2d::ui::TabControl::Dock)self->getHeaderDockPlace();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_TabControl_getHeaderHeight(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TabControl *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TabControl");

    // int getHeaderHeight()
    int ret = (int)self->getHeaderHeight();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_TabControl_getHeaderSelectedZoom(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TabControl *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TabControl");

    // float getHeaderSelectedZoom()
    float ret = (float)self->getHeaderSelectedZoom();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_TabControl_getHeaderWidth(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TabControl *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TabControl");

    // float getHeaderWidth()
    float ret = (float)self->getHeaderWidth();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_TabControl_getSelectedTabIndex(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TabControl *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TabControl");

    // int getSelectedTabIndex()
    int ret = (int)self->getSelectedTabIndex();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_TabControl_getTabContainer(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TabControl *self = nullptr;
    lua_Integer arg1 = 0;       /** index */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TabControl");
    olua_check_int(L, 2, &arg1);

    // @addref(protectedChildren |) cocos2d::ui::Layout *getTabContainer(int index)
    cocos2d::ui::Layout *ret = (cocos2d::ui::Layout *)self->getTabContainer((int)arg1);
    int num_ret = olua_push_cppobj(L, ret, "ccui.Layout");

    // inject code after call
    olua_addref(L, 1, "protectedChildren", -1, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_TabControl_getTabCount(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TabControl *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TabControl");

    // size_t getTabCount()
    size_t ret = (size_t)self->getTabCount();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_TabControl_getTabHeader(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TabControl *self = nullptr;
    lua_Integer arg1 = 0;       /** index */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TabControl");
    olua_check_int(L, 2, &arg1);

    // @addref(protectedChildren |) cocos2d::ui::TabHeader *getTabHeader(int index)
    cocos2d::ui::TabHeader *ret = (cocos2d::ui::TabHeader *)self->getTabHeader((int)arg1);
    int num_ret = olua_push_cppobj(L, ret, "ccui.TabHeader");

    // inject code after call
    olua_addref(L, 1, "protectedChildren", -1, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_TabControl_ignoreHeadersTextureSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TabControl *self = nullptr;
    bool arg1 = false;       /** ignore */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TabControl");
    olua_check_bool(L, 2, &arg1);

    // void ignoreHeadersTextureSize(bool ignore)
    self->ignoreHeadersTextureSize(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_TabControl_indexOfTabHeader(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TabControl *self = nullptr;
    cocos2d::ui::TabHeader *arg1 = nullptr;       /** tabCell */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TabControl");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccui.TabHeader");

    // int indexOfTabHeader(const cocos2d::ui::TabHeader *tabCell)
    int ret = (int)self->indexOfTabHeader(arg1);
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_TabControl_insertTab(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TabControl *self = nullptr;
    lua_Integer arg1 = 0;       /** index */
    cocos2d::ui::TabHeader *arg2 = nullptr;       /** header */
    cocos2d::ui::Layout *arg3 = nullptr;       /** container */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TabControl");
    olua_check_int(L, 2, &arg1);
    olua_check_cppobj(L, 3, (void **)&arg2, "ccui.TabHeader");
    olua_check_cppobj(L, 4, (void **)&arg3, "ccui.Layout");

    // void insertTab(int index, @addref(protectedChildren |) cocos2d::ui::TabHeader *header, @addref(protectedChildren |) cocos2d::ui::Layout *container)
    self->insertTab((int)arg1, arg2, arg3);

    // inject code after call
    olua_addref(L, 1, "protectedChildren", 3, OLUA_MODE_MULTIPLE);
    olua_addref(L, 1, "protectedChildren", 4, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_TabControl_isIgnoreHeadersTextureSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TabControl *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TabControl");

    // bool isIgnoreHeadersTextureSize()
    bool ret = (bool)self->isIgnoreHeadersTextureSize();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_TabControl_removeTab(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TabControl *self = nullptr;
    lua_Integer arg1 = 0;       /** index */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TabControl");
    olua_check_int(L, 2, &arg1);

    // inject code before call
    olua_startcmpdelref(L, 1, "protectedChildren");

    // @delref(protectedChildren ~) void removeTab(int index)
    self->removeTab((int)arg1);

    // inject code after call
    olua_endcmpdelref(L, 1, "protectedChildren");

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_TabControl_setHeaderDockPlace(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TabControl *self = nullptr;
    lua_Unsigned arg1 = 0;       /** dockPlace */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TabControl");
    olua_check_uint(L, 2, &arg1);

    // void setHeaderDockPlace(TabControl::Dock dockPlace)
    self->setHeaderDockPlace((cocos2d::ui::TabControl::Dock)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_TabControl_setHeaderHeight(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TabControl *self = nullptr;
    lua_Number arg1 = 0;       /** headerHeight */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TabControl");
    olua_check_number(L, 2, &arg1);

    // void setHeaderHeight(float headerHeight)
    self->setHeaderHeight((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_TabControl_setHeaderSelectedZoom(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TabControl *self = nullptr;
    lua_Number arg1 = 0;       /** zoom */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TabControl");
    olua_check_number(L, 2, &arg1);

    // void setHeaderSelectedZoom(float zoom)
    self->setHeaderSelectedZoom((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_TabControl_setHeaderWidth(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TabControl *self = nullptr;
    lua_Number arg1 = 0;       /** headerWidth */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TabControl");
    olua_check_number(L, 2, &arg1);

    // void setHeaderWidth(float headerWidth)
    self->setHeaderWidth((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_TabControl_setSelectTab1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TabControl *self = nullptr;
    lua_Integer arg1 = 0;       /** index */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TabControl");
    olua_check_int(L, 2, &arg1);

    // void setSelectTab(int index)
    self->setSelectTab((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_TabControl_setSelectTab2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TabControl *self = nullptr;
    cocos2d::ui::TabHeader *arg1 = nullptr;       /** tabHeader */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TabControl");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccui.TabHeader");

    // void setSelectTab(cocos2d::ui::TabHeader *tabHeader)
    self->setSelectTab(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_TabControl_setSelectTab(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        if ((olua_is_int(L, 2))) {
            // void setSelectTab(int index)
            return _cocos2d_ui_TabControl_setSelectTab1(L);
        }

        // if ((olua_is_cppobj(L, 2, "ccui.TabHeader"))) {
            // void setSelectTab(cocos2d::ui::TabHeader *tabHeader)
            return _cocos2d_ui_TabControl_setSelectTab2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::TabControl::setSelectTab' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ui_TabControl_setTabChangedEventListener(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TabControl *self = nullptr;
    std::function<void(int, cocos2d::ui::TabControl::EventType)> arg1;       /** callback */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TabControl");

    if (olua_is_std_function(L, 2)) {
        void *callback_store_obj = (void *)self;
        std::string tag = "tabChangedEventListener";
        std::string func = olua_setcallback(L, callback_store_obj, tag.c_str(), 2, OLUA_TAG_REPLACE);
        lua_State *MT = olua_mainthread();
        arg1 = [callback_store_obj, func, MT](int arg1, cocos2d::ui::TabControl::EventType arg2) {
            lua_State *L = olua_mainthread();

            if (MT == L) {
                int top = lua_gettop(L);
                olua_push_int(L, (lua_Integer)arg1);
                olua_push_uint(L, (lua_Unsigned)arg2);

                olua_callback(L, callback_store_obj, func.c_str(), 2);

                lua_settop(L, top);
            }
        };
    } else {
        void *callback_store_obj = (void *)self;
        std::string tag = "tabChangedEventListener";
        olua_removecallback(L, callback_store_obj, tag.c_str(), OLUA_TAG_SUBEQUAL);
        arg1 = nullptr;
    }

    // void setTabChangedEventListener(@nullable const std::function<void(int tabIndex, EventType)>& callback)
    self->setTabChangedEventListener(arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_ui_TabControl(lua_State *L)
{
    oluacls_class(L, "ccui.TabControl", "ccui.Widget");
    oluacls_func(L, "__move", _cocos2d_ui_TabControl___move);
    oluacls_func(L, "create", _cocos2d_ui_TabControl_create);
    oluacls_func(L, "getHeaderDockPlace", _cocos2d_ui_TabControl_getHeaderDockPlace);
    oluacls_func(L, "getHeaderHeight", _cocos2d_ui_TabControl_getHeaderHeight);
    oluacls_func(L, "getHeaderSelectedZoom", _cocos2d_ui_TabControl_getHeaderSelectedZoom);
    oluacls_func(L, "getHeaderWidth", _cocos2d_ui_TabControl_getHeaderWidth);
    oluacls_func(L, "getSelectedTabIndex", _cocos2d_ui_TabControl_getSelectedTabIndex);
    oluacls_func(L, "getTabContainer", _cocos2d_ui_TabControl_getTabContainer);
    oluacls_func(L, "getTabCount", _cocos2d_ui_TabControl_getTabCount);
    oluacls_func(L, "getTabHeader", _cocos2d_ui_TabControl_getTabHeader);
    oluacls_func(L, "ignoreHeadersTextureSize", _cocos2d_ui_TabControl_ignoreHeadersTextureSize);
    oluacls_func(L, "indexOfTabHeader", _cocos2d_ui_TabControl_indexOfTabHeader);
    oluacls_func(L, "insertTab", _cocos2d_ui_TabControl_insertTab);
    oluacls_func(L, "isIgnoreHeadersTextureSize", _cocos2d_ui_TabControl_isIgnoreHeadersTextureSize);
    oluacls_func(L, "removeTab", _cocos2d_ui_TabControl_removeTab);
    oluacls_func(L, "setHeaderDockPlace", _cocos2d_ui_TabControl_setHeaderDockPlace);
    oluacls_func(L, "setHeaderHeight", _cocos2d_ui_TabControl_setHeaderHeight);
    oluacls_func(L, "setHeaderSelectedZoom", _cocos2d_ui_TabControl_setHeaderSelectedZoom);
    oluacls_func(L, "setHeaderWidth", _cocos2d_ui_TabControl_setHeaderWidth);
    oluacls_func(L, "setSelectTab", _cocos2d_ui_TabControl_setSelectTab);
    oluacls_func(L, "setTabChangedEventListener", _cocos2d_ui_TabControl_setTabChangedEventListener);
    oluacls_prop(L, "headerDockPlace", _cocos2d_ui_TabControl_getHeaderDockPlace, _cocos2d_ui_TabControl_setHeaderDockPlace);
    oluacls_prop(L, "headerHeight", _cocos2d_ui_TabControl_getHeaderHeight, _cocos2d_ui_TabControl_setHeaderHeight);
    oluacls_prop(L, "headerSelectedZoom", _cocos2d_ui_TabControl_getHeaderSelectedZoom, _cocos2d_ui_TabControl_setHeaderSelectedZoom);
    oluacls_prop(L, "headerWidth", _cocos2d_ui_TabControl_getHeaderWidth, _cocos2d_ui_TabControl_setHeaderWidth);
    oluacls_prop(L, "ignoreHeadersTextureSize", _cocos2d_ui_TabControl_isIgnoreHeadersTextureSize, nullptr);
    oluacls_prop(L, "selectedTabIndex", _cocos2d_ui_TabControl_getSelectedTabIndex, nullptr);
    oluacls_prop(L, "tabCount", _cocos2d_ui_TabControl_getTabCount, nullptr);

    olua_registerluatype<cocos2d::ui::TabControl>(L, "ccui.TabControl");

    return 1;
}

static int luaopen_cocos2d_ui_ScrollView_Direction(lua_State *L)
{
    oluacls_class(L, "ccui.ScrollView.Direction", nullptr);
    oluacls_const_integer(L, "BOTH", (lua_Integer)cocos2d::ui::ScrollView::Direction::BOTH);
    oluacls_const_integer(L, "HORIZONTAL", (lua_Integer)cocos2d::ui::ScrollView::Direction::HORIZONTAL);
    oluacls_const_integer(L, "NONE", (lua_Integer)cocos2d::ui::ScrollView::Direction::NONE);
    oluacls_const_integer(L, "VERTICAL", (lua_Integer)cocos2d::ui::ScrollView::Direction::VERTICAL);

    olua_registerluatype<cocos2d::ui::ScrollView::Direction>(L, "ccui.ScrollView.Direction");

    return 1;
}

static int luaopen_cocos2d_ui_ScrollView_EventType(lua_State *L)
{
    oluacls_class(L, "ccui.ScrollView.EventType", nullptr);
    oluacls_const_integer(L, "AUTOSCROLL_ENDED", (lua_Integer)cocos2d::ui::ScrollView::EventType::AUTOSCROLL_ENDED);
    oluacls_const_integer(L, "BOUNCE_BOTTOM", (lua_Integer)cocos2d::ui::ScrollView::EventType::BOUNCE_BOTTOM);
    oluacls_const_integer(L, "BOUNCE_LEFT", (lua_Integer)cocos2d::ui::ScrollView::EventType::BOUNCE_LEFT);
    oluacls_const_integer(L, "BOUNCE_RIGHT", (lua_Integer)cocos2d::ui::ScrollView::EventType::BOUNCE_RIGHT);
    oluacls_const_integer(L, "BOUNCE_TOP", (lua_Integer)cocos2d::ui::ScrollView::EventType::BOUNCE_TOP);
    oluacls_const_integer(L, "CONTAINER_MOVED", (lua_Integer)cocos2d::ui::ScrollView::EventType::CONTAINER_MOVED);
    oluacls_const_integer(L, "SCROLLING", (lua_Integer)cocos2d::ui::ScrollView::EventType::SCROLLING);
    oluacls_const_integer(L, "SCROLLING_BEGAN", (lua_Integer)cocos2d::ui::ScrollView::EventType::SCROLLING_BEGAN);
    oluacls_const_integer(L, "SCROLLING_ENDED", (lua_Integer)cocos2d::ui::ScrollView::EventType::SCROLLING_ENDED);
    oluacls_const_integer(L, "SCROLL_TO_BOTTOM", (lua_Integer)cocos2d::ui::ScrollView::EventType::SCROLL_TO_BOTTOM);
    oluacls_const_integer(L, "SCROLL_TO_LEFT", (lua_Integer)cocos2d::ui::ScrollView::EventType::SCROLL_TO_LEFT);
    oluacls_const_integer(L, "SCROLL_TO_RIGHT", (lua_Integer)cocos2d::ui::ScrollView::EventType::SCROLL_TO_RIGHT);
    oluacls_const_integer(L, "SCROLL_TO_TOP", (lua_Integer)cocos2d::ui::ScrollView::EventType::SCROLL_TO_TOP);

    olua_registerluatype<cocos2d::ui::ScrollView::EventType>(L, "ccui.ScrollView.EventType");

    return 1;
}

static int _cocos2d_ui_ScrollView___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::ui::ScrollView *)olua_toobj(L, 1, "ccui.ScrollView");
    olua_push_cppobj(L, self, "ccui.ScrollView");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_ui_ScrollView_addEventListener(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;
    std::function<void(cocos2d::Ref *, cocos2d::ui::ScrollView::EventType)> arg1;       /** callback */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ScrollView");

    if (olua_is_std_function(L, 2)) {
        void *callback_store_obj = (void *)self;
        std::string tag = "scrollViewCallback";
        std::string func = olua_setcallback(L, callback_store_obj, tag.c_str(), 2, OLUA_TAG_REPLACE);
        lua_State *MT = olua_mainthread();
        arg1 = [callback_store_obj, func, MT](cocos2d::Ref *arg1, cocos2d::ui::ScrollView::EventType arg2) {
            lua_State *L = olua_mainthread();

            if (MT == L) {
                int top = lua_gettop(L);
                olua_push_cppobj(L, arg1, "cc.Ref");
                olua_push_uint(L, (lua_Unsigned)arg2);

                olua_callback(L, callback_store_obj, func.c_str(), 2);

                lua_settop(L, top);
            }
        };
    } else {
        void *callback_store_obj = (void *)self;
        std::string tag = "scrollViewCallback";
        olua_removecallback(L, callback_store_obj, tag.c_str(), OLUA_TAG_SUBEQUAL);
        arg1 = nullptr;
    }

    // void addEventListener(@nullable const std::function<void(Ref*, EventType)>& callback)
    self->addEventListener(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_ScrollView_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::ui::ScrollView *create()
    cocos2d::ui::ScrollView *ret = (cocos2d::ui::ScrollView *)cocos2d::ui::ScrollView::create();
    int num_ret = olua_push_cppobj(L, ret, "ccui.ScrollView");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_ScrollView_createInstance(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::Ref *createInstance()
    cocos2d::Ref *ret = (cocos2d::Ref *)cocos2d::ui::ScrollView::createInstance();
    int num_ret = olua_push_cppobj(L, ret, "cc.Ref");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_ScrollView_getDirection(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ScrollView");

    // cocos2d::ui::ScrollView::Direction getDirection()
    cocos2d::ui::ScrollView::Direction ret = (cocos2d::ui::ScrollView::Direction)self->getDirection();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_ScrollView_getInnerContainer(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ScrollView");

    // @addref(protectedChildren |) cocos2d::ui::Layout *getInnerContainer()
    cocos2d::ui::Layout *ret = (cocos2d::ui::Layout *)self->getInnerContainer();
    int num_ret = olua_push_cppobj(L, ret, "ccui.Layout");

    // inject code after call
    olua_addref(L, 1, "protectedChildren", -1, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_ScrollView_getInnerContainerPosition(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ScrollView");

    // const cocos2d::Vec2 &getInnerContainerPosition()
    const cocos2d::Vec2 &ret = (const cocos2d::Vec2 &)self->getInnerContainerPosition();
    int num_ret = auto_olua_push_cocos2d_Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_ScrollView_getInnerContainerSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ScrollView");

    // const cocos2d::Size &getInnerContainerSize()
    const cocos2d::Size &ret = (const cocos2d::Size &)self->getInnerContainerSize();
    int num_ret = auto_olua_push_cocos2d_Size(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_ScrollView_getScrollBarAutoHideTime(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ScrollView");

    // float getScrollBarAutoHideTime()
    float ret = (float)self->getScrollBarAutoHideTime();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_ScrollView_getScrollBarColor(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ScrollView");

    // const cocos2d::Color3B &getScrollBarColor()
    const cocos2d::Color3B &ret = (const cocos2d::Color3B &)self->getScrollBarColor();
    int num_ret = manual_olua_push_cocos2d_Color3B(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_ScrollView_getScrollBarOpacity(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ScrollView");

    // uint8_t getScrollBarOpacity()
    uint8_t ret = (uint8_t)self->getScrollBarOpacity();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_ScrollView_getScrollBarPositionFromCornerForHorizontal(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ScrollView");

    // cocos2d::Vec2 getScrollBarPositionFromCornerForHorizontal()
    cocos2d::Vec2 ret = (cocos2d::Vec2)self->getScrollBarPositionFromCornerForHorizontal();
    int num_ret = auto_olua_push_cocos2d_Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_ScrollView_getScrollBarPositionFromCornerForVertical(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ScrollView");

    // cocos2d::Vec2 getScrollBarPositionFromCornerForVertical()
    cocos2d::Vec2 ret = (cocos2d::Vec2)self->getScrollBarPositionFromCornerForVertical();
    int num_ret = auto_olua_push_cocos2d_Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_ScrollView_getScrollBarWidth(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ScrollView");

    // float getScrollBarWidth()
    float ret = (float)self->getScrollBarWidth();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_ScrollView_getScrolledPercentBothDirection(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ScrollView");

    // cocos2d::Vec2 getScrolledPercentBothDirection()
    cocos2d::Vec2 ret = (cocos2d::Vec2)self->getScrolledPercentBothDirection();
    int num_ret = auto_olua_push_cocos2d_Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_ScrollView_getScrolledPercentHorizontal(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ScrollView");

    // float getScrolledPercentHorizontal()
    float ret = (float)self->getScrolledPercentHorizontal();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_ScrollView_getScrolledPercentVertical(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ScrollView");

    // float getScrolledPercentVertical()
    float ret = (float)self->getScrolledPercentVertical();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_ScrollView_getTouchTotalTimeThreshold(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ScrollView");

    // float getTouchTotalTimeThreshold()
    float ret = (float)self->getTouchTotalTimeThreshold();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_ScrollView_isAutoScrolling(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ScrollView");

    // bool isAutoScrolling()
    bool ret = (bool)self->isAutoScrolling();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_ScrollView_isBounceEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ScrollView");

    // bool isBounceEnabled()
    bool ret = (bool)self->isBounceEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_ScrollView_isInertiaScrollEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ScrollView");

    // bool isInertiaScrollEnabled()
    bool ret = (bool)self->isInertiaScrollEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_ScrollView_isScrollBarAutoHideEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ScrollView");

    // bool isScrollBarAutoHideEnabled()
    bool ret = (bool)self->isScrollBarAutoHideEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_ScrollView_isScrollBarEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ScrollView");

    // bool isScrollBarEnabled()
    bool ret = (bool)self->isScrollBarEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_ScrollView_isScrolling(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ScrollView");

    // bool isScrolling()
    bool ret = (bool)self->isScrolling();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_ScrollView_jumpToBottom(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ScrollView");

    // void jumpToBottom()
    self->jumpToBottom();

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_ScrollView_jumpToBottomLeft(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ScrollView");

    // void jumpToBottomLeft()
    self->jumpToBottomLeft();

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_ScrollView_jumpToBottomRight(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ScrollView");

    // void jumpToBottomRight()
    self->jumpToBottomRight();

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_ScrollView_jumpToLeft(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ScrollView");

    // void jumpToLeft()
    self->jumpToLeft();

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_ScrollView_jumpToPercentBothDirection(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;
    cocos2d::Vec2 arg1;       /** percent */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ScrollView");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);

    // void jumpToPercentBothDirection(const cocos2d::Vec2 &percent)
    self->jumpToPercentBothDirection(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_ScrollView_jumpToPercentHorizontal(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;
    lua_Number arg1 = 0;       /** percent */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ScrollView");
    olua_check_number(L, 2, &arg1);

    // void jumpToPercentHorizontal(float percent)
    self->jumpToPercentHorizontal((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_ScrollView_jumpToPercentVertical(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;
    lua_Number arg1 = 0;       /** percent */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ScrollView");
    olua_check_number(L, 2, &arg1);

    // void jumpToPercentVertical(float percent)
    self->jumpToPercentVertical((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_ScrollView_jumpToRight(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ScrollView");

    // void jumpToRight()
    self->jumpToRight();

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_ScrollView_jumpToTop(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ScrollView");

    // void jumpToTop()
    self->jumpToTop();

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_ScrollView_jumpToTopLeft(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ScrollView");

    // void jumpToTopLeft()
    self->jumpToTopLeft();

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_ScrollView_jumpToTopRight(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ScrollView");

    // void jumpToTopRight()
    self->jumpToTopRight();

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_ScrollView_new(lua_State *L)
{
    olua_startinvoke(L);

    // ScrollView()
    cocos2d::ui::ScrollView *ret = (cocos2d::ui::ScrollView *)new cocos2d::ui::ScrollView();
    int num_ret = olua_push_cppobj(L, ret, "ccui.ScrollView");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_ScrollView_scrollToBottom(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;
    lua_Number arg1 = 0;       /** timeInSec */
    bool arg2 = false;       /** attenuated */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ScrollView");
    olua_check_number(L, 2, &arg1);
    olua_check_bool(L, 3, &arg2);

    // void scrollToBottom(float timeInSec, bool attenuated)
    self->scrollToBottom((float)arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_ScrollView_scrollToBottomLeft(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;
    lua_Number arg1 = 0;       /** timeInSec */
    bool arg2 = false;       /** attenuated */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ScrollView");
    olua_check_number(L, 2, &arg1);
    olua_check_bool(L, 3, &arg2);

    // void scrollToBottomLeft(float timeInSec, bool attenuated)
    self->scrollToBottomLeft((float)arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_ScrollView_scrollToBottomRight(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;
    lua_Number arg1 = 0;       /** timeInSec */
    bool arg2 = false;       /** attenuated */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ScrollView");
    olua_check_number(L, 2, &arg1);
    olua_check_bool(L, 3, &arg2);

    // void scrollToBottomRight(float timeInSec, bool attenuated)
    self->scrollToBottomRight((float)arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_ScrollView_scrollToLeft(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;
    lua_Number arg1 = 0;       /** timeInSec */
    bool arg2 = false;       /** attenuated */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ScrollView");
    olua_check_number(L, 2, &arg1);
    olua_check_bool(L, 3, &arg2);

    // void scrollToLeft(float timeInSec, bool attenuated)
    self->scrollToLeft((float)arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_ScrollView_scrollToPercentBothDirection(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;
    cocos2d::Vec2 arg1;       /** percent */
    lua_Number arg2 = 0;       /** timeInSec */
    bool arg3 = false;       /** attenuated */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ScrollView");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_bool(L, 4, &arg3);

    // void scrollToPercentBothDirection(const cocos2d::Vec2 &percent, float timeInSec, bool attenuated)
    self->scrollToPercentBothDirection(arg1, (float)arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_ScrollView_scrollToPercentHorizontal(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;
    lua_Number arg1 = 0;       /** percent */
    lua_Number arg2 = 0;       /** timeInSec */
    bool arg3 = false;       /** attenuated */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ScrollView");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_bool(L, 4, &arg3);

    // void scrollToPercentHorizontal(float percent, float timeInSec, bool attenuated)
    self->scrollToPercentHorizontal((float)arg1, (float)arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_ScrollView_scrollToPercentVertical(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;
    lua_Number arg1 = 0;       /** percent */
    lua_Number arg2 = 0;       /** timeInSec */
    bool arg3 = false;       /** attenuated */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ScrollView");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_bool(L, 4, &arg3);

    // void scrollToPercentVertical(float percent, float timeInSec, bool attenuated)
    self->scrollToPercentVertical((float)arg1, (float)arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_ScrollView_scrollToRight(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;
    lua_Number arg1 = 0;       /** timeInSec */
    bool arg2 = false;       /** attenuated */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ScrollView");
    olua_check_number(L, 2, &arg1);
    olua_check_bool(L, 3, &arg2);

    // void scrollToRight(float timeInSec, bool attenuated)
    self->scrollToRight((float)arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_ScrollView_scrollToTop(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;
    lua_Number arg1 = 0;       /** timeInSec */
    bool arg2 = false;       /** attenuated */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ScrollView");
    olua_check_number(L, 2, &arg1);
    olua_check_bool(L, 3, &arg2);

    // void scrollToTop(float timeInSec, bool attenuated)
    self->scrollToTop((float)arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_ScrollView_scrollToTopLeft(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;
    lua_Number arg1 = 0;       /** timeInSec */
    bool arg2 = false;       /** attenuated */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ScrollView");
    olua_check_number(L, 2, &arg1);
    olua_check_bool(L, 3, &arg2);

    // void scrollToTopLeft(float timeInSec, bool attenuated)
    self->scrollToTopLeft((float)arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_ScrollView_scrollToTopRight(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;
    lua_Number arg1 = 0;       /** timeInSec */
    bool arg2 = false;       /** attenuated */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ScrollView");
    olua_check_number(L, 2, &arg1);
    olua_check_bool(L, 3, &arg2);

    // void scrollToTopRight(float timeInSec, bool attenuated)
    self->scrollToTopRight((float)arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_ScrollView_setBounceEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;
    bool arg1 = false;       /** enabled */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ScrollView");
    olua_check_bool(L, 2, &arg1);

    // void setBounceEnabled(bool enabled)
    self->setBounceEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_ScrollView_setDirection(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;
    lua_Unsigned arg1 = 0;       /** dir */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ScrollView");
    olua_check_uint(L, 2, &arg1);

    // void setDirection(cocos2d::ui::ScrollView::Direction dir)
    self->setDirection((cocos2d::ui::ScrollView::Direction)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_ScrollView_setInertiaScrollEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;
    bool arg1 = false;       /** enabled */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ScrollView");
    olua_check_bool(L, 2, &arg1);

    // void setInertiaScrollEnabled(bool enabled)
    self->setInertiaScrollEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_ScrollView_setInnerContainerPosition(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;
    cocos2d::Vec2 arg1;       /** pos */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ScrollView");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);

    // void setInnerContainerPosition(const cocos2d::Vec2 &pos)
    self->setInnerContainerPosition(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_ScrollView_setInnerContainerSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;
    cocos2d::Size arg1;       /** size */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ScrollView");
    auto_olua_check_cocos2d_Size(L, 2, &arg1);

    // void setInnerContainerSize(const cocos2d::Size &size)
    self->setInnerContainerSize(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_ScrollView_setScrollBarAutoHideEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;
    bool arg1 = false;       /** autoHideEnabled */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ScrollView");
    olua_check_bool(L, 2, &arg1);

    // void setScrollBarAutoHideEnabled(bool autoHideEnabled)
    self->setScrollBarAutoHideEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_ScrollView_setScrollBarAutoHideTime(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;
    lua_Number arg1 = 0;       /** autoHideTime */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ScrollView");
    olua_check_number(L, 2, &arg1);

    // void setScrollBarAutoHideTime(float autoHideTime)
    self->setScrollBarAutoHideTime((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_ScrollView_setScrollBarColor(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;
    cocos2d::Color3B arg1;       /** color */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ScrollView");
    manual_olua_check_cocos2d_Color3B(L, 2, &arg1);

    // void setScrollBarColor(const cocos2d::Color3B &color)
    self->setScrollBarColor(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_ScrollView_setScrollBarEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;
    bool arg1 = false;       /** enabled */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ScrollView");
    olua_check_bool(L, 2, &arg1);

    // void setScrollBarEnabled(bool enabled)
    self->setScrollBarEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_ScrollView_setScrollBarOpacity(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;
    lua_Unsigned arg1 = 0;       /** opacity */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ScrollView");
    olua_check_uint(L, 2, &arg1);

    // void setScrollBarOpacity(uint8_t opacity)
    self->setScrollBarOpacity((uint8_t)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_ScrollView_setScrollBarPositionFromCorner(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;
    cocos2d::Vec2 arg1;       /** positionFromCorner */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ScrollView");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);

    // void setScrollBarPositionFromCorner(const cocos2d::Vec2 &positionFromCorner)
    self->setScrollBarPositionFromCorner(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_ScrollView_setScrollBarPositionFromCornerForHorizontal(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;
    cocos2d::Vec2 arg1;       /** positionFromCorner */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ScrollView");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);

    // void setScrollBarPositionFromCornerForHorizontal(const cocos2d::Vec2 &positionFromCorner)
    self->setScrollBarPositionFromCornerForHorizontal(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_ScrollView_setScrollBarPositionFromCornerForVertical(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;
    cocos2d::Vec2 arg1;       /** positionFromCorner */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ScrollView");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);

    // void setScrollBarPositionFromCornerForVertical(const cocos2d::Vec2 &positionFromCorner)
    self->setScrollBarPositionFromCornerForVertical(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_ScrollView_setScrollBarWidth(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;
    lua_Number arg1 = 0;       /** width */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ScrollView");
    olua_check_number(L, 2, &arg1);

    // void setScrollBarWidth(float width)
    self->setScrollBarWidth((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_ScrollView_setTouchTotalTimeThreshold(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;
    lua_Number arg1 = 0;       /** touchTotalTimeThreshold */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ScrollView");
    olua_check_number(L, 2, &arg1);

    // void setTouchTotalTimeThreshold(float touchTotalTimeThreshold)
    self->setTouchTotalTimeThreshold((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_ScrollView_stopAutoScroll(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ScrollView");

    // void stopAutoScroll()
    self->stopAutoScroll();

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_ScrollView_stopOverallScroll(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ScrollView");

    // void stopOverallScroll()
    self->stopOverallScroll();

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_ScrollView_stopScroll(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ScrollView");

    // void stopScroll()
    self->stopScroll();

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_ui_ScrollView(lua_State *L)
{
    oluacls_class(L, "ccui.ScrollView", "ccui.Layout");
    oluacls_func(L, "__move", _cocos2d_ui_ScrollView___move);
    oluacls_func(L, "addEventListener", _cocos2d_ui_ScrollView_addEventListener);
    oluacls_func(L, "addScrollEventListener", _cocos2d_ui_ScrollView_addEventListener);
    oluacls_func(L, "create", _cocos2d_ui_ScrollView_create);
    oluacls_func(L, "createInstance", _cocos2d_ui_ScrollView_createInstance);
    oluacls_func(L, "getDirection", _cocos2d_ui_ScrollView_getDirection);
    oluacls_func(L, "getInnerContainer", _cocos2d_ui_ScrollView_getInnerContainer);
    oluacls_func(L, "getInnerContainerPosition", _cocos2d_ui_ScrollView_getInnerContainerPosition);
    oluacls_func(L, "getInnerContainerSize", _cocos2d_ui_ScrollView_getInnerContainerSize);
    oluacls_func(L, "getScrollBarAutoHideTime", _cocos2d_ui_ScrollView_getScrollBarAutoHideTime);
    oluacls_func(L, "getScrollBarColor", _cocos2d_ui_ScrollView_getScrollBarColor);
    oluacls_func(L, "getScrollBarOpacity", _cocos2d_ui_ScrollView_getScrollBarOpacity);
    oluacls_func(L, "getScrollBarPositionFromCornerForHorizontal", _cocos2d_ui_ScrollView_getScrollBarPositionFromCornerForHorizontal);
    oluacls_func(L, "getScrollBarPositionFromCornerForVertical", _cocos2d_ui_ScrollView_getScrollBarPositionFromCornerForVertical);
    oluacls_func(L, "getScrollBarWidth", _cocos2d_ui_ScrollView_getScrollBarWidth);
    oluacls_func(L, "getScrolledPercentBothDirection", _cocos2d_ui_ScrollView_getScrolledPercentBothDirection);
    oluacls_func(L, "getScrolledPercentHorizontal", _cocos2d_ui_ScrollView_getScrolledPercentHorizontal);
    oluacls_func(L, "getScrolledPercentVertical", _cocos2d_ui_ScrollView_getScrolledPercentVertical);
    oluacls_func(L, "getTouchTotalTimeThreshold", _cocos2d_ui_ScrollView_getTouchTotalTimeThreshold);
    oluacls_func(L, "isAutoScrolling", _cocos2d_ui_ScrollView_isAutoScrolling);
    oluacls_func(L, "isBounceEnabled", _cocos2d_ui_ScrollView_isBounceEnabled);
    oluacls_func(L, "isInertiaScrollEnabled", _cocos2d_ui_ScrollView_isInertiaScrollEnabled);
    oluacls_func(L, "isScrollBarAutoHideEnabled", _cocos2d_ui_ScrollView_isScrollBarAutoHideEnabled);
    oluacls_func(L, "isScrollBarEnabled", _cocos2d_ui_ScrollView_isScrollBarEnabled);
    oluacls_func(L, "isScrolling", _cocos2d_ui_ScrollView_isScrolling);
    oluacls_func(L, "jumpToBottom", _cocos2d_ui_ScrollView_jumpToBottom);
    oluacls_func(L, "jumpToBottomLeft", _cocos2d_ui_ScrollView_jumpToBottomLeft);
    oluacls_func(L, "jumpToBottomRight", _cocos2d_ui_ScrollView_jumpToBottomRight);
    oluacls_func(L, "jumpToLeft", _cocos2d_ui_ScrollView_jumpToLeft);
    oluacls_func(L, "jumpToPercentBothDirection", _cocos2d_ui_ScrollView_jumpToPercentBothDirection);
    oluacls_func(L, "jumpToPercentHorizontal", _cocos2d_ui_ScrollView_jumpToPercentHorizontal);
    oluacls_func(L, "jumpToPercentVertical", _cocos2d_ui_ScrollView_jumpToPercentVertical);
    oluacls_func(L, "jumpToRight", _cocos2d_ui_ScrollView_jumpToRight);
    oluacls_func(L, "jumpToTop", _cocos2d_ui_ScrollView_jumpToTop);
    oluacls_func(L, "jumpToTopLeft", _cocos2d_ui_ScrollView_jumpToTopLeft);
    oluacls_func(L, "jumpToTopRight", _cocos2d_ui_ScrollView_jumpToTopRight);
    oluacls_func(L, "new", _cocos2d_ui_ScrollView_new);
    oluacls_func(L, "scrollToBottom", _cocos2d_ui_ScrollView_scrollToBottom);
    oluacls_func(L, "scrollToBottomLeft", _cocos2d_ui_ScrollView_scrollToBottomLeft);
    oluacls_func(L, "scrollToBottomRight", _cocos2d_ui_ScrollView_scrollToBottomRight);
    oluacls_func(L, "scrollToLeft", _cocos2d_ui_ScrollView_scrollToLeft);
    oluacls_func(L, "scrollToPercentBothDirection", _cocos2d_ui_ScrollView_scrollToPercentBothDirection);
    oluacls_func(L, "scrollToPercentHorizontal", _cocos2d_ui_ScrollView_scrollToPercentHorizontal);
    oluacls_func(L, "scrollToPercentVertical", _cocos2d_ui_ScrollView_scrollToPercentVertical);
    oluacls_func(L, "scrollToRight", _cocos2d_ui_ScrollView_scrollToRight);
    oluacls_func(L, "scrollToTop", _cocos2d_ui_ScrollView_scrollToTop);
    oluacls_func(L, "scrollToTopLeft", _cocos2d_ui_ScrollView_scrollToTopLeft);
    oluacls_func(L, "scrollToTopRight", _cocos2d_ui_ScrollView_scrollToTopRight);
    oluacls_func(L, "setBounceEnabled", _cocos2d_ui_ScrollView_setBounceEnabled);
    oluacls_func(L, "setDirection", _cocos2d_ui_ScrollView_setDirection);
    oluacls_func(L, "setInertiaScrollEnabled", _cocos2d_ui_ScrollView_setInertiaScrollEnabled);
    oluacls_func(L, "setInnerContainerPosition", _cocos2d_ui_ScrollView_setInnerContainerPosition);
    oluacls_func(L, "setInnerContainerSize", _cocos2d_ui_ScrollView_setInnerContainerSize);
    oluacls_func(L, "setScrollBarAutoHideEnabled", _cocos2d_ui_ScrollView_setScrollBarAutoHideEnabled);
    oluacls_func(L, "setScrollBarAutoHideTime", _cocos2d_ui_ScrollView_setScrollBarAutoHideTime);
    oluacls_func(L, "setScrollBarColor", _cocos2d_ui_ScrollView_setScrollBarColor);
    oluacls_func(L, "setScrollBarEnabled", _cocos2d_ui_ScrollView_setScrollBarEnabled);
    oluacls_func(L, "setScrollBarOpacity", _cocos2d_ui_ScrollView_setScrollBarOpacity);
    oluacls_func(L, "setScrollBarPositionFromCorner", _cocos2d_ui_ScrollView_setScrollBarPositionFromCorner);
    oluacls_func(L, "setScrollBarPositionFromCornerForHorizontal", _cocos2d_ui_ScrollView_setScrollBarPositionFromCornerForHorizontal);
    oluacls_func(L, "setScrollBarPositionFromCornerForVertical", _cocos2d_ui_ScrollView_setScrollBarPositionFromCornerForVertical);
    oluacls_func(L, "setScrollBarWidth", _cocos2d_ui_ScrollView_setScrollBarWidth);
    oluacls_func(L, "setTouchTotalTimeThreshold", _cocos2d_ui_ScrollView_setTouchTotalTimeThreshold);
    oluacls_func(L, "stopAutoScroll", _cocos2d_ui_ScrollView_stopAutoScroll);
    oluacls_func(L, "stopOverallScroll", _cocos2d_ui_ScrollView_stopOverallScroll);
    oluacls_func(L, "stopScroll", _cocos2d_ui_ScrollView_stopScroll);
    oluacls_prop(L, "autoScrolling", _cocos2d_ui_ScrollView_isAutoScrolling, nullptr);
    oluacls_prop(L, "bounceEnabled", _cocos2d_ui_ScrollView_isBounceEnabled, _cocos2d_ui_ScrollView_setBounceEnabled);
    oluacls_prop(L, "direction", _cocos2d_ui_ScrollView_getDirection, _cocos2d_ui_ScrollView_setDirection);
    oluacls_prop(L, "inertiaScrollEnabled", _cocos2d_ui_ScrollView_isInertiaScrollEnabled, _cocos2d_ui_ScrollView_setInertiaScrollEnabled);
    oluacls_prop(L, "innerContainer", _cocos2d_ui_ScrollView_getInnerContainer, nullptr);
    oluacls_prop(L, "innerContainerPosition", _cocos2d_ui_ScrollView_getInnerContainerPosition, _cocos2d_ui_ScrollView_setInnerContainerPosition);
    oluacls_prop(L, "innerContainerSize", _cocos2d_ui_ScrollView_getInnerContainerSize, _cocos2d_ui_ScrollView_setInnerContainerSize);
    oluacls_prop(L, "scrollBarAutoHideEnabled", _cocos2d_ui_ScrollView_isScrollBarAutoHideEnabled, _cocos2d_ui_ScrollView_setScrollBarAutoHideEnabled);
    oluacls_prop(L, "scrollBarAutoHideTime", _cocos2d_ui_ScrollView_getScrollBarAutoHideTime, _cocos2d_ui_ScrollView_setScrollBarAutoHideTime);
    oluacls_prop(L, "scrollBarColor", _cocos2d_ui_ScrollView_getScrollBarColor, _cocos2d_ui_ScrollView_setScrollBarColor);
    oluacls_prop(L, "scrollBarEnabled", _cocos2d_ui_ScrollView_isScrollBarEnabled, _cocos2d_ui_ScrollView_setScrollBarEnabled);
    oluacls_prop(L, "scrollBarOpacity", _cocos2d_ui_ScrollView_getScrollBarOpacity, _cocos2d_ui_ScrollView_setScrollBarOpacity);
    oluacls_prop(L, "scrollBarPositionFromCornerForHorizontal", _cocos2d_ui_ScrollView_getScrollBarPositionFromCornerForHorizontal, _cocos2d_ui_ScrollView_setScrollBarPositionFromCornerForHorizontal);
    oluacls_prop(L, "scrollBarPositionFromCornerForVertical", _cocos2d_ui_ScrollView_getScrollBarPositionFromCornerForVertical, _cocos2d_ui_ScrollView_setScrollBarPositionFromCornerForVertical);
    oluacls_prop(L, "scrollBarWidth", _cocos2d_ui_ScrollView_getScrollBarWidth, _cocos2d_ui_ScrollView_setScrollBarWidth);
    oluacls_prop(L, "scrolledPercentBothDirection", _cocos2d_ui_ScrollView_getScrolledPercentBothDirection, nullptr);
    oluacls_prop(L, "scrolledPercentHorizontal", _cocos2d_ui_ScrollView_getScrolledPercentHorizontal, nullptr);
    oluacls_prop(L, "scrolledPercentVertical", _cocos2d_ui_ScrollView_getScrolledPercentVertical, nullptr);
    oluacls_prop(L, "scrolling", _cocos2d_ui_ScrollView_isScrolling, nullptr);
    oluacls_prop(L, "touchTotalTimeThreshold", _cocos2d_ui_ScrollView_getTouchTotalTimeThreshold, _cocos2d_ui_ScrollView_setTouchTotalTimeThreshold);

    olua_registerluatype<cocos2d::ui::ScrollView>(L, "ccui.ScrollView");

    return 1;
}

static int luaopen_cocos2d_ui_ListView_Gravity(lua_State *L)
{
    oluacls_class(L, "ccui.ListView.Gravity", nullptr);
    oluacls_const_integer(L, "BOTTOM", (lua_Integer)cocos2d::ui::ListView::Gravity::BOTTOM);
    oluacls_const_integer(L, "CENTER_HORIZONTAL", (lua_Integer)cocos2d::ui::ListView::Gravity::CENTER_HORIZONTAL);
    oluacls_const_integer(L, "CENTER_VERTICAL", (lua_Integer)cocos2d::ui::ListView::Gravity::CENTER_VERTICAL);
    oluacls_const_integer(L, "LEFT", (lua_Integer)cocos2d::ui::ListView::Gravity::LEFT);
    oluacls_const_integer(L, "RIGHT", (lua_Integer)cocos2d::ui::ListView::Gravity::RIGHT);
    oluacls_const_integer(L, "TOP", (lua_Integer)cocos2d::ui::ListView::Gravity::TOP);

    olua_registerluatype<cocos2d::ui::ListView::Gravity>(L, "ccui.ListView.Gravity");

    return 1;
}

static int luaopen_cocos2d_ui_ListView_EventType(lua_State *L)
{
    oluacls_class(L, "ccui.ListView.EventType", nullptr);
    oluacls_const_integer(L, "ON_SELECTED_ITEM_END", (lua_Integer)cocos2d::ui::ListView::EventType::ON_SELECTED_ITEM_END);
    oluacls_const_integer(L, "ON_SELECTED_ITEM_START", (lua_Integer)cocos2d::ui::ListView::EventType::ON_SELECTED_ITEM_START);

    olua_registerluatype<cocos2d::ui::ListView::EventType>(L, "ccui.ListView.EventType");

    return 1;
}

static int luaopen_cocos2d_ui_ListView_MagneticType(lua_State *L)
{
    oluacls_class(L, "ccui.ListView.MagneticType", nullptr);
    oluacls_const_integer(L, "BOTH_END", (lua_Integer)cocos2d::ui::ListView::MagneticType::BOTH_END);
    oluacls_const_integer(L, "BOTTOM", (lua_Integer)cocos2d::ui::ListView::MagneticType::BOTTOM);
    oluacls_const_integer(L, "CENTER", (lua_Integer)cocos2d::ui::ListView::MagneticType::CENTER);
    oluacls_const_integer(L, "LEFT", (lua_Integer)cocos2d::ui::ListView::MagneticType::LEFT);
    oluacls_const_integer(L, "NONE", (lua_Integer)cocos2d::ui::ListView::MagneticType::NONE);
    oluacls_const_integer(L, "RIGHT", (lua_Integer)cocos2d::ui::ListView::MagneticType::RIGHT);
    oluacls_const_integer(L, "TOP", (lua_Integer)cocos2d::ui::ListView::MagneticType::TOP);

    olua_registerluatype<cocos2d::ui::ListView::MagneticType>(L, "ccui.ListView.MagneticType");

    return 1;
}

static int _cocos2d_ui_ListView___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::ui::ListView *)olua_toobj(L, 1, "ccui.ListView");
    olua_push_cppobj(L, self, "ccui.ListView");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_ui_ListView_addEventListener(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;
    std::function<void(cocos2d::Ref *, cocos2d::ui::ListView::EventType)> arg1;       /** callback */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ListView");

    if (olua_is_std_function(L, 2)) {
        void *callback_store_obj = (void *)self;
        std::string tag = "ListViewCallback";
        std::string func = olua_setcallback(L, callback_store_obj, tag.c_str(), 2, OLUA_TAG_REPLACE);
        lua_State *MT = olua_mainthread();
        arg1 = [callback_store_obj, func, MT](cocos2d::Ref *arg1, cocos2d::ui::ListView::EventType arg2) {
            lua_State *L = olua_mainthread();

            if (MT == L) {
                int top = lua_gettop(L);
                olua_push_cppobj(L, arg1, "cc.Ref");
                olua_push_uint(L, (lua_Unsigned)arg2);

                olua_callback(L, callback_store_obj, func.c_str(), 2);

                lua_settop(L, top);
            }
        };
    } else {
        void *callback_store_obj = (void *)self;
        std::string tag = "ListViewCallback";
        olua_removecallback(L, callback_store_obj, tag.c_str(), OLUA_TAG_SUBEQUAL);
        arg1 = nullptr;
    }

    // void addEventListener(@nullable const std::function<void(Ref*, EventType)>& callback)
    self->addEventListener(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_ListView_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::ui::ListView *create()
    cocos2d::ui::ListView *ret = (cocos2d::ui::ListView *)cocos2d::ui::ListView::create();
    int num_ret = olua_push_cppobj(L, ret, "ccui.ListView");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_ListView_createInstance(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::Ref *createInstance()
    cocos2d::Ref *ret = (cocos2d::Ref *)cocos2d::ui::ListView::createInstance();
    int num_ret = olua_push_cppobj(L, ret, "cc.Ref");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_ListView_doLayout(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ListView");

    // void doLayout()
    self->doLayout();

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_ListView_getBottomPadding(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ListView");

    // float getBottomPadding()
    float ret = (float)self->getBottomPadding();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_ListView_getBottommostItemInCurrentView(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ListView");

    // cocos2d::ui::Widget *getBottommostItemInCurrentView()
    cocos2d::ui::Widget *ret = (cocos2d::ui::Widget *)self->getBottommostItemInCurrentView();
    int num_ret = olua_push_cppobj(L, ret, "ccui.Widget");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_ListView_getCenterItemInCurrentView(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ListView");

    // cocos2d::ui::Widget *getCenterItemInCurrentView()
    cocos2d::ui::Widget *ret = (cocos2d::ui::Widget *)self->getCenterItemInCurrentView();
    int num_ret = olua_push_cppobj(L, ret, "ccui.Widget");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_ListView_getClosestItemToPosition(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;
    cocos2d::Vec2 arg1;       /** targetPosition */
    cocos2d::Vec2 arg2;       /** itemAnchorPoint */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ListView");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);
    auto_olua_check_cocos2d_Vec2(L, 3, &arg2);

    // cocos2d::ui::Widget *getClosestItemToPosition(const cocos2d::Vec2 &targetPosition, const cocos2d::Vec2 &itemAnchorPoint)
    cocos2d::ui::Widget *ret = (cocos2d::ui::Widget *)self->getClosestItemToPosition(arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "ccui.Widget");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_ListView_getClosestItemToPositionInCurrentView(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;
    cocos2d::Vec2 arg1;       /** positionRatioInView */
    cocos2d::Vec2 arg2;       /** itemAnchorPoint */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ListView");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);
    auto_olua_check_cocos2d_Vec2(L, 3, &arg2);

    // cocos2d::ui::Widget *getClosestItemToPositionInCurrentView(const cocos2d::Vec2 &positionRatioInView, const cocos2d::Vec2 &itemAnchorPoint)
    cocos2d::ui::Widget *ret = (cocos2d::ui::Widget *)self->getClosestItemToPositionInCurrentView(arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "ccui.Widget");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_ListView_getCurSelectedIndex(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ListView");

    // ssize_t getCurSelectedIndex()
    ssize_t ret = (ssize_t)self->getCurSelectedIndex();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_ListView_getIndex(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;
    cocos2d::ui::Widget *arg1 = nullptr;       /** item */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ListView");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccui.Widget");

    // ssize_t getIndex(cocos2d::ui::Widget *item)
    ssize_t ret = (ssize_t)self->getIndex(arg1);
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_ListView_getItem(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;
    lua_Integer arg1 = 0;       /** index */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ListView");
    olua_check_int(L, 2, &arg1);

    // @addref(children |) cocos2d::ui::Widget *getItem(ssize_t index)
    cocos2d::ui::Widget *ret = (cocos2d::ui::Widget *)self->getItem((ssize_t)arg1);
    int num_ret = olua_push_cppobj(L, ret, "ccui.Widget");

    // inject code after call
    olua_addref(L, 1, "children", -1, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_ListView_getItems(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ListView");

    // @addref(children |) Vector<cocos2d::ui::Widget *> &getItems()
    cocos2d::Vector<cocos2d::ui::Widget *> &ret = (cocos2d::Vector<cocos2d::ui::Widget *> &)self->getItems();
    int num_ret = manual_olua_push_cocos2d_Vector(L, ret, "ccui.Widget");

    // inject code after call
    olua_addref(L, 1, "children", -1, OLUA_MODE_MULTIPLE | OLUA_FLAG_ARRAY);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_ListView_getItemsMargin(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ListView");

    // float getItemsMargin()
    float ret = (float)self->getItemsMargin();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_ListView_getLeftPadding(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ListView");

    // float getLeftPadding()
    float ret = (float)self->getLeftPadding();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_ListView_getLeftmostItemInCurrentView(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ListView");

    // cocos2d::ui::Widget *getLeftmostItemInCurrentView()
    cocos2d::ui::Widget *ret = (cocos2d::ui::Widget *)self->getLeftmostItemInCurrentView();
    int num_ret = olua_push_cppobj(L, ret, "ccui.Widget");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_ListView_getMagneticAllowedOutOfBoundary(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ListView");

    // bool getMagneticAllowedOutOfBoundary()
    bool ret = (bool)self->getMagneticAllowedOutOfBoundary();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_ListView_getMagneticType(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ListView");

    // cocos2d::ui::ListView::MagneticType getMagneticType()
    cocos2d::ui::ListView::MagneticType ret = (cocos2d::ui::ListView::MagneticType)self->getMagneticType();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_ListView_getRightPadding(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ListView");

    // float getRightPadding()
    float ret = (float)self->getRightPadding();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_ListView_getRightmostItemInCurrentView(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ListView");

    // cocos2d::ui::Widget *getRightmostItemInCurrentView()
    cocos2d::ui::Widget *ret = (cocos2d::ui::Widget *)self->getRightmostItemInCurrentView();
    int num_ret = olua_push_cppobj(L, ret, "ccui.Widget");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_ListView_getScrollDuration(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ListView");

    // float getScrollDuration()
    float ret = (float)self->getScrollDuration();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_ListView_getTopPadding(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ListView");

    // float getTopPadding()
    float ret = (float)self->getTopPadding();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_ListView_getTopmostItemInCurrentView(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ListView");

    // cocos2d::ui::Widget *getTopmostItemInCurrentView()
    cocos2d::ui::Widget *ret = (cocos2d::ui::Widget *)self->getTopmostItemInCurrentView();
    int num_ret = olua_push_cppobj(L, ret, "ccui.Widget");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_ListView_insertCustomItem(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;
    cocos2d::ui::Widget *arg1 = nullptr;       /** item */
    lua_Integer arg2 = 0;       /** index */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ListView");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccui.Widget");
    olua_check_int(L, 3, &arg2);

    // void insertCustomItem(@addref(children |) cocos2d::ui::Widget *item, ssize_t index)
    self->insertCustomItem(arg1, (ssize_t)arg2);

    // inject code after call
    olua_addref(L, 1, "children", 2, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_ListView_insertDefaultItem(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;
    lua_Integer arg1 = 0;       /** index */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ListView");
    olua_check_int(L, 2, &arg1);

    // void insertDefaultItem(ssize_t index)
    self->insertDefaultItem((ssize_t)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_ListView_jumpToItem(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;
    lua_Integer arg1 = 0;       /** itemIndex */
    cocos2d::Vec2 arg2;       /** positionRatioInView */
    cocos2d::Vec2 arg3;       /** itemAnchorPoint */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ListView");
    olua_check_int(L, 2, &arg1);
    auto_olua_check_cocos2d_Vec2(L, 3, &arg2);
    auto_olua_check_cocos2d_Vec2(L, 4, &arg3);

    // void jumpToItem(ssize_t itemIndex, const cocos2d::Vec2 &positionRatioInView, const cocos2d::Vec2 &itemAnchorPoint)
    self->jumpToItem((ssize_t)arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_ListView_new(lua_State *L)
{
    olua_startinvoke(L);

    // ListView()
    cocos2d::ui::ListView *ret = (cocos2d::ui::ListView *)new cocos2d::ui::ListView();
    int num_ret = olua_push_cppobj(L, ret, "ccui.ListView");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_ListView_pushBackCustomItem(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;
    cocos2d::ui::Widget *arg1 = nullptr;       /** item */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ListView");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccui.Widget");

    // void pushBackCustomItem(@addref(children |) cocos2d::ui::Widget *item)
    self->pushBackCustomItem(arg1);

    // inject code after call
    olua_addref(L, 1, "children", 2, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_ListView_pushBackDefaultItem(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ListView");

    // void pushBackDefaultItem()
    self->pushBackDefaultItem();

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_ListView_removeAllItems(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ListView");

    // inject code before call
    olua_startcmpdelref(L, 1, "children");

    // @delref(children ~) void removeAllItems()
    self->removeAllItems();

    // inject code after call
    olua_endcmpdelref(L, 1, "children");

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_ListView_removeItem(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;
    lua_Integer arg1 = 0;       /** index */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ListView");
    olua_check_int(L, 2, &arg1);

    // inject code before call
    olua_startcmpdelref(L, 1, "children");

    // @delref(children ~) void removeItem(ssize_t index)
    self->removeItem((ssize_t)arg1);

    // inject code after call
    olua_endcmpdelref(L, 1, "children");

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_ListView_removeLastItem(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ListView");

    // inject code before call
    olua_startcmpdelref(L, 1, "children");

    // @delref(children ~) void removeLastItem()
    self->removeLastItem();

    // inject code after call
    olua_endcmpdelref(L, 1, "children");

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_ListView_scrollToItem1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;
    lua_Integer arg1 = 0;       /** itemIndex */
    cocos2d::Vec2 arg2;       /** positionRatioInView */
    cocos2d::Vec2 arg3;       /** itemAnchorPoint */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ListView");
    olua_check_int(L, 2, &arg1);
    auto_olua_check_cocos2d_Vec2(L, 3, &arg2);
    auto_olua_check_cocos2d_Vec2(L, 4, &arg3);

    // void scrollToItem(ssize_t itemIndex, const cocos2d::Vec2 &positionRatioInView, const cocos2d::Vec2 &itemAnchorPoint)
    self->scrollToItem((ssize_t)arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_ListView_scrollToItem2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;
    lua_Integer arg1 = 0;       /** itemIndex */
    cocos2d::Vec2 arg2;       /** positionRatioInView */
    cocos2d::Vec2 arg3;       /** itemAnchorPoint */
    lua_Number arg4 = 0;       /** timeInSec */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ListView");
    olua_check_int(L, 2, &arg1);
    auto_olua_check_cocos2d_Vec2(L, 3, &arg2);
    auto_olua_check_cocos2d_Vec2(L, 4, &arg3);
    olua_check_number(L, 5, &arg4);

    // void scrollToItem(ssize_t itemIndex, const cocos2d::Vec2 &positionRatioInView, const cocos2d::Vec2 &itemAnchorPoint, float timeInSec)
    self->scrollToItem((ssize_t)arg1, arg2, arg3, (float)arg4);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_ListView_scrollToItem(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 3) {
        // if ((olua_is_int(L, 2)) && (auto_olua_is_cocos2d_Vec2(L, 3)) && (auto_olua_is_cocos2d_Vec2(L, 4))) {
            // void scrollToItem(ssize_t itemIndex, const cocos2d::Vec2 &positionRatioInView, const cocos2d::Vec2 &itemAnchorPoint)
            return _cocos2d_ui_ListView_scrollToItem1(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_int(L, 2)) && (auto_olua_is_cocos2d_Vec2(L, 3)) && (auto_olua_is_cocos2d_Vec2(L, 4)) && (olua_is_number(L, 5))) {
            // void scrollToItem(ssize_t itemIndex, const cocos2d::Vec2 &positionRatioInView, const cocos2d::Vec2 &itemAnchorPoint, float timeInSec)
            return _cocos2d_ui_ListView_scrollToItem2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::ListView::scrollToItem' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ui_ListView_setBottomPadding(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;
    lua_Number arg1 = 0;       /** b */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ListView");
    olua_check_number(L, 2, &arg1);

    // void setBottomPadding(float b)
    self->setBottomPadding((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_ListView_setCurSelectedIndex(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;
    lua_Integer arg1 = 0;       /** itemIndex */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ListView");
    olua_check_int(L, 2, &arg1);

    // void setCurSelectedIndex(int itemIndex)
    self->setCurSelectedIndex((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_ListView_setGravity(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;
    lua_Unsigned arg1 = 0;       /** gravity */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ListView");
    olua_check_uint(L, 2, &arg1);

    // void setGravity(cocos2d::ui::ListView::Gravity gravity)
    self->setGravity((cocos2d::ui::ListView::Gravity)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_ListView_setItemModel(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;
    cocos2d::ui::Widget *arg1 = nullptr;       /** model */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ListView");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccui.Widget");

    // void setItemModel(cocos2d::ui::Widget *model)
    self->setItemModel(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_ListView_setItemsMargin(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;
    lua_Number arg1 = 0;       /** margin */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ListView");
    olua_check_number(L, 2, &arg1);

    // void setItemsMargin(float margin)
    self->setItemsMargin((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_ListView_setLeftPadding(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;
    lua_Number arg1 = 0;       /** l */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ListView");
    olua_check_number(L, 2, &arg1);

    // void setLeftPadding(float l)
    self->setLeftPadding((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_ListView_setMagneticAllowedOutOfBoundary(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;
    bool arg1 = false;       /** magneticAllowedOutOfBoundary */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ListView");
    olua_check_bool(L, 2, &arg1);

    // void setMagneticAllowedOutOfBoundary(bool magneticAllowedOutOfBoundary)
    self->setMagneticAllowedOutOfBoundary(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_ListView_setMagneticType(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;
    lua_Unsigned arg1 = 0;       /** magneticType */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ListView");
    olua_check_uint(L, 2, &arg1);

    // void setMagneticType(cocos2d::ui::ListView::MagneticType magneticType)
    self->setMagneticType((cocos2d::ui::ListView::MagneticType)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_ListView_setPadding(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;
    lua_Number arg1 = 0;       /** l */
    lua_Number arg2 = 0;       /** t */
    lua_Number arg3 = 0;       /** r */
    lua_Number arg4 = 0;       /** b */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ListView");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);
    olua_check_number(L, 5, &arg4);

    // void setPadding(float l, float t, float r, float b)
    self->setPadding((float)arg1, (float)arg2, (float)arg3, (float)arg4);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_ListView_setRightPadding(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;
    lua_Number arg1 = 0;       /** r */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ListView");
    olua_check_number(L, 2, &arg1);

    // void setRightPadding(float r)
    self->setRightPadding((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_ListView_setScrollDuration(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;
    lua_Number arg1 = 0;       /** time */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ListView");
    olua_check_number(L, 2, &arg1);

    // void setScrollDuration(float time)
    self->setScrollDuration((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_ListView_setTopPadding(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ListView *self = nullptr;
    lua_Number arg1 = 0;       /** t */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ListView");
    olua_check_number(L, 2, &arg1);

    // void setTopPadding(float t)
    self->setTopPadding((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_ui_ListView(lua_State *L)
{
    oluacls_class(L, "ccui.ListView", "ccui.ScrollView");
    oluacls_func(L, "__move", _cocos2d_ui_ListView___move);
    oluacls_func(L, "addEventListener", _cocos2d_ui_ListView_addEventListener);
    oluacls_func(L, "addListViewEventListener", _cocos2d_ui_ListView_addEventListener);
    oluacls_func(L, "create", _cocos2d_ui_ListView_create);
    oluacls_func(L, "createInstance", _cocos2d_ui_ListView_createInstance);
    oluacls_func(L, "doLayout", _cocos2d_ui_ListView_doLayout);
    oluacls_func(L, "getBottomPadding", _cocos2d_ui_ListView_getBottomPadding);
    oluacls_func(L, "getBottommostItemInCurrentView", _cocos2d_ui_ListView_getBottommostItemInCurrentView);
    oluacls_func(L, "getCenterItemInCurrentView", _cocos2d_ui_ListView_getCenterItemInCurrentView);
    oluacls_func(L, "getClosestItemToPosition", _cocos2d_ui_ListView_getClosestItemToPosition);
    oluacls_func(L, "getClosestItemToPositionInCurrentView", _cocos2d_ui_ListView_getClosestItemToPositionInCurrentView);
    oluacls_func(L, "getCurSelectedIndex", _cocos2d_ui_ListView_getCurSelectedIndex);
    oluacls_func(L, "getIndex", _cocos2d_ui_ListView_getIndex);
    oluacls_func(L, "getItem", _cocos2d_ui_ListView_getItem);
    oluacls_func(L, "getItems", _cocos2d_ui_ListView_getItems);
    oluacls_func(L, "getItemsMargin", _cocos2d_ui_ListView_getItemsMargin);
    oluacls_func(L, "getLeftPadding", _cocos2d_ui_ListView_getLeftPadding);
    oluacls_func(L, "getLeftmostItemInCurrentView", _cocos2d_ui_ListView_getLeftmostItemInCurrentView);
    oluacls_func(L, "getMagneticAllowedOutOfBoundary", _cocos2d_ui_ListView_getMagneticAllowedOutOfBoundary);
    oluacls_func(L, "getMagneticType", _cocos2d_ui_ListView_getMagneticType);
    oluacls_func(L, "getRightPadding", _cocos2d_ui_ListView_getRightPadding);
    oluacls_func(L, "getRightmostItemInCurrentView", _cocos2d_ui_ListView_getRightmostItemInCurrentView);
    oluacls_func(L, "getScrollDuration", _cocos2d_ui_ListView_getScrollDuration);
    oluacls_func(L, "getTopPadding", _cocos2d_ui_ListView_getTopPadding);
    oluacls_func(L, "getTopmostItemInCurrentView", _cocos2d_ui_ListView_getTopmostItemInCurrentView);
    oluacls_func(L, "insertCustomItem", _cocos2d_ui_ListView_insertCustomItem);
    oluacls_func(L, "insertDefaultItem", _cocos2d_ui_ListView_insertDefaultItem);
    oluacls_func(L, "jumpToItem", _cocos2d_ui_ListView_jumpToItem);
    oluacls_func(L, "new", _cocos2d_ui_ListView_new);
    oluacls_func(L, "pushBackCustomItem", _cocos2d_ui_ListView_pushBackCustomItem);
    oluacls_func(L, "pushBackDefaultItem", _cocos2d_ui_ListView_pushBackDefaultItem);
    oluacls_func(L, "removeAllItems", _cocos2d_ui_ListView_removeAllItems);
    oluacls_func(L, "removeItem", _cocos2d_ui_ListView_removeItem);
    oluacls_func(L, "removeLastItem", _cocos2d_ui_ListView_removeLastItem);
    oluacls_func(L, "scrollToItem", _cocos2d_ui_ListView_scrollToItem);
    oluacls_func(L, "setBottomPadding", _cocos2d_ui_ListView_setBottomPadding);
    oluacls_func(L, "setCurSelectedIndex", _cocos2d_ui_ListView_setCurSelectedIndex);
    oluacls_func(L, "setGravity", _cocos2d_ui_ListView_setGravity);
    oluacls_func(L, "setItemModel", _cocos2d_ui_ListView_setItemModel);
    oluacls_func(L, "setItemsMargin", _cocos2d_ui_ListView_setItemsMargin);
    oluacls_func(L, "setLeftPadding", _cocos2d_ui_ListView_setLeftPadding);
    oluacls_func(L, "setMagneticAllowedOutOfBoundary", _cocos2d_ui_ListView_setMagneticAllowedOutOfBoundary);
    oluacls_func(L, "setMagneticType", _cocos2d_ui_ListView_setMagneticType);
    oluacls_func(L, "setPadding", _cocos2d_ui_ListView_setPadding);
    oluacls_func(L, "setRightPadding", _cocos2d_ui_ListView_setRightPadding);
    oluacls_func(L, "setScrollDuration", _cocos2d_ui_ListView_setScrollDuration);
    oluacls_func(L, "setTopPadding", _cocos2d_ui_ListView_setTopPadding);
    oluacls_prop(L, "bottomPadding", _cocos2d_ui_ListView_getBottomPadding, _cocos2d_ui_ListView_setBottomPadding);
    oluacls_prop(L, "bottommostItemInCurrentView", _cocos2d_ui_ListView_getBottommostItemInCurrentView, nullptr);
    oluacls_prop(L, "centerItemInCurrentView", _cocos2d_ui_ListView_getCenterItemInCurrentView, nullptr);
    oluacls_prop(L, "curSelectedIndex", _cocos2d_ui_ListView_getCurSelectedIndex, _cocos2d_ui_ListView_setCurSelectedIndex);
    oluacls_prop(L, "items", _cocos2d_ui_ListView_getItems, nullptr);
    oluacls_prop(L, "itemsMargin", _cocos2d_ui_ListView_getItemsMargin, _cocos2d_ui_ListView_setItemsMargin);
    oluacls_prop(L, "leftPadding", _cocos2d_ui_ListView_getLeftPadding, _cocos2d_ui_ListView_setLeftPadding);
    oluacls_prop(L, "leftmostItemInCurrentView", _cocos2d_ui_ListView_getLeftmostItemInCurrentView, nullptr);
    oluacls_prop(L, "magneticAllowedOutOfBoundary", _cocos2d_ui_ListView_getMagneticAllowedOutOfBoundary, _cocos2d_ui_ListView_setMagneticAllowedOutOfBoundary);
    oluacls_prop(L, "magneticType", _cocos2d_ui_ListView_getMagneticType, _cocos2d_ui_ListView_setMagneticType);
    oluacls_prop(L, "rightPadding", _cocos2d_ui_ListView_getRightPadding, _cocos2d_ui_ListView_setRightPadding);
    oluacls_prop(L, "rightmostItemInCurrentView", _cocos2d_ui_ListView_getRightmostItemInCurrentView, nullptr);
    oluacls_prop(L, "scrollDuration", _cocos2d_ui_ListView_getScrollDuration, _cocos2d_ui_ListView_setScrollDuration);
    oluacls_prop(L, "topPadding", _cocos2d_ui_ListView_getTopPadding, _cocos2d_ui_ListView_setTopPadding);
    oluacls_prop(L, "topmostItemInCurrentView", _cocos2d_ui_ListView_getTopmostItemInCurrentView, nullptr);

    olua_registerluatype<cocos2d::ui::ListView>(L, "ccui.ListView");

    return 1;
}

static int luaopen_cocos2d_ui_LoadingBar_Direction(lua_State *L)
{
    oluacls_class(L, "ccui.LoadingBar.Direction", nullptr);
    oluacls_const_integer(L, "LEFT", (lua_Integer)cocos2d::ui::LoadingBar::Direction::LEFT);
    oluacls_const_integer(L, "RIGHT", (lua_Integer)cocos2d::ui::LoadingBar::Direction::RIGHT);

    olua_registerluatype<cocos2d::ui::LoadingBar::Direction>(L, "ccui.LoadingBar.Direction");

    return 1;
}

static int _cocos2d_ui_LoadingBar___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::ui::LoadingBar *)olua_toobj(L, 1, "ccui.LoadingBar");
    olua_push_cppobj(L, self, "ccui.LoadingBar");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_ui_LoadingBar_create1(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::ui::LoadingBar *create()
    cocos2d::ui::LoadingBar *ret = (cocos2d::ui::LoadingBar *)cocos2d::ui::LoadingBar::create();
    int num_ret = olua_push_cppobj(L, ret, "ccui.LoadingBar");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_LoadingBar_create2(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** textureName */
    lua_Number arg2 = 0;       /** percentage */

    olua_check_std_string(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);

    // static cocos2d::ui::LoadingBar *create(const std::string &textureName, @optional float percentage)
    cocos2d::ui::LoadingBar *ret = (cocos2d::ui::LoadingBar *)cocos2d::ui::LoadingBar::create(arg1, (float)arg2);
    int num_ret = olua_push_cppobj(L, ret, "ccui.LoadingBar");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_LoadingBar_create3(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** textureName */
    lua_Unsigned arg2 = 0;       /** texType */
    lua_Number arg3 = 0;       /** percentage */

    olua_check_std_string(L, 1, &arg1);
    olua_check_uint(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);

    // static cocos2d::ui::LoadingBar *create(const std::string &textureName, cocos2d::ui::Widget::TextureResType texType, @optional float percentage)
    cocos2d::ui::LoadingBar *ret = (cocos2d::ui::LoadingBar *)cocos2d::ui::LoadingBar::create(arg1, (cocos2d::ui::Widget::TextureResType)arg2, (float)arg3);
    int num_ret = olua_push_cppobj(L, ret, "ccui.LoadingBar");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_LoadingBar_create4(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** textureName */

    olua_check_std_string(L, 1, &arg1);

    // static cocos2d::ui::LoadingBar *create(const std::string &textureName, @optional float percentage)
    cocos2d::ui::LoadingBar *ret = (cocos2d::ui::LoadingBar *)cocos2d::ui::LoadingBar::create(arg1);
    int num_ret = olua_push_cppobj(L, ret, "ccui.LoadingBar");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_LoadingBar_create5(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** textureName */
    lua_Unsigned arg2 = 0;       /** texType */

    olua_check_std_string(L, 1, &arg1);
    olua_check_uint(L, 2, &arg2);

    // static cocos2d::ui::LoadingBar *create(const std::string &textureName, cocos2d::ui::Widget::TextureResType texType, @optional float percentage)
    cocos2d::ui::LoadingBar *ret = (cocos2d::ui::LoadingBar *)cocos2d::ui::LoadingBar::create(arg1, (cocos2d::ui::Widget::TextureResType)arg2);
    int num_ret = olua_push_cppobj(L, ret, "ccui.LoadingBar");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_LoadingBar_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // static cocos2d::ui::LoadingBar *create()
        return _cocos2d_ui_LoadingBar_create1(L);
    }

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 1))) {
            // static cocos2d::ui::LoadingBar *create(const std::string &textureName, @optional float percentage)
            return _cocos2d_ui_LoadingBar_create4(L);
        // }
    }

    if (num_args == 2) {
        if ((olua_is_std_string(L, 1)) && (olua_is_number(L, 2))) {
            // static cocos2d::ui::LoadingBar *create(const std::string &textureName, @optional float percentage)
            return _cocos2d_ui_LoadingBar_create2(L);
        }

        // if ((olua_is_std_string(L, 1)) && (olua_is_uint(L, 2))) {
            // static cocos2d::ui::LoadingBar *create(const std::string &textureName, cocos2d::ui::Widget::TextureResType texType, @optional float percentage)
            return _cocos2d_ui_LoadingBar_create5(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_std_string(L, 1)) && (olua_is_uint(L, 2)) && (olua_is_number(L, 3))) {
            // static cocos2d::ui::LoadingBar *create(const std::string &textureName, cocos2d::ui::Widget::TextureResType texType, @optional float percentage)
            return _cocos2d_ui_LoadingBar_create3(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::LoadingBar::create' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ui_LoadingBar_createInstance(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::Ref *createInstance()
    cocos2d::Ref *ret = (cocos2d::Ref *)cocos2d::ui::LoadingBar::createInstance();
    int num_ret = olua_push_cppobj(L, ret, "cc.Ref");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_LoadingBar_getCapInsets(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LoadingBar *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.LoadingBar");

    // const cocos2d::Rect &getCapInsets()
    const cocos2d::Rect &ret = (const cocos2d::Rect &)self->getCapInsets();
    int num_ret = manual_olua_push_cocos2d_Rect(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_LoadingBar_getDirection(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LoadingBar *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.LoadingBar");

    // cocos2d::ui::LoadingBar::Direction getDirection()
    cocos2d::ui::LoadingBar::Direction ret = (cocos2d::ui::LoadingBar::Direction)self->getDirection();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_LoadingBar_getPercent(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LoadingBar *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.LoadingBar");

    // float getPercent()
    float ret = (float)self->getPercent();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_LoadingBar_getRenderFile(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LoadingBar *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.LoadingBar");

    // cocos2d::ResourceData getRenderFile()
    cocos2d::ResourceData ret = (cocos2d::ResourceData)self->getRenderFile();
    int num_ret = auto_olua_push_cocos2d_ResourceData(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_LoadingBar_isScale9Enabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LoadingBar *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.LoadingBar");

    // bool isScale9Enabled()
    bool ret = (bool)self->isScale9Enabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_LoadingBar_loadTexture1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LoadingBar *self = nullptr;
    std::string arg1;       /** texture */
    lua_Unsigned arg2 = 0;       /** texType */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.LoadingBar");
    olua_check_std_string(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // void loadTexture(const std::string &texture, @optional cocos2d::ui::Widget::TextureResType texType)
    self->loadTexture(arg1, (cocos2d::ui::Widget::TextureResType)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_LoadingBar_loadTexture2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LoadingBar *self = nullptr;
    std::string arg1;       /** texture */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.LoadingBar");
    olua_check_std_string(L, 2, &arg1);

    // void loadTexture(const std::string &texture, @optional cocos2d::ui::Widget::TextureResType texType)
    self->loadTexture(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_LoadingBar_loadTexture(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 2))) {
            // void loadTexture(const std::string &texture, @optional cocos2d::ui::Widget::TextureResType texType)
            return _cocos2d_ui_LoadingBar_loadTexture2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_uint(L, 3))) {
            // void loadTexture(const std::string &texture, @optional cocos2d::ui::Widget::TextureResType texType)
            return _cocos2d_ui_LoadingBar_loadTexture1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::LoadingBar::loadTexture' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ui_LoadingBar_new(lua_State *L)
{
    olua_startinvoke(L);

    // LoadingBar()
    cocos2d::ui::LoadingBar *ret = (cocos2d::ui::LoadingBar *)new cocos2d::ui::LoadingBar();
    int num_ret = olua_push_cppobj(L, ret, "ccui.LoadingBar");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_LoadingBar_setCapInsets(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LoadingBar *self = nullptr;
    cocos2d::Rect arg1;       /** capInsets */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.LoadingBar");
    manual_olua_check_cocos2d_Rect(L, 2, &arg1);

    // void setCapInsets(const cocos2d::Rect &capInsets)
    self->setCapInsets(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_LoadingBar_setDirection(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LoadingBar *self = nullptr;
    lua_Unsigned arg1 = 0;       /** direction */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.LoadingBar");
    olua_check_uint(L, 2, &arg1);

    // void setDirection(cocos2d::ui::LoadingBar::Direction direction)
    self->setDirection((cocos2d::ui::LoadingBar::Direction)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_LoadingBar_setPercent(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LoadingBar *self = nullptr;
    lua_Number arg1 = 0;       /** percent */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.LoadingBar");
    olua_check_number(L, 2, &arg1);

    // void setPercent(float percent)
    self->setPercent((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_LoadingBar_setScale9Enabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LoadingBar *self = nullptr;
    bool arg1 = false;       /** enabled */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.LoadingBar");
    olua_check_bool(L, 2, &arg1);

    // void setScale9Enabled(bool enabled)
    self->setScale9Enabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_ui_LoadingBar(lua_State *L)
{
    oluacls_class(L, "ccui.LoadingBar", "ccui.Widget");
    oluacls_func(L, "__move", _cocos2d_ui_LoadingBar___move);
    oluacls_func(L, "create", _cocos2d_ui_LoadingBar_create);
    oluacls_func(L, "createInstance", _cocos2d_ui_LoadingBar_createInstance);
    oluacls_func(L, "getCapInsets", _cocos2d_ui_LoadingBar_getCapInsets);
    oluacls_func(L, "getDirection", _cocos2d_ui_LoadingBar_getDirection);
    oluacls_func(L, "getPercent", _cocos2d_ui_LoadingBar_getPercent);
    oluacls_func(L, "getRenderFile", _cocos2d_ui_LoadingBar_getRenderFile);
    oluacls_func(L, "isScale9Enabled", _cocos2d_ui_LoadingBar_isScale9Enabled);
    oluacls_func(L, "loadTexture", _cocos2d_ui_LoadingBar_loadTexture);
    oluacls_func(L, "new", _cocos2d_ui_LoadingBar_new);
    oluacls_func(L, "setCapInsets", _cocos2d_ui_LoadingBar_setCapInsets);
    oluacls_func(L, "setDirection", _cocos2d_ui_LoadingBar_setDirection);
    oluacls_func(L, "setPercent", _cocos2d_ui_LoadingBar_setPercent);
    oluacls_func(L, "setScale9Enabled", _cocos2d_ui_LoadingBar_setScale9Enabled);
    oluacls_prop(L, "capInsets", _cocos2d_ui_LoadingBar_getCapInsets, _cocos2d_ui_LoadingBar_setCapInsets);
    oluacls_prop(L, "direction", _cocos2d_ui_LoadingBar_getDirection, _cocos2d_ui_LoadingBar_setDirection);
    oluacls_prop(L, "percent", _cocos2d_ui_LoadingBar_getPercent, _cocos2d_ui_LoadingBar_setPercent);
    oluacls_prop(L, "renderFile", _cocos2d_ui_LoadingBar_getRenderFile, nullptr);
    oluacls_prop(L, "scale9Enabled", _cocos2d_ui_LoadingBar_isScale9Enabled, _cocos2d_ui_LoadingBar_setScale9Enabled);

    olua_registerluatype<cocos2d::ui::LoadingBar>(L, "ccui.LoadingBar");

    return 1;
}

static int luaopen_cocos2d_ui_PageView_EventType(lua_State *L)
{
    oluacls_class(L, "ccui.PageView.EventType", nullptr);
    oluacls_const_integer(L, "TURNING", (lua_Integer)cocos2d::ui::PageView::EventType::TURNING);

    olua_registerluatype<cocos2d::ui::PageView::EventType>(L, "ccui.PageView.EventType");

    return 1;
}

static int luaopen_cocos2d_ui_PageView_TouchDirection(lua_State *L)
{
    oluacls_class(L, "ccui.PageView.TouchDirection", nullptr);
    oluacls_const_integer(L, "DOWN", (lua_Integer)cocos2d::ui::PageView::TouchDirection::DOWN);
    oluacls_const_integer(L, "LEFT", (lua_Integer)cocos2d::ui::PageView::TouchDirection::LEFT);
    oluacls_const_integer(L, "RIGHT", (lua_Integer)cocos2d::ui::PageView::TouchDirection::RIGHT);
    oluacls_const_integer(L, "UP", (lua_Integer)cocos2d::ui::PageView::TouchDirection::UP);

    olua_registerluatype<cocos2d::ui::PageView::TouchDirection>(L, "ccui.PageView.TouchDirection");

    return 1;
}

static int _cocos2d_ui_PageView___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::ui::PageView *)olua_toobj(L, 1, "ccui.PageView");
    olua_push_cppobj(L, self, "ccui.PageView");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_ui_PageView_addEventListener(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::PageView *self = nullptr;
    std::function<void(cocos2d::Ref *, cocos2d::ui::PageView::EventType)> arg1;       /** callback */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.PageView");

    if (olua_is_std_function(L, 2)) {
        void *callback_store_obj = (void *)self;
        std::string tag = "PageViewCallback";
        std::string func = olua_setcallback(L, callback_store_obj, tag.c_str(), 2, OLUA_TAG_REPLACE);
        lua_State *MT = olua_mainthread();
        arg1 = [callback_store_obj, func, MT](cocos2d::Ref *arg1, cocos2d::ui::PageView::EventType arg2) {
            lua_State *L = olua_mainthread();

            if (MT == L) {
                int top = lua_gettop(L);
                olua_push_cppobj(L, arg1, "cc.Ref");
                olua_push_uint(L, (lua_Unsigned)arg2);

                olua_callback(L, callback_store_obj, func.c_str(), 2);

                lua_settop(L, top);
            }
        };
    } else {
        void *callback_store_obj = (void *)self;
        std::string tag = "PageViewCallback";
        olua_removecallback(L, callback_store_obj, tag.c_str(), OLUA_TAG_SUBEQUAL);
        arg1 = nullptr;
    }

    // void addEventListener(@nullable const std::function<void(Ref*, PageView::EventType)>& callback)
    self->addEventListener(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_PageView_addPage(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::PageView *self = nullptr;
    cocos2d::ui::Widget *arg1 = nullptr;       /** page */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.PageView");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccui.Widget");

    // void addPage(@addref(children |) cocos2d::ui::Widget *page)
    self->addPage(arg1);

    // inject code after call
    olua_addref(L, 1, "children", 2, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_PageView_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::ui::PageView *create()
    cocos2d::ui::PageView *ret = (cocos2d::ui::PageView *)cocos2d::ui::PageView::create();
    int num_ret = olua_push_cppobj(L, ret, "ccui.PageView");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_PageView_createInstance(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::Ref *createInstance()
    cocos2d::Ref *ret = (cocos2d::Ref *)cocos2d::ui::PageView::createInstance();
    int num_ret = olua_push_cppobj(L, ret, "cc.Ref");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_PageView_getCurrentPageIndex(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::PageView *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.PageView");

    // ssize_t getCurrentPageIndex()
    ssize_t ret = (ssize_t)self->getCurrentPageIndex();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_PageView_getIndicatorEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::PageView *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.PageView");

    // bool getIndicatorEnabled()
    bool ret = (bool)self->getIndicatorEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_PageView_getIndicatorIndexNodesColor(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::PageView *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.PageView");

    // const cocos2d::Color3B &getIndicatorIndexNodesColor()
    const cocos2d::Color3B &ret = (const cocos2d::Color3B &)self->getIndicatorIndexNodesColor();
    int num_ret = manual_olua_push_cocos2d_Color3B(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_PageView_getIndicatorIndexNodesOpacity(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::PageView *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.PageView");

    // uint8_t getIndicatorIndexNodesOpacity()
    uint8_t ret = (uint8_t)self->getIndicatorIndexNodesOpacity();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_PageView_getIndicatorIndexNodesScale(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::PageView *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.PageView");

    // float getIndicatorIndexNodesScale()
    float ret = (float)self->getIndicatorIndexNodesScale();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_PageView_getIndicatorPosition(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::PageView *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.PageView");

    // const cocos2d::Vec2 &getIndicatorPosition()
    const cocos2d::Vec2 &ret = (const cocos2d::Vec2 &)self->getIndicatorPosition();
    int num_ret = auto_olua_push_cocos2d_Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_PageView_getIndicatorPositionAsAnchorPoint(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::PageView *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.PageView");

    // const cocos2d::Vec2 &getIndicatorPositionAsAnchorPoint()
    const cocos2d::Vec2 &ret = (const cocos2d::Vec2 &)self->getIndicatorPositionAsAnchorPoint();
    int num_ret = auto_olua_push_cocos2d_Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_PageView_getIndicatorSelectedIndexColor(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::PageView *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.PageView");

    // const cocos2d::Color3B &getIndicatorSelectedIndexColor()
    const cocos2d::Color3B &ret = (const cocos2d::Color3B &)self->getIndicatorSelectedIndexColor();
    int num_ret = manual_olua_push_cocos2d_Color3B(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_PageView_getIndicatorSelectedIndexOpacity(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::PageView *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.PageView");

    // uint8_t getIndicatorSelectedIndexOpacity()
    uint8_t ret = (uint8_t)self->getIndicatorSelectedIndexOpacity();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_PageView_getIndicatorSpaceBetweenIndexNodes(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::PageView *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.PageView");

    // float getIndicatorSpaceBetweenIndexNodes()
    float ret = (float)self->getIndicatorSpaceBetweenIndexNodes();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_PageView_insertPage(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::PageView *self = nullptr;
    cocos2d::ui::Widget *arg1 = nullptr;       /** page */
    lua_Integer arg2 = 0;       /** idx */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.PageView");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccui.Widget");
    olua_check_int(L, 3, &arg2);

    // void insertPage(@addref(children |) cocos2d::ui::Widget *page, int idx)
    self->insertPage(arg1, (int)arg2);

    // inject code after call
    olua_addref(L, 1, "children", 2, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_PageView_new(lua_State *L)
{
    olua_startinvoke(L);

    // PageView()
    cocos2d::ui::PageView *ret = (cocos2d::ui::PageView *)new cocos2d::ui::PageView();
    int num_ret = olua_push_cppobj(L, ret, "ccui.PageView");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_PageView_removeAllPages(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::PageView *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.PageView");

    // @delref(children *) void removeAllPages()
    self->removeAllPages();

    // inject code after call
    olua_delallrefs(L, 1, "children");

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_PageView_removePage(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::PageView *self = nullptr;
    cocos2d::ui::Widget *arg1 = nullptr;       /** page */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.PageView");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccui.Widget");

    // void removePage(@delref(children |) cocos2d::ui::Widget *page)
    self->removePage(arg1);

    // inject code after call
    olua_delref(L, 1, "children", 2, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_PageView_removePageAtIndex(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::PageView *self = nullptr;
    lua_Integer arg1 = 0;       /** index */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.PageView");
    olua_check_int(L, 2, &arg1);

    // inject code before call
    olua_startcmpdelref(L, 1, "children");

    // @delref(children ~) void removePageAtIndex(ssize_t index)
    self->removePageAtIndex((ssize_t)arg1);

    // inject code after call
    olua_endcmpdelref(L, 1, "children");

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_PageView_scrollToItem1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::PageView *self = nullptr;
    lua_Integer arg1 = 0;       /** itemIndex */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.PageView");
    olua_check_int(L, 2, &arg1);

    // void scrollToItem(ssize_t itemIndex)
    self->scrollToItem((ssize_t)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_PageView_scrollToItem2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::PageView *self = nullptr;
    lua_Integer arg1 = 0;       /** idx */
    lua_Number arg2 = 0;       /** time */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.PageView");
    olua_check_int(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);

    // void scrollToItem(ssize_t idx, float time)
    self->scrollToItem((ssize_t)arg1, (float)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_PageView_scrollToItem(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_int(L, 2))) {
            // void scrollToItem(ssize_t itemIndex)
            return _cocos2d_ui_PageView_scrollToItem1(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_int(L, 2)) && (olua_is_number(L, 3))) {
            // void scrollToItem(ssize_t idx, float time)
            return _cocos2d_ui_PageView_scrollToItem2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::PageView::scrollToItem' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ui_PageView_scrollToPage1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::PageView *self = nullptr;
    lua_Integer arg1 = 0;       /** idx */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.PageView");
    olua_check_int(L, 2, &arg1);

    // void scrollToPage(ssize_t idx)
    self->scrollToPage((ssize_t)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_PageView_scrollToPage2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::PageView *self = nullptr;
    lua_Integer arg1 = 0;       /** idx */
    lua_Number arg2 = 0;       /** time */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.PageView");
    olua_check_int(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);

    // void scrollToPage(ssize_t idx, float time)
    self->scrollToPage((ssize_t)arg1, (float)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_PageView_scrollToPage(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_int(L, 2))) {
            // void scrollToPage(ssize_t idx)
            return _cocos2d_ui_PageView_scrollToPage1(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_int(L, 2)) && (olua_is_number(L, 3))) {
            // void scrollToPage(ssize_t idx, float time)
            return _cocos2d_ui_PageView_scrollToPage2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::PageView::scrollToPage' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ui_PageView_setAutoScrollStopEpsilon(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::PageView *self = nullptr;
    lua_Number arg1 = 0;       /** epsilon */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.PageView");
    olua_check_number(L, 2, &arg1);

    // void setAutoScrollStopEpsilon(float epsilon)
    self->setAutoScrollStopEpsilon((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_PageView_setCurrentPageIndex(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::PageView *self = nullptr;
    lua_Integer arg1 = 0;       /** index */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.PageView");
    olua_check_int(L, 2, &arg1);

    // void setCurrentPageIndex(ssize_t index)
    self->setCurrentPageIndex((ssize_t)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_PageView_setIndicatorEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::PageView *self = nullptr;
    bool arg1 = false;       /** enabled */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.PageView");
    olua_check_bool(L, 2, &arg1);

    // void setIndicatorEnabled(bool enabled)
    self->setIndicatorEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_PageView_setIndicatorIndexNodesColor(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::PageView *self = nullptr;
    cocos2d::Color3B arg1;       /** color */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.PageView");
    manual_olua_check_cocos2d_Color3B(L, 2, &arg1);

    // void setIndicatorIndexNodesColor(const cocos2d::Color3B &color)
    self->setIndicatorIndexNodesColor(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_PageView_setIndicatorIndexNodesOpacity(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::PageView *self = nullptr;
    lua_Unsigned arg1 = 0;       /** opacity */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.PageView");
    olua_check_uint(L, 2, &arg1);

    // void setIndicatorIndexNodesOpacity(uint8_t opacity)
    self->setIndicatorIndexNodesOpacity((uint8_t)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_PageView_setIndicatorIndexNodesScale(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::PageView *self = nullptr;
    lua_Number arg1 = 0;       /** indexNodesScale */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.PageView");
    olua_check_number(L, 2, &arg1);

    // void setIndicatorIndexNodesScale(float indexNodesScale)
    self->setIndicatorIndexNodesScale((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_PageView_setIndicatorIndexNodesTexture1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::PageView *self = nullptr;
    std::string arg1;       /** texName */
    lua_Unsigned arg2 = 0;       /** texType */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.PageView");
    olua_check_std_string(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // void setIndicatorIndexNodesTexture(const std::string &texName, @optional Widget::TextureResType texType)
    self->setIndicatorIndexNodesTexture(arg1, (cocos2d::ui::Widget::TextureResType)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_PageView_setIndicatorIndexNodesTexture2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::PageView *self = nullptr;
    std::string arg1;       /** texName */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.PageView");
    olua_check_std_string(L, 2, &arg1);

    // void setIndicatorIndexNodesTexture(const std::string &texName, @optional Widget::TextureResType texType)
    self->setIndicatorIndexNodesTexture(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_PageView_setIndicatorIndexNodesTexture(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 2))) {
            // void setIndicatorIndexNodesTexture(const std::string &texName, @optional Widget::TextureResType texType)
            return _cocos2d_ui_PageView_setIndicatorIndexNodesTexture2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_uint(L, 3))) {
            // void setIndicatorIndexNodesTexture(const std::string &texName, @optional Widget::TextureResType texType)
            return _cocos2d_ui_PageView_setIndicatorIndexNodesTexture1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::PageView::setIndicatorIndexNodesTexture' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ui_PageView_setIndicatorPosition(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::PageView *self = nullptr;
    cocos2d::Vec2 arg1;       /** position */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.PageView");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);

    // void setIndicatorPosition(const cocos2d::Vec2 &position)
    self->setIndicatorPosition(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_PageView_setIndicatorPositionAsAnchorPoint(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::PageView *self = nullptr;
    cocos2d::Vec2 arg1;       /** positionAsAnchorPoint */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.PageView");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);

    // void setIndicatorPositionAsAnchorPoint(const cocos2d::Vec2 &positionAsAnchorPoint)
    self->setIndicatorPositionAsAnchorPoint(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_PageView_setIndicatorSelectedIndexColor(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::PageView *self = nullptr;
    cocos2d::Color3B arg1;       /** color */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.PageView");
    manual_olua_check_cocos2d_Color3B(L, 2, &arg1);

    // void setIndicatorSelectedIndexColor(const cocos2d::Color3B &color)
    self->setIndicatorSelectedIndexColor(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_PageView_setIndicatorSelectedIndexOpacity(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::PageView *self = nullptr;
    lua_Unsigned arg1 = 0;       /** opacity */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.PageView");
    olua_check_uint(L, 2, &arg1);

    // void setIndicatorSelectedIndexOpacity(uint8_t opacity)
    self->setIndicatorSelectedIndexOpacity((uint8_t)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_PageView_setIndicatorSpaceBetweenIndexNodes(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::PageView *self = nullptr;
    lua_Number arg1 = 0;       /** spaceBetweenIndexNodes */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.PageView");
    olua_check_number(L, 2, &arg1);

    // void setIndicatorSpaceBetweenIndexNodes(float spaceBetweenIndexNodes)
    self->setIndicatorSpaceBetweenIndexNodes((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_ui_PageView(lua_State *L)
{
    oluacls_class(L, "ccui.PageView", "ccui.ListView");
    oluacls_func(L, "__move", _cocos2d_ui_PageView___move);
    oluacls_func(L, "addEventListener", _cocos2d_ui_PageView_addEventListener);
    oluacls_func(L, "addPage", _cocos2d_ui_PageView_addPage);
    oluacls_func(L, "addPageViewEventListener", _cocos2d_ui_PageView_addEventListener);
    oluacls_func(L, "create", _cocos2d_ui_PageView_create);
    oluacls_func(L, "createInstance", _cocos2d_ui_PageView_createInstance);
    oluacls_func(L, "getCurrentPageIndex", _cocos2d_ui_PageView_getCurrentPageIndex);
    oluacls_func(L, "getIndicatorEnabled", _cocos2d_ui_PageView_getIndicatorEnabled);
    oluacls_func(L, "getIndicatorIndexNodesColor", _cocos2d_ui_PageView_getIndicatorIndexNodesColor);
    oluacls_func(L, "getIndicatorIndexNodesOpacity", _cocos2d_ui_PageView_getIndicatorIndexNodesOpacity);
    oluacls_func(L, "getIndicatorIndexNodesScale", _cocos2d_ui_PageView_getIndicatorIndexNodesScale);
    oluacls_func(L, "getIndicatorPosition", _cocos2d_ui_PageView_getIndicatorPosition);
    oluacls_func(L, "getIndicatorPositionAsAnchorPoint", _cocos2d_ui_PageView_getIndicatorPositionAsAnchorPoint);
    oluacls_func(L, "getIndicatorSelectedIndexColor", _cocos2d_ui_PageView_getIndicatorSelectedIndexColor);
    oluacls_func(L, "getIndicatorSelectedIndexOpacity", _cocos2d_ui_PageView_getIndicatorSelectedIndexOpacity);
    oluacls_func(L, "getIndicatorSpaceBetweenIndexNodes", _cocos2d_ui_PageView_getIndicatorSpaceBetweenIndexNodes);
    oluacls_func(L, "insertPage", _cocos2d_ui_PageView_insertPage);
    oluacls_func(L, "new", _cocos2d_ui_PageView_new);
    oluacls_func(L, "removeAllPages", _cocos2d_ui_PageView_removeAllPages);
    oluacls_func(L, "removePage", _cocos2d_ui_PageView_removePage);
    oluacls_func(L, "removePageAtIndex", _cocos2d_ui_PageView_removePageAtIndex);
    oluacls_func(L, "scrollToItem", _cocos2d_ui_PageView_scrollToItem);
    oluacls_func(L, "scrollToPage", _cocos2d_ui_PageView_scrollToPage);
    oluacls_func(L, "setAutoScrollStopEpsilon", _cocos2d_ui_PageView_setAutoScrollStopEpsilon);
    oluacls_func(L, "setCurrentPageIndex", _cocos2d_ui_PageView_setCurrentPageIndex);
    oluacls_func(L, "setIndicatorEnabled", _cocos2d_ui_PageView_setIndicatorEnabled);
    oluacls_func(L, "setIndicatorIndexNodesColor", _cocos2d_ui_PageView_setIndicatorIndexNodesColor);
    oluacls_func(L, "setIndicatorIndexNodesOpacity", _cocos2d_ui_PageView_setIndicatorIndexNodesOpacity);
    oluacls_func(L, "setIndicatorIndexNodesScale", _cocos2d_ui_PageView_setIndicatorIndexNodesScale);
    oluacls_func(L, "setIndicatorIndexNodesTexture", _cocos2d_ui_PageView_setIndicatorIndexNodesTexture);
    oluacls_func(L, "setIndicatorPosition", _cocos2d_ui_PageView_setIndicatorPosition);
    oluacls_func(L, "setIndicatorPositionAsAnchorPoint", _cocos2d_ui_PageView_setIndicatorPositionAsAnchorPoint);
    oluacls_func(L, "setIndicatorSelectedIndexColor", _cocos2d_ui_PageView_setIndicatorSelectedIndexColor);
    oluacls_func(L, "setIndicatorSelectedIndexOpacity", _cocos2d_ui_PageView_setIndicatorSelectedIndexOpacity);
    oluacls_func(L, "setIndicatorSpaceBetweenIndexNodes", _cocos2d_ui_PageView_setIndicatorSpaceBetweenIndexNodes);
    oluacls_prop(L, "currentPageIndex", _cocos2d_ui_PageView_getCurrentPageIndex, _cocos2d_ui_PageView_setCurrentPageIndex);
    oluacls_prop(L, "indicatorEnabled", _cocos2d_ui_PageView_getIndicatorEnabled, _cocos2d_ui_PageView_setIndicatorEnabled);
    oluacls_prop(L, "indicatorIndexNodesColor", _cocos2d_ui_PageView_getIndicatorIndexNodesColor, _cocos2d_ui_PageView_setIndicatorIndexNodesColor);
    oluacls_prop(L, "indicatorIndexNodesOpacity", _cocos2d_ui_PageView_getIndicatorIndexNodesOpacity, _cocos2d_ui_PageView_setIndicatorIndexNodesOpacity);
    oluacls_prop(L, "indicatorIndexNodesScale", _cocos2d_ui_PageView_getIndicatorIndexNodesScale, _cocos2d_ui_PageView_setIndicatorIndexNodesScale);
    oluacls_prop(L, "indicatorPosition", _cocos2d_ui_PageView_getIndicatorPosition, _cocos2d_ui_PageView_setIndicatorPosition);
    oluacls_prop(L, "indicatorPositionAsAnchorPoint", _cocos2d_ui_PageView_getIndicatorPositionAsAnchorPoint, _cocos2d_ui_PageView_setIndicatorPositionAsAnchorPoint);
    oluacls_prop(L, "indicatorSelectedIndexColor", _cocos2d_ui_PageView_getIndicatorSelectedIndexColor, _cocos2d_ui_PageView_setIndicatorSelectedIndexColor);
    oluacls_prop(L, "indicatorSelectedIndexOpacity", _cocos2d_ui_PageView_getIndicatorSelectedIndexOpacity, _cocos2d_ui_PageView_setIndicatorSelectedIndexOpacity);
    oluacls_prop(L, "indicatorSpaceBetweenIndexNodes", _cocos2d_ui_PageView_getIndicatorSpaceBetweenIndexNodes, _cocos2d_ui_PageView_setIndicatorSpaceBetweenIndexNodes);

    olua_registerluatype<cocos2d::ui::PageView>(L, "ccui.PageView");

    return 1;
}

static int luaopen_cocos2d_ui_RichElement_Type(lua_State *L)
{
    oluacls_class(L, "ccui.RichElement.Type", nullptr);
    oluacls_const_integer(L, "CUSTOM", (lua_Integer)cocos2d::ui::RichElement::Type::CUSTOM);
    oluacls_const_integer(L, "IMAGE", (lua_Integer)cocos2d::ui::RichElement::Type::IMAGE);
    oluacls_const_integer(L, "NEWLINE", (lua_Integer)cocos2d::ui::RichElement::Type::NEWLINE);
    oluacls_const_integer(L, "TEXT", (lua_Integer)cocos2d::ui::RichElement::Type::TEXT);

    olua_registerluatype<cocos2d::ui::RichElement::Type>(L, "ccui.RichElement.Type");

    return 1;
}

static int _cocos2d_ui_RichElement___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::ui::RichElement *)olua_toobj(L, 1, "ccui.RichElement");
    olua_push_cppobj(L, self, "ccui.RichElement");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_ui_RichElement_equalType(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichElement *self = nullptr;
    lua_Unsigned arg1 = 0;       /** type */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RichElement");
    olua_check_uint(L, 2, &arg1);

    // bool equalType(cocos2d::ui::RichElement::Type type)
    bool ret = (bool)self->equalType((cocos2d::ui::RichElement::Type)arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_RichElement_init(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichElement *self = nullptr;
    lua_Integer arg1 = 0;       /** tag */
    cocos2d::Color3B arg2;       /** color */
    lua_Unsigned arg3 = 0;       /** opacity */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RichElement");
    olua_check_int(L, 2, &arg1);
    manual_olua_check_cocos2d_Color3B(L, 3, &arg2);
    olua_check_uint(L, 4, &arg3);

    // bool init(int tag, const cocos2d::Color3B &color, uint8_t opacity)
    bool ret = (bool)self->init((int)arg1, arg2, (uint8_t)arg3);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_RichElement_new(lua_State *L)
{
    olua_startinvoke(L);

    // RichElement()
    cocos2d::ui::RichElement *ret = (cocos2d::ui::RichElement *)new cocos2d::ui::RichElement();
    int num_ret = olua_push_cppobj(L, ret, "ccui.RichElement");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_RichElement_setColor(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichElement *self = nullptr;
    cocos2d::Color3B arg1;       /** color */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RichElement");
    manual_olua_check_cocos2d_Color3B(L, 2, &arg1);

    // void setColor(const cocos2d::Color3B &color)
    self->setColor(arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_ui_RichElement(lua_State *L)
{
    oluacls_class(L, "ccui.RichElement", "cc.Ref");
    oluacls_func(L, "__move", _cocos2d_ui_RichElement___move);
    oluacls_func(L, "equalType", _cocos2d_ui_RichElement_equalType);
    oluacls_func(L, "init", _cocos2d_ui_RichElement_init);
    oluacls_func(L, "new", _cocos2d_ui_RichElement_new);
    oluacls_func(L, "setColor", _cocos2d_ui_RichElement_setColor);

    olua_registerluatype<cocos2d::ui::RichElement>(L, "ccui.RichElement");

    return 1;
}

static int _cocos2d_ui_RichElementText___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::ui::RichElementText *)olua_toobj(L, 1, "ccui.RichElementText");
    olua_push_cppobj(L, self, "ccui.RichElementText");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_ui_RichElementText_create1(lua_State *L)
{
    olua_startinvoke(L);

    lua_Integer arg1 = 0;       /** tag */
    cocos2d::Color3B arg2;       /** color */
    lua_Unsigned arg3 = 0;       /** opacity */
    std::string arg4;       /** text */
    std::string arg5;       /** fontName */
    lua_Number arg6 = 0;       /** fontSize */
    lua_Unsigned arg7 = 0;       /** flags */
    std::string arg8;       /** url */
    cocos2d::Color3B arg9;       /** outlineColor */
    lua_Integer arg10 = 0;       /** outlineSize */
    cocos2d::Color3B arg11;       /** shadowColor */
    cocos2d::Size arg12;       /** shadowOffset */
    lua_Integer arg13 = 0;       /** shadowBlurRadius */
    cocos2d::Color3B arg14;       /** glowColor */

    olua_check_int(L, 1, &arg1);
    manual_olua_check_cocos2d_Color3B(L, 2, &arg2);
    olua_check_uint(L, 3, &arg3);
    olua_check_std_string(L, 4, &arg4);
    olua_check_std_string(L, 5, &arg5);
    olua_check_number(L, 6, &arg6);
    olua_check_uint(L, 7, &arg7);
    olua_check_std_string(L, 8, &arg8);
    manual_olua_check_cocos2d_Color3B(L, 9, &arg9);
    olua_check_int(L, 10, &arg10);
    manual_olua_check_cocos2d_Color3B(L, 11, &arg11);
    auto_olua_check_cocos2d_Size(L, 12, &arg12);
    olua_check_int(L, 13, &arg13);
    manual_olua_check_cocos2d_Color3B(L, 14, &arg14);

    // static cocos2d::ui::RichElementText *create(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &text, const std::string &fontName, float fontSize, @optional uint32_t flags, @optional const std::string &url, @optional const cocos2d::Color3B &outlineColor, @optional int outlineSize, @optional const cocos2d::Color3B &shadowColor, @optional const cocos2d::Size &shadowOffset, @optional int shadowBlurRadius, @optional const cocos2d::Color3B &glowColor)
    cocos2d::ui::RichElementText *ret = (cocos2d::ui::RichElementText *)cocos2d::ui::RichElementText::create((int)arg1, arg2, (uint8_t)arg3, arg4, arg5, (float)arg6, (uint32_t)arg7, arg8, arg9, (int)arg10, arg11, arg12, (int)arg13, arg14);
    int num_ret = olua_push_cppobj(L, ret, "ccui.RichElementText");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_RichElementText_create2(lua_State *L)
{
    olua_startinvoke(L);

    lua_Integer arg1 = 0;       /** tag */
    cocos2d::Color3B arg2;       /** color */
    lua_Unsigned arg3 = 0;       /** opacity */
    std::string arg4;       /** text */
    std::string arg5;       /** fontName */
    lua_Number arg6 = 0;       /** fontSize */

    olua_check_int(L, 1, &arg1);
    manual_olua_check_cocos2d_Color3B(L, 2, &arg2);
    olua_check_uint(L, 3, &arg3);
    olua_check_std_string(L, 4, &arg4);
    olua_check_std_string(L, 5, &arg5);
    olua_check_number(L, 6, &arg6);

    // static cocos2d::ui::RichElementText *create(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &text, const std::string &fontName, float fontSize, @optional uint32_t flags, @optional const std::string &url, @optional const cocos2d::Color3B &outlineColor, @optional int outlineSize, @optional const cocos2d::Color3B &shadowColor, @optional const cocos2d::Size &shadowOffset, @optional int shadowBlurRadius, @optional const cocos2d::Color3B &glowColor)
    cocos2d::ui::RichElementText *ret = (cocos2d::ui::RichElementText *)cocos2d::ui::RichElementText::create((int)arg1, arg2, (uint8_t)arg3, arg4, arg5, (float)arg6);
    int num_ret = olua_push_cppobj(L, ret, "ccui.RichElementText");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_RichElementText_create3(lua_State *L)
{
    olua_startinvoke(L);

    lua_Integer arg1 = 0;       /** tag */
    cocos2d::Color3B arg2;       /** color */
    lua_Unsigned arg3 = 0;       /** opacity */
    std::string arg4;       /** text */
    std::string arg5;       /** fontName */
    lua_Number arg6 = 0;       /** fontSize */
    lua_Unsigned arg7 = 0;       /** flags */

    olua_check_int(L, 1, &arg1);
    manual_olua_check_cocos2d_Color3B(L, 2, &arg2);
    olua_check_uint(L, 3, &arg3);
    olua_check_std_string(L, 4, &arg4);
    olua_check_std_string(L, 5, &arg5);
    olua_check_number(L, 6, &arg6);
    olua_check_uint(L, 7, &arg7);

    // static cocos2d::ui::RichElementText *create(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &text, const std::string &fontName, float fontSize, @optional uint32_t flags, @optional const std::string &url, @optional const cocos2d::Color3B &outlineColor, @optional int outlineSize, @optional const cocos2d::Color3B &shadowColor, @optional const cocos2d::Size &shadowOffset, @optional int shadowBlurRadius, @optional const cocos2d::Color3B &glowColor)
    cocos2d::ui::RichElementText *ret = (cocos2d::ui::RichElementText *)cocos2d::ui::RichElementText::create((int)arg1, arg2, (uint8_t)arg3, arg4, arg5, (float)arg6, (uint32_t)arg7);
    int num_ret = olua_push_cppobj(L, ret, "ccui.RichElementText");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_RichElementText_create4(lua_State *L)
{
    olua_startinvoke(L);

    lua_Integer arg1 = 0;       /** tag */
    cocos2d::Color3B arg2;       /** color */
    lua_Unsigned arg3 = 0;       /** opacity */
    std::string arg4;       /** text */
    std::string arg5;       /** fontName */
    lua_Number arg6 = 0;       /** fontSize */
    lua_Unsigned arg7 = 0;       /** flags */
    std::string arg8;       /** url */

    olua_check_int(L, 1, &arg1);
    manual_olua_check_cocos2d_Color3B(L, 2, &arg2);
    olua_check_uint(L, 3, &arg3);
    olua_check_std_string(L, 4, &arg4);
    olua_check_std_string(L, 5, &arg5);
    olua_check_number(L, 6, &arg6);
    olua_check_uint(L, 7, &arg7);
    olua_check_std_string(L, 8, &arg8);

    // static cocos2d::ui::RichElementText *create(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &text, const std::string &fontName, float fontSize, @optional uint32_t flags, @optional const std::string &url, @optional const cocos2d::Color3B &outlineColor, @optional int outlineSize, @optional const cocos2d::Color3B &shadowColor, @optional const cocos2d::Size &shadowOffset, @optional int shadowBlurRadius, @optional const cocos2d::Color3B &glowColor)
    cocos2d::ui::RichElementText *ret = (cocos2d::ui::RichElementText *)cocos2d::ui::RichElementText::create((int)arg1, arg2, (uint8_t)arg3, arg4, arg5, (float)arg6, (uint32_t)arg7, arg8);
    int num_ret = olua_push_cppobj(L, ret, "ccui.RichElementText");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_RichElementText_create5(lua_State *L)
{
    olua_startinvoke(L);

    lua_Integer arg1 = 0;       /** tag */
    cocos2d::Color3B arg2;       /** color */
    lua_Unsigned arg3 = 0;       /** opacity */
    std::string arg4;       /** text */
    std::string arg5;       /** fontName */
    lua_Number arg6 = 0;       /** fontSize */
    lua_Unsigned arg7 = 0;       /** flags */
    std::string arg8;       /** url */
    cocos2d::Color3B arg9;       /** outlineColor */

    olua_check_int(L, 1, &arg1);
    manual_olua_check_cocos2d_Color3B(L, 2, &arg2);
    olua_check_uint(L, 3, &arg3);
    olua_check_std_string(L, 4, &arg4);
    olua_check_std_string(L, 5, &arg5);
    olua_check_number(L, 6, &arg6);
    olua_check_uint(L, 7, &arg7);
    olua_check_std_string(L, 8, &arg8);
    manual_olua_check_cocos2d_Color3B(L, 9, &arg9);

    // static cocos2d::ui::RichElementText *create(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &text, const std::string &fontName, float fontSize, @optional uint32_t flags, @optional const std::string &url, @optional const cocos2d::Color3B &outlineColor, @optional int outlineSize, @optional const cocos2d::Color3B &shadowColor, @optional const cocos2d::Size &shadowOffset, @optional int shadowBlurRadius, @optional const cocos2d::Color3B &glowColor)
    cocos2d::ui::RichElementText *ret = (cocos2d::ui::RichElementText *)cocos2d::ui::RichElementText::create((int)arg1, arg2, (uint8_t)arg3, arg4, arg5, (float)arg6, (uint32_t)arg7, arg8, arg9);
    int num_ret = olua_push_cppobj(L, ret, "ccui.RichElementText");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_RichElementText_create6(lua_State *L)
{
    olua_startinvoke(L);

    lua_Integer arg1 = 0;       /** tag */
    cocos2d::Color3B arg2;       /** color */
    lua_Unsigned arg3 = 0;       /** opacity */
    std::string arg4;       /** text */
    std::string arg5;       /** fontName */
    lua_Number arg6 = 0;       /** fontSize */
    lua_Unsigned arg7 = 0;       /** flags */
    std::string arg8;       /** url */
    cocos2d::Color3B arg9;       /** outlineColor */
    lua_Integer arg10 = 0;       /** outlineSize */

    olua_check_int(L, 1, &arg1);
    manual_olua_check_cocos2d_Color3B(L, 2, &arg2);
    olua_check_uint(L, 3, &arg3);
    olua_check_std_string(L, 4, &arg4);
    olua_check_std_string(L, 5, &arg5);
    olua_check_number(L, 6, &arg6);
    olua_check_uint(L, 7, &arg7);
    olua_check_std_string(L, 8, &arg8);
    manual_olua_check_cocos2d_Color3B(L, 9, &arg9);
    olua_check_int(L, 10, &arg10);

    // static cocos2d::ui::RichElementText *create(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &text, const std::string &fontName, float fontSize, @optional uint32_t flags, @optional const std::string &url, @optional const cocos2d::Color3B &outlineColor, @optional int outlineSize, @optional const cocos2d::Color3B &shadowColor, @optional const cocos2d::Size &shadowOffset, @optional int shadowBlurRadius, @optional const cocos2d::Color3B &glowColor)
    cocos2d::ui::RichElementText *ret = (cocos2d::ui::RichElementText *)cocos2d::ui::RichElementText::create((int)arg1, arg2, (uint8_t)arg3, arg4, arg5, (float)arg6, (uint32_t)arg7, arg8, arg9, (int)arg10);
    int num_ret = olua_push_cppobj(L, ret, "ccui.RichElementText");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_RichElementText_create7(lua_State *L)
{
    olua_startinvoke(L);

    lua_Integer arg1 = 0;       /** tag */
    cocos2d::Color3B arg2;       /** color */
    lua_Unsigned arg3 = 0;       /** opacity */
    std::string arg4;       /** text */
    std::string arg5;       /** fontName */
    lua_Number arg6 = 0;       /** fontSize */
    lua_Unsigned arg7 = 0;       /** flags */
    std::string arg8;       /** url */
    cocos2d::Color3B arg9;       /** outlineColor */
    lua_Integer arg10 = 0;       /** outlineSize */
    cocos2d::Color3B arg11;       /** shadowColor */

    olua_check_int(L, 1, &arg1);
    manual_olua_check_cocos2d_Color3B(L, 2, &arg2);
    olua_check_uint(L, 3, &arg3);
    olua_check_std_string(L, 4, &arg4);
    olua_check_std_string(L, 5, &arg5);
    olua_check_number(L, 6, &arg6);
    olua_check_uint(L, 7, &arg7);
    olua_check_std_string(L, 8, &arg8);
    manual_olua_check_cocos2d_Color3B(L, 9, &arg9);
    olua_check_int(L, 10, &arg10);
    manual_olua_check_cocos2d_Color3B(L, 11, &arg11);

    // static cocos2d::ui::RichElementText *create(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &text, const std::string &fontName, float fontSize, @optional uint32_t flags, @optional const std::string &url, @optional const cocos2d::Color3B &outlineColor, @optional int outlineSize, @optional const cocos2d::Color3B &shadowColor, @optional const cocos2d::Size &shadowOffset, @optional int shadowBlurRadius, @optional const cocos2d::Color3B &glowColor)
    cocos2d::ui::RichElementText *ret = (cocos2d::ui::RichElementText *)cocos2d::ui::RichElementText::create((int)arg1, arg2, (uint8_t)arg3, arg4, arg5, (float)arg6, (uint32_t)arg7, arg8, arg9, (int)arg10, arg11);
    int num_ret = olua_push_cppobj(L, ret, "ccui.RichElementText");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_RichElementText_create8(lua_State *L)
{
    olua_startinvoke(L);

    lua_Integer arg1 = 0;       /** tag */
    cocos2d::Color3B arg2;       /** color */
    lua_Unsigned arg3 = 0;       /** opacity */
    std::string arg4;       /** text */
    std::string arg5;       /** fontName */
    lua_Number arg6 = 0;       /** fontSize */
    lua_Unsigned arg7 = 0;       /** flags */
    std::string arg8;       /** url */
    cocos2d::Color3B arg9;       /** outlineColor */
    lua_Integer arg10 = 0;       /** outlineSize */
    cocos2d::Color3B arg11;       /** shadowColor */
    cocos2d::Size arg12;       /** shadowOffset */

    olua_check_int(L, 1, &arg1);
    manual_olua_check_cocos2d_Color3B(L, 2, &arg2);
    olua_check_uint(L, 3, &arg3);
    olua_check_std_string(L, 4, &arg4);
    olua_check_std_string(L, 5, &arg5);
    olua_check_number(L, 6, &arg6);
    olua_check_uint(L, 7, &arg7);
    olua_check_std_string(L, 8, &arg8);
    manual_olua_check_cocos2d_Color3B(L, 9, &arg9);
    olua_check_int(L, 10, &arg10);
    manual_olua_check_cocos2d_Color3B(L, 11, &arg11);
    auto_olua_check_cocos2d_Size(L, 12, &arg12);

    // static cocos2d::ui::RichElementText *create(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &text, const std::string &fontName, float fontSize, @optional uint32_t flags, @optional const std::string &url, @optional const cocos2d::Color3B &outlineColor, @optional int outlineSize, @optional const cocos2d::Color3B &shadowColor, @optional const cocos2d::Size &shadowOffset, @optional int shadowBlurRadius, @optional const cocos2d::Color3B &glowColor)
    cocos2d::ui::RichElementText *ret = (cocos2d::ui::RichElementText *)cocos2d::ui::RichElementText::create((int)arg1, arg2, (uint8_t)arg3, arg4, arg5, (float)arg6, (uint32_t)arg7, arg8, arg9, (int)arg10, arg11, arg12);
    int num_ret = olua_push_cppobj(L, ret, "ccui.RichElementText");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_RichElementText_create9(lua_State *L)
{
    olua_startinvoke(L);

    lua_Integer arg1 = 0;       /** tag */
    cocos2d::Color3B arg2;       /** color */
    lua_Unsigned arg3 = 0;       /** opacity */
    std::string arg4;       /** text */
    std::string arg5;       /** fontName */
    lua_Number arg6 = 0;       /** fontSize */
    lua_Unsigned arg7 = 0;       /** flags */
    std::string arg8;       /** url */
    cocos2d::Color3B arg9;       /** outlineColor */
    lua_Integer arg10 = 0;       /** outlineSize */
    cocos2d::Color3B arg11;       /** shadowColor */
    cocos2d::Size arg12;       /** shadowOffset */
    lua_Integer arg13 = 0;       /** shadowBlurRadius */

    olua_check_int(L, 1, &arg1);
    manual_olua_check_cocos2d_Color3B(L, 2, &arg2);
    olua_check_uint(L, 3, &arg3);
    olua_check_std_string(L, 4, &arg4);
    olua_check_std_string(L, 5, &arg5);
    olua_check_number(L, 6, &arg6);
    olua_check_uint(L, 7, &arg7);
    olua_check_std_string(L, 8, &arg8);
    manual_olua_check_cocos2d_Color3B(L, 9, &arg9);
    olua_check_int(L, 10, &arg10);
    manual_olua_check_cocos2d_Color3B(L, 11, &arg11);
    auto_olua_check_cocos2d_Size(L, 12, &arg12);
    olua_check_int(L, 13, &arg13);

    // static cocos2d::ui::RichElementText *create(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &text, const std::string &fontName, float fontSize, @optional uint32_t flags, @optional const std::string &url, @optional const cocos2d::Color3B &outlineColor, @optional int outlineSize, @optional const cocos2d::Color3B &shadowColor, @optional const cocos2d::Size &shadowOffset, @optional int shadowBlurRadius, @optional const cocos2d::Color3B &glowColor)
    cocos2d::ui::RichElementText *ret = (cocos2d::ui::RichElementText *)cocos2d::ui::RichElementText::create((int)arg1, arg2, (uint8_t)arg3, arg4, arg5, (float)arg6, (uint32_t)arg7, arg8, arg9, (int)arg10, arg11, arg12, (int)arg13);
    int num_ret = olua_push_cppobj(L, ret, "ccui.RichElementText");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_RichElementText_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 6) {
        // if ((olua_is_int(L, 1)) && (manual_olua_is_cocos2d_Color3B(L, 2)) && (olua_is_uint(L, 3)) && (olua_is_std_string(L, 4)) && (olua_is_std_string(L, 5)) && (olua_is_number(L, 6))) {
            // static cocos2d::ui::RichElementText *create(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &text, const std::string &fontName, float fontSize, @optional uint32_t flags, @optional const std::string &url, @optional const cocos2d::Color3B &outlineColor, @optional int outlineSize, @optional const cocos2d::Color3B &shadowColor, @optional const cocos2d::Size &shadowOffset, @optional int shadowBlurRadius, @optional const cocos2d::Color3B &glowColor)
            return _cocos2d_ui_RichElementText_create2(L);
        // }
    }

    if (num_args == 7) {
        // if ((olua_is_int(L, 1)) && (manual_olua_is_cocos2d_Color3B(L, 2)) && (olua_is_uint(L, 3)) && (olua_is_std_string(L, 4)) && (olua_is_std_string(L, 5)) && (olua_is_number(L, 6)) && (olua_is_uint(L, 7))) {
            // static cocos2d::ui::RichElementText *create(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &text, const std::string &fontName, float fontSize, @optional uint32_t flags, @optional const std::string &url, @optional const cocos2d::Color3B &outlineColor, @optional int outlineSize, @optional const cocos2d::Color3B &shadowColor, @optional const cocos2d::Size &shadowOffset, @optional int shadowBlurRadius, @optional const cocos2d::Color3B &glowColor)
            return _cocos2d_ui_RichElementText_create3(L);
        // }
    }

    if (num_args == 8) {
        // if ((olua_is_int(L, 1)) && (manual_olua_is_cocos2d_Color3B(L, 2)) && (olua_is_uint(L, 3)) && (olua_is_std_string(L, 4)) && (olua_is_std_string(L, 5)) && (olua_is_number(L, 6)) && (olua_is_uint(L, 7)) && (olua_is_std_string(L, 8))) {
            // static cocos2d::ui::RichElementText *create(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &text, const std::string &fontName, float fontSize, @optional uint32_t flags, @optional const std::string &url, @optional const cocos2d::Color3B &outlineColor, @optional int outlineSize, @optional const cocos2d::Color3B &shadowColor, @optional const cocos2d::Size &shadowOffset, @optional int shadowBlurRadius, @optional const cocos2d::Color3B &glowColor)
            return _cocos2d_ui_RichElementText_create4(L);
        // }
    }

    if (num_args == 9) {
        // if ((olua_is_int(L, 1)) && (manual_olua_is_cocos2d_Color3B(L, 2)) && (olua_is_uint(L, 3)) && (olua_is_std_string(L, 4)) && (olua_is_std_string(L, 5)) && (olua_is_number(L, 6)) && (olua_is_uint(L, 7)) && (olua_is_std_string(L, 8)) && (manual_olua_is_cocos2d_Color3B(L, 9))) {
            // static cocos2d::ui::RichElementText *create(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &text, const std::string &fontName, float fontSize, @optional uint32_t flags, @optional const std::string &url, @optional const cocos2d::Color3B &outlineColor, @optional int outlineSize, @optional const cocos2d::Color3B &shadowColor, @optional const cocos2d::Size &shadowOffset, @optional int shadowBlurRadius, @optional const cocos2d::Color3B &glowColor)
            return _cocos2d_ui_RichElementText_create5(L);
        // }
    }

    if (num_args == 10) {
        // if ((olua_is_int(L, 1)) && (manual_olua_is_cocos2d_Color3B(L, 2)) && (olua_is_uint(L, 3)) && (olua_is_std_string(L, 4)) && (olua_is_std_string(L, 5)) && (olua_is_number(L, 6)) && (olua_is_uint(L, 7)) && (olua_is_std_string(L, 8)) && (manual_olua_is_cocos2d_Color3B(L, 9)) && (olua_is_int(L, 10))) {
            // static cocos2d::ui::RichElementText *create(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &text, const std::string &fontName, float fontSize, @optional uint32_t flags, @optional const std::string &url, @optional const cocos2d::Color3B &outlineColor, @optional int outlineSize, @optional const cocos2d::Color3B &shadowColor, @optional const cocos2d::Size &shadowOffset, @optional int shadowBlurRadius, @optional const cocos2d::Color3B &glowColor)
            return _cocos2d_ui_RichElementText_create6(L);
        // }
    }

    if (num_args == 11) {
        // if ((olua_is_int(L, 1)) && (manual_olua_is_cocos2d_Color3B(L, 2)) && (olua_is_uint(L, 3)) && (olua_is_std_string(L, 4)) && (olua_is_std_string(L, 5)) && (olua_is_number(L, 6)) && (olua_is_uint(L, 7)) && (olua_is_std_string(L, 8)) && (manual_olua_is_cocos2d_Color3B(L, 9)) && (olua_is_int(L, 10)) && (manual_olua_is_cocos2d_Color3B(L, 11))) {
            // static cocos2d::ui::RichElementText *create(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &text, const std::string &fontName, float fontSize, @optional uint32_t flags, @optional const std::string &url, @optional const cocos2d::Color3B &outlineColor, @optional int outlineSize, @optional const cocos2d::Color3B &shadowColor, @optional const cocos2d::Size &shadowOffset, @optional int shadowBlurRadius, @optional const cocos2d::Color3B &glowColor)
            return _cocos2d_ui_RichElementText_create7(L);
        // }
    }

    if (num_args == 12) {
        // if ((olua_is_int(L, 1)) && (manual_olua_is_cocos2d_Color3B(L, 2)) && (olua_is_uint(L, 3)) && (olua_is_std_string(L, 4)) && (olua_is_std_string(L, 5)) && (olua_is_number(L, 6)) && (olua_is_uint(L, 7)) && (olua_is_std_string(L, 8)) && (manual_olua_is_cocos2d_Color3B(L, 9)) && (olua_is_int(L, 10)) && (manual_olua_is_cocos2d_Color3B(L, 11)) && (auto_olua_is_cocos2d_Size(L, 12))) {
            // static cocos2d::ui::RichElementText *create(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &text, const std::string &fontName, float fontSize, @optional uint32_t flags, @optional const std::string &url, @optional const cocos2d::Color3B &outlineColor, @optional int outlineSize, @optional const cocos2d::Color3B &shadowColor, @optional const cocos2d::Size &shadowOffset, @optional int shadowBlurRadius, @optional const cocos2d::Color3B &glowColor)
            return _cocos2d_ui_RichElementText_create8(L);
        // }
    }

    if (num_args == 13) {
        // if ((olua_is_int(L, 1)) && (manual_olua_is_cocos2d_Color3B(L, 2)) && (olua_is_uint(L, 3)) && (olua_is_std_string(L, 4)) && (olua_is_std_string(L, 5)) && (olua_is_number(L, 6)) && (olua_is_uint(L, 7)) && (olua_is_std_string(L, 8)) && (manual_olua_is_cocos2d_Color3B(L, 9)) && (olua_is_int(L, 10)) && (manual_olua_is_cocos2d_Color3B(L, 11)) && (auto_olua_is_cocos2d_Size(L, 12)) && (olua_is_int(L, 13))) {
            // static cocos2d::ui::RichElementText *create(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &text, const std::string &fontName, float fontSize, @optional uint32_t flags, @optional const std::string &url, @optional const cocos2d::Color3B &outlineColor, @optional int outlineSize, @optional const cocos2d::Color3B &shadowColor, @optional const cocos2d::Size &shadowOffset, @optional int shadowBlurRadius, @optional const cocos2d::Color3B &glowColor)
            return _cocos2d_ui_RichElementText_create9(L);
        // }
    }

    if (num_args == 14) {
        // if ((olua_is_int(L, 1)) && (manual_olua_is_cocos2d_Color3B(L, 2)) && (olua_is_uint(L, 3)) && (olua_is_std_string(L, 4)) && (olua_is_std_string(L, 5)) && (olua_is_number(L, 6)) && (olua_is_uint(L, 7)) && (olua_is_std_string(L, 8)) && (manual_olua_is_cocos2d_Color3B(L, 9)) && (olua_is_int(L, 10)) && (manual_olua_is_cocos2d_Color3B(L, 11)) && (auto_olua_is_cocos2d_Size(L, 12)) && (olua_is_int(L, 13)) && (manual_olua_is_cocos2d_Color3B(L, 14))) {
            // static cocos2d::ui::RichElementText *create(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &text, const std::string &fontName, float fontSize, @optional uint32_t flags, @optional const std::string &url, @optional const cocos2d::Color3B &outlineColor, @optional int outlineSize, @optional const cocos2d::Color3B &shadowColor, @optional const cocos2d::Size &shadowOffset, @optional int shadowBlurRadius, @optional const cocos2d::Color3B &glowColor)
            return _cocos2d_ui_RichElementText_create1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::RichElementText::create' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ui_RichElementText_init1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichElementText *self = nullptr;
    lua_Integer arg1 = 0;       /** tag */
    cocos2d::Color3B arg2;       /** color */
    lua_Unsigned arg3 = 0;       /** opacity */
    std::string arg4;       /** text */
    std::string arg5;       /** fontName */
    lua_Number arg6 = 0;       /** fontSize */
    lua_Unsigned arg7 = 0;       /** flags */
    std::string arg8;       /** url */
    cocos2d::Color3B arg9;       /** outlineColor */
    lua_Integer arg10 = 0;       /** outlineSize */
    cocos2d::Color3B arg11;       /** shadowColor */
    cocos2d::Size arg12;       /** shadowOffset */
    lua_Integer arg13 = 0;       /** shadowBlurRadius */
    cocos2d::Color3B arg14;       /** glowColor */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RichElementText");
    olua_check_int(L, 2, &arg1);
    manual_olua_check_cocos2d_Color3B(L, 3, &arg2);
    olua_check_uint(L, 4, &arg3);
    olua_check_std_string(L, 5, &arg4);
    olua_check_std_string(L, 6, &arg5);
    olua_check_number(L, 7, &arg6);
    olua_check_uint(L, 8, &arg7);
    olua_check_std_string(L, 9, &arg8);
    manual_olua_check_cocos2d_Color3B(L, 10, &arg9);
    olua_check_int(L, 11, &arg10);
    manual_olua_check_cocos2d_Color3B(L, 12, &arg11);
    auto_olua_check_cocos2d_Size(L, 13, &arg12);
    olua_check_int(L, 14, &arg13);
    manual_olua_check_cocos2d_Color3B(L, 15, &arg14);

    // bool init(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &text, const std::string &fontName, float fontSize, uint32_t flags, const std::string &url, @optional const cocos2d::Color3B &outlineColor, @optional int outlineSize, @optional const cocos2d::Color3B &shadowColor, @optional const cocos2d::Size &shadowOffset, @optional int shadowBlurRadius, @optional const cocos2d::Color3B &glowColor)
    bool ret = (bool)self->init((int)arg1, arg2, (uint8_t)arg3, arg4, arg5, (float)arg6, (uint32_t)arg7, arg8, arg9, (int)arg10, arg11, arg12, (int)arg13, arg14);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_RichElementText_init2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichElementText *self = nullptr;
    lua_Integer arg1 = 0;       /** tag */
    cocos2d::Color3B arg2;       /** color */
    lua_Unsigned arg3 = 0;       /** opacity */
    std::string arg4;       /** text */
    std::string arg5;       /** fontName */
    lua_Number arg6 = 0;       /** fontSize */
    lua_Unsigned arg7 = 0;       /** flags */
    std::string arg8;       /** url */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RichElementText");
    olua_check_int(L, 2, &arg1);
    manual_olua_check_cocos2d_Color3B(L, 3, &arg2);
    olua_check_uint(L, 4, &arg3);
    olua_check_std_string(L, 5, &arg4);
    olua_check_std_string(L, 6, &arg5);
    olua_check_number(L, 7, &arg6);
    olua_check_uint(L, 8, &arg7);
    olua_check_std_string(L, 9, &arg8);

    // bool init(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &text, const std::string &fontName, float fontSize, uint32_t flags, const std::string &url, @optional const cocos2d::Color3B &outlineColor, @optional int outlineSize, @optional const cocos2d::Color3B &shadowColor, @optional const cocos2d::Size &shadowOffset, @optional int shadowBlurRadius, @optional const cocos2d::Color3B &glowColor)
    bool ret = (bool)self->init((int)arg1, arg2, (uint8_t)arg3, arg4, arg5, (float)arg6, (uint32_t)arg7, arg8);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_RichElementText_init3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichElementText *self = nullptr;
    lua_Integer arg1 = 0;       /** tag */
    cocos2d::Color3B arg2;       /** color */
    lua_Unsigned arg3 = 0;       /** opacity */
    std::string arg4;       /** text */
    std::string arg5;       /** fontName */
    lua_Number arg6 = 0;       /** fontSize */
    lua_Unsigned arg7 = 0;       /** flags */
    std::string arg8;       /** url */
    cocos2d::Color3B arg9;       /** outlineColor */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RichElementText");
    olua_check_int(L, 2, &arg1);
    manual_olua_check_cocos2d_Color3B(L, 3, &arg2);
    olua_check_uint(L, 4, &arg3);
    olua_check_std_string(L, 5, &arg4);
    olua_check_std_string(L, 6, &arg5);
    olua_check_number(L, 7, &arg6);
    olua_check_uint(L, 8, &arg7);
    olua_check_std_string(L, 9, &arg8);
    manual_olua_check_cocos2d_Color3B(L, 10, &arg9);

    // bool init(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &text, const std::string &fontName, float fontSize, uint32_t flags, const std::string &url, @optional const cocos2d::Color3B &outlineColor, @optional int outlineSize, @optional const cocos2d::Color3B &shadowColor, @optional const cocos2d::Size &shadowOffset, @optional int shadowBlurRadius, @optional const cocos2d::Color3B &glowColor)
    bool ret = (bool)self->init((int)arg1, arg2, (uint8_t)arg3, arg4, arg5, (float)arg6, (uint32_t)arg7, arg8, arg9);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_RichElementText_init4(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichElementText *self = nullptr;
    lua_Integer arg1 = 0;       /** tag */
    cocos2d::Color3B arg2;       /** color */
    lua_Unsigned arg3 = 0;       /** opacity */
    std::string arg4;       /** text */
    std::string arg5;       /** fontName */
    lua_Number arg6 = 0;       /** fontSize */
    lua_Unsigned arg7 = 0;       /** flags */
    std::string arg8;       /** url */
    cocos2d::Color3B arg9;       /** outlineColor */
    lua_Integer arg10 = 0;       /** outlineSize */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RichElementText");
    olua_check_int(L, 2, &arg1);
    manual_olua_check_cocos2d_Color3B(L, 3, &arg2);
    olua_check_uint(L, 4, &arg3);
    olua_check_std_string(L, 5, &arg4);
    olua_check_std_string(L, 6, &arg5);
    olua_check_number(L, 7, &arg6);
    olua_check_uint(L, 8, &arg7);
    olua_check_std_string(L, 9, &arg8);
    manual_olua_check_cocos2d_Color3B(L, 10, &arg9);
    olua_check_int(L, 11, &arg10);

    // bool init(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &text, const std::string &fontName, float fontSize, uint32_t flags, const std::string &url, @optional const cocos2d::Color3B &outlineColor, @optional int outlineSize, @optional const cocos2d::Color3B &shadowColor, @optional const cocos2d::Size &shadowOffset, @optional int shadowBlurRadius, @optional const cocos2d::Color3B &glowColor)
    bool ret = (bool)self->init((int)arg1, arg2, (uint8_t)arg3, arg4, arg5, (float)arg6, (uint32_t)arg7, arg8, arg9, (int)arg10);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_RichElementText_init5(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichElementText *self = nullptr;
    lua_Integer arg1 = 0;       /** tag */
    cocos2d::Color3B arg2;       /** color */
    lua_Unsigned arg3 = 0;       /** opacity */
    std::string arg4;       /** text */
    std::string arg5;       /** fontName */
    lua_Number arg6 = 0;       /** fontSize */
    lua_Unsigned arg7 = 0;       /** flags */
    std::string arg8;       /** url */
    cocos2d::Color3B arg9;       /** outlineColor */
    lua_Integer arg10 = 0;       /** outlineSize */
    cocos2d::Color3B arg11;       /** shadowColor */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RichElementText");
    olua_check_int(L, 2, &arg1);
    manual_olua_check_cocos2d_Color3B(L, 3, &arg2);
    olua_check_uint(L, 4, &arg3);
    olua_check_std_string(L, 5, &arg4);
    olua_check_std_string(L, 6, &arg5);
    olua_check_number(L, 7, &arg6);
    olua_check_uint(L, 8, &arg7);
    olua_check_std_string(L, 9, &arg8);
    manual_olua_check_cocos2d_Color3B(L, 10, &arg9);
    olua_check_int(L, 11, &arg10);
    manual_olua_check_cocos2d_Color3B(L, 12, &arg11);

    // bool init(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &text, const std::string &fontName, float fontSize, uint32_t flags, const std::string &url, @optional const cocos2d::Color3B &outlineColor, @optional int outlineSize, @optional const cocos2d::Color3B &shadowColor, @optional const cocos2d::Size &shadowOffset, @optional int shadowBlurRadius, @optional const cocos2d::Color3B &glowColor)
    bool ret = (bool)self->init((int)arg1, arg2, (uint8_t)arg3, arg4, arg5, (float)arg6, (uint32_t)arg7, arg8, arg9, (int)arg10, arg11);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_RichElementText_init6(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichElementText *self = nullptr;
    lua_Integer arg1 = 0;       /** tag */
    cocos2d::Color3B arg2;       /** color */
    lua_Unsigned arg3 = 0;       /** opacity */
    std::string arg4;       /** text */
    std::string arg5;       /** fontName */
    lua_Number arg6 = 0;       /** fontSize */
    lua_Unsigned arg7 = 0;       /** flags */
    std::string arg8;       /** url */
    cocos2d::Color3B arg9;       /** outlineColor */
    lua_Integer arg10 = 0;       /** outlineSize */
    cocos2d::Color3B arg11;       /** shadowColor */
    cocos2d::Size arg12;       /** shadowOffset */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RichElementText");
    olua_check_int(L, 2, &arg1);
    manual_olua_check_cocos2d_Color3B(L, 3, &arg2);
    olua_check_uint(L, 4, &arg3);
    olua_check_std_string(L, 5, &arg4);
    olua_check_std_string(L, 6, &arg5);
    olua_check_number(L, 7, &arg6);
    olua_check_uint(L, 8, &arg7);
    olua_check_std_string(L, 9, &arg8);
    manual_olua_check_cocos2d_Color3B(L, 10, &arg9);
    olua_check_int(L, 11, &arg10);
    manual_olua_check_cocos2d_Color3B(L, 12, &arg11);
    auto_olua_check_cocos2d_Size(L, 13, &arg12);

    // bool init(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &text, const std::string &fontName, float fontSize, uint32_t flags, const std::string &url, @optional const cocos2d::Color3B &outlineColor, @optional int outlineSize, @optional const cocos2d::Color3B &shadowColor, @optional const cocos2d::Size &shadowOffset, @optional int shadowBlurRadius, @optional const cocos2d::Color3B &glowColor)
    bool ret = (bool)self->init((int)arg1, arg2, (uint8_t)arg3, arg4, arg5, (float)arg6, (uint32_t)arg7, arg8, arg9, (int)arg10, arg11, arg12);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_RichElementText_init7(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichElementText *self = nullptr;
    lua_Integer arg1 = 0;       /** tag */
    cocos2d::Color3B arg2;       /** color */
    lua_Unsigned arg3 = 0;       /** opacity */
    std::string arg4;       /** text */
    std::string arg5;       /** fontName */
    lua_Number arg6 = 0;       /** fontSize */
    lua_Unsigned arg7 = 0;       /** flags */
    std::string arg8;       /** url */
    cocos2d::Color3B arg9;       /** outlineColor */
    lua_Integer arg10 = 0;       /** outlineSize */
    cocos2d::Color3B arg11;       /** shadowColor */
    cocos2d::Size arg12;       /** shadowOffset */
    lua_Integer arg13 = 0;       /** shadowBlurRadius */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RichElementText");
    olua_check_int(L, 2, &arg1);
    manual_olua_check_cocos2d_Color3B(L, 3, &arg2);
    olua_check_uint(L, 4, &arg3);
    olua_check_std_string(L, 5, &arg4);
    olua_check_std_string(L, 6, &arg5);
    olua_check_number(L, 7, &arg6);
    olua_check_uint(L, 8, &arg7);
    olua_check_std_string(L, 9, &arg8);
    manual_olua_check_cocos2d_Color3B(L, 10, &arg9);
    olua_check_int(L, 11, &arg10);
    manual_olua_check_cocos2d_Color3B(L, 12, &arg11);
    auto_olua_check_cocos2d_Size(L, 13, &arg12);
    olua_check_int(L, 14, &arg13);

    // bool init(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &text, const std::string &fontName, float fontSize, uint32_t flags, const std::string &url, @optional const cocos2d::Color3B &outlineColor, @optional int outlineSize, @optional const cocos2d::Color3B &shadowColor, @optional const cocos2d::Size &shadowOffset, @optional int shadowBlurRadius, @optional const cocos2d::Color3B &glowColor)
    bool ret = (bool)self->init((int)arg1, arg2, (uint8_t)arg3, arg4, arg5, (float)arg6, (uint32_t)arg7, arg8, arg9, (int)arg10, arg11, arg12, (int)arg13);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_RichElementText_init(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 8) {
        // if ((olua_is_int(L, 2)) && (manual_olua_is_cocos2d_Color3B(L, 3)) && (olua_is_uint(L, 4)) && (olua_is_std_string(L, 5)) && (olua_is_std_string(L, 6)) && (olua_is_number(L, 7)) && (olua_is_uint(L, 8)) && (olua_is_std_string(L, 9))) {
            // bool init(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &text, const std::string &fontName, float fontSize, uint32_t flags, const std::string &url, @optional const cocos2d::Color3B &outlineColor, @optional int outlineSize, @optional const cocos2d::Color3B &shadowColor, @optional const cocos2d::Size &shadowOffset, @optional int shadowBlurRadius, @optional const cocos2d::Color3B &glowColor)
            return _cocos2d_ui_RichElementText_init2(L);
        // }
    }

    if (num_args == 9) {
        // if ((olua_is_int(L, 2)) && (manual_olua_is_cocos2d_Color3B(L, 3)) && (olua_is_uint(L, 4)) && (olua_is_std_string(L, 5)) && (olua_is_std_string(L, 6)) && (olua_is_number(L, 7)) && (olua_is_uint(L, 8)) && (olua_is_std_string(L, 9)) && (manual_olua_is_cocos2d_Color3B(L, 10))) {
            // bool init(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &text, const std::string &fontName, float fontSize, uint32_t flags, const std::string &url, @optional const cocos2d::Color3B &outlineColor, @optional int outlineSize, @optional const cocos2d::Color3B &shadowColor, @optional const cocos2d::Size &shadowOffset, @optional int shadowBlurRadius, @optional const cocos2d::Color3B &glowColor)
            return _cocos2d_ui_RichElementText_init3(L);
        // }
    }

    if (num_args == 10) {
        // if ((olua_is_int(L, 2)) && (manual_olua_is_cocos2d_Color3B(L, 3)) && (olua_is_uint(L, 4)) && (olua_is_std_string(L, 5)) && (olua_is_std_string(L, 6)) && (olua_is_number(L, 7)) && (olua_is_uint(L, 8)) && (olua_is_std_string(L, 9)) && (manual_olua_is_cocos2d_Color3B(L, 10)) && (olua_is_int(L, 11))) {
            // bool init(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &text, const std::string &fontName, float fontSize, uint32_t flags, const std::string &url, @optional const cocos2d::Color3B &outlineColor, @optional int outlineSize, @optional const cocos2d::Color3B &shadowColor, @optional const cocos2d::Size &shadowOffset, @optional int shadowBlurRadius, @optional const cocos2d::Color3B &glowColor)
            return _cocos2d_ui_RichElementText_init4(L);
        // }
    }

    if (num_args == 11) {
        // if ((olua_is_int(L, 2)) && (manual_olua_is_cocos2d_Color3B(L, 3)) && (olua_is_uint(L, 4)) && (olua_is_std_string(L, 5)) && (olua_is_std_string(L, 6)) && (olua_is_number(L, 7)) && (olua_is_uint(L, 8)) && (olua_is_std_string(L, 9)) && (manual_olua_is_cocos2d_Color3B(L, 10)) && (olua_is_int(L, 11)) && (manual_olua_is_cocos2d_Color3B(L, 12))) {
            // bool init(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &text, const std::string &fontName, float fontSize, uint32_t flags, const std::string &url, @optional const cocos2d::Color3B &outlineColor, @optional int outlineSize, @optional const cocos2d::Color3B &shadowColor, @optional const cocos2d::Size &shadowOffset, @optional int shadowBlurRadius, @optional const cocos2d::Color3B &glowColor)
            return _cocos2d_ui_RichElementText_init5(L);
        // }
    }

    if (num_args == 12) {
        // if ((olua_is_int(L, 2)) && (manual_olua_is_cocos2d_Color3B(L, 3)) && (olua_is_uint(L, 4)) && (olua_is_std_string(L, 5)) && (olua_is_std_string(L, 6)) && (olua_is_number(L, 7)) && (olua_is_uint(L, 8)) && (olua_is_std_string(L, 9)) && (manual_olua_is_cocos2d_Color3B(L, 10)) && (olua_is_int(L, 11)) && (manual_olua_is_cocos2d_Color3B(L, 12)) && (auto_olua_is_cocos2d_Size(L, 13))) {
            // bool init(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &text, const std::string &fontName, float fontSize, uint32_t flags, const std::string &url, @optional const cocos2d::Color3B &outlineColor, @optional int outlineSize, @optional const cocos2d::Color3B &shadowColor, @optional const cocos2d::Size &shadowOffset, @optional int shadowBlurRadius, @optional const cocos2d::Color3B &glowColor)
            return _cocos2d_ui_RichElementText_init6(L);
        // }
    }

    if (num_args == 13) {
        // if ((olua_is_int(L, 2)) && (manual_olua_is_cocos2d_Color3B(L, 3)) && (olua_is_uint(L, 4)) && (olua_is_std_string(L, 5)) && (olua_is_std_string(L, 6)) && (olua_is_number(L, 7)) && (olua_is_uint(L, 8)) && (olua_is_std_string(L, 9)) && (manual_olua_is_cocos2d_Color3B(L, 10)) && (olua_is_int(L, 11)) && (manual_olua_is_cocos2d_Color3B(L, 12)) && (auto_olua_is_cocos2d_Size(L, 13)) && (olua_is_int(L, 14))) {
            // bool init(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &text, const std::string &fontName, float fontSize, uint32_t flags, const std::string &url, @optional const cocos2d::Color3B &outlineColor, @optional int outlineSize, @optional const cocos2d::Color3B &shadowColor, @optional const cocos2d::Size &shadowOffset, @optional int shadowBlurRadius, @optional const cocos2d::Color3B &glowColor)
            return _cocos2d_ui_RichElementText_init7(L);
        // }
    }

    if (num_args == 14) {
        // if ((olua_is_int(L, 2)) && (manual_olua_is_cocos2d_Color3B(L, 3)) && (olua_is_uint(L, 4)) && (olua_is_std_string(L, 5)) && (olua_is_std_string(L, 6)) && (olua_is_number(L, 7)) && (olua_is_uint(L, 8)) && (olua_is_std_string(L, 9)) && (manual_olua_is_cocos2d_Color3B(L, 10)) && (olua_is_int(L, 11)) && (manual_olua_is_cocos2d_Color3B(L, 12)) && (auto_olua_is_cocos2d_Size(L, 13)) && (olua_is_int(L, 14)) && (manual_olua_is_cocos2d_Color3B(L, 15))) {
            // bool init(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &text, const std::string &fontName, float fontSize, uint32_t flags, const std::string &url, @optional const cocos2d::Color3B &outlineColor, @optional int outlineSize, @optional const cocos2d::Color3B &shadowColor, @optional const cocos2d::Size &shadowOffset, @optional int shadowBlurRadius, @optional const cocos2d::Color3B &glowColor)
            return _cocos2d_ui_RichElementText_init1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::RichElementText::init' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ui_RichElementText_new(lua_State *L)
{
    olua_startinvoke(L);

    // RichElementText()
    cocos2d::ui::RichElementText *ret = (cocos2d::ui::RichElementText *)new cocos2d::ui::RichElementText();
    int num_ret = olua_push_cppobj(L, ret, "ccui.RichElementText");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_ui_RichElementText(lua_State *L)
{
    oluacls_class(L, "ccui.RichElementText", "ccui.RichElement");
    oluacls_func(L, "__move", _cocos2d_ui_RichElementText___move);
    oluacls_func(L, "create", _cocos2d_ui_RichElementText_create);
    oluacls_func(L, "init", _cocos2d_ui_RichElementText_init);
    oluacls_func(L, "new", _cocos2d_ui_RichElementText_new);

    olua_registerluatype<cocos2d::ui::RichElementText>(L, "ccui.RichElementText");

    return 1;
}

static int _cocos2d_ui_RichElementImage___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::ui::RichElementImage *)olua_toobj(L, 1, "ccui.RichElementImage");
    olua_push_cppobj(L, self, "ccui.RichElementImage");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_ui_RichElementImage_create1(lua_State *L)
{
    olua_startinvoke(L);

    lua_Integer arg1 = 0;       /** tag */
    cocos2d::Color3B arg2;       /** color */
    lua_Unsigned arg3 = 0;       /** opacity */
    std::string arg4;       /** filePath */
    std::string arg5;       /** url */
    lua_Unsigned arg6 = 0;       /** texType */

    olua_check_int(L, 1, &arg1);
    manual_olua_check_cocos2d_Color3B(L, 2, &arg2);
    olua_check_uint(L, 3, &arg3);
    olua_check_std_string(L, 4, &arg4);
    olua_check_std_string(L, 5, &arg5);
    olua_check_uint(L, 6, &arg6);

    // static cocos2d::ui::RichElementImage *create(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &filePath, @optional const std::string &url, @optional Widget::TextureResType texType)
    cocos2d::ui::RichElementImage *ret = (cocos2d::ui::RichElementImage *)cocos2d::ui::RichElementImage::create((int)arg1, arg2, (uint8_t)arg3, arg4, arg5, (cocos2d::ui::Widget::TextureResType)arg6);
    int num_ret = olua_push_cppobj(L, ret, "ccui.RichElementImage");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_RichElementImage_create2(lua_State *L)
{
    olua_startinvoke(L);

    lua_Integer arg1 = 0;       /** tag */
    cocos2d::Color3B arg2;       /** color */
    lua_Unsigned arg3 = 0;       /** opacity */
    std::string arg4;       /** filePath */

    olua_check_int(L, 1, &arg1);
    manual_olua_check_cocos2d_Color3B(L, 2, &arg2);
    olua_check_uint(L, 3, &arg3);
    olua_check_std_string(L, 4, &arg4);

    // static cocos2d::ui::RichElementImage *create(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &filePath, @optional const std::string &url, @optional Widget::TextureResType texType)
    cocos2d::ui::RichElementImage *ret = (cocos2d::ui::RichElementImage *)cocos2d::ui::RichElementImage::create((int)arg1, arg2, (uint8_t)arg3, arg4);
    int num_ret = olua_push_cppobj(L, ret, "ccui.RichElementImage");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_RichElementImage_create3(lua_State *L)
{
    olua_startinvoke(L);

    lua_Integer arg1 = 0;       /** tag */
    cocos2d::Color3B arg2;       /** color */
    lua_Unsigned arg3 = 0;       /** opacity */
    std::string arg4;       /** filePath */
    std::string arg5;       /** url */

    olua_check_int(L, 1, &arg1);
    manual_olua_check_cocos2d_Color3B(L, 2, &arg2);
    olua_check_uint(L, 3, &arg3);
    olua_check_std_string(L, 4, &arg4);
    olua_check_std_string(L, 5, &arg5);

    // static cocos2d::ui::RichElementImage *create(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &filePath, @optional const std::string &url, @optional Widget::TextureResType texType)
    cocos2d::ui::RichElementImage *ret = (cocos2d::ui::RichElementImage *)cocos2d::ui::RichElementImage::create((int)arg1, arg2, (uint8_t)arg3, arg4, arg5);
    int num_ret = olua_push_cppobj(L, ret, "ccui.RichElementImage");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_RichElementImage_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 4) {
        // if ((olua_is_int(L, 1)) && (manual_olua_is_cocos2d_Color3B(L, 2)) && (olua_is_uint(L, 3)) && (olua_is_std_string(L, 4))) {
            // static cocos2d::ui::RichElementImage *create(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &filePath, @optional const std::string &url, @optional Widget::TextureResType texType)
            return _cocos2d_ui_RichElementImage_create2(L);
        // }
    }

    if (num_args == 5) {
        // if ((olua_is_int(L, 1)) && (manual_olua_is_cocos2d_Color3B(L, 2)) && (olua_is_uint(L, 3)) && (olua_is_std_string(L, 4)) && (olua_is_std_string(L, 5))) {
            // static cocos2d::ui::RichElementImage *create(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &filePath, @optional const std::string &url, @optional Widget::TextureResType texType)
            return _cocos2d_ui_RichElementImage_create3(L);
        // }
    }

    if (num_args == 6) {
        // if ((olua_is_int(L, 1)) && (manual_olua_is_cocos2d_Color3B(L, 2)) && (olua_is_uint(L, 3)) && (olua_is_std_string(L, 4)) && (olua_is_std_string(L, 5)) && (olua_is_uint(L, 6))) {
            // static cocos2d::ui::RichElementImage *create(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &filePath, @optional const std::string &url, @optional Widget::TextureResType texType)
            return _cocos2d_ui_RichElementImage_create1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::RichElementImage::create' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ui_RichElementImage_init1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichElementImage *self = nullptr;
    lua_Integer arg1 = 0;       /** tag */
    cocos2d::Color3B arg2;       /** color */
    lua_Unsigned arg3 = 0;       /** opacity */
    std::string arg4;       /** filePath */
    std::string arg5;       /** url */
    lua_Unsigned arg6 = 0;       /** texType */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RichElementImage");
    olua_check_int(L, 2, &arg1);
    manual_olua_check_cocos2d_Color3B(L, 3, &arg2);
    olua_check_uint(L, 4, &arg3);
    olua_check_std_string(L, 5, &arg4);
    olua_check_std_string(L, 6, &arg5);
    olua_check_uint(L, 7, &arg6);

    // bool init(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &filePath, @optional const std::string &url, @optional Widget::TextureResType texType)
    bool ret = (bool)self->init((int)arg1, arg2, (uint8_t)arg3, arg4, arg5, (cocos2d::ui::Widget::TextureResType)arg6);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_RichElementImage_init2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichElementImage *self = nullptr;
    lua_Integer arg1 = 0;       /** tag */
    cocos2d::Color3B arg2;       /** color */
    lua_Unsigned arg3 = 0;       /** opacity */
    std::string arg4;       /** filePath */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RichElementImage");
    olua_check_int(L, 2, &arg1);
    manual_olua_check_cocos2d_Color3B(L, 3, &arg2);
    olua_check_uint(L, 4, &arg3);
    olua_check_std_string(L, 5, &arg4);

    // bool init(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &filePath, @optional const std::string &url, @optional Widget::TextureResType texType)
    bool ret = (bool)self->init((int)arg1, arg2, (uint8_t)arg3, arg4);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_RichElementImage_init3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichElementImage *self = nullptr;
    lua_Integer arg1 = 0;       /** tag */
    cocos2d::Color3B arg2;       /** color */
    lua_Unsigned arg3 = 0;       /** opacity */
    std::string arg4;       /** filePath */
    std::string arg5;       /** url */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RichElementImage");
    olua_check_int(L, 2, &arg1);
    manual_olua_check_cocos2d_Color3B(L, 3, &arg2);
    olua_check_uint(L, 4, &arg3);
    olua_check_std_string(L, 5, &arg4);
    olua_check_std_string(L, 6, &arg5);

    // bool init(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &filePath, @optional const std::string &url, @optional Widget::TextureResType texType)
    bool ret = (bool)self->init((int)arg1, arg2, (uint8_t)arg3, arg4, arg5);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_RichElementImage_init(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 4) {
        // if ((olua_is_int(L, 2)) && (manual_olua_is_cocos2d_Color3B(L, 3)) && (olua_is_uint(L, 4)) && (olua_is_std_string(L, 5))) {
            // bool init(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &filePath, @optional const std::string &url, @optional Widget::TextureResType texType)
            return _cocos2d_ui_RichElementImage_init2(L);
        // }
    }

    if (num_args == 5) {
        // if ((olua_is_int(L, 2)) && (manual_olua_is_cocos2d_Color3B(L, 3)) && (olua_is_uint(L, 4)) && (olua_is_std_string(L, 5)) && (olua_is_std_string(L, 6))) {
            // bool init(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &filePath, @optional const std::string &url, @optional Widget::TextureResType texType)
            return _cocos2d_ui_RichElementImage_init3(L);
        // }
    }

    if (num_args == 6) {
        // if ((olua_is_int(L, 2)) && (manual_olua_is_cocos2d_Color3B(L, 3)) && (olua_is_uint(L, 4)) && (olua_is_std_string(L, 5)) && (olua_is_std_string(L, 6)) && (olua_is_uint(L, 7))) {
            // bool init(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &filePath, @optional const std::string &url, @optional Widget::TextureResType texType)
            return _cocos2d_ui_RichElementImage_init1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::RichElementImage::init' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ui_RichElementImage_new(lua_State *L)
{
    olua_startinvoke(L);

    // RichElementImage()
    cocos2d::ui::RichElementImage *ret = (cocos2d::ui::RichElementImage *)new cocos2d::ui::RichElementImage();
    int num_ret = olua_push_cppobj(L, ret, "ccui.RichElementImage");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_RichElementImage_setHeight(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichElementImage *self = nullptr;
    lua_Integer arg1 = 0;       /** height */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RichElementImage");
    olua_check_int(L, 2, &arg1);

    // void setHeight(int height)
    self->setHeight((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_RichElementImage_setUrl(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichElementImage *self = nullptr;
    std::string arg1;       /** url */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RichElementImage");
    olua_check_std_string(L, 2, &arg1);

    // void setUrl(const std::string &url)
    self->setUrl(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_RichElementImage_setWidth(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichElementImage *self = nullptr;
    lua_Integer arg1 = 0;       /** width */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RichElementImage");
    olua_check_int(L, 2, &arg1);

    // void setWidth(int width)
    self->setWidth((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_ui_RichElementImage(lua_State *L)
{
    oluacls_class(L, "ccui.RichElementImage", "ccui.RichElement");
    oluacls_func(L, "__move", _cocos2d_ui_RichElementImage___move);
    oluacls_func(L, "create", _cocos2d_ui_RichElementImage_create);
    oluacls_func(L, "init", _cocos2d_ui_RichElementImage_init);
    oluacls_func(L, "new", _cocos2d_ui_RichElementImage_new);
    oluacls_func(L, "setHeight", _cocos2d_ui_RichElementImage_setHeight);
    oluacls_func(L, "setUrl", _cocos2d_ui_RichElementImage_setUrl);
    oluacls_func(L, "setWidth", _cocos2d_ui_RichElementImage_setWidth);

    olua_registerluatype<cocos2d::ui::RichElementImage>(L, "ccui.RichElementImage");

    return 1;
}

static int _cocos2d_ui_RichElementCustomNode___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::ui::RichElementCustomNode *)olua_toobj(L, 1, "ccui.RichElementCustomNode");
    olua_push_cppobj(L, self, "ccui.RichElementCustomNode");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_ui_RichElementCustomNode_create(lua_State *L)
{
    olua_startinvoke(L);

    lua_Integer arg1 = 0;       /** tag */
    cocos2d::Color3B arg2;       /** color */
    lua_Unsigned arg3 = 0;       /** opacity */
    cocos2d::Node *arg4 = nullptr;       /** customNode */

    olua_check_int(L, 1, &arg1);
    manual_olua_check_cocos2d_Color3B(L, 2, &arg2);
    olua_check_uint(L, 3, &arg3);
    olua_check_cppobj(L, 4, (void **)&arg4, "cc.Node");

    // static cocos2d::ui::RichElementCustomNode *create(int tag, const cocos2d::Color3B &color, uint8_t opacity, cocos2d::Node *customNode)
    cocos2d::ui::RichElementCustomNode *ret = (cocos2d::ui::RichElementCustomNode *)cocos2d::ui::RichElementCustomNode::create((int)arg1, arg2, (uint8_t)arg3, arg4);
    int num_ret = olua_push_cppobj(L, ret, "ccui.RichElementCustomNode");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_RichElementCustomNode_init(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichElementCustomNode *self = nullptr;
    lua_Integer arg1 = 0;       /** tag */
    cocos2d::Color3B arg2;       /** color */
    lua_Unsigned arg3 = 0;       /** opacity */
    cocos2d::Node *arg4 = nullptr;       /** customNode */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RichElementCustomNode");
    olua_check_int(L, 2, &arg1);
    manual_olua_check_cocos2d_Color3B(L, 3, &arg2);
    olua_check_uint(L, 4, &arg3);
    olua_check_cppobj(L, 5, (void **)&arg4, "cc.Node");

    // bool init(int tag, const cocos2d::Color3B &color, uint8_t opacity, cocos2d::Node *customNode)
    bool ret = (bool)self->init((int)arg1, arg2, (uint8_t)arg3, arg4);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_RichElementCustomNode_new(lua_State *L)
{
    olua_startinvoke(L);

    // RichElementCustomNode()
    cocos2d::ui::RichElementCustomNode *ret = (cocos2d::ui::RichElementCustomNode *)new cocos2d::ui::RichElementCustomNode();
    int num_ret = olua_push_cppobj(L, ret, "ccui.RichElementCustomNode");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_ui_RichElementCustomNode(lua_State *L)
{
    oluacls_class(L, "ccui.RichElementCustomNode", "ccui.RichElement");
    oluacls_func(L, "__move", _cocos2d_ui_RichElementCustomNode___move);
    oluacls_func(L, "create", _cocos2d_ui_RichElementCustomNode_create);
    oluacls_func(L, "init", _cocos2d_ui_RichElementCustomNode_init);
    oluacls_func(L, "new", _cocos2d_ui_RichElementCustomNode_new);

    olua_registerluatype<cocos2d::ui::RichElementCustomNode>(L, "ccui.RichElementCustomNode");

    return 1;
}

static int _cocos2d_ui_RichElementNewLine___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::ui::RichElementNewLine *)olua_toobj(L, 1, "ccui.RichElementNewLine");
    olua_push_cppobj(L, self, "ccui.RichElementNewLine");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_ui_RichElementNewLine_create(lua_State *L)
{
    olua_startinvoke(L);

    lua_Integer arg1 = 0;       /** tag */
    cocos2d::Color3B arg2;       /** color */
    lua_Unsigned arg3 = 0;       /** opacity */

    olua_check_int(L, 1, &arg1);
    manual_olua_check_cocos2d_Color3B(L, 2, &arg2);
    olua_check_uint(L, 3, &arg3);

    // static cocos2d::ui::RichElementNewLine *create(int tag, const cocos2d::Color3B &color, uint8_t opacity)
    cocos2d::ui::RichElementNewLine *ret = (cocos2d::ui::RichElementNewLine *)cocos2d::ui::RichElementNewLine::create((int)arg1, arg2, (uint8_t)arg3);
    int num_ret = olua_push_cppobj(L, ret, "ccui.RichElementNewLine");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_RichElementNewLine_new(lua_State *L)
{
    olua_startinvoke(L);

    // RichElementNewLine()
    cocos2d::ui::RichElementNewLine *ret = (cocos2d::ui::RichElementNewLine *)new cocos2d::ui::RichElementNewLine();
    int num_ret = olua_push_cppobj(L, ret, "ccui.RichElementNewLine");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_ui_RichElementNewLine(lua_State *L)
{
    oluacls_class(L, "ccui.RichElementNewLine", "ccui.RichElement");
    oluacls_func(L, "__move", _cocos2d_ui_RichElementNewLine___move);
    oluacls_func(L, "create", _cocos2d_ui_RichElementNewLine_create);
    oluacls_func(L, "new", _cocos2d_ui_RichElementNewLine_new);

    olua_registerluatype<cocos2d::ui::RichElementNewLine>(L, "ccui.RichElementNewLine");

    return 1;
}

static int luaopen_cocos2d_ui_RichText_WrapMode(lua_State *L)
{
    oluacls_class(L, "ccui.RichText.WrapMode", nullptr);
    oluacls_const_integer(L, "WRAP_PER_CHAR", (lua_Integer)cocos2d::ui::RichText::WrapMode::WRAP_PER_CHAR);
    oluacls_const_integer(L, "WRAP_PER_WORD", (lua_Integer)cocos2d::ui::RichText::WrapMode::WRAP_PER_WORD);

    olua_registerluatype<cocos2d::ui::RichText::WrapMode>(L, "ccui.RichText.WrapMode");

    return 1;
}

static int luaopen_cocos2d_ui_RichText_HorizontalAlignment(lua_State *L)
{
    oluacls_class(L, "ccui.RichText.HorizontalAlignment", nullptr);
    oluacls_const_integer(L, "CENTER", (lua_Integer)cocos2d::ui::RichText::HorizontalAlignment::CENTER);
    oluacls_const_integer(L, "LEFT", (lua_Integer)cocos2d::ui::RichText::HorizontalAlignment::LEFT);
    oluacls_const_integer(L, "RIGHT", (lua_Integer)cocos2d::ui::RichText::HorizontalAlignment::RIGHT);

    olua_registerluatype<cocos2d::ui::RichText::HorizontalAlignment>(L, "ccui.RichText.HorizontalAlignment");

    return 1;
}

static int _cocos2d_ui_RichText___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::ui::RichText *)olua_toobj(L, 1, "ccui.RichText");
    olua_push_cppobj(L, self, "ccui.RichText");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_ui_RichText_color3BWithString(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;
    std::string arg1;       /** color */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RichText");
    olua_check_std_string(L, 2, &arg1);

    // cocos2d::Color3B color3BWithString(const std::string &color)
    cocos2d::Color3B ret = (cocos2d::Color3B)self->color3BWithString(arg1);
    int num_ret = manual_olua_push_cocos2d_Color3B(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_RichText_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::ui::RichText *create()
    cocos2d::ui::RichText *ret = (cocos2d::ui::RichText *)cocos2d::ui::RichText::create();
    int num_ret = olua_push_cppobj(L, ret, "ccui.RichText");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_RichText_createWithXML1(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** xml */
    cocos2d::ValueMap arg2;       /** defaults */
    std::function<void(const std::string &)> arg3;       /** handleOpenUrl */

    olua_check_std_string(L, 1, &arg1);
    manual_olua_check_cocos2d_ValueMap(L, 2, &arg2);

    void *callback_store_obj = (void *)olua_allocobjstub(L, "ccui.RichText");
    std::string tag = "OpenUrlHandler";
    std::string func;
    if (olua_is_std_function(L, 3)) {
        func = olua_setcallback(L, callback_store_obj, tag.c_str(), 3, OLUA_TAG_REPLACE);
        lua_State *MT = olua_mainthread();
        arg3 = [callback_store_obj, func, MT](const std::string &arg1) {
            lua_State *L = olua_mainthread();

            if (MT == L) {
                int top = lua_gettop(L);
                olua_push_std_string(L, arg1);

                olua_callback(L, callback_store_obj, func.c_str(), 1);

                lua_settop(L, top);
            }
        };
    } else {
        olua_removecallback(L, callback_store_obj, tag.c_str(), OLUA_TAG_SUBEQUAL);
        arg3 = nullptr;
    }

    // static cocos2d::ui::RichText *createWithXML(const std::string &xml, @optional const cocos2d::ValueMap &defaults, @local @optional const std::function<void (const std::string &)> &handleOpenUrl)
    cocos2d::ui::RichText *ret = (cocos2d::ui::RichText *)cocos2d::ui::RichText::createWithXML(arg1, arg2, arg3);
    const char *cls = olua_getluatype(L, ret, "ccui.RichText");
    if (olua_pushobjstub(L, ret, callback_store_obj, cls) == OLUA_OBJ_EXIST) {
        olua_removecallback(L, callback_store_obj, tag.c_str(), OLUA_TAG_SUBEQUAL);
        lua_pushstring(L, func.c_str());
        lua_pushvalue(L, 3);
        olua_setvariable(L, -3);
    } else {
        olua_postpush(L, ret, OLUA_OBJ_NEW);
    };

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_ui_RichText_createWithXML2(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** xml */

    olua_check_std_string(L, 1, &arg1);

    // static cocos2d::ui::RichText *createWithXML(const std::string &xml, @optional const cocos2d::ValueMap &defaults, @local @optional const std::function<void (const std::string &)> &handleOpenUrl)
    cocos2d::ui::RichText *ret = (cocos2d::ui::RichText *)cocos2d::ui::RichText::createWithXML(arg1);
    int num_ret = olua_push_cppobj(L, ret, "ccui.RichText");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_RichText_createWithXML3(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** xml */
    cocos2d::ValueMap arg2;       /** defaults */

    olua_check_std_string(L, 1, &arg1);
    manual_olua_check_cocos2d_ValueMap(L, 2, &arg2);

    // static cocos2d::ui::RichText *createWithXML(const std::string &xml, @optional const cocos2d::ValueMap &defaults, @local @optional const std::function<void (const std::string &)> &handleOpenUrl)
    cocos2d::ui::RichText *ret = (cocos2d::ui::RichText *)cocos2d::ui::RichText::createWithXML(arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "ccui.RichText");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_RichText_createWithXML(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 1))) {
            // static cocos2d::ui::RichText *createWithXML(const std::string &xml, @optional const cocos2d::ValueMap &defaults, @local @optional const std::function<void (const std::string &)> &handleOpenUrl)
            return _cocos2d_ui_RichText_createWithXML2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 1)) && (manual_olua_is_cocos2d_ValueMap(L, 2))) {
            // static cocos2d::ui::RichText *createWithXML(const std::string &xml, @optional const cocos2d::ValueMap &defaults, @local @optional const std::function<void (const std::string &)> &handleOpenUrl)
            return _cocos2d_ui_RichText_createWithXML3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_std_string(L, 1)) && (manual_olua_is_cocos2d_ValueMap(L, 2)) && (olua_is_std_function(L, 3))) {
            // static cocos2d::ui::RichText *createWithXML(const std::string &xml, @optional const cocos2d::ValueMap &defaults, @local @optional const std::function<void (const std::string &)> &handleOpenUrl)
            return _cocos2d_ui_RichText_createWithXML1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::RichText::createWithXML' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ui_RichText_formatText(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RichText");

    // void formatText()
    self->formatText();

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_RichText_getAnchorFontColor(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RichText");

    // std::string getAnchorFontColor()
    std::string ret = (std::string)self->getAnchorFontColor();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_RichText_getAnchorFontColor3B(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RichText");

    // cocos2d::Color3B getAnchorFontColor3B()
    cocos2d::Color3B ret = (cocos2d::Color3B)self->getAnchorFontColor3B();
    int num_ret = manual_olua_push_cocos2d_Color3B(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_RichText_getAnchorTextGlowColor3B(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RichText");

    // cocos2d::Color3B getAnchorTextGlowColor3B()
    cocos2d::Color3B ret = (cocos2d::Color3B)self->getAnchorTextGlowColor3B();
    int num_ret = manual_olua_push_cocos2d_Color3B(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_RichText_getAnchorTextOutlineColor3B(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RichText");

    // cocos2d::Color3B getAnchorTextOutlineColor3B()
    cocos2d::Color3B ret = (cocos2d::Color3B)self->getAnchorTextOutlineColor3B();
    int num_ret = manual_olua_push_cocos2d_Color3B(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_RichText_getAnchorTextOutlineSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RichText");

    // int getAnchorTextOutlineSize()
    int ret = (int)self->getAnchorTextOutlineSize();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_RichText_getAnchorTextShadowBlurRadius(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RichText");

    // int getAnchorTextShadowBlurRadius()
    int ret = (int)self->getAnchorTextShadowBlurRadius();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_RichText_getAnchorTextShadowColor3B(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RichText");

    // cocos2d::Color3B getAnchorTextShadowColor3B()
    cocos2d::Color3B ret = (cocos2d::Color3B)self->getAnchorTextShadowColor3B();
    int num_ret = manual_olua_push_cocos2d_Color3B(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_RichText_getAnchorTextShadowOffset(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RichText");

    // cocos2d::Size getAnchorTextShadowOffset()
    cocos2d::Size ret = (cocos2d::Size)self->getAnchorTextShadowOffset();
    int num_ret = auto_olua_push_cocos2d_Size(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_RichText_getDefaults(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RichText");

    // cocos2d::ValueMap getDefaults()
    cocos2d::ValueMap ret = (cocos2d::ValueMap)self->getDefaults();
    int num_ret = manual_olua_push_cocos2d_ValueMap(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_RichText_getFontColor(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RichText");

    // std::string getFontColor()
    std::string ret = (std::string)self->getFontColor();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_RichText_getFontColor3B(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RichText");

    // cocos2d::Color3B getFontColor3B()
    cocos2d::Color3B ret = (cocos2d::Color3B)self->getFontColor3B();
    int num_ret = manual_olua_push_cocos2d_Color3B(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_RichText_getFontFace(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RichText");

    // std::string getFontFace()
    std::string ret = (std::string)self->getFontFace();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_RichText_getFontSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RichText");

    // float getFontSize()
    float ret = (float)self->getFontSize();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_RichText_getHorizontalAlignment(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RichText");

    // cocos2d::ui::RichText::HorizontalAlignment getHorizontalAlignment()
    cocos2d::ui::RichText::HorizontalAlignment ret = (cocos2d::ui::RichText::HorizontalAlignment)self->getHorizontalAlignment();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_RichText_getWrapMode(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RichText");

    // cocos2d::ui::RichText::WrapMode getWrapMode()
    cocos2d::ui::RichText::WrapMode ret = (cocos2d::ui::RichText::WrapMode)self->getWrapMode();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_RichText_insertElement(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;
    cocos2d::ui::RichElement *arg1 = nullptr;       /** element */
    lua_Integer arg2 = 0;       /** index */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RichText");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccui.RichElement");
    olua_check_int(L, 3, &arg2);

    // void insertElement(cocos2d::ui::RichElement *element, int index)
    self->insertElement(arg1, (int)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_RichText_isAnchorTextBoldEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RichText");

    // bool isAnchorTextBoldEnabled()
    bool ret = (bool)self->isAnchorTextBoldEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_RichText_isAnchorTextDelEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RichText");

    // bool isAnchorTextDelEnabled()
    bool ret = (bool)self->isAnchorTextDelEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_RichText_isAnchorTextGlowEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RichText");

    // bool isAnchorTextGlowEnabled()
    bool ret = (bool)self->isAnchorTextGlowEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_RichText_isAnchorTextItalicEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RichText");

    // bool isAnchorTextItalicEnabled()
    bool ret = (bool)self->isAnchorTextItalicEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_RichText_isAnchorTextOutlineEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RichText");

    // bool isAnchorTextOutlineEnabled()
    bool ret = (bool)self->isAnchorTextOutlineEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_RichText_isAnchorTextShadowEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RichText");

    // bool isAnchorTextShadowEnabled()
    bool ret = (bool)self->isAnchorTextShadowEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_RichText_isAnchorTextUnderlineEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RichText");

    // bool isAnchorTextUnderlineEnabled()
    bool ret = (bool)self->isAnchorTextUnderlineEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_RichText_new(lua_State *L)
{
    olua_startinvoke(L);

    // RichText()
    cocos2d::ui::RichText *ret = (cocos2d::ui::RichText *)new cocos2d::ui::RichText();
    int num_ret = olua_push_cppobj(L, ret, "ccui.RichText");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_RichText_openUrl(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;
    std::string arg1;       /** url */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RichText");
    olua_check_std_string(L, 2, &arg1);

    // void openUrl(const std::string &url)
    self->openUrl(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_RichText_pushBackElement(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;
    cocos2d::ui::RichElement *arg1 = nullptr;       /** element */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RichText");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccui.RichElement");

    // void pushBackElement(cocos2d::ui::RichElement *element)
    self->pushBackElement(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_RichText_removeElement1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;
    lua_Integer arg1 = 0;       /** index */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RichText");
    olua_check_int(L, 2, &arg1);

    // void removeElement(int index)
    self->removeElement((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_RichText_removeElement2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;
    cocos2d::ui::RichElement *arg1 = nullptr;       /** element */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RichText");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccui.RichElement");

    // void removeElement(cocos2d::ui::RichElement *element)
    self->removeElement(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_RichText_removeElement(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        if ((olua_is_int(L, 2))) {
            // void removeElement(int index)
            return _cocos2d_ui_RichText_removeElement1(L);
        }

        // if ((olua_is_cppobj(L, 2, "ccui.RichElement"))) {
            // void removeElement(cocos2d::ui::RichElement *element)
            return _cocos2d_ui_RichText_removeElement2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::RichText::removeElement' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ui_RichText_removeTagDescription(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** tag */

    olua_check_std_string(L, 1, &arg1);

    // static void removeTagDescription(const std::string &tag)
    cocos2d::ui::RichText::removeTagDescription(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_RichText_setAnchorFontColor(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;
    std::string arg1;       /** color */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RichText");
    olua_check_std_string(L, 2, &arg1);

    // void setAnchorFontColor(const std::string &color)
    self->setAnchorFontColor(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_RichText_setAnchorTextBold(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;
    bool arg1 = false;       /** enable */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RichText");
    olua_check_bool(L, 2, &arg1);

    // void setAnchorTextBold(bool enable)
    self->setAnchorTextBold(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_RichText_setAnchorTextDel(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;
    bool arg1 = false;       /** enable */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RichText");
    olua_check_bool(L, 2, &arg1);

    // void setAnchorTextDel(bool enable)
    self->setAnchorTextDel(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_RichText_setAnchorTextGlow1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;
    bool arg1 = false;       /** enable */
    cocos2d::Color3B arg2;       /** glowColor */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RichText");
    olua_check_bool(L, 2, &arg1);
    manual_olua_check_cocos2d_Color3B(L, 3, &arg2);

    // void setAnchorTextGlow(bool enable, @optional const cocos2d::Color3B &glowColor)
    self->setAnchorTextGlow(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_RichText_setAnchorTextGlow2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;
    bool arg1 = false;       /** enable */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RichText");
    olua_check_bool(L, 2, &arg1);

    // void setAnchorTextGlow(bool enable, @optional const cocos2d::Color3B &glowColor)
    self->setAnchorTextGlow(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_RichText_setAnchorTextGlow(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_bool(L, 2))) {
            // void setAnchorTextGlow(bool enable, @optional const cocos2d::Color3B &glowColor)
            return _cocos2d_ui_RichText_setAnchorTextGlow2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_bool(L, 2)) && (manual_olua_is_cocos2d_Color3B(L, 3))) {
            // void setAnchorTextGlow(bool enable, @optional const cocos2d::Color3B &glowColor)
            return _cocos2d_ui_RichText_setAnchorTextGlow1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::RichText::setAnchorTextGlow' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ui_RichText_setAnchorTextItalic(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;
    bool arg1 = false;       /** enable */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RichText");
    olua_check_bool(L, 2, &arg1);

    // void setAnchorTextItalic(bool enable)
    self->setAnchorTextItalic(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_RichText_setAnchorTextOutline1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;
    bool arg1 = false;       /** enable */
    cocos2d::Color3B arg2;       /** outlineColor */
    lua_Integer arg3 = 0;       /** outlineSize */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RichText");
    olua_check_bool(L, 2, &arg1);
    manual_olua_check_cocos2d_Color3B(L, 3, &arg2);
    olua_check_int(L, 4, &arg3);

    // void setAnchorTextOutline(bool enable, @optional const cocos2d::Color3B &outlineColor, @optional int outlineSize)
    self->setAnchorTextOutline(arg1, arg2, (int)arg3);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_RichText_setAnchorTextOutline2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;
    bool arg1 = false;       /** enable */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RichText");
    olua_check_bool(L, 2, &arg1);

    // void setAnchorTextOutline(bool enable, @optional const cocos2d::Color3B &outlineColor, @optional int outlineSize)
    self->setAnchorTextOutline(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_RichText_setAnchorTextOutline3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;
    bool arg1 = false;       /** enable */
    cocos2d::Color3B arg2;       /** outlineColor */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RichText");
    olua_check_bool(L, 2, &arg1);
    manual_olua_check_cocos2d_Color3B(L, 3, &arg2);

    // void setAnchorTextOutline(bool enable, @optional const cocos2d::Color3B &outlineColor, @optional int outlineSize)
    self->setAnchorTextOutline(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_RichText_setAnchorTextOutline(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_bool(L, 2))) {
            // void setAnchorTextOutline(bool enable, @optional const cocos2d::Color3B &outlineColor, @optional int outlineSize)
            return _cocos2d_ui_RichText_setAnchorTextOutline2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_bool(L, 2)) && (manual_olua_is_cocos2d_Color3B(L, 3))) {
            // void setAnchorTextOutline(bool enable, @optional const cocos2d::Color3B &outlineColor, @optional int outlineSize)
            return _cocos2d_ui_RichText_setAnchorTextOutline3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_bool(L, 2)) && (manual_olua_is_cocos2d_Color3B(L, 3)) && (olua_is_int(L, 4))) {
            // void setAnchorTextOutline(bool enable, @optional const cocos2d::Color3B &outlineColor, @optional int outlineSize)
            return _cocos2d_ui_RichText_setAnchorTextOutline1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::RichText::setAnchorTextOutline' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ui_RichText_setAnchorTextShadow1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;
    bool arg1 = false;       /** enable */
    cocos2d::Color3B arg2;       /** shadowColor */
    cocos2d::Size arg3;       /** offset */
    lua_Integer arg4 = 0;       /** blurRadius */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RichText");
    olua_check_bool(L, 2, &arg1);
    manual_olua_check_cocos2d_Color3B(L, 3, &arg2);
    auto_olua_check_cocos2d_Size(L, 4, &arg3);
    olua_check_int(L, 5, &arg4);

    // void setAnchorTextShadow(bool enable, @optional const cocos2d::Color3B &shadowColor, @optional const cocos2d::Size &offset, @optional int blurRadius)
    self->setAnchorTextShadow(arg1, arg2, arg3, (int)arg4);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_RichText_setAnchorTextShadow2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;
    bool arg1 = false;       /** enable */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RichText");
    olua_check_bool(L, 2, &arg1);

    // void setAnchorTextShadow(bool enable, @optional const cocos2d::Color3B &shadowColor, @optional const cocos2d::Size &offset, @optional int blurRadius)
    self->setAnchorTextShadow(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_RichText_setAnchorTextShadow3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;
    bool arg1 = false;       /** enable */
    cocos2d::Color3B arg2;       /** shadowColor */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RichText");
    olua_check_bool(L, 2, &arg1);
    manual_olua_check_cocos2d_Color3B(L, 3, &arg2);

    // void setAnchorTextShadow(bool enable, @optional const cocos2d::Color3B &shadowColor, @optional const cocos2d::Size &offset, @optional int blurRadius)
    self->setAnchorTextShadow(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_RichText_setAnchorTextShadow4(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;
    bool arg1 = false;       /** enable */
    cocos2d::Color3B arg2;       /** shadowColor */
    cocos2d::Size arg3;       /** offset */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RichText");
    olua_check_bool(L, 2, &arg1);
    manual_olua_check_cocos2d_Color3B(L, 3, &arg2);
    auto_olua_check_cocos2d_Size(L, 4, &arg3);

    // void setAnchorTextShadow(bool enable, @optional const cocos2d::Color3B &shadowColor, @optional const cocos2d::Size &offset, @optional int blurRadius)
    self->setAnchorTextShadow(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_RichText_setAnchorTextShadow(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_bool(L, 2))) {
            // void setAnchorTextShadow(bool enable, @optional const cocos2d::Color3B &shadowColor, @optional const cocos2d::Size &offset, @optional int blurRadius)
            return _cocos2d_ui_RichText_setAnchorTextShadow2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_bool(L, 2)) && (manual_olua_is_cocos2d_Color3B(L, 3))) {
            // void setAnchorTextShadow(bool enable, @optional const cocos2d::Color3B &shadowColor, @optional const cocos2d::Size &offset, @optional int blurRadius)
            return _cocos2d_ui_RichText_setAnchorTextShadow3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_bool(L, 2)) && (manual_olua_is_cocos2d_Color3B(L, 3)) && (auto_olua_is_cocos2d_Size(L, 4))) {
            // void setAnchorTextShadow(bool enable, @optional const cocos2d::Color3B &shadowColor, @optional const cocos2d::Size &offset, @optional int blurRadius)
            return _cocos2d_ui_RichText_setAnchorTextShadow4(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_bool(L, 2)) && (manual_olua_is_cocos2d_Color3B(L, 3)) && (auto_olua_is_cocos2d_Size(L, 4)) && (olua_is_int(L, 5))) {
            // void setAnchorTextShadow(bool enable, @optional const cocos2d::Color3B &shadowColor, @optional const cocos2d::Size &offset, @optional int blurRadius)
            return _cocos2d_ui_RichText_setAnchorTextShadow1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::RichText::setAnchorTextShadow' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ui_RichText_setAnchorTextUnderline(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;
    bool arg1 = false;       /** enable */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RichText");
    olua_check_bool(L, 2, &arg1);

    // void setAnchorTextUnderline(bool enable)
    self->setAnchorTextUnderline(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_RichText_setDefaults(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;
    cocos2d::ValueMap arg1;       /** defaults */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RichText");
    manual_olua_check_cocos2d_ValueMap(L, 2, &arg1);

    // void setDefaults(const cocos2d::ValueMap &defaults)
    self->setDefaults(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_RichText_setFontColor(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;
    std::string arg1;       /** color */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RichText");
    olua_check_std_string(L, 2, &arg1);

    // void setFontColor(const std::string &color)
    self->setFontColor(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_RichText_setFontFace(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;
    std::string arg1;       /** face */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RichText");
    olua_check_std_string(L, 2, &arg1);

    // void setFontFace(const std::string &face)
    self->setFontFace(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_RichText_setFontSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;
    lua_Number arg1 = 0;       /** size */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RichText");
    olua_check_number(L, 2, &arg1);

    // void setFontSize(float size)
    self->setFontSize((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_RichText_setHorizontalAlignment(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;
    lua_Unsigned arg1 = 0;       /** a */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RichText");
    olua_check_uint(L, 2, &arg1);

    // void setHorizontalAlignment(cocos2d::ui::RichText::HorizontalAlignment a)
    self->setHorizontalAlignment((cocos2d::ui::RichText::HorizontalAlignment)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_RichText_setOpenUrlHandler(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;
    std::function<void(const std::string &)> arg1;       /** handleOpenUrl */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RichText");

    void *callback_store_obj = (void *)self;
    std::string tag = "OpenUrlHandler";
    std::string func = olua_setcallback(L, callback_store_obj, tag.c_str(), 2, OLUA_TAG_REPLACE);
    lua_State *MT = olua_mainthread();
    arg1 = [callback_store_obj, func, MT](const std::string &arg1) {
        lua_State *L = olua_mainthread();

        if (MT == L) {
            int top = lua_gettop(L);
            olua_push_std_string(L, arg1);

            olua_callback(L, callback_store_obj, func.c_str(), 1);

            lua_settop(L, top);
        }
    };

    // void setOpenUrlHandler(@local const std::function<void (const std::string &)> &handleOpenUrl)
    self->setOpenUrlHandler(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_RichText_setVerticalSpace(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;
    lua_Number arg1 = 0;       /** space */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RichText");
    olua_check_number(L, 2, &arg1);

    // void setVerticalSpace(float space)
    self->setVerticalSpace((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_RichText_setWrapMode(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;
    lua_Unsigned arg1 = 0;       /** wrapMode */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RichText");
    olua_check_uint(L, 2, &arg1);

    // void setWrapMode(cocos2d::ui::RichText::WrapMode wrapMode)
    self->setWrapMode((cocos2d::ui::RichText::WrapMode)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_RichText_stringWithColor3B(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;
    cocos2d::Color3B arg1;       /** color3b */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RichText");
    manual_olua_check_cocos2d_Color3B(L, 2, &arg1);

    // std::string stringWithColor3B(const cocos2d::Color3B &color3b)
    std::string ret = (std::string)self->stringWithColor3B(arg1);
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_RichText_stringWithColor4B(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RichText *self = nullptr;
    cocos2d::Color4B arg1;       /** color4b */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RichText");
    manual_olua_check_cocos2d_Color4B(L, 2, &arg1);

    // std::string stringWithColor4B(const cocos2d::Color4B &color4b)
    std::string ret = (std::string)self->stringWithColor4B(arg1);
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_ui_RichText(lua_State *L)
{
    oluacls_class(L, "ccui.RichText", "ccui.Widget");
    oluacls_func(L, "__move", _cocos2d_ui_RichText___move);
    oluacls_func(L, "color3BWithString", _cocos2d_ui_RichText_color3BWithString);
    oluacls_func(L, "create", _cocos2d_ui_RichText_create);
    oluacls_func(L, "createWithXML", _cocos2d_ui_RichText_createWithXML);
    oluacls_func(L, "formatText", _cocos2d_ui_RichText_formatText);
    oluacls_func(L, "getAnchorFontColor", _cocos2d_ui_RichText_getAnchorFontColor);
    oluacls_func(L, "getAnchorFontColor3B", _cocos2d_ui_RichText_getAnchorFontColor3B);
    oluacls_func(L, "getAnchorTextGlowColor3B", _cocos2d_ui_RichText_getAnchorTextGlowColor3B);
    oluacls_func(L, "getAnchorTextOutlineColor3B", _cocos2d_ui_RichText_getAnchorTextOutlineColor3B);
    oluacls_func(L, "getAnchorTextOutlineSize", _cocos2d_ui_RichText_getAnchorTextOutlineSize);
    oluacls_func(L, "getAnchorTextShadowBlurRadius", _cocos2d_ui_RichText_getAnchorTextShadowBlurRadius);
    oluacls_func(L, "getAnchorTextShadowColor3B", _cocos2d_ui_RichText_getAnchorTextShadowColor3B);
    oluacls_func(L, "getAnchorTextShadowOffset", _cocos2d_ui_RichText_getAnchorTextShadowOffset);
    oluacls_func(L, "getDefaults", _cocos2d_ui_RichText_getDefaults);
    oluacls_func(L, "getFontColor", _cocos2d_ui_RichText_getFontColor);
    oluacls_func(L, "getFontColor3B", _cocos2d_ui_RichText_getFontColor3B);
    oluacls_func(L, "getFontFace", _cocos2d_ui_RichText_getFontFace);
    oluacls_func(L, "getFontSize", _cocos2d_ui_RichText_getFontSize);
    oluacls_func(L, "getHorizontalAlignment", _cocos2d_ui_RichText_getHorizontalAlignment);
    oluacls_func(L, "getWrapMode", _cocos2d_ui_RichText_getWrapMode);
    oluacls_func(L, "insertElement", _cocos2d_ui_RichText_insertElement);
    oluacls_func(L, "isAnchorTextBoldEnabled", _cocos2d_ui_RichText_isAnchorTextBoldEnabled);
    oluacls_func(L, "isAnchorTextDelEnabled", _cocos2d_ui_RichText_isAnchorTextDelEnabled);
    oluacls_func(L, "isAnchorTextGlowEnabled", _cocos2d_ui_RichText_isAnchorTextGlowEnabled);
    oluacls_func(L, "isAnchorTextItalicEnabled", _cocos2d_ui_RichText_isAnchorTextItalicEnabled);
    oluacls_func(L, "isAnchorTextOutlineEnabled", _cocos2d_ui_RichText_isAnchorTextOutlineEnabled);
    oluacls_func(L, "isAnchorTextShadowEnabled", _cocos2d_ui_RichText_isAnchorTextShadowEnabled);
    oluacls_func(L, "isAnchorTextUnderlineEnabled", _cocos2d_ui_RichText_isAnchorTextUnderlineEnabled);
    oluacls_func(L, "new", _cocos2d_ui_RichText_new);
    oluacls_func(L, "openUrl", _cocos2d_ui_RichText_openUrl);
    oluacls_func(L, "pushBackElement", _cocos2d_ui_RichText_pushBackElement);
    oluacls_func(L, "removeElement", _cocos2d_ui_RichText_removeElement);
    oluacls_func(L, "removeTagDescription", _cocos2d_ui_RichText_removeTagDescription);
    oluacls_func(L, "setAnchorFontColor", _cocos2d_ui_RichText_setAnchorFontColor);
    oluacls_func(L, "setAnchorTextBold", _cocos2d_ui_RichText_setAnchorTextBold);
    oluacls_func(L, "setAnchorTextDel", _cocos2d_ui_RichText_setAnchorTextDel);
    oluacls_func(L, "setAnchorTextGlow", _cocos2d_ui_RichText_setAnchorTextGlow);
    oluacls_func(L, "setAnchorTextItalic", _cocos2d_ui_RichText_setAnchorTextItalic);
    oluacls_func(L, "setAnchorTextOutline", _cocos2d_ui_RichText_setAnchorTextOutline);
    oluacls_func(L, "setAnchorTextShadow", _cocos2d_ui_RichText_setAnchorTextShadow);
    oluacls_func(L, "setAnchorTextUnderline", _cocos2d_ui_RichText_setAnchorTextUnderline);
    oluacls_func(L, "setDefaults", _cocos2d_ui_RichText_setDefaults);
    oluacls_func(L, "setFontColor", _cocos2d_ui_RichText_setFontColor);
    oluacls_func(L, "setFontFace", _cocos2d_ui_RichText_setFontFace);
    oluacls_func(L, "setFontSize", _cocos2d_ui_RichText_setFontSize);
    oluacls_func(L, "setHorizontalAlignment", _cocos2d_ui_RichText_setHorizontalAlignment);
    oluacls_func(L, "setOpenUrlHandler", _cocos2d_ui_RichText_setOpenUrlHandler);
    oluacls_func(L, "setVerticalSpace", _cocos2d_ui_RichText_setVerticalSpace);
    oluacls_func(L, "setWrapMode", _cocos2d_ui_RichText_setWrapMode);
    oluacls_func(L, "stringWithColor3B", _cocos2d_ui_RichText_stringWithColor3B);
    oluacls_func(L, "stringWithColor4B", _cocos2d_ui_RichText_stringWithColor4B);
    oluacls_prop(L, "anchorFontColor", _cocos2d_ui_RichText_getAnchorFontColor, _cocos2d_ui_RichText_setAnchorFontColor);
    oluacls_prop(L, "anchorFontColor3B", _cocos2d_ui_RichText_getAnchorFontColor3B, nullptr);
    oluacls_prop(L, "anchorTextBoldEnabled", _cocos2d_ui_RichText_isAnchorTextBoldEnabled, nullptr);
    oluacls_prop(L, "anchorTextDelEnabled", _cocos2d_ui_RichText_isAnchorTextDelEnabled, nullptr);
    oluacls_prop(L, "anchorTextGlowColor3B", _cocos2d_ui_RichText_getAnchorTextGlowColor3B, nullptr);
    oluacls_prop(L, "anchorTextGlowEnabled", _cocos2d_ui_RichText_isAnchorTextGlowEnabled, nullptr);
    oluacls_prop(L, "anchorTextItalicEnabled", _cocos2d_ui_RichText_isAnchorTextItalicEnabled, nullptr);
    oluacls_prop(L, "anchorTextOutlineColor3B", _cocos2d_ui_RichText_getAnchorTextOutlineColor3B, nullptr);
    oluacls_prop(L, "anchorTextOutlineEnabled", _cocos2d_ui_RichText_isAnchorTextOutlineEnabled, nullptr);
    oluacls_prop(L, "anchorTextOutlineSize", _cocos2d_ui_RichText_getAnchorTextOutlineSize, nullptr);
    oluacls_prop(L, "anchorTextShadowBlurRadius", _cocos2d_ui_RichText_getAnchorTextShadowBlurRadius, nullptr);
    oluacls_prop(L, "anchorTextShadowColor3B", _cocos2d_ui_RichText_getAnchorTextShadowColor3B, nullptr);
    oluacls_prop(L, "anchorTextShadowEnabled", _cocos2d_ui_RichText_isAnchorTextShadowEnabled, nullptr);
    oluacls_prop(L, "anchorTextShadowOffset", _cocos2d_ui_RichText_getAnchorTextShadowOffset, nullptr);
    oluacls_prop(L, "anchorTextUnderlineEnabled", _cocos2d_ui_RichText_isAnchorTextUnderlineEnabled, nullptr);
    oluacls_prop(L, "defaults", _cocos2d_ui_RichText_getDefaults, _cocos2d_ui_RichText_setDefaults);
    oluacls_prop(L, "fontColor", _cocos2d_ui_RichText_getFontColor, _cocos2d_ui_RichText_setFontColor);
    oluacls_prop(L, "fontColor3B", _cocos2d_ui_RichText_getFontColor3B, nullptr);
    oluacls_prop(L, "fontFace", _cocos2d_ui_RichText_getFontFace, _cocos2d_ui_RichText_setFontFace);
    oluacls_prop(L, "fontSize", _cocos2d_ui_RichText_getFontSize, _cocos2d_ui_RichText_setFontSize);
    oluacls_prop(L, "horizontalAlignment", _cocos2d_ui_RichText_getHorizontalAlignment, _cocos2d_ui_RichText_setHorizontalAlignment);
    oluacls_prop(L, "wrapMode", _cocos2d_ui_RichText_getWrapMode, _cocos2d_ui_RichText_setWrapMode);
    oluacls_const_string(L, "KEY_ANCHOR_FONT_COLOR_STRING", (const char *)cocos2d::ui::RichText::KEY_ANCHOR_FONT_COLOR_STRING.c_str());
    oluacls_const_string(L, "KEY_ANCHOR_TEXT_BOLD", (const char *)cocos2d::ui::RichText::KEY_ANCHOR_TEXT_BOLD.c_str());
    oluacls_const_string(L, "KEY_ANCHOR_TEXT_GLOW_COLOR", (const char *)cocos2d::ui::RichText::KEY_ANCHOR_TEXT_GLOW_COLOR.c_str());
    oluacls_const_string(L, "KEY_ANCHOR_TEXT_ITALIC", (const char *)cocos2d::ui::RichText::KEY_ANCHOR_TEXT_ITALIC.c_str());
    oluacls_const_string(L, "KEY_ANCHOR_TEXT_LINE", (const char *)cocos2d::ui::RichText::KEY_ANCHOR_TEXT_LINE.c_str());
    oluacls_const_string(L, "KEY_ANCHOR_TEXT_OUTLINE_COLOR", (const char *)cocos2d::ui::RichText::KEY_ANCHOR_TEXT_OUTLINE_COLOR.c_str());
    oluacls_const_string(L, "KEY_ANCHOR_TEXT_OUTLINE_SIZE", (const char *)cocos2d::ui::RichText::KEY_ANCHOR_TEXT_OUTLINE_SIZE.c_str());
    oluacls_const_string(L, "KEY_ANCHOR_TEXT_SHADOW_BLUR_RADIUS", (const char *)cocos2d::ui::RichText::KEY_ANCHOR_TEXT_SHADOW_BLUR_RADIUS.c_str());
    oluacls_const_string(L, "KEY_ANCHOR_TEXT_SHADOW_COLOR", (const char *)cocos2d::ui::RichText::KEY_ANCHOR_TEXT_SHADOW_COLOR.c_str());
    oluacls_const_string(L, "KEY_ANCHOR_TEXT_SHADOW_OFFSET_HEIGHT", (const char *)cocos2d::ui::RichText::KEY_ANCHOR_TEXT_SHADOW_OFFSET_HEIGHT.c_str());
    oluacls_const_string(L, "KEY_ANCHOR_TEXT_SHADOW_OFFSET_WIDTH", (const char *)cocos2d::ui::RichText::KEY_ANCHOR_TEXT_SHADOW_OFFSET_WIDTH.c_str());
    oluacls_const_string(L, "KEY_ANCHOR_TEXT_STYLE", (const char *)cocos2d::ui::RichText::KEY_ANCHOR_TEXT_STYLE.c_str());
    oluacls_const_string(L, "KEY_FONT_BIG", (const char *)cocos2d::ui::RichText::KEY_FONT_BIG.c_str());
    oluacls_const_string(L, "KEY_FONT_COLOR_STRING", (const char *)cocos2d::ui::RichText::KEY_FONT_COLOR_STRING.c_str());
    oluacls_const_string(L, "KEY_FONT_FACE", (const char *)cocos2d::ui::RichText::KEY_FONT_FACE.c_str());
    oluacls_const_string(L, "KEY_FONT_SIZE", (const char *)cocos2d::ui::RichText::KEY_FONT_SIZE.c_str());
    oluacls_const_string(L, "KEY_FONT_SMALL", (const char *)cocos2d::ui::RichText::KEY_FONT_SMALL.c_str());
    oluacls_const_string(L, "KEY_HORIZONTAL_ALIGNMENT", (const char *)cocos2d::ui::RichText::KEY_HORIZONTAL_ALIGNMENT.c_str());
    oluacls_const_string(L, "KEY_TEXT_BOLD", (const char *)cocos2d::ui::RichText::KEY_TEXT_BOLD.c_str());
    oluacls_const_string(L, "KEY_TEXT_GLOW_COLOR", (const char *)cocos2d::ui::RichText::KEY_TEXT_GLOW_COLOR.c_str());
    oluacls_const_string(L, "KEY_TEXT_ITALIC", (const char *)cocos2d::ui::RichText::KEY_TEXT_ITALIC.c_str());
    oluacls_const_string(L, "KEY_TEXT_LINE", (const char *)cocos2d::ui::RichText::KEY_TEXT_LINE.c_str());
    oluacls_const_string(L, "KEY_TEXT_OUTLINE_COLOR", (const char *)cocos2d::ui::RichText::KEY_TEXT_OUTLINE_COLOR.c_str());
    oluacls_const_string(L, "KEY_TEXT_OUTLINE_SIZE", (const char *)cocos2d::ui::RichText::KEY_TEXT_OUTLINE_SIZE.c_str());
    oluacls_const_string(L, "KEY_TEXT_SHADOW_BLUR_RADIUS", (const char *)cocos2d::ui::RichText::KEY_TEXT_SHADOW_BLUR_RADIUS.c_str());
    oluacls_const_string(L, "KEY_TEXT_SHADOW_COLOR", (const char *)cocos2d::ui::RichText::KEY_TEXT_SHADOW_COLOR.c_str());
    oluacls_const_string(L, "KEY_TEXT_SHADOW_OFFSET_HEIGHT", (const char *)cocos2d::ui::RichText::KEY_TEXT_SHADOW_OFFSET_HEIGHT.c_str());
    oluacls_const_string(L, "KEY_TEXT_SHADOW_OFFSET_WIDTH", (const char *)cocos2d::ui::RichText::KEY_TEXT_SHADOW_OFFSET_WIDTH.c_str());
    oluacls_const_string(L, "KEY_TEXT_STYLE", (const char *)cocos2d::ui::RichText::KEY_TEXT_STYLE.c_str());
    oluacls_const_string(L, "KEY_URL", (const char *)cocos2d::ui::RichText::KEY_URL.c_str());
    oluacls_const_string(L, "KEY_VERTICAL_SPACE", (const char *)cocos2d::ui::RichText::KEY_VERTICAL_SPACE.c_str());
    oluacls_const_string(L, "KEY_WRAP_MODE", (const char *)cocos2d::ui::RichText::KEY_WRAP_MODE.c_str());
    oluacls_const_string(L, "VALUE_TEXT_LINE_DEL", (const char *)cocos2d::ui::RichText::VALUE_TEXT_LINE_DEL.c_str());
    oluacls_const_string(L, "VALUE_TEXT_LINE_NONE", (const char *)cocos2d::ui::RichText::VALUE_TEXT_LINE_NONE.c_str());
    oluacls_const_string(L, "VALUE_TEXT_LINE_UNDER", (const char *)cocos2d::ui::RichText::VALUE_TEXT_LINE_UNDER.c_str());
    oluacls_const_string(L, "VALUE_TEXT_STYLE_GLOW", (const char *)cocos2d::ui::RichText::VALUE_TEXT_STYLE_GLOW.c_str());
    oluacls_const_string(L, "VALUE_TEXT_STYLE_NONE", (const char *)cocos2d::ui::RichText::VALUE_TEXT_STYLE_NONE.c_str());
    oluacls_const_string(L, "VALUE_TEXT_STYLE_OUTLINE", (const char *)cocos2d::ui::RichText::VALUE_TEXT_STYLE_OUTLINE.c_str());
    oluacls_const_string(L, "VALUE_TEXT_STYLE_SHADOW", (const char *)cocos2d::ui::RichText::VALUE_TEXT_STYLE_SHADOW.c_str());

    olua_registerluatype<cocos2d::ui::RichText>(L, "ccui.RichText");

    return 1;
}

static int _cocos2d_ui_ScrollViewBar___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::ui::ScrollViewBar *)olua_toobj(L, 1, "ccui.ScrollViewBar");
    olua_push_cppobj(L, self, "ccui.ScrollViewBar");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_ui_ScrollViewBar_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *arg1 = nullptr;       /** parent */
    lua_Unsigned arg2 = 0;       /** direction */

    olua_check_cppobj(L, 1, (void **)&arg1, "ccui.ScrollView");
    olua_check_uint(L, 2, &arg2);

    // static cocos2d::ui::ScrollViewBar *create(cocos2d::ui::ScrollView *parent, ScrollView::Direction direction)
    cocos2d::ui::ScrollViewBar *ret = (cocos2d::ui::ScrollViewBar *)cocos2d::ui::ScrollViewBar::create(arg1, (cocos2d::ui::ScrollView::Direction)arg2);
    int num_ret = olua_push_cppobj(L, ret, "ccui.ScrollViewBar");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_ScrollViewBar_getAutoHideTime(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollViewBar *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ScrollViewBar");

    // float getAutoHideTime()
    float ret = (float)self->getAutoHideTime();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_ScrollViewBar_getPositionFromCorner(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollViewBar *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ScrollViewBar");

    // cocos2d::Vec2 getPositionFromCorner()
    cocos2d::Vec2 ret = (cocos2d::Vec2)self->getPositionFromCorner();
    int num_ret = auto_olua_push_cocos2d_Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_ScrollViewBar_getWidth(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollViewBar *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ScrollViewBar");

    // float getWidth()
    float ret = (float)self->getWidth();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_ScrollViewBar_isAutoHideEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollViewBar *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ScrollViewBar");

    // bool isAutoHideEnabled()
    bool ret = (bool)self->isAutoHideEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_ScrollViewBar_new(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollView *arg1 = nullptr;       /** parent */
    lua_Unsigned arg2 = 0;       /** direction */

    olua_check_cppobj(L, 1, (void **)&arg1, "ccui.ScrollView");
    olua_check_uint(L, 2, &arg2);

    // ScrollViewBar(cocos2d::ui::ScrollView *parent, ScrollView::Direction direction)
    cocos2d::ui::ScrollViewBar *ret = (cocos2d::ui::ScrollViewBar *)new cocos2d::ui::ScrollViewBar(arg1, (cocos2d::ui::ScrollView::Direction)arg2);
    int num_ret = olua_push_cppobj(L, ret, "ccui.ScrollViewBar");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_ScrollViewBar_onScrolled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollViewBar *self = nullptr;
    cocos2d::Vec2 arg1;       /** outOfBoundary */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ScrollViewBar");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);

    // void onScrolled(const cocos2d::Vec2 &outOfBoundary)
    self->onScrolled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_ScrollViewBar_onTouchBegan(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollViewBar *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ScrollViewBar");

    // void onTouchBegan()
    self->onTouchBegan();

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_ScrollViewBar_onTouchEnded(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollViewBar *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ScrollViewBar");

    // void onTouchEnded()
    self->onTouchEnded();

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_ScrollViewBar_setAutoHideEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollViewBar *self = nullptr;
    bool arg1 = false;       /** autoHideEnabled */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ScrollViewBar");
    olua_check_bool(L, 2, &arg1);

    // void setAutoHideEnabled(bool autoHideEnabled)
    self->setAutoHideEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_ScrollViewBar_setAutoHideTime(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollViewBar *self = nullptr;
    lua_Number arg1 = 0;       /** autoHideTime */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ScrollViewBar");
    olua_check_number(L, 2, &arg1);

    // void setAutoHideTime(float autoHideTime)
    self->setAutoHideTime((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_ScrollViewBar_setPositionFromCorner(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollViewBar *self = nullptr;
    cocos2d::Vec2 arg1;       /** positionFromCorner */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ScrollViewBar");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);

    // void setPositionFromCorner(const cocos2d::Vec2 &positionFromCorner)
    self->setPositionFromCorner(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_ScrollViewBar_setWidth(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ScrollViewBar *self = nullptr;
    lua_Number arg1 = 0;       /** width */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ScrollViewBar");
    olua_check_number(L, 2, &arg1);

    // void setWidth(float width)
    self->setWidth((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_ui_ScrollViewBar(lua_State *L)
{
    oluacls_class(L, "ccui.ScrollViewBar", "cc.ProtectedNode");
    oluacls_func(L, "__move", _cocos2d_ui_ScrollViewBar___move);
    oluacls_func(L, "create", _cocos2d_ui_ScrollViewBar_create);
    oluacls_func(L, "getAutoHideTime", _cocos2d_ui_ScrollViewBar_getAutoHideTime);
    oluacls_func(L, "getPositionFromCorner", _cocos2d_ui_ScrollViewBar_getPositionFromCorner);
    oluacls_func(L, "getWidth", _cocos2d_ui_ScrollViewBar_getWidth);
    oluacls_func(L, "isAutoHideEnabled", _cocos2d_ui_ScrollViewBar_isAutoHideEnabled);
    oluacls_func(L, "new", _cocos2d_ui_ScrollViewBar_new);
    oluacls_func(L, "onScrolled", _cocos2d_ui_ScrollViewBar_onScrolled);
    oluacls_func(L, "onTouchBegan", _cocos2d_ui_ScrollViewBar_onTouchBegan);
    oluacls_func(L, "onTouchEnded", _cocos2d_ui_ScrollViewBar_onTouchEnded);
    oluacls_func(L, "setAutoHideEnabled", _cocos2d_ui_ScrollViewBar_setAutoHideEnabled);
    oluacls_func(L, "setAutoHideTime", _cocos2d_ui_ScrollViewBar_setAutoHideTime);
    oluacls_func(L, "setPositionFromCorner", _cocos2d_ui_ScrollViewBar_setPositionFromCorner);
    oluacls_func(L, "setWidth", _cocos2d_ui_ScrollViewBar_setWidth);
    oluacls_prop(L, "autoHideEnabled", _cocos2d_ui_ScrollViewBar_isAutoHideEnabled, _cocos2d_ui_ScrollViewBar_setAutoHideEnabled);
    oluacls_prop(L, "autoHideTime", _cocos2d_ui_ScrollViewBar_getAutoHideTime, _cocos2d_ui_ScrollViewBar_setAutoHideTime);
    oluacls_prop(L, "positionFromCorner", _cocos2d_ui_ScrollViewBar_getPositionFromCorner, _cocos2d_ui_ScrollViewBar_setPositionFromCorner);
    oluacls_prop(L, "width", _cocos2d_ui_ScrollViewBar_getWidth, _cocos2d_ui_ScrollViewBar_setWidth);

    olua_registerluatype<cocos2d::ui::ScrollViewBar>(L, "ccui.ScrollViewBar");

    return 1;
}

static int luaopen_cocos2d_ui_Slider_EventType(lua_State *L)
{
    oluacls_class(L, "ccui.Slider.EventType", nullptr);
    oluacls_const_integer(L, "ON_PERCENTAGE_CHANGED", (lua_Integer)cocos2d::ui::Slider::EventType::ON_PERCENTAGE_CHANGED);
    oluacls_const_integer(L, "ON_SLIDEBALL_CANCEL", (lua_Integer)cocos2d::ui::Slider::EventType::ON_SLIDEBALL_CANCEL);
    oluacls_const_integer(L, "ON_SLIDEBALL_DOWN", (lua_Integer)cocos2d::ui::Slider::EventType::ON_SLIDEBALL_DOWN);
    oluacls_const_integer(L, "ON_SLIDEBALL_UP", (lua_Integer)cocos2d::ui::Slider::EventType::ON_SLIDEBALL_UP);

    olua_registerluatype<cocos2d::ui::Slider::EventType>(L, "ccui.Slider.EventType");

    return 1;
}

static int _cocos2d_ui_Slider___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::ui::Slider *)olua_toobj(L, 1, "ccui.Slider");
    olua_push_cppobj(L, self, "ccui.Slider");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_ui_Slider_addEventListener(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Slider *self = nullptr;
    std::function<void(cocos2d::Ref *, cocos2d::ui::Slider::EventType)> arg1;       /** callback */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Slider");

    if (olua_is_std_function(L, 2)) {
        void *callback_store_obj = (void *)self;
        std::string tag = "sliderCallback";
        std::string func = olua_setcallback(L, callback_store_obj, tag.c_str(), 2, OLUA_TAG_REPLACE);
        lua_State *MT = olua_mainthread();
        arg1 = [callback_store_obj, func, MT](cocos2d::Ref *arg1, cocos2d::ui::Slider::EventType arg2) {
            lua_State *L = olua_mainthread();

            if (MT == L) {
                int top = lua_gettop(L);
                olua_push_cppobj(L, arg1, "cc.Ref");
                olua_push_uint(L, (lua_Unsigned)arg2);

                olua_callback(L, callback_store_obj, func.c_str(), 2);

                lua_settop(L, top);
            }
        };
    } else {
        void *callback_store_obj = (void *)self;
        std::string tag = "sliderCallback";
        olua_removecallback(L, callback_store_obj, tag.c_str(), OLUA_TAG_SUBEQUAL);
        arg1 = nullptr;
    }

    // void addEventListener(@nullable const std::function<void(Ref*,EventType)>& callback)
    self->addEventListener(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Slider_create1(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::ui::Slider *create()
    cocos2d::ui::Slider *ret = (cocos2d::ui::Slider *)cocos2d::ui::Slider::create();
    int num_ret = olua_push_cppobj(L, ret, "ccui.Slider");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Slider_create2(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** barTextureName */
    std::string arg2;       /** normalBallTextureName */
    lua_Unsigned arg3 = 0;       /** resType */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);
    olua_check_uint(L, 3, &arg3);

    // static cocos2d::ui::Slider *create(const std::string &barTextureName, const std::string &normalBallTextureName, @optional cocos2d::ui::Widget::TextureResType resType)
    cocos2d::ui::Slider *ret = (cocos2d::ui::Slider *)cocos2d::ui::Slider::create(arg1, arg2, (cocos2d::ui::Widget::TextureResType)arg3);
    int num_ret = olua_push_cppobj(L, ret, "ccui.Slider");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Slider_create3(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** barTextureName */
    std::string arg2;       /** normalBallTextureName */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);

    // static cocos2d::ui::Slider *create(const std::string &barTextureName, const std::string &normalBallTextureName, @optional cocos2d::ui::Widget::TextureResType resType)
    cocos2d::ui::Slider *ret = (cocos2d::ui::Slider *)cocos2d::ui::Slider::create(arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "ccui.Slider");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Slider_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // static cocos2d::ui::Slider *create()
        return _cocos2d_ui_Slider_create1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 1)) && (olua_is_std_string(L, 2))) {
            // static cocos2d::ui::Slider *create(const std::string &barTextureName, const std::string &normalBallTextureName, @optional cocos2d::ui::Widget::TextureResType resType)
            return _cocos2d_ui_Slider_create3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_std_string(L, 1)) && (olua_is_std_string(L, 2)) && (olua_is_uint(L, 3))) {
            // static cocos2d::ui::Slider *create(const std::string &barTextureName, const std::string &normalBallTextureName, @optional cocos2d::ui::Widget::TextureResType resType)
            return _cocos2d_ui_Slider_create2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::Slider::create' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ui_Slider_createInstance(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::Ref *createInstance()
    cocos2d::Ref *ret = (cocos2d::Ref *)cocos2d::ui::Slider::createInstance();
    int num_ret = olua_push_cppobj(L, ret, "cc.Ref");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Slider_getBackFile(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Slider *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Slider");

    // cocos2d::ResourceData getBackFile()
    cocos2d::ResourceData ret = (cocos2d::ResourceData)self->getBackFile();
    int num_ret = auto_olua_push_cocos2d_ResourceData(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Slider_getBallDisabledFile(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Slider *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Slider");

    // cocos2d::ResourceData getBallDisabledFile()
    cocos2d::ResourceData ret = (cocos2d::ResourceData)self->getBallDisabledFile();
    int num_ret = auto_olua_push_cocos2d_ResourceData(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Slider_getBallNormalFile(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Slider *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Slider");

    // cocos2d::ResourceData getBallNormalFile()
    cocos2d::ResourceData ret = (cocos2d::ResourceData)self->getBallNormalFile();
    int num_ret = auto_olua_push_cocos2d_ResourceData(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Slider_getBallPressedFile(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Slider *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Slider");

    // cocos2d::ResourceData getBallPressedFile()
    cocos2d::ResourceData ret = (cocos2d::ResourceData)self->getBallPressedFile();
    int num_ret = auto_olua_push_cocos2d_ResourceData(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Slider_getCapInsetsBarRenderer(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Slider *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Slider");

    // const cocos2d::Rect &getCapInsetsBarRenderer()
    const cocos2d::Rect &ret = (const cocos2d::Rect &)self->getCapInsetsBarRenderer();
    int num_ret = manual_olua_push_cocos2d_Rect(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Slider_getCapInsetsProgressBarRenderer(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Slider *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Slider");

    // const cocos2d::Rect &getCapInsetsProgressBarRenderer()
    const cocos2d::Rect &ret = (const cocos2d::Rect &)self->getCapInsetsProgressBarRenderer();
    int num_ret = manual_olua_push_cocos2d_Rect(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Slider_getMaxPercent(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Slider *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Slider");

    // int getMaxPercent()
    int ret = (int)self->getMaxPercent();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Slider_getPercent(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Slider *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Slider");

    // int getPercent()
    int ret = (int)self->getPercent();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Slider_getProgressBarFile(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Slider *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Slider");

    // cocos2d::ResourceData getProgressBarFile()
    cocos2d::ResourceData ret = (cocos2d::ResourceData)self->getProgressBarFile();
    int num_ret = auto_olua_push_cocos2d_ResourceData(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Slider_getSlidBallDisabledRenderer(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Slider *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Slider");

    // @addref(protectedChildren |) cocos2d::Sprite *getSlidBallDisabledRenderer()
    cocos2d::Sprite *ret = (cocos2d::Sprite *)self->getSlidBallDisabledRenderer();
    int num_ret = olua_push_cppobj(L, ret, "cc.Sprite");

    // inject code after call
    olua_addref(L, 1, "protectedChildren", -1, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Slider_getSlidBallNormalRenderer(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Slider *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Slider");

    // @addref(protectedChildren |) cocos2d::Sprite *getSlidBallNormalRenderer()
    cocos2d::Sprite *ret = (cocos2d::Sprite *)self->getSlidBallNormalRenderer();
    int num_ret = olua_push_cppobj(L, ret, "cc.Sprite");

    // inject code after call
    olua_addref(L, 1, "protectedChildren", -1, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Slider_getSlidBallPressedRenderer(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Slider *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Slider");

    // @addref(protectedChildren |) cocos2d::Sprite *getSlidBallPressedRenderer()
    cocos2d::Sprite *ret = (cocos2d::Sprite *)self->getSlidBallPressedRenderer();
    int num_ret = olua_push_cppobj(L, ret, "cc.Sprite");

    // inject code after call
    olua_addref(L, 1, "protectedChildren", -1, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Slider_getSlidBallRenderer(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Slider *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Slider");

    // @addref(protectedChildren |) cocos2d::Node *getSlidBallRenderer()
    cocos2d::Node *ret = (cocos2d::Node *)self->getSlidBallRenderer();
    int num_ret = olua_push_cppobj(L, ret, "cc.Node");

    // inject code after call
    olua_addref(L, 1, "protectedChildren", -1, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Slider_getZoomScale(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Slider *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Slider");

    // float getZoomScale()
    float ret = (float)self->getZoomScale();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Slider_isScale9Enabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Slider *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Slider");

    // bool isScale9Enabled()
    bool ret = (bool)self->isScale9Enabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Slider_loadBarTexture1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Slider *self = nullptr;
    std::string arg1;       /** fileName */
    lua_Unsigned arg2 = 0;       /** resType */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Slider");
    olua_check_std_string(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // void loadBarTexture(const std::string &fileName, @optional cocos2d::ui::Widget::TextureResType resType)
    self->loadBarTexture(arg1, (cocos2d::ui::Widget::TextureResType)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Slider_loadBarTexture2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Slider *self = nullptr;
    std::string arg1;       /** fileName */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Slider");
    olua_check_std_string(L, 2, &arg1);

    // void loadBarTexture(const std::string &fileName, @optional cocos2d::ui::Widget::TextureResType resType)
    self->loadBarTexture(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Slider_loadBarTexture(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 2))) {
            // void loadBarTexture(const std::string &fileName, @optional cocos2d::ui::Widget::TextureResType resType)
            return _cocos2d_ui_Slider_loadBarTexture2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_uint(L, 3))) {
            // void loadBarTexture(const std::string &fileName, @optional cocos2d::ui::Widget::TextureResType resType)
            return _cocos2d_ui_Slider_loadBarTexture1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::Slider::loadBarTexture' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ui_Slider_loadProgressBarTexture1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Slider *self = nullptr;
    std::string arg1;       /** fileName */
    lua_Unsigned arg2 = 0;       /** resType */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Slider");
    olua_check_std_string(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // void loadProgressBarTexture(const std::string &fileName, @optional cocos2d::ui::Widget::TextureResType resType)
    self->loadProgressBarTexture(arg1, (cocos2d::ui::Widget::TextureResType)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Slider_loadProgressBarTexture2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Slider *self = nullptr;
    std::string arg1;       /** fileName */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Slider");
    olua_check_std_string(L, 2, &arg1);

    // void loadProgressBarTexture(const std::string &fileName, @optional cocos2d::ui::Widget::TextureResType resType)
    self->loadProgressBarTexture(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Slider_loadProgressBarTexture(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 2))) {
            // void loadProgressBarTexture(const std::string &fileName, @optional cocos2d::ui::Widget::TextureResType resType)
            return _cocos2d_ui_Slider_loadProgressBarTexture2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_uint(L, 3))) {
            // void loadProgressBarTexture(const std::string &fileName, @optional cocos2d::ui::Widget::TextureResType resType)
            return _cocos2d_ui_Slider_loadProgressBarTexture1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::Slider::loadProgressBarTexture' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ui_Slider_loadSlidBallTextureDisabled1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Slider *self = nullptr;
    std::string arg1;       /** disabled */
    lua_Unsigned arg2 = 0;       /** resType */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Slider");
    olua_check_std_string(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // void loadSlidBallTextureDisabled(const std::string &disabled, @optional cocos2d::ui::Widget::TextureResType resType)
    self->loadSlidBallTextureDisabled(arg1, (cocos2d::ui::Widget::TextureResType)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Slider_loadSlidBallTextureDisabled2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Slider *self = nullptr;
    std::string arg1;       /** disabled */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Slider");
    olua_check_std_string(L, 2, &arg1);

    // void loadSlidBallTextureDisabled(const std::string &disabled, @optional cocos2d::ui::Widget::TextureResType resType)
    self->loadSlidBallTextureDisabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Slider_loadSlidBallTextureDisabled(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 2))) {
            // void loadSlidBallTextureDisabled(const std::string &disabled, @optional cocos2d::ui::Widget::TextureResType resType)
            return _cocos2d_ui_Slider_loadSlidBallTextureDisabled2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_uint(L, 3))) {
            // void loadSlidBallTextureDisabled(const std::string &disabled, @optional cocos2d::ui::Widget::TextureResType resType)
            return _cocos2d_ui_Slider_loadSlidBallTextureDisabled1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::Slider::loadSlidBallTextureDisabled' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ui_Slider_loadSlidBallTextureNormal1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Slider *self = nullptr;
    std::string arg1;       /** normal */
    lua_Unsigned arg2 = 0;       /** resType */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Slider");
    olua_check_std_string(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // void loadSlidBallTextureNormal(const std::string &normal, @optional cocos2d::ui::Widget::TextureResType resType)
    self->loadSlidBallTextureNormal(arg1, (cocos2d::ui::Widget::TextureResType)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Slider_loadSlidBallTextureNormal2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Slider *self = nullptr;
    std::string arg1;       /** normal */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Slider");
    olua_check_std_string(L, 2, &arg1);

    // void loadSlidBallTextureNormal(const std::string &normal, @optional cocos2d::ui::Widget::TextureResType resType)
    self->loadSlidBallTextureNormal(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Slider_loadSlidBallTextureNormal(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 2))) {
            // void loadSlidBallTextureNormal(const std::string &normal, @optional cocos2d::ui::Widget::TextureResType resType)
            return _cocos2d_ui_Slider_loadSlidBallTextureNormal2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_uint(L, 3))) {
            // void loadSlidBallTextureNormal(const std::string &normal, @optional cocos2d::ui::Widget::TextureResType resType)
            return _cocos2d_ui_Slider_loadSlidBallTextureNormal1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::Slider::loadSlidBallTextureNormal' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ui_Slider_loadSlidBallTexturePressed1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Slider *self = nullptr;
    std::string arg1;       /** pressed */
    lua_Unsigned arg2 = 0;       /** resType */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Slider");
    olua_check_std_string(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // void loadSlidBallTexturePressed(const std::string &pressed, @optional cocos2d::ui::Widget::TextureResType resType)
    self->loadSlidBallTexturePressed(arg1, (cocos2d::ui::Widget::TextureResType)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Slider_loadSlidBallTexturePressed2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Slider *self = nullptr;
    std::string arg1;       /** pressed */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Slider");
    olua_check_std_string(L, 2, &arg1);

    // void loadSlidBallTexturePressed(const std::string &pressed, @optional cocos2d::ui::Widget::TextureResType resType)
    self->loadSlidBallTexturePressed(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Slider_loadSlidBallTexturePressed(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 2))) {
            // void loadSlidBallTexturePressed(const std::string &pressed, @optional cocos2d::ui::Widget::TextureResType resType)
            return _cocos2d_ui_Slider_loadSlidBallTexturePressed2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_uint(L, 3))) {
            // void loadSlidBallTexturePressed(const std::string &pressed, @optional cocos2d::ui::Widget::TextureResType resType)
            return _cocos2d_ui_Slider_loadSlidBallTexturePressed1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::Slider::loadSlidBallTexturePressed' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ui_Slider_loadSlidBallTextures1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Slider *self = nullptr;
    std::string arg1;       /** normal */
    std::string arg2;       /** pressed */
    std::string arg3;       /** disabled */
    lua_Unsigned arg4 = 0;       /** texType */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Slider");
    olua_check_std_string(L, 2, &arg1);
    olua_check_std_string(L, 3, &arg2);
    olua_check_std_string(L, 4, &arg3);
    olua_check_uint(L, 5, &arg4);

    // void loadSlidBallTextures(const std::string &normal, @optional const std::string &pressed, @optional const std::string &disabled, @optional cocos2d::ui::Widget::TextureResType texType)
    self->loadSlidBallTextures(arg1, arg2, arg3, (cocos2d::ui::Widget::TextureResType)arg4);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Slider_loadSlidBallTextures2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Slider *self = nullptr;
    std::string arg1;       /** normal */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Slider");
    olua_check_std_string(L, 2, &arg1);

    // void loadSlidBallTextures(const std::string &normal, @optional const std::string &pressed, @optional const std::string &disabled, @optional cocos2d::ui::Widget::TextureResType texType)
    self->loadSlidBallTextures(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Slider_loadSlidBallTextures3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Slider *self = nullptr;
    std::string arg1;       /** normal */
    std::string arg2;       /** pressed */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Slider");
    olua_check_std_string(L, 2, &arg1);
    olua_check_std_string(L, 3, &arg2);

    // void loadSlidBallTextures(const std::string &normal, @optional const std::string &pressed, @optional const std::string &disabled, @optional cocos2d::ui::Widget::TextureResType texType)
    self->loadSlidBallTextures(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Slider_loadSlidBallTextures4(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Slider *self = nullptr;
    std::string arg1;       /** normal */
    std::string arg2;       /** pressed */
    std::string arg3;       /** disabled */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Slider");
    olua_check_std_string(L, 2, &arg1);
    olua_check_std_string(L, 3, &arg2);
    olua_check_std_string(L, 4, &arg3);

    // void loadSlidBallTextures(const std::string &normal, @optional const std::string &pressed, @optional const std::string &disabled, @optional cocos2d::ui::Widget::TextureResType texType)
    self->loadSlidBallTextures(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Slider_loadSlidBallTextures(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 2))) {
            // void loadSlidBallTextures(const std::string &normal, @optional const std::string &pressed, @optional const std::string &disabled, @optional cocos2d::ui::Widget::TextureResType texType)
            return _cocos2d_ui_Slider_loadSlidBallTextures2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_std_string(L, 3))) {
            // void loadSlidBallTextures(const std::string &normal, @optional const std::string &pressed, @optional const std::string &disabled, @optional cocos2d::ui::Widget::TextureResType texType)
            return _cocos2d_ui_Slider_loadSlidBallTextures3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_std_string(L, 3)) && (olua_is_std_string(L, 4))) {
            // void loadSlidBallTextures(const std::string &normal, @optional const std::string &pressed, @optional const std::string &disabled, @optional cocos2d::ui::Widget::TextureResType texType)
            return _cocos2d_ui_Slider_loadSlidBallTextures4(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_std_string(L, 3)) && (olua_is_std_string(L, 4)) && (olua_is_uint(L, 5))) {
            // void loadSlidBallTextures(const std::string &normal, @optional const std::string &pressed, @optional const std::string &disabled, @optional cocos2d::ui::Widget::TextureResType texType)
            return _cocos2d_ui_Slider_loadSlidBallTextures1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::Slider::loadSlidBallTextures' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ui_Slider_new(lua_State *L)
{
    olua_startinvoke(L);

    // Slider()
    cocos2d::ui::Slider *ret = (cocos2d::ui::Slider *)new cocos2d::ui::Slider();
    int num_ret = olua_push_cppobj(L, ret, "ccui.Slider");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Slider_setCapInsetProgressBarRenderer(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Slider *self = nullptr;
    cocos2d::Rect arg1;       /** capInsets */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Slider");
    manual_olua_check_cocos2d_Rect(L, 2, &arg1);

    // void setCapInsetProgressBarRenderer(const cocos2d::Rect &capInsets)
    self->setCapInsetProgressBarRenderer(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Slider_setCapInsets(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Slider *self = nullptr;
    cocos2d::Rect arg1;       /** capInsets */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Slider");
    manual_olua_check_cocos2d_Rect(L, 2, &arg1);

    // void setCapInsets(const cocos2d::Rect &capInsets)
    self->setCapInsets(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Slider_setCapInsetsBarRenderer(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Slider *self = nullptr;
    cocos2d::Rect arg1;       /** capInsets */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Slider");
    manual_olua_check_cocos2d_Rect(L, 2, &arg1);

    // void setCapInsetsBarRenderer(const cocos2d::Rect &capInsets)
    self->setCapInsetsBarRenderer(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Slider_setMaxPercent(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Slider *self = nullptr;
    lua_Integer arg1 = 0;       /** percent */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Slider");
    olua_check_int(L, 2, &arg1);

    // void setMaxPercent(int percent)
    self->setMaxPercent((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Slider_setPercent(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Slider *self = nullptr;
    lua_Integer arg1 = 0;       /** percent */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Slider");
    olua_check_int(L, 2, &arg1);

    // void setPercent(int percent)
    self->setPercent((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Slider_setScale9Enabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Slider *self = nullptr;
    bool arg1 = false;       /** able */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Slider");
    olua_check_bool(L, 2, &arg1);

    // void setScale9Enabled(bool able)
    self->setScale9Enabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Slider_setZoomScale(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Slider *self = nullptr;
    lua_Number arg1 = 0;       /** scale */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Slider");
    olua_check_number(L, 2, &arg1);

    // void setZoomScale(float scale)
    self->setZoomScale((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Slider_updateVisualSlider(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Slider *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Slider");

    // void updateVisualSlider()
    self->updateVisualSlider();

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_ui_Slider(lua_State *L)
{
    oluacls_class(L, "ccui.Slider", "ccui.Widget");
    oluacls_func(L, "__move", _cocos2d_ui_Slider___move);
    oluacls_func(L, "addEventListener", _cocos2d_ui_Slider_addEventListener);
    oluacls_func(L, "create", _cocos2d_ui_Slider_create);
    oluacls_func(L, "createInstance", _cocos2d_ui_Slider_createInstance);
    oluacls_func(L, "getBackFile", _cocos2d_ui_Slider_getBackFile);
    oluacls_func(L, "getBallDisabledFile", _cocos2d_ui_Slider_getBallDisabledFile);
    oluacls_func(L, "getBallNormalFile", _cocos2d_ui_Slider_getBallNormalFile);
    oluacls_func(L, "getBallPressedFile", _cocos2d_ui_Slider_getBallPressedFile);
    oluacls_func(L, "getCapInsetsBarRenderer", _cocos2d_ui_Slider_getCapInsetsBarRenderer);
    oluacls_func(L, "getCapInsetsProgressBarRenderer", _cocos2d_ui_Slider_getCapInsetsProgressBarRenderer);
    oluacls_func(L, "getMaxPercent", _cocos2d_ui_Slider_getMaxPercent);
    oluacls_func(L, "getPercent", _cocos2d_ui_Slider_getPercent);
    oluacls_func(L, "getProgressBarFile", _cocos2d_ui_Slider_getProgressBarFile);
    oluacls_func(L, "getSlidBallDisabledRenderer", _cocos2d_ui_Slider_getSlidBallDisabledRenderer);
    oluacls_func(L, "getSlidBallNormalRenderer", _cocos2d_ui_Slider_getSlidBallNormalRenderer);
    oluacls_func(L, "getSlidBallPressedRenderer", _cocos2d_ui_Slider_getSlidBallPressedRenderer);
    oluacls_func(L, "getSlidBallRenderer", _cocos2d_ui_Slider_getSlidBallRenderer);
    oluacls_func(L, "getZoomScale", _cocos2d_ui_Slider_getZoomScale);
    oluacls_func(L, "isScale9Enabled", _cocos2d_ui_Slider_isScale9Enabled);
    oluacls_func(L, "loadBarTexture", _cocos2d_ui_Slider_loadBarTexture);
    oluacls_func(L, "loadProgressBarTexture", _cocos2d_ui_Slider_loadProgressBarTexture);
    oluacls_func(L, "loadSlidBallTextureDisabled", _cocos2d_ui_Slider_loadSlidBallTextureDisabled);
    oluacls_func(L, "loadSlidBallTextureNormal", _cocos2d_ui_Slider_loadSlidBallTextureNormal);
    oluacls_func(L, "loadSlidBallTexturePressed", _cocos2d_ui_Slider_loadSlidBallTexturePressed);
    oluacls_func(L, "loadSlidBallTextures", _cocos2d_ui_Slider_loadSlidBallTextures);
    oluacls_func(L, "new", _cocos2d_ui_Slider_new);
    oluacls_func(L, "setCapInsetProgressBarRenderer", _cocos2d_ui_Slider_setCapInsetProgressBarRenderer);
    oluacls_func(L, "setCapInsets", _cocos2d_ui_Slider_setCapInsets);
    oluacls_func(L, "setCapInsetsBarRenderer", _cocos2d_ui_Slider_setCapInsetsBarRenderer);
    oluacls_func(L, "setMaxPercent", _cocos2d_ui_Slider_setMaxPercent);
    oluacls_func(L, "setPercent", _cocos2d_ui_Slider_setPercent);
    oluacls_func(L, "setScale9Enabled", _cocos2d_ui_Slider_setScale9Enabled);
    oluacls_func(L, "setZoomScale", _cocos2d_ui_Slider_setZoomScale);
    oluacls_func(L, "updateVisualSlider", _cocos2d_ui_Slider_updateVisualSlider);
    oluacls_prop(L, "backFile", _cocos2d_ui_Slider_getBackFile, nullptr);
    oluacls_prop(L, "ballDisabledFile", _cocos2d_ui_Slider_getBallDisabledFile, nullptr);
    oluacls_prop(L, "ballNormalFile", _cocos2d_ui_Slider_getBallNormalFile, nullptr);
    oluacls_prop(L, "ballPressedFile", _cocos2d_ui_Slider_getBallPressedFile, nullptr);
    oluacls_prop(L, "capInsetsBarRenderer", _cocos2d_ui_Slider_getCapInsetsBarRenderer, _cocos2d_ui_Slider_setCapInsetsBarRenderer);
    oluacls_prop(L, "capInsetsProgressBarRenderer", _cocos2d_ui_Slider_getCapInsetsProgressBarRenderer, nullptr);
    oluacls_prop(L, "maxPercent", _cocos2d_ui_Slider_getMaxPercent, _cocos2d_ui_Slider_setMaxPercent);
    oluacls_prop(L, "percent", _cocos2d_ui_Slider_getPercent, _cocos2d_ui_Slider_setPercent);
    oluacls_prop(L, "progressBarFile", _cocos2d_ui_Slider_getProgressBarFile, nullptr);
    oluacls_prop(L, "scale9Enabled", _cocos2d_ui_Slider_isScale9Enabled, _cocos2d_ui_Slider_setScale9Enabled);
    oluacls_prop(L, "slidBallDisabledRenderer", _cocos2d_ui_Slider_getSlidBallDisabledRenderer, nullptr);
    oluacls_prop(L, "slidBallNormalRenderer", _cocos2d_ui_Slider_getSlidBallNormalRenderer, nullptr);
    oluacls_prop(L, "slidBallPressedRenderer", _cocos2d_ui_Slider_getSlidBallPressedRenderer, nullptr);
    oluacls_prop(L, "slidBallRenderer", _cocos2d_ui_Slider_getSlidBallRenderer, nullptr);
    oluacls_prop(L, "zoomScale", _cocos2d_ui_Slider_getZoomScale, _cocos2d_ui_Slider_setZoomScale);

    olua_registerluatype<cocos2d::ui::Slider>(L, "ccui.Slider");

    return 1;
}

static int luaopen_cocos2d_ui_Text_Type(lua_State *L)
{
    oluacls_class(L, "ccui.Text.Type", nullptr);
    oluacls_const_integer(L, "SYSTEM", (lua_Integer)cocos2d::ui::Text::Type::SYSTEM);
    oluacls_const_integer(L, "TTF", (lua_Integer)cocos2d::ui::Text::Type::TTF);

    olua_registerluatype<cocos2d::ui::Text::Type>(L, "ccui.Text.Type");

    return 1;
}

static int _cocos2d_ui_Text___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::ui::Text *)olua_toobj(L, 1, "ccui.Text");
    olua_push_cppobj(L, self, "ccui.Text");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_ui_Text_create1(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::ui::Text *create()
    cocos2d::ui::Text *ret = (cocos2d::ui::Text *)cocos2d::ui::Text::create();
    int num_ret = olua_push_cppobj(L, ret, "ccui.Text");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Text_create2(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** textContent */
    std::string arg2;       /** fontName */
    lua_Number arg3 = 0;       /** fontSize */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);

    // static cocos2d::ui::Text *create(const std::string &textContent, const std::string &fontName, float fontSize)
    cocos2d::ui::Text *ret = (cocos2d::ui::Text *)cocos2d::ui::Text::create(arg1, arg2, (float)arg3);
    int num_ret = olua_push_cppobj(L, ret, "ccui.Text");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Text_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // static cocos2d::ui::Text *create()
        return _cocos2d_ui_Text_create1(L);
    }

    if (num_args == 3) {
        // if ((olua_is_std_string(L, 1)) && (olua_is_std_string(L, 2)) && (olua_is_number(L, 3))) {
            // static cocos2d::ui::Text *create(const std::string &textContent, const std::string &fontName, float fontSize)
            return _cocos2d_ui_Text_create2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::Text::create' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ui_Text_createInstance(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::Ref *createInstance()
    cocos2d::Ref *ret = (cocos2d::Ref *)cocos2d::ui::Text::createInstance();
    int num_ret = olua_push_cppobj(L, ret, "cc.Ref");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Text_disableEffect1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Text");

    // void disableEffect()
    self->disableEffect();

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Text_disableEffect2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;
    lua_Unsigned arg1 = 0;       /** effect */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Text");
    olua_check_uint(L, 2, &arg1);

    // void disableEffect(cocos2d::LabelEffect effect)
    self->disableEffect((cocos2d::LabelEffect)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Text_disableEffect(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // void disableEffect()
        return _cocos2d_ui_Text_disableEffect1(L);
    }

    if (num_args == 1) {
        // if ((olua_is_uint(L, 2))) {
            // void disableEffect(cocos2d::LabelEffect effect)
            return _cocos2d_ui_Text_disableEffect2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::Text::disableEffect' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ui_Text_enableGlow(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;
    cocos2d::Color4B arg1;       /** glowColor */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Text");
    manual_olua_check_cocos2d_Color4B(L, 2, &arg1);

    // void enableGlow(const cocos2d::Color4B &glowColor)
    self->enableGlow(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Text_enableOutline1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;
    cocos2d::Color4B arg1;       /** outlineColor */
    lua_Integer arg2 = 0;       /** outlineSize */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Text");
    manual_olua_check_cocos2d_Color4B(L, 2, &arg1);
    olua_check_int(L, 3, &arg2);

    // void enableOutline(const cocos2d::Color4B &outlineColor, @optional int outlineSize)
    self->enableOutline(arg1, (int)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Text_enableOutline2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;
    cocos2d::Color4B arg1;       /** outlineColor */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Text");
    manual_olua_check_cocos2d_Color4B(L, 2, &arg1);

    // void enableOutline(const cocos2d::Color4B &outlineColor, @optional int outlineSize)
    self->enableOutline(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Text_enableOutline(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((manual_olua_is_cocos2d_Color4B(L, 2))) {
            // void enableOutline(const cocos2d::Color4B &outlineColor, @optional int outlineSize)
            return _cocos2d_ui_Text_enableOutline2(L);
        // }
    }

    if (num_args == 2) {
        // if ((manual_olua_is_cocos2d_Color4B(L, 2)) && (olua_is_int(L, 3))) {
            // void enableOutline(const cocos2d::Color4B &outlineColor, @optional int outlineSize)
            return _cocos2d_ui_Text_enableOutline1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::Text::enableOutline' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ui_Text_enableShadow1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;
    cocos2d::Color4B arg1;       /** shadowColor */
    cocos2d::Size arg2;       /** offset */
    lua_Integer arg3 = 0;       /** blurRadius */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Text");
    manual_olua_check_cocos2d_Color4B(L, 2, &arg1);
    auto_olua_check_cocos2d_Size(L, 3, &arg2);
    olua_check_int(L, 4, &arg3);

    // void enableShadow(@optional const cocos2d::Color4B &shadowColor, @optional const cocos2d::Size &offset, @optional int blurRadius)
    self->enableShadow(arg1, arg2, (int)arg3);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Text_enableShadow2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Text");

    // void enableShadow(@optional const cocos2d::Color4B &shadowColor, @optional const cocos2d::Size &offset, @optional int blurRadius)
    self->enableShadow();

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Text_enableShadow3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;
    cocos2d::Color4B arg1;       /** shadowColor */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Text");
    manual_olua_check_cocos2d_Color4B(L, 2, &arg1);

    // void enableShadow(@optional const cocos2d::Color4B &shadowColor, @optional const cocos2d::Size &offset, @optional int blurRadius)
    self->enableShadow(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Text_enableShadow4(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;
    cocos2d::Color4B arg1;       /** shadowColor */
    cocos2d::Size arg2;       /** offset */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Text");
    manual_olua_check_cocos2d_Color4B(L, 2, &arg1);
    auto_olua_check_cocos2d_Size(L, 3, &arg2);

    // void enableShadow(@optional const cocos2d::Color4B &shadowColor, @optional const cocos2d::Size &offset, @optional int blurRadius)
    self->enableShadow(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Text_enableShadow(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // void enableShadow(@optional const cocos2d::Color4B &shadowColor, @optional const cocos2d::Size &offset, @optional int blurRadius)
        return _cocos2d_ui_Text_enableShadow2(L);
    }

    if (num_args == 1) {
        // if ((manual_olua_is_cocos2d_Color4B(L, 2))) {
            // void enableShadow(@optional const cocos2d::Color4B &shadowColor, @optional const cocos2d::Size &offset, @optional int blurRadius)
            return _cocos2d_ui_Text_enableShadow3(L);
        // }
    }

    if (num_args == 2) {
        // if ((manual_olua_is_cocos2d_Color4B(L, 2)) && (auto_olua_is_cocos2d_Size(L, 3))) {
            // void enableShadow(@optional const cocos2d::Color4B &shadowColor, @optional const cocos2d::Size &offset, @optional int blurRadius)
            return _cocos2d_ui_Text_enableShadow4(L);
        // }
    }

    if (num_args == 3) {
        // if ((manual_olua_is_cocos2d_Color4B(L, 2)) && (auto_olua_is_cocos2d_Size(L, 3)) && (olua_is_int(L, 4))) {
            // void enableShadow(@optional const cocos2d::Color4B &shadowColor, @optional const cocos2d::Size &offset, @optional int blurRadius)
            return _cocos2d_ui_Text_enableShadow1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::Text::enableShadow' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ui_Text_getAutoRenderSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Text");

    // cocos2d::Size getAutoRenderSize()
    cocos2d::Size ret = (cocos2d::Size)self->getAutoRenderSize();
    int num_ret = auto_olua_push_cocos2d_Size(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Text_getBlendFunc(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Text");

    // const cocos2d::BlendFunc &getBlendFunc()
    const cocos2d::BlendFunc &ret = (const cocos2d::BlendFunc &)self->getBlendFunc();
    int num_ret = auto_olua_push_cocos2d_BlendFunc(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Text_getEffectColor(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Text");

    // cocos2d::Color4B getEffectColor()
    cocos2d::Color4B ret = (cocos2d::Color4B)self->getEffectColor();
    int num_ret = manual_olua_push_cocos2d_Color4B(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Text_getFontName(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Text");

    // const std::string &getFontName()
    const std::string &ret = (const std::string &)self->getFontName();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Text_getFontSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Text");

    // float getFontSize()
    float ret = (float)self->getFontSize();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Text_getLabelEffectType(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Text");

    // cocos2d::LabelEffect getLabelEffectType()
    cocos2d::LabelEffect ret = (cocos2d::LabelEffect)self->getLabelEffectType();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Text_getLetter(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;
    lua_Integer arg1 = 0;       /** lettetIndex */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Text");
    olua_check_int(L, 2, &arg1);

    // cocos2d::Sprite *getLetter(int lettetIndex)
    cocos2d::Sprite *ret = (cocos2d::Sprite *)self->getLetter((int)arg1);
    int num_ret = olua_push_cppobj(L, ret, "cc.Sprite");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Text_getOutlineSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Text");

    // int getOutlineSize()
    int ret = (int)self->getOutlineSize();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Text_getShadowBlurRadius(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Text");

    // float getShadowBlurRadius()
    float ret = (float)self->getShadowBlurRadius();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Text_getShadowColor(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Text");

    // cocos2d::Color4B getShadowColor()
    cocos2d::Color4B ret = (cocos2d::Color4B)self->getShadowColor();
    int num_ret = manual_olua_push_cocos2d_Color4B(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Text_getShadowOffset(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Text");

    // cocos2d::Size getShadowOffset()
    cocos2d::Size ret = (cocos2d::Size)self->getShadowOffset();
    int num_ret = auto_olua_push_cocos2d_Size(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Text_getString(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Text");

    // const std::string &getString()
    const std::string &ret = (const std::string &)self->getString();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Text_getStringLength(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Text");

    // ssize_t getStringLength()
    ssize_t ret = (ssize_t)self->getStringLength();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Text_getTextAreaSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Text");

    // const cocos2d::Size &getTextAreaSize()
    const cocos2d::Size &ret = (const cocos2d::Size &)self->getTextAreaSize();
    int num_ret = auto_olua_push_cocos2d_Size(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Text_getTextColor(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Text");

    // const cocos2d::Color4B &getTextColor()
    const cocos2d::Color4B &ret = (const cocos2d::Color4B &)self->getTextColor();
    int num_ret = manual_olua_push_cocos2d_Color4B(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Text_getTextHorizontalAlignment(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Text");

    // cocos2d::TextHAlignment getTextHorizontalAlignment()
    cocos2d::TextHAlignment ret = (cocos2d::TextHAlignment)self->getTextHorizontalAlignment();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Text_getTextVerticalAlignment(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Text");

    // cocos2d::TextVAlignment getTextVerticalAlignment()
    cocos2d::TextVAlignment ret = (cocos2d::TextVAlignment)self->getTextVerticalAlignment();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Text_getType(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Text");

    // cocos2d::ui::Text::Type getType()
    cocos2d::ui::Text::Type ret = (cocos2d::ui::Text::Type)self->getType();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Text_init(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;
    std::string arg1;       /** textContent */
    std::string arg2;       /** fontName */
    lua_Number arg3 = 0;       /** fontSize */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Text");
    olua_check_std_string(L, 2, &arg1);
    olua_check_std_string(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);

    // bool init(const std::string &textContent, const std::string &fontName, float fontSize)
    bool ret = (bool)self->init(arg1, arg2, (float)arg3);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Text_isShadowEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Text");

    // bool isShadowEnabled()
    bool ret = (bool)self->isShadowEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Text_isTouchScaleChangeEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Text");

    // bool isTouchScaleChangeEnabled()
    bool ret = (bool)self->isTouchScaleChangeEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Text_new(lua_State *L)
{
    olua_startinvoke(L);

    // Text()
    cocos2d::ui::Text *ret = (cocos2d::ui::Text *)new cocos2d::ui::Text();
    int num_ret = olua_push_cppobj(L, ret, "ccui.Text");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Text_setBlendFunc(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;
    cocos2d::BlendFunc arg1;       /** blendFunc */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Text");
    auto_olua_check_cocos2d_BlendFunc(L, 2, &arg1);

    // void setBlendFunc(const cocos2d::BlendFunc &blendFunc)
    self->setBlendFunc(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Text_setFontName(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;
    std::string arg1;       /** name */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Text");
    olua_check_std_string(L, 2, &arg1);

    // void setFontName(const std::string &name)
    self->setFontName(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Text_setFontSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;
    lua_Number arg1 = 0;       /** size */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Text");
    olua_check_number(L, 2, &arg1);

    // void setFontSize(float size)
    self->setFontSize((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Text_setString(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;
    std::string arg1;       /** text */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Text");
    olua_check_std_string(L, 2, &arg1);

    // void setString(const std::string &text)
    self->setString(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Text_setTextAreaSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;
    cocos2d::Size arg1;       /** size */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Text");
    auto_olua_check_cocos2d_Size(L, 2, &arg1);

    // void setTextAreaSize(const cocos2d::Size &size)
    self->setTextAreaSize(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Text_setTextColor(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;
    cocos2d::Color4B arg1;       /** color */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Text");
    manual_olua_check_cocos2d_Color4B(L, 2, &arg1);

    // void setTextColor(const cocos2d::Color4B color)
    self->setTextColor(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Text_setTextHorizontalAlignment(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;
    lua_Unsigned arg1 = 0;       /** alignment */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Text");
    olua_check_uint(L, 2, &arg1);

    // void setTextHorizontalAlignment(cocos2d::TextHAlignment alignment)
    self->setTextHorizontalAlignment((cocos2d::TextHAlignment)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Text_setTextVerticalAlignment(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;
    lua_Unsigned arg1 = 0;       /** alignment */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Text");
    olua_check_uint(L, 2, &arg1);

    // void setTextVerticalAlignment(cocos2d::TextVAlignment alignment)
    self->setTextVerticalAlignment((cocos2d::TextVAlignment)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Text_setTouchScaleChangeEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Text *self = nullptr;
    bool arg1 = false;       /** enabled */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Text");
    olua_check_bool(L, 2, &arg1);

    // void setTouchScaleChangeEnabled(bool enabled)
    self->setTouchScaleChangeEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_ui_Text(lua_State *L)
{
    oluacls_class(L, "ccui.Text", "ccui.Widget");
    oluacls_func(L, "__move", _cocos2d_ui_Text___move);
    oluacls_func(L, "create", _cocos2d_ui_Text_create);
    oluacls_func(L, "createInstance", _cocos2d_ui_Text_createInstance);
    oluacls_func(L, "disableEffect", _cocos2d_ui_Text_disableEffect);
    oluacls_func(L, "enableGlow", _cocos2d_ui_Text_enableGlow);
    oluacls_func(L, "enableOutline", _cocos2d_ui_Text_enableOutline);
    oluacls_func(L, "enableShadow", _cocos2d_ui_Text_enableShadow);
    oluacls_func(L, "getAutoRenderSize", _cocos2d_ui_Text_getAutoRenderSize);
    oluacls_func(L, "getBlendFunc", _cocos2d_ui_Text_getBlendFunc);
    oluacls_func(L, "getEffectColor", _cocos2d_ui_Text_getEffectColor);
    oluacls_func(L, "getFontName", _cocos2d_ui_Text_getFontName);
    oluacls_func(L, "getFontSize", _cocos2d_ui_Text_getFontSize);
    oluacls_func(L, "getLabelEffectType", _cocos2d_ui_Text_getLabelEffectType);
    oluacls_func(L, "getLetter", _cocos2d_ui_Text_getLetter);
    oluacls_func(L, "getOutlineSize", _cocos2d_ui_Text_getOutlineSize);
    oluacls_func(L, "getShadowBlurRadius", _cocos2d_ui_Text_getShadowBlurRadius);
    oluacls_func(L, "getShadowColor", _cocos2d_ui_Text_getShadowColor);
    oluacls_func(L, "getShadowOffset", _cocos2d_ui_Text_getShadowOffset);
    oluacls_func(L, "getString", _cocos2d_ui_Text_getString);
    oluacls_func(L, "getStringLength", _cocos2d_ui_Text_getStringLength);
    oluacls_func(L, "getTextAreaSize", _cocos2d_ui_Text_getTextAreaSize);
    oluacls_func(L, "getTextColor", _cocos2d_ui_Text_getTextColor);
    oluacls_func(L, "getTextHorizontalAlignment", _cocos2d_ui_Text_getTextHorizontalAlignment);
    oluacls_func(L, "getTextVerticalAlignment", _cocos2d_ui_Text_getTextVerticalAlignment);
    oluacls_func(L, "getType", _cocos2d_ui_Text_getType);
    oluacls_func(L, "init", _cocos2d_ui_Text_init);
    oluacls_func(L, "isShadowEnabled", _cocos2d_ui_Text_isShadowEnabled);
    oluacls_func(L, "isTouchScaleChangeEnabled", _cocos2d_ui_Text_isTouchScaleChangeEnabled);
    oluacls_func(L, "new", _cocos2d_ui_Text_new);
    oluacls_func(L, "setBlendFunc", _cocos2d_ui_Text_setBlendFunc);
    oluacls_func(L, "setFontName", _cocos2d_ui_Text_setFontName);
    oluacls_func(L, "setFontSize", _cocos2d_ui_Text_setFontSize);
    oluacls_func(L, "setString", _cocos2d_ui_Text_setString);
    oluacls_func(L, "setTextAreaSize", _cocos2d_ui_Text_setTextAreaSize);
    oluacls_func(L, "setTextColor", _cocos2d_ui_Text_setTextColor);
    oluacls_func(L, "setTextHorizontalAlignment", _cocos2d_ui_Text_setTextHorizontalAlignment);
    oluacls_func(L, "setTextVerticalAlignment", _cocos2d_ui_Text_setTextVerticalAlignment);
    oluacls_func(L, "setTouchScaleChangeEnabled", _cocos2d_ui_Text_setTouchScaleChangeEnabled);
    oluacls_prop(L, "autoRenderSize", _cocos2d_ui_Text_getAutoRenderSize, nullptr);
    oluacls_prop(L, "blendFunc", _cocos2d_ui_Text_getBlendFunc, _cocos2d_ui_Text_setBlendFunc);
    oluacls_prop(L, "effectColor", _cocos2d_ui_Text_getEffectColor, nullptr);
    oluacls_prop(L, "fontName", _cocos2d_ui_Text_getFontName, _cocos2d_ui_Text_setFontName);
    oluacls_prop(L, "fontSize", _cocos2d_ui_Text_getFontSize, _cocos2d_ui_Text_setFontSize);
    oluacls_prop(L, "labelEffectType", _cocos2d_ui_Text_getLabelEffectType, nullptr);
    oluacls_prop(L, "outlineSize", _cocos2d_ui_Text_getOutlineSize, nullptr);
    oluacls_prop(L, "shadowBlurRadius", _cocos2d_ui_Text_getShadowBlurRadius, nullptr);
    oluacls_prop(L, "shadowColor", _cocos2d_ui_Text_getShadowColor, nullptr);
    oluacls_prop(L, "shadowEnabled", _cocos2d_ui_Text_isShadowEnabled, nullptr);
    oluacls_prop(L, "shadowOffset", _cocos2d_ui_Text_getShadowOffset, nullptr);
    oluacls_prop(L, "string", _cocos2d_ui_Text_getString, _cocos2d_ui_Text_setString);
    oluacls_prop(L, "stringLength", _cocos2d_ui_Text_getStringLength, nullptr);
    oluacls_prop(L, "textAreaSize", _cocos2d_ui_Text_getTextAreaSize, _cocos2d_ui_Text_setTextAreaSize);
    oluacls_prop(L, "textColor", _cocos2d_ui_Text_getTextColor, _cocos2d_ui_Text_setTextColor);
    oluacls_prop(L, "textHorizontalAlignment", _cocos2d_ui_Text_getTextHorizontalAlignment, _cocos2d_ui_Text_setTextHorizontalAlignment);
    oluacls_prop(L, "textVerticalAlignment", _cocos2d_ui_Text_getTextVerticalAlignment, _cocos2d_ui_Text_setTextVerticalAlignment);
    oluacls_prop(L, "touchScaleChangeEnabled", _cocos2d_ui_Text_isTouchScaleChangeEnabled, _cocos2d_ui_Text_setTouchScaleChangeEnabled);
    oluacls_prop(L, "type", _cocos2d_ui_Text_getType, nullptr);

    olua_registerluatype<cocos2d::ui::Text>(L, "ccui.Text");

    return 1;
}

static int _cocos2d_ui_TextAtlas___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::ui::TextAtlas *)olua_toobj(L, 1, "ccui.TextAtlas");
    olua_push_cppobj(L, self, "ccui.TextAtlas");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_ui_TextAtlas_adaptRenderers(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextAtlas *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TextAtlas");

    // void adaptRenderers()
    self->adaptRenderers();

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_TextAtlas_create1(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::ui::TextAtlas *create()
    cocos2d::ui::TextAtlas *ret = (cocos2d::ui::TextAtlas *)cocos2d::ui::TextAtlas::create();
    int num_ret = olua_push_cppobj(L, ret, "ccui.TextAtlas");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_TextAtlas_create2(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** stringValue */
    std::string arg2;       /** charMapFile */
    lua_Integer arg3 = 0;       /** itemWidth */
    lua_Integer arg4 = 0;       /** itemHeight */
    std::string arg5;       /** startCharMap */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);
    olua_check_int(L, 3, &arg3);
    olua_check_int(L, 4, &arg4);
    olua_check_std_string(L, 5, &arg5);

    // static cocos2d::ui::TextAtlas *create(const std::string &stringValue, const std::string &charMapFile, int itemWidth, int itemHeight, const std::string &startCharMap)
    cocos2d::ui::TextAtlas *ret = (cocos2d::ui::TextAtlas *)cocos2d::ui::TextAtlas::create(arg1, arg2, (int)arg3, (int)arg4, arg5);
    int num_ret = olua_push_cppobj(L, ret, "ccui.TextAtlas");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_TextAtlas_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // static cocos2d::ui::TextAtlas *create()
        return _cocos2d_ui_TextAtlas_create1(L);
    }

    if (num_args == 5) {
        // if ((olua_is_std_string(L, 1)) && (olua_is_std_string(L, 2)) && (olua_is_int(L, 3)) && (olua_is_int(L, 4)) && (olua_is_std_string(L, 5))) {
            // static cocos2d::ui::TextAtlas *create(const std::string &stringValue, const std::string &charMapFile, int itemWidth, int itemHeight, const std::string &startCharMap)
            return _cocos2d_ui_TextAtlas_create2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::TextAtlas::create' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ui_TextAtlas_createInstance(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::Ref *createInstance()
    cocos2d::Ref *ret = (cocos2d::Ref *)cocos2d::ui::TextAtlas::createInstance();
    int num_ret = olua_push_cppobj(L, ret, "cc.Ref");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_TextAtlas_getRenderFile(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextAtlas *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TextAtlas");

    // cocos2d::ResourceData getRenderFile()
    cocos2d::ResourceData ret = (cocos2d::ResourceData)self->getRenderFile();
    int num_ret = auto_olua_push_cocos2d_ResourceData(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_TextAtlas_getString(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextAtlas *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TextAtlas");

    // const std::string &getString()
    const std::string &ret = (const std::string &)self->getString();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_TextAtlas_getStringLength(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextAtlas *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TextAtlas");

    // ssize_t getStringLength()
    ssize_t ret = (ssize_t)self->getStringLength();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_TextAtlas_new(lua_State *L)
{
    olua_startinvoke(L);

    // TextAtlas()
    cocos2d::ui::TextAtlas *ret = (cocos2d::ui::TextAtlas *)new cocos2d::ui::TextAtlas();
    int num_ret = olua_push_cppobj(L, ret, "ccui.TextAtlas");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_TextAtlas_setProperty(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextAtlas *self = nullptr;
    std::string arg1;       /** stringValue */
    std::string arg2;       /** charMapFile */
    lua_Integer arg3 = 0;       /** itemWidth */
    lua_Integer arg4 = 0;       /** itemHeight */
    std::string arg5;       /** startCharMap */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TextAtlas");
    olua_check_std_string(L, 2, &arg1);
    olua_check_std_string(L, 3, &arg2);
    olua_check_int(L, 4, &arg3);
    olua_check_int(L, 5, &arg4);
    olua_check_std_string(L, 6, &arg5);

    // void setProperty(const std::string &stringValue, const std::string &charMapFile, int itemWidth, int itemHeight, const std::string &startCharMap)
    self->setProperty(arg1, arg2, (int)arg3, (int)arg4, arg5);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_TextAtlas_setString(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextAtlas *self = nullptr;
    std::string arg1;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TextAtlas");
    olua_check_std_string(L, 2, &arg1);

    // void setString(const std::string &value)
    self->setString(arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_ui_TextAtlas(lua_State *L)
{
    oluacls_class(L, "ccui.TextAtlas", "ccui.Widget");
    oluacls_func(L, "__move", _cocos2d_ui_TextAtlas___move);
    oluacls_func(L, "adaptRenderers", _cocos2d_ui_TextAtlas_adaptRenderers);
    oluacls_func(L, "create", _cocos2d_ui_TextAtlas_create);
    oluacls_func(L, "createInstance", _cocos2d_ui_TextAtlas_createInstance);
    oluacls_func(L, "getRenderFile", _cocos2d_ui_TextAtlas_getRenderFile);
    oluacls_func(L, "getString", _cocos2d_ui_TextAtlas_getString);
    oluacls_func(L, "getStringLength", _cocos2d_ui_TextAtlas_getStringLength);
    oluacls_func(L, "new", _cocos2d_ui_TextAtlas_new);
    oluacls_func(L, "setProperty", _cocos2d_ui_TextAtlas_setProperty);
    oluacls_func(L, "setString", _cocos2d_ui_TextAtlas_setString);
    oluacls_prop(L, "renderFile", _cocos2d_ui_TextAtlas_getRenderFile, nullptr);
    oluacls_prop(L, "string", _cocos2d_ui_TextAtlas_getString, _cocos2d_ui_TextAtlas_setString);
    oluacls_prop(L, "stringLength", _cocos2d_ui_TextAtlas_getStringLength, nullptr);

    olua_registerluatype<cocos2d::ui::TextAtlas>(L, "ccui.TextAtlas");

    return 1;
}

static int _cocos2d_ui_TextBMFont___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::ui::TextBMFont *)olua_toobj(L, 1, "ccui.TextBMFont");
    olua_push_cppobj(L, self, "ccui.TextBMFont");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_ui_TextBMFont_create1(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::ui::TextBMFont *create()
    cocos2d::ui::TextBMFont *ret = (cocos2d::ui::TextBMFont *)cocos2d::ui::TextBMFont::create();
    int num_ret = olua_push_cppobj(L, ret, "ccui.TextBMFont");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_TextBMFont_create2(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** text */
    std::string arg2;       /** filename */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);

    // static cocos2d::ui::TextBMFont *create(const std::string &text, const std::string &filename)
    cocos2d::ui::TextBMFont *ret = (cocos2d::ui::TextBMFont *)cocos2d::ui::TextBMFont::create(arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "ccui.TextBMFont");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_TextBMFont_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // static cocos2d::ui::TextBMFont *create()
        return _cocos2d_ui_TextBMFont_create1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 1)) && (olua_is_std_string(L, 2))) {
            // static cocos2d::ui::TextBMFont *create(const std::string &text, const std::string &filename)
            return _cocos2d_ui_TextBMFont_create2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::TextBMFont::create' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ui_TextBMFont_createInstance(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::Ref *createInstance()
    cocos2d::Ref *ret = (cocos2d::Ref *)cocos2d::ui::TextBMFont::createInstance();
    int num_ret = olua_push_cppobj(L, ret, "cc.Ref");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_TextBMFont_getRenderFile(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextBMFont *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TextBMFont");

    // cocos2d::ResourceData getRenderFile()
    cocos2d::ResourceData ret = (cocos2d::ResourceData)self->getRenderFile();
    int num_ret = auto_olua_push_cocos2d_ResourceData(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_TextBMFont_getString(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextBMFont *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TextBMFont");

    // const std::string &getString()
    const std::string &ret = (const std::string &)self->getString();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_TextBMFont_getStringLength(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextBMFont *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TextBMFont");

    // ssize_t getStringLength()
    ssize_t ret = (ssize_t)self->getStringLength();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_TextBMFont_new(lua_State *L)
{
    olua_startinvoke(L);

    // TextBMFont()
    cocos2d::ui::TextBMFont *ret = (cocos2d::ui::TextBMFont *)new cocos2d::ui::TextBMFont();
    int num_ret = olua_push_cppobj(L, ret, "ccui.TextBMFont");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_TextBMFont_resetRender(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextBMFont *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TextBMFont");

    // void resetRender()
    self->resetRender();

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_TextBMFont_setFntFile(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextBMFont *self = nullptr;
    std::string arg1;       /** fileName */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TextBMFont");
    olua_check_std_string(L, 2, &arg1);

    // void setFntFile(const std::string &fileName)
    self->setFntFile(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_TextBMFont_setString(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextBMFont *self = nullptr;
    std::string arg1;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TextBMFont");
    olua_check_std_string(L, 2, &arg1);

    // void setString(const std::string &value)
    self->setString(arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_ui_TextBMFont(lua_State *L)
{
    oluacls_class(L, "ccui.TextBMFont", "ccui.Widget");
    oluacls_func(L, "__move", _cocos2d_ui_TextBMFont___move);
    oluacls_func(L, "create", _cocos2d_ui_TextBMFont_create);
    oluacls_func(L, "createInstance", _cocos2d_ui_TextBMFont_createInstance);
    oluacls_func(L, "getRenderFile", _cocos2d_ui_TextBMFont_getRenderFile);
    oluacls_func(L, "getString", _cocos2d_ui_TextBMFont_getString);
    oluacls_func(L, "getStringLength", _cocos2d_ui_TextBMFont_getStringLength);
    oluacls_func(L, "new", _cocos2d_ui_TextBMFont_new);
    oluacls_func(L, "resetRender", _cocos2d_ui_TextBMFont_resetRender);
    oluacls_func(L, "setFntFile", _cocos2d_ui_TextBMFont_setFntFile);
    oluacls_func(L, "setString", _cocos2d_ui_TextBMFont_setString);
    oluacls_prop(L, "renderFile", _cocos2d_ui_TextBMFont_getRenderFile, nullptr);
    oluacls_prop(L, "string", _cocos2d_ui_TextBMFont_getString, _cocos2d_ui_TextBMFont_setString);
    oluacls_prop(L, "stringLength", _cocos2d_ui_TextBMFont_getStringLength, nullptr);

    olua_registerluatype<cocos2d::ui::TextBMFont>(L, "ccui.TextBMFont");

    return 1;
}

static int _cocos2d_ui_UICCTextField___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::ui::UICCTextField *)olua_toobj(L, 1, "ccui.UICCTextField");
    olua_push_cppobj(L, self, "ccui.UICCTextField");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_ui_UICCTextField_closeIME(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::UICCTextField *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.UICCTextField");

    // void closeIME()
    self->closeIME();

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_UICCTextField_create1(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::ui::UICCTextField *create()
    cocos2d::ui::UICCTextField *ret = (cocos2d::ui::UICCTextField *)cocos2d::ui::UICCTextField::create();
    int num_ret = olua_push_cppobj(L, ret, "ccui.UICCTextField");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_UICCTextField_create2(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** placeholder */
    std::string arg2;       /** fontName */
    lua_Number arg3 = 0;       /** fontSize */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);

    // static cocos2d::ui::UICCTextField *create(const std::string &placeholder, const std::string &fontName, float fontSize)
    cocos2d::ui::UICCTextField *ret = (cocos2d::ui::UICCTextField *)cocos2d::ui::UICCTextField::create(arg1, arg2, (float)arg3);
    int num_ret = olua_push_cppobj(L, ret, "ccui.UICCTextField");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_UICCTextField_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // static cocos2d::ui::UICCTextField *create()
        return _cocos2d_ui_UICCTextField_create1(L);
    }

    if (num_args == 3) {
        // if ((olua_is_std_string(L, 1)) && (olua_is_std_string(L, 2)) && (olua_is_number(L, 3))) {
            // static cocos2d::ui::UICCTextField *create(const std::string &placeholder, const std::string &fontName, float fontSize)
            return _cocos2d_ui_UICCTextField_create2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::UICCTextField::create' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ui_UICCTextField_getAttachWithIME(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::UICCTextField *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.UICCTextField");

    // bool getAttachWithIME()
    bool ret = (bool)self->getAttachWithIME();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_UICCTextField_getDeleteBackward(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::UICCTextField *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.UICCTextField");

    // bool getDeleteBackward()
    bool ret = (bool)self->getDeleteBackward();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_UICCTextField_getDetachWithIME(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::UICCTextField *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.UICCTextField");

    // bool getDetachWithIME()
    bool ret = (bool)self->getDetachWithIME();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_UICCTextField_getInsertText(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::UICCTextField *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.UICCTextField");

    // bool getInsertText()
    bool ret = (bool)self->getInsertText();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_UICCTextField_getMaxLength(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::UICCTextField *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.UICCTextField");

    // int getMaxLength()
    int ret = (int)self->getMaxLength();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_UICCTextField_insertText(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::UICCTextField *self = nullptr;
    const char *arg1 = nullptr;       /** text */
    lua_Unsigned arg2 = 0;       /** len */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.UICCTextField");
    olua_check_string(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // void insertText(const char *text, size_t len)
    self->insertText(arg1, (size_t)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_UICCTextField_isMaxLengthEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::UICCTextField *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.UICCTextField");

    // bool isMaxLengthEnabled()
    bool ret = (bool)self->isMaxLengthEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_UICCTextField_isPasswordEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::UICCTextField *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.UICCTextField");

    // bool isPasswordEnabled()
    bool ret = (bool)self->isPasswordEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_UICCTextField_new(lua_State *L)
{
    olua_startinvoke(L);

    // UICCTextField()
    cocos2d::ui::UICCTextField *ret = (cocos2d::ui::UICCTextField *)new cocos2d::ui::UICCTextField();
    int num_ret = olua_push_cppobj(L, ret, "ccui.UICCTextField");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_UICCTextField_onTextFieldAttachWithIME(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::UICCTextField *self = nullptr;
    cocos2d::TextFieldTTF *arg1 = nullptr;       /** pSender */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.UICCTextField");
    olua_check_cppobj(L, 2, (void **)&arg1, "cc.TextFieldTTF");

    // bool onTextFieldAttachWithIME(cocos2d::TextFieldTTF *pSender)
    bool ret = (bool)self->onTextFieldAttachWithIME(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_UICCTextField_onTextFieldDeleteBackward(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::UICCTextField *self = nullptr;
    cocos2d::TextFieldTTF *arg1 = nullptr;       /** pSender */
    const char *arg2 = nullptr;       /** delText */
    lua_Unsigned arg3 = 0;       /** nLen */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.UICCTextField");
    olua_check_cppobj(L, 2, (void **)&arg1, "cc.TextFieldTTF");
    olua_check_string(L, 3, &arg2);
    olua_check_uint(L, 4, &arg3);

    // bool onTextFieldDeleteBackward(cocos2d::TextFieldTTF *pSender, const char *delText, size_t nLen)
    bool ret = (bool)self->onTextFieldDeleteBackward(arg1, arg2, (size_t)arg3);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_UICCTextField_onTextFieldDetachWithIME(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::UICCTextField *self = nullptr;
    cocos2d::TextFieldTTF *arg1 = nullptr;       /** pSender */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.UICCTextField");
    olua_check_cppobj(L, 2, (void **)&arg1, "cc.TextFieldTTF");

    // bool onTextFieldDetachWithIME(cocos2d::TextFieldTTF *pSender)
    bool ret = (bool)self->onTextFieldDetachWithIME(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_UICCTextField_onTextFieldInsertText(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::UICCTextField *self = nullptr;
    cocos2d::TextFieldTTF *arg1 = nullptr;       /** pSender */
    const char *arg2 = nullptr;       /** text */
    lua_Unsigned arg3 = 0;       /** nLen */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.UICCTextField");
    olua_check_cppobj(L, 2, (void **)&arg1, "cc.TextFieldTTF");
    olua_check_string(L, 3, &arg2);
    olua_check_uint(L, 4, &arg3);

    // bool onTextFieldInsertText(cocos2d::TextFieldTTF *pSender, const char *text, size_t nLen)
    bool ret = (bool)self->onTextFieldInsertText(arg1, arg2, (size_t)arg3);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_UICCTextField_openIME(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::UICCTextField *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.UICCTextField");

    // void openIME()
    self->openIME();

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_UICCTextField_setAttachWithIME(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::UICCTextField *self = nullptr;
    bool arg1 = false;       /** attach */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.UICCTextField");
    olua_check_bool(L, 2, &arg1);

    // void setAttachWithIME(bool attach)
    self->setAttachWithIME(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_UICCTextField_setDeleteBackward(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::UICCTextField *self = nullptr;
    bool arg1 = false;       /** deleteBackward */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.UICCTextField");
    olua_check_bool(L, 2, &arg1);

    // void setDeleteBackward(bool deleteBackward)
    self->setDeleteBackward(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_UICCTextField_setDetachWithIME(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::UICCTextField *self = nullptr;
    bool arg1 = false;       /** detach */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.UICCTextField");
    olua_check_bool(L, 2, &arg1);

    // void setDetachWithIME(bool detach)
    self->setDetachWithIME(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_UICCTextField_setInsertText(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::UICCTextField *self = nullptr;
    bool arg1 = false;       /** insert */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.UICCTextField");
    olua_check_bool(L, 2, &arg1);

    // void setInsertText(bool insert)
    self->setInsertText(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_UICCTextField_setMaxLength(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::UICCTextField *self = nullptr;
    lua_Integer arg1 = 0;       /** length */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.UICCTextField");
    olua_check_int(L, 2, &arg1);

    // void setMaxLength(int length)
    self->setMaxLength((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_UICCTextField_setMaxLengthEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::UICCTextField *self = nullptr;
    bool arg1 = false;       /** enable */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.UICCTextField");
    olua_check_bool(L, 2, &arg1);

    // void setMaxLengthEnabled(bool enable)
    self->setMaxLengthEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_UICCTextField_setPasswordEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::UICCTextField *self = nullptr;
    bool arg1 = false;       /** enable */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.UICCTextField");
    olua_check_bool(L, 2, &arg1);

    // void setPasswordEnabled(bool enable)
    self->setPasswordEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_UICCTextField_setPasswordStyleText(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::UICCTextField *self = nullptr;
    std::string arg1;       /** styleText */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.UICCTextField");
    olua_check_std_string(L, 2, &arg1);

    // void setPasswordStyleText(const std::string &styleText)
    self->setPasswordStyleText(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_UICCTextField_setPasswordText(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::UICCTextField *self = nullptr;
    std::string arg1;       /** text */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.UICCTextField");
    olua_check_std_string(L, 2, &arg1);

    // void setPasswordText(const std::string &text)
    self->setPasswordText(arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_ui_UICCTextField(lua_State *L)
{
    oluacls_class(L, "ccui.UICCTextField", "cc.TextFieldTTF");
    oluacls_func(L, "__move", _cocos2d_ui_UICCTextField___move);
    oluacls_func(L, "closeIME", _cocos2d_ui_UICCTextField_closeIME);
    oluacls_func(L, "create", _cocos2d_ui_UICCTextField_create);
    oluacls_func(L, "getAttachWithIME", _cocos2d_ui_UICCTextField_getAttachWithIME);
    oluacls_func(L, "getDeleteBackward", _cocos2d_ui_UICCTextField_getDeleteBackward);
    oluacls_func(L, "getDetachWithIME", _cocos2d_ui_UICCTextField_getDetachWithIME);
    oluacls_func(L, "getInsertText", _cocos2d_ui_UICCTextField_getInsertText);
    oluacls_func(L, "getMaxLength", _cocos2d_ui_UICCTextField_getMaxLength);
    oluacls_func(L, "insertText", _cocos2d_ui_UICCTextField_insertText);
    oluacls_func(L, "isMaxLengthEnabled", _cocos2d_ui_UICCTextField_isMaxLengthEnabled);
    oluacls_func(L, "isPasswordEnabled", _cocos2d_ui_UICCTextField_isPasswordEnabled);
    oluacls_func(L, "new", _cocos2d_ui_UICCTextField_new);
    oluacls_func(L, "onTextFieldAttachWithIME", _cocos2d_ui_UICCTextField_onTextFieldAttachWithIME);
    oluacls_func(L, "onTextFieldDeleteBackward", _cocos2d_ui_UICCTextField_onTextFieldDeleteBackward);
    oluacls_func(L, "onTextFieldDetachWithIME", _cocos2d_ui_UICCTextField_onTextFieldDetachWithIME);
    oluacls_func(L, "onTextFieldInsertText", _cocos2d_ui_UICCTextField_onTextFieldInsertText);
    oluacls_func(L, "openIME", _cocos2d_ui_UICCTextField_openIME);
    oluacls_func(L, "setAttachWithIME", _cocos2d_ui_UICCTextField_setAttachWithIME);
    oluacls_func(L, "setDeleteBackward", _cocos2d_ui_UICCTextField_setDeleteBackward);
    oluacls_func(L, "setDetachWithIME", _cocos2d_ui_UICCTextField_setDetachWithIME);
    oluacls_func(L, "setInsertText", _cocos2d_ui_UICCTextField_setInsertText);
    oluacls_func(L, "setMaxLength", _cocos2d_ui_UICCTextField_setMaxLength);
    oluacls_func(L, "setMaxLengthEnabled", _cocos2d_ui_UICCTextField_setMaxLengthEnabled);
    oluacls_func(L, "setPasswordEnabled", _cocos2d_ui_UICCTextField_setPasswordEnabled);
    oluacls_func(L, "setPasswordStyleText", _cocos2d_ui_UICCTextField_setPasswordStyleText);
    oluacls_func(L, "setPasswordText", _cocos2d_ui_UICCTextField_setPasswordText);
    oluacls_prop(L, "attachWithIME", _cocos2d_ui_UICCTextField_getAttachWithIME, _cocos2d_ui_UICCTextField_setAttachWithIME);
    oluacls_prop(L, "deleteBackward", _cocos2d_ui_UICCTextField_getDeleteBackward, _cocos2d_ui_UICCTextField_setDeleteBackward);
    oluacls_prop(L, "detachWithIME", _cocos2d_ui_UICCTextField_getDetachWithIME, _cocos2d_ui_UICCTextField_setDetachWithIME);
    oluacls_prop(L, "insertText", _cocos2d_ui_UICCTextField_getInsertText, _cocos2d_ui_UICCTextField_setInsertText);
    oluacls_prop(L, "maxLength", _cocos2d_ui_UICCTextField_getMaxLength, _cocos2d_ui_UICCTextField_setMaxLength);
    oluacls_prop(L, "maxLengthEnabled", _cocos2d_ui_UICCTextField_isMaxLengthEnabled, _cocos2d_ui_UICCTextField_setMaxLengthEnabled);
    oluacls_prop(L, "passwordEnabled", _cocos2d_ui_UICCTextField_isPasswordEnabled, _cocos2d_ui_UICCTextField_setPasswordEnabled);

    olua_registerluatype<cocos2d::ui::UICCTextField>(L, "ccui.UICCTextField");

    return 1;
}

static int luaopen_cocos2d_ui_TextField_EventType(lua_State *L)
{
    oluacls_class(L, "ccui.TextField.EventType", nullptr);
    oluacls_const_integer(L, "ATTACH_WITH_IME", (lua_Integer)cocos2d::ui::TextField::EventType::ATTACH_WITH_IME);
    oluacls_const_integer(L, "DELETE_BACKWARD", (lua_Integer)cocos2d::ui::TextField::EventType::DELETE_BACKWARD);
    oluacls_const_integer(L, "DETACH_WITH_IME", (lua_Integer)cocos2d::ui::TextField::EventType::DETACH_WITH_IME);
    oluacls_const_integer(L, "INSERT_TEXT", (lua_Integer)cocos2d::ui::TextField::EventType::INSERT_TEXT);

    olua_registerluatype<cocos2d::ui::TextField::EventType>(L, "ccui.TextField.EventType");

    return 1;
}

static int _cocos2d_ui_TextField___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::ui::TextField *)olua_toobj(L, 1, "ccui.TextField");
    olua_push_cppobj(L, self, "ccui.TextField");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_ui_TextField_addEventListener(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;
    std::function<void(cocos2d::Ref *, cocos2d::ui::TextField::EventType)> arg1;       /** callback */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TextField");

    if (olua_is_std_function(L, 2)) {
        void *callback_store_obj = (void *)self;
        std::string tag = "textFieldCallback";
        std::string func = olua_setcallback(L, callback_store_obj, tag.c_str(), 2, OLUA_TAG_REPLACE);
        lua_State *MT = olua_mainthread();
        arg1 = [callback_store_obj, func, MT](cocos2d::Ref *arg1, cocos2d::ui::TextField::EventType arg2) {
            lua_State *L = olua_mainthread();

            if (MT == L) {
                int top = lua_gettop(L);
                olua_push_cppobj(L, arg1, "cc.Ref");
                olua_push_uint(L, (lua_Unsigned)arg2);

                olua_callback(L, callback_store_obj, func.c_str(), 2);

                lua_settop(L, top);
            }
        };
    } else {
        void *callback_store_obj = (void *)self;
        std::string tag = "textFieldCallback";
        olua_removecallback(L, callback_store_obj, tag.c_str(), OLUA_TAG_SUBEQUAL);
        arg1 = nullptr;
    }

    // void addEventListener(@nullable const std::function<void(Ref*, EventType)>& callback)
    self->addEventListener(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_TextField_attachWithIME(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TextField");

    // void attachWithIME()
    self->attachWithIME();

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_TextField_create1(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::ui::TextField *create()
    cocos2d::ui::TextField *ret = (cocos2d::ui::TextField *)cocos2d::ui::TextField::create();
    int num_ret = olua_push_cppobj(L, ret, "ccui.TextField");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_TextField_create2(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** placeholder */
    std::string arg2;       /** fontName */
    lua_Integer arg3 = 0;       /** fontSize */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);
    olua_check_int(L, 3, &arg3);

    // static cocos2d::ui::TextField *create(const std::string &placeholder, const std::string &fontName, int fontSize)
    cocos2d::ui::TextField *ret = (cocos2d::ui::TextField *)cocos2d::ui::TextField::create(arg1, arg2, (int)arg3);
    int num_ret = olua_push_cppobj(L, ret, "ccui.TextField");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_TextField_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // static cocos2d::ui::TextField *create()
        return _cocos2d_ui_TextField_create1(L);
    }

    if (num_args == 3) {
        // if ((olua_is_std_string(L, 1)) && (olua_is_std_string(L, 2)) && (olua_is_int(L, 3))) {
            // static cocos2d::ui::TextField *create(const std::string &placeholder, const std::string &fontName, int fontSize)
            return _cocos2d_ui_TextField_create2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::TextField::create' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ui_TextField_createInstance(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::Ref *createInstance()
    cocos2d::Ref *ret = (cocos2d::Ref *)cocos2d::ui::TextField::createInstance();
    int num_ret = olua_push_cppobj(L, ret, "cc.Ref");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_TextField_didNotSelectSelf(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TextField");

    // void didNotSelectSelf()
    self->didNotSelectSelf();

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_TextField_getAttachWithIME(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TextField");

    // bool getAttachWithIME()
    bool ret = (bool)self->getAttachWithIME();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_TextField_getAutoRenderSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TextField");

    // cocos2d::Size getAutoRenderSize()
    cocos2d::Size ret = (cocos2d::Size)self->getAutoRenderSize();
    int num_ret = auto_olua_push_cocos2d_Size(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_TextField_getDeleteBackward(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TextField");

    // bool getDeleteBackward()
    bool ret = (bool)self->getDeleteBackward();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_TextField_getDetachWithIME(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TextField");

    // bool getDetachWithIME()
    bool ret = (bool)self->getDetachWithIME();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_TextField_getFontName(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TextField");

    // const std::string &getFontName()
    const std::string &ret = (const std::string &)self->getFontName();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_TextField_getFontSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TextField");

    // int getFontSize()
    int ret = (int)self->getFontSize();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_TextField_getInsertText(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TextField");

    // bool getInsertText()
    bool ret = (bool)self->getInsertText();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_TextField_getMaxLength(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TextField");

    // int getMaxLength()
    int ret = (int)self->getMaxLength();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_TextField_getPasswordStyleText(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TextField");

    // const char *getPasswordStyleText()
    const char *ret = (const char *)self->getPasswordStyleText();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_TextField_getPlaceHolder(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TextField");

    // const std::string &getPlaceHolder()
    const std::string &ret = (const std::string &)self->getPlaceHolder();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_TextField_getPlaceHolderColor(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TextField");

    // const cocos2d::Color4B &getPlaceHolderColor()
    const cocos2d::Color4B &ret = (const cocos2d::Color4B &)self->getPlaceHolderColor();
    int num_ret = manual_olua_push_cocos2d_Color4B(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_TextField_getString(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TextField");

    // const std::string &getString()
    const std::string &ret = (const std::string &)self->getString();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_TextField_getStringLength(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TextField");

    // int getStringLength()
    int ret = (int)self->getStringLength();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_TextField_getTextColor(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TextField");

    // const cocos2d::Color4B &getTextColor()
    const cocos2d::Color4B &ret = (const cocos2d::Color4B &)self->getTextColor();
    int num_ret = manual_olua_push_cocos2d_Color4B(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_TextField_getTextHorizontalAlignment(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TextField");

    // cocos2d::TextHAlignment getTextHorizontalAlignment()
    cocos2d::TextHAlignment ret = (cocos2d::TextHAlignment)self->getTextHorizontalAlignment();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_TextField_getTextVerticalAlignment(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TextField");

    // cocos2d::TextVAlignment getTextVerticalAlignment()
    cocos2d::TextVAlignment ret = (cocos2d::TextVAlignment)self->getTextVerticalAlignment();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_TextField_getTouchSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TextField");

    // cocos2d::Size getTouchSize()
    cocos2d::Size ret = (cocos2d::Size)self->getTouchSize();
    int num_ret = auto_olua_push_cocos2d_Size(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_TextField_isMaxLengthEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TextField");

    // bool isMaxLengthEnabled()
    bool ret = (bool)self->isMaxLengthEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_TextField_isPasswordEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TextField");

    // bool isPasswordEnabled()
    bool ret = (bool)self->isPasswordEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_TextField_new(lua_State *L)
{
    olua_startinvoke(L);

    // TextField()
    cocos2d::ui::TextField *ret = (cocos2d::ui::TextField *)new cocos2d::ui::TextField();
    int num_ret = olua_push_cppobj(L, ret, "ccui.TextField");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_TextField_setAttachWithIME(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;
    bool arg1 = false;       /** attach */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TextField");
    olua_check_bool(L, 2, &arg1);

    // void setAttachWithIME(bool attach)
    self->setAttachWithIME(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_TextField_setCursorChar(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;
    lua_Integer arg1 = 0;       /** cursor */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TextField");
    olua_check_int(L, 2, &arg1);

    // void setCursorChar(char cursor)
    self->setCursorChar((char)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_TextField_setCursorEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;
    bool arg1 = false;       /** enabled */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TextField");
    olua_check_bool(L, 2, &arg1);

    // void setCursorEnabled(bool enabled)
    self->setCursorEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_TextField_setCursorFromPoint(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;
    cocos2d::Vec2 arg1;       /** point */
    cocos2d::Camera *arg2 = nullptr;       /** camera */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TextField");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);
    olua_check_cppobj(L, 3, (void **)&arg2, "cc.Camera");

    // void setCursorFromPoint(const cocos2d::Vec2 &point, const cocos2d::Camera *camera)
    self->setCursorFromPoint(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_TextField_setCursorPosition(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;
    lua_Unsigned arg1 = 0;       /** cursorPosition */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TextField");
    olua_check_uint(L, 2, &arg1);

    // void setCursorPosition(std::size_t cursorPosition)
    self->setCursorPosition((std::size_t)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_TextField_setDeleteBackward(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;
    bool arg1 = false;       /** deleteBackward */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TextField");
    olua_check_bool(L, 2, &arg1);

    // void setDeleteBackward(bool deleteBackward)
    self->setDeleteBackward(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_TextField_setDetachWithIME(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;
    bool arg1 = false;       /** detach */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TextField");
    olua_check_bool(L, 2, &arg1);

    // void setDetachWithIME(bool detach)
    self->setDetachWithIME(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_TextField_setFontName(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;
    std::string arg1;       /** name */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TextField");
    olua_check_std_string(L, 2, &arg1);

    // void setFontName(const std::string &name)
    self->setFontName(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_TextField_setFontSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;
    lua_Integer arg1 = 0;       /** size */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TextField");
    olua_check_int(L, 2, &arg1);

    // void setFontSize(int size)
    self->setFontSize((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_TextField_setInsertText(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;
    bool arg1 = false;       /** insertText */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TextField");
    olua_check_bool(L, 2, &arg1);

    // void setInsertText(bool insertText)
    self->setInsertText(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_TextField_setMaxLength(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;
    lua_Integer arg1 = 0;       /** length */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TextField");
    olua_check_int(L, 2, &arg1);

    // void setMaxLength(int length)
    self->setMaxLength((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_TextField_setMaxLengthEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;
    bool arg1 = false;       /** enable */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TextField");
    olua_check_bool(L, 2, &arg1);

    // void setMaxLengthEnabled(bool enable)
    self->setMaxLengthEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_TextField_setPasswordEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;
    bool arg1 = false;       /** enable */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TextField");
    olua_check_bool(L, 2, &arg1);

    // void setPasswordEnabled(bool enable)
    self->setPasswordEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_TextField_setPasswordStyleText(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;
    const char *arg1 = nullptr;       /** styleText */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TextField");
    olua_check_string(L, 2, &arg1);

    // void setPasswordStyleText(const char *styleText)
    self->setPasswordStyleText(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_TextField_setPlaceHolder(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;
    std::string arg1;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TextField");
    olua_check_std_string(L, 2, &arg1);

    // void setPlaceHolder(const std::string &value)
    self->setPlaceHolder(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_TextField_setPlaceHolderColor1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;
    cocos2d::Color3B arg1;       /** color */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TextField");
    manual_olua_check_cocos2d_Color3B(L, 2, &arg1);

    // void setPlaceHolderColor(const cocos2d::Color3B &color)
    self->setPlaceHolderColor(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_TextField_setPlaceHolderColor2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;
    cocos2d::Color4B arg1;       /** color */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TextField");
    manual_olua_check_cocos2d_Color4B(L, 2, &arg1);

    // void setPlaceHolderColor(const cocos2d::Color4B &color)
    self->setPlaceHolderColor(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_TextField_setPlaceHolderColor(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        if ((manual_olua_is_cocos2d_Color3B(L, 2))) {
            // void setPlaceHolderColor(const cocos2d::Color3B &color)
            return _cocos2d_ui_TextField_setPlaceHolderColor1(L);
        }

        // if ((manual_olua_is_cocos2d_Color4B(L, 2))) {
            // void setPlaceHolderColor(const cocos2d::Color4B &color)
            return _cocos2d_ui_TextField_setPlaceHolderColor2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::TextField::setPlaceHolderColor' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ui_TextField_setString(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;
    std::string arg1;       /** text */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TextField");
    olua_check_std_string(L, 2, &arg1);

    // void setString(const std::string &text)
    self->setString(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_TextField_setTextAreaSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;
    cocos2d::Size arg1;       /** size */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TextField");
    auto_olua_check_cocos2d_Size(L, 2, &arg1);

    // void setTextAreaSize(const cocos2d::Size &size)
    self->setTextAreaSize(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_TextField_setTextColor(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;
    cocos2d::Color4B arg1;       /** textColor */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TextField");
    manual_olua_check_cocos2d_Color4B(L, 2, &arg1);

    // void setTextColor(const cocos2d::Color4B &textColor)
    self->setTextColor(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_TextField_setTextHorizontalAlignment(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;
    lua_Unsigned arg1 = 0;       /** alignment */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TextField");
    olua_check_uint(L, 2, &arg1);

    // void setTextHorizontalAlignment(cocos2d::TextHAlignment alignment)
    self->setTextHorizontalAlignment((cocos2d::TextHAlignment)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_TextField_setTextVerticalAlignment(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;
    lua_Unsigned arg1 = 0;       /** alignment */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TextField");
    olua_check_uint(L, 2, &arg1);

    // void setTextVerticalAlignment(cocos2d::TextVAlignment alignment)
    self->setTextVerticalAlignment((cocos2d::TextVAlignment)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_TextField_setTouchAreaEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;
    bool arg1 = false;       /** enable */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TextField");
    olua_check_bool(L, 2, &arg1);

    // void setTouchAreaEnabled(bool enable)
    self->setTouchAreaEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_TextField_setTouchSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::TextField *self = nullptr;
    cocos2d::Size arg1;       /** size */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.TextField");
    auto_olua_check_cocos2d_Size(L, 2, &arg1);

    // void setTouchSize(const cocos2d::Size &size)
    self->setTouchSize(arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_ui_TextField(lua_State *L)
{
    oluacls_class(L, "ccui.TextField", "ccui.Widget");
    oluacls_func(L, "__move", _cocos2d_ui_TextField___move);
    oluacls_func(L, "addEventListener", _cocos2d_ui_TextField_addEventListener);
    oluacls_func(L, "attachWithIME", _cocos2d_ui_TextField_attachWithIME);
    oluacls_func(L, "create", _cocos2d_ui_TextField_create);
    oluacls_func(L, "createInstance", _cocos2d_ui_TextField_createInstance);
    oluacls_func(L, "didNotSelectSelf", _cocos2d_ui_TextField_didNotSelectSelf);
    oluacls_func(L, "getAttachWithIME", _cocos2d_ui_TextField_getAttachWithIME);
    oluacls_func(L, "getAutoRenderSize", _cocos2d_ui_TextField_getAutoRenderSize);
    oluacls_func(L, "getDeleteBackward", _cocos2d_ui_TextField_getDeleteBackward);
    oluacls_func(L, "getDetachWithIME", _cocos2d_ui_TextField_getDetachWithIME);
    oluacls_func(L, "getFontName", _cocos2d_ui_TextField_getFontName);
    oluacls_func(L, "getFontSize", _cocos2d_ui_TextField_getFontSize);
    oluacls_func(L, "getInsertText", _cocos2d_ui_TextField_getInsertText);
    oluacls_func(L, "getMaxLength", _cocos2d_ui_TextField_getMaxLength);
    oluacls_func(L, "getPasswordStyleText", _cocos2d_ui_TextField_getPasswordStyleText);
    oluacls_func(L, "getPlaceHolder", _cocos2d_ui_TextField_getPlaceHolder);
    oluacls_func(L, "getPlaceHolderColor", _cocos2d_ui_TextField_getPlaceHolderColor);
    oluacls_func(L, "getString", _cocos2d_ui_TextField_getString);
    oluacls_func(L, "getStringLength", _cocos2d_ui_TextField_getStringLength);
    oluacls_func(L, "getTextColor", _cocos2d_ui_TextField_getTextColor);
    oluacls_func(L, "getTextHorizontalAlignment", _cocos2d_ui_TextField_getTextHorizontalAlignment);
    oluacls_func(L, "getTextVerticalAlignment", _cocos2d_ui_TextField_getTextVerticalAlignment);
    oluacls_func(L, "getTouchSize", _cocos2d_ui_TextField_getTouchSize);
    oluacls_func(L, "isMaxLengthEnabled", _cocos2d_ui_TextField_isMaxLengthEnabled);
    oluacls_func(L, "isPasswordEnabled", _cocos2d_ui_TextField_isPasswordEnabled);
    oluacls_func(L, "new", _cocos2d_ui_TextField_new);
    oluacls_func(L, "setAttachWithIME", _cocos2d_ui_TextField_setAttachWithIME);
    oluacls_func(L, "setCursorChar", _cocos2d_ui_TextField_setCursorChar);
    oluacls_func(L, "setCursorEnabled", _cocos2d_ui_TextField_setCursorEnabled);
    oluacls_func(L, "setCursorFromPoint", _cocos2d_ui_TextField_setCursorFromPoint);
    oluacls_func(L, "setCursorPosition", _cocos2d_ui_TextField_setCursorPosition);
    oluacls_func(L, "setDeleteBackward", _cocos2d_ui_TextField_setDeleteBackward);
    oluacls_func(L, "setDetachWithIME", _cocos2d_ui_TextField_setDetachWithIME);
    oluacls_func(L, "setFontName", _cocos2d_ui_TextField_setFontName);
    oluacls_func(L, "setFontSize", _cocos2d_ui_TextField_setFontSize);
    oluacls_func(L, "setInsertText", _cocos2d_ui_TextField_setInsertText);
    oluacls_func(L, "setMaxLength", _cocos2d_ui_TextField_setMaxLength);
    oluacls_func(L, "setMaxLengthEnabled", _cocos2d_ui_TextField_setMaxLengthEnabled);
    oluacls_func(L, "setPasswordEnabled", _cocos2d_ui_TextField_setPasswordEnabled);
    oluacls_func(L, "setPasswordStyleText", _cocos2d_ui_TextField_setPasswordStyleText);
    oluacls_func(L, "setPlaceHolder", _cocos2d_ui_TextField_setPlaceHolder);
    oluacls_func(L, "setPlaceHolderColor", _cocos2d_ui_TextField_setPlaceHolderColor);
    oluacls_func(L, "setString", _cocos2d_ui_TextField_setString);
    oluacls_func(L, "setTextAreaSize", _cocos2d_ui_TextField_setTextAreaSize);
    oluacls_func(L, "setTextColor", _cocos2d_ui_TextField_setTextColor);
    oluacls_func(L, "setTextHorizontalAlignment", _cocos2d_ui_TextField_setTextHorizontalAlignment);
    oluacls_func(L, "setTextVerticalAlignment", _cocos2d_ui_TextField_setTextVerticalAlignment);
    oluacls_func(L, "setTouchAreaEnabled", _cocos2d_ui_TextField_setTouchAreaEnabled);
    oluacls_func(L, "setTouchSize", _cocos2d_ui_TextField_setTouchSize);
    oluacls_prop(L, "attachWithIME", _cocos2d_ui_TextField_getAttachWithIME, _cocos2d_ui_TextField_setAttachWithIME);
    oluacls_prop(L, "autoRenderSize", _cocos2d_ui_TextField_getAutoRenderSize, nullptr);
    oluacls_prop(L, "deleteBackward", _cocos2d_ui_TextField_getDeleteBackward, _cocos2d_ui_TextField_setDeleteBackward);
    oluacls_prop(L, "detachWithIME", _cocos2d_ui_TextField_getDetachWithIME, _cocos2d_ui_TextField_setDetachWithIME);
    oluacls_prop(L, "fontName", _cocos2d_ui_TextField_getFontName, _cocos2d_ui_TextField_setFontName);
    oluacls_prop(L, "fontSize", _cocos2d_ui_TextField_getFontSize, _cocos2d_ui_TextField_setFontSize);
    oluacls_prop(L, "insertText", _cocos2d_ui_TextField_getInsertText, _cocos2d_ui_TextField_setInsertText);
    oluacls_prop(L, "maxLength", _cocos2d_ui_TextField_getMaxLength, _cocos2d_ui_TextField_setMaxLength);
    oluacls_prop(L, "maxLengthEnabled", _cocos2d_ui_TextField_isMaxLengthEnabled, _cocos2d_ui_TextField_setMaxLengthEnabled);
    oluacls_prop(L, "passwordEnabled", _cocos2d_ui_TextField_isPasswordEnabled, _cocos2d_ui_TextField_setPasswordEnabled);
    oluacls_prop(L, "passwordStyleText", _cocos2d_ui_TextField_getPasswordStyleText, _cocos2d_ui_TextField_setPasswordStyleText);
    oluacls_prop(L, "placeHolder", _cocos2d_ui_TextField_getPlaceHolder, _cocos2d_ui_TextField_setPlaceHolder);
    oluacls_prop(L, "placeHolderColor", _cocos2d_ui_TextField_getPlaceHolderColor, _cocos2d_ui_TextField_setPlaceHolderColor);
    oluacls_prop(L, "string", _cocos2d_ui_TextField_getString, _cocos2d_ui_TextField_setString);
    oluacls_prop(L, "stringLength", _cocos2d_ui_TextField_getStringLength, nullptr);
    oluacls_prop(L, "textColor", _cocos2d_ui_TextField_getTextColor, _cocos2d_ui_TextField_setTextColor);
    oluacls_prop(L, "textHorizontalAlignment", _cocos2d_ui_TextField_getTextHorizontalAlignment, _cocos2d_ui_TextField_setTextHorizontalAlignment);
    oluacls_prop(L, "textVerticalAlignment", _cocos2d_ui_TextField_getTextVerticalAlignment, _cocos2d_ui_TextField_setTextVerticalAlignment);
    oluacls_prop(L, "touchSize", _cocos2d_ui_TextField_getTouchSize, _cocos2d_ui_TextField_setTouchSize);

    olua_registerluatype<cocos2d::ui::TextField>(L, "ccui.TextField");

    return 1;
}

static int _cocos2d_ui_Button___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::ui::Button *)olua_toobj(L, 1, "ccui.Button");
    olua_push_cppobj(L, self, "ccui.Button");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_ui_Button_create1(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::ui::Button *create()
    cocos2d::ui::Button *ret = (cocos2d::ui::Button *)cocos2d::ui::Button::create();
    int num_ret = olua_push_cppobj(L, ret, "ccui.Button");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Button_create2(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** normalImage */
    std::string arg2;       /** selectedImage */
    std::string arg3;       /** disableImage */
    lua_Unsigned arg4 = 0;       /** texType */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);
    olua_check_std_string(L, 3, &arg3);
    olua_check_uint(L, 4, &arg4);

    // static cocos2d::ui::Button *create(const std::string &normalImage, @optional const std::string &selectedImage, @optional const std::string &disableImage, @optional cocos2d::ui::Widget::TextureResType texType)
    cocos2d::ui::Button *ret = (cocos2d::ui::Button *)cocos2d::ui::Button::create(arg1, arg2, arg3, (cocos2d::ui::Widget::TextureResType)arg4);
    int num_ret = olua_push_cppobj(L, ret, "ccui.Button");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Button_create3(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** normalImage */

    olua_check_std_string(L, 1, &arg1);

    // static cocos2d::ui::Button *create(const std::string &normalImage, @optional const std::string &selectedImage, @optional const std::string &disableImage, @optional cocos2d::ui::Widget::TextureResType texType)
    cocos2d::ui::Button *ret = (cocos2d::ui::Button *)cocos2d::ui::Button::create(arg1);
    int num_ret = olua_push_cppobj(L, ret, "ccui.Button");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Button_create4(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** normalImage */
    std::string arg2;       /** selectedImage */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);

    // static cocos2d::ui::Button *create(const std::string &normalImage, @optional const std::string &selectedImage, @optional const std::string &disableImage, @optional cocos2d::ui::Widget::TextureResType texType)
    cocos2d::ui::Button *ret = (cocos2d::ui::Button *)cocos2d::ui::Button::create(arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "ccui.Button");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Button_create5(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** normalImage */
    std::string arg2;       /** selectedImage */
    std::string arg3;       /** disableImage */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);
    olua_check_std_string(L, 3, &arg3);

    // static cocos2d::ui::Button *create(const std::string &normalImage, @optional const std::string &selectedImage, @optional const std::string &disableImage, @optional cocos2d::ui::Widget::TextureResType texType)
    cocos2d::ui::Button *ret = (cocos2d::ui::Button *)cocos2d::ui::Button::create(arg1, arg2, arg3);
    int num_ret = olua_push_cppobj(L, ret, "ccui.Button");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Button_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // static cocos2d::ui::Button *create()
        return _cocos2d_ui_Button_create1(L);
    }

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 1))) {
            // static cocos2d::ui::Button *create(const std::string &normalImage, @optional const std::string &selectedImage, @optional const std::string &disableImage, @optional cocos2d::ui::Widget::TextureResType texType)
            return _cocos2d_ui_Button_create3(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 1)) && (olua_is_std_string(L, 2))) {
            // static cocos2d::ui::Button *create(const std::string &normalImage, @optional const std::string &selectedImage, @optional const std::string &disableImage, @optional cocos2d::ui::Widget::TextureResType texType)
            return _cocos2d_ui_Button_create4(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_std_string(L, 1)) && (olua_is_std_string(L, 2)) && (olua_is_std_string(L, 3))) {
            // static cocos2d::ui::Button *create(const std::string &normalImage, @optional const std::string &selectedImage, @optional const std::string &disableImage, @optional cocos2d::ui::Widget::TextureResType texType)
            return _cocos2d_ui_Button_create5(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_std_string(L, 1)) && (olua_is_std_string(L, 2)) && (olua_is_std_string(L, 3)) && (olua_is_uint(L, 4))) {
            // static cocos2d::ui::Button *create(const std::string &normalImage, @optional const std::string &selectedImage, @optional const std::string &disableImage, @optional cocos2d::ui::Widget::TextureResType texType)
            return _cocos2d_ui_Button_create2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::Button::create' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ui_Button_createInstance(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::Ref *createInstance()
    cocos2d::Ref *ret = (cocos2d::Ref *)cocos2d::ui::Button::createInstance();
    int num_ret = olua_push_cppobj(L, ret, "cc.Ref");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Button_getCapInsetsDisabledRenderer(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Button");

    // const cocos2d::Rect &getCapInsetsDisabledRenderer()
    const cocos2d::Rect &ret = (const cocos2d::Rect &)self->getCapInsetsDisabledRenderer();
    int num_ret = manual_olua_push_cocos2d_Rect(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Button_getCapInsetsNormalRenderer(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Button");

    // const cocos2d::Rect &getCapInsetsNormalRenderer()
    const cocos2d::Rect &ret = (const cocos2d::Rect &)self->getCapInsetsNormalRenderer();
    int num_ret = manual_olua_push_cocos2d_Rect(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Button_getCapInsetsPressedRenderer(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Button");

    // const cocos2d::Rect &getCapInsetsPressedRenderer()
    const cocos2d::Rect &ret = (const cocos2d::Rect &)self->getCapInsetsPressedRenderer();
    int num_ret = manual_olua_push_cocos2d_Rect(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Button_getDisabledFile(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Button");

    // cocos2d::ResourceData getDisabledFile()
    cocos2d::ResourceData ret = (cocos2d::ResourceData)self->getDisabledFile();
    int num_ret = auto_olua_push_cocos2d_ResourceData(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Button_getNormalFile(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Button");

    // cocos2d::ResourceData getNormalFile()
    cocos2d::ResourceData ret = (cocos2d::ResourceData)self->getNormalFile();
    int num_ret = auto_olua_push_cocos2d_ResourceData(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Button_getNormalTextureSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Button");

    // cocos2d::Size getNormalTextureSize()
    cocos2d::Size ret = (cocos2d::Size)self->getNormalTextureSize();
    int num_ret = auto_olua_push_cocos2d_Size(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Button_getPressedFile(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Button");

    // cocos2d::ResourceData getPressedFile()
    cocos2d::ResourceData ret = (cocos2d::ResourceData)self->getPressedFile();
    int num_ret = auto_olua_push_cocos2d_ResourceData(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Button_getRendererClicked(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Button");

    // @addref(protectedChildren |) cocos2d::ui::Scale9Sprite *getRendererClicked()
    cocos2d::ui::Scale9Sprite *ret = (cocos2d::ui::Scale9Sprite *)self->getRendererClicked();
    int num_ret = olua_push_cppobj(L, ret, "ccui.Scale9Sprite");

    // inject code after call
    olua_addref(L, 1, "protectedChildren", -1, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Button_getRendererDisabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Button");

    // @addref(protectedChildren |) cocos2d::ui::Scale9Sprite *getRendererDisabled()
    cocos2d::ui::Scale9Sprite *ret = (cocos2d::ui::Scale9Sprite *)self->getRendererDisabled();
    int num_ret = olua_push_cppobj(L, ret, "ccui.Scale9Sprite");

    // inject code after call
    olua_addref(L, 1, "protectedChildren", -1, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Button_getRendererNormal(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Button");

    // @addref(protectedChildren |) cocos2d::ui::Scale9Sprite *getRendererNormal()
    cocos2d::ui::Scale9Sprite *ret = (cocos2d::ui::Scale9Sprite *)self->getRendererNormal();
    int num_ret = olua_push_cppobj(L, ret, "ccui.Scale9Sprite");

    // inject code after call
    olua_addref(L, 1, "protectedChildren", -1, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Button_getTitleColor(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Button");

    // cocos2d::Color3B getTitleColor()
    cocos2d::Color3B ret = (cocos2d::Color3B)self->getTitleColor();
    int num_ret = manual_olua_push_cocos2d_Color3B(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Button_getTitleFontName(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Button");

    // std::string getTitleFontName()
    std::string ret = (std::string)self->getTitleFontName();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Button_getTitleFontSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Button");

    // float getTitleFontSize()
    float ret = (float)self->getTitleFontSize();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Button_getTitleLabel(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Button");

    // @addref(protectedChildren |) cocos2d::Label *getTitleLabel()
    cocos2d::Label *ret = (cocos2d::Label *)self->getTitleLabel();
    int num_ret = olua_push_cppobj(L, ret, "cc.Label");

    // inject code after call
    olua_addref(L, 1, "protectedChildren", -1, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Button_getTitleRenderer(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Button");

    // @addref(protectedChildren |) cocos2d::Label *getTitleRenderer()
    cocos2d::Label *ret = (cocos2d::Label *)self->getTitleRenderer();
    int num_ret = olua_push_cppobj(L, ret, "cc.Label");

    // inject code after call
    olua_addref(L, 1, "protectedChildren", -1, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Button_getTitleText(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Button");

    // std::string getTitleText()
    std::string ret = (std::string)self->getTitleText();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Button_getZoomScale(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Button");

    // float getZoomScale()
    float ret = (float)self->getZoomScale();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Button_init1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;
    std::string arg1;       /** normalImage */
    std::string arg2;       /** selectedImage */
    std::string arg3;       /** disableImage */
    lua_Unsigned arg4 = 0;       /** texType */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Button");
    olua_check_std_string(L, 2, &arg1);
    olua_check_std_string(L, 3, &arg2);
    olua_check_std_string(L, 4, &arg3);
    olua_check_uint(L, 5, &arg4);

    // bool init(const std::string &normalImage, @optional const std::string &selectedImage, @optional const std::string &disableImage, @optional cocos2d::ui::Widget::TextureResType texType)
    bool ret = (bool)self->init(arg1, arg2, arg3, (cocos2d::ui::Widget::TextureResType)arg4);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Button_init2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;
    std::string arg1;       /** normalImage */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Button");
    olua_check_std_string(L, 2, &arg1);

    // bool init(const std::string &normalImage, @optional const std::string &selectedImage, @optional const std::string &disableImage, @optional cocos2d::ui::Widget::TextureResType texType)
    bool ret = (bool)self->init(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Button_init3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;
    std::string arg1;       /** normalImage */
    std::string arg2;       /** selectedImage */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Button");
    olua_check_std_string(L, 2, &arg1);
    olua_check_std_string(L, 3, &arg2);

    // bool init(const std::string &normalImage, @optional const std::string &selectedImage, @optional const std::string &disableImage, @optional cocos2d::ui::Widget::TextureResType texType)
    bool ret = (bool)self->init(arg1, arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Button_init4(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;
    std::string arg1;       /** normalImage */
    std::string arg2;       /** selectedImage */
    std::string arg3;       /** disableImage */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Button");
    olua_check_std_string(L, 2, &arg1);
    olua_check_std_string(L, 3, &arg2);
    olua_check_std_string(L, 4, &arg3);

    // bool init(const std::string &normalImage, @optional const std::string &selectedImage, @optional const std::string &disableImage, @optional cocos2d::ui::Widget::TextureResType texType)
    bool ret = (bool)self->init(arg1, arg2, arg3);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Button_init(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 2))) {
            // bool init(const std::string &normalImage, @optional const std::string &selectedImage, @optional const std::string &disableImage, @optional cocos2d::ui::Widget::TextureResType texType)
            return _cocos2d_ui_Button_init2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_std_string(L, 3))) {
            // bool init(const std::string &normalImage, @optional const std::string &selectedImage, @optional const std::string &disableImage, @optional cocos2d::ui::Widget::TextureResType texType)
            return _cocos2d_ui_Button_init3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_std_string(L, 3)) && (olua_is_std_string(L, 4))) {
            // bool init(const std::string &normalImage, @optional const std::string &selectedImage, @optional const std::string &disableImage, @optional cocos2d::ui::Widget::TextureResType texType)
            return _cocos2d_ui_Button_init4(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_std_string(L, 3)) && (olua_is_std_string(L, 4)) && (olua_is_uint(L, 5))) {
            // bool init(const std::string &normalImage, @optional const std::string &selectedImage, @optional const std::string &disableImage, @optional cocos2d::ui::Widget::TextureResType texType)
            return _cocos2d_ui_Button_init1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::Button::init' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ui_Button_isScale9Enabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Button");

    // bool isScale9Enabled()
    bool ret = (bool)self->isScale9Enabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Button_loadTextureDisabled1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;
    std::string arg1;       /** disabled */
    lua_Unsigned arg2 = 0;       /** texType */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Button");
    olua_check_std_string(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // void loadTextureDisabled(const std::string &disabled, @optional cocos2d::ui::Widget::TextureResType texType)
    self->loadTextureDisabled(arg1, (cocos2d::ui::Widget::TextureResType)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Button_loadTextureDisabled2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;
    std::string arg1;       /** disabled */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Button");
    olua_check_std_string(L, 2, &arg1);

    // void loadTextureDisabled(const std::string &disabled, @optional cocos2d::ui::Widget::TextureResType texType)
    self->loadTextureDisabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Button_loadTextureDisabled(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 2))) {
            // void loadTextureDisabled(const std::string &disabled, @optional cocos2d::ui::Widget::TextureResType texType)
            return _cocos2d_ui_Button_loadTextureDisabled2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_uint(L, 3))) {
            // void loadTextureDisabled(const std::string &disabled, @optional cocos2d::ui::Widget::TextureResType texType)
            return _cocos2d_ui_Button_loadTextureDisabled1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::Button::loadTextureDisabled' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ui_Button_loadTextureNormal1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;
    std::string arg1;       /** normal */
    lua_Unsigned arg2 = 0;       /** texType */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Button");
    olua_check_std_string(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // void loadTextureNormal(const std::string &normal, @optional cocos2d::ui::Widget::TextureResType texType)
    self->loadTextureNormal(arg1, (cocos2d::ui::Widget::TextureResType)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Button_loadTextureNormal2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;
    std::string arg1;       /** normal */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Button");
    olua_check_std_string(L, 2, &arg1);

    // void loadTextureNormal(const std::string &normal, @optional cocos2d::ui::Widget::TextureResType texType)
    self->loadTextureNormal(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Button_loadTextureNormal(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 2))) {
            // void loadTextureNormal(const std::string &normal, @optional cocos2d::ui::Widget::TextureResType texType)
            return _cocos2d_ui_Button_loadTextureNormal2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_uint(L, 3))) {
            // void loadTextureNormal(const std::string &normal, @optional cocos2d::ui::Widget::TextureResType texType)
            return _cocos2d_ui_Button_loadTextureNormal1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::Button::loadTextureNormal' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ui_Button_loadTexturePressed1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;
    std::string arg1;       /** selected */
    lua_Unsigned arg2 = 0;       /** texType */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Button");
    olua_check_std_string(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // void loadTexturePressed(const std::string &selected, @optional cocos2d::ui::Widget::TextureResType texType)
    self->loadTexturePressed(arg1, (cocos2d::ui::Widget::TextureResType)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Button_loadTexturePressed2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;
    std::string arg1;       /** selected */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Button");
    olua_check_std_string(L, 2, &arg1);

    // void loadTexturePressed(const std::string &selected, @optional cocos2d::ui::Widget::TextureResType texType)
    self->loadTexturePressed(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Button_loadTexturePressed(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 2))) {
            // void loadTexturePressed(const std::string &selected, @optional cocos2d::ui::Widget::TextureResType texType)
            return _cocos2d_ui_Button_loadTexturePressed2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_uint(L, 3))) {
            // void loadTexturePressed(const std::string &selected, @optional cocos2d::ui::Widget::TextureResType texType)
            return _cocos2d_ui_Button_loadTexturePressed1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::Button::loadTexturePressed' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ui_Button_loadTextures1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;
    std::string arg1;       /** normal */
    std::string arg2;       /** selected */
    std::string arg3;       /** disabled */
    lua_Unsigned arg4 = 0;       /** texType */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Button");
    olua_check_std_string(L, 2, &arg1);
    olua_check_std_string(L, 3, &arg2);
    olua_check_std_string(L, 4, &arg3);
    olua_check_uint(L, 5, &arg4);

    // void loadTextures(const std::string &normal, const std::string &selected, @optional const std::string &disabled, @optional cocos2d::ui::Widget::TextureResType texType)
    self->loadTextures(arg1, arg2, arg3, (cocos2d::ui::Widget::TextureResType)arg4);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Button_loadTextures2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;
    std::string arg1;       /** normal */
    std::string arg2;       /** selected */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Button");
    olua_check_std_string(L, 2, &arg1);
    olua_check_std_string(L, 3, &arg2);

    // void loadTextures(const std::string &normal, const std::string &selected, @optional const std::string &disabled, @optional cocos2d::ui::Widget::TextureResType texType)
    self->loadTextures(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Button_loadTextures3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;
    std::string arg1;       /** normal */
    std::string arg2;       /** selected */
    std::string arg3;       /** disabled */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Button");
    olua_check_std_string(L, 2, &arg1);
    olua_check_std_string(L, 3, &arg2);
    olua_check_std_string(L, 4, &arg3);

    // void loadTextures(const std::string &normal, const std::string &selected, @optional const std::string &disabled, @optional cocos2d::ui::Widget::TextureResType texType)
    self->loadTextures(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Button_loadTextures(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_std_string(L, 3))) {
            // void loadTextures(const std::string &normal, const std::string &selected, @optional const std::string &disabled, @optional cocos2d::ui::Widget::TextureResType texType)
            return _cocos2d_ui_Button_loadTextures2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_std_string(L, 3)) && (olua_is_std_string(L, 4))) {
            // void loadTextures(const std::string &normal, const std::string &selected, @optional const std::string &disabled, @optional cocos2d::ui::Widget::TextureResType texType)
            return _cocos2d_ui_Button_loadTextures3(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_std_string(L, 3)) && (olua_is_std_string(L, 4)) && (olua_is_uint(L, 5))) {
            // void loadTextures(const std::string &normal, const std::string &selected, @optional const std::string &disabled, @optional cocos2d::ui::Widget::TextureResType texType)
            return _cocos2d_ui_Button_loadTextures1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::Button::loadTextures' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ui_Button_new(lua_State *L)
{
    olua_startinvoke(L);

    // Button()
    cocos2d::ui::Button *ret = (cocos2d::ui::Button *)new cocos2d::ui::Button();
    int num_ret = olua_push_cppobj(L, ret, "ccui.Button");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_Button_resetDisabledRender(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Button");

    // void resetDisabledRender()
    self->resetDisabledRender();

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Button_resetNormalRender(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Button");

    // void resetNormalRender()
    self->resetNormalRender();

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Button_resetPressedRender(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Button");

    // void resetPressedRender()
    self->resetPressedRender();

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Button_setCapInsets(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;
    cocos2d::Rect arg1;       /** capInsets */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Button");
    manual_olua_check_cocos2d_Rect(L, 2, &arg1);

    // void setCapInsets(const cocos2d::Rect &capInsets)
    self->setCapInsets(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Button_setCapInsetsDisabledRenderer(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;
    cocos2d::Rect arg1;       /** capInsets */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Button");
    manual_olua_check_cocos2d_Rect(L, 2, &arg1);

    // void setCapInsetsDisabledRenderer(const cocos2d::Rect &capInsets)
    self->setCapInsetsDisabledRenderer(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Button_setCapInsetsNormalRenderer(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;
    cocos2d::Rect arg1;       /** capInsets */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Button");
    manual_olua_check_cocos2d_Rect(L, 2, &arg1);

    // void setCapInsetsNormalRenderer(const cocos2d::Rect &capInsets)
    self->setCapInsetsNormalRenderer(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Button_setCapInsetsPressedRenderer(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;
    cocos2d::Rect arg1;       /** capInsets */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Button");
    manual_olua_check_cocos2d_Rect(L, 2, &arg1);

    // void setCapInsetsPressedRenderer(const cocos2d::Rect &capInsets)
    self->setCapInsetsPressedRenderer(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Button_setPressedActionEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;
    bool arg1 = false;       /** enabled */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Button");
    olua_check_bool(L, 2, &arg1);

    // void setPressedActionEnabled(bool enabled)
    self->setPressedActionEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Button_setScale9Enabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;
    bool arg1 = false;       /** enable */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Button");
    olua_check_bool(L, 2, &arg1);

    // void setScale9Enabled(bool enable)
    self->setScale9Enabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Button_setTitleAlignment1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;
    lua_Unsigned arg1 = 0;       /** hAlignment */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Button");
    olua_check_uint(L, 2, &arg1);

    // void setTitleAlignment(cocos2d::TextHAlignment hAlignment)
    self->setTitleAlignment((cocos2d::TextHAlignment)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Button_setTitleAlignment2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;
    lua_Unsigned arg1 = 0;       /** hAlignment */
    lua_Unsigned arg2 = 0;       /** vAlignment */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Button");
    olua_check_uint(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // void setTitleAlignment(cocos2d::TextHAlignment hAlignment, cocos2d::TextVAlignment vAlignment)
    self->setTitleAlignment((cocos2d::TextHAlignment)arg1, (cocos2d::TextVAlignment)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Button_setTitleAlignment(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_uint(L, 2))) {
            // void setTitleAlignment(cocos2d::TextHAlignment hAlignment)
            return _cocos2d_ui_Button_setTitleAlignment1(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_uint(L, 2)) && (olua_is_uint(L, 3))) {
            // void setTitleAlignment(cocos2d::TextHAlignment hAlignment, cocos2d::TextVAlignment vAlignment)
            return _cocos2d_ui_Button_setTitleAlignment2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::Button::setTitleAlignment' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ui_Button_setTitleColor(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;
    cocos2d::Color3B arg1;       /** color */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Button");
    manual_olua_check_cocos2d_Color3B(L, 2, &arg1);

    // void setTitleColor(const cocos2d::Color3B &color)
    self->setTitleColor(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Button_setTitleFontName(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;
    std::string arg1;       /** fontName */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Button");
    olua_check_std_string(L, 2, &arg1);

    // void setTitleFontName(const std::string &fontName)
    self->setTitleFontName(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Button_setTitleFontSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;
    lua_Number arg1 = 0;       /** size */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Button");
    olua_check_number(L, 2, &arg1);

    // void setTitleFontSize(float size)
    self->setTitleFontSize((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Button_setTitleLabel(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;
    cocos2d::Label *arg1 = nullptr;       /** label */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Button");
    olua_check_cppobj(L, 2, (void **)&arg1, "cc.Label");

    // void setTitleLabel(@addref(protectedChildren |) cocos2d::Label *label)
    self->setTitleLabel(arg1);

    // inject code after call
    olua_addref(L, 1, "protectedChildren", 2, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Button_setTitleText(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;
    std::string arg1;       /** text */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Button");
    olua_check_std_string(L, 2, &arg1);

    // void setTitleText(const std::string &text)
    self->setTitleText(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_Button_setZoomScale(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Button *self = nullptr;
    lua_Number arg1 = 0;       /** scale */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.Button");
    olua_check_number(L, 2, &arg1);

    // void setZoomScale(float scale)
    self->setZoomScale((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_ui_Button(lua_State *L)
{
    oluacls_class(L, "ccui.Button", "ccui.Widget");
    oluacls_func(L, "__move", _cocos2d_ui_Button___move);
    oluacls_func(L, "create", _cocos2d_ui_Button_create);
    oluacls_func(L, "createInstance", _cocos2d_ui_Button_createInstance);
    oluacls_func(L, "getCapInsetsDisabledRenderer", _cocos2d_ui_Button_getCapInsetsDisabledRenderer);
    oluacls_func(L, "getCapInsetsNormalRenderer", _cocos2d_ui_Button_getCapInsetsNormalRenderer);
    oluacls_func(L, "getCapInsetsPressedRenderer", _cocos2d_ui_Button_getCapInsetsPressedRenderer);
    oluacls_func(L, "getDisabledFile", _cocos2d_ui_Button_getDisabledFile);
    oluacls_func(L, "getNormalFile", _cocos2d_ui_Button_getNormalFile);
    oluacls_func(L, "getNormalTextureSize", _cocos2d_ui_Button_getNormalTextureSize);
    oluacls_func(L, "getPressedFile", _cocos2d_ui_Button_getPressedFile);
    oluacls_func(L, "getRendererClicked", _cocos2d_ui_Button_getRendererClicked);
    oluacls_func(L, "getRendererDisabled", _cocos2d_ui_Button_getRendererDisabled);
    oluacls_func(L, "getRendererNormal", _cocos2d_ui_Button_getRendererNormal);
    oluacls_func(L, "getTitleColor", _cocos2d_ui_Button_getTitleColor);
    oluacls_func(L, "getTitleFontName", _cocos2d_ui_Button_getTitleFontName);
    oluacls_func(L, "getTitleFontSize", _cocos2d_ui_Button_getTitleFontSize);
    oluacls_func(L, "getTitleLabel", _cocos2d_ui_Button_getTitleLabel);
    oluacls_func(L, "getTitleRenderer", _cocos2d_ui_Button_getTitleRenderer);
    oluacls_func(L, "getTitleText", _cocos2d_ui_Button_getTitleText);
    oluacls_func(L, "getZoomScale", _cocos2d_ui_Button_getZoomScale);
    oluacls_func(L, "init", _cocos2d_ui_Button_init);
    oluacls_func(L, "isScale9Enabled", _cocos2d_ui_Button_isScale9Enabled);
    oluacls_func(L, "loadTextureDisabled", _cocos2d_ui_Button_loadTextureDisabled);
    oluacls_func(L, "loadTextureNormal", _cocos2d_ui_Button_loadTextureNormal);
    oluacls_func(L, "loadTexturePressed", _cocos2d_ui_Button_loadTexturePressed);
    oluacls_func(L, "loadTextures", _cocos2d_ui_Button_loadTextures);
    oluacls_func(L, "new", _cocos2d_ui_Button_new);
    oluacls_func(L, "resetDisabledRender", _cocos2d_ui_Button_resetDisabledRender);
    oluacls_func(L, "resetNormalRender", _cocos2d_ui_Button_resetNormalRender);
    oluacls_func(L, "resetPressedRender", _cocos2d_ui_Button_resetPressedRender);
    oluacls_func(L, "setCapInsets", _cocos2d_ui_Button_setCapInsets);
    oluacls_func(L, "setCapInsetsDisabledRenderer", _cocos2d_ui_Button_setCapInsetsDisabledRenderer);
    oluacls_func(L, "setCapInsetsNormalRenderer", _cocos2d_ui_Button_setCapInsetsNormalRenderer);
    oluacls_func(L, "setCapInsetsPressedRenderer", _cocos2d_ui_Button_setCapInsetsPressedRenderer);
    oluacls_func(L, "setPressedActionEnabled", _cocos2d_ui_Button_setPressedActionEnabled);
    oluacls_func(L, "setScale9Enabled", _cocos2d_ui_Button_setScale9Enabled);
    oluacls_func(L, "setTitleAlignment", _cocos2d_ui_Button_setTitleAlignment);
    oluacls_func(L, "setTitleColor", _cocos2d_ui_Button_setTitleColor);
    oluacls_func(L, "setTitleFontName", _cocos2d_ui_Button_setTitleFontName);
    oluacls_func(L, "setTitleFontSize", _cocos2d_ui_Button_setTitleFontSize);
    oluacls_func(L, "setTitleLabel", _cocos2d_ui_Button_setTitleLabel);
    oluacls_func(L, "setTitleText", _cocos2d_ui_Button_setTitleText);
    oluacls_func(L, "setZoomScale", _cocos2d_ui_Button_setZoomScale);
    oluacls_prop(L, "capInsetsDisabledRenderer", _cocos2d_ui_Button_getCapInsetsDisabledRenderer, _cocos2d_ui_Button_setCapInsetsDisabledRenderer);
    oluacls_prop(L, "capInsetsNormalRenderer", _cocos2d_ui_Button_getCapInsetsNormalRenderer, _cocos2d_ui_Button_setCapInsetsNormalRenderer);
    oluacls_prop(L, "capInsetsPressedRenderer", _cocos2d_ui_Button_getCapInsetsPressedRenderer, _cocos2d_ui_Button_setCapInsetsPressedRenderer);
    oluacls_prop(L, "disabledFile", _cocos2d_ui_Button_getDisabledFile, nullptr);
    oluacls_prop(L, "normalFile", _cocos2d_ui_Button_getNormalFile, nullptr);
    oluacls_prop(L, "normalTextureSize", _cocos2d_ui_Button_getNormalTextureSize, nullptr);
    oluacls_prop(L, "pressedFile", _cocos2d_ui_Button_getPressedFile, nullptr);
    oluacls_prop(L, "rendererClicked", _cocos2d_ui_Button_getRendererClicked, nullptr);
    oluacls_prop(L, "rendererDisabled", _cocos2d_ui_Button_getRendererDisabled, nullptr);
    oluacls_prop(L, "rendererNormal", _cocos2d_ui_Button_getRendererNormal, nullptr);
    oluacls_prop(L, "scale9Enabled", _cocos2d_ui_Button_isScale9Enabled, _cocos2d_ui_Button_setScale9Enabled);
    oluacls_prop(L, "titleColor", _cocos2d_ui_Button_getTitleColor, _cocos2d_ui_Button_setTitleColor);
    oluacls_prop(L, "titleFontName", _cocos2d_ui_Button_getTitleFontName, _cocos2d_ui_Button_setTitleFontName);
    oluacls_prop(L, "titleFontSize", _cocos2d_ui_Button_getTitleFontSize, _cocos2d_ui_Button_setTitleFontSize);
    oluacls_prop(L, "titleLabel", _cocos2d_ui_Button_getTitleLabel, _cocos2d_ui_Button_setTitleLabel);
    oluacls_prop(L, "titleRenderer", _cocos2d_ui_Button_getTitleRenderer, nullptr);
    oluacls_prop(L, "titleText", _cocos2d_ui_Button_getTitleText, _cocos2d_ui_Button_setTitleText);
    oluacls_prop(L, "zoomScale", _cocos2d_ui_Button_getZoomScale, _cocos2d_ui_Button_setZoomScale);

    olua_registerluatype<cocos2d::ui::Button>(L, "ccui.Button");

    return 1;
}

static int luaopen_cocos2d_ui_CheckBox_EventType(lua_State *L)
{
    oluacls_class(L, "ccui.CheckBox.EventType", nullptr);
    oluacls_const_integer(L, "SELECTED", (lua_Integer)cocos2d::ui::CheckBox::EventType::SELECTED);
    oluacls_const_integer(L, "UNSELECTED", (lua_Integer)cocos2d::ui::CheckBox::EventType::UNSELECTED);

    olua_registerluatype<cocos2d::ui::CheckBox::EventType>(L, "ccui.CheckBox.EventType");

    return 1;
}

static int _cocos2d_ui_CheckBox___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::ui::CheckBox *)olua_toobj(L, 1, "ccui.CheckBox");
    olua_push_cppobj(L, self, "ccui.CheckBox");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_ui_CheckBox_addEventListener(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::CheckBox *self = nullptr;
    std::function<void(cocos2d::Ref *, cocos2d::ui::CheckBox::EventType)> arg1;       /** callback */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.CheckBox");

    if (olua_is_std_function(L, 2)) {
        void *callback_store_obj = (void *)self;
        std::string tag = "checkBoxCallback";
        std::string func = olua_setcallback(L, callback_store_obj, tag.c_str(), 2, OLUA_TAG_REPLACE);
        lua_State *MT = olua_mainthread();
        arg1 = [callback_store_obj, func, MT](cocos2d::Ref *arg1, cocos2d::ui::CheckBox::EventType arg2) {
            lua_State *L = olua_mainthread();

            if (MT == L) {
                int top = lua_gettop(L);
                olua_push_cppobj(L, arg1, "cc.Ref");
                olua_push_uint(L, (lua_Unsigned)arg2);

                olua_callback(L, callback_store_obj, func.c_str(), 2);

                lua_settop(L, top);
            }
        };
    } else {
        void *callback_store_obj = (void *)self;
        std::string tag = "checkBoxCallback";
        olua_removecallback(L, callback_store_obj, tag.c_str(), OLUA_TAG_SUBEQUAL);
        arg1 = nullptr;
    }

    // void addEventListener(@nullable const std::function<void(Ref*,CheckBox::EventType)>& callback)
    self->addEventListener(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_CheckBox_create1(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::ui::CheckBox *create()
    cocos2d::ui::CheckBox *ret = (cocos2d::ui::CheckBox *)cocos2d::ui::CheckBox::create();
    int num_ret = olua_push_cppobj(L, ret, "ccui.CheckBox");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_CheckBox_create2(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** backGround */
    std::string arg2;       /** backGroundSelected */
    std::string arg3;       /** cross */
    std::string arg4;       /** backGroundDisabled */
    std::string arg5;       /** frontCrossDisabled */
    lua_Unsigned arg6 = 0;       /** texType */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);
    olua_check_std_string(L, 3, &arg3);
    olua_check_std_string(L, 4, &arg4);
    olua_check_std_string(L, 5, &arg5);
    olua_check_uint(L, 6, &arg6);

    // static cocos2d::ui::CheckBox *create(const std::string &backGround, const std::string &backGroundSelected, const std::string &cross, const std::string &backGroundDisabled, const std::string &frontCrossDisabled, @optional cocos2d::ui::Widget::TextureResType texType)
    cocos2d::ui::CheckBox *ret = (cocos2d::ui::CheckBox *)cocos2d::ui::CheckBox::create(arg1, arg2, arg3, arg4, arg5, (cocos2d::ui::Widget::TextureResType)arg6);
    int num_ret = olua_push_cppobj(L, ret, "ccui.CheckBox");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_CheckBox_create3(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** backGround */
    std::string arg2;       /** cross */
    lua_Unsigned arg3 = 0;       /** texType */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);
    olua_check_uint(L, 3, &arg3);

    // static cocos2d::ui::CheckBox *create(const std::string &backGround, const std::string &cross, @optional cocos2d::ui::Widget::TextureResType texType)
    cocos2d::ui::CheckBox *ret = (cocos2d::ui::CheckBox *)cocos2d::ui::CheckBox::create(arg1, arg2, (cocos2d::ui::Widget::TextureResType)arg3);
    int num_ret = olua_push_cppobj(L, ret, "ccui.CheckBox");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_CheckBox_create4(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** backGround */
    std::string arg2;       /** backGroundSelected */
    std::string arg3;       /** cross */
    std::string arg4;       /** backGroundDisabled */
    std::string arg5;       /** frontCrossDisabled */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);
    olua_check_std_string(L, 3, &arg3);
    olua_check_std_string(L, 4, &arg4);
    olua_check_std_string(L, 5, &arg5);

    // static cocos2d::ui::CheckBox *create(const std::string &backGround, const std::string &backGroundSelected, const std::string &cross, const std::string &backGroundDisabled, const std::string &frontCrossDisabled, @optional cocos2d::ui::Widget::TextureResType texType)
    cocos2d::ui::CheckBox *ret = (cocos2d::ui::CheckBox *)cocos2d::ui::CheckBox::create(arg1, arg2, arg3, arg4, arg5);
    int num_ret = olua_push_cppobj(L, ret, "ccui.CheckBox");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_CheckBox_create5(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** backGround */
    std::string arg2;       /** cross */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);

    // static cocos2d::ui::CheckBox *create(const std::string &backGround, const std::string &cross, @optional cocos2d::ui::Widget::TextureResType texType)
    cocos2d::ui::CheckBox *ret = (cocos2d::ui::CheckBox *)cocos2d::ui::CheckBox::create(arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "ccui.CheckBox");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_CheckBox_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // static cocos2d::ui::CheckBox *create()
        return _cocos2d_ui_CheckBox_create1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 1)) && (olua_is_std_string(L, 2))) {
            // static cocos2d::ui::CheckBox *create(const std::string &backGround, const std::string &cross, @optional cocos2d::ui::Widget::TextureResType texType)
            return _cocos2d_ui_CheckBox_create5(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_std_string(L, 1)) && (olua_is_std_string(L, 2)) && (olua_is_uint(L, 3))) {
            // static cocos2d::ui::CheckBox *create(const std::string &backGround, const std::string &cross, @optional cocos2d::ui::Widget::TextureResType texType)
            return _cocos2d_ui_CheckBox_create3(L);
        // }
    }

    if (num_args == 5) {
        // if ((olua_is_std_string(L, 1)) && (olua_is_std_string(L, 2)) && (olua_is_std_string(L, 3)) && (olua_is_std_string(L, 4)) && (olua_is_std_string(L, 5))) {
            // static cocos2d::ui::CheckBox *create(const std::string &backGround, const std::string &backGroundSelected, const std::string &cross, const std::string &backGroundDisabled, const std::string &frontCrossDisabled, @optional cocos2d::ui::Widget::TextureResType texType)
            return _cocos2d_ui_CheckBox_create4(L);
        // }
    }

    if (num_args == 6) {
        // if ((olua_is_std_string(L, 1)) && (olua_is_std_string(L, 2)) && (olua_is_std_string(L, 3)) && (olua_is_std_string(L, 4)) && (olua_is_std_string(L, 5)) && (olua_is_uint(L, 6))) {
            // static cocos2d::ui::CheckBox *create(const std::string &backGround, const std::string &backGroundSelected, const std::string &cross, const std::string &backGroundDisabled, const std::string &frontCrossDisabled, @optional cocos2d::ui::Widget::TextureResType texType)
            return _cocos2d_ui_CheckBox_create2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::CheckBox::create' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ui_CheckBox_createInstance(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::Ref *createInstance()
    cocos2d::Ref *ret = (cocos2d::Ref *)cocos2d::ui::CheckBox::createInstance();
    int num_ret = olua_push_cppobj(L, ret, "cc.Ref");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_CheckBox_new(lua_State *L)
{
    olua_startinvoke(L);

    // CheckBox()
    cocos2d::ui::CheckBox *ret = (cocos2d::ui::CheckBox *)new cocos2d::ui::CheckBox();
    int num_ret = olua_push_cppobj(L, ret, "ccui.CheckBox");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_ui_CheckBox(lua_State *L)
{
    oluacls_class(L, "ccui.CheckBox", "ccui.AbstractCheckButton");
    oluacls_func(L, "__move", _cocos2d_ui_CheckBox___move);
    oluacls_func(L, "addEventListener", _cocos2d_ui_CheckBox_addEventListener);
    oluacls_func(L, "create", _cocos2d_ui_CheckBox_create);
    oluacls_func(L, "createInstance", _cocos2d_ui_CheckBox_createInstance);
    oluacls_func(L, "new", _cocos2d_ui_CheckBox_new);

    olua_registerluatype<cocos2d::ui::CheckBox>(L, "ccui.CheckBox");

    return 1;
}

static int luaopen_cocos2d_ui_RadioButton_EventType(lua_State *L)
{
    oluacls_class(L, "ccui.RadioButton.EventType", nullptr);
    oluacls_const_integer(L, "SELECTED", (lua_Integer)cocos2d::ui::RadioButton::EventType::SELECTED);
    oluacls_const_integer(L, "UNSELECTED", (lua_Integer)cocos2d::ui::RadioButton::EventType::UNSELECTED);

    olua_registerluatype<cocos2d::ui::RadioButton::EventType>(L, "ccui.RadioButton.EventType");

    return 1;
}

static int _cocos2d_ui_RadioButton___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::ui::RadioButton *)olua_toobj(L, 1, "ccui.RadioButton");
    olua_push_cppobj(L, self, "ccui.RadioButton");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_ui_RadioButton_addEventListener(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RadioButton *self = nullptr;
    std::function<void(cocos2d::ui::RadioButton *, cocos2d::ui::RadioButton::EventType)> arg1;       /** callback */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RadioButton");

    if (olua_is_std_function(L, 2)) {
        void *callback_store_obj = (void *)self;
        std::string tag = "radioButtonCallback";
        std::string func = olua_setcallback(L, callback_store_obj, tag.c_str(), 2, OLUA_TAG_REPLACE);
        lua_State *MT = olua_mainthread();
        arg1 = [callback_store_obj, func, MT](cocos2d::ui::RadioButton *arg1, cocos2d::ui::RadioButton::EventType arg2) {
            lua_State *L = olua_mainthread();

            if (MT == L) {
                int top = lua_gettop(L);
                olua_push_cppobj(L, arg1, "ccui.RadioButton");
                olua_push_uint(L, (lua_Unsigned)arg2);

                olua_callback(L, callback_store_obj, func.c_str(), 2);

                lua_settop(L, top);
            }
        };
    } else {
        void *callback_store_obj = (void *)self;
        std::string tag = "radioButtonCallback";
        olua_removecallback(L, callback_store_obj, tag.c_str(), OLUA_TAG_SUBEQUAL);
        arg1 = nullptr;
    }

    // void addEventListener(@nullable const std::function<void(RadioButton* radioButton, EventType)>& callback)
    self->addEventListener(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_RadioButton_create1(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::ui::RadioButton *create()
    cocos2d::ui::RadioButton *ret = (cocos2d::ui::RadioButton *)cocos2d::ui::RadioButton::create();
    int num_ret = olua_push_cppobj(L, ret, "ccui.RadioButton");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_RadioButton_create2(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** backGround */
    std::string arg2;       /** backGroundSelected */
    std::string arg3;       /** cross */
    std::string arg4;       /** backGroundDisabled */
    std::string arg5;       /** frontCrossDisabled */
    lua_Unsigned arg6 = 0;       /** texType */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);
    olua_check_std_string(L, 3, &arg3);
    olua_check_std_string(L, 4, &arg4);
    olua_check_std_string(L, 5, &arg5);
    olua_check_uint(L, 6, &arg6);

    // static cocos2d::ui::RadioButton *create(const std::string &backGround, const std::string &backGroundSelected, const std::string &cross, const std::string &backGroundDisabled, const std::string &frontCrossDisabled, @optional cocos2d::ui::Widget::TextureResType texType)
    cocos2d::ui::RadioButton *ret = (cocos2d::ui::RadioButton *)cocos2d::ui::RadioButton::create(arg1, arg2, arg3, arg4, arg5, (cocos2d::ui::Widget::TextureResType)arg6);
    int num_ret = olua_push_cppobj(L, ret, "ccui.RadioButton");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_RadioButton_create3(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** backGround */
    std::string arg2;       /** cross */
    lua_Unsigned arg3 = 0;       /** texType */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);
    olua_check_uint(L, 3, &arg3);

    // static cocos2d::ui::RadioButton *create(const std::string &backGround, const std::string &cross, @optional cocos2d::ui::Widget::TextureResType texType)
    cocos2d::ui::RadioButton *ret = (cocos2d::ui::RadioButton *)cocos2d::ui::RadioButton::create(arg1, arg2, (cocos2d::ui::Widget::TextureResType)arg3);
    int num_ret = olua_push_cppobj(L, ret, "ccui.RadioButton");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_RadioButton_create4(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** backGround */
    std::string arg2;       /** backGroundSelected */
    std::string arg3;       /** cross */
    std::string arg4;       /** backGroundDisabled */
    std::string arg5;       /** frontCrossDisabled */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);
    olua_check_std_string(L, 3, &arg3);
    olua_check_std_string(L, 4, &arg4);
    olua_check_std_string(L, 5, &arg5);

    // static cocos2d::ui::RadioButton *create(const std::string &backGround, const std::string &backGroundSelected, const std::string &cross, const std::string &backGroundDisabled, const std::string &frontCrossDisabled, @optional cocos2d::ui::Widget::TextureResType texType)
    cocos2d::ui::RadioButton *ret = (cocos2d::ui::RadioButton *)cocos2d::ui::RadioButton::create(arg1, arg2, arg3, arg4, arg5);
    int num_ret = olua_push_cppobj(L, ret, "ccui.RadioButton");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_RadioButton_create5(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** backGround */
    std::string arg2;       /** cross */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);

    // static cocos2d::ui::RadioButton *create(const std::string &backGround, const std::string &cross, @optional cocos2d::ui::Widget::TextureResType texType)
    cocos2d::ui::RadioButton *ret = (cocos2d::ui::RadioButton *)cocos2d::ui::RadioButton::create(arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "ccui.RadioButton");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_RadioButton_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // static cocos2d::ui::RadioButton *create()
        return _cocos2d_ui_RadioButton_create1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 1)) && (olua_is_std_string(L, 2))) {
            // static cocos2d::ui::RadioButton *create(const std::string &backGround, const std::string &cross, @optional cocos2d::ui::Widget::TextureResType texType)
            return _cocos2d_ui_RadioButton_create5(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_std_string(L, 1)) && (olua_is_std_string(L, 2)) && (olua_is_uint(L, 3))) {
            // static cocos2d::ui::RadioButton *create(const std::string &backGround, const std::string &cross, @optional cocos2d::ui::Widget::TextureResType texType)
            return _cocos2d_ui_RadioButton_create3(L);
        // }
    }

    if (num_args == 5) {
        // if ((olua_is_std_string(L, 1)) && (olua_is_std_string(L, 2)) && (olua_is_std_string(L, 3)) && (olua_is_std_string(L, 4)) && (olua_is_std_string(L, 5))) {
            // static cocos2d::ui::RadioButton *create(const std::string &backGround, const std::string &backGroundSelected, const std::string &cross, const std::string &backGroundDisabled, const std::string &frontCrossDisabled, @optional cocos2d::ui::Widget::TextureResType texType)
            return _cocos2d_ui_RadioButton_create4(L);
        // }
    }

    if (num_args == 6) {
        // if ((olua_is_std_string(L, 1)) && (olua_is_std_string(L, 2)) && (olua_is_std_string(L, 3)) && (olua_is_std_string(L, 4)) && (olua_is_std_string(L, 5)) && (olua_is_uint(L, 6))) {
            // static cocos2d::ui::RadioButton *create(const std::string &backGround, const std::string &backGroundSelected, const std::string &cross, const std::string &backGroundDisabled, const std::string &frontCrossDisabled, @optional cocos2d::ui::Widget::TextureResType texType)
            return _cocos2d_ui_RadioButton_create2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::RadioButton::create' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ui_RadioButton_createInstance(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::Ref *createInstance()
    cocos2d::Ref *ret = (cocos2d::Ref *)cocos2d::ui::RadioButton::createInstance();
    int num_ret = olua_push_cppobj(L, ret, "cc.Ref");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_RadioButton_new(lua_State *L)
{
    olua_startinvoke(L);

    // RadioButton()
    cocos2d::ui::RadioButton *ret = (cocos2d::ui::RadioButton *)new cocos2d::ui::RadioButton();
    int num_ret = olua_push_cppobj(L, ret, "ccui.RadioButton");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_ui_RadioButton(lua_State *L)
{
    oluacls_class(L, "ccui.RadioButton", "ccui.AbstractCheckButton");
    oluacls_func(L, "__move", _cocos2d_ui_RadioButton___move);
    oluacls_func(L, "addEventListener", _cocos2d_ui_RadioButton_addEventListener);
    oluacls_func(L, "create", _cocos2d_ui_RadioButton_create);
    oluacls_func(L, "createInstance", _cocos2d_ui_RadioButton_createInstance);
    oluacls_func(L, "new", _cocos2d_ui_RadioButton_new);

    olua_registerluatype<cocos2d::ui::RadioButton>(L, "ccui.RadioButton");

    return 1;
}

static int luaopen_cocos2d_ui_RadioButtonGroup_EventType(lua_State *L)
{
    oluacls_class(L, "ccui.RadioButtonGroup.EventType", nullptr);
    oluacls_const_integer(L, "SELECT_CHANGED", (lua_Integer)cocos2d::ui::RadioButtonGroup::EventType::SELECT_CHANGED);

    olua_registerluatype<cocos2d::ui::RadioButtonGroup::EventType>(L, "ccui.RadioButtonGroup.EventType");

    return 1;
}

static int _cocos2d_ui_RadioButtonGroup___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::ui::RadioButtonGroup *)olua_toobj(L, 1, "ccui.RadioButtonGroup");
    olua_push_cppobj(L, self, "ccui.RadioButtonGroup");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_ui_RadioButtonGroup_addEventListener(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RadioButtonGroup *self = nullptr;
    std::function<void(cocos2d::ui::RadioButton *, int, cocos2d::ui::RadioButtonGroup::EventType)> arg1;       /** callback */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RadioButtonGroup");

    if (olua_is_std_function(L, 2)) {
        void *callback_store_obj = (void *)self;
        std::string tag = "radioButtonCallback";
        std::string func = olua_setcallback(L, callback_store_obj, tag.c_str(), 2, OLUA_TAG_REPLACE);
        lua_State *MT = olua_mainthread();
        arg1 = [callback_store_obj, func, MT](cocos2d::ui::RadioButton *arg1, int arg2, cocos2d::ui::RadioButtonGroup::EventType arg3) {
            lua_State *L = olua_mainthread();

            if (MT == L) {
                int top = lua_gettop(L);
                olua_push_cppobj(L, arg1, "ccui.RadioButton");
                olua_push_int(L, (lua_Integer)arg2);
                olua_push_uint(L, (lua_Unsigned)arg3);

                olua_callback(L, callback_store_obj, func.c_str(), 3);

                lua_settop(L, top);
            }
        };
    } else {
        void *callback_store_obj = (void *)self;
        std::string tag = "radioButtonCallback";
        olua_removecallback(L, callback_store_obj, tag.c_str(), OLUA_TAG_SUBEQUAL);
        arg1 = nullptr;
    }

    // void addEventListener(@nullable const std::function<void(RadioButton* radioButton, int index, EventType)>& callback)
    self->addEventListener(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_RadioButtonGroup_addRadioButton(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RadioButtonGroup *self = nullptr;
    cocos2d::ui::RadioButton *arg1 = nullptr;       /** radioButton */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RadioButtonGroup");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccui.RadioButton");

    // void addRadioButton(cocos2d::ui::RadioButton *radioButton)
    self->addRadioButton(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_RadioButtonGroup_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::ui::RadioButtonGroup *create()
    cocos2d::ui::RadioButtonGroup *ret = (cocos2d::ui::RadioButtonGroup *)cocos2d::ui::RadioButtonGroup::create();
    int num_ret = olua_push_cppobj(L, ret, "ccui.RadioButtonGroup");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_RadioButtonGroup_getNumberOfRadioButtons(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RadioButtonGroup *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RadioButtonGroup");

    // ssize_t getNumberOfRadioButtons()
    ssize_t ret = (ssize_t)self->getNumberOfRadioButtons();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_RadioButtonGroup_getRadioButtonByIndex(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RadioButtonGroup *self = nullptr;
    lua_Integer arg1 = 0;       /** index */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RadioButtonGroup");
    olua_check_int(L, 2, &arg1);

    // cocos2d::ui::RadioButton *getRadioButtonByIndex(int index)
    cocos2d::ui::RadioButton *ret = (cocos2d::ui::RadioButton *)self->getRadioButtonByIndex((int)arg1);
    int num_ret = olua_push_cppobj(L, ret, "ccui.RadioButton");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_RadioButtonGroup_getSelectedButtonIndex(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RadioButtonGroup *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RadioButtonGroup");

    // int getSelectedButtonIndex()
    int ret = (int)self->getSelectedButtonIndex();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_RadioButtonGroup_isAllowedNoSelection(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RadioButtonGroup *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RadioButtonGroup");

    // bool isAllowedNoSelection()
    bool ret = (bool)self->isAllowedNoSelection();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_RadioButtonGroup_new(lua_State *L)
{
    olua_startinvoke(L);

    // RadioButtonGroup()
    cocos2d::ui::RadioButtonGroup *ret = (cocos2d::ui::RadioButtonGroup *)new cocos2d::ui::RadioButtonGroup();
    int num_ret = olua_push_cppobj(L, ret, "ccui.RadioButtonGroup");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_RadioButtonGroup_removeAllRadioButtons(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RadioButtonGroup *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RadioButtonGroup");

    // void removeAllRadioButtons()
    self->removeAllRadioButtons();

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_RadioButtonGroup_removeRadioButton(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RadioButtonGroup *self = nullptr;
    cocos2d::ui::RadioButton *arg1 = nullptr;       /** radioButton */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RadioButtonGroup");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccui.RadioButton");

    // void removeRadioButton(cocos2d::ui::RadioButton *radioButton)
    self->removeRadioButton(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_RadioButtonGroup_setAllowedNoSelection(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RadioButtonGroup *self = nullptr;
    bool arg1 = false;       /** allowedNoSelection */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RadioButtonGroup");
    olua_check_bool(L, 2, &arg1);

    // void setAllowedNoSelection(bool allowedNoSelection)
    self->setAllowedNoSelection(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_RadioButtonGroup_setSelectedButton1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RadioButtonGroup *self = nullptr;
    lua_Integer arg1 = 0;       /** index */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RadioButtonGroup");
    olua_check_int(L, 2, &arg1);

    // void setSelectedButton(int index)
    self->setSelectedButton((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_RadioButtonGroup_setSelectedButton2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RadioButtonGroup *self = nullptr;
    cocos2d::ui::RadioButton *arg1 = nullptr;       /** radioButton */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RadioButtonGroup");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccui.RadioButton");

    // void setSelectedButton(cocos2d::ui::RadioButton *radioButton)
    self->setSelectedButton(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_RadioButtonGroup_setSelectedButton(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        if ((olua_is_int(L, 2))) {
            // void setSelectedButton(int index)
            return _cocos2d_ui_RadioButtonGroup_setSelectedButton1(L);
        }

        // if ((olua_is_cppobj(L, 2, "ccui.RadioButton"))) {
            // void setSelectedButton(cocos2d::ui::RadioButton *radioButton)
            return _cocos2d_ui_RadioButtonGroup_setSelectedButton2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::RadioButtonGroup::setSelectedButton' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ui_RadioButtonGroup_setSelectedButtonWithoutEvent1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RadioButtonGroup *self = nullptr;
    lua_Integer arg1 = 0;       /** index */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RadioButtonGroup");
    olua_check_int(L, 2, &arg1);

    // void setSelectedButtonWithoutEvent(int index)
    self->setSelectedButtonWithoutEvent((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_RadioButtonGroup_setSelectedButtonWithoutEvent2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::RadioButtonGroup *self = nullptr;
    cocos2d::ui::RadioButton *arg1 = nullptr;       /** radioButton */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.RadioButtonGroup");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccui.RadioButton");

    // void setSelectedButtonWithoutEvent(cocos2d::ui::RadioButton *radioButton)
    self->setSelectedButtonWithoutEvent(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_RadioButtonGroup_setSelectedButtonWithoutEvent(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        if ((olua_is_int(L, 2))) {
            // void setSelectedButtonWithoutEvent(int index)
            return _cocos2d_ui_RadioButtonGroup_setSelectedButtonWithoutEvent1(L);
        }

        // if ((olua_is_cppobj(L, 2, "ccui.RadioButton"))) {
            // void setSelectedButtonWithoutEvent(cocos2d::ui::RadioButton *radioButton)
            return _cocos2d_ui_RadioButtonGroup_setSelectedButtonWithoutEvent2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::RadioButtonGroup::setSelectedButtonWithoutEvent' not support '%d' arguments", num_args);

    return 0;
}

static int luaopen_cocos2d_ui_RadioButtonGroup(lua_State *L)
{
    oluacls_class(L, "ccui.RadioButtonGroup", "ccui.Widget");
    oluacls_func(L, "__move", _cocos2d_ui_RadioButtonGroup___move);
    oluacls_func(L, "addEventListener", _cocos2d_ui_RadioButtonGroup_addEventListener);
    oluacls_func(L, "addRadioButton", _cocos2d_ui_RadioButtonGroup_addRadioButton);
    oluacls_func(L, "create", _cocos2d_ui_RadioButtonGroup_create);
    oluacls_func(L, "getNumberOfRadioButtons", _cocos2d_ui_RadioButtonGroup_getNumberOfRadioButtons);
    oluacls_func(L, "getRadioButtonByIndex", _cocos2d_ui_RadioButtonGroup_getRadioButtonByIndex);
    oluacls_func(L, "getSelectedButtonIndex", _cocos2d_ui_RadioButtonGroup_getSelectedButtonIndex);
    oluacls_func(L, "isAllowedNoSelection", _cocos2d_ui_RadioButtonGroup_isAllowedNoSelection);
    oluacls_func(L, "new", _cocos2d_ui_RadioButtonGroup_new);
    oluacls_func(L, "removeAllRadioButtons", _cocos2d_ui_RadioButtonGroup_removeAllRadioButtons);
    oluacls_func(L, "removeRadioButton", _cocos2d_ui_RadioButtonGroup_removeRadioButton);
    oluacls_func(L, "setAllowedNoSelection", _cocos2d_ui_RadioButtonGroup_setAllowedNoSelection);
    oluacls_func(L, "setSelectedButton", _cocos2d_ui_RadioButtonGroup_setSelectedButton);
    oluacls_func(L, "setSelectedButtonWithoutEvent", _cocos2d_ui_RadioButtonGroup_setSelectedButtonWithoutEvent);
    oluacls_prop(L, "allowedNoSelection", _cocos2d_ui_RadioButtonGroup_isAllowedNoSelection, _cocos2d_ui_RadioButtonGroup_setAllowedNoSelection);
    oluacls_prop(L, "numberOfRadioButtons", _cocos2d_ui_RadioButtonGroup_getNumberOfRadioButtons, nullptr);
    oluacls_prop(L, "selectedButtonIndex", _cocos2d_ui_RadioButtonGroup_getSelectedButtonIndex, nullptr);

    olua_registerluatype<cocos2d::ui::RadioButtonGroup>(L, "ccui.RadioButtonGroup");

    return 1;
}

static int _cocos2d_ui_ImageView___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::ui::ImageView *)olua_toobj(L, 1, "ccui.ImageView");
    olua_push_cppobj(L, self, "ccui.ImageView");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_ui_ImageView_create1(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::ui::ImageView *create()
    cocos2d::ui::ImageView *ret = (cocos2d::ui::ImageView *)cocos2d::ui::ImageView::create();
    int num_ret = olua_push_cppobj(L, ret, "ccui.ImageView");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_ImageView_create2(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** imageFileName */
    lua_Unsigned arg2 = 0;       /** texType */

    olua_check_std_string(L, 1, &arg1);
    olua_check_uint(L, 2, &arg2);

    // static cocos2d::ui::ImageView *create(const std::string &imageFileName, @optional cocos2d::ui::Widget::TextureResType texType)
    cocos2d::ui::ImageView *ret = (cocos2d::ui::ImageView *)cocos2d::ui::ImageView::create(arg1, (cocos2d::ui::Widget::TextureResType)arg2);
    int num_ret = olua_push_cppobj(L, ret, "ccui.ImageView");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_ImageView_create3(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** imageFileName */

    olua_check_std_string(L, 1, &arg1);

    // static cocos2d::ui::ImageView *create(const std::string &imageFileName, @optional cocos2d::ui::Widget::TextureResType texType)
    cocos2d::ui::ImageView *ret = (cocos2d::ui::ImageView *)cocos2d::ui::ImageView::create(arg1);
    int num_ret = olua_push_cppobj(L, ret, "ccui.ImageView");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_ImageView_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // static cocos2d::ui::ImageView *create()
        return _cocos2d_ui_ImageView_create1(L);
    }

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 1))) {
            // static cocos2d::ui::ImageView *create(const std::string &imageFileName, @optional cocos2d::ui::Widget::TextureResType texType)
            return _cocos2d_ui_ImageView_create3(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 1)) && (olua_is_uint(L, 2))) {
            // static cocos2d::ui::ImageView *create(const std::string &imageFileName, @optional cocos2d::ui::Widget::TextureResType texType)
            return _cocos2d_ui_ImageView_create2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::ImageView::create' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ui_ImageView_createInstance(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::Ref *createInstance()
    cocos2d::Ref *ret = (cocos2d::Ref *)cocos2d::ui::ImageView::createInstance();
    int num_ret = olua_push_cppobj(L, ret, "cc.Ref");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_ImageView_getBlendFunc(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ImageView *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ImageView");

    // const cocos2d::BlendFunc &getBlendFunc()
    const cocos2d::BlendFunc &ret = (const cocos2d::BlendFunc &)self->getBlendFunc();
    int num_ret = auto_olua_push_cocos2d_BlendFunc(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_ImageView_getCapInsets(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ImageView *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ImageView");

    // const cocos2d::Rect &getCapInsets()
    const cocos2d::Rect &ret = (const cocos2d::Rect &)self->getCapInsets();
    int num_ret = manual_olua_push_cocos2d_Rect(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_ImageView_getRenderFile(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ImageView *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ImageView");

    // cocos2d::ResourceData getRenderFile()
    cocos2d::ResourceData ret = (cocos2d::ResourceData)self->getRenderFile();
    int num_ret = auto_olua_push_cocos2d_ResourceData(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_ImageView_init1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ImageView *self = nullptr;
    std::string arg1;       /** imageFileName */
    lua_Unsigned arg2 = 0;       /** texType */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ImageView");
    olua_check_std_string(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // bool init(const std::string &imageFileName, @optional cocos2d::ui::Widget::TextureResType texType)
    bool ret = (bool)self->init(arg1, (cocos2d::ui::Widget::TextureResType)arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_ImageView_init2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ImageView *self = nullptr;
    std::string arg1;       /** imageFileName */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ImageView");
    olua_check_std_string(L, 2, &arg1);

    // bool init(const std::string &imageFileName, @optional cocos2d::ui::Widget::TextureResType texType)
    bool ret = (bool)self->init(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_ImageView_init(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 2))) {
            // bool init(const std::string &imageFileName, @optional cocos2d::ui::Widget::TextureResType texType)
            return _cocos2d_ui_ImageView_init2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_uint(L, 3))) {
            // bool init(const std::string &imageFileName, @optional cocos2d::ui::Widget::TextureResType texType)
            return _cocos2d_ui_ImageView_init1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::ImageView::init' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ui_ImageView_isScale9Enabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ImageView *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ImageView");

    // bool isScale9Enabled()
    bool ret = (bool)self->isScale9Enabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_ImageView_loadTexture1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ImageView *self = nullptr;
    std::string arg1;       /** fileName */
    lua_Unsigned arg2 = 0;       /** texType */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ImageView");
    olua_check_std_string(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // void loadTexture(const std::string &fileName, @optional cocos2d::ui::Widget::TextureResType texType)
    self->loadTexture(arg1, (cocos2d::ui::Widget::TextureResType)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_ImageView_loadTexture2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ImageView *self = nullptr;
    std::string arg1;       /** fileName */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ImageView");
    olua_check_std_string(L, 2, &arg1);

    // void loadTexture(const std::string &fileName, @optional cocos2d::ui::Widget::TextureResType texType)
    self->loadTexture(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_ImageView_loadTexture(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 2))) {
            // void loadTexture(const std::string &fileName, @optional cocos2d::ui::Widget::TextureResType texType)
            return _cocos2d_ui_ImageView_loadTexture2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_uint(L, 3))) {
            // void loadTexture(const std::string &fileName, @optional cocos2d::ui::Widget::TextureResType texType)
            return _cocos2d_ui_ImageView_loadTexture1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::ImageView::loadTexture' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ui_ImageView_new(lua_State *L)
{
    olua_startinvoke(L);

    // ImageView()
    cocos2d::ui::ImageView *ret = (cocos2d::ui::ImageView *)new cocos2d::ui::ImageView();
    int num_ret = olua_push_cppobj(L, ret, "ccui.ImageView");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_ImageView_setBlendFunc(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ImageView *self = nullptr;
    cocos2d::BlendFunc arg1;       /** blendFunc */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ImageView");
    auto_olua_check_cocos2d_BlendFunc(L, 2, &arg1);

    // void setBlendFunc(const cocos2d::BlendFunc &blendFunc)
    self->setBlendFunc(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_ImageView_setCapInsets(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ImageView *self = nullptr;
    cocos2d::Rect arg1;       /** capInsets */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ImageView");
    manual_olua_check_cocos2d_Rect(L, 2, &arg1);

    // void setCapInsets(const cocos2d::Rect &capInsets)
    self->setCapInsets(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_ImageView_setScale9Enabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ImageView *self = nullptr;
    bool arg1 = false;       /** enabled */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ImageView");
    olua_check_bool(L, 2, &arg1);

    // void setScale9Enabled(bool enabled)
    self->setScale9Enabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_ImageView_setTextureRect(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::ImageView *self = nullptr;
    cocos2d::Rect arg1;       /** rect */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.ImageView");
    manual_olua_check_cocos2d_Rect(L, 2, &arg1);

    // void setTextureRect(const cocos2d::Rect &rect)
    self->setTextureRect(arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_ui_ImageView(lua_State *L)
{
    oluacls_class(L, "ccui.ImageView", "ccui.Widget");
    oluacls_func(L, "__move", _cocos2d_ui_ImageView___move);
    oluacls_func(L, "create", _cocos2d_ui_ImageView_create);
    oluacls_func(L, "createInstance", _cocos2d_ui_ImageView_createInstance);
    oluacls_func(L, "getBlendFunc", _cocos2d_ui_ImageView_getBlendFunc);
    oluacls_func(L, "getCapInsets", _cocos2d_ui_ImageView_getCapInsets);
    oluacls_func(L, "getRenderFile", _cocos2d_ui_ImageView_getRenderFile);
    oluacls_func(L, "init", _cocos2d_ui_ImageView_init);
    oluacls_func(L, "isScale9Enabled", _cocos2d_ui_ImageView_isScale9Enabled);
    oluacls_func(L, "loadTexture", _cocos2d_ui_ImageView_loadTexture);
    oluacls_func(L, "new", _cocos2d_ui_ImageView_new);
    oluacls_func(L, "setBlendFunc", _cocos2d_ui_ImageView_setBlendFunc);
    oluacls_func(L, "setCapInsets", _cocos2d_ui_ImageView_setCapInsets);
    oluacls_func(L, "setScale9Enabled", _cocos2d_ui_ImageView_setScale9Enabled);
    oluacls_func(L, "setTextureRect", _cocos2d_ui_ImageView_setTextureRect);
    oluacls_prop(L, "blendFunc", _cocos2d_ui_ImageView_getBlendFunc, _cocos2d_ui_ImageView_setBlendFunc);
    oluacls_prop(L, "capInsets", _cocos2d_ui_ImageView_getCapInsets, _cocos2d_ui_ImageView_setCapInsets);
    oluacls_prop(L, "renderFile", _cocos2d_ui_ImageView_getRenderFile, nullptr);
    oluacls_prop(L, "scale9Enabled", _cocos2d_ui_ImageView_isScale9Enabled, _cocos2d_ui_ImageView_setScale9Enabled);

    olua_registerluatype<cocos2d::ui::ImageView>(L, "ccui.ImageView");

    return 1;
}

static int luaopen_cocos2d_ui_EditBoxDelegate_EditBoxEndAction(lua_State *L)
{
    oluacls_class(L, "ccui.EditBoxDelegate.EditBoxEndAction", nullptr);
    oluacls_const_integer(L, "RETURN", (lua_Integer)cocos2d::ui::EditBoxDelegate::EditBoxEndAction::RETURN);
    oluacls_const_integer(L, "TAB_TO_NEXT", (lua_Integer)cocos2d::ui::EditBoxDelegate::EditBoxEndAction::TAB_TO_NEXT);
    oluacls_const_integer(L, "TAB_TO_PREVIOUS", (lua_Integer)cocos2d::ui::EditBoxDelegate::EditBoxEndAction::TAB_TO_PREVIOUS);
    oluacls_const_integer(L, "UNKNOWN", (lua_Integer)cocos2d::ui::EditBoxDelegate::EditBoxEndAction::UNKNOWN);

    olua_registerluatype<cocos2d::ui::EditBoxDelegate::EditBoxEndAction>(L, "ccui.EditBoxDelegate.EditBoxEndAction");

    return 1;
}

static int _cocos2d_ui_EditBoxDelegate___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::ui::EditBoxDelegate *)olua_toobj(L, 1, "ccui.EditBoxDelegate");
    olua_push_cppobj(L, self, "ccui.EditBoxDelegate");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_ui_EditBoxDelegate_editBoxEditingDidBegin(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBoxDelegate *self = nullptr;
    cocos2d::ui::EditBox *arg1 = nullptr;       /**  */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.EditBoxDelegate");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccui.EditBox");

    // void editBoxEditingDidBegin(cocos2d::ui::EditBox *)
    self->editBoxEditingDidBegin(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_EditBoxDelegate_editBoxEditingDidEndWithAction(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBoxDelegate *self = nullptr;
    cocos2d::ui::EditBox *arg1 = nullptr;       /**  */
    lua_Unsigned arg2 = 0;       /**  */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.EditBoxDelegate");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccui.EditBox");
    olua_check_uint(L, 3, &arg2);

    // void editBoxEditingDidEndWithAction(cocos2d::ui::EditBox *, cocos2d::ui::EditBoxDelegate::EditBoxEndAction )
    self->editBoxEditingDidEndWithAction(arg1, (cocos2d::ui::EditBoxDelegate::EditBoxEndAction)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_EditBoxDelegate_editBoxReturn(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBoxDelegate *self = nullptr;
    cocos2d::ui::EditBox *arg1 = nullptr;       /** editBox */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.EditBoxDelegate");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccui.EditBox");

    // void editBoxReturn(cocos2d::ui::EditBox *editBox)
    self->editBoxReturn(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_EditBoxDelegate_editBoxTextChanged(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBoxDelegate *self = nullptr;
    cocos2d::ui::EditBox *arg1 = nullptr;       /**  */
    std::string arg2;       /**  */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.EditBoxDelegate");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccui.EditBox");
    olua_check_std_string(L, 3, &arg2);

    // void editBoxTextChanged(cocos2d::ui::EditBox *, const std::string &)
    self->editBoxTextChanged(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_ui_EditBoxDelegate(lua_State *L)
{
    oluacls_class(L, "ccui.EditBoxDelegate", nullptr);
    oluacls_func(L, "__move", _cocos2d_ui_EditBoxDelegate___move);
    oluacls_func(L, "editBoxEditingDidBegin", _cocos2d_ui_EditBoxDelegate_editBoxEditingDidBegin);
    oluacls_func(L, "editBoxEditingDidEndWithAction", _cocos2d_ui_EditBoxDelegate_editBoxEditingDidEndWithAction);
    oluacls_func(L, "editBoxReturn", _cocos2d_ui_EditBoxDelegate_editBoxReturn);
    oluacls_func(L, "editBoxTextChanged", _cocos2d_ui_EditBoxDelegate_editBoxTextChanged);

    olua_registerluatype<cocos2d::ui::EditBoxDelegate>(L, "ccui.EditBoxDelegate");

    return 1;
}

static int _cocos2d_ui_LuaEditBoxDelegate___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::ui::LuaEditBoxDelegate *)olua_toobj(L, 1, "ccui.LuaEditBoxDelegate");
    lua_pushstring(L, ".ownership");
    olua_getvariable(L, 1);
    if (lua_toboolean(L, -1) && self) {
        olua_setuserdata(L, 1, nullptr);
        delete self;
    }

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_LuaEditBoxDelegate___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::ui::LuaEditBoxDelegate *)olua_toobj(L, 1, "ccui.LuaEditBoxDelegate");
    olua_push_cppobj(L, self, "ccui.LuaEditBoxDelegate");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_ui_LuaEditBoxDelegate_new(lua_State *L)
{
    olua_startinvoke(L);

    // LuaEditBoxDelegate()
    cocos2d::ui::LuaEditBoxDelegate *ret = (cocos2d::ui::LuaEditBoxDelegate *)new cocos2d::ui::LuaEditBoxDelegate();
    int num_ret = olua_push_cppobj(L, ret, "ccui.LuaEditBoxDelegate");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_LuaEditBoxDelegate_get_onEditingDidBegin(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LuaEditBoxDelegate *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.LuaEditBoxDelegate");

    void *callback_store_obj = (void *)self;
    std::string tag = "onEditingDidBegin";
    olua_getcallback(L, callback_store_obj, tag.c_str(), OLUA_TAG_SUBEQUAL);

    // @nullable @local std::function<void (EditBox *)> onEditingDidBegin
    std::function<void(cocos2d::ui::EditBox *)> ret = (std::function<void(cocos2d::ui::EditBox *)>)self->onEditingDidBegin;
    int num_ret = olua_push_std_function(L, (std::function<void(cocos2d::ui::EditBox *)>)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_LuaEditBoxDelegate_set_onEditingDidBegin(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LuaEditBoxDelegate *self = nullptr;
    std::function<void(cocos2d::ui::EditBox *)> arg1;       /** onEditingDidBegin */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.LuaEditBoxDelegate");

    if (olua_is_std_function(L, 2)) {
        void *callback_store_obj = (void *)self;
        std::string tag = "onEditingDidBegin";
        std::string func = olua_setcallback(L, callback_store_obj, tag.c_str(), 2, OLUA_TAG_REPLACE);
        lua_State *MT = olua_mainthread();
        arg1 = [callback_store_obj, func, MT](cocos2d::ui::EditBox *arg1) {
            lua_State *L = olua_mainthread();

            if (MT == L) {
                int top = lua_gettop(L);
                size_t last = olua_push_objpool(L);
                olua_enable_objpool(L);
                olua_push_cppobj(L, arg1, "ccui.EditBox");
                olua_disable_objpool(L);

                olua_callback(L, callback_store_obj, func.c_str(), 1);

                //pop stack value
                olua_pop_objpool(L, last);
                lua_settop(L, top);
            }
        };
    } else {
        void *callback_store_obj = (void *)self;
        std::string tag = "onEditingDidBegin";
        olua_removecallback(L, callback_store_obj, tag.c_str(), OLUA_TAG_SUBEQUAL);
        arg1 = nullptr;
    }

    // @nullable @local std::function<void (EditBox *)> onEditingDidBegin
    self->onEditingDidBegin = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_LuaEditBoxDelegate_get_onEditingDidEndWithAction(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LuaEditBoxDelegate *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.LuaEditBoxDelegate");

    void *callback_store_obj = (void *)self;
    std::string tag = "onEditingDidEndWithAction";
    olua_getcallback(L, callback_store_obj, tag.c_str(), OLUA_TAG_SUBEQUAL);

    // @nullable @local std::function<void (EditBox *, EditBoxDelegate::EditBoxEndAction)> onEditingDidEndWithAction
    std::function<void(cocos2d::ui::EditBox *, cocos2d::ui::EditBoxDelegate::EditBoxEndAction)> ret = (std::function<void(cocos2d::ui::EditBox *, cocos2d::ui::EditBoxDelegate::EditBoxEndAction)>)self->onEditingDidEndWithAction;
    int num_ret = olua_push_std_function(L, (std::function<void(cocos2d::ui::EditBox *, cocos2d::ui::EditBoxDelegate::EditBoxEndAction)>)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_LuaEditBoxDelegate_set_onEditingDidEndWithAction(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LuaEditBoxDelegate *self = nullptr;
    std::function<void(cocos2d::ui::EditBox *, cocos2d::ui::EditBoxDelegate::EditBoxEndAction)> arg1;       /** onEditingDidEndWithAction */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.LuaEditBoxDelegate");

    if (olua_is_std_function(L, 2)) {
        void *callback_store_obj = (void *)self;
        std::string tag = "onEditingDidEndWithAction";
        std::string func = olua_setcallback(L, callback_store_obj, tag.c_str(), 2, OLUA_TAG_REPLACE);
        lua_State *MT = olua_mainthread();
        arg1 = [callback_store_obj, func, MT](cocos2d::ui::EditBox *arg1, cocos2d::ui::EditBoxDelegate::EditBoxEndAction arg2) {
            lua_State *L = olua_mainthread();

            if (MT == L) {
                int top = lua_gettop(L);
                size_t last = olua_push_objpool(L);
                olua_enable_objpool(L);
                olua_push_cppobj(L, arg1, "ccui.EditBox");
                olua_push_uint(L, (lua_Unsigned)arg2);
                olua_disable_objpool(L);

                olua_callback(L, callback_store_obj, func.c_str(), 2);

                //pop stack value
                olua_pop_objpool(L, last);
                lua_settop(L, top);
            }
        };
    } else {
        void *callback_store_obj = (void *)self;
        std::string tag = "onEditingDidEndWithAction";
        olua_removecallback(L, callback_store_obj, tag.c_str(), OLUA_TAG_SUBEQUAL);
        arg1 = nullptr;
    }

    // @nullable @local std::function<void (EditBox *, EditBoxDelegate::EditBoxEndAction)> onEditingDidEndWithAction
    self->onEditingDidEndWithAction = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_LuaEditBoxDelegate_get_onReturn(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LuaEditBoxDelegate *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.LuaEditBoxDelegate");

    void *callback_store_obj = (void *)self;
    std::string tag = "onReturn";
    olua_getcallback(L, callback_store_obj, tag.c_str(), OLUA_TAG_SUBEQUAL);

    // @nullable @local std::function<void (EditBox *)> onReturn
    std::function<void(cocos2d::ui::EditBox *)> ret = (std::function<void(cocos2d::ui::EditBox *)>)self->onReturn;
    int num_ret = olua_push_std_function(L, (std::function<void(cocos2d::ui::EditBox *)>)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_LuaEditBoxDelegate_set_onReturn(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LuaEditBoxDelegate *self = nullptr;
    std::function<void(cocos2d::ui::EditBox *)> arg1;       /** onReturn */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.LuaEditBoxDelegate");

    if (olua_is_std_function(L, 2)) {
        void *callback_store_obj = (void *)self;
        std::string tag = "onReturn";
        std::string func = olua_setcallback(L, callback_store_obj, tag.c_str(), 2, OLUA_TAG_REPLACE);
        lua_State *MT = olua_mainthread();
        arg1 = [callback_store_obj, func, MT](cocos2d::ui::EditBox *arg1) {
            lua_State *L = olua_mainthread();

            if (MT == L) {
                int top = lua_gettop(L);
                size_t last = olua_push_objpool(L);
                olua_enable_objpool(L);
                olua_push_cppobj(L, arg1, "ccui.EditBox");
                olua_disable_objpool(L);

                olua_callback(L, callback_store_obj, func.c_str(), 1);

                //pop stack value
                olua_pop_objpool(L, last);
                lua_settop(L, top);
            }
        };
    } else {
        void *callback_store_obj = (void *)self;
        std::string tag = "onReturn";
        olua_removecallback(L, callback_store_obj, tag.c_str(), OLUA_TAG_SUBEQUAL);
        arg1 = nullptr;
    }

    // @nullable @local std::function<void (EditBox *)> onReturn
    self->onReturn = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_LuaEditBoxDelegate_get_onTextChanged(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LuaEditBoxDelegate *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.LuaEditBoxDelegate");

    void *callback_store_obj = (void *)self;
    std::string tag = "onTextChanged";
    olua_getcallback(L, callback_store_obj, tag.c_str(), OLUA_TAG_SUBEQUAL);

    // @nullable @local std::function<void (EditBox *, const std::string &)> onTextChanged
    std::function<void(cocos2d::ui::EditBox *, const std::string &)> ret = (std::function<void(cocos2d::ui::EditBox *, const std::string &)>)self->onTextChanged;
    int num_ret = olua_push_std_function(L, (std::function<void(cocos2d::ui::EditBox *, const std::string &)>)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_LuaEditBoxDelegate_set_onTextChanged(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::LuaEditBoxDelegate *self = nullptr;
    std::function<void(cocos2d::ui::EditBox *, const std::string &)> arg1;       /** onTextChanged */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.LuaEditBoxDelegate");

    if (olua_is_std_function(L, 2)) {
        void *callback_store_obj = (void *)self;
        std::string tag = "onTextChanged";
        std::string func = olua_setcallback(L, callback_store_obj, tag.c_str(), 2, OLUA_TAG_REPLACE);
        lua_State *MT = olua_mainthread();
        arg1 = [callback_store_obj, func, MT](cocos2d::ui::EditBox *arg1, const std::string &arg2) {
            lua_State *L = olua_mainthread();

            if (MT == L) {
                int top = lua_gettop(L);
                size_t last = olua_push_objpool(L);
                olua_enable_objpool(L);
                olua_push_cppobj(L, arg1, "ccui.EditBox");
                olua_push_std_string(L, arg2);
                olua_disable_objpool(L);

                olua_callback(L, callback_store_obj, func.c_str(), 2);

                //pop stack value
                olua_pop_objpool(L, last);
                lua_settop(L, top);
            }
        };
    } else {
        void *callback_store_obj = (void *)self;
        std::string tag = "onTextChanged";
        olua_removecallback(L, callback_store_obj, tag.c_str(), OLUA_TAG_SUBEQUAL);
        arg1 = nullptr;
    }

    // @nullable @local std::function<void (EditBox *, const std::string &)> onTextChanged
    self->onTextChanged = arg1;

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_ui_LuaEditBoxDelegate(lua_State *L)
{
    oluacls_class(L, "ccui.LuaEditBoxDelegate", "ccui.EditBoxDelegate");
    oluacls_func(L, "__gc", _cocos2d_ui_LuaEditBoxDelegate___gc);
    oluacls_func(L, "__move", _cocos2d_ui_LuaEditBoxDelegate___move);
    oluacls_func(L, "new", _cocos2d_ui_LuaEditBoxDelegate_new);
    oluacls_prop(L, "onEditingDidBegin", _cocos2d_ui_LuaEditBoxDelegate_get_onEditingDidBegin, _cocos2d_ui_LuaEditBoxDelegate_set_onEditingDidBegin);
    oluacls_prop(L, "onEditingDidEndWithAction", _cocos2d_ui_LuaEditBoxDelegate_get_onEditingDidEndWithAction, _cocos2d_ui_LuaEditBoxDelegate_set_onEditingDidEndWithAction);
    oluacls_prop(L, "onReturn", _cocos2d_ui_LuaEditBoxDelegate_get_onReturn, _cocos2d_ui_LuaEditBoxDelegate_set_onReturn);
    oluacls_prop(L, "onTextChanged", _cocos2d_ui_LuaEditBoxDelegate_get_onTextChanged, _cocos2d_ui_LuaEditBoxDelegate_set_onTextChanged);

    olua_registerluatype<cocos2d::ui::LuaEditBoxDelegate>(L, "ccui.LuaEditBoxDelegate");

    return 1;
}

static int luaopen_cocos2d_ui_EditBox_KeyboardReturnType(lua_State *L)
{
    oluacls_class(L, "ccui.EditBox.KeyboardReturnType", nullptr);
    oluacls_const_integer(L, "DEFAULT", (lua_Integer)cocos2d::ui::EditBox::KeyboardReturnType::DEFAULT);
    oluacls_const_integer(L, "DONE", (lua_Integer)cocos2d::ui::EditBox::KeyboardReturnType::DONE);
    oluacls_const_integer(L, "GO", (lua_Integer)cocos2d::ui::EditBox::KeyboardReturnType::GO);
    oluacls_const_integer(L, "NEXT", (lua_Integer)cocos2d::ui::EditBox::KeyboardReturnType::NEXT);
    oluacls_const_integer(L, "SEARCH", (lua_Integer)cocos2d::ui::EditBox::KeyboardReturnType::SEARCH);
    oluacls_const_integer(L, "SEND", (lua_Integer)cocos2d::ui::EditBox::KeyboardReturnType::SEND);

    olua_registerluatype<cocos2d::ui::EditBox::KeyboardReturnType>(L, "ccui.EditBox.KeyboardReturnType");

    return 1;
}

static int luaopen_cocos2d_ui_EditBox_InputMode(lua_State *L)
{
    oluacls_class(L, "ccui.EditBox.InputMode", nullptr);
    oluacls_const_integer(L, "ANY", (lua_Integer)cocos2d::ui::EditBox::InputMode::ANY);
    oluacls_const_integer(L, "DECIMAL", (lua_Integer)cocos2d::ui::EditBox::InputMode::DECIMAL);
    oluacls_const_integer(L, "EMAIL_ADDRESS", (lua_Integer)cocos2d::ui::EditBox::InputMode::EMAIL_ADDRESS);
    oluacls_const_integer(L, "NUMERIC", (lua_Integer)cocos2d::ui::EditBox::InputMode::NUMERIC);
    oluacls_const_integer(L, "PHONE_NUMBER", (lua_Integer)cocos2d::ui::EditBox::InputMode::PHONE_NUMBER);
    oluacls_const_integer(L, "SINGLE_LINE", (lua_Integer)cocos2d::ui::EditBox::InputMode::SINGLE_LINE);
    oluacls_const_integer(L, "URL", (lua_Integer)cocos2d::ui::EditBox::InputMode::URL);

    olua_registerluatype<cocos2d::ui::EditBox::InputMode>(L, "ccui.EditBox.InputMode");

    return 1;
}

static int luaopen_cocos2d_ui_EditBox_InputFlag(lua_State *L)
{
    oluacls_class(L, "ccui.EditBox.InputFlag", nullptr);
    oluacls_const_integer(L, "INITIAL_CAPS_ALL_CHARACTERS", (lua_Integer)cocos2d::ui::EditBox::InputFlag::INITIAL_CAPS_ALL_CHARACTERS);
    oluacls_const_integer(L, "INITIAL_CAPS_SENTENCE", (lua_Integer)cocos2d::ui::EditBox::InputFlag::INITIAL_CAPS_SENTENCE);
    oluacls_const_integer(L, "INITIAL_CAPS_WORD", (lua_Integer)cocos2d::ui::EditBox::InputFlag::INITIAL_CAPS_WORD);
    oluacls_const_integer(L, "LOWERCASE_ALL_CHARACTERS", (lua_Integer)cocos2d::ui::EditBox::InputFlag::LOWERCASE_ALL_CHARACTERS);
    oluacls_const_integer(L, "PASSWORD", (lua_Integer)cocos2d::ui::EditBox::InputFlag::PASSWORD);
    oluacls_const_integer(L, "SENSITIVE", (lua_Integer)cocos2d::ui::EditBox::InputFlag::SENSITIVE);

    olua_registerluatype<cocos2d::ui::EditBox::InputFlag>(L, "ccui.EditBox.InputFlag");

    return 1;
}

static int _cocos2d_ui_EditBox___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::ui::EditBox *)olua_toobj(L, 1, "ccui.EditBox");
    olua_push_cppobj(L, self, "ccui.EditBox");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_ui_EditBox_create1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size arg1;       /** size */
    cocos2d::ui::Scale9Sprite *arg2 = nullptr;       /** normalSprite */
    cocos2d::ui::Scale9Sprite *arg3 = nullptr;       /** pressedSprite */
    cocos2d::ui::Scale9Sprite *arg4 = nullptr;       /** disabledSprite */

    auto_olua_check_cocos2d_Size(L, 1, &arg1);
    olua_check_cppobj(L, 2, (void **)&arg2, "ccui.Scale9Sprite");
    olua_check_cppobj(L, 3, (void **)&arg3, "ccui.Scale9Sprite");
    olua_check_cppobj(L, 4, (void **)&arg4, "ccui.Scale9Sprite");

    // static cocos2d::ui::EditBox *create(const cocos2d::Size &size, cocos2d::ui::Scale9Sprite *normalSprite, @optional cocos2d::ui::Scale9Sprite *pressedSprite, @optional cocos2d::ui::Scale9Sprite *disabledSprite)
    cocos2d::ui::EditBox *ret = (cocos2d::ui::EditBox *)cocos2d::ui::EditBox::create(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_cppobj(L, ret, "ccui.EditBox");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_EditBox_create2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size arg1;       /** size */
    std::string arg2;       /** normalImage */
    lua_Unsigned arg3 = 0;       /** texType */

    auto_olua_check_cocos2d_Size(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);
    olua_check_uint(L, 3, &arg3);

    // static cocos2d::ui::EditBox *create(const cocos2d::Size &size, const std::string &normalImage, cocos2d::ui::Widget::TextureResType texType)
    cocos2d::ui::EditBox *ret = (cocos2d::ui::EditBox *)cocos2d::ui::EditBox::create(arg1, arg2, (cocos2d::ui::Widget::TextureResType)arg3);
    int num_ret = olua_push_cppobj(L, ret, "ccui.EditBox");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_EditBox_create3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size arg1;       /** size */
    std::string arg2;       /** normalImage */
    std::string arg3;       /** pressedImage */
    std::string arg4;       /** disabledImage */
    lua_Unsigned arg5 = 0;       /** texType */

    auto_olua_check_cocos2d_Size(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);
    olua_check_std_string(L, 3, &arg3);
    olua_check_std_string(L, 4, &arg4);
    olua_check_uint(L, 5, &arg5);

    // static cocos2d::ui::EditBox *create(const cocos2d::Size &size, const std::string &normalImage, @optional const std::string &pressedImage, @optional const std::string &disabledImage, @optional cocos2d::ui::Widget::TextureResType texType)
    cocos2d::ui::EditBox *ret = (cocos2d::ui::EditBox *)cocos2d::ui::EditBox::create(arg1, arg2, arg3, arg4, (cocos2d::ui::Widget::TextureResType)arg5);
    int num_ret = olua_push_cppobj(L, ret, "ccui.EditBox");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_EditBox_create4(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size arg1;       /** size */
    cocos2d::ui::Scale9Sprite *arg2 = nullptr;       /** normalSprite */

    auto_olua_check_cocos2d_Size(L, 1, &arg1);
    olua_check_cppobj(L, 2, (void **)&arg2, "ccui.Scale9Sprite");

    // static cocos2d::ui::EditBox *create(const cocos2d::Size &size, cocos2d::ui::Scale9Sprite *normalSprite, @optional cocos2d::ui::Scale9Sprite *pressedSprite, @optional cocos2d::ui::Scale9Sprite *disabledSprite)
    cocos2d::ui::EditBox *ret = (cocos2d::ui::EditBox *)cocos2d::ui::EditBox::create(arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "ccui.EditBox");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_EditBox_create5(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size arg1;       /** size */
    cocos2d::ui::Scale9Sprite *arg2 = nullptr;       /** normalSprite */
    cocos2d::ui::Scale9Sprite *arg3 = nullptr;       /** pressedSprite */

    auto_olua_check_cocos2d_Size(L, 1, &arg1);
    olua_check_cppobj(L, 2, (void **)&arg2, "ccui.Scale9Sprite");
    olua_check_cppobj(L, 3, (void **)&arg3, "ccui.Scale9Sprite");

    // static cocos2d::ui::EditBox *create(const cocos2d::Size &size, cocos2d::ui::Scale9Sprite *normalSprite, @optional cocos2d::ui::Scale9Sprite *pressedSprite, @optional cocos2d::ui::Scale9Sprite *disabledSprite)
    cocos2d::ui::EditBox *ret = (cocos2d::ui::EditBox *)cocos2d::ui::EditBox::create(arg1, arg2, arg3);
    int num_ret = olua_push_cppobj(L, ret, "ccui.EditBox");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_EditBox_create6(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size arg1;       /** size */
    std::string arg2;       /** normalImage */

    auto_olua_check_cocos2d_Size(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);

    // static cocos2d::ui::EditBox *create(const cocos2d::Size &size, const std::string &normalImage, @optional const std::string &pressedImage, @optional const std::string &disabledImage, @optional cocos2d::ui::Widget::TextureResType texType)
    cocos2d::ui::EditBox *ret = (cocos2d::ui::EditBox *)cocos2d::ui::EditBox::create(arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "ccui.EditBox");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_EditBox_create7(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size arg1;       /** size */
    std::string arg2;       /** normalImage */
    std::string arg3;       /** pressedImage */

    auto_olua_check_cocos2d_Size(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);
    olua_check_std_string(L, 3, &arg3);

    // static cocos2d::ui::EditBox *create(const cocos2d::Size &size, const std::string &normalImage, @optional const std::string &pressedImage, @optional const std::string &disabledImage, @optional cocos2d::ui::Widget::TextureResType texType)
    cocos2d::ui::EditBox *ret = (cocos2d::ui::EditBox *)cocos2d::ui::EditBox::create(arg1, arg2, arg3);
    int num_ret = olua_push_cppobj(L, ret, "ccui.EditBox");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_EditBox_create8(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size arg1;       /** size */
    std::string arg2;       /** normalImage */
    std::string arg3;       /** pressedImage */
    std::string arg4;       /** disabledImage */

    auto_olua_check_cocos2d_Size(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);
    olua_check_std_string(L, 3, &arg3);
    olua_check_std_string(L, 4, &arg4);

    // static cocos2d::ui::EditBox *create(const cocos2d::Size &size, const std::string &normalImage, @optional const std::string &pressedImage, @optional const std::string &disabledImage, @optional cocos2d::ui::Widget::TextureResType texType)
    cocos2d::ui::EditBox *ret = (cocos2d::ui::EditBox *)cocos2d::ui::EditBox::create(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_cppobj(L, ret, "ccui.EditBox");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_EditBox_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        if ((auto_olua_is_cocos2d_Size(L, 1)) && (olua_is_cppobj(L, 2, "ccui.Scale9Sprite"))) {
            // static cocos2d::ui::EditBox *create(const cocos2d::Size &size, cocos2d::ui::Scale9Sprite *normalSprite, @optional cocos2d::ui::Scale9Sprite *pressedSprite, @optional cocos2d::ui::Scale9Sprite *disabledSprite)
            return _cocos2d_ui_EditBox_create4(L);
        }

        // if ((auto_olua_is_cocos2d_Size(L, 1)) && (olua_is_std_string(L, 2))) {
            // static cocos2d::ui::EditBox *create(const cocos2d::Size &size, const std::string &normalImage, @optional const std::string &pressedImage, @optional const std::string &disabledImage, @optional cocos2d::ui::Widget::TextureResType texType)
            return _cocos2d_ui_EditBox_create6(L);
        // }
    }

    if (num_args == 3) {
        if ((auto_olua_is_cocos2d_Size(L, 1)) && (olua_is_std_string(L, 2)) && (olua_is_uint(L, 3))) {
            // static cocos2d::ui::EditBox *create(const cocos2d::Size &size, const std::string &normalImage, cocos2d::ui::Widget::TextureResType texType)
            return _cocos2d_ui_EditBox_create2(L);
        }

        if ((auto_olua_is_cocos2d_Size(L, 1)) && (olua_is_cppobj(L, 2, "ccui.Scale9Sprite")) && (olua_is_cppobj(L, 3, "ccui.Scale9Sprite"))) {
            // static cocos2d::ui::EditBox *create(const cocos2d::Size &size, cocos2d::ui::Scale9Sprite *normalSprite, @optional cocos2d::ui::Scale9Sprite *pressedSprite, @optional cocos2d::ui::Scale9Sprite *disabledSprite)
            return _cocos2d_ui_EditBox_create5(L);
        }

        // if ((auto_olua_is_cocos2d_Size(L, 1)) && (olua_is_std_string(L, 2)) && (olua_is_std_string(L, 3))) {
            // static cocos2d::ui::EditBox *create(const cocos2d::Size &size, const std::string &normalImage, @optional const std::string &pressedImage, @optional const std::string &disabledImage, @optional cocos2d::ui::Widget::TextureResType texType)
            return _cocos2d_ui_EditBox_create7(L);
        // }
    }

    if (num_args == 4) {
        if ((auto_olua_is_cocos2d_Size(L, 1)) && (olua_is_cppobj(L, 2, "ccui.Scale9Sprite")) && (olua_is_cppobj(L, 3, "ccui.Scale9Sprite")) && (olua_is_cppobj(L, 4, "ccui.Scale9Sprite"))) {
            // static cocos2d::ui::EditBox *create(const cocos2d::Size &size, cocos2d::ui::Scale9Sprite *normalSprite, @optional cocos2d::ui::Scale9Sprite *pressedSprite, @optional cocos2d::ui::Scale9Sprite *disabledSprite)
            return _cocos2d_ui_EditBox_create1(L);
        }

        // if ((auto_olua_is_cocos2d_Size(L, 1)) && (olua_is_std_string(L, 2)) && (olua_is_std_string(L, 3)) && (olua_is_std_string(L, 4))) {
            // static cocos2d::ui::EditBox *create(const cocos2d::Size &size, const std::string &normalImage, @optional const std::string &pressedImage, @optional const std::string &disabledImage, @optional cocos2d::ui::Widget::TextureResType texType)
            return _cocos2d_ui_EditBox_create8(L);
        // }
    }

    if (num_args == 5) {
        // if ((auto_olua_is_cocos2d_Size(L, 1)) && (olua_is_std_string(L, 2)) && (olua_is_std_string(L, 3)) && (olua_is_std_string(L, 4)) && (olua_is_uint(L, 5))) {
            // static cocos2d::ui::EditBox *create(const cocos2d::Size &size, const std::string &normalImage, @optional const std::string &pressedImage, @optional const std::string &disabledImage, @optional cocos2d::ui::Widget::TextureResType texType)
            return _cocos2d_ui_EditBox_create3(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::EditBox::create' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ui_EditBox_getCapInsetsDisabledRenderer(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.EditBox");

    // const cocos2d::Rect &getCapInsetsDisabledRenderer()
    const cocos2d::Rect &ret = (const cocos2d::Rect &)self->getCapInsetsDisabledRenderer();
    int num_ret = manual_olua_push_cocos2d_Rect(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_EditBox_getCapInsetsNormalRenderer(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.EditBox");

    // const cocos2d::Rect &getCapInsetsNormalRenderer()
    const cocos2d::Rect &ret = (const cocos2d::Rect &)self->getCapInsetsNormalRenderer();
    int num_ret = manual_olua_push_cocos2d_Rect(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_EditBox_getCapInsetsPressedRenderer(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.EditBox");

    // const cocos2d::Rect &getCapInsetsPressedRenderer()
    const cocos2d::Rect &ret = (const cocos2d::Rect &)self->getCapInsetsPressedRenderer();
    int num_ret = manual_olua_push_cocos2d_Rect(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_EditBox_getDelegate(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.EditBox");

    // @addref(delegate ^) cocos2d::ui::EditBoxDelegate *getDelegate()
    cocos2d::ui::EditBoxDelegate *ret = (cocos2d::ui::EditBoxDelegate *)self->getDelegate();
    int num_ret = olua_push_cppobj(L, ret, "ccui.EditBoxDelegate");

    // inject code after call
    olua_addref(L, 1, "delegate", -1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_EditBox_getFontColor(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.EditBox");

    // const cocos2d::Color4B &getFontColor()
    const cocos2d::Color4B &ret = (const cocos2d::Color4B &)self->getFontColor();
    int num_ret = manual_olua_push_cocos2d_Color4B(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_EditBox_getFontName(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.EditBox");

    // const char *getFontName()
    const char *ret = (const char *)self->getFontName();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_EditBox_getFontSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.EditBox");

    // int getFontSize()
    int ret = (int)self->getFontSize();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_EditBox_getInputFlag(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.EditBox");

    // cocos2d::ui::EditBox::InputFlag getInputFlag()
    cocos2d::ui::EditBox::InputFlag ret = (cocos2d::ui::EditBox::InputFlag)self->getInputFlag();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_EditBox_getInputMode(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.EditBox");

    // cocos2d::ui::EditBox::InputMode getInputMode()
    cocos2d::ui::EditBox::InputMode ret = (cocos2d::ui::EditBox::InputMode)self->getInputMode();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_EditBox_getMaxLength(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.EditBox");

    // int getMaxLength()
    int ret = (int)self->getMaxLength();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_EditBox_getPlaceHolder(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.EditBox");

    // const char *getPlaceHolder()
    const char *ret = (const char *)self->getPlaceHolder();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_EditBox_getPlaceholderFontColor(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.EditBox");

    // const cocos2d::Color4B &getPlaceholderFontColor()
    const cocos2d::Color4B &ret = (const cocos2d::Color4B &)self->getPlaceholderFontColor();
    int num_ret = manual_olua_push_cocos2d_Color4B(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_EditBox_getPlaceholderFontName(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.EditBox");

    // const char *getPlaceholderFontName()
    const char *ret = (const char *)self->getPlaceholderFontName();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_EditBox_getPlaceholderFontSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.EditBox");

    // int getPlaceholderFontSize()
    int ret = (int)self->getPlaceholderFontSize();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_EditBox_getReturnType(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.EditBox");

    // cocos2d::ui::EditBox::KeyboardReturnType getReturnType()
    cocos2d::ui::EditBox::KeyboardReturnType ret = (cocos2d::ui::EditBox::KeyboardReturnType)self->getReturnType();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_EditBox_getText(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.EditBox");

    // const char *getText()
    const char *ret = (const char *)self->getText();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_EditBox_getTextHorizontalAlignment(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.EditBox");

    // cocos2d::TextHAlignment getTextHorizontalAlignment()
    cocos2d::TextHAlignment ret = (cocos2d::TextHAlignment)self->getTextHorizontalAlignment();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_EditBox_initWithSizeAndBackgroundSprite1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    cocos2d::Size arg1;       /** size */
    std::string arg2;       /** normal9SpriteBg */
    lua_Unsigned arg3 = 0;       /** texType */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.EditBox");
    auto_olua_check_cocos2d_Size(L, 2, &arg1);
    olua_check_std_string(L, 3, &arg2);
    olua_check_uint(L, 4, &arg3);

    // bool initWithSizeAndBackgroundSprite(const cocos2d::Size &size, const std::string &normal9SpriteBg, @optional cocos2d::ui::Widget::TextureResType texType)
    bool ret = (bool)self->initWithSizeAndBackgroundSprite(arg1, arg2, (cocos2d::ui::Widget::TextureResType)arg3);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_EditBox_initWithSizeAndBackgroundSprite2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    cocos2d::Size arg1;       /** size */
    cocos2d::ui::Scale9Sprite *arg2 = nullptr;       /** normal9SpriteBg */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.EditBox");
    auto_olua_check_cocos2d_Size(L, 2, &arg1);
    olua_check_cppobj(L, 3, (void **)&arg2, "ccui.Scale9Sprite");

    // bool initWithSizeAndBackgroundSprite(const cocos2d::Size &size, cocos2d::ui::Scale9Sprite *normal9SpriteBg)
    bool ret = (bool)self->initWithSizeAndBackgroundSprite(arg1, arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_EditBox_initWithSizeAndBackgroundSprite3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    cocos2d::Size arg1;       /** size */
    cocos2d::ui::Scale9Sprite *arg2 = nullptr;       /** normalSprite */
    cocos2d::ui::Scale9Sprite *arg3 = nullptr;       /** pressedSprite */
    cocos2d::ui::Scale9Sprite *arg4 = nullptr;       /** disabledSprite */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.EditBox");
    auto_olua_check_cocos2d_Size(L, 2, &arg1);
    olua_check_cppobj(L, 3, (void **)&arg2, "ccui.Scale9Sprite");
    olua_check_cppobj(L, 4, (void **)&arg3, "ccui.Scale9Sprite");
    olua_check_cppobj(L, 5, (void **)&arg4, "ccui.Scale9Sprite");

    // bool initWithSizeAndBackgroundSprite(const cocos2d::Size &size, cocos2d::ui::Scale9Sprite *normalSprite, cocos2d::ui::Scale9Sprite *pressedSprite, cocos2d::ui::Scale9Sprite *disabledSprite)
    bool ret = (bool)self->initWithSizeAndBackgroundSprite(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_EditBox_initWithSizeAndBackgroundSprite4(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    cocos2d::Size arg1;       /** size */
    std::string arg2;       /** normal9SpriteBg */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.EditBox");
    auto_olua_check_cocos2d_Size(L, 2, &arg1);
    olua_check_std_string(L, 3, &arg2);

    // bool initWithSizeAndBackgroundSprite(const cocos2d::Size &size, const std::string &normal9SpriteBg, @optional cocos2d::ui::Widget::TextureResType texType)
    bool ret = (bool)self->initWithSizeAndBackgroundSprite(arg1, arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_EditBox_initWithSizeAndBackgroundSprite(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 2) {
        if ((auto_olua_is_cocos2d_Size(L, 2)) && (olua_is_cppobj(L, 3, "ccui.Scale9Sprite"))) {
            // bool initWithSizeAndBackgroundSprite(const cocos2d::Size &size, cocos2d::ui::Scale9Sprite *normal9SpriteBg)
            return _cocos2d_ui_EditBox_initWithSizeAndBackgroundSprite2(L);
        }

        // if ((auto_olua_is_cocos2d_Size(L, 2)) && (olua_is_std_string(L, 3))) {
            // bool initWithSizeAndBackgroundSprite(const cocos2d::Size &size, const std::string &normal9SpriteBg, @optional cocos2d::ui::Widget::TextureResType texType)
            return _cocos2d_ui_EditBox_initWithSizeAndBackgroundSprite4(L);
        // }
    }

    if (num_args == 3) {
        // if ((auto_olua_is_cocos2d_Size(L, 2)) && (olua_is_std_string(L, 3)) && (olua_is_uint(L, 4))) {
            // bool initWithSizeAndBackgroundSprite(const cocos2d::Size &size, const std::string &normal9SpriteBg, @optional cocos2d::ui::Widget::TextureResType texType)
            return _cocos2d_ui_EditBox_initWithSizeAndBackgroundSprite1(L);
        // }
    }

    if (num_args == 4) {
        // if ((auto_olua_is_cocos2d_Size(L, 2)) && (olua_is_cppobj(L, 3, "ccui.Scale9Sprite")) && (olua_is_cppobj(L, 4, "ccui.Scale9Sprite")) && (olua_is_cppobj(L, 5, "ccui.Scale9Sprite"))) {
            // bool initWithSizeAndBackgroundSprite(const cocos2d::Size &size, cocos2d::ui::Scale9Sprite *normalSprite, cocos2d::ui::Scale9Sprite *pressedSprite, cocos2d::ui::Scale9Sprite *disabledSprite)
            return _cocos2d_ui_EditBox_initWithSizeAndBackgroundSprite3(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::EditBox::initWithSizeAndBackgroundSprite' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ui_EditBox_initWithSizeAndTexture1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    cocos2d::Size arg1;       /** size */
    std::string arg2;       /** normalImage */
    std::string arg3;       /** pressedImage */
    std::string arg4;       /** disabledImage */
    lua_Unsigned arg5 = 0;       /** texType */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.EditBox");
    auto_olua_check_cocos2d_Size(L, 2, &arg1);
    olua_check_std_string(L, 3, &arg2);
    olua_check_std_string(L, 4, &arg3);
    olua_check_std_string(L, 5, &arg4);
    olua_check_uint(L, 6, &arg5);

    // bool initWithSizeAndTexture(const cocos2d::Size &size, const std::string &normalImage, @optional const std::string &pressedImage, @optional const std::string &disabledImage, @optional cocos2d::ui::Widget::TextureResType texType)
    bool ret = (bool)self->initWithSizeAndTexture(arg1, arg2, arg3, arg4, (cocos2d::ui::Widget::TextureResType)arg5);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_EditBox_initWithSizeAndTexture2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    cocos2d::Size arg1;       /** size */
    std::string arg2;       /** normalImage */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.EditBox");
    auto_olua_check_cocos2d_Size(L, 2, &arg1);
    olua_check_std_string(L, 3, &arg2);

    // bool initWithSizeAndTexture(const cocos2d::Size &size, const std::string &normalImage, @optional const std::string &pressedImage, @optional const std::string &disabledImage, @optional cocos2d::ui::Widget::TextureResType texType)
    bool ret = (bool)self->initWithSizeAndTexture(arg1, arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_EditBox_initWithSizeAndTexture3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    cocos2d::Size arg1;       /** size */
    std::string arg2;       /** normalImage */
    std::string arg3;       /** pressedImage */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.EditBox");
    auto_olua_check_cocos2d_Size(L, 2, &arg1);
    olua_check_std_string(L, 3, &arg2);
    olua_check_std_string(L, 4, &arg3);

    // bool initWithSizeAndTexture(const cocos2d::Size &size, const std::string &normalImage, @optional const std::string &pressedImage, @optional const std::string &disabledImage, @optional cocos2d::ui::Widget::TextureResType texType)
    bool ret = (bool)self->initWithSizeAndTexture(arg1, arg2, arg3);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_EditBox_initWithSizeAndTexture4(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    cocos2d::Size arg1;       /** size */
    std::string arg2;       /** normalImage */
    std::string arg3;       /** pressedImage */
    std::string arg4;       /** disabledImage */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.EditBox");
    auto_olua_check_cocos2d_Size(L, 2, &arg1);
    olua_check_std_string(L, 3, &arg2);
    olua_check_std_string(L, 4, &arg3);
    olua_check_std_string(L, 5, &arg4);

    // bool initWithSizeAndTexture(const cocos2d::Size &size, const std::string &normalImage, @optional const std::string &pressedImage, @optional const std::string &disabledImage, @optional cocos2d::ui::Widget::TextureResType texType)
    bool ret = (bool)self->initWithSizeAndTexture(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_EditBox_initWithSizeAndTexture(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 2) {
        // if ((auto_olua_is_cocos2d_Size(L, 2)) && (olua_is_std_string(L, 3))) {
            // bool initWithSizeAndTexture(const cocos2d::Size &size, const std::string &normalImage, @optional const std::string &pressedImage, @optional const std::string &disabledImage, @optional cocos2d::ui::Widget::TextureResType texType)
            return _cocos2d_ui_EditBox_initWithSizeAndTexture2(L);
        // }
    }

    if (num_args == 3) {
        // if ((auto_olua_is_cocos2d_Size(L, 2)) && (olua_is_std_string(L, 3)) && (olua_is_std_string(L, 4))) {
            // bool initWithSizeAndTexture(const cocos2d::Size &size, const std::string &normalImage, @optional const std::string &pressedImage, @optional const std::string &disabledImage, @optional cocos2d::ui::Widget::TextureResType texType)
            return _cocos2d_ui_EditBox_initWithSizeAndTexture3(L);
        // }
    }

    if (num_args == 4) {
        // if ((auto_olua_is_cocos2d_Size(L, 2)) && (olua_is_std_string(L, 3)) && (olua_is_std_string(L, 4)) && (olua_is_std_string(L, 5))) {
            // bool initWithSizeAndTexture(const cocos2d::Size &size, const std::string &normalImage, @optional const std::string &pressedImage, @optional const std::string &disabledImage, @optional cocos2d::ui::Widget::TextureResType texType)
            return _cocos2d_ui_EditBox_initWithSizeAndTexture4(L);
        // }
    }

    if (num_args == 5) {
        // if ((auto_olua_is_cocos2d_Size(L, 2)) && (olua_is_std_string(L, 3)) && (olua_is_std_string(L, 4)) && (olua_is_std_string(L, 5)) && (olua_is_uint(L, 6))) {
            // bool initWithSizeAndTexture(const cocos2d::Size &size, const std::string &normalImage, @optional const std::string &pressedImage, @optional const std::string &disabledImage, @optional cocos2d::ui::Widget::TextureResType texType)
            return _cocos2d_ui_EditBox_initWithSizeAndTexture1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::EditBox::initWithSizeAndTexture' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ui_EditBox_loadTextureDisabled1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    std::string arg1;       /** disabled */
    lua_Unsigned arg2 = 0;       /** texType */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.EditBox");
    olua_check_std_string(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // void loadTextureDisabled(const std::string &disabled, @optional cocos2d::ui::Widget::TextureResType texType)
    self->loadTextureDisabled(arg1, (cocos2d::ui::Widget::TextureResType)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_EditBox_loadTextureDisabled2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    std::string arg1;       /** disabled */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.EditBox");
    olua_check_std_string(L, 2, &arg1);

    // void loadTextureDisabled(const std::string &disabled, @optional cocos2d::ui::Widget::TextureResType texType)
    self->loadTextureDisabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_EditBox_loadTextureDisabled(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 2))) {
            // void loadTextureDisabled(const std::string &disabled, @optional cocos2d::ui::Widget::TextureResType texType)
            return _cocos2d_ui_EditBox_loadTextureDisabled2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_uint(L, 3))) {
            // void loadTextureDisabled(const std::string &disabled, @optional cocos2d::ui::Widget::TextureResType texType)
            return _cocos2d_ui_EditBox_loadTextureDisabled1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::EditBox::loadTextureDisabled' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ui_EditBox_loadTextureNormal1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    std::string arg1;       /** normal */
    lua_Unsigned arg2 = 0;       /** texType */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.EditBox");
    olua_check_std_string(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // void loadTextureNormal(const std::string &normal, @optional cocos2d::ui::Widget::TextureResType texType)
    self->loadTextureNormal(arg1, (cocos2d::ui::Widget::TextureResType)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_EditBox_loadTextureNormal2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    std::string arg1;       /** normal */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.EditBox");
    olua_check_std_string(L, 2, &arg1);

    // void loadTextureNormal(const std::string &normal, @optional cocos2d::ui::Widget::TextureResType texType)
    self->loadTextureNormal(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_EditBox_loadTextureNormal(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 2))) {
            // void loadTextureNormal(const std::string &normal, @optional cocos2d::ui::Widget::TextureResType texType)
            return _cocos2d_ui_EditBox_loadTextureNormal2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_uint(L, 3))) {
            // void loadTextureNormal(const std::string &normal, @optional cocos2d::ui::Widget::TextureResType texType)
            return _cocos2d_ui_EditBox_loadTextureNormal1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::EditBox::loadTextureNormal' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ui_EditBox_loadTexturePressed1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    std::string arg1;       /** pressed */
    lua_Unsigned arg2 = 0;       /** texType */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.EditBox");
    olua_check_std_string(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // void loadTexturePressed(const std::string &pressed, @optional cocos2d::ui::Widget::TextureResType texType)
    self->loadTexturePressed(arg1, (cocos2d::ui::Widget::TextureResType)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_EditBox_loadTexturePressed2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    std::string arg1;       /** pressed */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.EditBox");
    olua_check_std_string(L, 2, &arg1);

    // void loadTexturePressed(const std::string &pressed, @optional cocos2d::ui::Widget::TextureResType texType)
    self->loadTexturePressed(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_EditBox_loadTexturePressed(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 2))) {
            // void loadTexturePressed(const std::string &pressed, @optional cocos2d::ui::Widget::TextureResType texType)
            return _cocos2d_ui_EditBox_loadTexturePressed2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_uint(L, 3))) {
            // void loadTexturePressed(const std::string &pressed, @optional cocos2d::ui::Widget::TextureResType texType)
            return _cocos2d_ui_EditBox_loadTexturePressed1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::EditBox::loadTexturePressed' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ui_EditBox_loadTextures1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    std::string arg1;       /** normal */
    std::string arg2;       /** pressed */
    std::string arg3;       /** disabled */
    lua_Unsigned arg4 = 0;       /** texType */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.EditBox");
    olua_check_std_string(L, 2, &arg1);
    olua_check_std_string(L, 3, &arg2);
    olua_check_std_string(L, 4, &arg3);
    olua_check_uint(L, 5, &arg4);

    // void loadTextures(const std::string &normal, const std::string &pressed, @optional const std::string &disabled, @optional cocos2d::ui::Widget::TextureResType texType)
    self->loadTextures(arg1, arg2, arg3, (cocos2d::ui::Widget::TextureResType)arg4);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_EditBox_loadTextures2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    std::string arg1;       /** normal */
    std::string arg2;       /** pressed */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.EditBox");
    olua_check_std_string(L, 2, &arg1);
    olua_check_std_string(L, 3, &arg2);

    // void loadTextures(const std::string &normal, const std::string &pressed, @optional const std::string &disabled, @optional cocos2d::ui::Widget::TextureResType texType)
    self->loadTextures(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_EditBox_loadTextures3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    std::string arg1;       /** normal */
    std::string arg2;       /** pressed */
    std::string arg3;       /** disabled */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.EditBox");
    olua_check_std_string(L, 2, &arg1);
    olua_check_std_string(L, 3, &arg2);
    olua_check_std_string(L, 4, &arg3);

    // void loadTextures(const std::string &normal, const std::string &pressed, @optional const std::string &disabled, @optional cocos2d::ui::Widget::TextureResType texType)
    self->loadTextures(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_EditBox_loadTextures(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_std_string(L, 3))) {
            // void loadTextures(const std::string &normal, const std::string &pressed, @optional const std::string &disabled, @optional cocos2d::ui::Widget::TextureResType texType)
            return _cocos2d_ui_EditBox_loadTextures2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_std_string(L, 3)) && (olua_is_std_string(L, 4))) {
            // void loadTextures(const std::string &normal, const std::string &pressed, @optional const std::string &disabled, @optional cocos2d::ui::Widget::TextureResType texType)
            return _cocos2d_ui_EditBox_loadTextures3(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_std_string(L, 3)) && (olua_is_std_string(L, 4)) && (olua_is_uint(L, 5))) {
            // void loadTextures(const std::string &normal, const std::string &pressed, @optional const std::string &disabled, @optional cocos2d::ui::Widget::TextureResType texType)
            return _cocos2d_ui_EditBox_loadTextures1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::EditBox::loadTextures' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ui_EditBox_new(lua_State *L)
{
    olua_startinvoke(L);

    // EditBox()
    cocos2d::ui::EditBox *ret = (cocos2d::ui::EditBox *)new cocos2d::ui::EditBox();
    int num_ret = olua_push_cppobj(L, ret, "ccui.EditBox");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ui_EditBox_openKeyboard(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccui.EditBox");

    // void openKeyboard()
    self->openKeyboard();

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_EditBox_setCapInsets(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    cocos2d::Rect arg1;       /** capInsets */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.EditBox");
    manual_olua_check_cocos2d_Rect(L, 2, &arg1);

    // void setCapInsets(const cocos2d::Rect &capInsets)
    self->setCapInsets(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_EditBox_setCapInsetsDisabledRenderer(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    cocos2d::Rect arg1;       /** capInsets */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.EditBox");
    manual_olua_check_cocos2d_Rect(L, 2, &arg1);

    // void setCapInsetsDisabledRenderer(const cocos2d::Rect &capInsets)
    self->setCapInsetsDisabledRenderer(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_EditBox_setCapInsetsNormalRenderer(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    cocos2d::Rect arg1;       /** capInsets */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.EditBox");
    manual_olua_check_cocos2d_Rect(L, 2, &arg1);

    // void setCapInsetsNormalRenderer(const cocos2d::Rect &capInsets)
    self->setCapInsetsNormalRenderer(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_EditBox_setCapInsetsPressedRenderer(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    cocos2d::Rect arg1;       /** capInsets */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.EditBox");
    manual_olua_check_cocos2d_Rect(L, 2, &arg1);

    // void setCapInsetsPressedRenderer(const cocos2d::Rect &capInsets)
    self->setCapInsetsPressedRenderer(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_EditBox_setDelegate(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    cocos2d::ui::EditBoxDelegate *arg1 = nullptr;       /** delegate */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.EditBox");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccui.EditBoxDelegate");

    // void setDelegate(@addref(delegate ^) cocos2d::ui::EditBoxDelegate *delegate)
    self->setDelegate(arg1);

    // inject code after call
    olua_addref(L, 1, "delegate", 2, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_EditBox_setFont(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    const char *arg1 = nullptr;       /** pFontName */
    lua_Integer arg2 = 0;       /** fontSize */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.EditBox");
    olua_check_string(L, 2, &arg1);
    olua_check_int(L, 3, &arg2);

    // void setFont(const char *pFontName, int fontSize)
    self->setFont(arg1, (int)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_EditBox_setFontColor1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    cocos2d::Color3B arg1;       /** color */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.EditBox");
    manual_olua_check_cocos2d_Color3B(L, 2, &arg1);

    // void setFontColor(const cocos2d::Color3B &color)
    self->setFontColor(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_EditBox_setFontColor2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    cocos2d::Color4B arg1;       /** color */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.EditBox");
    manual_olua_check_cocos2d_Color4B(L, 2, &arg1);

    // void setFontColor(const cocos2d::Color4B &color)
    self->setFontColor(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_EditBox_setFontColor(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        if ((manual_olua_is_cocos2d_Color3B(L, 2))) {
            // void setFontColor(const cocos2d::Color3B &color)
            return _cocos2d_ui_EditBox_setFontColor1(L);
        }

        // if ((manual_olua_is_cocos2d_Color4B(L, 2))) {
            // void setFontColor(const cocos2d::Color4B &color)
            return _cocos2d_ui_EditBox_setFontColor2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::EditBox::setFontColor' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ui_EditBox_setFontName(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    const char *arg1 = nullptr;       /** pFontName */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.EditBox");
    olua_check_string(L, 2, &arg1);

    // void setFontName(const char *pFontName)
    self->setFontName(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_EditBox_setFontSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    lua_Integer arg1 = 0;       /** fontSize */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.EditBox");
    olua_check_int(L, 2, &arg1);

    // void setFontSize(int fontSize)
    self->setFontSize((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_EditBox_setInputFlag(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    lua_Unsigned arg1 = 0;       /** inputFlag */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.EditBox");
    olua_check_uint(L, 2, &arg1);

    // void setInputFlag(cocos2d::ui::EditBox::InputFlag inputFlag)
    self->setInputFlag((cocos2d::ui::EditBox::InputFlag)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_EditBox_setInputMode(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    lua_Unsigned arg1 = 0;       /** inputMode */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.EditBox");
    olua_check_uint(L, 2, &arg1);

    // void setInputMode(cocos2d::ui::EditBox::InputMode inputMode)
    self->setInputMode((cocos2d::ui::EditBox::InputMode)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_EditBox_setMaxLength(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    lua_Integer arg1 = 0;       /** maxLength */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.EditBox");
    olua_check_int(L, 2, &arg1);

    // void setMaxLength(int maxLength)
    self->setMaxLength((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_EditBox_setPlaceHolder(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    const char *arg1 = nullptr;       /** pText */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.EditBox");
    olua_check_string(L, 2, &arg1);

    // void setPlaceHolder(const char *pText)
    self->setPlaceHolder(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_EditBox_setPlaceholderFont(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    const char *arg1 = nullptr;       /** pFontName */
    lua_Integer arg2 = 0;       /** fontSize */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.EditBox");
    olua_check_string(L, 2, &arg1);
    olua_check_int(L, 3, &arg2);

    // void setPlaceholderFont(const char *pFontName, int fontSize)
    self->setPlaceholderFont(arg1, (int)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_EditBox_setPlaceholderFontColor1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    cocos2d::Color3B arg1;       /** color */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.EditBox");
    manual_olua_check_cocos2d_Color3B(L, 2, &arg1);

    // void setPlaceholderFontColor(const cocos2d::Color3B &color)
    self->setPlaceholderFontColor(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_EditBox_setPlaceholderFontColor2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    cocos2d::Color4B arg1;       /** color */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.EditBox");
    manual_olua_check_cocos2d_Color4B(L, 2, &arg1);

    // void setPlaceholderFontColor(const cocos2d::Color4B &color)
    self->setPlaceholderFontColor(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_EditBox_setPlaceholderFontColor(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        if ((manual_olua_is_cocos2d_Color3B(L, 2))) {
            // void setPlaceholderFontColor(const cocos2d::Color3B &color)
            return _cocos2d_ui_EditBox_setPlaceholderFontColor1(L);
        }

        // if ((manual_olua_is_cocos2d_Color4B(L, 2))) {
            // void setPlaceholderFontColor(const cocos2d::Color4B &color)
            return _cocos2d_ui_EditBox_setPlaceholderFontColor2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::EditBox::setPlaceholderFontColor' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ui_EditBox_setPlaceholderFontName(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    const char *arg1 = nullptr;       /** pFontName */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.EditBox");
    olua_check_string(L, 2, &arg1);

    // void setPlaceholderFontName(const char *pFontName)
    self->setPlaceholderFontName(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_EditBox_setPlaceholderFontSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    lua_Integer arg1 = 0;       /** fontSize */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.EditBox");
    olua_check_int(L, 2, &arg1);

    // void setPlaceholderFontSize(int fontSize)
    self->setPlaceholderFontSize((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_EditBox_setReturnType(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    lua_Unsigned arg1 = 0;       /** returnType */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.EditBox");
    olua_check_uint(L, 2, &arg1);

    // void setReturnType(cocos2d::ui::EditBox::KeyboardReturnType returnType)
    self->setReturnType((cocos2d::ui::EditBox::KeyboardReturnType)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_EditBox_setText(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    const char *arg1 = nullptr;       /** pText */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.EditBox");
    olua_check_string(L, 2, &arg1);

    // void setText(const char *pText)
    self->setText(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ui_EditBox_setTextHorizontalAlignment(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::EditBox *self = nullptr;
    lua_Unsigned arg1 = 0;       /** alignment */

    olua_to_cppobj(L, 1, (void **)&self, "ccui.EditBox");
    olua_check_uint(L, 2, &arg1);

    // void setTextHorizontalAlignment(cocos2d::TextHAlignment alignment)
    self->setTextHorizontalAlignment((cocos2d::TextHAlignment)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_ui_EditBox(lua_State *L)
{
    oluacls_class(L, "ccui.EditBox", "ccui.Widget");
    oluacls_func(L, "__move", _cocos2d_ui_EditBox___move);
    oluacls_func(L, "create", _cocos2d_ui_EditBox_create);
    oluacls_func(L, "getCapInsetsDisabledRenderer", _cocos2d_ui_EditBox_getCapInsetsDisabledRenderer);
    oluacls_func(L, "getCapInsetsNormalRenderer", _cocos2d_ui_EditBox_getCapInsetsNormalRenderer);
    oluacls_func(L, "getCapInsetsPressedRenderer", _cocos2d_ui_EditBox_getCapInsetsPressedRenderer);
    oluacls_func(L, "getDelegate", _cocos2d_ui_EditBox_getDelegate);
    oluacls_func(L, "getFontColor", _cocos2d_ui_EditBox_getFontColor);
    oluacls_func(L, "getFontName", _cocos2d_ui_EditBox_getFontName);
    oluacls_func(L, "getFontSize", _cocos2d_ui_EditBox_getFontSize);
    oluacls_func(L, "getInputFlag", _cocos2d_ui_EditBox_getInputFlag);
    oluacls_func(L, "getInputMode", _cocos2d_ui_EditBox_getInputMode);
    oluacls_func(L, "getMaxLength", _cocos2d_ui_EditBox_getMaxLength);
    oluacls_func(L, "getPlaceHolder", _cocos2d_ui_EditBox_getPlaceHolder);
    oluacls_func(L, "getPlaceholderFontColor", _cocos2d_ui_EditBox_getPlaceholderFontColor);
    oluacls_func(L, "getPlaceholderFontName", _cocos2d_ui_EditBox_getPlaceholderFontName);
    oluacls_func(L, "getPlaceholderFontSize", _cocos2d_ui_EditBox_getPlaceholderFontSize);
    oluacls_func(L, "getReturnType", _cocos2d_ui_EditBox_getReturnType);
    oluacls_func(L, "getText", _cocos2d_ui_EditBox_getText);
    oluacls_func(L, "getTextHorizontalAlignment", _cocos2d_ui_EditBox_getTextHorizontalAlignment);
    oluacls_func(L, "initWithSizeAndBackgroundSprite", _cocos2d_ui_EditBox_initWithSizeAndBackgroundSprite);
    oluacls_func(L, "initWithSizeAndTexture", _cocos2d_ui_EditBox_initWithSizeAndTexture);
    oluacls_func(L, "loadTextureDisabled", _cocos2d_ui_EditBox_loadTextureDisabled);
    oluacls_func(L, "loadTextureNormal", _cocos2d_ui_EditBox_loadTextureNormal);
    oluacls_func(L, "loadTexturePressed", _cocos2d_ui_EditBox_loadTexturePressed);
    oluacls_func(L, "loadTextures", _cocos2d_ui_EditBox_loadTextures);
    oluacls_func(L, "new", _cocos2d_ui_EditBox_new);
    oluacls_func(L, "openKeyboard", _cocos2d_ui_EditBox_openKeyboard);
    oluacls_func(L, "setCapInsets", _cocos2d_ui_EditBox_setCapInsets);
    oluacls_func(L, "setCapInsetsDisabledRenderer", _cocos2d_ui_EditBox_setCapInsetsDisabledRenderer);
    oluacls_func(L, "setCapInsetsNormalRenderer", _cocos2d_ui_EditBox_setCapInsetsNormalRenderer);
    oluacls_func(L, "setCapInsetsPressedRenderer", _cocos2d_ui_EditBox_setCapInsetsPressedRenderer);
    oluacls_func(L, "setDelegate", _cocos2d_ui_EditBox_setDelegate);
    oluacls_func(L, "setFont", _cocos2d_ui_EditBox_setFont);
    oluacls_func(L, "setFontColor", _cocos2d_ui_EditBox_setFontColor);
    oluacls_func(L, "setFontName", _cocos2d_ui_EditBox_setFontName);
    oluacls_func(L, "setFontSize", _cocos2d_ui_EditBox_setFontSize);
    oluacls_func(L, "setInputFlag", _cocos2d_ui_EditBox_setInputFlag);
    oluacls_func(L, "setInputMode", _cocos2d_ui_EditBox_setInputMode);
    oluacls_func(L, "setMaxLength", _cocos2d_ui_EditBox_setMaxLength);
    oluacls_func(L, "setPlaceHolder", _cocos2d_ui_EditBox_setPlaceHolder);
    oluacls_func(L, "setPlaceholderFont", _cocos2d_ui_EditBox_setPlaceholderFont);
    oluacls_func(L, "setPlaceholderFontColor", _cocos2d_ui_EditBox_setPlaceholderFontColor);
    oluacls_func(L, "setPlaceholderFontName", _cocos2d_ui_EditBox_setPlaceholderFontName);
    oluacls_func(L, "setPlaceholderFontSize", _cocos2d_ui_EditBox_setPlaceholderFontSize);
    oluacls_func(L, "setReturnType", _cocos2d_ui_EditBox_setReturnType);
    oluacls_func(L, "setText", _cocos2d_ui_EditBox_setText);
    oluacls_func(L, "setTextHorizontalAlignment", _cocos2d_ui_EditBox_setTextHorizontalAlignment);
    oluacls_prop(L, "capInsetsDisabledRenderer", _cocos2d_ui_EditBox_getCapInsetsDisabledRenderer, _cocos2d_ui_EditBox_setCapInsetsDisabledRenderer);
    oluacls_prop(L, "capInsetsNormalRenderer", _cocos2d_ui_EditBox_getCapInsetsNormalRenderer, _cocos2d_ui_EditBox_setCapInsetsNormalRenderer);
    oluacls_prop(L, "capInsetsPressedRenderer", _cocos2d_ui_EditBox_getCapInsetsPressedRenderer, _cocos2d_ui_EditBox_setCapInsetsPressedRenderer);
    oluacls_prop(L, "delegate", _cocos2d_ui_EditBox_getDelegate, _cocos2d_ui_EditBox_setDelegate);
    oluacls_prop(L, "fontColor", _cocos2d_ui_EditBox_getFontColor, _cocos2d_ui_EditBox_setFontColor);
    oluacls_prop(L, "fontName", _cocos2d_ui_EditBox_getFontName, _cocos2d_ui_EditBox_setFontName);
    oluacls_prop(L, "fontSize", _cocos2d_ui_EditBox_getFontSize, _cocos2d_ui_EditBox_setFontSize);
    oluacls_prop(L, "inputFlag", _cocos2d_ui_EditBox_getInputFlag, _cocos2d_ui_EditBox_setInputFlag);
    oluacls_prop(L, "inputMode", _cocos2d_ui_EditBox_getInputMode, _cocos2d_ui_EditBox_setInputMode);
    oluacls_prop(L, "maxLength", _cocos2d_ui_EditBox_getMaxLength, _cocos2d_ui_EditBox_setMaxLength);
    oluacls_prop(L, "placeHolder", _cocos2d_ui_EditBox_getPlaceHolder, _cocos2d_ui_EditBox_setPlaceHolder);
    oluacls_prop(L, "placeholderFontColor", _cocos2d_ui_EditBox_getPlaceholderFontColor, _cocos2d_ui_EditBox_setPlaceholderFontColor);
    oluacls_prop(L, "placeholderFontName", _cocos2d_ui_EditBox_getPlaceholderFontName, _cocos2d_ui_EditBox_setPlaceholderFontName);
    oluacls_prop(L, "placeholderFontSize", _cocos2d_ui_EditBox_getPlaceholderFontSize, _cocos2d_ui_EditBox_setPlaceholderFontSize);
    oluacls_prop(L, "returnType", _cocos2d_ui_EditBox_getReturnType, _cocos2d_ui_EditBox_setReturnType);
    oluacls_prop(L, "text", _cocos2d_ui_EditBox_getText, _cocos2d_ui_EditBox_setText);
    oluacls_prop(L, "textHorizontalAlignment", _cocos2d_ui_EditBox_getTextHorizontalAlignment, _cocos2d_ui_EditBox_setTextHorizontalAlignment);

    olua_registerluatype<cocos2d::ui::EditBox>(L, "ccui.EditBox");

    return 1;
}

int luaopen_cocos2d_ui(lua_State *L)
{
    olua_require(L, "ccui.Widget.FocusDirection", luaopen_cocos2d_ui_Widget_FocusDirection);
    olua_require(L, "ccui.Widget.PositionType", luaopen_cocos2d_ui_Widget_PositionType);
    olua_require(L, "ccui.Widget.SizeType", luaopen_cocos2d_ui_Widget_SizeType);
    olua_require(L, "ccui.Widget.TouchEventType", luaopen_cocos2d_ui_Widget_TouchEventType);
    olua_require(L, "ccui.Widget.TextureResType", luaopen_cocos2d_ui_Widget_TextureResType);
    olua_require(L, "ccui.Widget.BrightStyle", luaopen_cocos2d_ui_Widget_BrightStyle);
    olua_require(L, "ccui.Widget", luaopen_cocos2d_ui_Widget);
    olua_require(L, "ccui.Helper", luaopen_cocos2d_ui_Helper);
    olua_require(L, "ccui.Scale9Sprite.State", luaopen_cocos2d_ui_Scale9Sprite_State);
    olua_require(L, "ccui.Scale9Sprite.RenderingType", luaopen_cocos2d_ui_Scale9Sprite_RenderingType);
    olua_require(L, "ccui.Scale9Sprite", luaopen_cocos2d_ui_Scale9Sprite);
    olua_require(L, "ccui.LayoutComponent.HorizontalEdge", luaopen_cocos2d_ui_LayoutComponent_HorizontalEdge);
    olua_require(L, "ccui.LayoutComponent.VerticalEdge", luaopen_cocos2d_ui_LayoutComponent_VerticalEdge);
    olua_require(L, "ccui.LayoutComponent", luaopen_cocos2d_ui_LayoutComponent);
    olua_require(L, "ccui.LayoutParameter.Type", luaopen_cocos2d_ui_LayoutParameter_Type);
    olua_require(L, "ccui.LayoutParameter", luaopen_cocos2d_ui_LayoutParameter);
    olua_require(L, "ccui.LinearLayoutParameter.LinearGravity", luaopen_cocos2d_ui_LinearLayoutParameter_LinearGravity);
    olua_require(L, "ccui.LinearLayoutParameter", luaopen_cocos2d_ui_LinearLayoutParameter);
    olua_require(L, "ccui.RelativeLayoutParameter.RelativeAlign", luaopen_cocos2d_ui_RelativeLayoutParameter_RelativeAlign);
    olua_require(L, "ccui.RelativeLayoutParameter", luaopen_cocos2d_ui_RelativeLayoutParameter);
    olua_require(L, "ccui.Layout.Type", luaopen_cocos2d_ui_Layout_Type);
    olua_require(L, "ccui.Layout.ClippingType", luaopen_cocos2d_ui_Layout_ClippingType);
    olua_require(L, "ccui.Layout.BackGroundColorType", luaopen_cocos2d_ui_Layout_BackGroundColorType);
    olua_require(L, "ccui.Layout", luaopen_cocos2d_ui_Layout);
    olua_require(L, "ccui.HBox", luaopen_cocos2d_ui_HBox);
    olua_require(L, "ccui.VBox", luaopen_cocos2d_ui_VBox);
    olua_require(L, "ccui.RelativeBox", luaopen_cocos2d_ui_RelativeBox);
#ifdef CCLUA_HAVE_WEBVIEW
    olua_require(L, "ccui.WebView", luaopen_cocos2d_ui_WebView);
#endif
#ifdef CCLUA_HAVE_VIDEOPLAYER
    olua_require(L, "ccui.VideoPlayer.EventType", luaopen_cocos2d_ui_VideoPlayer_EventType);
#endif
#ifdef CCLUA_HAVE_VIDEOPLAYER
    olua_require(L, "ccui.VideoPlayer.StyleType", luaopen_cocos2d_ui_VideoPlayer_StyleType);
#endif
#ifdef CCLUA_HAVE_VIDEOPLAYER
    olua_require(L, "ccui.VideoPlayer", luaopen_cocos2d_ui_VideoPlayer);
#endif
    olua_require(L, "ccui.AbstractCheckButton", luaopen_cocos2d_ui_AbstractCheckButton);
    olua_require(L, "ccui.TabHeader.EventType", luaopen_cocos2d_ui_TabHeader_EventType);
    olua_require(L, "ccui.TabHeader", luaopen_cocos2d_ui_TabHeader);
    olua_require(L, "ccui.TabControl.Dock", luaopen_cocos2d_ui_TabControl_Dock);
    olua_require(L, "ccui.TabControl.EventType", luaopen_cocos2d_ui_TabControl_EventType);
    olua_require(L, "ccui.TabControl", luaopen_cocos2d_ui_TabControl);
    olua_require(L, "ccui.ScrollView.Direction", luaopen_cocos2d_ui_ScrollView_Direction);
    olua_require(L, "ccui.ScrollView.EventType", luaopen_cocos2d_ui_ScrollView_EventType);
    olua_require(L, "ccui.ScrollView", luaopen_cocos2d_ui_ScrollView);
    olua_require(L, "ccui.ListView.Gravity", luaopen_cocos2d_ui_ListView_Gravity);
    olua_require(L, "ccui.ListView.EventType", luaopen_cocos2d_ui_ListView_EventType);
    olua_require(L, "ccui.ListView.MagneticType", luaopen_cocos2d_ui_ListView_MagneticType);
    olua_require(L, "ccui.ListView", luaopen_cocos2d_ui_ListView);
    olua_require(L, "ccui.LoadingBar.Direction", luaopen_cocos2d_ui_LoadingBar_Direction);
    olua_require(L, "ccui.LoadingBar", luaopen_cocos2d_ui_LoadingBar);
    olua_require(L, "ccui.PageView.EventType", luaopen_cocos2d_ui_PageView_EventType);
    olua_require(L, "ccui.PageView.TouchDirection", luaopen_cocos2d_ui_PageView_TouchDirection);
    olua_require(L, "ccui.PageView", luaopen_cocos2d_ui_PageView);
    olua_require(L, "ccui.RichElement.Type", luaopen_cocos2d_ui_RichElement_Type);
    olua_require(L, "ccui.RichElement", luaopen_cocos2d_ui_RichElement);
    olua_require(L, "ccui.RichElementText", luaopen_cocos2d_ui_RichElementText);
    olua_require(L, "ccui.RichElementImage", luaopen_cocos2d_ui_RichElementImage);
    olua_require(L, "ccui.RichElementCustomNode", luaopen_cocos2d_ui_RichElementCustomNode);
    olua_require(L, "ccui.RichElementNewLine", luaopen_cocos2d_ui_RichElementNewLine);
    olua_require(L, "ccui.RichText.WrapMode", luaopen_cocos2d_ui_RichText_WrapMode);
    olua_require(L, "ccui.RichText.HorizontalAlignment", luaopen_cocos2d_ui_RichText_HorizontalAlignment);
    olua_require(L, "ccui.RichText", luaopen_cocos2d_ui_RichText);
    olua_require(L, "ccui.ScrollViewBar", luaopen_cocos2d_ui_ScrollViewBar);
    olua_require(L, "ccui.Slider.EventType", luaopen_cocos2d_ui_Slider_EventType);
    olua_require(L, "ccui.Slider", luaopen_cocos2d_ui_Slider);
    olua_require(L, "ccui.Text.Type", luaopen_cocos2d_ui_Text_Type);
    olua_require(L, "ccui.Text", luaopen_cocos2d_ui_Text);
    olua_require(L, "ccui.TextAtlas", luaopen_cocos2d_ui_TextAtlas);
    olua_require(L, "ccui.TextBMFont", luaopen_cocos2d_ui_TextBMFont);
    olua_require(L, "ccui.UICCTextField", luaopen_cocos2d_ui_UICCTextField);
    olua_require(L, "ccui.TextField.EventType", luaopen_cocos2d_ui_TextField_EventType);
    olua_require(L, "ccui.TextField", luaopen_cocos2d_ui_TextField);
    olua_require(L, "ccui.Button", luaopen_cocos2d_ui_Button);
    olua_require(L, "ccui.CheckBox.EventType", luaopen_cocos2d_ui_CheckBox_EventType);
    olua_require(L, "ccui.CheckBox", luaopen_cocos2d_ui_CheckBox);
    olua_require(L, "ccui.RadioButton.EventType", luaopen_cocos2d_ui_RadioButton_EventType);
    olua_require(L, "ccui.RadioButton", luaopen_cocos2d_ui_RadioButton);
    olua_require(L, "ccui.RadioButtonGroup.EventType", luaopen_cocos2d_ui_RadioButtonGroup_EventType);
    olua_require(L, "ccui.RadioButtonGroup", luaopen_cocos2d_ui_RadioButtonGroup);
    olua_require(L, "ccui.ImageView", luaopen_cocos2d_ui_ImageView);
    olua_require(L, "ccui.EditBoxDelegate.EditBoxEndAction", luaopen_cocos2d_ui_EditBoxDelegate_EditBoxEndAction);
    olua_require(L, "ccui.EditBoxDelegate", luaopen_cocos2d_ui_EditBoxDelegate);
    olua_require(L, "ccui.LuaEditBoxDelegate", luaopen_cocos2d_ui_LuaEditBoxDelegate);
    olua_require(L, "ccui.EditBox.KeyboardReturnType", luaopen_cocos2d_ui_EditBox_KeyboardReturnType);
    olua_require(L, "ccui.EditBox.InputMode", luaopen_cocos2d_ui_EditBox_InputMode);
    olua_require(L, "ccui.EditBox.InputFlag", luaopen_cocos2d_ui_EditBox_InputFlag);
    olua_require(L, "ccui.EditBox", luaopen_cocos2d_ui_EditBox);
    return 0;
}
