#include "Box2DAdapter.h"

USING_NS_BOX2D;
USING_NS_CC;

void DestructionListener::SayGoodbye(b2Joint *joint)
{
    if (sayGoodbyeToJoint) {
        sayGoodbyeToJoint(joint);
    }
}

void DestructionListener::SayGoodbye(b2Fixture *fixture)
{
    if (sayGoodbyeToFixture) {
        sayGoodbyeToFixture(fixture);
    }
}

bool ContactFilter::ShouldCollide(b2Fixture *fixtureA, b2Fixture *fixtureB)
{
    if (shouldCollide) {
        return shouldCollide(fixtureA, fixtureB);
    } else {
        return b2ContactFilter::ShouldCollide(fixtureA, fixtureB);
    }
}


void ContactListener::BeginContact(b2Contact *contact)
{
    if (beginContact) {
        beginContact(contact);
    }
}

void ContactListener::EndContact(b2Contact *contact)
{
    if (endContact) {
        endContact(contact);
    }
}

void ContactListener::PreSolve(b2Contact *contact, const b2Manifold *oldManifold)
{
    if (preSolve) {
        preSolve(contact, oldManifold);
    }
}

void ContactListener::PostSolve(b2Contact *contact, const b2ContactImpulse *impulse)
{
    if (postSolve) {
        postSolve(contact, impulse);
    }
}

bool QueryCallback::ReportFixture(b2Fixture *fixture)
{
    CCASSERT(reportFixture, "no report fixture callback");
    return reportFixture(fixture);
}

float RayCastCallback::ReportFixture(b2Fixture *fixture, const b2Vec2 &point, const b2Vec2 &normal, float fraction)
{
    CCASSERT(reportFixture, "no report fixture callback");
    return reportFixture(fixture, point, normal, fraction);
}

Draw::Draw()
{
    _node = DrawNode::create();
    CC_SAFE_RETAIN(_node);
}

Draw::~Draw()
{
    CC_SAFE_RELEASE(_node);
}

void Draw::DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color)
{
    
}

void Draw::DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color)
{
    
}

void Draw::DrawCircle(const b2Vec2& center, float radius, const b2Color& color)
{
    
}

void Draw::DrawSolidCircle(const b2Vec2& center, float radius, const b2Vec2& axis, const b2Color& color)
{
    
}

void Draw::DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color)
{
    
}

void Draw::DrawTransform(const b2Transform& xf)
{
    
}

void Draw::DrawPoint(const b2Vec2& p, float size, const b2Color& color)
{
    
}
