#include <stdio.h>
#include "game.h"


game::game(){}

game::~game(){}

void game::init(const char* title,int xpos,int ypos,int width, int height, bool fullscreen){
	int flags=0;
	if(fullscreen) flags=SDL_WINDOW_FULLSCREEN;
	if(SDL_Init(SDL_INIT_EVERYTHING)==0){

		window=SDL_CreateWindow(title,xpos,ypos,width,height,flags);
		if(!window)
		{
			cout<<"error"<<endl;
		}
		timecount=0;
		Renderer=SDL_CreateRenderer(window,-1,0);
		if(Renderer){
			SDL_SetRenderDrawColor(Renderer,255,255,255,255);
		}
		else{cout<<"error"<<endl;}
		isrunning=true;
	}
	else{
		isrunning=false;
	}
}


void game::handleevent(){
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		isrunning=false;
		break;

	default:
		break;
	}
}

bool game::getstate(){
	return isrunning;
}
void game::update(){
	timecount++;
}

void game::render(){
	SDL_RenderClear(Renderer);
	SDL_RenderPresent(Renderer);
}

void game::clean(){
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(Renderer);
	SDL_Quit();
}