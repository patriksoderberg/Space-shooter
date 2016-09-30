#include "ZigZagEnemy.h"

ZigZagEnemy::ZigZagEnemy(int x, int y) : SolidSprite(x, y, IMG_Load("Resources/jimmy.jpg"))
{
	setBadGuy(true);
	setHealth(HEALTH_VALUE);
	setXspd(HORISONTAL_SPEED);
	setYspd(VERTICAL_SPEED);
	setAttack(ATTACK_VALUE);
	pattern = new ZigzagPattern(this, TICKS_UNTIL_DIRECTION_CHANGE);
}


ZigZagEnemy::~ZigZagEnemy()
{
	delete pattern;
}

void ZigZagEnemy::update(){
	
	if (getHealth() <= 0 || getX() + getWidth() <= 0 || getX() >= 1500){
		setDead(true);
	}
	else{
		pattern->moveLogic();
	}



}
