module 'cocos2d'

path = '../../frameworks/libxgame/src/lua-bindings'

headers = [[
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "lua-bindings/LuaCocosAdapter.h"
#include "audio/include/AudioEngine.h"
#include "cocos2d.h"
#include "base/TGAlib.h"
#include "ui/CocosGUI.h"
#include "navmesh/CCNavMesh.h"
#include "cclua/xlua.h"
]]

chunk = [[
static const std::string makeScheduleCallbackTag(const std::string &key)
{
    return "schedule." + key;
}]]

make_luacls = function (cppname)
    if cppname == 'ResolutionPolicy' then
        return 'cc.' .. cppname
    else
        cppname = string.gsub(cppname, "^cocos2d::network::", "cc.")
        cppname = string.gsub(cppname, "^cocos2d::", "cc.")
        cppname = string.gsub(cppname, "::", ".")
        return cppname
    end
end

include 'conf/exclude-type.lua'

typedef 'cocos2d::Data'
typedef 'cocos2d::Mat4'
typedef 'cocos2d::Vector'
typedef 'cocos2d::Color3B'
typedef 'cocos2d::Color4B'
typedef 'cocos2d::Color4F'
typedef 'cocos2d::Value'
typedef 'cocos2d::ValueMap'
typedef 'cocos2d::ValueMapIntKey'
typedef 'cocos2d::ValueVector'
typedef 'cocos2d::Map'

typedef 'cocos2d::Rect'
    .vars '4'

typedef 'cocos2d::EventListener::ListenerID'
    .decltype 'std::string'
    .conv 'olua_$$_std_string'

typeconf 'cocos2d::RenderTargetFlag'
typeconf 'cocos2d::ClearFlag'
typeconf 'cocos2d::MATRIX_STACK_TYPE'
typeconf 'cocos2d::Director::Projection'

typeconf 'cocos2d::UserDefault'
    .exclude 'setDelegate'

typeconf 'cocos2d::Ref'
    .exclude 'retain'
    .exclude 'release'
    .exclude 'autorelease'
    .func('__gc', '{\n    return xlua_ccobjgc(L);\n}')
    
typeconf 'cocos2d::Console'
typeconf 'cocos2d::Acceleration'

typeconf 'cocos2d::Director'
    .exclude 'getCocos2dThreadId'
    .alias('end', 'exit')
    .attr('getRunningScene', {ret = '@addref(scenes |)'})
    .attr('runWithScene', {arg1 = '@addref(scenes |)'})
    .attr('pushScene', {arg1 = '@addref(scenes |)'})
    .attr('replaceScene', {ret = '@delref(scenes ~)', arg1 = '@addref(scenes |)'})
    .attr('popScene', {ret = '@delref(scenes ~)'})
    .attr('popToRootScene', {ret = '@delref(scenes ~)'})
    .attr('popToSceneStackLevel', {ret = '@delref(scenes ~)'})
    .attr('getOpenGLView', {ret = '@addref(openGLView ^)'})
    .attr('setOpenGLView', {arg1 = '@addref(openGLView ^)'})
    .attr('getTextureCache', {ret = '@addref(textureCache ^)'})
    .attr('getNotificationNode', {ret = '@addref(notificationNode ^)'})
    .attr('setNotificationNode', {arg1 = '@addref(notificationNode ^)'})
    .attr('convertToGL', {arg1 = '@pack'})
    .attr('convertToUI', {arg1 = '@pack'})
    .attr('getEventDispatcher', {ret = '@addref(eventDispatcher ^)'})
    .attr('setEventDispatcher', {arg1 = '@addref(eventDispatcher ^)'})
    .attr('getScheduler', {ret = '@addref(scheduler ^)'})
    .attr('setScheduler', {arg1 = '@addref(scheduler ^)'})
    .attr('getActionManager', {ret = '@addref(actionManager ^)'})
    .attr('setActionManager', {arg1 = '@addref(actionManager ^)'})
    .attr('getRenderer', {ret = '@addref(renderer ^)'})

typeconf 'cocos2d::ccSchedulerFunc'

