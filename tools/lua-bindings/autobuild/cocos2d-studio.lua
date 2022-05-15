-- AUTO BUILD, DON'T MODIFY!

dofile "autobuild/cocos2d-studio-types.lua"

name = "cocos2d_studio"
path = "../../frameworks/libxgame/src/lua-bindings"
headers = [[
    #include "lua-bindings/lua_conv.h"
    #include "lua-bindings/lua_conv_manual.h"
    #include "cclua/xlua.h"
    #include "cocos2d.h"
    #include "editor-support/cocostudio/CocoStudio.h"
]]
chunk = [[
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
luaopen = nil

typeconv 'cocostudio::timeline::AnimationInfo'
    .var('name', 'std::string name')
    .var('startIndex', 'int startIndex')
    .var('endIndex', 'int endIndex')


typeconf 'cocos2d::CSLoader'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .func(nil, 'static cocos2d::CSLoader *getInstance()')
    .func(nil, 'static void destroyInstance()')
    .func(nil, 'CSLoader()')
    .func(nil, 'void init()')
    .func(nil, 'static cocostudio::timeline::ActionTimeline *createTimeline(const std::string &filename)', 'static cocostudio::timeline::ActionTimeline *createTimeline(const cocos2d::Data &data, const std::string &filename)')
    .func(nil, 'cocos2d::Node *createNodeFromJson(const std::string &filename)')
    .func(nil, 'cocos2d::Node *loadNodeWithFile(const std::string &fileName)')
    .func(nil, 'cocos2d::Node *loadNodeWithContent(const std::string &content)')
    .func(nil, 'void setRecordJsonPath(bool record)')
    .func(nil, 'bool isRecordJsonPath()')
    .func(nil, 'void setJsonPath(std::string jsonPath)')
    .func(nil, 'std::string getJsonPath()')
    .func(nil, 'cocos2d::Node *createNodeWithFlatBuffersFile(const std::string &filename)')
    .func(nil, 'cocos2d::Node *nodeWithFlatBuffersFile(const std::string &fileName)')
    .func(nil, 'bool bindCallback(const std::string &callbackName, const std::string &callbackType, cocos2d::ui::Widget *sender, cocos2d::Node *handler)')
    .func(nil, 'cocos2d::Node *createNodeWithFlatBuffersForSimulator(const std::string &filename)')
    .callback {
        funcs =  {
            'static cocos2d::Node *createNode(const std::string &filename)',
            'static cocos2d::Node *createNode(const std::string &filename, @localvar const std::function<void (cocos2d::Ref *)> &callback)',
            'static cocos2d::Node *createNode(const cocos2d::Data &data)',
            'static cocos2d::Node *createNode(const cocos2d::Data &data, @localvar const std::function<void (cocos2d::Ref *)> &callback)'
        },
        tag_maker = 'createNode',
        tag_mode = 'new',
        tag_store = 0,
        tag_scope = 'function',
    }
    .callback {
        funcs =  {
            'static cocos2d::Node *createNodeWithVisibleSize(const std::string &filename)',
            'static cocos2d::Node *createNodeWithVisibleSize(const std::string &filename, @localvar const std::function<void (cocos2d::Ref *)> &callback)'
        },
        tag_maker = 'createNodeWithVisibleSize',
        tag_mode = 'new',
        tag_store = 0,
        tag_scope = 'function',
    }
    .prop('instance', nil, nil)
    .prop('recordJsonPath', nil, nil)
    .prop('jsonPath', nil, nil)

typeconf 'cocostudio::MovementEventType'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .enum('START', 'cocostudio::MovementEventType::START')
    .enum('COMPLETE', 'cocostudio::MovementEventType::COMPLETE')
    .enum('LOOP_COMPLETE', 'cocostudio::MovementEventType::LOOP_COMPLETE')

typeconf 'cocostudio::DisplayType'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .enum('CS_DISPLAY_SPRITE', 'cocostudio::DisplayType::CS_DISPLAY_SPRITE')
    .enum('CS_DISPLAY_ARMATURE', 'cocostudio::DisplayType::CS_DISPLAY_ARMATURE')
    .enum('CS_DISPLAY_PARTICLE', 'cocostudio::DisplayType::CS_DISPLAY_PARTICLE')
    .enum('CS_DISPLAY_MAX', 'cocostudio::DisplayType::CS_DISPLAY_MAX')

typeconf 'cocostudio::ActionFrame'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .func(nil, 'ActionFrame()')
    .func(nil, 'void setFrameIndex(int index)')
    .func(nil, 'int getFrameIndex()')
    .func(nil, 'void setFrameTime(float fTime)')
    .func(nil, 'float getFrameTime()')
    .func(nil, 'void setFrameType(int frameType)')
    .func(nil, 'int getFrameType()')
    .func(nil, 'void setEasingType(int easingType)')
    .func(nil, 'int getEasingType()')
    .func(nil, '@addref(action |) cocos2d::ActionInterval *getAction(float duration)', '@addref(action |) cocos2d::ActionInterval *getAction(float duration, cocostudio::ActionFrame *srcFrame)')
    .func(nil, 'void setEasingParameter(std::vector<float> &parameter)')
    .prop('frameIndex', nil, nil)
    .prop('frameTime', nil, nil)
    .prop('frameType', nil, nil)
    .prop('easingType', nil, nil)

typeconf 'cocostudio::ActionFadeFrame'
    .supercls('cocostudio::ActionFrame')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .func(nil, 'ActionFadeFrame()')
    .func(nil, 'void setOpacity(int opacity)')
    .func(nil, 'int getOpacity()')
    .prop('opacity', nil, nil)

typeconf 'cocostudio::ActionFrameEasing'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .func(nil, 'ActionFrameEasing()')
    .func(nil, 'float bounceTime(float t)')
    .func(nil, 'float easeValue(float t)')

typeconf 'cocostudio::ActionMoveFrame'
    .supercls('cocostudio::ActionFrame')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .func(nil, 'ActionMoveFrame()')
    .func(nil, 'void setPosition(cocos2d::Vec2 pos)')
    .func(nil, 'cocos2d::Vec2 getPosition()')
    .prop('position', nil, nil)

typeconf 'cocostudio::ActionRotationFrame'
    .supercls('cocostudio::ActionFrame')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .func(nil, 'ActionRotationFrame()')
    .func(nil, 'void setRotation(float rotation)')
    .func(nil, 'float getRotation()')
    .prop('rotation', nil, nil)

typeconf 'cocostudio::ActionScaleFrame'
    .supercls('cocostudio::ActionFrame')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .func(nil, 'ActionScaleFrame()')
    .func(nil, 'void setScaleX(float scaleX)')
    .func(nil, 'float getScaleX()')
    .func(nil, 'void setScaleY(float scaleY)')
    .func(nil, 'float getScaleY()')
    .prop('scaleX', nil, nil)
    .prop('scaleY', nil, nil)

typeconf 'cocostudio::ActionTintFrame'
    .supercls('cocostudio::ActionFrame')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .func(nil, 'ActionTintFrame()')
    .func(nil, 'void setColor(cocos2d::Color3B ccolor)')
    .func(nil, 'cocos2d::Color3B getColor()')
    .prop('color', nil, nil)

typeconf 'cocostudio::AnimationData'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .func(nil, 'static cocostudio::AnimationData *create()')
    .func(nil, 'AnimationData()')
    .func(nil, 'void addMovement(cocostudio::MovementData *movData)')
    .func(nil, 'cocostudio::MovementData *getMovement(const std::string &movementName)')
    .func(nil, 'ssize_t getMovementCount()')
    .var('name', 'std::string name')
    .var('movementDataDic', 'cocos2d::Map<std::string, MovementData *> movementDataDic')
    .var('movementNames', 'std::vector<std::string> movementNames')
    .prop('movementCount', nil, nil)

typeconf 'cocostudio::Armature'
    .supercls('cocos2d::Node')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .func(nil, 'static cocostudio::Armature *create()', 'static cocostudio::Armature *create(const std::string &name)', 'static cocostudio::Armature *create(const std::string &name, cocostudio::Bone *parentBone)')
    .func(nil, 'Armature()')
    .func(nil, '@using bool init()', 'bool init(const std::string &name)', 'bool init(const std::string &name, cocostudio::Bone *parentBone)')
    .func(nil, 'void addBone(cocostudio::Bone *bone, const std::string &parentName)')
    .func(nil, 'cocostudio::Bone *getBone(const std::string &name)')
    .func(nil, 'void changeBoneParent(cocostudio::Bone *bone, const std::string &parentName)')
    .func(nil, 'void removeBone(cocostudio::Bone *bone, bool recursion)')
    .func(nil, 'const cocos2d::Map<std::string, Bone *> &getBoneDic()')
    .func(nil, 'cocostudio::Bone *getBoneAtPoint(float x, float y)')
    .func(nil, 'void setBlendFunc(const cocos2d::BlendFunc &blendFunc)')
    .func(nil, 'const cocos2d::BlendFunc &getBlendFunc()')
    .func(nil, 'void updateOffsetPoint()')
    .func(nil, 'const cocos2d::Vec2 &getOffsetPoints()')
    .func(nil, 'void setAnimation(cocostudio::ArmatureAnimation *animation)')
    .func(nil, 'cocostudio::ArmatureAnimation *getAnimation()')
    .func(nil, 'bool getArmatureTransformDirty()')
    .func(nil, 'void setArmatureData(cocostudio::ArmatureData *armatureData)')
    .func(nil, 'cocostudio::ArmatureData *getArmatureData()')
    .func(nil, 'void setParentBone(cocostudio::Bone *parentBone)')
    .func(nil, 'cocostudio::Bone *getParentBone()')
    .func(nil, 'void setVersion(float version)')
    .func(nil, 'float getVersion()')
    .func(nil, 'void setBatchNode(cocostudio::BatchNode *batchNode)')
    .func(nil, 'cocostudio::BatchNode *getBatchNode()')
    .prop('boneDic', nil, nil)
    .prop('blendFunc', nil, nil)
    .prop('offsetPoints', nil, nil)
    .prop('animation', nil, nil)
    .prop('armatureTransformDirty', nil, nil)
    .prop('armatureData', nil, nil)
    .prop('parentBone', nil, nil)
    .prop('version', nil, nil)
    .prop('batchNode', nil, nil)

typeconf 'cocostudio::ProcessBase'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .func(nil, 'ProcessBase()')
    .func(nil, 'void play(int durationTo, int durationTween, int loop, int tweenEasing)')
    .func(nil, 'void pause()')
    .func(nil, 'void resume()')
    .func(nil, 'void stop()')
    .func(nil, 'void update(float dt)')
    .func(nil, 'int getCurrentFrameIndex()')
    .func(nil, 'void setProcessScale(float processScale)')
    .func(nil, 'float getProcessScale()')
    .func(nil, 'void setIsPause(bool pause)')
    .func(nil, 'bool isPause()')
    .func(nil, 'void setIsComplete(bool complete)')
    .func(nil, 'bool isComplete()')
    .func(nil, 'void setIsPlaying(bool playing)')
    .func(nil, 'bool isPlaying()')
    .func(nil, 'float getCurrentPercent()')
    .func(nil, 'int getRawDuration()')
    .prop('currentFrameIndex', nil, nil)
    .prop('processScale', nil, nil)
    .prop('pause', nil, nil)
    .prop('complete', nil, nil)
    .prop('playing', nil, nil)
    .prop('currentPercent', nil, nil)
    .prop('rawDuration', nil, nil)

typeconf 'cocostudio::ActionManagerEx'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .func(nil, 'ActionManagerEx()')
    .func(nil, 'static cocostudio::ActionManagerEx *getInstance()')
    .func(nil, 'static void destroyInstance()')
    .func(nil, 'cocostudio::ActionObject *getActionByName(const char *jsonName, const char *actionName)')
    .func(nil, 'cocostudio::ActionObject *playActionByName(const char *jsonName, const char *actionName)', 'cocostudio::ActionObject *playActionByName(const char *jsonName, const char *actionName, cocos2d::CallFunc *func)')
    .func(nil, 'cocostudio::ActionObject *stopActionByName(const char *jsonName, const char *actionName)')
    .func(nil, 'void releaseActions()')
    .func(nil, 'int getStudioVersionNumber()')
    .prop('instance', nil, nil)
    .prop('studioVersionNumber', nil, nil)

typeconf 'cocostudio::ActionNode'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .func(nil, 'ActionNode()')
    .func(nil, 'void setUnitTime(float fTime)')
    .func(nil, 'float getUnitTime()')
    .func(nil, 'void setActionTag(int tag)')
    .func(nil, 'int getActionTag()')
    .func(nil, 'void setObject(cocos2d::Ref *node)')
    .func(nil, 'cocos2d::Ref *getObject()')
    .func(nil, 'void insertFrame(int index, cocostudio::ActionFrame *frame)')
    .func(nil, 'void addFrame(cocostudio::ActionFrame *frame)')
    .func(nil, 'void deleteFrame(cocostudio::ActionFrame *frame)')
    .func(nil, 'void clearAllFrame()')
    .func(nil, 'int getFirstFrameIndex()')
    .func(nil, 'int getLastFrameIndex()')
    .func(nil, 'bool updateActionToTimeLine(float fTime)')
    .func(nil, 'void playAction()')
    .func(nil, 'void stopAction()')
    .func(nil, 'bool isActionDoneOnce()')
    .prop('unitTime', nil, nil)
    .prop('actionTag', nil, nil)
    .prop('object', nil, nil)
    .prop('firstFrameIndex', nil, nil)
    .prop('lastFrameIndex', nil, nil)
    .prop('actionDoneOnce', nil, nil)

typeconf 'cocostudio::ActionObject'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .func(nil, 'ActionObject()')
    .func(nil, 'void setName(const char *name)')
    .func(nil, 'const char *getName()')
    .func(nil, 'void setLoop(bool bLoop)')
    .func(nil, 'bool getLoop()')
    .func(nil, 'void setUnitTime(float fTime)')
    .func(nil, 'float getUnitTime()')
    .func(nil, 'void setCurrentTime(float fTime)')
    .func(nil, 'float getCurrentTime()')
    .func(nil, 'float getTotalTime()')
    .func(nil, 'bool isPlaying()')
    .func(nil, 'void play()', 'void play(cocos2d::CallFunc *func)')
    .func(nil, 'void pause()')
    .func(nil, 'void stop()')
    .func(nil, 'void addActionNode(cocostudio::ActionNode *node)')
    .func(nil, 'void removeActionNode(cocostudio::ActionNode *node)')
    .func(nil, 'void updateToFrameByTime(float fTime)')
    .func(nil, 'void simulationActionUpdate(float dt)')
    .prop('name', nil, nil)
    .prop('loop', nil, nil)
    .prop('unitTime', nil, nil)
    .prop('currentTime', nil, nil)
    .prop('totalTime', nil, nil)
    .prop('playing', nil, nil)

typeconf 'cocostudio::ArmatureAnimation'
    .supercls('cocostudio::ProcessBase')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .func(nil, 'static cocostudio::ArmatureAnimation *create(cocostudio::Armature *armature)')
    .func(nil, 'ArmatureAnimation()')
    .func(nil, 'bool init(cocostudio::Armature *armature)')
    .func(nil, 'void setSpeedScale(float speedScale)')
    .func(nil, 'float getSpeedScale()')
    .func(nil, 'void play(const std::string &animationName, @optional int durationTo, @optional int loop)', '@using void play(int durationTo, int durationTween, int loop, int tweenEasing)')
    .func(nil, 'void playWithIndex(int animationIndex, @optional int durationTo, @optional int loop)')
    .func(nil, 'void playWithNames(const std::vector<std::string> &movementNames, @optional int durationTo, @optional bool loop)')
    .func(nil, 'void playWithIndexes(const std::vector<int> &movementIndexes, @optional int durationTo, @optional bool loop)')
    .func(nil, 'void gotoAndPlay(int frameIndex)')
    .func(nil, 'void gotoAndPause(int frameIndex)')
    .func(nil, 'ssize_t getMovementCount()')
    .func(nil, 'std::string getCurrentMovementID()')
    .func(nil, 'void setAnimationData(cocostudio::AnimationData *data)')
    .func(nil, 'cocostudio::AnimationData *getAnimationData()')
    .func(nil, 'cocos2d::Ref *getUserObject()')
    .func(nil, 'void setUserObject(cocos2d::Ref *userObject)')
    .callback {
        funcs =  {
            'void setMovementEventCallFunc(@localvar @nullable std::function<void (cocostudio::Armature *, cocostudio::MovementEventType, const std::string &)> listener)'
        },
        tag_maker = 'MovementEventCallFunc',
        tag_mode = 'replace',
        tag_store = 0,
        tag_scope = 'object',
    }
    .callback {
        funcs =  {
            'void setFrameEventCallFunc(@localvar @nullable std::function<void (cocostudio::Bone *, const std::string &, int, int)> listener)'
        },
        tag_maker = 'FrameEventCallFunc',
        tag_mode = 'replace',
        tag_store = 0,
        tag_scope = 'object',
    }
    .prop('speedScale', nil, nil)
    .prop('movementCount', nil, nil)
    .prop('currentMovementID', nil, nil)
    .prop('animationData', nil, nil)
    .prop('userObject', nil, nil)

typeconf 'cocostudio::ArmatureData'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .func(nil, 'static cocostudio::ArmatureData *create()')
    .func(nil, 'ArmatureData()')
    .func(nil, 'bool init()')
    .func(nil, 'void addBoneData(cocostudio::BoneData *boneData)')
    .func(nil, 'cocostudio::BoneData *getBoneData(const std::string &boneName)')
    .var('name', 'std::string name')
    .var('boneDataDic', 'cocos2d::Map<std::string, BoneData *> boneDataDic')
    .var('dataVersion', 'float dataVersion')

typeconf 'cocostudio::ArmatureDataManager'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .func(nil, 'static cocostudio::ArmatureDataManager *getInstance()')
    .func(nil, 'static void destroyInstance()')
    .func(nil, 'bool init()')
    .func(nil, 'void addArmatureData(const std::string &id, cocostudio::ArmatureData *armatureData, @optional const std::string &configFilePath)')
    .func(nil, 'cocostudio::ArmatureData *getArmatureData(const std::string &id)')
    .func(nil, 'void removeArmatureData(const std::string &id)')
    .func(nil, 'void addAnimationData(const std::string &id, cocostudio::AnimationData *animationData, @optional const std::string &configFilePath)')
    .func(nil, 'cocostudio::AnimationData *getAnimationData(const std::string &id)')
    .func(nil, 'void removeAnimationData(const std::string &id)')
    .func(nil, 'void addTextureData(const std::string &id, cocostudio::TextureData *textureData, @optional const std::string &configFilePath)')
    .func(nil, 'cocostudio::TextureData *getTextureData(const std::string &id)')
    .func(nil, 'void removeTextureData(const std::string &id)')
    .func(nil, 'void addArmatureFileInfo(const std::string &configFilePath)', 'void addArmatureFileInfo(const std::string &imagePath, const std::string &plistPath, const std::string &configFilePath)')
    .func(nil, 'void addSpriteFrameFromFile(const std::string &plistPath, const std::string &imagePath, @optional const std::string &configFilePath)')
    .func(nil, 'void removeArmatureFileInfo(const std::string &configFilePath)')
    .func(nil, 'bool isAutoLoadSpriteFile()')
    .func(nil, 'const cocos2d::Map<std::string, ArmatureData *> &getArmatureDatas()')
    .func(nil, 'const cocos2d::Map<std::string, AnimationData *> &getAnimationDatas()')
    .func(nil, 'const cocos2d::Map<std::string, TextureData *> &getTextureDatas()')
    .prop('instance', nil, nil)
    .prop('autoLoadSpriteFile', nil, nil)
    .prop('armatureDatas', nil, nil)
    .prop('animationDatas', nil, nil)
    .prop('textureDatas', nil, nil)

typeconf 'cocostudio::DisplayData'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .func(nil, 'static cocostudio::DisplayData *create()')
    .func(nil, 'static std::string changeDisplayToTexture(const std::string &displayName)')
    .func(nil, 'DisplayData()')
    .func(nil, 'void copy(cocostudio::DisplayData *displayData)')
    .var('displayType', 'cocostudio::DisplayType displayType')
    .var('displayName', 'std::string displayName')

typeconf 'cocostudio::ArmatureDisplayData'
    .supercls('cocostudio::DisplayData')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .func(nil, 'static cocostudio::ArmatureDisplayData *create()')
    .func(nil, 'ArmatureDisplayData()')

typeconf 'cocostudio::ArmatureMovementDispatcher'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)

typeconf 'cocostudio::BaseData'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .func(nil, 'static cocostudio::BaseData *create()')
    .func(nil, 'BaseData()')
    .func(nil, 'void copy(const cocostudio::BaseData *node)')
    .func(nil, 'void subtract(cocostudio::BaseData *from, cocostudio::BaseData *to, bool limit)')
    .func(nil, 'void setColor(const cocos2d::Color4B &color)')
    .func(nil, 'cocos2d::Color4B getColor()')
    .var('x', 'float x')
    .var('y', 'float y')
    .var('zOrder', 'int zOrder')
    .var('skewX', 'float skewX')
    .var('skewY', 'float skewY')
    .var('scaleX', 'float scaleX')
    .var('scaleY', 'float scaleY')
    .var('tweenRotate', 'float tweenRotate')
    .var('isUseColorInfo', 'bool isUseColorInfo')
    .var('a', 'int a')
    .var('r', 'int r')
    .var('g', 'int g')
    .var('b', 'int b')
    .prop('color', nil, nil)

typeconf 'cocostudio::BaseTriggerAction'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .func(nil, 'bool init()')
    .func(nil, 'void done()')
    .func(nil, 'void removeAll()')

typeconf 'cocostudio::BaseTriggerCondition'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .func(nil, 'bool init()')
    .func(nil, 'bool detect()')
    .func(nil, 'void removeAll()')

typeconf 'cocostudio::BatchNode'
    .supercls('cocos2d::Node')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .func(nil, 'static cocostudio::BatchNode *create()')
    .func(nil, 'BatchNode()')

typeconf 'cocostudio::Bone'
    .supercls('cocos2d::Node')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .func(nil, 'static cocostudio::Bone *create()', 'static cocostudio::Bone *create(const std::string &name)')
    .func(nil, 'Bone()')
    .func(nil, '@using bool init()', 'bool init(const std::string &name)')
    .func(nil, 'void addDisplay(cocostudio::DisplayData *displayData, int index)', 'void addDisplay(cocos2d::Node *display, int index)')
    .func(nil, 'void removeDisplay(int index)')
    .func(nil, 'void changeDisplayWithIndex(int index, bool force)')
    .func(nil, 'void changeDisplayWithName(const std::string &name, bool force)')
    .func(nil, 'void addChildBone(cocostudio::Bone *child)')
    .func(nil, 'void setParentBone(cocostudio::Bone *parent)')
    .func(nil, 'cocostudio::Bone *getParentBone()')
    .func(nil, '@delref(children | parent) void removeFromParent(bool recursion)', '@using @delref(children | parent) void removeFromParent()')
    .func(nil, 'void removeChildBone(cocostudio::Bone *bone, bool recursion)')
    .func(nil, 'void updateColor()')
    .func(nil, 'void updateZOrder()')
    .func(nil, 'void setLocalZOrder(int zOrder)')
    .func(nil, 'cocostudio::Tween *getTween()')
    .func(nil, 'void setTransformDirty(bool dirty)')
    .func(nil, 'bool isTransformDirty()')
    .func(nil, 'cocos2d::Mat4 getNodeToArmatureTransform()')
    .func(nil, 'cocos2d::Node *getDisplayRenderNode()')
    .func(nil, 'cocostudio::DisplayType getDisplayRenderNodeType()')
    .func(nil, 'cocostudio::ColliderDetector *getColliderDetector()')
    .func(nil, 'void setBoneData(cocostudio::BoneData *boneData)')
    .func(nil, 'cocostudio::BoneData *getBoneData()')
    .func(nil, 'void setArmature(cocostudio::Armature *armature)')
    .func(nil, 'cocostudio::Armature *getArmature()')
    .func(nil, 'void setChildArmature(cocostudio::Armature *childArmature)')
    .func(nil, 'cocostudio::Armature *getChildArmature()')
    .func(nil, 'cocostudio::DisplayManager *getDisplayManager()')
    .func(nil, 'void setIgnoreMovementBoneData(bool ignore)')
    .func(nil, 'bool isIgnoreMovementBoneData()')
    .func(nil, 'void setBlendFunc(const cocos2d::BlendFunc &blendFunc)')
    .func(nil, 'cocos2d::BlendFunc getBlendFunc()')
    .func(nil, 'void setBlendDirty(bool dirty)')
    .func(nil, 'bool isBlendDirty()')
    .func(nil, 'cocostudio::FrameData *getTweenData()')
    .func(nil, 'cocostudio::BaseData *getWorldInfo()')
    .prop('parentBone', nil, nil)
    .prop('tween', nil, nil)
    .prop('transformDirty', nil, nil)
    .prop('nodeToArmatureTransform', nil, nil)
    .prop('displayRenderNode', nil, nil)
    .prop('displayRenderNodeType', nil, nil)
    .prop('colliderDetector', nil, nil)
    .prop('boneData', nil, nil)
    .prop('armature', nil, nil)
    .prop('childArmature', nil, nil)
    .prop('displayManager', nil, nil)
    .prop('ignoreMovementBoneData', nil, nil)
    .prop('blendFunc', nil, nil)
    .prop('blendDirty', nil, nil)
    .prop('tweenData', nil, nil)
    .prop('worldInfo', nil, nil)
    .insert('removeFromParent', {
        before = [[
            if (!self->getParent()) {
                return 0;
            }
            olua_push_cppobj<cocos2d::Node>(L, self->getParent());
            int parent = lua_gettop(L);
        ]],
        after = nil,
        cbefore = nil,
        cafter = nil,
    })

typeconf 'cocostudio::BoneData'
    .supercls('cocostudio::BaseData')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .func(nil, 'static cocostudio::BoneData *create()')
    .func(nil, 'BoneData()')
    .func(nil, 'bool init()')
    .func(nil, 'void addDisplayData(cocostudio::DisplayData *displayData)')
    .func(nil, 'cocostudio::DisplayData *getDisplayData(int index)')
    .var('name', 'std::string name')
    .var('parentName', 'std::string parentName')
    .var('displayDataList', 'cocos2d::Vector<DisplayData *> displayDataList')
    .var('boneDataTransform', 'cocos2d::AffineTransform boneDataTransform')

typeconf 'cocostudio::CocoLoader'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)

