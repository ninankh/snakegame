#ifndef ADDCOMP_H
#define ADDCOMP_H

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

class Component;
class Entity;

using ComponentID = std::size_t;

inline ComponentID getComponentTypeID()
{
    static ComponentID lastID =0;
    return lastID++;

}

template <typename> inline ComponentID getComponentTypeID() noexcept{
    static ComponentID typeid =getComponentTypeID();
    return typeid();
}

constexpr std::size_t maxComponents =32;


using ComponentBitSet=std::bitset<maxComponents>;
using ComponentArray = std::array<Component*,maxComponents>;

class Component
{
private:
    /* data */
public:
    virtual ~Component();
    Entity* entity;
    virtual void init(){}
    virtual void update(){}
    virtual void draw(){}


};

class Entity
{
private:
    bool active;
    std::vector<std::unique_ptr<Component>> component;

    ComponentArray ComponentArray;
    ComponentBitSet ComponentBitSet;
public:
    void update();
    void draw(){}
    bool isActive() const{return active;}
    void destroy() {active =false;}

    template <typename T> bool hasComponent() const
    {
        return ComponentBitSet[getComponentID<T>];
    }

    template <typename T,typename... TArgs>
    T& addComponent(TArgs&&... mArgs)
    {
        T* C(new T(std::forward<Targs>(mArgs)...));
        c->entity=this;
        std::unique_ptr<Component> uPtr{ c };
        component.emplace_back(std::move(uPtr));

        ComponentArray[getComponentTypeID<T>()]=c;
        ComponentBitSet[getComponentTypeID<T>()=true];

        c->init();
        return *c;
    }
};



#endif