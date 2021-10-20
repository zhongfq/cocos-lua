#include "cclua/AssetsBundle.h"
#include "cclua/runtime.h"
#include "cclua/filesystem.h"
#include "cclua/FileFinder.h"

#include <time.h>

NS_CCLUA_BEGIN

USING_NS_CC;

typedef enum {
    CHUNK_NONE = 0,
    CHUNK_META = 1,
    CHUNK_DATA = 2
} ChunkKind;

#ifdef CCLUA_OS_ANDROID
static std::string to_assets_path(const std::string &path)
{
    static const std::string apkprefix("assets/");
    if (path.find(apkprefix) == 0) {
        return path.substr(apkprefix.size());
    } else {
        return path;
    }
}
#else
static std::string to_assets_path(const std::string &path)
{
    return path;
}
#endif

static AssetsBundle::File *file_open(const char *path, const char *mode)
{
#ifdef CCLUA_OS_ANDROID
    AAsset* asset = AAssetManager_open(cclua::FileFinder::getAssetManager(), path, AASSET_MODE_RANDOM);
    return (AssetsBundle::File *)asset;
#else
    return (AssetsBundle::File *)fopen(path, mode);
#endif
}

int	file_close(AssetsBundle::File *file)
{
    if (!file) {
        return 0;
    }
#ifdef CCLUA_OS_ANDROID
    AAsset_close((AAsset * )file);
    return 0;
#else
    return fclose((FILE *)file);
#endif
}

static int file_seek(AssetsBundle::File *file, long offset, int whence)
{
#ifdef CCLUA_OS_ANDROID
    return (int)AAsset_seek((AAsset *)file, (off_t)offset, whence);
#else
    return fseek((FILE *)file, offset, whence);
#endif
}

static bool file_read(AssetsBundle::File *file, void *buf, size_t size)
{
#ifdef CCLUA_OS_ANDROID
    return (size_t)AAsset_read((AAsset *)file, buf, size) == size;
#else
    return fread(buf, sizeof(unsigned char), size, (FILE *)file) == size;
#endif
}

static ChunkKind file_read_kind(AssetsBundle::File *file)
{
    uint8_t buf[1];
    if (file_read(file, buf, 1)) {
        return (ChunkKind)buf[0];
    }
    return CHUNK_NONE;
}

static uint16_t file_read_ushort(AssetsBundle::File *file)
{
    uint8_t buf[2];
    if (file_read(file, buf, 2)) {
        return (uint16_t)buf[1] << 8 | (uint16_t)buf[0];
    }
    return 0;
}

static uint32_t file_read_uint(AssetsBundle::File *file)
{
    uint8_t buf[4];
    if (file_read(file, buf, 4)) {
        return (uint32_t)buf[3] << 24 | (uint32_t)buf[2] << 16 | (uint32_t)buf[1] << 8 | (uint32_t)buf[0];
    }
    return 0;
}

AssetsBundle::AssetsBundle()
:_data(NULL)
{
}

AssetsBundle::~AssetsBundle()
{
    file_close(_data);
}

void AssetsBundle::init(const std::string &path)
{
    auto fs = FileUtils::getInstance();
    std::string fullPath = fs->fullPathForFilename(path);
    if (fullPath.size() == 0) {
        runtime::log("no builtin packed assets");
        return;
    }
    
    _data = file_open(to_assets_path(fullPath).c_str(), "rb");
    if (_data != NULL) {
        while (true) {
            ChunkKind kind = file_read_kind(_data);
            if (kind == CHUNK_META) {
                Assets asset;
                uint16_t len = file_read_ushort(_data);
                BufferReader *reader = filesystem::getBufferReader();
                reader->resize(len);
                if (file_read(_data, reader->buffer(), len)) {
                    asset.path = std::string((const char *)reader->buffer(), len);
                    asset.data = file_read_uint(_data);
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
    return _assets.find(to_assets_path(path)) != _assets.end();
}

cocos2d::FileUtils::Status AssetsBundle::getContents(const std::string& filename, cocos2d::ResizableBuffer* buffer) const
{
    auto it = _assets.find(to_assets_path(filename));
    
    if (it == _assets.end() || _data == NULL) {
        return FileUtils::Status::NotExists;
    }
    
    file_seek(_data, it->second.data, SEEK_SET);
    file_read_kind(_data); // skip kind
    uint32_t len = file_read_uint(_data);
    buffer->resize(len);
    if (file_read(_data, buffer->buffer(), len)) {
        return FileUtils::Status::OK;
    }
    
    return FileUtils::Status::ReadFailed;
}

NS_CCLUA_END
