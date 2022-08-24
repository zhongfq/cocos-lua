#ifndef __LUACOCOSADAPTER_H__
#define __LUACOCOSADAPTER_H__

#include "2d/CCComponent.h"
#include "2d/CCActionTween.h"
#include "ui/CocosGUI.h"
#include "network/WebSocket.h"

#include <functional>

NS_CC_BEGIN

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

NS_CC_END

#endif
