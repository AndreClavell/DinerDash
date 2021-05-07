#include "GameState.h"

GameState::GameState() {
    this->restaurant = new Restaurant();
}
void GameState::tick() {
	restaurant->tick();
	if(restaurant->getMoney()>=100){
		setNextState("Win");
		setFinished(true);
	}
	if(restaurant->getEntity()->getNumOfClients()==10){
		setNextState("GameOverState");
		setFinished(true);
	}
}
void GameState::render() {
	ofSetColor(255,255,255);
	restaurant->render();
	ofSetColor(0);
	ofDrawBitmapString("e = adds ingredient   u = remove ingredient \ns = serve client      m = increment money by 10\nc = activates sit down mode",10,15);
	ofNoFill();
	ofDrawRectangle(5,5,420,50);
}


void GameState::keyPressed(int key){
	restaurant->keyPressed(key);
}

void GameState::mousePressed(int x, int y, int button){
}

void GameState::keyReleased(int key){
}

void GameState::reset(){
	setFinished(false);
	setNextState("");
}