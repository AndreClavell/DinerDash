#pragma once 
#include "BaseCounter.h"

class StoveCounter :public BaseCounter{
 private:
 bool cooked = false;

public:
    StoveCounter(int,int,int,int,Item*,ofImage);
    void tick();
    bool isReady(){
        return cooked;
    }
    void Served(){
        cooked = false;
        ticks=0;
    }
};
