---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.WebSocket.Delegate

---The delegate class is used to process websocket events.
---
---The most member function are pure virtual functions,they should be implemented the in subclass.
---\lua NA
---@class cc.WebSocket.Delegate 
local Delegate = {}

---@return any
function Delegate:__gc() end

---When the WebSocket object connected wants to close or the protocol won't get used at all and current _readyState is State::CLOSING,this function is to be called.
---
---@param ws cc.WebSocket # The WebSocket object connected.
function Delegate:onClose(ws) end

---This function is to be called in the following cases:
---1. client connection is failed.
---2. the request client connection has been unable to complete a handshake with the remote server.
---3. the protocol won't get used at all after this callback and current _readyState is State::CONNECTING.
---4. when a socket descriptor needs to be removed from an external polling array. in is again the struct libwebsocket_pollargs containing the fd member to be removed. If you are using the internal polling loop, you can just ignore it and current _readyState is State::CONNECTING.
---
---@param ws cc.WebSocket # The WebSocket object connected.
---@param error cc.WebSocket.ErrorCode # WebSocket::ErrorCode enum,would be ErrorCode::TIME_OUT or ErrorCode::CONNECTION_FAILURE.
function Delegate:onError(ws, error) end

---This function to be called when data has appeared from the server for the client connection.
---
---@param ws cc.WebSocket # The WebSocket object connected.
---@param data any # Data object for message.
function Delegate:onMessage(ws, data) end

---This function to be called after the client connection complete a handshake with the remote server.
---This means that the WebSocket connection is ready to send and receive data.
---
---@param ws cc.WebSocket # The WebSocket object connected
function Delegate:onOpen(ws) end

return Delegate