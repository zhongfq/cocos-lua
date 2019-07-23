#ifndef __LUACOCOSADAPTER_H__
#define __LUACOCOSADAPTER_H__

#include "2d/CCComponent.h"
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

class LuaWebSocketDelegate : public cocos2d::network::WebSocket::Delegate {
public:
    static LuaWebSocketDelegate *create()
    {
        return new LuaWebSocketDelegate();
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
private:
    LuaWebSocketDelegate()
    :onOpenCallback(nullptr)
    ,onMessageCallback(nullptr)
    ,onCloseCallback(nullptr)
    ,onErrorCallback(nullptr)
    {
    }
};

namespace ui {
    class LuaEditBoxDelegate : public EditBoxDelegate {
    public:
        static LuaEditBoxDelegate *create()
        {
            return new LuaEditBoxDelegate();
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
        LuaEditBoxDelegate()
        :onEditingDidBegin(nullptr)
        ,onTextChanged(nullptr)
        ,onReturn(nullptr)
        ,onEditingDidEndWithAction(nullptr)
        {
            
        }
        bool init() { return true; }
    };
}

NS_CC_END

#endif
