//
// $id: lua_xgame.cpp O $
//

#include "xgame/lua_xgame.h"
#include "xgame/lua_socket.h"
#include "xgame/runtime.h"
#include "xgame/luaext.h"
#include "xgame/draw_node.h"
#include "xgame/file_loader.h"
#include "xgame/javabridge.h"
#include "bugly/lua/BuglyLuaAgent.h"

#include "cocos2d.h"
#include "CCLuaValue.h"
#include "CCLuaStack.h"
#include "CCLuaEngine.h"
#include "LuaBasicConversions.h"
#include "LuaScriptHandlerMgr.h"
#include "unzip/unzip.h"

#include <stdio.h>
#include <unordered_map>

using namespace cocos2d;
using namespace xgame;

static int _draw_node_create(lua_State *L)
{
    draw_node *node = draw_node::create();
    luaext_pushcocosobj(L, node, "xgame.draw_node");
    return 1;
}

static int _draw_node_get_mask(lua_State *L)
{
    draw_node *node = (draw_node *)luaext_checkcocosobj(L, 1, "xgame.draw_node");
    node->setClippingEnabled(true);
    luaext_pushcocosobj(L, node->get_mask(), "cc.DrawNode");
    return 1;
}

static int _draw_node_clear(lua_State *L)
{
    draw_node *node = (draw_node *)luaext_checkcocosobj(L, 1, "xgame.draw_node");
    node->clear();
    return 0;
}

static int _draw_node_begin_fill(lua_State *L)
{
    draw_node *node = (draw_node *)luaext_checkcocosobj(L, 1, "xgame.draw_node");
    cocos2d::Texture2D *texture = (cocos2d::Texture2D *)luaext_checkcocosobj(L, 2, "cc.Texture2D");
    node->begin_fill(texture);
    return 0;
}

static void _draw_node_to_vertices(lua_State *L, int idx, V3F_C4B_T2F *vertex)
{
    luaL_checktype(L, idx, LUA_TTABLE);
    vertex->vertices.x = luaext_getnumber(L, idx, "x", 0);
    vertex->vertices.y = luaext_getnumber(L, idx, "y", 0);
    vertex->vertices.z = luaext_getnumber(L, idx, "z", 0);
    vertex->texCoords.u = luaext_getnumber(L, idx, "u", 0);
    vertex->texCoords.v = luaext_getnumber(L, idx, "v", 0);
    vertex->colors.r = luaext_getnumber(L, idx, "r", 0xFF);
    vertex->colors.g = luaext_getnumber(L, idx, "g", 0xFF);
    vertex->colors.b = luaext_getnumber(L, idx, "b", 0xFF);
    vertex->colors.a = luaext_getnumber(L, idx, "a", 0xFF);
}

static int _draw_node_draw_triangles(lua_State *L)
{
    draw_node *node = (draw_node *)luaext_checkcocosobj(L, 1, "xgame.draw_node");
    int vertex_count = (int)lua_rawlen(L, 2);
    V3F_C4B_T2F *vertices = (V3F_C4B_T2F *)malloc(vertex_count * sizeof(V3F_C4B_T2F));
    for (int i = 1; i <= vertex_count; i++)
    {
        lua_rawgeti(L, 2, i);
        _draw_node_to_vertices(L, -1, &vertices[i - 1]);
        lua_pop(L, 1);
    }
    
    int index_count = (int)lua_rawlen(L, 3);
    unsigned short *indices = (unsigned short *)malloc(index_count * sizeof(unsigned short));
    for (int i = 1; i <= index_count; i++)
    {
        lua_rawgeti(L, 3, i);
        indices[i - 1] = (unsigned short)luaL_checkinteger(L, -1);
        lua_pop(L, 1);
    }
    
    node->draw_triangles(vertices, vertex_count, indices, index_count);
    
    return 0;
}

static int _draw_node_end_fill(lua_State *L)
{
    draw_node *node = (draw_node *)luaext_checkcocosobj(L, 1, "xgame.draw_node");
    node->end_fill();
    return 0;
}

static int luaopen_draw_node(lua_State *L)
{
    lua_pushglobaltable(L);
    tolua_open(L);
    tolua_module(L, "xgame", 0);
    tolua_beginmodule(L, "xgame");
    
    tolua_usertype(L, "xgame.draw_node");
    tolua_cclass(L, "draw_node", "xgame.draw_node", "ccui.Layout", nullptr);
    tolua_beginmodule(L, "draw_node");
    tolua_function(L, "create", _draw_node_create);
    tolua_function(L, "get_mask", _draw_node_get_mask);
    tolua_function(L, "clear", _draw_node_clear);
    tolua_function(L, "begin_fill", _draw_node_begin_fill);
    tolua_function(L, "draw_triangles", _draw_node_draw_triangles);
    tolua_function(L, "end_fill", _draw_node_end_fill);
    
    g_luaType[typeid(draw_node).name()] = "xgame.draw_node";
    g_typeCast["draw_node"] = "xgame.draw_node";
    
    return 1;
}

