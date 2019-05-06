#include "xgame/xfilesystem-private.h"
#include "xgame/xruntime.h"

#include "cocos2d.h"

#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID

#define JAVA_RUNTIME_CLASS "kernel/android/Runtime"

USING_NS_XGAME;
USING_NS_CC;

const std::string __filesystem_getDocumentDirectory()
{
    static std::string path;
    
    if (path.size() == 0) {
        path = JniHelper::callStaticStringMethod(JAVA_RUNTIME_CLASS, "getDocumentDirectory");
    }
    
    return path;
}

const std::string __filesystem_getCacheDirectory()
{
    static std::string path;
    
    if (path.size() == 0) {
        path = JniHelper::callStaticStringMethod(JAVA_RUNTIME_CLASS, "getCacheDirectory");
    }
    
    return path;
}

const std::string __filesystem_getTmpDirectory()
{
    static std::string path;
    
    if (path.size() == 0) {
        path = JniHelper::callStaticStringMethod(JAVA_RUNTIME_CLASS, "getTmpDirectory");
    }
    
    return path;
}

const std::string __filesystem_getSDCardDirectory()
{
    static std::string path;
    
    if (path.size() == 0) {
        path = JniHelper::callStaticStringMethod(JAVA_RUNTIME_CLASS, "getSDCardDirectory");
    }
    
    return path;
}

const std::string __filesystem_getDir(const std::string &type)
{
    return JniHelper::callStaticStringMethod(JAVA_RUNTIME_CLASS, "getDirectory", type);
}

#endif