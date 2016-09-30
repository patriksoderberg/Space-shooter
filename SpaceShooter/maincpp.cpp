#include "SDL.h" 
#include "SDL_image.h"
using namespace std;
int main( int argc, char* args[] ) { 
	
	SDL_Surface* hello = NULL; 
	SDL_Surface* screen = NULL;
	
	//Start SDL. Returnerar -1 vid fel.
	SDL_Init(SDL_INIT_EVERYTHING);

	screen = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE);
	SDL_WM_SetCaption("Hhhehehe", NULL);
	hello = IMG_Load("hehe.jpg");
		
	
	
	SDL_BlitSurface(hello, NULL, screen, NULL);
	//Update Screen 
	SDL_Flip( screen ); 
	//Pause 
	SDL_Delay(2000);
	SDL_FreeSurface(hello);
	//Quit SDL 
	SDL_Quit(); 
	return 0; 
}