#include "GameScreen.h"
#include <iostream>
#include "StartScreen.h"
#include "GameOverScreen.h"
#include "Rock.h"
#include "ZigZagEnemy.h"
#include "StalkerEnemy.h"
#include "MirrorShooter.h"
#include "Bomber.h"

using namespace std;

GameScreen::GameScreen()
{
	//SDL_Surface* loadImage(std::string filename);

	std::cout << "Create GameScreen" << std::endl;
	
	//Background
	SDL_Surface* spaceBg = IMG_Load("Resources/poorSpace.png");
	bg = new Background(0, 0, spaceBg);
	
	//Player ship
	SDL_Surface* shipImg = IMG_Load("Resources/paintShip.png");
	//SDL_SetColorKey(ship, SDL_SRCCOLORKEY, SDL_MapRGB(ship->format, 0xFF, 0xFF, 0xFF));
	player1 = new Player(100,500, SCREEN_WIDTH, SCREEN_HEIGHT, shipImg);
	friendlyObjects.push_back(player1);

	//GUI
	gui = new GUI(player1);

	//Music
	music = Mix_LoadMUS("Resources/Saturnine.wav");
	Mix_PlayMusic(music, -1);

	//spawner = new Spawner(enemies, player1);
}

//TODO
GameScreen::~GameScreen(){

	Mix_FreeMusic(music);
	delete bg;

	//Delete all objects
	for (SolidSprite* obj : friendlyObjects)
		delete obj;

	for (SolidSprite* obj : enemies)
		delete obj;
}

void GameScreen::handle_events(){
	SDL_Event event;
	//Ignore if there're more than 1 event
	while(SDL_PollEvent(&event)){
		if (event.type == SDL_QUIT){
			exit = true;
		}
		else if(event.type == SDL_KEYDOWN){
			switch (event.key.keysym.sym){
			case SDLK_p:
				pause(); 
				break;

			//U: Spawn enemies
			case SDLK_1:
				enemies.push_back(new Rock(1400, 300));
				enemies.push_back(new Rock(1400, 400));
				enemies.push_back(new Rock(1400, 100));
				break;
			case SDLK_2:
				enemies.push_back(new ZigZagEnemy(1300, 700));
				enemies.push_back(new ZigZagEnemy(1300, 100));
				break;
			case SDLK_3:
				enemies.push_back(new MirrorShooter(1200, 700, player1, &enemies));
				break;
			case SDLK_4:
				enemies.push_back(new Bomber(1300, 800, player1, &enemies));
				break;
			//Toggle invincible-mode
			case SDLK_i:
				if (player1->getArmor() > 5000){
					player1->setArmor(0);
					player1->setAttack(0);
					cout << "[CHEAT] INVINCIBLE MODE OFF" << endl;
				}
				else{
					player1->setArmor(5001);
					player1->setAttack(1);
					cout << "[CHEAT] INVINCIBLE MODE ON" << endl;
				}
				break;

			//Restart the game
			case SDLK_ESCAPE:
				nextState = new StartScreen();
				break;
			}
		}
	}

	player1->handleInput(&friendlyObjects);
}

//Update all game objects
void GameScreen::logic(){
	//spawner->spawn();
	
	check_collisions();
	bg->update();
	gui->update();

	for (Sprite *obj : friendlyObjects){
		obj->update();
	}

	//WARNING: objects can be created here, invalidating iterators.
	for (unsigned int i = 0; i < enemies.size(); i++)
		enemies[i]->update();

	removeDead();

	//Go to game over screen If the player dies 
	if (player1->getHealth() <= 0)
		nextState = new GameOverScreen();
}

//Render all game objects
void GameScreen::render(SDL_Surface* gameScreen){
	//SDL_FreeSurface(gameScreen);
	bg->draw(gameScreen);
	gui->draw(*gameScreen);

	for (Sprite *obj : friendlyObjects){
		obj->draw(gameScreen);
	}

	for (Sprite *obj : enemies){
		obj->draw(gameScreen);
	}

	SDL_Flip(gameScreen);
}

//pause until 'p'-key is pressed
void GameScreen::pause(){
	SDL_Event event;

	while (true){

		if (SDL_PollEvent(&event)){
			if (event.key.keysym.sym == SDLK_p && event.type == SDL_KEYDOWN){
				break;
			}
		}
	}
}

//Check collision for all objects and do damage to both if collided
void GameScreen::check_collisions(){
	for (SolidSprite* friendly : friendlyObjects){
		for (SolidSprite* enemy : enemies){
			if (has_collided(friendly, enemy)){
				friendly->attack(enemy);
				enemy->attack(friendly);
				friendly->onCollision();
				enemy->onCollision();
				cout << "[GAME LOGIC]: Collision!" << "; BETWEEN: A: " << friendly << " B: " << enemy << "HEALTH(A,B):" << friendly->getHealth() <<"," << enemy->getHealth() << endl;
			}
			
		}
	}
}
bool GameScreen::has_collided(SolidSprite *a, SolidSprite *b){
	
		//if the hitboxes overlap return true     
		if (a->getX() < (b->getX() + b->getWidth()) && (a->getX() + a->getWidth()) > b->getX() && (b->getY() + b->getHeight()) > a->getY() && b->getY() < (a->getY() + a->getHeight())){
			return true;
		}
		else{
			return false;
		}
	

	
}

// Remove objects that are dead. TODO: Can I use shared pointers here???
void GameScreen::removeDead(){
	//Check for dead good guys
	for (unsigned i = 0; i < friendlyObjects.size(); i++){
		if (friendlyObjects[i]->isDead()){
			delete friendlyObjects[i];
			friendlyObjects.erase(friendlyObjects.begin() + i);
		}
	}
	//Check for dead bad guys
	for (unsigned i = 0; i < enemies.size(); i++){
		if (enemies[i]->isDead()){
			delete enemies[i];
			enemies.erase(enemies.begin() + i);
		}
	}
}

SDL_Surface* loadImage(std::string filename){
	SDL_Surface* temp = IMG_Load(filename.c_str());
	if (temp == NULL)
		std::cerr << "failed to load from " << filename << std::endl;

	//SDL_SetColorKey(temp, SDL_SRCCOLORKEY, SDL_MapRGB(temp->format, 0xFF, 0xFF, 0xFF));
	SDL_Surface* optimized = SDL_DisplayFormat(temp);
	return optimized;
}