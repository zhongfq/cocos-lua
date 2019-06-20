local class         = require "xgame.class"
local Point         = require "xgame.Point"
local DisplayObject = require "xgame.swf.DisplayObject"
local swf           = require "xgame.swf.swf"

local Graphics = class("Graphics", DisplayObject)

local _new = Graphics.new

function Graphics.new(cobj)
    return _new(cobj or swf.Graphics.new())
end

function Graphics:ctor(cobj)
    self._currentFill = false
end

function Graphics:clear()
    self.cobj:clear()
end

function Graphics:beginFill(fillData, mat, repeatMode)
    if type(fillData) == "number" then
        self.cobj:beginFill(fillData)
    else
        self.cobj:beginFill(fillData.cobj)
    end
    self._currentFill = fillData
end

function Graphics:endFill()
    self._currentFill = false
    self.cobj:endFill()
end

function Graphics:drawRect(x, y, width, height)
    self.cobj:drawTriangles({
        x, y,
        x, y + height,
        x + width, y,
        x + width, y + height
    }, {
        0, 1, 2, 2, 1, 3
    }, {
    })
end

local function transfromAndAdd(mat, points, x, y)
    local px, py = mat:transformPoint(x, y)
    points[#points + 1] = px
    points[#points + 1] = py
end

local function addLeftJoin(mat, numSegments, radius, points, offset)
    local dis = radius / numSegments
    local y = 0
    local x = radius
    for i = 1, numSegments do
        if i == 1 then
            y = dis / 2
        else
            x = x - dis
            y = math.sqrt(radius * radius - x * x)
        end
        
        transfromAndAdd(mat, points, -x + offset, -y)
        transfromAndAdd(mat, points, -x + offset, y)
    end
end

local function addRightJoin(mat, numSegments, radius, points, offset)
    local dis = radius / numSegments
    local y = 0
    local x = 0
    for i = 1, numSegments do
        if i == numSegments then
            y = dis / 2
            x = x + dis
        else
            x = x + dis
            y = math.sqrt(radius * radius - x * x)
        end

        transfromAndAdd(mat, points, x + offset, -y)
        transfromAndAdd(mat, points, x + offset, y)
    end
end

local function convertLineToMesh(coords, lineWidth)
    local half = lineWidth / 2
    local numSegments = 3
    local num_points = #coords / 2
    local numMeshPoints = (num_points - 1) * 4 + 2 * (2 * numSegments)
    local mat = swf.matrix.new()
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
            addLeftJoin(mat, numSegments, half, vertices, 0)
        end

        transfromAndAdd(mat, vertices, 0, -half)
        transfromAndAdd(mat, vertices, 0, half)
        transfromAndAdd(mat, vertices, len, -half)
        transfromAndAdd(mat, vertices, len, half)

        if i == num_points - 1 then
            addRightJoin(mat, numSegments, half, vertices, len)
        end
    end

    assert(numMeshPoints == #vertices / 2)

    local indices = {}
    local index = 0
    for i = 0, numMeshPoints - 3 do
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

function Graphics:drawLine(coords, lineWidth)
    local vertices, indices = convertLineToMesh(coords, lineWidth)
    self.cobj:drawTriangles(vertices, indices, {})
end

function Graphics:drawTriangles(vertices, indices, uvs)
    self.cobj:drawTriangles(vertices, indices, uvs)
end

return Graphics
