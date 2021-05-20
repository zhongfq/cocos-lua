-- AUTO BUILD, DON'T MODIFY!

dofile "autobuild/cocos2d-physics-types.lua"

NAME = "cocos2d_physics"
PATH = "../../frameworks/libxgame/src/lua-bindings"
HEADERS = [[
    #include "lua-bindings/lua_conv.h"
    #include "lua-bindings/lua_conv_manual.h"
    #include "lua-bindings/LuaCocosAdapter.h"
    #include "cclua/xlua.h"
    #include "cocos2d.h"
]]
CHUNK = nil

typeconv 'cocos2d::PhysicsMaterial'
    .var('density', 'float density')
    .var('restitution', 'float restitution')
    .var('friction', 'float friction')


typecls 'cocos2d::PhysicsRayCastCallbackFunc'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)

typecls 'cocos2d::PhysicsQueryRectCallbackFunc'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)

typecls 'cocos2d::PhysicsQueryPointCallbackFunc'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)

typecls 'cocos2d::EventListenerPhysicsContact'
    .supercls('cocos2d::EventListenerCustom')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::EventListenerPhysicsContact *create()')
    .var('onContactBegin', '@nullable @local std::function<bool (cocos2d::PhysicsContact &)> onContactBegin')
    .var('onContactPreSolve', '@nullable @local std::function<bool (cocos2d::PhysicsContact &, cocos2d::PhysicsContactPreSolve &)> onContactPreSolve')
    .var('onContactPostSolve', '@nullable @local std::function<void (cocos2d::PhysicsContact &, const cocos2d::PhysicsContactPostSolve &)> onContactPostSolve')
    .var('onContactSeparate', '@nullable @local std::function<void (cocos2d::PhysicsContact &)> onContactSeparate')

typecls 'cocos2d::EventListenerPhysicsContactWithGroup'
    .supercls('cocos2d::EventListenerPhysicsContact')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::EventListenerPhysicsContactWithGroup *create(int group)')
    .func(nil, 'bool hitTest(cocos2d::PhysicsShape *shapeA, cocos2d::PhysicsShape *shapeB)')

typecls 'cocos2d::EventListenerPhysicsContactWithBodies'
    .supercls('cocos2d::EventListenerPhysicsContact')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::EventListenerPhysicsContactWithBodies *create(cocos2d::PhysicsBody *bodyA, cocos2d::PhysicsBody *bodyB)')
    .func(nil, 'bool hitTest(cocos2d::PhysicsShape *shapeA, cocos2d::PhysicsShape *shapeB)')

typecls 'cocos2d::EventListenerPhysicsContactWithShapes'
    .supercls('cocos2d::EventListenerPhysicsContact')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::EventListenerPhysicsContactWithShapes *create(cocos2d::PhysicsShape *shapeA, cocos2d::PhysicsShape *shapeB)')
    .func(nil, 'bool hitTest(cocos2d::PhysicsShape *shapeA, cocos2d::PhysicsShape *shapeB)')

