local cls = class(M)
cls.CPPCLS = "cocos2d::DrawNode"
cls.LUACLS = "cc.DrawNode"
cls.SUPERCLS = "cc.Node"
cls.funcs [[
    static DrawNode* create(GLfloat defaultLineWidth = 2)
    void drawPoint(const Vec2& point, const float pointSize, const Color4F &color)
    // void drawPoints(const Vec2 *position, unsigned int numberOfPoints, const Color4F &color)
    // void drawPoints(const Vec2 *position, unsigned int numberOfPoints, const float pointSize, const Color4F &color)
    void drawLine(const Vec2 &origin, const Vec2 &destination, const Color4F &color)
    void drawRect(const Vec2 &origin, const Vec2 &destination, const Color4F &color)
    // void drawPoly(const Vec2 *poli, unsigned int numberOfPoints, bool closePolygon, const Color4F &color)
    void drawCircle( const Vec2& center, float radius, float angle, unsigned int segments, bool drawLineToCenter, float scaleX, float scaleY, const Color4F &color)
    void drawCircle(const Vec2 &center, float radius, float angle, unsigned int segments, bool drawLineToCenter, const Color4F &color)
    void drawQuadBezier(const Vec2 &origin, const Vec2 &control, const Vec2 &destination, unsigned int segments, const Color4F &color)
    void drawCubicBezier(const Vec2 &origin, const Vec2 &control1, const Vec2 &control2, const Vec2 &destination, unsigned int segments, const Color4F &color)
    // void drawCardinalSpline(PointArray *config, float tension,  unsigned int segments, const Color4F &color)
    // void drawCatmullRom(PointArray *points, unsigned int segments, const Color4F &color)
    void drawDot(const Vec2 &pos, float radius, const Color4F &color)
    void drawRect(const Vec2 &p1, const Vec2 &p2, const Vec2 &p3, const Vec2& p4, const Color4F &color)
    void drawSolidRect(const Vec2 &origin, const Vec2 &destination, const Color4F &color)
    // void drawSolidPoly(const Vec2 *poli, unsigned int numberOfPoints, const Color4F &color)
    void drawSolidCircle(const Vec2& center, float radius, float angle, unsigned int segments, float scaleX, float scaleY, const Color4F &color)
    void drawSolidCircle(const Vec2& center, float radius, float angle, unsigned int segments, const Color4F& color)
    void drawSegment(const Vec2 &from, const Vec2 &to, float radius, const Color4F &color)
    // void drawPolygon(const Vec2 *verts, int count, const Color4F &fillColor, float borderWidth, const Color4F &borderColor)
    void drawTriangle(const Vec2 &p1, const Vec2 &p2, const Vec2 &p3, const Color4F &color)
    void clear()
    const BlendFunc& getBlendFunc()
    void setBlendFunc(const BlendFunc &blendFunc)
    void onDraw(const Mat4 &transform, uint32_t flags)
    void onDrawGLLine(const Mat4 &transform, uint32_t flags)
    void onDrawGLPoint(const Mat4 &transform, uint32_t flags)
    void setLineWidth(GLfloat lineWidth)
    GLfloat getLineWidth()
]]

return cls