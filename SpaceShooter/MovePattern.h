#pragma once
#include "Enemy.h"

class MovePattern{
public:
	virtual ~MovePattern(void){};
	virtual void moveLogic() = 0;
};