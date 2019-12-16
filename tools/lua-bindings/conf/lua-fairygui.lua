local autoconf = require "autoconf"
local M = autoconf.typemod 'fairygui'
local typeconf = M.typeconf
local typeconv = M.typeconv
local typedef = M.typedef
local typeonly = M.typeonly

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
}]]

M.EXCLUDE_TYPE = require "conf.exclude-type"
M.EXCLUDE_TYPE 'fairygui::ByteBuffer *'
M.EXCLUDE_TYPE 'fairygui::GObjectPool *'
M.EXCLUDE_TYPE 'std::vector *'

M.EXCLUDE_PASS = function (cppcls, fn, decl)
    return string.find(decl, 'operator *= *')
        or string.find(fn, '^_')
end

M.MAKE_LUACLS = function (cppname)
    cppname = string.gsub(cppname, '^fairygui::', 'fgui.')
    return cppname
end

typedef {
    CPPCLS = 'fairygui::EventTag',
    CONV = 'manual_olua_$$_fairygui_EventTag',
}

typeconv 'fairygui::Margin'
typeconv 'fairygui::TweenValue'
    .ATTR('*', {OPTIONAL = true})

typeconf 'fairygui::UIEventType'

local UIEventDispatcher = typeconf 'fairygui::UIEventDispatcher'
UIEventDispatcher.CHUNK = [[
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
}]]
UIEventDispatcher.CALLBACK {
    NAME = 'addEventListener',
    TAG_MAKER = {'makeListenerTag(L, #1, 0)', 'makeListenerTag(L, #1, 4)'},
    TAG_MODE = 'OLUA_TAG_NEW',
}
UIEventDispatcher.CALLBACK {
    NAME = 'removeEventListener',
    TAG_MAKER = {'makeListenerTag(L, #1, 0)', 'makeListenerTag(L, #1, 3)'},
    TAG_MODE = {'OLUA_TAG_SUBSTARTWITH', 'OLUA_TAG_SUBEQUAL'},
    REMOVE = true,
}
UIEventDispatcher.CALLBACK {
    NAME = 'removeEventListeners',
    TAG_MAKER = 'makeListenerTag(L, -1, 0)',
    TAG_MODE = 'OLUA_TAG_SUBSTARTWITH',
    REMOVE = true,
}

typeconf 'fairygui::EventContext'
typeconf 'fairygui::IHitTest'

typeconf 'fairygui::InputProcessor'
    .CALLBACK {NAME = 'setCaptureCallback', NULLABLE = true}

typeconf 'fairygui::InputEvent'

local TextFormat = typeconf 'fairygui::TextFormat'
TextFormat.FUNC('setFormat', [[
{
    fairygui::TextFormat *self = (fairygui::TextFormat *)olua_toobj(L, 1, "fgui.TextFormat");
    fairygui::TextFormat *fmt = (fairygui::TextFormat *)olua_checkobj(L, 2, "fgui.TextFormat");
    self->setFormat(*fmt);
    return 0;
}]])

typeconf 'fairygui::EaseType'
typeconf 'fairygui::EaseManager'
typeconf 'fairygui::TweenPropType'
typeonly 'fairygui::GPath'

typeconf 'fairygui::GTweener'
    .CALLBACK {NAME = 'onUpdate', LOCAL = false}
    .CALLBACK {NAME = 'onStart', LOCAL = false}
    .CALLBACK {NAME = 'onComplete', LOCAL = false}
    .CALLBACK {NAME = 'onComplete1', LOCAL = false}

local GTween = typeconf 'fairygui::GTween'
GTween.CHUNK = [[
static bool should_unref_tweener(lua_State *L, int idx)
{
    if (olua_isa(L, idx, "fgui.GTweener")) {
        fairygui::GTweener *obj = (fairygui::GTweener *)olua_toobj(L, idx, "fgui.GTweener");
        if (obj->getReferenceCount() == 1 || obj->allCompleted()) {
            return true;
        }
    }
    return false;
}]]
local UNREF_TWEEN = {
    AFTER = [[
        olua_getstore(L, "fgui.GTween");
        olua_mapwalkunref(L, -1, "tweeners", should_unref_tweener);
        lua_pop(L, 1);
    ]]
}
local REF_TEWEENER = {
    AFTER = [[
        olua_getstore(L, "fgui.GTween");
        olua_mapref(L, -1, "tweeners", -2);
        olua_mapwalkunref(L, -1, "tweeners", should_unref_tweener);
        lua_pop(L, 1);
    ]]
}
GTween.INJECT('to', REF_TEWEENER)
GTween.INJECT('toDouble', REF_TEWEENER)
GTween.INJECT('delayedCall', REF_TEWEENER)
GTween.INJECT('shake', REF_TEWEENER)
GTween.INJECT('kill', UNREF_TWEEN)
GTween.INJECT('clean', {
    AFTER = [[
        olua_getstore(L, "fgui.GTween");
        olua_unrefall(L, 1, "tweeners");
    ]]
})

