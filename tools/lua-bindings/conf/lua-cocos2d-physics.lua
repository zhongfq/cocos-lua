local typemod = require "typemod"
local M = typemod 'cocos2d_physics'
local typedef = M.typedef
local typeconf = M.typeconf
local typeconv = M.typeconv

M.PARSER = {
    PATH = {
        'cocos2d.h',
        'lua-bindings/LuaCocosAdapter.h'
    },
    ARGS = {
        '-I../../frameworks/cocos2d-x/cocos',
        '-I../../frameworks/libxgame/src',
        '-DCC_DLL=',
        '-DEXPORT_DLL=',
    },
}

M.NAMESPACES = {"cocos2d"}
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

M.MAKE_LUACLS = function (cppname)
    cppname = string.gsub(cppname, "^cocos2d::", "cc.")
    cppname = string.gsub(cppname, "::", ".")
    cppname = string.gsub(cppname, "[ *]*$", '')
    return cppname
end

M.EXCLUDE_TYPE = require "conf.exclude-type"

typedef {
    CPPCLS = 'cocos2d *',
    LUACLS = 'cc',
    CONV = 'olua_$$_obj',
}

typedef {
    CPPCLS = 'cocos2d::PhysicsMaterial',
    CONV = 'auto_olua_$$_cocos2d_PhysicsMaterial',
}

typeconv {
    CPPCLS = 'cocos2d::PhysicsMaterial',
    DEF = [[
        float density;
        float restitution;
        float friction;
    ]]
}

typedef {
    CPPCLS = 'cocos2d::PhysicsWorld',
    CONV = 'olua_$$_cppobj',
}

typedef {
    CPPCLS = 'cocos2d::PhysicsShape',
    CONV = 'olua_$$_cppobj',
}

typedef {
    CPPCLS = 'cocos2d::PhysicsContact',
    CONV = 'olua_$$_cppobj',
}

typedef {
    CPPCLS = 'cocos2d::PhysicsContactPreSolve',
    CONV = 'olua_$$_cppobj',
}

typedef {
    CPPCLS = 'cocos2d::PhysicsContactPostSolve',
    CONV = 'olua_$$_cppobj',
}

typedef {
    CPPCLS = 'cocos2d::PhysicsRayCastInfo',
    CONV = 'olua_$$_cppobj',
}

local EventListenerPhysicsContact = typeconf 'cocos2d::EventListenerPhysicsContact'
EventListenerPhysicsContact.VAR('onContactBegin', 'std::function<bool(@local PhysicsContact& contact)> onContactBegin = nullptr')
EventListenerPhysicsContact.VAR('onContactPreSolve', 'std::function<bool(@local PhysicsContact& contact, @local PhysicsContactPreSolve& solve)> onContactPreSolve = nullptr')
EventListenerPhysicsContact.VAR('onContactPostSolve', 'std::function<void(@local PhysicsContact& contact, @local const PhysicsContactPostSolve& solve)> onContactPostSolve = nullptr')
EventListenerPhysicsContact.VAR('onContactSeparate', 'std::function<void(@local PhysicsContact& contact)> onContactSeparate = nullptr')

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
PhysicsWorld.FUNC('getScene', [[
{
    auto self = olua_toobj<cocos2d::PhysicsWorld>(L, 1);
    cocos2d::Scene &scene = self->getScene();
    olua_push_cppobj<cocos2d::Scene>(L, &scene);
    return 1;
}]])
PhysicsWorld.PROP('scene')
PhysicsWorld.CALLBACK {
    FUNCS = {'void rayCast(std::function<bool(@local PhysicsWorld& world, @local const PhysicsRayCastInfo& info, void* data)> func, const Vec2& start, const Vec2& end, void* data)'},
    TAG_MAKER = 'olua_makecallbacktag("rayCast")',
    TAG_MODE = 'OLUA_TAG_REPLACE',
}
PhysicsWorld.CALLBACK {
    FUNCS = {'void queryRect(std::function<bool(@local PhysicsWorld&, @local PhysicsShape&, void*)> func, const Rect& rect, void* data)'},
    TAG_MAKER = 'olua_makecallbacktag("queryRect")',
    TAG_MODE = 'OLUA_TAG_REPLACE',
}
PhysicsWorld.CALLBACK {
    FUNCS = {'void queryPoint(std::function<bool(@local PhysicsWorld&, @local PhysicsShape&, void*)> func, const Vec2& point, void* data)'},
    TAG_MAKER = 'olua_makecallbacktag("queryPoint")',
    TAG_MODE = 'OLUA_TAG_REPLACE',
}
PhysicsWorld.CALLBACK {
    FUNCS = {'void setPreUpdateCallback(@nullable const std::function<void()> &callback)'},
    TAG_MAKER = 'olua_makecallbacktag("preUpdateCallback")',
    TAG_MODE = 'OLUA_TAG_REPLACE',
}
PhysicsWorld.CALLBACK {
    FUNCS = {'void setPostUpdateCallback(@nullable const std::function<void()> &callback)'},
    TAG_MAKER = 'olua_makecallbacktag("postUpdateCallback")',
    TAG_MODE = 'OLUA_TAG_REPLACE',
}

return M