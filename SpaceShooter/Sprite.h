#ifndef SPRITE_H
#define SPRITE_H

#include "SDL.h"
#include "SDL_image.h"
#include <string>


class Sprite{

public:
	Sprite(int xx, int yy, SDL_Surface* img);
	virtual ~Sprite(void);

	virtual void draw(SDL_Surface* surface);
	virtual void update() =0;
	
	//Getters
	SDL_Surface* getImage();
	int getXspd();
	int getYspd();
	int getX();
	int getY();
	int getHeight();
	int getWidth();

	//Setters
	void setXspd(int value);
	void setYspd(int value);
	void setX(int value);
	void setY(int value);

private:
	SDL_Surface* loadImage(std::string filename);
	int x;
	int y;
	int xSpeed = 0;
	int ySpeed = 0;
	SDL_Surface* image;

};

#endif