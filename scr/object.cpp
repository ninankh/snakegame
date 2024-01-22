#include "object.h"
#include "tmanage.h"
#include "game.h"



//generating
void snakebody::init(int direction,snakebody *p,snakebody *n,const char* name,location position){
    dire=direction;
    if (!p)
    {
        pre=p;
    }
    if(!n)
    {
        next=n;
    }
    sBody= TextureManager::LoadTexture(name);
    visible=true;
    pos=position;
}

void snake::init(){
    length=2;
    head = new snakebody(); 
    //tail = new snakebody();
    head->init(0,NULL,tail,"asset/shead.png",{0,0});
    //tail->init(0,head,NULL,"asset/stail.png",{50,50});

}

snakebody::~snakebody(){
    
}

snake::~snake(){
    delete head;
    delete tail;
}


//function about object
location object::getlocation(){
    return pos;
}

void object::update(){
    pos.x++;
    pos.y++;

    srcR.h=32;
    srcR.w=32;
    srcR.x=0;
    srcR.y=0;

    desnR.x=pos.x;
    desnR.y=pos.y;
    desnR.w=srcR.w*2;
    desnR.h=srcR.h*2;
}


//function about snake body
void snakebody::setdirection(int direction){
    dire=direction;
}

int snakebody::getdirection(void){
    return dire;
}

snakebody *snakebody::getpre(void){
    return pre;
}

snakebody *snakebody::getnext(void){
    cout<<"getnext"<<endl;
    return next;
}

void snakebody::setnext(snakebody *n){
    next=n;
}
void snakebody::setpre(snakebody *p){
    pre=p;
}




void snake::sRender(){

    snakebody *temp=head;
    
    
    while (temp!=NULL)
    {   
        temp->renderobj();
        cout<<"render"<<endl;
        temp=temp->getnext();
    }
    
}

void snake::sUpdate(){

    snakebody *temp=head;
    while (temp!=NULL)
    {   
        temp->update();
        cout<<"update"<<endl;
        temp=temp->getnext();
    }

    
}

void snakebody::move(void){
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
}

void snakebody::renderobj(){
    if (visible)
    {
        SDL_RenderCopy(game::Renderer,sBody,NULL,&desnR);
    }
}

//funciton about snake
void snake::growth(){
    snakebody *temp=tail->getpre();
    int newdire=temp->getdirection();
    location pos=temp->getlocation();
    snakebody *nBody;
    nBody->init(newdire,temp,tail,"asset/sbody.png",pos);
    length++;
}

bool snake::eatcoins(object coins){
    location snakepos=head->getlocation();
    location coinpos=coins.getlocation();
    if(snakepos.x==coinpos.x && snakepos.y==coinpos.y) return true;
    else return false;
}

bool snake::died(){
    location snakeheadpos=head->getlocation();
    location snaketailpos=tail->getlocation();
    if (snakeheadpos.x==snaketailpos.x && snakeheadpos.y==snaketailpos.y) return true;
}

void snake::move(int direction){
    int newdire=head->getdirection();
    head->setdirection(direction);
    snakebody *temp=head;
    int tempdire;
    for (int i = 0; i < length; i++)
    {
        temp->move();
        temp=temp->getnext();
        tempdire=temp->getdirection();
        temp->setdirection(newdire);
        newdire=tempdire;
    }
}


//funciton about coins
void coins::disappear(){

}