static int _file_loader_gc(lua_State *L)
{
    lua_pushvalue(L, lua_upvalueindex(1));
    file_loader *loader = luaext_checkudata(L, -1, file_loader *);
    delete loader;
    return 0;
}

static int _file_loader_pop(lua_State *L)
{
    lua_pushvalue(L, lua_upvalueindex(1));
    file_loader *loader = luaext_checkudata(L, -1, file_loader *);
    const char *STATES[] = {"ioerror", "loaded", "valid", "invalid"};
    const std::vector<file_task> tasks = loader->receive();
    lua_createtable(L, (int)tasks.size(), 0);
    int index = 1;
    for (auto it = tasks.begin(); it != tasks.end(); ++it)
    {
        lua_createtable(L, 0, 3);
        lua_pushstring(L, it->url.c_str());
        lua_setfield(L, -2, "url");
        lua_pushstring(L, it->storage_path.c_str());
        lua_setfield(L, -2, "local_path");
        lua_pushstring(L, it->md5.c_str());
        lua_setfield(L, -2, "md5");
        lua_pushstring(L, STATES[it->state]);
        lua_setfield(L, -2, "state");
        lua_rawseti(L, -2, index++);
    }
    return 1;
}

static int file_loader_load(lua_State *L)
{
    lua_settop(L, 3);
    lua_pushvalue(L, lua_upvalueindex(1));
    file_loader *loader = luaext_checkudata(L, -1, file_loader *);
    file_task task;
    task.url = luaL_checkstring(L, 1);
    task.storage_path = luaL_checkstring(L, 2);
    task.md5 = luaL_checkstring(L, 3);
    loader->load(task);
    return 0;
}

static int luaopen_file_loader(lua_State *L)
{
    const luaL_Reg lib[] = {
        {"__gc", _file_loader_gc},
        {"load", file_loader_load},
        {"receive", _file_loader_pop},
        {NULL, NULL},
    };
    
    file_loader *loader = new file_loader();
    *((file_loader **)lua_newuserdata(L, sizeof(file_loader *))) = loader;
    
    luaL_newlibtable(L, lib);
    lua_pushvalue(L, -1);
    lua_setfield(L, -2, "__index");
    
    lua_pushvalue(L, -2); // file_loader
    luaL_setfuncs(L, lib, 1);
    
    lua_setmetatable(L, -2);
    
    return 1;
}

static int _filesystem_get_document_directory(lua_State *L)
{
    lua_pushstring(L, filesystem::get_document_directory().c_str());
    return 1;
}

static int _filesystem_get_cache_directory(lua_State *L)
{
    lua_pushstring(L, filesystem::get_cache_directory().c_str());
    return 1;
}

static int _filesystem_get_tmp_directory(lua_State *L)
{
    lua_pushstring(L, filesystem::get_tmp_directory().c_str());
    return 1;
}

static int _filesystem_get_writable_path(lua_State *L)
{
    lua_pushstring(L, filesystem::get_writable_path().c_str());
    return 1;
}

static int _filesystem_get_sdcard_directory(lua_State *L)
{
    lua_pushstring(L, filesystem::get_sdcard_directory().c_str());
    return 1;
}

#define BOOL_STR(b) (b ? "OK" : "NO")

static int _filesystem_create_directory(lua_State *L)
{
    lua_settop(L, 1);
    const char *path = luaL_checkstring(L, 1);
    bool status = filesystem::create_directory(path);
    lua_pushboolean(L, status);
    runtime::log("create dir[%s]: %s", BOOL_STR(status), filesystem::short_path(path).c_str());
    return 1;
}

static int _filesystem_is_directory(lua_State *L)
{
    lua_settop(L, 1);
    const char *path = luaL_checkstring(L, 1);
    lua_pushboolean(L, FileUtils::getInstance()->isDirectoryExist(path));
    return 1;
}

static int _filesystem_is_file(lua_State *L)
{
    lua_settop(L, 1);
    const char *path = luaL_checkstring(L, 1);
    lua_pushboolean(L, FileUtils::getInstance()->isFileExist(path));
    return 1;
}

