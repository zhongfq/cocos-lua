-- AUTO BUILD, DON'T MODIFY!

require "autobuild.cocos2d-ui-types"

local olua = require "olua"
local typeconv = olua.typeconv
local typecls = olua.typecls
local cls = nil
local M = {}

M.NAME = "cocos2d_ui"
M.PATH = "../../frameworks/libxgame/src/lua-bindings"
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
M.CHUNK = [[

]]

M.CONVS = {
}

M.CLASSES = {}

cls = typecls 'cocos2d::ui::Widget::FocusDirection'
cls.enums [[
    LEFT
    RIGHT
    UP
    DOWN
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::Widget::PositionType'
cls.enums [[
    ABSOLUTE
    PERCENT
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::Widget::SizeType'
cls.enums [[
    ABSOLUTE
    PERCENT
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::Widget::TouchEventType'
cls.enums [[
    BEGAN
    MOVED
    ENDED
    CANCELED
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::Widget::TextureResType'
cls.enums [[
    LOCAL
    PLIST
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::Widget::BrightStyle'
cls.enums [[
    NONE
    NORMAL
    HIGHLIGHT
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::Widget'
cls.SUPERCLS = "cocos2d::ProtectedNode"
cls.funcs [[
    Widget()
    static cocos2d::ui::Widget *create()
    void setEnabled(bool enabled)
    bool isEnabled()
    void setBright(bool bright)
    bool isBright()
    void setTouchEnabled(bool enabled)
    void setBrightStyle(cocos2d::ui::Widget::BrightStyle style)
    bool isTouchEnabled()
    bool isHighlighted()
    void setHighlighted(bool highlight)
    float getLeftBoundary()
    float getBottomBoundary()
    float getRightBoundary()
    float getTopBoundary()
    void setPositionPercent(const cocos2d::Vec2 &percent)
    const cocos2d::Vec2 &getPositionPercent()
    void setPositionType(cocos2d::ui::Widget::PositionType type)
    cocos2d::ui::Widget::PositionType getPositionType()
    void setFlippedX(bool flippedX)
    bool isFlippedX()
    void setFlippedY(bool flippedY)
    bool isFlippedY()
    bool isClippingParentContainsPoint(const cocos2d::Vec2 &pt)
    const cocos2d::Vec2 &getTouchBeganPosition()
    const cocos2d::Vec2 &getTouchMovePosition()
    const cocos2d::Vec2 &getTouchEndPosition()
    void setSizePercent(const cocos2d::Vec2 &percent)
    void setSizeType(cocos2d::ui::Widget::SizeType type)
    cocos2d::ui::Widget::SizeType getSizeType()
    const cocos2d::Size &getCustomSize()
    const cocos2d::Size &getLayoutSize()
    const cocos2d::Vec2 &getSizePercent()
    bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unusedEvent)
    void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unusedEvent)
    void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unusedEvent)
    void onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event *unusedEvent)
    void setLayoutParameter(cocos2d::ui::LayoutParameter *parameter)
    cocos2d::ui::LayoutParameter *getLayoutParameter()
    void ignoreContentAdaptWithSize(bool ignore)
    bool isIgnoreContentAdaptWithSize()
    cocos2d::Vec2 getWorldPosition()
    @addref(protectedChildren |) cocos2d::Node *getVirtualRenderer()
    cocos2d::Size getVirtualRendererSize()
    cocos2d::ui::Widget *clone()
    void updateSizeAndPosition()
    void updateSizeAndPosition(const cocos2d::Size &parentSize)
    void setActionTag(int tag)
    int getActionTag()
    void setPropagateTouchEvents(bool isPropagate)
    bool isPropagateTouchEvents()
    void setSwallowTouches(bool swallow)
    bool isSwallowTouches()
    bool isFocused()
    void setFocused(bool focus)
    bool isFocusEnabled()
    void setFocusEnabled(bool enable)
    cocos2d::ui::Widget *findNextFocusedWidget(cocos2d::ui::Widget::FocusDirection direction, cocos2d::ui::Widget *current)
    void requestFocus()
    static cocos2d::ui::Widget *getCurrentFocusedWidget()
    static void enableDpadNavigation(bool enable)
    void setUnifySizeEnabled(bool enable)
    bool isUnifySizeEnabled()
    void setCallbackName(const std::string &callbackName)
    const std::string &getCallbackName()
    void setCallbackType(const std::string &callbackType)
    const std::string &getCallbackType()
    void setLayoutComponentEnabled(bool enable)
    bool isLayoutComponentEnabled()
    void interceptTouchEvent(cocos2d::ui::Widget::TouchEventType event, cocos2d::ui::Widget *sender, cocos2d::Touch *touch)
    void propagateTouchEvent(cocos2d::ui::Widget::TouchEventType event, cocos2d::ui::Widget *sender, cocos2d::Touch *touch)
    void onFocusChange(cocos2d::ui::Widget *widgetLostFocus, cocos2d::ui::Widget *widgetGetFocus)
    void dispatchFocusEvent(cocos2d::ui::Widget *widgetLoseFocus, cocos2d::ui::Widget *widgetGetFocus)
]]
cls.var('onFocusChanged', [[@nullable std::function<void (Widget *, Widget *)> onFocusChanged]])
cls.var('onNextFocusedWidget', [[@nullable @local std::function<Widget *(FocusDirection)> onNextFocusedWidget]])
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
cls.props [[
    enabled
    bright
    touchEnabled
    highlighted
    leftBoundary
    bottomBoundary
    rightBoundary
    topBoundary
    positionPercent
    positionType
    flippedX
    flippedY
    touchBeganPosition
    touchMovePosition
    touchEndPosition
    sizeType
    customSize
    layoutSize
    sizePercent
    layoutParameter
    ignoreContentAdaptWithSize
    worldPosition
    virtualRenderer
    virtualRendererSize
    actionTag
    propagateTouchEvents
    swallowTouches
    focused
    focusEnabled
    currentFocusedWidget
    unifySizeEnabled
    callbackName
    callbackType
    layoutComponentEnabled
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::Helper'
cls.funcs [[
    static cocos2d::ui::Widget *seekWidgetByTag(cocos2d::ui::Widget *root, int tag)
    static cocos2d::ui::Widget *seekWidgetByName(cocos2d::ui::Widget *root, const std::string &name)
    static cocos2d::ui::Widget *seekActionWidgetByActionTag(cocos2d::ui::Widget *root, int tag)
    static std::string getSubStringOfUTF8String(const std::string &str, std::string::size_type start, std::string::size_type length)
    static void doLayout(cocos2d::Node *rootNode)
    static void changeLayoutSystemActiveState(bool active)
    static cocos2d::Rect restrictCapInsetRect(const cocos2d::Rect &capInsets, const cocos2d::Size &textureSize)
    static cocos2d::Rect convertBoundingBoxToScreen(cocos2d::Node *node)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::Scale9Sprite::State'
cls.enums [[
    NORMAL
    GRAY
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::Scale9Sprite::RenderingType'
cls.enums [[
    SIMPLE
    SLICE
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::Scale9Sprite'
cls.SUPERCLS = "cocos2d::Sprite"
cls.funcs [[
    Scale9Sprite()
    static cocos2d::ui::Scale9Sprite *create()
    static cocos2d::ui::Scale9Sprite *create(const std::string &file, const cocos2d::Rect &rect, const cocos2d::Rect &capInsets)
    static cocos2d::ui::Scale9Sprite *create(const cocos2d::Rect &capInsets, const std::string &file)
    static cocos2d::ui::Scale9Sprite *create(const std::string &file, const cocos2d::Rect &rect)
    static cocos2d::ui::Scale9Sprite *create(const std::string &file)
    static cocos2d::ui::Scale9Sprite *createWithSpriteFrame(cocos2d::SpriteFrame *spriteFrame)
    static cocos2d::ui::Scale9Sprite *createWithSpriteFrame(cocos2d::SpriteFrame *spriteFrame, const cocos2d::Rect &capInsets)
    static cocos2d::ui::Scale9Sprite *createWithSpriteFrameName(const std::string &spriteFrameName)
    static cocos2d::ui::Scale9Sprite *createWithSpriteFrameName(const std::string &spriteFrameName, const cocos2d::Rect &capInsets)
    bool initWithFile(const std::string &file, const cocos2d::Rect &rect, const cocos2d::Rect &capInsets)
    bool initWithFile(const cocos2d::Rect &capInsets, const std::string &file)
    bool initWithSpriteFrame(cocos2d::SpriteFrame *spriteFrame, const cocos2d::Rect &capInsets)
    bool initWithSpriteFrameName(const std::string &spriteFrameName, const cocos2d::Rect &capInsets)
    bool init(cocos2d::Sprite *sprite, const cocos2d::Rect &rect, bool rotated, const cocos2d::Rect &capInsets)
    bool init(cocos2d::Sprite *sprite, const cocos2d::Rect &rect, const cocos2d::Rect &capInsets)
    bool init(cocos2d::Sprite *sprite, const cocos2d::Rect &rect, bool rotated, const cocos2d::Vec2 &offset, const cocos2d::Size &originalSize, const cocos2d::Rect &capInsets)
    cocos2d::ui::Scale9Sprite *resizableSpriteWithCapInsets(const cocos2d::Rect &capInsets)
    bool updateWithSprite(cocos2d::Sprite *sprite, const cocos2d::Rect &rect, bool rotated, const cocos2d::Rect &capInsets)
    bool updateWithSprite(cocos2d::Sprite *sprite, const cocos2d::Rect &rect, bool rotated, const cocos2d::Vec2 &offset, const cocos2d::Size &originalSize, const cocos2d::Rect &capInsets)
    void setSpriteFrame(cocos2d::SpriteFrame *spriteFrame, const cocos2d::Rect &capInsets)
    void setState(cocos2d::ui::Scale9Sprite::State state)
    cocos2d::ui::Scale9Sprite::State getState()
    cocos2d::Size getOriginalSize()
    void setPreferredSize(const cocos2d::Size &size)
    cocos2d::Size getPreferredSize()
    void setInsetLeft(float leftInset)
    float getInsetLeft()
    void setInsetTop(float topInset)
    float getInsetTop()
    void setInsetRight(float rightInset)
    float getInsetRight()
    void setInsetBottom(float bottomInset)
    float getInsetBottom()
    void setScale9Enabled(bool enabled)
    bool isScale9Enabled()
    cocos2d::Sprite *getSprite()
    void copyTo(cocos2d::ui::Scale9Sprite *copy)
    void setRenderingType(cocos2d::ui::Scale9Sprite::RenderingType type)
    cocos2d::ui::Scale9Sprite::RenderingType getRenderingType()
    void setCapInsets(const cocos2d::Rect &insets)
    cocos2d::Rect getCapInsets()
    void resetRender()
]]
cls.props [[
    state
    originalSize
    preferredSize
    insetLeft
    insetTop
    insetRight
    insetBottom
    scale9Enabled
    sprite
    renderingType
    capInsets
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::LayoutComponent::HorizontalEdge'
cls.enums [[
    None
    Left
    Right
    Center
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::LayoutComponent::VerticalEdge'
cls.enums [[
    None
    Bottom
    Top
    Center
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::LayoutComponent'
cls.SUPERCLS = "cocos2d::Component"
cls.funcs [[
    LayoutComponent()
    static cocos2d::ui::LayoutComponent *create()
    static cocos2d::ui::LayoutComponent *bindLayoutComponent(cocos2d::Node *node)
    void setUsingPercentContentSize(bool isUsed)
    bool getUsingPercentContentSize()
    void setPercentContentSize(const cocos2d::Vec2 &percent)
    cocos2d::Vec2 getPercentContentSize()
    const cocos2d::Point &getAnchorPosition()
    void setAnchorPosition(const cocos2d::Point &point)
    const cocos2d::Point &getPosition()
    void setPosition(const cocos2d::Point &position)
    bool isPositionPercentXEnabled()
    void setPositionPercentXEnabled(bool isUsed)
    float getPositionPercentX()
    void setPositionPercentX(float percentMargin)
    bool isPositionPercentYEnabled()
    void setPositionPercentYEnabled(bool isUsed)
    float getPositionPercentY()
    void setPositionPercentY(float percentMargin)
    cocos2d::ui::LayoutComponent::HorizontalEdge getHorizontalEdge()
    void setHorizontalEdge(cocos2d::ui::LayoutComponent::HorizontalEdge hEage)
    cocos2d::ui::LayoutComponent::VerticalEdge getVerticalEdge()
    void setVerticalEdge(cocos2d::ui::LayoutComponent::VerticalEdge vEage)
    float getLeftMargin()
    void setLeftMargin(float margin)
    float getRightMargin()
    void setRightMargin(float margin)
    float getTopMargin()
    void setTopMargin(float margin)
    float getBottomMargin()
    void setBottomMargin(float margin)
    const cocos2d::Size &getSize()
    void setSize(const cocos2d::Size &size)
    bool isPercentWidthEnabled()
    void setPercentWidthEnabled(bool isUsed)
    float getSizeWidth()
    void setSizeWidth(float width)
    float getPercentWidth()
    void setPercentWidth(float percentWidth)
    bool isPercentHeightEnabled()
    void setPercentHeightEnabled(bool isUsed)
    float getSizeHeight()
    void setSizeHeight(float height)
    float getPercentHeight()
    void setPercentHeight(float percentHeight)
    bool isStretchWidthEnabled()
    void setStretchWidthEnabled(bool isUsed)
    bool isStretchHeightEnabled()
    void setStretchHeightEnabled(bool isUsed)
    void setPercentOnlyEnabled(bool enable)
    void setActiveEnabled(bool enable)
    void refreshLayout()
]]
cls.props [[
    usingPercentContentSize
    percentContentSize
    anchorPosition
    position
    positionPercentXEnabled
    positionPercentX
    positionPercentYEnabled
    positionPercentY
    horizontalEdge
    verticalEdge
    leftMargin
    rightMargin
    topMargin
    bottomMargin
    size
    percentWidthEnabled
    sizeWidth
    percentWidth
    percentHeightEnabled
    sizeHeight
    percentHeight
    stretchWidthEnabled
    stretchHeightEnabled
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::LayoutParameter::Type'
cls.enums [[
    NONE
    LINEAR
    RELATIVE
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::LayoutParameter'
cls.SUPERCLS = "cocos2d::Ref"
cls.funcs [[
    LayoutParameter()
    static cocos2d::ui::LayoutParameter *create()
    void setMargin(const cocos2d::ui::Margin &margin)
    const cocos2d::ui::Margin &getMargin()
    cocos2d::ui::LayoutParameter::Type getLayoutType()
    cocos2d::ui::LayoutParameter *clone()
    cocos2d::ui::LayoutParameter *createCloneInstance()
    void copyProperties(cocos2d::ui::LayoutParameter *model)
]]
cls.props [[
    margin
    layoutType
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::LinearLayoutParameter::LinearGravity'
cls.enums [[
    NONE
    LEFT
    TOP
    RIGHT
    BOTTOM
    CENTER_VERTICAL
    CENTER_HORIZONTAL
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::LinearLayoutParameter'
cls.SUPERCLS = "cocos2d::ui::LayoutParameter"
cls.funcs [[
    LinearLayoutParameter()
    static cocos2d::ui::LinearLayoutParameter *create()
    void setGravity(cocos2d::ui::LinearLayoutParameter::LinearGravity gravity)
    cocos2d::ui::LinearLayoutParameter::LinearGravity getGravity()
]]
cls.props [[
    gravity
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::RelativeLayoutParameter::RelativeAlign'
cls.enums [[
    NONE
    PARENT_TOP_LEFT
    PARENT_TOP_CENTER_HORIZONTAL
    PARENT_TOP_RIGHT
    PARENT_LEFT_CENTER_VERTICAL
    CENTER_IN_PARENT
    PARENT_RIGHT_CENTER_VERTICAL
    PARENT_LEFT_BOTTOM
    PARENT_BOTTOM_CENTER_HORIZONTAL
    PARENT_RIGHT_BOTTOM
    LOCATION_ABOVE_LEFTALIGN
    LOCATION_ABOVE_CENTER
    LOCATION_ABOVE_RIGHTALIGN
    LOCATION_LEFT_OF_TOPALIGN
    LOCATION_LEFT_OF_CENTER
    LOCATION_LEFT_OF_BOTTOMALIGN
    LOCATION_RIGHT_OF_TOPALIGN
    LOCATION_RIGHT_OF_CENTER
    LOCATION_RIGHT_OF_BOTTOMALIGN
    LOCATION_BELOW_LEFTALIGN
    LOCATION_BELOW_CENTER
    LOCATION_BELOW_RIGHTALIGN
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::RelativeLayoutParameter'
cls.SUPERCLS = "cocos2d::ui::LayoutParameter"
cls.funcs [[
    RelativeLayoutParameter()
    static cocos2d::ui::RelativeLayoutParameter *create()
    void setAlign(cocos2d::ui::RelativeLayoutParameter::RelativeAlign align)
    cocos2d::ui::RelativeLayoutParameter::RelativeAlign getAlign()
    void setRelativeToWidgetName(const std::string &name)
    const std::string &getRelativeToWidgetName()
    void setRelativeName(const std::string &name)
    const std::string &getRelativeName()
]]
cls.props [[
    align
    relativeToWidgetName
    relativeName
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::Layout::Type'
cls.enums [[
    ABSOLUTE
    VERTICAL
    HORIZONTAL
    RELATIVE
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::Layout::ClippingType'
cls.enums [[
    STENCIL
    SCISSOR
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::Layout::BackGroundColorType'
cls.enums [[
    NONE
    SOLID
    GRADIENT
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::Layout'
cls.SUPERCLS = "cocos2d::ui::Widget"
cls.funcs [[
    static cocos2d::Ref *createInstance()
    Layout()
    static cocos2d::ui::Layout *create()
    void setBackGroundImage(const std::string &fileName, @optional cocos2d::ui::Widget::TextureResType texType)
    void setBackGroundImageCapInsets(const cocos2d::Rect &capInsets)
    const cocos2d::Rect &getBackGroundImageCapInsets()
    void setBackGroundColorType(cocos2d::ui::Layout::BackGroundColorType type)
    cocos2d::ui::Layout::BackGroundColorType getBackGroundColorType()
    void setBackGroundImageScale9Enabled(bool enabled)
    bool isBackGroundImageScale9Enabled()
    void setBackGroundColor(const cocos2d::Color3B &color)
    const cocos2d::Color3B &getBackGroundColor()
    void setBackGroundColor(const cocos2d::Color3B &startColor, const cocos2d::Color3B &endColor)
    const cocos2d::Color3B &getBackGroundStartColor()
    const cocos2d::Color3B &getBackGroundEndColor()
    void setBackGroundColorOpacity(uint8_t opacity)
    uint8_t getBackGroundColorOpacity()
    void setBackGroundColorVector(const cocos2d::Vec2 &vector)
    const cocos2d::Vec2 &getBackGroundColorVector()
    void setBackGroundImageColor(const cocos2d::Color3B &color)
    void setBackGroundImageOpacity(uint8_t opacity)
    const cocos2d::Color3B &getBackGroundImageColor()
    uint8_t getBackGroundImageOpacity()
    void removeBackGroundImage()
    const cocos2d::Size &getBackGroundImageTextureSize()
    void setClippingEnabled(bool enabled)
    void setClippingType(cocos2d::ui::Layout::ClippingType type)
    cocos2d::ui::Layout::ClippingType getClippingType()
    bool isClippingEnabled()
    void setLayoutType(cocos2d::ui::Layout::Type type)
    cocos2d::ui::Layout::Type getLayoutType()
    void forceDoLayout()
    void requestDoLayout()
    void setLoopFocus(bool loop)
    bool isLoopFocus()
    void setPassFocusToChild(bool pass)
    bool isPassFocusToChild()
    cocos2d::ResourceData getRenderFile()
]]
cls.var('onPassFocusToChild', [[@nullable std::function<int (FocusDirection, Widget *)> onPassFocusToChild]])
cls.props [[
    backGroundImageCapInsets
    backGroundColorType
    backGroundImageScale9Enabled
    backGroundColor
    backGroundStartColor
    backGroundEndColor
    backGroundColorOpacity
    backGroundColorVector
    backGroundImageColor
    backGroundImageOpacity
    backGroundImageTextureSize
    clippingType
    clippingEnabled
    layoutType
    loopFocus
    passFocusToChild
    renderFile
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::HBox'
cls.SUPERCLS = "cocos2d::ui::Layout"
cls.funcs [[
    HBox()
    static cocos2d::ui::HBox *create()
    static cocos2d::ui::HBox *create(const cocos2d::Size &size)
    bool initWithSize(const cocos2d::Size &size)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::VBox'
cls.SUPERCLS = "cocos2d::ui::Layout"
cls.funcs [[
    VBox()
    static cocos2d::ui::VBox *create()
    static cocos2d::ui::VBox *create(const cocos2d::Size &size)
    bool initWithSize(const cocos2d::Size &size)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::RelativeBox'
cls.SUPERCLS = "cocos2d::ui::Layout"
cls.funcs [[
    RelativeBox()
    static cocos2d::ui::RelativeBox *create()
    static cocos2d::ui::RelativeBox *create(const cocos2d::Size &size)
    bool initWithSize(const cocos2d::Size &size)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::WebView'
cls.SUPERCLS = "cocos2d::ui::Widget"
cls.DEFIF = "#ifdef CCLUA_HAVE_WEBVIEW"
cls.funcs [[
    static cocos2d::ui::WebView *create()
    void setJavascriptInterfaceScheme(const std::string &scheme)
    void loadData(const cocos2d::Data &data, const std::string &MIMEType, const std::string &encoding, const std::string &baseURL)
    void loadHTMLString(const std::string &string, @optional const std::string &baseURL)
    void loadURL(const std::string &url)
    void loadURL(const std::string &url, bool cleanCachedData)
    void loadFile(const std::string &fileName)
    void stopLoading()
    void reload()
    bool canGoBack()
    bool canGoForward()
    void goBack()
    void goForward()
    void evaluateJS(const std::string &js)
    void setScalesPageToFit(const bool scalesPageToFit)
    void setBounces(bool bounce)
    void setOpacityWebView(float opacity)
    float getOpacityWebView()
    void setBackgroundTransparent()
    WebView()
]]
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
cls.props [[
    opacityWebView
    onShouldStartLoading
    onDidFinishLoading
    onDidFailLoading
    onJSCallback
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::VideoPlayer::EventType'
cls.DEFIF = "#ifdef CCLUA_HAVE_VIDEOPLAYER"
cls.enums [[
    PLAYING
    PAUSED
    STOPPED
    COMPLETED
    ERROR
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::VideoPlayer::StyleType'
cls.DEFIF = "#ifdef CCLUA_HAVE_VIDEOPLAYER"
cls.enums [[
    DEFAULT
    NONE
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::VideoPlayer'
cls.SUPERCLS = "cocos2d::ui::Widget"
cls.DEFIF = "#ifdef CCLUA_HAVE_VIDEOPLAYER"
cls.funcs [[
    static cocos2d::ui::VideoPlayer *create()
    void setFileName(const std::string &videoPath)
    const std::string &getFileName()
    void setURL(const std::string &_videoURL)
    const std::string &getURL()
    void setLooping(bool looping)
    void setUserInputEnabled(bool enableInput)
    void setStyle(cocos2d::ui::VideoPlayer::StyleType style)
    void play()
    void stop()
    void seekTo(float sec)
    bool isPlaying()
    bool isLooping()
    bool isUserInputEnabled()
    void setKeepAspectRatioEnabled(bool enable)
    bool isKeepAspectRatioEnabled()
    void setFullScreenEnabled(bool fullscreen)
    bool isFullScreenEnabled()
    void onPlayEvent(int event)
    VideoPlayer()
]]
cls.callback {
    FUNCS =  {
        'void addEventListener(@nullable const std::function<void (Ref *, VideoPlayer::EventType)> &callback)'
    },
    TAG_MAKER = 'videoPlayerCallback',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.props [[
    fileName
    url
    playing
    looping
    userInputEnabled
    keepAspectRatioEnabled
    fullScreenEnabled
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::AbstractCheckButton'
cls.SUPERCLS = "cocos2d::ui::Widget"
cls.funcs [[
    void loadTextures(const std::string &background, const std::string &backgroundSelected, const std::string &cross, const std::string &backgroundDisabled, const std::string &frontCrossDisabled, @optional cocos2d::ui::Widget::TextureResType texType)
    void loadTextureBackGround(const std::string &backGround, @optional cocos2d::ui::Widget::TextureResType type)
    void loadTextureBackGroundSelected(const std::string &backGroundSelected, @optional cocos2d::ui::Widget::TextureResType texType)
    void loadTextureFrontCross(const std::string &crossTextureName, @optional cocos2d::ui::Widget::TextureResType texType)
    void loadTextureBackGroundDisabled(const std::string &backGroundDisabled, @optional cocos2d::ui::Widget::TextureResType texType)
    void loadTextureFrontCrossDisabled(const std::string &frontCrossDisabled, @optional cocos2d::ui::Widget::TextureResType texType)
    bool isSelected()
    void setSelected(bool selected)
    void setZoomScale(float scale)
    float getZoomScale()
    @addref(protectedChildren |) cocos2d::Sprite *getRendererBackground()
    @addref(protectedChildren |) cocos2d::Sprite *getRendererBackgroundSelected()
    @addref(protectedChildren |) cocos2d::Sprite *getRendererFrontCross()
    @addref(protectedChildren |) cocos2d::Sprite *getRendererBackgroundDisabled()
    @addref(protectedChildren |) cocos2d::Sprite *getRendererFrontCrossDisabled()
    cocos2d::ResourceData getBackNormalFile()
    cocos2d::ResourceData getBackPressedFile()
    cocos2d::ResourceData getBackDisabledFile()
    cocos2d::ResourceData getCrossNormalFile()
    cocos2d::ResourceData getCrossDisabledFile()
    bool init(const std::string &backGround, const std::string &backGroundSelected, const std::string &cross, const std::string &backGroundDisabled, const std::string &frontCrossDisabled, @optional cocos2d::ui::Widget::TextureResType texType)
]]
cls.props [[
    selected
    zoomScale
    rendererBackground
    rendererBackgroundSelected
    rendererFrontCross
    rendererBackgroundDisabled
    rendererFrontCrossDisabled
    backNormalFile
    backPressedFile
    backDisabledFile
    crossNormalFile
    crossDisabledFile
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::TabHeader::EventType'
cls.enums [[
    SELECTED
    UNSELECTED
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::TabHeader'
cls.SUPERCLS = "cocos2d::ui::AbstractCheckButton"
cls.funcs [[
    static cocos2d::ui::TabHeader *create()
    static cocos2d::ui::TabHeader *create(const std::string &titleStr, const std::string &backGround, const std::string &cross, @optional cocos2d::ui::Widget::TextureResType texType)
    static cocos2d::ui::TabHeader *create(const std::string &titleStr, const std::string &backGround, const std::string &backGroundSelected, const std::string &cross, const std::string &backGroundDisabled, const std::string &frontCrossDisabled, @optional cocos2d::ui::Widget::TextureResType texType)
    @addref(protectedChildren |) cocos2d::Label *getTitleRenderer()
    void setTitleText(const std::string &text)
    std::string getTitleText()
    void setTitleColor(const cocos2d::Color4B &color)
    const cocos2d::Color4B &getTitleColor()
    void setTitleFontSize(float size)
    float getTitleFontSize()
    void setTitleFontName(const std::string &fontName)
    std::string getTitleFontName()
    int getIndexInTabControl()
]]
cls.props [[
    titleRenderer
    titleText
    titleColor
    titleFontSize
    titleFontName
    indexInTabControl
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::TabControl::Dock'
cls.enums [[
    TOP
    LEFT
    BOTTOM
    RIGHT
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::TabControl::EventType'
cls.enums [[
    SELECT_CHANGED
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::TabControl'
cls.SUPERCLS = "cocos2d::ui::Widget"
cls.funcs [[
    static cocos2d::ui::TabControl *create()
    @delref(protectedChildren ~) void removeTab(int index)
    void setSelectTab(int index)
    void setSelectTab(cocos2d::ui::TabHeader *tabHeader)
    @addref(protectedChildren |) cocos2d::ui::TabHeader *getTabHeader(int index)
    @addref(protectedChildren |) cocos2d::ui::Layout *getTabContainer(int index)
    void insertTab(int index, @addref(protectedChildren |) cocos2d::ui::TabHeader *header, @addref(protectedChildren |) cocos2d::ui::Layout *container)
    size_t getTabCount()
    int getSelectedTabIndex()
    int indexOfTabHeader(const cocos2d::ui::TabHeader *tabCell)
    void setHeaderWidth(float headerWidth)
    float getHeaderWidth()
    void setHeaderHeight(float headerHeight)
    int getHeaderHeight()
    void ignoreHeadersTextureSize(bool ignore)
    bool isIgnoreHeadersTextureSize()
    void setHeaderSelectedZoom(float zoom)
    float getHeaderSelectedZoom()
    void setHeaderDockPlace(cocos2d::ui::TabControl::Dock dockPlace)
    cocos2d::ui::TabControl::Dock getHeaderDockPlace()
]]
cls.callback {
    FUNCS =  {
        'void setTabChangedEventListener(@nullable @local const std::function<void (int, EventType)> &callback)'
    },
    TAG_MAKER = 'tabChangedEventListener',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.props [[
    tabCount
    selectedTabIndex
    headerWidth
    headerHeight
    ignoreHeadersTextureSize
    headerSelectedZoom
    headerDockPlace
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::ScrollView::Direction'
cls.enums [[
    NONE
    VERTICAL
    HORIZONTAL
    BOTH
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::ScrollView::EventType'
cls.enums [[
    SCROLL_TO_TOP
    SCROLL_TO_BOTTOM
    SCROLL_TO_LEFT
    SCROLL_TO_RIGHT
    SCROLLING
    BOUNCE_TOP
    BOUNCE_BOTTOM
    BOUNCE_LEFT
    BOUNCE_RIGHT
    CONTAINER_MOVED
    SCROLLING_BEGAN
    SCROLLING_ENDED
    AUTOSCROLL_ENDED
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::ScrollView'
cls.SUPERCLS = "cocos2d::ui::Layout"
cls.funcs [[
    static cocos2d::Ref *createInstance()
    ScrollView()
    static cocos2d::ui::ScrollView *create()
    void setDirection(cocos2d::ui::ScrollView::Direction dir)
    cocos2d::ui::ScrollView::Direction getDirection()
    @addref(protectedChildren |) cocos2d::ui::Layout *getInnerContainer()
    void stopScroll()
    void stopAutoScroll()
    void stopOverallScroll()
    void scrollToBottom(float timeInSec, bool attenuated)
    void scrollToTop(float timeInSec, bool attenuated)
    void scrollToLeft(float timeInSec, bool attenuated)
    void scrollToRight(float timeInSec, bool attenuated)
    void scrollToTopLeft(float timeInSec, bool attenuated)
    void scrollToTopRight(float timeInSec, bool attenuated)
    void scrollToBottomLeft(float timeInSec, bool attenuated)
    void scrollToBottomRight(float timeInSec, bool attenuated)
    void scrollToPercentVertical(float percent, float timeInSec, bool attenuated)
    void scrollToPercentHorizontal(float percent, float timeInSec, bool attenuated)
    void scrollToPercentBothDirection(const cocos2d::Vec2 &percent, float timeInSec, bool attenuated)
    float getScrolledPercentVertical()
    float getScrolledPercentHorizontal()
    cocos2d::Vec2 getScrolledPercentBothDirection()
    void jumpToBottom()
    void jumpToTop()
    void jumpToLeft()
    void jumpToRight()
    void jumpToTopLeft()
    void jumpToTopRight()
    void jumpToBottomLeft()
    void jumpToBottomRight()
    void jumpToPercentVertical(float percent)
    void jumpToPercentHorizontal(float percent)
    void jumpToPercentBothDirection(const cocos2d::Vec2 &percent)
    void setInnerContainerSize(const cocos2d::Size &size)
    const cocos2d::Size &getInnerContainerSize()
    void setInnerContainerPosition(const cocos2d::Vec2 &pos)
    const cocos2d::Vec2 &getInnerContainerPosition()
    void setBounceEnabled(bool enabled)
    bool isBounceEnabled()
    void setInertiaScrollEnabled(bool enabled)
    bool isInertiaScrollEnabled()
    void setScrollBarEnabled(bool enabled)
    bool isScrollBarEnabled()
    void setScrollBarPositionFromCorner(const cocos2d::Vec2 &positionFromCorner)
    void setScrollBarPositionFromCornerForVertical(const cocos2d::Vec2 &positionFromCorner)
    cocos2d::Vec2 getScrollBarPositionFromCornerForVertical()
    void setScrollBarPositionFromCornerForHorizontal(const cocos2d::Vec2 &positionFromCorner)
    cocos2d::Vec2 getScrollBarPositionFromCornerForHorizontal()
    void setScrollBarWidth(float width)
    float getScrollBarWidth()
    void setScrollBarColor(const cocos2d::Color3B &color)
    const cocos2d::Color3B &getScrollBarColor()
    void setScrollBarOpacity(uint8_t opacity)
    uint8_t getScrollBarOpacity()
    void setScrollBarAutoHideEnabled(bool autoHideEnabled)
    bool isScrollBarAutoHideEnabled()
    void setScrollBarAutoHideTime(float autoHideTime)
    float getScrollBarAutoHideTime()
    void setTouchTotalTimeThreshold(float touchTotalTimeThreshold)
    float getTouchTotalTimeThreshold()
    bool isScrolling()
    bool isAutoScrolling()
]]
cls.callback {
    FUNCS =  {
        'void addEventListener(@nullable const std::function<void (Ref *, EventType)> &callback)'
    },
    TAG_MAKER = 'scrollViewCallback',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.props [[
    direction
    innerContainer
    scrolledPercentVertical
    scrolledPercentHorizontal
    scrolledPercentBothDirection
    innerContainerSize
    innerContainerPosition
    bounceEnabled
    inertiaScrollEnabled
    scrollBarEnabled
    scrollBarPositionFromCornerForVertical
    scrollBarPositionFromCornerForHorizontal
    scrollBarWidth
    scrollBarColor
    scrollBarOpacity
    scrollBarAutoHideEnabled
    scrollBarAutoHideTime
    touchTotalTimeThreshold
    scrolling
    autoScrolling
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::ListView::Gravity'
cls.enums [[
    LEFT
    RIGHT
    CENTER_HORIZONTAL
    TOP
    BOTTOM
    CENTER_VERTICAL
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::ListView::EventType'
cls.enums [[
    ON_SELECTED_ITEM_START
    ON_SELECTED_ITEM_END
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::ListView::MagneticType'
cls.enums [[
    NONE
    CENTER
    BOTH_END
    LEFT
    RIGHT
    TOP
    BOTTOM
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::ListView'
cls.SUPERCLS = "cocos2d::ui::ScrollView"
cls.funcs [[
    static cocos2d::Ref *createInstance()
    ListView()
    static cocos2d::ui::ListView *create()
    void setItemModel(cocos2d::ui::Widget *model)
    void pushBackDefaultItem()
    void insertDefaultItem(ssize_t index)
    void pushBackCustomItem(@addref(children |) cocos2d::ui::Widget *item)
    void insertCustomItem(@addref(children |) cocos2d::ui::Widget *item, ssize_t index)
    @delref(children ~) void removeLastItem()
    @delref(children ~) void removeItem(ssize_t index)
    @delref(children ~) void removeAllItems()
    @addref(children |) cocos2d::ui::Widget *getItem(ssize_t index)
    @addref(children |) Vector<cocos2d::ui::Widget *> &getItems()
    ssize_t getIndex(cocos2d::ui::Widget *item)
    void setGravity(cocos2d::ui::ListView::Gravity gravity)
    void setMagneticType(cocos2d::ui::ListView::MagneticType magneticType)
    cocos2d::ui::ListView::MagneticType getMagneticType()
    void setMagneticAllowedOutOfBoundary(bool magneticAllowedOutOfBoundary)
    bool getMagneticAllowedOutOfBoundary()
    void setItemsMargin(float margin)
    float getItemsMargin()
    void setPadding(float l, float t, float r, float b)
    void setLeftPadding(float l)
    void setTopPadding(float t)
    void setRightPadding(float r)
    void setBottomPadding(float b)
    float getLeftPadding()
    float getTopPadding()
    float getRightPadding()
    float getBottomPadding()
    void setScrollDuration(float time)
    float getScrollDuration()
    void doLayout()
    cocos2d::ui::Widget *getClosestItemToPosition(const cocos2d::Vec2 &targetPosition, const cocos2d::Vec2 &itemAnchorPoint)
    cocos2d::ui::Widget *getClosestItemToPositionInCurrentView(const cocos2d::Vec2 &positionRatioInView, const cocos2d::Vec2 &itemAnchorPoint)
    cocos2d::ui::Widget *getCenterItemInCurrentView()
    cocos2d::ui::Widget *getLeftmostItemInCurrentView()
    cocos2d::ui::Widget *getRightmostItemInCurrentView()
    cocos2d::ui::Widget *getTopmostItemInCurrentView()
    cocos2d::ui::Widget *getBottommostItemInCurrentView()
    void jumpToItem(ssize_t itemIndex, const cocos2d::Vec2 &positionRatioInView, const cocos2d::Vec2 &itemAnchorPoint)
    void scrollToItem(ssize_t itemIndex, const cocos2d::Vec2 &positionRatioInView, const cocos2d::Vec2 &itemAnchorPoint)
    void scrollToItem(ssize_t itemIndex, const cocos2d::Vec2 &positionRatioInView, const cocos2d::Vec2 &itemAnchorPoint, float timeInSec)
    ssize_t getCurSelectedIndex()
    void setCurSelectedIndex(int itemIndex)
]]
cls.callback {
    FUNCS =  {
        'void addEventListener(@nullable const std::function<void(Ref*, EventType)>& callback)'
    },
    TAG_MAKER = 'ListViewCallback',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.props [[
    items
    magneticType
    magneticAllowedOutOfBoundary
    itemsMargin
    leftPadding
    topPadding
    rightPadding
    bottomPadding
    scrollDuration
    centerItemInCurrentView
    leftmostItemInCurrentView
    rightmostItemInCurrentView
    topmostItemInCurrentView
    bottommostItemInCurrentView
    curSelectedIndex
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::LoadingBar::Direction'
cls.enums [[
    LEFT
    RIGHT
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::LoadingBar'
cls.SUPERCLS = "cocos2d::ui::Widget"
cls.funcs [[
    static cocos2d::Ref *createInstance()
    LoadingBar()
    static cocos2d::ui::LoadingBar *create()
    static cocos2d::ui::LoadingBar *create(const std::string &textureName, @optional float percentage)
    static cocos2d::ui::LoadingBar *create(const std::string &textureName, cocos2d::ui::Widget::TextureResType texType, @optional float percentage)
    void setDirection(cocos2d::ui::LoadingBar::Direction direction)
    cocos2d::ui::LoadingBar::Direction getDirection()
    void loadTexture(const std::string &texture, @optional cocos2d::ui::Widget::TextureResType texType)
    void setPercent(float percent)
    float getPercent()
    void setScale9Enabled(bool enabled)
    bool isScale9Enabled()
    void setCapInsets(const cocos2d::Rect &capInsets)
    const cocos2d::Rect &getCapInsets()
    cocos2d::ResourceData getRenderFile()
]]
cls.props [[
    direction
    percent
    scale9Enabled
    capInsets
    renderFile
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::PageView::EventType'
cls.enums [[
    TURNING
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::PageView::TouchDirection'
cls.enums [[
    LEFT
    RIGHT
    UP
    DOWN
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::PageView'
cls.SUPERCLS = "cocos2d::ui::ListView"
cls.funcs [[
    static cocos2d::Ref *createInstance()
    PageView()
    static cocos2d::ui::PageView *create()
    void addPage(@addref(children |) cocos2d::ui::Widget *page)
    void insertPage(@addref(children |) cocos2d::ui::Widget *page, int idx)
    void removePage(@delref(children |) cocos2d::ui::Widget *page)
    @delref(children ~) void removePageAtIndex(ssize_t index)
    @delref(children *) void removeAllPages()
    void scrollToPage(ssize_t idx)
    void scrollToPage(ssize_t idx, float time)
    void scrollToItem(ssize_t itemIndex)
    void scrollToItem(ssize_t idx, float time)
    ssize_t getCurrentPageIndex()
    void setCurrentPageIndex(ssize_t index)
    void setIndicatorEnabled(bool enabled)
    bool getIndicatorEnabled()
    void setIndicatorPositionAsAnchorPoint(const cocos2d::Vec2 &positionAsAnchorPoint)
    const cocos2d::Vec2 &getIndicatorPositionAsAnchorPoint()
    void setIndicatorPosition(const cocos2d::Vec2 &position)
    const cocos2d::Vec2 &getIndicatorPosition()
    void setIndicatorSpaceBetweenIndexNodes(float spaceBetweenIndexNodes)
    float getIndicatorSpaceBetweenIndexNodes()
    void setIndicatorSelectedIndexColor(const cocos2d::Color3B &color)
    const cocos2d::Color3B &getIndicatorSelectedIndexColor()
    void setIndicatorIndexNodesColor(const cocos2d::Color3B &color)
    const cocos2d::Color3B &getIndicatorIndexNodesColor()
    void setIndicatorSelectedIndexOpacity(uint8_t opacity)
    uint8_t getIndicatorSelectedIndexOpacity()
    void setIndicatorIndexNodesOpacity(uint8_t opacity)
    uint8_t getIndicatorIndexNodesOpacity()
    void setIndicatorIndexNodesScale(float indexNodesScale)
    void setIndicatorIndexNodesTexture(const std::string &texName, @optional cocos2d::ui::Widget::TextureResType texType)
    float getIndicatorIndexNodesScale()
    void setAutoScrollStopEpsilon(float epsilon)
]]
cls.callback {
    FUNCS =  {
        'void addEventListener(@nullable const std::function<void(Ref*, PageView::EventType)>& callback)'
    },
    TAG_MAKER = 'PageViewCallback',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.props [[
    currentPageIndex
    indicatorEnabled
    indicatorPositionAsAnchorPoint
    indicatorPosition
    indicatorSpaceBetweenIndexNodes
    indicatorSelectedIndexColor
    indicatorIndexNodesColor
    indicatorSelectedIndexOpacity
    indicatorIndexNodesOpacity
    indicatorIndexNodesScale
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::RichElement::Type'
cls.enums [[
    TEXT
    IMAGE
    CUSTOM
    NEWLINE
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::RichElement'
cls.SUPERCLS = "cocos2d::Ref"
cls.funcs [[
    RichElement()
    bool init(int tag, const cocos2d::Color3B &color, uint8_t opacity)
    bool equalType(cocos2d::ui::RichElement::Type type)
    void setColor(const cocos2d::Color3B &color)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::RichElementText'
cls.SUPERCLS = "cocos2d::ui::RichElement"
cls.funcs [[
    RichElementText()
    bool init(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &text, const std::string &fontName, float fontSize, uint32_t flags, const std::string &url, @optional const cocos2d::Color3B &outlineColor, @optional int outlineSize, @optional const cocos2d::Color3B &shadowColor, @optional const cocos2d::Size &shadowOffset, @optional int shadowBlurRadius, @optional const cocos2d::Color3B &glowColor)
    static cocos2d::ui::RichElementText *create(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &text, const std::string &fontName, float fontSize, @optional uint32_t flags, @optional const std::string &url, @optional const cocos2d::Color3B &outlineColor, @optional int outlineSize, @optional const cocos2d::Color3B &shadowColor, @optional const cocos2d::Size &shadowOffset, @optional int shadowBlurRadius, @optional const cocos2d::Color3B &glowColor)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::RichElementImage'
cls.SUPERCLS = "cocos2d::ui::RichElement"
cls.funcs [[
    RichElementImage()
    bool init(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &filePath, @optional const std::string &url, @optional cocos2d::ui::Widget::TextureResType texType)
    static cocos2d::ui::RichElementImage *create(int tag, const cocos2d::Color3B &color, uint8_t opacity, const std::string &filePath, @optional const std::string &url, @optional cocos2d::ui::Widget::TextureResType texType)
    void setWidth(int width)
    void setHeight(int height)
    void setUrl(const std::string &url)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::RichElementCustomNode'
cls.SUPERCLS = "cocos2d::ui::RichElement"
cls.funcs [[
    RichElementCustomNode()
    bool init(int tag, const cocos2d::Color3B &color, uint8_t opacity, cocos2d::Node *customNode)
    static cocos2d::ui::RichElementCustomNode *create(int tag, const cocos2d::Color3B &color, uint8_t opacity, cocos2d::Node *customNode)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::RichElementNewLine'
cls.SUPERCLS = "cocos2d::ui::RichElement"
cls.funcs [[
    RichElementNewLine()
    static cocos2d::ui::RichElementNewLine *create(int tag, const cocos2d::Color3B &color, uint8_t opacity)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::RichText::WrapMode'
cls.enums [[
    WRAP_PER_WORD
    WRAP_PER_CHAR
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::RichText::HorizontalAlignment'
cls.enums [[
    LEFT
    CENTER
    RIGHT
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::RichText'
cls.SUPERCLS = "cocos2d::ui::Widget"
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
cls.funcs [[
    RichText()
    static cocos2d::ui::RichText *create()
    void insertElement(cocos2d::ui::RichElement *element, int index)
    void pushBackElement(cocos2d::ui::RichElement *element)
    void removeElement(int index)
    void removeElement(cocos2d::ui::RichElement *element)
    void setVerticalSpace(float space)
    void formatText()
    void setWrapMode(cocos2d::ui::RichText::WrapMode wrapMode)
    cocos2d::ui::RichText::WrapMode getWrapMode()
    void setHorizontalAlignment(cocos2d::ui::RichText::HorizontalAlignment a)
    cocos2d::ui::RichText::HorizontalAlignment getHorizontalAlignment()
    void setFontColor(const std::string &color)
    std::string getFontColor()
    cocos2d::Color3B getFontColor3B()
    void setFontSize(float size)
    float getFontSize()
    void setFontFace(const std::string &face)
    std::string getFontFace()
    void setAnchorFontColor(const std::string &color)
    std::string getAnchorFontColor()
    cocos2d::Color3B getAnchorFontColor3B()
    void setAnchorTextBold(bool enable)
    bool isAnchorTextBoldEnabled()
    void setAnchorTextItalic(bool enable)
    bool isAnchorTextItalicEnabled()
    void setAnchorTextDel(bool enable)
    bool isAnchorTextDelEnabled()
    void setAnchorTextUnderline(bool enable)
    bool isAnchorTextUnderlineEnabled()
    void setAnchorTextOutline(bool enable, @optional const cocos2d::Color3B &outlineColor, @optional int outlineSize)
    bool isAnchorTextOutlineEnabled()
    cocos2d::Color3B getAnchorTextOutlineColor3B()
    int getAnchorTextOutlineSize()
    void setAnchorTextShadow(bool enable, @optional const cocos2d::Color3B &shadowColor, @optional const cocos2d::Size &offset, @optional int blurRadius)
    bool isAnchorTextShadowEnabled()
    cocos2d::Color3B getAnchorTextShadowColor3B()
    cocos2d::Size getAnchorTextShadowOffset()
    int getAnchorTextShadowBlurRadius()
    void setAnchorTextGlow(bool enable, @optional const cocos2d::Color3B &glowColor)
    bool isAnchorTextGlowEnabled()
    cocos2d::Color3B getAnchorTextGlowColor3B()
    void setDefaults(const cocos2d::ValueMap &defaults)
    cocos2d::ValueMap getDefaults()
    cocos2d::Color3B color3BWithString(const std::string &color)
    std::string stringWithColor3B(const cocos2d::Color3B &color3b)
    std::string stringWithColor4B(const cocos2d::Color4B &color4b)
    static void removeTagDescription(const std::string &tag)
    void openUrl(const std::string &url)
]]
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
cls.props [[
    wrapMode
    horizontalAlignment
    fontColor
    fontColor3B
    fontSize
    fontFace
    anchorFontColor
    anchorFontColor3B
    anchorTextBoldEnabled
    anchorTextItalicEnabled
    anchorTextDelEnabled
    anchorTextUnderlineEnabled
    anchorTextOutlineEnabled
    anchorTextOutlineColor3B
    anchorTextOutlineSize
    anchorTextShadowEnabled
    anchorTextShadowColor3B
    anchorTextShadowOffset
    anchorTextShadowBlurRadius
    anchorTextGlowEnabled
    anchorTextGlowColor3B
    defaults
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::ScrollViewBar'
cls.SUPERCLS = "cocos2d::ProtectedNode"
cls.funcs [[
    ScrollViewBar(cocos2d::ui::ScrollView *parent, cocos2d::ui::ScrollView::Direction direction)
    static cocos2d::ui::ScrollViewBar *create(cocos2d::ui::ScrollView *parent, cocos2d::ui::ScrollView::Direction direction)
    void setPositionFromCorner(const cocos2d::Vec2 &positionFromCorner)
    cocos2d::Vec2 getPositionFromCorner()
    void setWidth(float width)
    float getWidth()
    void setAutoHideEnabled(bool autoHideEnabled)
    bool isAutoHideEnabled()
    void setAutoHideTime(float autoHideTime)
    float getAutoHideTime()
    void onScrolled(const cocos2d::Vec2 &outOfBoundary)
    void onTouchBegan()
    void onTouchEnded()
]]
cls.props [[
    positionFromCorner
    width
    autoHideEnabled
    autoHideTime
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::Slider::EventType'
cls.enums [[
    ON_PERCENTAGE_CHANGED
    ON_SLIDEBALL_DOWN
    ON_SLIDEBALL_UP
    ON_SLIDEBALL_CANCEL
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::Slider'
cls.SUPERCLS = "cocos2d::ui::Widget"
cls.funcs [[
    static cocos2d::Ref *createInstance()
    Slider()
    static cocos2d::ui::Slider *create()
    static cocos2d::ui::Slider *create(const std::string &barTextureName, const std::string &normalBallTextureName, @optional cocos2d::ui::Widget::TextureResType resType)
    void loadBarTexture(const std::string &fileName, @optional cocos2d::ui::Widget::TextureResType resType)
    void setScale9Enabled(bool able)
    bool isScale9Enabled()
    void setCapInsets(const cocos2d::Rect &capInsets)
    void setCapInsetsBarRenderer(const cocos2d::Rect &capInsets)
    const cocos2d::Rect &getCapInsetsBarRenderer()
    void setCapInsetProgressBarRenderer(const cocos2d::Rect &capInsets)
    const cocos2d::Rect &getCapInsetsProgressBarRenderer()
    void loadSlidBallTextures(const std::string &normal, @optional const std::string &pressed, @optional const std::string &disabled, @optional cocos2d::ui::Widget::TextureResType texType)
    void loadSlidBallTextureNormal(const std::string &normal, @optional cocos2d::ui::Widget::TextureResType resType)
    void loadSlidBallTexturePressed(const std::string &pressed, @optional cocos2d::ui::Widget::TextureResType resType)
    void loadSlidBallTextureDisabled(const std::string &disabled, @optional cocos2d::ui::Widget::TextureResType resType)
    void loadProgressBarTexture(const std::string &fileName, @optional cocos2d::ui::Widget::TextureResType resType)
    void setPercent(int percent)
    void updateVisualSlider()
    int getPercent()
    void setMaxPercent(int percent)
    int getMaxPercent()
    void setZoomScale(float scale)
    float getZoomScale()
    @addref(protectedChildren |) cocos2d::Sprite *getSlidBallNormalRenderer()
    @addref(protectedChildren |) cocos2d::Sprite *getSlidBallPressedRenderer()
    @addref(protectedChildren |) cocos2d::Sprite *getSlidBallDisabledRenderer()
    @addref(protectedChildren |) cocos2d::Node *getSlidBallRenderer()
    cocos2d::ResourceData getBackFile()
    cocos2d::ResourceData getProgressBarFile()
    cocos2d::ResourceData getBallNormalFile()
    cocos2d::ResourceData getBallPressedFile()
    cocos2d::ResourceData getBallDisabledFile()
]]
cls.callback {
    FUNCS =  {
        'void addEventListener(@nullable const std::function<void (Ref *, EventType)> &callback)'
    },
    TAG_MAKER = 'sliderCallback',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.props [[
    scale9Enabled
    capInsetsBarRenderer
    capInsetsProgressBarRenderer
    percent
    maxPercent
    zoomScale
    slidBallNormalRenderer
    slidBallPressedRenderer
    slidBallDisabledRenderer
    slidBallRenderer
    backFile
    progressBarFile
    ballNormalFile
    ballPressedFile
    ballDisabledFile
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::Text::Type'
cls.enums [[
    SYSTEM
    TTF
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::Text'
cls.SUPERCLS = "cocos2d::ui::Widget"
cls.funcs [[
    static cocos2d::Ref *createInstance()
    Text()
    static cocos2d::ui::Text *create()
    static cocos2d::ui::Text *create(const std::string &textContent, const std::string &fontName, float fontSize)
    void setString(const std::string &text)
    const std::string &getString()
    ssize_t getStringLength()
    void setFontSize(float size)
    float getFontSize()
    void setFontName(const std::string &name)
    const std::string &getFontName()
    cocos2d::ui::Text::Type getType()
    void setTouchScaleChangeEnabled(bool enabled)
    bool isTouchScaleChangeEnabled()
    cocos2d::Size getAutoRenderSize()
    void setTextAreaSize(const cocos2d::Size &size)
    const cocos2d::Size &getTextAreaSize()
    void setTextHorizontalAlignment(cocos2d::TextHAlignment alignment)
    cocos2d::TextHAlignment getTextHorizontalAlignment()
    void setTextVerticalAlignment(cocos2d::TextVAlignment alignment)
    cocos2d::TextVAlignment getTextVerticalAlignment()
    void setTextColor(const cocos2d::Color4B color)
    const cocos2d::Color4B &getTextColor()
    void enableShadow(@optional const cocos2d::Color4B &shadowColor, @optional const cocos2d::Size &offset, @optional int blurRadius)
    void enableOutline(const cocos2d::Color4B &outlineColor, @optional int outlineSize)
    void enableGlow(const cocos2d::Color4B &glowColor)
    void disableEffect()
    void disableEffect(cocos2d::LabelEffect effect)
    bool isShadowEnabled()
    cocos2d::Size getShadowOffset()
    float getShadowBlurRadius()
    cocos2d::Color4B getShadowColor()
    int getOutlineSize()
    cocos2d::LabelEffect getLabelEffectType()
    cocos2d::Color4B getEffectColor()
    cocos2d::Sprite *getLetter(int lettetIndex)
    void setBlendFunc(const cocos2d::BlendFunc &blendFunc)
    const cocos2d::BlendFunc &getBlendFunc()
    bool init(const std::string &textContent, const std::string &fontName, float fontSize)
]]
cls.props [[
    string
    stringLength
    fontSize
    fontName
    type
    touchScaleChangeEnabled
    autoRenderSize
    textAreaSize
    textHorizontalAlignment
    textVerticalAlignment
    textColor
    shadowEnabled
    shadowOffset
    shadowBlurRadius
    shadowColor
    outlineSize
    labelEffectType
    effectColor
    blendFunc
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::TextAtlas'
cls.SUPERCLS = "cocos2d::ui::Widget"
cls.funcs [[
    static cocos2d::Ref *createInstance()
    TextAtlas()
    static cocos2d::ui::TextAtlas *create()
    static cocos2d::ui::TextAtlas *create(const std::string &stringValue, const std::string &charMapFile, int itemWidth, int itemHeight, const std::string &startCharMap)
    void setProperty(const std::string &stringValue, const std::string &charMapFile, int itemWidth, int itemHeight, const std::string &startCharMap)
    void setString(const std::string &value)
    const std::string &getString()
    ssize_t getStringLength()
    void adaptRenderers()
    cocos2d::ResourceData getRenderFile()
]]
cls.props [[
    string
    stringLength
    renderFile
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::TextBMFont'
cls.SUPERCLS = "cocos2d::ui::Widget"
cls.funcs [[
    static cocos2d::Ref *createInstance()
    TextBMFont()
    static cocos2d::ui::TextBMFont *create()
    static cocos2d::ui::TextBMFont *create(const std::string &text, const std::string &filename)
    void setFntFile(const std::string &fileName)
    void setString(const std::string &value)
    const std::string &getString()
    ssize_t getStringLength()
    cocos2d::ResourceData getRenderFile()
    void resetRender()
]]
cls.props [[
    string
    stringLength
    renderFile
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::UICCTextField'
cls.SUPERCLS = "cocos2d::TextFieldTTF"
cls.funcs [[
    static cocos2d::ui::UICCTextField *create()
    UICCTextField()
    static cocos2d::ui::UICCTextField *create(const std::string &placeholder, const std::string &fontName, float fontSize)
    bool onTextFieldAttachWithIME(cocos2d::TextFieldTTF *pSender)
    bool onTextFieldDetachWithIME(cocos2d::TextFieldTTF *pSender)
    bool onTextFieldInsertText(cocos2d::TextFieldTTF *pSender, const char *text, size_t nLen)
    bool onTextFieldDeleteBackward(cocos2d::TextFieldTTF *pSender, const char *delText, size_t nLen)
    void insertText(const char *text, size_t len)
    void openIME()
    void closeIME()
    void setMaxLengthEnabled(bool enable)
    bool isMaxLengthEnabled()
    void setMaxLength(int length)
    int getMaxLength()
    void setPasswordEnabled(bool enable)
    bool isPasswordEnabled()
    void setPasswordStyleText(const std::string &styleText)
    void setPasswordText(const std::string &text)
    void setAttachWithIME(bool attach)
    bool getAttachWithIME()
    void setDetachWithIME(bool detach)
    bool getDetachWithIME()
    void setInsertText(bool insert)
    bool getInsertText()
    void setDeleteBackward(bool deleteBackward)
    bool getDeleteBackward()
]]
cls.props [[
    maxLengthEnabled
    maxLength
    passwordEnabled
    attachWithIME
    detachWithIME
    insertText
    deleteBackward
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::TextField::EventType'
cls.enums [[
    ATTACH_WITH_IME
    DETACH_WITH_IME
    INSERT_TEXT
    DELETE_BACKWARD
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::TextField'
cls.SUPERCLS = "cocos2d::ui::Widget"
cls.funcs [[
    static cocos2d::Ref *createInstance()
    TextField()
    static cocos2d::ui::TextField *create()
    static cocos2d::ui::TextField *create(const std::string &placeholder, const std::string &fontName, int fontSize)
    void setTouchSize(const cocos2d::Size &size)
    cocos2d::Size getTouchSize()
    void setTouchAreaEnabled(bool enable)
    void setPlaceHolder(const std::string &value)
    const std::string &getPlaceHolder()
    const cocos2d::Color4B &getPlaceHolderColor()
    void setPlaceHolderColor(const cocos2d::Color3B &color)
    void setPlaceHolderColor(const cocos2d::Color4B &color)
    const cocos2d::Color4B &getTextColor()
    void setTextColor(const cocos2d::Color4B &textColor)
    void setFontSize(int size)
    int getFontSize()
    void setFontName(const std::string &name)
    const std::string &getFontName()
    void didNotSelectSelf()
    void setString(const std::string &text)
    const std::string &getString()
    void setMaxLengthEnabled(bool enable)
    bool isMaxLengthEnabled()
    void setMaxLength(int length)
    int getMaxLength()
    int getStringLength()
    void setPasswordEnabled(bool enable)
    bool isPasswordEnabled()
    void setPasswordStyleText(const char *styleText)
    const char *getPasswordStyleText()
    bool getAttachWithIME()
    void setAttachWithIME(bool attach)
    bool getDetachWithIME()
    void setDetachWithIME(bool detach)
    bool getInsertText()
    void setInsertText(bool insertText)
    bool getDeleteBackward()
    void setDeleteBackward(bool deleteBackward)
    cocos2d::Size getAutoRenderSize()
    void attachWithIME()
    void setTextAreaSize(const cocos2d::Size &size)
    void setTextHorizontalAlignment(cocos2d::TextHAlignment alignment)
    cocos2d::TextHAlignment getTextHorizontalAlignment()
    void setTextVerticalAlignment(cocos2d::TextVAlignment alignment)
    cocos2d::TextVAlignment getTextVerticalAlignment()
    void setCursorEnabled(bool enabled)
    void setCursorChar(char cursor)
    void setCursorPosition(std::size_t cursorPosition)
    void setCursorFromPoint(const cocos2d::Vec2 &point, const cocos2d::Camera *camera)
]]
cls.callback {
    FUNCS =  {
        'void addEventListener(@nullable const std::function<void (Ref *, EventType)> &callback)'
    },
    TAG_MAKER = 'textFieldCallback',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.props [[
    touchSize
    placeHolder
    placeHolderColor
    textColor
    fontSize
    fontName
    string
    maxLengthEnabled
    maxLength
    stringLength
    passwordEnabled
    passwordStyleText
    attachWithIME
    detachWithIME
    insertText
    deleteBackward
    autoRenderSize
    textHorizontalAlignment
    textVerticalAlignment
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::Button'
cls.SUPERCLS = "cocos2d::ui::Widget"
cls.funcs [[
    static cocos2d::Ref *createInstance()
    Button()
    static cocos2d::ui::Button *create()
    static cocos2d::ui::Button *create(const std::string &normalImage, @optional const std::string &selectedImage, @optional const std::string &disableImage, @optional cocos2d::ui::Widget::TextureResType texType)
    void loadTextures(const std::string &normal, const std::string &selected, @optional const std::string &disabled, @optional cocos2d::ui::Widget::TextureResType texType)
    void loadTextureNormal(const std::string &normal, @optional cocos2d::ui::Widget::TextureResType texType)
    void loadTexturePressed(const std::string &selected, @optional cocos2d::ui::Widget::TextureResType texType)
    void loadTextureDisabled(const std::string &disabled, @optional cocos2d::ui::Widget::TextureResType texType)
    void setCapInsets(const cocos2d::Rect &capInsets)
    void setCapInsetsNormalRenderer(const cocos2d::Rect &capInsets)
    const cocos2d::Rect &getCapInsetsNormalRenderer()
    void setCapInsetsPressedRenderer(const cocos2d::Rect &capInsets)
    const cocos2d::Rect &getCapInsetsPressedRenderer()
    void setCapInsetsDisabledRenderer(const cocos2d::Rect &capInsets)
    const cocos2d::Rect &getCapInsetsDisabledRenderer()
    void setScale9Enabled(bool enable)
    bool isScale9Enabled()
    void setPressedActionEnabled(bool enabled)
    @addref(protectedChildren |) cocos2d::Label *getTitleRenderer()
    void setTitleText(const std::string &text)
    std::string getTitleText()
    void setTitleColor(const cocos2d::Color3B &color)
    cocos2d::Color3B getTitleColor()
    void setTitleFontSize(float size)
    float getTitleFontSize()
    void setTitleFontName(const std::string &fontName)
    std::string getTitleFontName()
    void setTitleAlignment(cocos2d::TextHAlignment hAlignment)
    void setTitleAlignment(cocos2d::TextHAlignment hAlignment, cocos2d::TextVAlignment vAlignment)
    void setTitleLabel(@addref(protectedChildren |) cocos2d::Label *label)
    @addref(protectedChildren |) cocos2d::Label *getTitleLabel()
    void setZoomScale(float scale)
    float getZoomScale()
    @addref(protectedChildren |) cocos2d::ui::Scale9Sprite *getRendererNormal()
    @addref(protectedChildren |) cocos2d::ui::Scale9Sprite *getRendererClicked()
    @addref(protectedChildren |) cocos2d::ui::Scale9Sprite *getRendererDisabled()
    void resetNormalRender()
    void resetPressedRender()
    void resetDisabledRender()
    cocos2d::ResourceData getNormalFile()
    cocos2d::ResourceData getPressedFile()
    cocos2d::ResourceData getDisabledFile()
    bool init(const std::string &normalImage, @optional const std::string &selectedImage, @optional const std::string &disableImage, @optional cocos2d::ui::Widget::TextureResType texType)
    cocos2d::Size getNormalTextureSize()
]]
cls.props [[
    capInsetsNormalRenderer
    capInsetsPressedRenderer
    capInsetsDisabledRenderer
    scale9Enabled
    titleRenderer
    titleText
    titleColor
    titleFontSize
    titleFontName
    titleLabel
    zoomScale
    rendererNormal
    rendererClicked
    rendererDisabled
    normalFile
    pressedFile
    disabledFile
    normalTextureSize
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::CheckBox::EventType'
cls.enums [[
    SELECTED
    UNSELECTED
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::CheckBox'
cls.SUPERCLS = "cocos2d::ui::AbstractCheckButton"
cls.funcs [[
    static cocos2d::Ref *createInstance()
    CheckBox()
    static cocos2d::ui::CheckBox *create()
    static cocos2d::ui::CheckBox *create(const std::string &backGround, const std::string &backGroundSelected, const std::string &cross, const std::string &backGroundDisabled, const std::string &frontCrossDisabled, @optional cocos2d::ui::Widget::TextureResType texType)
    static cocos2d::ui::CheckBox *create(const std::string &backGround, const std::string &cross, @optional cocos2d::ui::Widget::TextureResType texType)
]]
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
cls.enums [[
    SELECTED
    UNSELECTED
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::RadioButton'
cls.SUPERCLS = "cocos2d::ui::AbstractCheckButton"
cls.funcs [[
    static cocos2d::Ref *createInstance()
    RadioButton()
    static cocos2d::ui::RadioButton *create()
    static cocos2d::ui::RadioButton *create(const std::string &backGround, const std::string &backGroundSelected, const std::string &cross, const std::string &backGroundDisabled, const std::string &frontCrossDisabled, @optional cocos2d::ui::Widget::TextureResType texType)
    static cocos2d::ui::RadioButton *create(const std::string &backGround, const std::string &cross, @optional cocos2d::ui::Widget::TextureResType texType)
]]
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
cls.enums [[
    SELECT_CHANGED
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::RadioButtonGroup'
cls.SUPERCLS = "cocos2d::ui::Widget"
cls.funcs [[
    RadioButtonGroup()
    static cocos2d::ui::RadioButtonGroup *create()
    int getSelectedButtonIndex()
    void setSelectedButton(int index)
    void setSelectedButton(cocos2d::ui::RadioButton *radioButton)
    void setSelectedButtonWithoutEvent(int index)
    void setSelectedButtonWithoutEvent(cocos2d::ui::RadioButton *radioButton)
    void addRadioButton(cocos2d::ui::RadioButton *radioButton)
    void removeRadioButton(cocos2d::ui::RadioButton *radioButton)
    void removeAllRadioButtons()
    ssize_t getNumberOfRadioButtons()
    cocos2d::ui::RadioButton *getRadioButtonByIndex(int index)
    void setAllowedNoSelection(bool allowedNoSelection)
    bool isAllowedNoSelection()
]]
cls.callback {
    FUNCS =  {
        'void addEventListener(@nullable const std::function<void (RadioButton *, int, EventType)> &callback)'
    },
    TAG_MAKER = 'radioButtonCallback',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.props [[
    selectedButtonIndex
    numberOfRadioButtons
    allowedNoSelection
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::ImageView'
cls.SUPERCLS = "cocos2d::ui::Widget"
cls.funcs [[
    static cocos2d::Ref *createInstance()
    ImageView()
    static cocos2d::ui::ImageView *create()
    static cocos2d::ui::ImageView *create(const std::string &imageFileName, @optional cocos2d::ui::Widget::TextureResType texType)
    void loadTexture(const std::string &fileName, @optional cocos2d::ui::Widget::TextureResType texType)
    void setTextureRect(const cocos2d::Rect &rect)
    void setScale9Enabled(bool enabled)
    bool isScale9Enabled()
    void setCapInsets(const cocos2d::Rect &capInsets)
    const cocos2d::Rect &getCapInsets()
    void setBlendFunc(const cocos2d::BlendFunc &blendFunc)
    const cocos2d::BlendFunc &getBlendFunc()
    cocos2d::ResourceData getRenderFile()
    bool init(const std::string &imageFileName, @optional cocos2d::ui::Widget::TextureResType texType)
]]
cls.props [[
    scale9Enabled
    capInsets
    blendFunc
    renderFile
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::EditBoxDelegate::EditBoxEndAction'
cls.enums [[
    UNKNOWN
    TAB_TO_NEXT
    TAB_TO_PREVIOUS
    RETURN
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::EditBoxDelegate'
cls.funcs [[
    void editBoxEditingDidBegin(cocos2d::ui::EditBox *)
    void editBoxTextChanged(cocos2d::ui::EditBox *, const std::string &)
    void editBoxReturn(cocos2d::ui::EditBox *editBox)
    void editBoxEditingDidEndWithAction(cocos2d::ui::EditBox *, cocos2d::ui::EditBoxDelegate::EditBoxEndAction )
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::LuaEditBoxDelegate'
cls.SUPERCLS = "cocos2d::ui::EditBoxDelegate"
cls.funcs [[
    LuaEditBoxDelegate()
]]
cls.var('onEditingDidBegin', [[@nullable @local std::function<void (EditBox *)> onEditingDidBegin]])
cls.var('onTextChanged', [[@nullable @local std::function<void (EditBox *, const std::string &)> onTextChanged]])
cls.var('onReturn', [[@nullable @local std::function<void (EditBox *)> onReturn]])
cls.var('onEditingDidEndWithAction', [[@nullable @local std::function<void (EditBox *, EditBoxDelegate::EditBoxEndAction)> onEditingDidEndWithAction]])
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::EditBox::KeyboardReturnType'
cls.enums [[
    DEFAULT
    DONE
    SEND
    SEARCH
    GO
    NEXT
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::EditBox::InputMode'
cls.enums [[
    ANY
    EMAIL_ADDRESS
    NUMERIC
    PHONE_NUMBER
    URL
    DECIMAL
    SINGLE_LINE
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::EditBox::InputFlag'
cls.enums [[
    PASSWORD
    SENSITIVE
    INITIAL_CAPS_WORD
    INITIAL_CAPS_SENTENCE
    INITIAL_CAPS_ALL_CHARACTERS
    LOWERCASE_ALL_CHARACTERS
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ui::EditBox'
cls.SUPERCLS = "cocos2d::ui::Widget"
cls.funcs [[
    static cocos2d::ui::EditBox *create(const cocos2d::Size &size, cocos2d::ui::Scale9Sprite *normalSprite, @optional cocos2d::ui::Scale9Sprite *pressedSprite, @optional cocos2d::ui::Scale9Sprite *disabledSprite)
    static cocos2d::ui::EditBox *create(const cocos2d::Size &size, const std::string &normalImage, cocos2d::ui::Widget::TextureResType texType)
    static cocos2d::ui::EditBox *create(const cocos2d::Size &size, const std::string &normalImage, @optional const std::string &pressedImage, @optional const std::string &disabledImage, @optional cocos2d::ui::Widget::TextureResType texType)
    EditBox()
    bool initWithSizeAndBackgroundSprite(const cocos2d::Size &size, const std::string &normal9SpriteBg, @optional cocos2d::ui::Widget::TextureResType texType)
    bool initWithSizeAndBackgroundSprite(const cocos2d::Size &size, cocos2d::ui::Scale9Sprite *normal9SpriteBg)
    bool initWithSizeAndBackgroundSprite(const cocos2d::Size &size, cocos2d::ui::Scale9Sprite *normalSprite, cocos2d::ui::Scale9Sprite *pressedSprite, cocos2d::ui::Scale9Sprite *disabledSprite)
    bool initWithSizeAndTexture(const cocos2d::Size &size, const std::string &normalImage, @optional const std::string &pressedImage, @optional const std::string &disabledImage, @optional cocos2d::ui::Widget::TextureResType texType)
    void loadTextures(const std::string &normal, const std::string &pressed, @optional const std::string &disabled, @optional cocos2d::ui::Widget::TextureResType texType)
    void loadTextureNormal(const std::string &normal, @optional cocos2d::ui::Widget::TextureResType texType)
    void loadTexturePressed(const std::string &pressed, @optional cocos2d::ui::Widget::TextureResType texType)
    void loadTextureDisabled(const std::string &disabled, @optional cocos2d::ui::Widget::TextureResType texType)
    void setCapInsets(const cocos2d::Rect &capInsets)
    void setCapInsetsNormalRenderer(const cocos2d::Rect &capInsets)
    const cocos2d::Rect &getCapInsetsNormalRenderer()
    void setCapInsetsPressedRenderer(const cocos2d::Rect &capInsets)
    const cocos2d::Rect &getCapInsetsPressedRenderer()
    void setCapInsetsDisabledRenderer(const cocos2d::Rect &capInsets)
    const cocos2d::Rect &getCapInsetsDisabledRenderer()
    void setDelegate(@addref(delegate ^) cocos2d::ui::EditBoxDelegate *delegate)
    @addref(delegate ^) cocos2d::ui::EditBoxDelegate *getDelegate()
    void setText(const char *pText)
    const char *getText()
    void setFont(const char *pFontName, int fontSize)
    void setFontName(const char *pFontName)
    const char *getFontName()
    void setFontSize(int fontSize)
    int getFontSize()
    void setFontColor(const cocos2d::Color3B &color)
    void setFontColor(const cocos2d::Color4B &color)
    const cocos2d::Color4B &getFontColor()
    void setPlaceholderFont(const char *pFontName, int fontSize)
    void setPlaceholderFontName(const char *pFontName)
    const char *getPlaceholderFontName()
    void setPlaceholderFontSize(int fontSize)
    int getPlaceholderFontSize()
    void setPlaceholderFontColor(const cocos2d::Color3B &color)
    void setPlaceholderFontColor(const cocos2d::Color4B &color)
    const cocos2d::Color4B &getPlaceholderFontColor()
    void setPlaceHolder(const char *pText)
    const char *getPlaceHolder()
    void setInputMode(cocos2d::ui::EditBox::InputMode inputMode)
    cocos2d::ui::EditBox::InputMode getInputMode()
    void setMaxLength(int maxLength)
    int getMaxLength()
    void setInputFlag(cocos2d::ui::EditBox::InputFlag inputFlag)
    cocos2d::ui::EditBox::InputFlag getInputFlag()
    void setReturnType(cocos2d::ui::EditBox::KeyboardReturnType returnType)
    cocos2d::ui::EditBox::KeyboardReturnType getReturnType()
    void setTextHorizontalAlignment(cocos2d::TextHAlignment alignment)
    cocos2d::TextHAlignment getTextHorizontalAlignment()
    void openKeyboard()
]]
cls.props [[
    capInsetsNormalRenderer
    capInsetsPressedRenderer
    capInsetsDisabledRenderer
    delegate
    text
    fontName
    fontSize
    fontColor
    placeholderFontName
    placeholderFontSize
    placeholderFontColor
    placeHolder
    inputMode
    maxLength
    inputFlag
    returnType
    textHorizontalAlignment
]]
M.CLASSES[#M.CLASSES + 1] = cls

return M
