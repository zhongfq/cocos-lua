//
// $id: lua_socket.cpp O $
//

#include "lua_socket.h"
#include "socket.h"

#include <string.h>
#include <stdlib.h>

using namespace xgame;

#define luaext_touserdata(L, idx, type) (*(type*)lua_touserdata(L, idx))

static int _socket_new(lua_State *L)
{
    Socket *socket = new Socket();
    socket->init();
    *(Socket **)lua_newuserdata(L, sizeof(Socket *)) = socket;
    lua_pushvalue(L, lua_upvalueindex(1));
    lua_setmetatable(L, -2);
    
    return 1;
}

static int _socket_gc(lua_State *L)
{
    Socket *self = luaext_touserdata(L, 1, Socket *);
    if (self)
    {
        delete self;
        *(Socket **)lua_newuserdata(L, sizeof(Socket *)) = NULL;
    }
    return 0;
}

static int _socket_connect(lua_State *L)
{
    Socket *self = luaext_touserdata(L, 1, Socket *);
    const char* host = luaL_checkstring(L, 2);
    uint16_t port = (uint16_t)luaL_checkinteger(L, 3);
    self->connect(host, port);
    return 0;
}

static int _scoket_clear(lua_State *L)
{
    Socket *self = luaext_touserdata(L, 1, Socket *);
    self->clear();
    return 0;
}

static int _socket_close(lua_State *L)
{
    Socket *self = luaext_touserdata(L, 1, Socket *);
    self->close();
    return 0;
}

static int _socket_bytes_available(lua_State *L)
{
    Socket *self = luaext_touserdata(L, 1, Socket *);
    lua_pushinteger(L, self->bytes_available());
    return 1;
}

static int _socket_get_status(lua_State *L)
{
    static const char *const status[] = {"invalid", "ioerror", "connecting",
        "connected", "disconnected"};
    Socket *self = luaext_touserdata(L, 1, Socket *);
    lua_pushstring(L, status[self->get_status()]);
    return 1;
}

static int _socket_flush(lua_State *L)
{
    Socket *self = luaext_touserdata(L, 1, Socket *);
    self->flush();
    return 0;
}

static int _socket_ipaddr(lua_State *L)
{
    Socket *self = luaext_touserdata(L, 1, Socket *);
    lua_pushstring(L, self->ipaddr());
    return 1;
}

static int _socket_read_ubyte(lua_State *L)
{
    Socket *self = luaext_touserdata(L, 1, Socket *);
    uint8_t value;
    if (self->read_ubyte(&value))
        lua_pushinteger(L, value);
    else
        luaL_error(L, "not enough");
    
    return 1;
}

static int _socket_write_ubyte(lua_State *L)
{
    Socket *self = luaext_touserdata(L, 1, Socket *);
    uint8_t value = (uint8_t)luaL_checkinteger(L, 2);
    self->write_ubyte(value);
    
    return 0;
}

static int _socket_read_byte(lua_State *L)
{
    Socket *self = luaext_touserdata(L, 1, Socket *);
    uint8_t value;
    if (self->read_ubyte(&value))
        lua_pushinteger(L, (int8_t)value);
    else
        luaL_error(L, "not enough");
    
    return 1;
}

static int _socket_write_byte(lua_State *L)
{
    Socket *self = luaext_touserdata(L, 1, Socket *);
    int8_t value = (int8_t)luaL_checkinteger(L, 2);
    self->write_ubyte((uint8_t)value);
    
    return 0;
}


static int _socket_read_ushort(lua_State *L)
{
    Socket *self = luaext_touserdata(L, 1, Socket *);
    uint16_t value;
    if (self->read_ushort(&value))
        lua_pushinteger(L, value);
    else
        luaL_error(L, "not enough");
    
    return 1;
}

static int _socket_write_ushort(lua_State *L)
{
    Socket *self = luaext_touserdata(L, 1, Socket *);
    uint16_t value = (uint16_t)luaL_checkinteger(L, 2);
    self->write_ushort(value);
    
    return 0;
}

static int _socket_read_short(lua_State *L)
{
    Socket *self = luaext_touserdata(L, 1, Socket *);
    uint16_t value;
    if (self->read_ushort(&value))
        lua_pushinteger(L, (int16_t)value);
    else
        luaL_error(L, "not enough");
    
    return 1;
}

static int _socket_write_short(lua_State *L)
{
    Socket *self = luaext_touserdata(L, 1, Socket *);
    int16_t value = (int16_t)luaL_checkinteger(L, 2);
    self->write_ushort((uint16_t)value);
    
    return 0;
}


static int _socket_read_uint(lua_State *L)
{
    Socket *self = luaext_touserdata(L, 1, Socket *);
    uint32_t value;
    if (self->read_uint(&value))
        lua_pushinteger(L, value);
    else
        luaL_error(L, "not enough");
    
    return 1;
}

static int _socket_write_uint(lua_State *L)
{
    Socket *self = luaext_touserdata(L, 1, Socket *);
    uint32_t value = (uint32_t)luaL_checkinteger(L, 2);
    self->write_uint(value);
    
    return 0;
}

