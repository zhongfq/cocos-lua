#ifndef __CCLUA_ASSETSBUNDLE_H__
#define __CCLUA_ASSETSBUNDLE_H__

#include "cclua/runtime.h"
#include "platform/CCFileUtils.h"

#include <stdio.h>
#include <string>
#include <unordered_map>

NS_CCLUA_BEGIN

class AssetsBundle {
public:
    class Assets {
    public:
        std::string path;
        size_t data;
    };
public:
    AssetsBundle() {};
    virtual ~AssetsBundle() {};
    
    virtual void init(const std::string &path);
    virtual bool exist(const std::string &path) const;
    virtual cocos2d::FileUtils::Status getContents(const std::string& filename, cocos2d::ResizableBuffer* buffer) const;
protected:
    std::unordered_map<std::string, Assets> _assets;
    FILE *_data = nullptr;
};

NS_CCLUA_END

#endif
