#include "map.h"
#include "game.h"
#include "object.h"

map::map(){
    s1=TextureManager::LoadTexture("asset/s1.png");
    s2=TextureManager::LoadTexture("asset/s2.png");
    src.x=src.y=0;
    src.w=dest.w=32;
    src.h=dest.h=32;
    dest.x=dest.y=0;
    TextureManager::Draw(s1,src,dest);
    TextureManager::Draw(s2,src,dest);
    LoadMap();
}


map::~map(){

}

void map::LoadMap(){
    for (int i = 0; i < 50; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            if ((i%2==0 && j%2!=0) || (i%2!=0 && j%2==0))
            {
                all[i][j]=0;
            }
            else{
                all[i][j]=1;
            }
        }
    }
    

}

void map::DrawMap(){
   for (int i = 0; i < 50; i++)
    {
        dest.x=i*32;
        for (int j = 0; j < 50; j++)
        {
            dest.y=j*32;
            switch (all[i][j])
            {   
            case 0:
                TextureManager::Draw(s1,src,dest);
                break;
            case 1:
                TextureManager::Draw(s2,src,dest);
                break;
            default:
                break;
            }
            
        }
        
    }
}