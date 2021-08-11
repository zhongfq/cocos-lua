//
// AUTO BUILD, DON'T MODIFY!
//
#include "lua_cocos2d_studio.h"

static std::string makeFrameEndCallbackTag(lua_Integer index, const std::string &key)
{
    if (index < 0) {
        return "frameEnd.";
    } else {
        return "frameEnd." + std::to_string((int)index) + "." + key;
    }
}

static std::string makeFrameEndCallbackTag(cocostudio::timeline::ActionTimeline *self, const std::string &animationName)
{
    auto info = self->getAnimationInfo(animationName);
    return makeFrameEndCallbackTag((lua_Integer)info.endIndex, animationName);
}

int olua_push_cocostudio_timeline_AnimationInfo(lua_State *L, const cocostudio::timeline::AnimationInfo *value)
{
    if (value) {
        lua_createtable(L, 0, 3);

        olua_push_std_string(L, value->name);
        olua_setfield(L, -2, "name");

        olua_push_int(L, (lua_Integer)value->startIndex);
        olua_setfield(L, -2, "startIndex");

        olua_push_int(L, (lua_Integer)value->endIndex);
        olua_setfield(L, -2, "endIndex");
    } else {
        lua_pushnil(L);
    }

    return 1;
}

void olua_check_cocostudio_timeline_AnimationInfo(lua_State *L, int idx, cocostudio::timeline::AnimationInfo *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);
    luaL_checktype(L, idx, LUA_TTABLE);

    std::string arg1;       /** name */
    lua_Integer arg2 = 0;       /** startIndex */
    lua_Integer arg3 = 0;       /** endIndex */

    olua_getfield(L, idx, "name");
    olua_check_std_string(L, -1, &arg1);
    value->name = (std::string)arg1;
    lua_pop(L, 1);

    olua_getfield(L, idx, "startIndex");
    olua_check_int(L, -1, &arg2);
    value->startIndex = (int)arg2;
    lua_pop(L, 1);

    olua_getfield(L, idx, "endIndex");
    olua_check_int(L, -1, &arg3);
    value->endIndex = (int)arg3;
    lua_pop(L, 1);
}

bool olua_is_cocostudio_timeline_AnimationInfo(lua_State *L, int idx)
{
    return olua_istable(L, idx) && olua_hasfield(L, idx, "endIndex") && olua_hasfield(L, idx, "startIndex") && olua_hasfield(L, idx, "name");
}

void olua_pack_cocostudio_timeline_AnimationInfo(lua_State *L, int idx, cocostudio::timeline::AnimationInfo *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);

    std::string arg1;       /** name */
    lua_Integer arg2 = 0;       /** startIndex */
    lua_Integer arg3 = 0;       /** endIndex */

    olua_check_std_string(L, idx + 0, &arg1);
    value->name = (std::string)arg1;

    olua_check_int(L, idx + 1, &arg2);
    value->startIndex = (int)arg2;

    olua_check_int(L, idx + 2, &arg3);
    value->endIndex = (int)arg3;
}

int olua_unpack_cocostudio_timeline_AnimationInfo(lua_State *L, const cocostudio::timeline::AnimationInfo *value)
{
    if (value) {
        olua_push_std_string(L, value->name);
        olua_push_int(L, (lua_Integer)value->startIndex);
        olua_push_int(L, (lua_Integer)value->endIndex);
    } else {
        for (int i = 0; i < 3; i++) {
            lua_pushnil(L);
        }
    }

    return 3;
}

bool olua_ispack_cocostudio_timeline_AnimationInfo(lua_State *L, int idx)
{
    return olua_is_std_string(L, idx + 0) && olua_is_int(L, idx + 1) && olua_is_int(L, idx + 2);
}

static int _cocos2d_CSLoader___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_postgc<cocos2d::CSLoader>(L, 1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_CSLoader___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::CSLoader *)olua_toobj(L, 1, "cc.CSLoader");
    olua_push_cppobj(L, self, "cc.CSLoader");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_CSLoader_bindCallback(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::CSLoader *self = nullptr;
    std::string arg1;       /** callbackName */
    std::string arg2;       /** callbackType */
    cocos2d::ui::Widget *arg3 = nullptr;       /** sender */
    cocos2d::Node *arg4 = nullptr;       /** handler */

    olua_to_cppobj(L, 1, (void **)&self, "cc.CSLoader");
    olua_check_std_string(L, 2, &arg1);
    olua_check_std_string(L, 3, &arg2);
    olua_check_cppobj(L, 4, (void **)&arg3, "ccui.Widget");
    olua_check_cppobj(L, 5, (void **)&arg4, "cc.Node");

    // bool bindCallback(const std::string &callbackName, const std::string &callbackType, cocos2d::ui::Widget *sender, cocos2d::Node *handler)
    bool ret = self->bindCallback(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_CSLoader_createNode1(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** filename */

    olua_check_std_string(L, 1, &arg1);

    // static cocos2d::Node *createNode(const std::string &filename)
    cocos2d::Node *ret = cocos2d::CSLoader::createNode(arg1);
    int num_ret = olua_push_cppobj(L, ret, "cc.Node");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_CSLoader_createNode2(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** filename */
    std::function<void(cocos2d::Ref *)> arg2;       /** callback */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_function(L, 2, &arg2);

    void *cb_store = (void *)olua_pushclassobj(L, "cc.CSLoader");
    std::string cb_tag = "createNode";
    std::string cb_name = olua_setcallback(L, cb_store,  2, cb_tag.c_str(), OLUA_TAG_NEW);
    lua_Integer cb_ctx = olua_context(L);
    arg2 = [cb_store, cb_name, cb_ctx](cocos2d::Ref *arg1) {
        lua_State *L = olua_mainthread(NULL);
        olua_checkhostthread();

        if (L != NULL && olua_context(L) == cb_ctx) {
            int top = lua_gettop(L);
            size_t last = olua_push_objpool(L);
            olua_enable_objpool(L);
            olua_push_cppobj(L, arg1, "cc.Ref");
            olua_disable_objpool(L);

            olua_callback(L, cb_store, cb_name.c_str(), 1);

            //pop stack value
            olua_pop_objpool(L, last);
            lua_settop(L, top);
        }
    };

    // static cocos2d::Node *createNode(const std::string &filename, @local const std::function<void (cocos2d::Ref *)> &callback)
    cocos2d::Node *ret = cocos2d::CSLoader::createNode(arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "cc.Node");

    olua_removecallback(L, cb_store, cb_name.c_str(), OLUA_TAG_WHOLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_CSLoader_createNode3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Data arg1;       /** data */

    olua_check_cocos2d_Data(L, 1, &arg1);

    // static cocos2d::Node *createNode(const cocos2d::Data &data)
    cocos2d::Node *ret = cocos2d::CSLoader::createNode(arg1);
    int num_ret = olua_push_cppobj(L, ret, "cc.Node");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_CSLoader_createNode4(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Data arg1;       /** data */
    std::function<void(cocos2d::Ref *)> arg2;       /** callback */

    olua_check_cocos2d_Data(L, 1, &arg1);
    olua_check_std_function(L, 2, &arg2);

    void *cb_store = (void *)olua_pushclassobj(L, "cc.CSLoader");
    std::string cb_tag = "createNode";
    std::string cb_name = olua_setcallback(L, cb_store,  2, cb_tag.c_str(), OLUA_TAG_NEW);
    lua_Integer cb_ctx = olua_context(L);
    arg2 = [cb_store, cb_name, cb_ctx](cocos2d::Ref *arg1) {
        lua_State *L = olua_mainthread(NULL);
        olua_checkhostthread();

        if (L != NULL && olua_context(L) == cb_ctx) {
            int top = lua_gettop(L);
            size_t last = olua_push_objpool(L);
            olua_enable_objpool(L);
            olua_push_cppobj(L, arg1, "cc.Ref");
            olua_disable_objpool(L);

            olua_callback(L, cb_store, cb_name.c_str(), 1);

            //pop stack value
            olua_pop_objpool(L, last);
            lua_settop(L, top);
        }
    };

    // static cocos2d::Node *createNode(const cocos2d::Data &data, @local const std::function<void (cocos2d::Ref *)> &callback)
    cocos2d::Node *ret = cocos2d::CSLoader::createNode(arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "cc.Node");

    olua_removecallback(L, cb_store, cb_name.c_str(), OLUA_TAG_WHOLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_CSLoader_createNode(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        if ((olua_is_std_string(L, 1))) {
            // static cocos2d::Node *createNode(const std::string &filename)
            return _cocos2d_CSLoader_createNode1(L);
        }

        // if ((olua_is_cocos2d_Data(L, 1))) {
            // static cocos2d::Node *createNode(const cocos2d::Data &data)
            return _cocos2d_CSLoader_createNode3(L);
        // }
    }

    if (num_args == 2) {
        if ((olua_is_std_string(L, 1)) && (olua_is_std_function(L, 2))) {
            // static cocos2d::Node *createNode(const std::string &filename, @local const std::function<void (cocos2d::Ref *)> &callback)
            return _cocos2d_CSLoader_createNode2(L);
        }

        // if ((olua_is_cocos2d_Data(L, 1)) && (olua_is_std_function(L, 2))) {
            // static cocos2d::Node *createNode(const cocos2d::Data &data, @local const std::function<void (cocos2d::Ref *)> &callback)
            return _cocos2d_CSLoader_createNode4(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::CSLoader::createNode' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_CSLoader_createNodeFromJson(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::CSLoader *self = nullptr;
    std::string arg1;       /** filename */

    olua_to_cppobj(L, 1, (void **)&self, "cc.CSLoader");
    olua_check_std_string(L, 2, &arg1);

    // cocos2d::Node *createNodeFromJson(const std::string &filename)
    cocos2d::Node *ret = self->createNodeFromJson(arg1);
    int num_ret = olua_push_cppobj(L, ret, "cc.Node");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_CSLoader_createNodeWithFlatBuffersFile(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::CSLoader *self = nullptr;
    std::string arg1;       /** filename */

    olua_to_cppobj(L, 1, (void **)&self, "cc.CSLoader");
    olua_check_std_string(L, 2, &arg1);

    // cocos2d::Node *createNodeWithFlatBuffersFile(const std::string &filename)
    cocos2d::Node *ret = self->createNodeWithFlatBuffersFile(arg1);
    int num_ret = olua_push_cppobj(L, ret, "cc.Node");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_CSLoader_createNodeWithFlatBuffersForSimulator(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::CSLoader *self = nullptr;
    std::string arg1;       /** filename */

    olua_to_cppobj(L, 1, (void **)&self, "cc.CSLoader");
    olua_check_std_string(L, 2, &arg1);

    // cocos2d::Node *createNodeWithFlatBuffersForSimulator(const std::string &filename)
    cocos2d::Node *ret = self->createNodeWithFlatBuffersForSimulator(arg1);
    int num_ret = olua_push_cppobj(L, ret, "cc.Node");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_CSLoader_createNodeWithVisibleSize1(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** filename */

    olua_check_std_string(L, 1, &arg1);

    // static cocos2d::Node *createNodeWithVisibleSize(const std::string &filename)
    cocos2d::Node *ret = cocos2d::CSLoader::createNodeWithVisibleSize(arg1);
    int num_ret = olua_push_cppobj(L, ret, "cc.Node");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_CSLoader_createNodeWithVisibleSize2(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** filename */
    std::function<void(cocos2d::Ref *)> arg2;       /** callback */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_function(L, 2, &arg2);

    void *cb_store = (void *)olua_pushclassobj(L, "cc.CSLoader");
    std::string cb_tag = "createNodeWithVisibleSize";
    std::string cb_name = olua_setcallback(L, cb_store,  2, cb_tag.c_str(), OLUA_TAG_NEW);
    lua_Integer cb_ctx = olua_context(L);
    arg2 = [cb_store, cb_name, cb_ctx](cocos2d::Ref *arg1) {
        lua_State *L = olua_mainthread(NULL);
        olua_checkhostthread();

        if (L != NULL && olua_context(L) == cb_ctx) {
            int top = lua_gettop(L);
            size_t last = olua_push_objpool(L);
            olua_enable_objpool(L);
            olua_push_cppobj(L, arg1, "cc.Ref");
            olua_disable_objpool(L);

            olua_callback(L, cb_store, cb_name.c_str(), 1);

            //pop stack value
            olua_pop_objpool(L, last);
            lua_settop(L, top);
        }
    };

    // static cocos2d::Node *createNodeWithVisibleSize(const std::string &filename, @local const std::function<void (cocos2d::Ref *)> &callback)
    cocos2d::Node *ret = cocos2d::CSLoader::createNodeWithVisibleSize(arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "cc.Node");

    olua_removecallback(L, cb_store, cb_name.c_str(), OLUA_TAG_WHOLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_CSLoader_createNodeWithVisibleSize(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 1))) {
            // static cocos2d::Node *createNodeWithVisibleSize(const std::string &filename)
            return _cocos2d_CSLoader_createNodeWithVisibleSize1(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 1)) && (olua_is_std_function(L, 2))) {
            // static cocos2d::Node *createNodeWithVisibleSize(const std::string &filename, @local const std::function<void (cocos2d::Ref *)> &callback)
            return _cocos2d_CSLoader_createNodeWithVisibleSize2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::CSLoader::createNodeWithVisibleSize' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_CSLoader_createTimeline1(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** filename */

    olua_check_std_string(L, 1, &arg1);

    // static cocostudio::timeline::ActionTimeline *createTimeline(const std::string &filename)
    cocostudio::timeline::ActionTimeline *ret = cocos2d::CSLoader::createTimeline(arg1);
    int num_ret = olua_push_cppobj(L, ret, "ccs.timeline.ActionTimeline");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_CSLoader_createTimeline2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Data arg1;       /** data */
    std::string arg2;       /** filename */

    olua_check_cocos2d_Data(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);

    // static cocostudio::timeline::ActionTimeline *createTimeline(const cocos2d::Data &data, const std::string &filename)
    cocostudio::timeline::ActionTimeline *ret = cocos2d::CSLoader::createTimeline(arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "ccs.timeline.ActionTimeline");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_CSLoader_createTimeline(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 1))) {
            // static cocostudio::timeline::ActionTimeline *createTimeline(const std::string &filename)
            return _cocos2d_CSLoader_createTimeline1(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_cocos2d_Data(L, 1)) && (olua_is_std_string(L, 2))) {
            // static cocostudio::timeline::ActionTimeline *createTimeline(const cocos2d::Data &data, const std::string &filename)
            return _cocos2d_CSLoader_createTimeline2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::CSLoader::createTimeline' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_CSLoader_destroyInstance(lua_State *L)
{
    olua_startinvoke(L);

    // static void destroyInstance()
    cocos2d::CSLoader::destroyInstance();

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_CSLoader_getInstance(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::CSLoader *getInstance()
    cocos2d::CSLoader *ret = cocos2d::CSLoader::getInstance();
    int num_ret = olua_push_cppobj(L, ret, "cc.CSLoader");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_CSLoader_getJsonPath(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::CSLoader *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.CSLoader");

    // std::string getJsonPath()
    std::string ret = self->getJsonPath();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_CSLoader_init(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::CSLoader *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.CSLoader");

    // void init()
    self->init();

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_CSLoader_isRecordJsonPath(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::CSLoader *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.CSLoader");

    // bool isRecordJsonPath()
    bool ret = self->isRecordJsonPath();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_CSLoader_loadNodeWithContent(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::CSLoader *self = nullptr;
    std::string arg1;       /** content */

    olua_to_cppobj(L, 1, (void **)&self, "cc.CSLoader");
    olua_check_std_string(L, 2, &arg1);

    // cocos2d::Node *loadNodeWithContent(const std::string &content)
    cocos2d::Node *ret = self->loadNodeWithContent(arg1);
    int num_ret = olua_push_cppobj(L, ret, "cc.Node");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_CSLoader_loadNodeWithFile(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::CSLoader *self = nullptr;
    std::string arg1;       /** fileName */

    olua_to_cppobj(L, 1, (void **)&self, "cc.CSLoader");
    olua_check_std_string(L, 2, &arg1);

    // cocos2d::Node *loadNodeWithFile(const std::string &fileName)
    cocos2d::Node *ret = self->loadNodeWithFile(arg1);
    int num_ret = olua_push_cppobj(L, ret, "cc.Node");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_CSLoader_new(lua_State *L)
{
    olua_startinvoke(L);

    // CSLoader()
    cocos2d::CSLoader *ret = new cocos2d::CSLoader();
    int num_ret = olua_push_cppobj(L, ret, "cc.CSLoader");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_CSLoader_nodeWithFlatBuffersFile(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::CSLoader *self = nullptr;
    std::string arg1;       /** fileName */

    olua_to_cppobj(L, 1, (void **)&self, "cc.CSLoader");
    olua_check_std_string(L, 2, &arg1);

    // cocos2d::Node *nodeWithFlatBuffersFile(const std::string &fileName)
    cocos2d::Node *ret = self->nodeWithFlatBuffersFile(arg1);
    int num_ret = olua_push_cppobj(L, ret, "cc.Node");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_CSLoader_setJsonPath(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::CSLoader *self = nullptr;
    std::string arg1;       /** jsonPath */

    olua_to_cppobj(L, 1, (void **)&self, "cc.CSLoader");
    olua_check_std_string(L, 2, &arg1);

    // void setJsonPath(std::string jsonPath)
    self->setJsonPath(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_CSLoader_setRecordJsonPath(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::CSLoader *self = nullptr;
    bool arg1 = false;       /** record */

    olua_to_cppobj(L, 1, (void **)&self, "cc.CSLoader");
    olua_check_bool(L, 2, &arg1);

    // void setRecordJsonPath(bool record)
    self->setRecordJsonPath(arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_CSLoader(lua_State *L)
{
    oluacls_class(L, "cc.CSLoader", nullptr);
    oluacls_func(L, "__gc", _cocos2d_CSLoader___gc);
    oluacls_func(L, "__olua_move", _cocos2d_CSLoader___olua_move);
    oluacls_func(L, "bindCallback", _cocos2d_CSLoader_bindCallback);
    oluacls_func(L, "createNode", _cocos2d_CSLoader_createNode);
    oluacls_func(L, "createNodeFromJson", _cocos2d_CSLoader_createNodeFromJson);
    oluacls_func(L, "createNodeWithFlatBuffersFile", _cocos2d_CSLoader_createNodeWithFlatBuffersFile);
    oluacls_func(L, "createNodeWithFlatBuffersForSimulator", _cocos2d_CSLoader_createNodeWithFlatBuffersForSimulator);
    oluacls_func(L, "createNodeWithVisibleSize", _cocos2d_CSLoader_createNodeWithVisibleSize);
    oluacls_func(L, "createTimeline", _cocos2d_CSLoader_createTimeline);
    oluacls_func(L, "destroyInstance", _cocos2d_CSLoader_destroyInstance);
    oluacls_func(L, "getInstance", _cocos2d_CSLoader_getInstance);
    oluacls_func(L, "getJsonPath", _cocos2d_CSLoader_getJsonPath);
    oluacls_func(L, "init", _cocos2d_CSLoader_init);
    oluacls_func(L, "isRecordJsonPath", _cocos2d_CSLoader_isRecordJsonPath);
    oluacls_func(L, "loadNodeWithContent", _cocos2d_CSLoader_loadNodeWithContent);
    oluacls_func(L, "loadNodeWithFile", _cocos2d_CSLoader_loadNodeWithFile);
    oluacls_func(L, "new", _cocos2d_CSLoader_new);
    oluacls_func(L, "nodeWithFlatBuffersFile", _cocos2d_CSLoader_nodeWithFlatBuffersFile);
    oluacls_func(L, "setJsonPath", _cocos2d_CSLoader_setJsonPath);
    oluacls_func(L, "setRecordJsonPath", _cocos2d_CSLoader_setRecordJsonPath);
    oluacls_prop(L, "instance", _cocos2d_CSLoader_getInstance, nullptr);
    oluacls_prop(L, "jsonPath", _cocos2d_CSLoader_getJsonPath, _cocos2d_CSLoader_setJsonPath);
    oluacls_prop(L, "recordJsonPath", _cocos2d_CSLoader_isRecordJsonPath, _cocos2d_CSLoader_setRecordJsonPath);

    olua_registerluatype<cocos2d::CSLoader>(L, "cc.CSLoader");

    return 1;
}

static int luaopen_cocostudio_MovementEventType(lua_State *L)
{
    oluacls_class(L, "ccs.MovementEventType", nullptr);
    oluacls_const_integer(L, "COMPLETE", (lua_Integer)cocostudio::MovementEventType::COMPLETE);
    oluacls_const_integer(L, "LOOP_COMPLETE", (lua_Integer)cocostudio::MovementEventType::LOOP_COMPLETE);
    oluacls_const_integer(L, "START", (lua_Integer)cocostudio::MovementEventType::START);

    olua_registerluatype<cocostudio::MovementEventType>(L, "ccs.MovementEventType");

    return 1;
}

static int luaopen_cocostudio_DisplayType(lua_State *L)
{
    oluacls_class(L, "ccs.DisplayType", nullptr);
    oluacls_const_integer(L, "CS_DISPLAY_ARMATURE", (lua_Integer)cocostudio::DisplayType::CS_DISPLAY_ARMATURE);
    oluacls_const_integer(L, "CS_DISPLAY_MAX", (lua_Integer)cocostudio::DisplayType::CS_DISPLAY_MAX);
    oluacls_const_integer(L, "CS_DISPLAY_PARTICLE", (lua_Integer)cocostudio::DisplayType::CS_DISPLAY_PARTICLE);
    oluacls_const_integer(L, "CS_DISPLAY_SPRITE", (lua_Integer)cocostudio::DisplayType::CS_DISPLAY_SPRITE);

    olua_registerluatype<cocostudio::DisplayType>(L, "ccs.DisplayType");

    return 1;
}

static int _cocostudio_ActionFrame___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocostudio::ActionFrame *)olua_toobj(L, 1, "ccs.ActionFrame");
    olua_push_cppobj(L, self, "ccs.ActionFrame");

    olua_endinvoke(L);

    return 1;
}

static int _cocostudio_ActionFrame_getAction1(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ActionFrame *self = nullptr;
    lua_Number arg1 = 0;       /** duration */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ActionFrame");
    olua_check_number(L, 2, &arg1);

    // @addref(action |) cocos2d::ActionInterval *getAction(float duration)
    cocos2d::ActionInterval *ret = self->getAction((float)arg1);
    int num_ret = olua_push_cppobj(L, ret, "cc.ActionInterval");

    // insert code after call
    olua_addref(L, 1, "action", -1, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ActionFrame_getAction2(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ActionFrame *self = nullptr;
    lua_Number arg1 = 0;       /** duration */
    cocostudio::ActionFrame *arg2 = nullptr;       /** srcFrame */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ActionFrame");
    olua_check_number(L, 2, &arg1);
    olua_check_cppobj(L, 3, (void **)&arg2, "ccs.ActionFrame");

    // @addref(action |) cocos2d::ActionInterval *getAction(float duration, cocostudio::ActionFrame *srcFrame)
    cocos2d::ActionInterval *ret = self->getAction((float)arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "cc.ActionInterval");

    // insert code after call
    olua_addref(L, 1, "action", -1, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ActionFrame_getAction(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_number(L, 2))) {
            // @addref(action |) cocos2d::ActionInterval *getAction(float duration)
            return _cocostudio_ActionFrame_getAction1(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_number(L, 2)) && (olua_is_cppobj(L, 3, "ccs.ActionFrame"))) {
            // @addref(action |) cocos2d::ActionInterval *getAction(float duration, cocostudio::ActionFrame *srcFrame)
            return _cocostudio_ActionFrame_getAction2(L);
        // }
    }

    luaL_error(L, "method 'cocostudio::ActionFrame::getAction' not support '%d' arguments", num_args);

    return 0;
}

static int _cocostudio_ActionFrame_getEasingType(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ActionFrame *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ActionFrame");

    // int getEasingType()
    int ret = self->getEasingType();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ActionFrame_getFrameIndex(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ActionFrame *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ActionFrame");

    // int getFrameIndex()
    int ret = self->getFrameIndex();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ActionFrame_getFrameTime(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ActionFrame *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ActionFrame");

    // float getFrameTime()
    float ret = self->getFrameTime();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ActionFrame_getFrameType(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ActionFrame *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ActionFrame");

    // int getFrameType()
    int ret = self->getFrameType();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ActionFrame_new(lua_State *L)
{
    olua_startinvoke(L);

    // ActionFrame()
    cocostudio::ActionFrame *ret = new cocostudio::ActionFrame();
    int num_ret = olua_push_cppobj(L, ret, "ccs.ActionFrame");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ActionFrame_setEasingParameter(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ActionFrame *self = nullptr;
    std::vector<float> arg1;       /** parameter */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ActionFrame");
    olua_check_std_vector<float>(L, 2, &arg1, [L](float *value) {
        lua_Number obj;
        olua_check_number(L, -1, &obj);
        *value = (float)obj;
    });

    // void setEasingParameter(std::vector<float> &parameter)
    self->setEasingParameter(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ActionFrame_setEasingType(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ActionFrame *self = nullptr;
    lua_Integer arg1 = 0;       /** easingType */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ActionFrame");
    olua_check_int(L, 2, &arg1);

    // void setEasingType(int easingType)
    self->setEasingType((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ActionFrame_setFrameIndex(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ActionFrame *self = nullptr;
    lua_Integer arg1 = 0;       /** index */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ActionFrame");
    olua_check_int(L, 2, &arg1);

    // void setFrameIndex(int index)
    self->setFrameIndex((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ActionFrame_setFrameTime(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ActionFrame *self = nullptr;
    lua_Number arg1 = 0;       /** fTime */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ActionFrame");
    olua_check_number(L, 2, &arg1);

    // void setFrameTime(float fTime)
    self->setFrameTime((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ActionFrame_setFrameType(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ActionFrame *self = nullptr;
    lua_Integer arg1 = 0;       /** frameType */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ActionFrame");
    olua_check_int(L, 2, &arg1);

    // void setFrameType(int frameType)
    self->setFrameType((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocostudio_ActionFrame(lua_State *L)
{
    oluacls_class(L, "ccs.ActionFrame", "cc.Ref");
    oluacls_func(L, "__olua_move", _cocostudio_ActionFrame___olua_move);
    oluacls_func(L, "getAction", _cocostudio_ActionFrame_getAction);
    oluacls_func(L, "getEasingType", _cocostudio_ActionFrame_getEasingType);
    oluacls_func(L, "getFrameIndex", _cocostudio_ActionFrame_getFrameIndex);
    oluacls_func(L, "getFrameTime", _cocostudio_ActionFrame_getFrameTime);
    oluacls_func(L, "getFrameType", _cocostudio_ActionFrame_getFrameType);
    oluacls_func(L, "new", _cocostudio_ActionFrame_new);
    oluacls_func(L, "setEasingParameter", _cocostudio_ActionFrame_setEasingParameter);
    oluacls_func(L, "setEasingType", _cocostudio_ActionFrame_setEasingType);
    oluacls_func(L, "setFrameIndex", _cocostudio_ActionFrame_setFrameIndex);
    oluacls_func(L, "setFrameTime", _cocostudio_ActionFrame_setFrameTime);
    oluacls_func(L, "setFrameType", _cocostudio_ActionFrame_setFrameType);
    oluacls_prop(L, "easingType", _cocostudio_ActionFrame_getEasingType, _cocostudio_ActionFrame_setEasingType);
    oluacls_prop(L, "frameIndex", _cocostudio_ActionFrame_getFrameIndex, _cocostudio_ActionFrame_setFrameIndex);
    oluacls_prop(L, "frameTime", _cocostudio_ActionFrame_getFrameTime, _cocostudio_ActionFrame_setFrameTime);
    oluacls_prop(L, "frameType", _cocostudio_ActionFrame_getFrameType, _cocostudio_ActionFrame_setFrameType);

    olua_registerluatype<cocostudio::ActionFrame>(L, "ccs.ActionFrame");

    return 1;
}

static int _cocostudio_ActionFadeFrame___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocostudio::ActionFadeFrame *)olua_toobj(L, 1, "ccs.ActionFadeFrame");
    olua_push_cppobj(L, self, "ccs.ActionFadeFrame");

    olua_endinvoke(L);

    return 1;
}

static int _cocostudio_ActionFadeFrame_getOpacity(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ActionFadeFrame *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ActionFadeFrame");

    // int getOpacity()
    int ret = self->getOpacity();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ActionFadeFrame_new(lua_State *L)
{
    olua_startinvoke(L);

    // ActionFadeFrame()
    cocostudio::ActionFadeFrame *ret = new cocostudio::ActionFadeFrame();
    int num_ret = olua_push_cppobj(L, ret, "ccs.ActionFadeFrame");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ActionFadeFrame_setOpacity(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ActionFadeFrame *self = nullptr;
    lua_Integer arg1 = 0;       /** opacity */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ActionFadeFrame");
    olua_check_int(L, 2, &arg1);

    // void setOpacity(int opacity)
    self->setOpacity((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocostudio_ActionFadeFrame(lua_State *L)
{
    oluacls_class(L, "ccs.ActionFadeFrame", "ccs.ActionFrame");
    oluacls_func(L, "__olua_move", _cocostudio_ActionFadeFrame___olua_move);
    oluacls_func(L, "getOpacity", _cocostudio_ActionFadeFrame_getOpacity);
    oluacls_func(L, "new", _cocostudio_ActionFadeFrame_new);
    oluacls_func(L, "setOpacity", _cocostudio_ActionFadeFrame_setOpacity);
    oluacls_prop(L, "opacity", _cocostudio_ActionFadeFrame_getOpacity, _cocostudio_ActionFadeFrame_setOpacity);

    olua_registerluatype<cocostudio::ActionFadeFrame>(L, "ccs.ActionFadeFrame");

    return 1;
}

static int _cocostudio_ActionFrameEasing___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocostudio::ActionFrameEasing *)olua_toobj(L, 1, "ccs.ActionFrameEasing");
    olua_push_cppobj(L, self, "ccs.ActionFrameEasing");

    olua_endinvoke(L);

    return 1;
}

static int _cocostudio_ActionFrameEasing_bounceTime(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ActionFrameEasing *self = nullptr;
    lua_Number arg1 = 0;       /** t */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ActionFrameEasing");
    olua_check_number(L, 2, &arg1);

    // float bounceTime(float t)
    float ret = self->bounceTime((float)arg1);
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ActionFrameEasing_easeValue(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ActionFrameEasing *self = nullptr;
    lua_Number arg1 = 0;       /** t */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ActionFrameEasing");
    olua_check_number(L, 2, &arg1);

    // float easeValue(float t)
    float ret = self->easeValue((float)arg1);
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ActionFrameEasing_new(lua_State *L)
{
    olua_startinvoke(L);

    // ActionFrameEasing()
    cocostudio::ActionFrameEasing *ret = new cocostudio::ActionFrameEasing();
    int num_ret = olua_push_cppobj(L, ret, "ccs.ActionFrameEasing");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocostudio_ActionFrameEasing(lua_State *L)
{
    oluacls_class(L, "ccs.ActionFrameEasing", "cc.Ref");
    oluacls_func(L, "__olua_move", _cocostudio_ActionFrameEasing___olua_move);
    oluacls_func(L, "bounceTime", _cocostudio_ActionFrameEasing_bounceTime);
    oluacls_func(L, "easeValue", _cocostudio_ActionFrameEasing_easeValue);
    oluacls_func(L, "new", _cocostudio_ActionFrameEasing_new);

    olua_registerluatype<cocostudio::ActionFrameEasing>(L, "ccs.ActionFrameEasing");

    return 1;
}

static int _cocostudio_ActionMoveFrame___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocostudio::ActionMoveFrame *)olua_toobj(L, 1, "ccs.ActionMoveFrame");
    olua_push_cppobj(L, self, "ccs.ActionMoveFrame");

    olua_endinvoke(L);

    return 1;
}

static int _cocostudio_ActionMoveFrame_getPosition(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ActionMoveFrame *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ActionMoveFrame");

    // cocos2d::Vec2 getPosition()
    cocos2d::Vec2 ret = self->getPosition();
    int num_ret = olua_push_cocos2d_Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ActionMoveFrame_new(lua_State *L)
{
    olua_startinvoke(L);

    // ActionMoveFrame()
    cocostudio::ActionMoveFrame *ret = new cocostudio::ActionMoveFrame();
    int num_ret = olua_push_cppobj(L, ret, "ccs.ActionMoveFrame");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ActionMoveFrame_setPosition(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ActionMoveFrame *self = nullptr;
    cocos2d::Vec2 arg1;       /** pos */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ActionMoveFrame");
    olua_check_cocos2d_Vec2(L, 2, &arg1);

    // void setPosition(cocos2d::Vec2 pos)
    self->setPosition(arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocostudio_ActionMoveFrame(lua_State *L)
{
    oluacls_class(L, "ccs.ActionMoveFrame", "ccs.ActionFrame");
    oluacls_func(L, "__olua_move", _cocostudio_ActionMoveFrame___olua_move);
    oluacls_func(L, "getPosition", _cocostudio_ActionMoveFrame_getPosition);
    oluacls_func(L, "new", _cocostudio_ActionMoveFrame_new);
    oluacls_func(L, "setPosition", _cocostudio_ActionMoveFrame_setPosition);
    oluacls_prop(L, "position", _cocostudio_ActionMoveFrame_getPosition, _cocostudio_ActionMoveFrame_setPosition);

    olua_registerluatype<cocostudio::ActionMoveFrame>(L, "ccs.ActionMoveFrame");

    return 1;
}

static int _cocostudio_ActionRotationFrame___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocostudio::ActionRotationFrame *)olua_toobj(L, 1, "ccs.ActionRotationFrame");
    olua_push_cppobj(L, self, "ccs.ActionRotationFrame");

    olua_endinvoke(L);

    return 1;
}

static int _cocostudio_ActionRotationFrame_getRotation(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ActionRotationFrame *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ActionRotationFrame");

    // float getRotation()
    float ret = self->getRotation();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ActionRotationFrame_new(lua_State *L)
{
    olua_startinvoke(L);

    // ActionRotationFrame()
    cocostudio::ActionRotationFrame *ret = new cocostudio::ActionRotationFrame();
    int num_ret = olua_push_cppobj(L, ret, "ccs.ActionRotationFrame");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ActionRotationFrame_setRotation(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ActionRotationFrame *self = nullptr;
    lua_Number arg1 = 0;       /** rotation */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ActionRotationFrame");
    olua_check_number(L, 2, &arg1);

    // void setRotation(float rotation)
    self->setRotation((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocostudio_ActionRotationFrame(lua_State *L)
{
    oluacls_class(L, "ccs.ActionRotationFrame", "ccs.ActionFrame");
    oluacls_func(L, "__olua_move", _cocostudio_ActionRotationFrame___olua_move);
    oluacls_func(L, "getRotation", _cocostudio_ActionRotationFrame_getRotation);
    oluacls_func(L, "new", _cocostudio_ActionRotationFrame_new);
    oluacls_func(L, "setRotation", _cocostudio_ActionRotationFrame_setRotation);
    oluacls_prop(L, "rotation", _cocostudio_ActionRotationFrame_getRotation, _cocostudio_ActionRotationFrame_setRotation);

    olua_registerluatype<cocostudio::ActionRotationFrame>(L, "ccs.ActionRotationFrame");

    return 1;
}

static int _cocostudio_ActionScaleFrame___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocostudio::ActionScaleFrame *)olua_toobj(L, 1, "ccs.ActionScaleFrame");
    olua_push_cppobj(L, self, "ccs.ActionScaleFrame");

    olua_endinvoke(L);

    return 1;
}

static int _cocostudio_ActionScaleFrame_getScaleX(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ActionScaleFrame *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ActionScaleFrame");

    // float getScaleX()
    float ret = self->getScaleX();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ActionScaleFrame_getScaleY(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ActionScaleFrame *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ActionScaleFrame");

    // float getScaleY()
    float ret = self->getScaleY();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ActionScaleFrame_new(lua_State *L)
{
    olua_startinvoke(L);

    // ActionScaleFrame()
    cocostudio::ActionScaleFrame *ret = new cocostudio::ActionScaleFrame();
    int num_ret = olua_push_cppobj(L, ret, "ccs.ActionScaleFrame");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ActionScaleFrame_setScaleX(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ActionScaleFrame *self = nullptr;
    lua_Number arg1 = 0;       /** scaleX */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ActionScaleFrame");
    olua_check_number(L, 2, &arg1);

    // void setScaleX(float scaleX)
    self->setScaleX((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ActionScaleFrame_setScaleY(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ActionScaleFrame *self = nullptr;
    lua_Number arg1 = 0;       /** scaleY */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ActionScaleFrame");
    olua_check_number(L, 2, &arg1);

    // void setScaleY(float scaleY)
    self->setScaleY((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocostudio_ActionScaleFrame(lua_State *L)
{
    oluacls_class(L, "ccs.ActionScaleFrame", "ccs.ActionFrame");
    oluacls_func(L, "__olua_move", _cocostudio_ActionScaleFrame___olua_move);
    oluacls_func(L, "getScaleX", _cocostudio_ActionScaleFrame_getScaleX);
    oluacls_func(L, "getScaleY", _cocostudio_ActionScaleFrame_getScaleY);
    oluacls_func(L, "new", _cocostudio_ActionScaleFrame_new);
    oluacls_func(L, "setScaleX", _cocostudio_ActionScaleFrame_setScaleX);
    oluacls_func(L, "setScaleY", _cocostudio_ActionScaleFrame_setScaleY);
    oluacls_prop(L, "scaleX", _cocostudio_ActionScaleFrame_getScaleX, _cocostudio_ActionScaleFrame_setScaleX);
    oluacls_prop(L, "scaleY", _cocostudio_ActionScaleFrame_getScaleY, _cocostudio_ActionScaleFrame_setScaleY);

    olua_registerluatype<cocostudio::ActionScaleFrame>(L, "ccs.ActionScaleFrame");

    return 1;
}

static int _cocostudio_ActionTintFrame___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocostudio::ActionTintFrame *)olua_toobj(L, 1, "ccs.ActionTintFrame");
    olua_push_cppobj(L, self, "ccs.ActionTintFrame");

    olua_endinvoke(L);

    return 1;
}

static int _cocostudio_ActionTintFrame_getColor(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ActionTintFrame *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ActionTintFrame");

    // cocos2d::Color3B getColor()
    cocos2d::Color3B ret = self->getColor();
    int num_ret = olua_push_cocos2d_Color3B(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ActionTintFrame_new(lua_State *L)
{
    olua_startinvoke(L);

    // ActionTintFrame()
    cocostudio::ActionTintFrame *ret = new cocostudio::ActionTintFrame();
    int num_ret = olua_push_cppobj(L, ret, "ccs.ActionTintFrame");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ActionTintFrame_setColor(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ActionTintFrame *self = nullptr;
    cocos2d::Color3B arg1;       /** ccolor */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ActionTintFrame");
    olua_check_cocos2d_Color3B(L, 2, &arg1);

    // void setColor(cocos2d::Color3B ccolor)
    self->setColor(arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocostudio_ActionTintFrame(lua_State *L)
{
    oluacls_class(L, "ccs.ActionTintFrame", "ccs.ActionFrame");
    oluacls_func(L, "__olua_move", _cocostudio_ActionTintFrame___olua_move);
    oluacls_func(L, "getColor", _cocostudio_ActionTintFrame_getColor);
    oluacls_func(L, "new", _cocostudio_ActionTintFrame_new);
    oluacls_func(L, "setColor", _cocostudio_ActionTintFrame_setColor);
    oluacls_prop(L, "color", _cocostudio_ActionTintFrame_getColor, _cocostudio_ActionTintFrame_setColor);

    olua_registerluatype<cocostudio::ActionTintFrame>(L, "ccs.ActionTintFrame");

    return 1;
}

static int _cocostudio_AnimationData___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocostudio::AnimationData *)olua_toobj(L, 1, "ccs.AnimationData");
    olua_push_cppobj(L, self, "ccs.AnimationData");

    olua_endinvoke(L);

    return 1;
}

static int _cocostudio_AnimationData_addMovement(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::AnimationData *self = nullptr;
    cocostudio::MovementData *arg1 = nullptr;       /** movData */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.AnimationData");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccs.MovementData");

    // void addMovement(cocostudio::MovementData *movData)
    self->addMovement(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_AnimationData_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cocostudio::AnimationData *create()
    cocostudio::AnimationData *ret = cocostudio::AnimationData::create();
    int num_ret = olua_push_cppobj(L, ret, "ccs.AnimationData");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_AnimationData_getMovement(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::AnimationData *self = nullptr;
    std::string arg1;       /** movementName */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.AnimationData");
    olua_check_std_string(L, 2, &arg1);

    // cocostudio::MovementData *getMovement(const std::string &movementName)
    cocostudio::MovementData *ret = self->getMovement(arg1);
    int num_ret = olua_push_cppobj(L, ret, "ccs.MovementData");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_AnimationData_getMovementCount(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::AnimationData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.AnimationData");

    // ssize_t getMovementCount()
    ssize_t ret = self->getMovementCount();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_AnimationData_new(lua_State *L)
{
    olua_startinvoke(L);

    // AnimationData()
    cocostudio::AnimationData *ret = new cocostudio::AnimationData();
    int num_ret = olua_push_cppobj(L, ret, "ccs.AnimationData");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_AnimationData_get_movementDataDic(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::AnimationData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.AnimationData");

    // cocos2d::Map<std::string, MovementData *> movementDataDic
    cocos2d::Map<std::string, cocostudio::MovementData *> ret = self->movementDataDic;
    int num_ret = olua_push_cocos2d_Map<std::string, cocostudio::MovementData *>(L, &ret, [L](std::string arg1, cocostudio::MovementData *arg2) {
        olua_push_std_string(L, (std::string)arg1);
        olua_push_cppobj(L, arg2, "ccs.MovementData");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_AnimationData_set_movementDataDic(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::AnimationData *self = nullptr;
    cocos2d::Map<std::string, cocostudio::MovementData *> arg1;       /** movementDataDic */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.AnimationData");
    olua_check_cocos2d_Map<std::string, cocostudio::MovementData *>(L, 2, &arg1, [L](std::string *arg1, cocostudio::MovementData **arg2) {
        olua_check_std_string(L, -1, arg1);
        olua_check_cppobj(L, -2, (void **)arg2, "ccs.MovementData");
    });

    // cocos2d::Map<std::string, MovementData *> movementDataDic
    self->movementDataDic = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_AnimationData_get_movementNames(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::AnimationData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.AnimationData");

    // std::vector<std::string> movementNames
    std::vector<std::string> ret = self->movementNames;
    int num_ret = olua_push_std_vector<std::string>(L, &ret, [L](std::string value) {
        olua_push_std_string(L, (std::string)value);
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_AnimationData_set_movementNames(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::AnimationData *self = nullptr;
    std::vector<std::string> arg1;       /** movementNames */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.AnimationData");
    olua_check_std_vector<std::string>(L, 2, &arg1, [L](std::string *value) {
        olua_check_std_string(L, -1, value);
    });

    // std::vector<std::string> movementNames
    self->movementNames = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_AnimationData_get_name(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::AnimationData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.AnimationData");

    // std::string name
    std::string ret = self->name;
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_AnimationData_set_name(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::AnimationData *self = nullptr;
    std::string arg1;       /** name */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.AnimationData");
    olua_check_std_string(L, 2, &arg1);

    // std::string name
    self->name = arg1;

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocostudio_AnimationData(lua_State *L)
{
    oluacls_class(L, "ccs.AnimationData", "cc.Ref");
    oluacls_func(L, "__olua_move", _cocostudio_AnimationData___olua_move);
    oluacls_func(L, "addMovement", _cocostudio_AnimationData_addMovement);
    oluacls_func(L, "create", _cocostudio_AnimationData_create);
    oluacls_func(L, "getMovement", _cocostudio_AnimationData_getMovement);
    oluacls_func(L, "getMovementCount", _cocostudio_AnimationData_getMovementCount);
    oluacls_func(L, "new", _cocostudio_AnimationData_new);
    oluacls_prop(L, "movementCount", _cocostudio_AnimationData_getMovementCount, nullptr);
    oluacls_prop(L, "movementDataDic", _cocostudio_AnimationData_get_movementDataDic, _cocostudio_AnimationData_set_movementDataDic);
    oluacls_prop(L, "movementNames", _cocostudio_AnimationData_get_movementNames, _cocostudio_AnimationData_set_movementNames);
    oluacls_prop(L, "name", _cocostudio_AnimationData_get_name, _cocostudio_AnimationData_set_name);

    olua_registerluatype<cocostudio::AnimationData>(L, "ccs.AnimationData");

    return 1;
}

static int _cocostudio_Armature___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocostudio::Armature *)olua_toobj(L, 1, "ccs.Armature");
    olua_push_cppobj(L, self, "ccs.Armature");

    olua_endinvoke(L);

    return 1;
}

static int _cocostudio_Armature_addBone(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Armature *self = nullptr;
    cocostudio::Bone *arg1 = nullptr;       /** bone */
    std::string arg2;       /** parentName */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Armature");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccs.Bone");
    olua_check_std_string(L, 3, &arg2);

    // void addBone(cocostudio::Bone *bone, const std::string &parentName)
    self->addBone(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_Armature_changeBoneParent(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Armature *self = nullptr;
    cocostudio::Bone *arg1 = nullptr;       /** bone */
    std::string arg2;       /** parentName */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Armature");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccs.Bone");
    olua_check_std_string(L, 3, &arg2);

    // void changeBoneParent(cocostudio::Bone *bone, const std::string &parentName)
    self->changeBoneParent(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_Armature_create1(lua_State *L)
{
    olua_startinvoke(L);

    // static cocostudio::Armature *create()
    cocostudio::Armature *ret = cocostudio::Armature::create();
    int num_ret = olua_push_cppobj(L, ret, "ccs.Armature");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_Armature_create2(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** name */

    olua_check_std_string(L, 1, &arg1);

    // static cocostudio::Armature *create(const std::string &name)
    cocostudio::Armature *ret = cocostudio::Armature::create(arg1);
    int num_ret = olua_push_cppobj(L, ret, "ccs.Armature");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_Armature_create3(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** name */
    cocostudio::Bone *arg2 = nullptr;       /** parentBone */

    olua_check_std_string(L, 1, &arg1);
    olua_check_cppobj(L, 2, (void **)&arg2, "ccs.Bone");

    // static cocostudio::Armature *create(const std::string &name, cocostudio::Bone *parentBone)
    cocostudio::Armature *ret = cocostudio::Armature::create(arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "ccs.Armature");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_Armature_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // static cocostudio::Armature *create()
        return _cocostudio_Armature_create1(L);
    }

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 1))) {
            // static cocostudio::Armature *create(const std::string &name)
            return _cocostudio_Armature_create2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 1)) && (olua_is_cppobj(L, 2, "ccs.Bone"))) {
            // static cocostudio::Armature *create(const std::string &name, cocostudio::Bone *parentBone)
            return _cocostudio_Armature_create3(L);
        // }
    }

    luaL_error(L, "method 'cocostudio::Armature::create' not support '%d' arguments", num_args);

    return 0;
}

static int _cocostudio_Armature_getAnimation(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Armature *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Armature");

    // cocostudio::ArmatureAnimation *getAnimation()
    cocostudio::ArmatureAnimation *ret = self->getAnimation();
    int num_ret = olua_push_cppobj(L, ret, "ccs.ArmatureAnimation");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_Armature_getArmatureData(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Armature *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Armature");

    // cocostudio::ArmatureData *getArmatureData()
    cocostudio::ArmatureData *ret = self->getArmatureData();
    int num_ret = olua_push_cppobj(L, ret, "ccs.ArmatureData");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_Armature_getArmatureTransformDirty(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Armature *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Armature");

    // bool getArmatureTransformDirty()
    bool ret = self->getArmatureTransformDirty();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_Armature_getBatchNode(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Armature *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Armature");

    // cocostudio::BatchNode *getBatchNode()
    cocostudio::BatchNode *ret = self->getBatchNode();
    int num_ret = olua_push_cppobj(L, ret, "ccs.BatchNode");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_Armature_getBlendFunc(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Armature *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Armature");

    // const cocos2d::BlendFunc &getBlendFunc()
    const cocos2d::BlendFunc &ret = self->getBlendFunc();
    int num_ret = olua_push_cocos2d_BlendFunc(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_Armature_getBone(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Armature *self = nullptr;
    std::string arg1;       /** name */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Armature");
    olua_check_std_string(L, 2, &arg1);

    // cocostudio::Bone *getBone(const std::string &name)
    cocostudio::Bone *ret = self->getBone(arg1);
    int num_ret = olua_push_cppobj(L, ret, "ccs.Bone");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_Armature_getBoneAtPoint(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Armature *self = nullptr;
    lua_Number arg1 = 0;       /** x */
    lua_Number arg2 = 0;       /** y */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Armature");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);

    // cocostudio::Bone *getBoneAtPoint(float x, float y)
    cocostudio::Bone *ret = self->getBoneAtPoint((float)arg1, (float)arg2);
    int num_ret = olua_push_cppobj(L, ret, "ccs.Bone");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_Armature_getBoneDic(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Armature *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Armature");

    // const cocos2d::Map<std::string, Bone *> &getBoneDic()
    const cocos2d::Map<std::string, cocostudio::Bone *> &ret = self->getBoneDic();
    int num_ret = olua_push_cocos2d_Map<std::string, cocostudio::Bone *>(L, &ret, [L](std::string arg1, cocostudio::Bone *arg2) {
        olua_push_std_string(L, (std::string)arg1);
        olua_push_cppobj(L, arg2, "ccs.Bone");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_Armature_getOffsetPoints(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Armature *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Armature");

    // const cocos2d::Vec2 &getOffsetPoints()
    const cocos2d::Vec2 &ret = self->getOffsetPoints();
    int num_ret = olua_push_cocos2d_Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_Armature_getParentBone(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Armature *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Armature");

    // cocostudio::Bone *getParentBone()
    cocostudio::Bone *ret = self->getParentBone();
    int num_ret = olua_push_cppobj(L, ret, "ccs.Bone");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_Armature_getVersion(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Armature *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Armature");

    // float getVersion()
    float ret = self->getVersion();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_Armature_init1(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Armature *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Armature");

    // @using bool init()
    bool ret = self->init();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_Armature_init2(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Armature *self = nullptr;
    std::string arg1;       /** name */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Armature");
    olua_check_std_string(L, 2, &arg1);

    // bool init(const std::string &name)
    bool ret = self->init(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_Armature_init3(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Armature *self = nullptr;
    std::string arg1;       /** name */
    cocostudio::Bone *arg2 = nullptr;       /** parentBone */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Armature");
    olua_check_std_string(L, 2, &arg1);
    olua_check_cppobj(L, 3, (void **)&arg2, "ccs.Bone");

    // bool init(const std::string &name, cocostudio::Bone *parentBone)
    bool ret = self->init(arg1, arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_Armature_init(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // @using bool init()
        return _cocostudio_Armature_init1(L);
    }

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 2))) {
            // bool init(const std::string &name)
            return _cocostudio_Armature_init2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_cppobj(L, 3, "ccs.Bone"))) {
            // bool init(const std::string &name, cocostudio::Bone *parentBone)
            return _cocostudio_Armature_init3(L);
        // }
    }

    luaL_error(L, "method 'cocostudio::Armature::init' not support '%d' arguments", num_args);

    return 0;
}

static int _cocostudio_Armature_new(lua_State *L)
{
    olua_startinvoke(L);

    // Armature()
    cocostudio::Armature *ret = new cocostudio::Armature();
    int num_ret = olua_push_cppobj(L, ret, "ccs.Armature");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_Armature_removeBone(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Armature *self = nullptr;
    cocostudio::Bone *arg1 = nullptr;       /** bone */
    bool arg2 = false;       /** recursion */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Armature");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccs.Bone");
    olua_check_bool(L, 3, &arg2);

    // void removeBone(cocostudio::Bone *bone, bool recursion)
    self->removeBone(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_Armature_setAnimation(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Armature *self = nullptr;
    cocostudio::ArmatureAnimation *arg1 = nullptr;       /** animation */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Armature");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccs.ArmatureAnimation");

    // void setAnimation(cocostudio::ArmatureAnimation *animation)
    self->setAnimation(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_Armature_setArmatureData(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Armature *self = nullptr;
    cocostudio::ArmatureData *arg1 = nullptr;       /** armatureData */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Armature");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccs.ArmatureData");

    // void setArmatureData(cocostudio::ArmatureData *armatureData)
    self->setArmatureData(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_Armature_setBatchNode(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Armature *self = nullptr;
    cocostudio::BatchNode *arg1 = nullptr;       /** batchNode */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Armature");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccs.BatchNode");

    // void setBatchNode(cocostudio::BatchNode *batchNode)
    self->setBatchNode(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_Armature_setBlendFunc(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Armature *self = nullptr;
    cocos2d::BlendFunc arg1;       /** blendFunc */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Armature");
    olua_check_cocos2d_BlendFunc(L, 2, &arg1);

    // void setBlendFunc(const cocos2d::BlendFunc &blendFunc)
    self->setBlendFunc(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_Armature_setParentBone(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Armature *self = nullptr;
    cocostudio::Bone *arg1 = nullptr;       /** parentBone */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Armature");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccs.Bone");

    // void setParentBone(cocostudio::Bone *parentBone)
    self->setParentBone(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_Armature_setVersion(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Armature *self = nullptr;
    lua_Number arg1 = 0;       /** version */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Armature");
    olua_check_number(L, 2, &arg1);

    // void setVersion(float version)
    self->setVersion((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_Armature_updateOffsetPoint(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Armature *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Armature");

    // void updateOffsetPoint()
    self->updateOffsetPoint();

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocostudio_Armature(lua_State *L)
{
    oluacls_class(L, "ccs.Armature", "cc.Node");
    oluacls_func(L, "__olua_move", _cocostudio_Armature___olua_move);
    oluacls_func(L, "addBone", _cocostudio_Armature_addBone);
    oluacls_func(L, "changeBoneParent", _cocostudio_Armature_changeBoneParent);
    oluacls_func(L, "create", _cocostudio_Armature_create);
    oluacls_func(L, "getAnimation", _cocostudio_Armature_getAnimation);
    oluacls_func(L, "getArmatureData", _cocostudio_Armature_getArmatureData);
    oluacls_func(L, "getArmatureTransformDirty", _cocostudio_Armature_getArmatureTransformDirty);
    oluacls_func(L, "getBatchNode", _cocostudio_Armature_getBatchNode);
    oluacls_func(L, "getBlendFunc", _cocostudio_Armature_getBlendFunc);
    oluacls_func(L, "getBone", _cocostudio_Armature_getBone);
    oluacls_func(L, "getBoneAtPoint", _cocostudio_Armature_getBoneAtPoint);
    oluacls_func(L, "getBoneDic", _cocostudio_Armature_getBoneDic);
    oluacls_func(L, "getOffsetPoints", _cocostudio_Armature_getOffsetPoints);
    oluacls_func(L, "getParentBone", _cocostudio_Armature_getParentBone);
    oluacls_func(L, "getVersion", _cocostudio_Armature_getVersion);
    oluacls_func(L, "init", _cocostudio_Armature_init);
    oluacls_func(L, "new", _cocostudio_Armature_new);
    oluacls_func(L, "removeBone", _cocostudio_Armature_removeBone);
    oluacls_func(L, "setAnimation", _cocostudio_Armature_setAnimation);
    oluacls_func(L, "setArmatureData", _cocostudio_Armature_setArmatureData);
    oluacls_func(L, "setBatchNode", _cocostudio_Armature_setBatchNode);
    oluacls_func(L, "setBlendFunc", _cocostudio_Armature_setBlendFunc);
    oluacls_func(L, "setParentBone", _cocostudio_Armature_setParentBone);
    oluacls_func(L, "setVersion", _cocostudio_Armature_setVersion);
    oluacls_func(L, "updateOffsetPoint", _cocostudio_Armature_updateOffsetPoint);
    oluacls_prop(L, "animation", _cocostudio_Armature_getAnimation, _cocostudio_Armature_setAnimation);
    oluacls_prop(L, "armatureData", _cocostudio_Armature_getArmatureData, _cocostudio_Armature_setArmatureData);
    oluacls_prop(L, "armatureTransformDirty", _cocostudio_Armature_getArmatureTransformDirty, nullptr);
    oluacls_prop(L, "batchNode", _cocostudio_Armature_getBatchNode, _cocostudio_Armature_setBatchNode);
    oluacls_prop(L, "blendFunc", _cocostudio_Armature_getBlendFunc, _cocostudio_Armature_setBlendFunc);
    oluacls_prop(L, "boneDic", _cocostudio_Armature_getBoneDic, nullptr);
    oluacls_prop(L, "offsetPoints", _cocostudio_Armature_getOffsetPoints, nullptr);
    oluacls_prop(L, "parentBone", _cocostudio_Armature_getParentBone, _cocostudio_Armature_setParentBone);
    oluacls_prop(L, "version", _cocostudio_Armature_getVersion, _cocostudio_Armature_setVersion);

    olua_registerluatype<cocostudio::Armature>(L, "ccs.Armature");

    return 1;
}

static int _cocostudio_ProcessBase___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocostudio::ProcessBase *)olua_toobj(L, 1, "ccs.ProcessBase");
    olua_push_cppobj(L, self, "ccs.ProcessBase");

    olua_endinvoke(L);

    return 1;
}

static int _cocostudio_ProcessBase_getCurrentFrameIndex(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ProcessBase *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ProcessBase");

    // int getCurrentFrameIndex()
    int ret = self->getCurrentFrameIndex();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ProcessBase_getCurrentPercent(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ProcessBase *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ProcessBase");

    // float getCurrentPercent()
    float ret = self->getCurrentPercent();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ProcessBase_getProcessScale(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ProcessBase *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ProcessBase");

    // float getProcessScale()
    float ret = self->getProcessScale();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ProcessBase_getRawDuration(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ProcessBase *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ProcessBase");

    // int getRawDuration()
    int ret = self->getRawDuration();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ProcessBase_isComplete(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ProcessBase *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ProcessBase");

    // bool isComplete()
    bool ret = self->isComplete();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ProcessBase_isPause(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ProcessBase *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ProcessBase");

    // bool isPause()
    bool ret = self->isPause();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ProcessBase_isPlaying(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ProcessBase *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ProcessBase");

    // bool isPlaying()
    bool ret = self->isPlaying();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ProcessBase_new(lua_State *L)
{
    olua_startinvoke(L);

    // ProcessBase()
    cocostudio::ProcessBase *ret = new cocostudio::ProcessBase();
    int num_ret = olua_push_cppobj(L, ret, "ccs.ProcessBase");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ProcessBase_pause(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ProcessBase *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ProcessBase");

    // void pause()
    self->pause();

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ProcessBase_play(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ProcessBase *self = nullptr;
    lua_Integer arg1 = 0;       /** durationTo */
    lua_Integer arg2 = 0;       /** durationTween */
    lua_Integer arg3 = 0;       /** loop */
    lua_Integer arg4 = 0;       /** tweenEasing */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ProcessBase");
    olua_check_int(L, 2, &arg1);
    olua_check_int(L, 3, &arg2);
    olua_check_int(L, 4, &arg3);
    olua_check_int(L, 5, &arg4);

    // void play(int durationTo, int durationTween, int loop, int tweenEasing)
    self->play((int)arg1, (int)arg2, (int)arg3, (int)arg4);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ProcessBase_resume(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ProcessBase *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ProcessBase");

    // void resume()
    self->resume();

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ProcessBase_setIsComplete(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ProcessBase *self = nullptr;
    bool arg1 = false;       /** complete */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ProcessBase");
    olua_check_bool(L, 2, &arg1);

    // void setIsComplete(bool complete)
    self->setIsComplete(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ProcessBase_setIsPause(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ProcessBase *self = nullptr;
    bool arg1 = false;       /** pause */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ProcessBase");
    olua_check_bool(L, 2, &arg1);

    // void setIsPause(bool pause)
    self->setIsPause(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ProcessBase_setIsPlaying(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ProcessBase *self = nullptr;
    bool arg1 = false;       /** playing */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ProcessBase");
    olua_check_bool(L, 2, &arg1);

    // void setIsPlaying(bool playing)
    self->setIsPlaying(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ProcessBase_setProcessScale(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ProcessBase *self = nullptr;
    lua_Number arg1 = 0;       /** processScale */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ProcessBase");
    olua_check_number(L, 2, &arg1);

    // void setProcessScale(float processScale)
    self->setProcessScale((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ProcessBase_stop(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ProcessBase *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ProcessBase");

    // void stop()
    self->stop();

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ProcessBase_update(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ProcessBase *self = nullptr;
    lua_Number arg1 = 0;       /** dt */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ProcessBase");
    olua_check_number(L, 2, &arg1);

    // void update(float dt)
    self->update((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocostudio_ProcessBase(lua_State *L)
{
    oluacls_class(L, "ccs.ProcessBase", "cc.Ref");
    oluacls_func(L, "__olua_move", _cocostudio_ProcessBase___olua_move);
    oluacls_func(L, "getCurrentFrameIndex", _cocostudio_ProcessBase_getCurrentFrameIndex);
    oluacls_func(L, "getCurrentPercent", _cocostudio_ProcessBase_getCurrentPercent);
    oluacls_func(L, "getProcessScale", _cocostudio_ProcessBase_getProcessScale);
    oluacls_func(L, "getRawDuration", _cocostudio_ProcessBase_getRawDuration);
    oluacls_func(L, "isComplete", _cocostudio_ProcessBase_isComplete);
    oluacls_func(L, "isPause", _cocostudio_ProcessBase_isPause);
    oluacls_func(L, "isPlaying", _cocostudio_ProcessBase_isPlaying);
    oluacls_func(L, "new", _cocostudio_ProcessBase_new);
    oluacls_func(L, "pause", _cocostudio_ProcessBase_pause);
    oluacls_func(L, "play", _cocostudio_ProcessBase_play);
    oluacls_func(L, "resume", _cocostudio_ProcessBase_resume);
    oluacls_func(L, "setIsComplete", _cocostudio_ProcessBase_setIsComplete);
    oluacls_func(L, "setIsPause", _cocostudio_ProcessBase_setIsPause);
    oluacls_func(L, "setIsPlaying", _cocostudio_ProcessBase_setIsPlaying);
    oluacls_func(L, "setProcessScale", _cocostudio_ProcessBase_setProcessScale);
    oluacls_func(L, "stop", _cocostudio_ProcessBase_stop);
    oluacls_func(L, "update", _cocostudio_ProcessBase_update);
    oluacls_prop(L, "complete", _cocostudio_ProcessBase_isComplete, nullptr);
    oluacls_prop(L, "currentFrameIndex", _cocostudio_ProcessBase_getCurrentFrameIndex, nullptr);
    oluacls_prop(L, "currentPercent", _cocostudio_ProcessBase_getCurrentPercent, nullptr);
    oluacls_prop(L, "pause", _cocostudio_ProcessBase_isPause, nullptr);
    oluacls_prop(L, "playing", _cocostudio_ProcessBase_isPlaying, nullptr);
    oluacls_prop(L, "processScale", _cocostudio_ProcessBase_getProcessScale, _cocostudio_ProcessBase_setProcessScale);
    oluacls_prop(L, "rawDuration", _cocostudio_ProcessBase_getRawDuration, nullptr);

    olua_registerluatype<cocostudio::ProcessBase>(L, "ccs.ProcessBase");

    return 1;
}

static int _cocostudio_ActionManagerEx___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocostudio::ActionManagerEx *)olua_toobj(L, 1, "ccs.ActionManagerEx");
    olua_push_cppobj(L, self, "ccs.ActionManagerEx");

    olua_endinvoke(L);

    return 1;
}

static int _cocostudio_ActionManagerEx_destroyInstance(lua_State *L)
{
    olua_startinvoke(L);

    // static void destroyInstance()
    cocostudio::ActionManagerEx::destroyInstance();

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ActionManagerEx_getActionByName(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ActionManagerEx *self = nullptr;
    const char *arg1 = nullptr;       /** jsonName */
    const char *arg2 = nullptr;       /** actionName */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ActionManagerEx");
    olua_check_string(L, 2, &arg1);
    olua_check_string(L, 3, &arg2);

    // cocostudio::ActionObject *getActionByName(const char *jsonName, const char *actionName)
    cocostudio::ActionObject *ret = self->getActionByName(arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "ccs.ActionObject");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ActionManagerEx_getInstance(lua_State *L)
{
    olua_startinvoke(L);

    // static cocostudio::ActionManagerEx *getInstance()
    cocostudio::ActionManagerEx *ret = cocostudio::ActionManagerEx::getInstance();
    int num_ret = olua_push_cppobj(L, ret, "ccs.ActionManagerEx");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ActionManagerEx_getStudioVersionNumber(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ActionManagerEx *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ActionManagerEx");

    // int getStudioVersionNumber()
    int ret = self->getStudioVersionNumber();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ActionManagerEx_new(lua_State *L)
{
    olua_startinvoke(L);

    // ActionManagerEx()
    cocostudio::ActionManagerEx *ret = new cocostudio::ActionManagerEx();
    int num_ret = olua_push_cppobj(L, ret, "ccs.ActionManagerEx");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ActionManagerEx_playActionByName1(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ActionManagerEx *self = nullptr;
    const char *arg1 = nullptr;       /** jsonName */
    const char *arg2 = nullptr;       /** actionName */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ActionManagerEx");
    olua_check_string(L, 2, &arg1);
    olua_check_string(L, 3, &arg2);

    // cocostudio::ActionObject *playActionByName(const char *jsonName, const char *actionName)
    cocostudio::ActionObject *ret = self->playActionByName(arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "ccs.ActionObject");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ActionManagerEx_playActionByName2(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ActionManagerEx *self = nullptr;
    const char *arg1 = nullptr;       /** jsonName */
    const char *arg2 = nullptr;       /** actionName */
    cocos2d::CallFunc *arg3 = nullptr;       /** func */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ActionManagerEx");
    olua_check_string(L, 2, &arg1);
    olua_check_string(L, 3, &arg2);
    olua_check_cppobj(L, 4, (void **)&arg3, "cc.CallFunc");

    // cocostudio::ActionObject *playActionByName(const char *jsonName, const char *actionName, cocos2d::CallFunc *func)
    cocostudio::ActionObject *ret = self->playActionByName(arg1, arg2, arg3);
    int num_ret = olua_push_cppobj(L, ret, "ccs.ActionObject");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ActionManagerEx_playActionByName(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 2) {
        // if ((olua_is_string(L, 2)) && (olua_is_string(L, 3))) {
            // cocostudio::ActionObject *playActionByName(const char *jsonName, const char *actionName)
            return _cocostudio_ActionManagerEx_playActionByName1(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_string(L, 2)) && (olua_is_string(L, 3)) && (olua_is_cppobj(L, 4, "cc.CallFunc"))) {
            // cocostudio::ActionObject *playActionByName(const char *jsonName, const char *actionName, cocos2d::CallFunc *func)
            return _cocostudio_ActionManagerEx_playActionByName2(L);
        // }
    }

    luaL_error(L, "method 'cocostudio::ActionManagerEx::playActionByName' not support '%d' arguments", num_args);

    return 0;
}

static int _cocostudio_ActionManagerEx_releaseActions(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ActionManagerEx *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ActionManagerEx");

    // void releaseActions()
    self->releaseActions();

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ActionManagerEx_stopActionByName(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ActionManagerEx *self = nullptr;
    const char *arg1 = nullptr;       /** jsonName */
    const char *arg2 = nullptr;       /** actionName */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ActionManagerEx");
    olua_check_string(L, 2, &arg1);
    olua_check_string(L, 3, &arg2);

    // cocostudio::ActionObject *stopActionByName(const char *jsonName, const char *actionName)
    cocostudio::ActionObject *ret = self->stopActionByName(arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "ccs.ActionObject");

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocostudio_ActionManagerEx(lua_State *L)
{
    oluacls_class(L, "ccs.ActionManagerEx", "cc.Ref");
    oluacls_func(L, "__olua_move", _cocostudio_ActionManagerEx___olua_move);
    oluacls_func(L, "destroyInstance", _cocostudio_ActionManagerEx_destroyInstance);
    oluacls_func(L, "getActionByName", _cocostudio_ActionManagerEx_getActionByName);
    oluacls_func(L, "getInstance", _cocostudio_ActionManagerEx_getInstance);
    oluacls_func(L, "getStudioVersionNumber", _cocostudio_ActionManagerEx_getStudioVersionNumber);
    oluacls_func(L, "new", _cocostudio_ActionManagerEx_new);
    oluacls_func(L, "playActionByName", _cocostudio_ActionManagerEx_playActionByName);
    oluacls_func(L, "releaseActions", _cocostudio_ActionManagerEx_releaseActions);
    oluacls_func(L, "stopActionByName", _cocostudio_ActionManagerEx_stopActionByName);
    oluacls_prop(L, "instance", _cocostudio_ActionManagerEx_getInstance, nullptr);
    oluacls_prop(L, "studioVersionNumber", _cocostudio_ActionManagerEx_getStudioVersionNumber, nullptr);

    olua_registerluatype<cocostudio::ActionManagerEx>(L, "ccs.ActionManagerEx");

    return 1;
}

static int _cocostudio_ActionNode___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocostudio::ActionNode *)olua_toobj(L, 1, "ccs.ActionNode");
    olua_push_cppobj(L, self, "ccs.ActionNode");

    olua_endinvoke(L);

    return 1;
}

static int _cocostudio_ActionNode_addFrame(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ActionNode *self = nullptr;
    cocostudio::ActionFrame *arg1 = nullptr;       /** frame */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ActionNode");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccs.ActionFrame");

    // void addFrame(cocostudio::ActionFrame *frame)
    self->addFrame(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ActionNode_clearAllFrame(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ActionNode *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ActionNode");

    // void clearAllFrame()
    self->clearAllFrame();

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ActionNode_deleteFrame(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ActionNode *self = nullptr;
    cocostudio::ActionFrame *arg1 = nullptr;       /** frame */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ActionNode");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccs.ActionFrame");

    // void deleteFrame(cocostudio::ActionFrame *frame)
    self->deleteFrame(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ActionNode_getActionTag(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ActionNode *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ActionNode");

    // int getActionTag()
    int ret = self->getActionTag();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ActionNode_getFirstFrameIndex(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ActionNode *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ActionNode");

    // int getFirstFrameIndex()
    int ret = self->getFirstFrameIndex();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ActionNode_getLastFrameIndex(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ActionNode *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ActionNode");

    // int getLastFrameIndex()
    int ret = self->getLastFrameIndex();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ActionNode_getObject(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ActionNode *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ActionNode");

    // cocos2d::Ref *getObject()
    cocos2d::Ref *ret = self->getObject();
    int num_ret = olua_push_cppobj(L, ret, "cc.Ref");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ActionNode_getUnitTime(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ActionNode *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ActionNode");

    // float getUnitTime()
    float ret = self->getUnitTime();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ActionNode_insertFrame(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ActionNode *self = nullptr;
    lua_Integer arg1 = 0;       /** index */
    cocostudio::ActionFrame *arg2 = nullptr;       /** frame */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ActionNode");
    olua_check_int(L, 2, &arg1);
    olua_check_cppobj(L, 3, (void **)&arg2, "ccs.ActionFrame");

    // void insertFrame(int index, cocostudio::ActionFrame *frame)
    self->insertFrame((int)arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ActionNode_isActionDoneOnce(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ActionNode *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ActionNode");

    // bool isActionDoneOnce()
    bool ret = self->isActionDoneOnce();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ActionNode_new(lua_State *L)
{
    olua_startinvoke(L);

    // ActionNode()
    cocostudio::ActionNode *ret = new cocostudio::ActionNode();
    int num_ret = olua_push_cppobj(L, ret, "ccs.ActionNode");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ActionNode_playAction(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ActionNode *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ActionNode");

    // void playAction()
    self->playAction();

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ActionNode_setActionTag(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ActionNode *self = nullptr;
    lua_Integer arg1 = 0;       /** tag */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ActionNode");
    olua_check_int(L, 2, &arg1);

    // void setActionTag(int tag)
    self->setActionTag((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ActionNode_setObject(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ActionNode *self = nullptr;
    cocos2d::Ref *arg1 = nullptr;       /** node */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ActionNode");
    olua_check_cppobj(L, 2, (void **)&arg1, "cc.Ref");

    // void setObject(cocos2d::Ref *node)
    self->setObject(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ActionNode_setUnitTime(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ActionNode *self = nullptr;
    lua_Number arg1 = 0;       /** fTime */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ActionNode");
    olua_check_number(L, 2, &arg1);

    // void setUnitTime(float fTime)
    self->setUnitTime((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ActionNode_stopAction(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ActionNode *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ActionNode");

    // void stopAction()
    self->stopAction();

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ActionNode_updateActionToTimeLine(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ActionNode *self = nullptr;
    lua_Number arg1 = 0;       /** fTime */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ActionNode");
    olua_check_number(L, 2, &arg1);

    // bool updateActionToTimeLine(float fTime)
    bool ret = self->updateActionToTimeLine((float)arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocostudio_ActionNode(lua_State *L)
{
    oluacls_class(L, "ccs.ActionNode", "cc.Ref");
    oluacls_func(L, "__olua_move", _cocostudio_ActionNode___olua_move);
    oluacls_func(L, "addFrame", _cocostudio_ActionNode_addFrame);
    oluacls_func(L, "clearAllFrame", _cocostudio_ActionNode_clearAllFrame);
    oluacls_func(L, "deleteFrame", _cocostudio_ActionNode_deleteFrame);
    oluacls_func(L, "getActionTag", _cocostudio_ActionNode_getActionTag);
    oluacls_func(L, "getFirstFrameIndex", _cocostudio_ActionNode_getFirstFrameIndex);
    oluacls_func(L, "getLastFrameIndex", _cocostudio_ActionNode_getLastFrameIndex);
    oluacls_func(L, "getObject", _cocostudio_ActionNode_getObject);
    oluacls_func(L, "getUnitTime", _cocostudio_ActionNode_getUnitTime);
    oluacls_func(L, "insertFrame", _cocostudio_ActionNode_insertFrame);
    oluacls_func(L, "isActionDoneOnce", _cocostudio_ActionNode_isActionDoneOnce);
    oluacls_func(L, "new", _cocostudio_ActionNode_new);
    oluacls_func(L, "playAction", _cocostudio_ActionNode_playAction);
    oluacls_func(L, "setActionTag", _cocostudio_ActionNode_setActionTag);
    oluacls_func(L, "setObject", _cocostudio_ActionNode_setObject);
    oluacls_func(L, "setUnitTime", _cocostudio_ActionNode_setUnitTime);
    oluacls_func(L, "stopAction", _cocostudio_ActionNode_stopAction);
    oluacls_func(L, "updateActionToTimeLine", _cocostudio_ActionNode_updateActionToTimeLine);
    oluacls_prop(L, "actionDoneOnce", _cocostudio_ActionNode_isActionDoneOnce, nullptr);
    oluacls_prop(L, "actionTag", _cocostudio_ActionNode_getActionTag, _cocostudio_ActionNode_setActionTag);
    oluacls_prop(L, "firstFrameIndex", _cocostudio_ActionNode_getFirstFrameIndex, nullptr);
    oluacls_prop(L, "lastFrameIndex", _cocostudio_ActionNode_getLastFrameIndex, nullptr);
    oluacls_prop(L, "object", _cocostudio_ActionNode_getObject, _cocostudio_ActionNode_setObject);
    oluacls_prop(L, "unitTime", _cocostudio_ActionNode_getUnitTime, _cocostudio_ActionNode_setUnitTime);

    olua_registerluatype<cocostudio::ActionNode>(L, "ccs.ActionNode");

    return 1;
}

static int _cocostudio_ActionObject___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocostudio::ActionObject *)olua_toobj(L, 1, "ccs.ActionObject");
    olua_push_cppobj(L, self, "ccs.ActionObject");

    olua_endinvoke(L);

    return 1;
}

static int _cocostudio_ActionObject_addActionNode(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ActionObject *self = nullptr;
    cocostudio::ActionNode *arg1 = nullptr;       /** node */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ActionObject");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccs.ActionNode");

    // void addActionNode(cocostudio::ActionNode *node)
    self->addActionNode(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ActionObject_getCurrentTime(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ActionObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ActionObject");

    // float getCurrentTime()
    float ret = self->getCurrentTime();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ActionObject_getLoop(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ActionObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ActionObject");

    // bool getLoop()
    bool ret = self->getLoop();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ActionObject_getName(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ActionObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ActionObject");

    // const char *getName()
    const char *ret = self->getName();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ActionObject_getTotalTime(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ActionObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ActionObject");

    // float getTotalTime()
    float ret = self->getTotalTime();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ActionObject_getUnitTime(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ActionObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ActionObject");

    // float getUnitTime()
    float ret = self->getUnitTime();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ActionObject_isPlaying(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ActionObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ActionObject");

    // bool isPlaying()
    bool ret = self->isPlaying();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ActionObject_new(lua_State *L)
{
    olua_startinvoke(L);

    // ActionObject()
    cocostudio::ActionObject *ret = new cocostudio::ActionObject();
    int num_ret = olua_push_cppobj(L, ret, "ccs.ActionObject");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ActionObject_pause(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ActionObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ActionObject");

    // void pause()
    self->pause();

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ActionObject_play1(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ActionObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ActionObject");

    // void play()
    self->play();

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ActionObject_play2(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ActionObject *self = nullptr;
    cocos2d::CallFunc *arg1 = nullptr;       /** func */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ActionObject");
    olua_check_cppobj(L, 2, (void **)&arg1, "cc.CallFunc");

    // void play(cocos2d::CallFunc *func)
    self->play(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ActionObject_play(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // void play()
        return _cocostudio_ActionObject_play1(L);
    }

    if (num_args == 1) {
        // if ((olua_is_cppobj(L, 2, "cc.CallFunc"))) {
            // void play(cocos2d::CallFunc *func)
            return _cocostudio_ActionObject_play2(L);
        // }
    }

    luaL_error(L, "method 'cocostudio::ActionObject::play' not support '%d' arguments", num_args);

    return 0;
}

static int _cocostudio_ActionObject_removeActionNode(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ActionObject *self = nullptr;
    cocostudio::ActionNode *arg1 = nullptr;       /** node */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ActionObject");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccs.ActionNode");

    // void removeActionNode(cocostudio::ActionNode *node)
    self->removeActionNode(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ActionObject_setCurrentTime(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ActionObject *self = nullptr;
    lua_Number arg1 = 0;       /** fTime */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ActionObject");
    olua_check_number(L, 2, &arg1);

    // void setCurrentTime(float fTime)
    self->setCurrentTime((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ActionObject_setLoop(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ActionObject *self = nullptr;
    bool arg1 = false;       /** bLoop */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ActionObject");
    olua_check_bool(L, 2, &arg1);

    // void setLoop(bool bLoop)
    self->setLoop(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ActionObject_setName(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ActionObject *self = nullptr;
    const char *arg1 = nullptr;       /** name */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ActionObject");
    olua_check_string(L, 2, &arg1);

    // void setName(const char *name)
    self->setName(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ActionObject_setUnitTime(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ActionObject *self = nullptr;
    lua_Number arg1 = 0;       /** fTime */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ActionObject");
    olua_check_number(L, 2, &arg1);

    // void setUnitTime(float fTime)
    self->setUnitTime((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ActionObject_simulationActionUpdate(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ActionObject *self = nullptr;
    lua_Number arg1 = 0;       /** dt */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ActionObject");
    olua_check_number(L, 2, &arg1);

    // void simulationActionUpdate(float dt)
    self->simulationActionUpdate((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ActionObject_stop(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ActionObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ActionObject");

    // void stop()
    self->stop();

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ActionObject_updateToFrameByTime(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ActionObject *self = nullptr;
    lua_Number arg1 = 0;       /** fTime */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ActionObject");
    olua_check_number(L, 2, &arg1);

    // void updateToFrameByTime(float fTime)
    self->updateToFrameByTime((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocostudio_ActionObject(lua_State *L)
{
    oluacls_class(L, "ccs.ActionObject", "cc.Ref");
    oluacls_func(L, "__olua_move", _cocostudio_ActionObject___olua_move);
    oluacls_func(L, "addActionNode", _cocostudio_ActionObject_addActionNode);
    oluacls_func(L, "getCurrentTime", _cocostudio_ActionObject_getCurrentTime);
    oluacls_func(L, "getLoop", _cocostudio_ActionObject_getLoop);
    oluacls_func(L, "getName", _cocostudio_ActionObject_getName);
    oluacls_func(L, "getTotalTime", _cocostudio_ActionObject_getTotalTime);
    oluacls_func(L, "getUnitTime", _cocostudio_ActionObject_getUnitTime);
    oluacls_func(L, "isPlaying", _cocostudio_ActionObject_isPlaying);
    oluacls_func(L, "new", _cocostudio_ActionObject_new);
    oluacls_func(L, "pause", _cocostudio_ActionObject_pause);
    oluacls_func(L, "play", _cocostudio_ActionObject_play);
    oluacls_func(L, "removeActionNode", _cocostudio_ActionObject_removeActionNode);
    oluacls_func(L, "setCurrentTime", _cocostudio_ActionObject_setCurrentTime);
    oluacls_func(L, "setLoop", _cocostudio_ActionObject_setLoop);
    oluacls_func(L, "setName", _cocostudio_ActionObject_setName);
    oluacls_func(L, "setUnitTime", _cocostudio_ActionObject_setUnitTime);
    oluacls_func(L, "simulationActionUpdate", _cocostudio_ActionObject_simulationActionUpdate);
    oluacls_func(L, "stop", _cocostudio_ActionObject_stop);
    oluacls_func(L, "updateToFrameByTime", _cocostudio_ActionObject_updateToFrameByTime);
    oluacls_prop(L, "currentTime", _cocostudio_ActionObject_getCurrentTime, _cocostudio_ActionObject_setCurrentTime);
    oluacls_prop(L, "loop", _cocostudio_ActionObject_getLoop, _cocostudio_ActionObject_setLoop);
    oluacls_prop(L, "name", _cocostudio_ActionObject_getName, _cocostudio_ActionObject_setName);
    oluacls_prop(L, "playing", _cocostudio_ActionObject_isPlaying, nullptr);
    oluacls_prop(L, "totalTime", _cocostudio_ActionObject_getTotalTime, nullptr);
    oluacls_prop(L, "unitTime", _cocostudio_ActionObject_getUnitTime, _cocostudio_ActionObject_setUnitTime);

    olua_registerluatype<cocostudio::ActionObject>(L, "ccs.ActionObject");

    return 1;
}

static int _cocostudio_ArmatureAnimation___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocostudio::ArmatureAnimation *)olua_toobj(L, 1, "ccs.ArmatureAnimation");
    olua_push_cppobj(L, self, "ccs.ArmatureAnimation");

    olua_endinvoke(L);

    return 1;
}

static int _cocostudio_ArmatureAnimation_create(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Armature *arg1 = nullptr;       /** armature */

    olua_check_cppobj(L, 1, (void **)&arg1, "ccs.Armature");

    // static cocostudio::ArmatureAnimation *create(cocostudio::Armature *armature)
    cocostudio::ArmatureAnimation *ret = cocostudio::ArmatureAnimation::create(arg1);
    int num_ret = olua_push_cppobj(L, ret, "ccs.ArmatureAnimation");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ArmatureAnimation_getAnimationData(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ArmatureAnimation *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ArmatureAnimation");

    // cocostudio::AnimationData *getAnimationData()
    cocostudio::AnimationData *ret = self->getAnimationData();
    int num_ret = olua_push_cppobj(L, ret, "ccs.AnimationData");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ArmatureAnimation_getCurrentMovementID(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ArmatureAnimation *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ArmatureAnimation");

    // std::string getCurrentMovementID()
    std::string ret = self->getCurrentMovementID();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ArmatureAnimation_getMovementCount(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ArmatureAnimation *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ArmatureAnimation");

    // ssize_t getMovementCount()
    ssize_t ret = self->getMovementCount();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ArmatureAnimation_getSpeedScale(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ArmatureAnimation *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ArmatureAnimation");

    // float getSpeedScale()
    float ret = self->getSpeedScale();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ArmatureAnimation_getUserObject(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ArmatureAnimation *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ArmatureAnimation");

    // cocos2d::Ref *getUserObject()
    cocos2d::Ref *ret = self->getUserObject();
    int num_ret = olua_push_cppobj(L, ret, "cc.Ref");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ArmatureAnimation_gotoAndPause(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ArmatureAnimation *self = nullptr;
    lua_Integer arg1 = 0;       /** frameIndex */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ArmatureAnimation");
    olua_check_int(L, 2, &arg1);

    // void gotoAndPause(int frameIndex)
    self->gotoAndPause((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ArmatureAnimation_gotoAndPlay(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ArmatureAnimation *self = nullptr;
    lua_Integer arg1 = 0;       /** frameIndex */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ArmatureAnimation");
    olua_check_int(L, 2, &arg1);

    // void gotoAndPlay(int frameIndex)
    self->gotoAndPlay((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ArmatureAnimation_init(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ArmatureAnimation *self = nullptr;
    cocostudio::Armature *arg1 = nullptr;       /** armature */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ArmatureAnimation");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccs.Armature");

    // bool init(cocostudio::Armature *armature)
    bool ret = self->init(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ArmatureAnimation_new(lua_State *L)
{
    olua_startinvoke(L);

    // ArmatureAnimation()
    cocostudio::ArmatureAnimation *ret = new cocostudio::ArmatureAnimation();
    int num_ret = olua_push_cppobj(L, ret, "ccs.ArmatureAnimation");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ArmatureAnimation_play1(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ArmatureAnimation *self = nullptr;
    std::string arg1;       /** animationName */
    lua_Integer arg2 = 0;       /** durationTo */
    lua_Integer arg3 = 0;       /** loop */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ArmatureAnimation");
    olua_check_std_string(L, 2, &arg1);
    olua_check_int(L, 3, &arg2);
    olua_check_int(L, 4, &arg3);

    // void play(const std::string &animationName, @optional int durationTo, @optional int loop)
    self->play(arg1, (int)arg2, (int)arg3);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ArmatureAnimation_play2(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ArmatureAnimation *self = nullptr;
    lua_Integer arg1 = 0;       /** durationTo */
    lua_Integer arg2 = 0;       /** durationTween */
    lua_Integer arg3 = 0;       /** loop */
    lua_Integer arg4 = 0;       /** tweenEasing */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ArmatureAnimation");
    olua_check_int(L, 2, &arg1);
    olua_check_int(L, 3, &arg2);
    olua_check_int(L, 4, &arg3);
    olua_check_int(L, 5, &arg4);

    // @using void play(int durationTo, int durationTween, int loop, int tweenEasing)
    self->play((int)arg1, (int)arg2, (int)arg3, (int)arg4);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ArmatureAnimation_play3(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ArmatureAnimation *self = nullptr;
    std::string arg1;       /** animationName */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ArmatureAnimation");
    olua_check_std_string(L, 2, &arg1);

    // void play(const std::string &animationName, @optional int durationTo, @optional int loop)
    self->play(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ArmatureAnimation_play4(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ArmatureAnimation *self = nullptr;
    std::string arg1;       /** animationName */
    lua_Integer arg2 = 0;       /** durationTo */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ArmatureAnimation");
    olua_check_std_string(L, 2, &arg1);
    olua_check_int(L, 3, &arg2);

    // void play(const std::string &animationName, @optional int durationTo, @optional int loop)
    self->play(arg1, (int)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ArmatureAnimation_play(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 2))) {
            // void play(const std::string &animationName, @optional int durationTo, @optional int loop)
            return _cocostudio_ArmatureAnimation_play3(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_int(L, 3))) {
            // void play(const std::string &animationName, @optional int durationTo, @optional int loop)
            return _cocostudio_ArmatureAnimation_play4(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_int(L, 3)) && (olua_is_int(L, 4))) {
            // void play(const std::string &animationName, @optional int durationTo, @optional int loop)
            return _cocostudio_ArmatureAnimation_play1(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_int(L, 2)) && (olua_is_int(L, 3)) && (olua_is_int(L, 4)) && (olua_is_int(L, 5))) {
            // @using void play(int durationTo, int durationTween, int loop, int tweenEasing)
            return _cocostudio_ArmatureAnimation_play2(L);
        // }
    }

    luaL_error(L, "method 'cocostudio::ArmatureAnimation::play' not support '%d' arguments", num_args);

    return 0;
}

static int _cocostudio_ArmatureAnimation_playWithIndex1(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ArmatureAnimation *self = nullptr;
    lua_Integer arg1 = 0;       /** animationIndex */
    lua_Integer arg2 = 0;       /** durationTo */
    lua_Integer arg3 = 0;       /** loop */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ArmatureAnimation");
    olua_check_int(L, 2, &arg1);
    olua_check_int(L, 3, &arg2);
    olua_check_int(L, 4, &arg3);

    // void playWithIndex(int animationIndex, @optional int durationTo, @optional int loop)
    self->playWithIndex((int)arg1, (int)arg2, (int)arg3);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ArmatureAnimation_playWithIndex2(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ArmatureAnimation *self = nullptr;
    lua_Integer arg1 = 0;       /** animationIndex */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ArmatureAnimation");
    olua_check_int(L, 2, &arg1);

    // void playWithIndex(int animationIndex, @optional int durationTo, @optional int loop)
    self->playWithIndex((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ArmatureAnimation_playWithIndex3(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ArmatureAnimation *self = nullptr;
    lua_Integer arg1 = 0;       /** animationIndex */
    lua_Integer arg2 = 0;       /** durationTo */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ArmatureAnimation");
    olua_check_int(L, 2, &arg1);
    olua_check_int(L, 3, &arg2);

    // void playWithIndex(int animationIndex, @optional int durationTo, @optional int loop)
    self->playWithIndex((int)arg1, (int)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ArmatureAnimation_playWithIndex(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_int(L, 2))) {
            // void playWithIndex(int animationIndex, @optional int durationTo, @optional int loop)
            return _cocostudio_ArmatureAnimation_playWithIndex2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_int(L, 2)) && (olua_is_int(L, 3))) {
            // void playWithIndex(int animationIndex, @optional int durationTo, @optional int loop)
            return _cocostudio_ArmatureAnimation_playWithIndex3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_int(L, 2)) && (olua_is_int(L, 3)) && (olua_is_int(L, 4))) {
            // void playWithIndex(int animationIndex, @optional int durationTo, @optional int loop)
            return _cocostudio_ArmatureAnimation_playWithIndex1(L);
        // }
    }

    luaL_error(L, "method 'cocostudio::ArmatureAnimation::playWithIndex' not support '%d' arguments", num_args);

    return 0;
}

static int _cocostudio_ArmatureAnimation_playWithIndexes1(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ArmatureAnimation *self = nullptr;
    std::vector<int> arg1;       /** movementIndexes */
    lua_Integer arg2 = 0;       /** durationTo */
    bool arg3 = false;       /** loop */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ArmatureAnimation");
    olua_check_std_vector<int>(L, 2, &arg1, [L](int *value) {
        lua_Integer obj;
        olua_check_int(L, -1, &obj);
        *value = (int)obj;
    });
    olua_check_int(L, 3, &arg2);
    olua_check_bool(L, 4, &arg3);

    // void playWithIndexes(const std::vector<int> &movementIndexes, @optional int durationTo, @optional bool loop)
    self->playWithIndexes(arg1, (int)arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ArmatureAnimation_playWithIndexes2(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ArmatureAnimation *self = nullptr;
    std::vector<int> arg1;       /** movementIndexes */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ArmatureAnimation");
    olua_check_std_vector<int>(L, 2, &arg1, [L](int *value) {
        lua_Integer obj;
        olua_check_int(L, -1, &obj);
        *value = (int)obj;
    });

    // void playWithIndexes(const std::vector<int> &movementIndexes, @optional int durationTo, @optional bool loop)
    self->playWithIndexes(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ArmatureAnimation_playWithIndexes3(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ArmatureAnimation *self = nullptr;
    std::vector<int> arg1;       /** movementIndexes */
    lua_Integer arg2 = 0;       /** durationTo */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ArmatureAnimation");
    olua_check_std_vector<int>(L, 2, &arg1, [L](int *value) {
        lua_Integer obj;
        olua_check_int(L, -1, &obj);
        *value = (int)obj;
    });
    olua_check_int(L, 3, &arg2);

    // void playWithIndexes(const std::vector<int> &movementIndexes, @optional int durationTo, @optional bool loop)
    self->playWithIndexes(arg1, (int)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ArmatureAnimation_playWithIndexes(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_std_vector(L, 2))) {
            // void playWithIndexes(const std::vector<int> &movementIndexes, @optional int durationTo, @optional bool loop)
            return _cocostudio_ArmatureAnimation_playWithIndexes2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_vector(L, 2)) && (olua_is_int(L, 3))) {
            // void playWithIndexes(const std::vector<int> &movementIndexes, @optional int durationTo, @optional bool loop)
            return _cocostudio_ArmatureAnimation_playWithIndexes3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_std_vector(L, 2)) && (olua_is_int(L, 3)) && (olua_is_bool(L, 4))) {
            // void playWithIndexes(const std::vector<int> &movementIndexes, @optional int durationTo, @optional bool loop)
            return _cocostudio_ArmatureAnimation_playWithIndexes1(L);
        // }
    }

    luaL_error(L, "method 'cocostudio::ArmatureAnimation::playWithIndexes' not support '%d' arguments", num_args);

    return 0;
}

static int _cocostudio_ArmatureAnimation_playWithNames1(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ArmatureAnimation *self = nullptr;
    std::vector<std::string> arg1;       /** movementNames */
    lua_Integer arg2 = 0;       /** durationTo */
    bool arg3 = false;       /** loop */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ArmatureAnimation");
    olua_check_std_vector<std::string>(L, 2, &arg1, [L](std::string *value) {
        olua_check_std_string(L, -1, value);
    });
    olua_check_int(L, 3, &arg2);
    olua_check_bool(L, 4, &arg3);

    // void playWithNames(const std::vector<std::string> &movementNames, @optional int durationTo, @optional bool loop)
    self->playWithNames(arg1, (int)arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ArmatureAnimation_playWithNames2(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ArmatureAnimation *self = nullptr;
    std::vector<std::string> arg1;       /** movementNames */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ArmatureAnimation");
    olua_check_std_vector<std::string>(L, 2, &arg1, [L](std::string *value) {
        olua_check_std_string(L, -1, value);
    });

    // void playWithNames(const std::vector<std::string> &movementNames, @optional int durationTo, @optional bool loop)
    self->playWithNames(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ArmatureAnimation_playWithNames3(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ArmatureAnimation *self = nullptr;
    std::vector<std::string> arg1;       /** movementNames */
    lua_Integer arg2 = 0;       /** durationTo */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ArmatureAnimation");
    olua_check_std_vector<std::string>(L, 2, &arg1, [L](std::string *value) {
        olua_check_std_string(L, -1, value);
    });
    olua_check_int(L, 3, &arg2);

    // void playWithNames(const std::vector<std::string> &movementNames, @optional int durationTo, @optional bool loop)
    self->playWithNames(arg1, (int)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ArmatureAnimation_playWithNames(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_std_vector(L, 2))) {
            // void playWithNames(const std::vector<std::string> &movementNames, @optional int durationTo, @optional bool loop)
            return _cocostudio_ArmatureAnimation_playWithNames2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_vector(L, 2)) && (olua_is_int(L, 3))) {
            // void playWithNames(const std::vector<std::string> &movementNames, @optional int durationTo, @optional bool loop)
            return _cocostudio_ArmatureAnimation_playWithNames3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_std_vector(L, 2)) && (olua_is_int(L, 3)) && (olua_is_bool(L, 4))) {
            // void playWithNames(const std::vector<std::string> &movementNames, @optional int durationTo, @optional bool loop)
            return _cocostudio_ArmatureAnimation_playWithNames1(L);
        // }
    }

    luaL_error(L, "method 'cocostudio::ArmatureAnimation::playWithNames' not support '%d' arguments", num_args);

    return 0;
}

static int _cocostudio_ArmatureAnimation_setAnimationData(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ArmatureAnimation *self = nullptr;
    cocostudio::AnimationData *arg1 = nullptr;       /** data */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ArmatureAnimation");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccs.AnimationData");

    // void setAnimationData(cocostudio::AnimationData *data)
    self->setAnimationData(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ArmatureAnimation_setFrameEventCallFunc(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ArmatureAnimation *self = nullptr;
    std::function<void(cocostudio::Bone *, const std::string &, int, int)> arg1;       /** listener */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ArmatureAnimation");
    olua_check_std_function(L, 2, &arg1);

    void *cb_store = (void *)self;
    std::string cb_tag = "FrameEventCallFunc";
    std::string cb_name;
    if (olua_is_std_function(L, 2)) {
        cb_name = olua_setcallback(L, cb_store,  2, cb_tag.c_str(), OLUA_TAG_REPLACE);
        lua_Integer cb_ctx = olua_context(L);
        arg1 = [cb_store, cb_name, cb_ctx](cocostudio::Bone *arg1, const std::string &arg2, int arg3, int arg4) {
            lua_State *L = olua_mainthread(NULL);
            olua_checkhostthread();

            if (L != NULL && olua_context(L) == cb_ctx) {
                int top = lua_gettop(L);
                size_t last = olua_push_objpool(L);
                olua_enable_objpool(L);
                olua_push_cppobj(L, arg1, "ccs.Bone");
                olua_push_std_string(L, arg2);
                olua_push_int(L, (lua_Integer)arg3);
                olua_push_int(L, (lua_Integer)arg4);
                olua_disable_objpool(L);

                olua_callback(L, cb_store, cb_name.c_str(), 4);

                //pop stack value
                olua_pop_objpool(L, last);
                lua_settop(L, top);
            }
        };
    } else {
        olua_removecallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_SUBEQUAL);
        arg1 = nullptr;
    }

    // void setFrameEventCallFunc(@nullable @local std::function<void (cocostudio::Bone *, const std::string &, int, int)> listener)
    self->setFrameEventCallFunc(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ArmatureAnimation_setMovementEventCallFunc(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ArmatureAnimation *self = nullptr;
    std::function<void(cocostudio::Armature *, cocostudio::MovementEventType, const std::string &)> arg1;       /** listener */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ArmatureAnimation");
    olua_check_std_function(L, 2, &arg1);

    void *cb_store = (void *)self;
    std::string cb_tag = "MovementEventCallFunc";
    std::string cb_name;
    if (olua_is_std_function(L, 2)) {
        cb_name = olua_setcallback(L, cb_store,  2, cb_tag.c_str(), OLUA_TAG_REPLACE);
        lua_Integer cb_ctx = olua_context(L);
        arg1 = [cb_store, cb_name, cb_ctx](cocostudio::Armature *arg1, cocostudio::MovementEventType arg2, const std::string &arg3) {
            lua_State *L = olua_mainthread(NULL);
            olua_checkhostthread();

            if (L != NULL && olua_context(L) == cb_ctx) {
                int top = lua_gettop(L);
                size_t last = olua_push_objpool(L);
                olua_enable_objpool(L);
                olua_push_cppobj(L, arg1, "ccs.Armature");
                olua_push_uint(L, (lua_Unsigned)arg2);
                olua_push_std_string(L, arg3);
                olua_disable_objpool(L);

                olua_callback(L, cb_store, cb_name.c_str(), 3);

                //pop stack value
                olua_pop_objpool(L, last);
                lua_settop(L, top);
            }
        };
    } else {
        olua_removecallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_SUBEQUAL);
        arg1 = nullptr;
    }

    // void setMovementEventCallFunc(@nullable @local std::function<void (cocostudio::Armature *, cocostudio::MovementEventType, const std::string &)> listener)
    self->setMovementEventCallFunc(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ArmatureAnimation_setSpeedScale(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ArmatureAnimation *self = nullptr;
    lua_Number arg1 = 0;       /** speedScale */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ArmatureAnimation");
    olua_check_number(L, 2, &arg1);

    // void setSpeedScale(float speedScale)
    self->setSpeedScale((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ArmatureAnimation_setUserObject(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ArmatureAnimation *self = nullptr;
    cocos2d::Ref *arg1 = nullptr;       /** userObject */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ArmatureAnimation");
    olua_check_cppobj(L, 2, (void **)&arg1, "cc.Ref");

    // void setUserObject(cocos2d::Ref *userObject)
    self->setUserObject(arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocostudio_ArmatureAnimation(lua_State *L)
{
    oluacls_class(L, "ccs.ArmatureAnimation", "ccs.ProcessBase");
    oluacls_func(L, "__olua_move", _cocostudio_ArmatureAnimation___olua_move);
    oluacls_func(L, "create", _cocostudio_ArmatureAnimation_create);
    oluacls_func(L, "getAnimationData", _cocostudio_ArmatureAnimation_getAnimationData);
    oluacls_func(L, "getCurrentMovementID", _cocostudio_ArmatureAnimation_getCurrentMovementID);
    oluacls_func(L, "getMovementCount", _cocostudio_ArmatureAnimation_getMovementCount);
    oluacls_func(L, "getSpeedScale", _cocostudio_ArmatureAnimation_getSpeedScale);
    oluacls_func(L, "getUserObject", _cocostudio_ArmatureAnimation_getUserObject);
    oluacls_func(L, "gotoAndPause", _cocostudio_ArmatureAnimation_gotoAndPause);
    oluacls_func(L, "gotoAndPlay", _cocostudio_ArmatureAnimation_gotoAndPlay);
    oluacls_func(L, "init", _cocostudio_ArmatureAnimation_init);
    oluacls_func(L, "new", _cocostudio_ArmatureAnimation_new);
    oluacls_func(L, "play", _cocostudio_ArmatureAnimation_play);
    oluacls_func(L, "playWithIndex", _cocostudio_ArmatureAnimation_playWithIndex);
    oluacls_func(L, "playWithIndexes", _cocostudio_ArmatureAnimation_playWithIndexes);
    oluacls_func(L, "playWithNames", _cocostudio_ArmatureAnimation_playWithNames);
    oluacls_func(L, "setAnimationData", _cocostudio_ArmatureAnimation_setAnimationData);
    oluacls_func(L, "setFrameEventCallFunc", _cocostudio_ArmatureAnimation_setFrameEventCallFunc);
    oluacls_func(L, "setMovementEventCallFunc", _cocostudio_ArmatureAnimation_setMovementEventCallFunc);
    oluacls_func(L, "setSpeedScale", _cocostudio_ArmatureAnimation_setSpeedScale);
    oluacls_func(L, "setUserObject", _cocostudio_ArmatureAnimation_setUserObject);
    oluacls_prop(L, "animationData", _cocostudio_ArmatureAnimation_getAnimationData, _cocostudio_ArmatureAnimation_setAnimationData);
    oluacls_prop(L, "currentMovementID", _cocostudio_ArmatureAnimation_getCurrentMovementID, nullptr);
    oluacls_prop(L, "movementCount", _cocostudio_ArmatureAnimation_getMovementCount, nullptr);
    oluacls_prop(L, "speedScale", _cocostudio_ArmatureAnimation_getSpeedScale, _cocostudio_ArmatureAnimation_setSpeedScale);
    oluacls_prop(L, "userObject", _cocostudio_ArmatureAnimation_getUserObject, _cocostudio_ArmatureAnimation_setUserObject);

    olua_registerluatype<cocostudio::ArmatureAnimation>(L, "ccs.ArmatureAnimation");

    return 1;
}

static int _cocostudio_ArmatureData___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocostudio::ArmatureData *)olua_toobj(L, 1, "ccs.ArmatureData");
    olua_push_cppobj(L, self, "ccs.ArmatureData");

    olua_endinvoke(L);

    return 1;
}

static int _cocostudio_ArmatureData_addBoneData(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ArmatureData *self = nullptr;
    cocostudio::BoneData *arg1 = nullptr;       /** boneData */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ArmatureData");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccs.BoneData");

    // void addBoneData(cocostudio::BoneData *boneData)
    self->addBoneData(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ArmatureData_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cocostudio::ArmatureData *create()
    cocostudio::ArmatureData *ret = cocostudio::ArmatureData::create();
    int num_ret = olua_push_cppobj(L, ret, "ccs.ArmatureData");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ArmatureData_getBoneData(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ArmatureData *self = nullptr;
    std::string arg1;       /** boneName */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ArmatureData");
    olua_check_std_string(L, 2, &arg1);

    // cocostudio::BoneData *getBoneData(const std::string &boneName)
    cocostudio::BoneData *ret = self->getBoneData(arg1);
    int num_ret = olua_push_cppobj(L, ret, "ccs.BoneData");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ArmatureData_init(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ArmatureData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ArmatureData");

    // bool init()
    bool ret = self->init();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ArmatureData_new(lua_State *L)
{
    olua_startinvoke(L);

    // ArmatureData()
    cocostudio::ArmatureData *ret = new cocostudio::ArmatureData();
    int num_ret = olua_push_cppobj(L, ret, "ccs.ArmatureData");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ArmatureData_get_boneDataDic(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ArmatureData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ArmatureData");

    // cocos2d::Map<std::string, BoneData *> boneDataDic
    cocos2d::Map<std::string, cocostudio::BoneData *> ret = self->boneDataDic;
    int num_ret = olua_push_cocos2d_Map<std::string, cocostudio::BoneData *>(L, &ret, [L](std::string arg1, cocostudio::BoneData *arg2) {
        olua_push_std_string(L, (std::string)arg1);
        olua_push_cppobj(L, arg2, "ccs.BoneData");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ArmatureData_set_boneDataDic(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ArmatureData *self = nullptr;
    cocos2d::Map<std::string, cocostudio::BoneData *> arg1;       /** boneDataDic */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ArmatureData");
    olua_check_cocos2d_Map<std::string, cocostudio::BoneData *>(L, 2, &arg1, [L](std::string *arg1, cocostudio::BoneData **arg2) {
        olua_check_std_string(L, -1, arg1);
        olua_check_cppobj(L, -2, (void **)arg2, "ccs.BoneData");
    });

    // cocos2d::Map<std::string, BoneData *> boneDataDic
    self->boneDataDic = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ArmatureData_get_dataVersion(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ArmatureData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ArmatureData");

    // float dataVersion
    float ret = self->dataVersion;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ArmatureData_set_dataVersion(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ArmatureData *self = nullptr;
    lua_Number arg1 = 0;       /** dataVersion */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ArmatureData");
    olua_check_number(L, 2, &arg1);

    // float dataVersion
    self->dataVersion = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ArmatureData_get_name(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ArmatureData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ArmatureData");

    // std::string name
    std::string ret = self->name;
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ArmatureData_set_name(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ArmatureData *self = nullptr;
    std::string arg1;       /** name */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ArmatureData");
    olua_check_std_string(L, 2, &arg1);

    // std::string name
    self->name = arg1;

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocostudio_ArmatureData(lua_State *L)
{
    oluacls_class(L, "ccs.ArmatureData", "cc.Ref");
    oluacls_func(L, "__olua_move", _cocostudio_ArmatureData___olua_move);
    oluacls_func(L, "addBoneData", _cocostudio_ArmatureData_addBoneData);
    oluacls_func(L, "create", _cocostudio_ArmatureData_create);
    oluacls_func(L, "getBoneData", _cocostudio_ArmatureData_getBoneData);
    oluacls_func(L, "init", _cocostudio_ArmatureData_init);
    oluacls_func(L, "new", _cocostudio_ArmatureData_new);
    oluacls_prop(L, "boneDataDic", _cocostudio_ArmatureData_get_boneDataDic, _cocostudio_ArmatureData_set_boneDataDic);
    oluacls_prop(L, "dataVersion", _cocostudio_ArmatureData_get_dataVersion, _cocostudio_ArmatureData_set_dataVersion);
    oluacls_prop(L, "name", _cocostudio_ArmatureData_get_name, _cocostudio_ArmatureData_set_name);

    olua_registerluatype<cocostudio::ArmatureData>(L, "ccs.ArmatureData");

    return 1;
}

static int _cocostudio_ArmatureDataManager___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocostudio::ArmatureDataManager *)olua_toobj(L, 1, "ccs.ArmatureDataManager");
    olua_push_cppobj(L, self, "ccs.ArmatureDataManager");

    olua_endinvoke(L);

    return 1;
}

static int _cocostudio_ArmatureDataManager_addAnimationData1(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ArmatureDataManager *self = nullptr;
    std::string arg1;       /** id */
    cocostudio::AnimationData *arg2 = nullptr;       /** animationData */
    std::string arg3;       /** configFilePath */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ArmatureDataManager");
    olua_check_std_string(L, 2, &arg1);
    olua_check_cppobj(L, 3, (void **)&arg2, "ccs.AnimationData");
    olua_check_std_string(L, 4, &arg3);

    // void addAnimationData(const std::string &id, cocostudio::AnimationData *animationData, @optional const std::string &configFilePath)
    self->addAnimationData(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ArmatureDataManager_addAnimationData2(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ArmatureDataManager *self = nullptr;
    std::string arg1;       /** id */
    cocostudio::AnimationData *arg2 = nullptr;       /** animationData */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ArmatureDataManager");
    olua_check_std_string(L, 2, &arg1);
    olua_check_cppobj(L, 3, (void **)&arg2, "ccs.AnimationData");

    // void addAnimationData(const std::string &id, cocostudio::AnimationData *animationData, @optional const std::string &configFilePath)
    self->addAnimationData(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ArmatureDataManager_addAnimationData(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_cppobj(L, 3, "ccs.AnimationData"))) {
            // void addAnimationData(const std::string &id, cocostudio::AnimationData *animationData, @optional const std::string &configFilePath)
            return _cocostudio_ArmatureDataManager_addAnimationData2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_cppobj(L, 3, "ccs.AnimationData")) && (olua_is_std_string(L, 4))) {
            // void addAnimationData(const std::string &id, cocostudio::AnimationData *animationData, @optional const std::string &configFilePath)
            return _cocostudio_ArmatureDataManager_addAnimationData1(L);
        // }
    }

    luaL_error(L, "method 'cocostudio::ArmatureDataManager::addAnimationData' not support '%d' arguments", num_args);

    return 0;
}

static int _cocostudio_ArmatureDataManager_addArmatureData1(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ArmatureDataManager *self = nullptr;
    std::string arg1;       /** id */
    cocostudio::ArmatureData *arg2 = nullptr;       /** armatureData */
    std::string arg3;       /** configFilePath */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ArmatureDataManager");
    olua_check_std_string(L, 2, &arg1);
    olua_check_cppobj(L, 3, (void **)&arg2, "ccs.ArmatureData");
    olua_check_std_string(L, 4, &arg3);

    // void addArmatureData(const std::string &id, cocostudio::ArmatureData *armatureData, @optional const std::string &configFilePath)
    self->addArmatureData(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ArmatureDataManager_addArmatureData2(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ArmatureDataManager *self = nullptr;
    std::string arg1;       /** id */
    cocostudio::ArmatureData *arg2 = nullptr;       /** armatureData */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ArmatureDataManager");
    olua_check_std_string(L, 2, &arg1);
    olua_check_cppobj(L, 3, (void **)&arg2, "ccs.ArmatureData");

    // void addArmatureData(const std::string &id, cocostudio::ArmatureData *armatureData, @optional const std::string &configFilePath)
    self->addArmatureData(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ArmatureDataManager_addArmatureData(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_cppobj(L, 3, "ccs.ArmatureData"))) {
            // void addArmatureData(const std::string &id, cocostudio::ArmatureData *armatureData, @optional const std::string &configFilePath)
            return _cocostudio_ArmatureDataManager_addArmatureData2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_cppobj(L, 3, "ccs.ArmatureData")) && (olua_is_std_string(L, 4))) {
            // void addArmatureData(const std::string &id, cocostudio::ArmatureData *armatureData, @optional const std::string &configFilePath)
            return _cocostudio_ArmatureDataManager_addArmatureData1(L);
        // }
    }

    luaL_error(L, "method 'cocostudio::ArmatureDataManager::addArmatureData' not support '%d' arguments", num_args);

    return 0;
}

static int _cocostudio_ArmatureDataManager_addArmatureFileInfo1(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ArmatureDataManager *self = nullptr;
    std::string arg1;       /** configFilePath */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ArmatureDataManager");
    olua_check_std_string(L, 2, &arg1);

    // void addArmatureFileInfo(const std::string &configFilePath)
    self->addArmatureFileInfo(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ArmatureDataManager_addArmatureFileInfo2(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ArmatureDataManager *self = nullptr;
    std::string arg1;       /** imagePath */
    std::string arg2;       /** plistPath */
    std::string arg3;       /** configFilePath */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ArmatureDataManager");
    olua_check_std_string(L, 2, &arg1);
    olua_check_std_string(L, 3, &arg2);
    olua_check_std_string(L, 4, &arg3);

    // void addArmatureFileInfo(const std::string &imagePath, const std::string &plistPath, const std::string &configFilePath)
    self->addArmatureFileInfo(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ArmatureDataManager_addArmatureFileInfo(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 2))) {
            // void addArmatureFileInfo(const std::string &configFilePath)
            return _cocostudio_ArmatureDataManager_addArmatureFileInfo1(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_std_string(L, 3)) && (olua_is_std_string(L, 4))) {
            // void addArmatureFileInfo(const std::string &imagePath, const std::string &plistPath, const std::string &configFilePath)
            return _cocostudio_ArmatureDataManager_addArmatureFileInfo2(L);
        // }
    }

    luaL_error(L, "method 'cocostudio::ArmatureDataManager::addArmatureFileInfo' not support '%d' arguments", num_args);

    return 0;
}

static int _cocostudio_ArmatureDataManager_addSpriteFrameFromFile1(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ArmatureDataManager *self = nullptr;
    std::string arg1;       /** plistPath */
    std::string arg2;       /** imagePath */
    std::string arg3;       /** configFilePath */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ArmatureDataManager");
    olua_check_std_string(L, 2, &arg1);
    olua_check_std_string(L, 3, &arg2);
    olua_check_std_string(L, 4, &arg3);

    // void addSpriteFrameFromFile(const std::string &plistPath, const std::string &imagePath, @optional const std::string &configFilePath)
    self->addSpriteFrameFromFile(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ArmatureDataManager_addSpriteFrameFromFile2(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ArmatureDataManager *self = nullptr;
    std::string arg1;       /** plistPath */
    std::string arg2;       /** imagePath */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ArmatureDataManager");
    olua_check_std_string(L, 2, &arg1);
    olua_check_std_string(L, 3, &arg2);

    // void addSpriteFrameFromFile(const std::string &plistPath, const std::string &imagePath, @optional const std::string &configFilePath)
    self->addSpriteFrameFromFile(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ArmatureDataManager_addSpriteFrameFromFile(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_std_string(L, 3))) {
            // void addSpriteFrameFromFile(const std::string &plistPath, const std::string &imagePath, @optional const std::string &configFilePath)
            return _cocostudio_ArmatureDataManager_addSpriteFrameFromFile2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_std_string(L, 3)) && (olua_is_std_string(L, 4))) {
            // void addSpriteFrameFromFile(const std::string &plistPath, const std::string &imagePath, @optional const std::string &configFilePath)
            return _cocostudio_ArmatureDataManager_addSpriteFrameFromFile1(L);
        // }
    }

    luaL_error(L, "method 'cocostudio::ArmatureDataManager::addSpriteFrameFromFile' not support '%d' arguments", num_args);

    return 0;
}

static int _cocostudio_ArmatureDataManager_addTextureData1(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ArmatureDataManager *self = nullptr;
    std::string arg1;       /** id */
    cocostudio::TextureData *arg2 = nullptr;       /** textureData */
    std::string arg3;       /** configFilePath */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ArmatureDataManager");
    olua_check_std_string(L, 2, &arg1);
    olua_check_cppobj(L, 3, (void **)&arg2, "ccs.TextureData");
    olua_check_std_string(L, 4, &arg3);

    // void addTextureData(const std::string &id, cocostudio::TextureData *textureData, @optional const std::string &configFilePath)
    self->addTextureData(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ArmatureDataManager_addTextureData2(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ArmatureDataManager *self = nullptr;
    std::string arg1;       /** id */
    cocostudio::TextureData *arg2 = nullptr;       /** textureData */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ArmatureDataManager");
    olua_check_std_string(L, 2, &arg1);
    olua_check_cppobj(L, 3, (void **)&arg2, "ccs.TextureData");

    // void addTextureData(const std::string &id, cocostudio::TextureData *textureData, @optional const std::string &configFilePath)
    self->addTextureData(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ArmatureDataManager_addTextureData(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_cppobj(L, 3, "ccs.TextureData"))) {
            // void addTextureData(const std::string &id, cocostudio::TextureData *textureData, @optional const std::string &configFilePath)
            return _cocostudio_ArmatureDataManager_addTextureData2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_cppobj(L, 3, "ccs.TextureData")) && (olua_is_std_string(L, 4))) {
            // void addTextureData(const std::string &id, cocostudio::TextureData *textureData, @optional const std::string &configFilePath)
            return _cocostudio_ArmatureDataManager_addTextureData1(L);
        // }
    }

    luaL_error(L, "method 'cocostudio::ArmatureDataManager::addTextureData' not support '%d' arguments", num_args);

    return 0;
}

static int _cocostudio_ArmatureDataManager_destroyInstance(lua_State *L)
{
    olua_startinvoke(L);

    // static void destroyInstance()
    cocostudio::ArmatureDataManager::destroyInstance();

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ArmatureDataManager_getAnimationData(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ArmatureDataManager *self = nullptr;
    std::string arg1;       /** id */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ArmatureDataManager");
    olua_check_std_string(L, 2, &arg1);

    // cocostudio::AnimationData *getAnimationData(const std::string &id)
    cocostudio::AnimationData *ret = self->getAnimationData(arg1);
    int num_ret = olua_push_cppobj(L, ret, "ccs.AnimationData");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ArmatureDataManager_getAnimationDatas(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ArmatureDataManager *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ArmatureDataManager");

    // const cocos2d::Map<std::string, AnimationData *> &getAnimationDatas()
    const cocos2d::Map<std::string, cocostudio::AnimationData *> &ret = self->getAnimationDatas();
    int num_ret = olua_push_cocos2d_Map<std::string, cocostudio::AnimationData *>(L, &ret, [L](std::string arg1, cocostudio::AnimationData *arg2) {
        olua_push_std_string(L, (std::string)arg1);
        olua_push_cppobj(L, arg2, "ccs.AnimationData");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ArmatureDataManager_getArmatureData(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ArmatureDataManager *self = nullptr;
    std::string arg1;       /** id */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ArmatureDataManager");
    olua_check_std_string(L, 2, &arg1);

    // cocostudio::ArmatureData *getArmatureData(const std::string &id)
    cocostudio::ArmatureData *ret = self->getArmatureData(arg1);
    int num_ret = olua_push_cppobj(L, ret, "ccs.ArmatureData");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ArmatureDataManager_getArmatureDatas(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ArmatureDataManager *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ArmatureDataManager");

    // const cocos2d::Map<std::string, ArmatureData *> &getArmatureDatas()
    const cocos2d::Map<std::string, cocostudio::ArmatureData *> &ret = self->getArmatureDatas();
    int num_ret = olua_push_cocos2d_Map<std::string, cocostudio::ArmatureData *>(L, &ret, [L](std::string arg1, cocostudio::ArmatureData *arg2) {
        olua_push_std_string(L, (std::string)arg1);
        olua_push_cppobj(L, arg2, "ccs.ArmatureData");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ArmatureDataManager_getInstance(lua_State *L)
{
    olua_startinvoke(L);

    // static cocostudio::ArmatureDataManager *getInstance()
    cocostudio::ArmatureDataManager *ret = cocostudio::ArmatureDataManager::getInstance();
    int num_ret = olua_push_cppobj(L, ret, "ccs.ArmatureDataManager");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ArmatureDataManager_getTextureData(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ArmatureDataManager *self = nullptr;
    std::string arg1;       /** id */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ArmatureDataManager");
    olua_check_std_string(L, 2, &arg1);

    // cocostudio::TextureData *getTextureData(const std::string &id)
    cocostudio::TextureData *ret = self->getTextureData(arg1);
    int num_ret = olua_push_cppobj(L, ret, "ccs.TextureData");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ArmatureDataManager_getTextureDatas(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ArmatureDataManager *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ArmatureDataManager");

    // const cocos2d::Map<std::string, TextureData *> &getTextureDatas()
    const cocos2d::Map<std::string, cocostudio::TextureData *> &ret = self->getTextureDatas();
    int num_ret = olua_push_cocos2d_Map<std::string, cocostudio::TextureData *>(L, &ret, [L](std::string arg1, cocostudio::TextureData *arg2) {
        olua_push_std_string(L, (std::string)arg1);
        olua_push_cppobj(L, arg2, "ccs.TextureData");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ArmatureDataManager_init(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ArmatureDataManager *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ArmatureDataManager");

    // bool init()
    bool ret = self->init();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ArmatureDataManager_isAutoLoadSpriteFile(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ArmatureDataManager *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ArmatureDataManager");

    // bool isAutoLoadSpriteFile()
    bool ret = self->isAutoLoadSpriteFile();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ArmatureDataManager_removeAnimationData(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ArmatureDataManager *self = nullptr;
    std::string arg1;       /** id */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ArmatureDataManager");
    olua_check_std_string(L, 2, &arg1);

    // void removeAnimationData(const std::string &id)
    self->removeAnimationData(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ArmatureDataManager_removeArmatureData(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ArmatureDataManager *self = nullptr;
    std::string arg1;       /** id */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ArmatureDataManager");
    olua_check_std_string(L, 2, &arg1);

    // void removeArmatureData(const std::string &id)
    self->removeArmatureData(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ArmatureDataManager_removeArmatureFileInfo(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ArmatureDataManager *self = nullptr;
    std::string arg1;       /** configFilePath */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ArmatureDataManager");
    olua_check_std_string(L, 2, &arg1);

    // void removeArmatureFileInfo(const std::string &configFilePath)
    self->removeArmatureFileInfo(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ArmatureDataManager_removeTextureData(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ArmatureDataManager *self = nullptr;
    std::string arg1;       /** id */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ArmatureDataManager");
    olua_check_std_string(L, 2, &arg1);

    // void removeTextureData(const std::string &id)
    self->removeTextureData(arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocostudio_ArmatureDataManager(lua_State *L)
{
    oluacls_class(L, "ccs.ArmatureDataManager", "cc.Ref");
    oluacls_func(L, "__olua_move", _cocostudio_ArmatureDataManager___olua_move);
    oluacls_func(L, "addAnimationData", _cocostudio_ArmatureDataManager_addAnimationData);
    oluacls_func(L, "addArmatureData", _cocostudio_ArmatureDataManager_addArmatureData);
    oluacls_func(L, "addArmatureFileInfo", _cocostudio_ArmatureDataManager_addArmatureFileInfo);
    oluacls_func(L, "addSpriteFrameFromFile", _cocostudio_ArmatureDataManager_addSpriteFrameFromFile);
    oluacls_func(L, "addTextureData", _cocostudio_ArmatureDataManager_addTextureData);
    oluacls_func(L, "destroyInstance", _cocostudio_ArmatureDataManager_destroyInstance);
    oluacls_func(L, "getAnimationData", _cocostudio_ArmatureDataManager_getAnimationData);
    oluacls_func(L, "getAnimationDatas", _cocostudio_ArmatureDataManager_getAnimationDatas);
    oluacls_func(L, "getArmatureData", _cocostudio_ArmatureDataManager_getArmatureData);
    oluacls_func(L, "getArmatureDatas", _cocostudio_ArmatureDataManager_getArmatureDatas);
    oluacls_func(L, "getInstance", _cocostudio_ArmatureDataManager_getInstance);
    oluacls_func(L, "getTextureData", _cocostudio_ArmatureDataManager_getTextureData);
    oluacls_func(L, "getTextureDatas", _cocostudio_ArmatureDataManager_getTextureDatas);
    oluacls_func(L, "init", _cocostudio_ArmatureDataManager_init);
    oluacls_func(L, "isAutoLoadSpriteFile", _cocostudio_ArmatureDataManager_isAutoLoadSpriteFile);
    oluacls_func(L, "removeAnimationData", _cocostudio_ArmatureDataManager_removeAnimationData);
    oluacls_func(L, "removeArmatureData", _cocostudio_ArmatureDataManager_removeArmatureData);
    oluacls_func(L, "removeArmatureFileInfo", _cocostudio_ArmatureDataManager_removeArmatureFileInfo);
    oluacls_func(L, "removeTextureData", _cocostudio_ArmatureDataManager_removeTextureData);
    oluacls_prop(L, "animationDatas", _cocostudio_ArmatureDataManager_getAnimationDatas, nullptr);
    oluacls_prop(L, "armatureDatas", _cocostudio_ArmatureDataManager_getArmatureDatas, nullptr);
    oluacls_prop(L, "autoLoadSpriteFile", _cocostudio_ArmatureDataManager_isAutoLoadSpriteFile, nullptr);
    oluacls_prop(L, "instance", _cocostudio_ArmatureDataManager_getInstance, nullptr);
    oluacls_prop(L, "textureDatas", _cocostudio_ArmatureDataManager_getTextureDatas, nullptr);

    olua_registerluatype<cocostudio::ArmatureDataManager>(L, "ccs.ArmatureDataManager");

    return 1;
}

static int _cocostudio_DisplayData___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocostudio::DisplayData *)olua_toobj(L, 1, "ccs.DisplayData");
    olua_push_cppobj(L, self, "ccs.DisplayData");

    olua_endinvoke(L);

    return 1;
}

static int _cocostudio_DisplayData_changeDisplayToTexture(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** displayName */

    olua_check_std_string(L, 1, &arg1);

    // static std::string changeDisplayToTexture(const std::string &displayName)
    std::string ret = cocostudio::DisplayData::changeDisplayToTexture(arg1);
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_DisplayData_copy(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::DisplayData *self = nullptr;
    cocostudio::DisplayData *arg1 = nullptr;       /** displayData */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.DisplayData");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccs.DisplayData");

    // void copy(cocostudio::DisplayData *displayData)
    self->copy(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_DisplayData_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cocostudio::DisplayData *create()
    cocostudio::DisplayData *ret = cocostudio::DisplayData::create();
    int num_ret = olua_push_cppobj(L, ret, "ccs.DisplayData");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_DisplayData_new(lua_State *L)
{
    olua_startinvoke(L);

    // DisplayData()
    cocostudio::DisplayData *ret = new cocostudio::DisplayData();
    int num_ret = olua_push_cppobj(L, ret, "ccs.DisplayData");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_DisplayData_get_displayName(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::DisplayData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.DisplayData");

    // std::string displayName
    std::string ret = self->displayName;
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_DisplayData_set_displayName(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::DisplayData *self = nullptr;
    std::string arg1;       /** displayName */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.DisplayData");
    olua_check_std_string(L, 2, &arg1);

    // std::string displayName
    self->displayName = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_DisplayData_get_displayType(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::DisplayData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.DisplayData");

    // cocostudio::DisplayType displayType
    cocostudio::DisplayType ret = self->displayType;
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_DisplayData_set_displayType(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::DisplayData *self = nullptr;
    lua_Unsigned arg1 = 0;       /** displayType */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.DisplayData");
    olua_check_uint(L, 2, &arg1);

    // cocostudio::DisplayType displayType
    self->displayType = (cocostudio::DisplayType)arg1;

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocostudio_DisplayData(lua_State *L)
{
    oluacls_class(L, "ccs.DisplayData", "cc.Ref");
    oluacls_func(L, "__olua_move", _cocostudio_DisplayData___olua_move);
    oluacls_func(L, "changeDisplayToTexture", _cocostudio_DisplayData_changeDisplayToTexture);
    oluacls_func(L, "copy", _cocostudio_DisplayData_copy);
    oluacls_func(L, "create", _cocostudio_DisplayData_create);
    oluacls_func(L, "new", _cocostudio_DisplayData_new);
    oluacls_prop(L, "displayName", _cocostudio_DisplayData_get_displayName, _cocostudio_DisplayData_set_displayName);
    oluacls_prop(L, "displayType", _cocostudio_DisplayData_get_displayType, _cocostudio_DisplayData_set_displayType);

    olua_registerluatype<cocostudio::DisplayData>(L, "ccs.DisplayData");

    return 1;
}

static int _cocostudio_ArmatureDisplayData___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocostudio::ArmatureDisplayData *)olua_toobj(L, 1, "ccs.ArmatureDisplayData");
    olua_push_cppobj(L, self, "ccs.ArmatureDisplayData");

    olua_endinvoke(L);

    return 1;
}

static int _cocostudio_ArmatureDisplayData_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cocostudio::ArmatureDisplayData *create()
    cocostudio::ArmatureDisplayData *ret = cocostudio::ArmatureDisplayData::create();
    int num_ret = olua_push_cppobj(L, ret, "ccs.ArmatureDisplayData");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ArmatureDisplayData_new(lua_State *L)
{
    olua_startinvoke(L);

    // ArmatureDisplayData()
    cocostudio::ArmatureDisplayData *ret = new cocostudio::ArmatureDisplayData();
    int num_ret = olua_push_cppobj(L, ret, "ccs.ArmatureDisplayData");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocostudio_ArmatureDisplayData(lua_State *L)
{
    oluacls_class(L, "ccs.ArmatureDisplayData", "ccs.DisplayData");
    oluacls_func(L, "__olua_move", _cocostudio_ArmatureDisplayData___olua_move);
    oluacls_func(L, "create", _cocostudio_ArmatureDisplayData_create);
    oluacls_func(L, "new", _cocostudio_ArmatureDisplayData_new);

    olua_registerluatype<cocostudio::ArmatureDisplayData>(L, "ccs.ArmatureDisplayData");

    return 1;
}

static int _cocostudio_ArmatureMovementDispatcher___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocostudio::ArmatureMovementDispatcher *)olua_toobj(L, 1, "ccs.ArmatureMovementDispatcher");
    olua_push_cppobj(L, self, "ccs.ArmatureMovementDispatcher");

    olua_endinvoke(L);

    return 1;
}

static int luaopen_cocostudio_ArmatureMovementDispatcher(lua_State *L)
{
    oluacls_class(L, "ccs.ArmatureMovementDispatcher", "cc.Ref");
    oluacls_func(L, "__olua_move", _cocostudio_ArmatureMovementDispatcher___olua_move);

    olua_registerluatype<cocostudio::ArmatureMovementDispatcher>(L, "ccs.ArmatureMovementDispatcher");

    return 1;
}

static int _cocostudio_BaseData___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocostudio::BaseData *)olua_toobj(L, 1, "ccs.BaseData");
    olua_push_cppobj(L, self, "ccs.BaseData");

    olua_endinvoke(L);

    return 1;
}

static int _cocostudio_BaseData_copy(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::BaseData *self = nullptr;
    cocostudio::BaseData *arg1 = nullptr;       /** node */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.BaseData");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccs.BaseData");

    // void copy(const cocostudio::BaseData *node)
    self->copy(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_BaseData_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cocostudio::BaseData *create()
    cocostudio::BaseData *ret = cocostudio::BaseData::create();
    int num_ret = olua_push_cppobj(L, ret, "ccs.BaseData");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_BaseData_getColor(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::BaseData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.BaseData");

    // cocos2d::Color4B getColor()
    cocos2d::Color4B ret = self->getColor();
    int num_ret = olua_push_cocos2d_Color4B(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_BaseData_new(lua_State *L)
{
    olua_startinvoke(L);

    // BaseData()
    cocostudio::BaseData *ret = new cocostudio::BaseData();
    int num_ret = olua_push_cppobj(L, ret, "ccs.BaseData");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_BaseData_setColor(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::BaseData *self = nullptr;
    cocos2d::Color4B arg1;       /** color */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.BaseData");
    olua_check_cocos2d_Color4B(L, 2, &arg1);

    // void setColor(const cocos2d::Color4B &color)
    self->setColor(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_BaseData_subtract(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::BaseData *self = nullptr;
    cocostudio::BaseData *arg1 = nullptr;       /** from */
    cocostudio::BaseData *arg2 = nullptr;       /** to */
    bool arg3 = false;       /** limit */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.BaseData");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccs.BaseData");
    olua_check_cppobj(L, 3, (void **)&arg2, "ccs.BaseData");
    olua_check_bool(L, 4, &arg3);

    // void subtract(cocostudio::BaseData *from, cocostudio::BaseData *to, bool limit)
    self->subtract(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_BaseData_get_a(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::BaseData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.BaseData");

    // int a
    int ret = self->a;
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_BaseData_set_a(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::BaseData *self = nullptr;
    lua_Integer arg1 = 0;       /** a */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.BaseData");
    olua_check_int(L, 2, &arg1);

    // int a
    self->a = (int)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_BaseData_get_b(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::BaseData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.BaseData");

    // int b
    int ret = self->b;
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_BaseData_set_b(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::BaseData *self = nullptr;
    lua_Integer arg1 = 0;       /** b */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.BaseData");
    olua_check_int(L, 2, &arg1);

    // int b
    self->b = (int)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_BaseData_get_g(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::BaseData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.BaseData");

    // int g
    int ret = self->g;
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_BaseData_set_g(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::BaseData *self = nullptr;
    lua_Integer arg1 = 0;       /** g */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.BaseData");
    olua_check_int(L, 2, &arg1);

    // int g
    self->g = (int)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_BaseData_get_isUseColorInfo(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::BaseData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.BaseData");

    // bool isUseColorInfo
    bool ret = self->isUseColorInfo;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_BaseData_set_isUseColorInfo(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::BaseData *self = nullptr;
    bool arg1 = false;       /** isUseColorInfo */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.BaseData");
    olua_check_bool(L, 2, &arg1);

    // bool isUseColorInfo
    self->isUseColorInfo = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_BaseData_get_r(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::BaseData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.BaseData");

    // int r
    int ret = self->r;
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_BaseData_set_r(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::BaseData *self = nullptr;
    lua_Integer arg1 = 0;       /** r */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.BaseData");
    olua_check_int(L, 2, &arg1);

    // int r
    self->r = (int)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_BaseData_get_scaleX(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::BaseData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.BaseData");

    // float scaleX
    float ret = self->scaleX;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_BaseData_set_scaleX(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::BaseData *self = nullptr;
    lua_Number arg1 = 0;       /** scaleX */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.BaseData");
    olua_check_number(L, 2, &arg1);

    // float scaleX
    self->scaleX = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_BaseData_get_scaleY(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::BaseData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.BaseData");

    // float scaleY
    float ret = self->scaleY;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_BaseData_set_scaleY(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::BaseData *self = nullptr;
    lua_Number arg1 = 0;       /** scaleY */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.BaseData");
    olua_check_number(L, 2, &arg1);

    // float scaleY
    self->scaleY = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_BaseData_get_skewX(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::BaseData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.BaseData");

    // float skewX
    float ret = self->skewX;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_BaseData_set_skewX(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::BaseData *self = nullptr;
    lua_Number arg1 = 0;       /** skewX */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.BaseData");
    olua_check_number(L, 2, &arg1);

    // float skewX
    self->skewX = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_BaseData_get_skewY(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::BaseData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.BaseData");

    // float skewY
    float ret = self->skewY;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_BaseData_set_skewY(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::BaseData *self = nullptr;
    lua_Number arg1 = 0;       /** skewY */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.BaseData");
    olua_check_number(L, 2, &arg1);

    // float skewY
    self->skewY = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_BaseData_get_tweenRotate(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::BaseData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.BaseData");

    // float tweenRotate
    float ret = self->tweenRotate;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_BaseData_set_tweenRotate(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::BaseData *self = nullptr;
    lua_Number arg1 = 0;       /** tweenRotate */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.BaseData");
    olua_check_number(L, 2, &arg1);

    // float tweenRotate
    self->tweenRotate = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_BaseData_get_x(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::BaseData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.BaseData");

    // float x
    float ret = self->x;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_BaseData_set_x(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::BaseData *self = nullptr;
    lua_Number arg1 = 0;       /** x */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.BaseData");
    olua_check_number(L, 2, &arg1);

    // float x
    self->x = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_BaseData_get_y(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::BaseData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.BaseData");

    // float y
    float ret = self->y;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_BaseData_set_y(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::BaseData *self = nullptr;
    lua_Number arg1 = 0;       /** y */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.BaseData");
    olua_check_number(L, 2, &arg1);

    // float y
    self->y = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_BaseData_get_zOrder(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::BaseData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.BaseData");

    // int zOrder
    int ret = self->zOrder;
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_BaseData_set_zOrder(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::BaseData *self = nullptr;
    lua_Integer arg1 = 0;       /** zOrder */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.BaseData");
    olua_check_int(L, 2, &arg1);

    // int zOrder
    self->zOrder = (int)arg1;

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocostudio_BaseData(lua_State *L)
{
    oluacls_class(L, "ccs.BaseData", "cc.Ref");
    oluacls_func(L, "__olua_move", _cocostudio_BaseData___olua_move);
    oluacls_func(L, "copy", _cocostudio_BaseData_copy);
    oluacls_func(L, "create", _cocostudio_BaseData_create);
    oluacls_func(L, "getColor", _cocostudio_BaseData_getColor);
    oluacls_func(L, "new", _cocostudio_BaseData_new);
    oluacls_func(L, "setColor", _cocostudio_BaseData_setColor);
    oluacls_func(L, "subtract", _cocostudio_BaseData_subtract);
    oluacls_prop(L, "color", _cocostudio_BaseData_getColor, _cocostudio_BaseData_setColor);
    oluacls_prop(L, "a", _cocostudio_BaseData_get_a, _cocostudio_BaseData_set_a);
    oluacls_prop(L, "b", _cocostudio_BaseData_get_b, _cocostudio_BaseData_set_b);
    oluacls_prop(L, "g", _cocostudio_BaseData_get_g, _cocostudio_BaseData_set_g);
    oluacls_prop(L, "isUseColorInfo", _cocostudio_BaseData_get_isUseColorInfo, _cocostudio_BaseData_set_isUseColorInfo);
    oluacls_prop(L, "r", _cocostudio_BaseData_get_r, _cocostudio_BaseData_set_r);
    oluacls_prop(L, "scaleX", _cocostudio_BaseData_get_scaleX, _cocostudio_BaseData_set_scaleX);
    oluacls_prop(L, "scaleY", _cocostudio_BaseData_get_scaleY, _cocostudio_BaseData_set_scaleY);
    oluacls_prop(L, "skewX", _cocostudio_BaseData_get_skewX, _cocostudio_BaseData_set_skewX);
    oluacls_prop(L, "skewY", _cocostudio_BaseData_get_skewY, _cocostudio_BaseData_set_skewY);
    oluacls_prop(L, "tweenRotate", _cocostudio_BaseData_get_tweenRotate, _cocostudio_BaseData_set_tweenRotate);
    oluacls_prop(L, "x", _cocostudio_BaseData_get_x, _cocostudio_BaseData_set_x);
    oluacls_prop(L, "y", _cocostudio_BaseData_get_y, _cocostudio_BaseData_set_y);
    oluacls_prop(L, "zOrder", _cocostudio_BaseData_get_zOrder, _cocostudio_BaseData_set_zOrder);

    olua_registerluatype<cocostudio::BaseData>(L, "ccs.BaseData");

    return 1;
}

static int _cocostudio_BaseTriggerAction___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocostudio::BaseTriggerAction *)olua_toobj(L, 1, "ccs.BaseTriggerAction");
    olua_push_cppobj(L, self, "ccs.BaseTriggerAction");

    olua_endinvoke(L);

    return 1;
}

static int _cocostudio_BaseTriggerAction_done(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::BaseTriggerAction *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.BaseTriggerAction");

    // void done()
    self->done();

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_BaseTriggerAction_init(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::BaseTriggerAction *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.BaseTriggerAction");

    // bool init()
    bool ret = self->init();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_BaseTriggerAction_removeAll(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::BaseTriggerAction *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.BaseTriggerAction");

    // void removeAll()
    self->removeAll();

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocostudio_BaseTriggerAction(lua_State *L)
{
    oluacls_class(L, "ccs.BaseTriggerAction", "cc.Ref");
    oluacls_func(L, "__olua_move", _cocostudio_BaseTriggerAction___olua_move);
    oluacls_func(L, "done", _cocostudio_BaseTriggerAction_done);
    oluacls_func(L, "init", _cocostudio_BaseTriggerAction_init);
    oluacls_func(L, "removeAll", _cocostudio_BaseTriggerAction_removeAll);

    olua_registerluatype<cocostudio::BaseTriggerAction>(L, "ccs.BaseTriggerAction");

    return 1;
}

static int _cocostudio_BaseTriggerCondition___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocostudio::BaseTriggerCondition *)olua_toobj(L, 1, "ccs.BaseTriggerCondition");
    olua_push_cppobj(L, self, "ccs.BaseTriggerCondition");

    olua_endinvoke(L);

    return 1;
}

static int _cocostudio_BaseTriggerCondition_detect(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::BaseTriggerCondition *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.BaseTriggerCondition");

    // bool detect()
    bool ret = self->detect();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_BaseTriggerCondition_init(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::BaseTriggerCondition *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.BaseTriggerCondition");

    // bool init()
    bool ret = self->init();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_BaseTriggerCondition_removeAll(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::BaseTriggerCondition *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.BaseTriggerCondition");

    // void removeAll()
    self->removeAll();

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocostudio_BaseTriggerCondition(lua_State *L)
{
    oluacls_class(L, "ccs.BaseTriggerCondition", "cc.Ref");
    oluacls_func(L, "__olua_move", _cocostudio_BaseTriggerCondition___olua_move);
    oluacls_func(L, "detect", _cocostudio_BaseTriggerCondition_detect);
    oluacls_func(L, "init", _cocostudio_BaseTriggerCondition_init);
    oluacls_func(L, "removeAll", _cocostudio_BaseTriggerCondition_removeAll);

    olua_registerluatype<cocostudio::BaseTriggerCondition>(L, "ccs.BaseTriggerCondition");

    return 1;
}

static int _cocostudio_BatchNode___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocostudio::BatchNode *)olua_toobj(L, 1, "ccs.BatchNode");
    olua_push_cppobj(L, self, "ccs.BatchNode");

    olua_endinvoke(L);

    return 1;
}

static int _cocostudio_BatchNode_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cocostudio::BatchNode *create()
    cocostudio::BatchNode *ret = cocostudio::BatchNode::create();
    int num_ret = olua_push_cppobj(L, ret, "ccs.BatchNode");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_BatchNode_new(lua_State *L)
{
    olua_startinvoke(L);

    // BatchNode()
    cocostudio::BatchNode *ret = new cocostudio::BatchNode();
    int num_ret = olua_push_cppobj(L, ret, "ccs.BatchNode");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocostudio_BatchNode(lua_State *L)
{
    oluacls_class(L, "ccs.BatchNode", "cc.Node");
    oluacls_func(L, "__olua_move", _cocostudio_BatchNode___olua_move);
    oluacls_func(L, "create", _cocostudio_BatchNode_create);
    oluacls_func(L, "new", _cocostudio_BatchNode_new);

    olua_registerluatype<cocostudio::BatchNode>(L, "ccs.BatchNode");

    return 1;
}

static int _cocostudio_Bone___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocostudio::Bone *)olua_toobj(L, 1, "ccs.Bone");
    olua_push_cppobj(L, self, "ccs.Bone");

    olua_endinvoke(L);

    return 1;
}

static int _cocostudio_Bone_addChildBone(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Bone *self = nullptr;
    cocostudio::Bone *arg1 = nullptr;       /** child */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Bone");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccs.Bone");

    // void addChildBone(cocostudio::Bone *child)
    self->addChildBone(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_Bone_addDisplay1(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Bone *self = nullptr;
    cocostudio::DisplayData *arg1 = nullptr;       /** displayData */
    lua_Integer arg2 = 0;       /** index */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Bone");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccs.DisplayData");
    olua_check_int(L, 3, &arg2);

    // void addDisplay(cocostudio::DisplayData *displayData, int index)
    self->addDisplay(arg1, (int)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_Bone_addDisplay2(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Bone *self = nullptr;
    cocos2d::Node *arg1 = nullptr;       /** display */
    lua_Integer arg2 = 0;       /** index */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Bone");
    olua_check_cppobj(L, 2, (void **)&arg1, "cc.Node");
    olua_check_int(L, 3, &arg2);

    // void addDisplay(cocos2d::Node *display, int index)
    self->addDisplay(arg1, (int)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_Bone_addDisplay(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 2) {
        if ((olua_is_cppobj(L, 2, "ccs.DisplayData")) && (olua_is_int(L, 3))) {
            // void addDisplay(cocostudio::DisplayData *displayData, int index)
            return _cocostudio_Bone_addDisplay1(L);
        }

        // if ((olua_is_cppobj(L, 2, "cc.Node")) && (olua_is_int(L, 3))) {
            // void addDisplay(cocos2d::Node *display, int index)
            return _cocostudio_Bone_addDisplay2(L);
        // }
    }

    luaL_error(L, "method 'cocostudio::Bone::addDisplay' not support '%d' arguments", num_args);

    return 0;
}

static int _cocostudio_Bone_changeDisplayWithIndex(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Bone *self = nullptr;
    lua_Integer arg1 = 0;       /** index */
    bool arg2 = false;       /** force */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Bone");
    olua_check_int(L, 2, &arg1);
    olua_check_bool(L, 3, &arg2);

    // void changeDisplayWithIndex(int index, bool force)
    self->changeDisplayWithIndex((int)arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_Bone_changeDisplayWithName(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Bone *self = nullptr;
    std::string arg1;       /** name */
    bool arg2 = false;       /** force */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Bone");
    olua_check_std_string(L, 2, &arg1);
    olua_check_bool(L, 3, &arg2);

    // void changeDisplayWithName(const std::string &name, bool force)
    self->changeDisplayWithName(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_Bone_create1(lua_State *L)
{
    olua_startinvoke(L);

    // static cocostudio::Bone *create()
    cocostudio::Bone *ret = cocostudio::Bone::create();
    int num_ret = olua_push_cppobj(L, ret, "ccs.Bone");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_Bone_create2(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** name */

    olua_check_std_string(L, 1, &arg1);

    // static cocostudio::Bone *create(const std::string &name)
    cocostudio::Bone *ret = cocostudio::Bone::create(arg1);
    int num_ret = olua_push_cppobj(L, ret, "ccs.Bone");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_Bone_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // static cocostudio::Bone *create()
        return _cocostudio_Bone_create1(L);
    }

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 1))) {
            // static cocostudio::Bone *create(const std::string &name)
            return _cocostudio_Bone_create2(L);
        // }
    }

    luaL_error(L, "method 'cocostudio::Bone::create' not support '%d' arguments", num_args);

    return 0;
}

static int _cocostudio_Bone_getArmature(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Bone *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Bone");

    // cocostudio::Armature *getArmature()
    cocostudio::Armature *ret = self->getArmature();
    int num_ret = olua_push_cppobj(L, ret, "ccs.Armature");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_Bone_getBlendFunc(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Bone *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Bone");

    // cocos2d::BlendFunc getBlendFunc()
    cocos2d::BlendFunc ret = self->getBlendFunc();
    int num_ret = olua_push_cocos2d_BlendFunc(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_Bone_getBoneData(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Bone *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Bone");

    // cocostudio::BoneData *getBoneData()
    cocostudio::BoneData *ret = self->getBoneData();
    int num_ret = olua_push_cppobj(L, ret, "ccs.BoneData");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_Bone_getChildArmature(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Bone *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Bone");

    // cocostudio::Armature *getChildArmature()
    cocostudio::Armature *ret = self->getChildArmature();
    int num_ret = olua_push_cppobj(L, ret, "ccs.Armature");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_Bone_getColliderDetector(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Bone *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Bone");

    // cocostudio::ColliderDetector *getColliderDetector()
    cocostudio::ColliderDetector *ret = self->getColliderDetector();
    int num_ret = olua_push_cppobj(L, ret, "ccs.ColliderDetector");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_Bone_getDisplayManager(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Bone *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Bone");

    // cocostudio::DisplayManager *getDisplayManager()
    cocostudio::DisplayManager *ret = self->getDisplayManager();
    int num_ret = olua_push_cppobj(L, ret, "ccs.DisplayManager");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_Bone_getDisplayRenderNode(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Bone *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Bone");

    // cocos2d::Node *getDisplayRenderNode()
    cocos2d::Node *ret = self->getDisplayRenderNode();
    int num_ret = olua_push_cppobj(L, ret, "cc.Node");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_Bone_getDisplayRenderNodeType(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Bone *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Bone");

    // cocostudio::DisplayType getDisplayRenderNodeType()
    cocostudio::DisplayType ret = self->getDisplayRenderNodeType();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_Bone_getNodeToArmatureTransform(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Bone *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Bone");

    // cocos2d::Mat4 getNodeToArmatureTransform()
    cocos2d::Mat4 ret = self->getNodeToArmatureTransform();
    int num_ret = olua_push_cocos2d_Mat4(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_Bone_getParentBone(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Bone *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Bone");

    // cocostudio::Bone *getParentBone()
    cocostudio::Bone *ret = self->getParentBone();
    int num_ret = olua_push_cppobj(L, ret, "ccs.Bone");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_Bone_getTween(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Bone *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Bone");

    // cocostudio::Tween *getTween()
    cocostudio::Tween *ret = self->getTween();
    int num_ret = olua_push_cppobj(L, ret, "ccs.Tween");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_Bone_getTweenData(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Bone *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Bone");

    // cocostudio::FrameData *getTweenData()
    cocostudio::FrameData *ret = self->getTweenData();
    int num_ret = olua_push_cppobj(L, ret, "ccs.FrameData");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_Bone_getWorldInfo(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Bone *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Bone");

    // cocostudio::BaseData *getWorldInfo()
    cocostudio::BaseData *ret = self->getWorldInfo();
    int num_ret = olua_push_cppobj(L, ret, "ccs.BaseData");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_Bone_init1(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Bone *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Bone");

    // @using bool init()
    bool ret = self->init();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_Bone_init2(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Bone *self = nullptr;
    std::string arg1;       /** name */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Bone");
    olua_check_std_string(L, 2, &arg1);

    // bool init(const std::string &name)
    bool ret = self->init(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_Bone_init(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // @using bool init()
        return _cocostudio_Bone_init1(L);
    }

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 2))) {
            // bool init(const std::string &name)
            return _cocostudio_Bone_init2(L);
        // }
    }

    luaL_error(L, "method 'cocostudio::Bone::init' not support '%d' arguments", num_args);

    return 0;
}

static int _cocostudio_Bone_isBlendDirty(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Bone *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Bone");

    // bool isBlendDirty()
    bool ret = self->isBlendDirty();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_Bone_isIgnoreMovementBoneData(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Bone *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Bone");

    // bool isIgnoreMovementBoneData()
    bool ret = self->isIgnoreMovementBoneData();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_Bone_isTransformDirty(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Bone *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Bone");

    // bool isTransformDirty()
    bool ret = self->isTransformDirty();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_Bone_new(lua_State *L)
{
    olua_startinvoke(L);

    // Bone()
    cocostudio::Bone *ret = new cocostudio::Bone();
    int num_ret = olua_push_cppobj(L, ret, "ccs.Bone");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_Bone_removeChildBone(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Bone *self = nullptr;
    cocostudio::Bone *arg1 = nullptr;       /** bone */
    bool arg2 = false;       /** recursion */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Bone");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccs.Bone");
    olua_check_bool(L, 3, &arg2);

    // void removeChildBone(cocostudio::Bone *bone, bool recursion)
    self->removeChildBone(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_Bone_removeDisplay(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Bone *self = nullptr;
    lua_Integer arg1 = 0;       /** index */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Bone");
    olua_check_int(L, 2, &arg1);

    // void removeDisplay(int index)
    self->removeDisplay((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_Bone_removeFromParent1(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Bone *self = nullptr;
    bool arg1 = false;       /** recursion */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Bone");
    olua_check_bool(L, 2, &arg1);

    // insert code before call
    if (!self->getParent()) {
        return 0;
    }
    olua_push_cppobj<cocos2d::Node>(L, self->getParent());
    int parent = lua_gettop(L);

    // @delref(children | parent) void removeFromParent(bool recursion)
    self->removeFromParent(arg1);

    // insert code after call
    olua_delref(L, parent, "children", 1, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_Bone_removeFromParent2(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Bone *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Bone");

    // insert code before call
    if (!self->getParent()) {
        return 0;
    }
    olua_push_cppobj<cocos2d::Node>(L, self->getParent());
    int parent = lua_gettop(L);

    // @using @delref(children | parent) void removeFromParent()
    self->removeFromParent();

    // insert code after call
    olua_delref(L, parent, "children", 1, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_Bone_removeFromParent(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // @using @delref(children | parent) void removeFromParent()
        return _cocostudio_Bone_removeFromParent2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_bool(L, 2))) {
            // @delref(children | parent) void removeFromParent(bool recursion)
            return _cocostudio_Bone_removeFromParent1(L);
        // }
    }

    luaL_error(L, "method 'cocostudio::Bone::removeFromParent' not support '%d' arguments", num_args);

    return 0;
}

static int _cocostudio_Bone_setArmature(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Bone *self = nullptr;
    cocostudio::Armature *arg1 = nullptr;       /** armature */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Bone");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccs.Armature");

    // void setArmature(cocostudio::Armature *armature)
    self->setArmature(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_Bone_setBlendDirty(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Bone *self = nullptr;
    bool arg1 = false;       /** dirty */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Bone");
    olua_check_bool(L, 2, &arg1);

    // void setBlendDirty(bool dirty)
    self->setBlendDirty(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_Bone_setBlendFunc(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Bone *self = nullptr;
    cocos2d::BlendFunc arg1;       /** blendFunc */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Bone");
    olua_check_cocos2d_BlendFunc(L, 2, &arg1);

    // void setBlendFunc(const cocos2d::BlendFunc &blendFunc)
    self->setBlendFunc(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_Bone_setBoneData(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Bone *self = nullptr;
    cocostudio::BoneData *arg1 = nullptr;       /** boneData */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Bone");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccs.BoneData");

    // void setBoneData(cocostudio::BoneData *boneData)
    self->setBoneData(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_Bone_setChildArmature(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Bone *self = nullptr;
    cocostudio::Armature *arg1 = nullptr;       /** childArmature */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Bone");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccs.Armature");

    // void setChildArmature(cocostudio::Armature *childArmature)
    self->setChildArmature(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_Bone_setIgnoreMovementBoneData(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Bone *self = nullptr;
    bool arg1 = false;       /** ignore */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Bone");
    olua_check_bool(L, 2, &arg1);

    // void setIgnoreMovementBoneData(bool ignore)
    self->setIgnoreMovementBoneData(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_Bone_setLocalZOrder(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Bone *self = nullptr;
    lua_Integer arg1 = 0;       /** zOrder */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Bone");
    olua_check_int(L, 2, &arg1);

    // void setLocalZOrder(int zOrder)
    self->setLocalZOrder((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_Bone_setParentBone(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Bone *self = nullptr;
    cocostudio::Bone *arg1 = nullptr;       /** parent */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Bone");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccs.Bone");

    // void setParentBone(cocostudio::Bone *parent)
    self->setParentBone(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_Bone_setTransformDirty(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Bone *self = nullptr;
    bool arg1 = false;       /** dirty */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Bone");
    olua_check_bool(L, 2, &arg1);

    // void setTransformDirty(bool dirty)
    self->setTransformDirty(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_Bone_updateColor(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Bone *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Bone");

    // void updateColor()
    self->updateColor();

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_Bone_updateZOrder(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Bone *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Bone");

    // void updateZOrder()
    self->updateZOrder();

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocostudio_Bone(lua_State *L)
{
    oluacls_class(L, "ccs.Bone", "cc.Node");
    oluacls_func(L, "__olua_move", _cocostudio_Bone___olua_move);
    oluacls_func(L, "addChildBone", _cocostudio_Bone_addChildBone);
    oluacls_func(L, "addDisplay", _cocostudio_Bone_addDisplay);
    oluacls_func(L, "changeDisplayWithIndex", _cocostudio_Bone_changeDisplayWithIndex);
    oluacls_func(L, "changeDisplayWithName", _cocostudio_Bone_changeDisplayWithName);
    oluacls_func(L, "create", _cocostudio_Bone_create);
    oluacls_func(L, "getArmature", _cocostudio_Bone_getArmature);
    oluacls_func(L, "getBlendFunc", _cocostudio_Bone_getBlendFunc);
    oluacls_func(L, "getBoneData", _cocostudio_Bone_getBoneData);
    oluacls_func(L, "getChildArmature", _cocostudio_Bone_getChildArmature);
    oluacls_func(L, "getColliderDetector", _cocostudio_Bone_getColliderDetector);
    oluacls_func(L, "getDisplayManager", _cocostudio_Bone_getDisplayManager);
    oluacls_func(L, "getDisplayRenderNode", _cocostudio_Bone_getDisplayRenderNode);
    oluacls_func(L, "getDisplayRenderNodeType", _cocostudio_Bone_getDisplayRenderNodeType);
    oluacls_func(L, "getNodeToArmatureTransform", _cocostudio_Bone_getNodeToArmatureTransform);
    oluacls_func(L, "getParentBone", _cocostudio_Bone_getParentBone);
    oluacls_func(L, "getTween", _cocostudio_Bone_getTween);
    oluacls_func(L, "getTweenData", _cocostudio_Bone_getTweenData);
    oluacls_func(L, "getWorldInfo", _cocostudio_Bone_getWorldInfo);
    oluacls_func(L, "init", _cocostudio_Bone_init);
    oluacls_func(L, "isBlendDirty", _cocostudio_Bone_isBlendDirty);
    oluacls_func(L, "isIgnoreMovementBoneData", _cocostudio_Bone_isIgnoreMovementBoneData);
    oluacls_func(L, "isTransformDirty", _cocostudio_Bone_isTransformDirty);
    oluacls_func(L, "new", _cocostudio_Bone_new);
    oluacls_func(L, "removeChildBone", _cocostudio_Bone_removeChildBone);
    oluacls_func(L, "removeDisplay", _cocostudio_Bone_removeDisplay);
    oluacls_func(L, "removeFromParent", _cocostudio_Bone_removeFromParent);
    oluacls_func(L, "setArmature", _cocostudio_Bone_setArmature);
    oluacls_func(L, "setBlendDirty", _cocostudio_Bone_setBlendDirty);
    oluacls_func(L, "setBlendFunc", _cocostudio_Bone_setBlendFunc);
    oluacls_func(L, "setBoneData", _cocostudio_Bone_setBoneData);
    oluacls_func(L, "setChildArmature", _cocostudio_Bone_setChildArmature);
    oluacls_func(L, "setIgnoreMovementBoneData", _cocostudio_Bone_setIgnoreMovementBoneData);
    oluacls_func(L, "setLocalZOrder", _cocostudio_Bone_setLocalZOrder);
    oluacls_func(L, "setParentBone", _cocostudio_Bone_setParentBone);
    oluacls_func(L, "setTransformDirty", _cocostudio_Bone_setTransformDirty);
    oluacls_func(L, "updateColor", _cocostudio_Bone_updateColor);
    oluacls_func(L, "updateZOrder", _cocostudio_Bone_updateZOrder);
    oluacls_prop(L, "armature", _cocostudio_Bone_getArmature, _cocostudio_Bone_setArmature);
    oluacls_prop(L, "blendDirty", _cocostudio_Bone_isBlendDirty, _cocostudio_Bone_setBlendDirty);
    oluacls_prop(L, "blendFunc", _cocostudio_Bone_getBlendFunc, _cocostudio_Bone_setBlendFunc);
    oluacls_prop(L, "boneData", _cocostudio_Bone_getBoneData, _cocostudio_Bone_setBoneData);
    oluacls_prop(L, "childArmature", _cocostudio_Bone_getChildArmature, _cocostudio_Bone_setChildArmature);
    oluacls_prop(L, "colliderDetector", _cocostudio_Bone_getColliderDetector, nullptr);
    oluacls_prop(L, "displayManager", _cocostudio_Bone_getDisplayManager, nullptr);
    oluacls_prop(L, "displayRenderNode", _cocostudio_Bone_getDisplayRenderNode, nullptr);
    oluacls_prop(L, "displayRenderNodeType", _cocostudio_Bone_getDisplayRenderNodeType, nullptr);
    oluacls_prop(L, "ignoreMovementBoneData", _cocostudio_Bone_isIgnoreMovementBoneData, _cocostudio_Bone_setIgnoreMovementBoneData);
    oluacls_prop(L, "nodeToArmatureTransform", _cocostudio_Bone_getNodeToArmatureTransform, nullptr);
    oluacls_prop(L, "parentBone", _cocostudio_Bone_getParentBone, _cocostudio_Bone_setParentBone);
    oluacls_prop(L, "transformDirty", _cocostudio_Bone_isTransformDirty, _cocostudio_Bone_setTransformDirty);
    oluacls_prop(L, "tween", _cocostudio_Bone_getTween, nullptr);
    oluacls_prop(L, "tweenData", _cocostudio_Bone_getTweenData, nullptr);
    oluacls_prop(L, "worldInfo", _cocostudio_Bone_getWorldInfo, nullptr);

    olua_registerluatype<cocostudio::Bone>(L, "ccs.Bone");

    return 1;
}

static int _cocostudio_BoneData___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocostudio::BoneData *)olua_toobj(L, 1, "ccs.BoneData");
    olua_push_cppobj(L, self, "ccs.BoneData");

    olua_endinvoke(L);

    return 1;
}

static int _cocostudio_BoneData_addDisplayData(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::BoneData *self = nullptr;
    cocostudio::DisplayData *arg1 = nullptr;       /** displayData */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.BoneData");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccs.DisplayData");

    // void addDisplayData(cocostudio::DisplayData *displayData)
    self->addDisplayData(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_BoneData_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cocostudio::BoneData *create()
    cocostudio::BoneData *ret = cocostudio::BoneData::create();
    int num_ret = olua_push_cppobj(L, ret, "ccs.BoneData");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_BoneData_getDisplayData(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::BoneData *self = nullptr;
    lua_Integer arg1 = 0;       /** index */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.BoneData");
    olua_check_int(L, 2, &arg1);

    // cocostudio::DisplayData *getDisplayData(int index)
    cocostudio::DisplayData *ret = self->getDisplayData((int)arg1);
    int num_ret = olua_push_cppobj(L, ret, "ccs.DisplayData");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_BoneData_init(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::BoneData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.BoneData");

    // bool init()
    bool ret = self->init();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_BoneData_new(lua_State *L)
{
    olua_startinvoke(L);

    // BoneData()
    cocostudio::BoneData *ret = new cocostudio::BoneData();
    int num_ret = olua_push_cppobj(L, ret, "ccs.BoneData");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_BoneData_get_boneDataTransform(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::BoneData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.BoneData");

    // cocos2d::AffineTransform boneDataTransform
    cocos2d::AffineTransform ret = self->boneDataTransform;
    int num_ret = olua_push_cocos2d_AffineTransform(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_BoneData_set_boneDataTransform(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::BoneData *self = nullptr;
    cocos2d::AffineTransform arg1;       /** boneDataTransform */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.BoneData");
    olua_check_cocos2d_AffineTransform(L, 2, &arg1);

    // cocos2d::AffineTransform boneDataTransform
    self->boneDataTransform = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_BoneData_get_displayDataList(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::BoneData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.BoneData");

    // cocos2d::Vector<DisplayData *> displayDataList
    cocos2d::Vector<cocostudio::DisplayData *> ret = self->displayDataList;
    int num_ret = olua_push_cocos2d_Vector<cocostudio::DisplayData *>(L, &ret, [L](cocostudio::DisplayData *value) {
        olua_push_cppobj(L, value, "ccs.DisplayData");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_BoneData_set_displayDataList(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::BoneData *self = nullptr;
    cocos2d::Vector<cocostudio::DisplayData *> arg1;       /** displayDataList */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.BoneData");
    olua_check_cocos2d_Vector<cocostudio::DisplayData *>(L, 2, &arg1, [L](cocostudio::DisplayData **value) {
        olua_check_cppobj(L, -1, (void **)value, "ccs.DisplayData");
    });

    // cocos2d::Vector<DisplayData *> displayDataList
    self->displayDataList = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_BoneData_get_name(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::BoneData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.BoneData");

    // std::string name
    std::string ret = self->name;
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_BoneData_set_name(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::BoneData *self = nullptr;
    std::string arg1;       /** name */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.BoneData");
    olua_check_std_string(L, 2, &arg1);

    // std::string name
    self->name = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_BoneData_get_parentName(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::BoneData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.BoneData");

    // std::string parentName
    std::string ret = self->parentName;
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_BoneData_set_parentName(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::BoneData *self = nullptr;
    std::string arg1;       /** parentName */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.BoneData");
    olua_check_std_string(L, 2, &arg1);

    // std::string parentName
    self->parentName = arg1;

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocostudio_BoneData(lua_State *L)
{
    oluacls_class(L, "ccs.BoneData", "ccs.BaseData");
    oluacls_func(L, "__olua_move", _cocostudio_BoneData___olua_move);
    oluacls_func(L, "addDisplayData", _cocostudio_BoneData_addDisplayData);
    oluacls_func(L, "create", _cocostudio_BoneData_create);
    oluacls_func(L, "getDisplayData", _cocostudio_BoneData_getDisplayData);
    oluacls_func(L, "init", _cocostudio_BoneData_init);
    oluacls_func(L, "new", _cocostudio_BoneData_new);
    oluacls_prop(L, "boneDataTransform", _cocostudio_BoneData_get_boneDataTransform, _cocostudio_BoneData_set_boneDataTransform);
    oluacls_prop(L, "displayDataList", _cocostudio_BoneData_get_displayDataList, _cocostudio_BoneData_set_displayDataList);
    oluacls_prop(L, "name", _cocostudio_BoneData_get_name, _cocostudio_BoneData_set_name);
    oluacls_prop(L, "parentName", _cocostudio_BoneData_get_parentName, _cocostudio_BoneData_set_parentName);

    olua_registerluatype<cocostudio::BoneData>(L, "ccs.BoneData");

    return 1;
}

static int _cocostudio_CocoLoader___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocostudio::CocoLoader *)olua_toobj(L, 1, "ccs.CocoLoader");
    olua_push_cppobj(L, self, "ccs.CocoLoader");

    olua_endinvoke(L);

    return 1;
}

static int luaopen_cocostudio_CocoLoader(lua_State *L)
{
    oluacls_class(L, "ccs.CocoLoader", nullptr);
    oluacls_func(L, "__olua_move", _cocostudio_CocoLoader___olua_move);

    olua_registerluatype<cocostudio::CocoLoader>(L, "ccs.CocoLoader");

    return 1;
}

static int _cocostudio_ColliderBody___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocostudio::ColliderBody *)olua_toobj(L, 1, "ccs.ColliderBody");
    olua_push_cppobj(L, self, "ccs.ColliderBody");

    olua_endinvoke(L);

    return 1;
}

static int _cocostudio_ColliderBody_getCalculatedVertexList(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ColliderBody *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ColliderBody");

    // const std::vector<cocos2d::Vec2> &getCalculatedVertexList()
    const std::vector<cocos2d::Vec2> &ret = self->getCalculatedVertexList();
    int num_ret = olua_push_std_vector<cocos2d::Vec2>(L, &ret, [L](cocos2d::Vec2 value) {
        olua_push_cocos2d_Vec2(L, &value);
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ColliderBody_getContourData(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ColliderBody *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ColliderBody");

    // cocostudio::ContourData *getContourData()
    cocostudio::ContourData *ret = self->getContourData();
    int num_ret = olua_push_cppobj(L, ret, "ccs.ContourData");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ColliderBody_new(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ContourData *arg1 = nullptr;       /** contourData */

    olua_check_cppobj(L, 1, (void **)&arg1, "ccs.ContourData");

    // ColliderBody(cocostudio::ContourData *contourData)
    cocostudio::ColliderBody *ret = new cocostudio::ColliderBody(arg1);
    int num_ret = olua_push_cppobj(L, ret, "ccs.ColliderBody");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocostudio_ColliderBody(lua_State *L)
{
    oluacls_class(L, "ccs.ColliderBody", "cc.Ref");
    oluacls_func(L, "__olua_move", _cocostudio_ColliderBody___olua_move);
    oluacls_func(L, "getCalculatedVertexList", _cocostudio_ColliderBody_getCalculatedVertexList);
    oluacls_func(L, "getContourData", _cocostudio_ColliderBody_getContourData);
    oluacls_func(L, "new", _cocostudio_ColliderBody_new);
    oluacls_prop(L, "calculatedVertexList", _cocostudio_ColliderBody_getCalculatedVertexList, nullptr);
    oluacls_prop(L, "contourData", _cocostudio_ColliderBody_getContourData, nullptr);

    olua_registerluatype<cocostudio::ColliderBody>(L, "ccs.ColliderBody");

    return 1;
}

static int _cocostudio_ColliderDetector___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocostudio::ColliderDetector *)olua_toobj(L, 1, "ccs.ColliderDetector");
    olua_push_cppobj(L, self, "ccs.ColliderDetector");

    olua_endinvoke(L);

    return 1;
}

static int _cocostudio_ColliderDetector_addContourData(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ColliderDetector *self = nullptr;
    cocostudio::ContourData *arg1 = nullptr;       /** contourData */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ColliderDetector");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccs.ContourData");

    // void addContourData(cocostudio::ContourData *contourData)
    self->addContourData(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ColliderDetector_addContourDataList(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ColliderDetector *self = nullptr;
    cocos2d::Vector<cocostudio::ContourData *> arg1;       /** contourDataList */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ColliderDetector");
    olua_check_cocos2d_Vector<cocostudio::ContourData *>(L, 2, &arg1, [L](cocostudio::ContourData **value) {
        olua_check_cppobj(L, -1, (void **)value, "ccs.ContourData");
    });

    // void addContourDataList(cocos2d::Vector<ContourData *> &contourDataList)
    self->addContourDataList(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ColliderDetector_create1(lua_State *L)
{
    olua_startinvoke(L);

    // static cocostudio::ColliderDetector *create()
    cocostudio::ColliderDetector *ret = cocostudio::ColliderDetector::create();
    int num_ret = olua_push_cppobj(L, ret, "ccs.ColliderDetector");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ColliderDetector_create2(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Bone *arg1 = nullptr;       /** bone */

    olua_check_cppobj(L, 1, (void **)&arg1, "ccs.Bone");

    // static cocostudio::ColliderDetector *create(cocostudio::Bone *bone)
    cocostudio::ColliderDetector *ret = cocostudio::ColliderDetector::create(arg1);
    int num_ret = olua_push_cppobj(L, ret, "ccs.ColliderDetector");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ColliderDetector_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // static cocostudio::ColliderDetector *create()
        return _cocostudio_ColliderDetector_create1(L);
    }

    if (num_args == 1) {
        // if ((olua_is_cppobj(L, 1, "ccs.Bone"))) {
            // static cocostudio::ColliderDetector *create(cocostudio::Bone *bone)
            return _cocostudio_ColliderDetector_create2(L);
        // }
    }

    luaL_error(L, "method 'cocostudio::ColliderDetector::create' not support '%d' arguments", num_args);

    return 0;
}

static int _cocostudio_ColliderDetector_getActive(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ColliderDetector *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ColliderDetector");

    // bool getActive()
    bool ret = self->getActive();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ColliderDetector_getBone(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ColliderDetector *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ColliderDetector");

    // cocostudio::Bone *getBone()
    cocostudio::Bone *ret = self->getBone();
    int num_ret = olua_push_cppobj(L, ret, "ccs.Bone");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ColliderDetector_getColliderBodyList(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ColliderDetector *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ColliderDetector");

    // const cocos2d::Vector<ColliderBody *> &getColliderBodyList()
    const cocos2d::Vector<cocostudio::ColliderBody *> &ret = self->getColliderBodyList();
    int num_ret = olua_push_cocos2d_Vector<cocostudio::ColliderBody *>(L, &ret, [L](cocostudio::ColliderBody *value) {
        olua_push_cppobj(L, value, "ccs.ColliderBody");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ColliderDetector_init1(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ColliderDetector *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ColliderDetector");

    // bool init()
    bool ret = self->init();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ColliderDetector_init2(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ColliderDetector *self = nullptr;
    cocostudio::Bone *arg1 = nullptr;       /** bone */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ColliderDetector");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccs.Bone");

    // bool init(cocostudio::Bone *bone)
    bool ret = self->init(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ColliderDetector_init(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // bool init()
        return _cocostudio_ColliderDetector_init1(L);
    }

    if (num_args == 1) {
        // if ((olua_is_cppobj(L, 2, "ccs.Bone"))) {
            // bool init(cocostudio::Bone *bone)
            return _cocostudio_ColliderDetector_init2(L);
        // }
    }

    luaL_error(L, "method 'cocostudio::ColliderDetector::init' not support '%d' arguments", num_args);

    return 0;
}

static int _cocostudio_ColliderDetector_new(lua_State *L)
{
    olua_startinvoke(L);

    // ColliderDetector()
    cocostudio::ColliderDetector *ret = new cocostudio::ColliderDetector();
    int num_ret = olua_push_cppobj(L, ret, "ccs.ColliderDetector");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ColliderDetector_removeAll(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ColliderDetector *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ColliderDetector");

    // void removeAll()
    self->removeAll();

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ColliderDetector_removeContourData(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ColliderDetector *self = nullptr;
    cocostudio::ContourData *arg1 = nullptr;       /** contourData */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ColliderDetector");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccs.ContourData");

    // void removeContourData(cocostudio::ContourData *contourData)
    self->removeContourData(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ColliderDetector_setActive(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ColliderDetector *self = nullptr;
    bool arg1 = false;       /** active */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ColliderDetector");
    olua_check_bool(L, 2, &arg1);

    // void setActive(bool active)
    self->setActive(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ColliderDetector_setBone(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ColliderDetector *self = nullptr;
    cocostudio::Bone *arg1 = nullptr;       /** bone */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ColliderDetector");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccs.Bone");

    // void setBone(cocostudio::Bone *bone)
    self->setBone(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ColliderDetector_updateTransform(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ColliderDetector *self = nullptr;
    cocos2d::Mat4 arg1;       /** t */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ColliderDetector");
    olua_check_cocos2d_Mat4(L, 2, &arg1);

    // void updateTransform(cocos2d::Mat4 &t)
    self->updateTransform(arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocostudio_ColliderDetector(lua_State *L)
{
    oluacls_class(L, "ccs.ColliderDetector", "cc.Ref");
    oluacls_func(L, "__olua_move", _cocostudio_ColliderDetector___olua_move);
    oluacls_func(L, "addContourData", _cocostudio_ColliderDetector_addContourData);
    oluacls_func(L, "addContourDataList", _cocostudio_ColliderDetector_addContourDataList);
    oluacls_func(L, "create", _cocostudio_ColliderDetector_create);
    oluacls_func(L, "getActive", _cocostudio_ColliderDetector_getActive);
    oluacls_func(L, "getBone", _cocostudio_ColliderDetector_getBone);
    oluacls_func(L, "getColliderBodyList", _cocostudio_ColliderDetector_getColliderBodyList);
    oluacls_func(L, "init", _cocostudio_ColliderDetector_init);
    oluacls_func(L, "new", _cocostudio_ColliderDetector_new);
    oluacls_func(L, "removeAll", _cocostudio_ColliderDetector_removeAll);
    oluacls_func(L, "removeContourData", _cocostudio_ColliderDetector_removeContourData);
    oluacls_func(L, "setActive", _cocostudio_ColliderDetector_setActive);
    oluacls_func(L, "setBone", _cocostudio_ColliderDetector_setBone);
    oluacls_func(L, "updateTransform", _cocostudio_ColliderDetector_updateTransform);
    oluacls_prop(L, "active", _cocostudio_ColliderDetector_getActive, _cocostudio_ColliderDetector_setActive);
    oluacls_prop(L, "bone", _cocostudio_ColliderDetector_getBone, _cocostudio_ColliderDetector_setBone);
    oluacls_prop(L, "colliderBodyList", _cocostudio_ColliderDetector_getColliderBodyList, nullptr);

    olua_registerluatype<cocostudio::ColliderDetector>(L, "ccs.ColliderDetector");

    return 1;
}

static int _cocostudio_ColliderFilter___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocostudio::ColliderFilter *)olua_toobj(L, 1, "ccs.ColliderFilter");
    olua_push_cppobj(L, self, "ccs.ColliderFilter");

    olua_endinvoke(L);

    return 1;
}

static int luaopen_cocostudio_ColliderFilter(lua_State *L)
{
    oluacls_class(L, "ccs.ColliderFilter", nullptr);
    oluacls_func(L, "__olua_move", _cocostudio_ColliderFilter___olua_move);

    olua_registerluatype<cocostudio::ColliderFilter>(L, "ccs.ColliderFilter");

    return 1;
}

static int _cocostudio_ComAttribute___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocostudio::ComAttribute *)olua_toobj(L, 1, "ccs.ComAttribute");
    olua_push_cppobj(L, self, "ccs.ComAttribute");

    olua_endinvoke(L);

    return 1;
}

static int _cocostudio_ComAttribute_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cocostudio::ComAttribute *create()
    cocostudio::ComAttribute *ret = cocostudio::ComAttribute::create();
    int num_ret = olua_push_cppobj(L, ret, "ccs.ComAttribute");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ComAttribute_createInstance(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::Ref *createInstance()
    cocos2d::Ref *ret = cocostudio::ComAttribute::createInstance();
    int num_ret = olua_push_cppobj(L, ret, "cc.Ref");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ComAttribute_getBool1(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ComAttribute *self = nullptr;
    std::string arg1;       /** key */
    bool arg2 = false;       /** def */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ComAttribute");
    olua_check_std_string(L, 2, &arg1);
    olua_check_bool(L, 3, &arg2);

    // bool getBool(const std::string &key, @optional bool def)
    bool ret = self->getBool(arg1, arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ComAttribute_getBool2(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ComAttribute *self = nullptr;
    std::string arg1;       /** key */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ComAttribute");
    olua_check_std_string(L, 2, &arg1);

    // bool getBool(const std::string &key, @optional bool def)
    bool ret = self->getBool(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ComAttribute_getBool(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 2))) {
            // bool getBool(const std::string &key, @optional bool def)
            return _cocostudio_ComAttribute_getBool2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_bool(L, 3))) {
            // bool getBool(const std::string &key, @optional bool def)
            return _cocostudio_ComAttribute_getBool1(L);
        // }
    }

    luaL_error(L, "method 'cocostudio::ComAttribute::getBool' not support '%d' arguments", num_args);

    return 0;
}

static int _cocostudio_ComAttribute_getFloat1(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ComAttribute *self = nullptr;
    std::string arg1;       /** key */
    lua_Number arg2 = 0;       /** def */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ComAttribute");
    olua_check_std_string(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);

    // float getFloat(const std::string &key, @optional float def)
    float ret = self->getFloat(arg1, (float)arg2);
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ComAttribute_getFloat2(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ComAttribute *self = nullptr;
    std::string arg1;       /** key */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ComAttribute");
    olua_check_std_string(L, 2, &arg1);

    // float getFloat(const std::string &key, @optional float def)
    float ret = self->getFloat(arg1);
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ComAttribute_getFloat(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 2))) {
            // float getFloat(const std::string &key, @optional float def)
            return _cocostudio_ComAttribute_getFloat2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_number(L, 3))) {
            // float getFloat(const std::string &key, @optional float def)
            return _cocostudio_ComAttribute_getFloat1(L);
        // }
    }

    luaL_error(L, "method 'cocostudio::ComAttribute::getFloat' not support '%d' arguments", num_args);

    return 0;
}

static int _cocostudio_ComAttribute_getInt1(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ComAttribute *self = nullptr;
    std::string arg1;       /** key */
    lua_Integer arg2 = 0;       /** def */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ComAttribute");
    olua_check_std_string(L, 2, &arg1);
    olua_check_int(L, 3, &arg2);

    // int getInt(const std::string &key, @optional int def)
    int ret = self->getInt(arg1, (int)arg2);
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ComAttribute_getInt2(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ComAttribute *self = nullptr;
    std::string arg1;       /** key */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ComAttribute");
    olua_check_std_string(L, 2, &arg1);

    // int getInt(const std::string &key, @optional int def)
    int ret = self->getInt(arg1);
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ComAttribute_getInt(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 2))) {
            // int getInt(const std::string &key, @optional int def)
            return _cocostudio_ComAttribute_getInt2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_int(L, 3))) {
            // int getInt(const std::string &key, @optional int def)
            return _cocostudio_ComAttribute_getInt1(L);
        // }
    }

    luaL_error(L, "method 'cocostudio::ComAttribute::getInt' not support '%d' arguments", num_args);

    return 0;
}

static int _cocostudio_ComAttribute_getString1(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ComAttribute *self = nullptr;
    std::string arg1;       /** key */
    std::string arg2;       /** def */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ComAttribute");
    olua_check_std_string(L, 2, &arg1);
    olua_check_std_string(L, 3, &arg2);

    // std::string getString(const std::string &key, @optional const std::string &def)
    std::string ret = self->getString(arg1, arg2);
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ComAttribute_getString2(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ComAttribute *self = nullptr;
    std::string arg1;       /** key */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ComAttribute");
    olua_check_std_string(L, 2, &arg1);

    // std::string getString(const std::string &key, @optional const std::string &def)
    std::string ret = self->getString(arg1);
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ComAttribute_getString(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 2))) {
            // std::string getString(const std::string &key, @optional const std::string &def)
            return _cocostudio_ComAttribute_getString2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_std_string(L, 3))) {
            // std::string getString(const std::string &key, @optional const std::string &def)
            return _cocostudio_ComAttribute_getString1(L);
        // }
    }

    luaL_error(L, "method 'cocostudio::ComAttribute::getString' not support '%d' arguments", num_args);

    return 0;
}

static int _cocostudio_ComAttribute_new(lua_State *L)
{
    olua_startinvoke(L);

    // ComAttribute()
    cocostudio::ComAttribute *ret = new cocostudio::ComAttribute();
    int num_ret = olua_push_cppobj(L, ret, "ccs.ComAttribute");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ComAttribute_parse(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ComAttribute *self = nullptr;
    std::string arg1;       /** jsonFile */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ComAttribute");
    olua_check_std_string(L, 2, &arg1);

    // bool parse(const std::string &jsonFile)
    bool ret = self->parse(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ComAttribute_setBool(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ComAttribute *self = nullptr;
    std::string arg1;       /** key */
    bool arg2 = false;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ComAttribute");
    olua_check_std_string(L, 2, &arg1);
    olua_check_bool(L, 3, &arg2);

    // void setBool(const std::string &key, bool value)
    self->setBool(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ComAttribute_setFloat(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ComAttribute *self = nullptr;
    std::string arg1;       /** key */
    lua_Number arg2 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ComAttribute");
    olua_check_std_string(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);

    // void setFloat(const std::string &key, float value)
    self->setFloat(arg1, (float)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ComAttribute_setInt(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ComAttribute *self = nullptr;
    std::string arg1;       /** key */
    lua_Integer arg2 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ComAttribute");
    olua_check_std_string(L, 2, &arg1);
    olua_check_int(L, 3, &arg2);

    // void setInt(const std::string &key, int value)
    self->setInt(arg1, (int)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ComAttribute_setString(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ComAttribute *self = nullptr;
    std::string arg1;       /** key */
    std::string arg2;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ComAttribute");
    olua_check_std_string(L, 2, &arg1);
    olua_check_std_string(L, 3, &arg2);

    // void setString(const std::string &key, const std::string &value)
    self->setString(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocostudio_ComAttribute(lua_State *L)
{
    oluacls_class(L, "ccs.ComAttribute", "cc.Component");
    oluacls_func(L, "__olua_move", _cocostudio_ComAttribute___olua_move);
    oluacls_func(L, "create", _cocostudio_ComAttribute_create);
    oluacls_func(L, "createInstance", _cocostudio_ComAttribute_createInstance);
    oluacls_func(L, "getBool", _cocostudio_ComAttribute_getBool);
    oluacls_func(L, "getFloat", _cocostudio_ComAttribute_getFloat);
    oluacls_func(L, "getInt", _cocostudio_ComAttribute_getInt);
    oluacls_func(L, "getString", _cocostudio_ComAttribute_getString);
    oluacls_func(L, "new", _cocostudio_ComAttribute_new);
    oluacls_func(L, "parse", _cocostudio_ComAttribute_parse);
    oluacls_func(L, "setBool", _cocostudio_ComAttribute_setBool);
    oluacls_func(L, "setFloat", _cocostudio_ComAttribute_setFloat);
    oluacls_func(L, "setInt", _cocostudio_ComAttribute_setInt);
    oluacls_func(L, "setString", _cocostudio_ComAttribute_setString);
    oluacls_const_string(L, "COMPONENT_NAME", (const char *)cocostudio::ComAttribute::COMPONENT_NAME.c_str());

    olua_registerluatype<cocostudio::ComAttribute>(L, "ccs.ComAttribute");

    return 1;
}

static int _cocostudio_ComAudio___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocostudio::ComAudio *)olua_toobj(L, 1, "ccs.ComAudio");
    olua_push_cppobj(L, self, "ccs.ComAudio");

    olua_endinvoke(L);

    return 1;
}

static int _cocostudio_ComAudio_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cocostudio::ComAudio *create()
    cocostudio::ComAudio *ret = cocostudio::ComAudio::create();
    int num_ret = olua_push_cppobj(L, ret, "ccs.ComAudio");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ComAudio_createInstance(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::Ref *createInstance()
    cocos2d::Ref *ret = cocostudio::ComAudio::createInstance();
    int num_ret = olua_push_cppobj(L, ret, "cc.Ref");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ComAudio_end(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ComAudio *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ComAudio");

    // void end()
    self->end();

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ComAudio_getBackgroundMusicVolume(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ComAudio *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ComAudio");

    // float getBackgroundMusicVolume()
    float ret = self->getBackgroundMusicVolume();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ComAudio_getEffectsVolume(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ComAudio *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ComAudio");

    // float getEffectsVolume()
    float ret = self->getEffectsVolume();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ComAudio_getFile(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ComAudio *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ComAudio");

    // const char *getFile()
    const char *ret = self->getFile();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ComAudio_isBackgroundMusicPlaying(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ComAudio *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ComAudio");

    // bool isBackgroundMusicPlaying()
    bool ret = self->isBackgroundMusicPlaying();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ComAudio_isLoop(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ComAudio *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ComAudio");

    // bool isLoop()
    bool ret = self->isLoop();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ComAudio_new(lua_State *L)
{
    olua_startinvoke(L);

    // ComAudio()
    cocostudio::ComAudio *ret = new cocostudio::ComAudio();
    int num_ret = olua_push_cppobj(L, ret, "ccs.ComAudio");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ComAudio_pauseAllEffects(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ComAudio *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ComAudio");

    // void pauseAllEffects()
    self->pauseAllEffects();

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ComAudio_pauseBackgroundMusic(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ComAudio *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ComAudio");

    // void pauseBackgroundMusic()
    self->pauseBackgroundMusic();

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ComAudio_pauseEffect(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ComAudio *self = nullptr;
    lua_Unsigned arg1 = 0;       /** nSoundId */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ComAudio");
    olua_check_uint(L, 2, &arg1);

    // void pauseEffect(unsigned int nSoundId)
    self->pauseEffect((unsigned int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ComAudio_playBackgroundMusic1(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ComAudio *self = nullptr;
    const char *arg1 = nullptr;       /** pszFilePath */
    bool arg2 = false;       /** bLoop */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ComAudio");
    olua_check_string(L, 2, &arg1);
    olua_check_bool(L, 3, &arg2);

    // void playBackgroundMusic(const char *pszFilePath, bool bLoop)
    self->playBackgroundMusic(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ComAudio_playBackgroundMusic2(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ComAudio *self = nullptr;
    const char *arg1 = nullptr;       /** pszFilePath */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ComAudio");
    olua_check_string(L, 2, &arg1);

    // void playBackgroundMusic(const char *pszFilePath)
    self->playBackgroundMusic(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ComAudio_playBackgroundMusic3(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ComAudio *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ComAudio");

    // void playBackgroundMusic()
    self->playBackgroundMusic();

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ComAudio_playBackgroundMusic(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // void playBackgroundMusic()
        return _cocostudio_ComAudio_playBackgroundMusic3(L);
    }

    if (num_args == 1) {
        // if ((olua_is_string(L, 2))) {
            // void playBackgroundMusic(const char *pszFilePath)
            return _cocostudio_ComAudio_playBackgroundMusic2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_string(L, 2)) && (olua_is_bool(L, 3))) {
            // void playBackgroundMusic(const char *pszFilePath, bool bLoop)
            return _cocostudio_ComAudio_playBackgroundMusic1(L);
        // }
    }

    luaL_error(L, "method 'cocostudio::ComAudio::playBackgroundMusic' not support '%d' arguments", num_args);

    return 0;
}

static int _cocostudio_ComAudio_playEffect1(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ComAudio *self = nullptr;
    const char *arg1 = nullptr;       /** pszFilePath */
    bool arg2 = false;       /** bLoop */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ComAudio");
    olua_check_string(L, 2, &arg1);
    olua_check_bool(L, 3, &arg2);

    // unsigned int playEffect(const char *pszFilePath, bool bLoop)
    unsigned int ret = self->playEffect(arg1, arg2);
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ComAudio_playEffect2(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ComAudio *self = nullptr;
    const char *arg1 = nullptr;       /** pszFilePath */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ComAudio");
    olua_check_string(L, 2, &arg1);

    // unsigned int playEffect(const char *pszFilePath)
    unsigned int ret = self->playEffect(arg1);
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ComAudio_playEffect3(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ComAudio *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ComAudio");

    // unsigned int playEffect()
    unsigned int ret = self->playEffect();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ComAudio_playEffect(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // unsigned int playEffect()
        return _cocostudio_ComAudio_playEffect3(L);
    }

    if (num_args == 1) {
        // if ((olua_is_string(L, 2))) {
            // unsigned int playEffect(const char *pszFilePath)
            return _cocostudio_ComAudio_playEffect2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_string(L, 2)) && (olua_is_bool(L, 3))) {
            // unsigned int playEffect(const char *pszFilePath, bool bLoop)
            return _cocostudio_ComAudio_playEffect1(L);
        // }
    }

    luaL_error(L, "method 'cocostudio::ComAudio::playEffect' not support '%d' arguments", num_args);

    return 0;
}

static int _cocostudio_ComAudio_preloadBackgroundMusic(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ComAudio *self = nullptr;
    const char *arg1 = nullptr;       /** pszFilePath */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ComAudio");
    olua_check_string(L, 2, &arg1);

    // void preloadBackgroundMusic(const char *pszFilePath)
    self->preloadBackgroundMusic(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ComAudio_preloadEffect(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ComAudio *self = nullptr;
    const char *arg1 = nullptr;       /** pszFilePath */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ComAudio");
    olua_check_string(L, 2, &arg1);

    // void preloadEffect(const char *pszFilePath)
    self->preloadEffect(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ComAudio_resumeAllEffects(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ComAudio *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ComAudio");

    // void resumeAllEffects()
    self->resumeAllEffects();

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ComAudio_resumeBackgroundMusic(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ComAudio *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ComAudio");

    // void resumeBackgroundMusic()
    self->resumeBackgroundMusic();

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ComAudio_resumeEffect(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ComAudio *self = nullptr;
    lua_Unsigned arg1 = 0;       /** nSoundId */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ComAudio");
    olua_check_uint(L, 2, &arg1);

    // void resumeEffect(unsigned int nSoundId)
    self->resumeEffect((unsigned int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ComAudio_rewindBackgroundMusic(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ComAudio *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ComAudio");

    // void rewindBackgroundMusic()
    self->rewindBackgroundMusic();

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ComAudio_setBackgroundMusicVolume(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ComAudio *self = nullptr;
    lua_Number arg1 = 0;       /** volume */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ComAudio");
    olua_check_number(L, 2, &arg1);

    // void setBackgroundMusicVolume(float volume)
    self->setBackgroundMusicVolume((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ComAudio_setEffectsVolume(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ComAudio *self = nullptr;
    lua_Number arg1 = 0;       /** volume */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ComAudio");
    olua_check_number(L, 2, &arg1);

    // void setEffectsVolume(float volume)
    self->setEffectsVolume((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ComAudio_setFile(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ComAudio *self = nullptr;
    const char *arg1 = nullptr;       /** pszFilePath */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ComAudio");
    olua_check_string(L, 2, &arg1);

    // void setFile(const char *pszFilePath)
    self->setFile(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ComAudio_setLoop(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ComAudio *self = nullptr;
    bool arg1 = false;       /** bLoop */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ComAudio");
    olua_check_bool(L, 2, &arg1);

    // void setLoop(bool bLoop)
    self->setLoop(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ComAudio_start(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ComAudio *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ComAudio");

    // void start()
    self->start();

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ComAudio_stop(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ComAudio *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ComAudio");

    // void stop()
    self->stop();

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ComAudio_stopAllEffects(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ComAudio *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ComAudio");

    // void stopAllEffects()
    self->stopAllEffects();

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ComAudio_stopBackgroundMusic1(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ComAudio *self = nullptr;
    bool arg1 = false;       /** bReleaseData */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ComAudio");
    olua_check_bool(L, 2, &arg1);

    // void stopBackgroundMusic(bool bReleaseData)
    self->stopBackgroundMusic(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ComAudio_stopBackgroundMusic2(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ComAudio *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ComAudio");

    // void stopBackgroundMusic()
    self->stopBackgroundMusic();

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ComAudio_stopBackgroundMusic(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // void stopBackgroundMusic()
        return _cocostudio_ComAudio_stopBackgroundMusic2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_bool(L, 2))) {
            // void stopBackgroundMusic(bool bReleaseData)
            return _cocostudio_ComAudio_stopBackgroundMusic1(L);
        // }
    }

    luaL_error(L, "method 'cocostudio::ComAudio::stopBackgroundMusic' not support '%d' arguments", num_args);

    return 0;
}

static int _cocostudio_ComAudio_stopEffect(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ComAudio *self = nullptr;
    lua_Unsigned arg1 = 0;       /** nSoundId */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ComAudio");
    olua_check_uint(L, 2, &arg1);

    // void stopEffect(unsigned int nSoundId)
    self->stopEffect((unsigned int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ComAudio_unloadEffect(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ComAudio *self = nullptr;
    const char *arg1 = nullptr;       /** pszFilePath */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ComAudio");
    olua_check_string(L, 2, &arg1);

    // void unloadEffect(const char *pszFilePath)
    self->unloadEffect(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ComAudio_willPlayBackgroundMusic(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ComAudio *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ComAudio");

    // bool willPlayBackgroundMusic()
    bool ret = self->willPlayBackgroundMusic();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocostudio_ComAudio(lua_State *L)
{
    oluacls_class(L, "ccs.ComAudio", "cc.Component");
    oluacls_func(L, "__olua_move", _cocostudio_ComAudio___olua_move);
    oluacls_func(L, "create", _cocostudio_ComAudio_create);
    oluacls_func(L, "createInstance", _cocostudio_ComAudio_createInstance);
    oluacls_func(L, "end", _cocostudio_ComAudio_end);
    oluacls_func(L, "getBackgroundMusicVolume", _cocostudio_ComAudio_getBackgroundMusicVolume);
    oluacls_func(L, "getEffectsVolume", _cocostudio_ComAudio_getEffectsVolume);
    oluacls_func(L, "getFile", _cocostudio_ComAudio_getFile);
    oluacls_func(L, "isBackgroundMusicPlaying", _cocostudio_ComAudio_isBackgroundMusicPlaying);
    oluacls_func(L, "isLoop", _cocostudio_ComAudio_isLoop);
    oluacls_func(L, "new", _cocostudio_ComAudio_new);
    oluacls_func(L, "pauseAllEffects", _cocostudio_ComAudio_pauseAllEffects);
    oluacls_func(L, "pauseBackgroundMusic", _cocostudio_ComAudio_pauseBackgroundMusic);
    oluacls_func(L, "pauseEffect", _cocostudio_ComAudio_pauseEffect);
    oluacls_func(L, "playBackgroundMusic", _cocostudio_ComAudio_playBackgroundMusic);
    oluacls_func(L, "playEffect", _cocostudio_ComAudio_playEffect);
    oluacls_func(L, "preloadBackgroundMusic", _cocostudio_ComAudio_preloadBackgroundMusic);
    oluacls_func(L, "preloadEffect", _cocostudio_ComAudio_preloadEffect);
    oluacls_func(L, "resumeAllEffects", _cocostudio_ComAudio_resumeAllEffects);
    oluacls_func(L, "resumeBackgroundMusic", _cocostudio_ComAudio_resumeBackgroundMusic);
    oluacls_func(L, "resumeEffect", _cocostudio_ComAudio_resumeEffect);
    oluacls_func(L, "rewindBackgroundMusic", _cocostudio_ComAudio_rewindBackgroundMusic);
    oluacls_func(L, "setBackgroundMusicVolume", _cocostudio_ComAudio_setBackgroundMusicVolume);
    oluacls_func(L, "setEffectsVolume", _cocostudio_ComAudio_setEffectsVolume);
    oluacls_func(L, "setFile", _cocostudio_ComAudio_setFile);
    oluacls_func(L, "setLoop", _cocostudio_ComAudio_setLoop);
    oluacls_func(L, "start", _cocostudio_ComAudio_start);
    oluacls_func(L, "stop", _cocostudio_ComAudio_stop);
    oluacls_func(L, "stopAllEffects", _cocostudio_ComAudio_stopAllEffects);
    oluacls_func(L, "stopBackgroundMusic", _cocostudio_ComAudio_stopBackgroundMusic);
    oluacls_func(L, "stopEffect", _cocostudio_ComAudio_stopEffect);
    oluacls_func(L, "unloadEffect", _cocostudio_ComAudio_unloadEffect);
    oluacls_func(L, "willPlayBackgroundMusic", _cocostudio_ComAudio_willPlayBackgroundMusic);
    oluacls_prop(L, "backgroundMusicPlaying", _cocostudio_ComAudio_isBackgroundMusicPlaying, nullptr);
    oluacls_prop(L, "backgroundMusicVolume", _cocostudio_ComAudio_getBackgroundMusicVolume, _cocostudio_ComAudio_setBackgroundMusicVolume);
    oluacls_prop(L, "effectsVolume", _cocostudio_ComAudio_getEffectsVolume, _cocostudio_ComAudio_setEffectsVolume);
    oluacls_prop(L, "file", _cocostudio_ComAudio_getFile, _cocostudio_ComAudio_setFile);
    oluacls_prop(L, "loop", _cocostudio_ComAudio_isLoop, _cocostudio_ComAudio_setLoop);
    oluacls_const_string(L, "COMPONENT_NAME", (const char *)cocostudio::ComAudio::COMPONENT_NAME.c_str());

    olua_registerluatype<cocostudio::ComAudio>(L, "ccs.ComAudio");

    return 1;
}

static int _cocostudio_ComController___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocostudio::ComController *)olua_toobj(L, 1, "ccs.ComController");
    olua_push_cppobj(L, self, "ccs.ComController");

    olua_endinvoke(L);

    return 1;
}

static int _cocostudio_ComController_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cocostudio::ComController *create()
    cocostudio::ComController *ret = cocostudio::ComController::create();
    int num_ret = olua_push_cppobj(L, ret, "ccs.ComController");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ComController_createInstance(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::Ref *createInstance()
    cocos2d::Ref *ret = cocostudio::ComController::createInstance();
    int num_ret = olua_push_cppobj(L, ret, "cc.Ref");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ComController_new(lua_State *L)
{
    olua_startinvoke(L);

    // ComController()
    cocostudio::ComController *ret = new cocostudio::ComController();
    int num_ret = olua_push_cppobj(L, ret, "ccs.ComController");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocostudio_ComController(lua_State *L)
{
    oluacls_class(L, "ccs.ComController", "cc.Component");
    oluacls_func(L, "__olua_move", _cocostudio_ComController___olua_move);
    oluacls_func(L, "create", _cocostudio_ComController_create);
    oluacls_func(L, "createInstance", _cocostudio_ComController_createInstance);
    oluacls_func(L, "new", _cocostudio_ComController_new);
    oluacls_const_string(L, "COMPONENT_NAME", (const char *)cocostudio::ComController::COMPONENT_NAME.c_str());

    olua_registerluatype<cocostudio::ComController>(L, "ccs.ComController");

    return 1;
}

static int _cocostudio_ComRender___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocostudio::ComRender *)olua_toobj(L, 1, "ccs.ComRender");
    olua_push_cppobj(L, self, "ccs.ComRender");

    olua_endinvoke(L);

    return 1;
}

static int _cocostudio_ComRender_create1(lua_State *L)
{
    olua_startinvoke(L);

    // static cocostudio::ComRender *create()
    cocostudio::ComRender *ret = cocostudio::ComRender::create();
    int num_ret = olua_push_cppobj(L, ret, "ccs.ComRender");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ComRender_create2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Node *arg1 = nullptr;       /** node */
    const char *arg2 = nullptr;       /** comName */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.Node");
    olua_check_string(L, 2, &arg2);

    // static cocostudio::ComRender *create(cocos2d::Node *node, const char *comName)
    cocostudio::ComRender *ret = cocostudio::ComRender::create(arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "ccs.ComRender");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ComRender_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // static cocostudio::ComRender *create()
        return _cocostudio_ComRender_create1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_cppobj(L, 1, "cc.Node")) && (olua_is_string(L, 2))) {
            // static cocostudio::ComRender *create(cocos2d::Node *node, const char *comName)
            return _cocostudio_ComRender_create2(L);
        // }
    }

    luaL_error(L, "method 'cocostudio::ComRender::create' not support '%d' arguments", num_args);

    return 0;
}

static int _cocostudio_ComRender_createInstance(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::Ref *createInstance()
    cocos2d::Ref *ret = cocostudio::ComRender::createInstance();
    int num_ret = olua_push_cppobj(L, ret, "cc.Ref");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ComRender_getNode(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ComRender *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ComRender");

    // cocos2d::Node *getNode()
    cocos2d::Node *ret = self->getNode();
    int num_ret = olua_push_cppobj(L, ret, "cc.Node");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ComRender_new1(lua_State *L)
{
    olua_startinvoke(L);

    // ComRender()
    cocostudio::ComRender *ret = new cocostudio::ComRender();
    int num_ret = olua_push_cppobj(L, ret, "ccs.ComRender");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ComRender_new2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Node *arg1 = nullptr;       /** node */
    const char *arg2 = nullptr;       /** comName */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.Node");
    olua_check_string(L, 2, &arg2);

    // ComRender(cocos2d::Node *node, const char *comName)
    cocostudio::ComRender *ret = new cocostudio::ComRender(arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "ccs.ComRender");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ComRender_new(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // ComRender()
        return _cocostudio_ComRender_new1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_cppobj(L, 1, "cc.Node")) && (olua_is_string(L, 2))) {
            // ComRender(cocos2d::Node *node, const char *comName)
            return _cocostudio_ComRender_new2(L);
        // }
    }

    luaL_error(L, "method 'cocostudio::ComRender::new' not support '%d' arguments", num_args);

    return 0;
}

static int _cocostudio_ComRender_setNode(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ComRender *self = nullptr;
    cocos2d::Node *arg1 = nullptr;       /** node */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ComRender");
    olua_check_cppobj(L, 2, (void **)&arg1, "cc.Node");

    // void setNode(cocos2d::Node *node)
    self->setNode(arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocostudio_ComRender(lua_State *L)
{
    oluacls_class(L, "ccs.ComRender", "cc.Component");
    oluacls_func(L, "__olua_move", _cocostudio_ComRender___olua_move);
    oluacls_func(L, "create", _cocostudio_ComRender_create);
    oluacls_func(L, "createInstance", _cocostudio_ComRender_createInstance);
    oluacls_func(L, "getNode", _cocostudio_ComRender_getNode);
    oluacls_func(L, "new", _cocostudio_ComRender_new);
    oluacls_func(L, "setNode", _cocostudio_ComRender_setNode);
    oluacls_prop(L, "node", _cocostudio_ComRender_getNode, _cocostudio_ComRender_setNode);
    oluacls_const_string(L, "COMPONENT_NAME", (const char *)cocostudio::ComRender::COMPONENT_NAME.c_str());

    olua_registerluatype<cocostudio::ComRender>(L, "ccs.ComRender");

    return 1;
}

static int _cocostudio_ContourData___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocostudio::ContourData *)olua_toobj(L, 1, "ccs.ContourData");
    olua_push_cppobj(L, self, "ccs.ContourData");

    olua_endinvoke(L);

    return 1;
}

static int _cocostudio_ContourData_addVertex(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ContourData *self = nullptr;
    cocos2d::Vec2 arg1;       /** vertex */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ContourData");
    olua_check_cocos2d_Vec2(L, 2, &arg1);

    // void addVertex(cocos2d::Vec2 &vertex)
    self->addVertex(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_ContourData_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cocostudio::ContourData *create()
    cocostudio::ContourData *ret = cocostudio::ContourData::create();
    int num_ret = olua_push_cppobj(L, ret, "ccs.ContourData");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ContourData_init(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ContourData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ContourData");

    // bool init()
    bool ret = self->init();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ContourData_new(lua_State *L)
{
    olua_startinvoke(L);

    // ContourData()
    cocostudio::ContourData *ret = new cocostudio::ContourData();
    int num_ret = olua_push_cppobj(L, ret, "ccs.ContourData");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ContourData_get_vertexList(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ContourData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ContourData");

    // std::vector<cocos2d::Vec2> vertexList
    std::vector<cocos2d::Vec2> ret = self->vertexList;
    int num_ret = olua_push_std_vector<cocos2d::Vec2>(L, &ret, [L](cocos2d::Vec2 value) {
        olua_push_cocos2d_Vec2(L, &value);
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ContourData_set_vertexList(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::ContourData *self = nullptr;
    std::vector<cocos2d::Vec2> arg1;       /** vertexList */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.ContourData");
    olua_check_std_vector<cocos2d::Vec2>(L, 2, &arg1, [L](cocos2d::Vec2 *value) {
        olua_check_cocos2d_Vec2(L, -1, value);
    });

    // std::vector<cocos2d::Vec2> vertexList
    self->vertexList = arg1;

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocostudio_ContourData(lua_State *L)
{
    oluacls_class(L, "ccs.ContourData", "cc.Ref");
    oluacls_func(L, "__olua_move", _cocostudio_ContourData___olua_move);
    oluacls_func(L, "addVertex", _cocostudio_ContourData_addVertex);
    oluacls_func(L, "create", _cocostudio_ContourData_create);
    oluacls_func(L, "init", _cocostudio_ContourData_init);
    oluacls_func(L, "new", _cocostudio_ContourData_new);
    oluacls_prop(L, "vertexList", _cocostudio_ContourData_get_vertexList, _cocostudio_ContourData_set_vertexList);

    olua_registerluatype<cocostudio::ContourData>(L, "ccs.ContourData");

    return 1;
}

static int _cocostudio_DataReaderHelper___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_postgc<cocostudio::DataReaderHelper>(L, 1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_DataReaderHelper___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocostudio::DataReaderHelper *)olua_toobj(L, 1, "ccs.DataReaderHelper");
    olua_push_cppobj(L, self, "ccs.DataReaderHelper");

    olua_endinvoke(L);

    return 1;
}

static int _cocostudio_DataReaderHelper_addDataAsyncCallBack(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::DataReaderHelper *self = nullptr;
    lua_Number arg1 = 0;       /** dt */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.DataReaderHelper");
    olua_check_number(L, 2, &arg1);

    // void addDataAsyncCallBack(float dt)
    self->addDataAsyncCallBack((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_DataReaderHelper_addDataFromFile(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::DataReaderHelper *self = nullptr;
    std::string arg1;       /** filePath */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.DataReaderHelper");
    olua_check_std_string(L, 2, &arg1);

    // void addDataFromFile(const std::string &filePath)
    self->addDataFromFile(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_DataReaderHelper_getInstance(lua_State *L)
{
    olua_startinvoke(L);

    // static cocostudio::DataReaderHelper *getInstance()
    cocostudio::DataReaderHelper *ret = cocostudio::DataReaderHelper::getInstance();
    int num_ret = olua_push_cppobj(L, ret, "ccs.DataReaderHelper");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_DataReaderHelper_getPositionReadScale(lua_State *L)
{
    olua_startinvoke(L);

    // static float getPositionReadScale()
    float ret = cocostudio::DataReaderHelper::getPositionReadScale();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_DataReaderHelper_new(lua_State *L)
{
    olua_startinvoke(L);

    // DataReaderHelper()
    cocostudio::DataReaderHelper *ret = new cocostudio::DataReaderHelper();
    int num_ret = olua_push_cppobj(L, ret, "ccs.DataReaderHelper");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_DataReaderHelper_purge(lua_State *L)
{
    olua_startinvoke(L);

    // static void purge()
    cocostudio::DataReaderHelper::purge();

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_DataReaderHelper_removeConfigFile(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::DataReaderHelper *self = nullptr;
    std::string arg1;       /** configFile */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.DataReaderHelper");
    olua_check_std_string(L, 2, &arg1);

    // void removeConfigFile(const std::string &configFile)
    self->removeConfigFile(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_DataReaderHelper_setPositionReadScale(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** scale */

    olua_check_number(L, 1, &arg1);

    // static void setPositionReadScale(float scale)
    cocostudio::DataReaderHelper::setPositionReadScale((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocostudio_DataReaderHelper(lua_State *L)
{
    oluacls_class(L, "ccs.DataReaderHelper", nullptr);
    oluacls_func(L, "__gc", _cocostudio_DataReaderHelper___gc);
    oluacls_func(L, "__olua_move", _cocostudio_DataReaderHelper___olua_move);
    oluacls_func(L, "addDataAsyncCallBack", _cocostudio_DataReaderHelper_addDataAsyncCallBack);
    oluacls_func(L, "addDataFromFile", _cocostudio_DataReaderHelper_addDataFromFile);
    oluacls_func(L, "getInstance", _cocostudio_DataReaderHelper_getInstance);
    oluacls_func(L, "getPositionReadScale", _cocostudio_DataReaderHelper_getPositionReadScale);
    oluacls_func(L, "new", _cocostudio_DataReaderHelper_new);
    oluacls_func(L, "purge", _cocostudio_DataReaderHelper_purge);
    oluacls_func(L, "removeConfigFile", _cocostudio_DataReaderHelper_removeConfigFile);
    oluacls_func(L, "setPositionReadScale", _cocostudio_DataReaderHelper_setPositionReadScale);
    oluacls_prop(L, "instance", _cocostudio_DataReaderHelper_getInstance, nullptr);
    oluacls_prop(L, "positionReadScale", _cocostudio_DataReaderHelper_getPositionReadScale, _cocostudio_DataReaderHelper_setPositionReadScale);

    olua_registerluatype<cocostudio::DataReaderHelper>(L, "ccs.DataReaderHelper");

    return 1;
}

static int _cocostudio_DecorativeDisplay___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocostudio::DecorativeDisplay *)olua_toobj(L, 1, "ccs.DecorativeDisplay");
    olua_push_cppobj(L, self, "ccs.DecorativeDisplay");

    olua_endinvoke(L);

    return 1;
}

static int _cocostudio_DecorativeDisplay_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cocostudio::DecorativeDisplay *create()
    cocostudio::DecorativeDisplay *ret = cocostudio::DecorativeDisplay::create();
    int num_ret = olua_push_cppobj(L, ret, "ccs.DecorativeDisplay");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_DecorativeDisplay_getColliderDetector(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::DecorativeDisplay *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.DecorativeDisplay");

    // cocostudio::ColliderDetector *getColliderDetector()
    cocostudio::ColliderDetector *ret = self->getColliderDetector();
    int num_ret = olua_push_cppobj(L, ret, "ccs.ColliderDetector");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_DecorativeDisplay_getDisplay(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::DecorativeDisplay *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.DecorativeDisplay");

    // cocos2d::Node *getDisplay()
    cocos2d::Node *ret = self->getDisplay();
    int num_ret = olua_push_cppobj(L, ret, "cc.Node");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_DecorativeDisplay_getDisplayData(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::DecorativeDisplay *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.DecorativeDisplay");

    // cocostudio::DisplayData *getDisplayData()
    cocostudio::DisplayData *ret = self->getDisplayData();
    int num_ret = olua_push_cppobj(L, ret, "ccs.DisplayData");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_DecorativeDisplay_init(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::DecorativeDisplay *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.DecorativeDisplay");

    // bool init()
    bool ret = self->init();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_DecorativeDisplay_new(lua_State *L)
{
    olua_startinvoke(L);

    // DecorativeDisplay()
    cocostudio::DecorativeDisplay *ret = new cocostudio::DecorativeDisplay();
    int num_ret = olua_push_cppobj(L, ret, "ccs.DecorativeDisplay");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_DecorativeDisplay_setColliderDetector(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::DecorativeDisplay *self = nullptr;
    cocostudio::ColliderDetector *arg1 = nullptr;       /** detector */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.DecorativeDisplay");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccs.ColliderDetector");

    // void setColliderDetector(cocostudio::ColliderDetector *detector)
    self->setColliderDetector(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_DecorativeDisplay_setDisplay(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::DecorativeDisplay *self = nullptr;
    cocos2d::Node *arg1 = nullptr;       /** display */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.DecorativeDisplay");
    olua_check_cppobj(L, 2, (void **)&arg1, "cc.Node");

    // void setDisplay(cocos2d::Node *display)
    self->setDisplay(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_DecorativeDisplay_setDisplayData(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::DecorativeDisplay *self = nullptr;
    cocostudio::DisplayData *arg1 = nullptr;       /** data */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.DecorativeDisplay");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccs.DisplayData");

    // void setDisplayData(cocostudio::DisplayData *data)
    self->setDisplayData(arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocostudio_DecorativeDisplay(lua_State *L)
{
    oluacls_class(L, "ccs.DecorativeDisplay", "cc.Ref");
    oluacls_func(L, "__olua_move", _cocostudio_DecorativeDisplay___olua_move);
    oluacls_func(L, "create", _cocostudio_DecorativeDisplay_create);
    oluacls_func(L, "getColliderDetector", _cocostudio_DecorativeDisplay_getColliderDetector);
    oluacls_func(L, "getDisplay", _cocostudio_DecorativeDisplay_getDisplay);
    oluacls_func(L, "getDisplayData", _cocostudio_DecorativeDisplay_getDisplayData);
    oluacls_func(L, "init", _cocostudio_DecorativeDisplay_init);
    oluacls_func(L, "new", _cocostudio_DecorativeDisplay_new);
    oluacls_func(L, "setColliderDetector", _cocostudio_DecorativeDisplay_setColliderDetector);
    oluacls_func(L, "setDisplay", _cocostudio_DecorativeDisplay_setDisplay);
    oluacls_func(L, "setDisplayData", _cocostudio_DecorativeDisplay_setDisplayData);
    oluacls_prop(L, "colliderDetector", _cocostudio_DecorativeDisplay_getColliderDetector, _cocostudio_DecorativeDisplay_setColliderDetector);
    oluacls_prop(L, "display", _cocostudio_DecorativeDisplay_getDisplay, _cocostudio_DecorativeDisplay_setDisplay);
    oluacls_prop(L, "displayData", _cocostudio_DecorativeDisplay_getDisplayData, _cocostudio_DecorativeDisplay_setDisplayData);

    olua_registerluatype<cocostudio::DecorativeDisplay>(L, "ccs.DecorativeDisplay");

    return 1;
}

static int _cocostudio_DisplayFactory___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocostudio::DisplayFactory *)olua_toobj(L, 1, "ccs.DisplayFactory");
    olua_push_cppobj(L, self, "ccs.DisplayFactory");

    olua_endinvoke(L);

    return 1;
}

static int _cocostudio_DisplayFactory_addArmatureDisplay(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Bone *arg1 = nullptr;       /** bone */
    cocostudio::DecorativeDisplay *arg2 = nullptr;       /** decoDisplay */
    cocostudio::DisplayData *arg3 = nullptr;       /** displayData */

    olua_check_cppobj(L, 1, (void **)&arg1, "ccs.Bone");
    olua_check_cppobj(L, 2, (void **)&arg2, "ccs.DecorativeDisplay");
    olua_check_cppobj(L, 3, (void **)&arg3, "ccs.DisplayData");

    // static void addArmatureDisplay(cocostudio::Bone *bone, cocostudio::DecorativeDisplay *decoDisplay, cocostudio::DisplayData *displayData)
    cocostudio::DisplayFactory::addArmatureDisplay(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_DisplayFactory_addDisplay(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Bone *arg1 = nullptr;       /** bone */
    cocostudio::DecorativeDisplay *arg2 = nullptr;       /** decoDisplay */
    cocostudio::DisplayData *arg3 = nullptr;       /** displayData */

    olua_check_cppobj(L, 1, (void **)&arg1, "ccs.Bone");
    olua_check_cppobj(L, 2, (void **)&arg2, "ccs.DecorativeDisplay");
    olua_check_cppobj(L, 3, (void **)&arg3, "ccs.DisplayData");

    // static void addDisplay(cocostudio::Bone *bone, cocostudio::DecorativeDisplay *decoDisplay, cocostudio::DisplayData *displayData)
    cocostudio::DisplayFactory::addDisplay(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_DisplayFactory_addParticleDisplay(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Bone *arg1 = nullptr;       /** bone */
    cocostudio::DecorativeDisplay *arg2 = nullptr;       /** decoDisplay */
    cocostudio::DisplayData *arg3 = nullptr;       /** displayData */

    olua_check_cppobj(L, 1, (void **)&arg1, "ccs.Bone");
    olua_check_cppobj(L, 2, (void **)&arg2, "ccs.DecorativeDisplay");
    olua_check_cppobj(L, 3, (void **)&arg3, "ccs.DisplayData");

    // static void addParticleDisplay(cocostudio::Bone *bone, cocostudio::DecorativeDisplay *decoDisplay, cocostudio::DisplayData *displayData)
    cocostudio::DisplayFactory::addParticleDisplay(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_DisplayFactory_addSpriteDisplay(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Bone *arg1 = nullptr;       /** bone */
    cocostudio::DecorativeDisplay *arg2 = nullptr;       /** decoDisplay */
    cocostudio::DisplayData *arg3 = nullptr;       /** displayData */

    olua_check_cppobj(L, 1, (void **)&arg1, "ccs.Bone");
    olua_check_cppobj(L, 2, (void **)&arg2, "ccs.DecorativeDisplay");
    olua_check_cppobj(L, 3, (void **)&arg3, "ccs.DisplayData");

    // static void addSpriteDisplay(cocostudio::Bone *bone, cocostudio::DecorativeDisplay *decoDisplay, cocostudio::DisplayData *displayData)
    cocostudio::DisplayFactory::addSpriteDisplay(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_DisplayFactory_createArmatureDisplay(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Bone *arg1 = nullptr;       /** bone */
    cocostudio::DecorativeDisplay *arg2 = nullptr;       /** decoDisplay */

    olua_check_cppobj(L, 1, (void **)&arg1, "ccs.Bone");
    olua_check_cppobj(L, 2, (void **)&arg2, "ccs.DecorativeDisplay");

    // static void createArmatureDisplay(cocostudio::Bone *bone, cocostudio::DecorativeDisplay *decoDisplay)
    cocostudio::DisplayFactory::createArmatureDisplay(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_DisplayFactory_createDisplay(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Bone *arg1 = nullptr;       /** bone */
    cocostudio::DecorativeDisplay *arg2 = nullptr;       /** decoDisplay */

    olua_check_cppobj(L, 1, (void **)&arg1, "ccs.Bone");
    olua_check_cppobj(L, 2, (void **)&arg2, "ccs.DecorativeDisplay");

    // static void createDisplay(cocostudio::Bone *bone, cocostudio::DecorativeDisplay *decoDisplay)
    cocostudio::DisplayFactory::createDisplay(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_DisplayFactory_createParticleDisplay(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Bone *arg1 = nullptr;       /** bone */
    cocostudio::DecorativeDisplay *arg2 = nullptr;       /** decoDisplay */

    olua_check_cppobj(L, 1, (void **)&arg1, "ccs.Bone");
    olua_check_cppobj(L, 2, (void **)&arg2, "ccs.DecorativeDisplay");

    // static void createParticleDisplay(cocostudio::Bone *bone, cocostudio::DecorativeDisplay *decoDisplay)
    cocostudio::DisplayFactory::createParticleDisplay(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_DisplayFactory_createSpriteDisplay(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Bone *arg1 = nullptr;       /** bone */
    cocostudio::DecorativeDisplay *arg2 = nullptr;       /** decoDisplay */

    olua_check_cppobj(L, 1, (void **)&arg1, "ccs.Bone");
    olua_check_cppobj(L, 2, (void **)&arg2, "ccs.DecorativeDisplay");

    // static void createSpriteDisplay(cocostudio::Bone *bone, cocostudio::DecorativeDisplay *decoDisplay)
    cocostudio::DisplayFactory::createSpriteDisplay(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_DisplayFactory_initSpriteDisplay(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Bone *arg1 = nullptr;       /** bone */
    cocostudio::DecorativeDisplay *arg2 = nullptr;       /** decoDisplay */
    const char *arg3 = nullptr;       /** displayName */
    cocostudio::Skin *arg4 = nullptr;       /** skin */

    olua_check_cppobj(L, 1, (void **)&arg1, "ccs.Bone");
    olua_check_cppobj(L, 2, (void **)&arg2, "ccs.DecorativeDisplay");
    olua_check_string(L, 3, &arg3);
    olua_check_cppobj(L, 4, (void **)&arg4, "ccs.Skin");

    // static void initSpriteDisplay(cocostudio::Bone *bone, cocostudio::DecorativeDisplay *decoDisplay, const char *displayName, cocostudio::Skin *skin)
    cocostudio::DisplayFactory::initSpriteDisplay(arg1, arg2, arg3, arg4);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_DisplayFactory_updateArmatureDisplay(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Bone *arg1 = nullptr;       /** bone */
    cocos2d::Node *arg2 = nullptr;       /** display */
    lua_Number arg3 = 0;       /** dt */

    olua_check_cppobj(L, 1, (void **)&arg1, "ccs.Bone");
    olua_check_cppobj(L, 2, (void **)&arg2, "cc.Node");
    olua_check_number(L, 3, &arg3);

    // static void updateArmatureDisplay(cocostudio::Bone *bone, cocos2d::Node *display, float dt)
    cocostudio::DisplayFactory::updateArmatureDisplay(arg1, arg2, (float)arg3);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_DisplayFactory_updateDisplay(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Bone *arg1 = nullptr;       /** bone */
    lua_Number arg2 = 0;       /** dt */
    bool arg3 = false;       /** dirty */

    olua_check_cppobj(L, 1, (void **)&arg1, "ccs.Bone");
    olua_check_number(L, 2, &arg2);
    olua_check_bool(L, 3, &arg3);

    // static void updateDisplay(cocostudio::Bone *bone, float dt, bool dirty)
    cocostudio::DisplayFactory::updateDisplay(arg1, (float)arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_DisplayFactory_updateParticleDisplay(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Bone *arg1 = nullptr;       /** bone */
    cocos2d::Node *arg2 = nullptr;       /** display */
    lua_Number arg3 = 0;       /** dt */

    olua_check_cppobj(L, 1, (void **)&arg1, "ccs.Bone");
    olua_check_cppobj(L, 2, (void **)&arg2, "cc.Node");
    olua_check_number(L, 3, &arg3);

    // static void updateParticleDisplay(cocostudio::Bone *bone, cocos2d::Node *display, float dt)
    cocostudio::DisplayFactory::updateParticleDisplay(arg1, arg2, (float)arg3);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocostudio_DisplayFactory(lua_State *L)
{
    oluacls_class(L, "ccs.DisplayFactory", nullptr);
    oluacls_func(L, "__olua_move", _cocostudio_DisplayFactory___olua_move);
    oluacls_func(L, "addArmatureDisplay", _cocostudio_DisplayFactory_addArmatureDisplay);
    oluacls_func(L, "addDisplay", _cocostudio_DisplayFactory_addDisplay);
    oluacls_func(L, "addParticleDisplay", _cocostudio_DisplayFactory_addParticleDisplay);
    oluacls_func(L, "addSpriteDisplay", _cocostudio_DisplayFactory_addSpriteDisplay);
    oluacls_func(L, "createArmatureDisplay", _cocostudio_DisplayFactory_createArmatureDisplay);
    oluacls_func(L, "createDisplay", _cocostudio_DisplayFactory_createDisplay);
    oluacls_func(L, "createParticleDisplay", _cocostudio_DisplayFactory_createParticleDisplay);
    oluacls_func(L, "createSpriteDisplay", _cocostudio_DisplayFactory_createSpriteDisplay);
    oluacls_func(L, "initSpriteDisplay", _cocostudio_DisplayFactory_initSpriteDisplay);
    oluacls_func(L, "updateArmatureDisplay", _cocostudio_DisplayFactory_updateArmatureDisplay);
    oluacls_func(L, "updateDisplay", _cocostudio_DisplayFactory_updateDisplay);
    oluacls_func(L, "updateParticleDisplay", _cocostudio_DisplayFactory_updateParticleDisplay);

    olua_registerluatype<cocostudio::DisplayFactory>(L, "ccs.DisplayFactory");

    return 1;
}

static int _cocostudio_DisplayManager___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocostudio::DisplayManager *)olua_toobj(L, 1, "ccs.DisplayManager");
    olua_push_cppobj(L, self, "ccs.DisplayManager");

    olua_endinvoke(L);

    return 1;
}

static int _cocostudio_DisplayManager_addDisplay1(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::DisplayManager *self = nullptr;
    cocostudio::DisplayData *arg1 = nullptr;       /** displayData */
    lua_Integer arg2 = 0;       /** index */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.DisplayManager");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccs.DisplayData");
    olua_check_int(L, 3, &arg2);

    // void addDisplay(cocostudio::DisplayData *displayData, int index)
    self->addDisplay(arg1, (int)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_DisplayManager_addDisplay2(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::DisplayManager *self = nullptr;
    cocos2d::Node *arg1 = nullptr;       /** display */
    lua_Integer arg2 = 0;       /** index */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.DisplayManager");
    olua_check_cppobj(L, 2, (void **)&arg1, "cc.Node");
    olua_check_int(L, 3, &arg2);

    // void addDisplay(cocos2d::Node *display, int index)
    self->addDisplay(arg1, (int)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_DisplayManager_addDisplay(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 2) {
        if ((olua_is_cppobj(L, 2, "ccs.DisplayData")) && (olua_is_int(L, 3))) {
            // void addDisplay(cocostudio::DisplayData *displayData, int index)
            return _cocostudio_DisplayManager_addDisplay1(L);
        }

        // if ((olua_is_cppobj(L, 2, "cc.Node")) && (olua_is_int(L, 3))) {
            // void addDisplay(cocos2d::Node *display, int index)
            return _cocostudio_DisplayManager_addDisplay2(L);
        // }
    }

    luaL_error(L, "method 'cocostudio::DisplayManager::addDisplay' not support '%d' arguments", num_args);

    return 0;
}

static int _cocostudio_DisplayManager_changeDisplayWithIndex(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::DisplayManager *self = nullptr;
    lua_Integer arg1 = 0;       /** index */
    bool arg2 = false;       /** force */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.DisplayManager");
    olua_check_int(L, 2, &arg1);
    olua_check_bool(L, 3, &arg2);

    // void changeDisplayWithIndex(int index, bool force)
    self->changeDisplayWithIndex((int)arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_DisplayManager_changeDisplayWithName(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::DisplayManager *self = nullptr;
    std::string arg1;       /** name */
    bool arg2 = false;       /** force */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.DisplayManager");
    olua_check_std_string(L, 2, &arg1);
    olua_check_bool(L, 3, &arg2);

    // void changeDisplayWithName(const std::string &name, bool force)
    self->changeDisplayWithName(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_DisplayManager_containPoint1(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::DisplayManager *self = nullptr;
    cocos2d::Vec2 arg1;       /** _point */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.DisplayManager");
    olua_check_cocos2d_Vec2(L, 2, &arg1);

    // bool containPoint(cocos2d::Vec2 &_point)
    bool ret = self->containPoint(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_DisplayManager_containPoint2(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::DisplayManager *self = nullptr;
    lua_Number arg1 = 0;       /** x */
    lua_Number arg2 = 0;       /** y */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.DisplayManager");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);

    // bool containPoint(float x, float y)
    bool ret = self->containPoint((float)arg1, (float)arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_DisplayManager_containPoint(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_cocos2d_Vec2(L, 2))) {
            // bool containPoint(cocos2d::Vec2 &_point)
            return _cocostudio_DisplayManager_containPoint1(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_number(L, 2)) && (olua_is_number(L, 3))) {
            // bool containPoint(float x, float y)
            return _cocostudio_DisplayManager_containPoint2(L);
        // }
    }

    luaL_error(L, "method 'cocostudio::DisplayManager::containPoint' not support '%d' arguments", num_args);

    return 0;
}

static int _cocostudio_DisplayManager_create(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Bone *arg1 = nullptr;       /** bone */

    olua_check_cppobj(L, 1, (void **)&arg1, "ccs.Bone");

    // static cocostudio::DisplayManager *create(cocostudio::Bone *bone)
    cocostudio::DisplayManager *ret = cocostudio::DisplayManager::create(arg1);
    int num_ret = olua_push_cppobj(L, ret, "ccs.DisplayManager");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_DisplayManager_getAnchorPoint(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::DisplayManager *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.DisplayManager");

    // cocos2d::Vec2 getAnchorPoint()
    cocos2d::Vec2 ret = self->getAnchorPoint();
    int num_ret = olua_push_cocos2d_Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_DisplayManager_getAnchorPointInPoints(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::DisplayManager *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.DisplayManager");

    // cocos2d::Vec2 getAnchorPointInPoints()
    cocos2d::Vec2 ret = self->getAnchorPointInPoints();
    int num_ret = olua_push_cocos2d_Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_DisplayManager_getBoundingBox(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::DisplayManager *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.DisplayManager");

    // cocos2d::Rect getBoundingBox()
    cocos2d::Rect ret = self->getBoundingBox();
    int num_ret = olua_push_cocos2d_Rect(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_DisplayManager_getContentSize(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::DisplayManager *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.DisplayManager");

    // cocos2d::Size getContentSize()
    cocos2d::Size ret = self->getContentSize();
    int num_ret = olua_push_cocos2d_Size(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_DisplayManager_getCurrentDecorativeDisplay(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::DisplayManager *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.DisplayManager");

    // cocostudio::DecorativeDisplay *getCurrentDecorativeDisplay()
    cocostudio::DecorativeDisplay *ret = self->getCurrentDecorativeDisplay();
    int num_ret = olua_push_cppobj(L, ret, "ccs.DecorativeDisplay");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_DisplayManager_getCurrentDisplayIndex(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::DisplayManager *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.DisplayManager");

    // int getCurrentDisplayIndex()
    int ret = self->getCurrentDisplayIndex();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_DisplayManager_getDecorativeDisplayByIndex(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::DisplayManager *self = nullptr;
    lua_Integer arg1 = 0;       /** index */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.DisplayManager");
    olua_check_int(L, 2, &arg1);

    // cocostudio::DecorativeDisplay *getDecorativeDisplayByIndex(int index)
    cocostudio::DecorativeDisplay *ret = self->getDecorativeDisplayByIndex((int)arg1);
    int num_ret = olua_push_cppobj(L, ret, "ccs.DecorativeDisplay");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_DisplayManager_getDecorativeDisplayList(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::DisplayManager *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.DisplayManager");

    // const cocos2d::Vector<DecorativeDisplay *> &getDecorativeDisplayList()
    const cocos2d::Vector<cocostudio::DecorativeDisplay *> &ret = self->getDecorativeDisplayList();
    int num_ret = olua_push_cocos2d_Vector<cocostudio::DecorativeDisplay *>(L, &ret, [L](cocostudio::DecorativeDisplay *value) {
        olua_push_cppobj(L, value, "ccs.DecorativeDisplay");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_DisplayManager_getDisplayRenderNode(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::DisplayManager *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.DisplayManager");

    // cocos2d::Node *getDisplayRenderNode()
    cocos2d::Node *ret = self->getDisplayRenderNode();
    int num_ret = olua_push_cppobj(L, ret, "cc.Node");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_DisplayManager_getDisplayRenderNodeType(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::DisplayManager *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.DisplayManager");

    // cocostudio::DisplayType getDisplayRenderNodeType()
    cocostudio::DisplayType ret = self->getDisplayRenderNodeType();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_DisplayManager_init(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::DisplayManager *self = nullptr;
    cocostudio::Bone *arg1 = nullptr;       /** bone */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.DisplayManager");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccs.Bone");

    // bool init(cocostudio::Bone *bone)
    bool ret = self->init(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_DisplayManager_initDisplayList(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::DisplayManager *self = nullptr;
    cocostudio::BoneData *arg1 = nullptr;       /** boneData */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.DisplayManager");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccs.BoneData");

    // void initDisplayList(cocostudio::BoneData *boneData)
    self->initDisplayList(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_DisplayManager_isForceChangeDisplay(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::DisplayManager *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.DisplayManager");

    // bool isForceChangeDisplay()
    bool ret = self->isForceChangeDisplay();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_DisplayManager_isVisible(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::DisplayManager *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.DisplayManager");

    // bool isVisible()
    bool ret = self->isVisible();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_DisplayManager_new(lua_State *L)
{
    olua_startinvoke(L);

    // DisplayManager()
    cocostudio::DisplayManager *ret = new cocostudio::DisplayManager();
    int num_ret = olua_push_cppobj(L, ret, "ccs.DisplayManager");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_DisplayManager_removeDisplay(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::DisplayManager *self = nullptr;
    lua_Integer arg1 = 0;       /** index */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.DisplayManager");
    olua_check_int(L, 2, &arg1);

    // void removeDisplay(int index)
    self->removeDisplay((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_DisplayManager_setCurrentDecorativeDisplay(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::DisplayManager *self = nullptr;
    cocostudio::DecorativeDisplay *arg1 = nullptr;       /** decoDisplay */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.DisplayManager");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccs.DecorativeDisplay");

    // void setCurrentDecorativeDisplay(cocostudio::DecorativeDisplay *decoDisplay)
    self->setCurrentDecorativeDisplay(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_DisplayManager_setForceChangeDisplay(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::DisplayManager *self = nullptr;
    bool arg1 = false;       /** force */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.DisplayManager");
    olua_check_bool(L, 2, &arg1);

    // void setForceChangeDisplay(bool force)
    self->setForceChangeDisplay(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_DisplayManager_setVisible(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::DisplayManager *self = nullptr;
    bool arg1 = false;       /** visible */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.DisplayManager");
    olua_check_bool(L, 2, &arg1);

    // void setVisible(bool visible)
    self->setVisible(arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocostudio_DisplayManager(lua_State *L)
{
    oluacls_class(L, "ccs.DisplayManager", "cc.Ref");
    oluacls_func(L, "__olua_move", _cocostudio_DisplayManager___olua_move);
    oluacls_func(L, "addDisplay", _cocostudio_DisplayManager_addDisplay);
    oluacls_func(L, "changeDisplayWithIndex", _cocostudio_DisplayManager_changeDisplayWithIndex);
    oluacls_func(L, "changeDisplayWithName", _cocostudio_DisplayManager_changeDisplayWithName);
    oluacls_func(L, "containPoint", _cocostudio_DisplayManager_containPoint);
    oluacls_func(L, "create", _cocostudio_DisplayManager_create);
    oluacls_func(L, "getAnchorPoint", _cocostudio_DisplayManager_getAnchorPoint);
    oluacls_func(L, "getAnchorPointInPoints", _cocostudio_DisplayManager_getAnchorPointInPoints);
    oluacls_func(L, "getBoundingBox", _cocostudio_DisplayManager_getBoundingBox);
    oluacls_func(L, "getContentSize", _cocostudio_DisplayManager_getContentSize);
    oluacls_func(L, "getCurrentDecorativeDisplay", _cocostudio_DisplayManager_getCurrentDecorativeDisplay);
    oluacls_func(L, "getCurrentDisplayIndex", _cocostudio_DisplayManager_getCurrentDisplayIndex);
    oluacls_func(L, "getDecorativeDisplayByIndex", _cocostudio_DisplayManager_getDecorativeDisplayByIndex);
    oluacls_func(L, "getDecorativeDisplayList", _cocostudio_DisplayManager_getDecorativeDisplayList);
    oluacls_func(L, "getDisplayRenderNode", _cocostudio_DisplayManager_getDisplayRenderNode);
    oluacls_func(L, "getDisplayRenderNodeType", _cocostudio_DisplayManager_getDisplayRenderNodeType);
    oluacls_func(L, "init", _cocostudio_DisplayManager_init);
    oluacls_func(L, "initDisplayList", _cocostudio_DisplayManager_initDisplayList);
    oluacls_func(L, "isForceChangeDisplay", _cocostudio_DisplayManager_isForceChangeDisplay);
    oluacls_func(L, "isVisible", _cocostudio_DisplayManager_isVisible);
    oluacls_func(L, "new", _cocostudio_DisplayManager_new);
    oluacls_func(L, "removeDisplay", _cocostudio_DisplayManager_removeDisplay);
    oluacls_func(L, "setCurrentDecorativeDisplay", _cocostudio_DisplayManager_setCurrentDecorativeDisplay);
    oluacls_func(L, "setForceChangeDisplay", _cocostudio_DisplayManager_setForceChangeDisplay);
    oluacls_func(L, "setVisible", _cocostudio_DisplayManager_setVisible);
    oluacls_prop(L, "anchorPoint", _cocostudio_DisplayManager_getAnchorPoint, nullptr);
    oluacls_prop(L, "anchorPointInPoints", _cocostudio_DisplayManager_getAnchorPointInPoints, nullptr);
    oluacls_prop(L, "boundingBox", _cocostudio_DisplayManager_getBoundingBox, nullptr);
    oluacls_prop(L, "contentSize", _cocostudio_DisplayManager_getContentSize, nullptr);
    oluacls_prop(L, "currentDecorativeDisplay", _cocostudio_DisplayManager_getCurrentDecorativeDisplay, _cocostudio_DisplayManager_setCurrentDecorativeDisplay);
    oluacls_prop(L, "currentDisplayIndex", _cocostudio_DisplayManager_getCurrentDisplayIndex, nullptr);
    oluacls_prop(L, "decorativeDisplayList", _cocostudio_DisplayManager_getDecorativeDisplayList, nullptr);
    oluacls_prop(L, "displayRenderNode", _cocostudio_DisplayManager_getDisplayRenderNode, nullptr);
    oluacls_prop(L, "displayRenderNodeType", _cocostudio_DisplayManager_getDisplayRenderNodeType, nullptr);
    oluacls_prop(L, "forceChangeDisplay", _cocostudio_DisplayManager_isForceChangeDisplay, _cocostudio_DisplayManager_setForceChangeDisplay);
    oluacls_prop(L, "visible", _cocostudio_DisplayManager_isVisible, _cocostudio_DisplayManager_setVisible);

    olua_registerluatype<cocostudio::DisplayManager>(L, "ccs.DisplayManager");

    return 1;
}

static int _cocostudio_FrameData___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocostudio::FrameData *)olua_toobj(L, 1, "ccs.FrameData");
    olua_push_cppobj(L, self, "ccs.FrameData");

    olua_endinvoke(L);

    return 1;
}

static int _cocostudio_FrameData_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cocostudio::FrameData *create()
    cocostudio::FrameData *ret = cocostudio::FrameData::create();
    int num_ret = olua_push_cppobj(L, ret, "ccs.FrameData");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_FrameData_new(lua_State *L)
{
    olua_startinvoke(L);

    // FrameData()
    cocostudio::FrameData *ret = new cocostudio::FrameData();
    int num_ret = olua_push_cppobj(L, ret, "ccs.FrameData");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_FrameData_get_blendFunc(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::FrameData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.FrameData");

    // cocos2d::BlendFunc blendFunc
    cocos2d::BlendFunc ret = self->blendFunc;
    int num_ret = olua_push_cocos2d_BlendFunc(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_FrameData_set_blendFunc(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::FrameData *self = nullptr;
    cocos2d::BlendFunc arg1;       /** blendFunc */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.FrameData");
    olua_check_cocos2d_BlendFunc(L, 2, &arg1);

    // cocos2d::BlendFunc blendFunc
    self->blendFunc = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_FrameData_get_displayIndex(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::FrameData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.FrameData");

    // int displayIndex
    int ret = self->displayIndex;
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_FrameData_set_displayIndex(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::FrameData *self = nullptr;
    lua_Integer arg1 = 0;       /** displayIndex */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.FrameData");
    olua_check_int(L, 2, &arg1);

    // int displayIndex
    self->displayIndex = (int)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_FrameData_get_duration(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::FrameData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.FrameData");

    // int duration
    int ret = self->duration;
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_FrameData_set_duration(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::FrameData *self = nullptr;
    lua_Integer arg1 = 0;       /** duration */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.FrameData");
    olua_check_int(L, 2, &arg1);

    // int duration
    self->duration = (int)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_FrameData_get_easingParamNumber(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::FrameData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.FrameData");

    // int easingParamNumber
    int ret = self->easingParamNumber;
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_FrameData_set_easingParamNumber(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::FrameData *self = nullptr;
    lua_Integer arg1 = 0;       /** easingParamNumber */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.FrameData");
    olua_check_int(L, 2, &arg1);

    // int easingParamNumber
    self->easingParamNumber = (int)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_FrameData_get_frameID(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::FrameData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.FrameData");

    // int frameID
    int ret = self->frameID;
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_FrameData_set_frameID(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::FrameData *self = nullptr;
    lua_Integer arg1 = 0;       /** frameID */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.FrameData");
    olua_check_int(L, 2, &arg1);

    // int frameID
    self->frameID = (int)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_FrameData_get_isTween(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::FrameData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.FrameData");

    // bool isTween
    bool ret = self->isTween;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_FrameData_set_isTween(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::FrameData *self = nullptr;
    bool arg1 = false;       /** isTween */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.FrameData");
    olua_check_bool(L, 2, &arg1);

    // bool isTween
    self->isTween = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_FrameData_get_strEvent(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::FrameData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.FrameData");

    // std::string strEvent
    std::string ret = self->strEvent;
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_FrameData_set_strEvent(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::FrameData *self = nullptr;
    std::string arg1;       /** strEvent */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.FrameData");
    olua_check_std_string(L, 2, &arg1);

    // std::string strEvent
    self->strEvent = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_FrameData_get_strMovement(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::FrameData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.FrameData");

    // std::string strMovement
    std::string ret = self->strMovement;
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_FrameData_set_strMovement(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::FrameData *self = nullptr;
    std::string arg1;       /** strMovement */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.FrameData");
    olua_check_std_string(L, 2, &arg1);

    // std::string strMovement
    self->strMovement = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_FrameData_get_strSound(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::FrameData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.FrameData");

    // std::string strSound
    std::string ret = self->strSound;
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_FrameData_set_strSound(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::FrameData *self = nullptr;
    std::string arg1;       /** strSound */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.FrameData");
    olua_check_std_string(L, 2, &arg1);

    // std::string strSound
    self->strSound = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_FrameData_get_strSoundEffect(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::FrameData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.FrameData");

    // std::string strSoundEffect
    std::string ret = self->strSoundEffect;
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_FrameData_set_strSoundEffect(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::FrameData *self = nullptr;
    std::string arg1;       /** strSoundEffect */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.FrameData");
    olua_check_std_string(L, 2, &arg1);

    // std::string strSoundEffect
    self->strSoundEffect = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_FrameData_get_tweenEasing(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::FrameData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.FrameData");

    // cocos2d::tweenfunc::TweenType tweenEasing
    cocos2d::tweenfunc::TweenType ret = self->tweenEasing;
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_FrameData_set_tweenEasing(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::FrameData *self = nullptr;
    lua_Unsigned arg1 = 0;       /** tweenEasing */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.FrameData");
    olua_check_uint(L, 2, &arg1);

    // cocos2d::tweenfunc::TweenType tweenEasing
    self->tweenEasing = (cocos2d::tweenfunc::TweenType)arg1;

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocostudio_FrameData(lua_State *L)
{
    oluacls_class(L, "ccs.FrameData", "ccs.BaseData");
    oluacls_func(L, "__olua_move", _cocostudio_FrameData___olua_move);
    oluacls_func(L, "create", _cocostudio_FrameData_create);
    oluacls_func(L, "new", _cocostudio_FrameData_new);
    oluacls_prop(L, "blendFunc", _cocostudio_FrameData_get_blendFunc, _cocostudio_FrameData_set_blendFunc);
    oluacls_prop(L, "displayIndex", _cocostudio_FrameData_get_displayIndex, _cocostudio_FrameData_set_displayIndex);
    oluacls_prop(L, "duration", _cocostudio_FrameData_get_duration, _cocostudio_FrameData_set_duration);
    oluacls_prop(L, "easingParamNumber", _cocostudio_FrameData_get_easingParamNumber, _cocostudio_FrameData_set_easingParamNumber);
    oluacls_prop(L, "frameID", _cocostudio_FrameData_get_frameID, _cocostudio_FrameData_set_frameID);
    oluacls_prop(L, "isTween", _cocostudio_FrameData_get_isTween, _cocostudio_FrameData_set_isTween);
    oluacls_prop(L, "strEvent", _cocostudio_FrameData_get_strEvent, _cocostudio_FrameData_set_strEvent);
    oluacls_prop(L, "strMovement", _cocostudio_FrameData_get_strMovement, _cocostudio_FrameData_set_strMovement);
    oluacls_prop(L, "strSound", _cocostudio_FrameData_get_strSound, _cocostudio_FrameData_set_strSound);
    oluacls_prop(L, "strSoundEffect", _cocostudio_FrameData_get_strSoundEffect, _cocostudio_FrameData_set_strSoundEffect);
    oluacls_prop(L, "tweenEasing", _cocostudio_FrameData_get_tweenEasing, _cocostudio_FrameData_set_tweenEasing);

    olua_registerluatype<cocostudio::FrameData>(L, "ccs.FrameData");

    return 1;
}

static int _cocostudio_GUIReader___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocostudio::GUIReader *)olua_toobj(L, 1, "ccs.GUIReader");
    olua_push_cppobj(L, self, "ccs.GUIReader");

    olua_endinvoke(L);

    return 1;
}

static int _cocostudio_GUIReader_destroyInstance(lua_State *L)
{
    olua_startinvoke(L);

    // static void destroyInstance()
    cocostudio::GUIReader::destroyInstance();

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_GUIReader_getFileDesignSize(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::GUIReader *self = nullptr;
    const char *arg1 = nullptr;       /** fileName */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.GUIReader");
    olua_check_string(L, 2, &arg1);

    // cocos2d::Size getFileDesignSize(const char *fileName)
    cocos2d::Size ret = self->getFileDesignSize(arg1);
    int num_ret = olua_push_cocos2d_Size(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_GUIReader_getFilePath(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::GUIReader *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.GUIReader");

    // const std::string &getFilePath()
    const std::string &ret = self->getFilePath();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_GUIReader_getInstance(lua_State *L)
{
    olua_startinvoke(L);

    // static cocostudio::GUIReader *getInstance()
    cocostudio::GUIReader *ret = cocostudio::GUIReader::getInstance();
    int num_ret = olua_push_cppobj(L, ret, "ccs.GUIReader");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_GUIReader_getVersionInteger(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::GUIReader *self = nullptr;
    const char *arg1 = nullptr;       /** str */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.GUIReader");
    olua_check_string(L, 2, &arg1);

    // int getVersionInteger(const char *str)
    int ret = self->getVersionInteger(arg1);
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_GUIReader_setFilePath(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::GUIReader *self = nullptr;
    std::string arg1;       /** strFilePath */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.GUIReader");
    olua_check_std_string(L, 2, &arg1);

    // void setFilePath(const std::string &strFilePath)
    self->setFilePath(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_GUIReader_storeFileDesignSize(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::GUIReader *self = nullptr;
    const char *arg1 = nullptr;       /** fileName */
    cocos2d::Size arg2;       /** size */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.GUIReader");
    olua_check_string(L, 2, &arg1);
    olua_check_cocos2d_Size(L, 3, &arg2);

    // void storeFileDesignSize(const char *fileName, const cocos2d::Size &size)
    self->storeFileDesignSize(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_GUIReader_widgetFromBinaryFile(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::GUIReader *self = nullptr;
    const char *arg1 = nullptr;       /** fileName */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.GUIReader");
    olua_check_string(L, 2, &arg1);

    // cocos2d::ui::Widget *widgetFromBinaryFile(const char *fileName)
    cocos2d::ui::Widget *ret = self->widgetFromBinaryFile(arg1);
    int num_ret = olua_push_cppobj(L, ret, "ccui.Widget");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_GUIReader_widgetFromJsonFile(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::GUIReader *self = nullptr;
    const char *arg1 = nullptr;       /** fileName */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.GUIReader");
    olua_check_string(L, 2, &arg1);

    // cocos2d::ui::Widget *widgetFromJsonFile(const char *fileName)
    cocos2d::ui::Widget *ret = self->widgetFromJsonFile(arg1);
    int num_ret = olua_push_cppobj(L, ret, "ccui.Widget");

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocostudio_GUIReader(lua_State *L)
{
    oluacls_class(L, "ccs.GUIReader", "cc.Ref");
    oluacls_func(L, "__olua_move", _cocostudio_GUIReader___olua_move);
    oluacls_func(L, "destroyInstance", _cocostudio_GUIReader_destroyInstance);
    oluacls_func(L, "getFileDesignSize", _cocostudio_GUIReader_getFileDesignSize);
    oluacls_func(L, "getFilePath", _cocostudio_GUIReader_getFilePath);
    oluacls_func(L, "getInstance", _cocostudio_GUIReader_getInstance);
    oluacls_func(L, "getVersionInteger", _cocostudio_GUIReader_getVersionInteger);
    oluacls_func(L, "setFilePath", _cocostudio_GUIReader_setFilePath);
    oluacls_func(L, "storeFileDesignSize", _cocostudio_GUIReader_storeFileDesignSize);
    oluacls_func(L, "widgetFromBinaryFile", _cocostudio_GUIReader_widgetFromBinaryFile);
    oluacls_func(L, "widgetFromJsonFile", _cocostudio_GUIReader_widgetFromJsonFile);
    oluacls_prop(L, "filePath", _cocostudio_GUIReader_getFilePath, _cocostudio_GUIReader_setFilePath);
    oluacls_prop(L, "instance", _cocostudio_GUIReader_getInstance, nullptr);

    olua_registerluatype<cocostudio::GUIReader>(L, "ccs.GUIReader");

    return 1;
}

static int _cocostudio_InputDelegate___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_postgc<cocostudio::InputDelegate>(L, 1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_InputDelegate___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocostudio::InputDelegate *)olua_toobj(L, 1, "ccs.InputDelegate");
    olua_push_cppobj(L, self, "ccs.InputDelegate");

    olua_endinvoke(L);

    return 1;
}

static int _cocostudio_InputDelegate_getTouchMode(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::InputDelegate *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.InputDelegate");

    // cocos2d::Touch::DispatchMode getTouchMode()
    cocos2d::Touch::DispatchMode ret = self->getTouchMode();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_InputDelegate_getTouchPriority(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::InputDelegate *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.InputDelegate");

    // int getTouchPriority()
    int ret = self->getTouchPriority();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_InputDelegate_isAccelerometerEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::InputDelegate *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.InputDelegate");

    // bool isAccelerometerEnabled()
    bool ret = self->isAccelerometerEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_InputDelegate_isKeypadEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::InputDelegate *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.InputDelegate");

    // bool isKeypadEnabled()
    bool ret = self->isKeypadEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_InputDelegate_isTouchEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::InputDelegate *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.InputDelegate");

    // bool isTouchEnabled()
    bool ret = self->isTouchEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_InputDelegate_new(lua_State *L)
{
    olua_startinvoke(L);

    // InputDelegate()
    cocostudio::InputDelegate *ret = new cocostudio::InputDelegate();
    int num_ret = olua_push_cppobj(L, ret, "ccs.InputDelegate");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_InputDelegate_onAcceleration(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::InputDelegate *self = nullptr;
    cocos2d::Acceleration *arg1 = nullptr;       /** acc */
    cocos2d::Event *arg2 = nullptr;       /** event */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.InputDelegate");
    olua_check_cppobj(L, 2, (void **)&arg1, "cc.Acceleration");
    olua_check_cppobj(L, 3, (void **)&arg2, "cc.Event");

    // void onAcceleration(cocos2d::Acceleration *acc, cocos2d::Event *event)
    self->onAcceleration(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_InputDelegate_onKeyPressed(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::InputDelegate *self = nullptr;
    lua_Unsigned arg1 = 0;       /** keyCode */
    cocos2d::Event *arg2 = nullptr;       /** event */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.InputDelegate");
    olua_check_uint(L, 2, &arg1);
    olua_check_cppobj(L, 3, (void **)&arg2, "cc.Event");

    // void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event)
    self->onKeyPressed((cocos2d::EventKeyboard::KeyCode)arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_InputDelegate_onKeyReleased(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::InputDelegate *self = nullptr;
    lua_Unsigned arg1 = 0;       /** keyCode */
    cocos2d::Event *arg2 = nullptr;       /** event */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.InputDelegate");
    olua_check_uint(L, 2, &arg1);
    olua_check_cppobj(L, 3, (void **)&arg2, "cc.Event");

    // void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event)
    self->onKeyReleased((cocos2d::EventKeyboard::KeyCode)arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_InputDelegate_onTouchBegan(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::InputDelegate *self = nullptr;
    cocos2d::Touch *arg1 = nullptr;       /** touch */
    cocos2d::Event *arg2 = nullptr;       /** event */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.InputDelegate");
    olua_check_cppobj(L, 2, (void **)&arg1, "cc.Touch");
    olua_check_cppobj(L, 3, (void **)&arg2, "cc.Event");

    // bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
    bool ret = self->onTouchBegan(arg1, arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_InputDelegate_onTouchCancelled(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::InputDelegate *self = nullptr;
    cocos2d::Touch *arg1 = nullptr;       /** touch */
    cocos2d::Event *arg2 = nullptr;       /** event */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.InputDelegate");
    olua_check_cppobj(L, 2, (void **)&arg1, "cc.Touch");
    olua_check_cppobj(L, 3, (void **)&arg2, "cc.Event");

    // void onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event *event)
    self->onTouchCancelled(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_InputDelegate_onTouchEnded(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::InputDelegate *self = nullptr;
    cocos2d::Touch *arg1 = nullptr;       /** touch */
    cocos2d::Event *arg2 = nullptr;       /** event */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.InputDelegate");
    olua_check_cppobj(L, 2, (void **)&arg1, "cc.Touch");
    olua_check_cppobj(L, 3, (void **)&arg2, "cc.Event");

    // void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event)
    self->onTouchEnded(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_InputDelegate_onTouchMoved(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::InputDelegate *self = nullptr;
    cocos2d::Touch *arg1 = nullptr;       /** touch */
    cocos2d::Event *arg2 = nullptr;       /** event */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.InputDelegate");
    olua_check_cppobj(L, 2, (void **)&arg1, "cc.Touch");
    olua_check_cppobj(L, 3, (void **)&arg2, "cc.Event");

    // void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event)
    self->onTouchMoved(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_InputDelegate_onTouchesBegan(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::InputDelegate *self = nullptr;
    std::vector<cocos2d::Touch *> arg1;       /** touches */
    cocos2d::Event *arg2 = nullptr;       /** event */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.InputDelegate");
    olua_check_std_vector<cocos2d::Touch *>(L, 2, &arg1, [L](cocos2d::Touch **value) {
        olua_check_cppobj(L, -1, (void **)value, "cc.Touch");
    });
    olua_check_cppobj(L, 3, (void **)&arg2, "cc.Event");

    // void onTouchesBegan(const std::vector<cocos2d::Touch *> &touches, cocos2d::Event *event)
    self->onTouchesBegan(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_InputDelegate_onTouchesCancelled(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::InputDelegate *self = nullptr;
    std::vector<cocos2d::Touch *> arg1;       /** touches */
    cocos2d::Event *arg2 = nullptr;       /** event */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.InputDelegate");
    olua_check_std_vector<cocos2d::Touch *>(L, 2, &arg1, [L](cocos2d::Touch **value) {
        olua_check_cppobj(L, -1, (void **)value, "cc.Touch");
    });
    olua_check_cppobj(L, 3, (void **)&arg2, "cc.Event");

    // void onTouchesCancelled(const std::vector<cocos2d::Touch *> &touches, cocos2d::Event *event)
    self->onTouchesCancelled(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_InputDelegate_onTouchesEnded(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::InputDelegate *self = nullptr;
    std::vector<cocos2d::Touch *> arg1;       /** touches */
    cocos2d::Event *arg2 = nullptr;       /** event */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.InputDelegate");
    olua_check_std_vector<cocos2d::Touch *>(L, 2, &arg1, [L](cocos2d::Touch **value) {
        olua_check_cppobj(L, -1, (void **)value, "cc.Touch");
    });
    olua_check_cppobj(L, 3, (void **)&arg2, "cc.Event");

    // void onTouchesEnded(const std::vector<cocos2d::Touch *> &touches, cocos2d::Event *event)
    self->onTouchesEnded(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_InputDelegate_onTouchesMoved(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::InputDelegate *self = nullptr;
    std::vector<cocos2d::Touch *> arg1;       /** touches */
    cocos2d::Event *arg2 = nullptr;       /** event */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.InputDelegate");
    olua_check_std_vector<cocos2d::Touch *>(L, 2, &arg1, [L](cocos2d::Touch **value) {
        olua_check_cppobj(L, -1, (void **)value, "cc.Touch");
    });
    olua_check_cppobj(L, 3, (void **)&arg2, "cc.Event");

    // void onTouchesMoved(const std::vector<cocos2d::Touch *> &touches, cocos2d::Event *event)
    self->onTouchesMoved(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_InputDelegate_setAccelerometerEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::InputDelegate *self = nullptr;
    bool arg1 = false;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.InputDelegate");
    olua_check_bool(L, 2, &arg1);

    // void setAccelerometerEnabled(bool value)
    self->setAccelerometerEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_InputDelegate_setKeypadEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::InputDelegate *self = nullptr;
    bool arg1 = false;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.InputDelegate");
    olua_check_bool(L, 2, &arg1);

    // void setKeypadEnabled(bool value)
    self->setKeypadEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_InputDelegate_setTouchEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::InputDelegate *self = nullptr;
    bool arg1 = false;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.InputDelegate");
    olua_check_bool(L, 2, &arg1);

    // void setTouchEnabled(bool value)
    self->setTouchEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_InputDelegate_setTouchMode(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::InputDelegate *self = nullptr;
    lua_Unsigned arg1 = 0;       /** mode */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.InputDelegate");
    olua_check_uint(L, 2, &arg1);

    // void setTouchMode(cocos2d::Touch::DispatchMode mode)
    self->setTouchMode((cocos2d::Touch::DispatchMode)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_InputDelegate_setTouchPriority(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::InputDelegate *self = nullptr;
    lua_Integer arg1 = 0;       /** priority */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.InputDelegate");
    olua_check_int(L, 2, &arg1);

    // void setTouchPriority(int priority)
    self->setTouchPriority((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocostudio_InputDelegate(lua_State *L)
{
    oluacls_class(L, "ccs.InputDelegate", nullptr);
    oluacls_func(L, "__gc", _cocostudio_InputDelegate___gc);
    oluacls_func(L, "__olua_move", _cocostudio_InputDelegate___olua_move);
    oluacls_func(L, "getTouchMode", _cocostudio_InputDelegate_getTouchMode);
    oluacls_func(L, "getTouchPriority", _cocostudio_InputDelegate_getTouchPriority);
    oluacls_func(L, "isAccelerometerEnabled", _cocostudio_InputDelegate_isAccelerometerEnabled);
    oluacls_func(L, "isKeypadEnabled", _cocostudio_InputDelegate_isKeypadEnabled);
    oluacls_func(L, "isTouchEnabled", _cocostudio_InputDelegate_isTouchEnabled);
    oluacls_func(L, "new", _cocostudio_InputDelegate_new);
    oluacls_func(L, "onAcceleration", _cocostudio_InputDelegate_onAcceleration);
    oluacls_func(L, "onKeyPressed", _cocostudio_InputDelegate_onKeyPressed);
    oluacls_func(L, "onKeyReleased", _cocostudio_InputDelegate_onKeyReleased);
    oluacls_func(L, "onTouchBegan", _cocostudio_InputDelegate_onTouchBegan);
    oluacls_func(L, "onTouchCancelled", _cocostudio_InputDelegate_onTouchCancelled);
    oluacls_func(L, "onTouchEnded", _cocostudio_InputDelegate_onTouchEnded);
    oluacls_func(L, "onTouchMoved", _cocostudio_InputDelegate_onTouchMoved);
    oluacls_func(L, "onTouchesBegan", _cocostudio_InputDelegate_onTouchesBegan);
    oluacls_func(L, "onTouchesCancelled", _cocostudio_InputDelegate_onTouchesCancelled);
    oluacls_func(L, "onTouchesEnded", _cocostudio_InputDelegate_onTouchesEnded);
    oluacls_func(L, "onTouchesMoved", _cocostudio_InputDelegate_onTouchesMoved);
    oluacls_func(L, "setAccelerometerEnabled", _cocostudio_InputDelegate_setAccelerometerEnabled);
    oluacls_func(L, "setKeypadEnabled", _cocostudio_InputDelegate_setKeypadEnabled);
    oluacls_func(L, "setTouchEnabled", _cocostudio_InputDelegate_setTouchEnabled);
    oluacls_func(L, "setTouchMode", _cocostudio_InputDelegate_setTouchMode);
    oluacls_func(L, "setTouchPriority", _cocostudio_InputDelegate_setTouchPriority);
    oluacls_prop(L, "accelerometerEnabled", _cocostudio_InputDelegate_isAccelerometerEnabled, _cocostudio_InputDelegate_setAccelerometerEnabled);
    oluacls_prop(L, "keypadEnabled", _cocostudio_InputDelegate_isKeypadEnabled, _cocostudio_InputDelegate_setKeypadEnabled);
    oluacls_prop(L, "touchEnabled", _cocostudio_InputDelegate_isTouchEnabled, _cocostudio_InputDelegate_setTouchEnabled);
    oluacls_prop(L, "touchMode", _cocostudio_InputDelegate_getTouchMode, _cocostudio_InputDelegate_setTouchMode);
    oluacls_prop(L, "touchPriority", _cocostudio_InputDelegate_getTouchPriority, _cocostudio_InputDelegate_setTouchPriority);

    olua_registerluatype<cocostudio::InputDelegate>(L, "ccs.InputDelegate");

    return 1;
}

static int _cocostudio_MovementBoneData___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocostudio::MovementBoneData *)olua_toobj(L, 1, "ccs.MovementBoneData");
    olua_push_cppobj(L, self, "ccs.MovementBoneData");

    olua_endinvoke(L);

    return 1;
}

static int _cocostudio_MovementBoneData_addFrameData(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::MovementBoneData *self = nullptr;
    cocostudio::FrameData *arg1 = nullptr;       /** frameData */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.MovementBoneData");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccs.FrameData");

    // void addFrameData(cocostudio::FrameData *frameData)
    self->addFrameData(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_MovementBoneData_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cocostudio::MovementBoneData *create()
    cocostudio::MovementBoneData *ret = cocostudio::MovementBoneData::create();
    int num_ret = olua_push_cppobj(L, ret, "ccs.MovementBoneData");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_MovementBoneData_getFrameData(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::MovementBoneData *self = nullptr;
    lua_Integer arg1 = 0;       /** index */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.MovementBoneData");
    olua_check_int(L, 2, &arg1);

    // cocostudio::FrameData *getFrameData(int index)
    cocostudio::FrameData *ret = self->getFrameData((int)arg1);
    int num_ret = olua_push_cppobj(L, ret, "ccs.FrameData");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_MovementBoneData_init(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::MovementBoneData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.MovementBoneData");

    // bool init()
    bool ret = self->init();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_MovementBoneData_new(lua_State *L)
{
    olua_startinvoke(L);

    // MovementBoneData()
    cocostudio::MovementBoneData *ret = new cocostudio::MovementBoneData();
    int num_ret = olua_push_cppobj(L, ret, "ccs.MovementBoneData");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_MovementBoneData_get_delay(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::MovementBoneData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.MovementBoneData");

    // float delay
    float ret = self->delay;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_MovementBoneData_set_delay(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::MovementBoneData *self = nullptr;
    lua_Number arg1 = 0;       /** delay */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.MovementBoneData");
    olua_check_number(L, 2, &arg1);

    // float delay
    self->delay = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_MovementBoneData_get_duration(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::MovementBoneData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.MovementBoneData");

    // float duration
    float ret = self->duration;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_MovementBoneData_set_duration(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::MovementBoneData *self = nullptr;
    lua_Number arg1 = 0;       /** duration */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.MovementBoneData");
    olua_check_number(L, 2, &arg1);

    // float duration
    self->duration = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_MovementBoneData_get_frameList(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::MovementBoneData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.MovementBoneData");

    // cocos2d::Vector<FrameData *> frameList
    cocos2d::Vector<cocostudio::FrameData *> ret = self->frameList;
    int num_ret = olua_push_cocos2d_Vector<cocostudio::FrameData *>(L, &ret, [L](cocostudio::FrameData *value) {
        olua_push_cppobj(L, value, "ccs.FrameData");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_MovementBoneData_set_frameList(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::MovementBoneData *self = nullptr;
    cocos2d::Vector<cocostudio::FrameData *> arg1;       /** frameList */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.MovementBoneData");
    olua_check_cocos2d_Vector<cocostudio::FrameData *>(L, 2, &arg1, [L](cocostudio::FrameData **value) {
        olua_check_cppobj(L, -1, (void **)value, "ccs.FrameData");
    });

    // cocos2d::Vector<FrameData *> frameList
    self->frameList = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_MovementBoneData_get_name(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::MovementBoneData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.MovementBoneData");

    // std::string name
    std::string ret = self->name;
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_MovementBoneData_set_name(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::MovementBoneData *self = nullptr;
    std::string arg1;       /** name */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.MovementBoneData");
    olua_check_std_string(L, 2, &arg1);

    // std::string name
    self->name = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_MovementBoneData_get_scale(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::MovementBoneData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.MovementBoneData");

    // float scale
    float ret = self->scale;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_MovementBoneData_set_scale(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::MovementBoneData *self = nullptr;
    lua_Number arg1 = 0;       /** scale */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.MovementBoneData");
    olua_check_number(L, 2, &arg1);

    // float scale
    self->scale = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocostudio_MovementBoneData(lua_State *L)
{
    oluacls_class(L, "ccs.MovementBoneData", "cc.Ref");
    oluacls_func(L, "__olua_move", _cocostudio_MovementBoneData___olua_move);
    oluacls_func(L, "addFrameData", _cocostudio_MovementBoneData_addFrameData);
    oluacls_func(L, "create", _cocostudio_MovementBoneData_create);
    oluacls_func(L, "getFrameData", _cocostudio_MovementBoneData_getFrameData);
    oluacls_func(L, "init", _cocostudio_MovementBoneData_init);
    oluacls_func(L, "new", _cocostudio_MovementBoneData_new);
    oluacls_prop(L, "delay", _cocostudio_MovementBoneData_get_delay, _cocostudio_MovementBoneData_set_delay);
    oluacls_prop(L, "duration", _cocostudio_MovementBoneData_get_duration, _cocostudio_MovementBoneData_set_duration);
    oluacls_prop(L, "frameList", _cocostudio_MovementBoneData_get_frameList, _cocostudio_MovementBoneData_set_frameList);
    oluacls_prop(L, "name", _cocostudio_MovementBoneData_get_name, _cocostudio_MovementBoneData_set_name);
    oluacls_prop(L, "scale", _cocostudio_MovementBoneData_get_scale, _cocostudio_MovementBoneData_set_scale);

    olua_registerluatype<cocostudio::MovementBoneData>(L, "ccs.MovementBoneData");

    return 1;
}

static int _cocostudio_MovementData___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocostudio::MovementData *)olua_toobj(L, 1, "ccs.MovementData");
    olua_push_cppobj(L, self, "ccs.MovementData");

    olua_endinvoke(L);

    return 1;
}

static int _cocostudio_MovementData_addMovementBoneData(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::MovementData *self = nullptr;
    cocostudio::MovementBoneData *arg1 = nullptr;       /** movBoneData */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.MovementData");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccs.MovementBoneData");

    // void addMovementBoneData(cocostudio::MovementBoneData *movBoneData)
    self->addMovementBoneData(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_MovementData_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cocostudio::MovementData *create()
    cocostudio::MovementData *ret = cocostudio::MovementData::create();
    int num_ret = olua_push_cppobj(L, ret, "ccs.MovementData");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_MovementData_getMovementBoneData(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::MovementData *self = nullptr;
    std::string arg1;       /** boneName */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.MovementData");
    olua_check_std_string(L, 2, &arg1);

    // cocostudio::MovementBoneData *getMovementBoneData(const std::string &boneName)
    cocostudio::MovementBoneData *ret = self->getMovementBoneData(arg1);
    int num_ret = olua_push_cppobj(L, ret, "ccs.MovementBoneData");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_MovementData_new(lua_State *L)
{
    olua_startinvoke(L);

    // MovementData()
    cocostudio::MovementData *ret = new cocostudio::MovementData();
    int num_ret = olua_push_cppobj(L, ret, "ccs.MovementData");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_MovementData_get_duration(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::MovementData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.MovementData");

    // int duration
    int ret = self->duration;
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_MovementData_set_duration(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::MovementData *self = nullptr;
    lua_Integer arg1 = 0;       /** duration */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.MovementData");
    olua_check_int(L, 2, &arg1);

    // int duration
    self->duration = (int)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_MovementData_get_durationTo(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::MovementData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.MovementData");

    // int durationTo
    int ret = self->durationTo;
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_MovementData_set_durationTo(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::MovementData *self = nullptr;
    lua_Integer arg1 = 0;       /** durationTo */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.MovementData");
    olua_check_int(L, 2, &arg1);

    // int durationTo
    self->durationTo = (int)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_MovementData_get_durationTween(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::MovementData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.MovementData");

    // int durationTween
    int ret = self->durationTween;
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_MovementData_set_durationTween(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::MovementData *self = nullptr;
    lua_Integer arg1 = 0;       /** durationTween */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.MovementData");
    olua_check_int(L, 2, &arg1);

    // int durationTween
    self->durationTween = (int)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_MovementData_get_loop(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::MovementData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.MovementData");

    // bool loop
    bool ret = self->loop;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_MovementData_set_loop(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::MovementData *self = nullptr;
    bool arg1 = false;       /** loop */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.MovementData");
    olua_check_bool(L, 2, &arg1);

    // bool loop
    self->loop = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_MovementData_get_movBoneDataDic(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::MovementData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.MovementData");

    // cocos2d::Map<std::string, MovementBoneData *> movBoneDataDic
    cocos2d::Map<std::string, cocostudio::MovementBoneData *> ret = self->movBoneDataDic;
    int num_ret = olua_push_cocos2d_Map<std::string, cocostudio::MovementBoneData *>(L, &ret, [L](std::string arg1, cocostudio::MovementBoneData *arg2) {
        olua_push_std_string(L, (std::string)arg1);
        olua_push_cppobj(L, arg2, "ccs.MovementBoneData");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_MovementData_set_movBoneDataDic(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::MovementData *self = nullptr;
    cocos2d::Map<std::string, cocostudio::MovementBoneData *> arg1;       /** movBoneDataDic */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.MovementData");
    olua_check_cocos2d_Map<std::string, cocostudio::MovementBoneData *>(L, 2, &arg1, [L](std::string *arg1, cocostudio::MovementBoneData **arg2) {
        olua_check_std_string(L, -1, arg1);
        olua_check_cppobj(L, -2, (void **)arg2, "ccs.MovementBoneData");
    });

    // cocos2d::Map<std::string, MovementBoneData *> movBoneDataDic
    self->movBoneDataDic = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_MovementData_get_name(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::MovementData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.MovementData");

    // std::string name
    std::string ret = self->name;
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_MovementData_set_name(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::MovementData *self = nullptr;
    std::string arg1;       /** name */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.MovementData");
    olua_check_std_string(L, 2, &arg1);

    // std::string name
    self->name = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_MovementData_get_scale(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::MovementData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.MovementData");

    // float scale
    float ret = self->scale;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_MovementData_set_scale(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::MovementData *self = nullptr;
    lua_Number arg1 = 0;       /** scale */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.MovementData");
    olua_check_number(L, 2, &arg1);

    // float scale
    self->scale = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_MovementData_get_tweenEasing(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::MovementData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.MovementData");

    // cocos2d::tweenfunc::TweenType tweenEasing
    cocos2d::tweenfunc::TweenType ret = self->tweenEasing;
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_MovementData_set_tweenEasing(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::MovementData *self = nullptr;
    lua_Unsigned arg1 = 0;       /** tweenEasing */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.MovementData");
    olua_check_uint(L, 2, &arg1);

    // cocos2d::tweenfunc::TweenType tweenEasing
    self->tweenEasing = (cocos2d::tweenfunc::TweenType)arg1;

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocostudio_MovementData(lua_State *L)
{
    oluacls_class(L, "ccs.MovementData", "cc.Ref");
    oluacls_func(L, "__olua_move", _cocostudio_MovementData___olua_move);
    oluacls_func(L, "addMovementBoneData", _cocostudio_MovementData_addMovementBoneData);
    oluacls_func(L, "create", _cocostudio_MovementData_create);
    oluacls_func(L, "getMovementBoneData", _cocostudio_MovementData_getMovementBoneData);
    oluacls_func(L, "new", _cocostudio_MovementData_new);
    oluacls_prop(L, "duration", _cocostudio_MovementData_get_duration, _cocostudio_MovementData_set_duration);
    oluacls_prop(L, "durationTo", _cocostudio_MovementData_get_durationTo, _cocostudio_MovementData_set_durationTo);
    oluacls_prop(L, "durationTween", _cocostudio_MovementData_get_durationTween, _cocostudio_MovementData_set_durationTween);
    oluacls_prop(L, "loop", _cocostudio_MovementData_get_loop, _cocostudio_MovementData_set_loop);
    oluacls_prop(L, "movBoneDataDic", _cocostudio_MovementData_get_movBoneDataDic, _cocostudio_MovementData_set_movBoneDataDic);
    oluacls_prop(L, "name", _cocostudio_MovementData_get_name, _cocostudio_MovementData_set_name);
    oluacls_prop(L, "scale", _cocostudio_MovementData_get_scale, _cocostudio_MovementData_set_scale);
    oluacls_prop(L, "tweenEasing", _cocostudio_MovementData_get_tweenEasing, _cocostudio_MovementData_set_tweenEasing);

    olua_registerluatype<cocostudio::MovementData>(L, "ccs.MovementData");

    return 1;
}

static int _cocostudio_ParticleDisplayData___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocostudio::ParticleDisplayData *)olua_toobj(L, 1, "ccs.ParticleDisplayData");
    olua_push_cppobj(L, self, "ccs.ParticleDisplayData");

    olua_endinvoke(L);

    return 1;
}

static int _cocostudio_ParticleDisplayData_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cocostudio::ParticleDisplayData *create()
    cocostudio::ParticleDisplayData *ret = cocostudio::ParticleDisplayData::create();
    int num_ret = olua_push_cppobj(L, ret, "ccs.ParticleDisplayData");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_ParticleDisplayData_new(lua_State *L)
{
    olua_startinvoke(L);

    // ParticleDisplayData()
    cocostudio::ParticleDisplayData *ret = new cocostudio::ParticleDisplayData();
    int num_ret = olua_push_cppobj(L, ret, "ccs.ParticleDisplayData");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocostudio_ParticleDisplayData(lua_State *L)
{
    oluacls_class(L, "ccs.ParticleDisplayData", "ccs.DisplayData");
    oluacls_func(L, "__olua_move", _cocostudio_ParticleDisplayData___olua_move);
    oluacls_func(L, "create", _cocostudio_ParticleDisplayData_create);
    oluacls_func(L, "new", _cocostudio_ParticleDisplayData_new);

    olua_registerluatype<cocostudio::ParticleDisplayData>(L, "ccs.ParticleDisplayData");

    return 1;
}

static int luaopen_cocostudio_SceneReader_AttachComponentType(lua_State *L)
{
    oluacls_class(L, "ccs.SceneReader.AttachComponentType", nullptr);
    oluacls_const_integer(L, "DEFAULT", (lua_Integer)cocostudio::SceneReader::AttachComponentType::DEFAULT);
    oluacls_const_integer(L, "EMPTY_NODE", (lua_Integer)cocostudio::SceneReader::AttachComponentType::EMPTY_NODE);
    oluacls_const_integer(L, "RENDER_NODE", (lua_Integer)cocostudio::SceneReader::AttachComponentType::RENDER_NODE);

    olua_registerluatype<cocostudio::SceneReader::AttachComponentType>(L, "ccs.SceneReader.AttachComponentType");

    return 1;
}

static int _cocostudio_SceneReader___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_postgc<cocostudio::SceneReader>(L, 1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_SceneReader___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocostudio::SceneReader *)olua_toobj(L, 1, "ccs.SceneReader");
    olua_push_cppobj(L, self, "ccs.SceneReader");

    olua_endinvoke(L);

    return 1;
}

static int _cocostudio_SceneReader_createNodeWithSceneFile1(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::SceneReader *self = nullptr;
    std::string arg1;       /** fileName */
    lua_Unsigned arg2 = 0;       /** attachComponent */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.SceneReader");
    olua_check_std_string(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // cocos2d::Node *createNodeWithSceneFile(const std::string &fileName, @optional cocostudio::SceneReader::AttachComponentType attachComponent)
    cocos2d::Node *ret = self->createNodeWithSceneFile(arg1, (cocostudio::SceneReader::AttachComponentType)arg2);
    int num_ret = olua_push_cppobj(L, ret, "cc.Node");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_SceneReader_createNodeWithSceneFile2(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::SceneReader *self = nullptr;
    std::string arg1;       /** fileName */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.SceneReader");
    olua_check_std_string(L, 2, &arg1);

    // cocos2d::Node *createNodeWithSceneFile(const std::string &fileName, @optional cocostudio::SceneReader::AttachComponentType attachComponent)
    cocos2d::Node *ret = self->createNodeWithSceneFile(arg1);
    int num_ret = olua_push_cppobj(L, ret, "cc.Node");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_SceneReader_createNodeWithSceneFile(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 2))) {
            // cocos2d::Node *createNodeWithSceneFile(const std::string &fileName, @optional cocostudio::SceneReader::AttachComponentType attachComponent)
            return _cocostudio_SceneReader_createNodeWithSceneFile2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_uint(L, 3))) {
            // cocos2d::Node *createNodeWithSceneFile(const std::string &fileName, @optional cocostudio::SceneReader::AttachComponentType attachComponent)
            return _cocostudio_SceneReader_createNodeWithSceneFile1(L);
        // }
    }

    luaL_error(L, "method 'cocostudio::SceneReader::createNodeWithSceneFile' not support '%d' arguments", num_args);

    return 0;
}

static int _cocostudio_SceneReader_destroyInstance(lua_State *L)
{
    olua_startinvoke(L);

    // static void destroyInstance()
    cocostudio::SceneReader::destroyInstance();

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_SceneReader_getAttachComponentType(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::SceneReader *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.SceneReader");

    // cocostudio::SceneReader::AttachComponentType getAttachComponentType()
    cocostudio::SceneReader::AttachComponentType ret = self->getAttachComponentType();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_SceneReader_getInstance(lua_State *L)
{
    olua_startinvoke(L);

    // static cocostudio::SceneReader *getInstance()
    cocostudio::SceneReader *ret = cocostudio::SceneReader::getInstance();
    int num_ret = olua_push_cppobj(L, ret, "ccs.SceneReader");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_SceneReader_getNodeByTag(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::SceneReader *self = nullptr;
    lua_Integer arg1 = 0;       /** nTag */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.SceneReader");
    olua_check_int(L, 2, &arg1);

    // cocos2d::Node *getNodeByTag(int nTag)
    cocos2d::Node *ret = self->getNodeByTag((int)arg1);
    int num_ret = olua_push_cppobj(L, ret, "cc.Node");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_SceneReader_new(lua_State *L)
{
    olua_startinvoke(L);

    // SceneReader()
    cocostudio::SceneReader *ret = new cocostudio::SceneReader();
    int num_ret = olua_push_cppobj(L, ret, "ccs.SceneReader");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_SceneReader_sceneReaderVersion(lua_State *L)
{
    olua_startinvoke(L);

    // static const char *sceneReaderVersion()
    const char *ret = cocostudio::SceneReader::sceneReaderVersion();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_SceneReader_setTarget(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::SceneReader *self = nullptr;
    std::function<void(cocos2d::Ref *, void *)> arg1;       /** selector */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.SceneReader");
    olua_check_std_function(L, 2, &arg1);

    void *cb_store = (void *)self;
    std::string cb_tag = "Target";
    std::string cb_name;
    if (olua_is_std_function(L, 2)) {
        cb_name = olua_setcallback(L, cb_store,  2, cb_tag.c_str(), OLUA_TAG_REPLACE);
        lua_Integer cb_ctx = olua_context(L);
        arg1 = [cb_store, cb_name, cb_ctx](cocos2d::Ref *arg1, void *arg2) {
            lua_State *L = olua_mainthread(NULL);
            olua_checkhostthread();

            if (L != NULL && olua_context(L) == cb_ctx) {
                int top = lua_gettop(L);
                size_t last = olua_push_objpool(L);
                olua_enable_objpool(L);
                olua_push_cppobj(L, arg1, "cc.Ref");
                olua_push_obj(L, arg2, "void *");
                olua_disable_objpool(L);

                olua_callback(L, cb_store, cb_name.c_str(), 2);

                //pop stack value
                olua_pop_objpool(L, last);
                lua_settop(L, top);
            }
        };
    } else {
        olua_removecallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_SUBEQUAL);
        arg1 = nullptr;
    }

    // void setTarget(@nullable @local const std::function<void (cocos2d::Ref *, void *)> &selector)
    self->setTarget(arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocostudio_SceneReader(lua_State *L)
{
    oluacls_class(L, "ccs.SceneReader", nullptr);
    oluacls_func(L, "__gc", _cocostudio_SceneReader___gc);
    oluacls_func(L, "__olua_move", _cocostudio_SceneReader___olua_move);
    oluacls_func(L, "createNodeWithSceneFile", _cocostudio_SceneReader_createNodeWithSceneFile);
    oluacls_func(L, "destroyInstance", _cocostudio_SceneReader_destroyInstance);
    oluacls_func(L, "getAttachComponentType", _cocostudio_SceneReader_getAttachComponentType);
    oluacls_func(L, "getInstance", _cocostudio_SceneReader_getInstance);
    oluacls_func(L, "getNodeByTag", _cocostudio_SceneReader_getNodeByTag);
    oluacls_func(L, "new", _cocostudio_SceneReader_new);
    oluacls_func(L, "sceneReaderVersion", _cocostudio_SceneReader_sceneReaderVersion);
    oluacls_func(L, "setTarget", _cocostudio_SceneReader_setTarget);
    oluacls_prop(L, "attachComponentType", _cocostudio_SceneReader_getAttachComponentType, nullptr);
    oluacls_prop(L, "instance", _cocostudio_SceneReader_getInstance, nullptr);

    olua_registerluatype<cocostudio::SceneReader>(L, "ccs.SceneReader");

    return 1;
}

static int _cocostudio_Skin___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocostudio::Skin *)olua_toobj(L, 1, "ccs.Skin");
    olua_push_cppobj(L, self, "ccs.Skin");

    olua_endinvoke(L);

    return 1;
}

static int _cocostudio_Skin_create1(lua_State *L)
{
    olua_startinvoke(L);

    // static cocostudio::Skin *create()
    cocostudio::Skin *ret = cocostudio::Skin::create();
    int num_ret = olua_push_cppobj(L, ret, "ccs.Skin");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_Skin_create2(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** pszFileName */

    olua_check_std_string(L, 1, &arg1);

    // static cocostudio::Skin *create(const std::string &pszFileName)
    cocostudio::Skin *ret = cocostudio::Skin::create(arg1);
    int num_ret = olua_push_cppobj(L, ret, "ccs.Skin");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_Skin_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // static cocostudio::Skin *create()
        return _cocostudio_Skin_create1(L);
    }

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 1))) {
            // static cocostudio::Skin *create(const std::string &pszFileName)
            return _cocostudio_Skin_create2(L);
        // }
    }

    luaL_error(L, "method 'cocostudio::Skin::create' not support '%d' arguments", num_args);

    return 0;
}

static int _cocostudio_Skin_createWithSpriteFrameName(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** pszSpriteFrameName */

    olua_check_std_string(L, 1, &arg1);

    // static cocostudio::Skin *createWithSpriteFrameName(const std::string &pszSpriteFrameName)
    cocostudio::Skin *ret = cocostudio::Skin::createWithSpriteFrameName(arg1);
    int num_ret = olua_push_cppobj(L, ret, "ccs.Skin");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_Skin_getBone(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Skin *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Skin");

    // cocostudio::Bone *getBone()
    cocostudio::Bone *ret = self->getBone();
    int num_ret = olua_push_cppobj(L, ret, "ccs.Bone");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_Skin_getDisplayName(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Skin *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Skin");

    // const std::string &getDisplayName()
    const std::string &ret = self->getDisplayName();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_Skin_getNodeToWorldTransformAR(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Skin *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Skin");

    // cocos2d::Mat4 getNodeToWorldTransformAR()
    cocos2d::Mat4 ret = self->getNodeToWorldTransformAR();
    int num_ret = olua_push_cocos2d_Mat4(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_Skin_getSkinData(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Skin *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Skin");

    // const cocostudio::BaseData &getSkinData()
    const cocostudio::BaseData &ret = self->getSkinData();
    int num_ret = olua_push_cppobj(L, &ret, "ccs.BaseData");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_Skin_new(lua_State *L)
{
    olua_startinvoke(L);

    // Skin()
    cocostudio::Skin *ret = new cocostudio::Skin();
    int num_ret = olua_push_cppobj(L, ret, "ccs.Skin");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_Skin_setBone(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Skin *self = nullptr;
    cocostudio::Bone *arg1 = nullptr;       /** bone */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Skin");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccs.Bone");

    // void setBone(cocostudio::Bone *bone)
    self->setBone(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_Skin_setSkinData(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Skin *self = nullptr;
    cocostudio::BaseData *arg1 = nullptr;       /** data */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Skin");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccs.BaseData");

    // void setSkinData(const cocostudio::BaseData &data)
    self->setSkinData(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_Skin_updateArmatureTransform(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Skin *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Skin");

    // void updateArmatureTransform()
    self->updateArmatureTransform();

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocostudio_Skin(lua_State *L)
{
    oluacls_class(L, "ccs.Skin", "cc.Sprite");
    oluacls_func(L, "__olua_move", _cocostudio_Skin___olua_move);
    oluacls_func(L, "create", _cocostudio_Skin_create);
    oluacls_func(L, "createWithSpriteFrameName", _cocostudio_Skin_createWithSpriteFrameName);
    oluacls_func(L, "getBone", _cocostudio_Skin_getBone);
    oluacls_func(L, "getDisplayName", _cocostudio_Skin_getDisplayName);
    oluacls_func(L, "getNodeToWorldTransformAR", _cocostudio_Skin_getNodeToWorldTransformAR);
    oluacls_func(L, "getSkinData", _cocostudio_Skin_getSkinData);
    oluacls_func(L, "new", _cocostudio_Skin_new);
    oluacls_func(L, "setBone", _cocostudio_Skin_setBone);
    oluacls_func(L, "setSkinData", _cocostudio_Skin_setSkinData);
    oluacls_func(L, "updateArmatureTransform", _cocostudio_Skin_updateArmatureTransform);
    oluacls_prop(L, "bone", _cocostudio_Skin_getBone, _cocostudio_Skin_setBone);
    oluacls_prop(L, "displayName", _cocostudio_Skin_getDisplayName, nullptr);
    oluacls_prop(L, "nodeToWorldTransformAR", _cocostudio_Skin_getNodeToWorldTransformAR, nullptr);
    oluacls_prop(L, "skinData", _cocostudio_Skin_getSkinData, _cocostudio_Skin_setSkinData);

    olua_registerluatype<cocostudio::Skin>(L, "ccs.Skin");

    return 1;
}

static int _cocostudio_SpriteDisplayData___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocostudio::SpriteDisplayData *)olua_toobj(L, 1, "ccs.SpriteDisplayData");
    olua_push_cppobj(L, self, "ccs.SpriteDisplayData");

    olua_endinvoke(L);

    return 1;
}

static int _cocostudio_SpriteDisplayData_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cocostudio::SpriteDisplayData *create()
    cocostudio::SpriteDisplayData *ret = cocostudio::SpriteDisplayData::create();
    int num_ret = olua_push_cppobj(L, ret, "ccs.SpriteDisplayData");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_SpriteDisplayData_new(lua_State *L)
{
    olua_startinvoke(L);

    // SpriteDisplayData()
    cocostudio::SpriteDisplayData *ret = new cocostudio::SpriteDisplayData();
    int num_ret = olua_push_cppobj(L, ret, "ccs.SpriteDisplayData");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_SpriteDisplayData_get_skinData(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::SpriteDisplayData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.SpriteDisplayData");

    // cocostudio::BaseData skinData
    cocostudio::BaseData &ret = (cocostudio::BaseData &)self->skinData;
    int num_ret = olua_push_cppobj(L, &ret, "ccs.BaseData");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_SpriteDisplayData_set_skinData(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::SpriteDisplayData *self = nullptr;
    cocostudio::BaseData *arg1 = nullptr;       /** skinData */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.SpriteDisplayData");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccs.BaseData");

    // cocostudio::BaseData skinData
    self->skinData = *arg1;

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocostudio_SpriteDisplayData(lua_State *L)
{
    oluacls_class(L, "ccs.SpriteDisplayData", "ccs.DisplayData");
    oluacls_func(L, "__olua_move", _cocostudio_SpriteDisplayData___olua_move);
    oluacls_func(L, "create", _cocostudio_SpriteDisplayData_create);
    oluacls_func(L, "new", _cocostudio_SpriteDisplayData_new);
    oluacls_prop(L, "skinData", _cocostudio_SpriteDisplayData_get_skinData, _cocostudio_SpriteDisplayData_set_skinData);

    olua_registerluatype<cocostudio::SpriteDisplayData>(L, "ccs.SpriteDisplayData");

    return 1;
}

static int _cocostudio_SpriteFrameCacheHelper___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocostudio::SpriteFrameCacheHelper *)olua_toobj(L, 1, "ccs.SpriteFrameCacheHelper");
    olua_push_cppobj(L, self, "ccs.SpriteFrameCacheHelper");

    olua_endinvoke(L);

    return 1;
}

static int _cocostudio_SpriteFrameCacheHelper_addSpriteFrameFromFile(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::SpriteFrameCacheHelper *self = nullptr;
    std::string arg1;       /** plistPath */
    std::string arg2;       /** imagePath */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.SpriteFrameCacheHelper");
    olua_check_std_string(L, 2, &arg1);
    olua_check_std_string(L, 3, &arg2);

    // void addSpriteFrameFromFile(const std::string &plistPath, const std::string &imagePath)
    self->addSpriteFrameFromFile(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_SpriteFrameCacheHelper_getInstance(lua_State *L)
{
    olua_startinvoke(L);

    // static cocostudio::SpriteFrameCacheHelper *getInstance()
    cocostudio::SpriteFrameCacheHelper *ret = cocostudio::SpriteFrameCacheHelper::getInstance();
    int num_ret = olua_push_cppobj(L, ret, "ccs.SpriteFrameCacheHelper");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_SpriteFrameCacheHelper_purge(lua_State *L)
{
    olua_startinvoke(L);

    // static void purge()
    cocostudio::SpriteFrameCacheHelper::purge();

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_SpriteFrameCacheHelper_removeSpriteFrameFromFile(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::SpriteFrameCacheHelper *self = nullptr;
    std::string arg1;       /** plistPath */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.SpriteFrameCacheHelper");
    olua_check_std_string(L, 2, &arg1);

    // void removeSpriteFrameFromFile(const std::string &plistPath)
    self->removeSpriteFrameFromFile(arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocostudio_SpriteFrameCacheHelper(lua_State *L)
{
    oluacls_class(L, "ccs.SpriteFrameCacheHelper", nullptr);
    oluacls_func(L, "__olua_move", _cocostudio_SpriteFrameCacheHelper___olua_move);
    oluacls_func(L, "addSpriteFrameFromFile", _cocostudio_SpriteFrameCacheHelper_addSpriteFrameFromFile);
    oluacls_func(L, "getInstance", _cocostudio_SpriteFrameCacheHelper_getInstance);
    oluacls_func(L, "purge", _cocostudio_SpriteFrameCacheHelper_purge);
    oluacls_func(L, "removeSpriteFrameFromFile", _cocostudio_SpriteFrameCacheHelper_removeSpriteFrameFromFile);
    oluacls_prop(L, "instance", _cocostudio_SpriteFrameCacheHelper_getInstance, nullptr);

    olua_registerluatype<cocostudio::SpriteFrameCacheHelper>(L, "ccs.SpriteFrameCacheHelper");

    return 1;
}

static int _cocostudio_TextureData___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocostudio::TextureData *)olua_toobj(L, 1, "ccs.TextureData");
    olua_push_cppobj(L, self, "ccs.TextureData");

    olua_endinvoke(L);

    return 1;
}

static int _cocostudio_TextureData_addContourData(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::TextureData *self = nullptr;
    cocostudio::ContourData *arg1 = nullptr;       /** contourData */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.TextureData");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccs.ContourData");

    // void addContourData(cocostudio::ContourData *contourData)
    self->addContourData(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_TextureData_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cocostudio::TextureData *create()
    cocostudio::TextureData *ret = cocostudio::TextureData::create();
    int num_ret = olua_push_cppobj(L, ret, "ccs.TextureData");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_TextureData_getContourData(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::TextureData *self = nullptr;
    lua_Integer arg1 = 0;       /** index */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.TextureData");
    olua_check_int(L, 2, &arg1);

    // cocostudio::ContourData *getContourData(int index)
    cocostudio::ContourData *ret = self->getContourData((int)arg1);
    int num_ret = olua_push_cppobj(L, ret, "ccs.ContourData");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_TextureData_init(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::TextureData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.TextureData");

    // bool init()
    bool ret = self->init();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_TextureData_new(lua_State *L)
{
    olua_startinvoke(L);

    // TextureData()
    cocostudio::TextureData *ret = new cocostudio::TextureData();
    int num_ret = olua_push_cppobj(L, ret, "ccs.TextureData");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_TextureData_get_contourDataList(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::TextureData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.TextureData");

    // cocos2d::Vector<ContourData *> contourDataList
    cocos2d::Vector<cocostudio::ContourData *> ret = self->contourDataList;
    int num_ret = olua_push_cocos2d_Vector<cocostudio::ContourData *>(L, &ret, [L](cocostudio::ContourData *value) {
        olua_push_cppobj(L, value, "ccs.ContourData");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_TextureData_set_contourDataList(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::TextureData *self = nullptr;
    cocos2d::Vector<cocostudio::ContourData *> arg1;       /** contourDataList */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.TextureData");
    olua_check_cocos2d_Vector<cocostudio::ContourData *>(L, 2, &arg1, [L](cocostudio::ContourData **value) {
        olua_check_cppobj(L, -1, (void **)value, "ccs.ContourData");
    });

    // cocos2d::Vector<ContourData *> contourDataList
    self->contourDataList = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_TextureData_get_height(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::TextureData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.TextureData");

    // float height
    float ret = self->height;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_TextureData_set_height(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::TextureData *self = nullptr;
    lua_Number arg1 = 0;       /** height */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.TextureData");
    olua_check_number(L, 2, &arg1);

    // float height
    self->height = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_TextureData_get_name(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::TextureData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.TextureData");

    // std::string name
    std::string ret = self->name;
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_TextureData_set_name(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::TextureData *self = nullptr;
    std::string arg1;       /** name */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.TextureData");
    olua_check_std_string(L, 2, &arg1);

    // std::string name
    self->name = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_TextureData_get_pivotX(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::TextureData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.TextureData");

    // float pivotX
    float ret = self->pivotX;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_TextureData_set_pivotX(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::TextureData *self = nullptr;
    lua_Number arg1 = 0;       /** pivotX */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.TextureData");
    olua_check_number(L, 2, &arg1);

    // float pivotX
    self->pivotX = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_TextureData_get_pivotY(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::TextureData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.TextureData");

    // float pivotY
    float ret = self->pivotY;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_TextureData_set_pivotY(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::TextureData *self = nullptr;
    lua_Number arg1 = 0;       /** pivotY */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.TextureData");
    olua_check_number(L, 2, &arg1);

    // float pivotY
    self->pivotY = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_TextureData_get_width(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::TextureData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.TextureData");

    // float width
    float ret = self->width;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_TextureData_set_width(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::TextureData *self = nullptr;
    lua_Number arg1 = 0;       /** width */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.TextureData");
    olua_check_number(L, 2, &arg1);

    // float width
    self->width = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocostudio_TextureData(lua_State *L)
{
    oluacls_class(L, "ccs.TextureData", "cc.Ref");
    oluacls_func(L, "__olua_move", _cocostudio_TextureData___olua_move);
    oluacls_func(L, "addContourData", _cocostudio_TextureData_addContourData);
    oluacls_func(L, "create", _cocostudio_TextureData_create);
    oluacls_func(L, "getContourData", _cocostudio_TextureData_getContourData);
    oluacls_func(L, "init", _cocostudio_TextureData_init);
    oluacls_func(L, "new", _cocostudio_TextureData_new);
    oluacls_prop(L, "contourDataList", _cocostudio_TextureData_get_contourDataList, _cocostudio_TextureData_set_contourDataList);
    oluacls_prop(L, "height", _cocostudio_TextureData_get_height, _cocostudio_TextureData_set_height);
    oluacls_prop(L, "name", _cocostudio_TextureData_get_name, _cocostudio_TextureData_set_name);
    oluacls_prop(L, "pivotX", _cocostudio_TextureData_get_pivotX, _cocostudio_TextureData_set_pivotX);
    oluacls_prop(L, "pivotY", _cocostudio_TextureData_get_pivotY, _cocostudio_TextureData_set_pivotY);
    oluacls_prop(L, "width", _cocostudio_TextureData_get_width, _cocostudio_TextureData_set_width);

    olua_registerluatype<cocostudio::TextureData>(L, "ccs.TextureData");

    return 1;
}

static int _cocostudio_Tween___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocostudio::Tween *)olua_toobj(L, 1, "ccs.Tween");
    olua_push_cppobj(L, self, "ccs.Tween");

    olua_endinvoke(L);

    return 1;
}

static int _cocostudio_Tween_create(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Bone *arg1 = nullptr;       /** bone */

    olua_check_cppobj(L, 1, (void **)&arg1, "ccs.Bone");

    // static cocostudio::Tween *create(cocostudio::Bone *bone)
    cocostudio::Tween *ret = cocostudio::Tween::create(arg1);
    int num_ret = olua_push_cppobj(L, ret, "ccs.Tween");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_Tween_getAnimation(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Tween *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Tween");

    // cocostudio::ArmatureAnimation *getAnimation()
    cocostudio::ArmatureAnimation *ret = self->getAnimation();
    int num_ret = olua_push_cppobj(L, ret, "ccs.ArmatureAnimation");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_Tween_getMovementBoneData(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Tween *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Tween");

    // const cocostudio::MovementBoneData *getMovementBoneData()
    const cocostudio::MovementBoneData *ret = self->getMovementBoneData();
    int num_ret = olua_push_cppobj(L, ret, "ccs.MovementBoneData");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_Tween_gotoAndPause(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Tween *self = nullptr;
    lua_Integer arg1 = 0;       /** frameIndex */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Tween");
    olua_check_int(L, 2, &arg1);

    // void gotoAndPause(int frameIndex)
    self->gotoAndPause((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_Tween_gotoAndPlay(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Tween *self = nullptr;
    lua_Integer arg1 = 0;       /** frameIndex */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Tween");
    olua_check_int(L, 2, &arg1);

    // void gotoAndPlay(int frameIndex)
    self->gotoAndPlay((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_Tween_init(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Tween *self = nullptr;
    cocostudio::Bone *arg1 = nullptr;       /** bone */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Tween");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccs.Bone");

    // bool init(cocostudio::Bone *bone)
    bool ret = self->init(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_Tween_new(lua_State *L)
{
    olua_startinvoke(L);

    // Tween()
    cocostudio::Tween *ret = new cocostudio::Tween();
    int num_ret = olua_push_cppobj(L, ret, "ccs.Tween");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_Tween_play1(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Tween *self = nullptr;
    cocostudio::MovementBoneData *arg1 = nullptr;       /** movementBoneData */
    lua_Integer arg2 = 0;       /** durationTo */
    lua_Integer arg3 = 0;       /** durationTween */
    lua_Integer arg4 = 0;       /** loop */
    lua_Integer arg5 = 0;       /** tweenEasing */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Tween");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccs.MovementBoneData");
    olua_check_int(L, 3, &arg2);
    olua_check_int(L, 4, &arg3);
    olua_check_int(L, 5, &arg4);
    olua_check_int(L, 6, &arg5);

    // void play(cocostudio::MovementBoneData *movementBoneData, int durationTo, int durationTween, int loop, int tweenEasing)
    self->play(arg1, (int)arg2, (int)arg3, (int)arg4, (int)arg5);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_Tween_play2(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Tween *self = nullptr;
    lua_Integer arg1 = 0;       /** durationTo */
    lua_Integer arg2 = 0;       /** durationTween */
    lua_Integer arg3 = 0;       /** loop */
    lua_Integer arg4 = 0;       /** tweenEasing */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Tween");
    olua_check_int(L, 2, &arg1);
    olua_check_int(L, 3, &arg2);
    olua_check_int(L, 4, &arg3);
    olua_check_int(L, 5, &arg4);

    // @using void play(int durationTo, int durationTween, int loop, int tweenEasing)
    self->play((int)arg1, (int)arg2, (int)arg3, (int)arg4);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_Tween_play(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 4) {
        // if ((olua_is_int(L, 2)) && (olua_is_int(L, 3)) && (olua_is_int(L, 4)) && (olua_is_int(L, 5))) {
            // @using void play(int durationTo, int durationTween, int loop, int tweenEasing)
            return _cocostudio_Tween_play2(L);
        // }
    }

    if (num_args == 5) {
        // if ((olua_is_cppobj(L, 2, "ccs.MovementBoneData")) && (olua_is_int(L, 3)) && (olua_is_int(L, 4)) && (olua_is_int(L, 5)) && (olua_is_int(L, 6))) {
            // void play(cocostudio::MovementBoneData *movementBoneData, int durationTo, int durationTween, int loop, int tweenEasing)
            return _cocostudio_Tween_play1(L);
        // }
    }

    luaL_error(L, "method 'cocostudio::Tween::play' not support '%d' arguments", num_args);

    return 0;
}

static int _cocostudio_Tween_setAnimation(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Tween *self = nullptr;
    cocostudio::ArmatureAnimation *arg1 = nullptr;       /** animation */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Tween");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccs.ArmatureAnimation");

    // void setAnimation(cocostudio::ArmatureAnimation *animation)
    self->setAnimation(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_Tween_setMovementBoneData(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::Tween *self = nullptr;
    cocostudio::MovementBoneData *arg1 = nullptr;       /** data */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.Tween");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccs.MovementBoneData");

    // void setMovementBoneData(cocostudio::MovementBoneData *data)
    self->setMovementBoneData(arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocostudio_Tween(lua_State *L)
{
    oluacls_class(L, "ccs.Tween", "ccs.ProcessBase");
    oluacls_func(L, "__olua_move", _cocostudio_Tween___olua_move);
    oluacls_func(L, "create", _cocostudio_Tween_create);
    oluacls_func(L, "getAnimation", _cocostudio_Tween_getAnimation);
    oluacls_func(L, "getMovementBoneData", _cocostudio_Tween_getMovementBoneData);
    oluacls_func(L, "gotoAndPause", _cocostudio_Tween_gotoAndPause);
    oluacls_func(L, "gotoAndPlay", _cocostudio_Tween_gotoAndPlay);
    oluacls_func(L, "init", _cocostudio_Tween_init);
    oluacls_func(L, "new", _cocostudio_Tween_new);
    oluacls_func(L, "play", _cocostudio_Tween_play);
    oluacls_func(L, "setAnimation", _cocostudio_Tween_setAnimation);
    oluacls_func(L, "setMovementBoneData", _cocostudio_Tween_setMovementBoneData);
    oluacls_prop(L, "animation", _cocostudio_Tween_getAnimation, _cocostudio_Tween_setAnimation);
    oluacls_prop(L, "movementBoneData", _cocostudio_Tween_getMovementBoneData, _cocostudio_Tween_setMovementBoneData);

    olua_registerluatype<cocostudio::Tween>(L, "ccs.Tween");

    return 1;
}

static int luaopen_cocostudio_timeline_InnerActionType(lua_State *L)
{
    oluacls_class(L, "ccs.timeline.InnerActionType", nullptr);
    oluacls_const_integer(L, "LoopAction", (lua_Integer)cocostudio::timeline::InnerActionType::LoopAction);
    oluacls_const_integer(L, "NoLoopAction", (lua_Integer)cocostudio::timeline::InnerActionType::NoLoopAction);
    oluacls_const_integer(L, "SingleFrame", (lua_Integer)cocostudio::timeline::InnerActionType::SingleFrame);

    olua_registerluatype<cocostudio::timeline::InnerActionType>(L, "ccs.timeline.InnerActionType");

    return 1;
}

static int _cocostudio_timeline_Frame___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocostudio::timeline::Frame *)olua_toobj(L, 1, "ccs.timeline.Frame");
    olua_push_cppobj(L, self, "ccs.timeline.Frame");

    olua_endinvoke(L);

    return 1;
}

static int _cocostudio_timeline_Frame_apply(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::Frame *self = nullptr;
    lua_Number arg1 = 0;       /** percent */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.Frame");
    olua_check_number(L, 2, &arg1);

    // void apply(float percent)
    self->apply((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_timeline_Frame_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::Frame *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.Frame");

    // cocostudio::timeline::Frame *clone()
    cocostudio::timeline::Frame *ret = self->clone();
    int num_ret = olua_push_cppobj(L, ret, "ccs.timeline.Frame");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_Frame_getEasingParams(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::Frame *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.Frame");

    // const std::vector<float> &getEasingParams()
    const std::vector<float> &ret = self->getEasingParams();
    int num_ret = olua_push_std_vector<float>(L, &ret, [L](float value) {
        olua_push_number(L, (lua_Number)value);
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_Frame_getFrameIndex(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::Frame *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.Frame");

    // unsigned int getFrameIndex()
    unsigned int ret = self->getFrameIndex();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_Frame_getNode(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::Frame *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.Frame");

    // @addref(node ^) cocos2d::Node *getNode()
    cocos2d::Node *ret = self->getNode();
    int num_ret = olua_push_cppobj(L, ret, "cc.Node");

    // insert code after call
    olua_addref(L, 1, "node", -1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_Frame_getTimeline(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::Frame *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.Frame");

    // @addref(timeline ^) cocostudio::timeline::Timeline *getTimeline()
    cocostudio::timeline::Timeline *ret = self->getTimeline();
    int num_ret = olua_push_cppobj(L, ret, "ccs.timeline.Timeline");

    // insert code after call
    olua_addref(L, 1, "timeline", -1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_Frame_getTweenType(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::Frame *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.Frame");

    // cocos2d::tweenfunc::TweenType getTweenType()
    cocos2d::tweenfunc::TweenType ret = self->getTweenType();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_Frame_isEnterWhenPassed(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::Frame *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.Frame");

    // bool isEnterWhenPassed()
    bool ret = self->isEnterWhenPassed();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_Frame_isTween(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::Frame *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.Frame");

    // bool isTween()
    bool ret = self->isTween();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_Frame_onEnter(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::Frame *self = nullptr;
    cocostudio::timeline::Frame *arg1 = nullptr;       /** nextFrame */
    lua_Integer arg2 = 0;       /** currentFrameIndex */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.Frame");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccs.timeline.Frame");
    olua_check_int(L, 3, &arg2);

    // void onEnter(cocostudio::timeline::Frame *nextFrame, int currentFrameIndex)
    self->onEnter(arg1, (int)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_timeline_Frame_setEasingParams(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::Frame *self = nullptr;
    std::vector<float> arg1;       /** easingParams */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.Frame");
    olua_check_std_vector<float>(L, 2, &arg1, [L](float *value) {
        lua_Number obj;
        olua_check_number(L, -1, &obj);
        *value = (float)obj;
    });

    // void setEasingParams(const std::vector<float> &easingParams)
    self->setEasingParams(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_timeline_Frame_setFrameIndex(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::Frame *self = nullptr;
    lua_Unsigned arg1 = 0;       /** frameIndex */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.Frame");
    olua_check_uint(L, 2, &arg1);

    // void setFrameIndex(unsigned int frameIndex)
    self->setFrameIndex((unsigned int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_timeline_Frame_setNode(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::Frame *self = nullptr;
    cocos2d::Node *arg1 = nullptr;       /** node */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.Frame");
    olua_check_cppobj(L, 2, (void **)&arg1, "cc.Node");

    // void setNode(@addref(node ^) cocos2d::Node *node)
    self->setNode(arg1);

    // insert code after call
    olua_addref(L, 1, "node", 2, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_timeline_Frame_setTimeline(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::Frame *self = nullptr;
    cocostudio::timeline::Timeline *arg1 = nullptr;       /** timeline */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.Frame");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccs.timeline.Timeline");

    // void setTimeline(@addref(timeline ^) cocostudio::timeline::Timeline *timeline)
    self->setTimeline(arg1);

    // insert code after call
    olua_addref(L, 1, "timeline", 2, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_timeline_Frame_setTween(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::Frame *self = nullptr;
    bool arg1 = false;       /** tween */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.Frame");
    olua_check_bool(L, 2, &arg1);

    // void setTween(bool tween)
    self->setTween(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_timeline_Frame_setTweenType(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::Frame *self = nullptr;
    lua_Unsigned arg1 = 0;       /** tweenType */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.Frame");
    olua_check_uint(L, 2, &arg1);

    // void setTweenType(const cocos2d::tweenfunc::TweenType &tweenType)
    self->setTweenType((cocos2d::tweenfunc::TweenType)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocostudio_timeline_Frame(lua_State *L)
{
    oluacls_class(L, "ccs.timeline.Frame", "cc.Ref");
    oluacls_func(L, "__olua_move", _cocostudio_timeline_Frame___olua_move);
    oluacls_func(L, "apply", _cocostudio_timeline_Frame_apply);
    oluacls_func(L, "clone", _cocostudio_timeline_Frame_clone);
    oluacls_func(L, "getEasingParams", _cocostudio_timeline_Frame_getEasingParams);
    oluacls_func(L, "getFrameIndex", _cocostudio_timeline_Frame_getFrameIndex);
    oluacls_func(L, "getNode", _cocostudio_timeline_Frame_getNode);
    oluacls_func(L, "getTimeline", _cocostudio_timeline_Frame_getTimeline);
    oluacls_func(L, "getTweenType", _cocostudio_timeline_Frame_getTweenType);
    oluacls_func(L, "isEnterWhenPassed", _cocostudio_timeline_Frame_isEnterWhenPassed);
    oluacls_func(L, "isTween", _cocostudio_timeline_Frame_isTween);
    oluacls_func(L, "onEnter", _cocostudio_timeline_Frame_onEnter);
    oluacls_func(L, "setEasingParams", _cocostudio_timeline_Frame_setEasingParams);
    oluacls_func(L, "setFrameIndex", _cocostudio_timeline_Frame_setFrameIndex);
    oluacls_func(L, "setNode", _cocostudio_timeline_Frame_setNode);
    oluacls_func(L, "setTimeline", _cocostudio_timeline_Frame_setTimeline);
    oluacls_func(L, "setTween", _cocostudio_timeline_Frame_setTween);
    oluacls_func(L, "setTweenType", _cocostudio_timeline_Frame_setTweenType);
    oluacls_prop(L, "easingParams", _cocostudio_timeline_Frame_getEasingParams, _cocostudio_timeline_Frame_setEasingParams);
    oluacls_prop(L, "enterWhenPassed", _cocostudio_timeline_Frame_isEnterWhenPassed, nullptr);
    oluacls_prop(L, "frameIndex", _cocostudio_timeline_Frame_getFrameIndex, _cocostudio_timeline_Frame_setFrameIndex);
    oluacls_prop(L, "node", _cocostudio_timeline_Frame_getNode, _cocostudio_timeline_Frame_setNode);
    oluacls_prop(L, "timeline", _cocostudio_timeline_Frame_getTimeline, _cocostudio_timeline_Frame_setTimeline);
    oluacls_prop(L, "tween", _cocostudio_timeline_Frame_isTween, _cocostudio_timeline_Frame_setTween);
    oluacls_prop(L, "tweenType", _cocostudio_timeline_Frame_getTweenType, _cocostudio_timeline_Frame_setTweenType);

    olua_registerluatype<cocostudio::timeline::Frame>(L, "ccs.timeline.Frame");

    return 1;
}

static int _cocostudio_timeline_AlphaFrame___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocostudio::timeline::AlphaFrame *)olua_toobj(L, 1, "ccs.timeline.AlphaFrame");
    olua_push_cppobj(L, self, "ccs.timeline.AlphaFrame");

    olua_endinvoke(L);

    return 1;
}

static int _cocostudio_timeline_AlphaFrame_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cocostudio::timeline::AlphaFrame *create()
    cocostudio::timeline::AlphaFrame *ret = cocostudio::timeline::AlphaFrame::create();
    int num_ret = olua_push_cppobj(L, ret, "ccs.timeline.AlphaFrame");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_AlphaFrame_getAlpha(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::AlphaFrame *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.AlphaFrame");

    // uint8_t getAlpha()
    uint8_t ret = self->getAlpha();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_AlphaFrame_new(lua_State *L)
{
    olua_startinvoke(L);

    // AlphaFrame()
    cocostudio::timeline::AlphaFrame *ret = new cocostudio::timeline::AlphaFrame();
    int num_ret = olua_push_cppobj(L, ret, "ccs.timeline.AlphaFrame");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_AlphaFrame_setAlpha(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::AlphaFrame *self = nullptr;
    lua_Unsigned arg1 = 0;       /** alpha */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.AlphaFrame");
    olua_check_uint(L, 2, &arg1);

    // void setAlpha(uint8_t alpha)
    self->setAlpha((uint8_t)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocostudio_timeline_AlphaFrame(lua_State *L)
{
    oluacls_class(L, "ccs.timeline.AlphaFrame", "ccs.timeline.Frame");
    oluacls_func(L, "__olua_move", _cocostudio_timeline_AlphaFrame___olua_move);
    oluacls_func(L, "create", _cocostudio_timeline_AlphaFrame_create);
    oluacls_func(L, "getAlpha", _cocostudio_timeline_AlphaFrame_getAlpha);
    oluacls_func(L, "new", _cocostudio_timeline_AlphaFrame_new);
    oluacls_func(L, "setAlpha", _cocostudio_timeline_AlphaFrame_setAlpha);
    oluacls_prop(L, "alpha", _cocostudio_timeline_AlphaFrame_getAlpha, _cocostudio_timeline_AlphaFrame_setAlpha);

    olua_registerluatype<cocostudio::timeline::AlphaFrame>(L, "ccs.timeline.AlphaFrame");

    return 1;
}

static int _cocostudio_timeline_AnchorPointFrame___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocostudio::timeline::AnchorPointFrame *)olua_toobj(L, 1, "ccs.timeline.AnchorPointFrame");
    olua_push_cppobj(L, self, "ccs.timeline.AnchorPointFrame");

    olua_endinvoke(L);

    return 1;
}

static int _cocostudio_timeline_AnchorPointFrame_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cocostudio::timeline::AnchorPointFrame *create()
    cocostudio::timeline::AnchorPointFrame *ret = cocostudio::timeline::AnchorPointFrame::create();
    int num_ret = olua_push_cppobj(L, ret, "ccs.timeline.AnchorPointFrame");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_AnchorPointFrame_getAnchorPoint(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::AnchorPointFrame *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.AnchorPointFrame");

    // cocos2d::Point getAnchorPoint()
    cocos2d::Point ret = self->getAnchorPoint();
    int num_ret = olua_push_cocos2d_Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_AnchorPointFrame_new(lua_State *L)
{
    olua_startinvoke(L);

    // AnchorPointFrame()
    cocostudio::timeline::AnchorPointFrame *ret = new cocostudio::timeline::AnchorPointFrame();
    int num_ret = olua_push_cppobj(L, ret, "ccs.timeline.AnchorPointFrame");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_AnchorPointFrame_setAnchorPoint(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::AnchorPointFrame *self = nullptr;
    cocos2d::Point arg1;       /** point */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.AnchorPointFrame");
    olua_check_cocos2d_Vec2(L, 2, &arg1);

    // void setAnchorPoint(const cocos2d::Point &point)
    self->setAnchorPoint(arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocostudio_timeline_AnchorPointFrame(lua_State *L)
{
    oluacls_class(L, "ccs.timeline.AnchorPointFrame", "ccs.timeline.Frame");
    oluacls_func(L, "__olua_move", _cocostudio_timeline_AnchorPointFrame___olua_move);
    oluacls_func(L, "create", _cocostudio_timeline_AnchorPointFrame_create);
    oluacls_func(L, "getAnchorPoint", _cocostudio_timeline_AnchorPointFrame_getAnchorPoint);
    oluacls_func(L, "new", _cocostudio_timeline_AnchorPointFrame_new);
    oluacls_func(L, "setAnchorPoint", _cocostudio_timeline_AnchorPointFrame_setAnchorPoint);
    oluacls_prop(L, "anchorPoint", _cocostudio_timeline_AnchorPointFrame_getAnchorPoint, _cocostudio_timeline_AnchorPointFrame_setAnchorPoint);

    olua_registerluatype<cocostudio::timeline::AnchorPointFrame>(L, "ccs.timeline.AnchorPointFrame");

    return 1;
}

static int _cocostudio_timeline_BlendFuncFrame___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocostudio::timeline::BlendFuncFrame *)olua_toobj(L, 1, "ccs.timeline.BlendFuncFrame");
    olua_push_cppobj(L, self, "ccs.timeline.BlendFuncFrame");

    olua_endinvoke(L);

    return 1;
}

static int _cocostudio_timeline_BlendFuncFrame_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cocostudio::timeline::BlendFuncFrame *create()
    cocostudio::timeline::BlendFuncFrame *ret = cocostudio::timeline::BlendFuncFrame::create();
    int num_ret = olua_push_cppobj(L, ret, "ccs.timeline.BlendFuncFrame");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_BlendFuncFrame_getBlendFunc(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::BlendFuncFrame *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.BlendFuncFrame");

    // cocos2d::BlendFunc getBlendFunc()
    cocos2d::BlendFunc ret = self->getBlendFunc();
    int num_ret = olua_push_cocos2d_BlendFunc(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_BlendFuncFrame_new(lua_State *L)
{
    olua_startinvoke(L);

    // BlendFuncFrame()
    cocostudio::timeline::BlendFuncFrame *ret = new cocostudio::timeline::BlendFuncFrame();
    int num_ret = olua_push_cppobj(L, ret, "ccs.timeline.BlendFuncFrame");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_BlendFuncFrame_setBlendFunc(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::BlendFuncFrame *self = nullptr;
    cocos2d::BlendFunc arg1;       /** blendFunc */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.BlendFuncFrame");
    olua_check_cocos2d_BlendFunc(L, 2, &arg1);

    // void setBlendFunc(cocos2d::BlendFunc blendFunc)
    self->setBlendFunc(arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocostudio_timeline_BlendFuncFrame(lua_State *L)
{
    oluacls_class(L, "ccs.timeline.BlendFuncFrame", "ccs.timeline.Frame");
    oluacls_func(L, "__olua_move", _cocostudio_timeline_BlendFuncFrame___olua_move);
    oluacls_func(L, "create", _cocostudio_timeline_BlendFuncFrame_create);
    oluacls_func(L, "getBlendFunc", _cocostudio_timeline_BlendFuncFrame_getBlendFunc);
    oluacls_func(L, "new", _cocostudio_timeline_BlendFuncFrame_new);
    oluacls_func(L, "setBlendFunc", _cocostudio_timeline_BlendFuncFrame_setBlendFunc);
    oluacls_prop(L, "blendFunc", _cocostudio_timeline_BlendFuncFrame_getBlendFunc, _cocostudio_timeline_BlendFuncFrame_setBlendFunc);

    olua_registerluatype<cocostudio::timeline::BlendFuncFrame>(L, "ccs.timeline.BlendFuncFrame");

    return 1;
}

static int _cocostudio_timeline_ColorFrame___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocostudio::timeline::ColorFrame *)olua_toobj(L, 1, "ccs.timeline.ColorFrame");
    olua_push_cppobj(L, self, "ccs.timeline.ColorFrame");

    olua_endinvoke(L);

    return 1;
}

static int _cocostudio_timeline_ColorFrame_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cocostudio::timeline::ColorFrame *create()
    cocostudio::timeline::ColorFrame *ret = cocostudio::timeline::ColorFrame::create();
    int num_ret = olua_push_cppobj(L, ret, "ccs.timeline.ColorFrame");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_ColorFrame_getColor(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::ColorFrame *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.ColorFrame");

    // cocos2d::Color3B getColor()
    cocos2d::Color3B ret = self->getColor();
    int num_ret = olua_push_cocos2d_Color3B(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_ColorFrame_new(lua_State *L)
{
    olua_startinvoke(L);

    // ColorFrame()
    cocostudio::timeline::ColorFrame *ret = new cocostudio::timeline::ColorFrame();
    int num_ret = olua_push_cppobj(L, ret, "ccs.timeline.ColorFrame");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_ColorFrame_setColor(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::ColorFrame *self = nullptr;
    cocos2d::Color3B arg1;       /** color */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.ColorFrame");
    olua_check_cocos2d_Color3B(L, 2, &arg1);

    // void setColor(const cocos2d::Color3B &color)
    self->setColor(arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocostudio_timeline_ColorFrame(lua_State *L)
{
    oluacls_class(L, "ccs.timeline.ColorFrame", "ccs.timeline.Frame");
    oluacls_func(L, "__olua_move", _cocostudio_timeline_ColorFrame___olua_move);
    oluacls_func(L, "create", _cocostudio_timeline_ColorFrame_create);
    oluacls_func(L, "getColor", _cocostudio_timeline_ColorFrame_getColor);
    oluacls_func(L, "new", _cocostudio_timeline_ColorFrame_new);
    oluacls_func(L, "setColor", _cocostudio_timeline_ColorFrame_setColor);
    oluacls_prop(L, "color", _cocostudio_timeline_ColorFrame_getColor, _cocostudio_timeline_ColorFrame_setColor);

    olua_registerluatype<cocostudio::timeline::ColorFrame>(L, "ccs.timeline.ColorFrame");

    return 1;
}

static int _cocostudio_timeline_EventFrame___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocostudio::timeline::EventFrame *)olua_toobj(L, 1, "ccs.timeline.EventFrame");
    olua_push_cppobj(L, self, "ccs.timeline.EventFrame");

    olua_endinvoke(L);

    return 1;
}

static int _cocostudio_timeline_EventFrame_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cocostudio::timeline::EventFrame *create()
    cocostudio::timeline::EventFrame *ret = cocostudio::timeline::EventFrame::create();
    int num_ret = olua_push_cppobj(L, ret, "ccs.timeline.EventFrame");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_EventFrame_getEvent(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::EventFrame *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.EventFrame");

    // std::string getEvent()
    std::string ret = self->getEvent();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_EventFrame_init(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::EventFrame *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.EventFrame");

    // void init()
    self->init();

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_timeline_EventFrame_new(lua_State *L)
{
    olua_startinvoke(L);

    // EventFrame()
    cocostudio::timeline::EventFrame *ret = new cocostudio::timeline::EventFrame();
    int num_ret = olua_push_cppobj(L, ret, "ccs.timeline.EventFrame");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_EventFrame_setEvent(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::EventFrame *self = nullptr;
    std::string arg1;       /** event */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.EventFrame");
    olua_check_std_string(L, 2, &arg1);

    // void setEvent(std::string event)
    self->setEvent(arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocostudio_timeline_EventFrame(lua_State *L)
{
    oluacls_class(L, "ccs.timeline.EventFrame", "ccs.timeline.Frame");
    oluacls_func(L, "__olua_move", _cocostudio_timeline_EventFrame___olua_move);
    oluacls_func(L, "create", _cocostudio_timeline_EventFrame_create);
    oluacls_func(L, "getEvent", _cocostudio_timeline_EventFrame_getEvent);
    oluacls_func(L, "init", _cocostudio_timeline_EventFrame_init);
    oluacls_func(L, "new", _cocostudio_timeline_EventFrame_new);
    oluacls_func(L, "setEvent", _cocostudio_timeline_EventFrame_setEvent);
    oluacls_prop(L, "event", _cocostudio_timeline_EventFrame_getEvent, _cocostudio_timeline_EventFrame_setEvent);

    olua_registerluatype<cocostudio::timeline::EventFrame>(L, "ccs.timeline.EventFrame");

    return 1;
}

static int _cocostudio_timeline_InnerActionFrame___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocostudio::timeline::InnerActionFrame *)olua_toobj(L, 1, "ccs.timeline.InnerActionFrame");
    olua_push_cppobj(L, self, "ccs.timeline.InnerActionFrame");

    olua_endinvoke(L);

    return 1;
}

static int _cocostudio_timeline_InnerActionFrame_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cocostudio::timeline::InnerActionFrame *create()
    cocostudio::timeline::InnerActionFrame *ret = cocostudio::timeline::InnerActionFrame::create();
    int num_ret = olua_push_cppobj(L, ret, "ccs.timeline.InnerActionFrame");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_InnerActionFrame_getEndFrameIndex(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::InnerActionFrame *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.InnerActionFrame");

    // int getEndFrameIndex()
    int ret = self->getEndFrameIndex();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_InnerActionFrame_getInnerActionType(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::InnerActionFrame *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.InnerActionFrame");

    // cocostudio::timeline::InnerActionType getInnerActionType()
    cocostudio::timeline::InnerActionType ret = self->getInnerActionType();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_InnerActionFrame_getSingleFrameIndex(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::InnerActionFrame *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.InnerActionFrame");

    // int getSingleFrameIndex()
    int ret = self->getSingleFrameIndex();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_InnerActionFrame_getStartFrameIndex(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::InnerActionFrame *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.InnerActionFrame");

    // int getStartFrameIndex()
    int ret = self->getStartFrameIndex();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_InnerActionFrame_new(lua_State *L)
{
    olua_startinvoke(L);

    // InnerActionFrame()
    cocostudio::timeline::InnerActionFrame *ret = new cocostudio::timeline::InnerActionFrame();
    int num_ret = olua_push_cppobj(L, ret, "ccs.timeline.InnerActionFrame");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_InnerActionFrame_setAnimationName(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::InnerActionFrame *self = nullptr;
    std::string arg1;       /** animationNamed */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.InnerActionFrame");
    olua_check_std_string(L, 2, &arg1);

    // void setAnimationName(const std::string &animationNamed)
    self->setAnimationName(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_timeline_InnerActionFrame_setEndFrameIndex(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::InnerActionFrame *self = nullptr;
    lua_Integer arg1 = 0;       /** frameIndex */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.InnerActionFrame");
    olua_check_int(L, 2, &arg1);

    // void setEndFrameIndex(int frameIndex)
    self->setEndFrameIndex((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_timeline_InnerActionFrame_setEnterWithName(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::InnerActionFrame *self = nullptr;
    bool arg1 = false;       /** isEnterWithName */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.InnerActionFrame");
    olua_check_bool(L, 2, &arg1);

    // void setEnterWithName(bool isEnterWithName)
    self->setEnterWithName(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_timeline_InnerActionFrame_setInnerActionType(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::InnerActionFrame *self = nullptr;
    lua_Unsigned arg1 = 0;       /** type */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.InnerActionFrame");
    olua_check_uint(L, 2, &arg1);

    // void setInnerActionType(cocostudio::timeline::InnerActionType type)
    self->setInnerActionType((cocostudio::timeline::InnerActionType)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_timeline_InnerActionFrame_setSingleFrameIndex(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::InnerActionFrame *self = nullptr;
    lua_Integer arg1 = 0;       /** frameIndex */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.InnerActionFrame");
    olua_check_int(L, 2, &arg1);

    // void setSingleFrameIndex(int frameIndex)
    self->setSingleFrameIndex((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_timeline_InnerActionFrame_setStartFrameIndex(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::InnerActionFrame *self = nullptr;
    lua_Integer arg1 = 0;       /** frameIndex */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.InnerActionFrame");
    olua_check_int(L, 2, &arg1);

    // void setStartFrameIndex(int frameIndex)
    self->setStartFrameIndex((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocostudio_timeline_InnerActionFrame(lua_State *L)
{
    oluacls_class(L, "ccs.timeline.InnerActionFrame", "ccs.timeline.Frame");
    oluacls_func(L, "__olua_move", _cocostudio_timeline_InnerActionFrame___olua_move);
    oluacls_func(L, "create", _cocostudio_timeline_InnerActionFrame_create);
    oluacls_func(L, "getEndFrameIndex", _cocostudio_timeline_InnerActionFrame_getEndFrameIndex);
    oluacls_func(L, "getInnerActionType", _cocostudio_timeline_InnerActionFrame_getInnerActionType);
    oluacls_func(L, "getSingleFrameIndex", _cocostudio_timeline_InnerActionFrame_getSingleFrameIndex);
    oluacls_func(L, "getStartFrameIndex", _cocostudio_timeline_InnerActionFrame_getStartFrameIndex);
    oluacls_func(L, "new", _cocostudio_timeline_InnerActionFrame_new);
    oluacls_func(L, "setAnimationName", _cocostudio_timeline_InnerActionFrame_setAnimationName);
    oluacls_func(L, "setEndFrameIndex", _cocostudio_timeline_InnerActionFrame_setEndFrameIndex);
    oluacls_func(L, "setEnterWithName", _cocostudio_timeline_InnerActionFrame_setEnterWithName);
    oluacls_func(L, "setInnerActionType", _cocostudio_timeline_InnerActionFrame_setInnerActionType);
    oluacls_func(L, "setSingleFrameIndex", _cocostudio_timeline_InnerActionFrame_setSingleFrameIndex);
    oluacls_func(L, "setStartFrameIndex", _cocostudio_timeline_InnerActionFrame_setStartFrameIndex);
    oluacls_prop(L, "endFrameIndex", _cocostudio_timeline_InnerActionFrame_getEndFrameIndex, _cocostudio_timeline_InnerActionFrame_setEndFrameIndex);
    oluacls_prop(L, "innerActionType", _cocostudio_timeline_InnerActionFrame_getInnerActionType, _cocostudio_timeline_InnerActionFrame_setInnerActionType);
    oluacls_prop(L, "singleFrameIndex", _cocostudio_timeline_InnerActionFrame_getSingleFrameIndex, _cocostudio_timeline_InnerActionFrame_setSingleFrameIndex);
    oluacls_prop(L, "startFrameIndex", _cocostudio_timeline_InnerActionFrame_getStartFrameIndex, _cocostudio_timeline_InnerActionFrame_setStartFrameIndex);
    oluacls_const_string(L, "AnimationAllName", (const char *)cocostudio::timeline::InnerActionFrame::AnimationAllName.c_str());

    olua_registerluatype<cocostudio::timeline::InnerActionFrame>(L, "ccs.timeline.InnerActionFrame");

    return 1;
}

static int _cocostudio_timeline_PlayableFrame___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocostudio::timeline::PlayableFrame *)olua_toobj(L, 1, "ccs.timeline.PlayableFrame");
    olua_push_cppobj(L, self, "ccs.timeline.PlayableFrame");

    olua_endinvoke(L);

    return 1;
}

static int _cocostudio_timeline_PlayableFrame_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cocostudio::timeline::PlayableFrame *create()
    cocostudio::timeline::PlayableFrame *ret = cocostudio::timeline::PlayableFrame::create();
    int num_ret = olua_push_cppobj(L, ret, "ccs.timeline.PlayableFrame");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_PlayableFrame_getPlayableAct(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::PlayableFrame *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.PlayableFrame");

    // std::string getPlayableAct()
    std::string ret = self->getPlayableAct();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_PlayableFrame_new(lua_State *L)
{
    olua_startinvoke(L);

    // PlayableFrame()
    cocostudio::timeline::PlayableFrame *ret = new cocostudio::timeline::PlayableFrame();
    int num_ret = olua_push_cppobj(L, ret, "ccs.timeline.PlayableFrame");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_PlayableFrame_setPlayableAct(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::PlayableFrame *self = nullptr;
    std::string arg1;       /** playact */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.PlayableFrame");
    olua_check_std_string(L, 2, &arg1);

    // void setPlayableAct(std::string playact)
    self->setPlayableAct(arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocostudio_timeline_PlayableFrame(lua_State *L)
{
    oluacls_class(L, "ccs.timeline.PlayableFrame", "ccs.timeline.Frame");
    oluacls_func(L, "__olua_move", _cocostudio_timeline_PlayableFrame___olua_move);
    oluacls_func(L, "create", _cocostudio_timeline_PlayableFrame_create);
    oluacls_func(L, "getPlayableAct", _cocostudio_timeline_PlayableFrame_getPlayableAct);
    oluacls_func(L, "new", _cocostudio_timeline_PlayableFrame_new);
    oluacls_func(L, "setPlayableAct", _cocostudio_timeline_PlayableFrame_setPlayableAct);
    oluacls_prop(L, "playableAct", _cocostudio_timeline_PlayableFrame_getPlayableAct, _cocostudio_timeline_PlayableFrame_setPlayableAct);
    oluacls_const_string(L, "PLAYABLE_EXTENTION", (const char *)cocostudio::timeline::PlayableFrame::PLAYABLE_EXTENTION.c_str());

    olua_registerluatype<cocostudio::timeline::PlayableFrame>(L, "ccs.timeline.PlayableFrame");

    return 1;
}

static int _cocostudio_timeline_PositionFrame___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocostudio::timeline::PositionFrame *)olua_toobj(L, 1, "ccs.timeline.PositionFrame");
    olua_push_cppobj(L, self, "ccs.timeline.PositionFrame");

    olua_endinvoke(L);

    return 1;
}

static int _cocostudio_timeline_PositionFrame_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cocostudio::timeline::PositionFrame *create()
    cocostudio::timeline::PositionFrame *ret = cocostudio::timeline::PositionFrame::create();
    int num_ret = olua_push_cppobj(L, ret, "ccs.timeline.PositionFrame");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_PositionFrame_getPosition(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::PositionFrame *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.PositionFrame");

    // cocos2d::Point getPosition()
    cocos2d::Point ret = self->getPosition();
    int num_ret = olua_push_cocos2d_Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_PositionFrame_getX(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::PositionFrame *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.PositionFrame");

    // float getX()
    float ret = self->getX();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_PositionFrame_getY(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::PositionFrame *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.PositionFrame");

    // float getY()
    float ret = self->getY();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_PositionFrame_new(lua_State *L)
{
    olua_startinvoke(L);

    // PositionFrame()
    cocostudio::timeline::PositionFrame *ret = new cocostudio::timeline::PositionFrame();
    int num_ret = olua_push_cppobj(L, ret, "ccs.timeline.PositionFrame");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_PositionFrame_setPosition(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::PositionFrame *self = nullptr;
    cocos2d::Point arg1;       /** position */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.PositionFrame");
    olua_check_cocos2d_Vec2(L, 2, &arg1);

    // void setPosition(const cocos2d::Point &position)
    self->setPosition(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_timeline_PositionFrame_setX(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::PositionFrame *self = nullptr;
    lua_Number arg1 = 0;       /** x */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.PositionFrame");
    olua_check_number(L, 2, &arg1);

    // void setX(float x)
    self->setX((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_timeline_PositionFrame_setY(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::PositionFrame *self = nullptr;
    lua_Number arg1 = 0;       /** y */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.PositionFrame");
    olua_check_number(L, 2, &arg1);

    // void setY(float y)
    self->setY((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocostudio_timeline_PositionFrame(lua_State *L)
{
    oluacls_class(L, "ccs.timeline.PositionFrame", "ccs.timeline.Frame");
    oluacls_func(L, "__olua_move", _cocostudio_timeline_PositionFrame___olua_move);
    oluacls_func(L, "create", _cocostudio_timeline_PositionFrame_create);
    oluacls_func(L, "getPosition", _cocostudio_timeline_PositionFrame_getPosition);
    oluacls_func(L, "getX", _cocostudio_timeline_PositionFrame_getX);
    oluacls_func(L, "getY", _cocostudio_timeline_PositionFrame_getY);
    oluacls_func(L, "new", _cocostudio_timeline_PositionFrame_new);
    oluacls_func(L, "setPosition", _cocostudio_timeline_PositionFrame_setPosition);
    oluacls_func(L, "setX", _cocostudio_timeline_PositionFrame_setX);
    oluacls_func(L, "setY", _cocostudio_timeline_PositionFrame_setY);
    oluacls_prop(L, "position", _cocostudio_timeline_PositionFrame_getPosition, _cocostudio_timeline_PositionFrame_setPosition);
    oluacls_prop(L, "x", _cocostudio_timeline_PositionFrame_getX, _cocostudio_timeline_PositionFrame_setX);
    oluacls_prop(L, "y", _cocostudio_timeline_PositionFrame_getY, _cocostudio_timeline_PositionFrame_setY);

    olua_registerluatype<cocostudio::timeline::PositionFrame>(L, "ccs.timeline.PositionFrame");

    return 1;
}

static int _cocostudio_timeline_RotationFrame___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocostudio::timeline::RotationFrame *)olua_toobj(L, 1, "ccs.timeline.RotationFrame");
    olua_push_cppobj(L, self, "ccs.timeline.RotationFrame");

    olua_endinvoke(L);

    return 1;
}

static int _cocostudio_timeline_RotationFrame_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cocostudio::timeline::RotationFrame *create()
    cocostudio::timeline::RotationFrame *ret = cocostudio::timeline::RotationFrame::create();
    int num_ret = olua_push_cppobj(L, ret, "ccs.timeline.RotationFrame");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_RotationFrame_getRotation(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::RotationFrame *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.RotationFrame");

    // float getRotation()
    float ret = self->getRotation();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_RotationFrame_new(lua_State *L)
{
    olua_startinvoke(L);

    // RotationFrame()
    cocostudio::timeline::RotationFrame *ret = new cocostudio::timeline::RotationFrame();
    int num_ret = olua_push_cppobj(L, ret, "ccs.timeline.RotationFrame");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_RotationFrame_setRotation(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::RotationFrame *self = nullptr;
    lua_Number arg1 = 0;       /** rotation */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.RotationFrame");
    olua_check_number(L, 2, &arg1);

    // void setRotation(float rotation)
    self->setRotation((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocostudio_timeline_RotationFrame(lua_State *L)
{
    oluacls_class(L, "ccs.timeline.RotationFrame", "ccs.timeline.Frame");
    oluacls_func(L, "__olua_move", _cocostudio_timeline_RotationFrame___olua_move);
    oluacls_func(L, "create", _cocostudio_timeline_RotationFrame_create);
    oluacls_func(L, "getRotation", _cocostudio_timeline_RotationFrame_getRotation);
    oluacls_func(L, "new", _cocostudio_timeline_RotationFrame_new);
    oluacls_func(L, "setRotation", _cocostudio_timeline_RotationFrame_setRotation);
    oluacls_prop(L, "rotation", _cocostudio_timeline_RotationFrame_getRotation, _cocostudio_timeline_RotationFrame_setRotation);

    olua_registerluatype<cocostudio::timeline::RotationFrame>(L, "ccs.timeline.RotationFrame");

    return 1;
}

static int _cocostudio_timeline_SkewFrame___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocostudio::timeline::SkewFrame *)olua_toobj(L, 1, "ccs.timeline.SkewFrame");
    olua_push_cppobj(L, self, "ccs.timeline.SkewFrame");

    olua_endinvoke(L);

    return 1;
}

static int _cocostudio_timeline_SkewFrame_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cocostudio::timeline::SkewFrame *create()
    cocostudio::timeline::SkewFrame *ret = cocostudio::timeline::SkewFrame::create();
    int num_ret = olua_push_cppobj(L, ret, "ccs.timeline.SkewFrame");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_SkewFrame_getSkewX(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::SkewFrame *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.SkewFrame");

    // float getSkewX()
    float ret = self->getSkewX();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_SkewFrame_getSkewY(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::SkewFrame *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.SkewFrame");

    // float getSkewY()
    float ret = self->getSkewY();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_SkewFrame_new(lua_State *L)
{
    olua_startinvoke(L);

    // SkewFrame()
    cocostudio::timeline::SkewFrame *ret = new cocostudio::timeline::SkewFrame();
    int num_ret = olua_push_cppobj(L, ret, "ccs.timeline.SkewFrame");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_SkewFrame_setSkewX(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::SkewFrame *self = nullptr;
    lua_Number arg1 = 0;       /** skewx */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.SkewFrame");
    olua_check_number(L, 2, &arg1);

    // void setSkewX(float skewx)
    self->setSkewX((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_timeline_SkewFrame_setSkewY(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::SkewFrame *self = nullptr;
    lua_Number arg1 = 0;       /** skewy */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.SkewFrame");
    olua_check_number(L, 2, &arg1);

    // void setSkewY(float skewy)
    self->setSkewY((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocostudio_timeline_SkewFrame(lua_State *L)
{
    oluacls_class(L, "ccs.timeline.SkewFrame", "ccs.timeline.Frame");
    oluacls_func(L, "__olua_move", _cocostudio_timeline_SkewFrame___olua_move);
    oluacls_func(L, "create", _cocostudio_timeline_SkewFrame_create);
    oluacls_func(L, "getSkewX", _cocostudio_timeline_SkewFrame_getSkewX);
    oluacls_func(L, "getSkewY", _cocostudio_timeline_SkewFrame_getSkewY);
    oluacls_func(L, "new", _cocostudio_timeline_SkewFrame_new);
    oluacls_func(L, "setSkewX", _cocostudio_timeline_SkewFrame_setSkewX);
    oluacls_func(L, "setSkewY", _cocostudio_timeline_SkewFrame_setSkewY);
    oluacls_prop(L, "skewX", _cocostudio_timeline_SkewFrame_getSkewX, _cocostudio_timeline_SkewFrame_setSkewX);
    oluacls_prop(L, "skewY", _cocostudio_timeline_SkewFrame_getSkewY, _cocostudio_timeline_SkewFrame_setSkewY);

    olua_registerluatype<cocostudio::timeline::SkewFrame>(L, "ccs.timeline.SkewFrame");

    return 1;
}

static int _cocostudio_timeline_RotationSkewFrame___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocostudio::timeline::RotationSkewFrame *)olua_toobj(L, 1, "ccs.timeline.RotationSkewFrame");
    olua_push_cppobj(L, self, "ccs.timeline.RotationSkewFrame");

    olua_endinvoke(L);

    return 1;
}

static int _cocostudio_timeline_RotationSkewFrame_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cocostudio::timeline::RotationSkewFrame *create()
    cocostudio::timeline::RotationSkewFrame *ret = cocostudio::timeline::RotationSkewFrame::create();
    int num_ret = olua_push_cppobj(L, ret, "ccs.timeline.RotationSkewFrame");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_RotationSkewFrame_new(lua_State *L)
{
    olua_startinvoke(L);

    // RotationSkewFrame()
    cocostudio::timeline::RotationSkewFrame *ret = new cocostudio::timeline::RotationSkewFrame();
    int num_ret = olua_push_cppobj(L, ret, "ccs.timeline.RotationSkewFrame");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocostudio_timeline_RotationSkewFrame(lua_State *L)
{
    oluacls_class(L, "ccs.timeline.RotationSkewFrame", "ccs.timeline.SkewFrame");
    oluacls_func(L, "__olua_move", _cocostudio_timeline_RotationSkewFrame___olua_move);
    oluacls_func(L, "create", _cocostudio_timeline_RotationSkewFrame_create);
    oluacls_func(L, "new", _cocostudio_timeline_RotationSkewFrame_new);

    olua_registerluatype<cocostudio::timeline::RotationSkewFrame>(L, "ccs.timeline.RotationSkewFrame");

    return 1;
}

static int _cocostudio_timeline_ScaleFrame___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocostudio::timeline::ScaleFrame *)olua_toobj(L, 1, "ccs.timeline.ScaleFrame");
    olua_push_cppobj(L, self, "ccs.timeline.ScaleFrame");

    olua_endinvoke(L);

    return 1;
}

static int _cocostudio_timeline_ScaleFrame_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cocostudio::timeline::ScaleFrame *create()
    cocostudio::timeline::ScaleFrame *ret = cocostudio::timeline::ScaleFrame::create();
    int num_ret = olua_push_cppobj(L, ret, "ccs.timeline.ScaleFrame");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_ScaleFrame_getScaleX(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::ScaleFrame *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.ScaleFrame");

    // float getScaleX()
    float ret = self->getScaleX();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_ScaleFrame_getScaleY(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::ScaleFrame *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.ScaleFrame");

    // float getScaleY()
    float ret = self->getScaleY();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_ScaleFrame_new(lua_State *L)
{
    olua_startinvoke(L);

    // ScaleFrame()
    cocostudio::timeline::ScaleFrame *ret = new cocostudio::timeline::ScaleFrame();
    int num_ret = olua_push_cppobj(L, ret, "ccs.timeline.ScaleFrame");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_ScaleFrame_setScale(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::ScaleFrame *self = nullptr;
    lua_Number arg1 = 0;       /** scale */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.ScaleFrame");
    olua_check_number(L, 2, &arg1);

    // void setScale(float scale)
    self->setScale((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_timeline_ScaleFrame_setScaleX(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::ScaleFrame *self = nullptr;
    lua_Number arg1 = 0;       /** scaleX */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.ScaleFrame");
    olua_check_number(L, 2, &arg1);

    // void setScaleX(float scaleX)
    self->setScaleX((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_timeline_ScaleFrame_setScaleY(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::ScaleFrame *self = nullptr;
    lua_Number arg1 = 0;       /** scaleY */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.ScaleFrame");
    olua_check_number(L, 2, &arg1);

    // void setScaleY(float scaleY)
    self->setScaleY((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocostudio_timeline_ScaleFrame(lua_State *L)
{
    oluacls_class(L, "ccs.timeline.ScaleFrame", "ccs.timeline.Frame");
    oluacls_func(L, "__olua_move", _cocostudio_timeline_ScaleFrame___olua_move);
    oluacls_func(L, "create", _cocostudio_timeline_ScaleFrame_create);
    oluacls_func(L, "getScaleX", _cocostudio_timeline_ScaleFrame_getScaleX);
    oluacls_func(L, "getScaleY", _cocostudio_timeline_ScaleFrame_getScaleY);
    oluacls_func(L, "new", _cocostudio_timeline_ScaleFrame_new);
    oluacls_func(L, "setScale", _cocostudio_timeline_ScaleFrame_setScale);
    oluacls_func(L, "setScaleX", _cocostudio_timeline_ScaleFrame_setScaleX);
    oluacls_func(L, "setScaleY", _cocostudio_timeline_ScaleFrame_setScaleY);
    oluacls_prop(L, "scaleX", _cocostudio_timeline_ScaleFrame_getScaleX, _cocostudio_timeline_ScaleFrame_setScaleX);
    oluacls_prop(L, "scaleY", _cocostudio_timeline_ScaleFrame_getScaleY, _cocostudio_timeline_ScaleFrame_setScaleY);

    olua_registerluatype<cocostudio::timeline::ScaleFrame>(L, "ccs.timeline.ScaleFrame");

    return 1;
}

static int _cocostudio_timeline_TextureFrame___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocostudio::timeline::TextureFrame *)olua_toobj(L, 1, "ccs.timeline.TextureFrame");
    olua_push_cppobj(L, self, "ccs.timeline.TextureFrame");

    olua_endinvoke(L);

    return 1;
}

static int _cocostudio_timeline_TextureFrame_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cocostudio::timeline::TextureFrame *create()
    cocostudio::timeline::TextureFrame *ret = cocostudio::timeline::TextureFrame::create();
    int num_ret = olua_push_cppobj(L, ret, "ccs.timeline.TextureFrame");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_TextureFrame_getTextureName(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::TextureFrame *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.TextureFrame");

    // std::string getTextureName()
    std::string ret = self->getTextureName();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_TextureFrame_new(lua_State *L)
{
    olua_startinvoke(L);

    // TextureFrame()
    cocostudio::timeline::TextureFrame *ret = new cocostudio::timeline::TextureFrame();
    int num_ret = olua_push_cppobj(L, ret, "ccs.timeline.TextureFrame");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_TextureFrame_setTextureName(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::TextureFrame *self = nullptr;
    std::string arg1;       /** textureName */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.TextureFrame");
    olua_check_std_string(L, 2, &arg1);

    // void setTextureName(std::string textureName)
    self->setTextureName(arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocostudio_timeline_TextureFrame(lua_State *L)
{
    oluacls_class(L, "ccs.timeline.TextureFrame", "ccs.timeline.Frame");
    oluacls_func(L, "__olua_move", _cocostudio_timeline_TextureFrame___olua_move);
    oluacls_func(L, "create", _cocostudio_timeline_TextureFrame_create);
    oluacls_func(L, "getTextureName", _cocostudio_timeline_TextureFrame_getTextureName);
    oluacls_func(L, "new", _cocostudio_timeline_TextureFrame_new);
    oluacls_func(L, "setTextureName", _cocostudio_timeline_TextureFrame_setTextureName);
    oluacls_prop(L, "textureName", _cocostudio_timeline_TextureFrame_getTextureName, _cocostudio_timeline_TextureFrame_setTextureName);

    olua_registerluatype<cocostudio::timeline::TextureFrame>(L, "ccs.timeline.TextureFrame");

    return 1;
}

static int _cocostudio_timeline_VisibleFrame___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocostudio::timeline::VisibleFrame *)olua_toobj(L, 1, "ccs.timeline.VisibleFrame");
    olua_push_cppobj(L, self, "ccs.timeline.VisibleFrame");

    olua_endinvoke(L);

    return 1;
}

static int _cocostudio_timeline_VisibleFrame_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cocostudio::timeline::VisibleFrame *create()
    cocostudio::timeline::VisibleFrame *ret = cocostudio::timeline::VisibleFrame::create();
    int num_ret = olua_push_cppobj(L, ret, "ccs.timeline.VisibleFrame");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_VisibleFrame_isVisible(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::VisibleFrame *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.VisibleFrame");

    // bool isVisible()
    bool ret = self->isVisible();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_VisibleFrame_new(lua_State *L)
{
    olua_startinvoke(L);

    // VisibleFrame()
    cocostudio::timeline::VisibleFrame *ret = new cocostudio::timeline::VisibleFrame();
    int num_ret = olua_push_cppobj(L, ret, "ccs.timeline.VisibleFrame");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_VisibleFrame_setVisible(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::VisibleFrame *self = nullptr;
    bool arg1 = false;       /** visible */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.VisibleFrame");
    olua_check_bool(L, 2, &arg1);

    // void setVisible(bool visible)
    self->setVisible(arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocostudio_timeline_VisibleFrame(lua_State *L)
{
    oluacls_class(L, "ccs.timeline.VisibleFrame", "ccs.timeline.Frame");
    oluacls_func(L, "__olua_move", _cocostudio_timeline_VisibleFrame___olua_move);
    oluacls_func(L, "create", _cocostudio_timeline_VisibleFrame_create);
    oluacls_func(L, "isVisible", _cocostudio_timeline_VisibleFrame_isVisible);
    oluacls_func(L, "new", _cocostudio_timeline_VisibleFrame_new);
    oluacls_func(L, "setVisible", _cocostudio_timeline_VisibleFrame_setVisible);
    oluacls_prop(L, "visible", _cocostudio_timeline_VisibleFrame_isVisible, _cocostudio_timeline_VisibleFrame_setVisible);

    olua_registerluatype<cocostudio::timeline::VisibleFrame>(L, "ccs.timeline.VisibleFrame");

    return 1;
}

static int _cocostudio_timeline_ZOrderFrame___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocostudio::timeline::ZOrderFrame *)olua_toobj(L, 1, "ccs.timeline.ZOrderFrame");
    olua_push_cppobj(L, self, "ccs.timeline.ZOrderFrame");

    olua_endinvoke(L);

    return 1;
}

static int _cocostudio_timeline_ZOrderFrame_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cocostudio::timeline::ZOrderFrame *create()
    cocostudio::timeline::ZOrderFrame *ret = cocostudio::timeline::ZOrderFrame::create();
    int num_ret = olua_push_cppobj(L, ret, "ccs.timeline.ZOrderFrame");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_ZOrderFrame_getZOrder(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::ZOrderFrame *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.ZOrderFrame");

    // int getZOrder()
    int ret = self->getZOrder();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_ZOrderFrame_new(lua_State *L)
{
    olua_startinvoke(L);

    // ZOrderFrame()
    cocostudio::timeline::ZOrderFrame *ret = new cocostudio::timeline::ZOrderFrame();
    int num_ret = olua_push_cppobj(L, ret, "ccs.timeline.ZOrderFrame");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_ZOrderFrame_setZOrder(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::ZOrderFrame *self = nullptr;
    lua_Integer arg1 = 0;       /** zorder */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.ZOrderFrame");
    olua_check_int(L, 2, &arg1);

    // void setZOrder(int zorder)
    self->setZOrder((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocostudio_timeline_ZOrderFrame(lua_State *L)
{
    oluacls_class(L, "ccs.timeline.ZOrderFrame", "ccs.timeline.Frame");
    oluacls_func(L, "__olua_move", _cocostudio_timeline_ZOrderFrame___olua_move);
    oluacls_func(L, "create", _cocostudio_timeline_ZOrderFrame_create);
    oluacls_func(L, "getZOrder", _cocostudio_timeline_ZOrderFrame_getZOrder);
    oluacls_func(L, "new", _cocostudio_timeline_ZOrderFrame_new);
    oluacls_func(L, "setZOrder", _cocostudio_timeline_ZOrderFrame_setZOrder);
    oluacls_prop(L, "zOrder", _cocostudio_timeline_ZOrderFrame_getZOrder, _cocostudio_timeline_ZOrderFrame_setZOrder);

    olua_registerluatype<cocostudio::timeline::ZOrderFrame>(L, "ccs.timeline.ZOrderFrame");

    return 1;
}

static int _cocostudio_timeline_ActionTimelineCache___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocostudio::timeline::ActionTimelineCache *)olua_toobj(L, 1, "ccs.timeline.ActionTimelineCache");
    olua_push_cppobj(L, self, "ccs.timeline.ActionTimelineCache");

    olua_endinvoke(L);

    return 1;
}

static int _cocostudio_timeline_ActionTimelineCache_createAction(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** fileName */

    olua_check_std_string(L, 1, &arg1);

    // static cocostudio::timeline::ActionTimeline *createAction(const std::string &fileName)
    cocostudio::timeline::ActionTimeline *ret = cocostudio::timeline::ActionTimelineCache::createAction(arg1);
    int num_ret = olua_push_cppobj(L, ret, "ccs.timeline.ActionTimeline");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_ActionTimelineCache_createActionFromContent(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::ActionTimelineCache *self = nullptr;
    std::string arg1;       /** fileName */
    std::string arg2;       /** content */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.ActionTimelineCache");
    olua_check_std_string(L, 2, &arg1);
    olua_check_std_string(L, 3, &arg2);

    // cocostudio::timeline::ActionTimeline *createActionFromContent(const std::string &fileName, const std::string &content)
    cocostudio::timeline::ActionTimeline *ret = self->createActionFromContent(arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "ccs.timeline.ActionTimeline");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_ActionTimelineCache_createActionFromJson(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::ActionTimelineCache *self = nullptr;
    std::string arg1;       /** fileName */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.ActionTimelineCache");
    olua_check_std_string(L, 2, &arg1);

    // cocostudio::timeline::ActionTimeline *createActionFromJson(const std::string &fileName)
    cocostudio::timeline::ActionTimeline *ret = self->createActionFromJson(arg1);
    int num_ret = olua_push_cppobj(L, ret, "ccs.timeline.ActionTimeline");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_ActionTimelineCache_createActionWithDataBuffer(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::ActionTimelineCache *self = nullptr;
    cocos2d::Data arg1;       /** data */
    std::string arg2;       /** fileName */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.ActionTimelineCache");
    olua_check_cocos2d_Data(L, 2, &arg1);
    olua_check_std_string(L, 3, &arg2);

    // cocostudio::timeline::ActionTimeline *createActionWithDataBuffer(cocos2d::Data data, const std::string &fileName)
    cocostudio::timeline::ActionTimeline *ret = self->createActionWithDataBuffer(arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "ccs.timeline.ActionTimeline");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_ActionTimelineCache_createActionWithFlatBuffersFile(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::ActionTimelineCache *self = nullptr;
    std::string arg1;       /** fileName */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.ActionTimelineCache");
    olua_check_std_string(L, 2, &arg1);

    // cocostudio::timeline::ActionTimeline *createActionWithFlatBuffersFile(const std::string &fileName)
    cocostudio::timeline::ActionTimeline *ret = self->createActionWithFlatBuffersFile(arg1);
    int num_ret = olua_push_cppobj(L, ret, "ccs.timeline.ActionTimeline");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_ActionTimelineCache_createActionWithFlatBuffersForSimulator(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::ActionTimelineCache *self = nullptr;
    std::string arg1;       /** fileName */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.ActionTimelineCache");
    olua_check_std_string(L, 2, &arg1);

    // cocostudio::timeline::ActionTimeline *createActionWithFlatBuffersForSimulator(const std::string &fileName)
    cocostudio::timeline::ActionTimeline *ret = self->createActionWithFlatBuffersForSimulator(arg1);
    int num_ret = olua_push_cppobj(L, ret, "ccs.timeline.ActionTimeline");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_ActionTimelineCache_destroyInstance(lua_State *L)
{
    olua_startinvoke(L);

    // static void destroyInstance()
    cocostudio::timeline::ActionTimelineCache::destroyInstance();

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_timeline_ActionTimelineCache_getInstance(lua_State *L)
{
    olua_startinvoke(L);

    // static cocostudio::timeline::ActionTimelineCache *getInstance()
    cocostudio::timeline::ActionTimelineCache *ret = cocostudio::timeline::ActionTimelineCache::getInstance();
    int num_ret = olua_push_cppobj(L, ret, "ccs.timeline.ActionTimelineCache");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_ActionTimelineCache_init(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::ActionTimelineCache *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.ActionTimelineCache");

    // void init()
    self->init();

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_timeline_ActionTimelineCache_loadAnimationActionWithContent(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::ActionTimelineCache *self = nullptr;
    std::string arg1;       /** fileName */
    std::string arg2;       /** content */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.ActionTimelineCache");
    olua_check_std_string(L, 2, &arg1);
    olua_check_std_string(L, 3, &arg2);

    // cocostudio::timeline::ActionTimeline *loadAnimationActionWithContent(const std::string &fileName, const std::string &content)
    cocostudio::timeline::ActionTimeline *ret = self->loadAnimationActionWithContent(arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "ccs.timeline.ActionTimeline");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_ActionTimelineCache_loadAnimationActionWithFile(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::ActionTimelineCache *self = nullptr;
    std::string arg1;       /** fileName */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.ActionTimelineCache");
    olua_check_std_string(L, 2, &arg1);

    // cocostudio::timeline::ActionTimeline *loadAnimationActionWithFile(const std::string &fileName)
    cocostudio::timeline::ActionTimeline *ret = self->loadAnimationActionWithFile(arg1);
    int num_ret = olua_push_cppobj(L, ret, "ccs.timeline.ActionTimeline");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_ActionTimelineCache_loadAnimationActionWithFlatBuffersFile(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::ActionTimelineCache *self = nullptr;
    std::string arg1;       /** fileName */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.ActionTimelineCache");
    olua_check_std_string(L, 2, &arg1);

    // cocostudio::timeline::ActionTimeline *loadAnimationActionWithFlatBuffersFile(const std::string &fileName)
    cocostudio::timeline::ActionTimeline *ret = self->loadAnimationActionWithFlatBuffersFile(arg1);
    int num_ret = olua_push_cppobj(L, ret, "ccs.timeline.ActionTimeline");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_ActionTimelineCache_loadAnimationWithDataBuffer(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::ActionTimelineCache *self = nullptr;
    cocos2d::Data arg1;       /** data */
    std::string arg2;       /** fileName */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.ActionTimelineCache");
    olua_check_cocos2d_Data(L, 2, &arg1);
    olua_check_std_string(L, 3, &arg2);

    // cocostudio::timeline::ActionTimeline *loadAnimationWithDataBuffer(const cocos2d::Data &data, const std::string &fileName)
    cocostudio::timeline::ActionTimeline *ret = self->loadAnimationWithDataBuffer(arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "ccs.timeline.ActionTimeline");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_ActionTimelineCache_purge(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::ActionTimelineCache *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.ActionTimelineCache");

    // void purge()
    self->purge();

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_timeline_ActionTimelineCache_removeAction(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::ActionTimelineCache *self = nullptr;
    std::string arg1;       /** fileName */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.ActionTimelineCache");
    olua_check_std_string(L, 2, &arg1);

    // void removeAction(const std::string &fileName)
    self->removeAction(arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocostudio_timeline_ActionTimelineCache(lua_State *L)
{
    oluacls_class(L, "ccs.timeline.ActionTimelineCache", nullptr);
    oluacls_func(L, "__olua_move", _cocostudio_timeline_ActionTimelineCache___olua_move);
    oluacls_func(L, "createAction", _cocostudio_timeline_ActionTimelineCache_createAction);
    oluacls_func(L, "createActionFromContent", _cocostudio_timeline_ActionTimelineCache_createActionFromContent);
    oluacls_func(L, "createActionFromJson", _cocostudio_timeline_ActionTimelineCache_createActionFromJson);
    oluacls_func(L, "createActionWithDataBuffer", _cocostudio_timeline_ActionTimelineCache_createActionWithDataBuffer);
    oluacls_func(L, "createActionWithFlatBuffersFile", _cocostudio_timeline_ActionTimelineCache_createActionWithFlatBuffersFile);
    oluacls_func(L, "createActionWithFlatBuffersForSimulator", _cocostudio_timeline_ActionTimelineCache_createActionWithFlatBuffersForSimulator);
    oluacls_func(L, "destroyInstance", _cocostudio_timeline_ActionTimelineCache_destroyInstance);
    oluacls_func(L, "getInstance", _cocostudio_timeline_ActionTimelineCache_getInstance);
    oluacls_func(L, "init", _cocostudio_timeline_ActionTimelineCache_init);
    oluacls_func(L, "loadAnimationActionWithContent", _cocostudio_timeline_ActionTimelineCache_loadAnimationActionWithContent);
    oluacls_func(L, "loadAnimationActionWithFile", _cocostudio_timeline_ActionTimelineCache_loadAnimationActionWithFile);
    oluacls_func(L, "loadAnimationActionWithFlatBuffersFile", _cocostudio_timeline_ActionTimelineCache_loadAnimationActionWithFlatBuffersFile);
    oluacls_func(L, "loadAnimationWithDataBuffer", _cocostudio_timeline_ActionTimelineCache_loadAnimationWithDataBuffer);
    oluacls_func(L, "purge", _cocostudio_timeline_ActionTimelineCache_purge);
    oluacls_func(L, "removeAction", _cocostudio_timeline_ActionTimelineCache_removeAction);
    oluacls_prop(L, "instance", _cocostudio_timeline_ActionTimelineCache_getInstance, nullptr);

    olua_registerluatype<cocostudio::timeline::ActionTimelineCache>(L, "ccs.timeline.ActionTimelineCache");

    return 1;
}

static int _cocostudio_timeline_ActionTimelineData___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocostudio::timeline::ActionTimelineData *)olua_toobj(L, 1, "ccs.timeline.ActionTimelineData");
    olua_push_cppobj(L, self, "ccs.timeline.ActionTimelineData");

    olua_endinvoke(L);

    return 1;
}

static int _cocostudio_timeline_ActionTimelineData_create(lua_State *L)
{
    olua_startinvoke(L);

    lua_Integer arg1 = 0;       /** actionTag */

    olua_check_int(L, 1, &arg1);

    // static cocostudio::timeline::ActionTimelineData *create(int actionTag)
    cocostudio::timeline::ActionTimelineData *ret = cocostudio::timeline::ActionTimelineData::create((int)arg1);
    int num_ret = olua_push_cppobj(L, ret, "ccs.timeline.ActionTimelineData");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_ActionTimelineData_getActionTag(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::ActionTimelineData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.ActionTimelineData");

    // int getActionTag()
    int ret = self->getActionTag();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_ActionTimelineData_init(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::ActionTimelineData *self = nullptr;
    lua_Integer arg1 = 0;       /** actionTag */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.ActionTimelineData");
    olua_check_int(L, 2, &arg1);

    // bool init(int actionTag)
    bool ret = self->init((int)arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_ActionTimelineData_new(lua_State *L)
{
    olua_startinvoke(L);

    // ActionTimelineData()
    cocostudio::timeline::ActionTimelineData *ret = new cocostudio::timeline::ActionTimelineData();
    int num_ret = olua_push_cppobj(L, ret, "ccs.timeline.ActionTimelineData");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_ActionTimelineData_setActionTag(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::ActionTimelineData *self = nullptr;
    lua_Integer arg1 = 0;       /** actionTag */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.ActionTimelineData");
    olua_check_int(L, 2, &arg1);

    // void setActionTag(int actionTag)
    self->setActionTag((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocostudio_timeline_ActionTimelineData(lua_State *L)
{
    oluacls_class(L, "ccs.timeline.ActionTimelineData", "cc.Ref");
    oluacls_func(L, "__olua_move", _cocostudio_timeline_ActionTimelineData___olua_move);
    oluacls_func(L, "create", _cocostudio_timeline_ActionTimelineData_create);
    oluacls_func(L, "getActionTag", _cocostudio_timeline_ActionTimelineData_getActionTag);
    oluacls_func(L, "init", _cocostudio_timeline_ActionTimelineData_init);
    oluacls_func(L, "new", _cocostudio_timeline_ActionTimelineData_new);
    oluacls_func(L, "setActionTag", _cocostudio_timeline_ActionTimelineData_setActionTag);
    oluacls_prop(L, "actionTag", _cocostudio_timeline_ActionTimelineData_getActionTag, _cocostudio_timeline_ActionTimelineData_setActionTag);

    olua_registerluatype<cocostudio::timeline::ActionTimelineData>(L, "ccs.timeline.ActionTimelineData");

    return 1;
}

static int _cocostudio_timeline_ActionTimelineNode___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocostudio::timeline::ActionTimelineNode *)olua_toobj(L, 1, "ccs.timeline.ActionTimelineNode");
    olua_push_cppobj(L, self, "ccs.timeline.ActionTimelineNode");

    olua_endinvoke(L);

    return 1;
}

static int _cocostudio_timeline_ActionTimelineNode_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Node *arg1 = nullptr;       /** root */
    cocostudio::timeline::ActionTimeline *arg2 = nullptr;       /** action */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.Node");
    olua_check_cppobj(L, 2, (void **)&arg2, "ccs.timeline.ActionTimeline");

    // static cocostudio::timeline::ActionTimelineNode *create(cocos2d::Node *root, cocostudio::timeline::ActionTimeline *action)
    cocostudio::timeline::ActionTimelineNode *ret = cocostudio::timeline::ActionTimelineNode::create(arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "ccs.timeline.ActionTimelineNode");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_ActionTimelineNode_getActionTimeline(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::ActionTimelineNode *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.ActionTimelineNode");

    // @addref(actionTimeline ^) cocostudio::timeline::ActionTimeline *getActionTimeline()
    cocostudio::timeline::ActionTimeline *ret = self->getActionTimeline();
    int num_ret = olua_push_cppobj(L, ret, "ccs.timeline.ActionTimeline");

    // insert code after call
    olua_addref(L, 1, "actionTimeline", -1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_ActionTimelineNode_getRoot(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::ActionTimelineNode *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.ActionTimelineNode");

    // @addref(root ^) cocos2d::Node *getRoot()
    cocos2d::Node *ret = self->getRoot();
    int num_ret = olua_push_cppobj(L, ret, "cc.Node");

    // insert code after call
    olua_addref(L, 1, "root", -1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_ActionTimelineNode_init1(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::ActionTimelineNode *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.ActionTimelineNode");

    // @using bool init()
    bool ret = self->init();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_ActionTimelineNode_init2(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::ActionTimelineNode *self = nullptr;
    cocos2d::Node *arg1 = nullptr;       /** root */
    cocostudio::timeline::ActionTimeline *arg2 = nullptr;       /** action */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.ActionTimelineNode");
    olua_check_cppobj(L, 2, (void **)&arg1, "cc.Node");
    olua_check_cppobj(L, 3, (void **)&arg2, "ccs.timeline.ActionTimeline");

    // bool init(cocos2d::Node *root, cocostudio::timeline::ActionTimeline *action)
    bool ret = self->init(arg1, arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_ActionTimelineNode_init(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // @using bool init()
        return _cocostudio_timeline_ActionTimelineNode_init1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_cppobj(L, 2, "cc.Node")) && (olua_is_cppobj(L, 3, "ccs.timeline.ActionTimeline"))) {
            // bool init(cocos2d::Node *root, cocostudio::timeline::ActionTimeline *action)
            return _cocostudio_timeline_ActionTimelineNode_init2(L);
        // }
    }

    luaL_error(L, "method 'cocostudio::timeline::ActionTimelineNode::init' not support '%d' arguments", num_args);

    return 0;
}

static int _cocostudio_timeline_ActionTimelineNode_new(lua_State *L)
{
    olua_startinvoke(L);

    // ActionTimelineNode()
    cocostudio::timeline::ActionTimelineNode *ret = new cocostudio::timeline::ActionTimelineNode();
    int num_ret = olua_push_cppobj(L, ret, "ccs.timeline.ActionTimelineNode");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_ActionTimelineNode_setActionTimeline(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::ActionTimelineNode *self = nullptr;
    cocostudio::timeline::ActionTimeline *arg1 = nullptr;       /** action */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.ActionTimelineNode");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccs.timeline.ActionTimeline");

    // void setActionTimeline(@addref(actionTimeline ^) cocostudio::timeline::ActionTimeline *action)
    self->setActionTimeline(arg1);

    // insert code after call
    olua_addref(L, 1, "actionTimeline", 2, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_timeline_ActionTimelineNode_setRoot(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::ActionTimelineNode *self = nullptr;
    cocos2d::Node *arg1 = nullptr;       /** root */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.ActionTimelineNode");
    olua_check_cppobj(L, 2, (void **)&arg1, "cc.Node");

    // void setRoot(@addref(root ^) cocos2d::Node *root)
    self->setRoot(arg1);

    // insert code after call
    olua_addref(L, 1, "root", 2, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocostudio_timeline_ActionTimelineNode(lua_State *L)
{
    oluacls_class(L, "ccs.timeline.ActionTimelineNode", "cc.Node");
    oluacls_func(L, "__olua_move", _cocostudio_timeline_ActionTimelineNode___olua_move);
    oluacls_func(L, "create", _cocostudio_timeline_ActionTimelineNode_create);
    oluacls_func(L, "getActionTimeline", _cocostudio_timeline_ActionTimelineNode_getActionTimeline);
    oluacls_func(L, "getRoot", _cocostudio_timeline_ActionTimelineNode_getRoot);
    oluacls_func(L, "init", _cocostudio_timeline_ActionTimelineNode_init);
    oluacls_func(L, "new", _cocostudio_timeline_ActionTimelineNode_new);
    oluacls_func(L, "setActionTimeline", _cocostudio_timeline_ActionTimelineNode_setActionTimeline);
    oluacls_func(L, "setRoot", _cocostudio_timeline_ActionTimelineNode_setRoot);
    oluacls_prop(L, "actionTimeline", _cocostudio_timeline_ActionTimelineNode_getActionTimeline, _cocostudio_timeline_ActionTimelineNode_setActionTimeline);
    oluacls_prop(L, "root", _cocostudio_timeline_ActionTimelineNode_getRoot, _cocostudio_timeline_ActionTimelineNode_setRoot);

    olua_registerluatype<cocostudio::timeline::ActionTimelineNode>(L, "ccs.timeline.ActionTimelineNode");

    return 1;
}

static int _cocostudio_timeline_BoneNode___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocostudio::timeline::BoneNode *)olua_toobj(L, 1, "ccs.timeline.BoneNode");
    olua_push_cppobj(L, self, "ccs.timeline.BoneNode");

    olua_endinvoke(L);

    return 1;
}

static int _cocostudio_timeline_BoneNode_addSkin1(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::BoneNode *self = nullptr;
    cocostudio::timeline::SkinNode *arg1 = nullptr;       /** skin */
    bool arg2 = false;       /** display */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.BoneNode");
    olua_check_cppobj(L, 2, (void **)&arg1, "cc.Node");
    olua_check_bool(L, 3, &arg2);

    // void addSkin(@addref(skins |) cocostudio::timeline::SkinNode *skin, bool display)
    self->addSkin(arg1, arg2);

    // insert code after call
    olua_addref(L, 1, "skins", 2, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_timeline_BoneNode_addSkin2(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::BoneNode *self = nullptr;
    cocostudio::timeline::SkinNode *arg1 = nullptr;       /** skin */
    bool arg2 = false;       /** display */
    bool arg3 = false;       /** hideOthers */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.BoneNode");
    olua_check_cppobj(L, 2, (void **)&arg1, "cc.Node");
    olua_check_bool(L, 3, &arg2);
    olua_check_bool(L, 4, &arg3);

    // void addSkin(@addref(skins |) cocostudio::timeline::SkinNode *skin, bool display, bool hideOthers)
    self->addSkin(arg1, arg2, arg3);

    // insert code after call
    olua_addref(L, 1, "skins", 2, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_timeline_BoneNode_addSkin(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 2) {
        // if ((olua_is_cppobj(L, 2, "cc.Node")) && (olua_is_bool(L, 3))) {
            // void addSkin(@addref(skins |) cocostudio::timeline::SkinNode *skin, bool display)
            return _cocostudio_timeline_BoneNode_addSkin1(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_cppobj(L, 2, "cc.Node")) && (olua_is_bool(L, 3)) && (olua_is_bool(L, 4))) {
            // void addSkin(@addref(skins |) cocostudio::timeline::SkinNode *skin, bool display, bool hideOthers)
            return _cocostudio_timeline_BoneNode_addSkin2(L);
        // }
    }

    luaL_error(L, "method 'cocostudio::timeline::BoneNode::addSkin' not support '%d' arguments", num_args);

    return 0;
}

static int _cocostudio_timeline_BoneNode_create1(lua_State *L)
{
    olua_startinvoke(L);

    // static cocostudio::timeline::BoneNode *create()
    cocostudio::timeline::BoneNode *ret = cocostudio::timeline::BoneNode::create();
    int num_ret = olua_push_cppobj(L, ret, "ccs.timeline.BoneNode");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_BoneNode_create2(lua_State *L)
{
    olua_startinvoke(L);

    lua_Integer arg1 = 0;       /** length */

    olua_check_int(L, 1, &arg1);

    // static cocostudio::timeline::BoneNode *create(int length)
    cocostudio::timeline::BoneNode *ret = cocostudio::timeline::BoneNode::create((int)arg1);
    int num_ret = olua_push_cppobj(L, ret, "ccs.timeline.BoneNode");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_BoneNode_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // static cocostudio::timeline::BoneNode *create()
        return _cocostudio_timeline_BoneNode_create1(L);
    }

    if (num_args == 1) {
        // if ((olua_is_int(L, 1))) {
            // static cocostudio::timeline::BoneNode *create(int length)
            return _cocostudio_timeline_BoneNode_create2(L);
        // }
    }

    luaL_error(L, "method 'cocostudio::timeline::BoneNode::create' not support '%d' arguments", num_args);

    return 0;
}

static int _cocostudio_timeline_BoneNode_displaySkin1(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::BoneNode *self = nullptr;
    cocostudio::timeline::SkinNode *arg1 = nullptr;       /** skin */
    bool arg2 = false;       /** hideOthers */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.BoneNode");
    olua_check_cppobj(L, 2, (void **)&arg1, "cc.Node");
    olua_check_bool(L, 3, &arg2);

    // void displaySkin(cocostudio::timeline::SkinNode *skin, bool hideOthers)
    self->displaySkin(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_timeline_BoneNode_displaySkin2(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::BoneNode *self = nullptr;
    std::string arg1;       /** skinName */
    bool arg2 = false;       /** hideOthers */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.BoneNode");
    olua_check_std_string(L, 2, &arg1);
    olua_check_bool(L, 3, &arg2);

    // void displaySkin(const std::string &skinName, bool hideOthers)
    self->displaySkin(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_timeline_BoneNode_displaySkin(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 2) {
        if ((olua_is_cppobj(L, 2, "cc.Node")) && (olua_is_bool(L, 3))) {
            // void displaySkin(cocostudio::timeline::SkinNode *skin, bool hideOthers)
            return _cocostudio_timeline_BoneNode_displaySkin1(L);
        }

        // if ((olua_is_std_string(L, 2)) && (olua_is_bool(L, 3))) {
            // void displaySkin(const std::string &skinName, bool hideOthers)
            return _cocostudio_timeline_BoneNode_displaySkin2(L);
        // }
    }

    luaL_error(L, "method 'cocostudio::timeline::BoneNode::displaySkin' not support '%d' arguments", num_args);

    return 0;
}

static int _cocostudio_timeline_BoneNode_getAllSubBones(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::BoneNode *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.BoneNode");

    // @addref(subBones |) cocos2d::Vector<BoneNode *> getAllSubBones()
    cocos2d::Vector<cocostudio::timeline::BoneNode *> ret = self->getAllSubBones();
    int num_ret = olua_push_cocos2d_Vector<cocostudio::timeline::BoneNode *>(L, &ret, [L](cocostudio::timeline::BoneNode *value) {
        olua_push_cppobj(L, value, "ccs.timeline.BoneNode");
    });

    // insert code after call
    olua_addref(L, 1, "subBones", -1, OLUA_MODE_MULTIPLE | OLUA_FLAG_TABLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_BoneNode_getAllSubSkins(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::BoneNode *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.BoneNode");

    // @addref(subSkins |) cocos2d::Vector<SkinNode *> getAllSubSkins()
    cocos2d::Vector<cocostudio::timeline::SkinNode *> ret = self->getAllSubSkins();
    int num_ret = olua_push_cocos2d_Vector<cocostudio::timeline::SkinNode *>(L, &ret, [L](cocostudio::timeline::SkinNode *value) {
        olua_push_cppobj(L, value, "cc.Node");
    });

    // insert code after call
    olua_addref(L, 1, "subSkins", -1, OLUA_MODE_MULTIPLE | OLUA_FLAG_TABLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_BoneNode_getBlendFunc(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::BoneNode *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.BoneNode");

    // const cocos2d::BlendFunc &getBlendFunc()
    const cocos2d::BlendFunc &ret = self->getBlendFunc();
    int num_ret = olua_push_cocos2d_BlendFunc(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_BoneNode_getChildBones(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::BoneNode *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.BoneNode");

    // @addref(bones |) const cocos2d::Vector<BoneNode *> &getChildBones()
    const cocos2d::Vector<cocostudio::timeline::BoneNode *> &ret = self->getChildBones();
    int num_ret = olua_push_cocos2d_Vector<cocostudio::timeline::BoneNode *>(L, &ret, [L](cocostudio::timeline::BoneNode *value) {
        olua_push_cppobj(L, value, "ccs.timeline.BoneNode");
    });

    // insert code after call
    olua_addref(L, 1, "bones", -1, OLUA_MODE_MULTIPLE | OLUA_FLAG_TABLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_BoneNode_getDebugDrawColor(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::BoneNode *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.BoneNode");

    // cocos2d::Color4F getDebugDrawColor()
    cocos2d::Color4F ret = self->getDebugDrawColor();
    int num_ret = olua_push_cocos2d_Color4F(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_BoneNode_getDebugDrawLength(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::BoneNode *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.BoneNode");

    // float getDebugDrawLength()
    float ret = self->getDebugDrawLength();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_BoneNode_getDebugDrawWidth(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::BoneNode *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.BoneNode");

    // float getDebugDrawWidth()
    float ret = self->getDebugDrawWidth();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_BoneNode_getRootSkeletonNode(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::BoneNode *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.BoneNode");

    // @addref(rootSkeletonNode ^) cocostudio::timeline::SkeletonNode *getRootSkeletonNode()
    cocostudio::timeline::SkeletonNode *ret = self->getRootSkeletonNode();
    int num_ret = olua_push_cppobj(L, ret, "ccs.timeline.SkeletonNode");

    // insert code after call
    olua_addref(L, 1, "rootSkeletonNode", -1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_BoneNode_getSkins(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::BoneNode *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.BoneNode");

    // @addref(skins |) const cocos2d::Vector<SkinNode *> &getSkins()
    const cocos2d::Vector<cocostudio::timeline::SkinNode *> &ret = self->getSkins();
    int num_ret = olua_push_cocos2d_Vector<cocostudio::timeline::SkinNode *>(L, &ret, [L](cocostudio::timeline::SkinNode *value) {
        olua_push_cppobj(L, value, "cc.Node");
    });

    // insert code after call
    olua_addref(L, 1, "skins", -1, OLUA_MODE_MULTIPLE | OLUA_FLAG_TABLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_BoneNode_getVisibleSkins(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::BoneNode *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.BoneNode");

    // @addref(skins |) cocos2d::Vector<SkinNode *> getVisibleSkins()
    cocos2d::Vector<cocostudio::timeline::SkinNode *> ret = self->getVisibleSkins();
    int num_ret = olua_push_cocos2d_Vector<cocostudio::timeline::SkinNode *>(L, &ret, [L](cocostudio::timeline::SkinNode *value) {
        olua_push_cppobj(L, value, "cc.Node");
    });

    // insert code after call
    olua_addref(L, 1, "skins", -1, OLUA_MODE_MULTIPLE | OLUA_FLAG_TABLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_BoneNode_getVisibleSkinsRect(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::BoneNode *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.BoneNode");

    // cocos2d::Rect getVisibleSkinsRect()
    cocos2d::Rect ret = self->getVisibleSkinsRect();
    int num_ret = olua_push_cocos2d_Rect(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_BoneNode_isDebugDrawEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::BoneNode *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.BoneNode");

    // bool isDebugDrawEnabled()
    bool ret = self->isDebugDrawEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_BoneNode_new(lua_State *L)
{
    olua_startinvoke(L);

    // BoneNode()
    cocostudio::timeline::BoneNode *ret = new cocostudio::timeline::BoneNode();
    int num_ret = olua_push_cppobj(L, ret, "ccs.timeline.BoneNode");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_BoneNode_setBlendFunc(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::BoneNode *self = nullptr;
    cocos2d::BlendFunc arg1;       /** blendFunc */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.BoneNode");
    olua_check_cocos2d_BlendFunc(L, 2, &arg1);

    // void setBlendFunc(const cocos2d::BlendFunc &blendFunc)
    self->setBlendFunc(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_timeline_BoneNode_setDebugDrawColor(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::BoneNode *self = nullptr;
    cocos2d::Color4F arg1;       /** color */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.BoneNode");
    olua_check_cocos2d_Color4F(L, 2, &arg1);

    // void setDebugDrawColor(const cocos2d::Color4F &color)
    self->setDebugDrawColor(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_timeline_BoneNode_setDebugDrawEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::BoneNode *self = nullptr;
    bool arg1 = false;       /** isDebugDraw */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.BoneNode");
    olua_check_bool(L, 2, &arg1);

    // void setDebugDrawEnabled(bool isDebugDraw)
    self->setDebugDrawEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_timeline_BoneNode_setDebugDrawLength(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::BoneNode *self = nullptr;
    lua_Number arg1 = 0;       /** length */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.BoneNode");
    olua_check_number(L, 2, &arg1);

    // void setDebugDrawLength(float length)
    self->setDebugDrawLength((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_timeline_BoneNode_setDebugDrawWidth(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::BoneNode *self = nullptr;
    lua_Number arg1 = 0;       /** width */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.BoneNode");
    olua_check_number(L, 2, &arg1);

    // void setDebugDrawWidth(float width)
    self->setDebugDrawWidth((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_timeline_BoneNode_setLocalZOrder(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::BoneNode *self = nullptr;
    lua_Integer arg1 = 0;       /** localZOrder */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.BoneNode");
    olua_check_int(L, 2, &arg1);

    // void setLocalZOrder(int localZOrder)
    self->setLocalZOrder((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocostudio_timeline_BoneNode(lua_State *L)
{
    oluacls_class(L, "ccs.timeline.BoneNode", "cc.Node");
    oluacls_func(L, "__olua_move", _cocostudio_timeline_BoneNode___olua_move);
    oluacls_func(L, "addSkin", _cocostudio_timeline_BoneNode_addSkin);
    oluacls_func(L, "create", _cocostudio_timeline_BoneNode_create);
    oluacls_func(L, "displaySkin", _cocostudio_timeline_BoneNode_displaySkin);
    oluacls_func(L, "getAllSubBones", _cocostudio_timeline_BoneNode_getAllSubBones);
    oluacls_func(L, "getAllSubSkins", _cocostudio_timeline_BoneNode_getAllSubSkins);
    oluacls_func(L, "getBlendFunc", _cocostudio_timeline_BoneNode_getBlendFunc);
    oluacls_func(L, "getChildBones", _cocostudio_timeline_BoneNode_getChildBones);
    oluacls_func(L, "getDebugDrawColor", _cocostudio_timeline_BoneNode_getDebugDrawColor);
    oluacls_func(L, "getDebugDrawLength", _cocostudio_timeline_BoneNode_getDebugDrawLength);
    oluacls_func(L, "getDebugDrawWidth", _cocostudio_timeline_BoneNode_getDebugDrawWidth);
    oluacls_func(L, "getRootSkeletonNode", _cocostudio_timeline_BoneNode_getRootSkeletonNode);
    oluacls_func(L, "getSkins", _cocostudio_timeline_BoneNode_getSkins);
    oluacls_func(L, "getVisibleSkins", _cocostudio_timeline_BoneNode_getVisibleSkins);
    oluacls_func(L, "getVisibleSkinsRect", _cocostudio_timeline_BoneNode_getVisibleSkinsRect);
    oluacls_func(L, "isDebugDrawEnabled", _cocostudio_timeline_BoneNode_isDebugDrawEnabled);
    oluacls_func(L, "new", _cocostudio_timeline_BoneNode_new);
    oluacls_func(L, "setBlendFunc", _cocostudio_timeline_BoneNode_setBlendFunc);
    oluacls_func(L, "setDebugDrawColor", _cocostudio_timeline_BoneNode_setDebugDrawColor);
    oluacls_func(L, "setDebugDrawEnabled", _cocostudio_timeline_BoneNode_setDebugDrawEnabled);
    oluacls_func(L, "setDebugDrawLength", _cocostudio_timeline_BoneNode_setDebugDrawLength);
    oluacls_func(L, "setDebugDrawWidth", _cocostudio_timeline_BoneNode_setDebugDrawWidth);
    oluacls_func(L, "setLocalZOrder", _cocostudio_timeline_BoneNode_setLocalZOrder);
    oluacls_prop(L, "allSubBones", _cocostudio_timeline_BoneNode_getAllSubBones, nullptr);
    oluacls_prop(L, "allSubSkins", _cocostudio_timeline_BoneNode_getAllSubSkins, nullptr);
    oluacls_prop(L, "blendFunc", _cocostudio_timeline_BoneNode_getBlendFunc, _cocostudio_timeline_BoneNode_setBlendFunc);
    oluacls_prop(L, "childBones", _cocostudio_timeline_BoneNode_getChildBones, nullptr);
    oluacls_prop(L, "debugDrawColor", _cocostudio_timeline_BoneNode_getDebugDrawColor, _cocostudio_timeline_BoneNode_setDebugDrawColor);
    oluacls_prop(L, "debugDrawEnabled", _cocostudio_timeline_BoneNode_isDebugDrawEnabled, _cocostudio_timeline_BoneNode_setDebugDrawEnabled);
    oluacls_prop(L, "debugDrawLength", _cocostudio_timeline_BoneNode_getDebugDrawLength, _cocostudio_timeline_BoneNode_setDebugDrawLength);
    oluacls_prop(L, "debugDrawWidth", _cocostudio_timeline_BoneNode_getDebugDrawWidth, _cocostudio_timeline_BoneNode_setDebugDrawWidth);
    oluacls_prop(L, "rootSkeletonNode", _cocostudio_timeline_BoneNode_getRootSkeletonNode, nullptr);
    oluacls_prop(L, "skins", _cocostudio_timeline_BoneNode_getSkins, nullptr);
    oluacls_prop(L, "visibleSkins", _cocostudio_timeline_BoneNode_getVisibleSkins, nullptr);
    oluacls_prop(L, "visibleSkinsRect", _cocostudio_timeline_BoneNode_getVisibleSkinsRect, nullptr);

    olua_registerluatype<cocostudio::timeline::BoneNode>(L, "ccs.timeline.BoneNode");

    return 1;
}

static int _cocostudio_timeline_SkeletonNode___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocostudio::timeline::SkeletonNode *)olua_toobj(L, 1, "ccs.timeline.SkeletonNode");
    olua_push_cppobj(L, self, "ccs.timeline.SkeletonNode");

    olua_endinvoke(L);

    return 1;
}

static int _cocostudio_timeline_SkeletonNode_addSkinGroup(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::SkeletonNode *self = nullptr;
    std::string arg1;       /** groupName */
    std::map<std::string, std::string> arg2;       /** boneSkinNameMap */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.SkeletonNode");
    olua_check_std_string(L, 2, &arg1);
    olua_check_std_map<std::string, std::string>(L, 3, &arg2, [L](std::string *arg1, std::string *arg2) {
        olua_check_std_string(L, -1, arg1);
        olua_check_std_string(L, -2, arg2);
    });

    // void addSkinGroup(std::string groupName, std::map<std::string, std::string> boneSkinNameMap)
    self->addSkinGroup(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_timeline_SkeletonNode_changeSkins1(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::SkeletonNode *self = nullptr;
    std::map<std::string, std::string> arg1;       /** boneSkinNameMap */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.SkeletonNode");
    olua_check_std_map<std::string, std::string>(L, 2, &arg1, [L](std::string *arg1, std::string *arg2) {
        olua_check_std_string(L, -1, arg1);
        olua_check_std_string(L, -2, arg2);
    });

    // void changeSkins(const std::map<std::string, std::string> &boneSkinNameMap)
    self->changeSkins(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_timeline_SkeletonNode_changeSkins2(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::SkeletonNode *self = nullptr;
    std::string arg1;       /** skinGroupName */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.SkeletonNode");
    olua_check_std_string(L, 2, &arg1);

    // void changeSkins(const std::string &skinGroupName)
    self->changeSkins(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_timeline_SkeletonNode_changeSkins(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        if ((olua_is_std_map(L, 2))) {
            // void changeSkins(const std::map<std::string, std::string> &boneSkinNameMap)
            return _cocostudio_timeline_SkeletonNode_changeSkins1(L);
        }

        // if ((olua_is_std_string(L, 2))) {
            // void changeSkins(const std::string &skinGroupName)
            return _cocostudio_timeline_SkeletonNode_changeSkins2(L);
        // }
    }

    luaL_error(L, "method 'cocostudio::timeline::SkeletonNode::changeSkins' not support '%d' arguments", num_args);

    return 0;
}

static int _cocostudio_timeline_SkeletonNode_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cocostudio::timeline::SkeletonNode *create()
    cocostudio::timeline::SkeletonNode *ret = cocostudio::timeline::SkeletonNode::create();
    int num_ret = olua_push_cppobj(L, ret, "ccs.timeline.SkeletonNode");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_SkeletonNode_getAllSubBonesMap(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::SkeletonNode *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.SkeletonNode");

    // @addref(boneNodes |) const cocos2d::Map<std::string, BoneNode *> &getAllSubBonesMap()
    const cocos2d::Map<std::string, cocostudio::timeline::BoneNode *> &ret = self->getAllSubBonesMap();
    int num_ret = olua_push_cocos2d_Map<std::string, cocostudio::timeline::BoneNode *>(L, &ret, [L](std::string arg1, cocostudio::timeline::BoneNode *arg2) {
        olua_push_std_string(L, (std::string)arg1);
        olua_push_cppobj(L, arg2, "ccs.timeline.BoneNode");
    });

    // insert code after call
    olua_addref(L, 1, "boneNodes", -1, OLUA_MODE_MULTIPLE | OLUA_FLAG_TABLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_SkeletonNode_getBoneNode(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::SkeletonNode *self = nullptr;
    std::string arg1;       /** boneName */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.SkeletonNode");
    olua_check_std_string(L, 2, &arg1);

    // @addref(boneNodes |) cocostudio::timeline::BoneNode *getBoneNode(const std::string &boneName)
    cocostudio::timeline::BoneNode *ret = self->getBoneNode(arg1);
    int num_ret = olua_push_cppobj(L, ret, "ccs.timeline.BoneNode");

    // insert code after call
    olua_addref(L, 1, "boneNodes", -1, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_SkeletonNode_new(lua_State *L)
{
    olua_startinvoke(L);

    // SkeletonNode()
    cocostudio::timeline::SkeletonNode *ret = new cocostudio::timeline::SkeletonNode();
    int num_ret = olua_push_cppobj(L, ret, "ccs.timeline.SkeletonNode");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocostudio_timeline_SkeletonNode(lua_State *L)
{
    oluacls_class(L, "ccs.timeline.SkeletonNode", "ccs.timeline.BoneNode");
    oluacls_func(L, "__olua_move", _cocostudio_timeline_SkeletonNode___olua_move);
    oluacls_func(L, "addSkinGroup", _cocostudio_timeline_SkeletonNode_addSkinGroup);
    oluacls_func(L, "changeSkins", _cocostudio_timeline_SkeletonNode_changeSkins);
    oluacls_func(L, "create", _cocostudio_timeline_SkeletonNode_create);
    oluacls_func(L, "getAllSubBonesMap", _cocostudio_timeline_SkeletonNode_getAllSubBonesMap);
    oluacls_func(L, "getBoneNode", _cocostudio_timeline_SkeletonNode_getBoneNode);
    oluacls_func(L, "new", _cocostudio_timeline_SkeletonNode_new);
    oluacls_prop(L, "allSubBonesMap", _cocostudio_timeline_SkeletonNode_getAllSubBonesMap, nullptr);

    olua_registerluatype<cocostudio::timeline::SkeletonNode>(L, "ccs.timeline.SkeletonNode");

    return 1;
}

static int _cocostudio_timeline_Timeline___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocostudio::timeline::Timeline *)olua_toobj(L, 1, "ccs.timeline.Timeline");
    olua_push_cppobj(L, self, "ccs.timeline.Timeline");

    olua_endinvoke(L);

    return 1;
}

static int _cocostudio_timeline_Timeline_addFrame(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::Timeline *self = nullptr;
    cocostudio::timeline::Frame *arg1 = nullptr;       /** frame */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.Timeline");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccs.timeline.Frame");

    // void addFrame(@addref(frames |) cocostudio::timeline::Frame *frame)
    self->addFrame(arg1);

    // insert code after call
    olua_addref(L, 1, "frames", 2, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_timeline_Timeline_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::Timeline *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.Timeline");

    // cocostudio::timeline::Timeline *clone()
    cocostudio::timeline::Timeline *ret = self->clone();
    int num_ret = olua_push_cppobj(L, ret, "ccs.timeline.Timeline");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_Timeline_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cocostudio::timeline::Timeline *create()
    cocostudio::timeline::Timeline *ret = cocostudio::timeline::Timeline::create();
    int num_ret = olua_push_cppobj(L, ret, "ccs.timeline.Timeline");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_Timeline_getActionTag(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::Timeline *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.Timeline");

    // int getActionTag()
    int ret = self->getActionTag();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_Timeline_getActionTimeline(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::Timeline *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.Timeline");

    // @addref(actionTimeline ^) cocostudio::timeline::ActionTimeline *getActionTimeline()
    cocostudio::timeline::ActionTimeline *ret = self->getActionTimeline();
    int num_ret = olua_push_cppobj(L, ret, "ccs.timeline.ActionTimeline");

    // insert code after call
    olua_addref(L, 1, "actionTimeline", -1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_Timeline_getFrames(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::Timeline *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.Timeline");

    // @addref(frames |) const cocos2d::Vector<Frame *> &getFrames()
    const cocos2d::Vector<cocostudio::timeline::Frame *> &ret = self->getFrames();
    int num_ret = olua_push_cocos2d_Vector<cocostudio::timeline::Frame *>(L, &ret, [L](cocostudio::timeline::Frame *value) {
        olua_push_cppobj(L, value, "ccs.timeline.Frame");
    });

    // insert code after call
    olua_addref(L, 1, "frames", -1, OLUA_MODE_MULTIPLE | OLUA_FLAG_TABLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_Timeline_getNode(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::Timeline *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.Timeline");

    // @addref(node ^) cocos2d::Node *getNode()
    cocos2d::Node *ret = self->getNode();
    int num_ret = olua_push_cppobj(L, ret, "cc.Node");

    // insert code after call
    olua_addref(L, 1, "node", -1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_Timeline_gotoFrame(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::Timeline *self = nullptr;
    lua_Integer arg1 = 0;       /** frameIndex */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.Timeline");
    olua_check_int(L, 2, &arg1);

    // void gotoFrame(int frameIndex)
    self->gotoFrame((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_timeline_Timeline_insertFrame(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::Timeline *self = nullptr;
    cocostudio::timeline::Frame *arg1 = nullptr;       /** frame */
    lua_Integer arg2 = 0;       /** index */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.Timeline");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccs.timeline.Frame");
    olua_check_int(L, 3, &arg2);

    // void insertFrame(@addref(frames |) cocostudio::timeline::Frame *frame, int index)
    self->insertFrame(arg1, (int)arg2);

    // insert code after call
    olua_addref(L, 1, "frames", 2, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_timeline_Timeline_new(lua_State *L)
{
    olua_startinvoke(L);

    // Timeline()
    cocostudio::timeline::Timeline *ret = new cocostudio::timeline::Timeline();
    int num_ret = olua_push_cppobj(L, ret, "ccs.timeline.Timeline");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_Timeline_removeFrame(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::Timeline *self = nullptr;
    cocostudio::timeline::Frame *arg1 = nullptr;       /** frame */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.Timeline");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccs.timeline.Frame");

    // void removeFrame(@delref(frames |) cocostudio::timeline::Frame *frame)
    self->removeFrame(arg1);

    // insert code after call
    olua_delref(L, 1, "frames", 2, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_timeline_Timeline_setActionTag(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::Timeline *self = nullptr;
    lua_Integer arg1 = 0;       /** tag */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.Timeline");
    olua_check_int(L, 2, &arg1);

    // void setActionTag(int tag)
    self->setActionTag((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_timeline_Timeline_setActionTimeline(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::Timeline *self = nullptr;
    cocostudio::timeline::ActionTimeline *arg1 = nullptr;       /** action */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.Timeline");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccs.timeline.ActionTimeline");

    // void setActionTimeline(@addref(actionTimeline ^) cocostudio::timeline::ActionTimeline *action)
    self->setActionTimeline(arg1);

    // insert code after call
    olua_addref(L, 1, "actionTimeline", 2, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_timeline_Timeline_setNode(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::Timeline *self = nullptr;
    cocos2d::Node *arg1 = nullptr;       /** node */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.Timeline");
    olua_check_cppobj(L, 2, (void **)&arg1, "cc.Node");

    // void setNode(@addref(node ^) cocos2d::Node *node)
    self->setNode(arg1);

    // insert code after call
    olua_addref(L, 1, "node", 2, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_timeline_Timeline_stepToFrame(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::Timeline *self = nullptr;
    lua_Integer arg1 = 0;       /** frameIndex */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.Timeline");
    olua_check_int(L, 2, &arg1);

    // void stepToFrame(int frameIndex)
    self->stepToFrame((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocostudio_timeline_Timeline(lua_State *L)
{
    oluacls_class(L, "ccs.timeline.Timeline", "cc.Ref");
    oluacls_func(L, "__olua_move", _cocostudio_timeline_Timeline___olua_move);
    oluacls_func(L, "addFrame", _cocostudio_timeline_Timeline_addFrame);
    oluacls_func(L, "clone", _cocostudio_timeline_Timeline_clone);
    oluacls_func(L, "create", _cocostudio_timeline_Timeline_create);
    oluacls_func(L, "getActionTag", _cocostudio_timeline_Timeline_getActionTag);
    oluacls_func(L, "getActionTimeline", _cocostudio_timeline_Timeline_getActionTimeline);
    oluacls_func(L, "getFrames", _cocostudio_timeline_Timeline_getFrames);
    oluacls_func(L, "getNode", _cocostudio_timeline_Timeline_getNode);
    oluacls_func(L, "gotoFrame", _cocostudio_timeline_Timeline_gotoFrame);
    oluacls_func(L, "insertFrame", _cocostudio_timeline_Timeline_insertFrame);
    oluacls_func(L, "new", _cocostudio_timeline_Timeline_new);
    oluacls_func(L, "removeFrame", _cocostudio_timeline_Timeline_removeFrame);
    oluacls_func(L, "setActionTag", _cocostudio_timeline_Timeline_setActionTag);
    oluacls_func(L, "setActionTimeline", _cocostudio_timeline_Timeline_setActionTimeline);
    oluacls_func(L, "setNode", _cocostudio_timeline_Timeline_setNode);
    oluacls_func(L, "stepToFrame", _cocostudio_timeline_Timeline_stepToFrame);
    oluacls_prop(L, "actionTag", _cocostudio_timeline_Timeline_getActionTag, _cocostudio_timeline_Timeline_setActionTag);
    oluacls_prop(L, "actionTimeline", _cocostudio_timeline_Timeline_getActionTimeline, _cocostudio_timeline_Timeline_setActionTimeline);
    oluacls_prop(L, "frames", _cocostudio_timeline_Timeline_getFrames, nullptr);
    oluacls_prop(L, "node", _cocostudio_timeline_Timeline_getNode, _cocostudio_timeline_Timeline_setNode);

    olua_registerluatype<cocostudio::timeline::Timeline>(L, "ccs.timeline.Timeline");

    return 1;
}

static int _cocostudio_timeline_ActionTimeline_IsAnimationInfoExists(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::ActionTimeline *self = nullptr;
    std::string arg1;       /** animationName */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.ActionTimeline");
    olua_check_std_string(L, 2, &arg1);

    // bool IsAnimationInfoExists(const std::string &animationName)
    bool ret = self->IsAnimationInfoExists(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_ActionTimeline___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocostudio::timeline::ActionTimeline *)olua_toobj(L, 1, "ccs.timeline.ActionTimeline");
    olua_push_cppobj(L, self, "ccs.timeline.ActionTimeline");

    olua_endinvoke(L);

    return 1;
}

static int _cocostudio_timeline_ActionTimeline_addAnimationInfo(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::ActionTimeline *self = nullptr;
    cocostudio::timeline::AnimationInfo arg1;       /** animationInfo */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.ActionTimeline");
    olua_check_cocostudio_timeline_AnimationInfo(L, 2, &arg1);

    // insert code before call
    if (olua_getfield(L, 2, "clipEndCallBack") == LUA_TFUNCTION) {
        void *cb_store = (void *)self;
        std::string cb_tag = makeFrameEndCallbackTag(arg1.endIndex, arg1.name);
        std::string cb_name = olua_setcallback(L, cb_store, -1, cb_tag.c_str(), OLUA_TAG_REPLACE);
        lua_Integer cb_ctx = olua_context(L);
        arg1.clipEndCallBack = [cb_store, cb_name, cb_ctx]() {
            lua_State *L = olua_mainthread(NULL);
            olua_checkhostthread();

            if (L != NULL && olua_context(L) == cb_ctx) {
                int top = lua_gettop(L);

                olua_callback(L, cb_store, cb_name.c_str(), 0);

                lua_settop(L, top);
            }
        };
    }

    // void addAnimationInfo(const cocostudio::timeline::AnimationInfo &animationInfo)
    self->addAnimationInfo(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_timeline_ActionTimeline_addFrameEndCallFunc(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::ActionTimeline *self = nullptr;
    lua_Integer arg1 = 0;       /** frameIndex */
    std::string arg2;       /** funcKey */
    std::function<void()> arg3;       /** func */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.ActionTimeline");
    olua_check_int(L, 2, &arg1);
    olua_check_std_string(L, 3, &arg2);
    olua_check_std_function(L, 4, &arg3);

    void *cb_store = (void *)self;
    std::string cb_tag = makeFrameEndCallbackTag(arg1, arg2);
    std::string cb_name = olua_setcallback(L, cb_store,  4, cb_tag.c_str(), OLUA_TAG_REPLACE);
    lua_Integer cb_ctx = olua_context(L);
    arg3 = [cb_store, cb_name, cb_ctx]() {
        lua_State *L = olua_mainthread(NULL);
        olua_checkhostthread();

        if (L != NULL && olua_context(L) == cb_ctx) {
            int top = lua_gettop(L);

            olua_callback(L, cb_store, cb_name.c_str(), 0);

            lua_settop(L, top);
        }
    };

    // void addFrameEndCallFunc(int frameIndex, const std::string &funcKey, @local std::function<void ()> func)
    self->addFrameEndCallFunc((int)arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_timeline_ActionTimeline_addTimeline(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::ActionTimeline *self = nullptr;
    cocostudio::timeline::Timeline *arg1 = nullptr;       /** timeline */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.ActionTimeline");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccs.timeline.Timeline");

    // void addTimeline(@addref(timelines |) cocostudio::timeline::Timeline *timeline)
    self->addTimeline(arg1);

    // insert code after call
    olua_addref(L, 1, "timelines", 2, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_timeline_ActionTimeline_clearFrameEndCallFuncs(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::ActionTimeline *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.ActionTimeline");

    std::string cb_tag = makeFrameEndCallbackTag(-1, "");
    void *cb_store = (void *)self;
    olua_removecallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_SUBSTARTWITH);

    // void clearFrameEndCallFuncs()
    self->clearFrameEndCallFuncs();

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_timeline_ActionTimeline_clearFrameEventCallFunc(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::ActionTimeline *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.ActionTimeline");

    std::string cb_tag = "frameEventCallFunc";
    void *cb_store = (void *)self;
    olua_removecallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_SUBSTARTWITH);

    // void clearFrameEventCallFunc()
    self->clearFrameEventCallFunc();

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_timeline_ActionTimeline_clearLastFrameCallFunc(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::ActionTimeline *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.ActionTimeline");

    std::string cb_tag = "lastFrameCallFunc";
    void *cb_store = (void *)self;
    olua_removecallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_SUBSTARTWITH);

    // void clearLastFrameCallFunc()
    self->clearLastFrameCallFunc();

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_timeline_ActionTimeline_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cocostudio::timeline::ActionTimeline *create()
    cocostudio::timeline::ActionTimeline *ret = cocostudio::timeline::ActionTimeline::create();
    int num_ret = olua_push_cppobj(L, ret, "ccs.timeline.ActionTimeline");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_ActionTimeline_getAnimationInfo(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::ActionTimeline *self = nullptr;
    std::string arg1;       /** animationName */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.ActionTimeline");
    olua_check_std_string(L, 2, &arg1);

    // const cocostudio::timeline::AnimationInfo &getAnimationInfo(const std::string &animationName)
    const cocostudio::timeline::AnimationInfo &ret = self->getAnimationInfo(arg1);
    int num_ret = olua_push_cocostudio_timeline_AnimationInfo(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_ActionTimeline_getCurrentFrame(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::ActionTimeline *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.ActionTimeline");

    // int getCurrentFrame()
    int ret = self->getCurrentFrame();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_ActionTimeline_getDuration(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::ActionTimeline *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.ActionTimeline");

    // int getDuration()
    int ret = self->getDuration();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_ActionTimeline_getEndFrame(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::ActionTimeline *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.ActionTimeline");

    // int getEndFrame()
    int ret = self->getEndFrame();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_ActionTimeline_getStartFrame(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::ActionTimeline *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.ActionTimeline");

    // int getStartFrame()
    int ret = self->getStartFrame();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_ActionTimeline_getTimeSpeed(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::ActionTimeline *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.ActionTimeline");

    // float getTimeSpeed()
    float ret = self->getTimeSpeed();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_ActionTimeline_getTimelines(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::ActionTimeline *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.ActionTimeline");

    // @addref(timelines |) const cocos2d::Vector<Timeline *> &getTimelines()
    const cocos2d::Vector<cocostudio::timeline::Timeline *> &ret = self->getTimelines();
    int num_ret = olua_push_cocos2d_Vector<cocostudio::timeline::Timeline *>(L, &ret, [L](cocostudio::timeline::Timeline *value) {
        olua_push_cppobj(L, value, "ccs.timeline.Timeline");
    });

    // insert code after call
    olua_addref(L, 1, "timelines", -1, OLUA_MODE_MULTIPLE | OLUA_FLAG_TABLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_ActionTimeline_gotoFrameAndPause(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::ActionTimeline *self = nullptr;
    lua_Integer arg1 = 0;       /** startIndex */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.ActionTimeline");
    olua_check_int(L, 2, &arg1);

    // void gotoFrameAndPause(int startIndex)
    self->gotoFrameAndPause((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_timeline_ActionTimeline_gotoFrameAndPlay1(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::ActionTimeline *self = nullptr;
    lua_Integer arg1 = 0;       /** startIndex */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.ActionTimeline");
    olua_check_int(L, 2, &arg1);

    // void gotoFrameAndPlay(int startIndex)
    self->gotoFrameAndPlay((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_timeline_ActionTimeline_gotoFrameAndPlay2(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::ActionTimeline *self = nullptr;
    lua_Integer arg1 = 0;       /** startIndex */
    bool arg2 = false;       /** loop */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.ActionTimeline");
    olua_check_int(L, 2, &arg1);
    olua_check_bool(L, 3, &arg2);

    // void gotoFrameAndPlay(int startIndex, bool loop)
    self->gotoFrameAndPlay((int)arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_timeline_ActionTimeline_gotoFrameAndPlay3(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::ActionTimeline *self = nullptr;
    lua_Integer arg1 = 0;       /** startIndex */
    lua_Integer arg2 = 0;       /** endIndex */
    bool arg3 = false;       /** loop */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.ActionTimeline");
    olua_check_int(L, 2, &arg1);
    olua_check_int(L, 3, &arg2);
    olua_check_bool(L, 4, &arg3);

    // void gotoFrameAndPlay(int startIndex, int endIndex, bool loop)
    self->gotoFrameAndPlay((int)arg1, (int)arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_timeline_ActionTimeline_gotoFrameAndPlay4(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::ActionTimeline *self = nullptr;
    lua_Integer arg1 = 0;       /** startIndex */
    lua_Integer arg2 = 0;       /** endIndex */
    lua_Integer arg3 = 0;       /** currentFrameIndex */
    bool arg4 = false;       /** loop */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.ActionTimeline");
    olua_check_int(L, 2, &arg1);
    olua_check_int(L, 3, &arg2);
    olua_check_int(L, 4, &arg3);
    olua_check_bool(L, 5, &arg4);

    // void gotoFrameAndPlay(int startIndex, int endIndex, int currentFrameIndex, bool loop)
    self->gotoFrameAndPlay((int)arg1, (int)arg2, (int)arg3, arg4);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_timeline_ActionTimeline_gotoFrameAndPlay(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_int(L, 2))) {
            // void gotoFrameAndPlay(int startIndex)
            return _cocostudio_timeline_ActionTimeline_gotoFrameAndPlay1(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_int(L, 2)) && (olua_is_bool(L, 3))) {
            // void gotoFrameAndPlay(int startIndex, bool loop)
            return _cocostudio_timeline_ActionTimeline_gotoFrameAndPlay2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_int(L, 2)) && (olua_is_int(L, 3)) && (olua_is_bool(L, 4))) {
            // void gotoFrameAndPlay(int startIndex, int endIndex, bool loop)
            return _cocostudio_timeline_ActionTimeline_gotoFrameAndPlay3(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_int(L, 2)) && (olua_is_int(L, 3)) && (olua_is_int(L, 4)) && (olua_is_bool(L, 5))) {
            // void gotoFrameAndPlay(int startIndex, int endIndex, int currentFrameIndex, bool loop)
            return _cocostudio_timeline_ActionTimeline_gotoFrameAndPlay4(L);
        // }
    }

    luaL_error(L, "method 'cocostudio::timeline::ActionTimeline::gotoFrameAndPlay' not support '%d' arguments", num_args);

    return 0;
}

static int _cocostudio_timeline_ActionTimeline_isPlaying(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::ActionTimeline *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.ActionTimeline");

    // bool isPlaying()
    bool ret = self->isPlaying();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_ActionTimeline_new(lua_State *L)
{
    olua_startinvoke(L);

    // ActionTimeline()
    cocostudio::timeline::ActionTimeline *ret = new cocostudio::timeline::ActionTimeline();
    int num_ret = olua_push_cppobj(L, ret, "ccs.timeline.ActionTimeline");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocostudio_timeline_ActionTimeline_pause(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::ActionTimeline *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.ActionTimeline");

    // void pause()
    self->pause();

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_timeline_ActionTimeline_play(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::ActionTimeline *self = nullptr;
    std::string arg1;       /** animationName */
    bool arg2 = false;       /** loop */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.ActionTimeline");
    olua_check_std_string(L, 2, &arg1);
    olua_check_bool(L, 3, &arg2);

    // void play(std::string animationName, bool loop)
    self->play(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_timeline_ActionTimeline_removeAnimationInfo(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::ActionTimeline *self = nullptr;
    std::string arg1;       /** animationName */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.ActionTimeline");
    olua_check_std_string(L, 2, &arg1);

    // insert code before call
    auto info = self->getAnimationInfo(arg1);
    std::string cb_tag = makeFrameEndCallbackTag(info.endIndex, arg1);
    void *cb_store = (void *)self;
    olua_removecallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_SUBSTARTWITH);

    // void removeAnimationInfo(std::string animationName)
    self->removeAnimationInfo(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_timeline_ActionTimeline_removeFrameEndCallFunc(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::ActionTimeline *self = nullptr;
    lua_Integer arg1 = 0;       /** frameIndex */
    std::string arg2;       /** funcKey */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.ActionTimeline");
    olua_check_int(L, 2, &arg1);
    olua_check_std_string(L, 3, &arg2);

    std::string cb_tag = makeFrameEndCallbackTag(arg1, arg2);
    void *cb_store = (void *)self;
    olua_removecallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_SUBSTARTWITH);

    // void removeFrameEndCallFunc(int frameIndex, const std::string &funcKey)
    self->removeFrameEndCallFunc((int)arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_timeline_ActionTimeline_removeFrameEndCallFuncs(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::ActionTimeline *self = nullptr;
    lua_Integer arg1 = 0;       /** frameIndex */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.ActionTimeline");
    olua_check_int(L, 2, &arg1);

    std::string cb_tag = makeFrameEndCallbackTag(arg1, "");
    void *cb_store = (void *)self;
    olua_removecallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_SUBSTARTWITH);

    // void removeFrameEndCallFuncs(int frameIndex)
    self->removeFrameEndCallFuncs((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_timeline_ActionTimeline_removeTimeline(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::ActionTimeline *self = nullptr;
    cocostudio::timeline::Timeline *arg1 = nullptr;       /** timeline */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.ActionTimeline");
    olua_check_cppobj(L, 2, (void **)&arg1, "ccs.timeline.Timeline");

    // void removeTimeline(@delref(timelines |) cocostudio::timeline::Timeline *timeline)
    self->removeTimeline(arg1);

    // insert code after call
    olua_delref(L, 1, "timelines", 2, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_timeline_ActionTimeline_resume(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::ActionTimeline *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.ActionTimeline");

    // void resume()
    self->resume();

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_timeline_ActionTimeline_setAnimationEndCallFunc(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::ActionTimeline *self = nullptr;
    std::string arg1;       /** animationName */
    std::function<void()> arg2;       /** func */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.ActionTimeline");
    olua_check_std_string(L, 2, &arg1);
    olua_check_std_function(L, 3, &arg2);

    void *cb_store = (void *)self;
    std::string cb_tag = makeFrameEndCallbackTag(self, arg1);
    std::string cb_name = olua_setcallback(L, cb_store,  3, cb_tag.c_str(), OLUA_TAG_REPLACE);
    lua_Integer cb_ctx = olua_context(L);
    arg2 = [cb_store, cb_name, cb_ctx]() {
        lua_State *L = olua_mainthread(NULL);
        olua_checkhostthread();

        if (L != NULL && olua_context(L) == cb_ctx) {
            int top = lua_gettop(L);

            olua_callback(L, cb_store, cb_name.c_str(), 0);

            lua_settop(L, top);
        }
    };

    // void setAnimationEndCallFunc(const std::string animationName, @local std::function<void ()> func)
    self->setAnimationEndCallFunc(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_timeline_ActionTimeline_setCurrentFrame(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::ActionTimeline *self = nullptr;
    lua_Integer arg1 = 0;       /** frameIndex */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.ActionTimeline");
    olua_check_int(L, 2, &arg1);

    // void setCurrentFrame(int frameIndex)
    self->setCurrentFrame((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_timeline_ActionTimeline_setDuration(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::ActionTimeline *self = nullptr;
    lua_Integer arg1 = 0;       /** duration */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.ActionTimeline");
    olua_check_int(L, 2, &arg1);

    // void setDuration(int duration)
    self->setDuration((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_timeline_ActionTimeline_setFrameEventCallFunc(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::ActionTimeline *self = nullptr;
    std::function<void(cocostudio::timeline::Frame *)> arg1;       /** listener */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.ActionTimeline");
    olua_check_std_function(L, 2, &arg1);

    void *cb_store = (void *)self;
    std::string cb_tag = "frameEventCallFunc";
    std::string cb_name;
    if (olua_is_std_function(L, 2)) {
        cb_name = olua_setcallback(L, cb_store,  2, cb_tag.c_str(), OLUA_TAG_REPLACE);
        lua_Integer cb_ctx = olua_context(L);
        arg1 = [cb_store, cb_name, cb_ctx](cocostudio::timeline::Frame *arg1) {
            lua_State *L = olua_mainthread(NULL);
            olua_checkhostthread();

            if (L != NULL && olua_context(L) == cb_ctx) {
                int top = lua_gettop(L);
                size_t last = olua_push_objpool(L);
                olua_enable_objpool(L);
                olua_push_cppobj(L, arg1, "ccs.timeline.Frame");
                olua_disable_objpool(L);

                // insert code before call
                if (arg1->getTimeline() && arg1->getTimeline()->getActionTimeline()) {
                    olua_push_cppobj<cocostudio::timeline::ActionTimeline>(L, arg1->getTimeline()->getActionTimeline());
                    olua_push_cppobj<cocostudio::timeline::Timeline>(L, arg1->getTimeline());
                    olua_push_cppobj<cocostudio::timeline::Frame>(L, arg1);
                    olua_addref(L, -3, "timelines", -2, OLUA_MODE_MULTIPLE);
                    olua_addref(L, -2, "frames", -1, OLUA_MODE_MULTIPLE);
                    lua_pop(L, 3);
                }

                olua_callback(L, cb_store, cb_name.c_str(), 1);

                //pop stack value
                olua_pop_objpool(L, last);
                lua_settop(L, top);
            }
        };
    } else {
        olua_removecallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_SUBEQUAL);
        arg1 = nullptr;
    }

    // void setFrameEventCallFunc(@nullable @local std::function<void (cocostudio::timeline::Frame *)> listener)
    self->setFrameEventCallFunc(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_timeline_ActionTimeline_setLastFrameCallFunc(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::ActionTimeline *self = nullptr;
    std::function<void()> arg1;       /** listener */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.ActionTimeline");
    olua_check_std_function(L, 2, &arg1);

    void *cb_store = (void *)self;
    std::string cb_tag = "lastFrameCallFunc";
    std::string cb_name;
    if (olua_is_std_function(L, 2)) {
        cb_name = olua_setcallback(L, cb_store,  2, cb_tag.c_str(), OLUA_TAG_REPLACE);
        lua_Integer cb_ctx = olua_context(L);
        arg1 = [cb_store, cb_name, cb_ctx]() {
            lua_State *L = olua_mainthread(NULL);
            olua_checkhostthread();

            if (L != NULL && olua_context(L) == cb_ctx) {
                int top = lua_gettop(L);

                olua_callback(L, cb_store, cb_name.c_str(), 0);

                lua_settop(L, top);
            }
        };
    } else {
        olua_removecallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_SUBEQUAL);
        arg1 = nullptr;
    }

    // void setLastFrameCallFunc(@nullable @local std::function<void ()> listener)
    self->setLastFrameCallFunc(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_timeline_ActionTimeline_setTimeSpeed(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::ActionTimeline *self = nullptr;
    lua_Number arg1 = 0;       /** speed */

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.ActionTimeline");
    olua_check_number(L, 2, &arg1);

    // void setTimeSpeed(float speed)
    self->setTimeSpeed((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocostudio_timeline_ActionTimeline_start(lua_State *L)
{
    olua_startinvoke(L);

    cocostudio::timeline::ActionTimeline *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "ccs.timeline.ActionTimeline");

    // void start()
    self->start();

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocostudio_timeline_ActionTimeline(lua_State *L)
{
    oluacls_class(L, "ccs.timeline.ActionTimeline", "cc.Action");
    oluacls_func(L, "IsAnimationInfoExists", _cocostudio_timeline_ActionTimeline_IsAnimationInfoExists);
    oluacls_func(L, "__olua_move", _cocostudio_timeline_ActionTimeline___olua_move);
    oluacls_func(L, "addAnimationInfo", _cocostudio_timeline_ActionTimeline_addAnimationInfo);
    oluacls_func(L, "addFrameEndCallFunc", _cocostudio_timeline_ActionTimeline_addFrameEndCallFunc);
    oluacls_func(L, "addTimeline", _cocostudio_timeline_ActionTimeline_addTimeline);
    oluacls_func(L, "clearFrameEndCallFuncs", _cocostudio_timeline_ActionTimeline_clearFrameEndCallFuncs);
    oluacls_func(L, "clearFrameEventCallFunc", _cocostudio_timeline_ActionTimeline_clearFrameEventCallFunc);
    oluacls_func(L, "clearLastFrameCallFunc", _cocostudio_timeline_ActionTimeline_clearLastFrameCallFunc);
    oluacls_func(L, "create", _cocostudio_timeline_ActionTimeline_create);
    oluacls_func(L, "getAnimationInfo", _cocostudio_timeline_ActionTimeline_getAnimationInfo);
    oluacls_func(L, "getCurrentFrame", _cocostudio_timeline_ActionTimeline_getCurrentFrame);
    oluacls_func(L, "getDuration", _cocostudio_timeline_ActionTimeline_getDuration);
    oluacls_func(L, "getEndFrame", _cocostudio_timeline_ActionTimeline_getEndFrame);
    oluacls_func(L, "getStartFrame", _cocostudio_timeline_ActionTimeline_getStartFrame);
    oluacls_func(L, "getTimeSpeed", _cocostudio_timeline_ActionTimeline_getTimeSpeed);
    oluacls_func(L, "getTimelines", _cocostudio_timeline_ActionTimeline_getTimelines);
    oluacls_func(L, "gotoFrameAndPause", _cocostudio_timeline_ActionTimeline_gotoFrameAndPause);
    oluacls_func(L, "gotoFrameAndPlay", _cocostudio_timeline_ActionTimeline_gotoFrameAndPlay);
    oluacls_func(L, "isPlaying", _cocostudio_timeline_ActionTimeline_isPlaying);
    oluacls_func(L, "new", _cocostudio_timeline_ActionTimeline_new);
    oluacls_func(L, "pause", _cocostudio_timeline_ActionTimeline_pause);
    oluacls_func(L, "play", _cocostudio_timeline_ActionTimeline_play);
    oluacls_func(L, "removeAnimationInfo", _cocostudio_timeline_ActionTimeline_removeAnimationInfo);
    oluacls_func(L, "removeFrameEndCallFunc", _cocostudio_timeline_ActionTimeline_removeFrameEndCallFunc);
    oluacls_func(L, "removeFrameEndCallFuncs", _cocostudio_timeline_ActionTimeline_removeFrameEndCallFuncs);
    oluacls_func(L, "removeTimeline", _cocostudio_timeline_ActionTimeline_removeTimeline);
    oluacls_func(L, "resume", _cocostudio_timeline_ActionTimeline_resume);
    oluacls_func(L, "setAnimationEndCallFunc", _cocostudio_timeline_ActionTimeline_setAnimationEndCallFunc);
    oluacls_func(L, "setCurrentFrame", _cocostudio_timeline_ActionTimeline_setCurrentFrame);
    oluacls_func(L, "setDuration", _cocostudio_timeline_ActionTimeline_setDuration);
    oluacls_func(L, "setFrameEventCallFunc", _cocostudio_timeline_ActionTimeline_setFrameEventCallFunc);
    oluacls_func(L, "setLastFrameCallFunc", _cocostudio_timeline_ActionTimeline_setLastFrameCallFunc);
    oluacls_func(L, "setTimeSpeed", _cocostudio_timeline_ActionTimeline_setTimeSpeed);
    oluacls_func(L, "start", _cocostudio_timeline_ActionTimeline_start);
    oluacls_prop(L, "currentFrame", _cocostudio_timeline_ActionTimeline_getCurrentFrame, _cocostudio_timeline_ActionTimeline_setCurrentFrame);
    oluacls_prop(L, "duration", _cocostudio_timeline_ActionTimeline_getDuration, _cocostudio_timeline_ActionTimeline_setDuration);
    oluacls_prop(L, "endFrame", _cocostudio_timeline_ActionTimeline_getEndFrame, nullptr);
    oluacls_prop(L, "playing", _cocostudio_timeline_ActionTimeline_isPlaying, nullptr);
    oluacls_prop(L, "startFrame", _cocostudio_timeline_ActionTimeline_getStartFrame, nullptr);
    oluacls_prop(L, "timeSpeed", _cocostudio_timeline_ActionTimeline_getTimeSpeed, _cocostudio_timeline_ActionTimeline_setTimeSpeed);
    oluacls_prop(L, "timelines", _cocostudio_timeline_ActionTimeline_getTimelines, nullptr);

    olua_registerluatype<cocostudio::timeline::ActionTimeline>(L, "ccs.timeline.ActionTimeline");

    return 1;
}

int luaopen_cocos2d_studio(lua_State *L)
{
    olua_require(L, "cc.CSLoader", luaopen_cocos2d_CSLoader);
    olua_require(L, "ccs.MovementEventType", luaopen_cocostudio_MovementEventType);
    olua_require(L, "ccs.DisplayType", luaopen_cocostudio_DisplayType);
    olua_require(L, "ccs.ActionFrame", luaopen_cocostudio_ActionFrame);
    olua_require(L, "ccs.ActionFadeFrame", luaopen_cocostudio_ActionFadeFrame);
    olua_require(L, "ccs.ActionFrameEasing", luaopen_cocostudio_ActionFrameEasing);
    olua_require(L, "ccs.ActionMoveFrame", luaopen_cocostudio_ActionMoveFrame);
    olua_require(L, "ccs.ActionRotationFrame", luaopen_cocostudio_ActionRotationFrame);
    olua_require(L, "ccs.ActionScaleFrame", luaopen_cocostudio_ActionScaleFrame);
    olua_require(L, "ccs.ActionTintFrame", luaopen_cocostudio_ActionTintFrame);
    olua_require(L, "ccs.AnimationData", luaopen_cocostudio_AnimationData);
    olua_require(L, "ccs.Armature", luaopen_cocostudio_Armature);
    olua_require(L, "ccs.ProcessBase", luaopen_cocostudio_ProcessBase);
    olua_require(L, "ccs.ActionManagerEx", luaopen_cocostudio_ActionManagerEx);
    olua_require(L, "ccs.ActionNode", luaopen_cocostudio_ActionNode);
    olua_require(L, "ccs.ActionObject", luaopen_cocostudio_ActionObject);
    olua_require(L, "ccs.ArmatureAnimation", luaopen_cocostudio_ArmatureAnimation);
    olua_require(L, "ccs.ArmatureData", luaopen_cocostudio_ArmatureData);
    olua_require(L, "ccs.ArmatureDataManager", luaopen_cocostudio_ArmatureDataManager);
    olua_require(L, "ccs.DisplayData", luaopen_cocostudio_DisplayData);
    olua_require(L, "ccs.ArmatureDisplayData", luaopen_cocostudio_ArmatureDisplayData);
    olua_require(L, "ccs.ArmatureMovementDispatcher", luaopen_cocostudio_ArmatureMovementDispatcher);
    olua_require(L, "ccs.BaseData", luaopen_cocostudio_BaseData);
    olua_require(L, "ccs.BaseTriggerAction", luaopen_cocostudio_BaseTriggerAction);
    olua_require(L, "ccs.BaseTriggerCondition", luaopen_cocostudio_BaseTriggerCondition);
    olua_require(L, "ccs.BatchNode", luaopen_cocostudio_BatchNode);
    olua_require(L, "ccs.Bone", luaopen_cocostudio_Bone);
    olua_require(L, "ccs.BoneData", luaopen_cocostudio_BoneData);
    olua_require(L, "ccs.CocoLoader", luaopen_cocostudio_CocoLoader);
    olua_require(L, "ccs.ColliderBody", luaopen_cocostudio_ColliderBody);
    olua_require(L, "ccs.ColliderDetector", luaopen_cocostudio_ColliderDetector);
    olua_require(L, "ccs.ColliderFilter", luaopen_cocostudio_ColliderFilter);
    olua_require(L, "ccs.ComAttribute", luaopen_cocostudio_ComAttribute);
    olua_require(L, "ccs.ComAudio", luaopen_cocostudio_ComAudio);
    olua_require(L, "ccs.ComController", luaopen_cocostudio_ComController);
    olua_require(L, "ccs.ComRender", luaopen_cocostudio_ComRender);
    olua_require(L, "ccs.ContourData", luaopen_cocostudio_ContourData);
    olua_require(L, "ccs.DataReaderHelper", luaopen_cocostudio_DataReaderHelper);
    olua_require(L, "ccs.DecorativeDisplay", luaopen_cocostudio_DecorativeDisplay);
    olua_require(L, "ccs.DisplayFactory", luaopen_cocostudio_DisplayFactory);
    olua_require(L, "ccs.DisplayManager", luaopen_cocostudio_DisplayManager);
    olua_require(L, "ccs.FrameData", luaopen_cocostudio_FrameData);
    olua_require(L, "ccs.GUIReader", luaopen_cocostudio_GUIReader);
    olua_require(L, "ccs.InputDelegate", luaopen_cocostudio_InputDelegate);
    olua_require(L, "ccs.MovementBoneData", luaopen_cocostudio_MovementBoneData);
    olua_require(L, "ccs.MovementData", luaopen_cocostudio_MovementData);
    olua_require(L, "ccs.ParticleDisplayData", luaopen_cocostudio_ParticleDisplayData);
    olua_require(L, "ccs.SceneReader.AttachComponentType", luaopen_cocostudio_SceneReader_AttachComponentType);
    olua_require(L, "ccs.SceneReader", luaopen_cocostudio_SceneReader);
    olua_require(L, "ccs.Skin", luaopen_cocostudio_Skin);
    olua_require(L, "ccs.SpriteDisplayData", luaopen_cocostudio_SpriteDisplayData);
    olua_require(L, "ccs.SpriteFrameCacheHelper", luaopen_cocostudio_SpriteFrameCacheHelper);
    olua_require(L, "ccs.TextureData", luaopen_cocostudio_TextureData);
    olua_require(L, "ccs.Tween", luaopen_cocostudio_Tween);
    olua_require(L, "ccs.timeline.InnerActionType", luaopen_cocostudio_timeline_InnerActionType);
    olua_require(L, "ccs.timeline.Frame", luaopen_cocostudio_timeline_Frame);
    olua_require(L, "ccs.timeline.AlphaFrame", luaopen_cocostudio_timeline_AlphaFrame);
    olua_require(L, "ccs.timeline.AnchorPointFrame", luaopen_cocostudio_timeline_AnchorPointFrame);
    olua_require(L, "ccs.timeline.BlendFuncFrame", luaopen_cocostudio_timeline_BlendFuncFrame);
    olua_require(L, "ccs.timeline.ColorFrame", luaopen_cocostudio_timeline_ColorFrame);
    olua_require(L, "ccs.timeline.EventFrame", luaopen_cocostudio_timeline_EventFrame);
    olua_require(L, "ccs.timeline.InnerActionFrame", luaopen_cocostudio_timeline_InnerActionFrame);
    olua_require(L, "ccs.timeline.PlayableFrame", luaopen_cocostudio_timeline_PlayableFrame);
    olua_require(L, "ccs.timeline.PositionFrame", luaopen_cocostudio_timeline_PositionFrame);
    olua_require(L, "ccs.timeline.RotationFrame", luaopen_cocostudio_timeline_RotationFrame);
    olua_require(L, "ccs.timeline.SkewFrame", luaopen_cocostudio_timeline_SkewFrame);
    olua_require(L, "ccs.timeline.RotationSkewFrame", luaopen_cocostudio_timeline_RotationSkewFrame);
    olua_require(L, "ccs.timeline.ScaleFrame", luaopen_cocostudio_timeline_ScaleFrame);
    olua_require(L, "ccs.timeline.TextureFrame", luaopen_cocostudio_timeline_TextureFrame);
    olua_require(L, "ccs.timeline.VisibleFrame", luaopen_cocostudio_timeline_VisibleFrame);
    olua_require(L, "ccs.timeline.ZOrderFrame", luaopen_cocostudio_timeline_ZOrderFrame);
    olua_require(L, "ccs.timeline.ActionTimelineCache", luaopen_cocostudio_timeline_ActionTimelineCache);
    olua_require(L, "ccs.timeline.ActionTimelineData", luaopen_cocostudio_timeline_ActionTimelineData);
    olua_require(L, "ccs.timeline.ActionTimelineNode", luaopen_cocostudio_timeline_ActionTimelineNode);
    olua_require(L, "ccs.timeline.BoneNode", luaopen_cocostudio_timeline_BoneNode);
    olua_require(L, "ccs.timeline.SkeletonNode", luaopen_cocostudio_timeline_SkeletonNode);
    olua_require(L, "ccs.timeline.Timeline", luaopen_cocostudio_timeline_Timeline);
    olua_require(L, "ccs.timeline.ActionTimeline", luaopen_cocostudio_timeline_ActionTimeline);
    return 0;
}
