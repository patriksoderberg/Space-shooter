#include "StalkPattern.h"
#include <iostream>

StalkPattern::StalkPattern(SolidSprite* movingObj, SolidSprite* stalkedObj)
{
	this->movingObj = movingObj;
	this->stalkedObj = stalkedObj;
}


StalkPattern::~StalkPattern()
{
}

void StalkPattern::moveLogic(){
	//Check if object is moving toward stalkedObj, if not then make it do so.

	//If this object is to the right of stalkedObj and is moving away from stalkedObj, turn around.
	if (movingObj->getX() > stalkedObj->getX() && movingObj->getXspd() > 0){
		movingObj->setXspd(movingObj->getXspd() *-1);
	}
	else if (movingObj->getX() < stalkedObj->getX() && movingObj->getXspd() < 0){
		movingObj->setXspd(movingObj->getXspd() *-1);
	}

	//if stalkedObj is above and this object is not moving towards stalkedObj
	if (movingObj->getY() > stalkedObj->getY() && movingObj->getYspd() > 0)
		movingObj->setYspd(movingObj->getYspd()*-1);
	//if stalkedObj is under this object and this object is not moving towards stalkedObj
	else if (movingObj->getY() < stalkedObj->getY() && movingObj->getYspd() < 0)
		movingObj->setYspd(movingObj->getYspd()*-1);

	//if stalkedObj is (almost) in front: Set y-speed to zero.
	if (movingObj->getY() + 10 > stalkedObj->getY() && movingObj->getY() - 10 < stalkedObj->getY()){
		if (movingObj->getYspd() != 0)
			defaultYspeed = movingObj->getYspd();

		movingObj->setYspd(0);
	}
	else if (movingObj->getYspd() == 0){
		movingObj->setYspd(defaultYspeed);
	}


	//Update the position
	movingObj->setX(movingObj->getXspd() + movingObj->getX());
	movingObj->setY(movingObj->getYspd() + movingObj->getY());
}