typeconf 'cocos2d::Scheduler'
    .exclude 'performFunctionInCocosThread'
    .chunk([[
        template <typename T> bool doScheduleUpdate(lua_State *L)
        {
            if (olua_isa<T>(L, 2)) {
                auto self = olua_checkobj<cocos2d::Scheduler>(L, 1);
                auto target = olua_checkobj<T>(L, 2);
                lua_Integer priority = olua_checkinteger(L, 3);
                bool paused = olua_checkboolean(L, 4);
                self->scheduleUpdate(target, (int)priority, paused);
                return true;
            }

            return false;
        }
    ]])
    .callback {
        name = 'schedule',
        tag_maker = 'makeScheduleCallbackTag(#-1)',
        tag_mode = 'OLUA_TAG_REPLACE',
        tag_store = 2, -- 2th void *target
    }
    .callback {
        name = 'unschedule',
        tag_maker = 'makeScheduleCallbackTag(#1)',
        tag_store = 2, -- 2th void *target
        tag_mode = 'OLUA_TAG_SUBEQUAL',
    }
    .callback {
        name = 'unscheduleAllForTarget',
        tag_maker = 'makeScheduleCallbackTag("")',
        tag_mode = 'OLUA_TAG_SUBSTARTWITH',
        tag_store = 1, -- 1th void *target
    }
    .callback {
        name = 'unscheduleAll',
        tag_maker = 'makeScheduleCallbackTag("")',
        tag_mode = 'OLUA_TAG_SUBSTARTWITH',
    }
    .func('scheduleUpdate', [[
        {
            if (doScheduleUpdate<cocos2d::Scheduler>(L) ||
                doScheduleUpdate<cocos2d::ActionManager>(L) ||
                doScheduleUpdate<cocos2d::Node>(L) ||
                doScheduleUpdate<cocos2d::Action>(L) ||
                doScheduleUpdate<cocos2d::Component>(L) ||
                doScheduleUpdate<cocos2d::ActionManager>(L)) {
                return 0;
            }

            luaL_error(L, "unsupport type: %s", olua_typename(L, 2));

            return 0;
        }
    ]])

--
-- event & event listener
--
typeconf 'cocos2d::EventDispatcher'
    .chunk([[
        static int _cocos2d_EventDispatcher_addEventListenerWithFixedPriority(lua_State *L);

        static void doRemoveEventListenersForTarget(lua_State *L, cocos2d::Node *target, bool recursive, const char *refname)
        {
            if (olua_getrawobj(L, target)) {
                olua_delallrefs(L, -1, refname);
                lua_pop(L, 1);
            }
            if (recursive) {
                const auto &children = target->getChildren();
                for (const auto& child : children)
                {
                    doRemoveEventListenersForTarget(L, child, recursive, refname);
                }
            }
        }
    ]])
    .attr('addEventListenerWithSceneGraphPriority', {arg1 = '@addref(listeners | 3)'})
    .attr('addEventListenerWithFixedPriority', {arg1 = '@addref(listeners |)'})
    .attr('addCustomEventListener', {ret = '@addref(listeners |)'})
    .attr('removeCustomEventListeners', {ret = '@delref(listeners ~)'})
    .attr('removeEventListener', {ret = '@delref(listeners ~)', arg1 = '@delref(listeners |)'})
    .attr('removeEventListenersForType', {ret = '@delref(listeners ~)'})
    .attr('removeAllEventListeners', {ret = '@delref(listeners ~)'})
    .callback {
        name = 'addCustomEventListener',
        tag_maker = '(#1)',
        tag_store = 'return',
        tag_mode = 'OLUA_TAG_NEW',
    }
    .insert('removeEventListenersForTarget', {
        before = [[
            bool recursive = false;
            auto node = olua_checkobj<cocos2d::Node>(L, 2);
            if (lua_gettop(L) >= 3) {
                recursive = olua_toboolean(L, 3);
            }
            doRemoveEventListenersForTarget(L, node, recursive, "listeners");
        ]]
    })
    .func('addEventListener', [[
        {
            lua_settop(L, 2);
            olua_push_int(L, 1);
            return _cocos2d_EventDispatcher_addEventListenerWithFixedPriority(L);
        }
    ]])

typeconf 'cocos2d::EventListener::Type'

typeconf 'cocos2d::EventListener'
    .exclude 'init'
    .prop('available', 'bool checkAvailable()')

typeconf 'cocos2d::EventListenerTouchOneByOne::ccTouchBeganCallback'
typeconf 'cocos2d::EventListenerTouchOneByOne::ccTouchCallback'
typeconf 'cocos2d::EventListenerTouchOneByOne'
typeconf 'cocos2d::EventListenerTouchAllAtOnce::ccTouchesCallback'
typeconf 'cocos2d::EventListenerTouchAllAtOnce'

typeconf 'cocos2d::EventListenerCustom'
    .callback {
        name = 'create',
        tag_maker = 'listener',
        tag_mode = 'OLUA_TAG_NEW',
        tag_store = 'return',
    }

typeconf 'cocos2d::EventListenerKeyboard'

typeconf 'cocos2d::EventListenerAcceleration'
    .callback {
        name = 'create',
        tag_maker = 'listener',
        tag_mode = 'OLUA_TAG_NEW',
        tag_store = 'return',
    }

