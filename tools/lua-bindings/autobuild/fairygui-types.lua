local olua = require "olua"
local typedef = olua.typedef

olua.nowarning(typedef)

typedef {
    CONV_FUNC = 'manual_olua_$$_fairygui_EventTag',
    CPPCLS = 'fairygui::EventTag',
    INIT_VALUE = false,
}

typedef {
    CONV_FUNC = 'auto_olua_$$_fairygui_Margin',
    CPPCLS = 'fairygui::Margin',
    INIT_VALUE = false,
}

typedef {
    CONV_FUNC = 'auto_olua_$$_fairygui_TweenValue',
    CPPCLS = 'fairygui::TweenValue',
    INIT_VALUE = false,
}

typedef {
    CPPCLS = 'fairygui::AutoSizeType',
    DECL_TYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    VALUE_TYPE = true,
    LUACLS = 'fui.AutoSizeType',
}

typedef {
    CPPCLS = 'fairygui::ButtonMode',
    DECL_TYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    VALUE_TYPE = true,
    LUACLS = 'fui.ButtonMode',
}

typedef {
    CPPCLS = 'fairygui::ChildrenRenderOrder',
    DECL_TYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    VALUE_TYPE = true,
    LUACLS = 'fui.ChildrenRenderOrder',
}

typedef {
    CPPCLS = 'fairygui::EaseType',
    DECL_TYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    VALUE_TYPE = true,
    LUACLS = 'fui.EaseType',
}

typedef {
    CPPCLS = 'fairygui::FillMethod',
    DECL_TYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    VALUE_TYPE = true,
    LUACLS = 'fui.FillMethod',
}

typedef {
    CPPCLS = 'fairygui::FillOrigin',
    DECL_TYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    VALUE_TYPE = true,
    LUACLS = 'fui.FillOrigin',
}

typedef {
    CPPCLS = 'fairygui::FlipType',
    DECL_TYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    VALUE_TYPE = true,
    LUACLS = 'fui.FlipType',
}

typedef {
    CPPCLS = 'fairygui::GroupLayoutType',
    DECL_TYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    VALUE_TYPE = true,
    LUACLS = 'fui.GroupLayoutType',
}

typedef {
    CPPCLS = 'fairygui::ListLayoutType',
    DECL_TYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    VALUE_TYPE = true,
    LUACLS = 'fui.ListLayoutType',
}

typedef {
    CPPCLS = 'fairygui::ListSelectionMode',
    DECL_TYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    VALUE_TYPE = true,
    LUACLS = 'fui.ListSelectionMode',
}

typedef {
    CPPCLS = 'fairygui::LoaderFillType',
    DECL_TYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    VALUE_TYPE = true,
    LUACLS = 'fui.LoaderFillType',
}

typedef {
    CPPCLS = 'fairygui::ObjectType',
    DECL_TYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    VALUE_TYPE = true,
    LUACLS = 'fui.ObjectType',
}

typedef {
    CPPCLS = 'fairygui::OverflowType',
    DECL_TYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    VALUE_TYPE = true,
    LUACLS = 'fui.OverflowType',
}

typedef {
    CPPCLS = 'fairygui::PackageItemType',
    DECL_TYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    VALUE_TYPE = true,
    LUACLS = 'fui.PackageItemType',
}

typedef {
    CPPCLS = 'fairygui::PopupDirection',
    DECL_TYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    VALUE_TYPE = true,
    LUACLS = 'fui.PopupDirection',
}

typedef {
    CPPCLS = 'fairygui::ProgressTitleType',
    DECL_TYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    VALUE_TYPE = true,
    LUACLS = 'fui.ProgressTitleType',
}

typedef {
    CPPCLS = 'fairygui::RelationType',
    DECL_TYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    VALUE_TYPE = true,
    LUACLS = 'fui.RelationType',
}

typedef {
    CPPCLS = 'fairygui::ScrollBarDisplayType',
    DECL_TYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    VALUE_TYPE = true,
    LUACLS = 'fui.ScrollBarDisplayType',
}

typedef {
    CPPCLS = 'fairygui::ScrollType',
    DECL_TYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    VALUE_TYPE = true,
    LUACLS = 'fui.ScrollType',
}

typedef {
    CPPCLS = 'fairygui::TransitionActionType',
    DECL_TYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    VALUE_TYPE = true,
    LUACLS = 'fui.TransitionActionType',
}

typedef {
    CPPCLS = 'fairygui::TweenPropType',
    DECL_TYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    VALUE_TYPE = true,
    LUACLS = 'fui.TweenPropType',
}

