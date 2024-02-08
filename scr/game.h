#ifndef GAME_H
#define GAME_H
#include "object.h"
#include "tmanage.h"
#include "map.h"
#include <iostream>
#include <stdio.h>
using namespace std;


class game{
    public:
    game();
    ~game();
    void init(const char* title,int xpos,int ypos,int width, int height, bool fullscreen);
    void handleevent();
    void update();
    void render();
    void clean();
    bool getstate();
    static SDL_Renderer *Renderer;
    static SDL_Event event;
    private:
    coins *Coin;
    map *background;
    int timecount;
    snake player;
    SDL_Window *window;
    bool isrunning;

};

#endif