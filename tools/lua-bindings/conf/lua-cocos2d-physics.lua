local M = ...
local typeconv = M.typeconv
local typedef = M.typedef

local function typeconf(name)
    local cls = M.typeconf(name)
    cls.GSUB = function (fn, decl)
        decl = string.gsub(decl, 'PHYSICSBODY_MATERIAL_DEFAULT', 'cocos2d::PHYSICSBODY_MATERIAL_DEFAULT')
        decl = string.gsub(decl, 'PHYSICSSHAPE_MATERIAL_DEFAULT', 'cocos2d::PHYSICSSHAPE_MATERIAL_DEFAULT')
        return decl
    end
    return cls
end

typedef {
    CPPCLS = 'cocos2d *',
    LUACLS = 'cc',
    CONV_FUNC = 'olua_$$_obj',
}

typedef {
    CPPCLS = 'cocos2d::PhysicsMaterial',
    CONV_FUNC = 'auto_luacv_$$_cocos2d_PhysicsMaterial',
    INIT_VALUE = false,
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
    CONV_FUNC = 'manual_luacv_$$_cocos2d_PhysicsWorld',
    INIT_VALUE = false,
}

typedef {
    CPPCLS = 'cocos2d::PhysicsShape',
    CONV_FUNC = 'manual_luacv_$$_cocos2d_PhysicsShape',
    INIT_VALUE = false,
}

typedef {
    CPPCLS = 'cocos2d::PhysicsContact',
    CONV_FUNC = 'manual_luacv_$$_cocos2d_PhysicsContact',
    INIT_VALUE = false,
}

typedef {
    CPPCLS = 'cocos2d::PhysicsContactPreSolve',
    CONV_FUNC = 'manual_luacv_$$_cocos2d_PhysicsContactPreSolve',
    INIT_VALUE = false,
}

typedef {
    CPPCLS = 'cocos2d::PhysicsContactPostSolve',
    CONV_FUNC = 'manual_luacv_$$_cocos2d_PhysicsContactPostSolve',
    INIT_VALUE = false,
}

typedef {
    CPPCLS = 'cocos2d::PhysicsRayCastInfo',
    CONV_FUNC = 'manual_luacv_$$_cocos2d_PhysicsRayCastInfo',
    INIT_VALUE = false,
}

M.CHUNK = M.CHUNK .. [[
static int manual_luacv_push_cocos2d_PhysicsWorld(lua_State *L, cocos2d::PhysicsWorld *value)
{
    if (!olua_getobj(L, value)) {
        olua_push_cppobj<cocos2d::PhysicsWorld>(L, value);
    }
    return 1;
}

static int manual_luacv_push_cocos2d_PhysicsShape(lua_State *L, cocos2d::PhysicsShape *value)
{
    if (!olua_getobj(L, value)) {
        olua_push_cppobj<cocos2d::PhysicsShape>(L, value);
    }
    return 1;
}

static int manual_luacv_push_cocos2d_PhysicsContact(lua_State *L, cocos2d::PhysicsContact *value)
{
    if (!olua_getobj(L, value)) {
        olua_push_cppobj<cocos2d::PhysicsContact>(L, value);
    }
    return 1;
}

static int manual_luacv_push_cocos2d_PhysicsContactPreSolve(lua_State *L, const cocos2d::PhysicsContactPreSolve *value)
{
    if (!olua_getobj(L, (cocos2d::PhysicsContactPreSolve *)value)) {
        olua_push_cppobj<cocos2d::PhysicsContactPreSolve>(L, (cocos2d::PhysicsContactPreSolve *)value);
    }
    return 1;
}

static int manual_luacv_push_cocos2d_PhysicsContactPostSolve(lua_State *L, const cocos2d::PhysicsContactPostSolve *value)
{
    if (!olua_getobj(L, (cocos2d::PhysicsContactPreSolve *)value)) {
        olua_push_cppobj<cocos2d::PhysicsContactPostSolve>(L, (cocos2d::PhysicsContactPostSolve *)value);
    }
    return 1;
}

static int manual_luacv_push_cocos2d_PhysicsRayCastInfo(lua_State *L, const cocos2d::PhysicsRayCastInfo *value)
{
    olua_push_cppobj<cocos2d::PhysicsRayCastInfo>(L, (cocos2d::PhysicsRayCastInfo *)value);
    return 1;
}
]]

