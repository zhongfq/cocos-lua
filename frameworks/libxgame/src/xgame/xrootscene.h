#ifndef __XROOTSCENE_H__
#define __XROOTSCENE_H__

#include "xgame/xdef.h"

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
    
    cocos2d::DrawNode *getClippingNode() { return _clippingStencil; }
};


NS_XGAME_END

#endif
