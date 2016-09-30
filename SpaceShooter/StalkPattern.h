#pragma once
#include "MovePattern.h"
class StalkPattern :
	public MovePattern
{
public:
	StalkPattern(SolidSprite* movingObj, SolidSprite* stalkedObj);
	~StalkPattern(void);
	void moveLogic();
private:
	SolidSprite* movingObj;
	SolidSprite* stalkedObj;
	
	int defaultXspeed;
	int defaultYspeed;
};

