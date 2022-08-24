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

ScaleFrom *ScaleFrom::create(float duration, float s)
{
    ScaleFrom *ret = new (std::nothrow) ScaleFrom();
    if (ret && ret->initWithDuration(duration, s))
    {
        ret->autorelease();
        return ret;
    }
    
    delete ret;
    return nullptr;
}

ScaleFrom *ScaleFrom::create(float duration, float sx, float sy)
{
    ScaleFrom *ret = new (std::nothrow) ScaleFrom();
    if (ret && ret->initWithDuration(duration, sx, sy, 1.f))
    {
        ret->autorelease();
        return ret;
    }
    
    delete ret;
    return nullptr;
}

ScaleFrom *ScaleFrom::create(float duration, float sx, float sy, float sz)
{
    ScaleFrom *ret = new (std::nothrow) ScaleFrom();
    if (ret && ret->initWithDuration(duration, sx, sy, sz))
    {
        ret->autorelease();
        return ret;
    }
    
    delete ret;
    return nullptr;
}

ScaleFrom *ScaleFrom::clone() const
{
    // no copy constructor
    return ScaleFrom::create(_duration, _endScaleX, _endScaleY, _endScaleZ);
}

void ScaleFrom::startWithTarget(Node *target)
{
    ScaleTo::startWithTarget(target);
    _deltaX = _startScaleX - _endScaleX;
    _deltaY = _startScaleY - _endScaleY;
    _deltaZ = _startScaleZ - _endScaleZ;
    _startScaleX = _endScaleX;
    _startScaleY = _endScaleY;
    _startScaleZ = _endScaleZ;
}

ScaleFrom *ScaleFrom::reverse() const
{
    return ScaleFrom::create(_duration, 1 / _endScaleX, 1 / _endScaleY, 1/ _endScaleZ);
}

MoveFrom *MoveFrom::create(float duration, const Vec2 &position)
{
    return MoveFrom::create(duration, Vec3(position.x, position.y, 0));
}

MoveFrom *MoveFrom::create(float duration, const Vec3 &position)
{
    MoveFrom *ret = new (std::nothrow) MoveFrom();
    
    if (ret && ret->initWithDuration(duration, position))
    {
        ret->autorelease();
        return ret;
    }
    
    delete ret;
    return nullptr;
}

bool MoveFrom::initWithDuration(float duration, const Vec2 &position)
{
    return initWithDuration(duration, Vec3(position.x, position.y, 0));
}

bool MoveFrom::initWithDuration(float duration, const Vec3 &position)
{
    bool ret = false;
    
    if (ActionInterval::initWithDuration(duration))
    {
        _endPosition = position;
        ret = true;
    }
    
    return ret;
}

MoveFrom* MoveFrom::clone() const
{
    return MoveFrom::create(_duration, _endPosition);
}

void MoveFrom::startWithTarget(Node *target)
{
    MoveBy::startWithTarget(target);
    _positionDelta = target->getPosition3D() - _endPosition;
    _startPosition = _endPosition;
}

MoveFrom *MoveFrom::reverse() const
{
    CCASSERT(false, "reverse() not supported in MoveFrom");
    return nullptr;
}

FadeFrom *FadeFrom::create(float d, uint8_t opacity)
{
    FadeFrom *action = new (std::nothrow) FadeFrom();
    if (action && action->initWithDuration(d, opacity))
    {
        action->autorelease();
        return action;
    }
    
    delete action;
    return nullptr;
}

FadeFrom *FadeFrom::clone() const
{
    return FadeFrom::create(_duration, _toOpacity);
}

void FadeFrom::startWithTarget(cocos2d::Node *target)
{
    ActionInterval::startWithTarget(target);
    _deltaOpacity = target->getOpacity() - _toOpacity;
    _fromOpacity = _toOpacity;
}

void FadeFrom::update(float time)
{
    if (_target)
    {
        _target->setOpacity((uint8_t)(_fromOpacity + _deltaOpacity * time));
    }
}

FadeFrom *FadeFrom::reverse() const
{
    CCASSERT(false, "reverse() not supported in FadeFrom");
    return nullptr;
}

RotateFrom* RotateFrom::create(float duration, float fromAngle)
{
    RotateFrom* ret = new (std::nothrow) RotateFrom();
    if (ret && ret->initWithDuration(duration, fromAngle, fromAngle))
    {
        ret->autorelease();
        return ret;
    }
    
    delete ret;
    return nullptr;
}

RotateFrom* RotateFrom::create(float duration, float fromAngleX, float fromAngleY)
{
    RotateFrom* ret = new (std::nothrow) RotateFrom();
    if (ret && ret->initWithDuration(duration, fromAngleX, fromAngleY))
    {
        ret->autorelease();
        return ret;
    }
    
    delete ret;
    return nullptr;
}

RotateFrom* RotateFrom::create(float duration, const Vec3& fromAngle3D)
{
    RotateFrom* ret = new (std::nothrow) RotateFrom();
    if(ret && ret->initWithDuration(duration, fromAngle3D))
    {
        ret->autorelease();
        return ret;
    }

    delete ret;
    return nullptr;
}

RotateFrom* RotateFrom::clone() const
{
    // no copy constructor
    auto a = new (std::nothrow) RotateFrom();
    if(_is3D)
       a->initWithDuration(_duration, _dstAngle);
    else
        a->initWithDuration(_duration, _dstAngle.x, _dstAngle.y);
    a->autorelease();
    return a;
}

void RotateFrom::startWithTarget(Node *target)
{
    RotateTo::startWithTarget(target);
    
    Vec3 dstAngle;
    
    if (_is3D)
    {
        dstAngle = _target->getRotation3D();
    }
    else
    {
        dstAngle.x = _target->getRotationSkewX();
        dstAngle.y = _target->getRotationSkewY();
    }
    _startAngle = _dstAngle;

    calculateAngles(_startAngle.x, _diffAngle.x, dstAngle.x);
    calculateAngles(_startAngle.y, _diffAngle.y, dstAngle.y);
    calculateAngles(_startAngle.z, _diffAngle.z, dstAngle.z);
}

RotateFrom *RotateFrom::reverse() const
{
    CCASSERT(false, "RotateFrom doesn't support the 'reverse' method");
    return nullptr;
}

NS_CC_END
