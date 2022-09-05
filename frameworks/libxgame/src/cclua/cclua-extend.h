#ifndef __CCLUA_EXTEND_H__
#define __CCLUA_EXTEND_H__

#include "2d/CCComponent.h"
#include "2d/CCActionTween.h"
#include "ui/CocosGUI.h"
#include "network/WebSocket.h"
#include "cclua/olua-2dx.h"

#include <functional>

NS_CC_BEGIN

typedef cocos2d::Rect Bounds;

class LuaComponent : public Component
{
public:
    static LuaComponent* create();
    LuaComponent();
    virtual ~LuaComponent();
    
    virtual void update(float delta);
    virtual void onEnter();
    virtual void onExit();
    virtual void onAdd();
    virtual void onRemove();
public:
    std::function<void(float)> onUpdateCallback;
    std::function<void()> onEnterCallback;
    std::function<void()> onExitCallback;
    std::function<void()> onAddCallback;
    std::function<void()> onRemoveCallback;
};

class LuaTweenNode : public Node, public ActionTweenDelegate
{
public:
    typedef std::function<void(float, const std::string &)> ccTweenCallback;
    
    static LuaTweenNode *create(const ccTweenCallback &callback);
    
    virtual void updateTweenAction(float value, const std::string &key);
private:
    virtual bool initWithCallback(const ccTweenCallback &callback);
    
    ccTweenCallback _callback = nullptr;
};

class LuaWebSocketDelegate : public cocos2d::network::WebSocket::Delegate {
public:
    LuaWebSocketDelegate()
       :onOpenCallback(nullptr)
       ,onMessageCallback(nullptr)
       ,onCloseCallback(nullptr)
       ,onErrorCallback(nullptr)
       {
       }
    
    virtual void onOpen(network::WebSocket* ws)
    {
        if (onOpenCallback) {
            onOpenCallback(ws);
        }
    }
    
    virtual void onMessage(network::WebSocket* ws, const network::WebSocket::Data& data)
    {
        if (onMessageCallback) {
            onMessageCallback(ws, data);
        }
    }
    
    virtual void onClose(network::WebSocket* ws)
    {
        if (onCloseCallback) {
            onCloseCallback(ws);
        }
    }
    
    virtual void onError(network::WebSocket* ws, const network::WebSocket::ErrorCode& error)
    {
        if (onErrorCallback) {
            onErrorCallback(ws, error);
        }
    }
public:
    std::function<void (network::WebSocket *)> onOpenCallback;
    std::function<void (network::WebSocket *, const network::WebSocket::Data &)> onMessageCallback;
    std::function<void (network::WebSocket *)> onCloseCallback;
    std::function<void (network::WebSocket *, const network::WebSocket::ErrorCode &)> onErrorCallback;
};

namespace ui {
    class LuaEditBoxDelegate : public EditBoxDelegate {
    public:
        LuaEditBoxDelegate()
        :onEditingDidBegin(nullptr)
        ,onTextChanged(nullptr)
        ,onReturn(nullptr)
        ,onEditingDidEndWithAction(nullptr)
        {
        }
        
        virtual void editBoxEditingDidBegin(EditBox* editBox)
        {
            if (onEditingDidBegin) {
                onEditingDidBegin(editBox);
            }
        }
        
        virtual void editBoxTextChanged(EditBox* editBox, const std::string& text)
        {
            if (onTextChanged) {
                onTextChanged(editBox, text);
            }
        }
        
        virtual void editBoxReturn(EditBox* editBox)
        {
            if (onReturn) {
                onReturn(editBox);
            }
        }
        
        virtual void editBoxEditingDidEndWithAction(EditBox* editBox, EditBoxEndAction action)
        {
            if (onEditingDidEndWithAction) {
                onEditingDidEndWithAction(editBox, action);
            }
        }
        
        std::function<void(EditBox *)> onEditingDidBegin;
        std::function<void(EditBox *, const std::string &)> onTextChanged;
        std::function<void(EditBox *)> onReturn;
        std::function<void(EditBox *, EditBoxDelegate::EditBoxEndAction)> onEditingDidEndWithAction;
    private:
        bool init() { return true; }
    };
}

class ScaleFrom : public ScaleTo
{
public:
    static ScaleFrom *create(float duration, float s);
    static ScaleFrom *create(float duration, float sx, float sy);
    static ScaleFrom *create(float duration, float sx, float sy, float sz);
    virtual void startWithTarget(Node *target) override;
    virtual ScaleFrom *clone() const override;
    virtual ScaleFrom *reverse() const override;
    
private:
    ScaleFrom() {}
    virtual ~ScaleFrom() {}
    CC_DISALLOW_COPY_AND_ASSIGN(ScaleFrom);
};

