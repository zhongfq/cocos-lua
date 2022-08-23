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

        // box2d
        #include "box2d/box2d.h"
        #include "box2d/Box2DAdapter.h"

        // xgame
        #include "cclua/cclua.h"
        #include "lua-bindings/LuaCocosAdapter.h"

        #include "alipay/alipay.h"
        #include "apple/apple.h"
        #include "bugly/CrashReport.h"
        #include "huawei/huawei.h"
        #include "jiguang/jiguang.h"
        #include "oppo/oppo.h"
        #include "talkingdata/talkingdata.h"
        #include "vivo/vivo.h"
        #include "wechat/wechat.h"
    ]],
    flags = {
        '-DCC_CONSTRUCTOR_ACCESS=public',
        '-DCC_ENABLE_SCRIPT_BINDING=0',
        '-DSPINE_USE_STD_FUNCTION',
        '-DCCLUA_BUILD_JPUSH',
        '-DCCLUA_BUILD_JAUTH',
        '-DCCLUA_BUILD_JANALYTICS',
        '-DCCLUA_BUILD_TALKINGDATA',
        '-DCCLUA_BUILD_WECHAT',
        '-I../../frameworks/cocos2d-x/cocos',
        '-I../../frameworks/cocos2d-x/cocos/editor-support',
        '-I../../frameworks/cocos2d-x/cocos/platform',
        '-I../../frameworks/cocos2d-x/external',
        '-I../../frameworks/box2d/include',
        '-I../../frameworks/libfairygui/Classes',
        '-I../../frameworks/libdragonbones/src',
        '-I../../frameworks/libxgame/src',
        '-I../../frameworks/libxgame/src/lua',
        '-I../../frameworks/plugins',
    },
}