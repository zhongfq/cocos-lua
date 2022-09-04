#ifndef __CCLUA_WINDOW_H__
#define __CCLUA_WINDOW_H__

#include "cclua/runtime.h"
#include "cclua/cclua-extend.h"

#include "cocos2d.h"

NS_CCLUA_BEGIN

class window {
public:
    static OLUA_UNPACK cocos2d::Bounds getVisibleBounds();
    static OLUA_UNPACK cocos2d::Size getVisibleSize();
    static OLUA_UNPACK cocos2d::Size getFrameSize();
    static void setFrameSize(OLUA_PACK const cocos2d::Size &size);
    static OLUA_UNPACK cocos2d::Size getDesignSize();
    static void setDesignSize(OLUA_PACK const cocos2d::Size &size,  ResolutionPolicy resolutionPolicy);
    static cocos2d::Vec2 convertToCameraSpace(OLUA_PACK const cocos2d::Vec2 &position);
};

NS_CCLUA_END

#endif
