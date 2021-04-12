local class = require "xgame.class"

local MyNode = class('MyNode', require('cc.Node'))

function MyNode:ctor(...)
    print('MyNode ctor:', self, ...)
    print('NyNode addChild', self.addChild)
    self._value = 0
end

function MyNode:trace(...)
    print('My Node trace:', self, ...)
end

function MyNode.Get:value()
    return self._value
end

function MyNode.Set:value(v)
    self._value = v
end

local SubMyNode = class('SubMyNode', MyNode)
function SubMyNode:ctor(...)
    print('SubMyNode ctor:', self, ...)
    print('SubMyNode addChild', self.addChild)
end

local my = MyNode.new('a', 'b', 'c')
my:trace(1, 2, 3)
print('----- new sub node')

local submy = SubMyNode.new('a', 'b')
print('SubMyNode value:', submy.value)
submy.value = 100
print('SubMyNode value:', submy.value)