#ifndef PLAYER_H
#define PLAYER_H

#include "SolidSprite.h"
#include <vector>
#include <SDL_mixer.h>

class Player : public SolidSprite{
public:
	Player(int xx, int yy, int screenWidth, int screenHeight, SDL_Surface* img);
	virtual ~Player(void);

	void handleInput(std:: vector<SolidSprite*> *objectContainer);
	void update();
	void collides(SolidSprite* other);
	void getScore();
	void onCollision();

private:
	const int SHOOT_CD = 10;
	const int PLAYER_HEALTH = 10;
	const int MAX_X_SPEED = 7;
	const int MAX_Y_SPEED = 7;
	const int ATTACK_VALUE = 1; //Deals this damage on contact with the ship

	int screenWidth; //Width of the window
	int screenHeight; //Height of the window
	int score;
	int frames = 0;

	bool invincible = false;
	int const INVINCIBLE_CD = 15; //How many frames player should be invincible after hit
	int invincibleFrames = 0; //How many frames player has been invincible
	Mix_Chunk * shootSound;
};

#endif