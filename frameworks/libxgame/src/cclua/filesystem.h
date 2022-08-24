#ifndef __CCLUA_FILESYSTEM_H__
#define __CCLUA_FILESYSTEM_H__

#include "cclua/runtime.h"
#include "base/CCData.h"
#include "platform/CCFileUtils.h"

#include <string>

NS_CCLUA_BEGIN

class BufferReader : public cocos2d::ResizableBuffer
{
public:
    BufferReader();
    virtual ~BufferReader();
    virtual void resize(size_t size);
    virtual void* buffer() const { return _data; }
    size_t size() const { return _size; }
private:
    size_t _capacity;
    size_t _size;
    unsigned char *_data;
};

class filesystem {
public:
#if defined(CCLUA_OS_WIN32) || defined(CCLUA_OS_MAC)
    static std::string getAppDataDirectory();
#endif
    
    static BufferReader *getBufferReader() { return &s_reader; }
    
    static std::string getWritablePath();
    static std::string getCacheDirectory();
    static std::string getDocumentDirectory();
    static std::string getTmpDirectory();
    static std::string getBuiltinCacheDirectory(); // for cache builtin audio

    // android only
    static std::string getSDCardDirectory();
    static std::string getDirectory(const std::string &type);

    static void addSearchPath(const std::string &path, bool front = false);
    static std::string trimPath(const std::string &path, size_t limit = 60); // for log
    static std::string fullPath(const std::string &path);
    static bool createDirectory(const std::string &path, bool isFilePath = false);
    static bool remove(const std::string &path);
    static bool exist(const std::string &path);
    static bool isFile(const std::string &path);
    static bool isDirectory(const std::string &path);
    static bool isAbsolutePath(const std::string& path);
    static bool rename(const std::string &oldPath, const std::string &newPath);
    static bool copy(const std::string &srcPath, const std::string &destPath);
    static bool write(const std::string &path, const char *data, size_t len);
    static bool write(const std::string &path, const cocos2d::Data &data);
    static cocos2d::Data read(const std::string &path);
    static bool unzip(const std::string &path, const std::string &dest);
    
private:
    static BufferReader s_reader;
};

NS_CCLUA_END

#endif
