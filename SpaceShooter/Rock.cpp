#include "Rock.h"
#include <iostream>

Rock::Rock(int x, int y) : SolidSprite(x, y, IMG_Load("Resources/rock.jpg")){
	setBadGuy(true);
	setXspd(HORISONTAL_SPEED);
	setYspd(VERTICAL_SPEED);
	setAttack(ATTACK_VALUE);
	setHealth(HEALTH);
}