typeconf 'cocos2d::EventListenerFocus'
typeconf 'cocos2d::EventListenerMouse'
typeconf 'cocos2d::Event::Type'
typeconf 'cocos2d::Event'
typeconf 'cocos2d::EventCustom'
typeconf 'cocos2d::EventListenerController'
typeconf 'cocos2d::EventTouch::EventCode'
typeconf 'cocos2d::EventTouch'
typeconf 'cocos2d::EventKeyboard'
typeconf 'cocos2d::EventAcceleration'
typeconf 'cocos2d::EventFocus'
typeconf 'cocos2d::EventMouse::MouseEventType'
typeconf 'cocos2d::EventMouse::MouseButton'
typeconf 'cocos2d::EventMouse'
typeconf 'cocos2d::EventKeyboard::KeyCode'
typeconf 'cocos2d::Touch::DispatchMode'
typeconf 'cocos2d::EventController::ControllerEventType'
typeconf 'cocos2d::EventController'

typeconf 'cocos2d::Touch'
typeconf 'cocos2d::Controller::Key'

typeconf 'cocos2d::Controller'
    .exclude 'receiveExternalKeyEvent'

typeconf 'cocos2d::AudioProfile'
typeconf 'cocos2d::AudioEngine::AudioState'

typeconf 'cocos2d::AudioEngine'
    .chunk([[
        NS_CC_BEGIN
        class LuaAudioEngine : public cocos2d::AudioEngine
        {
        public:
            static std::list<int> getAudioIDs(const std::string &path)
            {
                std::list<int> list;
                auto it = _audioPathIDMap.find(path);
                if (it != _audioPathIDMap.end()) {
                    list = it->second;
                }
                return list;
            }
        };
        NS_CC_END

        static const std::string makeAudioEngineFinishCallbackTag(lua_Integer id)
        {
            if (id < 0) {
                return "finishCallback.";
            } else {
                char buf[64];
                sprintf(buf, "finishCallback.%d", (int)id);
                return std::string(buf);
            }
        }
    ]])
    .insert('uncache', {
        before = [[
            std::string path = olua_checkstring(L, 1);
            std::list<int> ids = cocos2d::LuaAudioEngine::getAudioIDs(path);
            void *cb_store = olua_pushclassobj<cocos2d::AudioEngine>(L);
            for (auto id : ids) {
                std::string tag = makeAudioEngineFinishCallbackTag((lua_Integer)id);
                olua_removecallback(L, cb_store, tag.c_str(), OLUA_TAG_SUBEQUAL);
            }
        ]]
    })
    .callback {
        name = 'stop',
        tag_maker = 'makeAudioEngineFinishCallbackTag(#1)',
        tag_mode = 'OLUA_TAG_SUBEQUAL',
    }
    .callback {
        name = 'stopAll',
        tag_maker = 'makeAudioEngineFinishCallbackTag(-1)',
        tag_mode = "OLUA_TAG_SUBSTARTWITH",
    }
    .callback {
        name = 'uncacheAll',
        tag_maker = 'makeAudioEngineFinishCallbackTag(-1)',
        tag_mode = "OLUA_TAG_SUBSTARTWITH",
    }
    .callback {
        name = 'setFinishCallback',
        tag_maker = 'makeAudioEngineFinishCallbackTag(#1)',
        nullable = true,
        tag_scope = 'once',
    }
    .callback {
        name = 'preload',
        tag_scope = 'once',
    }

typeconf 'cocos2d::ApplicationProtocol::Platform'
typeconf 'cocos2d::LanguageType'
typeconf 'cocos2d::ApplicationProtocol'

typeconf 'cocos2d::Application'
    .exclude 'setStartupScriptFilename'
    .exclude 'applicationScreenSizeChanged'

typeconf 'cocos2d::Device'
    .exclude 'getTextureDataForText'

typeconf 'cocos2d::ResizableBuffer'
typeconf 'cocos2d::FileUtils::Status'

typeconf 'cocos2d::FileUtils'
    .attr('listFilesRecursively', {arg2 = '@out'})
    .callback {name = "getStringFromFile", tag_scope = 'once', tag_mode = 'OLUA_TAG_NEW'}
    .callback {name = "getDataFromFile", tag_scope = 'once', tag_mode = 'OLUA_TAG_NEW'}
    .callback {name = "writeStringToFile", tag_scope = 'once', tag_mode = 'OLUA_TAG_NEW'}
    .callback {name = "writeDataToFile", tag_scope = 'once', tag_mode = 'OLUA_TAG_NEW'}
    .callback {name = "writeValueMapToFile", tag_scope = 'once', tag_mode = 'OLUA_TAG_NEW'}
    .callback {name = "writeValueVectorToFile", tag_scope = 'once', tag_mode = 'OLUA_TAG_NEW'}
    .callback {name = "isFileExist", tag_scope = 'once', tag_mode = 'OLUA_TAG_NEW'}
    .callback {name = "isDirectoryExist", tag_scope = 'once', tag_mode = 'OLUA_TAG_NEW'}
    .callback {name = "createDirectory", tag_scope = 'once', tag_mode = 'OLUA_TAG_NEW'}
    .callback {name = "removeDirectory", tag_scope = 'once', tag_mode = 'OLUA_TAG_NEW'}
    .callback {name = "removeFile", tag_scope = 'once', tag_mode = 'OLUA_TAG_NEW'}
    .callback {name = "renameFile", tag_scope = 'once', tag_mode = 'OLUA_TAG_NEW'}
    .callback {name = "getFileSize", tag_scope = 'once', tag_mode = 'OLUA_TAG_NEW'}
    .callback {name = "listFilesAsync", tag_scope = 'once', tag_mode = 'OLUA_TAG_NEW'}
    .callback {name = "listFilesRecursivelyAsync", tag_scope = 'once', tag_mode = 'OLUA_TAG_NEW'}
    .func('getFileDataFromZip', [[
        {
            cocos2d::FileUtils *self = olua_toobj<cocos2d::FileUtils>(L, 1);
            std::string zipFilePath = olua_checkstring(L, 2);
            std::string filename = olua_checkstring(L, 3);
            ssize_t size = 0;
            unsigned char *data = self->getFileDataFromZip(zipFilePath, filename, &size);
            lua_pushlstring(L, (const char *)data, size);
            olua_push_int(L, (lua_Integer)size);

            return 2;
        }
    ]])

