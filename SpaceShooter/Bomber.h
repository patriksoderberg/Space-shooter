#pragma once
#include "SolidSprite.h"
#include "Player.h"

class Bomber :
	public SolidSprite
{
public:
	Bomber(int x, int y, Player* player, std::vector<SolidSprite*>*  objectContainer);
	void update();
private:
	static const int DEFAULT_HEALTH = 2;
	static const int DEFAULT_ATTACK_VALUE = 1;
	static const int DEFAULT_VERTICAL_SPEED = -2;
	static const int DEFAULT_HORISONTAL_SPEED = -4;

	Player* player;
	std::vector<SolidSprite*>* objectContainer;

	void shootLogic();
	void shoot();
	int shootCD = 30; //in frames
	int cdCounter = shootCD; //this is reset to 0 every time object shoots
	int shootRange = 50;
	
};

