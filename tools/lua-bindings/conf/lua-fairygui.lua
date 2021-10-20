module 'fairygui'

path = "../../frameworks/libxgame/src/lua-bindings"

headers = [[
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "cclua/xlua.h"
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
}]]

make_luacls = function (cppname)
    cppname = string.gsub(cppname, '^fairygui::', 'fgui.')
    return cppname
end

include "conf/exclude-type.lua"

exclude 'fairygui::ByteBuffer *'
exclude 'fairygui::GObjectPool *'
exclude 'fairygui::GObjectPool'
exclude 'std::vector *'

typedef 'fairygui::EventTag'

typeconv 'fairygui::Margin'
typeconv 'fairygui::HtmlParseOptions'

typeconv 'fairygui::TweenValue'
    .attr('*', {optional = true})

typeconf 'fairygui::UIEventType'
typeconf 'fairygui::EventCallback'

typeconf 'fairygui::UIEventDispatcher'
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
                sprintf(buf, "listeners.");
            } else if (tag > 0) {
                sprintf(buf, "listeners.%d.%p", (int)type, (void *)tag);
            } else {
                sprintf(buf, "listeners.%d.", (int)type);
            }
            return std::string(buf);
        }
    ]])
    .callback {
        name = 'addEventListener',
        tag_maker = {'makeListenerTag(L, #1, 0)', 'makeListenerTag(L, #1, 4)'},
        tag_mode = 'OLUA_TAG_NEW',
    }
    .callback {
        name = 'removeEventListener',
        tag_maker = {'makeListenerTag(L, #1, 0)', 'makeListenerTag(L, #1, 3)'},
        tag_mode = {'OLUA_TAG_SUBSTARTWITH', 'OLUA_TAG_SUBEQUAL'},
    }
    .callback {
        name = 'removeEventListeners',
        tag_maker = 'makeListenerTag(L, -1, 0)',
        tag_mode = 'OLUA_TAG_SUBSTARTWITH',
    }

typeconf 'fairygui::EventContext'
typeconf 'fairygui::IHitTest'
typeconf 'fairygui::PixelHitTest'
typeconf 'fairygui::PixelHitTestData'

typeconf 'fairygui::InputProcessor::CaptureEventCallback'

typeconf 'fairygui::InputProcessor'
    .callback {name = 'setCaptureCallback', nullable = true}

typeconf 'fairygui::InputEvent'
typeconf 'fairygui::TextFormat'
typeconf 'fairygui::EaseType'
typeconf 'fairygui::EaseManager'
typeconf 'fairygui::TweenPropType'
typeonly 'fairygui::GPath'

typeconf 'fairygui::GTweener::GTweenCallback'
typeconf 'fairygui::GTweener::GTweenCallback0'

typeconf 'fairygui::GTweener'
    .callback {name = 'onUpdate', localvar = false}
    .callback {name = 'onStart', localvar = false}
    .callback {name = 'onComplete', localvar = false}
    .callback {name = 'onComplete1', localvar = false}

local DELREF_TWEEN = {
    after = [[
        olua_pushclassobj<fairygui::GTween>(L);
        olua_visitrefs(L, -1, "tweeners", should_del_tweener_ref);
        lua_pop(L, 1);
    ]]
}
local REF_TEWEENER = {
    after = [[
        olua_pushclassobj<fairygui::GTween>(L);
        olua_addref(L, -1, "tweeners", -2, OLUA_MODE_MULTIPLE);
        olua_visitrefs(L, -1, "tweeners", should_del_tweener_ref);
        lua_pop(L, 1);
    ]]
}

typeconf 'fairygui::GTween'
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
    .insert('to', REF_TEWEENER)
    .insert('toColor', REF_TEWEENER)
    .insert('toDouble', REF_TEWEENER)
    .insert('delayedCall', REF_TEWEENER)
    .insert('shake', REF_TEWEENER)
    .insert('kill', DELREF_TWEEN)
    .insert('clean', {
        after = [[
            olua_pushclassobj<fairygui::GTween>(L);
            olua_delallrefs(L, -1, "tweeners");
            lua_pop(L, 1);
        ]]
    })

typeconf 'fairygui::UIPackage'

typeconf 'fairygui::PackageItem'
    .exclude 'rawData'
    .exclude 'pixelHitTestData'
    .exclude 'extensionCreator'
    .exclude 'bitmapFont'
    .exclude 'scale9Grid'

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