typeconf 'ResolutionPolicy'
typeconf 'cocos2d::GLView'

typeconf 'cocos2d::GLViewImpl'
    .exclude 'create'
    .exclude 'createWithRect'
    .exclude 'createWithFullScreen'

typeconf 'cocos2d::Image::Format'

typeconf 'cocos2d::Image'
    .chunk([[
        NS_CC_BEGIN
        class LuaImage : public cocos2d::Image {
        public:
            static bool getPNGPremultipliedAlphaEnabled() { return PNG_PREMULTIPLIED_ALPHA_ENABLED; };
        };
        NS_CC_END
    ]])
    .func('getPNGPremultipliedAlphaEnabled', [[
        {
            lua_pushboolean(L, cocos2d::LuaImage::getPNGPremultipliedAlphaEnabled());
            return 1;
        }
    ]])

typeconf 'cocos2d::Properties::Type'
typeconf 'cocos2d::Properties'
    .attr('getPath', {arg2 = '@out'})

typeconf 'cocos2d::Material'
typeconf 'cocos2d::Renderer'
typeconf 'cocos2d::RenderCommand::Type'
typeconf 'cocos2d::CustomCommand::DrawType'
typeconf 'cocos2d::PipelineDescriptor'
typeonly 'cocos2d::Technique'
typeonly 'cocos2d::Pass'
typeonly 'cocos2d::RenderState'
typeconf 'cocos2d::RenderCommand'
typeconf 'cocos2d::CustomCommand'
typeconf 'cocos2d::MeshCommand'
    .exclude 'listenRendererRecreated'

typeconf 'cocos2d::TextureCache'
    .chunk([[
        static const std::string makeTextureCacheCallbackTag(const std::string &key)
        {
            return "addImageAsync." + key;
        }
    ]])
    .callback {
        name = 'addImageAsync',
        tag_maker = {'makeTextureCacheCallbackTag(#1)', 'makeTextureCacheCallbackTag(#-1)'},
        tag_mode = 'OLUA_TAG_REPLACE',
        tag_scope = 'once',
        localvar = false,
    }
    .callback {
        name = 'unbindImageAsync',
        tag_maker = 'makeTextureCacheCallbackTag(#1)',
        tag_mode = 'OLUA_TAG_SUBEQUAL',
    }
    .callback {
        name = 'unbindAllImageAsync',
        tag_maker = 'makeTextureCacheCallbackTag("")',
        tag_mode = 'OLUA_TAG_SUBSTARTWITH',
    }

typeconf 'cocos2d::Texture2D'
typeconf 'cocos2d::TextureCube'
typeconf 'cocos2d::TextureAtlas'

typeconf 'cocos2d::network::WebSocket::ErrorCode'
typeconf 'cocos2d::network::WebSocket::State'
typeconf 'cocos2d::network::WebSocket::Delegate'

typeconf 'cocos2d::network::WebSocket'
    .func('init', [[
        {
            std::vector<std::string> protocols;
            auto self =  olua_toobj<cocos2d::network::WebSocket>(L, 1);
            auto delegate = olua_checkobj<cocos2d::network::WebSocket::Delegate>(L, 2);
            std::string url = olua_tostring(L, 3);
            std::string cafile = olua_optstring(L, 5, "");

            if (!lua_isnil(L, 4)) {
                luaL_checktype(L, 4, LUA_TTABLE);
                int len = (int)lua_rawlen(L, 4);
                protocols.reserve(len);
                for (int i = 1; i <= len; i++) {
                    lua_rawgeti(L, 4, i);
                    protocols.push_back(olua_checkstring(L, -1));
                    lua_pop(L, 1);
                }
            }

            self->init(*delegate, url, protocols.size() > 0 ? &protocols : nullptr, cafile);
            olua_addref(L, 1, "delegate", 2, OLUA_MODE_SINGLE);

            return 0;
        }
    ]])

