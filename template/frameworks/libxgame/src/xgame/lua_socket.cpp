#include "xgame/lua_socket.h"
#include "xgame/xsocket.h"
#include "xgame/xlua.h"
#include "tolua/tolua.hpp"

#include <string.h>
#include <stdlib.h>

using namespace xgame;

#define SOCKET_CLS "kernel.Socket"

static int _socket_new(lua_State *L)
{
    Socket *socket = new Socket();
    socket->init();
    toluacls_pushobj(L, socket, SOCKET_CLS);
    
    return 1;
}

static int _socket_gc(lua_State *L)
{
    Socket *self = (Socket *)toluacls_checkobj(L, 1, SOCKET_CLS);
    if (self) {
        delete self;
        *(Socket **)lua_newuserdata(L, sizeof(Socket *)) = NULL;
    }
    return 0;
}

static int _socket_connect(lua_State *L)
{
    Socket *self = (Socket *)toluacls_checkobj(L, 1, SOCKET_CLS);
    const char* host = luaL_checkstring(L, 2);
    uint16_t port = (uint16_t)luaL_checkinteger(L, 3);
    self->connect(host, port);
    return 0;
}

static int _scoket_clear(lua_State *L)
{
    Socket *self = (Socket *)toluacls_checkobj(L, 1, SOCKET_CLS);
    self->clear();
    return 0;
}

static int _socket_close(lua_State *L)
{
    Socket *self = (Socket *)toluacls_checkobj(L, 1, SOCKET_CLS);
    self->close();
    return 0;
}

static int _socket_bytes_available(lua_State *L)
{
    Socket *self = (Socket *)toluacls_checkobj(L, 1, SOCKET_CLS);
    lua_pushinteger(L, self->bytes_available());
    return 1;
}

static int _socket_get_status(lua_State *L)
{
    static const char *const status[] = {"invalid", "ioerror", "connecting",
        "connected", "disconnected"};
    Socket *self = (Socket *)toluacls_checkobj(L, 1, SOCKET_CLS);
    lua_pushstring(L, status[self->get_status()]);
    return 1;
}

static int _socket_flush(lua_State *L)
{
    Socket *self = (Socket *)toluacls_checkobj(L, 1, SOCKET_CLS);
    self->flush();
    return 0;
}

static int _socket_read_ubyte(lua_State *L)
{
    Socket *self = (Socket *)toluacls_checkobj(L, 1, SOCKET_CLS);
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
    Socket *self = (Socket *)toluacls_checkobj(L, 1, SOCKET_CLS);
    uint8_t value = (uint8_t)luaL_checkinteger(L, 2);
    self->write_ubyte(value);
    
    return 0;
}

static int _socket_read_byte(lua_State *L)
{
    Socket *self = (Socket *)toluacls_checkobj(L, 1, SOCKET_CLS);
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
    Socket *self = (Socket *)toluacls_checkobj(L, 1, SOCKET_CLS);
    int8_t value = (int8_t)luaL_checkinteger(L, 2);
    self->write_ubyte((uint8_t)value);
    
    return 0;
}


static int _socket_read_ushort(lua_State *L)
{
    Socket *self = (Socket *)toluacls_checkobj(L, 1, SOCKET_CLS);
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
    Socket *self = (Socket *)toluacls_checkobj(L, 1, SOCKET_CLS);
    uint16_t value = (uint16_t)luaL_checkinteger(L, 2);
    self->write_ushort(value);
    
    return 0;
}

static int _socket_read_short(lua_State *L)
{
    Socket *self = (Socket *)toluacls_checkobj(L, 1, SOCKET_CLS);
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
    Socket *self = (Socket *)toluacls_checkobj(L, 1, SOCKET_CLS);
    int16_t value = (int16_t)luaL_checkinteger(L, 2);
    self->write_ushort((uint16_t)value);
    
    return 0;
}


static int _socket_read_uint(lua_State *L)
{
    Socket *self = (Socket *)toluacls_checkobj(L, 1, SOCKET_CLS);
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
    Socket *self = (Socket *)toluacls_checkobj(L, 1, SOCKET_CLS);
    uint32_t value = (uint32_t)luaL_checkinteger(L, 2);
    self->write_uint(value);
    
    return 0;
}

static int _socket_read_int(lua_State *L)
{
    Socket *self = (Socket *)toluacls_checkobj(L, 1, SOCKET_CLS);
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
    Socket *self = (Socket *)toluacls_checkobj(L, 1, SOCKET_CLS);
    int32_t value = (int32_t)luaL_checkinteger(L, 2);
    self->write_uint((uint32_t)value);
    
    return 0;
}

