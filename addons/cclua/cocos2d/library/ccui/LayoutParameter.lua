---AUTO GENERATED, DO NOT MODIFY!
---@meta ccui.LayoutParameter

---Base class for various LayoutParameter.
---@class ccui.LayoutParameter : cc.Ref
---@field layoutType ccui.LayoutParameter.Type Gets LayoutParameterType of LayoutParameter. <br><br>\see LayoutParameterType. \return LayoutParameterType
---@field margin cc.ui.Margin Gets margin parameter of LayoutParameter. <br><br>\see Margin \return Margin of layout parameter.
local LayoutParameter = {}

---Create a copy of original LayoutParameter.
---@return ccui.LayoutParameter # A LayoutParameter pointer.
function LayoutParameter:clone() end

---Copy all the member field from argument LayoutParameter to self.
---@param model ccui.LayoutParameter # A LayoutParameter instance.
function LayoutParameter:copyProperties(model) end

---Create a empty LayoutParameter.
---@return ccui.LayoutParameter # A autorelease LayoutParameter instance.
function LayoutParameter.create() end

---Create a cloned instance of LayoutParameter.
---@return ccui.LayoutParameter # A LayoutParameter pointer.
function LayoutParameter:createCloneInstance() end

---Gets LayoutParameterType of LayoutParameter.
---
---\see LayoutParameterType.
---@return ccui.LayoutParameter.Type # LayoutParameterType
function LayoutParameter:getLayoutType() end

---Gets margin parameter of LayoutParameter.
---
---\see Margin
---@return cc.ui.Margin # Margin of layout parameter.
function LayoutParameter:getMargin() end

---Default constructor.
---
---\lua new
---@return ccui.LayoutParameter
function LayoutParameter.new() end

---Set margin parameter for LayoutParameter.
---
---\see Margin
---@param margin cc.ui.Margin # 
function LayoutParameter:setMargin(margin) end

return LayoutParameter