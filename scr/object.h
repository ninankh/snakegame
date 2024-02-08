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

/*class PositionComponent : public Component
{
    private:
    float xpos=0;
    float ypos=0;
    public:
    
    int x(){ return xpos;}
    int y(){ return ypos;}

    void update() override
    {
        xpos++;
        ypos++;
    }

    void setpos(float x, float y){
        xpos=x;
        ypos=y;
    }
};
*/

class object{
    public:
    object(){
        location oPosition={0,0};
    }
    virtual location getlocation();
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
    bool changedire();
    void growth();
    bool eatcoins(object coins);
    void move();
    bool died();
    private:
    int change;
    SDL_Texture *shead;
    SDL_Texture *stail;
    SDL_Texture *sbody;
    SDL_Texture *tLeft;
    SDL_Texture *tRight;
    int length;
    vector<location> pos;
    vector<int> dire;
    SDL_Rect HdesnR;
};


class coins:object{
private:
    location move;
public:
    coins();
    ~coins();
    void refresh();
    void cRender();
    void cupdate();
};



#endif