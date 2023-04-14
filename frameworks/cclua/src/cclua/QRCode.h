#ifndef __CCLUA_QRCODE_H__
#define __CCLUA_QRCODE_H__

#include "runtime.h"
#include "qrencode/qrencode.h"

NS_CCLUA_BEGIN

class QRCode : public cocos2d::Sprite {
public:
    using ECLevel = QRecLevel;
    using EncodeMode = QRencodeMode;
public:
    static QRCode *create(const std::string &code, int version = 1, ECLevel level = ECLevel::QR_ECLEVEL_H, EncodeMode hint = EncodeMode::QR_MODE_8, bool casesensitive = true);
    
private:
    bool initWithString(const std::string &code, int version, ECLevel level, EncodeMode hint, bool casesensitive);
};

NS_CCLUA_END

#endif
