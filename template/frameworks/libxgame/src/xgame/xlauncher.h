#ifndef __XLAUNCHER_H__
#define __XLAUNCHER_H__

#include "xgame/xdef.h"

#include "cocos/2d/CCScene.h"

#include <vector>
#include <string>

NS_XGAME_BEGIN

class launcher : public cocos2d::Scene
{
public:
    static launcher* create(const std::string &script_path);
    
    virtual void onEnter() override;
private:
    launcher(const std::string &script_path)
        :_script_path(script_path)
        ,_executed(false)
    {}
    virtual ~launcher() {};
    
    void execute();
private:
    std::string _script_path;
    bool _executed;
};

NS_XGAME_END

#endif
