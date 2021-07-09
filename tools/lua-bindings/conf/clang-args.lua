clang {
    headers = [[
        #include "cocos2d.h"
        #include "3d/CC3DProgramInfo.h"
        #include "3d/CCBundle3D.h"
        #include "audio/include/AudioEngine.h"
        #include "base/TGAlib.h"
        #include "base/CCMap.h"
        #include "renderer/backend/Backend.h"
        #include "ui/CocosGUI.h"
        #include "ui/UIScrollViewBar.h"
        #include "navmesh/CCNavMesh.h"
        #include "editor-support/cocostudio/CocoStudio.h"

        // fairygui
        #include "FairyGUI.h"
        #include "GLoader3D.h"
        #include "tween/EaseManager.h"
        #include "tween/GPath.h"
        #include "display/FUISprite.h"
        #include "utils/html/HtmlElement.h"
        #include "utils/html/HtmlObject.h"
        #include "utils/html/HtmlParser.h"

        // spine
        #include "spine/spine-cocos2dx.h"

        // dragonbones
        #include "CCDragonBonesHeaders.h"

        // xgame
        #include "cclua/filesystem.h"
        #include "cclua/runtime.h"
        #include "cclua/preferences.h"
        #include "cclua/downloader.h"
        #include "cclua/RootScene.h"
        #include "cclua/timer.h"
        #include "cclua/window.h"
        #include "lua-bindings/LuaCocosAdapter.h"

        #include "jiguang/JiGuang.h"
        #include "talkingdata/TalkingData.h"
        #include "wechat/WeChat.h"
        #include "bugly/CrashReport.h"
        #include "apple/Apple.h"
    ]],
    flags = {
        '-DCC_CONSTRUCTOR_ACCESS=public',
        '-DCC_ENABLE_SCRIPT_BINDING=0',
        '-DSPINE_USE_STD_FUNCTION',
        '-DCCLUA_BUILD_JPUSH',
        '-DCCLUA_BUILD_JAUTH',
        '-DCCLUA_BUILD_JANALYTICS',
        '-DCCLUA_BUILD_TALKINGDATA',
        '-DCCLUA_BUILD_APPLE_AUTH',
        '-I../../frameworks/cocos2d-x/cocos',
        '-I../../frameworks/cocos2d-x/cocos/editor-support',
        '-I../../frameworks/cocos2d-x/cocos/platform',
        '-I../../frameworks/cocos2d-x/external',
        '-I../../frameworks/libfairygui/Classes',
        '-I../../frameworks/libdragonbones/src',
        '-I../../frameworks/libxgame/src',
        '-I../../frameworks/libxgame/src/lua',
        '-I../../frameworks/plugins',

        '-x', 'c++', '-nostdinc', '-std=c++11',
        '-U__SSE__',
        '-DANDROID', '-target', 'armv7-none-linux-androideabi',

        '-idirafter', '${HOMEDIR}/include/c++',
        '-idirafter', '${HOMEDIR}/include/c',
        '-idirafter', '${HOMEDIR}/include/android-sysroot/x86_64-linux-android',
        '-idirafter', '${HOMEDIR}/include/android-sysroot',
    },
}