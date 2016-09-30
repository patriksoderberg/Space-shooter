#pragma once
#include "StalkerEnemy.h"
#include "SolidSprite.h"
#include "Player.h"
#include "MyTimer.h"
#include "StalkPattern.h"
class StalkerEnemy : public SolidSprite{
public:
	StalkerEnemy(int x, int y, Player* player);
	void update();

private:
	static const int DEFAULT_HEALTH = 3;
	static const int DEFAULT_ATTACK_VALUE = 1;
	static const int DEFAULT_VERTICAL_SPEED = 4;
	static const int DEFAULT_HORISONTAL_SPEED = 1;
	int currentXSpeed;
	StalkPattern* pattern;
	MyTimer* timer;

};