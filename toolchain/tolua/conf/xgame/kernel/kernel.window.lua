local cls = class()
cls.CPPCLS = "xgame::window"
cls.LUACLS = "kernel.window"
cls.func("visibleBounds", [[
{
    auto rect = cocos2d::Director::getInstance()->getOpenGLView()->getVisibleRect();
    lua_pushinteger(L, rect.getMinX());
    lua_pushinteger(L, rect.getMaxX());
    lua_pushinteger(L, rect.getMaxY());
    lua_pushinteger(L, rect.getMinY());
    return 4;
}
]])
cls.func('getDesignSize', [[
{
    auto size = cocos2d::Director::getInstance()->getOpenGLView()->getDesignResolutionSize();
    lua_pushnumber(L, size.width);
    lua_pushnumber(L, size.height);
    return 2;
}]])
cls.func('setDesignSize', [[
{
    lua_settop(L, 3);
    cocos2d::Director::getInstance()->getOpenGLView()->setDesignResolutionSize(
        (float)luaL_checknumber(L, 1), (float)luaL_checknumber(L, 2),
        (ResolutionPolicy)luaL_checkinteger(L, 3));
    return 0;
}]])
cls.func('convertToCameraSpace', [[
{
    cocos2d::Vec2 pt = cocos2d::Vec2(luaL_checknumber(L, 1), luaL_checknumber(L, 2));
    
    auto director = cocos2d::Director::getInstance();
    cocos2d::Mat4 w2l = director->getRunningScene()->getWorldToNodeTransform();
    cocos2d::Rect rect;
    rect.size = director->getOpenGLView()->getDesignResolutionSize();
    auto camera = director->getRunningScene()->getDefaultCamera();
    cocos2d::Vec3 Pn(pt.x, pt.y, -1), Pf(pt.x, pt.y, 1);
    Pn = camera->unprojectGL(Pn);
    Pf = camera->unprojectGL(Pf);
    
    //  then convert Pn and Pf to node space
    w2l.transformPoint(&Pn);
    w2l.transformPoint(&Pf);
    
    // Pn and Pf define a line Q(t) = D + t * E which D = Pn
    auto E = Pf - Pn;
    
    // second, get three points which define content plane
    //  these points define a plane P(u, w) = A + uB + wC
    cocos2d::Vec3 A = cocos2d::Vec3(rect.origin.x, rect.origin.y, 0);
    cocos2d::Vec3 B(rect.origin.x + rect.size.width, rect.origin.y, 0);
    cocos2d::Vec3 C(rect.origin.x, rect.origin.y + rect.size.height, 0);
    B = B - A;
    C = C - A;
    
    //  the line Q(t) intercept with plane P(u, w)
    //  calculate the intercept point P = Q(t)
    //      (BxC).A - (BxC).D
    //  t = -----------------
    //          (BxC).E
    cocos2d::Vec3 BxC;
    cocos2d::Vec3::cross(B, C, &BxC);
    auto BxCdotE = BxC.dot(E);
    auto t = (BxC.dot(A) - BxC.dot(Pn)) / BxCdotE;
    cocos2d::Vec3 P = Pn + t * E;
    
    lua_pushnumber(L, P.x);
    lua_pushnumber(L, P.y);
    
    return 2;
}]])
return cls