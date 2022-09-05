module 'cocos2d_physics'

path "../../frameworks/libxgame/src/lua-bindings"

headers [[
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "cocos2d.h"
]]

luacls(function (cppname)
    cppname = string.gsub(cppname, "^cocos2d::", "cc.")
    cppname = string.gsub(cppname, "::", ".")
    return cppname
end)

luaopen [[cclua::runtime::registerFeature("physics", true);]]

macro '#if CC_USE_PHYSICS'

typeconv 'cocos2d::PhysicsMaterial'

typeconf 'cocos2d::PhysicsRayCastCallbackFunc'
typeconf 'cocos2d::PhysicsQueryRectCallbackFunc'
typeconf 'cocos2d::PhysicsQueryPointCallbackFunc'
typeconf 'cocos2d::EventListenerPhysicsContact'
typeconf 'cocos2d::EventListenerPhysicsContactWithGroup'
typeconf 'cocos2d::EventListenerPhysicsContactWithBodies'
typeconf 'cocos2d::EventListenerPhysicsContactWithShapes'
typeconf 'cocos2d::PhysicsBody'
typeconf 'cocos2d::PhysicsContact::EventCode'
typeconf 'cocos2d::PhysicsContact'
typeconf 'cocos2d::PhysicsContactPostSolve'
typeconf 'cocos2d::PhysicsContactPreSolve'
typeconf 'cocos2d::PhysicsJoint'
typeconf 'cocos2d::PhysicsJointDistance'
typeconf 'cocos2d::PhysicsJointFixed'
typeconf 'cocos2d::PhysicsJointGear'
typeconf 'cocos2d::PhysicsJointGroove'
typeconf 'cocos2d::PhysicsJointLimit'
typeconf 'cocos2d::PhysicsJointMotor'
typeconf 'cocos2d::PhysicsJointPin'
typeconf 'cocos2d::PhysicsJointRatchet'
typeconf 'cocos2d::PhysicsJointRotaryLimit'
typeconf 'cocos2d::PhysicsJointRotarySpring'
typeconf 'cocos2d::PhysicsJointSpring'
typeconf 'cocos2d::PhysicsShape::Type'
typeconf 'cocos2d::PhysicsShape'
typeconf 'cocos2d::PhysicsShapePolygon'
typeconf 'cocos2d::PhysicsShapeEdgePolygon'
typeconf 'cocos2d::PhysicsShapeBox'
typeconf 'cocos2d::PhysicsShapeCircle'
typeconf 'cocos2d::PhysicsShapeEdgeBox'
typeconf 'cocos2d::PhysicsShapeEdgeChain'
typeconf 'cocos2d::PhysicsShapeEdgeSegment'
typeconf 'cocos2d::PhysicsRayCastInfo'

typeconf 'cocos2d::PhysicsWorld'
    .callback 'setPreUpdateCallback' .arg1 '@nullable'
    .callback 'setPostUpdateCallback' .arg1 '@nullable'

macro '' -- CC_USE_PHYSICS
