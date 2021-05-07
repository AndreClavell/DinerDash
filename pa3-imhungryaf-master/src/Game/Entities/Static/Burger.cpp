//
// Created by joshu on 11/4/2020.
//

#include "Burger.h"

Burger::Burger(int x, int y, int width, int height){
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}
 
void Burger::addIngredient(Item *item) {
    ingredients.push(item);
    amount++;
}
void Burger::removeIngredient(){
    ingredients.pop();
    amount--;
}
int Burger::ingredientAmount(){
    return amount;
}

void Burger::render(){
    counter = 1;
    for (int i = -(ingredients.size()); i < 0; i++)
    {
        temp.push(ingredients.top());
        ingredients.pop();
        
    }
    for (int i = -(temp.size()); i < 0; i++)
    {
        if (temp.top()->name == "patty")
        {
            ofSetColor(180);
        }
        else
        {
            ofSetColor(255);
        }
        temp.top()->sprite.draw(x, y - (counter * 10) + 32, width, height);
        ingredients.push(temp.top());
        temp.pop();
        counter++;
    }
}

void Burger::clear(){
    ingredients.empty();
}
bool Burger::equals(Burger *b)
{
    found = 0;
    stack<Item *> clientIngredients = getIngredientsStack();
    stack<Item *> chefIngredients = b->ingredients;

        int chefing=chefIngredients.size();
        if(this->ingredients.size()!=chefIngredients.size()){
            return false;
        }
        for (int i = 0; i < chefing; i++)
        {
            stack<Item *> tempStack;
            int clienting=clientIngredients.size();

            for (int j = 0; j < clienting; j++)
            {
                if (chefIngredients.top()->name == clientIngredients.top()->name)
                {
                    found++;
                    clientIngredients.pop();

                    // Save rest of stack into copy
                    while (!clientIngredients.empty())
                    {
                        tempStack.push(clientIngredients.top());
                        clientIngredients.pop();
                    }
                    break;
                }
                else
                {
                    tempStack.push(clientIngredients.top());
                    clientIngredients.pop();
                }
            }

            chefIngredients.pop();
            clientIngredients = tempStack;
        }
        if (found != (int)this->ingredients.size())
        {
            return false;
        }
        else
        {
            return true;
        }    
}