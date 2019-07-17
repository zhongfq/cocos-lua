local olua = require "olua"
local typedef = olua.typedef

olua.nowarning(typedef)

typedef {
    CONV_FUNC = 'olua_$$_obj',
    CPPCLS = 'cocos2d *',
    LUACLS = 'cc',
}

typedef {
    CONV_FUNC = 'auto_olua_$$_cocos2d_PhysicsMaterial',
    CPPCLS = 'cocos2d::PhysicsMaterial',
    INIT_VALUE = false,
}

typedef {
    CONV_FUNC = 'olua_$$_cppobj',
    CPPCLS = 'cocos2d::PhysicsWorld',
    INIT_VALUE = false,
}

typedef {
    CONV_FUNC = 'olua_$$_cppobj',
    CPPCLS = 'cocos2d::PhysicsShape',
    INIT_VALUE = false,
}

typedef {
    CONV_FUNC = 'olua_$$_cppobj',
    CPPCLS = 'cocos2d::PhysicsContact',
    INIT_VALUE = false,
}

typedef {
    CONV_FUNC = 'olua_$$_cppobj',
    CPPCLS = 'cocos2d::PhysicsContactPreSolve',
    INIT_VALUE = false,
}

typedef {
    CONV_FUNC = 'olua_$$_cppobj',
    CPPCLS = 'cocos2d::PhysicsContactPostSolve',
    INIT_VALUE = false,
}

typedef {
    CONV_FUNC = 'olua_$$_cppobj',
    CPPCLS = 'cocos2d::PhysicsRayCastInfo',
    INIT_VALUE = false,
}

typedef {
    CPPCLS = 'cocos2d::PhysicsContact::EventCode',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'cc.PhysicsContact.EventCode',
}

typedef {
    CPPCLS = 'cocos2d::PhysicsShape::Type',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'cc.PhysicsShape.Type',
}

typedef {
    CPPCLS = 'cocos2d::EventListenerPhysicsContact *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.EventListenerPhysicsContact',
}

typedef {
    CPPCLS = 'cocos2d::EventListenerPhysicsContactWithBodies *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.EventListenerPhysicsContactWithBodies',
}

typedef {
    CPPCLS = 'cocos2d::EventListenerPhysicsContactWithGroup *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.EventListenerPhysicsContactWithGroup',
}

typedef {
    CPPCLS = 'cocos2d::EventListenerPhysicsContactWithShapes *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.EventListenerPhysicsContactWithShapes',
}

typedef {
    CPPCLS = 'cocos2d::PhysicsBody *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.PhysicsBody',
}

typedef {
    CPPCLS = 'cocos2d::PhysicsContact *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.PhysicsContact',
}

typedef {
    CPPCLS = 'cocos2d::PhysicsContactPostSolve *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.PhysicsContactPostSolve',
}

typedef {
    CPPCLS = 'cocos2d::PhysicsContactPreSolve *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.PhysicsContactPreSolve',
}

typedef {
    CPPCLS = 'cocos2d::PhysicsJoint *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.PhysicsJoint',
}

typedef {
    CPPCLS = 'cocos2d::PhysicsJointDistance *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.PhysicsJointDistance',
}

typedef {
    CPPCLS = 'cocos2d::PhysicsJointFixed *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.PhysicsJointFixed',
}

typedef {
    CPPCLS = 'cocos2d::PhysicsJointGear *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.PhysicsJointGear',
}

typedef {
    CPPCLS = 'cocos2d::PhysicsJointGroove *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.PhysicsJointGroove',
}

typedef {
    CPPCLS = 'cocos2d::PhysicsJointLimit *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.PhysicsJointLimit',
}

typedef {
    CPPCLS = 'cocos2d::PhysicsJointMotor *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.PhysicsJointMotor',
}

typedef {
    CPPCLS = 'cocos2d::PhysicsJointPin *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.PhysicsJointPin',
}

typedef {
    CPPCLS = 'cocos2d::PhysicsJointRatchet *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.PhysicsJointRatchet',
}

typedef {
    CPPCLS = 'cocos2d::PhysicsJointRotaryLimit *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.PhysicsJointRotaryLimit',
}

typedef {
    CPPCLS = 'cocos2d::PhysicsJointRotarySpring *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.PhysicsJointRotarySpring',
}

typedef {
    CPPCLS = 'cocos2d::PhysicsJointSpring *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.PhysicsJointSpring',
}

typedef {
    CPPCLS = 'cocos2d::PhysicsRayCastInfo *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.PhysicsRayCastInfo',
}

typedef {
    CPPCLS = 'cocos2d::PhysicsShape *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.PhysicsShape',
}

typedef {
    CPPCLS = 'cocos2d::PhysicsShapeBox *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.PhysicsShapeBox',
}

typedef {
    CPPCLS = 'cocos2d::PhysicsShapeCircle *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.PhysicsShapeCircle',
}

typedef {
    CPPCLS = 'cocos2d::PhysicsShapeEdgeBox *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.PhysicsShapeEdgeBox',
}

typedef {
    CPPCLS = 'cocos2d::PhysicsShapeEdgeChain *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.PhysicsShapeEdgeChain',
}

typedef {
    CPPCLS = 'cocos2d::PhysicsShapeEdgePolygon *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.PhysicsShapeEdgePolygon',
}

typedef {
    CPPCLS = 'cocos2d::PhysicsShapeEdgeSegment *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.PhysicsShapeEdgeSegment',
}

typedef {
    CPPCLS = 'cocos2d::PhysicsShapePolygon *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.PhysicsShapePolygon',
}

typedef {
    CPPCLS = 'cocos2d::PhysicsWorld *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'cc.PhysicsWorld',
}

