#include "xgame/xlua.h"
#include "xgame/runtime.h"
#include "xgame/filesystem.h"
#include "olua/olua.hpp"

#include "cocos2d.h"

#include <unordered_map>

USING_NS_CC;
USING_NS_XGAME;

lua_State *xlua_invokingstate = NULL;
static std::unordered_map<std::string, std::string> xlua_typemap;

extern bool CC_DLL cc_assert_script_compatible(const char *msg)
{
	if (xlua_invokingstate) {
		lua_State *L = xlua_invokingstate;
		xlua_invokingstate = NULL;
		luaL_error(L, msg);
	}
	return false;
}

static int _coroutine_resume(lua_State *L)
{
    lua_pushvalue(L, 1);
    lua_insert(L, 1);
    
    lua_pushvalue(L, lua_upvalueindex(1));
    lua_insert(L, 2);
    lua_call(L, lua_gettop(L) - 2, LUA_MULTRET);
    
    if (lua_toboolean(L, 2) == 0) {
        olua_geterrorfunc(L);
        lua_pushvalue(L, 1);
        lua_pushvalue(L, 3);
        lua_pcall(L, 2, 0, 0);
    }
    
    return lua_gettop(L) - 1;
}

static int _fixcoresume(lua_State *L)
{
    lua_getglobal(L, LUA_COLIBNAME);
    lua_getfield(L, -1, "resume");
    lua_pushcclosure(L, _coroutine_resume, 1);
    lua_setfield(L, -2, "resume");
    lua_pop(L, 1);
    return 0;
}

static int _print(lua_State *L)
{
    int n = lua_gettop(L);
    luaL_Buffer buffer;
    lua_getglobal(L, "tostring");
    luaL_buffinit(L, &buffer);
    for (int i = 1; i <= n; i++) {
        const char *s;
        size_t l;
        lua_pushvalue(L, n + 1);
        lua_pushvalue(L, i);
        lua_pcall(L, 1, 1, 0);
        s = lua_tolstring(L, -1, &l);
        
        if (olua_testudata(L, -2, "LUABOX")) {
            lua_insert(L, -2);
        }
        
        if (s == NULL) {
            return luaL_error(L, "'tostring' must return a string to 'print'");
        }
        
        if (i > 1) {
            luaL_addstring(&buffer, "\t");
        }
        
        luaL_addlstring(&buffer, s, l);
        
        if (olua_testudata(L, -1, "LUABOX")) {
            lua_remove(L, -2);
        } else {
            lua_pop(L, 1);  /* pop str */
        }
    }
    luaL_pushresult(&buffer);
    
    runtime::log("%s", lua_tostring(L, -1));
    
    return 0;
}

static int _fixprint(lua_State *L)
{
    lua_pushcfunction(L, _print);
    lua_setglobal(L, "print");
    return 0;
}

static int _addsearchpath(lua_State *L)
{
    lua_getglobal(L, LUA_LOADLIBNAME);
    lua_getfield(L, -1, "path");
    const char *path = lua_tostring(L, -1);
    lua_pushfstring(L, "src/?.lua;?.lua;%s", path);
    lua_setfield(L, -3, "path");
    lua_pop(L, 2);
    return 0;
}

static const char *_pushnexttemplate (lua_State *L, const char *path) {
    const char *l;
    while (*path == ';') path++;
    if (*path == '\0') {
        return NULL;
    }
    l = strchr(path, ';');
    if (l == NULL) {
        l = path + strlen(path);
    }
    lua_pushlstring(L, path, l - path);
    return l;
}

static int _loader (lua_State *L)
{
    runtime::log("require \"%s\"", luaL_checkstring(L, 1));
    lua_getglobal(L, LUA_LOADLIBNAME);
    lua_getfield(L, -1, "path");
    
    const char *search_path = luaL_checkstring(L, -1);
    const char *name = luaL_gsub(L, luaL_checkstring(L, 1), ".", LUA_DIRSEP);
    
    lua_pushnil(L); // not found will return nil
    
    while ((search_path = _pushnexttemplate(L, search_path)) != nullptr) {
        const char *path = luaL_gsub(L, lua_tostring(L, -1), "?", name);
        FileUtils *fileUtils = FileUtils::getInstance();
        BufferReader *reader = filesystem::getBufferReader();
        if (filesystem::exist(path) && fileUtils->getContents(path, reader) == FileUtils::Status::OK) {
            lua_pushfstring(L, "%s%s", "@", path);
            int status = luaL_loadbuffer(L, (const char *)reader->buffer(),
                (size_t)reader->size(), lua_tostring(L, -1));
            if (status != LUA_OK) {
                return luaL_error(L, "error loading module '%s' from file '%s':\n\t%s",
                    lua_tostring(L, 1), path, lua_tostring(L, -1));
            }
            lua_pushstring(L, path);
            return 2;
        } else {
            lua_pop(L, 2); // path template, filename
        }
    }
    return 1;
}

