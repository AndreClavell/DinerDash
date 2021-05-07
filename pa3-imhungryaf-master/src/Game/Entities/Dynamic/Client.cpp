#include "Client.h"

Client::Client(int x, int y, int width, int height, ofImage sprite, Burger *burger) : Entity(x, y, width, height, sprite)
{
    this->burger = burger;
   
}

Client::~Client()
{
    burger->~Burger();
}
void Client::render()
{
    timer++;
    ofSetColor(255, 255, 255);
    burger->render();
    if (nextClient != nullptr)
    {
        nextClient->render();
    }

  
    if (patience <= 2000 && patience > 1000)
    {
        ofSetColor(255, 100, 100);
    }
    else if (patience <= 1000 && patience > 500)
    {
        ofSetColor(255, 50, 50);
    }
    else if (patience <= 500)
    {
        ofSetColor(255, 0, 0);
    }

    // ofDrawRectangle(getBounds()); 
    if(!this->beenServed){
        sprite.draw(x, y, width, height);
    }
    
}

void Client::tick()
{
    patience--;
    if(!this->beenServed){
    
        burger->setY(y);
    }
    
    if (patience == 0)
    {
        isLeaving = true;
    }
    if (nextClient != nullptr)
    {
        nextClient->tick();
    }
}

int Client::serve(Burger *chefBurger,bool activated)
{
    if (nextClient != nullptr && isLeaving == false)
    {
        if (this->getBurgy()->equals(chefBurger) == true)
        {
            isLeaving = true;
            if(activated){
                beenServed=true;
            }
            return 10 + nextClient->serve(chefBurger,activated);
        }
        else
        {
            return 0 + nextClient->serve(chefBurger,activated);
        }
    }
    else if (nextClient != nullptr && isLeaving == true)
    {
        return 0 + nextClient->serve(chefBurger,activated);
    }
    else if (nextClient == nullptr && isLeaving == false)
    {
        if (this->getBurgy()->equals(chefBurger) == true)
        {
            isLeaving = true;
            if(activated){
                beenServed=true;
            }
            return 10;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}
//Bonus
void Client::sitDown(int s)
{
    if(s>=6){
        s=1;
    }
    if (this->isLeaving && this->beenServed)
    {

        sprite.draw(188, (76 * s), width, height);
        this->getBurgy()->setX(240);
        this->getBurgy()->setY((72 * s));

        if (timer % 3500 == 0)
        {
            timer = 0;
            this->beenServed = false;
        }
    }
    if (nextClient != nullptr && this->beenServed)
    {
        nextClient->sitDown(s+1);
    }else if(nextClient!=nullptr && !this->beenServed){
        nextClient->sitDown(s);
    }
    
}
