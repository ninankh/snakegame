#include "object.h"
#include "tmanage.h"
#include "game.h"



//generating

void snake::init(){
    length=2;
    shead=TextureManager::LoadTexture("asset/shead.png");
    stail=TextureManager::LoadTexture("asset/stail.png");
    sbody=TextureManager::LoadTexture("asset/sbody.png");
    tLeft=TextureManager::LoadTexture("asset/left.png");
    tRight=TextureManager::LoadTexture("asset/right.png");
    change=0;
    srcR.h=32;
    srcR.w=32;
    srcR.x=0;
    srcR.y=0;

    desnR.x=0;
    desnR.y=0;
    desnR.w=srcR.w;
    desnR.h=srcR.h;

    HdesnR.x=0;
    HdesnR.y=0;
    HdesnR.w=srcR.w;
    HdesnR.h=srcR.h;
    

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
    HdesnR.x=pos[0].x;
    HdesnR.y=pos[0].y;
    for (int i=1;i<=length;i++)
    {
        desnR.x=pos[i-1].x;
        desnR.y=pos[i-1].y;
       if(i==1){
            TextureManager::Draw(shead,srcR,HdesnR);
            if(HdesnR.x>32*25 || HdesnR.y>32*25) {
                if (HdesnR.x>32*2) {HdesnR.x=0; pos[0].x=0;}
                if (HdesnR.y>32*2) {HdesnR.y=0; pos[0].y=0;}
                TextureManager::Draw(shead,srcR,HdesnR);
            }
       }
       else{
        if (i==length)
        {
            TextureManager::Draw(stail,srcR,desnR);
            if(desnR.x>32*25 || desnR.y>32*25) {
                if (desnR.x>32*2) {desnR.x=0; pos[i-1].x=0;}
                if (desnR.y>32*2) {desnR.y=0; pos[i-1].y=0;}
                TextureManager::Draw(shead,srcR,desnR);
            }
        }
        else{
            TextureManager::Draw(sbody,srcR,desnR);
            if(desnR.x>32*25 || desnR.y>32*25) {
                if (desnR.x>32*2) {desnR.x=0; pos[i-1].x=0;}
                if (desnR.y>32*2) {desnR.y=0; pos[i-1].y=0;}
                TextureManager::Draw(shead,srcR,desnR);
            }
        }
       }      

    }
}
    

void snake::sUpdate(){
    static vector<location> tempall=pos;
    static bool flag=false;
    if(pos[0].x%32==0 && pos[0].y%32==0){
    int currentd=dire[0];
    dire.insert(dire.begin(),currentd);
    dire.pop_back();
    tempall.insert(tempall.begin(),pos[0]);
    tempall.pop_back();
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
        cout<<desnR.y<<move.y<<endl;
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