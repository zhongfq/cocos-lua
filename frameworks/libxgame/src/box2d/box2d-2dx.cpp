#include "box2d-2dx.h"

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

Box2dNode *Box2dNode::create(b2World *world)
{
    Box2dNode *ret = new (std::nothrow) Box2dNode();
    if (ret && ret->init(world)) {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return nullptr;
}

Box2dNode::Box2dNode()
:_world(nullptr)
{
}

Box2dNode::~Box2dNode()
{
}

bool Box2dNode::init(b2World *world)
{
    _world = world;
    _world->SetDebugDraw(this);
    return DrawNode::init();
}

void Box2dNode::visit(Renderer *renderer, const Mat4& parentTransform, uint32_t parentFlags)
{
    _world->DebugDraw();
    DrawNode::visit(renderer, parentTransform, parentFlags);
}

Color4F Box2dNode::toColor4f(const b2Color& value)
{
    return Color4F(value.r, value.g, value.b, value.r);
}

Vec2 Box2dNode::toVec2(const b2Vec2& value)
{
    return Vec2(value.x, value.y);
}

void Box2dNode::DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color)
{
    drawPoly((Vec2 *)vertices, vertexCount, false, toColor4f(color));
}

void Box2dNode::DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color)
{
    drawPolygon((Vec2 *)vertices, vertexCount, toColor4f(color), 0, toColor4f(color));
}

void Box2dNode::DrawCircle(const b2Vec2& center, float radius, const b2Color& color)
{
    drawCircle(toVec2(center), radius, 0, 20, false, toColor4f(color));
}

void Box2dNode::DrawSolidCircle(const b2Vec2& center, float radius, const b2Vec2& axis, const b2Color& color)
{
    drawSolidCircle(toVec2(center), radius, 0, 20, toColor4f(color));
}

void Box2dNode::DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color)
{
    drawLine(toVec2(p1), toVec2(p2), toColor4f(color));
}

void Box2dNode::DrawTransform(const b2Transform& xf)
{
    const float k_axisScale = 0.4f;
    Color4F red(1.0f, 0.0f, 0.0f, 1.0f);
    Color4F green(0.0f, 1.0f, 0.0f, 1.0f);
    Vec2 p1 = toVec2(xf.p);
    Vec2 p2 = p1 + toVec2(xf.q.GetXAxis()) * k_axisScale;
    
    drawLine(p1, p2, red);

    p2 = p1 + toVec2(xf.q.GetYAxis()) * k_axisScale;
    drawLine(p1, p2, green);
}

void Box2dNode::DrawPoint(const b2Vec2& p, float size, const b2Color& color)
{
    drawPoint(toVec2(p), size, toColor4f(color));
}
