#include "cclua/olua-2dx.h"
#include "cclua/filesystem.h"
#include "cclua/runtime.h"

#include "cocos2d.h"

#include <unordered_map>

USING_NS_CC;
USING_NS_CCLUA;

lua_State *cclua_invokingstate = NULL;
static std::unordered_map<std::string, std::string> cclua_typemap;

OLUA_BEGIN_DECLS
extern bool olua_throw_error(const char *msg)
{
    if (cclua_invokingstate) {
        lua_State *L = cclua_invokingstate;
        cclua_invokingstate = NULL;
        luaL_error(L, msg);
    }
    return false;
}
OLUA_END_DECLS

#if COCOS2D_VERSION < 0x00040000 && defined(CCLUA_OS_WIN32)
#include "base/CCScriptSupport.h"
class AssertEngine : public ScriptEngineProtocol {
public:
    virtual int executeString(const char* codes) { return 0; }
    virtual int executeScriptFile(const char* filename) { return 0; }
    virtual int executeGlobalFunction(const char* functionName) { return 0; }
    virtual int sendEvent(ScriptEvent* evt) { return 0; }
    virtual bool parseConfig(ConfigType type, const std::string& str) { return true; }

    virtual bool handleAssert(const char *msg)
    {
        return throw_lua_error(msg);
    }
};
#else
extern bool cc_assert_script_compatible(const char *msg)
{
    return olua_throw_error(msg);
}
#endif