typecls 'cocos2d::PhysicsBody'
    .supercls('cocos2d::Component')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .const('COMPONENT_NAME', 'cocos2d::PhysicsBody::COMPONENT_NAME', 'const std::string')
    .func(nil, 'static cocos2d::PhysicsBody *create()', 'static cocos2d::PhysicsBody *create(float mass)', 'static cocos2d::PhysicsBody *create(float mass, float moment)')
    .func(nil, 'static cocos2d::PhysicsBody *createCircle(float radius, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset)')
    .func(nil, 'static cocos2d::PhysicsBody *createBox(const cocos2d::Size &size, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset)')
    .func(nil, 'static cocos2d::PhysicsBody *createEdgeSegment(const cocos2d::Vec2 &a, const cocos2d::Vec2 &b, @optional const cocos2d::PhysicsMaterial &material, @optional float border)')
    .func(nil, 'static cocos2d::PhysicsBody *createEdgeBox(const cocos2d::Size &size, @optional const cocos2d::PhysicsMaterial &material, @optional float border, @optional const cocos2d::Vec2 &offset)')
    .func(nil, 'cocos2d::PhysicsShape *addShape(cocos2d::PhysicsShape *shape, @optional bool addMassAndMoment)')
    .func(nil, 'void removeShape(cocos2d::PhysicsShape *shape, @optional bool reduceMassAndMoment)', 'void removeShape(int tag, @optional bool reduceMassAndMoment)')
    .func(nil, 'void removeAllShapes(@optional bool reduceMassAndMoment)')
    .func(nil, 'const Vector<cocos2d::PhysicsShape *> &getShapes()')
    .func(nil, 'cocos2d::PhysicsShape *getFirstShape()')
    .func(nil, 'cocos2d::PhysicsShape *getShape(int tag)')
    .func(nil, 'void applyForce(const cocos2d::Vec2 &force, @optional const cocos2d::Vec2 &offset)')
    .func(nil, 'void resetForces()')
    .func(nil, 'void applyImpulse(const cocos2d::Vec2 &impulse, @optional const cocos2d::Vec2 &offset)')
    .func(nil, 'void applyTorque(float torque)')
    .func(nil, 'void setVelocity(const cocos2d::Vec2 &velocity)')
    .func(nil, 'cocos2d::Vec2 getVelocity()')
    .func(nil, 'void setAngularVelocity(float velocity)')
    .func(nil, 'cocos2d::Vec2 getVelocityAtLocalPoint(const cocos2d::Vec2 &point)')
    .func(nil, 'cocos2d::Vec2 getVelocityAtWorldPoint(const cocos2d::Vec2 &point)')
    .func(nil, 'float getAngularVelocity()')
    .func(nil, 'void setVelocityLimit(float limit)')
    .func(nil, 'float getVelocityLimit()')
    .func(nil, 'void setAngularVelocityLimit(float limit)')
    .func(nil, 'float getAngularVelocityLimit()')
    .func(nil, 'void removeFromWorld()')
    .func(nil, 'cocos2d::PhysicsWorld *getWorld()')
    .func(nil, 'const std::vector<PhysicsJoint *> &getJoints()')
    .func(nil, 'cocos2d::Node *getNode()')
    .func(nil, 'void setCategoryBitmask(int bitmask)')
    .func(nil, 'void setContactTestBitmask(int bitmask)')
    .func(nil, 'void setCollisionBitmask(int bitmask)')
    .func(nil, 'int getCategoryBitmask()')
    .func(nil, 'int getContactTestBitmask()')
    .func(nil, 'int getCollisionBitmask()')
    .func(nil, 'void setGroup(int group)')
    .func(nil, 'int getGroup()')
    .func(nil, 'cocos2d::Vec2 getPosition()')
    .func(nil, 'float getRotation()')
    .func(nil, 'void setPositionOffset(const cocos2d::Vec2 &position)')
    .func(nil, 'const cocos2d::Vec2 &getPositionOffset()')
    .func(nil, 'void setRotationOffset(float rotation)')
    .func(nil, 'float getRotationOffset()')
    .func(nil, 'bool isDynamic()')
    .func(nil, 'void setDynamic(bool dynamic)')
    .func(nil, 'void setMass(float mass)')
    .func(nil, 'float getMass()')
    .func(nil, 'void addMass(float mass)')
    .func(nil, 'void setMoment(float moment)')
    .func(nil, 'float getMoment()')
    .func(nil, 'void addMoment(float moment)')
    .func(nil, 'float getLinearDamping()')
    .func(nil, 'void setLinearDamping(float damping)')
    .func(nil, 'float getAngularDamping()')
    .func(nil, 'void setAngularDamping(float damping)')
    .func(nil, 'bool isResting()')
    .func(nil, 'void setResting(bool rest)')
    .func(nil, 'bool isRotationEnabled()')
    .func(nil, 'void setRotationEnable(bool enable)')
    .func(nil, 'bool isGravityEnabled()')
    .func(nil, 'void setGravityEnable(bool enable)')
    .func(nil, 'int getTag()')
    .func(nil, 'void setTag(int tag)')
    .func(nil, 'cocos2d::Vec2 world2Local(const cocos2d::Vec2 &point)')
    .func(nil, 'cocos2d::Vec2 local2World(const cocos2d::Vec2 &point)')
    .prop('shapes', nil, nil)
    .prop('firstShape', nil, nil)
    .prop('velocity', nil, nil)
    .prop('angularVelocity', nil, nil)
    .prop('velocityLimit', nil, nil)
    .prop('angularVelocityLimit', nil, nil)
    .prop('world', nil, nil)
    .prop('joints', nil, nil)
    .prop('node', nil, nil)
    .prop('categoryBitmask', nil, nil)
    .prop('contactTestBitmask', nil, nil)
    .prop('collisionBitmask', nil, nil)
    .prop('group', nil, nil)
    .prop('position', nil, nil)
    .prop('rotation', nil, nil)
    .prop('positionOffset', nil, nil)
    .prop('rotationOffset', nil, nil)
    .prop('dynamic', nil, nil)
    .prop('mass', nil, nil)
    .prop('moment', nil, nil)
    .prop('linearDamping', nil, nil)
    .prop('angularDamping', nil, nil)
    .prop('resting', nil, nil)
    .prop('rotationEnabled', nil, nil)
    .prop('gravityEnabled', nil, nil)
    .prop('tag', nil, nil)

