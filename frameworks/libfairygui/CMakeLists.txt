cmake_minimum_required(VERSION 3.6)

if(POLICY CMP0022)
    cmake_policy(SET CMP0022 NEW)
endif()

project(fairygui)

# file list

set(FAIRYGUI_SRC   
    Classes/controller_action/ChangePageAction.cpp
    Classes/controller_action/ControllerAction.cpp
    Classes/controller_action/PlayTransitionAction.cpp
    Classes/Controller.cpp
    Classes/display/BitmapFont.cpp
    Classes/display/FUIContainer.cpp
    Classes/display/FUIInput.cpp
    Classes/display/FUILabel.cpp
    Classes/display/FUIRichText.cpp
    Classes/display/FUISprite.cpp
    Classes/display/TextFormat.cpp
    Classes/DragDropManager.cpp
    Classes/event/EventContext.cpp
    Classes/event/HitTest.cpp
    Classes/event/InputEvent.cpp
    Classes/event/InputProcessor.cpp
    Classes/event/UIEventDispatcher.cpp
    Classes/GButton.cpp
    Classes/GComboBox.cpp
    Classes/GComponent.cpp
    Classes/gears/GearAnimation.cpp
    Classes/gears/GearBase.cpp
    Classes/gears/GearColor.cpp
    Classes/gears/GearDisplay.cpp
    Classes/gears/GearDisplay2.cpp
    Classes/gears/GearFontSize.cpp
    Classes/gears/GearIcon.cpp
    Classes/gears/GearLook.cpp
    Classes/gears/GearSize.cpp
    Classes/gears/GearText.cpp
    Classes/gears/GearXY.cpp
    Classes/GGraph.cpp
    Classes/GGroup.cpp
    Classes/GImage.cpp
    Classes/GLabel.cpp
    Classes/GList.cpp
    Classes/GLoader.cpp
    Classes/GMovieClip.cpp
    Classes/GObject.cpp
    Classes/GObjectPool.cpp
    Classes/GProgressBar.cpp
    Classes/GRichTextField.cpp
    Classes/GRoot.cpp
    Classes/GScrollBar.cpp
    Classes/GSlider.cpp
    Classes/GTextField.cpp
    Classes/GTextInput.cpp
    Classes/GTree.cpp
    Classes/GTreeNode.cpp
    Classes/Margin.cpp
    Classes/PackageItem.cpp
    Classes/PopupMenu.cpp
    Classes/RelationItem.cpp
    Classes/Relations.cpp
    Classes/ScrollPane.cpp
    Classes/Transition.cpp
    Classes/TranslationHelper.cpp
    Classes/tween/EaseManager.cpp
    Classes/tween/GPath.cpp
    Classes/tween/GTween.cpp
    Classes/tween/GTweener.cpp
    Classes/tween/TweenManager.cpp
    Classes/tween/TweenPropType.cpp
    Classes/tween/TweenValue.cpp
    Classes/UIConfig.cpp
    Classes/UIObjectFactory.cpp
    Classes/UIPackage.cpp
    Classes/utils/ByteBuffer.cpp
    Classes/utils/ToolSet.cpp
    Classes/utils/UBBParser.cpp
    Classes/utils/WeakPtr.cpp
    Classes/Window.cpp
    )



set(FAIRYGUI_HEADER 
    Classes/controller_action/ChangePageAction.h
    Classes/controller_action/ControllerAction.h
    Classes/controller_action/PlayTransitionAction.h
    Classes/Controller.h
    Classes/display/BitmapFont.h
    Classes/display/FUIContainer.h
    Classes/display/FUIInput.h
    Classes/display/FUILabel.h
    Classes/display/FUIRichText.h
    Classes/display/FUISprite.h
    Classes/display/TextFormat.h
    Classes/DragDropManager.h
    Classes/event/EventContext.h
    Classes/event/HitTest.h
    Classes/event/InputEvent.h
    Classes/event/InputProcessor.h
    Classes/event/UIEventDispatcher.h
    Classes/event/UIEventType.h
    Classes/FairyGUI.h
    Classes/FairyGUIMacros.h
    Classes/FieldTypes.h
    Classes/GButton.h
    Classes/GComboBox.h
    Classes/GComponent.h
    Classes/gears/GearAnimation.h
    Classes/gears/GearBase.h
    Classes/gears/GearColor.h
    Classes/gears/GearDisplay.h
    Classes/gears/GearDisplay2.h
    Classes/gears/GearFontSize.h
    Classes/gears/GearIcon.h
    Classes/gears/GearLook.h
    Classes/gears/GearSize.h
    Classes/gears/GearText.h
    Classes/gears/GearXY.h
    Classes/GGraph.h
    Classes/GGroup.h
    Classes/GImage.h
    Classes/GLabel.h
    Classes/GList.h
    Classes/GLoader.h
    Classes/GMovieClip.h
    Classes/GObject.h
    Classes/GObjectPool.h
    Classes/GProgressBar.h
    Classes/GRichTextField.h
    Classes/GRoot.h
    Classes/GScrollBar.h
    Classes/GSlider.h
    Classes/GTextField.h
    Classes/GTextInput.h
    Classes/GTree.h
    Classes/GTreeNode.h
    Classes/Margin.h
    Classes/PackageItem.h
    Classes/PopupMenu.h
    Classes/RelationItem.h
    Classes/Relations.h
    Classes/ScrollPane.h 
    Classes/Transition.h
    Classes/TranslationHelper.h
    Classes/tween/EaseManager.h
    Classes/tween/EaseType.h
    Classes/tween/GPath.h
    Classes/tween/GTween.h
    Classes/tween/GTweener.h
    Classes/tween/TweenManager.h
    Classes/tween/TweenPropType.h
    Classes/tween/TweenValue.h
    Classes/UIConfig.h
    Classes/UIObjectFactory.h
    Classes/UIPackage.h
    Classes/utils/ByteBuffer.h
    Classes/utils/ToolSet.h
    Classes/utils/UBBParser.h
    Classes/utils/WeakPtr.h
    Classes/Window.h
    )

list(APPEND FAIRYGUI_SRC ${FAIRYGUI_HEADER})

include_directories(
    ${COCOS2DX_ROOT_PATH}/cocos/audio/include/
)

add_library(fairygui ${FAIRYGUI_SRC})

target_link_libraries(
    fairygui
    PRIVATE
    cocos2d
)

target_include_directories(fairygui
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Classes>
)

set_target_properties(fairygui PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    FOLDER "Internal"
)

if(XCODE OR VS)
    cocos_mark_code_files("fairygui" GROUPBASE "${CMAKE_CURRENT_SOURCE_DIR}/Classes")
endif()