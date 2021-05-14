-- AUTO BUILD, DON'T MODIFY!

dofile "autobuild/cocos2d-studio-types.lua"

local olua = require "olua"
local typeconv = olua.typeconv
local typecls = olua.typecls
local cls = nil
local M = {}

M.NAME = "cocos2d_studio"
M.PATH = "../../frameworks/libxgame/src/lua-bindings"
M.HEADERS = [[
    #include "lua-bindings/lua_conv.h"
    #include "lua-bindings/lua_conv_manual.h"
    #include "cclua/xlua.h"
    #include "cocos2d.h"
    #include "editor-support/cocostudio/CocoStudio.h"
]]
M.CHUNK = [[
    static std::string makeFrameEndCallbackTag(lua_Integer index, const std::string &key)
    {
        if (index < 0) {
            return "frameEnd.";
        } else {
            return "frameEnd." + std::to_string((int)index) + "." + key;
        }
    }

    static std::string makeFrameEndCallbackTag(cocostudio::timeline::ActionTimeline *self, const std::string &animationName)
    {
        auto info = self->getAnimationInfo(animationName);
        return makeFrameEndCallbackTag((lua_Integer)info.endIndex, animationName);
    }
]]

M.CONVS = {
    typeconv {
        CPPCLS = 'cocostudio::timeline::AnimationInfo',
        IFDEF = nil,
        DEF = [[
            std::string name;
            int startIndex;
            int endIndex;
        ]],
    },
}

M.CLASSES = {}