typecls 'cocos2d::PhysicsContact::EventCode'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('NONE', 'cocos2d::PhysicsContact::EventCode::NONE')
    .enum('BEGIN', 'cocos2d::PhysicsContact::EventCode::BEGIN')
    .enum('PRESOLVE', 'cocos2d::PhysicsContact::EventCode::PRESOLVE')
    .enum('POSTSOLVE', 'cocos2d::PhysicsContact::EventCode::POSTSOLVE')
    .enum('SEPARATE', 'cocos2d::PhysicsContact::EventCode::SEPARATE')

typecls 'cocos2d::PhysicsContact'
    .supercls('cocos2d::EventCustom')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'cocos2d::PhysicsShape *getShapeA()')
    .func(nil, 'cocos2d::PhysicsShape *getShapeB()')
    .func(nil, 'void *getData()')
    .func(nil, 'void setData(void *data)')
    .func(nil, 'cocos2d::PhysicsContact::EventCode getEventCode()')
    .prop('shapeA', nil, nil)
    .prop('shapeB', nil, nil)
    .prop('data', nil, nil)
    .prop('eventCode', nil, nil)

typecls 'cocos2d::PhysicsContactPostSolve'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'float getRestitution()')
    .func(nil, 'float getFriction()')
    .func(nil, 'cocos2d::Vec2 getSurfaceVelocity()')
    .prop('restitution', nil, nil)
    .prop('friction', nil, nil)
    .prop('surfaceVelocity', nil, nil)

typecls 'cocos2d::PhysicsContactPreSolve'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'float getRestitution()')
    .func(nil, 'float getFriction()')
    .func(nil, 'cocos2d::Vec2 getSurfaceVelocity()')
    .func(nil, 'void setRestitution(float restitution)')
    .func(nil, 'void setFriction(float friction)')
    .func(nil, 'void setSurfaceVelocity(const cocos2d::Vec2 &velocity)')
    .func(nil, 'void ignore()')
    .prop('restitution', nil, nil)
    .prop('friction', nil, nil)
    .prop('surfaceVelocity', nil, nil)

typecls 'cocos2d::PhysicsJoint'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'cocos2d::PhysicsBody *getBodyA()')
    .func(nil, 'cocos2d::PhysicsBody *getBodyB()')
    .func(nil, 'cocos2d::PhysicsWorld *getWorld()')
    .func(nil, 'int getTag()')
    .func(nil, 'void setTag(int tag)')
    .func(nil, 'bool isEnabled()')
    .func(nil, 'void setEnable(bool enable)')
    .func(nil, 'bool isCollisionEnabled()')
    .func(nil, 'void setCollisionEnable(bool enable)')
    .func(nil, 'void removeFormWorld()')
    .func(nil, 'void setMaxForce(float force)')
    .func(nil, 'float getMaxForce()')
    .prop('bodyA', nil, nil)
    .prop('bodyB', nil, nil)
    .prop('world', nil, nil)
    .prop('tag', nil, nil)
    .prop('enabled', nil, nil)
    .prop('collisionEnabled', nil, nil)
    .prop('maxForce', nil, nil)

typecls 'cocos2d::PhysicsJointDistance'
    .supercls('cocos2d::PhysicsJoint')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::PhysicsJointDistance *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b, const cocos2d::Vec2 &anchr1, const cocos2d::Vec2 &anchr2)')
    .func(nil, 'float getDistance()')
    .func(nil, 'void setDistance(float distance)')
    .func(nil, 'bool createConstraints()')
    .prop('distance', nil, nil)

typecls 'cocos2d::PhysicsJointFixed'
    .supercls('cocos2d::PhysicsJoint')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::PhysicsJointFixed *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b, const cocos2d::Vec2 &anchr)')
    .func(nil, 'bool createConstraints()')

