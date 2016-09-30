#include "Bomber.h"
#include <iostream>

Bomber::Bomber(int x, int y, Player* player, std::vector<SolidSprite*>*  objectContainer) : SolidSprite(x, y, IMG_Load("Resources/bomber.png"))
{
	this->player = player;
	this->objectContainer = objectContainer;
	setBadGuy(true);
	setHealth(DEFAULT_HEALTH);
	setAttack(DEFAULT_ATTACK_VALUE);
	setXspd(DEFAULT_HORISONTAL_SPEED);
	setYspd(DEFAULT_VERTICAL_SPEED);

}

void Bomber::update(){
	if (getHealth() <= 0 || getX() + getWidth() <= 0){
		setDead(true);
	}
	else{
		setX(getX() + getXspd());
		setY(getY() + getYspd());
		shootLogic();
	}
}

void Bomber::shootLogic(){
	cdCounter++;
	//Can only Shoot if cooldown is over
	if (cdCounter >= shootCD){
		//Shoot if player is below (to the left) and within shooting range.

		if (getY() < player->getY() && getX() - shootRange <= player->getX() + player->getWidth() && getX() + getWidth() + shootRange >= player->getX()){
			shoot();
			cdCounter = 0; //reset cooldown
		}
	}
}

void Bomber::shoot(){
	std::cout << "SHOOT" << std::endl;
	SDL_Surface* img = IMG_Load("Resources/bullet1.png");
	SolidSprite* bullet = new SolidSprite(getX() - 10, getY() + getHeight() / 2, img, 0, 5, 1, 1);
	bullet->setBadGuy(true);
	objectContainer->push_back(bullet);
}