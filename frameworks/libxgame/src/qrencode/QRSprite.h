#ifndef __QRSPRITE_H__
#define __QRSPRITE_H__

#include "2d/CCSprite.h"

class QRSprite : public cocos2d::Sprite {
    
private:
    QRSprite();
    virtual ~QRSprite();
public:
    
    bool initWithString(const std::string &code);
    static QRSprite* create(const std::string &code);
};

#endif /* QRSprite_hpp */
