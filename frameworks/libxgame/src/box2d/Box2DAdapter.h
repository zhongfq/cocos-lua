#ifndef __BOX2D_BOX2DADAPTER__
#define __BOX2D_BOX2DADAPTER__

#include "box2d/box2d.h"
#include "cclua/runtime.h"

#include <functional>

#define NS_BOX2D_BEGIN  namespace box2d {
#define NS_BOX2D_END    }
#define USING_NS_BOX2D using namespace box2d

NS_BOX2D_BEGIN

class DestructionListener : public b2DestructionListener
{
public:
    DestructionListener() {}
    virtual void SayGoodbye(b2Joint *joint) override;
    virtual void SayGoodbye(b2Fixture *fixture) override;
    
    std::function<void(b2Joint *)> sayGoodbyeToJoint;
    std::function<void(b2Fixture *)> sayGoodbyeToFixture;
};

class ContactFilter : public b2ContactFilter
{
public:
    ContactFilter() {}

    virtual bool ShouldCollide(b2Fixture *fixtureA, b2Fixture *fixtureB) override;
    
    std::function<bool(b2Fixture *, b2Fixture *)> shouldCollide;
};

class ContactListener : public b2ContactListener
{
public:
    ContactListener() {}

    virtual void BeginContact(b2Contact *contact) override;
    virtual void EndContact(b2Contact *contact) override;
    virtual void PreSolve(b2Contact *contact, const b2Manifold *oldManifold) override;
    virtual void PostSolve(b2Contact *contact, const b2ContactImpulse *impulse) override;
    
    std::function<void(b2Contact *)> beginContact;
    std::function<void(b2Contact *)> endContact;
    std::function<void(b2Contact *, const b2Manifold *)> preSolve;
    std::function<void(b2Contact *, const b2ContactImpulse *)> postSolve;
};

class QueryCallback : public b2QueryCallback
{
public:
    QueryCallback() {}
    virtual bool ReportFixture(b2Fixture *fixture) override;
    
    std::function<bool(b2Fixture *)> reportFixture;
};

class RayCastCallback : public b2RayCastCallback
{
public:
    RayCastCallback() {}
    
    virtual float ReportFixture(b2Fixture *fixture, const b2Vec2 &point, const b2Vec2 &normal, float fraction) override;
    
    std::function<float(b2Fixture *, const b2Vec2 &, const b2Vec2 &, float)> reportFixture;
};

class Draw : public b2Draw
{
public:
    Draw();
    virtual ~Draw();

    virtual void DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color) override;
    virtual void DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color) override;
    virtual void DrawCircle(const b2Vec2& center, float radius, const b2Color& color) override;
    virtual void DrawSolidCircle(const b2Vec2& center, float radius, const b2Vec2& axis, const b2Color& color) override;
    virtual void DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color) override;
    virtual void DrawTransform(const b2Transform& xf) override;
    virtual void DrawPoint(const b2Vec2& p, float size, const b2Color& color) override;
    
    cocos2d::DrawNode *getRenderer() const { return _node; }
protected:
    cocos2d::DrawNode *_node = nullptr;
};

NS_BOX2D_END

#endif
