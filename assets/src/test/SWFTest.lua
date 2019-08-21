local class     = require "xgame.class"
local util      = require "xgame.util"
local MixSWF    = require "xgame.swf.MixSWF"
local swf       = require "xgame.swf.swf"
local FLImage   = require "xgame.swf.FLImage"
local FLQRCode  = require "xgame.swf.FLQRCode"
local A         = require "xgame.ui.action"

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
                -- xGame:popScene()
                xGame:gc()
                btn:runAction(A.Sequence(
                    A.FadeOut(1),
                    A.FadeIn(1)
                ))
            end)

            rootswf.ns['menu'].ns['avatar']:relative('left', 'top')
            rootswf.ns['menu'].ns['user']:relative('left', 'top')
            mc.ns['btn_ttsz']:relative('right', 'bottom')
            mc.ns['btn_bbmath']:relative('right', 'bottom')

            local img = FLImage.new()
            img:load('http://127.0.0.1/cocoslua/current/assets/res/HelloWorld.png')
            img.x = 500
            img.y = 300
            rootswf:addChild(img)

            local code = FLQRCode.new()
            code.text = 'text'
            code.scaleX = 5
            code.scaleY = 5
            code.x = 500
            code.y = 200
            rootswf:addChild(code)
        end)
end

return SWFTest