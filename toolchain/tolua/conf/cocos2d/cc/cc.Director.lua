local cls = class()
cls.CPPCLS = "cocos2d::Director"
cls.LUACLS = "cc.Director"
cls.SUPERCLS = "cc.Ref"
cls.func(nil, "static cocos2d::Director *getInstance()")
cls.prop("runningScene", 'cocos2d::Scene *getRunningScene()')
return cls