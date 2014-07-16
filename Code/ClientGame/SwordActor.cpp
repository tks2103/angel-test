//
//  SwordActor.cpp
//  ClientGame
//
//  Created by tks2103 on 6/30/14.
//
//

#include "SwordActor.h"

const float SWORD_LENGTH = 1.4f;
const float DEGTORAD = pi / 180.0f;

SwordActor::~SwordActor() {
    theWorld.GetPhysicsWorld().DestroyJoint(joint);
    joint = NULL;
    PhysicsActor::~PhysicsActor();
}


SwordActor::SwordActor() {
    swordTicks = 0;
}


void SwordActor::AttachTo(PhysicsActor *actor) {
    Vector2 actorPosition = actor->GetPosition();
    Vector2 actorSize = actor->GetSize();
    Vector2 actorOffset(actorSize.X / 2.0f, actorSize.Y / 2.0f);
    Vector2 swordSize(2.4f, 0.4f);
    Vector2 anchorA(actorSize.X / 2.0f, 0.0f);
    Vector2 anchorB(-SWORD_LENGTH * 1.2f, 0.0f);
    float swingStart = -55;
    float swingEnd = 55;

    SetPosition(actorPosition.X + actorOffset.X + SWORD_LENGTH / 2.0f, actorPosition.Y + actorOffset.Y);
    SetColor(0.0f, 1.0f, 0.0f);
    SetSize(swordSize);
    SetDrawShape(ADS_Square);

    SetDensity(0.01f);
    SetFriction(1.0f);
    SetRestitution(0.0f);
    SetShapeType(PhysicsActor::SHAPETYPE_BOX);
    InitPhysics();
    GetBody()->SetLinearDamping(7.0f);

    jointDef.bodyA = actor->GetBody();
    jointDef.bodyB = this->GetBody();
    jointDef.collideConnected = false;
    jointDef.localAnchorA = b2Vec2(anchorA.X, anchorA.Y);
    jointDef.localAnchorB = b2Vec2(anchorB.X, anchorB.Y);
    jointDef.lowerAngle = swingStart * DEGTORAD;
    jointDef.upperAngle = swingEnd * DEGTORAD;
    jointDef.enableLimit = true;
    joint = (b2RevoluteJoint*)theWorld.GetPhysicsWorld().CreateJoint(&jointDef);

    ApplyAngularImpulse(-0.5);
    theWorld.Add(this);
}


void SwordActor::Update(float dt) {
    swordTicks++;
    if (swordTicks > 20) {
        theWorld.GetPhysicsWorld().DestroyJoint(joint);
        theWorld.GetPhysicsWorld().DestroyBody(GetBody());
        joint = NULL;
        theWorld.Remove(this);
    }
    PhysicsActor::Update(dt);
}
