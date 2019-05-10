local M = {}

local cls = class(M)
cls.CPPCLS = "cocos2d::TransitionScene::Orientation"
cls.LUACLS = "cc.TransitionScene.Orientation"
cls.enums [[
    LEFT_OVER
    RIGHT_OVER
    UP_OVER
    DOWN_OVER
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::TransitionScene"
cls.LUACLS = "cc.TransitionScene"
cls.SUPERCLS = "cc.Scene"
cls.funcs([[
    static TransitionScene * create(float t, @ref(map autoref) Scene *scene)
    void finish(void)
    void hideOutShowIn(void)
    Scene* getInScene()
    float getDuration()
]])
cls.props [[
    inScene
    duration
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::TransitionSceneOriented"
cls.LUACLS = "cc.TransitionSceneOriented"
cls.SUPERCLS = "cc.TransitionScene"
cls.funcs([[
    static TransitionSceneOriented * create(float t, @ref(map autoref) Scene* scene, TransitionScene::Orientation orientation)
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::TransitionRotoZoom"
cls.LUACLS = "cc.TransitionRotoZoom"
cls.SUPERCLS = "cc.TransitionScene"
cls.funcs([[
    static TransitionRotoZoom* create(float t, @ref(map autoref) Scene* scene)
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::TransitionJumpZoom"
cls.LUACLS = "cc.TransitionJumpZoom"
cls.SUPERCLS = "cc.TransitionScene"
cls.funcs([[
    static TransitionJumpZoom* create(float t, @ref(map autoref) Scene* scene)
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::TransitionMoveInL"
cls.LUACLS = "cc.TransitionMoveInL"
cls.SUPERCLS = "cc.TransitionScene"
cls.funcs([[
    static TransitionMoveInL* create(float t, @ref(map autoref) Scene* scene)
    ActionInterval* action(void)
    ActionInterval* easeActionWithAction(@ref(single action) ActionInterval * action)
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::TransitionMoveInR"
cls.LUACLS = "cc.TransitionMoveInR"
cls.SUPERCLS = "cc.TransitionMoveInL"
cls.funcs([[
    static TransitionMoveInR* create(float t, @ref(map autoref) Scene* scene)
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::TransitionMoveInT"
cls.LUACLS = "cc.TransitionMoveInT"
cls.SUPERCLS = "cc.TransitionMoveInL"
cls.funcs([[
    static TransitionMoveInT* create(float t, @ref(map autoref) Scene* scene)
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::TransitionMoveInB"
cls.LUACLS = "cc.TransitionMoveInB"
cls.SUPERCLS = "cc.TransitionMoveInL"
cls.funcs([[
    static TransitionMoveInB* create(float t, @ref(map autoref) Scene* scene)
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::TransitionSlideInL"
cls.LUACLS = "cc.TransitionSlideInL"
cls.SUPERCLS = "cc.TransitionScene"
cls.funcs([[
    static TransitionSlideInL* create(float t, @ref(map autoref) Scene* scene)
    ActionInterval* easeActionWithAction(@ref(single action)ActionInterval * action)
    ActionInterval* action(void)
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::TransitionSlideInR"
cls.LUACLS = "cc.TransitionSlideInR"
cls.SUPERCLS = "cc.TransitionSlideInL"
cls.funcs([[
    static TransitionSlideInR* create(float t, @ref(map autoref) Scene* scene)
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::TransitionSlideInB"
cls.LUACLS = "cc.TransitionSlideInB"
cls.SUPERCLS = "cc.TransitionSlideInL"
cls.funcs([[
    static TransitionSlideInB* create(float t, @ref(map autoref) Scene* scene)
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::TransitionSlideInT"
cls.LUACLS = "cc.TransitionSlideInT"
cls.SUPERCLS = "cc.TransitionSlideInL"
cls.funcs([[
    static TransitionSlideInT* create(float t, @ref(map autoref) Scene* scene)
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::TransitionShrinkGrow"
cls.LUACLS = "cc.TransitionShrinkGrow"
cls.SUPERCLS = "cc.TransitionScene"
cls.funcs([[
    static TransitionShrinkGrow* create(float t, @ref(map autoref) Scene* scene)
    ActionInterval* easeActionWithAction(@ref(single action) ActionInterval * action)
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::TransitionFlipX"
cls.LUACLS = "cc.TransitionFlipX"
cls.SUPERCLS = "cc.TransitionSceneOriented"
cls.funcs([[
    static TransitionFlipX* create(float t, @ref(map autoref) Scene* s, TransitionScene::Orientation o)
    static TransitionFlipX* create(float t, @ref(map autoref) Scene* s)
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::TransitionFlipY"
cls.LUACLS = "cc.TransitionFlipY"
cls.SUPERCLS = "cc.TransitionSceneOriented"
cls.funcs([[
    static TransitionFlipY* create(float t, @ref(map autoref) Scene* s, TransitionScene::Orientation o)
    static TransitionFlipY* create(float t, @ref(map autoref) Scene* s)
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::TransitionFlipAngular"
cls.LUACLS = "cc.TransitionFlipAngular"
cls.SUPERCLS = "cc.TransitionSceneOriented"
cls.funcs([[
    static TransitionFlipAngular* create(float t, @ref(map autoref) Scene* s, TransitionScene::Orientation o)
    static TransitionFlipAngular* create(float t, @ref(map autoref) Scene* s)
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::TransitionZoomFlipX"
cls.LUACLS = "cc.TransitionZoomFlipX"
cls.SUPERCLS = "cc.TransitionSceneOriented"
cls.funcs([[
    static TransitionZoomFlipX* create(float t, @ref(map autoref) Scene* s, TransitionScene::Orientation o)
    static TransitionZoomFlipX* create(float t, @ref(map autoref) Scene* s)
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::TransitionZoomFlipY"
cls.LUACLS = "cc.TransitionZoomFlipY"
cls.SUPERCLS = "cc.TransitionSceneOriented"
cls.funcs([[
    static TransitionZoomFlipY* create(float t, @ref(map autoref) Scene* s, TransitionScene::Orientation o)
    static TransitionZoomFlipY* create(float t, @ref(map autoref) Scene* s)
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::TransitionZoomFlipAngular"
cls.LUACLS = "cc.TransitionZoomFlipAngular"
cls.SUPERCLS = "cc.TransitionSceneOriented"
cls.funcs([[
    static TransitionZoomFlipAngular* create(float t, @ref(map autoref) Scene* s, TransitionScene::Orientation o)
    static TransitionZoomFlipAngular* create(float t, @ref(map autoref) Scene* s)
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::TransitionFade"
cls.LUACLS = "cc.TransitionFade"
cls.SUPERCLS = "cc.TransitionScene"
cls.funcs([[
    static TransitionFade* create(float duration, @ref(map autoref) Scene* scene, const Color3B& color)
    static TransitionFade* create(float duration, @ref(map autoref) Scene* scene)
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::TransitionCrossFade"
cls.LUACLS = "cc.TransitionCrossFade"
cls.SUPERCLS = "cc.TransitionScene"
cls.funcs([[
    static TransitionCrossFade* create(float t, @ref(map autoref) Scene* scene)
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::TransitionTurnOffTiles"
cls.LUACLS = "cc.TransitionTurnOffTiles"
cls.SUPERCLS = "cc.TransitionScene"
cls.funcs([[
    static TransitionTurnOffTiles* create(float t, @ref(map autoref) Scene* scene)
    ActionInterval * easeActionWithAction(@ref(single action) ActionInterval * action)
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::TransitionSplitCols"
cls.LUACLS = "cc.TransitionSplitCols"
cls.SUPERCLS = "cc.TransitionScene"
cls.funcs([[
    static TransitionSplitCols* create(float t, @ref(map autoref) Scene* scene)
    ActionInterval* action()
    ActionInterval * easeActionWithAction(@ref(single action) ActionInterval * action)
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::TransitionSplitRows"
cls.LUACLS = "cc.TransitionSplitRows"
cls.SUPERCLS = "cc.TransitionSplitCols"
cls.funcs([[
    static TransitionSplitRows* create(float t, @ref(map autoref) Scene* scene)
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::TransitionFadeTR"
cls.LUACLS = "cc.TransitionFadeTR"
cls.SUPERCLS = "cc.TransitionScene"
cls.funcs([[
    static TransitionFadeTR* create(float t, @ref(map autoref) Scene* scene)
    ActionInterval* actionWithSize(const Size& size)
    ActionInterval* easeActionWithAction(@ref(single action) ActionInterval * action)
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::TransitionFadeBL"
cls.LUACLS = "cc.TransitionFadeBL"
cls.SUPERCLS = "cc.TransitionFadeTR"
cls.funcs([[
    static TransitionFadeBL* create(float t, @ref(map autoref) Scene* scene)
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::TransitionFadeUp"
cls.LUACLS = "cc.TransitionFadeUp"
cls.SUPERCLS = "cc.TransitionFadeTR"
cls.funcs([[
    static TransitionFadeUp* create(float t, @ref(map autoref) Scene* scene)
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::TransitionFadeDown"
cls.LUACLS = "cc.TransitionFadeDown"
cls.SUPERCLS = "cc.TransitionFadeTR"
cls.funcs([[
    static TransitionFadeDown* create(float t, @ref(map autoref) Scene* scene)
]])

return M