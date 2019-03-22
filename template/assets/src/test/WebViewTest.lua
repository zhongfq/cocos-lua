local runtime = require "kernel.runtime"

local M = {}

M.available = runtime.os == 'android' or runtime.os == 'ios'

function M.new()
    local Director  = require "cc.Director"
    local Scene     = require "cc.Scene"
    local WebView   = require "ccui.WebView"

    local scene = Scene.create()

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

    scene:addChild(webview)

    return scene
end
    
return M