#include "tmanage.h"
#include "game.h"

SDL_Texture *TextureManager::LoadTexture(const char *texture){
    SDL_Surface *tempsur=IMG_Load(texture);
    SDL_Texture *nTexture=SDL_CreateTextureFromSurface(game::Renderer,tempsur);
    SDL_FreeSurface(tempsur);
    return nTexture;
}


void TextureManager::Draw(SDL_Texture *text,SDL_Rect src, SDL_Rect dest){
    SDL_RenderCopy(game::Renderer,text,&src,&dest);
}


enum KeyPressSurfaces
{
    KEY_PRESS_SURFACE_DEFAULT,
    KEY_PRESS_SURFACE_UP,
    KEY_PRESS_SURFACE_DOWN,
    KEY_PRESS_SURFACE_LEFT,
    KEY_PRESS_SURFACE_RIGHT,
    KEY_PRESS_SURFACE_TOTAL
};