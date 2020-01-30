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
    AssetsBundle();
    
    void init(const std::string &path);
    bool exist(const std::string &path) const;
    cocos2d::FileUtils::Status getContents(const std::string& filename, cocos2d::ResizableBuffer* buffer) const;
private:
    std::unordered_map<std::string, Assets> _assets;
    FILE *_data;
};

NS_XGAME_END

#endif
