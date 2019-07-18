local olua = require "olua"
local typedef = olua.typedef

olua.nowarning(typedef)

typedef {
    CONV_FUNC = 'auto_olua_$$_cocos2d_ui_Margin',
    CPPCLS = 'cocos2d::ui::Margin',
}

typedef {
    CPPCLS = 'cocos2d::experimental::ui::VideoPlayer::EventType',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'ccui.VideoPlayer.EventType',
}

typedef {
    CPPCLS = 'cocos2d::experimental::ui::VideoPlayer::StyleType',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'ccui.VideoPlayer.StyleType',
}

typedef {
    CPPCLS = 'cocos2d::ui::CheckBox::EventType',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'ccui.CheckBox.EventType',
}

typedef {
    CPPCLS = 'cocos2d::ui::EditBox::InputFlag',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'ccui.EditBox.InputFlag',
}

typedef {
    CPPCLS = 'cocos2d::ui::EditBox::InputMode',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'ccui.EditBox.InputMode',
}

typedef {
    CPPCLS = 'cocos2d::ui::EditBox::KeyboardReturnType',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'ccui.EditBox.KeyboardReturnType',
}

typedef {
    CPPCLS = 'cocos2d::ui::EditBoxDelegate::EditBoxEndAction',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'ccui.EditBoxDelegate.EditBoxEndAction',
}

typedef {
    CPPCLS = 'cocos2d::ui::Layout::BackGroundColorType',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'ccui.Layout.BackGroundColorType',
}

typedef {
    CPPCLS = 'cocos2d::ui::Layout::ClippingType',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'ccui.Layout.ClippingType',
}

typedef {
    CPPCLS = 'cocos2d::ui::Layout::Type',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'ccui.Layout.Type',
}

typedef {
    CPPCLS = 'cocos2d::ui::LayoutComponent::HorizontalEdge',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'ccui.LayoutComponent.HorizontalEdge',
}

typedef {
    CPPCLS = 'cocos2d::ui::LayoutComponent::VerticalEdge',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'ccui.LayoutComponent.VerticalEdge',
}

typedef {
    CPPCLS = 'cocos2d::ui::LayoutParameter::Type',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'ccui.LayoutParameter.Type',
}

typedef {
    CPPCLS = 'cocos2d::ui::LinearLayoutParameter::LinearGravity',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'ccui.LinearLayoutParameter.LinearGravity',
}

typedef {
    CPPCLS = 'cocos2d::ui::ListView::EventType',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'ccui.ListView.EventType',
}

typedef {
    CPPCLS = 'cocos2d::ui::ListView::Gravity',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'ccui.ListView.Gravity',
}

typedef {
    CPPCLS = 'cocos2d::ui::ListView::MagneticType',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'ccui.ListView.MagneticType',
}

typedef {
    CPPCLS = 'cocos2d::ui::LoadingBar::Direction',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'ccui.LoadingBar.Direction',
}

typedef {
    CPPCLS = 'cocos2d::ui::PageView::EventType',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'ccui.PageView.EventType',
}

typedef {
    CPPCLS = 'cocos2d::ui::PageView::TouchDirection',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'ccui.PageView.TouchDirection',
}

typedef {
    CPPCLS = 'cocos2d::ui::RadioButton::EventType',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'ccui.RadioButton.EventType',
}

typedef {
    CPPCLS = 'cocos2d::ui::RadioButtonGroup::EventType',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'ccui.RadioButtonGroup.EventType',
}

typedef {
    CPPCLS = 'cocos2d::ui::RelativeLayoutParameter::RelativeAlign',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'ccui.RelativeLayoutParameter.RelativeAlign',
}

typedef {
    CPPCLS = 'cocos2d::ui::RichElement::Type',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'ccui.RichElement.Type',
}

typedef {
    CPPCLS = 'cocos2d::ui::RichText::HorizontalAlignment',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'ccui.RichText.HorizontalAlignment',
}

typedef {
    CPPCLS = 'cocos2d::ui::RichText::WrapMode',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'ccui.RichText.WrapMode',
}

typedef {
    CPPCLS = 'cocos2d::ui::Scale9Sprite::RenderingType',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'ccui.Scale9Sprite.RenderingType',
}

typedef {
    CPPCLS = 'cocos2d::ui::Scale9Sprite::State',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'ccui.Scale9Sprite.State',
}

typedef {
    CPPCLS = 'cocos2d::ui::ScrollView::Direction',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'ccui.ScrollView.Direction',
}

typedef {
    CPPCLS = 'cocos2d::ui::ScrollView::EventType',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'ccui.ScrollView.EventType',
}

typedef {
    CPPCLS = 'cocos2d::ui::Slider::EventType',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'ccui.Slider.EventType',
}

typedef {
    CPPCLS = 'cocos2d::ui::TabControl::Dock',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'ccui.TabControl.Dock',
}

typedef {
    CPPCLS = 'cocos2d::ui::TabControl::EventType',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'ccui.TabControl.EventType',
}

typedef {
    CPPCLS = 'cocos2d::ui::TabHeader::EventType',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'ccui.TabHeader.EventType',
}

typedef {
    CPPCLS = 'cocos2d::ui::Text::Type',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'ccui.Text.Type',
}

typedef {
    CPPCLS = 'cocos2d::ui::TextField::EventType',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'ccui.TextField.EventType',
}

typedef {
    CPPCLS = 'cocos2d::ui::Widget::BrightStyle',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'ccui.Widget.BrightStyle',
}

