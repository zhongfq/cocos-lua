local cls = class()
cls.CPPCLS = "cocos2d::experimental::ui::WebView"
cls.LUACLS = "ccui.WebView"
cls.SUPERCLS = "ccui.Widget"
cls.DEFIF = '#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_TIZEN)'
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
    void draw(cocos2d::Renderer *renderer, cocos2d::Mat4 const &transform, uint32_t flags)
    void setOpacityWebView(float opacity)
    float getOpacityWebView()
    void setBackgroundTransparent()
]]

cls.callbacks([[
    void setOnShouldStartLoading(@nullable const std::function<bool(WebView *sender, const std::string &url)>& callback)
    void setOnDidFinishLoading(@nullable const std::function<void(WebView *sender, const std::string &url)>& callback)
    void setOnDidFailLoading(@nullable const std::function<void(WebView *sender, const std::string &url)>& callback)
    void setOnJSCallback(@nullable const std::function<void(WebView *sender, const std::string &url)>& callback)
    std::function<bool(WebView *sender, const std::string &url)> getOnShouldStartLoading()
    std::function<void(WebView *sender, const std::string &url)> getOnDidFinishLoading()
    std::function<void(WebView *sender, const std::string &url)> getOnDidFailLoading()
    std::function<void(WebView *sender, const std::string &url)> getOnJSCallback()
]])

cls.props [[
    onShouldStartLoading
    onDidFinishLoading
    onDidFailLoading
    onJSCallback
]]

return cls