typeconf 'fairygui::UIPackage'
local PackageItem = typeconf 'fairygui::PackageItem'
PackageItem.EXCLUDE 'rawData'
PackageItem.EXCLUDE 'pixelHitTestData'
PackageItem.EXCLUDE 'extensionCreator'
PackageItem.EXCLUDE 'bitmapFont'
PackageItem.EXCLUDE 'scale9Grid'

typeconf 'fairygui::PackageItemType'
typeconf 'fairygui::ObjectType'
typeconf 'fairygui::ButtonMode'
typeconf 'fairygui::ChildrenRenderOrder'
typeconf 'fairygui::OverflowType'
typeconf 'fairygui::ScrollType'
typeconf 'fairygui::ScrollBarDisplayType'
typeconf 'fairygui::LoaderFillType'
typeconf 'fairygui::ProgressTitleType'
typeconf 'fairygui::ListLayoutType'
typeconf 'fairygui::ListSelectionMode'
typeconf 'fairygui::GroupLayoutType'
typeconf 'fairygui::PopupDirection'
typeconf 'fairygui::AutoSizeType'
typeconf 'fairygui::FlipType'
typeconf 'fairygui::TransitionActionType'
typeconf 'fairygui::FillMethod'
typeconf 'fairygui::FillOrigin'
typeconf 'fairygui::ObjectPropID'
typeconf 'fairygui::GController'

local GObject = typeconf 'fairygui::GObject'
GObject.EXCLUDE 'constructFromResource'
GObject.ATTR('getGroup', {RET = '@ref(single group)'})
GObject.ATTR('setGroup', {ARG1 = '@ref(single group)'})
GObject.ATTR('globalToLocal', {ARG1 = '@pack'})
GObject.ATTR('localToGlobal', {ARG1 = '@pack'})
GObject.ATTR('transformRect', {ARG1 = '@pack'})
GObject.ATTR('displayObject', {RET = '@ref(single displayObject)'})
GObject.PROP('relations', 'Relations* relations()')
GObject.PROP('displayObject', 'cocos2d::Node* displayObject()')
GObject.FUNC('getDragBounds', [[
{
    fairygui::GObject *self = (fairygui::GObject *)olua_toobj(L, 1, "fgui.GObject");
    cocos2d::Rect *rect = self->getDragBounds();
    manual_olua_push_cocos2d_Rect(L, rect);
    return 1;
}]])
GObject.CALLBACK {
    NAME = 'addClickListener',
    TAG_MAKER = {
        'makeListenerTag(L, fairygui::UIEventType::Click, 0)', -- no tag
        'makeListenerTag(L, fairygui::UIEventType::Click, 3)', -- tag stack idx
    },
    TAG_MODE = 'OLUA_TAG_NEW',
}
GObject.CALLBACK {
    NAME = 'removeClickListener',
    TAG_MAKER = 'makeListenerTag(L, fairygui::UIEventType::Click, 2)',
    TAG_MODE = 'OLUA_TAG_SUBEQUAL',
    REMOVE = true,
}
GObject.INJECT('center', {
    BEFORE = [[
        if (!self->getParent() && !fairygui::UIRoot) {
            luaL_error(L, "UIRoot and parent are both nullptr");
        }
    ]]
})
GObject.INJECT('makeFullScreen', {
    BEFORE = [[
        if (!fairygui::UIRoot) {
            luaL_error(L, "UIRoot is nullptr");
        }
    ]]
})

