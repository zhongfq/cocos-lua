cmake_minimum_required(VERSION 3.6)

set(DRAGONBONES_ROOT ${CMAKE_CURRENT_SOURCE_DIR})

set(HEADER
    src/animation/Animation.h
    src/animation/AnimationState.h
    src/animation/BaseTimelineState.h
    src/animation/IAnimatable.h
    src/animation/TimelineState.h
    src/animation/WorldClock.h
    src/armature/Armature.h
    src/armature/Bone.h
    src/armature/Constraint.h
    src/armature/DeformVertices.h
    src/armature/IArmatureProxy.h
    src/armature/Slot.h
    src/armature/TransformObject.h
    src/CCArmatureDisplay.h
    src/CCDragonBonesHeaders.h
    src/CCFactory.h
    src/CCSlot.h
    src/CCTextureAtlasData.h
    src/core/BaseObject.h
    src/core/DragonBones.h
    src/DragonBonesHeaders.h
    src/event/EventObject.h
    src/event/IEventDispatcher.h
    src/factory/BaseFactory.h
    src/geom/ColorTransform.h
    src/geom/Matrix.h
    src/geom/Point.h
    src/geom/Rectangle.h
    src/geom/Transform.h
    src/model/AnimationConfig.h
    src/model/AnimationData.h
    src/model/ArmatureData.h
    src/model/BoundingBoxData.h
    src/model/CanvasData.h
    src/model/ConstraintData.h
    src/model/DisplayData.h
    src/model/DragonBonesData.h
    src/model/SkinData.h
    src/model/TextureAtlasData.h
    src/model/UserData.h
    src/parser/BinaryDataParser.h
    src/parser/DataParser.h
    src/parser/JSONDataParser.h
)
set(SRC
    src/animation/Animation.cpp
    src/animation/AnimationState.cpp
    src/animation/BaseTimelineState.cpp
    src/animation/TimelineState.cpp
    src/animation/WorldClock.cpp
    src/armature/Armature.cpp
    src/armature/Bone.cpp
    src/armature/Constraint.cpp
    src/armature/DeformVertices.cpp
    src/armature/Slot.cpp
    src/armature/TransformObject.cpp
    src/CCArmatureDisplay.cpp
    src/CCFactory.cpp
    src/CCSlot.cpp
    src/CCTextureAtlasData.cpp
    src/core/BaseObject.cpp
    src/core/DragonBones.cpp
    src/event/EventObject.cpp
    src/factory/BaseFactory.cpp
    src/geom/Point.cpp
    src/geom/Transform.cpp
    src/model/AnimationConfig.cpp
    src/model/AnimationData.cpp
    src/model/ArmatureData.cpp
    src/model/BoundingBoxData.cpp
    src/model/CanvasData.cpp
    src/model/ConstraintData.cpp
    src/model/DisplayData.cpp
    src/model/DragonBonesData.cpp
    src/model/SkinData.cpp
    src/model/TextureAtlasData.cpp
    src/model/UserData.cpp
    src/parser/BinaryDataParser.cpp
    src/parser/DataParser.cpp
    src/parser/JSONDataParser.cpp
)

list(APPEND SRC ${HEADER})

add_library(dragonbones ${SRC})

target_link_libraries(dragonbones 
	PRIVATE cocos2d
)

add_dependencies(dragonbones cocos2d)

target_include_directories(dragonbones
	PUBLIC ${DRAGONBONES_ROOT}/src
)
