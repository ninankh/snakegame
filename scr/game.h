#ifndef GAME_H
#define GAME_H
#include "object.h"
#include <iostream>
#include <SDL2/SDL.h>
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
    private:
    int timecount;
    SDL_Window *window;
    SDL_Renderer *Renderer;
    bool isrunning;



};

#endif