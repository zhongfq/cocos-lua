---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.AttachNode

---attach a node to a bone
---usage: auto sprite = Sprite3D::create("girl.c3b");
---auto weapon = Sprite3D::create("weapon.c3b");
---auto attachNode = sprite->getAttachNode("left hand");
---attachNode->addChild(weapon);
---@class cc.AttachNode : cc.Node
local AttachNode = {}

---creates an AttachNode
---@param attachBone cc.Bone3D # The bone to which the AttachNode is going to attach, the attacheBone must be a bone of the AttachNode's parent
---@return cc.AttachNode
function AttachNode.create(attachBone) end

---@return cc.AttachNode
function AttachNode.new() end

return AttachNode