static int _socket_read_uint64(lua_State *L)
{
    Socket *self = (Socket *)toluacls_checkobj(L, 1, SOCKET_CLS);
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
    Socket *self = (Socket *)toluacls_checkobj(L, 1, SOCKET_CLS);
    uint64_t value = (uint64_t)luaL_checkinteger(L, 2);
    self->write_uint64(value);
    
    return 0;
}

static int _socket_read_int64(lua_State *L)
{
    Socket *self = (Socket *)toluacls_checkobj(L, 1, SOCKET_CLS);
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
    Socket *self = (Socket *)toluacls_checkobj(L, 1, SOCKET_CLS);
    int64_t value = (int64_t)luaL_checkinteger(L, 2);
    self->write_uint64((uint64_t)value);
    
    return 0;
}

static int _socket_read_float(lua_State *L)
{
    Socket *self = (Socket *)toluacls_checkobj(L, 1, SOCKET_CLS);
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
    Socket *self = (Socket *)toluacls_checkobj(L, 1, SOCKET_CLS);
    float value = (float)luaL_checkinteger(L, 2);
    self->write_float(value);
    
    return 0;
}

static int _socket_read_double(lua_State *L)
{
    Socket *self = (Socket *)toluacls_checkobj(L, 1, SOCKET_CLS);
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
    Socket *self = (Socket *)toluacls_checkobj(L, 1, SOCKET_CLS);
    double value = (double)luaL_checkinteger(L, 2);
    self->write_double(value);
    
    return 0;
}

static int _socket_read_bytes(lua_State *L)
{
    Socket *self = (Socket *)toluacls_checkobj(L, 1, SOCKET_CLS);
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
    Socket *self = (Socket *)toluacls_checkobj(L, 1, SOCKET_CLS);
    size_t len;
    uint8_t *buf = (uint8_t *)luaL_checklstring(L, 2, &len);
    self->write_bytes(buf, (int)len);
    return 0;
}

LUALIB_API int luaopen_socket(lua_State *L)
{
    toluacls_class(L, "kernel.Socket", nullptr);
    toluacls_setfunc(L, "__gc", _socket_gc);
    toluacls_setfunc(L, "new", _socket_new);
    toluacls_setfunc(L, "connect", _socket_connect);
    toluacls_setfunc(L, "close", _socket_close);
    toluacls_setfunc(L, "clear", _scoket_clear);
    toluacls_setfunc(L, "flush", _socket_flush);
    toluacls_setfunc(L, "readUbyte", _socket_read_ubyte);
    toluacls_setfunc(L, "writeUbyte", _socket_write_ubyte);
    toluacls_setfunc(L, "readUshort", _socket_read_ushort);
    toluacls_setfunc(L, "writeUshort", _socket_write_ushort);
    toluacls_setfunc(L, "readUint", _socket_read_uint);
    toluacls_setfunc(L, "writeUint", _socket_write_uint);
    toluacls_setfunc(L, "readUint64", _socket_read_uint64);
    toluacls_setfunc(L, "writeUint64", _socket_write_uint64);
    toluacls_setfunc(L, "readByte", _socket_read_byte);
    toluacls_setfunc(L, "writeByte", _socket_write_byte);
    toluacls_setfunc(L, "readShort", _socket_read_short);
    toluacls_setfunc(L, "writeShort", _socket_write_short);
    toluacls_setfunc(L, "readInt", _socket_read_int);
    toluacls_setfunc(L, "writeInt", _socket_write_int);
    toluacls_setfunc(L, "readInt64", _socket_read_int64);
    toluacls_setfunc(L, "writeInt64", _socket_write_int64);
    toluacls_setfunc(L, "readFloat", _socket_read_float);
    toluacls_setfunc(L, "writeFloat", _socket_write_float);
    toluacls_setfunc(L, "readDouble", _socket_read_double);
    toluacls_setfunc(L, "writeDouble", _socket_write_double);
    toluacls_setfunc(L, "readBytes", _socket_read_bytes);
    toluacls_setfunc(L, "writeBytes", _socket_write_bytes);
    toluacls_property(L, "bytesAvailable", _socket_bytes_available, NULL);
    toluacls_property(L, "status", _socket_get_status, NULL);
    
    toluacls_createclassproxy(L);

    return 1;
}