typeconf 'fairygui::GObject'
    .exclude 'constructFromResource'
    .attr('getGroup', {ret = '@addref(group ^)'})
    .attr('setGroup', {arg1 = '@addref(group ^)'})
    .attr('globalToLocal', {arg1 = '@pack'})
    .attr('localToGlobal', {arg1 = '@pack'})
    .attr('transformRect', {arg1 = '@pack'})
    .attr('displayObject', {ret = '@addref(displayObject ^)'})
    .prop('relations', 'Relations* relations()')
    .prop('displayObject', 'cocos2d::Node* displayObject()')
    .callback {
        name = 'addClickListener',
        tag_maker = {
            'makeListenerTag(L, fairygui::UIEventType::Click, 0)', -- no tag
            'makeListenerTag(L, fairygui::UIEventType::Click, 3)', -- tag stack idx
        },
        tag_mode = 'OLUA_TAG_NEW',
    }
    .callback {
        name = 'removeClickListener',
        tag_maker = 'makeListenerTag(L, fairygui::UIEventType::Click, 2)',
        tag_mode = 'OLUA_TAG_SUBEQUAL',
    }
    .insert('center', {
        before = [[
            if (!self->getParent() && !fairygui::UIRoot) {
                luaL_error(L, "UIRoot and parent are both nullptr");
            }
        ]]
    })
    .insert('makeFullScreen', {
        before = [[
            if (!fairygui::UIRoot) {
                luaL_error(L, "UIRoot is nullptr");
            }
        ]]
    })

