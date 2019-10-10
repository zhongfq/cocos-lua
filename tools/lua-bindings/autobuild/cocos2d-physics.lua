-- AUTO BUILD, DON'T MODIFY!

require "autobuild.cocos2d-physics-types"

local olua = require "olua"
local typeconv = olua.typeconv
local typecls = olua.typecls
local cls = nil
local M = {}

olua.nowarning(typeconv, typecls, cls)

M.NAME = "cocos2d_physics"
M.HEADER_PATH = "../../frameworks/libxgame/src/lua-bindings/lua_cocos2d_physics.h"
M.SOURCE_PATH = "../../frameworks/libxgame/src/lua-bindings/lua_cocos2d_physics.cpp"
M.INCLUDES = [[
#include "lua-bindings/lua_cocos2d_physics.h"
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "lua-bindings/LuaCocosAdapter.h"
#include "xgame/xlua.h"
#include "xgame/xruntime.h"
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
]]
cls.var('onContactBegin', [[std::function<bool(@local PhysicsContact& contact)> onContactBegin = nullptr]])
cls.var('onContactPreSolve', [[std::function<bool(@local PhysicsContact& contact, @local PhysicsContactPreSolve& solve)> onContactPreSolve = nullptr]])
cls.var('onContactPostSolve', [[std::function<void(@local PhysicsContact& contact, @local const PhysicsContactPostSolve& solve)> onContactPostSolve = nullptr]])
cls.var('onContactSeparate', [[std::function<void(@local PhysicsContact& contact)> onContactSeparate = nullptr]])
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EventListenerPhysicsContactWithGroup'
cls.SUPERCLS = "cocos2d::EventListenerPhysicsContact"
cls.funcs [[
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EventListenerPhysicsContactWithBodies'
cls.SUPERCLS = "cocos2d::EventListenerPhysicsContact"
cls.funcs [[
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EventListenerPhysicsContactWithShapes'
cls.SUPERCLS = "cocos2d::EventListenerPhysicsContact"
cls.funcs [[
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PhysicsBody'
cls.SUPERCLS = "cocos2d::Component"
cls.funcs [[
    static PhysicsBody* create()
    static PhysicsBody* create(float mass)
    static PhysicsBody* create(float mass, float moment)
    static PhysicsBody* createCircle(float radius, const PhysicsMaterial& material = PHYSICSBODY_MATERIAL_DEFAULT, const Vec2& offset = Vec2::ZERO)
    static PhysicsBody* createBox(const Size& size, const PhysicsMaterial& material = PHYSICSBODY_MATERIAL_DEFAULT, const Vec2& offset = Vec2::ZERO)
    static PhysicsBody* createEdgeSegment(const Vec2& a, const Vec2& b, const PhysicsMaterial& material = PHYSICSBODY_MATERIAL_DEFAULT, float border = 1)
    static PhysicsBody* createEdgeBox(const Size& size, const PhysicsMaterial& material = PHYSICSBODY_MATERIAL_DEFAULT, float border = 1, const Vec2& offset = Vec2::ZERO)
    PhysicsShape* addShape(PhysicsShape* shape, bool addMassAndMoment = true)
    void removeShape(PhysicsShape* shape, bool reduceMassAndMoment = true)
    void removeShape(int tag, bool reduceMassAndMoment = true)
    void removeAllShapes(bool reduceMassAndMoment = true)
    const Vector<PhysicsShape*>& getShapes()
    PhysicsShape* getFirstShape()
    PhysicsShape* getShape(int tag)
    void applyForce(const Vec2& force, const Vec2& offset = Vec2::ZERO)
    void resetForces()
    void applyImpulse(const Vec2& impulse, const Vec2& offset = Vec2::ZERO)
    void applyTorque(float torque)
    void setVelocity(const Vec2& velocity)
    Vec2 getVelocity()
    void setAngularVelocity(float velocity)
    Vec2 getVelocityAtLocalPoint(const Vec2& point)
    Vec2 getVelocityAtWorldPoint(const Vec2& point)
    float getAngularVelocity()
    void setVelocityLimit(float limit)
    float getVelocityLimit()
    void setAngularVelocityLimit(float limit)
    float getAngularVelocityLimit()
    void removeFromWorld()
    PhysicsWorld* getWorld()
    const std::vector<PhysicsJoint*>& getJoints()
    Node* getNode()
    void setCategoryBitmask(int bitmask)
    void setContactTestBitmask(int bitmask)
    void setCollisionBitmask(int bitmask)
    int getCategoryBitmask()
    int getContactTestBitmask()
    int getCollisionBitmask()
    void setGroup(int group)
    int getGroup()
    Vec2 getPosition()
    float getRotation()
    void setPositionOffset(const Vec2& position)
    const Vec2& getPositionOffset()
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
    Vec2 world2Local(const Vec2& point)
    Vec2 local2World(const Vec2& point)
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
    PhysicsShape* getShapeA()
    PhysicsShape* getShapeB()
    void* getData()
    void setData(void* data)
    EventCode getEventCode()
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
    Vec2 getSurfaceVelocity()
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
    Vec2 getSurfaceVelocity()
    void setRestitution(float restitution)
    void setFriction(float friction)
    void setSurfaceVelocity(const Vec2& velocity)
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
    PhysicsBody* getBodyA()
    PhysicsBody* getBodyB()
    PhysicsWorld* getWorld()
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
    static PhysicsJointDistance* construct(PhysicsBody* a, PhysicsBody* b, const Vec2& anchr1, const Vec2& anchr2)
    float getDistance()
    void setDistance(float distance)
]]
cls.props [[
    distance
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PhysicsJointFixed'
cls.SUPERCLS = "cocos2d::PhysicsJoint"
cls.funcs [[
    static PhysicsJointFixed* construct(PhysicsBody* a, PhysicsBody* b, const Vec2& anchr)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PhysicsJointGear'
cls.SUPERCLS = "cocos2d::PhysicsJoint"
cls.funcs [[
    static PhysicsJointGear* construct(PhysicsBody* a, PhysicsBody* b, float phase, float ratio)
    float getPhase()
    void setPhase(float phase)
    float getRatio()
    void setRatio(float ratchet)
]]
cls.props [[
    phase
    ratio
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PhysicsJointGroove'
cls.SUPERCLS = "cocos2d::PhysicsJoint"
cls.funcs [[
    static PhysicsJointGroove* construct(PhysicsBody* a, PhysicsBody* b, const Vec2& grooveA, const Vec2& grooveB, const Vec2& anchr2)
    Vec2 getGrooveA()
    void setGrooveA(const Vec2& grooveA)
    Vec2 getGrooveB()
    void setGrooveB(const Vec2& grooveB)
    Vec2 getAnchr2()
    void setAnchr2(const Vec2& anchr2)
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
    static PhysicsJointLimit* construct(PhysicsBody* a, PhysicsBody* b, const Vec2& anchr1, const Vec2& anchr2)
    static PhysicsJointLimit* construct(PhysicsBody* a, PhysicsBody* b, const Vec2& anchr1, const Vec2& anchr2, float min, float max)
    Vec2 getAnchr1()
    void setAnchr1(const Vec2& anchr1)
    Vec2 getAnchr2()
    void setAnchr2(const Vec2& anchr2)
    float getMin()
    void setMin(float min)
    float getMax()
    void setMax(float max)
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
    static PhysicsJointMotor* construct(PhysicsBody* a, PhysicsBody* b, float rate)
    float getRate()
    void setRate(float rate)
]]
cls.props [[
    rate
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PhysicsJointPin'
cls.SUPERCLS = "cocos2d::PhysicsJoint"
cls.funcs [[
    static PhysicsJointPin* construct(PhysicsBody* a, PhysicsBody* b, const Vec2& pivot)
    static PhysicsJointPin* construct(PhysicsBody* a, PhysicsBody* b, const Vec2& anchr1, const Vec2& anchr2)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PhysicsJointRatchet'
cls.SUPERCLS = "cocos2d::PhysicsJoint"
cls.funcs [[
    static PhysicsJointRatchet* construct(PhysicsBody* a, PhysicsBody* b, float phase, float ratchet)
    float getAngle()
    void setAngle(float angle)
    float getPhase()
    void setPhase(float phase)
    float getRatchet()
    void setRatchet(float ratchet)
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
    static PhysicsJointRotaryLimit* construct(PhysicsBody* a, PhysicsBody* b, float min, float max)
    static PhysicsJointRotaryLimit* construct(PhysicsBody* a, PhysicsBody* b)
    float getMin()
    void setMin(float min)
    float getMax()
    void setMax(float max)
]]
cls.props [[
    min
    max
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PhysicsJointRotarySpring'
cls.SUPERCLS = "cocos2d::PhysicsJoint"
cls.funcs [[
    static PhysicsJointRotarySpring* construct(PhysicsBody* a, PhysicsBody* b, float stiffness, float damping)
    float getRestAngle()
    void setRestAngle(float restAngle)
    float getStiffness()
    void setStiffness(float stiffness)
    float getDamping()
    void setDamping(float damping)
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
    static PhysicsJointSpring* construct(PhysicsBody* a, PhysicsBody* b, const Vec2& anchr1, const Vec2& anchr2, float stiffness, float damping)
    Vec2 getAnchr1()
    void setAnchr1(const Vec2& anchr1)
    Vec2 getAnchr2()
    void setAnchr2(const Vec2& anchr2)
    float getRestLength()
    void setRestLength(float restLength)
    float getStiffness()
    void setStiffness(float stiffness)
    float getDamping()
    void setDamping(float damping)
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
    PhysicsBody* getBody()
    Type getType()
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
    const PhysicsMaterial& getMaterial()
    void setMaterial(const PhysicsMaterial& material)
    bool isSensor()
    void setSensor(bool sensor)
    float calculateDefaultMoment()
    Vec2 getOffset()
    Vec2 getCenter()
    bool containsPoint(const Vec2& point)
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
    Vec2 getPoint(int i)
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
    static PhysicsShapeBox* create(const Size& size, const PhysicsMaterial& material = PHYSICSSHAPE_MATERIAL_DEFAULT, const Vec2& offset = Vec2::ZERO, float radius = 0.0f)
    Size getSize()
]]
cls.props [[
    size
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PhysicsShapeCircle'
cls.SUPERCLS = "cocos2d::PhysicsShape"
cls.funcs [[
    static PhysicsShapeCircle* create(float radius, const PhysicsMaterial& material = PHYSICSSHAPE_MATERIAL_DEFAULT, const Vec2& offset = Vec2(0, 0))
    static float calculateArea(float radius)
    static float calculateMoment(float mass, float radius, const Vec2& offset = Vec2::ZERO)
    float getRadius()
]]
cls.props [[
    radius
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PhysicsShapeEdgeBox'
cls.SUPERCLS = "cocos2d::PhysicsShapeEdgePolygon"
cls.funcs [[
    static PhysicsShapeEdgeBox* create(const Size& size, const PhysicsMaterial& material = PHYSICSSHAPE_MATERIAL_DEFAULT, float border = 0, const Vec2& offset = Vec2::ZERO)
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
    static PhysicsShapeEdgeSegment* create(const Vec2& a, const Vec2& b, const PhysicsMaterial& material = PHYSICSSHAPE_MATERIAL_DEFAULT, float border = 1)
    Vec2 getPointA()
    Vec2 getPointB()
]]
cls.props [[
    pointA
    pointB
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PhysicsRayCastInfo'
cls.funcs [[
]]
cls.var('shape', [[PhysicsShape* shape]])
cls.var('start', [[Vec2 start]])
cls.var('end', [[Vec2 end]])
cls.var('contact', [[Vec2 contact]])
cls.var('normal', [[Vec2 normal]])
cls.var('fraction', [[float fraction]])
cls.var('data', [[void* data]])
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PhysicsWorld'
cls.funcs [[
    void addJoint(PhysicsJoint* joint)
    void removeJoint(PhysicsJoint* joint, bool destroy = true)
    void removeAllJoints(bool destroy = true)
    void removeBody(PhysicsBody* body)
    void removeBody(int tag)
    void removeAllBodies()
    Vector<PhysicsShape*> getShapes(const Vec2& point)
    PhysicsShape* getShape(const Vec2& point)
    const Vector<PhysicsBody*>& getAllBodies()
    PhysicsBody* getBody(int tag)
    Vec2 getGravity()
    void setGravity(const Vec2& gravity)
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
    void setDebugDrawGlobalZOrder(float globalZOrder)
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
        'void rayCast(std::function<bool(@local PhysicsWorld& world, @local const PhysicsRayCastInfo& info, void* data)> func, const Vec2& start, const Vec2& end, void* data)',
    },
    TAG_MAKER = 'olua_makecallbacktag("rayCast")',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    CALLONCE = false,
    REMOVE = false,
}
cls.callback {
    FUNCS =  {
        'void queryRect(std::function<bool(@local PhysicsWorld&, @local PhysicsShape&, void*)> func, const Rect& rect, void* data)',
    },
    TAG_MAKER = 'olua_makecallbacktag("queryRect")',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    CALLONCE = false,
    REMOVE = false,
}
cls.callback {
    FUNCS =  {
        'void queryPoint(std::function<bool(@local PhysicsWorld&, @local PhysicsShape&, void*)> func, const Vec2& point, void* data)',
    },
    TAG_MAKER = 'olua_makecallbacktag("queryPoint")',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    CALLONCE = false,
    REMOVE = false,
}
cls.callback {
    FUNCS =  {
        'void setPreUpdateCallback(@nullable const std::function<void()> &callback)',
    },
    TAG_MAKER = 'olua_makecallbacktag("preUpdateCallback")',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    CALLONCE = false,
    REMOVE = false,
}
cls.callback {
    FUNCS =  {
        'void setPostUpdateCallback(@nullable const std::function<void()> &callback)',
    },
    TAG_MAKER = 'olua_makecallbacktag("postUpdateCallback")',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    CALLONCE = false,
    REMOVE = false,
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
