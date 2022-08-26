#include "lua_socket.h"
#include "cclua/Socket.h"
#include "cclua/olua-2dx.h"
#include "olua/olua.h"

#include <string.h>
#include <stdlib.h>

USING_NS_CCLUA;

#define SOCKET_CLS "cclua.Socket"

static int _socket_new(lua_State *L)
{
    Socket *socket = new Socket();
    socket->init();
    olua_pushobj(L, socket, SOCKET_CLS);
    
    return 1;
}

static int _socket_gc(lua_State *L)
{
    Socket *self = (Socket *)olua_checkobj(L, 1, SOCKET_CLS);
    if (self) {
        delete self;
        *(Socket **)lua_newuserdata(L, sizeof(Socket *)) = NULL;
    }
    return 0;
}

static int _socket_connect(lua_State *L)
{
    Socket *self = (Socket *)olua_checkobj(L, 1, SOCKET_CLS);
    const char* host = luaL_checkstring(L, 2);
    uint16_t port = (uint16_t)luaL_checkinteger(L, 3);
    self->connect(host, port);
    return 0;
}

static int _scoket_clear(lua_State *L)
{
    Socket *self = (Socket *)olua_checkobj(L, 1, SOCKET_CLS);
    self->clear();
    return 0;
}

static int _socket_close(lua_State *L)
{
    Socket *self = (Socket *)olua_checkobj(L, 1, SOCKET_CLS);
    self->close();
    return 0;
}

static int _socket_bytes_available(lua_State *L)
{
    Socket *self = (Socket *)olua_checkobj(L, 1, SOCKET_CLS);
    lua_pushinteger(L, self->bytes_available());
    return 1;
}

static int _socket_get_status(lua_State *L)
{
    static const char *const status[] = {"invalid", "ioerror", "connecting",
        "connected", "disconnected"};
    Socket *self = (Socket *)olua_checkobj(L, 1, SOCKET_CLS);
    lua_pushstring(L, status[self->get_status()]);
    return 1;
}

static int _socket_flush(lua_State *L)
{
    Socket *self = (Socket *)olua_checkobj(L, 1, SOCKET_CLS);
    self->flush();
    return 0;
}

static int _socket_read_ubyte(lua_State *L)
{
    Socket *self = (Socket *)olua_checkobj(L, 1, SOCKET_CLS);
    uint8_t value;
    if (self->read_ubyte(&value)) {
        lua_pushinteger(L, value);
    } else {
        luaL_error(L, "not enough");
    }
    
    return 1;
}

static int _socket_write_ubyte(lua_State *L)
{
    Socket *self = (Socket *)olua_checkobj(L, 1, SOCKET_CLS);
    uint8_t value = (uint8_t)luaL_checkinteger(L, 2);
    self->write_ubyte(value);
    
    return 0;
}

static int _socket_read_byte(lua_State *L)
{
    Socket *self = (Socket *)olua_checkobj(L, 1, SOCKET_CLS);
    uint8_t value;
    if (self->read_ubyte(&value)) {
        lua_pushinteger(L, (int8_t)value);
    } else {
        luaL_error(L, "not enough");
    }
    
    return 1;
}

static int _socket_write_byte(lua_State *L)
{
    Socket *self = (Socket *)olua_checkobj(L, 1, SOCKET_CLS);
    int8_t value = (int8_t)luaL_checkinteger(L, 2);
    self->write_ubyte((uint8_t)value);
    
    return 0;
}


static int _socket_read_ushort(lua_State *L)
{
    Socket *self = (Socket *)olua_checkobj(L, 1, SOCKET_CLS);
    uint16_t value;
    if (self->read_ushort(&value)) {
        lua_pushinteger(L, value);
    } else {
        luaL_error(L, "not enough");
    }
    
    return 1;
}

static int _socket_write_ushort(lua_State *L)
{
    Socket *self = (Socket *)olua_checkobj(L, 1, SOCKET_CLS);
    uint16_t value = (uint16_t)luaL_checkinteger(L, 2);
    self->write_ushort(value);
    
    return 0;
}

static int _socket_read_short(lua_State *L)
{
    Socket *self = (Socket *)olua_checkobj(L, 1, SOCKET_CLS);
    uint16_t value;
    if (self->read_ushort(&value)) {
        lua_pushinteger(L, (int16_t)value);
    } else {
        luaL_error(L, "not enough");
    }
    
    return 1;
}

static int _socket_write_short(lua_State *L)
{
    Socket *self = (Socket *)olua_checkobj(L, 1, SOCKET_CLS);
    int16_t value = (int16_t)luaL_checkinteger(L, 2);
    self->write_ushort((uint16_t)value);
    
    return 0;
}


static int _socket_read_uint(lua_State *L)
{
    Socket *self = (Socket *)olua_checkobj(L, 1, SOCKET_CLS);
    uint32_t value;
    if (self->read_uint(&value)) {
        lua_pushinteger(L, value);
    } else {
        luaL_error(L, "not enough");
    }
    
    return 1;
}

static int _socket_write_uint(lua_State *L)
{
    Socket *self = (Socket *)olua_checkobj(L, 1, SOCKET_CLS);
    uint32_t value = (uint32_t)luaL_checkinteger(L, 2);
    self->write_uint(value);
    
    return 0;
}

static int _socket_read_int(lua_State *L)
{
    Socket *self = (Socket *)olua_checkobj(L, 1, SOCKET_CLS);
    uint32_t value;
    if (self->read_uint(&value)) {
        lua_pushinteger(L, (int32_t)value);
    } else {
        luaL_error(L, "not enough");
    }
    
    return 1;
}

