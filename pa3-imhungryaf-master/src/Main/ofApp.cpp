#include "ofApp.h"
#include "Images.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowTitle("Java Game Box");
	//States
	menuState = new MenuState();
	// Initial State
	currentState = menuState;
	playingsound.load("sounds/TheFatRatUnity.mp3");
	playingsound.setVolume(0.05);
}

//--------------------------------------------------------------
void ofApp::update(){
	if (currentState != nullptr){
		currentState->tick();
		if(currentState->hasFinished()){
			if(currentState->getNextState() == "Menu"){
				currentState = menuState;
			}else if(currentState->getNextState() == "Game"){
				gameState = new GameState();
				currentState = gameState;
				playingsound.play();

			}else if(currentState->getNextState()== "Win"){
				currentState= new WinState();
				playingsound.stop();
			}else if(currentState->getNextState()=="GameOverState"){
				currentState= new GameOverState();
				playingsound.stop();
			}
			currentState->reset();
		}
	}
		
}

//--------------------------------------------------------------
void ofApp::draw(){
	if (currentState != nullptr){
		currentState->render();
		table.crop(21,27,62,54);
    	table.draw(40,40,30,18);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (currentState != nullptr)
		currentState->keyPressed(key);

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if (currentState != nullptr)
			currentState->keyReleased(key);
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	if (currentState != nullptr)
		currentState->mouseMoved(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	if (currentState != nullptr)
		currentState->mouseDragged(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	if (currentState != nullptr)
		currentState->mousePressed(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	if (currentState != nullptr)
		currentState->mouseReleased(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
	if (currentState != nullptr)
			currentState->mouseEntered(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
	if (currentState != nullptr)
		currentState->mouseExited(x, y);
}


//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
	if (currentState != nullptr)
			currentState->windowResized(w, h);
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
	if (currentState != nullptr)
		currentState->gotMessage(msg);
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
	if (currentState != nullptr)
		currentState->dragEvent(dragInfo);
}
