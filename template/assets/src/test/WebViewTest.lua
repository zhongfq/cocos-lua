-- TODO: use class

local runtime = require "kernel.runtime"

if runtime.os ~= 'android' and runtime.os ~= 'ios' then
    print("WebViewTest not support:", runtime.os)
    return
end

local Director  = require "cc.Director"
local WebView   = require "ccui.WebView"

local rootscene = Director.instance.runningScene

local webview = WebView.create()
webview.ignoreAnchorPointForPosition = true
webview.width = 1000
webview.height = 700
webview:loadURL("https://www.baidu.com")
webview.onShouldStartLoading = function (...)
    print("[WebView] onShouldStartLoading", ...)
    return true
end

webview.onDidFinishLoading = function (...)
    print("[WebView] onDidFinishLoading", ...)
end

webview.onDidFailLoading = function (...)
    print("[WebView] onDidFailLoading", ...)
end

webview.onJSCallback = function (...)
    print("[WebView] onJSCallback", ...)
end

rootscene:addChild(webview)
    