typedef {
    CPPCLS = 'cocos2d::ui::Widget::FocusDirection',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'ccui.Widget.FocusDirection',
}

typedef {
    CPPCLS = 'cocos2d::ui::Widget::PositionType',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'ccui.Widget.PositionType',
}

typedef {
    CPPCLS = 'cocos2d::ui::Widget::SizeType',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'ccui.Widget.SizeType',
}

typedef {
    CPPCLS = 'cocos2d::ui::Widget::TextureResType',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'ccui.Widget.TextureResType',
}

typedef {
    CPPCLS = 'cocos2d::ui::Widget::TouchEventType',
    DECLTYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    LUACLS = 'ccui.Widget.TouchEventType',
}

typedef {
    CPPCLS = 'cocos2d::experimental::ui::VideoPlayer *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'ccui.VideoPlayer',
}

typedef {
    CPPCLS = 'cocos2d::experimental::ui::WebView *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'ccui.WebView',
}

typedef {
    CPPCLS = 'cocos2d::ui::AbstractCheckButton *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'ccui.AbstractCheckButton',
}

typedef {
    CPPCLS = 'cocos2d::ui::Button *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'ccui.Button',
}

typedef {
    CPPCLS = 'cocos2d::ui::CheckBox *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'ccui.CheckBox',
}

typedef {
    CPPCLS = 'cocos2d::ui::EditBox *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'ccui.EditBox',
}

typedef {
    CPPCLS = 'cocos2d::ui::EditBoxDelegate *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'ccui.EditBoxDelegate',
}

typedef {
    CPPCLS = 'cocos2d::ui::HBox *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'ccui.HBox',
}

typedef {
    CPPCLS = 'cocos2d::ui::Helper *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'ccui.Helper',
}

typedef {
    CPPCLS = 'cocos2d::ui::ImageView *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'ccui.ImageView',
}

typedef {
    CPPCLS = 'cocos2d::ui::Layout *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'ccui.Layout',
}

typedef {
    CPPCLS = 'cocos2d::ui::LayoutComponent *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'ccui.LayoutComponent',
}

typedef {
    CPPCLS = 'cocos2d::ui::LayoutParameter *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'ccui.LayoutParameter',
}

typedef {
    CPPCLS = 'cocos2d::ui::LinearLayoutParameter *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'ccui.LinearLayoutParameter',
}

typedef {
    CPPCLS = 'cocos2d::ui::ListView *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'ccui.ListView',
}

typedef {
    CPPCLS = 'cocos2d::ui::LoadingBar *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'ccui.LoadingBar',
}

typedef {
    CPPCLS = 'cocos2d::ui::LuaEditBoxDelegate *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'ccui.LuaEditBoxDelegate',
}

typedef {
    CPPCLS = 'cocos2d::ui::PageView *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'ccui.PageView',
}

typedef {
    CPPCLS = 'cocos2d::ui::RadioButton *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'ccui.RadioButton',
}

typedef {
    CPPCLS = 'cocos2d::ui::RadioButtonGroup *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'ccui.RadioButtonGroup',
}

typedef {
    CPPCLS = 'cocos2d::ui::RelativeBox *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'ccui.RelativeBox',
}

typedef {
    CPPCLS = 'cocos2d::ui::RelativeLayoutParameter *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'ccui.RelativeLayoutParameter',
}

typedef {
    CPPCLS = 'cocos2d::ui::RichElement *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'ccui.RichElement',
}

typedef {
    CPPCLS = 'cocos2d::ui::RichElementCustomNode *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'ccui.RichElementCustomNode',
}

typedef {
    CPPCLS = 'cocos2d::ui::RichElementImage *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'ccui.RichElementImage',
}

typedef {
    CPPCLS = 'cocos2d::ui::RichElementNewLine *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'ccui.RichElementNewLine',
}

typedef {
    CPPCLS = 'cocos2d::ui::RichElementText *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'ccui.RichElementText',
}

typedef {
    CPPCLS = 'cocos2d::ui::RichText *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'ccui.RichText',
}

typedef {
    CPPCLS = 'cocos2d::ui::Scale9Sprite *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'ccui.Scale9Sprite',
}

typedef {
    CPPCLS = 'cocos2d::ui::ScrollView *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'ccui.ScrollView',
}

typedef {
    CPPCLS = 'cocos2d::ui::ScrollViewBar *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'ccui.ScrollViewBar',
}

typedef {
    CPPCLS = 'cocos2d::ui::Slider *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'ccui.Slider',
}

typedef {
    CPPCLS = 'cocos2d::ui::TabControl *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'ccui.TabControl',
}

typedef {
    CPPCLS = 'cocos2d::ui::TabHeader *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'ccui.TabHeader',
}

typedef {
    CPPCLS = 'cocos2d::ui::Text *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'ccui.Text',
}

typedef {
    CPPCLS = 'cocos2d::ui::TextAtlas *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'ccui.TextAtlas',
}

typedef {
    CPPCLS = 'cocos2d::ui::TextBMFont *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'ccui.TextBMFont',
}

typedef {
    CPPCLS = 'cocos2d::ui::TextField *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'ccui.TextField',
}

typedef {
    CPPCLS = 'cocos2d::ui::UICCTextField *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'ccui.UICCTextField',
}

typedef {
    CPPCLS = 'cocos2d::ui::VBox *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'ccui.VBox',
}

typedef {
    CPPCLS = 'cocos2d::ui::Widget *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'ccui.Widget',
}

