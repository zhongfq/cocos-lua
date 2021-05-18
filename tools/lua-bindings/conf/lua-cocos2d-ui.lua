module 'cocos2d_ui'

path = '../../frameworks/libxgame/src/lua-bindings'

headers = [[
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "lua-bindings/LuaCocosAdapter.h"
#include "cclua/xlua.h"
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "ui/UIScrollViewBar.h"
]]

make_luacls = function (cppname)
    cppname = string.gsub(cppname, '^cocos2d::ui::', 'ccui.')
    cppname = string.gsub(cppname, "::", ".")
    return cppname
end

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
    .attr('getVirtualRenderer', {ret = '@addref(protectedChildren |)'})
    .attr('findNextFocusedWidget', {arg2 = '@nullable'})
    .attr('onFocusChange', {arg1 = '@nullable', arg2 = '@nullable'})
    .attr('dispatchFocusEvent', {arg1 = '@nullable', arg2 = '@nullable'})
    .callback {name = 'onFocusChanged', localvar = false}
    .callback {name = 'addTouchEventListener', nullable = true, localvar = false}
    .callback {name = 'addClickEventListener', nullable = true, localvar = false}
    .callback {name = 'addCCSEventListener', nullable = true, localvar = false}

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
    .callback {name = 'onPassFocusToChild', nullable = true, localvar = false}

typeconf 'cocos2d::ui::HBox'
typeconf 'cocos2d::ui::VBox'
typeconf 'cocos2d::ui::RelativeBox'

ifdef 'defined(CCLUA_OS_IOS) || defined(CCLUA_OS_ANDROID)'
typeconf 'cocos2d::ui::WebView::ccWebViewCallback'
typeconf 'cocos2d::ui::WebView'
    .callback {name = 'setOnShouldStartLoading', nullable = true, localvar = false}
    .callback {name = 'setOnDidFinishLoading', nullable = true, localvar = false}
    .callback {name = 'setOnDidFailLoading', nullable = true, localvar = false}
    .callback {name = 'setOnJSCallback', nullable = true, localvar = false}
typeconf 'cocos2d::ui::VideoPlayer::EventType'
typeconf 'cocos2d::ui::VideoPlayer::ccVideoPlayerCallback'
typeconf 'cocos2d::ui::VideoPlayer::StyleType'
typeconf 'cocos2d::ui::VideoPlayer'
    .callback {
        name = 'addEventListener',
        tag_maker = 'videoPlayerCallback',
        tag_mode = 'OLUA_TAG_REPLACE',
        localvar = false,
    }
endif ''

typeconf 'cocos2d::ui::AbstractCheckButton'
    .attr('getRendererBackground', {ret = '@addref(protectedChildren |)'})
    .attr('getRendererBackgroundSelected', {ret = '@addref(protectedChildren |)'})
    .attr('getRendererFrontCross', {ret = '@addref(protectedChildren |)'})
    .attr('getRendererBackgroundDisabled', {ret = '@addref(protectedChildren |)'})
    .attr('getRendererFrontCrossDisabled', {ret = '@addref(protectedChildren |)'})

typeconf 'cocos2d::ui::TabHeader::EventType'

typeconf 'cocos2d::ui::TabHeader'
    .attr('getTitleRenderer', {ret = '@addref(protectedChildren |)'})

typeconf 'cocos2d::ui::TabControl::Dock'
typeconf 'cocos2d::ui::TabControl::EventType'
typeconf 'cocos2d::ui::TabControl::ccTabControlCallback'

typeconf 'cocos2d::ui::TabControl'
    .attr('removeTab', {ret = '@delref(protectedChildren ~)'})
    .attr('getTabHeader', {ret = '@addref(protectedChildren |)'})
    .attr('getTabContainer', {ret = '@addref(protectedChildren |)'})
    .attr('insertTab', {arg2 = '@addref(protectedChildren |)', arg3 = '@addref(protectedChildren |)'})
    .callback {
        name = 'setTabChangedEventListener',
        tag_maker = 'tabChangedEventListener',
        tag_mode = 'OLUA_TAG_REPLACE',
        nullable = true,
    }

typeconf 'cocos2d::ui::ScrollView::Direction'
typeconf 'cocos2d::ui::ScrollView::EventType'
typeconf 'cocos2d::ui::ScrollView::ccScrollViewCallback'

typeconf 'cocos2d::ui::ScrollView'
    .attr('getInnerContainer', {ret = '@addref(protectedChildren |)'})
    .callback {
        name = 'addEventListener',
        tag_maker = 'scrollViewCallback',
        tag_mode = 'OLUA_TAG_REPLACE',
        localvar = false,
    }

typeconf 'cocos2d::ui::ListView::Gravity'
typeconf 'cocos2d::ui::ListView::EventType'
typeconf 'cocos2d::ui::ListView::MagneticType'
typeconf 'cocos2d::ui::ListView::ccListViewCallback'

typeconf 'cocos2d::ui::ListView'
    .attr('pushBackCustomItem', {arg1 = '@addref(children |)'})
    .attr('insertCustomItem', {arg1 = '@addref(children |)'})
    .attr('removeLastItem', {ret = '@delref(children ~)'})
    .attr('removeItem', {ret = '@delref(children ~)'})
    .attr('removeAllItems', {ret = '@delref(children ~)'})
    .attr('getItem', {ret = '@addref(children |)'})
    .attr('getItems', {ret = '@addref(children |)'})
    .callback {
        name = 'addEventListener',
        tag_maker = 'ListViewCallback',
        tag_mode = 'OLUA_TAG_REPLACE',
        localvar = false,
    }

