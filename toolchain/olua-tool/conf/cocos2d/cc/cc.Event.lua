local M = {}

local cls = class(M)
cls.CPPCLS = "cocos2d::Event::Type"
cls.LUACLS = "cc.Event.Type"
cls.enum('TOUCH', 'cocos2d::Event::Type::TOUCH')
cls.enum('KEYBOARD', 'cocos2d::Event::Type::KEYBOARD')
cls.enum('ACCELERATION', 'cocos2d::Event::Type::ACCELERATION')
cls.enum('MOUSE', 'cocos2d::Event::Type::MOUSE')
cls.enum('FOCUS', 'cocos2d::Event::Type::FOCUS')
cls.enum('GAME_CONTROLLER', 'cocos2d::Event::Type::GAME_CONTROLLER')
cls.enum('CUSTOM', 'cocos2d::Event::Type::CUSTOM')

local cls = class(M)
cls.CPPCLS = "cocos2d::Event"
cls.LUACLS = "cc.Event"
cls.SUPERCLS = "cc.Ref"
cls.prop('type', 'Type getType()')
cls.prop('currentTarget', 'Node* getCurrentTarget()')
cls.prop('stopped', 'bool isStopped()')
cls.funcs([[
    Type getType();
    void stopPropagation()
    bool isStopped()
    Node* getCurrentTarget()
]])

return M