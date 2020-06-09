local class         = require "xgame.class"
local window        = require "xgame.window"
local ScrollImpl    = require "xgame.ui.ScrollImpl"
local Align         = require "xgame.ui.Align"
local FLMovieClip   = require "xgame.swf.FLMovieClip"
local swf           = require "xgame.swf.swf"

local FLScrollBase = class("FLScrollBase", FLMovieClip)

function FLScrollBase:ctor()
    self:stop()
    self.touchChildren = false
    self.touchable = true
    self._container = self.ns['container']
    local viewport = assert(self.ns['__viewport__'], 'no viewport')
    viewport.visible = false
    rawset(self, 'width', viewport.width)
    rawset(self, 'height', viewport.height)
    self._scrollImpl = self:_createScrollImpl()
end

function FLScrollBase:_createScrollImpl()
    return ScrollImpl.new(self, self._container)
end

function FLScrollBase:getBounds(target)
    return self.cobj:getBounds(target.cobj, 0, self.width, 0, self.height)
end

function FLScrollBase:getScrollBounds()
    local obj = self._container
    local l, r, t, b = obj:getBounds(self, 0, obj.width, 0, obj.height)
    return l, r, b, t
end

function FLScrollBase:_validateMetaLayout()
    FLMovieClip._validateMetaLayout(self)
    local viewport = self.metadata.viewport
    if viewport then
        local vw, vh = string.match(viewport, '(%w+) *, *(%w+)')
        assert(vw and vh, 'not a valid viewport: ' .. viewport)
        local vl, vr, vt, vb = window.getVisibleBounds()
        vl, vt = self.parent:globalToLocal(vl, vt)
        vr, vb = self.parent:globalToLocal(vr, vb)
        local ml, mr, mt, mb = 0, self.movieWidth, 0, self.movieHeight
        ml, mt = self.rootNode.rootswf:localToGlobal(ml, mt)
        mr, mb = self.rootNode.rootswf:localToGlobal(mr, mb)
        ml, mt = self.parent:globalToLocal(ml, mt)
        mr, mb = self.parent:globalToLocal(mr, mb)
        if vw == 'match' then
            self.width = math.abs(vr - vl) - math.abs((mr - ml) - self.width)
        end
        if vh == 'match' then
            self.height = math.abs(vt - vb) - math.abs((mt - mb) - self.height)
        end
    end
end

function FLScrollBase:_invalidate()
    self._childrenBounds = false
    self._scrollImpl:validateLater()
end

function FLScrollBase:validateDisplay()
    FLMovieClip.validateDisplay(self)
    self:_invalidate()
end

function FLScrollBase:validateNow()
    self._scrollImpl:validate()
end

return FLScrollBase