local M = {}

M.DUMMY_STR = '<dummy str>'
M.FUNC = function () return M.PROXY end
M.FUNC_STR = function () return "<proxy table>" end
M.FUNC_NUM = function () return 1, 1, 1, 1 end

M.PROXY = setmetatable({}, {
    __index = M.FUNC,
    __tostring = M.FUNC_STR,
    __call = M.FUNC,
})

package.preload['cc.AudioEngine'] = M.FUNC
package.preload['cc.Director'] = M.FUNC
package.preload['cc.Node'] = M.FUNC
package.preload['cc.Sprite'] = M.FUNC
package.preload['cc.Scene'] = M.FUNC
package.preload['cc.Scheduler'] = M.FUNC
package.preload['cc.SpriteFrameCache'] = M.FUNC
package.preload['cc.TextureCache'] = M.FUNC
package.preload['ccui.Layout'] = M.FUNC
package.preload['ccui.MaskLayout'] = M.FUNC

package.preload['db.Factory'] = M.FUNC

package.preload['kernel.runtime'] = function ()
    return setmetatable({
        on = false,
        off = false,
    }, {__index = M.FUNC})
end
package.preload['kernel.timer'] = function ()
    return setmetatable({
        new = false,
    }, {__index = M.FUNC})
end
package.preload['kernel.filesystem'] = function ()
    return setmetatable({
        dir = false,
        localCachePath = false,
        sdCardDirectory = M.DUMMY_STR,
        documentDirectory = M.DUMMY_STR,
        cacheDirectory = M.DUMMY_STR,
        tmpDirectory = M.DUMMY_STR,
        writablePath = M.DUMMY_STR,
    }, {__index = M.FUNC})
end
package.preload['kernel.downloader'] = M.FUNC

return M