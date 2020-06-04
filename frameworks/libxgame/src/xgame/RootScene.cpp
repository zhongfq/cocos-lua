#include "xgame/RootScene.h"
#include "xgame/runtime.h"
#include "xgame/xlua.h"

using namespace cocos2d;

NS_XGAME_BEGIN

RootScene* RootScene::create(const std::string &scriptPath)
{
    RootScene *ret = new (std::nothrow) RootScene(scriptPath);
    ret->autorelease();
    ret->init();
    return ret;
}

void RootScene::onEnter()
{
    Scene::onEnter();
    if (_executed == false) {
        _executed = true;
        execute();
    }
}

void RootScene::execute()
{
    lua_State *L = xlua_mainthread(NULL);
    int top = lua_gettop(L);
    
    if (xlua_dofile(L, _scriptPath.c_str()) == LUA_OK &&
        olua_getglobal(L, "main") == LUA_TFUNCTION) {
        olua_pcall(L, 0, 0);
    } else {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
        runtime::clearStorage();
        runtime::restart();
#else
        runtime::log("launch error, see the console!!!");
#endif
    }
    lua_settop(L, top);
}

SceneNoCamera* SceneNoCamera::create()
{
    SceneNoCamera *ret = new (std::nothrow) SceneNoCamera();
    ret->autorelease();
    ret->init();
    return ret;
}

SceneNoCamera* SceneNoCamera::createWithSize(const Size& size)
{
    SceneNoCamera *ret = new (std::nothrow) SceneNoCamera();
    ret->autorelease();
    ret->initWithSize(size);
    return ret;
}

SceneNoCamera* SceneNoCamera::createWithPhysics()
{
    SceneNoCamera *ret = new (std::nothrow) SceneNoCamera();
    ret->autorelease();
    ret->initWithPhysics();
    return ret;
}

SceneNoCamera::SceneNoCamera()
{
    _defaultCamera->retain();
    removeAllChildren();
}

SceneNoCamera::~SceneNoCamera()
{
    _defaultCamera->release();
}

void SceneNoCamera::removeAllChildren()
{
    Node::removeAllChildren();
}

NS_XGAME_END
