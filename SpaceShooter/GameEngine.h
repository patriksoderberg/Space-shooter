#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "SDL.h"
#include <vector>
#include <list>
#include "Sprite.h"
#include "player.h"
#include "Timer.h"
#include "SDL_ttf.h"
#include <string> 
#include <sstream>
#include "MyTimer.h"
#include <SDL_mixer.h>
#include "StartScreen.h"

class GameEngine{
public:
	GameEngine(int width, int height);
	void run();
	
private:
	const int SCREEN_WIDTH = 1280;
	const int SCREEN_HEIGHT = 720;

	const int MAX_FPS = 60; //60 
	const int TICKS_PER_FRAME = 1000 / MAX_FPS;
	//double currentFPS;
	int width;
	int height;
	SDL_Surface* gameScreen; //= SDL_SetVideoMode(width, height, 32, SDL_SWSURFACE); //640, 480, 32 SDL_SWSURFACE
	GameState *currentState; //Stores the current state of the game

	//functions
	void change_state(); 
	void cleanup();
	void init();
	void draw();
	void update();
	void pause();
	void handleInput();
	
};
#endif