#include "xgame/xfilesystem.h"
#include "xgame/xruntime.h"
#include "xgame/lua_javabridge.h"

#include "cocos2d.h"

#define JAVA_RUNTIME_CLASS "kernel/android/Runtime"

USING_NS_XGAME;
USING_NS_CC;

NS_XGAME_BEGIN

#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
const std::string filesystem::getDocumentDirectory()
{
    static std::string path;
    
    if (path.size() == 0) {
        path = JniHelper::callStaticStringMethod(JAVA_RUNTIME_CLASS, "getDocumentDirectory");
    }
    
    return path;
}

const std::string filesystem::getCacheDirectory()
{
    static std::string path;
    
    if (path.size() == 0) {
        path = JniHelper::callStaticStringMethod(JAVA_RUNTIME_CLASS, "getCacheDirectory");
    }
    
    return path;
}

const std::string filesystem::getTmpDirectory()
{
    static std::string path;
    
    if (path.size() == 0) {
        path = JniHelper::callStaticStringMethod(JAVA_RUNTIME_CLASS, "getTmpDirectory");
    }
    
    return path;
}
#elif CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
const std::string filesystem::getDocumentDirectory()
{
    return filesystem::getWritablePath() + "/Documents";
}

const std::string filesystem::getCacheDirectory()
{
    return filesystem::getWritablePath() + "/Cache";
}

const std::string filesystem::getTmpDirectory()
{
    return filesystem::getWritablePath() + "/Tmp";
}
#endif

#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
const std::string filesystem::getSDCardDirectory()
{
    static std::string path;
    
    if (path.size() == 0) {
        path = JniHelper::callStaticStringMethod(JAVA_RUNTIME_CLASS, "getSDCardDirectory");
    }
    
    return path;
}
#else
const std::string filesystem::getSDCardDirectory()
{
    runtime::log("filesystem::getSDCardDirectory only support android");
    return "/";
}
#endif

const std::string filesystem::getWritablePath()
{
    std::string path = FileUtils::getInstance()->getWritablePath();
    auto sep = path.at(path.size() - 1);
    if (sep == '/' || sep == '\\') {
        return path.substr(0, path.size() - 1);
    } else {
        return path;
    }
}

const std::string filesystem::shortPath(const std::string &path, size_t limit)
{
    size_t len = path.size();
    if (len > limit) {
        return "..." + path.substr(len - limit + 3);
    } else {
        return path;
    }
}

bool filesystem::createDirectory(const std::string &path)
{
    return FileUtils::getInstance()->createDirectory(path);
}

bool filesystem::remove(const std::string &path)
{
    if (FileUtils::getInstance()->isDirectoryExist(path)) {
        return FileUtils::getInstance()->removeDirectory(path);
    } else {
        return FileUtils::getInstance()->removeFile(path);
    }
}

bool filesystem::exist(const std::string &path)
{
    return FileUtils::getInstance()->isFileExist(path);
}

NS_XGAME_END
