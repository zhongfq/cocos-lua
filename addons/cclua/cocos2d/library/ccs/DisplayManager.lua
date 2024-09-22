---AUTO GENERATED, DO NOT MODIFY!
---@meta ccs.DisplayManager

---! DisplayManager manages Bone's display
---\js NA
---\lua NA
---@class ccs.DisplayManager : cc.Ref
---@field anchorPoint cc.Vec2 
---@field anchorPointInPoints cc.Vec2 
---@field boundingBox cc.Rect 
---@field contentSize cc.Size 
---@field currentDecorativeDisplay ccs.DecorativeDisplay 
---@field currentDisplayIndex integer 
---@field decorativeDisplayList any 
---@field displayRenderNode cc.Node 
---@field displayRenderNodeType ccs.DisplayType 
---@field forceChangeDisplay boolean 
---@field visible boolean Determines if the display is visible <br><br>\see setVisible(bool) \return true if the node is visible, false if the node is hidden.
local DisplayManager = {}

---Add display and use  _DisplayData init the display.
---If index already have a display, then replace it.
---If index is current display index, then also change display to _index
---
---@param displayData ccs.DisplayData # it include the display information, like DisplayType.
---If you want to create a sprite display, then create a SpriteDisplayData param
---
---@param index integer # the index of the display you want to replace or add to
----1 : append display from back
---@overload fun(self: ccs.DisplayManager, display: cc.Node, index: integer)
function DisplayManager:addDisplay(displayData, index) end

---Change display by index. You can just use this method to change display in the display list.
---The display list is just used for this bone, and it is the displays you may use in every frame.
---
---Note : if index is the same with prev index, the method will not effect
---
---@param index integer # The index of the display you want to change
---@param force boolean # If true, then force change display to specified display, or current display will set to  display index edit in the flash every key frame.
function DisplayManager:changeDisplayWithIndex(index, force) end

---@param name string
---@param force boolean
function DisplayManager:changeDisplayWithName(name, force) end

---Check if the position is inside the bone.
---@param _point cc.Vec2
---@return boolean
---@overload fun(self: ccs.DisplayManager, x: number, y: number): boolean
function DisplayManager:containPoint(_point) end

---@param bone ccs.Bone
---@return ccs.DisplayManager
function DisplayManager.create(bone) end

---@return cc.Vec2
function DisplayManager:getAnchorPoint() end

---@return cc.Vec2
function DisplayManager:getAnchorPointInPoints() end

---@return cc.Rect
function DisplayManager:getBoundingBox() end

---@return cc.Size
function DisplayManager:getContentSize() end

---@return ccs.DecorativeDisplay
function DisplayManager:getCurrentDecorativeDisplay() end

---@return integer
function DisplayManager:getCurrentDisplayIndex() end

---@param index integer
---@return ccs.DecorativeDisplay
function DisplayManager:getDecorativeDisplayByIndex(index) end

---@return any
function DisplayManager:getDecorativeDisplayList() end

---@return cc.Node
function DisplayManager:getDisplayRenderNode() end

---@return ccs.DisplayType
function DisplayManager:getDisplayRenderNodeType() end

---@param bone ccs.Bone
---@return boolean
function DisplayManager:init(bone) end

---Use BoneData to init the display list.
---If display is a sprite, and it have texture info in the TextureData, then use TextureData to init the display's anchor point
---If the display is a Armature, then create a new Armature
---@param boneData ccs.BoneData
function DisplayManager:initDisplayList(boneData) end

---@return boolean
function DisplayManager:isForceChangeDisplay() end

---Determines if the display is visible
---
---\see setVisible(bool)
---@return boolean # true if the node is visible, false if the node is hidden.
function DisplayManager:isVisible() end

---@return ccs.DisplayManager
function DisplayManager.new() end

---@param index integer
function DisplayManager:removeDisplay(index) end

---@param decoDisplay ccs.DecorativeDisplay
function DisplayManager:setCurrentDecorativeDisplay(decoDisplay) end

---@param force boolean
function DisplayManager:setForceChangeDisplay(force) end

---Sets whether the display is visible
---The default value is true, a node is default to visible
---
---@param visible boolean # true if the node is visible, false if the node is hidden.
function DisplayManager:setVisible(visible) end

return DisplayManager