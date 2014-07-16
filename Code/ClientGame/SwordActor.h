//
//  SwordActor.h
//  ClientGame
//
//  Created by tks2103 on 6/30/14.
//
//

#ifndef __ClientGame__SwordActor__
#define __ClientGame__SwordActor__

class SwordActor : public PhysicsActor {
public:
    SwordActor();
    ~SwordActor();
    void AttachTo(PhysicsActor *actor);
    void Update(float dt);

private:
    b2RevoluteJointDef jointDef;
    b2RevoluteJoint *joint;
    int swordTicks;

};

#endif /* defined(__ClientGame__SwordActor__) */