class MoveFrom : public MoveBy
{
public:
    static MoveFrom *create(float duration, const Vec2 &position);
    static MoveFrom *create(float duration, const Vec3 &position);
    virtual MoveFrom *clone() const override;
    virtual MoveFrom *reverse() const  override;
    virtual void startWithTarget(Node *target) override;
    
private:
    MoveFrom() {}
    virtual ~MoveFrom() {}
    bool initWithDuration(float duration, const Vec2 &position);
    bool initWithDuration(float duration, const Vec3 &position);
protected:
    Vec3 _endPosition;

private:
    CC_DISALLOW_COPY_AND_ASSIGN(MoveFrom);
};

class FadeFrom : public FadeTo
{
public:
    static FadeFrom *create(float d, uint8_t opacity);

    virtual void startWithTarget(Node *target) override;
    virtual FadeFrom *clone() const  override;
    virtual FadeFrom *reverse() const override;
    virtual void update(float time) override;
private:
    FadeFrom():_deltaOpacity(0) {}
    virtual ~FadeFrom() {}
    CC_DISALLOW_COPY_AND_ASSIGN(FadeFrom);
    uint8_t _deltaOpacity;
};

class RotateFrom : public RotateTo
{
public:
    static RotateFrom *create(float duration, float fromAngleX, float fromAngleY);
    static RotateFrom *create(float duration, float fromAngle);
    static RotateFrom *create(float duration, const Vec3 &fromAngle3D);

    virtual RotateFrom *clone() const override;
    virtual RotateFrom *reverse() const override;
    virtual void startWithTarget(Node *target) override;
private:
    RotateFrom() {};
    virtual ~RotateFrom() {};
    CC_DISALLOW_COPY_AND_ASSIGN(RotateFrom);
};

class ImageExtend : private cocos2d::Image {
public:
    static bool getPNGPremultipliedAlphaEnabled() { return PNG_PREMULTIPLIED_ALPHA_ENABLED; }
};

class FileUtilsExtend {
public:
    static cocos2d::Data getFileDataFromZip(cocos2d::FileUtils *obj, const std::string &zipPath, const std::string &name);
};

class NodeExtend {
public:
    static float getAnchorX(cocos2d::Node *obj);
    static void setAnchorX(cocos2d::Node *obj, float value);
    
    static float getAnchorY(cocos2d::Node *obj);
    static void setAnchorY(cocos2d::Node *obj, float value);
    
    static float getWidth(cocos2d::Node *obj);
    static void setWidth(cocos2d::Node *obj, float value);
    
    static float getHeight(cocos2d::Node *obj);
    static void setHeight(cocos2d::Node *obj, float value);
    
    static float getAlpha(cocos2d::Node *obj);
    static void setAlpha(cocos2d::Node *obj, float value);
    
    static oluaret_t __index(lua_State *L);
    
    static cocos2d::Bounds getBounds(cocos2d::Node *obj, cocos2d::Node *target, float left, float right, float top, float bottom);
};

class Mat4Extend {
public:
    static cocos2d::Vec4 transform(cocos2d::Mat4 *mat, OLUA_PACK const cocos2d::Vec4 &p);
    static cocos2d::Vec3 transform(cocos2d::Mat4 *mat, OLUA_PACK const cocos2d::Vec3 &p);
    static cocos2d::Vec2 transform(cocos2d::Mat4 *mat, OLUA_PACK const cocos2d::Vec2 &p);
    static OLUA_POSTNEW cocos2d::Mat4 *__add(cocos2d::Mat4 *mat1, cocos2d::Mat4 *mat2);
    static OLUA_POSTNEW cocos2d::Mat4 *__sub(cocos2d::Mat4 *mat1, cocos2d::Mat4 *mat2);
    static OLUA_POSTNEW cocos2d::Mat4 *__mul(cocos2d::Mat4 *mat1, cocos2d::Mat4 *mat2);
};

NS_CC_END

#ifdef CCLUA_BUILD_SPINE
#include "spine/spine-cocos2dx.h"

namespace spine {

class SkeletonDataExtend {
public:
    static oluaret_t __gc(lua_State *L);
    static oluaret_t create(lua_State *L, const char *skelPath, const char *atlasPath, float scale = 1.0f);
};

}
#endif // CCLUA_BUILD_SPINE

#endif
