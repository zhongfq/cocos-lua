-- AUTO BUILD, DON'T MODIFY!

dofile "autobuild/cocos2d-ui-types.lua"

local olua = require "olua"
local typeconv = olua.typeconv
local typecls = olua.typecls
local cls = nil
local M = {}

M.NAME = "cocos2d_ui"
M.PATH = "../../frameworks/libxgame/src/lua-bindings"
M.INCLUDES = [[
    #include "lua-bindings/lua_conv.h"
    #include "lua-bindings/lua_conv_manual.h"
    #include "lua-bindings/LuaCocosAdapter.h"
    #include "xgame/xlua.h"
    #include "cocos2d.h"
    #include "ui/CocosGUI.h"
    #include "ui/UIScrollViewBar.h"
]]
M.CHUNK = ''

M.CONVS = {
}

M.CLASSES = {}

cls = typecls 'cocos2d::ui::Widget::FocusDirection'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('LEFT', 'cocos2d::ui::Widget::FocusDirection::LEFT')
cls.enum('RIGHT', 'cocos2d::ui::Widget::FocusDirection::RIGHT')
cls.enum('UP', 'cocos2d::ui::Widget::FocusDirection::UP')
cls.enum('DOWN', 'cocos2d::ui::Widget::FocusDirection::DOWN')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::Widget::PositionType'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('ABSOLUTE', 'cocos2d::ui::Widget::PositionType::ABSOLUTE')
cls.enum('PERCENT', 'cocos2d::ui::Widget::PositionType::PERCENT')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::Widget::SizeType'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('ABSOLUTE', 'cocos2d::ui::Widget::SizeType::ABSOLUTE')
cls.enum('PERCENT', 'cocos2d::ui::Widget::SizeType::PERCENT')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::Widget::TouchEventType'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('BEGAN', 'cocos2d::ui::Widget::TouchEventType::BEGAN')
cls.enum('MOVED', 'cocos2d::ui::Widget::TouchEventType::MOVED')
cls.enum('ENDED', 'cocos2d::ui::Widget::TouchEventType::ENDED')
cls.enum('CANCELED', 'cocos2d::ui::Widget::TouchEventType::CANCELED')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::Widget::TextureResType'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('LOCAL', 'cocos2d::ui::Widget::TextureResType::LOCAL')
cls.enum('PLIST', 'cocos2d::ui::Widget::TextureResType::PLIST')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::Widget::BrightStyle'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('NONE', 'cocos2d::ui::Widget::BrightStyle::NONE')
cls.enum('NORMAL', 'cocos2d::ui::Widget::BrightStyle::NORMAL')
cls.enum('HIGHLIGHT', 'cocos2d::ui::Widget::BrightStyle::HIGHLIGHT')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::Widget'
cls.SUPERCLS = 'cocos2d::ProtectedNode'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'Widget()')
cls.func(nil, 'static cocos2d::ui::Widget *create()')
cls.func(nil, 'void setEnabled(bool enabled)')
cls.func(nil, 'bool isEnabled()')
cls.func(nil, 'void setBright(bool bright)')
cls.func(nil, 'bool isBright()')
cls.func(nil, 'void setTouchEnabled(bool enabled)')
cls.func(nil, 'void setBrightStyle(cocos2d::ui::Widget::BrightStyle style)')
cls.func(nil, 'bool isTouchEnabled()')
cls.func(nil, 'bool isHighlighted()')
cls.func(nil, 'void setHighlighted(bool highlight)')
cls.func(nil, 'float getLeftBoundary()')
cls.func(nil, 'float getBottomBoundary()')
cls.func(nil, 'float getRightBoundary()')
cls.func(nil, 'float getTopBoundary()')
cls.func(nil, 'void setPositionPercent(const cocos2d::Vec2 &percent)')
cls.func(nil, 'const cocos2d::Vec2 &getPositionPercent()')
cls.func(nil, 'void setPositionType(cocos2d::ui::Widget::PositionType type)')
cls.func(nil, 'cocos2d::ui::Widget::PositionType getPositionType()')
cls.func(nil, 'void setFlippedX(bool flippedX)')
cls.func(nil, 'bool isFlippedX()')
cls.func(nil, 'void setFlippedY(bool flippedY)')
cls.func(nil, 'bool isFlippedY()')
cls.func(nil, 'bool isClippingParentContainsPoint(const cocos2d::Vec2 &pt)')
cls.func(nil, 'const cocos2d::Vec2 &getTouchBeganPosition()')
cls.func(nil, 'const cocos2d::Vec2 &getTouchMovePosition()')
cls.func(nil, 'const cocos2d::Vec2 &getTouchEndPosition()')
cls.func(nil, 'void setSizePercent(const cocos2d::Vec2 &percent)')
cls.func(nil, 'void setSizeType(cocos2d::ui::Widget::SizeType type)')
cls.func(nil, 'cocos2d::ui::Widget::SizeType getSizeType()')
cls.func(nil, 'const cocos2d::Size &getCustomSize()')
cls.func(nil, 'const cocos2d::Size &getLayoutSize()')
cls.func(nil, 'const cocos2d::Vec2 &getSizePercent()')
cls.func(nil, 'bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unusedEvent)')
cls.func(nil, 'void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unusedEvent)')
cls.func(nil, 'void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unusedEvent)')
cls.func(nil, 'void onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event *unusedEvent)')
cls.func(nil, 'void setLayoutParameter(cocos2d::ui::LayoutParameter *parameter)')
cls.func(nil, 'cocos2d::ui::LayoutParameter *getLayoutParameter()')
cls.func(nil, 'void ignoreContentAdaptWithSize(bool ignore)')
cls.func(nil, 'bool isIgnoreContentAdaptWithSize()')
cls.func(nil, 'cocos2d::Vec2 getWorldPosition()')
cls.func(nil, '@addref(protectedChildren |) cocos2d::Node *getVirtualRenderer()')
cls.func(nil, 'cocos2d::Size getVirtualRendererSize()')
cls.func(nil, 'cocos2d::ui::Widget *clone()')
cls.func(nil, 'void updateSizeAndPosition()', 'void updateSizeAndPosition(const cocos2d::Size &parentSize)')
cls.func(nil, 'void setActionTag(int tag)')
cls.func(nil, 'int getActionTag()')
cls.func(nil, 'void setPropagateTouchEvents(bool isPropagate)')
cls.func(nil, 'bool isPropagateTouchEvents()')
cls.func(nil, 'void setSwallowTouches(bool swallow)')
cls.func(nil, 'bool isSwallowTouches()')
cls.func(nil, 'bool isFocused()')
cls.func(nil, 'void setFocused(bool focus)')
cls.func(nil, 'bool isFocusEnabled()')
cls.func(nil, 'void setFocusEnabled(bool enable)')
cls.func(nil, 'cocos2d::ui::Widget *findNextFocusedWidget(cocos2d::ui::Widget::FocusDirection direction, cocos2d::ui::Widget *current)')
cls.func(nil, 'void requestFocus()')
cls.func(nil, 'static cocos2d::ui::Widget *getCurrentFocusedWidget()')
cls.func(nil, 'static void enableDpadNavigation(bool enable)')
cls.func(nil, 'void setUnifySizeEnabled(bool enable)')
cls.func(nil, 'bool isUnifySizeEnabled()')
cls.func(nil, 'void setCallbackName(const std::string &callbackName)')
cls.func(nil, 'const std::string &getCallbackName()')
cls.func(nil, 'void setCallbackType(const std::string &callbackType)')
cls.func(nil, 'const std::string &getCallbackType()')
cls.func(nil, 'void setLayoutComponentEnabled(bool enable)')
cls.func(nil, 'bool isLayoutComponentEnabled()')
cls.func(nil, 'void interceptTouchEvent(cocos2d::ui::Widget::TouchEventType event, cocos2d::ui::Widget *sender, cocos2d::Touch *touch)')
cls.func(nil, 'void propagateTouchEvent(cocos2d::ui::Widget::TouchEventType event, cocos2d::ui::Widget *sender, cocos2d::Touch *touch)')
cls.func(nil, 'void onFocusChange(cocos2d::ui::Widget *widgetLostFocus, cocos2d::ui::Widget *widgetGetFocus)')
cls.func(nil, 'void dispatchFocusEvent(cocos2d::ui::Widget *widgetLoseFocus, cocos2d::ui::Widget *widgetGetFocus)')
cls.var('onFocusChanged', '@nullable std::function<void (Widget *, Widget *)> onFocusChanged')
cls.var('onNextFocusedWidget', '@nullable @local std::function<Widget *(FocusDirection)> onNextFocusedWidget')
cls.callback {
    FUNCS =  {
        'void addTouchEventListener(@nullable const std::function<void (Ref *, Widget::TouchEventType)> &callback)'
    },
    TAG_MAKER = 'addTouchEventListener',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        'void addClickEventListener(@nullable const std::function<void (Ref *)> &callback)'
    },
    TAG_MAKER = 'addClickEventListener',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        'void addCCSEventListener(@nullable const std::function<void (Ref *, int)> &callback)'
    },
    TAG_MAKER = 'addCCSEventListener',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.prop('enabled', nil, nil)
