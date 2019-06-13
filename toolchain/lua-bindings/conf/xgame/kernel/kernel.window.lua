local cls = class()
cls.CPPCLS = "xgame::window"
cls.LUACLS = "kernel.window"
cls.REG_LUATYPE = false
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
        (float)olua_checknumber(L, 1), (float)olua_checknumber(L, 2),
        (ResolutionPolicy)olua_checkinteger(L, 3));
    return 0;
}]])
cls.func('convertToCameraSpace', [[
{
    cocos2d::Rect rect;
    cocos2d::Vec3 out;
    auto director = cocos2d::Director::getInstance();
    auto pt = cocos2d::Vec2(olua_checknumber(L, 1), olua_checknumber(L, 2));
    auto runningScene = director->getRunningScene();
    auto w2l = runningScene->getWorldToNodeTransform();
    rect.size = director->getOpenGLView()->getDesignResolutionSize();
    cocos2d::isScreenPointInRect(pt, runningScene->getDefaultCamera(), w2l, rect, &out);
    lua_pushnumber(L, out.x);
    lua_pushnumber(L, out.y);
    return 2;
}]])
return cls