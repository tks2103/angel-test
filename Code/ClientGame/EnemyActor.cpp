//
//  EnemyActor.cpp
//  ClientGame
//
//  Created by tks2103 on 7/1/14.
//
//

#include "EnemyActor.h"

EnemyActor::EnemyActor() {
    SetPosition(-2.0f, -2.0f);
    SetColor(1.0f, 0.0f, 0.0f);
    SetSize(1.5f, 2.0f);
    SetDrawShape(ADS_Square);
    
    SetDensity(0.8f);
    SetFriction(0.1f);
    SetRestitution(0.7f);
    SetShapeType(PhysicsActor::SHAPETYPE_BOX);
    InitPhysics();
    GetBody()->SetLinearDamping(7.0f);
    GetBody()->SetFixedRotation(true);
}