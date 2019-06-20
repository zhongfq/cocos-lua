local class     = require "xgame.class"
local util      = require "xgame.util"
local MixSWF    = require "xgame.swf.MixSWF"
local swf       = require "xgame.swf.swf"

local SWFTest = class('SWFTest', MixSWF)

function SWFTest:ctor()
end

function SWFTest.Get:rootswfPath()
    return 'res/swf/test.swf'
end

function SWFTest:onCreate()
    MixSWF.onCreate(self)
    
    local rootswf = self.rootswf
    rootswf:gotoAndStop('iPhone')

    self:scanAudio(rootswf)
    self:play(rootswf.ns['audio'].ns['music'], 'start')
    self:play(rootswf.ns['page'], 'start', true)
        :onStart(function ()
            local function playItem(item)
                local t = item.parent.metadata.initTime[item.name]
                item:gotoAndStop('none')
                self:delay(t / item.rawFrameRate, function ()
                    self:play(item, 'into')
                        :onEnd(function ()
                            if swf.hasLabel(item, 'idle') then
                                item:gotoAndStop('idle')
                            end
                        end)
                end)
            end
            local mc = rootswf.ns['page'].topMC
            playItem(mc.ns['btn_play'])
            playItem(mc.ns['btn_ttsz'])
            playItem(mc.ns['btn_bbmath'])
            playItem(mc.ns['item1'])
            playItem(mc.ns['item2'])
            playItem(mc.ns['item3'])

            local btn = mc.ns['btn_play']
            self(btn):onClick(function ()
                print('hello click')
                xGame:popScene()
            end)
        end)
end

return SWFTest