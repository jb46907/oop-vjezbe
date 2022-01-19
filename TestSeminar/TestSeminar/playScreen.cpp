#include "playScreen.h"

int PlayScreen::playScreen()
{
	//Game game;
	//GameOver gOver;
	//IntroScreen introS;

	collisions[0] = 1;
	collisions[1] = 0;
	collisions[2] = 0;
	collisionPos[0] = collisionPos[1] = collisionPos[2] = 1;

	int score = 0;
	gOver2.setScore(score);
	generateCollision(0);
	updateCurrentScore();
	game2.drawBorder();

	xManPos = 36;
	yManPos = 10;
	manAnim = introS2.getManAnimation();


	int movingMan = 1;
	int move = 0;
	int i = 17;
	int j = 36;
	//counter = 36;
	float x = 2;

	gotoxy(SCREEN_WIDTH / 3.5, 20);cout << "Press space to change direction";
	_getch();
	gotoxy(SCREEN_WIDTH / 3.5, 20);cout << "                               ";

	erasePlayer();
	if (manAnim != 2) {
		drawPlayer(movingMan);
	}
	else {
		drawPlayer(movingMan);
	}
	erasePlayer();
	xManPos -= 2;
	drawPlayer(movingMan);
	erasePlayer();




	while (1) {

		if (_kbhit()) { //unos tipkovnice, ako da provjeri da li je space
			char space = _getch();
			if (space == 32) {
				if (!movingMan) {
					movingMan = 1;
 					if (manAnim == 2) {
						drawPlayer(movingMan);
						
					}
					else {
						drawPlayer(movingMan);
						
					}	//izmjena animacije
					x = 2;
				}
				else {
					movingMan = 0;
					if (manAnim == 2) {
						drawPlayer(movingMan);
						
					}
					else {
						drawPlayer(movingMan);
						
					}	//izmjena animacije
					x = 2;
				}

			}
			if (space == 27) {
				break;
			}
		}
		erasePlayer();
		//uvecavanje ili smanjivanje pozicije lika ovisnoti o movingMan(klik)
		if (!movingMan) {
			xManPos += x;
			
		}
		else {
			xManPos -= x;
			
		}
		x += 0.9; // nelinearno ubrzavanje lika - otezava igru

		
		drawPlayer(movingMan);
		drawCollision(0);
		drawCollision(1);
		drawCollision(2);

		//provjera collision
		if (checkCollision())
		{
			//provjera play again

			if (gOver2.gameover())
			{
				return 1;
			}
			return 0;
		}
		else if (collisionPos[0] == 27) {
			score++;
			gOver2.setScore(score);
			//PlaySound(TEXT("gametouch.wav"), NULL, SND_ASYNC); //play sound
			
		}
		updateCurrentScore();
		Sleep(150);

		erasePlayer();
		eraseCollision(0);
		eraseCollision(1);
		eraseCollision(2);

		if (collisions[0] == 1)
			collisionPos[0] += 2;

		if (collisions[1] == 1)
			collisionPos[1] += 2;

		if (collisions[2] == 1)
			collisionPos[2] += 2;

		if (collisionPos[0] >= 15 && collisionPos[0] < 17 && collisions[1] != 1) {

			collisions[1] = 1;
			collisionPos[1] = 1;
			generateCollision(1);

		}
		if (collisionPos[1] >= 15 && collisionPos[1] < 17) {
			collisions[2] = 1;
			collisionPos[2] = 1;
			generateCollision(2);
		}
		if (collisionPos[0] > 34) {
			collisions[1] = 1;
			collisions[2] = 0;
			collisionPos[0] = collisionPos[1];
			generate[0] = generate[1];
			collisionPos[1] = collisionPos[2];
			generate[1] = generate[2];

			sprites[0] = sprites[1];
			sprites[1] = sprites[2];
		}
	

	}
}