static int _socket_write_int(lua_State *L)
{
    Socket *self = (Socket *)olua_checkobj(L, 1, SOCKET_CLS);
    int32_t value = (int32_t)luaL_checkinteger(L, 2);
    self->write_uint((uint32_t)value);
    
    return 0;
}

static int _socket_read_uint64(lua_State *L)
{
    Socket *self = (Socket *)olua_checkobj(L, 1, SOCKET_CLS);
    uint64_t value;
    if (self->read_uint64(&value)) {
        lua_pushinteger(L, value);
    } else {
        luaL_error(L, "not enough");
    }
    
    return 1;
}

static int _socket_write_uint64(lua_State *L)
{
    Socket *self = (Socket *)olua_checkobj(L, 1, SOCKET_CLS);
    uint64_t value = (uint64_t)luaL_checkinteger(L, 2);
    self->write_uint64(value);
    
    return 0;
}

static int _socket_read_int64(lua_State *L)
{
    Socket *self = (Socket *)olua_checkobj(L, 1, SOCKET_CLS);
    uint64_t value;
    if (self->read_uint64(&value)) {
        lua_pushinteger(L, (int64_t)value);
    } else {
        luaL_error(L, "not enough");
    }
    
    return 1;
}

static int _socket_write_int64(lua_State *L)
{
    Socket *self = (Socket *)olua_checkobj(L, 1, SOCKET_CLS);
    int64_t value = (int64_t)luaL_checkinteger(L, 2);
    self->write_uint64((uint64_t)value);
    
    return 0;
}

static int _socket_read_float(lua_State *L)
{
    Socket *self = (Socket *)olua_checkobj(L, 1, SOCKET_CLS);
    float value;
    if (self->read_float(&value)) {
        lua_pushnumber(L, value);
    } else {
        luaL_error(L, "not enough");
    }
    
    return 1;
}

static int _socket_write_float(lua_State *L)
{
    Socket *self = (Socket *)olua_checkobj(L, 1, SOCKET_CLS);
    float value = (float)luaL_checkinteger(L, 2);
    self->write_float(value);
    
    return 0;
}

static int _socket_read_double(lua_State *L)
{
    Socket *self = (Socket *)olua_checkobj(L, 1, SOCKET_CLS);
    double value;
    if (self->read_double(&value)) {
        lua_pushnumber(L, value);
    } else {
        luaL_error(L, "not enough");
    }
    
    return 1;
}

static int _socket_write_double(lua_State *L)
{
    Socket *self = (Socket *)olua_checkobj(L, 1, SOCKET_CLS);
    double value = (double)luaL_checkinteger(L, 2);
    self->write_double(value);
    
    return 0;
}

static int _socket_read_bytes(lua_State *L)
{
    Socket *self = (Socket *)olua_checkobj(L, 1, SOCKET_CLS);
    int len = (int)luaL_checkinteger(L, 2);
    if (len <= 0) {
        luaL_error(L, "len = %d", len);
    }
    
    uint8_t *buf = (uint8_t *)malloc(len);
    if (self->read_bytes(buf, len)) {
        lua_pushlstring(L, (const char *)buf, len);
        free(buf);
    } else {
        free(buf);
        luaL_error(L, "not enough");
    }
    
    return 1;
}

static int _socket_write_bytes(lua_State *L)
{
    Socket *self = (Socket *)olua_checkobj(L, 1, SOCKET_CLS);
    size_t len;
    uint8_t *buf = (uint8_t *)luaL_checklstring(L, 2, &len);
    self->write_bytes(buf, (int)len);
    return 0;
}

LUALIB_API int luaopen_socket(lua_State *L)
{
    oluacls_class(L, "cclua.Socket", nullptr);
    oluacls_func(L, "__gc", _socket_gc);
    oluacls_func(L, "new", _socket_new);
    oluacls_func(L, "connect", _socket_connect);
    oluacls_func(L, "close", _socket_close);
    oluacls_func(L, "clear", _scoket_clear);
    oluacls_func(L, "flush", _socket_flush);
    oluacls_func(L, "readUbyte", _socket_read_ubyte);
    oluacls_func(L, "writeUbyte", _socket_write_ubyte);
    oluacls_func(L, "readUshort", _socket_read_ushort);
    oluacls_func(L, "writeUshort", _socket_write_ushort);
    oluacls_func(L, "readUint", _socket_read_uint);
    oluacls_func(L, "writeUint", _socket_write_uint);
    oluacls_func(L, "readUint64", _socket_read_uint64);
    oluacls_func(L, "writeUint64", _socket_write_uint64);
    oluacls_func(L, "readByte", _socket_read_byte);
    oluacls_func(L, "writeByte", _socket_write_byte);
    oluacls_func(L, "readShort", _socket_read_short);
    oluacls_func(L, "writeShort", _socket_write_short);
    oluacls_func(L, "readInt", _socket_read_int);
    oluacls_func(L, "writeInt", _socket_write_int);
    oluacls_func(L, "readInt64", _socket_read_int64);
    oluacls_func(L, "writeInt64", _socket_write_int64);
    oluacls_func(L, "readFloat", _socket_read_float);
    oluacls_func(L, "writeFloat", _socket_write_float);
    oluacls_func(L, "readDouble", _socket_read_double);
    oluacls_func(L, "writeDouble", _socket_write_double);
    oluacls_func(L, "readBytes", _socket_read_bytes);
    oluacls_func(L, "writeBytes", _socket_write_bytes);
    oluacls_prop(L, "bytesAvailable", _socket_bytes_available, NULL);
    oluacls_prop(L, "status", _socket_get_status, NULL);

    return 1;
}
