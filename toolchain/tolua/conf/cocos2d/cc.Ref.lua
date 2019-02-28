local cls = class()
cls.CPPCLS = "cocos2d::Ref"
cls.LUACLS = "cc.Ref"
cls.prop('referenceCount', 'unsigned int getReferenceCount()')
return cls