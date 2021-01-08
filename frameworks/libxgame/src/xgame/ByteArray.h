#ifndef __XGAME_BYTEARRAY_H__
#define __XGAME_BYTEARRAY_H__

#include "xgame/runtime.h"

#include <stdio.h>
#include <stdint.h>
#include <string>

NS_XGAME_BEGIN

class ByteArray {
public:
    enum class Endian {BIG, LITTLE};
public:
    ByteArray();
    ~ByteArray();
    
    size_t getBytesAvailable() const;
    
    size_t getLength() const;
    void setLength(size_t value);
    
    size_t getPosition() const;
    void setPosition(size_t value);
    
    Endian getEndian() const;
    void setEndian(Endian value);
    
    void clear();
    
    void compress(const std::string &algorithm);
    void uncompress(const std::string &algorithm);
    
    void deflate();
    void inflate();
    
    bool readBoolean();
    void writeBoolean(bool value);
    
    double readDouble();
    void writeDouble(double value);
    
    float readFloat();
    void writeFloat(float value);
    
    int8_t readByte();
    void writeByte(int8_t value);
    uint8_t readUByte();
    void writeUByte(uint8_t value);
    
    int16_t readShort();
    void writeShort(int16_t value);
    uint16_t readUShort();
    void writeUShort(uint16_t value);
    
    int32_t readInt();
    void writeInt(int32_t value);
    uint32_t readUInt();
    void writeUInt(uint32_t value);
    
    int64_t readInt64();
    void writeInt64(int64_t value);
    uint64_t readUInt64();
    void writeUInt64(uint64_t value);
    
    void readBytes(ByteArray *bytes, size_t offset = 0, size_t length = 0);
    void writeBytes(ByteArray *bytes, size_t offset = 0, size_t length = 0);
    
    std::string readUTF8();
    void writeUTF8(const std::string &value);
    
    std::string readUTFBytes(size_t length);
    void writeUTFBytes(const std::string &value);
    
    std::string toString();
private:
    Endian _endian = Endian::BIG;
    size_t _position = 0;
    size_t _length = 0;
    size_t _bufferSize = 0;
    const char *_buffer = nullptr;
};

NS_XGAME_END

#endif
