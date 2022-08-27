clang {
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