typeconf 'cocostudio::ColliderBody'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .func(nil, 'ColliderBody(cocostudio::ContourData *contourData)')
    .func(nil, 'cocostudio::ContourData *getContourData()')
    .func(nil, 'const std::vector<cocos2d::Vec2> &getCalculatedVertexList()')
    .prop('contourData', nil, nil)
    .prop('calculatedVertexList', nil, nil)

typeconf 'cocostudio::ColliderDetector'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .func(nil, 'static cocostudio::ColliderDetector *create()', 'static cocostudio::ColliderDetector *create(cocostudio::Bone *bone)')
    .func(nil, 'ColliderDetector()')
    .func(nil, 'bool init()', 'bool init(cocostudio::Bone *bone)')
    .func(nil, 'void addContourData(cocostudio::ContourData *contourData)')
    .func(nil, 'void addContourDataList(cocos2d::Vector<ContourData *> &contourDataList)')
    .func(nil, 'void removeContourData(cocostudio::ContourData *contourData)')
    .func(nil, 'void removeAll()')
    .func(nil, 'void updateTransform(cocos2d::Mat4 &t)')
    .func(nil, 'void setActive(bool active)')
    .func(nil, 'bool getActive()')
    .func(nil, 'const cocos2d::Vector<ColliderBody *> &getColliderBodyList()')
    .func(nil, 'void setBone(cocostudio::Bone *bone)')
    .func(nil, 'cocostudio::Bone *getBone()')
    .prop('active', nil, nil)
    .prop('colliderBodyList', nil, nil)
    .prop('bone', nil, nil)

