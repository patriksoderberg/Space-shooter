#ifndef SOLIDOBJ_H
#define SOLIDOBJ_H
#include "Sprite.h"


class SolidSprite : public Sprite{
public:
	SolidSprite(int xx, int yy, SDL_Surface* img);
	SolidSprite(int xx, int yy, SDL_Surface* img, int xSpeed, int ySpeed, int health, int atk);
	virtual ~SolidSprite(void);
	
	virtual void update();
	void draw(SDL_Surface* surface);

	virtual void onCollision();
	virtual void collides(SolidSprite* other); //not used atm
	
	void attack(SolidSprite *other);
	
	//Setters
	void setArmor(int armorValue);
	void setBadGuy(bool isBad);
	void setHealth(int newHealth);
	void setDead(bool dead);
	void setAttack(int newAttack);
	//Getters
	int getArmor();
	bool isBadGuy();
	int getHealth();
	bool isDead();
	int getAttack();
	
private:
	bool badGuy;
	int armor = 0;
	int attackValue = 0;
	int health = 1;
	bool dead = false;
	
	
};

#endif