static int _filesystem_list_files(lua_State *L)
{
    lua_settop(L, 2);
    const char *path = luaL_checkstring(L, 1);
    bool recursive = lua_toboolean(L, 2);
    std::vector<std::string> files;
    if (recursive)
    {
        FileUtils::getInstance()->listFilesRecursively(path, &files);
    }
    else
    {
        files = FileUtils::getInstance()->listFiles(path);
    }
    
    int size = (int)files.size();
    lua_createtable(L, size, 0);
    for (int i = 0; i < size; i++)
    {
        lua_pushstring(L, files.at(i).c_str());
        lua_rawseti(L, -2, i + 1);
    }
    
    return 1;
}

static int _filesystem_short_path(lua_State *L)
{
    lua_settop(L, 2);
    const char *path = luaL_checkstring(L, 1);
    if (!lua_isnil(L, 2)) {
        lua_pushstring(L, filesystem::short_path(path, (size_t)luaL_checkinteger(L, 2)).c_str());
    } else {
        lua_pushstring(L, filesystem::short_path(path).c_str());
    }
    return 1;
}

static int _filesystem_remove(lua_State *L)
{
    lua_settop(L, 1);
    const char *path = luaL_checkstring(L, 1);
    bool status = filesystem::remove(path);
    lua_pushboolean(L, status);
    runtime::log("[%s] remove: %s", BOOL_STR(status), filesystem::short_path(path).c_str());
    return 1;
}

static int _filesystem_rename(lua_State *L)
{
    lua_settop(L, 2);
    const char *old_path = luaL_checkstring(L, 1);
    const char *new_path = luaL_checkstring(L, 2);
    bool status = FileUtils::getInstance()->renameFile(old_path, new_path);
    lua_pushboolean(L, status);
    runtime::log("[%s] rename: %s => %s", BOOL_STR(status),
        filesystem::short_path(old_path).c_str(), filesystem::short_path(new_path).c_str());
    return 1;
}

static int _filesystem_exist(lua_State *L)
{
    lua_settop(L, 1);
    const char *path = luaL_checkstring(L, 1);
    lua_pushboolean(L, filesystem::exist(path));
    return 1;
}

static int _filesystem_write(lua_State *L)
{
    lua_settop(L, 2);
    
    size_t len;
    const char *path = luaL_checkstring(L, 1);
    const char *data = luaL_checklstring(L, 2, &len);
    
    char *dir_sep = (char *)strrchr(path, '/');
    filesystem::create_directory(std::string(path, dir_sep ? (dir_sep - path) : strlen(path)));
    
    FILE *file = fopen(path, luaL_optstring(L, 3, "w"));
    if (file != NULL)
    {
        fwrite(data, sizeof(char), len, file);
        fflush(file);
        fclose(file);
        lua_pushboolean(L, true);
        runtime::log("[OK] write file: %s", filesystem::short_path(path).c_str());
        return 1;
    }
    
    runtime::log("[NO] write file: %s", filesystem::short_path(path).c_str());
    lua_pushboolean(L, false);
    
    return 1;
}

static int _filesystem_read(lua_State *L)
{
    lua_settop(L, 1);
    const char *path = luaL_checkstring(L, 1);
    Data data = FileUtils::getInstance()->getDataFromFile(path);
    if (!data.isNull())
    {
        runtime::log("[OK] read file: %s", filesystem::short_path(path).c_str());
        lua_pushlstring(L, (const char *)data.getBytes(), (size_t)data.getSize());
        return 1;
    }
    
    lua_pushnil(L);
    runtime::log("[NO] read file: %s", filesystem::short_path(path).c_str());
    
    return 1;
}

static int _filesystem_copy(lua_State *L)
{
    lua_settop(L, 2);
    const char *src_path = luaL_checkstring(L, 1);
    const char *dest_path = luaL_checkstring(L, 2);
    
    if (!strcaseequal(src_path, dest_path))
    {
        Data data = FileUtils::getInstance()->getDataFromFile(src_path);
        if (!data.isNull())
        {
            bool status = FileUtils::getInstance()->writeDataToFile(data, dest_path);
            lua_pushboolean(L, status);
            runtime::log("copy file[%s]: %s => %s", BOOL_STR(status),
                filesystem::short_path(src_path, 40).c_str(), filesystem::short_path(dest_path, 40).c_str());
            return 1;
        }
    }
    
    lua_pushboolean(L, false);
    runtime::log("copy file[NO]: %s => %s",
        filesystem::short_path(src_path, 40).c_str(), filesystem::short_path(dest_path, 40).c_str());
    
    return 1;
}

