local class = require "xgame.class"
local util  = require "xgame.util"
local Event = require "xgame.Event"
local ui    = require "xgame.ui.ui"

local assert = assert
local trace = util.trace("[MediatorMap]")
local DLOG = trace

local MediatorMap = class("MediatorMap")

function MediatorMap:ctor(stage)
    self._instances = {}
    stage:addListener(Event.ADDED, self._addedHandler, self)
    stage:addListener(Event.REMOVED, self._removeHandler, self)
end

function MediatorMap:_addedHandler(_, view)
    local mcls = view.mediatorClass

    if not mcls then
        return
    end

    assert(mcls.onCreate, view.classname)
    assert(mcls.onDestroy, view.classname)

    local function create()
        local m = mcls == view.class and view or mcls.new(view)
        self._instances[view] = m
        DLOG("create '%s' for '%s'", m.classname, view.classname)
        ui.bindEvents(view, m)
        m:onCreate()
    end

    if view.initialized then
        create()
    else
        view:addListener(Event.CREATION_COMPLETE, function ()
            view:removeListener(Event.CREATION_COMPLETE, util.callee())
            create()
        end, nil, math.maxinteger)
    end
end

function MediatorMap:_removeHandler(_, view)
    local m = self._instances[view]
    if not m then
        return
    end

    self._instances[view] = nil
    DLOG("destroy '%s' for '%s'", m.classname, view.classname)
    m:onDestroy()
    assert(m.onDestroy == true, m.classname)
end

return MediatorMap
