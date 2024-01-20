#include <iostream>
#include "object.h"
using namespace std;

//generating
snakebody::snakebody(int direction,snakebody *p,snakebody *n){
    dire=direction;
    pre=p;
    next=n;
}

snake::~snake(void){
   // delete[] parts;
}




//function about object
location object::getlocation(){
    return pos;
}

//function about snake body
void snakebody::setdirection(int direction){
    dire=direction;
}

snakebody *snakebody::getpre(void){
    return pre;
}

snakebody *snakebody::getnext(void){
    return next;
}

void snakebody::setnext(snakebody *n){
    next=n;
}
void snakebody::setpre(snakebody *p){
    pre=p;
}

int snakebody::getdirection(void){
    return dire;
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

//funciton about snake
void snake::growth(bool flag){
    int newdire=0;
    snakebody *p=NULL;
    if(tail==NULL){
        int newdire=head->getdirection();
        snakebody *p=head;
    }
    else{
        int newdire=tail->getdirection();
        snakebody *p=tail;
    }
    tail=new snakebody(newdire,p);
    p->setnext(tail);
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