static bool _do_unzip(lua_State *L, const char *zip_path, const char *dir)
{
    unzFile zip = unzOpen(zip_path);
    
    if (zip == nullptr)
    {
        lua_pushfstring(L, "can not open zip file: %s", filesystem::short_path(zip_path).c_str());
        return false;
    }
    
    unz_global_info global_info;
    if (unzGetGlobalInfo(zip, &global_info) != UNZ_OK)
    {
        lua_pushfstring(L, "can not get zip global info: %s", filesystem::short_path(zip_path).c_str());
        unzClose(zip);
        return false;
    }
    
    for (uLong i = 0; i < global_info.number_entry; i++)
    {
        char namebuff[FILENAME_MAX];
        unz_file_info file;
        if (unzGetCurrentFileInfo(zip, &file, namebuff, FILENAME_MAX,
                                  nullptr, 0, nullptr, 0) != UNZ_OK)
        {
            lua_pushfstring(L, "can not read file info: %s", filesystem::short_path(zip_path).c_str());
            unzClose(zip);
            return false;
        }
        
        char *dir_sep = strrchr(namebuff, '/');
        if (dir_sep != nullptr)
        {
            char dir_path[FILENAME_MAX] = {0};
            strcat(dir_path, dir);
            strncat(dir_path, namebuff, dir_sep - namebuff);

            if (!filesystem::create_directory(dir_path))
            {
                lua_pushfstring(L, "can not create dir: %s", filesystem::short_path(dir_path).c_str());
                unzClose(zip);
                return false;
            }
        }
        
        if (namebuff[file.size_filename - 1] != '/')
        {
            char fullpath[FILENAME_MAX];
            snprintf(fullpath, FILENAME_MAX, "%s/%s", dir, namebuff);
            if (unzOpenCurrentFile(zip) != UNZ_OK)
            {
                xgame::runtime::log("can open file in zip: %s %s", namebuff, zip_path);
                unzClose(zip);
                return false;
            }
            
            FILE *local_file = fopen(fullpath, "wb");
            if (local_file == nullptr)
            {
                xgame::runtime::log("cant not write file: %s", fullpath);
                unzClose(zip);
                return false;
            }
            
            int len = 0;
            char contentbuff[BUFSIZ];
            while ((len = unzReadCurrentFile(zip, contentbuff, BUFSIZ)) > 0)
            {
                fwrite(contentbuff, sizeof(char), len, local_file);
            }
            
            fclose(local_file);
            
            if (len < 0)
            {
                lua_pushfstring(L, "read file error in zip: %s %s", namebuff, zip_path);
                unzClose(zip);
                return false;
            }
            
            runtime::log("write file: %s", fullpath);
            
            unzCloseCurrentFile(zip);
        }
        
        if (i < global_info.number_entry - 1)
        {
            if (unzGoToNextFile(zip) != UNZ_OK)
            {
                lua_pushfstring(L, "can not read next file: %s", zip_path);
                unzClose(zip);
                return false;
            }
        }
    }
    
    unzClose(zip);
    
    return true;
}

static int _filesystem_unzip(lua_State *L)
{
    lua_settop(L, 2);
    const char *path = luaL_checkstring(L, 1);
    const char *dir = luaL_checkstring(L, 2);
    
    if (_do_unzip(L, path, dir))
    {
        lua_pushboolean(L, true);
        return 1;
    }
    else
    {
        lua_pushboolean(L, false);
        lua_insert(L, -2);
        return 2;
    }
}

static int luaopen_filesystem(lua_State *L)
{
    static const luaL_Reg lib[] = {
        {"get_document_directory", _filesystem_get_document_directory},
        {"get_cache_directory", _filesystem_get_cache_directory},
        {"get_tmp_directory", _filesystem_get_tmp_directory},
        {"get_writable_path", _filesystem_get_writable_path},
        {"get_sdcard_directory", _filesystem_get_sdcard_directory},
        {"create_directory", _filesystem_create_directory},
        {"is_directory", _filesystem_is_directory},
        {"is_file", _filesystem_is_file},
        {"list_files", _filesystem_list_files},
        {"short_path", _filesystem_short_path},
        {"remove", _filesystem_remove},
        {"rename", _filesystem_rename},
        {"exist", _filesystem_exist},
        {"write", _filesystem_write},
        {"read", _filesystem_read},
        {"copy", _filesystem_copy},
        {"unzip", _filesystem_unzip},
        {NULL, NULL}
    };
    
    luaL_newlib(L, lib);

    return 1;
}

static int _preferences_get_bool(lua_State *L)
{
    lua_settop(L, 1);
    lua_pushboolean(L, preferences::get_bool(luaL_checkstring(L, 1)));
    return 1;
}

static int _preferences_set_bool(lua_State *L)
{
    lua_settop(L, 2);
    preferences::set_bool(luaL_checkstring(L, 1), lua_toboolean(L, 2));
    return 0;
}

static int _preferences_get_float(lua_State *L)
{
    lua_settop(L, 2);
    lua_pushnumber(L, preferences::get_float(luaL_checkstring(L, 1), luaL_optnumber(L, 2, 0)));
    return 1;
}

