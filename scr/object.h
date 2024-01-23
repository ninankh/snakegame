#ifndef OBJECT_H
#define OBJECT_H
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
using namespace std;
typedef struct location
{
     int x,y;
};

class object{
    public:
    object(){
        location oPosition={0,0};
    }
    virtual void renderobj(){};
    virtual location getlocation();
    virtual void update();
    protected:
    location oPosition;
    bool visible;
    SDL_Texture *sBody;
    SDL_Rect srcR,desnR;
};


class snake:object{
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
    SDL_Texture *shead;
    SDL_Texture *stail;
    SDL_Texture *sbody;
    int length;
    vector<location> pos;
    vector<int> dire;
    SDL_Rect HdesnR;
};


class coins:object{
private:

public:
    coins();
    ~coins();
    void disappear();
};



#endif