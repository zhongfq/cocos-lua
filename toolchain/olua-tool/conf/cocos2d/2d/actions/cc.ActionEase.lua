local M = {}

local cls = class(M)
cls.CPPCLS = "cocos2d::ActionEase"
cls.LUACLS = "cc.ActionEase"
cls.SUPERCLS = "cc.ActionInterval"
cls.funcs([[
    ActionInterval* getInnerAction()
]])
cls.prop('innerAction')

local cls = class(M)
cls.CPPCLS = "cocos2d::EaseRateAction"
cls.LUACLS = "cc.EaseRateAction"
cls.SUPERCLS = "cc.ActionEase"
cls.funcs([[
    static EaseRateAction* create(@ref(singleref innerAction) ActionInterval* action, float rate)
    void setRate(float rate)
    float getRate()
]])
cls.prop('rate')

local function ease_class(NAME)
    local cls = class(M)
    cls.CPPCLS = format_snippet "cocos2d::${NAME}"
    cls.LUACLS = format_snippet "cc.${NAME}"
    cls.SUPERCLS = "cc.ActionEase"
    cls.funcs(format_snippet([[
        static ${NAME* create(@ref(singleref innerAction) ActionInterval* action)
    ]]))
end

ease_class('EaseExponentialIn')
ease_class('EaseExponentialOut')
ease_class('EaseExponentialInOut')
ease_class('EaseSineIn')
ease_class('EaseSineOut')
ease_class('EaseSineInOut')
ease_class('EaseBounceIn')
ease_class('EaseBounceOut')
ease_class('EaseBounceInOut')
ease_class('EaseBackIn')
ease_class('EaseBackOut')
ease_class('EaseBackInOut')
ease_class('EaseQuadraticActionIn')
ease_class('EaseQuadraticActionOut')
ease_class('EaseQuadraticActionInOut')
ease_class('EaseQuarticActionIn')
ease_class('EaseQuarticActionOut')
ease_class('EaseQuarticActionInOut')
ease_class('EaseQuinticActionIn')
ease_class('EaseQuinticActionOut')
ease_class('EaseQuinticActionInOut')
ease_class('EaseCircleActionIn')
ease_class('EaseCircleActionOut')
ease_class('EaseCircleActionInOut')
ease_class('EaseCubicActionIn')
ease_class('EaseCubicActionOut')
ease_class('EaseCubicActionInOut')

local function ease_rate_class(NAME)
    local cls = class(M)
    cls.CPPCLS = format_snippet "cocos2d::${NAME}"
    cls.LUACLS = format_snippet "cc.${NAME}"
    cls.SUPERCLS = "cc.EaseRateAction"
    cls.funcs(format_snippet([[
        static ${NAME* create(@ref(singleref innerAction) ActionInterval* action, float rate)
    ]]))
end

ease_rate_class('EaseIn')
ease_rate_class('EaseOut')
ease_rate_class('EaseInOut')

local cls = class(M)
cls.CPPCLS = "cocos2d::EaseElastic"
cls.LUACLS = "cc.EaseElastic"
cls.SUPERCLS = "cc.ActionEase"
cls.funcs([[
    float getPeriod()
    void setPeriod(float fPeriod)
]])
cls.prop('period')

local function ease_elastic_class(NAME)
    local cls = class(M)
    cls.CPPCLS = format_snippet "cocos2d::${NAME}"
    cls.LUACLS = format_snippet "cc.${NAME}"
    cls.SUPERCLS = "cc.EaseElastic"
    cls.funcs(format_snippet([[
        static ${NAME* create(@ref(singleref innerAction) ActionInterval* action, float rate = 0.3f)
    ]]))
end

ease_elastic_class('EaseElasticIn')
ease_elastic_class('EaseElasticOut')
ease_elastic_class('EaseElasticInOut')

local cls = class(M)
cls.CPPCLS = "cocos2d::EaseBezierAction"
cls.LUACLS = "cc.EaseBezierAction"
cls.SUPERCLS = "cc.ActionEase"
cls.funcs([[
    static EaseBezierAction* create(@ref(singleref innerAction) ActionInterval* action)
    void setBezierParamer( float p0, float p1, float p2, float p3)
]])

return M