typeconf 'cocos2d::ui::LoadingBar::Direction'
typeconf 'cocos2d::ui::LoadingBar'
typeconf 'cocos2d::ui::PageView::EventType'
typeconf 'cocos2d::ui::PageView::TouchDirection'
typeconf 'cocos2d::ui::PageView::ccPageViewCallback'

typeconf 'cocos2d::ui::PageView'
    .attr('addPage', {arg1 = '@addref(children |)'})
    .attr('insertPage', {arg1 = '@addref(children |)'})
    .attr('removePage', {arg1 = '@delref(children |)'})
    .attr('removePageAtIndex', {ret = '@delref(children ~)'})
    .attr('removeAllPages', {ret = '@delref(children *)'})
    .callback {
        name = 'addEventListener',
        tag_maker = 'PageViewCallback',
        tag_mode = 'OLUA_TAG_REPLACE',
        localvar = false,
    }

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
    .callback {
        name = 'createWithXML',
        tag_maker = 'OpenUrlHandler',
        tag_mode = 'OLUA_TAG_REPLACE',
        tag_store = 'return',
    }

typeconf 'cocos2d::ui::ScrollViewBar'
typeconf 'cocos2d::ui::Slider::EventType'
typeconf 'cocos2d::ui::Slider::ccSliderCallback'

typeconf 'cocos2d::ui::Slider'
    .attr('getSlidBallNormalRenderer', {ret = '@addref(protectedChildren |)'})
    .attr('getSlidBallPressedRenderer', {ret = '@addref(protectedChildren |)'})
    .attr('getSlidBallDisabledRenderer', {ret = '@addref(protectedChildren |)'})
    .attr('getSlidBallRenderer', {ret = '@addref(protectedChildren |)'})
    .callback {
        name = 'addEventListener',
        tag_maker = 'sliderCallback',
        tag_mode = 'OLUA_TAG_REPLACE',
        localvar = false,
    }

typeconf 'cocos2d::ui::Text::Type'
typeconf 'cocos2d::ui::Text'
typeconf 'cocos2d::ui::TextAtlas'
typeconf 'cocos2d::ui::TextBMFont'
typeconf 'cocos2d::ui::UICCTextField'
typeconf 'cocos2d::ui::TextField::EventType'
typeconf 'cocos2d::ui::TextField::ccTextFieldCallback'

typeconf 'cocos2d::ui::TextField'
    .callback {
        name = 'addEventListener',
        tag_maker = 'textFieldCallback',
        tag_mode = 'OLUA_TAG_REPLACE',
        localvar = false,
    }

typeconf 'cocos2d::ui::Button'
    .attr('setTitleLabel', {arg1 = '@addref(protectedChildren |)'})
    .attr('getTitleRenderer', {ret = '@addref(protectedChildren |)'})
    .attr('getTitleLabel', {ret = '@addref(protectedChildren |)'})
    .attr('getRendererNormal', {ret = '@addref(protectedChildren |)'})
    .attr('getRendererClicked', {ret = '@addref(protectedChildren |)'})
    .attr('getRendererDisabled', {ret = '@addref(protectedChildren |)'})

typeconf 'cocos2d::ui::CheckBox::EventType'
typeconf 'cocos2d::ui::CheckBox::ccCheckBoxCallback'

typeconf 'cocos2d::ui::CheckBox'
    .callback {
        name ='addEventListener',
        tag_maker = 'checkBoxCallback',
        tag_mode = 'OLUA_TAG_REPLACE',
        localvar = false,
    }

typeconf 'cocos2d::ui::RadioButton::EventType'
typeconf 'cocos2d::ui::RadioButton::ccRadioButtonCallback'

typeconf 'cocos2d::ui::RadioButton'
    .callback {
        name = 'addEventListener',
        tag_maker = 'radioButtonCallback',
        tag_mode = 'OLUA_TAG_REPLACE',
        localvar = false,
    }

typeconf 'cocos2d::ui::RadioButtonGroup::EventType'
typeconf 'cocos2d::ui::RadioButtonGroup::ccRadioButtonGroupCallback'

typeconf 'cocos2d::ui::RadioButtonGroup'
    .callback {
        name = 'addEventListener',
        tag_maker = 'radioButtonCallback',
        tag_mode = 'OLUA_TAG_REPLACE',
        localvar = false,
    }

typeconf 'cocos2d::ui::ImageView'
typeconf 'cocos2d::ui::EditBoxDelegate::EditBoxEndAction'
typeconf 'cocos2d::ui::EditBoxDelegate'
typeconf 'cocos2d::ui::LuaEditBoxDelegate'
typeconf 'cocos2d::ui::EditBox::KeyboardReturnType'
typeconf 'cocos2d::ui::EditBox::InputMode'
typeconf 'cocos2d::ui::EditBox::InputFlag'
typeconf 'cocos2d::ui::EditBox'
    .attr('setDelegate', {arg1 = '@addref(delegate ^)'})
    .attr('getDelegate', {ret = '@addref(delegate ^)'})
