---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.RenderCommand.Type

---@type cc.RenderCommand.Type
local VALUE

---
---@enum cc.RenderCommand.Type
local Type = {
    ---Callback command, used for calling callback for rendering.
    CALLBACK_COMMAND = 6,
    CAPTURE_SCREEN_COMMAND = 7,
    ---Custom command, used to draw things other then TRIANGLES_COMMAND.
    CUSTOM_COMMAND = 2,
    ---Group command, which can group command in a tree hierarchy.
    GROUP_COMMAND = 3,
    ---Mesh command, used to draw 3D meshes.
    MESH_COMMAND = 4,
    ---Quad command, used for draw quad.
    QUAD_COMMAND = 1,
    ---Triangles command, used to draw triangles.
    TRIANGLES_COMMAND = 5,
    ---Reserved type.
    UNKNOWN_COMMAND = 0,
}

return Type