typecls 'cocos2d::PhysicsJointGear'
    .supercls('cocos2d::PhysicsJoint')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::PhysicsJointGear *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b, float phase, float ratio)')
    .func(nil, 'float getPhase()')
    .func(nil, 'void setPhase(float phase)')
    .func(nil, 'float getRatio()')
    .func(nil, 'void setRatio(float ratchet)')
    .func(nil, 'bool createConstraints()')
    .prop('phase', nil, nil)
    .prop('ratio', nil, nil)

typecls 'cocos2d::PhysicsJointGroove'
    .supercls('cocos2d::PhysicsJoint')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::PhysicsJointGroove *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b, const cocos2d::Vec2 &grooveA, const cocos2d::Vec2 &grooveB, const cocos2d::Vec2 &anchr2)')
    .func(nil, 'cocos2d::Vec2 getGrooveA()')
    .func(nil, 'void setGrooveA(const cocos2d::Vec2 &grooveA)')
    .func(nil, 'cocos2d::Vec2 getGrooveB()')
    .func(nil, 'void setGrooveB(const cocos2d::Vec2 &grooveB)')
    .func(nil, 'cocos2d::Vec2 getAnchr2()')
    .func(nil, 'void setAnchr2(const cocos2d::Vec2 &anchr2)')
    .func(nil, 'bool createConstraints()')
    .prop('grooveA', nil, nil)
    .prop('grooveB', nil, nil)
    .prop('anchr2', nil, nil)

typecls 'cocos2d::PhysicsJointLimit'
    .supercls('cocos2d::PhysicsJoint')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::PhysicsJointLimit *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b, const cocos2d::Vec2 &anchr1, const cocos2d::Vec2 &anchr2)', 'static cocos2d::PhysicsJointLimit *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b, const cocos2d::Vec2 &anchr1, const cocos2d::Vec2 &anchr2, float min, float max)')
    .func(nil, 'cocos2d::Vec2 getAnchr1()')
    .func(nil, 'void setAnchr1(const cocos2d::Vec2 &anchr1)')
    .func(nil, 'cocos2d::Vec2 getAnchr2()')
    .func(nil, 'void setAnchr2(const cocos2d::Vec2 &anchr2)')
    .func(nil, 'float getMin()')
    .func(nil, 'void setMin(float min)')
    .func(nil, 'float getMax()')
    .func(nil, 'void setMax(float max)')
    .func(nil, 'bool createConstraints()')
    .prop('anchr1', nil, nil)
    .prop('anchr2', nil, nil)
    .prop('min', nil, nil)
    .prop('max', nil, nil)

typecls 'cocos2d::PhysicsJointMotor'
    .supercls('cocos2d::PhysicsJoint')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::PhysicsJointMotor *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b, float rate)')
    .func(nil, 'float getRate()')
    .func(nil, 'void setRate(float rate)')
    .func(nil, 'bool createConstraints()')
    .prop('rate', nil, nil)

typecls 'cocos2d::PhysicsJointPin'
    .supercls('cocos2d::PhysicsJoint')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::PhysicsJointPin *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b, const cocos2d::Vec2 &pivot)', 'static cocos2d::PhysicsJointPin *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b, const cocos2d::Vec2 &anchr1, const cocos2d::Vec2 &anchr2)')
    .func(nil, 'bool createConstraints()')

typecls 'cocos2d::PhysicsJointRatchet'
    .supercls('cocos2d::PhysicsJoint')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::PhysicsJointRatchet *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b, float phase, float ratchet)')
    .func(nil, 'float getAngle()')
    .func(nil, 'void setAngle(float angle)')
    .func(nil, 'float getPhase()')
    .func(nil, 'void setPhase(float phase)')
    .func(nil, 'float getRatchet()')
    .func(nil, 'void setRatchet(float ratchet)')
    .func(nil, 'bool createConstraints()')
    .prop('angle', nil, nil)
    .prop('phase', nil, nil)
    .prop('ratchet', nil, nil)

typecls 'cocos2d::PhysicsJointRotaryLimit'
    .supercls('cocos2d::PhysicsJoint')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::PhysicsJointRotaryLimit *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b, float min, float max)', 'static cocos2d::PhysicsJointRotaryLimit *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b)')
    .func(nil, 'float getMin()')
    .func(nil, 'void setMin(float min)')
    .func(nil, 'float getMax()')
    .func(nil, 'void setMax(float max)')
    .func(nil, 'bool createConstraints()')
    .prop('min', nil, nil)
    .prop('max', nil, nil)

