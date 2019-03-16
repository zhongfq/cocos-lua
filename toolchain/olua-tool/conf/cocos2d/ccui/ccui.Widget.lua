local M = {}

local cls = class(M)
cls.CPPCLS = "cocos2d::ui::Widget"
cls.LUACLS = "ccui.Widget"
cls.SUPERCLS = "cc.ProtectedNode"
cls.funcs [[
    bool hitTest(const Vec2 &pt, const Camera* camera, Vec3 *p = nullptr)
]]

return M