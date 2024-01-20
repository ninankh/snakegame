#include <stdio.h>
#include "game.h"


game::game(){}

game::~game(){}

void game::init(const char* title,int xpos,int ypos,int width, int height, bool fullscreen){
	int flags=0;
	if(fullscreen) flags=SDL_WINDOW_FULLSCREEN;
	if(SDL_Init(SDL_INIT_EVERYTHING)==0){

		window=SDL_CreateWindow(title,xpos,ypos,width,height,flags);
	}
}
