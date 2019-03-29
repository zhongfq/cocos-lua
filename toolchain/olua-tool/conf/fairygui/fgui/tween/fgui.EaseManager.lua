local M = {}

local cls = class(M)
cls.CPPCLS = "fairygui::EaseType"
cls.LUACLS = "fgui.EaseType"
cls.enums [[
    Linear
    SineIn
    SineOut
    SineInOut
    QuadIn
    QuadOut
    QuadInOut
    CubicIn
    CubicOut
    CubicInOut
    QuartIn
    QuartOut
    QuartInOut
    QuintIn
    QuintOut
    QuintInOut
    ExpoIn
    ExpoOut
    ExpoInOut
    CircIn
    CircOut
    CircInOut
    ElasticIn
    ElasticOut
    ElasticInOut
    BackIn
    BackOut
    BackInOut
    BounceIn
    BounceOut
    BounceInOut
    Custom
]]

local cls = class(M)
cls.CPPCLS = "fairygui::EaseManager"
cls.LUACLS = "fgui.EaseManager"
cls.funcs [[
    static float evaluate(EaseType easeType, float time, float duration, float overshootOrAmplitude, float period)
]]

return M