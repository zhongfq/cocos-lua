local class     = require "xgame.class"
local util      = require "xgame.util"
local Event     = require "xgame.event.Event"
local shader    = require "xgame.shader"
local runtime   = require "xgame.runtime"
local cjson     = require "cjson.safe"

local assert = assert
local string = string
local trace = util.trace("[swf]")

local M = setmetatable({}, {__index = require("swf.core")})

M.ObjectType = require("swf.ObjectType")
M.loader = require("swf.loader")
M.Image = require("swf.Image")
M.Graphics = require("swf.Graphics")
M.BitmapData = require("swf.BitmapData")
M.SWFNode = require("swf.SWFNode")
M.SWFSnapshot = require("swf.SWFSnapshot")

runtime.on(Event.RUNTIME_GC, function ()
    local stat = M.stat()
    print(string.format("swf obj: holder=%d gc_object=%d texture=%d,%fM",
        stat.numHolders, stat.numObjects,
        stat.numTextures, stat.textureMem / (1024 ^ 2)))
end)

local T = M.ObjectType
local userClasses = {}
local movieInfoes = {}
local watchedRef = {}

local parseMetadata -- func

local fileToID = setmetatable({count = 0}, {__index = function (fileToID, path)
    local count = rawget(fileToID, "count") + 1
    rawset(fileToID, "count", count)
    rawset(fileToID, path, count)
    return count
end})

local function toGlobalID(cobj)
    local filePath = cobj.filePath
    if filePath then
        local fid = fileToID[filePath]
        return fid << 16 | (cobj.id + 1) -- character id is 16bit unsinged int
    else
        -- create by 'movieclip.createMovieclip'
        return 0
    end
end

local defaultClasses = {}

local function lazyRequire()
    require "xgame.swf.FLTextInput"
    require "xgame.swf.FLScroller"
    require "xgame.swf.FLSlider"
    require "xgame.swf.FLList"
    require "xgame.swf.FLLoader"
    require "xgame.swf.FLRadioButton"
    require "xgame.swf.FLRadioGroup"
    require "xgame.swf.FLTab"

    defaultClasses[T.SHAPE] = require('xgame.swf.FLShape')
    defaultClasses[T.IMAGE] = require('xgame.swf.FLImage')
    defaultClasses[T.TEXTFIELD] = require('xgame.swf.FLTextField')
    defaultClasses[T.GRAPHICS] = require('xgame.swf.FLGraphics')
    defaultClasses[T.MOVIE_CLIP] = require('xgame.swf.FLMovieClip')
end

local function construct(cls, cobj, ...)
    local obj = setmetatable({cobj = assert(cobj)}, cls)
    local function create(cls, ...)
        if cls.super then
            create(cls.super, ...)
        end
        if cls.ctor then
            cls.ctor(obj, ...)
        end
    end
    create(cls, ...)
    return obj
end

-- test only
function M.clearCache()
    movieInfoes = {}
end

function M.metadata(cobj)
    assert(cobj.type == T.MOVIE_CLIP)
    local id = toGlobalID(cobj)
    local info = movieInfoes[id]
    if not info then
        info = parseMetadata(cobj)
        movieInfoes[id] = info
    end
    return info
end

function M.class(classname, super)
    if not classname or not super then
        error(string.format("classname='%s', super='%s'", classname, super))
    elseif userClasses[classname] then
        error(string.format("classname conflict: %s", classname))
    end

    local cls = class(classname, super)
    userClasses[classname] = cls
    return cls
end

function M.new(filePath, autowatch, cls, ...) -- autowatch default true
    if lazyRequire then
        lazyRequire()
        lazyRequire = false
    end
    assert(string.match(filePath, "%.swf$"), filePath)
    local movie = M.loader.load(filePath)
    if movie then
        if type(movie.type) == 'table' then
            -- in 'build-builtin-manifest'
            return movie
        end
        local target = M.wrapper(cls, movie, ...)
        if autowatch ~= false then
            return M.watch(target)
        else
            return target
        end
    end
end

function M.watch(target)
    local filePath = target.cobj.filePath
    local ref = watchedRef[filePath]
    if not ref then
        ref = 0
        trace("watch swf file: %s", filePath)
    end
    watchedRef[filePath] = ref + 1
    target:addListener(Event.REMOVED, function ()
        target:removeListener(Event.REMOVED, util.callee())
        local ref = watchedRef[filePath]
        if ref then
            ref = ref - 1
            watchedRef[filePath] = ref
            if ref <= 0 then
                trace("auto unload watched swf file: %s", filePath)
                M.loader.unload(filePath)
            end
        end
    end)
    return target
end

function M.wrapper(cls, cobj, ...)
    if not cls then
        if cobj.type == T.MOVIE_CLIP then
            local classname = M.metadata(cobj).classname
            if classname then
                cls = assert(userClasses[classname], classname)
            end
        end
        if not cls then
            cls = defaultClasses[cobj.type]
        end
        if not cls then
            error(string.format("unknown type %s", cobj.type))
        end
    end
    return construct(cls, cobj, ...)