static int _coroutine_resume(lua_State *L)
{
    lua_pushvalue(L, 1);
    lua_insert(L, 1);
    
    lua_pushvalue(L, lua_upvalueindex(1));
    lua_insert(L, 2);
    lua_call(L, lua_gettop(L) - 2, LUA_MULTRET);
    
    if (lua_toboolean(L, 2) == 0) {
        olua_pusherrorfunc(L);
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
    lua_getglobal(L, "tostring");
    for (int i = 1; i <= n; i++) {
        lua_pushvalue(L, n + 1);
        lua_pushvalue(L, i);
        lua_pcall(L, 1, 1, 0);
        if (!lua_isstring(L, -1)) {
            luaL_error(L, "'tostring' must return a string to 'print'");
        }
        lua_replace(L, i);
    }
    
    luaL_Buffer buffer;
    luaL_buffinit(L, &buffer);
    for (int i = 1; i <= n; i++) {
        size_t l;
        const char *s = lua_tolstring(L, i, &l);
        if (i > 1) {
            luaL_addstring(&buffer, "    ");
        }
        luaL_addlstring(&buffer, s, l);
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

static int _loadfile(lua_State *L)
{
    int num = lua_gettop(L);
    int env = (!lua_isnone(L, 3) ? 3 : 0);
    
    // search cocos directories
    const char *path = lua_tostring(L, 1);
    if (!filesystem::isAbsolutePath(path)) {
        FileUtils *fileUtils = FileUtils::getInstance();
        BufferReader *reader = filesystem::getBufferReader();
        if (filesystem::exist(path) && fileUtils->getContents(path, reader) == FileUtils::Status::OK) {
            lua_pushfstring(L, "%s%s", "@", path);
            int status = luaL_loadbuffer(L, (const char *)reader->buffer(),
                (size_t)reader->size(), lua_tostring(L, -1));
            if (status == LUA_OK) {
                runtime::log("loadfile: %s", path);
                if (env != 0) {
                  lua_pushvalue(L, env);
                  if (!lua_setupvalue(L, -2, 1))
                    lua_pop(L, 1);
                }
                return 1;
            }
            lua_pop(L, 1); // pop path
        }
    }

    // call builtin loadfile
    lua_pushvalue(L, lua_upvalueindex(1));
    lua_insert(L, 1);
    lua_call(L, num, LUA_MULTRET);
    return lua_gettop(L);
}

static int _fixloadfile(lua_State *L)
{
    lua_getglobal(L, "loadfile");
    lua_pushcclosure(L, _loadfile, 1);
    lua_setglobal(L, "loadfile");
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
        luaL_traceback(L, lua_tothread(L, 1), NULL, 0);
        errstack = lua_tostring(L, -1);
    } else {
        errmsg = lua_tostring(L, 1);
    }
    
    luaL_traceback(L, L, errstack, 1);
    errstack = simplify_traceback(lua_tostring(L, -1));
    
    if (errmsg == NULL) {
        errmsg = "";
    }
    
    runtime::reportError(errmsg, errstack);
    runtime::log("--------------------LUA ERROR--------------------\n%s\n%s", errmsg, errstack);
    
    free((void *)errstack);
    
    runtime::dispatch("runtimeTraceback");
    
    return 0;
}

lua_State *cclua_new()
{
    lua_State *L = luaL_newstate();
    
    luaL_openlibs(L);
    olua_callfunc(L, _fixcoresume);
    olua_callfunc(L, _fixprint);
    olua_callfunc(L, _fixloadfile);
    olua_callfunc(L, _addsearchpath);
    olua_callfunc(L, _addlualoader);
    
    lua_pushcfunction(L, _errorfunc);
    lua_setglobal(L, "__TRACEBACK__");
    
    lua_pushboolean(L, runtime::isDebug());
    lua_setglobal(L, "DEBUG");

#if COCOS2D_VERSION < 0x00040000
#ifdef CCLUA_OS_WIN32
	ScriptEngineManager::getInstance()->setScriptEngine(new AssertEngine());
#endif
#endif
    
    return L;
}

int cclua_dofile(lua_State *L, const char *filename)
{
    int errfunc, status;
    
    olua_pusherrorfunc(L);                              // L: errfunc
    errfunc = lua_gettop(L);
    
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

static int report_gc_error(lua_State *L)
{
    luaL_error(L, "'referenceCount > 0xFFFF' maybe a error, check this obj: %s", olua_objstring(L, 1));
    return 0;
}

int cclua_ccobjgc(lua_State *L)
{
    auto obj = olua_toobj<cocos2d::Ref>(L, 1);
#ifdef COCOS2D_DEBUG
    if (obj->getReferenceCount() > 0xFFFF) {
        int top = lua_gettop(L);
        olua_pusherrorfunc(L);
        lua_pushcfunction(L, report_gc_error);
        lua_pushvalue(L, 1);
        lua_pcall(L, 1, 0, top + 1);
        lua_settop(L, top);
    }
#endif
    if (olua_isdebug(L)) {
        int top = lua_gettop(L);
        lua_getfield(L, 1, "name");
        const char *name = lua_tostring(L, -1);
        const char *str = olua_objstring(L, 1);
        cclua::runtime::log("lua gc: %s(NAME=%s, RC=%d, TC=%d)", str,
            name && strlen(name) > 0 ? name : "''",
            (int)obj->getReferenceCount() - 1, (int)olua_objcount(L));
        lua_settop(L, top);
    }
    
    obj->release();
    olua_setrawobj(L, 1, nullptr);
    lua_pushnil(L);
    lua_setuservalue(L, 1);
    return 0;
}

#ifdef OLUA_HAVE_MAINTHREAD
OLUA_API lua_State *olua_mainthread(lua_State *L)
{
    return runtime::luaVM();
}
#endif

#ifdef OLUA_HAVE_CHECKHOSTTHREAD
OLUA_API void olua_checkhostthread()
{
    assert(cclua::runtime::isCocosThread() && "callback should run on cocos thread");
}
#endif

#ifdef OLUA_HAVE_CMPREF
OLUA_API void olua_startcmpref(lua_State *L, int idx, const char *refname)
{
    if (olua_loadref(L, idx, refname) == LUA_TTABLE) {
        lua_pushnil(L);
        while (lua_next(L, -2)) {
            if (olua_isa<cocos2d::Ref>(L, -2)) {
                auto obj = olua_toobj<cocos2d::Ref>(L, -2);
                lua_pushvalue(L, -2);
                lua_pushinteger(L, obj->getReferenceCount());
                lua_rawset(L, -5);
            }
            lua_pop(L, 1);
        }
    }
    lua_pop(L, 1);
}

static bool should_delref(lua_State *L, int idx)
{
    if (olua_isa<cocos2d::Ref>(L, idx)) {
        auto obj = olua_toobj<cocos2d::Ref>(L, idx);
        if (olua_isinteger(L, -1)) {
            unsigned int last = (unsigned int)olua_tointeger(L, -1);
            unsigned int curr = obj->getReferenceCount();
            if (curr < last || curr == 1) {
                return true;
            }
        }
        
        if (olua_isa<cocos2d::Action>(L, idx)) {
            auto action = olua_toobj<cocos2d::Action>(L, idx);
            if (!action->getTarget() || action->isDone()) {
                return true;
            }
        }
    }
    return false;
}

OLUA_API void olua_endcmpref(lua_State *L, int idx, const char *refname)
{
    olua_visitrefs(L, idx, refname, should_delref);
}
#endif

#ifdef OLUA_HAVE_LUATYPE
OLUA_API void olua_registerluatype(lua_State *L, const char *type, const char *cls)
{
    cclua_typemap[type] = cls;
}

OLUA_API const char *olua_getluatype(lua_State *L, const char *type)
{
    auto cls = cclua_typemap.find(type);
    return cls != cclua_typemap.end() ? cls->second.c_str() : nullptr;
}
#endif