local GComponent = typeconf 'fairygui::GComponent'
GComponent.ATTR('addChild', {ARG1 = '@ref(map children)'})
GComponent.ATTR('addChildAt', {ARG1 = '@ref(map children)'})
GComponent.ATTR('removeChild', {ARG1 = '@unref(map children)'})
GComponent.ATTR('removeChildAt', {RET = '@unref(cmp children)'})
GComponent.ATTR('removeChildren', {RET = '@unref(cmp children)'})
GComponent.ATTR('getChildAt', {RET = '@ref(map children)'})
GComponent.ATTR('getChild', {RET = '@ref(map children)'})
GComponent.ATTR('getChildInGroup', {RET = '@ref(map children)'})
GComponent.ATTR('getChildById', {RET = '@ref(map children)'})
GComponent.ATTR('getChildren', {RET = '@ref(map children)'})
GComponent.ATTR('addController', {ARG1 = '@ref(map controllers)'})
GComponent.ATTR('getControllerAt', {RET = '@ref(map controllers)'})
GComponent.ATTR('getController', {RET = '@ref(map controllers)'})
GComponent.ATTR('getControllers', {RET = '@ref(map controllers)'})
GComponent.ATTR('removeController', {ARG1 = '@unref(map controllers)'})
GComponent.ATTR('getTransition', {RET = '@ref(map transitions)'})
GComponent.ATTR('getTransitionAt', {RET = '@ref(map transitions)'})
GComponent.ATTR('getTransitions', {RET = '@ref(map transitions)'})
GComponent.ATTR('getMask', {RET = '@ref(single mask)'})
GComponent.ATTR('setMask', {ARG1 = '@ref(single mask)'})
GComponent.PROP('numChildren', 'int numChildren()')
GComponent.FUNC('resolve', [[
{
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

local GRoot = typeconf 'fairygui::GRoot'
GRoot.ATTR('showWindow', {RET = '@unref(cmp children)', ARG1 = '@ref(map children)'})
GRoot.ATTR('hideWindow', {RET = '@unref(cmp children parent)'})
GRoot.ATTR('hideWindowImmediately', {RET = '@unref(cmp children parent)'})
GRoot.ATTR('getTopWindow', {RET = '@ref(map children)'})
GRoot.ATTR('getModalWaitingPane', {RET = '@ref(map children)'})
GRoot.ATTR('getModalLayer', {RET = '@ref(map children)'})
GRoot.ATTR('showPopup', {RET = '@unref(cmp children)', ARG1 = '@ref(map children)'})
GRoot.ATTR('togglePopup', {RET = '@unref(cmp children)', ARG1 = '@ref(map children)'})
GRoot.ATTR('hidePopup', {RET = '@unref(cmp children)'})
GRoot.ATTR('getInputProcessor', {RET = '@ref(single inputProcessor)'})
GRoot.ATTR('worldToRoot', {ARG1 = '@pack'})
GRoot.ATTR('rootToWorld', {ARG1 = '@pack'})
GRoot.PROP('UIRoot', 'static GRoot* getInstance()')
GRoot.INJECT('create', {
    AFTER = [[
        olua_push_cppobj<cocos2d::Node>(L, ret->displayObject(), "cc.Node");
        olua_singleref(L, -1, "fgui.root", -2);
        olua_mapref(L, 1, "children", -1);
        lua_pop(L, 1);
    ]]
})

GRoot.INJECT({'hideWindow', 'hideWindowImmediately'}, {
    BEFORE = [[
        int parent = 1;
        if (arg1->getParent()) {
            olua_push_cppobj<fairygui::GComponent>(L, arg1->getParent(), "fgui.GComponent");
            parent = lua_gettop(L);
        }
    ]]
})

typeconf 'fairygui::GGroup'
typeconf 'fairygui::GScrollBar'

local GLoader = typeconf 'fairygui::GLoader'
GLoader.ATTR('getComponent', {RET = '@ref(single component)'})

local GTextField = typeconf 'fairygui::GTextField'
GTextField.FUNC('getTemplateVars', [[
{
    fairygui::GTextField *self = (fairygui::GTextField *)olua_toobj(L, 1, "fgui.GTextField");
    manual_olua_push_cocos2d_ValueMap(L, self->getTemplateVars());
    return 1;
}]])
GTextField.FUNC('setTemplateVars', [[
{
    cocos2d::ValueMap arg;
    fairygui::GTextField *self = (fairygui::GTextField *)olua_toobj(L, 1, "fgui.GTextField");
    manual_olua_check_cocos2d_ValueMap(L, 2, &arg);
    self->setTemplateVars(&arg);
    return 1;
}]])
GTextField.PROP('templateVars')

typeconf 'fairygui::GBasicTextField'

typeconf 'fairygui::GGraph'

local GButton = typeconf 'fairygui::GButton'
GButton.ATTR('getRelatedController', {RET = '@ref(single relatedController)'})
GButton.ATTR('setRelatedController', {ARG1 = '@ref(single relatedController)'})
GButton.ATTR('getTextField', {RET = '@ref(single textField)'})

typeconf 'fairygui::GImage'

local GLabel = typeconf 'fairygui::GLabel'
GLabel.ATTR('getTextField', {RET = '@ref(single textField)'})

local GList = typeconf 'fairygui::GList'
GList.ATTR('returnToPool', {ARG1 = '@unref(map children)'})
GList.ATTR('addItemFromPool', {RET = '@ref(map children)'})
GList.ATTR('removeChildToPoolAt', {RET = '@unref(cmp children)'})
GList.ATTR('removeChildToPool', {ARG1 = '@unref(map children)'})
GList.ATTR('removeChildrenToPool', {RET = '@unref(cmp children)'})
GList.ATTR('getSelectionController', {RET = '@ref(single selectionController)'})
GList.ATTR('setSelectionController', {ARG1 = '@ref(single selectionController)'})
GList.ATTR('setVirtual', {RET = '@unref(cmp children)'})
GList.ATTR('setVirtualAndLoop', {RET = '@unref(cmp children)'})
GList.ATTR('setNumItems', {RET = '@unref(cmp children)'})
GList.VAR('itemRenderer', 'std::function<void(int, GObject*)> itemRenderer')
GList.VAR('itemProvider', 'std::function<std::string(int)> itemProvider')
-- std::function<void(int, GObject*)> itemRenderer;
GList.ATTR('getSelection', {ARG1 = '@out'})
GList.INJECT('itemRenderer', {
    CALLBACK_BEFORE = [[
        if (arg2->getParent()) {
            olua_push_cppobj<fairygui::GComponent>(L, (fairygui::GComponent *)callback_store_obj);
            olua_mapref(L, -1, "children", -2);
            lua_pop(L, 1);
        }
    ]]
})

typeconf 'fairygui::GMovieClip'
typeconf 'fairygui::GProgressBar'

local GComboBox = typeconf 'fairygui::GComboBox'
GComboBox.ATTR('getSelectionController', {RET = '@ref(single selectionController)'})
GComboBox.ATTR('setSelectionController', {ARG1 = '@ref(single selectionController)'})
GComboBox.ATTR('getDropdown', {RET = '@ref(single dropdown)'})
GComboBox.ATTR('getTextField', {RET = '@ref(single textField)'})

typeconf 'fairygui::GRichTextField'
typeconf 'fairygui::GSlider'
typeconf 'fairygui::GTextInput'

local PopupMenu = typeconf 'fairygui::PopupMenu'
PopupMenu.ATTR('removeItem', {RET = '@unref(cmp children parent)'})
PopupMenu.ATTR('clearItems', {RET = '@unref(cmp children parent)'})
PopupMenu.ATTR('getContentPane', {RET = '@ref(single contentPane)'})
PopupMenu.ATTR('getList', {RET = '@ref(single list)'})
PopupMenu.ATTR('show', {RET = '@unref(cmp children parent)@ref(map children parent)'})
PopupMenu.CHUNK = [[
static int _fairygui_PopupMenu_addItemAt(lua_State *L);
]]
PopupMenu.FUNC('addItemAt', [[
{
    fairygui::PopupMenu *self = (fairygui::PopupMenu *)olua_toobj(L, 1, "fgui.PopupMenu");
    std::string caption = olua_checkstring(L, 2);
    int index = (int)olua_checkinteger(L, 3);
    fairygui::GButton *ret = (fairygui::GButton *)self->addItemAt(caption, index, nullptr);

    void *callback_store_obj = (void *)ret;
    std::string tag = makeListenerTag(L, fairygui::UIEventType::ClickMenu, 0);
    std::string func = olua_setcallback(L, callback_store_obj, tag.c_str(), 4, OLUA_TAG_NEW);
    std::function<void(fairygui::EventContext *)> callback = [callback_store_obj, func, tag](fairygui::EventContext *event) {
        lua_State *L = olua_mainthread();
        int top = lua_gettop(L);
        size_t last = olua_push_objpool(L);
        olua_enable_objpool(L);
        olua_push_cppobj<fairygui::EventContext>(L, event);
        olua_disable_objpool(L);
        olua_callback(L, callback_store_obj, func.c_str(), 1);
        
        //pop stack value
        olua_pop_objpool(L, last);
        
        lua_settop(L, top);
    };
    
    ret->addEventListener(fairygui::UIEventType::ClickMenu, callback);
    
    olua_push_cppobj<fairygui::GButton>(L, ret);
    olua_push_cppobj<fairygui::GComponent>(L, ret->getParent());
    olua_mapref(L, -1, "children", -2);
    lua_pop(L, 1);

    return 1;
}]])
PopupMenu.FUNC('addItem', [[
{
    fairygui::PopupMenu *self = (fairygui::PopupMenu *)olua_toobj(L, 1, "fgui.PopupMenu");
    lua_pushinteger(L, self->getList()->numChildren());
    lua_insert(L, -2);
    return _fairygui_PopupMenu_addItemAt(L);
}]])
-- void show()
-- void show(GObject* target, PopupDirection dir)
PopupMenu.INJECT('show', {
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
    ]]
})
-- bool removeItem(const std::string& name)
-- void clearItems()
PopupMenu.INJECT({'removeItem', 'clearItems'}, {
    BEFORE = [[
        olua_push_cppobj<fairygui::GList>(L, self->getList());
        int parent = lua_gettop(L);
    ]]
})

local Relations = typeconf 'fairygui::Relations'
Relations.FUNC('copyFrom', [[
{
    fairygui::Relations *self = (fairygui::Relations *)olua_toobj(L, 1, "fgui.Relations");
    fairygui::Relations *source = (fairygui::Relations *)olua_checkobj(L, 2, "fgui.Relations");
    // void copyFrom(const Relations& source)
    self->copyFrom(*source);
    
    return 0;
}]])

typeconf 'fairygui::RelationType'

local RelationItem = typeconf 'fairygui::RelationItem'
RelationItem.ATTR('getTarget', {RET = '@ref(single target)'})
RelationItem.ATTR('setTarget', {ARG1 = '@ref(single target)'})
RelationItem.FUNC('copyFrom', [[
{
    fairygui::RelationItem *self = (fairygui::RelationItem *)olua_toobj(L, 1, "fgui.RelationItem");
    fairygui::RelationItem *source = (fairygui::RelationItem *)olua_checkobj(L, 2, "fgui.RelationItem");
    // void copyFrom(const RelationItem& source)
    self->copyFrom(*source);
    
    return 0;
}]])

local ScrollPane = typeconf 'fairygui::ScrollPane'
ScrollPane.ATTR('getOwner', {RET = '@ref(single owner)'})
ScrollPane.ATTR('getHeader', {RET = '@ref(single header)'})
ScrollPane.ATTR('getFooter', {RET = '@ref(single footer)'})
ScrollPane.ATTR('getVtScrollBar', {RET = '@ref(single vtScrollBar)'})
ScrollPane.ATTR('getHzScrollBar', {RET = '@ref(single hzScrollBar)'})
ScrollPane.ATTR('getPageController', {RET = '@ref(single pageController)'})
ScrollPane.ATTR('setPageController', {ARG1 = '@ref(single pageController)'})

local Transition = typeconf 'fairygui::Transition'
Transition.ATTR('getOwner', {RET = '@ref(single owner)'})
Transition.CALLBACK {
    NAME = 'play',
    TAG_MAKER = 'play',
    TAG_MODE = 'OLUA_TAG_REPLACE',
}
Transition.CALLBACK {
    NAME = 'playReverse',
    TAG_MAKER = 'playReverse',
    TAG_MODE = 'OLUA_TAG_REPLACE',
}
Transition.CALLBACK {
    NAME = 'setHook',
    TAG_MAKER = '("hook." + #1)',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    NULLABLE = true,
}
Transition.CALLBACK {
    NAME = 'clearHooks',
    TAG_MAKER = '("hook.")',
    TAG_MODE = 'OLUA_TAG_SUBSTARTWITH',
    REMOVE = true,
}

typeconf 'fairygui::UIConfig'
    .ATTR('getRealFontName', {ARG2 = '@out'})
-- UIConfig.FUNC('getRealFontName', [[
-- {
--     bool isTTF = false;
--     std::string aliasName = olua_checkstring(L, 1);
--     std::string fontName = fairygui::UIConfig::getRealFontName(aliasName, &isTTF);
--     lua_pushstring(L, fontName.c_str());
--     lua_pushboolean(L, isTTF);
--     return 2;
-- }]])

typeconf 'fairygui::IUISource'
    .CALLBACK {NAME = 'load', NULLABLE = true}

local UISource = typeconf 'fairygui::UISource'
UISource.NOTCONF = true
UISource.SUPERCLS = 'fairygui::IUISource'
UISource.CHUNK = [[
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

    std::function<void()> _complete;
    std::string _name;
    bool _loaded;
};
NS_FGUI_END
]]
UISource.FUNC('create', 'static UISource *create()')
UISource.FUNC('loadComplete', 'void loadComplete()')

local Window = typeconf 'fairygui::Window'
Window.ATTR('show', {RET = '@unref(cmp children parent)@ref(map children parent)'})
Window.ATTR('hide', {RET = '@unref(cmp children parent)'})
Window.ATTR('hideImmediately', {RET = '@unref(cmp children parent)'})
Window.ATTR('getContentPane', {RET = '@ref(single contentPane)'})
Window.ATTR('setContentPane', {ARG1 = '@ref(single contentPane)'})
Window.ATTR('getFrame', {RET = '@ref(single frame)'})
Window.ATTR('getCloseButton', {RET = '@ref(single closeButton)'})
Window.ATTR('setCloseButton', {ARG1 = '@ref(single closeButton)'})
Window.ATTR('getDragArea', {RET = '@ref(single dragArea)'})
Window.ATTR('setDragArea', {ARG1 = '@ref(single dragArea)'})
Window.ATTR('getContentArea', {RET = '@ref(single contentArea)'})
Window.ATTR('setContentArea', {ARG1 = '@ref(single contentArea)'})
Window.ATTR('getModalWaitingPane', {RET = '@ref(single modalWaitingPane)'})
Window.INJECT('show', {
    BEFORE = [[
        fairygui::GComponent *root = fairygui::UIRoot;
        if (!root) {
            luaL_error(L, "no root to add 'Window'");
        }
        olua_push_cppobj<fairygui::GComponent>(L, root);
        int parent = lua_gettop(L);
    ]]
})
Window.INJECT({'hide', 'hideImmediately'}, {
    BEFORE = [[
        fairygui::GComponent *root = self->getParent() ? self->getParent() : fairygui::UIRoot;
        if (!root) {
            return 0;
        }
        olua_push_cppobj<fairygui::GComponent>(L, root);
        int parent = lua_gettop(L);
    ]]
})

typeconf 'fairygui::DragDropManager'
typeconf 'fairygui::UIObjectFactory'

local GearBase = typeconf 'fairygui::GearBase'
GearBase.EXCLUDE 'getController'
GearBase.EXCLUDE 'setController'
GearBase.EXCLUDE 'getTweenConfig'
GearBase.EXCLUDE 'updateFromRelations'
GearBase.EXCLUDE 'apply'
GearBase.EXCLUDE 'updateState'
GearBase.EXCLUDE 'setup'

local GTreeNode = typeconf 'fairygui::GTreeNode'
GTreeNode.ATTR('getCell', {RET = '@ref(single cell)'})
GTreeNode.ATTR('addChild', {ARG1 = '@ref(map children)'})
GTreeNode.ATTR('addChildAt', {ARG1 = '@ref(map children)'})
GTreeNode.ATTR('removeChild', {ARG1 = '@unref(map children)'})
GTreeNode.ATTR('removeChildAt', {RET ='@unref(cmp children)'})
GTreeNode.ATTR('removeChildren', {RET ='@unref(cmp children)'})
GTreeNode.ATTR('getChildAt', {RET = '@ref(map children)'})
GTreeNode.ATTR('getPrevSibling', {RET = '@ref(map children)'})
GTreeNode.ATTR('getNextSibling', {RET = '@ref(map children)'})
GTreeNode.PROP('numChildren', 'int numChildren()')

local GTree = typeconf 'fairygui::GTree'
GTree.ATTR('getList', {RET = '@ref(single list)'})
GTree.ATTR('getRootNode', {RET = '@ref(single rootNode)'})
GTree.CALLBACK {NAME = 'treeNodeRender', LOCAL = false}
GTree.CALLBACK {NAME = 'treeNodeWillExpand', LOCAL = false}
GTree.ATTR('getSelectedNodes', {ARG1 = '@out'})

typeconf 'fairygui::FUIContainer'
typeconf 'fairygui::FUIInput'
typeconf 'fairygui::FUILabel'
typeconf 'fairygui::FUIRichText'
typeconf 'fairygui::FUISprite'

return M