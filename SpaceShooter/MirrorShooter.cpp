#include "MirrorShooter.h"
#include <iostream>

MirrorShooter::MirrorShooter(int x, int y, Player* player, std::vector<SolidSprite*>*  objectContainer) : SolidSprite(x, y, IMG_Load("Resources/stalker.png"))
{
	this->player = player;
	this->objectContainer = objectContainer;
	pattern = new StalkPattern(this, player);
	setBadGuy(true);
	setHealth(DEFAULT_HEALTH);
	setAttack(DEFAULT_ATTACK_VALUE);
	setXspd(DEFAULT_HORISONTAL_SPEED);
	setYspd(DEFAULT_VERTICAL_SPEED);
}



void MirrorShooter :: update(){
	if (getHealth() <= 0 || getX() + getWidth() <= 0 || getX() >= 1280){
		setDead(true);
	}
	else{
		pattern->moveLogic();
	}

	shootLogic();
	
}


void MirrorShooter::shootLogic(){
	cdCounter++;
	//Can only Shoot if cooldown is over
	if (cdCounter >= shootCD){
		//Shoot if player is in front (to the left) and within shooting range.
		if (getX() > player->getX() && getY() - shootRange <= player->getY() && getY() + shootRange >= player->getY()){
			shoot();
			cdCounter = 0; //reset cooldown
		}
	}
}

void MirrorShooter::shoot(){
	std::cout << "SHOOT" << std::endl;
	SDL_Surface* img = IMG_Load("Resources/bullet1.png");
	SolidSprite* bullet = new SolidSprite(getX() - 10, getY() + getHeight()/2, img, -10, 0, 1, 1);
	bullet->setBadGuy(true);
	objectContainer->push_back(bullet);
}
