---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.Console

---Console is helper class that lets the developer control the game from TCP connection.
---Console will spawn a new thread that will listen to a specified TCP port.
---Console has a basic token parser. Each token is associated with an std::function<void(int)>.
---If the std::function<> needs to use the cocos2d API, it needs to call
---
---```
---scheduler->performFunctionInCocosThread( ... );
---```
---@class cc.Console : cc.Ref
---@field commandSeparator integer The command separator
---@field ipv6Server boolean Checks whether the server for console is bound with ipv6 address
local Console = {}

---delete custom command
---@param cmdName string
function Console:delCommand(cmdName) end

---@param cmdName string
---@param subCmdName string
function Console:delSubCommand(cmdName, subCmdName) end

---The command separator
---@return integer
function Console:getCommandSeparator() end

---Checks whether the server for console is bound with ipv6 address
---@return boolean
function Console:isIpv6Server() end

---starts listening to specified file descriptor
---@param fd integer
---@return boolean
function Console:listenOnFileDescriptor(fd) end

---starts listening to specified TCP port
---@param port integer
---@return boolean
function Console:listenOnTCP(port) end

---log something in the console
---@param buf string
function Console:log(buf) end

---Constructor
---@return cc.Console
function Console.new() end

---set bind address
---
---\address : 127.0.0.1
---@param address string
function Console:setBindAddress(address) end

---The command separator
---@param var integer
function Console:setCommandSeparator(var) end

---stops the Console. 'stop' will be called at destruction time as well
function Console:stop() end

return Console