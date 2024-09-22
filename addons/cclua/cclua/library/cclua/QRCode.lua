---AUTO GENERATED, DO NOT MODIFY!
---@meta cclua.QRCode

---
---@class cclua.QRCode : cc.Sprite
local QRCode = {}

---@param code string
---@param version integer
---@param level cclua.QRCode.ECLevel
---@param hint cclua.QRCode.EncodeMode
---@param casesensitive boolean
---@return cclua.QRCode
---@overload fun(code: string): cclua.QRCode
---@overload fun(code: string, version: integer): cclua.QRCode
---@overload fun(code: string, version: integer, level: cclua.QRCode.ECLevel): cclua.QRCode
---@overload fun(code: string, version: integer, level: cclua.QRCode.ECLevel, hint: cclua.QRCode.EncodeMode): cclua.QRCode
function QRCode.create(code, version, level, hint, casesensitive) end

return QRCode