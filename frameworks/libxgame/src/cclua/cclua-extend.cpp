#include "cclua-extend.h"
#include "runtime.h"

USING_NS_CC;

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

cocos2d::Data FileUtilsExtend::getFileDataFromZip(cocos2d::FileUtils *obj, const std::string &zipPath, const std::string &name)
{
    cocos2d::Data data;
    ssize_t size = 0;
    unsigned char *value = obj->getFileDataFromZip(zipPath, name, &size);
    data.fastSet(value, size);
    return data;
}

float NodeExtend::getAnchorX(cocos2d::Node *obj)
{
    return obj->getAnchorPoint().x;
}

void NodeExtend::setAnchorX(cocos2d::Node *obj, float value)
{
    cocos2d::Vec2 anchor = obj->getAnchorPoint();
    anchor.x = value;
    obj->setAnchorPoint(anchor);
}

float NodeExtend::getAnchorY(cocos2d::Node *obj)
{
    return obj->getAnchorPoint().y;
}

void NodeExtend::setAnchorY(cocos2d::Node *obj, float value)
{
    cocos2d::Vec2 anchor = obj->getAnchorPoint();
    anchor.y = value;
    obj->setAnchorPoint(anchor);
}

float NodeExtend::getWidth(cocos2d::Node *obj)
{
    return obj->getContentSize().width;
}

void NodeExtend::setWidth(cocos2d::Node *obj, float value)
{
    cocos2d::Size size = obj->getContentSize();
    size.width = value;
    obj->setContentSize(size);
}

float NodeExtend::getHeight(cocos2d::Node *obj)
{
    return obj->getContentSize().height;
}

void NodeExtend::setHeight(cocos2d::Node *obj, float value)
{
    cocos2d::Size size = obj->getContentSize();
    size.height = value;
    obj->setContentSize(size);
}

float NodeExtend::getAlpha(cocos2d::Node *obj)
{
    return obj->getOpacity() / 255.0f;
}

void NodeExtend::setAlpha(cocos2d::Node *obj, float value)
{
    obj->setOpacity((uint8_t)(value * 255.0f));
}

oluaret_t NodeExtend::__index(lua_State *L)
{
    if(!olua_isuserdata(L, 1)) {
        return 0;
    }
        
    if (olua_isstring(L, 2)) {
        auto self = olua_toobj<cocos2d::Node>(L, 1);
        cocos2d::Node *child = self->getChildByName(olua_tostring(L, 2));
        if (child) {
            olua_pushobj<cocos2d::Node>(L, child);
            olua_addref(L, 1, "children", -1, OLUA_FLAG_MULTIPLE);
            return 1;
        }
    }
    lua_settop(L, 2);
    olua_getvariable(L, 1);
    return 1;
}

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

cocos2d::Bounds NodeExtend::getBounds(cocos2d::Node *obj, cocos2d::Node *target, float left, float right, float top, float bottom)
{
    cocos2d::Vec3 p1(left, bottom, 0);
    cocos2d::Vec3 p2(right, top, 0);

    auto m = cocos2d::Mat4::IDENTITY;

    if (target == obj->getParent()) {
        m = obj->getNodeToParentTransform();
    } else if (target != obj) {
        auto ancestor = _find_ancestor(target, obj);
        if (!ancestor) {
            m = target->getWorldToNodeTransform() * obj->getNodeToWorldTransform();
        } else if (target == ancestor) {
            m = obj->getNodeToParentTransform(target);
        } else if (obj == ancestor) {
            m = target->getNodeToParentTransform(obj).getInversed();
        } else {
            m = target->getNodeToParentTransform(ancestor).getInversed() * obj->getNodeToParentTransform(ancestor);
        }
    }

    m.transformPoint(&p1);
    m.transformPoint(&p2);

    left = MIN(p1.x, p2.x);
    right = MAX(p1.x, p2.x);
    top = MAX(p1.y, p2.y);
    bottom = MIN(p1.y, p2.y);
    
    return cocos2d::Rect(left, bottom, right - left, top - bottom);
}

cocos2d::Vec4 Mat4Extend::transform(cocos2d::Mat4 *mat, const cocos2d::Vec4 &p)
{
    cocos2d::Vec4 result;
    mat->transformVector(p, &result);
    return result;
}

