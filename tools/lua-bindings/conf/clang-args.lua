return {
    HEADERS = [[
        #include "cocos2d.h"
        #include "3d/CC3DProgramInfo.h"
        #include "3d/CCBundle3D.h"
        #include "audio/include/AudioEngine.h"
        #include "base/TGAlib.h"
        #include "renderer/backend/Backend.h"
        #include "ui/CocosGUI.h"
        #include "ui/UIScrollViewBar.h"
        #include "navmesh/CCNavMesh.h"

        // fairygui
        #include "FairyGUI.h"
        #include "tween/EaseManager.h"
        #include "tween/GPath.h"
        #include "display/FUISprite.h"

        // spine
        #include "spine/spine-cocos2dx.h"

        // dragonbones
        #include "CCDragonBonesHeaders.h"

        // xgame
        #include "xgame/xfilesystem.h"
        #include "xgame/xruntime.h"
        #include "xgame/xpreferences.h"
        #include "xgame/xdownloader.h"
        #include "xgame/xrootscene.h"
        #include "xgame/xtimer.h"
        #include "lua-bindings/LuaCocosAdapter.h"
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

        '-idirafter', 'bindings-generator/include/c++',
        '-idirafter', 'bindings-generator/include/c',
        '-idirafter', 'bindings-generator/include/android-sysroot/x86_64-linux-android',
        '-idirafter', 'bindings-generator/include/android-sysroot',
    },
}