#ifndef __XGAME_ASSETSBUNDLE_H__
#define __XGAME_ASSETSBUNDLE_H__

#include "xgame/config.h"
#include "platform/CCFileUtils.h"

#include <stdio.h>

#include <string>
#include <unordered_map>

NS_XGAME_BEGIN

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

NS_XGAME_END

#endif
