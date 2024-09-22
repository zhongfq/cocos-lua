---AUTO GENERATED, DO NOT MODIFY!
---@meta ccui.RadioButtonGroup

---RadioButtonGroup groups designated radio buttons to make them interact to each other.
---In one RadioButtonGroup, only one or no RadioButton can be checked.
---@class ccui.RadioButtonGroup : ccui.Widget
---@field allowedNoSelection boolean Query whether no-selection is allowed or not. <br><br>\param true means no-selection is allowed, false means no-selection is not allowed.
---@field numberOfRadioButtons integer Get the number of radio buttons in this group. <br><br>\return the number of radio buttons in this group
---@field selectedButtonIndex integer Get the index of selected radio button. <br><br>\return the selected button's index. Returns -1 if no button is selected.
local RadioButtonGroup = {}

---Add a callback function which would be called when radio button is selected or unselected.
---@param callback ccui.RadioButtonGroup.ccRadioButtonGroupCallback # A std::function with type @see `ccRadioButtonGroupCallback`
function RadioButtonGroup:addEventListener(callback) end

---Add a radio button into this group.
---
---\param radio button instance
---@param radioButton ccui.RadioButton
function RadioButtonGroup:addRadioButton(radioButton) end

---Create and return a empty RadioButtonGroup instance pointer.
---@return ccui.RadioButtonGroup
function RadioButtonGroup.create() end

---Get the number of radio buttons in this group.
---
---@return integer # the number of radio buttons in this group
function RadioButtonGroup:getNumberOfRadioButtons() end

---Get a radio button in this group by index.
---
---@param index integer # of the radio button
---@return ccui.RadioButton # radio button instance. Returns nullptr if out of index.
function RadioButtonGroup:getRadioButtonByIndex(index) end

---Get the index of selected radio button.
---
---@return integer # the selected button's index. Returns -1 if no button is selected.
function RadioButtonGroup:getSelectedButtonIndex() end

---Query whether no-selection is allowed or not.
---
---\param true means no-selection is allowed, false means no-selection is not allowed.
---@return boolean
function RadioButtonGroup:isAllowedNoSelection() end

---Default constructor.
---
---\lua new
---@return ccui.RadioButtonGroup
function RadioButtonGroup.new() end

---Remove all radio button from this group.
function RadioButtonGroup:removeAllRadioButtons() end

---Remove a radio button from this group.
---
---\param radio button instance
---@param radioButton ccui.RadioButton
function RadioButtonGroup:removeRadioButton(radioButton) end

---Set a flag for allowing no-selection feature.
---If it is allowed, no radio button can be selected.
---If it is not allowed, one radio button must be selected all time except it is empty.
---Default is not allowed.
---
---\param true means allowing no-selection, false means disallowing no-selection.
---@param allowedNoSelection boolean
function RadioButtonGroup:setAllowedNoSelection(allowedNoSelection) end

---Select a radio button by index.
---
---@param index integer # of the radio button
---
---Select a radio button by instance.
---
---\param radio button instance
---@overload fun(self: ccui.RadioButtonGroup, radioButton: ccui.RadioButton)
function RadioButtonGroup:setSelectedButton(index) end

---Select a radio button by index without event dispatch.
---
---@param index integer # of the radio button
---
---Select a radio button by instance without event dispatch.
---
---\param radio button instance
---@overload fun(self: ccui.RadioButtonGroup, radioButton: ccui.RadioButton)
function RadioButtonGroup:setSelectedButtonWithoutEvent(index) end

return RadioButtonGroup