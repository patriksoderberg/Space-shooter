#include "StalkerEnemy.h"

StalkerEnemy::StalkerEnemy(int x, int y, Player* player) : SolidSprite(x, y, IMG_Load("Resources/stalker.png"))
{
	pattern = new StalkPattern(this, player);
	setBadGuy(true);
	setHealth(DEFAULT_HEALTH);
	setAttack(DEFAULT_ATTACK_VALUE);
	setXspd(DEFAULT_HORISONTAL_SPEED);
	setYspd(DEFAULT_VERTICAL_SPEED);
	
}

void StalkerEnemy::update(){
	if (getHealth() <= 0 || getX() + getWidth() <= 0 || getX() >= 1500){
		setDead(true);
	}
	else{
		pattern->moveLogic();
	}
}