module 'cocos2d_ui'

path '../../frameworks/libxgame/src/lua-bindings'

headers [[
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "lua-bindings/LuaCocosAdapter.h"
#include "cclua/xlua.h"
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "ui/UIScrollViewBar.h"
]]

luacls(function (cppname)
    cppname = string.gsub(cppname, '^cocos2d::ui::', 'ccui.')
    cppname = string.gsub(cppname, "::", ".")
    return cppname
end)

include 'conf/exclude-type.lua'

exclude 'cocos2d::ui::PageViewIndicator'

typeconf 'cocos2d::ui::Widget::FocusDirection'
typeconf 'cocos2d::ui::Widget::PositionType'
typeconf 'cocos2d::ui::Widget::SizeType'
typeconf 'cocos2d::ui::Widget::TouchEventType'
typeconf 'cocos2d::ui::Widget::TextureResType'
typeconf 'cocos2d::ui::Widget::BrightStyle'
typeconf 'cocos2d::ui::Widget::ccWidgetTouchCallback'
typeconf 'cocos2d::ui::Widget::ccWidgetClickCallback'
typeconf 'cocos2d::ui::Widget::ccWidgetEventCallback'

typeconf 'cocos2d::ui::Widget'
    .exclude 'createInstance'
    .func 'getVirtualRenderer' .ret '@addref(protectedChildren |)'
    .func 'findNextFocusedWidget' .arg2 '@nullable'
    .func 'onFocusChange' .arg1 '@nullable' .arg2 '@nullable'
    .func 'dispatchFocusEvent' .arg1 '@nullable' .arg2 '@nullable'
    .callback 'onFocusChanged' .localvar 'false'
    .callback 'addTouchEventListener' .arg1 '@nullable' .localvar 'false'
    .callback 'addClickEventListener' .arg1 '@nullable' .localvar 'false'
    .callback 'addCCSEventListener' .arg1 '@nullable' .localvar 'false'

typeconf 'cocos2d::ui::Helper'
typeconf 'cocos2d::ui::Scale9Sprite::State'
typeconf 'cocos2d::ui::Scale9Sprite::RenderingType'
typeconf 'cocos2d::ui::Scale9Sprite'
typeconf 'cocos2d::ui::LayoutComponent::HorizontalEdge'
typeconf 'cocos2d::ui::LayoutComponent::VerticalEdge'
typeconf 'cocos2d::ui::LayoutComponent'
typeconf 'cocos2d::ui::LayoutParameter::Type'
typeconf 'cocos2d::ui::LayoutParameter'
typeconf 'cocos2d::ui::LinearLayoutParameter::LinearGravity'
typeconf 'cocos2d::ui::LinearLayoutParameter'
typeconf 'cocos2d::ui::RelativeLayoutParameter::RelativeAlign'
typeconf 'cocos2d::ui::RelativeLayoutParameter'
typeconf 'cocos2d::ui::Layout::Type'
typeconf 'cocos2d::ui::Layout::ClippingType'
typeconf 'cocos2d::ui::Layout::BackGroundColorType'

typeconf 'cocos2d::ui::Layout'
    .callback 'onPassFocusToChild' .localvar 'false'

typeconf 'cocos2d::ui::HBox'
typeconf 'cocos2d::ui::VBox'
typeconf 'cocos2d::ui::RelativeBox'

ifdef 'defined(CCLUA_OS_IOS) || defined(CCLUA_OS_ANDROID)'
typeconf 'cocos2d::ui::WebView::ccWebViewCallback'
typeconf 'cocos2d::ui::WebView'
    .callback 'setOnShouldStartLoading' .arg1 '@nullable' .localvar 'false'
    .callback 'setOnDidFinishLoading' .arg1 '@nullable' .localvar 'false'
    .callback 'setOnDidFailLoading' .arg1 '@nullable' .localvar 'false'
    .callback 'setOnJSCallback' .arg1 '@nullable' .localvar 'false'
typeconf 'cocos2d::ui::VideoPlayer::EventType'
typeconf 'cocos2d::ui::VideoPlayer::ccVideoPlayerCallback'
typeconf 'cocos2d::ui::VideoPlayer::StyleType'
typeconf 'cocos2d::ui::VideoPlayer'
    .callback 'addEventListener'
        .tag_maker 'videoPlayerCallback'
        .tag_mode 'replace'
        .localvar 'false'
