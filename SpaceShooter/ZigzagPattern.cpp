#include "ZigzagPattern.h"


ZigzagPattern::ZigzagPattern(SolidSprite* movingObj, int ticksUntilDirectionChange)
{
	this->movingObj = movingObj;
	this->ticksUntilDirectionChange = ticksUntilDirectionChange;
}


ZigzagPattern::~ZigzagPattern(void)
{
	delete timer;
}

void ZigzagPattern::moveLogic(){

	//Start the timer first time this function is called
	if (!timer->isStarted())
		timer->start();
	//Change direction every few seconds or if outside vertical borders
	if (timer->getTicks() >= ticksUntilDirectionChange || movingObj->getY() <= 0 && movingObj->getYspd() < 0 || movingObj->getY() + movingObj->getHeight() >= 720 && movingObj->getYspd() > 0){
		movingObj->setYspd(movingObj->getYspd()*-1);
		//restart timer
		timer->stop();
		timer->start();
	}

	movingObj->setX(movingObj->getXspd() + movingObj->getX());
	movingObj->setY(movingObj->getYspd() + movingObj->getY());
}