typecls 'cocos2d::PhysicsJointRotarySpring'
    .supercls('cocos2d::PhysicsJoint')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::PhysicsJointRotarySpring *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b, float stiffness, float damping)')
    .func(nil, 'float getRestAngle()')
    .func(nil, 'void setRestAngle(float restAngle)')
    .func(nil, 'float getStiffness()')
    .func(nil, 'void setStiffness(float stiffness)')
    .func(nil, 'float getDamping()')
    .func(nil, 'void setDamping(float damping)')
    .func(nil, 'bool createConstraints()')
    .prop('restAngle', nil, nil)
    .prop('stiffness', nil, nil)
    .prop('damping', nil, nil)

typecls 'cocos2d::PhysicsJointSpring'
    .supercls('cocos2d::PhysicsJoint')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::PhysicsJointSpring *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b, const cocos2d::Vec2 &anchr1, const cocos2d::Vec2 &anchr2, float stiffness, float damping)')
    .func(nil, 'cocos2d::Vec2 getAnchr1()')
    .func(nil, 'void setAnchr1(const cocos2d::Vec2 &anchr1)')
    .func(nil, 'cocos2d::Vec2 getAnchr2()')
    .func(nil, 'void setAnchr2(const cocos2d::Vec2 &anchr2)')
    .func(nil, 'float getRestLength()')
    .func(nil, 'void setRestLength(float restLength)')
    .func(nil, 'float getStiffness()')
    .func(nil, 'void setStiffness(float stiffness)')
    .func(nil, 'float getDamping()')
    .func(nil, 'void setDamping(float damping)')
    .func(nil, 'bool createConstraints()')
    .prop('anchr1', nil, nil)
    .prop('anchr2', nil, nil)
    .prop('restLength', nil, nil)
    .prop('stiffness', nil, nil)
    .prop('damping', nil, nil)

typecls 'cocos2d::PhysicsShape::Type'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('UNKNOWN', 'cocos2d::PhysicsShape::Type::UNKNOWN')
    .enum('CIRCLE', 'cocos2d::PhysicsShape::Type::CIRCLE')
    .enum('BOX', 'cocos2d::PhysicsShape::Type::BOX')
    .enum('POLYGON', 'cocos2d::PhysicsShape::Type::POLYGON')
    .enum('EDGESEGMENT', 'cocos2d::PhysicsShape::Type::EDGESEGMENT')
    .enum('EDGEBOX', 'cocos2d::PhysicsShape::Type::EDGEBOX')
    .enum('EDGEPOLYGON', 'cocos2d::PhysicsShape::Type::EDGEPOLYGON')
    .enum('EDGECHAIN', 'cocos2d::PhysicsShape::Type::EDGECHAIN')
    .enum('POLYGEN', 'cocos2d::PhysicsShape::Type::POLYGEN')
    .enum('EDGEPOLYGEN', 'cocos2d::PhysicsShape::Type::EDGEPOLYGEN')

typecls 'cocos2d::PhysicsShape'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'cocos2d::PhysicsBody *getBody()')
    .func(nil, 'cocos2d::PhysicsShape::Type getType()')
    .func(nil, 'float getArea()')
    .func(nil, 'float getMoment()')
    .func(nil, 'void setMoment(float moment)')
    .func(nil, 'void setTag(int tag)')
    .func(nil, 'int getTag()')
    .func(nil, 'float getMass()')
    .func(nil, 'void setMass(float mass)')
    .func(nil, 'float getDensity()')
    .func(nil, 'void setDensity(float density)')
    .func(nil, 'float getRestitution()')
    .func(nil, 'void setRestitution(float restitution)')
    .func(nil, 'float getFriction()')
    .func(nil, 'void setFriction(float friction)')
    .func(nil, 'const cocos2d::PhysicsMaterial &getMaterial()')
    .func(nil, 'void setMaterial(const cocos2d::PhysicsMaterial &material)')
    .func(nil, 'bool isSensor()')
    .func(nil, 'void setSensor(bool sensor)')
    .func(nil, 'float calculateDefaultMoment()')
    .func(nil, 'cocos2d::Vec2 getOffset()')
    .func(nil, 'cocos2d::Vec2 getCenter()')
    .func(nil, 'bool containsPoint(const cocos2d::Vec2 &point)')
    .func(nil, 'void setCategoryBitmask(int bitmask)')
    .func(nil, 'int getCategoryBitmask()')
    .func(nil, 'void setContactTestBitmask(int bitmask)')
    .func(nil, 'int getContactTestBitmask()')
    .func(nil, 'void setCollisionBitmask(int bitmask)')
    .func(nil, 'int getCollisionBitmask()')
    .func(nil, 'void setGroup(int group)')
    .func(nil, 'int getGroup()')
    .prop('body', nil, nil)
    .prop('type', nil, nil)
    .prop('area', nil, nil)
    .prop('moment', nil, nil)
    .prop('tag', nil, nil)
    .prop('mass', nil, nil)
    .prop('density', nil, nil)
    .prop('restitution', nil, nil)
    .prop('friction', nil, nil)
    .prop('material', nil, nil)
    .prop('sensor', nil, nil)
    .prop('offset', nil, nil)
    .prop('center', nil, nil)
    .prop('categoryBitmask', nil, nil)
    .prop('contactTestBitmask', nil, nil)
    .prop('collisionBitmask', nil, nil)
    .prop('group', nil, nil)

