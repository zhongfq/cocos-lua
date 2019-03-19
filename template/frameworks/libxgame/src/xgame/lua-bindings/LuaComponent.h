#ifndef __LUACOMPONENT_H__
#define __LUACOMPONENT_H__

#include "2d/CCComponent.h"

#include <functional>

NS_CC_BEGIN

class CC_DLL LuaComponent : public Component
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

NS_CC_END

#endif