static int _addlualoader(lua_State *L)
{
    lua_getglobal(L, LUA_LOADLIBNAME);                          // L: package
    lua_getfield(L, -1, LUA_LOADER_TABLE);                      // L: package, searchers
    
    for (int i = (int)(lua_rawlen(L, - 1) + 1); i > 2; i--) {
        lua_rawgeti(L, -1, i - 1);                              // L: package, searchers func
        lua_rawseti(L, -2, i);                                  // L: package, searchers
    }
    
    lua_pushcfunction(L, _loader);                              // L: package, searchers, func
    lua_rawseti(L, -2, 2);                                      // L: package, searchers
    
    return 0;
}

static char *simplify_traceback(const char *msg)
{
    const char *FUNCSTR = ": in function '";
    size_t len = strlen(msg);
    size_t funclen = strlen(FUNCSTR);
    int count = 0;
    char *buffer = (char *)malloc(len + 1);
    const char *end = msg + len;
    while (msg < end) {
        const char *funcstart = strstr(msg, FUNCSTR);
        if (funcstart) {
            funcstart += funclen;
            memcpy(buffer + count, msg, funcstart - msg);
            count += funcstart - msg;
            msg = funcstart;
            
            const char *funcend = strchr(msg, '\'');
            if (funcend) {
                funcend++;
                const char *dotstart = msg;
                while (dotstart < funcend) {
                    if (*dotstart++ == '.')
                        msg = dotstart;
                }
                memcpy(buffer + count, msg, funcend - msg);
                count += funcend - msg;
                msg = funcend;
            } else {
                break;
            }
        } else {
            break;
        }
    }
    
    if (msg < end) {
        memcpy(buffer + count, msg, end - msg);
        count += end - msg;
    }
    
    buffer[count] = '\0';
    
    return buffer;
}

static int _errorfunc(lua_State *L)
{
    const char *errmsg = NULL;
    const char *errstack = NULL;
    
    if (olua_isthread(L, 1)) {
        errmsg = luaL_optstring(L, 2, "");
        olua_traceback(L, lua_tothread(L, 1), NULL, 0);
        errstack = lua_tostring(L, -1);
    } else {
        errmsg = lua_tostring(L, 1);
    }
    
    olua_traceback(L, L, errstack, 1);
    errstack = simplify_traceback(lua_tostring(L, -1));
    
    if (errmsg == NULL) {
        errmsg = "";
    }
    
    runtime::reportError(errmsg, errstack);
    runtime::log("--------------------LUA ERROR--------------------\n%s\n%s", errmsg, errstack);
    
    free((void *)errstack);
    
    return 0;
}

lua_State *xlua_new()
{
    lua_State *L = luaL_newstate();
    luaL_openlibs(L);
    olua_dofunc(L, _fixcoresume);
    olua_dofunc(L, _fixprint);
    olua_dofunc(L, _addsearchpath);
    olua_dofunc(L, _addlualoader);
    
    lua_pushcfunction(L, _errorfunc);
    lua_setglobal(L, "__TRACEBACK__");
    
    lua_pushboolean(L, runtime::isDebug());
    lua_setglobal(L, "DEBUG");

    
    return L;
}

int xlua_dofile(lua_State *L, const char *filename)
{
    int errfunc, status;
    
    errfunc = olua_geterrorfunc(L);                     // L: errfunc
    
    luaL_gsub(L, filename, ".lua", "");                 // L: errfunc "xxx.xxxx"
    luaL_gsub(L, lua_tostring(L, -1), "/", ".");        // L: errfunc "xxx.xxxx" "xxx/xxxx"
    lua_remove(L, -2);                                  // L: errfunc "xxx/xxxx"
    
    lua_pushcfunction(L, _loader);                      // L: errfunc "xxx/xxxx" _loader
    lua_pushvalue(L, -2);                               // L: errfunc "xxx/xxxx" _loader "xxx/xxxx"
    
    status = lua_pcall(L, 1, LUA_MULTRET, errfunc);     // L: errfunc "xxx/xxxx" func filename
    lua_remove(L, errfunc + 1);                         // L: errfunc func filename
    
    if (status == LUA_OK) {
        if (olua_isfunction(L, errfunc + 1)) {
            status = lua_pcall(L, 1, LUA_MULTRET, errfunc);
            lua_remove(L, errfunc);
        } else {
            status = LUA_ERRFILE;
            lua_settop(L, errfunc - 1);
            runtime::log("[NO] do file: no such file '%s'", filename);
        }
    } else {
        lua_settop(L, errfunc - 1);
        runtime::log("do file error: '%s'", filename);
    }
    
    return status;
}

