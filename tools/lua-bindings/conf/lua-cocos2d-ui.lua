local olua = require "olua"
local autoconf = require "autoconf"
local M = autoconf.typemod 'cocos2d_ui'
local typeconf = M.typeconf
local typedef = M.typedef

M.PATH = '../../frameworks/libxgame/src/lua-bindings'
M.INCLUDES = [[
#include "lua-bindings/lua_cocos2d_ui.h"
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "lua-bindings/LuaCocosAdapter.h"
#include "xgame/xlua.h"
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "ui/UIScrollViewBar.h"
]]
M.CHUNK = [[]]

typedef {
    CPPCLS = 'cocos2d::ui::Margin',
    CONV = 'auto_olua_$$_cocos2d_ui_Margin',
}

M.MAKE_LUACLS = function (cppname)
    cppname = string.gsub(cppname, '^cocos2d::ui::', 'ccui.')
    cppname = string.gsub(cppname, "::", ".")
    return cppname
end

M.EXCLUDE_TYPE = require 'conf.exclude-type'
M.EXCLUDE_TYPE 'cocos2d::ui::PageViewIndicator'

typeconf 'cocos2d::ui::Widget::FocusDirection'
typeconf 'cocos2d::ui::Widget::PositionType'
typeconf 'cocos2d::ui::Widget::SizeType'
typeconf 'cocos2d::ui::Widget::TouchEventType'
typeconf 'cocos2d::ui::Widget::TextureResType'
typeconf 'cocos2d::ui::Widget::BrightStyle'

local Widget = typeconf 'cocos2d::ui::Widget'
Widget.EXCLUDE 'createInstance'
Widget.ATTR('getVirtualRenderer', {RET = '@hold(coexist protectedChildren)'})
Widget.VAR('onFocusChanged', '@nullable std::function<void(Widget*,Widget*)> onFocusChanged')
Widget.VAR('onNextFocusedWidget', '@nullable std::function<Widget*(FocusDirection)> onNextFocusedWidget')
Widget.CALLBACK {
    FUNCS = {'void addTouchEventListener(@nullable const std::function<void(Ref*,Widget::TouchEventType)>& callback)'},
    TAG_MAKER = 'touchEventListener',
    TAG_MODE = 'OLUA_TAG_REPLACE',
}
Widget.CALLBACK {
    FUNCS = {'void addClickEventListener(@nullable std::function<void(Ref*)>& callback)'},
    TAG_MAKER = 'clickEventListener',
    TAG_MODE = 'OLUA_TAG_REPLACE',
}
Widget.CALLBACK {
    FUNCS = {'void addCCSEventListener(@nullable const std::function<void(Ref*, int)>& callback)'},
    TAG_MAKER = 'ccsEventListener',
    TAG_MODE = 'OLUA_TAG_REPLACE',
}

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

local Layout = typeconf 'cocos2d::ui::Layout'
Layout.VAR('onPassFocusToChild', '@nullable std::function<int(Widget::FocusDirection, Widget*)> onPassFocusToChild')

typeconf 'cocos2d::ui::HBox'
typeconf 'cocos2d::ui::VBox'
typeconf 'cocos2d::ui::RelativeBox'

local WebView = typeconf 'cocos2d::ui::WebView'
WebView.DEFIF = '#ifdef CCLUA_HAVE_WEBVIEW'
WebView.CALLBACK {NAME = 'setOnShouldStartLoading', NULLABLE = true, LOCAL = false}
WebView.CALLBACK {NAME = 'setOnDidFinishLoading', NULLABLE = true, LOCAL = false}
WebView.CALLBACK {NAME = 'setOnDidFailLoading', NULLABLE = true, LOCAL = false}
WebView.CALLBACK {NAME = 'setOnJSCallback', NULLABLE = true, LOCAL = false}

local EventType = typeconf 'cocos2d::ui::VideoPlayer::EventType'
EventType.DEFIF = '#ifdef CCLUA_HAVE_VIDEOPLAYER'

local StyleType = typeconf 'cocos2d::ui::VideoPlayer::StyleType'
StyleType.DEFIF = '#ifdef CCLUA_HAVE_VIDEOPLAYER'

local VideoPlayer = typeconf 'cocos2d::ui::VideoPlayer'
VideoPlayer.DEFIF = '#ifdef CCLUA_HAVE_VIDEOPLAYER'
VideoPlayer.CALLBACK {
    FUNCS = {'void addEventListener(@nullable const std::function<void(Ref*,VideoPlayer::EventType)>& callback)'},
    TAG_MAKER = 'videoPlayerCallback',
    TAG_MODE = 'OLUA_TAG_REPLACE',
}

