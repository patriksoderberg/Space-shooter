#pragma once
#include "SolidSprite.h"
#include "ZigzagPattern.h"

class ZigZagEnemy :
	public SolidSprite
{
public:
	ZigZagEnemy(int x, int y);
	~ZigZagEnemy();
	void update();
private:
	ZigzagPattern* pattern;

	int const static HEALTH_VALUE = 3;
	int const static ATTACK_VALUE = 1;
	int const static HORISONTAL_SPEED = -3;
	int const static VERTICAL_SPEED = 1;
	int const static TICKS_UNTIL_DIRECTION_CHANGE = 2000;

};