typecls 'cocos2d::PhysicsShapePolygon'
    .supercls('cocos2d::PhysicsShape')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'cocos2d::Vec2 getPoint(int i)')
    .func(nil, 'int getPointsCount()')
    .prop('pointsCount', nil, nil)

typecls 'cocos2d::PhysicsShapeEdgePolygon'
    .supercls('cocos2d::PhysicsShape')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'int getPointsCount()')
    .prop('pointsCount', nil, nil)

typecls 'cocos2d::PhysicsShapeBox'
    .supercls('cocos2d::PhysicsShapePolygon')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::PhysicsShapeBox *create(const cocos2d::Size &size, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset, @optional float radius)')
    .func(nil, 'cocos2d::Size getSize()')
    .prop('size', nil, nil)

typecls 'cocos2d::PhysicsShapeCircle'
    .supercls('cocos2d::PhysicsShape')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::PhysicsShapeCircle *create(float radius, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset)')
    .func(nil, 'static float calculateArea(float radius)')
    .func(nil, 'static float calculateMoment(float mass, float radius, @optional const cocos2d::Vec2 &offset)')
    .func(nil, 'float getRadius()')
    .prop('radius', nil, nil)

typecls 'cocos2d::PhysicsShapeEdgeBox'
    .supercls('cocos2d::PhysicsShapeEdgePolygon')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::PhysicsShapeEdgeBox *create(const cocos2d::Size &size, @optional const cocos2d::PhysicsMaterial &material, @optional float border, @optional const cocos2d::Vec2 &offset)')

typecls 'cocos2d::PhysicsShapeEdgeChain'
    .supercls('cocos2d::PhysicsShape')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'int getPointsCount()')
    .prop('pointsCount', nil, nil)

typecls 'cocos2d::PhysicsShapeEdgeSegment'
    .supercls('cocos2d::PhysicsShape')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::PhysicsShapeEdgeSegment *create(const cocos2d::Vec2 &a, const cocos2d::Vec2 &b, @optional const cocos2d::PhysicsMaterial &material, @optional float border)')
    .func(nil, 'cocos2d::Vec2 getPointA()')
    .func(nil, 'cocos2d::Vec2 getPointB()')
    .prop('pointA', nil, nil)
    .prop('pointB', nil, nil)

typecls 'cocos2d::PhysicsRayCastInfo'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .var('shape', 'cocos2d::PhysicsShape *shape')
    .var('start', 'cocos2d::Vec2 start')
    .var('end', 'cocos2d::Vec2 end')
    .var('contact', 'cocos2d::Vec2 contact')
    .var('normal', 'cocos2d::Vec2 normal')
    .var('fraction', 'float fraction')
    .var('data', 'void *data')