endif ''

typeconf 'cocos2d::ui::AbstractCheckButton'
    .func 'getRendererBackground' .ret '@addref(protectedChildren |)'
    .func 'getRendererBackgroundSelected' .ret '@addref(protectedChildren |)'
    .func 'getRendererFrontCross' .ret '@addref(protectedChildren |)'
    .func 'getRendererBackgroundDisabled' .ret '@addref(protectedChildren |)'
    .func 'getRendererFrontCrossDisabled' .ret '@addref(protectedChildren |)'

typeconf 'cocos2d::ui::TabHeader::EventType'

typeconf 'cocos2d::ui::TabHeader'
    .func 'getTitleRenderer' .ret '@addref(protectedChildren |)'

typeconf 'cocos2d::ui::TabControl::Dock'
typeconf 'cocos2d::ui::TabControl::EventType'
typeconf 'cocos2d::ui::TabControl::ccTabControlCallback'

typeconf 'cocos2d::ui::TabControl'
    .func 'removeTab' .ret '@delref(protectedChildren ~)'
    .func 'getTabHeader' .ret '@addref(protectedChildren |)'
    .func 'getTabContainer' .ret '@addref(protectedChildren |)'
    .func 'insertTab' .arg2 '@addref(protectedChildren |)' .arg3 '@addref(protectedChildren |)'
    .callback 'setTabChangedEventListener'
        .tag_maker 'tabChangedEventListener'
        .tag_mode 'replace'
        .arg1 '@nullable'

typeconf 'cocos2d::ui::ScrollView::Direction'
typeconf 'cocos2d::ui::ScrollView::EventType'
typeconf 'cocos2d::ui::ScrollView::ccScrollViewCallback'

typeconf 'cocos2d::ui::ScrollView'
    .func 'getInnerContainer' .ret '@addref(protectedChildren |)'
    .callback 'addEventListener'
        .tag_maker 'scrollViewCallback'
        .tag_mode 'replace'
        .localvar 'false'

typeconf 'cocos2d::ui::ListView::Gravity'
typeconf 'cocos2d::ui::ListView::EventType'
typeconf 'cocos2d::ui::ListView::MagneticType'
typeconf 'cocos2d::ui::ListView::ccListViewCallback'

typeconf 'cocos2d::ui::ListView'
    .func 'pushBackCustomItem' .arg1 '@addref(children |)'
    .func 'insertCustomItem' .arg1 '@addref(children |)'
    .func 'removeLastItem' .ret '@delref(children ~)'
    .func 'removeItem' .ret '@delref(children ~)'
    .func 'removeAllItems' .ret '@delref(children ~)'
    .func 'getItem' .ret '@addref(children |)'
    .func 'getItems' .ret '@addref(children |)'
    .callback 'addEventListener'
        .tag_maker 'ListViewCallback'
        .tag_mode 'replace'
        .localvar 'false'

typeconf 'cocos2d::ui::LoadingBar::Direction'
typeconf 'cocos2d::ui::LoadingBar'
typeconf 'cocos2d::ui::PageView::EventType'
typeconf 'cocos2d::ui::PageView::TouchDirection'
typeconf 'cocos2d::ui::PageView::ccPageViewCallback'

typeconf 'cocos2d::ui::PageView'
    .func 'addPage' .arg1 '@addref(children |)'
    .func 'insertPage' .arg1 '@addref(children |)'
    .func 'removePage' .arg1 '@delref(children |)'
    .func 'removePageAtIndex' .ret '@delref(children ~)'
    .func 'removeAllPages' .ret '@delref(children *)'
    .callback 'addEventListener'
        .tag_maker 'PageViewCallback'
        .tag_mode 'replace'
        .localvar 'false'

typeconf 'cocos2d::ui::RichElement::Type'
typeconf 'cocos2d::ui::RichElement'
typeconf 'cocos2d::ui::RichElementText'
typeconf 'cocos2d::ui::RichElementImage'
typeconf 'cocos2d::ui::RichElementCustomNode'
typeconf 'cocos2d::ui::RichElementNewLine'
typeconf 'cocos2d::ui::RichText::WrapMode'
typeconf 'cocos2d::ui::RichText::HorizontalAlignment'
typeconf 'cocos2d::ui::RichText::OpenUrlHandler'

