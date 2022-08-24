clang {
    headers = [[
        #include "audio/include/AudioEngine.h"
        #include "base/TGAlib.h"
        #include "cocos2d.h"
        #include "ui/CocosGUI.h"
        #include "ui/UIScrollViewBar.h"
        #include "vr/CCVRGenericHeadTracker.h"
        #include "vr/CCVRGenericRenderer.h"

        #include "FairyGUI.h"
        #include "GLoader3D.h"
        #include "tween/EaseManager.h"
        #include "tween/GPath.h"
        #include "display/FUISprite.h"
        #include "utils/html/HtmlElement.h"
        #include "utils/html/HtmlObject.h"
        #include "utils/html/HtmlParser.h"

        #include "spine/spine-cocos2dx.h"

        #include "cclua/cclua.h"
        #include "lua-bindings/LuaCocosAdapter.h"

        #include "CCDragonBonesHeaders.h"

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
        '-I../../frameworks/cocos2d-x/cocos',
        '-I../../frameworks/cocos2d-x/cocos/editor-support',
        '-I../../frameworks/cocos2d-x/cocos/platform',
        '-I../../frameworks/cocos2d-x/external',
        '-I../../frameworks/libfairygui/Classes',
        '-I../../frameworks/libdragonbones/src',
        '-I../../frameworks/libxgame/src',
        '-I../../frameworks/libxgame/src/lua',
        '-I../../frameworks/plugins',
    },
}