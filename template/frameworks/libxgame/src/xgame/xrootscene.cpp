#include "xgame/xrootscene.h"
#include "xgame/xruntime.h"
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
    if (_executed == false)
    {
        _executed = true;
        execute();
    }
}

void RootScene::execute()
{
    lua_State *L = xlua_cocosthread();
    int top = lua_gettop(L);
    
    if (xlua_dofile(L, _scriptPath.c_str()) == LUA_OK &&
        lua_getglobal(L, "main") == LUA_TFUNCTION) {
        xlua_pcall(L, 0, 0);
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

NS_XGAME_END
