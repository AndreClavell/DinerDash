//
// Created by joshu on 11/4/2020.
//

#ifndef APGAMEENGINE_BURGER_H
#define APGAMEENGINE_BURGER_H
#pragma once
#include "Item.h"
#include "Entity.h"


class Burger {
private:
    int x,y,width,height;
 stack<Item*> ingredients;
 stack<Item*> temp;
 int amount = 0;
 int counter = 1;
 int found=0;
 


public:
    Burger(int, int, int, int);
    void addIngredient(Item *item);
    void removeIngredient();
    int ingredientAmount();
    void render();
    void clear();
    void setY(int y){
        this->y = y;
    }
    void setX(int x){
        this->x = x;
    }
    bool equals(Burger* b);
    stack<Item*> getIngredientsStack(){
        return ingredients;
    }
};


#endif //APGAMEENGINE_BURGER_H
