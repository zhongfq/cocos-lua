# Cocos-lua

cocos-lua以cocos2d-x 3.17.2的c++项目为基础，采用基于lua gc来管理c++对象的生命周期，提供更丰富cocos2d-x lua api，包括几乎除模版以外的所有lambda（schedule、scheduleOnce...）函数回调，能够极大减少在lua层使用c++对象的负担。

## 优势

1. 基于lua gc管理c++对象生命周期，更符合lua开发者，规避使用tolua.isnull判断。
2. 导出代码相对tolua更精炼、高效率以及更友善错误检测机制。
3. lambda函数自动化的导出，tolua是手动导出。
4. 更优秀的第三方框架支持，如fairygui、spine、dragonbone之类的。
5. 更加轻量和高效的lua绑定层。

## 如何使用

仓库本身就是一个项目，方便以后统一升级至最新的cocos2dx源码，也可以使用脚本创建项目：

    $ cd tools/bin
    $ ./create-project -n project-name -p package-name -d ~/

runtime-src目录包括了mac、win和android平台的项目，具体使用方式可以参考cocos2d-x官方的文档，后续会在tools/bin中提供更方便的编译iOS和android脚本。

## 热更新

cocos-lua在lua层提供热更的检测和下载，并提供按需下载的支持，具体实现参见assets/src/bootstrap.lua。生成热更新版本文件参见tools/hot-update/build-update.lua脚本，后续将提供更为详细的使用方法。

## 启动流程

cocos-lua启动后会在c++层执行assets/src/bootstrap.lua文件，也就是说，你可以完全不使用cocos-lua提供的lua脚本，更换为自己所熟悉的方案，比如quick-x。

## lua版本

