--
-- $id: ui.lua O $
--

local class         = require "xgame.class"
local util          = require "xgame.util"
local Event         = require "xgame.Event"
local assetcache    = require "xgame.assetcache"
local TouchEvent    = require "xgame.display.TouchEvent"
local DataLoader    = require "xgame.display.support.DataLoader"

local trace = util.trace("[ui]")

local ipairs = ipairs
local pairs = pairs
local assert = assert

assert(not ui)
ui = {}

local view_creators = {}
local view_classes = {}
local new_statck = {}
local last_new

local todo_bindings = setmetatable({}, {__mode = "k"})
local events = setmetatable({}, {__mode = "k"})
local bindable_events = {
    [Event.CHANGE] = true,
    [Event.SELECT] = true,
    [TouchEvent.CLICK] = true,
    [TouchEvent.TOUCH_UP] = true,
    [TouchEvent.TOUCH_DOWN] = true,
    [TouchEvent.TOUCH_MOVE] = true,
}

local view_symbols = setmetatable({}, {__mode = "k"})
local layouts = setmetatable({}, {__index = function (layouts, symbol)
    local data = require(string.format("data.layouts.layout_%s", symbol))
    data.symbol = symbol
    rawset(layouts, symbol, data)
    return data
end})

--
-- event binder
--
local function build_events(data)
    if not events[data] then
        events[data] = {}
        for e in pairs(bindable_events) do
            events[data][e] = data[e]
        end
        if data.children then
            for _, subdata in ipairs(data.children) do
                build_events(subdata)
            end
        end
    end
end

local function collect_events(root, child, data)
    build_events(data)

    if next(events[data]) then
        local entry = todo_bindings[root]
        if not entry then
            entry = {mapping = setmetatable({}, {__mode = "k"})}
            todo_bindings[root] = entry
        end
        entry.mapping[child] = events[data]

        if entry.mediator then
            ui.bind_events(root, entry.mediator)
        end
    end
end

function ui.bind_events(view, mediator)
    if not todo_bindings[view] then
        return
    end

    local entry = todo_bindings[view]

    for child, events in pairs(entry.mapping) do
        for event, handle_name in pairs(events) do
            local listener = mediator[handle_name]
            if listener then
                child:add_event_listener(event, listener, mediator)
            else
                trace("no handle for '%s'", handle_name)
            end
        end
        entry.mapping[child] = nil
    end

    entry.mediator = mediator
end

--
-- layout data
--
function ui.add_data(symbol, data)
    data.symbol = symbol
    layouts[symbol] = data
    build_events(data)
end

function ui.get_data(symbol)
    local data = layouts[symbol]
    if not data then
        error(string.format("layout not found: %s", symbol))
    end
    return data
end

--
-- ui new
--
local function create_child(data, parent, classname)
    local classname = classname or data.classname
    local creator = view_creators[classname]
    if not creator then
        error(string.format("no creator for '%s'", classname))
    end
    return creator(data, parent)
end

local function create_children(data, parent, namespace, root)
    for _, subdata in ipairs(data.children) do
        local child = create_child(subdata, parent)
        local name = subdata.name

        if name then
            if namespace[name] ~= nil then
                error(string.format("variable name conflict: layout=%s name=%s", 
                    tostring(new_statck[#new_statck]), name))
            else
                namespace[name] = child
            end
        end

        if subdata.children then
            local namespace = subdata.standalone and child or namespace
            local root = subdata.classname == "UIFile" and child or root
            if subdata.lazy_init then
                local cls = getmetatable(child)
                local proxy = {}
                setmetatable(child, proxy)
                proxy.__index = cls.__index
                function proxy.__newindex(self, key, value)
                    if key == "visible" and value then
                        setmetatable(child, cls)
                        create_children(subdata, child, namespace, root)
                    end
                    return cls.__newindex(self, key, value)
                end
            else
                create_children(subdata, child, namespace, root)
            end
        end

        collect_events(root, child, subdata)
        parent:add_child(child)
    end
end

function ui.inflate(data, parent, fill_parent)
    assert(data, "no data")

    if not parent then
        parent = create_child(data)
        collect_events(parent, parent, data)
    elseif fill_parent then
        DataLoader:fill_target(parent, data)
        collect_events(parent, parent, data)
    end

    if data.children then
        create_children(data, parent, parent, parent)
    end

    return parent
end

function ui.new(symbol, parent, fill_parent)
    local data = assert(layouts[symbol], symbol)

    if symbol ~= last_new then
        trace("new layout: %s", symbol)
    end

    last_new = symbol
    new_statck[#new_statck + 1] = symbol

    assetcache.load(nil, data.assets)
    local view = ui.inflate(data, parent, fill_parent)
    view_symbols[view] = symbol
    assetcache.load(view, data.assets) -- bind assets to view

    view:add_event_listener(Event.CREATION_COMPLETE, function ()
        view:remove_event_listener(Event.CREATION_COMPLETE, util.callee())
        xGame:dispatch_event(Event.START_GUIDE, symbol)
    end, nil, math.maxinteger)

    new_statck[#new_statck] = nil

    return view
end

function ui.symbol(view)
    return view_symbols[view]
end

local function is_active(view)
    while view do
        if not view.stage or not view.cobj or not view.visible then
            return false
        end

        view = view.parent
    end
    return true
end

function ui.try_guide()
    for view, symbol in pairs(view_symbols) do
        if is_active(view) then
            xGame:dispatch_event(Event.START_GUIDE, symbol)
        end
    end
end

--
-- creator
--
local function bind_creator(classname, creator)
    if view_creators[classname] then
        error(string.format("creator conflict: %s", classname))
    end
    assert(type(creator) == "function")
    view_creators[classname] = creator
end

local function new_creator(class)
    assert(class.new)
    return function (data, parent)
        local view = class.new()
        DataLoader:fill_target(view, data)
        if data.lazy_init then
            view.visible = false
        end
        return view
    end
end

function ui.class(classname, super)
    assert(super)
    assert(not view_classes[classname], classname)

    local cls = class(classname, super)
    bind_creator(classname, new_creator(cls))
    view_classes[classname] = cls

    return cls
end

--
-- base creator
--
local function bind_base_creator(classname)
    local class = require(string.format("xgame.display.%s", classname))
    bind_creator(classname, new_creator(class))
end

bind_creator("UIFile", function (data, parent)
    return ui.new(data.symbol, create_child(data, parent, data.custom_class))
end)
bind_base_creator("UIButton")
bind_base_creator("UICheckBox")
bind_base_creator("UIGrid")
bind_base_creator("UIHLayer")
bind_base_creator("UIImage")
bind_base_creator("UILayer")
bind_base_creator("UIList")
bind_base_creator("UILoadingBar")
bind_base_creator("UIRadioButton")
bind_base_creator("UIRichText")
bind_base_creator("UIScroller")
bind_base_creator("UISlider")
bind_base_creator("UITextBMFont")
bind_base_creator("UITextField")
bind_base_creator("UITextInput")
bind_base_creator("UIVLayer")

function ui.bind_creator(classname, class_type)
    bind_creator(classname, new_creator(class_type))
end

return ui
