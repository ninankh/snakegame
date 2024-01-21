#include "game.h"

int main(int argc,const char * argv[]){
    game static *Ngame=new game();
    Ngame->init("Snakegame",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,600,false);
    while(Ngame->getstate()){
        Ngame->handleevent();
        Ngame->update();
        Ngame->render();

    }
    Ngame->clean();
    return 0;
}

