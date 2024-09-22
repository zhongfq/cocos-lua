---AUTO GENERATED, DO NOT MODIFY!
---@meta cclua.QRCode.EncodeMode

---@type cclua.QRCode.EncodeMode
local VALUE

---
---@enum cclua.QRCode.EncodeMode
local EncodeMode = {
    ---< 8-bit data mode
    QR_MODE_8 = 2,
    ---< Alphabet-numeric mode
    QR_MODE_AN = 1,
    ---< Kanji (shift-jis) mode
    QR_MODE_KANJI = 3,
    ---< Terminator (NUL character). Internal use only
    QR_MODE_NUL = -1,
    ---< Numeric mode
    QR_MODE_NUM = 0,
    ---< Internal use only
    QR_MODE_STRUCTURE = 4,
}

return EncodeMode