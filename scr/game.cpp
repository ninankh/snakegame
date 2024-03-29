#include "game.h"



game::game(){}

game::~game(){}

SDL_Renderer* game::Renderer=nullptr;
SDL_Event game::event;



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
		player.init();
		Coin=new coins();
		background=new map();
		cout<<"init sucessfully"<<endl;
	}
	else{
		isrunning=false;
	}
}


void game::handleevent(){
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
	static bool flag=false;
	if (player.getstate())
	{
		background->endgame();
	}
	else{
	flag=player.eatcoins(*Coin);
	player.sUpdate();
	Coin->cupdate();
	if(flag) {cout<<"yes"<<endl;Coin->refresh(); player.growth();}
	}	
}

void game::render(){
	SDL_RenderClear(Renderer);
	background->DrawMap();
	player.sRender();
	Coin->cRender();
	SDL_RenderPresent(Renderer);
}

void game::clean(){
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(Renderer);
	SDL_Quit();
}