typeconf 'cocostudio::ColliderFilter'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)

typeconf 'cocostudio::ComAttribute'
    .supercls('cocos2d::Component')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .const('COMPONENT_NAME', 'cocostudio::ComAttribute::COMPONENT_NAME', 'const std::string')
    .func(nil, 'static cocos2d::Ref *createInstance()')
    .func(nil, 'ComAttribute()')
    .func(nil, 'static cocostudio::ComAttribute *create()')
    .func(nil, 'void setInt(const std::string &key, int value)')
    .func(nil, 'void setFloat(const std::string &key, float value)')
    .func(nil, 'void setBool(const std::string &key, bool value)')
    .func(nil, 'void setString(const std::string &key, const std::string &value)')
    .func(nil, 'int getInt(const std::string &key, @optional int def)')
    .func(nil, 'float getFloat(const std::string &key, @optional float def)')
    .func(nil, 'bool getBool(const std::string &key, @optional bool def)')
    .func(nil, 'std::string getString(const std::string &key, @optional const std::string &def)')
    .func(nil, 'bool parse(const std::string &jsonFile)')

typeconf 'cocostudio::ComAudio'
    .supercls('cocos2d::Component')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .const('COMPONENT_NAME', 'cocostudio::ComAudio::COMPONENT_NAME', 'const std::string')
    .func(nil, 'static cocos2d::Ref *createInstance()')
    .func(nil, 'ComAudio()')
    .func(nil, 'static cocostudio::ComAudio *create()')
    .func(nil, 'void end()')
    .func(nil, 'void preloadBackgroundMusic(const char *pszFilePath)')
    .func(nil, 'void playBackgroundMusic(const char *pszFilePath, bool bLoop)', 'void playBackgroundMusic(const char *pszFilePath)', 'void playBackgroundMusic()')
    .func(nil, 'void stopBackgroundMusic(bool bReleaseData)', 'void stopBackgroundMusic()')
    .func(nil, 'void pauseBackgroundMusic()')
    .func(nil, 'void resumeBackgroundMusic()')
    .func(nil, 'void rewindBackgroundMusic()')
    .func(nil, 'bool willPlayBackgroundMusic()')
    .func(nil, 'bool isBackgroundMusicPlaying()')
    .func(nil, 'float getBackgroundMusicVolume()')
    .func(nil, 'void setBackgroundMusicVolume(float volume)')
    .func(nil, 'float getEffectsVolume()')
    .func(nil, 'void setEffectsVolume(float volume)')
    .func(nil, 'unsigned int playEffect(const char *pszFilePath, bool bLoop)', 'unsigned int playEffect(const char *pszFilePath)', 'unsigned int playEffect()')
    .func(nil, 'void pauseEffect(unsigned int nSoundId)')
    .func(nil, 'void pauseAllEffects()')
    .func(nil, 'void resumeEffect(unsigned int nSoundId)')
    .func(nil, 'void resumeAllEffects()')
    .func(nil, 'void stopEffect(unsigned int nSoundId)')
    .func(nil, 'void stopAllEffects()')
    .func(nil, 'void preloadEffect(const char *pszFilePath)')
    .func(nil, 'void unloadEffect(const char *pszFilePath)')
    .func(nil, 'void setFile(const char *pszFilePath)')
    .func(nil, 'const char *getFile()')
    .func(nil, 'void setLoop(bool bLoop)')
    .func(nil, 'bool isLoop()')
    .func(nil, 'void start()')
    .func(nil, 'void stop()')
    .prop('backgroundMusicPlaying', nil, nil)
    .prop('backgroundMusicVolume', nil, nil)
    .prop('effectsVolume', nil, nil)
    .prop('file', nil, nil)
    .prop('loop', nil, nil)

