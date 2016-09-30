#pragma once
#include "Player.h"
#include "SDL_ttf.h"
#include <sstream>

class GUI
{
public:
	GUI(Player* player);
	~GUI();
	void update();
	void draw(SDL_Surface& screen);

	TTF_Font* font;
	SDL_Color color;
	SDL_Surface* textSurface;
	std::stringstream textStream;
	Player* player;
	int prevHealth = -1; //The last checked health value
	int prevArmor = -1;
	bool changed = false;
};