static int _nonsupport_func(lua_State *L)
{
    lua_settop(L, 0);
    lua_pushvalue(L, lua_upvalueindex(1));
    lua_pushvalue(L, lua_upvalueindex(2));
    lua_getfield(L, 1, "__name");
    xgame::runtime::log("function '%s.%s' not supported on '%s'",
        lua_tostring(L, -1), lua_tostring(L, 2), xgame::runtime::getOS().c_str());
    return 0;
}

static int _nonsupport_index(lua_State *L)
{
    lua_pushvalue(L, 1);
    lua_pushvalue(L, 2);
    lua_pushcclosure(L, _nonsupport_func, 2);
    return 1;
}

int xlua_nonsupport(lua_State *L)
{
    lua_settop(L, 1);
    const char *name = lua_tostring(L, 1);
    
    lua_newtable(L);
    lua_pushstring(L, name);
    lua_setfield(L, -2, "__name");
    
    lua_pushcfunction(L, _nonsupport_index);
    lua_setfield(L, -2, "__index");
    
    lua_pushvalue(L, -1);
    lua_setmetatable(L, -2);
    
    return 1;
}

static int report_gc_error(lua_State *L)
{
    luaL_error(L, "'referenceCount > 0xFFFF' maybe a error, check this obj: %s", olua_objstring(L, 1));
    return 0;
}

int xlua_ccobjgc(lua_State *L)
{
    auto obj = olua_toobj<cocos2d::Ref>(L, 1);
#ifdef COCOS2D_DEBUG
    if (obj->getReferenceCount() > 0xFFFF) {
        int errfuc = olua_geterrorfunc(L);
        lua_pushcfunction(L, report_gc_error);
        lua_pushvalue(L, 1);
        lua_pcall(L, 1, 0, errfuc);
    }
#endif
    if (olua_vmstatus(L)->debug) {
        int top = lua_gettop(L);
        lua_getfield(L, 1, "name");
        const char *name = lua_tostring(L, -1);
        const char *str = olua_objstring(L, 1);
        xgame::runtime::log("lua gc: %s(NAME=%s, RC=%d, TC=%d)", str,
            name && strlen(name) > 0 ? name : "''",
            obj->getReferenceCount() - 1, olua_objcount(L) - 1);
        lua_settop(L, top);
    }
    
    obj->release();
    olua_setrawobj(L, 1, nullptr);
    lua_pushnil(L);
    lua_setuservalue(L, 1);
    olua_subobjcount(L);
    return 0;
}

lua_State *xlua_mainthread(lua_State *L)
{
    return L ? olua_vmstatus(L)->mainthread : runtime::luaVM();
}

void xlua_startcmpdelref(lua_State *L, int idx, const char *refname)
{
    olua_getreftable(L, idx, refname);                      // L: t
    lua_pushnil(L);                                         // L: t k
    while (lua_next(L, -2)) {                               // L: t k v
        if (olua_isa<cocos2d::Ref>(L, -2)) {
            auto obj = olua_toobj<cocos2d::Ref>(L, -2);
            if (obj) {
                lua_pushvalue(L, -2);                        // L: t k v k
                lua_pushinteger(L, obj->getReferenceCount());// L: t k v k refcount
                lua_rawset(L, -5);                           // L: t k v
            }
        }
        lua_pop(L, 1);                                      // L: t k
    }                                                       // L: t
    lua_pop(L, 1);
}

static bool should_delref(lua_State *L, int idx)
{
    if (olua_isa<cocos2d::Ref>(L, idx)) {
        auto obj = olua_toobj<cocos2d::Ref>(L, idx);
        if (obj && olua_isinteger(L, -1)) {
            unsigned int last = (unsigned int)olua_tointeger(L, -1);
            unsigned int curr = obj->getReferenceCount();
            if (curr < last || curr == 1) {
                return true;
            }
        }
    } else {
        return false;
    }
    
    if (olua_isa<cocos2d::Action>(L, idx)) {
        auto obj = olua_toobj<cocos2d::Action>(L, idx);
        if (obj && (!obj->getTarget() || obj->isDone())) {
            return true;
        }
    }
    return false;
}

void xlua_endcmpdelref(lua_State *L, int idx, const char *refname)
{
    olua_visitrefs(L, idx, refname, should_delref);
}

void xlua_registerluatype(lua_State *L, const char *type, const char *cls)
{
    xlua_typemap[type] = cls;
}

const char *xlua_getluatype(lua_State *L, const char *type)
{
    auto cls = xlua_typemap.find(type);
    return cls != xlua_typemap.end() ? cls->second.c_str() : nullptr;
}
