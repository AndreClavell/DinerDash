#pragma once
#include "State.h"
#include "Button.h"



class WinState : public State {
private:
	ofImage winner;
	Button *restartButton;
	ofImage buttonRestart;

public:
	
	void tick();
	void render();
	void keyPressed(int key);
	void mousePressed(int x, int y, int button);
	void reset();

    WinState();

};