typeconf 'cocos2d::LuaWebSocketDelegate'
    .make_luaname(function (name)
        return string.gsub(name, 'Callback', '')
    end)

typeconf 'cocos2d::ActionManager'
typeconf 'cocos2d::Component'

typeconf 'cocos2d::LuaComponent'
    .make_luaname(function (name)
        return string.gsub(name, 'Callback', '')
    end)

-- node
typeconf 'cocos2d::Node'
    .chunk([[
        static cocos2d::Node *_find_ancestor(cocos2d::Node *node1, cocos2d::Node *node2)
        {
            for (auto *p1 = node1; p1 != nullptr; p1 = p1->getParent()) {
                for (auto *p2 = node2; p2 != nullptr; p2 = p2->getParent()) {
                    if (p1 == p2) {
                        return p1;
                    }
                }
            }
            return NULL;
        }
    ]])
    .exclude 'scheduleUpdateWithPriorityLua'
    .attr('addChild', {arg1 = '@addref(children |)'})
    .attr('getChildByTag', {ret = '@addref(children |)'})
    .attr('getChildByName', {ret = '@addref(children |)'})
    .attr('getChildren', {ret = '@addref(children |)'})
    .attr('removeFromParent', {ret = '@delref(children | parent)'})
    .attr('removeFromParentAndCleanup', {ret = '@delref(children | parent)'})
    .attr('removeChild', {arg1 = '@delref(children |)'})
    .attr('removeChildByTag', {ret = '@delref(children ~)'})
    .attr('removeChildByName', {ret = '@delref(children ~)'})
    .attr('removeAllChildren', {ret = '@delref(children *)'})
    .attr('removeAllChildrenWithCleanup', {ret = '@delref(children *)'})
    .attr('getProgramState', {ret = '@addref(programState ^)'})
    .attr('setProgramState', {arg1 = '@addref(programState ^)'})
    .attr('getEventDispatcher', {ret = '@addref(eventDispatcher ^)'})
    .attr('setEventDispatcher', {arg1 = '@addref(eventDispatcher ^)'})
    .attr('getActionManager', {ret = '@addref(actionManager ^)'})
    .attr('setActionManager', {arg1 = '@addref(actionManager ^)'})
    .attr('runAction', {ret = '@delref(actions ~)', arg1 = '@addref(actions |)'})
    .attr('stopAllActions', {ret = '@delref(actions ~)'})
    .attr('stopAction', {ret = '@delref(actions ~)'})
    .attr('stopActionByTag', {ret = '@delref(actions ~)'})
    .attr('stopAllActionsByTag', {ret = '@delref(actions ~)'})
    .attr('stopActionsByFlags', {ret = '@delref(actions ~)'})
    .attr('getActionByTag', {ret = '@addref(actions |)'})
    .attr('setScheduler', {arg1 = '@addref(scheduler ^)'})
    .attr('getScheduler', {ret = '@addref(scheduler ^)'})
    .attr('convertToNodeSpace', {arg1 = '@pack'})
    .attr('convertToWorldSpace', {arg1 = '@pack'})
    .attr('convertToNodeSpaceAR', {arg1 = '@pack'})
    .attr('convertToWorldSpaceAR', {arg1 = '@pack'})
    .attr('getComponent', {ret = '@addref(components |)'})
    .attr('addComponent', {arg1 = '@addref(components |)'})
    .attr('removeComponent', {ret = '@delref(components ~)'})
    .attr('removeAllComponents', {ret = '@delref(components *)'})
    .attr('setPhysicsBody', {arg1 = '@addref(physicsBody ^)'})
    .attr('getPhysicsBody', {ret = '@addref(physicsBody ^)'})
    .func('__index', [[
        {
            auto self = olua_toobj<cocos2d::Node>(L, 1);
            if (olua_isstring(L, 2)) {
                cocos2d::Node *child = self->getChildByName(olua_tostring(L, 2));
                if (child) {
                    olua_pushobj<cocos2d::Node>(L, child);
                    olua_addref(L, 1, "children", -1, OLUA_MODE_MULTIPLE);
                    return 1;
                }
            }
            lua_settop(L, 2);
            olua_getvariable(L, 1);
            return 1;
        }
    ]])
    .func('getBounds', [[
        {
            auto self = olua_checkobj<cocos2d::Node>(L, 1);
            auto target = olua_checkobj<cocos2d::Node>(L, 2);

            float left = (float)luaL_checknumber(L, 3);
            float right = (float)luaL_checknumber(L, 4);
            float top = (float)luaL_checknumber(L, 5);
            float bottom = (float)luaL_checknumber(L, 6);

            cocos2d::Vec3 p1(left, bottom, 0);
            cocos2d::Vec3 p2(right, top, 0);

            auto m = cocos2d::Mat4::IDENTITY;

            if (target == self->getParent()) {
                m = self->getNodeToParentTransform();
            } else if (target != self) {
                auto ancestor = _find_ancestor(target, self);
                if (!ancestor) {
                    m = target->getWorldToNodeTransform() * self->getNodeToWorldTransform();
                } else if (target == ancestor) {
                    m = self->getNodeToParentTransform(target);
                } else if (self == ancestor) {
                    m = target->getNodeToParentTransform(self).getInversed();
                } else {
                    m = target->getNodeToParentTransform(ancestor).getInversed() * self->getNodeToParentTransform(ancestor);
                }
            }

            m.transformPoint(&p1);
            m.transformPoint(&p2);

            left = MIN(p1.x, p2.x);
            right = MAX(p1.x, p2.x);
            top = MAX(p1.y, p2.y);
            bottom = MIN(p1.y, p2.y);

            lua_pushnumber(L, left);
            lua_pushnumber(L, right);
            lua_pushnumber(L, top);
            lua_pushnumber(L, bottom);

            return 4;
        }
    ]])
    .prop('x', 'float getPositionX()', 'void setPositionX(float x)')
    .prop('y', 'float getPositionY()', 'void setPositionY(float y)')
    .prop('z', 'float getPositionZ()', 'void setPositionZ(float z)')
    .prop('anchorX', [[
        {
            auto self = olua_toobj<cocos2d::Node>(L, 1);
            lua_pushnumber(L, self->getAnchorPoint().x);
            return 1;
        }
        ]], [[
        {
            auto self = olua_toobj<cocos2d::Node>(L, 1);
            cocos2d::Vec2 anchor = self->getAnchorPoint();
            anchor.x = (float)olua_checknumber(L, 2);
            self->setAnchorPoint(anchor);
            return 0;
        }
    ]])
    .prop('anchorY', [[
        {
            auto self = olua_toobj<cocos2d::Node>(L, 1);
            lua_pushnumber(L, self->getAnchorPoint().y);
            return 1;
        }
        ]], [[
        {
            auto self = olua_toobj<cocos2d::Node>(L, 1);
            cocos2d::Vec2 anchor = self->getAnchorPoint();
            anchor.y = (float)olua_checknumber(L, 2);
            self->setAnchorPoint(anchor);
            return 0;
        }
    ]])
    .prop('width', [[
        {
            auto self = olua_toobj<cocos2d::Node>(L, 1);
            lua_pushnumber(L, self->getContentSize().width);
            return 1;
        }
        ]], [[
        {
            auto self = olua_toobj<cocos2d::Node>(L, 1);
            cocos2d::Size size = self->getContentSize();
            size.width = (float)olua_checknumber(L, 2);
            self->setContentSize(size);
            return 0;
        }
    ]])
    .prop('height', [[
        {
            auto self = olua_toobj<cocos2d::Node>(L, 1);
            lua_pushnumber(L, self->getContentSize().height);
            return 1;
        }
        ]], [[
        {
            auto self = olua_toobj<cocos2d::Node>(L, 1);
            cocos2d::Size size = self->getContentSize();
            size.height = (float)olua_checknumber(L, 2);
            self->setContentSize(size);
            return 0;
        }
    ]])
    .prop('alpha', [[
        {
            auto self = olua_toobj<cocos2d::Node>(L, 1);
            lua_pushnumber(L, self->getOpacity() / 255.0f);
            return 1;
        }
        ]], [[
        {
            auto self = olua_toobj<cocos2d::Node>(L, 1);
            self->setOpacity((uint8_t)(olua_checknumber(L, 2) * 255.0f));
            return 0;
        }
    ]])
    .callback {name = 'setOnEnterCallback', nullable = true}
    .callback {name = 'getOnEnterCallback', nullable = true}
    .callback {name = 'setOnExitCallback', nullable = true}
    .callback {name = 'getOnExitCallback', nullable = true}
    .callback {name = 'setOnEnterTransitionDidFinishCallback', nullable = true}
    .callback {name = 'getOnEnterTransitionDidFinishCallback', nullable = true}
    .callback {name = 'setOnExitTransitionDidStartCallback', nullable = true}
    .callback {name = 'getOnExitTransitionDidStartCallback', nullable = true}
    .callback {
        name = 'scheduleOnce',
        tag_maker = 'makeScheduleCallbackTag(#-1)',
        tag_mode = 'OLUA_TAG_REPLACE',
        tag_scope = 'once',
    }
    .callback {
        name = 'schedule',
        tag_maker = "makeScheduleCallbackTag(#-1)",
        tag_mode = 'OLUA_TAG_REPLACE',
    }
    .callback {
        name = 'unschedule',
        tag_maker = "makeScheduleCallbackTag(#1)",
        tag_mode = 'OLUA_TAG_SUBEQUAL',
    }
    .callback {
        name = 'unscheduleAllCallbacks',
        tag_maker = 'makeScheduleCallbackTag("")',
        tag_mode = "OLUA_TAG_SUBSTARTWITH",
    }
    .callback {
        name = 'enumerateChildren',
        tag_mode = 'OLUA_TAG_NEW',
        tag_scope = 'function',
    }
    .insert({'removeFromParent', 'removeFromParentAndCleanup'}, {
        before = [[
            if (!self->getParent()) {
                return 0;
            }
            olua_push_cppobj<cocos2d::Node>(L, self->getParent());
            int parent = lua_gettop(L);
        ]]
    })
    .insert({'onEnter', 'onExit'}, {
        before = [[
            if (!self->getParent()) {
                luaL_error(L, "parent is nullptr");
            }
        ]]
    })

