#include "cclua/RootScene.h"
#include "cclua/xlua.h"

using namespace cocos2d;

NS_CCLUA_BEGIN

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
    lua_State *L = olua_mainthread(NULL);
    int top = lua_gettop(L);
    
    if (xlua_dofile(L, _scriptPath.c_str()) == LUA_OK &&
        olua_getglobal(L, "main") == LUA_TFUNCTION) {
        olua_pcall(L, 0, 0);
    } else if (runtime::getEnv("cclua.debug") == "true") {
        runtime::log("launch error, see the console!!!");
        runtime::clearStorage();
        runtime::showLog();
    } else {
        runtime::clearStorage();
        runtime::restart();
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

Container::~Container()
{
    CC_SAFE_RELEASE(_filter);
}

void Container::visit(cocos2d::Renderer *renderer, const cocos2d::Mat4& parentTransform, uint32_t parentFlags)
{
    if (!_visible)
    {
        return;
    }
    
    if (_filter) {
        uint32_t flags = processParentFlags(parentTransform, parentFlags);
        Director* director = Director::getInstance();
        CCASSERT(nullptr != director, "Director is null when setting matrix stack");
        director->pushMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
        director->loadMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW, _modelViewTransform);
        _filter->visit(renderer, _modelViewTransform, flags);
        director->popMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
    } else {
        Layout::visit(renderer, parentTransform, parentFlags);
    }
}

void Container::onEnter()
{
    Layout::onEnter();
    if (_filter) {
        _filter->onEnter();
    }
}

void Container::onExit()
{
    Layout::onExit();
    if (_filter) {
        _filter->onExit();
    }
}

void Container::setFilter(cocos2d::Node *value)
{
    if (value != _filter) {
        CC_SAFE_RELEASE(_filter);
        CC_SAFE_RETAIN(value);
        if (_filter) {
            _filter->setParent(nullptr);
            if (_running) {
                _filter->onExit();
            }
        }
        _filter = value;
        if (_filter) {
            _filter->setParent(this);
            if (_running) {
                _filter->onEnter();
            }
        }
    }
}

cocos2d::Node *Container::getFilter()
{
    return _filter;
}

NS_CCLUA_END
