#pragma once
#include "State.h"
#include "Button.h"


class GameOverState : public State {
private:
	Button *restartButton;
	ofImage gameOver;
	ofImage buttonRestart;
public:
	void tick();
	void render();
	void keyPressed(int key);
	void mousePressed(int x, int y, int button);
	void reset();
    GameOverState();

};