typeconf 'cocos2d::LuaTweenNode'
    .callback {
        name = 'create',
        tag_maker = 'ActionTween',
        tag_mode = 'OLUA_TAG_NEW',
        tag_store = 'return',
    }

typeconf 'cocos2d::AtlasNode'
typeconf 'cocos2d::sImageTGA'
typeconf 'cocos2d::TileMapAtlas'
typeconf 'cocos2d::ClippingNode'
typeconf 'cocos2d::MotionStreak'

typeconf 'cocos2d::ProtectedNode'
    .attr('addProtectedChild', {arg1 = '@addref(protectedChildren |)'})
    .attr('getProtectedChildByTag', {ret = '@addref(protectedChildren |)'})
    .attr('removeProtectedChild', {arg1 = '@delref(protectedChildren |)'})
    .attr('removeProtectedChildByTag', {ret = '@delref(protectedChildren ~)'})
    .attr('removeAllProtectedChildren', {ret = '@delref(protectedChildren *)'})
    .attr('removeAllProtectedChildrenWithCleanup', {ret = '@delref(protectedChildren *)'})

typeconf 'cocos2d::DrawNode'

typeconf 'cocos2d::ParallaxNode'
    .attr('addChild', {arg1 = '@addref(chilren |)'})
    
typeconf 'cocos2d::TextHAlignment'
typeconf 'cocos2d::TextVAlignment'
typeconf 'cocos2d::GlyphCollection'
typeconf 'cocos2d::LabelEffect'
typeconf 'cocos2d::Label::LabelType'
typeconf 'cocos2d::Label::Overflow'
typeconf 'cocos2d::Label'
typeconf 'cocos2d::LabelAtlas'

