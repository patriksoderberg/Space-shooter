#include "Spawner.h"
#include <iostream>
#include "Rock.h"
#include <time.h> 
#include "ZigZagEnemy.h"
#include "StalkerEnemy.h"

Spawner::Spawner(vector<SolidSprite*>& gameObjects, Player* player){
	this->gameObjects = &gameObjects;
	this->player = player;
	currentFrames = 0;
	srand(time(NULL));

	//vector<SolidSprite*> wave1 = { new Rock(1, 1, IMG_Load("Resources/rock.jpg")), new Rock(1, 1, IMG_Load("Resources/rock.jpg")) };




	//spawnWaves.push_back(wave1);
}
void Spawner::spawn(){
	
	if (currentFrames %FRAMES_PER_SPAWN == 0 ){
		//for (SolidSprite* obj : spawnObjects)
			gameObjects->push_back(new Rock(1200, rand() % 700));
			gameObjects->push_back(new ZigZagEnemy(1200, rand() % 700));
			gameObjects->push_back(new StalkerEnemy(1200, rand() % 700, player));
			
	}

	currentFrames++;
}

//vector<vector<SolidSprite*>> initWaves(){
//	vector<SolidSprite*> wave1 = {};
//}