static int _socket_read_int(lua_State *L)
{
    Socket *self = luaext_touserdata(L, 1, Socket *);
    uint32_t value;
    if (self->read_uint(&value))
        lua_pushinteger(L, (int32_t)value);
    else
        luaL_error(L, "not enough");
    
    return 1;
}

static int _socket_write_int(lua_State *L)
{
    Socket *self = luaext_touserdata(L, 1, Socket *);
    int32_t value = (int32_t)luaL_checkinteger(L, 2);
    self->write_uint((uint32_t)value);
    
    return 0;
}

static int _socket_read_uint64(lua_State *L)
{
    Socket *self = luaext_touserdata(L, 1, Socket *);
    uint64_t value;
    if (self->read_uint64(&value))
        lua_pushinteger(L, value);
    else
        luaL_error(L, "not enough");
    
    return 1;
}

static int _socket_write_uint64(lua_State *L)
{
    Socket *self = luaext_touserdata(L, 1, Socket *);
    uint64_t value = (uint64_t)luaL_checkinteger(L, 2);
    self->write_uint64(value);
    
    return 0;
}

static int _socket_read_int64(lua_State *L)
{
    Socket *self = luaext_touserdata(L, 1, Socket *);
    uint64_t value;
    if (self->read_uint64(&value))
        lua_pushinteger(L, (int64_t)value);
    else
        luaL_error(L, "not enough");
    
    return 1;
}

static int _socket_write_int64(lua_State *L)
{
    Socket *self = luaext_touserdata(L, 1, Socket *);
    int64_t value = (int64_t)luaL_checkinteger(L, 2);
    self->write_uint64((uint64_t)value);
    
    return 0;
}

static int _socket_read_float(lua_State *L)
{
    Socket *self = luaext_touserdata(L, 1, Socket *);
    float value;
    if (self->read_float(&value))
        lua_pushnumber(L, value);
    else
        luaL_error(L, "not enough");
    
    return 1;
}

static int _socket_write_float(lua_State *L)
{
    Socket *self = luaext_touserdata(L, 1, Socket *);
    float value = (float)luaL_checkinteger(L, 2);
    self->write_float(value);
    
    return 0;
}

static int _socket_read_double(lua_State *L)
{
    Socket *self = luaext_touserdata(L, 1, Socket *);
    double value;
    if (self->read_double(&value))
        lua_pushnumber(L, value);
    else
        luaL_error(L, "not enough");
    
    return 1;
}

static int _socket_write_double(lua_State *L)
{
    Socket *self = luaext_touserdata(L, 1, Socket *);
    double value = (double)luaL_checkinteger(L, 2);
    self->write_double(value);
    
    return 0;
}

static int _socket_read_bytes(lua_State *L)
{
    Socket *self = luaext_touserdata(L, 1, Socket *);
    int len = (int)luaL_checkinteger(L, 2);
    if (len <= 0)
    {
        luaL_error(L, "len = %d", len);
    }
    
    uint8_t *buf = (uint8_t *)malloc(len);
    if (self->read_bytes(buf, len))
    {
        lua_pushlstring(L, (const char *)buf, len);
        free(buf);
    }
    else
    {
        free(buf);
        luaL_error(L, "not enough");
    }
    
    return 1;
}

static int _socket_write_bytes(lua_State *L)
{
    Socket *self = luaext_touserdata(L, 1, Socket *);
    size_t len;
    uint8_t *buf = (uint8_t *)luaL_checklstring(L, 2, &len);
    self->write_bytes(buf, (int)len);
    return 0;
}

static const luaL_Reg lib[] = {
    {"__gc", _socket_gc},
    {"connect", _socket_connect},
    {"close", _socket_close},
    {"clear", _scoket_clear},
    {"bytes_available", _socket_bytes_available},
    {"status", _socket_get_status},
    {"flush", _socket_flush},
    {"ipaddr", _socket_ipaddr},
    {"read_ubyte", _socket_read_ubyte},
    {"write_ubyte", _socket_write_ubyte},
    {"read_ushort", _socket_read_ushort},
    {"write_ushort", _socket_write_ushort},
    {"read_uint", _socket_read_uint},
    {"write_uint", _socket_write_uint},
    {"read_uint64", _socket_read_uint64},
    {"write_uint64", _socket_write_uint64},
    {"read_byte", _socket_read_byte},
    {"write_byte", _socket_write_byte},
    {"read_short", _socket_read_short},
    {"write_short", _socket_write_short},
    {"read_int", _socket_read_int},
    {"write_int", _socket_write_int},
    {"read_int64", _socket_read_int64},
    {"write_int64", _socket_write_int64},
    {"read_float", _socket_read_float},
    {"write_float", _socket_write_float},
    {"read_double", _socket_read_double},
    {"write_double", _socket_write_double},
    {"read_bytes", _socket_read_bytes},
    {"write_bytes", _socket_write_bytes},
    {NULL, NULL},
};

LUALIB_API int luaopen_socket(lua_State *L)
{
    luaL_newlib(L, lib);
    lua_pushvalue(L, -1);
    lua_setfield(L, -2, "__index");
    
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, _socket_new, 1);
    lua_setfield(L, -2, "new");

    return 1;
}