static int _preferences_set_float(lua_State *L)
{
    lua_settop(L, 2);
    preferences::set_float(luaL_checkstring(L, 1), (float)luaL_checknumber(L, 2));
    return 0;
}

static int _preferences_get_double(lua_State *L)
{
    lua_settop(L, 2);
    lua_pushnumber(L, preferences::get_double(luaL_checkstring(L, 1), (double)luaL_optnumber(L, 2, 0)));
    return 1;
}

static int _preferences_set_double(lua_State *L)
{
    lua_settop(L, 2);
    preferences::set_double(luaL_checkstring(L, 1), (double)luaL_checknumber(L, 2));
    return 0;
}

static int _preferences_get_int(lua_State *L)
{
    lua_settop(L, 2);
    lua_pushinteger(L, preferences::get_int(luaL_checkstring(L, 1), (int)luaL_optinteger(L, 2, 0)));
    return 1;
}

static int _preferences_set_int(lua_State *L)
{
    lua_settop(L, 2);
    preferences::set_int(luaL_checkstring(L, 1), (int)luaL_checkinteger(L, 2));
    return 0;
}

static int _preferences_get_string(lua_State *L)
{
    lua_settop(L, 2);
    lua_pushstring(L, preferences::get_string(luaL_checkstring(L, 1), luaL_optstring(L, 2, "")).c_str());
    return 1;
}

static int _preferences_set_string(lua_State *L)
{
    lua_settop(L, 2);
    preferences::set_string(luaL_checkstring(L, 1), luaL_checkstring(L, 2));
    return 0;
}

static int _preferences_flush(lua_State *L)
{
    preferences::flush();
    return 0;
}

static int _preferences_delete_key(lua_State *L)
{
    preferences::delete_key(luaL_checkstring(L, 1));
    return 0;
}

static int luaopen_preferences(lua_State *L)
{
    static const luaL_Reg lib[] = {
        {"get_bool", _preferences_get_bool},
        {"set_bool", _preferences_set_bool},
        {"get_float", _preferences_get_float},
        {"set_float", _preferences_set_float},
        {"get_double", _preferences_get_double},
        {"set_double", _preferences_set_double},
        {"get_int", _preferences_get_int},
        {"set_int", _preferences_set_int},
        {"get_string", _preferences_get_string},
        {"set_string", _preferences_set_string},
        {"flush", _preferences_flush},
        {"delete_key", _preferences_delete_key},
        {NULL, NULL}
    };
    
    luaL_newlib(L, lib);
    
    return 1;
}

static int _window_get_visible_bounds(lua_State *L)
{
    auto rect = Director::getInstance()->getOpenGLView()->getVisibleRect();
    lua_pushinteger(L, rect.getMinX());
    lua_pushinteger(L, rect.getMaxX());
    lua_pushinteger(L, rect.getMaxY());
    lua_pushinteger(L, rect.getMinY());
    return 4;
}

static int _window_get_design_size(lua_State *L)
{
    auto size = Director::getInstance()->getOpenGLView()->getDesignResolutionSize();
    lua_pushnumber(L, size.width);
    lua_pushnumber(L, size.height);
    return 2;
}

static int _window_set_design_size(lua_State *L)
{
    lua_settop(L, 3);
    Director::getInstance()->getOpenGLView()->setDesignResolutionSize(
        (float)luaL_checknumber(L, 1), (float)luaL_checknumber(L, 2),
        (ResolutionPolicy)luaL_checkinteger(L, 3));
    return 0;
}

static int _window_convert_to_camera_space(lua_State *L)
{
    Vec2 pt = Vec2(luaL_checknumber(L, 1), luaL_checknumber(L, 2));
    
    auto director = Director::getInstance();
    Mat4 w2l = director->getRunningScene()->getWorldToNodeTransform();
    Rect rect;
    rect.size = director->getOpenGLView()->getDesignResolutionSize();
    auto camera = director->getRunningScene()->getDefaultCamera();
    Vec3 Pn(pt.x, pt.y, -1), Pf(pt.x, pt.y, 1);
    Pn = camera->unprojectGL(Pn);
    Pf = camera->unprojectGL(Pf);
    
    //  then convert Pn and Pf to node space
    w2l.transformPoint(&Pn);
    w2l.transformPoint(&Pf);
    
    // Pn and Pf define a line Q(t) = D + t * E which D = Pn
    auto E = Pf - Pn;
    
    // second, get three points which define content plane
    //  these points define a plane P(u, w) = A + uB + wC
    Vec3 A = Vec3(rect.origin.x, rect.origin.y, 0);
    Vec3 B(rect.origin.x + rect.size.width, rect.origin.y, 0);
    Vec3 C(rect.origin.x, rect.origin.y + rect.size.height, 0);
    B = B - A;
    C = C - A;
    
    //  the line Q(t) intercept with plane P(u, w)
    //  calculate the intercept point P = Q(t)
    //      (BxC).A - (BxC).D
    //  t = -----------------
    //          (BxC).E
    Vec3 BxC;
    Vec3::cross(B, C, &BxC);
    auto BxCdotE = BxC.dot(E);
    auto t = (BxC.dot(A) - BxC.dot(Pn)) / BxCdotE;
    Vec3 P = Pn + t * E;
    
    lua_pushnumber(L, P.x);
    lua_pushnumber(L, P.y);
    
    return 2;
}

