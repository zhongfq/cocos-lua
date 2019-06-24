local cls = class()
cls.CPPCLS = 'spSkeletonData'
cls.LUACLS = 'sp.SkeletonData'

cls.func("__gc", [[
{
    if (olua_isa(L, 1, "sp.SkeletonData")) {
        spSkeletonData *self = olua_touserdata(L, 1, spSkeletonData *);
        lua_pushstring(L, ".ownership");
        olua_getvariable(L, 1);
        if (lua_toboolean(L, -1) && self) {
            *(void **)lua_touserdata(L, 1) = nullptr;
            
            lua_pushstring(L, ".skel.loader");
            olua_getvariable(L, 1);
            spAttachmentLoader *loader = olua_touserdata(L, -1, spAttachmentLoader *);
            spAttachmentLoader_dispose(loader);
            
            lua_pushstring(L, ".skel.atlas");
            olua_getvariable(L, 1);
            spAtlas *atlas = olua_touserdata(L, -1, spAtlas *);
            spAtlas_dispose(atlas);
            
            spSkeletonData_dispose(self);
        }
    }
    return 0;
}]])
cls.alias("__gc", "dispose")

cls.func("new", [[
{
    const char *skel_path = olua_checkstring(L, 1);
    const char *atlas_path = olua_checkstring(L, 2);
    float scale = olua_optnumber(L, 3, 1);
    
    spAtlas* atlas = spAtlas_createFromFile(atlas_path, 0);
    if (!atlas) {
        luaL_error(L, "error reading altas file: %s", atlas_path);
    }
    
    spSkeletonData *skel_data = nullptr;
    spAttachmentLoader *loader = (spAttachmentLoader *)Cocos2dAttachmentLoader_create(atlas);
    
    if (strendwith(skel_path, ".skel")) {
        spSkeletonBinary *reader = spSkeletonBinary_createWithLoader(loader);
        reader->scale = scale;
        skel_data = spSkeletonBinary_readSkeletonDataFile(reader, skel_path);
        spSkeletonBinary_dispose(reader);
    } else {
        spSkeletonJson *reader = spSkeletonJson_createWithLoader(loader);
        reader->scale = scale;
        skel_data = spSkeletonJson_readSkeletonDataFile(reader, skel_path);
        spSkeletonJson_dispose(reader);
    }
    
    if (!skel_data) {
        spAttachmentLoader_dispose(loader);
        spAtlas_dispose(atlas);
        luaL_error(L, "error reading skeleton file: %s", skel_path);
    }
    
    olua_push_obj(L, skel_data, "sp.SkeletonData");
    
    lua_pushstring(L, ".ownership");
    lua_pushboolean(L, true);
    olua_setvariable(L, -3);
    
    lua_pushstring(L, ".skel.loader");
    lua_pushlightuserdata(L, loader);
    olua_setvariable(L, -3);
    
    lua_pushstring(L, ".skel.atlas");
    lua_pushlightuserdata(L, atlas);
    olua_setvariable(L, -3);
    
    return 1;
}]])

return cls