end

function M.checkLabels(target, ...)
    local frameLabels = target.frameLabels
    
    local function test(label)
        if not frameLabels[label] then
            error(string.format("label '%s' can't found in '%s'",
                label, target.name))
        end
    end

    for _, label in ipairs({...}) do
        -- ok1[1-3]
        local base, from, to = string.match(label, "([^[]+)%[(%d+)-(%d+)%]")
        if base then
            for i = from, to do
                test(string.format("%s%d", base, i))
            end
        else
            test(label)
        end
    end

    return target
end

function M.hasLabel(target, label)
    if target.frameLabels then
        return target.frameLabels[label] ~= nil
    end
end

function M.checkTarget(target, namepath, ...)
    target = M.checkName(target, namepath)
    if M.hasLabel(target, "none") then
        target:gotoAndStop("none")
    end
    M.checkLabels(target, ...)
    return target
end

function M.checkName(target, namefmt, ...)
    target = target:resolve(string.format(namefmt, ...))
    if target then
        return target
    else
        error(string.format("can't find target named '%s'", namefmt))
    end
end

--
-- auxiliary function
--
function parseMetadata(cobj)
    local def = {audios = {}}
    local frameLabels = cobj.frameLabels
    for label in pairs(frameLabels) do
        local kind, data = string.match(label, "^@(%w+)({.+})$")
        if kind then
            local mt, errormsg = cjson.decode(data)
            if mt then
                if kind == "metadata" then
                    for k, v in pairs(mt) do
                        assert(k ~= "audios")
                        def[k] = v
                    end
                elseif kind == "audio" then
                    def.audios[label] = mt
                end
            else
                trace("parse def error: %s(%s)", errormsg, label)
            end
        end
    end
    return def
end

function M.dumpLoadedSWF()
    local str = "loaded swf:\n"
    for path in pairs(M.loader.loaded) do
        str = str .. "    " .. path .. "\n"
    end
    trace(str)
end

shader.load("swfColorGray",
    [[
        attribute vec4 a_position;
        attribute vec4 a_color;
        attribute mat4 a_mat;

        #ifdef GL_ES
        varying lowp vec4 v_fragmentColor;
        #else
        varying vec4 v_fragmentColor;
        #endif

        void main()
        {
            gl_Position = a_mat * a_position;
            v_fragmentColor = a_color;
        }
    ]],
    [[
        #ifdef GL_ES
        precision lowp float;
        #endif

        varying vec4 v_fragmentColor;

        void main()
        {
            float alpha = v_fragmentColor.a;
            vec3 color = v_fragmentColor.rgb;
            float gray = dot(color, vec3(0.299,0.587,0.114));
            gl_FragColor = vec4(gray * alpha, gray * alpha,
                gray * alpha, alpha);
        }
    ]]
)

shader.load("swfTextGray",
    [[
        attribute vec4 a_position;
        attribute vec2 a_texCoord;
        attribute vec4 a_color;

        #ifdef GL_ES
        varying lowp vec4 v_fragmentColor;
        varying mediump vec2 v_texCoord;
        #else
        varying vec4 v_fragmentColor;
        varying vec2 v_texCoord;
        #endif

        void main()
        {
            gl_Position = CC_MVPMatrix * a_position;
            v_fragmentColor = a_color;
            v_texCoord = a_texCoord;
        }
    ]],
    [[
        #ifdef GL_ES
        precision lowp float;
        #endif

        varying vec4 v_fragmentColor;
        varying vec2 v_texCoord;

        void main()
        {
            vec4 color = vec4(v_fragmentColor.rgb, v_fragmentColor.a
                * texture2D(CC_Texture0, v_texCoord).a);
            float alpha = color.a * v_fragmentColor.a;
            float gray = dot(color.rgb, vec3(0.299,0.587,0.114));
            gl_FragColor = vec4(gray * alpha, gray * alpha,
                gray * alpha, alpha);
        }
    ]]
)

shader.load("swfBitmapGray",
    [[
        attribute vec4 a_position;
        attribute vec2 a_texCoord;
        attribute vec4 a_color;

        #ifdef GL_ES
        varying lowp vec4 v_fragmentColor;
        varying mediump vec2 v_texCoord;
        #else
        varying vec4 v_fragmentColor;
        varying vec2 v_texCoord;
        #endif

        void main()
        {
            gl_Position = CC_MVPMatrix * a_position;
            v_fragmentColor = a_color;
            v_texCoord = a_texCoord;
        }
    ]],
    [[
        #ifdef GL_ES
        precision lowp float;
        #endif

        varying vec4 v_fragmentColor;
        varying vec2 v_texCoord;

        void main()
        {
            float alpha = texture2D(CC_Texture0, v_texCoord).a * v_fragmentColor.a;
            float grey = dot(texture2D(CC_Texture0, v_texCoord).rgb, vec3(0.299,0.587,0.114));
            gl_FragColor = vec4(grey * alpha, grey * alpha, grey * alpha, alpha);
        }
    ]]
)

return M