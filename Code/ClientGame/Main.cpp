
#include "stdafx.h"
#include "PlayerActor.h"


int main(int argc, char* argv[])
{
	theWorld.Initialize();
    theWorld.SetupPhysics(Vector2(0.0f, 0.0f));
    theWorld.SetSideBlockers(true);

    GridActor *g = new GridActor();
    theWorld.Add(g);

    TextActor *t = new TextActor("Console", "Yaaa", TXT_Center);
    theWorld.Add(t);
    PlayerActor *p = new PlayerActor();
    PhysicsActor *pa = new PhysicsActor();
    pa->SetColor(1.0, 0, 0);
    pa->InitPhysics();


    theWorld.Add(p);
    theWorld.Add(pa);
	// do all your setup first, because this function won't return until you're exiting
	theWorld.StartGame();

	// any cleanup can go here
	theWorld.Destroy();

	return 0;
}