static int luaopen_window(lua_State *L)
{
    static const luaL_Reg lib[] = {
        {"get_visible_bounds", _window_get_visible_bounds},
        {"get_design_size", _window_get_design_size},
        {"set_design_size", _window_set_design_size},
        {"convert_to_camera_space", _window_convert_to_camera_space},
        {NULL, NULL},
    };
    
    luaL_newlib(L, lib);
    
    return 1;
}

static int _timer_schedule(lua_State *L)
{
    lua_settop(L, 2);
    float interval = (float)luaL_checknumber(L, 1);
    unsigned int callback = luaext_reffunction(L, 2);
    unsigned int id = timer::schedule(interval, [callback](float dt) {
        lua_State *L = luaext_cocosthread();
        int top = lua_gettop(L);
        lua_pushcfunction(L, luaext_errorfunc);
        luaext_getref(L, callback);
        if (lua_isfunction(L, -1)) {
            lua_pushnumber(L, dt);
            lua_pcall(L, 1, 0, top + 1);
        }
        lua_settop(L, top);
    });
    lua_pushinteger(L, ((uint64_t)callback << 32) | (uint64_t)id);
    return 1;
}

static int _timer_unschedule(lua_State *L)
{
    lua_settop(L, 1);
    uint64_t value = luaL_checkinteger(L, 1);
    unsigned int callback = value >> 32;
    unsigned int id = value & 0xFFFFFFFF;
    luaext_unref(L, callback);
    timer::unschedule(id);
    return 0;
}

static int _timer_delay(lua_State *L)
{
    lua_settop(L, 2);
    float time = (float)luaL_checknumber(L, 1);
    unsigned int callback = luaext_reffunction(L, 2);
    timer::delay(time, [callback]() {
        lua_State *L = luaext_cocosthread();
        int top = lua_gettop(L);
        lua_pushcfunction(L, luaext_errorfunc);
        luaext_getref(L, callback);
        if (lua_isfunction(L, -1)) {
            lua_pcall(L, 0, 0, top + 1);
            luaext_unref(L, callback);
        }
        lua_settop(L, top);
    });
    return 0;
}

static std::unordered_map<std::string, int> s_timer_tag;
static int _timer_delay_with_tag(lua_State *L)
{
    lua_settop(L, 3);
    size_t len;
    float time = (float)luaL_checknumber(L, 1);
    const char *tagstr = luaL_checklstring(L, 2, &len);
    if (len <= 0) {
        luaL_error(L, "key should not be empty!");
    }
    const std::string tag = std::string(tagstr);
    if (s_timer_tag.find(tag) != s_timer_tag.end()) {
        luaext_unref(L, s_timer_tag[tag]);
    }
    unsigned int callback = luaext_reffunction(L, 3);
    s_timer_tag[tag] = callback;
    timer::delay_with_tag(time, tag, [callback]() {
        lua_State *L = luaext_cocosthread();
        int top = lua_gettop(L);
        lua_pushcfunction(L, luaext_errorfunc);
        luaext_getref(L, callback);
        if (lua_isfunction(L, -1)) {
            lua_pcall(L, 0, 0, top + 1);
            luaext_unref(L, callback);
        }
        lua_settop(L, top);
    });
    return 0;
}

static int _timer_kill_delay(lua_State *L)
{
    lua_settop(L, 1);
    const char *tagstr = luaL_checkstring(L, 1);
    const std::string tag = std::string(tagstr);
    auto it = s_timer_tag.find(tag);
    if (it != s_timer_tag.end()) {
        luaext_unref(L, it->second);
        s_timer_tag.erase(it);
        timer::kill_delay(tag);
    }
    return 0;
}

static int luaopen_timer(lua_State *L)
{
    static const luaL_Reg lib[] = {
        {"schedule", _timer_schedule},
        {"unschedule", _timer_unschedule},
        {"delay", _timer_delay},
        {"delay_with_tag", _timer_delay_with_tag},
        {"kill_delay", _timer_kill_delay},
        {NULL, NULL},
    };
    luaL_newlib(L, lib);
    
    return 1;
}

