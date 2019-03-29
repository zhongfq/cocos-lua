require "aux.olua-cls"
require "conf.cocos2d.import-cocos2d-type"
require "conf.fairygui.import-fairygui-type"

local M = {}

M.NAME = "fairygui"
M.HEADER_PATH = "template/frameworks/libxgame/src/xgame/lua-bindings/lua_fairygui.h"
M.SOURCE_PATH = "template/frameworks/libxgame/src/xgame/lua-bindings/lua_fairygui.cpp"

M.INCLUDES = [[
#include "xgame/lua-bindings/lua_xgame.h"
#include "xgame/lua-bindings/lua_conv.h"
#include "xgame/lua-bindings/lua_conv_manual.h"
#include "xgame/xlua.h"
#include "olua/olua.hpp"
#include "FairyGUI.h"
#include "tween/EaseManager.h"
]]

M.CLASSES = {
    include('conf/fairygui/fgui/event/fgui.UIEventType.lua'),
    include('conf/fairygui/fgui/event/fgui.UIEventDispatcher.lua'),
    include('conf/fairygui/fgui/event/fgui.EventContext.lua'),
    include('conf/fairygui/fgui/event/fgui.HitTest.lua'),
    include('conf/fairygui/fgui/event/fgui.InputProcessor.lua'),
    include('conf/fairygui/fgui/event/fgui.InputEvent.lua'),
    include('conf/fairygui/fgui/display/fgui.TextFormat.lua'),
    include('conf/fairygui/fgui/tween/fgui.EaseManager.lua'),
    include('conf/fairygui/fgui/fgui.UIPackage.lua'),
    include('conf/fairygui/fgui/fgui.PackageItem.lua'),
    include('conf/fairygui/fgui/fgui.FieldTypes.lua'),
    include('conf/fairygui/fgui/fgui.GController.lua'),
    include('conf/fairygui/fgui/fgui.GObject.lua'),
    include('conf/fairygui/fgui/fgui.GComponent.lua'),
    include('conf/fairygui/fgui/fgui.GRoot.lua'),
    include('conf/fairygui/fgui/fgui.GGroup.lua'),
    include('conf/fairygui/fgui/fgui.GScrollBar.lua'),
    include('conf/fairygui/fgui/fgui.GLoader.lua'),
    include('conf/fairygui/fgui/fgui.GTextField.lua'),
    include('conf/fairygui/fgui/fgui.GGraph.lua'),
    include('conf/fairygui/fgui/fgui.GButton.lua'),
    include('conf/fairygui/fgui/fgui.GImage.lua'),
    include('conf/fairygui/fgui/fgui.GLabel.lua'),
    include('conf/fairygui/fgui/fgui.GList.lua'),
    include('conf/fairygui/fgui/fgui.GMovieClip.lua'),
    include('conf/fairygui/fgui/fgui.GProgressBar.lua'),
    include('conf/fairygui/fgui/fgui.GComboBox.lua'),
    include('conf/fairygui/fgui/fgui.GRichTextField.lua'),
    include('conf/fairygui/fgui/fgui.GSlider.lua'),
    include('conf/fairygui/fgui/fgui.GTextInput.lua'),
    include('conf/fairygui/fgui/fgui.PopupMenu.lua'),
    include('conf/fairygui/fgui/fgui.Relations.lua'),
    include('conf/fairygui/fgui/fgui.RelationItem.lua'),
    include('conf/fairygui/fgui/fgui.ScrollPane.lua'),
    include('conf/fairygui/fgui/fgui.Transition.lua'),
    include('conf/fairygui/fgui/fgui.UIConfig.lua'),
    include('conf/fairygui/fgui/fgui.Window.lua'),
    include('conf/fairygui/fgui/fgui.DragDropManager.lua'),
    include('conf/fairygui/fgui/fgui.UIObjectFactory.lua'),
    include('conf/fairygui/fgui/gears/fgui.GearBase.lua'),
}

return M