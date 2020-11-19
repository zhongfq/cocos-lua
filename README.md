# Cocos-lua

[![iOS Build Status](https://github.com/zhongfq/cocos-lua/workflows/ios/badge.svg)](https://github.com/zhongfq/cocos-lua/actions?query=workflow:ios)
[![Android Build Status](https://github.com/zhongfq/cocos-lua/workflows/android/badge.svg)](https://github.com/zhongfq/cocos-lua/actions?query=workflow:android)
[![Mac Build Status](https://github.com/zhongfq/cocos-lua/workflows/macos/badge.svg)](https://github.com/zhongfq/cocos-lua/actions?query=workflow:macos)
[![Window Build Status](https://github.com/zhongfq/cocos-lua/workflows/windows/badge.svg)](https://github.com/zhongfq/cocos-lua/actions?query=workflow:windows)

cocos-lua以cocos2d-x v4的c++项目为基础，采用基于lua gc来管理c++对象的生命周期，提供更丰富cocos2d-x lua api，包括几乎除模版以外的所有lambda（schedule、scheduleOnce...）函数回调，能够极大减少在lua层使用c++对象的负担。

## 优势

1. 基于lua gc管理c++对象生命周期，更符合lua开发者，规避使用tolua.isnull判断。
2. 导出代码相对tolua更精炼、高效率以及更友善错误检测机制。
3. lambda函数自动化的导出，tolua是手动导出。
4. 更优秀的第三方框架支持，如fairygui、spine、dragonbone之类的。
5. 更加轻量和高效的lua绑定层。

## 如何使用

cocos2d-x v4全部采用cmake构建，可以使用cmake生成各平台项目，生成之前，确保已经安装了cmake和python2.7。

#### 生成macOS项目

```sh
cd cocos-lua
mkdir -p build/mac-build && cd build/mac-build
cmake ../.. -GXcode
open cocos-lua.xcodeproj
```

#### 生成iOS项目

```sh
cd cocos-lua
mkdir build/ios-build && cd build/ios-build
cmake ../.. -GXcode -DCMAKE_SYSTEM_NAME=iOS
open cocos-lua.xcodeproj
```

#### 生成Visual Studio项目（使用cmd）

```sh
cd cocos-lua
mkdir build\win32-build && cd build\win32-build
cmake ../.. -A Win32
# cmake ../.. -G"Visual Studio 15 2017" -Tv141 -A Win32
```

#### Android编译
```sh
cd runtime-src/proj.android
./gradlew assembleRelease
```

更多信息参见[v4编译说明](https://github.com/cocos2d/cocos2d-x/blob/v4/cmake/README.md)

## 热更新

cocos-lua在lua层提供热更的检测和下载，并提供按需下载的支持，具体实现参见assets/src/bootstrap.lua。生成热更新版本文件参见tools/hot-update/build-update.lua脚本，后续将提供更为详细的使用方法。

## 启动流程

cocos-lua启动后会在c++层执行assets/src/bootstrap.lua文件，也就是说，你可以完全不使用cocos-lua提供的lua脚本，更换为自己所熟悉的方案，比如quick-x。

## lua版本

cocos-lua虽然基于lua 5.4，但是绑定库[olua](https://github.com/zhongfq/olua)兼容lua 5.1和5.3，也就是你自己可以更换lua 5.1或luajit。当然也可以将cocos-lua的绑定代码移植至你所熟悉的cocos2d-x lua方案中。

## 绑定代码生成

tools/lua-bindings提供代码生成脚本，具体的例子可以参考tools/lua-bindings/conf目前下的配置文件，如果你所使用的平台执行有问题，那么你可以自己编译clang动态库，编译参见[lua-clang](https://github.com/zhongfq/lua-clang)
```sh
# window cmd，mac or linux terminal
cd tools/lua-bindings
lua buildConfig.lua     # 自动扫描类，生成扫描结果
lua buildBindings.lua   # 执行导出lua bindings
```

## 核心实现

cocos-lua在lua层屏蔽Ref的release和retain方法，改由lua gc管理，以实现c++对象的安全访问。

### 1. 引用管理
+ lua vm建立一个弱引用表，以c++对象指针为键，userdata为值，进行存储。
+ 当调用olua_push_cppobj将c++对象传递给lua层时，如果c++对象是全新的并且是派生于Ref的对象，那么将调用obj->retain()，使得lua vm持有一份引用。
+ 在lua gc的时候，如果对象未被使用，会在gc方法中调用obj->release()将对象释放。
+ 如果你又在gc中将此对象复活，当你再次使用该对象时，将得一个lua error。

### 2. lambda函数

区别于传统lua ref机制，olua将lua函数回调存储在userdata的uservalue中，这样好处，是将函数的生命周期与对象绑定，并且不会出现传统lua ref机制中循环引用，导致对象不被回收。

### 3. 回调函数生命周期

将lua回调函数存储在uservalue会有一个问题，如果uservalue被回收，那么回调函数就丢失了。比如CallFunc中的回调，当调用完obj:runAction(sequence)之后，在action未全部完成而中途发生lua gc，那么这些userdata对象将被回收，这就导致与使用的预期不一致问题。为了解决这个问题，cocos-lua通过导出时插入代码的方式，引入了引用链的机制。

+ 将cocos2d::Director作用根对象，以__cocos2d_ref_chain__为键存储在LUA_REGISTRYINDEX表中。
+ 对能够存储回调的Node、Director、Action、Component、ActionManager、Schedule以及EventDispatcher等对象，在一些添加（addChild...）或移除（removeAllChildren...）方法中注入addref或delref代码。

## 若干说明
1. assets/src/ui目录下的布局代码不建议使用，它的存在只是用来做兼容层（为swf添加触摸支持等），推荐使用fairygui进行布局。
2. 如果你需要使用的一些类没有导出，可以提个需求，我尽快导出。
3. 建议使用vscode打开项目，可以使用luaide插件进行调试。

## 待完成

+ 导出工具自动检查指定类型的ref和unref情况
+ 更完善的单元测试
