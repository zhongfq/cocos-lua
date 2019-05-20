--
-- $id: TouchStyle.lua O $
--

local util  = require "xgame.util"
local A     = require "xgame.display.action"

local TouchStyle = {}

function TouchStyle.newscale(down_scale, up_scale)
    local style = {}

    function style:touch_down()
        style.target:set_scale(down_scale, down_scale)
    end

    function style:touch_up()
        style.target:set_scale(up_scale, up_scale)
    end

    function style:hook(...)
        return util.hook(style, ...)
    end

    return style
end

function TouchStyle.newelastic(down_scale, up_scale)
    local style = {}
    local TAG = 0xFFFFF

    function style:touch_down()
        style.target:stop_action_by_tag(TAG)
        style.target:run_action(A.ease_elastic_out(
            A.scale_to(0.5, down_scale, down_scale)))
    end

    function style:touch_up()
        style.target:stop_action_by_tag(TAG)
        style.target:run_action(A.ease_elastic_out(
            A.scale_to(0.5, up_scale, up_scale)))
    end

    function style:hook(...)
        return util.hook(style, ...)
    end

    return style
end

function TouchStyle.newstate(down_skin, up_skin)
    assert(down_skin and up_skin)
    local style = {}

    function style:touch_down()
        style.target:load_texture(down_skin)
    end

    function style:touch_up()
        style.target:load_texture(up_skin)
    end

    function style:hook(...)
        return util.hook(style, ...)
    end

    return style
end

return TouchStyle
