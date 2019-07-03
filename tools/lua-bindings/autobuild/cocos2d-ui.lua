require "autobuild.cocos2d-ui-types"

local cls
local M = {}
M.NAME = "cocos2d_ui"
M.HEADER_PATH = "frameworks/libxgame/src/lua-bindings/lua_cocos2d_ui.h"
M.SOURCE_PATH = "frameworks/libxgame/src/lua-bindings/lua_cocos2d_ui.cpp"
M.INCLUDES = [[
#include "lua-bindings/lua_cocos2d_ui.h"
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "lua-bindings/LuaCocosAdapter.h"
#include "xgame/xlua.h"
#include "xgame/xruntime.h"
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "ui/UIPageViewIndicator.h"
#include "ui/UIScrollViewBar.h"
]]
M.CHUNK = [[
]]

M.CLASSES = {}

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::Widget::FocusDirection"
cls.enums [[
    LEFT
    RIGHT
    UP
    DOWN
]]

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::Widget::PositionType"
cls.enums [[
    ABSOLUTE
    PERCENT
]]

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::Widget::SizeType"
cls.enums [[
    ABSOLUTE
    PERCENT
]]

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::Widget::TouchEventType"
cls.enums [[
    BEGAN
    MOVED
    ENDED
    CANCELED
]]

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::Widget::TextureResType"
cls.enums [[
    LOCAL
    PLIST
]]

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::Widget::BrightStyle"
cls.enums [[
    NONE
    NORMAL
    HIGHLIGHT
]]

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::Widget"
cls.SUPERCLS = "cocos2d::ProtectedNode"
cls.funcs [[
    static Widget* create()
    void setEnabled(bool enabled)
    bool isEnabled()
    void setBright(bool bright)
    bool isBright()
    void setTouchEnabled(bool enabled)
    void setBrightStyle(BrightStyle style)
    bool isTouchEnabled()
    bool isHighlighted()
    void setHighlighted(bool highlight)
    float getLeftBoundary()
    float getBottomBoundary()
    float getRightBoundary()
    float getTopBoundary()
    void setPositionPercent(const Vec2 &percent)
    const Vec2& getPositionPercent()
    void setPositionType(PositionType type)
    PositionType getPositionType()
    void setFlippedX(bool flippedX)
    bool isFlippedX()
    void setFlippedY(bool flippedY)
    bool isFlippedY()
    bool isClippingParentContainsPoint(const Vec2& pt)
    const Vec2& getTouchBeganPosition()
    const Vec2& getTouchMovePosition()
    const Vec2& getTouchEndPosition()
    void setSizePercent(const Vec2 &percent)
    void setSizeType(SizeType type)
    SizeType getSizeType()
    const Size& getCustomSize()
    const Size& getLayoutSize()
    const Vec2& getSizePercent()
    bool onTouchBegan(Touch *touch, Event *unusedEvent)
    void onTouchMoved(Touch *touch, Event *unusedEvent)
    void onTouchEnded(Touch *touch, Event *unusedEvent)
    void onTouchCancelled(Touch *touch, Event *unusedEvent)
    void setLayoutParameter(LayoutParameter* parameter)
    LayoutParameter* getLayoutParameter()
    void ignoreContentAdaptWithSize(bool ignore)
    bool isIgnoreContentAdaptWithSize()
    Vec2 getWorldPosition()
    @ref(map protectedChildren) Node* getVirtualRenderer()
    Size getVirtualRendererSize()
    Widget* clone()
    void updateSizeAndPosition()
    void updateSizeAndPosition(const Size& parentSize)
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
    Widget* findNextFocusedWidget(FocusDirection direction, Widget* current)
    void requestFocus()
    static Widget* getCurrentFocusedWidget()
    static void enableDpadNavigation(bool enable)
    void setUnifySizeEnabled(bool enable)
    bool isUnifySizeEnabled()
    void setCallbackName(const std::string& callbackName)
    const std::string& getCallbackName()
    void setCallbackType(const std::string& callbackType)
    const std::string& getCallbackType()
    void setLayoutComponentEnabled(bool enable)
    bool isLayoutComponentEnabled()
    void interceptTouchEvent(TouchEventType event, Widget* sender, Touch *touch)
    void propagateTouchEvent(TouchEventType event, Widget* sender, Touch *touch)
    void onFocusChange(Widget* widgetLostFocus, Widget* widgetGetFocus)
    void dispatchFocusEvent(Widget* widgetLoseFocus, Widget* widgetGetFocus)
]]
cls.var('onFocusChanged', [[@nullable std::function<void(Widget*,Widget*)> onFocusChanged]])
cls.var('onNextFocusedWidget', [[@nullable std::function<Widget*(FocusDirection)> onNextFocusedWidget]])
cls.callback {
    FUNCS =  {
        'void addTouchEventListener(@nullable const std::function<void(Ref*,Widget::TouchEventType)>& callback)',
    },
    TAG_MAKER = 'olua_makecallbacktag("touchEventListener")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
    CALLONCE = false,
    REMOVE = false,
}
cls.callback {
    FUNCS =  {
        'void addClickEventListener(@nullable std::function<void(Ref*)>& callback)',
    },
    TAG_MAKER = 'olua_makecallbacktag("clickEventListener")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
    CALLONCE = false,
    REMOVE = false,
}
cls.callback {
    FUNCS =  {
        'void addCCSEventListener(@nullable const std::function<void(Ref*, int)>& callback)',
    },
    TAG_MAKER = 'olua_makecallbacktag("ccsEventListener")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
    CALLONCE = false,
    REMOVE = false,
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

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::Helper"
cls.funcs [[
    static Widget* seekWidgetByTag(Widget* root, int tag)
    static Widget* seekWidgetByName(Widget* root, const std::string& name)
    static Widget* seekActionWidgetByActionTag(Widget* root, int tag)
    static std::string getSubStringOfUTF8String(const std::string& str, std::string::size_type start, std::string::size_type length)
    static void doLayout(Node *rootNode)
    static void changeLayoutSystemActiveState(bool active)
    static Rect restrictCapInsetRect(const Rect& capInsets, const Size& textureSize)
    static Rect convertBoundingBoxToScreen(Node* node)
]]

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::Scale9Sprite::State"
cls.enums [[
    NORMAL
    GRAY
]]

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::Scale9Sprite::RenderingType"
cls.enums [[
    SIMPLE
    SLICE
]]

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::Scale9Sprite"
cls.SUPERCLS = "cocos2d::Sprite"
cls.funcs [[
    static Scale9Sprite* create()
    static Scale9Sprite* create(const std::string& file, const Rect& rect, const Rect& capInsets)
    static Scale9Sprite* create(const Rect& capInsets, const std::string& file)
    static Scale9Sprite* create(const std::string& file, const Rect& rect)
    static Scale9Sprite* create(const std::string& file)
    static Scale9Sprite* createWithSpriteFrame(SpriteFrame* spriteFrame)
    static Scale9Sprite* createWithSpriteFrame(SpriteFrame* spriteFrame, const Rect& capInsets)
    static Scale9Sprite* createWithSpriteFrameName(const std::string& spriteFrameName)
    static Scale9Sprite* createWithSpriteFrameName(const std::string& spriteFrameName, const Rect& capInsets)
    bool initWithFile(const std::string& file, const Rect& rect, const Rect& capInsets)
    bool initWithFile(const Rect& capInsets, const std::string& file)
    bool initWithSpriteFrame(SpriteFrame* spriteFrame, const Rect& capInsets)
    bool initWithSpriteFrameName(const std::string& spriteFrameName, const Rect& capInsets)
    bool init(Sprite* sprite, const Rect& rect, bool rotated, const Rect& capInsets)
    bool init(Sprite* sprite, const Rect& rect, const Rect& capInsets)
    bool init(Sprite* sprite, const Rect& rect, bool rotated, const Vec2 &offset, const Size &originalSize, const Rect& capInsets)
    Scale9Sprite* resizableSpriteWithCapInsets(const Rect& capInsets)
    bool updateWithSprite(Sprite* sprite, const Rect& rect, bool rotated, const Rect& capInsets)
    bool updateWithSprite(Sprite* sprite, const Rect& rect, bool rotated, const Vec2 &offset, const Size &originalSize, const Rect& capInsets)
    void setSpriteFrame(SpriteFrame * spriteFrame, const Rect& capInsets)
    void setState(State state)
    State getState()
    Size getOriginalSize()
    void setPreferredSize(const Size& size)
    Size getPreferredSize()
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
    Sprite* getSprite()
    void copyTo(Scale9Sprite* copy)
    void setRenderingType(RenderingType type)
    RenderingType getRenderingType()
    void setCapInsets(const Rect& insets)
    Rect getCapInsets()
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

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::LayoutComponent::HorizontalEdge"
cls.enums [[
    None
    Left
    Right
    Center
]]

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::LayoutComponent::VerticalEdge"
cls.enums [[
    None
    Bottom
    Top
    Center
]]

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::LayoutComponent"
cls.SUPERCLS = "cocos2d::Component"
cls.funcs [[
    static cocos2d::ui::LayoutComponent *create()
    static LayoutComponent* bindLayoutComponent(Node* node)
    void setUsingPercentContentSize(bool isUsed)
    bool getUsingPercentContentSize()
    void setPercentContentSize(const Vec2 &percent)
    Vec2 getPercentContentSize()
    const Point& getAnchorPosition()
    void setAnchorPosition(const Point& point)
    const Point& getPosition()
    void setPosition(const Point& position)
    bool isPositionPercentXEnabled()
    void setPositionPercentXEnabled(bool isUsed)
    float getPositionPercentX()
    void setPositionPercentX(float percentMargin)
    bool isPositionPercentYEnabled()
    void setPositionPercentYEnabled(bool isUsed)
    float getPositionPercentY()
    void setPositionPercentY(float percentMargin)
    HorizontalEdge getHorizontalEdge()
    void setHorizontalEdge(HorizontalEdge hEage)
    VerticalEdge getVerticalEdge()
    void setVerticalEdge(VerticalEdge vEage)
    float getLeftMargin()
    void setLeftMargin(float margin)
    float getRightMargin()
    void setRightMargin(float margin)
    float getTopMargin()
    void setTopMargin(float margin)
    float getBottomMargin()
    void setBottomMargin(float margin)
    const Size& getSize()
    void setSize(const Size& size)
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

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::LayoutParameter::Type"
cls.enums [[
    NONE
    LINEAR
    RELATIVE
]]

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::LayoutParameter"
cls.SUPERCLS = "cocos2d::Ref"
cls.funcs [[
    static LayoutParameter* create()
    void setMargin(const Margin& margin)
    const Margin& getMargin()
    Type getLayoutType()
    LayoutParameter* clone()
    LayoutParameter* createCloneInstance()
    void copyProperties(LayoutParameter* model)
]]
cls.props [[
    margin
    layoutType
]]

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::LinearLayoutParameter::LinearGravity"
cls.enums [[
    NONE
    LEFT
    TOP
    RIGHT
    BOTTOM
    CENTER_VERTICAL
    CENTER_HORIZONTAL
]]

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::LinearLayoutParameter"
cls.SUPERCLS = "cocos2d::ui::LayoutParameter"
cls.funcs [[
    static LinearLayoutParameter* create()
    void setGravity(LinearGravity gravity)
    LinearGravity getGravity()
]]
cls.props [[
    gravity
]]

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::RelativeLayoutParameter::RelativeAlign"
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

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::RelativeLayoutParameter"
cls.SUPERCLS = "cocos2d::ui::LayoutParameter"
cls.funcs [[
    static RelativeLayoutParameter* create()
    void setAlign(RelativeAlign align)
    RelativeAlign getAlign()
    void setRelativeToWidgetName(const std::string& name)
    const std::string& getRelativeToWidgetName()
    void setRelativeName(const std::string& name)
    const std::string& getRelativeName()
]]
cls.props [[
    align
    relativeToWidgetName
    relativeName
]]

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::Layout::Type"
cls.enums [[
    ABSOLUTE
    VERTICAL
    HORIZONTAL
    RELATIVE
]]

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::Layout::ClippingType"
cls.enums [[
    STENCIL
    SCISSOR
]]

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::Layout::BackGroundColorType"
cls.enums [[
    NONE
    SOLID
    GRADIENT
]]

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::Layout"
cls.SUPERCLS = "cocos2d::ui::Widget"
cls.funcs [[
    static Layout* create()
    void setBackGroundImage(const std::string& fileName,TextureResType texType = TextureResType::LOCAL)
    void setBackGroundImageCapInsets(const Rect& capInsets)
    const Rect& getBackGroundImageCapInsets()
    void setBackGroundColorType(BackGroundColorType type)
    BackGroundColorType getBackGroundColorType()
    void setBackGroundImageScale9Enabled(bool enabled)
    bool isBackGroundImageScale9Enabled()
    void setBackGroundColor(const Color3B &color)
    const Color3B& getBackGroundColor()
    void setBackGroundColor(const Color3B &startColor, const Color3B &endColor)
    const Color3B& getBackGroundStartColor()
    const Color3B& getBackGroundEndColor()
    void setBackGroundColorOpacity(GLubyte opacity)
    GLubyte getBackGroundColorOpacity()
    void setBackGroundColorVector(const Vec2 &vector)
    const Vec2& getBackGroundColorVector()
    void setBackGroundImageColor(const Color3B& color)
    void setBackGroundImageOpacity(GLubyte opacity)
    const Color3B& getBackGroundImageColor()
    GLubyte getBackGroundImageOpacity()
    void removeBackGroundImage()
    const Size& getBackGroundImageTextureSize()
    void setClippingEnabled(bool enabled)
    void setClippingType(ClippingType type)
    ClippingType getClippingType()
    bool isClippingEnabled()
    void setLayoutType(Type type)
    Type getLayoutType()
    void forceDoLayout()
    void requestDoLayout()
    void setLoopFocus(bool loop)
    bool isLoopFocus()
    void setPassFocusToChild(bool pass)
    bool isPassFocusToChild()
    ResourceData getRenderFile()
    DrawNode *getClippingNode()
]]
cls.var('onPassFocusToChild', [[@nullable std::function<int(Widget::FocusDirection, Widget*)> onPassFocusToChild]])
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
    clippingNode
]]

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::HBox"
cls.SUPERCLS = "cocos2d::ui::Layout"
cls.funcs [[
    static HBox* create()
    static HBox* create(const Size& size)
    bool initWithSize(const Size& size)
]]

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::VBox"
cls.SUPERCLS = "cocos2d::ui::Layout"
cls.funcs [[
    static VBox* create()
    static VBox* create(const Size& size)
    bool initWithSize(const Size& size)
]]

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::RelativeBox"
cls.SUPERCLS = "cocos2d::ui::Layout"
cls.funcs [[
    static RelativeBox* create()
    static RelativeBox* create(const Size& size)
    bool initWithSize(const Size& size)
]]

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::experimental::ui::WebView"
cls.SUPERCLS = "cocos2d::ui::Widget"
cls.DEFIF = "#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_TIZEN)"
cls.funcs [[
    static WebView *create()
    void setJavascriptInterfaceScheme(const std::string &scheme)
    void loadData(const cocos2d::Data &data, const std::string &MIMEType, const std::string &encoding, const std::string &baseURL)
    void loadHTMLString(const std::string &string, const std::string &baseURL = "")
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
]]
cls.callback {
    FUNCS =  {
        'void setOnShouldStartLoading(@nullable const std::function<bool(WebView *sender, const std::string &url)>& callback)',
    },
    TAG_MAKER = 'olua_makecallbacktag("onShouldStartLoading")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
    CALLONCE = false,
    REMOVE = false,
}
cls.callback {
    FUNCS =  {
        'std::function<bool(WebView *sender, const std::string &url)> getOnShouldStartLoading()',
    },
    TAG_MAKER = 'olua_makecallbacktag("onShouldStartLoading")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_ENDWITH',
    CALLONCE = false,
    REMOVE = false,
}
cls.callback {
    FUNCS =  {
        'void setOnDidFinishLoading(@nullable const std::function<void(WebView *sender, const std::string &url)>& callback)',
    },
    TAG_MAKER = 'olua_makecallbacktag("onDidFinishLoading")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
    CALLONCE = false,
    REMOVE = false,
}
cls.callback {
    FUNCS =  {
        'std::function<void(WebView *sender, const std::string &url)> getOnDidFinishLoading()',
    },
    TAG_MAKER = 'olua_makecallbacktag("onDidFinishLoading")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_ENDWITH',
    CALLONCE = false,
    REMOVE = false,
}
cls.callback {
    FUNCS =  {
        'void setOnDidFailLoading(@nullable const std::function<void(WebView *sender, const std::string &url)>& callback)',
    },
    TAG_MAKER = 'olua_makecallbacktag("onDidFailLoading")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
    CALLONCE = false,
    REMOVE = false,
}
cls.callback {
    FUNCS =  {
        'std::function<void(WebView *sender, const std::string &url)> getOnDidFailLoading()',
    },
    TAG_MAKER = 'olua_makecallbacktag("onDidFailLoading")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_ENDWITH',
    CALLONCE = false,
    REMOVE = false,
}
cls.callback {
    FUNCS =  {
        'void setOnJSCallback(@nullable const std::function<void(WebView *sender, const std::string &url)>& callback)',
    },
    TAG_MAKER = 'olua_makecallbacktag("onJSCallback")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
    CALLONCE = false,
    REMOVE = false,
}
cls.callback {
    FUNCS =  {
        'std::function<void(WebView *sender, const std::string &url)> getOnJSCallback()',
    },
    TAG_MAKER = 'olua_makecallbacktag("onJSCallback")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_ENDWITH',
    CALLONCE = false,
    REMOVE = false,
}
cls.props [[
    opacityWebView
    onShouldStartLoading
    onDidFinishLoading
    onDidFailLoading
    onJSCallback
]]

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::experimental::ui::VideoPlayer::EventType"
cls.DEFIF = "#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_TIZEN)"
cls.enums [[
    PLAYING
    PAUSED
    STOPPED
    COMPLETED
    ERROR
]]

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::experimental::ui::VideoPlayer::StyleType"
cls.DEFIF = "#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_TIZEN)"
cls.enums [[
    DEFAULT
    NONE
]]

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::experimental::ui::VideoPlayer"
cls.SUPERCLS = "cocos2d::ui::Widget"
cls.DEFIF = "#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_TIZEN)"
cls.funcs [[
    static cocos2d::experimental::ui::VideoPlayer *create()
    void setFileName(const std::string& videoPath)
    const std::string& getFileName()
    void setURL(const std::string& _videoURL)
    const std::string& getURL()
    void setLooping(bool looping)
    void setUserInputEnabled(bool enableInput)
    void setStyle(StyleType style)
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
]]
cls.callback {
    FUNCS =  {
        'void addEventListener(@nullable const std::function<void(Ref*,VideoPlayer::EventType)>& callback)',
    },
    TAG_MAKER = 'olua_makecallbacktag("videoPlayerCallback")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
    CALLONCE = false,
    REMOVE = false,
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

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::AbstractCheckButton"
cls.SUPERCLS = "cocos2d::ui::Widget"
cls.funcs [[
    void loadTextures(const std::string& background, const std::string& backgroundSelected, const std::string& cross, const std::string& backgroundDisabled, const std::string& frontCrossDisabled, TextureResType texType = TextureResType::LOCAL)
    void loadTextureBackGround(const std::string& backGround,TextureResType type = TextureResType::LOCAL)
    void loadTextureBackGroundSelected(const std::string& backGroundSelected,TextureResType texType = TextureResType::LOCAL)
    void loadTextureFrontCross(const std::string& crossTextureName,TextureResType texType = TextureResType::LOCAL)
    void loadTextureBackGroundDisabled(const std::string& backGroundDisabled,TextureResType texType = TextureResType::LOCAL)
    void loadTextureFrontCrossDisabled(const std::string& frontCrossDisabled,TextureResType texType = TextureResType::LOCAL)
    bool isSelected()
    void setSelected(bool selected)
    void setZoomScale(float scale)
    float getZoomScale()
    @ref(map protectedChildren) Sprite* getRendererBackground()
    @ref(map protectedChildren) Sprite* getRendererBackgroundSelected()
    @ref(map protectedChildren) Sprite* getRendererFrontCross()
    @ref(map protectedChildren) Sprite* getRendererBackgroundDisabled()
    @ref(map protectedChildren) Sprite* getRendererFrontCrossDisabled()
    ResourceData getBackNormalFile()
    ResourceData getBackPressedFile()
    ResourceData getBackDisabledFile()
    ResourceData getCrossNormalFile()
    ResourceData getCrossDisabledFile()
    bool init(const std::string& backGround, const std::string& backGroundSelected, const std::string& cross, const std::string& backGroundDisabled, const std::string& frontCrossDisabled, TextureResType texType = TextureResType::LOCAL)
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

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::TabHeader::EventType"
cls.enums [[
    SELECTED
    UNSELECTED
]]

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::TabHeader"
cls.SUPERCLS = "cocos2d::ui::AbstractCheckButton"
cls.funcs [[
    static TabHeader* create()
    static TabHeader* create(const std::string& titleStr, const std::string& backGround, const std::string& cross, TextureResType texType = TextureResType::LOCAL)
    static TabHeader* create(const std::string& titleStr, const std::string& backGround, const std::string& backGroundSelected, const std::string& cross, const std::string& backGroundDisabled, const std::string& frontCrossDisabled, TextureResType texType = TextureResType::LOCAL)
    @ref(map protectedChildren) Label* getTitleRenderer()
    void setTitleText(const std::string& text)
    std::string getTitleText()
    void setTitleColor(const Color4B& color)
    const Color4B& getTitleColor()
    void setTitleFontSize(float size)
    float getTitleFontSize()
    void setTitleFontName(const std::string& fontName)
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

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::TabControl::Dock"
cls.enums [[
    TOP
    LEFT
    BOTTOM
    RIGHT
]]

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::TabControl::EventType"
cls.enums [[
    SELECT_CHANGED
]]

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::TabControl"
cls.SUPERCLS = "cocos2d::ui::Widget"
cls.funcs [[
    static TabControl* create()
    @unref(cmp protectedChildren) void removeTab(int index)
    void setSelectTab(int index)
    void setSelectTab(TabHeader* tabHeader)
    @ref(map protectedChildren) TabHeader* getTabHeader(int index)
    @ref(map protectedChildren) Layout* getTabContainer(int index)
    void insertTab(int index, @ref(map protectedChildren) TabHeader* header, @ref(map protectedChildren) Layout* container)
    size_t getTabCount()
    int getSelectedTabIndex()
    int indexOfTabHeader(const TabHeader* tabCell)
    void setHeaderWidth(float headerWidth)
    float getHeaderWidth()
    void setHeaderHeight(float headerHeight)
    int getHeaderHeight()
    void ignoreHeadersTextureSize(bool ignore)
    bool isIgnoreHeadersTextureSize()
    void setHeaderSelectedZoom(float zoom)
    float getHeaderSelectedZoom()
    void setHeaderDockPlace(TabControl::Dock dockPlace)
    TabControl::Dock getHeaderDockPlace()
]]
cls.callback {
    FUNCS =  {
        'void setTabChangedEventListener(@nullable const std::function<void(int tabIndex, EventType)>& callback)',
    },
    TAG_MAKER = 'olua_makecallbacktag("tabChangedEventListener")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
    CALLONCE = false,
    REMOVE = false,
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

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::ScrollView::Direction"
cls.enums [[
    NONE
    VERTICAL
    HORIZONTAL
    BOTH
]]

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::ScrollView::EventType"
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

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::ScrollView"
cls.SUPERCLS = "cocos2d::ui::Layout"
cls.funcs [[
    static ScrollView* create()
    void setDirection(Direction dir)
    Direction getDirection()
    @ref(map protectedChildren) Layout* getInnerContainer()
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
    void scrollToPercentBothDirection(const Vec2& percent, float timeInSec, bool attenuated)
    float getScrolledPercentVertical()
    float getScrolledPercentHorizontal()
    Vec2 getScrolledPercentBothDirection()
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
    void jumpToPercentBothDirection(const Vec2& percent)
    void setInnerContainerSize(const Size &size)
    const Size& getInnerContainerSize()
    void setInnerContainerPosition(const Vec2 &pos)
    const Vec2& getInnerContainerPosition()
    void setBounceEnabled(bool enabled)
    bool isBounceEnabled()
    void setInertiaScrollEnabled(bool enabled)
    bool isInertiaScrollEnabled()
    void setScrollBarEnabled(bool enabled)
    bool isScrollBarEnabled()
    void setScrollBarPositionFromCorner(const Vec2& positionFromCorner)
    void setScrollBarPositionFromCornerForVertical(const Vec2& positionFromCorner)
    Vec2 getScrollBarPositionFromCornerForVertical()
    void setScrollBarPositionFromCornerForHorizontal(const Vec2& positionFromCorner)
    Vec2 getScrollBarPositionFromCornerForHorizontal()
    void setScrollBarWidth(float width)
    float getScrollBarWidth()
    void setScrollBarColor(const Color3B& color)
    const Color3B& getScrollBarColor()
    void setScrollBarOpacity(GLubyte opacity)
    GLubyte getScrollBarOpacity()
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
        'void addEventListener(@nullable const std::function<void(Ref*, EventType)>& callback)',
    },
    TAG_MAKER = 'olua_makecallbacktag("scrollViewCallback")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
    CALLONCE = false,
    REMOVE = false,
}
cls.alias('addEventListener', 'addScrollEventListener')
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

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::ListView::Gravity"
cls.enums [[
    LEFT
    RIGHT
    CENTER_HORIZONTAL
    TOP
    BOTTOM
    CENTER_VERTICAL
]]

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::ListView::EventType"
cls.enums [[
    ON_SELECTED_ITEM_START
    ON_SELECTED_ITEM_END
]]

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::ListView::MagneticType"
cls.enums [[
    NONE
    CENTER
    BOTH_END
    LEFT
    RIGHT
    TOP
    BOTTOM
]]

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::ListView"
cls.SUPERCLS = "cocos2d::ui::ScrollView"
cls.funcs [[
    static ListView* create()
    void setItemModel(Widget* model)
    void pushBackDefaultItem()
    void insertDefaultItem(ssize_t index)
    void pushBackCustomItem(@ref(map children) Widget* item)
    void insertCustomItem(@ref(map children) Widget* item, ssize_t index)
    @unref(cmp children) void removeLastItem()
    @unref(cmp children) void removeItem(ssize_t index)
    @unref(cmp children) void removeAllItems()
    @ref(map children) Widget* getItem(ssize_t index)
    @ref(map children) Vector<Widget*>& getItems()
    ssize_t getIndex(Widget* item)
    void setGravity(Gravity gravity)
    void setMagneticType(MagneticType magneticType)
    MagneticType getMagneticType()
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
    Widget* getClosestItemToPosition(const Vec2& targetPosition, const Vec2& itemAnchorPoint)
    Widget* getClosestItemToPositionInCurrentView(const Vec2& positionRatioInView, const Vec2& itemAnchorPoint)
    Widget* getCenterItemInCurrentView()
    Widget* getLeftmostItemInCurrentView()
    Widget* getRightmostItemInCurrentView()
    Widget* getTopmostItemInCurrentView()
    Widget* getBottommostItemInCurrentView()
    void jumpToItem(ssize_t itemIndex, const Vec2& positionRatioInView, const Vec2& itemAnchorPoint)
    void scrollToItem(ssize_t itemIndex, const Vec2& positionRatioInView, const Vec2& itemAnchorPoint)
    void scrollToItem(ssize_t itemIndex, const Vec2& positionRatioInView, const Vec2& itemAnchorPoint, float timeInSec)
    ssize_t getCurSelectedIndex()
    void setCurSelectedIndex(int itemIndex)
]]
cls.callback {
    FUNCS =  {
        'void addEventListener(@nullable const std::function<void(Ref*, EventType)>& callback)',
    },
    TAG_MAKER = 'olua_makecallbacktag("ListViewCallback")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
    CALLONCE = false,
    REMOVE = false,
}
cls.alias('addEventListener', 'addListViewEventListener')
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

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::LoadingBar::Direction"
cls.enums [[
    LEFT
    RIGHT
]]

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::LoadingBar"
cls.SUPERCLS = "cocos2d::ui::Widget"
cls.funcs [[
    static LoadingBar* create()
    static LoadingBar* create(const std::string& textureName, float percentage = 0)
    static LoadingBar* create(const std::string& textureName, TextureResType texType, float percentage = 0)
    void setDirection(Direction direction)
    Direction getDirection()
    void loadTexture(const std::string& texture,TextureResType texType = TextureResType::LOCAL)
    void setPercent(float percent)
    float getPercent()
    void setScale9Enabled(bool enabled)
    bool isScale9Enabled()
    void setCapInsets(const Rect &capInsets)
    const Rect& getCapInsets()
    ResourceData getRenderFile()
]]
cls.props [[
    direction
    percent
    scale9Enabled
    capInsets
    renderFile
]]

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::PageView::EventType"
cls.enums [[
    TURNING
]]

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::PageView::TouchDirection"
cls.enums [[
    LEFT
    RIGHT
    UP
    DOWN
]]

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::PageView"
cls.SUPERCLS = "cocos2d::ui::ListView"
cls.funcs [[
    static PageView* create()
    void addPage(@ref(map children) Widget* page)
    void insertPage(@ref(map children) Widget* page, int idx)
    void removePage(@unref(map children) Widget* page)
    @unref(cmp children) void removePageAtIndex(ssize_t index)
    @unref(cmp children) void removeAllPages()
    void scrollToPage(ssize_t idx)
    void scrollToPage(ssize_t idx, float time)
    void scrollToItem(ssize_t itemIndex)
    void scrollToItem(ssize_t idx, float time)
    ssize_t getCurrentPageIndex()
    void setCurrentPageIndex(ssize_t index)
    void setIndicatorEnabled(bool enabled)
    bool getIndicatorEnabled()
    void setIndicatorPositionAsAnchorPoint(const Vec2& positionAsAnchorPoint)
    const Vec2& getIndicatorPositionAsAnchorPoint()
    void setIndicatorPosition(const Vec2& position)
    const Vec2& getIndicatorPosition()
    void setIndicatorSpaceBetweenIndexNodes(float spaceBetweenIndexNodes)
    float getIndicatorSpaceBetweenIndexNodes()
    void setIndicatorSelectedIndexColor(const Color3B& color)
    const Color3B& getIndicatorSelectedIndexColor()
    void setIndicatorIndexNodesColor(const Color3B& color)
    const Color3B& getIndicatorIndexNodesColor()
    void setIndicatorSelectedIndexOpacity(GLubyte opacity)
    GLubyte getIndicatorSelectedIndexOpacity()
    void setIndicatorIndexNodesOpacity(GLubyte opacity)
    GLubyte getIndicatorIndexNodesOpacity()
    void setIndicatorIndexNodesScale(float indexNodesScale)
    void setIndicatorIndexNodesTexture(const std::string& texName,Widget::TextureResType texType = Widget::TextureResType::LOCAL)
    float getIndicatorIndexNodesScale()
    void setAutoScrollStopEpsilon(float epsilon)
]]
cls.callback {
    FUNCS =  {
        'void addEventListener(@nullable const std::function<void(Ref*, PageView::EventType)>& callback)',
    },
    TAG_MAKER = 'olua_makecallbacktag("PageViewCallback")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
    CALLONCE = false,
    REMOVE = false,
}
cls.alias('addEventListener', 'addPageViewEventListener')
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

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::PageViewIndicator"
cls.SUPERCLS = "cocos2d::ProtectedNode"
cls.funcs [[
    static PageViewIndicator* create()
    void setDirection(PageView::Direction direction)
    void reset(ssize_t numberOfTotalPages)
    void indicate(ssize_t index)
    void clear()
    void setSpaceBetweenIndexNodes(float spaceBetweenIndexNodes)
    float getSpaceBetweenIndexNodes()
    void setSelectedIndexColor(const Color3B& color)
    const Color3B& getSelectedIndexColor()
    void setIndexNodesColor(const Color3B& indexNodesColor)
    const Color3B& getIndexNodesColor()
    void setIndexNodesScale(float indexNodesScale)
    float getIndexNodesScale()
    void setSelectedIndexOpacity(GLubyte opacity)
    GLubyte getSelectedIndexOpacity()
    void setIndexNodesOpacity(GLubyte opacity)
    GLubyte getIndexNodesOpacity()
    void setIndexNodesTexture(const std::string& texName,Widget::TextureResType texType = Widget::TextureResType::LOCAL)
]]
cls.props [[
    spaceBetweenIndexNodes
    selectedIndexColor
    indexNodesColor
    indexNodesScale
    selectedIndexOpacity
    indexNodesOpacity
]]

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::RichElement::Type"
cls.enums [[
    TEXT
    IMAGE
    CUSTOM
    NEWLINE
]]

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::RichElement"
cls.SUPERCLS = "cocos2d::Ref"
cls.funcs [[
    bool init(int tag, const Color3B& color, GLubyte opacity)
    bool equalType(Type type)
    void setColor(const Color3B& color)
]]

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::RichElementText"
cls.SUPERCLS = "cocos2d::ui::RichElement"
cls.funcs [[
    bool init(int tag, const Color3B& color, GLubyte opacity, const std::string& text, const std::string& fontName, float fontSize, uint32_t flags, const std::string& url, const Color3B& outlineColor = Color3B::WHITE, int outlineSize = -1, const Color3B& shadowColor = Color3B::BLACK, const cocos2d::Size& shadowOffset = Size(2.0, -2.0), int shadowBlurRadius = 0, const Color3B& glowColor = Color3B::WHITE)
    static RichElementText* create(int tag, const Color3B& color, GLubyte opacity, const std::string& text, const std::string& fontName, float fontSize, uint32_t flags=0, const std::string& url="", const Color3B& outlineColor = Color3B::WHITE, int outlineSize = -1, const Color3B& shadowColor = Color3B::BLACK, const cocos2d::Size& shadowOffset = Size(2.0, -2.0), int shadowBlurRadius = 0, const Color3B& glowColor = Color3B::WHITE)
]]

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::RichElementImage"
cls.SUPERCLS = "cocos2d::ui::RichElement"
cls.funcs [[
    bool init(int tag, const Color3B& color, GLubyte opacity, const std::string& filePath, const std::string& url = "", Widget::TextureResType texType = Widget::TextureResType::LOCAL)
    static RichElementImage* create(int tag, const Color3B& color, GLubyte opacity, const std::string& filePath, const std::string& url = "", Widget::TextureResType texType = Widget::TextureResType::LOCAL)
    void setWidth(int width)
    void setHeight(int height)
    void setUrl(const std::string& url)
]]

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::RichElementCustomNode"
cls.SUPERCLS = "cocos2d::ui::RichElement"
cls.funcs [[
    bool init(int tag, const Color3B& color, GLubyte opacity, Node* customNode)
    static RichElementCustomNode* create(int tag, const Color3B& color, GLubyte opacity, Node* customNode)
]]

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::RichElementNewLine"
cls.SUPERCLS = "cocos2d::ui::RichElement"
cls.funcs [[
    static RichElementNewLine* create(int tag, const Color3B& color, GLubyte opacity)
]]

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::RichText::WrapMode"
cls.enums [[
    WRAP_PER_WORD
    WRAP_PER_CHAR
]]

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::RichText::HorizontalAlignment"
cls.enums [[
    LEFT
    CENTER
    RIGHT
]]

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::RichText"
cls.SUPERCLS = "cocos2d::ui::Widget"
cls.funcs [[
    static RichText* create()
    void insertElement(RichElement* element, int index)
    void pushBackElement(RichElement* element)
    void removeElement(int index)
    void removeElement(RichElement* element)
    void setVerticalSpace(float space)
    void formatText()
    void setWrapMode(WrapMode wrapMode)
    WrapMode getWrapMode()
    void setHorizontalAlignment(HorizontalAlignment a)
    HorizontalAlignment getHorizontalAlignment()
    void setFontColor(const std::string& color)
    std::string getFontColor()
    Color3B getFontColor3B()
    void setFontSize(float size)
    float getFontSize()
    void setFontFace(const std::string& face)
    std::string getFontFace()
    void setAnchorFontColor(const std::string& color)
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
    void setAnchorTextOutline(bool enable, const Color3B& outlineColor = Color3B::WHITE, int outlineSize = -1)
    bool isAnchorTextOutlineEnabled()
    Color3B getAnchorTextOutlineColor3B()
    int getAnchorTextOutlineSize()
    void setAnchorTextShadow(bool enable, const Color3B& shadowColor = Color3B::BLACK, const Size& offset = Size(2.0, -2.0), int blurRadius = 0)
    bool isAnchorTextShadowEnabled()
    Color3B getAnchorTextShadowColor3B()
    Size getAnchorTextShadowOffset()
    int getAnchorTextShadowBlurRadius()
    void setAnchorTextGlow(bool enable, const Color3B& glowColor = Color3B::WHITE)
    bool isAnchorTextGlowEnabled()
    Color3B getAnchorTextGlowColor3B()
    void setDefaults(const ValueMap& defaults)
    ValueMap getDefaults()
    cocos2d::Color3B color3BWithString(const std::string& color)
    std::string stringWithColor3B(const cocos2d::Color3B& color3b)
    std::string stringWithColor4B(const cocos2d::Color4B& color4b)
    static void removeTagDescription(const std::string& tag)
    void openUrl(const std::string& url)
]]
cls.callback {
    FUNCS =  {
        'void setOpenUrlHandler(const std::function<void(const std::string& url)>& handleOpenUrl)',
    },
    TAG_MAKER = 'olua_makecallbacktag("openUrlHandler")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
    CALLONCE = false,
    REMOVE = false,
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

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::ScrollViewBar"
cls.SUPERCLS = "cocos2d::ProtectedNode"
cls.funcs [[
    static ScrollViewBar* create(ScrollView* parent, ScrollView::Direction direction)
    void setPositionFromCorner(const Vec2& positionFromCorner)
    Vec2 getPositionFromCorner()
    void setWidth(float width)
    float getWidth()
    void setAutoHideEnabled(bool autoHideEnabled)
    bool isAutoHideEnabled()
    void setAutoHideTime(float autoHideTime)
    float getAutoHideTime()
    void onScrolled(const Vec2& outOfBoundary)
    void onTouchBegan()
    void onTouchEnded()
]]
cls.props [[
    positionFromCorner
    width
    autoHideEnabled
    autoHideTime
]]

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::Slider::EventType"
cls.enums [[
    ON_PERCENTAGE_CHANGED
    ON_SLIDEBALL_DOWN
    ON_SLIDEBALL_UP
    ON_SLIDEBALL_CANCEL
]]

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::Slider"
cls.SUPERCLS = "cocos2d::ui::Widget"
cls.funcs [[
    static Slider* create()
    static Slider* create(const std::string& barTextureName, const std::string& normalBallTextureName, TextureResType resType = TextureResType::LOCAL)
    void loadBarTexture(const std::string& fileName,TextureResType resType = TextureResType::LOCAL)
    void setScale9Enabled(bool able)
    bool isScale9Enabled()
    void setCapInsets(const Rect &capInsets)
    void setCapInsetsBarRenderer(const Rect &capInsets)
    const Rect& getCapInsetsBarRenderer()
    void setCapInsetProgressBarRenderer(const Rect &capInsets)
    const Rect& getCapInsetsProgressBarRenderer()
    void loadSlidBallTextures(const std::string& normal, const std::string& pressed = "", const std::string& disabled = "", TextureResType texType = TextureResType::LOCAL)
    void loadSlidBallTextureNormal(const std::string& normal,TextureResType resType = TextureResType::LOCAL)
    void loadSlidBallTexturePressed(const std::string& pressed,TextureResType resType = TextureResType::LOCAL)
    void loadSlidBallTextureDisabled(const std::string& disabled,TextureResType resType = TextureResType::LOCAL)
    void loadProgressBarTexture(const std::string& fileName, TextureResType resType = TextureResType::LOCAL)
    void setPercent(int percent)
    void updateVisualSlider()
    int getPercent()
    void setMaxPercent(int percent)
    int getMaxPercent()
    void setZoomScale(float scale)
    float getZoomScale()
    @ref(map protectedChildren) Sprite* getSlidBallNormalRenderer()
    @ref(map protectedChildren) Sprite* getSlidBallPressedRenderer()
    @ref(map protectedChildren) Sprite* getSlidBallDisabledRenderer()
    @ref(map protectedChildren) Node* getSlidBallRenderer()
    ResourceData getBackFile()
    ResourceData getProgressBarFile()
    ResourceData getBallNormalFile()
    ResourceData getBallPressedFile()
    ResourceData getBallDisabledFile()
]]
cls.callback {
    FUNCS =  {
        'void addEventListener(@nullable const std::function<void(Ref*,EventType)>& callback)',
    },
    TAG_MAKER = 'olua_makecallbacktag("sliderCallback")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
    CALLONCE = false,
    REMOVE = false,
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

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::Text::Type"
cls.enums [[
    SYSTEM
    TTF
]]

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::Text"
cls.SUPERCLS = "cocos2d::ui::Widget"
cls.funcs [[
    static Text* create()
    static Text* create(const std::string& textContent, const std::string& fontName, float fontSize)
    void setString(const std::string& text)
    const std::string& getString()
    ssize_t getStringLength()
    void setFontSize(float size)
    float getFontSize()
    void setFontName(const std::string& name)
    const std::string& getFontName()
    Type getType()
    void setTouchScaleChangeEnabled(bool enabled)
    bool isTouchScaleChangeEnabled()
    Size getAutoRenderSize()
    void setTextAreaSize(const Size &size)
    const Size& getTextAreaSize()
    void setTextHorizontalAlignment(TextHAlignment alignment)
    TextHAlignment getTextHorizontalAlignment()
    void setTextVerticalAlignment(TextVAlignment alignment)
    TextVAlignment getTextVerticalAlignment()
    void setTextColor(const Color4B color)
    const Color4B& getTextColor()
    void enableShadow(const Color4B& shadowColor = Color4B::BLACK, const Size &offset = Size(2,-2), int blurRadius = 0)
    void enableOutline(const Color4B& outlineColor,int outlineSize = 1)
    void enableGlow(const Color4B& glowColor)
    void disableEffect()
    void disableEffect(LabelEffect effect)
    bool isShadowEnabled()
    Size getShadowOffset()
    float getShadowBlurRadius()
    Color4B getShadowColor()
    int getOutlineSize()
    LabelEffect getLabelEffectType()
    Color4B getEffectColor()
    Sprite * getLetter(int lettetIndex)
    void setBlendFunc(const BlendFunc &blendFunc)
    const BlendFunc &getBlendFunc()
    bool init(const std::string& textContent, const std::string& fontName, float fontSize)
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

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::TextAtlas"
cls.SUPERCLS = "cocos2d::ui::Widget"
cls.funcs [[
    static TextAtlas* create()
    static TextAtlas* create(const std::string& stringValue, const std::string& charMapFile, int itemWidth, int itemHeight, const std::string& startCharMap)
    void setProperty(const std::string& stringValue, const std::string& charMapFile, int itemWidth, int itemHeight, const std::string& startCharMap)
    void setString(const std::string& value)
    const std::string& getString()
    ssize_t getStringLength()
    ResourceData getRenderFile()
]]
cls.props [[
    string
    stringLength
    renderFile
]]

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::TextBMFont"
cls.SUPERCLS = "cocos2d::ui::Widget"
cls.funcs [[
    static TextBMFont* create()
    static TextBMFont* create(const std::string& text, const std::string& filename)
    void setFntFile(const std::string& fileName)
    void setString(const std::string& value)
    const std::string& getString()
    ssize_t getStringLength()
    ResourceData getRenderFile()
    void resetRender()
]]
cls.props [[
    string
    stringLength
    renderFile
]]

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::UICCTextField"
cls.SUPERCLS = "cocos2d::TextFieldTTF"
cls.funcs [[
    static UICCTextField* create()
    static UICCTextField* create(const std::string& placeholder, const std::string& fontName, float fontSize)
    bool onTextFieldAttachWithIME(TextFieldTTF *pSender)
    bool onTextFieldDetachWithIME(TextFieldTTF * pSender)
    bool onTextFieldInsertText(TextFieldTTF * pSender, const char * text, size_t nLen)
    bool onTextFieldDeleteBackward(TextFieldTTF * pSender, const char * delText, size_t nLen)
    void openIME()
    void closeIME()
    void setMaxLengthEnabled(bool enable)
    bool isMaxLengthEnabled()
    void setMaxLength(int length)
    int getMaxLength()
    void setPasswordEnabled(bool enable)
    bool isPasswordEnabled()
    void setPasswordStyleText(const std::string& styleText)
    void setPasswordText(const std::string& text)
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

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::TextField::EventType"
cls.enums [[
    ATTACH_WITH_IME
    DETACH_WITH_IME
    INSERT_TEXT
    DELETE_BACKWARD
]]

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::TextField"
cls.SUPERCLS = "cocos2d::ui::Widget"
cls.funcs [[
    static TextField* create()
    static TextField* create(const std::string& placeholder, const std::string& fontName, int fontSize)
    void setTouchSize(const Size &size)
    Size getTouchSize()
    void setTouchAreaEnabled(bool enable)
    void setPlaceHolder(const std::string& value)
    const std::string& getPlaceHolder()
    const Color4B& getPlaceHolderColor()
    void setPlaceHolderColor(const Color3B& color)
    void setPlaceHolderColor(const Color4B& color)
    const Color4B& getTextColor()
    void setTextColor(const Color4B& textColor)
    void setFontSize(int size)
    int getFontSize()
    void setFontName(const std::string& name)
    const std::string& getFontName()
    void didNotSelectSelf()
    void setString(const std::string& text)
    const std::string& getString()
    void setMaxLengthEnabled(bool enable)
    bool isMaxLengthEnabled()
    void setMaxLength(int length)
    int getMaxLength()
    int getStringLength()
    void setPasswordEnabled(bool enable)
    bool isPasswordEnabled()
    void setPasswordStyleText(const char* styleText)
    const char* getPasswordStyleText()
    bool getAttachWithIME()
    void setAttachWithIME(bool attach)
    bool getDetachWithIME()
    void setDetachWithIME(bool detach)
    bool getInsertText()
    void setInsertText(bool insertText)
    bool getDeleteBackward()
    void setDeleteBackward(bool deleteBackward)
    Size getAutoRenderSize()
    void attachWithIME()
    void setTextAreaSize(const Size &size)
    void setTextHorizontalAlignment(TextHAlignment alignment)
    TextHAlignment getTextHorizontalAlignment()
    void setTextVerticalAlignment(TextVAlignment alignment)
    TextVAlignment getTextVerticalAlignment()
    void setCursorEnabled(bool enabled)
    void setCursorChar(char cursor)
    void setCursorPosition(std::size_t cursorPosition)
    void setCursorFromPoint(const Vec2 &point, const Camera* camera)
]]
cls.callback {
    FUNCS =  {
        'void addEventListener(@nullable const std::function<void(Ref*, EventType)>& callback)',
    },
    TAG_MAKER = 'olua_makecallbacktag("textFieldCallback")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
    CALLONCE = false,
    REMOVE = false,
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

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::Button"
cls.SUPERCLS = "cocos2d::ui::Widget"
cls.funcs [[
    static Button* create()
    static Button* create(const std::string& normalImage, const std::string& selectedImage = "", const std::string& disableImage = "", TextureResType texType = TextureResType::LOCAL)
    void loadTextures(const std::string& normal, const std::string& selected, const std::string& disabled = "", TextureResType texType = TextureResType::LOCAL)
    void loadTextureNormal(const std::string& normal, TextureResType texType = TextureResType::LOCAL)
    void loadTexturePressed(const std::string& selected, TextureResType texType = TextureResType::LOCAL)
    void loadTextureDisabled(const std::string& disabled, TextureResType texType = TextureResType::LOCAL)
    void setCapInsets(const Rect &capInsets)
    void setCapInsetsNormalRenderer(const Rect &capInsets)
    const Rect& getCapInsetsNormalRenderer()
    void setCapInsetsPressedRenderer(const Rect &capInsets)
    const Rect& getCapInsetsPressedRenderer()
    void setCapInsetsDisabledRenderer(const Rect &capInsets)
    const Rect& getCapInsetsDisabledRenderer()
    void setScale9Enabled(bool enable)
    bool isScale9Enabled()
    void setPressedActionEnabled(bool enabled)
    @ref(map protectedChildren) Label* getTitleRenderer()
    void setTitleText(const std::string& text)
    std::string getTitleText()
    void setTitleColor(const Color3B& color)
    Color3B getTitleColor()
    void setTitleFontSize(float size)
    float getTitleFontSize()
    void setTitleFontName(const std::string& fontName)
    std::string getTitleFontName()
    void setTitleAlignment(TextHAlignment hAlignment)
    void setTitleAlignment(TextHAlignment hAlignment, TextVAlignment vAlignment)
    void setTitleLabel(@ref(map protectedChildren) Label* label)
    @ref(map protectedChildren) Label* getTitleLabel()
    void setZoomScale(float scale)
    float getZoomScale()
    @ref(map protectedChildren) Scale9Sprite* getRendererNormal()
    @ref(map protectedChildren) Scale9Sprite* getRendererClicked()
    @ref(map protectedChildren) Scale9Sprite* getRendererDisabled()
    void resetNormalRender()
    void resetPressedRender()
    void resetDisabledRender()
    ResourceData getNormalFile()
    ResourceData getPressedFile()
    ResourceData getDisabledFile()
    bool init(const std::string& normalImage, const std::string& selectedImage = "", const std::string& disableImage = "", TextureResType texType = TextureResType::LOCAL)
    Size getNormalTextureSize()
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

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::CheckBox::EventType"
cls.enums [[
    SELECTED
    UNSELECTED
]]

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::CheckBox"
cls.SUPERCLS = "cocos2d::ui::AbstractCheckButton"
cls.funcs [[
    static CheckBox* create()
    static CheckBox* create(const std::string& backGround, const std::string& backGroundSelected, const std::string& cross, const std::string& backGroundDisabled, const std::string& frontCrossDisabled, TextureResType texType = TextureResType::LOCAL)
    static CheckBox* create(const std::string& backGround, const std::string& cross, TextureResType texType = TextureResType::LOCAL)
]]
cls.callback {
    FUNCS =  {
        'void addEventListener(@nullable const std::function<void(Ref*,CheckBox::EventType)>& callback)',
    },
    TAG_MAKER = 'olua_makecallbacktag("checkBoxCallback")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
    CALLONCE = false,
    REMOVE = false,
}

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::RadioButton::EventType"
cls.enums [[
    SELECTED
    UNSELECTED
]]

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::RadioButton"
cls.SUPERCLS = "cocos2d::ui::AbstractCheckButton"
cls.funcs [[
    static RadioButton* create()
    static RadioButton* create(const std::string& backGround, const std::string& backGroundSelected, const std::string& cross, const std::string& backGroundDisabled, const std::string& frontCrossDisabled, TextureResType texType = TextureResType::LOCAL)
    static RadioButton* create(const std::string& backGround, const std::string& cross, TextureResType texType = TextureResType::LOCAL)
]]
cls.callback {
    FUNCS =  {
        'void addEventListener(@nullable const std::function<void(RadioButton* radioButton, EventType)>& callback)',
    },
    TAG_MAKER = 'olua_makecallbacktag("radioButtonCallback")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
    CALLONCE = false,
    REMOVE = false,
}

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::RadioButtonGroup::EventType"
cls.enums [[
    SELECT_CHANGED
]]

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::RadioButtonGroup"
cls.SUPERCLS = "cocos2d::ui::Widget"
cls.funcs [[
    static RadioButtonGroup* create()
    int getSelectedButtonIndex()
    void setSelectedButton(int index)
    void setSelectedButton(RadioButton* radioButton)
    void setSelectedButtonWithoutEvent(int index)
    void setSelectedButtonWithoutEvent(RadioButton* radioButton)
    void addRadioButton(RadioButton* radioButton)
    void removeRadioButton(RadioButton* radioButton)
    void removeAllRadioButtons()
    ssize_t getNumberOfRadioButtons()
    RadioButton* getRadioButtonByIndex(int index)
    void setAllowedNoSelection(bool allowedNoSelection)
    bool isAllowedNoSelection()
]]
cls.callback {
    FUNCS =  {
        'void addEventListener(@nullable const std::function<void(RadioButton* radioButton, int index, EventType)>& callback)',
    },
    TAG_MAKER = 'olua_makecallbacktag("radioButtonCallback")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
    CALLONCE = false,
    REMOVE = false,
}
cls.props [[
    selectedButtonIndex
    numberOfRadioButtons
    allowedNoSelection
]]

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::ImageView"
cls.SUPERCLS = "cocos2d::ui::Widget"
cls.funcs [[
    static ImageView* create()
    static ImageView* create(const std::string& imageFileName, TextureResType texType = TextureResType::LOCAL)
    void loadTexture(const std::string& fileName,TextureResType texType = TextureResType::LOCAL)
    void setTextureRect(const Rect& rect)
    void setScale9Enabled(bool enabled)
    bool isScale9Enabled()
    void setCapInsets(const Rect &capInsets)
    const Rect& getCapInsets()
    void setBlendFunc(const BlendFunc &blendFunc)
    const BlendFunc &getBlendFunc()
    ResourceData getRenderFile()
    bool init(const std::string& imageFileName, TextureResType texType = TextureResType::LOCAL)
]]
cls.props [[
    scale9Enabled
    capInsets
    blendFunc
    renderFile
]]

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::EditBoxDelegate::EditBoxEndAction"
cls.enums [[
    UNKNOWN
    TAB_TO_NEXT
    TAB_TO_PREVIOUS
    RETURN
]]

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::EditBoxDelegate"
cls.funcs [[
    void editBoxEditingDidBegin(EditBox* )
    void editBoxTextChanged(EditBox* , const std::string& )
    void editBoxReturn(EditBox* editBox)
    void editBoxEditingDidEndWithAction(EditBox* , EditBoxEndAction )
]]

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::LuaEditBoxDelegate"
cls.SUPERCLS = "cocos2d::ui::EditBoxDelegate"
cls.funcs [[
    static LuaEditBoxDelegate *create()
]]
cls.var('onEditingDidBegin', [[@nullable std::function<void(EditBox *)> onEditingDidBegin]])
cls.var('onTextChanged', [[@nullable std::function<void(EditBox *, const std::string &)> onTextChanged]])
cls.var('onReturn', [[@nullable std::function<void(EditBox *)> onReturn]])
cls.var('onEditingDidEndWithAction', [[@nullable std::function<void(EditBox *, EditBoxDelegate::EditBoxEndAction)> onEditingDidEndWithAction]])

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::EditBox::KeyboardReturnType"
cls.enums [[
    DEFAULT
    DONE
    SEND
    SEARCH
    GO
    NEXT
]]

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::EditBox::InputMode"
cls.enums [[
    ANY
    EMAIL_ADDRESS
    NUMERIC
    PHONE_NUMBER
    URL
    DECIMAL
    SINGLE_LINE
]]

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::EditBox::InputFlag"
cls.enums [[
    PASSWORD
    SENSITIVE
    INITIAL_CAPS_WORD
    INITIAL_CAPS_SENTENCE
    INITIAL_CAPS_ALL_CHARACTERS
    LOWERCASE_ALL_CHARACTERS
]]

cls = class(M.CLASSES)
cls.CPPCLS = "cocos2d::ui::EditBox"
cls.SUPERCLS = "cocos2d::ui::Widget"
cls.funcs [[
    static EditBox* create(const Size& size, Scale9Sprite* normalSprite, Scale9Sprite* pressedSprite = nullptr, Scale9Sprite* disabledSprite = nullptr)
    static EditBox* create(const Size& size, const std::string& normalImage, TextureResType texType)
    static EditBox* create(const Size& size, const std::string& normalImage, const std::string& pressedImage = "", const std::string& disabledImage = "", TextureResType texType = TextureResType::LOCAL)
    bool initWithSizeAndBackgroundSprite(const Size& size, const std::string& normal9SpriteBg, TextureResType texType = TextureResType::LOCAL)
    bool initWithSizeAndBackgroundSprite(const Size& size, Scale9Sprite* normal9SpriteBg)
    bool initWithSizeAndBackgroundSprite(const Size& size, Scale9Sprite* normalSprite, Scale9Sprite* pressedSprite, Scale9Sprite* disabledSprite)
    bool initWithSizeAndTexture(const Size& size, const std::string& normalImage, const std::string& pressedImage = "", const std::string& disabledImage = "", TextureResType texType = TextureResType::LOCAL)
    void loadTextures(const std::string& normal, const std::string& pressed, const std::string& disabled = "", TextureResType texType = TextureResType::LOCAL)
    void loadTextureNormal(const std::string& normal, TextureResType texType = TextureResType::LOCAL)
    void loadTexturePressed(const std::string& pressed, TextureResType texType = TextureResType::LOCAL)
    void loadTextureDisabled(const std::string& disabled, TextureResType texType = TextureResType::LOCAL)
    void setCapInsets(const Rect &capInsets)
    void setCapInsetsNormalRenderer(const Rect &capInsets)
    const Rect& getCapInsetsNormalRenderer()
    void setCapInsetsPressedRenderer(const Rect &capInsets)
    const Rect& getCapInsetsPressedRenderer()
    void setCapInsetsDisabledRenderer(const Rect &capInsets)
    const Rect& getCapInsetsDisabledRenderer()
    void setDelegate(@ref(single delegate) EditBoxDelegate* delegate)
    @ref(single delegate) EditBoxDelegate* getDelegate()
    void setText(const char* pText)
    const char* getText()
    void setFont(const char* pFontName, int fontSize)
    void setFontName(const char* pFontName)
    const char* getFontName()
    void setFontSize(int fontSize)
    int getFontSize()
    void setFontColor(const Color3B& color)
    void setFontColor(const Color4B& color)
    const Color4B& getFontColor()
    void setPlaceholderFont(const char* pFontName, int fontSize)
    void setPlaceholderFontName(const char* pFontName)
    const char* getPlaceholderFontName()
    void setPlaceholderFontSize(int fontSize)
    int getPlaceholderFontSize()
    void setPlaceholderFontColor(const Color3B& color)
    void setPlaceholderFontColor(const Color4B& color)
    const Color4B& getPlaceholderFontColor()
    void setPlaceHolder(const char* pText)
    const char* getPlaceHolder()
    void setInputMode(InputMode inputMode)
    InputMode getInputMode()
    void setMaxLength(int maxLength)
    int getMaxLength()
    void setInputFlag(InputFlag inputFlag)
    InputFlag getInputFlag()
    void setReturnType(KeyboardReturnType returnType)
    KeyboardReturnType getReturnType()
    void setTextHorizontalAlignment(TextHAlignment alignment)
    TextHAlignment getTextHorizontalAlignment()
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

return M
