-- AUTO BUILD, DON'T MODIFY!

dofile "autobuild/cocos2d-physics-types.lua"

local olua = require "olua"
local typeconv = olua.typeconv
local typecls = olua.typecls
local cls = nil
local M = {}

M.NAME = "cocos2d_physics"
M.PATH = "../../frameworks/libxgame/src/lua-bindings"
M.INCLUDES = [[
    #include "lua-bindings/lua_conv.h"
    #include "lua-bindings/lua_conv_manual.h"
    #include "lua-bindings/LuaCocosAdapter.h"
    #include "xgame/xlua.h"
    #include "cocos2d.h"
]]
M.CHUNK = 'using namespace cocos2d;'

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
cls.SUPERCLS = 'cocos2d::EventListenerCustom'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::EventListenerPhysicsContact *create()')
cls.var('onContactBegin', '@nullable @local std::function<bool (PhysicsContact &)> onContactBegin')
cls.var('onContactPreSolve', '@nullable @local std::function<bool (PhysicsContact &, PhysicsContactPreSolve &)> onContactPreSolve')
cls.var('onContactPostSolve', '@nullable @local std::function<void (PhysicsContact &, const PhysicsContactPostSolve &)> onContactPostSolve')
cls.var('onContactSeparate', '@nullable @local std::function<void (PhysicsContact &)> onContactSeparate')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EventListenerPhysicsContactWithGroup'
cls.SUPERCLS = 'cocos2d::EventListenerPhysicsContact'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::EventListenerPhysicsContactWithGroup *create(int group)')
cls.func(nil, 'bool hitTest(cocos2d::PhysicsShape *shapeA, cocos2d::PhysicsShape *shapeB)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EventListenerPhysicsContactWithBodies'
cls.SUPERCLS = 'cocos2d::EventListenerPhysicsContact'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::EventListenerPhysicsContactWithBodies *create(cocos2d::PhysicsBody *bodyA, cocos2d::PhysicsBody *bodyB)')
cls.func(nil, 'bool hitTest(cocos2d::PhysicsShape *shapeA, cocos2d::PhysicsShape *shapeB)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EventListenerPhysicsContactWithShapes'
cls.SUPERCLS = 'cocos2d::EventListenerPhysicsContact'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::EventListenerPhysicsContactWithShapes *create(cocos2d::PhysicsShape *shapeA, cocos2d::PhysicsShape *shapeB)')
cls.func(nil, 'bool hitTest(cocos2d::PhysicsShape *shapeA, cocos2d::PhysicsShape *shapeB)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PhysicsBody'
cls.SUPERCLS = 'cocos2d::Component'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.const('COMPONENT_NAME', 'cocos2d::PhysicsBody::COMPONENT_NAME', 'const std::string')
cls.func(nil, 'static cocos2d::PhysicsBody *create()', 'static cocos2d::PhysicsBody *create(float mass)', 'static cocos2d::PhysicsBody *create(float mass, float moment)')
cls.func(nil, 'static cocos2d::PhysicsBody *createCircle(float radius, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset)')
cls.func(nil, 'static cocos2d::PhysicsBody *createBox(const cocos2d::Size &size, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset)')
cls.func(nil, 'static cocos2d::PhysicsBody *createEdgeSegment(const cocos2d::Vec2 &a, const cocos2d::Vec2 &b, @optional const cocos2d::PhysicsMaterial &material, @optional float border)')
cls.func(nil, 'static cocos2d::PhysicsBody *createEdgeBox(const cocos2d::Size &size, @optional const cocos2d::PhysicsMaterial &material, @optional float border, @optional const cocos2d::Vec2 &offset)')
cls.func(nil, 'cocos2d::PhysicsShape *addShape(cocos2d::PhysicsShape *shape, @optional bool addMassAndMoment)')
cls.func(nil, 'void removeShape(cocos2d::PhysicsShape *shape, @optional bool reduceMassAndMoment)', 'void removeShape(int tag, @optional bool reduceMassAndMoment)')
cls.func(nil, 'void removeAllShapes(@optional bool reduceMassAndMoment)')
cls.func(nil, 'const Vector<cocos2d::PhysicsShape *> &getShapes()')
cls.func(nil, 'cocos2d::PhysicsShape *getFirstShape()')
cls.func(nil, 'cocos2d::PhysicsShape *getShape(int tag)')
cls.func(nil, 'void applyForce(const cocos2d::Vec2 &force, @optional const cocos2d::Vec2 &offset)')
cls.func(nil, 'void resetForces()')
cls.func(nil, 'void applyImpulse(const cocos2d::Vec2 &impulse, @optional const cocos2d::Vec2 &offset)')
cls.func(nil, 'void applyTorque(float torque)')
cls.func(nil, 'void setVelocity(const cocos2d::Vec2 &velocity)')
cls.func(nil, 'cocos2d::Vec2 getVelocity()')
cls.func(nil, 'void setAngularVelocity(float velocity)')
cls.func(nil, 'cocos2d::Vec2 getVelocityAtLocalPoint(const cocos2d::Vec2 &point)')
cls.func(nil, 'cocos2d::Vec2 getVelocityAtWorldPoint(const cocos2d::Vec2 &point)')
cls.func(nil, 'float getAngularVelocity()')
cls.func(nil, 'void setVelocityLimit(float limit)')
cls.func(nil, 'float getVelocityLimit()')
cls.func(nil, 'void setAngularVelocityLimit(float limit)')
cls.func(nil, 'float getAngularVelocityLimit()')
cls.func(nil, 'void removeFromWorld()')
cls.func(nil, 'cocos2d::PhysicsWorld *getWorld()')
cls.func(nil, 'const std::vector<PhysicsJoint *> &getJoints()')
cls.func(nil, 'cocos2d::Node *getNode()')
cls.func(nil, 'void setCategoryBitmask(int bitmask)')
cls.func(nil, 'void setContactTestBitmask(int bitmask)')
cls.func(nil, 'void setCollisionBitmask(int bitmask)')
cls.func(nil, 'int getCategoryBitmask()')
cls.func(nil, 'int getContactTestBitmask()')
cls.func(nil, 'int getCollisionBitmask()')
cls.func(nil, 'void setGroup(int group)')
cls.func(nil, 'int getGroup()')
cls.func(nil, 'cocos2d::Vec2 getPosition()')
cls.func(nil, 'float getRotation()')
cls.func(nil, 'void setPositionOffset(const cocos2d::Vec2 &position)')
cls.func(nil, 'const cocos2d::Vec2 &getPositionOffset()')
cls.func(nil, 'void setRotationOffset(float rotation)')
cls.func(nil, 'float getRotationOffset()')
cls.func(nil, 'bool isDynamic()')
cls.func(nil, 'void setDynamic(bool dynamic)')
cls.func(nil, 'void setMass(float mass)')
cls.func(nil, 'float getMass()')
cls.func(nil, 'void addMass(float mass)')
cls.func(nil, 'void setMoment(float moment)')
cls.func(nil, 'float getMoment()')
cls.func(nil, 'void addMoment(float moment)')
cls.func(nil, 'float getLinearDamping()')
cls.func(nil, 'void setLinearDamping(float damping)')
cls.func(nil, 'float getAngularDamping()')
cls.func(nil, 'void setAngularDamping(float damping)')
cls.func(nil, 'bool isResting()')
cls.func(nil, 'void setResting(bool rest)')
cls.func(nil, 'bool isRotationEnabled()')
cls.func(nil, 'void setRotationEnable(bool enable)')
cls.func(nil, 'bool isGravityEnabled()')
cls.func(nil, 'void setGravityEnable(bool enable)')
cls.func(nil, 'int getTag()')
cls.func(nil, 'void setTag(int tag)')
cls.func(nil, 'cocos2d::Vec2 world2Local(const cocos2d::Vec2 &point)')
cls.func(nil, 'cocos2d::Vec2 local2World(const cocos2d::Vec2 &point)')
cls.prop('shapes', nil, nil)
cls.prop('firstShape', nil, nil)
cls.prop('velocity', nil, nil)
cls.prop('angularVelocity', nil, nil)
cls.prop('velocityLimit', nil, nil)
cls.prop('angularVelocityLimit', nil, nil)
cls.prop('world', nil, nil)
cls.prop('joints', nil, nil)
cls.prop('node', nil, nil)
cls.prop('categoryBitmask', nil, nil)
cls.prop('contactTestBitmask', nil, nil)
cls.prop('collisionBitmask', nil, nil)
cls.prop('group', nil, nil)
cls.prop('position', nil, nil)
cls.prop('rotation', nil, nil)
cls.prop('positionOffset', nil, nil)
cls.prop('rotationOffset', nil, nil)
cls.prop('dynamic', nil, nil)
cls.prop('mass', nil, nil)
cls.prop('moment', nil, nil)
cls.prop('linearDamping', nil, nil)
cls.prop('angularDamping', nil, nil)
cls.prop('resting', nil, nil)
cls.prop('rotationEnabled', nil, nil)
cls.prop('gravityEnabled', nil, nil)
cls.prop('tag', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PhysicsContact::EventCode'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('NONE', 'cocos2d::PhysicsContact::EventCode::NONE')
cls.enum('BEGIN', 'cocos2d::PhysicsContact::EventCode::BEGIN')
cls.enum('PRESOLVE', 'cocos2d::PhysicsContact::EventCode::PRESOLVE')
cls.enum('POSTSOLVE', 'cocos2d::PhysicsContact::EventCode::POSTSOLVE')
cls.enum('SEPARATE', 'cocos2d::PhysicsContact::EventCode::SEPARATE')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PhysicsContact'
cls.SUPERCLS = 'cocos2d::EventCustom'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'cocos2d::PhysicsShape *getShapeA()')
cls.func(nil, 'cocos2d::PhysicsShape *getShapeB()')
cls.func(nil, 'void *getData()')
cls.func(nil, 'void setData(void *data)')
cls.func(nil, 'cocos2d::PhysicsContact::EventCode getEventCode()')
cls.prop('shapeA', nil, nil)
cls.prop('shapeB', nil, nil)
cls.prop('data', nil, nil)
cls.prop('eventCode', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PhysicsContactPostSolve'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'float getRestitution()')
cls.func(nil, 'float getFriction()')
cls.func(nil, 'cocos2d::Vec2 getSurfaceVelocity()')
cls.prop('restitution', nil, nil)
cls.prop('friction', nil, nil)
cls.prop('surfaceVelocity', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PhysicsContactPreSolve'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'float getRestitution()')
cls.func(nil, 'float getFriction()')
cls.func(nil, 'cocos2d::Vec2 getSurfaceVelocity()')
cls.func(nil, 'void setRestitution(float restitution)')
cls.func(nil, 'void setFriction(float friction)')
cls.func(nil, 'void setSurfaceVelocity(const cocos2d::Vec2 &velocity)')
cls.func(nil, 'void ignore()')
cls.prop('restitution', nil, nil)
cls.prop('friction', nil, nil)
cls.prop('surfaceVelocity', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PhysicsJoint'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'cocos2d::PhysicsBody *getBodyA()')
cls.func(nil, 'cocos2d::PhysicsBody *getBodyB()')
cls.func(nil, 'cocos2d::PhysicsWorld *getWorld()')
cls.func(nil, 'int getTag()')
cls.func(nil, 'void setTag(int tag)')
cls.func(nil, 'bool isEnabled()')
cls.func(nil, 'void setEnable(bool enable)')
cls.func(nil, 'bool isCollisionEnabled()')
cls.func(nil, 'void setCollisionEnable(bool enable)')
cls.func(nil, 'void removeFormWorld()')
cls.func(nil, 'void setMaxForce(float force)')
cls.func(nil, 'float getMaxForce()')
cls.prop('bodyA', nil, nil)
cls.prop('bodyB', nil, nil)
cls.prop('world', nil, nil)
cls.prop('tag', nil, nil)
cls.prop('enabled', nil, nil)
cls.prop('collisionEnabled', nil, nil)
cls.prop('maxForce', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PhysicsJointDistance'
cls.SUPERCLS = 'cocos2d::PhysicsJoint'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::PhysicsJointDistance *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b, const cocos2d::Vec2 &anchr1, const cocos2d::Vec2 &anchr2)')
cls.func(nil, 'float getDistance()')
cls.func(nil, 'void setDistance(float distance)')
cls.func(nil, 'bool createConstraints()')
cls.prop('distance', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PhysicsJointFixed'
cls.SUPERCLS = 'cocos2d::PhysicsJoint'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::PhysicsJointFixed *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b, const cocos2d::Vec2 &anchr)')
cls.func(nil, 'bool createConstraints()')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PhysicsJointGear'
cls.SUPERCLS = 'cocos2d::PhysicsJoint'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::PhysicsJointGear *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b, float phase, float ratio)')
cls.func(nil, 'float getPhase()')
cls.func(nil, 'void setPhase(float phase)')
cls.func(nil, 'float getRatio()')
cls.func(nil, 'void setRatio(float ratchet)')
cls.func(nil, 'bool createConstraints()')
cls.prop('phase', nil, nil)
cls.prop('ratio', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PhysicsJointGroove'
cls.SUPERCLS = 'cocos2d::PhysicsJoint'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::PhysicsJointGroove *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b, const cocos2d::Vec2 &grooveA, const cocos2d::Vec2 &grooveB, const cocos2d::Vec2 &anchr2)')
cls.func(nil, 'cocos2d::Vec2 getGrooveA()')
cls.func(nil, 'void setGrooveA(const cocos2d::Vec2 &grooveA)')
cls.func(nil, 'cocos2d::Vec2 getGrooveB()')
cls.func(nil, 'void setGrooveB(const cocos2d::Vec2 &grooveB)')
cls.func(nil, 'cocos2d::Vec2 getAnchr2()')
cls.func(nil, 'void setAnchr2(const cocos2d::Vec2 &anchr2)')
cls.func(nil, 'bool createConstraints()')
cls.prop('grooveA', nil, nil)
cls.prop('grooveB', nil, nil)
cls.prop('anchr2', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PhysicsJointLimit'
cls.SUPERCLS = 'cocos2d::PhysicsJoint'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::PhysicsJointLimit *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b, const cocos2d::Vec2 &anchr1, const cocos2d::Vec2 &anchr2)', 'static cocos2d::PhysicsJointLimit *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b, const cocos2d::Vec2 &anchr1, const cocos2d::Vec2 &anchr2, float min, float max)')
cls.func(nil, 'cocos2d::Vec2 getAnchr1()')
cls.func(nil, 'void setAnchr1(const cocos2d::Vec2 &anchr1)')
cls.func(nil, 'cocos2d::Vec2 getAnchr2()')
cls.func(nil, 'void setAnchr2(const cocos2d::Vec2 &anchr2)')
cls.func(nil, 'float getMin()')
cls.func(nil, 'void setMin(float min)')
cls.func(nil, 'float getMax()')
cls.func(nil, 'void setMax(float max)')
cls.func(nil, 'bool createConstraints()')
cls.prop('anchr1', nil, nil)
cls.prop('anchr2', nil, nil)
cls.prop('min', nil, nil)
cls.prop('max', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PhysicsJointMotor'
cls.SUPERCLS = 'cocos2d::PhysicsJoint'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::PhysicsJointMotor *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b, float rate)')
cls.func(nil, 'float getRate()')
cls.func(nil, 'void setRate(float rate)')
cls.func(nil, 'bool createConstraints()')
cls.prop('rate', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PhysicsJointPin'
cls.SUPERCLS = 'cocos2d::PhysicsJoint'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::PhysicsJointPin *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b, const cocos2d::Vec2 &pivot)', 'static cocos2d::PhysicsJointPin *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b, const cocos2d::Vec2 &anchr1, const cocos2d::Vec2 &anchr2)')
cls.func(nil, 'bool createConstraints()')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PhysicsJointRatchet'
cls.SUPERCLS = 'cocos2d::PhysicsJoint'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::PhysicsJointRatchet *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b, float phase, float ratchet)')
cls.func(nil, 'float getAngle()')
cls.func(nil, 'void setAngle(float angle)')
cls.func(nil, 'float getPhase()')
cls.func(nil, 'void setPhase(float phase)')
cls.func(nil, 'float getRatchet()')
cls.func(nil, 'void setRatchet(float ratchet)')
cls.func(nil, 'bool createConstraints()')
cls.prop('angle', nil, nil)
cls.prop('phase', nil, nil)
cls.prop('ratchet', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PhysicsJointRotaryLimit'
cls.SUPERCLS = 'cocos2d::PhysicsJoint'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::PhysicsJointRotaryLimit *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b, float min, float max)', 'static cocos2d::PhysicsJointRotaryLimit *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b)')
cls.func(nil, 'float getMin()')
cls.func(nil, 'void setMin(float min)')
cls.func(nil, 'float getMax()')
cls.func(nil, 'void setMax(float max)')
cls.func(nil, 'bool createConstraints()')
cls.prop('min', nil, nil)
cls.prop('max', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PhysicsJointRotarySpring'
cls.SUPERCLS = 'cocos2d::PhysicsJoint'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::PhysicsJointRotarySpring *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b, float stiffness, float damping)')
cls.func(nil, 'float getRestAngle()')
cls.func(nil, 'void setRestAngle(float restAngle)')
cls.func(nil, 'float getStiffness()')
cls.func(nil, 'void setStiffness(float stiffness)')
cls.func(nil, 'float getDamping()')
cls.func(nil, 'void setDamping(float damping)')
cls.func(nil, 'bool createConstraints()')
cls.prop('restAngle', nil, nil)
cls.prop('stiffness', nil, nil)
cls.prop('damping', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PhysicsJointSpring'
cls.SUPERCLS = 'cocos2d::PhysicsJoint'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::PhysicsJointSpring *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b, const cocos2d::Vec2 &anchr1, const cocos2d::Vec2 &anchr2, float stiffness, float damping)')
cls.func(nil, 'cocos2d::Vec2 getAnchr1()')
cls.func(nil, 'void setAnchr1(const cocos2d::Vec2 &anchr1)')
cls.func(nil, 'cocos2d::Vec2 getAnchr2()')
cls.func(nil, 'void setAnchr2(const cocos2d::Vec2 &anchr2)')
cls.func(nil, 'float getRestLength()')
cls.func(nil, 'void setRestLength(float restLength)')
cls.func(nil, 'float getStiffness()')
cls.func(nil, 'void setStiffness(float stiffness)')
cls.func(nil, 'float getDamping()')
cls.func(nil, 'void setDamping(float damping)')
cls.func(nil, 'bool createConstraints()')
cls.prop('anchr1', nil, nil)
cls.prop('anchr2', nil, nil)
cls.prop('restLength', nil, nil)
cls.prop('stiffness', nil, nil)
cls.prop('damping', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PhysicsShape::Type'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('UNKNOWN', 'cocos2d::PhysicsShape::Type::UNKNOWN')
cls.enum('CIRCLE', 'cocos2d::PhysicsShape::Type::CIRCLE')
cls.enum('BOX', 'cocos2d::PhysicsShape::Type::BOX')
cls.enum('POLYGON', 'cocos2d::PhysicsShape::Type::POLYGON')
cls.enum('EDGESEGMENT', 'cocos2d::PhysicsShape::Type::EDGESEGMENT')
cls.enum('EDGEBOX', 'cocos2d::PhysicsShape::Type::EDGEBOX')
cls.enum('EDGEPOLYGON', 'cocos2d::PhysicsShape::Type::EDGEPOLYGON')
cls.enum('EDGECHAIN', 'cocos2d::PhysicsShape::Type::EDGECHAIN')
cls.enum('POLYGEN', 'cocos2d::PhysicsShape::Type::POLYGEN')
cls.enum('EDGEPOLYGEN', 'cocos2d::PhysicsShape::Type::EDGEPOLYGEN')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PhysicsShape'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'cocos2d::PhysicsBody *getBody()')
cls.func(nil, 'cocos2d::PhysicsShape::Type getType()')
cls.func(nil, 'float getArea()')
cls.func(nil, 'float getMoment()')
cls.func(nil, 'void setMoment(float moment)')
cls.func(nil, 'void setTag(int tag)')
cls.func(nil, 'int getTag()')
cls.func(nil, 'float getMass()')
cls.func(nil, 'void setMass(float mass)')
cls.func(nil, 'float getDensity()')
cls.func(nil, 'void setDensity(float density)')
cls.func(nil, 'float getRestitution()')
cls.func(nil, 'void setRestitution(float restitution)')
cls.func(nil, 'float getFriction()')
cls.func(nil, 'void setFriction(float friction)')
cls.func(nil, 'const cocos2d::PhysicsMaterial &getMaterial()')
cls.func(nil, 'void setMaterial(const cocos2d::PhysicsMaterial &material)')
cls.func(nil, 'bool isSensor()')
cls.func(nil, 'void setSensor(bool sensor)')
cls.func(nil, 'float calculateDefaultMoment()')
cls.func(nil, 'cocos2d::Vec2 getOffset()')
cls.func(nil, 'cocos2d::Vec2 getCenter()')
cls.func(nil, 'bool containsPoint(const cocos2d::Vec2 &point)')
cls.func(nil, 'void setCategoryBitmask(int bitmask)')
cls.func(nil, 'int getCategoryBitmask()')
cls.func(nil, 'void setContactTestBitmask(int bitmask)')
cls.func(nil, 'int getContactTestBitmask()')
cls.func(nil, 'void setCollisionBitmask(int bitmask)')
cls.func(nil, 'int getCollisionBitmask()')
cls.func(nil, 'void setGroup(int group)')
cls.func(nil, 'int getGroup()')
cls.prop('body', nil, nil)
cls.prop('type', nil, nil)
cls.prop('area', nil, nil)
cls.prop('moment', nil, nil)
cls.prop('tag', nil, nil)
cls.prop('mass', nil, nil)
cls.prop('density', nil, nil)
cls.prop('restitution', nil, nil)
cls.prop('friction', nil, nil)
cls.prop('material', nil, nil)
cls.prop('sensor', nil, nil)
cls.prop('offset', nil, nil)
cls.prop('center', nil, nil)
cls.prop('categoryBitmask', nil, nil)
cls.prop('contactTestBitmask', nil, nil)
cls.prop('collisionBitmask', nil, nil)
cls.prop('group', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PhysicsShapePolygon'
cls.SUPERCLS = 'cocos2d::PhysicsShape'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'cocos2d::Vec2 getPoint(int i)')
cls.func(nil, 'int getPointsCount()')
cls.prop('pointsCount', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PhysicsShapeEdgePolygon'
cls.SUPERCLS = 'cocos2d::PhysicsShape'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'int getPointsCount()')
cls.prop('pointsCount', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PhysicsShapeBox'
cls.SUPERCLS = 'cocos2d::PhysicsShapePolygon'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::PhysicsShapeBox *create(const cocos2d::Size &size, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset, @optional float radius)')
cls.func(nil, 'cocos2d::Size getSize()')
cls.prop('size', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PhysicsShapeCircle'
cls.SUPERCLS = 'cocos2d::PhysicsShape'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::PhysicsShapeCircle *create(float radius, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset)')
cls.func(nil, 'static float calculateArea(float radius)')
cls.func(nil, 'static float calculateMoment(float mass, float radius, @optional const cocos2d::Vec2 &offset)')
cls.func(nil, 'float getRadius()')
cls.prop('radius', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PhysicsShapeEdgeBox'
cls.SUPERCLS = 'cocos2d::PhysicsShapeEdgePolygon'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::PhysicsShapeEdgeBox *create(const cocos2d::Size &size, @optional const cocos2d::PhysicsMaterial &material, @optional float border, @optional const cocos2d::Vec2 &offset)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PhysicsShapeEdgeChain'
cls.SUPERCLS = 'cocos2d::PhysicsShape'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'int getPointsCount()')
cls.prop('pointsCount', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PhysicsShapeEdgeSegment'
cls.SUPERCLS = 'cocos2d::PhysicsShape'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::PhysicsShapeEdgeSegment *create(const cocos2d::Vec2 &a, const cocos2d::Vec2 &b, @optional const cocos2d::PhysicsMaterial &material, @optional float border)')
cls.func(nil, 'cocos2d::Vec2 getPointA()')
cls.func(nil, 'cocos2d::Vec2 getPointB()')
cls.prop('pointA', nil, nil)
cls.prop('pointB', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PhysicsRayCastInfo'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.var('shape', 'cocos2d::PhysicsShape *shape')
cls.var('start', 'cocos2d::Vec2 start')
cls.var('end', 'cocos2d::Vec2 end')
cls.var('contact', 'cocos2d::Vec2 contact')
cls.var('normal', 'cocos2d::Vec2 normal')
cls.var('fraction', 'float fraction')
cls.var('data', 'void *data')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PhysicsWorld'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.const('DEBUGDRAW_NONE', 'cocos2d::PhysicsWorld::DEBUGDRAW_NONE', 'const int')
cls.const('DEBUGDRAW_SHAPE', 'cocos2d::PhysicsWorld::DEBUGDRAW_SHAPE', 'const int')
cls.const('DEBUGDRAW_JOINT', 'cocos2d::PhysicsWorld::DEBUGDRAW_JOINT', 'const int')
cls.const('DEBUGDRAW_CONTACT', 'cocos2d::PhysicsWorld::DEBUGDRAW_CONTACT', 'const int')
cls.const('DEBUGDRAW_ALL', 'cocos2d::PhysicsWorld::DEBUGDRAW_ALL', 'const int')
cls.func(nil, 'void addJoint(cocos2d::PhysicsJoint *joint)')
cls.func(nil, 'void removeJoint(cocos2d::PhysicsJoint *joint, @optional bool destroy)')
cls.func(nil, 'void removeAllJoints(@optional bool destroy)')
cls.func(nil, 'void removeBody(cocos2d::PhysicsBody *body)', 'void removeBody(int tag)')
cls.func(nil, 'void removeAllBodies()')
cls.func(nil, 'Vector<cocos2d::PhysicsShape *> getShapes(const cocos2d::Vec2 &point)')
cls.func(nil, 'cocos2d::PhysicsShape *getShape(const cocos2d::Vec2 &point)')
cls.func(nil, 'const Vector<cocos2d::PhysicsBody *> &getAllBodies()')
cls.func(nil, 'cocos2d::PhysicsBody *getBody(int tag)')
cls.func(nil, 'cocos2d::Scene &getScene()')
cls.func(nil, 'cocos2d::Vec2 getGravity()')
cls.func(nil, 'void setGravity(const cocos2d::Vec2 &gravity)')
cls.func(nil, 'void setSpeed(float speed)')
cls.func(nil, 'float getSpeed()')
cls.func(nil, 'void setUpdateRate(int rate)')
cls.func(nil, 'int getUpdateRate()')
cls.func(nil, 'void setSubsteps(int steps)')
cls.func(nil, 'int getSubsteps()')
cls.func(nil, 'void setFixedUpdateRate(int updatesPerSecond)')
cls.func(nil, 'int getFixedUpdateRate()')
cls.func(nil, 'void setDebugDrawMask(int mask)')
cls.func(nil, 'int getDebugDrawMask()')
cls.func(nil, 'void setAutoStep(bool autoStep)')
cls.func(nil, 'bool isAutoStep()')
cls.func(nil, 'void step(float delta)')
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
cls.prop('allBodies', nil, nil)
cls.prop('scene', nil, nil)
cls.prop('gravity', nil, nil)
cls.prop('speed', nil, nil)
cls.prop('updateRate', nil, nil)
cls.prop('substeps', nil, nil)
cls.prop('fixedUpdateRate', nil, nil)
cls.prop('debugDrawMask', nil, nil)
cls.prop('autoStep', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

return M
