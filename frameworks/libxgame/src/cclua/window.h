#ifndef __CCLUA_WINDOW_H__
#define __CCLUA_WINDOW_H__

#include "cclua/runtime.h"

#include "cocos2d.h"

NS_CCLUA_BEGIN

class window {
public:
    typedef cocos2d::Rect Bounds;
    
    static Bounds getVisibleBounds();
    static cocos2d::Size getVisibleSize();
    static cocos2d::Size getFrameSize();
    static void setFrameSize(const cocos2d::Size &size);
    static cocos2d::Size getDesignSize();
    static void setDesignSize(const cocos2d::Size &size,  ResolutionPolicy resolutionPolicy);
    static cocos2d::Vec2 convertToCameraSpace(const cocos2d::Vec2 &position);
};

NS_CCLUA_END

#endif
