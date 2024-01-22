#ifndef TMANAGE_H
#define TMANAGE_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class TextureManager{

    public:
        static SDL_Texture *LoadTexture(const char *filename);
        static  void Draw(SDL_Texture *text,SDL_Rect src, SDL_Rect dest);
};

#endif