#pragma once
#include "Game.h"

class GameOver {
	int score;

public:
	GameOver() { score = 0; }
	int gameover();
	void highScore();

	int getScore() { return score; }
	void setScore(int Score) { score = Score; }

	/*void gotoxy(int x, int y);

	void color(int color);*/
};