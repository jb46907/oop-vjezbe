#pragma once
#include "Game.h"
#include "gameOver.h"
#include "introScreen.h"

class PlayScreen {

	int collisionPos[3];
	int generate[3];
	int sprites[3];
	int collisions[3];

	int xManPos;
	int yManPos;
	int manAnim;

	Game game2;
	GameOver gOver2;
	IntroScreen introS2;

public:
	int playScreen();
	void generateCollision(int number);
	void drawCollision(int number);
	void eraseCollision(int number);

	void updateCurrentScore();
	int checkCollision();

	void leftSprit(int number);
	void rightSprit(int number);

	void leftObj(int number);
	void rightObj(int number);

	void drawPlayer(int x);
	void erasePlayer();
};