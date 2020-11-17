#include "window.h"
#include "preferences.h"

NS_XGAME_BEGIN

window::Bounds window::getVisibleBounds()
{
    return (window::Bounds)cocos2d::Director::getInstance()->getOpenGLView()->getVisibleRect();
}

cocos2d::Size window::getVisibleSize()
{
    return cocos2d::Director::getInstance()->getOpenGLView()->getVisibleRect().size;
}

cocos2d::Size window::getFrameSize()
{
    return cocos2d::Director::getInstance()->getOpenGLView()->getFrameSize();
}

void window::setFrameSize(const cocos2d::Size &size)
{
    preferences::setFloat(CONF_WINDOW_WIDTH, size.width);
    preferences::setFloat(CONF_WINDOW_HEIGHT, size.height);
    cocos2d::Director::getInstance()->getOpenGLView()->setFrameSize(size.width, size.height);
}

cocos2d::Size window::getDesignSize()
{
    return cocos2d::Director::getInstance()->getOpenGLView()->getDesignResolutionSize();
}

void window::setDesignSize(const cocos2d::Size &size, ResolutionPolicy resolutionPolicy)
{
    cocos2d::Director::getInstance()->getOpenGLView()->setDesignResolutionSize(size.width, size.height, resolutionPolicy);
}

cocos2d::Vec2 window::convertToCameraSpace(const cocos2d::Vec2 &position)
{
    cocos2d::Rect rect;
    cocos2d::Vec3 out;
    auto director = cocos2d::Director::getInstance();
    auto runningScene = director->getRunningScene();
    auto w2l = runningScene->getWorldToNodeTransform();
    rect.size = director->getOpenGLView()->getDesignResolutionSize();
    cocos2d::isScreenPointInRect(position, runningScene->getDefaultCamera(), w2l, rect, &out);
    return cocos2d::Vec2(out.x, out.y);
}

NS_XGAME_END
