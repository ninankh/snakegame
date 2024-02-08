#ifndef MAP_H
#define MAP_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


class map{
    public:

    map();
    ~map();

    void LoadMap();
    void DrawMap();
    void endgame();
    private:
    bool flag;
    SDL_Rect src,dest;
    SDL_Texture *s1;
    SDL_Texture *s2;
    SDL_Texture *s3;
    SDL_Texture *s4;
    int all[50][50];


};

#endif