typeconf 'cocostudio::ComController'
    .supercls('cocos2d::Component')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .const('COMPONENT_NAME', 'cocostudio::ComController::COMPONENT_NAME', 'const std::string')
    .func(nil, 'static cocos2d::Ref *createInstance()')
    .func(nil, 'ComController()')
    .func(nil, 'static cocostudio::ComController *create()')

typeconf 'cocostudio::ComRender'
    .supercls('cocos2d::Component')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .const('COMPONENT_NAME', 'cocostudio::ComRender::COMPONENT_NAME', 'const std::string')
    .func(nil, 'static cocos2d::Ref *createInstance()')
    .func(nil, 'static cocostudio::ComRender *create()', 'static cocostudio::ComRender *create(cocos2d::Node *node, const char *comName)')
    .func(nil, 'cocos2d::Node *getNode()')
    .func(nil, 'void setNode(cocos2d::Node *node)')
    .func(nil, 'ComRender()', 'ComRender(cocos2d::Node *node, const char *comName)')
    .prop('node', nil, nil)

typeconf 'cocostudio::ContourData'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .func(nil, 'static cocostudio::ContourData *create()')
    .func(nil, 'ContourData()')
    .func(nil, 'bool init()')
    .func(nil, 'void addVertex(cocos2d::Vec2 &vertex)')
    .var('vertexList', 'std::vector<cocos2d::Vec2> vertexList')

typeconf 'cocostudio::DataReaderHelper'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .func(nil, 'static cocostudio::DataReaderHelper *getInstance()')
    .func(nil, 'static void setPositionReadScale(float scale)')
    .func(nil, 'static float getPositionReadScale()')
    .func(nil, 'static void purge()')
    .func(nil, 'DataReaderHelper()')
    .func(nil, 'void addDataFromFile(const std::string &filePath)')
    .func(nil, 'void addDataAsyncCallBack(float dt)')
    .func(nil, 'void removeConfigFile(const std::string &configFile)')
    .prop('instance', nil, nil)
    .prop('positionReadScale', nil, nil)

typeconf 'cocostudio::DecorativeDisplay'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .func(nil, 'static cocostudio::DecorativeDisplay *create()')
    .func(nil, 'DecorativeDisplay()')
    .func(nil, 'bool init()')
    .func(nil, 'void setDisplay(cocos2d::Node *display)')
    .func(nil, 'cocos2d::Node *getDisplay()')
    .func(nil, 'void setDisplayData(cocostudio::DisplayData *data)')
    .func(nil, 'cocostudio::DisplayData *getDisplayData()')
    .func(nil, 'void setColliderDetector(cocostudio::ColliderDetector *detector)')
    .func(nil, 'cocostudio::ColliderDetector *getColliderDetector()')
    .prop('display', nil, nil)
    .prop('displayData', nil, nil)
    .prop('colliderDetector', nil, nil)

typeconf 'cocostudio::DisplayFactory'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .func(nil, 'static void addDisplay(cocostudio::Bone *bone, cocostudio::DecorativeDisplay *decoDisplay, cocostudio::DisplayData *displayData)')
    .func(nil, 'static void createDisplay(cocostudio::Bone *bone, cocostudio::DecorativeDisplay *decoDisplay)')
    .func(nil, 'static void updateDisplay(cocostudio::Bone *bone, float dt, bool dirty)')
    .func(nil, 'static void addSpriteDisplay(cocostudio::Bone *bone, cocostudio::DecorativeDisplay *decoDisplay, cocostudio::DisplayData *displayData)')
    .func(nil, 'static void createSpriteDisplay(cocostudio::Bone *bone, cocostudio::DecorativeDisplay *decoDisplay)')
    .func(nil, 'static void initSpriteDisplay(cocostudio::Bone *bone, cocostudio::DecorativeDisplay *decoDisplay, const char *displayName, cocostudio::Skin *skin)')
    .func(nil, 'static void addArmatureDisplay(cocostudio::Bone *bone, cocostudio::DecorativeDisplay *decoDisplay, cocostudio::DisplayData *displayData)')
    .func(nil, 'static void createArmatureDisplay(cocostudio::Bone *bone, cocostudio::DecorativeDisplay *decoDisplay)')
    .func(nil, 'static void updateArmatureDisplay(cocostudio::Bone *bone, cocos2d::Node *display, float dt)')
    .func(nil, 'static void addParticleDisplay(cocostudio::Bone *bone, cocostudio::DecorativeDisplay *decoDisplay, cocostudio::DisplayData *displayData)')
    .func(nil, 'static void createParticleDisplay(cocostudio::Bone *bone, cocostudio::DecorativeDisplay *decoDisplay)')
    .func(nil, 'static void updateParticleDisplay(cocostudio::Bone *bone, cocos2d::Node *display, float dt)')

