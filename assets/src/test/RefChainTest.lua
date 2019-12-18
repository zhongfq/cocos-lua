local _ENV = setmetatable({}, {__index = _ENV})

local runtime   = require "kernel.runtime"
local timer     = require "kernel.timer"
local Director  = require "cc.Director"
local Scene     = require "cc.Scene"
local Node      = require "cc.Node"
local MoveTo    = require "cc.MoveTo"
local Sprite    = require "cc.Sprite"

local director = Director.instance

function new()
    print(director.runningScene)
    print(director.scheduler)
    print(director.actionManager)
    print(director.eventDispatcher)
    print(director.textureCache)
    printUserValue(Director.instance)

    timer.delay(0.2, function ()
        local s1 = Scene.create()
        local s2 = Scene.create()
        local s3 = Scene.create()
        local s4 = Scene.create()
        local s5 = Scene.create()
        director:pushScene(s1)
        assert(hasScene(s1))
        director:pushScene(s2)
        director:pushScene(s3)
        assert(hasScene(s2))
        assert(hasScene(s3))
        director:replaceScene(s4)
        assert(not hasScene(s3))
        assert(hasScene(s4))
        director:pushScene(s5)
        assert(hasScene(s5))
        director:popScene()
        assert(not hasScene(s5))
        director:popToSceneStackLevel(3)
        assert(not hasScene(s2))
        assert(not hasScene(s4))
        director:popToRootScene()
        assert(not hasScene(s1))
        printUserValue(director)

        local rootscene = director.runningScene
        clearRefs(director, '.hold.scenes')
        assert(not hasScene(rootscene))
        print(director.runningScene)
        assert(hasScene(rootscene))

        local REF_CHILDREN = '.hold.children'
        local node1 = Node.create()
        node1.name = 'node1'
        local node2 = Node.create()
        node2.tag = 10
        local node3 = Node.create()
        local node4 = Node.create()
        rootscene:addChild(node1)
        rootscene:addChild(node2)
        rootscene:addChild(node3)
        rootscene:addChild(node4)
        printUserValue(rootscene)
        assert(hasRef(rootscene, REF_CHILDREN, node1))
        assert(hasRef(rootscene, REF_CHILDREN, node2))
        assert(hasRef(rootscene, REF_CHILDREN, node3))
        assert(hasRef(rootscene, REF_CHILDREN, node4))
        node3:removeFromParent()
        assert(not hasRef(rootscene, REF_CHILDREN, node3))
        rootscene:removeChild(node4)
        assert(not hasRef(rootscene, REF_CHILDREN, node4))
        clearRefs(rootscene, REF_CHILDREN)
        print(rootscene:getChildByName('node1'))
        assert(hasRef(rootscene, REF_CHILDREN, node1))
        print(rootscene:getChildByTag(10))
        assert(hasRef(rootscene, REF_CHILDREN, node2))
        printUserValue(rootscene)
        rootscene:removeChildByTag(10)
        assert(not hasRef(rootscene, REF_CHILDREN, node2))
        rootscene:removeChildByName('node1')
        assert(not hasRef(rootscene, REF_CHILDREN, node1))
    end)

    timer.delay(0.5, function ()
        collectgarbage('collect')
        local REF_ACTIONS = '.hold.actions'
        local image = Sprite.create('res/HelloWorld.png')
        image.x = 100
        image.y = 100
        director.runningScene:addChild(image)
        local moveto = MoveTo.create(1, 400, 500)
        image:runAction(moveto)
        printUserValue(image)
        assert(hasRef(image, REF_ACTIONS, moveto))
        timer.delay(2, function ()
            image:runAction(MoveTo.create(0.5, 300, 200))
            printUserValue(image)
            assert(not hasRef(image, REF_ACTIONS, moveto))
            timer.delay(0.2, function ()
                image:stopAllActions()
                printUserValue(image)
            end)
        end)
    end)

    return Scene.create()
end

function hasScene(scene)
    local uservalue = debug.getuservalue(director)
    local ref = uservalue['.hold.scenes']
    if ref then
        return ref[scene]
    end
end

function hasRef(obj, ref, value)
     local uservalue = debug.getuservalue(obj)
    local ref = uservalue[ref]
    if ref then
        return ref[value]
    end
end

function clearRefs(obj, ref)
    local uservalue = debug.getuservalue(obj)
    rawset(uservalue, ref, nil)
end
    
return _ENV