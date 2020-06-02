#include "LuaCocosAdapter.h"

NS_CC_BEGIN

LuaComponent* LuaComponent::create()
{
    LuaComponent *ret = new (std::nothrow) LuaComponent();
    if (ret && ret->init()) {
        ret->autorelease();
    } else {
        CC_SAFE_DELETE(ret);
    }
    return ret;
}

LuaComponent::LuaComponent()
:onUpdateCallback(nullptr)
,onEnterCallback(nullptr)
,onExitCallback(nullptr)
,onAddCallback(nullptr)
,onRemoveCallback(nullptr)
{
    
}

LuaComponent::~LuaComponent()
{
}

void LuaComponent::update(float delta)
{
    Component::update(delta);
    if (onUpdateCallback) {
        onUpdateCallback(delta);
    }
}

void LuaComponent::onEnter()
{
    Component::onEnter();
    if (onEnterCallback) {
        onEnterCallback();
    }
}

void LuaComponent::onExit()
{
    Component::onExit();
    if (onExitCallback) {
        onExitCallback();
    }
}

void LuaComponent::onAdd()
{
    Component::onAdd();
    if (onAddCallback) {
        onAddCallback();
    }
}

void LuaComponent::onRemove()
{
    Component::onRemove();
    if (onRemoveCallback) {
        onRemoveCallback();
    }
}

LuaTweenNode *LuaTweenNode::create(const ccTweenCallback &callback)
{
    LuaTweenNode *ret = new (std::nothrow) LuaTweenNode();
    if (ret && ret->initWithCallback(callback)) {
        ret->autorelease();
    } else {
        CC_SAFE_DELETE(ret);
    }
    return ret;
}
   
void LuaTweenNode::updateTweenAction(float value, const std::string &key)
{
    if (_callback) {
        _callback(value, key);
    }
}

bool LuaTweenNode::initWithCallback(const ccTweenCallback &callback)
{
    if (Node::init()) {
        _callback = callback;
        return true;
    } else {
        return false;
    }
}

NS_CC_END
