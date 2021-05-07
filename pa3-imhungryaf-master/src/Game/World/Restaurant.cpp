//
// Created by joshu on 11/3/2020.
//

#include "Restaurant.h"

Player *Restaurant::getPlayer() {
    return player;
}

void Restaurant::setPlayer(Player *player) {
    this->player = player;
}

Restaurant::Restaurant(){
    floor.load("images/floor.jpg");
    table.load("images/sprite.png");
    table.crop(21,27,62,54);
    chair.load("images/sprite.png");
    chair.crop(108,14,30,36);
    sunset.load("images/sunsetpainting.jpg");
    entityManager = new EntityManager();
    ofImage chefPlayerImage;
    chefPlayerImage.load("images/chef.png");
    this->player = new Player(0, 600, 64, 64, chefPlayerImage, entityManager);    
    initItems();
    initCounters();
    initClients();
    generateClient();

}
void Restaurant::initItems(){
    ofImage burgerSpriteSheet, cheeseImg, lettuceImg, tomatoImg, burgerImg, botBreadImg, topBreadImg, plateImg;
    burgerSpriteSheet.load("images/burger.png");
    topBreadImg.cropFrom(burgerSpriteSheet, 25, 16, 112, 43); // top bun
    burgerImg.cropFrom(burgerSpriteSheet, 30, 134, 103, 48); // patty
    cheeseImg.cropFrom(burgerSpriteSheet, 169, 213, 102, 39); // cheese
    tomatoImg.cropFrom(burgerSpriteSheet, 169, 158, 110, 41); // tomato
    lettuceImg.cropFrom(burgerSpriteSheet, 161, 62, 117, 34); // lettuce
    botBreadImg.cropFrom(burgerSpriteSheet, 444, 270, 115, 39); // bottom bun
    plateImg.cropFrom(burgerSpriteSheet, 575, 263, 131, 51); // plate

    cheese = new Item(cheeseImg, "cheese");
    lettuce = new Item(lettuceImg, "lettuce");
    tomato = new Item(tomatoImg, "tomato");
    burger = new Item(burgerImg, "patty");
    botBread = new Item(botBreadImg, "bottomBun");
    topBread = new Item(topBreadImg, "topBun");
}
void Restaurant::initCounters(){
    int counterWidth = 96;
    int yOffset = 500;
    ofImage counterSheet, plateCounterImg, cheeseCounterImg, stoveCounterImg, lettuceCounterImg, emptyCounterImg, tomatoCounterImg, breadCounterImg;
    counterSheet.load("images/kitchen_cabinets_by_ayene_chan.png");
    stoveCounterImg.cropFrom(counterSheet, 224,12,32,43);//stoveTop
    lettuceCounterImg.cropFrom(counterSheet,96,76,32,43);//Vegetables
    emptyCounterImg.cropFrom(counterSheet,0,245,30,43);//Empty
    tomatoCounterImg.cropFrom(counterSheet,96,200,32,48);//fruit basket
    cheeseCounterImg.cropFrom(counterSheet,64,73,32,46);//cheese
    plateCounterImg.cropFrom(counterSheet,0,133,32,50);//plates
    breadCounterImg.cropFrom(counterSheet,0,63,34,56);//buns
    entityManager->addEntity(new BaseCounter(0,yOffset-16, counterWidth, 117, nullptr, plateCounterImg));
    entityManager->addEntity( new BaseCounter(counterWidth,yOffset-7, counterWidth,108, cheese, cheeseCounterImg));
    entityManager->addEntity(new StoveCounter(counterWidth*2,yOffset, counterWidth, 102, burger, stoveCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth*3, yOffset, counterWidth, 102, lettuce, lettuceCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth*4,yOffset, counterWidth, 102, nullptr, emptyCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth*5, yOffset -10, counterWidth, 113, tomato, tomatoCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth*6, yOffset-32, counterWidth, 133, botBread, breadCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth*7, yOffset-32, counterWidth, 133, topBread, breadCounterImg));
    
}
void Restaurant::initClients(){
    ofImage temp;
    temp.load("images/People/Car_Designer3Female.png");
    people.push_back(temp);
    temp.load("images/People/Freedom_Fighter2Male.png");
    people.push_back(temp);
    temp.load("images/People/Weather_Reporter2Female.png");
    people.push_back(temp);
    temp.load("images/People/Lawyer2Male.png");
    people.push_back(temp);
    temp.load("images/People/Mad_Scientist3Female.png");
    people.push_back(temp);
    temp.load("images/People/Programmer2Male.png");
    people.push_back(temp);
    temp.load("images/People/Songwriter3Male.png");
    people.push_back(temp);
    temp.load("images/People/Hipster.png");
    people.push_back(temp);
}
void Restaurant::tick() {

    if(entityManager->firstClient!= nullptr){
    if(entityManager->firstClient->getPatience() == 1 && dynamic_cast<Inspector*>(entityManager->firstClient)){
        money/=2;
    }
}

    ticks++;
    if(ticks % 925 == 0){
        generateClient();
    }
    if(ticks%2==0){
        player->tick();
       
    } 
    entityManager->tick(); 
    
}


void Restaurant::generateClient(){
    Burger* b = new Burger(72, 100, 50, 25);
    b->addIngredient(botBread);
    for (int i = 0; i < 3; i++)
    {   int ing = round(ofRandom(0,3));
        switch(ing){
            case 0:
            b->addIngredient(burger);
            break;
            case 1:
            b->addIngredient(cheese);
            break;
            case 2:
            b->addIngredient(tomato);
            break;
            case 3:
            b->addIngredient(lettuce);
            break;
        }
    }
    b->addIngredient(topBread);
    if(tempClientCount == 5){
        entityManager->addClient(new Inspector(0, 72, 64, 72,people[7], b));
        tempClientCount = 0;
    }else{
        entityManager->addClient(new Client(0, 72, 64, 72,people[ofRandom(7)], b));
        tempClientCount++;
    }
    

}
void Restaurant::render(){
    floor.draw(0,0, ofGetWidth(), ofGetHeight());
    ofSetColor(255);
    for (int i = 1; i < 6; i++)
    {
        table.draw((2*76)+76,76*i,76,76);
        chair.draw(2*76+38,76*i+36,38,38);
    }
    ofSetColor(255,100,100); 
    ofFill();
    ofDrawRectangle(0,0,ofGetWidth(),76);
    ofSetColor(255);
    sunset.draw(608,5,64,64);
    player->render();
    entityManager->render();
    ofSetColor(0);
    ofDrawBitmapString("Money: " + to_string(money), ofGetWidth()/2+40, 10);
    ofSetColor(255, 255, 255);
    //Bonus
    if (activateSitDown)
    {
        if (entityManager->firstClient != nullptr)
        {
            entityManager->firstClient->sitDown(servedClients);
            if (served)
            {
                servedClients++;
                served = false;
            }
            if (servedClients >= 6)
            {
                servedClients = 1;
            }
        }
    }
}
void Restaurant::serveClient(){
    if(entityManager->firstClient!= nullptr){
        hambur = player->getBurger();
        money += entityManager->firstClient->serve(hambur,activateSitDown);
        served=true;
    }
}
void Restaurant::keyPressed(int key) {
    player->keyPressed(key);
    if(key == 's'||key=='S'){
        serveClient();
    }
    if(key == 'm'||key=='M'){
        money+=10;
    }
    if(key=='c'||key=='C'){
        activateSitDown=true;
    }
}
void Restaurant::setMoney(int m){
    money = m;
}