typeconf 'cocos2d::ui::RichText'
    .exclude 'setTagDescription'
    .exclude 'initWithXML'
    .callback 'createWithXML'
        .tag_maker 'OpenUrlHandler'
        .tag_mode 'replace'
        .tag_store '-1'

typeconf 'cocos2d::ui::ScrollViewBar'
typeconf 'cocos2d::ui::Slider::EventType'
typeconf 'cocos2d::ui::Slider::ccSliderCallback'

typeconf 'cocos2d::ui::Slider'
    .func 'getSlidBallNormalRenderer' .ret '@addref(protectedChildren |)'
    .func 'getSlidBallPressedRenderer' .ret '@addref(protectedChildren |)'
    .func 'getSlidBallDisabledRenderer' .ret '@addref(protectedChildren |)'
    .func 'getSlidBallRenderer' .ret '@addref(protectedChildren |)'
    .callback 'addEventListener'
        .tag_maker 'sliderCallback'
        .tag_mode 'replace'
        .localvar 'false'

typeconf 'cocos2d::ui::Text::Type'
typeconf 'cocos2d::ui::Text'
typeconf 'cocos2d::ui::TextAtlas'
typeconf 'cocos2d::ui::TextBMFont'
typeconf 'cocos2d::ui::UICCTextField'
typeconf 'cocos2d::ui::TextField::EventType'
typeconf 'cocos2d::ui::TextField::ccTextFieldCallback'

typeconf 'cocos2d::ui::TextField'
    .callback 'addEventListener'
        .tag_maker 'textFieldCallback'
        .tag_mode 'replace'
        .localvar 'false'

typeconf 'cocos2d::ui::Button'
    .func 'setTitleLabel' .arg1 '@addref(protectedChildren |)'
    .func 'getTitleRenderer' .ret '@addref(protectedChildren |)'
    .func 'getTitleLabel' .ret '@addref(protectedChildren |)'
    .func 'getRendererNormal' .ret '@addref(protectedChildren |)'
    .func 'getRendererClicked' .ret '@addref(protectedChildren |)'
    .func 'getRendererDisabled' .ret '@addref(protectedChildren |)'

typeconf 'cocos2d::ui::CheckBox::EventType'
typeconf 'cocos2d::ui::CheckBox::ccCheckBoxCallback'

typeconf 'cocos2d::ui::CheckBox'
    .callback 'addEventListener'
        .tag_maker 'checkBoxCallback'
        .tag_mode 'replace'
        .localvar 'false'

typeconf 'cocos2d::ui::RadioButton::EventType'
typeconf 'cocos2d::ui::RadioButton::ccRadioButtonCallback'

typeconf 'cocos2d::ui::RadioButton'
    .callback 'addEventListener'
        .tag_maker 'radioButtonCallback'
        .tag_mode 'replace'
        .localvar 'false'

typeconf 'cocos2d::ui::RadioButtonGroup::EventType'
typeconf 'cocos2d::ui::RadioButtonGroup::ccRadioButtonGroupCallback'

typeconf 'cocos2d::ui::RadioButtonGroup'
    .callback 'addEventListener'
        .tag_maker 'radioButtonCallback'
        .tag_mode 'replace'
        .localvar 'false'

typeconf 'cocos2d::ui::ImageView'
typeconf 'cocos2d::ui::EditBoxDelegate::EditBoxEndAction'
typeconf 'cocos2d::ui::EditBoxDelegate'
typeconf 'cocos2d::ui::LuaEditBoxDelegate'
typeconf 'cocos2d::ui::EditBox::KeyboardReturnType'
typeconf 'cocos2d::ui::EditBox::InputMode'
typeconf 'cocos2d::ui::EditBox::InputFlag'
typeconf 'cocos2d::ui::EditBox'
    .func 'setDelegate' .arg1 '@addref(delegate ^)'
    .func 'getDelegate' .ret '@addref(delegate ^)'