local AbstractCheckButton = typeconf 'cocos2d::ui::AbstractCheckButton'
AbstractCheckButton.ATTR('getRendererBackground', {RET = '@hold(coexist protectedChildren)'})
AbstractCheckButton.ATTR('getRendererBackgroundSelected', {RET = '@hold(coexist protectedChildren)'})
AbstractCheckButton.ATTR('getRendererFrontCross', {RET = '@hold(coexist protectedChildren)'})
AbstractCheckButton.ATTR('getRendererBackgroundDisabled', {RET = '@hold(coexist protectedChildren)'})
AbstractCheckButton.ATTR('getRendererFrontCrossDisabled', {RET = '@hold(coexist protectedChildren)'})

typeconf 'cocos2d::ui::TabHeader::EventType'

local TabHeader = typeconf 'cocos2d::ui::TabHeader'
TabHeader.ATTR('getTitleRenderer', {RET = '@hold(coexist protectedChildren)'})

typeconf 'cocos2d::ui::TabControl::Dock'
typeconf 'cocos2d::ui::TabControl::EventType'

local TabControl = typeconf 'cocos2d::ui::TabControl'
TabControl.ATTR('removeTab', {RET = '@unhold(cmp protectedChildren)'})
TabControl.ATTR('getTabHeader', {RET = '@hold(coexist protectedChildren)'})
TabControl.ATTR('getTabContainer', {RET = '@hold(coexist protectedChildren)'})
TabControl.ATTR('insertTab', {ARG2 = '@hold(coexist protectedChildren)', ARG3 = '@hold(coexist protectedChildren)'})
TabControl.CALLBACK {
    FUNCS = {'void setTabChangedEventListener(@nullable const std::function<void(int tabIndex, EventType)>& callback)'},
    TAG_MAKER = 'tabChangedEventListener',
    TAG_MODE = 'OLUA_TAG_REPLACE',
}

typeconf 'cocos2d::ui::ScrollView::Direction'
typeconf 'cocos2d::ui::ScrollView::EventType'

local ScrollView = typeconf 'cocos2d::ui::ScrollView'
ScrollView.ATTR('getInnerContainer', {RET = '@hold(coexist protectedChildren)'})
ScrollView.CALLBACK {
    FUNCS = {'void addEventListener(@nullable const std::function<void(Ref*, EventType)>& callback)'},
    TAG_MAKER = 'scrollViewCallback',
    TAG_MODE = 'OLUA_TAG_REPLACE'
}
ScrollView.ALIAS('addEventListener', 'addScrollEventListener')

typeconf 'cocos2d::ui::ListView::Gravity'
typeconf 'cocos2d::ui::ListView::EventType'
typeconf 'cocos2d::ui::ListView::MagneticType'

local ListView = typeconf 'cocos2d::ui::ListView'
ListView.ATTR('pushBackCustomItem', {ARG1 = '@hold(coexist children)'})
ListView.ATTR('insertCustomItem', {ARG1 = '@hold(coexist children)'})
ListView.ATTR('removeLastItem', {RET = '@unhold(cmp children)'})
ListView.ATTR('removeItem', {RET = '@unhold(cmp children)'})
ListView.ATTR('removeAllItems', {RET = '@unhold(cmp children)'})
ListView.ATTR('getItem', {RET = '@hold(coexist children)'})
ListView.ATTR('getItems', {RET = '@hold(coexist children)'})
ListView.CALLBACK {
    FUNCS = {'void addEventListener(@nullable const std::function<void(Ref*, EventType)>& callback)'},
    TAG_MAKER = 'ListViewCallback',
    TAG_MODE = 'OLUA_TAG_REPLACE',
}
ListView.ALIAS('addEventListener', 'addListViewEventListener')

typeconf 'cocos2d::ui::LoadingBar::Direction'
typeconf 'cocos2d::ui::LoadingBar'
typeconf 'cocos2d::ui::PageView::EventType'
typeconf 'cocos2d::ui::PageView::TouchDirection'

local PageView = typeconf 'cocos2d::ui::PageView'
PageView.ATTR('addPage', {ARG1 = '@hold(coexist children)'})
PageView.ATTR('insertPage', {ARG1 = '@hold(coexist children)'})
PageView.ATTR('removePage', {ARG1 = '@unhold(coexist children)'})
PageView.ATTR('removePageAtIndex', {RET = '@unhold(cmp children)'})
PageView.ATTR('removeAllPages', {RET = '@unhold(all children)'})
PageView.CALLBACK {
    FUNCS = {'void addEventListener(@nullable const std::function<void(Ref*, PageView::EventType)>& callback)'},
    TAG_MAKER = 'PageViewCallback',
    TAG_MODE = 'OLUA_TAG_REPLACE',
}
PageView.ALIAS('addEventListener', 'addPageViewEventListener')

