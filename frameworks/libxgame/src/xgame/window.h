#ifndef __XGAME_WINDOW_H__
#define __XGAME_WINDOW_H__

#include "xgame/config.h"
#include "xgame/xlua.h"

#include "cocos2d.h"

NS_XGAME_BEGIN

class window {
public:
    struct Rect {
        float left;     // x
        float right;    // x + width
        float top;      // y + height
        float bottom;   // y
    };
    
    typedef cocos2d::Rect Bounds;
    
    static Bounds getVisibleBounds();
    static cocos2d::Size getVisibleSize();
    static cocos2d::Size getFrameSize();
    static void setFrameSize(const cocos2d::Size &size);
    static cocos2d::Size getDesignSize();
    static void setDesignSize(const cocos2d::Size &size,  ResolutionPolicy resolutionPolicy);
    static cocos2d::Vec2 convertToCameraSpace(const cocos2d::Vec2 &position);
};

NS_XGAME_END

#endif
