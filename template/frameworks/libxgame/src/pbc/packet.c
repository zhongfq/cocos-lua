//
// $id: packet.c zhongfq $
//

#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "lua.h"
#include "lauxlib.h"

#define LUA_PACKETHANDLE "packet_t*"

#define check_packet() ((packet_t *)luaL_checkudata(L, 1, LUA_PACKETHANDLE))

typedef struct {
    int owner;
    unsigned char *data;
    unsigned char *pos;
    unsigned char *end;
} packet_t;

static int _new(lua_State *L)
{
    lua_settop(L, 3);
    packet_t *self = (packet_t *)lua_newuserdata(L, sizeof(*self));
    size_t len = (size_t)luaL_checkinteger(L, 1);
    
    if (lua_isuserdata(L, 2)) {
        self->owner = lua_toboolean(L, 3);
        self->data = (unsigned char *)lua_touserdata(L, 2);
    } else {
        self->data = (unsigned char *)malloc(len);
        self->owner = 1;
    }
    
    self->pos = self->data;
    self->end = self->data + len;
    
    luaL_setmetatable(L, LUA_PACKETHANDLE);
    
    return 1;
}

static int _gc(lua_State *L)
{
    packet_t *self = check_packet();
    if (self->owner && self->data) {
        free(self->data);
        self->data = NULL;
        self->end = NULL;
        self->pos = NULL;
    }
    return 0;
}

static int _length(lua_State *L)
{
    packet_t *self = check_packet();
    lua_pushinteger(L, self->pos - self->data);
    return 1;
}

static packet_t *check_read_packet(lua_State *L, size_t size)
{
    packet_t *self = check_packet();
    
    if (!(self->data && self->end - self->pos >= size))
        luaL_error(L, "no more data");
    
    return self;
}

static packet_t *check_write_packet(lua_State *L, size_t size)
{
    packet_t *self = check_packet();
    
    if (!(self->data && self->owner && self->end - self->pos >= 1))
        luaL_error(L, "no more data, owner=%d", self->owner);
    
    return self;
}

static uint64_t _read_value(packet_t *self, size_t num)
{
    uint64_t value = 0;
    
    if (num == 1) {
        value = (uint8_t)*self->pos++;
    } else if (num == 2) {
        value |= ((uint16_t)*self->pos++) << 8;
        value |= ((uint16_t)*self->pos++);
    } else if (num == 4) {
        value |= ((uint32_t)*self->pos++) << 24;
        value |= ((uint32_t)*self->pos++) << 16;
        value |= ((uint32_t)*self->pos++) << 8;
        value |= ((uint32_t)*self->pos++);
    } else if (num == 8) {
        value |= ((uint64_t)*self->pos++) << 56;
        value |= ((uint64_t)*self->pos++) << 48;
        value |= ((uint64_t)*self->pos++) << 40;
        value |= ((uint64_t)*self->pos++) << 32;
        value |= ((uint64_t)*self->pos++) << 24;
        value |= ((uint64_t)*self->pos++) << 16;
        value |= ((uint64_t)*self->pos++) << 8;
        value |= ((uint64_t)*self->pos++);
    }
    
    return value;
}

static void _write_value(packet_t *self, uint64_t value, size_t num)
{
    if (num == 1) {
        *self->pos++ = value & 0xff;
    } else if (num == 2) {
        *self->pos++ = value >> 8 & 0xff;
        *self->pos++ = value & 0xff;
    } else if (num == 4) {
        *self->pos++ = value >> 24 & 0xff;
        *self->pos++ = value >> 16 & 0xff;
        *self->pos++ = value >> 8 & 0xff;
        *self->pos++ = value & 0xff;
    } else if (num == 8) {
        *self->pos++ = value >> 56 & 0xff;
        *self->pos++ = value >> 48 & 0xff;
        *self->pos++ = value >> 40 & 0xff;
        *self->pos++ = value >> 32 & 0xff;
        *self->pos++ = value >> 24 & 0xff;
        *self->pos++ = value >> 16 & 0xff;
        *self->pos++ = value >> 8 & 0xff;
        *self->pos++ = value & 0xff;
    }
}

