#include "Sprite.h"
#include <iostream>

/*
Sprite::Sprite(int xx, int yy, std::string filename){
	x = xx;
	y = yy;
	image = loadImage(filename);
}
*/

Sprite::Sprite(int xx, int yy, SDL_Surface* img){
	x = xx;
	y = yy;
	//SDL_SetColorKey(img, SDL_SRCCOLORKEY, SDL_MapRGB(img->format, 0xFF, 0xFF, 0xFF));
	image = SDL_DisplayFormat(img);
}


Sprite::~Sprite(void){
	std::cout << "remove object" << std::endl;
	SDL_FreeSurface(image);
}

void Sprite::draw(SDL_Surface* surface){
	SDL_Rect offset;
	offset.x = x; offset.y = y;
	SDL_BlitSurface(image, NULL, surface, &offset);
};
/*
void Sprite::update(){
}

*/
int Sprite::getX(){return x;};
int Sprite::getY(){ return y; };

void Sprite::setX(int value){
	x = value;
}

void Sprite::setY(int value){
	y = value;
}

SDL_Surface* Sprite::getImage(){
	return image;
};
int Sprite::getXspd(){
	return xSpeed;
};
int Sprite::getYspd(){
	return ySpeed;
};

void Sprite::setXspd(int value){
	xSpeed = value;
}

void Sprite::setYspd(int value){
	ySpeed = value;
}

int Sprite::getHeight(){
	return image->h;
}
int Sprite::getWidth(){
	return image->w;
}

SDL_Surface* Sprite::loadImage(std::string filename){

	SDL_Surface* temp = IMG_Load(filename.c_str());
	if (temp == NULL)
		std::cerr << "failed to load from " << filename << std::endl;

	SDL_SetColorKey(temp, SDL_SRCCOLORKEY, SDL_MapRGB(temp->format, 0xFF, 0xFF, 0xFF));
	SDL_Surface* optimized = SDL_DisplayFormat(temp);
	return optimized;
}