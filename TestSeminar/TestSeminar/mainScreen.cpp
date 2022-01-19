#include "mainScreen.h"


void MainScreen::mainScreen()
{
	//IntroScreen introS;
	//PlayScreen playS;
	//GameOver gOver;

	setcursor(0, 0);	//ponistavanje kursora
	drawingMainScreen();

	
	int set[] = { 12, 7, 7 };	//postavljanje boje teksta

	int counter = 1;
	char key;

	while (1) {
		
		color(set[0]);
		gotoxy(30, 9); cout << " S T A R T ";

		color(set[1]);
		gotoxy(30, 11); cout << " Settings  ";

		color(set[2]);
		gotoxy(30, 13); cout << "   Exit!   ";
		
		key = _getch();	//unos znaka

		//strelice gore i dolje
		if (key == 72 && (counter >= 2 && counter <= 3)) {
			PlaySound(TEXT("arcadegamejumpcoin.wav"), NULL, SND_SYNC); //play sound
			counter--;
		}
		if (key == 80 && (counter >= 1 && counter <= 2)) {
			PlaySound(TEXT("arcadegamejumpcoin.wav"), NULL, SND_SYNC); //play sound
			counter++;
		}
		if (key == '\r') {
			if (counter == 1) {		//play
				//PlaySound(TEXT("unlockgam.wav"), NULL, SND_SYNC);
				int checkYes = 0;
				do {
					introS.introScreen();
					checkYes = playSc.playScreen();

				} while (checkYes);
				system("cls");
				drawingMainScreen();

			}
			else if (counter == 2) {	//setting

			}
			else if (counter == 3) {	//exit
				set[2] = 7;
				color(set[2]);
				system("cls");
				exit(0);
			}
		}
		//postavljanje boje teksta i zavisnosti o counteru
		set[0] = 7; set[1] = 7; set[2] = 7;
		if (counter == 1) {
			set[0] = 12;
		}
		if (counter == 2) {
			set[1] = 12;
		}
		if (counter == 3) {
			set[2] = 12;
		}
	}
}

void MainScreen::drawingMainScreen()
{
	//Game game;
	//iscrtavanje granice
	game.drawBorder();

	//ispis naslova
	{
		gotoxy(8, 2); cout << "____ ____ _    _    _ _  _ ____    ___  ____ _ _ _ _  _ ";
		gotoxy(8, 3); cout << "|___ |__| |    |    | |\\ | | __    |  \\ |  | | | | |\\ |";
		gotoxy(8, 4); cout << "|    |  | |___ |___ | | \\| |__|    |__/ |__| |_|_| | \\|";
	}
	//iscrtavanje zgrade
	for (int i = SCREEN_HEIGHT / 2; i < SCREEN_HEIGHT - 1; i += 2) {
		for (int j = 1; j < SCREEN_WIDTH / 2 + 2; j++) {
			gotoxy(j, i);
			cout << "_";

			if (j % 4 == 0) {
				gotoxy(j, i + 1);
				cout << "|";
			}
			else {
				gotoxy(j, i + 1);
				cout << "_";
			}
		}
	}

	//iscrtavanje highscore-a
	{
		gOver.highScore();
		gotoxy(10, 20); cout << "+==================+";
		gotoxy(10, 21); cout << "|                  |";
		gotoxy(10, 22); cout << "|   HIGHSCORE: " << gOver.getScore() << "   |";
		gotoxy(10, 23); cout << "|                  |";
		gotoxy(10, 24); cout << "+==================+";
	}

	//iscrtavanje border oko botuna play, settings i exit
	for (int i = 28; i <= 42; i++) {
		for (int j = 8; j <= 14; j++) {
			gotoxy(i, j); cout << "°";
		}
	}

	//iscrtavanje lika na zgradi
	{
		gotoxy(14, 16); cout << " @";
		gotoxy(14, 17); cout << "(|)";
		gotoxy(14, 18); cout << "/_\\";
	}

	//iscrtavanje lika na balkonu zgrade
	{
		gotoxy(SCREEN_WIDTH / 2 + 2, 24); cout << "____________";
		gotoxy(SCREEN_WIDTH / 2 + 2, 25); cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\";
		gotoxy(SCREEN_WIDTH / 2 + 2, 27); cout << "   @/  _";
		gotoxy(SCREEN_WIDTH / 2 + 2, 28); cout << "  (|   |";
		gotoxy(SCREEN_WIDTH / 2 + 2, 29); cout << "__/_\\__|";
	}

	//iscrtavanje zgrada u pozadini
	{
		gotoxy(SCREEN_WIDTH - 14, 26); cout << "   _!__";
		gotoxy(SCREEN_WIDTH - 14, 27); cout << "   |::| ___";
		gotoxy(SCREEN_WIDTH - 14, 28); cout << "   |::|\\|:|";
		gotoxy(SCREEN_WIDTH - 14, 29); cout << "___|::|_|:|__";
		gotoxy(SCREEN_WIDTH - 14, 30); cout << "|::|--|:|---|";
		gotoxy(SCREEN_WIDTH - 14, 31); cout << "|::|::|:|-::|";
		gotoxy(SCREEN_WIDTH - 14, 32); cout << "|::|--|:|:--|";
		gotoxy(SCREEN_WIDTH - 14, 33); cout << "|::|::|:|:::|";
		gotoxy(SCREEN_WIDTH - 14, 34); cout << "|::|::|:|:::|";
		gotoxy(SCREEN_WIDTH - 14, 35); cout << "|::|::|:|:::|";
	}

	//iscrtavanje sunca
	{
		gotoxy(SCREEN_WIDTH - 14, 8); cout << "     .";
		gotoxy(SCREEN_WIDTH - 14, 9); cout << "   \\ | /";
		gotoxy(SCREEN_WIDTH - 14, 10); cout << " '-.;;;.-'";
		gotoxy(SCREEN_WIDTH - 14, 11); cout << "-==;;;;;==-";
		gotoxy(SCREEN_WIDTH - 14, 12); cout << " .-';;;'-.";
		gotoxy(SCREEN_WIDTH - 14, 13); cout << "   / | \\";
		gotoxy(SCREEN_WIDTH - 14, 14); cout << "     '";

	}
}

//void MainScreen::gotoxy(int x, int y) {
//	COORD cPosition;
//	cPosition.X = x;
//	cPosition.Y = y;
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cPosition);
//}
//void MainScreen::setcursor(bool visible, DWORD size)
//{
//	if (size == 0)
//		size = 20;
//
//	CONSOLE_CURSOR_INFO lpCursor;
//	lpCursor.bVisible = visible;
//	lpCursor.dwSize = size;
//	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &lpCursor);
//}
//void MainScreen::color(int color) {
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
//}