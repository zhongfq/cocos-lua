local M = {}

local cls = class(M)
cls.CPPCLS = "fairygui::RelationType"
cls.LUACLS = "fui.RelationType"
cls.enums [[
    Left_Left
    Left_Center
    Left_Right
    Center_Center
    Right_Left
    Right_Center
    Right_Right
    Top_Top
    Top_Middle
    Top_Bottom
    Middle_Middle
    Bottom_Top
    Bottom_Middle
    Bottom_Bottom
    Width
    Height
    LeftExt_Left
    LeftExt_Right
    RightExt_Left
    RightExt_Right
    TopExt_Top
    TopExt_Bottom
    BottomExt_Top
    BottomExt_Bottom
    Size
]]

local cls = class(M)
cls.CPPCLS = "fairygui::RelationItem"
cls.LUACLS = "fui.RelationItem"
cls.funcs [[
    @ref(singleref target) GObject* getTarget()
    void setTarget(@ref(singleref target) GObject* value)
    void add(RelationType relationType, bool usePercent)
    void internalAdd(RelationType relationType, bool usePercent)
    void remove(RelationType relationType)
    bool isEmpty()
    void applyOnSelfSizeChanged(float dWidth, float dHeight, bool applyPivot)
]]
cls.func('copyFrom', [[
{
    lua_settop(L, 2);
    
    fairygui::RelationItem *self = (fairygui::RelationItem *)olua_toobj(L, 1, "fui.RelationItem");
    fairygui::RelationItem *source = (fairygui::RelationItem *)olua_checkobj(L, 2, "fui.RelationItem");
    // void copyFrom(const RelationItem& source)
    self->copyFrom(*source);
    
    return 0;
}
]])
cls.props [[
    target
    empty
]]
return M