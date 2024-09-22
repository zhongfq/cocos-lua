---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.WebSocket

---WebSocket is wrapper of the libwebsockets-protocol, let the develop could call the websocket easily.
---Please note that all public methods of WebSocket have to be invoked on Cocos Thread.
---@class cc.WebSocket 
---@field protocol string Gets the protocol selected by websocket server.
---@field readyState cc.WebSocket.State Gets current state of connection. \return State the state value could be State::CONNECTING, State::OPEN, State::CLOSING or State::CLOSED
---@field url string Gets the URL of websocket connection.
local WebSocket = {}

---@return any
function WebSocket:__gc() end

---Closes the connection to server synchronously.
---\note It's a synchronous method, it will not return until websocket thread exits.
function WebSocket:close() end

---Close all connections and wait for all websocket threads to exit
---\note This method has to be invoked on Cocos Thread
function WebSocket.closeAllConnections() end

---Closes the connection to server asynchronously.
---\note It's an asynchronous method, it just notifies websocket thread to exit and returns directly,
---If using 'closeAsync' to close websocket connection, 
---be careful of not using destructed variables in the callback of 'onClose'.
function WebSocket:closeAsync() end

---Gets the protocol selected by websocket server.
---@return string
function WebSocket:getProtocol() end

---Gets current state of connection.
---@return cc.WebSocket.State # State the state value could be State::CONNECTING, State::OPEN, State::CLOSING or State::CLOSED
function WebSocket:getReadyState() end

---Gets the URL of websocket connection.
---@return string
function WebSocket:getUrl() end

---@return any
function WebSocket:init() end

---Constructor of WebSocket.
---
---\js ctor
---@return cc.WebSocket
function WebSocket.new() end

---Sends string data to websocket server.
---
---@param message string # string data.
---\lua sendstring
---
---Sends binary data to websocket server.
---
---\param binaryMsg binary string data.
---\param len the size of binary string data.
---\lua sendstring
---@overload fun(self: cc.WebSocket, binaryMsg: string, len: integer)
function WebSocket:send(message) end

return WebSocket