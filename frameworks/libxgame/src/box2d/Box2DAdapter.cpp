#include "Box2DAdapter.h"

USING_NS_BOX2D;

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
    CCASSERT(shouldCollide, "no collide callback");
    return shouldCollide(fixtureA, fixtureB);
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
