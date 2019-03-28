local function make_luacls(cppname)
    cppname = string.gsub(cppname, '^fairygui::', 'fgui.')
    cppname = string.gsub(cppname, "[ *]*$", '')
    return cppname
end

local function make_auto_conv_func(cppname)
    cppname = string.gsub(cppname, '::', '_')
    cppname = string.gsub(cppname, '[ *]*$', '')
    return 'auto_luacv_$$_' .. cppname
end

local function make_manual_conv_func(cppname)
    cppname = string.gsub(cppname, '::', '_')
    cppname = string.gsub(cppname, '[ *]*$', '')
    return 'manual_luacv_$$_' .. cppname
end

REG_TYPE {
    TYPENAME = [[
        fairygui::Margin
    ]],
    CONV_FUNC = make_auto_conv_func,
    INIT_VALUE = false,
}

REG_TYPE {
    TYPENAME = 'fairygui::EventTag',
    CONV_FUNC = 'manual_luacv_$$_fairygui_EventTag',
    INIT_VALUE = false,
}

REG_TYPE {
    TYPENAME = [[
        fairygui::AutoSizeType
        fairygui::ButtonMode
        fairygui::ChildrenRenderOrder
        fairygui::FillMethod
        fairygui::FillOrigin
        fairygui::FlipType
        fairygui::GroupLayoutType
        fairygui::ListLayoutType
        fairygui::ListSelectionMode
        fairygui::LoaderFillType
        fairygui::ObjectType
        fairygui::OverflowType
        fairygui::PackageItemType
        fairygui::PopupDirection
        fairygui::ProgressTitleType
        fairygui::RelationType
        fairygui::ScrollType
        fairygui::TransitionActionType
    ]],
    DECL_TYPE = 'lua_Unsigned',
    CONV_FUNC = "olua_$$_uint",
    VALUE_TYPE = true,
}

REG_TYPE {
    TYPENAME = [[
        fairygui::EventContext *
        fairygui::GComponent *
        fairygui::GController *
        fairygui::GearBase *
        fairygui::GGroup *
        fairygui::GObject *
        fairygui::GRoot *
        fairygui::GScrollBar *
        fairygui::IHitTest *
        fairygui::IUISource *
        fairygui::PackageItem *
        fairygui::RelationItem *
        fairygui::Relations *
        fairygui::ScrollPane *
        fairygui::ScrollPane *
        fairygui::Transition *
        fairygui::GGraph *
        fairygui::UIEventDispatcher *
        fairygui::UISource *
        fairygui::Window *
    ]],
    CONV_FUNC = "olua_$$_cppobj",
    LUACLS = make_luacls,
}

REG_TYPE {
    TYPENAME = [[
    ]],
    CONV_FUNC = "olua_$$_obj",
    LUACLS = function (name)
        name = string.gsub(name, 'sp', 'sp.')
        name = string.gsub(name, '[ *]+', '')
        return name
    end,
}