local EventListenerPhysicsContact = typeconf 'cocos2d::EventListenerPhysicsContact'
EventListenerPhysicsContact.VAR('onContactBegin', 'std::function<bool(PhysicsContact& contact)> onContactBegin = nullptr')
EventListenerPhysicsContact.VAR('onContactPreSolve', 'std::function<bool(PhysicsContact& contact, PhysicsContactPreSolve& solve)> onContactPreSolve = nullptr')
EventListenerPhysicsContact.VAR('onContactPostSolve', 'std::function<void(PhysicsContact& contact, const PhysicsContactPostSolve& solve)> onContactPostSolve = nullptr')
EventListenerPhysicsContact.VAR('onContactSeparate', 'std::function<void(PhysicsContact& contact)> onContactSeparate = nullptr')

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

local PhysicsRayCastInfo = typeconf 'cocos2d::PhysicsRayCastInfo'
PhysicsRayCastInfo.CPPCLS = 'cocos2d::PhysicsRayCastInfo'
PhysicsRayCastInfo.VAR('shape', 'PhysicsShape* shape') -- TODO: autoconf
PhysicsRayCastInfo.VAR('start', 'Vec2 start')
PhysicsRayCastInfo.VAR('end', 'Vec2 end')
PhysicsRayCastInfo.VAR('contact', 'Vec2 contact')
PhysicsRayCastInfo.VAR('normal', 'Vec2 normal')
PhysicsRayCastInfo.VAR('fraction', 'float fraction')
PhysicsRayCastInfo.VAR('data', 'void* data')

local PhysicsWorld = typeconf 'cocos2d::PhysicsWorld'
PhysicsWorld.FUNC('getScene', [[
{
    auto self = olua_toobj<cocos2d::PhysicsWorld>(L, 1);
    cocos2d::Scene &scene = self->getScene();
    olua_push_cppobj<cocos2d::Scene>(L, &scene);
    return 1;
}]])
PhysicsWorld.PROP('scene')
PhysicsWorld.CALLBACK('rayCast', {
    FUNCS = {'void rayCast(std::function<bool(@stack PhysicsWorld& world, @stack const PhysicsRayCastInfo& info, void* data)> func, const Vec2& start, const Vec2& end, void* data)'},
    TAG_MAKER = 'olua_makecallbacktag("rayCast")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
})
PhysicsWorld.CALLBACK('queryRect', {
    FUNCS = {'void queryRect(std::function<bool(@stack PhysicsWorld&, @stack PhysicsShape&, void*)> func, const Rect& rect, void* data)'},
    TAG_MAKER = 'olua_makecallbacktag("queryRect")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
})
PhysicsWorld.CALLBACK('queryPoint', {
    FUNCS = {'void queryPoint(std::function<bool(@stack PhysicsWorld&, @stack PhysicsShape&, void*)> func, const Vec2& point, void* data)'},
    TAG_MAKER = 'olua_makecallbacktag("queryPoint")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
})
PhysicsWorld.CALLBACK('setPreUpdateCallback', {
    FUNCS = {'void setPreUpdateCallback(@nullable const std::function<void()> &callback)'},
    TAG_MAKER = 'olua_makecallbacktag("preUpdateCallback")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
})
PhysicsWorld.CALLBACK('setPostUpdateCallback', {
    FUNCS = {'void setPostUpdateCallback(@nullable const std::function<void()> &callback)'},
    TAG_MAKER = 'olua_makecallbacktag("postUpdateCallback")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
})

return M