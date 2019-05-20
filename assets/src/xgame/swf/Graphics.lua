--
-- $id: Graphics.lua O $
--

local class         = require "xgame.class"
local Point         = require "xgame.Point"
local DisplayObject = require "xgame.swf.DisplayObject"

local Graphics = class("Graphics", DisplayObject)

local _new = Graphics.new

function Graphics.new(cobj)
    return _new(cobj or swf.graphics.new())
end

function Graphics:ctor(cobj)
    self._current_fill = false
end

function Graphics:clear()
    self.cobj:clear()
end

function Graphics:begin_fill(fill_data, mat, repeat_mode)
    if type(fill_data) == "number" then
        self.cobj:begin_fill(fill_data)
    else
        self.cobj:begin_fill(fill_data.cobj)
    end
    self._current_fill = fill_data
end

function Graphics:end_fill()
    self._current_fill = false
    self.cobj:end_fill()
end

function Graphics:draw_rect(x, y, width, height)
    self.cobj:draw_triangles({
        x, y,
        x, y + height,
        x + width, y,
        x + width, y + height
    }, {
        0, 1, 2, 2, 1, 3
    }, {
    })
end

local function transfrom_and_add(mat, points, x, y)
    local px, py = mat:transform_point(x, y)
    points[#points + 1] = px
    points[#points + 1] = py
end

local function add_left_join(mat, num_segments, radius, points, offset)
    local dis = radius / num_segments
    local y = 0
    local x = radius
    for i = 1, num_segments do
        if i == 1 then
            y = dis / 2
        else
            x = x - dis
            y = math.sqrt(radius * radius - x * x)
        end
        
        transfrom_and_add(mat, points, -x + offset, -y)
        transfrom_and_add(mat, points, -x + offset, y)
    end
end

local function add_right_join(mat, num_segments, radius, points, offset)
    local dis = radius / num_segments
    local y = 0
    local x = 0
    for i = 1, num_segments do
        if i == num_segments then
            y = dis / 2
            x = x + dis
        else
            x = x + dis
            y = math.sqrt(radius * radius - x * x)
        end

        transfrom_and_add(mat, points, x + offset, -y)
        transfrom_and_add(mat, points, x + offset, y)
    end
end

local function convert_line_to_mesh(coords, line_width)
    local half = line_width / 2
    local num_segments = 3
    local num_points = #coords / 2
    local num_mesh_points = (num_points - 1) * 4 + 2 * (2 * num_segments)
    local mat = swf.matrix.new()
    local count = 0
    local vertices = {}
    for i = 1, num_points - 1 do
        local x1 = coords[(i - 1) * 2 + 1]
        local y1 = coords[(i - 1) * 2 + 2]
        local x2 = coords[i * 2 + 1]
        local y2 = coords[i * 2 + 2]

        mat:identity()
        mat:translate(x1, y1)
        mat:rotate(math.deg(math.atan(y2 - y1, x2 - x1)))

        local len = Point.new(x2 - x1, y2 - y1).length
        if i == 1 then
            add_left_join(mat, num_segments, half, vertices, 0)
        end

        transfrom_and_add(mat, vertices, 0, -half)
        transfrom_and_add(mat, vertices, 0, half)
        transfrom_and_add(mat, vertices, len, -half)
        transfrom_and_add(mat, vertices, len, half)

        if i == num_points - 1 then
            add_right_join(mat, num_segments, half, vertices, len)
        end
    end

    assert(num_mesh_points == #vertices / 2)

    local indices = {}
    local index = 0
    for i = 0, num_mesh_points - 3 do
        if i % 2 == 0 then
            indices[#indices + 1] = index
            indices[#indices + 1] = index + 1
            indices[#indices + 1] = index + 2
        else
            indices[#indices + 1] = index
            indices[#indices + 1] = index + 2
            indices[#indices + 1] = index + 1
        end
        index = index + 1
    end

    return vertices, indices
end

function Graphics:draw_line(coords, line_width)
    local vertices, indices = convert_line_to_mesh(coords, line_width)
    self.cobj:draw_triangles(vertices, indices, {})
end

function Graphics:draw_triangles(vertices, indices, uvs)
    self.cobj:draw_triangles(vertices, indices, uvs)
end

return Graphics