typeconf 'cocos2d::FontAtlas'
    .exclude 'getTextures'
    .exclude 'prepareLetterDefinitions'

typeconf 'cocos2d::ClippingRectangleNode'

typeconf 'cocos2d::RenderTexture'
    .callback {
        name = 'saveToFile',
        localvar = false,
        tag_scope = 'once',
    }
    .callback {
        name = 'saveToFileAsNonPMA',
        tag_maker = 'saveToFile',
        localvar = false,
        tag_scope = 'once',
    }
    .callback {
        name = 'newImage',
        tag_mode = 'OLUA_TAG_NEW',
        localvar = false,
        tag_scope = 'once',
    }
    .alias('begin', 'beginVisit')
    .alias('end', 'endVisit')

typeconf 'cocos2d::ProgressTimer::Type'
typeconf 'cocos2d::ProgressTimer'
typeconf 'cocos2d::AnimationFrame'
typeconf 'cocos2d::Animation'
typeconf 'cocos2d::SpriteFrame'
typeconf 'cocos2d::Sprite'
typeconf 'cocos2d::SpriteBatchNode'
typeconf 'cocos2d::SpriteFrameCache'
typeconf 'cocos2d::AnimationCache'

typeconf 'cocos2d::Scene'
    .attr('getPhysicsWorld', {ret = '@addref(physicsWorld ^)'})
    .attr('getPhysics3DWorld', {ret = '@addref(physics3DWorld ^)'})

typeconf 'cocos2d::Layer'
typeconf 'cocos2d::LayerColor'
typeconf 'cocos2d::LayerGradient'
typeconf 'cocos2d::LayerRadialGradient'
typeconf 'cocos2d::LayerMultiplex'

typeconf 'cocos2d::TransitionScene::Orientation'

local function typeconfTransition(name)
    local cls = typeconf(name)
    cls.attr('create', {arg2 = '@addref(scenes |)'})
    cls.attr('easeActionWithAction', {arg1 = '@addref(action ^)'})
    return cls
end

typeconfTransition 'cocos2d::TransitionScene'
    .exclude 'initWithDuration'

