#include "object.h"
#include "tmanage.h"
#include "game.h"



//generating

void snake::init(){
    length=2;
    shead=TextureManager::LoadTexture("asset/shead.png");
    sbody=TextureManager::LoadTexture("asset/sbody.png");
    dead=false;
    change=0;
    srcR.h=32;
    srcR.w=32;
    srcR.x=0;
    srcR.y=0;

    desnR.x=0;
    desnR.y=0;
    desnR.w=srcR.w;
    desnR.h=srcR.h;    

    pos={{512,512},{512,544}};
    dire={0,0};
}



snake::~snake(){

}


//function about object
location object::getlocation(){
    return oPosition;
}


//function about snake body
void snake::sRender(){
    for (int i=0;i<length;i++)
    {
        desnR.x=pos[i].x;
        desnR.y=pos[i].y;
       if(i==0){
            TextureManager::Draw(shead,srcR,desnR);
       }
       else{

            TextureManager::Draw(sbody,srcR,desnR);
            }      
    }/*
            if (desnR.x>32*25) {desnR.x=0; pos[i].x=0;}
            if (desnR.x<-32){desnR.x=32*25; pos[i].x=32*25;}
            if (desnR.y>32*25) {desnR.y=0; pos[i].y=0;}
            if (desnR.y<-32) {desnR.y=32*25; pos[i].y=32*25;}
            TextureManager::Draw(shead,srcR,desnR);
            */ 
}
    

void snake::sUpdate(){
    died();
    if(dead) return;
    static vector<location> tempall=pos;
    static bool flag=false;
    if(pos[0].x%32==0 && pos[0].y%32==0){
    int currentd=dire[0];
    dire.insert(dire.begin(),currentd);
    tempall.insert(tempall.begin(),pos[0]);
    if(grow){
    length++;
    grow=false;}
    else{
    dire.pop_back();
    tempall.pop_back(); 
    }
    
    pos=tempall;
    if(flag){
        switch (change)
    {
    case 0:
        dire[0]=0;
        break;
    case 1:
        dire[0]=1;
        break;
    case 2:
        dire[0]=2;
        break;
    case 3:
        dire[0]=3;
        break;
    default:
        cout<<"error"<<endl;
        break;
    } 
    flag=false;
    }
    }
    if (pos[0].x%32==0  && pos[0].y%32==0)
    {
        flag=changedire();
    }
    
    move();
}

void snake::move(){
    for (size_t i = 0; i < length; i++)
    {
       
    switch (dire[i])
    {
    case 0:
        pos[i].y--;
        break;
    case 1:
        pos[i].y++;
        break;
    case 2:
        pos[i].x--;
        break;
    case 3:
        pos[i].x++;
        break;
    default:
        cout<<"error"<<endl;
        break;
    } 
 }   
}


bool snake::changedire(){
    switch (game::event.key.keysym.sym)
        {
        case SDLK_UP:
            if (dire[0]==1)
            {
                break;
            }
            change=0;
            break;
        case SDLK_DOWN:
            if (dire[0]==0)
            {
                break;
            }
            change=1;
            break;
        case SDLK_LEFT:
            if (dire[0]==3)
            {
                break;
            }
            change=2;
            break;
        case SDLK_RIGHT:
        if (dire[0]==2)
            {
                break;
            }
            change=3;
            break;
        default:
            break;
        }
        if(change!=dire[0]) return true;
        else{return false;}
}



//funciton about snake
void snake::growth(){
    grow=true;
}

bool snake::eatcoins(coins c){
    location temp=c.getlocation();
    bool flag;
    if(pos[0].x==temp.x && temp.y==pos[0].y) flag=true;
    else{flag=false;}
    return flag;
}

void snake::died(){
    location temp=pos[0];
    if(temp.x<-30 || temp.y<-30 || temp.x>32*25+10 || temp.y>32*25+10)  dead=true;
    for (int i = 2; i < length; i++)
    {
        if( length>=2 && temp.x==pos[i].x && temp.y ==pos[i].y) dead= true;
    }
    
}

bool snake::getstate(){
    return dead;
}
//funciton about coins

coins::coins(){
    sBody=TextureManager::LoadTexture("asset/coins.png");
    srcR.h=32;
    srcR.w=32;
    srcR.x=0;
    srcR.y=0;
    desnR.w=srcR.w;
    desnR.h=srcR.h;
    oPosition.x=rand()%25;
    oPosition.y=rand()%25;
    desnR.x=move.x=oPosition.x*32;
    desnR.y=move.y=oPosition.y*32;

}

coins::~coins(){

}

void coins::refresh(){
    oPosition.x=rand()%25;
    oPosition.y=rand()%25;
    desnR.x=move.x=oPosition.x*32;
    desnR.y=move.y=oPosition.y*32;
}

void coins::cRender(){
    TextureManager::Draw(sBody,srcR,desnR);
}

void coins::cupdate(){
    static int flag=0;
    if((desnR.y -move.y <=3) && flag==0) {
        desnR.y++;
    }
    else {
        if(desnR.y -move.y>=-3){
        flag=1;
        desnR.y--;
        }
        else{
            flag=0;
    }
    }
}

location coins::getlocation(){
    return move;
}