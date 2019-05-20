--
-- $id: swf.lua O $
--

local class     = require "xgame.class"
local util      = require "xgame.util"
local Event     = require "xgame.Event"
local Image     = require "xgame.swf.Image"
local Shape     = require "xgame.swf.Shape"
local TextField = require "xgame.swf.TextField"
local MovieClip = require "xgame.swf.MovieClip"
local Graphics  = require "xgame.swf.Graphics"
local Shader    = require "xgame.Shader"
local cjson     = require "cjson.safe"
local window    = require "kernel.window"

local assert = assert
local string = string
local trace = util.trace("[swf]")

assert(swf)

local swfclasses = {}
local T = swf.type
local movieinfo = {}
local watched_ref = {}

local parse_metadata -- func

local file_ids = setmetatable({count = 0}, {__index = function (file_ids, path)
    local count = rawget(file_ids, "count") + 1
    rawset(file_ids, "count", count)
    rawset(file_ids, path, count)
    return count
end})

local function to_global_id(cobj)
    local filepath = cobj.filepath
    if filepath then
        local fid = file_ids[filepath]
        return fid << 16 | (cobj.id + 1) -- character id is 16bit unsinged int
    else
        -- create by 'movieclip.create_movieclip'
        return 0
    end 
end

-- test only
function swf.clear_cache()
    movieinfo = {}
end

function swf.design_size()
    return window.get_design_size()
end

function swf.visible_bounds()
    local left, right, top, bottom = window.get_visible_bounds()
    return left, right, bottom, top
end

function swf.metadata(cobj)
    assert(cobj.type == T.MOVIECLIP)
    local id = to_global_id(cobj)
    local info = movieinfo[id]
    if not info then
        info = parse_metadata(cobj)
        movieinfo[id] = info
    end
    return info
end

function swf.class(classname, super)
    if not classname or not super then
        error(string.format("classname='%s', super='%s'", classname, super))
    elseif swfclasses[classname] then
        error(string.format("classname conflict: %s", classname))
    end

    local cls = class(classname, super)
    swfclasses[classname] = cls
    return cls
end

function swf.new(filepath, autowatch, cls) -- autowatch default true
    assert(string.match(filepath, "%.swf$"), filepath)
    local movie = swf.loader.load(filepath)
    if movie then
        local target = cls and cls.new(movie) or swf.wrapper(movie)
        if autowatch ~= false then
            return swf.watch(target)
        else
            return target
        end
    end
end

function swf.watch(target)
    local filepath = target.cobj.filepath
    local ref = watched_ref[filepath]
    if not ref then
        ref = 0
        trace("watch swf file: %s", filepath)
    end
    watched_ref[filepath] = ref + 1
    target:add_event_listener(Event.REMOVED_FORM_STAGE, function ()
        target:remove_event_listener(Event.REMOVED_FORM_STAGE, util.callee())
        local ref = watched_ref[filepath]
        if ref then
            ref = ref - 1
            watched_ref[filepath] = ref
            if ref <= 0 then
                swf.loader.unload(filepath)
                trace("auto unload watched swf file: %s", filepath)
            end
        end
    end)
    return target
end

function swf.wrapper(cobj)
    assert(cobj)
    if cobj.type == T.SHAPE then
        return Shape.new(cobj)
    elseif cobj.type == T.IMAGE then
        return Image.new(cobj)
    elseif cobj.type == T.TEXTFIELD then
        return TextField.new(cobj)
    elseif cobj.type == T.GRAPHICS then
        return Graphics.new(cobj) 
    elseif cobj.type == T.MOVIECLIP then
        local def = swf.metadata(cobj)
        local classname = def.classname
        if classname then
            assert(swfclasses[classname], classname)
            return swfclasses[classname].new(cobj)
        else
            return MovieClip.new(cobj)
        end
    else
        error(string.format("unknown type %s", cobj.type))
    end
end

function swf.check_labels(target, ...)
    local frame_labels = target.frame_labels
    
    local function test(label)
        if not frame_labels[label] then
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

