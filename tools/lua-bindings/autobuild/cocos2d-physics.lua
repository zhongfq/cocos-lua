-- AUTO BUILD, DON'T MODIFY!

require "autobuild.cocos2d-physics-types"

local olua = require "olua"
local typeconv = olua.typeconv
local typecls = olua.typecls
local cls = nil
local M = {}

M.NAME = "cocos2d_physics"
M.PATH = "../../frameworks/libxgame/src/lua-bindings"
M.INCLUDES = [[
#include "lua-bindings/lua_cocos2d_physics.h"
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "lua-bindings/LuaCocosAdapter.h"
#include "xgame/xlua.h"
#include "cocos2d.h"
]]
M.CHUNK = [[
using namespace cocos2d;
]]

M.CONVS = {
    typeconv {
        CPPCLS = 'cocos2d::PhysicsMaterial',
        DEF = [[
            float density;
            float restitution;
            float friction;
        ]],
    },
}

M.CLASSES = {}

cls = typecls 'cocos2d::EventListenerPhysicsContact'
cls.SUPERCLS = "cocos2d::EventListenerCustom"
cls.funcs [[
    static cocos2d::EventListenerPhysicsContact *create()
]]
cls.var('onContactBegin', [[@nullable @local std::function<bool (PhysicsContact &)> onContactBegin]])
cls.var('onContactPreSolve', [[@nullable @local std::function<bool (PhysicsContact &, PhysicsContactPreSolve &)> onContactPreSolve]])
cls.var('onContactPostSolve', [[@nullable @local std::function<void (PhysicsContact &, const PhysicsContactPostSolve &)> onContactPostSolve]])
cls.var('onContactSeparate', [[@nullable @local std::function<void (PhysicsContact &)> onContactSeparate]])
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EventListenerPhysicsContactWithGroup'
cls.SUPERCLS = "cocos2d::EventListenerPhysicsContact"
cls.funcs [[
    static cocos2d::EventListenerPhysicsContactWithGroup *create(int group)
    bool hitTest(cocos2d::PhysicsShape *shapeA, cocos2d::PhysicsShape *shapeB)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EventListenerPhysicsContactWithBodies'
cls.SUPERCLS = "cocos2d::EventListenerPhysicsContact"
cls.funcs [[
    static cocos2d::EventListenerPhysicsContactWithBodies *create(cocos2d::PhysicsBody *bodyA, cocos2d::PhysicsBody *bodyB)
    bool hitTest(cocos2d::PhysicsShape *shapeA, cocos2d::PhysicsShape *shapeB)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EventListenerPhysicsContactWithShapes'
cls.SUPERCLS = "cocos2d::EventListenerPhysicsContact"
cls.funcs [[
    static cocos2d::EventListenerPhysicsContactWithShapes *create(cocos2d::PhysicsShape *shapeA, cocos2d::PhysicsShape *shapeB)
    bool hitTest(cocos2d::PhysicsShape *shapeA, cocos2d::PhysicsShape *shapeB)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PhysicsBody'
cls.SUPERCLS = "cocos2d::Component"
cls.const('COMPONENT_NAME', 'cocos2d::PhysicsBody::COMPONENT_NAME', 'const std::string')
cls.funcs [[
    static cocos2d::PhysicsBody *create()
    static cocos2d::PhysicsBody *create(float mass)
    static cocos2d::PhysicsBody *create(float mass, float moment)
    static cocos2d::PhysicsBody *createCircle(float radius, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset)
    static cocos2d::PhysicsBody *createBox(const cocos2d::Size &size, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset)
    static cocos2d::PhysicsBody *createEdgeSegment(const cocos2d::Vec2 &a, const cocos2d::Vec2 &b, @optional const cocos2d::PhysicsMaterial &material, @optional float border)
    static cocos2d::PhysicsBody *createEdgeBox(const cocos2d::Size &size, @optional const cocos2d::PhysicsMaterial &material, @optional float border, @optional const cocos2d::Vec2 &offset)
    cocos2d::PhysicsShape *addShape(cocos2d::PhysicsShape *shape, @optional bool addMassAndMoment)
    void removeShape(cocos2d::PhysicsShape *shape, @optional bool reduceMassAndMoment)
    void removeShape(int tag, @optional bool reduceMassAndMoment)
    void removeAllShapes(@optional bool reduceMassAndMoment)
    const Vector<cocos2d::PhysicsShape *> &getShapes()
    cocos2d::PhysicsShape *getFirstShape()
    cocos2d::PhysicsShape *getShape(int tag)
    void applyForce(const cocos2d::Vec2 &force, @optional const cocos2d::Vec2 &offset)
    void resetForces()
    void applyImpulse(const cocos2d::Vec2 &impulse, @optional const cocos2d::Vec2 &offset)
    void applyTorque(float torque)
    void setVelocity(const cocos2d::Vec2 &velocity)
    cocos2d::Vec2 getVelocity()
    void setAngularVelocity(float velocity)
    cocos2d::Vec2 getVelocityAtLocalPoint(const cocos2d::Vec2 &point)
    cocos2d::Vec2 getVelocityAtWorldPoint(const cocos2d::Vec2 &point)
    float getAngularVelocity()
    void setVelocityLimit(float limit)
    float getVelocityLimit()
    void setAngularVelocityLimit(float limit)
    float getAngularVelocityLimit()
    void removeFromWorld()
    cocos2d::PhysicsWorld *getWorld()
    const std::vector<PhysicsJoint *> &getJoints()
    cocos2d::Node *getNode()
    void setCategoryBitmask(int bitmask)
    void setContactTestBitmask(int bitmask)
    void setCollisionBitmask(int bitmask)
    int getCategoryBitmask()
    int getContactTestBitmask()
    int getCollisionBitmask()
    void setGroup(int group)
    int getGroup()
    cocos2d::Vec2 getPosition()
    float getRotation()
    void setPositionOffset(const cocos2d::Vec2 &position)
    const cocos2d::Vec2 &getPositionOffset()
    void setRotationOffset(float rotation)
    float getRotationOffset()
    bool isDynamic()
    void setDynamic(bool dynamic)
    void setMass(float mass)
    float getMass()
    void addMass(float mass)
    void setMoment(float moment)
    float getMoment()
    void addMoment(float moment)
    float getLinearDamping()
    void setLinearDamping(float damping)
    float getAngularDamping()
    void setAngularDamping(float damping)
    bool isResting()
    void setResting(bool rest)
    bool isRotationEnabled()
    void setRotationEnable(bool enable)
    bool isGravityEnabled()
    void setGravityEnable(bool enable)
    int getTag()
    void setTag(int tag)
    cocos2d::Vec2 world2Local(const cocos2d::Vec2 &point)
    cocos2d::Vec2 local2World(const cocos2d::Vec2 &point)
]]
cls.props [[
    shapes
    firstShape
    velocity
    angularVelocity
    velocityLimit
    angularVelocityLimit
    world
    joints
    node
    categoryBitmask
    contactTestBitmask
    collisionBitmask
    group
    position
    rotation
    positionOffset
    rotationOffset
    dynamic
    mass
    moment
    linearDamping
    angularDamping
    resting
    rotationEnabled
    gravityEnabled
    tag
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PhysicsContact::EventCode'
cls.enums [[
    NONE
    BEGIN
    PRESOLVE
    POSTSOLVE
    SEPARATE
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PhysicsContact'
cls.SUPERCLS = "cocos2d::EventCustom"
cls.funcs [[
    cocos2d::PhysicsShape *getShapeA()
    cocos2d::PhysicsShape *getShapeB()
    void *getData()
    void setData(void *data)
    cocos2d::PhysicsContact::EventCode getEventCode()
]]
cls.props [[
    shapeA
    shapeB
    data
    eventCode
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PhysicsContactPostSolve'
cls.funcs [[
    float getRestitution()
    float getFriction()
    cocos2d::Vec2 getSurfaceVelocity()
]]
cls.props [[
    restitution
    friction
    surfaceVelocity
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PhysicsContactPreSolve'
cls.funcs [[
    float getRestitution()
    float getFriction()
    cocos2d::Vec2 getSurfaceVelocity()
    void setRestitution(float restitution)
    void setFriction(float friction)
    void setSurfaceVelocity(const cocos2d::Vec2 &velocity)
    void ignore()
]]
cls.props [[
    restitution
    friction
    surfaceVelocity
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PhysicsJoint'
cls.funcs [[
    cocos2d::PhysicsBody *getBodyA()
    cocos2d::PhysicsBody *getBodyB()
    cocos2d::PhysicsWorld *getWorld()
    int getTag()
    void setTag(int tag)
    bool isEnabled()
    void setEnable(bool enable)
    bool isCollisionEnabled()
    void setCollisionEnable(bool enable)
    void removeFormWorld()
    void setMaxForce(float force)
    float getMaxForce()
]]
cls.props [[
    bodyA
    bodyB
    world
    tag
    enabled
    collisionEnabled
    maxForce
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PhysicsJointDistance'
cls.SUPERCLS = "cocos2d::PhysicsJoint"
cls.funcs [[
    static cocos2d::PhysicsJointDistance *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b, const cocos2d::Vec2 &anchr1, const cocos2d::Vec2 &anchr2)
    float getDistance()
    void setDistance(float distance)
    bool createConstraints()
]]
cls.props [[
    distance
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PhysicsJointFixed'
cls.SUPERCLS = "cocos2d::PhysicsJoint"
cls.funcs [[
    static cocos2d::PhysicsJointFixed *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b, const cocos2d::Vec2 &anchr)
    bool createConstraints()
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PhysicsJointGear'
cls.SUPERCLS = "cocos2d::PhysicsJoint"
cls.funcs [[
    static cocos2d::PhysicsJointGear *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b, float phase, float ratio)
    float getPhase()
    void setPhase(float phase)
    float getRatio()
    void setRatio(float ratchet)
    bool createConstraints()
]]
cls.props [[
    phase
    ratio
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PhysicsJointGroove'
cls.SUPERCLS = "cocos2d::PhysicsJoint"
cls.funcs [[
    static cocos2d::PhysicsJointGroove *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b, const cocos2d::Vec2 &grooveA, const cocos2d::Vec2 &grooveB, const cocos2d::Vec2 &anchr2)
    cocos2d::Vec2 getGrooveA()
    void setGrooveA(const cocos2d::Vec2 &grooveA)
    cocos2d::Vec2 getGrooveB()
    void setGrooveB(const cocos2d::Vec2 &grooveB)
    cocos2d::Vec2 getAnchr2()
    void setAnchr2(const cocos2d::Vec2 &anchr2)
    bool createConstraints()
]]
cls.props [[
    grooveA
    grooveB
    anchr2
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PhysicsJointLimit'
cls.SUPERCLS = "cocos2d::PhysicsJoint"
cls.funcs [[
    static cocos2d::PhysicsJointLimit *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b, const cocos2d::Vec2 &anchr1, const cocos2d::Vec2 &anchr2)
    static cocos2d::PhysicsJointLimit *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b, const cocos2d::Vec2 &anchr1, const cocos2d::Vec2 &anchr2, float min, float max)
    cocos2d::Vec2 getAnchr1()
    void setAnchr1(const cocos2d::Vec2 &anchr1)
    cocos2d::Vec2 getAnchr2()
    void setAnchr2(const cocos2d::Vec2 &anchr2)
    float getMin()
    void setMin(float min)
    float getMax()
    void setMax(float max)
    bool createConstraints()
]]
cls.props [[
    anchr1
    anchr2
    min
    max
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PhysicsJointMotor'
cls.SUPERCLS = "cocos2d::PhysicsJoint"
cls.funcs [[
    static cocos2d::PhysicsJointMotor *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b, float rate)
    float getRate()
    void setRate(float rate)
    bool createConstraints()
]]
cls.props [[
    rate
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PhysicsJointPin'
cls.SUPERCLS = "cocos2d::PhysicsJoint"
cls.funcs [[
    static cocos2d::PhysicsJointPin *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b, const cocos2d::Vec2 &pivot)
    static cocos2d::PhysicsJointPin *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b, const cocos2d::Vec2 &anchr1, const cocos2d::Vec2 &anchr2)
    bool createConstraints()
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PhysicsJointRatchet'
cls.SUPERCLS = "cocos2d::PhysicsJoint"
cls.funcs [[
    static cocos2d::PhysicsJointRatchet *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b, float phase, float ratchet)
    float getAngle()
    void setAngle(float angle)
    float getPhase()
    void setPhase(float phase)
    float getRatchet()
    void setRatchet(float ratchet)
    bool createConstraints()
]]
cls.props [[
    angle
    phase
    ratchet
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PhysicsJointRotaryLimit'
cls.SUPERCLS = "cocos2d::PhysicsJoint"
cls.funcs [[
    static cocos2d::PhysicsJointRotaryLimit *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b, float min, float max)
    static cocos2d::PhysicsJointRotaryLimit *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b)
    float getMin()
    void setMin(float min)
    float getMax()
    void setMax(float max)
    bool createConstraints()
]]
cls.props [[
    min
    max
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PhysicsJointRotarySpring'
cls.SUPERCLS = "cocos2d::PhysicsJoint"
cls.funcs [[
    static cocos2d::PhysicsJointRotarySpring *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b, float stiffness, float damping)
    float getRestAngle()
    void setRestAngle(float restAngle)
    float getStiffness()
    void setStiffness(float stiffness)
    float getDamping()
    void setDamping(float damping)
    bool createConstraints()
]]
cls.props [[
    restAngle
    stiffness
    damping
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PhysicsJointSpring'
cls.SUPERCLS = "cocos2d::PhysicsJoint"
cls.funcs [[
    static cocos2d::PhysicsJointSpring *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b, const cocos2d::Vec2 &anchr1, const cocos2d::Vec2 &anchr2, float stiffness, float damping)
    cocos2d::Vec2 getAnchr1()
    void setAnchr1(const cocos2d::Vec2 &anchr1)
    cocos2d::Vec2 getAnchr2()
    void setAnchr2(const cocos2d::Vec2 &anchr2)
    float getRestLength()
    void setRestLength(float restLength)
    float getStiffness()
    void setStiffness(float stiffness)
    float getDamping()
    void setDamping(float damping)
    bool createConstraints()
]]
cls.props [[
    anchr1
    anchr2
    restLength
    stiffness
    damping
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PhysicsShape::Type'
cls.enums [[
    UNKNOWN
    CIRCLE
    BOX
    POLYGON
    EDGESEGMENT
    EDGEBOX
    EDGEPOLYGON
    EDGECHAIN
    POLYGEN
    EDGEPOLYGEN
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PhysicsShape'
cls.SUPERCLS = "cocos2d::Ref"
cls.funcs [[
    cocos2d::PhysicsBody *getBody()
    cocos2d::PhysicsShape::Type getType()
    float getArea()
    float getMoment()
    void setMoment(float moment)
    void setTag(int tag)
    int getTag()
    float getMass()
    void setMass(float mass)
    float getDensity()
    void setDensity(float density)
    float getRestitution()
    void setRestitution(float restitution)
    float getFriction()
    void setFriction(float friction)
    const cocos2d::PhysicsMaterial &getMaterial()
    void setMaterial(const cocos2d::PhysicsMaterial &material)
    bool isSensor()
    void setSensor(bool sensor)
    float calculateDefaultMoment()
    cocos2d::Vec2 getOffset()
    cocos2d::Vec2 getCenter()
    bool containsPoint(const cocos2d::Vec2 &point)
    void setCategoryBitmask(int bitmask)
    int getCategoryBitmask()
    void setContactTestBitmask(int bitmask)
    int getContactTestBitmask()
    void setCollisionBitmask(int bitmask)
    int getCollisionBitmask()
    void setGroup(int group)
    int getGroup()
]]
cls.props [[
    body
    type
    area
    moment
    tag
    mass
    density
    restitution
    friction
    material
    sensor
    offset
    center
    categoryBitmask
    contactTestBitmask
    collisionBitmask
    group
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PhysicsShapePolygon'
cls.SUPERCLS = "cocos2d::PhysicsShape"
cls.funcs [[
    cocos2d::Vec2 getPoint(int i)
    int getPointsCount()
]]
cls.props [[
    pointsCount
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PhysicsShapeEdgePolygon'
cls.SUPERCLS = "cocos2d::PhysicsShape"
cls.funcs [[
    int getPointsCount()
]]
cls.props [[
    pointsCount
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PhysicsShapeBox'
cls.SUPERCLS = "cocos2d::PhysicsShapePolygon"
cls.funcs [[
    static cocos2d::PhysicsShapeBox *create(const cocos2d::Size &size, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset, @optional float radius)
    cocos2d::Size getSize()
]]
cls.props [[
    size
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PhysicsShapeCircle'
cls.SUPERCLS = "cocos2d::PhysicsShape"
cls.funcs [[
    static cocos2d::PhysicsShapeCircle *create(float radius, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset)
    static float calculateArea(float radius)
    static float calculateMoment(float mass, float radius, @optional const cocos2d::Vec2 &offset)
    float getRadius()
]]
cls.props [[
    radius
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PhysicsShapeEdgeBox'
cls.SUPERCLS = "cocos2d::PhysicsShapeEdgePolygon"
cls.funcs [[
    static cocos2d::PhysicsShapeEdgeBox *create(const cocos2d::Size &size, @optional const cocos2d::PhysicsMaterial &material, @optional float border, @optional const cocos2d::Vec2 &offset)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PhysicsShapeEdgeChain'
cls.SUPERCLS = "cocos2d::PhysicsShape"
cls.funcs [[
    int getPointsCount()
]]
cls.props [[
    pointsCount
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PhysicsShapeEdgeSegment'
cls.SUPERCLS = "cocos2d::PhysicsShape"
cls.funcs [[
    static cocos2d::PhysicsShapeEdgeSegment *create(const cocos2d::Vec2 &a, const cocos2d::Vec2 &b, @optional const cocos2d::PhysicsMaterial &material, @optional float border)
    cocos2d::Vec2 getPointA()
    cocos2d::Vec2 getPointB()
]]
cls.props [[
    pointA
    pointB
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PhysicsRayCastInfo'
cls.funcs [[
]]
cls.var('shape', [[cocos2d::PhysicsShape *shape]])
cls.var('start', [[cocos2d::Vec2 start]])
cls.var('end', [[cocos2d::Vec2 end]])
cls.var('contact', [[cocos2d::Vec2 contact]])
cls.var('normal', [[cocos2d::Vec2 normal]])
cls.var('fraction', [[float fraction]])
cls.var('data', [[void *data]])
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PhysicsWorld'
cls.const('DEBUGDRAW_NONE', 'cocos2d::PhysicsWorld::DEBUGDRAW_NONE', 'const int')
cls.const('DEBUGDRAW_SHAPE', 'cocos2d::PhysicsWorld::DEBUGDRAW_SHAPE', 'const int')
cls.const('DEBUGDRAW_JOINT', 'cocos2d::PhysicsWorld::DEBUGDRAW_JOINT', 'const int')
cls.const('DEBUGDRAW_CONTACT', 'cocos2d::PhysicsWorld::DEBUGDRAW_CONTACT', 'const int')
cls.const('DEBUGDRAW_ALL', 'cocos2d::PhysicsWorld::DEBUGDRAW_ALL', 'const int')
cls.funcs [[
    void addJoint(cocos2d::PhysicsJoint *joint)
    void removeJoint(cocos2d::PhysicsJoint *joint, @optional bool destroy)
    void removeAllJoints(@optional bool destroy)
    void removeBody(cocos2d::PhysicsBody *body)
    void removeBody(int tag)
    void removeAllBodies()
    Vector<cocos2d::PhysicsShape *> getShapes(const cocos2d::Vec2 &point)
    cocos2d::PhysicsShape *getShape(const cocos2d::Vec2 &point)
    const Vector<cocos2d::PhysicsBody *> &getAllBodies()
    cocos2d::PhysicsBody *getBody(int tag)
    cocos2d::Vec2 getGravity()
    void setGravity(const cocos2d::Vec2 &gravity)
    void setSpeed(float speed)
    float getSpeed()
    void setUpdateRate(int rate)
    int getUpdateRate()
    void setSubsteps(int steps)
    int getSubsteps()
    void setFixedUpdateRate(int updatesPerSecond)
    int getFixedUpdateRate()
    void setDebugDrawMask(int mask)
    int getDebugDrawMask()
    void setAutoStep(bool autoStep)
    bool isAutoStep()
    void step(float delta)
]]
cls.func('getScene', [[{
    auto self = olua_toobj<cocos2d::PhysicsWorld>(L, 1);
    cocos2d::Scene &scene = self->getScene();
    olua_push_cppobj<cocos2d::Scene>(L, &scene);
    return 1;
}]])
cls.prop('scene')
cls.callback {
    FUNCS =  {
        'void setPreUpdateCallback(@nullable @local const std::function<void ()> &callback)'
    },
    TAG_MAKER = 'PreUpdateCallback',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        'void setPostUpdateCallback(@nullable @local const std::function<void ()> &callback)'
    },
    TAG_MAKER = 'PostUpdateCallback',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        'void rayCast(@local std::function<bool (PhysicsWorld &, const PhysicsRayCastInfo &, void *)> func, const cocos2d::Vec2 &start, const cocos2d::Vec2 &end, void *data)'
    },
    TAG_MAKER = 'rayCast',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        'void queryRect(@local std::function<bool (PhysicsWorld &, PhysicsShape &, void *)> func, const cocos2d::Rect &rect, void *data)'
    },
    TAG_MAKER = 'queryRect',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        'void queryPoint(@local std::function<bool (PhysicsWorld &, PhysicsShape &, void *)> func, const cocos2d::Vec2 &point, void *data)'
    },
    TAG_MAKER = 'queryPoint',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.props [[
    allBodies
    gravity
    speed
    updateRate
    substeps
    fixedUpdateRate
    debugDrawMask
    autoStep
]]
M.CLASSES[#M.CLASSES + 1] = cls

return M