typeconf 'cocostudio::DisplayManager'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .func(nil, 'static cocostudio::DisplayManager *create(cocostudio::Bone *bone)')
    .func(nil, 'DisplayManager()')
    .func(nil, 'bool init(cocostudio::Bone *bone)')
    .func(nil, 'void initDisplayList(cocostudio::BoneData *boneData)')
    .func(nil, 'void addDisplay(cocostudio::DisplayData *displayData, int index)', 'void addDisplay(cocos2d::Node *display, int index)')
    .func(nil, 'void removeDisplay(int index)')
    .func(nil, 'const cocos2d::Vector<DecorativeDisplay *> &getDecorativeDisplayList()')
    .func(nil, 'void changeDisplayWithIndex(int index, bool force)')
    .func(nil, 'void changeDisplayWithName(const std::string &name, bool force)')
    .func(nil, 'cocos2d::Node *getDisplayRenderNode()')
    .func(nil, 'cocostudio::DisplayType getDisplayRenderNodeType()')
    .func(nil, 'int getCurrentDisplayIndex()')
    .func(nil, 'void setCurrentDecorativeDisplay(cocostudio::DecorativeDisplay *decoDisplay)')
    .func(nil, 'cocostudio::DecorativeDisplay *getCurrentDecorativeDisplay()')
    .func(nil, 'cocostudio::DecorativeDisplay *getDecorativeDisplayByIndex(int index)')
    .func(nil, 'void setVisible(bool visible)')
    .func(nil, 'bool isVisible()')
    .func(nil, 'cocos2d::Size getContentSize()')
    .func(nil, 'cocos2d::Rect getBoundingBox()')
    .func(nil, 'cocos2d::Vec2 getAnchorPoint()')
    .func(nil, 'cocos2d::Vec2 getAnchorPointInPoints()')
    .func(nil, 'bool containPoint(cocos2d::Vec2 &_point)', 'bool containPoint(float x, float y)')
    .func(nil, 'void setForceChangeDisplay(bool force)')
    .func(nil, 'bool isForceChangeDisplay()')
    .prop('decorativeDisplayList', nil, nil)
    .prop('displayRenderNode', nil, nil)
    .prop('displayRenderNodeType', nil, nil)
    .prop('currentDisplayIndex', nil, nil)
    .prop('currentDecorativeDisplay', nil, nil)
    .prop('visible', nil, nil)
    .prop('contentSize', nil, nil)
    .prop('boundingBox', nil, nil)
    .prop('anchorPoint', nil, nil)
    .prop('anchorPointInPoints', nil, nil)
    .prop('forceChangeDisplay', nil, nil)

typeconf 'cocostudio::FrameData'
    .supercls('cocostudio::BaseData')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .func(nil, 'static cocostudio::FrameData *create()')
    .func(nil, 'FrameData()')
    .var('frameID', 'int frameID')
    .var('duration', 'int duration')
    .var('tweenEasing', 'cocos2d::tweenfunc::TweenType tweenEasing')
    .var('easingParamNumber', 'int easingParamNumber')
    .var('isTween', 'bool isTween')
    .var('displayIndex', 'int displayIndex')
    .var('blendFunc', 'cocos2d::BlendFunc blendFunc')
    .var('strEvent', 'std::string strEvent')
    .var('strMovement', 'std::string strMovement')
    .var('strSound', 'std::string strSound')
    .var('strSoundEffect', 'std::string strSoundEffect')

typeconf 'cocostudio::GUIReader'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .func(nil, 'static cocostudio::GUIReader *getInstance()')
    .func(nil, 'static void destroyInstance()')
    .func(nil, 'cocos2d::ui::Widget *widgetFromJsonFile(const char *fileName)')
    .func(nil, 'cocos2d::ui::Widget *widgetFromBinaryFile(const char *fileName)')
    .func(nil, 'int getVersionInteger(const char *str)')
    .func(nil, 'void storeFileDesignSize(const char *fileName, const cocos2d::Size &size)')
    .func(nil, 'cocos2d::Size getFileDesignSize(const char *fileName)')
    .func(nil, 'void setFilePath(const std::string &strFilePath)')
    .func(nil, 'const std::string &getFilePath()')
    .prop('instance', nil, nil)
    .prop('filePath', nil, nil)

typeconf 'cocostudio::InputDelegate'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .func(nil, 'InputDelegate()')
    .func(nil, 'bool isTouchEnabled()')
    .func(nil, 'void setTouchEnabled(bool value)')
    .func(nil, 'bool isAccelerometerEnabled()')
    .func(nil, 'void setAccelerometerEnabled(bool value)')
    .func(nil, 'bool isKeypadEnabled()')
    .func(nil, 'void setKeypadEnabled(bool value)')
    .func(nil, 'void setTouchMode(cocos2d::Touch::DispatchMode mode)')
    .func(nil, 'cocos2d::Touch::DispatchMode getTouchMode()')
    .func(nil, 'void setTouchPriority(int priority)')
    .func(nil, 'int getTouchPriority()')
    .func(nil, 'void onAcceleration(cocos2d::Acceleration *acc, cocos2d::Event *event)')
    .func(nil, 'void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event)')
    .func(nil, 'void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event)')
    .func(nil, 'bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)')
    .func(nil, 'void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event)')
    .func(nil, 'void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event)')
    .func(nil, 'void onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event *event)')
    .func(nil, 'void onTouchesBegan(const std::vector<cocos2d::Touch *> &touches, cocos2d::Event *event)')
    .func(nil, 'void onTouchesMoved(const std::vector<cocos2d::Touch *> &touches, cocos2d::Event *event)')
    .func(nil, 'void onTouchesEnded(const std::vector<cocos2d::Touch *> &touches, cocos2d::Event *event)')
    .func(nil, 'void onTouchesCancelled(const std::vector<cocos2d::Touch *> &touches, cocos2d::Event *event)')
    .prop('touchEnabled', nil, nil)
    .prop('accelerometerEnabled', nil, nil)
    .prop('keypadEnabled', nil, nil)
    .prop('touchMode', nil, nil)
    .prop('touchPriority', nil, nil)

typeconf 'cocostudio::MovementBoneData'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .func(nil, 'static cocostudio::MovementBoneData *create()')
    .func(nil, 'MovementBoneData()')
    .func(nil, 'bool init()')
    .func(nil, 'void addFrameData(cocostudio::FrameData *frameData)')
    .func(nil, 'cocostudio::FrameData *getFrameData(int index)')
    .var('delay', 'float delay')
    .var('scale', 'float scale')
    .var('duration', 'float duration')
    .var('name', 'std::string name')
    .var('frameList', 'cocos2d::Vector<FrameData *> frameList')

typeconf 'cocostudio::MovementData'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .func(nil, 'static cocostudio::MovementData *create()')
    .func(nil, 'MovementData()')
    .func(nil, 'void addMovementBoneData(cocostudio::MovementBoneData *movBoneData)')
    .func(nil, 'cocostudio::MovementBoneData *getMovementBoneData(const std::string &boneName)')
    .var('name', 'std::string name')
    .var('duration', 'int duration')
    .var('scale', 'float scale')
    .var('durationTo', 'int durationTo')
    .var('durationTween', 'int durationTween')
    .var('loop', 'bool loop')
    .var('tweenEasing', 'cocos2d::tweenfunc::TweenType tweenEasing')
    .var('movBoneDataDic', 'cocos2d::Map<std::string, MovementBoneData *> movBoneDataDic')

typeconf 'cocostudio::ParticleDisplayData'
    .supercls('cocostudio::DisplayData')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .func(nil, 'static cocostudio::ParticleDisplayData *create()')
    .func(nil, 'ParticleDisplayData()')

typeconf 'cocostudio::SceneReader::AttachComponentType'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .enum('EMPTY_NODE', 'cocostudio::SceneReader::AttachComponentType::EMPTY_NODE')
    .enum('RENDER_NODE', 'cocostudio::SceneReader::AttachComponentType::RENDER_NODE')
    .enum('DEFAULT', 'cocostudio::SceneReader::AttachComponentType::DEFAULT')

typeconf 'cocostudio::SceneReader'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .func(nil, 'static cocostudio::SceneReader *getInstance()')
    .func(nil, 'static void destroyInstance()')
    .func(nil, 'static const char *sceneReaderVersion()')
    .func(nil, 'cocos2d::Node *createNodeWithSceneFile(const std::string &fileName, @optional cocostudio::SceneReader::AttachComponentType attachComponent)')
    .func(nil, 'cocos2d::Node *getNodeByTag(int nTag)')
    .func(nil, 'cocostudio::SceneReader::AttachComponentType getAttachComponentType()')
    .func(nil, 'SceneReader()')
    .callback {
        funcs =  {
            'void setTarget(@localvar @nullable const std::function<void (cocos2d::Ref *, void *)> &selector)'
        },
        tag_maker = 'Target',
        tag_mode = 'replace',
        tag_store = 0,
        tag_scope = 'object',
    }
    .prop('instance', nil, nil)
    .prop('attachComponentType', nil, nil)

