module 'box2d'

path '../../frameworks/libxgame/src/lua-bindings'

headers [[
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "cclua/xlua.h"
#include "cocos2d.h"
#include "box2d/box2d.h"
#include "box2d/Box2DAdapter.h"
]]

local namemap = {
    ['b2Draw'] = 'box2d.interface.Draw',
    ['b2DestructionListener'] = 'box2d.interface.DestructionListener',
    ['b2ContactFilter'] = 'box2d.interface.ContactFilter',
    ['b2ContactListener'] = 'box2d.interface.ContactListener',
    ['b2QueryCallback'] = 'box2d.interface.QueryCallback',
    ['b2RayCastCallback'] = 'box2d.interface.RayCastCallback',
}

luacls(function (cppname)
    cppname = namemap[cppname] or cppname
    cppname = string.gsub(cppname, '^b2(.+)', 'box2d.%1')
    cppname = string.gsub(cppname, '::', '.')
    return cppname
end)

include 'conf/exclude-type.lua'

exclude 'b2BlockAllocator *'
exclude 'b2ContactID'
exclude 'b2RayCastOutput *'
exclude 'b2Transform'

chunk [[
int olua_push_b2MassData(lua_State *L, const b2MassData *value)
{
    lua_createtable(L, 0, 2);
    olua_push_number(L, value->mass);
    olua_setfield(L, -2, "mass");
    olua_push_b2Vec2(L, &value->center);
    olua_setfield(L, -2, "center");
    olua_push_number(L, value->I);
    olua_setfield(L, -2, "I");
    return 1;
}
]]

typedef 'int8;int16;int32'
    .decltype 'lua_Integer'

typedef 'uint8;uint16;uint32'
    .decltype 'lua_Unsigned'

typedef 'b2MassData'

typeconv 'b2Vec2'
typeconv 'b2Vec3'
typeconv 'b2Color'
typeconv 'b2FixtureUserData'
typeconv 'b2Filter'
typeconv 'b2ManifoldPoint'

-- need provide implemention
typeconf 'b2Draw'
typeconf 'b2DestructionListener'
typeconf 'b2ContactFilter'
typeconf 'b2ContactListener'
typeconf 'b2QueryCallback'
typeconf 'b2RayCastCallback'
typeconf 'box2d::DestructionListener'
typeconf 'box2d::ContactFilter'
typeconf 'box2d::ContactListener'
typeconf 'box2d::QueryCallback'
typeconf 'box2d::RayCastCallback'

typeconf 'b2MassData'

typeconf 'b2Shape::Type'
    .luaname(function (value) return value:gsub('^e_', '') end)
typeconf 'b2Shape'
typeconf 'b2PolygonShape'
typeconf 'b2EdgeShape'
typeconf 'b2CircleShape'
typeconf 'b2ChainShape'

typeconf 'b2BodyDef'
typeconf 'b2BodyType'
    .luaname(function (value) return value:gsub('^b2_', '') end)
typeconf 'b2Body'
typeconf 'b2BodyUserData'
typeconf 'b2FixtureDef'
typeconf 'b2Fixture'
typeconf 'b2JointDef'
typeconf 'b2JointType'
    .luaname(function (value) return value:gsub('^e_', '') end)
typeconf 'b2Joint'
typeconf 'b2DistanceJointDef'
typeconf 'b2DistanceJoint'
typeconf 'b2FrictionJointDef'
typeconf 'b2FrictionJoint'
typeconf 'b2GearJointDef'
typeconf 'b2GearJoint'
typeconf 'b2MotorJointDef'
typeconf 'b2MotorJoint'
typeconf 'b2MouseJointDef'
typeconf 'b2MouseJoint'
typeconf 'b2PrismaticJointDef'
typeconf 'b2PrismaticJoint'
typeconf 'b2PulleyJointDef'
typeconf 'b2PulleyJoint'
typeconf 'b2RevoluteJointDef'
typeconf 'b2RevoluteJoint'
typeconf 'b2WeldJointDef'
typeconf 'b2WeldJoint'
typeconf 'b2WheelJointDef'
typeconf 'b2WheelJoint'
typeconf 'b2JointEdge'
typeconf 'b2JointUserData'
typeconf 'b2ContactEdge'

typeconf 'b2ContactManager'
typeconf 'b2Profile'
typeconf 'b2BroadPhase'
typeconf 'b2AABB'
typeconf 'b2Contact'
typeconf 'b2ContactImpulse'
typeconf 'b2Manifold'
typeconf 'b2Manifold::Type'
    .luaname(function (value) return value:gsub('^e_', '') end)
typeconf 'b2World'
    .func 'SetDestructionListener' .arg1 '@addref(destructionListener ^)'
    .func 'SetContactFilter' .arg1 '@addref(contactFilter ^)'
    .func 'SetContactListener' .arg1 '@addref(contactListener ^)'
    .func 'SetDebugDraw' .arg1 '@addref(debugDraw ^)'
typeconf 'b2WorldManifold'