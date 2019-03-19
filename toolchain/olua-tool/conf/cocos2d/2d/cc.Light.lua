local M = {}

local cls = class(M)
cls.CPPCLS = 'cocos2d::LightType'
cls.LUACLS = 'cc.LightType'
cls.enums [[
    DIRECTIONAL
    POINT
    SPOT
    AMBIENT
]]

local cls = class(M)
cls.CPPCLS = 'cocos2d::LightFlag'
cls.LUACLS = 'cc.LightFlag'
cls.enums [[
    LIGHT0
    LIGHT1
    LIGHT2
    LIGHT3
    LIGHT4
    LIGHT5
    LIGHT6
    LIGHT7
    LIGHT8
    LIGHT9
    LIGHT10
    LIGHT11
    LIGHT12
    LIGHT13
    LIGHT14
    LIGHT15
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::BaseLight"
cls.LUACLS = "cc.BaseLight"
cls.SUPERCLS = "cc.Node"
cls.funcs([[
    LightType getLightType()
    float getIntensity()
    void setIntensity(float intensity)
    LightFlag getLightFlag()
    void setLightFlag(LightFlag flag)
    void setEnabled(bool enabled)
    bool isEnabled()
]])
cls.props [[
    lightType
    intensity
    lightFlag
    enabled
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::DirectionLight"
cls.LUACLS = "cc.DirectionLight"
cls.SUPERCLS = "cc.BaseLight"
cls.funcs([[
    static DirectionLight* create(const Vec3 &direction, const Color3B &color)
    void setDirection(@pack const Vec3 &dir)
    @unpack Vec3 getDirection()
    @unpack Vec3 getDirectionInWorld()
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::PointLight"
cls.LUACLS = "cc.PointLight"
cls.SUPERCLS = "cc.BaseLight"
cls.funcs([[
    static PointLight* create(const Vec3 &position, const Color3B &color, float range)
    float getRange()
    void setRange(float range)
]])
cls.props [[
    range
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::SpotLight"
cls.LUACLS = "cc.SpotLight"
cls.SUPERCLS = "cc.BaseLight"
cls.funcs([[
    static SpotLight* create(const Vec3 &direction, const Vec3 &position, const Color3B &color, float innerAngle, float outerAngle, float range)
    void setDirection(@pack const Vec3 &dir)
    @unpack Vec3 getDirection()
    @unpack Vec3 getDirectionInWorld()
    void setRange(float range)
    float getRange()
    void setInnerAngle(float angle)
    float getInnerAngle()
    float getCosInnerAngle()
    void setOuterAngle(float outerAngle)
    float getOuterAngle()
    float getCosOuterAngle()
]])
cls.props [[
    range
    innerAngle
    cosInnerAngle
    outerAngle
    cosOuterAngle
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::AmbientLight"
cls.LUACLS = "cc.AmbientLight"
cls.SUPERCLS = "cc.BaseLight"
cls.funcs([[
    static AmbientLight* create(const Color3B &color)
]])

return M