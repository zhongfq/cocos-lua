#ifndef __BOX2D_2DX_H__
#define __BOX2D_2DX_H__

#include "cclua/runtime.h"
#include "box2d/box2d.h"

#include <functional>

#define NS_BOX2D_BEGIN  namespace box2d {
#define NS_BOX2D_END    }
#define USING_NS_BOX2D using namespace box2d

NS_BOX2D_BEGIN

class DestructionListener : public b2DestructionListener
{
public:
    DestructionListener() {}
    virtual void SayGoodbye(b2Joint *joint) override OLUA_EXCLUDE;
    virtual void SayGoodbye(b2Fixture *fixture) override OLUA_EXCLUDE;
    
    std::function<void(b2Joint *)> sayGoodbyeToJoint;
    std::function<void(b2Fixture *)> sayGoodbyeToFixture;
};

class ContactFilter : public b2ContactFilter
{
public:
    ContactFilter() {}

    virtual bool ShouldCollide(b2Fixture *fixtureA, b2Fixture *fixtureB) override OLUA_EXCLUDE;
    
    std::function<bool(b2Fixture *, b2Fixture *)> shouldCollide;
};

class ContactListener : public b2ContactListener
{
public:
    ContactListener() {}

    virtual void BeginContact(b2Contact *contact) override OLUA_EXCLUDE;
    virtual void EndContact(b2Contact *contact) override OLUA_EXCLUDE;
    virtual void PreSolve(b2Contact *contact, const b2Manifold *oldManifold) override OLUA_EXCLUDE;
    virtual void PostSolve(b2Contact *contact, const b2ContactImpulse *impulse) override OLUA_EXCLUDE;
    
    std::function<void(b2Contact *)> beginContact;
    std::function<void(b2Contact *)> endContact;
    std::function<void(b2Contact *, const b2Manifold *)> preSolve;
    std::function<void(b2Contact *, const b2ContactImpulse *)> postSolve;
};

class QueryCallback : public b2QueryCallback
{
public:
    QueryCallback() {}
    virtual bool ReportFixture(b2Fixture *fixture) override OLUA_EXCLUDE;
    
    std::function<bool(b2Fixture *)> reportFixture;
};

class RayCastCallback : public b2RayCastCallback
{
public:
    RayCastCallback() {}
    
    virtual float ReportFixture(b2Fixture *fixture, const b2Vec2 &point, const b2Vec2 &normal, float fraction) override OLUA_EXCLUDE;
    
    std::function<float(b2Fixture *, const b2Vec2 &, const b2Vec2 &, float)> reportFixture;
};

class Box2dNode : public cocos2d::DrawNode, public b2Draw
{
public:
    static Box2dNode* create(OLUA_ADDREF(world ^) b2World *world);
    
    virtual ~Box2dNode();
    
    virtual void visit(cocos2d::Renderer *renderer, const cocos2d::Mat4& parentTransform, uint32_t parentFlags) override;

    virtual void DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color) override OLUA_EXCLUDE;
    virtual void DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color) override OLUA_EXCLUDE;
    virtual void DrawCircle(const b2Vec2& center, float radius, const b2Color& color) override OLUA_EXCLUDE;
    virtual void DrawSolidCircle(const b2Vec2& center, float radius, const b2Vec2& axis, const b2Color& color) override OLUA_EXCLUDE;
    virtual void DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color) override OLUA_EXCLUDE;
    virtual void DrawTransform(const b2Transform& xf) override OLUA_EXCLUDE;
    virtual void DrawPoint(const b2Vec2& p, float size, const b2Color& color) override OLUA_EXCLUDE;
private:
    Box2dNode();
    
    virtual bool init(b2World *world);
    
    cocos2d::Color4F toColor4f(const b2Color& value);
    cocos2d::Vec2 toVec2(const b2Vec2& value);
private:
    b2World *_world;
};

NS_BOX2D_END

#endif