cls.prop('bright', nil, nil)
cls.prop('touchEnabled', nil, nil)
cls.prop('highlighted', nil, nil)
cls.prop('leftBoundary', nil, nil)
cls.prop('bottomBoundary', nil, nil)
cls.prop('rightBoundary', nil, nil)
cls.prop('topBoundary', nil, nil)
cls.prop('positionPercent', nil, nil)
cls.prop('positionType', nil, nil)
cls.prop('flippedX', nil, nil)
cls.prop('flippedY', nil, nil)
cls.prop('touchBeganPosition', nil, nil)
cls.prop('touchMovePosition', nil, nil)
cls.prop('touchEndPosition', nil, nil)
cls.prop('sizeType', nil, nil)
cls.prop('customSize', nil, nil)
cls.prop('layoutSize', nil, nil)
cls.prop('sizePercent', nil, nil)
cls.prop('layoutParameter', nil, nil)
cls.prop('ignoreContentAdaptWithSize', nil, nil)
cls.prop('worldPosition', nil, nil)
cls.prop('virtualRenderer', nil, nil)
cls.prop('virtualRendererSize', nil, nil)
cls.prop('actionTag', nil, nil)
cls.prop('propagateTouchEvents', nil, nil)
cls.prop('swallowTouches', nil, nil)
cls.prop('focused', nil, nil)
cls.prop('focusEnabled', nil, nil)
cls.prop('currentFocusedWidget', nil, nil)
cls.prop('unifySizeEnabled', nil, nil)
cls.prop('callbackName', nil, nil)
cls.prop('callbackType', nil, nil)
cls.prop('layoutComponentEnabled', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::Helper'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::ui::Widget *seekWidgetByTag(cocos2d::ui::Widget *root, int tag)')
cls.func(nil, 'static cocos2d::ui::Widget *seekWidgetByName(cocos2d::ui::Widget *root, const std::string &name)')
cls.func(nil, 'static cocos2d::ui::Widget *seekActionWidgetByActionTag(cocos2d::ui::Widget *root, int tag)')
cls.func(nil, 'static std::string getSubStringOfUTF8String(const std::string &str, std::string::size_type start, std::string::size_type length)')
cls.func(nil, 'static void doLayout(cocos2d::Node *rootNode)')
cls.func(nil, 'static void changeLayoutSystemActiveState(bool active)')
cls.func(nil, 'static cocos2d::Rect restrictCapInsetRect(const cocos2d::Rect &capInsets, const cocos2d::Size &textureSize)')
cls.func(nil, 'static cocos2d::Rect convertBoundingBoxToScreen(cocos2d::Node *node)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::Scale9Sprite::State'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('NORMAL', 'cocos2d::ui::Scale9Sprite::State::NORMAL')
cls.enum('GRAY', 'cocos2d::ui::Scale9Sprite::State::GRAY')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::Scale9Sprite::RenderingType'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('SIMPLE', 'cocos2d::ui::Scale9Sprite::RenderingType::SIMPLE')
cls.enum('SLICE', 'cocos2d::ui::Scale9Sprite::RenderingType::SLICE')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::Scale9Sprite'
cls.SUPERCLS = 'cocos2d::Sprite'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'Scale9Sprite()')
cls.func(nil, 'static cocos2d::ui::Scale9Sprite *create()', 'static cocos2d::ui::Scale9Sprite *create(const std::string &file, const cocos2d::Rect &rect, const cocos2d::Rect &capInsets)', 'static cocos2d::ui::Scale9Sprite *create(const cocos2d::Rect &capInsets, const std::string &file)', 'static cocos2d::ui::Scale9Sprite *create(const std::string &file, const cocos2d::Rect &rect)', 'static cocos2d::ui::Scale9Sprite *create(const std::string &file)')
cls.func(nil, 'static cocos2d::ui::Scale9Sprite *createWithSpriteFrame(cocos2d::SpriteFrame *spriteFrame)', 'static cocos2d::ui::Scale9Sprite *createWithSpriteFrame(cocos2d::SpriteFrame *spriteFrame, const cocos2d::Rect &capInsets)')
cls.func(nil, 'static cocos2d::ui::Scale9Sprite *createWithSpriteFrameName(const std::string &spriteFrameName)', 'static cocos2d::ui::Scale9Sprite *createWithSpriteFrameName(const std::string &spriteFrameName, const cocos2d::Rect &capInsets)')
cls.func(nil, 'bool initWithFile(const std::string &file, const cocos2d::Rect &rect, const cocos2d::Rect &capInsets)', 'bool initWithFile(const cocos2d::Rect &capInsets, const std::string &file)')
cls.func(nil, 'bool initWithSpriteFrame(cocos2d::SpriteFrame *spriteFrame, const cocos2d::Rect &capInsets)')
cls.func(nil, 'bool initWithSpriteFrameName(const std::string &spriteFrameName, const cocos2d::Rect &capInsets)')
cls.func(nil, 'bool init(cocos2d::Sprite *sprite, const cocos2d::Rect &rect, bool rotated, const cocos2d::Rect &capInsets)', 'bool init(cocos2d::Sprite *sprite, const cocos2d::Rect &rect, const cocos2d::Rect &capInsets)', 'bool init(cocos2d::Sprite *sprite, const cocos2d::Rect &rect, bool rotated, const cocos2d::Vec2 &offset, const cocos2d::Size &originalSize, const cocos2d::Rect &capInsets)')
cls.func(nil, 'cocos2d::ui::Scale9Sprite *resizableSpriteWithCapInsets(const cocos2d::Rect &capInsets)')
cls.func(nil, 'bool updateWithSprite(cocos2d::Sprite *sprite, const cocos2d::Rect &rect, bool rotated, const cocos2d::Rect &capInsets)', 'bool updateWithSprite(cocos2d::Sprite *sprite, const cocos2d::Rect &rect, bool rotated, const cocos2d::Vec2 &offset, const cocos2d::Size &originalSize, const cocos2d::Rect &capInsets)')
cls.func(nil, 'void setSpriteFrame(cocos2d::SpriteFrame *spriteFrame, const cocos2d::Rect &capInsets)')
cls.func(nil, 'void setState(cocos2d::ui::Scale9Sprite::State state)')
cls.func(nil, 'cocos2d::ui::Scale9Sprite::State getState()')
cls.func(nil, 'cocos2d::Size getOriginalSize()')
cls.func(nil, 'void setPreferredSize(const cocos2d::Size &size)')
cls.func(nil, 'cocos2d::Size getPreferredSize()')
cls.func(nil, 'void setInsetLeft(float leftInset)')
cls.func(nil, 'float getInsetLeft()')
cls.func(nil, 'void setInsetTop(float topInset)')
cls.func(nil, 'float getInsetTop()')
cls.func(nil, 'void setInsetRight(float rightInset)')
cls.func(nil, 'float getInsetRight()')
cls.func(nil, 'void setInsetBottom(float bottomInset)')
cls.func(nil, 'float getInsetBottom()')
cls.func(nil, 'void setScale9Enabled(bool enabled)')
cls.func(nil, 'bool isScale9Enabled()')
cls.func(nil, 'cocos2d::Sprite *getSprite()')
cls.func(nil, 'void copyTo(cocos2d::ui::Scale9Sprite *copy)')
cls.func(nil, 'void setRenderingType(cocos2d::ui::Scale9Sprite::RenderingType type)')
cls.func(nil, 'cocos2d::ui::Scale9Sprite::RenderingType getRenderingType()')
cls.func(nil, 'void setCapInsets(const cocos2d::Rect &insets)')
cls.func(nil, 'cocos2d::Rect getCapInsets()')
cls.func(nil, 'void resetRender()')
cls.prop('state', nil, nil)
cls.prop('originalSize', nil, nil)
cls.prop('preferredSize', nil, nil)
cls.prop('insetLeft', nil, nil)
cls.prop('insetTop', nil, nil)
cls.prop('insetRight', nil, nil)
cls.prop('insetBottom', nil, nil)
cls.prop('scale9Enabled', nil, nil)
cls.prop('sprite', nil, nil)
cls.prop('renderingType', nil, nil)
cls.prop('capInsets', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::LayoutComponent::HorizontalEdge'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('None', 'cocos2d::ui::LayoutComponent::HorizontalEdge::None')
cls.enum('Left', 'cocos2d::ui::LayoutComponent::HorizontalEdge::Left')
cls.enum('Right', 'cocos2d::ui::LayoutComponent::HorizontalEdge::Right')
cls.enum('Center', 'cocos2d::ui::LayoutComponent::HorizontalEdge::Center')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::LayoutComponent::VerticalEdge'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('None', 'cocos2d::ui::LayoutComponent::VerticalEdge::None')
cls.enum('Bottom', 'cocos2d::ui::LayoutComponent::VerticalEdge::Bottom')
cls.enum('Top', 'cocos2d::ui::LayoutComponent::VerticalEdge::Top')
cls.enum('Center', 'cocos2d::ui::LayoutComponent::VerticalEdge::Center')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::LayoutComponent'
cls.SUPERCLS = 'cocos2d::Component'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'LayoutComponent()')
cls.func(nil, 'static cocos2d::ui::LayoutComponent *create()')
cls.func(nil, 'static cocos2d::ui::LayoutComponent *bindLayoutComponent(cocos2d::Node *node)')
cls.func(nil, 'void setUsingPercentContentSize(bool isUsed)')
cls.func(nil, 'bool getUsingPercentContentSize()')
cls.func(nil, 'void setPercentContentSize(const cocos2d::Vec2 &percent)')
cls.func(nil, 'cocos2d::Vec2 getPercentContentSize()')
cls.func(nil, 'const cocos2d::Point &getAnchorPosition()')
cls.func(nil, 'void setAnchorPosition(const cocos2d::Point &point)')
cls.func(nil, 'const cocos2d::Point &getPosition()')
cls.func(nil, 'void setPosition(const cocos2d::Point &position)')
cls.func(nil, 'bool isPositionPercentXEnabled()')
cls.func(nil, 'void setPositionPercentXEnabled(bool isUsed)')
cls.func(nil, 'float getPositionPercentX()')
cls.func(nil, 'void setPositionPercentX(float percentMargin)')
cls.func(nil, 'bool isPositionPercentYEnabled()')
cls.func(nil, 'void setPositionPercentYEnabled(bool isUsed)')
cls.func(nil, 'float getPositionPercentY()')
cls.func(nil, 'void setPositionPercentY(float percentMargin)')
cls.func(nil, 'cocos2d::ui::LayoutComponent::HorizontalEdge getHorizontalEdge()')
cls.func(nil, 'void setHorizontalEdge(cocos2d::ui::LayoutComponent::HorizontalEdge hEage)')
cls.func(nil, 'cocos2d::ui::LayoutComponent::VerticalEdge getVerticalEdge()')
cls.func(nil, 'void setVerticalEdge(cocos2d::ui::LayoutComponent::VerticalEdge vEage)')
cls.func(nil, 'float getLeftMargin()')
cls.func(nil, 'void setLeftMargin(float margin)')
cls.func(nil, 'float getRightMargin()')
cls.func(nil, 'void setRightMargin(float margin)')
cls.func(nil, 'float getTopMargin()')
cls.func(nil, 'void setTopMargin(float margin)')
cls.func(nil, 'float getBottomMargin()')
cls.func(nil, 'void setBottomMargin(float margin)')
cls.func(nil, 'const cocos2d::Size &getSize()')
cls.func(nil, 'void setSize(const cocos2d::Size &size)')
cls.func(nil, 'bool isPercentWidthEnabled()')
cls.func(nil, 'void setPercentWidthEnabled(bool isUsed)')
cls.func(nil, 'float getSizeWidth()')
cls.func(nil, 'void setSizeWidth(float width)')
cls.func(nil, 'float getPercentWidth()')
cls.func(nil, 'void setPercentWidth(float percentWidth)')
cls.func(nil, 'bool isPercentHeightEnabled()')
cls.func(nil, 'void setPercentHeightEnabled(bool isUsed)')
cls.func(nil, 'float getSizeHeight()')
cls.func(nil, 'void setSizeHeight(float height)')
cls.func(nil, 'float getPercentHeight()')
cls.func(nil, 'void setPercentHeight(float percentHeight)')
cls.func(nil, 'bool isStretchWidthEnabled()')
cls.func(nil, 'void setStretchWidthEnabled(bool isUsed)')
cls.func(nil, 'bool isStretchHeightEnabled()')
cls.func(nil, 'void setStretchHeightEnabled(bool isUsed)')
cls.func(nil, 'void setPercentOnlyEnabled(bool enable)')
cls.func(nil, 'void setActiveEnabled(bool enable)')
cls.func(nil, 'void refreshLayout()')
cls.prop('usingPercentContentSize', nil, nil)
cls.prop('percentContentSize', nil, nil)
cls.prop('anchorPosition', nil, nil)
cls.prop('position', nil, nil)
cls.prop('positionPercentXEnabled', nil, nil)
cls.prop('positionPercentX', nil, nil)
cls.prop('positionPercentYEnabled', nil, nil)
cls.prop('positionPercentY', nil, nil)
cls.prop('horizontalEdge', nil, nil)
cls.prop('verticalEdge', nil, nil)
cls.prop('leftMargin', nil, nil)
cls.prop('rightMargin', nil, nil)
cls.prop('topMargin', nil, nil)
cls.prop('bottomMargin', nil, nil)
cls.prop('size', nil, nil)
cls.prop('percentWidthEnabled', nil, nil)
cls.prop('sizeWidth', nil, nil)
cls.prop('percentWidth', nil, nil)
cls.prop('percentHeightEnabled', nil, nil)
cls.prop('sizeHeight', nil, nil)
cls.prop('percentHeight', nil, nil)
cls.prop('stretchWidthEnabled', nil, nil)
cls.prop('stretchHeightEnabled', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::LayoutParameter::Type'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('NONE', 'cocos2d::ui::LayoutParameter::Type::NONE')
cls.enum('LINEAR', 'cocos2d::ui::LayoutParameter::Type::LINEAR')
cls.enum('RELATIVE', 'cocos2d::ui::LayoutParameter::Type::RELATIVE')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::LayoutParameter'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'LayoutParameter()')
cls.func(nil, 'static cocos2d::ui::LayoutParameter *create()')
cls.func(nil, 'void setMargin(const cocos2d::ui::Margin &margin)')
cls.func(nil, 'const cocos2d::ui::Margin &getMargin()')
cls.func(nil, 'cocos2d::ui::LayoutParameter::Type getLayoutType()')
cls.func(nil, 'cocos2d::ui::LayoutParameter *clone()')
cls.func(nil, 'cocos2d::ui::LayoutParameter *createCloneInstance()')
cls.func(nil, 'void copyProperties(cocos2d::ui::LayoutParameter *model)')
cls.prop('margin', nil, nil)
cls.prop('layoutType', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::LinearLayoutParameter::LinearGravity'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('NONE', 'cocos2d::ui::LinearLayoutParameter::LinearGravity::NONE')
cls.enum('LEFT', 'cocos2d::ui::LinearLayoutParameter::LinearGravity::LEFT')
cls.enum('TOP', 'cocos2d::ui::LinearLayoutParameter::LinearGravity::TOP')
cls.enum('RIGHT', 'cocos2d::ui::LinearLayoutParameter::LinearGravity::RIGHT')
cls.enum('BOTTOM', 'cocos2d::ui::LinearLayoutParameter::LinearGravity::BOTTOM')
cls.enum('CENTER_VERTICAL', 'cocos2d::ui::LinearLayoutParameter::LinearGravity::CENTER_VERTICAL')
cls.enum('CENTER_HORIZONTAL', 'cocos2d::ui::LinearLayoutParameter::LinearGravity::CENTER_HORIZONTAL')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::LinearLayoutParameter'
cls.SUPERCLS = 'cocos2d::ui::LayoutParameter'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'LinearLayoutParameter()')
cls.func(nil, 'static cocos2d::ui::LinearLayoutParameter *create()')
cls.func(nil, 'void setGravity(cocos2d::ui::LinearLayoutParameter::LinearGravity gravity)')
cls.func(nil, 'cocos2d::ui::LinearLayoutParameter::LinearGravity getGravity()')
cls.prop('gravity', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::RelativeLayoutParameter::RelativeAlign'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('NONE', 'cocos2d::ui::RelativeLayoutParameter::RelativeAlign::NONE')
cls.enum('PARENT_TOP_LEFT', 'cocos2d::ui::RelativeLayoutParameter::RelativeAlign::PARENT_TOP_LEFT')
cls.enum('PARENT_TOP_CENTER_HORIZONTAL', 'cocos2d::ui::RelativeLayoutParameter::RelativeAlign::PARENT_TOP_CENTER_HORIZONTAL')
cls.enum('PARENT_TOP_RIGHT', 'cocos2d::ui::RelativeLayoutParameter::RelativeAlign::PARENT_TOP_RIGHT')
cls.enum('PARENT_LEFT_CENTER_VERTICAL', 'cocos2d::ui::RelativeLayoutParameter::RelativeAlign::PARENT_LEFT_CENTER_VERTICAL')
cls.enum('CENTER_IN_PARENT', 'cocos2d::ui::RelativeLayoutParameter::RelativeAlign::CENTER_IN_PARENT')
cls.enum('PARENT_RIGHT_CENTER_VERTICAL', 'cocos2d::ui::RelativeLayoutParameter::RelativeAlign::PARENT_RIGHT_CENTER_VERTICAL')
cls.enum('PARENT_LEFT_BOTTOM', 'cocos2d::ui::RelativeLayoutParameter::RelativeAlign::PARENT_LEFT_BOTTOM')
cls.enum('PARENT_BOTTOM_CENTER_HORIZONTAL', 'cocos2d::ui::RelativeLayoutParameter::RelativeAlign::PARENT_BOTTOM_CENTER_HORIZONTAL')
cls.enum('PARENT_RIGHT_BOTTOM', 'cocos2d::ui::RelativeLayoutParameter::RelativeAlign::PARENT_RIGHT_BOTTOM')
cls.enum('LOCATION_ABOVE_LEFTALIGN', 'cocos2d::ui::RelativeLayoutParameter::RelativeAlign::LOCATION_ABOVE_LEFTALIGN')
cls.enum('LOCATION_ABOVE_CENTER', 'cocos2d::ui::RelativeLayoutParameter::RelativeAlign::LOCATION_ABOVE_CENTER')
cls.enum('LOCATION_ABOVE_RIGHTALIGN', 'cocos2d::ui::RelativeLayoutParameter::RelativeAlign::LOCATION_ABOVE_RIGHTALIGN')
cls.enum('LOCATION_LEFT_OF_TOPALIGN', 'cocos2d::ui::RelativeLayoutParameter::RelativeAlign::LOCATION_LEFT_OF_TOPALIGN')
cls.enum('LOCATION_LEFT_OF_CENTER', 'cocos2d::ui::RelativeLayoutParameter::RelativeAlign::LOCATION_LEFT_OF_CENTER')
cls.enum('LOCATION_LEFT_OF_BOTTOMALIGN', 'cocos2d::ui::RelativeLayoutParameter::RelativeAlign::LOCATION_LEFT_OF_BOTTOMALIGN')
cls.enum('LOCATION_RIGHT_OF_TOPALIGN', 'cocos2d::ui::RelativeLayoutParameter::RelativeAlign::LOCATION_RIGHT_OF_TOPALIGN')
cls.enum('LOCATION_RIGHT_OF_CENTER', 'cocos2d::ui::RelativeLayoutParameter::RelativeAlign::LOCATION_RIGHT_OF_CENTER')
cls.enum('LOCATION_RIGHT_OF_BOTTOMALIGN', 'cocos2d::ui::RelativeLayoutParameter::RelativeAlign::LOCATION_RIGHT_OF_BOTTOMALIGN')
cls.enum('LOCATION_BELOW_LEFTALIGN', 'cocos2d::ui::RelativeLayoutParameter::RelativeAlign::LOCATION_BELOW_LEFTALIGN')
cls.enum('LOCATION_BELOW_CENTER', 'cocos2d::ui::RelativeLayoutParameter::RelativeAlign::LOCATION_BELOW_CENTER')
cls.enum('LOCATION_BELOW_RIGHTALIGN', 'cocos2d::ui::RelativeLayoutParameter::RelativeAlign::LOCATION_BELOW_RIGHTALIGN')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::RelativeLayoutParameter'
cls.SUPERCLS = 'cocos2d::ui::LayoutParameter'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'RelativeLayoutParameter()')
cls.func(nil, 'static cocos2d::ui::RelativeLayoutParameter *create()')
cls.func(nil, 'void setAlign(cocos2d::ui::RelativeLayoutParameter::RelativeAlign align)')
cls.func(nil, 'cocos2d::ui::RelativeLayoutParameter::RelativeAlign getAlign()')
cls.func(nil, 'void setRelativeToWidgetName(const std::string &name)')
cls.func(nil, 'const std::string &getRelativeToWidgetName()')
cls.func(nil, 'void setRelativeName(const std::string &name)')
cls.func(nil, 'const std::string &getRelativeName()')
cls.prop('align', nil, nil)
cls.prop('relativeToWidgetName', nil, nil)
cls.prop('relativeName', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::Layout::Type'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('ABSOLUTE', 'cocos2d::ui::Layout::Type::ABSOLUTE')
cls.enum('VERTICAL', 'cocos2d::ui::Layout::Type::VERTICAL')
cls.enum('HORIZONTAL', 'cocos2d::ui::Layout::Type::HORIZONTAL')
cls.enum('RELATIVE', 'cocos2d::ui::Layout::Type::RELATIVE')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::Layout::ClippingType'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('STENCIL', 'cocos2d::ui::Layout::ClippingType::STENCIL')
cls.enum('SCISSOR', 'cocos2d::ui::Layout::ClippingType::SCISSOR')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::Layout::BackGroundColorType'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('NONE', 'cocos2d::ui::Layout::BackGroundColorType::NONE')
cls.enum('SOLID', 'cocos2d::ui::Layout::BackGroundColorType::SOLID')
cls.enum('GRADIENT', 'cocos2d::ui::Layout::BackGroundColorType::GRADIENT')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::Layout'
cls.SUPERCLS = 'cocos2d::ui::Widget'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::Ref *createInstance()')
cls.func(nil, 'Layout()')
cls.func(nil, 'static cocos2d::ui::Layout *create()')
cls.func(nil, 'void setBackGroundImage(const std::string &fileName, @optional cocos2d::ui::Widget::TextureResType texType)')
cls.func(nil, 'void setBackGroundImageCapInsets(const cocos2d::Rect &capInsets)')
cls.func(nil, 'const cocos2d::Rect &getBackGroundImageCapInsets()')
cls.func(nil, 'void setBackGroundColorType(cocos2d::ui::Layout::BackGroundColorType type)')
cls.func(nil, 'cocos2d::ui::Layout::BackGroundColorType getBackGroundColorType()')
cls.func(nil, 'void setBackGroundImageScale9Enabled(bool enabled)')
cls.func(nil, 'bool isBackGroundImageScale9Enabled()')
cls.func(nil, 'void setBackGroundColor(const cocos2d::Color3B &color)', 'void setBackGroundColor(const cocos2d::Color3B &startColor, const cocos2d::Color3B &endColor)')
cls.func(nil, 'const cocos2d::Color3B &getBackGroundColor()')
cls.func(nil, 'const cocos2d::Color3B &getBackGroundStartColor()')
cls.func(nil, 'const cocos2d::Color3B &getBackGroundEndColor()')
cls.func(nil, 'void setBackGroundColorOpacity(uint8_t opacity)')
cls.func(nil, 'uint8_t getBackGroundColorOpacity()')
cls.func(nil, 'void setBackGroundColorVector(const cocos2d::Vec2 &vector)')
cls.func(nil, 'const cocos2d::Vec2 &getBackGroundColorVector()')
cls.func(nil, 'void setBackGroundImageColor(const cocos2d::Color3B &color)')
cls.func(nil, 'void setBackGroundImageOpacity(uint8_t opacity)')
cls.func(nil, 'const cocos2d::Color3B &getBackGroundImageColor()')
cls.func(nil, 'uint8_t getBackGroundImageOpacity()')
cls.func(nil, 'void removeBackGroundImage()')
cls.func(nil, 'const cocos2d::Size &getBackGroundImageTextureSize()')
cls.func(nil, 'void setClippingEnabled(bool enabled)')
cls.func(nil, 'void setClippingType(cocos2d::ui::Layout::ClippingType type)')
cls.func(nil, 'cocos2d::ui::Layout::ClippingType getClippingType()')
cls.func(nil, 'bool isClippingEnabled()')
cls.func(nil, 'void setLayoutType(cocos2d::ui::Layout::Type type)')
cls.func(nil, 'cocos2d::ui::Layout::Type getLayoutType()')
cls.func(nil, 'void forceDoLayout()')
cls.func(nil, 'void requestDoLayout()')
cls.func(nil, 'void setLoopFocus(bool loop)')
cls.func(nil, 'bool isLoopFocus()')
cls.func(nil, 'void setPassFocusToChild(bool pass)')
cls.func(nil, 'bool isPassFocusToChild()')
cls.func(nil, 'cocos2d::ResourceData getRenderFile()')
cls.var('onPassFocusToChild', '@nullable std::function<int (FocusDirection, Widget *)> onPassFocusToChild')
cls.prop('backGroundImageCapInsets', nil, nil)
cls.prop('backGroundColorType', nil, nil)
cls.prop('backGroundImageScale9Enabled', nil, nil)
cls.prop('backGroundColor', nil, nil)
cls.prop('backGroundStartColor', nil, nil)
cls.prop('backGroundEndColor', nil, nil)
cls.prop('backGroundColorOpacity', nil, nil)
cls.prop('backGroundColorVector', nil, nil)
cls.prop('backGroundImageColor', nil, nil)
cls.prop('backGroundImageOpacity', nil, nil)
cls.prop('backGroundImageTextureSize', nil, nil)
cls.prop('clippingType', nil, nil)
cls.prop('clippingEnabled', nil, nil)
cls.prop('layoutType', nil, nil)
cls.prop('loopFocus', nil, nil)
cls.prop('passFocusToChild', nil, nil)
cls.prop('renderFile', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::HBox'
cls.SUPERCLS = 'cocos2d::ui::Layout'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'HBox()')
cls.func(nil, 'static cocos2d::ui::HBox *create()', 'static cocos2d::ui::HBox *create(const cocos2d::Size &size)')
cls.func(nil, 'bool initWithSize(const cocos2d::Size &size)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::VBox'
cls.SUPERCLS = 'cocos2d::ui::Layout'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'VBox()')
cls.func(nil, 'static cocos2d::ui::VBox *create()', 'static cocos2d::ui::VBox *create(const cocos2d::Size &size)')
cls.func(nil, 'bool initWithSize(const cocos2d::Size &size)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::RelativeBox'
cls.SUPERCLS = 'cocos2d::ui::Layout'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'RelativeBox()')
cls.func(nil, 'static cocos2d::ui::RelativeBox *create()', 'static cocos2d::ui::RelativeBox *create(const cocos2d::Size &size)')
cls.func(nil, 'bool initWithSize(const cocos2d::Size &size)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::WebView'
cls.SUPERCLS = 'cocos2d::ui::Widget'
cls.REG_LUATYPE = true
cls.DEFIF = '#ifdef CCLUA_HAVE_WEBVIEW'
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::ui::WebView *create()')
cls.func(nil, 'void setJavascriptInterfaceScheme(const std::string &scheme)')
cls.func(nil, 'void loadData(const cocos2d::Data &data, const std::string &MIMEType, const std::string &encoding, const std::string &baseURL)')
cls.func(nil, 'void loadHTMLString(const std::string &string, @optional const std::string &baseURL)')
cls.func(nil, 'void loadURL(const std::string &url)', 'void loadURL(const std::string &url, bool cleanCachedData)')
cls.func(nil, 'void loadFile(const std::string &fileName)')
cls.func(nil, 'void stopLoading()')
cls.func(nil, 'void reload()')
cls.func(nil, 'bool canGoBack()')
cls.func(nil, 'bool canGoForward()')
cls.func(nil, 'void goBack()')
cls.func(nil, 'void goForward()')
cls.func(nil, 'void evaluateJS(const std::string &js)')
cls.func(nil, 'void setScalesPageToFit(const bool scalesPageToFit)')
cls.func(nil, 'void setBounces(bool bounce)')
cls.func(nil, 'void setOpacityWebView(float opacity)')
cls.func(nil, 'float getOpacityWebView()')
cls.func(nil, 'void setBackgroundTransparent()')
cls.func(nil, 'WebView()')
cls.callback {
    FUNCS =  {
        'void setOnShouldStartLoading(@nullable const std::function<bool (WebView *, const std::string &)> &callback)'
    },
    TAG_MAKER = 'OnShouldStartLoading',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        'void setOnDidFinishLoading(@nullable const std::function<void (WebView *, const std::string &)> &callback)'
    },
    TAG_MAKER = 'OnDidFinishLoading',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        'void setOnDidFailLoading(@nullable const std::function<void (WebView *, const std::string &)> &callback)'
    },
    TAG_MAKER = 'OnDidFailLoading',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        'void setOnJSCallback(@nullable const std::function<void (WebView *, const std::string &)> &callback)'
    },
    TAG_MAKER = 'OnJSCallback',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        '@local std::function<bool (WebView *, const std::string &)> getOnShouldStartLoading()'
    },
    TAG_MAKER = 'OnShouldStartLoading',
    TAG_MODE = 'OLUA_TAG_SUBEQUAL',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        '@local std::function<void (WebView *, const std::string &)> getOnDidFinishLoading()'
    },
    TAG_MAKER = 'OnDidFinishLoading',
    TAG_MODE = 'OLUA_TAG_SUBEQUAL',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        '@local std::function<void (WebView *, const std::string &)> getOnDidFailLoading()'
    },
    TAG_MAKER = 'OnDidFailLoading',
    TAG_MODE = 'OLUA_TAG_SUBEQUAL',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        '@local std::function<void (WebView *, const std::string &)> getOnJSCallback()'
    },
    TAG_MAKER = 'OnJSCallback',
    TAG_MODE = 'OLUA_TAG_SUBEQUAL',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.prop('onShouldStartLoading', nil, nil)
