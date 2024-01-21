#ifndef OBJECT_H
#define OBJECT_H
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
    virtual location getlocation();
    protected:
    location pos;
    object *pre;
    object *next;
};

class snakebody:public object{
    public:
    snakebody(int direction=0,snakebody *pre=nullptr,snakebody *next=nullptr);
    ~snakebody();
    void move();
    void setdirection(int direction);
    int getdirection();
    snakebody *getnext();
    snakebody *getpre();
    void setnext(snakebody *n);
    void setpre(snakebody *p);
    private:
    int dire;
    snakebody *pre;
    snakebody *next;
};


class snake{
    public:
    snake()
    {
        int length=1;
        snakebody head();
        tail=nullptr;
    }
    ~snake(void);
    void growth(bool flag);
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