cls = typecls 'cocos2d::CSLoader'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.func(nil, 'static cocos2d::CSLoader *getInstance()')
cls.func(nil, 'static void destroyInstance()')
cls.func(nil, 'CSLoader()')
cls.func(nil, 'void init()')
cls.func(nil, 'static cocostudio::timeline::ActionTimeline *createTimeline(const std::string &filename)', 'static cocostudio::timeline::ActionTimeline *createTimeline(const cocos2d::Data &data, const std::string &filename)')
cls.func(nil, 'cocos2d::Node *createNodeFromJson(const std::string &filename)')
cls.func(nil, 'cocos2d::Node *loadNodeWithFile(const std::string &fileName)')
cls.func(nil, 'cocos2d::Node *loadNodeWithContent(const std::string &content)')
cls.func(nil, 'void setRecordJsonPath(bool record)')
cls.func(nil, 'bool isRecordJsonPath()')
cls.func(nil, 'void setJsonPath(std::string jsonPath)')
cls.func(nil, 'std::string getJsonPath()')
cls.func(nil, 'cocos2d::Node *createNodeWithFlatBuffersFile(const std::string &filename)')
cls.func(nil, 'cocos2d::Node *nodeWithFlatBuffersFile(const std::string &fileName)')
cls.func(nil, 'bool bindCallback(const std::string &callbackName, const std::string &callbackType, cocos2d::ui::Widget *sender, cocos2d::Node *handler)')
cls.func(nil, 'cocos2d::Node *createNodeWithFlatBuffersForSimulator(const std::string &filename)')
cls.callback {
    FUNCS =  {
        'static cocos2d::Node *createNode(const std::string &filename)',
        'static cocos2d::Node *createNode(const std::string &filename, @local const std::function<void (cocos2d::Ref *)> &callback)',
        'static cocos2d::Node *createNode(const cocos2d::Data &data)',
        'static cocos2d::Node *createNode(const cocos2d::Data &data, @local const std::function<void (cocos2d::Ref *)> &callback)'
    },
    TAG_MAKER = 'createNode',
    TAG_MODE = 'OLUA_TAG_NEW',
    TAG_STORE = nil,
    TAG_SCOPE = 'function',
}
cls.callback {
    FUNCS =  {
        'static cocos2d::Node *createNodeWithVisibleSize(const std::string &filename)',
        'static cocos2d::Node *createNodeWithVisibleSize(const std::string &filename, @local const std::function<void (cocos2d::Ref *)> &callback)'
    },
    TAG_MAKER = 'createNodeWithVisibleSize',
    TAG_MODE = 'OLUA_TAG_NEW',
    TAG_STORE = nil,
    TAG_SCOPE = 'function',
}
cls.prop('instance', nil, nil)
cls.prop('recordJsonPath', nil, nil)
cls.prop('jsonPath', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocostudio::MovementEventType'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.enum('START', 'cocostudio::MovementEventType::START')
cls.enum('COMPLETE', 'cocostudio::MovementEventType::COMPLETE')
cls.enum('LOOP_COMPLETE', 'cocostudio::MovementEventType::LOOP_COMPLETE')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocostudio::DisplayType'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.enum('CS_DISPLAY_SPRITE', 'cocostudio::DisplayType::CS_DISPLAY_SPRITE')
cls.enum('CS_DISPLAY_ARMATURE', 'cocostudio::DisplayType::CS_DISPLAY_ARMATURE')
cls.enum('CS_DISPLAY_PARTICLE', 'cocostudio::DisplayType::CS_DISPLAY_PARTICLE')
cls.enum('CS_DISPLAY_MAX', 'cocostudio::DisplayType::CS_DISPLAY_MAX')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocostudio::ActionFrame'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.func(nil, 'ActionFrame()')
cls.func(nil, 'void setFrameIndex(int index)')
cls.func(nil, 'int getFrameIndex()')
cls.func(nil, 'void setFrameTime(float fTime)')
cls.func(nil, 'float getFrameTime()')
cls.func(nil, 'void setFrameType(int frameType)')
cls.func(nil, 'int getFrameType()')
cls.func(nil, 'void setEasingType(int easingType)')
cls.func(nil, 'int getEasingType()')
cls.func(nil, '@addref(action |) cocos2d::ActionInterval *getAction(float duration)', '@addref(action |) cocos2d::ActionInterval *getAction(float duration, cocostudio::ActionFrame *srcFrame)')
cls.func(nil, 'void setEasingParameter(std::vector<float> &parameter)')
cls.prop('frameIndex', nil, nil)
cls.prop('frameTime', nil, nil)
cls.prop('frameType', nil, nil)
cls.prop('easingType', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocostudio::ActionFadeFrame'
cls.SUPERCLS = 'cocostudio::ActionFrame'
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.func(nil, 'ActionFadeFrame()')
cls.func(nil, 'void setOpacity(int opacity)')
cls.func(nil, 'int getOpacity()')
cls.prop('opacity', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocostudio::ActionFrameEasing'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.func(nil, 'ActionFrameEasing()')
cls.func(nil, 'float bounceTime(float t)')
cls.func(nil, 'float easeValue(float t)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocostudio::ActionMoveFrame'
cls.SUPERCLS = 'cocostudio::ActionFrame'
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.func(nil, 'ActionMoveFrame()')
cls.func(nil, 'void setPosition(cocos2d::Vec2 pos)')
cls.func(nil, 'cocos2d::Vec2 getPosition()')
cls.prop('position', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocostudio::ActionRotationFrame'
cls.SUPERCLS = 'cocostudio::ActionFrame'
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.func(nil, 'ActionRotationFrame()')
cls.func(nil, 'void setRotation(float rotation)')
cls.func(nil, 'float getRotation()')
cls.prop('rotation', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocostudio::ActionScaleFrame'
cls.SUPERCLS = 'cocostudio::ActionFrame'
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.func(nil, 'ActionScaleFrame()')
cls.func(nil, 'void setScaleX(float scaleX)')
cls.func(nil, 'float getScaleX()')
cls.func(nil, 'void setScaleY(float scaleY)')
cls.func(nil, 'float getScaleY()')
cls.prop('scaleX', nil, nil)
cls.prop('scaleY', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocostudio::ActionTintFrame'
cls.SUPERCLS = 'cocostudio::ActionFrame'
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.func(nil, 'ActionTintFrame()')
cls.func(nil, 'void setColor(cocos2d::Color3B ccolor)')
cls.func(nil, 'cocos2d::Color3B getColor()')
cls.prop('color', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocostudio::AnimationData'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.func(nil, 'static cocostudio::AnimationData *create()')
cls.func(nil, 'AnimationData()')
cls.func(nil, 'void addMovement(cocostudio::MovementData *movData)')
cls.func(nil, 'cocostudio::MovementData *getMovement(const std::string &movementName)')
cls.func(nil, 'ssize_t getMovementCount()')
cls.var('name', 'std::string name')
cls.var('movementDataDic', 'cocos2d::Map<std::string, MovementData *> movementDataDic')
cls.var('movementNames', 'std::vector<std::string> movementNames')
cls.prop('movementCount', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocostudio::Armature'
cls.SUPERCLS = 'cocos2d::Node'
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.func(nil, 'static cocostudio::Armature *create()', 'static cocostudio::Armature *create(const std::string &name)', 'static cocostudio::Armature *create(const std::string &name, cocostudio::Bone *parentBone)')
cls.func(nil, 'Armature()')
cls.func(nil, '@using bool init()', 'bool init(const std::string &name)', 'bool init(const std::string &name, cocostudio::Bone *parentBone)')
cls.func(nil, 'void addBone(cocostudio::Bone *bone, const std::string &parentName)')
cls.func(nil, 'cocostudio::Bone *getBone(const std::string &name)')
cls.func(nil, 'void changeBoneParent(cocostudio::Bone *bone, const std::string &parentName)')
cls.func(nil, 'void removeBone(cocostudio::Bone *bone, bool recursion)')
cls.func(nil, 'const cocos2d::Map<std::string, Bone *> &getBoneDic()')
cls.func(nil, 'cocostudio::Bone *getBoneAtPoint(float x, float y)')
cls.func(nil, 'void setBlendFunc(const cocos2d::BlendFunc &blendFunc)')
cls.func(nil, 'const cocos2d::BlendFunc &getBlendFunc()')
cls.func(nil, 'void updateOffsetPoint()')
cls.func(nil, 'const cocos2d::Vec2 &getOffsetPoints()')
cls.func(nil, 'void setAnimation(cocostudio::ArmatureAnimation *animation)')
cls.func(nil, 'cocostudio::ArmatureAnimation *getAnimation()')
cls.func(nil, 'bool getArmatureTransformDirty()')
cls.func(nil, 'void setArmatureData(cocostudio::ArmatureData *armatureData)')
cls.func(nil, 'cocostudio::ArmatureData *getArmatureData()')
cls.func(nil, 'void setParentBone(cocostudio::Bone *parentBone)')
cls.func(nil, 'cocostudio::Bone *getParentBone()')
cls.func(nil, 'void setVersion(float version)')
cls.func(nil, 'float getVersion()')
cls.func(nil, 'void setBatchNode(cocostudio::BatchNode *batchNode)')
cls.func(nil, 'cocostudio::BatchNode *getBatchNode()')
cls.prop('boneDic', nil, nil)
cls.prop('blendFunc', nil, nil)
cls.prop('offsetPoints', nil, nil)
cls.prop('animation', nil, nil)
cls.prop('armatureTransformDirty', nil, nil)
cls.prop('armatureData', nil, nil)
cls.prop('parentBone', nil, nil)
cls.prop('version', nil, nil)
cls.prop('batchNode', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocostudio::ProcessBase'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.func(nil, 'ProcessBase()')
cls.func(nil, 'void play(int durationTo, int durationTween, int loop, int tweenEasing)')
cls.func(nil, 'void pause()')
cls.func(nil, 'void resume()')
cls.func(nil, 'void stop()')
cls.func(nil, 'void update(float dt)')
cls.func(nil, 'int getCurrentFrameIndex()')
cls.func(nil, 'void setProcessScale(float processScale)')
cls.func(nil, 'float getProcessScale()')
cls.func(nil, 'void setIsPause(bool pause)')
cls.func(nil, 'bool isPause()')
cls.func(nil, 'void setIsComplete(bool complete)')
cls.func(nil, 'bool isComplete()')
cls.func(nil, 'void setIsPlaying(bool playing)')
cls.func(nil, 'bool isPlaying()')
cls.func(nil, 'float getCurrentPercent()')
cls.func(nil, 'int getRawDuration()')
cls.prop('currentFrameIndex', nil, nil)
cls.prop('processScale', nil, nil)
cls.prop('pause', nil, nil)
cls.prop('complete', nil, nil)
cls.prop('playing', nil, nil)
cls.prop('currentPercent', nil, nil)
cls.prop('rawDuration', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocostudio::ActionManagerEx'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.func(nil, 'ActionManagerEx()')
cls.func(nil, 'static cocostudio::ActionManagerEx *getInstance()')
cls.func(nil, 'static void destroyInstance()')
cls.func(nil, 'cocostudio::ActionObject *getActionByName(const char *jsonName, const char *actionName)')
cls.func(nil, 'cocostudio::ActionObject *playActionByName(const char *jsonName, const char *actionName)', 'cocostudio::ActionObject *playActionByName(const char *jsonName, const char *actionName, cocos2d::CallFunc *func)')
cls.func(nil, 'cocostudio::ActionObject *stopActionByName(const char *jsonName, const char *actionName)')
cls.func(nil, 'void releaseActions()')
cls.func(nil, 'int getStudioVersionNumber()')
cls.prop('instance', nil, nil)
cls.prop('studioVersionNumber', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocostudio::ActionNode'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.func(nil, 'ActionNode()')
cls.func(nil, 'void setUnitTime(float fTime)')
cls.func(nil, 'float getUnitTime()')
cls.func(nil, 'void setActionTag(int tag)')
cls.func(nil, 'int getActionTag()')
cls.func(nil, 'void setObject(cocos2d::Ref *node)')
cls.func(nil, 'cocos2d::Ref *getObject()')
cls.func(nil, 'void insertFrame(int index, cocostudio::ActionFrame *frame)')
cls.func(nil, 'void addFrame(cocostudio::ActionFrame *frame)')
cls.func(nil, 'void deleteFrame(cocostudio::ActionFrame *frame)')
cls.func(nil, 'void clearAllFrame()')
cls.func(nil, 'int getFirstFrameIndex()')
cls.func(nil, 'int getLastFrameIndex()')
cls.func(nil, 'bool updateActionToTimeLine(float fTime)')
cls.func(nil, 'void playAction()')
cls.func(nil, 'void stopAction()')
cls.func(nil, 'bool isActionDoneOnce()')
cls.prop('unitTime', nil, nil)
cls.prop('actionTag', nil, nil)
cls.prop('object', nil, nil)
cls.prop('firstFrameIndex', nil, nil)
cls.prop('lastFrameIndex', nil, nil)
cls.prop('actionDoneOnce', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocostudio::ActionObject'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.func(nil, 'ActionObject()')
cls.func(nil, 'void setName(const char *name)')
cls.func(nil, 'const char *getName()')
cls.func(nil, 'void setLoop(bool bLoop)')
cls.func(nil, 'bool getLoop()')
cls.func(nil, 'void setUnitTime(float fTime)')
cls.func(nil, 'float getUnitTime()')
cls.func(nil, 'void setCurrentTime(float fTime)')
cls.func(nil, 'float getCurrentTime()')
cls.func(nil, 'float getTotalTime()')
cls.func(nil, 'bool isPlaying()')
cls.func(nil, 'void play()', 'void play(cocos2d::CallFunc *func)')
cls.func(nil, 'void pause()')
cls.func(nil, 'void stop()')
cls.func(nil, 'void addActionNode(cocostudio::ActionNode *node)')
cls.func(nil, 'void removeActionNode(cocostudio::ActionNode *node)')
cls.func(nil, 'void updateToFrameByTime(float fTime)')
cls.func(nil, 'void simulationActionUpdate(float dt)')
cls.prop('name', nil, nil)
cls.prop('loop', nil, nil)
cls.prop('unitTime', nil, nil)
cls.prop('currentTime', nil, nil)
cls.prop('totalTime', nil, nil)
cls.prop('playing', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocostudio::ArmatureAnimation'
cls.SUPERCLS = 'cocostudio::ProcessBase'
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.func(nil, 'static cocostudio::ArmatureAnimation *create(cocostudio::Armature *armature)')
cls.func(nil, 'ArmatureAnimation()')
cls.func(nil, 'bool init(cocostudio::Armature *armature)')
cls.func(nil, 'void setSpeedScale(float speedScale)')
cls.func(nil, 'float getSpeedScale()')
cls.func(nil, 'void play(const std::string &animationName, @optional int durationTo, @optional int loop)', '@using void play(int durationTo, int durationTween, int loop, int tweenEasing)')
cls.func(nil, 'void playWithIndex(int animationIndex, @optional int durationTo, @optional int loop)')
cls.func(nil, 'void playWithNames(const std::vector<std::string> &movementNames, @optional int durationTo, @optional bool loop)')
cls.func(nil, 'void playWithIndexes(const std::vector<int> &movementIndexes, @optional int durationTo, @optional bool loop)')
cls.func(nil, 'void gotoAndPlay(int frameIndex)')
cls.func(nil, 'void gotoAndPause(int frameIndex)')
cls.func(nil, 'ssize_t getMovementCount()')
cls.func(nil, 'std::string getCurrentMovementID()')
cls.func(nil, 'void setAnimationData(cocostudio::AnimationData *data)')
cls.func(nil, 'cocostudio::AnimationData *getAnimationData()')
cls.func(nil, 'cocos2d::Ref *getUserObject()')
cls.func(nil, 'void setUserObject(cocos2d::Ref *userObject)')
cls.callback {
    FUNCS =  {
        'void setMovementEventCallFunc(@nullable @local std::function<void (cocostudio::Armature *, cocostudio::MovementEventType, const std::string &)> listener)'
    },
    TAG_MAKER = 'MovementEventCallFunc',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        'void setFrameEventCallFunc(@nullable @local std::function<void (cocostudio::Bone *, const std::string &, int, int)> listener)'
    },
    TAG_MAKER = 'FrameEventCallFunc',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.prop('speedScale', nil, nil)
cls.prop('movementCount', nil, nil)
cls.prop('currentMovementID', nil, nil)
cls.prop('animationData', nil, nil)
cls.prop('userObject', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocostudio::ArmatureData'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.func(nil, 'static cocostudio::ArmatureData *create()')
cls.func(nil, 'ArmatureData()')
cls.func(nil, 'bool init()')
cls.func(nil, 'void addBoneData(cocostudio::BoneData *boneData)')
cls.func(nil, 'cocostudio::BoneData *getBoneData(const std::string &boneName)')
cls.var('name', 'std::string name')
cls.var('boneDataDic', 'cocos2d::Map<std::string, BoneData *> boneDataDic')
cls.var('dataVersion', 'float dataVersion')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocostudio::ArmatureDataManager'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.func(nil, 'static cocostudio::ArmatureDataManager *getInstance()')
cls.func(nil, 'static void destroyInstance()')
cls.func(nil, 'bool init()')
cls.func(nil, 'void addArmatureData(const std::string &id, cocostudio::ArmatureData *armatureData, @optional const std::string &configFilePath)')
cls.func(nil, 'cocostudio::ArmatureData *getArmatureData(const std::string &id)')
cls.func(nil, 'void removeArmatureData(const std::string &id)')
cls.func(nil, 'void addAnimationData(const std::string &id, cocostudio::AnimationData *animationData, @optional const std::string &configFilePath)')
cls.func(nil, 'cocostudio::AnimationData *getAnimationData(const std::string &id)')
cls.func(nil, 'void removeAnimationData(const std::string &id)')
cls.func(nil, 'void addTextureData(const std::string &id, cocostudio::TextureData *textureData, @optional const std::string &configFilePath)')
cls.func(nil, 'cocostudio::TextureData *getTextureData(const std::string &id)')
cls.func(nil, 'void removeTextureData(const std::string &id)')
cls.func(nil, 'void addArmatureFileInfo(const std::string &configFilePath)', 'void addArmatureFileInfo(const std::string &imagePath, const std::string &plistPath, const std::string &configFilePath)')
cls.func(nil, 'void addSpriteFrameFromFile(const std::string &plistPath, const std::string &imagePath, @optional const std::string &configFilePath)')
cls.func(nil, 'void removeArmatureFileInfo(const std::string &configFilePath)')
cls.func(nil, 'bool isAutoLoadSpriteFile()')
cls.func(nil, 'const cocos2d::Map<std::string, ArmatureData *> &getArmatureDatas()')
cls.func(nil, 'const cocos2d::Map<std::string, AnimationData *> &getAnimationDatas()')
cls.func(nil, 'const cocos2d::Map<std::string, TextureData *> &getTextureDatas()')
cls.prop('instance', nil, nil)
cls.prop('autoLoadSpriteFile', nil, nil)
cls.prop('armatureDatas', nil, nil)
cls.prop('animationDatas', nil, nil)
cls.prop('textureDatas', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocostudio::DisplayData'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.func(nil, 'static cocostudio::DisplayData *create()')
cls.func(nil, 'static std::string changeDisplayToTexture(const std::string &displayName)')
cls.func(nil, 'DisplayData()')
cls.func(nil, 'void copy(cocostudio::DisplayData *displayData)')
cls.var('displayType', 'cocostudio::DisplayType displayType')
cls.var('displayName', 'std::string displayName')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocostudio::ArmatureDisplayData'
cls.SUPERCLS = 'cocostudio::DisplayData'
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.func(nil, 'static cocostudio::ArmatureDisplayData *create()')
cls.func(nil, 'ArmatureDisplayData()')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocostudio::ArmatureMovementDispatcher'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocostudio::BaseData'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.func(nil, 'static cocostudio::BaseData *create()')
cls.func(nil, 'BaseData()')
cls.func(nil, 'void copy(const cocostudio::BaseData *node)')
cls.func(nil, 'void subtract(cocostudio::BaseData *from, cocostudio::BaseData *to, bool limit)')
cls.func(nil, 'void setColor(const cocos2d::Color4B &color)')
cls.func(nil, 'cocos2d::Color4B getColor()')
cls.var('x', 'float x')
cls.var('y', 'float y')
cls.var('zOrder', 'int zOrder')
cls.var('skewX', 'float skewX')
cls.var('skewY', 'float skewY')
cls.var('scaleX', 'float scaleX')
cls.var('scaleY', 'float scaleY')
cls.var('tweenRotate', 'float tweenRotate')
cls.var('isUseColorInfo', 'bool isUseColorInfo')
cls.var('a', 'int a')
cls.var('r', 'int r')
cls.var('g', 'int g')
cls.var('b', 'int b')
cls.prop('color', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocostudio::BaseTriggerAction'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.func(nil, 'bool init()')
cls.func(nil, 'void done()')
cls.func(nil, 'void removeAll()')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocostudio::BaseTriggerCondition'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.func(nil, 'bool init()')
cls.func(nil, 'bool detect()')
cls.func(nil, 'void removeAll()')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocostudio::BatchNode'
cls.SUPERCLS = 'cocos2d::Node'
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.func(nil, 'static cocostudio::BatchNode *create()')
cls.func(nil, 'BatchNode()')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocostudio::Bone'
cls.SUPERCLS = 'cocos2d::Node'
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.func(nil, 'static cocostudio::Bone *create()', 'static cocostudio::Bone *create(const std::string &name)')
cls.func(nil, 'Bone()')
cls.func(nil, '@using bool init()', 'bool init(const std::string &name)')
cls.func(nil, 'void addDisplay(cocostudio::DisplayData *displayData, int index)', 'void addDisplay(cocos2d::Node *display, int index)')
cls.func(nil, 'void removeDisplay(int index)')
cls.func(nil, 'void changeDisplayWithIndex(int index, bool force)')
cls.func(nil, 'void changeDisplayWithName(const std::string &name, bool force)')
cls.func(nil, 'void addChildBone(cocostudio::Bone *child)')
cls.func(nil, 'void setParentBone(cocostudio::Bone *parent)')
cls.func(nil, 'cocostudio::Bone *getParentBone()')
cls.func(nil, '@delref(children | parent) void removeFromParent(bool recursion)', '@using @delref(children | parent) void removeFromParent()')
cls.func(nil, 'void removeChildBone(cocostudio::Bone *bone, bool recursion)')
cls.func(nil, 'void updateColor()')
cls.func(nil, 'void updateZOrder()')
cls.func(nil, 'void setLocalZOrder(int zOrder)')
cls.func(nil, 'cocostudio::Tween *getTween()')
cls.func(nil, 'void setTransformDirty(bool dirty)')
cls.func(nil, 'bool isTransformDirty()')
cls.func(nil, 'cocos2d::Mat4 getNodeToArmatureTransform()')
cls.func(nil, 'cocos2d::Node *getDisplayRenderNode()')
cls.func(nil, 'cocostudio::DisplayType getDisplayRenderNodeType()')
cls.func(nil, 'cocostudio::ColliderDetector *getColliderDetector()')
cls.func(nil, 'void setBoneData(cocostudio::BoneData *boneData)')
cls.func(nil, 'cocostudio::BoneData *getBoneData()')
cls.func(nil, 'void setArmature(cocostudio::Armature *armature)')
cls.func(nil, 'cocostudio::Armature *getArmature()')
cls.func(nil, 'void setChildArmature(cocostudio::Armature *childArmature)')
cls.func(nil, 'cocostudio::Armature *getChildArmature()')
cls.func(nil, 'cocostudio::DisplayManager *getDisplayManager()')
cls.func(nil, 'void setIgnoreMovementBoneData(bool ignore)')
cls.func(nil, 'bool isIgnoreMovementBoneData()')
cls.func(nil, 'void setBlendFunc(const cocos2d::BlendFunc &blendFunc)')
cls.func(nil, 'cocos2d::BlendFunc getBlendFunc()')
cls.func(nil, 'void setBlendDirty(bool dirty)')
cls.func(nil, 'bool isBlendDirty()')
cls.func(nil, 'cocostudio::FrameData *getTweenData()')
cls.func(nil, 'cocostudio::BaseData *getWorldInfo()')
cls.prop('parentBone', nil, nil)
cls.prop('tween', nil, nil)
cls.prop('transformDirty', nil, nil)
cls.prop('nodeToArmatureTransform', nil, nil)
cls.prop('displayRenderNode', nil, nil)
cls.prop('displayRenderNodeType', nil, nil)
cls.prop('colliderDetector', nil, nil)
cls.prop('boneData', nil, nil)
cls.prop('armature', nil, nil)
cls.prop('childArmature', nil, nil)
cls.prop('displayManager', nil, nil)
cls.prop('ignoreMovementBoneData', nil, nil)
cls.prop('blendFunc', nil, nil)
cls.prop('blendDirty', nil, nil)
cls.prop('tweenData', nil, nil)
cls.prop('worldInfo', nil, nil)
cls.insert('removeFromParent', {
    BEFORE = [[
        if (!self->getParent()) {
            return 0;
        }
        olua_push_cppobj<cocos2d::Node>(L, self->getParent());
        int parent = lua_gettop(L);
    ]],
    AFTER = nil,
    CALLBACK_BEFORE = nil,
    CALLBACK_AFTER = nil,
})
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocostudio::BoneData'
cls.SUPERCLS = 'cocostudio::BaseData'
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.func(nil, 'static cocostudio::BoneData *create()')
cls.func(nil, 'BoneData()')
cls.func(nil, 'bool init()')
cls.func(nil, 'void addDisplayData(cocostudio::DisplayData *displayData)')
cls.func(nil, 'cocostudio::DisplayData *getDisplayData(int index)')
cls.var('name', 'std::string name')
cls.var('parentName', 'std::string parentName')
cls.var('displayDataList', 'cocos2d::Vector<DisplayData *> displayDataList')
cls.var('boneDataTransform', 'cocos2d::AffineTransform boneDataTransform')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocostudio::CocoLoader'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocostudio::ColliderBody'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.func(nil, 'ColliderBody(cocostudio::ContourData *contourData)')
cls.func(nil, 'cocostudio::ContourData *getContourData()')
cls.func(nil, 'const std::vector<cocos2d::Vec2> &getCalculatedVertexList()')
cls.prop('contourData', nil, nil)
cls.prop('calculatedVertexList', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocostudio::ColliderDetector'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.func(nil, 'static cocostudio::ColliderDetector *create()', 'static cocostudio::ColliderDetector *create(cocostudio::Bone *bone)')
cls.func(nil, 'ColliderDetector()')
cls.func(nil, 'bool init()', 'bool init(cocostudio::Bone *bone)')
cls.func(nil, 'void addContourData(cocostudio::ContourData *contourData)')
cls.func(nil, 'void addContourDataList(cocos2d::Vector<ContourData *> &contourDataList)')
cls.func(nil, 'void removeContourData(cocostudio::ContourData *contourData)')
cls.func(nil, 'void removeAll()')
cls.func(nil, 'void updateTransform(cocos2d::Mat4 &t)')
cls.func(nil, 'void setActive(bool active)')
cls.func(nil, 'bool getActive()')
cls.func(nil, 'const cocos2d::Vector<ColliderBody *> &getColliderBodyList()')
cls.func(nil, 'void setBone(cocostudio::Bone *bone)')
cls.func(nil, 'cocostudio::Bone *getBone()')
cls.prop('active', nil, nil)
cls.prop('colliderBodyList', nil, nil)
cls.prop('bone', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocostudio::ColliderFilter'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocostudio::ComAttribute'
cls.SUPERCLS = 'cocos2d::Component'
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.const('COMPONENT_NAME', 'cocostudio::ComAttribute::COMPONENT_NAME', 'const std::string')
cls.func(nil, 'static cocos2d::Ref *createInstance()')
cls.func(nil, 'ComAttribute()')
cls.func(nil, 'static cocostudio::ComAttribute *create()')
cls.func(nil, 'void setInt(const std::string &key, int value)')
cls.func(nil, 'void setFloat(const std::string &key, float value)')
cls.func(nil, 'void setBool(const std::string &key, bool value)')
cls.func(nil, 'void setString(const std::string &key, const std::string &value)')
cls.func(nil, 'int getInt(const std::string &key, @optional int def)')
cls.func(nil, 'float getFloat(const std::string &key, @optional float def)')
cls.func(nil, 'bool getBool(const std::string &key, @optional bool def)')
cls.func(nil, 'std::string getString(const std::string &key, @optional const std::string &def)')
cls.func(nil, 'bool parse(const std::string &jsonFile)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocostudio::ComAudio'
cls.SUPERCLS = 'cocos2d::Component'
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.const('COMPONENT_NAME', 'cocostudio::ComAudio::COMPONENT_NAME', 'const std::string')
cls.func(nil, 'static cocos2d::Ref *createInstance()')
cls.func(nil, 'ComAudio()')
cls.func(nil, 'static cocostudio::ComAudio *create()')
cls.func(nil, 'void end()')
cls.func(nil, 'void preloadBackgroundMusic(const char *pszFilePath)')
cls.func(nil, 'void playBackgroundMusic(const char *pszFilePath, bool bLoop)', 'void playBackgroundMusic(const char *pszFilePath)', 'void playBackgroundMusic()')
cls.func(nil, 'void stopBackgroundMusic(bool bReleaseData)', 'void stopBackgroundMusic()')
cls.func(nil, 'void pauseBackgroundMusic()')
cls.func(nil, 'void resumeBackgroundMusic()')
cls.func(nil, 'void rewindBackgroundMusic()')
cls.func(nil, 'bool willPlayBackgroundMusic()')
cls.func(nil, 'bool isBackgroundMusicPlaying()')
cls.func(nil, 'float getBackgroundMusicVolume()')
cls.func(nil, 'void setBackgroundMusicVolume(float volume)')
cls.func(nil, 'float getEffectsVolume()')
cls.func(nil, 'void setEffectsVolume(float volume)')
cls.func(nil, 'unsigned int playEffect(const char *pszFilePath, bool bLoop)', 'unsigned int playEffect(const char *pszFilePath)', 'unsigned int playEffect()')
cls.func(nil, 'void pauseEffect(unsigned int nSoundId)')
cls.func(nil, 'void pauseAllEffects()')
cls.func(nil, 'void resumeEffect(unsigned int nSoundId)')
cls.func(nil, 'void resumeAllEffects()')
cls.func(nil, 'void stopEffect(unsigned int nSoundId)')
cls.func(nil, 'void stopAllEffects()')
cls.func(nil, 'void preloadEffect(const char *pszFilePath)')
cls.func(nil, 'void unloadEffect(const char *pszFilePath)')
cls.func(nil, 'void setFile(const char *pszFilePath)')
cls.func(nil, 'const char *getFile()')
cls.func(nil, 'void setLoop(bool bLoop)')
cls.func(nil, 'bool isLoop()')
cls.func(nil, 'void start()')
cls.func(nil, 'void stop()')
cls.prop('backgroundMusicPlaying', nil, nil)
cls.prop('backgroundMusicVolume', nil, nil)
cls.prop('effectsVolume', nil, nil)
cls.prop('file', nil, nil)
cls.prop('loop', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocostudio::ComController'
cls.SUPERCLS = 'cocos2d::Component'
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.const('COMPONENT_NAME', 'cocostudio::ComController::COMPONENT_NAME', 'const std::string')
cls.func(nil, 'static cocos2d::Ref *createInstance()')
cls.func(nil, 'ComController()')
cls.func(nil, 'static cocostudio::ComController *create()')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocostudio::ComRender'
cls.SUPERCLS = 'cocos2d::Component'
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.const('COMPONENT_NAME', 'cocostudio::ComRender::COMPONENT_NAME', 'const std::string')
cls.func(nil, 'static cocos2d::Ref *createInstance()')
cls.func(nil, 'static cocostudio::ComRender *create()', 'static cocostudio::ComRender *create(cocos2d::Node *node, const char *comName)')
cls.func(nil, 'cocos2d::Node *getNode()')
cls.func(nil, 'void setNode(cocos2d::Node *node)')
cls.func(nil, 'ComRender()', 'ComRender(cocos2d::Node *node, const char *comName)')
cls.prop('node', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocostudio::ContourData'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.func(nil, 'static cocostudio::ContourData *create()')
cls.func(nil, 'ContourData()')
cls.func(nil, 'bool init()')
cls.func(nil, 'void addVertex(cocos2d::Vec2 &vertex)')
cls.var('vertexList', 'std::vector<cocos2d::Vec2> vertexList')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocostudio::DataReaderHelper'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.func(nil, 'static cocostudio::DataReaderHelper *getInstance()')
cls.func(nil, 'static void setPositionReadScale(float scale)')
cls.func(nil, 'static float getPositionReadScale()')
cls.func(nil, 'static void purge()')
cls.func(nil, 'DataReaderHelper()')
cls.func(nil, 'void addDataFromFile(const std::string &filePath)')
cls.func(nil, 'void addDataAsyncCallBack(float dt)')
cls.func(nil, 'void removeConfigFile(const std::string &configFile)')
cls.prop('instance', nil, nil)
cls.prop('positionReadScale', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocostudio::DecorativeDisplay'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.func(nil, 'static cocostudio::DecorativeDisplay *create()')
cls.func(nil, 'DecorativeDisplay()')
cls.func(nil, 'bool init()')
cls.func(nil, 'void setDisplay(cocos2d::Node *display)')
cls.func(nil, 'cocos2d::Node *getDisplay()')
cls.func(nil, 'void setDisplayData(cocostudio::DisplayData *data)')
cls.func(nil, 'cocostudio::DisplayData *getDisplayData()')
cls.func(nil, 'void setColliderDetector(cocostudio::ColliderDetector *detector)')
cls.func(nil, 'cocostudio::ColliderDetector *getColliderDetector()')
cls.prop('display', nil, nil)
cls.prop('displayData', nil, nil)
cls.prop('colliderDetector', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocostudio::DisplayFactory'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.func(nil, 'static void addDisplay(cocostudio::Bone *bone, cocostudio::DecorativeDisplay *decoDisplay, cocostudio::DisplayData *displayData)')
cls.func(nil, 'static void createDisplay(cocostudio::Bone *bone, cocostudio::DecorativeDisplay *decoDisplay)')
cls.func(nil, 'static void updateDisplay(cocostudio::Bone *bone, float dt, bool dirty)')
cls.func(nil, 'static void addSpriteDisplay(cocostudio::Bone *bone, cocostudio::DecorativeDisplay *decoDisplay, cocostudio::DisplayData *displayData)')
cls.func(nil, 'static void createSpriteDisplay(cocostudio::Bone *bone, cocostudio::DecorativeDisplay *decoDisplay)')
cls.func(nil, 'static void initSpriteDisplay(cocostudio::Bone *bone, cocostudio::DecorativeDisplay *decoDisplay, const char *displayName, cocostudio::Skin *skin)')
cls.func(nil, 'static void addArmatureDisplay(cocostudio::Bone *bone, cocostudio::DecorativeDisplay *decoDisplay, cocostudio::DisplayData *displayData)')
cls.func(nil, 'static void createArmatureDisplay(cocostudio::Bone *bone, cocostudio::DecorativeDisplay *decoDisplay)')
cls.func(nil, 'static void updateArmatureDisplay(cocostudio::Bone *bone, cocos2d::Node *display, float dt)')
cls.func(nil, 'static void addParticleDisplay(cocostudio::Bone *bone, cocostudio::DecorativeDisplay *decoDisplay, cocostudio::DisplayData *displayData)')
cls.func(nil, 'static void createParticleDisplay(cocostudio::Bone *bone, cocostudio::DecorativeDisplay *decoDisplay)')
cls.func(nil, 'static void updateParticleDisplay(cocostudio::Bone *bone, cocos2d::Node *display, float dt)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocostudio::DisplayManager'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.func(nil, 'static cocostudio::DisplayManager *create(cocostudio::Bone *bone)')
cls.func(nil, 'DisplayManager()')
cls.func(nil, 'bool init(cocostudio::Bone *bone)')
cls.func(nil, 'void initDisplayList(cocostudio::BoneData *boneData)')
cls.func(nil, 'void addDisplay(cocostudio::DisplayData *displayData, int index)', 'void addDisplay(cocos2d::Node *display, int index)')
cls.func(nil, 'void removeDisplay(int index)')
cls.func(nil, 'const cocos2d::Vector<DecorativeDisplay *> &getDecorativeDisplayList()')
cls.func(nil, 'void changeDisplayWithIndex(int index, bool force)')
cls.func(nil, 'void changeDisplayWithName(const std::string &name, bool force)')
cls.func(nil, 'cocos2d::Node *getDisplayRenderNode()')
cls.func(nil, 'cocostudio::DisplayType getDisplayRenderNodeType()')
cls.func(nil, 'int getCurrentDisplayIndex()')
cls.func(nil, 'void setCurrentDecorativeDisplay(cocostudio::DecorativeDisplay *decoDisplay)')
cls.func(nil, 'cocostudio::DecorativeDisplay *getCurrentDecorativeDisplay()')
cls.func(nil, 'cocostudio::DecorativeDisplay *getDecorativeDisplayByIndex(int index)')
cls.func(nil, 'void setVisible(bool visible)')
cls.func(nil, 'bool isVisible()')
cls.func(nil, 'cocos2d::Size getContentSize()')
cls.func(nil, 'cocos2d::Rect getBoundingBox()')
cls.func(nil, 'cocos2d::Vec2 getAnchorPoint()')
cls.func(nil, 'cocos2d::Vec2 getAnchorPointInPoints()')
cls.func(nil, 'bool containPoint(cocos2d::Vec2 &_point)', 'bool containPoint(float x, float y)')
cls.func(nil, 'void setForceChangeDisplay(bool force)')
cls.func(nil, 'bool isForceChangeDisplay()')
cls.prop('decorativeDisplayList', nil, nil)
cls.prop('displayRenderNode', nil, nil)
cls.prop('displayRenderNodeType', nil, nil)
cls.prop('currentDisplayIndex', nil, nil)
cls.prop('currentDecorativeDisplay', nil, nil)
cls.prop('visible', nil, nil)
cls.prop('contentSize', nil, nil)
cls.prop('boundingBox', nil, nil)
cls.prop('anchorPoint', nil, nil)
cls.prop('anchorPointInPoints', nil, nil)
cls.prop('forceChangeDisplay', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocostudio::FrameData'
cls.SUPERCLS = 'cocostudio::BaseData'
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.func(nil, 'static cocostudio::FrameData *create()')
cls.func(nil, 'FrameData()')
cls.var('frameID', 'int frameID')
cls.var('duration', 'int duration')
cls.var('tweenEasing', 'cocos2d::tweenfunc::TweenType tweenEasing')
cls.var('easingParamNumber', 'int easingParamNumber')
cls.var('isTween', 'bool isTween')
cls.var('displayIndex', 'int displayIndex')
cls.var('blendFunc', 'cocos2d::BlendFunc blendFunc')
cls.var('strEvent', 'std::string strEvent')
cls.var('strMovement', 'std::string strMovement')
cls.var('strSound', 'std::string strSound')
cls.var('strSoundEffect', 'std::string strSoundEffect')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocostudio::GUIReader'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.func(nil, 'static cocostudio::GUIReader *getInstance()')
cls.func(nil, 'static void destroyInstance()')
cls.func(nil, 'cocos2d::ui::Widget *widgetFromJsonFile(const char *fileName)')
cls.func(nil, 'cocos2d::ui::Widget *widgetFromBinaryFile(const char *fileName)')
cls.func(nil, 'int getVersionInteger(const char *str)')
cls.func(nil, 'void storeFileDesignSize(const char *fileName, const cocos2d::Size &size)')
cls.func(nil, 'cocos2d::Size getFileDesignSize(const char *fileName)')
cls.func(nil, 'void setFilePath(const std::string &strFilePath)')
cls.func(nil, 'const std::string &getFilePath()')
cls.prop('instance', nil, nil)
cls.prop('filePath', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocostudio::InputDelegate'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.func(nil, 'InputDelegate()')
cls.func(nil, 'bool isTouchEnabled()')
cls.func(nil, 'void setTouchEnabled(bool value)')
cls.func(nil, 'bool isAccelerometerEnabled()')
cls.func(nil, 'void setAccelerometerEnabled(bool value)')
cls.func(nil, 'bool isKeypadEnabled()')
cls.func(nil, 'void setKeypadEnabled(bool value)')
cls.func(nil, 'void setTouchMode(cocos2d::Touch::DispatchMode mode)')
cls.func(nil, 'cocos2d::Touch::DispatchMode getTouchMode()')
cls.func(nil, 'void setTouchPriority(int priority)')
cls.func(nil, 'int getTouchPriority()')
cls.func(nil, 'void onAcceleration(cocos2d::Acceleration *acc, cocos2d::Event *event)')
cls.func(nil, 'void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event)')
cls.func(nil, 'void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event)')
cls.func(nil, 'bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)')
cls.func(nil, 'void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event)')
cls.func(nil, 'void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event)')
cls.func(nil, 'void onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event *event)')
cls.func(nil, 'void onTouchesBegan(const std::vector<cocos2d::Touch *> &touches, cocos2d::Event *event)')
cls.func(nil, 'void onTouchesMoved(const std::vector<cocos2d::Touch *> &touches, cocos2d::Event *event)')
cls.func(nil, 'void onTouchesEnded(const std::vector<cocos2d::Touch *> &touches, cocos2d::Event *event)')
cls.func(nil, 'void onTouchesCancelled(const std::vector<cocos2d::Touch *> &touches, cocos2d::Event *event)')
cls.prop('touchEnabled', nil, nil)
cls.prop('accelerometerEnabled', nil, nil)
cls.prop('keypadEnabled', nil, nil)
cls.prop('touchMode', nil, nil)
cls.prop('touchPriority', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocostudio::MovementBoneData'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.func(nil, 'static cocostudio::MovementBoneData *create()')
cls.func(nil, 'MovementBoneData()')
cls.func(nil, 'bool init()')
cls.func(nil, 'void addFrameData(cocostudio::FrameData *frameData)')
cls.func(nil, 'cocostudio::FrameData *getFrameData(int index)')
cls.var('delay', 'float delay')
cls.var('scale', 'float scale')
cls.var('duration', 'float duration')
cls.var('name', 'std::string name')
cls.var('frameList', 'cocos2d::Vector<FrameData *> frameList')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocostudio::MovementData'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.func(nil, 'static cocostudio::MovementData *create()')
cls.func(nil, 'MovementData()')
cls.func(nil, 'void addMovementBoneData(cocostudio::MovementBoneData *movBoneData)')
cls.func(nil, 'cocostudio::MovementBoneData *getMovementBoneData(const std::string &boneName)')
cls.var('name', 'std::string name')
cls.var('duration', 'int duration')
cls.var('scale', 'float scale')
cls.var('durationTo', 'int durationTo')
cls.var('durationTween', 'int durationTween')
cls.var('loop', 'bool loop')
cls.var('tweenEasing', 'cocos2d::tweenfunc::TweenType tweenEasing')
cls.var('movBoneDataDic', 'cocos2d::Map<std::string, MovementBoneData *> movBoneDataDic')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocostudio::ParticleDisplayData'
cls.SUPERCLS = 'cocostudio::DisplayData'
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.func(nil, 'static cocostudio::ParticleDisplayData *create()')
cls.func(nil, 'ParticleDisplayData()')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocostudio::SceneReader::AttachComponentType'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.enum('EMPTY_NODE', 'cocostudio::SceneReader::AttachComponentType::EMPTY_NODE')
cls.enum('RENDER_NODE', 'cocostudio::SceneReader::AttachComponentType::RENDER_NODE')
cls.enum('DEFAULT', 'cocostudio::SceneReader::AttachComponentType::DEFAULT')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocostudio::SceneReader'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.func(nil, 'static cocostudio::SceneReader *getInstance()')
cls.func(nil, 'static void destroyInstance()')
cls.func(nil, 'static const char *sceneReaderVersion()')
cls.func(nil, 'cocos2d::Node *createNodeWithSceneFile(const std::string &fileName, @optional cocostudio::SceneReader::AttachComponentType attachComponent)')
cls.func(nil, 'cocos2d::Node *getNodeByTag(int nTag)')
cls.func(nil, 'cocostudio::SceneReader::AttachComponentType getAttachComponentType()')
cls.func(nil, 'SceneReader()')
cls.callback {
    FUNCS =  {
        'void setTarget(@nullable @local const std::function<void (cocos2d::Ref *, void *)> &selector)'
    },
    TAG_MAKER = 'Target',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.prop('instance', nil, nil)
cls.prop('attachComponentType', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocostudio::Skin'
cls.SUPERCLS = 'cocos2d::Sprite'
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.func(nil, 'static cocostudio::Skin *create()', 'static cocostudio::Skin *create(const std::string &pszFileName)')
cls.func(nil, 'static cocostudio::Skin *createWithSpriteFrameName(const std::string &pszSpriteFrameName)')
cls.func(nil, 'Skin()')
cls.func(nil, 'void updateArmatureTransform()')
cls.func(nil, 'cocos2d::Mat4 getNodeToWorldTransformAR()')
cls.func(nil, 'void setSkinData(const cocostudio::BaseData &data)')
cls.func(nil, 'const cocostudio::BaseData &getSkinData()')
cls.func(nil, 'void setBone(cocostudio::Bone *bone)')
cls.func(nil, 'cocostudio::Bone *getBone()')
cls.func(nil, 'const std::string &getDisplayName()')
cls.prop('nodeToWorldTransformAR', nil, nil)
cls.prop('skinData', nil, nil)
cls.prop('bone', nil, nil)
cls.prop('displayName', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocostudio::SpriteDisplayData'
cls.SUPERCLS = 'cocostudio::DisplayData'
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.func(nil, 'static cocostudio::SpriteDisplayData *create()')
cls.func(nil, 'SpriteDisplayData()')
cls.var('skinData', 'cocostudio::BaseData skinData')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocostudio::SpriteFrameCacheHelper'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.func(nil, 'static cocostudio::SpriteFrameCacheHelper *getInstance()')
cls.func(nil, 'static void purge()')
cls.func(nil, 'void addSpriteFrameFromFile(const std::string &plistPath, const std::string &imagePath)')
cls.func(nil, 'void removeSpriteFrameFromFile(const std::string &plistPath)')
cls.prop('instance', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocostudio::TextureData'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.func(nil, 'static cocostudio::TextureData *create()')
cls.func(nil, 'TextureData()')
cls.func(nil, 'bool init()')
cls.func(nil, 'void addContourData(cocostudio::ContourData *contourData)')
cls.func(nil, 'cocostudio::ContourData *getContourData(int index)')
cls.var('height', 'float height')
cls.var('width', 'float width')
cls.var('pivotX', 'float pivotX')
cls.var('pivotY', 'float pivotY')
cls.var('name', 'std::string name')
cls.var('contourDataList', 'cocos2d::Vector<ContourData *> contourDataList')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocostudio::Tween'
cls.SUPERCLS = 'cocostudio::ProcessBase'
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.func(nil, 'static cocostudio::Tween *create(cocostudio::Bone *bone)')
cls.func(nil, 'Tween()')
cls.func(nil, 'bool init(cocostudio::Bone *bone)')
cls.func(nil, 'void play(cocostudio::MovementBoneData *movementBoneData, int durationTo, int durationTween, int loop, int tweenEasing)', '@using void play(int durationTo, int durationTween, int loop, int tweenEasing)')
cls.func(nil, 'void setAnimation(cocostudio::ArmatureAnimation *animation)')
cls.func(nil, 'cocostudio::ArmatureAnimation *getAnimation()')
cls.func(nil, 'void gotoAndPlay(int frameIndex)')
cls.func(nil, 'void gotoAndPause(int frameIndex)')
cls.func(nil, 'void setMovementBoneData(cocostudio::MovementBoneData *data)')
cls.func(nil, 'const cocostudio::MovementBoneData *getMovementBoneData()')
cls.prop('animation', nil, nil)
cls.prop('movementBoneData', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocostudio::timeline::InnerActionType'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.enum('LoopAction', 'cocostudio::timeline::InnerActionType::LoopAction')
cls.enum('NoLoopAction', 'cocostudio::timeline::InnerActionType::NoLoopAction')
cls.enum('SingleFrame', 'cocostudio::timeline::InnerActionType::SingleFrame')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocostudio::timeline::Frame'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.func(nil, 'void setFrameIndex(unsigned int frameIndex)')
cls.func(nil, 'unsigned int getFrameIndex()')
cls.func(nil, 'void setTimeline(@addref(timeline ^) cocostudio::timeline::Timeline *timeline)')
cls.func(nil, '@addref(timeline ^) cocostudio::timeline::Timeline *getTimeline()')
cls.func(nil, 'void setNode(@addref(node ^) cocos2d::Node *node)')
cls.func(nil, '@addref(node ^) cocos2d::Node *getNode()')
cls.func(nil, 'void setTween(bool tween)')
cls.func(nil, 'bool isTween()')
cls.func(nil, 'void setTweenType(const cocos2d::tweenfunc::TweenType &tweenType)')
cls.func(nil, 'cocos2d::tweenfunc::TweenType getTweenType()')
cls.func(nil, 'void setEasingParams(const std::vector<float> &easingParams)')
cls.func(nil, 'const std::vector<float> &getEasingParams()')
cls.func(nil, 'bool isEnterWhenPassed()')
cls.func(nil, 'void onEnter(cocostudio::timeline::Frame *nextFrame, int currentFrameIndex)')
cls.func(nil, 'void apply(float percent)')
cls.func(nil, 'cocostudio::timeline::Frame *clone()')
cls.prop('frameIndex', nil, nil)
cls.prop('timeline', nil, nil)
cls.prop('node', nil, nil)
cls.prop('tween', nil, nil)
cls.prop('tweenType', nil, nil)
cls.prop('easingParams', nil, nil)
cls.prop('enterWhenPassed', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocostudio::timeline::AlphaFrame'
cls.SUPERCLS = 'cocostudio::timeline::Frame'
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.func(nil, 'static cocostudio::timeline::AlphaFrame *create()')
cls.func(nil, 'AlphaFrame()')
cls.func(nil, 'void setAlpha(uint8_t alpha)')
cls.func(nil, 'uint8_t getAlpha()')
cls.prop('alpha', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocostudio::timeline::AnchorPointFrame'
cls.SUPERCLS = 'cocostudio::timeline::Frame'
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.func(nil, 'static cocostudio::timeline::AnchorPointFrame *create()')
cls.func(nil, 'AnchorPointFrame()')
cls.func(nil, 'void setAnchorPoint(const cocos2d::Point &point)')
cls.func(nil, 'cocos2d::Point getAnchorPoint()')
cls.prop('anchorPoint', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocostudio::timeline::BlendFuncFrame'
cls.SUPERCLS = 'cocostudio::timeline::Frame'
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.func(nil, 'static cocostudio::timeline::BlendFuncFrame *create()')
cls.func(nil, 'BlendFuncFrame()')
cls.func(nil, 'cocos2d::BlendFunc getBlendFunc()')
cls.func(nil, 'void setBlendFunc(cocos2d::BlendFunc blendFunc)')
cls.prop('blendFunc', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocostudio::timeline::ColorFrame'
cls.SUPERCLS = 'cocostudio::timeline::Frame'
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.func(nil, 'static cocostudio::timeline::ColorFrame *create()')
cls.func(nil, 'ColorFrame()')
cls.func(nil, 'void setColor(const cocos2d::Color3B &color)')
cls.func(nil, 'cocos2d::Color3B getColor()')
cls.prop('color', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocostudio::timeline::EventFrame'
cls.SUPERCLS = 'cocostudio::timeline::Frame'
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.func(nil, 'static cocostudio::timeline::EventFrame *create()')
cls.func(nil, 'void init()')
cls.func(nil, 'EventFrame()')
cls.func(nil, 'void setEvent(std::string event)')
cls.func(nil, 'std::string getEvent()')
cls.prop('event', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocostudio::timeline::InnerActionFrame'
cls.SUPERCLS = 'cocostudio::timeline::Frame'
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.const('AnimationAllName', 'cocostudio::timeline::InnerActionFrame::AnimationAllName', 'const std::string')
cls.func(nil, 'static cocostudio::timeline::InnerActionFrame *create()')
cls.func(nil, 'InnerActionFrame()')
cls.func(nil, 'void setInnerActionType(cocostudio::timeline::InnerActionType type)')
cls.func(nil, 'cocostudio::timeline::InnerActionType getInnerActionType()')
cls.func(nil, 'void setEnterWithName(bool isEnterWithName)')
cls.func(nil, 'void setStartFrameIndex(int frameIndex)')
cls.func(nil, 'int getStartFrameIndex()')
cls.func(nil, 'void setEndFrameIndex(int frameIndex)')
cls.func(nil, 'int getEndFrameIndex()')
cls.func(nil, 'void setAnimationName(const std::string &animationNamed)')
cls.func(nil, 'void setSingleFrameIndex(int frameIndex)')
cls.func(nil, 'int getSingleFrameIndex()')
cls.prop('innerActionType', nil, nil)
cls.prop('startFrameIndex', nil, nil)
cls.prop('endFrameIndex', nil, nil)
cls.prop('singleFrameIndex', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocostudio::timeline::PlayableFrame'
cls.SUPERCLS = 'cocostudio::timeline::Frame'
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.const('PLAYABLE_EXTENTION', 'cocostudio::timeline::PlayableFrame::PLAYABLE_EXTENTION', 'const std::string')
cls.func(nil, 'static cocostudio::timeline::PlayableFrame *create()')
cls.func(nil, 'PlayableFrame()')
cls.func(nil, 'std::string getPlayableAct()')
cls.func(nil, 'void setPlayableAct(std::string playact)')
cls.prop('playableAct', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocostudio::timeline::PositionFrame'
cls.SUPERCLS = 'cocostudio::timeline::Frame'
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.func(nil, 'static cocostudio::timeline::PositionFrame *create()')
cls.func(nil, 'PositionFrame()')
cls.func(nil, 'void setPosition(const cocos2d::Point &position)')
cls.func(nil, 'cocos2d::Point getPosition()')
cls.func(nil, 'void setX(float x)')
cls.func(nil, 'void setY(float y)')
cls.func(nil, 'float getX()')
cls.func(nil, 'float getY()')
cls.prop('position', nil, nil)
cls.prop('x', nil, nil)
cls.prop('y', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocostudio::timeline::RotationFrame'
cls.SUPERCLS = 'cocostudio::timeline::Frame'
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.func(nil, 'static cocostudio::timeline::RotationFrame *create()')
cls.func(nil, 'RotationFrame()')
cls.func(nil, 'void setRotation(float rotation)')
cls.func(nil, 'float getRotation()')
cls.prop('rotation', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocostudio::timeline::SkewFrame'
cls.SUPERCLS = 'cocostudio::timeline::Frame'
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.func(nil, 'static cocostudio::timeline::SkewFrame *create()')
cls.func(nil, 'SkewFrame()')
cls.func(nil, 'void setSkewX(float skewx)')
cls.func(nil, 'float getSkewX()')
cls.func(nil, 'void setSkewY(float skewy)')
cls.func(nil, 'float getSkewY()')
cls.prop('skewX', nil, nil)
cls.prop('skewY', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocostudio::timeline::RotationSkewFrame'
cls.SUPERCLS = 'cocostudio::timeline::SkewFrame'
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.func(nil, 'static cocostudio::timeline::RotationSkewFrame *create()')
cls.func(nil, 'RotationSkewFrame()')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocostudio::timeline::ScaleFrame'
cls.SUPERCLS = 'cocostudio::timeline::Frame'
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.func(nil, 'static cocostudio::timeline::ScaleFrame *create()')
cls.func(nil, 'ScaleFrame()')
cls.func(nil, 'void setScale(float scale)')
cls.func(nil, 'void setScaleX(float scaleX)')
cls.func(nil, 'float getScaleX()')
cls.func(nil, 'void setScaleY(float scaleY)')
cls.func(nil, 'float getScaleY()')
cls.prop('scaleX', nil, nil)
cls.prop('scaleY', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocostudio::timeline::TextureFrame'
cls.SUPERCLS = 'cocostudio::timeline::Frame'
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.func(nil, 'static cocostudio::timeline::TextureFrame *create()')
cls.func(nil, 'TextureFrame()')
cls.func(nil, 'void setTextureName(std::string textureName)')
cls.func(nil, 'std::string getTextureName()')
cls.prop('textureName', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocostudio::timeline::VisibleFrame'
cls.SUPERCLS = 'cocostudio::timeline::Frame'
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.func(nil, 'static cocostudio::timeline::VisibleFrame *create()')
cls.func(nil, 'VisibleFrame()')
cls.func(nil, 'void setVisible(bool visible)')
cls.func(nil, 'bool isVisible()')
cls.prop('visible', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocostudio::timeline::ZOrderFrame'
cls.SUPERCLS = 'cocostudio::timeline::Frame'
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.func(nil, 'static cocostudio::timeline::ZOrderFrame *create()')
cls.func(nil, 'ZOrderFrame()')
cls.func(nil, 'void setZOrder(int zorder)')
cls.func(nil, 'int getZOrder()')
cls.prop('zOrder', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocostudio::timeline::ActionTimelineCache'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.func(nil, 'static cocostudio::timeline::ActionTimelineCache *getInstance()')
cls.func(nil, 'static void destroyInstance()')
cls.func(nil, 'void purge()')
cls.func(nil, 'void init()')
cls.func(nil, 'void removeAction(const std::string &fileName)')
cls.func(nil, 'static cocostudio::timeline::ActionTimeline *createAction(const std::string &fileName)')
cls.func(nil, 'cocostudio::timeline::ActionTimeline *createActionFromJson(const std::string &fileName)')
cls.func(nil, 'cocostudio::timeline::ActionTimeline *createActionFromContent(const std::string &fileName, const std::string &content)')
cls.func(nil, 'cocostudio::timeline::ActionTimeline *loadAnimationActionWithFile(const std::string &fileName)')
cls.func(nil, 'cocostudio::timeline::ActionTimeline *loadAnimationActionWithContent(const std::string &fileName, const std::string &content)')
cls.func(nil, 'cocostudio::timeline::ActionTimeline *createActionWithFlatBuffersFile(const std::string &fileName)')
cls.func(nil, 'cocostudio::timeline::ActionTimeline *createActionWithDataBuffer(cocos2d::Data data, const std::string &fileName)')
cls.func(nil, 'cocostudio::timeline::ActionTimeline *loadAnimationActionWithFlatBuffersFile(const std::string &fileName)')
cls.func(nil, 'cocostudio::timeline::ActionTimeline *loadAnimationWithDataBuffer(const cocos2d::Data &data, const std::string &fileName)')
cls.func(nil, 'cocostudio::timeline::ActionTimeline *createActionWithFlatBuffersForSimulator(const std::string &fileName)')
cls.prop('instance', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocostudio::timeline::ActionTimelineData'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.func(nil, 'static cocostudio::timeline::ActionTimelineData *create(int actionTag)')
cls.func(nil, 'void setActionTag(int actionTag)')
cls.func(nil, 'int getActionTag()')
cls.func(nil, 'ActionTimelineData()')
cls.func(nil, 'bool init(int actionTag)')
cls.prop('actionTag', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocostudio::timeline::ActionTimelineNode'
cls.SUPERCLS = 'cocos2d::Node'
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.func(nil, 'static cocostudio::timeline::ActionTimelineNode *create(cocos2d::Node *root, cocostudio::timeline::ActionTimeline *action)')
cls.func(nil, 'ActionTimelineNode()')
cls.func(nil, '@using bool init()', 'bool init(cocos2d::Node *root, cocostudio::timeline::ActionTimeline *action)')
cls.func(nil, 'void setRoot(@addref(root ^) cocos2d::Node *root)')
cls.func(nil, '@addref(root ^) cocos2d::Node *getRoot()')
cls.func(nil, 'void setActionTimeline(@addref(actionTimeline ^) cocostudio::timeline::ActionTimeline *action)')
cls.func(nil, '@addref(actionTimeline ^) cocostudio::timeline::ActionTimeline *getActionTimeline()')
cls.prop('root', nil, nil)
cls.prop('actionTimeline', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocostudio::timeline::BoneNode'
cls.SUPERCLS = 'cocos2d::Node'
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.func(nil, 'static cocostudio::timeline::BoneNode *create()', 'static cocostudio::timeline::BoneNode *create(int length)')
cls.func(nil, '@addref(bones |) const cocos2d::Vector<BoneNode *> &getChildBones()')
cls.func(nil, '@addref(rootSkeletonNode ^) cocostudio::timeline::SkeletonNode *getRootSkeletonNode()')
cls.func(nil, '@addref(subBones |) cocos2d::Vector<BoneNode *> getAllSubBones()')
cls.func(nil, 'void addSkin(@addref(skins |) cocostudio::timeline::SkinNode *skin, bool display)', 'void addSkin(@addref(skins |) cocostudio::timeline::SkinNode *skin, bool display, bool hideOthers)')
cls.func(nil, 'void displaySkin(cocostudio::timeline::SkinNode *skin, bool hideOthers)', 'void displaySkin(const std::string &skinName, bool hideOthers)')
cls.func(nil, '@addref(skins |) cocos2d::Vector<SkinNode *> getVisibleSkins()')
cls.func(nil, '@addref(skins |) const cocos2d::Vector<SkinNode *> &getSkins()')
cls.func(nil, '@addref(subSkins |) cocos2d::Vector<SkinNode *> getAllSubSkins()')
cls.func(nil, 'void setBlendFunc(const cocos2d::BlendFunc &blendFunc)')
cls.func(nil, 'const cocos2d::BlendFunc &getBlendFunc()')
cls.func(nil, 'void setDebugDrawEnabled(bool isDebugDraw)')
cls.func(nil, 'bool isDebugDrawEnabled()')
cls.func(nil, 'void setDebugDrawLength(float length)')
cls.func(nil, 'float getDebugDrawLength()')
cls.func(nil, 'void setDebugDrawWidth(float width)')
cls.func(nil, 'float getDebugDrawWidth()')
cls.func(nil, 'void setDebugDrawColor(const cocos2d::Color4F &color)')
cls.func(nil, 'cocos2d::Color4F getDebugDrawColor()')
cls.func(nil, 'cocos2d::Rect getVisibleSkinsRect()')
cls.func(nil, 'void setLocalZOrder(int localZOrder)')
cls.func(nil, 'BoneNode()')
cls.prop('childBones', nil, nil)
cls.prop('rootSkeletonNode', nil, nil)
cls.prop('allSubBones', nil, nil)
cls.prop('visibleSkins', nil, nil)
cls.prop('skins', nil, nil)
cls.prop('allSubSkins', nil, nil)
cls.prop('blendFunc', nil, nil)
cls.prop('debugDrawEnabled', nil, nil)
cls.prop('debugDrawLength', nil, nil)
cls.prop('debugDrawWidth', nil, nil)
cls.prop('debugDrawColor', nil, nil)
cls.prop('visibleSkinsRect', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocostudio::timeline::SkeletonNode'
cls.SUPERCLS = 'cocostudio::timeline::BoneNode'
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.func(nil, 'static cocostudio::timeline::SkeletonNode *create()')
cls.func(nil, '@addref(boneNodes |) cocostudio::timeline::BoneNode *getBoneNode(const std::string &boneName)')
cls.func(nil, '@addref(boneNodes |) const cocos2d::Map<std::string, BoneNode *> &getAllSubBonesMap()')
cls.func(nil, 'void changeSkins(const std::map<std::string, std::string> &boneSkinNameMap)', 'void changeSkins(const std::string &skinGroupName)')
cls.func(nil, 'void addSkinGroup(std::string groupName, std::map<std::string, std::string> boneSkinNameMap)')
cls.func(nil, 'SkeletonNode()')
cls.prop('allSubBonesMap', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocostudio::timeline::Timeline'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.func(nil, 'static cocostudio::timeline::Timeline *create()')
cls.func(nil, 'Timeline()')
cls.func(nil, 'void gotoFrame(int frameIndex)')
cls.func(nil, 'void stepToFrame(int frameIndex)')
cls.func(nil, '@addref(frames |) const cocos2d::Vector<Frame *> &getFrames()')
cls.func(nil, 'void addFrame(@addref(frames |) cocostudio::timeline::Frame *frame)')
cls.func(nil, 'void insertFrame(@addref(frames |) cocostudio::timeline::Frame *frame, int index)')
cls.func(nil, 'void removeFrame(@delref(frames |) cocostudio::timeline::Frame *frame)')
cls.func(nil, 'void setActionTag(int tag)')
cls.func(nil, 'int getActionTag()')
cls.func(nil, 'void setNode(@addref(node ^) cocos2d::Node *node)')
cls.func(nil, '@addref(node ^) cocos2d::Node *getNode()')
cls.func(nil, 'void setActionTimeline(@addref(actionTimeline ^) cocostudio::timeline::ActionTimeline *action)')
cls.func(nil, '@addref(actionTimeline ^) cocostudio::timeline::ActionTimeline *getActionTimeline()')
cls.func(nil, 'cocostudio::timeline::Timeline *clone()')
cls.prop('frames', nil, nil)
cls.prop('actionTag', nil, nil)
cls.prop('node', nil, nil)
cls.prop('actionTimeline', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocostudio::timeline::ActionTimeline'
cls.SUPERCLS = 'cocos2d::Action'
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.func(nil, 'static cocostudio::timeline::ActionTimeline *create()')
cls.func(nil, 'ActionTimeline()')
cls.func(nil, 'void play(std::string animationName, bool loop)')
cls.func(nil, 'void gotoFrameAndPlay(int startIndex)', 'void gotoFrameAndPlay(int startIndex, bool loop)', 'void gotoFrameAndPlay(int startIndex, int endIndex, bool loop)', 'void gotoFrameAndPlay(int startIndex, int endIndex, int currentFrameIndex, bool loop)')
cls.func(nil, 'void gotoFrameAndPause(int startIndex)')
cls.func(nil, 'void pause()')
cls.func(nil, 'void resume()')
cls.func(nil, 'bool isPlaying()')
cls.func(nil, 'void setTimeSpeed(float speed)')
cls.func(nil, 'float getTimeSpeed()')
cls.func(nil, 'void setDuration(int duration)')
cls.func(nil, 'int getDuration()')
cls.func(nil, 'int getStartFrame()')
cls.func(nil, 'int getEndFrame()')
cls.func(nil, 'void setCurrentFrame(int frameIndex)')
cls.func(nil, 'int getCurrentFrame()')
cls.func(nil, 'void addTimeline(@addref(timelines |) cocostudio::timeline::Timeline *timeline)')
cls.func(nil, 'void removeTimeline(@delref(timelines |) cocostudio::timeline::Timeline *timeline)')
cls.func(nil, '@addref(timelines |) const cocos2d::Vector<Timeline *> &getTimelines()')
cls.func(nil, 'void addAnimationInfo(const cocostudio::timeline::AnimationInfo &animationInfo)')
cls.func(nil, 'void removeAnimationInfo(std::string animationName)')
cls.func(nil, 'bool IsAnimationInfoExists(const std::string &animationName)')
cls.func(nil, 'const cocostudio::timeline::AnimationInfo &getAnimationInfo(const std::string &animationName)')
cls.func(nil, 'void start()')
cls.callback {
    FUNCS =  {
        'void setAnimationEndCallFunc(const std::string animationName, @local std::function<void ()> func)'
    },
    TAG_MAKER = 'makeFrameEndCallbackTag(#0, #1)',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        'void setFrameEventCallFunc(@nullable @local std::function<void (cocostudio::timeline::Frame *)> listener)'
    },
    TAG_MAKER = 'frameEventCallFunc',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        'void clearFrameEventCallFunc()'
    },
    TAG_MAKER = 'frameEventCallFunc',
    TAG_MODE = 'OLUA_TAG_SUBSTARTWITH',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        'void setLastFrameCallFunc(@nullable @local std::function<void ()> listener)'
    },
    TAG_MAKER = 'lastFrameCallFunc',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        'void clearLastFrameCallFunc()'
    },
    TAG_MAKER = 'lastFrameCallFunc',
    TAG_MODE = 'OLUA_TAG_SUBSTARTWITH',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        'void addFrameEndCallFunc(int frameIndex, const std::string &funcKey, @local std::function<void ()> func)'
    },
    TAG_MAKER = 'makeFrameEndCallbackTag(#1, #2)',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        'void removeFrameEndCallFunc(int frameIndex, const std::string &funcKey)'
    },
    TAG_MAKER = 'makeFrameEndCallbackTag(#1, #2)',
    TAG_MODE = 'OLUA_TAG_SUBSTARTWITH',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        'void removeFrameEndCallFuncs(int frameIndex)'
    },
    TAG_MAKER = 'makeFrameEndCallbackTag(#1, "")',
    TAG_MODE = 'OLUA_TAG_SUBSTARTWITH',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        'void clearFrameEndCallFuncs()'
    },
    TAG_MAKER = 'makeFrameEndCallbackTag(-1, "")',
    TAG_MODE = 'OLUA_TAG_SUBSTARTWITH',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.prop('playing', nil, nil)
cls.prop('timeSpeed', nil, nil)
cls.prop('duration', nil, nil)
cls.prop('startFrame', nil, nil)
cls.prop('endFrame', nil, nil)
cls.prop('currentFrame', nil, nil)
cls.prop('timelines', nil, nil)
cls.insert('addAnimationInfo', {
    BEFORE = [[
        if (olua_getfield(L, 2, "clipEndCallBack") == LUA_TFUNCTION) {
            void *cb_store = (void *)self;
            std::string cb_tag = makeFrameEndCallbackTag(arg1.endIndex, arg1.name);
            std::string cb_name = olua_setcallback(L, cb_store, cb_tag.c_str(), -1, OLUA_TAG_REPLACE);
            lua_Integer cb_ctx = olua_context(L);
            arg1.clipEndCallBack = [cb_store, cb_name, cb_ctx]() {
                lua_State *L = olua_mainthread(NULL);
                olua_checkhostthread();

                if (L != NULL && olua_context(L) == cb_ctx) {
                    int top = lua_gettop(L);

                    olua_callback(L, cb_store, cb_name.c_str(), 0);

                    lua_settop(L, top);
                }
            };
        }
    ]],
    AFTER = nil,
    CALLBACK_BEFORE = nil,
    CALLBACK_AFTER = nil,
})
cls.insert('removeAnimationInfo', {
    BEFORE = [[
        auto info = self->getAnimationInfo(arg1);
        std::string cb_tag = makeFrameEndCallbackTag(info.endIndex, arg1);
        void *cb_store = (void *)self;
        olua_removecallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_SUBSTARTWITH);
    ]],
    AFTER = nil,
    CALLBACK_BEFORE = nil,
    CALLBACK_AFTER = nil,
})
cls.insert('setFrameEventCallFunc', {
    BEFORE = nil,
    AFTER = nil,
    CALLBACK_BEFORE = [[
        if (arg1->getTimeline() && arg1->getTimeline()->getActionTimeline()) {
            olua_push_cppobj<cocostudio::timeline::ActionTimeline>(L, arg1->getTimeline()->getActionTimeline());
            olua_push_cppobj<cocostudio::timeline::Timeline>(L, arg1->getTimeline());
            olua_push_cppobj<cocostudio::timeline::Frame>(L, arg1);
            olua_addref(L, -3, "timelines", -2, OLUA_MODE_MULTIPLE);
            olua_addref(L, -2, "frames", -1, OLUA_MODE_MULTIPLE);
            lua_pop(L, 3);
        }
    ]],
    CALLBACK_AFTER = nil,
})
M.CLASSES[#M.CLASSES + 1] = cls

return M
