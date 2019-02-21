#ifndef __XROOTSCENE_H__
#define __XROOTSCENE_H__

#include "xgame/xdef.h"

#include "cocos/2d/CCScene.h"

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

NS_XGAME_END

#endif
