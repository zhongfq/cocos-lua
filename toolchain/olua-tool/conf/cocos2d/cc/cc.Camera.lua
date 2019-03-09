local cls = class()
cls.CPPCLS = "cocos2d::Camera"
cls.LUACLS = "cc.Camera"
cls.SUPERCLS = "cc.Node"
cls.prop('defaultViewport', 'static const experimental::Viewport& getDefaultViewport()', 'static void setDefaultViewport(const experimental::Viewport& vp)')
cls.func(nil, 'static Camera* createPerspective(float fieldOfView, float aspectRatio, float nearPlane, float farPlane)')
cls.func(nil, 'static Camera* createOrthographic(float zoomX, float zoomY, float nearPlane, float farPlane)')
cls.func(nil, 'static Camera* create()')
cls.func(nil, 'static Camera* getVisitingCamera()')
return cls