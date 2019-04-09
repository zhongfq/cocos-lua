require "aux.olua-cls"
require "conf.cocos2d.import-cocos2d-type"
require "conf.fairygui.import-fairygui-type"

local M = {}

M.NAME = "fairygui"
M.HEADER_PATH = "frameworks/libxgame/src/xgame/lua-bindings/lua_fairygui.h"
M.SOURCE_PATH = "frameworks/libxgame/src/xgame/lua-bindings/lua_fairygui.cpp"

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
    include('conf/fairygui/fui/event/fui.UIEventType.lua'),
    include('conf/fairygui/fui/event/fui.UIEventDispatcher.lua'),
    include('conf/fairygui/fui/event/fui.EventContext.lua'),
    include('conf/fairygui/fui/event/fui.HitTest.lua'),
    include('conf/fairygui/fui/event/fui.InputProcessor.lua'),
    include('conf/fairygui/fui/event/fui.InputEvent.lua'),
    include('conf/fairygui/fui/display/fui.TextFormat.lua'),
    include('conf/fairygui/fui/tween/fui.EaseManager.lua'),
    include('conf/fairygui/fui/tween/fui.GTweener.lua'),
    include('conf/fairygui/fui/tween/fui.GTween.lua'),
    include('conf/fairygui/fui/fui.UIPackage.lua'),
    include('conf/fairygui/fui/fui.PackageItem.lua'),
    include('conf/fairygui/fui/fui.FieldTypes.lua'),
    include('conf/fairygui/fui/fui.GController.lua'),
    include('conf/fairygui/fui/fui.GObject.lua'),
    include('conf/fairygui/fui/fui.GComponent.lua'),
    include('conf/fairygui/fui/fui.GRoot.lua'),
    include('conf/fairygui/fui/fui.GGroup.lua'),
    include('conf/fairygui/fui/fui.GScrollBar.lua'),
    include('conf/fairygui/fui/fui.GLoader.lua'),
    include('conf/fairygui/fui/fui.GTextField.lua'),
    include('conf/fairygui/fui/fui.GGraph.lua'),
    include('conf/fairygui/fui/fui.GButton.lua'),
    include('conf/fairygui/fui/fui.GImage.lua'),
    include('conf/fairygui/fui/fui.GLabel.lua'),
    include('conf/fairygui/fui/fui.GList.lua'),
    include('conf/fairygui/fui/fui.GMovieClip.lua'),
    include('conf/fairygui/fui/fui.GProgressBar.lua'),
    include('conf/fairygui/fui/fui.GComboBox.lua'),
    include('conf/fairygui/fui/fui.GRichTextField.lua'),
    include('conf/fairygui/fui/fui.GSlider.lua'),
    include('conf/fairygui/fui/fui.GTextInput.lua'),
    include('conf/fairygui/fui/fui.PopupMenu.lua'),
    include('conf/fairygui/fui/fui.Relations.lua'),
    include('conf/fairygui/fui/fui.RelationItem.lua'),
    include('conf/fairygui/fui/fui.ScrollPane.lua'),
    include('conf/fairygui/fui/fui.Transition.lua'),
    include('conf/fairygui/fui/fui.UIConfig.lua'),
    include('conf/fairygui/fui/fui.Window.lua'),
    include('conf/fairygui/fui/fui.DragDropManager.lua'),
    include('conf/fairygui/fui/fui.UIObjectFactory.lua'),
    include('conf/fairygui/fui/gears/fui.GearBase.lua'),
    include('conf/fairygui/fui/treeview/fui.TreeNode.lua'),
    include('conf/fairygui/fui/treeview/fui.TreeView.lua'),
}

return M