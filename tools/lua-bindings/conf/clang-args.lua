return {
    DEFINE = [[
        #undef __APPLE__
        #undef __SSE__
    ]],
    HEADERS = {
        'cocos2d.h',
        '3d/CC3DProgramInfo.h',
        '3d/CCBundle3D.h',
        'audio/include/AudioEngine.h',
        'base/TGAlib.h',
        'renderer/backend/Backend.h',
        'ui/CocosGUI.h',
        'ui/UIScrollViewBar.h',
        'navmesh/CCNavMesh.h',

        'FairyGUI.h',
        'tween/EaseManager.h',
        'tween/GPath.h',
        'display/FUISprite.h',

        'spine/spine-cocos2dx.h',

        'xgame/xfilesystem.h',
        'xgame/xruntime.h',
        'xgame/xpreferences.h',
        'xgame/xdownloader.h',
        'xgame/xrootscene.h',
        'xgame/xtimer.h',
        'lua-bindings/LuaCocosAdapter.h',
    },
    FLAGS = {
        '-DCC_CONSTRUCTOR_ACCESS=public',
        '-DCC_DLL=',
        '-DCC_ENABLE_SCRIPT_BINDING=0',
        '-DEXPORT_DLL=',
        '-DSP_API=',
        '-DSPINE_USE_STD_FUNCTION',
        '-I../../frameworks/cocos2d-x/cocos',
        '-I../../frameworks/cocos2d-x/cocos/editor-support',
        '-I../../frameworks/cocos2d-x/cocos/platform',
        '-I../../frameworks/cocos2d-x/external',
        '-I../../frameworks/libfairygui/Classes',
        '-I../../frameworks/libxgame/src',
    },
}