cocos-lua虽然基于lua 5.3，但是绑定库[olua](https://github.com/zhongfq/olua)兼容lua 5.1，也就是你自己可以更换lua 5.1或luajit。当然也可以将cocos-lua的绑定代码移植至你所熟悉的cocos2d-x lua方案中。

## 绑定代码生成

tools/lua-bindings提供代码生成脚本，目前只支持mac平台，后续将支持linux和win，你可以参考tools/lua-clang，自己编译libclang后，再编译成lua可调用的动态库。

## 核心实现

cocos-lua在lua层屏蔽Ref的release和retain方法，改由lua gc管理，以实现c++对象的安全访问。

### 1. 引用管理
+ lua vm建立一个弱引用表，以c++对象指针为键，userdata为值，进行存储。
+ 当调用olua_push_cppobj将c++对象传递给lua层时，如果c++对象是全新的并且是派生于Ref的对象，那么将调用obj->retain()，使得lua vm持有一份引用。
+ 在lua gc的时候，如果对象未被使用，会在gc方法中调用obj->release()将对象释放。
+ 如果你又在gc中将此对象复活，当你再次使用该对象时，将得一个lua error。

### 2. lambda函数

区别于传统lua ref机制，olua将lua函数回调存储在userdata的uservalue中，这样好处，是将函数的生命周期与对象绑定，并且不会出现传统lua ref机制中循环引用，导致对象不被回收。

以下是自动导出的代码片断：

```c++
static int _cocos2d_EventListenerTouchAllAtOnce_set_onTouchesBegan(lua_State *L)
{
    olua_startinvoke(L);

    lua_settop(L, 2);

    cocos2d::EventListenerTouchAllAtOnce *self = nullptr;
    std::function<void(const std::vector<cocos2d::Touch *> &, cocos2d::Event *)> arg1;       /** onTouchesBegan */

    olua_to_cppobj(L, 1, (void **)&self, "cc.EventListenerTouchAllAtOnce");

    if (olua_is_std_function(L, 2)) {
        void *callback_store_obj = (void *)self;
        std::string tag = olua_makecallbacktag("onTouchesBegan");
        std::string func = olua_setcallback(L, callback_store_obj, tag.c_str(), 2, OLUA_TAG_REPLACE);
        arg1 = [callback_store_obj, func](const std::vector<cocos2d::Touch *> &arg1, cocos2d::Event *arg2) {
            lua_State *L = olua_mainthread();
            int top = lua_gettop(L);

            size_t last = olua_push_objpool(L);
            olua_enable_objpool(L);
            olua_push_std_vector(L, arg1, "cc.Touch");
            olua_push_cppobj(L, arg2, "cc.Event");
            olua_disable_objpool(L);

            olua_callback(L, callback_store_obj, func.c_str(), 2);

            //pop stack value
            olua_pop_objpool(L, last);

            lua_settop(L, top);
        };
    } else {
        void *callback_store_obj = (void *)self;
        std::string tag = olua_makecallbacktag("onTouchesBegan");
        olua_removecallback(L, callback_store_obj, tag.c_str(), OLUA_TAG_ENDWITH);
        arg1 = nullptr;
    }

    // std::function<void(@local const std::vector<Touch*>&, @local Event*)> onTouchesBegan = nullptr
    self->onTouchesBegan = arg1;

    olua_endinvoke(L);

    return 0;
}
```
### 3. 回调函数生命周期

将lua回调函数存储在uservalue会有一个问题，如果uservalue被回收，那么回调函数就丢失了。比如CallFunc中的回调，当调用完obj:runAction(sequence)之后，在action未全部完成而中途发生lua gc，那么这些userdata对象将被回收，这就导致与使用的预期不一致问题。为了解决这个问题，cocos-lua通过导出时注入代码的方式，引入了引用链的机制。

+ 将cocos2d::Director作用根对象，以__cocos2d_ref_chain__为键存储在LUA_REGISTRYINDEX表中。
+ 对能够存储回调的Node、Director、Action、Component、ActionManager、Schedule以及EventDispatcher等对象，在一些添加（addChild...）或移除（removeAllChildren...）方法中注入ref或unref代码。

导出配置：
```lua
local Director = typeconf 'cocos2d::Director'
Director.ATTR('getRunningScene', {RET = '@ref(map scenes)'})
Director.ATTR('runWithScene', {ARG1 = '@ref(map scenes)'})
Director.ATTR('pushScene', {ARG1 = '@ref(map scenes)'})
Director.ATTR('replaceScene', {RET = '@unref(cmp scenes)', ARG1 = '@ref(map scenes)'})
Director.ATTR('popScene', {RET = '@unref(cmp scenes)'})
Director.ATTR('popToRootScene', {RET = '@unref(cmp scenes)'})
Director.ATTR('popToSceneStackLevel', {RET = '@unref(cmp scenes)'})
```
生成代码：
```c++
static int _cocos2d_Director_getRunningScene(lua_State *L)
{
    olua_startinvoke(L);
    lua_settop(L, 1);
    cocos2d::Director *self = nullptr;
    olua_to_cppobj(L, 1, (void **)&self, "cc.Director");
    // @ref(map scenes) Scene* getRunningScene()
    cocos2d::Scene *ret = (cocos2d::Scene *)self->getRunningScene();
    int num_ret = olua_push_cppobj(L, ret, "cc.Scene");
    // inject code after call
    olua_mapref(L, 1, "scenes", -1);
    olua_endinvoke(L);
    return num_ret;
}

static int _cocos2d_Director_popScene(lua_State *L)
{
    olua_startinvoke(L);
    lua_settop(L, 1);
    cocos2d::Director *self = nullptr;
    olua_to_cppobj(L, 1, (void **)&self, "cc.Director");
    // inject code before call
    olua_startcmpunref(L, 1, "scenes");
    // @unref(cmp scenes) void popScene()
    self->popScene();
    // inject code after call
    olua_endcmpunref(L, 1, "scenes");
    olua_endinvoke(L);
    return 0;
}
```

## 若干说明
1. assets/src/swf目录下的lua代码不宜使用，因为swf c++解析渲染库目前暂时无法开源。
2. assets/src/ui目录下的布局代码不建议使用，它的存在只是用来做兼容层（为swf添加触摸支持等），推荐使用fairygui进行布局。
3. 如果你需要使用的一些类没有导出，可以提个需求，我尽快导出。
4. 建议使用vscode打开项目，可以使用luaide插件进行调试。

## 待完成

+ 导出工具自动检查指定类型的ref和unref情况
+ cocos2dx v4版本绑定支持
+ 导出工具的linux和win平台支持
+ 更完善的单元测试