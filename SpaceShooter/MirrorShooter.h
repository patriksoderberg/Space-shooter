#pragma once
#include "SolidSprite.h"
#include "Player.h"
#include "StalkPattern.h"
#include "MyTimer.h"

class MirrorShooter :
	public SolidSprite
{
public:
public:
	MirrorShooter(int x, int y, Player* player, std::vector<SolidSprite*>*  objectContainer);
	void update();

private:
	static const int DEFAULT_HEALTH = 3;
	static const int DEFAULT_ATTACK_VALUE = 1;
	static const int DEFAULT_VERTICAL_SPEED = 4;
	static const int DEFAULT_HORISONTAL_SPEED = 1;
	int currentXSpeed;
	StalkPattern* pattern;
	MyTimer* timer;

	Player* player;
	std::vector<SolidSprite*>* objectContainer;

	int shootCD = 30; //in frames
	int cdCounter = shootCD; //this is reset to 0 every time object shoots
	int shootRange = 10;
	void shootLogic();
	void shoot();
};