void PlayScreen::generateCollision(int number) {
	generate[number] = 3 + rand() % 23;
	sprites[number] = 0 + rand() % 6;
}
void PlayScreen::drawCollision(int number) {
	if (collisions[number] == 1) {
		for (int i = 0; i < generate[number]; i++) {
			gotoxy(i - 1 + SCREEN_WIDTH / 4, SCREEN_HEIGHT - collisionPos[number] - 1);
			cout << "_";
			gotoxy(i + SCREEN_WIDTH / 4, SCREEN_HEIGHT - collisionPos[number]);
			cout << "\\";
			if (collisionPos[number] > 4 && generate[number] > 10) {
				leftSprit(number);
			}
			else if (collisionPos[number] > 3 && generate[number] < 10 && generate[number] > 3) {
				leftObj(number);
			}

		}
		for (int i = generate[number] + GAP_SIZE; i < SCREEN_WIDTH / 1.9; i++) {
			gotoxy(i + 1 + SCREEN_WIDTH / 4, SCREEN_HEIGHT - collisionPos[number] - 1);
			cout << "_";
			gotoxy(i + SCREEN_WIDTH / 4, SCREEN_HEIGHT - collisionPos[number]);
			cout << "/";
			if (collisionPos[number] > 4 && generate[number] < 20) {
				rightSprit(number);
			}
			else if (collisionPos[number] > 3 && generate[number] > 19) {
				rightObj(number);
			}
		}
	}
}
void PlayScreen::eraseCollision(int number) {
	if (collisions[number] == 1) {
		for (int i = 0; i < generate[number]; i++) {
			gotoxy(i + SCREEN_WIDTH / 4, SCREEN_HEIGHT - collisionPos[number] - 1);
			cout << " ";
			gotoxy(i + SCREEN_WIDTH / 4, SCREEN_HEIGHT - collisionPos[number]);
			cout << " ";
			if (collisionPos[number] > 4) {
				gotoxy(SCREEN_WIDTH / 4, SCREEN_HEIGHT - collisionPos[number] + 2); cout << "       ";
				gotoxy(SCREEN_WIDTH / 4, SCREEN_HEIGHT - collisionPos[number] + 3); cout << "       ";
				gotoxy(SCREEN_WIDTH / 4, SCREEN_HEIGHT - collisionPos[number] + 4); cout << "       ";
			}
		}
		for (int i = generate[number] + GAP_SIZE; i < SCREEN_WIDTH / 1.9; i++) {
			gotoxy(i + SCREEN_WIDTH / 4, SCREEN_HEIGHT - collisionPos[number] - 1);
			cout << " ";
			gotoxy(i + SCREEN_WIDTH / 4, SCREEN_HEIGHT - collisionPos[number]);
			cout << " ";
			if (collisionPos[number] > 4) {
				gotoxy(47, SCREEN_HEIGHT - collisionPos[number] + 2); cout << "       ";
				gotoxy(47, SCREEN_HEIGHT - collisionPos[number] + 3); cout << "       ";
				gotoxy(47, SCREEN_HEIGHT - collisionPos[number] + 4); cout << "       ";
			}
		}
	}
}

//provjera collision isTrue
int PlayScreen::checkCollision() {
	//IntroScreen introS;
	//provjera tek na ovo visini te provjera udaranje zgrade
	if (collisionPos[0] == 24 || collisionPos[0] == 25 || xManPos < 17 || xManPos > 47) {
		//provjera da li je doslo do collisiona
		if (xManPos < generate[0] + 70 / 4 || xManPos > generate[0] + 70 / 4 + GAP_SIZE || xManPos + 5 < generate[0] + SCREEN_WIDTH / 4 || xManPos + 5 > generate[0] + SCREEN_WIDTH / 4 + GAP_SIZE) {

			return 1;
		}
	}
	
	return 0;
}

void PlayScreen::updateCurrentScore() {
	
	gotoxy(SCREEN_WIDTH / 2.1, 3);cout << "Score: " << gOver2.getScore() << endl;
}


void PlayScreen::leftSprit(int number) {

	switch (sprites[number]) { //sprites
	case 0:
		gotoxy(SCREEN_WIDTH / 4, SCREEN_HEIGHT - collisionPos[number] + 2); cout << "  @";
		gotoxy(SCREEN_WIDTH / 4, SCREEN_HEIGHT - collisionPos[number] + 3); cout << " (|)  |";
		gotoxy(SCREEN_WIDTH / 4, SCREEN_HEIGHT - collisionPos[number] + 4); cout << "_/_\\__|";
		break;
	case 1:
		gotoxy(SCREEN_WIDTH / 4, SCREEN_HEIGHT - collisionPos[number] + 2); cout << "  #";
		gotoxy(SCREEN_WIDTH / 4, SCREEN_HEIGHT - collisionPos[number] + 3); cout << " ### |";
		gotoxy(SCREEN_WIDTH / 4, SCREEN_HEIGHT - collisionPos[number] + 4); cout << "_\\|/_|";
		break;
	case 2:
		gotoxy(SCREEN_WIDTH / 4, SCREEN_HEIGHT - collisionPos[number] + 2); cout << "  @/";
		gotoxy(SCREEN_WIDTH / 4, SCREEN_HEIGHT - collisionPos[number] + 3); cout << " (|   |";
		gotoxy(SCREEN_WIDTH / 4, SCREEN_HEIGHT - collisionPos[number] + 4); cout << "_/_\\__|";
		break;
	case 3:
		gotoxy(SCREEN_WIDTH / 4, SCREEN_HEIGHT - collisionPos[number] + 2); cout << "  @";
		gotoxy(SCREEN_WIDTH / 4, SCREEN_HEIGHT - collisionPos[number] + 3); cout << " \\|_  |";
		gotoxy(SCREEN_WIDTH / 4, SCREEN_HEIGHT - collisionPos[number] + 4); cout << "_/_\\\\_|";
		break;
	case 4:
		gotoxy(SCREEN_WIDTH / 4, SCREEN_HEIGHT - collisionPos[number] + 2); cout << "     __";
		gotoxy(SCREEN_WIDTH / 4, SCREEN_HEIGHT - collisionPos[number] + 3); cout << "     /";
		gotoxy(SCREEN_WIDTH / 4, SCREEN_HEIGHT - collisionPos[number] + 4); cout << "____/";
		break;
	case 5:
		gotoxy(SCREEN_WIDTH / 4, SCREEN_HEIGHT - collisionPos[number] + 2); cout << "--";
		gotoxy(SCREEN_WIDTH / 4, SCREEN_HEIGHT - collisionPos[number] + 3); cout << "##|";
		gotoxy(SCREEN_WIDTH / 4, SCREEN_HEIGHT - collisionPos[number] + 4); cout << "__|";
		break;
	}


}