static int _runtime_launch(lua_State *L)
{
    const char *path = luaL_checkstring(L, 1);
    lua_pushboolean(L, runtime::launch(path));
    return 1;
}

static int _runtime_restart(lua_State *L)
{
    lua_pushboolean(L, runtime::restart());
    return 1;
}

static int _runtime_clear_storage(lua_State *L)
{
    runtime::clear_storage();
    return 0;
}

static int _runtime_set_log_url(lua_State *L)
{
    lua_settop(L, 1);
    return 0;
}

static int _runtime_set_log_path(lua_State *L)
{
    lua_settop(L, 1);
    return 0;
}

static int _runtime_get_log_path(lua_State *L)
{
    lua_pushstring(L, logger::get_log_path().c_str());
    return 1;
}

static int _runtime_set_dispatcher(lua_State *L)
{
    int handler = luaext_reffunction(L, 1);
    runtime::set_dispatcher([handler](const std::string &event, const std::string &args) {
        lua_State *L = luaext_cocosthread();
        int top = lua_gettop(L);
        lua_pushcfunction(L, luaext_errorfunc);
        luaext_getref(L, handler);
        if (lua_isfunction(L, -1)) {
            lua_pushstring(L, event.c_str());
            lua_pushstring(L, args.c_str());
            lua_pcall(L, 2, 0, top + 1);
        }
        lua_settop(L, top);
    });
    return 0;
}

static int _runtime_support(lua_State *L)
{
    const char *api = luaL_checkstring(L, 1);
    lua_pushboolean(L, runtime::support(api));
    
    return 1;
}

static int _runtime_print_support(lua_State *L)
{
    runtime::print_support();
    return 1;
}

static int _runtime_set_clipboard_text(lua_State *L)
{
    runtime::copy_to_pasteboard(luaL_checkstring(L, 1));
    return 0;
}

static int _runtime_get_os(lua_State *L)
{
    lua_pushstring(L, runtime::get_os().c_str());
    return 1;
}

static int _runtime_get_platform(lua_State *L)
{
    lua_pushstring(L, runtime::get_platform().c_str());
    return 1;
}

static int _runtime_get_channel(lua_State *L)
{
    lua_pushstring(L, runtime::get_channel().c_str());
    return 1;
}

static int _runtime_get_device_info(lua_State *L)
{
    lua_pushstring(L, runtime::get_device_info().c_str());
    return 1;
}

static int _runtime_get_package_name(lua_State *L)
{
    lua_pushstring(L, runtime::get_app_id().c_str());
    return 1;
}

static int _runtime_get_open_url(lua_State *L)
{
    lua_pushstring(L, runtime::get_open_url().c_str());
    return 1;
}

static int _runtime_get_version(lua_State *L)
{
    lua_pushstring(L, runtime::get_app_version().c_str());
    return 1;
}

static int _runtime_get_sdk_int(lua_State *L)
{
    lua_pushinteger(L, runtime::get_sdk_int());
    return 1;
}

static int _runtime_get_version_code(lua_State *L)
{
    lua_pushstring(L, runtime::get_app_version_code().c_str());
    return 1;
}

static int _runtime_set_audio_session_catalog(lua_State *L)
{
    const char *catalog = luaL_checkstring(L, 1);
    runtime::set_audio_session_catalog(catalog);
    return 0;
}

static int _runtime_get_audio_session_catalog(lua_State *L)
{
    lua_pushstring(L, runtime::get_audio_session_catalog().c_str());
    return 1;
}

static int _runtime_bind_push_identifier(lua_State *L)
{
    static const int type[] = {0, 1 << 0, 1 << 1};
    static const char *const type_names[] = {"NONE", "ACCOUNT", "TAG"};
    const char *identifier = luaL_checkstring(L, 1);
    int idx = luaL_checkoption(L, 2, "ACCOUNT", type_names);
    runtime::bind_push_identifier(identifier, type[idx]);
    return 0;
}

static int _runtime_unbind_push_identifier(lua_State *L)
{
    static const int type[] = {0, 1 << 0, 1 << 1};
    static const char *const type_names[] = {"NONE", "ACCOUNT", "TAG"};
    const char *identifier = luaL_checkstring(L, 1);
    int idx = luaL_checkoption(L, 2, "ACCOUNT", type_names);
    runtime::unbind_push_identifier(identifier, type[idx]);
    return 0;
}

static int _runtime_test_crash(lua_State *L)
{
    runtime::log("test native crash!!!!");
    char *prt = NULL;
    *prt = 0;
    return 0;
}

