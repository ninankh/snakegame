#ifndef OBJECT_H
#define OBJECT_H
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
using namespace std;
typedef struct location
{
     int x,y;
};

class object{
    public:
    object(){
        location pos={0,0};
    }
    virtual void renderobj(){};
    virtual location getlocation();
    virtual void update();
    protected:
    location pos;
    bool visible;
    SDL_Texture *sBody;
    SDL_Rect srcR,desnR;
};

class snakebody:public object{
    public:
    snakebody(){
        dire=0;
        sBody=NULL;

    };
    ~snakebody();
    void init(int direction,snakebody *pre,snakebody *next,const char* filename,location pos);
    void move();
    void setdirection(int direction);
    int getdirection();
    snakebody *getnext();
    snakebody *getpre();
    void setnext(snakebody *n);
    void setpre(snakebody *p);
    void renderobj();
    private:
    int dire;
    snakebody *pre;
    snakebody *next;
};


class snake{
    public:
    snake(){};
    ~snake(void);
    void init();
    void sRender();
    void sUpdate();
    void growth();
    bool eatcoins(object coins);
    void move(int direction);
    bool died();
    private:
    snakebody *head;
    snakebody *tail;
    int length;
};


class coins:object{
private:

public:
    coins();
    ~coins();
    void disappear();
};



#endif