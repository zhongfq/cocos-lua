local autoconf = require "autoconf"
local M = autoconf.typemod 'cocos2d_physics'
local typedef = M.typedef
local typeconf = M.typeconf
local typeconv = M.typeconv

M.PATH = "../../frameworks/libxgame/src/lua-bindings"
M.INCLUDES = [[
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "lua-bindings/LuaCocosAdapter.h"
#include "xgame/xlua.h"
#include "cocos2d.h"
]]
M.CHUNK = [[
using namespace cocos2d;
]]

M.MAKE_LUACLS = function (cppname)
    cppname = string.gsub(cppname, "^cocos2d::", "cc.")
    cppname = string.gsub(cppname, "::", ".")
    return cppname
end

M.EXCLUDE_TYPE = require "conf.exclude-type"

typeconv 'cocos2d::PhysicsMaterial'
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

local PhysicsWorld = typeconf 'cocos2d::PhysicsWorld'
PhysicsWorld.CALLBACK {NAME = 'setPreUpdateCallback', NULLABLE = true}
PhysicsWorld.CALLBACK {NAME = 'setPostUpdateCallback', NULLABLE = true}

return M