#include "object.h"
#include "tmanage.h"
#include "game.h"



//generating

void snake::init(){
    length=2;
    shead=TextureManager::LoadTexture("asset/shead.png");
    stail=TextureManager::LoadTexture("asset/stail.png");
    sbody=TextureManager::LoadTexture("asset/sbody.png");
    srcR.h=32;
    srcR.w=32;
    srcR.x=0;
    srcR.y=0;

    desnR.x=0;
    desnR.y=0;
    desnR.w=srcR.w*2/3;
    desnR.h=srcR.h*2/3;

    HdesnR.x=0;
    HdesnR.y=0;
    HdesnR.w=srcR.w;
    HdesnR.h=srcR.h;
    

    pos={{0,0},{5,31}};
    dire={0,0};
}



snake::~snake(){

}


//function about object
location object::getlocation(){
    return oPosition;
}

void object::update(){
    oPosition.x++;
    oPosition.y++;

    srcR.h=32;
    srcR.w=32;
    srcR.x=0;
    srcR.y=0;

    desnR.x=oPosition.x;
    desnR.y=oPosition.y;
    desnR.w=srcR.w*2;
    desnR.h=srcR.h*2;
}


//function about snake body
void snake::sRender(){
    for (int i=1;i<=length;i++)
    {
        desnR.x=pos[i-1].x;
        desnR.y=pos[i-1].y;
        cout<<"Render"<<endl;
       if(i==1){
            HdesnR.x=pos[0].x;
            HdesnR.y=pos[0].y;
            TextureManager::Draw(shead,srcR,HdesnR);
       }
       else{
        if (i==length)
        {
            TextureManager::Draw(stail,srcR,desnR);
        }
        else{
            TextureManager::Draw(sbody,srcR,desnR);
        }
       }      

    }
}
    

void snake::sUpdate(){
/*
    switch (dire)
    {
    case 0:
        //move upward;
        break;
    case 1:
        //move downward;
        break;
    case 2:
        //move left;
        break;
    case 3:
        //move right;
        break;
    default:
        cout<<"error"<<endl;
        break;
    } 
    */
   //if(move)
   location temp;
   for (int i = 0; i < length; i++)
   {
    pos[i].x++;
    pos[i].y++;
   }
}


//funciton about snake
void snake::growth(){
    location temppos=pos[length-1];
    pos.insert(pos.end(),temppos);
    int tempdire=dire[length-1];
    dire.insert(dire.end(),tempdire);
    length++;
}

bool snake::eatcoins(object coins){
    location temp=coins.getlocation();
    if(pos[0].x==temp.x && pos[length-1].y==temp.y) return true;
    else return false;
}

bool snake::died(){
    if (pos[0].x==pos[length-1].x && pos[0].y==pos[length-1].y) return true;
    else{return false;}
}


//funciton about coins
void coins::disappear(){

}