typedef {
    CPPCLS = 'fairygui::DragDropManager *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'fui.DragDropManager',
}

typedef {
    CPPCLS = 'fairygui::EaseManager *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'fui.EaseManager',
}

typedef {
    CPPCLS = 'fairygui::EventContext *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'fui.EventContext',
}

typedef {
    CPPCLS = 'fairygui::GButton *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'fui.GButton',
}

typedef {
    CPPCLS = 'fairygui::GComboBox *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'fui.GComboBox',
}

typedef {
    CPPCLS = 'fairygui::GComponent *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'fui.GComponent',
}

typedef {
    CPPCLS = 'fairygui::GController *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'fui.GController',
}

typedef {
    CPPCLS = 'fairygui::GGraph *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'fui.GGraph',
}

typedef {
    CPPCLS = 'fairygui::GGroup *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'fui.GGroup',
}

typedef {
    CPPCLS = 'fairygui::GImage *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'fui.GImage',
}

typedef {
    CPPCLS = 'fairygui::GLabel *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'fui.GLabel',
}

typedef {
    CPPCLS = 'fairygui::GList *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'fui.GList',
}

typedef {
    CPPCLS = 'fairygui::GLoader *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'fui.GLoader',
}

typedef {
    CPPCLS = 'fairygui::GMovieClip *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'fui.GMovieClip',
}

typedef {
    CPPCLS = 'fairygui::GObject *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'fui.GObject',
}

typedef {
    CPPCLS = 'fairygui::GProgressBar *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'fui.GProgressBar',
}

typedef {
    CPPCLS = 'fairygui::GRichTextField *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'fui.GRichTextField',
}

typedef {
    CPPCLS = 'fairygui::GRoot *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'fui.GRoot',
}

typedef {
    CPPCLS = 'fairygui::GScrollBar *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'fui.GScrollBar',
}

typedef {
    CPPCLS = 'fairygui::GSlider *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'fui.GSlider',
}

typedef {
    CPPCLS = 'fairygui::GTextField *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'fui.GTextField',
}

typedef {
    CPPCLS = 'fairygui::GTextInput *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'fui.GTextInput',
}

typedef {
    CPPCLS = 'fairygui::GTween *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'fui.GTween',
}

typedef {
    CPPCLS = 'fairygui::GTweener *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'fui.GTweener',
}

typedef {
    CPPCLS = 'fairygui::GearBase *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'fui.GearBase',
}

typedef {
    CPPCLS = 'fairygui::IHitTest *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'fui.IHitTest',
}

typedef {
    CPPCLS = 'fairygui::IUISource *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'fui.IUISource',
}

typedef {
    CPPCLS = 'fairygui::InputEvent *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'fui.InputEvent',
}

typedef {
    CPPCLS = 'fairygui::InputProcessor *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'fui.InputProcessor',
}

typedef {
    CPPCLS = 'fairygui::PackageItem *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'fui.PackageItem',
}

typedef {
    CPPCLS = 'fairygui::PopupMenu *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'fui.PopupMenu',
}

typedef {
    CPPCLS = 'fairygui::RelationItem *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'fui.RelationItem',
}

typedef {
    CPPCLS = 'fairygui::Relations *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'fui.Relations',
}

typedef {
    CPPCLS = 'fairygui::ScrollPane *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'fui.ScrollPane',
}

typedef {
    CPPCLS = 'fairygui::TextFormat *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'fui.TextFormat',
}

typedef {
    CPPCLS = 'fairygui::Transition *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'fui.Transition',
}

typedef {
    CPPCLS = 'fairygui::TreeNode *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'fui.TreeNode',
}

typedef {
    CPPCLS = 'fairygui::TreeView *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'fui.TreeView',
}

typedef {
    CPPCLS = 'fairygui::UIConfig *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'fui.UIConfig',
}

typedef {
    CPPCLS = 'fairygui::UIEventDispatcher *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'fui.UIEventDispatcher',
}

typedef {
    CPPCLS = 'fairygui::UIEventType *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'fui.UIEventType',
}

typedef {
    CPPCLS = 'fairygui::UIObjectFactory *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'fui.UIObjectFactory',
}

typedef {
    CPPCLS = 'fairygui::UIPackage *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'fui.UIPackage',
}

typedef {
    CPPCLS = 'fairygui::UISource *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'fui.UISource',
}

typedef {
    CPPCLS = 'fairygui::Window *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'fui.Window',
}

