#include "GUI.h"


GUI::GUI(Player* player)
{
	this->player = player;
	font = TTF_OpenFont("c:\\WINDOWS\\Fonts\\arial.ttf", 36);
	color = { 255, 255, 255 };
}


GUI::~GUI()
{
}

void GUI::update(){
		//text += "Health: " + player->getHealth();
	
	textStream.str("");
	textStream << "Health: " << player->getHealth() << "   Armor: " << player->getArmor();
		
}

void GUI::draw(SDL_Surface& screen){
		SDL_FreeSurface(textSurface); //Remove old text
		textSurface = TTF_RenderText_Blended(font, textStream.str().c_str(), color);
		SDL_Rect offset;
		offset.x = 100; offset.y = 100;
		SDL_BlitSurface(textSurface, NULL, &screen, &offset);
}