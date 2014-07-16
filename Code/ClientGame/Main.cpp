
#include "stdafx.h"
#include "PlayerActor.h"
#include "EnemyActor.h"


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
    EnemyActor *e = new EnemyActor();


    theWorld.Add(p);
    theWorld.Add(e);
	// do all your setup first, because this function won't return until you're exiting
	theWorld.StartGame();

	// any cleanup can go here
	theWorld.Destroy();

	return 0;
}