typeconf 'cocostudio::Skin'
    .supercls('cocos2d::Sprite')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .func(nil, 'static cocostudio::Skin *create()', 'static cocostudio::Skin *create(const std::string &pszFileName)')
    .func(nil, 'static cocostudio::Skin *createWithSpriteFrameName(const std::string &pszSpriteFrameName)')
    .func(nil, 'Skin()')
    .func(nil, 'void updateArmatureTransform()')
    .func(nil, 'cocos2d::Mat4 getNodeToWorldTransformAR()')
    .func(nil, 'void setSkinData(const cocostudio::BaseData &data)')
    .func(nil, 'const cocostudio::BaseData &getSkinData()')
    .func(nil, 'void setBone(cocostudio::Bone *bone)')
    .func(nil, 'cocostudio::Bone *getBone()')
    .func(nil, 'const std::string &getDisplayName()')
    .prop('nodeToWorldTransformAR', nil, nil)
    .prop('skinData', nil, nil)
    .prop('bone', nil, nil)
    .prop('displayName', nil, nil)

typeconf 'cocostudio::SpriteDisplayData'
    .supercls('cocostudio::DisplayData')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .func(nil, 'static cocostudio::SpriteDisplayData *create()')
    .func(nil, 'SpriteDisplayData()')
    .var('skinData', 'cocostudio::BaseData skinData')

typeconf 'cocostudio::SpriteFrameCacheHelper'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .func(nil, 'static cocostudio::SpriteFrameCacheHelper *getInstance()')
    .func(nil, 'static void purge()')
    .func(nil, 'void addSpriteFrameFromFile(const std::string &plistPath, const std::string &imagePath)')
    .func(nil, 'void removeSpriteFrameFromFile(const std::string &plistPath)')
    .prop('instance', nil, nil)

typeconf 'cocostudio::TextureData'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .func(nil, 'static cocostudio::TextureData *create()')
    .func(nil, 'TextureData()')
    .func(nil, 'bool init()')
    .func(nil, 'void addContourData(cocostudio::ContourData *contourData)')
    .func(nil, 'cocostudio::ContourData *getContourData(int index)')
    .var('height', 'float height')
    .var('width', 'float width')
    .var('pivotX', 'float pivotX')
    .var('pivotY', 'float pivotY')
    .var('name', 'std::string name')
    .var('contourDataList', 'cocos2d::Vector<ContourData *> contourDataList')

typeconf 'cocostudio::Tween'
    .supercls('cocostudio::ProcessBase')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .func(nil, 'static cocostudio::Tween *create(cocostudio::Bone *bone)')
    .func(nil, 'Tween()')
    .func(nil, 'bool init(cocostudio::Bone *bone)')
    .func(nil, 'void play(cocostudio::MovementBoneData *movementBoneData, int durationTo, int durationTween, int loop, int tweenEasing)', '@using void play(int durationTo, int durationTween, int loop, int tweenEasing)')
    .func(nil, 'void setAnimation(cocostudio::ArmatureAnimation *animation)')
    .func(nil, 'cocostudio::ArmatureAnimation *getAnimation()')
    .func(nil, 'void gotoAndPlay(int frameIndex)')
    .func(nil, 'void gotoAndPause(int frameIndex)')
    .func(nil, 'void setMovementBoneData(cocostudio::MovementBoneData *data)')
    .func(nil, 'const cocostudio::MovementBoneData *getMovementBoneData()')
    .prop('animation', nil, nil)
    .prop('movementBoneData', nil, nil)

typeconf 'cocostudio::timeline::InnerActionType'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .enum('LoopAction', 'cocostudio::timeline::InnerActionType::LoopAction')
    .enum('NoLoopAction', 'cocostudio::timeline::InnerActionType::NoLoopAction')
    .enum('SingleFrame', 'cocostudio::timeline::InnerActionType::SingleFrame')

typeconf 'cocostudio::timeline::Frame'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .func(nil, 'void setFrameIndex(unsigned int frameIndex)')
    .func(nil, 'unsigned int getFrameIndex()')
    .func(nil, 'void setTimeline(@addref(timeline ^) cocostudio::timeline::Timeline *timeline)')
    .func(nil, '@addref(timeline ^) cocostudio::timeline::Timeline *getTimeline()')
    .func(nil, 'void setNode(@addref(node ^) cocos2d::Node *node)')
    .func(nil, '@addref(node ^) cocos2d::Node *getNode()')
    .func(nil, 'void setTween(bool tween)')
    .func(nil, 'bool isTween()')
    .func(nil, 'void setTweenType(const cocos2d::tweenfunc::TweenType &tweenType)')
    .func(nil, 'cocos2d::tweenfunc::TweenType getTweenType()')
    .func(nil, 'void setEasingParams(const std::vector<float> &easingParams)')
    .func(nil, 'const std::vector<float> &getEasingParams()')
    .func(nil, 'bool isEnterWhenPassed()')
    .func(nil, 'void onEnter(cocostudio::timeline::Frame *nextFrame, int currentFrameIndex)')
    .func(nil, 'void apply(float percent)')
    .func(nil, 'cocostudio::timeline::Frame *clone()')
    .prop('frameIndex', nil, nil)
    .prop('timeline', nil, nil)
    .prop('node', nil, nil)
    .prop('tween', nil, nil)
    .prop('tweenType', nil, nil)
    .prop('easingParams', nil, nil)
    .prop('enterWhenPassed', nil, nil)

typeconf 'cocostudio::timeline::AlphaFrame'
    .supercls('cocostudio::timeline::Frame')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .func(nil, 'static cocostudio::timeline::AlphaFrame *create()')
    .func(nil, 'AlphaFrame()')
    .func(nil, 'void setAlpha(uint8_t alpha)')
    .func(nil, 'uint8_t getAlpha()')
    .prop('alpha', nil, nil)

typeconf 'cocostudio::timeline::AnchorPointFrame'
    .supercls('cocostudio::timeline::Frame')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .func(nil, 'static cocostudio::timeline::AnchorPointFrame *create()')
    .func(nil, 'AnchorPointFrame()')
    .func(nil, 'void setAnchorPoint(const cocos2d::Point &point)')
    .func(nil, 'cocos2d::Point getAnchorPoint()')
    .prop('anchorPoint', nil, nil)

typeconf 'cocostudio::timeline::BlendFuncFrame'
    .supercls('cocostudio::timeline::Frame')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .func(nil, 'static cocostudio::timeline::BlendFuncFrame *create()')
    .func(nil, 'BlendFuncFrame()')
    .func(nil, 'cocos2d::BlendFunc getBlendFunc()')
    .func(nil, 'void setBlendFunc(cocos2d::BlendFunc blendFunc)')
    .prop('blendFunc', nil, nil)

typeconf 'cocostudio::timeline::ColorFrame'
    .supercls('cocostudio::timeline::Frame')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .func(nil, 'static cocostudio::timeline::ColorFrame *create()')
    .func(nil, 'ColorFrame()')
    .func(nil, 'void setColor(const cocos2d::Color3B &color)')
    .func(nil, 'cocos2d::Color3B getColor()')
    .prop('color', nil, nil)

typeconf 'cocostudio::timeline::EventFrame'
    .supercls('cocostudio::timeline::Frame')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .func(nil, 'static cocostudio::timeline::EventFrame *create()')
    .func(nil, 'void init()')
    .func(nil, 'EventFrame()')
    .func(nil, 'void setEvent(std::string event)')
    .func(nil, 'std::string getEvent()')
    .prop('event', nil, nil)

typeconf 'cocostudio::timeline::InnerActionFrame'
    .supercls('cocostudio::timeline::Frame')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .const('AnimationAllName', 'cocostudio::timeline::InnerActionFrame::AnimationAllName', 'const std::string')
    .func(nil, 'static cocostudio::timeline::InnerActionFrame *create()')
    .func(nil, 'InnerActionFrame()')
    .func(nil, 'void setInnerActionType(cocostudio::timeline::InnerActionType type)')
    .func(nil, 'cocostudio::timeline::InnerActionType getInnerActionType()')
    .func(nil, 'void setEnterWithName(bool isEnterWithName)')
    .func(nil, 'void setStartFrameIndex(int frameIndex)')
    .func(nil, 'int getStartFrameIndex()')
    .func(nil, 'void setEndFrameIndex(int frameIndex)')
    .func(nil, 'int getEndFrameIndex()')
    .func(nil, 'void setAnimationName(const std::string &animationNamed)')
    .func(nil, 'void setSingleFrameIndex(int frameIndex)')
    .func(nil, 'int getSingleFrameIndex()')
    .prop('innerActionType', nil, nil)
    .prop('startFrameIndex', nil, nil)
    .prop('endFrameIndex', nil, nil)
    .prop('singleFrameIndex', nil, nil)

typeconf 'cocostudio::timeline::PlayableFrame'
    .supercls('cocostudio::timeline::Frame')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .const('PLAYABLE_EXTENTION', 'cocostudio::timeline::PlayableFrame::PLAYABLE_EXTENTION', 'const std::string')
    .func(nil, 'static cocostudio::timeline::PlayableFrame *create()')
    .func(nil, 'PlayableFrame()')
    .func(nil, 'std::string getPlayableAct()')
    .func(nil, 'void setPlayableAct(std::string playact)')
    .prop('playableAct', nil, nil)

