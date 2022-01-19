#pragma once
#include "Game.h"


class IntroScreen {
	int groundPos;
	int manAnimation;
	int changeManAnim;
	int counter;

	int manPosX;
	int manPosY;

	Game game1;

public:
	IntroScreen() { groundPos = 0, changeManAnim = 0, manAnimation = 0, manPosX = 22, manPosY = 24, counter = 0; }
	void introScreen();
	void drawingBuilding();
	void drawingBuildingUP();
	void drawMan();

	void eraseBuilding();
	void eraseMan();

	int getManPosX() { return manPosX; }
	void setManPosX(int posX) { manPosX = posX; }
	int getManPosY() { return manPosY; }
	void setManPosY(int posY) { manPosY = posY; }

	void setManAnimation(int pos) { manAnimation = pos; }
	int getManAnimation() { return manAnimation; }

	void setChangeManAnimation(int animation) { changeManAnim = animation; }
	int getChangeManAnimation() { return changeManAnim; }

	//void gotoxy(int x, int y);

};

