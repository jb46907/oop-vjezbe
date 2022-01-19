#pragma once
#include "Game.h"
#include "introScreen.h"
#include "gameOver.h"
#include "playScreen.h"

class MainScreen {

	Game game;
	IntroScreen introS;
	GameOver gOver;
	PlayScreen playSc;


public:
	void mainScreen();
	void drawingMainScreen();

	/*void gotoxy(int x, int y);
	void setcursor(bool visible, DWORD size);
	void color(int color);*/
};