#include "xgame/AssetsBundle.h"
#include "xgame/runtime.h"
#include "xgame/filesystem.h"

NS_XGAME_BEGIN

USING_NS_CC;

typedef enum {
    CHUNK_NONE = 0,
    CHUNK_META = 1,
    CHUNK_DATA = 2
} ChunkKind;

static uint16_t readUShort(FILE *file)
{
    uint8_t buf[2];
    if (fread(buf, sizeof(uint8_t), 2, file) == 2) {
        return (uint16_t)buf[1] << 8 | (uint16_t)buf[0];
    }
    return 0;
}

static uint32_t readUInt(FILE *file)
{
    uint8_t buf[4];
    if (fread(buf, sizeof(uint8_t), 4, file) == 4) {
        return (uint32_t)buf[3] << 24 | (uint32_t)buf[2] << 16 | (uint32_t)buf[1] << 8 | (uint32_t)buf[0];
    }
    return 0;
}

void AssetsBundle::init(const std::string &path)
{
    auto fs = FileUtils::getInstance();
    std::string fullPath = fs->fullPathForFilename(path);
    if (fullPath.size() == 0) {
        runtime::log("no builtin packed assets");
        return;
    }
    
    _data = fopen(fullPath.c_str(), "r");
    if (_data != NULL) {
        while (true) {
            uint16_t kind = readUShort(_data);
            if (kind == CHUNK_META) {
                Assets asset;
                uint16_t len = readUShort(_data);
                BufferReader *reader = filesystem::getBufferReader();
                reader->resize(len);
                if (fread(reader->buffer(), sizeof(unsigned char), len, _data) == len) {
                    asset.path = std::string((const char *)reader->buffer(), len);
                    asset.data = readUInt(_data);
                    _assets[asset.path] = asset;
                } else {
                    break;
                }
            } else {
                break;
            }
        }
    }
}

bool AssetsBundle::exist(const std::string &path) const
{
    return _assets.find(path) != _assets.end();
}

cocos2d::FileUtils::Status AssetsBundle::getContents(const std::string& filename, cocos2d::ResizableBuffer* buffer) const
{
    auto it = _assets.find(filename);
    
    if (it == _assets.end() || _data == NULL) {
        return FileUtils::Status::NotExists;
    }
    
    fseek(_data, it->second.data, SEEK_SET);
    readUShort(_data); // skip kind
    uint32_t len = readUInt(_data);
    buffer->resize(len);
    
    if (fread(buffer->buffer(), sizeof(unsigned char), len, _data) != len) {
        return FileUtils::Status::ReadFailed;
    }
    
    return FileUtils::Status::OK;
}

NS_XGAME_END