typeconf 'cocostudio::timeline::PositionFrame'
    .supercls('cocostudio::timeline::Frame')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .func(nil, 'static cocostudio::timeline::PositionFrame *create()')
    .func(nil, 'PositionFrame()')
    .func(nil, 'void setPosition(const cocos2d::Point &position)')
    .func(nil, 'cocos2d::Point getPosition()')
    .func(nil, 'void setX(float x)')
    .func(nil, 'void setY(float y)')
    .func(nil, 'float getX()')
    .func(nil, 'float getY()')
    .prop('position', nil, nil)
    .prop('x', nil, nil)
    .prop('y', nil, nil)

typeconf 'cocostudio::timeline::RotationFrame'
    .supercls('cocostudio::timeline::Frame')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .func(nil, 'static cocostudio::timeline::RotationFrame *create()')
    .func(nil, 'RotationFrame()')
    .func(nil, 'void setRotation(float rotation)')
    .func(nil, 'float getRotation()')
    .prop('rotation', nil, nil)

typeconf 'cocostudio::timeline::SkewFrame'
    .supercls('cocostudio::timeline::Frame')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .func(nil, 'static cocostudio::timeline::SkewFrame *create()')
    .func(nil, 'SkewFrame()')
    .func(nil, 'void setSkewX(float skewx)')
    .func(nil, 'float getSkewX()')
    .func(nil, 'void setSkewY(float skewy)')
    .func(nil, 'float getSkewY()')
    .prop('skewX', nil, nil)
    .prop('skewY', nil, nil)

typeconf 'cocostudio::timeline::RotationSkewFrame'
    .supercls('cocostudio::timeline::SkewFrame')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .func(nil, 'static cocostudio::timeline::RotationSkewFrame *create()')
    .func(nil, 'RotationSkewFrame()')

typeconf 'cocostudio::timeline::ScaleFrame'
    .supercls('cocostudio::timeline::Frame')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .func(nil, 'static cocostudio::timeline::ScaleFrame *create()')
    .func(nil, 'ScaleFrame()')
    .func(nil, 'void setScale(float scale)')
    .func(nil, 'void setScaleX(float scaleX)')
    .func(nil, 'float getScaleX()')
    .func(nil, 'void setScaleY(float scaleY)')
    .func(nil, 'float getScaleY()')
    .prop('scaleX', nil, nil)
    .prop('scaleY', nil, nil)

typeconf 'cocostudio::timeline::TextureFrame'
    .supercls('cocostudio::timeline::Frame')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .func(nil, 'static cocostudio::timeline::TextureFrame *create()')
    .func(nil, 'TextureFrame()')
    .func(nil, 'void setTextureName(std::string textureName)')
    .func(nil, 'std::string getTextureName()')
    .prop('textureName', nil, nil)

typeconf 'cocostudio::timeline::VisibleFrame'
    .supercls('cocostudio::timeline::Frame')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .func(nil, 'static cocostudio::timeline::VisibleFrame *create()')
    .func(nil, 'VisibleFrame()')
    .func(nil, 'void setVisible(bool visible)')
    .func(nil, 'bool isVisible()')
    .prop('visible', nil, nil)

typeconf 'cocostudio::timeline::ZOrderFrame'
    .supercls('cocostudio::timeline::Frame')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .func(nil, 'static cocostudio::timeline::ZOrderFrame *create()')
    .func(nil, 'ZOrderFrame()')
    .func(nil, 'void setZOrder(int zorder)')
    .func(nil, 'int getZOrder()')
    .prop('zOrder', nil, nil)

typeconf 'cocostudio::timeline::ActionTimelineCache'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .func(nil, 'static cocostudio::timeline::ActionTimelineCache *getInstance()')
    .func(nil, 'static void destroyInstance()')
    .func(nil, 'void purge()')
    .func(nil, 'void init()')
    .func(nil, 'void removeAction(const std::string &fileName)')
    .func(nil, 'static cocostudio::timeline::ActionTimeline *createAction(const std::string &fileName)')
    .func(nil, 'cocostudio::timeline::ActionTimeline *createActionFromJson(const std::string &fileName)')
    .func(nil, 'cocostudio::timeline::ActionTimeline *createActionFromContent(const std::string &fileName, const std::string &content)')
    .func(nil, 'cocostudio::timeline::ActionTimeline *loadAnimationActionWithFile(const std::string &fileName)')
    .func(nil, 'cocostudio::timeline::ActionTimeline *loadAnimationActionWithContent(const std::string &fileName, const std::string &content)')
    .func(nil, 'cocostudio::timeline::ActionTimeline *createActionWithFlatBuffersFile(const std::string &fileName)')
    .func(nil, 'cocostudio::timeline::ActionTimeline *createActionWithDataBuffer(cocos2d::Data data, const std::string &fileName)')
    .func(nil, 'cocostudio::timeline::ActionTimeline *loadAnimationActionWithFlatBuffersFile(const std::string &fileName)')
    .func(nil, 'cocostudio::timeline::ActionTimeline *loadAnimationWithDataBuffer(const cocos2d::Data &data, const std::string &fileName)')
    .func(nil, 'cocostudio::timeline::ActionTimeline *createActionWithFlatBuffersForSimulator(const std::string &fileName)')
    .prop('instance', nil, nil)

typeconf 'cocostudio::timeline::ActionTimelineData'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .func(nil, 'static cocostudio::timeline::ActionTimelineData *create(int actionTag)')
    .func(nil, 'void setActionTag(int actionTag)')
    .func(nil, 'int getActionTag()')
    .func(nil, 'ActionTimelineData()')
    .func(nil, 'bool init(int actionTag)')
    .prop('actionTag', nil, nil)

typeconf 'cocostudio::timeline::ActionTimelineNode'
    .supercls('cocos2d::Node')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .func(nil, 'static cocostudio::timeline::ActionTimelineNode *create(cocos2d::Node *root, cocostudio::timeline::ActionTimeline *action)')
    .func(nil, 'ActionTimelineNode()')
    .func(nil, '@using bool init()', 'bool init(cocos2d::Node *root, cocostudio::timeline::ActionTimeline *action)')
    .func(nil, 'void setRoot(@addref(root ^) cocos2d::Node *root)')
    .func(nil, '@addref(root ^) cocos2d::Node *getRoot()')
    .func(nil, 'void setActionTimeline(@addref(actionTimeline ^) cocostudio::timeline::ActionTimeline *action)')
    .func(nil, '@addref(actionTimeline ^) cocostudio::timeline::ActionTimeline *getActionTimeline()')
    .prop('root', nil, nil)
    .prop('actionTimeline', nil, nil)

typeconf 'cocostudio::timeline::BoneNode'
    .supercls('cocos2d::Node')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .func(nil, 'static cocostudio::timeline::BoneNode *create()', 'static cocostudio::timeline::BoneNode *create(int length)')
    .func(nil, '@addref(bones |) const cocos2d::Vector<BoneNode *> &getChildBones()')
    .func(nil, '@addref(rootSkeletonNode ^) cocostudio::timeline::SkeletonNode *getRootSkeletonNode()')
    .func(nil, '@addref(subBones |) cocos2d::Vector<BoneNode *> getAllSubBones()')
    .func(nil, 'void addSkin(@addref(skins |) cocostudio::timeline::SkinNode *skin, bool display)', 'void addSkin(@addref(skins |) cocostudio::timeline::SkinNode *skin, bool display, bool hideOthers)')
    .func(nil, 'void displaySkin(cocostudio::timeline::SkinNode *skin, bool hideOthers)', 'void displaySkin(const std::string &skinName, bool hideOthers)')
    .func(nil, '@addref(skins |) cocos2d::Vector<SkinNode *> getVisibleSkins()')
    .func(nil, '@addref(skins |) const cocos2d::Vector<SkinNode *> &getSkins()')
    .func(nil, '@addref(subSkins |) cocos2d::Vector<SkinNode *> getAllSubSkins()')
    .func(nil, 'void setBlendFunc(const cocos2d::BlendFunc &blendFunc)')
    .func(nil, 'const cocos2d::BlendFunc &getBlendFunc()')
    .func(nil, 'void setDebugDrawEnabled(bool isDebugDraw)')
    .func(nil, 'bool isDebugDrawEnabled()')
    .func(nil, 'void setDebugDrawLength(float length)')
    .func(nil, 'float getDebugDrawLength()')
    .func(nil, 'void setDebugDrawWidth(float width)')
    .func(nil, 'float getDebugDrawWidth()')
    .func(nil, 'void setDebugDrawColor(const cocos2d::Color4F &color)')
    .func(nil, 'cocos2d::Color4F getDebugDrawColor()')
    .func(nil, 'cocos2d::Rect getVisibleSkinsRect()')
    .func(nil, 'void setLocalZOrder(int localZOrder)')
    .func(nil, 'BoneNode()')
    .prop('childBones', nil, nil)
    .prop('rootSkeletonNode', nil, nil)
    .prop('allSubBones', nil, nil)
    .prop('visibleSkins', nil, nil)
    .prop('skins', nil, nil)
    .prop('allSubSkins', nil, nil)
    .prop('blendFunc', nil, nil)
    .prop('debugDrawEnabled', nil, nil)
    .prop('debugDrawLength', nil, nil)
    .prop('debugDrawWidth', nil, nil)
    .prop('debugDrawColor', nil, nil)
    .prop('visibleSkinsRect', nil, nil)

