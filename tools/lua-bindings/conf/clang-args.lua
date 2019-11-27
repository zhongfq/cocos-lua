return {
    DEFINE = [[
        #undef __APPLE__
        #undef __SSE__
    ]],
    HEADERS = {
        'audio/include/AudioEngine.h',
        'audio/include/SimpleAudioEngine.h',
        'base/TGAlib.h',
        'cocos2d.h',
        'ui/CocosGUI.h',
        'ui/UIScrollViewBar.h',
        'vr/CCVRGenericHeadTracker.h',
        'vr/CCVRGenericRenderer.h',

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

        'CCDragonBonesHeaders.h',
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
        '-I../../frameworks/libdragonbones/src',
        '-I../../frameworks/libfairygui/Classes',
        '-I../../frameworks/libxgame/src',
    },
}