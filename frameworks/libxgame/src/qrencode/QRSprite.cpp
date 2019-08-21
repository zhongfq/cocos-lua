#include "QRSprite.h"
#include "qrencode.h"

using namespace cocos2d;

QRSprite* QRSprite::create(const std::string &code)
{
    QRSprite* s = new QRSprite;
    s->autorelease();
    if(s->initWithString(code))
        return s;
    
    return nullptr;
}

QRSprite::QRSprite()
{
}

QRSprite::~QRSprite()
{
}

bool QRSprite::initWithString(const std::string& code)
{
    Sprite::init();
    QRcode* _qrcode = QRcode_encodeString(code.c_str(), 0, QR_ECLEVEL_H, QR_MODE_8, 1);
    if (_qrcode != nullptr) {
        Texture2D *texture = new Texture2D();
        unsigned char *img = (unsigned char *)malloc(_qrcode->width * _qrcode->width * 3); // RGB
        unsigned char *data = img;
        for (int i = 0; i < _qrcode->width * _qrcode->width; i++)
        {
            if ((_qrcode->data[i] & 1) == 0)
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
        
        texture->initWithData(img, _qrcode->width * _qrcode->width, Texture2D::PixelFormat::RGB888,
                               _qrcode->width, _qrcode->width, Size(_qrcode->width, _qrcode->width));
        texture->setAliasTexParameters();
        setTexture(texture);
        Rect rect = Rect::ZERO;
        rect.size = texture->getContentSize();
        setTextureRect(rect);
        setIgnoreAnchorPointForPosition(true);
        QRcode_free(_qrcode);
        free(img);
        texture->autorelease();
        return true;
    }
    return false;
}
