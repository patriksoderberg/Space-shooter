#include "SolidSprite.h"
#ifndef ENEMY_H
#define ENEMY_H
class Enemy: public SolidSprite{
public:
	Enemy(int x, int y, SDL_Surface* image);
	virtual ~Enemy(void);
	void update();
	virtual void move();

private:
	int scoreValue = 0;
	void checkIfDead(); //If dead the status of the object is set to dead.
	int getScore();

	
};

#endif