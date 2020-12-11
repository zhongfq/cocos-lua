#ifndef __XGAME_ROOTSCENE_H__
#define __XGAME_ROOTSCENE_H__

#include "xgame/config.h"

#include "2d/CCScene.h"
#include "ui/UILayout.h"

#include <vector>
#include <string>

NS_XGAME_BEGIN

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
    static SceneNoCamera *createWithPhysics();
    
    SceneNoCamera();
    virtual ~SceneNoCamera();
    
    virtual void removeAllChildren() override;
};

class MaskLayout : public cocos2d::ui::Layout {
public:
    CREATE_FUNC(MaskLayout);
    
    MaskLayout() {};
    virtual ~MaskLayout();
    
    cocos2d::DrawNode *getClippingNode() { return _clippingStencil; }
    
    virtual void visit(cocos2d::Renderer *renderer, const cocos2d::Mat4& parentTransform, uint32_t parentFlags) override;
    virtual void onEnter() override;
    virtual void onExit() override;
    
    void setFilter(cocos2d::Node *value);
    cocos2d::Node *getFilter();
private:
    cocos2d::Node *_filter = nullptr;
};


NS_XGAME_END

#endif
