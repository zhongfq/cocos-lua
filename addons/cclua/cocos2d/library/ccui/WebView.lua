---AUTO GENERATED, DO NOT MODIFY!
---@meta ccui.WebView

---A View that displays web pages. 
---
---\note WebView displays web pages base on system widget.
---It's mean WebView displays web pages above all graphical elements of cocos2d-x.
---\js NA
---@class ccui.WebView : ccui.Widget
---@field onDidFailLoading ccui.WebView.ccWebViewCallback Get the callback when WebView has failed loading.
---@field onDidFinishLoading ccui.WebView.ccWebViewCallback Get the callback when WebView has finished loading.
---@field onJSCallback ccui.WebView.ccWebViewCallback Get the Javascript callback.
---@field onShouldStartLoading fun(arg1: ccui.WebView, arg2: string): boolean Get the callback when WebView is about to start.
---@field opacityWebView number getOpacity of webview.
local WebView = {}

---Gets whether this WebView has a back history item.
---
---@return boolean # WebView has a back history item.
function WebView:canGoBack() end

---Gets whether this WebView has a forward history item.
---
---@return boolean # WebView has a forward history item.
function WebView:canGoForward() end

---Allocates and initializes a WebView.
---@return ccui.WebView
function WebView.create() end

---Evaluates JavaScript in the context of the currently displayed page.
---@param js string
function WebView:evaluateJS(js) end

---Get the callback when WebView has failed loading.
---@return ccui.WebView.ccWebViewCallback
function WebView:getOnDidFailLoading() end

---Get the callback when WebView has finished loading.
---@return ccui.WebView.ccWebViewCallback
function WebView:getOnDidFinishLoading() end

---Get the Javascript callback.
---@return ccui.WebView.ccWebViewCallback
function WebView:getOnJSCallback() end

---Get the callback when WebView is about to start.
---@return fun(arg1: ccui.WebView, arg2: string): boolean
function WebView:getOnShouldStartLoading() end

---getOpacity of webview.
---@return number
function WebView:getOpacityWebView() end

---Goes back in the history.
function WebView:goBack() end

---Goes forward in the history.
function WebView:goForward() end

---Sets the main page contents, MIME type, content encoding, and base URL.
---
---@param data any # The content for the main page.
---@param MIMEType string # The MIME type of the data.
---@param encoding string # The encoding of the data.
---@param baseURL string # The base URL for the content.
function WebView:loadData(data, MIMEType, encoding, baseURL) end

---Loads the given fileName.
---
---@param fileName string # Content fileName.
function WebView:loadFile(fileName) end

---Sets the main page content and base URL.
---
---@param string string # The content for the main page.
---@param baseURL string # The base URL for the content.
---@overload fun(self: ccui.WebView, string: string)
function WebView:loadHTMLString(string, baseURL) end

---Loads the given URL. It doesn't clean cached data.
---
---@param url string # Content URL.
---
---Loads the given URL with cleaning cached data or not.
---\param url Content URL.
---\cleanCachedData Whether to clean cached data.
---@overload fun(self: ccui.WebView, url: string, cleanCachedData: boolean)
function WebView:loadURL(url) end

---Default constructor.
---@return ccui.WebView
function WebView.new() end

---Reloads the current URL.
function WebView:reload() end

---set the background transparent
function WebView:setBackgroundTransparent() end

---Set whether the webview bounces at end of scroll of WebView.
---@param bounce boolean
function WebView:setBounces(bounce) end

---Set javascript interface scheme.
---
---\see WebView::setOnJSCallback()
---@param scheme string
function WebView:setJavascriptInterfaceScheme(scheme) end

---Call if a web view failed to load content.
---
---@param callback ccui.WebView.ccWebViewCallback # The web view that has failed loading.
function WebView:setOnDidFailLoading(callback) end

---Call after a web view finishes loading.
---
---@param callback ccui.WebView.ccWebViewCallback # The web view that has finished loading.
function WebView:setOnDidFinishLoading(callback) end

---This callback called when load URL that start with javascript interface scheme.
---@param callback ccui.WebView.ccWebViewCallback
function WebView:setOnJSCallback(callback) end

---Call before a web view begins loading.
---
---@param callback fun(arg1: ccui.WebView, arg2: string): boolean # The web view that is about to load new content.
---\return YES if the web view should begin loading content; otherwise, NO.
function WebView:setOnShouldStartLoading(callback) end

---SetOpacity of webview.
---@param opacity number
function WebView:setOpacityWebView(opacity) end

---Set WebView should support zooming. The default value is false.
---@param scalesPageToFit boolean
function WebView:setScalesPageToFit(scalesPageToFit) end

---Stops the current load.
function WebView:stopLoading() end

return WebView