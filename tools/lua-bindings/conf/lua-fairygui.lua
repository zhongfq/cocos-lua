local autoconf = require "autoconf"
local M = autoconf.typemod 'fairygui'
local typeconf = M.typeconf
local typeconv = M.typeconv
local typedef = M.typedef
local typeonly = M.typeonly

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
}]]

M.EXCLUDE_TYPE = require "conf.exclude-type"
M.EXCLUDE_TYPE 'fairygui::ByteBuffer *'
M.EXCLUDE_TYPE 'fairygui::GObjectPool *'
M.EXCLUDE_TYPE 'fairygui::GObjectPool'
M.EXCLUDE_TYPE 'std::vector *'

M.MAKE_LUACLS = function (cppname)
    cppname = string.gsub(cppname, '^fairygui::', 'fgui.')
    return cppname
end

typedef {
    CPPCLS = 'fairygui::EventTag',
    CONV = 'manual_olua_$$_fairygui_EventTag',
}

typeconv 'fairygui::Margin'
typeconv 'fairygui::HtmlParseOptions'

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
}
UIEventDispatcher.CALLBACK {
    NAME = 'removeEventListeners',
    TAG_MAKER = 'makeListenerTag(L, -1, 0)',
    TAG_MODE = 'OLUA_TAG_SUBSTARTWITH',
}

typeconf 'fairygui::EventContext'
typeconf 'fairygui::IHitTest'
typeconf 'fairygui::PixelHitTest'
typeconf 'fairygui::PixelHitTestData'

typeconf 'fairygui::InputProcessor'
    .CALLBACK {NAME = 'setCaptureCallback', NULLABLE = true}

typeconf 'fairygui::InputEvent'
typeconf 'fairygui::TextFormat'
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
static bool should_del_tweener_ref(lua_State *L, int idx)
{
    if (olua_isa<fairygui::GTweener>(L, idx)) {
        fairygui::GTweener *obj = olua_toobj<fairygui::GTweener>(L, idx);
        if (obj->getReferenceCount() == 1 || obj->allCompleted()) {
            return true;
        }
    }
    return false;
}]]
local DELREF_TWEEN = {
    AFTER = [[
        olua_pushclassobj<fairygui::GTween>(L);
        olua_visitrefs(L, -1, "tweeners", should_del_tweener_ref);
        lua_pop(L, 1);
    ]]
}
local REF_TEWEENER = {
    AFTER = [[
        olua_pushclassobj<fairygui::GTween>(L);
        olua_addref(L, -1, "tweeners", -2, OLUA_MODE_MULTIPLE);
        olua_visitrefs(L, -1, "tweeners", should_del_tweener_ref);
        lua_pop(L, 1);
    ]]
}
GTween.INSERT('to', REF_TEWEENER)
GTween.INSERT('toColor', REF_TEWEENER)
GTween.INSERT('toDouble', REF_TEWEENER)
GTween.INSERT('delayedCall', REF_TEWEENER)
GTween.INSERT('shake', REF_TEWEENER)
GTween.INSERT('kill', DELREF_TWEEN)
GTween.INSERT('clean', {
    AFTER = [[
        olua_pushclassobj<fairygui::GTween>(L);
        olua_delallrefs(L, -1, "tweeners");
        lua_pop(L, 1);
    ]]
})

typeconf 'fairygui::UIPackage'

typeconf 'fairygui::PackageItem'
    .EXCLUDE_FUNC 'rawData'
    .EXCLUDE_FUNC 'pixelHitTestData'
    .EXCLUDE_FUNC 'extensionCreator'
    .EXCLUDE_FUNC 'bitmapFont'
    .EXCLUDE_FUNC 'scale9Grid'

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
GObject.EXCLUDE_FUNC 'constructFromResource'
GObject.ATTR('getGroup', {RET = '@addref(group ^)'})
GObject.ATTR('setGroup', {ARG1 = '@addref(group ^)'})
GObject.ATTR('globalToLocal', {ARG1 = '@pack'})
GObject.ATTR('localToGlobal', {ARG1 = '@pack'})
GObject.ATTR('transformRect', {ARG1 = '@pack'})
GObject.ATTR('displayObject', {RET = '@addref(displayObject ^)'})
GObject.PROP('relations', 'Relations* relations()')
GObject.PROP('displayObject', 'cocos2d::Node* displayObject()')
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
}
GObject.INSERT('center', {
    BEFORE = [[
        if (!self->getParent() && !fairygui::UIRoot) {
            luaL_error(L, "UIRoot and parent are both nullptr");
        }
    ]]
})
GObject.INSERT('makeFullScreen', {
    BEFORE = [[
        if (!fairygui::UIRoot) {
            luaL_error(L, "UIRoot is nullptr");
        }
    ]]
})

