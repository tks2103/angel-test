//
//  PlayerActor.h
//  ClientGame
//
//  Created by tks2103 on 6/29/14.
//
//

#ifndef __ClientGame__PlayerActor__
#define __ClientGame__PlayerActor__

#include "SwordActor.h"

class PlayerActor : public PhysicsActor {
    public:
        void Update(float dt);
        void ReceiveMessage(Message* m);
        void SwingSword();
        PlayerActor();

    private:
        bool swinging;
        SwordActor *sword;
};

#endif /* defined(__ClientGame__PlayerActor__) */
