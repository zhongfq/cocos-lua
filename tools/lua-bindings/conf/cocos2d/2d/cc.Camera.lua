local cls = class()
cls.CPPCLS = "cocos2d::Camera"
cls.LUACLS = "cc.Camera"
cls.SUPERCLS = "cc.Node"
cls.funcs [[
    static const experimental::Viewport& getDefaultViewport()
    static void setDefaultViewport(const experimental::Viewport& vp)
    static Camera* createPerspective(float fieldOfView, float aspectRatio, float nearPlane, float farPlane)
    static Camera* createOrthographic(float zoomX, float zoomY, float nearPlane, float farPlane)
    static Camera* create()
    static Camera* getVisitingCamera()
]]
cls.props [[
    defaultViewport
]]
return cls