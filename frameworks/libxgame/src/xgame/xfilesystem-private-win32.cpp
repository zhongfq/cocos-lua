#include "xgame/xfilesystem.h"
#include "xgame/xfilesystem-private.h"
#include "xgame/xruntime.h"

#include "cocos2d.h"

USING_NS_XGAME;
USING_NS_CC;

const std::string __filesystem_getDocumentDirectory()
{
    return filesystem::getWritablePath() + "/Documents";
}

const std::string __filesystem_getCacheDirectory()
{
    return filesystem::getWritablePath() + "/Cache";
}

const std::string __filesystem_getTmpDirectory()
{
    return filesystem::getWritablePath() + "/Tmp";
}

const std::string __filesystem_getSDCardDirectory()
{
    runtime::log("filesystem::getSDCardDirectory only support android");
    return "/";
}
