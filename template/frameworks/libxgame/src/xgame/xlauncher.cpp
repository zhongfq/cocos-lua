#include "xgame/xlauncher.h"

#include "xlua.h"

using namespace cocos2d;

NS_XGAME_BEGIN

launcher* launcher::create(const std::string &script_path)
{
    launcher *ret = new (std::nothrow) launcher(script_path);
    ret->autorelease();
    ret->init();
    return ret;
}

void launcher::onEnter()
{
    Scene::onEnter();
    if (_executed == false)
    {
        _executed = true;
        execute();
    }
}

void launcher::execute()
{
//    auto engine = LuaEngine::getInstance();
//    ScriptEngineManager::getInstance()->setScriptEngine(engine);
//    lua_State *L = engine->getLuaStack()->getLuaState();
//    
//    int top = lua_gettop(L);
//    
//    luaext_openlibs(L);
//    luaext_dofile(L, _script_path.c_str());
//    lua_getglobal(L, "main");
//    
//    if (lua_isfunction(L, -1))
//    {
//        engine->executeGlobalFunction("main");
//    }
//    else
//    {
//#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
//        xgame::runtime::clear_storage();
//        xgame::runtime::restart();
//#else
//        xgame::runtime::log("launch error, lookup the console!!!");
//#endif
//    }
//    
//    lua_settop(L, top);
}

NS_XGAME_END
