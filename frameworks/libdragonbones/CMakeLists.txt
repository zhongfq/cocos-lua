cmake_minimum_required(VERSION 3.6)

set(DRAGONBONES_ROOT ${CMAKE_CURRENT_SOURCE_DIR})

set(HEADER
    src/CCArmatureDisplay.h
    src/CCDragonBonesHeaders.h
    src/CCFactory.h
    src/CCSlot.h
    src/CCTextureAtlasData.h
    src/dragonBones/animation/Animation.h
    src/dragonBones/animation/AnimationState.h
    src/dragonBones/animation/BaseTimelineState.h
    src/dragonBones/animation/IAnimatable.h
    src/dragonBones/animation/TimelineState.h
    src/dragonBones/animation/WorldClock.h
    src/dragonBones/armature/Armature.h
    src/dragonBones/armature/Bone.h
    src/dragonBones/armature/Constraint.h
    src/dragonBones/armature/DeformVertices.h
    src/dragonBones/armature/IArmatureProxy.h
    src/dragonBones/armature/Slot.h
    src/dragonBones/armature/TransformObject.h
    src/dragonBones/core/BaseObject.h
    src/dragonBones/core/DragonBones.h
    src/dragonBones/DragonBonesHeaders.h
    src/dragonBones/event/EventObject.h
    src/dragonBones/event/IEventDispatcher.h
    src/dragonBones/factory/BaseFactory.h
    src/dragonBones/geom/ColorTransform.h
    src/dragonBones/geom/Matrix.h
    src/dragonBones/geom/Point.h
    src/dragonBones/geom/Rectangle.h
    src/dragonBones/geom/Transform.h
    src/dragonBones/model/AnimationConfig.h
    src/dragonBones/model/AnimationData.h
    src/dragonBones/model/ArmatureData.h
    src/dragonBones/model/BoundingBoxData.h
    src/dragonBones/model/CanvasData.h
    src/dragonBones/model/ConstraintData.h
    src/dragonBones/model/DisplayData.h
    src/dragonBones/model/DragonBonesData.h
    src/dragonBones/model/SkinData.h
    src/dragonBones/model/TextureAtlasData.h
    src/dragonBones/model/UserData.h
    src/dragonBones/parser/BinaryDataParser.h
    src/dragonBones/parser/DataParser.h
    src/dragonBones/parser/JSONDataParser.h
    src/rapidjson/allocators.h
    src/rapidjson/document.h
    src/rapidjson/encodedstream.h
    src/rapidjson/encodings.h
    src/rapidjson/error/en.h
    src/rapidjson/error/error.h
    src/rapidjson/filereadstream.h
    src/rapidjson/filewritestream.h
    src/rapidjson/fwd.h
    src/rapidjson/internal/biginteger.h
    src/rapidjson/internal/diyfp.h
    src/rapidjson/internal/dtoa.h
    src/rapidjson/internal/ieee754.h
    src/rapidjson/internal/itoa.h
    src/rapidjson/internal/meta.h
    src/rapidjson/internal/pow10.h
    src/rapidjson/internal/regex.h
    src/rapidjson/internal/stack.h
    src/rapidjson/internal/strfunc.h
    src/rapidjson/internal/strtod.h
    src/rapidjson/internal/swap.h
    src/rapidjson/istreamwrapper.h
    src/rapidjson/memorybuffer.h
    src/rapidjson/memorystream.h
    src/rapidjson/msinttypes/inttypes.h
    src/rapidjson/msinttypes/stdint.h
    src/rapidjson/ostreamwrapper.h
    src/rapidjson/pointer.h
    src/rapidjson/prettywriter.h
    src/rapidjson/rapidjson.h
    src/rapidjson/reader.h
    src/rapidjson/schema.h
    src/rapidjson/stream.h
    src/rapidjson/stringbuffer.h
    src/rapidjson/writer.h
)
set(SRC
    src/CCArmatureDisplay.cpp
    src/CCFactory.cpp
    src/CCSlot.cpp
    src/CCTextureAtlasData.cpp
    src/dragonBones/animation/Animation.cpp
    src/dragonBones/animation/AnimationState.cpp
    src/dragonBones/animation/BaseTimelineState.cpp
    src/dragonBones/animation/TimelineState.cpp
    src/dragonBones/animation/WorldClock.cpp
    src/dragonBones/armature/Armature.cpp
    src/dragonBones/armature/Bone.cpp
    src/dragonBones/armature/Constraint.cpp
    src/dragonBones/armature/DeformVertices.cpp
    src/dragonBones/armature/Slot.cpp
    src/dragonBones/armature/TransformObject.cpp
    src/dragonBones/core/BaseObject.cpp
    src/dragonBones/core/DragonBones.cpp
    src/dragonBones/event/EventObject.cpp
    src/dragonBones/factory/BaseFactory.cpp
    src/dragonBones/geom/Point.cpp
    src/dragonBones/geom/Transform.cpp
    src/dragonBones/model/AnimationConfig.cpp
    src/dragonBones/model/AnimationData.cpp
    src/dragonBones/model/ArmatureData.cpp
    src/dragonBones/model/BoundingBoxData.cpp
    src/dragonBones/model/CanvasData.cpp
    src/dragonBones/model/ConstraintData.cpp
    src/dragonBones/model/DisplayData.cpp
    src/dragonBones/model/DragonBonesData.cpp
    src/dragonBones/model/SkinData.cpp
    src/dragonBones/model/TextureAtlasData.cpp
    src/dragonBones/model/UserData.cpp
    src/dragonBones/parser/BinaryDataParser.cpp
    src/dragonBones/parser/DataParser.cpp
    src/dragonBones/parser/JSONDataParser.cpp
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

set_target_properties(dragonbones PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    FOLDER "Internal"
)

if(XCODE OR VS)
    cocos_mark_code_files("dragonbones" GROUPBASE "${CMAKE_CURRENT_SOURCE_DIR}/src")
endif()