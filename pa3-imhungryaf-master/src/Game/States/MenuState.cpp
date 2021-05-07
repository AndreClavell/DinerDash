#include "MenuState.h"

MenuState::MenuState() {
	startButton = new Button((ofGetWidth()/2)-100, (ofGetHeight()/2)-83, 137, 323, "");
	img1.load("images/Entrance.png");
	ringBell.load("sounds/RingBell.mp3");
	ringBell.setVolume(0.05);
}
void MenuState::tick() {
	startButton->tick();
	if(startButton->wasPressed()){
		setNextState("Game");
		setFinished(true);
		ringBell.play();
	}
}
void MenuState::render() {
	ofSetBackgroundColor(0, 0, 0);
	ofSetColor(255);
	img1.draw(0, 0, ofGetWidth(), ofGetHeight());
	startButton->render();
	ofSetColor(255,255,255);
	ofDrawBitmapString("e = adds ingredient \nu = remove ingredient \ns = serve client\nm = increment money by 10\nc = activates sit down mode",32,80);
	ofNoFill();
	ofDrawRectangle(26,70,230,70);
	}

void MenuState::keyPressed(int key){
	
}

void MenuState::mousePressed(int x, int y, int button){
	startButton->mousePressed(x, y);
}

void MenuState::reset(){
	setFinished(false);
	setNextState("");
	startButton->reset();
}