local GComponent = typeconf 'fairygui::GComponent'
GComponent.CHUNK = [[
static int _fairygui_GComponent_getController(lua_State *L);
static int _fairygui_GComponent_getTransition(lua_State *L);
static int _fairygui_GComponent_getChild(lua_State *L);
]]
GComponent.EXCLUDE_FUNC 'getChildByPath'
GComponent.ALIAS('resolve', 'getChildByPath')
GComponent.ATTR('addChild', {ARG1 = '@addref(children |)'})
GComponent.ATTR('addChildAt', {ARG1 = '@addref(children |)'})
GComponent.ATTR('removeChild', {ARG1 = '@delref(children |)'})
GComponent.ATTR('removeChildAt', {RET = '@delref(children ~)'})
GComponent.ATTR('removeChildren', {RET = '@delref(children ~)'})
GComponent.ATTR('getChildAt', {RET = '@addref(children |)'})
GComponent.ATTR('getChild', {RET = '@addref(children |)'})
GComponent.ATTR('getChildInGroup', {RET = '@addref(children |)'})
GComponent.ATTR('getChildById', {RET = '@addref(children |)'})
GComponent.ATTR('getChildren', {RET = '@addref(children |)'})
GComponent.ATTR('addController', {ARG1 = '@addref(controllers |)'})
GComponent.ATTR('getControllerAt', {RET = '@addref(controllers |)'})
GComponent.ATTR('getController', {RET = '@addref(controllers |)'})
GComponent.ATTR('getControllers', {RET = '@addref(controllers |)'})
GComponent.ATTR('removeController', {ARG1 = '@delref(controllers |)'})
GComponent.ATTR('getTransition', {RET = '@addref(transitions |)'})
GComponent.ATTR('getTransitionAt', {RET = '@addref(transitions |)'})
GComponent.ATTR('getTransitions', {RET = '@addref(transitions |)'})
GComponent.ATTR('getMask', {RET = '@addref(mask ^)'})
GComponent.ATTR('setMask', {ARG1 = '@addref(mask ^)'})
GComponent.PROP('numChildren', 'int numChildren()')
GComponent.FUNC('resolve', [[
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
}]])

local GRoot = typeconf 'fairygui::GRoot'
GRoot.ATTR('showWindow', {RET = '@delref(children ~)', ARG1 = '@addref(children |)'})
GRoot.ATTR('hideWindow', {RET = '@delref(children ~ parent)'})
GRoot.ATTR('hideWindowImmediately', {RET = '@delref(children ~ parent)'})
GRoot.ATTR('getTopWindow', {RET = '@addref(children |)'})
GRoot.ATTR('getModalWaitingPane', {RET = '@addref(children |)'})
GRoot.ATTR('getModalLayer', {RET = '@addref(children |)'})
GRoot.ATTR('showPopup', {RET = '@delref(children ~)', ARG1 = '@addref(children |)'})
GRoot.ATTR('togglePopup', {RET = '@delref(children ~)', ARG1 = '@addref(children |)'})
GRoot.ATTR('hidePopup', {RET = '@delref(children ~)'})
GRoot.ATTR('getInputProcessor', {RET = '@addref(inputProcessor ^)'})
GRoot.PROP('UIRoot', 'static GRoot* getInstance()')
GRoot.INSERT('create', {
    AFTER = [[
        olua_push_cppobj<cocos2d::Node>(L, ret->displayObject());
        olua_addref(L, -1, "fgui.root", -2, OLUA_MODE_SINGLE);
        olua_addref(L, 1, "children", -1, OLUA_MODE_MULTIPLE);
        lua_pop(L, 1);
    ]]
})

GRoot.INSERT({'hideWindow', 'hideWindowImmediately'}, {
    BEFORE = [[
        int parent = 1;
        if (arg1->getParent()) {
            olua_push_cppobj<fairygui::GComponent>(L, arg1->getParent());
            parent = lua_gettop(L);
        }
    ]]
})

typeconf 'fairygui::GGroup'
typeconf 'fairygui::GScrollBar'

typeconf 'fairygui::GLoader'
    .ATTR('getComponent', {RET = '@addref(component ^)'})

typeconf 'fairygui::GLoader3D'
    .ATTR('getContent', {RET = '@addref(content ^)'})
    .ATTR('setContent', {ARG1 = '@addref(content ^)'})

typeconf 'fairygui::GTextField'
typeconf 'fairygui::GBasicTextField'
typeconf 'fairygui::GGraph'

