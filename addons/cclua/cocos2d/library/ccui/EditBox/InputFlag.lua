---AUTO GENERATED, DO NOT MODIFY!
---@meta ccui.EditBox.InputFlag

---@type ccui.EditBox.InputFlag
local VALUE

---
---@enum ccui.EditBox.InputFlag
local InputFlag = {
    ---Capitalize all characters automatically.
    INITIAL_CAPS_ALL_CHARACTERS = 4,
    ---This flag is a hint to the implementation that during text editing,
    ---the initial letter of each sentence should be capitalized.
    INITIAL_CAPS_SENTENCE = 3,
    ---This flag is a hint to the implementation that during text editing,
    ---the initial letter of each word should be capitalized.
    INITIAL_CAPS_WORD = 2,
    ---Lowercase all characters automatically.
    LOWERCASE_ALL_CHARACTERS = 5,
    ---Indicates that the text entered is confidential data that should be
    ---obscured whenever possible. This implies EDIT_BOX_INPUT_FLAG_SENSITIVE.
    PASSWORD = 0,
    ---Indicates that the text entered is sensitive data that the
    ---implementation must never store into a dictionary or table for use
    ---in predictive, auto-completing, or other accelerated input schemes.
    ---A credit card number is an example of sensitive data.
    SENSITIVE = 1,
}

return InputFlag