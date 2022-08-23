#include "QRCode.h"

USING_NS_CC;
USING_NS_CCLUA;

QRCode *QRCode::create(const std::string &code, int version, ECLevel level, EncodeMode hint, bool casesensitive)
{
    QRCode *s = new QRCode;
    s->autorelease();
    if(s->initWithString(code, version, level, hint, casesensitive)) {
        return s;
    }
    
    return nullptr;
}

bool QRCode::initWithString(const std::string &code, int version, ECLevel level, EncodeMode hint, bool casesensitive)
{
    Sprite::init();
    QRcode *qrcode = QRcode_encodeString(code.c_str(), version, (QRecLevel)level, (QRencodeMode)hint, (int)casesensitive);
    if (qrcode != nullptr) {
        Texture2D *texture = new Texture2D();
        unsigned char *img = (unsigned char *)malloc(qrcode->width * qrcode->width * 3); // RGB
        unsigned char *data = img;
        for (int i = 0; i < qrcode->width * qrcode->width; i++)
        {
            if ((qrcode->data[i] & 1) == 0)
            {
                *data++ = 255;
                *data++ = 255;
                *data++ = 255;
            }
            else
            {
                *data++ = 0;
                *data++ = 0;
                *data++ = 0;
            }
        }
        
        texture->initWithData(img, qrcode->width * qrcode->width, backend::PixelFormat::RGB888,
            qrcode->width, qrcode->width, Size(qrcode->width, qrcode->width));
        texture->setAliasTexParameters();
        setTexture(texture);
        Rect rect = Rect::ZERO;
        rect.size = texture->getContentSize();
        setTextureRect(rect);
        setIgnoreAnchorPointForPosition(true);
        QRcode_free(qrcode);
        free(img);
        texture->autorelease();
        return true;
    }
    return false;
}
