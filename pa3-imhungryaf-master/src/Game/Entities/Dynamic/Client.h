#pragma once
#include "Entity.h"
#include "Burger.h"

class Client : public Entity
{
private:
    Burger *burger;
    int originalPatience;
    int patience = 4000;
    int timer=0;
    
   
public:

    Client(int, int, int, int, ofImage, Burger *);
    ~Client();
    void tick();
    void render();
    int getPatience() { return patience; }
    int serve(Burger *chefBurger,bool activated);
    Client *nextClient = nullptr;
    bool isLeaving = false;
    bool beenServed=false;
    Burger* getBurgy(){return burger;};
    void sitDown(int s);
    
};