typeconfTransition 'cocos2d::TransitionSceneOriented'
typeconfTransition 'cocos2d::TransitionRotoZoom'
typeconfTransition 'cocos2d::TransitionJumpZoom'
typeconfTransition 'cocos2d::TransitionMoveInL'
typeconfTransition 'cocos2d::TransitionMoveInR'
typeconfTransition 'cocos2d::TransitionMoveInT'
typeconfTransition 'cocos2d::TransitionMoveInB'
typeconfTransition 'cocos2d::TransitionSlideInL'
typeconfTransition 'cocos2d::TransitionSlideInR'
typeconfTransition 'cocos2d::TransitionSlideInB'
typeconfTransition 'cocos2d::TransitionSlideInT'
typeconfTransition 'cocos2d::TransitionShrinkGrow'
typeconfTransition 'cocos2d::TransitionFlipX'
typeconfTransition 'cocos2d::TransitionFlipY'
typeconfTransition 'cocos2d::TransitionFlipAngular'
typeconfTransition 'cocos2d::TransitionZoomFlipX'
typeconfTransition 'cocos2d::TransitionZoomFlipY'
typeconfTransition 'cocos2d::TransitionZoomFlipAngular'
typeconfTransition 'cocos2d::TransitionFade'
typeconfTransition 'cocos2d::TransitionCrossFade'
typeconfTransition 'cocos2d::TransitionTurnOffTiles'
typeconfTransition 'cocos2d::TransitionSplitCols'
typeconfTransition 'cocos2d::TransitionSplitRows'
typeconfTransition 'cocos2d::TransitionFadeTR'
typeconfTransition 'cocos2d::TransitionFadeBL'
typeconfTransition 'cocos2d::TransitionFadeUp'
typeconfTransition 'cocos2d::TransitionFadeDown'
typeconfTransition 'cocos2d::TransitionPageTurn'
typeconfTransition 'cocos2d::TransitionProgress'
typeconfTransition 'cocos2d::TransitionProgressRadialCCW'
typeconfTransition 'cocos2d::TransitionProgressRadialCW'
typeconfTransition 'cocos2d::TransitionProgressHorizontal'
typeconfTransition 'cocos2d::TransitionProgressVertical'
typeconfTransition 'cocos2d::TransitionProgressInOut'
typeconfTransition 'cocos2d::TransitionProgressOutIn'

typeconf 'cocos2d::TextFieldDelegate'
typeconf 'cocos2d::TextFieldTTF'

typeconf 'cocos2d::LightType'
typeconf 'cocos2d::LightFlag'
typeconf 'cocos2d::BaseLight'
typeconf 'cocos2d::DirectionLight'
typeconf 'cocos2d::PointLight'
typeconf 'cocos2d::SpotLight'
typeconf 'cocos2d::AmbientLight'
typeconf 'cocos2d::CameraFlag'
typeconf 'cocos2d::Camera::Type'

typeconf 'cocos2d::Camera'
    .exclude 'isVisibleInFrustum'
    .exclude 'setFrameBufferObject'

typeconf 'cocos2d::CameraBackgroundBrush::BrushType'
typeconf 'cocos2d::CameraBackgroundBrush'
typeconf 'cocos2d::CameraBackgroundDepthBrush'
typeconf 'cocos2d::CameraBackgroundColorBrush'
typeconf 'cocos2d::CameraBackgroundSkyBoxBrush'

typeconf 'cocos2d::ParticleBatchNode'
typeconf 'cocos2d::ParticleSystem::Mode'
typeconf 'cocos2d::ParticleSystem::PositionType'
typeconf 'cocos2d::ParticleSystem'
typeconf 'cocos2d::ParticleSystemQuad'
typeconf 'cocos2d::ParticleExplosion'
typeconf 'cocos2d::ParticleFire'
typeconf 'cocos2d::ParticleFireworks'
typeconf 'cocos2d::ParticleFlower'
typeconf 'cocos2d::ParticleGalaxy'
typeconf 'cocos2d::ParticleMeteor'
typeconf 'cocos2d::ParticleRain'
typeconf 'cocos2d::ParticleSmoke'
typeconf 'cocos2d::ParticleSnow'
typeconf 'cocos2d::ParticleSpiral'
typeconf 'cocos2d::ParticleSun'

typeconf 'cocos2d::TMXTileFlags'
typeconf 'cocos2d::TMXObjectGroup'

typeconf 'cocos2d::TMXLayer'
    .attr('getTileGIDAt', {arg2 = '@out'})

typeconf 'cocos2d::TMXLayerInfo'
typeconf 'cocos2d::TMXMapInfo'
typeconf 'cocos2d::TMXTilesetInfo'
typeconf 'cocos2d::TMXTiledMap'
typeconf 'cocos2d::FastTMXTiledMap'

typeconf 'cocos2d::FastTMXLayer'
    .attr('getTileGIDAt', {arg2 = '@out'})

typeconf 'cocos2d::NavMeshAgent::NavMeshAgentSyncFlag'
typeconf 'cocos2d::NavMeshAgent'
typeconf 'cocos2d::NavMeshObstacle::NavMeshObstacleSyncFlag'
typeconf 'cocos2d::NavMeshObstacle'
typeconf 'cocos2d::NavMesh'
