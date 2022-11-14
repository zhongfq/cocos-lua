# Cocos-lua

cocos-lua以 cocos2d-x 3.17.2 的 c++ 项目为基础，采用基于 lua gc 来管理 c++ 对象的生命周期，提供更丰富 cocos2d-x lua api，包括几乎除模版以外的所有 lambda（schedule、scheduleOnce...）函数回调，能够极大减少在 lua 层使用 c++ 对象的负担。

## 优势

1. 基于 lua gc 管理 c++ 对象生命周期，更符合 lua 开发者，规避使用 tolua.isnull 判断。
2. 导出代码相对 tolua 更精炼、高效率以及更友善错误检测机制。
3. lambda 函数自动化的导出，tolua 是手动导出。
4. 更优秀的第三方框架支持，如 fairygui、spine、dragonbone 之类的。
5. 更加轻量和高效的 lua 绑定层。

## 如何使用

仓库本身就是一个项目，方便以后统一升级至最新的 cocos2dx 源码，也可以使用脚本创建项目：

    $ cd tools/bin
    $ ./create-project -n project-name -p package-name -d ~/

runtime-src 目录包括了 mac、win 和 android 平台的项目，具体使用方式可以参考 cocos2d-x 官方的文档，后续会在 tools/bin 中提供更方便的编译 iOS 和 android 脚本。

## 热更新

cocos-lua 在 lua 层提供热更的检测和下载，并提供按需下载的支持，具体实现参见 assets/src/bootstrap.lua。生成热更新版本文件参见 tools/hot-update/build-update.lua 脚本，后续将提供更为详细的使用方法。

## 启动流程

cocos-lua 启动后会在 c++ 层执行 assets/src/bootstrap.lua 文件，也就是说，你可以完全不使用 cocos-lua 提供的 lua 脚本，更换为自己所熟悉的方案，比如 quick-x。

## lua版本

cocos-lua 虽然基于 lua 5.3，但是绑定库 [olua](https://github.com/zhongfq/olua) 兼容 lua 5.1，也就是你自己可以更换 lua 5.1 或 luajit。当然也可以将 cocos-lua 的绑定代码移植至你所熟悉的 cocos2d-x lua方案中。

## 绑定代码生成

tools/lua-bindings 提供代码生成脚本，具体的例子可以参考 tools/lua-bindings/conf 目前下的配置文件，如果你所使用的平台执行有问题，那么你可以自己编译 clang 动态库，编译参见[lua-clang](https://github.com/zhongfq/lua-clang)
```sh
# window cmd，mac or linux terminal
cd tools/lua-bindings
lua buildConfig.lua     # 自动扫描类，生成扫描结果
lua buildBindings.lua   # 执行导出lua bindings
```

## 核心实现

cocos-lua 在 lua 层屏蔽 Ref 的 release 和 retain 方法，改由 lua gc 管理，以实现 c++ 对象的安全访问。

### 1. 引用管理
+ lua vm 建立一个弱引用表，以 c++ 对象指针为键，userdata 为值，进行存储。
+ 当调用 olua_push_obj 将 c++ 对象传递给lua层时，如果c++对象是全新的并且是派生于Ref的对象，那么将调用obj->retain()，使得lua vm持有一份引用。
+ 在lua gc的时候，如果对象未被使用，会在gc方法中调用obj->release()将对象释放。
+ 如果你又在gc中将此对象复活，当你再次使用该对象时，将得一个lua error。

### 2. lambda函数

区别于传统lua ref机制，olua将lua函数回调存储在userdata的uservalue中，这样好处，是将函数的生命周期与对象绑定，并且不会出现传统lua ref机制中循环引用，导致对象不被回收。

### 3. 回调函数生命周期

将lua回调函数存储在uservalue会有一个问题，如果uservalue被回收，那么回调函数就丢失了。比如CallFunc中的回调，当调用完obj:runAction(sequence)之后，在action未全部完成而中途发生lua gc，那么这些userdata对象将被回收，这就导致与使用的预期不一致问题。为了解决这个问题，cocos-lua通过导出时注入代码的方式，引入了引用链的机制。

+ 将cocos2d::Director作用根对象，以__cocos2d_ref_chain__为键存储在LUA_REGISTRYINDEX表中。
+ 对能够存储回调的Node、Director、Action、Component、ActionManager、Schedule以及EventDispatcher等对象，在一些添加（addChild...）或移除（removeAllChildren...）方法中注入addref或delref代码。

## 若干说明
1. assets/src/ui目录下的布局代码不建议使用，它的存在只是用来做兼容层（为swf添加触摸支持等），推荐使用fairygui进行布局。
2. 如果你需要使用的一些类没有导出，可以提个需求，我尽快导出。
3. 建议使用vscode打开项目，可以使用luaide插件进行调试。

## 待完成

+ 导出工具自动检查指定类型的ref和unref情况
+ 更完善的单元测试