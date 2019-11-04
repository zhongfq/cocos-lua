local olua = require "olua"
local typemod = require "typemod"
local M = typemod 'cocos2d_ui'
local typeconf = M.typeconf
local typedef = M.typedef

M.PARSER = {
    HEADERS = {
        'cocos2d.h',
        'ui/CocosGUI.h',
        'ui/UIScrollViewBar.h',
        'lua-bindings/LuaCocosAdapter.h'
    },
    FLAGS = {
        '-I../../frameworks/cocos2d-x/cocos',
        '-I../../frameworks/libxgame/src',
        '-DCC_DLL=',
        '-DEXPORT_DLL=',
    },
}

M.PATH = "../../frameworks/libxgame/src/lua-bindings"
M.INCLUDES = [[
#include "lua-bindings/lua_cocos2d_ui.h"
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "lua-bindings/LuaCocosAdapter.h"
#include "xgame/xlua.h"
#include "xgame/xruntime.h"
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
    cppname = string.gsub(cppname, '^cocos2d::experimental::ui::', 'ccui.')
    cppname = string.gsub(cppname, '^cocos2d::ui::', 'ccui.')
    cppname = string.gsub(cppname, "::", ".")
    cppname = string.gsub(cppname, "[ *]*$", '')
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
Widget.ATTR('getVirtualRenderer', {RET = '@ref(map protectedChildren)'})
Widget.VAR('onFocusChanged', '@nullable std::function<void(Widget*,Widget*)> onFocusChanged')
Widget.VAR('onNextFocusedWidget', '@nullable std::function<Widget*(FocusDirection)> onNextFocusedWidget')
Widget.CALLBACK {
    FUNCS = {'void addTouchEventListener(@nullable const std::function<void(Ref*,Widget::TouchEventType)>& callback)'},
    TAG_MAKER = 'olua_makecallbacktag("touchEventListener")',
    TAG_MODE = 'OLUA_TAG_REPLACE',
}
Widget.CALLBACK {
    FUNCS = {'void addClickEventListener(@nullable std::function<void(Ref*)>& callback)'},
    TAG_MAKER = 'olua_makecallbacktag("clickEventListener")',
    TAG_MODE = 'OLUA_TAG_REPLACE',
}
Widget.CALLBACK {
    FUNCS = {'void addCCSEventListener(@nullable const std::function<void(Ref*, int)>& callback)'},
    TAG_MAKER = 'olua_makecallbacktag("ccsEventListener")',
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

local WebView = typeconf 'cocos2d::experimental::ui::WebView'
WebView.DEFIF = '#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_TIZEN)'
WebView.CALLBACK {
    FUNCS = {'void setOnShouldStartLoading(@nullable const std::function<bool(WebView *sender, const std::string &url)>& callback)'},
    TAG_MAKER = 'olua_makecallbacktag("onShouldStartLoading")',
    TAG_MODE = 'OLUA_TAG_REPLACE',
}
WebView.CALLBACK {
    FUNCS = {'std::function<bool(WebView *sender, const std::string &url)> getOnShouldStartLoading()'},
    TAG_MAKER = 'olua_makecallbacktag("onShouldStartLoading")',
    TAG_MODE = 'OLUA_TAG_EQUAL',
}
WebView.CALLBACK {
    FUNCS = {'void setOnDidFinishLoading(@nullable const std::function<void(WebView *sender, const std::string &url)>& callback)'},
    TAG_MAKER = 'olua_makecallbacktag("onDidFinishLoading")',
    TAG_MODE = 'OLUA_TAG_REPLACE',
}
WebView.CALLBACK {
    FUNCS = {'std::function<void(WebView *sender, const std::string &url)> getOnDidFinishLoading()'},
    TAG_MAKER = 'olua_makecallbacktag("onDidFinishLoading")',
    TAG_MODE = 'OLUA_TAG_EQUAL',
}
WebView.CALLBACK {
    FUNCS = {'void setOnDidFailLoading(@nullable const std::function<void(WebView *sender, const std::string &url)>& callback)'},
    TAG_MAKER = 'olua_makecallbacktag("onDidFailLoading")',
    TAG_MODE = 'OLUA_TAG_REPLACE',
}
WebView.CALLBACK {
    FUNCS = {'std::function<void(WebView *sender, const std::string &url)> getOnDidFailLoading()'},
    TAG_MAKER = 'olua_makecallbacktag("onDidFailLoading")',
    TAG_MODE = 'OLUA_TAG_EQUAL',
}
WebView.CALLBACK {
    FUNCS = {'void setOnJSCallback(@nullable const std::function<void(WebView *sender, const std::string &url)>& callback)'},
    TAG_MAKER = 'olua_makecallbacktag("onJSCallback")',
    TAG_MODE = 'OLUA_TAG_REPLACE',
}
WebView.CALLBACK {
    FUNCS = {'std::function<void(WebView *sender, const std::string &url)> getOnJSCallback()'},
    TAG_MAKER = 'olua_makecallbacktag("onJSCallback")',
    TAG_MODE = 'OLUA_TAG_EQUAL',
}

local EventType = typeconf 'cocos2d::experimental::ui::VideoPlayer::EventType'
EventType.DEFIF = '#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_TIZEN)'

local StyleType = typeconf 'cocos2d::experimental::ui::VideoPlayer::StyleType'
StyleType.DEFIF = '#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_TIZEN)'

local VideoPlayer = typeconf 'cocos2d::experimental::ui::VideoPlayer'
VideoPlayer.DEFIF = '#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_TIZEN)'
VideoPlayer.CALLBACK {
    FUNCS = {'void addEventListener(@nullable const std::function<void(Ref*,VideoPlayer::EventType)>& callback)'},
    TAG_MAKER = 'olua_makecallbacktag("videoPlayerCallback")',
    TAG_MODE = 'OLUA_TAG_REPLACE',
}

local AbstractCheckButton = typeconf 'cocos2d::ui::AbstractCheckButton'
AbstractCheckButton.ATTR('getRendererBackground', {RET = '@ref(map protectedChildren)'})
AbstractCheckButton.ATTR('getRendererBackgroundSelected', {RET = '@ref(map protectedChildren)'})
AbstractCheckButton.ATTR('getRendererFrontCross', {RET = '@ref(map protectedChildren)'})
AbstractCheckButton.ATTR('getRendererBackgroundDisabled', {RET = '@ref(map protectedChildren)'})
AbstractCheckButton.ATTR('getRendererFrontCrossDisabled', {RET = '@ref(map protectedChildren)'})

typeconf 'cocos2d::ui::TabHeader::EventType'

local TabHeader = typeconf 'cocos2d::ui::TabHeader'
TabHeader.ATTR('getTitleRenderer', {RET = '@ref(map protectedChildren)'})

typeconf 'cocos2d::ui::TabControl::Dock'
typeconf 'cocos2d::ui::TabControl::EventType'

local TabControl = typeconf 'cocos2d::ui::TabControl'
TabControl.ATTR('removeTab', {RET = '@unref(cmp protectedChildren)'})
TabControl.ATTR('getTabHeader', {RET = '@ref(map protectedChildren)'})
TabControl.ATTR('getTabContainer', {RET = '@ref(map protectedChildren)'})
TabControl.ATTR('insertTab', {ARG2 = '@ref(map protectedChildren)', ARG3 = '@ref(map protectedChildren)'})
TabControl.CALLBACK {
    FUNCS = {'void setTabChangedEventListener(@nullable const std::function<void(int tabIndex, EventType)>& callback)'},
    TAG_MAKER = 'olua_makecallbacktag("tabChangedEventListener")',
    TAG_MODE = 'OLUA_TAG_REPLACE',
}

typeconf 'cocos2d::ui::ScrollView::Direction'
typeconf 'cocos2d::ui::ScrollView::EventType'

local ScrollView = typeconf 'cocos2d::ui::ScrollView'
ScrollView.ATTR('getInnerContainer', {RET = '@ref(map protectedChildren)'})
ScrollView.CALLBACK {
    FUNCS = {'void addEventListener(@nullable const std::function<void(Ref*, EventType)>& callback)'},
    TAG_MAKER = 'olua_makecallbacktag("scrollViewCallback")',
    TAG_MODE = 'OLUA_TAG_REPLACE'
}
ScrollView.ALIAS('addEventListener', 'addScrollEventListener')

typeconf 'cocos2d::ui::ListView::Gravity'
typeconf 'cocos2d::ui::ListView::EventType'
typeconf 'cocos2d::ui::ListView::MagneticType'

local ListView = typeconf 'cocos2d::ui::ListView'
ListView.ATTR('pushBackCustomItem', {ARG1 = '@ref(map children)'})
ListView.ATTR('insertCustomItem', {ARG1 = '@ref(map children)'})
ListView.ATTR('removeLastItem', {RET = '@unref(cmp children)'})
ListView.ATTR('removeItem', {RET = '@unref(cmp children)'})
ListView.ATTR('removeAllItems', {RET = '@unref(cmp children)'})
ListView.ATTR('getItem', {RET = '@ref(map children)'})
ListView.ATTR('getItems', {RET = '@ref(map children)'})
ListView.CALLBACK {
    FUNCS = {'void addEventListener(@nullable const std::function<void(Ref*, EventType)>& callback)'},
    TAG_MAKER = 'olua_makecallbacktag("ListViewCallback")',
    TAG_MODE = 'OLUA_TAG_REPLACE',
}
ListView.ALIAS('addEventListener', 'addListViewEventListener')

typeconf 'cocos2d::ui::LoadingBar::Direction'
typeconf 'cocos2d::ui::LoadingBar'
typeconf 'cocos2d::ui::PageView::EventType'
typeconf 'cocos2d::ui::PageView::TouchDirection'

local PageView = typeconf 'cocos2d::ui::PageView'
PageView.ATTR('addPage', {ARG1 = '@ref(map children)'})
PageView.ATTR('insertPage', {ARG1 = '@ref(map children)'})
PageView.ATTR('removePage', {ARG1 = '@unref(map children)'})
PageView.ATTR('removePageAtIndex', {RET = '@unref(cmp children)'})
PageView.ATTR('removeAllPages', {RET = '@unref(all children)'})
PageView.CALLBACK {
    FUNCS = {'void addEventListener(@nullable const std::function<void(Ref*, PageView::EventType)>& callback)'},
    TAG_MAKER = 'olua_makecallbacktag("PageViewCallback")',
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
    FUNCS = {
        'static RichText* createWithXML(const std::string& xml)',
        'static RichText* createWithXML(const std::string& xml, const ValueMap& defaults)',
        'static RichText* createWithXML(const std::string& xml, const ValueMap& defaults, const std::function<void(const std::string& url)>& handleOpenUrl)',
    },
    TAG_MAKER = 'olua_makecallbacktag("openUrlHandler")',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    CPPFUNC = 'initWithXML',
    NEW = [[
        auto *self = new ${DECLTYPE}();
        auto *ret = self;
        self->autorelease();
        olua_push_cppobj<${DECLTYPE}>(L, self);
    ]],
}
RichText.CALLBACK {
    FUNCS = {'void setOpenUrlHandler(const std::function<void(const std::string& url)>& handleOpenUrl)'},
    TAG_MAKER = 'olua_makecallbacktag("openUrlHandler")',
    TAG_MODE = 'OLUA_TAG_REPLACE',
}

typeconf 'cocos2d::ui::ScrollViewBar'
typeconf 'cocos2d::ui::Slider::EventType'

local Slider = typeconf 'cocos2d::ui::Slider'
Slider.ATTR('getSlidBallNormalRenderer', {RET = '@ref(map protectedChildren)'})
Slider.ATTR('getSlidBallPressedRenderer', {RET = '@ref(map protectedChildren)'})
Slider.ATTR('getSlidBallDisabledRenderer', {RET = '@ref(map protectedChildren)'})
Slider.ATTR('getSlidBallRenderer', {RET = '@ref(map protectedChildren)'})
Slider.CALLBACK {
    FUNCS = {'void addEventListener(@nullable const std::function<void(Ref*,EventType)>& callback)'},
    TAG_MAKER = 'olua_makecallbacktag("sliderCallback")',
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
    TAG_MAKER = 'olua_makecallbacktag("textFieldCallback")',
    TAG_MODE = 'OLUA_TAG_REPLACE',
}

local Button = typeconf 'cocos2d::ui::Button'
Button.ATTR('setTitleLabel', {ARG1 = '@ref(map protectedChildren)'})
Button.ATTR('getTitleRenderer', {RET = '@ref(map protectedChildren)'})
Button.ATTR('getTitleLabel', {RET = '@ref(map protectedChildren)'})
Button.ATTR('getRendererNormal', {RET = '@ref(map protectedChildren)'})
Button.ATTR('getRendererClicked', {RET = '@ref(map protectedChildren)'})
Button.ATTR('getRendererDisabled', {RET = '@ref(map protectedChildren)'})

typeconf 'cocos2d::ui::CheckBox::EventType'

local CheckBox = typeconf 'cocos2d::ui::CheckBox'
CheckBox.CALLBACK {
    FUNCS = {'void addEventListener(@nullable const std::function<void(Ref*,CheckBox::EventType)>& callback)'},
    TAG_MAKER = 'olua_makecallbacktag("checkBoxCallback")',
    TAG_MODE = 'OLUA_TAG_REPLACE',
}

typeconf 'cocos2d::ui::RadioButton::EventType'

local RadioButton = typeconf 'cocos2d::ui::RadioButton'
RadioButton.CALLBACK {
    FUNCS = {'void addEventListener(@nullable const std::function<void(RadioButton* radioButton, EventType)>& callback)'},
    TAG_MAKER = 'olua_makecallbacktag("radioButtonCallback")',
    TAG_MODE = 'OLUA_TAG_REPLACE',
}

typeconf 'cocos2d::ui::RadioButtonGroup::EventType'

local RadioButtonGroup = typeconf 'cocos2d::ui::RadioButtonGroup'
RadioButtonGroup.CALLBACK {
    FUNCS = {'void addEventListener(@nullable const std::function<void(RadioButton* radioButton, int index, EventType)>& callback)'},
    TAG_MAKER = 'olua_makecallbacktag("radioButtonCallback")',
    TAG_MODE = 'OLUA_TAG_REPLACE',
}

typeconf 'cocos2d::ui::ImageView'

typeconf 'cocos2d::ui::EditBoxDelegate::EditBoxEndAction'

local EditBoxDelegate = typeconf 'cocos2d::ui::EditBoxDelegate'
EditBoxDelegate.FUNC('__gc', olua.gcfunc(EditBoxDelegate))

local LuaEditBoxDelegate = typeconf 'cocos2d::ui::LuaEditBoxDelegate'
LuaEditBoxDelegate.VAR('onEditingDidBegin', '@nullable std::function<void(EditBox *)> onEditingDidBegin')
LuaEditBoxDelegate.VAR('onTextChanged', '@nullable std::function<void(EditBox *, const std::string &)> onTextChanged')
LuaEditBoxDelegate.VAR('onReturn', '@nullable std::function<void(EditBox *)> onReturn')
LuaEditBoxDelegate.VAR('onEditingDidEndWithAction', '@nullable std::function<void(EditBox *, EditBoxDelegate::EditBoxEndAction)> onEditingDidEndWithAction')

typeconf 'cocos2d::ui::EditBox::KeyboardReturnType'
typeconf 'cocos2d::ui::EditBox::InputMode'
typeconf 'cocos2d::ui::EditBox::InputFlag'

local EditBox = typeconf 'cocos2d::ui::EditBox'
EditBox.EXCLUDE 'registerScriptEditBoxHandler'
EditBox.EXCLUDE 'unregisterScriptEditBoxHandler'
EditBox.EXCLUDE 'getScriptEditBoxHandler'
EditBox.ATTR('setDelegate', {ARG1 = '@ref(single delegate)'})
EditBox.ATTR('getDelegate', {RET = '@ref(single delegate)'})

return M