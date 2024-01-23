#include "addcomp.h"


void Entity::update(){
        for(auto& c: component) c->update();
        for(auto& c: component) c->draw();    
}

