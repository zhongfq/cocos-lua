---AUTO GENERATED, DO NOT MODIFY!
---@meta ccui.EditBox.InputMode

---@type ccui.EditBox.InputMode
local VALUE

---
---@enum ccui.EditBox.InputMode
local InputMode = {
    ---The user is allowed to enter any text, including line breaks.
    ANY = 0,
    ---The user is allowed to enter a real number value.
    ---This extends kEditBoxInputModeNumeric by allowing a decimal point.
    DECIMAL = 5,
    ---The user is allowed to enter an e-mail address.
    EMAIL_ADDRESS = 1,
    ---The user is allowed to enter an integer value.
    NUMERIC = 2,
    ---The user is allowed to enter a phone number.
    PHONE_NUMBER = 3,
    ---The user is allowed to enter any text, except for line breaks.
    SINGLE_LINE = 6,
    ---The user is allowed to enter a URL.
    URL = 4,
}

return InputMode