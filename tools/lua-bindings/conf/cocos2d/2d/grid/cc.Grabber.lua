local M = {}

local cls = class(M)
cls.CPPCLS = "cocos2d::Grabber"
cls.LUACLS = "cc.Grabber"
cls.SUPERCLS = "cc.Ref"
cls.funcs [[
    void grab(Texture2D *texture)
    void beforeRender(Texture2D *texture)
    void afterRender(Texture2D *texture)
]]

return M