typeconf 'fairygui::GComponent'
    .chunk([[
        static int _fairygui_GComponent_getController(lua_State *L);
        static int _fairygui_GComponent_getTransition(lua_State *L);
        static int _fairygui_GComponent_getChild(lua_State *L);
    ]])
    .exclude 'getChildByPath'
    .alias('resolve', 'getChildByPath')
    .attr('addChild', {arg1 = '@addref(children |)'})
    .attr('addChildAt', {arg1 = '@addref(children |)'})
    .attr('removeChild', {arg1 = '@delref(children |)'})
    .attr('removeChildAt', {ret = '@delref(children ~)'})
    .attr('removeChildren', {ret = '@delref(children ~)'})
    .attr('getChildAt', {ret = '@addref(children |)'})
    .attr('getChild', {ret = '@addref(children |)'})
    .attr('getChildInGroup', {ret = '@addref(children |)'})
    .attr('getChildById', {ret = '@addref(children |)'})
    .attr('getChildren', {ret = '@addref(children |)'})
    .attr('addController', {arg1 = '@addref(controllers |)'})
    .attr('getControllerAt', {ret = '@addref(controllers |)'})
    .attr('getController', {ret = '@addref(controllers |)'})
    .attr('getControllers', {ret = '@addref(controllers |)'})
    .attr('removeController', {arg1 = '@delref(controllers |)'})
    .attr('getTransition', {ret = '@addref(transitions |)'})
    .attr('getTransitionAt', {ret = '@addref(transitions |)'})
    .attr('getTransitions', {ret = '@addref(transitions |)'})
    .attr('getMask', {ret = '@addref(mask ^)'})
    .attr('setMask', {arg1 = '@addref(mask ^)'})
    .prop('numChildren', 'int numChildren()')
    .func('__index', [[
        {
            auto self = olua_toobj<fairygui::GComponent>(L, 1);
            if (olua_isstring(L, 2)) {
                fairygui::GObject *child = self->getChild(olua_tostring(L, 2));
                if (child) {
                    olua_pushobj<fairygui::GObject>(L, child);
                    olua_addref(L, 1, "children", -1, OLUA_MODE_MULTIPLE);
                    return 1;
                }
            }
            lua_settop(L, 2);
            olua_getvariable(L, 1);
            return 1;
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

typeconf 'fairygui::GRoot'
    .attr('showWindow', {ret = '@delref(children ~)', arg1 = '@addref(children |)'})
    .attr('hideWindow', {ret = '@delref(children ~ parent)'})
    .attr('hideWindowImmediately', {ret = '@delref(children ~ parent)'})
    .attr('getTopWindow', {ret = '@addref(children |)'})
    .attr('getModalWaitingPane', {ret = '@addref(children |)'})
    .attr('getModalLayer', {ret = '@addref(children |)'})
    .attr('showPopup', {ret = '@delref(children ~)', arg1 = '@addref(children |)'})
    .attr('togglePopup', {ret = '@delref(children ~)', arg1 = '@addref(children |)'})
    .attr('hidePopup', {ret = '@delref(children ~)'})
    .attr('getInputProcessor', {ret = '@addref(inputProcessor ^)'})
    .attr('worldToRoot', {arg1 = '@pack'})
    .attr('rootToWorld', {arg1 = '@pack'})
    .prop('UIRoot', 'static GRoot* getInstance()')
    .insert('create', {
        after = [[
            olua_push_cppobj<cocos2d::Node>(L, ret->displayObject());
            olua_addref(L, -1, "fgui.root", -2, OLUA_MODE_SINGLE);
            olua_addref(L, 1, "children", -1, OLUA_MODE_MULTIPLE);
            lua_pop(L, 1);
        ]]
    })
    .insert({'hideWindow', 'hideWindowImmediately'}, {
        before = [[
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
    .attr('getComponent', {ret = '@addref(component ^)'})

typeconf 'fairygui::GLoader3D'
    .attr('getContent', {ret = '@addref(content ^)'})
    .attr('setContent', {arg1 = '@addref(content ^)'})

typeconf 'fairygui::GTextField'
typeconf 'fairygui::GBasicTextField'

typeconf 'fairygui::GGraph'
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
            olua_check_std_vector<cocos2d::Vec2>(L, 5, &points, [L](cocos2d::Vec2 *value) {
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
                olua_check_std_vector<float>(L, 7, &distances, [L](float *value) {
                    *value = (float)olua_checknumber(L, -1);
                });
                self->drawRegularPolygon((int)lineSize, lineColor, fillColor, (int)sides, (float)startAngle, distances.size() ? &distances[0] : nullptr, (int)distances.size());
            }
            
            return 0;
        }
    ]])

typeconf 'fairygui::GButton'
    .attr('getRelatedController', {ret = '@addref(relatedController ^)'})
    .attr('setRelatedController', {arg1 = '@addref(relatedController ^)'})
    .attr('getTextField', {ret = '@addref(textField ^)'})

typeconf 'fairygui::GImage'

typeconf 'fairygui::GLabel'
    .attr('getTextField', {ret = '@addref(textField ^)'})

typeconf 'fairygui::GList::ListItemRenderer'
typeconf 'fairygui::GList::ListItemProvider'

typeconf 'fairygui::GList'
    .attr('returnToPool', {arg1 = '@delref(children |)'})
    .attr('addItemFromPool', {ret = '@addref(children |)'})
    .attr('removeChildToPoolAt', {ret = '@delref(children ~)'})
    .attr('removeChildToPool', {arg1 = '@delref(children |)'})
    .attr('removeChildrenToPool', {ret = '@delref(children ~)'})
    .attr('getSelectionController', {ret = '@addref(selectionController ^)'})
    .attr('setSelectionController', {arg1 = '@addref(selectionController ^)'})
    .attr('setVirtual', {ret = '@delref(children ~)'})
    .attr('setVirtualAndLoop', {ret = '@delref(children ~)'})
    .attr('setNumItems', {ret = '@delref(children ~)'})
    .attr('getSelection', {arg1 = '@ret'})
    .callback {name = 'itemRenderer', localvar = false}
    .insert('itemRenderer', {
        callback_before = [[
            olua_push_cppobj<fairygui::GComponent>(L, (fairygui::GComponent *)cb_store);
            olua_addref(L, -1, "children", top + 2, OLUA_MODE_MULTIPLE);
            lua_pop(L, 1);
        ]]
    })

typeconf 'fairygui::GMovieClip'
typeconf 'fairygui::GProgressBar'

typeconf 'fairygui::GComboBox'
    .attr('getSelectionController', {ret = '@addref(selectionController ^)'})
    .attr('setSelectionController', {arg1 = '@addref(selectionController ^)'})
    .attr('getDropdown', {ret = '@addref(dropdown ^)'})
    .attr('getTextField', {ret = '@addref(textField ^)'})

typeconf 'fairygui::GRichTextField'
typeconf 'fairygui::GSlider'
typeconf 'fairygui::GTextInput'

typeconf 'fairygui::PopupMenu'
    .attr('addItem', {ret = '@addref(children | parent)'})
    .attr('addItemAt', {ret = '@addref(children | parent)'})
    .attr('removeItem', {ret = '@delref(children ~ parent)'})
    .attr('clearItems', {ret = '@delref(children ~ parent)'})
    .attr('getContentPane', {ret = '@addref(contentPane ^)'})
    .attr('getList', {ret = '@addref(list ^)'})
    .attr('show', {ret = '@delref(children ~ parent)@addref(children | parent)'})
    .callback {
        name = 'addItem',
        tag_maker = 'makeListenerTag(L, fairygui::UIEventType::ClickMenu, 0)',
        tag_mode = 'OLUA_TAG_REPLACE',
        tag_store = 'return',
    }
    .callback {
        name = 'addItemAt',
        tag_maker = 'makeListenerTag(L, fairygui::UIEventType::ClickMenu, 0)',
        tag_mode = 'OLUA_TAG_REPLACE',
        tag_store = 'return',
    }
    -- void show()
    -- void show(GObject* target, PopupDirection dir)
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
        ]]
    })
    -- bool removeItem(const std::string& name)
    -- void clearItems()
    -- GButton* addItem(const std::string& caption, EventCallback callback);
    -- GButton* addItemAt(const std::string& caption, int index, EventCallback callback);
    .insert({'removeItem', 'clearItems', 'addItem', 'addItemAt'}, {
        before = [[
            olua_push_cppobj<fairygui::GList>(L, self->getList());
            int parent = lua_gettop(L);
        ]]
    })

typeconf 'fairygui::Relations'
typeconf 'fairygui::RelationType'

typeconf 'fairygui::RelationItem'
    .attr('getTarget', {ret = '@addref(target ^)'})
    .attr('setTarget', {arg1 = '@addref(target ^)'})

typeconf 'fairygui::ScrollPane'
    .attr('getOwner', {ret = '@addref(owner ^)'})
    .attr('getHeader', {ret = '@addref(header ^)'})
    .attr('getFooter', {ret = '@addref(footer ^)'})
    .attr('getVtScrollBar', {ret = '@addref(vtScrollBar ^)'})
    .attr('getHzScrollBar', {ret = '@addref(hzScrollBar ^)'})
    .attr('getPageController', {ret = '@addref(pageController ^)'})
    .attr('setPageController', {arg1 = '@addref(pageController ^)'})

typeconf 'fairygui::Transition::PlayCompleteCallback'
typeconf 'fairygui::Transition::TransitionHook'

typeconf 'fairygui::Transition'
    .attr('getOwner', {ret = '@addref(owner ^)'})
    .callback {
        name = 'play',
        tag_maker = 'play',
        tag_mode = 'OLUA_TAG_REPLACE',
    }
    .callback {
        name = 'playReverse',
        tag_maker = 'playReverse',
        tag_mode = 'OLUA_TAG_REPLACE',
    }
    .callback {
        name = 'setHook',
        tag_maker = '("hook." + #1)',
        tag_mode = 'OLUA_TAG_REPLACE',
        nullable = true,
    }
    .callback {
        name = 'clearHooks',
        tag_maker = '("hook.")',
        tag_mode = 'OLUA_TAG_SUBSTARTWITH',
    }

typeconf 'fairygui::UIConfig'
    .attr('getRealFontName', {arg2 = '@ret'})

typeconf 'fairygui::IUISource'
    .callback {name = 'load', nullable = true}

typeconf 'fairygui::UISource'
    .supercls 'fairygui::IUISource'
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
    .func('create', 'static UISource *create()')
    .func('loadComplete', 'void loadComplete()')

typeconf 'fairygui::Window'
    .attr('show', {ret = '@delref(children ~ parent)@addref(children | parent)'})
    .attr('hide', {ret = '@delref(children ~ parent)'})
    .attr('hideImmediately', {ret = '@delref(children ~ parent)'})
    .attr('getContentPane', {ret = '@addref(contentPane ^)'})
    .attr('setContentPane', {arg1 = '@addref(contentPane ^)'})
    .attr('getFrame', {ret = '@addref(frame ^)'})
    .attr('getCloseButton', {ret = '@addref(closeButton ^)'})
    .attr('setCloseButton', {arg1 = '@addref(closeButton ^)'})
    .attr('getDragArea', {ret = '@addref(dragArea ^)'})
    .attr('setDragArea', {arg1 = '@addref(dragArea ^)'})
    .attr('getContentArea', {ret = '@addref(contentArea ^)'})
    .attr('setContentArea', {arg1 = '@addref(contentArea ^)'})
    .attr('getModalWaitingPane', {ret = '@addref(modalWaitingPane ^)'})
    .insert('show', {
        before = [[
            fairygui::GComponent *root = fairygui::UIRoot;
            if (!root) {
                luaL_error(L, "no root to add 'Window'");
            }
            olua_push_cppobj<fairygui::GComponent>(L, root);
            int parent = lua_gettop(L);
        ]]
    })
    .insert({'hide', 'hideImmediately'}, {
        before = [[
            fairygui::GComponent *root = self->getParent() ? self->getParent() : fairygui::UIRoot;
            if (!root) {
                return 0;
            }
            olua_push_cppobj<fairygui::GComponent>(L, root);
            int parent = lua_gettop(L);
        ]]
    })

typeconf 'fairygui::DragDropManager'
typeconf 'fairygui::UIObjectFactory::GLoaderCreator'
typeconf 'fairygui::UIObjectFactory::GComponentCreator'
typeconf 'fairygui::UIObjectFactory'

typeconf 'fairygui::GearBase'
    .exclude 'getController'
    .exclude 'setController'
    .exclude 'getTweenConfig'
    .exclude 'updateFromRelations'
    .exclude 'apply'
    .exclude 'updateState'
    .exclude 'setup'

typeconf 'fairygui::GTreeNode'
    .attr('getCell', {ret = '@addref(cell ^)'})
    .attr('addChild', {arg1 = '@addref(children |)'})
    .attr('addChildAt', {arg1 = '@addref(children |)'})
    .attr('removeChild', {arg1 = '@delref(children |)'})
    .attr('removeChildAt', {ret ='@delref(children ~)'})
    .attr('removeChildren', {ret ='@delref(children ~)'})
    .attr('getChildAt', {ret = '@addref(children |)'})
    .attr('getPrevSibling', {ret = '@addref(children |)'})
    .attr('getNextSibling', {ret = '@addref(children |)'})
    .prop('numChildren', 'int numChildren()')

typeconf 'fairygui::GTree::TreeNodeRenderFunction'
typeconf 'fairygui::GTree::TreeNodeWillExpandFunction'

typeconf 'fairygui::GTree'
    .attr('getList', {ret = '@addref(list ^)'})
    .attr('getRootNode', {ret = '@addref(rootNode ^)'})
    .attr('getSelectedNode', {ret = '@addref(nodes |)'})
    .attr('getSelectedNodes', {arg1 = '@addref(nodes |)@ret'})
    .callback {name = 'treeNodeRender', localvar = false}
    .callback {name = 'treeNodeWillExpand', localvar = false}
    -- std::function<void (GTreeNode *, GComponent *)> treeNodeRender
    .insert('treeNodeRender', {
        callback_before = [[
            olua_push_cppobj<fairygui::GComponent>(L, (fairygui::GComponent *)cb_store);
            olua_addref(L, -1, "nodes", top + 1, OLUA_MODE_MULTIPLE);
            olua_addref(L, -1, "children",top + 2, OLUA_MODE_MULTIPLE);
            lua_pop(L, 1);
        ]]
    })
    -- std::function<void (GTreeNode *, bool)> treeNodeWillExpand
    .insert('treeNodeWillExpand', {
        callback_before = [[
            olua_push_cppobj<fairygui::GComponent>(L, (fairygui::GComponent *)cb_store);
            olua_addref(L, -1, "nodes", top + 1, OLUA_MODE_MULTIPLE);
            lua_pop(L, 1);
        ]]
    })

typeconf 'fairygui::FUIContainer'
typeconf 'fairygui::FUIInput'
typeconf 'fairygui::FUILabel'
typeconf 'fairygui::FUIRichText'
typeconf 'fairygui::FUISprite'
typeconf 'fairygui::HtmlObject'
typeconf 'fairygui::HtmlElement::Type'
typeconf 'fairygui::HtmlElement'
