#include "map.h"
#include "game.h"
#include "object.h"

map::map(){
    s1=TextureManager::LoadTexture("asset/s1.png");
    s2=TextureManager::LoadTexture("asset/s2.png");
    s3=TextureManager::LoadTexture("asset/s3.png");
    s4=TextureManager::LoadTexture("asset/died.png");
    src.x=src.y=0;
    src.w=dest.w=32;
    src.h=dest.h=32;
    dest.x=dest.y=0;
    flag=false;
    LoadMap();
}


map::~map(){

}

void map::LoadMap(){
    for (int i = 0; i < 25; i++)
    {
        for (int j = 0; j < 25; j++)
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

void map::endgame(){
    flag=true;
}


void map::DrawMap(){
   for (int i = 0; i < 25; i++)
    {
        dest.x=i*32;
        for (int j = 0; j < 25; j++)
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
        
        if(flag){
                
                for (int i = 0; i < 18; i++)
                {   
                    dest.x=112+i*32;
                    src.x=i*32;
                    for (int j = 0; j < 4; j++)
                    {
                        dest.y=336+j*32;
                        src.y=j*32;
                        TextureManager::Draw(s4,src,dest);
                    }
                    
                }
                
                
            }
    }
}