typecls 'cocos2d::PhysicsWorld'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .const('DEBUGDRAW_NONE', 'cocos2d::PhysicsWorld::DEBUGDRAW_NONE', 'const int')
    .const('DEBUGDRAW_SHAPE', 'cocos2d::PhysicsWorld::DEBUGDRAW_SHAPE', 'const int')
    .const('DEBUGDRAW_JOINT', 'cocos2d::PhysicsWorld::DEBUGDRAW_JOINT', 'const int')
    .const('DEBUGDRAW_CONTACT', 'cocos2d::PhysicsWorld::DEBUGDRAW_CONTACT', 'const int')
    .const('DEBUGDRAW_ALL', 'cocos2d::PhysicsWorld::DEBUGDRAW_ALL', 'const int')
    .func(nil, 'void addJoint(cocos2d::PhysicsJoint *joint)')
    .func(nil, 'void removeJoint(cocos2d::PhysicsJoint *joint, @optional bool destroy)')
    .func(nil, 'void removeAllJoints(@optional bool destroy)')
    .func(nil, 'void removeBody(cocos2d::PhysicsBody *body)', 'void removeBody(int tag)')
    .func(nil, 'void removeAllBodies()')
    .func(nil, 'Vector<cocos2d::PhysicsShape *> getShapes(const cocos2d::Vec2 &point)')
    .func(nil, 'cocos2d::PhysicsShape *getShape(const cocos2d::Vec2 &point)')
    .func(nil, 'const Vector<cocos2d::PhysicsBody *> &getAllBodies()')
    .func(nil, 'cocos2d::PhysicsBody *getBody(int tag)')
    .func(nil, 'cocos2d::Scene &getScene()')
    .func(nil, 'cocos2d::Vec2 getGravity()')
    .func(nil, 'void setGravity(const cocos2d::Vec2 &gravity)')
    .func(nil, 'void setSpeed(float speed)')
    .func(nil, 'float getSpeed()')
    .func(nil, 'void setUpdateRate(int rate)')
    .func(nil, 'int getUpdateRate()')
    .func(nil, 'void setSubsteps(int steps)')
    .func(nil, 'int getSubsteps()')
    .func(nil, 'void setFixedUpdateRate(int updatesPerSecond)')
    .func(nil, 'int getFixedUpdateRate()')
    .func(nil, 'void setDebugDrawMask(int mask)')
    .func(nil, 'int getDebugDrawMask()')
    .func(nil, 'void setAutoStep(bool autoStep)')
    .func(nil, 'bool isAutoStep()')
    .func(nil, 'void step(float delta)')
    .callback {
        FUNCS =  {
            'void setPreUpdateCallback(@nullable @local const std::function<void ()> &callback)'
        },
        TAG_MAKER = 'PreUpdateCallback',
        TAG_MODE = 'OLUA_TAG_REPLACE',
        TAG_STORE = nil,
        TAG_SCOPE = 'object',
    }
    .callback {
        FUNCS =  {
            'void setPostUpdateCallback(@nullable @local const std::function<void ()> &callback)'
        },
        TAG_MAKER = 'PostUpdateCallback',
        TAG_MODE = 'OLUA_TAG_REPLACE',
        TAG_STORE = nil,
        TAG_SCOPE = 'object',
    }
    .callback {
        FUNCS =  {
            'void rayCast(@local cocos2d::PhysicsRayCastCallbackFunc func, const cocos2d::Vec2 &start, const cocos2d::Vec2 &end, void *data)'
        },
        TAG_MAKER = 'rayCast',
        TAG_MODE = 'OLUA_TAG_REPLACE',
        TAG_STORE = nil,
        TAG_SCOPE = 'object',
    }
    .callback {
        FUNCS =  {
            'void queryRect(@local cocos2d::PhysicsQueryRectCallbackFunc func, const cocos2d::Rect &rect, void *data)'
        },
        TAG_MAKER = 'queryRect',
        TAG_MODE = 'OLUA_TAG_REPLACE',
        TAG_STORE = nil,
        TAG_SCOPE = 'object',
    }
    .callback {
        FUNCS =  {
            'void queryPoint(@local cocos2d::PhysicsQueryPointCallbackFunc func, const cocos2d::Vec2 &point, void *data)'
        },
        TAG_MAKER = 'queryPoint',
        TAG_MODE = 'OLUA_TAG_REPLACE',
        TAG_STORE = nil,
        TAG_SCOPE = 'object',
    }
    .prop('allBodies', nil, nil)
    .prop('scene', nil, nil)
    .prop('gravity', nil, nil)
    .prop('speed', nil, nil)
    .prop('updateRate', nil, nil)
    .prop('substeps', nil, nil)
    .prop('fixedUpdateRate', nil, nil)
    .prop('debugDrawMask', nil, nil)
    .prop('autoStep', nil, nil)