typeconf 'fairygui::GButton'
    .ATTR('getRelatedController', {RET = '@addref(relatedController ^)'})
    .ATTR('setRelatedController', {ARG1 = '@addref(relatedController ^)'})
    .ATTR('getTextField', {RET = '@addref(textField ^)'})

typeconf 'fairygui::GImage'

typeconf 'fairygui::GLabel'
    .ATTR('getTextField', {RET = '@addref(textField ^)'})

local GList = typeconf 'fairygui::GList'
GList.ATTR('returnToPool', {ARG1 = '@delref(children |)'})
GList.ATTR('addItemFromPool', {RET = '@addref(children |)'})
GList.ATTR('removeChildToPoolAt', {RET = '@delref(children ~)'})
GList.ATTR('removeChildToPool', {ARG1 = '@delref(children |)'})
GList.ATTR('removeChildrenToPool', {RET = '@delref(children ~)'})
GList.ATTR('getSelectionController', {RET = '@addref(selectionController ^)'})
GList.ATTR('setSelectionController', {ARG1 = '@addref(selectionController ^)'})
GList.ATTR('setVirtual', {RET = '@delref(children ~)'})
GList.ATTR('setVirtualAndLoop', {RET = '@delref(children ~)'})
GList.ATTR('setNumItems', {RET = '@delref(children ~)'})
GList.ATTR('getSelection', {ARG1 = '@out'})
GList.CALLBACK {NAME = 'itemRenderer', LOCAL = false}
-- std::function<void(int, GObject*)> itemRenderer;
GList.INSERT('itemRenderer', {
    CALLBACK_BEFORE = [[
        if (arg2->getParent()) {
            olua_push_cppobj<fairygui::GComponent>(L, (fairygui::GComponent *)cb_store);
            olua_addref(L, -1, "children", -2, OLUA_MODE_MULTIPLE);
            lua_pop(L, 1);
        }
    ]]
})

typeconf 'fairygui::GMovieClip'
typeconf 'fairygui::GProgressBar'

typeconf 'fairygui::GComboBox'
    .ATTR('getSelectionController', {RET = '@addref(selectionController ^)'})
    .ATTR('setSelectionController', {ARG1 = '@addref(selectionController ^)'})
    .ATTR('getDropdown', {RET = '@addref(dropdown ^)'})
    .ATTR('getTextField', {RET = '@addref(textField ^)'})

typeconf 'fairygui::GRichTextField'
typeconf 'fairygui::GSlider'
typeconf 'fairygui::GTextInput'

local PopupMenu = typeconf 'fairygui::PopupMenu'
PopupMenu.ATTR('addItem', {RET = '@addref(children | parent)'})
PopupMenu.ATTR('addItemAt', {RET = '@addref(children | parent)'})
PopupMenu.ATTR('removeItem', {RET = '@delref(children ~ parent)'})
PopupMenu.ATTR('clearItems', {RET = '@delref(children ~ parent)'})
PopupMenu.ATTR('getContentPane', {RET = '@addref(contentPane ^)'})
PopupMenu.ATTR('getList', {RET = '@addref(list ^)'})
PopupMenu.ATTR('show', {RET = '@delref(children ~ parent)@addref(children | parent)'})
PopupMenu.CALLBACK {
    NAME = 'addItem',
    TAG_MAKER = 'makeListenerTag(L, fairygui::UIEventType::ClickMenu, 0)',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = 'return',
}
PopupMenu.CALLBACK {
    NAME = 'addItemAt',
    TAG_MAKER = 'makeListenerTag(L, fairygui::UIEventType::ClickMenu, 0)',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = 'return',
}
-- void show()
-- void show(GObject* target, PopupDirection dir)
PopupMenu.INSERT('show', {
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
    ]]
})
-- bool removeItem(const std::string& name)
-- void clearItems()
-- GButton* addItem(const std::string& caption, EventCallback callback);
-- GButton* addItemAt(const std::string& caption, int index, EventCallback callback);
PopupMenu.INSERT({'removeItem', 'clearItems', 'addItem', 'addItemAt'}, {
    BEFORE = [[
        olua_push_cppobj<fairygui::GList>(L, self->getList());
        int parent = lua_gettop(L);
    ]]
})

typeconf 'fairygui::Relations'
typeconf 'fairygui::RelationType'

typeconf 'fairygui::RelationItem'
    .ATTR('getTarget', {RET = '@addref(target ^)'})
    .ATTR('setTarget', {ARG1 = '@addref(target ^)'})

