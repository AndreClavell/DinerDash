#include "WinState.h"

WinState:: WinState(){
	winner.load("images/Winner.jpg");
	buttonRestart.load("images/restart1.jpg");
	buttonRestart.crop(124,124,590,582);
	restartButton = new Button(ofGetWidth()/2-64, ofGetHeight()/2+112, 120, 80, buttonRestart);
	

}

void WinState::tick() {
    restartButton->tick();
	if(restartButton->wasPressed()){
		setNextState("Menu");
		setFinished(true);	
	}
}

void WinState::render() {
	ofSetColor(255);
	winner.draw(0,0,ofGetWidth(),ofGetHeight());
	if((ofGetMouseX() >= restartButton->getX() && ofGetMouseY() >= restartButton->getY()) && (ofGetMouseX() <= restartButton->getX() + restartButton->getWidth() && ofGetMouseY() <= restartButton->getY() + restartButton->getHeight())){
		ofSetColor(252,133,198);
		restartButton->render();
	}else{
		ofSetColor(109,137,189);
		restartButton->render();	
	}
}
void WinState ::keyPressed(int key){

}
void WinState::mousePressed(int x, int y, int button){
	restartButton->mousePressed(x, y);
}
void WinState::reset(){
	setFinished(false);
	setNextState("");
	restartButton->reset();
}