cls.prop('onDidFinishLoading', nil, nil)
cls.prop('onDidFailLoading', nil, nil)
cls.prop('onJSCallback', nil, nil)
cls.prop('opacityWebView', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::VideoPlayer::EventType'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = '#ifdef CCLUA_HAVE_VIDEOPLAYER'
cls.CHUNK = nil
cls.enum('PLAYING', 'cocos2d::ui::VideoPlayer::EventType::PLAYING')
cls.enum('PAUSED', 'cocos2d::ui::VideoPlayer::EventType::PAUSED')
cls.enum('STOPPED', 'cocos2d::ui::VideoPlayer::EventType::STOPPED')
cls.enum('COMPLETED', 'cocos2d::ui::VideoPlayer::EventType::COMPLETED')
cls.enum('ERROR', 'cocos2d::ui::VideoPlayer::EventType::ERROR')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::VideoPlayer::StyleType'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = '#ifdef CCLUA_HAVE_VIDEOPLAYER'
cls.CHUNK = nil
cls.enum('DEFAULT', 'cocos2d::ui::VideoPlayer::StyleType::DEFAULT')
cls.enum('NONE', 'cocos2d::ui::VideoPlayer::StyleType::NONE')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::VideoPlayer'
cls.SUPERCLS = 'cocos2d::ui::Widget'
cls.REG_LUATYPE = true
cls.DEFIF = '#ifdef CCLUA_HAVE_VIDEOPLAYER'
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::ui::VideoPlayer *create()')
cls.func(nil, 'void setFileName(const std::string &videoPath)')
cls.func(nil, 'const std::string &getFileName()')
cls.func(nil, 'void setURL(const std::string &_videoURL)')
cls.func(nil, 'const std::string &getURL()')
cls.func(nil, 'void setLooping(bool looping)')
cls.func(nil, 'void setUserInputEnabled(bool enableInput)')
cls.func(nil, 'void setStyle(cocos2d::ui::VideoPlayer::StyleType style)')
cls.func(nil, 'void play()')
cls.func(nil, 'void stop()')
cls.func(nil, 'void seekTo(float sec)')
cls.func(nil, 'bool isPlaying()')
cls.func(nil, 'bool isLooping()')
cls.func(nil, 'bool isUserInputEnabled()')
cls.func(nil, 'void setKeepAspectRatioEnabled(bool enable)')
cls.func(nil, 'bool isKeepAspectRatioEnabled()')
cls.func(nil, 'void setFullScreenEnabled(bool fullscreen)')
cls.func(nil, 'bool isFullScreenEnabled()')
cls.func(nil, 'void onPlayEvent(int event)')
cls.func(nil, 'VideoPlayer()')
cls.callback {
    FUNCS =  {
        'void addEventListener(@nullable const std::function<void (Ref *, VideoPlayer::EventType)> &callback)'
    },
    TAG_MAKER = 'videoPlayerCallback',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.prop('fileName', nil, nil)
cls.prop('url', nil, nil)
cls.prop('playing', nil, nil)
cls.prop('looping', nil, nil)
cls.prop('userInputEnabled', nil, nil)
cls.prop('keepAspectRatioEnabled', nil, nil)
cls.prop('fullScreenEnabled', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::AbstractCheckButton'
cls.SUPERCLS = 'cocos2d::ui::Widget'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'void loadTextures(const std::string &background, const std::string &backgroundSelected, const std::string &cross, const std::string &backgroundDisabled, const std::string &frontCrossDisabled, @optional cocos2d::ui::Widget::TextureResType texType)')
cls.func(nil, 'void loadTextureBackGround(const std::string &backGround, @optional cocos2d::ui::Widget::TextureResType type)')
cls.func(nil, 'void loadTextureBackGroundSelected(const std::string &backGroundSelected, @optional cocos2d::ui::Widget::TextureResType texType)')
cls.func(nil, 'void loadTextureFrontCross(const std::string &crossTextureName, @optional cocos2d::ui::Widget::TextureResType texType)')
cls.func(nil, 'void loadTextureBackGroundDisabled(const std::string &backGroundDisabled, @optional cocos2d::ui::Widget::TextureResType texType)')
cls.func(nil, 'void loadTextureFrontCrossDisabled(const std::string &frontCrossDisabled, @optional cocos2d::ui::Widget::TextureResType texType)')
cls.func(nil, 'bool isSelected()')
cls.func(nil, 'void setSelected(bool selected)')
cls.func(nil, 'void setZoomScale(float scale)')
cls.func(nil, 'float getZoomScale()')
cls.func(nil, '@addref(protectedChildren |) cocos2d::Sprite *getRendererBackground()')
cls.func(nil, '@addref(protectedChildren |) cocos2d::Sprite *getRendererBackgroundSelected()')
cls.func(nil, '@addref(protectedChildren |) cocos2d::Sprite *getRendererFrontCross()')
cls.func(nil, '@addref(protectedChildren |) cocos2d::Sprite *getRendererBackgroundDisabled()')
cls.func(nil, '@addref(protectedChildren |) cocos2d::Sprite *getRendererFrontCrossDisabled()')
cls.func(nil, 'cocos2d::ResourceData getBackNormalFile()')
cls.func(nil, 'cocos2d::ResourceData getBackPressedFile()')
cls.func(nil, 'cocos2d::ResourceData getBackDisabledFile()')
cls.func(nil, 'cocos2d::ResourceData getCrossNormalFile()')
cls.func(nil, 'cocos2d::ResourceData getCrossDisabledFile()')
cls.func(nil, 'bool init(const std::string &backGround, const std::string &backGroundSelected, const std::string &cross, const std::string &backGroundDisabled, const std::string &frontCrossDisabled, @optional cocos2d::ui::Widget::TextureResType texType)')
cls.prop('selected', nil, nil)
cls.prop('zoomScale', nil, nil)
cls.prop('rendererBackground', nil, nil)
cls.prop('rendererBackgroundSelected', nil, nil)
cls.prop('rendererFrontCross', nil, nil)
cls.prop('rendererBackgroundDisabled', nil, nil)
cls.prop('rendererFrontCrossDisabled', nil, nil)
cls.prop('backNormalFile', nil, nil)
cls.prop('backPressedFile', nil, nil)
cls.prop('backDisabledFile', nil, nil)
cls.prop('crossNormalFile', nil, nil)
cls.prop('crossDisabledFile', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::TabHeader::EventType'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('SELECTED', 'cocos2d::ui::TabHeader::EventType::SELECTED')
cls.enum('UNSELECTED', 'cocos2d::ui::TabHeader::EventType::UNSELECTED')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::TabHeader'
cls.SUPERCLS = 'cocos2d::ui::AbstractCheckButton'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::ui::TabHeader *create()', 'static cocos2d::ui::TabHeader *create(const std::string &titleStr, const std::string &backGround, const std::string &cross, @optional cocos2d::ui::Widget::TextureResType texType)', 'static cocos2d::ui::TabHeader *create(const std::string &titleStr, const std::string &backGround, const std::string &backGroundSelected, const std::string &cross, const std::string &backGroundDisabled, const std::string &frontCrossDisabled, @optional cocos2d::ui::Widget::TextureResType texType)')
cls.func(nil, '@addref(protectedChildren |) cocos2d::Label *getTitleRenderer()')
cls.func(nil, 'void setTitleText(const std::string &text)')
cls.func(nil, 'std::string getTitleText()')
cls.func(nil, 'void setTitleColor(const cocos2d::Color4B &color)')
cls.func(nil, 'const cocos2d::Color4B &getTitleColor()')
cls.func(nil, 'void setTitleFontSize(float size)')
cls.func(nil, 'float getTitleFontSize()')
cls.func(nil, 'void setTitleFontName(const std::string &fontName)')
cls.func(nil, 'std::string getTitleFontName()')
cls.func(nil, 'int getIndexInTabControl()')
cls.prop('titleRenderer', nil, nil)
cls.prop('titleText', nil, nil)
cls.prop('titleColor', nil, nil)
cls.prop('titleFontSize', nil, nil)
cls.prop('titleFontName', nil, nil)
cls.prop('indexInTabControl', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::TabControl::Dock'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('TOP', 'cocos2d::ui::TabControl::Dock::TOP')
cls.enum('LEFT', 'cocos2d::ui::TabControl::Dock::LEFT')
cls.enum('BOTTOM', 'cocos2d::ui::TabControl::Dock::BOTTOM')
cls.enum('RIGHT', 'cocos2d::ui::TabControl::Dock::RIGHT')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::TabControl::EventType'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('SELECT_CHANGED', 'cocos2d::ui::TabControl::EventType::SELECT_CHANGED')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::TabControl'
cls.SUPERCLS = 'cocos2d::ui::Widget'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::ui::TabControl *create()')
cls.func(nil, '@delref(protectedChildren ~) void removeTab(int index)')
cls.func(nil, 'void setSelectTab(int index)', 'void setSelectTab(cocos2d::ui::TabHeader *tabHeader)')
cls.func(nil, '@addref(protectedChildren |) cocos2d::ui::TabHeader *getTabHeader(int index)')
cls.func(nil, '@addref(protectedChildren |) cocos2d::ui::Layout *getTabContainer(int index)')
cls.func(nil, 'void insertTab(int index, @addref(protectedChildren |) cocos2d::ui::TabHeader *header, @addref(protectedChildren |) cocos2d::ui::Layout *container)')
cls.func(nil, 'size_t getTabCount()')
cls.func(nil, 'int getSelectedTabIndex()')
cls.func(nil, 'int indexOfTabHeader(const cocos2d::ui::TabHeader *tabCell)')
cls.func(nil, 'void setHeaderWidth(float headerWidth)')
cls.func(nil, 'float getHeaderWidth()')
cls.func(nil, 'void setHeaderHeight(float headerHeight)')
cls.func(nil, 'int getHeaderHeight()')
cls.func(nil, 'void ignoreHeadersTextureSize(bool ignore)')
cls.func(nil, 'bool isIgnoreHeadersTextureSize()')
cls.func(nil, 'void setHeaderSelectedZoom(float zoom)')
cls.func(nil, 'float getHeaderSelectedZoom()')
cls.func(nil, 'void setHeaderDockPlace(cocos2d::ui::TabControl::Dock dockPlace)')
cls.func(nil, 'cocos2d::ui::TabControl::Dock getHeaderDockPlace()')
cls.callback {
    FUNCS =  {
        'void setTabChangedEventListener(@nullable @local const std::function<void (int, EventType)> &callback)'
    },
    TAG_MAKER = 'tabChangedEventListener',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.prop('tabCount', nil, nil)
cls.prop('selectedTabIndex', nil, nil)
cls.prop('headerWidth', nil, nil)
cls.prop('headerHeight', nil, nil)
cls.prop('ignoreHeadersTextureSize', nil, nil)
cls.prop('headerSelectedZoom', nil, nil)
cls.prop('headerDockPlace', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::ScrollView::Direction'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('NONE', 'cocos2d::ui::ScrollView::Direction::NONE')
cls.enum('VERTICAL', 'cocos2d::ui::ScrollView::Direction::VERTICAL')
cls.enum('HORIZONTAL', 'cocos2d::ui::ScrollView::Direction::HORIZONTAL')
cls.enum('BOTH', 'cocos2d::ui::ScrollView::Direction::BOTH')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::ScrollView::EventType'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('SCROLL_TO_TOP', 'cocos2d::ui::ScrollView::EventType::SCROLL_TO_TOP')
cls.enum('SCROLL_TO_BOTTOM', 'cocos2d::ui::ScrollView::EventType::SCROLL_TO_BOTTOM')
cls.enum('SCROLL_TO_LEFT', 'cocos2d::ui::ScrollView::EventType::SCROLL_TO_LEFT')
cls.enum('SCROLL_TO_RIGHT', 'cocos2d::ui::ScrollView::EventType::SCROLL_TO_RIGHT')
cls.enum('SCROLLING', 'cocos2d::ui::ScrollView::EventType::SCROLLING')
cls.enum('BOUNCE_TOP', 'cocos2d::ui::ScrollView::EventType::BOUNCE_TOP')
cls.enum('BOUNCE_BOTTOM', 'cocos2d::ui::ScrollView::EventType::BOUNCE_BOTTOM')
cls.enum('BOUNCE_LEFT', 'cocos2d::ui::ScrollView::EventType::BOUNCE_LEFT')
cls.enum('BOUNCE_RIGHT', 'cocos2d::ui::ScrollView::EventType::BOUNCE_RIGHT')
cls.enum('CONTAINER_MOVED', 'cocos2d::ui::ScrollView::EventType::CONTAINER_MOVED')
cls.enum('SCROLLING_BEGAN', 'cocos2d::ui::ScrollView::EventType::SCROLLING_BEGAN')
cls.enum('SCROLLING_ENDED', 'cocos2d::ui::ScrollView::EventType::SCROLLING_ENDED')
cls.enum('AUTOSCROLL_ENDED', 'cocos2d::ui::ScrollView::EventType::AUTOSCROLL_ENDED')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::ScrollView'
cls.SUPERCLS = 'cocos2d::ui::Layout'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::Ref *createInstance()')
cls.func(nil, 'ScrollView()')
cls.func(nil, 'static cocos2d::ui::ScrollView *create()')
cls.func(nil, 'void setDirection(cocos2d::ui::ScrollView::Direction dir)')
cls.func(nil, 'cocos2d::ui::ScrollView::Direction getDirection()')
cls.func(nil, '@addref(protectedChildren |) cocos2d::ui::Layout *getInnerContainer()')
cls.func(nil, 'void stopScroll()')
cls.func(nil, 'void stopAutoScroll()')
cls.func(nil, 'void stopOverallScroll()')
cls.func(nil, 'void scrollToBottom(float timeInSec, bool attenuated)')
cls.func(nil, 'void scrollToTop(float timeInSec, bool attenuated)')
cls.func(nil, 'void scrollToLeft(float timeInSec, bool attenuated)')
cls.func(nil, 'void scrollToRight(float timeInSec, bool attenuated)')
cls.func(nil, 'void scrollToTopLeft(float timeInSec, bool attenuated)')
cls.func(nil, 'void scrollToTopRight(float timeInSec, bool attenuated)')
cls.func(nil, 'void scrollToBottomLeft(float timeInSec, bool attenuated)')
cls.func(nil, 'void scrollToBottomRight(float timeInSec, bool attenuated)')
cls.func(nil, 'void scrollToPercentVertical(float percent, float timeInSec, bool attenuated)')
cls.func(nil, 'void scrollToPercentHorizontal(float percent, float timeInSec, bool attenuated)')
cls.func(nil, 'void scrollToPercentBothDirection(const cocos2d::Vec2 &percent, float timeInSec, bool attenuated)')
cls.func(nil, 'float getScrolledPercentVertical()')
cls.func(nil, 'float getScrolledPercentHorizontal()')
cls.func(nil, 'cocos2d::Vec2 getScrolledPercentBothDirection()')
cls.func(nil, 'void jumpToBottom()')
cls.func(nil, 'void jumpToTop()')
cls.func(nil, 'void jumpToLeft()')
cls.func(nil, 'void jumpToRight()')
cls.func(nil, 'void jumpToTopLeft()')
cls.func(nil, 'void jumpToTopRight()')
cls.func(nil, 'void jumpToBottomLeft()')
cls.func(nil, 'void jumpToBottomRight()')
cls.func(nil, 'void jumpToPercentVertical(float percent)')
cls.func(nil, 'void jumpToPercentHorizontal(float percent)')
cls.func(nil, 'void jumpToPercentBothDirection(const cocos2d::Vec2 &percent)')
cls.func(nil, 'void setInnerContainerSize(const cocos2d::Size &size)')
cls.func(nil, 'const cocos2d::Size &getInnerContainerSize()')
cls.func(nil, 'void setInnerContainerPosition(const cocos2d::Vec2 &pos)')
cls.func(nil, 'const cocos2d::Vec2 &getInnerContainerPosition()')
cls.func(nil, 'void setBounceEnabled(bool enabled)')
cls.func(nil, 'bool isBounceEnabled()')
cls.func(nil, 'void setInertiaScrollEnabled(bool enabled)')
cls.func(nil, 'bool isInertiaScrollEnabled()')
cls.func(nil, 'void setScrollBarEnabled(bool enabled)')
cls.func(nil, 'bool isScrollBarEnabled()')
cls.func(nil, 'void setScrollBarPositionFromCorner(const cocos2d::Vec2 &positionFromCorner)')
cls.func(nil, 'void setScrollBarPositionFromCornerForVertical(const cocos2d::Vec2 &positionFromCorner)')
cls.func(nil, 'cocos2d::Vec2 getScrollBarPositionFromCornerForVertical()')
cls.func(nil, 'void setScrollBarPositionFromCornerForHorizontal(const cocos2d::Vec2 &positionFromCorner)')
cls.func(nil, 'cocos2d::Vec2 getScrollBarPositionFromCornerForHorizontal()')
cls.func(nil, 'void setScrollBarWidth(float width)')
cls.func(nil, 'float getScrollBarWidth()')
cls.func(nil, 'void setScrollBarColor(const cocos2d::Color3B &color)')
cls.func(nil, 'const cocos2d::Color3B &getScrollBarColor()')
cls.func(nil, 'void setScrollBarOpacity(uint8_t opacity)')
cls.func(nil, 'uint8_t getScrollBarOpacity()')
cls.func(nil, 'void setScrollBarAutoHideEnabled(bool autoHideEnabled)')
cls.func(nil, 'bool isScrollBarAutoHideEnabled()')
cls.func(nil, 'void setScrollBarAutoHideTime(float autoHideTime)')
cls.func(nil, 'float getScrollBarAutoHideTime()')
cls.func(nil, 'void setTouchTotalTimeThreshold(float touchTotalTimeThreshold)')
cls.func(nil, 'float getTouchTotalTimeThreshold()')
cls.func(nil, 'bool isScrolling()')
cls.func(nil, 'bool isAutoScrolling()')
cls.callback {
    FUNCS =  {
        'void addEventListener(@nullable const std::function<void (Ref *, EventType)> &callback)'
    },
    TAG_MAKER = 'scrollViewCallback',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.prop('direction', nil, nil)
cls.prop('innerContainer', nil, nil)
cls.prop('scrolledPercentVertical', nil, nil)
cls.prop('scrolledPercentHorizontal', nil, nil)
cls.prop('scrolledPercentBothDirection', nil, nil)
cls.prop('innerContainerSize', nil, nil)
cls.prop('innerContainerPosition', nil, nil)
cls.prop('bounceEnabled', nil, nil)
cls.prop('inertiaScrollEnabled', nil, nil)
cls.prop('scrollBarEnabled', nil, nil)
cls.prop('scrollBarPositionFromCornerForVertical', nil, nil)
cls.prop('scrollBarPositionFromCornerForHorizontal', nil, nil)
cls.prop('scrollBarWidth', nil, nil)
cls.prop('scrollBarColor', nil, nil)
cls.prop('scrollBarOpacity', nil, nil)
cls.prop('scrollBarAutoHideEnabled', nil, nil)
cls.prop('scrollBarAutoHideTime', nil, nil)
cls.prop('touchTotalTimeThreshold', nil, nil)
cls.prop('scrolling', nil, nil)
cls.prop('autoScrolling', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::ListView::Gravity'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('LEFT', 'cocos2d::ui::ListView::Gravity::LEFT')
cls.enum('RIGHT', 'cocos2d::ui::ListView::Gravity::RIGHT')
cls.enum('CENTER_HORIZONTAL', 'cocos2d::ui::ListView::Gravity::CENTER_HORIZONTAL')
cls.enum('TOP', 'cocos2d::ui::ListView::Gravity::TOP')
cls.enum('BOTTOM', 'cocos2d::ui::ListView::Gravity::BOTTOM')
cls.enum('CENTER_VERTICAL', 'cocos2d::ui::ListView::Gravity::CENTER_VERTICAL')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::ListView::EventType'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('ON_SELECTED_ITEM_START', 'cocos2d::ui::ListView::EventType::ON_SELECTED_ITEM_START')
cls.enum('ON_SELECTED_ITEM_END', 'cocos2d::ui::ListView::EventType::ON_SELECTED_ITEM_END')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::ListView::MagneticType'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('NONE', 'cocos2d::ui::ListView::MagneticType::NONE')
cls.enum('CENTER', 'cocos2d::ui::ListView::MagneticType::CENTER')
cls.enum('BOTH_END', 'cocos2d::ui::ListView::MagneticType::BOTH_END')
cls.enum('LEFT', 'cocos2d::ui::ListView::MagneticType::LEFT')
cls.enum('RIGHT', 'cocos2d::ui::ListView::MagneticType::RIGHT')
cls.enum('TOP', 'cocos2d::ui::ListView::MagneticType::TOP')
cls.enum('BOTTOM', 'cocos2d::ui::ListView::MagneticType::BOTTOM')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::ListView'
cls.SUPERCLS = 'cocos2d::ui::ScrollView'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::Ref *createInstance()')
cls.func(nil, 'ListView()')
cls.func(nil, 'static cocos2d::ui::ListView *create()')
cls.func(nil, 'void setItemModel(cocos2d::ui::Widget *model)')
cls.func(nil, 'void pushBackDefaultItem()')
cls.func(nil, 'void insertDefaultItem(ssize_t index)')
cls.func(nil, 'void pushBackCustomItem(@addref(children |) cocos2d::ui::Widget *item)')
cls.func(nil, 'void insertCustomItem(@addref(children |) cocos2d::ui::Widget *item, ssize_t index)')
cls.func(nil, '@delref(children ~) void removeLastItem()')
cls.func(nil, '@delref(children ~) void removeItem(ssize_t index)')
cls.func(nil, '@delref(children ~) void removeAllItems()')
cls.func(nil, '@addref(children |) cocos2d::ui::Widget *getItem(ssize_t index)')
cls.func(nil, '@addref(children |) Vector<cocos2d::ui::Widget *> &getItems()')
cls.func(nil, 'ssize_t getIndex(cocos2d::ui::Widget *item)')
cls.func(nil, 'void setGravity(cocos2d::ui::ListView::Gravity gravity)')
cls.func(nil, 'void setMagneticType(cocos2d::ui::ListView::MagneticType magneticType)')
cls.func(nil, 'cocos2d::ui::ListView::MagneticType getMagneticType()')
cls.func(nil, 'void setMagneticAllowedOutOfBoundary(bool magneticAllowedOutOfBoundary)')
cls.func(nil, 'bool getMagneticAllowedOutOfBoundary()')
cls.func(nil, 'void setItemsMargin(float margin)')
cls.func(nil, 'float getItemsMargin()')
cls.func(nil, 'void setPadding(float l, float t, float r, float b)')
cls.func(nil, 'void setLeftPadding(float l)')
cls.func(nil, 'void setTopPadding(float t)')
cls.func(nil, 'void setRightPadding(float r)')
cls.func(nil, 'void setBottomPadding(float b)')
cls.func(nil, 'float getLeftPadding()')
cls.func(nil, 'float getTopPadding()')
cls.func(nil, 'float getRightPadding()')
cls.func(nil, 'float getBottomPadding()')
cls.func(nil, 'void setScrollDuration(float time)')
cls.func(nil, 'float getScrollDuration()')
cls.func(nil, 'void doLayout()')
cls.func(nil, 'cocos2d::ui::Widget *getClosestItemToPosition(const cocos2d::Vec2 &targetPosition, const cocos2d::Vec2 &itemAnchorPoint)')
cls.func(nil, 'cocos2d::ui::Widget *getClosestItemToPositionInCurrentView(const cocos2d::Vec2 &positionRatioInView, const cocos2d::Vec2 &itemAnchorPoint)')
cls.func(nil, 'cocos2d::ui::Widget *getCenterItemInCurrentView()')
cls.func(nil, 'cocos2d::ui::Widget *getLeftmostItemInCurrentView()')
cls.func(nil, 'cocos2d::ui::Widget *getRightmostItemInCurrentView()')
cls.func(nil, 'cocos2d::ui::Widget *getTopmostItemInCurrentView()')
cls.func(nil, 'cocos2d::ui::Widget *getBottommostItemInCurrentView()')
cls.func(nil, 'void jumpToItem(ssize_t itemIndex, const cocos2d::Vec2 &positionRatioInView, const cocos2d::Vec2 &itemAnchorPoint)')
cls.func(nil, 'void scrollToItem(ssize_t itemIndex, const cocos2d::Vec2 &positionRatioInView, const cocos2d::Vec2 &itemAnchorPoint)', 'void scrollToItem(ssize_t itemIndex, const cocos2d::Vec2 &positionRatioInView, const cocos2d::Vec2 &itemAnchorPoint, float timeInSec)')
cls.func(nil, 'ssize_t getCurSelectedIndex()')
cls.func(nil, 'void setCurSelectedIndex(int itemIndex)')
cls.callback {
    FUNCS =  {
        'void addEventListener(@nullable const std::function<void(Ref*, EventType)>& callback)'
    },
    TAG_MAKER = 'ListViewCallback',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.prop('items', nil, nil)
cls.prop('magneticType', nil, nil)
cls.prop('magneticAllowedOutOfBoundary', nil, nil)
cls.prop('itemsMargin', nil, nil)
cls.prop('leftPadding', nil, nil)
cls.prop('topPadding', nil, nil)
cls.prop('rightPadding', nil, nil)
cls.prop('bottomPadding', nil, nil)
cls.prop('scrollDuration', nil, nil)
cls.prop('centerItemInCurrentView', nil, nil)
cls.prop('leftmostItemInCurrentView', nil, nil)
cls.prop('rightmostItemInCurrentView', nil, nil)
cls.prop('topmostItemInCurrentView', nil, nil)
cls.prop('bottommostItemInCurrentView', nil, nil)
cls.prop('curSelectedIndex', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::LoadingBar::Direction'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('LEFT', 'cocos2d::ui::LoadingBar::Direction::LEFT')
cls.enum('RIGHT', 'cocos2d::ui::LoadingBar::Direction::RIGHT')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::LoadingBar'
cls.SUPERCLS = 'cocos2d::ui::Widget'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::Ref *createInstance()')
cls.func(nil, 'LoadingBar()')
cls.func(nil, 'static cocos2d::ui::LoadingBar *create()', 'static cocos2d::ui::LoadingBar *create(const std::string &textureName, @optional float percentage)', 'static cocos2d::ui::LoadingBar *create(const std::string &textureName, cocos2d::ui::Widget::TextureResType texType, @optional float percentage)')
cls.func(nil, 'void setDirection(cocos2d::ui::LoadingBar::Direction direction)')
cls.func(nil, 'cocos2d::ui::LoadingBar::Direction getDirection()')
cls.func(nil, 'void loadTexture(const std::string &texture, @optional cocos2d::ui::Widget::TextureResType texType)')
cls.func(nil, 'void setPercent(float percent)')
cls.func(nil, 'float getPercent()')
cls.func(nil, 'void setScale9Enabled(bool enabled)')
cls.func(nil, 'bool isScale9Enabled()')
cls.func(nil, 'void setCapInsets(const cocos2d::Rect &capInsets)')
cls.func(nil, 'const cocos2d::Rect &getCapInsets()')
cls.func(nil, 'cocos2d::ResourceData getRenderFile()')
cls.prop('direction', nil, nil)
cls.prop('percent', nil, nil)
cls.prop('scale9Enabled', nil, nil)
cls.prop('capInsets', nil, nil)
cls.prop('renderFile', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::PageView::EventType'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('TURNING', 'cocos2d::ui::PageView::EventType::TURNING')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::PageView::TouchDirection'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('LEFT', 'cocos2d::ui::PageView::TouchDirection::LEFT')
cls.enum('RIGHT', 'cocos2d::ui::PageView::TouchDirection::RIGHT')
cls.enum('UP', 'cocos2d::ui::PageView::TouchDirection::UP')
cls.enum('DOWN', 'cocos2d::ui::PageView::TouchDirection::DOWN')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::PageView'
cls.SUPERCLS = 'cocos2d::ui::ListView'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::Ref *createInstance()')
cls.func(nil, 'PageView()')
cls.func(nil, 'static cocos2d::ui::PageView *create()')
cls.func(nil, 'void addPage(@addref(children |) cocos2d::ui::Widget *page)')
cls.func(nil, 'void insertPage(@addref(children |) cocos2d::ui::Widget *page, int idx)')
cls.func(nil, 'void removePage(@delref(children |) cocos2d::ui::Widget *page)')
cls.func(nil, '@delref(children ~) void removePageAtIndex(ssize_t index)')
cls.func(nil, '@delref(children *) void removeAllPages()')
cls.func(nil, 'void scrollToPage(ssize_t idx)', 'void scrollToPage(ssize_t idx, float time)')
cls.func(nil, 'void scrollToItem(ssize_t itemIndex)', 'void scrollToItem(ssize_t idx, float time)')
cls.func(nil, 'ssize_t getCurrentPageIndex()')
cls.func(nil, 'void setCurrentPageIndex(ssize_t index)')
cls.func(nil, 'void setIndicatorEnabled(bool enabled)')
cls.func(nil, 'bool getIndicatorEnabled()')
cls.func(nil, 'void setIndicatorPositionAsAnchorPoint(const cocos2d::Vec2 &positionAsAnchorPoint)')
cls.func(nil, 'const cocos2d::Vec2 &getIndicatorPositionAsAnchorPoint()')
cls.func(nil, 'void setIndicatorPosition(const cocos2d::Vec2 &position)')
cls.func(nil, 'const cocos2d::Vec2 &getIndicatorPosition()')
cls.func(nil, 'void setIndicatorSpaceBetweenIndexNodes(float spaceBetweenIndexNodes)')
cls.func(nil, 'float getIndicatorSpaceBetweenIndexNodes()')
cls.func(nil, 'void setIndicatorSelectedIndexColor(const cocos2d::Color3B &color)')
cls.func(nil, 'const cocos2d::Color3B &getIndicatorSelectedIndexColor()')
cls.func(nil, 'void setIndicatorIndexNodesColor(const cocos2d::Color3B &color)')
cls.func(nil, 'const cocos2d::Color3B &getIndicatorIndexNodesColor()')
cls.func(nil, 'void setIndicatorSelectedIndexOpacity(uint8_t opacity)')
cls.func(nil, 'uint8_t getIndicatorSelectedIndexOpacity()')
cls.func(nil, 'void setIndicatorIndexNodesOpacity(uint8_t opacity)')
cls.func(nil, 'uint8_t getIndicatorIndexNodesOpacity()')
cls.func(nil, 'void setIndicatorIndexNodesScale(float indexNodesScale)')
cls.func(nil, 'void setIndicatorIndexNodesTexture(const std::string &texName, @optional cocos2d::ui::Widget::TextureResType texType)')
cls.func(nil, 'float getIndicatorIndexNodesScale()')
cls.func(nil, 'void setAutoScrollStopEpsilon(float epsilon)')
cls.callback {
    FUNCS =  {
        'void addEventListener(@nullable const std::function<void(Ref*, PageView::EventType)>& callback)'
    },
    TAG_MAKER = 'PageViewCallback',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.prop('currentPageIndex', nil, nil)
cls.prop('indicatorEnabled', nil, nil)
cls.prop('indicatorPositionAsAnchorPoint', nil, nil)
cls.prop('indicatorPosition', nil, nil)
cls.prop('indicatorSpaceBetweenIndexNodes', nil, nil)
cls.prop('indicatorSelectedIndexColor', nil, nil)
cls.prop('indicatorIndexNodesColor', nil, nil)
cls.prop('indicatorSelectedIndexOpacity', nil, nil)
cls.prop('indicatorIndexNodesOpacity', nil, nil)
cls.prop('indicatorIndexNodesScale', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::RichElement::Type'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('TEXT', 'cocos2d::ui::RichElement::Type::TEXT')
cls.enum('IMAGE', 'cocos2d::ui::RichElement::Type::IMAGE')
cls.enum('CUSTOM', 'cocos2d::ui::RichElement::Type::CUSTOM')
cls.enum('NEWLINE', 'cocos2d::ui::RichElement::Type::NEWLINE')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::RichElement'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'RichElement()')
cls.func(nil, 'bool init(int tag, const cocos2d::Color3B &color, uint8_t opacity)')
cls.func(nil, 'bool equalType(cocos2d::ui::RichElement::Type type)')
cls.func(nil, 'void setColor(const cocos2d::Color3B &color)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::RichElementText'
cls.SUPERCLS = 'cocos2d::ui::RichElement'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'RichElementText()')
cls.func(nil, 'bool init(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &text, const std::string &fontName, float fontSize, uint32_t flags, const std::string &url, @optional const cocos2d::Color3B &outlineColor, @optional int outlineSize, @optional const cocos2d::Color3B &shadowColor, @optional const cocos2d::Size &shadowOffset, @optional int shadowBlurRadius, @optional const cocos2d::Color3B &glowColor)')
cls.func(nil, 'static cocos2d::ui::RichElementText *create(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &text, const std::string &fontName, float fontSize, @optional uint32_t flags, @optional const std::string &url, @optional const cocos2d::Color3B &outlineColor, @optional int outlineSize, @optional const cocos2d::Color3B &shadowColor, @optional const cocos2d::Size &shadowOffset, @optional int shadowBlurRadius, @optional const cocos2d::Color3B &glowColor)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::RichElementImage'
cls.SUPERCLS = 'cocos2d::ui::RichElement'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'RichElementImage()')
cls.func(nil, 'bool init(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &filePath, @optional const std::string &url, @optional cocos2d::ui::Widget::TextureResType texType)')
cls.func(nil, 'static cocos2d::ui::RichElementImage *create(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &filePath, @optional const std::string &url, @optional cocos2d::ui::Widget::TextureResType texType)')
cls.func(nil, 'void setWidth(int width)')
cls.func(nil, 'void setHeight(int height)')
cls.func(nil, 'void setUrl(const std::string &url)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::RichElementCustomNode'
cls.SUPERCLS = 'cocos2d::ui::RichElement'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'RichElementCustomNode()')
cls.func(nil, 'bool init(int tag, const cocos2d::Color3B &color, uint8_t opacity, cocos2d::Node *customNode)')
cls.func(nil, 'static cocos2d::ui::RichElementCustomNode *create(int tag, const cocos2d::Color3B &color, uint8_t opacity, cocos2d::Node *customNode)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::RichElementNewLine'
cls.SUPERCLS = 'cocos2d::ui::RichElement'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'RichElementNewLine()')
cls.func(nil, 'static cocos2d::ui::RichElementNewLine *create(int tag, const cocos2d::Color3B &color, uint8_t opacity)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::RichText::WrapMode'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('WRAP_PER_WORD', 'cocos2d::ui::RichText::WrapMode::WRAP_PER_WORD')
cls.enum('WRAP_PER_CHAR', 'cocos2d::ui::RichText::WrapMode::WRAP_PER_CHAR')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::RichText::HorizontalAlignment'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('LEFT', 'cocos2d::ui::RichText::HorizontalAlignment::LEFT')
cls.enum('CENTER', 'cocos2d::ui::RichText::HorizontalAlignment::CENTER')
cls.enum('RIGHT', 'cocos2d::ui::RichText::HorizontalAlignment::RIGHT')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::RichText'
cls.SUPERCLS = 'cocos2d::ui::Widget'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.const('KEY_VERTICAL_SPACE', 'cocos2d::ui::RichText::KEY_VERTICAL_SPACE', 'const std::string')
cls.const('KEY_WRAP_MODE', 'cocos2d::ui::RichText::KEY_WRAP_MODE', 'const std::string')
cls.const('KEY_HORIZONTAL_ALIGNMENT', 'cocos2d::ui::RichText::KEY_HORIZONTAL_ALIGNMENT', 'const std::string')
cls.const('KEY_FONT_COLOR_STRING', 'cocos2d::ui::RichText::KEY_FONT_COLOR_STRING', 'const std::string')
cls.const('KEY_FONT_SIZE', 'cocos2d::ui::RichText::KEY_FONT_SIZE', 'const std::string')
cls.const('KEY_FONT_SMALL', 'cocos2d::ui::RichText::KEY_FONT_SMALL', 'const std::string')
cls.const('KEY_FONT_BIG', 'cocos2d::ui::RichText::KEY_FONT_BIG', 'const std::string')
cls.const('KEY_FONT_FACE', 'cocos2d::ui::RichText::KEY_FONT_FACE', 'const std::string')
cls.const('KEY_TEXT_BOLD', 'cocos2d::ui::RichText::KEY_TEXT_BOLD', 'const std::string')
cls.const('KEY_TEXT_ITALIC', 'cocos2d::ui::RichText::KEY_TEXT_ITALIC', 'const std::string')
cls.const('KEY_TEXT_LINE', 'cocos2d::ui::RichText::KEY_TEXT_LINE', 'const std::string')
cls.const('VALUE_TEXT_LINE_NONE', 'cocos2d::ui::RichText::VALUE_TEXT_LINE_NONE', 'const std::string')
cls.const('VALUE_TEXT_LINE_DEL', 'cocos2d::ui::RichText::VALUE_TEXT_LINE_DEL', 'const std::string')
cls.const('VALUE_TEXT_LINE_UNDER', 'cocos2d::ui::RichText::VALUE_TEXT_LINE_UNDER', 'const std::string')
cls.const('KEY_TEXT_STYLE', 'cocos2d::ui::RichText::KEY_TEXT_STYLE', 'const std::string')
cls.const('VALUE_TEXT_STYLE_NONE', 'cocos2d::ui::RichText::VALUE_TEXT_STYLE_NONE', 'const std::string')
cls.const('VALUE_TEXT_STYLE_OUTLINE', 'cocos2d::ui::RichText::VALUE_TEXT_STYLE_OUTLINE', 'const std::string')
cls.const('VALUE_TEXT_STYLE_SHADOW', 'cocos2d::ui::RichText::VALUE_TEXT_STYLE_SHADOW', 'const std::string')
cls.const('VALUE_TEXT_STYLE_GLOW', 'cocos2d::ui::RichText::VALUE_TEXT_STYLE_GLOW', 'const std::string')
cls.const('KEY_TEXT_OUTLINE_COLOR', 'cocos2d::ui::RichText::KEY_TEXT_OUTLINE_COLOR', 'const std::string')
cls.const('KEY_TEXT_OUTLINE_SIZE', 'cocos2d::ui::RichText::KEY_TEXT_OUTLINE_SIZE', 'const std::string')
cls.const('KEY_TEXT_SHADOW_COLOR', 'cocos2d::ui::RichText::KEY_TEXT_SHADOW_COLOR', 'const std::string')
cls.const('KEY_TEXT_SHADOW_OFFSET_WIDTH', 'cocos2d::ui::RichText::KEY_TEXT_SHADOW_OFFSET_WIDTH', 'const std::string')
cls.const('KEY_TEXT_SHADOW_OFFSET_HEIGHT', 'cocos2d::ui::RichText::KEY_TEXT_SHADOW_OFFSET_HEIGHT', 'const std::string')
cls.const('KEY_TEXT_SHADOW_BLUR_RADIUS', 'cocos2d::ui::RichText::KEY_TEXT_SHADOW_BLUR_RADIUS', 'const std::string')
cls.const('KEY_TEXT_GLOW_COLOR', 'cocos2d::ui::RichText::KEY_TEXT_GLOW_COLOR', 'const std::string')
cls.const('KEY_URL', 'cocos2d::ui::RichText::KEY_URL', 'const std::string')
cls.const('KEY_ANCHOR_FONT_COLOR_STRING', 'cocos2d::ui::RichText::KEY_ANCHOR_FONT_COLOR_STRING', 'const std::string')
cls.const('KEY_ANCHOR_TEXT_BOLD', 'cocos2d::ui::RichText::KEY_ANCHOR_TEXT_BOLD', 'const std::string')
cls.const('KEY_ANCHOR_TEXT_ITALIC', 'cocos2d::ui::RichText::KEY_ANCHOR_TEXT_ITALIC', 'const std::string')
cls.const('KEY_ANCHOR_TEXT_LINE', 'cocos2d::ui::RichText::KEY_ANCHOR_TEXT_LINE', 'const std::string')
cls.const('KEY_ANCHOR_TEXT_STYLE', 'cocos2d::ui::RichText::KEY_ANCHOR_TEXT_STYLE', 'const std::string')
cls.const('KEY_ANCHOR_TEXT_OUTLINE_COLOR', 'cocos2d::ui::RichText::KEY_ANCHOR_TEXT_OUTLINE_COLOR', 'const std::string')
cls.const('KEY_ANCHOR_TEXT_OUTLINE_SIZE', 'cocos2d::ui::RichText::KEY_ANCHOR_TEXT_OUTLINE_SIZE', 'const std::string')
cls.const('KEY_ANCHOR_TEXT_SHADOW_COLOR', 'cocos2d::ui::RichText::KEY_ANCHOR_TEXT_SHADOW_COLOR', 'const std::string')
cls.const('KEY_ANCHOR_TEXT_SHADOW_OFFSET_WIDTH', 'cocos2d::ui::RichText::KEY_ANCHOR_TEXT_SHADOW_OFFSET_WIDTH', 'const std::string')
cls.const('KEY_ANCHOR_TEXT_SHADOW_OFFSET_HEIGHT', 'cocos2d::ui::RichText::KEY_ANCHOR_TEXT_SHADOW_OFFSET_HEIGHT', 'const std::string')
cls.const('KEY_ANCHOR_TEXT_SHADOW_BLUR_RADIUS', 'cocos2d::ui::RichText::KEY_ANCHOR_TEXT_SHADOW_BLUR_RADIUS', 'const std::string')
cls.const('KEY_ANCHOR_TEXT_GLOW_COLOR', 'cocos2d::ui::RichText::KEY_ANCHOR_TEXT_GLOW_COLOR', 'const std::string')
cls.func(nil, 'RichText()')
cls.func(nil, 'static cocos2d::ui::RichText *create()')
cls.func(nil, 'void insertElement(cocos2d::ui::RichElement *element, int index)')
cls.func(nil, 'void pushBackElement(cocos2d::ui::RichElement *element)')
cls.func(nil, 'void removeElement(int index)', 'void removeElement(cocos2d::ui::RichElement *element)')
cls.func(nil, 'void setVerticalSpace(float space)')
cls.func(nil, 'void formatText()')
cls.func(nil, 'void setWrapMode(cocos2d::ui::RichText::WrapMode wrapMode)')
cls.func(nil, 'cocos2d::ui::RichText::WrapMode getWrapMode()')
cls.func(nil, 'void setHorizontalAlignment(cocos2d::ui::RichText::HorizontalAlignment a)')
cls.func(nil, 'cocos2d::ui::RichText::HorizontalAlignment getHorizontalAlignment()')
cls.func(nil, 'void setFontColor(const std::string &color)')
cls.func(nil, 'std::string getFontColor()')
cls.func(nil, 'cocos2d::Color3B getFontColor3B()')
cls.func(nil, 'void setFontSize(float size)')
cls.func(nil, 'float getFontSize()')
cls.func(nil, 'void setFontFace(const std::string &face)')
cls.func(nil, 'std::string getFontFace()')
cls.func(nil, 'void setAnchorFontColor(const std::string &color)')
cls.func(nil, 'std::string getAnchorFontColor()')
cls.func(nil, 'cocos2d::Color3B getAnchorFontColor3B()')
cls.func(nil, 'void setAnchorTextBold(bool enable)')
cls.func(nil, 'bool isAnchorTextBoldEnabled()')
cls.func(nil, 'void setAnchorTextItalic(bool enable)')
cls.func(nil, 'bool isAnchorTextItalicEnabled()')
cls.func(nil, 'void setAnchorTextDel(bool enable)')
cls.func(nil, 'bool isAnchorTextDelEnabled()')
cls.func(nil, 'void setAnchorTextUnderline(bool enable)')
cls.func(nil, 'bool isAnchorTextUnderlineEnabled()')
cls.func(nil, 'void setAnchorTextOutline(bool enable, @optional const cocos2d::Color3B &outlineColor, @optional int outlineSize)')
cls.func(nil, 'bool isAnchorTextOutlineEnabled()')
cls.func(nil, 'cocos2d::Color3B getAnchorTextOutlineColor3B()')
cls.func(nil, 'int getAnchorTextOutlineSize()')
cls.func(nil, 'void setAnchorTextShadow(bool enable, @optional const cocos2d::Color3B &shadowColor, @optional const cocos2d::Size &offset, @optional int blurRadius)')
cls.func(nil, 'bool isAnchorTextShadowEnabled()')
cls.func(nil, 'cocos2d::Color3B getAnchorTextShadowColor3B()')
cls.func(nil, 'cocos2d::Size getAnchorTextShadowOffset()')
cls.func(nil, 'int getAnchorTextShadowBlurRadius()')
cls.func(nil, 'void setAnchorTextGlow(bool enable, @optional const cocos2d::Color3B &glowColor)')
cls.func(nil, 'bool isAnchorTextGlowEnabled()')
cls.func(nil, 'cocos2d::Color3B getAnchorTextGlowColor3B()')
cls.func(nil, 'void setDefaults(const cocos2d::ValueMap &defaults)')
cls.func(nil, 'cocos2d::ValueMap getDefaults()')
cls.func(nil, 'cocos2d::Color3B color3BWithString(const std::string &color)')
cls.func(nil, 'std::string stringWithColor3B(const cocos2d::Color3B &color3b)')
cls.func(nil, 'std::string stringWithColor4B(const cocos2d::Color4B &color4b)')
cls.func(nil, 'static void removeTagDescription(const std::string &tag)')
cls.func(nil, 'void openUrl(const std::string &url)')
cls.callback {
    FUNCS =  {
        'static cocos2d::ui::RichText *createWithXML(const std::string &xml, @optional const cocos2d::ValueMap &defaults, @local @optional const std::function<void (const std::string &)> &handleOpenUrl)'
    },
    TAG_MAKER = 'OpenUrlHandler',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = "return",
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        'void setOpenUrlHandler(@local const std::function<void (const std::string &)> &handleOpenUrl)'
    },
    TAG_MAKER = 'OpenUrlHandler',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.prop('wrapMode', nil, nil)
cls.prop('horizontalAlignment', nil, nil)
cls.prop('fontColor', nil, nil)
cls.prop('fontColor3B', nil, nil)
cls.prop('fontSize', nil, nil)
cls.prop('fontFace', nil, nil)
cls.prop('anchorFontColor', nil, nil)
cls.prop('anchorFontColor3B', nil, nil)
cls.prop('anchorTextBoldEnabled', nil, nil)
cls.prop('anchorTextItalicEnabled', nil, nil)
cls.prop('anchorTextDelEnabled', nil, nil)
cls.prop('anchorTextUnderlineEnabled', nil, nil)
cls.prop('anchorTextOutlineEnabled', nil, nil)
cls.prop('anchorTextOutlineColor3B', nil, nil)
cls.prop('anchorTextOutlineSize', nil, nil)
cls.prop('anchorTextShadowEnabled', nil, nil)
cls.prop('anchorTextShadowColor3B', nil, nil)
cls.prop('anchorTextShadowOffset', nil, nil)
cls.prop('anchorTextShadowBlurRadius', nil, nil)
cls.prop('anchorTextGlowEnabled', nil, nil)
cls.prop('anchorTextGlowColor3B', nil, nil)
cls.prop('defaults', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::ScrollViewBar'
cls.SUPERCLS = 'cocos2d::ProtectedNode'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'ScrollViewBar(cocos2d::ui::ScrollView *parent, cocos2d::ui::ScrollView::Direction direction)')
cls.func(nil, 'static cocos2d::ui::ScrollViewBar *create(cocos2d::ui::ScrollView *parent, cocos2d::ui::ScrollView::Direction direction)')
cls.func(nil, 'void setPositionFromCorner(const cocos2d::Vec2 &positionFromCorner)')
cls.func(nil, 'cocos2d::Vec2 getPositionFromCorner()')
cls.func(nil, 'void setWidth(float width)')
cls.func(nil, 'float getWidth()')
cls.func(nil, 'void setAutoHideEnabled(bool autoHideEnabled)')
cls.func(nil, 'bool isAutoHideEnabled()')
cls.func(nil, 'void setAutoHideTime(float autoHideTime)')
cls.func(nil, 'float getAutoHideTime()')
cls.func(nil, 'void onScrolled(const cocos2d::Vec2 &outOfBoundary)')
cls.func(nil, 'void onTouchBegan()')
cls.func(nil, 'void onTouchEnded()')
cls.prop('positionFromCorner', nil, nil)
cls.prop('width', nil, nil)
cls.prop('autoHideEnabled', nil, nil)
cls.prop('autoHideTime', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::Slider::EventType'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('ON_PERCENTAGE_CHANGED', 'cocos2d::ui::Slider::EventType::ON_PERCENTAGE_CHANGED')
cls.enum('ON_SLIDEBALL_DOWN', 'cocos2d::ui::Slider::EventType::ON_SLIDEBALL_DOWN')
cls.enum('ON_SLIDEBALL_UP', 'cocos2d::ui::Slider::EventType::ON_SLIDEBALL_UP')
cls.enum('ON_SLIDEBALL_CANCEL', 'cocos2d::ui::Slider::EventType::ON_SLIDEBALL_CANCEL')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::Slider'
cls.SUPERCLS = 'cocos2d::ui::Widget'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::Ref *createInstance()')
cls.func(nil, 'Slider()')
cls.func(nil, 'static cocos2d::ui::Slider *create()', 'static cocos2d::ui::Slider *create(const std::string &barTextureName, const std::string &normalBallTextureName, @optional cocos2d::ui::Widget::TextureResType resType)')
cls.func(nil, 'void loadBarTexture(const std::string &fileName, @optional cocos2d::ui::Widget::TextureResType resType)')
cls.func(nil, 'void setScale9Enabled(bool able)')
cls.func(nil, 'bool isScale9Enabled()')
cls.func(nil, 'void setCapInsets(const cocos2d::Rect &capInsets)')
cls.func(nil, 'void setCapInsetsBarRenderer(const cocos2d::Rect &capInsets)')
cls.func(nil, 'const cocos2d::Rect &getCapInsetsBarRenderer()')
cls.func(nil, 'void setCapInsetProgressBarRenderer(const cocos2d::Rect &capInsets)')
cls.func(nil, 'const cocos2d::Rect &getCapInsetsProgressBarRenderer()')
cls.func(nil, 'void loadSlidBallTextures(const std::string &normal, @optional const std::string &pressed, @optional const std::string &disabled, @optional cocos2d::ui::Widget::TextureResType texType)')
cls.func(nil, 'void loadSlidBallTextureNormal(const std::string &normal, @optional cocos2d::ui::Widget::TextureResType resType)')
cls.func(nil, 'void loadSlidBallTexturePressed(const std::string &pressed, @optional cocos2d::ui::Widget::TextureResType resType)')
cls.func(nil, 'void loadSlidBallTextureDisabled(const std::string &disabled, @optional cocos2d::ui::Widget::TextureResType resType)')
cls.func(nil, 'void loadProgressBarTexture(const std::string &fileName, @optional cocos2d::ui::Widget::TextureResType resType)')
cls.func(nil, 'void setPercent(int percent)')
cls.func(nil, 'void updateVisualSlider()')
cls.func(nil, 'int getPercent()')
cls.func(nil, 'void setMaxPercent(int percent)')
cls.func(nil, 'int getMaxPercent()')
cls.func(nil, 'void setZoomScale(float scale)')
cls.func(nil, 'float getZoomScale()')
cls.func(nil, '@addref(protectedChildren |) cocos2d::Sprite *getSlidBallNormalRenderer()')
cls.func(nil, '@addref(protectedChildren |) cocos2d::Sprite *getSlidBallPressedRenderer()')
cls.func(nil, '@addref(protectedChildren |) cocos2d::Sprite *getSlidBallDisabledRenderer()')
cls.func(nil, '@addref(protectedChildren |) cocos2d::Node *getSlidBallRenderer()')
cls.func(nil, 'cocos2d::ResourceData getBackFile()')
cls.func(nil, 'cocos2d::ResourceData getProgressBarFile()')
cls.func(nil, 'cocos2d::ResourceData getBallNormalFile()')
cls.func(nil, 'cocos2d::ResourceData getBallPressedFile()')
cls.func(nil, 'cocos2d::ResourceData getBallDisabledFile()')
cls.callback {
    FUNCS =  {
        'void addEventListener(@nullable const std::function<void (Ref *, EventType)> &callback)'
    },
    TAG_MAKER = 'sliderCallback',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.prop('scale9Enabled', nil, nil)
cls.prop('capInsetsBarRenderer', nil, nil)
cls.prop('capInsetsProgressBarRenderer', nil, nil)
cls.prop('percent', nil, nil)
cls.prop('maxPercent', nil, nil)
cls.prop('zoomScale', nil, nil)
cls.prop('slidBallNormalRenderer', nil, nil)
cls.prop('slidBallPressedRenderer', nil, nil)
cls.prop('slidBallDisabledRenderer', nil, nil)
cls.prop('slidBallRenderer', nil, nil)
cls.prop('backFile', nil, nil)
cls.prop('progressBarFile', nil, nil)
cls.prop('ballNormalFile', nil, nil)
cls.prop('ballPressedFile', nil, nil)
cls.prop('ballDisabledFile', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::Text::Type'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('SYSTEM', 'cocos2d::ui::Text::Type::SYSTEM')
cls.enum('TTF', 'cocos2d::ui::Text::Type::TTF')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::Text'
cls.SUPERCLS = 'cocos2d::ui::Widget'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::Ref *createInstance()')
cls.func(nil, 'Text()')
cls.func(nil, 'static cocos2d::ui::Text *create()', 'static cocos2d::ui::Text *create(const std::string &textContent, const std::string &fontName, float fontSize)')
cls.func(nil, 'void setString(const std::string &text)')
cls.func(nil, 'const std::string &getString()')
cls.func(nil, 'ssize_t getStringLength()')
cls.func(nil, 'void setFontSize(float size)')
cls.func(nil, 'float getFontSize()')
cls.func(nil, 'void setFontName(const std::string &name)')
cls.func(nil, 'const std::string &getFontName()')
cls.func(nil, 'cocos2d::ui::Text::Type getType()')
cls.func(nil, 'void setTouchScaleChangeEnabled(bool enabled)')
cls.func(nil, 'bool isTouchScaleChangeEnabled()')
cls.func(nil, 'cocos2d::Size getAutoRenderSize()')
cls.func(nil, 'void setTextAreaSize(const cocos2d::Size &size)')
cls.func(nil, 'const cocos2d::Size &getTextAreaSize()')
cls.func(nil, 'void setTextHorizontalAlignment(cocos2d::TextHAlignment alignment)')
cls.func(nil, 'cocos2d::TextHAlignment getTextHorizontalAlignment()')
cls.func(nil, 'void setTextVerticalAlignment(cocos2d::TextVAlignment alignment)')
cls.func(nil, 'cocos2d::TextVAlignment getTextVerticalAlignment()')
cls.func(nil, 'void setTextColor(const cocos2d::Color4B color)')
cls.func(nil, 'const cocos2d::Color4B &getTextColor()')
cls.func(nil, 'void enableShadow(@optional const cocos2d::Color4B &shadowColor, @optional const cocos2d::Size &offset, @optional int blurRadius)')
cls.func(nil, 'void enableOutline(const cocos2d::Color4B &outlineColor, @optional int outlineSize)')
cls.func(nil, 'void enableGlow(const cocos2d::Color4B &glowColor)')
cls.func(nil, 'void disableEffect()', 'void disableEffect(cocos2d::LabelEffect effect)')
cls.func(nil, 'bool isShadowEnabled()')
cls.func(nil, 'cocos2d::Size getShadowOffset()')
cls.func(nil, 'float getShadowBlurRadius()')
cls.func(nil, 'cocos2d::Color4B getShadowColor()')
cls.func(nil, 'int getOutlineSize()')
cls.func(nil, 'cocos2d::LabelEffect getLabelEffectType()')
cls.func(nil, 'cocos2d::Color4B getEffectColor()')
cls.func(nil, 'cocos2d::Sprite *getLetter(int lettetIndex)')
cls.func(nil, 'void setBlendFunc(const cocos2d::BlendFunc &blendFunc)')
cls.func(nil, 'const cocos2d::BlendFunc &getBlendFunc()')
cls.func(nil, 'bool init(const std::string &textContent, const std::string &fontName, float fontSize)')
cls.prop('string', nil, nil)
cls.prop('stringLength', nil, nil)
cls.prop('fontSize', nil, nil)
cls.prop('fontName', nil, nil)
cls.prop('type', nil, nil)
cls.prop('touchScaleChangeEnabled', nil, nil)
cls.prop('autoRenderSize', nil, nil)
cls.prop('textAreaSize', nil, nil)
cls.prop('textHorizontalAlignment', nil, nil)
cls.prop('textVerticalAlignment', nil, nil)
cls.prop('textColor', nil, nil)
cls.prop('shadowEnabled', nil, nil)
cls.prop('shadowOffset', nil, nil)
cls.prop('shadowBlurRadius', nil, nil)
cls.prop('shadowColor', nil, nil)
cls.prop('outlineSize', nil, nil)
cls.prop('labelEffectType', nil, nil)
cls.prop('effectColor', nil, nil)
cls.prop('blendFunc', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::TextAtlas'
cls.SUPERCLS = 'cocos2d::ui::Widget'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::Ref *createInstance()')
cls.func(nil, 'TextAtlas()')
cls.func(nil, 'static cocos2d::ui::TextAtlas *create()', 'static cocos2d::ui::TextAtlas *create(const std::string &stringValue, const std::string &charMapFile, int itemWidth, int itemHeight, const std::string &startCharMap)')
cls.func(nil, 'void setProperty(const std::string &stringValue, const std::string &charMapFile, int itemWidth, int itemHeight, const std::string &startCharMap)')
cls.func(nil, 'void setString(const std::string &value)')
cls.func(nil, 'const std::string &getString()')
cls.func(nil, 'ssize_t getStringLength()')
cls.func(nil, 'void adaptRenderers()')
cls.func(nil, 'cocos2d::ResourceData getRenderFile()')
cls.prop('string', nil, nil)
cls.prop('stringLength', nil, nil)
cls.prop('renderFile', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::TextBMFont'
cls.SUPERCLS = 'cocos2d::ui::Widget'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::Ref *createInstance()')
cls.func(nil, 'TextBMFont()')
cls.func(nil, 'static cocos2d::ui::TextBMFont *create()', 'static cocos2d::ui::TextBMFont *create(const std::string &text, const std::string &filename)')
cls.func(nil, 'void setFntFile(const std::string &fileName)')
cls.func(nil, 'void setString(const std::string &value)')
cls.func(nil, 'const std::string &getString()')
cls.func(nil, 'ssize_t getStringLength()')
cls.func(nil, 'cocos2d::ResourceData getRenderFile()')
cls.func(nil, 'void resetRender()')
cls.prop('string', nil, nil)
cls.prop('stringLength', nil, nil)
cls.prop('renderFile', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::UICCTextField'
cls.SUPERCLS = 'cocos2d::TextFieldTTF'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::ui::UICCTextField *create()', 'static cocos2d::ui::UICCTextField *create(const std::string &placeholder, const std::string &fontName, float fontSize)')
cls.func(nil, 'UICCTextField()')
cls.func(nil, 'bool onTextFieldAttachWithIME(cocos2d::TextFieldTTF *pSender)')
cls.func(nil, 'bool onTextFieldDetachWithIME(cocos2d::TextFieldTTF *pSender)')
cls.func(nil, 'bool onTextFieldInsertText(cocos2d::TextFieldTTF *pSender, const char *text, size_t nLen)')
cls.func(nil, 'bool onTextFieldDeleteBackward(cocos2d::TextFieldTTF *pSender, const char *delText, size_t nLen)')
cls.func(nil, 'void insertText(const char *text, size_t len)')
cls.func(nil, 'void openIME()')
cls.func(nil, 'void closeIME()')
cls.func(nil, 'void setMaxLengthEnabled(bool enable)')
cls.func(nil, 'bool isMaxLengthEnabled()')
cls.func(nil, 'void setMaxLength(int length)')
cls.func(nil, 'int getMaxLength()')
cls.func(nil, 'void setPasswordEnabled(bool enable)')
cls.func(nil, 'bool isPasswordEnabled()')
cls.func(nil, 'void setPasswordStyleText(const std::string &styleText)')
cls.func(nil, 'void setPasswordText(const std::string &text)')
cls.func(nil, 'void setAttachWithIME(bool attach)')
cls.func(nil, 'bool getAttachWithIME()')
cls.func(nil, 'void setDetachWithIME(bool detach)')
cls.func(nil, 'bool getDetachWithIME()')
cls.func(nil, 'void setInsertText(bool insert)')
cls.func(nil, 'bool getInsertText()')
cls.func(nil, 'void setDeleteBackward(bool deleteBackward)')
cls.func(nil, 'bool getDeleteBackward()')
cls.prop('maxLengthEnabled', nil, nil)
cls.prop('maxLength', nil, nil)
cls.prop('passwordEnabled', nil, nil)
cls.prop('attachWithIME', nil, nil)
cls.prop('detachWithIME', nil, nil)
cls.prop('insertText', nil, nil)
cls.prop('deleteBackward', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::TextField::EventType'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('ATTACH_WITH_IME', 'cocos2d::ui::TextField::EventType::ATTACH_WITH_IME')
cls.enum('DETACH_WITH_IME', 'cocos2d::ui::TextField::EventType::DETACH_WITH_IME')
cls.enum('INSERT_TEXT', 'cocos2d::ui::TextField::EventType::INSERT_TEXT')
cls.enum('DELETE_BACKWARD', 'cocos2d::ui::TextField::EventType::DELETE_BACKWARD')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::TextField'
cls.SUPERCLS = 'cocos2d::ui::Widget'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::Ref *createInstance()')
cls.func(nil, 'TextField()')
cls.func(nil, 'static cocos2d::ui::TextField *create()', 'static cocos2d::ui::TextField *create(const std::string &placeholder, const std::string &fontName, int fontSize)')
cls.func(nil, 'void setTouchSize(const cocos2d::Size &size)')
cls.func(nil, 'cocos2d::Size getTouchSize()')
cls.func(nil, 'void setTouchAreaEnabled(bool enable)')
cls.func(nil, 'void setPlaceHolder(const std::string &value)')
cls.func(nil, 'const std::string &getPlaceHolder()')
cls.func(nil, 'const cocos2d::Color4B &getPlaceHolderColor()')
cls.func(nil, 'void setPlaceHolderColor(const cocos2d::Color3B &color)', 'void setPlaceHolderColor(const cocos2d::Color4B &color)')
cls.func(nil, 'const cocos2d::Color4B &getTextColor()')
cls.func(nil, 'void setTextColor(const cocos2d::Color4B &textColor)')
cls.func(nil, 'void setFontSize(int size)')
cls.func(nil, 'int getFontSize()')
cls.func(nil, 'void setFontName(const std::string &name)')
cls.func(nil, 'const std::string &getFontName()')
cls.func(nil, 'void didNotSelectSelf()')
cls.func(nil, 'void setString(const std::string &text)')
cls.func(nil, 'const std::string &getString()')
cls.func(nil, 'void setMaxLengthEnabled(bool enable)')
cls.func(nil, 'bool isMaxLengthEnabled()')
cls.func(nil, 'void setMaxLength(int length)')
cls.func(nil, 'int getMaxLength()')
cls.func(nil, 'int getStringLength()')
cls.func(nil, 'void setPasswordEnabled(bool enable)')
cls.func(nil, 'bool isPasswordEnabled()')
cls.func(nil, 'void setPasswordStyleText(const char *styleText)')
cls.func(nil, 'const char *getPasswordStyleText()')
cls.func(nil, 'bool getAttachWithIME()')
cls.func(nil, 'void setAttachWithIME(bool attach)')
cls.func(nil, 'bool getDetachWithIME()')
cls.func(nil, 'void setDetachWithIME(bool detach)')
cls.func(nil, 'bool getInsertText()')
cls.func(nil, 'void setInsertText(bool insertText)')
cls.func(nil, 'bool getDeleteBackward()')
cls.func(nil, 'void setDeleteBackward(bool deleteBackward)')
cls.func(nil, 'cocos2d::Size getAutoRenderSize()')
cls.func(nil, 'void attachWithIME()')
cls.func(nil, 'void setTextAreaSize(const cocos2d::Size &size)')
cls.func(nil, 'void setTextHorizontalAlignment(cocos2d::TextHAlignment alignment)')
cls.func(nil, 'cocos2d::TextHAlignment getTextHorizontalAlignment()')
cls.func(nil, 'void setTextVerticalAlignment(cocos2d::TextVAlignment alignment)')
cls.func(nil, 'cocos2d::TextVAlignment getTextVerticalAlignment()')
cls.func(nil, 'void setCursorEnabled(bool enabled)')
cls.func(nil, 'void setCursorChar(char cursor)')
cls.func(nil, 'void setCursorPosition(std::size_t cursorPosition)')
cls.func(nil, 'void setCursorFromPoint(const cocos2d::Vec2 &point, const cocos2d::Camera *camera)')
cls.callback {
    FUNCS =  {
        'void addEventListener(@nullable const std::function<void (Ref *, EventType)> &callback)'
    },
    TAG_MAKER = 'textFieldCallback',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.prop('touchSize', nil, nil)
cls.prop('placeHolder', nil, nil)
cls.prop('placeHolderColor', nil, nil)
cls.prop('textColor', nil, nil)
cls.prop('fontSize', nil, nil)
cls.prop('fontName', nil, nil)
cls.prop('string', nil, nil)
cls.prop('maxLengthEnabled', nil, nil)
cls.prop('maxLength', nil, nil)
cls.prop('stringLength', nil, nil)
cls.prop('passwordEnabled', nil, nil)
cls.prop('passwordStyleText', nil, nil)
cls.prop('attachWithIME', nil, nil)
cls.prop('detachWithIME', nil, nil)
cls.prop('insertText', nil, nil)
cls.prop('deleteBackward', nil, nil)
cls.prop('autoRenderSize', nil, nil)
cls.prop('textHorizontalAlignment', nil, nil)
cls.prop('textVerticalAlignment', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::Button'
cls.SUPERCLS = 'cocos2d::ui::Widget'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::Ref *createInstance()')
cls.func(nil, 'Button()')
cls.func(nil, 'static cocos2d::ui::Button *create()', 'static cocos2d::ui::Button *create(const std::string &normalImage, @optional const std::string &selectedImage, @optional const std::string &disableImage, @optional cocos2d::ui::Widget::TextureResType texType)')
cls.func(nil, 'void loadTextures(const std::string &normal, const std::string &selected, @optional const std::string &disabled, @optional cocos2d::ui::Widget::TextureResType texType)')
cls.func(nil, 'void loadTextureNormal(const std::string &normal, @optional cocos2d::ui::Widget::TextureResType texType)')
cls.func(nil, 'void loadTexturePressed(const std::string &selected, @optional cocos2d::ui::Widget::TextureResType texType)')
cls.func(nil, 'void loadTextureDisabled(const std::string &disabled, @optional cocos2d::ui::Widget::TextureResType texType)')
cls.func(nil, 'void setCapInsets(const cocos2d::Rect &capInsets)')
cls.func(nil, 'void setCapInsetsNormalRenderer(const cocos2d::Rect &capInsets)')
cls.func(nil, 'const cocos2d::Rect &getCapInsetsNormalRenderer()')
cls.func(nil, 'void setCapInsetsPressedRenderer(const cocos2d::Rect &capInsets)')
cls.func(nil, 'const cocos2d::Rect &getCapInsetsPressedRenderer()')
cls.func(nil, 'void setCapInsetsDisabledRenderer(const cocos2d::Rect &capInsets)')
cls.func(nil, 'const cocos2d::Rect &getCapInsetsDisabledRenderer()')
cls.func(nil, 'void setScale9Enabled(bool enable)')
cls.func(nil, 'bool isScale9Enabled()')
cls.func(nil, 'void setPressedActionEnabled(bool enabled)')
cls.func(nil, '@addref(protectedChildren |) cocos2d::Label *getTitleRenderer()')
cls.func(nil, 'void setTitleText(const std::string &text)')
cls.func(nil, 'std::string getTitleText()')
cls.func(nil, 'void setTitleColor(const cocos2d::Color3B &color)')
cls.func(nil, 'cocos2d::Color3B getTitleColor()')
cls.func(nil, 'void setTitleFontSize(float size)')
cls.func(nil, 'float getTitleFontSize()')
cls.func(nil, 'void setTitleFontName(const std::string &fontName)')
cls.func(nil, 'std::string getTitleFontName()')
cls.func(nil, 'void setTitleAlignment(cocos2d::TextHAlignment hAlignment)', 'void setTitleAlignment(cocos2d::TextHAlignment hAlignment, cocos2d::TextVAlignment vAlignment)')
cls.func(nil, 'void setTitleLabel(@addref(protectedChildren |) cocos2d::Label *label)')
cls.func(nil, '@addref(protectedChildren |) cocos2d::Label *getTitleLabel()')
cls.func(nil, 'void setZoomScale(float scale)')
cls.func(nil, 'float getZoomScale()')
cls.func(nil, '@addref(protectedChildren |) cocos2d::ui::Scale9Sprite *getRendererNormal()')
cls.func(nil, '@addref(protectedChildren |) cocos2d::ui::Scale9Sprite *getRendererClicked()')
cls.func(nil, '@addref(protectedChildren |) cocos2d::ui::Scale9Sprite *getRendererDisabled()')
cls.func(nil, 'void resetNormalRender()')
cls.func(nil, 'void resetPressedRender()')
cls.func(nil, 'void resetDisabledRender()')
cls.func(nil, 'cocos2d::ResourceData getNormalFile()')
cls.func(nil, 'cocos2d::ResourceData getPressedFile()')
cls.func(nil, 'cocos2d::ResourceData getDisabledFile()')
cls.func(nil, 'bool init(const std::string &normalImage, @optional const std::string &selectedImage, @optional const std::string &disableImage, @optional cocos2d::ui::Widget::TextureResType texType)')
cls.func(nil, 'cocos2d::Size getNormalTextureSize()')
cls.prop('capInsetsNormalRenderer', nil, nil)
cls.prop('capInsetsPressedRenderer', nil, nil)
cls.prop('capInsetsDisabledRenderer', nil, nil)
cls.prop('scale9Enabled', nil, nil)
cls.prop('titleRenderer', nil, nil)
cls.prop('titleText', nil, nil)
cls.prop('titleColor', nil, nil)
cls.prop('titleFontSize', nil, nil)
cls.prop('titleFontName', nil, nil)
cls.prop('titleLabel', nil, nil)
cls.prop('zoomScale', nil, nil)
cls.prop('rendererNormal', nil, nil)
cls.prop('rendererClicked', nil, nil)
cls.prop('rendererDisabled', nil, nil)
cls.prop('normalFile', nil, nil)
cls.prop('pressedFile', nil, nil)
cls.prop('disabledFile', nil, nil)
cls.prop('normalTextureSize', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::CheckBox::EventType'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('SELECTED', 'cocos2d::ui::CheckBox::EventType::SELECTED')
cls.enum('UNSELECTED', 'cocos2d::ui::CheckBox::EventType::UNSELECTED')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::CheckBox'
cls.SUPERCLS = 'cocos2d::ui::AbstractCheckButton'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::Ref *createInstance()')
cls.func(nil, 'CheckBox()')
cls.func(nil, 'static cocos2d::ui::CheckBox *create()', 'static cocos2d::ui::CheckBox *create(const std::string &backGround, const std::string &backGroundSelected, const std::string &cross, const std::string &backGroundDisabled, const std::string &frontCrossDisabled, @optional cocos2d::ui::Widget::TextureResType texType)', 'static cocos2d::ui::CheckBox *create(const std::string &backGround, const std::string &cross, @optional cocos2d::ui::Widget::TextureResType texType)')
cls.callback {
    FUNCS =  {
        'void addEventListener(@nullable const std::function<void (Ref *, CheckBox::EventType)> &callback)'
    },
    TAG_MAKER = 'checkBoxCallback',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::RadioButton::EventType'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('SELECTED', 'cocos2d::ui::RadioButton::EventType::SELECTED')
cls.enum('UNSELECTED', 'cocos2d::ui::RadioButton::EventType::UNSELECTED')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::RadioButton'
cls.SUPERCLS = 'cocos2d::ui::AbstractCheckButton'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::Ref *createInstance()')
cls.func(nil, 'RadioButton()')
cls.func(nil, 'static cocos2d::ui::RadioButton *create()', 'static cocos2d::ui::RadioButton *create(const std::string &backGround, const std::string &backGroundSelected, const std::string &cross, const std::string &backGroundDisabled, const std::string &frontCrossDisabled, @optional cocos2d::ui::Widget::TextureResType texType)', 'static cocos2d::ui::RadioButton *create(const std::string &backGround, const std::string &cross, @optional cocos2d::ui::Widget::TextureResType texType)')
cls.callback {
    FUNCS =  {
        'void addEventListener(@nullable const std::function<void (RadioButton *, EventType)> &callback)'
    },
    TAG_MAKER = 'radioButtonCallback',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::RadioButtonGroup::EventType'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('SELECT_CHANGED', 'cocos2d::ui::RadioButtonGroup::EventType::SELECT_CHANGED')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::RadioButtonGroup'
cls.SUPERCLS = 'cocos2d::ui::Widget'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'RadioButtonGroup()')
cls.func(nil, 'static cocos2d::ui::RadioButtonGroup *create()')
cls.func(nil, 'int getSelectedButtonIndex()')
cls.func(nil, 'void setSelectedButton(int index)', 'void setSelectedButton(cocos2d::ui::RadioButton *radioButton)')
cls.func(nil, 'void setSelectedButtonWithoutEvent(int index)', 'void setSelectedButtonWithoutEvent(cocos2d::ui::RadioButton *radioButton)')
cls.func(nil, 'void addRadioButton(cocos2d::ui::RadioButton *radioButton)')
cls.func(nil, 'void removeRadioButton(cocos2d::ui::RadioButton *radioButton)')
cls.func(nil, 'void removeAllRadioButtons()')
cls.func(nil, 'ssize_t getNumberOfRadioButtons()')
cls.func(nil, 'cocos2d::ui::RadioButton *getRadioButtonByIndex(int index)')
cls.func(nil, 'void setAllowedNoSelection(bool allowedNoSelection)')
cls.func(nil, 'bool isAllowedNoSelection()')
cls.callback {
    FUNCS =  {
        'void addEventListener(@nullable const std::function<void (RadioButton *, int, EventType)> &callback)'
    },
    TAG_MAKER = 'radioButtonCallback',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.prop('selectedButtonIndex', nil, nil)
cls.prop('numberOfRadioButtons', nil, nil)
cls.prop('allowedNoSelection', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::ImageView'
cls.SUPERCLS = 'cocos2d::ui::Widget'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::Ref *createInstance()')
cls.func(nil, 'ImageView()')
cls.func(nil, 'static cocos2d::ui::ImageView *create()', 'static cocos2d::ui::ImageView *create(const std::string &imageFileName, @optional cocos2d::ui::Widget::TextureResType texType)')
cls.func(nil, 'void loadTexture(const std::string &fileName, @optional cocos2d::ui::Widget::TextureResType texType)')
cls.func(nil, 'void setTextureRect(const cocos2d::Rect &rect)')
cls.func(nil, 'void setScale9Enabled(bool enabled)')
cls.func(nil, 'bool isScale9Enabled()')
cls.func(nil, 'void setCapInsets(const cocos2d::Rect &capInsets)')
cls.func(nil, 'const cocos2d::Rect &getCapInsets()')
cls.func(nil, 'void setBlendFunc(const cocos2d::BlendFunc &blendFunc)')
cls.func(nil, 'const cocos2d::BlendFunc &getBlendFunc()')
cls.func(nil, 'cocos2d::ResourceData getRenderFile()')
cls.func(nil, 'bool init(const std::string &imageFileName, @optional cocos2d::ui::Widget::TextureResType texType)')
cls.prop('scale9Enabled', nil, nil)
cls.prop('capInsets', nil, nil)
cls.prop('blendFunc', nil, nil)
cls.prop('renderFile', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::EditBoxDelegate::EditBoxEndAction'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('UNKNOWN', 'cocos2d::ui::EditBoxDelegate::EditBoxEndAction::UNKNOWN')
cls.enum('TAB_TO_NEXT', 'cocos2d::ui::EditBoxDelegate::EditBoxEndAction::TAB_TO_NEXT')
cls.enum('TAB_TO_PREVIOUS', 'cocos2d::ui::EditBoxDelegate::EditBoxEndAction::TAB_TO_PREVIOUS')
cls.enum('RETURN', 'cocos2d::ui::EditBoxDelegate::EditBoxEndAction::RETURN')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::EditBoxDelegate'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'void editBoxEditingDidBegin(cocos2d::ui::EditBox *)')
cls.func(nil, 'void editBoxTextChanged(cocos2d::ui::EditBox *, const std::string &)')
cls.func(nil, 'void editBoxReturn(cocos2d::ui::EditBox *editBox)')
cls.func(nil, 'void editBoxEditingDidEndWithAction(cocos2d::ui::EditBox *, cocos2d::ui::EditBoxDelegate::EditBoxEndAction )')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::LuaEditBoxDelegate'
cls.SUPERCLS = 'cocos2d::ui::EditBoxDelegate'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'LuaEditBoxDelegate()')
cls.var('onEditingDidBegin', '@nullable @local std::function<void (EditBox *)> onEditingDidBegin')
cls.var('onTextChanged', '@nullable @local std::function<void (EditBox *, const std::string &)> onTextChanged')
cls.var('onReturn', '@nullable @local std::function<void (EditBox *)> onReturn')
cls.var('onEditingDidEndWithAction', '@nullable @local std::function<void (EditBox *, EditBoxDelegate::EditBoxEndAction)> onEditingDidEndWithAction')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::EditBox::KeyboardReturnType'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('DEFAULT', 'cocos2d::ui::EditBox::KeyboardReturnType::DEFAULT')
cls.enum('DONE', 'cocos2d::ui::EditBox::KeyboardReturnType::DONE')
cls.enum('SEND', 'cocos2d::ui::EditBox::KeyboardReturnType::SEND')
cls.enum('SEARCH', 'cocos2d::ui::EditBox::KeyboardReturnType::SEARCH')
cls.enum('GO', 'cocos2d::ui::EditBox::KeyboardReturnType::GO')
cls.enum('NEXT', 'cocos2d::ui::EditBox::KeyboardReturnType::NEXT')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::EditBox::InputMode'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('ANY', 'cocos2d::ui::EditBox::InputMode::ANY')
cls.enum('EMAIL_ADDRESS', 'cocos2d::ui::EditBox::InputMode::EMAIL_ADDRESS')
cls.enum('NUMERIC', 'cocos2d::ui::EditBox::InputMode::NUMERIC')
cls.enum('PHONE_NUMBER', 'cocos2d::ui::EditBox::InputMode::PHONE_NUMBER')
cls.enum('URL', 'cocos2d::ui::EditBox::InputMode::URL')
cls.enum('DECIMAL', 'cocos2d::ui::EditBox::InputMode::DECIMAL')
cls.enum('SINGLE_LINE', 'cocos2d::ui::EditBox::InputMode::SINGLE_LINE')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::EditBox::InputFlag'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('PASSWORD', 'cocos2d::ui::EditBox::InputFlag::PASSWORD')
cls.enum('SENSITIVE', 'cocos2d::ui::EditBox::InputFlag::SENSITIVE')
cls.enum('INITIAL_CAPS_WORD', 'cocos2d::ui::EditBox::InputFlag::INITIAL_CAPS_WORD')
cls.enum('INITIAL_CAPS_SENTENCE', 'cocos2d::ui::EditBox::InputFlag::INITIAL_CAPS_SENTENCE')
cls.enum('INITIAL_CAPS_ALL_CHARACTERS', 'cocos2d::ui::EditBox::InputFlag::INITIAL_CAPS_ALL_CHARACTERS')
cls.enum('LOWERCASE_ALL_CHARACTERS', 'cocos2d::ui::EditBox::InputFlag::LOWERCASE_ALL_CHARACTERS')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::EditBox'
cls.SUPERCLS = 'cocos2d::ui::Widget'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::ui::EditBox *create(const cocos2d::Size &size, cocos2d::ui::Scale9Sprite *normalSprite, @optional cocos2d::ui::Scale9Sprite *pressedSprite, @optional cocos2d::ui::Scale9Sprite *disabledSprite)', 'static cocos2d::ui::EditBox *create(const cocos2d::Size &size, const std::string &normalImage, cocos2d::ui::Widget::TextureResType texType)', 'static cocos2d::ui::EditBox *create(const cocos2d::Size &size, const std::string &normalImage, @optional const std::string &pressedImage, @optional const std::string &disabledImage, @optional cocos2d::ui::Widget::TextureResType texType)')
cls.func(nil, 'EditBox()')
cls.func(nil, 'bool initWithSizeAndBackgroundSprite(const cocos2d::Size &size, const std::string &normal9SpriteBg, @optional cocos2d::ui::Widget::TextureResType texType)', 'bool initWithSizeAndBackgroundSprite(const cocos2d::Size &size, cocos2d::ui::Scale9Sprite *normal9SpriteBg)', 'bool initWithSizeAndBackgroundSprite(const cocos2d::Size &size, cocos2d::ui::Scale9Sprite *normalSprite, cocos2d::ui::Scale9Sprite *pressedSprite, cocos2d::ui::Scale9Sprite *disabledSprite)')
cls.func(nil, 'bool initWithSizeAndTexture(const cocos2d::Size &size, const std::string &normalImage, @optional const std::string &pressedImage, @optional const std::string &disabledImage, @optional cocos2d::ui::Widget::TextureResType texType)')
cls.func(nil, 'void loadTextures(const std::string &normal, const std::string &pressed, @optional const std::string &disabled, @optional cocos2d::ui::Widget::TextureResType texType)')
cls.func(nil, 'void loadTextureNormal(const std::string &normal, @optional cocos2d::ui::Widget::TextureResType texType)')
cls.func(nil, 'void loadTexturePressed(const std::string &pressed, @optional cocos2d::ui::Widget::TextureResType texType)')
cls.func(nil, 'void loadTextureDisabled(const std::string &disabled, @optional cocos2d::ui::Widget::TextureResType texType)')
cls.func(nil, 'void setCapInsets(const cocos2d::Rect &capInsets)')
cls.func(nil, 'void setCapInsetsNormalRenderer(const cocos2d::Rect &capInsets)')
cls.func(nil, 'const cocos2d::Rect &getCapInsetsNormalRenderer()')
cls.func(nil, 'void setCapInsetsPressedRenderer(const cocos2d::Rect &capInsets)')
cls.func(nil, 'const cocos2d::Rect &getCapInsetsPressedRenderer()')
cls.func(nil, 'void setCapInsetsDisabledRenderer(const cocos2d::Rect &capInsets)')
cls.func(nil, 'const cocos2d::Rect &getCapInsetsDisabledRenderer()')
cls.func(nil, 'void setDelegate(@addref(delegate ^) cocos2d::ui::EditBoxDelegate *delegate)')
cls.func(nil, '@addref(delegate ^) cocos2d::ui::EditBoxDelegate *getDelegate()')
cls.func(nil, 'void setText(const char *pText)')
cls.func(nil, 'const char *getText()')
cls.func(nil, 'void setFont(const char *pFontName, int fontSize)')
cls.func(nil, 'void setFontName(const char *pFontName)')
cls.func(nil, 'const char *getFontName()')
cls.func(nil, 'void setFontSize(int fontSize)')
cls.func(nil, 'int getFontSize()')
cls.func(nil, 'void setFontColor(const cocos2d::Color3B &color)', 'void setFontColor(const cocos2d::Color4B &color)')
cls.func(nil, 'const cocos2d::Color4B &getFontColor()')
cls.func(nil, 'void setPlaceholderFont(const char *pFontName, int fontSize)')
cls.func(nil, 'void setPlaceholderFontName(const char *pFontName)')
cls.func(nil, 'const char *getPlaceholderFontName()')
cls.func(nil, 'void setPlaceholderFontSize(int fontSize)')
cls.func(nil, 'int getPlaceholderFontSize()')
cls.func(nil, 'void setPlaceholderFontColor(const cocos2d::Color3B &color)', 'void setPlaceholderFontColor(const cocos2d::Color4B &color)')
cls.func(nil, 'const cocos2d::Color4B &getPlaceholderFontColor()')
cls.func(nil, 'void setPlaceHolder(const char *pText)')
cls.func(nil, 'const char *getPlaceHolder()')
cls.func(nil, 'void setInputMode(cocos2d::ui::EditBox::InputMode inputMode)')
cls.func(nil, 'cocos2d::ui::EditBox::InputMode getInputMode()')
cls.func(nil, 'void setMaxLength(int maxLength)')
cls.func(nil, 'int getMaxLength()')
cls.func(nil, 'void setInputFlag(cocos2d::ui::EditBox::InputFlag inputFlag)')
cls.func(nil, 'cocos2d::ui::EditBox::InputFlag getInputFlag()')
cls.func(nil, 'void setReturnType(cocos2d::ui::EditBox::KeyboardReturnType returnType)')
cls.func(nil, 'cocos2d::ui::EditBox::KeyboardReturnType getReturnType()')
cls.func(nil, 'void setTextHorizontalAlignment(cocos2d::TextHAlignment alignment)')
cls.func(nil, 'cocos2d::TextHAlignment getTextHorizontalAlignment()')
cls.func(nil, 'void openKeyboard()')
cls.prop('capInsetsNormalRenderer', nil, nil)
cls.prop('capInsetsPressedRenderer', nil, nil)
cls.prop('capInsetsDisabledRenderer', nil, nil)
cls.prop('delegate', nil, nil)
cls.prop('text', nil, nil)
cls.prop('fontName', nil, nil)
cls.prop('fontSize', nil, nil)
cls.prop('fontColor', nil, nil)
cls.prop('placeholderFontName', nil, nil)
cls.prop('placeholderFontSize', nil, nil)
cls.prop('placeholderFontColor', nil, nil)
cls.prop('placeHolder', nil, nil)
cls.prop('inputMode', nil, nil)
cls.prop('maxLength', nil, nil)
cls.prop('inputFlag', nil, nil)
cls.prop('returnType', nil, nil)
cls.prop('textHorizontalAlignment', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

return M
