#ifndef SPAWNER_H
#define SPAWNER_H

#include <vector>
#include "SolidSprite.h"
#include "Player.h"

using namespace std;

class Spawner{
public:
	const int FRAMES_PER_SPAWN = 120;
	Spawner(vector<SolidSprite*>& gameObjects, Player* player);
	void spawn();
private:
	int currentFrames;
	vector<SolidSprite*>* gameObjects; 
	vector<vector<SolidSprite*>> spawnWaves;
	Player* player;
};

#endif