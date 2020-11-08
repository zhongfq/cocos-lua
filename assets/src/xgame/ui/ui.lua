local class         = require "xgame.class"
local util          = require "xgame.util"
local loader        = require "xgame.loader"
local Event         = require "xgame.event.Event"
local TouchEvent    = require "xgame.event.TouchEvent"
local dataloader    = require "xgame.ui.dataloader"

local trace = util.trace("[ui]")

local ipairs = ipairs
local pairs = pairs
local assert = assert

local ui = {}

local viewCreators = {}
local viewClasses = {}
local newStatck = {}
local lazyInitCreator
local lastNew

local todoBindings = setmetatable({}, {__mode = "k"})
local events = setmetatable({}, {__mode = "k"})
local bindableEvents = {
    [Event.CHANGE] = true,
    [Event.SELECT] = true,
    [TouchEvent.CLICK] = true,
    [TouchEvent.TOUCH_UP] = true,
    [TouchEvent.TOUCH_DOWN] = true,
    [TouchEvent.TOUCH_MOVE] = true,
}

local viewSymbols = setmetatable({}, {__mode = "k"})
local layouts = setmetatable({}, {__index = function (layouts, symbol)
    local data = require(string.format("data.layouts.layout_%s", symbol))
    data.symbol = symbol
    rawset(layouts, symbol, data)
    return data
end})

--
-- event binder
--
local function buildEvents(data)
    if not events[data] then
        events[data] = {}
        for e in pairs(bindableEvents) do
            events[data][e] = data[e]
        end
        if data.children then
            for _, subdata in ipairs(data.children) do
                buildEvents(subdata)
            end
        end
    end
end

local function collectEvents(root, child, data)
    buildEvents(data)

    if next(events[data]) then
        local entry = todoBindings[root]
        if not entry then
            entry = {mapping = setmetatable({}, {__mode = "k"})}
            todoBindings[root] = entry
        end
        entry.mapping[child] = events[data]

        if entry.mediator then
            ui.bindEvents(root, entry.mediator)
        end
    end
end

function ui.bindEvents(view, mediator)
    if not todoBindings[view] then
        return
    end

    local entry = todoBindings[view]

    for child, events in pairs(entry.mapping) do
        for event, fn in pairs(events) do
            local listener = mediator[fn]
            if listener then
                child:addListener(event, listener, mediator)
            else
                trace("no handle for '%s'", fn)
            end
        end
        entry.mapping[child] = nil
    end

    entry.mediator = mediator
end

--
-- layout data
--
function ui.addData(symbol, data)
    data.symbol = symbol
    layouts[symbol] = data
    buildEvents(data)
end

function ui.getData(symbol)
    local data = layouts[symbol]
    if not data then
        error(string.format("layout not found: %s", symbol))
    end
    return data
end

--
-- ui new
--
local function createChild(data, parent, classname)
    classname = classname or data.classname
    local creator = viewCreators[classname]
    if not creator then
        error(string.format("no creator for '%s'", classname))
    end
    return creator(data, parent)
end

local function createChildren(data, parent, namespace, root)
    for _, subdata in ipairs(data.children) do
        local child = createChild(subdata, parent)
        local name = subdata.name

        if name then
            if namespace[name] ~= nil then
                error(string.format("variable name conflict: layout=%s name=%s",
                    tostring(newStatck[#newStatck]), name))
            else
                namespace[name] = child
            end
        end

        if subdata.children then
            local subnamespace = subdata.standalone and child or namespace
            local subroot = subdata.classname == "UIFile" and child or root
            if subdata.lazyInit then
                local cls = getmetatable(child)
                local proxy = {}
                setmetatable(child, proxy)
                proxy.__index = cls.__index
                function proxy.__newindex(self, key, value)
                    if key == "visible" and value then
                        setmetatable(child, cls)
                        createChildren(subdata, child, subnamespace, subroot)
                    end
                    return cls.__newindex(self, key, value)
                end
            else
                createChildren(subdata, child, subnamespace, subroot)
            end
        end

        collectEvents(root, child, subdata)
        parent:addChild(child)
    end
end

function ui.inflate(data, parent, fillParent)
    assert(data, "no data")

    if lazyInitCreator then
        lazyInitCreator()
        lazyInitCreator = false
    end

    if not parent then
        parent = createChild(data)
        collectEvents(parent, parent, data)
    elseif fillParent then
        dataloader.fill(parent, data)
        collectEvents(parent, parent, data)
    end

    if data.children then
        createChildren(data, parent, parent, parent)
    end

    return parent
end

function ui.new(symbol, parent, fillParent)
    local data = assert(layouts[symbol], symbol)

    if symbol ~= lastNew then
        trace("new layout: %s", symbol)
    end

    lastNew = symbol
    newStatck[#newStatck + 1] = symbol

    local assets = {}
    for path in pairs(data.assets) do
        assets[path] = loader.load(path)
    end
    local view = ui.inflate(data, parent, fillParent)
    viewSymbols[view] = symbol
    view.assetObjects = assets

    newStatck[#newStatck] = nil

    return view
end

function ui.symbol(view)
    return viewSymbols[view]
end

--
-- creator
--
local function bindCreator(classname, creator)
    if viewCreators[classname] then
        error(string.format("creator conflict: %s", classname))
    end
    assert(type(creator) == "function")
    viewCreators[classname] = creator
end

local function newCreator(class)
    assert(class.new)
    return function (data, parent)
        local view = class.new()
        dataloader.fill(view, data)
        if data.lazyInit then
            view.visible = false
        end
        return view
    end
end

function ui.class(classname, super)
    assert(super)
    assert(not viewClasses[classname], classname)

    local cls = class(classname, super)
    bindCreator(classname, newCreator(cls))
    viewClasses[classname] = cls

    return cls
end

--
-- base creator
--
local function bindBaseCreator(classname)
    local class = require(string.format("xgame.ui.%s", classname))
    bindCreator(classname, newCreator(class))
end

function lazyInitCreator()
    bindCreator("UIFile", function (data, parent)
        return ui.new(data.symbol, createChild(data, parent, data.custom_class))
    end)
    bindBaseCreator("UIButton")
    bindBaseCreator("UICheckBox")
    bindBaseCreator("UIGrid")
    bindBaseCreator("UIHLayer")
    bindBaseCreator("UIImage")
    bindBaseCreator("UILayer")
    bindBaseCreator("UIList")
    bindBaseCreator("UILoadingBar")
    bindBaseCreator("UIRadioButton")
    bindBaseCreator("UIRichText")
    bindBaseCreator("UIScroller")
    bindBaseCreator("UISlider")
    bindBaseCreator("UITextBMFont")
    bindBaseCreator("UITextField")
    bindBaseCreator("UITextInput")
    bindBaseCreator("UIVLayer")
end

function ui.bindCreator(classname, class_type)
    bindCreator(classname, newCreator(class_type))
end

return ui
