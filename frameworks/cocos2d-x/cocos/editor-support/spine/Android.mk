


LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE := spine

LOCAL_MODULE_FILENAME := libspine

LOCAL_ARM_MODE := arm

LOCAL_SRC_FILES := \
Animation.cpp \
AnimationState.cpp \
AnimationStateData.cpp \
Atlas.cpp \
AtlasAttachmentLoader.cpp \
Attachment.cpp \
AttachmentLoader.cpp \
AttachmentTimeline.cpp \
AttachmentVertices.cpp \
Bone.cpp \
BoneData.cpp \
BoundingBoxAttachment.cpp \
ClippingAttachment.cpp \
ColorTimeline.cpp \
Constraint.cpp \
CurveTimeline.cpp \
DeformTimeline.cpp \
DrawOrderTimeline.cpp \
Event.cpp \
EventData.cpp \
EventTimeline.cpp \
Extension.cpp \
IkConstraint.cpp \
IkConstraintData.cpp \
IkConstraintTimeline.cpp \
Json.cpp \
LinkedMesh.cpp \
MathUtil.cpp \
MeshAttachment.cpp \
PathAttachment.cpp \
PathConstraint.cpp \
PathConstraintData.cpp \
PathConstraintMixTimeline.cpp \
PathConstraintPositionTimeline.cpp \
PathConstraintSpacingTimeline.cpp \
PointAttachment.cpp \
RegionAttachment.cpp \
RotateTimeline.cpp \
RTTI.cpp \
ScaleTimeline.cpp \
ShearTimeline.cpp \
Skeleton.cpp \
SkeletonAnimation.cpp \
SkeletonBatch.cpp \
SkeletonBinary.cpp \
SkeletonBounds.cpp \
SkeletonClipping.cpp \
SkeletonData.cpp \
SkeletonJson.cpp \
SkeletonRenderer.cpp \
SkeletonTwoColorBatch.cpp \
Skin.cpp \
Slot.cpp \
SlotData.cpp \
spine-cocos2dx.cpp \
SpineObject.cpp \
TextureLoader.cpp \
Timeline.cpp \
TransformConstraint.cpp \
TransformConstraintData.cpp \
TransformConstraintTimeline.cpp \
TranslateTimeline.cpp \
Triangulator.cpp \
TwoColorTimeline.cpp \
Updatable.cpp \
VertexAttachment.cpp \
VertexEffect.cpp

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/..

LOCAL_C_INCLUDES := $(LOCAL_PATH)/..

LOCAL_STATIC_LIBRARIES := cc_core

include $(BUILD_STATIC_LIBRARY)
