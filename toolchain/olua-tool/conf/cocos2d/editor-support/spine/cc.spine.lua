local M = {}

local cls = class(M)
cls.CPPCLS = 'spEventType'
cls.LUACLS = 'sp.EventType'
cls.enums [[
    ANIMATION_START
    ANIMATION_INTERRUPT
    ANIMATION_END
    ANIMATION_COMPLETE
    ANIMATION_DISPOSE
    ANIMATION_EVENT
]]

local cls = class(M)
cls.CPPCLS = 'spAttachmentType'
cls.LUACLS = 'sp.AttachmentType'
cls.enums [[
    ATTACHMENT_REGION,
    ATTACHMENT_BOUNDING_BOX,
    ATTACHMENT_MESH,
    ATTACHMENT_LINKED_MESH,
    ATTACHMENT_PATH,
    ATTACHMENT_POINT,
    ATTACHMENT_CLIPPING
]]

local cls = class(M)
cls.CPPCLS = 'spTrackEntry'
cls.LUACLS = 'sp.TrackEntry'
cls.vars [[
    @readonly spAnimation* animation;
    @readonly spTrackEntry* next;
    @readonly spTrackEntry* mixingFrom;
    @readonly int trackIndex;
    @readonly int loop;
    @readonly float eventThreshold;
    @readonly float attachmentThreshold;
    @readonly float drawOrderThreshold;
    @readonly float animationStart;
    @readonly float animationEnd;
    @readonly float animationLast;
    @readonly float nextAnimationLast;
    @readonly float delay;
    @readonly float trackTime;
    @readonly float trackLast;
    @readonly float nextTrackLast;
    @readonly float trackEnd;
    @readonly float timeScale;
    @readonly float alpha;
    @readonly float mixTime;
    @readonly float mixDuration;
    @readonly float interruptAlpha;
    @readonly float totalAlpha;
]]

local cls = class(M)
cls.CPPCLS = 'spSkeletonData'
cls.LUACLS = 'sp.SkeletonData'

local cls = class(M)
cls.CPPCLS = 'spAnimation'
cls.LUACLS = 'sp.Animation'
cls.vars [[
    @readonly const char* name;
    @readonly float duration;
]]

local cls = class(M)
cls.CPPCLS = 'spAtlas'
cls.LUACLS = 'sp.Atlas'

local cls = class(M)
cls.CPPCLS = 'spEvent'
cls.LUACLS = 'sp.Event'
cls.vars [[
    @readonly spEventData* data;
    @readonly float const time;
    @readonly int intValue;
    @readonly float floatValue;
    @readonly const char* stringValue;
]]

local cls = class(M)
cls.CPPCLS = 'spEventData'
cls.LUACLS = 'sp.EventData'
cls.vars [[
    @readonly const char* name;
    @readonly int intValue;
    @readonly float floatValue;
    @readonly const char* stringValue;
]]

local cls = class(M)
cls.CPPCLS = 'spAnimationState'
cls.LUACLS = 'sp.AnimationState'

local cls = class(M)
cls.CPPCLS = 'spSkeleton'
cls.LUACLS = 'sp.Skeleton'

local cls = class(M)
cls.CPPCLS = 'spBone'
cls.LUACLS = 'sp.Bone'

local cls = class(M)
cls.CPPCLS = 'spSlot'
cls.LUACLS = 'sp.Slot'

local cls = class(M)
cls.CPPCLS = 'spAttachment'
cls.LUACLS = 'sp.Attachment'
cls.vars [[
    @readonly const char* name;
    @readonly const spAttachmentType type;
]]

local cls = class(M)
cls.CPPCLS = 'spVertexEffect'
cls.LUACLS = 'sp.VertexEffect'

local cls = class(M)
cls.CPPCLS = 'spAnimationStateData'
cls.LUACLS = 'sp.AnimationStateData'

return M