typeconf 'cocos2d::ui::RichElement::Type'
typeconf 'cocos2d::ui::RichElement'
typeconf 'cocos2d::ui::RichElementText'
typeconf 'cocos2d::ui::RichElementImage'
typeconf 'cocos2d::ui::RichElementCustomNode'
typeconf 'cocos2d::ui::RichElementNewLine'
typeconf 'cocos2d::ui::RichText::WrapMode'
typeconf 'cocos2d::ui::RichText::HorizontalAlignment'

local RichText = typeconf 'cocos2d::ui::RichText'
RichText.EXCLUDE 'setTagDescription'
RichText.EXCLUDE 'initWithXML'
RichText.CALLBACK {
    NAME = 'createWithXML',
    TAG_MAKER = 'OpenUrlHandler',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    CPPFUNC = 'initWithXML',
}

typeconf 'cocos2d::ui::ScrollViewBar'
typeconf 'cocos2d::ui::Slider::EventType'

local Slider = typeconf 'cocos2d::ui::Slider'
Slider.ATTR('getSlidBallNormalRenderer', {RET = '@hold(coexist protectedChildren)'})
Slider.ATTR('getSlidBallPressedRenderer', {RET = '@hold(coexist protectedChildren)'})
Slider.ATTR('getSlidBallDisabledRenderer', {RET = '@hold(coexist protectedChildren)'})
Slider.ATTR('getSlidBallRenderer', {RET = '@hold(coexist protectedChildren)'})
Slider.CALLBACK {
    FUNCS = {'void addEventListener(@nullable const std::function<void(Ref*,EventType)>& callback)'},
    TAG_MAKER = 'sliderCallback',
    TAG_MODE = 'OLUA_TAG_REPLACE',
}

typeconf 'cocos2d::ui::Text::Type'
typeconf 'cocos2d::ui::Text'
typeconf 'cocos2d::ui::TextAtlas'
typeconf 'cocos2d::ui::TextBMFont'
typeconf 'cocos2d::ui::UICCTextField'
typeconf 'cocos2d::ui::TextField::EventType'

local TextField = typeconf 'cocos2d::ui::TextField'
TextField.CALLBACK {
    FUNCS = {'void addEventListener(@nullable const std::function<void(Ref*, EventType)>& callback)'},
    TAG_MAKER = 'textFieldCallback',
    TAG_MODE = 'OLUA_TAG_REPLACE',
}

local Button = typeconf 'cocos2d::ui::Button'
Button.ATTR('setTitleLabel', {ARG1 = '@hold(coexist protectedChildren)'})
Button.ATTR('getTitleRenderer', {RET = '@hold(coexist protectedChildren)'})
Button.ATTR('getTitleLabel', {RET = '@hold(coexist protectedChildren)'})
Button.ATTR('getRendererNormal', {RET = '@hold(coexist protectedChildren)'})
Button.ATTR('getRendererClicked', {RET = '@hold(coexist protectedChildren)'})
Button.ATTR('getRendererDisabled', {RET = '@hold(coexist protectedChildren)'})

typeconf 'cocos2d::ui::CheckBox::EventType'

local CheckBox = typeconf 'cocos2d::ui::CheckBox'
CheckBox.CALLBACK {
    FUNCS = {'void addEventListener(@nullable const std::function<void(Ref*,CheckBox::EventType)>& callback)'},
    TAG_MAKER = 'checkBoxCallback',
    TAG_MODE = 'OLUA_TAG_REPLACE',
}

typeconf 'cocos2d::ui::RadioButton::EventType'

local RadioButton = typeconf 'cocos2d::ui::RadioButton'
RadioButton.CALLBACK {
    FUNCS = {'void addEventListener(@nullable const std::function<void(RadioButton* radioButton, EventType)>& callback)'},
    TAG_MAKER = 'radioButtonCallback',
    TAG_MODE = 'OLUA_TAG_REPLACE',
}

typeconf 'cocos2d::ui::RadioButtonGroup::EventType'

local RadioButtonGroup = typeconf 'cocos2d::ui::RadioButtonGroup'
RadioButtonGroup.CALLBACK {
    FUNCS = {'void addEventListener(@nullable const std::function<void(RadioButton* radioButton, int index, EventType)>& callback)'},
    TAG_MAKER = 'radioButtonCallback',
    TAG_MODE = 'OLUA_TAG_REPLACE',
}

typeconf 'cocos2d::ui::ImageView'
typeconf 'cocos2d::ui::EditBoxDelegate::EditBoxEndAction'
typeconf 'cocos2d::ui::EditBoxDelegate'
typeconf 'cocos2d::ui::LuaEditBoxDelegate'
typeconf 'cocos2d::ui::EditBox::KeyboardReturnType'
typeconf 'cocos2d::ui::EditBox::InputMode'
typeconf 'cocos2d::ui::EditBox::InputFlag'
typeconf 'cocos2d::ui::EditBox'
    .ATTR('setDelegate', {ARG1 = '@hold(exclusive delegate)'})
    .ATTR('getDelegate', {RET = '@hold(exclusive delegate)'})

return M