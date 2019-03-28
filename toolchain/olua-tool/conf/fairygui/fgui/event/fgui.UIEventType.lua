local cls = class()
cls.CPPCLS = 'fairygui::UIEventType'
cls.LUACLS = 'fgui.UIEventType'
cls.enums [[
    Enter
    Exit
    Changed
    Submit
    TouchBegin 
    TouchMove 
    TouchEnd 
    Click 
    RollOver 
    RollOut 
    MouseWheel 
    RightClick 
    MiddleClick 
    PositionChange 
    SizeChange 
    KeyDown 
    KeyUp 
    Scroll 
    ScrollEnd 
    PullDownRelease 
    PullUpRelease 
    ClickItem 
    ClickLink
    ClickMenu
    RightClickItem
    DragStart
    DragMove
    DragEnd
    Drop
    GearStop
]]

return cls