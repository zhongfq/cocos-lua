---AUTO GENERATED, DO NOT MODIFY!
---@meta cclua.downloader

---
---@class cclua.downloader 
local downloader = {}

---@return any
function downloader:__gc() end

function downloader.end_() end

function downloader.init() end

---@param uri string
---@param path string
---@param md5 string
---@overload fun(uri: string, path: string)
function downloader.load(uri, path, md5) end

---@param dispatcher cclua.Callback
function downloader.setDispatcher(dispatcher) end

---@param resolver fun(arg1: string): string
function downloader.setURIResolver(resolver) end

return downloader