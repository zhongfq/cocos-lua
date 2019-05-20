local M = {}

local cls = class(M)
cls.CPPCLS = 'BaseObject'
cls.LUACLS = 'db.BaseObject'

local cls = class(M)
cls.CPPCLS = 'BaseFactory'
cls.LUACLS = 'db.BaseFactory'
cls.funcs [[
	void replaceDisplay(Slot* slot, DisplayData* displayData, int displayIndex)
    bool replaceSkin(Armature* armature, SkinData* skin, bool isOverride = false, const std::vector<std::string>* exclude = nullptr)
    bool replaceAnimation(Armature* armature, ArmatureData* armatureData, bool isReplaceAll = true)
    bool replaceSlotDisplay(const std::string& dragonBonesName, const std::string& armatureName, const std::string& slotName, const std::string& displayName, Slot* slot, int displayIndex = -1)
]]

local cls = class(M)
cls.CPPCLS = 'TransformObject'
cls.LUACLS = 'db.TransformObject'
cls.SUPERCLS = "db.BaseObject"

local cls = class(M)
cls.CPPCLS = 'Slot'
cls.LUACLS = 'db.Slot'
cls.SUPERCLS = "db.TransformObject"

local cls = class(M)
cls.CPPCLS = 'Bone'
cls.LUACLS = 'db.Bone'
cls.SUPERCLS = "db.TransformObject"

local cls = class(M)
cls.CPPCLS = "DragonBonesData"
cls.LUACLS = "db.DragonBonesData"
cls.SUPERCLS = "db.BaseObject"
cls.funcs [[
    void addArmature(ArmatureData* value)
   	ArmatureData* getArmature(const std::string& armatureName)
]]

local cls = class(M)
cls.CPPCLS = "DisplayData"
cls.LUACLS = "db.DisplayData"
cls.SUPERCLS = "db.BaseObject"

local cls = class(M)
cls.CPPCLS = "TextureAtlasData"
cls.LUACLS = "db.TextureAtlasData"
cls.SUPERCLS = "db.BaseObject"

local cls = class(M)
cls.CPPCLS = "TextureData"
cls.LUACLS = "db.TextureData"
cls.SUPERCLS = "db.BaseObject"

local cls = class(M)
cls.CPPCLS = "ArmatureData"
cls.LUACLS = "db.ArmatureData"
cls.SUPERCLS = "db.BaseObject"

local cls = class(M)
cls.CPPCLS = "BoneData"
cls.LUACLS = "db.BoneData"
cls.SUPERCLS = "db.BaseObject"

local cls = class(M)
cls.CPPCLS = "SlotData"
cls.LUACLS = "db.SlotData"
cls.SUPERCLS = "db.BaseObject"

local cls = class(M)
cls.CPPCLS = "AnimationState"
cls.LUACLS = "db.AnimationState"
cls.SUPERCLS = "db.BaseObject"

local cls = class(M)
cls.CPPCLS = "AnimationData"
cls.LUACLS = "db.AnimationData"
cls.SUPERCLS = "db.BaseObject"

local cls = class(M)
cls.CPPCLS = "AnimationConfig"
cls.LUACLS = "db.AnimationConfig"
cls.SUPERCLS = "db.BaseObject"

local cls = class(M)
cls.CPPCLS = "Armature"
cls.LUACLS = "db.Armature"
cls.SUPERCLS = "db.BaseObject"
cls.funcs [[
    Bone* getBone(const std::string& name)
    Bone* getBoneByDisplay(void* display)
    Slot* getSlot(const std::string& name)
    Slot* getSlotByDisplay(void* display)
    const std::vector<Bone*>& getBones()
    const std::vector<Slot*>& getSlots()
    bool getFlipX()
    void setFlipX(bool value)
    bool getFlipY()
    void setFlipY(bool value)
    const std::string& getName()
    const ArmatureData* getArmatureData()
    Animation* getAnimation()
    void* getDisplay()
    void* getReplacedTexture()
    void setReplacedTexture(void* value)
    Slot* getParent()
]]

local cls = class(M)
cls.CPPCLS = "Animation"
cls.LUACLS = "db.Animation"
cls.SUPERCLS = "db.BaseObject"
cls.funcs [[
    void reset()
    void stop(const std::string& animationName)
    AnimationState* playConfig(AnimationConfig* animationConfig)
    AnimationState* play(const std::string& animationName = "", int playTimes = -1)
    AnimationState* gotoAndPlayByTime(const std::string& animationName, float time = 0.f, int playTimes = -1)
    AnimationState* gotoAndPlayByFrame(const std::string& animationName, unsigned frame = 0, int playTimes = -1)
    AnimationState* gotoAndPlayByProgress(const std::string& animationName, float progress = 0.f, int playTimes = -1)
    AnimationState* gotoAndStopByTime(const std::string& animationName, float time = 0.f)
    AnimationState* gotoAndStopByFrame(const std::string& animationName, unsigned frame = 0)
    AnimationState* gotoAndStopByProgress(const std::string& animationName, float progress = 0.f)
    AnimationState* getState(const std::string& animationName)
    bool hasAnimation(const std::string& animationName)
    const std::vector<AnimationState*>& getStates()
    bool isPlaying()
    bool isCompleted()
    const std::string& getLastAnimationName()
    const std::vector<std::string>& getAnimationNames()
    const std::map<std::string, AnimationData*>& getAnimations()
    void setAnimations(const std::map<std::string, AnimationData*>& value)
    AnimationConfig* getAnimationConfig()
    AnimationState* getLastAnimationState()
]]

return M