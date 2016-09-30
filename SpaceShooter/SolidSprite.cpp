#include "SolidSprite.h"
#include <iostream>


SolidSprite::SolidSprite(int xx, int yy, SDL_Surface* img) : Sprite(xx, yy, img){

}

SolidSprite::SolidSprite(int xx, int yy, SDL_Surface* img, int xSpeed, int ySpeed, int health, int atk) : Sprite(xx, yy, img){
	setXspd(xSpeed);
	setYspd(ySpeed);
	this->health = health;
	attackValue = atk;
}

SolidSprite::~SolidSprite(void){
	std::cout << "solidsprite delete" << std::endl;
}

//Object dies if it's outside the screen or has 0 health
void SolidSprite::update(){
	
	if (health <= 0 || getX() <= 0 || getX() > 1500){
		dead = true;
	}
	else{
		setX(getX() + getXspd()); 
		setY(getY() + getYspd()); 
	}
}

void SolidSprite::onCollision(){
	//Do nothing
}

void SolidSprite::collides(SolidSprite* other){
	//Kolla inte collision mot andra från samma fraktion.
	if (badGuy != other->isBadGuy()){
	
		if (other->getX() < (getX() + getWidth()) && (other->getX() + other->getWidth()) > getX() && (getY() + getHeight()) > other->getY() && getY() < (other->getY() + other->getHeight())) {
			setHealth(getHealth() - other->getAttack()); //Tar bort liv om träffad
			std::cout << "Kolliderar" << std::endl;
		}
	}

}
void SolidSprite::draw(SDL_Surface* surface){
	SDL_Rect offset;
	offset.x = getX(); offset.y = getY();
	SDL_BlitSurface(getImage(), NULL, surface, &offset);

	//SDL_FillRect(surface, &hitBox, SDL_MapRGB(surface->format, 255, 0, 0));
	
};



int SolidSprite::getAttack(){
	return attackValue;
}

void SolidSprite::setAttack(int newAttack){
	attackValue = newAttack;
}

int SolidSprite::getHealth(){
	return health;
}

void SolidSprite::setHealth(int newHealth){
	health = newHealth;
}

//Changed this, is this correct? CHECK IT
bool SolidSprite::isDead(){
	//if (getHealth() <= 0  ) // || ska jag kolla om utanför fönstret här?
	return dead;
}

void SolidSprite::setDead(bool dead){
	this->dead = dead;
}


bool SolidSprite::isBadGuy(){
	return badGuy;
}

void SolidSprite::setBadGuy(bool isBad){
	badGuy = isBad;
}

void SolidSprite::setArmor(int armorValue){
	armor = armorValue;
}

int SolidSprite::getArmor(){
	return armor;
}

//Reduce the health of the attacked object by the current object's attack value
void SolidSprite::attack(SolidSprite *other){
	int damage = attackValue - other->getArmor();
	//Only do damage if the damage value is over 0. Don't want to heal.
	if (damage > 0){
		other->health -= damage;
		std::cout << "DAMAGE: " << damage << std::endl;
	}
}