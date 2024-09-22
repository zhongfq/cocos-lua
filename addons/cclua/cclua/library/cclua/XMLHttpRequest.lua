---AUTO GENERATED, DO NOT MODIFY!
---@meta cclua.XMLHttpRequest

---
---@class cclua.XMLHttpRequest : cc.Ref
---@field aborted boolean 
---@field allResponseHeaders { [string]: string } 
---@field dataSize integer 
---@field dataStr string 
---@field errorFlag boolean 
---@field readyState integer 
---@field response any 
---@field responseType cclua.XMLHttpRequest.ResponseType 
---@field responseURL string 
---@field status integer 
---@field statusText string 
---@field timeout integer 
---@field url string 
---@field withCredentials boolean 
---@field DONE integer
---@field HEADERS_RECEIVED integer
---@field LOADING integer
---@field OPENED integer
---@field UNSENT integer
local XMLHttpRequest = {}

function XMLHttpRequest:abort() end

---@return { [string]: string }
function XMLHttpRequest:getAllResponseHeaders() end

---@return integer
function XMLHttpRequest:getDataSize() end

---@return string
function XMLHttpRequest:getDataStr() end

---@return boolean
function XMLHttpRequest:getErrorFlag() end

---@return integer
function XMLHttpRequest:getReadyState() end

---@return any
function XMLHttpRequest.getResponse() end

---@param name string
---@return string
function XMLHttpRequest:getResponseHeader(name) end

---@return cclua.XMLHttpRequest.ResponseType
function XMLHttpRequest:getResponseType() end

---@return string
function XMLHttpRequest:getResponseURL() end

---@return integer
function XMLHttpRequest:getStatus() end

---@return string
function XMLHttpRequest:getStatusText() end

---@return integer
function XMLHttpRequest:getTimeout() end

---@return string
function XMLHttpRequest:getURL() end

---@return boolean
function XMLHttpRequest:getWithCredentials() end

---@return boolean
function XMLHttpRequest:isAborted() end

---@return cclua.XMLHttpRequest
function XMLHttpRequest.new() end

---@param method string
---@param url string
function XMLHttpRequest:open(method, url) end

---@param data any
---@overload fun(self: cclua.XMLHttpRequest)
function XMLHttpRequest:send(data) end

---@param errorFlag boolean
function XMLHttpRequest:setErrorFlag(errorFlag) end

---@param name string
---@param value string
function XMLHttpRequest:setRequestHeader(name, value) end

---@param handler fun(arg1: integer)
function XMLHttpRequest:setResponseCallback(handler) end

---@param value cclua.XMLHttpRequest.ResponseType
function XMLHttpRequest:setResponseType(value) end

---@param value integer
function XMLHttpRequest:setTimeout(value) end

---@param value boolean
function XMLHttpRequest:setWithCredentials(value) end

return XMLHttpRequest