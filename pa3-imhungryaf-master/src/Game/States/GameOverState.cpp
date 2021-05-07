#include "GameOverState.h"

GameOverState:: GameOverState(){
	gameOver.load("images/GameOver.jpg");
	buttonRestart.load("images/restart1.jpg");
	buttonRestart.crop(130,124,596,582);
	restartButton = new Button(ofGetWidth()/2-64, ofGetHeight()/2+112, 120, 80, buttonRestart);
	
}

void GameOverState::tick() {
    restartButton->tick();
	if(restartButton->wasPressed()){
		setNextState("Menu");
		setFinished(true);	
	}
}

void GameOverState::render() {
	ofSetColor(255);
	gameOver.draw(0,0,ofGetWidth(),ofGetHeight());
	if((ofGetMouseX() >= restartButton->getX() && ofGetMouseY() >= restartButton->getY()) && (ofGetMouseX() <= restartButton->getX() + restartButton->getWidth() && ofGetMouseY() <= restartButton->getY() + restartButton->getHeight())){
		ofSetColor(187,18,193);
		restartButton->render();
	}else{
		ofSetColor(32,181,225);
		restartButton->render();	
	}
}


void GameOverState::mousePressed(int x, int y, int button){
	restartButton->mousePressed(x, y);
}
void GameOverState::keyPressed(int key){

}

void GameOverState::reset(){
	setFinished(false);
	setNextState("");
	restartButton->reset();
}