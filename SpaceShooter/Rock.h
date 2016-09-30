#pragma once
#include "SolidSprite.h"
#include <string>
using namespace std;
class Rock : public SolidSprite{
public:
	Rock(int x, int y);
	//Rock(int x, int y, int horisontalSpeed);

private:
	const int HORISONTAL_SPEED = -10;
	const int VERTICAL_SPEED = 0;
	const int ATTACK_VALUE = 1;
	const int HEALTH = 5;
};

