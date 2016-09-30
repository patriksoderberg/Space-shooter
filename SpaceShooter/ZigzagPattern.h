#pragma once
#include "MovePattern.h"
#include "MyTimer.h"

class ZigzagPattern :
	public MovePattern
{
public:
	ZigzagPattern(SolidSprite* movingObj, int ticksUntilDirectionChange);
	~ZigzagPattern(void);
	void moveLogic();

private:
	MyTimer* timer = new MyTimer();
	SolidSprite* movingObj;
	int ticksUntilDirectionChange;
};