static int _read_ubyte(lua_State *L)
{
    packet_t *self = check_read_packet(L, 1);
    lua_pushnumber(L, (uint8_t)_read_value(self, 1));
    return 1;
}

static int _write_ubyte(lua_State *L)
{
    lua_settop(L, 2);
    packet_t *self = check_write_packet(L, 1);
    uint8_t value = (uint8_t)luaL_checkinteger(L, 2);
    _write_value(self, value, 1);
    return 0;
}

static int _read_byte(lua_State *L)
{
    packet_t *self = check_read_packet(L, 1);
    lua_pushnumber(L, (int8_t)(uint8_t)_read_value(self, 1));
    return 1;
}

static int _write_byte(lua_State *L)
{
    lua_settop(L, 2);
    packet_t *self = check_write_packet(L, 1);
    uint8_t value = (uint8_t)luaL_checkinteger(L, 2);
    _write_value(self, value, 1);
    return 0;
}

static int _read_ushort(lua_State *L)
{
    packet_t *self = check_read_packet(L, 2);
    lua_pushnumber(L, (uint16_t)_read_value(self, 2));
    return 1;
}

static int _write_ushort(lua_State *L)
{
    lua_settop(L, 2);
    packet_t *self = check_write_packet(L, 2);
    uint16_t value = (uint16_t)luaL_checkinteger(L, 2);
    _write_value(self, value, 2);
    return 0;
}

static int _read_short(lua_State *L)
{
    packet_t *self = check_read_packet(L, 2);
    lua_pushnumber(L, (int16_t)(uint16_t)_read_value(self, 2));
    return 1;
}

static int _write_short(lua_State *L)
{
    lua_settop(L, 2);
    packet_t *self = check_write_packet(L, 2);
    uint16_t value = (uint16_t)luaL_checkinteger(L, 2);
    _write_value(self, value, 2);
    return 0;
}

static int _read_uint(lua_State *L)
{
    packet_t *self = check_read_packet(L, 4);
    lua_pushnumber(L, (uint32_t)_read_value(self, 4));
    return 1;
}

static int _write_uint(lua_State *L)
{
    lua_settop(L, 2);
    packet_t *self = check_write_packet(L, 4);
    uint32_t value = (uint32_t)luaL_checkinteger(L, 2);
    _write_value(self, value, 4);
    return 0;
}

static int _read_int(lua_State *L)
{
    packet_t *self = check_read_packet(L, 4);
    lua_pushnumber(L, (int32_t)(uint32_t)_read_value(self, 4));
    return 1;
}

static int _write_int(lua_State *L)
{
    lua_settop(L, 2);
    packet_t *self = check_write_packet(L, 4);
    uint32_t value = (uint32_t)luaL_checkinteger(L, 2);
    _write_value(self, value, 4);
    return 1;
}

static int _read_uint64(lua_State *L)
{
    packet_t *self = check_read_packet(L, 8);
    lua_pushnumber(L, (uint64_t)_read_value(self, 8));
    return 1;
}

static int _write_uint64(lua_State *L)
{
    lua_settop(L, 2);
    packet_t *self = check_write_packet(L, 8);
    uint64_t value = (uint64_t)luaL_checkinteger(L, 2);
    _write_value(self, value, 8);
    return 0;
}

static int _read_int64(lua_State *L)
{
    packet_t *self = check_read_packet(L, 8);
    lua_pushnumber(L, (int64_t)(uint64_t)_read_value(self, 8));
    return 1;
}

static int _write_int64(lua_State *L)
{
    lua_settop(L, 2);
    packet_t *self = check_write_packet(L, 8);
    uint64_t value = (uint64_t)luaL_checkinteger(L, 2);
    _write_value(self, value, 8);
    return 0;
}

static int _read_float(lua_State *L)
{
    union {
        uint32_t i;
        float f;
    } u;
    u.i = (uint32_t)_read_value(check_read_packet(L, 4), 4);
    lua_pushnumber(L, u.f);
    return 1;
}

static int _write_float(lua_State *L)
{
    lua_settop(L, 2);
    union {
        uint32_t i;
        float f;
    } u;
    u.f = (float)luaL_checknumber(L, 2);
    _write_value(check_write_packet(L, 4), u.i, 4);
    return 0;
}

