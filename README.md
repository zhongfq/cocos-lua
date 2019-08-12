# olua (object lua)
olua is a lua binding library based on lua gc memory management mechanism, it design for c/c++ lua binding code generation and providing lambda function binding support.

## how to use

```c++
class Base {
public:
    virtual void print(const std::string &msg);
}

class Derived : public Base {
public:
    virtual void doSomething();
    virtual void setOnEnter(const std::function<void (Derived *)> &callback);
    virtual const std::function<void (Derived *)> &getOnEnter();
}

// lua-binding
static int luaopen_Base(lua_State *L)
{
    oluacls_class(L, "Base", nullptr);
    oluacls_func(L, "print", _base_print);
    oluacls_func(L, "__gc", _base___gc);
    olua_registerluatype<Base>(L, "Base");
    oluacls_createclassproxy(L);
    return 1;
}

static int luaopen_Derived(lua_State *L)
{
    oluacls_class(L, "Derived", "Base");
  	oluacls_func(L, "new", _derived_new)
    oluacls_func(L, "doSomething", _derived_doSomething);
    oluacls_prop(L, "onEnter", _derived_getOnEnter, _derived_setOnEnter);
    olua_registerluatype<Derived>(L, "Derived");
    oluacls_createclassproxy(L);
    return 1;
}
```

use in lua

```lua
local Derived = require "Derived"
local obj = Derived.new()
obj.onEnter = function ()
  	print('hello world!')
end
obj:doSomething()
obj:print()
print(obj.onEnter)
```

## export tool

The export tool is based on clang, using lua scripts, it can auto export c/c++ method and lambda function. More detail and example see https://github.com/zhongfq/cocos-lua/tree/master/tools/lua-bindings.