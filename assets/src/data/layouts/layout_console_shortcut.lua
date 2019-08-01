--
--$id: layout_console_shortcut.lua Editor Studio $
--

return {
    classname = "ConsoleShortcut",
    name = "控制台命令",
    width = 200,
    height = 80,
    touchable = true,
    touchChildren = false,
    children = {
        {
            classname = "UILayer",
            horizontalAlign = "center",
            verticalAlign = "center",
            width = 180,
            height = 60,
            color = 0xCCCCCC,
            colorType = 1,
            children = {
            },
        },
        {
            classname = "UITextField",
            name = "label",
            horizontalAlign = "center",
            verticalAlign = "center",
            width = 0,
            height = 0,
            text = "切换正式服",
            color = 0x000000,
            fontSize = 24,
        },
    },
    assets = {},
    files = {
    },
}
