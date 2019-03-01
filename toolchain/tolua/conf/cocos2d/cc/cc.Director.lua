local cls = class()
cls.CPPCLS = "cocos2d::Director"
cls.LUACLS = "cc.Director"
cls.SUPERCLS = "cc.Ref"
cls.func(nil, "static Director *getInstance()")
cls.prop("runningScene", 'Scene *getRunningScene()')
return cls