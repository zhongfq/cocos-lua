local cls = class()
cls.CPPCLS = "cocos2d::Ref"
cls.LUACLS = "cc.Ref"
cls.func('__gc', '{\n    return xlua_ccobjgc(L);\n}')
cls.prop('referenceCount', 'unsigned int getReferenceCount()')
return cls