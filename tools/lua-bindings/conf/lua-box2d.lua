module 'box2d'

path '../../frameworks/libxgame/src/lua-bindings'

headers [[
#include "lua-bindings/lua_cocos2d_types.h"
#include "lua-bindings/lua_conv_manual.h"
#include "box2d/box2d.h"
#include "box2d/box2d-2dx.h"
]]

local namemap = {
    ['b2Draw'] = 'b2.interface.Draw',
    ['b2DestructionListener'] = 'b2.interface.DestructionListener',
    ['b2ContactFilter'] = 'b2.interface.ContactFilter',
    ['b2ContactListener'] = 'b2.interface.ContactListener',
    ['b2QueryCallback'] = 'b2.interface.QueryCallback',
    ['b2RayCastCallback'] = 'b2.interface.RayCastCallback',
}

luaopen [[cclua::runtime::registerFeature("box2d", true);]]

luacls(function (cppname)
    if namemap[cppname] then
        return namemap[cppname]
    end
    cppname = string.gsub(cppname, '^b2(.+)', 'b2.%1')
    cppname = string.gsub(cppname, 'box2d::', 'b2.')
    cppname = string.gsub(cppname, '::', '.')
    return cppname
end)

excludetype 'b2BlockAllocator'

local _typeconf = typeconf
local function typeconf(...)
    local cls = _typeconf(...)
    cls.exclude '^m_.*'
    cls.luaname(function (name, kind)
        name = name:gsub('^e_', '')
        name = name:gsub('^b2_', '')
        local v = name:match('^%u+')
        if v and kind == 'func' then
            name = name:gsub('^' .. v, string.lower(v))
        end
        return name
    end)
    return cls
end

typeconf 'b2Vec2'
typeconf 'b2Vec3'
typeconf 'b2ContactID'
typeconf 'b2ContactFeature'
typeconf 'b2Color'
typeconf 'b2FixtureUserData'
typeconf 'b2Filter'
typeconf 'b2ManifoldPoint'
typeconf 'b2Rot'

typeconf 'b2Draw'
    .exclude '*'
typeonly 'b2DestructionListener'
typeonly 'b2ContactFilter'
typeonly 'b2ContactListener'
typeonly 'b2QueryCallback'
typeonly 'b2RayCastCallback'
typeconf 'box2d::Vec2Array'
typeconf 'box2d::DestructionListener'
typeconf 'box2d::ContactFilter'
typeconf 'box2d::ContactListener'
typeconf 'box2d::QueryCallback'
typeconf 'box2d::RayCastCallback'
typeconf 'box2d::DebugNode::Flags'
typeconf 'box2d::DebugNode'

typeconf 'b2MassData'
    .extend 'box2d::b2MassDataExtend'
typeconf 'b2Transform'
typeconf 'b2RayCastInput'
typeconf 'b2RayCastOutput'

typeconf 'b2Shape::Type'
typeconf 'b2Shape'
typeconf 'b2PolygonShape'
typeconf 'b2EdgeShape'
typeconf 'b2CircleShape'
typeconf 'b2ChainShape'

typeconf 'b2BodyDef'
typeconf 'b2BodyType'
typeconf 'b2Body'
typeconf 'b2BodyUserData'
typeconf 'b2FixtureDef'
typeconf 'b2Fixture'
typeconf 'b2JointDef'
typeconf 'b2JointType'
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
typeconf 'b2World'
    .func 'SetDestructionListener' .arg1 '@addref(^)'
    .func 'SetContactFilter' .arg1 '@addref(^)'
    .func 'SetContactListener' .arg1 '@addref(^)'
    .func 'SetDebugDraw' .arg1 '@addref(^)'
typeconf 'b2WorldManifold'