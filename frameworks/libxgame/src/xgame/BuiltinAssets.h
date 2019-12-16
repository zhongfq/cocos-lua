#ifndef __BuiltinAssets_h__
#define __BuiltinAssets_h__

#include "xgame/xdef.h"
#include "platform/CCFileUtils.h"

#include <stdio.h>

#include <string>
#include <unordered_map>

NS_XGAME_BEGIN

class BuiltinAssets {
public:
    class Assets {
    public:
        std::string path;
        size_t data;
    };
public:
    BuiltinAssets();
    
    void init(const std::string &path);
    bool exist(const std::string &path) const;
    cocos2d::FileUtils::Status getContents(const std::string& filename, cocos2d::ResizableBuffer* buffer) const;
private:
    std::unordered_map<std::string, Assets> _assets;
    FILE *_data;
};

NS_XGAME_END

#endif
