return {
    HEADERS = [[
        #include "audio/include/AudioEngine.h"
        #include "audio/include/SimpleAudioEngine.h"
        #include "base/TGAlib.h"
        #include "cocos2d.h"
        #include "ui/CocosGUI.h"
        #include "ui/UIScrollViewBar.h"
        #include "vr/CCVRGenericHeadTracker.h"
        #include "vr/CCVRGenericRenderer.h"

        #include "FairyGUI.h"
        #include "tween/EaseManager.h"
        #include "tween/GPath.h"
        #include "display/FUISprite.h"

        #include "spine/spine-cocos2dx.h"

        #include "xgame/xfilesystem.h"
        #include "xgame/xfilefinder.h"
        #include "xgame/xruntime.h"
        #include "xgame/xpreferences.h"
        #include "xgame/xdownloader.h"
        #include "xgame/xrootscene.h"
        #include "xgame/xtimer.h"
        #include "lua-bindings/LuaCocosAdapter.h"

        #include "CCDragonBonesHeaders.h"
    ]],
    FLAGS = {
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
        '-I../../frameworks/libxgame/src/lua/src',

        '-x', 'c++', '-nostdinc', '-std=c++11',
        '-U__SSE__',
        '-DANDROID', '-target', 'armv7-none-linux-androideabi',

        '-idirafter', '${HOMEDIR}/include/c++',
        '-idirafter', '${HOMEDIR}/include/c',
        '-idirafter', '${HOMEDIR}/include/android-sysroot/x86_64-linux-android',
        '-idirafter', '${HOMEDIR}/include/android-sysroot',
    },
}