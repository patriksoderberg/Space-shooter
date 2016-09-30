#include "Player.h"
#include <iostream>

Player::Player(int xx, int yy, int screenWidth, int screenHeight, SDL_Surface* img) : SolidSprite(xx, yy, img){
	setAttack(ATTACK_VALUE);
	setHealth(PLAYER_HEALTH);
	setBadGuy(false);
	this->screenWidth = screenWidth; //Width of the window
	this->screenHeight = screenHeight; //height of the window

	shootSound = Mix_LoadWAV("laser1.wav");
}

Player::~Player(void)
{
}

//Player becomes invincible for a few frames
void Player::onCollision(){
	if (invincible == false){
		SDL_SetAlpha(getImage(), SDL_SRCALPHA, 100); //Transparent when invincible
		invincible = true;
		setArmor(getArmor() + 1000);
		setAttack(0); //Ship can't deal damage while invincible
	}
	
}
//TODO ta bort hårdkodning av fönsterdimensioner
void Player::update(){
	//Only update if player is alive
	if (getHealth() > 0){
		
		//If the player is outside of left or right border : Remove the x-speed
		if (getX() + getWidth() >= screenWidth && getXspd() > 0 || getX() <= 0 && getXspd() < 0)
			setXspd(getXspd() - getXspd());
		//Top/down
		if (getY() + getHeight() >= screenHeight && getYspd() > 0 || getY() <= 0 && getYspd() < 0)
			setYspd(getYspd() - getYspd());
		
		setX(getX() + getXspd());
		setY(getY() + getYspd());

		if (invincible == true){
			//If player no longer is invincible
			if (invincibleFrames++ == INVINCIBLE_CD){
				invincibleFrames = 0; //reset the counter
				setArmor(getArmor() - 1000); //armor back to normal
				setAttack(ATTACK_VALUE); //ship damage to normal
				invincible = false;
				SDL_SetAlpha(getImage(), SDL_SRCALPHA, 255);
			}

		}
	}
};
/*
void shoot(bool activated){
	SDL_Surface* bulletImg = IMG_Load("bullet1.png");
	SolidSprite* bullet = new SolidSprite(getX(), getY(), bulletImg, 4, 0, 1, getAttack());
	bullet->setBadGuy(false);
	gameObjects->push_back(bullet);
	std::cout << "En kula" << std::endl;
}
*/
void Player::handleInput(std::vector<SolidSprite*> *objectContainer){
	frames++;
	
	Uint8 *keystates = SDL_GetKeyState(NULL);
	if (keystates[SDLK_UP])
		setYspd(MAX_Y_SPEED * -1); 
	else if (keystates[SDLK_DOWN])
		setYspd(MAX_Y_SPEED);
	else
		setYspd(0);
	
	if (keystates[SDLK_LEFT])
		setXspd(MAX_X_SPEED * -1);
	else if (keystates[SDLK_RIGHT])
		setXspd(MAX_X_SPEED);
	else
		setXspd(0);
		
	if (keystates[SDLK_SPACE]){
		if (frames >= SHOOT_CD){
			//SDL_Surface* bulletImg = IMG_Load("Resources/bullet1.png");
			//SDL_SetColorKey(bulletImg, SDL_SRCCOLORKEY, SDL_MapRGB(bulletImg->format, 0xFF, 0xFF, 0xFF));
			SDL_Surface* img = IMG_Load("Resources/bullet1.png");
			SolidSprite* bullet = new SolidSprite(getX() + 10, getY() + 10, img, 30, 0, 1, getAttack());
			bullet->setBadGuy(false);
			objectContainer->push_back(bullet);

			//Mix_PlayChannel(-1, shootSound, 0); //Play laser sound while shooting

			frames = 0;
		}
	}
}

void Player::collides(SolidSprite* other){
	//Only check collision against enemies
	if (other->isBadGuy()){
		if (other->getX() < (getX() + getWidth()) && (other->getX() + other->getWidth()) > getX() && (getY() + getHeight()) > other->getY() && getY() < (other->getY() + other->getHeight())) {
			int newHealth = getHealth() - other->getAttack();
			setHealth(newHealth);
		}
	}
	
}