local cls = class()
cls.CPPCLS = "fairygui::Relations"
cls.LUACLS = "fui.Relations"
cls.funcs [[
    void add(GObject* target, RelationType relationType)
    void add(GObject* target, RelationType relationType, bool usePercent)
    void remove(GObject* target, RelationType relationType)
    bool contains(GObject* target)
    void clearFor(GObject* target)
    void clearAll()
    void onOwnerSizeChanged(float dWidth, float dHeight, bool applyPivot)
    bool isEmpty()
]]
cls.func('copyFrom', [[
{
    lua_settop(L, 2);
    
    fairygui::Relations *self = (fairygui::Relations *)olua_toobj(L, 1, "fui.Relations");
    fairygui::Relations *source = (fairygui::Relations *)olua_checkobj(L, 2, "fui.Relations");
    // void copyFrom(const Relations& source)
    self->copyFrom(*source);
    
    return 0;
}
]])
cls.props [[
    empty
]]

return cls