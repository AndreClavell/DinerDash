//
// Created by joshu on 11/3/2020.
//
#pragma once
#ifndef APGAMEENGINE_RESTAURANT_H
#define APGAMEENGINE_RESTAURANT_H
#include "ofMain.h"
#include "Player.h"
#include "EntityManager.h"
#include "BaseCounter.h"
#include "Burger.h"
#include "StoveCounter.h"

class Restaurant {
    private:
        Player* player;
        EntityManager* entityManager;
        int ticks=0;
        std::vector<ofImage> people;
        int money=0;
        int tempClientCount = 0;
        Burger* hambur;
        int servedClients=0;
        bool served=false;
        bool activateSitDown=false;
    public:
        Restaurant();
        int getMoney(){return money;}
        void setMoney(int m);
        EntityManager* getEntity(){return entityManager;}
        Player* getPlayer();
        void setPlayer(Player *player);
        Item* cheese;
        Item* lettuce;
        Item* tomato;
        Item* burger;
        Item* botBread;
        Item* topBread;
        ofImage floor;
        ofImage table;
        ofImage chair;
        ofImage sunset;
        void initItems();
        void initCounters();
        void initClients();
        void generateClient();
        void serveClient();
        void tick();
        void render();
        void keyPressed(int key);
};


#endif //APGAMEENGINE_RESTAURANT_H