static int _read_double(lua_State *L)
{
    union {
        uint64_t i;
        double f;
    } u;
    u.i = (uint64_t)_read_value(check_read_packet(L, 8), 8);
    lua_pushnumber(L, u.f);
    return 1;
}

static int _write_double(lua_State *L)
{
    lua_settop(L, 2);
    union {
        uint64_t i;
        double f;
    } u;
    u.f = (double)luaL_checknumber(L, 2);
    _write_value(check_write_packet(L, 8), u.i, 8);
    return 0;
}

static int _read_bytes(lua_State *L)
{
    int len = (int)luaL_checkinteger(L, 2);
    packet_t *self = check_read_packet(L, len);
    lua_pushlightuserdata(L, self->pos);
    self->pos += len;
    return 1;
}

static int _write_bytes(lua_State *L)
{
    lua_settop(L, 3);
    size_t len;
    const void *data;
    if (lua_islightuserdata(L, 2)) {
        data = lua_touserdata(L, 2);
        len = (size_t)luaL_checkinteger(L, 3);
    } else {
        data = (void *)luaL_checklstring(L, 2, &len);
    }
    
    packet_t *self = check_write_packet(L, len);
    memcpy((void *)self->pos, data, len);
    self->pos += len;
    return 0;
}

static int _read_string(lua_State *L)
{
    int len = (int)luaL_checkinteger(L, 2);
    packet_t *self = check_read_packet(L, len);
    lua_pushlstring(L, (const char *)self->pos, len);
    self->pos += len;
    return 1;
}

static int _write_string(lua_State *L)
{
    return _write_bytes(L);
}

static int _pack(lua_State *L)
{
    packet_t *self = check_packet();
    lua_pushinteger(L, self->pos - self->data);
    lua_pushlightuserdata(L, self->data);
    self->data = NULL;
    
    return 2;
}

static int _dump(lua_State *L)
{
    static char X[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    
    packet_t *self = check_packet();
    
    luaL_Buffer b;
    luaL_buffinit(L, &b);
    unsigned char *start = self->data;
    while (start < self->end) {
        uint8_t c = (uint8_t)*start++;
        luaL_addchar(&b, X[c >> 4 & 0xF]);
        luaL_addchar(&b, X[c & 0xF]);
    }
    luaL_pushresult(&b);
    return 1;
}

static int _free(lua_State *L)
{
    luaL_checktype(L, 1, LUA_TLIGHTUSERDATA);
    void *ptr = lua_touserdata(L, 1);
    free(ptr);
    
    return 0;
}

LUALIB_API int luaopen_packet(lua_State *L)
{
    luaL_checkversion(L);
    
    luaL_Reg l[] = {
        {"new", _new},
        {"__gc", _gc},
        {"__len", _length},
        {"read_ubyte", _read_ubyte},
        {"write_ubyte", _write_ubyte},
        {"read_ushort", _read_ushort},
        {"write_ushort", _write_ushort},
        {"read_uint", _read_uint},
        {"write_uint", _write_uint},
        {"read_uint64", _read_uint64},
        {"write_uint64", _write_uint64},
        {"read_byte", _read_byte},
        {"write_byte", _write_byte},
        {"read_short", _read_short},
        {"write_short", _write_short},
        {"read_int", _read_int},
        {"write_int", _write_int},
        {"read_int64", _read_int64},
        {"write_int64", _write_int64},
        {"read_float", _read_float},
        {"write_float", _write_float},
        {"read_double", _read_double},
        {"write_double", _write_double},
        {"read_bytes", _read_bytes},
        {"write_bytes", _write_bytes},
        {"read_string", _read_string},
        {"write_string", _write_string},
        {"pack", _pack},
        {"dump", _dump},
        {"free", _free},
        {NULL, NULL},
    };
    
    luaL_newmetatable(L, LUA_PACKETHANDLE);
    luaL_setfuncs(L, l, 0);
    lua_pushvalue(L, -1);
    lua_setfield(L, -2, "__index");
    
    return 1;
}