typeconf 'fairygui::ScrollPane'
    .ATTR('getOwner', {RET = '@addref(owner ^)'})
    .ATTR('getHeader', {RET = '@addref(header ^)'})
    .ATTR('getFooter', {RET = '@addref(footer ^)'})
    .ATTR('getVtScrollBar', {RET = '@addref(vtScrollBar ^)'})
    .ATTR('getHzScrollBar', {RET = '@addref(hzScrollBar ^)'})
    .ATTR('getPageController', {RET = '@addref(pageController ^)'})
    .ATTR('setPageController', {ARG1 = '@addref(pageController ^)'})

local Transition = typeconf 'fairygui::Transition'
Transition.ATTR('getOwner', {RET = '@addref(owner ^)'})
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
}

typeconf 'fairygui::UIConfig'
    .ATTR('getRealFontName', {ARG2 = '@out'})

typeconf 'fairygui::IUISource'
    .CALLBACK {NAME = 'load', NULLABLE = true}

local UISource = typeconf 'fairygui::UISource'
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

    bool _loaded;
    std::function<void()> _complete;
    std::string _name;
};
NS_FGUI_END
]]
UISource.FUNC('create', 'static UISource *create()')
UISource.FUNC('loadComplete', 'void loadComplete()')

local Window = typeconf 'fairygui::Window'
Window.ATTR('show', {RET = '@delref(children ~ parent)@addref(children | parent)'})
Window.ATTR('hide', {RET = '@delref(children ~ parent)'})
Window.ATTR('hideImmediately', {RET = '@delref(children ~ parent)'})
Window.ATTR('getContentPane', {RET = '@addref(contentPane ^)'})
Window.ATTR('setContentPane', {ARG1 = '@addref(contentPane ^)'})
Window.ATTR('getFrame', {RET = '@addref(frame ^)'})
Window.ATTR('getCloseButton', {RET = '@addref(closeButton ^)'})
Window.ATTR('setCloseButton', {ARG1 = '@addref(closeButton ^)'})
Window.ATTR('getDragArea', {RET = '@addref(dragArea ^)'})
Window.ATTR('setDragArea', {ARG1 = '@addref(dragArea ^)'})
Window.ATTR('getContentArea', {RET = '@addref(contentArea ^)'})
Window.ATTR('setContentArea', {ARG1 = '@addref(contentArea ^)'})
Window.ATTR('getModalWaitingPane', {RET = '@addref(modalWaitingPane ^)'})
Window.INSERT('show', {
    BEFORE = [[
        fairygui::GComponent *root = fairygui::UIRoot;
        if (!root) {
            luaL_error(L, "no root to add 'Window'");
        }
        olua_push_cppobj<fairygui::GComponent>(L, root);
        int parent = lua_gettop(L);
    ]]
})
Window.INSERT({'hide', 'hideImmediately'}, {
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

typeconf 'fairygui::GearBase'
    .EXCLUDE_FUNC 'getController'
    .EXCLUDE_FUNC 'setController'
    .EXCLUDE_FUNC 'getTweenConfig'
    .EXCLUDE_FUNC 'updateFromRelations'
    .EXCLUDE_FUNC 'apply'
    .EXCLUDE_FUNC 'updateState'
    .EXCLUDE_FUNC 'setup'

typeconf 'fairygui::GTreeNode'
    .ATTR('getCell', {RET = '@addref(cell ^)'})
    .ATTR('addChild', {ARG1 = '@addref(children |)'})
    .ATTR('addChildAt', {ARG1 = '@addref(children |)'})
    .ATTR('removeChild', {ARG1 = '@delref(children |)'})
    .ATTR('removeChildAt', {RET ='@delref(children ~)'})
    .ATTR('removeChildren', {RET ='@delref(children ~)'})
    .ATTR('getChildAt', {RET = '@addref(children |)'})
    .ATTR('getPrevSibling', {RET = '@addref(children |)'})
    .ATTR('getNextSibling', {RET = '@addref(children |)'})
    .PROP('numChildren', 'int numChildren()')

local GTree = typeconf 'fairygui::GTree'
GTree.ATTR('getList', {RET = '@addref(list ^)'})
GTree.ATTR('getRootNode', {RET = '@addref(rootNode ^)'})
GTree.ATTR('getSelectedNodes', {ARG1 = '@out'})
GTree.CALLBACK {NAME = 'treeNodeRender', LOCAL = false}
GTree.CALLBACK {NAME = 'treeNodeWillExpand', LOCAL = false}

typeconf 'fairygui::FUIContainer'
typeconf 'fairygui::FUIInput'

typeconf 'fairygui::FUILabel'
    .EXCLUDE_FUNC 'setBMFontFilePath'

typeconf 'fairygui::FUIRichText'
typeconf 'fairygui::FUISprite'
typeconf 'fairygui::HtmlObject'
typeconf 'fairygui::HtmlElement::Type'
typeconf 'fairygui::HtmlElement'

return M