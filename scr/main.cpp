#include "game.h"
#include "object.h"


int main(int argc,const char * argv[]){
    const int FPS=60;
    const int frameDelay= 1000/FPS;
    Uint32 frameStart;
    int frameTime;
    game static *Ngame=new game();
    Ngame->init("Snakegame",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,600,false);
    while(Ngame->getstate()){
        frameStart=SDL_GetTicks();

        Ngame->handleevent();
        Ngame->update();
        Ngame->render();

        frameTime=SDL_GetTicks()-frameStart;
        if(frameDelay>frameTime){
            SDL_Delay(frameDelay-frameTime);
        }
    }
    Ngame->clean();
    return 0;
}

