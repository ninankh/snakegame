#ifndef GAME_H
#define GAME_H
#include "object.h"
#include <SDL2/SDL.h>

class game{
    public:
    game();
    ~game();
    void init(const char* title="snakegame",int xpos,int ypos,int width, int height, bool fullscreen=false);
    void update();
    void render();
    void clean();
    
    private:
    SDL_Window *window;
    SDL_Renderer *Renderer;



};

#endif