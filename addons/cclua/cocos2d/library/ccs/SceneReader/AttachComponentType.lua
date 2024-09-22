---AUTO GENERATED, DO NOT MODIFY!
---@meta ccs.SceneReader.AttachComponentType

---@type ccs.SceneReader.AttachComponentType
local VALUE

---
---@enum ccs.SceneReader.AttachComponentType
local AttachComponentType = {
    ---Default AttachComponentType is _EmptyNode
    DEFAULT = 0,
    ---parent: Empty Node
    ---ComRender(Sprite, Armature, TMXTiledMap, ParticleSystemQuad, GUIComponent)
    ---ComAttribute
    ---ComAudio
    ---....
    EMPTY_NODE = 0,
    ---parent:   ComRender(Sprite, Armature, TMXTiledMap, ParticleSystemQuad, GUIComponent)
    ---ComAttribute
    ---ComAudio
    ---.....
    RENDER_NODE = 1,
}

return AttachComponentType