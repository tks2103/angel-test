//
//  PlayerActor.cpp
//  ClientGame
//
//  Created by tks2103 on 6/29/14.
//
//

#include "PlayerActor.h"
#include <iostream>
const float IMPULSE = 550.0;

PlayerActor::PlayerActor() {
    SetPosition(2.0f, 2.0f);
    SetColor(1.0f, 0.0f, 1.0f);
    SetSize(2.0f, 3.2f);
    SetDrawShape(ADS_Square);

    SetDensity(0.8f);
    SetFriction(0.1f);
    SetRestitution(0.7f);
    SetShapeType(PhysicsActor::SHAPETYPE_BOX);
    InitPhysics();
    GetBody()->SetLinearDamping(7.0f);
    GetBody()->SetFixedRotation(true);

    theSwitchboard.SubscribeTo(this, "SwingSword");
}

void PlayerActor::ReceiveMessage(Message *m) {
    if (m->GetMessageName() == "SwingSword") {
        SwingSword();
    }
}


void PlayerActor::Update(float dt) {
    if (theInput.IsKeyDown(GLFW_KEY_RIGHT)) {
        ApplyForce(Vector2(IMPULSE, 0.0f), Vector2(0.0f, 0.0f));
    }
    if (theInput.IsKeyDown(GLFW_KEY_LEFT)) {
        ApplyForce(Vector2(-IMPULSE, 0.0f), Vector2(0.0f, 0.0f));
    }
    if (theInput.IsKeyDown(GLFW_KEY_UP)) {
        ApplyForce(Vector2(0.0f, IMPULSE), Vector2(0.0f, 0.0f));
    }
    if (theInput.IsKeyDown(GLFW_KEY_DOWN)) {
        ApplyForce(Vector2(0.0f, -IMPULSE), Vector2(0.0f, 0.0f));
    }
    PhysicsActor::Update(dt);
}


void PlayerActor::SwingSword() {
    if (swinging == true) {
        return;
    }
    sword = new SwordActor();
    sword->AttachTo(this);
}