void PlayScreen::rightSprit(int number) {
	switch (sprites[number]) { //animacija lika
	case 5:
		gotoxy(47, SCREEN_HEIGHT - collisionPos[number] + 2); cout << "    @";
		gotoxy(47, SCREEN_HEIGHT - collisionPos[number] + 3); cout << "|  (|) ";
		gotoxy(47, SCREEN_HEIGHT - collisionPos[number] + 4); cout << "|__/_\\_";
		break;
	case 0:
		gotoxy(47, SCREEN_HEIGHT - collisionPos[number] + 2); cout << "   #";
		gotoxy(47, SCREEN_HEIGHT - collisionPos[number] + 3); cout << "| ### ";
		gotoxy(47, SCREEN_HEIGHT - collisionPos[number] + 4); cout << "|_\\|/__";
		break;
	case 2:
		gotoxy(47, SCREEN_HEIGHT - collisionPos[number] + 2); cout << "   \\@";
		gotoxy(47, SCREEN_HEIGHT - collisionPos[number] + 3); cout << "|   |) ";
		gotoxy(47, SCREEN_HEIGHT - collisionPos[number] + 4); cout << "|__/_\\_";
		break;
	case 3:
		gotoxy(47, SCREEN_HEIGHT - collisionPos[number] + 2); cout << "__     ";
		gotoxy(47, SCREEN_HEIGHT - collisionPos[number] + 3); cout << " \\    ";
		gotoxy(47, SCREEN_HEIGHT - collisionPos[number] + 4); cout << "  \\____";
		break;
	case 4:
		gotoxy(47, SCREEN_HEIGHT - collisionPos[number] + 2); cout << "    @";
		gotoxy(47, SCREEN_HEIGHT - collisionPos[number] + 3); cout << "|  _|/";
		gotoxy(47, SCREEN_HEIGHT - collisionPos[number] + 4); cout << "|_//_\\_";
		break;
	case 1:
		gotoxy(51, SCREEN_HEIGHT - collisionPos[number] + 2); cout << " --";
		gotoxy(51, SCREEN_HEIGHT - collisionPos[number] + 3); cout << "|##";
		gotoxy(51, SCREEN_HEIGHT - collisionPos[number] + 4); cout << "|__";
		break;
	}
}

void PlayScreen::leftObj(int number) {
	switch (sprites[number]) { //objects
	case 0:
		gotoxy(SCREEN_WIDTH / 4, SCREEN_HEIGHT - collisionPos[number] + 3); cout << "[#]";
		break;
	case 1:
		gotoxy(SCREEN_WIDTH / 4, SCREEN_HEIGHT - collisionPos[number] + 3); cout << "-%%";
		break;
	case 2:
		gotoxy(SCREEN_WIDTH / 4, SCREEN_HEIGHT - collisionPos[number] + 3); cout << ">-/";
		break;
	case 3:
		gotoxy(SCREEN_WIDTH / 4, SCREEN_HEIGHT - collisionPos[number] + 3); cout << "X:-";
		break;
	case 4:
		gotoxy(SCREEN_WIDTH / 4, SCREEN_HEIGHT - collisionPos[number] + 3); cout << "#))";
		break;
	case 5:
		gotoxy(SCREEN_WIDTH / 4, SCREEN_HEIGHT - collisionPos[number] + 3); cout << ";;;";
		break;
	}

}

void PlayScreen::rightObj(int number) {
	switch (sprites[number]) { //objects
	case 0:
		gotoxy(51, SCREEN_HEIGHT - collisionPos[number] + 3); cout << "[#]";
		break;
	case 1:
		gotoxy(51, SCREEN_HEIGHT - collisionPos[number] + 3); cout << "%-%";
		break;
	case 2:
		gotoxy(51, SCREEN_HEIGHT - collisionPos[number] + 3); cout << "/-<";
		break;
	case 3:
		gotoxy(51, SCREEN_HEIGHT - collisionPos[number] + 3); cout << "__X";
		break;
	case 4:
		gotoxy(51, SCREEN_HEIGHT - collisionPos[number] + 3); cout << "(&)";
		break;
	case 5:
		gotoxy(51, SCREEN_HEIGHT - collisionPos[number] + 3); cout << "LLL";
		break;
	}

}

void PlayScreen::drawPlayer(int x) {
	switch (x) {
	case 0:
		gotoxy(xManPos, yManPos); cout << "\\___/o";
		break;
	case 1:
		gotoxy(xManPos, yManPos); cout << "o\\___/";
		break;
	}
}
void PlayScreen::erasePlayer() {
	
	gotoxy(xManPos, yManPos); cout << "      ";
}