static int _runtime_open_url(lua_State *L)
{
    lua_settop(L, 2);
    int callback = LUA_REFNIL;
    if (lua_isfunction(L, 2)) {
        callback = luaext_reffunction(L, 2);
    }
    runtime::open_url(luaL_checkstring(L, 1), [callback](bool success) {
        if (callback != LUA_REFNIL) {
            lua_State *L = luaext_cocosthread();
            int top = lua_gettop(L);
            lua_pushcfunction(L, luaext_errorfunc);
            luaext_getref(L, callback);
            if (lua_isfunction(L, -1)) {
                lua_pushboolean(L, success);
                lua_pcall(L, 1, 0, top + 1);
                luaext_unref(L, callback);
            }
            lua_settop(L, top);
        }
    });
    return 0;
}

static int _runtme_get_lua_mapping_count(lua_State *L)
{
    lua_pushinteger(L, luaext_mapping_count(L));
    return 1;
}

static int _runtime_disable_reprot(lua_State *L)
{
    runtime::disable_report();
    return 0;
}

static int _runtime_set_antialias(lua_State *L)
{
    lua_settop(L, 2);
    runtime::set_antialias(lua_toboolean(L, 1), (unsigned int)luaL_checkinteger(L, 2));
    return 0;
}

static int _runtime_is_antialias(lua_State *L)
{
    lua_pushboolean(L, runtime::is_antialias());
    return 1;
}

static int luaopen_runtime(lua_State *L)
{
    static const luaL_Reg lib[] = {
        {"support", _runtime_support},
        {"print_support", _runtime_print_support},
        {"launch", _runtime_launch},
        {"restart", _runtime_restart},
        {"clear_storage", _runtime_clear_storage},
        {"set_clipboard_text", _runtime_set_clipboard_text},
        {"set_log_url", _runtime_set_log_url},
        {"set_log_path", _runtime_set_log_path},
        {"get_log_path", _runtime_get_log_path},
        {"set_dispatcher", _runtime_set_dispatcher},
        {"get_os", _runtime_get_os},
        {"get_platform", _runtime_get_platform},
        {"get_channel", _runtime_get_channel},
        {"get_device_info", _runtime_get_device_info},
        {"get_package_name", _runtime_get_package_name},
        {"get_open_url", _runtime_get_open_url},
        {"get_version", _runtime_get_version},
        {"get_sdk_int", _runtime_get_sdk_int},
        {"get_version_code", _runtime_get_version_code},
        {"set_audio_session_catalog", _runtime_set_audio_session_catalog},
        {"get_audio_session_catalog", _runtime_get_audio_session_catalog},
        {"bind_push_identifier", _runtime_bind_push_identifier},
        {"unbind_push_identifier", _runtime_unbind_push_identifier},
        {"test_crash", _runtime_test_crash},
        {"open_url", _runtime_open_url},
        {"get_lua_mapping_count", _runtme_get_lua_mapping_count}, // debug
        {"disable_report", _runtime_disable_reprot}, // debug
        {"set_antialias", _runtime_set_antialias},
        {"is_antialias", _runtime_is_antialias},
        {NULL, NULL},
    };
    luaL_newlib(L, lib);

    return 1;
}

static int _tween_func(lua_State *L)
{
    lua_settop(L, 2);
    float time = (float)luaL_checknumber(L, 1);
    cocos2d::tweenfunc::TweenType type = (cocos2d::tweenfunc::TweenType)luaL_checkinteger(L, 2);
    float value = tweenTo(time, type, nullptr);
    lua_pushnumber(L, value);
    return 1;
}

static int luaopen_tween_func(lua_State *L)
{
    lua_pushcfunction(L, _tween_func);
    return 1;
}

int luaopen_xgame(lua_State *L)
{
    static luaL_Reg lib[] = {
        {"kernel.draw_node", luaopen_draw_node},
        {"kernel.socket", luaopen_socket},
        {"kernel.fileloader", luaopen_file_loader},
        {"kernel.filesystem", luaopen_filesystem},
        {"kernel.preferences", luaopen_preferences},
        {"kernel.window", luaopen_window},
        {"kernel.timer", luaopen_timer},
        {"kernel.runtime", luaopen_runtime},
        {"kernel.tween_func", luaopen_tween_func},
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
        {"kernel.javabridge", luaopen_javabridge},
#endif
        {NULL, NULL}
    };
    
    luaL_getsubtable(L, LUA_REGISTRYINDEX, LUA_PRELOAD_TABLE);
    for (luaL_Reg *l = lib; l->func; ++l)
    {
        lua_pushcfunction(L, l->func);
        lua_setfield(L, -2, l->name);
    }
    lua_pop(L, 2);
    
    BuglyLuaAgent::registerLuaExceptionHandler(LuaEngine::getInstance());

    return 1;
}