function swf.has_label(target, label)
    return target.frame_labels[label] ~= nil
end

function swf.check_target(target, namepath, ...)
    local target = swf.check_name(target, namepath)
    if swf.has_label(target, "none") then
        target:goto_and_stop("none")
    end
    swf.check_labels(target, ...)
    return target
end

function swf.lookup(target, namefmt, ...)
    local found = target

    local name_path = string.format(namefmt, ...)

    if found then
        for k in string.gmatch(name_path, "[^.]+") do
            if found then
                found = found.ns[k]
            end
        end

        if found then
            return found
        end
    end
end

function swf.check_name(target, namefmt, ...)
    local target = swf.lookup(target, namefmt, ...)
    if target then
        return target
    else
        error(string.format("can't find target named '%s'", namefmt))
    end
end

--
-- auxiliary function
--
function parse_metadata(cobj)
    local def = {audios = {}}
    local frame_labels = cobj.frame_labels
    for label, index in pairs(frame_labels) do
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

--
-- load & unload, ensure player->get_root() != null
--
local loader_load = swf.loader.load
local loader_unload = swf.loader.unload
local loadedswf = setmetatable({}, {__mode = "v"})

function swf.loader.load(path)
    local rootswf = loader_load(path)
    loadedswf[path] = rootswf
    return rootswf
end

function swf.loader.unload(path)
    watched_ref[path] = nil
    loadedswf[path] = nil
    loader_unload(path)

    local _, rootswf = next(loadedswf)
    if rootswf then
        swf.set_root(rootswf)
    end
end

function swf.dump_loaded_swf()
    local str = "loaded swf:\n"
    for path in pairs(loadedswf) do
        str = str .. "    " .. path .. "\n"
    end
    trace(str)
end

Shader.load("swf_color_gray",
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

Shader.load("swf_text_gray",
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

Shader.load("swf_bitmap_gray",
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

-- action api
-- swf.action.sequence
-- swf.action.repeat
-- swf.action.repeat_forever
-- swf.action.enter_frame
-- swf.action.interval
-- swf.action.spawn
-- swf.action.speed
-- swf.action.delay_time
-- swf.action.scale_to
-- swf.action.scale_by
-- swf.action.move_to
-- swf.action.move_by
-- swf.action.rotate_to
-- swf.action.rotate_by
-- swf.action.fade_to
-- swf.action.fade_in
-- swf.action.fade_out
-- swf.action.tween_value
-- swf.action.jump_by
-- swf.action.jump_to
-- swf.action.bezier_by
-- swf.action.bezier_to
-- swf.action.cardinal_spline_to
-- swf.action.cardinal_spline_by
-- swf.action.catmull_rom_to
-- swf.action.catmull_rom_by
-- swf.action.show
-- swf.action.hide
-- swf.action.toggle_visibility
-- swf.action.remove_self
-- swf.action.call_func
-- swf.action.ease_rate
-- swf.action.ease_in
-- swf.action.ease_out
-- swf.action.ease_inout
-- swf.action.ease_exponential_in
-- swf.action.ease_exponential_out
-- swf.action.ease_exponential_inout
-- swf.action.ease_sine_in
-- swf.action.ease_sine_out
-- swf.action.ease_sine_inout
-- swf.action.ease_elastic_in
-- swf.action.ease_elastic_out
-- swf.action.ease_elastic_inout
-- swf.action.ease_bounce_in
-- swf.action.ease_bounce_out
-- swf.action.ease_bounce_inout
-- swf.action.ease_back_in
-- swf.action.ease_back_out
-- swf.action.ease_back_inout
-- swf.action.ease_quadratic_in
-- swf.action.ease_quadratic_out
-- swf.action.ease_quadratic_inout
-- swf.action.ease_quartic_in
-- swf.action.ease_quartic_out
-- swf.action.ease_quartic_inout
-- swf.action.ease_quintic_in
-- swf.action.ease_quintic_out
-- swf.action.ease_quintic_inout

return swf