cocos2d::Vec3 Mat4Extend::transform(cocos2d::Mat4 *mat, const cocos2d::Vec3 &p)
{
    cocos2d::Vec3 result;
    mat->transformPoint(p, &result);
    return result;
}

cocos2d::Vec2 Mat4Extend::transform(cocos2d::Mat4 *mat, const cocos2d::Vec2 &p)
{
    cocos2d::Vec3 result;
    mat->transformPoint(cocos2d::Vec3(p.x, p.y, 0), &result);
    return cocos2d::Vec2(result.x, result.y);
}

cocos2d::Mat4 *Mat4Extend::__add(cocos2d::Mat4 *mat1, cocos2d::Mat4 *mat2)
{
    cocos2d::Mat4 *mat = new cocos2d::Mat4();
    *mat = *mat1 + *mat2;
    return mat;
}

cocos2d::Mat4 *Mat4Extend::__sub(cocos2d::Mat4 *mat1, cocos2d::Mat4 *mat2)
{
    cocos2d::Mat4 *mat = new cocos2d::Mat4();
    *mat = *mat1 - *mat2;
    return mat;
}

cocos2d::Mat4 *Mat4Extend::__mul(cocos2d::Mat4 *mat1, cocos2d::Mat4 *mat2)
{
    cocos2d::Mat4 *mat = new cocos2d::Mat4();
    *mat = (*mat1) * (*mat2);
    return mat;
}

#ifdef CCLUA_BUILD_SPINE
using namespace spine;

oluaret_t SkeletonDataExtend::__gc(lua_State *L)
{
    auto self = olua_toobj<spine::SkeletonData>(L, 1);
    lua_pushstring(L, ".ownership");
    olua_getvariable(L, 1);
    if (lua_toboolean(L, -1) && self) {
        olua_setrawobj(L, 1, nullptr);

        lua_pushstring(L, ".skel.attachment_loader");
        olua_getvariable(L, 1);
        auto attachment_loader = (spine::Cocos2dAtlasAttachmentLoader *)olua_torawobj(L, -1);
        delete attachment_loader;

        lua_pushstring(L, ".skel.atlas");
        olua_getvariable(L, 1);
        auto atlas = (spine::Atlas *)olua_torawobj(L, -1);
        delete atlas;

        lua_pushstring(L, ".skel.texture_loader");
        olua_getvariable(L, 1);
        auto texture_loader = (spine::Cocos2dTextureLoader *)olua_torawobj(L, -1);
        delete texture_loader;

        delete self;
    }
    return 0;
}

oluaret_t SkeletonDataExtend::create(lua_State *L, const char *skel_path, const char *atlas_path, float scale)
{
    auto texture_loader = new spine::Cocos2dTextureLoader();
    auto atlas = new spine::Atlas(atlas_path, texture_loader);
    spine::SkeletonData *skel_data = nullptr;
    spine::String error;
    auto attachment_loader = new spine::Cocos2dAtlasAttachmentLoader(atlas);

    if (strendwith(skel_path, ".skel")) {
        auto reader = new spine::SkeletonBinary(attachment_loader);
        reader->setScale(scale);
        skel_data = reader->readSkeletonDataFile(skel_path);
        error = reader->getError();
        delete reader;
    } else {
        auto reader = new spine::SkeletonJson(attachment_loader);
        reader->setScale(scale);
        skel_data = reader->readSkeletonDataFile(skel_path);
        error = reader->getError();
        delete reader;
    }

    if (!skel_data) {
        delete attachment_loader;
        delete atlas;
        delete texture_loader;
        luaL_error(L, "%s\nerror reading skeleton file: %s", error.buffer(), skel_path);
    }

    olua_pushobj<spine::SkeletonData>(L, skel_data);

    lua_pushstring(L, ".ownership");
    lua_pushboolean(L, true);
    olua_setvariable(L, -3);

    lua_pushstring(L, ".skel.texture_loader");
    olua_newrawobj(L, texture_loader);
    olua_setvariable(L, -3);

    lua_pushstring(L, ".skel.attachment_loader");
    olua_newrawobj(L, attachment_loader);
    olua_setvariable(L, -3);

    lua_pushstring(L, ".skel.atlas");
    olua_newrawobj(L, atlas);
    olua_setvariable(L, -3);

    return 1;
}
#endif
