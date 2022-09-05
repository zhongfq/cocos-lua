#ifndef __CCLUA_ROOTSCENE_H__
#define __CCLUA_ROOTSCENE_H__

#include "cclua/runtime.h"

#include "2d/CCScene.h"
#include "ui/UILayout.h"

#include <vector>
#include <string>

NS_CCLUA_BEGIN

class RootScene : public cocos2d::Scene
{
public:
    static RootScene* create(const std::string &scriptPath);
    
    virtual void onEnter() override;
private:
    RootScene(const std::string &scriptPath)
        :_scriptPath(scriptPath)
        ,_executed(false)
    {}
    virtual ~RootScene() {};
    
    void execute();
private:
    std::string _scriptPath;
    bool _executed;
};

class SceneNoCamera : public cocos2d::Scene
{
public:
    static SceneNoCamera *create();
    static SceneNoCamera *createWithSize(const cocos2d::Size& size);
    
#if (CC_USE_PHYSICS || (CC_USE_3D_PHYSICS && CC_ENABLE_BULLET_INTEGRATION))
    static SceneNoCamera *createWithPhysics();
#endif
    
    SceneNoCamera();
    virtual ~SceneNoCamera();
    
    virtual void removeAllChildren() override;
};

class Container : public cocos2d::ui::Layout {
public:
    CREATE_FUNC(Container);
    
    Container() {};
    virtual ~Container();
    
    cocos2d::DrawNode *getClippingNode() { return _clippingStencil; }
    
    virtual void visit(cocos2d::Renderer *renderer, const cocos2d::Mat4& parentTransform, uint32_t parentFlags) override;
    virtual void onEnter() override;
    virtual void onExit() override;
    
    void setFilter(OLUA_NULLABLE OLUA_ADDREF(^) cocos2d::Node *value);
    OLUA_ADDREF(^) cocos2d::Node *getFilter();
private:
    cocos2d::Node *_filter = nullptr;
};


NS_CCLUA_END

#endif
