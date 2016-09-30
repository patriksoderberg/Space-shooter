#include "Enemy.h"
#include <iostream>
#include "SDL.h"
#include "SDL_image.h"
#include <time.h> 

Enemy::Enemy(int xx, int yy, SDL_Surface* image) : SolidSprite(xx, yy, image){
	setBadGuy(true);
}

Enemy::~Enemy(void)
{
	
}

void Enemy::move(){
	setX(getX() + getXspd());
	setY(getY() + getYspd());
}

void Enemy::update(){
	if (getHealth() <= 0 || getX() + getWidth() <= 0){
		//setDead(true);
		setHealth(1);
		setX(1300 + (rand() % 100));
		setY(rand() % 600);
	}	
	else{
		move();
	}
};


//Checks if object is outside of the screen or has zero health and changes the death status.
void Enemy::checkIfDead(){
	if (getHealth() <= 0 || getX() + getWidth() <= 0 || getX() >= 1280){
		setDead(true);
	}
}

int Enemy::getScore(){
	return scoreValue;
}




