return {
    CHANGE              = "change",
    CANCEL              = "cancel",
    SELECT              = "select",
    CREATE              = "create",
    STOP                = "stop",
    COMPLETE            = "complete",
    PROGRESS            = "progress",
    IOERROR             = "ioerror",
    CLOSE               = "close",
    UPDATE              = "update",

    -- view event
    CREATION_COMPLETE   = "creationComplete",
    ADDED               = "added",
    REMOVED             = "removed",
    FOCUS_IN            = "focusIn",
    FOCUS_OUT           = "focusOut",

    -- runtime event
    OPEN_URL            = "openURL",
    MEMORY_WARNING      = "memoryWarning",
    NETWORK_CHANGE      = "networkChange",
    RUNTIME_GC          = "runtimeGC",
    RUNTIME_PAUSE       = "runtimePause",
    RUNTIME_RESUME      = "runtimeResume",
    RUNTIME_UPDATE      = "runtimeUpdate",
    RUNTIME_RESIZE      = "runtimeResize",
    RUNTIME_TRACEBACK   = "runtimeTraceback",

    -- download on-demand assets
    LOADER_START        = "loaderStart",
    LOADER_ERROR        = "loaderError",
    LOADER_UPDATE       = "loaderUpdate",
    LOADER_COMPLETE     = "loaderComplete",
}