typeconf 'cocostudio::timeline::SkeletonNode'
    .supercls('cocostudio::timeline::BoneNode')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .func(nil, 'static cocostudio::timeline::SkeletonNode *create()')
    .func(nil, '@addref(boneNodes |) cocostudio::timeline::BoneNode *getBoneNode(const std::string &boneName)')
    .func(nil, '@addref(boneNodes |) const cocos2d::Map<std::string, BoneNode *> &getAllSubBonesMap()')
    .func(nil, 'void changeSkins(const std::map<std::string, std::string> &boneSkinNameMap)', 'void changeSkins(const std::string &skinGroupName)')
    .func(nil, 'void addSkinGroup(std::string groupName, std::map<std::string, std::string> boneSkinNameMap)')
    .func(nil, 'SkeletonNode()')
    .prop('allSubBonesMap', nil, nil)

typeconf 'cocostudio::timeline::Timeline'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .func(nil, 'static cocostudio::timeline::Timeline *create()')
    .func(nil, 'Timeline()')
    .func(nil, 'void gotoFrame(int frameIndex)')
    .func(nil, 'void stepToFrame(int frameIndex)')
    .func(nil, '@addref(frames |) const cocos2d::Vector<Frame *> &getFrames()')
    .func(nil, 'void addFrame(@addref(frames |) cocostudio::timeline::Frame *frame)')
    .func(nil, 'void insertFrame(@addref(frames |) cocostudio::timeline::Frame *frame, int index)')
    .func(nil, 'void removeFrame(@delref(frames |) cocostudio::timeline::Frame *frame)')
    .func(nil, 'void setActionTag(int tag)')
    .func(nil, 'int getActionTag()')
    .func(nil, 'void setNode(@addref(node ^) cocos2d::Node *node)')
    .func(nil, '@addref(node ^) cocos2d::Node *getNode()')
    .func(nil, 'void setActionTimeline(@addref(actionTimeline ^) cocostudio::timeline::ActionTimeline *action)')
    .func(nil, '@addref(actionTimeline ^) cocostudio::timeline::ActionTimeline *getActionTimeline()')
    .func(nil, 'cocostudio::timeline::Timeline *clone()')
    .prop('frames', nil, nil)
    .prop('actionTag', nil, nil)
    .prop('node', nil, nil)
    .prop('actionTimeline', nil, nil)

typeconf 'cocostudio::timeline::ActionTimeline'
    .supercls('cocos2d::Action')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .func(nil, 'static cocostudio::timeline::ActionTimeline *create()')
    .func(nil, 'ActionTimeline()')
    .func(nil, 'void play(std::string animationName, bool loop)')
    .func(nil, 'void gotoFrameAndPlay(int startIndex)', 'void gotoFrameAndPlay(int startIndex, bool loop)', 'void gotoFrameAndPlay(int startIndex, int endIndex, bool loop)', 'void gotoFrameAndPlay(int startIndex, int endIndex, int currentFrameIndex, bool loop)')
    .func(nil, 'void gotoFrameAndPause(int startIndex)')
    .func(nil, 'void pause()')
    .func(nil, 'void resume()')
    .func(nil, 'bool isPlaying()')
    .func(nil, 'void setTimeSpeed(float speed)')
    .func(nil, 'float getTimeSpeed()')
    .func(nil, 'void setDuration(int duration)')
    .func(nil, 'int getDuration()')
    .func(nil, 'int getStartFrame()')
    .func(nil, 'int getEndFrame()')
    .func(nil, 'void setCurrentFrame(int frameIndex)')
    .func(nil, 'int getCurrentFrame()')
    .func(nil, 'void addTimeline(@addref(timelines |) cocostudio::timeline::Timeline *timeline)')
    .func(nil, 'void removeTimeline(@delref(timelines |) cocostudio::timeline::Timeline *timeline)')
    .func(nil, '@addref(timelines |) const cocos2d::Vector<Timeline *> &getTimelines()')
    .func(nil, 'void addAnimationInfo(const cocostudio::timeline::AnimationInfo &animationInfo)')
    .func(nil, 'void removeAnimationInfo(std::string animationName)')
    .func(nil, 'bool IsAnimationInfoExists(const std::string &animationName)')
    .func(nil, 'const cocostudio::timeline::AnimationInfo &getAnimationInfo(const std::string &animationName)')
    .func(nil, 'void start()')
    .callback {
        funcs =  {
            'void setAnimationEndCallFunc(const std::string animationName, @localvar std::function<void ()> func)'
        },
        tag_maker = 'makeFrameEndCallbackTag(#0, #1)',
        tag_mode = 'replace',
        tag_store = 0,
        tag_scope = 'object',
    }
    .callback {
        funcs =  {
            'void setFrameEventCallFunc(@localvar @nullable std::function<void (cocostudio::timeline::Frame *)> listener)'
        },
        tag_maker = 'frameEventCallFunc',
        tag_mode = 'replace',
        tag_store = 0,
        tag_scope = 'object',
    }
    .callback {
        funcs =  {
            'void clearFrameEventCallFunc()'
        },
        tag_maker = 'frameEventCallFunc',
        tag_mode = 'substartwith',
        tag_store = 0,
        tag_scope = 'object',
    }
    .callback {
        funcs =  {
            'void setLastFrameCallFunc(@localvar @nullable std::function<void ()> listener)'
        },
        tag_maker = 'lastFrameCallFunc',
        tag_mode = 'replace',
        tag_store = 0,
        tag_scope = 'object',
    }
    .callback {
        funcs =  {
            'void clearLastFrameCallFunc()'
        },
        tag_maker = 'lastFrameCallFunc',
        tag_mode = 'substartwith',
        tag_store = 0,
        tag_scope = 'object',
    }
    .callback {
        funcs =  {
            'void addFrameEndCallFunc(int frameIndex, const std::string &funcKey, @localvar std::function<void ()> func)'
        },
        tag_maker = 'makeFrameEndCallbackTag(#1, #2)',
        tag_mode = 'replace',
        tag_store = 0,
        tag_scope = 'object',
    }
    .callback {
        funcs =  {
            'void removeFrameEndCallFunc(int frameIndex, const std::string &funcKey)'
        },
        tag_maker = 'makeFrameEndCallbackTag(#1, #2)',
        tag_mode = 'substartwith',
        tag_store = 0,
        tag_scope = 'object',
    }
    .callback {
        funcs =  {
            'void removeFrameEndCallFuncs(int frameIndex)'
        },
        tag_maker = 'makeFrameEndCallbackTag(#1, "")',
        tag_mode = 'substartwith',
        tag_store = 0,
        tag_scope = 'object',
    }
    .callback {
        funcs =  {
            'void clearFrameEndCallFuncs()'
        },
        tag_maker = 'makeFrameEndCallbackTag(-1, "")',
        tag_mode = 'substartwith',
        tag_store = 0,
        tag_scope = 'object',
    }
    .prop('playing', nil, nil)
    .prop('timeSpeed', nil, nil)
    .prop('duration', nil, nil)
    .prop('startFrame', nil, nil)
    .prop('endFrame', nil, nil)
    .prop('currentFrame', nil, nil)
    .prop('timelines', nil, nil)
    .insert('addAnimationInfo', {
        before = [[
            if (olua_getfield(L, 2, "clipEndCallBack") == LUA_TFUNCTION) {
                void *cb_store = (void *)self;
                std::string cb_tag = makeFrameEndCallbackTag(arg1.endIndex, arg1.name);
                std::string cb_name = olua_setcallback(L, cb_store, -1, cb_tag.c_str(), OLUA_TAG_REPLACE);
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
        after = nil,
        cbefore = nil,
        cafter = nil,
    })
    .insert('removeAnimationInfo', {
        before = [[
            auto info = self->getAnimationInfo(arg1);
            std::string cb_tag = makeFrameEndCallbackTag(info.endIndex, arg1);
            void *cb_store = (void *)self;
            olua_removecallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_SUBSTARTWITH);
        ]],
        after = nil,
        cbefore = nil,
        cafter = nil,
    })
    .insert('setFrameEventCallFunc', {
        before = nil,
        after = nil,
        cbefore = [[
            if (arg1->getTimeline() && arg1->getTimeline()->getActionTimeline()) {
                olua_push_cppobj<cocostudio::timeline::ActionTimeline>(L, arg1->getTimeline()->getActionTimeline());
                olua_push_cppobj<cocostudio::timeline::Timeline>(L, arg1->getTimeline());
                olua_push_cppobj<cocostudio::timeline::Frame>(L, arg1);
                olua_addref(L, -3, "timelines", -2, OLUA_FLAG_MULTIPLE);
                olua_addref(L, -2, "frames", -1, OLUA_FLAG_MULTIPLE);
                lua_pop(L, 3);
            }
        ]],
        cafter = nil,
    })
